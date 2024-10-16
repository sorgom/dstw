@echo off
rem ========================================================================
rem Bullseye coverage: build and run module tests (requires VS shell)
rem ========================================================================

SETLOCAL
set _me=%~n0
call %~dp0_covstep1.cmd %*
if %errorlevel% neq 0 exit /b 0

call %myDir%\_covbuild.cmd --off dstw_gen dstw_stop systemtests_run
if %errorlevel% NEQ 0 exit /b 1

call %myDir%\_covbuild.cmd --on dstw_run
if %errorlevel% NEQ 0 exit /b 1

if not exist %covfile% (
    echo %covfile% not found
    exit /b 1
)
rm -f %buildLog%

echo - gen data
call %exeDir%\dstw_gen.exe >NUL

set /a "myID=%random%"
set tmpFile=%reportsDir%\run.%myID%.tmp

echo - launch application
start /B %myDir%\_runapp.cmd

timeout /t 2 /nobreak >NUL 2>&1
echo - run tests
call %exeDir%\systemtests_run.exe -b -v > %testReport% 2>&1
if %errorlevel% == 0 rm -f %testReport%

echo - stop application ...
call %exeDir%\dstw_stop.exe

:wait
timeout /t 1 /nobreak >NUL 2>&1
if exist %tmpFile% goto wait

rem - minimal function coverage %
set minFunctionCov=50
rem - minimal decision coverage %
set minDecisionCov=30

call %myDir%\_covreport.cmd
