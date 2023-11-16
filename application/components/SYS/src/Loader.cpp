#include <SYS/Loader.h>
#include <SYS/IL.h>

INSTANCE_DEF(Loader)

void Loader::load(const ProjData& data) const
{
    IL::getDispatcher().reset();
    
    IL::getTSW_Provider().load(data.pTSW, data.numTSW);
    IL::getSIG_Provider().load(data.pSIG, data.numSIG);
    IL::getLCR_Provider().load(data.pLCR, data.numLCR);
    // TODO: SEG
    IL::getDispatcher().index();
}