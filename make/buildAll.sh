#!/bin/bash

help()
{
    echo "===================================="
    echo "build all major makes parallelly"
    echo "options:"
    echo "-c  clean ignored artifacts before"
    echo "-p  premake5 makefiles"
    echo "-x  execute all binaries"
    echo "-s  build sequencially"
    echo "-h  this help"
    echo "===================================="
    exit
}

ecode=0

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
exe=
pre=
seq=
while getopts hcxps option; do
    case $option in
      (h)  help;;
      (c)  clean=1;;
      (x)  exe=1;;
      (p)  pre=1;;
      (s)  seq=1;;
    esac
done

cd $(dirname $0)

if test ! -z $clean; then git clean -dfx .; fi

if test ! -z $pre; then premake5 gmake2; fi

pids=()
st=$(date +%s)
for fn in $(ls *.make | grep -v '_'); do
    if test -z $seq
    then
        mk $fn & pids+=($!)
    else 
        mk $fn
        if test $? -ne 0; then ecode=1; fi
    fi
done

for pid in ${pids[*]}; do
    if ! wait $pid; then ecode=1; fi
done
echo ecode $ecode
tm "DONE" $st

if test -z $exe; then exit $ecode; fi

for b in bin/*; do
    echo ''
    echo "====== $b"
    $b -b
    echo 'return:' $?
    if test $? -ne 0; then ecode=2; fi
done

exit $ecode