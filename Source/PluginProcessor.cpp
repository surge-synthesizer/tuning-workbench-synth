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
                                                             0.0, 1.0, 1.0 ),
                      std::make_unique<AudioParameterFloat>( "squareLevel",
                                                             "Square Osc Level",
                                                             0.0, 1.0, 1.0 ),
                      std::make_unique<AudioParameterFloat>( "sawLevel",
                                                             "Saw Osc Level",
                                                             0.0, 1.0, 1.0 ),
                      std::make_unique<AudioParameterFloat>( "triLevel",
                                                             "Tri Osc Level",
                                                             0.0, 1.0, 1.0 ),
                      std::make_unique<AudioParameterInt>( "uni_count",
                                                           "Unison Count",
                                                           1, 10, 1 ),
                      std::make_unique<AudioParameterFloat>( "uni_spread",
                                                             "Unison Spread",
                                                             1, 100, 10 ),

                      std::make_unique<AudioParameterInt>( "pb_down",
                                                           "Pitch Bend Down",
                                                           1, 12, 2 ),
                      std::make_unique<AudioParameterInt>( "pb_up",
                                                           "Pitch Bend",
                                                           1, 12, 2 ),

                      std::make_unique<AudioParameterFloat>( "amp_attack",
                                                            "Amp Attack",
                                                            0, 10.0, 0.1 ),
                      std::make_unique<AudioParameterFloat>( "amp_decay",
                                                            "Amp Decay",
                                                            0, 10.0, 0.1 ),
                      std::make_unique<AudioParameterFloat>( "amp_sustain",
                                                            "Amp Sustain",
                                                            0, 1.0, 0.5 ),
                      std::make_unique<AudioParameterFloat>( "amp_release",
                                                            "Amp Release",
                                                            0, 10.0, 0.1 ),

                      std::make_unique<AudioParameterFloat>( "filter_attack",
                                                            "Filter Attack",
                                                            0, 10.0, 0.1 ),
                      std::make_unique<AudioParameterFloat>( "filter_decay",
                                                            "Filter Decay",
                                                            0, 10.0, 0.1 ),
                      std::make_unique<AudioParameterFloat>( "filter_sustain",
                                                            "Filter Sustain",
                                                            0, 1.0, 0.5 ),
                      std::make_unique<AudioParameterFloat>( "filter_release",
                                                            "Filter Release",
                                                            0, 10.0, 0.1 ),
                      std::make_unique<AudioParameterFloat>( "filter_depth",
                                                            "Filter ModulationDepth",
                                                            0, 1.0, 0.0 ),

                      std::make_unique<AudioParameterInt>( "filter_type",
                                                           "Filter Type",
                                                           1,3,1 ),
                      std::make_unique<AudioParameterFloat>( "filter_cutoff",
                                                             "Filter Cutoff",
                                                             10.0, 20000.0, 880 ),
                      std::make_unique<AudioParameterFloat>( "filter_resonance",
                                                             "Filter Resonance",
                                                             0, 1.0, 0.7 ),

                      std::make_unique<AudioParameterFloat>( "master_sat",
                                                             "Master Saturation",
                                                             0, 5, 0 ),
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
                                                             0, 1.0, 0.0 ),

                      std::make_unique<AudioParameterFloat>( "delay_time",
                                                             "Delay Time",
                                                             0.05, MAX_DELAY_TIME, 0.5 ),
                      std::make_unique<AudioParameterFloat>( "delay_fb",
                                                             "Delay Feedback",
                                                             0., 1.0, 0.1 ),


                      std::make_unique<AudioParameterInt>( "lfo_type",
                                                          "LFO Type",
                                                          0, 2.0, 0.0 ),
                      std::make_unique<AudioParameterFloat>( "lfo_rate",
                                                             "LFO Rate",
                                                             0.1, 100.0, 5.0 ),
                      std::make_unique<AudioParameterFloat>( "lfo_delay",
                                                             "LFO Delay",
                                                             0.0, 10.0, 0.0 ),
                      std::make_unique<AudioParameterFloat>( "lfo_attack",
                                                             "LFO Attack",
                                                             0., 10.0, 0.0 ),
                      std::make_unique<AudioParameterFloat>( "lfo_pitch",
                                                             "LFO Pitch",
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
                                                           0, 1.0, 1.0 ),
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

    SP(lfo_type);
    SP(lfo_rate);
    SP(lfo_delay);
    SP(lfo_attack);
    SP(lfo_pitch);
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
    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples() );
    if( noteListeners.size() > 0 )
    {
        bool noteTog = false;
        MidiBuffer::Iterator midiIterator (midiMessages);
        midiIterator.setNextSamplePosition (0);
        int midiEventPos;
        MidiMessage m;

        int ons[127], offs[127];
        int onp=0, offp=0;

        while( midiIterator.getNextEvent(m, midiEventPos ) )
        {
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
            for( auto l : noteListeners )
            {
                for( int i=0; i<onp; ++i )
                    l->noteOn( ons[i] );
                for( int i=0; i<offp; ++i )
                    l->noteOff( offs[i] );
            }
        }
    }
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
