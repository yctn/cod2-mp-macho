/* Converted to C from ASM: MacGameEngine.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacGameEngine.cp */
/* On Linux, the Mac C++ game engine class is not needed. */
/* WinMain handles init/loop directly. Stubs provided for references. */

#include "common_types.h"
#include "imports.h"

Boolean CMacGameEngine_ProcessAllEvents(void)
{
    /* On Linux we don't have a Carbon event loop */
    return 0;
}

void CMacGameEngine_Quit(void)
{
    /* No-op on Linux */
}
