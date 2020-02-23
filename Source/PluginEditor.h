/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "TWSMainPanel.h"

//==============================================================================
/**
*/
class TuningworkbenchsynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    TuningworkbenchsynthAudioProcessorEditor (TuningworkbenchsynthAudioProcessor&, AudioProcessorValueTreeState &);
    ~TuningworkbenchsynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    TWSMainPanel mainPanel;
private:

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TuningworkbenchsynthAudioProcessor& processor;
    AudioProcessorValueTreeState &parameters;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TuningworkbenchsynthAudioProcessorEditor)
};
