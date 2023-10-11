#include <testlib/CppUTest.h>
#include <testlib/TestGroupBase.h>

#include "TestPack.h"

namespace test
{

    TEST_GROUP_BASE(BT_01, TestGroupBase)
    {
        
    };

    TEST(BT_01, T01)
    {
        STEP(1)
        CHECK_EQUAL(2 * sizeof(UINT32), sizeof(Unpacked));

        STEP(2)
        CHECK_EQUAL(sizeof(UINT32) + sizeof(UINT8), sizeof(Packed));

        CHECK_N_CLEAR()
    }
    
    // IGNORE_TEST(BT_01, T02)
    // {
    //     STEP(1)
    //     CHECK_N_CLEAR()
    // }
}