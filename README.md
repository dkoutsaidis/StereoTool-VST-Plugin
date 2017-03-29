## "StereoTool VST Plugin"
In this repository i include all project files and builds of my first plugin.
I used JUCE for the plugin development.
This is a simple plugin that i coded in order to learn and get used to JUCE platform.


## How to use
In order to see and edit the code download and set up JUCE. Then download and set up Steinberg SDK into JUCE.
From JUCE you can control your project and its properties, develop the code for the audio processing and the GUI of the plugin and create different export targets.

In order to just use the plugin, simply copy any of the ".dll" files from the "Builds" folder to your DAW plugins folder.


## Description
The plugin swaps the left and right channels of the input audio (Stereo Image Flip).
Also you can control the "Stereo to Mono" slider and narrow the stereo image down to 2 channel mono.