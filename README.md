# ZX Spectrum Game Development Modules

This repo contains Z88DK modules that can be used independently for game development on the ZX Spectrum.

## Available modules

- SPRITE: simple sprite drawing, includes preshifting. Intended to be used with a Linear Framebuffer, e.g. the OFFSCREEN module described below.
- SCROLL: multidirectional scrolling, also to be used with a linear framwbuffer
- SEQUENCE: control of animation sequences, implemented as a state machine
- INTERRUPT: basic IM2 interrupt setup and periodic task execution
- OFFSCREEN: Linear Framebuffer management and blitting to real screen
- [ASSERT](src/assert/): debug macros for ensuring certain conditions are met during execution
- [TEMPLATE](src/template/): a Makefile template which makes it easy to bootstrap new projects

_Note: this is still a Work In Progress, I'm moving my previous libraries to this repo, so if a module you want appears listed above but you don't still see the code, please be patient :-)_

## Module usage and dependencies

These modules are intended to be copied in your game source and used as additional source files. They are not meant to be compiled as libraries, because some optimizations can be made only at compile time for performance reasons.

So to use any module, just add its C files to your `Makefile` if needed, put them together with your sources, and use the associated `#include` file to use the module functionality.

If you use the TEMPLATE `Makefile` from this repository, you don't need to modify anything: just drop the module files into your source directory where the `Makefile` lives and they will be automatically included in the build.

The modules are mostly self contained, except for the dependencies indicated in the following table:

| Module    | Deps             |
|-----------|------------------|
| SPRITE    | OFFSCREEN,ASSERT |
| SCROLL    | OFFSCREEN,ASSERT |
| SEQUENCE  | ASSERT           |
| INTERRUPT | ASSERT           |
| OFFSCREEN | ASSERT           |
| ASSERT    |                  |
| TEMPLATE  |                  |
