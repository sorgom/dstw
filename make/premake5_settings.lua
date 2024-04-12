--  ============================================================
--  common premake5 build settings gcc & VS
--  ============================================================

appIncludes = {
    '../specification',
    '../application',
    '../application/components'
}

testIncludes = {
    '../testing/testenv',
    -- '../devel',
    '../BuildCppUTest/CppUTest/include',
    '../CppUTestSteps/TestSteps/include',
    appIncludes
}

appSrcs = {
    '../application/components/**.cpp'
}

testEnvSrcs = {
    '../testing/testenv/**.cpp',
    '../CppUTestSteps/TestSteps/src/*.cpp'
}

testDefines = {
    'CPPUTEST_USE_LONG_LONG=0'
}

appDefines = { 'NDEBUG' }

genDefines = { 
    'NDEBUG', 
    'TEST_NUM_TSW=1000', 
    'TEST_NUM_SIG=1000', 
    'TEST_NUM_LCR=1000', 
    'TEST_NUM_SEG=1000' 
}

modTestSrcs = { '../testing/tests/moduletests/**.cpp' }
sysTestSrcs = { '../testing/tests/systemtests/**.cpp' }
devTestSrcs = { '../testing/tests/devtests/**.cpp' }

genDataSrcs = { 
    '../testing/gendata/genDataMain.cpp', 
    '../testing/testenv/testlib/src/TestLib.cpp'
}

testLinks = { 'CppUTest', 'CppUTestExt' }

CppUTestHome = '../BuildCppUTest/CppUTest/'

