//  ============================================================
//  test of NcpIndex
//  - should also cover all methods of container class Index
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/NcpIndex.h>

namespace test
{

    TEST_GROUP_BASE(BAS_02, TestGroupBase) {};

    //  test type: equivalence class test
    //  add and find data
    TEST(BAS_02, T01)
    {
        NcpIndex indx;
        
        const UINT8 tSize = 10;
        const UINT8 tOffs = tSize - 1;

        STEP(1)
        for (UINT8 n = 0; n < tSize; ++n)
        {
            indx << Ncp(genComName(tOffs - n), n, n);
        }

        STEP(2)
        {
            const auto ok = indx.index();
            L_CHECK_TRUE(ok)
        }

        STEP(3)
        SUBSTEPS()
        for (UINT8 n = 0; n < tSize; ++n)
        {
            LSTEP(n)
            const auto& cn = genComName(tOffs - n);
            const auto fnd = indx.find(cn);
            L_CHECK_TRUE(fnd.valid)
            L_CHECK_EQUAL(static_cast<size_t>(tOffs - n), fnd.pos)
            const bool eq = (cn == indx.at(fnd).name);
            L_CHECK_TRUE(eq)
        }
        ENDSTEPS()
    }

    //  test type: equivalence class test
    //  search for non-existing data
    //  after successful index
    TEST(BAS_02, T02)
    {
        NcpIndex indx;
        
        // no data added
        STEP(1)
        {
            const auto ok = indx.index();
            L_CHECK_TRUE(ok);
            const auto fnd = indx.find(genComName(1));
            L_CHECK_FALSE(fnd.valid)
        }

        // add data 0 .. 19
        // index & find 20
        STEP(2)
        for (UINT8 n = 0; n < 10; ++n)
        {
            indx 
                << Ncp(genComName(n), n, n)
                << Ncp(genComName(n + 10), n, n);
        }
        {
            const auto ok = indx.index();
            L_CHECK_TRUE(ok);
            const auto fnd = indx.find(genComName(20));
            L_CHECK_FALSE(fnd.valid)
        }
    }
    //  test type: equivalence class test
    //  failure of index due to duplicate data
    TEST(BAS_02, T03)
    {
        NcpIndex indx;
        
        // no data added
        STEP(1)
        indx 
            << Ncp(genComName(1), 1, 1)
            << Ncp(genComName(1), 2, 3)
        ;
        const auto ok = indx.index();
        L_CHECK_FALSE(ok);
    }
} // namespace
