## directory content

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

> devtests.make
development only tests
->  bin/devtests
```
