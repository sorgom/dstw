#include <baselib/TeleMapper.h>


// bool TeleMap::isGreater(const UINT32 posA, const UINT32 posB) const
// {
//     return Mem::cmp(at(posA).name, at(posB).name) > 0;
// }

// bool TeleMap::isEqual(const UINT32 posA, const UINT32 posB) const
// {
//     return Mem::cmp(at(posA).name, at(posB).name) == 0;
// }

NameNum GetNameNum::mNameNum;

const NameNum& GetNameNum::getNameNum(const ElementName& name, const UINT32 num)
{
    Mem::copy(mNameNum.name, name);
    mNameNum.num = num;
    return mNameNum;
}
