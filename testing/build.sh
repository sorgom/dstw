#!/usr/bin/bash

basedir=$(dirname $0)

cd $basedir

rm -rf build bin Makefile *.make
premake5 gmake2
make
