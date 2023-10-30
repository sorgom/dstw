#!/usr/bin/bash
#   ============================================================
#   build application from Makefile
#   ============================================================
#   created by Manfred Sorgo

mydir=$(dirname $0)

cd $mydir/../testing
make -f dstw.make $@
