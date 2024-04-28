--  ============================================================
--  premake5 build rules for gcc (gmake2):
--  ============================================================

include 'premake5_settings.lua'
buildoptions_gcc = '-std=c++17 -pedantic-errors -Werror -Wall'

--  ============================================================
--  > lib_cpputest.make
--  cpputest lib
--  ============================================================
workspace 'lib_cpputest'
    filter { 'action:gmake*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}/%{cfg.name}'
        defines { defines_test }
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
--  - qnd       module tests with devel includes
--  - dev       developer tests with devel includes
--  - bullseye  module tests with bullseye coverage
--  - none      no tests
--  ============================================================
workspace 'tests'
    filter { 'action:gmake*' }
        configurations { 'ci', 'qnd', 'dev', 'bullseye', 'tmp' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}/%{cfg.name}'
        targetsuffix '_%{cfg.name}'
        buildoptions { buildoptions_gcc }
        linkoptions { linkoptions_test_gcc }

        project 'tests'
            kind 'ConsoleApp'
            defines { 'NDEBUG', defines_test }
            targetdir 'bin'
            libdirs { 'lib' }
            includedirs { includedirs_test }
            links { links_test_gcc }
            files { files_testenv, files_app }

            filter { 'configurations:ci' }
                files { files_moduletest }

            filter { 'configurations:qnd' }
                files { files_moduletest }
                includedirs { includedirs_qnd }

            filter { 'configurations:dev' }
                files { files_devtest }
                includedirs { includedirs_qnd }

            filter { 'configurations:bullseye' }
                files { files_moduletest }
                prebuildcommands { 'cov01 -1 --no-banner' }
                postbuildcommands { './bullseye.sh' }

            filter { 'configurations:tmp' }
                includedirs { includedirs_qnd }
                files {
                    '../testing/tests/moduletests/COM/*.cpp'
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
        configurations { 'ci', 'dev', 'qnd' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'
        targetsuffix '_%{cfg.name}'

        includedirs { includedirs_test }
        buildoptions { buildoptions_gcc }

        defines { 'DEBUG', defines_test }
        symbols 'On'

        project 'coverage_app'
            kind 'StaticLib'
            targetdir 'lib'
            files { files_app }
            buildoptions {'-fprofile-arcs -ftest-coverage'}

        project 'coverage_tests'
            kind 'ConsoleApp'
            targetdir 'bin'
            libdirs { 'lib' }
            links { 'coverage_app', 'gcov', links_test_gcc }
            linkoptions { linkoptions_test_gcc, '--coverage' }
            files { files_testenv }
            filter { 'configurations:ci' }
                files { files_moduletest }
            filter { 'configurations:dev' }
                files { files_devtest }
            filter { 'configurations:qnd' }
                files { files_moduletest }
                includedirs { includedirs_qnd }

--  ============================================================
--  > systemtests.make
--  -   run tests only runtime
--  configurations: 
--  - ci        module tests
--  - qnd       with devel includes
--  ============================================================
workspace 'systemtests'
    filter { 'action:gmake*' }
        configurations { 'ci', 'qnd' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'
        buildoptions { buildoptions_gcc }

        defines { 'DEBUG', defines_gendata }
        symbols 'On'

        filter { 'configurations:qnd' }
            includedirs { includedirs_qnd }

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
            removefiles { 
                '../testing/testenv/mocks/**.cpp'
            }
            includedirs { includedirs_test }
            linkoptions { linkoptions_test_gcc }

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
        buildoptions { buildoptions_gcc }
        optimize 'On'

        project 'dstw_gen'
            kind 'ConsoleApp'
            includedirs { includedirs_test }
            defines { 'NDEBUG', defines_gendata }
            files { files_gendata }

        project 'dstw_run'
            kind 'ConsoleApp'
            includedirs { includedirs_app }
            defines { defines_app }
            files { files_app, files_app_main }

--  ============================================================
--  > _valgrind.make
--  sample runtime with memory leak
--  ============================================================
workspace '_valgrind'
    filter { 'action:gmake*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'
        targetdir 'bin'
        buildoptions { buildoptions_gcc }
        defines { 'DEBUG' }
        symbols 'On'

        project '_valgrind'
            kind 'ConsoleApp'
            files { '../testing/valgrind/*.cpp' }

