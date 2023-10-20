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
    //  and recieve:
    //  - dispatcher id
    //  ============================================================
    virtual INT32 assign(const ElementName& name, E_Subsys subs, UINT32 pos) = 0;
```

**I_FldCom.h**
```
Interface FldCom
- field communication device
```

**I_Signal.h**
```
interface Signal
```

**I_SignalPort.h**
```
interface SignalPort
```

**I_TrackSwitch.h**
```
interface TrackSwitch
```

**I_TrackSwitchProvider.h**
```
interface TrackSwitchProvider
```

**I_TrackSwitchHub.h**
```
interface TrackSwitchHub
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
