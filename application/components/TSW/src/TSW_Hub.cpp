#include <TSW/TSW_Hub.h>

#include <BAS/Mem.h>
#include <SYS/IL.h>

INSTANCE_DEF(TSW_Hub)

void TSW_Hub::fromDsp(const UINT32 pos, const FldState& tele) const
{
    I_TSW_Provider& prov = IL::getTSW_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.state1);
    }
    else
    {pass();}
}

void TSW_Hub::fromDsp(const UINT32 pos, const GuiCmd& tele) const
{
    I_TSW_Provider& prov = IL::getTSW_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.cmd1);
    }
    else
    {pass();}
}

void TSW_Hub::toFld(const UINT32 id, const INT32 cmd) const
{
    static CmdFld tele;
    Mem::zero(tele);
    tele.cmd1 = cmd;
    IL::getDispatcher().dispatch(id, tele);
}

void TSW_Hub::toGui(const UINT32 id, const INT32 state) const
{
    static StateGui tele;
    Mem::zero(tele);
    tele.state1 = state;
    IL::getDispatcher().dispatch(id, tele);
}


