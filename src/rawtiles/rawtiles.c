#include <arch/spectrum.h>
#include <string.h>

#include "rawtiles.h"

// utility blank tile definition
uint8_t blank_tile[ 8 ] = { 0,0,0,0,0,0,0,0 };

////////////////////////
// Printing routines
////////////////////////

void print_tile( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr ) __z88dk_callee{
    uint8_t *dst = zx_cxy2saddr( col, row );
    uint8_t i;
    for ( i = 0; i < 8; i++ ) {
       *dst = *src++;
       dst = zx_saddrpdown( dst );
    }
    *zx_cxy2aaddr( col, row ) = attr;
}

void print_tile_masked_src( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t mask ) __z88dk_callee {
    uint8_t *dst = zx_cxy2saddr( col, row );
    uint8_t i;
    for ( i = 0; i < 8; i++ ) {
       *dst = (*src++) & mask;
       dst = zx_saddrpdown( dst );
    }
    *zx_cxy2aaddr( col, row ) = attr;
}

void print_tile_masked_dst( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t mask ) __z88dk_callee {
    uint8_t *dst = zx_cxy2saddr( col, row );
    uint8_t i;
    for ( i = 0; i < 8; i++ ) {
       *dst = ( *dst & mask ) | *src++;
       dst = zx_saddrpdown( dst );
    }
    *zx_cxy2aaddr( col, row ) = attr;
}

void print_tile_row( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t count ) __z88dk_callee {
    while ( count-- ) {
        print_tile( row, col, src, attr );
        col++;
        src += 8;
    }
}

void print_tile_column( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t count ) __z88dk_callee {
    while ( count-- ) {
        print_tile( row, col, src, attr );
        row++;
        src += 8;
    }
}

void print_tiles( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t nrows, uint8_t ncols ) __z88dk_callee {
    uint8_t i,j;
    for ( i=0; i < nrows; i++ )
        for ( j=0; j < ncols; j++ ) {
            print_tile( row + i, col + j, src, attr );
            src += 8;
        }
}

void print_tiles_with_attr( uint8_t row, uint8_t col, uint8_t *src, uint8_t *attr, uint8_t nrows, uint8_t ncols ) __z88dk_callee {
    uint8_t i,j;
    for ( i=0; i < nrows; i++ )
        for ( j=0; j < ncols; j++ ) {
            print_tile( row + i, col + j, src, *attr );
            src += 8;
            attr++;
        }
}

void clear_rectangle( struct rect_s *box, uint8_t *src, uint8_t attr ) __z88dk_callee {
    uint8_t row = box->row;
    uint8_t h = box->height;
    while( h-- ) {
        uint8_t col = box->col;
        uint8_t w = box->width;
        while ( w-- )
            print_tile( row, col++, src, attr );
        row++;
    }
}

void clear_screen_to_black( void ) {
    __asm
    ld hl,0x4000
    xor a
    ld (hl),a
    ld de,0x4001
    ld bc,6911
    ldir
    __endasm;
}

void clear_attr_to_black( void ) {
    __asm
    ld hl,0x5800	;; start ot attr area
    xor a
    ld (hl),a
    ld de,0x5801
    ld bc,767
    ldir
    __endasm;
}

void save_tile_pixels( uint8_t row, uint8_t col, uint8_t *buffer ) {
    uint8_t i = 8;
    uint8_t *addr = zx_cxy2saddr( col, row );
    while ( i-- ) {
        *buffer++ = *addr;
        addr += 256;
    }
}

void save_screen_tiles( struct rect_s *r, uint8_t *buffer ) {
    uint8_t i,j;

    // save pixel data
    for ( i = r->row; i < r->row + r->height; i++ ) {
        for ( j = r->col; j < r->col + r->width; j++ ) {
            save_tile_pixels( i, j, buffer );
            buffer += 8;
        }
    }

    // save attr data
    for ( i = r->row; i < r->row + r->height; i++ )
        for ( j = r->col; j < r->col + r->width; j++ )
            *buffer++ = *zx_cxy2aaddr( j, i );
}
