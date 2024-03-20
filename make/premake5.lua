--  ============================================================
--  Makefile build rules for premake5:
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

testSrcs = {
    testEnvSrcs,
    appSrcs,
    '../testing/tests/moduletests/**.cpp',
    '../testing/tests/systemtests/**.cpp'
}

testLinks = { 'CppUTest', 'CppUTestExt' }

-- buildOpts = { '-std=c++2a -pedantic-errors' }
buildOpts = { '-std=c++17 -pedantic-errors -Werror -Wall' }
buildOptsVC = { '/std:c++20 /W3' }

CppUTestHome = '../BuildCppUTest/CppUTest/'

--  ============================================================
--  > tests.make
--  module tests and system tests at once runtime
--  ->  bin/tests
--  ============================================================
workspace 'tests'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs { testIncludes }

    filter { 'action:gmake2' }
        buildoptions { buildOpts }

    filter { 'action:vs*' }
        buildoptions { buildOptsVC }
        disablewarnings { '4103' }

    project 'tests'
        kind        'ConsoleApp'

        filter { 'action:gmake2' }
            targetdir 'bin'
            files { 
                testSrcs
            }
            libdirs { '../BuildCppUTest/lib' }
            links { testLinks }

        filter { 'action:vs*' }
            targetdir 'exe'
            files { 
                testSrcs,
                CppUTestHome .. 'src/CppUTest/*.cpp',
                CppUTestHome .. 'src/Platforms/VisualCpp/*.cpp',
                CppUTestHome .. 'src/CppUTestExt/*.cpp'
            }
            links { 'winmm' }

        defines { 'NDEBUG', testDefines }
        optimize 'On'
        stl 'none'

--  ============================================================
--  > coverage.make
--  -   coverage instrumented application (static lib)
--  -   module tests only runtime
--  ->  bin/coverage_tests
--  ============================================================
workspace 'coverage'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs { testIncludes }

    buildoptions { buildOpts }

    defines { 'DEBUG', testDefines }
    symbols 'On'
    stl 'none'

    project 'coverage_app'
        kind        'StaticLib'
        targetdir   'lib'
        
        files { appSrcs }
        buildoptions {'-fprofile-arcs -ftest-coverage'}

    project 'coverage_tests'
        kind        'ConsoleApp'
        targetdir   'bin'

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
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs { appIncludes }

    filter { 'action:gmake2' }
        targetdir   'bin'
        buildoptions { buildOpts }

    filter { 'action:vs*' }
        targetdir   'exe'
        buildoptions { buildOptsVC }
        disablewarnings { '4103' }

    project 'dstw'
        kind        'ConsoleApp'
        
        files { 
            '../application/**.cpp'
        }

        defines { 
            'NDEBUG', 
            'CAPACITY_TSW=2000', 
            'CAPACITY_SIG=2000', 
            'CAPACITY_LCR=2000', 
            'CAPACITY_SEG=2000' 
        }
        optimize 'On'
        stl 'none'
    
--  ============================================================
--  > _devtests.make
--  development only tests
--  ->  bin/_devtests
--  ============================================================
workspace '_devtests'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs { testIncludes }
    buildoptions { buildOpts }

    project '_devtests'
        kind        'ConsoleApp'
        targetdir   'bin'

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
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs { testIncludes }
    buildoptions { buildOpts }

    project '_bullseye'
        kind        'ConsoleApp'
        targetdir   'bin'

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