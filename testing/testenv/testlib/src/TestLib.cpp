#include <testlib/TestLib.h>

#include <cstdio>
#include <BAS/Mem.h>
#include <cstring>
namespace test
{

    const ElementName& genElementName(const UINT32 num, const CONST_C_STRING name)
    {
        static ElementName eName;
        Mem::set(eName.chars, ' ');
        CHAR buf[sizeof(ElementName) + 1];
        const int sz = std::snprintf(buf, sizeof(buf), "%s %03u ", name, num);
        if (sz > 0)
        {
            std::memcpy(eName.chars, buf, sz - 1);
        }
        return eName;
    }

    

} // namespace