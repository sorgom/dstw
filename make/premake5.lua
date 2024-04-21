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

        buildoptions { buildoptions_gcc }

        project 'tests'
            kind 'ConsoleApp'
            defines { 'NDEBUG', defines_test }
            targetdir 'bin'
            libdirs { 'lib' }
            includedirs { includedirs_test }
            links { links_test_gcc }
            files { files_testenv, files_app }
            removefiles { removefiles_test }

            filter { 'configurations:ci' }
                files { files_moduletest }

            filter { 'configurations:qnd' }
                files { files_moduletest }
                includedirs { '../devel' }

            filter { 'configurations:dev' }
                files { files_devtest }

            filter { 'configurations:bullseye' }
                files { files_moduletest }
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

        includedirs { includedirs_test }
        buildoptions { buildoptions_gcc }

        defines { 'DEBUG', defines_test }
        symbols 'On'

        project 'coverage_app'
            kind 'StaticLib'
            targetdir 'lib'
            files { files_app }
            removefiles { removefiles_test }
            buildoptions {'-fprofile-arcs -ftest-coverage'}

        project 'coverage_tests'
            kind 'ConsoleApp'
            targetdir 'bin'
            libdirs { 'lib' }
            links { 'coverage_app', 'gcov', links_test_gcc }
            linkoptions { '--coverage' }
            files { files_testenv }
            filter { 'configurations:ci' }
                files { files_moduletest }
            filter { 'configurations:dev' }
                files { files_devtest }

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

        buildoptions { buildoptions_gcc }

        defines { 'DEBUG', defines_test }
        symbols 'On'

        filter { 'configurations:qnd' }
            includedirs { '../devel' }

        project 'systests_app'
            kind 'StaticLib'
            targetdir 'lib'
            files { files_app }
            includedirs { includedirs_app }
            removefiles { removefiles_systest_app }

        project 'systests_tests'
            kind 'ConsoleApp'
            targetdir 'bin'
            libdirs { 'lib' }
            links { 'systests_app_%{cfg.name}', links_test_gcc }
            files { files_testenv, files_systest }
            removefiles { removefiles_systest_test }
            includedirs { includedirs_test }

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
            defines { defines_gendata }
            files { files_gendata }

        project 'dstw_run'
            kind 'ConsoleApp'
            includedirs { includedirs_app }
            defines { defines_app }
            files { files_app }

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

