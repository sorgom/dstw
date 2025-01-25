#ifdef _WIN32

#include <BAS/Net.h>
#include <WinSock.h>

namespace Net
{

    UINT16 toN(const UINT16 h)
    {
        return htons(h);
    }
    UINT16 toH(const UINT16 n)
    {
        return ntohs(n);
    }

    UINT32 toN(const UINT32 h)
    {
        return htonl(h);
    }

    UINT32 toH(const UINT32 n)
    {
        return ntohl(n);
    }

} // namespace

#endif // _WIN32
