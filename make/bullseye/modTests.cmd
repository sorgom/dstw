@echo off
rem ========================================================================
rem Bullseye coverage: build and run module tests (requires VS shell)
rem ========================================================================
SETLOCAL
set _me=%~n0
call %~dp0_covoptions.cmd %*
if %errorlevel% neq 0 exit /b 0

rem minmal coverage setup
rem - minimal function coverage %
set minFunctionCov=100
rem - minimal decision coverage %
set minDecisionCov=99

call %myDir%\_covbuild.cmd --on moduletests
if %errorlevel% NEQ 0 exit /b 1

if not exist %covfile% (
    echo %covfile% not found
    exit /b 1
)

del /Q %buildLog% >NUL 2>&1

rem rewind coverage file if it was not removed before
call covclear -q

echo - run
call %exeDir%\moduletests.exe -b -v > %testReport% 2>&1
if %errorlevel% == 0 rm -f %testReport%

call %myDir%\_covreport.cmd
