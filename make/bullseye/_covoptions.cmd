@echo off
if "%_me%" == "" exit /b 1
rem ========================================================================
rem Bullseye coverage: CLI options
rem ========================================================================
call %~dp0_covsetup.cmd %*

%pyDir%\somutil\docopts.py %optsTxt% %* > %tmpCmd%
if %errorlevel% NEQ 0 exit /b 1
call %tmpCmd%

if not exist %covfile% set _c=1==1

if %_h% (
    echo.
    echo usage: %_me%.cmd [options]
    type %optsTxt%
    exit /b 1
)

echo - setup

if not exist %vsSolution% (
    echo %vsSolution% not found
    echo use premak5 vs... in make folder to generate it
    exit /b 1
)

if %_c% (
    echo - clean
    del /Q %covfile% >NUL 2>&1
    %vsCall% -t:Clean >NUL
)
if %_r% (
    rmdir /S /Q %myReportsDir% >NUL 2>&1
)
set _genhtml=%_Hu%
set _update=%_u%
set _gentodo=%_t%
set _genmd=%_m%

md %myReportsDir% >NUL 2>&1

echo - build

call %myDir%\_covbuild.cmd --off cpputest
if %errorlevel% NEQ 0 exit /b 1

cd %myDir%
