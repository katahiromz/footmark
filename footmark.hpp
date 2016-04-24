// footmark.hpp --- footmark for C++ debugging
// This file is public domain software (PDS)
///////////////////////////////////////////////////////////////////////////////

#ifndef FOOTMARK_HPP_
#define FOOTMARK_HPP_   1   // Version 1

#ifndef __cplusplus
  #error This library (footmark) needs C++. You lose.
#endif

///////////////////////////////////////////////////////////////////////////////
// DebugPrint

#ifndef DebugPrint
  #include <cstdio>
  #define DebugPrint  printf
#endif

///////////////////////////////////////////////////////////////////////////////
// FootmarkLocation and FootmarkPrintCallStack (on debugging)

#ifndef NDEBUG
  #include <vector>   // for std::vector
  #include <cassert>  // for assert

  struct FootmarkLocation {
    const char *m_file;
    int         m_line;
    const char *m_func;
    bool        m_flag;
    FootmarkLocation() :
      m_file(NULL), m_line(0), m_func(NULL), m_flag(false) {}
    FootmarkLocation(const char *file, int line, const char *func) :
      m_file(file), m_line(line), m_func(func), m_flag(true) { Enter(); }
    FootmarkLocation(const FootmarkLocation& location) :
      m_file(location.m_file), m_line(location.m_line),
      m_func(location.m_func), m_flag(false) {}
    FootmarkLocation& operator=(const FootmarkLocation& location) {
      m_file = location.m_file;
      m_line = location.m_line;
      m_func = location.m_func;
      m_flag = false;
      return *this;
    }
    ~FootmarkLocation() { if (m_flag) { Leave(); } }
    void Enter();
    void Leave();
  };

  inline std::vector<FootmarkLocation>& GetFootmarkStack() {
    static std::vector<FootmarkLocation> s_stack;
    return s_stack;
  }

  inline void FootmarkLocation::Enter() {
    GetFootmarkStack().push_back(*this);
    DebugPrint("%s (%u): entering %s\n", m_file, m_line, m_func);
  }
  inline void FootmarkLocation::Leave() {
    if (GetFootmarkStack().size()) {
      DebugPrint("%s: leaving %s\n", m_file, m_func);
      GetFootmarkStack().pop_back();
    } else {
      DebugPrint("Footmark: ERROR: stack was broken.\n");
      DebugPrint("Footmark: NOTE: DebugPrint must be thread-safe.\n");
      assert(0);
    }
  }

  inline void FootmarkPrintCallStack() {
    DebugPrint("CALL STACK:\n");
    const std::vector<FootmarkLocation>& stack = GetFootmarkStack();
    for (size_t i = 0; i < stack.size(); ++i) {
      DebugPrint("+ %s (%u): %s\n", stack[i].m_file, stack[i].m_line,
                 stack[i].m_func);
    }
  }
#endif  // ndef NDEBUG

///////////////////////////////////////////////////////////////////////////////
// FOOTMARK(), FOOTMARK_PRINT_CALL_STACK() macros

#ifndef NDEBUG
  #define FOOTMARK() \
    FootmarkLocation \
      object_for_debugging_##__LINE__(__FILE__, __LINE__, __func__);
  #define FOOTMARK_PRINT_CALL_STACK() FootmarkPrintCallStack()
#else
  #define FOOTMARK()                  /*empty*/
  #define FOOTMARK_PRINT_CALL_STACK() /*empty*/
#endif

///////////////////////////////////////////////////////////////////////////////

#endif  // ndef FOOTMARK_HPP_

///////////////////////////////////////////////////////////////////////////////
