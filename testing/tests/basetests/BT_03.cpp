//  ============================================================
//  test of basic functionality
//  - TeleMapper
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

#include <baselib/TeleMapper.h>

#include <qnd/useCout.h>

namespace test
{

    TEST_GROUP_BASE(BT_03, TestGroupBase)
    {
        
    };

    //  test type: equivalence class test
    TEST(BT_03, T01)
    {
        TeleMap<10> map;

        cout << endl;
        STEP(1)
        const UINT32 cap = map.capacity();

        for (UINT32 p = 0; p < cap; ++p)
        {
            map.addName(genElementName(cap - p));
        }
        L_CHECK_EQUAL(10, map.size())

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
