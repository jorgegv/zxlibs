#include <stdint.h>
#include <alloc.h>

#include "heap_config.h"

#pragma output CLIB_MALLOC_HEAP_SIZE  = 0       // // heap: initialized manually

#define HEAP_START (&heap[0]) 

uint8_t heap[ HEAP_SIZE ];

uint8_t *_malloc_heap;

void init_heap( void ) {
    _malloc_heap = HEAP_START;
    heap_init( HEAP_START, HEAP_SIZE );
}
