#include <cstdio>
#include "footmark.hpp"

int func_2(void) {
  FOOTMARK();
  FOOTMARK_PRINT_CALL_STACK();
  return 0;
}
