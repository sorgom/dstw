--  ============================================================
--  Makefile build rules for premake5
--  - module tests with target compiler settings
--  - module tests with coverage instrumented application code
--  ============================================================
workspace 'Testing'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs {
        'testenv/',
        '../application',
        '../application/modules',
    }

    buildoptions { '-std=c++98 -pedantic-errors' }
    
-- module tests release   
project 'moduletests'
    kind        'ConsoleApp'
    targetdir   'bin'

    files { 
        '../application/modules/*/src/*.cpp',
        'testenv/*/src/*.cpp',
        'tests/**.cpp',
    }

    defines { 'NDEBUG' }
    optimize 'On'
    links { 'CppUTest', 'CppUTestExt' }

-- coverage instrumented application library
project 'application_coverage'
    kind        'StaticLib'
    targetdir   'lib'
    
    files { 
        '../application/modules/*/src/*.cpp',
    }

    defines { 'DEBUG' }
    symbols 'On'
    buildoptions {'-fprofile-arcs -ftest-coverage'}

-- test runtime using instrumented application library
project 'moduletests_coverage'
    kind        'ConsoleApp'
    targetdir   'bin'

    files { 
        'testenv/*/src/*.cpp',
        'tests/**.cpp',
    }

    defines { 'DEBUG' }
    symbols 'On'

    libdirs { 'lib' }
    links { 'application_coverage', 'CppUTest', 'CppUTestExt', 'gcov' }
    linkoptions { '--coverage' }
