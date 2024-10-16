# code coverage tools
## bullseye
Bullseye coverage turned out a most excellent tool.

It analyses:
-   analyses source and header coverage
-   every condition of logical and / or
-   every item of multiple case statement
-   for loops

It can generate several outputs from simple text to html documentation.

It's available for Windows and Linux.

Bullseye is not for free - but they provide a free trial period.

- [current text report](coverage_bullseye.md)
- [sample html report](http://dstw.sorgo.de/bullseye/)

## gcov
Gcov comes with gnu compiler collection (gcc) and therefore is available
-   on a standard linux
-   for the github CI

It
-   provides a very limited impression of the source code coverage
-   is quite useless with headers

It requires explicit _if else_ blocks. Therefore one has to attach an _else_ block with a (dummy) statement to every _if_ block.

sample:
```cpp
    if (mIndx.size() > id)
    {
        tele.name = mIndx.at(id).name;
        IL::getCom().send(tele);
    }
    else
    { pass(); }
```
But this isn't too bad, because some SIL4 coding guidelines require this anyhow.

## sample gcov snapshot
```
(2024-05-09 22:26)
file                      lines  uncovered  percent
BAS/src/BAS_Provider.cpp     26         --       --
COM/src/Com.cpp              62         --       --
COM/src/TCP.cpp              87         --       --
COM/src/TCP_Com.cpp         175         --       --
LCR/src/LCR_Provider.cpp     20         --       --
LCR/src/LCR_X.cpp           126         --       --
SIG/src/SIG_Provider.cpp     23         --       --
SIG/src/SIG_X.cpp           310         --       --
SYS/src/Dispatcher.cpp      138         --       --
SYS/src/Log.cpp               9         --       --
SYS/src/Reader.cpp           70         --       --
TSW/src/TSW.cpp              99         --       --
TSW/src/TSW_Provider.cpp      2         --       --
total                      1147         --       --
```
