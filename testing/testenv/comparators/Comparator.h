//  ============================================================
//  CppUTest style comparator
//  This comparator template works for all complex types,
//  Precondition: ostream operator for a type is defined.
//  See ostreams.h
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef COMPERATOR_H
#define COMPERATOR_H

#include <BAS/BaseTypes.h>
#include <BAS/coding.h>

#include <CppUTest/SimpleString.h>
#include <CppUTestExt/MockNamedValue.h>

#include <iostream>
#include <cstring>
#include <sstream>

namespace test
{
    class ComparatorBase
    {
    protected:
        inline ComparatorBase() {}

        static std::ostream& begin();
        static std::ostringstream mStream;

        NOCOPY(ComparatorBase)
    };

    template <class T>
    class Comparator : 
        public MockNamedValueComparator,
        private ComparatorBase
    {
    public:
        inline Comparator() {}

        SimpleString valueToString(CPTR ptr)
        {
            begin() << std::endl << *reinterpret_cast<const T*>(ptr);
            //  content is copied by CppUTest
            //  cppcheck-suppress returnDanglingLifetime
            return mStream.str().c_str();
        }
        inline bool isEqual(CPTR ptr1, CPTR ptr2)
        {
            return std::memcmp(ptr1, ptr2, sizeof(T)) == 0;
        }
        NOCOPY(Comparator)
    };
}

#endif // H_