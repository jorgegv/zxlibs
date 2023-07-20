// zcc +zx -vn test.c -o test -create-app -m --list --c-code-in-asm

#include <stdint.h>

#define _ASSERT_DEBUG

#include "assert.h"

uint8_t pepe = 16;

void main(void) {
    assert( pepe == 16, 0x5678 );
    assert( pepe == 17, 0x1234 );
    while(1);
}
