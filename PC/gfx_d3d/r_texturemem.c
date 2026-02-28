/* Converted to C from ASM: r_texturemem.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_texturemem.cpp */

#include "common_types.h"
#include "imports.h"

extern void MacDisplay_GetVideoMemoryInfo(int *vidMemMB, int *totalVidMem);

extern char *d3d_context; /* imp_dx — D3D device wrapper */
extern refimport_t *ri; /* imp_ri */

unsigned int R_AvailableTextureMemory(void)
{
    int vidMemInMegs;
    int vidMem2;
    unsigned int texMemInMegs;

    MacDisplay_GetVideoMemoryInfo(&vidMemInMegs, &vidMem2);

    /* IDirect3DDevice9::GetAvailableTextureMem() via COM vtable */
    char *device = *(char **)(d3d_context + 8);
    void **vtable = *(void ***)device;
    unsigned int texMem = ((unsigned int (*)(void *))vtable[4])(device);
    texMemInMegs = texMem >> 20;

    if (vidMemInMegs == 0) {
        ri->Printf(0, "DirectX reports %i MB of available texture memory, but wouldn't tell available video memory.\n", texMemInMegs);
    } else {
        ri->Printf(0, "DirectX reports %i MB of video memory and %i MB of available texture memory.\n", vidMemInMegs, texMemInMegs);
        if ((unsigned int)vidMemInMegs < texMemInMegs) {
            texMemInMegs = vidMemInMegs - 16;
            ri->Printf(0, "Using video memory size to cap used texture memory at %i MB.\n", texMemInMegs);
        }
    }
    return texMemInMegs;
}
