/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
	std::vector<RangedAudioParameter> params;
	//TODO finish constructor

	params.push_back(AudioParameterFloat("fineTune1", "fineTune1", NormalisableRange<float>(-200, 200), 0));
	params.push_back(AudioParameterFloat("fineTune2", "fineTune2", NormalisableRange<float>(-200, 200), 0));
	params.push_back(AudioParameterFloat("fineTune3", "fineTune3", NormalisableRange<float>(-200, 200), 0));
	params.push_back(AudioParameterFloat("fineTune4", "fineTune4", NormalisableRange<float>(-200, 200), 0));

	params.push_back(AudioParameterInt("courseTune1", "courseTune1", -24, 24, 0));
	params.push_back(AudioParameterInt("courseTune2", "courseTune2", -24, 24, 0));
	params.push_back(AudioParameterInt("courseTune3", "courseTune3", -24, 24, 0));
	params.push_back(AudioParameterInt("courseTune4", "courseTune4", -24, 24, 0));

	params.push_back(AudioParameterInt("oscType1", "oscType1", 0, 3, 0));
	params.push_back(AudioParameterInt("oscType2", "oscType2", 0, 3, 0));
	params.push_back(AudioParameterInt("oscType3", "oscType3", 0, 3, 0));
	params.push_back(AudioParameterInt("oscType4", "oscType4", 0, 3, 0));

	return { params.begin, params.end };
}

SquareSynthAudioProcessor::SquareSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
	, state(*this, nullptr, "PARAMS", createParameterLayout() )
{

}

SquareSynthAudioProcessor::~SquareSynthAudioProcessor()
{
}

//==============================================================================
const String SquareSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SquareSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SquareSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SquareSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SquareSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SquareSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SquareSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SquareSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String SquareSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void SquareSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SquareSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void SquareSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SquareSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SquareSynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool SquareSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SquareSynthAudioProcessor::createEditor()
{
    return new SquareSynthAudioProcessorEditor (*this);
}

//==============================================================================
void SquareSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SquareSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SquareSynthAudioProcessor();
}
