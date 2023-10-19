//  ============================================================
//  test of NtpArray / NtpIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <Dispatcher/NtpArray.h>

namespace test
{

    TEST_GROUP_BASE(DSP_01, TestGroupBase) {};

    //  test type: equivalence class test
    TEST(DSP_01, T01)
    {
        // cout << endl;
        // TestStepper::show(1);
        SETUP()
        NtpArray<CAPACITY_ELEMENTS> data;
        NtpIndex<CAPACITY_ELEMENTS> indx(data);
        L_CHECK_EQUAL(CAPACITY_ELEMENTS, data.capacity())
        L_CHECK_EQUAL(CAPACITY_ELEMENTS, indx.capacity())
        
        Ntp tNtp;
        const UINT32 tSize = 10;
        const UINT32 tOffs = tSize - 1;

        STEP(1)
        SUBSTEPS()
        for (INT32 i = 0; i < tSize; ++i)
        {
            LSTEP(i)
            genElementName(tNtp.name, tOffs - i);
            tNtp.type = 100 + i;
            tNtp.pos  = i;
            data.add(tNtp);
        }
        ENDSTEPS()

        STEP(2)
        indx.adapt();
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
