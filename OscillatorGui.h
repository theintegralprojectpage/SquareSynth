/*
  ==============================================================================

    OscillatorGui.h
    Created: 26 Sep 2019 6:09:46pm
    Author:  ben haywood

  ==============================================================================
*/

#pragma once

#include "SquareSynthProject/JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class OscillatorGui    : public Component
{
public:
    OscillatorGui(SquareSynthAudioProcessor&);
    ~OscillatorGui();

    void paint (Graphics&) override;
    void resized() override;
    
    
    Slider fineTuneParam;
    Slider couresTuneParam;
    
    ComboBox oscSelect;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorGui)
    SquareSynthAudioProcessor& processor;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> oscSelectState;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> fineTuneState;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> courseTuneState;

};
