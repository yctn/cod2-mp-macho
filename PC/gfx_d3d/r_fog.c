/* Converted to C from ASM: r_fog.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_fog.cpp */

#include "common_types.h"
#include "imports.h"

typedef void (*ArchiveProc)(MemoryFile *, int, void *);

extern r_globals_t *rg; /* imp_rg */

void R_ClearFogs(void)
{
    memset(rg->fogSettings, 0, sizeof(rg->fogSettings));
    rg->fogIndex = 0;
}

void R_SetFog(int fogvar, float start, float end, int r, int g, int b, float density)
{
    GfxFog *fog = &rg->fogSettings[fogvar];

    fog->color.array[0] = (byte)b;
    fog->color.array[1] = (byte)g;
    fog->color.array[2] = (byte)r;
    fog->color.array[3] = 0xFF;

    fog->fogStart = start;
    fog->fogEnd = end;

    if (density >= 1.0f) {
        fog->techniqueOffset = 1;
        fog->drawSky = 1;
        fog->clearScreen = 0;
        fog->density = 1.0f;
    } else {
        fog->techniqueOffset = 2;
        fog->drawSky = 1;
        fog->clearScreen = 0;
        fog->density = density;
    }

    fog->registered = 1;
}

void R_SwitchFog(int fogvar, int startTime, int transitionTime)
{
    rg->fogIndex = fogvar;

    if (rg->fogSettings[2].registered) {
        rg->fogSettings[3] = rg->fogSettings[2];
    } else {
        rg->fogSettings[3] = rg->fogSettings[fogvar];
        transitionTime = 0;
    }

    rg->fogSettings[4] = rg->fogSettings[rg->fogIndex];

    if (transitionTime == 0) {
        rg->fogSettings[4].startTime = 0;
        rg->fogSettings[4].finishTime = 0;
    } else {
        rg->fogSettings[4].startTime = startTime;
        rg->fogSettings[4].finishTime = startTime + transitionTime;
    }
}

void R_ArchiveFogState(MemoryFile *memFile)
{
    ((ArchiveProc)memFile->archiveProc)(memFile, sizeof(rg->fogSettings), rg->fogSettings);
    ((ArchiveProc)memFile->archiveProc)(memFile, sizeof(rg->fogIndex), &rg->fogIndex);
}

