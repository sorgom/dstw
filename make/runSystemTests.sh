#!/bin/bash
#   ====================================
#   run real time tests
#   ====================================
#   created by Manfred Sorgo

function appRunning()
{
    runs=$(ps -u | grep dstw_run | grep -v grep | wc -l)
    if test $runs -ne 0; then
        return 0
    fi
    return 1
}

cd $(dirname $0)
ret=0
bins="dstw_gen dstw_run run_tests stop_app"
for bin in $bins; do
    if test ! -f bin/$bin; then 
        echo "bin/$bin not found"
        ret=1
    fi
done

if test $ret -ne 0; then exit $ret; fi

bin/stop_app
sleep 1

#   gen required proj data file
bin/dstw_gen
#   start app in background
bin/dstw_run 1 &
sleep 1
#   run tests and stop app
#   if app started
bin/run_tests -b -v
bin/stop_app

