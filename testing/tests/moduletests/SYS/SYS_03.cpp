//  ============================================================
//  test of modules Com, Log (coverage)
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <SYS/Com.h>
#include <SYS/Log.h>

namespace test
{
    TEST_GROUP_BASE(SYS_03, TestGroupBase) {};

    //  test type: coverage
    TEST(SYS_03, T01)
    {
        const ComTeleGui tg {};
        const ComTeleFld tf {};
        Com::instance().send(tg);
        Com::instance().send(tf);
        Log::instance().log(COMP_SYS, ERR_MATCH);
    }
}