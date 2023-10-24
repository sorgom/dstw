//  ============================================================
//  development tests vol. 1
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <SIG/SIG.h>

#include <qnd/useCout.h>

namespace test
{

    TEST_GROUP_BASE(DEV_01, TestGroupBase) {};


    //  test type: devel
    TEST(DEV_01, T01)
    {
        cout << "SIG     : " << sizeof(SIG) << endl;
        cout << "SIG_Main: " << sizeof(SIG_Main) << endl;
        cout << "SIG_Supp: " << sizeof(SIG_Supp) << endl;
    }
}
