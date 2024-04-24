//  ============================================================
//  block any copying
//  ============================================================
//  created by Manfred Sorgo
#pragma once

//  disable copy constructor and copy operator
#define NOCOPY(CLASS) \
CLASS(const CLASS&) = delete; \
CLASS(CLASS&&) = delete; \
CLASS& operator = (const CLASS&) = delete;

//  disable default constructor
#define NODEF(CLASS) \
CLASS() = delete;
