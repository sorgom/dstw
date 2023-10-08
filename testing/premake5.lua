workspace 'Wumpel'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs {
        './',
        '../application',
        '../application/modules',
    }
    
    defines { 'MODULE_TEST' }

-- module tests release   
project 'moduletests'
    kind        'ConsoleApp'
    targetdir   'bin'

    files { 
        '../application/modules/*/src/*.cpp',
        '*/src/*.cpp',
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

project 'moduletests_coverage'
    kind        'ConsoleApp'
    targetdir   'bin'

    files { 
        '*/src/*.cpp',
        'tests/**.cpp',
    }

    defines { 'DEBUG' }
    symbols 'On'

    libdirs { 'lib' }
    links { 'application_coverage', 'CppUTest', 'CppUTestExt', 'gcov' }
    linkoptions { '--coverage' }
