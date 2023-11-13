## directory content

**buildAll.sh**
```
build all major makes parallelly
options:
-r  remove all artifacts before
-x  execute all binaries
-h  this help
```

**bullseye.sh**
```
bullseye coverage output
```

**premake5.lua**
```
Makefile build rules for premake5:

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
