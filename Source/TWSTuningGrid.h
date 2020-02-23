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
class TWSTuningGrid  : public Component,
                       public TableListBoxModel,
                       public TuningUpdatedListener
{
public:
    //==============================================================================
    TWSTuningGrid ();
    ~TWSTuningGrid() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    virtual int getNumRows() override { return 128; }
    virtual void paintRowBackground( Graphics &g, int rowNumber, int width, int height, bool rowIsSelected ) override;
    virtual void paintCell( Graphics &g, int rowNumber, int columnId, int width, int height, bool rowIsSelected ) override;
    virtual void tuningUpdated( const Tunings::Tuning &newTuning ) override {
        tuning = newTuning;
        // updateContent();
        repaint();
    }

    friend class TWSMainPanel;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Tunings::Tuning tuning;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TableListBox> table;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TWSTuningGrid)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

