--  ============================================================
--  premake5 build rules for VS:
--  ============================================================

include 'premake5_settings.lua'

--  ============================================================
--  > cpputest.sln
--  cpputest library
--  ->  lib/cpputest.lib
--  ============================================================
workspace 'cpputest'
    filter { 'action:vs*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/%{prj.name}'

        includedirs { testIncludes }

        defines { 'NDEBUG', testDefines }
        optimize 'On'
        stl 'none'

        project 'cpputest'
            kind 'StaticLib'
            targetdir 'lib'
            buildoptions { '/std:c++20 /W2' }
            files { 
                CppUTestHome .. 'src/CppUTest/*.cpp',
                CppUTestHome .. 'src/Platforms/VisualCpp/*.cpp',
                CppUTestHome .. 'src/CppUTestExt/*.cpp'
            }

--  ============================================================
--  > tests.sln
--  module tests and system tests at once runtime
--  (requires cpputest.lib)
--  ->  exe/tests.exe
--  ============================================================
workspace 'tests'
    filter { 'action:vs*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/%{prj.name}'

        includedirs { testIncludes }

        defines { 'NDEBUG', testDefines }
        optimize 'On'
        stl 'none'

        project 'tests'
            kind 'ConsoleApp'
            targetdir 'exe'
            warnings 'high'
            buildoptions { '/std:c++20 /W4 /wd4103 /wd4100 /wd4127' }

            files { testSrcs }
            libdirs { 'lib' }

            links { 'winmm', 'cpputest' }


--  ============================================================
--  > dstw.sln
--  application runtime
--  ->  exe/dstw.exe
--  ============================================================
workspace 'dstw'
    filter { 'action:vs*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/%{prj.name}'

        includedirs { appIncludes }
        targetdir 'exe'
        warnings 'high'
        buildoptions { '/std:c++20 /W4 /wd4100 /wd4103' }

        project 'dstw'
            kind 'ConsoleApp'
            
            files { '../application/**.cpp' }

            defines { 
                'NDEBUG', 
                'CAPACITY_TSW=2000', 
                'CAPACITY_SIG=2000', 
                'CAPACITY_LCR=2000', 
                'CAPACITY_SEG=2000' 
            }
            optimize 'On'
            stl 'none'
   
