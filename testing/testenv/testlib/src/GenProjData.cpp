#include <testlib/GenProjData.h>


namespace test
{
    bool DumpProjData::dump(const ProjData& data, CONST_C_STRING filename)
    {
        std::ofstream os(filename, std::ios::binary);
        const bool ok = os.good();
        if (ok)
        {
            write(os, data.numTSW);
            write(os, data.numSIG);
            write(os, data.numLCR);
            write(os, data.numSEG);
            write(os, data.pTSW, data.numTSW);
            write(os, data.pSIG, data.numSIG);
            write(os, data.pLCR, data.numLCR);
            write(os, data.pSEG, data.numSEG);
        }
        os.close();
        return ok;
    }
} // namespace    

