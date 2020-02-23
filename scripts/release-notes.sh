#!/bin/bash

cat <<- EOH
# Automated build of surge-synth-team tuning-workbench-synth

ALPHA SOFTWARE. GO AWAY UNLESS YOU HAVE CHATTED ON OUR SLACK!

EOH
date
echo ""
echo "Most recent commits:" 
echo ""
git log --pretty=oneline | head -5
