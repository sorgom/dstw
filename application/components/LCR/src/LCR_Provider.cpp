#include <LCR/LCR_Provider.h>
#include <LCR/LCR_X.h>
#include <SYS/IL.h>

ILX_INSTANCE_DEF(LCR_Provider)

void LCR_Provider::load(const ProjLCR* data, UINT32 num)
{
    reset();
    mElems.reserve(num);
    bool ok = true;
    for (UINT32 n = 0; ok and (n < num); ++n, ++data)
    {
        const PosRes res = IL::getDispatcher().assign(data->name, COMP_LCR, n);
        ok = res.valid;
        if (ok)
        {
            switch (data->type)
            {
                case LCR_TYPE_LCR:
                    mElems.add<LCR>(res.pos);
                    break;
                case LCR_TYPE_LCR_UBK:
                    mElems.add<LCR_UBK>(res.pos);
                    break;
                default:
                    ok = false;
                    break;;
            }
        }
    }
    if (not ok)
    {
        reset();
        IL::getLog().log(MOD_LCR_PROVIDER, ERR_STARTUP);
    }
}
