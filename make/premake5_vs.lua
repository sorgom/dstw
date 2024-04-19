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
buildoptions_vs = '/std:c++17 /MP'
buildoptions_vs_app = buildoptions_vs .. ' /W4 /wd4100 /wd4103'
buildoptions_vs_test = buildoptions_vs_app .. ' /wd4127'

--  ============================================================
--  > tests.sln
--  module tests at once runtime
--  including CppUTest sources
--  ->  exe/tests.exe
--  configurations: 
--  - ci        module tests
--  - dev       developer tests
--  ============================================================
workspace 'tests'
    filter { 'action:vs*' }
        configurations { 'ci', 'dev' }
        language 'C++'
        objdir 'obj/vs/%{prj.name}'

        includedirs { includedirs_test }

        defines { 'NDEBUG', defines_test }

        project 'tests'
            kind 'ConsoleApp'
            targetdir 'exe'
            warnings 'high'
            links { 'winmm' }
            buildoptions { buildoptions_vs_test }
            files { files_cpputest_vs }
            removefiles { removefiles_test }
            
            filter { 'configurations:ci' }
                files { files_moduletest }

            filter { 'configurations:dev' }
                files { files_devtest }

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
        buildoptions { buildoptions_vs_app }

        defines { defines_gendata }
    
        project 'gendata'
            kind 'ConsoleApp'
            includedirs { includedirs_test }
            files { files_gendata }

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
        buildoptions { buildoptions_vs_app }

        defines { defines_app }
    
        project 'dstw'
            includedirs { includedirs_app }
            kind 'ConsoleApp'
            files { files_app }

