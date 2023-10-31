#!/usr/bin/bash
#   ============================================================
#   build dstw application from Makefile
#   ============================================================
#   created by Manfred Sorgo

cd $(dirname $0)
. dirs.rc
cd $makeDir
make -f dstw.make $@
