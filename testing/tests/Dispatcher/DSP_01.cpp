//  ============================================================
//  test of NtpArray / NtpIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <Dispatcher/NtpArray.h>

#include <qnd/useCout.h>

namespace test
{

    TEST_GROUP_BASE(DSP_01, TestGroupBase)
    {
        
    };

    //  test type: equivalence class test
    TEST(DSP_01, T01)
    {
        cout << endl;
        TestStepper::show(1);
        SETUP()
        NtpArray<CAPACITY_ELEMENTS> data;
        NtpIndex<CAPACITY_ELEMENTS> indx(data);
        L_CHECK_EQUAL(CAPACITY_ELEMENTS, data.capacity())
        L_CHECK_EQUAL(CAPACITY_ELEMENTS, indx.capacity())
        
        STEP(1)
        Ntp tNtp;
        const UINT32 tSize = 10;

        SUBSTEPS()
        for (INT32 i = 0; i < tSize; ++i)
        {
            LSTEP(i)
            genElementName(tNtp.name, tSize - i);
            tNtp.type = 100 + i;
            tNtp.pos  = i;
            cout << i << ": " << tNtp.name << endl;
            data.add(tNtp);
        }
        ENDSTEPS()


        STEP(2)
        indx.adapt();

        STEP(3)
        for (INT32 i = 0; i < tSize; ++i)
        {
            cout << i << ": " << indx[i].ref().name << endl;
        }

        STEP(4)
        SUBSTEPS()
        for (INT32 i = 0; i < tSize; ++i)
        {
            LSTEP(i)
            const ElementName& en = genElementName(tSize - i);
            cout << i << ": " << en << endl;
            const INT32 f = indx.findNtp(en);
            cout << " -> " << f << endl;
        }
        ENDSTEPS()


        // STEP(2)
        // //  test unsorted data as loaded
        // SUBSTEPS()
        // for (INT32 i = 0; i < a.size(); ++i)
        // {
        //     LSTEP(i)
        //     const Idata& d = a[i];
        //     L_CHECK_EQUAL(-i, d.m1)
        //     L_CHECK_EQUAL( i, d.m2)
        // }
        // ENDSTEPS()
        
        // STEP(3)
        // //  apply sort()
        // //  test sorted data
        // a.sort();
        // const INT32 of = a.size() - 1;
        // SUBSTEPS()
        // for (INT32 i = 0; i < a.size(); ++i)
        // {
        //     LSTEP(i)
        //     const Idata& d = a[i];
        //     L_CHECK_EQUAL(-of + i, d.m1)
        //     L_CHECK_EQUAL( of - i, d.m2)
        // }
        // ENDSTEPS()

        // STEP(4)
        // //  apply find() to const object
        // const IdataArray& c = a;
        // SUBSTEPS()
        // for (INT32 i = 0; i < a.size(); ++i)
        // {
        //     LSTEP(i)
        //     const INT32 p = c.find(c[i]);
        //     L_CHECK_EQUAL(i, p)
        // }
        // ENDSTEPS()
    }

    // //  test type: equivalence class test
    // //  test of StackArray: with placement new
    // TEST(DSP_01, T02)
    // {
    //     STEP(1)
    //     IdataArray a;

    //     for (INT32 i = 0; i < a.capacity(); ++i)
    //     {
    //         L_CHECK_FALSE(a.isFull())
    //         new (a.addPtr()) Idata(-i, i);
    //     }
    //     L_CHECK_EQUAL(a.capacity(), a.size())
    //     L_CHECK_TRUE(a.isFull())

    //     STEP(2)
    //     //  test unsorted data as loaded
    //     SUBSTEPS()
    //     for (INT32 i = 0; i < a.size(); ++i)
    //     {
    //         LSTEP(i)
    //         const Idata& d = a[i];
    //         L_CHECK_EQUAL(-i, d.m1)
    //         L_CHECK_EQUAL( i, d.m2)
    //     }
    //     ENDSTEPS()
    // }

    // //  test type: equivalence class test
    // //  test of StackArrayIndex
    // TEST(DSP_01, T03)
    // {
    //     STEP(1)
    //     //  create array
    //     //  load data
    //     IdataArray a;
    //     IdataIndex ix(a);
    //     L_CHECK_EQUAL(a.capacity(), ix.capacity())

    //     for (INT32 i = 0; i < a.capacity(); ++i)
    //     {
    //         a.add(Idata(-i, i));
    //     }
    //     L_CHECK_TRUE(a.isFull())

    //     STEP(2)
    //     //  adapt index
    //     //  find all data in index
    //     ix.adapt();
    //     L_CHECK_TRUE(ix.isFull())
    //     SUBSTEPS()
    //     for (INT32 i = 0; i < a.size(); ++i)
    //     {
    //         LSTEP(i)
    //         const Idata& d = a[i];
    //         const INT32  f = ix.findRef(d);
    //         const Idata& r = ix.getRef(f);
    //         L_CHECK_EQUAL(d.m1, r.m1)
    //         L_CHECK_EQUAL(d.m2, r.m2)
    //     }
    //     ENDSTEPS()
    // }
    // //  test type: equivalence class test
    // //  test of NtpArray / NtpIndex
    // TEST(DSP_01, T04)
    // {

    // }
} // namespace
