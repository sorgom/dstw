//  ============================================================
//  test of NtpArray / NtpIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/NtpArray.h>

namespace test
{

    TEST_GROUP_BASE(BAS_02, TestGroupBase) {};

    //  test type: equivalence class test
    TEST(BAS_02, T01)
    {
        // cout << endl;
        // TestSteps::show(1);
        SETUP()
        NtpArray<CAPACITY_DSP> data;
        NtpIndex<CAPACITY_DSP> indx(data);
        L_CHECK_EQUAL(CAPACITY_DSP, data.capacity())
        
        const size_t tSize = 10;
        const size_t tOffs = tSize - 1;

        STEP(1)
        SUBSTEPS()
        for (UINT16 i = 0; i < tSize; ++i)
        {
            LSTEP(i)
            data.add(genComName(tOffs - i), 100 + i, i);
        }
        ENDSTEPS()

        STEP(2)
        indx.index();
        STEP(3)
        SUBSTEPS()
        for (UINT16 i = 0; i < tSize; ++i)
        {
            LSTEP(i)
            const ComName& cn = genComName(tOffs - i);
            const PosRes f = indx.find(cn);
            L_CHECK_TRUE(f.valid)
            L_CHECK_EQUAL(tOffs -i, f.pos)
            const bool eq = cn == indx.get(f).name;
            L_CHECK_TRUE(eq)
        }
        ENDSTEPS()
    }

} // namespace
