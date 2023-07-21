# Adding new modules to ZXLIBS

A module should be added to this repo this way:

- Create a dedicated directory for it under `src`, e.g. `src/sprite`
- Create a C header file (`.h`) with the same name as the module (e.g. `sprite.h`), and standard boilerplate (i.e. `#ifndef _SPRITE_H`... etc.)
- (Optional) Create a C header file (`.h`) named `<module>_config.h` which contains the user-configurable definitions for the new module (e.g. size of scroll area, maximum number of sprites, etc.)
- Ensure the official include file (e.g. `sprite.h`) includes the config one (`#include sprite_config.h`)
- Add all needed module C and ASM files to the module directory
- File names should start with the module name, e.g. `sprite_create.c`, `sprite_erase.asm`, etc. This will avoid name clashes.
- Function names should start with the name of the module, except the initialization function, if there is any: e.g. `void init_sprites( void )`, `void sprite_draw( void )`, etc.
- All code should be heavily commented, but specially the .H file: this is the module interface for the users, so it needs to be very clear. At least each function prototype should be clearly commented amd its parameters and return values explained in the comments.
