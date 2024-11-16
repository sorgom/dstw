@echo off
rem ====================================
rem run system tests in windows
rem ====================================
rem created by ChatGPT
SETLOCAL
cd /d %~dp0
set myDir=%cd%
cd ..
set buildDir=%cd%\build
set bindir=windows\bin
cd %myDir%
msbuild DSTW.sln -t:dstw_gen,dstw_runtime,systemtests,dstw_stop >NUL
if %errorlevel% neq 0 exit /b %errorlevel%

set tmpfile=tmp_%random%.txt

cd %buildDir%

%binDir%\dstw_stop.exe
timeout /t 1 /nobreak >nul

rem gen required proj data file
%binDir%\dstw_gen.exe
rem start app in background
echo run > %tmpfile%
start /B %myDir%\runSub.cmd %tmpfile% %binDir%\dstw_runtime.exe 1
rem run tests
%binDir%\systemtests.exe -b -v
set ret=%errorlevel%
rem stop app anyway
%binDir%\dstw_stop.exe
:wait
timeout /t 1 /nobreak >nul
if exist %tmpfile% goto wait

exit /b %ret%
