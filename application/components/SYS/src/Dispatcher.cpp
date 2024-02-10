#include <SYS/Dispatcher.h>
#include <codebase/Mem.h>
#include <BAS/coding.h>
#include <SYS/IL.h>

INSTANCE_DEF(Dispatcher)

void Dispatcher::reset()
{
    mData.reset();
    mIndx.reset();
}

void Dispatcher::index()
{
    if (mIndx.index())
    { pass();}
    else
    {
        IL::getLog().log(MOD_SYS_DISPATCHER, ERR_STARTUP);
    }
}

const PosRes Dispatcher::assign(
    const ComName& name, 
    const E_Subsys subs, 
    const size_t pos)
{
    const bool valid = mData.hasSpace();
    size_t dpos = 0;
    if (valid)
    {
        dpos = mData.add(name, subs, pos);
    }
    else
    { pass();}
    return PosRes{dpos, valid};
}

void Dispatcher::dispatch(const ComFldState& tele) const
{
    const PosRes res = mIndx.find(tele.name);

    if (res.valid)
    {
        const Ntp& ntp = mIndx.get(res);
        switch (ntp.type)
        {
        case SUBSYS_TSW:
            IL::getTSW_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SIG:
            IL::getSIG_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_LCR:
            IL::getLCR_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SEG:
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

void Dispatcher::dispatch(const ComGuiCmd& tele) const
{
    const PosRes res = mIndx.find(tele.name);

    if (res.valid)
    {
        const Ntp& ntp = mIndx.get(res);
        switch (ntp.type)
        {
        case SUBSYS_TSW:
            IL::getTSW_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SIG:
            IL::getSIG_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_LCR:
            IL::getLCR_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SEG:
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

void Dispatcher::dispatch(const size_t id, ComCmdFld&& tele) const
{
    if (mData.has(id))
    {
        tele.name = mData.at(id).name;
        IL::getCom().send(tele);
    }
    else
    { pass();}
}

void Dispatcher::dispatch(const size_t id, ComStateGui&& tele) const
{
    if (mData.has(id))
    {
        tele.name = mData.at(id).name;
        IL::getCom().send(tele);
    }
    else
    { pass();}
}
