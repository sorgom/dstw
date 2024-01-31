//  ============================================================
//  class MemStream saves file io for testing
//  ============================================================
//  created by Manfred Sorgo
//  source:
//  https://tuttlem.github.io/2014/08/18/getting-istream-to-work-off-a-byte-array.html
#pragma once
#ifndef MEMSTREAM_H
#define MEMSTREAM_H

#include <istream>

namespace test
{
    class MemStream : public std::istream 
    {
    public:
        inline MemStream(const void* ptr, size_t size):
            std::istream(&mBuf),
            mBuf(ptr, size)
        {
            rdbuf(&mBuf);
        }

    private:
        class MemBuf : public std::basic_streambuf<char>
        {
        public:
            inline MemBuf(const void* p, size_t size)
            {
                setg((char*) p, (char*) p, (char*) p + size);
            }
        };
        MemBuf mBuf;
    };

} // namespace
#endif // H_