@echo off
if "%_me%" == "" exit /b 1
rem ========================================================================
rem Bullseye coverage: reporting
rem ========================================================================

if %_update% == 1 exit /b 0

set covMin=%minFunctionCov%,%minDecisionCov%

call covselect -qd
call covselect -q --import %excludeFile%

if %_genhtml% == 1 (
    echo - html
    call covhtml -q --allNum %covHtmlDir%
)

echo - report

cd %dstwDir%
call covdir -q --by-name --srcdir . | tee %covLog%

set _result=failed
call covdir -q --checkmin %covMin%
if %errorlevel% == 0 set _result=passed
echo covmin %covMin% %_result% | tee -a %covLog%
