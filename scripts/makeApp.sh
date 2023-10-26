#!/usr/bin/bash
#   ============================================================
#   build application library from Makefile
#   ============================================================
#   created by Manfred Sorgo

mydir=$(dirname $0)

cd $mydir/../testing
make verbose=$1 application_lib
