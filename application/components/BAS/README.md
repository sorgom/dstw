## directory content

**I_Array.h**
```
defintion of interface I_Array:
enables:
- bubble sort
- b-tree search
- uniqueness check / duplicates count
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
    derived from main class
-   do not provide any overflow protection

StaticArray
keeps objects in the same order as they were added.

class CRef
enables to store references as objects

StaticIndex
provides search for unsorted StaticArray.
```

**SwapBytes.h**
```
class SwapBytes enables static byte swapping
(no memory reallocation)
```

**coding.h**
```
misc coding enhancers
```
