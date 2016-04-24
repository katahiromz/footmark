// a.hpp --- footmark sample
// This file is public domain software (PDS).
///////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include "footmark.hpp"

int func_2(void);

int func_1(void) {
  FOOTMARK();
  func_2();
  return 0;
}

int main(void) {
  FOOTMARK();
  func_1();
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
