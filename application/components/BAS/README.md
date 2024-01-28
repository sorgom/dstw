## directory content

**BaseTypes.h**
```
basic integral types
```

**I_Array.h**
```
defintion of interface I_Array to apply:
- bubble sort
- b-tree search
- uniqueness check / duplicates count
```

**Mem.h**
```
type safe memset & memcpy
```

**NtpArray.h**
```
name, type, position

- storage of name, type, position

- index of name, type, position by name
```

**StaticArray.h**
```
the core of static memory allocation
StaticArrays
-   act like arrays of pre-defined size
-   can be filled with objects at runtime
-   can store objects of different size classes
    for the same interface
-   do not provide any overflow protection

StaticArray
keeps objects in the same order as they were added.

class CRef
enables to store references as objects

StaticIndex
provides search for unsorted StaticArray.
Derived classes have to provide
the isGreater method for objects of their type
See interface I_Array
```

**coding.h**
```
misc coding enhancers
```

**packBegin.h**
```
begin of packed alignment for data structs
```

**packEnd.h**
```
end of packed alignment for data structs
```
