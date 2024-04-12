#include <SYS/Reader.h>
#include <ifs/ProjTypes.h>
#include <SYS/IL.h>

#include <fstream>
#include <algorithm>

using stype = std::streamoff;

INSTANCE_DEF(Reader)

void Reader::read(const CONST_C_STRING filename) const
{
    IL::getDispatcher().reset();
    IL::getTSW_Provider().reset();
    IL::getSIG_Provider().reset();
    IL::getLCR_Provider().reset();
    //  SEG not yet implemented

    std::ifstream is(filename, std::ios::binary);
    bool ok = is.good();
    if (ok)
    {
        constexpr static stype nCAP = 4;
        constexpr static stype hSize = nCAP * sizeof(UINT32);
        is.seekg(0, is.end);
        const stype end = is.tellg();
        is.seekg(0, is.beg);
        const stype fsize = end - is.tellg();
        ok = fsize >= hSize;
        if (ok)
        {
            union
            {
                CHAR buf[hSize];
                UINT32 vals[nCAP];
            } head;
            
            is.read(head.buf, hSize);
            auto [nTSW, nSIG, nLCR, nSEG] = head.vals;

            const stype sTSW = nTSW * sizeof(ProjTSW);
            const stype sSIG = nSIG * sizeof(ProjSIG);
            const stype sLCR = nLCR * sizeof(ProjLCR);
            const stype sSEG = nSEG * sizeof(ProjSEG);

            ok = (fsize == hSize + sTSW + sSIG + sLCR + sSEG);

            if (ok)
            {
                const auto mxSize = std::max({sTSW, sSIG, sLCR, sSEG});

                CHAR* buf = new CHAR[static_cast<size_t>(mxSize)];

                is.read(buf, sTSW);
                IL::getTSW_Provider().load(reinterpret_cast<const ProjTSW*>(buf), nTSW);

                is.read(buf, sSIG);
                IL::getSIG_Provider().load(reinterpret_cast<const ProjSIG*>(buf), nSIG);

                is.read(buf, sLCR);
                IL::getLCR_Provider().load(reinterpret_cast<const ProjLCR*>(buf), nLCR);

                //  SEG not yet implemented

                delete [] buf;

                IL::getDispatcher().index();
            }    
            else
            { pass(); }
        }
        else
        { pass(); }

    }
    else
    { pass(); }
    is.close();

    if (not ok)
    {
        IL::getLog().log(MOD_SYS_READER, ERR_STARTUP);
    }
    else
    { pass(); }
}
