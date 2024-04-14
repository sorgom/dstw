## directory content

#### ComTypes.h
```
communication telegram types
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

field states shall be dispatched to components

GUI commands shall be dispatched to components

commands from components shall be dispatched to field

states from components shall be dispatched to GUI
```

#### I_LCR.h
```
interface LCR (level crossing)
```

#### I_Hub.h
```
interface LCR_Hub
```

#### I_Provider.h
```
interface LCR_Provider
```

#### I_Log.h
```
interface Log
- runtime error logging
```

#### I_Reader.h
```
interface Reader
the Reader is called at system start and shall:
-   reset I_Dispatcher
-   read proj data from binary file
-   distribute load to subsystems
-   call indexing of I_Dispatcher
```

#### I_SIG.h
```
interface SIG (signal)
```

#### I_Hub.h
```
interface SIG_Hub
```

#### I_Provider.h
```
interface SIG_Provider
```

#### I_TSW.h
```
interface TSW (track switch)
```

#### I_Hub.h
```
interface TSW_Hub
```

#### I_Provider.h
```
interface TSW_Provider
```

#### PosRes.h
```
defintion of position result
```

#### ProjTypes.h
```
projectation data types
```

#### SystemEnums.h
```
system wide enumerations
-   E_Comp  components
-   E_Mod   modules
-   E_Err   errors
```
