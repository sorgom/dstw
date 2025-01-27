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
set buildDir=%cd%\build
set subsDir=%cd%\submodules
set ReportsDir=%cd%\reports
set myReportsDir=%reportsDir%\%_me%

set pyDir=%subsDir%\sompy
set vsSolution=%makeDir%\DSTW.sln
set exeDir=%buildDir%\windows
set buildLog=%myReportsDir%\build.txt
set covLog=%myReportsDir%\coverage.txt
set covHtmlDir=%myReportsDir%\html
set testReport=%myReportsDir%\test_errors.txt

set covcopt=--srcdir %dstwDir% --macro
set covfile=%reportsDir%\%_me%.cov
set excludeFile=%myDir%\_covexclude.txt
set covTodoTxt=%buildDir%\%_me%_todo.txt

set optsTxt=%myDir%\_covoptions.txt
set vsCall=msbuild %vsSolution%
set tmpCmd=%buildDir%\tmp.cmd
set projFile=dstw.proj

md %buildDir% >NUL 2>&1
