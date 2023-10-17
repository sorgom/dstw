//  ============================================================
//  test of basic functionality
//  - ElementNameMap
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

#include <baselib/ElementNameMap.h>

#include <qnd/useCout.h>

namespace test
{

    TEST_GROUP_BASE(BT_03, TestGroupBase)
    {
        
    };

    //  test type: equivalence class test
    TEST(BT_03, T01)
    {
        ElementNameMap<100> map;

        cout << endl;
        STEP(1)
        const UINT32 cap = map.capacity();

        for (UINT32 p = 0; p < cap; ++p)
        {
            map.addName(genElementName(cap - p));
        }
        L_CHECK_EQUAL(100, map.size())

        STEP(2)
        map.sort();
        SUBSTEPS()
        for (UINT32 p = 0; p < map.size(); ++p)
        {
            STEP(p + 1)
            L_CHECK_EQUAL(p, map.find(genElementName(cap - p)))
        }
        ENDSTEPS()
    }

} // namespace
