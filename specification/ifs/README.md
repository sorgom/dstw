## directory content

#### DataTypes.h
```
structured data types

- communication telegrams

- project items

- result of a find operation
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

field state telegrams shall be dispatched to components

GUI command telegrams shall be dispatched to components

element commands shall be dispatched to field

element states shall be dispatched to GUI
```

#### I_Elem.h
```
interface Elem
processing:
- commands from GUI
- states from field
```

#### I_Log.h
```
interface Log
- runtime error logging
```

#### I_Provider.h
```
interface Provider
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

#### SystemEnums.h
```
system wide enumerations
-   E_Comp  components
-   E_Err   errors
```

#### values.h
```
system wide specified values

- component identifiers

- return types

- parameter values

- SIG types and states

- TSW commands and states

- LCR types and states
```
