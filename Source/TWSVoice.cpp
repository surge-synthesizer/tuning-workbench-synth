/**
 * This file contains all the DSP.
 *
 * Warning: The DSP isn't very good!
 */

#include "TWSVoice.h"
#include "PluginProcessor.h"

void TWSVoice::startNote (int midiNoteNumber, float velocity,
                          SynthesiserSound*, int currentPitchWheelPosition) 
{
    level = velocity * 0.15;

    nunison = std::max( 1, (int)( *(p->uni_count) ) );
    // Here is where we apply the tuning
    auto cyclesPerSecond = p->tuning.frequencyForMidiNote(midiNoteNumber);

    if( nunison == 1 )
    {
        auto cyclesPerSample = cyclesPerSecond / getSampleRate();
        currentAngle[0] = 0;
        angleDelta[0] = cyclesPerSample;
        pan[0] = 0;
        dDelta[0] = 0;
    }
    else
    {
        auto noteDown = p->tuning.frequencyForMidiNote( midiNoteNumber - 1 );
        auto noteUp   = p->tuning.frequencyForMidiNote( midiNoteNumber + 1 );

        double uso = *( p->uni_spread ) / 100.0 * 2.0; // the 2.0 is for up and down
        double duso = uso / (nunison - 1);
        double sso = -uso / 2;

        level /= sqrt(nunison - 1);
        
        for( int i=0; i<nunison; ++i )
        {
            double frc = duso * i + sso;
            auto cyc = cyclesPerSecond;
            if( frc < 0 )
            {
                // between down and center
                cyc = -frc * noteDown + ( 1 + frc ) * cyclesPerSecond;
            }
            else
            {
                cyc = frc * noteUp + ( 1 - frc ) * cyclesPerSecond;
            }

            auto cyclesPerSample = cyc / getSampleRate();

            currentAngle[i] = 1.0 * rand() / RAND_MAX;
            angleDelta[i] = cyclesPerSample;
            pan[i] = 2.0 * i / ( nunison - 1 ) - 1.0;
            dDelta[i] = 0;
        }
    }

    ampenv.setSampleRate( getSampleRate() );
    auto ap = ampenv.getParameters();
    ap.attack = *( p->amp_attack );
    ap.decay = *( p->amp_decay );
    ap.sustain = *( p->amp_sustain );
    ap.release = *( p->amp_release );
    ap.release = std::max( ap.release, 0.01f );
    ampenv.setParameters(ap);

    sinLevel.reset( 32 );
    sinLevel.setCurrentAndTargetValue( *( p->sinLevel ) );
    
    squareLevel.reset( 32 );
    squareLevel.setCurrentAndTargetValue( *( p->squareLevel ) );
    
    sawLevel.reset( 32 );
    sawLevel.setCurrentAndTargetValue( *( p->sawLevel ) );
    
    triLevel.reset( 32 );
    triLevel.setCurrentAndTargetValue( *( p->triLevel ) );
    
    ampenv.noteOn();
}

void TWSVoice::stopNote (float velocity, bool allowTailOff) 
{
    ampenv.noteOff();
}

void TWSVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) 
{
    if( ! isVoiceActive() ) return;

    sinLevel.setTargetValue( *( p->sinLevel ) );
    squareLevel.setTargetValue( *( p->squareLevel ) );
    sawLevel.setTargetValue( *( p->sawLevel ) );
    triLevel.setTargetValue( *( p->triLevel ) );
    

    while (--numSamples >= 0)
    {
        // doto - lose the current
        auto sampleL = 0.0f;
        auto sampleR = 0.0f;

        auto AEG = ampenv.getNextSample() * level;

        auto sinlv = sinLevel.getNextValue();
        auto sqrlv = squareLevel.getNextValue();
        auto sawlv = sawLevel.getNextValue();
        auto trilv = triLevel.getNextValue();
        
        for( int i=0; i<nunison; ++i )
        {
            auto ca = currentAngle[i];

            // Obviously these waveforms suck
            auto oscSin = (float) std::sin ( 2.0 * MathConstants<double>::pi * ca) * sinlv;
            auto oscSqr = (float) ( ( ca > 0.5 ) ? 1.f : -1.f ) * sqrlv;
            auto oscSaw = (float) ( ( ca - 0.5 ) * 2.0 ) * sawlv;
            auto oscTri = (float) ( ( ( ca > 0.5 ) ? 0.5 - ca : ca ) - 0.25 ) * 4.0 * trilv;

            auto currentVoice = AEG * ( oscSqr + oscSin + oscSaw + oscTri );

            // http://www.cs.cmu.edu/~music/icm-online/readings/panlaws/
            // FIXME - make this more efficient by using a lookup table obvs
            auto piby2 = MathConstants<double>::pi / 2.0;
            auto panAngle = ( pan[i] + 1.0 ) * MathConstants<double>::pi / 4.0;
            auto lW = sqrt( ( piby2 - panAngle ) / piby2 * cos( panAngle ) );
            auto rW = sqrt( panAngle * sin( panAngle ) / piby2 );

            // std::cout << "lW/rW=" << lW << " " << rW << " " << panAngle << std::endl;
            sampleL += lW * currentVoice;
            sampleR += rW * currentVoice;
            
            currentAngle[i] += angleDelta[i];
            if( currentAngle[i] > 1.0 )
                currentAngle[i] -= 1.0;
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
    if( ! ampenv.isActive() && isVoiceActive() )
    {
        clearCurrentNote();
    }
    

}


