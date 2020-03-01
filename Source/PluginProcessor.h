/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Tunings.h"
#include <set>
#include "TuningListener.h"

//==============================================================================
/**
*/

class TWSVoice;
class TWSMainPanel;
class TuningworkbenchsynthAudioProcessor;

class TWSSynthesiser : public Synthesiser {
public:
    TWSSynthesiser(TuningworkbenchsynthAudioProcessor &p);
protected:
    TuningworkbenchsynthAudioProcessor &processor;
    virtual void renderVoices( AudioBuffer<float> &b, int s, int n ) override;

    std::vector<float> lineL, lineR;
    size_t delayPos;
    size_t delaySize;
    bool lastDelayOn = true;
};


class TuningworkbenchsynthAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    TuningworkbenchsynthAudioProcessor();
    ~TuningworkbenchsynthAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    // == tuning support ==
    void addTuningUpdatedListener( TuningUpdatedListener *l ) { tuningListeners.insert( l ); }
    void removeTuningUpdatedListener( TuningUpdatedListener *l ) { tuningListeners.erase( l ); }
    void setSCL( String SCL, bool retune = true );
    void setKBM( String KBM, bool retune = true );
    void resetSCLToStandard() {
        auto s = Tunings::evenTemperament12NoteScale();
        setSCL( s.rawText );
    }
    void resetKBMToStandard() {
        setKBM( "" );
    }

    void retune();

    std::set< TuningUpdatedListener * > tuningListeners;
    Tunings::Tuning tuning;
    String currentSCLString = "", currentKBMString = "";
    
    friend class TWSVoice;
    friend class TWSMainPanel;
    friend class TWSSynthesiser;
    
private:
    TWSSynthesiser synth;
    AudioProcessorValueTreeState parameters;

    std::atomic<float> *sinLevel, *squareLevel, *sawLevel, *triLevel;
    std::atomic<float> *uni_count; // as float
    std::atomic<float> *uni_spread;

    std::atomic<float> *pb_down, *pb_up; // as float

    std::atomic<float> *amp_attack, *amp_decay, *amp_sustain, *amp_release;
    std::atomic<float> *filter_attack, *filter_decay, *filter_sustain, *filter_release, *filter_depth;

    std::atomic<float> *filter_type;
    std::atomic<float> *filter_cutoff, *filter_resonance;

    std::atomic<float> *master_sat, *master_level;

    std::atomic<float> *subosc_level, *subosc_oct;
    std::atomic<float> *pluck_flt, *pluck_atn, *pluck_init, *pluck_lev;
    std::atomic<float> *delay_time, *delay_fb;

    std::atomic<float> *lfo_type, *lfo_rate, *lfo_delay, *lfo_attack, *lfo_pitch, *lfo_filter;

    std::atomic<float> *vco_on, *sub_on, *pluck_on, *delay_on, *modwheel_on, *filter_on;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TuningworkbenchsynthAudioProcessor)
};
