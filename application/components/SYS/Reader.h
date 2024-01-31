//  ============================================================
//  class Reader implements I_Reader
//  ============================================================
#pragma once
#ifndef READER_H
#define READER_H

#include <ifs/I_Reader.h>
#include <BAS/coding.h>

class Reader : public I_Reader
{
public:
    inline Reader() = default;
    void read(CONST_C_STRING filename) const;

    IL_INSTANCE_DEC(Reader)
    NOCOPY(Reader)
};
#endif // H_