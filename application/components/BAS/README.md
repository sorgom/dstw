## directory content

**BaseTypes.h**
```
basic integral types and limits
```

**I_Searchable.h**
```
defintion of interface I_Searchable to apply:
- bubble sort
- b-tree search
- uniqueness check / duplicates count
```

**InstanceMacros.h**
```
instance declaration & definiton macros
```

**Mem.h**
```
type safe memset & memcpy
```

**NtpArray.h**
```
Storage of Name Type Position
```

**StackArray.h**
```
the core of static memory allocation
StackArrays
-   act like arrays of pre-defined size
-   can be filled with objects at runtime
-   do not provide any overflow protection

SimpleStackArray
keeps objects in the same order as they were added.

StackArray
-   can be sorted
-   can search for elements
Derived classes have to provide
the isGreater method for objects of their type
See interface I_Searchable

class CRef
enables to store references as objects

StackArrayIndex
provides search for unsorted SimpleStackArray.
Derived classes have to provide
the isGreater method for objects of their type
See interface I_Searchable
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
