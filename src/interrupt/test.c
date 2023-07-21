#include <stdint.h>

#include "interrupt.h"

void my_task( void ) {
    (*(uint8_t *)0x4000)++;
}

void main( void ) {
    init_interrupts();
    interrupt_add_task( &my_task );
    while(1);
}
