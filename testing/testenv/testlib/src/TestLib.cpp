#include <testlib/TestLib.h>

#include <cstdio>
#include <codebase/Mem.h>
#include <cstring>
namespace test
{

    const ComAddr& genComAddr(const UINT32 num, const CONST_C_STRING addr)
    {
        static ComAddr cAddr;
        genComAddr(cAddr, num, addr);
        return cAddr;
    }

    void genComAddr(ComAddr& cAddr, UINT32 num, CONST_C_STRING addr)
    {
        std::memset(cAddr.chars, ' ', ComNameSize);
        static CHAR buf[sizeof(ComAddr) + 1];
        const int sz = std::snprintf(buf, sizeof(buf), "%s %03u ", addr, num);
        if (sz > 0)
        {
            std::memcpy(cAddr.chars, buf, sz - 1);
        }
    }
} // namespace
