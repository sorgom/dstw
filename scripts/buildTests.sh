#!/usr/bin/bash

mydir=$(dirname $0)
$mydir/cleanTests.sh

cd $mydir/../testing
premake5 gmake2
make verbose=$1
