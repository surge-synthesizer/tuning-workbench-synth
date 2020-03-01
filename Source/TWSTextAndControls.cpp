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
#include "Tunings.h"
//[/Headers]

#include "TWSTextAndControls.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TWSTextAndControls::TWSTextAndControls (bool isSCL, TuningworkbenchsynthAudioProcessor &p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    this->isSCL = isSCL;
    //[/Constructor_pre]

    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (true);
    textEditor->setReturnKeyStartsNewLine (true);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String());

    applyButton.reset (new TextButton ("new button"));
    addAndMakeVisible (applyButton.get());
    applyButton->setButtonText (TRANS("Apply"));
    applyButton->addListener (this);

    applyButton->setBounds (346, 298, 78, 24);

    openButton.reset (new TextButton ("open file"));
    addAndMakeVisible (openButton.get());
    openButton->setButtonText (TRANS("Open"));
    openButton->addListener (this);

    openButton->setBounds (94, 298, 78, 24);

    exportButton.reset (new TextButton ("export file"));
    addAndMakeVisible (exportButton.get());
    exportButton->setButtonText (TRANS("Export"));
    exportButton->addListener (this);

    exportButton->setBounds (10, 298, 78, 24);

    resetButton.reset (new TextButton ("reset"));
    addAndMakeVisible (resetButton.get());
    resetButton->setButtonText (TRANS("Reset"));
    resetButton->addListener (this);

    resetButton->setBounds (262, 298, 78, 24);

    advButton.reset (new TextButton ("open file"));
    addAndMakeVisible (advButton.get());
    advButton->setButtonText (TRANS("Advanced"));
    advButton->addListener (this);

    advButton->setBounds (178, 298, 78, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (432, 328);


    //[Constructor] You can add your own custom stuff here..
    auto tf = Typeface::createSystemTypefaceFor(BinaryData::FiraCodeRegular_ttf, BinaryData::FiraCodeRegular_ttfSize);
    Font fira(tf);
    fira.setHeight(15);
    textEditor->setFont(fira);

    if( isSCL )
    {
        applyButton->setButtonText( TRANS( "Apply" ) );
        openButton->setButtonText( TRANS( "Load" ) );
    }
    else
    {
        applyButton->setButtonText( TRANS( "Apply" ) );
        openButton->setButtonText( TRANS( "Load" ) );
    }
    applyButton->setEnabled( false );
    textEditor->addListener( this );
    //[/Constructor]
}

TWSTextAndControls::~TWSTextAndControls()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textEditor = nullptr;
    applyButton = nullptr;
    openButton = nullptr;
    exportButton = nullptr;
    resetButton = nullptr;
    advButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TWSTextAndControls::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TWSTextAndControls::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textEditor->setBounds (0, 0, proportionOfWidth (1.0000f), 288);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TWSTextAndControls::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == applyButton.get())
    {
        //[UserButtonCode_applyButton] -- add your button handler code here..
        if( isSCL )
            processor.setSCL( textEditor->getText() );
        else
            processor.setKBM( textEditor->getText() );
        //[/UserButtonCode_applyButton]
    }
    else if (buttonThatWasClicked == openButton.get())
    {
        //[UserButtonCode_openButton] -- add your button handler code here..
        FileChooser fc( isSCL ? "Open SCL File" : "Open KBM File", File(), isSCL ? "*.scl" : "*.kbm" );
        if( fc.browseForFileToOpen() )
        {
            auto s = fc.getResult().loadFileAsString();
            processor.setSCL(s);
        }
        //[/UserButtonCode_openButton]
    }
    else if (buttonThatWasClicked == exportButton.get())
    {
        //[UserButtonCode_exportButton] -- add your button handler code here..
        FileChooser fc( isSCL ? "Export SCL File" : "Export KBM File" );
        if( fc.browseForFileToSave(true) )
        {
            auto f = fc.getResult();
            if( ! f.replaceWithText( textEditor->getText() ) )
            {
                AlertWindow::showMessageBoxAsync( AlertWindow::AlertIconType::WarningIcon,
                                                  "Error exporting file",
                                                  "An unknown error occured streaming data to file",
                                                  "OK" );

            }
        }
        //[/UserButtonCode_exportButton]
    }
    else if (buttonThatWasClicked == resetButton.get())
    {
        //[UserButtonCode_resetButton] -- add your button handler code here..
        if( isSCL )
            processor.resetSCLToStandard();
        else
            processor.resetKBMToStandard();
        //[/UserButtonCode_resetButton]
    }
    else if (buttonThatWasClicked == advButton.get())
    {
        //[UserButtonCode_advButton] -- add your button handler code here..
        //[/UserButtonCode_advButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TWSTextAndControls::tuningUpdated( const Tunings::Tuning &newTuning )
{
    if( isSCL )
    {
        textEditor->setText( newTuning.scale.rawText );
    }
    else
    {
        textEditor->setText( newTuning.keyboardMapping.rawText );
    }
    applyButton->setEnabled( false );
}

void TWSTextAndControls::textEditorTextChanged(TextEditor &t) {
    applyButton->setEnabled( true );
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TWSTextAndControls" componentName=""
                 parentClasses="public Component, public TuningUpdatedListener, public TextEditor::Listener"
                 constructorParams="bool isSCL, TuningworkbenchsynthAudioProcessor &amp;p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="432"
                 initialHeight="328">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTEDITOR name="new text editor" id="3ad00fda4fd6209c" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="0 0 100% 288" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="1e4d84268b671e98" memberName="applyButton"
              virtualName="" explicitFocusOrder="0" pos="346 298 78 24" buttonText="Apply"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="open file" id="ba3c0d0c50f8320e" memberName="openButton"
              virtualName="" explicitFocusOrder="0" pos="94 298 78 24" buttonText="Open"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="export file" id="6af643b74bcf3ead" memberName="exportButton"
              virtualName="" explicitFocusOrder="0" pos="10 298 78 24" buttonText="Export"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="reset" id="6bce6e37a7ee85b4" memberName="resetButton" virtualName=""
              explicitFocusOrder="0" pos="262 298 78 24" buttonText="Reset"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="open file" id="cfd93fc0b32b30c3" memberName="advButton"
              virtualName="" explicitFocusOrder="0" pos="178 298 78 24" buttonText="Advanced"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

