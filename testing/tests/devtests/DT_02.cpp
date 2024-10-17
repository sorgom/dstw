//  ============================================================
//  test of test features
//  - output of fixed size strings
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

#include <sstream>

namespace test
{

    TEST_GROUP_BASE(DT_02, TestGroupBase) {};

    TEST(DT_02, T01)
    {
        STEP(1)
        CHAR chars[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

        std::ostringstream os;
        os << fixT(chars);
        STRCMP_EQUAL("0123456789", os.str().c_str());

        STEP(2)
        chars[4]  = 0;
        chars[7] = 127;
        os.str("");
        os << fixT(chars);
        STRCMP_EQUAL("0123*56*89", os.str().c_str());
    }
}
