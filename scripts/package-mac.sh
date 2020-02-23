#!/bin/sh

GIT_TAG=`git rev-parse --short HEAD`
BUILDDATE=`date +%Y%m%d`
VERSION="${GIT_TAG}-${BUILDDATE}"

rm -rf Builds/MacOSX/tuning-workbench-synth-Nightly
rm -rf *dmg
mkdir -p Builds/MacOSX/tuning-workbench-synth-Nightly

mkdir -p products/

cd Builds/MacOSX/build/Release
tar cf - tuning-workbench-synth.component/* | ( cd ../../tuning-workbench-synth-nightly ; tar xf - )
tar cf - tuning-workbench-synth.vst3/* | ( cd ../../tuning-workbench-synth-nightly ; tar xf - )
tar cf - tuning-workbench-synth.app/* | ( cd ../../tuning-workbench-synth-nightly ; tar xf - )
cd ../../../..

hdiutil create products/tuning-workbench-synth_macOS_${VERSION}.dmg -ov -volname "tuning-workbench-synth_${VERSION}" -fs HFS+ -srcfolder Builds/MacOSX/tuning-workbench-synth-nightly/

