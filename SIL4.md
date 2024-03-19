# Meeting SIL4 (Safety Integrity Level 4)
EN 50128 / EN 50129 

## GitLab process
### Peer review
Sources cannot be merged into a dev branch without a peer review.

### Continuous integration CI
Sources must pass continuous integration before a merge is permitted:
-   build
-   run tests
-   static code analysis
-   code coverage by tests

## Static code analysis (SCA)
### Cppcheck
Cppcheck is a free tool for SCA.
The free base version does not detect many coding errors.
But cppcheck can be extended by commercial _premium_ packages
as for example Cert C++.

### Compiler flags
The gcc compiler itself turned out to be a very strong SCA tool with the appropriate flags set:
-pedantic-errors 
-Werror 
-Wall

|Flag|Effect|
|----|----|
|-pedantic-errors|self explaining|
|-Werror|tread warnings as errors|
|-Wall|do not suppress any warning|

## Code coverage
### Gcov
