#!/bin/bash
#   ====================================
#   run system tests
#   ====================================
#   created by Manfred Sorgo

cd $(dirname $0)
ret=0
bins="dstw_gen dstw_run systemtests_run systemtests_stop"
for bin in $bins; do
    if test ! -f bin/$bin; then 
        echo "bin/$bin not found"
        ret+=(1)
    fi
done

if test $ret -ne 0; then exit $ret; fi

bin/systemtests_stop
sleep 1

#   gen required proj data file
bin/dstw_gen
#   start app in background
bin/dstw_run 1 &
sleep 1
#   run tests
bin/systemtests_run -b -v
ret=$?
#   stop app
bin/systemtests_stop

exit $ret
