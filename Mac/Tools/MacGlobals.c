/* Converted to C from ASM: MacGlobals.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacGlobals.cp */

#include "common_types.h"
#include "imports.h"

static int sSystemLock;

void MacGlobals_LockSystem(void)
{
    sSystemLock++;
}

void MacGlobals_UnlockSystem(void)
{
    if (sSystemLock > 0)
        sSystemLock--;
}

bool MacGlobals_IsSystemLocked(void)
{
    return sSystemLock > 0;
}
