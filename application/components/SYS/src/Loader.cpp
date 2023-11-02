#include <SYS/Loader.h>
#include <SYS/IL.h>

INSTANCE_DEF(Loader)

void Loader::load(const ProjData& data) const
{
    IL::getDispatcher().reset();
    IL::getTSW_Provider().load(data.pTSW, data.numTSW);
    IL::getSIG_Provider().load(data.pSIG, data.numSIG);
    // TODO: LCR, SEG
    IL::getDispatcher().index();
}