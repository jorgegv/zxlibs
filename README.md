# ZX Spectrum Game Development Modules

This repo contains Z88DK modules that can be used independently for game development on the ZX Spectrum.

## Available modules

- SPRITE: masked sprite drawing routines, including preshifting. Intended to be used with a Linear Framebuffer (e.g. the OFFSCREEN module described below)
- TILE: basic 8x8-pixel tile drawing routines to offscreen buffer
- BTILE: big (composite) tile drawing routines and support data structures
- SCROLL: multidirectional scrolling engine, also to be used with a linear framebuffer
- SEQUENCE: control of animation sequences, implemented as a state machine. Can be used for anything requiring some configuration and state changes at given times
- [INTERRUPT](src/interrupt): basic IM2 interrupt setup and periodic task execution (NEWLIB/CLASSIC)
- OFFSCREEN: Linear Framebuffer management and blitting to real ZX screen. The framebuffer is arranged in columnar form, for fast vertical scroll
- [ASSERT](src/assert/): debug macros for ensuring certain conditions are met during execution (NEWLIB/CLASSIC)
- [TEMPLATE](src/template/): a Makefile template which makes it easy to bootstrap new projects
- [HEAP](src/heap/): a quick heap configuration (NEWLIB only)
- [RAWTILES](src/rawtiles): basic 8x8-pixel tile drawing-to-screen routines, simple and reusable for almost any situation (NEWLIB only)
- [PRINT6X8](src/print6x8): 6x8-pixel character printing routines (NEWLIB only)

_Note: this is still a Work In Progress, I'm moving my previous libraries to this repo, so if a module you want appears listed above but you don't still see the code, please be patient :-)_

## Module usage and dependencies

These modules are intended to be copied in your game source and used as additional source files. They are not meant to be compiled as libraries, because some optimizations can be made only at compile time for performance reasons.

So to use any module, just add all the `.c` and `.h` files in the module directory (except `test.c`) to your `Makefile` sources if needed, put them together in your project's source directory, and use the associated `#include` file to use the module functionality.

There may be an optional `<module>_config.h` file in the module's directory, which contains the user-modifiable configuration for that module (if any). Copy that file also to your source directory, and modify it to suit you needs. The official header file for the module will include the config file and adjust the build for you.

If you use the TEMPLATE module (`Makefile`) from this repository, you don't need to modify anything: just drop the module files into your source directory where the `Makefile` lives and they will be automatically included in the build.

The modules are mostly self contained, except for the dependencies indicated in the following table:

| Module    | Dependencies |
|-----------|--------------|
| SPRITE    | OFFSCREEN    |
| TILE      | OFFSCREEN    |
| BTILE     | TILE         |
| SCROLL    | OFFSCREEN    |
| SEQUENCE  |              |
| INTERRUPT |              |
| OFFSCREEN |              |
| ASSERT    |              |
| TEMPLATE  |              |
| HEAP      |              |
| RAWTILES  |              |
| PRINT6X8  | RAWTILES     |
