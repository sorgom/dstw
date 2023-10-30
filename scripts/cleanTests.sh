#!/usr/bin/bash
#   ============================================================
#   clean all build artifacts
#   ============================================================
#   created by Manfred Sorgo

mydir=$(dirname $0)
cd $mydir/../testing
rm -rf obj bin lib Makefile *.gcov report.txt
