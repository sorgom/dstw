## directory content

**DataTypes.h**
```
definiton of complex data types
- mainly communication telegrams
```

**I_Dispatcher.h**
```
interface Dispatcher

when loading project data
subsytems assign themselfs with:
- element name
- subsystem id
- own processing element position
and shall recieve:
- dispatcher id

when sending telegrams
subsytems shall retieve the assigned name with:
- dispatcher id returned at assignement

field states shall be dispatched to subsystems

GUI commands shall be dispatched to subsystems
```

**I_FldCom.h**
```
Interface FldCom
- field communication device
```

**I_GuiCom.h**
```
Interface GuiCom
- GUI communication device
```

**I_Loader.h**
```
interface Loader
the Loader is called at sytem start and shall:
-   reset I_Dispatcher
-   distribute load to subsytems
-   call indexing of I_Dispatcher
-   in case of any subsystem load failure
    -   reset I_Dispatcher
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
-   E_Subsys subsytems
```
