@echo off
rem ========================================================================
rem Bullseye coverage: generate md file
rem ========================================================================
SETLOCAL
set _me=%~n0
call %~dp0_covdirs.cmd %*
set reportMod=%reportsDir%\modTests\coverage.txt
set reportSys=%reportsDir%\sysTests\coverage.txt
set target=%dstwDir%\testing\coverage_bullseye.md

if not exist %reportMod% call %myDir%\modTests.cmd
if not exist %reportSys% call %myDir%\sysTests.cmd

if not exist %reportMod% (
    echo %reportMod% not found
    exit /b 1
)
if not exist %reportSys% (
    echo %reportSys% not found
    exit /b 1
)
echo # current bullseye coverage > %target%
echo. >> %target%
cat %reportMod% >> %target%
echo. >> %target%
cat %reportSys% >> %target%
echo. >> %target%
