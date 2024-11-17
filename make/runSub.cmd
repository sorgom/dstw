@echo off
SETLOCAL
set tsfile=%1
call %2 %3 %4 %5 %6 %7 %8 %9
del /Q %tsfile% 2>nul
exit 0
