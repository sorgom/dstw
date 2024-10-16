@echo off
if "%_me%" == "" exit /b 1
rem ========================================================================
rem Bullseye coverage: build step
rem ========================================================================

SETLOCAL
call cov01 -q %1

:next
shift
if "%1"=="" goto end
echo - %1
call %vsCall% /t:%1 >> %buildLog% 2>&1
if %errorlevel% NEQ 0 (
    echo - build error
    exit /b 1
)
if not exist %exeDir%\%1.exe (
    echo - exe not found
    exit /b 1
)
goto next
:end
