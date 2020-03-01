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

    SmoothedValue<float> delayT, delayFB;
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

    void addNotesOnChangedListener( NotesOnChangedListener *l ) { noteListeners.insert( l ); }
    void removeNotesOnChangedListener( NotesOnChangedListener *l ) { noteListeners.erase( l ); }
    std::set< NotesOnChangedListener * > noteListeners;

    Tunings::Tuning tuning;
    String currentSCLString = "", currentKBMString = "";
    
    friend class TWSVoice;
    friend class TWSMainPanel;
    friend class TWSSynthesiser;
    
private:
    TWSSynthesiser synth;

    AudioProcessorValueTreeState parameters;


    std::unique_ptr<AudioParameterFloat> envelopeTimeParam( String tag, String name, float init, float min = 0, float max = 10 )
        {
            return std::make_unique<AudioParameterFloat>( tag, name,
                                                          NormalisableRange<float>(
                                                              0, 10,
                                                              [](float start, float end, float value ) -> float {
                                                                  // basically we want ( e^v/e^1 ) * end
                                                                  auto r = ( exp( value ) - 1 ) / ( exp(1) - 1 )  * end;
                                                                  return r;
                                                              },
                                                              [](float start, float end, float value ) -> float {
                                                                  // r = (e^v-1)/(e^1-1)*end
                                                                  // r / end * (e^1-1) + 1 = e^v;
                                                                  auto r = log( value / end * ( exp(1) - 1 ) + 1 );
                                                                  return r;
                                                              } ),
                                                             init,
                                                             "", AudioProcessorParameter::genericParameter,
                                                             [](float v, int length) -> String
                                                                 {
                                                                     String asText(v,2);
                                                                     return ( length > 0 ? asText.substring( 0, length ) : asText );
                                                                 },
                                                             [](const String& text ) -> float { return text.getFloatValue(); }
                );
        }
    std::unique_ptr<AudioParameterFloat> expRangeParam( String tag, String name, float low, float high, float init )
        {
            return std::make_unique<AudioParameterFloat>( tag, name,
                                                          NormalisableRange<float>(
                                                              low, high,
                                                              [](float start, float end, float value ) -> float {
                                                                     // So we want 2^x flavor here
                                                                     // 2^0 + b = 10 -> b = 10
                                                                     // 2^a + b = 20000 - a = log_2( 19000 )
                                                                     auto b = start;
                                                                     auto a = log(end-start)/log(2);
                                                                     auto r = pow( 2.0, a * value ) + b;
                                                                     
                                                                     return r;
                                                                 },
                                                                 [](float start, float end, float value ) -> float {
                                                                     // 2^ar + b = v
                                                                     // 2^ar = v - b;
                                                                     // r = log2(v-b)/a
                                                                     // a = log2(end-start)
                                                                     // r = log2(v-start)/log2(end-start)
                                                                     auto r = log(value - start)/log(end - start);
                                                                     return r;
                                                                 } ),
                                                             init,
                                                             "", AudioProcessorParameter::genericParameter,
                                                             [](float v, int length) -> String
                                                                 {
                                                                     String asText(v,2);
                                                                     return ( length > 0 ? asText.substring( 0, length ) : asText );
                                                                 },
                                                             [](const String& text ) -> float { return text.getFloatValue(); }
                );
        }
    
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
