#!/usr/bin/bash
#   ============================================================
#   re-build Makefiles
#   ============================================================
#   created by Manfred Sorgo

cd $(dirname $0)
. dirs.rc
cd $makeDir
rm -f *.make
premake5 gmake2
