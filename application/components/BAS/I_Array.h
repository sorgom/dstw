//  ============================================================
//  definition of interfaces I_Array / I_SortableArray
//  enables:
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

    inline bool hasSpace() const
    {
        return size() < CAP;
    }

    inline bool has(size_t pos) const
    {
        return pos < size();
    }
};

template <class T, size_t CAP>
class I_SortableArray : public I_Array<T, CAP>
{
protected:
    //  definition object a is greater than object b
    virtual bool isGreater(const T& a, const T& b) const = 0;

    //  swap content of position a and b
    virtual void swap(size_t posA, size_t posB) = 0;

    void sort()
    {
        bool swapped = true;
        for (size_t n = this->size(); swapped and n > 1; --n)
        {
            swapped = false;
            for (size_t p = 0; p < n - 1; ++p)
            {
                if (isGreater(this->at(p), this->at(p + 1)))
                {
                    swap(p, p + 1);
                    swapped = true;
                }
            }
        }
    }

    const PosRes find(const T& obj) const
    {
        size_t pos = 0;
        bool valid = false;
        if (this->size() > 0)
        {
            size_t pMin = 0;
            size_t pMax = this->size() - 1;

            while (pMax >= pMin)
            {
                const size_t pCur = (pMin + pMax + 1) / 2;

                if (isGreater(obj, this->at(pCur)))
                {
                    pMin = pCur + 1;
                }
                else if (isGreater(this->at(pCur), obj))
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
                    pos = pCur;
                    valid = true;
                    break;
                }
            }
        }
        return PosRes{ pos, valid };
    }

    size_t dupCnt() const
    {
        size_t nd = 0;
        for (size_t p = 1; p < this->size(); ++p)
        {
            if (not isGreater(this->at(p), this->at(p - 1)))
            {
                ++nd;
            }
        }
        return nd;
    }

};

#endif // H_