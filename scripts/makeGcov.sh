#!/usr/bin/bash
#   ============================================================
#   build coverage tests from Makefile
#   - see also projectGcov.py
#   ============================================================
#   created by Manfred Sorgo

mydir=$(dirname $0)

cd $mydir/../testing
rm -f *.gcov
make -f Coverage.make $@
