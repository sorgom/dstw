@echo off
if "%_me%" == "" exit /b 1
rem ========================================================================
rem Bullseye coverage: reporting
rem ========================================================================

if exist %testReport% (
    echo - test errors
    cat %testReport%
    exit /b 1
)

if %_update% == 1 exit /b 0

set covMin=%minFunctionCov%,%minDecisionCov%

call covselect -qd
call covselect -q --import %excludeFile%

if %_genhtml% == 1 (
    echo - html
    call covhtml -q --allNum %covHtmlDir%
)

echo - report

echo ### %_me% %DATE% %TIME% > %covLog%
echo ``` >> %covLog%
cd %dstwDir%
call covdir -q --by-name --srcdir . >> %covLog%

set _result=failed
call covdir -q --checkmin %covMin%
if %errorlevel% == 0 set _result=passed
echo covmin %covMin% %_result% >> %covLog%
echo ``` >> %covLog%
cat %covLog%
