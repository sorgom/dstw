# component BAS
**commonly used basic features**

## directory content

#### BAS_Provider.h
```
class BAS_Provider: base class to implement I_Provider
- provides everything to satisfy
  an I_Provider derived interface
- except the load method which is too specific
```

#### Containers.h
```
container collection

class PolyVec allows to store polymorphic objects
derived from interface class IF

class Index allows to
- store const CONT objects with KEY type member
  in the order that the were added
- index and find objects by KEY type
requires operator > (KEY a, KEY b) to be defined
```

#### NcpIndex.h
```
name, component, position

class NcpIndex is the core of Dispatcher
see interface I_Dispatcher
```

#### coding.h
```
misc coding enhancers
```
