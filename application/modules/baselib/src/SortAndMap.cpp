#include <baselib/SortAndMap.h>

void bSort(I_Sortable& srt)
{
    for (UINT32 n = srt.size(); n > 0; --n)
    {
        bool swapped = false;
        for (UINT32 p = 0; p < n; ++p)
        {
            if (srt.isGreater(p, p + 1))
            {
                srt.swap(p, p + 1);
                swapped = true;
            }
        }
        if (not swapped)
        {
            break;
        }
    }
}

//  TODO: not ready
//  reach pos 0 with even size
INT32 bSearch(I_Searchable& src)
{
    const UINT32 sPos = src.initSearchPos();
    UINT32 stp = src.size() / 2;
    UINT32 pos = stp;
    INT32 res = -1;

    while (stp > 0)
    {
        if (src.isEqual(sPos, pos))
        {
            res = pos;
            break;
        }
        //  ERROR: permanent loop
        stp = (stp + 1) / 2;
        if (src.isGreater(sPos, pos))
        {
            pos += stp;
        }
        else
        {
            pos -= stp;
        }
    }
    return res;
}
