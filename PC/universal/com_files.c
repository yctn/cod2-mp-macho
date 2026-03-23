/* ASM dump from: com_files.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_files.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

extern char fs_gamedir[256]; /* 0x0 */
extern const dvar_t *fs_debug; /* 0x0 */
extern const dvar_t *fs_homepath; /* 0x0 */
extern const dvar_t *fs_basepath; /* 0x0 */
extern const dvar_t *fs_basegame; /* 0x0 */
extern const dvar_t *fs_cdpath; /* 0x0 */
extern const dvar_t *fs_copyfiles; /* 0x0 */
extern const dvar_t *fs_gameDirVar; /* 0x0 */
extern const dvar_t *fs_restrict; /* 0x0 */
extern searchpath_t *fs_searchpaths; /* 0x0 */
extern int fs_loadStack; /* 0x0 */
extern int fs_packFiles; /* 0x0 */
extern int fs_fakeChkSum; /* 0x0 */
extern int fs_checksumFeed; /* 0x0 */
extern fileHandleData_t fsh[74]; /* 0x0 */
extern int fs_numServerIwds; /* 0x0 */
extern int fs_serverIwds[1024]; /* 0x0 */
extern char * fs_serverIwdNames[1024]; /* 0x0 */
extern int fs_numServerReferencedIwds; /* 0x0 */
extern int fs_serverReferencedIwds[1024]; /* 0x0 */
extern char * fs_serverReferencedIwdNames[1024]; /* 0x0 */
extern int com_fileAccessed; /* 0x0 */
extern const dvar_t *fs_useOldAssets; /* 0x0 */
extern const dvar_t *fs_ignoreLocalized; /* 0x0 */
extern char lastValidBase[256]; /* 0x0 */
extern char lastValidGame[256]; /* 0x0 */
static char szIwdLanguageName[2][64]; /* szIwdLanguageName */
static int iString; /* iString */
extern void Hunk_FreeTempMemory(void *buf);
extern float FS_DisplayPath(qboolean bLanguageCull);
extern int SEH_GetCurrentLanguage(void);
extern const char *Dvar_GetString(const char *name);
extern const char *va(const char *fmt, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern void Z_FreeInternal(void *ptr);
extern const dvar_t *Dvar_RegisterInt(const char *dvarName, int value, int min, int max, unsigned short flags);
extern const dvar_t *Dvar_RegisterBool_mac(const char *dvarName, int value, unsigned short flags);
extern const dvar_t *Dvar_RegisterString_mac(const char *dvarName, const char *value, unsigned short flags);
extern const char *Sys_DefaultCDPath(void);
extern const char *Sys_DefaultInstallPath(void);
extern const char *Sys_DefaultHomePath(void);
extern void Com_Printf(const char *fmt, ...);

static qboolean bLanguagesListed; /* bLanguagesListed */

qboolean FS_Initialized(void);
float FS_CheckFileSystemStarted(void);
int FS_LoadStack(void);
qboolean FS_UseSearchPath(const searchpath_t *pSearch);
qboolean FS_LanguageHasAssets(int iLanguage);
long int FS_HashFileName(const char *fname, int hashSize);
fileHandle_t FS_HandleForFile(qboolean streamThread);
FILE * FS_FileForHandle(fileHandle_t f);
qboolean FS_CreatePath(char *OSPath);
float FS_Remove(const char *osPath);
qboolean FS_FilenameCompare(const char *s1, const char *s2);
qboolean FS_PureIgnoresExtension(const char *extension);
float FS_ResetFiles(void);
float FS_ConvertPath(char *s);
float FS_ShutdownServerIwdNames(void);
float FS_ShutdownServerReferencedIwds(void);
Bool FS_RegisterDvars(void);
float FS_ClearIwdReferences(void);
const char * GetBspExtension(void);
float FS_FreeFile(float *buffer);
float FS_FreeFileList(const char * *list, int allocTrackType);
int FS_filelength(fileHandle_t f);
float FS_FCloseFile(fileHandle_t h);
float FS_Shutdown(qboolean closemfp);
int FS_Read(float *buffer, int len, fileHandle_t h);
int FS_Write(const float *buffer, int len, fileHandle_t h);
int FS_Seek(fileHandle_t f, long int offset, int origin);
int FS_FTell(fileHandle_t f);
float FS_Flush(fileHandle_t f);
static Bool __attribute_regparm__(3) FS_SanitizeFilename(const char *filename, char *sanitizedName, unsigned int sanitizedNameSize);
static float __attribute_regparm__(3) FS_BuildOSPath_Internal(const char *base, const char *game, const char *qpath, char *ospath, qboolean streamThread);
float FS_BuildOSPath(const char *base, const char *game, const char *qpath, char *ospath);
qboolean FS_FileExists(const char *file);
const char * FS_ShortOSFilePath(const char *filename);
int FS_GetFileOsPath(const char *filename, char *ospath);
float FS_DisplayPath(qboolean bLanguageCull);
float FS_Path_f(void);
float FS_FullPath_f(void);
float FS_Printf(fileHandle_t h, const char *fmt);
const char * * FS_ListFilteredFiles(searchpath_t *searchPath, const char *path, const char *extension, const char *filter, FsListBehavior behavior, int *numfiles, int allocTrackType);
const char * * FS_ListFiles(const char *path, const char *extension, FsListBehavior behavior, int *numfiles, int allocTrackType);
int FS_GetFileList(const char *path, const char *extension, FsListBehavior behavior, char *listbuf, int bufsize);
float FS_SortFileList(const char * *filelist, int numfiles);
fileHandle_t FS_OpenFileOverwrite(const char *qpath);
static int iwdsort(const float *a, const float *b);
static float FS_AddIwdFilesForGameDirectory(const char *path, const char *pszGameFolder);
static float FS_AddGameDirectory(int iLanguage);
float FS_CopyFile(char *fromOSPath, char *toOSPath);
static int FS_FOpenFileRead_Internal(const char *filename, fileHandle_t *file, qboolean uniqueFILE, qboolean streamThread, qboolean fsOnly);
int FS_FOpenFileRead(const char *filename, fileHandle_t *file, qboolean uniqueFILE);
int FS_FOpenFileReadStream(const char *filename, fileHandle_t *file, qboolean uniqueFILE);
qboolean FS_TouchFile(const char *name);
int FS_ReadFile(const char *qpath, float * *buffer);
fileHandle_t FS_FOpenFileWrite(const char *filename);
qboolean FS_WriteFile(const char *qpath, const float *buffer, int size);
fileHandle_t FS_FOpenTextFileWrite(const char *filename);
fileHandle_t FS_FOpenFileAppend(const char *filename);
int FS_FOpenFileByMode(const char *qpath, fileHandle_t *f, fsMode_t mode);
float FS_Startup(const char *gameName);
float FS_Restart(int checksumFeed);
qboolean FS_ConditionalRestart(int checksumFeed);
float FS_InitFilesystem(void);

/* line 319 */
qboolean FS_Initialized(void)
{
    return fs_searchpaths != 0;
}

/* line 336 */
float FS_CheckFileSystemStarted(void)
{
}

/* line 398 */
int FS_LoadStack(void)
{
    return fs_loadStack;
}

/* line 415 */
qboolean FS_UseSearchPath(const searchpath_t *pSearch)
{
    if (!pSearch->bLocalized)
        return 1;

    if (fs_ignoreLocalized->current.enabled)
        return 0;

    if (pSearch->language != SEH_GetCurrentLanguage())
        return 0;

    return 1;
}

/* line 436 */
qboolean FS_LanguageHasAssets(int iLanguage)
{
    searchpath_t *sp;
    for (sp = fs_searchpaths; sp; sp = (searchpath_t *)(uintptr_t)sp->next) {
        if (sp->bLocalized && sp->language == iLanguage)
            return 1;
    }
    return 0;
}

/* line 459 */
extern int ___tolower(int c);
long int FS_HashFileName(const char *fname, int hashSize)
{
    int hash, i, letter;

    hash = 0;
    i = 119;
    while (*fname) {
        letter = ___tolower((signed char)*fname);
        if (letter == '.')
            break;
        if (letter == '\\')
            letter = '/';
        hash += letter * i;
        i++;
        fname++;
    }

    hash ^= (hash >> 10);
    return ((hash >> 20) ^ hash) & (hashSize - 1);
}

/* line 497 */
fileHandle_t FS_HandleForFile(qboolean streamThread) {
    int first, count, i;

    if (streamThread) {
        first = 61;
        count = 13;
    } else {
        first = 1;
        count = 60;
    }

    if (!*(int *)((byte *)&fsh[first])) {
        return first;
    }

    for (i = 1; i < count; i++) {
        if (!*(int *)((byte *)&fsh[first + i])) {
            return first + i;
        }
    }

    for (i = 1; i < 74; i++) {
        Com_Printf((const char *)"FILE %2i: '%s'\n", i, (byte *)fsh + i * 0x11c + 28);
    }
    Com_Error(1, (const char *)"\x15" "FS_HandleForFile: none free");
    return -1;
}

/* line 538 */
FILE * FS_FileForHandle(fileHandle_t f)
{
    return *(FILE **)((byte *)fsh + f * 284);
}

/* line 708 */
extern char *strstr(const char *, const char *);
extern void Sys_Mkdir(const char *path);
extern void Com_Printf(const char *fmt, ...);
qboolean FS_CreatePath(char *OSPath)
{
    char *ofs;

    /* Refuse relative paths */
    if (strstr(OSPath, "..") || strstr(OSPath, "::")) {
        Com_Printf("WARNING: refusing to create relative path \"%s\"\n", OSPath);
        return 1;
    }

    /* Create directories along the path */
    for (ofs = OSPath + 1; *ofs; ofs++) {
        if (*ofs == '/') {
            *ofs = '\0';
            Sys_Mkdir(OSPath);
            *ofs = '/';
        }
    }
    return 0;
}

/* line 796 */
float FS_Remove(const char *osPath)
{
    remove(osPath);
}

/* line 1089 */
extern Bool I_islower(int c);
qboolean FS_FilenameCompare(const char *s1, const char *s2)
{
    int c1, c2;

    do {
        c1 = (signed char)*s1++;
        c2 = (signed char)*s2++;

        if (I_islower(c1))
            c1 -= 0x20;
        if (I_islower(c2))
            c2 -= 0x20;

        /* Normalize path separators */
        if (c1 == '\\' || c1 == ':')
            c1 = '/';
        if (c2 == '\\' || c2 == ':')
            c2 = '/';

        if (c1 != c2)
            return -1;
    } while (c1);

    return 0;
}

/* line 1224 */
extern int stricmp(const char *, const char *);
extern int I_stricmp(const char *, const char *);
qboolean FS_PureIgnoresExtension(const char *extension)
{
    /* Skip leading dot */
    if (*extension == '.')
        extension++;

    if (!stricmp(extension, "cfg"))
        return 1;
    if (!I_stricmp(extension, "menu"))
        return 1;
    if (!I_stricmp(extension, "str"))
        return 1;
    if (!I_stricmp(extension, "roq"))
        return 1;
    if (!I_stricmp(extension, ".dm_NETWORK_PROTOCOL_VERSION"))
        return 1;
    return 0;
}

/* line 2167 */
float FS_ResetFiles(void)
{
    fs_loadStack = 0;
}

/* line 2900 */
float FS_ConvertPath(char *s)
{
    while (*s) {
        if (*s == '\\' || *s == ':')
            *s = '/';
        s++;
    }
}

/* line 3447 */
float FS_ShutdownServerIwdNames(void)
{
    int i;
    for (i = 0; i < fs_numServerIwds; i++) {
        if (fs_serverIwdNames[i])
            Z_FreeInternal(fs_serverIwdNames[i]);
        fs_serverIwdNames[i] = 0;
    }
    fs_numServerIwds = 0;
}

/* line 3469 */
float FS_ShutdownServerReferencedIwds(void)
{
    int i;
    for (i = 0; i < fs_numServerReferencedIwds; i++) {
        if (fs_serverReferencedIwdNames[i])
            Z_FreeInternal(fs_serverReferencedIwdNames[i]);
        fs_serverReferencedIwdNames[i] = 0;
    }
    fs_numServerReferencedIwds = 0;
}

/* line 3544 */
Bool FS_RegisterDvars(void) {
    const char *homePath;

    if (fs_debug)
        return 0;

    fs_debug = Dvar_RegisterInt("fs_debug", 0, 0, 2, 0x1000);
    fs_copyfiles = Dvar_RegisterBool_mac("fs_copyfiles", 0, 0x1010);
    fs_cdpath = Dvar_RegisterString_mac("fs_cdpath", Sys_DefaultCDPath(), 0x1010);
    fs_basepath = Dvar_RegisterString_mac("fs_basepath", Sys_DefaultInstallPath(), 0x1010);
    fs_basegame = Dvar_RegisterString_mac("fs_basegame", (const char *)"", 0x1010);
    fs_useOldAssets = Dvar_RegisterBool_mac("fs_useOldAssets", 0, 0x1000);

    homePath = Sys_DefaultHomePath();
    if (!homePath || !homePath[0]) {
        homePath = *(const char **)(*(byte **)&fs_basepath + 8);
    }

    fs_homepath = Dvar_RegisterString_mac("fs_homepath", homePath, 0x1010);
    fs_gameDirVar = Dvar_RegisterString_mac("fs_game", (const char *)"", 0x101c);
    fs_restrict = Dvar_RegisterBool_mac("fs_restrict", 0, 0x1010);
    fs_ignoreLocalized = Dvar_RegisterBool_mac("fs_ignoreLocalized", 0, 0x10a0);

    return 1;
}

/* line 3726 */
float FS_ClearIwdReferences(void)
{
    byte *search;

    for (search = (byte *)fs_searchpaths; search; search = *(byte **)search) {
        pack_t *pack = *(pack_t **)(search + 4);
        if (pack)
            pack->referenced = 0;
    }
}

/* line 4057 */
const char * GetBspExtension(void)
{
    const char *ext = Dvar_GetString((const char *)"gfx_driver");
    if (*ext)
        return va("%sbsp", ext);
    return va((const char *)"d3dbsp");
}

/* line 2180 */
float FS_FreeFile(float *buffer)
{
    fs_loadStack--;
    Hunk_FreeTempMemory(buffer);
}

/* line 2829 */
float FS_FreeFileList(const char **list, int allocTrackType)
{
    if (!list)
        return 0;

    const char **p;
    for (p = list; *p; p++) {
        Z_FreeInternal((void *)*p);
    }
    Z_FreeInternal((void *)list);
    return 0;
}

/* line 572 */
extern void FS_FileSeek(void *stream, int offset, int origin);
int FS_filelength(fileHandle_t f)
{
    byte *entry = (byte *)fsh + f * 284;
    void *h;
    int pos, end;

    /* If zipfile, return stored size */
    if (*(int *)(entry + 20))
        return *(int *)(*(byte **)entry + 0x44); /* directory entry size at 0x44 */

    /* Otherwise seek to end and back */
    h = *(void **)entry;
    pos = ftell(h);
    FS_FileSeek(h, 0, 2);
    end = ftell(h);
    FS_FileSeek(h, pos, 0);
    return end;
}

/* line 884 */
extern void FS_FileClose(int handle);
extern void Sys_EndStreamedFile(fileHandle_t h);
extern void unzCloseCurrentFile(void *file);
extern void unzClose(void *file);
extern void Com_Memset(void *dest, int val, int count);
float FS_FCloseFile(fileHandle_t h)
{
    byte *entry = (byte *)fsh + h * 284;

    /* End streaming if active */
    if (*(int *)(entry + 24))
        Sys_EndStreamedFile(h);

    if (*(int *)(entry + 20)) {
        /* Zip file entry */
        unzCloseCurrentFile(*(void **)entry);
        if (*(int *)(entry + 4)) {
            /* Owned zip handle - close the entire zip */
            unzClose(*(void **)entry);
        }
    } else if (h) {
        /* Regular file */
        FS_FileClose(*(int *)entry);
    }

    Com_Memset(entry, 0, 0x11c);
}

/* line 3494 */
float FS_Shutdown(qboolean closemfp) { return 0.0f; }
