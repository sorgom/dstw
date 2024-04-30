@echo off
rem ====================================
rem run system tests in windows
rem ====================================
rem created by ChatGPT

cd /d "%~dp0"
set ret=0
set bins=dstw_gen.exe dstw_run.exe systemtests_run.exe systemtests_stop.exe
for %%I in (%bins%) do (
    if not exist exe\%%I (
        echo not found: exe\%%I
        set /a ret+=1
    )
)

if %ret% neq 0 exit /b %ret%

exe\systemtests_stop.exe
timeout /t 1 /nobreak >nul

rem gen required proj data file
exe\dstw_gen.exe
rem start app in background
start /B exe\dstw_run.exe 1
rem run tests after a second
timeout /t 1 /nobreak >nul
exe\systemtests_run.exe -b -v
set ret=%errorlevel%
rem stop app anyway
exe\systemtests_stop.exe
timeout /t 1 /nobreak >nul

pause
exit /b %ret%

