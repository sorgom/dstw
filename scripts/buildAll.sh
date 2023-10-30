#!/usr/bin/bash
#   ============================================================
#   all build steps
#   - clean everything
#   - generate Makefile
#   - build all versions:
#       - module tests
#       - coverage 
#   ============================================================
#   created by Manfred Sorgo

mydir=$(dirname $0)
$mydir/cleanTests.sh

cd $mydir/../testing
premake5 gmake2
make -f coverage.make $@
make -f dstw.make $@
make -f tests.make $@
