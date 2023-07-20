// zcc +zx -vn test.c -o test -create-app -m --list --c-code-in-asm

#include <stdint.h>

#define __DEBUG

#include "assert.h"

uint8_t pepe = 16;

void main(void) {
    assert( pepe == 17, 0x1234 );
    while(1);
}
