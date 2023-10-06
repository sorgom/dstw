//! @file
//! @brief      minimal type definitions
//!
//! @author     Manfred Sorgo, ms@sorgo.de
//!
//!

#ifndef BASETYPES_H
#define BASETYPES_H

#include <ciso646>

typedef unsigned char UINT8;

#ifdef USE_OLD_TYPES
    typedef UINT8 BYTE;
#endif

typedef unsigned short UINT16;
typedef unsigned long UINT32;

#if defined(IARCOMPILED) or defined(__IAR_SYSTEMS_ICC__)
    #pragma language = save
    #pragma language = extended
#endif
typedef unsigned long long UINT64;
#if defined(IARCOMPILED) or defined(__IAR_SYSTEMS_ICC__)
    #pragma language = restore
#endif

typedef signed char INT8;
typedef signed short INT16;
typedef signed long INT32;

#if defined(IARCOMPILED) or defined(__IAR_SYSTEMS_ICC__)
    #pragma language = save
    #pragma language = extended
#endif
typedef signed long long INT64;
#if defined(IARCOMPILED) or defined(__IAR_SYSTEMS_ICC__)
    #pragma language = restore
#endif

typedef char CHAR;

typedef void* PTR;

typedef const void* CPTR;

typedef CHAR* STRPTR;

typedef const CHAR* CONSTSTRPTR;
typedef const CHAR* CONST_C_STRING;

typedef bool BOOL;

// #ifndef size_t
// typedef unsigned int size_t;
// #endif

#endif // _H
