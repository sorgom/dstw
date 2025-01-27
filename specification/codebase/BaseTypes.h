//  ============================================================
//  basic integral types
//  ============================================================
//  created by Manfred Sorgo

#ifndef BASETYPES_H
#define BASETYPES_H

#include <cstdint>

using UINT8  = uint8_t;
using BYTE   = UINT8;
using UINT16 = uint16_t;
using UINT32 = uint32_t;
using UINT64 = uint64_t;

using INT8  = int8_t;
using INT16 = int16_t;
using INT32 = int32_t;
using INT64 = int64_t;

using CHAR = char;
using PTR  = void*;
using CPTR = const void*;
using C_STRING = CHAR*;
using CONST_C_STRING = const CHAR*;

#ifndef _MSC_VER
using std::size_t;
#endif

template <size_t N>
using ByteArray = UINT8[N];

template <typename NUM>
using ByteArrayFor = ByteArray<sizeof(NUM)>;

#endif // _H
