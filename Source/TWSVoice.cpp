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

    // Here is where we apply the tuning
    auto cyclesPerSecond = p->tuning.frequencyForMidiNote(midiNoteNumber);
    auto cyclesPerSample = cyclesPerSecond / getSampleRate();

    nunison = std::max( 1, (int)( *(p->uni_count) ) );
    nunison = 1;
    
    for( int i=0; i<nunison; ++i )
    {
        currentAngle[0] = rand() * 1.0 / RAND_MAX;
        angleDelta[i] = cyclesPerSample;
        pan[i] = 0;
        dDelta[i] = 0;
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
            
            // fixme - don't ignore pan
            sampleL += currentVoice;
            sampleR += currentVoice;
            
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
        static int si = 0;
        clearCurrentNote();
    }
    

}


