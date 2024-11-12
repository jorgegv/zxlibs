#include <spectrum.h>

#include "assert.h"

void assert_panic( void ) __naked {
__asm
    ld a,PANIC_COLOUR
    out ($fe),a
    di
    halt
__endasm;
}
