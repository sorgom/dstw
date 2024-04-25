--  ============================================================
--  common premake5 build settings gcc & VS
--  ============================================================

base_cpputest = '../cpputest'

includedirs_cpputest = {
    base_cpputest .. '/include'
}

base_teststeps = '../CppUTestSteps/TestSteps'

includedirs_teststeps = {
    base_teststeps .. '/include'
}

files_teststeps = {
    base_teststeps .. '/src/*.cpp'
}

includedirs_app = {
    '../specification',
    '../application/components'
}

includedirs_test = {
    '../testing/testenv',
    base_cpputest .. '/include',
    includedirs_teststeps,
    includedirs_app
}

files_app = {
    '../application/components/**.cpp'
}

files_app_main = {
    '../application/main/*.cpp'
}

files_testenv = {
    '../testing/testenv/**.cpp',
    files_teststeps
}

defines_test = {
    'CPPUTEST_USE_LONG_LONG=0'
}

defines_app = { 'NDEBUG' }

defines_gendata = { 
    'NDEBUG', 
    'TEST_NUM_TSW=1001', 
    'TEST_NUM_SIG=1002', 
    'TEST_NUM_LCR=1003', 
    'TEST_NUM_SEG=1004' 
}

files_moduletest = { '../testing/tests/moduletests/**.cpp' }
files_systest = { '../testing/tests/systemtests/**.cpp' }
files_devtest = { '../testing/tests/devtests/**.cpp' }

files_gendata = { 
    '../testing/gendata/genDataMain.cpp', 
    '../testing/testenv/testlib/src/TestLib.cpp'
}

links_test_gcc = { 'cppu_test' }

files_cpputest = {
    base_cpputest .. '/src/CppUTest/*.cpp',
    base_cpputest .. '/src/CppUTestExt/*.cpp'
}

files_cpputest_vs = {
    files_cpputest,
    base_cpputest .. '/src/Platforms/VisualCpp/*.cpp'
}

files_cpputest_gcc = {
    files_cpputest,
    base_cpputest .. '/src/Platforms/Gcc/*.cpp'
}

linkoptions_test_gcc = { '-pthread' }