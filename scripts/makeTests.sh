#!/usr/bin/bash

mydir=$(dirname $0)

cd $mydir/../testing
make verbose=$1 moduletests
