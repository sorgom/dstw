--  ============================================================
--  premake5 build rules for gcc (gmake2):
--  ============================================================

include 'premake5_settings.lua'
buildoptions_gcc = '-std=c++17 -pedantic-errors -Werror -Wall'

--  ============================================================
--  > lib_cpputest.make
--  cpputest lib
--  configurations: 
--  - ci        
--  - debug     debug mode
--  ============================================================
workspace 'lib_cpputest'
    filter { 'action:gmake*' }
        configurations { 'ci', 'debug' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}/%{cfg.name}'
        defines { defines_test }

        filter { 'configurations:ci' }
            defines { 'NDEBUG' }

        filter { 'configurations:debug' }
            defines { 'DEBUG' }
            symbols 'On'

        project 'cppu_test'
            kind 'StaticLib'
            targetdir 'lib'
            files { files_cpputest_gcc }
            includedirs { includedirs_cpputest }
            buildoptions { buildoptions_gcc .. ' -DCPPUTEST_MEM_LEAK_DETECTION_DISABLED' }

--  ============================================================
--  > tests.make
--  app and tests at once runtime
--  ->  bin/tests_{config}
--  configurations: 
--  - ci        module tests
--  - debug     module tests debug mode
--  - dev       developer tests debug mode
--  - bullseye  module tests with bullseye coverage
--  - tmp       temporary tests
--  ============================================================
workspace 'tests'
    filter { 'action:gmake*' }
        configurations { 'ci', 'debug', 'dev', 'bullseye', 'tmp' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}/%{cfg.name}'
        targetsuffix '_%{cfg.name}'
        buildoptions { buildoptions_gcc }
        linkoptions { linkoptions_test_gcc }

        project 'tests'
            kind 'ConsoleApp'
            defines { defines_test }

            targetdir 'bin'
            libdirs { 'lib' }
            includedirs { includedirs_test }
            links { links_test_gcc }
            files { files_testenv, files_app }

            filter { 'configurations:ci' }
                defines { 'NDEBUG' }
                files { files_moduletest }

            filter { 'configurations:debug' }
                defines { 'DEBUG' }
                symbols 'On'
                files { files_moduletest }

            filter { 'configurations:dev' }
                defines { 'DEBUG' }
                symbols 'On'
                files { files_devtest }

            filter { 'configurations:bullseye' }
                defines { 'NDEBUG' }
                files { files_moduletest }
                prebuildcommands { 'cov01 -1 --no-banner' }
                postbuildcommands { './bullseye.sh' }

            filter { 'configurations:tmp' }
                defines { 'DEBUG' }
                symbols 'On'
                includedirs { includedirs_qnd }
                files {
                    '../testing/tests/moduletests/COM/*.cpp'
                }
    
--  ============================================================
--  > coverage.make
--  -   coverage instrumented application (static lib)
--  -   module tests only runtime
--  ->  bin/coverage_tests_{config}
--  ============================================================
workspace 'coverage'
    filter { 'action:gmake*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'

        includedirs { includedirs_test }
        buildoptions { buildoptions_gcc }

        defines { 'DEBUG', defines_test }
        symbols 'On'

        project 'coverage_app'
            kind 'StaticLib'
            targetdir 'lib'
            files { files_app }
            buildoptions {'-fprofile-arcs -ftest-coverage' }

        project 'coverage_tests'
            kind 'ConsoleApp'
            targetdir 'bin'
            libdirs { 'lib' }
            links { 'coverage_app', 'gcov', links_test_gcc }
            linkoptions { linkoptions_test_gcc, '--coverage' }
            files { files_testenv, files_moduletest }

--  ============================================================
--  > systemtests.make
--  -   run tests only runtime
--  configurations: 
--  - ci        module tests
--  ============================================================
workspace 'systemtests'
    filter { 'action:gmake*' }
        configurations { 'ci', 'debug' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'
        buildoptions { buildoptions_gcc }

        defines { defines_test }

        filter { 'configurations:ci' }
            defines { 'NDEBUG' }

        filter { 'configurations:debug' }
            defines { 'DEBUG' }
            symbols 'On'

        project 'systemtests_stop'
            kind 'ConsoleApp'
            targetdir 'bin'
            files { files_systemtest_stop }    
            includedirs { includedirs_test }

        project 'systemtests_run'
            kind 'ConsoleApp'
            targetdir 'bin'
            libdirs { 'lib' }
            links { links_test_gcc }
            files { files_testenv, files_systemtest }
            includedirs { includedirs_test }
            linkoptions { linkoptions_test_gcc }

--  ============================================================
--  > dstw.make
--  data generator and application runtime
--  ============================================================
workspace 'dstw'
    filter { 'action:gmake*' }
        configurations { 'ci', 'debug' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'
        targetdir 'bin'
        buildoptions { buildoptions_gcc }
        
        filter { 'configurations:ci' }
            defines { 'NDEBUG' }

        filter { 'configurations:debug' }
            defines { 'DEBUG' }
            symbols 'On'

        project 'dstw_gen'
            kind 'ConsoleApp'
            includedirs { includedirs_test }
            defines { 'NDEBUG', defines_test }
            files { files_gendata }

        project 'dstw_run'
            kind 'ConsoleApp'
            includedirs { includedirs_app }
            defines { defines_app }
            files { files_app, files_app_main }

