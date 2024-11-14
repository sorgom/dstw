#!/bin/bash
#   ====================================
#   build and run all tests and app
#   ====================================
cd $(dirname $0)
myDir=$(pwd)
cd ..
buildDir=$(pwd)/build
bindir=$buildDir/linux/bin

cd $myDir
make -j

cd $buildDir
tot=0
for bin in $bindir/*; do
echo ==== $(basename $bin)
$bin
tot=$((tot+$?))
done
exit $tot
