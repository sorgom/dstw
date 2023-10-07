
#ifndef BASELIB_MEM_H
#define BASELIB_MEM_H

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
