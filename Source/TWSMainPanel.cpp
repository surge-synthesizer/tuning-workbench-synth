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

    groupComponent8.reset (new GroupComponent ("new group",
                                               TRANS("LFO")));
    addAndMakeVisible (groupComponent8.get());

    groupComponent8->setBounds (224, 224, 400, 96);

    tuningGrid.reset (new TWSTuningGrid());
    addAndMakeVisible (tuningGrid.get());
    tuningGrid->setName ("tuningGrid");

    tuningGrid->setBounds (24, 344, 296, 360);

    groupComponent7.reset (new GroupComponent ("new group",
                                               TRANS("Tuning")));
    addAndMakeVisible (groupComponent7.get());

    groupComponent7->setBounds (8, 320, 768, 400);

    groupComponent3.reset (new GroupComponent ("new group",
                                               TRANS("Filter Envelope")));
    addAndMakeVisible (groupComponent3.get());

    groupComponent3->setBounds (224, 32, 336, 96);

    groupComponent2.reset (new GroupComponent ("new group",
                                               TRANS("Amplitude Envelope")));
    addAndMakeVisible (groupComponent2.get());

    groupComponent2->setBounds (224, 128, 272, 96);

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

    tabbedComponent->setBounds (328, 344, 432, 360);

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

    AEG_A->setBounds (232, 142, 63, 72);

    FEG_A.reset (new Slider ("feg_A"));
    addAndMakeVisible (FEG_A.get());
    FEG_A->setRange (0, 10, 0);
    FEG_A->setSliderStyle (Slider::Rotary);
    FEG_A->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_A->setBounds (232, 46, 63, 72);

    AEG_D.reset (new Slider ("aeg_D"));
    addAndMakeVisible (AEG_D.get());
    AEG_D->setRange (0, 10, 0);
    AEG_D->setSliderStyle (Slider::Rotary);
    AEG_D->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    AEG_D->setBounds (296, 142, 63, 72);

    FEG_D.reset (new Slider ("feg_D"));
    addAndMakeVisible (FEG_D.get());
    FEG_D->setRange (0, 10, 0);
    FEG_D->setSliderStyle (Slider::Rotary);
    FEG_D->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_D->setBounds (296, 46, 63, 72);

    AEG_S.reset (new Slider ("aeg_S"));
    addAndMakeVisible (AEG_S.get());
    AEG_S->setRange (0, 10, 0);
    AEG_S->setSliderStyle (Slider::Rotary);
    AEG_S->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    AEG_S->setBounds (360, 142, 63, 72);

    FEG_S.reset (new Slider ("feg_S"));
    addAndMakeVisible (FEG_S.get());
    FEG_S->setRange (0, 10, 0);
    FEG_S->setSliderStyle (Slider::Rotary);
    FEG_S->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_S->setBounds (360, 46, 63, 72);

    AEG_R.reset (new Slider ("aeg_R"));
    addAndMakeVisible (AEG_R.get());
    AEG_R->setRange (0, 10, 0);
    AEG_R->setSliderStyle (Slider::Rotary);
    AEG_R->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    AEG_R->setBounds (424, 142, 63, 72);

    FEG_R.reset (new Slider ("feg_R"));
    addAndMakeVisible (FEG_R.get());
    FEG_R->setRange (0, 10, 0);
    FEG_R->setSliderStyle (Slider::Rotary);
    FEG_R->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_R->setBounds (424, 46, 63, 72);

    groupComponent4.reset (new GroupComponent ("new group",
                                               TRANS("Filter")));
    addAndMakeVisible (groupComponent4.get());

    groupComponent4->setBounds (568, 32, 208, 96);

    Filt_Cutoff.reset (new Slider ("filt_cutoff"));
    addAndMakeVisible (Filt_Cutoff.get());
    Filt_Cutoff->setRange (0, 10, 0);
    Filt_Cutoff->setSliderStyle (Slider::Rotary);
    Filt_Cutoff->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    Filt_Cutoff->setBounds (641, 45, 63, 72);

    Filt_Q.reset (new Slider ("fllt_Q"));
    addAndMakeVisible (Filt_Q.get());
    Filt_Q->setRange (0, 10, 0);
    Filt_Q->setSliderStyle (Slider::Rotary);
    Filt_Q->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    Filt_Q->setBounds (705, 45, 63, 72);

    LPFToggle.reset (new ToggleButton ("LPF"));
    addAndMakeVisible (LPFToggle.get());
    LPFToggle->setRadioGroupId (1);
    LPFToggle->addListener (this);
    LPFToggle->setToggleState (true, dontSendNotification);

    LPFToggle->setBounds (576, 50, 56, 24);

    HPFToggle.reset (new ToggleButton ("HPF"));
    addAndMakeVisible (HPFToggle.get());
    HPFToggle->setRadioGroupId (1);
    HPFToggle->addListener (this);

    HPFToggle->setBounds (576, 71, 56, 24);

    BPFToggle.reset (new ToggleButton ("BPF"));
    addAndMakeVisible (BPFToggle.get());
    BPFToggle->setRadioGroupId (1);
    BPFToggle->addListener (this);

    BPFToggle->setBounds (576, 93, 56, 24);

    groupComponent5.reset (new GroupComponent ("new group",
                                               TRANS("Master")));
    addAndMakeVisible (groupComponent5.get());

    groupComponent5->setBounds (632, 224, 144, 96);

    master_sat.reset (new Slider ("master_sat"));
    addAndMakeVisible (master_sat.get());
    master_sat->setRange (0, 10, 0);
    master_sat->setSliderStyle (Slider::Rotary);
    master_sat->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    master_sat->setBounds (641, 236, 63, 72);

    master_out.reset (new Slider ("master_out"));
    addAndMakeVisible (master_out.get());
    master_out->setRange (0, 10, 0);
    master_out->setSliderStyle (Slider::Rotary);
    master_out->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    master_out->setBounds (705, 236, 63, 72);

    FEG_depth.reset (new Slider ("feg_depth"));
    addAndMakeVisible (FEG_depth.get());
    FEG_depth->setRange (0, 10, 0);
    FEG_depth->setSliderStyle (Slider::Rotary);
    FEG_depth->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    FEG_depth->setBounds (487, 46, 63, 72);

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

    pb_up.reset (new Slider ("PB UP"));
    addAndMakeVisible (pb_up.get());
    pb_up->setRange (0, 10, 0);
    pb_up->setSliderStyle (Slider::IncDecButtons);
    pb_up->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    pb_up->setBounds (550, 151, 56, 30);

    pb_down.reset (new Slider ("PB Down"));
    addAndMakeVisible (pb_down.get());
    pb_down->setRange (0, 10, 0);
    pb_down->setSliderStyle (Slider::IncDecButtons);
    pb_down->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    pb_down->setBounds (550, 183, 58, 30);

    version.reset (new Label ("Version Label",
                              TRANS("set-this")));
    addAndMakeVisible (version.get());
    version->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    version->setJustificationType (Justification::centredRight);
    version->setEditable (false, false, false);
    version->setColour (Label::textColourId, Colour (0xffa6a6a6));
    version->setColour (TextEditor::textColourId, Colours::black);
    version->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    version->setBounds (490, 9, 190, 16);

    aboutButton.reset (new TextButton ("aboutButton"));
    addAndMakeVisible (aboutButton.get());
    aboutButton->setButtonText (TRANS("About"));
    aboutButton->addListener (this);

    aboutButton->setBounds (688, 3, 79, 24);

    lfo_rate.reset (new Slider ("lfo_rate"));
    addAndMakeVisible (lfo_rate.get());
    lfo_rate->setRange (0, 10, 0);
    lfo_rate->setSliderStyle (Slider::Rotary);
    lfo_rate->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    lfo_rate->setBounds (304, 238, 63, 72);

    lfo_delay.reset (new Slider ("lfo_delay"));
    addAndMakeVisible (lfo_delay.get());
    lfo_delay->setRange (0, 10, 0);
    lfo_delay->setSliderStyle (Slider::Rotary);
    lfo_delay->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    lfo_delay->setBounds (368, 238, 63, 72);

    lfo_attack.reset (new Slider ("lfo_attack"));
    addAndMakeVisible (lfo_attack.get());
    lfo_attack->setRange (0, 10, 0);
    lfo_attack->setSliderStyle (Slider::Rotary);
    lfo_attack->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    lfo_attack->setBounds (432, 238, 63, 72);

    lfotritog.reset (new ToggleButton ("lfotri"));
    addAndMakeVisible (lfotritog.get());
    lfotritog->setButtonText (TRANS("TRI"));
    lfotritog->setRadioGroupId (2);
    lfotritog->addListener (this);
    lfotritog->setToggleState (true, dontSendNotification);

    lfotritog->setBounds (237, 242, 56, 24);

    lfosqrtog.reset (new ToggleButton ("lfosq"));
    addAndMakeVisible (lfosqrtog.get());
    lfosqrtog->setButtonText (TRANS("SQR"));
    lfosqrtog->setRadioGroupId (2);
    lfosqrtog->addListener (this);

    lfosqrtog->setBounds (237, 263, 56, 24);

    lforndtog.reset (new ToggleButton ("lfornd"));
    addAndMakeVisible (lforndtog.get());
    lforndtog->setButtonText (TRANS("RND"));
    lforndtog->setRadioGroupId (2);
    lforndtog->addListener (this);

    lforndtog->setBounds (237, 285, 56, 24);

    lfo_to_pitch.reset (new Slider ("lfo_to_pitch"));
    addAndMakeVisible (lfo_to_pitch.get());
    lfo_to_pitch->setRange (0, 10, 0);
    lfo_to_pitch->setSliderStyle (Slider::Rotary);
    lfo_to_pitch->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    lfo_to_pitch->setBounds (496, 238, 63, 72);

    lfo_to_cutoff.reset (new Slider ("lfo_to_cutoff"));
    addAndMakeVisible (lfo_to_cutoff.get());
    lfo_to_cutoff->setRange (0, 10, 0);
    lfo_to_cutoff->setSliderStyle (Slider::Rotary);
    lfo_to_cutoff->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    lfo_to_cutoff->setBounds (560, 238, 63, 72);

    groupComponent9.reset (new GroupComponent ("new group",
                                               TRANS("Sub")));
    addAndMakeVisible (groupComponent9.get());

    groupComponent9->setBounds (8, 160, 208, 64);

    sublevel.reset (new Slider ("sineMix"));
    addAndMakeVisible (sublevel.get());
    sublevel->setRange (0, 1, 0);
    sublevel->setSliderStyle (Slider::LinearHorizontal);
    sublevel->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    sublevel->setBounds (18, 179, 94, 30);

    sub_oct.reset (new Slider ("Octave"));
    addAndMakeVisible (sub_oct.get());
    sub_oct->setRange (0, 10, 0);
    sub_oct->setSliderStyle (Slider::IncDecButtons);
    sub_oct->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    sub_oct->setBounds (148, 177, 56, 32);

    groupComponent10.reset (new GroupComponent ("new group",
                                                TRANS("Pluck")));
    addAndMakeVisible (groupComponent10.get());

    groupComponent10->setBounds (8, 224, 208, 96);

    groupComponent11.reset (new GroupComponent ("new group",
                                                TRANS("Delay")));
    addAndMakeVisible (groupComponent11.get());

    groupComponent11->setBounds (632, 128, 144, 96);

    comboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox.get());
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addListener (this);

    comboBox->setBounds (8, 3, 168, 24);

    delay_fb.reset (new Slider ("delay_fb"));
    addAndMakeVisible (delay_fb.get());
    delay_fb->setRange (0, 10, 0);
    delay_fb->setSliderStyle (Slider::Rotary);
    delay_fb->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    delay_fb->setBounds (712, 144, 63, 72);

    delay_time.reset (new Slider ("delay_time"));
    addAndMakeVisible (delay_time.get());
    delay_time->setRange (0, 10, 0);
    delay_time->setSliderStyle (Slider::Rotary);
    delay_time->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    delay_time->setBounds (640, 144, 63, 72);

    pluck_atn.reset (new Slider ("squareMix"));
    addAndMakeVisible (pluck_atn.get());
    pluck_atn->setRange (0, 1, 0);
    pluck_atn->setSliderStyle (Slider::LinearHorizontal);
    pluck_atn->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    pluck_atn->setBounds (48, 264, 88, 30);

    pluck_flt.reset (new Slider ("sineMix"));
    addAndMakeVisible (pluck_flt.get());
    pluck_flt->setRange (0, 1, 0);
    pluck_flt->setSliderStyle (Slider::LinearHorizontal);
    pluck_flt->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    pluck_flt->setBounds (48, 240, 88, 30);

    pluck_init.reset (new Slider ("sawMix"));
    addAndMakeVisible (pluck_init.get());
    pluck_init->setRange (0, 1, 0);
    pluck_init->setSliderStyle (Slider::LinearHorizontal);
    pluck_init->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    pluck_init->setBounds (48, 288, 88, 30);

    pluck_lev.reset (new Slider ("lfo_rate"));
    addAndMakeVisible (pluck_lev.get());
    pluck_lev->setRange (0, 10, 0);
    pluck_lev->setSliderStyle (Slider::Rotary);
    pluck_lev->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    pluck_lev->setBounds (144, 240, 63, 72);

    SubPower.reset (new TWSPowerToggle());
    addAndMakeVisible (SubPower.get());
    SubPower->setName ("new component");

    SubPower->setBounds (184, 160, 16, 16);

    PluckPower.reset (new TWSPowerToggle());
    addAndMakeVisible (PluckPower.get());
    PluckPower->setName ("new component");

    PluckPower->setBounds (184, 224, 16, 16);

    DelayPower.reset (new TWSPowerToggle());
    addAndMakeVisible (DelayPower.get());
    DelayPower->setName ("new component");

    DelayPower->setBounds (744, 128, 16, 16);

    VCOPower.reset (new TWSPowerToggle());
    addAndMakeVisible (VCOPower.get());
    VCOPower->setName ("new component");

    VCOPower->setBounds (184, 32, 16, 16);

    wheelLab.reset (new Label ("new label",
                               TRANS("wheel")));
    addAndMakeVisible (wheelLab.get());
    wheelLab->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    wheelLab->setJustificationType (Justification::centred);
    wheelLab->setEditable (false, false, false);
    wheelLab->setColour (Label::backgroundColourId, Colour (0xffab1d1d));
    wheelLab->setColour (TextEditor::textColourId, Colours::black);
    wheelLab->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    wheelLab->setBounds (545, 219, 55, 24);

    ModWheelPower.reset (new TWSPowerToggle());
    addAndMakeVisible (ModWheelPower.get());
    ModWheelPower->setName ("new component");

    ModWheelPower->setBounds (593, 224, 16, 16);

    groupComponent6.reset (new GroupComponent ("new group",
                                               TRANS("Bend")));
    addAndMakeVisible (groupComponent6.get());

    groupComponent6->setBounds (504, 128, 120, 96);

    FilterPower.reset (new TWSPowerToggle());
    addAndMakeVisible (FilterPower.get());
    FilterPower->setName ("new component");

    FilterPower->setBounds (744, 32, 16, 16);


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
    processor.addNotesOnChangedListener( tuningGrid.get() );
    
    wheelLab->setColour (Label::backgroundColourId, getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    VCOPower->setToggleState( true, dontSendNotification );
    VCOPower->addListener(this);
    SubPower->addListener(this);
    PluckPower->addListener(this);
    DelayPower->addListener(this);
    ModWheelPower->addListener(this);
    FilterPower->addListener(this);

    /*
    ** set up the range functions
    */
    auto freqMapTop01 = [](double start, double end, double value ) {
                            std::cout << "TO: " << start << " " << end << " " << value << std::endl;
                            return value;
                        };
    auto freqMapFrom01 = [](double start, double end, double value ) {
                            std::cout << "FR: " << start << " " << end << " " << value << std::endl;
                            return value;
                        };
    NormalisableRange<double> filtfrange( 10, 20000, freqMapFrom01, freqMapTop01 );
    Filt_Cutoff->setNormalisableRange( filtfrange );

    
    //[/UserPreSize]

    setSize (784, 730);


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
    processor.removeNotesOnChangedListener( tuningGrid.get() );
    
    sliderAttachments.clear();
    buttonAttachments.clear();
    lambdaAtttachments.clear();
    //[/Destructor_pre]

    groupComponent8 = nullptr;
    tuningGrid = nullptr;
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
    HPFToggle = nullptr;
    BPFToggle = nullptr;
    groupComponent5 = nullptr;
    master_sat = nullptr;
    master_out = nullptr;
    FEG_depth = nullptr;
    uni_spread = nullptr;
    uni_count = nullptr;
    pb_up = nullptr;
    pb_down = nullptr;
    version = nullptr;
    aboutButton = nullptr;
    lfo_rate = nullptr;
    lfo_delay = nullptr;
    lfo_attack = nullptr;
    lfotritog = nullptr;
    lfosqrtog = nullptr;
    lforndtog = nullptr;
    lfo_to_pitch = nullptr;
    lfo_to_cutoff = nullptr;
    groupComponent9 = nullptr;
    sublevel = nullptr;
    sub_oct = nullptr;
    groupComponent10 = nullptr;
    groupComponent11 = nullptr;
    comboBox = nullptr;
    delay_fb = nullptr;
    delay_time = nullptr;
    pluck_atn = nullptr;
    pluck_flt = nullptr;
    pluck_init = nullptr;
    pluck_lev = nullptr;
    SubPower = nullptr;
    PluckPower = nullptr;
    DelayPower = nullptr;
    VCOPower = nullptr;
    wheelLab = nullptr;
    ModWheelPower = nullptr;
    groupComponent6 = nullptr;
    FilterPower = nullptr;


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
        int x = 0, y = 3, width = proportionOfWidth (1.0000f), height = 27;
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
        int x = 635, y = 43, width = 22, height = 21;
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
        int x = 699, y = 43, width = 22, height = 21;
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
        int x = 635, y = 235, width = 22, height = 21;
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
        int x = 699, y = 235, width = 22, height = 21;
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
        int x = 480, y = 45, width = 22, height = 21;
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
        int x = 516, y = 181, width = 31, height = 30;
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
        int x = 516, y = 149, width = 31, height = 30;
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

    {
        int x = 116, y = 185, width = 22, height = 21;
        String text (TRANS("oct"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 360, y = 237, width = 22, height = 21;
        String text (TRANS("del"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 296, y = 237, width = 22, height = 21;
        String text (TRANS("rate"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 432, y = 237, width = 22, height = 21;
        String text (TRANS("atk"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 496, y = 237, width = 22, height = 21;
        String text (TRANS("ptc"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 552, y = 237, width = 22, height = 21;
        String text (TRANS("flt"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 640, y = 141, width = 22, height = 21;
        String text (TRANS("time"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 712, y = 141, width = 22, height = 21;
        String text (TRANS("fb"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 21, y = 236, width = 31, height = 30;
        String text (TRANS("Flt"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 21, y = 260, width = 31, height = 30;
        String text (TRANS("Attn"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 21, y = 284, width = 31, height = 30;
        String text (TRANS("Init"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 144, y = 237, width = 22, height = 21;
        String text (TRANS("lev"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
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

    if (buttonThatWasClicked == LPFToggle.get())
    {
        //[UserButtonCode_LPFToggle] -- add your button handler code here..
        if( buttonThatWasClicked->getToggleState() )
        {
            auto ft = processor.parameters.getParameter("filter_type");
            ft->beginChangeGesture();
            ft->setValueNotifyingHost( 0.0 );
            ft->endChangeGesture();
        }
        //[/UserButtonCode_LPFToggle]
    }
    else if (buttonThatWasClicked == HPFToggle.get())
    {
        //[UserButtonCode_HPFToggle] -- add your button handler code here..
        if( buttonThatWasClicked->getToggleState() )
        {
            auto ft = processor.parameters.getParameter("filter_type");
            ft->beginChangeGesture();
            ft->setValueNotifyingHost( 0.5 );
            ft->endChangeGesture();
        }
        //[/UserButtonCode_HPFToggle]
    }
    else if (buttonThatWasClicked == BPFToggle.get())
    {
        //[UserButtonCode_BPFToggle] -- add your button handler code here..
        if( buttonThatWasClicked->getToggleState() )
        {
            auto ft = processor.parameters.getParameter("filter_type");
            ft->beginChangeGesture();
            ft->setValueNotifyingHost( 1.0 );
            ft->endChangeGesture();
        }
        //[/UserButtonCode_BPFToggle]
    }
    else if (buttonThatWasClicked == aboutButton.get())
    {
        //[UserButtonCode_aboutButton] -- add your button handler code here..
        auto te = new TWSAbout();

        DialogWindow::LaunchOptions options;
        options.content.setOwned(te);
        options.dialogTitle = "About";
        options.escapeKeyTriggersCloseButton = true;
        options.useNativeTitleBar = false;
        options.resizable = false;

        auto dialogwindow = options.launchAsync();
        //[/UserButtonCode_aboutButton]
    }
    else if (buttonThatWasClicked == lfotritog.get())
    {
        //[UserButtonCode_lfotritog] -- add your button handler code here..
        //[/UserButtonCode_lfotritog]
    }
    else if (buttonThatWasClicked == lfosqrtog.get())
    {
        //[UserButtonCode_lfosqrtog] -- add your button handler code here..
        //[/UserButtonCode_lfosqrtog]
    }
    else if (buttonThatWasClicked == lforndtog.get())
    {
        //[UserButtonCode_lforndtog] -- add your button handler code here..
        //[/UserButtonCode_lforndtog]
    }

    //[UserbuttonClicked_Post]
    auto stv = [this, &buttonThatWasClicked](const char* lb) {
                   auto ft = this->processor.parameters.getParameter(lb);
                   ft->beginChangeGesture();
                   ft->setValueNotifyingHost(buttonThatWasClicked->getToggleState() ? 1 : 0 );
                   ft->endChangeGesture();
               };
    if (buttonThatWasClicked == VCOPower.get() )
    {
        stv( "vco_on" );
    }
    if (buttonThatWasClicked == SubPower.get() )
    {
        stv( "sub_on" );
    }
    if (buttonThatWasClicked == PluckPower.get() )
    {
        stv( "pluck_on" );
    }
    if (buttonThatWasClicked == DelayPower.get() )
    {
        stv( "delay_on" );
    }
    if (buttonThatWasClicked == ModWheelPower.get() )
    {
        stv( "modwheel_on" );
    }
    if (buttonThatWasClicked == FilterPower.get() )
    {
        stv( "filter_on" );
    }

    //[/UserbuttonClicked_Post]
}

void TWSMainPanel::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox.get())
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
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

    auto pb = [this, &t](const char* lb, std::unique_ptr<TWSPowerToggle> &ptg )
                  {
                      // FIXME - don't leak this listener
                      auto l = new TWSLambdaParamListener();
                      l->lfunc = [&ptg](int i, float v)
                                     {
                                         if( v == 0 )
                                             ptg->setToggleState( false, dontSendNotification );
                                         else
                                             ptg->setToggleState( true, dontSendNotification );
                                     };
                      t.getParameter(lb)->addListener(l);
                      l->lfunc(0,t.getParameter(lb)->getValue());
                      lambdaAtttachments.push_back(l);
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

    s( "subosc_level", sublevel );
    s( "subosc_oct", sub_oct );
    s( "pluck_flt", pluck_flt );
    s( "pluck_atn", pluck_atn );
    s( "pluck_init", pluck_init );
    s( "pluck_lev", pluck_lev );

    s( "lfo_rate", lfo_rate );
    s( "lfo_delay", lfo_delay );
    s( "lfo_attack", lfo_attack );
    s( "lfo_pitch", lfo_to_pitch );
    s( "lfo_filter", lfo_to_cutoff );

    s( "delay_fb", delay_fb );
    s( "delay_time", delay_time );

    pb( "vco_on", VCOPower );
    pb( "sub_on", SubPower );
    pb( "pluck_on", PluckPower );
    pb( "delay_on", DelayPower );
    pb( "modwheel_on", ModWheelPower );
    pb( "filter_on", FilterPower );

    /*
    ** Hook up the filter tri-state
    */
    {
        // FIXME - don't leak this listener
        auto l = new TWSLambdaParamListener();
        l->lfunc = [this](int i, float v)
                       {
                           this->LPFToggle->setToggleState( v == 0, dontSendNotification );
                           this->HPFToggle->setToggleState( v == 0.5, dontSendNotification );
                           this->BPFToggle->setToggleState( v == 1, dontSendNotification );
                       };
        t.getParameter("filter_type")->addListener(l);
        l->lfunc(0,t.getParameter("filter_type")->getValue());
        lambdaAtttachments.push_back(l);
    }
}

void TWSPowerToggle::paintButton( Graphics &g, bool hl, bool dn )
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    if( getToggleState() )
    {
        g.setColour( findColour( Slider::thumbColourId ) );
        g.fillEllipse( 2, 3, 12, 12 );
        g.setColour( findColour( Label::textColourId ) );
        g.drawEllipse( 2, 3, 12, 11, 1 );
        g.fillRect( 7, 2, 2, 6 );
    }
    else
    {
        g.setColour( findColour( GroupComponent::outlineColourId ) );
        g.drawEllipse( 2, 3, 12, 12, 1 );
        g.fillRect( 7, 3, 2, 6 );
    }
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
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="784"
                 initialHeight="730">
  <METHODS>
    <METHOD name="filesDropped (const StringArray&amp; filenames, int mouseX, int mouseY)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="0 3 100% 27" fill="solid: ffffffff" hasStroke="0" text="Tuning Workbench"
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
    <TEXT pos="635 43 22 21" fill="solid: ffffffff" hasStroke="0" text="f"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="699 43 22 21" fill="solid: ffffffff" hasStroke="0" text="q"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="635 235 22 21" fill="solid: ffffffff" hasStroke="0" text="sat"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="699 235 22 21" fill="solid: ffffffff" hasStroke="0" text="out"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="480 45 22 21" fill="solid: ffffffff" hasStroke="0" text="mod"
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
    <TEXT pos="516 181 31 30" fill="solid: ffffffff" hasStroke="0" text="Dn"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="516 149 31 30" fill="solid: ffffffff" hasStroke="0" text="Up"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="151 44 56 30" fill="solid: ffffffff" hasStroke="0" text="Unison"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="116 185 22 21" fill="solid: ffffffff" hasStroke="0" text="oct"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="360 237 22 21" fill="solid: ffffffff" hasStroke="0" text="del"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="296 237 22 21" fill="solid: ffffffff" hasStroke="0" text="rate"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="432 237 22 21" fill="solid: ffffffff" hasStroke="0" text="atk"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="496 237 22 21" fill="solid: ffffffff" hasStroke="0" text="ptc"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="552 237 22 21" fill="solid: ffffffff" hasStroke="0" text="flt"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="640 141 22 21" fill="solid: ffffffff" hasStroke="0" text="time"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="712 141 22 21" fill="solid: ffffffff" hasStroke="0" text="fb"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="21 236 31 30" fill="solid: ffffffff" hasStroke="0" text="Flt"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="21 260 31 30" fill="solid: ffffffff" hasStroke="0" text="Attn"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="21 284 31 30" fill="solid: ffffffff" hasStroke="0" text="Init"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="144 237 22 21" fill="solid: ffffffff" hasStroke="0" text="lev"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="fbbdde6af60bfa90" memberName="groupComponent8"
                  virtualName="" explicitFocusOrder="0" pos="224 224 400 96" title="LFO"/>
  <GENERICCOMPONENT name="tuningGrid" id="8857390d3f7a2a0b" memberName="tuningGrid"
                    virtualName="" explicitFocusOrder="0" pos="24 344 296 360" class="TWSTuningGrid"
                    params=""/>
  <GROUPCOMPONENT name="new group" id="2fbebfe69a2a9d0" memberName="groupComponent7"
                  virtualName="" explicitFocusOrder="0" pos="8 320 768 400" title="Tuning"/>
  <GROUPCOMPONENT name="new group" id="d1ab89cbe04d6843" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="224 32 336 96" title="Filter Envelope"/>
  <GROUPCOMPONENT name="new group" id="d2339ec442610ced" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="224 128 272 96" title="Amplitude Envelope"/>
  <GROUPCOMPONENT name="new group" id="8e34fd0e54cfbee4" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 32 208 128" title="VCO"/>
  <SLIDER name="squareMix" id="5bec37d607899054" memberName="squareMix"
          virtualName="" explicitFocusOrder="0" pos="48 72 88 30" min="0.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TABBEDCOMPONENT name="new tabbed component" id="db420304d870887d" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="328 344 432 360" orientation="top"
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
          explicitFocusOrder="0" pos="232 142 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="feg_A" id="307c85464b04b122" memberName="FEG_A" virtualName=""
          explicitFocusOrder="0" pos="232 46 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="aeg_D" id="4b80491e05a59f72" memberName="AEG_D" virtualName=""
          explicitFocusOrder="0" pos="296 142 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="feg_D" id="1ab4422d750007b8" memberName="FEG_D" virtualName=""
          explicitFocusOrder="0" pos="296 46 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="aeg_S" id="5e5c0eeeb9f48337" memberName="AEG_S" virtualName=""
          explicitFocusOrder="0" pos="360 142 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="feg_S" id="d0284dcf8a50fe6a" memberName="FEG_S" virtualName=""
          explicitFocusOrder="0" pos="360 46 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="aeg_R" id="86c4bfb8f4ba8511" memberName="AEG_R" virtualName=""
          explicitFocusOrder="0" pos="424 142 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="feg_R" id="d10d41e8cf59cdfb" memberName="FEG_R" virtualName=""
          explicitFocusOrder="0" pos="424 46 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <GROUPCOMPONENT name="new group" id="5ea4de9077e4e327" memberName="groupComponent4"
                  virtualName="" explicitFocusOrder="0" pos="568 32 208 96" title="Filter"/>
  <SLIDER name="filt_cutoff" id="fb57dc5327ec8482" memberName="Filt_Cutoff"
          virtualName="" explicitFocusOrder="0" pos="641 45 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="fllt_Q" id="9b609f0af7cc9a16" memberName="Filt_Q" virtualName=""
          explicitFocusOrder="0" pos="705 45 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <TOGGLEBUTTON name="LPF" id="a76275562ee11c77" memberName="LPFToggle" virtualName=""
                explicitFocusOrder="0" pos="576 50 56 24" buttonText="LPF" connectedEdges="0"
                needsCallback="1" radioGroupId="1" state="1"/>
  <TOGGLEBUTTON name="HPF" id="a475114ff5ac492c" memberName="HPFToggle" virtualName=""
                explicitFocusOrder="0" pos="576 71 56 24" buttonText="HPF" connectedEdges="0"
                needsCallback="1" radioGroupId="1" state="0"/>
  <TOGGLEBUTTON name="BPF" id="87defba6f79e9432" memberName="BPFToggle" virtualName=""
                explicitFocusOrder="0" pos="576 93 56 24" buttonText="BPF" connectedEdges="0"
                needsCallback="1" radioGroupId="1" state="0"/>
  <GROUPCOMPONENT name="new group" id="643f7ea232ea9de9" memberName="groupComponent5"
                  virtualName="" explicitFocusOrder="0" pos="632 224 144 96" title="Master"/>
  <SLIDER name="master_sat" id="71bfa7556a0d4988" memberName="master_sat"
          virtualName="" explicitFocusOrder="0" pos="641 236 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="master_out" id="4050b7c060ab07f8" memberName="master_out"
          virtualName="" explicitFocusOrder="0" pos="705 236 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="feg_depth" id="d36f99a31a63f29e" memberName="FEG_depth"
          virtualName="" explicitFocusOrder="0" pos="487 46 63 72" min="0.0"
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
  <SLIDER name="PB UP" id="cd1af9391f3be38b" memberName="pb_up" virtualName=""
          explicitFocusOrder="0" pos="550 151 56 30" min="0.0" max="10.0"
          int="0.0" style="IncDecButtons" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="PB Down" id="778d93a375abf370" memberName="pb_down" virtualName=""
          explicitFocusOrder="0" pos="550 183 58 30" min="0.0" max="10.0"
          int="0.0" style="IncDecButtons" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <LABEL name="Version Label" id="f03eb6156ac44877" memberName="version"
         virtualName="" explicitFocusOrder="0" pos="490 9 190 16" textCol="ffa6a6a6"
         edTextCol="ff000000" edBkgCol="0" labelText="set-this" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTBUTTON name="aboutButton" id="611931d47a95eacb" memberName="aboutButton"
              virtualName="" explicitFocusOrder="0" pos="688 3 79 24" buttonText="About"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="lfo_rate" id="6a9193d7258c1681" memberName="lfo_rate" virtualName=""
          explicitFocusOrder="0" pos="304 238 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="lfo_delay" id="bd0a101d21e402b5" memberName="lfo_delay"
          virtualName="" explicitFocusOrder="0" pos="368 238 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="lfo_attack" id="2fb75b347cd330db" memberName="lfo_attack"
          virtualName="" explicitFocusOrder="0" pos="432 238 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <TOGGLEBUTTON name="lfotri" id="4854b4183a8e0826" memberName="lfotritog" virtualName=""
                explicitFocusOrder="0" pos="237 242 56 24" buttonText="TRI" connectedEdges="0"
                needsCallback="1" radioGroupId="2" state="1"/>
  <TOGGLEBUTTON name="lfosq" id="9096bc04f359db3a" memberName="lfosqrtog" virtualName=""
                explicitFocusOrder="0" pos="237 263 56 24" buttonText="SQR" connectedEdges="0"
                needsCallback="1" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="lfornd" id="3007921d4cb0e134" memberName="lforndtog" virtualName=""
                explicitFocusOrder="0" pos="237 285 56 24" buttonText="RND" connectedEdges="0"
                needsCallback="1" radioGroupId="2" state="0"/>
  <SLIDER name="lfo_to_pitch" id="6102623ee8a927fd" memberName="lfo_to_pitch"
          virtualName="" explicitFocusOrder="0" pos="496 238 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="lfo_to_cutoff" id="74ecf6b446a99ae5" memberName="lfo_to_cutoff"
          virtualName="" explicitFocusOrder="0" pos="560 238 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <GROUPCOMPONENT name="new group" id="1a6ff50d70c6708f" memberName="groupComponent9"
                  virtualName="" explicitFocusOrder="0" pos="8 160 208 64" title="Sub"/>
  <SLIDER name="sineMix" id="7c74ce40dda4a6af" memberName="sublevel" virtualName=""
          explicitFocusOrder="0" pos="18 179 94 30" min="0.0" max="1.0"
          int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="Octave" id="c496b5d553a407cc" memberName="sub_oct" virtualName=""
          explicitFocusOrder="0" pos="148 177 56 32" min="0.0" max="10.0"
          int="0.0" style="IncDecButtons" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <GROUPCOMPONENT name="new group" id="54484da892d90c71" memberName="groupComponent10"
                  virtualName="" explicitFocusOrder="0" pos="8 224 208 96" title="Pluck"/>
  <GROUPCOMPONENT name="new group" id="8ef713d8bfa0a07b" memberName="groupComponent11"
                  virtualName="" explicitFocusOrder="0" pos="632 128 144 96" title="Delay"/>
  <COMBOBOX name="new combo box" id="970d30d04b5c167c" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="8 3 168 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="delay_fb" id="e034138b2cf38cda" memberName="delay_fb" virtualName=""
          explicitFocusOrder="0" pos="712 144 63 72" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="15" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="delay_time" id="83f72f5048c8af2d" memberName="delay_time"
          virtualName="" explicitFocusOrder="0" pos="640 144 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="squareMix" id="ecc8a0f8fce934e8" memberName="pluck_atn"
          virtualName="" explicitFocusOrder="0" pos="48 264 88 30" min="0.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="sineMix" id="9085283745af7088" memberName="pluck_flt" virtualName=""
          explicitFocusOrder="0" pos="48 240 88 30" min="0.0" max="1.0"
          int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="sawMix" id="db5365e77efe03e8" memberName="pluck_init" virtualName=""
          explicitFocusOrder="0" pos="48 288 88 30" min="0.0" max="1.0"
          int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="lfo_rate" id="e8ae948f8e79bbb2" memberName="pluck_lev"
          virtualName="" explicitFocusOrder="0" pos="144 240 63 72" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <GENERICCOMPONENT name="new component" id="ac8ce2870242f1fe" memberName="SubPower"
                    virtualName="" explicitFocusOrder="0" pos="184 160 16 16" class="TWSPowerToggle"
                    params=""/>
  <GENERICCOMPONENT name="new component" id="55e0f7d8357b759a" memberName="PluckPower"
                    virtualName="" explicitFocusOrder="0" pos="184 224 16 16" class="TWSPowerToggle"
                    params=""/>
  <GENERICCOMPONENT name="new component" id="1d9d3b36c701b236" memberName="DelayPower"
                    virtualName="" explicitFocusOrder="0" pos="744 128 16 16" class="TWSPowerToggle"
                    params=""/>
  <GENERICCOMPONENT name="new component" id="392fcad2efd873fc" memberName="VCOPower"
                    virtualName="" explicitFocusOrder="0" pos="184 32 16 16" class="TWSPowerToggle"
                    params=""/>
  <LABEL name="new label" id="5599c301ca781b78" memberName="wheelLab"
         virtualName="" explicitFocusOrder="0" pos="545 219 55 24" bkgCol="ffab1d1d"
         edTextCol="ff000000" edBkgCol="0" labelText="wheel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <GENERICCOMPONENT name="new component" id="15fed711e2489031" memberName="ModWheelPower"
                    virtualName="" explicitFocusOrder="0" pos="593 224 16 16" class="TWSPowerToggle"
                    params=""/>
  <GROUPCOMPONENT name="new group" id="b05188e3af5159ec" memberName="groupComponent6"
                  virtualName="" explicitFocusOrder="0" pos="504 128 120 96" title="Bend"/>
  <GENERICCOMPONENT name="new component" id="f6b98ff890ab9c00" memberName="FilterPower"
                    virtualName="" explicitFocusOrder="0" pos="744 32 16 16" class="TWSPowerToggle"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

