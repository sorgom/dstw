//  ============================================================
//  misc coding enhancers
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef CODING_H
#define CODING_H

#include <BAS/BaseTypes.h>

//  enable usage of "and", "or" 
#include <ciso646>

//  put into empty if / else branches for coverage
inline void pass() {}

//  disable copy constructor and copy operator
#define NOCOPY(CLASS) \
CLASS(const CLASS& o) = delete; \
CLASS& operator = (const CLASS& o) = delete;

#define NODEF(CLASS) \
CLASS() = delete;

//  unified instance declaration
#define INSTANCE_DEC(NAME) \
    static NAME& instance();

//  unified instance declaration for IL modules
#define IL_INSTANCE_DEC(NAME) INSTANCE_DEC(NAME)

//  unified instance definition
#define INSTANCE_DEF(NAME) \
    NAME& NAME::instance() \
    { \
        static NAME instance; \
        return instance; \
    }

#endif // H_