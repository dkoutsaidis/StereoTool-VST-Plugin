/*

"StereoToolEditor" class definition.

This class controls the plugins GUI.
Child class of the "AudioProcessor" class.

Date: 29/03/2017
Plugin Name: Stereo Tool
Author: Dimitris Koutsaidis

to do:
	- better graphics..
	- best control over slider..

*/


class StereoToolEditor : public AudioProcessorEditor
{
public:
    enum
    {
        paramControlHeight = 40,
        paramLabelWidth    = 150,
        paramSliderWidth   = 300
    };

    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    
	StereoToolEditor(AudioProcessor& parent, AudioProcessorValueTreeState& vts) : AudioProcessorEditor(parent), valueTreeState(vts)
    {
		gainLabel.setText("Stereo to Mono Mix (%)", dontSendNotification);
        addAndMakeVisible (gainLabel);
        
        addAndMakeVisible (gainSlider);
		gainAttachment = new SliderAttachment(valueTreeState, "monoMix", gainSlider);
        
        setSize (paramSliderWidth + paramLabelWidth, paramControlHeight * 2);
    }

	~StereoToolEditor() {}

    void resized() override
    {
        Rectangle<int> r = getLocalBounds();
        {
            Rectangle<int> gainRect = r.removeFromTop (paramControlHeight);
            gainLabel.setBounds (gainRect.removeFromLeft (paramLabelWidth));
            gainSlider.setBounds (gainRect);
        }
    }

    void paint (Graphics& g) override
    {
        g.setColour (Colours::white);
        g.fillRect (getLocalBounds());
    }
    
private:
    AudioProcessorValueTreeState& valueTreeState;
    
    Label gainLabel;
    Slider gainSlider;
    ScopedPointer<SliderAttachment> gainAttachment;
};