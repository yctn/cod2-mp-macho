/* Converted to C from ASM: surfaceflags.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/surfaceflags.cpp */

#include "common_types.h"
#include "imports.h"

extern int stricmp(const char *, const char *);

extern infoParm_t infoParms[53]; /* 0x0 */

int Com_SurfaceTypeFromName(const char *name)
{
    int i;

    if (stricmp(name, "default") == 0)
        return 0;

    for (i = 0; i < 22; i++) {
        if (stricmp(name, infoParms[i].name) == 0) {
            return (infoParms[i].surfaceFlags & 0x1f00000) >> 20;
        }
    }

    return -1;
}

const char *Com_SurfaceTypeToName(int iTypeIndex)
{
    if (iTypeIndex < 1 || iTypeIndex > 22)
        return "default";

    return infoParms[iTypeIndex - 1].name;
}
