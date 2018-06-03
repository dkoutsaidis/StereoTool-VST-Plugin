## "StereoTool VST Plugin"
In this repository I include all project files and builds of my first VST Plug-In.
I used the JUCE library for the plugin development.
This is a simple plugin that I coded in order to learn and get used to JUCE.


## How to use
You will need to download and set up the JUCE library and Projucer software.
Then download and set up Steinberg SDK into JUCE VST path.

In order to just use the plugin, simply copy any of the ".dll" files (debug/x32/x64) from the "Builds" folder to your DAW plugins folder.


## Description
The plugin swaps the left and right channels of the input audio (Stereo Image Flip).
In addition, you can control the "Stereo to Mono" slider and narrow the stereo image to mono.
