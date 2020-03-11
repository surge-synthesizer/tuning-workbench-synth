#!/bin/sh

GIT_TAG=`git rev-parse --short HEAD`
BUILDDATE=`date +%Y%m%d`
VERSION="beta-${GIT_TAG}-${BUILDDATE}"
echo "Setting vrsion to '$VERSION'"

sed -e "s/#define TWS_VERSION .*/#define TWS_VERSION \"${VERSION}\"/" Source/Constants.h > Source/Constants_versioned.h
mv Source/Constants_versioned.h Source/Constants.h
