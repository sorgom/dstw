#!/usr/bin/bash
#   ============================================================
#   re-build Makefiles
#   ============================================================
#   created by Manfred Sorgo

mydir=$(dirname $0)

cd $mydir/../testing
rm -f *.make
premake5 gmake2
