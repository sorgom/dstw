## directory content

**DataTypes.h**
```
definiton of complex data types
- mainly communication telegrams
```

**I_Dispatcher.h**
```
interface Dispatcher

    //  when loading project data
    //  subsytems assign themselfs with:
    //  - element name
    //  - subsystem id
    //  - own processing element position
    //  and shall recieve:
    //  - dispatcher id
    //  ============================================================
    virtual INT32 assign(const ElementName& name, E_Subsys subs, UINT32 pos) = 0;

    virtual bool label(ElementName& name, UINT32 id) const = 0;


    virtual bool dispatch(const FldState& tele) const = 0;

```

**I_FldCom.h**
```
Interface FldCom
- field communication device
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
interface SIG
```

**I_SIG_Hub.h**
```
interface SIG_Hub
```

**I_TSW.h**
```
interface TSW
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
-   E_Result commonly used result type
-   E_Subsys subsytems
```
