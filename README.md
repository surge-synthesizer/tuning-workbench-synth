# SUPER ALPHA

This is super alpha

If you aren't chatting with the team on slack right now, you probably want to come back in a week.

# How to Build

hop on slack if you get stuck

## macOS

```
git submodule update --init --recursive
scripts/get-juce.sh
scripts/projuce-mac.sh
scripts/build-mac.sh
```

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

