@echo off
if "%_me%" == "" exit /b 1
rem ========================================================================
rem Bullseye coverage: base directories
rem ========================================================================
cd /d %~dp0
set myDir=%cd%
cd ..
set makeDir=%cd%
cd ..
set dstwDir=%cd%

set reportsDir=%dstwDir%\reports

cd %myDir%
