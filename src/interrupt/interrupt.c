#include <intrinsic.h>
#include <stdint.h>
#include <string.h>

#include "interrupt.h"

#if ( ( (ISR_ADDR) / 256 ) != ( (ISR_ADDR) % 256 ) )
    #error ISR_ADDR address low and high bytes must be equal!
#endif

#if ( ( (ISR_ADDR) >= (VECTOR_TABLE_ADDR) ) && ( (ISR_ADDR) <= (VECTOR_TABLE_ADDR) + 256 ) )
    #error ISR_ADDR falls inside the vector table at VECTOR_TABLE_ADDR!
#endif

typedef void (*func_p)( void );

struct interrupt_task_s {
    uint8_t num_tasks;
    func_p tasks[ MAX_INTERRUPT_TASKS ];
} interrupt_tasks;

uint32_t global_frame_counter;

uint8_t interrupt_initialized = 0;

void my_isr( void ) __interrupt {
    static uint8_t i;
    global_frame_counter++;
    // if there are registered tasks, run them in order
    if ( interrupt_tasks.num_tasks )
        for ( i = 0; i < interrupt_tasks.num_tasks; i++ )
            (*(func_p *)interrupt_tasks.tasks[ i ])();
}

void init_interrupts( void ) {
    // setup tasks
    interrupt_tasks.num_tasks = 0;

    // setup interrupt table and vector
    intrinsic_di();
    memset( (void *) VECTOR_TABLE_ADDR, (ISR_ADDR) / 256, 257 );
    *(uint8_t *)(ISR_ADDR) = 0xC3;			// JP opcode
    *(uint16_t *)(ISR_ADDR + 1) = (uint16_t) &my_isr;	// destination for JP

__asm
    ld a,0xD0
    ld i,a
    im 2
__endasm;

    // reset counter and set initialized flag
    global_frame_counter = 0;
    interrupt_initialized = 1;

    // enable ints
    intrinsic_ei();
}

void interrupt_add_task( void *func ) {
    if ( ! interrupt_initialized )
        return;

    if ( interrupt_tasks.num_tasks < MAX_INTERRUPT_TASKS ) {
        // ints must be disabled while adding this function
        intrinsic_di();
        interrupt_tasks.tasks[ interrupt_tasks.num_tasks++ ] = func;
        intrinsic_ei();
    }
}
