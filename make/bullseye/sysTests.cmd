@echo off
rem ========================================================================
rem Bullseye coverage: build and run module tests (requires VS shell)
rem ========================================================================

SETLOCAL
set _me=%~n0
call %~dp0_covoptions.cmd %*
if %errorlevel% neq 0 exit /b 0

rem - minimal function coverage %
set minFunctionCov=50
rem - minimal decision coverage %
set minDecisionCov=30

for %%t in (dstw_gen dstw_stop systemtests) do (
    call %myDir%\_covbuild.cmd --off %%t
    if %errorlevel% NEQ 0 exit /b 1
)
call %myDir%\_covbuild.cmd --on dstw_runtime
if %errorlevel% NEQ 0 exit /b 1

cd /d %buildDir%

DEL /Q %projFile% >NUL 2>&1

echo - launch application without data
%exeDir%\dstw_runtime.exe X

echo - gen data
%exeDir%\dstw_gen.exe >NUL

echo - launch application without parameter
%exeDir%\dstw_runtime.exe

set /a "myID=%random%"
set tmpFile=%buildDir%\run.%myID%.tmp

echo - launch application
start /B %myDir%\_runapp.cmd dstw_runtime

echo - run tests
%exeDir%\systemtests.exe -b -v > %testReport% 2>&1
if %errorlevel% == 0 del %testReport%

echo - stop application ...
%exeDir%\dstw_stop.exe

:wait
timeout /t 1 /nobreak >NUL 2>&1
if exist %tmpFile% goto wait

call %myDir%\_covreport.cmd
