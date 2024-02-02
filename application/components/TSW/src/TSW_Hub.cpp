#include <TSW/TSW_Hub.h>

#include <codebase/Mem.h>
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
    IL::getDispatcher().dispatch(id, CmdFld(cmd));
}

void TSW_Hub::toGui(const size_t id, const INT32 state) const
{
    IL::getDispatcher().dispatch(id, StateGui(state));
}


