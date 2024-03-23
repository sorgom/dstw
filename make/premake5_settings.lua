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
    'CAPACITY_TSW=11', 
    'CAPACITY_SIG=10', 
    'CAPACITY_LCR=9', 
    'CAPACITY_SEG=22' 
}

appDefines = { 
    'NDEBUG', 
    'CAPACITY_TSW=5000', 
    'CAPACITY_SIG=5000', 
    'CAPACITY_LCR=5000', 
    'CAPACITY_SEG=5000' 
}

testSrcs = {
    testEnvSrcs,
    appSrcs,
    '../testing/tests/moduletests/**.cpp',
    '../testing/tests/systemtests/**.cpp'
}

genDataSrcs = { 
    '../testing/gendata/genDataMain.cpp', 
    '../testing/testenv/testlib/src/TestLib.cpp',
    '../application/components/BAS/src/HN.cpp'
}

testLinks = { 'CppUTest', 'CppUTestExt' }

CppUTestHome = '../BuildCppUTest/CppUTest/'

