#ifndef _ZXLIBS_INTERRUPT_H
#define _ZXLIBS_INTERRUPT_H

#include <stdint.h>

extern uint32_t global_frame_counter;

/*
 * Set up IM2 mode with an interrupt table at $D000-$D100 (inclusive),
 * jumping to $D1D1 and from there to the main ISR.  This leaves a hole from
 * $D101 to $D1D0 (208 bytes) that very conveniently can be used for the
 * stack.  Set initial stack ptr to $D1D0 to do this.
 */

void init_interrupts( void );

// Add a function to be called on every interrupt.  Will be called with
// interrupts disabled

void interrupt_add_task( void *func );

#endif // _ZXLIBS_INTERRUPT_H
