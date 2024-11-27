//  ============================================================
//  misc coding enhancers
//  ============================================================
//  created by Manfred Sorgo
#ifndef CODING_H
#define CODING_H

#include <codebase/BaseTypes.h>
#include <codebase/nocopy.h>

//  enable usage of "and", "or", "not" in place of "&&", "||", "!"
#include <ciso646>

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
#endif // _H
