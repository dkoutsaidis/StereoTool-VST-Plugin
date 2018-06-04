

#include "PluginProcessor.h"
#include "PluginEditor.h"


// ========== Define Constractor ==========
StereoToolAudioProcessor::StereoToolAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}


// ========== Define Deconstractor ==========
StereoToolAudioProcessor::~StereoToolAudioProcessor()
{
}


// ========== Define getName Method ==========
const String StereoToolAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

// ========== Define acceptsMidi Method ==========
bool StereoToolAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

// ========== Define producesMidi Method ==========
bool StereoToolAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

// ========== Define isMidiEffect Method ==========
bool StereoToolAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

// ========== Define getTailLengthSeconds Method ==========
double StereoToolAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

// ========== Define getNumPrograms Method ==========
int StereoToolAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

// ========== Define getCurrentProgram Method ==========
int StereoToolAudioProcessor::getCurrentProgram()
{
    return 0;
}

// ========== Define setCurrentProgram Method ==========
void StereoToolAudioProcessor::setCurrentProgram (int index)
{
}

// ========== Define getProgramName Method ==========
const String StereoToolAudioProcessor::getProgramName (int index)
{
    return {};
}

// ========== Define changeProgramName Method ==========
void StereoToolAudioProcessor::changeProgramName (int index, const String& newName)
{
}

// ========== Define prepareToPlay Method ==========
void StereoToolAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    monoMix = 0;
    buttonState = 0;
}

// ========== Define releaseResources Method ==========
void StereoToolAudioProcessor::releaseResources()
{
}

// ========== Define isBusesLayoutSupported Method ==========
#ifndef JucePlugin_PreferredChannelConfigurations
bool StereoToolAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif




// ==============================================================================
// ========================= Define processBlock Method =========================
// ==============================================================================
void StereoToolAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    
    const float numSamples = buffer.getNumSamples();
    float* const leftChannelDataOut = buffer.getWritePointer(0);
    float* const rightChannelDataOut = buffer.getWritePointer(1);
    
    for (int i = 0; i < numSamples; ++i)
    {
        float leftChannelDataIn = buffer.getReadPointer(0)[i];
        float rightChannelDataIn = buffer.getReadPointer(1)[i];
        float monoDataIn = (leftChannelDataIn + rightChannelDataIn) / 2;
        
        if (buttonState == 0)
        {
            leftChannelDataOut[i] = (1 - monoMix*0.01)*rightChannelDataIn + (monoMix*0.01)*monoDataIn;
            rightChannelDataOut[i] = (1 - monoMix*0.01)*leftChannelDataIn + (monoMix*0.01)*monoDataIn;
        }
        else
        {
            leftChannelDataOut[i] = (1 - monoMix*0.01)*leftChannelDataIn + (monoMix*0.01)*monoDataIn;
            rightChannelDataOut[i] = (1 - monoMix*0.01)*rightChannelDataIn + (monoMix*0.01)*monoDataIn;
        }
    }
}
// ==============================================================================
// ==============================================================================
// ==============================================================================




// ========== Define hasEditor Method ==========
bool StereoToolAudioProcessor::hasEditor() const
{
    return true;
}

// ========== Define createEditor Method ==========
AudioProcessorEditor* StereoToolAudioProcessor::createEditor()
{
    return new StereoToolAudioProcessorEditor (*this);
}

// ========== Define getStateInformation Method ==========
void StereoToolAudioProcessor::getStateInformation (MemoryBlock& destData)
{
}

// ========== Define setStateInformation Method ==========
void StereoToolAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}


// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new StereoToolAudioProcessor();
}


// <----- EOF PluginProcessor.cpp

