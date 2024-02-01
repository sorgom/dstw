#include <TSW/TSW_Hub.h>

#include <BAS/Mem.h>
#include <SYS/IL.h>

INSTANCE_DEF(TSW_Hub)

void TSW_Hub::fromDsp(const size_t pos, const FldState& tele) const
{
    I_TSW_Provider& prov = IL::getTSW_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.state1);
    }
    else
    {pass();}
}

void TSW_Hub::fromDsp(const size_t pos, const GuiCmd& tele) const
{
    I_TSW_Provider& prov = IL::getTSW_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.cmd1);
    }
    else
    {pass();}
}

void TSW_Hub::toFld(const size_t id, const INT32 cmd) const
{
    CmdFld tele(cmd);
    IL::getDispatcher().dispatch(id, tele);
}

void TSW_Hub::toGui(const size_t id, const INT32 state) const
{
    StateGui tele(state);
    IL::getDispatcher().dispatch(id, tele);
}


