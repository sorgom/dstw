#!/bin/bash
#   ====================================
#   run system tests
#   ====================================
#   created by Manfred Sorgo

cd $(dirname $0)
myDir=$(pwd)
cd ..
buildDir=$(pwd)/build
bindir=linux/bin

cd $myDir
make -j dstw_gen dstw_runtime dstw_stop systemtests

cd $buildDir
ret=0

$bindir/dstw_stop
sleep 1

#   gen required proj data file
$bindir/dstw_gen
#   start app in background
$bindir/dstw_runtime X & pid=$!
#   run tests
$bindir/systemtests -b -v
ret=$((ret+$?))

#   stop app
$bindir/dstw_stop

if ! wait $pid; then
    ret=$((ret+1))
fi
exit $ret
