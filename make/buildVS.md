# Visual Studio build
## preconditions
- premake5 available
- Visual Studio

## 1) generate VS solution using premake5
### 1.1) find out suitable VS version using premake5 --help

````shell
$> premake5 --help
Usage: premake5 [options] action [arguments]

OPTIONS - General
 --file=FILE         Read FILE as a Premake script; default is 'premake5.lua'

ACTIONS
 vs2005            Generate Visual Studio 2005 project files
 vs2008            Generate Visual Studio 2008 project files
 vs2010            Generate Visual Studio 2010 project files
 vs2012            Generate Visual Studio 2012 project files
 vs2013            Generate Visual Studio 2013 project files
 vs2015            Generate Visual Studio 2015 project files
 vs2017            Generate Visual Studio 2017 project files
 vs2019            Generate Visual Studio 2019 project files
 vs2022            Generate Visual Studio 2022 project files
````
### 1.2) generate solution with your VS version
e.g. VS 2019
````shell
$> premake5 --file=premake5_vs.lua vs2019
Building configurations...
Running action 'vs2019'...
Generated cpputest.sln...
Generated cpputest.vcxproj...
Generated cpputest.vcxproj.filters...
Generated tests.sln...
Generated tests.vcxproj...
Generated tests.vcxproj.filters...
Generated dstw.sln...
Generated dstw.vcxproj...
Generated dstw.vcxproj.filters...
Done (130ms).
````
## 2) build executables in VS
### 2.1) build and run module tests
- open and build _cpputest.sln_
- open and build _tests.sln_
- run executable

### 2.2) build and run application
- open and build _gendata.sln_
- run executable
- open and build _dstw.sln_
- run executable
