# ZX Spectrum Game Development Modules

This repo contains Z88DK modules that can be used independently for game development on the ZX Spectrum.

## Available modules

- SPRITE: simple sprite drawing, includes preshifting. Intended to be used with a Linear Framebuffer, e.g. the OFFSCREEN module described below.
- SCROLL: multidirectional scrolling, also to be used with a linear framwbuffer
- SEQUENCE: control of animation sequences, implemented as a state machine
- INTERRUPT: basic IM2 interrupt setup and periodic task execution
- OFFSCREEN: Linear Framebuffer management and blitting to real screen
- ASSERTION: debug tool for ensuring certain conditions are met during execution

## Module usage and dependencies

These modules are intended to be copied in your game source and used as additional source files. They are not meant to be compiled as libraries, because some optimizations can be made only at compile time for performance reasons.

So to use any module, just add its C files to your `Makefile` if needed, put them together with your sources, and use the associated `#include` file to use the module functionality.

The modules are mostly self contained, except for the dependencies indicated in the following table:

| Module    | Deps      |
|-----------|-----------|
| SPRITE    | OFFSCREEN |
| SCROLL    | OFFSCREEN |
| SEQUENCE  |           |
| INTERRUPT |           |
| OFFSCREEN |           |
| ASSERTION |           |


