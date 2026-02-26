/* ASM dump from: rb_light.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_light.cpp */

#include "common_types.h"
#include "imports.h"

extern float floorf(float x);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static vec3_t gridBasisDirs[8]; /* 0x2f2a00 */
static int s_vc_log; /* 0xc96c80 */

/* Adjacent global: count of entries in s_vc_log */
extern int s_vc_logCount; /* 0xc96c84 */

/* Global pointers used in this file */
extern r_global_permanent_t *rgp;       /* 0x195eebc */
extern r_backEndGlobals_t *backEnd;     /* 0x195f0c8 */
extern void **g_viewParms;              /* 0x195f188 */
extern const dvar_t **r_lightGridSunDir;      /* 0x195f184 — pointer to sun direction floats */
extern const dvar_t **r_lightGridContrast;    /* 0x195f18c */
extern const dvar_t **r_lightGridEnableTweaks;/* 0x195f190 */
extern const dvar_t **r_lightGridSpread;      /* 0x195f194 */
extern const dvar_t **r_lightGridUseTweakedValues; /* 0x195f180 */

/* Color constants used in various places */
extern const float *colorRed;       /* 0x195ed98 */
extern const float *colorGreen;     /* 0x195ed60 */
extern const float *colorYellow;    /* 0x195ed78 */
extern const float *colorWhite;     /* 0x195ed2c */
extern const float *vec3_origin;    /* 0x195ed4c */

/* External function declarations */
extern void Com_StripExtension(const char *src, char *dest);
extern void FS_WriteFile(const char *path, const void *buffer, int size);
extern void Z_FreeInternal(void *ptr);
extern void *Z_MallocInternal(int size);
extern int FS_ReadFile(const char *path, void **buffer);
extern void FS_FreeFile(void *buffer);
extern void Com_Error(int level, const char *fmt, ...);
extern float Vec3Normalize(vec3_t v);
extern int R_CullPointAndRadius(const vec_t *pt, float radius, const DpvsPlane *clipPlanes, int clipPlaneCount);
extern void R_AddDebugString(void *debugGlobals, const vec_t *origin, const float *color, float scale, const char *text);
extern void R_AddDebugBox(void *debugGlobals, const vec_t *mins, const vec_t *maxs, const float *color);
extern int CM_BoxSightTrace(int oldHitNum, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, unsigned int brushmask, int zero);

void RB_SaveLightVisHistory(void);
int RB_DeriveEntityLights(vec4_t *colorForDir, float sunVisibility, const Material *material, D3DLIGHT9 *lights, int maxLights);
void RB_ShowLightVisCachePoints(const vec_t *viewOrigin, const DpvsPlane *clipPlanes, int clipPlaneCount);
float RB_GetLightingAtPoint(const GfxLightGrid *lightGrid, const vec_t *samplePos, vec4_t *colorForDir);
void RB_SetupEntityLighting(const GfxEntity *ent, GfxEntityLighting *lighting);
void RB_InitLightVisHistory(const char *bspName);

/*
 * Helper: build filename with .grid extension.
 * The original code used inline strlen (repne scasb) and checked length < 63.
 */
static void BuildGridFilename(const char *baseName, char *filename)
{
    int len;

    Com_StripExtension(baseName, filename);
    len = strlen(filename) + 5; /* +5 for ".grid" with null */
    if (len > 63) {
        Com_Error(1, "light grid log filename '%s.grid' is too long\n", filename);
    }
    strcat(filename, ".grid");
}

/* Sorted log entry: 3 unsigned shorts (x, y, z) = 6 bytes each */
typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short z;
} vc_log_entry_t;

/*
 * Binary search for a point in the vc_log, returning 1 if found.
 * Used in both RB_ShowLightVisCachePoints and RB_GetLightingAtPoint.
 */
static int VC_SearchLog(int gridX, int gridY, int gridZ, int *outMid)
{
    int bot = 0;
    int top = s_vc_logCount - 1;
    vc_log_entry_t *entries = (vc_log_entry_t *)s_vc_log;

    while (bot <= top) {
        int mid = (bot + top) / 2;
        int cmp;
        vc_log_entry_t *e = &entries[mid];

        cmp = gridX - (int)e->x;
        if (cmp == 0) {
            cmp = gridY - (int)e->y;
            if (cmp == 0) {
                cmp = gridZ - (int)e->z;
                if (cmp == 0) {
                    if (outMid) *outMid = mid;
                    return 1;
                }
            }
        }
        if (cmp < 0) {
            top = mid - 1;
        } else {
            bot = mid + 1;
        }
    }
    if (outMid) *outMid = bot;
    return 0;
}

/*
 * Insert a new entry into the sorted vc_log at position 'insertAt'.
 */
static void VC_InsertLog(int insertAt, int gridX, int gridY, int gridZ)
{
    vc_log_entry_t *entries = (vc_log_entry_t *)s_vc_log;
    int remaining = s_vc_logCount - insertAt;

    if (s_vc_logCount > 0x3fffff) return; /* overflow check */

    memmove(&entries[insertAt + 1], &entries[insertAt], remaining * sizeof(vc_log_entry_t));
    entries[insertAt].x = (unsigned short)gridX;
    entries[insertAt].y = (unsigned short)gridY;
    entries[insertAt].z = (unsigned short)gridZ;
    s_vc_logCount++;
}

/* line 817 */
void RB_SaveLightVisHistory(void)
{
    char filename[64];
    GfxWorld *world;

    if (!s_vc_log)
        return;

    world = rgp->world;
    if (!world)
        return;

    BuildGridFilename(world->name, filename);
    FS_WriteFile(filename, (void *)s_vc_log, s_vc_logCount * 6);
    Z_FreeInternal((void *)s_vc_log);
    s_vc_log = 0;
    s_vc_logCount = 0;
}

/*
 * Helper for DeriveEntityLights: compute dot product of dir with errorInDir[i]
 * and accumulate weighted light contribution.
 * VecScaleAdd: out += scale * in
 */
static void VecScaleAdd(vec3_t out, float scale, const vec3_t dir)
{
    out[0] += scale * dir[0];
    out[1] += scale * dir[1];
    out[2] += scale * dir[2];
}

static float VecDot(const vec3_t a, const vec3_t b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

/*
 * Setup a D3DLIGHT9 as a directional light with given color and direction.
 * The D3DLIGHT9 is 0x68 (104) bytes.
 * Offset 0x00: Type (D3DLIGHTTYPE 3 = directional)
 * Offset 0x04: Diffuse (r,g,b,a) - color
 * Offset 0x24: Ambient (r,g,b,a)
 * Offset 0x40: Direction (x,y,z)
 * Offset 0x48: Direction.z also (range/falloff start area)
 */
static void SetupDirectionalLight(D3DLIGHT9 *light, const float *ambient, const float *diffuse, const float *direction)
{
    light->Type = 3; /* D3DLIGHT_DIRECTIONAL */
    light->Ambient.r = ambient[0];
    light->Ambient.g = ambient[1];
    light->Ambient.b = ambient[2];
    if (diffuse) {
        light->Diffuse.r = diffuse[0];
        light->Diffuse.g = diffuse[1];
        light->Diffuse.b = diffuse[2];
    }
    if (direction) {
        light->Direction.x = direction[0];
        light->Direction.y = direction[1];
        light->Direction.z = direction[2];
    }
    light->Range = 1.0f;
}

/* line 745 */
int RB_DeriveEntityLights(vec4_t *colorForDir, float sunVisibility, const Material *material, D3DLIGHT9 *lights, int maxLights)
{
    GfxWorld *world;
    MaterialTechniqueSet *techSet;
    MaterialTechnique *technique;
    int lightCount;
    int i, j;
    vec3_t errorInDir[8];
    vec3_t errorDirAvg;
    vec3_t lightColor;
    vec3_t lightDir;
    float errorTotal;
    float dotProduct;
    float scale;
    float sumX, sumY, sumZ;
    float ambientR, ambientG, ambientH;
    D3DLIGHT9 *light;
    float *sunDirPtr;
    float sunColorR, sunColorG, sunColorB;
    (void)0; /* unused vars cleaned */

    /* Check if material has a lit technique (index 15) */
    techSet = material->techniqueSet;
    technique = techSet->techniques[15];
    if (!technique)
        goto fallback;

    /* Check byte at offset 0xe within technique - passCount or flag */
    if (*((unsigned char *)technique + 0xe) == 0)
        goto fallback;

    /* Simple lit path: only 2 lights */
    memset(lights, 0, maxLights * sizeof(D3DLIGHT9));

    /* Compute average color from the 8 grid directions */
    /* colorForDir is vec4_t[6] with layout:
     * [0..7]: channel 0 values (8 floats starting at colorForDir[0][0])
     * [8..15]: channel 1 values (8 floats at +0x20)
     * [16..23]: channel 2 values (8 floats at +0x40)
     */
    {
        float *chan0 = (float *)colorForDir;
        float *chan1 = chan0 + 8;
        float *chan2 = chan0 + 16;
        float avgR = 0.0f, avgG = 0.0f, avgB = 0.0f;

        for (i = 0; i < 8; i++) {
            avgR += chan0[i];
            avgG += chan1[i];
            avgB += chan2[i];
        }

        /* First light: ambient from grid average */
        lights[0].Type = 3;
        lights[0].Ambient.r = avgR * 0.125f * 0.5f;
        lights[0].Ambient.g = avgG * 0.125f * 0.5f;
        lights[0].Ambient.b = avgB * 0.125f * 0.5f;
        lights[0].Range = 1.0f;

        /* Second light: sun contribution */
        world = rgp->world;
        sunColorR = sunVisibility * world->sunLight.color[0] + world->sunLight.u.dir.ambientColor[0];
        sunColorG = sunVisibility * world->sunLight.color[1] + world->sunLight.u.dir.ambientColor[1];
        sunColorB = sunVisibility * world->sunLight.color[2] + world->sunLight.u.dir.ambientColor[2];

        light = &lights[1];
        light->Type = 3;
        light->Ambient.r = sunColorR * 0.5f;
        light->Ambient.g = sunColorG * 0.5f;
        light->Ambient.b = sunColorB * 0.5f;
        light->Range = 1.0f;
        lightCount = 2;
    }
    return lightCount;

fallback:
    /* Full light derivation path */
    memset(lights, 0, maxLights * sizeof(D3DLIGHT9));

    /* Build errorInDir from colorForDir - interleave channels */
    {
        float *chan0 = (float *)colorForDir;
        float *chan1 = chan0 + 8;
        float *chan2 = chan0 + 16;

        for (i = 0; i < 8; i++) {
            errorInDir[i][0] = chan0[i];
            errorInDir[i][1] = chan1[i];
            errorInDir[i][2] = chan2[i];
        }
    }

    light = lights;
    lightCount = 0;

    for (;;) {
        lightCount++;
        if (lightCount > maxLights)
            break;

        /* Compute weighted average direction from error */
        errorDirAvg[0] = 0.0f;
        errorDirAvg[1] = 0.0f;
        errorDirAvg[2] = 0.0f;

        {
            float *sunDir = *(float **)r_lightGridSunDir;
            float sdx = sunDir[0];
            float sdy = sunDir[1];
            float sdz = sunDir[2];
            unsigned int abs_mask = 0x7FFFFFFF;

            errorTotal = 0.0f;

            for (i = 0; i < 8; i++) {
                float dot = sdx * errorInDir[i][0] + sdy * errorInDir[i][1] + sdz * errorInDir[i][2];
                float absDot;
                /* fabs via bit mask */
                {
                    union { float f; unsigned int u; } uv;
                    uv.f = dot;
                    uv.u &= abs_mask;
                    absDot = uv.f;
                }
                errorDirAvg[0] += absDot * gridBasisDirs[i][0];
                errorDirAvg[1] += absDot * gridBasisDirs[i][1];
                errorDirAvg[2] += absDot * gridBasisDirs[i][2];
                errorTotal += dot * dot;
            }
        }

        if (errorTotal < 0.0008f) {
            /* Too little error - done */
            goto deriveLightDone;
        }

        /* Normalize errorDirAvg */
        Vec3Normalize(errorDirAvg);

        /* Compute forward-facing light color */
        lightColor[0] = 0.0f;
        lightColor[1] = 0.0f;
        lightColor[2] = 0.0f;
        {
            float edx = errorDirAvg[0];
            float edy = errorDirAvg[1];
            float edz = errorDirAvg[2];
            float totalWeight = 0.0f;

            for (i = 0; i < 8; i++) {
                float dot = edx * gridBasisDirs[i][0] + edy * gridBasisDirs[i][1] + edz * gridBasisDirs[i][2];
                if (dot > 0.01f) {
                    lightColor[0] += dot * errorInDir[i][0];
                    lightColor[1] += dot * errorInDir[i][1];
                    lightColor[2] += dot * errorInDir[i][2];
                    totalWeight += dot;
                }
            }

            /* Normalize light color by total weight */
            if (totalWeight != 0.0f) {
                scale = 1.0f / totalWeight;
                lightColor[0] *= scale;
                lightColor[1] *= scale;
                lightColor[2] *= scale;
            }
        }

        /* Subtract light contribution from errorInDir and compute new average */
        sumX = 0.0f;
        sumY = 0.0f;
        sumZ = 0.0f;
        {
            for (i = 0; i < 8; i++) {
                float dot = gridBasisDirs[i][0] * errorDirAvg[0]
                          + gridBasisDirs[i][1] * errorDirAvg[1]
                          + gridBasisDirs[i][2] * errorDirAvg[2];

                if (dot > 0.0f) {
                    float negDot = -dot;
                    errorInDir[i][0] += negDot * lightColor[0];
                    errorInDir[i][1] += negDot * lightColor[1];
                    errorInDir[i][2] += negDot * lightColor[2];
                }

                sumX += errorInDir[i][0];
                sumY += errorInDir[i][1];
                sumZ += errorInDir[i][2];
            }
        }

        /* Compute ambient from average */
        ambientR = sumX * 0.125f;
        ambientG = sumY * 0.125f;
        ambientH = sumZ * 0.125f;

        /* Subtract ambient from each errorInDir and compute remaining error */
        {
            float *sunDir = *(float **)r_lightGridSunDir;
            float sdx = sunDir[0];
            float sdy = sunDir[1];
            float sdz = sunDir[2];
            float newError = 0.0f;

            for (i = 0; i < 8; i++) {
                float dot;
                errorInDir[i][0] -= ambientR;
                errorInDir[i][1] -= ambientG;
                errorInDir[i][2] -= ambientH;
                dot = sdx * errorInDir[i][0] + sdy * errorInDir[i][1] + sdz * errorInDir[i][2];
                newError += dot * dot;
            }

            /* Check if error reduction is sufficient */
            if (errorTotal - newError < 0.02f) {
                goto deriveLightDone;
            }
        }

        /* Set up this light */
        light->Type = 3;
        light->Ambient.r = ambientR * 0.5f;
        light->Ambient.g = ambientG * 0.5f;
        light->Ambient.b = ambientH * 0.5f;
        light->Diffuse.r = lightColor[0] * 0.5f;
        light->Diffuse.g = lightColor[1] * 0.5f;
        light->Diffuse.b = lightColor[2] * 0.5f;

        /* Direction = -errorDirAvg (if length sufficient) */
        {
            float lenSq = errorDirAvg[0] * errorDirAvg[0] + errorDirAvg[1] * errorDirAvg[1] + errorDirAvg[2] * errorDirAvg[2];
            if (lenSq < 0.000001f) {
                light->Direction.x = 0.0f;
                light->Direction.y = 0.0f;
                light->Direction.z = 1.0f;
            } else {
                light->Direction.x = -errorDirAvg[0];
                light->Direction.y = -errorDirAvg[1];
                light->Direction.z = -errorDirAvg[2];
            }
        }

        light++;
        continue;

    deriveLightDone:
        /* No valid light derived */
        light++;
        break;
    }

    /* Set up the sun light as the last derived light */
    {
        D3DLIGHT9 *sunLight;
        int prevCount = lightCount - 1;
        sunLight = &lights[prevCount];

        world = rgp->world;

        sunLight->Type = 3;
        sunLight->Ambient.r = world->sunLight.u.dir.ambientColor[0] * 0.5f;
        sunLight->Ambient.g = world->sunLight.u.dir.ambientColor[1] * 0.5f;
        sunLight->Ambient.b = world->sunLight.u.dir.ambientColor[2] * 0.5f;
        sunLight->Diffuse.r = sunVisibility * world->sunLight.color[0] * 0.5f;
        sunLight->Diffuse.g = sunVisibility * world->sunLight.color[1] * 0.5f;
        sunLight->Diffuse.b = sunVisibility * world->sunLight.color[2] * 0.5f;
        sunLight->Direction.x = -world->sunLight.position[0];
        sunLight->Direction.y = -world->sunLight.position[1];
        sunLight->Direction.z = -world->sunLight.position[2];
    }

    return lightCount;
}

/* line 201 */
void RB_ShowLightVisCachePoints(const vec_t *viewOrigin, const DpvsPlane *clipPlanes, int clipPlaneCount)
{
    int spread;
    int x, y, z;
    int dx, dy, dz;
    vec3_t origin;
    void *debugGlobals;
    const float *debugColor;

    if (!s_vc_log)
        return;

    spread = **(int **)r_lightGridSpread;
    if (spread <= 0)
        return;

    /* Convert viewOrigin to grid coordinates */
    x = ((int)floorf(viewOrigin[0] + 131072.0f + 0.5f)) >> 5;
    y = ((int)floorf(viewOrigin[1] + 131072.0f + 0.5f)) >> 5;
    z = ((int)floorf(131072.0f + viewOrigin[2])) >> 6;

    /* Set initial origin display position */
    origin[0] = (float)(x * 32 - 0x20000);
    origin[1] = (float)(y * 32 - 0x20000);
    origin[2] = (float)(z * 64 - 0x20000);

    for (dz = -1; dz < 2; dz++) {
        int gz = z + dz;
        if (gz < 0 || (gz << 6) > 0x80000)
            continue;

        float gridZ = (float)((gz << 6) - 0x20000);

        for (dy = -spread; dy <= spread; dy++) {
            int gy = y + dy;
            if (gy < 0 || (gy << 5) > 0x80000)
                continue;

            float gridY = (float)((gy << 5) - 0x20000);

            for (dx = -spread; dx <= spread; dx++) {
                int gx = x + dx;
                if (gx < 0 || (gx << 5) > 0x80000)
                    continue;

                /* Binary search for this point in vc_log */
                {
                    int bot = 0;
                    int top = s_vc_logCount - 1;
                    vc_log_entry_t *entries = (vc_log_entry_t *)s_vc_log;
                    int found = 0;

                    while (bot <= top) {
                        int mid = (bot + top) / 2;
                        vc_log_entry_t *e = &entries[mid];
                        int cmp;

                        cmp = gx - (int)e->x;
                        if (cmp == 0) {
                            cmp = gy - (int)e->y;
                            if (cmp == 0) {
                                cmp = gz - (int)e->z;
                                if (cmp == 0) {
                                    /* Found - check mid sign for display skip */
                                    if (mid >= 0)
                                        goto next_dx;
                                    found = 1;
                                    break;
                                }
                            }
                        }
                        if (cmp < 0) {
                            top = mid - 1;
                        } else {
                            bot = mid + 1;
                        }
                    }
                }

                /* Not found in log - display point */
                origin[0] = (float)((gx << 5) - 0x20000);
                origin[1] = gridY;
                origin[2] = gridZ;

                if (R_CullPointAndRadius(origin, 0.0f, clipPlanes, clipPlaneCount) == 2)
                    goto next_dx;

                /* Choose color based on dz */
                if ((unsigned int)dz <= 1) {
                    debugColor = colorGreen;
                } else {
                    debugColor = colorRed;
                }

                debugGlobals = *(void **)g_viewParms;
                debugGlobals = (char *)debugGlobals + 0x249d18;
                R_AddDebugString(debugGlobals, origin, debugColor, 1.0f, ".");

            next_dx:
                ;
            }
        }
    }
}

/*
 * Look up a grid point by its packed key using binary search in the
 * lightGrid points array.
 */
static int GridPointLookup(const GfxLightGrid *lightGrid, unsigned int keyHigh, unsigned char keyLow, int *outIndex)
{
    int bot = 0;
    int top = lightGrid->pointCount - 1;
    GfxLightGridPoint *points = lightGrid->points;

    while (bot <= top) {
        int mid = (bot + top) / 2;
        int cmp;
        GfxLightGridPoint *p = &points[mid];

        cmp = (int)p->xyzHighBits - (int)keyHigh;
        if (cmp == 0) {
            cmp = ((int)p->xyzLowBitsAndSunVisible - (int)keyLow) & ~1;
            if (cmp == 0) {
                *outIndex = mid;
                return 1;
            }
        }
        if (cmp < 0) {
            bot = mid + 1;
        } else {
            top = mid - 1;
        }
    }
    *outIndex = bot;
    return 0;
}

/*
 * Pack grid coordinates into the key format used by GfxLightGridPoint.
 */
static void PackGridKey(int gridX, int gridY, int gridZ, unsigned int *keyHigh, unsigned char *keyLow)
{
    *keyHigh = ((gridX & ~3) << 19) | ((gridY & ~3) << 8) | (gridZ >> 2);
    *keyLow = ((gridX & 3) << 6) | ((gridY & 3) << 4) | ((gridZ & 3) << 2);
}

/*
 * Accumulate grid colors from a grid point's color data into colorForDir.
 * Each channel (RGB) has 8 samples stored as bytes, converted to float and
 * weighted by the trilinear interpolation weight.
 */
static void AccumulateGridColors(vec4_t *colorForDir, GfxLightGridColors *gridColors, float weight)
{
    float scale = weight * (1.0f / 255.0f);
    int channelIndex;
    float *outPtr = (float *)colorForDir;

    for (channelIndex = 0; channelIndex < 3; channelIndex++) {
        unsigned char *rgb = &gridColors->rgb[channelIndex][0];
        int j;
        for (j = 0; j < 8; j++) {
            *outPtr += (float)rgb[j] * scale;
            outPtr++;
        }
    }
}

/* line 412 */
float RB_GetLightingAtPoint(const GfxLightGrid *lightGrid, const vec_t *samplePos, vec4_t *colorForDir)
{
    int x0, y0, z0;
    float wx1, wx0, wy1, wy0, wz1, wz0;
    float maxWeight, sunWeight;
    int cornerIndex;
    GfxWorld *world;
    int doDebug;

    /* Compute grid coordinates and interpolation weights */
    {
        float fx = samplePos[0] + 131072.0f;
        float fy = samplePos[1] + 131072.0f;
        float fz = samplePos[2] + 131072.0f;

        x0 = ((int)floorf(fx)) >> 5;
        wx1 = fx * 0.03125f - (float)x0;
        wx0 = 1.0f - wx1;

        y0 = ((int)floorf(fy)) >> 5;
        wy1 = fy * 0.03125f - (float)y0;
        wy0 = 1.0f - wy1;

        z0 = ((int)floorf(fz)) >> 6;
        wz1 = fz * 0.015625f - (float)z0;
        wz0 = 1.0f - wz1;
    }

    /* Debug visualization if enabled */
    doDebug = **(char **)r_lightGridEnableTweaks;
    if (doDebug) {
        vec3_t boxMins, boxMaxs;
        vec3_t sampleBoxMins, sampleBoxMaxs;
        void *debugGlobals;

        /* Draw grid cell box */
        boxMins[0] = (float)(x0 * 32 - 0x20000);
        boxMins[1] = (float)(y0 * 32 - 0x20000);
        boxMins[2] = (float)(z0 * 64 - 0x20000);
        boxMaxs[0] = boxMins[0] + 32.0f;
        boxMaxs[1] = boxMins[1] + 32.0f;
        boxMaxs[2] = boxMins[2] + 64.0f;

        debugGlobals = (char *)(*(void **)g_viewParms) + 0x249d18;
        R_AddDebugBox(debugGlobals, boxMins, boxMaxs, colorWhite);

        /* Draw sample position box */
        sampleBoxMins[0] = samplePos[0] - 0.5f;
        sampleBoxMins[1] = samplePos[1] - 0.5f;
        sampleBoxMins[2] = samplePos[2] - 0.5f;
        sampleBoxMaxs[0] = samplePos[0] + 0.5f;
        sampleBoxMaxs[1] = samplePos[1] + 0.5f;
        sampleBoxMaxs[2] = samplePos[2] + 0.5f;
        R_AddDebugBox(debugGlobals, sampleBoxMins, sampleBoxMaxs, colorYellow);
    }

    /* Clear colorForDir (6 vec4_t = 96 bytes) */
    memset(colorForDir, 0, 0x60);
    maxWeight = 0.0f;
    sunWeight = 0.0f;

    /* Trilinear interpolation over 8 corners */
    for (cornerIndex = 0; cornerIndex < 8; cornerIndex++) {
        int cx = (cornerIndex & 1);
        int gridX = x0 + cx;
        int cy = (cornerIndex >> 1) & 1;
        int gridY = y0 + cy;
        int cz = (cornerIndex >> 2) & 1;
        int gridZ = z0 + cz;
        unsigned int keyHigh;
        unsigned char keyLow;
        int pointIndex;
        int gridIndex;
        GfxLightGridPoint *gridPoint;
        float weight;
        int debugTrace;

        /* Check if vis cache tracing is enabled */
        debugTrace = **(int **)r_lightGridContrast;
        if (debugTrace) {
            /* Check the vis cache log for this point */
            int bot, top, found;
            vc_log_entry_t *entries = (vc_log_entry_t *)s_vc_log;
            top = s_vc_logCount - 1;
            bot = 0;
            found = 0;

            while (bot <= top) {
                int mid = (bot + top) / 2;
                vc_log_entry_t *e = &entries[mid];
                int cmp;

                cmp = gridX - (int)e->x;
                if (cmp == 0) {
                    cmp = gridY - (int)e->y;
                    if (cmp == 0) {
                        cmp = gridZ - (int)e->z;
                        if (cmp == 0) {
                            found = 1;
                            break;
                        }
                    }
                }
                if (cmp < 0) {
                    top = mid - 1;
                } else {
                    bot = mid + 1;
                }
            }

            if (!found) {
                /* Not in cache - insert it */
                if (s_vc_logCount <= 0x3fffff) {
                    int insertAt = bot;
                    int remaining = s_vc_logCount - insertAt;
                    memmove(&entries[insertAt + 1], &entries[insertAt], remaining * sizeof(vc_log_entry_t));
                    entries[insertAt].x = (unsigned short)gridX;
                    entries[insertAt].y = (unsigned short)gridY;
                    entries[insertAt].z = (unsigned short)gridZ;
                    s_vc_logCount++;
                }
            }

            gridY = gridY; /* keep gridY for packing below */
        }

        /* Pack grid coordinates */
        PackGridKey(gridX, gridY, gridZ, &keyHigh, &keyLow);

        /* Look up in light grid */
        if (!GridPointLookup(lightGrid, keyHigh, keyLow, &gridIndex))
            continue;

        gridPoint = &lightGrid->points[gridIndex];

        /* Check if this point needs a visibility trace */
        if (gridPoint->needsTrace & (1 << cornerIndex)) {
            /* Compute grid position and trace direction */
            float gridPosX = (float)(gridX * 32 - 0x20000);
            float gridPosY = (float)(gridY * 32 - 0x20000);
            float gridPosZ = (float)(gridZ * 64 - 0x20000);
            vec3_t traceDir;
            vec3_t nudgedGridPos;

            traceDir[0] = samplePos[0] - gridPosX;
            traceDir[1] = samplePos[1] - gridPosY;
            traceDir[2] = samplePos[2] - gridPosZ;
            Vec3Normalize(traceDir);

            nudgedGridPos[0] = gridPosX + 0.01f * traceDir[0];
            nudgedGridPos[1] = gridPosY + 0.01f * traceDir[1];
            nudgedGridPos[2] = gridPosZ + 0.01f * traceDir[2];

            /* Trace to see if the grid point is visible from samplePos */
            if (CM_BoxSightTrace(0, samplePos, nudgedGridPos, vec3_origin, vec3_origin, 0, 0x2001)) {
                /* Blocked - debug draw if enabled */
                doDebug = **(char **)r_lightGridEnableTweaks;
                if (doDebug) {
                    vec3_t bmin, bmax;
                    bmin[0] = gridPosX - 1.1f;
                    bmin[1] = gridPosY - 1.1f;
                    bmin[2] = gridPosZ - 1.1f;
                    bmax[0] = gridPosX + 1.1f;
                    bmax[1] = gridPosY + 1.1f;
                    bmax[2] = gridPosZ + 1.1f;
                    R_AddDebugBox((char *)(*(void **)g_viewParms) + 0x249d18, bmin, bmax, colorRed);
                }
                continue;
            }

            /* Visible - debug draw */
            doDebug = **(char **)r_lightGridEnableTweaks;
            if (doDebug) {
                vec3_t bmin, bmax;
                bmin[0] = gridPosX - 1.0f;
                bmin[1] = gridPosY - 1.0f;
                bmin[2] = gridPosZ - 1.0f;
                bmax[0] = gridPosX + 1.0f;
                bmax[1] = gridPosY + 1.0f;
                bmax[2] = gridPosZ + 1.0f;
                R_AddDebugBox((char *)(*(void **)g_viewParms) + 0x249d18, bmin, bmax, colorRed);
            }
        } else {
            /* needsTrace bit not set - check debug draw */
            doDebug = **(char **)r_lightGridEnableTweaks;
            if (doDebug) {
                float gridPosX = (float)(gridX * 32 - 0x20000);
                float gridPosY = (float)(gridY * 32 - 0x20000);
                float gridPosZ = (float)(gridZ * 64 - 0x20000);
                vec3_t bmin, bmax;
                bmin[0] = gridPosX - 0.9f;
                bmin[1] = gridPosY - 0.9f;
                bmin[2] = gridPosZ - 0.9f;
                bmax[0] = gridPosX + 0.9f;
                bmax[1] = gridPosY + 0.9f;
                bmax[2] = gridPosZ + 0.9f;
                R_AddDebugBox((char *)(*(void **)g_viewParms) + 0x249d18, bmin, bmax, colorGreen);
            }
        }

        /* Accumulate this corner's contribution */
        weight = (cx ? wx1 : wx0) * (cy ? wy1 : wy0) * (cz ? wz1 : wz0);
        maxWeight += weight;

        /* Get colors for this grid point */
        {
            GfxLightGridColors *colors = &lightGrid->colors[gridPoint->colorsIndex];
            AccumulateGridColors(colorForDir, colors, weight);
        }

        /* Check sun visibility bit */
        if (gridPoint->xyzLowBitsAndSunVisible & 1) {
            sunWeight += weight;
        }
    }

    /* Normalize by maxWeight if needed */
    if (maxWeight >= 0.98f)
        return sunWeight;

    if (maxWeight == 0.0f) {
        /* No valid grid points - find nearest point */
        int nearX, nearY, nearZ;
        unsigned int keyHigh;
        unsigned char keyLow;
        int gridIndex;
        GfxLightGridColors *colors;

        nearX = x0 + (wx1 > 0.5f ? 1 : 0);
        nearY = y0 + (wy1 > 0.5f ? 1 : 0);
        nearZ = z0 + (wz1 > 0.5f ? 1 : 0);

        /* Check if world exists and has points */
        world = rgp->world;
        if (world) {
            doDebug = **(char **)r_lightGridUseTweakedValues;
            if (doDebug) {
                /* Fall through to lookup */
            } else {
                goto setDefaultColors;
            }
        } else {
            goto setDefaultColors;
        }

        if (lightGrid->pointCount == 0)
            goto setDefaultColors;

        PackGridKey(nearX, nearY, nearZ, &keyHigh, &keyLow);

        {
            int bot = 0;
            int top = lightGrid->pointCount - 1;
            GfxLightGridPoint *points = lightGrid->points;

            while (bot <= top) {
                int mid = (bot + top) / 2;
                GfxLightGridPoint *p = &points[mid];
                int cmp;

                cmp = (int)p->xyzHighBits - (int)keyHigh;
                if (cmp == 0) {
                    cmp = ((int)p->xyzLowBitsAndSunVisible - (int)keyLow) & ~1;
                    if (cmp == 0) {
                        gridIndex = mid;
                        goto foundNearest;
                    }
                }
                if (cmp < 0) {
                    bot = mid + 1;
                } else {
                    top = mid - 1;
                }
            }
            gridIndex = bot; /* nearest insertion point */
        }

        {
            GfxLightGridPoint *points = lightGrid->points;
            colors = &lightGrid->colors[points[gridIndex].colorsIndex];
        }

        /* Accumulate the nearest point's colors with weight 1.0 */
        {
            float *outPtr = (float *)colorForDir;
            int channelIndex;
            for (channelIndex = 0; channelIndex < 3; channelIndex++) {
                unsigned char *rgb = &colors->rgb[channelIndex][0];
                int j;
                for (j = 0; j < 8; j++) {
                    *outPtr += (float)rgb[j] * (1.0f / 255.0f);
                    outPtr++;
                }
            }
        }

        /* Check sun visibility */
        if (lightGrid->points[gridIndex].xyzLowBitsAndSunVisible & 1) {
            sunWeight = 1.0f;
        } else {
            /* sunWeight stays as pxor'd 0 */
        }
        return sunWeight;

    foundNearest:
        {
            GfxLightGridPoint *points = lightGrid->points;
            colors = &lightGrid->colors[points[gridIndex].colorsIndex];
        }
        {
            float *outPtr = (float *)colorForDir;
            int channelIndex;
            for (channelIndex = 0; channelIndex < 3; channelIndex++) {
                unsigned char *rgb = &colors->rgb[channelIndex][0];
                int j;
                for (j = 0; j < 8; j++) {
                    *outPtr += (float)rgb[j] * (1.0f / 255.0f);
                    outPtr++;
                }
            }
        }
        if (lightGrid->points[gridIndex].xyzLowBitsAndSunVisible & 1) {
            sunWeight = 1.0f;
        }
        return sunWeight;

    setDefaultColors:
        /* Set default lighting: 6 directions with specific patterns */
        {
            float one = 1.0f;
            float *v = (float *)colorForDir;

            /* Direction 0: (0, 1, 0, 1) */
            v[0] = 0.0f; v[1] = one; v[2] = 0.0f; v[3] = one;
            /* Direction 1: (0, 1, 0, 1) */
            v[4] = 0.0f; v[5] = one; v[6] = 0.0f; v[7] = one;
            /* Direction 2: (0, 0, 1, 1) */
            v[8] = 0.0f; v[9] = 0.0f; v[10] = one; v[11] = one;
            /* Direction 3: (0, 0, 1, 1) */
            v[12] = 0.0f; v[13] = 0.0f; v[14] = one; v[15] = one;
            /* Direction 4: (0, 0, 0, 0) */
            v[16] = 0.0f; v[17] = 0.0f; v[18] = 0.0f; v[19] = 0.0f;
            /* Direction 5: (1, 1, 1, 1) */
            v[20] = one; v[21] = one; v[22] = one; v[23] = one;
        }
        return sunWeight;
    }

    /* Scale all colorForDir values by 1/maxWeight */
    {
        float invWeight = 1.0f / maxWeight;
        float *ptr = (float *)colorForDir;
        int k;

        sunWeight *= invWeight;

        for (k = 0; k < 6; k++) {
            ptr[0] *= invWeight;
            ptr[1] *= invWeight;
            ptr[2] *= invWeight;
            ptr[3] *= invWeight;
            ptr += 4;
        }
    }

    return sunWeight;
}

/* line 499 */
void RB_SetupEntityLighting(const GfxEntity *ent, GfxEntityLighting *lighting)
{
    vec3_t lightOrigin;
    GfxWorld *world;
    unsigned char *entBytes = (unsigned char *)ent;

    /* Set viewCount from backEnd */
    lighting->viewCount = backEnd->viewCount;

    /* Check renderFxFlags sign bit (offset 4 of GfxEntity) */
    if ((signed char)entBytes[4] < 0) {
        /* Use origin at offset 0x08 (axes origin) */
        lightOrigin[0] = *(float *)(entBytes + 8);
        lightOrigin[1] = *(float *)(entBytes + 12);
        lightOrigin[2] = *(float *)(entBytes + 16);
    } else {
        /* Use origin at offset 0x3c (endpos) plus height offset */
        lightOrigin[0] = *(float *)(entBytes + 0x3c);
        lightOrigin[1] = *(float *)(entBytes + 0x40);
        lightOrigin[2] = *(float *)(entBytes + 0x44) + 4.0f;
    }

    world = rgp->world;
    lighting->sunVisibility = RB_GetLightingAtPoint(&world->lightGrid, lightOrigin, lighting->colorForDir);
}

/* line 779 */
void RB_InitLightVisHistory(const char *bspName)
{
    char filename[64];
    void *buffer;
    int fileLen;
    int entrySize;
    int copySize;

    s_vc_log = 0;
    s_vc_logCount = 0;

    if (!**(int **)r_lightGridContrast)
        return;

    s_vc_log = (int)Z_MallocInternal(0x1800000);

    if (**(int **)r_lightGridContrast != 2)
        return;

    BuildGridFilename(bspName, filename);

    fileLen = FS_ReadFile(filename, &buffer);
    if (fileLen < 0)
        return;

    /* Validate file size is a multiple of 6 (entry size) */
    /* Multiply by 0xAAAAAAAAB and shift to divide by 6 */
    entrySize = fileLen / 6;
    if (entrySize * 6 != fileLen)
        goto cleanup;

    /* Clamp copy size */
    copySize = 0x1800000;
    if ((unsigned int)fileLen < 0x1800001u)
        copySize = fileLen;

    memcpy((void *)s_vc_log, buffer, copySize);
    s_vc_logCount = copySize / 6;

cleanup:
    FS_FreeFile(buffer);
}
