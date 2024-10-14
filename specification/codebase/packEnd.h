//  ============================================================
//  end of packed alignment for data structs
//  ============================================================
//  created by Manfred Sorgo

//  prevent include guards to be inserted by script
#ifndef PACKEND_H
#define PACKEND_H
#endif // _H

//! check if packBegin.h has been included before
#ifdef IS_PACKED
    #undef IS_PACKED
    //  this works with GCC and VS
    #pragma pack (pop)
#else
    #error Missing previous #include "packBegin.h"
#endif
