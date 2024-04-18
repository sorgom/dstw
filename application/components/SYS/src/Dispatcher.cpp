#include <SYS/Dispatcher.h>
#include <codebase/Mem.h>
#include <BAS/coding.h>
#include <SYS/IL.h>

INSTANCE_DEF(Dispatcher)

void Dispatcher::clear()
{
    mIndx.clear();
}

void Dispatcher::index()
{
    if (mIndx.index())
    { pass(); }
    else
    {
        IL::getLog().log(COMP_SYS, ERR_STARTUP);
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

void Dispatcher::fromFld(const ComTele& tele) const
{
    const PosRes res = mIndx.find(tele.name);

    if (res.valid)
    {
        const Ncp& ncp = mIndx.at(res);
        switch (ncp.comp)
        {
        case COMP_TSW:
            forwardFld(IL::getTSW_Provider(), ncp, tele);
            break;
        case COMP_SIG:
            forwardFld(IL::getSIG_Provider(), ncp, tele);
            break;
        case COMP_LCR:
            forwardFld(IL::getLCR_Provider(), ncp, tele);
            break;
        case COMP_SEG:
            break;
        default:
            break;
        }
    }
    else
    { 
        IL::getLog().log(COMP_SYS, ERR_MATCH);
    }
}

void Dispatcher::fromGui(const ComTele& tele) const
{
    const PosRes res = mIndx.find(tele.name);

    if (res.valid)
    {
        const Ncp& ncp = mIndx.at(res);
        switch (ncp.comp)
        {
        case COMP_TSW:
            forwardGui(IL::getTSW_Provider(), ncp, tele);
            break;
        case COMP_SIG:
            forwardGui(IL::getSIG_Provider(), ncp, tele);
            break;
        case COMP_LCR:
            forwardGui(IL::getLCR_Provider(), ncp, tele);
            break;
        case COMP_SEG:
            break;
        default:
            break;
        }
    }
    else
    { 
        IL::getLog().log(COMP_SYS, ERR_MATCH);
    }
}

void Dispatcher::toFld(const size_t id, const ComData& data) const
{
    if (mIndx.size() > id)
    {
        const ComTele tele { mIndx.at(id).name, data };
        IL::getCom().toFld(tele);
    }
    else
    { pass(); }
}

void Dispatcher::toGui(const size_t id, const ComData& data) const
{
    if (mIndx.size() > id)
    {
        const ComTele tele { mIndx.at(id).name, data };
        IL::getCom().toGui(tele);
    }
    else
    { pass(); }
}

void Dispatcher::forwardFld(I_Provider& prov, const Ncp& ncp, const ComTele& tele)
{
    if (prov.size() > ncp.pos)
    {
        prov.at(ncp.pos).fromFld(tele.data);
    }
    else
    { 
        IL::getLog().log(COMP_SYS, ERR_RANGE);    
    }
}
void Dispatcher::forwardGui(I_Provider& prov, const Ncp& ncp, const ComTele& tele)
{
    if (prov.size() > ncp.pos)
    {
        prov.at(ncp.pos).fromGui(tele.data);
    }
    else
    { 
        IL::getLog().log(COMP_SYS, ERR_RANGE);    
    }
}
