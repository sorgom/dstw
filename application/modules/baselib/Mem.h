//! @file
//! @brief      cstring (memset / memcpy) shortcut templates for size safety
//!
//! @author     SOM, Manfred Sorgo, manfred.sorgo.ext@siemens.com
//!
//! @reviewer   TODO: assign reviewer
//!
//! @copyright (c) Siemens Mobility AG 2020 all rights reserved confidential
//!
//! Change History
//! @date 2019-10-31 SOM: creation of file
//! @date 2020-06-18 SRM: review performed
//! @date 2020-07-29 SRM: review ok

#ifndef BASELIB_MEM_H
#define BASELIB_MEM_H

//! @(#)97f5464b17ca3d9ad7a2d92662aabecb 2021-08-23 13:05:33 Mem.h >

#include <baselib/BaseTypes.h>

#include <cstring>

namespace baselib
{
    //! static methods provider class
    class Mem
    {
    public:
        //! memset a data object with given byte
        //! @param ptr pointer to data object
        //! @param b   byte to set
        template <class T>
        inline static void set(T* ptr, UINT8 b = 0)
        {
            std::memset(ptr, b, sizeof(T));
        }

        //! memset a data object with given byte
        //! @param ref reference to data object
        //! @param b   byte to set
        template <class T>
        inline static void set(T& ref, UINT8 b = 0)
        {
            std::memset(&ref, b, sizeof(T));
        }

        //! set all bytes of a data object to zero
        //! @param ptr pointer to data object
        template <class T>
        inline static void zero(T* ptr)
        {
            std::memset(ptr, 0, sizeof(T));
        }

        //! set all bytes of a data object to zero
        //! @param ref reference to data object
        template <class T>
        inline static void zero(T& ref)
        {
            std::memset(&ref, 0, sizeof(T));
        }

        //! copy bytes from source to data object
        //! @param ptr pointer to data object
        //! @param src source pointer
        template <class T>
        inline static void copy(T* ptr, const CPTR src)
        {
            std::memcpy(ptr, src, sizeof(T));
        }

        //! copy bytes from source data object to target data object
        //! @param ref reference to target data object
        //! @param src reference to source data object
        template <class T>
        inline static void copy(T& ref, const T& src)
        {
            std::memcpy(&ref, &src, sizeof(T));
        }
    };
} // namespace
#endif // _H
