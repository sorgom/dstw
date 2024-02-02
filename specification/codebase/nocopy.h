//  ============================================================
//  block any copying
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef NOCOPY_H
#define NOCOPY_H

//  disable copy constructor and copy operator
#define NOCOPY(CLASS) \
CLASS(const CLASS& o) = delete; \
CLASS& operator = (const CLASS& o) = delete;

//  disable default constructor
#define NODEF(CLASS) \
CLASS() = delete;

#endif // H_