//  ============================================================
//  CppUTest style comparator
//  This comparator template works for all complex types,
//  Precondition: ostream operator for a type is defined.
//  See ostreams.h
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef BASECOMPERATOR_H
#define BASECOMPERATOR_H

#include <BAS/BaseTypes.h>
#include <iostream>
#include <cstring>

#include <CppUTest/SimpleString.h>
#include <CppUTestExt/MockNamedValue.h>

#include <comparators/CompOstream.h>

namespace test
{
    template <class T>
    class Comparator : public MockNamedValueComparator
    {
    public:
        SimpleString valueToString(CPTR ptr)
        {
            begin() << std::endl << *reinterpret_cast<const T*>(ptr);
            return get().str().c_str();
        }
        inline bool isEqual(CPTR ptr1, CPTR ptr2)
        {
            return std::memcmp(ptr1, ptr2, sizeof(T)) == 0;
        }
    protected:
        inline static std::ostream& begin()
        {
            return CompOstream::instance().begin();
        }
        inline static const std::ostringstream& get()
        {
            return CompOstream::instance().get();
        }

    }; 

}

#endif // H_