//  ============================================================
//  base CppUTest test group
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTGROUPBASE_H
#define TESTGROUPBASE_H

#include <testlib/CppUTest.h>

#include <baselib/Mem.h>
#include <comparators/ostreams.h>
#include <ddi/ddi.h>
#include <mocks/M_Instances.h>
#include <setup/capacities.h>
#include <testlib/GenProjData.h>
#include <testlib/TestLib.h>
#include <testlib/TestLiterals.h>
#include <TestStepper/TestStepper.h>

namespace test
{
    class TestGroupBase : public Utest
    {
    protected:
        inline TestGroupBase()
        {
            unmock();
        }

        inline void teardown()
        {
            CHECK_N_CLEAR()
        }

    };

} // namespace

#define L_CHECK_ELEMENT_NAME(exp, act) L_CHECK_EQUAL(0, Mem::cmp(exp, act))

#endif // _H














