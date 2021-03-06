// a.hpp --- footmark sample
// This file is public domain software (PDS).
///////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#ifdef _WIN32
  #include <windows.h>
#endif
#include "footmark.hpp"

int func_2(void);

int func_1(void) {
  FOOTMARK_FORMAT("We entered func_%d. One plus one is %d.\n", 1, 1 + 1);
  func_2();
  FOOTMARK_RETURN_INT(0);
}

void func_5(void) {
  FOOTMARK();
  *(char *)NULL = 0;
}

void func_4(void) {
  FOOTMARK();
  func_5();
}

void func_3(void) {
  FOOTMARK();
  func_4();
}

#ifdef _WIN32
  LONG WINAPI MyUnhandledExceptionFilter(PEXCEPTION_POINTERS ExceptionInfo) {
    FootmarkDebugPrint("### Abnormal Status ###\n");
    FOOTMARK_PRINT_CALL_STACK();
    fflush(stdout);
    return EXCEPTION_EXECUTE_HANDLER;
  }
#endif

int main(void) {
  FOOTMARK();
  func_1();
#ifdef _WIN32
  ::SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);
  func_3();
#endif
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
