//  coverage instrumentation exception handling
//  > works with compilers
//      that support _Pragma(string-literal) directive
//  - documented for:
//    - gcc : https://gcc.gnu.org/onlinedocs/cpp/Pragmas.html
//    - msvc: https://learn.microsoft.com/en-us/cpp/preprocessor/pragma-directives-and-the-pragma-keyword

//  created by Manfred Sorgo
#ifndef COVERAGE_H
#define COVERAGE_H

//  bullseye coverage
#if _BullseyeCoverage
    // pause coverage instrumentation
    #define COVERAGE_PAUSE _Pragma("BullseyeCoverage off")
    // resume coverage instrumentation
    #define COVERAGE_RESUME _Pragma("BullseyeCoverage on")
    // force coverage of simple boolean expressions
    // by converting them to ternary expressions
    #define B(SIMPLE_EXPR) (SIMPLE_EXPR ? true : false)
#else
    #define COVERAGE_PAUSE
    #define COVERAGE_RESUME
    #define B(SIMPLE_EXPR) SIMPLE_EXPR
#endif

#endif // _H
