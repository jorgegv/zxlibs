#include <spectrum.h>

void assert_panic( void ) __naked {
__asm
    ld a,INK_RED
    out ($fe),a
    di
    halt
__endasm;
}
