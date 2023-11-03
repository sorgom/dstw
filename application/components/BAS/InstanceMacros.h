//  ============================================================
//  instance declaration & definiton macros
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef INSTANCEMACROS_H
#define INSTANCEMACROS_H

//  CLASS HEADER MACROS
#define INSTANCE_DEC(cName) \
    static cName& instance();

//  use this one to provide instance for IL
#define IL_INSTANCE_DEC(cName) INSTANCE_DEC(cName)

//  CLASS SOURCE FILE MACROS
#define INSTANCE_DEF(cName) \
    cName& cName::instance() \
    { \
        static cName instance; \
        return instance; \
    }

#endif // _H
