/* Converted to C from ASM: r_splitscreen.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_splitscreen.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdio.h>

extern int R_BeginDelayedDrawing(void);
extern void R_EndDelayedDrawing(int handle);
extern void R_IssueDelayedDrawing(int handle);
static int splitscreen_diag = 0;

extern GfxDrawGroupCommands delayedGroup[5];

void R_InitDrawGroups(void)
{
    int group;
    for (group = 0; group < 5; group++) {
        delayedGroup[group].isIssuingGlue = 0;
        delayedGroup[group].begin = -1;
        int i;
        for (i = 0; i < 10; i++) {
            delayedGroup[group].perView[i] = -1;
        }
        delayedGroup[group].end = -1;
    }
}

GfxDrawGroupGlueBehavior R_BeginDrawGroupSection(GfxDrawGroupType group)
{
    static int bdgs_diag = 0;
    int trace = (bdgs_diag >= 200 && bdgs_diag < 260);
    if (delayedGroup[group].begin != -1) {
        if (trace) fprintf(stderr, "[BeginDGS#%d] group=%d ALREADY begin=%d\n", bdgs_diag, group, delayedGroup[group].begin);
        bdgs_diag++;
        return 1;
    }

    delayedGroup[group].isIssuingGlue = 1;
    delayedGroup[group].begin = R_BeginDelayedDrawing();
    if (trace) fprintf(stderr, "[BeginDGS#%d] group=%d NEW begin=%d\n", bdgs_diag, group, delayedGroup[group].begin);
    bdgs_diag++;
    return 0;
}

void R_BeginDrawGroupLoop(GfxDrawGroupType group, int viewIndex)
{
    if (delayedGroup[group].isIssuingGlue) {
        R_EndDelayedDrawing(delayedGroup[group].begin);
        delayedGroup[group].isIssuingGlue = 0;
    }
    delayedGroup[group].perView[viewIndex] = R_BeginDelayedDrawing();
}

GfxDrawGroupGlueBehavior R_EndDrawGroupLoop(GfxDrawGroupType group, int viewIndex)
{
    if (delayedGroup[group].perView[viewIndex] != -1)
        R_EndDelayedDrawing(delayedGroup[group].perView[viewIndex]);

    if (delayedGroup[group].end != -1)
        return 1;

    delayedGroup[group].isIssuingGlue = 1;
    delayedGroup[group].end = R_BeginDelayedDrawing();
    return 0;
}

void R_EndDrawGroupSection(GfxDrawGroupType group)
{
    if (delayedGroup[group].isIssuingGlue) {
        R_EndDelayedDrawing(delayedGroup[group].end);
        delayedGroup[group].isIssuingGlue = 0;
    }
}

void R_IssueDrawGroups(void)
{
    int group;
    int trace = (splitscreen_diag >= 430 && splitscreen_diag < 445);
    if (trace) {
        fprintf(stderr, "[IssueDrawGroups#%d] ", splitscreen_diag);
    }
    int totalIssued = 0;
    for (group = 0; group < 5; group++) {
        if (delayedGroup[group].begin != -1) {
            if (trace) fprintf(stderr, "g%d.begin=%d ", group, delayedGroup[group].begin);
            R_IssueDelayedDrawing(delayedGroup[group].begin);
            delayedGroup[group].begin = -1;
            totalIssued++;
        }

        int i;
        for (i = 0; i < 10; i++) {
            if (delayedGroup[group].perView[i] != -1) {
                if (trace) fprintf(stderr, "g%d.v%d=%d ", group, i, delayedGroup[group].perView[i]);
                R_IssueDelayedDrawing(delayedGroup[group].perView[i]);
                delayedGroup[group].perView[i] = -1;
                totalIssued++;
            }
        }

        if (delayedGroup[group].end != -1) {
            if (trace) fprintf(stderr, "g%d.end=%d ", group, delayedGroup[group].end);
            R_IssueDelayedDrawing(delayedGroup[group].end);
            delayedGroup[group].end = -1;
            totalIssued++;
        }
    }
    if (trace) fprintf(stderr, "total=%d\n", totalIssued);
    splitscreen_diag++;
}

