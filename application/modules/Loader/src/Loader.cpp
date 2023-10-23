#include <Loader/Loader.h>
#include <ddi/ddi.h>

#include <qnd/useCout.h>


INSTANCE_DEF(Loader)

bool Loader::load(const ProjData& data) const
{
    cout << "Loader::load" << endl;
    I_Dispatcher& disp = ddi::getDispatcher();
    disp.reset();

    bool ok = true;
    cout << "TSW: " << data.numTSW << endl;
    ok = ok and ddi::getTSW_Hub().load(data.pTSW, data.numTSW);
    // TODO: SIG, LCR, SEG

    if (ok)
    {
        disp.index();   
    }
    else
    {
        disp.reset();
    }
    return ok;
}