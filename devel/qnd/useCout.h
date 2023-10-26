//  ============================================================
//  use cout for quick and dirty temporary traces
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef USECOUT_H
#define USECOUT_H

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::setfill;

#include <cstdio>

#define TRACEVAR(VAR) cout << #VAR << ": " << VAR << endl;

#endif // H_