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
ret=$?
echo return: $ret
tot=$((tot+ret))
done
if test $tot -eq 0; then echo OK; fi
exit $tot
