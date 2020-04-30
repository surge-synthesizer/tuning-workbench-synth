/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "TWSVoice.h"
#include "PluginProcessor.h"
#include "PluginEditor.h"



//==============================================================================
TuningworkbenchsynthAudioProcessor::TuningworkbenchsynthAudioProcessor()
    : AudioProcessor (BusesProperties()
                      .withOutput ("Output", AudioChannelSet::stereo(), true)
        ),
      synth( *this ),
      parameters( *this,
                  nullptr,
                  Identifier( "tuning-workbench-synthesiser" ),
                  {
                      std::make_unique<AudioParameterFloat>( "sinLevel",
                                                             "Sin Osc Level",
                                                             0.0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterFloat>( "squareLevel",
                                                             "Square Osc Level",
                                                             0.0, 1.0, 0.2 ),
                      std::make_unique<AudioParameterFloat>( "sawLevel",
                                                             "Saw Osc Level",
                                                             0.0, 1.0, 0.8 ),
                      std::make_unique<AudioParameterFloat>( "triLevel",
                                                             "Tri Osc Level",
                                                             0.0, 1.0, 0.3 ),
                      std::make_unique<AudioParameterInt>( "uni_count",
                                                           "Unison Count",
                                                           1, 10, 3 ),
                      std::make_unique<AudioParameterFloat>( "uni_spread",
                                                             "Unison Spread",
                                                             1, 100, 4 ),

                      std::make_unique<AudioParameterInt>( "pb_down",
                                                           "Pitch Bend Down",
                                                           1, 12, 2 ),
                      std::make_unique<AudioParameterInt>( "pb_up",
                                                           "Pitch Bend",
                                                           1, 12, 2 ),

                      envelopeTimeParam( "amp_attack", "Amp Attack", 0.02 ),
                      envelopeTimeParam( "amp_decay", "Amp Decay", 0.1 ),
                      std::make_unique<AudioParameterFloat>( "amp_sustain",
                                                            "Amp Sustain",
                                                            0, 1.0, 0.7 ),
                      envelopeTimeParam( "amp_release", "Amp Release", 0.1 ),

                      envelopeTimeParam( "filter_attack", "Filter Attack", 0.1 ),
                      envelopeTimeParam( "filter_decay", "Filter Decay", 0.1 ),
                      std::make_unique<AudioParameterFloat>( "filter_sustain",
                                                            "Filter Sustain",
                                                            0, 1.0, 0.5 ),
                      envelopeTimeParam( "filter_release", "Filter Release", 0.1 ),
                      std::make_unique<AudioParameterFloat>( "filter_depth",
                                                             "Filter ModulationDepth",
                                                             -1.0, 1.0, 0.0 ),

                      std::make_unique<AudioParameterInt>( "filter_type",
                                                           "Filter Type",
                                                           1,3,1 ),
                      expRangeParam( "filter_cutoff", "Filter Cutoff", 40, 18000, 880 ),
                      std::make_unique<AudioParameterFloat>( "filter_resonance",
                                                             "Filter Resonance",
                                                             0, 1.0, 0.7 ),

                      std::make_unique<AudioParameterFloat>( "master_sat",
                                                             "Master Saturation",
                                                             0, 7.0, 0 ),
                      std::make_unique<AudioParameterFloat>( "master_level",
                                                             "Master Level",
                                                             0, 1.0, 1.0 ),

                      std::make_unique<AudioParameterFloat>( "subosc_level",
                                                             "SubOSC Level",
                                                             0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterInt>( "subosc_oct",
                                                           "SubOSC Octave",
                                                           -3, -1, -1 ),

                      std::make_unique<AudioParameterFloat>( "pluck_flt",
                                                             "Pluck Flt",
                                                             0.05, 0.95, 0.6 ),
                      std::make_unique<AudioParameterFloat>( "pluck_atn",
                                                             "Pluck Atten",
                                                             0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterInt>( "pluck_init",
                                                          "Pluck Init",
                                                          0, 5.0, 0.0 ),
                      std::make_unique<AudioParameterFloat>( "pluck_lev",
                                                             "Pluck Level",
                                                             0, 1.0, 1.0 ),

                      envelopeTimeParam( "delay_time", "Delay Time", 0.5, 0.05, MAX_DELAY_TIME ),
                      std::make_unique<AudioParameterFloat>( "delay_fb",
                                                             "Delay Feedback",
                                                             0., 1.0, 0.1 ),
                      std::make_unique<AudioParameterFloat>( "delay_wet",
                                                             "Delay Wet Level",
                                                             0., 1.0, 0.4 ),
                      std::make_unique<AudioParameterFloat>( "delay_dry",
                                                             "Delay Dry Level",
                                                             0., 1.0, 1.0 ),


                      std::make_unique<AudioParameterInt>( "lfo_type",
                                                          "LFO Type",
                                                          0, 2.0, 0.0 ),
                      std::make_unique<AudioParameterFloat>( "lfo_rate",
                                                             "LFO Rate",
                                                             0.0, 12.0, 3.0 ),
                      envelopeTimeParam( "lfo_delay", "LFO Delay", 0.0 ),
                      envelopeTimeParam( "lfo_attack", "LFO Attack", 0.0 ),
                      std::make_unique<AudioParameterFloat>( "lfo_pitch",
                                                             "LFO Pitch",
                                                             0.0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterFloat>( "lfo_vcolev",
                                                             "LFO VCO Level",
                                                             0.0, 1.0, 0.1 ),
                      std::make_unique<AudioParameterFloat>( "lfo_sublev",
                                                             "LFO VCO Level",
                                                             0.0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterFloat>( "lfo_plucklev",
                                                             "LFO VCO Level",
                                                             0.0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterFloat>( "lfo_filter",
                                                             "LFO Filter",
                                                             0.0, 10.0, 0.0 ),

                      std::make_unique<AudioParameterInt>( "vco_on",
                                                           "VCO On",
                                                           0, 1.0, 1.0 ),
                      std::make_unique<AudioParameterInt>( "sub_on",
                                                           "SUB On",
                                                           0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterInt>( "pluck_on",
                                                           "PLUCK On",
                                                           0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterInt>( "delay_on",
                                                           "Delay On",
                                                           0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterInt>( "modwheel_on",
                                                           "ModWheel On",
                                                           0, 1.0, 0.0 ),
                      std::make_unique<AudioParameterInt>( "filter_on",
                                                           "Filter On",
                                                           0, 1.0, 1.0 )

                  } )
{
    for( int i=0; i<32; ++i )
    {
        auto v = new TWSVoice(this);
        addTuningUpdatedListener( v );
        synth.addVoice( v );
    }

    synth.addSound( new TWSSound( this ) );

#define SP(x) x = parameters.getRawParameterValue( #x )
    
    SP(sinLevel);
    SP(squareLevel);
    SP(sawLevel);
    SP(triLevel);

    SP(uni_count);
    SP(uni_spread);
    
    SP(amp_attack);
    SP(amp_decay);
    SP(amp_sustain);
    SP(amp_release);

    SP(filter_attack);
    SP(filter_decay);
    SP(filter_sustain);
    SP(filter_release);
    SP(filter_depth);

    SP(filter_type);
    SP(filter_cutoff);
    SP(filter_resonance);

    SP(master_sat);
    SP(master_level);

    SP(pb_down);
    SP(pb_up);

    SP(subosc_level);
    SP(subosc_oct);
    SP(pluck_flt);
    SP(pluck_atn);
    SP(pluck_init);
    SP(pluck_lev);

    SP(delay_time);
    SP(delay_fb);
    SP(delay_wet);
    SP(delay_dry);

    SP(lfo_type);
    SP(lfo_rate);
    SP(lfo_delay);
    SP(lfo_attack);
    SP(lfo_pitch);
    SP(lfo_vcolev);
    SP(lfo_sublev);
    SP(lfo_plucklev);
    SP(lfo_filter);

    SP(vco_on);
    SP(sub_on);
    SP(pluck_on);
    SP(delay_on);
    SP(modwheel_on);
    SP(filter_on);
    
    auto initS = Tunings::evenTemperament12NoteScale();
    setSCL( initS.rawText, false );
    setKBM( "", false );
    retune();

    // And finally set up the factory patches.
    auto mt = []( std::string a, const char* b, size_t c ) {
                  return std::make_tuple(a,b,c);
              };
    factoryPresets.push_back( mt( "Init", 0, 0 ) );              
    factoryPresets.push_back( mt( "Init Sine", BinaryData::INIT_Sine_twsxml, BinaryData::INIT_Sine_twsxmlSize ) );
    factoryPresets.push_back( mt( "Init Square", BinaryData::INIT_Square_twsxml, BinaryData::INIT_Square_twsxmlSize ) );
    factoryPresets.push_back( mt( "Init Saw", BinaryData::INIT_Saw_twsxml, BinaryData::INIT_Saw_twsxmlSize ) );
    factoryPresets.push_back( mt( "TWS Init ", BinaryData::TWS_Init_twsxml, BinaryData::TWS_Init_twsxmlSize ) );
    factoryPresets.push_back( mt( "Pads", 0, 0 ) );             
    factoryPresets.push_back( mt( "Discovery", BinaryData::Discovery_twsxml, BinaryData::Discovery_twsxmlSize ) );              
    factoryPresets.push_back( mt( "Facets 15", BinaryData::Facets_15_twsxml, BinaryData::Just_Frippertonics_twsxmlSize ) );              
    factoryPresets.push_back( mt( "On Whole Tones", BinaryData::On_Whole_Tones_twsxml, BinaryData::On_Whole_Tones_twsxmlSize ) );              
    factoryPresets.push_back( mt( "Swell Pulse", BinaryData::Swell_Pulse_Pad_twsxml, BinaryData::Swell_Pulse_Pad_twsxmlSize ) );              
    factoryPresets.push_back( mt( "Xenarctica", BinaryData::Xenarctica_twsxml, BinaryData::Xenarctica_twsxmlSize ) );              
    factoryPresets.push_back( mt( "Keys and Mallets", 0, 0 ) );
    factoryPresets.push_back( mt( "Marimba", BinaryData::Marimba_twsxml, BinaryData::Marimba_twsxmlSize ) );
    factoryPresets.push_back( mt( "Space Clav", BinaryData::Space_Clav_twsxml, BinaryData::Space_Clav_twsxmlSize ) );
    factoryPresets.push_back( mt( "Strings", 0, 0 ) );
    factoryPresets.push_back( mt( "Fibonacci Plucks", BinaryData::Fibonacci_Plucks_twsxml, BinaryData::Fibonacci_Plucks_twsxmlSize ) );    
    factoryPresets.push_back( mt( "Pluckedelica", BinaryData::Pluckedelica_twsxml, BinaryData::Pluckedelica_twsxmlSize ) );
    factoryPresets.push_back( mt( "Struck String", BinaryData::Struck_String_twsxml, BinaryData::Struck_String_twsxmlSize ) );
    factoryPresets.push_back( mt( "Swarmandal", BinaryData::Swarm_Andal_twsxml, BinaryData::Swarm_Andal_twsxmlSize ) );    
    factoryPresets.push_back( mt( "Winds", 0, 0 ) );
    factoryPresets.push_back( mt( "Bamboo Flute", BinaryData::Bamboo_Flute_twsxml, BinaryData::Bamboo_Flute_twsxmlSize ) );
    factoryPresets.push_back( mt( "Brass Lead", BinaryData::Brass_Lead_twsxml, BinaryData::Brass_Lead_twsxmlSize ) );    
    factoryPresets.push_back( mt( "Lusheng Flute", BinaryData::Lusheng_Flute_twsxml, BinaryData::Lusheng_Flute_twsxmlSize ) );
}

TuningworkbenchsynthAudioProcessor::~TuningworkbenchsynthAudioProcessor()
{
    for( int i=0; i<synth.getNumVoices(); ++i )
    {
        auto tl = dynamic_cast<TuningUpdatedListener*>( synth.getVoice(i) );
        if( tl )
            removeTuningUpdatedListener( tl );
    }
}

//==============================================================================
const String TuningworkbenchsynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TuningworkbenchsynthAudioProcessor::acceptsMidi() const
{
    return true;
}

bool TuningworkbenchsynthAudioProcessor::producesMidi() const
{
    return false;
}

bool TuningworkbenchsynthAudioProcessor::isMidiEffect() const
{
    return false;
}

double TuningworkbenchsynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TuningworkbenchsynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TuningworkbenchsynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TuningworkbenchsynthAudioProcessor::setCurrentProgram (int index)
{
}

const String TuningworkbenchsynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void TuningworkbenchsynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TuningworkbenchsynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    synth.setCurrentPlaybackSampleRate( sampleRate );
}

void TuningworkbenchsynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

bool TuningworkbenchsynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;

    return true;
}

void TuningworkbenchsynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    if( noteListeners.size() > 0 )
    {
        bool noteTog = false;
        MidiBufferIterator midiIterator  = midiMessages.begin();
        int midiEventPos;

        int ons[127], offs[127];
        int onp=0, offp=0;

        while( midiIterator != midiMessages.end() )
        {
            auto m = (*midiIterator).getMessage();
            if( m.isNoteOn() )
            {
                ons[onp++] = m.getNoteNumber();
                noteTog = true;
            }
            else if( m.isNoteOff() )
            {
                offs[offp++] = m.getNoteNumber();
                noteTog = true;
            }
        }

        if( noteTog )
        {
            /*
            ** We have to have at least one oscillator on (although this is a rare case)
            */
            if( ! ( *vco_on || *pluck_on || *sub_on ) )
            {
                *vco_on = 1.0; // this will get re-written in the async update
                auto vo = parameters.getParameter( "vco_on" );
                vo->beginChangeGesture();
                vo->setValueNotifyingHost( 1.0 );
                vo->endChangeGesture();
            }
            for( auto l : noteListeners )
            {
                for( int i=0; i<onp; ++i )
                    l->noteOn( ons[i] );
                for( int i=0; i<offp; ++i )
                    l->noteOff( offs[i] );
            }
        }
    }

    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples() );
}

//==============================================================================
bool TuningworkbenchsynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TuningworkbenchsynthAudioProcessor::createEditor()
{
    return new TuningworkbenchsynthAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void TuningworkbenchsynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml (state.createXml());

    xml->deleteAllChildElementsWithTagName( "tuningState" );
    
    auto txml = xml->createNewChildElement( "tuningState" );
    auto sclx = txml->createNewChildElement( "scl" );
    sclx->addTextElement(currentSCLString);
    auto kbmx = txml->createNewChildElement( "kbm" );
    kbmx->addTextElement(currentKBMString);

    copyXmlToBinary (*xml, destData);
}

void TuningworkbenchsynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState.get() != nullptr)
    {
        if (xmlState->hasTagName (parameters.state.getType()))
            parameters.replaceState (ValueTree::fromXml (*xmlState));


        auto txml = xmlState->getChildByName( "tuningState" );
        if( txml )
        {
            bool needsRT = false;

            auto sclx = txml->getChildByName( "scl" );
            auto kbmx = txml->getChildByName( "kbm" );
            std::string s = "";

            if( sclx && sclx->getFirstChildElement() && sclx->getFirstChildElement()->isTextElement() )
            {
                s = sclx->getFirstChildElement()->getText().toStdString();
                if( s.size() > 1 )
                {
                    needsRT = true;
                    setSCL( s, false );
                }
            }
            
            std::string k = "";
            if( kbmx && kbmx->getFirstChildElement() && kbmx->getFirstChildElement()->isTextElement() )
            {
                k = kbmx->getFirstChildElement()->getText().toStdString();
                if( k.size() > 1 )
                {
                    needsRT = true;
                    setKBM( k, false );
                }
            }

            if( needsRT )
            {
                retune();
            }
        }
    }
}


void TuningworkbenchsynthAudioProcessor::setSCL( String SCL, bool dretune )
{
    currentSCLString = SCL;
    if( dretune )
        retune();
}

void TuningworkbenchsynthAudioProcessor::setKBM( String KBM, bool dretune )
{
    currentKBMString = KBM;
    if( dretune )
        retune();
}

void TuningworkbenchsynthAudioProcessor::retune() {
    bool sclGood = false;
    try
    {
        auto s = Tunings::parseSCLData( currentSCLString.toStdString() );
        sclGood = true;
        auto k = Tunings::KeyboardMapping();
        if( currentKBMString.length() > 0 )
        {
            k = Tunings::parseKBMData( currentKBMString.toStdString() );
        }
        tuning = Tunings::Tuning( s, k );
        for( auto l : tuningListeners )
        {
            l->tuningUpdated( tuning );
        }
    }
    catch( Tunings::TuningError &e )
    {
        AlertWindow::showMessageBoxAsync( AlertWindow::AlertIconType::WarningIcon,
                                          "Error Applying Tuning",
                                          e.what(),
                                          "OK" );
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TuningworkbenchsynthAudioProcessor();
}
