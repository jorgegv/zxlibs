#ifndef _HEAP_H
#define _HEAP_H

/*
 * Initializes a heap of the given size for malloc() et al. functions
 *
 * This module _requires_ that you add the following line to your pragma
 * file:

     #pragma output CLIB_MALLOC_HEAP_SIZE  = 0       // // heap: initialized manually

 *
 * Also, this module ionly works with NEWLIB, so ensure that you are using
 * one of -clib=new, -clib=sdcc_ix or -clib=sdcc_iy options
 */

#include "heap_config.h"

void init_heap( void );

#endif // _HEAP_H
