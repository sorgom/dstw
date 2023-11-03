#include <testlib/TestLib.h>

#include <cstdio>
#include <BAS/Mem.h>

namespace test
{

    const ElementName& genElementName(const UINT32 num, const CONST_C_STRING name)
    {
        static ElementName eName = {{""}};
        Mem::zero(eName);
        Mem::set(eName, 0);
        std::sprintf(eName.chars, "%s %03u ", name, num);
        return eName;
    }
    void genElementName(ElementName& eName, const UINT32 num, const CONST_C_STRING name)
    {
        Mem::cpy(eName, genElementName(num, name));
    }

    

} // namespace