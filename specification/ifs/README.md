## directory content

**DataTypes.h**
```
definiton of complex data types
- mainly communication telegrams
```

**I_Com.h**
```
Interface Com
- field and GUI communication device
```

**I_Dispatcher.h**
```
interface Dispatcher

when loading project data
subsystems assign themselves with:
- element name
- subsystem id
- own processing element position
and shall receive:
- dispatcher id

field states shall be dispatched to subsystems

GUI commands shall be dispatched to subsystems

commands from subsystems shall be dispatched to field

states from subsystems shall be dispatched to GUI
```

**I_LCR.h**
```
interface LCR (level crossing)
```

**I_LCR_Hub.h**
```
interface LCR_Hub
```

**I_LCR_Provider.h**
```
interface LCR_Provider
```

**I_Loader.h**
```
interface Loader
the Loader is called at system start and shall:
-   reset I_Dispatcher
-   distribute load to subsystems
-   call indexing of I_Dispatcher
```

**I_Log.h**
```
interface Log
- runtime error logging
```

**I_SIG.h**
```
interface SIG (signal)
```

**I_SIG_Hub.h**
```
interface SIG_Hub
```

**I_SIG_Provider.h**
```
interface SIG_Provider
```

**I_TSW.h**
```
interface TSW (track switch)
```

**I_TSW_Hub.h**
```
interface TSW_Hub
```

**I_TSW_Provider.h**
```
interface TSW_Provider
```

**ProjData.h**
```
projectation data types
```

**SystemEnums.h**
```
system wide enumerations
-   E_Subsys subsystems
-   E_mod    modules
-   E_Err    errors
```
