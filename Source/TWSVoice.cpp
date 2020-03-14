/**
 * This file contains all the DSP.
 *
 * Warning: The DSP isn't very good!
 */

#include "TWSVoice.h"
#include "PluginProcessor.h"

TWSVoice::TWSVoice(TuningworkbenchsynthAudioProcessor *i) : p(i), needsRetune(false) {
    // http://www.cs.cmu.edu/~music/icm-online/readings/panlaws/
    // FIXME - make this more efficient by using a lookup table obvs
    for( int i=0; i<N_PAN; ++i )
    {
        double panAngle = 1.0 * i / (N_PAN - 1) * MathConstants<double>::pi / 2.0;
        auto piby2 = MathConstants<double>::pi / 2.0;
        auto lW = sqrt( ( piby2 - panAngle ) / piby2 * cos( panAngle ) );
        auto rW = sqrt( panAngle * sin( panAngle ) / piby2 );
        panBufferL[i] = lW;
        panBufferR[i] = rW;
    }
    synthModWheel = 0;
}

void TWSVoice::startNote (int midiNoteNumber, float velocity,
                          SynthesiserSound*, int currentPitchWheelPosition) 
{
    setPitchWheel( currentPitchWheelPosition );
    noteNum = midiNoteNumber;
    modwheelLevel = synthModWheel.load();
    
    level = ( velocity + 64 ) / 192.0 * 0.7; // cramp up the velosity sens a bit
    lfoTime = 0;
    lfoDTime = 1.0 / getSampleRate();
    lfoAngle = 0;
    lfoLastRand.reset( 128 );
    lfoLastSquare.reset( 128 );
    lfoLastRand.setCurrentAndTargetValue( 2.0 * rand() / RAND_MAX - 1.0 );
    lfoLastSquare.setCurrentAndTargetValue( -1.0 );

    nunison = std::max( 1, (int)( *(p->uni_count) ) );
    filterTypeAtOutset = *( p->filter_type );

    switch( filterTypeAtOutset )
    {
    case 2: // HPF
    {
        filterL.parameters->type = dsp::StateVariableFilter::Parameters<float>::Type::highPass;
        filterR.parameters->type = dsp::StateVariableFilter::Parameters<float>::Type::highPass;
    }
    break;
    case 3: // HPF
    {
        filterL.parameters->type = dsp::StateVariableFilter::Parameters<float>::Type::bandPass;
        filterR.parameters->type = dsp::StateVariableFilter::Parameters<float>::Type::bandPass;
    }
    break;
    
    default: // LPF
    {
        filterL.parameters->type = dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
        filterR.parameters->type = dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
        
    }
    break;
    }
    filterL.reset();
    filterR.reset();

    if( nunison == 1 )
    {
        auto cyclesPerSample = frequencyForFractionalNote( midiNoteNumber + pitchWheelNoteShift() ) / getSampleRate();
        currentAngle[0] = 0;
        angleDelta[0] = cyclesPerSample;
        pan[0] = 0;
        dDelta[0] = 0;

    }
    else
    {
        double uso = *( p->uni_spread ) / 100.0 * 2.0; // the 2.0 is for up and down
        double duso = uso / (nunison - 1);
        double sso = -uso / 2;
        priorRenderedUniSpread = *( p->uni_spread );
        
        level /= sqrt(nunison - 1);
        
        for( int i=0; i<nunison; ++i )
        {
            double frc = duso * i + sso;
            auto cyc = frequencyForFractionalNote( midiNoteNumber + frc + pitchWheelNoteShift() );
            auto cyclesPerSample = cyc / getSampleRate();

            currentAngle[i] = 1.0 * rand() / RAND_MAX;
            angleDelta[i] = cyclesPerSample;
            pan[i] = 2.0 * i / ( nunison - 1 ) - 1.0;
            dDelta[i] = duso * i + sso;
     ;
#if DEBUG_UNISON            
            std::cout << "UNISON i=" << i
                      << " frc=" << frc 
                      << " angleDelta[i] = " << angleDelta[i] * getSampleRate() << " pan[i] = " << pan[i] << std::endl;
#endif            
        }
    }

    {
        // Setup the sub-oscillattr
        auto cyclesPerSample = frequencyForFractionalNote( midiNoteNumber + pitchWheelNoteShift() ) / getSampleRate();
        for( int i=0; i< -*(p->subosc_oct); ++i )
            cyclesPerSample /= 2.0;
        subAngle = 0;
        subAngleDelta = cyclesPerSample;
    }


    {
#define _D(x) " " << #x << "=" << x

        // Set up the pluck
        if( pluckDelayLine.size() != getSampleRate() )
        {
            pluckDelayLine.resize(getSampleRate());
            pluckDelayLineSize = getSampleRate();
        }
        pluckSampleDelay = 1.0 / ( frequencyForFractionalNote( midiNoteNumber + pitchWheelNoteShift() ) / getSampleRate() );
        iPluckSampleDelay = std::floor(pluckSampleDelay);
        fracPluckSampleDelay = pluckSampleDelay - iPluckSampleDelay;
        pluckAttenNorm = 44100 / getSampleRate() / 10.0;
        
        pluckDelayPos = iPluckSampleDelay + 10; // enough room for the filter

        int ft = *( p->pluck_init );
        switch( ft )
        {
        case 1:
        {
            // square
            for( int i=0; i<pluckDelayPos; ++i )
                pluckDelayLine[i] = ( i < pluckDelayPos / 2 ? 1.0 : -1.0 );
            break;
        }
        case 2:
        {
            // saw 
            for( int i=0; i<pluckDelayPos; ++i )
                pluckDelayLine[i] = ( i * 2.0f / pluckDelayPos ) - 1.0;
            break;
        }
        case 3:
        {
            // noisy saw
            for( int i=0; i<pluckDelayPos; ++i )
                pluckDelayLine[i] = 0.5 * ( ( i * 2.0f / pluckDelayPos ) - 1.0 ) + 0.5 * ( 2.0 * rand() / RAND_MAX - 1.0 );
            break;
        }
        case 4:
        {
            // Sin
            float scale = 2.0 * MathConstants<double>::pi / iPluckSampleDelay;
            for( int i=0; i<pluckDelayPos; ++i )
                pluckDelayLine[i] = std::sin( i * scale );
            break;
        }
        case 5:
        {
            // Chirp
            for (int i = 0; i < pluckDelayPos; ++i) {
                float ls = 1.0f * i / pluckDelayPos;
                float lse = exp(ls * 2) * 3;
                pluckDelayLine[i] = sin(lse * 2 * MathConstants<double>::pi);
            }
            break;

        }
            
        case 0:
        default:
        {
            for( int i=0; i<pluckDelayPos; ++i )
                pluckDelayLine[i] = rand() * 2.0 / RAND_MAX - 1.0;
            break;
        }

        }

    }
    priorRenderedPW = pwAmount;
    
    ampenv.setSampleRate( getSampleRate() );
    auto ap = ampenv.getParameters();
    ap.attack = *( p->amp_attack );
    ap.decay = *( p->amp_decay );
    ap.sustain = *( p->amp_sustain );
    ap.release = *( p->amp_release );
    ap.release = std::max( ap.release, 0.01f );
    ampenv.setParameters(ap);

    pluckenv.setSampleRate( getSampleRate() );
    auto pp = pluckenv.getParameters();
    pp.attack = 0.0;
    pp.decay = 0.0;
    pp.sustain = 1.0;
    pp.release = 0.1;
    pluckenv.setParameters(pp);

    filtenv.setSampleRate( getSampleRate() );
    auto fp = filtenv.getParameters();
    fp.attack = *( p->filter_attack );
    fp.decay = *( p->filter_decay );
    fp.sustain = *( p->filter_sustain );
    fp.release = *( p->filter_release );
    fp.release = std::max( fp.release, 0.01f );
    filtenv.setParameters(fp);

    sinLevel.reset( 32 );
    sinLevel.setCurrentAndTargetValue( *( p->sinLevel ) );
    
    squareLevel.reset( 32 );
    squareLevel.setCurrentAndTargetValue( *( p->squareLevel ) );
    
    sawLevel.reset( 32 );
    sawLevel.setCurrentAndTargetValue( *( p->sawLevel ) );
    
    triLevel.reset( 32 );
    triLevel.setCurrentAndTargetValue( *( p->triLevel ) );

    filterCut.reset(32);
    filterCut.setCurrentAndTargetValue( *( p->filter_cutoff ) );

    filterRes.reset(32);
    filterRes.setCurrentAndTargetValue( *( p->filter_resonance ) );

    filterDepth.reset(32);
    filterDepth.setCurrentAndTargetValue( *( p->filter_depth ) );

    subLevel.reset(32);
    subLevel.setCurrentAndTargetValue( *(p->subosc_level) );

    pluckWeight.reset(32);
    pluckWeight.setCurrentAndTargetValue( *(p->pluck_flt) );

    pluckAtten.reset(32);
    pluckAtten.setCurrentAndTargetValue( *(p->pluck_atn) * pluckAttenNorm );

    pluckLevel.reset(32);
    pluckLevel.setCurrentAndTargetValue( *(p->pluck_lev ) );

    ampenv.noteOn();
    pluckenv.noteOn();
    filtenv.noteOn();
}

void TWSVoice::stopNote (float velocity, bool allowTailOff) 
{
    ampenv.noteOff();
    pluckenv.noteOff();
    filtenv.noteOff();
}

inline double analogishSquare( double x )
{
    if( x > 1 ) x-= 1;
    double r = 0;
    if( x < 0.5 )
    {
        r = 1.0 - 0.1 * ( ( x + 0.3 ) * ( x + 0.3 ) - 0.3 * 0.3 ) / ( 0.8 * 0.8 - 0.3 * 0.3 );
    }
    else
    {
        r = 0.1 * ( ( x - 0.2 ) * ( x - 0.2 ) - 0.3 * 0.3 ) / ( 0.8 * 0.8 - 0.3 * 0.3 );
    }
    return r * 2.0 - 1.0;
}

inline double analogishTri( double x )
{
    if( x > 1 ) x-= 1;
    double r = 0;
    if( x < 0.5 )
    {
        r = ( ( x + 0.3 ) * ( x + 0.3 ) - 0.3 * 0.3 ) / ( 0.8 * 0.8 - 0.3 * 0.3 );
    }
    else
    {
        r = 1.0 - ( ( x - 0.2 ) * ( x - 0.2 ) - 0.3 * 0.3 ) / ( 0.8 * 0.8 - 0.3 * 0.3 );
    }
    return r * 2.0 - 1.0;
}

inline double analogishSaw( double x )
{
    if( x > 1 ) x-= 1;
    double r = 0;
    if( x < 0.94 )
    {
        r = ( ( x + 0.3 ) * ( x + 0.3 ) - 0.3 * 0.3 ) / ( 1.4 * 1.4 - 0.3 * 0.3 );
    }
    else
    {
        auto q = x - 1;
        r = - q * q * q * q * 10000.0 + 1.0;
    }
    return r * 2.0 - 1.0;
}

void TWSVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) 
{
    if( ! isVoiceActive() ) return;
    const int resetFilterEvery = 8;

    bool usef = *(p->filter_on) != 0 ? true : false;
    
    sinLevel.setTargetValue( *( p->sinLevel ) );
    squareLevel.setTargetValue( *( p->squareLevel ) );
    sawLevel.setTargetValue( *( p->sawLevel ) );
    triLevel.setTargetValue( *( p->triLevel ) );
    subLevel.setTargetValue( *( p->subosc_level ) );
    
    filterCut.setTargetValue( *( p->filter_cutoff ) );
    filterRes.setTargetValue( *( p->filter_resonance ) );
    filterDepth.setTargetValue( *( p->filter_depth ) );

    pluckWeight.setTargetValue( *( p->pluck_flt ) );
    pluckAtten.setTargetValue( *(p->pluck_atn) * pluckAttenNorm );
    pluckLevel.setTargetValue( *( p->pluck_lev ) );
    
    bool recalcCycle = false;
    if( priorRenderedPW != pwAmount )
    {
        priorRenderedPW = pwAmount;
        recalcCycle = true;
    }

    if( nunison > 1 && priorRenderedUniSpread != *( p->uni_spread ) )
    {
        double uso = *( p->uni_spread ) / 100.0 * 2.0; // the 2.0 is for up and down
        double duso = uso / (nunison - 1);
        double sso = -uso / 2;
        priorRenderedUniSpread = *( p->uni_spread );
        for( int i=0; i<nunison; ++i )
        {
            dDelta[i] = duso * i + sso;
        }
        recalcCycle = true;
    }

    if( needsRetune.exchange(false) )
    {
        recalcCycle = true;
    }
    
    int sc = 0;
    float lfoDAngle = *( p->lfo_rate ) * lfoDTime;
    while (--numSamples >= 0)
    {
        // First calculate the LFO
        float lfoMul = 1.f;
        if( lfoTime < *( p->lfo_delay ) )
            lfoMul = 0;
        else if( lfoTime < *( p->lfo_delay ) + *( p->lfo_attack ) )
        {
            lfoMul = ( lfoTime - *( p->lfo_delay ) ) / *( p->lfo_attack );
        }

        float lfoVal;
        if( *( p->lfo_rate ) == 0 )
            lfoVal = lfoMul;
        else
        {
            int t = *(p->lfo_type);
            switch( t )
            {
            case 1: // square
            {
                if( lfoAngle > 0.5 && lfoAngle - lfoDAngle <= 0.5 )
                    lfoLastSquare.setTargetValue( 1.0 );
                if( lfoAngle + lfoDAngle >= 1.0 )
                    lfoLastSquare.setTargetValue( -1.0 );
                lfoVal = lfoMul * lfoLastSquare.getNextValue();
                break;
            }
            case 2: // rand
            {
                if( lfoAngle + lfoDAngle >= 1 )
                    lfoLastRand.setTargetValue( 2.0 * rand() / RAND_MAX - 1.0 );
                lfoVal = lfoMul * lfoLastRand.getNextValue();
                break;
            }
            default:
            case 0: // tri
            {
                lfoVal = lfoMul * ( ( lfoAngle > 0.5 ? ( 1.0 - lfoAngle ) : lfoAngle ) * 4.0 - 1.0 );
                break;
            }

            }
        }

        if( *(p->modwheel_on) )
            lfoVal *= modwheelLevel / 127.0;
        
        lfoTime += lfoDTime;
        lfoAngle += lfoDAngle;
        if( lfoAngle >= 1 )
            lfoAngle -= 1;

        if( sc % resetFilterEvery == 0 && *( p->lfo_pitch ) != 0 )
            recalcCycle = true;
        
        auto sampleL = 0.0f;
        auto sampleR = 0.0f;

        auto AEG = ampenv.getNextSample() * level;
        auto PEG = pluckenv.getNextSample() * level * pluckLevel.getNextValue();
        auto FEG = filtenv.getNextSample();
        
        auto sinlv = sinLevel.getNextValue();
        auto sqrlv = squareLevel.getNextValue();
        auto sawlv = sawLevel.getNextValue();
        auto trilv = triLevel.getNextValue();

        
        if( usef )
        {
            auto lfof = lfoVal * *( p->lfo_filter ) * 0.2; // These are all callibrations from just playing with the sliders
            auto filtd = filterDepth.getNextValue();
            auto filtf = FEG * FEG * filtd * 64.0;
            if( filtd < 0 )
                filtf = FEG * FEG * filtd * 0.95;
            auto filtc = std::max( 10.0, std::min(
                                       filterCut.getNextValue() * ( 1 + filtf + lfof ),
                                       getSampleRate() / 4 ) );
            auto filtr = std::min( std::max( 0.05f, filterRes.getNextValue() ), 0.99f );
            
            // This is overkill but for now just hammer it
            if( sc % resetFilterEvery == 0 )
            {
                filterL.parameters->setCutOffFrequency( getSampleRate(), filtc, filtr );
                filterR.parameters->setCutOffFrequency( getSampleRate(), filtc, filtr );

                // handle denomrals
                filterL.snapToZero();
                filterR.snapToZero();
            }
        }
        sc++;

        for( int i=0; i<nunison; ++i )
        {
            auto ca = currentAngle[i];

            if( *( p->vco_on) )
            {
                auto oscSin = (float) std::sin ( 2.0 * MathConstants<double>::pi * ca) * sinlv;
                auto oscSqr = analogishSquare(ca + 0.05) * sqrlv;
                auto oscSaw = analogishSaw(ca + 0.07) * sawlv;
                auto oscTri = analogishTri(ca + 0.03) * trilv;
                
                auto currentVoice = AEG * ( oscSqr + oscSin + oscSaw + oscTri );

                int panIdx = ( pan[i] + 1 ) * N_PAN / 2;
                if( panIdx < 0 ) panIdx = 0;
                if( panIdx >= N_PAN ) panIdx = N_PAN - 1;
                
                // This isn't precise enough to bother interpolating
                auto lW = panBufferL[panIdx];
                auto rW = panBufferR[panIdx];

                if( nunison == 1 )
                {
                    // Force absolute mono
                    auto t = (lW + rW) * 0.5;
                    lW = t;
                    rW = t;
                }

                // Apply the volume LFO
                if( *( p->lfo_vcolev ) != 0 )
                {
                    float fac = std::max( 0.f, 1.f + *( p->lfo_vcolev ) * lfoVal );
                    lW *= fac;
                    rW *= fac;
                }
                
                // std::cout << "lW/rW=" << lW << " " << rW << " " << panAngle << std::endl;
                sampleL += lW * currentVoice;
                sampleR += rW * currentVoice;
            }
            
            if( recalcCycle )
            {
                auto cyc = frequencyForFractionalNote( noteNum + dDelta[i] + pitchWheelNoteShift() + *(p->lfo_pitch) * lfoVal );
                auto cyclesPerSample = cyc / getSampleRate();
                angleDelta[i] = cyclesPerSample;
            }
            
            currentAngle[i] += angleDelta[i];
            if( currentAngle[i] > 1.0 )
                currentAngle[i] -= 1.0;
        }
        
        if( recalcCycle )
        {
            auto cyclesPerSample = frequencyForFractionalNote( noteNum + pitchWheelNoteShift()  + *(p->lfo_pitch) * lfoVal ) / getSampleRate();
            for( int i=0; i< -*(p->subosc_oct); ++i )
                cyclesPerSample /= 2.0;
            subAngleDelta = cyclesPerSample;
        }

        if( *(p->sub_on) )
        {
            auto subl = subLevel.getNextValue();
            auto oscSqr = analogishSquare(subAngle) * subl * AEG;

            if( *( p->lfo_sublev ) != 0 )
            {
                float fac = std::max( 0.f, 1.f + *( p->lfo_sublev ) * lfoVal );
                oscSqr *= fac;
            }

            subAngle += subAngleDelta;
            if( subAngle > 1 )
                subAngle -= 1;
            sampleL += oscSqr;
            sampleR += oscSqr;
        }

        
        if( *(p->pluck_on) )
        {
            // Filter the signal and write it into the delay line
            size_t priorPos;
            if( pluckDelayPos != 0 )
                priorPos = pluckDelayPos - 1;
            else
                priorPos = pluckDelayLineSize - 1;

            long ago = pluckDelayPos - iPluckSampleDelay;
            long agop1 = ago + 1;
            if( ago < 0 ) ago += pluckDelayLineSize;
            if( agop1 < 0 ) agop1 += pluckDelayLineSize;
            // for now - interp this
            float mixvalue = (1.0 - fracPluckSampleDelay ) * pluckDelayLine[ago] + fracPluckSampleDelay * pluckDelayLine[agop1];

            auto pw = pluckWeight.getNextValue();
            auto pa = pluckAtten.getNextValue();
            auto filtval = ( pw * mixvalue + ( 1 - pw ) * pluckDelayLine[priorPos] ) * ( 1.0 - pa );
            pluckDelayPos ++;
            if( pluckDelayPos >= pluckDelayLineSize ) pluckDelayPos = 0;
            pluckDelayLine[pluckDelayPos] = filtval;

            if( *( p->lfo_plucklev ) != 0 )
            {
                float fac = std::max( 0.f, 1.f + *( p->lfo_plucklev ) * lfoVal );
                filtval *= fac;
            }

            sampleL += filtval * PEG * 2.2;
            sampleR += filtval * PEG * 2.2; // amplify the pluck max level a bit

            if( recalcCycle )
            {
                pluckSampleDelay = 1.0 / ( frequencyForFractionalNote( noteNum + pitchWheelNoteShift()  + *(p->lfo_pitch) * lfoVal )
                                           / getSampleRate() );
                iPluckSampleDelay = std::floor(pluckSampleDelay);
                fracPluckSampleDelay = pluckSampleDelay - iPluckSampleDelay;
            }
        }

        if( usef )
        {
            sampleL = filterL.processSample( sampleL );
            sampleR = filterR.processSample( sampleR );
        }
        
        if( outputBuffer.getNumChannels() == 1 )
        {
            outputBuffer.addSample (0, startSample, ( sampleL + sampleR ) / 2.0 );
        }
        else 
        {
            outputBuffer.addSample (0, startSample, sampleL);
            outputBuffer.addSample (1, startSample, sampleR);
        }
        
        ++startSample;
    }
    
    // TODO: If the AEG is over kill the note
    if( ! ampenv.isActive() && !pluckenv.isActive() && isVoiceActive() )
    {
        clearCurrentNote();
    }
    

}


double TWSVoice::frequencyForFractionalNote( double fnote )
{
    /*
     * TODO: We know frequency is actually exponential in note so should we interp differently?
     * If so - push that answer to the library not here.
     */
    int bn = std::floor( fnote );
    double frac = fnote - bn;

    auto noteDown = p->tuning.frequencyForMidiNote( bn );
    auto noteUp   = p->tuning.frequencyForMidiNote( bn + 1 );

    auto res = noteDown * ( 1 - frac ) + noteUp * frac;
    
    return res;
}

double TWSVoice::pitchWheelNoteShift() {
    if( pwAmount == 0 )
        return 0;
    else if( pwAmount < 0 )
        return pwAmount * ( *(p->pb_down ));
    else
        return pwAmount * ( *(p->pb_up ));
}

void TWSVoice::tuningUpdated( const Tunings::Tuning &newTuning ) {
    needsRetune = true;
}


TWSSynthesiser::TWSSynthesiser(TuningworkbenchsynthAudioProcessor &p) : processor( p )
{
    delayT.reset(512);
    delayFB.reset(32);

    delayWet.reset(32);
    delayDry.reset(32);
}


void TWSSynthesiser::handleController( int chan, int cont, int val )
{
    if( cont == 1 )
    {
        for( int i=0; i<getNumVoices(); ++i )
        {
            ((TWSVoice *)getVoice(i))->synthModWheel = val;
        }
    }
    Synthesiser::handleController(chan, cont, val);
}

/*
** This is where we can place per-synth as opposed to per-voice things
** in our case: a delay line and a saturator and a master gain
*/
void TWSSynthesiser::renderVoices( AudioBuffer<float> &b, int s, int n )
{
    if( lineL.size() < getSampleRate() * MAX_DELAY_TIME + 100 )
    {
        lineL.resize( getSampleRate() * MAX_DELAY_TIME + 100 );
        lineR.resize( getSampleRate() * MAX_DELAY_TIME + 100 );
        for( int i=0; i<lineL.size(); ++i )
        {
            lineL[i] = 0;
            lineR[i] = 0;
        }
        delayPos = 0;
        delaySize = lineL.size();
    }
    Synthesiser::renderVoices(b,s,n);

    if( *(processor.delay_on) != 0 )
    {
        delayT.setTargetValue( *(processor.delay_time) );
        delayFB.setTargetValue( *(processor.delay_fb ) );
        delayWet.setTargetValue( *(processor.delay_wet ) );
        delayDry.setTargetValue( *(processor.delay_dry ) );

        lastDelayOn = true;
        
        for( int i=0; i<n; ++i )
        {
            long ago = getSampleRate() * ( delayT.getNextValue() ); // should really interp
            if( ago >= delaySize ) ago=delaySize-1;
            if( ago < 1 ) ago = 1;
            float fb = delayFB.getNextValue();
            
            long p = delayPos - ago;
            if( p < 0 ) p += delaySize;
            
            float sL = b.getSample(0,s+i);
            float sR = b.getSample(1,s+i);

            auto delL = lineL[p]; // INTERP
            auto delR = lineR[p]; // INTERP
            
            lineL[delayPos] = sL + fb * delL;
            lineR[delayPos] = sR + fb * delR;

            // Now sample is wet + dry
            auto wm = delayWet.getNextValue();
            auto dm = delayDry.getNextValue();

            auto newL = dm * sL + wm * delL;
            auto newR = dm * sR + wm * delR;

            b.setSample(0,s+i,newL);
            b.setSample(1,s+i,newR);

            delayPos ++;
            if( delayPos >= delaySize)
                delayPos = 0;
        }
    }
    else
    {
        if( lastDelayOn )
        {
            for( int i=0; i<lineL.size(); ++i )
            {
                lineL[i] = 0;
                lineR[i] = 0;
            }
            delayPos = 0;
            delaySize = lineL.size();
        }
        lastDelayOn = false;
    }

    float ml = *(processor.master_level);
    float ms = *(processor.master_sat);
    
    for( int i=0; i<n; ++i )
    {
        // FIXME - there must be a vectorized way to do this
        float sL = b.getSample(0,s+i);
        float sR = b.getSample(1,s+i);
        // overdrive into a cubic soft clipper
        sL *= ( 1.0 + ms );
        sL = std::min( 1.f, std::max( -1.f, sL ) );
        sL = 1.5 * sL - 0.5 * sL * sL * sL;

        sR *= ( 1.0 + ms );
        sR = std::min( 1.f, std::max( -1.f, sR ) );
        sR = 1.5 * sR - 0.5 * sR * sR * sR;
        
        b.setSample(0,s+i,sL * ml);
        b.setSample(1,s+i,sR * ml);
    }

}
