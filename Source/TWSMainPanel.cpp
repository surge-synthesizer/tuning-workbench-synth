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

    version3.reset (new Label ("Version Label",
                               TRANS("https://surge-synth-team.org/")));
    addAndMakeVisible (version3.get());
    version3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    version3->setJustificationType (Justification::centred);
    version3->setEditable (false, false, false);
    version3->setColour (Label::textColourId, Colours::white);
    version3->setColour (TextEditor::textColourId, Colours::black);
    version3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    version3->setBounds (0, 721, 784, 16);

    groupComponent7.reset (new GroupComponent ("new group",
                                               TRANS("Tuning")));
    addAndMakeVisible (groupComponent7.get());

    groupComponent7->setBounds (8, 320, 768, 400);

    groupComponent8.reset (new GroupComponent ("new group",
                                               TRANS("LFO")));
    addAndMakeVisible (groupComponent8.get());

    groupComponent8->setBounds (224, 224, 400, 96);

    tuningGrid.reset (new TWSTuningGrid());
    addAndMakeVisible (tuningGrid.get());
    tuningGrid->setName ("tuningGrid");

    tuningGrid->setBounds (24, 344, 296, 360);

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

    uni_spread->setBounds (152, 112, 56, 40);

    uni_count.reset (new Slider ("Uni Count"));
    addAndMakeVisible (uni_count.get());
    uni_count->setRange (0, 10, 0);
    uni_count->setSliderStyle (Slider::IncDecButtons);
    uni_count->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 15);

    uni_count->setBounds (152, 64, 56, 32);

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

    version->setBounds (592, 721, 190, 16);

    aboutButton.reset (new TextButton ("aboutButton"));
    addAndMakeVisible (aboutButton.get());
    aboutButton->setButtonText (TRANS("About"));
    aboutButton->addListener (this);

    aboutButton->setBounds (716, 3, 55, 24);

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

    delay_fb.reset (new Slider ("new slider"));
    addAndMakeVisible (delay_fb.get());
    delay_fb->setRange (0, 10, 0);
    delay_fb->setSliderStyle (Slider::LinearVertical);
    delay_fb->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    delay_fb->addListener (this);

    delay_fb->setBounds (702, 151, 24, 68);

    delay_wet.reset (new Slider ("new slider"));
    addAndMakeVisible (delay_wet.get());
    delay_wet->setRange (0, 10, 0);
    delay_wet->setSliderStyle (Slider::LinearVertical);
    delay_wet->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    delay_wet->addListener (this);

    delay_wet->setBounds (748, 151, 24, 68);

    delay_dry.reset (new Slider ("new slider"));
    addAndMakeVisible (delay_dry.get());
    delay_dry->setRange (0, 10, 0);
    delay_dry->setSliderStyle (Slider::LinearVertical);
    delay_dry->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    delay_dry->addListener (this);

    delay_dry->setBounds (725, 151, 24, 68);

    lfo_pitch.reset (new Slider ("new slider"));
    addAndMakeVisible (lfo_pitch.get());
    lfo_pitch->setRange (0, 10, 0);
    lfo_pitch->setSliderStyle (Slider::LinearVertical);
    lfo_pitch->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lfo_pitch->addListener (this);

    lfo_pitch->setBounds (496, 247, 24, 68);

    lfo_sublev.reset (new Slider ("new slider"));
    addAndMakeVisible (lfo_sublev.get());
    lfo_sublev->setRange (0, 10, 0);
    lfo_sublev->setSliderStyle (Slider::LinearVertical);
    lfo_sublev->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lfo_sublev->addListener (this);

    lfo_sublev->setBounds (544, 247, 24, 68);

    lfo_vcolev.reset (new Slider ("new slider"));
    addAndMakeVisible (lfo_vcolev.get());
    lfo_vcolev->setRange (0, 10, 0);
    lfo_vcolev->setSliderStyle (Slider::LinearVertical);
    lfo_vcolev->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lfo_vcolev->addListener (this);

    lfo_vcolev->setBounds (520, 247, 24, 68);

    lfo_plucklev.reset (new Slider ("new slider"));
    addAndMakeVisible (lfo_plucklev.get());
    lfo_plucklev->setRange (0, 10, 0);
    lfo_plucklev->setSliderStyle (Slider::LinearVertical);
    lfo_plucklev->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lfo_plucklev->addListener (this);

    lfo_plucklev->setBounds (568, 247, 24, 68);

    lfo_filter.reset (new Slider ("new slider"));
    addAndMakeVisible (lfo_filter.get());
    lfo_filter->setRange (0, 10, 0);
    lfo_filter->setSliderStyle (Slider::LinearVertical);
    lfo_filter->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lfo_filter->addListener (this);

    lfo_filter->setBounds (592, 247, 24, 68);

    version2.reset (new Label ("Version Label",
                               TRANS("Released under GNU General Public License v3\n")));
    addAndMakeVisible (version2.get());
    version2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    version2->setJustificationType (Justification::centredLeft);
    version2->setEditable (false, false, false);
    version2->setColour (Label::textColourId, Colour (0xffa6a6a6));
    version2->setColour (TextEditor::textColourId, Colours::black);
    version2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    version2->setBounds (0, 721, 312, 16);

    helpButton.reset (new TextButton ("helpButton"));
    addAndMakeVisible (helpButton.get());
    helpButton->setButtonText (TRANS("Help"));
    helpButton->addListener (this);

    helpButton->setBounds (655, 3, 55, 24);

    presetButton.reset (new TextButton ("helpButton"));
    addAndMakeVisible (presetButton.get());
    presetButton->setButtonText (TRANS("Presets"));
    presetButton->addListener (this);

    presetButton->setBounds (8, 3, 55, 24);


    //[UserPreSize]
    version->setText( TWS_VERSION, dontSendNotification );

    sclTextAndControls = dynamic_cast<TWSTextAndControls*>( tabbedComponent->getTabContentComponent(0) );
    sclTextAndControls->textEditor->setText( processor.currentSCLString );

    kbmTextAndControls = dynamic_cast<TWSTextAndControls*>( tabbedComponent->getTabContentComponent(1) );
    kbmTextAndControls->textEditor->setText( processor.currentKBMString );

    sclTextAndControls->applyButton->setEnabled( false ); // bit of a hack
    kbmTextAndControls->applyButton->setEnabled( false ); // bit of a hack

    tuningGrid->mod->tuningUpdated( processor.tuning );

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

    presetMenu = std::make_unique<PopupMenu>();
    //[/UserPreSize]

    setSize (784, 742);


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
    for( auto &p: lambdaAtttachments )
    {
        processor.parameters.getParameter(p.first.c_str())->removeListener(p.second);
        delete p.second;
    }
    lambdaAtttachments.clear();
    //[/Destructor_pre]

    version3 = nullptr;
    groupComponent7 = nullptr;
    groupComponent8 = nullptr;
    tuningGrid = nullptr;
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
    groupComponent9 = nullptr;
    sublevel = nullptr;
    sub_oct = nullptr;
    groupComponent10 = nullptr;
    groupComponent11 = nullptr;
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
    delay_fb = nullptr;
    delay_wet = nullptr;
    delay_dry = nullptr;
    lfo_pitch = nullptr;
    lfo_sublev = nullptr;
    lfo_vcolev = nullptr;
    lfo_plucklev = nullptr;
    lfo_filter = nullptr;
    version2 = nullptr;
    helpButton = nullptr;
    presetButton = nullptr;


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
        int x = 520, y = 237, width = 22, height = 21;
        String text (TRANS("vco"));
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
        int x = 704, y = 141, width = 22, height = 21;
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

    {
        int x = 726, y = 141, width = 22, height = 21;
        String text (TRANS("dry"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 750, y = 141, width = 22, height = 21;
        String text (TRANS("wet"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 152, y = 40, width = 56, height = 30;
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
        int x = 152, y = 93, width = 56, height = 30;
        String text (TRANS("Spread"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 544, y = 237, width = 22, height = 21;
        String text (TRANS("sub"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 568, y = 237, width = 22, height = 21;
        String text (TRANS("plk"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 592, y = 237, width = 22, height = 21;
        String text (TRANS("f"));
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

        options.launchAsync();
        //[/UserButtonCode_aboutButton]
    }
    else if (buttonThatWasClicked == lfotritog.get())
    {
        //[UserButtonCode_lfotritog] -- add your button handler code here..
        if( buttonThatWasClicked->getToggleState() )
        {
            auto ft = processor.parameters.getParameter("lfo_type");
            ft->beginChangeGesture();
            ft->setValueNotifyingHost( 0.0 );
            ft->endChangeGesture();
        }

        //[/UserButtonCode_lfotritog]
    }
    else if (buttonThatWasClicked == lfosqrtog.get())
    {
        //[UserButtonCode_lfosqrtog] -- add your button handler code here..
        if( buttonThatWasClicked->getToggleState() )
        {
            auto ft = processor.parameters.getParameter("lfo_type");
            ft->beginChangeGesture();
            ft->setValueNotifyingHost( 0.5 );
            ft->endChangeGesture();
        }
        //[/UserButtonCode_lfosqrtog]
    }
    else if (buttonThatWasClicked == lforndtog.get())
    {
        //[UserButtonCode_lforndtog] -- add your button handler code here..
        if( buttonThatWasClicked->getToggleState() )
        {
            auto ft = processor.parameters.getParameter("lfo_type");
            ft->beginChangeGesture();
            ft->setValueNotifyingHost( 1.0 );
            ft->endChangeGesture();
        }
        //[/UserButtonCode_lforndtog]
    }
    else if (buttonThatWasClicked == helpButton.get())
    {
        //[UserButtonCode_helpButton] -- add your button handler code here..
        //[/UserButtonCode_helpButton]
    }
    else if (buttonThatWasClicked == presetButton.get())
    {
        //[UserButtonCode_presetButton] -- add your button handler code here..
        doPresetMenu();
        //[/UserButtonCode_presetButton]
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

void TWSMainPanel::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == delay_fb.get())
    {
        //[UserSliderCode_delay_fb] -- add your slider handling code here..
        //[/UserSliderCode_delay_fb]
    }
    else if (sliderThatWasMoved == delay_wet.get())
    {
        //[UserSliderCode_delay_wet] -- add your slider handling code here..
        //[/UserSliderCode_delay_wet]
    }
    else if (sliderThatWasMoved == delay_dry.get())
    {
        //[UserSliderCode_delay_dry] -- add your slider handling code here..
        //[/UserSliderCode_delay_dry]
    }
    else if (sliderThatWasMoved == lfo_pitch.get())
    {
        //[UserSliderCode_lfo_pitch] -- add your slider handling code here..
        //[/UserSliderCode_lfo_pitch]
    }
    else if (sliderThatWasMoved == lfo_sublev.get())
    {
        //[UserSliderCode_lfo_sublev] -- add your slider handling code here..
        //[/UserSliderCode_lfo_sublev]
    }
    else if (sliderThatWasMoved == lfo_vcolev.get())
    {
        //[UserSliderCode_lfo_vcolev] -- add your slider handling code here..
        //[/UserSliderCode_lfo_vcolev]
    }
    else if (sliderThatWasMoved == lfo_plucklev.get())
    {
        //[UserSliderCode_lfo_plucklev] -- add your slider handling code here..
        //[/UserSliderCode_lfo_plucklev]
    }
    else if (sliderThatWasMoved == lfo_filter.get())
    {
        //[UserSliderCode_lfo_filter] -- add your slider handling code here..
        //[/UserSliderCode_lfo_filter]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
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
    if( f.hasFileExtension( ".twsxml" ) )
    {
        auto s = f.loadFileAsString();
        MemoryBlock b;
        f.loadFileAsData( b );
        processor.setStateInformation( b.getData(), (int)b.getSize() );
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

    auto pb = [this, &t](const char *lb, Button *tb )
                  {
                      buttonAttachments.push_back(std::make_unique<ButtonAttachment>( t, lb, *( tb ) ) );
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
    s( "lfo_pitch", lfo_pitch );
    s( "lfo_filter", lfo_filter );
    s( "lfo_plucklev", lfo_plucklev );
    s( "lfo_sublev", lfo_sublev );
    s( "lfo_vcolev", lfo_vcolev );

    s( "delay_fb", delay_fb );
    s( "delay_wet", delay_wet );
    s( "delay_dry", delay_dry );
    s( "delay_time", delay_time );

    pb( "vco_on", VCOPower.get() );
    pb( "sub_on", SubPower.get() );
    pb( "pluck_on", PluckPower.get() );
    pb( "delay_on", DelayPower.get() );
    pb( "modwheel_on", ModWheelPower.get() );
    pb( "filter_on", FilterPower.get() );
    
    /*
    ** Hook up the filter tri-state and LFO tri-state
    */
    {
        auto l = new TWSLambdaParamListener();
        l->lfunc = [this](int i, float v)
                       {
                           this->LPFToggle->setToggleState( v == 0, dontSendNotification );
                           this->HPFToggle->setToggleState( v == 0.5, dontSendNotification );
                           this->BPFToggle->setToggleState( v == 1, dontSendNotification );
                       };
        t.getParameter("filter_type")->addListener(l);
        l->lfunc(0,t.getParameter("filter_type")->getValue());
        lambdaAtttachments.push_back(std::make_pair(std::string("filter_type"), l));
    }
    {
        auto l = new TWSLambdaParamListener();
        l->lfunc = [this](int i, float v)
                       {
                           this->lfotritog->setToggleState( v == 0, dontSendNotification );
                           this->lfosqrtog->setToggleState( v == 0.5, dontSendNotification );
                           this->lforndtog->setToggleState( v == 1, dontSendNotification );
                       };
        t.getParameter("lfo_type")->addListener(l);
        l->lfunc(0,t.getParameter("lfo_type")->getValue());
        lambdaAtttachments.push_back(std::make_pair(std::string("lfo_type"), l));
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

void TWSMainPanel::doPresetMenu()
{
    presetMenu->clear();
    for( int i=0; i<processor.factoryPresets.size(); ++i )
    {
        auto t = processor.factoryPresets[i];
        auto n = std::get<0>(t);
        auto b = std::get<1>(t);
        auto s = std::get<2>(t);
        if( b == 0 || s == 0 )
            presetMenu->addSectionHeader( n );
        else
            presetMenu->addItem( i, n );
    }
    presetMenu->addSeparator();

    presetMenu->addItem( 10000, "Save Preset As..." );
    presetMenu->addItem( 10001, "Load Preset From..." );

    auto ri = presetButton->getScreenBounds();
    // ri.setY( ri.getY() + presetButton->getHeight() );

    auto res = presetMenu->showAt( ri );
    switch( res )
    {
    case 10000:
    {
        FileChooser fc( "Save Preset As..", File(), "*.twsxml" );
        if( fc.browseForFileToSave(true) )
        {
            auto f = fc.getResult();
            MemoryBlock b;
            processor.getStateInformation(b);
            if( ! f.replaceWithData( b.getData(),b.getSize() ) )
            {
                AlertWindow::showMessageBoxAsync( AlertWindow::AlertIconType::WarningIcon,
                                                  "Error saving preset",
                                                  "An unknown error occured streaming data to file",
                                                  "OK" );
            }
        }
        break;
    }
    case 10001:
    {
        FileChooser fc( "Load Preset From...", File(), "*.twsxml" );
        if( fc.browseForFileToOpen() )
        {
            auto f = fc.getResult();
            MemoryBlock b;
            f.loadFileAsData( b );
            processor.setStateInformation( b.getData(), (int)b.getSize() );
        }
        break;
    }
    default:
    {
        auto t = processor.factoryPresets[res];
        auto b = std::get<1>(t);
        auto s = std::get<2>(t);
        processor.setStateInformation( b, (int)s );

        break;
    }
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
                 initialHeight="742">
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
    <TEXT pos="520 237 22 21" fill="solid: ffffffff" hasStroke="0" text="vco"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="640 141 22 21" fill="solid: ffffffff" hasStroke="0" text="time"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="704 141 22 21" fill="solid: ffffffff" hasStroke="0" text="fb"
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
    <TEXT pos="726 141 22 21" fill="solid: ffffffff" hasStroke="0" text="dry"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="750 141 22 21" fill="solid: ffffffff" hasStroke="0" text="wet"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="152 40 56 30" fill="solid: ffffffff" hasStroke="0" text="Unison"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="152 93 56 30" fill="solid: ffffffff" hasStroke="0" text="Spread"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="544 237 22 21" fill="solid: ffffffff" hasStroke="0" text="sub"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="568 237 22 21" fill="solid: ffffffff" hasStroke="0" text="plk"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="592 237 22 21" fill="solid: ffffffff" hasStroke="0" text="f"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <LABEL name="Version Label" id="d55a14560dfb93a" memberName="version3"
         virtualName="" explicitFocusOrder="0" pos="0 721 784 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="https://surge-synth-team.org/"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <GROUPCOMPONENT name="new group" id="2fbebfe69a2a9d0" memberName="groupComponent7"
                  virtualName="" explicitFocusOrder="0" pos="8 320 768 400" title="Tuning"/>
  <GROUPCOMPONENT name="new group" id="fbbdde6af60bfa90" memberName="groupComponent8"
                  virtualName="" explicitFocusOrder="0" pos="224 224 400 96" title="LFO"/>
  <GENERICCOMPONENT name="tuningGrid" id="8857390d3f7a2a0b" memberName="tuningGrid"
                    virtualName="" explicitFocusOrder="0" pos="24 344 296 360" class="TWSTuningGrid"
                    params=""/>
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
          virtualName="" explicitFocusOrder="0" pos="152 112 56 40" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="15" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Uni Count" id="671852c0dcb9a6cd" memberName="uni_count"
          virtualName="" explicitFocusOrder="0" pos="152 64 56 32" min="0.0"
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
         virtualName="" explicitFocusOrder="0" pos="592 721 190 16" textCol="ffa6a6a6"
         edTextCol="ff000000" edBkgCol="0" labelText="set-this" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTBUTTON name="aboutButton" id="611931d47a95eacb" memberName="aboutButton"
              virtualName="" explicitFocusOrder="0" pos="716 3 55 24" buttonText="About"
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
  <SLIDER name="new slider" id="cbc517d7e682513a" memberName="delay_fb"
          virtualName="" explicitFocusOrder="0" pos="702 151 24 68" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="ab65fae43903f271" memberName="delay_wet"
          virtualName="" explicitFocusOrder="0" pos="748 151 24 68" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="fc3191b5e3aed740" memberName="delay_dry"
          virtualName="" explicitFocusOrder="0" pos="725 151 24 68" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="1d4d6ebea78d727e" memberName="lfo_pitch"
          virtualName="" explicitFocusOrder="0" pos="496 247 24 68" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="6290d41d04902ca5" memberName="lfo_sublev"
          virtualName="" explicitFocusOrder="0" pos="544 247 24 68" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="5d73f53dcb4e4e98" memberName="lfo_vcolev"
          virtualName="" explicitFocusOrder="0" pos="520 247 24 68" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="b31e5f053f4b7be1" memberName="lfo_plucklev"
          virtualName="" explicitFocusOrder="0" pos="568 247 24 68" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="d0b2ae558adcaa68" memberName="lfo_filter"
          virtualName="" explicitFocusOrder="0" pos="592 247 24 68" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Version Label" id="d05faf01cb855cdf" memberName="version2"
         virtualName="" explicitFocusOrder="0" pos="0 721 312 16" textCol="ffa6a6a6"
         edTextCol="ff000000" edBkgCol="0" labelText="Released under GNU General Public License v3&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTBUTTON name="helpButton" id="29f7b15e1ff1f153" memberName="helpButton"
              virtualName="" explicitFocusOrder="0" pos="655 3 55 24" buttonText="Help"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="helpButton" id="33185602b7f821b6" memberName="presetButton"
              virtualName="" explicitFocusOrder="0" pos="8 3 55 24" buttonText="Presets"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

