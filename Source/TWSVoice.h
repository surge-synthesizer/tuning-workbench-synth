// -*-c++-*-
#pragma once

#include <JuceHeader.h>
#include <iostream>
#include "Constants.h"

class TuningworkbenchsynthAudioProcessor;

//==============================================================================
struct TWSSound   : public SynthesiserSound
{
    TWSSound(TuningworkbenchsynthAudioProcessor *i) : p(i) {}

    bool appliesToNote    (int) override        { return true; }
    bool appliesToChannel (int) override        { return true; }

    TuningworkbenchsynthAudioProcessor *p;
};

//==============================================================================
struct TWSVoice   : public SynthesiserVoice
{
    TWSVoice(TuningworkbenchsynthAudioProcessor *i) : p(i) {}

    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<TWSSound*> (sound) != nullptr;
    }

    void startNote (int midiNoteNumber, float velocity,
                    SynthesiserSound*, int currentPitchWheelPosition) override;

    void stopNote (float /*velocity*/, bool allowTailOff) override;

    void pitchWheelMoved (int pw) override
    {
        double pwf = (1.0 * pw - 8192)/8192;
        std::cout << "pitchWheel is at " << pwf << std::endl;
    }
    void controllerMoved (int, int) override {}

    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

private:
    TuningworkbenchsynthAudioProcessor *p;

    double currentAngle[MAX_UNISON], angleDelta[MAX_UNISON], level = 0.0;
    int nunison;
    double dDelta[MAX_UNISON], pan[MAX_UNISON];

    SmoothedValue<float> sinLevel, squareLevel, sawLevel, triLevel;
    
    ADSR ampenv, filtenv;
};
