workspace 'Wumpel'
    configurations { 'release', 'debug' }

-- module tests project   
project 'moduletests'
    kind        'ConsoleApp'
    language    'C++'
    targetdir   'bin'
    objdir      'build/obj/%{cfg.buildcfg}'

    includedirs {
        '../application',
        '../application/modules',
        './'
    }

    files { 
        '../application/modules/*/src/*.cpp',
        '*/src/*.cpp',
        'tests/**.cpp',
    }

    defines { 'MODULE_TEST' }

    links { 'CppUTest', 'CppUTestExt' }

    filter 'configurations:debug'
        defines { 'DEBUG' }
        symbols 'On'

    filter 'configurations:release'
        defines { 'NDEBUG' }
        -- optimize 'On'

