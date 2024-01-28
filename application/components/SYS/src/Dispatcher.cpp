#include <SYS/Dispatcher.h>
#include <BAS/Mem.h>
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
        IL::getLog().log(MOD_DISPATCHER, ERR_STARTUP);
    }
}

size_t Dispatcher::assign(
    const ElementName& name, 
    const E_Subsys subs, 
    const size_t pos)
{
    size_t res = invalidPos;
    if (mData.hasSpace())
    {
        res = mData.add(name, subs, pos);
    }
    else
    { pass();}
    return res;
}

void Dispatcher::dispatch(const FldState& tele) const
{
    const PosRes res = mIndx.find(tele.name);

    if (res.valid)
    {
        const Ntp& ntp = mIndx.get(res.pos);
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
        IL::getLog().log(MOD_DISPATCHER, ERR_MATCH);
    }
}

void Dispatcher::dispatch(const GuiCmd& tele) const
{
    const PosRes res = mIndx.find(tele.name);

    if (res.valid)
    {
        const Ntp& ntp = mIndx.get(res.pos);
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
        IL::getLog().log(MOD_DISPATCHER, ERR_MATCH);
    }
}

void Dispatcher::dispatch(const size_t id, const CmdFld& tele) const
{
    if (id < mData.size())
    {
        static CmdFld cmd;
        Mem::cpy(cmd, tele);
        Mem::cpy(cmd.name, mData.at(id).name);
        IL::getCom().send(cmd);
    }
    else
    { pass();}
}

void Dispatcher::dispatch(const size_t id, const StateGui& tele) const
{
    if (id < mData.size())
    {
        static StateGui state;
        Mem::cpy(state, tele);
        Mem::cpy(state.name, mData.at(id).name);
        IL::getCom().send(state);
    }
    else
    { pass();}
}
