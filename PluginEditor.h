/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SquareSynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SquareSynthAudioProcessorEditor (SquareSynthAudioProcessor&);
    ~SquareSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SquareSynthAudioProcessor& processor;
    
    Slider attackParam;
    Slider decayParam;
    Slider sustainParam;
    Slider releaseParam;
    
    Slider fineTuneParam;
    Slider couresTuneParam;
    
    ComboBox oscSelect;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SquareSynthAudioProcessorEditor)
public:
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackState;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayState;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainState;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseState;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> oscSelectState;
};
