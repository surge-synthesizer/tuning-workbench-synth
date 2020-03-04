/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
class TWSMainPanel;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TWSTextAndControls  : public Component,
                            public TuningUpdatedListener,
                            public TextEditor::Listener,
                            public Button::Listener
{
public:
    //==============================================================================
    TWSTextAndControls (bool isSCL, TuningworkbenchsynthAudioProcessor &p);
    ~TWSTextAndControls() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    friend class TWSMainPanel;
    void tuningUpdated( const Tunings::Tuning &newTuning ) override;
    virtual void textEditorTextChanged( TextEditor &t ) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    bool isSCL;
    bool supressFirstTextChange;
    TuningworkbenchsynthAudioProcessor &processor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TextEditor> textEditor;
    std::unique_ptr<TextButton> applyButton;
    std::unique_ptr<TextButton> openButton;
    std::unique_ptr<TextButton> exportButton;
    std::unique_ptr<TextButton> resetButton;
    std::unique_ptr<TextButton> advButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TWSTextAndControls)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

