@echo off
if "%_me%" == "" exit /b 1
if "%tmpFile%" == "" exit /b 1
rem ========================================================================
rem system tests: run app in background
rem ========================================================================
echo running > %tmpFile%
call %exeDir%\dstw_run.exe loop >NUL
rm -f %tmpFile%
exit 0
