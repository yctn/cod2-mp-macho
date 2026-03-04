/* Decompiled from: bg_weapons_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_weapons_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

#include <string.h>
#include <strings.h>
#define stricmp strcasecmp

extern void BG_InitWeaponString(int index, const char *name);
extern int FS_FOpenFileByMode(const char *filename, fileHandle_t *f, int mode);
extern void Com_Error(int code, const char *fmt, ...);
extern void FS_FCloseFile(fileHandle_t f);
extern int FS_Read(void *buffer, int len, fileHandle_t f);
extern void Com_BeginParseSession(const char *name);
extern char *Com_Parse(char **data_p);
extern void Com_EndParseSession(void);
extern void *Hunk_AllocLowInternal(int size);
extern void *Hunk_AllocLowAlignInternal(int size, int align);
extern qboolean G_ParseWeaponAccurayGraphs(WeaponDef *weapDef);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern qboolean Info_Validate(const char *s);
extern int ParseConfigStringToStruct(byte *pStruct, cspField_t *fields, int numFields, const char *buffer, int maxFieldTypes, qboolean (*parseSpecificFieldType)(byte *, const char *, int), long int (*setConfigString)(byte *, const char *));
extern void I_strlwr(char *s);

static WeaponDef bg_defaultWeaponDefs; /* bg_defaultWeaponDefs */
static int g_playerAnimTypeNamesCount; /* g_playerAnimTypeNamesCount */
static char * g_playerAnimTypeNames[64]; /* g_playerAnimTypeNames */
extern char * szWeapTypeNames[4]; /* szWeapTypeNames */
extern char * szWeapSlotNames[3]; /* szWeapSlotNames */
extern char * szProjectileExplosionNames[3]; /* szProjectileExplosionNames */
extern char * szWeapOverlayReticleNames[5]; /* szWeapOverlayReticleNames */
extern char * szWeapClassNames[10]; /* szWeapClassNames */
extern char * szWeapStanceNames[3]; /* szWeapStanceNames */
extern char * offhandClassNames[3]; /* offhandClassNames */
extern cspField_t weaponDefFields[366]; /* weaponDefFields */

int BG_GetWeaponSlotForName(const char *pszSlotName);
const char * BG_GetWeaponSlotNameForIndex(int iSlot);
long int BG_LoadWeaponStrings(void);
long int BG_LoadPlayerAnimTypes(void);
long int SetConfigString(char * *ppszConfigString, const char *pszKeyValue);
WeaponDef * BG_LoadDefaultWeaponDef(void);
static qboolean BG_ParseWeaponDefSpecificFieldType(byte *pStruct, const char *pValue, const int iFieldType);
static long int SetConfigString2(byte *pMember, const char *pszKeyValue);
WeaponDef * BG_LoadWeaponDefInternal(const char *folder, const char *name);

/* Helper: search a name array using case-insensitive compare, return index or -1 */
static int FindNameIndex(const char *pValue, char **names, int count)
{
    int i;
    for (i = 0; i < count; i++) {
        if (!stricmp(pValue, names[i])) {
            return i;
        }
    }
    return -1;
}

/* Helper: initialize string fields of a WeaponDef to "" */
static void BG_InitWeaponDefStrings(WeaponDef *weapDef)
{
    int i;

    weapDef->szInternalName = "";
    for (i = 0; i < 366; i++) {
        if (weaponDefFields[i].iFieldType == 0) {
            *(char **)((byte *)weapDef + weaponDefFields[i].iOffset) = "";
        }
    }
}

/* line 613 */
int BG_GetWeaponSlotForName(const char *pszSlotName)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (!stricmp(pszSlotName, szWeapSlotNames[i])) {
            break;
        }
    }
    if (i == 3) {
        i = 0;
    }

    return i;
}

/* line 635 */
const char * BG_GetWeaponSlotNameForIndex(int iSlot)
{
    return szWeapSlotNames[iSlot];
}

/* line 650 */
long int BG_LoadWeaponStrings(void)
{
    int i;

    if (g_playerAnimTypeNamesCount > 0) {
        for (i = 0; i < g_playerAnimTypeNamesCount; i++) {
            BG_InitWeaponString(i, g_playerAnimTypeNames[i]);
        }
    }
}

/* line 668 */
long int BG_LoadPlayerAnimTypes(void)
{
    fileHandle_t f;
    int iLen;
    char buf[4096];
    char *text_p;
    char *token;

    g_playerAnimTypeNamesCount = 0;

    iLen = FS_FOpenFileByMode("mp/playeranimtypes.txt", &f, 0);
    if (iLen < 0) {
        Com_Error(1, "Couldn't load file '%s'", "mp/playeranimtypes.txt");
    }

    if (iLen > 4095) {
        FS_FCloseFile(f);
        Com_Error(1, "'%s' max size exceeded", "mp/playeranimtypes.txt");
    }

    FS_Read(buf, iLen, f);
    buf[iLen] = '\0';
    FS_FCloseFile(f);

    text_p = buf;
    Com_BeginParseSession("BG_AnimParseAnimScript");

    while (1) {
        token = Com_Parse(&text_p);
        if (!token || *token == '\0') {
            break;
        }
        if (g_playerAnimTypeNamesCount > 63) {
            Com_Error(1, "Player anim type array size exceeded");
        }
        g_playerAnimTypeNames[g_playerAnimTypeNamesCount] = Hunk_AllocLowInternal(strlen(token) + 1);
        strcpy(g_playerAnimTypeNames[g_playerAnimTypeNamesCount], token);
        g_playerAnimTypeNamesCount++;
    }

    Com_EndParseSession();
}

/* line 916 */
long int SetConfigString(char * *ppszConfigString, const char *pszKeyValue)
{
    char *buf;

    if (*pszKeyValue == '\0') {
        *ppszConfigString = "";
        return 0;
    }

    buf = Hunk_AllocLowAlignInternal(strlen(pszKeyValue) + 1, 1);
    strcpy(buf, pszKeyValue);
    *ppszConfigString = buf;
    return 0;
}

/* line 933 */
static long int SetConfigString2(byte *pMember, const char *pszKeyValue)
{
    char *buf;

    if (*pszKeyValue == '\0') {
        *(char **)pMember = "";
        return 0;
    }

    buf = Hunk_AllocLowAlignInternal(strlen(pszKeyValue) + 1, 1);
    strcpy(buf, pszKeyValue);
    *(char **)pMember = buf;
    return 0;
}

/* line 1051 */
WeaponDef * BG_LoadDefaultWeaponDef(void)
{
    BG_InitWeaponDefStrings(&bg_defaultWeaponDefs);

    bg_defaultWeaponDefs.szInternalName = "none";
    bg_defaultWeaponDefs.accuracyGraphName[0] = "noweapon.accu";
    bg_defaultWeaponDefs.accuracyGraphName[1] = "noweapon.accu";

    G_ParseWeaponAccurayGraphs(&bg_defaultWeaponDefs);

    return &bg_defaultWeaponDefs;
}

/* line 778 */
static qboolean BG_ParseWeaponDefSpecificFieldType(byte *pStruct, const char *pValue, const int iFieldType)
{
    int arrayIndex;
    int arraySize;
    WeaponDef *wd = (WeaponDef *)pStruct;

    switch (iFieldType - 8) {
    case 0: /* weapType */
        arrayIndex = FindNameIndex(pValue, szWeapTypeNames, 4);
        if (arrayIndex < 0) {
            Com_Error(1, "Unknown weapon type \"%s\" in \"%s\"\n", pValue, wd->szInternalName);
        }
        wd->weapType = arrayIndex;
        return 1;

    case 1: /* weapClass */
        arrayIndex = FindNameIndex(pValue, szWeapClassNames, 10);
        if (arrayIndex < 0) {
            Com_Error(1, "Unknown weapon class \"%s\" in \"%s\"\n", pValue, wd->szInternalName);
        }
        wd->weapClass = arrayIndex;
        return 1;

    case 2: /* overlayReticle */
        arrayIndex = FindNameIndex(pValue, szWeapOverlayReticleNames, 5);
        if (arrayIndex < 0) {
            Com_Error(1, "Unknown weapon overlay reticle \"%s\" in \"%s\"\n", pValue, wd->szInternalName);
        }
        wd->overlayReticle = arrayIndex;
        return 1;

    case 3: /* weapSlot */
        arrayIndex = FindNameIndex(pValue, szWeapSlotNames, 3);
        if (arrayIndex < 0) {
            Com_Error(1, "Unknown weapon slot \"%s\" in \"%s\"\n", pValue, wd->szInternalName);
        }
        wd->weapSlot = arrayIndex;
        return 1;

    case 4: /* stance */
        arrayIndex = FindNameIndex(pValue, szWeapStanceNames, 3);
        if (arrayIndex < 0) {
            Com_Error(1, "Unknown weapon stance \"%s\" in \"%s\"\n", pValue, wd->szInternalName);
        }
        wd->stance = arrayIndex;
        return 1;

    case 5: /* projExplosion */
        arrayIndex = FindNameIndex(pValue, szProjectileExplosionNames, 3);
        if (arrayIndex < 0) {
            Com_Error(1, "Unknown projectile explosion \"%s\" in \"%s\"\n", pValue, wd->szInternalName);
        }
        wd->projExplosion = arrayIndex;
        return 1;

    case 6: /* offhandClass */
        arrayIndex = FindNameIndex(pValue, offhandClassNames, 3);
        if (arrayIndex < 0) {
            Com_Error(1, "Unknown offhand class \"%s\" in \"%s\"\n", pValue, wd->szInternalName);
        }
        wd->offhandClass = arrayIndex;
        return 1;

    case 7: /* playerAnimType */
        arraySize = g_playerAnimTypeNamesCount;
        arrayIndex = FindNameIndex(pValue, g_playerAnimTypeNames, arraySize);
        if (arrayIndex < 0) {
            Com_Error(1, "Unknown playerAnimType \"%s\" in \"%s\"\n", pValue, wd->szInternalName);
        }
        wd->playerAnimType = arrayIndex;
        return 1;

    default:
        Com_Error(1, "Bad field type %i in %s\n", iFieldType, wd->szInternalName);
        return 0;
    }
}

/* line 968 */
WeaponDef * BG_LoadWeaponDefInternal(const char *folder, const char *name)
{
    WeaponDef *weapDef;
    fileHandle_t hFile;
    int iFileLength;
    char szFileName[64];
    char szBuffer[8192];

    weapDef = Hunk_AllocLowInternal(sizeof(WeaponDef));

    BG_InitWeaponDefStrings(weapDef);

    Com_sprintf(szFileName, 64, "weapons/%s/%s", folder, name);

    iFileLength = FS_FOpenFileByMode(szFileName, &hFile, 0);
    if (iFileLength < 0) {
        Com_Printf("^3WARNING: Could not load weapon file '%s'\n", szFileName);
        return 0;
    }

    /* Read and check magic header */
    FS_Read(szBuffer, 10, hFile);
    szBuffer[10] = '\0';
    if (memcmp(szBuffer, "WEAPONFILE", 10) != 0) {
        Com_Printf("^3WARNING: \"%s\" does not appear to be a weapon file\n", szFileName);
        FS_FCloseFile(hFile);
        return 0;
    }

    iFileLength -= 10;
    if (iFileLength > 8191) {
        Com_Printf("^3WARNING: \"%s\" Is too long of a weapon file to parse\n", szFileName);
        FS_FCloseFile(hFile);
        return 0;
    }

    memset(szBuffer, 0, 8192);
    FS_Read(szBuffer, iFileLength, hFile);
    szBuffer[iFileLength] = '\0';
    FS_FCloseFile(hFile);

    if (!Info_Validate(szBuffer)) {
        Com_Printf("^3WARNING: \"%s\" is not a valid weapon file\n", szFileName);
        return 0;
    }

    /* Set weapon name */
    SetConfigString((char **)&weapDef->szInternalName, name);

    if (!ParseConfigStringToStruct((byte *)weapDef, weaponDefFields, 366, szBuffer, 16,
                                    BG_ParseWeaponDefSpecificFieldType, SetConfigString2)) {
        weapDef = 0;
        return weapDef;
    }

    /* Compute fire time rate */
    if (weapDef->iFireTime > 0) {
        weapDef->fOOPosAnimLength[0] = 1.0f / (float)weapDef->iFireTime;
    } else {
        /* Default: ~1/300 */
        *(int *)&weapDef->fOOPosAnimLength[0] = 0x3b5a740e;
    }

    /* Compute rechamber time rate */
    if (weapDef->iRechamberTime > 0) {
        weapDef->fOOPosAnimLength[1] = 1.0f / (float)weapDef->iRechamberTime;
    } else {
        /* Default: ~1/500 */
        *(int *)&weapDef->fOOPosAnimLength[1] = 0x3b03126f;
    }

    /* Default destabilization base time if not set */
    if (weapDef->destabilizationBaseTime <= 0.0f) {
        *(int *)&weapDef->destabilizationBaseTime = 0x497423f0; /* 999999.0f */
    }

    /* Default destabilization time reduction ratio if not set */
    if (weapDef->destabilizationTimeReductionRatio <= 0.0f) {
        *(int *)&weapDef->destabilizationTimeReductionRatio = 0x497423f2; /* ~999999.0f */
    }

    /* Validate enemy crosshair range */
    if (weapDef->enemyCrosshairRange > 15000.0f) {
        Com_Error(1, "Enemy crosshair ranges should be less than %f ", 15000.0);
    }

    /* Projectile weapon validations */
    if (weapDef->weapType == 2) {
        if ((float)weapDef->iProjectileSpeed <= 0.0f) {
            Com_Error(1, "Projectile speed for WeapType %s must be greater than 0.0", weapDef->szDisplayName);
        }

        if (weapDef->destabilizationAngleMax >= 45.0f || weapDef->destabilizationAngleMax < 0.0f) {
            Com_Error(1, "Destabilization angle for for WeapType %s must be between 0 and 45 degrees", weapDef->szDisplayName);
        }

        if (weapDef->destabilizationBaseTime <= 0.0f) {
            Com_Error(1, "Destabilization base time for for WeapType %s must be positive", weapDef->szDisplayName);
        }

        if (weapDef->destabilizationTimeReductionRatio <= 0.0f) {
            Com_Error(1, "Destabilization reduction ratio for for WeapType %s must be positive", weapDef->szDisplayName);
        }
    }

    if (!G_ParseWeaponAccurayGraphs(weapDef)) {
        weapDef = 0;
        return weapDef;
    }

    I_strlwr(weapDef->szAmmoName);
    I_strlwr(weapDef->szClipName);

    return weapDef;
}
