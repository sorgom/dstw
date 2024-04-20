#include <SIG/SIG_Provider.h>
#include <SIG/SIG_X.h>

INSTANCE_DEF(SIG_Provider)

bool SIG_Provider::add(const size_t id, const ProjItem& item)
{
    bool ok = true;
    switch (item.type)
    {
        case TYPE_SIG_H:
            mElems.add<SIG_H>(id);
            break;
        case TYPE_SIG_N:
            mElems.add<SIG_N>(id);
            break;
        case TYPE_SIG_H_N:
            mElems.add<SIG_H_N>(id);
            break;
        default:
            ok = false;
            break;
    }
    return ok;
}
