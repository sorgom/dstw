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
    mIndx.index();
}

INT32 Dispatcher::assign(
    const ElementName& name, 
    const E_Subsys subs, 
    const UINT32 pos)
{
    INT32 res = -1;
    if (mData.hasSpace())
    {
        res = mData.addNtp(name, subs, pos);
    }
    else
    { pass();}
    return res;
}

void Dispatcher::dispatch(const FldState& tele) const
{
    const INT32 fnd = mIndx.findNtp(tele.name);
    if (fnd < 0)
    { 
        IL::getLog().log(COMP_DISPATCHER, ERR_MATCH);
    }
    else
    {
        const Ntp& ntp = mIndx.getRef(fnd);
        switch (ntp.type)
        {
        case SUBSYS_TSW:
            IL::getTSW_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SIG:
            IL::getSIG_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SEG:
            break;
        case SUBSYS_LCR:
            break;
// NO_COV >>
// assignment limited by enum            
        default:
            break;
// << NO_COV
        }
    }
}

void Dispatcher::dispatch(const GuiCmd& tele) const
{
    const INT32 fnd = mIndx.findNtp(tele.name);
    if (fnd < 0)
    { 
        IL::getLog().log(COMP_DISPATCHER, ERR_MATCH);
    }
    else
    {
        const Ntp& ntp = mIndx.getRef(fnd);
        switch (ntp.type)
        {
        case SUBSYS_TSW:
            IL::getTSW_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SIG:
            IL::getSIG_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SEG:
            break;
        case SUBSYS_LCR:
            break;
// NO_COV >>
// assignment limited by enum            
        default:
            break;
// << NO_COV
        }
    }
}

void Dispatcher::dispatch(const UINT32 id, const CmdFld& tele) const
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

void Dispatcher::dispatch(const UINT32 id, const StateGui& tele) const
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
