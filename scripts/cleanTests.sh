#!/usr/bin/bash
#   ============================================================
#   clean all build artifacts
#   ============================================================
#   created by Manfred Sorgo

cd $(dirname $0)
. dirs.rc
cd $makeDir
rm -rf obj bin lib Makefile *.gcov report.txt
