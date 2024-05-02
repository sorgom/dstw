# testing

## CppUTest
CppUTest is the base of testing in this project for good reasons:

-   it's lean and fast
-   it runs on almost every device
-   the greatest advantage to other frameworks: it natively handles unexpected calls as well as expected calls that aren't fulfilled

## module tests
### Interface Locator (IL)
The Interface Locator is a light weight version of the service locator pattern.

In test context every module instance that realizes an interface is substituted by a mock.

The software compiled for production does not provide any substitution of the modules in charge.

The whole thing is achieved by different include paths leading to two different IL.h headers.

#### header for production build 
```cpp
namespace IL
{
    inline I_Com& getCom() { return Com::instance(); }
    inline I_Dispatcher& getDispatcher() { return Dispatcher::instance(); }
    inline I_Log& getLog() { return Log::instance(); }
    inline I_Provider& getLCR_Provider() { return LCR_Provider::instance(); }
    inline I_Provider& getSIG_Provider() { return SIG_Provider::instance(); }
    inline I_Provider& getTSW_Provider() { return TSW_Provider::instance(); }
    inline I_Reader& getReader() { return Reader::instance(); }
    ...
}
```
#### header for test build 
```cpp
namespace IL
{
    inline I_Com& getCom() { return test::m_Com(); }
    inline I_Dispatcher& getDispatcher() { return test::m_Dispatcher(); }
    inline I_Log& getLog() { return test::m_Log(); }
    inline I_Provider& getLCR_Provider() { return test::m_LCR_Provider(); }
    inline I_Provider& getSIG_Provider() { return test::m_SIG_Provider(); }
    inline I_Provider& getTSW_Provider() { return test::m_TSW_Provider(); }
    inline I_Reader& getReader() { return test::m_Reader(); }
    ...
}
```
This concept has been SIL4 validated already.

### module test principle
If testing a single application module (SUT, software under test)
-   we describe expected calls to other modules,
-   trigger the SUT by method calls
-   and check if the mocked modules were called as expected.

### sample: test of dispatcher
#### mocks and calls scheme

![test Dispatcher](../specification/doc/test_dispatcher.svg) 

#### sample test code
```cpp
        STEP(1)
        //  setup test data
        const ComData data{55, 66};
        //  prepare expected telegram
        ComTele teleExp{{}, data};
        nameElement(teleExp, 1, "TSW");
        //  describe expectation for mock:
        //  Com method toFld must be called with telegram
        m_Com().expectToFld(teleExp);
        //  call Dispatcher's toFld method with data
        dsp.toFld(0, data);
        //  check if exactly this has happened
        CHECK_N_CLEAR()

```

## system tests
Here we have 
-   a DSTW application built without any test code
-   a test application 

The system tests take place that way:
- At startup the DSTW application reads project data provided for testing
- The test application then communicates via TCP   

![system tests](../specification/doc/sys_tests.svg) 

## code coverage
for current current code coverage see [coverage.md](coverage.md)

## used APIs
-   [CppUTestSteps](https://github.com/sorgom/CppUTestSteps)

