# how to build
## gcc build
### preconditions
- make
- gcc
### use build.sh
call help
````shell
DSTW/make$> ./build.sh -h
````
then call to build and run, e.g.
````shell
DSTW/make$> ./build.sh -cr
````

## Visual Studio build
### preconditions
- [premake5](https://premake.github.io/) available
- Visual Studio

### 1) generate VS solution using premake5
#### 1.1) find out suitable VS version using premake5 --help

````shell
D:\git\DSTW\make> premake5 --help
Usage: premake5 [options] action [arguments]

OPTIONS - General
 --file=FILE         Read FILE as a Premake script; default is 'premake5.lua'

ACTIONS
 vs2005            Generate Visual Studio 2005 project files
 ...
 vs2022            Generate Visual Studio 2022 project files
````
#### 1.2) generate solution with your VS version
e.g. VS 2019
````shell
D:\git\DSTW\make> premake5 --file=premake5_vs.lua vs2019
Building configurations...
Running action 'vs2019'...
Generated tests.sln...
...
Done (143ms).
````
### 2) build executables in VS
#### 2.1) build and run module tests
- open _tests.sln_
- build and run

#### 2.2) build and run application
- open _gendata.sln_
- build and run
- open _dstw.sln_
- build and run

### 3) VS keyboard shortcuts
- build: [CTRL] [shift] [B]
- (build and) run: [CTRL] [F5]
