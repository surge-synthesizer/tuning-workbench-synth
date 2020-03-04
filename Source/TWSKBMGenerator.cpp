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
//[/Headers]

#include "TWSKBMGenerator.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TWSKBMGenerator::TWSKBMGenerator (TuningworkbenchsynthAudioProcessor &p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupComponent.reset (new GroupComponent ("new group",
                                              TRANS("Generate Mapping")));
    addAndMakeVisible (groupComponent.get());

    groupComponent->setBounds (2, 1, 296, 144);

    scaleStart.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (scaleStart.get());
    scaleStart->setMultiLine (false);
    scaleStart->setReturnKeyStartsNewLine (false);
    scaleStart->setReadOnly (false);
    scaleStart->setScrollbarsShown (true);
    scaleStart->setCaretVisible (true);
    scaleStart->setPopupMenuEnabled (true);
    scaleStart->setText (TRANS("60"));

    scaleStart->setBounds (176, 24, 104, 24);

    tuneNote.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (tuneNote.get());
    tuneNote->setMultiLine (false);
    tuneNote->setReturnKeyStartsNewLine (false);
    tuneNote->setReadOnly (false);
    tuneNote->setScrollbarsShown (true);
    tuneNote->setCaretVisible (true);
    tuneNote->setPopupMenuEnabled (true);
    tuneNote->setText (TRANS("69"));

    tuneNote->setBounds (176, 64, 104, 24);

    tuneFreq.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (tuneFreq.get());
    tuneFreq->setMultiLine (false);
    tuneFreq->setReturnKeyStartsNewLine (false);
    tuneFreq->setReadOnly (false);
    tuneFreq->setScrollbarsShown (true);
    tuneFreq->setCaretVisible (true);
    tuneFreq->setPopupMenuEnabled (true);
    tuneFreq->setText (TRANS("440.0"));

    tuneFreq->setBounds (176, 104, 104, 24);

    applyButton.reset (new TextButton ("new button"));
    addAndMakeVisible (applyButton.get());
    applyButton->setButtonText (TRANS("Apply"));
    applyButton->addListener (this);

    applyButton->setBounds (192, 152, 102, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 184);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TWSKBMGenerator::~TWSKBMGenerator()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent = nullptr;
    scaleStart = nullptr;
    tuneNote = nullptr;
    tuneFreq = nullptr;
    applyButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TWSKBMGenerator::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 14, y = 20, width = 200, height = 30;
        String text (TRANS("Scale starts at note:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 14, y = 60, width = 200, height = 30;
        String text (TRANS("Tune this midi note:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 14, y = 100, width = 200, height = 30;
        String text (TRANS("To this frequency (hz):"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TWSKBMGenerator::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TWSKBMGenerator::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == applyButton.get())
    {
        //[UserButtonCode_applyButton] -- add your button handler code here..
        int ss = scaleStart->getText().getIntValue();
        int mn = tuneNote->getText().getIntValue();
        double fr = tuneFreq->getText().getDoubleValue();

        if( ss < 0 || ss > 127 || mn < 0 || mn > 127 || fr < 10 || fr > 10000 )
        {
            // Error condition
        }
        else
        {
            auto k = Tunings::startScaleOnAndTuneNoteTo( ss, mn, fr );
            processor.setKBM( k.rawText, true );
        }
        //[/UserButtonCode_applyButton]
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

<JUCER_COMPONENT documentType="Component" className="TWSKBMGenerator" componentName=""
                 parentClasses="public Component" constructorParams="TuningworkbenchsynthAudioProcessor &amp;p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="300"
                 initialHeight="184">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="14 20 200 30" fill="solid: ffffffff" hasStroke="0" text="Scale starts at note:"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="14 60 200 30" fill="solid: ffffffff" hasStroke="0" text="Tune this midi note:"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="14 100 200 30" fill="solid: ffffffff" hasStroke="0" text="To this frequency (hz):"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="481da90cff4b77d7" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="2 1 296 144" title="Generate Mapping"/>
  <TEXTEDITOR name="new text editor" id="a239267d6217951a" memberName="scaleStart"
              virtualName="" explicitFocusOrder="0" pos="176 24 104 24" initialText="60"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="48d363c09cdf1ba9" memberName="tuneNote"
              virtualName="" explicitFocusOrder="0" pos="176 64 104 24" initialText="69"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="bae1809c112cf834" memberName="tuneFreq"
              virtualName="" explicitFocusOrder="0" pos="176 104 104 24" initialText="440.0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="4a8695af84a4d834" memberName="applyButton"
              virtualName="" explicitFocusOrder="0" pos="192 152 102 24" buttonText="Apply"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

