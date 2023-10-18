#pragma once
#ifndef I_SEARCHABLE_H
#define I_SEARCHABLE_H

#include <baselib/BaseTypes.h>

#include <qnd/useCout.h>

template <class T>
class I_Searchable
{
public:
    virtual UINT32 size() const = 0;
    virtual const T& at(UINT32 pos) const = 0;
    virtual bool isGreater(const T& a, const T& b) const = 0;
    virtual void swap(UINT32 posA, UINT32 posB) = 0;
};

template <class T>
void bSort(I_Searchable<T>& src)
{
    for (UINT32 n = src.size(); n > 0; --n)
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
    cout << "START bsearch" << endl;
    INT32 pMin = 0;
    INT32 pMax = src.size() - 1;
    INT32 res = -1;

    while (pMax >= pMin)
    {
        const INT32 pCur = (pMin + pMax + 1) / 2;

        cout << "bSearch: " << pMin << ", " << pCur << ", " << pMax << endl;

        if (src.isGreater(obj, src.at(pCur)))
        {
            cout << "object is greater" << endl;
            pMin = pCur + 1;
        }
        else if (src.isGreater(src.at(pCur), obj))
        {
            pMax = pCur - 1;
            cout << "current is greater" << endl;
        }
        else
        {
            res = pCur;
            break;
        }
    }
    cout << "bSearch res: " << res << endl; 
    return res;
}


#endif // H_