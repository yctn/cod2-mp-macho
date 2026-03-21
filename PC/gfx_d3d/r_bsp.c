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

extern byte *r_glob_ptr;         /* imp_rgp */
/* r_device_ptr was imp_r_rendererInUse */
extern byte *r_vtable_ptr;       /* imp_ri */
extern byte r_frontEndData_ptr[]; /* imp_rg */
extern byte *r_dvar_ef30;        /* imp_r_lightTweakSunColor */
extern byte *r_dvar_ef34;        /* imp_r_lightTweakDiffuseFraction */
extern byte *r_dvar_ef38;        /* imp_r_lightTweakAmbient */
extern byte *r_dvar_ef3c;        /* imp_r_lightTweakAmbientColor */
extern byte *r_dvar_ef44;        /* imp_r_lightTweakSunDiffuseColor */
extern byte *r_dvar_ef48;        /* imp_r_lightTweakSunLight */
extern byte *r_dvar_ef4c;        /* imp_r_lightTweakSunDirection */

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

/* Helper: get the GfxWorld pointer from rgp */
static inline GfxWorld *R_GetWorld(void)
{
    return *(GfxWorld **)(r_glob_ptr + 0x109c);
}

/* line 273 */
void R_ResetSunLightOverride(void)
{
    GfxWorld *world = R_GetWorld();

    /* VectorCopy: sunLight.color → sunColorFromBsp */
    world->sunColorFromBsp[0] = world->sunLight.color[0];
    world->sunColorFromBsp[1] = world->sunLight.color[1];
    world->sunColorFromBsp[2] = world->sunLight.color[2];
}

/* line 366 */
void R_ReleaseWorld(void)
{
    GfxWorld *world = R_GetWorld();

    if (world->vd.worldVb != NULL) {
        R_FreeStaticVertexBuffer(world->vd.worldVb);
        world->vd.worldVb = NULL;
    }
}

/* line 166 */
void R_GetWorldBounds(vec_t *min, vec_t *max)
{
    GfxWorld *world = R_GetWorld();

    /* VectorCopy: world->mins → min */
    *(int *)(min + 0) = *(int *)&world->mins[0];
    *(int *)(min + 1) = *(int *)&world->mins[1];
    *(int *)(min + 2) = *(int *)&world->mins[2];

    /* VectorCopy: world->maxs → max */
    *(int *)(max + 0) = *(int *)&world->maxs[0];
    *(int *)(max + 1) = *(int *)&world->maxs[1];
    *(int *)(max + 2) = *(int *)&world->maxs[2];
}

/* line 244 */
void R_InterpretSunLightParseParams(SunLightParseParams *sunParse)
{
    GfxWorld *world = R_GetWorld();

    R_InterpretSunLightParseParamsIntoLights(sunParse, &world->sunLight);

    /* VectorCopy: sunLight.color → sunColorFromBsp */
    world->sunColorFromBsp[0] = world->sunLight.color[0];
    world->sunColorFromBsp[1] = world->sunLight.color[1];
    world->sunColorFromBsp[2] = world->sunLight.color[2];
}

/* line 261 */
void R_SetSunLightOverride(const vec_t *sunColor)
{
    byte *device = *(byte **)imp_r_rendererInUse;

    if (*(int *)(device + 8) == 2)
        return;

    {
        GfxWorld *world = R_GetWorld();

        /* VectorCopy: sunColor → sunLight.color */
        world->sunLight.color[0] = sunColor[0];
        world->sunLight.color[1] = sunColor[1];
        world->sunLight.color[2] = sunColor[2];
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

    device = *(byte **)imp_r_rendererInUse;
    sizeVerts = 0x20;
    if (*(int *)(device + 8) != 2)
        sizeVerts = 0x44;
    sizeVerts *= vertexCount;

    dataPtr = (byte *)R_AllocStaticVertexBuffer(&worldVb, sizeVerts);

    device = *(byte **)imp_r_rendererInUse;
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
    GfxWorld *world = R_GetWorld();

    world->vd.worldVb = R_CreateWorldVertexBuffer(
        world->vd.vertices,
        world->vertexCount);
}

/* line 355 */
void R_ShutdownWorld(void)
{
    GfxWorld *world = R_GetWorld();

    if (world == NULL)
        return;

    if (world->vd.worldVb != NULL) {
        R_FreeStaticVertexBuffer(world->vd.worldVb);
        world->vd.worldVb = NULL;
    }

    *(void **)(r_glob_ptr + 0x109c) = NULL;
}

/* line 252 */
void R_UpdateLightsFromDvars(void)
{
    SunLightParseParams sunParse;
    byte *dvar;
    int channelIter;
    GfxWorld *world;

    /* Load scalar float values from three dvars */
    dvar = *(byte **)r_dvar_ef38;
    sunParse.ambientScale = *(float *)(dvar + 8);

    dvar = *(byte **)r_dvar_ef34;
    sunParse.diffuseFraction = *(float *)(dvar + 8);

    dvar = *(byte **)r_dvar_ef48;
    sunParse.sunLight = *(float *)(dvar + 8);

    /* Convert first color dvar RGB bytes to float, normalize */
    dvar = *(byte **)r_dvar_ef3c;
    for (channelIter = 0; channelIter < 3; channelIter++) {
        sunParse.ambientColor[channelIter] = (float)(unsigned char)dvar[8 + channelIter];
    }
    ColorNormalize(sunParse.ambientColor, sunParse.ambientColor);

    /* Convert second color dvar */
    dvar = *(byte **)r_dvar_ef30;
    for (channelIter = 0; channelIter < 3; channelIter++) {
        sunParse.sunColor[channelIter] = (float)(unsigned char)dvar[8 + channelIter];
    }
    ColorNormalize(sunParse.sunColor, sunParse.sunColor);

    /* Convert third color dvar */
    dvar = *(byte **)r_dvar_ef44;
    for (channelIter = 0; channelIter < 3; channelIter++) {
        sunParse.diffuseColor[channelIter] = (float)(unsigned char)dvar[8 + channelIter];
    }
    ColorNormalize(sunParse.diffuseColor, sunParse.diffuseColor);

    /* Set override flag */
    sunParse.diffuseColorHasBeenSet = 1;

    /* Copy vec3 from last dvar's pointed-to value */
    dvar = *(byte **)r_dvar_ef4c;
    {
        byte *src = *(byte **)(dvar + 8);
        sunParse.angles[0] = *(float *)(src + 0);
        sunParse.angles[1] = *(float *)(src + 4);
        sunParse.angles[2] = *(float *)(src + 8);
    }

    /* Apply sun light params */
    world = R_GetWorld();
    R_InterpretSunLightParseParamsIntoLights(&sunParse, &world->sunLight);

    /* VectorCopy: sunLight.color → sunColorFromBsp */
    world->sunColorFromBsp[0] = world->sunLight.color[0];
    world->sunColorFromBsp[1] = world->sunLight.color[1];
    world->sunColorFromBsp[2] = world->sunLight.color[2];
}

/* line 317 */
void R_LoadWorld(const char *name, int *checksum)
{
    GfxWorld *world;
    SunLightParseParams *worldSunParse;
    byte *vtable;
    byte *dvar;
    byte *frontEnd;
    int i;

    RB_InitLightVisHistory(name);
    world = (GfxWorld *)R_LoadWorldInternal(name);
    *(void **)(r_glob_ptr + 0x109c) = world;

    if (checksum != NULL) {
        *checksum = world->checksum;
    }

    world = R_GetWorld();
    worldSunParse = &world->sunParse;

    /* Set up dvars from world data through vtable */
    vtable = r_vtable_ptr;

    /* Dvar_SetFloat-style calls (vtable offset 0x9c) */
    ((void (*)(void *, int))(*(void **)(vtable + 0x9c)))
        (*(void **)r_dvar_ef38, *(int *)&worldSunParse->ambientScale);
    ((void (*)(void *, int))(*(void **)(vtable + 0x9c)))
        (*(void **)r_dvar_ef34, *(int *)&worldSunParse->diffuseFraction);
    ((void (*)(void *, int))(*(void **)(vtable + 0x9c)))
        (*(void **)r_dvar_ef48, *(int *)&worldSunParse->sunLight);

    /* Dvar_SetColor-style calls (vtable offset 0xa4) - (dvar, r, g, b, 1.0f) */
    ((void (*)(void *, int, int, int, int))(*(void **)(vtable + 0xa4)))
        (*(void **)r_dvar_ef3c,
         *(int *)&worldSunParse->ambientColor[0], *(int *)&worldSunParse->ambientColor[1],
         *(int *)&worldSunParse->ambientColor[2], 0x3f800000);
    ((void (*)(void *, int, int, int, int))(*(void **)(vtable + 0xa4)))
        (*(void **)r_dvar_ef30,
         *(int *)&worldSunParse->sunColor[0], *(int *)&worldSunParse->sunColor[1],
         *(int *)&worldSunParse->sunColor[2], 0x3f800000);
    ((void (*)(void *, int, int, int, int))(*(void **)(vtable + 0xa4)))
        (*(void **)r_dvar_ef44,
         *(int *)&worldSunParse->diffuseColor[0], *(int *)&worldSunParse->diffuseColor[1],
         *(int *)&worldSunParse->diffuseColor[2], 0x3f800000);

    /* Dvar_SetVec3-style call (vtable offset 0xac) */
    ((void (*)(void *, int, int, int))(*(void **)(vtable + 0xac)))
        (*(void **)r_dvar_ef4c,
         *(int *)&worldSunParse->angles[0], *(int *)&worldSunParse->angles[1],
         *(int *)&worldSunParse->angles[2]);

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
    world = R_GetWorld();

    *(void **)(frontEnd + 0x3194) = Hunk_AllocInternal(world->smodelCount * 8);
    world = R_GetWorld();
    *(void **)(frontEnd + 0x3198) = Hunk_AllocInternal(world->surfaceCount * 4);
    world = R_GetWorld();
    *(void **)(frontEnd + 0x319c) = Hunk_AllocInternal(world->cullGroupCount * 4);

    /* Init static model dynamic data */
    world = R_GetWorld();
    if (world->smodelCount > 0) {
        for (i = 0; i < world->smodelCount; i++) {
            R_InitStaticModelDynamicData(i);
        }
    }

    /* Register sun half-angle image for DX9 */
    {
        byte *device = *(byte **)imp_r_rendererInUse;
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
