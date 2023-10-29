--  ============================================================
--  Makefile build rules for premake5:
--  ============================================================

--  ============================================================
--  > Tests.make
--  module tests and system tests at once runtime
--  ============================================================
workspace 'Tests'
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

    project 'tests'
        kind        'ConsoleApp'
        targetdir   'bin'

        files { 
            '../application/modules/**.cpp',
            'testenv/**.cpp',
            'moduletests/**.cpp',
            'systemtests/**.cpp'
        }

        defines { 'NDEBUG' }
        optimize 'On'
        links { 'CppUTest', 'CppUTestExt' }

--  ============================================================
--  > Coverage.make
--  -   coverage instrumented application (static lib)
--  -   module tests only runtime
--  ============================================================
workspace 'Coverage'
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

    project 'application_coverage'
        kind        'StaticLib'
        targetdir   'lib'
        
        files { 
            '../application/modules/**.cpp',
        }

        defines { 'DEBUG' }
        symbols 'On'
        buildoptions {'-fprofile-arcs -ftest-coverage'}

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

--  ============================================================
--  > Application.make
--  application runtime
--  ============================================================
workspace 'Application'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs {
        '../specification',
        '../application',
        '../application/modules',
    }

    buildoptions { '-std=c++98 -pedantic-errors' }

    project 'dstw_app'
        kind        'ConsoleApp'
        targetdir   'bin'
        
        files { 
            '../application/**.cpp'
        }

        defines { 'NDEBUG' }
        optimize 'On'
    

