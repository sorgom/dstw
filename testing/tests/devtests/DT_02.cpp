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

    //  ostreams
    TEST(DT_02, T01)
    {
        STEP(1)
        ElementName fn = {{ '0', '1', '2', '3', '4', '5', '6', '7', '8' }};

        std::ostringstream os;
        os << fixC(fn.chars);
        STRCMP_EQUAL("012345678", os.str().c_str());

        STEP(2)
        fn.chars[4]  = 0;
        fn.chars[7] = 127;
        os.str("");
        os << fixC(fn.chars);
        STRCMP_EQUAL("0123*56*8", os.str().c_str());
    }

}
