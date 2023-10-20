//  ============================================================
//  test of GenProjData
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <testlib/GenProjData.h>

#include <baselib/Mem.h>

#include <qnd/useCout.h>

#define CAPTSW 40
#define CAPSIG 30
#define CAPLCR 20
#define CAPSEG 10

namespace test
{

    TEST_GROUP_BASE(BT_03, TestGroupBase) {};

    //  test type: equivalence class test
    TEST(BT_03, T01)
    {
        SETUP()
        GenProjData<CAPTSW, CAPSIG, CAPLCR, CAPSEG> projData;
        ProjTSW projTSW;
        ProjSIG projSIG;
        ProjLCR projLCR;
        ProjSEG projSEG;

        STEP(1)
        //  load ProjTSW
        projData.preset();
        L_CHECK_EQUAL(CAPTSW, projData.numTSW)
        L_CHECK_EQUAL(CAPSIG, projData.numSIG)
        L_CHECK_EQUAL(CAPLCR, projData.numLCR)
        L_CHECK_EQUAL(CAPSEG, projData.numSEG)

        // STEP(2)
        // //  check content
        // SUBSTEPS()
        // for (UINT8 n = 0; n < TCAP; ++n)
        // {
        //     LSTEP(n)
        //     const ElementName& exp = genElementName(OFFS - n, "TSW");
        //     L_CHECK_ELEMENT_NAME(exp, projData.pTSW[n].name)
        // }
        // ENDSTEPS()

    }

} // namespace