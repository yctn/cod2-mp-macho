/* Converted to C from ASM: r_utils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_utils.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern int strnicmp(const char *s1, const char *s2, int n);
extern double acos(double);
extern double asin(double);
extern double sin(double);
extern double tan(double);
extern double fabs(double);

extern byte *r_vtable_ptr;         /* 0x195eee0 */
extern byte *r_world_ptr;          /* 0x195ed4c */
extern byte *r_surftype_table_ptr; /* 0x195f1f4 */

int R_HashAssetName(const char *name);
int R_HashString(const char *string);
int R_CullPointAndRadius(const vec_t *pt, float radius, const DpvsPlane *clipPlanes, int clipPlaneCount);
double R_ConvertColorToBytes(const vec_t *colorFloat, byte *colorBytes);
qboolean R_PickMaterial(const vec_t *org, const vec_t *dir, char *name, char *surfaceFlags, char *contents, int charLimit);
Bool R_ValidXModelName(const char *name);
float FresnelTerm(float n0, float n1, float cosIncidentAngle);

/* line 26 */
int R_HashAssetName(const char *name)
{
    int hash = 0;
    int mult = 0x77;
    int i;

    for (i = 0; name[i]; i++) {
        hash += (signed char)name[i] * mult;
        mult++;
    }
    return hash;
}

/* line 49 */
int R_HashString(const char *string)
{
    int hash = 0;
    int mult = 0x77;
    int i;

    for (i = 0; string[i]; i++) {
        hash += (signed char)(string[i] | 0x20) * mult;
        mult++;
    }
    return hash;
}

/* line 90 */
int R_CullPointAndRadius(const vec_t *pt, float radius, const DpvsPlane *clipPlanes, int clipPlaneCount)
{
    int i;
    float negRadius = -radius;

    for (i = 0; i < clipPlaneCount; i++) {
        byte *plane = (byte *)clipPlanes + i * 0x14;
        float dist = pt[0] * *(float *)(plane)
                   + pt[1] * *(float *)(plane + 4)
                   + pt[2] * *(float *)(plane + 8)
                   + *(float *)(plane + 0xc);
        if (dist < negRadius)
            return 2;
    }
    return 0;
}

/* line 106 */
double R_ConvertColorToBytes(const vec_t *colorFloat, byte *colorBytes)
{
    if (colorFloat == NULL) {
        *(int *)colorBytes = -1;
        return 0;
    }

    colorBytes[0] = (byte)(int)(colorFloat[3] * 255.0f);
    colorBytes[1] = (byte)(int)(colorFloat[0] * 255.0f);
    colorBytes[2] = (byte)(int)(colorFloat[1] * 255.0f);
    colorBytes[3] = (byte)(int)(colorFloat[2] * 255.0f);
}

/* line 154 */
qboolean R_PickMaterial(const vec_t *org, const vec_t *dir, char *name, char *surfaceFlags, char *contents, int charLimit)
{
    float end[3];
    byte trace[36];
    int surfFlags;
    int contFlags;
    void *material;
    int surfType;
    int surfaceFlagsLen;
    int contentsLen;
    char *surfEnd;
    char *contEnd;
    char *appendPos;
    void **vtable;
    byte *table;
    int entryOff;

    end[0] = org[0] + dir[0] * 262144.0f;
    end[1] = org[1] + dir[1] * 262144.0f;
    end[2] = org[2] + dir[2] * 262144.0f;

    vtable = *(void ***)&r_vtable_ptr;
    {
        void *worldPtr = *(void **)&r_world_ptr;
        ((void (*)(void *, const vec_t *, float *, void *, void *, int, int))vtable[0x158/4])
            (trace, org, end, worldPtr, worldPtr, 0, 0x0f83fff7);
    }

    if (*(short *)(trace + 0x22) != 0)
        return 0;
    if (*(float *)trace == 1.0f)
        return 0;
    material = *(void **)(trace + 0x18);
    if (material == NULL)
        return 0;

    strcpy(name, (char *)material);

    surfaceFlags[0] = '\0';
    surfEnd = surfaceFlags + charLimit - 1;
    *surfEnd = '\0';
    contents[0] = '\0';
    contEnd = contents + charLimit - 1;
    *contEnd = '\0';

    surfFlags = *(int *)(trace + 0x10);
    surfType = ((surfFlags & 0x1f00000) >> 20) - 1;

    if (surfType > 21) {
        strncpy(surfaceFlags, "^1default^7", charLimit);
    } else {
        table = *(byte **)&r_surftype_table_ptr;
        strncpy(surfaceFlags, *(char **)(table + surfType * 20), charLimit);
    }

    if (*surfEnd != '\0')
        return 0;

    surfaceFlagsLen = strlen(surfaceFlags);

    contFlags = *(int *)(trace + 0x14);
    if (contFlags & 1) {
        strncpy(contents, "solid", charLimit);
    } else {
        strncpy(contents, "^3nonsolid^7", charLimit);
    }

    if (*contEnd != '\0')
        return 0;

    contentsLen = strlen(contents);

    table = *(byte **)&r_surftype_table_ptr;
    entryOff = 0x1b8;

    while (*(char **)(table + entryOff) != NULL) {
        if (*(int *)(table + entryOff + 8) & surfFlags) {
            surfaceFlags[surfaceFlagsLen] = ' ';
            appendPos = surfaceFlags + surfaceFlagsLen + 1;
            strncpy(appendPos, *(char **)(table + entryOff), charLimit - surfaceFlagsLen - 1);
            if (*surfEnd != '\0')
                return 0;
            surfaceFlagsLen = surfaceFlagsLen + 1 + strlen(appendPos);
        }

        if (*(int *)(table + entryOff + 0xc) & contFlags) {
            contents[contentsLen] = ' ';
            appendPos = contents + contentsLen + 1;
            strncpy(appendPos, *(char **)(table + entryOff), charLimit - contentsLen - 1);
            if (*contEnd != '\0')
                return 0;
            contentsLen = contentsLen + 1 + strlen(appendPos);
        }

        entryOff += 0x14;
    }

    return 1;
}

/* line 223 */
Bool R_ValidXModelName(const char *name)
{
    if (strlen(name) > 63)
        return 0;
    if (strnicmp(name, "xmodel", 6) != 0)
        return 0;
    if (name[6] != '/')
        return 0;
    return 1;
}

/* line 231 */
float FresnelTerm(float n0, float n1, float cosIncidentAngle)
{
    double incidentAngle;
    double sinRefracted;
    double refractedAngle;
    double sumAngle;
    double diffAngle;
    double Rs;
    double Rp;
    double reflectance;
    float result;

    incidentAngle = acos(fabs((double)cosIncidentAngle));
    sinRefracted = (double)(n0 / n1) * sin(incidentAngle);

    if (sinRefracted > 1.0)
        sinRefracted = sinRefracted;
    else if (sinRefracted < -1.0)
        sinRefracted = -1.0;

    refractedAngle = asin(sinRefracted);

    sumAngle = incidentAngle + refractedAngle;
    diffAngle = incidentAngle - refractedAngle;

    Rs = sin(diffAngle) / sin(sumAngle);
    Rp = tan(diffAngle) / tan(sumAngle);

    reflectance = Rs * Rs + Rp * Rp;
    result = (float)(reflectance * 0.5);

    if (result < 0.0f)
        result = 0.0f;
    if (result > 1.0f)
        result = 1.0f;

    return result;
}
