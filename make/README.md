# how to build and run
## linux make / gcc
### simple make
````shell
DSTW/make$> make clean
DSTW/make$> make -j
````
- find binaries in build/linux/bin folder
````shell
DSTW/make$> cd ../build/linux/bin
DSTW/build/linux/bin$> ls
````
### buildAndRun.sh
````shell
DSTW/make$> ./buildAndRun.sh
````
### run gcov
````shell
DSTW/make$> ./runGcov.sh
````
### buid & run system tests
````shell
DSTW/make$> ./runSystemTests.sh
````
## msbuild / visual studio
- requires [premake5](https://premake.github.io/)

### create solution for your VS version
````shell
DSTW\make> premake5 --help
DSTW\make> premake5 vsNNNN
````
### just build
````shell
DSTW\make> msbuild -m dstw.sln
````
- find binaries in build/windows folder
````shell
DSTW\make> cd ../build/windows
DSTW\build\windows> dir /B *.exe
````
### build & run system tests
````shell
DSTW\make> ./runSystemTests.cmd
````
