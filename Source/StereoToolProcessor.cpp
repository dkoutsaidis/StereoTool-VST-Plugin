/*

"StereoToolProcessor" class definition.

This class controls the plugins core audio processing.
Parent class of the "StereoToolEditor" class.

Date: 29/03/2017
Plugin Name: Stereo Tool
Author: Dimitris Koutsaidis

to do:
- learn how to initialize all kind of things (e.g. in/out channel layout)..
- clarify last sample problem in the 'for' loop of the "processBlock" method..

*/


#include "JuceHeader.h"
#include "StereoToolEditor.h"


class StereoToolProcessor : public AudioProcessor
{
public:

	StereoToolProcessor() : parameters(*this, nullptr)
    {
        parameters.createAndAddParameter ("monoMix", "Stereo to Mono Mix (%)", String(), NormalisableRange<float> (0.0f, 100.0f, 1.0f), 0.0f, nullptr, nullptr);
        
		parameters.state = ValueTree(Identifier("Stereo Tool"));
    }

	~StereoToolProcessor() {}

    void prepareToPlay (double, int) override {}
    
    void releaseResources() override {}

	void processBlock(AudioSampleBuffer& buffer, MidiBuffer&) override
    {
		const float monoMix = *parameters.getRawParameterValue("monoMix");
		const float numSamples = buffer.getNumSamples();
		float* const leftChannelDataOut = buffer.getWritePointer(0);
		float* const rightChannelDataOut = buffer.getWritePointer(1);

		for (int i = 0; i < numSamples; ++i)
		{
			float leftChannelDataIn = buffer.getReadPointer(0)[i];
			float rightChannelDataIn = buffer.getReadPointer(1)[i];
			float monoDataIn = (leftChannelDataIn + rightChannelDataIn) / 2;

			leftChannelDataOut[i] = (1 - monoMix*0.01)*rightChannelDataIn + (monoMix*0.01)*monoDataIn;
			rightChannelDataOut[i] = (1 - monoMix*0.01)*leftChannelDataIn + (monoMix*0.01)*monoDataIn;
		}
    }

	AudioProcessorEditor* createEditor() override         { return new StereoToolEditor (*this, parameters); }
    bool hasEditor() const override                       { return true;   }
	const String getName() const override                 { return "Stereo Tool"; }
    bool acceptsMidi() const override                     { return false; }
    bool producesMidi() const override                    { return false; }
    double getTailLengthSeconds() const override          { return 0; }
	int getNumPrograms() override                         { return 1; }
    int getCurrentProgram() override                      { return 0; }
    void setCurrentProgram (int) override                 { }
    const String getProgramName (int) override            { return String(); }
    void changeProgramName (int, const String& ) override { }

    void getStateInformation (MemoryBlock& destData) override
    {
        ScopedPointer<XmlElement> xml (parameters.state.createXml());
        copyXmlToBinary (*xml, destData);
    }
    
    void setStateInformation (const void* data, int sizeInBytes) override
    {
        ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
        
        if (xmlState != nullptr)
            if (xmlState->hasTagName (parameters.state.getType()))
                parameters.state = ValueTree::fromXml (*xmlState);
    }
       
private:
    AudioProcessorValueTreeState parameters;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StereoToolProcessor)
};


AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new StereoToolProcessor();
}