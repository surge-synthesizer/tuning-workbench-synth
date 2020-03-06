#!/bin/bash

if [ -z $VST2SDK_DIR ]; then
    echo "VST2SDK_DIR is not set. Please point it to a directory containing the VST2 SDK"
    exit 1
else
   sed -e 's/buildVST3,b/buildVST,b/' tuning-workbench-synth.jucer | \
	sed -e "s@VST2SDK_DIR@${VST2SDK_DIR}@" | \
	sed -e 's/PLUGINHOST_VST="0"/PLUGINHOST_VST="1"/' | \
	sed -e 's/buildVST="0"/buildVST="1"/' > tuning-workbench-synth-vst2.jucer
   mv tuning-workbench-synth.jucer tuning-workbench-synth-orig.jucer
   mv tuning-workbench-synth-vst2.jucer tuning-workbench-synth.jucer
   assets/JUCE/Projucer.app/Contents/MacOS/Projucer --resave tuning-workbench-synth.jucer
   mv tuning-workbench-synth-orig.jucer tuning-workbench-synth.jucer
fi

