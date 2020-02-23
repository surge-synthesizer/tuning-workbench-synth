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
    table->getHeader().addColumn( "Note", 0, 40 );
    table->getHeader().addColumn( "Name", 1, 40 );
    table->getHeader().addColumn( "Freq (hz)", 2, 90 );
    table->getHeader().addColumn( "log2(f/8.17)", 3, 90 );
    table->setModel( this );
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

    table->setBounds (8, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// These are pretty clearly cribbed from the tutorial
void TWSTuningGrid::paintRowBackground (Graphics& g, int rowNumber, int /*width*/, int /*height*/, bool rowIsSelected)
{
    auto alternateColour = getLookAndFeel().findColour (ListBox::backgroundColourId)
        .interpolatedWith (getLookAndFeel().findColour (ListBox::textColourId), 0.03f);
    if (rowIsSelected)
        g.fillAll (Colours::lightblue);
    else if( rowNumber % 2 )
        g.fillAll (alternateColour);

}

void TWSTuningGrid::paintCell (Graphics& g, int rowNumber, int columnID, int width, int height, bool rowIsSelected)
{

    int noteInScale = rowNumber % 12;
    bool whitekey = true;
    bool noblack = false;
    if( (noteInScale == 1 ||
         noteInScale == 3 ||
         noteInScale == 6 ||
         noteInScale == 8 ||
         noteInScale == 10 ) )
    {
        whitekey = false;
    }
    if( noteInScale == 4 || noteInScale == 11 )
        noblack = true;

    // Black Key
    auto kbdColour = getLookAndFeel().findColour( ListBox::backgroundColourId );
    if( whitekey )
        kbdColour = kbdColour.interpolatedWith( getLookAndFeel().findColour( ListBox::textColourId ), 0.3f );
    if( rowIsSelected )
        kbdColour = Colours::lightblue;

    g.fillAll( kbdColour );

    int txtOff = 0;
    if( columnID == 0 )
    {
        // Black Key
        if( ! whitekey )
        {
            txtOff = 10;
            // "Black Key"
            auto kbc = kbdColour.interpolatedWith( getLookAndFeel().findColour( ListBox::textColourId ), 0.3f );
            g.setColour(kbc);
            g.fillRect(0,0,txtOff, height );

            g.setColour (getLookAndFeel().findColour (ListBox::backgroundColourId));
            g.fillRect (0, height / 2, txtOff, 1 );

        }
    }

    g.setColour (rowIsSelected ? Colours::darkblue : getLookAndFeel().findColour (ListBox::textColourId)); // [5]

    // FixMe - replace this with the proper tuning of course
    auto mn = rowNumber;
    double lmn = tuning.logScaledFrequencyForMidiNote( mn );
    double fr  = tuning.frequencyForMidiNote( mn );

    char txt[256];

    switch( columnID ) {
    case 0:
        sprintf( txt, "%d", mn );
        break;
    case 1:
        static std::vector<std::string> nn = { { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" } };
        sprintf( txt, "%s%d", nn[noteInScale].c_str(), (int)(rowNumber / 12 ) - 1 );
        break;
    case 2:
        sprintf( txt, "%.3lf", fr );
        break;
    case 3:
        sprintf( txt, "%.6lf", lmn );
        break;
    }

    g.drawText (txt, 2 + txtOff, 0, width - 4, height, Justification::centredLeft, true);
    g.setColour (getLookAndFeel().findColour (ListBox::backgroundColourId));
    g.fillRect (width - 1, 0, 1, height);
    if( noblack )
        g.fillRect (0, height - 1, width, 1 );

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TWSTuningGrid" componentName=""
                 parentClasses="public Component, public TableListBoxModel, public TuningUpdatedListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="300"
                 initialHeight="300">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="new component" id="d6aed48af2079d51" memberName="table"
                    virtualName="" explicitFocusOrder="0" pos="8 0 100% 100%" class="TableListBox"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

