//  ============================================================
//  defintion of interface I_Searchable to apply:
//  - bubble sort
//  - b-tree search
//  - uniqueness check / duplicates count
//  ============================================================
#pragma once
#ifndef I_SEARCHABLE_H
#define I_SEARCHABLE_H

#include <BAS/BaseTypes.h>
#include <BAS/coding.h>

template <class T>
class I_Searchable
{
public:
    //  current number of objects
    virtual UINT32 size() const = 0;
    //  object access by position
    virtual const T& at(UINT32 pos) const = 0;
    //  definition object a is greater than object b
    virtual bool isGreater(const T& a, const T& b) const = 0;
    //  swap content of position a and b
    virtual void swap(UINT32 posA, UINT32 posB) = 0;
};

template <class T>
void bSort(I_Searchable<T>& src)
{
    for (UINT32 n = src.size(); n > 1; --n)
    {
        bool swapped = false;
        for (UINT32 p = 0; p < n - 1; ++p)
        {
            if (src.isGreater(src.at(p), src.at(p + 1)))
            {
                src.swap(p, p + 1);
                swapped = true;
            }
        }
        if (not swapped)
        {
            break;
        }
    }
}

template <class T>
INT32 bSearch(const I_Searchable<T>& src, const T& obj)
{
    INT32 pMin = 0;
    INT32 pMax = src.size() - 1;
    INT32 res = -1;

    while (pMax >= pMin)
    {
        const INT32 pCur = (pMin + pMax + 1) / 2;

        if (src.isGreater(obj, src.at(pCur)))
        {
            pMin = pCur + 1;
        }
        else if (src.isGreater(src.at(pCur), obj))
        {
            pMax = pCur - 1;
        }
        else
        {
            res = pCur;
            break;
        }
    }
    return res;
}

//  apply duplicates count to I_Searchable
//  precondition: bSort applied before
template <class T>
UINT32 dupCnt(const I_Searchable<T>& src)
{
    UINT32 ndups = 0;
    for (UINT32 p = 0; p < src.size() - 1; ++p)
    {
        if (not src.isGreater(src.at(p + 1), src.at(p)))
        {
            ++ndups;
        }
    }
    return ndups;
}

#endif // H_