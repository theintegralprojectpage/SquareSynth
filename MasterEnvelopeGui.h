/*
  ==============================================================================

    MasterEnvelopeGui.h
    Created: 28 Sep 2019 6:59:19pm
    Author:  ben haywood

  ==============================================================================
*/

#pragma once

#include "SquareSynthProject/JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class MasterEnvelopeGui    : public Component
{
public:
    MasterEnvelopeGui();
    ~MasterEnvelopeGui();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterEnvelopeGui)
};
