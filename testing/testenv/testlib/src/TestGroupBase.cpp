#include <testlib/TestGroupBase.h>

#include <cstdio>
#include <baselib/Mem.h>

namespace test
{

    const ElementName& TestGroupBase::genElementName(const UINT32 num, const CONST_C_STRING name)
    {
        static ElementName eName = {{""}};
        Mem::zero(eName);
        Mem::set(eName, 0);
        std::sprintf(eName.chars + 1, "%s %3u ", name, num);
        return eName;
    }
    void TestGroupBase::genElementName(ElementName& eName, const UINT32 num, const CONST_C_STRING name)
    {
        Mem::copy(eName, genElementName(num, name));
    }

} // namespace