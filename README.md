# Tuning Workbench Synth

Tuning Workbench Synth is a synthesizer for learning and experimenting with microtonal scales. For motivation and
documentation please see [the surge synth team TWS landing page](https://surge-synth-team.org/tuning-workbench-synth/).

This is the developer documentation. Currently we are in an early beta. Some features are still not implemented,
but the ones which are work well.

We distribute a built version of the codebase for mac windows and linux [here](https://github.com/surge-synthesizer/tuning-workbench-synth/releases/tag/Nightly)

If you find a bug or want to make a change, please open a github issue or join our slack.

# How to Build 

We have upgraded to JUCE6 and now use Cmake to build. This means the build instructions on all platforms are the same

```
git clone https://github.com/surge-synthesizer/tuning-workbench-synth.git   # or your fork obviously
cd tuning-workbench-synth
git submodule update --init --recursive
cmake -Bbuild     # macos users may want cmake -Bbuild -GXcode if they want an xcode file
cmake --build build --config Release 
```

and you should get your build working. That's it. Cool eh?

Of course cmake will create IDE assets in a normal way if you want them. They will all appear in the build directory.
