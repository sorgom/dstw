//  ============================================================
//  test of NtpArray / NtpIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/NtpArray.h>

namespace test
{

    TEST_GROUP_BASE(BAS_03, TestGroupBase) {};

    //  test type: equivalence class test
    TEST(BAS_03, T01)
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
        for (INT32 i = 0; i < tSize; ++i)
        {
            LSTEP(i)
            data.add(genElementName(tOffs - i), 100 + i, i);
        }
        ENDSTEPS()

        STEP(2)
        indx.index();
        STEP(3)
        SUBSTEPS()
        for (INT32 i = 0; i < tSize; ++i)
        {
            LSTEP(i)
            const ElementName& en = genElementName(tOffs - i);
            const PosRes f = indx.find(en);
            L_CHECK_TRUE(f.valid)
            L_CHECK_EQUAL(tOffs -i, f.pos)
            const INT32 cmp = Mem::cmp(en, indx.get(f).name);
            L_CHECK_EQUAL(0, cmp)
        }
        ENDSTEPS()
    }

} // namespace
