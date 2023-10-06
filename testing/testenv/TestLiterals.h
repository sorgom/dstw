//! @file
//! @brief      central string literals register
//!
//! @author     SOM, Manfred Sorgo, manfred.sorgo.ext@siemens.com
//!
//! @reviewer   SRM, Martin Schneider, martin.sm.schneider@siemens.com
//!
//! @copyright (c) Siemens Mobility AG 2020 all rights reserved confidential
//!
//! Change History
//! @date 2019-06-14 SOM: creation of file
//! @date 2020-06-24 SRM: review ok

#ifndef TESTLIB_LITERALS_H
#define TESTLIB_LITERALS_H

//! @(#)e579f5ced2e7d93b123e7f410a0f82e9 2021-08-23 13:05:47 Literals.h >

#include <baselib/BaseTypes.h>

namespace test
{
    extern const CONST_C_STRING c__expected;
    extern const CONST_C_STRING c__actual;
    extern const CONST_C_STRING c__matched;
    extern const CONST_C_STRING c__line;
    extern const CONST_C_STRING c__file;
    extern const CONST_C_STRING c__func;
    extern const CONST_C_STRING c__missing_comparator;
    extern const CONST_C_STRING c__not_implemented;
    extern const CONST_C_STRING c__byte_allocation_error;
} // namespace

#endif // _H
