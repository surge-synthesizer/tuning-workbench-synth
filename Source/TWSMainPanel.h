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

class TWSTextAndControls;
class TWSTuningGrid;

class TWSPowerToggle : public virtual ToggleButton {
public:
    TWSPowerToggle() : ToggleButton() { };
    virtual void paintButton( Graphics &g, bool hl, bool dn );
};

struct TWSLambdaParamListener : public virtual AudioProcessorParameter::Listener
{
    virtual void parameterGestureChanged( int, bool ) { }
    virtual void parameterValueChanged( int idx, float nv ) {
        lfunc(idx, nv);
    }
    std::function<void(int,float)> lfunc = [](int,float){};
};
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TWSMainPanel  : public Component,
                      public FileDragAndDropTarget,
                      public Button::Listener,
                      public Slider::Listener
{
public:
    //==============================================================================
    TWSMainPanel (TuningworkbenchsynthAudioProcessor &p);
    ~TWSMainPanel() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void connectValueTreeState( AudioProcessorValueTreeState &p );
    virtual bool isInterestedInFileDrag (const StringArray& files) override {
        return true; // FIXME
    }
    virtual void doPresetMenu();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void filesDropped (const StringArray& filenames, int mouseX, int mouseY) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TuningworkbenchsynthAudioProcessor &processor;
    TWSTextAndControls *sclTextAndControls, *kbmTextAndControls;

    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    std::vector<std::unique_ptr<SliderAttachment>> sliderAttachments;
    typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
    std::vector<std::unique_ptr<ButtonAttachment>> buttonAttachments;
    std::vector<TWSLambdaParamListener*> lambdaAtttachments;
    std::unique_ptr<PopupMenu> presetMenu;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> version3;
    std::unique_ptr<GroupComponent> groupComponent7;
    std::unique_ptr<GroupComponent> groupComponent8;
    std::unique_ptr<TWSTuningGrid> tuningGrid;
    std::unique_ptr<GroupComponent> groupComponent3;
    std::unique_ptr<GroupComponent> groupComponent2;
    std::unique_ptr<GroupComponent> groupComponent;
    std::unique_ptr<Slider> squareMix;
    std::unique_ptr<TabbedComponent> tabbedComponent;
    std::unique_ptr<Slider> sineMix;
    std::unique_ptr<Slider> sawMix;
    std::unique_ptr<Slider> triMix;
    std::unique_ptr<Slider> AEG_A;
    std::unique_ptr<Slider> FEG_A;
    std::unique_ptr<Slider> AEG_D;
    std::unique_ptr<Slider> FEG_D;
    std::unique_ptr<Slider> AEG_S;
    std::unique_ptr<Slider> FEG_S;
    std::unique_ptr<Slider> AEG_R;
    std::unique_ptr<Slider> FEG_R;
    std::unique_ptr<GroupComponent> groupComponent4;
    std::unique_ptr<Slider> Filt_Cutoff;
    std::unique_ptr<Slider> Filt_Q;
    std::unique_ptr<ToggleButton> LPFToggle;
    std::unique_ptr<ToggleButton> HPFToggle;
    std::unique_ptr<ToggleButton> BPFToggle;
    std::unique_ptr<GroupComponent> groupComponent5;
    std::unique_ptr<Slider> master_sat;
    std::unique_ptr<Slider> master_out;
    std::unique_ptr<Slider> FEG_depth;
    std::unique_ptr<Slider> uni_spread;
    std::unique_ptr<Slider> uni_count;
    std::unique_ptr<Slider> pb_up;
    std::unique_ptr<Slider> pb_down;
    std::unique_ptr<Label> version;
    std::unique_ptr<TextButton> aboutButton;
    std::unique_ptr<Slider> lfo_rate;
    std::unique_ptr<Slider> lfo_delay;
    std::unique_ptr<Slider> lfo_attack;
    std::unique_ptr<ToggleButton> lfotritog;
    std::unique_ptr<ToggleButton> lfosqrtog;
    std::unique_ptr<ToggleButton> lforndtog;
    std::unique_ptr<GroupComponent> groupComponent9;
    std::unique_ptr<Slider> sublevel;
    std::unique_ptr<Slider> sub_oct;
    std::unique_ptr<GroupComponent> groupComponent10;
    std::unique_ptr<GroupComponent> groupComponent11;
    std::unique_ptr<Slider> delay_time;
    std::unique_ptr<Slider> pluck_atn;
    std::unique_ptr<Slider> pluck_flt;
    std::unique_ptr<Slider> pluck_init;
    std::unique_ptr<Slider> pluck_lev;
    std::unique_ptr<TWSPowerToggle> SubPower;
    std::unique_ptr<TWSPowerToggle> PluckPower;
    std::unique_ptr<TWSPowerToggle> DelayPower;
    std::unique_ptr<TWSPowerToggle> VCOPower;
    std::unique_ptr<Label> wheelLab;
    std::unique_ptr<TWSPowerToggle> ModWheelPower;
    std::unique_ptr<GroupComponent> groupComponent6;
    std::unique_ptr<TWSPowerToggle> FilterPower;
    std::unique_ptr<Slider> delay_fb;
    std::unique_ptr<Slider> delay_dry;
    std::unique_ptr<Slider> delay_wet;
    std::unique_ptr<Slider> lfo_pitch;
    std::unique_ptr<Slider> lfo_sublev;
    std::unique_ptr<Slider> lfo_vcolev;
    std::unique_ptr<Slider> lfo_plucklev;
    std::unique_ptr<Slider> lfo_filter;
    std::unique_ptr<Label> version2;
    std::unique_ptr<TextButton> helpButton;
    std::unique_ptr<TextButton> presetButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TWSMainPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

