@echo off
rem ========================================================================
rem Bullseye coverage: build and run tests (requires VS shell)
rem ========================================================================

SETLOCAL
rem minmal coverage setup
rem - minimal function coverage %
set minFunctionCov=100
rem - minimal decision coverage %
set minDecisionCov=99

cd /d %~dp0
set myDir=%cd%
cd ..
set makeDir=%cd%
cd ..
set dstwDir=%cd%

set premakeFile=%makeDir%\premake5_vs.lua

set executable=%makeDir%\exe\tests.exe
set vsSolution=%makeDir%\tests.sln
set vsBuildTarget=tests

set reportsDir=%dstwDir%\reports
set buildLog=%reportsDir%\buildReport.txt
set covLog=%reportsDir%\coverageReport.txt
set covHtmlDir=%reportsDir%\html

set covfile=%makeDir%\modtest.cov
set covcopt=--srcdir %dstwDir%
set excludeFile=%myDir%\_covexclude.txt
set optsTxt=%myDir%\_covoptions.txt

set covMin=%minFunctionCov%,%minDecisionCov%

set _vsversion=vs2019
set _premake=0
set _cleanbuild=0
set _cleanreports=0
set _genhtml=0
set _update=0

for %%p in (%*) do (
    if "%%p" == "-h" (
        echo Usage: %~n0%~x0 [options]
        cat %optsTxt%
        exit /b 0
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

if not exist %vsSolution% set _premake=1
if not exist %covfile% set _cleanbuild=1

if %_premake% == 1 (
    echo - premake for %_vsversion%
    call premake5 --file=%premakeFile% %_vsversion%
    set _cleanbuild=1
)

if %_cleanreports% == 1 (
    echo - clean reports
    if exist %reportsDir% rm -rf %reportsDir%
)

if %_cleanbuild% == 1 (
    echo - clean
    if exist %covfile% rm -f %covfile%
    call msbuild /t:Clean %vsSolution% >NUL
)

if not exist %reportsDir% mkdir %reportsDir%

call cov01 -q1

echo - build
call msbuild %vsSolution% > %buildLog% 2>&1

call cov01 -q0

if not exist %executable% (
    echo %executable% not found
    exit /b 1
)

if not exist %covfile% (
    echo %covfile% not found
    exit /b 1
)

rm -f %buildLog%

rem rewind coverage file if it was not removed before
call covclear -q

echo - run
call %executable% >NUL

if %_update% == 1 exit /b 0

call covselect -qd
call covselect -q --import %excludeFile%

if %_genhtml% == 1 (
    echo - html
    call covhtml -q --allNum %covHtmlDir%
)

echo - report

cd %dstwDir%
call covdir -q --by-name --srcdir . | tee %covLog%

set _result=failed
call covdir -q --checkmin %covMin%
if %errorlevel% == 0 set _result=passed
echo covmin %covMin% %_result% | tee -a %covLog%
