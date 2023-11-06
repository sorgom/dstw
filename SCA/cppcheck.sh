#!/bin/bash
#   ============================================================
#   static code analysis using cppcheck
#   check always:
#   -   application
#   check optionally:
#   -   test env
#   -   tests
#   ============================================================
#   created by Manfred Sorgo

APP_INCS="-I../specification
    -I../application/components
    -I../application"

TEST_INCS="-I../testing/testenv
    "$APP_INCS" 
    -I../devel
    -I../BuildCppUTest/include
    -I../CppUTestSteps/TestSteps/include"

APP_CALL="cppcheck -q --language=c++ --check-level=exhaustive"
TST_CALL="cppcheck -q --language=c++ --check-level=exhaustive --force --inline-suppr"

cppcheck --version
echo - application
$APP_CALL \
    $APP_INCS \
    ../application/components/*/src/*.cpp \
    ../application/components/*/*.h

if test $# -eq 0; then exit; fi

echo - testenv
$TST_CALL \
    $TEST_INCS \
    ../testing/testenv/*/src/*.cpp \
    ../testing/testenv/*/*.h

if test $# -eq 1; then exit; fi

echo - tests
$TST_CALL \
    $TEST_INCS \
    ../testing/tests/*/*/*.cpp \
    ../testing/tests/*/*.cpp
