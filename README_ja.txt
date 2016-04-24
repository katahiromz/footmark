(Japanese, UTF-8)

footmark --- C++デバッグ用の足跡
--------------------------------

このライブラリ（footmark）は、FOOTMARK() と FOOTMARK_PRINT_CALL_STACK()
マクロを定義します。デバッグ時には、FOOTMARK() は次のような出力を生成します。

    a.cpp (13): entering main
    a.cpp (7): entering func_1
    b.cpp (5): entering func_2
    b.cpp: leaving func_2
    a.cpp: leaving func_1
    a.cpp: leaving main

すべての関数定義の先頭に FOOTMARK() を置くといいかもしれないです。

FOOTMARK_PRINT_CALL_STACK() マクロは次のような出力を生成します。

    ### CALL STACK ###
    + a.cpp (13): main
    + a.cpp (7): func_1
    + b.cpp (5): func_2

デバッグ出力用に DebugPrint を定義するといいかもしれません。
詳しくは、ソースをご覧下さい。

/////////////////////////////////////////////////////
// Katayama Hirofumi MZ (katahiromz) [ANT]
// Homepage     http://katahiromz.web.fc2.com/
// BBS          http://katahiromz.bbs.fc2.com/
// E-Mail       katayama.hirofumi.mz@gmail.com
/////////////////////////////////////////////////////
