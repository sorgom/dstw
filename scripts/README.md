## directory content

**buildAll.sh**
```
all build steps
- clean everything
- generate Makefile
- build all versions:
    - module tests
    - coverage
```

**cleanMdj.py**
```
put line breaks into mdj files
to create smaller git diffs
```

**cleanSvg.py**
```
clean SVG files from UNREGISTERED background
also put line breaks behind tags
to create smaller git diffs
```

**cleanTests.sh**
```
clean all build artifacts
```

**makeApp.sh**
```
build application library from Makefile
```

**makeGcov.sh**
```
build coverage tests from Makefile
- see also projectGcov.py
```

**makeTests.sh**
```
build module tests from Makefile
- see also runTests.sh
```

**modCloc.py**
```
application of cloc tool for C++ lines of code
- writes CLOC.md
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

**premake.sh**
```
re-build Makefiles
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
