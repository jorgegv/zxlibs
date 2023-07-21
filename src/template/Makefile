##
## Generic Z88DK Makefile - Just put the Makefile in your project directory
## and drop your project .c and .asm files in the same directory.  Just type
## 'make' and get main.tap built from all your source files
##
## Provided targets:
##
##   main.tap: (default target) builds your program using all .c and .asm files in this directory
##   clean: removes intermediate build files
##   build: makes a clean target, then rebuild everything
##   run: executes FUSE emulator with the generated main.tap file
##

################################
## Build configuration
################################

# Comment this out if you want your build to be more verbose
.SILENT:

# Compiler configuration and basic flags
ZCC = zcc +zx -vn -m --list --c-code-in-asm

# Default build configuration is SCCZ80 compiler and Classic library. 
# Uncomment any of the options below if you want to change any of them

# Uncomment to use SDCC compiler
#CFLAGS += -compiler=sdcc

# Uncomment to use Newlib C library
#CFLAGS += -clib=sdcc_iy

# Additional custom CFLAGS, put them here
#CFLAGS += (...whatever)

# Additional custom LDFLAGS, put them here
#LDFLAGS += -lsp1-zx -startup=31 -lmath32 (etc)
# Minimal Newlib target LDFLAGS
#LDFLAGS = -lndos -startup=31

#############################################################
# No more configuration is normally needed below this line
#############################################################

.PHONY: clean run build

# standard TAP output
TAP_FILE = main.tap

# generic source definitions
SRCS_C          = $(wildcard *.c) $(wildcard tiles/*.c) $(wildcard sprites/*.c)
SRCS_ASM        = $(wildcard *.asm)
OBJS            = $(SRCS_C:.c=.o) $(SRCS_ASM:.asm=.o)

# generic compilation rules
%.o: %.c
	$(ZCC) $(CFLAGS) -c $*.c

%.o: %.asm
	$(ZCC) $(CFLAGS) -c $*.asm

# targets
$(TAP_FILE): $(OBJS)
	$(ZCC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o main -create-app

clean:
	-rm -f *.tap *.o *.bin *.map *.lis main *.c.lis

run:
	fuse $(TAP_FILE)

build: clean
	$(MAKE) -s -j8 $(TAP_FILE)
