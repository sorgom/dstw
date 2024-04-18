--  ============================================================
--  premake5 build rules for gcc (gmake2):
--  ============================================================

include 'premake5_settings.lua'
buildOpts = { '-std=c++17 -pedantic-errors -Werror -Wall' }

--  ============================================================
--  > dstw.make
--  data generator and application runtime
--  ============================================================
workspace 'dstw'
    filter { 'action:gmake*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'
        targetdir 'bin'
        buildoptions { buildOpts }
        optimize 'On'

        project 'dstw_gen'
            kind 'ConsoleApp'
            includedirs { testIncludes }
            defines { genDefines }
            files { genDataSrcs }

        project 'dstw_run'
            kind 'ConsoleApp'
            includedirs { appIncludes }
            defines { appDefines }
            files { '../application/**.cpp' }

--  ============================================================
--  > tests.make
--  module tests and system tests at once runtime
--  ->  bin/tests_{config}
--  configurations: 
--  - ci        module and system tests
--  - qnd       module and system tests with devel includes
--  - mod       module tests
--  - sys       system tests
--  - dev       developer tests
--  - bullseye  module tests with bullseye coverage
--  - none      no tests
--  ============================================================
workspace 'tests'
    filter { 'action:gmake*' }
        configurations { 'ci', 'qnd', 'mod', 'sys', 'dev', 'bullseye', 'tmp' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}/%{cfg.name}'
        targetsuffix '_%{cfg.name}'

        buildoptions { buildOpts }

        project 'tests'
            kind 'ConsoleApp'
            defines { 'NDEBUG', testDefines }
            targetdir 'bin'
            libdirs { '../BuildCppUTest/lib' }
            includedirs { testIncludes }
            links { testLinks }
            files { testEnvSrcs, appSrcs }
            removefiles { noTestSrcs }

            filter { 'configurations:ci' }
                files { modTestSrcs, sysTestSrcs }

            filter { 'configurations:qnd' }
                files { modTestSrcs, sysTestSrcs }
                includedirs { '../devel' }

            filter { 'configurations:mod' }
                files { modTestSrcs }

            filter { 'configurations:sys' }
                files { sysTestSrcs }

            filter { 'configurations:dev' }
                files { devTestSrcs }

            filter { 'configurations:bullseye' }
                files { modTestSrcs }
                prebuildcommands { 'cov01 -1 --no-banner' }
                postbuildcommands { './bullseye.sh' }
            filter { 'configurations:tmp' }
                includedirs { '../devel' }
                files {
                    -- '../testing/tests/moduletests/BAS/BAS_01.cpp',
                    -- '../testing/tests/moduletests/BAS/BAS_02.cpp',  
                    -- '../testing/tests/moduletests/SYS/SYS_01.cpp',
                    -- '../testing/tests/moduletests/SYS/SYS_02.cpp',
                    -- '../testing/tests/moduletests/SYS/SYS_03.cpp',
                    -- '../testing/tests/devtests/DT_01.cpp',
                    '../testing/tests/moduletests/SIG/SIG_01.cpp',
                }
    
--  ============================================================
--  > coverage.make
--  -   coverage instrumented application (static lib)
--  -   module tests only runtime
--  ->  bin/coverage_tests_{config}
--  configurations: 
--  - ci        module tests
--  - sys       system tests
--  - dev       developer tests
--  ============================================================
workspace 'coverage'
    filter { 'action:gmake*' }
        configurations { 'ci', 'sys', 'dev' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'
        targetsuffix '_%{cfg.name}'

        includedirs { testIncludes }
        buildoptions { buildOpts }

        defines { 'DEBUG', testDefines }
        symbols 'On'

        project 'coverage_app'
            kind 'StaticLib'
            targetdir 'lib'
            files { appSrcs }
            removefiles { noTestSrcs }
            buildoptions {'-fprofile-arcs -ftest-coverage'}

        project 'coverage_tests'
            kind 'ConsoleApp'
            targetdir 'bin'
            libdirs { 'lib', '../BuildCppUTest/lib' }
            links { 'coverage_app', 'gcov', testLinks }
            linkoptions { '--coverage' }
            files { testEnvSrcs }
            filter { 'configurations:ci' }
                files { modTestSrcs }
            filter { 'configurations:sys' }
                files { sysTestSrcs }
            filter { 'configurations:dev' }
                files { devTestSrcs }
