//  ============================================================
//  basic test features
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTLIB_H
#define TESTLIB_H

#include <ifs/DataTypes.h>
#include <testlib/TestLiterals.h>
#include <BAS/coding.h>

namespace test
{
    //  preset an ElmentName for testing
    const ElementName& genElementName(UINT32 num, CONST_C_STRING name = c__ELM);
    void genElementName(ElementName& eName, UINT32 num, CONST_C_STRING name = c__ELM);

    template <class T>
    void nameElement(T& elem, UINT32 num, CONST_C_STRING name = c__ELM)
    {
        genElementName(elem.name, num, name);
    }

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

    private:
        T* mPtr;
        NOCOPY(Ref)
        Ref();
    };
}

#endif // H_