

#include "PluginProcessor.h"
#include "PluginEditor.h"


// ========== Define Constractor ==========
StereoToolAudioProcessorEditor::StereoToolAudioProcessorEditor (StereoToolAudioProcessor &p)
    : AudioProcessorEditor(&p), processor(p)
{
    // Stereo to Mono Mix Slider
    mixSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    mixSlider.setTextBoxStyle(Slider::TextBoxLeft, true, 35, 20);
    mixSlider.setRange(0.0, 100.0, 1.0);
    mixSlider.setValue(0);
    mixSlider.addListener(this);
    mixSlider.setBounds(100, 92, 260, 30);
    addAndMakeVisible (mixSlider);
    
    // set plugin's UI window size
    AudioProcessorEditor::setSize (400, 200);
    
    // stereo image flip buttons
    addAndMakeVisible(stereoFlip);
    stereoFlip.setBounds(158, 130, 30, 30);
    //stereoFlip.addListener(this);
}


// ========== Define Deconstractor ==========
StereoToolAudioProcessorEditor::~StereoToolAudioProcessorEditor()
{
}


// ========== Define paint Method ==========
void StereoToolAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    // add title
    {
        int x = 109, y = 20, width = 184, height = 32;
        String text (TRANS("Stereo Tool"));
        Colour fillColour = Colour(71, 163, 198);
        g.setColour (fillColour);
        g.setFont (Font (18.80f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height, Justification::centred, true);
    }
    
    // add description
    {
        int x = 56, y = 45, width = 288, height = 32;
        String text (TRANS("Stereo Image Flip & Stereo to Mono Mix"));
        Colour fillColour = Colour(71, 163, 198);
        g.setColour (fillColour);
        g.setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height, Justification::centred, true);
    }
    
    // add label for the slider
    {
        int x = 22, y = 92, width = 100, height = 30;
        String text (TRANS("Mix (%)"));
        Colour fillColour = Colour(24, 31, 34);
        g.setColour (fillColour);
        g.setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height, Justification::centred, true);
    }
    
    // add label for the button
    {
        int x = 48, y = 130, width = 110, height = 30;
        String text (TRANS("Stereo image flip"));
        Colour fillColour = Colour(24, 31, 34);
        g.setColour (fillColour);
        g.setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height, Justification::centred, true);
    }
    
    // add info for the Plug-In
    {
        int x = 200, y = 180, width = 530, height = 11;
        String text (TRANS("Ver: ") + JucePlugin_VersionString + BUILD_VER_SUFFIX + TRANS(", Build Date: ") + __DATE__ + TRANS(" "));
        Colour fillColour = Colours::white;
        g.setColour (fillColour);
        g.setFont(Font(11.00f, Font::plain));
        g.drawText(text, x, y, width, height, Justification::centredLeft, true);
    }
}


// ========== Define resized Method ==========
void StereoToolAudioProcessorEditor::resized()
{
}


// ========== Define sliderValueChanged Method ==========
void StereoToolAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if (slider == &mixSlider)
    {
        processor.monoMix = mixSlider.getValue();
    }
}


// ========== Define updateToggleState Method ==========
void StereoToolAudioProcessorEditor::buttonToggled (Button* button)
{
    if (button == &stereoFlip)
    {
        processor.buttonState = button->getToggleState();
    }
}


// <----- EOF PluginEditor.cpp

