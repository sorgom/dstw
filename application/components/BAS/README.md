## directory content

**BaseTypes.h**
```
basic integral types and limits
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

**StackArray.h**
```
the core of static memory allocation
StackArrays
-   act like arrays of pre-defined size
-   can be filled with objects at runtime
-   do not provide any overflow protection

StackArray
keeps objects in the same order as they were added.

SortableStackArray
-   can be sorted
-   can search for elements
Derived classes have to provide
the isGreater method for objects of their type
See interface I_Array

class CRef
enables to store references as objects

StackArrayIndex
provides search for unsorted StackArray.
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
