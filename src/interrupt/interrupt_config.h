// module configuration - you can change these values and the module will be
// reconfigured according to them

// maximum number of interrupt functions that will be called
#define MAX_INTERRUPT_TASKS	4

// base for the interrupt vector table (257 bytes with the same value)
#define VECTOR_TABLE_ADDR	0xd000

// the address where the JP <isr_address> will be patched (3 bytes) this
// addres must have the low and high bytes equal, i.e.  0xd1d1, 0xa0a0, etc.
#define	ISR_ADDR		0xd1d1
