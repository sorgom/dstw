#include <testlib/TestGroupBase.h>

#include <cstdio>
#include <baselib/Mem.h>

namespace test
{

    const ElementName& TestGroupBase::genElementName(const UINT32 num, const CONST_C_STRING name)
    {
        static ElementName eName = {{""}};
        Mem::zero(eName);
        std::sprintf(eName.chars, "%s %04X", name, num);
        return eName;
    }

} // namespace