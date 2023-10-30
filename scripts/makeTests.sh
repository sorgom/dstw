#!/usr/bin/bash
#   ============================================================
#   build module tests from Makefile
#   - see also runTests.sh
#   ============================================================
#   created by Manfred Sorgo

mydir=$(dirname $0)

cd $mydir/../testing
make -f tests.make $@
