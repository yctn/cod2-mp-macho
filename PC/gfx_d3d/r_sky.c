/* Decompiled from: r_sky.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_sky.cpp */

#include "common_types.h"
#include "imports.h"


/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern const dvar_t *r_sunsprite_shader; /* 0x0 */
extern const dvar_t *r_sunsprite_size; /* 0x0 */
extern const dvar_t *r_sunflare_shader; /* 0x0 */
extern const dvar_t *r_sunflare_min_size; /* 0x0 */
extern const dvar_t *r_sunflare_min_angle; /* 0x0 */
extern const dvar_t *r_sunflare_max_size; /* 0x0 */
extern const dvar_t *r_sunflare_max_angle; /* 0x0 */
extern const dvar_t *r_sunflare_max_alpha; /* 0x0 */
extern const dvar_t *r_sunflare_fadein; /* 0x0 */
extern const dvar_t *r_sunflare_fadeout; /* 0x0 */
extern const dvar_t *r_sunblind_min_angle; /* 0x0 */
extern const dvar_t *r_sunblind_max_angle; /* 0x0 */
extern const dvar_t *r_sunblind_max_darken; /* 0x0 */
extern const dvar_t *r_sunblind_fadein; /* 0x0 */
extern const dvar_t *r_sunblind_fadeout; /* 0x0 */
extern const dvar_t *r_sunglare_min_angle; /* 0x0 */
extern const dvar_t *r_sunglare_max_angle; /* 0x0 */
extern const dvar_t *r_sunglare_max_lighten; /* 0x0 */
extern const dvar_t *r_sunglare_fadein; /* 0x0 */
extern const dvar_t *r_sunglare_fadeout; /* 0x0 */
extern const char * s_sundvars[21]; /* 0x0 */
extern const dvar_t *r_sun_fx_position; /* 0x0 */

extern refimport_t *ri;                 /* 0x195eee0 */
extern r_global_permanent_t *rgp;       /* 0x195eebc */
extern const dvar_t **sv_cheats_ptr;    /* 0x195ef54 */
extern unsigned char *r_sunFlareState;  /* 0x195f088 */

extern MaterialHandle Material_RegisterHandle(const char *name, int lightmapIndex, int imageTrack);
extern void R_LoadSunThroughDvars(const char *sunName, sunflare_t *sun);
extern void AngleVectors(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
extern const char *va(const char *format, ...);
extern double cos(double);
extern float floorf(float);
extern unsigned int strlen(const char *);

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define DEG2RAD (M_PI / 180.0)

int R_GetSundvarsSize(void);
int R_RegisterSunDvars(void);
int R_Cmd_LoadSun(void);
int R_Cmd_SaveSun(void);
int R_FlushSun(void);
int R_SetSunFromDvars(sunflare_t *sun);

int R_GetSundvarsSize(void)
{
    return 0x15;
}

int R_RegisterSunDvars(void)
{
    r_sunsprite_shader = ri->Dvar_RegisterString("r_sunsprite_shader", "sun", 0x2000);
    r_sunsprite_size = ri->Dvar_RegisterFloat("r_sunsprite_size", 16.0f, 1.0f, 1000.0f, 0x2000);

    r_sunflare_shader = ri->Dvar_RegisterString("r_sunflare_shader", "sun_flare", 0x2000);
    r_sunflare_min_size = ri->Dvar_RegisterFloat("r_sunflare_min_size", 0.0f, 0.0f, 10000.0f, 0x2000);
    r_sunflare_min_angle = ri->Dvar_RegisterFloat("r_sunflare_min_angle", 45.0f, 0.0f, 90.0f, 0x2000);
    r_sunflare_max_size = ri->Dvar_RegisterFloat("r_sunflare_max_size", 2500.0f, 0.0f, 10000.0f, 0x2000);
    r_sunflare_max_angle = ri->Dvar_RegisterFloat("r_sunflare_max_angle", 2.0f, 0.0f, 90.0f, 0x2000);
    r_sunflare_max_alpha = ri->Dvar_RegisterFloat("r_sunflare_max_alpha", 1.0f, 0.0f, 1.0f, 0x2000);
    r_sunflare_fadein = ri->Dvar_RegisterFloat("r_sunflare_fadein", 1.0f, 0.0f, 60.0f, 0x2000);
    r_sunflare_fadeout = ri->Dvar_RegisterFloat("r_sunflare_fadeout", 1.0f, 0.0f, 60.0f, 0x2000);

    r_sunblind_min_angle = ri->Dvar_RegisterFloat("r_sunblind_min_angle", 30.0f, 0.0f, 90.0f, 0x2000);
    r_sunblind_max_angle = ri->Dvar_RegisterFloat("r_sunblind_max_angle", 5.0f, 0.0f, 90.0f, 0x2000);
    r_sunblind_max_darken = ri->Dvar_RegisterFloat("r_sunblind_max_darken", 0.75f, 0.0f, 1.0f, 0x2000);
    r_sunblind_fadein = ri->Dvar_RegisterFloat("r_sunblind_fadein", 0.5f, 0.0f, 60.0f, 0x2000);
    r_sunblind_fadeout = ri->Dvar_RegisterFloat("r_sunblind_fadeout", 3.0f, 0.0f, 60.0f, 0x2000);

    r_sunglare_min_angle = ri->Dvar_RegisterFloat("r_sunglare_min_angle", 30.0f, 0.0f, 90.0f, 0x2000);
    r_sunglare_max_angle = ri->Dvar_RegisterFloat("r_sunglare_max_angle", 5.0f, 0.0f, 90.0f, 0x2000);
    r_sunglare_max_lighten = ri->Dvar_RegisterFloat("r_sunglare_max_lighten", 0.75f, 0.0f, 1.0f, 0x2000);
    r_sunglare_fadein = ri->Dvar_RegisterFloat("r_sunglare_fadein", 0.5f, 0.0f, 60.0f, 0x2000);
    r_sunglare_fadeout = ri->Dvar_RegisterFloat("r_sunglare_fadeout", 3.0f, 0.0f, 60.0f, 0x2000);

    r_sun_fx_position = ri->Dvar_RegisterVec3("r_sun_fx_position", 0.0f, 0.0f, 0.0f, -360.0f, 360.0f, 0x2000);

    return 0;
}

int R_Cmd_LoadSun(void)
{
    int argc;
    const char *sunName;
    GfxWorld *world;

    argc = ri->Cmd_Argc();
    if (argc != 2) {
        ri->Printf(0, "usage: loadsun <name>\n");
        return 0;
    }

    sunName = (*sv_cheats_ptr)->current.string;
    if (sunName[0] == '\0') {
        ri->Printf(0, "must be in a level to loadsun\n");
        return 0;
    }

    world = rgp->world;
    if (world == NULL) {
        ri->Printf(0, "must have a world loaded to loadsun\n");
        return 0;
    }

    sunName = ri->Cmd_Argv(1);
    R_LoadSunThroughDvars(sunName, &world->sun);

    return 0;
}

int R_Cmd_SaveSun(void)
{
    int argc;
    const char *sunName;
    char szFileBuffer[0x2000];
    int len;

    argc = ri->Cmd_Argc();
    if (argc != 2) {
        ri->Printf(0, "usage: savesun <name>\n");
        return 0;
    }

    sunName = ri->Cmd_Argv(1);

    if (ri->Com_SaveDvarsToBuffer((const char **)s_sundvars, 0x15, szFileBuffer, 0x2000)) {
        const char *filename;
        len = strlen(szFileBuffer);
        filename = va("sun/%s.sun", sunName);
        ri->FS_WriteFile(filename, szFileBuffer, len);
    }

    return 0;
}

int R_FlushSun(void)
{
    int i;
    unsigned char *p;

    p = r_sunFlareState;
    for (i = 0; i < 4; i++) {
        *(int *)(p + 0x04) = 0;
        *(int *)(p + 0x08) = 0;
        *(int *)(p + 0x00) = 0;
        *(int *)(p + 0x20) = 0;
        *(int *)(p + 0x1c) = 0;
        *(int *)(p + 0x0c) = 0;
        *(int *)(p + 0x18) = 0;
        p += 0x30;
    }

    return 0;
}

int R_SetSunFromDvars(sunflare_t *sun)
{
    sun->spriteMaterial = Material_RegisterHandle(r_sunsprite_shader->current.string, 0, 6);

    sun->spriteSize = r_sunsprite_size->current.value;

    sun->flareMaterial = Material_RegisterHandle(r_sunflare_shader->current.string, 0, 6);

    sun->flareMinSize = r_sunflare_min_size->current.value * 0.5f;
    sun->flareMinDot = (float)cos((double)r_sunflare_min_angle->current.value * DEG2RAD);
    sun->flareMaxSize = r_sunflare_max_size->current.value * 0.5f;
    sun->flareMaxDot = (float)cos((double)r_sunflare_max_angle->current.value * DEG2RAD);
    sun->flareMaxAlpha = r_sunflare_max_alpha->current.value;
    sun->flareFadeInTime = (int)floorf(r_sunflare_fadein->current.value * 1000.0f + 0.5f);
    sun->flareFadeOutTime = (int)floorf(r_sunflare_fadeout->current.value * 1000.0f + 0.5f);

    sun->blindMinDot = (float)cos((double)r_sunblind_min_angle->current.value * DEG2RAD);
    sun->blindMaxDot = (float)cos((double)r_sunblind_max_angle->current.value * DEG2RAD);
    sun->blindMaxDarken = r_sunblind_max_darken->current.value;
    sun->blindFadeInTime = (int)floorf(r_sunblind_fadein->current.value * 1000.0f + 0.5f);
    sun->blindFadeOutTime = (int)floorf(r_sunblind_fadeout->current.value * 1000.0f + 0.5f);

    sun->glareMinDot = (float)cos((double)r_sunglare_min_angle->current.value * DEG2RAD);
    sun->glareMaxDot = (float)cos((double)r_sunglare_max_angle->current.value * DEG2RAD);
    sun->glareMaxLighten = r_sunglare_max_lighten->current.value;
    sun->glareFadeInTime = (int)floorf(r_sunglare_fadein->current.value * 1000.0f + 0.5f);
    sun->glareFadeOutTime = (int)floorf(1000.0f * r_sunglare_fadeout->current.value + 0.5f);

    AngleVectors(r_sun_fx_position->current.vector, sun->sunFxPosition, 0, 0);

    sun->hasValidData = 1;

    return 0;
}
