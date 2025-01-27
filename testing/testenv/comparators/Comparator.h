//  ============================================================
//  CppUTest style comparator
//  This comparator template works for all complex types,
//  Precondition: ostream operator for a type is defined.
//  See ostreams.h
//  ============================================================
//  created by Manfred Sorgo

#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <codebase/BaseTypes.h>
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
        inline ComparatorBase() = default;

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
        inline Comparator() = default;

        SimpleString valueToString(CPTR ptr)
        {
            begin() << '\n' << *reinterpret_cast<const T*>(ptr);
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
#endif // _H
