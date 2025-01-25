#include <SYS/Reader.h>
#include <ifs/DataTypes.h>
#include <SYS/IL.h>

#include <fstream>
#include <algorithm>
#include <BAS/Net.h>

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
        const auto end = is.tellg();
        is.seekg(0, is.beg);

        const UINT32 fsize = end - is.tellg();

        ok = fsize >= minSize;
        if (ok)
        {
            UINT32 netNums[nCAP] = {};
            is.read(reinterpret_cast<CHAR*>(&netNums), hSize);
            const auto nTSW = Net::toH(netNums[0]);
            const auto nSIG = Net::toH(netNums[1]);
            const auto nLCR = Net::toH(netNums[2]);
            const auto nSEG = Net::toH(netNums[3]);

            const auto sTSW = nTSW * sizeof(ProjItem);
            const auto sSIG = nSIG * sizeof(ProjItem);
            const auto sLCR = nLCR * sizeof(ProjItem);
            const auto sSEG = nSEG * sizeof(ProjItem);
            const auto sTOT = sTSW + sSIG + sLCR + sSEG;

            ok = (sTOT > 0) and (fsize == minSize + sTOT);

            if (ok)
            {
                UINT16 netVals[4] = {};
                static_assert(sizeof(ComSetup) == sizeof(netVals));
                is.read(reinterpret_cast<CHAR*>(&netVals), sizeof(ComSetup));
                mComSetup.portFld  = Net::toH(netVals[0]);
                mComSetup.portGui  = Net::toH(netVals[1]);
                mComSetup.portCtrl = Net::toH(netVals[2]);
                mComSetup.timeout  = Net::toH(netVals[3]);

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
