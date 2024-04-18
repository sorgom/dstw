#include <LCR/LCR_Provider.h>
#include <LCR/LCR_X.h>

INSTANCE_DEF(LCR_Provider)

bool LCR_Provider::add(const size_t id, const ProjItem& item)
{
    bool ok = true;
    switch (item.type)
    {
        case LCR_TYPE_LCR:
            mElems.add<LCR>(id);
            break;
        case LCR_TYPE_LCR_UBK:
            mElems.add<LCR_UBK>(id);
            break;
        default:
            ok = false;
            break;
    }
    return ok;
}
