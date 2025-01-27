--  ============================================================
--  premake5 build settings
--  ============================================================

buildoptions_gcc = '-std=c++17 -pedantic-errors -Werror -Wall'

buildoptions_vs = '/std:c++17 /MP'
buildoptions_vs_app = buildoptions_vs .. ' /W4 /wd4100 /wd4103'
buildoptions_vs_test = buildoptions_vs_app .. ' /wd4127 /D_WINSOCK_DEPRECATED_NO_WARNINGS'
buildoptions_vs_cpputest = buildoptions_vs_app .. ' /DCPPUTEST_MEM_LEAK_DETECTION_DISABLED /wd4611 /wd4996'

base_cpputest = '../submodules/cpputest'
includedirs_cpputest = { base_cpputest .. '/include' }

base_teststeps = '../submodules/CppUTestSteps/TestSteps'

includedirs_app = {
    '../specification',
    '../application/components'
}
files_app = { '../application/components/**.cpp'}

includedirs_testenv = { '../testing/testenv' }
files_testenv = {
    '../testing/testenv/**.cpp',
    base_teststeps .. '/src/*.cpp'
}

includedirs_test = {
    includedirs_testenv,
    includedirs_cpputest,
    base_teststeps .. '/include',
    includedirs_app
}
defines_test = { 'CPPUTEST_USE_LONG_LONG=0' }

files_moduletest = { '../testing/tests/moduletests/**.cpp' }

--  ============================================================
--  premake5 build rules
--  ============================================================

workspace 'DSTW'
    configurations { 'ci', 'debug' }
    language 'C++'
    targetdir '../build/%{_TARGET_OS}'
    objdir  '../build/%{_TARGET_OS}/obj'
    kind 'ConsoleApp'
    libdirs { '../build/%{_TARGET_OS}/lib' }

    filter { 'action:vs*' }
        targetdir '../build/%{_TARGET_OS}'
        buildoptions { buildoptions_vs_test }
        links { 'ws2_32' }
        warnings 'high'

    filter { 'action:gmake*' }
        targetdir '../build/%{_TARGET_OS}/bin'
        buildoptions { buildoptions_gcc }
        linkoptions { '-pthread' }

    filter { 'configurations:ci' }
        defines { 'NDEBUG' }

    filter { 'configurations:debug' }
        defines { 'DEBUG' }
        symbols 'On'

    --  ============================================================
    --  cpputest
    --  ============================================================
    project 'cpputest'
        kind 'StaticLib'
        targetdir '../build/%{_TARGET_OS}/lib'
        defines { 'NDEBUG' }

        defines { defines_test, 'CPPUTEST_MEM_LEAK_DETECTION_DISABLED' }
        includedirs { includedirs_cpputest }
        files {
            base_cpputest .. '/src/CppUTest/*.cpp',
            base_cpputest .. '/src/CppUTestExt/*.cpp'
        }

        filter { 'action:vs*' }
            buildoptions { buildoptions_vs_cpputest }
            files { base_cpputest .. '/src/Platforms/VisualCpp/*.cpp' }

        filter { 'action:gmake*' }
            files { base_cpputest .. '/src/Platforms/Gcc/*.cpp' }

    --  ============================================================
    --  module tests / dev tests
    --  ============================================================
    project 'moduletests'
        files { files_app, files_testenv, files_moduletest }
        includedirs { includedirs_test }
        defines { defines_test }
        links { 'cpputest' }

        filter { 'action:vs*' }
        links { 'winmm' }

    project 'devtests'
        files { files_app, files_testenv, '../testing/tests/devtests/*.cpp' }
        includedirs { includedirs_test, '../devel' }
        defines { defines_test }
        links { 'cpputest' }

        filter { 'action:vs*' }
        links { 'winmm' }

    --  ============================================================
    --  system tests
    --  ============================================================
    --  run first
    project 'dstw_gen'
        includedirs { includedirs_test }
        files {
            '../testing/gendata/genDataMain.cpp',
            '../testing/testenv/testlib/src/TestLib.cpp',
            '../testing/testenv/testlib/src/NetTest.cpp'
        }

    --  run second in background
    --  must be unstrumented for coverage
    project 'dstw_runtime'
        files { files_app, '../application/main/*.cpp' }
        includedirs { includedirs_app }

    --  run third
    project 'systemtests'
        files { files_testenv, '../testing/tests/systemtests/SYST_*.cpp' }
        includedirs { includedirs_test }
        defines { defines_test, 'REQUIRE_PARAM' }
        links { 'cpputest' }

        filter { 'action:vs*' }
        links { 'winmm' }


    --  run last to stop application in background
    project 'dstw_stop'
        files {
            '../testing/tests/systemtests/stopAppMain.cpp',
            '../testing/testenv/TCP/src/TCP_Client.cpp'
        }
        includedirs { includedirs_test }

    project 'gcovapp'
        filter { 'action:vs*' }

        filter { 'action:gmake*' }
            kind 'StaticLib'
            targetdir '../build/%{_TARGET_OS}/lib'
            includedirs { includedirs_test }
            files { files_app }
            buildoptions {'-fprofile-arcs -ftest-coverage' }

    project 'gcovtests'
        filter { 'action:vs*' }

        filter { 'action:gmake*' }
            files { files_testenv, files_moduletest }
            includedirs { includedirs_test }
            defines { defines_test }
            links { 'gcovapp', 'gcov', 'cpputest' }
            linkoptions { '--coverage' }
