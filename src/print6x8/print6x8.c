#include <arch/spectrum.h>
#include <stdio.h>

#include "print6x8.h"
#include "rawtiles.h"

extern uint8_t charset6x8[];

uint8_t current_row = 0;
uint8_t current_col = 0;

uint8_t tile_buffer[ 8 ];

void shift_tile_right( uint8_t *dst, uint8_t count ) __z88dk_callee {
    uint8_t i = 8;
    while ( i-- ) dst[ i ] >>= count;
}

void shift_tile_left( uint8_t *dst, uint8_t count ) __z88dk_callee {
    uint8_t i = 8;
    while ( i-- ) dst[ i ] <<= count;
}

void copy_tile( uint8_t *dst, uint8_t *src ) __z88dk_callee {
    uint8_t i = 8;
    while ( i-- ) dst[ i ] = src[ i ];
}

// prints a char to screen in 6x8 coords (24 rows x 42 cols)
void print6x8_char( char c, uint8_t attr ) __z88dk_callee {
    uint8_t real_col;
    uint8_t *char_tile_ptr;

    // only print if char is printable
    if ( ( c >= ' ' ) && ( c <= '~' ) ) {
        char_tile_ptr = &charset6x8[ 8 * (c - ' ') ];
        // get the first cell of the 4-char group where the current 6x8 col is
        real_col = 3 * ( current_col / 4 );
        switch ( current_col % 4 ) {
            case 0:
                // char is fully on the first cell (+0)
                // preserving mask: 0x03 (00000011b)
                print_tile_masked_dst( current_row, real_col, char_tile_ptr, attr, 0x03 );
                break;
            case 1:
                // char is partially on the first and second cells (+0 and +1)
                // preserving mask: 0xFC (11111100b)
                copy_tile( tile_buffer, char_tile_ptr );
                shift_tile_right( tile_buffer, 6 );
                print_tile_masked_dst( current_row, real_col, tile_buffer, attr, 0xFC );
                // preserving mask: 0x0F (00001111b)
                copy_tile( tile_buffer, char_tile_ptr );
                shift_tile_left( tile_buffer, 2 );
                print_tile_masked_dst( current_row, real_col + 1, tile_buffer, attr, 0x0F );
                break;
            case 2:
                // char is partially on the second and third cells (+1 and +2)
                // preserving mask: 0xF0 (11110000b)
                copy_tile( tile_buffer, char_tile_ptr );
                shift_tile_right( tile_buffer, 4 );
                print_tile_masked_dst( current_row, real_col + 1, tile_buffer, attr, 0xF0 );
                // preserving mask: 0x3F (00111111b)
                copy_tile( tile_buffer, char_tile_ptr );
                shift_tile_left( tile_buffer, 4 );
                print_tile_masked_dst( current_row, real_col + 2, tile_buffer, attr, 0x3F );
                break;
            case 3:
                // char is fully on the third cell (+2)
                // preserving mask: 0xC0 (11000000b)
                copy_tile( tile_buffer, char_tile_ptr );
                shift_tile_right( tile_buffer, 2 );
                print_tile_masked_dst( current_row, real_col + 2, tile_buffer, attr, 0xC0 );
                break;
        }
    }
}

void print6x8_string( char *txt, uint8_t attr ) __z88dk_callee {
    while( *txt ) {
        if ( ( current_row <= 23 ) && ( current_col <= 42 ) ) {
            print6x8_char( *txt, attr );
            if ( ++current_col > 41 ) {
                current_col = 0;
                if ( current_row < 23 )
                    current_row++;
            }
        }
        txt++;
    }
}

void print6x8_setpos( uint8_t row, uint8_t col ) __z88dk_callee {
    current_row = row;
    current_col = col;
}

void print6x8_string_at( uint8_t row, uint8_t col, char *txt, uint8_t attr ) __z88dk_callee {
    print6x8_setpos( row, col );
    print6x8_string( txt, attr );
}

void print6x8_string_at_rec( struct print_str_rec *r ) __z88dk_fastcall {
    print6x8_setpos( r->row, r->col );
    print6x8_string( r->txt, r->attr );
}
