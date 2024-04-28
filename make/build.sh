#!/bin/bash

help()
{
    echo "Usage: $(basename $0) [options]"
    echo "build all major makes parallelly"
    echo "options:"
    echo "-c  clean ignored artifacts before"
    echo "-p  premake5 makefiles"
    echo "-r  run all binaries"
    echo "-h  this help"
    exit
}

function tm()
{
    en=$(date +%s)
    printf "%-25s[%3d]\n" $1 $(($en-$2))
}

function mk()
{
    st=$(date +%s)
    make -j -f $1 > /dev/null
    if test $? -ne 0; then return 1; fi
    tm ${1%.*} $st
    return 0
}

clean=
run=
pre=
while getopts hcrp option; do
    case $option in
      (h)  help;;
      (c)  clean=1;;
      (r)  run=1;;
      (p)  pre=1;;
    esac
done

cd $(dirname $0)

if test ! -z $clean; then git clean -dfXq .; fi

if test ! -z $pre; then premake5 gmake2; fi

echo build ...
err=0
pids=()
for fn in lib_*.make; do
    mk $fn & pids+=($!)
done
for pid in ${pids[*]}; do
    if ! wait $pid; then err=1; fi
done

pids=()
for fn in $(ls *.make | grep -v '_'); do
    mk $fn & pids+=($!)
done
for pid in ${pids[*]}; do
    if ! wait $pid; then err=1; fi
done

if test $err -ne 0; then exit 1; fi

if test -z $run; then exit 0; fi

for b in bin/*; do
    echo ''
    echo "====== $b"
    $b
    x=$?
    echo 'returned' $x
    if test $x -ne 0; then err=1; fi
done

exit $err