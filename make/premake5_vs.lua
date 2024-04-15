--  ============================================================
--  premake5 build rules for VS
--  ============================================================

include 'premake5_settings.lua'

--  ============================================================
--  general setup
--  warning level: 4 (high)
--  multi processor build
--  
--  suppressed warnings application:
--  -   4100 unreferenced formal parameter
--  -   4103 change of alignement with header inclusion
--      this is intended behaviour of packBegin.h / packEnd.h
--  additional suppressed warnings test code:
--  -   4127 suggested 'if constexpr' 
--      warning caused by CppUTest headers code
--  ============================================================
buildOpts = '/std:c++17 /MP'
buildOptsApp = buildOpts .. ' /W4 /wd4100 /wd4103'
buildOptsTest = buildOptsApp .. ' /wd4127'

--  ============================================================
--  > tests.sln
--  module tests and system tests at once runtime
--  including CppUTest sources
--  ->  exe/tests.exe
--  configurations: 
--  - ci        module and system tests
--  - sys       system tests
--  - dev       developer tests
--  ============================================================
workspace 'tests'
    filter { 'action:vs*' }
        configurations { 'ci', 'sys', 'dev' }
        language 'C++'
        objdir 'obj/vs/%{prj.name}'

        includedirs { testIncludes }

        defines { 'NDEBUG', testDefines }

        project 'tests'
            kind 'ConsoleApp'
            targetdir 'exe'
            warnings 'high'
            links { 'winmm', 'ws2_32' }
            buildoptions { buildOptsTest }
            files { 
                testEnvSrcs, appSrcs,
                CppUTestHome .. 'src/CppUTest/*.cpp',
                CppUTestHome .. 'src/Platforms/VisualCpp/*.cpp',
                CppUTestHome .. 'src/CppUTestExt/*.cpp'
            }
            removefiles { noTestSrcs }
            
            filter { 'configurations:ci' }
                files { modTestSrcs, sysTestSrcs }

            filter { 'configurations:sys' }
                files { sysTestSrcs }

            filter { 'configurations:dev' }
                files { devTestSrcs }

--  ============================================================
--  > gendata.sln
--  generate proj data for application runtime
--  ->  exe/gendata.exe
--  ============================================================
workspace 'gendata'
    filter { 'action:vs*' }
        configurations { 'ci' }
        language 'C++'
        objdir 'obj/vs/%{prj.name}'

        targetdir 'exe'
        warnings 'high'
        buildoptions { buildOptsApp }

        defines { genDefines }
    
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
        objdir 'obj/vs/%{prj.name}'

        targetdir 'exe'
        warnings 'high'
        buildoptions { buildOptsApp }

        defines { appDefines }
    
        project 'dstw'
            includedirs { appIncludes }
            kind 'ConsoleApp'
            files { '../application/**.cpp' }
            links { 'ws2_32' }

