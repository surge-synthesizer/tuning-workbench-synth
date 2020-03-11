#!/bin/bash

cat <<- EOH
# Automated build of surge-synth-team tuning-workbench-synth

The tuning-workbench-synth is currently in a beta stage, ready for
general testing from people who are OK runnign beta music software.

For more information see https://surge-synth-team.org/tuning-workbench-synth/

EOH
date
echo ""
echo "Most recent commits:" 
echo ""
git log --pretty=oneline | head -5
