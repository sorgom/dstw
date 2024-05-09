# code coverage
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

Sample (and very outdated) text summary output:
```
Source            Function Coverage      C/D Coverage
----------------  -----------------  ----------------
Com.h                3 /   3 = 100%    0 /   0
Dispatcher.cpp       7 /   7 = 100%   20 /  20 = 100%
Dispatcher.h         1 /   1 = 100%    0 /   0
I_Array.h            3 /   3 = 100%   18 /  18 = 100%
LCR_Hub.cpp          4 /   4 = 100%    4 /   4 = 100%
LCR_Hub.h            1 /   1 = 100%    0 /   0
LCR_Provider.cpp     1 /   1 = 100%   15 /  15 = 100%
LCR_Provider.h       3 /   3 = 100%    0 /   0
LCR_X.cpp            9 /   9 = 100%   37 /  37 = 100%
LCR_X.h              7 /   7 = 100%    0 /   0
Loader.cpp           1 /   1 = 100%    0 /   0
Loader.h             1 /   1 = 100%    0 /   0
Log.h                2 /   2 = 100%    0 /   0
Mem.h                4 /   4 = 100%    0 /   0
NtpArray.cpp         1 /   1 = 100%    0 /   0
NtpArray.h           4 /   4 = 100%    0 /   0
SIG_Hub.cpp          4 /   4 = 100%    4 /   4 = 100%
SIG_Hub.h            1 /   1 = 100%    0 /   0
SIG_Provider.cpp     1 /   1 = 100%   16 /  16 = 100%
SIG_Provider.h       3 /   3 = 100%    0 /   0
SIG_X.cpp           18 /  18 = 100%   93 /  93 = 100%
SIG_X.h              9 /   9 = 100%    0 /   0
StackArray.cpp       1 /   1 = 100%    0 /   0
StackArray.h        26 /  26 = 100%    2 /   2 = 100%
TSW.cpp              7 /   7 = 100%   22 /  22 = 100%
TSW.h                1 /   1 = 100%    0 /   0
TSW_Hub.cpp          4 /   4 = 100%    4 /   4 = 100%
TSW_Hub.h            1 /   1 = 100%    0 /   0
TSW_Provider.cpp     1 /   1 = 100%   12 /  12 = 100%
TSW_Provider.h       3 /   3 = 100%    0 /   0
coding.h             1 /   1 = 100%    0 /   0
----------------  -----------------  ----------------
Total              133 / 133 = 100%  247 / 247 = 100%
```
For details see [bullseye html report](http://dstw.sorgo.de/bullseye/)

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
