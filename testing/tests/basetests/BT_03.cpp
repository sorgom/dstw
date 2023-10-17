//  ============================================================
//  test of basic functionality
//  - NameTypePosMap
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

#include <baselib/NameTypePosMap.h>

#include <qnd/useCout.h>

namespace test
{

    TEST_GROUP_BASE(BT_03, TestGroupBase)
    {
        
    };

    //  test type: equivalence class test
    TEST(BT_03, T01)
    {
        SETUP()
        NameTypePosMap<100> map;
        STEP(1)
        const UINT32 cap = map.capacity();

        STEP(2)
        SUBSTEPS()
        for (UINT32 p = 0; p < cap; ++p)
        {
            LSTEP(p)
            const INT32 pos = map.addNtp(genElementName(cap - p), p + 10, p * 10);
            L_CHECK_EQUAL(p, pos)
        }
        ENDSTEPS()
        L_CHECK_EQUAL(100, map.size())
        CHECK_TRUE(map.full());

        STEP(2)
        map.sort();
        SUBSTEPS()
        for (UINT32 p = 0; p < map.size(); ++p)
        {
            LSTEP(p)
            const NameTypePos& ntp = map[map.searchName(genElementName(cap - p))];
            L_CHECK_EQUAL(p + 10, ntp.type)
            L_CHECK_EQUAL(p * 10, ntp.pos)
        }
        ENDSTEPS()
    }

} // namespace
