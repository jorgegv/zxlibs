#include <stdint.h>
#include <arch/spectrum.h>

#include "print6x8.h"

void main( void ) {
    uint8_t i;
    print6x8_string_at( 10, 4, "Hey, this is a test in 6x8 font!", INK_BLUE | PAPER_WHITE | BRIGHT );
    for ( i=0; i < 42; i++ ) {
        print6x8_setpos( 12, i );
        print6x8_char( '0' + i, INK_YELLOW | PAPER_BLUE | BRIGHT );
    }
}
