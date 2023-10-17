#include <baselib/SortAndSearch.h>

void bSort(I_Sortable& obj)
{
    for (UINT32 n = obj.size(); n > 0; --n)
    {
        bool swapped = false;
        for (UINT32 p = 0; p < n - 1; ++p)
        {
            if (obj.isGreater(p, p + 1))
            {
                obj.swap(p, p + 1);
                swapped = true;
            }
        }
        if (not swapped)
        {
            break;
        }
    }
}

INT32 bSearch(const I_Searchable& obj)
{
    const UINT32 pSrc = obj.getSearchPos();
    INT32 pMin = 0;
    INT32 pMax = obj.size() - 1;
    INT32 res = -1;

    while (pMax >= pMin)
    {
        const INT32 pCur = (pMin + pMax + 1) / 2;
        if (obj.isEqual(pSrc, pCur))
        {
            res = pCur;
            break;
        }
        if (obj.isGreater(pSrc, pCur))
        {
            pMin = pCur + 1;
        }
        else
        {
            pMax = pCur - 1;
        }
    }
    return res;
}
