// -*-c++-*-
#pragma once

#include <JuceHeader.h>
#include <iostream>
#include "Constants.h"

class TuningworkbenchsynthAudioProcessor;

//==============================================================================
class TWSSound   : public SynthesiserSound
{
public:
    TWSSound(TuningworkbenchsynthAudioProcessor *i) : p(i) {}

    bool appliesToNote    (int) override        { return true; }
    bool appliesToChannel (int) override        { return true; }

    TuningworkbenchsynthAudioProcessor *p;
};

//==============================================================================
class TWSVoice   : public SynthesiserVoice
{
public:
    TWSVoice(TuningworkbenchsynthAudioProcessor *i);

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

    static const int N_PAN = 1000;
    double panBufferL[N_PAN], panBufferR[N_PAN];
    
    SmoothedValue<float> sinLevel, squareLevel, sawLevel, triLevel;

    SmoothedValue<float> filterCut, filterRes, filterDepth;
    IIRFilter filterL, filterR;
    
    ADSR ampenv, filtenv;
};
