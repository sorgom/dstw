--  ============================================================
--  premake5 build settings
--  ============================================================

buildoptions_gcc = '-std=c++17 -pedantic-errors -Werror -Wall'

buildoptions_vs = '/std:c++17 /MP'
buildoptions_vs_app = buildoptions_vs .. ' /W4 /wd4100 /wd4103'
buildoptions_vs_test = buildoptions_vs_app .. ' /wd4127 /D_WINSOCK_DEPRECATED_NO_WARNINGS'
buildoptions_vs_cpputest = buildoptions_vs_app .. ' /DCPPUTEST_MEM_LEAK_DETECTION_DISABLED'

base_cpputest = '../submodules/cpputest'
includedirs_cpputest = { base_cpputest .. '/include' }
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


base_teststeps = '../submodules/CppUTestSteps/TestSteps'
includedirs_teststeps = { base_teststeps .. '/include' }
files_teststeps = { base_teststeps .. '/src/*.cpp' }

includedirs_app = {
    '../specification',
    '../application/components'
}
files_app = {
    '../application/components/**.cpp'
}
files_app_main = {
    '../application/main/*.cpp'
}

includedirs_testenv = { '../testing/testenv' }
files_testenv = {
    '../testing/testenv/**.cpp',
    files_teststeps
}

includedirs_test = {
    includedirs_testenv,
    includedirs_cpputest,
    includedirs_teststeps,
    includedirs_app
}
defines_test = { 'CPPUTEST_USE_LONG_LONG=0' }


files_moduletest = { '../testing/tests/moduletests/**.cpp' }
files_systemtest  = { '../testing/tests/systemtests/SYST_*.cpp' }
files_devtest  = { '../testing/tests/devtests/*.cpp' }
files_dstw_stop  = { 
    '../testing/tests/systemtests/stopAppMain.cpp',
    '../testing/testenv/TCP/src/TCP_Client.cpp'
}
files_gendata = { 
    '../testing/gendata/genDataMain.cpp', 
    '../testing/testenv/testlib/src/TestLib.cpp'
}
