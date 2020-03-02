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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TWSAbout  : public Component,
                  public Button::Listener
{
public:
    //==============================================================================
    TWSAbout ();
    ~TWSAbout() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> version;
    std::unique_ptr<Label> builddate;
    std::unique_ptr<Label> builddate2;
    std::unique_ptr<Label> builddate3;
    std::unique_ptr<Label> builddate4;
    std::unique_ptr<TextButton> githubButton;
    std::unique_ptr<TextButton> licenseButton;
    std::unique_ptr<TextButton> teamButton;
    std::unique_ptr<Drawable> drawable1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TWSAbout)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

