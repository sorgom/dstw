#!/bin/bash
#   created by Manfred Sorgo

help()
{
    version
    echo "===================================="
    echo "static code analysis using cppcheck"
    echo "check:"
    echo "-a  application"
    echo "-e  test env"
    echo "-t  tests"
    echo "-v  version of cppcheck"
    echo "===================================="
    exit
}

APP_INCS="-I../specification
    -I../application/components
    -I../application"

TEST_INCS="-I../testing/testenv
    $APP_INCS 
    -I../devel
    -I../BuildCppUTest/CppUTest/include
    -I../CppUTestSteps/TestSteps/include"

APP_CALL="cppcheck -q -j 200 --language=c++ --check-level=exhaustive"
TST_CALL="cppcheck -q -j 200 --language=c++ --check-level=exhaustive --force --inline-suppr"

pids=()

done=
version()
{
    if test -z $done; then cppcheck --version; done=1; fi
}

check_app()
{
    version
    echo - application
    $APP_CALL \
        $APP_INCS \
        ../application/components/*/src/*.cpp \
        ../application/components/*/*.h & pids+=($!)
}

check_testenv()
{
    version
    echo - testenv
    $TST_CALL \
        $TEST_INCS \
        ../testing/testenv/*/src/*.cpp \
        ../testing/testenv/*/*.h & pids+=($!)
}

check_tests()
{
    version
    echo - tests
    $TST_CALL \
        $TEST_INCS \
        ../testing/tests/*/*/*.cpp \
        ../testing/tests/*/*.cpp & pids+=($!)
}

ca=
ce=
ct=

while getopts aethv option; do
    case $option in
      (h)  help;;
      (v)  version; exit;;
      (a)  ca=1;;
      (e)  ce=1;;
      (t)  ct=1;;
    esac
done

if test ! -z $ca; then check_app; fi
if test ! -z $ce; then check_testenv; fi
if test ! -z $ct; then check_tests; fi
if test -z $done; then check_app; fi

err=0
for pid in ${pids[*]}; do
    if ! wait $pid; then err=1; fi
done
exit $err