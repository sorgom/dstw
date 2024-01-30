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
        }
        return ok;
    }
} // namespace    

// UINT32 numTSW;
//     UINT32 numSIG;
//     UINT32 numLCR;
//     UINT32 numSEG;