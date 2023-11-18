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
        
        Ntp tNtp;
        const UINT32 tSize = 10;
        const UINT32 tOffs = tSize - 1;

        STEP(1)
        SUBSTEPS()
        for (INT32 i = 0; i < tSize; ++i)
        {
            LSTEP(i)
            nameElement(tNtp, tOffs - i);
            tNtp.type = 100 + i;
            tNtp.pos  = i;
            data.add(tNtp);
        }
        ENDSTEPS()

        STEP(2)
        indx.index();
        SUBSTEPS()
        for (INT32 i = 0; i < tSize; ++i)
        {
            LSTEP(i)
            const ElementName& en = genElementName(tOffs - i);
            const INT32 f = indx.findNtp(en);
            L_CHECK_EQUAL(tOffs -i, f)
            const INT32 cmp = Mem::cmp(en, indx.getRef(f).name);
            L_CHECK_EQUAL(0, cmp)
        }
        ENDSTEPS()
    }

} // namespace
