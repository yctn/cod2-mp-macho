/* Decompiled from: com_playerprofile.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/com_playerprofile.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdarg.h>
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

extern const dvar_t *com_playerProfile; /* 0x0 */
extern const dvar_t *ui_playerProfileAlreadyChosen; /* 0x0 */

extern void Com_Error(int level, const char *fmt, ...);
extern int Com_sprintf(char *dest, int size, const char *fmt, ...);
extern const char *Com_Parse(const char **buf);
extern void Com_Printf(const char *fmt, ...);
extern void Com_ExecStartupConfigs(const char *configFile);
extern void Com_CheckSetRecommended(void);
extern void Cbuf_ExecuteText(int exec_when, const char *text);
extern void Cbuf_AddText(const char *text);
extern void Dvar_ResetDvars(unsigned int filter, DvarSetSource setSource);
extern Bool Dvar_AnyLatchedValues(void);
extern void Dvar_SetString(const dvar_t *dvar, const char *value);
extern const dvar_t *Dvar_RegisterInt(const char *name, int value, int min, int max, unsigned int flags);
extern const dvar_t *Dvar_RegisterString(const char *name, const char *value, unsigned int flags);
extern void Dvar_ChangeResetValue(const dvar_t *dvar, DvarValue value);
extern int FS_ReadFile(const char *qpath, void **buffer);
extern void FS_FreeFile(void *buffer);
extern const char **FS_ListFiles(const char *path, const char *extension, int behavior, int *numfiles, int allocTrackType);
extern void FS_FreeFileList(const char **list, int allocTrackType);
extern void FS_BuildOSPath(const char *base, const char *game, const char *qpath, char *ospath);
extern qboolean FS_CreatePath(char *OSPath);
extern qboolean FS_WriteFile(const char *qpath, const void *buffer, int size);
extern int I_stricmp(const char *s1, const char *s2);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern qboolean Sys_RemoveDirTree(const char *path);

extern const dvar_t *fs_basepath;
extern char fs_gamedir[256];

Bool Com_HasPlayerProfile(void);
int Com_BuildPlayerProfilePath(char *path, int pathSize, const char *format, ...);
int Com_BuildPlayerProfilePathForPlayer(char *path, int pathSize, const char *playerName, const char *format, ...);
Bool Com_DeletePlayerProfile(const char *profileName);
JCOEF Com_ChangePlayerProfile(const char *profileName);
JCOEF Com_InitPlayerProfiles(void);
Bool Com_NewPlayerProfile(const char *profileName);

/*
 * Helper: Check if profileName exists in the "players" directory listing.
 * Returns 1 if found, 0 if not.
 * Used by Com_DeletePlayerProfile, Com_ChangePlayerProfile,
 * Com_InitPlayerProfiles, and Com_NewPlayerProfile.
 */
static int Com_PlayerProfileExists(const char *profileName)
{
    int dirCount;
    const char **dirs;
    int i;
    int found;

    if (profileName[0] == '\0')
        return 0;

    dirs = FS_ListFiles("players", "/", 1, &dirCount, 3);
    found = 0;
    if (dirCount > 0) {
        for (i = 0; i < dirCount; i++) {
            if (I_stricmp(dirs[i], profileName) == 0) {
                found = 1;
                break;
            }
        }
    }
    FS_FreeFileList(dirs, 3);
    return found;
}

/*
 * Helper: Set player profile dvar and exec startup configs.
 * Used by Com_ChangePlayerProfile and Com_InitPlayerProfiles.
 */
static void Com_SetPlayerProfileAndExec(const char *profileName)
{
    char configFile[64];

    Dvar_SetString(com_playerProfile, profileName);
    Com_BuildPlayerProfilePath(configFile, 64, "config_mp.cfg");
    Com_ExecStartupConfigs(configFile);
}

/* line 124 */
Bool Com_HasPlayerProfile(void)
{
    return com_playerProfile->current.string[0] != '\0';
}

/*
 * Helper: Build path with prefix "players/<profile>/" then append formatted suffix.
 * Returns total length, or pathSize if truncated.
 */
static int Com_BuildPlayerProfilePathInternal(char *path, int pathSize, const char *playerName, const char *format, va_list vargs)
{
    int prefixLength;
    int suffixLength;
    int totalLength;

    prefixLength = Com_sprintf(path, pathSize, "players/%s/", playerName);
    if (prefixLength < 0 || prefixLength >= pathSize) {
        return pathSize;
    }

    suffixLength = vsnprintf(path + prefixLength, pathSize - prefixLength, format, vargs);
    totalLength = prefixLength + suffixLength;
    if (suffixLength < 0 || totalLength >= pathSize) {
        path[pathSize - 1] = '\0';
        return pathSize;
    }

    return totalLength;
}

/* line 179 */
int Com_BuildPlayerProfilePath(char *path, int pathSize, const char *format, ...)
{
    va_list vargs;

    if (com_playerProfile->current.string[0] == '\0') {
        Com_Error(0, "Tried to use a player profile before it was set.  This is probably a menu bug.\n");
    }

    va_start(vargs, format);
    {
        int result;
        result = Com_BuildPlayerProfilePathInternal(path, pathSize, com_playerProfile->current.string, format, vargs);
        va_end(vargs);
        return result;
    }
}

/* line 166 */
int Com_BuildPlayerProfilePathForPlayer(char *path, int pathSize, const char *playerName, const char *format, ...)
{
    va_list vargs;
    int result;

    va_start(vargs, format);
    result = Com_BuildPlayerProfilePathInternal(path, pathSize, playerName, format, vargs);
    va_end(vargs);
    return result;
}

/* line 220 */
Bool Com_DeletePlayerProfile(const char *profileName)
{
    int dirCount;
    int found;
    char profilePath[64];
    char osPath[256];

    found = Com_PlayerProfileExists(profileName);

    if (!found) {
        return 0;
    }

    Com_BuildPlayerProfilePathForPlayer(profilePath, 64, profileName, "");

    FS_BuildOSPath(fs_basepath->current.string, fs_gamedir, profilePath, osPath);

    if (!Sys_RemoveDirTree(osPath)) {
        return 0;
    }

    if (I_stricmp(profileName, com_playerProfile->current.string) == 0) {
        Dvar_SetString(com_playerProfile, "");
    }

    return 1;
}

/* line 57 */
JCOEF Com_ChangePlayerProfile(const char *profileName)
{
    char cachedName[64];
    int dirCount;
    int found;
    char configFile[64];

    if (I_stricmp(profileName, com_playerProfile->current.string) == 0) {
        return 0;
    }

    I_strncpyz(cachedName, profileName, 64);

    found = Com_PlayerProfileExists(cachedName);

    if (!found) {
        return 0;
    }

    FS_WriteFile("players/active.txt", cachedName, strlen(cachedName));

    Cbuf_ExecuteText(0, "disconnect");

    Dvar_ResetDvars(0xffffffff, DVAR_SOURCE_EXTERNAL);

    Com_SetPlayerProfileAndExec(cachedName);

    Com_CheckSetRecommended();

    if (Dvar_AnyLatchedValues()) {
        Cbuf_AddText("snd_restart\n");
    }
    return 0;
}

/* line 107 */
JCOEF Com_InitPlayerProfiles(void)
{
    void *buf;
    const char *bufPtr;
    const char *profileName;
    int dirCount;
    int found;
    char configFile[64];

    ui_playerProfileAlreadyChosen = Dvar_RegisterInt("ui_playerProfileAlreadyChosen", 0, 0, 1, 0x1200);
    {
        DvarValue resetVal;
        resetVal.integer = 1;
        Dvar_ChangeResetValue(ui_playerProfileAlreadyChosen, resetVal);
    }

    com_playerProfile = Dvar_RegisterString("com_playerProfile", "", 0x1040);

    if (FS_ReadFile("players/active.txt", &buf) < 0) {
        Com_ExecStartupConfigs(0);
        return 0;
    }

    bufPtr = (const char *)buf;
    profileName = Com_Parse(&bufPtr);
    FS_FreeFile(buf);

    found = Com_PlayerProfileExists(profileName);

    if (!found) {
        Com_ExecStartupConfigs(0);
        return 0;
    }

    Com_SetPlayerProfileAndExec(profileName);
    return 0;
}

/* line 197 */
Bool Com_NewPlayerProfile(const char *profileName)
{
    int dirCount;
    int found;
    char profilePath[64];
    char osPath[256];

    found = Com_PlayerProfileExists(profileName);

    if (found) {
        Com_Printf("Profile '%s' already exists\n", profileName);
        return 0;
    }

    Com_BuildPlayerProfilePathForPlayer(profilePath, 64, profileName, "");

    FS_BuildOSPath(fs_basepath->current.string, fs_gamedir, profilePath, osPath);

    if (FS_CreatePath(osPath)) {
        Com_Printf("Unable to create new profile path: %s\n", osPath);
        return 0;
    }

    return 1;
}
