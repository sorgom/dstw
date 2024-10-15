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
buildoptions_vs_cpputest = buildoptions_vs_app .. ' -DCPPUTEST_MEM_LEAK_DETECTION_DISABLED'
--  ============================================================
--  > tests.sln
--  module tests at once runtime
--  including CppUTest sources
--  ->  exe/tests.exe
--  configurations: 
--  - ci        module tests
--  - debug     module tests debug mode
--  - dev       developer tests debug mode
--  ============================================================
workspace 'dstw'
    filter { 'action:vs*' }
        configurations { 'ci', 'debug', 'dev' }
        language 'C++'
        objdir 'obj/%{prj.name}/%{cfg.name}'
        kind 'ConsoleApp'
        targetdir 'exe'
        warnings 'high'
 
        filter { 'configurations:ci' }
            defines { 'NDEBUG' }

        filter { 'configurations:debug' }
            defines { 'DEBUG' }
            symbols 'On'

        filter { 'configurations:dev' }
            defines { 'DEBUG' }
            symbols 'On'

        project 'moduletests'
            buildoptions { buildoptions_vs_test }
            includedirs { includedirs_test }
            links { 'winmm', 'ws2_32' }
        
            files { files_cpputest_vs, files_testenv, files_app }
            
            filter { 'configurations:ci' }
                files { files_moduletest }

            filter { 'configurations:debug' }
                files { files_moduletest }

            filter { 'configurations:dev' }
                files { files_devtest }
    
        project 'dstw_gen'
            buildoptions { buildoptions_vs_app }
            includedirs { includedirs_test }
            files { files_gendata }
        
        project 'dstw_run'
            buildoptions { buildoptions_vs_app }
            includedirs { includedirs_app }
            files { files_app, files_app_main }
            links { 'ws2_32' }

        project 'systemtests_stop'
            buildoptions { buildoptions_vs_test }
            includedirs { includedirs_test }
            files { files_systemtest_stop }    
            links { 'ws2_32' }

        project 'systemtests_run'
            buildoptions { buildoptions_vs_test }
            includedirs { includedirs_test }
            files { files_cpputest_vs, files_testenv, files_systemtest }
            links { 'winmm', 'ws2_32' }

--  ============================================================
--  > dstw_system.sln
--  build all executables at once:
--  - application runtime
--  - generate proj data for runtime
--  - TCP based system tests
--  - TCP based application stop
--  ============================================================
-- workspace 'dstw_system'
--     filter { 'action:vs*' }
--         configurations { 'ci', 'debug' }
--         language 'C++'
--         objdir 'obj/vs/%{prj.name}'
--         kind 'ConsoleApp'

--         targetdir 'exe'
--         warnings 'high'
--         buildoptions { buildoptions_vs_app }

--         filter { 'configurations:ci' }
--             defines { 'NDEBUG' }

--         filter { 'configurations:debug' }
--             defines { 'DEBUG' }
--             symbols 'On'


