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
    'CAPACITY_TSW=2000', 
    'CAPACITY_SIG=2000', 
    'CAPACITY_LCR=2000', 
    'CAPACITY_SEG=2000' 
}

testSrcs = {
    testEnvSrcs,
    appSrcs,
    '../testing/tests/moduletests/**.cpp',
    '../testing/tests/systemtests/**.cpp'
}

testLinks = { 'CppUTest', 'CppUTestExt' }

CppUTestHome = '../BuildCppUTest/CppUTest/'

