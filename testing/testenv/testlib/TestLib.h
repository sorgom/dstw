//  ============================================================
//  basic test features
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <ifs/DataTypes.h>
#include <codebase/Mem.h>
#include <BAS/coding.h>

namespace test
{
    //  preset ComName for testing
    void genComName(ComName& cName, UINT32 num, CONST_C_STRING name = "ELM");

    template <class T>
    void nameElement(T& elem, UINT32 num, CONST_C_STRING name = "ELM")
    {
        genComName(elem.name, num, name);
    }

    const ComName& genComName(UINT32 num, CONST_C_STRING name = "ELM");

    inline bool operator==(const ComName& n1, const ComName& n2)
    {
        return Mem::cmp(n1.chars, n2.chars) == 0;
    }

    // inline bool operator==(const ComData& d1, const ComData& d2)
    // {
    //     return Mem::cmp(d1, d2) == 0;
    // }

    // inline bool operator==(const ComTele& t1, const ComTele& t2)
    // {
    //     return Mem::cmp(t1, t2) == 0;
    // }

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
