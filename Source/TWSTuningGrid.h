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
#include <atomic>
#include <array>
#include <surgesynthteam_tuningui/surgesynthteam_tuningui.h>
class TWSMainPanel;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TWSTuningGrid  : public Component,
                       public TuningUpdatedListener,
                       public NotesOnChangedListener
{
public:
    //==============================================================================
    TWSTuningGrid ();
    ~TWSTuningGrid() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    virtual void tuningUpdated( const Tunings::Tuning &newTuning ) override {
        mod->tuningUpdated(newTuning);
    }
    virtual void noteOn( int noteNum ) override {
        mod->noteOn(noteNum);
    }
    virtual void noteOff( int noteNum ) override {
        mod->noteOff(noteNum);
    }

    friend class TWSMainPanel;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<surgesynthteam::TuningTableListBoxModel> mod;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TableListBox> table;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TWSTuningGrid)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

