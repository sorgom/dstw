## directory content

**buildAll.sh**
```
build all major makes parallelly
options:
-r  remove all artifacts before
-p  premake5 makefiles
-x  execute all binaries
-h  this help
```

**bullseye.sh**
```
bullseye coverage output
```

**premake5.lua**
```
premake5 build rules for gcc (gmake2):

> tests.make
module tests and system tests at once runtime
->  bin/tests

> coverage.make
-   coverage instrumented application (static lib)
-   module tests only runtime
->  bin/coverage_tests

> dstw.make
application runtime
->  bin/dstw

> _devtests.make
development only tests
->  bin/_devtests

> _bullseye.make
module tests for bullseye coverage
->  bin/_bullseye
```

**premake5_settings.lua**
```
common premake5 build settings gcc & VS
```

**premake5_vs.lua**
```
premake5 build rules for VS

general setup
warning level: 4 (high)

suppressed warnings application:
-   4100 unreferenced formal parameter
-   4103 change of alignement with header inclusion
    this is intended behaviour of packBegin.h / packEnd.h
additional suppressed warnings test code:
-   4127 suggested 'if constexpr'
    warning caused by CppUTest headers code

> cpputest.sln
cpputest library
->  lib/cpputest.lib

> tests.sln
module tests and system tests at once runtime
(requires cpputest.lib)
->  exe/tests.exe

> gendata.sln
generate proj data for application runtime
->  exe/gendata.exe

> dstw.sln
application runtime
->  exe/dstw.exe
```
