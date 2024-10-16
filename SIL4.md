# meeting SIL4 (safety integrity level 4)
EN 50128 / EN 50129

## gitLab / github process
### peer review
Sources cannot be merged into a dev branch without a peer review.

### continuous integration CI
Sources must pass continuous integration before a merge is permitted:
-   build
-   run tests
-   static code analysis
-   code coverage by tests

## static code analysis (SCA)
### cppcheck
Cppcheck is a free tool for SCA.
The free base version does not detect many coding errors.
But cppcheck can be extended by commercial _premium_ packages
as for example Cert C++.

### compiler flags gcc
The gcc compiler itself turned out to be a very strong SCA tool with the appropriate flags set (C++ 2017):

-std=c++17 -pedantic-errors -Werror -Wall

|Flag|Effect|
|----|----|
|-pedantic-errors|self explaining|
|-Werror|tread warnings as errors|
|-Wall|do not suppress any warning|

### compiler flags VS
Visual Studio turned out to be an even more pedantic code analyzer with the right options set:

/std:c++17 /MP /W4

|Flag|Effect|
|----|----|
|/W4|highest warning level|
|/MP|multi processor build|

Additional flags see header of [premake5_vs.lua](make/premake5_vs.lua)

## code coverage
Application code coverage by tests must be 100%.

See also [code coverage tools](testing/coverage_tools.md)
