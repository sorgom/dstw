## directory content

#### build.sh
```
build all major makes parallelly
options:
-c  clean ignored artifacts before
-p  premake5 makefiles
-r  run all binaries
-h  this help
```

#### bullseye.sh
```
bullseye coverage output
```

#### checkEnv.sh
```
check for availability of tools
```

#### premake5.lua
```
premake5 build rules for gcc (gmake2):

> dstw.make
data generator and application runtime

> tests.make
app and tests at once runtime
->  bin/tests_{config}
configurations:
- ci        module tests
- qnd       module tests with devel includes
- dev       developer tests
- bullseye  module tests with bullseye coverage
- none      no tests

> coverage.make
-   coverage instrumented application (static lib)
-   module tests only runtime
->  bin/coverage_tests_{config}
configurations:
- ci        module tests
- dev       developer tests

> systests.make
-   application without test includes (static lib)
-   system tests only runtime
->  bin/sysests_tests_{config}
configurations:
- ci        module tests
- qnd       with devel includes
```

#### premake5_settings.lua
```
common premake5 build settings gcc & VS
```

#### premake5_vs.lua
```
premake5 build rules for VS

general setup
warning level: 4 (high)
multi processor build

suppressed warnings application:
-   4100 unreferenced formal parameter
-   4103 change of alignement with header inclusion
    this is intended behaviour of packBegin.h / packEnd.h
additional suppressed warnings test code:
-   4127 suggested 'if constexpr'
    warning caused by CppUTest headers code

> tests.sln
module tests and system tests at once runtime
including CppUTest sources
->  exe/tests.exe
configurations:
- ci        module and system tests
- sys       system tests
- dev       developer tests

> gendata.sln
generate proj data for application runtime
->  exe/gendata.exe

> dstw.sln
application runtime
->  exe/dstw.exe
```

#### runGcov.sh
```
run coverage using gcov
```
