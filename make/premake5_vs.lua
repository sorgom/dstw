--  ============================================================
--  premake5 build rules for VS
--  ============================================================

include 'premake5_settings.lua'

--  ============================================================
--  general setup
--  warning level: 4 (high)
--  
--  suppressed warnings application:
--  -   4100 unreferenced formal parameter
--  -   4103 change of alignement with header inclusion
--      this is intended behaviour of packBegin.h / packEnd.h
--  additional suppressed warnings test code:
--  -   4127 suggested 'if constexpr' 
--      warning caused by CppUTest headers code
--  ============================================================
buildOptsApp = '/std:c++17 /W4 /wd4100 /wd4103'
buildOptsTest = buildOptsApp .. ' /wd4127'

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

        project 'cpputest'
            kind 'StaticLib'
            targetdir 'lib'
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

        project 'tests'
            kind 'ConsoleApp'
            targetdir 'exe'
            warnings 'high'
            buildoptions { buildOptsTest }

            files { testSrcs }
            libdirs { 'lib' }

            links { 'winmm', 'ws2_32', 'cpputest' }

--  ============================================================
--  > gendata.sln
--  generate proj data for application runtime
--  ->  exe/gendata.exe
--  ============================================================
workspace 'gendata'
    filter { 'action:vs*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/%{prj.name}'

        targetdir 'exe'
        warnings 'high'
        buildoptions { buildOptsApp }

        defines { appDefines }
    
        project 'gendata'
            kind 'ConsoleApp'
            includedirs { testIncludes }
            files { genDataSrcs }
            links { 'ws2_32' }

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

        targetdir 'exe'
        warnings 'high'
        buildoptions { buildOptsApp }

        defines { appDefines }
    
        project 'dstw'
            includedirs { appIncludes }
            kind 'ConsoleApp'
            files { '../application/**.cpp' }
            links { 'ws2_32' }

