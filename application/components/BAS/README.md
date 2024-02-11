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

InterfaceArray
-   stores objects that implement an interface class
-   keeps objects in the same order as they were added
-   provides const and non const object access

ConstArray
- keeps objects in the same order as they were added
- stores objects of one class
- provides const object access only

MutableArray
- keeps objects in the same order as they were added
- stores objects of one class
- provides const and mutable object access

class CRef
enables to store references as objects

ConstArrayIndex
provides search for unsorted ConstArray
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
