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
    if (not mIndx.index())
    {
        IL::getLog().log(COMP_SYS, RET_ERR_STARTUP);
    }
}

const PosRes Dispatcher::assign(
    const ComAddr& addr,
    const E_Comp comp,
    const size_t pos)
{
    mIndx.add(addr, comp, pos);
    return PosRes{true, mIndx.size() - 1};
}

void Dispatcher::fromFld(const ComTele& tele) const
{
    const PosRes res = mIndx.find(tele.addr);

    if (res.valid)
    {
        const Acp& acp = mIndx.at(res);
        switch (acp.comp)
        {
        case COMP_TSW:
            forwardFld(IL::getTSW_Provider(), acp, tele);
            break;
        case COMP_SIG:
            forwardFld(IL::getSIG_Provider(), acp, tele);
            break;
        case COMP_LCR:
            forwardFld(IL::getLCR_Provider(), acp, tele);
            break;
        case COMP_SEG:
            break;
        default:
            break;
        }
    }
    else
    {
        IL::getLog().log(COMP_SYS, RET_ERR_MATCH);
    }
}

void Dispatcher::fromGui(const ComTele& tele) const
{
    const PosRes res = mIndx.find(tele.addr);

    if (res.valid)
    {
        const Acp& acp = mIndx.at(res);
        switch (acp.comp)
        {
        case COMP_TSW:
            forwardGui(IL::getTSW_Provider(), acp, tele);
            break;
        case COMP_SIG:
            forwardGui(IL::getSIG_Provider(), acp, tele);
            break;
        case COMP_LCR:
            forwardGui(IL::getLCR_Provider(), acp, tele);
            break;
        case COMP_SEG:
            break;
        default:
            break;
        }
    }
    else
    {
        IL::getLog().log(COMP_SYS, RET_ERR_MATCH);
    }
}

void Dispatcher::toFld(const size_t id, const ComData& data) const
{
    if (mIndx.size() > id)
    {
        const ComTele tele { mIndx.at(id).addr, data };
        IL::getCom().toFld(tele);
    }
}

void Dispatcher::toGui(const size_t id, const ComData& data) const
{
    if (mIndx.size() > id)
    {
        const ComTele tele { mIndx.at(id).addr, data };
        IL::getCom().toGui(tele);
    }
}

void Dispatcher::reGui() const
{
    reGui(IL::getTSW_Provider());
    reGui(IL::getSIG_Provider());
    reGui(IL::getLCR_Provider());
}

void Dispatcher::reGui(I_Provider& prov)
{
    const size_t size = prov.size();
    for (size_t p = 0; p < size; ++p)
    {
        prov.at(p).toGui();
    }
}

void Dispatcher::forwardFld(I_Provider& prov, const Acp& acp, const ComTele& tele)
{
    if (prov.size() > acp.pos)
    {
        prov.at(acp.pos).fromFld(tele.data);
    }
    else
    {
        IL::getLog().log(COMP_SYS, RET_ERR_RANGE);
    }
}
void Dispatcher::forwardGui(I_Provider& prov, const Acp& acp, const ComTele& tele)
{
    if (prov.size() > acp.pos)
    {
        prov.at(acp.pos).fromGui(tele.data);
    }
    else
    {
        IL::getLog().log(COMP_SYS, RET_ERR_RANGE);
    }
}
