

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


// ========== Declare the Plug-In's processor class ==========
class StereoToolAudioProcessor  : public AudioProcessor
{
public:
    // declare constractor and deconstractor
    StereoToolAudioProcessor();
    ~StereoToolAudioProcessor();

    
    // declare default methods
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif
    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    
    // declare extra default methods
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    const String getName() const override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    
    // declare custom variables
    double monoMix;
    bool buttonState;
    
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StereoToolAudioProcessor)
};


// <----- EOF PluginProcessor.h

