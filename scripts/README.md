## directory content

**TestStepper.py**
```
simple test steps re-numbering script
```

**buildAll.sh**
```
all build steps
- clean everything
- generate Makefile
- build all versions:
    - module tests
    - coverage
```

**ci.py**
```
run code checker if available
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

**dirs.rc**
```
directory listing
```

**genCode.py**
```
code automatization of this project
```

**makeApp.sh**
```
build dstw application from Makefile
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

**modGcov.py**
```
application of gcov tool
- run instrumented binary
- invoke gcov
- analyze *.gcov files of cpp sources
```

**modGenCloc.py**
```
application of cloc tool for C++ lines of code
- writes CLOC.md
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
- application instance declarations for IL
- mocks
- data structs
- interface declarations
- ostream specializations
```

**modUtilz.py**
```
some commonly used features
```

**preCommit.py**
```
all pre-commit script calls in one
```

**premake.sh**
```
re-build Makefiles
```

**projectDirs.py**
```
directories of this project in git
```

**runGcov.py**
```
code coverage of this project
```

**runTests.py**
```
module test analyzis of this project
```

**runTests.sh**
```
run module tests of this project
- see makeTests.sh
```
