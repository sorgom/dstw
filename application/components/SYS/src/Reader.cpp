#include <SYS/Reader.h>
#include <ifs/DataTypes.h>
#include <SYS/IL.h>

#include <fstream>
#include <algorithm>

// using auto = std::streamoff;
// using auto = UINT32;

INSTANCE_DEF(Reader)

void Reader::read(const CONST_C_STRING filename)
{
    IL::getDispatcher().clear();
    IL::getTSW_Provider().clear();
    IL::getSIG_Provider().clear();
    IL::getLCR_Provider().clear();
    //  SEG not yet implemented

    std::ifstream is(filename, std::ios::binary);
    bool ok = is.good();
    if (ok)
    {
        constexpr static auto nCAP = 4;
        constexpr static auto hSize = nCAP * sizeof(UINT32);
        constexpr static auto minSize = hSize + sizeof(ComSetup);
        is.seekg(0, is.end);
        const std::streamoff end = is.tellg();
        is.seekg(0, is.beg);

#ifdef _WIN32
//  warning C4244: 'initializing': conversion from 'std::streamoff' to 'UINT32', possible loss of data
//  warning C4244: 'initializing': conversion from 'std::streamoff' to 'const UINT32', possible loss of data
//  UINT32_MAX cannot be exceeded in this context
#pragma warning(disable:4244)
#endif
        const UINT32 fsize = end - is.tellg();
#ifdef _WIN32
#pragma warning(default:4244)
#endif
        ok = fsize >= minSize;
        if (ok)
        {
            union
            {
                CHAR buf[hSize];
                UINT32 vals[nCAP];
            } head;

            is.read(head.buf, hSize);
            auto [nTSW, nSIG, nLCR, nSEG] = head.vals;

            const auto sTSW = nTSW * sizeof(ProjItem);
            const auto sSIG = nSIG * sizeof(ProjItem);
            const auto sLCR = nLCR * sizeof(ProjItem);
            const auto sSEG = nSEG * sizeof(ProjItem);
            const auto sTOT = sTSW + sSIG + sLCR + sSEG;

            ok = (sTOT > 0) and (fsize == minSize + sTOT);

            if (ok)
            {
                is.read(reinterpret_cast<CHAR*>(&mComSetup), sizeof(ComSetup));

                const auto mxSize = std::max({sTSW, sSIG, sLCR, sSEG});
                CHAR* buf = new CHAR[static_cast<size_t>(mxSize)];

                is.read(buf, sTSW);
                IL::getTSW_Provider().load(reinterpret_cast<const ProjItem*>(buf), nTSW);

                is.read(buf, sSIG);
                IL::getSIG_Provider().load(reinterpret_cast<const ProjItem*>(buf), nSIG);

                is.read(buf, sLCR);
                IL::getLCR_Provider().load(reinterpret_cast<const ProjItem*>(buf), nLCR);

                //  SEG not yet implemented

                delete [] buf;

                IL::getDispatcher().index();
            }
        }
    }
    is.close();

    if (not ok)
    {
        IL::getLog().log(COMP_SYS, RET_ERR_STARTUP);
    }
}
