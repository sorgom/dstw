#pragma once
#ifndef TESTGROUPBASE_H
#define TESTGROUPBASE_H

#include <testenv/CppUTest.h>

namespace test
{
    class TestGroupBase : public Utest
    {
    protected:
        // inline TestGroupBase()
        // {}
        
        // inline ~TestGroupBase()
        // {}

        inline void teardown()
        {
            CHECK_N_CLEAR()
        }
    };
}

#endif // _H














