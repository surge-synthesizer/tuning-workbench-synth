# Tuning Workbench Synth

Tuning Workbench Synth is a synthesizer for learning and experimenting with microtonal scales. For motivation and
documentation please see [the surge synth team TWS landing page](https://surge-synth-team.org/tuning-workbench-synth/).

This is the developer documentation. Currently we are in an early beta. Some features are still not implemented,
but the ones which are work well.

We distribute a built version of the codebase for mac windows and linux [here](https://github.com/surge-synthesizer/tuning-workbench-synth/releases/tag/Nightly)

If you find a bug or want to make a change, please open a github issue or join our slack.

# How to Build 

We follow the protocol of downloading JUCE and building our own JUCE output files in every build. This is accomplised by a 
small set of scripts in the scripts/ directory which are also run in our CI pipeline.

## macOS

```
git submodule update --init --recursive
scripts/get-juce.sh
scripts/projuce-mac.sh
scripts/build-mac.sh
```

This will generate the standalone and generate and locally install the VST3 and AU

## windows

in a bash-like environment

```
git submodule update --init --recursive
scripts/get-juce.sh
assets/JUCE/projucer.exe --resave tuning-workbench-synth.jucer
```

then open the msbuild file

## linux

```
git submodule update --init --recursive
scripts/get-juce.sh
scripts/projuce-lin.sh
scripts/build-lin.sh
```

If you want the VST2 and have the SDK

```
export VST2SDK_DIR=~/Location/Of/SDK
scripts/projuce-lin-vst2.sh
scripts/build-lin.sh
```

You will need to install the VST2 in the location appropriate for your system.

