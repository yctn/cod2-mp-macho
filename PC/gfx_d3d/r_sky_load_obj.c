/* Converted to C from ASM: r_sky_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_sky_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

extern char *va(const char *format, ...);
extern int FS_ReadFile(const char *filename, void **buffer);
extern void FS_FreeFile(void *buffer);
extern int R_GetSundvarsSize(void);
extern int Com_LoadDvarsFromBuffer(void *dvarTable, int numDvars, const void *buffer, const char *filename);
extern void R_SetSunFromDvars(sunflare_t *sun);
extern void Com_Printf(const char *fmt, ...);
extern void Com_Memset(void *dest, int val, int count);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern char *strchr(const char *s, int c);

extern void *r_sundvar_table; /* imp_s_sundvars */

void R_LoadSunThroughDvars(const char *sunName, sunflare_t *sun)
{
    const char *fullpath;
    void *sunFile;

    fullpath = va("sun/%s.sun", sunName);
    if (FS_ReadFile(fullpath, &sunFile) < 0) {
        Com_Printf("^3WARNING: couldn't load sun file '%s'\n", fullpath);
        return;
    }

    if (Com_LoadDvarsFromBuffer(&r_sundvar_table, R_GetSundvarsSize(), sunFile, fullpath)) {
        R_SetSunFromDvars(sun);
    }

    FS_FreeFile(sunFile);
}

void R_LoadSun(const char *name, sunflare_t *sun)
{
    char sunFile[64];
    const char *lastSlash;
    const char *p;
    char *dot;

    Com_Memset(sun, 0, 0x60);

    /* Find last path separator */
    lastSlash = name;
    p = name;
    while (*p) {
        if (*p == '/' || *p == '\\') {
            lastSlash = p + 1;
        }
        p++;
    }

    /* Copy basename into sunFile buffer */
    I_strncpyz(sunFile, lastSlash, 0x40);

    /* Strip extension */
    dot = strchr(sunFile, '.');
    if (dot)
        *dot = '\0';

    if (sunFile[0] != '\0') {
        R_LoadSunThroughDvars(sunFile, sun);
    }
}
