#include <system/Loader.h>
#include <ddi/ddi.h>

INSTANCE_DEF(Loader)

void Loader::load(const ProjData& data) const
{
    ddi::getDispatcher().reset();
    ddi::getTSW_Provider().load(data.pTSW, data.numTSW);
    ddi::getSIG_Provider().load(data.pSIG, data.numSIG);
    // TODO: LCR, SEG
    ddi::getDispatcher().index();
}