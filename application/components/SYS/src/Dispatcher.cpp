#include <SYS/Dispatcher.h>
#include <codebase/Mem.h>
#include <BAS/coding.h>
#include <SYS/IL.h>

INSTANCE_DEF(Dispatcher)

void Dispatcher::reset()
{
    mIndx.clear();
}

void Dispatcher::index()
{
    if (mIndx.index())
    { pass(); }
    else
    {
        IL::getLog().log(MOD_SYS_DISPATCHER, ERR_STARTUP);
    }
}

const PosRes Dispatcher::assign(
    const ComName& name, 
    const E_Comp comp, 
    const size_t pos)
{
    mIndx.add(name, comp, pos);
    return PosRes{mIndx.size() - 1, true};
}

void Dispatcher::dispatch(const ComTeleFld& tele) const
{
    const PosRes res = mIndx.find(tele.name);

    if (res.valid)
    {
        const Ncp& ncp = mIndx.at(res);
        switch (ncp.comp)
        {
        case COMP_TSW:
            IL::getTSW_Hub().fromDsp(ncp.pos, tele);
            break;
        case COMP_SIG:
            IL::getSIG_Hub().fromDsp(ncp.pos, tele);
            break;
        case COMP_LCR:
            IL::getLCR_Hub().fromDsp(ncp.pos, tele);
            break;
        case COMP_SEG:
            break;
        default:
            break;
        }
    }
    else
    { 
        IL::getLog().log(MOD_SYS_DISPATCHER, ERR_MATCH);
    }
}

void Dispatcher::dispatch(const ComTeleGui& tele) const
{
    const PosRes res = mIndx.find(tele.name);

    if (res.valid)
    {
        const Ncp& ncp = mIndx.at(res);
        switch (ncp.comp)
        {
        case COMP_TSW:
            IL::getTSW_Hub().fromDsp(ncp.pos, tele);
            break;
        case COMP_SIG:
            IL::getSIG_Hub().fromDsp(ncp.pos, tele);
            break;
        case COMP_LCR:
            IL::getLCR_Hub().fromDsp(ncp.pos, tele);
            break;
        case COMP_SEG:
            break;
        default:
            break;
        }
    }
    else
    { 
        IL::getLog().log(MOD_SYS_DISPATCHER, ERR_MATCH);
    }
}

void Dispatcher::dispatch(const size_t id, ComTeleFld&& tele) const
{
    if (mIndx.size() > id)
    {
        tele.name = mIndx.at(id).name;
        IL::getCom().send(tele);
    }
    else
    { pass(); }
}

void Dispatcher::dispatch(const size_t id, ComTeleGui&& tele) const
{
    if (mIndx.size() > id)
    {
        tele.name = mIndx.at(id).name;
        IL::getCom().send(tele);
    }
    else
    { pass(); }
}
