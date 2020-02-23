#!/bin/sh

GIT_TAG=`git rev-parse --short HEAD`
BUILDDATE=`date +%Y%m%d`
VERSION="${GIT_TAG}-${BUILDDATE}"
UN=`uname -a`

rm -rf Builds/Linux/tuning-workbench-synth-Nightly
mkdir -p Builds/Linux/tuning-workbench-synth-Nightly

mkdir -p products/

cd Builds/Linux/build/
cp tuning-workbench-synth tuning-workbench-synth.a ../tuning-workbench-synth-Nightly
cd ..

cat <<EOF > tuning-workbench-synth-Nightly/BuildInfo.txt
Build in azure pipeline
$VERSION
$UN

EOF

md5sum tuning-workbench-synth-Nightly/tuning-workbench-synth* >> tuning-workbench-synth-Nightly/BuildInfo.txt

cat tuning-workbench-synth-Nightly/BuildInfo.txt

pwd
tar cvzf ../../products/tuning-workbench-synth_ubuntu_linux_${VERSION}.tgz tuning-workbench-synth-Nightly

