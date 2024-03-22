# component BAS
**commonly used basic features**

## directory content

**HN.h**
```
host and network byte order
```

**I_Array.h**
```
definition of interfaces I_Array / I_SortableArray

I_Array
defines basic const access to an array type

I_SortableArray extends I_Array
to enable:
- bubble sort
- b-tree search
- duplicates count
```

**NtpArray.h**
```
name, type, position

- storage of name, type, position

- index of name, type, position by name
```

**StaticArray.h**
```
collection of static array types
Static arrays
-   act like arrays of pre-defined size
-   can be filled with objects at runtime
-   do not provide any overflow protection
This is not an API
Static arrays defined here are suitable for the application:
-   as flexible as needed
-   as const as possible

InterfaceArray
-   stores objects that implement an interface class
-   keeps objects in the same order as they were added
-   provides const and non const object access

ConstArray
- keeps objects in the same order as they were added
- stores objects of one class
- provides const object access only
- can be indexed

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
