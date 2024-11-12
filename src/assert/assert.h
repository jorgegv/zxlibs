#ifndef _ZXLIBS_ASSERT_H
#define _ZXLIBS_ASSERT_H

#include <stdint.h>
#include <intrinsic.h>

/*
 * assert - define assert() macro (not the STDLIB one!)
 *
 * assert(a,code): tests that condition (a) is met, and if it is not, it
 * loads a 16-bit value (code) into address ASSERT_PANIC_ADDRESS, and then
 * jumps to assert_panic() function, which normally sets the border to
 * PANIC_COLOUR colour and hangs the machine.  A debugger can then be used
 * to break examine the hung machine and the cause of the failed assertion
 * checked at a fixed address.
 *
 * This is done using the smallest number of instructions, so that the state
 * of the machine is minimally modified before the hang.  The value stored
 * at ASSERT_PANIC_ADDRESS is meant to be a unique 16-bit code for each
 * place where the macro is used.
 *
 * Remember that the 16-bit value is stored in little endian order, so
 * 0x1234 at address 0xFFFE will be stored as 0x34,0x12 in memory
 */

#include "assert_config.h"

#ifdef _ASSERT_DEBUG
  #define assert(a,code) do { if ( !(a) ) { *(uint16_t *)ASSERT_PANIC_ADDRESS = (code); asm("jp _assert_panic"); } } while(0)
#else
  #define assert(a,code)
#endif

extern void assert_panic( void );

#endif // _ZXLIBS_ASSERT_H
