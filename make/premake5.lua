--  ============================================================
--  premake5 build rules
--  ============================================================

include 'premake5_settings.lua'


workspace 'DSTW'
    configurations { 'ci' }
    language 'C++'
    targetdir '../build'
    objdir  '../build/%{_TARGET_OS}'
    defines { 'NDEBUG' }
    optimize 'Speed'
    kind 'ConsoleApp'
    libdirs { '../build' }

    filter { 'action:vs*' }
        buildoptions { buildoptions_vs_test }
        links { 'ws2_32' }
        warnings 'high'

    filter { 'action:gmake*' }
        buildoptions { buildoptions_gcc }
        linkoptions { '-pthread' }

    --  ============================================================
    --  cpputest
    --  ============================================================
    project 'cpputest'
        kind 'StaticLib'
        defines { defines_test, 'CPPUTEST_MEM_LEAK_DETECTION_DISABLED' }
        includedirs { includedirs_cpputest }

        filter { 'action:vs*' }
            buildoptions { buildoptions_vs_cpputest }
            files { files_cpputest_vs }

        filter { 'action:gmake*' }
            files { files_cpputest_gcc }

    --  ============================================================
    --  module tests / dev tests
    --  ============================================================
    project 'moduletests'
        files { files_app, files_testenv, files_moduletest }
        includedirs { includedirs_test }
        defines { defines_test }
        links { 'cpputest' }

        filter { 'action:vs*' }
        links { 'winmm' }

    project 'devtests'
        files { files_app, files_testenv, files_devtests }
        includedirs { includedirs_test, '../devel' }
        defines { defines_test }
        links { 'cpputest' }

        filter { 'action:vs*' }
        links { 'winmm' }

    --  ============================================================
    --  system tests
    --  ============================================================
    --  run first
    project 'dstw_gen'
        includedirs { includedirs_test }
        files { files_gendata }

    --  run second in background
    --  must be unstrumented for coverage
    project 'dstw_run'
        files { files_app, files_app_main }
        includedirs { includedirs_app }

    --  run third
    project 'systemtests_run'
        files { files_systemtest, files_testenv }
        includedirs { includedirs_test }
        defines { defines_test }
        links { 'cpputest' }

        filter { 'action:vs*' }
        links { 'winmm' }


    --  run last to stop application in background
    project 'dstw_stop'
        files { files_dstw_stop }    
        includedirs { includedirs_test }
