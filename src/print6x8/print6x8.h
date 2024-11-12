#ifndef _PRINT6X8_H
#define _PRINT6X8_H



#include <stdint.h>

struct print_str_rec {
    uint8_t row;
    uint8_t col;
    char *txt;
    uint8_t attr;
};

void print6x8_char( char c, uint8_t attr ) __z88dk_callee;
void print6x8_string( char *txt, uint8_t attr ) __z88dk_callee;
void print6x8_setpos( uint8_t row, uint8_t col ) __z88dk_callee;
void print6x8_string_at( uint8_t row, uint8_t col, char *txt, uint8_t attr ) __z88dk_callee;
void print6x8_string_at_rec( struct print_str_rec *r ) __z88dk_fastcall;

#endif // _PRINT6X8_H
