#include <ifs/ProjTypes.h>
#include <setup/capacities.h>
#include <SYS/IL.h>
#include <SYS/Reader.h>

#include <algorithm>
#include <fstream>

INSTANCE_DEF(Reader)

inline std::ifstream& operator>>(std::ifstream& is, UINT32& n)
{
    is.read(reinterpret_cast<CHAR*>(&n), sizeof(UINT32));
    return is;
}

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
        constexpr static size_t nCAP = 4;
        constexpr static size_t hSize = nCAP * sizeof(UINT32);
        is.seekg(0, is.end);
        const size_t end = is.tellg();
        is.seekg(0, is.beg);
        const size_t fsize = end - is.tellg();
        ok = fsize >= hSize;
        if (ok)
        {
            union
            {
                CHAR buf[hSize];
                UINT32 vals[nCAP];
            } head;
            
            is.read(head.buf, hSize);
            const auto [nTSW, nSIG, nLCR, nSEG] = head.vals;

            const size_t sTSW = nTSW * sizeof(ProjTSW);
            const size_t sSIG = nSIG * sizeof(ProjSIG);
            const size_t sLCR = nLCR * sizeof(ProjLCR);
            const size_t sSEG = nSEG * sizeof(ProjSEG);

            ok = fsize == hSize + sTSW + sSIG + sLCR + sSEG;

            if (ok)
            {
                ok = nTSW <= CAPACITY_TSW;
            }
            else
            { pass(); }

            if (ok)
            {
                ok = nSIG <= CAPACITY_SIG;
            }
            else
            { pass(); }

            if (ok)
            {
                ok = nLCR <= CAPACITY_LCR;
            }
            else
            { pass(); }

            if (ok)
            {
                ok = nSEG <= CAPACITY_SEG;
            }
            else
            { pass(); }

            if (ok)
            {
                constexpr static size_t dSize = std::max({
                    CAPACITY_TSW * sizeof(ProjTSW),
                    CAPACITY_SIG * sizeof(ProjSIG),
                    CAPACITY_LCR * sizeof(ProjLCR),
                    CAPACITY_SEG * sizeof(ProjSEG)
                });

                CHAR buf[dSize];

                is.read(buf, sTSW);
                IL::getTSW_Provider().load(reinterpret_cast<const ProjTSW*>(buf), nTSW);

                is.read(buf, sSIG);
                IL::getSIG_Provider().load(reinterpret_cast<const ProjSIG*>(buf), nSIG);

                is.read(buf, sLCR);
                IL::getLCR_Provider().load(reinterpret_cast<const ProjLCR*>(buf), nLCR);

                //  SEG not yet implemented

                
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
        IL::getLog().log(MOD_READER, ERR_STARTUP);
    }
    else
    { pass(); }
}
