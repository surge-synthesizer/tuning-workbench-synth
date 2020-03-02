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

#include "TWSTuningGrid.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TWSTuningGrid::TWSTuningGrid ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    table.reset (new TableListBox());
    addAndMakeVisible (table.get());
    table->setName ("new component");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 300);


    //[Constructor] You can add your own custom stuff here..
    mod = std::make_unique<surgesynthteam_TuningTableListBoxModel>();
    mod->setTableListBox( table.get() );
    mod->setupDefaultHeaders( table.get() );
    
    table->setModel( mod.get() );

    table->getViewport()->setScrollBarsShown(true,false);
    table->getViewport()->setViewPositionProportionately( 0.0,  60.0 / 127.0 );
    //[/Constructor]
}

TWSTuningGrid::~TWSTuningGrid()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    table = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TWSTuningGrid::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TWSTuningGrid::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    table->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    table->getViewport()->setScrollBarsShown(true,false);
    table->getViewport()->setViewPositionProportionately( 0.0, 60.0 / 127.0 );
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TWSTuningGrid" componentName=""
                 parentClasses="public Component, public TuningUpdatedListener, public NotesOnChangedListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="300"
                 initialHeight="300">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="new component" id="d6aed48af2079d51" memberName="table"
                    virtualName="" explicitFocusOrder="0" pos="0 0 100% 100%" class="TableListBox"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
    
