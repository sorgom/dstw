@echo off
if "%_me%" == "" exit /b 1
rem ========================================================================
rem Bullseye coverage: build step
rem ========================================================================

SETLOCAL
cov01 -q %1
shift
if "%1"=="" goto end
echo -- %1
call %vsCall% -t:%1 >> %buildLog% 2>&1
if %errorlevel% NEQ 0 (
    echo - build error %1
    exit /b 1
)
:end
