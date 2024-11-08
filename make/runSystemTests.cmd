@echo off
rem ====================================
rem run system tests in windows
rem ====================================
rem created by ChatGPT
SETLOCAL
cd /d "%~dp0"
set ret=0
set bins=dstw_gen.exe dstw_run.exe systemtests_run.exe dstw_stop.exe
for %%I in (%bins%) do (
    if not exist exe\%%I (
        echo not found: exe\%%I
        set /a ret+=1
    )
)

if %ret% neq 0 exit /b %ret%

set tmpfile=tmp_%random%.txt

exe\dstw_stop.exe
timeout /t 1 /nobreak >nul

rem gen required proj data file
exe\dstw_gen.exe
rem start app in background
echo run > %tmpfile%
start /B runSub.cmd %tmpfile% exe\dstw_run.exe 1
rem run tests after a second
timeout /t 1 /nobreak >nul
exe\systemtests_run.exe -b -v
set ret=%errorlevel%
rem stop app anyway
exe\dstw_stop.exe
:wait
timeout /t 1 /nobreak >nul
if exist %tmpfile% goto wait

exit /b %ret%
