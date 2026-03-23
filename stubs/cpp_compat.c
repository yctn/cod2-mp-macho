/* C++ symbol wrappers: Mac double-underscore to Linux single-underscore */
/* These are needed because Mach-O prepends _ to all C symbols, so C++ mangled
   names like _ZNSsD1Ev become __ZNSsD1Ev in Mach-O. Our ASM code still uses
   the Mach-O convention. We wrap them here. */

#include <stdlib.h>

/* For each double-underscore symbol, we define a function that calls the 
   single-underscore version. Using asm labels is the cleanest approach. */

/* operator new / delete - Mach-O double underscore wrappers */
void *_Znwm(unsigned int n) { return malloc(n); }
void *_Znam(unsigned int n) { return malloc(n); }
void *__Znwm(unsigned int n) { return malloc(n); }
void *__Znam(unsigned int n) { return malloc(n); }
void _ZdlPv(void *p) { free(p); }
void __ZdlPv(void *p) { free(p); }
void _ZdaPv(void *p) { free(p); }
void __ZdaPv(void *p) { free(p); }

