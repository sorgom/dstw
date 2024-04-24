//  ============================================================
//  test of modules Com, Log (coverage)
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <COM/Com.h>
#include <SYS/Log.h>

namespace test
{
    TEST_GROUP_BASE(SYS_03, TestGroupBase) {};

    //  test type: coverage
    TEST(SYS_03, T01)
    {
        const ComTele tf {};
        const ComTele tg {};
        Com::instance().toFld(tf);
        Com::instance().toGui(tg);
        Log::instance().log(COMP_SYS, RET_ERR_MATCH);
    }
}