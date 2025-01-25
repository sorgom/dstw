//  ============================================================
//  network (big endian) byte order conversion
//  see: https://en.wikipedia.org/wiki/Endianness
//  ============================================================
//  created by Manfred Sorgo
#ifndef NET_H
#define NET_H

#include <codebase/BaseTypes.h>

#ifdef _WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#endif

namespace Net
{
    inline UINT16 toN(const UINT16 h)
    {
        return htons(h);
    }
    inline UINT16 toH(const UINT16 n)
    {
        return ntohs(n);
    }

    inline UINT32 toN(const UINT32 h)
    {
        return htonl(h);
    }
    inline UINT32 toH(const UINT32 n)
    {
        return ntohl(n);
    }

    inline INT16 toN(const INT16 h)
    {
        return static_cast<INT16>(toN(static_cast<const UINT16>(h)));
    }
    inline INT16 toH(const INT16 n)
    {
        return static_cast<INT16>(toH(static_cast<const UINT16>(n)));
    }

    inline INT32 toN(const INT32 h)
    {
        return static_cast<INT32>(toN(static_cast<const UINT32>(h)));
    }
    inline INT32 toH(const INT32 n)
    {
        return static_cast<INT32>(toH(static_cast<const UINT32>(n)));
    }

} // namespace

#endif // _H
