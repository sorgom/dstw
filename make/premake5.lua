--  ============================================================
--  premake5 build rules for gcc (gmake2):
--  ============================================================

include 'premake5_settings.lua'
buildOpts = { '-std=c++2a -pedantic-errors -Werror -Wall' }

--  ============================================================
--  > tests.make
--  module tests and system tests at once runtime
--  ->  bin/tests
--  ============================================================
workspace 'tests'
    filter { 'action:gmake*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/%{prj.name}'

        includedirs { testIncludes }
        buildoptions { buildOpts }

        project 'tests'
            kind 'ConsoleApp'
            defines { 'NDEBUG', testDefines }
            optimize 'On'
            stl 'none'
            targetdir 'bin'
            files { testSrcs }
            libdirs { '../BuildCppUTest/lib' }
            links { testLinks }

--  ============================================================
--  > coverage.make
--  -   coverage instrumented application (static lib)
--  -   module tests only runtime
--  ->  bin/coverage_tests
--  ============================================================
workspace 'coverage'
    filter { 'action:gmake*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/%{prj.name}'

        includedirs { testIncludes }
        buildoptions { buildOpts }

        defines { 'DEBUG', testDefines }
        symbols 'On'
        stl 'none'

        project 'coverage_app'
            kind 'StaticLib'
            targetdir 'lib'
            files { appSrcs }
            buildoptions {'-fprofile-arcs -ftest-coverage'}

        project 'coverage_tests'
            kind 'ConsoleApp'
            targetdir 'bin'

            files { 
                testEnvSrcs,
                '../testing/tests/moduletests/**.cpp'
            }

            libdirs { 'lib', '../BuildCppUTest/lib' }
            links { 'coverage_app', 'gcov', testLinks }
            linkoptions { '--coverage' }

--  ============================================================
--  > dstw.make
--  application runtime
--  ->  bin/dstw
--  ============================================================
workspace 'dstw'
    filter { 'action:gmake*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/%{prj.name}'
        targetdir 'bin'
        buildoptions { buildOpts }
        defines { 
            'NDEBUG', 
            'CAPACITY_TSW=2000', 
            'CAPACITY_SIG=2000', 
            'CAPACITY_LCR=2000', 
            'CAPACITY_SEG=2000' 
        }
        optimize 'On'
        stl 'none'

        project 'dstw'
            kind 'ConsoleApp'
            includedirs { appIncludes }
            files { '../application/**.cpp' }

    
        project 'gendata'
            kind 'ConsoleApp'
            includedirs { testIncludes }
            files { genDataSrcs }

--  ============================================================
--  > _devtests.make
--  development only tests
--  ->  bin/_devtests
--  ============================================================
workspace '_devtests'
    filter { 'action:gmake*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/%{prj.name}'

        includedirs { testIncludes }
        buildoptions { buildOpts }

        project '_devtests'
            kind 'ConsoleApp'
            targetdir 'bin'

            files { 
                appSrcs,
                testEnvSrcs,
                '../testing/tests/devtests/*.cpp',
            }

            defines { 'NDEBUG', testDefines }
            optimize 'On'
            libdirs { '../BuildCppUTest/lib' }
            links { testLinks }

--  ============================================================
--  > _bullseye.make
--  module tests for bullseye coverage
--  ->  bin/_bullseye
--  ============================================================
workspace '_bullseye'
    filter { 'action:gmake*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/%{prj.name}'

        includedirs { testIncludes }
        buildoptions { buildOpts }

        project '_bullseye'
            kind 'ConsoleApp'
            targetdir 'bin'

            files { 
                appSrcs,
                testEnvSrcs,
                '../testing/tests/moduletests/**.cpp',
            }

            defines { 'NDEBUG', testDefines }
            optimize 'On'
            stl 'none'

            libdirs { '../BuildCppUTest/lib' }
            links { testLinks }

            prebuildcommands { 'cov01 -1 --no-banner' }
            postbuildcommands { './bullseye.sh' }
