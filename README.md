## "StereoTool VST Plugin"
In this repository I include all project files and builds of my first VST Plug-In.
I used the JUCE library for the plugin development.
This is a simple plugin that I coded in order to start learning the JUCE library.


## How to use
You will need to download and set up the [JUCE library and Projucer software](https://shop.juce.com/get-juce/download).
Then download and set up [Steinberg's VST3_SDK](https://www.steinberg.net/en/company/developers.html) into JUCE.

In order to just use the plug-in, simply copy the pre-build VST file from the "Builds" folder to your DAW plug-ins folder. For MacOS users, copy the pre-build VST file to this path "~/Library/Audio/Plug-Ins/VST".


## Description
The plugin swaps the left and right channels of the input audio (Stereo Image Flip).
In addition, you can control the "Stereo to Mono" slider and narrow the stereo image to mono.
