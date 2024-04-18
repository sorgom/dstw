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
--  app and tests at once runtime
--  ->  bin/tests_{config}
--  configurations: 
--  - ci        module tests
--  - qnd       module tests with devel includes
--  - dev       developer tests
--  - bullseye  module tests with bullseye coverage
--  - none      no tests
--  ============================================================
workspace 'tests'
    filter { 'action:gmake*' }
        configurations { 'ci', 'qnd', 'dev', 'bullseye', 'tmp' }
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
                files { modTestSrcs }

            filter { 'configurations:qnd' }
                files { modTestSrcs }
                includedirs { '../devel' }

            filter { 'configurations:dev' }
                files { devTestSrcs }

            filter { 'configurations:bullseye' }
                files { modTestSrcs }
                prebuildcommands { 'cov01 -1 --no-banner' }
                postbuildcommands { './bullseye.sh' }
            filter { 'configurations:tmp' }
                includedirs { '../devel' }
                files {
                }
    
--  ============================================================
--  > coverage.make
--  -   coverage instrumented application (static lib)
--  -   module tests only runtime
--  ->  bin/coverage_tests_{config}
--  configurations: 
--  - ci        module tests
--  - dev       developer tests
--  ============================================================
workspace 'coverage'
    filter { 'action:gmake*' }
        configurations { 'ci', 'dev' }
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
            filter { 'configurations:dev' }
                files { devTestSrcs }

--  ============================================================
--  > systests.make
--  -   application without test includes (static lib)
--  -   system tests only runtime
--  ->  bin/sysests_tests_{config}
--  configurations: 
--  - ci        module tests
--  - qnd       with devel includes
--  ============================================================
workspace 'systests'
    filter { 'action:gmake*' }
        configurations { 'ci', 'qnd' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'
        targetsuffix '_%{cfg.name}'

        buildoptions { buildOpts }

        defines { 'DEBUG', testDefines }
        symbols 'On'

        filter { 'configurations:qnd' }
            includedirs { '../devel' }

        project 'systests_app'
            kind 'StaticLib'
            targetdir 'lib'
            files { appSrcs }
            includedirs { appIncludes }
            removefiles { noSysTestSrcs_app }

        project 'systests_tests'
            kind 'ConsoleApp'
            targetdir 'bin'
            libdirs { 'lib', '../BuildCppUTest/lib' }
            links { 'systests_app_%{cfg.name}', testLinks }
            files { testEnvSrcs, sysTestSrcs }
            removefiles { noSysTestSrcs_tests }
            includedirs { testIncludes }
