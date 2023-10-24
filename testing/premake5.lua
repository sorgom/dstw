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
        'testenv',
        '../specification',
        '../application',
        '../application/modules',
        '../devel'
    }

    buildoptions { '-std=c++98 -pedantic-errors' }

-- application library (build check for app sources)
project 'application_lib'
    kind        'StaticLib'
    targetdir   'lib'
    
    files { 
        '../application/**.cpp',
    }

    defines { 'NDEBUG' }
    optimize 'On'
    
-- tests release   
project 'tests'
    kind        'ConsoleApp'
    targetdir   'bin'

    files { 
        '../application/**.cpp',
        '**.cpp'
    }

    defines { 'NDEBUG' }
    optimize 'On'
    links { 'CppUTest', 'CppUTestExt' }

-- coverage instrumented application library
project 'application_coverage'
    kind        'StaticLib'
    targetdir   'lib'
    
    files { 
        '../application/**.cpp',
    }

    defines { 'DEBUG' }
    symbols 'On'
    buildoptions {'-fprofile-arcs -ftest-coverage'}

-- test runtime using instrumented application library
project 'tests_coverage'
    kind        'ConsoleApp'
    targetdir   'bin'

    files { 
        'testenv/**.cpp',
        'moduletests/**.cpp'
    }

    defines { 'DEBUG' }
    symbols 'On'

    libdirs { 'lib' }
    links { 'application_coverage', 'CppUTest', 'CppUTestExt', 'gcov' }
    linkoptions { '--coverage' }
