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
    '../devel',
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
    'CPPUTEST_USE_LONG_LONG=0', 
    'TEST_NUM_TSW=11', 
    'TEST_NUM_SIG=10', 
    'TEST_NUM_LCR=9', 
    'TEST_NUM_SEG=22' 
}

appDefines = { 
    'NDEBUG', 
    'TEST_NUM_TSW=5000', 
    'TEST_NUM_SIG=5000', 
    'TEST_NUM_LCR=5000', 
    'TEST_NUM_SEG=5000' 
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

