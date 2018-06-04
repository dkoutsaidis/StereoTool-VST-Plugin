

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


#define BUILD_VER_SUFFIX " alpha" // String to be added before the version name on the GUI (e.g. beta, alpha etc..)


// ========== Declare the Plug-In's editor class ==========
class StereoToolAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Slider::Listener//,
                                        //public Button::Listener
{
public:
    // declare constractor and deconstractor
    StereoToolAudioProcessorEditor (StereoToolAudioProcessor &);
    ~StereoToolAudioProcessorEditor();

    // declare default methods
    void paint (Graphics &) override;
    void resized() override;
    
    // declare custom methods
    void sliderValueChanged(Slider *) override;
    void buttonToggled (Button* button);

private:
    // audio processor's listener pointer
    StereoToolAudioProcessor &processor;

    // slider
    Slider mixSlider;
    ToggleButton stereoFlip;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StereoToolAudioProcessorEditor)
};


// <----- EOF PluginEditor.h

