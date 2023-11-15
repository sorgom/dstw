#include <SYS/IL.h>

#include <mocks/M_Instances.h>
#include <BAS/coding.h>

#define IL_MEMB(NAME) \
    ILPLug<I_ ## NAME> m ## NAME;

// default: application instance
#define IL_CON(NAME) \
    m ## NAME(NAME::instance()),

//  default: mock only
#define IL_CON_MOCK(NAME) \
    m ## NAME(m_ ## NAME()),

#define IL_RESET(NAME) \
    m ## NAME.reset();

//  I_NAME& IL::getNAME() { return ILPLugs::instance().mNAME(); }
//  void IL::setNAME(I_NAME& ref) { ILPLugs::instance().mNAME = ref; } 
#define IL_DEF(NAME) \
    I_ ## NAME& IL::get ## NAME() { return test::ILPLugs::instance().m ## NAME.ref(); } \
    void IL::set ## NAME(I_ ## NAME& ref) { test::ILPLugs::instance().m ## NAME.set(ref); } 

namespace test
{
    template <class T>
    class ILPLug
    {
    public:
        inline ILPLug(T& ref):
            mDefault(ref),
            mPointer(&ref)
        {}

        inline void set(T& ref)
        {
            mPointer = &ref;
        }

        inline void reset()
        {
            mPointer = &mDefault;
        }

        inline T& ref() const
        {
            return *mPointer;
        }

    private:
        T& mDefault;
        T* mPointer;
        NOCOPY(ILPLug)
        ILPLug();
    };    

    class ILPLugs
    {
    public:
        INSTANCE_DEC(ILPLugs)

        void reset();

        //# IL_MEMB
        IL_MEMB(Com)
        IL_MEMB(Dispatcher)
        IL_MEMB(LCR)
        IL_MEMB(LCR_Hub)
        IL_MEMB(LCR_Provider)
        IL_MEMB(Loader)
        IL_MEMB(Log)
        IL_MEMB(SIG)
        IL_MEMB(SIG_Hub)
        IL_MEMB(SIG_Provider)
        IL_MEMB(TSW)
        IL_MEMB(TSW_Hub)
        IL_MEMB(TSW_Provider)
        //# END
        int mTerm;


        NOCOPY(ILPLugs)
        ILPLugs();
    };
    
    INSTANCE_DEF(ILPLugs)
    
    ILPLugs::ILPLugs():
        //# IL_CON : APP
        IL_CON(Com)
        IL_CON(Dispatcher)
        IL_CON(LCR_Hub)
        IL_CON(LCR_Provider)
        IL_CON(Loader)
        IL_CON(Log)
        IL_CON(SIG_Hub)
        IL_CON(SIG_Provider)
        IL_CON(TSW_Hub)
        IL_CON(TSW_Provider)
        //# END

        //# IL_CON_MOCK : MOCK
        IL_CON_MOCK(LCR)
        IL_CON_MOCK(SIG)
        IL_CON_MOCK(TSW)
        //# END
        mTerm(0)
    {}

    void ILPLugs::reset()
    {
        //# IL_RESET
        IL_RESET(Com)
        IL_RESET(Dispatcher)
        IL_RESET(LCR)
        IL_RESET(LCR_Hub)
        IL_RESET(LCR_Provider)
        IL_RESET(Loader)
        IL_RESET(Log)
        IL_RESET(SIG)
        IL_RESET(SIG_Hub)
        IL_RESET(SIG_Provider)
        IL_RESET(TSW)
        IL_RESET(TSW_Hub)
        IL_RESET(TSW_Provider)
        //# END
    }
} // namespace

//# IL_DEF
IL_DEF(Com)
IL_DEF(Dispatcher)
IL_DEF(LCR)
IL_DEF(LCR_Hub)
IL_DEF(LCR_Provider)
IL_DEF(Loader)
IL_DEF(Log)
IL_DEF(SIG)
IL_DEF(SIG_Hub)
IL_DEF(SIG_Provider)
IL_DEF(TSW)
IL_DEF(TSW_Hub)
IL_DEF(TSW_Provider)
//# END

void IL::reset()
{
    test::ILPLugs::instance().reset();
}
