/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "TWSVoice.h"


//==============================================================================
TuningworkbenchsynthAudioProcessor::TuningworkbenchsynthAudioProcessor()
    : AudioProcessor (BusesProperties()
                      .withOutput ("Output", AudioChannelSet::stereo(), true)
        ),
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
                                                             10, 100, 1 ),

                      std::make_unique<AudioParameterInt>( "pb_down",
                                                           "Pitch Bend Down",
                                                           1, 10, 2 ),
                      std::make_unique<AudioParameterInt>( "pb_up",
                                                           "Pitch Bend",
                                                           1, 10, 2 ),

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
                                                           0,2,0 ),
                      std::make_unique<AudioParameterFloat>( "filter_cutoff",
                                                             "Filter Cutoff",
                                                             10, 30000.0, 880 ),
                      std::make_unique<AudioParameterFloat>( "filter_resonance",
                                                             "Filter Resonance",
                                                             0, 1.0, 0.7 ),

                      std::make_unique<AudioParameterFloat>( "master_sat",
                                                             "Master Saturation",
                                                             0, 5, 0 ),
                      std::make_unique<AudioParameterFloat>( "master_level",
                                                             "Master Level",
                                                             0, 1.0, 1.0 )

                  } )
{
    for( int i=0; i<32; ++i )
        synth.addVoice( new TWSVoice(this) );

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

    SP(filter_cutoff);
    SP(filter_resonance);

    SP(master_sat);
    SP(master_level);

    auto initS = Tunings::evenTemperament12NoteScale();
    setSCL( initS.rawText, false );
    setKBM( "", false );
    retune();
}

TuningworkbenchsynthAudioProcessor::~TuningworkbenchsynthAudioProcessor()
{
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
    static float mo = 0;
    float ml = *sinLevel;
    if( mo != ml )
    {
        std::cout << "AL=" << ml << std::endl;
        mo = ml;
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
    try
    {
        auto s = Tunings::parseSCLData( currentSCLString.toStdString() );
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
        // FIXME - give feedback to user
        std::cout << e.what() << std::endl;
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TuningworkbenchsynthAudioProcessor();
}
