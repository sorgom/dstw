//  ============================================================
//  proj data generator
//      presets all proj data
//      with element names in reversed alphanumerical order
//      from size down to 1
//      e.g. TSW, size 100:
//          "TSW 100 *" .. "TSW 001 *"
//
//      dumps data to file
//
//      additional features
//      -   set SIG type for signal data
//      -   set LCR type for level crossing data
//  ============================================================
//  created by Manfred Sorgo

#ifndef GENPROJDATA_H
#define GENPROJDATA_H

#include <ifs/DataTypes.h>
#include <testlib/NetTest.h>
#include <testlib/testValues.h>
#include <testlib/TestLib.h>
#include <fstream>
#include <vector>

namespace test
{
    template <
        size_t NTSW = TEST_NUM_TSW,
        size_t NSIG = TEST_NUM_SIG,
        size_t NLCR = TEST_NUM_LCR,
        size_t NSEG = TEST_NUM_SEG
    >
    class GenProjData
    {
    private:
        using ProjVec = std::vector<ProjItem>;
        ProjVec mTSWs, mSIGs, mLCRs, mSEGs;

    public:
        // const ComSetup mComSetup = { tcpPortFld, tcpPortGui, tcpPortCtrl, tcpTimeout };
        const ComSetup mComSetup = {
            NetTest::toN(tcpPortFld),
            NetTest::toN(tcpPortGui),
            NetTest::toN(tcpPortCtrl),
            NetTest::toN(tcpTimeout)
        };

        GenProjData()
        {
            preset(mTSWs, "TSW", NTSW);
            preset(mSIGs, "SIG", NSIG);
            preset(mLCRs, "LCR", NLCR);
            preset(mSEGs, "SEG", NSEG);

            setSigType(TYPE_SIG_H);
            setLcrType(TYPE_LCR);
        }

        inline UINT32 numTSW() const { return mTSWs.size(); }
        inline UINT32 numSIG() const { return mSIGs.size(); }
        inline UINT32 numLCR() const { return mLCRs.size(); }
        inline UINT32 numSEG() const { return mSEGs.size(); }

        inline const ProjItem* pTSW() const { return mTSWs.data(); }
        inline const ProjItem* pSIG() const { return mSIGs.data(); }
        inline const ProjItem* pLCR() const { return mLCRs.data(); }
        inline const ProjItem* pSEG() const { return mSEGs.data(); }

        inline const ProjItem& tsw(size_t pos) const { return mTSWs.at(pos); }
        inline const ProjItem& sig(size_t pos) const { return mSIGs.at(pos); }
        inline const ProjItem& lcr(size_t pos) const { return mLCRs.at(pos); }
        inline const ProjItem& seg(size_t pos) const { return mSEGs.at(pos); }

        inline const ComAddr& tswAddr(size_t pos) const { return tsw(pos).addr; }
        inline const ComAddr& sigAddr(size_t pos) const { return sig(pos).addr; }
        inline const ComAddr& lcrAddr(size_t pos) const { return lcr(pos).addr; }
        inline const ComAddr& segAddr(size_t pos) const { return seg(pos).addr; }

        void setSigType(size_t pos, UINT8 type)
        {
            setType(mSIGs, pos, type);
        }

        void setSigType(UINT8 type)
        {
            setType(mSIGs, type);
        }

        void setLcrType(size_t pos, UINT8 type)
        {
            setType(mLCRs, pos, type);
        }

        void setLcrType(UINT8 type)
        {
            setType(mLCRs, type);
        }

        void dump(CONST_C_STRING filename) const
        {
            std::ofstream os(filename, std::ios::binary);
            if (os.good())
            {
                write(os, numTSW());
                write(os, numSIG());
                write(os, numLCR());
                write(os, numSEG());
                write(os, mComSetup);
                write(os, mTSWs);
                write(os, mSIGs);
                write(os, mLCRs);
                write(os, mSEGs);
            }
            os.close();
        }

        NOCOPY(GenProjData)

    private:

        void preset(ProjVec& vec, CONST_C_STRING what, size_t num)
        {
            vec.resize(num);
            for (auto& elem : vec)         {
                adrrElement(elem, num--, what);
            }
        }

        void setType(ProjVec& vec, size_t pos, UINT8 type)
        {
            vec.at(pos).type = type;
        }

        void setType(ProjVec& vec, UINT8 type)
        {
            for (auto& elem : vec)
            {
                elem.type = type;
            }
        }

        template <typename T>
        inline static void write(std::ofstream& os, const T& t)
        {
            os.write(reinterpret_cast<const CHAR*>(&t), sizeof(T));
        }

        inline static void write(std::ofstream& os, const UINT32 n)
        {
            const UINT32 r = NetTest::toN(n);
            os.write(reinterpret_cast<const CHAR*>(&r), sizeof(UINT32));
        }

        inline static void write(std::ofstream& os, const ProjVec& vec)
        {
            os.write(reinterpret_cast<const CHAR*>(vec.data()), sizeof(ProjItem) * vec.size());
        }
    };
} // namespace
#endif // _H
