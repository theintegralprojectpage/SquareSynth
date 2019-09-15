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
    
    void envelopeParams(float* attack) //double* decay, double* sustain, double* release)
    {
        masterEnvelope.setAttack((double)*attack);
//        masterEnvelope.setDecay(*decay);
//        masterEnvelope.setSustain(*sustain);
//        masterEnvelope.setRelease(*release);
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
    
    void getOscType(float* select)
    {
        
    }

	float renderOsc(int oscNum)
	{
		//TODO add the rest of processing chain, including a phase dial, gain manipulations, and filter
		return getWaveForm(oscNum);
	}

	float getWaveForm(int oscNum)
	{
		switch ((int)oscNum)
		{
		  case 0:
			  return osc1.sinewave(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		  case 1:
			  return osc1.square(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		  case 2:
			  return osc1.triangle(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		  case 3:
			  return osc1.saw(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		  default:
			  return osc1.sinewave(inFrequencyMIDI + getFineTune(oscNum) + getCourseTune(oscNum));
		}
	}

	int getFineTune(int oscNum)
	{
		return oscNum;
	}

	int getCourseTune(int oscNum)
	{
		return (oscNum);
	}

	void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{
		for (int i = 0; i < outputBuffer.getNumChannels(); i++)
		{
			for (int j = 0; j < numSamples; j++)
			{
				outputBuffer.addSample(i, j, renderOsc(0) * 0.25f);
//                outputBuffer.addSample(i, j, renderOsc(1) * 0.25f);
//                outputBuffer.addSample(i, j, renderOsc(2) * 0.25f);
//                outputBuffer.addSample(i, j, renderOsc(3) * 0.25f);
			}
            startSample++;
		}
	}

	//AudioProcessorValueTreeState processor;
  private:
    maxiOsc osc1, osc2, osc3, osc4;
    int waveFormSelection1, waveFormSelection2, waveFormSelection3, waveFormSelection4;
    maxiEnv masterEnvelope;
    int inFrequencyMIDI;
    int inVelocityMIDI;
    
    
    

//   vector<maxiOsc> oscillators{ maxiOsc(), maxiOsc(), maxiOsc(), maxiOsc()};
//     vector<string> courseTune { "courseTune1", "courseTune2", "courseTune3", "courseTune4" };
//      vector<string> fineTune{ "fineTune1", "fineTune2", "fineTune3", "fineTune4" };
//      vector<string> oscType{ "oscType1", "oscType2", "oscType3", "oscType4" };


};
