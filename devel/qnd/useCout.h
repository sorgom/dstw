//  ============================================================
//  use cout for quick and dirty temporary traces
//  note
//  CI application build will fail
//  with this file (still) included
//  and merge request will be blocked
//  ============================================================
//  created by Manfred Sorgo

#ifndef USECOUT_H
#define USECOUT_H

#include <iostream>
#include <iomanip>
using std::ostream, std::cout;
#include <iomanip>
using std::setw, std::left, std::right, std::setfill, std::hex;

#include <cstdio>

#define TRACEVAR(VAR) cout << #VAR << ": " << VAR << '\n';
#endif // _H
