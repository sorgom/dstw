//  ============================================================
//  begin of packed alignment for data structs
//  ============================================================
//  created by Manfred Sorgo

#ifndef PACKBEGIN_H
#define PACKBEGIN_H
#endif // _H

//! check if we have an nested Pack definition
#ifdef IS_PACKED
    #error Nested use of PackBegin.h (probably missing #include "packEnd.h")
#else
    //  this works with GCC and VS
    #pragma pack (push, 1)
    #define IS_PACKED
#endif
