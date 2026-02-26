/* Converted to C from ASM: r_bsp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_bsp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern void R_FreeStaticVertexBuffer(void *vb);
extern void *R_AllocStaticVertexBuffer(void *vb_out, int size);
extern void R_FinishStaticVertexBuffer(void *vb);
extern void Com_Memcpy(void *dest, void *src, int count);
extern void R_InterpretSunLightParseParamsIntoLights(void *sunParse, void *lights);
extern float ColorNormalize(float *in, float *out);
extern void *R_LoadWorldInternal(const char *name);
extern void RB_InitLightVisHistory(const char *name);
extern void R_FlushSun(void);
extern void R_ResetShadowCookies(void);
extern void R_InitStaticModelIndexCache(void);
extern void *Hunk_AllocInternal(int size);
extern void R_InitStaticModelDynamicData(int index);
extern void *Image_Register(const char *name, int flag1, int flag2);

extern byte *r_glob_ptr;         /* 0x195eebc */
extern byte *r_device_ptr;       /* 0x195eec0 */
extern byte *r_vtable_ptr;       /* 0x195eee0 */
extern byte *r_frontEndData_ptr; /* 0x195eec8 */
extern byte *r_dvar_ef30;        /* 0x195ef30 */
extern byte *r_dvar_ef34;        /* 0x195ef34 */
extern byte *r_dvar_ef38;        /* 0x195ef38 */
extern byte *r_dvar_ef3c;        /* 0x195ef3c */
extern byte *r_dvar_ef44;        /* 0x195ef44 */
extern byte *r_dvar_ef48;        /* 0x195ef48 */
extern byte *r_dvar_ef4c;        /* 0x195ef4c */

extern vec3_t vec3_colorintensity; /* 0x0 */

void R_ResetSunLightOverride(void);
void R_ReleaseWorld(void);
void R_GetWorldBounds(vec_t *min, vec_t *max);
void R_InterpretSunLightParseParams(SunLightParseParams *sunParse);
void R_SetSunLightOverride(const vec_t *sunColor);
IDirect3DVertexBuffer9 * R_CreateWorldVertexBuffer(GfxWorldVertex *vertices, int vertexCount);
void R_ReloadWorld(void);
void R_ShutdownWorld(void);
void R_UpdateLightsFromDvars(void);
void R_LoadWorld(const char *name, int *checksum);
void R_ResetSunLightParseParams(void);

/* line 273 */
void R_ResetSunLightOverride(void)
{
    byte *world = *(byte **)(r_glob_ptr + 0x109c);

    /* VectorCopy: world+0xe0 → world+0xc8 */
    *(int *)(world + 0xc8) = *(int *)(world + 0xe0);
    *(int *)(world + 0xcc) = *(int *)(world + 0xe4);
    *(int *)(world + 0xd0) = *(int *)(world + 0xe8);
}

/* line 366 */
void R_ReleaseWorld(void)
{
    byte *world = *(byte **)(r_glob_ptr + 0x109c);

    if (*(void **)(world + 0x30) != NULL) {
        R_FreeStaticVertexBuffer(*(void **)(world + 0x30));
        *(void **)(world + 0x30) = NULL;
    }
}

/* line 166 */
void R_GetWorldBounds(vec_t *min, vec_t *max)
{
    byte *world = *(byte **)(r_glob_ptr + 0x109c);

    /* VectorCopy: world+0x13c → min */
    *(int *)(min + 0) = *(int *)(world + 0x13c);
    *(int *)(min + 1) = *(int *)(world + 0x140);
    *(int *)(min + 2) = *(int *)(world + 0x144);

    /* VectorCopy: world+0x148 → max */
    *(int *)(max + 0) = *(int *)(world + 0x148);
    *(int *)(max + 1) = *(int *)(world + 0x14c);
    *(int *)(max + 2) = *(int *)(world + 0x150);
}

/* line 244 */
void R_InterpretSunLightParseParams(SunLightParseParams *sunParse)
{
    byte *world = *(byte **)(r_glob_ptr + 0x109c);

    R_InterpretSunLightParseParamsIntoLights(sunParse, world + 0xb4);

    /* VectorCopy: world+0xc8 → world+0xe0 */
    *(int *)(world + 0xe0) = *(int *)(world + 0xc8);
    *(int *)(world + 0xe4) = *(int *)(world + 0xcc);
    *(int *)(world + 0xe8) = *(int *)(world + 0xd0);
}

/* line 261 */
void R_SetSunLightOverride(const vec_t *sunColor)
{
    byte *device = *(byte **)r_device_ptr;

    if (*(int *)(device + 8) == 2)
        return;

    {
        byte *world = *(byte **)(r_glob_ptr + 0x109c);

        /* VectorCopy: sunColor → world+0xc8 */
        *(int *)(world + 0xc8) = *(int *)(sunColor + 0);
        *(int *)(world + 0xcc) = *(int *)(sunColor + 1);
        *(int *)(world + 0xd0) = *(int *)(sunColor + 2);
    }
}

/* line 24 */
IDirect3DVertexBuffer9 * R_CreateWorldVertexBuffer(GfxWorldVertex *vertices, int vertexCount)
{
    void *worldVb;
    byte *dataPtr;
    int sizeVerts;
    int vertIndex;
    byte *device;

    device = *(byte **)r_device_ptr;
    sizeVerts = 0x20;
    if (*(int *)(device + 8) != 2)
        sizeVerts = 0x44;
    sizeVerts *= vertexCount;

    dataPtr = (byte *)R_AllocStaticVertexBuffer(&worldVb, sizeVerts);

    device = *(byte **)r_device_ptr;
    if (*(int *)(device + 8) != 2) {
        /* Non-DX9: direct memcpy */
        Com_Memcpy(dataPtr, vertices, sizeVerts);
    } else {
        /* DX9: convert 0x44-byte vertices to 0x20-byte format */
        for (vertIndex = 0; vertIndex < vertexCount; vertIndex++) {
            byte *src = (byte *)vertices + vertIndex * 0x44;
            byte *dst = dataPtr + vertIndex * 0x20;

            /* Copy position xyz */
            *(int *)(dst + 0x00) = *(int *)(src + 0x00);
            *(int *)(dst + 0x04) = *(int *)(src + 0x04);
            *(int *)(dst + 0x08) = *(int *)(src + 0x08);
            /* Copy selected attributes */
            *(int *)(dst + 0x0c) = *(int *)(src + 0x18);
            *(int *)(dst + 0x10) = *(int *)(src + 0x1c);
            *(int *)(dst + 0x14) = *(int *)(src + 0x20);
            *(int *)(dst + 0x18) = *(int *)(src + 0x24);
            *(int *)(dst + 0x1c) = *(int *)(src + 0x28);
        }
    }

    R_FinishStaticVertexBuffer(worldVb);
    return (IDirect3DVertexBuffer9 *)worldVb;
}

/* line 381 */
void R_ReloadWorld(void)
{
    byte *world = *(byte **)(r_glob_ptr + 0x109c);

    *(void **)(world + 0x30) = R_CreateWorldVertexBuffer(
        *(GfxWorldVertex **)(world + 0x28),
        *(int *)(world + 0x2c));
}

/* line 355 */
void R_ShutdownWorld(void)
{
    byte *world = *(byte **)(r_glob_ptr + 0x109c);

    if (world == NULL)
        return;

    if (*(void **)(world + 0x30) != NULL) {
        R_FreeStaticVertexBuffer(*(void **)(world + 0x30));
        *(void **)(world + 0x30) = NULL;
    }

    *(void **)(r_glob_ptr + 0x109c) = NULL;
}

/* line 252 */
void R_UpdateLightsFromDvars(void)
{
    byte sunParse[128];
    byte *dvar;
    int channelIter;
    byte *world;

    /* Load scalar float values from three dvars */
    dvar = *(byte **)r_dvar_ef38;
    *(int *)(sunParse + 0x40) = *(int *)(dvar + 8);

    dvar = *(byte **)r_dvar_ef34;
    *(int *)(sunParse + 0x50) = *(int *)(dvar + 8);

    dvar = *(byte **)r_dvar_ef48;
    *(int *)(sunParse + 0x54) = *(int *)(dvar + 8);

    /* Convert first color dvar RGB bytes to float, normalize */
    dvar = *(byte **)r_dvar_ef3c;
    for (channelIter = 0; channelIter < 3; channelIter++) {
        *(float *)(sunParse + 0x44 + channelIter * 4) = (float)(unsigned char)dvar[8 + channelIter];
    }
    ColorNormalize((float *)(sunParse + 0x44), (float *)(sunParse + 0x44));

    /* Convert second color dvar */
    dvar = *(byte **)r_dvar_ef30;
    for (channelIter = 0; channelIter < 3; channelIter++) {
        *(float *)(sunParse + 0x58 + channelIter * 4) = (float)(unsigned char)dvar[8 + channelIter];
    }
    ColorNormalize((float *)(sunParse + 0x58), (float *)(sunParse + 0x58));

    /* Convert third color dvar */
    dvar = *(byte **)r_dvar_ef44;
    for (channelIter = 0; channelIter < 3; channelIter++) {
        *(float *)(sunParse + 0x64 + channelIter * 4) = (float)(unsigned char)dvar[8 + channelIter];
    }
    ColorNormalize((float *)(sunParse + 0x64), (float *)(sunParse + 0x64));

    /* Set override flag */
    sunParse[0x70] = 1;

    /* Copy vec3 from last dvar's pointed-to value */
    dvar = *(byte **)r_dvar_ef4c;
    {
        byte *src = *(byte **)(dvar + 8);
        *(int *)(sunParse + 0x74) = *(int *)(src + 0);
        *(int *)(sunParse + 0x78) = *(int *)(src + 4);
        *(int *)(sunParse + 0x7c) = *(int *)(src + 8);
    }

    /* Apply sun light params */
    world = *(byte **)(r_glob_ptr + 0x109c);
    R_InterpretSunLightParseParamsIntoLights(sunParse, world + 0xb4);

    /* VectorCopy: world+0xc8 → world+0xe0 */
    *(int *)(world + 0xe0) = *(int *)(world + 0xc8);
    *(int *)(world + 0xe4) = *(int *)(world + 0xcc);
    *(int *)(world + 0xe8) = *(int *)(world + 0xd0);
}

/* line 317 */
void R_LoadWorld(const char *name, int *checksum)
{
    byte *globals;
    byte *world;
    byte *worldData;
    byte *vtable;
    byte *dvar;
    byte *frontEnd;
    int i;

    RB_InitLightVisHistory(name);
    world = (byte *)R_LoadWorldInternal(name);
    *(void **)(r_glob_ptr + 0x109c) = world;

    if (checksum != NULL) {
        *checksum = *(int *)(world + 0x154);
    }

    globals = r_glob_ptr;
    world = *(byte **)(globals + 0x109c);
    worldData = world + 0x34;

    /* Set up dvars from world data through vtable */
    vtable = r_vtable_ptr;

    /* Dvar_SetFloat-style calls (vtable offset 0x9c) */
    ((void (*)(void *, int))(*(void **)(vtable + 0x9c)))
        (*(void **)r_dvar_ef38, *(int *)(worldData + 0x40));
    ((void (*)(void *, int))(*(void **)(vtable + 0x9c)))
        (*(void **)r_dvar_ef34, *(int *)(worldData + 0x50));
    ((void (*)(void *, int))(*(void **)(vtable + 0x9c)))
        (*(void **)r_dvar_ef48, *(int *)(worldData + 0x54));

    /* Dvar_SetColor-style calls (vtable offset 0xa4) - (dvar, r, g, b, 1.0f) */
    ((void (*)(void *, int, int, int, int))(*(void **)(vtable + 0xa4)))
        (*(void **)r_dvar_ef3c,
         *(int *)(worldData + 0x44), *(int *)(worldData + 0x48),
         *(int *)(worldData + 0x4c), 0x3f800000);
    ((void (*)(void *, int, int, int, int))(*(void **)(vtable + 0xa4)))
        (*(void **)r_dvar_ef30,
         *(int *)(worldData + 0x58), *(int *)(worldData + 0x5c),
         *(int *)(worldData + 0x60), 0x3f800000);
    ((void (*)(void *, int, int, int, int))(*(void **)(vtable + 0xa4)))
        (*(void **)r_dvar_ef44,
         *(int *)(worldData + 0x64), *(int *)(worldData + 0x68),
         *(int *)(worldData + 0x6c), 0x3f800000);

    /* Dvar_SetVec3-style call (vtable offset 0xac) */
    ((void (*)(void *, int, int, int))(*(void **)(vtable + 0xac)))
        (*(void **)r_dvar_ef4c,
         *(int *)(worldData + 0x74), *(int *)(worldData + 0x78),
         *(int *)(worldData + 0x7c));

    /* Dvar_SetModified-style calls (vtable offset 0x80) - (dvar, dvar->current) */
    dvar = *(byte **)r_dvar_ef38;
    ((void (*)(void *, int))(*(void **)(vtable + 0x80)))(dvar, *(int *)(dvar + 8));
    dvar = *(byte **)r_dvar_ef34;
    ((void (*)(void *, int))(*(void **)(vtable + 0x80)))(dvar, *(int *)(dvar + 8));
    dvar = *(byte **)r_dvar_ef48;
    ((void (*)(void *, int))(*(void **)(vtable + 0x80)))(dvar, *(int *)(dvar + 8));
    dvar = *(byte **)r_dvar_ef3c;
    ((void (*)(void *, int))(*(void **)(vtable + 0x80)))(dvar, *(int *)(dvar + 8));
    dvar = *(byte **)r_dvar_ef30;
    ((void (*)(void *, int))(*(void **)(vtable + 0x80)))(dvar, *(int *)(dvar + 8));
    dvar = *(byte **)r_dvar_ef44;
    ((void (*)(void *, int))(*(void **)(vtable + 0x80)))(dvar, *(int *)(dvar + 8));
    dvar = *(byte **)r_dvar_ef4c;
    ((void (*)(void *, int))(*(void **)(vtable + 0x80)))(dvar, *(int *)(dvar + 8));

    R_UpdateLightsFromDvars();
    R_FlushSun();
    R_ResetShadowCookies();
    R_InitStaticModelIndexCache();

    /* Allocate front-end data arrays */
    frontEnd = r_frontEndData_ptr;
    world = *(byte **)(r_glob_ptr + 0x109c);

    *(void **)(frontEnd + 0x3194) = Hunk_AllocInternal(*(int *)(world + 0xf4) * 8);
    world = *(byte **)(r_glob_ptr + 0x109c);
    *(void **)(frontEnd + 0x3198) = Hunk_AllocInternal(*(int *)(world + 0x10) * 4);
    world = *(byte **)(r_glob_ptr + 0x109c);
    *(void **)(frontEnd + 0x319c) = Hunk_AllocInternal(*(int *)(world + 0xec) * 4);

    /* Init static model dynamic data */
    world = *(byte **)(r_glob_ptr + 0x109c);
    if (*(int *)(world + 0xf4) > 0) {
        for (i = 0; i < *(int *)(world + 0xf4); i++) {
            R_InitStaticModelDynamicData(i);
        }
    }

    /* Register sun half-angle image for DX9 */
    {
        byte *device = *(byte **)r_device_ptr;
        if (*(int *)(device + 8) == 2) {
            *(void **)(r_glob_ptr + 0x10a0) =
                Image_Register("$sunhalfangle", 1, 0);
        }
    }
}

/* line 210 */
void R_ResetSunLightParseParams(void)
{
    R_UpdateLightsFromDvars();
}
