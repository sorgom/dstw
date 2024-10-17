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
--  > dstw.sln
--  configurations: 
--  - ci        no debug
--  - debug     debug mode
--  - dev       debug mode
--  ============================================================
workspace 'dstw'
    filter { 'action:vs*' }
        configurations { 'ci', 'debug', 'dev' }
        language 'C++'
        objdir 'obj/%{prj.name}/%{cfg.name}'
        kind 'ConsoleApp'
        targetdir 'exe'
        libdirs { 'lib/%{cfg.name}' }
        warnings 'high'
 
        filter { 'configurations:ci' }
            defines { 'NDEBUG' }

        filter { 'configurations:debug' }
            defines { 'DEBUG' }
            symbols 'On'

        filter { 'configurations:dev' }
            defines { 'DEBUG' }
            symbols 'On'

        --  ============================================================
        --  common
        --  ============================================================
        project 'cpputest'
            kind 'StaticLib'
            targetdir 'lib/%{cfg.name}'
            buildoptions { buildoptions_vs_cpputest }
            includedirs { includedirs_cpputest }
            files { files_cpputest_vs }

        --  ============================================================
        --  module tests
        --  configurations: 
        --  - ci        module tests
        --  - debug     module tests debug mode
        --  - dev       developer tests debug mode
        --  ============================================================
        --  must be unstrumented for coverage
        project 'moduletests'
            buildoptions { buildoptions_vs_test }
            includedirs { includedirs_test }
            links { 'winmm', 'ws2_32', 'cpputest' }
        
            files { files_app, files_testenv }
            
            filter { 'configurations:ci' }
                files { files_moduletest }

            filter { 'configurations:debug' }
                files { files_moduletest }

            filter { 'configurations:dev' }
                files { files_devtest }
    
        --  ============================================================
        --  system tests
        --  ============================================================
        --  run first
        project 'dstw_gen'
            buildoptions { buildoptions_vs_app }
            includedirs { includedirs_test }
            files { files_gendata }
        
         --  run second in background
         --  must be unstrumented for coverage
         project 'dstw_run'
            buildoptions { buildoptions_vs_app }
            includedirs { includedirs_app }
            files { files_app, files_app_main }
            links { 'ws2_32' }

        --  run third
        project 'systemtests_run'
            buildoptions { buildoptions_vs_test }
            includedirs { includedirs_test }
            files { files_systemtest, files_testenv }
            links { 'winmm', 'ws2_32', 'cpputest' }

        --  run last to stop application in background
        project 'dstw_stop'
            buildoptions { buildoptions_vs_test }
            includedirs { includedirs_test }
            files { files_dstw_stop }    
            links { 'ws2_32' }

