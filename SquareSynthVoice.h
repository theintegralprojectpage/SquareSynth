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
        DBG("level: " << inVelocityMIDI);
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
    
    void envelopeParams(float* attack, float* decay, float* sustain, float* release)
    {
        masterEnvelope.setAttack((double)*attack);
        masterEnvelope.setDecay((double)*decay);
        masterEnvelope.setSustain((double)*sustain);
        masterEnvelope.setRelease((double)*release);
//        DBG("Attack: " << *attack);
//        DBG("decay: " << *decay);
//        DBG("sustain: " << *sustain);
//        DBG("release: " << *release);

        

    }
    void getFineTune(float* oscNum)
    {
        fineTune1 = (int)*oscNum / 10;
        //DBG("fineTune" << fineTune1);
    }
    
    void getCourseTune(float* oscNum)
    {
        courseTune1 = (int)*oscNum / 10;
//        double deBug = inFrequencyMIDI + fineTune1 + courseTune1;
//        DBG("Debug" << deBug);
        //have to fix course b/c it different in serum!
        //TO DO add semi Tone
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
        waveFormSelection1 = *select;
    }

	float renderOsc(int oscNum)
	{
		//TODO add the rest of processing chain, including a phase dial, gain manipulations, and filter
		return masterEnvelope.adsr((double)getWaveForm(oscNum), masterEnvelope.trigger);
	}

	double getWaveForm(int oscNum)
	{
        
		switch (oscNum)
		{
		  case 0:
              return osc1.sinewave(inFrequencyMIDI + fineTune1 + courseTune1);
		  case 1:
                return osc1.square(inFrequencyMIDI + fineTune1 + courseTune1);
		  case 2:
			  return osc1.triangle(inFrequencyMIDI + fineTune1 + courseTune1);
		  case 3:
			  return osc1.saw(inFrequencyMIDI + fineTune1 + courseTune1);
		  default:
			  return osc1.sinewave(inFrequencyMIDI + fineTune1 + courseTune1);
		}
        
	}

//    void getFineTune(float* oscNum)
//    {
//        fineTune1 =  *oscNum;
//    }
//
//    int getCourseTune(int oscNum)
//    {
//        return (oscNum);
//    }

	void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{
		for (int sample = 0; sample < numSamples; sample++)
		{
			for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
			{
				outputBuffer.addSample(channel, startSample, renderOsc(waveFormSelection1));
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
    double inFrequencyMIDI;
    int inVelocityMIDI;
    double fineTune1;
    double courseTune1;

//    double level;
    
    

//   vector<maxiOsc> oscillators{ maxiOsc(), maxiOsc(), maxiOsc(), maxiOsc()};
//     vector<string> courseTune { "courseTune1", "courseTune2", "courseTune3", "courseTune4" };
//      vector<string> fineTune{ "fineTune1", "fineTune2", "fineTune3", "fineTune4" };
//      vector<string> oscType{ "oscType1", "oscType2", "oscType3", "oscType4" };


};
