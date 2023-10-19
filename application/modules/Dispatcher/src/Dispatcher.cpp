#include <Dispatcher/Dispatcher.h>
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

bool Dispatcher::label(ElementName& name, const UINT32 id) const
{
    bool res = false;
    if (id < mData.size())
    {
        Mem::copy(name, mData[id].name);
        res = true;
    }
    else
    { pass();}
    return res;
}

bool Dispatcher::dispatch(const FldState& tele) const
{
    bool res = false;
    const INT32 fnd = mIndx.findNtp(tele.name);
    if (fnd < 0)
    { pass();}
    else
    {
        res = true;
        const Ntp& ntp = mIndx.getRef(fnd);
        switch (ntp.type)
        {
        case SUBSYS_TSW:
            ddi::getTrackSwitchPort().fromFld(tele, ntp.pos);
            break;
        case SUBSYS_SIG:
            break;
        case SUBSYS_SEG:
            break;
        case SUBSYS_LCR:
            break;
        default:
            res = false;
            break;
        }
    }
    return res;
}

bool Dispatcher::dispatch(const GuiCmd& tele) const
{
    bool res = false;
    const INT32 fnd = mIndx.findNtp(tele.name);
    if (fnd < 0)
    { pass();}
    else
    {
        res = true;
        const Ntp& ntp = mIndx.getRef(fnd);
        switch (ntp.type)
        {
        case SUBSYS_TSW:
            ddi::getTrackSwitchPort().fromGui(tele, ntp.pos);
            break;
        case SUBSYS_SIG:
            break;
        case SUBSYS_SEG:
            break;
        case SUBSYS_LCR:
            break;
        default:
            res = false;
            break;
        }
    }
    return res;
}