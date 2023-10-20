//  ============================================================
//  ElementName generator
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef GENELEMENTNAME_H
#define GENELEMENTNAME_H

#include <ifs/DataTypes.h>
#include <testlib/TestLiterals.h>

namespace test
{
    //  preset an ElmentName for testing
    const ElementName& genElementName(UINT32 num, CONST_C_STRING name = c__ELEM);
    void genElementName(ElementName& eName, UINT32 num, CONST_C_STRING name = c__ELEM);
}


#endif // H_