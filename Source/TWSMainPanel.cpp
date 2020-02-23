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
#include "TWSAbout.h"
#include "TWSTextAndControls.h"
#include "TWSTuningGrid.h"
#include "Constants.h"
//[/Headers]

#include "TWSMainPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TWSMainPanel::TWSMainPanel (TuningworkbenchsynthAudioProcessor &p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupComponent7.reset (new GroupComponent ("new group",
                                               TRANS("Tuning")));
    addAndMakeVisible (groupComponent7.get());

    groupComponent7->setBounds (8, 224, 704, 400);

    groupComponent3.reset (new GroupComponent ("new group",
                                               TRANS("Filter Envelope")));
    addAndMakeVisible (groupComponent3.get());

    groupComponent3->setBounds (224, 128, 336, 96);

    groupComponent2.reset (new GroupComponent ("new group",
                                               TRANS("Amplitude Envelope")));
    addAndMakeVisible (groupComponent2.get());

    groupComponent2->setBounds (224, 32, 272, 96);

    groupComponent.reset (new GroupComponent ("new group",
                                              TRANS("VCO")));
    addAndMakeVisible (groupComponent.get());

    groupComponent->setBounds (8, 32, 208, 128);

    squareMix.reset (new Slider ("squareMix"));
    addAndMakeVisible (squareMix.get());
    squareMix->setRange (0, 1, 0);
    squareMix->setSliderStyle (Slider::LinearHorizontal);
    squareMix->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    squareMix->setBounds (48, 72, 88, 30);

    tabbedComponent.reset (new TabbedComponent (TabbedButtonBar::TabsAtTop));
    addAndMakeVisible (tabbedComponent.get());
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (TRANS("SCL File"), Colours::lightgrey, new TWSTextAndControls (true, processor), true);
    tabbedComponent->addTab (TRANS("KBM File"), Colours::lightgrey, new TWSTextAndControls (false, processor), true);
    tabbedComponent->setCurrentTabIndex (0);

    tabbedComponent->setBounds (312, 248, 384, 360);

    sineMix.reset (new Slider ("sineMix"));
    addAndMakeVisible (sineMix.get());
    sineMix->setRange (0, 1, 0);
    sineMix->setSliderStyle (Slider::LinearHorizontal);
    sineMix->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    sineMix->setBounds (48, 48, 88, 30);

    sawMix.reset (new Slider ("sawMix"));
    addAndMakeVisible (sawMix.get());
    sawMix->setRange (0, 1, 0);
    sawMix->setSliderStyle (Slider::LinearHorizontal);
    sawMix->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    sawMix->setBounds (48, 96, 88, 30);

    triMix.reset (new Slider ("triMix"));
    addAndMakeVisible (triMix.get());
    triMix->setRange (0, 1, 0);
    triMix->setSliderStyle (Slider::LinearHorizontal);
    triMix->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    triMix->setBounds (48, 120, 88, 30);

    AEG_A.reset (new Slider ("aeg_A"));
    addAndMakeVisible (AEG_A.get());
    AEG_A->setRange (0, 10, 0);
    AEG_A->setSliderStyle (Slider::Rotary);
    AEG_A->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    AEG_A->setBounds (232, 46, 63, 72);

    FEG_A.reset (new Slider ("feg_A"));
    addAndMakeVisible (FEG_A.get());
    FEG_A->setRange (0, 10, 0);
    FEG_A->setSliderStyle (Slider::Rotary);
    FEG_A->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_A->setBounds (232, 142, 63, 72);

    AEG_D.reset (new Slider ("aeg_D"));
    addAndMakeVisible (AEG_D.get());
    AEG_D->setRange (0, 10, 0);
    AEG_D->setSliderStyle (Slider::Rotary);
    AEG_D->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    AEG_D->setBounds (296, 46, 63, 72);

    FEG_D.reset (new Slider ("feg_D"));
    addAndMakeVisible (FEG_D.get());
    FEG_D->setRange (0, 10, 0);
    FEG_D->setSliderStyle (Slider::Rotary);
    FEG_D->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_D->setBounds (296, 142, 63, 72);

    AEG_S.reset (new Slider ("aeg_S"));
    addAndMakeVisible (AEG_S.get());
    AEG_S->setRange (0, 10, 0);
    AEG_S->setSliderStyle (Slider::Rotary);
    AEG_S->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    AEG_S->setBounds (360, 46, 63, 72);

    FEG_S.reset (new Slider ("feg_S"));
    addAndMakeVisible (FEG_S.get());
    FEG_S->setRange (0, 10, 0);
    FEG_S->setSliderStyle (Slider::Rotary);
    FEG_S->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_S->setBounds (360, 142, 63, 72);

    AEG_R.reset (new Slider ("aeg_R"));
    addAndMakeVisible (AEG_R.get());
    AEG_R->setRange (0, 10, 0);
    AEG_R->setSliderStyle (Slider::Rotary);
    AEG_R->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    AEG_R->setBounds (424, 46, 63, 72);

    FEG_R.reset (new Slider ("feg_R"));
    addAndMakeVisible (FEG_R.get());
    FEG_R->setRange (0, 10, 0);
    FEG_R->setSliderStyle (Slider::Rotary);
    FEG_R->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_R->setBounds (424, 142, 63, 72);

    groupComponent4.reset (new GroupComponent ("new group",
                                               TRANS("Filter")));
    addAndMakeVisible (groupComponent4.get());

    groupComponent4->setBounds (504, 32, 208, 96);

    Filt_Cutoff.reset (new Slider ("filt_cutoff"));
    addAndMakeVisible (Filt_Cutoff.get());
    Filt_Cutoff->setRange (0, 10, 0);
    Filt_Cutoff->setSliderStyle (Slider::Rotary);
    Filt_Cutoff->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    Filt_Cutoff->setBounds (577, 45, 63, 72);

    Filt_Q.reset (new Slider ("fllt_Q"));
    addAndMakeVisible (Filt_Q.get());
    Filt_Q->setRange (0, 10, 0);
    Filt_Q->setSliderStyle (Slider::Rotary);
    Filt_Q->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    Filt_Q->setBounds (641, 45, 63, 72);

    LPFToggle.reset (new ToggleButton ("LPF"));
    addAndMakeVisible (LPFToggle.get());
    LPFToggle->setRadioGroupId (1);
    LPFToggle->setToggleState (true, dontSendNotification);

    LPFToggle->setBounds (512, 50, 104, 24);

    HPToggle.reset (new ToggleButton ("HPF"));
    addAndMakeVisible (HPToggle.get());
    HPToggle->setRadioGroupId (1);

    HPToggle->setBounds (512, 71, 104, 24);

    BPFTogle.reset (new ToggleButton ("BPF"));
    addAndMakeVisible (BPFTogle.get());
    BPFTogle->setRadioGroupId (1);

    BPFTogle->setBounds (512, 93, 104, 24);

    groupComponent5.reset (new GroupComponent ("new group",
                                               TRANS("Master")));
    addAndMakeVisible (groupComponent5.get());

    groupComponent5->setBounds (568, 128, 144, 96);

    master_sat.reset (new Slider ("master_sat"));
    addAndMakeVisible (master_sat.get());
    master_sat->setRange (0, 10, 0);
    master_sat->setSliderStyle (Slider::Rotary);
    master_sat->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    master_sat->setBounds (577, 140, 63, 72);

    master_out.reset (new Slider ("master_out"));
    addAndMakeVisible (master_out.get());
    master_out->setRange (0, 10, 0);
    master_out->setSliderStyle (Slider::Rotary);
    master_out->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    master_out->setBounds (641, 140, 63, 72);

    FEG_depth.reset (new Slider ("feg_depth"));
    addAndMakeVisible (FEG_depth.get());
    FEG_depth->setRange (0, 10, 0);
    FEG_depth->setSliderStyle (Slider::Rotary);
    FEG_depth->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_depth->setBounds (487, 142, 63, 72);

    uni_spread.reset (new Slider ("Uni_Spread"));
    addAndMakeVisible (uni_spread.get());
    uni_spread->setRange (0, 10, 0);
    uni_spread->setSliderStyle (Slider::LinearHorizontal);
    uni_spread->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    uni_spread->setBounds (152, 96, 56, 56);

    uni_count.reset (new Slider ("Uni Count"));
    addAndMakeVisible (uni_count.get());
    uni_count->setRange (0, 10, 0);
    uni_count->setSliderStyle (Slider::IncDecButtons);
    uni_count->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    uni_count->setBounds (152, 70, 56, 32);

    groupComponent6.reset (new GroupComponent ("new group",
                                               TRANS("Pitch Bend Range")));
    addAndMakeVisible (groupComponent6.get());

    groupComponent6->setBounds (8, 160, 208, 64);

    pb_down.reset (new Slider ("PB Down"));
    addAndMakeVisible (pb_down.get());
    pb_down->setRange (0, 10, 0);
    pb_down->setSliderStyle (Slider::IncDecButtons);
    pb_down->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    pb_down->setBounds (50, 182, 56, 32);

    pb_up.reset (new Slider ("PB Up"));
    addAndMakeVisible (pb_up.get());
    pb_up->setRange (0, 10, 0);
    pb_up->setSliderStyle (Slider::IncDecButtons);
    pb_up->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    pb_up->setBounds (147, 182, 56, 32);

    version.reset (new Label ("Version Label",
                              TRANS("set-this")));
    addAndMakeVisible (version.get());
    version->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    version->setJustificationType (Justification::centredLeft);
    version->setEditable (false, false, false);
    version->setColour (Label::textColourId, Colour (0xffa6a6a6));
    version->setColour (TextEditor::textColourId, Colours::black);
    version->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    version->setBounds (0, 0, 190, 16);

    tuningGrid.reset (new TWSTuningGrid());
    addAndMakeVisible (tuningGrid.get());
    tuningGrid->setName ("tuningGrid");

    tuningGrid->setBounds (24, 248, 272, 360);

    aboutButton.reset (new TextButton ("aboutButton"));
    addAndMakeVisible (aboutButton.get());
    aboutButton->setButtonText (TRANS("About"));
    aboutButton->addListener (this);

    aboutButton->setBounds (632, 8, 79, 24);


    //[UserPreSize]
    version->setText( TWS_VERSION, dontSendNotification );

    sclTextAndControls = dynamic_cast<TWSTextAndControls*>( tabbedComponent->getTabContentComponent(0) );
    sclTextAndControls->textEditor->setText( processor.currentSCLString );
    
    kbmTextAndControls = dynamic_cast<TWSTextAndControls*>( tabbedComponent->getTabContentComponent(1) );
    kbmTextAndControls->textEditor->setText( processor.currentKBMString );

    sclTextAndControls->applyButton->setEnabled( false ); // bit of a hack
    kbmTextAndControls->applyButton->setEnabled( false ); // bit of a hack

    tuningGrid->tuning = processor.tuning;
    
    processor.addTuningUpdatedListener( sclTextAndControls );
    processor.addTuningUpdatedListener( kbmTextAndControls );
    processor.addTuningUpdatedListener( tuningGrid.get() );
    //[/UserPreSize]

    setSize (720, 630);


    //[Constructor] You can add your own custom stuff here..
    sineMix->setValue( 1.0 );
    //[/Constructor]
}

TWSMainPanel::~TWSMainPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    // Clear our attachments before we destroy our components
    processor.removeTuningUpdatedListener( sclTextAndControls );
    processor.removeTuningUpdatedListener( kbmTextAndControls );
    processor.removeTuningUpdatedListener( tuningGrid.get() );

    sliderAttachments.clear();
    buttonAttachments.clear();
    //[/Destructor_pre]

    groupComponent7 = nullptr;
    groupComponent3 = nullptr;
    groupComponent2 = nullptr;
    groupComponent = nullptr;
    squareMix = nullptr;
    tabbedComponent = nullptr;
    sineMix = nullptr;
    sawMix = nullptr;
    triMix = nullptr;
    AEG_A = nullptr;
    FEG_A = nullptr;
    AEG_D = nullptr;
    FEG_D = nullptr;
    AEG_S = nullptr;
    FEG_S = nullptr;
    AEG_R = nullptr;
    FEG_R = nullptr;
    groupComponent4 = nullptr;
    Filt_Cutoff = nullptr;
    Filt_Q = nullptr;
    LPFToggle = nullptr;
    HPToggle = nullptr;
    BPFTogle = nullptr;
    groupComponent5 = nullptr;
    master_sat = nullptr;
    master_out = nullptr;
    FEG_depth = nullptr;
    uni_spread = nullptr;
    uni_count = nullptr;
    groupComponent6 = nullptr;
    pb_down = nullptr;
    pb_up = nullptr;
    version = nullptr;
    tuningGrid = nullptr;
    aboutButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TWSMainPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 0, y = 0, width = proportionOfWidth (1.0000f), height = 27;
        String text (TRANS("Tuning Workbench"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 227, y = 43, width = 22, height = 21;
        String text (TRANS("A"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 291, y = 43, width = 22, height = 21;
        String text (TRANS("D"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 355, y = 43, width = 22, height = 21;
        String text (TRANS("S"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 419, y = 43, width = 22, height = 21;
        String text (TRANS("R"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 227, y = 139, width = 22, height = 21;
        String text (TRANS("A"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 291, y = 139, width = 22, height = 21;
        String text (TRANS("D"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 355, y = 139, width = 22, height = 21;
        String text (TRANS("S"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 419, y = 139, width = 22, height = 21;
        String text (TRANS("R"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 571, y = 43, width = 22, height = 21;
        String text (TRANS("f"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 635, y = 43, width = 22, height = 21;
        String text (TRANS("q"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 571, y = 139, width = 22, height = 21;
        String text (TRANS("sat"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 635, y = 139, width = 22, height = 21;
        String text (TRANS("out"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 477, y = 139, width = 22, height = 21;
        String text (TRANS("mod"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 21, y = 44, width = 31, height = 30;
        String text (TRANS("Sine"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 21, y = 68, width = 31, height = 30;
        String text (TRANS("Sqr"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 21, y = 92, width = 31, height = 30;
        String text (TRANS("Saw"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 21, y = 116, width = 31, height = 30;
        String text (TRANS("Tri"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 15, y = 180, width = 31, height = 30;
        String text (TRANS("Dn"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 119, y = 180, width = 31, height = 30;
        String text (TRANS("Up"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 151, y = 44, width = 56, height = 30;
        String text (TRANS("Unison"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TWSMainPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TWSMainPanel::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == aboutButton.get())
    {
        //[UserButtonCode_aboutButton] -- add your button handler code here..
        //[/UserButtonCode_aboutButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void TWSMainPanel::filesDropped (const StringArray& filenames, int mouseX, int mouseY)
{
    //[UserCode_filesDropped] -- Add your code here...
    if( filenames.size() != 1 ) return;
    File f( filenames[0] );
    if( f.hasFileExtension( ".scl" ) )
    {
        auto s = f.loadFileAsString();
        processor.setSCL( s );
        tabbedComponent->setCurrentTabIndex( 0, false );
    }
    if( f.hasFileExtension( ".kbm" ) )
    {
        auto s = f.loadFileAsString();
        processor.setKBM( s );
        tabbedComponent->setCurrentTabIndex( 1, false );
    }

    //[/UserCode_filesDropped]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TWSMainPanel::connectValueTreeState(AudioProcessorValueTreeState &t )
{
    auto s = [this, &t](const char* lb, std::unique_ptr<Slider> &sll )
                 {
                     sliderAttachments.push_back(std::make_unique<SliderAttachment>( t, lb, *(sll.get() ) ) );
                 };

    s("sinLevel", sineMix);
    s("squareLevel", squareMix);
    s("sawLevel", sawMix);
    s("triLevel", triMix);

    s("uni_count", uni_count );
    s("uni_spread", uni_spread );

    s( "pb_down", pb_down );
    s( "pb_up", pb_up );

    s( "amp_attack", AEG_A );
    s( "amp_decay", AEG_D );
    s( "amp_sustain", AEG_S );
    s( "amp_release", AEG_R );

    s( "filter_attack", FEG_A );
    s( "filter_decay", FEG_D );
    s( "filter_sustain", FEG_S );
    s( "filter_release", FEG_R );
    s( "filter_depth", FEG_depth );

    s( "filter_cutoff", Filt_Cutoff );
    s( "filter_resonance", Filt_Q );
    s( "master_sat", master_sat );
    s( "master_level", master_out );
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TWSMainPanel" componentName=""
                 parentClasses="public Component, public FileDragAndDropTarget"
                 constructorParams="TuningworkbenchsynthAudioProcessor &amp;p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="720"
                 initialHeight="630">
  <METHODS>
    <METHOD name="filesDropped (const StringArray&amp; filenames, int mouseX, int mouseY)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="0 0 100% 27" fill="solid: ffffffff" hasStroke="0" text="Tuning Workbench"
          fontname="Default font" fontsize="20.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="227 43 22 21" fill="solid: ffffffff" hasStroke="0" text="A"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="291 43 22 21" fill="solid: ffffffff" hasStroke="0" text="D"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="355 43 22 21" fill="solid: ffffffff" hasStroke="0" text="S"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="419 43 22 21" fill="solid: ffffffff" hasStroke="0" text="R"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="227 139 22 21" fill="solid: ffffffff" hasStroke="0" text="A"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="291 139 22 21" fill="solid: ffffffff" hasStroke="0" text="D"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="355 139 22 21" fill="solid: ffffffff" hasStroke="0" text="S"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="419 139 22 21" fill="solid: ffffffff" hasStroke="0" text="R"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="571 43 22 21" fill="solid: ffffffff" hasStroke="0" text="f"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="635 43 22 21" fill="solid: ffffffff" hasStroke="0" text="q"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="571 139 22 21" fill="solid: ffffffff" hasStroke="0" text="sat"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="635 139 22 21" fill="solid: ffffffff" hasStroke="0" text="out"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="477 139 22 21" fill="solid: ffffffff" hasStroke="0" text="mod"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="21 44 31 30" fill="solid: ffffffff" hasStroke="0" text="Sine"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="21 68 31 30" fill="solid: ffffffff" hasStroke="0" text="Sqr"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="21 92 31 30" fill="solid: ffffffff" hasStroke="0" text="Saw"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="21 116 31 30" fill="solid: ffffffff" hasStroke="0" text="Tri"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="15 180 31 30" fill="solid: ffffffff" hasStroke="0" text="Dn"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="119 180 31 30" fill="solid: ffffffff" hasStroke="0" text="Up"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="151 44 56 30" fill="solid: ffffffff" hasStroke="0" text="Unison"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="2fbebfe69a2a9d0" memberName="groupComponent7"
                  virtualName="" explicitFocusOrder="0" pos="8 224 704 400" title="Tuning"/>
  <GROUPCOMPONENT name="new group" id="d1ab89cbe04d6843" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="224 128 336 96" title="Filter Envelope"/>
  <GROUPCOMPONENT name="new group" id="d2339ec442610ced" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="224 32 272 96" title="Amplitude Envelope"/>
  <GROUPCOMPONENT name="new group" id="8e34fd0e54cfbee4" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 32 208 128" title="VCO"/>
  <SLIDER name="squareMix" id="5bec37d607899054" memberName="squareMix"
          virtualName="" explicitFocusOrder="0" pos="48 72 88 30" min="0.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TABBEDCOMPONENT name="new tabbed component" id="db420304d870887d" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="312 248 384 360" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="SCL File" colour="ffd3d3d3" useJucerComp="0" contentClassName="TWSTextAndControls"
         constructorParams="true, processor" jucerComponentFile=""/>
    <TAB name="KBM File" colour="ffd3d3d3" useJucerComp="0" contentClassName="TWSTextAndControls"
         constructorParams="false, processor" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <SLIDER name="sineMix" id="4ae9df7d7efe8aee" memberName="sineMix" virtualName=""
          explicitFocusOrder="0" pos="48 48 88 30" min="0.0" max="1.0"
          int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="sawMix" id="3f21241547992500" memberName="sawMix" virtualName=""
          explicitFocusOrder="0" pos="48 96 88 30" min="0.0" max="1.0"
          int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="triMix" id="d9e3bbe14d877dad" memberName="triMix" virtualName=""
          explicitFocusOrder="0" pos="48 120 88 30" min="0.0" max="1.0"
          int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="aeg_A" id="3f8f972f16f259c9" memberName="AEG_A" virtualName=""
          explicitFocusOrder="0" pos="232 46 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="feg_A" id="307c85464b04b122" memberName="FEG_A" virtualName=""
          explicitFocusOrder="0" pos="232 142 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="aeg_D" id="4b80491e05a59f72" memberName="AEG_D" virtualName=""
          explicitFocusOrder="0" pos="296 46 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="feg_D" id="1ab4422d750007b8" memberName="FEG_D" virtualName=""
          explicitFocusOrder="0" pos="296 142 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="aeg_S" id="5e5c0eeeb9f48337" memberName="AEG_S" virtualName=""
          explicitFocusOrder="0" pos="360 46 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="feg_S" id="d0284dcf8a50fe6a" memberName="FEG_S" virtualName=""
          explicitFocusOrder="0" pos="360 142 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="aeg_R" id="86c4bfb8f4ba8511" memberName="AEG_R" virtualName=""
          explicitFocusOrder="0" pos="424 46 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="feg_R" id="d10d41e8cf59cdfb" memberName="FEG_R" virtualName=""
          explicitFocusOrder="0" pos="424 142 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <GROUPCOMPONENT name="new group" id="5ea4de9077e4e327" memberName="groupComponent4"
                  virtualName="" explicitFocusOrder="0" pos="504 32 208 96" title="Filter"/>
  <SLIDER name="filt_cutoff" id="fb57dc5327ec8482" memberName="Filt_Cutoff"
          virtualName="" explicitFocusOrder="0" pos="577 45 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="fllt_Q" id="9b609f0af7cc9a16" memberName="Filt_Q" virtualName=""
          explicitFocusOrder="0" pos="641 45 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <TOGGLEBUTTON name="LPF" id="a76275562ee11c77" memberName="LPFToggle" virtualName=""
                explicitFocusOrder="0" pos="512 50 104 24" buttonText="LPF" connectedEdges="0"
                needsCallback="0" radioGroupId="1" state="1"/>
  <TOGGLEBUTTON name="HPF" id="a475114ff5ac492c" memberName="HPToggle" virtualName=""
                explicitFocusOrder="0" pos="512 71 104 24" buttonText="HPF" connectedEdges="0"
                needsCallback="0" radioGroupId="1" state="0"/>
  <TOGGLEBUTTON name="BPF" id="87defba6f79e9432" memberName="BPFTogle" virtualName=""
                explicitFocusOrder="0" pos="512 93 104 24" buttonText="BPF" connectedEdges="0"
                needsCallback="0" radioGroupId="1" state="0"/>
  <GROUPCOMPONENT name="new group" id="643f7ea232ea9de9" memberName="groupComponent5"
                  virtualName="" explicitFocusOrder="0" pos="568 128 144 96" title="Master"/>
  <SLIDER name="master_sat" id="71bfa7556a0d4988" memberName="master_sat"
          virtualName="" explicitFocusOrder="0" pos="577 140 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="master_out" id="4050b7c060ab07f8" memberName="master_out"
          virtualName="" explicitFocusOrder="0" pos="641 140 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="feg_depth" id="d36f99a31a63f29e" memberName="FEG_depth"
          virtualName="" explicitFocusOrder="0" pos="487 142 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Uni_Spread" id="b13048de96bc2e15" memberName="uni_spread"
          virtualName="" explicitFocusOrder="0" pos="152 96 56 56" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Uni Count" id="671852c0dcb9a6cd" memberName="uni_count"
          virtualName="" explicitFocusOrder="0" pos="152 70 56 32" min="0.0"
          max="10.0" int="0.0" style="IncDecButtons" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <GROUPCOMPONENT name="new group" id="b05188e3af5159ec" memberName="groupComponent6"
                  virtualName="" explicitFocusOrder="0" pos="8 160 208 64" title="Pitch Bend Range"/>
  <SLIDER name="PB Down" id="cd1af9391f3be38b" memberName="pb_down" virtualName=""
          explicitFocusOrder="0" pos="50 182 56 32" min="0.0" max="10.0"
          int="0.0" style="IncDecButtons" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="PB Up" id="778d93a375abf370" memberName="pb_up" virtualName=""
          explicitFocusOrder="0" pos="147 182 56 32" min="0.0" max="10.0"
          int="0.0" style="IncDecButtons" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <LABEL name="Version Label" id="f03eb6156ac44877" memberName="version"
         virtualName="" explicitFocusOrder="0" pos="0 0 190 16" textCol="ffa6a6a6"
         edTextCol="ff000000" edBkgCol="0" labelText="set-this" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="tuningGrid" id="8857390d3f7a2a0b" memberName="tuningGrid"
                    virtualName="" explicitFocusOrder="0" pos="24 248 272 360" class="TWSTuningGrid"
                    params=""/>
  <TEXTBUTTON name="aboutButton" id="611931d47a95eacb" memberName="aboutButton"
              virtualName="" explicitFocusOrder="0" pos="632 8 79 24" buttonText="About"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

