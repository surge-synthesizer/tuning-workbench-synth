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

//[Headers] You can add your own extra header files here...
#include "Constants.h"
//[/Headers]

#include "TWSAbout.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TWSAbout::TWSAbout ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    version.reset (new Label ("new label",
                              TRANS("VERSION\n")));
    addAndMakeVisible (version.get());
    version->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    version->setJustificationType (Justification::centred);
    version->setEditable (false, false, false);
    version->setColour (TextEditor::textColourId, Colours::black);
    version->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    builddate.reset (new Label ("new label",
                                TRANS("BUILD DATE\n")));
    addAndMakeVisible (builddate.get());
    builddate->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    builddate->setJustificationType (Justification::centred);
    builddate->setEditable (false, false, false);
    builddate->setColour (TextEditor::textColourId, Colours::black);
    builddate->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    builddate2.reset (new Label ("new label",
                                 TRANS("Released under GPL v3\n")));
    addAndMakeVisible (builddate2.get());
    builddate2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    builddate2->setJustificationType (Justification::centred);
    builddate2->setEditable (false, false, false);
    builddate2->setColour (TextEditor::textColourId, Colours::black);
    builddate2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    builddate3.reset (new Label ("new label",
                                 TRANS("Copyright 2019-2020\n")));
    addAndMakeVisible (builddate3.get());
    builddate3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    builddate3->setJustificationType (Justification::centred);
    builddate3->setEditable (false, false, false);
    builddate3->setColour (TextEditor::textColourId, Colours::black);
    builddate3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    builddate4.reset (new Label ("new label",
                                 TRANS("Various Authors\n")));
    addAndMakeVisible (builddate4.get());
    builddate4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    builddate4->setJustificationType (Justification::centred);
    builddate4->setEditable (false, false, false);
    builddate4->setColour (TextEditor::textColourId, Colours::black);
    builddate4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    githubButton.reset (new TextButton ("new button"));
    addAndMakeVisible (githubButton.get());
    githubButton->setButtonText (TRANS("Source on GitHub"));
    githubButton->addListener (this);

    githubButton->setBounds (25, 296, 158, 24);

    licenseButton.reset (new TextButton ("new button"));
    addAndMakeVisible (licenseButton.get());
    licenseButton->setButtonText (TRANS("Read the License"));
    licenseButton->addListener (this);

    licenseButton->setBounds (25, 328, 158, 24);

    teamButton.reset (new TextButton ("new button"));
    addAndMakeVisible (teamButton.get());
    teamButton->setButtonText (TRANS("About the Team"));
    teamButton->addListener (this);

    teamButton->setBounds (25, 360, 158, 24);

    drawable1 = Drawable::createFromImageData (BinaryData::TWSLogo_Inverted_NoBG_120_png, BinaryData::TWSLogo_Inverted_NoBG_120_pngSize);

    //[UserPreSize]
    version->setText( "version: " TWS_VERSION, dontSendNotification );
    builddate->setText( "built: " __DATE__, dontSendNotification );
    //[/UserPreSize]

    setSize (208, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TWSAbout::~TWSAbout()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    version = nullptr;
    builddate = nullptr;
    builddate2 = nullptr;
    builddate3 = nullptr;
    builddate4 = nullptr;
    githubButton = nullptr;
    licenseButton = nullptr;
    teamButton = nullptr;
    drawable1 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TWSAbout::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 0, y = 112, width = proportionOfWidth (1.0000f), height = 27;
        String text (TRANS("Tuning Workbench"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (22.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 0, y = 135, width = proportionOfWidth (1.0000f), height = 30;
        String text (TRANS("A Surge Synth Team Product"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 40, y = 0, width = 120, height = 120;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black);
        jassert (drawable1 != nullptr);
        if (drawable1 != nullptr)
            drawable1->drawWithin (g, Rectangle<int> (x, y, width, height).toFloat(),
                                   RectanglePlacement::stretchToFit, 1.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TWSAbout::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    version->setBounds (0, 170, proportionOfWidth (1.0000f), 24);
    builddate->setBounds (0, 194, proportionOfWidth (1.0000f), 24);
    builddate2->setBounds (0, 226, proportionOfWidth (1.0000f), 24);
    builddate3->setBounds (0, 244, proportionOfWidth (1.0000f), 24);
    builddate4->setBounds (0, 263, proportionOfWidth (1.0000f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TWSAbout::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == githubButton.get())
    {
        //[UserButtonCode_githubButton] -- add your button handler code here..
        URL( "https://github.com/surge-synthesizer/tuning-workbench-synth/" ).launchInDefaultBrowser();
        //[/UserButtonCode_githubButton]
    }
    else if (buttonThatWasClicked == licenseButton.get())
    {
        //[UserButtonCode_licenseButton] -- add your button handler code here..
        URL( "https://www.gnu.org/licenses/gpl-3.0.en.html" ).launchInDefaultBrowser();
        //[/UserButtonCode_licenseButton]
    }
    else if (buttonThatWasClicked == teamButton.get())
    {
        //[UserButtonCode_teamButton] -- add your button handler code here..
        URL( "https://surge-synth-team.org/" ).launchInDefaultBrowser();
        //[/UserButtonCode_teamButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TWSAbout" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="208" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="0 112 100% 27" fill="solid: ffffffff" hasStroke="0" text="Tuning Workbench"
          fontname="Default font" fontsize="22.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="0 135 100% 30" fill="solid: ffffffff" hasStroke="0" text="A Surge Synth Team Product"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <IMAGE pos="40 0 120 120" resource="BinaryData::TWSLogo_Inverted_NoBG_120_png"
           opacity="1.0" mode="0"/>
  </BACKGROUND>
  <LABEL name="new label" id="58511ee6b81396c6" memberName="version" virtualName=""
         explicitFocusOrder="0" pos="0 170 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="VERSION&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="63f949d172f6adaa" memberName="builddate"
         virtualName="" explicitFocusOrder="0" pos="0 194 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="BUILD DATE&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bff6615291674353" memberName="builddate2"
         virtualName="" explicitFocusOrder="0" pos="0 226 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Released under GPL v3&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="95f7900bf16d3843" memberName="builddate3"
         virtualName="" explicitFocusOrder="0" pos="0 244 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Copyright 2019-2020&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="23a8dc5ee93fb0da" memberName="builddate4"
         virtualName="" explicitFocusOrder="0" pos="0 263 100% 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Various Authors&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="new button" id="a6b2546fe131d228" memberName="githubButton"
              virtualName="" explicitFocusOrder="0" pos="25 296 158 24" buttonText="Source on GitHub"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="102b12e5926e90e7" memberName="licenseButton"
              virtualName="" explicitFocusOrder="0" pos="25 328 158 24" buttonText="Read the License"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="4d151adf80975a44" memberName="teamButton"
              virtualName="" explicitFocusOrder="0" pos="25 360 158 24" buttonText="About the Team"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

