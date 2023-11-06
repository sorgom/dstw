//  ============================================================
//  test of GenProjData
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

#define CAPTSW 40
#define CAPSIG 30
#define CAPLCR 20
#define CAPSEG 10

namespace test
{

    TEST_GROUP_BASE(DT_03, TestGroupBase) {};

    //  test type: equivalence class test
    TEST(DT_03, T01)
    {
        SETUP()
        GenProjData<CAPTSW, CAPSIG, CAPLCR, CAPSEG> projData;
        // projData.preset();

        STEP(1)
        //  check content TSW
        L_CHECK_EQUAL(CAPTSW, projData.numTSW)
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPTSW; ++n)
        {
            LSTEP(n)
            const ElementName& name = genElementName(CAPTSW - n, "TSW");
            L_CHECK_ELEMENT_NAME(name, projData.pTSW[n].name)
        }
        ENDSTEPS()

        STEP(2)
        //  check content SIG
        L_CHECK_EQUAL(CAPSIG, projData.numSIG)
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPSIG; ++n)
        {
            LSTEP(n)
            const ElementName& name = genElementName(CAPSIG - n, "SIG");
            L_CHECK_ELEMENT_NAME(name, projData.pSIG[n].name)
        }
        ENDSTEPS()

        STEP(3)
        //  check content LCR
        L_CHECK_EQUAL(CAPLCR, projData.numLCR)
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPLCR; ++n)
        {
            LSTEP(n)
            const ElementName& name = genElementName(CAPLCR - n, "LCR");
            L_CHECK_ELEMENT_NAME(name, projData.pLCR[n].name)
        }
        ENDSTEPS()

        STEP(4)
        //  check content SEG
        SUBSTEPS()
        L_CHECK_EQUAL(CAPSEG, projData.numSEG)
        for (UINT32 n = 0; n < CAPSEG; ++n)
        {
            LSTEP(n)
            const ElementName& name = genElementName(CAPSEG - n, "SEG");
            L_CHECK_ELEMENT_NAME(name, projData.pSEG[n].name)
        }
        ENDSTEPS()
    }

} // namespace