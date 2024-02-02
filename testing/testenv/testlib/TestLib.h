//  ============================================================
//  basic test features
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTLIB_H
#define TESTLIB_H

#include <ifs/DataTypes.h>
#include <testlib/TestLiterals.h>
#include <BAS/Mem.h>
#include <BAS/coding.h>

namespace test
{
    //  preset an ElmentName for testing
    const ComName& genComName(UINT32 num, CONST_C_STRING name = c__ELM);
    void genComName(ComName& eName, UINT32 num, CONST_C_STRING name = c__ELM);

    inline void genComName(ComName& eName, UINT32 num, CONST_C_STRING name)
    {
        eName = genComName(num, name);
    }

    template <class T>
    void nameElement(T& elem, UINT32 num, CONST_C_STRING name = c__ELM)
    {
        genComName(elem.name, num, name);
    }

    inline bool operator==(const ComName& n1, const ComName& n2)
    {
        return Mem::cmp(n1.chars, n2.chars) == 0;
    }

    //  avoid "not used" warning
    template<typename T>
    void play(const T&)
    {}

    //  exchangeable non const reference
    template <class T>
    class Ref
    {
    public:
        inline Ref(T& obj):
            mPtr(&obj)
        {}
        inline T& ref() const
        {
            return *mPtr;
        }
        inline void set(T& ref)
        {
            mPtr = &ref;
        }
        NOCOPY(Ref)
        NODEF(Ref)
    private:
        T* mPtr;
    };
}

#endif // H_