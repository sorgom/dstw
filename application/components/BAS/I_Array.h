//  ============================================================
//  defintion of interface I_Array to apply:
//  - bubble sort
//  - b-tree search
//  - uniqueness check / duplicates count
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_ARRAY_H
#define I_ARRAY_H

#include <BAS/coding.h>
#include <ifs/PosRes.h>

template <class T, size_t CAP>
class I_Array
{
public:
    constexpr inline static size_t capacity()
    {
        return CAP;
    } 

    //  current number of objects
    virtual size_t size() const = 0;
    
    //  object access by position
    virtual const T& at(size_t pos) const = 0;
    
    //  object pointer access by position
    virtual const T* ptr(size_t pos) const = 0;

    //  definition object a is greater than object b
    inline virtual bool isGreater(const T& a, const T& b) const
    {
        return false;
    } 

    void sort()
    {
        bool swapped = true;
        for (size_t n = size(); swapped and n > 1; --n)
        {
            swapped = false;
            for (size_t p = 0; p < n - 1; ++p)
            {
                if (isGreater(at(p), at(p + 1)))
                {
                    swap(p, p + 1);
                    swapped = true;
                }
            }
        }
    }

    PosRes find(const T& obj) const
    {
        PosRes res = { 0, false };
        
        if (size() > 0)
        {
            size_t pMin = 0;
            size_t pMax = size() - 1;

            while (pMax >= pMin)
            {
                const size_t pCur = (pMin + pMax + 1) / 2;

                if (isGreater(obj, at(pCur)))
                {
                    pMin = pCur + 1;
                }
                else if (isGreater(at(pCur), obj))
                {
                    if (pCur > 0)
                    {
                        pMax = pCur - 1;
                    } 
                    else
                    {
                        break;
                    }
                }
                else
                {
                    res.pos = pCur;
                    res.valid = true;
                    break;
                }
            }
        }
        return res;
    }

    size_t dupCnt() const
    {
        size_t nd = 0;
        for (size_t p = 1; p < size(); ++p)
        {
            if (not isGreater(at(p), at(p - 1)))
            {
                ++nd;
            }
        }
        return nd;
    }

protected:
    //  swap content of position a and b
    inline virtual void swap(size_t posA, size_t posB)
    {}
};

#endif // H_