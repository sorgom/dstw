@echo off
rem ========================================================================
rem Bullseye coverage: build and run module tests (requires VS shell)
rem ========================================================================

SETLOCAL
set _me=%~n0
call %~dp0_covsetup.cmd %*
if %errorlevel% neq 0 exit /b 0

rem - minimal function coverage %
set minFunctionCov=50
rem - minimal decision coverage %
set minDecisionCov=30

for %%t in (dstw_gen dstw_stop systemtests) do (
    call %myDir%\_covbuild.cmd --off %%t
    if %errorlevel% NEQ 0 exit /b 1
)
call %myDir%\_covbuild.cmd --on dstw_run
if %errorlevel% NEQ 0 exit /b 1

cd /d %buildDir%

echo - gen data
%exeDir%\dstw_gen.exe >NUL

set /a "myID=%random%"
set tmpFile=%buildDir%\run.%myID%.tmp

echo - launch application
start /B %myDir%\_runapp.cmd

echo - wait
timeout /t 5 /nobreak >NUL 2>&1
echo - run tests
call %exeDir%\systemtests.exe -b -v > %testReport% 2>&1
if %errorlevel% == 0 del %testReport%

echo - stop application ...
call %exeDir%\dstw_stop.exe

:wait
timeout /t 1 /nobreak >NUL 2>&1
if exist %tmpFile% goto wait

call %myDir%\_covreport.cmd
