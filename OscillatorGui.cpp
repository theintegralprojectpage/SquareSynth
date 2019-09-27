/*
  ==============================================================================

    OscillatorGui.cpp
    Created: 26 Sep 2019 6:09:46pm
    Author:  ben haywood

  ==============================================================================
*/

#include "SquareSynthProject/JuceLibraryCode/JuceHeader.h"
#include "OscillatorGui.h"

//==============================================================================
OscillatorGui::OscillatorGui(SquareSynthAudioProcessor& p) : processor (p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    //osc1 select combobox gui
    oscSelect.addItem("Sine", 1);
    oscSelect.addItem("Square", 2);
    oscSelect.addItem("Triangle", 3);
    oscSelect.addItem("Saw", 4);
    
    addAndMakeVisible(&oscSelect);
    
    //================================================================
    
    //fine tune
    fineTuneParam.setSliderStyle(Slider::SliderStyle::Rotary);
    fineTuneParam.setRange(-100.0f, 100.0f);
    fineTuneParam.setValue(0.0f);
    fineTuneParam.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    fineTuneParam.setSliderStyle(Slider::RotaryVerticalDrag);
    
    addAndMakeVisible(&fineTuneParam);
    
    //====================================================================
    
    //coures tune
    
    couresTuneParam.setSliderStyle(Slider::SliderStyle::Rotary);
    couresTuneParam.setRange(-64.0, 64.0f);
    couresTuneParam.setValue(0.0f);
    couresTuneParam.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    couresTuneParam.setSliderStyle(Slider::RotaryVerticalDrag);

    addAndMakeVisible(&couresTuneParam);
    
    //=====================================================================
    //
    oscSelectState = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.state, "wavetype", oscSelect);
    
    
    
    fineTuneState = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.state, "fineTune1", fineTuneParam);
    
    courseTuneState = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.state, "courseTune1", couresTuneParam);


}

OscillatorGui::~OscillatorGui()
{
}

void OscillatorGui::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("OscillatorGui", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void OscillatorGui::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    oscSelect.setBounds(0, 0, 50, 50);
    
    fineTuneParam.setBounds(50, 0, 50, 50);
    
    couresTuneParam.setBounds(100, 0, 50, 50);

}
