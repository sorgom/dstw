## directory content

**buildTests.sh**
```
all build steps
- clean everything
- generate Makefile
- build all versions:
    - module tests
    - coverage
```

**cleanTests.sh**
```
clean all build artifacts
```

**makeTests.sh**
```
build module tests from Makefile
- see also runTests.sh
```

**modGcov.py**
```
application of gcov tool
- run instrumented binary
- invoke gcov
- analyze *.gcov files of cpp sources
```

**modGenCode.py**
```
simple code generator features
```

**modGenMd.py**
```
simple md generator
```

**modRunTests.py**
```
run CppUTest tests
- run test binary
- output to report text
- count failures reported
```

**modScanCode.py**
```
simple code scanner for code generator features
- application instance declarations for ddi
- mocks
- data structs
- interface declarations
- ostream specializations
```

**modUtilz.py**
```
some commonly used features
```

**projectCode.py**
```
code automatization of this project
```

**projectDirs.py**
```
directories of this project in git
```

**projectGcov.py**
```
code coverage of this project
```

**projectRunTests.py**
```
module test analyzis of this project
```

**runTests.sh**
```
run module tests of this project
- see makeTests.sh
```
