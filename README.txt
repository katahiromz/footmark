footmark --- footmark for C++ debugging
---------------------------------------

This library (footmark) defines FOOTMARK() and FOOTMARK_PRINT_CALL_STACK()
macros. On debugging, FOOTMARK() generates output as follows:

    a.cpp (13): entering main
    a.cpp (7): entering func_1
    b.cpp (5): entering func_2
    b.cpp: leaving func_2
    a.cpp: leaving func_1
    a.cpp: leaving main

You may want to put FOOTMARK() at top of every function definition.

The FOOTMARK_PRINT_CALL_STACK() macro generates output as follows:

    test.c (3): FOOTMARK_PRINT_CALL_STACK()
    ### CALL STACK ###
    + a.cpp (13): main
    + a.cpp (7): func_1
    + b.cpp (5): func_2

You may pre-#define the DebugPrint function macro for debugging output.
For more details, please see source.

/////////////////////////////////////////////////////
// Katayama Hirofumi MZ (katahiromz) [ANT]
// Homepage     http://katahiromz.web.fc2.com/
// BBS          http://katahiromz.bbs.fc2.com/
// E-Mail       katayama.hirofumi.mz@gmail.com
/////////////////////////////////////////////////////
