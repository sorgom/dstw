## directory content

#### ComTypes.h
```
communication telegram types
```

#### CompEnums.h
```
component specific enumerations

SIG types and states

TSW commands and states

TSW types and states
```

#### I_Com.h
```
Interface Com
- field and GUI communication device
```

#### I_Dispatcher.h
```
interface Dispatcher

when loading project data
components providers (TSW, SIG, LCR, SEG)
assign themselves with:
- element name
- component id
- own processing element position
and shall receive:
- dispatcher id (position of responsible dispatcher element)

field telegrams shall be dispatched to components

GUI telegrams shall be dispatched to components

field telegrams from components shall be dispatched to field

GUI telegrams components shall be dispatched to GUI
```

#### I_Elem.h
```
interface Elem
processing:
- GUI telegrams
- field telegrams
```

#### I_Hub.h
```
interface Hub and derived interfaces:
- I_TSW_Hub
- I_SIG_Hub
- I_LCR_Hub
```

#### I_Log.h
```
interface Log
- runtime error logging
```

#### I_Provider.h
```
interface Provider and derived interfaces:
- I_TSW_Provider
- I_SIG_Provider
- I_LCR_Provider
```

#### I_Reader.h
```
interface Reader
the Reader is called at system start and shall:
-   clear I_Dispatcher
-   read proj data from binary file
-   distribute load to subsystems
-   call indexing of I_Dispatcher
```

#### PosRes.h
```
defintion of position result
```

#### ProjItem.h
```
unified proj data item
```

#### SystemEnums.h
```
system wide enumerations
-   E_Comp  components
-   E_Mod   modules
-   E_Err   errors
```
