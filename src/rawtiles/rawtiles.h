#ifndef _RAWTILES_H
#define _RAWTILES_H

#include <stdint.h>

/*
 * Module for printing 8x8-pixel tiles with optional attrs to screen
 */

// rectangle structure compatible with SP1's struct sp1_Rect
struct rect_s {
   uint8_t row;
   uint8_t col;
   uint8_t width;
   uint8_t height;
};

// prints a tile at (row,col), 8 bytes at *src, with attribute
void print_tile( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr ) __z88dk_callee;

// prints a tile at (row,col), 8 bytes at *src, with attribute, masking each source byte with mask
void print_tile_masked_src( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t mask ) __z88dk_callee;

// prints a tile at (row,col), 8 bytes at *src, with attribute, masking each dest byte with mask
void print_tile_masked_dst( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t mask ) __z88dk_callee;

// prints a row of count tiles, one after another
void print_tile_row( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t count ) __z88dk_callee;

// prints a column of count tiles, one after another
void print_tile_column( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t count ) __z88dk_callee;

// prints a rectangle of tiles, one after another, in row-major order
void print_tiles( uint8_t row, uint8_t col, uint8_t *src, uint8_t attr, uint8_t nrows, uint8_t ncols ) __z88dk_callee;

// prints a rectangle of tiles, one after another, in row-major order, with separate attributes per tile
void print_tiles_with_attr( uint8_t row, uint8_t col, uint8_t *src, uint8_t *attr, uint8_t nrows, uint8_t ncols ) __z88dk_callee;

// fills a rectangle with a given tile and attribute
void clear_rectangle( struct rect_s *box, uint8_t *src, uint8_t attr ) __z88dk_callee;
extern uint8_t blank_tile[];

// clears the screen to black
void clear_screen_to_black( void );

// clears the screen to black - attributes only
void clear_attr_to_black( void );

// saves a screen area in a format suitable for printing with the above functions (pixels and attrs)
void save_screen_tiles( struct rect_s *r, uint8_t *buffer );

#endif // _RAWTILES_H
