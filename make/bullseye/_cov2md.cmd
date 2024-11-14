@echo off
rem ========================================================================
rem Bullseye coverage: generate md file
rem ========================================================================
SETLOCAL
set reportMod=%reportsDir%\modTests\coverage.txt
set reportSys=%reportsDir%\sysTests\coverage.txt
set target=%dstwDir%\testing\coverage_bullseye.md

if not exist %reportMod% exit /b 0
if not exist %reportSys% exit /b 0

echo - md

echo # current bullseye coverage > %target%
echo %DATE% >> %target%
echo. >> %target%
type %reportMod% >> %target%
echo. >> %target%
type %reportSys% >> %target%
