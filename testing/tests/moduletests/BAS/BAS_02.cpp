//  ============================================================
//  test of NtpIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/NtpIndex.h>

namespace test
{

    TEST_GROUP_BASE(BAS_02, TestGroupBase) {};

    //  test type: equivalence class test
    TEST(BAS_02, T01)
    {
        // cout << endl;
        // TestSteps::show(1);
        SETUP()
        NtpIndex indx;
        
        const UINT8 tSize = 10;
        const UINT8 tOffs = tSize - 1;

        STEP(1)
        SUBSTEPS()
        for (UINT8 n = 0; n < tSize; ++n)
        {
            LSTEP(n)
            indx << Ntp(genComName(tOffs - n), n, n);
        }
        ENDSTEPS()

        STEP(2)
        indx.index();
        STEP(3)
        SUBSTEPS()
        for (UINT8 n = 0; n < tSize; ++n)
        {
            LSTEP(n)
            const ComName& cn = genComName(tOffs - n);
            const PosRes f = indx.find(cn);
            L_CHECK_TRUE(f.valid)
            L_CHECK_EQUAL(static_cast<size_t>(tOffs - n), f.pos)
            const bool eq = cn == indx.at(f).name;
            L_CHECK_TRUE(eq)
        }
        ENDSTEPS()
    }

} // namespace
