/* Converted to C from ASM: MacGameEngine.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacGameEngine.cp */
/* On Linux, the Mac C++ game engine class is not needed. */
/* WinMain handles init/loop directly. Stubs provided for references. */

#include "common_types.h"
#include "imports.h"

typedef struct {
    const char *value;
    UInt32 reserved[6];
} MacGameEngineProductTagStorage;

__attribute__((used)) static const char *kBuildTag = "Posted-04/18/06"; /* 0x3083a0 */
__attribute__((used)) static MacGameEngineProductTagStorage kProductTag = {
    "2FF037E8990B11DAA29C000A95675086",
    {0, 0, 0, 0, 0, 0},
}; /* 0x3083a4 */

Boolean CMacGameEngine_ProcessAllEvents(void)
{
    /* On Linux we don't have a Carbon event loop */
    return 0;
}

void CMacGameEngine_Quit(void)
{
    /* No-op on Linux */
}
