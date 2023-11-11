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

testLinks = { 'CppUTest', 'CppUTestExt' }

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

    buildoptions { '-std=c++98 -pedantic-errors' }

    project 'tests'
        kind        'ConsoleApp'
        targetdir   'bin'

        files { 
            testEnvSrcs,
            appSrcs,
            '../testing/tests/moduletests/**.cpp',
            '../testing/tests/systemtests/**.cpp',
        }

        defines { 'NDEBUG', testDefines }
        optimize 'On'
        stl 'none'
        libdirs { '../BuildCppUTest/lib' }
        links { testLinks }

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

    buildoptions { '-std=c++98 -pedantic-errors' }

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

    buildoptions { '-std=c++98 -pedantic-errors' }

    project 'dstw'
        kind        'ConsoleApp'
        targetdir   'bin'
        
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
    buildoptions { '-std=c++98 -pedantic-errors' }

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
    buildoptions { '-std=c++98 -pedantic-errors' }

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