@echo off
if "%_me%" == "" exit /b 1
rem ========================================================================
rem Bullseye coverage: build and run step 1 (requires VS shell)
rem ========================================================================
rem setup
rem ========================================================================
rem minmal coverage setup
rem - minimal function coverage %
set minFunctionCov=100
rem - minimal decision coverage %
set minDecisionCov=99

call %~dp0_covdirs.cmd

set premakeFile=%makeDir%\premake5_vs.lua

set exeDir=%makeDir%\exe
set vsSolution=%makeDir%\dstw.sln
set vsConfig=ci
set myReportsDir=%reportsDir%\%_me%
set buildLog=%myReportsDir%\build_.txt
set covLog=%myReportsDir%\coverage.txt
set covHtmlDir=%myReportsDir%\html
set testReport=%myReportsDir%\test_errors.txt

set covfile=%reportsDir%\%_me%.cov
set covcopt=--srcdir %dstwDir% --macro
set excludeFile=%myDir%\_covexclude.txt
set optsTxt=%myDir%\_covoptions.txt

set vsCall=msbuild %vsSolution% /p:Configuration=%vsConfig%

rem ========================================================================
rem CLI options
rem ========================================================================
set _vsversion=vs2019
set _premake=0
set _cleanbuild=0
set _cleanreports=0
set _genhtml=0
set _update=0

for %%p in (%*) do (
    if "%%p" == "-h" (
        echo Usage: %_me%.cmd [options]
        cat %optsTxt%
        exit /b 1
    ) else if "%%p" == "-c" (
        set _cleanbuild=1
    ) else if "%%p" == "-r" (
        set _cleanreports=1
    ) else if "%%p" == "-H" (
        set _genhtml=1
    ) else if "%%p" == "-u" (
        set _update=1
    ) else if "%%p" == "-p" (
        set _premake=1
    ) else (
        set _vsversion=%%p
    )
)

rem ========================================================================
rem common 1st steps
rem ========================================================================
if not exist %vsSolution% set _premake=1
if not exist %covfile% set _cleanbuild=1

if %_cleanreports% == 1 (
    echo - clean reports
    if exist %myReportsDir% rm -rf %myReportsDir%
)

if %_premake% == 1 (
    echo - premake for %_vsversion%
    call premake5 --file=%premakeFile% %_vsversion%
)

if %_cleanbuild% == 1 (
    echo - clean
    if exist %covfile% rm -f %covfile%
    call %vsCall% /t:clean >NUL
)

if not exist %myReportsDir% mkdir %myReportsDir%

echo %DATE% %TIME% > %buildLog%

echo - build
call cov01 -q --off
echo -- cpputest
call %vsCall% /t:cpputest >> %buildLog% 2>&1

exit /b 0
