#include <system/Loader.h>
#include <ddi/ddi.h>

INSTANCE_DEF(Loader)

bool Loader::load(const ProjData& data) const
{
    I_Dispatcher& disp = ddi::getDispatcher();
    disp.reset();

    bool ok = true;
    ok = ok and ddi::getTSW_Provider().load(data.pTSW, data.numTSW);
    ok = ok and ddi::getSIG_Provider().load(data.pSIG, data.numSIG);
    // TODO: LCR, SEG

    if (ok)
    {
        disp.index();  
    }
    else
    {
        disp.reset();
    }
    return ok;
}