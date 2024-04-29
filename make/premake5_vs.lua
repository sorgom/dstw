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
buildoptions_vs_test = buildoptions_vs_app .. ' /wd4127 /D_WINSOCK_DEPRECATED_NO_WARNINGS'

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
        configurations { 'ci', 'dev', 'qnd' }
        language 'C++'
        objdir 'obj/vs/%{prj.name}'

        includedirs { includedirs_test }

        defines { 'NDEBUG', defines_test }

        project 'tests'
            kind 'ConsoleApp'
            targetdir 'exe'
            warnings 'high'
            links { 'winmm', 'ws2_32' }
            buildoptions { buildoptions_vs_test }
            files { files_cpputest_vs, files_testenv, files_app }
            
            filter { 'configurations:ci' }
                files { files_moduletest }

            filter { 'configurations:qnd' }
                files { files_moduletest }
                includedirs { includedirs_qnd }

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
            files { files_app, files_app_main }
            links { 'ws2_32' }

--  ============================================================
--  > systemtests.sln
--  -   run tests only runtime
--  configurations: 
--  - ci        module tests
--  - qnd       with devel includes
--  ============================================================
workspace 'systemtests'
    filter { 'action:vs*' }
        configurations { 'ci', 'qnd' }
        language 'C++'
        objdir 'obj/gcc/%{prj.name}'
        buildoptions { buildoptions_vs_test }

        defines { 'DEBUG', defines_gendata }
        symbols 'On'
        warnings 'high'

        filter { 'configurations:qnd' }
            includedirs { includedirs_qnd }

        project 'systemtests_stop'
            kind 'ConsoleApp'
            targetdir 'exe'
            links { 'ws2_32' }
            files { files_systemtest_stop }    
            includedirs { includedirs_test }

        project 'systemtests_run'
            kind 'ConsoleApp'
            targetdir 'exe'
            libdirs { 'lib' }
            links { 'winmm', 'ws2_32' }
            files { files_cpputest_vs, files_testenv, files_systemtest }
            includedirs { includedirs_test }
