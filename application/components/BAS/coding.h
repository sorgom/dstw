//  ============================================================
//  misc coding enhancers
//  ============================================================
//  created by Manfred Sorgo
#pragma once

#include <codebase/BaseTypes.h>
#include <codebase/nocopy.h>

//  enable usage of "and", "or" 
#include <ciso646>

//  put into empty if / else branches for coverage
inline void pass() {}

//  unified instance declaration
#define INSTANCE_DEC(NAME) \
    static NAME& instance();

//  unified instance definition
#define INSTANCE_DEF(NAME) \
    NAME& NAME::instance() \
    { \
        static NAME instance; \
        return instance; \
    }
