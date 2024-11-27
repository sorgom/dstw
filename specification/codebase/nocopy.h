//  ============================================================
//  block any copying
//  ============================================================
//  created by Manfred Sorgo
#ifndef NOCOPY_H
#define NOCOPY_H

//  disable copy constructor and copy operator
#define NOCOPY(CLASS) \
CLASS(const CLASS&) = delete; \
CLASS(CLASS&&) = delete; \
CLASS& operator = (const CLASS&) = delete;

//  disable default constructor
#define NODEF(CLASS) \
CLASS() = delete;
#endif // _H
