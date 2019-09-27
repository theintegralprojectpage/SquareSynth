/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SquareSynthAudioProcessorEditor::SquareSynthAudioProcessorEditor (SquareSynthAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p), oscGui(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 400);
    
    
    addAndMakeVisible(&oscGui);
    
    //===============================================================
    //attack gui
    attackParam.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackParam.setRange(0.1f, 5000.0f);
    attackParam.setValue(0.1f);
    attackParam.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    // attackParameter.addListener(this);
    addAndMakeVisible(&attackParam);
    
    
    //===============================================================
    //decay gui
    
    decayParam.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decayParam.setRange(0.1f, 500.0f);
    decayParam.setValue(500.0f);
    decayParam.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    // attackParameter.addListener(this);
    addAndMakeVisible(&decayParam);
    
    
    //===============================================================
    //sustain gui
    
    sustainParam.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainParam.setRange(0.1f, 0.8f);
    sustainParam.setValue(0.8f);
    sustainParam.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    // attackParameter.addListener(this);
    addAndMakeVisible(&sustainParam);
    
    
    //===============================================================
    //release gui
    
    releaseParam.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseParam.setRange(0.1f, 5000.0f);
    releaseParam.setValue(0.1f);
    releaseParam.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    // attackParameter.addListener(this);
    addAndMakeVisible(&releaseParam);
    
    //===============================================================
    

    //===============================================================
    attackState = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.state, "attack", attackParam);
    decayState = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.state, "decay", decayParam);
    sustainState = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.state, "sustain", sustainParam);
    releaseState = std::make_unique< AudioProcessorValueTreeState::SliderAttachment>(processor.state, "release", releaseParam);
    
    

    
}

SquareSynthAudioProcessorEditor::~SquareSynthAudioProcessorEditor()
{
}

//==============================================================================
void SquareSynthAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void SquareSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
   // Rectangle<int> area = getBounds().reduced(40);
    attackParam.setBounds(53, 50, 40, 100);
    decayParam.setBounds(77, 50, 40, 100);
    sustainParam.setBounds(103, 50, 40, 100);
    releaseParam.setBounds(128, 50, 40, 100);
    
    Rectangle<int> area = getLocalBounds();
    
    const int componentWidth = 200;
    const int componentHeight = 200;

    
    oscGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    

}
