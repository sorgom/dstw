#include <TSW/TSW_Hub.h>

#include <baselib/InstanceMacros.h>
#include <baselib/coding.h>
#include <baselib/Mem.h>
#include <ddi/ddi.h>

#include <qnd/useCout.h>

INSTANCE_DEF(TSW_Hub)

bool TSW_Hub::load(const ProjTSW* const data, const UINT32 num)
{
    cout << "TSW_Hub::load " << num << endl;

    I_TSW_Provider& prov = ddi::getTSW_Provider();
    I_Dispatcher& disp = ddi::getDispatcher();

    bool ok = true;
    prov.reset();
    if (num > prov.capacity())
    { 
        ok = false;
    }
    else
    {
        for (UINT32 n = 0; ok and (n < num); ++n)
        {
            const INT32 id = disp.assign(data[n].name, SUBSYS_TSW, n);
            if (id < 0)
            {
                ok = false;
                prov.reset();
            }
            else
            { 
                prov.add(id);
            }
        }
    }
    cout << "TSW_Hub::loaded: " << ok << endl;
    return ok;
}

void TSW_Hub::fromFld(const FldState& tele, const UINT32 pos)
{
    cout << "TSW_Hub::fromFld " << pos << endl;
    I_TSW_Provider& prov = ddi::getTSW_Provider();
    if (prov.has(pos))
    {
        cout << "ok" << endl;
        prov.at(pos).fromFld(tele.state);
    }
    else
    {pass();}
}

void TSW_Hub::fromGui(const GuiCmd& tele, const UINT32 pos)
{
    I_TSW_Provider& prov = ddi::getTSW_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.cmd);
    }
    else
    {pass();}
}

void TSW_Hub::toFld(const UINT32 id, const INT32 cmd) const
{
    static CmdFld cmdFld;
    Mem::zero(cmdFld);
    if (ddi::getDispatcher().label(cmdFld.name, id))
    {
        cmdFld.cmd = cmd;
        ddi::getFldCom().send(cmdFld);
    }
    else
    {pass();}
}

void TSW_Hub::toGui(const UINT32 id, const INT32 state) const
{
    cout << "TSW_Hub::toGui " << id << ", " << state << endl;
    static StateGui stateGui;
    Mem::zero(stateGui);
    if (ddi::getDispatcher().label(stateGui.name, id))
    {
        stateGui.state = state;
        ddi::getFldCom().send(stateGui);
    }
    else
    {pass();}
}


