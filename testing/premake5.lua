workspace 'Wumpel'
    configurations { 'release', 'debug' }

-- module tests project   
project 'moduletests'
    kind        'ConsoleApp'
    language    'C++'
    targetdir   'build/%{cfg.buildcfg}'
    objdir      'build/obj/%{cfg.buildcfg}'

    includedirs { 
        '../application/interfaces',
        '../application/modules',
        './'
    }

    files { 
        '../application/modules/src/*.cpp',
        'testenv/src/*.cpp',
        'tests/**.cpp',
    }

    defines { 'MODULE_TEST' }

    links { 'CppUTest', 'CppUTestExt' }

    libdirs { '/usr/local/lib' }

    filter 'configurations:debug'
        defines { 'DEBUG' }
        symbols 'On'

    filter 'configurations:release'
        defines { 'NDEBUG' }
        optimize 'On'

