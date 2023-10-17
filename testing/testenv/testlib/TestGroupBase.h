//  ============================================================
//  base CppUTest test group
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTGROUPBASE_H
#define TESTGROUPBASE_H

#include <testlib/CppUTest.h>
#include <mocks/M_Instances.h>
#include <comparators/ostreams.h>
#include <testlib/TestLiterals.h>
#include <ifs/DataTypes.h>

namespace test
{
    class TestGroupBase : public Utest
    {
    protected:
        inline ~TestGroupBase()
        {
            unmock();
        }

        inline void teardown()
        {
            CHECK_N_CLEAR()
        }

        //  preset an ElmentName for testing
        static const ElementName& genElementName(UINT32 num, CONST_C_STRING name = c__ELEM);
    };


} // namespace

#endif // _H














