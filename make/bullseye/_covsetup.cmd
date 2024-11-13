@echo off
if "%_me%" == "" exit /b 1
rem ========================================================================
rem Bullseye coverage: base directories
rem ========================================================================
rem minmal coverage setup
rem - minimal function coverage %
set minFunctionCov=100
rem - minimal decision coverage %
set minDecisionCov=99

cd /d %~dp0
set myDir=%cd%
cd ..
set makeDir=%cd%
cd ..
set dstwDir=%cd%
set buildDir=%cd%\build
set subsDir=%cd%\submodules
set ReportsDir=%cd%\reports
set myReportsDir=%reportsDir%\%_me%

set binDir=%subsDir%\sombin
set vsSolution=%makeDir%\DSTW.sln
set vsConfig=ci
set exeDir=%buildDir%\windows\%vsConfig%\bin
set buildLog=%myReportsDir%\build.txt
set covLog=%myReportsDir%\coverage.txt
set covHtmlDir=%myReportsDir%\html
set testReport=%myReportsDir%\test_errors.txt

set covcopt=--srcdir %dstwDir% --macro
set covfile=%reportsDir%\%_me%.cov
set excludeFile=%myDir%\_covexclude.txt
set covTodoTxt=%buildDir%\%_me%_todo.txt

set optsTxt=%myDir%\_covoptions.txt
set vsCall=msbuild %vsSolution% -p:Configuration=%vsConfig%
set tmpCmd=%buildDir%\tmp.cmd

%binDir%\docopts.exe %optsTxt% %* > %tmpCmd%
call %tmpCmd%

if not exist %covfile% set _c=1==1

if %_h% (
    echo usage: %_me%.cmd [options]
    type %optsTxt%
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

call %myDir%\_covbuild.cmd --off cpputest
if %errorlevel% NEQ 0 exit /b 1

cd %myDir%
