# Adding new modules to ZXLIBS

A module should be added to this repo this way:

- Create a dedicated directory for it under `src`, e.g. `src/sprite`
- Create a C header file (.H) with the same name as the module (e.g. `sprite.h`), and standard boilerplate (i.e. `#ifndef _SPRITE_H`... etc.)
- Add all needed C/ASM files in the module directory
- File names should start with the module name, e.g. `sprite_create.c`, `sprite_erase.asm`, etc. This will avoid name clashes.
- Function names should start with the name of the module, e.g. `void sprite_init( void )`
- All code should be heavily commented, but specially the .H file: this is the module interface for the users, so it needs to be very clear
