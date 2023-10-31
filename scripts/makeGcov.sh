#!/usr/bin/bash
#   ============================================================
#   build coverage tests from Makefile
#   - see also projectGcov.py
#   ============================================================
#   created by Manfred Sorgo

cd $(dirname $0)
. dirs.rc
cd $makeDir
rm -f *.gcov
make -f coverage.make $@
