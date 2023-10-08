#!/usr/bin/bash

basedir=$(dirname $0)

cd $basedir

./cleanup.sh
premake5 gmake2
make verbose=1
