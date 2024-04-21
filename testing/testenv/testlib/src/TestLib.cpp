#include <testlib/TestLib.h>

#include <cstdio>
#include <codebase/Mem.h>
#include <cstring>
namespace test
{

    const ComName& genComName(const UINT32 num, const CONST_C_STRING name)
    {
        static ComName cName;
        genComName(cName, num, name);
        return cName;
    }

    void genComName(ComName& cName, UINT32 num, CONST_C_STRING name)
    {
        Mem::set(cName.chars, ' ');
        static CHAR buf[sizeof(ComName) + 1];
        const int sz = std::snprintf(buf, sizeof(buf), "%s %03u ", name, num);
        if (sz > 0)
        {
            std::memcpy(cName.chars, buf, sz - 1);
        }
    }
    

} // namespace