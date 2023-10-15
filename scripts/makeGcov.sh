#!/usr/bin/bash
#   ============================================================
#   build coverage tests from Makefile
#   - see also projectGcov.py
#   ============================================================
#   created by Manfred Sorgo

mydir=$(dirname $0)

cd $mydir/../testing
make verbose=$1 application_coverage moduletests_coverage
