#ifndef _ZXLIBS_ASSERT_H
#define _ZXLIBS_ASSERT_H

#include <stdint.h>
#include <intrinsic.h>

#define ASSERT_PANIC_ADDRESS    0xFFFE

#ifdef __DEBUG
  #define assert(a,code) do { if ( !(a) ) *(uint16_t *)ASSERT_PANIC_ADDRESS = (code); intrinsic_di(); intrinsic_halt(); } while(0)
#else
  #define assert(a,code)
#endif

#endif // _ZXLIBS_ASSERT_H
