## directory content

**ci.py**
```
run code checker if available
* experimental *
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

**genCode.py**
```
code automatization of this project
```

**mdjStateCharts.py**
```
extract state transitions from StarUML state charts
and generate md test steps
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

**modMdTable.py**
```
simple md table generator
- numeric align right
- alpha   align left
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

**modTransCsv.py**
```
process csv transition tables
-   generate md tables
-   generate test code
```

**modTransTable.py**
```
generate transition tables from transition lists
-   for other generators
-   as md output
```

**modUtilz.py**
```
some commonly used features
```

**preCommit.py**
```
all pre-commit script calls in one
```

**projectDirs.py**
```
directories of this project in git
```

**runGcov.py**
```
code gcov coverage of this project
```

**srcNums.py**
```
simple line numbering for source sample markups
```
