#!/usr/bin/bash
#   ============================================================
#   build module tests from Makefile
#   - see also runTests.sh
#   ============================================================
#   created by Manfred Sorgo

cd $(dirname $0)
. dirs.rc
cd $makeDir
make -f tests.make $@
