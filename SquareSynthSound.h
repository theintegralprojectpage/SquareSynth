/*
  ==============================================================================

    SquareSynthSound.h
    Created: 5 Aug 2019 8:43:00pm
    Author:  Administrator

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SquareSynthSound: public SynthesiserSound
{
  public:

	bool appliesToNote( int midiNoteNumber )
	{
		return true;
	}

	bool appliesToChannel(int channelNumber)
	{
		return true;
	}
};
