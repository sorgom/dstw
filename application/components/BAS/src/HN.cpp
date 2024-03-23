#include <BAS/HN.h>
// #include <bit>

#ifdef _WIN32
#include <winsock.h>
#else
#include <arpa/inet.h>
#endif

UINT32 HN::toN(const UINT32 val)
{
    return htonl(val);
}

UINT32 HN::toH(const UINT32 val)
{
    return ntohl(val);
}

UINT16 HN::toN(const UINT16 val)
{
    return htons(val);
}

UINT16 HN::toH(const UINT16 val)
{
    return ntohs(val);
}
