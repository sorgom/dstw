#include <system/Dispatcher.h>
#include <baselib/Mem.h>
#include <baselib/coding.h>
#include <ddi/ddi.h>

INSTANCE_DEF(Dispatcher)

void Dispatcher::reset()
{
    mData.reset();
    mIndx.reset();
}

void Dispatcher::index()
{
    mIndx.adapt();
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
        ddi::getLog().log(COMP_DISPATCHER, ERR_MATCH);
    }
    else
    {
        const Ntp& ntp = mIndx.getRef(fnd);
        switch (ntp.type)
        {
        case SUBSYS_TSW:
            ddi::getTSW_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SIG:
            ddi::getSIG_Hub().fromDsp(ntp.pos, tele);
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
        ddi::getLog().log(COMP_DISPATCHER, ERR_MATCH);
    }
    else
    {
        const Ntp& ntp = mIndx.getRef(fnd);
        switch (ntp.type)
        {
        case SUBSYS_TSW:
            ddi::getTSW_Hub().fromDsp(ntp.pos, tele);
            break;
        case SUBSYS_SIG:
            ddi::getSIG_Hub().fromDsp(ntp.pos, tele);
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
        Mem::copy(cmd, tele);
        Mem::copy(cmd.name, mData[id].name);
        ddi::getCom().send(cmd);
    }
    else
    { pass();}
}

void Dispatcher::dispatch(const UINT32 id, const StateGui& tele) const
{
    if (id < mData.size())
    {
        static StateGui state;
        Mem::copy(state, tele);
        Mem::copy(state.name, mData[id].name);
        ddi::getCom().send(state);
    }
    else
    { pass();}
}
