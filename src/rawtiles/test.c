#include <stdint.h>
#include <arch/spectrum.h>

#include "rawtiles.h"

uint8_t my_tile[ 8 ] = { 128, 192, 224, 240, 248, 252, 254, 255 };

void main( void ) {
    uint8_t i,j;
    for ( i = 6; i < 16; i++ )
        for ( j = 10; j < 20; j++ )
            print_tile( i, j, my_tile, INK_RED | PAPER_WHITE | BRIGHT );
}
