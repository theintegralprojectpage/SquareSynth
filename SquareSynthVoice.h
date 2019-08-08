/*
  ==============================================================================

    SquareSynthVoice.h
    Created: 5 Aug 2019 8:40:08pm
    Author:  Administrator

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode//JuceHeader.h"
#include <string>
#include "maximilian.h"
#include "SquareSynthSound.h"

class SquareSynthVoice : public SynthesiserVoice
{
  public:

	bool canPlaySound(SynthesiserSound* sound)
	{
		return dynamic_cast<SquareSynthSound*>(sound)!= nullptr;
	}

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchwheelPosition)
	{
		masterEnvelope.trigger = 1;
		inFrequencyMIDI = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		inVelocityMIDI = velocity;
	}

	void stopNote(float velocity, bool allowTailOff)
	{
		masterEnvelope.trigger = 0;
		allowTailOff = true;

		if (velocity == 0)
		{
			clearCurrentNote();
		}
	}

	bool isVoiceActive()
	{
		//TODO
	}

	void pitchWheelMoved(int newPitchWheelValue)
	{
		//TODO
	}

	void controllerMoved(int controllerNumber, int newControllerValue)
	{
		//TODO
	}

	void afterTouchChanged(int newAfterTouchValue)
	{
		//TODO
	}

	void channelPressureChanged(int newChannelPressureValue)
	{
		//TODO
	}

	float renderOsc(int oscNum)
	{
		//TODO add the rest of processing chain, including a phase dial, gain manipulations, and filter
		return getWaveForm(oscNum);
	}

	float getWaveForm(int oscNum)
	{
		switch ( (int) processor.getRawParameterValue(oscType.at(oscNum)))
		{
		  case 0:
			  return oscillators.at(oscNum).sinewave(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		  case 1:
			  return oscillators.at(oscNum).square(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		  case 2:
			  return oscillators.at(oscNum).triangle(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		  case 3:
			  return oscillators.at(oscNum).saw(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		  default:
			  return oscillators.at(oscNum).sinewave(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		}
	}

	int getFineTune(int oscNum)
	{
		return (int)processor.getRawParameterValue(fineTune.at(oscNum));
	}

	int getCourseTune(int oscNum)
	{
		return (int)processor.getRawParameterValue(courseTune.at(oscNum));
	}

	void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{
		for (int i = 0; i < outputBuffer.getNumChannels(); i++)
		{
			for (int j = startSample; j < numSamples; j++)
			{
				outputBuffer.addSample(i, j, renderOsc(0) * 0.25f);
				outputBuffer.addSample(i, j, renderOsc(1) * 0.25f);
				outputBuffer.addSample(i, j, renderOsc(2) * 0.25f);
				outputBuffer.addSample(i, j, renderOsc(3) * 0.25f);
			}
		}
	}

	AudioProcessorValueTreeState processor;
  private:
	  maxiOsc osc1, osc2, osc3, osc4;
	  int waveFormSelection1, waveFormSelection2, waveFormSelection3, waveFormSelection4;
	  maxiEnv masterEnvelope;
	  int inFrequencyMIDI;
	  int inVelocityMIDI;

	  vector<maxiOsc> oscillators{ maxiOsc(), maxiOsc(), maxiOsc(), maxiOsc()};
	  vector<string> courseTune { "courseTune1", "courseTune2", "courseTune3", "courseTune4" };
	  vector<string> fineTune{ "fineTune1", "fineTune2", "fineTune3", "fineTune4" };
	  vector<string> oscType{ "oscType1", "oscType2", "oscType3", "oscType4" };
}

};