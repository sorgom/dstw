#!/usr/bin/bash

mydir=$(dirname $0)
cd $mydir/../testing
rm -rf obj bin lib Makefile *.make *.gcov report.txt
