// -*-c++-*-
#pragma once

#include <JuceHeader.h>
#include <iostream>
#include "Constants.h"
#include "Tunings.h"
#include "TuningListener.h"

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
class TWSVoice   : public SynthesiserVoice, public TuningUpdatedListener
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
        setPitchWheel( pw );
    }

    void controllerMoved (int, int) override {}

    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    virtual void tuningUpdated( const Tunings::Tuning &newTuning ) override;

private:
    void setPitchWheel( int pw ) {
        pwAmount = (1.0 * pw - 8192)/8192;
    }

    double pitchWheelNoteShift();
        
    double frequencyForFractionalNote( double fracNote );
        
    int noteNum;
    double pwAmount;
    double priorRenderedPW = 0;
    
    
    TuningworkbenchsynthAudioProcessor *p;

    double currentAngle[MAX_UNISON], angleDelta[MAX_UNISON], level = 0.0;
    double subAngle, subAngleDelta;
    
    int nunison;
    double dDelta[MAX_UNISON], pan[MAX_UNISON];

    static const int N_PAN = 1000;
    double panBufferL[N_PAN], panBufferR[N_PAN];
    
    SmoothedValue<float> sinLevel, squareLevel, sawLevel, triLevel;
    SmoothedValue<float> subLevel;
    
    SmoothedValue<float> filterCut, filterRes, filterDepth;
    IIRFilter filterL, filterR;
    int filterTypeAtOutset;

    // Pluck oscillator
    std::vector<float> pluckDelayLine;
    size_t pluckDelayLineSize;
    float pluckSampleDelay, fracPluckSampleDelay;
    int iPluckSampleDelay;
    size_t pluckDelayPos;
    SmoothedValue<float> pluckWeight, pluckAtten, pluckLevel;
    float pluckAttenNorm;
    
    std::atomic<bool> needsRetune;
    
    ADSR ampenv, filtenv, pluckenv; // pluck env has no user parameters
};
