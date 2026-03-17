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
    if (!*(int *)((byte *)pSearch + 0xc))
        return 1;

    if (*(byte *)((byte *)fs_ignoreLocalized + 8))
        return 0;

    if (*(int *)((byte *)pSearch + 0x10) != SEH_GetCurrentLanguage())
        return 0;

    return 1;
}

/* line 436 */
qboolean FS_LanguageHasAssets(int iLanguage)
{
    searchpath_t *sp;
    for (sp = fs_searchpaths; sp; sp = *(searchpath_t **)sp) {
        if (*(int *)((byte *)sp + 0xc) && *(int *)((byte *)sp + 0x10) == iLanguage)
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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
fileHandle_t FS_HandleForFile(qboolean streamThread)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 497 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %esi\n" /* line 503 | streamThread, first */
        "testl %esi, %esi\n" /* first */
        "je .Lf32ed8_00032f33\n"
        "movl $0x3d, %esi\n" /* first */
        "movl $0xd, %edi\n" /* count */
        "leal (%esi, %esi, 8), %eax\n" /* line 516 | first */
        "shll $3, %eax\n"
        "subl %esi, %eax\n" /* first */
        "shll $2, %eax\n"
        "movl fsh(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf32ed8_00032f52\n"
        ".Lf32ed8_00032f07:\n"
        "leal fsh(%eax), %ecx\n" /* line 526 */
        "xorl %edx, %edx\n"
        ".Lf32ed8_00032f0f:\n"
        "addl $1, %edx\n" /* line 514 */
        "cmpl %edx, %edi\n" /* count */
        "je .Lf32ed8_00032f5e\n"
        "leal (%edx, %esi), %ebx\n" /* line 516 */
        "movl 0x11c(%ecx), %eax\n"
        "addl $0x11c, %ecx\n"
        "testl %eax, %eax\n"
        "jne .Lf32ed8_00032f0f\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 528 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf32ed8_00032f33:\n"
        "movl $1, %esi\n" /* line 503 | first */
        "movl $0x3c, %edi\n" /* count */
        "leal (%esi, %esi, 8), %eax\n" /* line 516 | first */
        "shll $3, %eax\n"
        "subl %esi, %eax\n" /* first */
        "shll $2, %eax\n"
        "movl fsh(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf32ed8_00032f07\n"
        ".Lf32ed8_00032f52:\n"
        "movl %esi, %ebx\n" /* first */
        /* } scope */
        "movl %ebx, %eax\n" /* line 528 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf32ed8_00032f5e:\n"
        "movl $1, %ebx\n" /* line 514 */
        "movl $fsh+312, %esi\n" /* first */
        ".Lf32ed8_00032f68:\n"
        "movl %esi, 8(%esp)\n" /* line 524 | first */
        "movl %ebx, 4(%esp)\n"
        "movl $str_00216c70, (%esp)\n" /* "FILE %2i: '%s'
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 523 */
        "addl $0x11c, %esi\n" /* first */
        "cmpl $0x4a, %ebx\n"
        "jne .Lf32ed8_00032f68\n"
        "movl $str_00216c80, 4(%esp)\n" /* line 526 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0xffffffff, %ebx\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 528 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
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
        Com_Printf((const char *)str_00216c70, i, (byte *)fsh + i * 0x11c + 28);
    }
    Com_Error(1, (const char *)str_00216c80);
    return -1;
}
#endif

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
    if (strstr(OSPath, str_00216ca0) || strstr(OSPath, str_00215bf8)) {
        Com_Printf(str_00216ca4, OSPath);
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

    if (!stricmp(extension, str_00216cd4))
        return 1;
    if (!I_stricmp(extension, str_00216cd8))
        return 1;
    if (!I_stricmp(extension, str_00216ce0))
        return 1;
    if (!I_stricmp(extension, str_00216ce4))
        return 1;
    if (!I_stricmp(extension, str_00216ce8))
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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
Bool FS_RegisterDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3544 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "movl fs_debug, %eax\n" /* line 3549 */
        "testl %eax, %eax\n"
        "je .Lf33246_00033259\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 3601 */
        "retl\n"
        /* { scope 1 */
        ".Lf33246_00033259:\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 3552 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_00216d08, (%esp)\n" /* "fs_debug" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, fs_debug\n"
        "movl $0x1010, 8(%esp)\n" /* line 3556 */
        "movl $0, 4(%esp)\n"
        "movl $str_00216d14, (%esp)\n" /* "fs_copyfiles" */
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, fs_copyfiles\n"
        "calll Sys_DefaultCDPath\n" /* line 3560 */
        "movl $0x1010, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00216d24, (%esp)\n" /* "fs_cdpath" */
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, fs_cdpath\n"
        "calll Sys_DefaultInstallPath\n" /* line 3564 */
        "movl $0x1010, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00216d30, (%esp)\n" /* "fs_basepath" */
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, fs_basepath\n"
        "movl $0x1010, 8(%esp)\n" /* line 3568 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_00216d3c, (%esp)\n" /* "fs_basegame" */
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, fs_basegame\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 3572 */
        "movl $0, 4(%esp)\n"
        "movl $str_00216d48, (%esp)\n" /* "fs_useOldAssets" */
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, fs_useOldAssets\n"
        "calll Sys_DefaultHomePath\n" /* line 3575 */
        "testl %eax, %eax\n" /* line 3576 */
        "je .Lf33246_0003333f\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf33246_00033347\n"
        ".Lf33246_0003333f:\n"
        "movl fs_basepath, %eax\n" /* line 3577 */
        "movl 8(%eax), %eax\n"
        ".Lf33246_00033347:\n"
        "movl $0x1010, 8(%esp)\n" /* line 3580 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00216d58, (%esp)\n" /* "fs_homepath" */
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, fs_homepath\n"
        "movl $0x101c, 8(%esp)\n" /* line 3584 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_00216d64, (%esp)\n" /* "fs_game" */
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, fs_gameDirVar\n"
        "movl $0x1010, 8(%esp)\n" /* line 3589 */
        "movl $0, 4(%esp)\n"
        "movl $str_00216d6c, (%esp)\n" /* "fs_restrict" */
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, fs_restrict\n"
        "movl $0x10a0, 8(%esp)\n" /* line 3594 */
        "movl $0, 4(%esp)\n"
        "movl $str_00216d78, (%esp)\n" /* "fs_ignoreLocalized" */
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, fs_ignoreLocalized\n"
        "movl $1, %eax\n"
        /* } scope */
        "leave\n" /* line 3601 */
        "retl\n"
    );
}
#else
Bool FS_RegisterDvars(void) {
    const char *homePath;

    if (fs_debug)
        return 0;

    fs_debug = Dvar_RegisterInt(str_00216d08, 0, 0, 2, 0x1000);
    fs_copyfiles = Dvar_RegisterBool_mac(str_00216d14, 0, 0x1010);
    fs_cdpath = Dvar_RegisterString_mac(str_00216d24, Sys_DefaultCDPath(), 0x1010);
    fs_basepath = Dvar_RegisterString_mac(str_00216d30, Sys_DefaultInstallPath(), 0x1010);
    fs_basegame = Dvar_RegisterString_mac(str_00216d3c, (const char *)str_002157b8, 0x1010);
    fs_useOldAssets = Dvar_RegisterBool_mac(str_00216d48, 0, 0x1000);

    homePath = Sys_DefaultHomePath();
    if (!homePath || !homePath[0]) {
        homePath = *(const char **)(*(byte **)&fs_basepath + 8);
    }

    fs_homepath = Dvar_RegisterString_mac(str_00216d58, homePath, 0x1010);
    fs_gameDirVar = Dvar_RegisterString_mac(str_00216d64, (const char *)str_002157b8, 0x101c);
    fs_restrict = Dvar_RegisterBool_mac(str_00216d6c, 0, 0x1010);
    fs_ignoreLocalized = Dvar_RegisterBool_mac(str_00216d78, 0, 0x10a0);

    return 1;
}
#endif

/* line 3726 */
float FS_ClearIwdReferences(void)
{
    byte *search;

    for (search = (byte *)fs_searchpaths; search; search = *(byte **)search) {
        byte *pack = *(byte **)(search + 4);
        if (pack)
            *(byte *)(pack + 0x310) = 0;
    }
}

/* line 4057 */
const char * GetBspExtension(void)
{
    const char *ext = Dvar_GetString((const char *)str_00216d8c);
    if (*ext)
        return va("%sbsp", ext);
    return va((const char *)str_00216da0);
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
        return *(int *)(*(byte **)entry + 0x44);

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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
float FS_Shutdown(qboolean closemfp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3494 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $8, (%esp)\n" /* line 3500 */
        "calll SND_StopSounds\n"
        "calll SEH_Shutdown_StringEd\n" /* line 3507 */
        "movl $1, %esi\n" /* i */
        "movl $fsh, %ebx\n"
        "jmp .Lf335d4_00033607\n"
        ".Lf335d4_000335f9:\n"
        "addl $1, %esi\n" /* line 3513 | i */
        "addl $0x11c, %ebx\n"
        "cmpl $0x4a, %esi\n" /* i */
        "je .Lf335d4_00033627\n"
        ".Lf335d4_00033607:\n"
        "movl 0x128(%ebx), %eax\n" /* line 3515 */
        "testl %eax, %eax\n"
        "je .Lf335d4_000335f9\n"
        "movl %esi, (%esp)\n" /* line 3516 | i */
        "calll FS_FCloseFile\n"
        "addl $1, %esi\n" /* line 3513 | i */
        "addl $0x11c, %ebx\n"
        "cmpl $0x4a, %esi\n" /* i */
        "jne .Lf335d4_00033607\n"
        ".Lf335d4_00033627:\n"
        "movl fs_searchpaths, %ebx\n" /* line 3519 | p */
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 3420 */
        "jne .Lf335d4_00033635\n"
        "jmp .Lf335d4_00033683\n"
        ".Lf335d4_00033633:\n"
        "movl %esi, %ebx\n"
        ".Lf335d4_00033635:\n"
        "movl (%ebx), %esi\n" /* line 3422 */
        "movl 4(%ebx), %eax\n" /* line 3424 */
        "testl %eax, %eax\n"
        "je .Lf335d4_00033668\n"
        "movl 0x300(%eax), %eax\n" /* line 3426 */
        "movl %eax, (%esp)\n"
        "calll unzClose\n"
        "movl 4(%ebx), %eax\n" /* line 3427 */
        "movl 0x31c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl 4(%ebx), %eax\n" /* line 3428 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        ".Lf335d4_00033668:\n"
        "movl 8(%ebx), %eax\n" /* line 3430 */
        "testl %eax, %eax\n"
        "je .Lf335d4_00033677\n"
        "movl %eax, (%esp)\n" /* line 3432 */
        "calll Z_FreeInternal\n"
        ".Lf335d4_00033677:\n"
        "movl %ebx, (%esp)\n" /* line 3434 */
        "calll Z_FreeInternal\n"
        "testl %esi, %esi\n" /* line 3420 */
        "jne .Lf335d4_00033633\n"
        /* } scope */
        ".Lf335d4_00033683:\n"
        "movl $0, fs_searchpaths\n" /* line 3522 */
        "movl $str_00216da8, (%esp)\n" /* line 3525 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_00216db0, (%esp)\n" /* line 3526 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_00216dbc, (%esp)\n" /* line 3527 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_00216dc0, (%esp)\n" /* line 3528 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_00216dc8, 8(%ebp)\n" /* line 3529 | closemfp */
        /* } scope */
        "addl $0x10, %esp\n" /* line 3536 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Cmd_RemoveCommand\n" /* line 3529 */
    );
}

/* line 1827 */
__attribute__((naked))
int FS_Read(float *buffer, int len, fileHandle_t h)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1827 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* buffer */
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, -0x28(%ebp)\n" /* len */
        "movl 0x10(%ebp), %edx\n" /* h */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 1838 */
        "je .Lf336d0_00033739\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 1842 */
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "movl fsh+20(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf336d0_0003371c\n"
        "movl -0x28(%ebp), %edx\n" /* line 1844 | len */
        "movl %edx, 0x10(%ebp)\n" /* h */
        "movl %ecx, 0xc(%ebp)\n" /* len */
        "movl fsh(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* buffer */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1886 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp unzReadCurrentFile\n" /* line 1844 */
        ".Lf336d0_0003371c:\n"
        "movl fsh(%eax), %eax\n" /* line 544 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        "movl %ecx, %edi\n" /* line 1851 | buf */
        "movl -0x28(%ebp), %eax\n" /* line 1855 | len */
        "testl %eax, %eax\n"
        "jne .Lf336d0_00033743\n"
        ".Lf336d0_0003372e:\n"
        "movl -0x28(%ebp), %eax\n" /* len */
        /* } scope */
        ".Lf336d0_00033731:\n"
        "addl $0x2c, %esp\n" /* line 1886 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf336d0_00033739:\n"
        "xorl %eax, %eax\n" /* line 1855 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1886 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf336d0_00033743:\n"
        "subl $0x3d, %edx\n" /* line 1876 */
        "movl %edx, -0x24(%ebp)\n"
        "movl -0x28(%ebp), %esi\n" /* len, remaining */
        "movl $0, -0x20(%ebp)\n" /* tries */
        "jmp .Lf336d0_00033769\n"
        ".Lf336d0_00033755:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1863 | tries */
        "testl %eax, %eax\n"
        "jne .Lf336d0_000337ab\n"
        "movl $1, -0x20(%ebp)\n" /* line 1869 | tries */
        ".Lf336d0_00033763:\n"
        "addl %ebx, %edi\n" /* line 1883 | buf */
        "subl %ebx, %esi\n" /* line 1855 | remaining */
        "je .Lf336d0_0003372e\n"
        ".Lf336d0_00033769:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1858 | f */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* remaining */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* buf */
        "calll FS_FileRead\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 1859 */
        "je .Lf336d0_00033755\n"
        "cmpl $-1, %eax\n" /* line 1873 */
        "jne .Lf336d0_00033763\n"
        "cmpl $0xc, -0x24(%ebp)\n" /* line 1876 */
        "jbe .Lf336d0_000337b5\n"
        "movl $str_00216dd4, 4(%esp)\n" /* line 1879 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf336d0_00033763\n"
        ".Lf336d0_000337ab:\n"
        "movl -0x28(%ebp), %eax\n" /* line 1869 | len */
        "subl %esi, %eax\n" /* remaining */
        "jmp .Lf336d0_00033731\n"
        ".Lf336d0_000337b5:\n"
        "movl $0xffffffff, %eax\n" /* line 1876 */
        "jmp .Lf336d0_00033731\n"
    );
}

/* line 1896 */
__attribute__((naked))
int FS_Write(const float *buffer, int len, fileHandle_t h)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1896 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* h */
        /* { scope 1 */
        "testl %edi, %edi\n" /* line 1908 | h */
        "je .Lf337c0_00033868\n"
        "leal (%edi, %edi, 8), %eax\n" /* line 544 */
        "shll $3, %eax\n"
        "subl %edi, %eax\n"
        "movl fsh(, %eax, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        "movl 8(%ebp), %esi\n" /* line 1912 | buffer, buf */
        "movl 0xc(%ebp), %ecx\n" /* line 1916 | len */
        "testl %ecx, %ecx\n"
        "jne .Lf337c0_00033824\n"
        ".Lf337c0_000337f0:\n"
        "leal (%edi, %edi, 8), %eax\n" /* line 1936 | h */
        "shll $3, %eax\n"
        "subl %edi, %eax\n" /* h */
        "movl fsh+8(, %eax, 4), %esi\n" /* buf */
        "testl %esi, %esi\n" /* buf */
        "jne .Lf337c0_0003380e\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 1944 | len */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf337c0_0003380e:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1938 | f */
        "movl %eax, (%esp)\n"
        "calll fflush\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 1944 | len */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf337c0_00033824:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1916 | len, remaining */
        "movl $0, -0x20(%ebp)\n" /* tries */
        "jmp .Lf337c0_00033844\n"
        ".Lf337c0_00033830:\n"
        "movl -0x20(%ebp), %edx\n" /* line 1922 | tries */
        "testl %edx, %edx\n"
        "jne .Lf337c0_00033868\n"
        "movl $1, -0x20(%ebp)\n" /* tries */
        ".Lf337c0_0003383e:\n"
        "addl %eax, %esi\n" /* line 1932 | buf */
        "subl %eax, %ebx\n" /* line 1916 | remaining */
        "je .Lf337c0_000337f0\n"
        ".Lf337c0_00033844:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1919 | f */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* remaining */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* buf */
        "calll FS_FileWrite\n"
        "testl %eax, %eax\n" /* line 1920 */
        "je .Lf337c0_00033830\n"
        "cmpl $-1, %eax\n" /* line 1928 */
        "jne .Lf337c0_0003383e\n"
        ".Lf337c0_00033868:\n"
        "movl $0, 0xc(%ebp)\n" /* line 1938 | len */
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 1944 | len */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1970 */
__attribute__((naked))
int FS_Seek(fileHandle_t f, long int offset, int origin)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1970 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* f */
        "movl 0xc(%ebp), %eax\n" /* offset */
        "movl %eax, -0x20(%ebp)\n" /* offset */
        "movl 0x10(%ebp), %esi\n" /* origin */
        /* { scope 1 */
        "leal (%edi, %edi, 8), %eax\n" /* line 1982 | f */
        "shll $3, %eax\n"
        "subl %edi, %eax\n" /* f */
        "leal (, %eax, 4), %ebx\n"
        "movl fsh+24(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf3387a_00033966\n"
        "movl fsh+20(%ebx), %eax\n" /* line 1990 */
        "testl %eax, %eax\n"
        "je .Lf3387a_0003399b\n"
        ".Lf3387a_000338ba:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1992 | offset */
        "testl %eax, %eax\n"
        "jne .Lf3387a_000338d2\n"
        "cmpl $2, %esi\n" /* origin */
        "je .Lf3387a_000339f4\n"
        "testl %esi, %esi\n" /* line 1998 | origin */
        "je .Lf3387a_0003395c\n"
        ".Lf3387a_000338d2:\n"
        "leal (%edi, %edi, 8), %eax\n" /* line 2005 | f */
        "shll $3, %eax\n"
        "subl %edi, %eax\n" /* f */
        "leal (, %eax, 4), %ebx\n"
        "movl fsh(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll unztell\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %esi, %esi\n" /* line 2007 | origin */
        "je .Lf3387a_00033923\n"
        "cmpl $1, %esi\n" /* line 2023 | origin */
        "jne .Lf3387a_00033a21\n"
        "movl %edi, (%esp)\n" /* line 2025 | f */
        "calll FS_filelength\n"
        "addl -0x20(%ebp), %eax\n" /* offset */
        "cmpl %eax, -0x1c(%ebp)\n"
        "jg .Lf3387a_000339be\n"
        "movl %edi, (%esp)\n" /* line 2034 | f */
        "calll FS_filelength\n"
        "addl -0x20(%ebp), %eax\n" /* offset */
        "subl -0x1c(%ebp), %eax\n"
        "jmp .Lf3387a_00033931\n"
        ".Lf3387a_00033923:\n"
        "movl -0x20(%ebp), %esi\n" /* line 2011 | offset, origin */
        "testl %esi, %esi\n" /* origin */
        "js .Lf3387a_00033a4d\n"
        ".Lf3387a_0003392e:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2042 | offset */
        ".Lf3387a_00033931:\n"
        "movl %eax, 8(%esp)\n" /* line 2057 */
        "movl $0, 4(%esp)\n"
        "leal (%edi, %edi, 8), %eax\n" /* f */
        "shll $3, %eax\n"
        "subl %edi, %eax\n" /* f */
        "movl fsh(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll unzReadCurrentFile\n"
        "testl %eax, %eax\n" /* line 2058 */
        "je .Lf3387a_00033a26\n"
        /* { scope 2 */
        ".Lf3387a_0003395c:\n"
        "xorl %eax, %eax\n" /* line 2087 */
        /* } scope */
        /* } scope */
        ".Lf3387a_0003395e:\n"
        "addl $0x2c, %esp\n" /* line 2089 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3387a_00033966:\n"
        "movl $0, fsh+24(%ebx)\n" /* line 1984 */
        "movl %esi, 8(%esp)\n" /* line 1985 | origin */
        "movl -0x20(%ebp), %edx\n" /* offset */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* f */
        "calll Sys_StreamSeek\n"
        "movl $1, fsh+24(%ebx)\n" /* line 1986 */
        "movl fsh+20(%ebx), %eax\n" /* line 1990 */
        "testl %eax, %eax\n"
        "jne .Lf3387a_000338ba\n"
        /* { scope 2 */
        ".Lf3387a_0003399b:\n"
        "movl fsh(%ebx), %eax\n" /* line 544 */
        "cmpl $1, %esi\n" /* line 2072 | origin */
        "je .Lf3387a_00033a30\n"
        "cmpl $2, %esi\n" /* origin */
        "je .Lf3387a_00033a91\n"
        "testl %esi, %esi\n" /* origin */
        "jne .Lf3387a_0003395c\n"
        "movl $1, %edx\n"
        "jmp .Lf3387a_00033a35\n"
        /* } scope */
        ".Lf3387a_000339be:\n"
        "movl fsh+16(%ebx), %eax\n" /* line 2027 */
        "movl %eax, 4(%esp)\n"
        "movl fsh(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll unzSetCurrentFileInfoPosition\n"
        "movl fsh(%ebx), %eax\n" /* line 2028 */
        "movl %eax, (%esp)\n"
        "calll unzOpenCurrentFile\n"
        "movl %edi, (%esp)\n" /* line 2030 | f */
        "calll FS_filelength\n"
        "addl -0x20(%ebp), %eax\n" /* offset */
        "jmp .Lf3387a_00033931\n"
        ".Lf3387a_000339f4:\n"
        "movl fsh+16(%ebx), %eax\n" /* line 1995 */
        "movl %eax, 4(%esp)\n"
        "movl fsh(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll unzSetCurrentFileInfoPosition\n"
        "movl fsh(%ebx), %eax\n" /* line 1996 */
        "movl %eax, 8(%ebp)\n" /* f */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2089 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp unzOpenCurrentFile\n" /* line 1996 */
        ".Lf3387a_00033a21:\n"
        "cmpl $2, %esi\n" /* line 2037 | origin */
        "je .Lf3387a_00033a7e\n"
        ".Lf3387a_00033a26:\n"
        "movl $0xffffffff, %eax\n" /* line 2058 */
        "jmp .Lf3387a_0003395e\n"
        /* { scope 2 */
        ".Lf3387a_00033a30:\n"
        "movl $2, %edx\n" /* line 2072 */
        ".Lf3387a_00033a35:\n"
        "movl %edx, 0x10(%ebp)\n" /* line 2087 | origin */
        "movl -0x20(%ebp), %edx\n" /* offset */
        "movl %edx, 0xc(%ebp)\n" /* offset */
        "movl %eax, 8(%ebp)\n" /* f */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2089 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp FS_FileSeek\n" /* line 2087 */
        /* } scope */
        ".Lf3387a_00033a4d:\n"
        "movl fsh+16(%ebx), %eax\n" /* line 2013 */
        "movl %eax, 4(%esp)\n"
        "movl fsh(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll unzSetCurrentFileInfoPosition\n"
        "movl fsh(%ebx), %eax\n" /* line 2014 */
        "movl %eax, (%esp)\n"
        "calll unzOpenCurrentFile\n"
        "movl -0x20(%ebp), %eax\n" /* line 2016 | offset */
        "addl -0x1c(%ebp), %eax\n"
        "jmp .Lf3387a_00033931\n"
        ".Lf3387a_00033a7e:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2039 */
        "cmpl %eax, -0x20(%ebp)\n" /* offset */
        "jl .Lf3387a_00033a95\n"
        "movl -0x20(%ebp), %eax\n" /* line 2048 | offset */
        "subl -0x1c(%ebp), %eax\n"
        "jmp .Lf3387a_00033931\n"
        /* { scope 2 */
        ".Lf3387a_00033a91:\n"
        "xorl %edx, %edx\n" /* line 2072 */
        "jmp .Lf3387a_00033a35\n"
        /* } scope */
        ".Lf3387a_00033a95:\n"
        "movl fsh+16(%ebx), %eax\n" /* line 2041 */
        "movl %eax, 4(%esp)\n"
        "movl fsh(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll unzSetCurrentFileInfoPosition\n"
        "movl fsh(%ebx), %eax\n" /* line 2042 */
        "movl %eax, (%esp)\n"
        "calll unzOpenCurrentFile\n"
        "jmp .Lf3387a_0003392e\n"
    );
}

/* line 4033 */
__attribute__((naked))
int FS_FTell(fileHandle_t f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4033 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* f */
        "leal (%edx, %edx, 8), %eax\n" /* line 4038 */
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "movl fsh+20(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf33ac0_00033aea\n"
        "movl fsh(%eax), %eax\n" /* line 4040 */
        "movl %eax, 8(%ebp)\n" /* f */
        "popl %ebp\n" /* line 4048 */
        "jmp unztell\n" /* line 4040 */
        ".Lf33ac0_00033aea:\n"
        "movl fsh(%eax), %eax\n" /* line 4045 */
        "movl %eax, 8(%ebp)\n" /* f */
        "popl %ebp\n" /* line 4048 */
        "jmp ftell\n" /* line 4045 */
    );
}

/* line 4051 */
float FS_Flush(fileHandle_t f)
{
    /* fsh stride: f*72 - f = f*71; fsh[f*71] is the FILE* */
    fflush(*(FILE **)((byte *)&fsh + f * 71 * 4));
    return 0;
}

/* line 1270 */
static __attribute_regparm__(3)
Bool __attribute_regparm__(3) FS_SanitizeFilename(const char *filename, char *sanitizedName, unsigned int sanitizedNameSize)
{
    unsigned int srcIndex = 0;
    unsigned int dstIndex = 0;
    unsigned char c;

    (void)sanitizedNameSize;

    while (filename[srcIndex] == '/' || filename[srcIndex] == '\\') {
        ++srcIndex;
    }

    if (filename[srcIndex] == '\0') {
        sanitizedName[0] = '\0';
        return 1;
    }

    while ((c = (unsigned char)filename[srcIndex]) != '\0') {
        if ((c == '.' && filename[srcIndex + 1] == '.') ||
            (c == ':' && filename[srcIndex + 1] == ':')) {
            return 0;
        }

        if (c == '.') {
            unsigned char next = (unsigned char)filename[srcIndex + 1];

            if (next == '\0' || next == '/' || next == '\\') {
                ++srcIndex;
                continue;
            }
        }

        if (c == '/' || c == '\\') {
            sanitizedName[dstIndex++] = '/';
            do {
                ++srcIndex;
                c = (unsigned char)filename[srcIndex];
            } while (c == '/' || c == '\\');
            continue;
        }

        sanitizedName[dstIndex++] = (char)c;
        ++srcIndex;
    }

    sanitizedName[dstIndex] = '\0';
    return 1;
}

/* line 652 */
static __attribute_regparm__(3)
float FS_BuildOSPath_Internal(const char *base, const char *game, const char *qpath, char *ospath, qboolean streamThread)
{
    const char *useGame;
    int lenBase;
    int lenGame;
    int lenQpath;
    const char *src;
    char *dst;
    qboolean sawSlash;

    useGame = (game && game[0]) ? game : fs_gamedir;
    lenBase = strlen(base);
    lenGame = strlen(useGame);
    lenQpath = strlen(qpath);

    if (lenBase + lenGame + lenQpath + 2 > 0xff) {
        if (streamThread) {
            ospath[0] = '\0';
            return 0;
        }
        Com_Error(0, "FS_BuildOSPath: os path length exceeded\n");
    }

    memcpy(ospath, base, lenBase);
    ospath[lenBase] = '/';
    memcpy(ospath + lenBase + 1, useGame, lenGame);
    ospath[lenBase + lenGame + 1] = '/';
    memcpy(ospath + lenBase + lenGame + 2, qpath, lenQpath + 1);

    src = ospath;
    dst = ospath;
    sawSlash = 0;

    while (*src) {
        char c = *src++;
        if (c == '\\' || c == '/' || c == ':') {
            if (sawSlash) {
                continue;
            }
            *dst++ = '/';
            sawSlash = 1;
            continue;
        }
        *dst++ = c;
        sawSlash = 0;
    }
    *dst = '\0';

    return 0;
}

/* line 695 */
float FS_BuildOSPath(const char *base, const char *game, const char *qpath, char *ospath)
{
    return FS_BuildOSPath_Internal(base, game, qpath, ospath, 0);
}

/* line 814 */
extern int FS_FileOpen(const char *path, const char *mode);
extern void FS_FileClose(int handle);
qboolean FS_FileExists(const char *file)
{
    char testpath[256];
    int handle;

    FS_BuildOSPath(fs_homepath->current.string, fs_gamedir, file, testpath);
    handle = FS_FileOpen(testpath, str_00215b98);
    if (!handle)
        return 0;
    FS_FileClose(handle);
    return 1;
}

/* line 1709 */
__attribute__((naked))
const char * FS_ShortOSFilePath(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1709 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1 */
        "movl fs_searchpaths, %esi\n" /* line 1716 | search */
        "testl %esi, %esi\n" /* search */
        "je .Lf33d84_00033e30\n"
        "leal -0x118(%ebp), %edi\n" /* netpath */
        "jmp .Lf33d84_00033db7\n"
        ".Lf33d84_00033da6:\n"
        "movl fs_ignoreLocalized, %eax\n" /* line 417 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf33d84_00033e1e\n"
        ".Lf33d84_00033db1:\n"
        "movl (%esi), %esi\n" /* line 1716 | search */
        "testl %esi, %esi\n" /* search */
        "je .Lf33d84_00033e30\n"
        ".Lf33d84_00033db7:\n"
        "movl 0xc(%esi), %ecx\n" /* line 417 */
        "testl %ecx, %ecx\n"
        "jne .Lf33d84_00033da6\n"
        ".Lf33d84_00033dbe:\n"
        "movl 8(%esi), %eax\n" /* line 1722 | search */
        "testl %eax, %eax\n"
        "je .Lf33d84_00033db1\n"
        "leal 0x100(%eax), %ebx\n" /* line 1726 */
        "movl $0, 4(%esp)\n" /* line 697 */
        "movl %edi, (%esp)\n"
        "movl 8(%ebp), %ecx\n" /* filename */
        "movl %ebx, %edx\n"
        "calll FS_BuildOSPath_Internal\n"
        "movl $str_00215b98, 4(%esp)\n" /* line 1727 */
        "movl %edi, (%esp)\n"
        "calll FS_FileOpen\n"
        "testl %eax, %eax\n" /* line 1728 */
        "je .Lf33d84_00033db1\n"
        "movl %eax, (%esp)\n" /* line 1730 */
        "calll FS_FileClose\n"
        "movl 8(%ebp), %eax\n" /* line 1731 | filename */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_00216e18, (%esp)\n" /* "%s/%s" */
        "calll va\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 1735 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf33d84_00033e1e:\n"
        "movl 0x10(%esi), %ebx\n" /* line 422 */
        "calll SEH_GetCurrentLanguage\n"
        "cmpl %eax, %ebx\n"
        "je .Lf33d84_00033dbe\n"
        "movl (%esi), %esi\n" /* line 1716 | search */
        "testl %esi, %esi\n" /* search */
        "jne .Lf33d84_00033db7\n"
        ".Lf33d84_00033e30:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 1735 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2237 */
__attribute__((naked))
int FS_GetFileOsPath(const char *filename, char *ospath)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2237 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "movl 8(%ebp), %eax\n" /* filename */
        /* { scope 1 */
        "leal -0x118(%ebp), %edi\n" /* line 2247 | sanitizedName */
        "movl $0x100, %ecx\n"
        "movl %edi, %edx\n"
        "calll FS_SanitizeFilename\n"
        "testb %al, %al\n"
        "jne .Lf33e3e_00033e73\n"
        ".Lf33e3e_00033e63:\n"
        "movl $0xffffffff, %eax\n" /* line 2254 */
        /* } scope */
        ".Lf33e3e_00033e68:\n"
        "addl $0x11c, %esp\n" /* line 2272 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf33e3e_00033e73:\n"
        "movl fs_searchpaths, %esi\n" /* line 2254 | search */
        "testl %esi, %esi\n" /* search */
        "jne .Lf33e3e_00033e90\n"
        "jmp .Lf33e3e_00033e63\n"
        ".Lf33e3e_00033e7f:\n"
        "movl fs_ignoreLocalized, %eax\n" /* line 417 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf33e3e_00033edf\n"
        ".Lf33e3e_00033e8a:\n"
        "movl (%esi), %esi\n" /* line 2254 | search */
        "testl %esi, %esi\n" /* search */
        "je .Lf33e3e_00033e63\n"
        ".Lf33e3e_00033e90:\n"
        "movl 0xc(%esi), %eax\n" /* line 417 */
        "testl %eax, %eax\n"
        "jne .Lf33e3e_00033e7f\n"
        ".Lf33e3e_00033e97:\n"
        "movl 4(%esi), %ebx\n" /* line 2259 | search */
        "testl %ebx, %ebx\n"
        "jne .Lf33e3e_00033e8a\n"
        "movl 8(%esi), %eax\n" /* line 2262 | search */
        "leal 0x100(%eax), %edx\n" /* line 2263 */
        "movl $0, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* ospath */
        "movl %ecx, (%esp)\n"
        "movl %edi, %ecx\n"
        "calll FS_BuildOSPath_Internal\n"
        "movl $str_00215b98, 4(%esp)\n" /* line 2265 */
        "movl 0xc(%ebp), %eax\n" /* ospath */
        "movl %eax, (%esp)\n"
        "calll FS_FileOpen\n"
        "testl %eax, %eax\n" /* line 2266 */
        "je .Lf33e3e_00033e8a\n"
        "movl %eax, (%esp)\n" /* line 2268 */
        "calll FS_FileClose\n"
        "xorl %eax, %eax\n"
        "jmp .Lf33e3e_00033e68\n"
        ".Lf33e3e_00033edf:\n"
        "movl 0x10(%esi), %ebx\n" /* line 422 */
        "calll SEH_GetCurrentLanguage\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf33e3e_00033e8a\n"
        "jmp .Lf33e3e_00033e97\n"
    );
}

/* line 3002 */
__attribute__((naked))
float FS_DisplayPath(qboolean bLanguageCull)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3002 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "calll SEH_GetCurrentLanguage\n" /* line 3013 */
        "movl %eax, (%esp)\n" /* line 3014 */
        "calll SEH_GetLanguageName\n"
        "movl %eax, 4(%esp)\n" /* line 3015 */
        "movl $str_00216e20, (%esp)\n" /* "Current language: %s
" */
        "calll Com_Printf\n"
        "movl fs_ignoreLocalized, %eax\n" /* line 3018 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf33eee_000340c8\n"
        ".Lf33eee_00033f23:\n"
        "movl $str_00216e60, (%esp)\n" /* line 3020 */
        "calll Com_Printf\n"
        "movl fs_searchpaths, %esi\n" /* line 3021 | s */
        "testl %esi, %esi\n" /* s */
        "jne .Lf33eee_00033f5e\n"
        "jmp .Lf33eee_00033fe5\n"
        ".Lf33eee_00033f3e:\n"
        "movl 0xc(%esi), %eax\n" /* line 417 */
        "testl %eax, %eax\n"
        "je .Lf33eee_00033f65\n"
        "movl fs_ignoreLocalized, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf33eee_000340b3\n"
        ".Lf33eee_00033f54:\n"
        "movl (%esi), %esi\n" /* line 3021 | s */
        "testl %esi, %esi\n" /* s */
        "je .Lf33eee_00033fe5\n"
        ".Lf33eee_00033f5e:\n"
        "movl 8(%ebp), %eax\n" /* line 3023 | bLanguageCull */
        "testl %eax, %eax\n"
        "jne .Lf33eee_00033f3e\n"
        ".Lf33eee_00033f65:\n"
        "movl 4(%esi), %edx\n" /* line 3026 | s */
        "testl %edx, %edx\n"
        "je .Lf33eee_0003406b\n"
        "movl 0x30c(%edx), %eax\n" /* line 3028 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_00216e78, (%esp)\n" /* "%s (%i files)
" */
        "calll Com_Printf\n"
        "movl 0xc(%esi), %eax\n" /* line 3030 | s */
        "testl %eax, %eax\n"
        "jne .Lf33eee_0003404b\n"
        ".Lf33eee_00033f95:\n"
        "movl fs_numServerIwds, %ebx\n" /* line 3035 | i */
        "cmpl $0, %ebx\n" /* i */
        "je .Lf33eee_00033f54\n"
        "movl 4(%esi), %eax\n" /* line 3037 | s, pack */
        /* { scope 2 */
        /* { scope 3 */
        "jle .Lf33eee_0003403a\n" /* line 373 */
        "movl 0x304(%eax), %edi\n" /* line 376 */
        "cmpl fs_serverIwds, %edi\n"
        "je .Lf33eee_00033fcf\n"
        "xorl %ecx, %ecx\n"
        "movl $fs_serverIwds, %edx\n"
        ".Lf33eee_00033fbe:\n"
        "addl $1, %ecx\n" /* line 373 */
        "cmpl %ecx, %ebx\n"
        "je .Lf33eee_0003403a\n"
        "movl 4(%edx), %eax\n" /* line 376 */
        "addl $4, %edx\n"
        "cmpl %eax, %edi\n"
        "jne .Lf33eee_00033fbe\n"
        /* } scope */
        /* } scope */
        ".Lf33eee_00033fcf:\n"
        "movl $str_00216eb0, (%esp)\n" /* line 3040 */
        "calll Com_Printf\n"
        "movl (%esi), %esi\n" /* line 3021 | s */
        "testl %esi, %esi\n" /* s */
        "jne .Lf33eee_00033f5e\n"
        ".Lf33eee_00033fe5:\n"
        "movl $str_00216efc, (%esp)\n" /* line 3055 */
        "calll Com_Printf\n"
        "movl $1, %ebx\n" /* i */
        "movl $fsh, %esi\n" /* s */
        "movl $fsh+312, %edi\n"
        ".Lf33eee_00034000:\n"
        "movl 0x11c(%esi), %eax\n" /* line 3058 | s */
        "testl %eax, %eax\n"
        "je .Lf33eee_0003401e\n"
        "movl %edi, 8(%esp)\n" /* line 3059 */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $str_00216f0c, (%esp)\n" /* "handle %i: %s
" */
        "calll Com_Printf\n"
        ".Lf33eee_0003401e:\n"
        "addl $1, %ebx\n" /* line 3056 | i */
        "addl $0x11c, %edi\n"
        "addl $0x11c, %esi\n" /* s */
        "cmpl $0x4a, %ebx\n" /* i */
        "jne .Lf33eee_00034000\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3062 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf33eee_0003403a:\n"
        "movl $str_00216f1c, (%esp)\n" /* line 3038 */
        "calll Com_Printf\n"
        "jmp .Lf33eee_00033f54\n"
        ".Lf33eee_0003404b:\n"
        "movl 0x10(%esi), %eax\n" /* line 3031 | s */
        "movl %eax, (%esp)\n"
        "calll SEH_GetLanguageName\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00216e88, (%esp)\n" /* "    localized assets iwd file for %s
" */
        "calll Com_Printf\n"
        "jmp .Lf33eee_00033f95\n"
        ".Lf33eee_0003406b:\n"
        "movl 8(%esi), %edx\n" /* line 3046 | s */
        "leal 0x100(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_00216ec8, (%esp)\n" /* "%s/%s
" */
        "calll Com_Printf\n"
        "movl 0xc(%esi), %eax\n" /* line 3048 | s */
        "testl %eax, %eax\n"
        "je .Lf33eee_00033f54\n"
        "movl 0x10(%esi), %eax\n" /* line 3049 | s */
        "movl %eax, (%esp)\n"
        "calll SEH_GetLanguageName\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00216ed0, (%esp)\n" /* "    localized assets game folder for %s
" */
        "calll Com_Printf\n"
        "jmp .Lf33eee_00033f54\n"
        ".Lf33eee_000340b3:\n"
        "movl 0x10(%esi), %ebx\n" /* line 422 */
        "calll SEH_GetCurrentLanguage\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf33eee_00033f54\n"
        "jmp .Lf33eee_00033f65\n"
        ".Lf33eee_000340c8:\n"
        "movl $str_00216e38, (%esp)\n" /* line 3019 */
        "calll Com_Printf\n"
        "jmp .Lf33eee_00033f23\n"
    );
}

/* line 3085 */
float FS_Path_f(void)
{
    FS_DisplayPath(1);
}

/* line 3072 */
float FS_FullPath_f(void)
{
    FS_DisplayPath(0);
}

/* line 1948 */
__attribute__((naked))
float FS_Printf(fileHandle_t h, const char *fmt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1948 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x103c, %esp\n"
        "movl 8(%ebp), %esi\n" /* h */
        /* { scope 1: tries, f */
        "leal 0x10(%ebp), %eax\n" /* line 1954 */
        "movl %eax, -0x1c(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 1955 */
        "movl 0xc(%ebp), %eax\n" /* fmt */
        "movl %eax, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "leal -0x101c(%ebp), %ebx\n" /* msg, buf */
        "movl %ebx, (%esp)\n" /* buf */
        "calll vsnprintf\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n"
        /* { scope 2 */
        "testl %esi, %esi\n" /* line 1908 */
        "je .Lf34102_00034179\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 544 */
        "shll $3, %eax\n"
        "subl %esi, %eax\n"
        "movl fsh(, %eax, 4), %eax\n"
        "movl %eax, -0x102c(%ebp)\n" /* f */
        "testl %edi, %edi\n" /* line 1916 | block */
        "jne .Lf34102_0003419d\n"
        ".Lf34102_00034166:\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 1936 */
        "shll $3, %eax\n"
        "subl %esi, %eax\n"
        "movl fsh+8(, %eax, 4), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf34102_00034184\n"
        /* } scope */
        /* } scope */
        ".Lf34102_00034179:\n"
        "addl $0x103c, %esp\n" /* line 1960 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tries, f */
        /* { scope 2 */
        ".Lf34102_00034184:\n"
        "movl -0x102c(%ebp), %eax\n" /* line 1938 | f */
        "movl %eax, (%esp)\n"
        "calll fflush\n"
        /* } scope */
        /* } scope */
        "addl $0x103c, %esp\n" /* line 1960 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tries, f */
        /* { scope 2 */
        ".Lf34102_0003419d:\n"
        "movl $0, -0x1030(%ebp)\n" /* line 1916 | tries */
        "jmp .Lf34102_000341c3\n"
        ".Lf34102_000341a9:\n"
        "movl -0x1030(%ebp), %ecx\n" /* line 1922 | tries */
        "testl %ecx, %ecx\n"
        "jne .Lf34102_00034179\n"
        "movl $1, -0x1030(%ebp)\n" /* tries */
        ".Lf34102_000341bd:\n"
        "addl %eax, %ebx\n" /* line 1932 | buf */
        "subl %eax, %edi\n" /* line 1916 | block */
        "je .Lf34102_00034166\n"
        ".Lf34102_000341c3:\n"
        "movl -0x102c(%ebp), %eax\n" /* line 1919 | f */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* block */
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* buf */
        "calll FS_FileWrite\n"
        "testl %eax, %eax\n" /* line 1920 */
        "je .Lf34102_000341a9\n"
        "cmpl $-1, %eax\n" /* line 1928 */
        "jne .Lf34102_000341bd\n"
        "jmp .Lf34102_00034179\n"
    );
}

/* line 2514 */
__attribute__((naked))
const char * * FS_ListFilteredFiles(searchpath_t *searchPath, const char *path, const char *extension, const char *filter, FsListBehavior behavior, int *numfiles, int allocTrackType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2514 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x437c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* path */
        /* { scope 1: zpathLen, netpath, numSysFiles, sysFiles */
        "testl %ebx, %ebx\n" /* line 2532 | path */
        "je .Lf341ec_00034867\n"
        "movl 0x10(%ebp), %edi\n" /* line 2537 | extension */
        "testl %edi, %edi\n"
        "movl $str_002157b8, %eax\n"
        "cmovnel 0x10(%ebp), %eax\n" /* extension */
        "movl %eax, 0x10(%ebp)\n" /* extension */
        "movl $0x100, %ecx\n" /* line 2542 */
        "leal -0x21c(%ebp), %edx\n" /* sanitizedPath */
        "movl %ebx, %eax\n" /* path */
        "calll FS_SanitizeFilename\n"
        "testb %al, %al\n"
        "jne .Lf341ec_00034242\n"
        "movl 0x1c(%ebp), %edx\n" /* line 2544 | numfiles */
        "movl $0, (%edx)\n"
        "xorl %ecx, %ecx\n"
        /* } scope */
        ".Lf341ec_00034235:\n"
        "movl %ecx, %eax\n" /* line 2697 */
        "addl $0x437c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: zpathLen, netpath, numSysFiles, sysFiles */
        ".Lf341ec_00034242:\n"
        "movl $str_00216f38, 4(%esp)\n" /* line 2548 */
        "movl 0x10(%ebp), %eax\n" /* extension */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "sete -0x4341(%ebp)\n" /* isDirSearch */
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x21c(%ebp), %edi\n" /* sanitizedPath */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, %edx\n" /* line 2551 */
        "subl $1, %edx\n"
        "movl %edx, -0x434c(%ebp)\n" /* pathLength */
        "je .Lf341ec_00034298\n"
        "leal -2(%ecx), %edx\n"
        "movzbl -0x21c(%ebp, %edx), %eax\n"
        "cmpb $0x5c, %al\n"
        "je .Lf341ec_0003463f\n"
        "cmpb $0x2f, %al\n"
        "je .Lf341ec_0003463f\n"
        ".Lf341ec_00034298:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0x10(%ebp), %edi\n" /* extension */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x4340(%ebp)\n"
        /* { scope 2: szTrimmedName */
        "movb $0, -0x11c(%ebp)\n" /* line 2450 | zpath */
        "movzbl -0x21c(%ebp), %eax\n" /* line 2454 | sanitizedPath */
        "testb %al, %al\n"
        "jne .Lf341ec_000345f6\n"
        "movl $0, -0x4348(%ebp)\n" /* pathDepth */
        "xorl %ebx, %ebx\n" /* len */
        "xorl %esi, %esi\n"
        "movl $1, %edi\n"
        ".Lf341ec_000342d9:\n"
        "leal -0x21c(%ebp), %eax\n" /* line 2463 | sanitizedPath */
        "movl %eax, 4(%esp)\n"
        "leal -0x11c(%ebp), %edx\n" /* zpath */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "movb $0, -0x11c(%ebp, %esi)\n" /* line 2464 */
        "movl -0x4348(%ebp), %eax\n" /* line 2468 | pathDepth */
        "subl $1, %eax\n"
        "cmpl %ebx, %edi\n" /* len */
        "cmovnel -0x4348(%ebp), %eax\n" /* pathDepth */
        /* } scope */
        "cmpb $1, -0x21c(%ebp)\n" /* line 2561 | sanitizedPath */
        "sbbl $-1, %eax\n"
        "movl %eax, -0x4348(%ebp)\n" /* pathDepth */
        "movl 8(%ebp), %esi\n" /* line 2567 | searchPath */
        "testl %esi, %esi\n"
        "je .Lf341ec_000346c7\n"
        "movl 8(%ebp), %eax\n" /* searchPath */
        "movl %eax, -0x4354(%ebp)\n" /* search */
        "movl $0, -0x4358(%ebp)\n" /* nfiles */
        "movl %eax, %edx\n"
        "jmp .Lf341ec_00034368\n"
        ".Lf341ec_0003433d:\n"
        "movl fs_ignoreLocalized, %eax\n" /* line 417 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf341ec_000346ac\n"
        ".Lf341ec_0003434c:\n"
        "movl -0x4354(%ebp), %edx\n" /* search */
        ".Lf341ec_00034352:\n"
        "movl (%edx), %edx\n" /* line 2567 */
        "movl %edx, -0x4354(%ebp)\n" /* search */
        "testl %edx, %edx\n"
        "je .Lf341ec_000346d1\n"
        "movl -0x4354(%ebp), %edx\n" /* search */
        ".Lf341ec_00034368:\n"
        "movl 0xc(%edx), %ebx\n" /* line 417 */
        "testl %ebx, %ebx\n"
        "jne .Lf341ec_0003433d\n"
        ".Lf341ec_0003436f:\n"
        "movl 4(%edx), %edx\n" /* line 2573 */
        "movl %edx, -0x435c(%ebp)\n"
        "testl %edx, %edx\n"
        "je .Lf341ec_000346f3\n"
        "movl -0x4354(%ebp), %eax\n" /* line 2578 | search */
        "movl 0xc(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf341ec_000343ca\n"
        /* { scope 2: szTrimmedName */
        "movl fs_numServerIwds, %ebx\n" /* line 367 */
        "cmpl $0, %ebx\n"
        "je .Lf341ec_000343ca\n"
        "jle .Lf341ec_0003434c\n" /* line 373 */
        "movl -0x435c(%ebp), %eax\n" /* line 376 */
        "movl 0x304(%eax), %esi\n"
        "cmpl fs_serverIwds, %esi\n"
        "je .Lf341ec_00034860\n"
        "xorl %ecx, %ecx\n"
        "movl $fs_serverIwds, %edx\n"
        ".Lf341ec_000343b9:\n"
        "addl $1, %ecx\n" /* line 373 */
        "cmpl %ecx, %ebx\n"
        "je .Lf341ec_0003434c\n"
        "movl 4(%edx), %eax\n" /* line 376 */
        "addl $4, %edx\n"
        "cmpl %esi, %eax\n"
        "jne .Lf341ec_000343b9\n"
        ".Lf341ec_000343ca:\n"
        "movl -0x435c(%ebp), %edx\n"
        /* } scope */
        ".Lf341ec_000343d0:\n"
        "movl 0x31c(%edx), %eax\n" /* line 2584 */
        "movl 0x30c(%edx), %ecx\n" /* line 2585 */
        "testl %ecx, %ecx\n"
        "jle .Lf341ec_0003434c\n"
        "movl %eax, -0x432c(%ebp)\n"
        "movl $0, -0x4350(%ebp)\n" /* i */
        "movl %eax, %edx\n"
        /* { scope 2: szTrimmedName */
        "movl 4(%edx), %esi\n" /* line 2591 | name */
        "movl 0x14(%ebp), %eax\n" /* line 2593 | filter */
        "testl %eax, %eax\n"
        "je .Lf341ec_000344b5\n"
        ".Lf341ec_00034404:\n"
        "movl $0, 8(%esp)\n" /* line 2596 */
        "movl %esi, 4(%esp)\n" /* name */
        "movl 0x14(%ebp), %eax\n" /* filter */
        "movl %eax, (%esp)\n"
        "calll Com_FilterPath\n"
        "testb %al, %al\n"
        "je .Lf341ec_0003447b\n"
        /* { scope 3 */
        "cmpl $0xfff, -0x4358(%ebp)\n" /* line 2484 | nfiles */
        "je .Lf341ec_0003469d\n"
        "movl -0x4358(%ebp), %eax\n" /* line 2488 | nfiles */
        "testl %eax, %eax\n"
        "jle .Lf341ec_0003445d\n"
        "xorl %ebx, %ebx\n" /* line 2484 | i */
        ".Lf341ec_0003443b:\n"
        "movl -0x431c(%ebp, %ebx, 4), %eax\n" /* line 2490 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf341ec_0003447b\n"
        "addl $1, %ebx\n" /* line 2488 | i */
        "cmpl %ebx, -0x4358(%ebp)\n" /* i, nfiles */
        "jne .Lf341ec_0003443b\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf341ec_0003445d:\n"
        "movl %esi, (%esp)\n" /* line 2495 */
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf341ec_00034460:\n"
        "calll CopyStringInternal\n"
        "movl -0x4358(%ebp), %edx\n" /* nfiles */
        "movl %eax, -0x431c(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 2496 */
        "movl %edx, -0x4358(%ebp)\n" /* nfiles */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf341ec_0003447b:\n"
        "addl $1, -0x4350(%ebp)\n" /* line 2585 | i */
        "addl $0xc, -0x432c(%ebp)\n"
        "movl -0x4350(%ebp), %edx\n" /* i */
        "movl -0x435c(%ebp), %eax\n"
        "cmpl 0x30c(%eax), %edx\n"
        "jge .Lf341ec_0003434c\n"
        "movl -0x432c(%ebp), %edx\n"
        /* { scope 2: szTrimmedName */
        "movl 4(%edx), %esi\n" /* line 2591 | name */
        "movl 0x14(%ebp), %eax\n" /* line 2593 | filter */
        "testl %eax, %eax\n"
        "jne .Lf341ec_00034404\n"
        ".Lf341ec_000344b5:\n"
        "movb $0, -0x11c(%ebp)\n" /* line 2450 | zpath */
        "movzbl (%esi), %eax\n" /* line 2454 */
        "testb %al, %al\n"
        "jne .Lf341ec_0003464a\n"
        "xorl %edi, %edi\n"
        "movl $0, -0x433c(%ebp)\n" /* zpathLen */
        "xorl %ebx, %ebx\n" /* len */
        "movl $0, -0x4334(%ebp)\n"
        "movl $1, -0x4330(%ebp)\n"
        ".Lf341ec_000344e9:\n"
        "movl %esi, 4(%esp)\n" /* line 2463 */
        "leal -0x11c(%ebp), %eax\n" /* zpath */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x4334(%ebp), %edx\n" /* line 2464 */
        "movb $0, -0x11c(%ebp, %edx)\n"
        "leal -1(%edi), %eax\n" /* line 2468 */
        "cmpl %ebx, -0x4330(%ebp)\n" /* len */
        "cmovel %eax, %edi\n"
        "cmpl -0x4348(%ebp), %edi\n" /* line 2606 | pathDepth, depth */
        "jne .Lf341ec_0003447b\n"
        "movl -0x433c(%ebp), %eax\n" /* zpathLen */
        "cmpl %eax, -0x434c(%ebp)\n" /* pathLength */
        "jg .Lf341ec_0003447b\n"
        "movl -0x434c(%ebp), %eax\n" /* pathLength */
        "testl %eax, %eax\n"
        "jle .Lf341ec_00034877\n"
        "movl -0x434c(%ebp), %edx\n" /* pathLength */
        "cmpb $0x2f, (%esi, %edx)\n" /* name */
        "jne .Lf341ec_0003447b\n"
        "movl %edx, %eax\n"
        ".Lf341ec_00034553:\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x21c(%ebp), %edx\n" /* sanitizedPath */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* name */
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf341ec_0003447b\n"
        "cmpb $0, -0x4341(%ebp)\n" /* line 2612 | isDirSearch */
        "jne .Lf341ec_00034890\n"
        "movl -0x4340(%ebp), %eax\n" /* line 2619 */
        "testl %eax, %eax\n"
        "jne .Lf341ec_000348ae\n"
        ".Lf341ec_0003458c:\n"
        "movl -0x434c(%ebp), %edi\n" /* line 2632 | pathLength, depth */
        "testl %edi, %edi\n" /* depth */
        "jne .Lf341ec_00034882\n"
        "xorl %eax, %eax\n"
        ".Lf341ec_0003459c:\n"
        "cmpb $0, -0x4341(%ebp)\n" /* line 2637 | isDirSearch */
        "jne .Lf341ec_00034903\n"
        "addl %eax, %esi\n" /* line 2648 | name */
        /* { scope 3 */
        /* { scope 4 */
        "cmpl $0xfff, -0x4358(%ebp)\n" /* line 2484 | nfiles */
        "je .Lf341ec_0003469d\n"
        "movl -0x4358(%ebp), %eax\n" /* line 2488 | nfiles */
        "testl %eax, %eax\n"
        "jle .Lf341ec_0003445d\n"
        "xorl %ebx, %ebx\n" /* line 2484 | i */
        ".Lf341ec_000345cb:\n"
        "movl -0x431c(%ebp, %ebx, 4), %eax\n" /* line 2490 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf341ec_0003447b\n"
        "addl $1, %ebx\n" /* line 2488 | i */
        "cmpl %ebx, -0x4358(%ebp)\n" /* i, nfiles */
        "jne .Lf341ec_000345cb\n"
        "jmp .Lf341ec_0003445d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: szTrimmedName */
        ".Lf341ec_000345f6:\n"
        "movl $0, -0x4348(%ebp)\n" /* line 2454 | pathDepth */
        "xorl %edx, %edx\n"
        "xorl %ebx, %ebx\n" /* len */
        "jmp .Lf341ec_00034619\n"
        ".Lf341ec_00034606:\n"
        "cmpb $0x5c, %al\n" /* line 2456 */
        "je .Lf341ec_0003461d\n"
        "addl $1, %ebx\n" /* line 2461 | len */
        "movzbl -0x21c(%ebx, %ebp), %eax\n" /* line 2454 | len */
        "testb %al, %al\n"
        "je .Lf341ec_00034635\n"
        ".Lf341ec_00034619:\n"
        "cmpb $0x2f, %al\n" /* line 2456 */
        "jne .Lf341ec_00034606\n"
        ".Lf341ec_0003461d:\n"
        "addl $1, -0x4348(%ebp)\n" /* line 2459 | pathDepth */
        "movl %ebx, %edx\n" /* len */
        "addl $1, %ebx\n" /* line 2461 | len */
        "movzbl -0x21c(%ebx, %ebp), %eax\n" /* line 2454 | len */
        "testb %al, %al\n"
        "jne .Lf341ec_00034619\n"
        ".Lf341ec_00034635:\n"
        "movl %edx, %esi\n"
        "leal 1(%edx), %edi\n"
        "jmp .Lf341ec_000342d9\n"
        /* } scope */
        ".Lf341ec_0003463f:\n"
        "movl %edx, -0x434c(%ebp)\n" /* line 2551 | pathLength */
        "jmp .Lf341ec_00034298\n"
        /* { scope 2: szTrimmedName */
        ".Lf341ec_0003464a:\n"
        "xorl %ebx, %ebx\n" /* line 2454 | len */
        "movl $0, -0x433c(%ebp)\n" /* zpathLen */
        "xorl %edi, %edi\n"
        "jmp .Lf341ec_00034669\n"
        ".Lf341ec_0003465a:\n"
        "cmpb $0x5c, %al\n" /* line 2456 */
        "je .Lf341ec_0003466d\n"
        "addl $1, %ebx\n" /* line 2461 | len */
        "movzbl (%esi, %ebx), %eax\n" /* line 2454 */
        "testb %al, %al\n"
        "je .Lf341ec_00034681\n"
        ".Lf341ec_00034669:\n"
        "cmpb $0x2f, %al\n" /* line 2456 */
        "jne .Lf341ec_0003465a\n"
        ".Lf341ec_0003466d:\n"
        "addl $1, %edi\n" /* line 2459 */
        "movl %ebx, -0x433c(%ebp)\n" /* len, zpathLen */
        "addl $1, %ebx\n" /* line 2461 | len */
        "movzbl (%esi, %ebx), %eax\n" /* line 2454 */
        "testb %al, %al\n"
        "jne .Lf341ec_00034669\n"
        ".Lf341ec_00034681:\n"
        "movl -0x433c(%ebp), %eax\n" /* zpathLen */
        "movl %eax, -0x4334(%ebp)\n"
        "movl %eax, %edx\n"
        "addl $1, %edx\n"
        "movl %edx, -0x4330(%ebp)\n"
        "jmp .Lf341ec_000344e9\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf341ec_0003469d:\n"
        "movl $0xfff, -0x4358(%ebp)\n" /* line 2496 | nfiles */
        "jmp .Lf341ec_0003447b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf341ec_000346ac:\n"
        "movl 0x10(%edx), %ebx\n" /* line 422 */
        "calll SEH_GetCurrentLanguage\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf341ec_0003434c\n"
        "movl -0x4354(%ebp), %edx\n" /* search */
        "jmp .Lf341ec_0003436f\n"
        ".Lf341ec_000346c7:\n"
        "movl $0, -0x4358(%ebp)\n" /* line 2567 | nfiles */
        ".Lf341ec_000346d1:\n"
        "movl -0x4358(%ebp), %eax\n" /* line 2680 | nfiles */
        "movl 0x1c(%ebp), %edx\n" /* numfiles */
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 2682 */
        "jne .Lf341ec_00034807\n"
        "xorl %ecx, %ecx\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 2697 */
        "addl $0x437c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: zpathLen, netpath, numSysFiles, sysFiles */
        ".Lf341ec_000346f3:\n"
        "movl -0x4354(%ebp), %eax\n" /* line 2653 | search */
        "movl 8(%eax), %ebx\n" /* path */
        "testl %ebx, %ebx\n" /* path */
        "je .Lf341ec_00034859\n"
        /* { scope 2: szTrimmedName */
        "movl fs_restrict, %eax\n" /* line 2663 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf341ec_00034719\n"
        "movl fs_numServerIwds, %esi\n" /* name */
        "testl %esi, %esi\n" /* name */
        "je .Lf341ec_00034724\n"
        ".Lf341ec_00034719:\n"
        "movl 0x18(%ebp), %ecx\n" /* behavior */
        "testl %ecx, %ecx\n"
        "je .Lf341ec_0003434c\n"
        ".Lf341ec_00034724:\n"
        "leal 0x100(%ebx), %edx\n" /* line 697 */
        "movl $0, 4(%esp)\n"
        "leal -0x31c(%ebp), %eax\n" /* szTrimmedName */
        "movl %eax, (%esp)\n"
        "leal -0x21c(%ebp), %ecx\n" /* sanitizedPath */
        "movl %ebx, %eax\n"
        "calll FS_BuildOSPath_Internal\n"
        "movzbl -0x4341(%ebp), %eax\n" /* line 2668 | isDirSearch */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* numSysFiles */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* filter */
        "movl %edx, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* extension */
        "movl %eax, 4(%esp)\n"
        "leal -0x31c(%ebp), %edx\n" /* szTrimmedName */
        "movl %edx, (%esp)\n"
        "calll Sys_ListFiles\n"
        "movl %eax, -0x4338(%ebp)\n" /* sysFiles */
        "movl -0x1c(%ebp), %edx\n" /* line 2669 | numSysFiles */
        "testl %edx, %edx\n"
        "jle .Lf341ec_000347f4\n"
        "xorl %edi, %edi\n" /* depth */
        ".Lf341ec_00034785:\n"
        "movl -0x4338(%ebp), %eax\n" /* line 2672 | sysFiles */
        "movl (%eax, %edi, 4), %esi\n" /* name */
        /* { scope 3 */
        "cmpl $0xfff, -0x4358(%ebp)\n" /* line 2484 | nfiles */
        "je .Lf341ec_000347e6\n"
        "movl -0x4358(%ebp), %eax\n" /* line 2488 | nfiles */
        "testl %eax, %eax\n"
        "jle .Lf341ec_000347c8\n"
        "xorl %ebx, %ebx\n" /* line 2484 | i */
        ".Lf341ec_000347a6:\n"
        "movl -0x431c(%ebp, %ebx, 4), %eax\n" /* line 2490 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf341ec_000347e6\n"
        "addl $1, %ebx\n" /* line 2488 | i */
        "cmpl -0x4358(%ebp), %ebx\n" /* nfiles, i */
        "jne .Lf341ec_000347a6\n"
        ".Lf341ec_000347c8:\n"
        "movl %esi, (%esp)\n" /* line 2495 */
        "calll CopyStringInternal\n"
        "movl -0x4358(%ebp), %edx\n" /* nfiles */
        "movl %eax, -0x431c(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 2496 */
        "movl %edx, -0x4358(%ebp)\n" /* nfiles */
        /* } scope */
        ".Lf341ec_000347e6:\n"
        "addl $1, %edi\n" /* line 2669 | depth */
        "cmpl %edi, -0x1c(%ebp)\n" /* depth, numSysFiles */
        "jg .Lf341ec_00034785\n"
        "movl -0x4338(%ebp), %eax\n" /* sysFiles */
        ".Lf341ec_000347f4:\n"
        "movl %eax, (%esp)\n" /* line 2675 */
        "calll Sys_FreeFileList\n"
        "movl -0x4354(%ebp), %edx\n" /* search */
        "jmp .Lf341ec_00034352\n"
        /* } scope */
        ".Lf341ec_00034807:\n"
        "movl -0x4358(%ebp), %edx\n" /* line 2687 | nfiles */
        "leal 4(, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ecx\n"
        "movl -0x4358(%ebp), %ebx\n" /* line 2689 | nfiles, path */
        "testl %ebx, %ebx\n" /* path */
        "jg .Lf341ec_0003483e\n"
        "xorl %eax, %eax\n"
        ".Lf341ec_0003482a:\n"
        "movl $0, (%ecx, %eax, 4)\n" /* line 2694 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 2697 */
        "addl $0x437c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: zpathLen, netpath, numSysFiles, sysFiles */
        ".Lf341ec_0003483e:\n"
        "xorl %edx, %edx\n" /* line 2689 */
        ".Lf341ec_00034840:\n"
        "movl -0x431c(%ebp, %edx, 4), %eax\n" /* line 2691 */
        "movl %eax, (%ecx, %edx, 4)\n"
        "addl $1, %edx\n" /* line 2689 */
        "cmpl %edx, -0x4358(%ebp)\n" /* nfiles */
        "jne .Lf341ec_00034840\n"
        "movl %edx, %eax\n"
        "jmp .Lf341ec_0003482a\n"
        ".Lf341ec_00034859:\n"
        "movl %eax, %edx\n"
        "jmp .Lf341ec_00034352\n"
        ".Lf341ec_00034860:\n"
        "movl %eax, %edx\n"
        "jmp .Lf341ec_000343d0\n"
        ".Lf341ec_00034867:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 2534 | numfiles */
        "movl $0, (%eax)\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf341ec_00034235\n"
        ".Lf341ec_00034877:\n"
        "movl -0x434c(%ebp), %eax\n" /* pathLength */
        "jmp .Lf341ec_00034553\n"
        /* { scope 2: szTrimmedName */
        ".Lf341ec_00034882:\n"
        "movl -0x434c(%ebp), %eax\n" /* line 2634 | pathLength */
        "addl $1, %eax\n"
        "jmp .Lf341ec_0003459c\n"
        ".Lf341ec_00034890:\n"
        "cld\n" /* line 2616 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* name, depth */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* depth */
        "notl %ecx\n"
        "cmpb $0x2f, -2(%ecx, %esi)\n"
        "jne .Lf341ec_0003447b\n"
        "jmp .Lf341ec_0003458c\n"
        ".Lf341ec_000348ae:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "cmpl %edx, -0x4340(%ebp)\n" /* line 2622 */
        "jge .Lf341ec_0003447b\n"
        "movl %edx, %eax\n" /* line 2624 */
        "subl -0x4340(%ebp), %eax\n"
        "cmpb $0x2e, -1(%esi, %eax)\n" /* name */
        "jne .Lf341ec_0003447b\n"
        "movl 0x10(%ebp), %eax\n" /* line 2626 | extension */
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %edx), %eax\n" /* name */
        "subl -0x4340(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf341ec_0003447b\n"
        "jmp .Lf341ec_0003458c\n"
        /* { scope 3 */
        ".Lf341ec_00034903:\n"
        "leal (%esi, %eax), %eax\n" /* line 2641 | name */
        "movl %eax, 4(%esp)\n"
        "leal -0x31c(%ebp), %edx\n" /* szTrimmedName */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 2642 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x31c(%ebp), %edi\n" /* szTrimmedName, depth */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* depth */
        "notl %ecx\n"
        "movb $0, -0x31e(%ecx, %ebp)\n"
        /* { scope 4 */
        "cmpl $0xfff, -0x4358(%ebp)\n" /* line 2484 | nfiles */
        "je .Lf341ec_0003469d\n"
        "movl -0x4358(%ebp), %eax\n" /* line 2488 | nfiles */
        "testl %eax, %eax\n"
        "jle .Lf341ec_0003497a\n"
        "xorl %ebx, %ebx\n" /* line 2484 | i */
        ".Lf341ec_0003494e:\n"
        "movl -0x431c(%ebp, %ebx, 4), %eax\n" /* line 2490 */
        "movl %eax, 4(%esp)\n"
        "leal -0x31c(%ebp), %edx\n" /* szTrimmedName */
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf341ec_0003447b\n"
        "addl $1, %ebx\n" /* line 2488 | i */
        "cmpl %ebx, -0x4358(%ebp)\n" /* i, nfiles */
        "jne .Lf341ec_0003494e\n"
        ".Lf341ec_0003497a:\n"
        "leal -0x31c(%ebp), %eax\n" /* line 2495 | szTrimmedName */
        "movl %eax, (%esp)\n"
        "jmp .Lf341ec_00034460\n"
    );
}

/* line 2705 */
__attribute__((naked))
const char * * FS_ListFiles(const char *path, const char *extension, FsListBehavior behavior, int *numfiles, int allocTrackType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2705 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 0x18(%ebp), %eax\n" /* line 2707 | allocTrackType */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* numfiles */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* behavior */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* extension */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* path */
        "movl %eax, 4(%esp)\n"
        "movl fs_searchpaths, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_ListFilteredFiles\n"
        "leave\n" /* line 2708 */
        "retl\n"
    );
}

/* line 2855 */
__attribute__((naked))
int FS_GetFileList(const char *path, const char *extension, FsListBehavior behavior, char *listbuf, int bufsize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2855 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* path */
        "movl 0x14(%ebp), %esi\n" /* listbuf */
        /* { scope 1 */
        "movb $0, (%esi)\n" /* line 2860 | listbuf */
        "movl $0, -0x1c(%ebp)\n" /* line 2861 | fileCount */
        "movl $str_00216f5c, 4(%esp)\n" /* line 2865 */
        "movl %ebx, (%esp)\n" /* path */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf349ca_00034a0e\n"
        "movl 0x18(%ebp), %eax\n" /* line 2866 | bufsize */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* listbuf */
        "calll FS_GetModList\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2890 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf349ca_00034a0e:\n"
        "movl $3, 0x18(%esp)\n" /* line 2707 */
        "leal -0x1c(%ebp), %eax\n" /* fileCount */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* behavior */
        "movl %edx, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* extension */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl fs_searchpaths, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_ListFilteredFiles\n"
        "movl %eax, -0x2c(%ebp)\n" /* fileNames */
        "movl -0x1c(%ebp), %edi\n" /* line 2871 | fileCount */
        "testl %edi, %edi\n"
        "jg .Lf349ca_00034a8c\n"
        ".Lf349ca_00034a4e:\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 2835 | fileNames */
        "testl %ebx, %ebx\n"
        "je .Lf349ca_00034a81\n"
        ".Lf349ca_00034a55:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2840 | fileNames */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf349ca_00034ae8\n"
        "movl %edx, %edi\n"
        ".Lf349ca_00034a64:\n"
        "movl %eax, (%esp)\n" /* line 2842 */
        "calll Z_FreeInternal\n"
        "movl 4(%edi), %eax\n" /* line 2840 */
        "addl $4, %edi\n"
        "testl %eax, %eax\n"
        "jne .Lf349ca_00034a64\n"
        "movl -0x2c(%ebp), %ecx\n" /* fileNames */
        ".Lf349ca_00034a79:\n"
        "movl %ecx, (%esp)\n" /* line 2845 */
        "calll Z_FreeInternal\n"
        ".Lf349ca_00034a81:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2889 | fileCount */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2890 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf349ca_00034a8c:\n"
        "movl $0, -0x30(%ebp)\n" /* line 2871 | nTotal */
        "movl $0, -0x34(%ebp)\n" /* i */
        ".Lf349ca_00034a9a:\n"
        "movl -0x34(%ebp), %eax\n" /* line 2873 | i */
        "movl -0x2c(%ebp), %ecx\n" /* fileNames */
        "movl (%ecx, %eax, 4), %edx\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "addl %ebx, -0x30(%ebp)\n" /* line 2874 | path, nTotal */
        "movl -0x30(%ebp), %eax\n" /* nTotal */
        "addl $1, %eax\n"
        "cmpl 0x18(%ebp), %eax\n" /* bufsize */
        "jge .Lf349ca_00034aec\n"
        "movl %edx, 4(%esp)\n" /* line 2876 */
        "movl %esi, (%esp)\n" /* listbuf */
        "calll strcpy\n"
        "addl %ebx, %esi\n" /* line 2877 | path, listbuf */
        "addl $1, -0x34(%ebp)\n" /* line 2871 | i */
        "movl -0x34(%ebp), %eax\n" /* i */
        "cmpl -0x1c(%ebp), %eax\n" /* fileCount */
        "jl .Lf349ca_00034a9a\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 2835 | fileNames */
        "testl %ebx, %ebx\n"
        "jne .Lf349ca_00034a55\n"
        "jmp .Lf349ca_00034a81\n"
        ".Lf349ca_00034ae8:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf349ca_00034a79\n"
        ".Lf349ca_00034aec:\n"
        "movl -0x34(%ebp), %edx\n" /* line 2882 | i */
        "movl %edx, -0x1c(%ebp)\n" /* fileCount */
        "jmp .Lf349ca_00034a4e\n"
    );
}

/* line 2968 */
__attribute__((naked))
float FS_SortFileList(const char * *filelist, int numfiles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2968 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* filelist */
        "movl %eax, -0x30(%ebp)\n" /* filelist */
        "movl 0xc(%ebp), %edx\n" /* numfiles */
        "movl %edx, -0x34(%ebp)\n" /* numfiles */
        /* { scope 1: s2 */
        "leal 4(, %edx, 4), %eax\n" /* line 2973 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, -0x24(%ebp)\n" /* sortedlist */
        "movl $0, (%eax)\n" /* line 2974 */
        "movl -0x34(%ebp), %edx\n" /* line 2976 | numfiles */
        "testl %edx, %edx\n"
        "jle .Lf34af8_00034c3f\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* j */
        "movl $0, -0x28(%ebp)\n" /* numsortedfiles */
        "movl -0x28(%ebp), %edx\n" /* numsortedfiles */
        ".Lf34af8_00034b44:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 2989 | filelist */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl -0x2c(%ebp), %edx\n" /* j */
        "movl -0x24(%ebp), %ecx\n" /* sortedlist */
        "movl %eax, (%ecx, %edx, 4)\n"
        "addl $1, -0x28(%ebp)\n" /* line 2990 | numsortedfiles */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 2976 | numsortedfiles */
        "cmpl %eax, -0x34(%ebp)\n" /* numfiles */
        "je .Lf34af8_00034c3f\n"
        ".Lf34af8_00034b67:\n"
        "movl $0, -0x2c(%ebp)\n" /* j */
        "testl %eax, %eax\n" /* line 2978 */
        "jle .Lf34af8_00034c19\n"
        "movl -0x2c(%ebp), %ecx\n" /* j */
        ".Lf34af8_00034b79:\n"
        "movl -0x24(%ebp), %eax\n" /* line 2980 | sortedlist */
        "movl (%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* s2 */
        "movl -0x28(%ebp), %eax\n" /* numsortedfiles */
        "movl -0x30(%ebp), %edx\n" /* filelist */
        "movl (%edx, %eax, 4), %edi\n" /* s1 */
        "jmp .Lf34af8_00034bb1\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf34af8_00034b8d:\n"
        "cmpl $0x3a, %esi\n" /* line 2940 | c1 */
        "je .Lf34af8_00034be5\n"
        "cmpl $0x5c, %ebx\n" /* line 2944 | c2 */
        "je .Lf34af8_00034bef\n"
        ".Lf34af8_00034b97:\n"
        "cmpl $0x3a, %ebx\n" /* c2 */
        "je .Lf34af8_00034bef\n"
        "cmpl %ebx, %esi\n" /* line 2949 | c2, c1 */
        "jl .Lf34af8_00034bf8\n"
        ".Lf34af8_00034ba0:\n"
        "jg .Lf34af8_00034c6d\n" /* line 2953 */
        "testl %esi, %esi\n" /* line 2926 | c1 */
        "je .Lf34af8_00034c6d\n"
        "movl -0x20(%ebp), %ecx\n" /* s2 */
        ".Lf34af8_00034bb1:\n"
        "movsbl (%edi), %esi\n" /* line 2928 | c1 */
        "addl $1, %edi\n"
        "movsbl (%ecx), %ebx\n" /* line 2929 | c2 */
        "addl $1, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* s2 */
        "movl %esi, (%esp)\n" /* line 2931 | c1 */
        "calll I_islower\n"
        "leal -0x20(%esi), %edx\n" /* line 2933 | c1 */
        "testb %al, %al\n"
        "cmovnel %edx, %esi\n" /* c1 */
        "movl %ebx, (%esp)\n" /* line 2935 | c2 */
        "calll I_islower\n"
        "leal -0x20(%ebx), %edx\n" /* line 2937 | c2 */
        "testb %al, %al\n"
        "cmovnel %edx, %ebx\n" /* c2 */
        "cmpl $0x5c, %esi\n" /* line 2940 | c1 */
        "jne .Lf34af8_00034b8d\n"
        ".Lf34af8_00034be5:\n"
        "movl $0x2f, %esi\n" /* c1 */
        "cmpl $0x5c, %ebx\n" /* line 2944 | c2 */
        "jne .Lf34af8_00034b97\n"
        ".Lf34af8_00034bef:\n"
        "movl $0x2f, %ebx\n" /* c2 */
        "cmpl %ebx, %esi\n" /* line 2949 | c2, c1 */
        "jge .Lf34af8_00034ba0\n"
        /* } scope */
        /* } scope */
        ".Lf34af8_00034bf8:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2985 | j */
        "cmpl %eax, -0x28(%ebp)\n" /* numsortedfiles */
        "jle .Lf34af8_00034c19\n"
        "movl -0x1c(%ebp), %edx\n"
        "subl $4, %edx\n"
        "movl -0x28(%ebp), %ecx\n" /* numsortedfiles */
        ".Lf34af8_00034c09:\n"
        "movl (%edx), %eax\n" /* line 2987 */
        "movl %eax, 4(%edx)\n"
        "subl $1, %ecx\n" /* line 2985 */
        "subl $4, %edx\n"
        "cmpl -0x2c(%ebp), %ecx\n" /* j */
        "jg .Lf34af8_00034c09\n"
        ".Lf34af8_00034c19:\n"
        "movl -0x28(%ebp), %edx\n" /* numsortedfiles */
        "movl -0x30(%ebp), %ecx\n" /* line 2989 | filelist */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl -0x2c(%ebp), %edx\n" /* j */
        "movl -0x24(%ebp), %ecx\n" /* sortedlist */
        "movl %eax, (%ecx, %edx, 4)\n"
        "addl $1, -0x28(%ebp)\n" /* line 2990 | numsortedfiles */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 2976 | numsortedfiles */
        "cmpl %eax, -0x34(%ebp)\n" /* numfiles */
        "jne .Lf34af8_00034b67\n"
        ".Lf34af8_00034c3f:\n"
        "movl -0x34(%ebp), %eax\n" /* line 2992 | numfiles */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %edx\n" /* sortedlist */
        "movl %edx, 4(%esp)\n"
        "movl -0x30(%ebp), %ecx\n" /* filelist */
        "movl %ecx, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl -0x24(%ebp), %eax\n" /* line 2993 | sortedlist */
        "movl %eax, 8(%ebp)\n" /* filelist */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2994 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: s2 */
        "jmp Z_FreeInternal\n" /* line 2993 */
        ".Lf34af8_00034c6d:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 2978 | j */
        "movl -0x2c(%ebp), %edx\n" /* j */
        "cmpl %edx, -0x28(%ebp)\n" /* numsortedfiles */
        "je .Lf34af8_00034c80\n"
        "movl %edx, %ecx\n"
        "jmp .Lf34af8_00034b79\n"
        ".Lf34af8_00034c80:\n"
        "movl -0x28(%ebp), %ecx\n" /* numsortedfiles */
        "movl %ecx, -0x2c(%ebp)\n" /* j */
        "movl %ecx, %edx\n"
        "jmp .Lf34af8_00034b44\n"
    );
}

/* line 2275 */
__attribute__((naked))
fileHandle_t FS_OpenFileOverwrite(const char *qpath)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2275 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1 */
        "leal -0x118(%ebp), %ebx\n" /* line 2285 | ospath, i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl 8(%ebp), %eax\n" /* qpath */
        "movl %eax, (%esp)\n"
        "calll FS_GetFileOsPath\n"
        "testl %eax, %eax\n"
        "js .Lf34c8e_00034dcc\n"
        "movl fs_debug, %eax\n" /* line 2291 */
        "movl 8(%eax), %esi\n" /* f */
        "testl %esi, %esi\n" /* f */
        "jne .Lf34c8e_00034d6d\n"
        ".Lf34c8e_00034cc7:\n"
        "movl %ebx, (%esp)\n" /* line 2294 | i */
        "calll GetFileAttributesA\n"
        "movl %eax, %edx\n" /* line 2295 */
        "andl $0xfffffffe, %edx\n"
        "cmpl %edx, %eax\n" /* line 2296 */
        "je .Lf34c8e_00034ce4\n"
        "movl %edx, 4(%esp)\n" /* line 2297 */
        "movl %ebx, (%esp)\n" /* i */
        "calll SetFileAttributesA\n"
        /* { scope 2 */
        ".Lf34c8e_00034ce4:\n"
        "movl $str_00216fec, 4(%esp)\n" /* line 933 */
        "movl %ebx, (%esp)\n" /* i */
        "calll FS_FileOpen\n"
        "movl %eax, %edi\n" /* fp */
        "testl %eax, %eax\n" /* line 936 */
        "je .Lf34c8e_00034df6\n"
        "xorl %esi, %esi\n" /* f */
        "movl $fsh, %eax\n"
        "jmp .Lf34c8e_00034d11\n"
        /* { scope 3 */
        ".Lf34c8e_00034d07:\n"
        "addl $0x11c, %eax\n" /* line 516 */
        "cmpl $0x3c, %esi\n" /* line 514 */
        "je .Lf34c8e_00034d82\n"
        ".Lf34c8e_00034d11:\n"
        "addl $1, %esi\n" /* line 516 */
        "movl 0x11c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf34c8e_00034d07\n"
        /* } scope */
        ".Lf34c8e_00034d1e:\n"
        "leal (%esi, %esi, 8), %ebx\n" /* line 940 | f, i */
        "shll $3, %ebx\n" /* i */
        "subl %esi, %ebx\n" /* f, i */
        "shll $2, %ebx\n" /* i */
        "movl $0, fsh+20(%ebx)\n" /* i */
        "movl %edi, fsh(%ebx)\n" /* line 941 | fp, i */
        "movl $0x100, 8(%esp)\n" /* line 942 */
        "movl 8(%ebp), %eax\n" /* qpath */
        "movl %eax, 4(%esp)\n"
        "leal fsh+28(%ebx), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0, fsh+8(%ebx)\n" /* line 943 | i */
        /* } scope */
        /* } scope */
        ".Lf34c8e_00034d60:\n"
        "movl %esi, %eax\n" /* line 2300 | f */
        "addl $0x11c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf34c8e_00034d6d:\n"
        "movl %ebx, 4(%esp)\n" /* line 2292 | i */
        "movl $str_00216fd0, (%esp)\n" /* "FS_FOpenFileOverWrite: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf34c8e_00034cc7\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf34c8e_00034d82:\n"
        "movl $1, %ebx\n" /* line 514 | i */
        "movl $fsh+312, %esi\n"
        ".Lf34c8e_00034d8c:\n"
        "movl %esi, 8(%esp)\n" /* line 524 */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $str_00216c70, (%esp)\n" /* "FILE %2i: '%s'
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 523 | i */
        "addl $0x11c, %esi\n"
        "cmpl $0x4a, %ebx\n" /* i */
        "jne .Lf34c8e_00034d8c\n"
        "movl $str_00216c80, 4(%esp)\n" /* line 526 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0xffffffff, %esi\n"
        "jmp .Lf34c8e_00034d1e\n"
        /* } scope */
        /* } scope */
        ".Lf34c8e_00034dcc:\n"
        "movl 8(%ebp), %eax\n" /* line 2287 | qpath */
        "movl %eax, 8(%esp)\n"
        "movl $str_00216f68, 4(%esp)\n" /* "FS_FOpenFileOverWrite: Failed to open %s for writing.  It ei" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %esi, %esi\n" /* f */
        /* } scope */
        "movl %esi, %eax\n" /* line 2300 | f */
        "addl $0x11c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf34c8e_00034df6:\n"
        "xorl %esi, %esi\n" /* line 936 | f */
        "jmp .Lf34c8e_00034d60\n"
    );
}

/* line 3122 */
static __attribute__((naked))
int iwdsort(const float *a, const float *b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3122 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1: pszLanguageA, s1 */
        "movl 8(%ebp), %eax\n" /* line 3126 | a */
        "movl (%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* aa */
        "movl 0xc(%ebp), %eax\n" /* line 3127 | b */
        "movl (%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* bb */
        "movl $0xa, 8(%esp)\n" /* line 3129 */
        "movl $str_00216ff0, 4(%esp)\n" /* "          " */
        "movl -0x28(%ebp), %eax\n" /* aa */
        "movl %eax, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lf34dfe_00034e59\n"
        "movl $0xa, 8(%esp)\n"
        "movl $str_00216ff0, 4(%esp)\n" /* "          " */
        "movl -0x24(%ebp), %eax\n" /* bb */
        "movl %eax, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "je .Lf34dfe_00034ee2\n"
        /* { scope 2 */
        ".Lf34dfe_00034e59:\n"
        "movl -0x28(%ebp), %eax\n" /* line 3143 | aa */
        "movl %eax, -0x1c(%ebp)\n" /* s1 */
        "movl -0x24(%ebp), %esi\n" /* bb */
        "jmp .Lf34dfe_00034e84\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf34dfe_00034e64:\n"
        "cmpl $0x3a, %ebx\n" /* line 2940 | c1 */
        "je .Lf34dfe_00034eb8\n"
        "cmpl $0x5c, %edi\n" /* line 2944 | c2 */
        "je .Lf34dfe_00034ec2\n"
        ".Lf34dfe_00034e6e:\n"
        "cmpl $0x3a, %edi\n" /* c2 */
        "je .Lf34dfe_00034ec2\n"
        "cmpl %edi, %ebx\n" /* line 2949 | c2, c1 */
        "jl .Lf34dfe_00034ecb\n"
        ".Lf34dfe_00034e77:\n"
        "jg .Lf34dfe_00034f8f\n" /* line 2953 */
        "testl %ebx, %ebx\n" /* line 2926 | c1 */
        "je .Lf34dfe_00034ed8\n"
        "movl -0x1c(%ebp), %eax\n" /* s1 */
        ".Lf34dfe_00034e84:\n"
        "movsbl (%eax), %ebx\n" /* line 2928 | c1 */
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* s1 */
        "movsbl (%esi), %edi\n" /* line 2929 | c2 */
        "addl $1, %esi\n"
        "movl %ebx, (%esp)\n" /* line 2931 | c1 */
        "calll I_islower\n"
        "leal -0x20(%ebx), %edx\n" /* line 2933 | c1 */
        "testb %al, %al\n"
        "cmovnel %edx, %ebx\n" /* c1 */
        "movl %edi, (%esp)\n" /* line 2935 | c2 */
        "calll I_islower\n"
        "leal -0x20(%edi), %edx\n" /* line 2937 | c2 */
        "testb %al, %al\n"
        "cmovnel %edx, %edi\n" /* c2 */
        "cmpl $0x5c, %ebx\n" /* line 2940 | c1 */
        "jne .Lf34dfe_00034e64\n"
        ".Lf34dfe_00034eb8:\n"
        "movl $0x2f, %ebx\n" /* c1 */
        "cmpl $0x5c, %edi\n" /* line 2944 | c2 */
        "jne .Lf34dfe_00034e6e\n"
        ".Lf34dfe_00034ec2:\n"
        "movl $0x2f, %edi\n" /* c2 */
        "cmpl %edi, %ebx\n" /* line 2949 | c2, c1 */
        "jge .Lf34dfe_00034e77\n"
        ".Lf34dfe_00034ecb:\n"
        "movl $0xffffffff, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf34dfe_00034ed0:\n"
        "addl $0x2c, %esp\n" /* line 3148 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pszLanguageA, s1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf34dfe_00034ed8:\n"
        "xorl %eax, %eax\n" /* line 2926 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3148 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pszLanguageA, s1 */
        /* { scope 2 */
        ".Lf34dfe_00034ee2:\n"
        "movl iString, %ebx\n" /* line 3104 | c1 */
        "xorl $1, %ebx\n" /* c1 */
        "movl %ebx, iString\n" /* c1 */
        "cld\n" /* line 3106 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x28(%ebp), %edi\n" /* aa, c2 */
        "repne scasb %es:(%edi), %al\n" /* c2 */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $9, %ecx\n"
        "ja .Lf34dfe_00034f9c\n"
        "movl %ebx, %eax\n" /* line 3108 | c1 */
        "shll $6, %eax\n"
        "movb $0, szIwdLanguageName(%eax)\n"
        ".Lf34dfe_00034f16:\n"
        "movl %ebx, %eax\n" /* line 3118 | c1 */
        "shll $6, %eax\n"
        "addl $szIwdLanguageName, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* pszLanguageA */
        "xorl $1, %ebx\n" /* line 3104 | c1 */
        "movl %ebx, iString\n" /* c1 */
        "cld\n" /* line 3106 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x24(%ebp), %edi\n" /* bb, c2 */
        "repne scasb %es:(%edi), %al\n" /* c2 */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $9, %ecx\n"
        "ja .Lf34dfe_00035032\n"
        "movl %ebx, %eax\n" /* line 3108 | c1 */
        "shll $6, %eax\n"
        "movb $0, szIwdLanguageName(%eax)\n"
        ".Lf34dfe_00034f53:\n"
        "shll $6, %ebx\n" /* line 3118 | c1 */
        "addl $szIwdLanguageName, %ebx\n" /* c1 */
        "movl $str_0021699c, 4(%esp)\n" /* line 3137 */
        "movl -0x20(%ebp), %eax\n" /* pszLanguageA */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf34dfe_000350d6\n"
        "movl $str_0021699c, 4(%esp)\n" /* line 3143 */
        "movl %ebx, (%esp)\n" /* pszLanguageB */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf34dfe_00034e59\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf34dfe_00034f8f:\n"
        "movl $1, %eax\n" /* line 2926 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3148 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pszLanguageA, s1 */
        /* { scope 2 */
        ".Lf34dfe_00034f9c:\n"
        "shll $6, %ebx\n" /* line 3113 | c1 */
        "leal szIwdLanguageName(%ebx), %eax\n" /* c1 */
        "movl $0x40, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "xorl %esi, %esi\n"
        "jmp .Lf34dfe_00034ff9\n"
        /* { scope 3 */
        ".Lf34dfe_00034fc1:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "movl 0x34(%eax, %edx, 4), %eax\n"
        "shrl $8, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        ".Lf34dfe_00034fd0:\n"
        "testl %eax, %eax\n" /* line 3114 */
        "je .Lf34dfe_000350cb\n"
        "movl iString, %ebx\n" /* line 3115 | c1 */
        "movl %ebx, %edx\n" /* c1 */
        "shll $6, %edx\n"
        "movzbl (%edi), %eax\n" /* c2 */
        "movb %al, szIwdLanguageName(%edx, %esi)\n"
        "addl $1, %esi\n"
        "cmpl $0x36, %esi\n" /* line 3114 */
        "je .Lf34dfe_00034f16\n"
        ".Lf34dfe_00034ff9:\n"
        "movl -0x28(%ebp), %eax\n" /* line 3122 | aa, b */
        "addl %esi, %eax\n" /* b */
        "leal 0xa(%eax), %edi\n" /* c2 */
        "movzbl 0xa(%eax), %eax\n" /* line 3114 */
        "testb %al, %al\n"
        "je .Lf34dfe_000350cb\n"
        "movsbl %al, %edx\n" /* _c */
        /* { scope 3 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf34dfe_00034fc1\n"
        "movl $0x100, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf34dfe_00034fd0\n"
        /* } scope */
        ".Lf34dfe_00035032:\n"
        "shll $6, %ebx\n" /* line 3113 | c1 */
        "leal szIwdLanguageName(%ebx), %eax\n" /* c1 */
        "movl $0x40, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "xorl %esi, %esi\n"
        "jmp .Lf34dfe_0003508b\n"
        /* { scope 3 */
        ".Lf34dfe_00035057:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "movl 0x34(%eax, %edx, 4), %eax\n"
        "shrl $8, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        ".Lf34dfe_00035066:\n"
        "testl %eax, %eax\n" /* line 3114 */
        "je .Lf34dfe_000350c0\n"
        "movl iString, %ebx\n" /* line 3115 | c1 */
        "movl %ebx, %edx\n" /* c1 */
        "shll $6, %edx\n"
        "movzbl (%edi), %eax\n" /* c2 */
        "movb %al, szIwdLanguageName(%edx, %esi)\n"
        "addl $1, %esi\n"
        "cmpl $0x36, %esi\n" /* line 3114 */
        "je .Lf34dfe_00034f53\n"
        ".Lf34dfe_0003508b:\n"
        "movl -0x24(%ebp), %eax\n" /* line 3122 | bb, b */
        "addl %esi, %eax\n" /* b */
        "leal 0xa(%eax), %edi\n" /* c2 */
        "movzbl 0xa(%eax), %eax\n" /* line 3114 */
        "testb %al, %al\n"
        "je .Lf34dfe_000350c0\n"
        "movsbl %al, %edx\n" /* _c */
        /* { scope 3 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf34dfe_00035057\n"
        "movl $0x100, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf34dfe_00035066\n"
        ".Lf34dfe_000350c0:\n"
        "movl iString, %ebx\n"
        "jmp .Lf34dfe_00034f53\n"
        ".Lf34dfe_000350cb:\n"
        "movl iString, %ebx\n"
        "jmp .Lf34dfe_00034f16\n"
        /* } scope */
        ".Lf34dfe_000350d6:\n"
        "movl $str_0021699c, 4(%esp)\n" /* line 3140 */
        "movl %ebx, (%esp)\n" /* pszLanguageB */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf34dfe_00034e59\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        "movl $0xffffffff, %eax\n" /* line 2949 */
        "jmp .Lf34dfe_00034ed0\n"
    );
}

/* line 3184 */
static __attribute__((naked))
float FS_AddIwdFilesForGameDirectory(const char *path, const char *pszGameFolder)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3184 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x12cc, %esp\n"
        /* { scope 1: basename, pszIwdFileName */
        "movl $0, 4(%esp)\n" /* line 697 */
        "leal -0x178(%ebp), %eax\n" /* iwdfile */
        "movl %eax, (%esp)\n"
        "movl $str_002157b8, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* pszGameFolder */
        "movl 8(%ebp), %eax\n" /* path */
        "calll FS_BuildOSPath_Internal\n"
        "cld\n" /* line 3203 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x178(%ebp), %edi\n" /* iwdfile */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -0x17a(%ecx, %ebp)\n"
        "movl $0, 0x10(%esp)\n" /* line 3205 */
        "leal -0x1c(%ebp), %eax\n" /* numfiles */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_00216ffc, 4(%esp)\n" /* "iwd" */
        "leal -0x178(%ebp), %edx\n" /* iwdfile */
        "movl %edx, (%esp)\n"
        "calll Sys_ListFiles\n"
        "movl %eax, -0x12b0(%ebp)\n" /* iwdfiles */
        "movl -0x1c(%ebp), %eax\n" /* line 3209 | numfiles */
        "cmpl $0x400, %eax\n"
        "jg .Lf350f8_00035925\n"
        ".Lf350f8_00035180:\n"
        "movl %eax, %edx\n" /* line 3215 */
        "testl %eax, %eax\n"
        "jg .Lf350f8_000358be\n"
        "leal -0x1278(%ebp), %edi\n" /* sorted */
        ".Lf350f8_00035190:\n"
        "movl $iwdsort, 0xc(%esp)\n" /* line 3224 */
        "movl $4, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll qsort\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 3226 | numfiles, i */
        "testl %ebx, %ebx\n" /* i */
        "jg .Lf350f8_000351cc\n"
        ".Lf350f8_000351b3:\n"
        "movl -0x12b0(%ebp), %eax\n" /* line 3295 | iwdfiles */
        "movl %eax, (%esp)\n"
        "calll Sys_FreeFileList\n"
        /* } scope */
        "addl $0x12cc, %esp\n" /* line 3296 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: basename, pszIwdFileName */
        ".Lf350f8_000351cc:\n"
        "movl $1, -0x1284(%ebp)\n" /* line 3226 */
        "addl $4, %edi\n"
        "movl %edi, -0x12b8(%ebp)\n"
        "movl %edi, %ecx\n"
        "jmp .Lf350f8_0003527f\n"
        ".Lf350f8_000351e6:\n"
        "movl $0, -0x20(%ebp)\n" /* line 3276 | iIwdLanguage */
        "movl $0, -0x12b4(%ebp)\n" /* bIwdLocalized */
        ".Lf350f8_000351f7:\n"
        "movl $0, 4(%esp)\n" /* line 697 */
        "leal -0x178(%ebp), %ecx\n" /* iwdfile */
        "movl %ecx, (%esp)\n"
        "movl -0x12b8(%ebp), %eax\n"
        "movl -4(%eax), %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* pszGameFolder */
        "movl 8(%ebp), %eax\n" /* path */
        "calll FS_BuildOSPath_Internal\n"
        "movl -0x12b8(%ebp), %edx\n"
        "movl -4(%edx), %edx\n"
        "movl %edx, -0x12a8(%ebp)\n" /* basename */
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        /* { scope 3: hashSize */
        "leal -0x178(%ebp), %ecx\n" /* line 2337 | iwdfile */
        "movl %ecx, (%esp)\n"
        "calll unzOpen\n"
        "movl %eax, -0x12a0(%ebp)\n" /* uf */
        "leal -0x28(%ebp), %eax\n" /* line 2338 | gi */
        "movl %eax, 4(%esp)\n"
        "movl -0x12a0(%ebp), %eax\n" /* uf */
        "movl %eax, (%esp)\n"
        "calll unzGetGlobalInfo\n"
        "testl %eax, %eax\n" /* line 2340 */
        "je .Lf350f8_00035344\n"
        /* } scope */
        /* } scope */
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        ".Lf350f8_0003525c:\n"
        "movl -0x1284(%ebp), %eax\n" /* line 3172 */
        "addl $1, -0x1284(%ebp)\n"
        "addl $4, -0x12b8(%ebp)\n"
        /* } scope */
        "cmpl -0x1c(%ebp), %eax\n" /* line 3226 | numfiles */
        "jge .Lf350f8_000351b3\n"
        "movl -0x12b8(%ebp), %ecx\n"
        ".Lf350f8_0003527f:\n"
        "movl $0xa, 8(%esp)\n" /* line 3229 */
        "movl $str_00216ff0, 4(%esp)\n" /* "          " */
        "movl -4(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lf350f8_000351e6\n"
        "movl -0x12b8(%ebp), %edx\n" /* line 3231 */
        "movl -4(%edx), %eax\n"
        "movl $0x61636f6c, (%eax)\n"
        "movl $0x657a696c, 4(%eax)\n"
        "movw $0x5f64, 8(%eax)\n"
        "movl -4(%edx), %ecx\n"
        "movl %ecx, -0x12ac(%ebp)\n" /* pszIwdFileName */
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        "movl iString, %ebx\n" /* line 3104 | i */
        "xorl $1, %ebx\n" /* i */
        "movl %ebx, iString\n" /* i */
        "cld\n" /* line 3106 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x12ac(%ebp), %edi\n" /* pszIwdFileName */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $9, %ecx\n"
        "ja .Lf350f8_00035568\n"
        "movl %ebx, %eax\n" /* line 3108 | i */
        "shll $6, %eax\n"
        "movb $0, szIwdLanguageName(%eax)\n"
        ".Lf350f8_00035300:\n"
        "movl %ebx, %eax\n" /* line 3118 | i */
        "shll $6, %eax\n"
        "leal szIwdLanguageName(%eax), %edx\n"
        /* } scope */
        "cmpb $0, szIwdLanguageName(%eax)\n" /* line 3239 */
        "jne .Lf350f8_00035518\n"
        "movl -0x12b8(%ebp), %ecx\n" /* line 3241 */
        "movl -4(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pszGameFolder */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* path */
        "movl %edx, 4(%esp)\n"
        "movl $str_00217048, (%esp)\n" /* "WARNING: Localized assets iwd file %s/%s/%s has invalid name" */
        "calll Com_Printf\n"
        "jmp .Lf350f8_0003525c\n"
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        /* { scope 3: hashSize */
        ".Lf350f8_00035344:\n"
        "movl -0x28(%ebp), %eax\n" /* line 2343 | gi */
        "addl %eax, fs_packFiles\n"
        "movl -0x12a0(%ebp), %edx\n" /* line 2346 | uf */
        "movl %edx, (%esp)\n"
        "calll unzGoToFirstFile\n"
        "movl -0x28(%ebp), %eax\n" /* line 2347 | gi */
        "testl %eax, %eax\n"
        "jne .Lf350f8_0003583f\n"
        "xorl %edx, %edx\n"
        ".Lf350f8_00035368:\n"
        "movl -0x28(%ebp), %eax\n" /* line 2358 | gi */
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, -0x12a4(%ebp)\n" /* buildBuffer */
        "movl -0x28(%ebp), %eax\n" /* line 2359 | gi */
        "leal (%eax, %eax, 2), %edx\n"
        "movl -0x12a4(%ebp), %ecx\n" /* buildBuffer */
        "leal (%ecx, %edx, 4), %edx\n"
        "movl %edx, -0x1294(%ebp)\n" /* namePtr */
        "shll $2, %eax\n" /* line 2360 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, -0x1298(%ebp)\n" /* fs_headerLongs */
        "movl -0x28(%ebp), %edx\n" /* line 2366 | gi */
        "movl $1, %edi\n"
        "movl $0xb, %eax\n"
        ".Lf350f8_000353b2:\n"
        "cmpl %edi, %edx\n"
        "jb .Lf350f8_000353bd\n"
        "addl %edi, %edi\n" /* line 2364 */
        "subl $1, %eax\n"
        "jne .Lf350f8_000353b2\n"
        ".Lf350f8_000353bd:\n"
        "leal 0x320(, %edi, 4), %eax\n" /* line 2372 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %esi\n" /* len */
        "movl %edi, 0x314(%eax)\n" /* line 2373 */
        "leal 0x320(%eax), %eax\n" /* line 2374 */
        "movl %eax, 0x318(%esi)\n" /* len */
        "testl %edi, %edi\n" /* line 2375 */
        "je .Lf350f8_000353fe\n"
        "xorl %edx, %edx\n"
        ".Lf350f8_000353e6:\n"
        "movl 0x318(%esi), %eax\n" /* line 2377 | len */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 2375 */
        "cmpl %edx, 0x314(%esi)\n" /* len */
        "ja .Lf350f8_000353e6\n"
        ".Lf350f8_000353fe:\n"
        "movl $0x100, 8(%esp)\n" /* line 2380 */
        "leal -0x178(%ebp), %eax\n" /* iwdfile */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* len */
        "calll I_strncpyz\n"
        "leal 0x100(%esi), %ebx\n" /* line 2381 | len, i */
        "movl $0x100, 8(%esp)\n"
        "movl -0x12a8(%ebp), %edx\n" /* basename */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll I_strncpyz\n"
        "cld\n" /* line 2384 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* i */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "cmpl $4, %eax\n"
        "ja .Lf350f8_0003580a\n"
        ".Lf350f8_00035452:\n"
        "movl -0x12a0(%ebp), %edx\n" /* line 2389 | uf */
        "movl %edx, 0x300(%esi)\n" /* len */
        "movl -0x28(%ebp), %eax\n" /* line 2390 | gi */
        "movl %eax, 0x30c(%esi)\n" /* len */
        "movl %edx, (%esp)\n" /* line 2391 */
        "calll unzGoToFirstFile\n"
        "movl -0x28(%ebp), %eax\n" /* line 2393 | gi */
        "testl %eax, %eax\n"
        "jne .Lf350f8_00035607\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf350f8_0003547c:\n"
        "movl %ebx, 4(%esp)\n" /* line 2418 | i */
        "movl -0x1298(%ebp), %ecx\n" /* fs_headerLongs */
        "movl %ecx, (%esp)\n"
        "calll Com_BlockChecksum\n"
        "movl %eax, 0x304(%esi)\n" /* len */
        "movl fs_checksumFeed, %eax\n" /* line 2419 */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl -0x1298(%ebp), %eax\n" /* fs_headerLongs */
        "movl %eax, (%esp)\n"
        "calll Com_BlockChecksumKey\n"
        "movl %eax, 0x308(%esi)\n" /* len */
        "movl -0x1298(%ebp), %edx\n" /* line 2428 | fs_headerLongs */
        "movl %edx, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl -0x12a4(%ebp), %ecx\n" /* line 2430 | buildBuffer */
        "movl %ecx, 0x31c(%esi)\n" /* len */
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 3284 | pszGameFolder */
        "movl %eax, 4(%esp)\n"
        "leal 0x200(%esi), %eax\n" /* iwd */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl $0x14, (%esp)\n" /* line 3286 */
        "calll Z_MallocInternal\n"
        "movl %eax, %edx\n"
        "movl %esi, 4(%eax)\n" /* line 3287 | iwd */
        "movl -0x12b4(%ebp), %ecx\n" /* line 3289 | bIwdLocalized */
        "movl %ecx, 0xc(%eax)\n"
        "movl -0x20(%ebp), %eax\n" /* line 3290 | iIwdLanguage */
        "movl %eax, 0x10(%edx)\n"
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        "testl %ecx, %ecx\n" /* line 3165 */
        "jne .Lf350f8_0003553e\n"
        ".Lf350f8_00035508:\n"
        "movl $fs_searchpaths, %ecx\n"
        "movl (%ecx), %eax\n"
        ".Lf350f8_0003550f:\n"
        "movl %eax, (%edx)\n" /* line 3171 */
        "movl %edx, (%ecx)\n" /* line 3172 */
        "jmp .Lf350f8_0003525c\n"
        /* } scope */
        ".Lf350f8_00035518:\n"
        "leal -0x20(%ebp), %eax\n" /* line 3252 | iIwdLanguage */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SEH_GetLanguageIndexForName\n"
        "testl %eax, %eax\n"
        "je .Lf350f8_0003595c\n"
        "movl $1, -0x12b4(%ebp)\n" /* bIwdLocalized */
        "jmp .Lf350f8_000351f7\n"
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        ".Lf350f8_0003553e:\n"
        "movl fs_searchpaths, %eax\n" /* line 3167 */
        "testl %eax, %eax\n"
        "je .Lf350f8_00035508\n"
        "movl 0xc(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf350f8_00035508\n"
        ".Lf350f8_0003554e:\n"
        "movl %eax, %ecx\n" /* line 3168 */
        "movl (%eax), %eax\n" /* line 3167 */
        "testl %eax, %eax\n"
        "je .Lf350f8_0003550f\n"
        "movl 0xc(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf350f8_0003554e\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n" /* line 3171 */
        "movl %edx, (%ecx)\n" /* line 3172 */
        "jmp .Lf350f8_0003525c\n"
        /* } scope */
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        ".Lf350f8_00035568:\n"
        "shll $6, %ebx\n" /* line 3113 | i */
        "leal szIwdLanguageName(%ebx), %eax\n" /* i */
        "movl $0x40, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "xorl %esi, %esi\n" /* len */
        "jmp .Lf350f8_000355c1\n"
        /* { scope 3: hashSize */
        ".Lf350f8_0003558d:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "movl 0x34(%eax, %edx, 4), %eax\n"
        "shrl $8, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 3114 */
        "je .Lf350f8_000355fc\n"
        ".Lf350f8_000355a0:\n"
        "movl iString, %ebx\n" /* line 3115 | i */
        "movl %ebx, %edx\n" /* i */
        "shll $6, %edx\n"
        "movzbl (%edi), %eax\n"
        "movb %al, szIwdLanguageName(%edx, %esi)\n"
        "addl $1, %esi\n" /* len */
        "cmpl $0x36, %esi\n" /* line 3114 | len */
        "je .Lf350f8_00035300\n"
        ".Lf350f8_000355c1:\n"
        "movl -0x12ac(%ebp), %edx\n" /* line 3184 | pszIwdFileName */
        "leal (%esi, %edx), %eax\n" /* len */
        "leal 0xa(%eax), %edi\n"
        "movzbl 0xa(%eax), %eax\n" /* line 3114 */
        "testb %al, %al\n"
        "je .Lf350f8_000355fc\n"
        "movsbl %al, %edx\n" /* _c */
        /* { scope 3: hashSize */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf350f8_0003558d\n"
        "movl $0x100, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 3114 */
        "jne .Lf350f8_000355a0\n"
        ".Lf350f8_000355fc:\n"
        "movl iString, %ebx\n" /* i */
        "jmp .Lf350f8_00035300\n"
        /* } scope */
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        /* { scope 3: hashSize */
        ".Lf350f8_00035607:\n"
        "movl -0x12a4(%ebp), %ecx\n" /* line 2393 | buildBuffer */
        "movl %ecx, -0x1288(%ebp)\n"
        "movl $0, -0x1280(%ebp)\n"
        "movl $0, -0x129c(%ebp)\n" /* fs_numHeaderLongs */
        "jmp .Lf350f8_000356fd\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lf350f8_0003562c:\n"
        "movl $0, -0x127c(%ebp)\n" /* line 467 */
        "movl $0, -0x128c(%ebp)\n"
        "xorl %ebx, %ebx\n"
        /* } scope */
        /* } scope */
        ".Lf350f8_00035642:\n"
        "movl -0x1294(%ebp), %ecx\n" /* line 2406 | namePtr */
        "movl -0x1288(%ebp), %edx\n"
        "movl %ecx, 4(%edx)\n"
        "leal -0x278(%ebp), %eax\n" /* line 2407 | filename_inzip */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 2408 */
        "xorl %eax, %eax\n"
        "movl $0xffffffff, %ecx\n"
        "leal -0x278(%ebp), %edi\n" /* filename_inzip */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl %ecx, -0x1294(%ebp)\n" /* namePtr */
        "movl -0x1288(%ebp), %edx\n" /* line 2410 */
        "movl %edx, 4(%esp)\n"
        "movl -0x12a0(%ebp), %ecx\n" /* uf */
        "movl %ecx, (%esp)\n"
        "calll unzGetCurrentFileInfoPosition\n"
        "movl -0x127c(%ebp), %eax\n" /* line 2412 */
        "xorl %eax, -0x128c(%ebp)\n"
        "xorl -0x128c(%ebp), %ebx\n" /* i */
        "movl -0x1290(%ebp), %eax\n" /* hashSize */
        "subl $1, %eax\n"
        "andl %eax, %ebx\n" /* i */
        "leal (, %ebx, 4), %edx\n"
        "movl 0x318(%esi), %eax\n" /* len */
        "movl (%eax, %edx), %eax\n"
        "movl -0x1288(%ebp), %ecx\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0x318(%esi), %eax\n" /* line 2413 | len */
        "movl %ecx, (%edx, %eax)\n"
        "movl -0x12a0(%ebp), %eax\n" /* line 2414 | uf */
        "movl %eax, (%esp)\n"
        "calll unzGoToNextFile\n"
        "addl $1, -0x1280(%ebp)\n" /* line 2393 */
        "addl $0xc, -0x1288(%ebp)\n"
        "movl -0x1280(%ebp), %edx\n"
        "cmpl -0x28(%ebp), %edx\n" /* gi */
        "jae .Lf350f8_000357fc\n"
        ".Lf350f8_000356fd:\n"
        "movl $0, 0x1c(%esp)\n" /* line 2395 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x100, 0xc(%esp)\n"
        "leal -0x278(%ebp), %eax\n" /* filename_inzip */
        "movl %eax, 8(%esp)\n"
        "leal -0x78(%ebp), %edx\n" /* file_info */
        "movl %edx, 4(%esp)\n"
        "movl -0x12a0(%ebp), %ecx\n" /* uf */
        "movl %ecx, (%esp)\n"
        "calll unzGetCurrentFileInfo\n"
        "testl %eax, %eax\n" /* line 2396 */
        "jne .Lf350f8_000357fc\n"
        "movl -0x5c(%ebp), %eax\n" /* line 2400 */
        "testl %eax, %eax\n"
        "je .Lf350f8_0003576e\n"
        "movl -0x64(%ebp), %eax\n" /* line 2402 */
        "movl -0x129c(%ebp), %edx\n" /* fs_numHeaderLongs */
        "movl -0x1298(%ebp), %ecx\n" /* fs_headerLongs */
        "movl %eax, (%ecx, %edx, 4)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x129c(%ebp)\n" /* fs_numHeaderLongs */
        ".Lf350f8_0003576e:\n"
        "leal -0x278(%ebp), %eax\n" /* line 2404 | filename_inzip */
        "movl %eax, (%esp)\n"
        "calll I_strlwr\n"
        "movl 0x314(%esi), %edx\n" /* line 2405 | len */
        "movl %edx, -0x1290(%ebp)\n" /* hashSize */
        /* { scope 4 */
        /* { scope 5 */
        "movzbl -0x278(%ebp), %eax\n" /* line 467 | filename_inzip */
        "testb %al, %al\n"
        "je .Lf350f8_0003562c\n"
        "movl $0, -0x127c(%ebp)\n"
        "movl $0x77, %ebx\n"
        ".Lf350f8_000357a6:\n"
        "movsbl %al, %eax\n" /* line 469 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %eax, %edx\n"
        "cmpl $0x2e, %eax\n" /* line 470 */
        "je .Lf350f8_000359cd\n"
        "cmpl $0x5c, %eax\n" /* line 473 */
        "movl $0x2f, %eax\n"
        "cmovel %eax, %edx\n"
        "imull %ebx, %edx\n" /* line 478 */
        "addl %edx, -0x127c(%ebp)\n"
        "movzbl -0x2ee(%ebx, %ebp), %eax\n" /* line 467 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf350f8_000357a6\n"
        "movl -0x127c(%ebp), %eax\n"
        "sarl $0xa, %eax\n"
        "movl %eax, -0x128c(%ebp)\n"
        "movl -0x127c(%ebp), %ebx\n"
        "sarl $0x14, %ebx\n"
        "jmp .Lf350f8_00035642\n"
        /* } scope */
        /* } scope */
        ".Lf350f8_000357fc:\n"
        "movl -0x129c(%ebp), %ebx\n" /* line 2393 | fs_numHeaderLongs, i */
        "shll $2, %ebx\n" /* i */
        "jmp .Lf350f8_0003547c\n"
        ".Lf350f8_0003580a:\n"
        "movl $str_00217198, 4(%esp)\n" /* line 2384 */
        "leal -4(%ebx, %eax), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf350f8_00035452\n"
        "cld\n" /* line 2386 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* i */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, 0xfb(%ecx, %esi)\n"
        "jmp .Lf350f8_00035452\n"
        ".Lf350f8_0003583f:\n"
        "xorl %ebx, %ebx\n" /* line 2347 | i */
        "xorl %esi, %esi\n" /* len */
        ".Lf350f8_00035843:\n"
        "movl $0, 0x1c(%esp)\n" /* line 2349 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x100, 0xc(%esp)\n"
        "leal -0x278(%ebp), %ecx\n" /* filename_inzip */
        "movl %ecx, 8(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* file_info */
        "movl %eax, 4(%esp)\n"
        "movl -0x12a0(%ebp), %edx\n" /* uf */
        "movl %edx, (%esp)\n"
        "calll unzGetCurrentFileInfo\n"
        "testl %eax, %eax\n" /* line 2350 */
        "jne .Lf350f8_000358b7\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x278(%ebp), %edi\n" /* filename_inzip */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal (%ecx, %esi), %esi\n"
        "movl -0x12a0(%ebp), %edx\n" /* line 2355 | uf */
        "movl %edx, (%esp)\n"
        "calll unzGoToNextFile\n"
        "addl $1, %ebx\n" /* line 2347 | i */
        "cmpl %ebx, -0x28(%ebp)\n" /* i, gi */
        "ja .Lf350f8_00035843\n"
        ".Lf350f8_000358b7:\n"
        "movl %esi, %edx\n" /* len */
        "jmp .Lf350f8_00035368\n"
        /* } scope */
        /* } scope */
        ".Lf350f8_000358be:\n"
        "movl $1, %ebx\n" /* line 3215 | i */
        "leal -0x1278(%ebp), %edi\n" /* sorted */
        "leal -0x1274(%ebp), %esi\n" /* iwd */
        "jmp .Lf350f8_000358e4\n"
        ".Lf350f8_000358d1:\n"
        "movl %ebx, %eax\n" /* line 3221 | i */
        "movl -0x1c(%ebp), %edx\n" /* line 3215 | numfiles */
        "addl $1, %ebx\n" /* i */
        "addl $4, %esi\n" /* iwd */
        "cmpl %eax, %edx\n"
        "jle .Lf350f8_00035190\n"
        ".Lf350f8_000358e4:\n"
        "movl -0x12b0(%ebp), %edx\n" /* line 3217 | iwdfiles */
        "movl -4(%edx, %ebx, 4), %eax\n"
        "movl %eax, -4(%esi)\n" /* iwd */
        "movl $0xa, 8(%esp)\n" /* line 3220 */
        "movl $str_0021703c, 4(%esp)\n" /* "localized_" */
        "movl %eax, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lf350f8_000358d1\n"
        "movl -4(%esi), %eax\n" /* line 3221 | iwd */
        "movl $0x20202020, (%eax)\n"
        "movl $0x20202020, 4(%eax)\n"
        "movw $0x2020, 8(%eax)\n"
        "jmp .Lf350f8_000358d1\n"
        ".Lf350f8_00035925:\n"
        "movl $0x400, 0x10(%esp)\n" /* line 3211 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* pszGameFolder */
        "movl %ecx, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* path */
        "movl %eax, 4(%esp)\n"
        "movl $str_00217000, (%esp)\n" /* "WARNING: Exceeded max number of iwd files in %s/%s (%1/%1)
" */
        "calll Com_Printf\n"
        "movl $0x400, -0x1c(%ebp)\n" /* line 3212 | numfiles */
        "movl $0x400, %eax\n"
        "jmp .Lf350f8_00035180\n"
        ".Lf350f8_0003595c:\n"
        "movl -0x12b8(%ebp), %ecx\n" /* line 3254 */
        "movl -4(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pszGameFolder */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* path */
        "movl %edx, 4(%esp)\n"
        "movl $str_002170dc, (%esp)\n" /* "WARNING: Localized assets iwd file %s/%s/%s has invalid name" */
        "calll Com_Printf\n"
        "movl bLanguagesListed, %eax\n" /* line 3257 */
        "testl %eax, %eax\n"
        "jne .Lf350f8_0003525c\n"
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        "movl $str_00217174, (%esp)\n" /* line 3261 */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* iSuppLang */
        ".Lf350f8_0003599e:\n"
        "movl %ebx, (%esp)\n" /* line 3264 | iSuppLang */
        "calll SEH_GetLanguageName\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00217190, (%esp)\n" /* "    %s
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 3263 | iSuppLang */
        "cmpl $0xe, %ebx\n" /* iSuppLang */
        "jne .Lf350f8_0003599e\n"
        "movl $1, bLanguagesListed\n" /* line 3266 */
        "jmp .Lf350f8_0003525c\n"
        /* } scope */
        /* { scope 2: buildBuffer, uf, gi, filename_inzip, ... */
        /* { scope 3: hashSize */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf350f8_000359cd:\n"
        "movl -0x127c(%ebp), %ecx\n" /* line 470 */
        "sarl $0xa, %ecx\n"
        "movl %ecx, -0x128c(%ebp)\n"
        "movl -0x127c(%ebp), %ebx\n"
        "sarl $0x14, %ebx\n"
        "jmp .Lf350f8_00035642\n"
    );
}

/* line 3308 */
static __attribute__((naked))
float FS_AddGameDirectory(int iLanguage)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3308 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x16c, %esp\n"
        "movl %eax, %ebx\n" /* path */
        "movl %edx, %edi\n" /* dir */
        "movl %ecx, %esi\n" /* bLanguageDirectory */
        /* { scope 1: ospath */
        "testl %ecx, %ecx\n" /* line 3315 */
        "je .Lf359ea_00035bcb\n"
        "movl 8(%ebp), %eax\n" /* line 3321 | iLanguage */
        "movl %eax, (%esp)\n"
        "calll SEH_GetLanguageName\n"
        "movl %eax, 0x10(%esp)\n" /* line 3323 */
        "movl %edi, 0xc(%esp)\n" /* search */
        "movl $str_00216e18, 8(%esp)\n" /* "%s/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x58(%ebp), %edi\n" /* szGameFolder, search */
        "movl %edi, (%esp)\n" /* search */
        "calll Com_sprintf\n"
        ".Lf359ea_00035a32:\n"
        "movl fs_searchpaths, %edi\n" /* line 3332 | search */
        "testl %edi, %edi\n" /* search */
        "jne .Lf359ea_00035a4b\n"
        "jmp .Lf359ea_00035ae1\n"
        ".Lf359ea_00035a41:\n"
        "movl (%edi), %edi\n" /* search */
        "testl %edi, %edi\n" /* search */
        "je .Lf359ea_00035ae1\n"
        ".Lf359ea_00035a4b:\n"
        "movl 8(%edi), %eax\n" /* line 3334 | search */
        "testl %eax, %eax\n"
        "je .Lf359ea_00035a41\n"
        "movl %ebx, 4(%esp)\n" /* path */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf359ea_00035a41\n"
        "leal -0x58(%ebp), %eax\n" /* szGameFolder */
        "movl %eax, 4(%esp)\n"
        "movl 8(%edi), %eax\n" /* search */
        "addl $0x100, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf359ea_00035a41\n"
        "movl 0xc(%edi), %edx\n" /* line 3337 | search */
        "cmpl %edx, %esi\n" /* bLanguageDirectory */
        "je .Lf359ea_00035aae\n"
        "movl $str_002171a0, %eax\n" /* line 3338 */
        "testl %edx, %edx\n"
        "movl $str_002171ac, %edx\n" /* "non-localized" */
        "cmovel %edx, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* szGameFolder */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* path */
        "movl $str_002171bc, (%esp)\n" /* "WARNING: game folder %s/%s added as both localized & non-loc" */
        "calll Com_Printf\n"
        ".Lf359ea_00035aae:\n"
        "movl 0xc(%edi), %esi\n" /* line 3341 | search, bLanguageDirectory */
        "testl %esi, %esi\n" /* bLanguageDirectory */
        "je .Lf359ea_00035bc0\n"
        "movl 8(%ebp), %eax\n" /* iLanguage */
        "cmpl 0x10(%edi), %eax\n" /* search */
        "je .Lf359ea_00035bc0\n"
        "leal -0x58(%ebp), %edi\n" /* line 3342 | szGameFolder, search */
        "movl %edi, 8(%esp)\n" /* search */
        "movl %ebx, 4(%esp)\n" /* path */
        "movl $str_00217214, (%esp)\n" /* "WARNING: game golder %s/%s re-added as localized folder with" */
        "calll Com_Printf\n"
        "jmp .Lf359ea_00035bc0\n"
        ".Lf359ea_00035ae1:\n"
        "testl %esi, %esi\n" /* line 3348 | bLanguageDirectory */
        "je .Lf359ea_00035bfa\n"
        /* { scope 2 */
        "movl $0, 4(%esp)\n" /* line 697 */
        "leal -0x158(%ebp), %eax\n" /* ospath */
        "movl %eax, (%esp)\n"
        "movl $str_002157b8, %ecx\n"
        "leal -0x58(%ebp), %edx\n" /* szGameFolder */
        "movl %ebx, %eax\n"
        "calll FS_BuildOSPath_Internal\n"
        "cld\n" /* line 3353 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x158(%ebp), %edi\n" /* ospath, search */
        "repne scasb %es:(%edi), %al\n" /* search */
        "notl %ecx\n"
        "movb $0, -0x15a(%ecx, %ebp)\n"
        "leal -0x158(%ebp), %eax\n" /* line 3355 | ospath */
        "movl %eax, (%esp)\n"
        "calll Sys_DirectoryHasContents\n"
        "testl %eax, %eax\n"
        "je .Lf359ea_00035bc0\n"
        /* } scope */
        ".Lf359ea_00035b39:\n"
        "movl $0x14, (%esp)\n" /* line 3366 */
        "calll Z_MallocInternal\n"
        "movl %eax, %edi\n" /* search */
        "movl $0x200, (%esp)\n" /* line 3367 */
        "calll Z_MallocInternal\n"
        "movl %eax, 8(%edi)\n" /* search */
        "movl $0x100, 8(%esp)\n" /* line 3369 */
        "movl %ebx, 4(%esp)\n" /* path */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x100, 8(%esp)\n" /* line 3370 */
        "leal -0x58(%ebp), %eax\n" /* szGameFolder */
        "movl %eax, 4(%esp)\n"
        "movl 8(%edi), %eax\n" /* search */
        "addl $0x100, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %esi, 0xc(%edi)\n" /* line 3374 | bLanguageDirectory, search */
        "movl 8(%ebp), %eax\n" /* line 3375 | iLanguage */
        "movl %eax, 0x10(%edi)\n" /* search */
        /* { scope 2 */
        "testl %esi, %esi\n" /* line 3165 */
        "je .Lf359ea_00035ba6\n"
        "movl fs_searchpaths, %eax\n" /* line 3167 */
        "testl %eax, %eax\n"
        "je .Lf359ea_00035ba6\n"
        "movl 0xc(%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf359ea_00035be7\n"
        ".Lf359ea_00035ba6:\n"
        "movl $fs_searchpaths, %edx\n"
        "movl (%edx), %eax\n"
        ".Lf359ea_00035bad:\n"
        "movl %eax, (%edi)\n" /* line 3171 */
        "movl %edi, (%edx)\n" /* line 3172 */
        /* } scope */
        "leal -0x58(%ebp), %edi\n" /* line 3380 | szGameFolder, search */
        "movl %edi, 4(%esp)\n" /* search */
        "movl %ebx, (%esp)\n" /* path */
        "calll FS_AddIwdFilesForGameDirectory\n"
        /* } scope */
        ".Lf359ea_00035bc0:\n"
        "addl $0x16c, %esp\n" /* line 3381 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ospath */
        ".Lf359ea_00035bcb:\n"
        "movl $0x40, 8(%esp)\n" /* line 3327 */
        "movl %edx, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* szGameFolder */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf359ea_00035a32\n"
        /* { scope 2 */
        ".Lf359ea_00035be7:\n"
        "movl %eax, %edx\n" /* line 3168 */
        "movl (%eax), %eax\n" /* line 3167 */
        "testl %eax, %eax\n"
        "je .Lf359ea_00035bad\n"
        "movl 0xc(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf359ea_00035be7\n"
        "movl (%edx), %eax\n"
        "jmp .Lf359ea_00035bad\n"
        /* } scope */
        ".Lf359ea_00035bfa:\n"
        "movl $0x100, 8(%esp)\n" /* line 3360 */
        "leal -0x58(%ebp), %edi\n" /* szGameFolder, search */
        "movl %edi, 4(%esp)\n" /* search */
        "movl $fs_gamedir, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf359ea_00035b39\n"
    );
}

/* line 749 */
__attribute__((naked))
float FS_CopyFile(char *fromOSPath, char *toOSPath)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 749 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* toOSPath */
        /* { scope 1 */
        "movl $str_00215b98, 4(%esp)\n" /* line 755 */
        "movl 8(%ebp), %eax\n" /* fromOSPath */
        "movl %eax, (%esp)\n"
        "calll FS_FileOpen\n"
        "movl %eax, %ebx\n" /* f */
        "testl %eax, %eax\n" /* line 756 */
        "je .Lf35c1a_00035cf6\n"
        "movl $2, 8(%esp)\n" /* line 760 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "movl %ebx, (%esp)\n" /* line 761 | f */
        "calll ftell\n"
        "movl %eax, %edi\n" /* len */
        "movl $0, 8(%esp)\n" /* line 762 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* f */
        "calll FS_FileSeek\n"
        "movl %edi, (%esp)\n" /* line 766 | len */
        "calll malloc\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, 0xc(%esp)\n" /* line 767 | f */
        "movl %edi, 8(%esp)\n" /* len */
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "cmpl %eax, %edi\n" /* len */
        "je .Lf35c1a_00035cb8\n"
        "movl $str_00217268, 4(%esp)\n" /* line 768 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf35c1a_00035cb8:\n"
        "movl %ebx, (%esp)\n" /* line 769 | f */
        "calll FS_FileClose\n"
        /* { scope 2 */
        "movl $str_00216ca0, 4(%esp)\n" /* line 715 */
        "movl %esi, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf35c1a_00035cfe\n"
        ".Lf35c1a_00035cd4:\n"
        "movl %esi, 4(%esp)\n" /* line 717 */
        "movl $str_00216ca4, (%esp)\n" /* "WARNING: refusing to create relative path "%s"
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf35c1a_00035ce4:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 786 */
        "movl %eax, 8(%ebp)\n" /* fromOSPath */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 787 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp free\n" /* line 786 */
        /* } scope */
        ".Lf35c1a_00035cf6:\n"
        "addl $0x2c, %esp\n" /* line 787 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf35c1a_00035cfe:\n"
        "movl $str_00215bf8, 4(%esp)\n" /* line 715 */
        "movl %esi, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "jne .Lf35c1a_00035cd4\n"
        "leal 1(%esi), %edx\n" /* line 721 */
        "movzbl 1(%esi), %eax\n"
        "testb %al, %al\n"
        "je .Lf35c1a_00035d40\n"
        "movl %edx, %ebx\n"
        "jmp .Lf35c1a_00035d2c\n"
        ".Lf35c1a_00035d21:\n"
        "movzbl 1(%ebx), %eax\n"
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "je .Lf35c1a_00035d40\n"
        ".Lf35c1a_00035d2c:\n"
        "cmpb $0x2f, %al\n" /* line 723 */
        "jne .Lf35c1a_00035d21\n"
        "movb $0, (%ebx)\n" /* line 726 */
        "movl %esi, (%esp)\n" /* line 727 */
        "calll Sys_Mkdir\n"
        "movb $0x2f, (%ebx)\n" /* line 728 */
        "jmp .Lf35c1a_00035d21\n"
        /* } scope */
        ".Lf35c1a_00035d40:\n"
        "movl $str_00216fec, 4(%esp)\n" /* line 777 */
        "movl %esi, (%esp)\n" /* toOSPath */
        "calll FS_FileOpen\n"
        "movl %eax, %ebx\n" /* f */
        "testl %eax, %eax\n" /* line 778 */
        "je .Lf35c1a_00035ce4\n"
        "movl %ebx, 0xc(%esp)\n" /* line 783 | f */
        "movl %edi, 8(%esp)\n" /* len */
        "movl $1, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileWrite\n"
        "cmpl %eax, %edi\n" /* len */
        "je .Lf35c1a_00035d89\n"
        "movl $str_00217288, 4(%esp)\n" /* line 784 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf35c1a_00035d89:\n"
        "movl %ebx, (%esp)\n" /* line 785 | f */
        "calll FS_FileClose\n"
        "jmp .Lf35c1a_00035ce4\n"
    );
}

/* line 1345 */
static __attribute__((naked))
int FS_FOpenFileRead_Internal(const char *filename, fileHandle_t *file, qboolean uniqueFILE, qboolean streamThread, qboolean fsOnly)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1345 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x35c, %esp\n"
        "movl %eax, -0x344(%ebp)\n"
        "movl %edx, -0x348(%ebp)\n"
        "movl %ecx, -0x34c(%ebp)\n"
        /* { scope 1: s2, extensions, s2 */
        "movl $0x100, %ecx\n" /* line 1369 */
        "leal -0x118(%ebp), %edx\n" /* sanitizedName */
        "calll FS_SanitizeFilename\n"
        "testb %al, %al\n"
        "je .Lf35d96_000365da\n"
        "movl -0x348(%ebp), %eax\n" /* line 1376 */
        "testl %eax, %eax\n"
        "je .Lf35d96_00036645\n"
        /* { scope 2 */
        "movl 8(%ebp), %esi\n" /* line 503 | streamThread, hash */
        "testl %esi, %esi\n" /* hash */
        "je .Lf35d96_00035fa2\n"
        "movl $0x3d, %esi\n" /* hash */
        "movl $0xd, %edi\n" /* count */
        ".Lf35d96_00035def:\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 516 | hash */
        "shll $3, %eax\n"
        "subl %esi, %eax\n" /* hash */
        "shll $2, %eax\n"
        "movl fsh(%eax), %ebx\n" /* first */
        "testl %ebx, %ebx\n" /* first */
        "je .Lf35d96_00035e2c\n"
        /* } scope */
        "leal fsh(%eax), %ecx\n" /* line 1467 */
        "xorl %edx, %edx\n"
        /* { scope 2 */
        ".Lf35d96_00035e0c:\n"
        "addl $1, %edx\n" /* line 514 */
        "cmpl %edx, %edi\n" /* count */
        "je .Lf35d96_000363cf\n"
        "leal (%edx, %esi), %ebx\n" /* line 516 | first */
        "movl 0x11c(%ecx), %eax\n"
        "addl $0x11c, %ecx\n"
        "testl %eax, %eax\n"
        "jne .Lf35d96_00035e0c\n"
        "movl %ebx, %esi\n" /* first, hash */
        /* } scope */
        ".Lf35d96_00035e2c:\n"
        "movl -0x348(%ebp), %ecx\n" /* line 1427 */
        "movl %esi, (%ecx)\n" /* zfi */
        "leal (%esi, %esi, 8), %eax\n" /* line 1428 | zfi */
        "shll $3, %eax\n"
        "subl %esi, %eax\n" /* zfi */
        "movl -0x34c(%ebp), %ebx\n" /* c2 */
        "movl %ebx, fsh+4(, %eax, 4)\n" /* c2 */
        "movl fs_searchpaths, %eax\n" /* line 1431 */
        "movl %eax, -0x31c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf35d96_00036770\n"
        "movb $0, -0x329(%ebp)\n" /* wasSkipped */
        "movl $0, -0x330(%ebp)\n" /* impureIwd */
        "jmp .Lf35d96_00035e94\n"
        ".Lf35d96_00035e6f:\n"
        "movl fs_ignoreLocalized, %eax\n" /* line 417 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf35d96_000362b3\n"
        ".Lf35d96_00035e7e:\n"
        "movl -0x31c(%ebp), %eax\n"
        ".Lf35d96_00035e84:\n"
        "movl (%eax), %eax\n" /* line 1431 */
        "movl %eax, -0x31c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf35d96_000362e0\n"
        ".Lf35d96_00035e94:\n"
        "movl -0x31c(%ebp), %edx\n" /* line 417 */
        "movl 0xc(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf35d96_00035e6f\n"
        "movl %edx, %ebx\n"
        ".Lf35d96_00035ea3:\n"
        "movl 4(%ebx), %ebx\n" /* line 1437 | c2 */
        "movl %ebx, -0x33c(%ebp)\n" /* c2, iwd */
        "testl %ebx, %ebx\n" /* line 1438 | c2 */
        "je .Lf35d96_00035fb1\n"
        "movl 0xc(%ebp), %eax\n" /* fsOnly */
        "testl %eax, %eax\n"
        "jne .Lf35d96_00035fb1\n"
        "movl 0x314(%ebx), %edi\n" /* line 1440 | c2, hashSize */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl -0x118(%ebp), %eax\n" /* line 467 | sanitizedName */
        "testb %al, %al\n"
        "jne .Lf35d96_00036388\n"
        "xorl %esi, %esi\n" /* hash */
        "xorl %eax, %eax\n"
        "xorl %edx, %edx\n"
        /* } scope */
        /* } scope */
        ".Lf35d96_00035eda:\n"
        "xorl %eax, %esi\n" /* line 1443 | zfi */
        "xorl %esi, %edx\n" /* zfi */
        "leal -1(%edi), %eax\n" /* hashSize */
        "andl %eax, %edx\n"
        "movl -0x33c(%ebp), %ecx\n" /* iwd */
        "movl 0x318(%ecx), %eax\n"
        "movl (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x320(%ebp)\n"
        "testl %edx, %edx\n"
        "je .Lf35d96_00035fb1\n"
        "movl %edx, %ebx\n" /* c2 */
        ".Lf35d96_00035f02:\n"
        "movl 4(%ebx), %esi\n" /* c2, zfi */
        "leal -0x118(%ebp), %eax\n" /* sanitizedName */
        "movl %eax, -0x324(%ebp)\n" /* s2 */
        "movl %eax, %edx\n"
        "jmp .Lf35d96_00035f36\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf35d96_00035f15:\n"
        "cmpl $0x3a, %edi\n" /* line 1107 | c1 */
        "je .Lf35d96_00035f6d\n"
        "cmpl $0x5c, %ebx\n" /* line 1111 | c2 */
        "je .Lf35d96_00035f77\n"
        ".Lf35d96_00035f1f:\n"
        "cmpl $0x3a, %ebx\n" /* c2 */
        "je .Lf35d96_00035f77\n"
        "cmpl %ebx, %edi\n" /* line 1116 | c2, c1 */
        "jne .Lf35d96_00035f80\n"
        ".Lf35d96_00035f28:\n"
        "testl %edi, %edi\n" /* line 1093 | c1 */
        "je .Lf35d96_0003611e\n"
        "movl -0x324(%ebp), %edx\n" /* s2 */
        ".Lf35d96_00035f36:\n"
        "movsbl (%esi), %edi\n" /* line 1095 | c1 */
        "addl $1, %esi\n" /* c1 */
        "movsbl (%edx), %ebx\n" /* line 1096 | c2 */
        "addl $1, %edx\n"
        "movl %edx, -0x324(%ebp)\n" /* s2 */
        "movl %edi, (%esp)\n" /* line 1098 | c1 */
        "calll I_islower\n"
        "leal -0x20(%edi), %edx\n" /* line 1100 | c1 */
        "testb %al, %al\n"
        "cmovnel %edx, %edi\n" /* c1 */
        "movl %ebx, (%esp)\n" /* line 1102 | c2 */
        "calll I_islower\n"
        "leal -0x20(%ebx), %edx\n" /* line 1104 | c2 */
        "testb %al, %al\n"
        "cmovnel %edx, %ebx\n" /* c2 */
        "cmpl $0x5c, %edi\n" /* line 1107 | c1 */
        "jne .Lf35d96_00035f15\n"
        ".Lf35d96_00035f6d:\n"
        "movl $0x2f, %edi\n" /* c1 */
        "cmpl $0x5c, %ebx\n" /* line 1111 | c2 */
        "jne .Lf35d96_00035f1f\n"
        ".Lf35d96_00035f77:\n"
        "movl $0x2f, %ebx\n" /* c2 */
        "cmpl %ebx, %edi\n" /* line 1116 | c2, c1 */
        "je .Lf35d96_00035f28\n"
        /* } scope */
        /* } scope */
        ".Lf35d96_00035f80:\n"
        "movl -0x320(%ebp), %ecx\n" /* line 1513 */
        "movl 8(%ecx), %ecx\n"
        "movl %ecx, -0x320(%ebp)\n"
        "testl %ecx, %ecx\n" /* line 1447 */
        "je .Lf35d96_00035e7e\n"
        "movl -0x320(%ebp), %ebx\n" /* c2 */
        "jmp .Lf35d96_00035f02\n"
        /* { scope 2 */
        ".Lf35d96_00035fa2:\n"
        "movl $1, %esi\n" /* line 503 | hash */
        "movl $0x3c, %edi\n" /* count */
        "jmp .Lf35d96_00035def\n"
        /* } scope */
        ".Lf35d96_00035fb1:\n"
        "movl -0x31c(%ebp), %edx\n" /* line 1516 */
        "movl 8(%edx), %ebx\n" /* c2 */
        "testl %ebx, %ebx\n" /* c2 */
        "je .Lf35d96_000362ce\n"
        "leal -0x118(%ebp), %ecx\n" /* line 1527 | sanitizedName */
        "movl %ecx, (%esp)\n"
        "calll Com_GetExtensionSubString\n"
        "movl %eax, -0x334(%ebp)\n" /* extension */
        "movl fs_restrict, %eax\n" /* line 1528 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf35d96_00035fef\n"
        "movl fs_numServerIwds, %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf35d96_0003637d\n"
        ".Lf35d96_00035fef:\n"
        "movl -0x31c(%ebp), %ebx\n" /* line 1530 | c2 */
        "movl 0xc(%ebx), %edx\n" /* c2 */
        "testl %edx, %edx\n"
        "je .Lf35d96_00036367\n"
        ".Lf35d96_00036000:\n"
        "movl 8(%ebx), %esi\n" /* line 1550 | c2, s1 */
        "leal 0x100(%esi), %edi\n" /* line 1552 | s1, hashSize */
        "movl 8(%ebp), %eax\n" /* streamThread */
        "movl %eax, 4(%esp)\n"
        "leal -0x218(%ebp), %edx\n" /* netpath */
        "movl %edx, (%esp)\n"
        "leal -0x118(%ebp), %ecx\n" /* sanitizedName */
        "movl %edi, %edx\n" /* hashSize */
        "movl %esi, %eax\n" /* s1 */
        "calll FS_BuildOSPath_Internal\n"
        "movl -0x348(%ebp), %ecx\n" /* line 1554 */
        "movl (%ecx), %ebx\n" /* c2 */
        "movl $str_00215b98, 4(%esp)\n" /* "rb" */
        "leal -0x218(%ebp), %eax\n" /* netpath */
        "movl %eax, (%esp)\n"
        "calll FS_FileOpen\n"
        "leal (%ebx, %ebx, 8), %edx\n" /* c2 */
        "shll $3, %edx\n"
        "subl %ebx, %edx\n" /* c2 */
        "movl %eax, fsh(, %edx, 4)\n"
        "movl -0x348(%ebp), %ecx\n" /* line 1556 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl fsh(, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf35d96_00035e7e\n"
        "movl -0x31c(%ebp), %ebx\n" /* line 1560 | c2 */
        "movl 0xc(%ebx), %eax\n" /* c2 */
        "testl %eax, %eax\n"
        "je .Lf35d96_000367e9\n"
        ".Lf35d96_00036085:\n"
        "movl $0x100, 8(%esp)\n" /* line 1567 */
        "leal -0x118(%ebp), %eax\n" /* sanitizedName */
        "movl %eax, 4(%esp)\n"
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal fsh+28(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x348(%ebp), %ecx\n" /* line 1568 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl $0, fsh+20(, %eax, 4)\n"
        "movl fs_debug, %eax\n" /* line 1569 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf35d96_000360fa\n"
        "movl 8(%ebp), %eax\n" /* streamThread */
        "testl %eax, %eax\n"
        "jne .Lf35d96_000360fa\n"
        "movl %edi, 0xc(%esp)\n" /* line 1570 | hashSize */
        "movl %esi, 8(%esp)\n" /* s1 */
        "leal -0x118(%ebp), %ebx\n" /* sanitizedName, c2 */
        "movl %ebx, 4(%esp)\n" /* c2 */
        "movl $str_00217318, (%esp)\n" /* "FS_FOpenFileRead: %s (found in '%s/%s')
" */
        "calll Com_Printf\n"
        ".Lf35d96_000360fa:\n"
        "movl fs_copyfiles, %eax\n" /* line 1574 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf35d96_0003680c\n"
        ".Lf35d96_00036109:\n"
        "movl -0x348(%ebp), %ebx\n" /* line 1582 | c2 */
        "movl (%ebx), %eax\n" /* c2 */
        "movl %eax, (%esp)\n"
        "calll FS_filelength\n"
        "jmp .Lf35d96_000362a8\n"
        ".Lf35d96_0003611e:\n"
        "movl -0x31c(%ebp), %ebx\n" /* line 1456 | c2 */
        "movl 0xc(%ebx), %eax\n" /* c2 */
        "testl %eax, %eax\n"
        "jne .Lf35d96_00036170\n"
        /* { scope 2 */
        "movl fs_numServerIwds, %esi\n" /* line 367 */
        "cmpl $0, %esi\n"
        "je .Lf35d96_00036170\n"
        "jle .Lf35d96_00036350\n" /* line 373 */
        "movl -0x33c(%ebp), %ecx\n" /* line 376 | iwd */
        "movl 0x304(%ecx), %ebx\n"
        "cmpl fs_serverIwds, %ebx\n"
        "je .Lf35d96_000367e2\n"
        "xorl %ecx, %ecx\n"
        "movl $fs_serverIwds, %edx\n"
        ".Lf35d96_0003615b:\n"
        "addl $1, %ecx\n" /* line 373 */
        "cmpl %ecx, %esi\n"
        "je .Lf35d96_00036350\n"
        "movl 4(%edx), %eax\n" /* line 376 */
        "addl $4, %edx\n"
        "cmpl %ebx, %eax\n"
        "jne .Lf35d96_0003615b\n"
        ".Lf35d96_00036170:\n"
        "movl -0x33c(%ebp), %eax\n" /* iwd */
        /* } scope */
        ".Lf35d96_00036176:\n"
        "cmpb $0, 0x310(%eax)\n" /* line 1467 */
        "je .Lf35d96_00036530\n"
        ".Lf35d96_00036183:\n"
        "movl -0x34c(%ebp), %eax\n" /* line 1475 */
        "testl %eax, %eax\n"
        "jne .Lf35d96_000364ac\n"
        "movl -0x348(%ebp), %edx\n" /* line 1492 */
        "movl (%edx), %eax\n"
        "leal (%eax, %eax, 8), %edx\n"
        "shll $3, %edx\n"
        "subl %eax, %edx\n"
        "movl -0x33c(%ebp), %ecx\n" /* iwd */
        "movl 0x300(%ecx), %eax\n"
        "movl %eax, fsh(, %edx, 4)\n"
        "movl -0x348(%ebp), %ebx\n" /* c2 */
        "movl (%ebx), %edx\n" /* c2 */
        ".Lf35d96_000361bc:\n"
        "movl $0x100, 8(%esp)\n" /* line 1494 */
        "leal -0x118(%ebp), %eax\n" /* sanitizedName */
        "movl %eax, 4(%esp)\n"
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal fsh+28(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x348(%ebp), %ecx\n" /* line 1495 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl -0x33c(%ebp), %ebx\n" /* iwd, c2 */
        "movl %ebx, fsh+20(, %eax, 4)\n" /* c2 */
        "movl (%ecx), %edx\n" /* line 1496 */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl fsh(, %eax, 4), %esi\n" /* s1 */
        "movl (%esi), %ebx\n" /* line 1498 | s1, c2 */
        "movl -0x320(%ebp), %edx\n" /* line 1500 */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x33c(%ebp), %ecx\n" /* iwd */
        "movl 0x300(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll unzSetCurrentFileInfoPosition\n"
        "movl $0x80, 8(%esp)\n" /* line 1502 */
        "movl -0x33c(%ebp), %edx\n" /* iwd */
        "movl 0x300(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* s1 */
        "calll Com_Memcpy\n"
        "movl %ebx, (%esi)\n" /* line 1504 | c2, s1 */
        "movl -0x348(%ebp), %ecx\n" /* line 1506 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl fsh(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll unzOpenCurrentFile\n"
        "movl -0x348(%ebp), %ebx\n" /* line 1507 | c2 */
        "movl (%ebx), %edx\n" /* c2 */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl -0x320(%ebp), %ecx\n"
        "movl (%ecx), %edx\n"
        "movl %edx, fsh+16(, %eax, 4)\n"
        "movl fs_debug, %eax\n" /* line 1509 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf35d96_00036419\n"
        ".Lf35d96_000362a5:\n"
        "movl 0x44(%esi), %eax\n" /* line 1511 | s1 */
        /* } scope */
        ".Lf35d96_000362a8:\n"
        "addl $0x35c, %esp\n" /* line 1603 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: s2, extensions, s2 */
        ".Lf35d96_000362b3:\n"
        "movl 0x10(%edx), %ebx\n" /* line 422 */
        "calll SEH_GetCurrentLanguage\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf35d96_00035e7e\n"
        "movl -0x31c(%ebp), %ebx\n"
        "jmp .Lf35d96_00035ea3\n"
        ".Lf35d96_000362ce:\n"
        "movl %edx, %eax\n"
        "movl (%eax), %eax\n" /* line 1431 */
        "movl %eax, -0x31c(%ebp)\n"
        "testl %eax, %eax\n"
        "jne .Lf35d96_00035e94\n"
        ".Lf35d96_000362e0:\n"
        "movl fs_debug, %eax\n" /* line 1586 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf35d96_000362f7\n"
        "movl 8(%ebp), %eax\n" /* streamThread */
        "testl %eax, %eax\n"
        "je .Lf35d96_000365b5\n"
        ".Lf35d96_000362f7:\n"
        "movl -0x348(%ebp), %ecx\n" /* line 1594 */
        "movl $0, (%ecx)\n"
        "movl -0x330(%ebp), %edi\n" /* line 1596 | impureIwd, hashSize */
        "testl %edi, %edi\n" /* hashSize */
        "je .Lf35d96_00036333\n"
        "movl -0x330(%ebp), %ebx\n" /* line 1597 | impureIwd, c2 */
        "movl %ebx, 4(%esp)\n" /* c2 */
        "movl $str_00217354, (%esp)\n" /* "EXE_UNPURECLIENTDETECTED
%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf35d96_00036333:\n"
        "cmpb $0, -0x329(%ebp)\n" /* line 1599 | wasSkipped */
        "jne .Lf35d96_000365d0\n"
        ".Lf35d96_00036340:\n"
        "movl $0xffffffff, %eax\n" /* line 1484 */
        /* } scope */
        ".Lf35d96_00036345:\n"
        "addl $0x35c, %esp\n" /* line 1603 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: s2, extensions, s2 */
        ".Lf35d96_00036350:\n"
        "movl -0x33c(%ebp), %eax\n" /* line 1458 | iwd */
        "movl %eax, -0x330(%ebp)\n" /* impureIwd */
        "movl -0x31c(%ebp), %eax\n"
        "jmp .Lf35d96_00035e84\n"
        ".Lf35d96_00036367:\n"
        "movl -0x334(%ebp), %eax\n" /* line 1530 | extension */
        "movl %eax, (%esp)\n"
        "calll FS_PureIgnoresExtension\n"
        "testl %eax, %eax\n"
        "je .Lf35d96_00036449\n"
        ".Lf35d96_0003637d:\n"
        "movl -0x31c(%ebp), %ebx\n" /* c2 */
        "jmp .Lf35d96_00036000\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf35d96_00036388:\n"
        "xorl %esi, %esi\n" /* line 467 | hash */
        "movl $0x77, %ebx\n"
        ".Lf35d96_0003638f:\n"
        "movsbl %al, %eax\n" /* line 469 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %eax, %edx\n"
        "cmpl $0x2e, %eax\n" /* line 470 */
        "je .Lf35d96_000363c0\n"
        "cmpl $0x5c, %eax\n" /* line 473 */
        "movl $0x2f, %eax\n"
        "cmovel %eax, %edx\n"
        "imull %ebx, %edx\n" /* line 478 */
        "addl %edx, %esi\n" /* hash */
        "movzbl -0x18e(%ebx, %ebp), %eax\n" /* line 467 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf35d96_0003638f\n"
        ".Lf35d96_000363c0:\n"
        "movl %esi, %eax\n" /* hash */
        "sarl $0xa, %eax\n"
        "movl %esi, %edx\n" /* hash */
        "sarl $0x14, %edx\n"
        "jmp .Lf35d96_00035eda\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf35d96_000363cf:\n"
        "movl $1, %ebx\n" /* line 514 | first */
        "movl $fsh+312, %edi\n" /* count */
        ".Lf35d96_000363d9:\n"
        "movl %edi, 8(%esp)\n" /* line 524 | count */
        "movl %ebx, 4(%esp)\n" /* first */
        "movl $str_00216c70, (%esp)\n" /* "FILE %2i: '%s'
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 523 | first */
        "addl $0x11c, %edi\n" /* count */
        "cmpl $0x4a, %ebx\n" /* first */
        "jne .Lf35d96_000363d9\n"
        "movl $str_00216c80, 4(%esp)\n" /* line 526 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0xffffffff, %esi\n" /* hash */
        "jmp .Lf35d96_00035e2c\n"
        /* } scope */
        ".Lf35d96_00036419:\n"
        "movl 8(%ebp), %edi\n" /* line 1509 | streamThread, hashSize */
        "testl %edi, %edi\n" /* hashSize */
        "jne .Lf35d96_000362a5\n"
        "movl -0x33c(%ebp), %ebx\n" /* line 1510 | iwd, c2 */
        "movl %ebx, 8(%esp)\n" /* c2 */
        "leal -0x118(%ebp), %eax\n" /* sanitizedName */
        "movl %eax, 4(%esp)\n"
        "movl $str_002172f0, (%esp)\n" /* "FS_FOpenFileRead: %s (found in '%s')
" */
        "calll Com_Printf\n"
        "jmp .Lf35d96_000362a5\n"
        ".Lf35d96_00036449:\n"
        "cmpb $0, -0x329(%ebp)\n" /* line 1532 | wasSkipped */
        "jne .Lf35d96_00035e7e\n"
        "movl 8(%ebx), %eax\n" /* line 1536 | c2 */
        "leal 0x100(%eax), %edx\n" /* line 1537 */
        "movl 8(%ebp), %ecx\n" /* streamThread */
        "movl %ecx, 4(%esp)\n"
        "leal -0x218(%ebp), %ebx\n" /* netpath, c2 */
        "movl %ebx, (%esp)\n" /* c2 */
        "leal -0x118(%ebp), %ecx\n" /* sanitizedName */
        "calll FS_BuildOSPath_Internal\n"
        "movl $str_00215b98, 4(%esp)\n" /* line 1538 */
        "movl %ebx, (%esp)\n" /* c2 */
        "calll FS_FileOpen\n"
        "testl %eax, %eax\n" /* line 1539 */
        "je .Lf35d96_00035e7e\n"
        "movl %eax, (%esp)\n" /* line 1542 */
        "calll FS_FileClose\n"
        "movb $1, -0x329(%ebp)\n" /* wasSkipped */
        "movl -0x31c(%ebp), %eax\n"
        "jmp .Lf35d96_00035e84\n"
        ".Lf35d96_000364ac:\n"
        "movl -0x348(%ebp), %ecx\n" /* line 1478 */
        "movl (%ecx), %ebx\n" /* c2 */
        "movl -0x33c(%ebp), %edx\n" /* iwd */
        "movl 0x300(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll unzReOpen\n"
        "leal (%ebx, %ebx, 8), %edx\n" /* c2 */
        "shll $3, %edx\n"
        "subl %ebx, %edx\n" /* c2 */
        "movl %eax, fsh(, %edx, 4)\n"
        "movl -0x348(%ebp), %ecx\n" /* line 1479 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl fsh(, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf35d96_000361bc\n"
        "movl 8(%ebp), %eax\n" /* line 1481 | streamThread */
        "testl %eax, %eax\n"
        "jne .Lf35d96_000368ec\n"
        "movl -0x33c(%ebp), %ebx\n" /* line 1487 | iwd, c2 */
        "movl %ebx, 8(%esp)\n" /* c2 */
        "movl $str_002172dc, 4(%esp)\n" /* "Couldn't reopen %s" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x348(%ebp), %eax\n"
        "movl (%eax), %edx\n"
        "jmp .Lf35d96_000361bc\n"
        /* { scope 2 */
        ".Lf35d96_00036530:\n"
        "movl $str_002172a8, -0x318(%ebp)\n" /* line 1323 | extensions */
        "movl $str_002172b0, -0x314(%ebp)\n" /* ".txt" */
        "movl $str_00216330, -0x310(%ebp)\n" /* ".cfg" */
        "movl $str_002172b8, -0x30c(%ebp)\n" /* ".levelshots" */
        "movl $str_002172c4, -0x308(%ebp)\n" /* ".menu" */
        "movl $str_002172cc, -0x304(%ebp)\n" /* ".arena" */
        "movl $str_002172d4, -0x300(%ebp)\n" /* ".str" */
        "movl $str_002157b8, -0x2fc(%ebp)\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x118(%ebp), %edi\n" /* sanitizedName, count */
        "repne scasb %es:(%edi), %al\n" /* count */
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "movl $str_002172a8, %edx\n" /* line 1329 */
        "cmpb $0, str_002172a8\n" /* ".hlsl" */
        "jne .Lf35d96_000365fe\n"
        /* } scope */
        ".Lf35d96_000365a3:\n"
        "movl -0x33c(%ebp), %edx\n" /* line 1471 | iwd */
        "movb $1, 0x310(%edx)\n"
        "jmp .Lf35d96_00036183\n"
        ".Lf35d96_000365b5:\n"
        "movl -0x344(%ebp), %edx\n" /* line 1587 */
        "movl %edx, 4(%esp)\n"
        "movl $str_00217344, (%esp)\n" /* "Can't find %s
" */
        "calll Com_Printf\n"
        "jmp .Lf35d96_000362f7\n"
        ".Lf35d96_000365d0:\n"
        "movl $0xfffffffe, %eax\n" /* line 1599 */
        "jmp .Lf35d96_000362a8\n"
        ".Lf35d96_000365da:\n"
        "movl -0x348(%ebp), %eax\n" /* line 1371 */
        "testl %eax, %eax\n"
        "je .Lf35d96_00036340\n"
        "movl -0x348(%ebp), %eax\n" /* line 1372 */
        "movl $0, (%eax)\n"
        "movl $0xffffffff, %eax\n"
        "jmp .Lf35d96_000362a8\n"
        /* { scope 2 */
        ".Lf35d96_000365fe:\n"
        "leal -0x118(%ebp), %esi\n" /* line 1329 | sanitizedName, c1 */
        "addl %eax, %esi\n" /* c1 */
        "leal -0x318(%ebp), %ebx\n" /* extensions, c2 */
        ".Lf35d96_0003660c:\n"
        "movl %edx, 4(%esp)\n" /* line 1331 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n" /* c1 */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* c1 */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %esi, %eax\n" /* c1 */
        "subl %ecx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf35d96_00036183\n"
        "movl 4(%ebx), %edx\n" /* line 1329 | c2 */
        "addl $4, %ebx\n" /* c2 */
        "cmpb $0, (%edx)\n"
        "jne .Lf35d96_0003660c\n"
        "jmp .Lf35d96_000365a3\n"
        /* } scope */
        ".Lf35d96_00036645:\n"
        "movl fs_searchpaths, %edx\n" /* line 1379 */
        "movl %edx, -0x340(%ebp)\n" /* search */
        "testl %edx, %edx\n"
        "je .Lf35d96_00036340\n"
        ".Lf35d96_00036659:\n"
        "movl -0x340(%ebp), %ecx\n" /* line 417 | search */
        "movl 0xc(%ecx), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf35d96_00036699\n"
        "movl fs_ignoreLocalized, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf35d96_0003668d\n"
        ".Lf35d96_00036671:\n"
        "movl -0x340(%ebp), %edx\n" /* line 1379 | search */
        "movl (%edx), %edx\n"
        "movl %edx, -0x340(%ebp)\n" /* search */
        "testl %edx, %edx\n"
        "jne .Lf35d96_00036659\n"
        "movl $0xffffffff, %eax\n" /* line 1484 */
        "jmp .Lf35d96_00036345\n"
        ".Lf35d96_0003668d:\n"
        "movl 0x10(%ecx), %ebx\n" /* line 422 */
        "calll SEH_GetCurrentLanguage\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf35d96_00036671\n"
        ".Lf35d96_00036699:\n"
        "movl -0x340(%ebp), %ebx\n" /* line 1385 | search, c2 */
        "movl 4(%ebx), %ecx\n" /* c2 */
        "testl %ecx, %ecx\n"
        "je .Lf35d96_00036786\n"
        "movl 0x314(%ecx), %edi\n" /* line 1387 | hashSize */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl -0x118(%ebp), %eax\n" /* line 467 | sanitizedName */
        "testb %al, %al\n"
        "jne .Lf35d96_00036864\n"
        "xorl %esi, %esi\n" /* hash */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        ".Lf35d96_000366c5:\n"
        "xorl %esi, %edx\n" /* line 482 | hash */
        "xorl %eax, %edx\n"
        "leal -1(%edi), %eax\n"
        "andl %eax, %edx\n"
        /* } scope */
        /* } scope */
        "testl %ecx, %ecx\n" /* line 1390 */
        "je .Lf35d96_00036786\n"
        "movl 0x318(%ecx), %eax\n"
        "movl (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x338(%ebp)\n" /* iwdFile */
        "testl %edx, %edx\n"
        "je .Lf35d96_00036786\n"
        ".Lf35d96_000366ed:\n"
        "movl -0x338(%ebp), %eax\n" /* iwdFile */
        "movl 4(%eax), %edi\n" /* hashSize */
        "leal -0x118(%ebp), %edx\n" /* sanitizedName */
        "movl %edx, -0x328(%ebp)\n" /* s2 */
        "movl %edx, %ecx\n"
        "jmp .Lf35d96_0003672b\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf35d96_00036706:\n"
        "cmpl $0x3a, %esi\n" /* line 1107 | c1 */
        "je .Lf35d96_00036762\n"
        ".Lf35d96_0003670b:\n"
        "cmpl $0x5c, %ebx\n" /* line 1111 | c2 */
        "je .Lf35d96_00036769\n"
        "cmpl $0x3a, %ebx\n" /* c2 */
        "je .Lf35d96_00036769\n"
        ".Lf35d96_00036715:\n"
        "cmpl %ebx, %esi\n" /* line 1116 | c2, c1 */
        "jne .Lf35d96_000368b6\n"
        "testl %esi, %esi\n" /* line 1093 | c1 */
        "je .Lf35d96_000367d8\n"
        "movl -0x328(%ebp), %ecx\n" /* s2 */
        ".Lf35d96_0003672b:\n"
        "movsbl (%edi), %esi\n" /* line 1095 | c1 */
        "addl $1, %edi\n" /* c1 */
        "movsbl (%ecx), %ebx\n" /* line 1096 | c2 */
        "addl $1, %ecx\n"
        "movl %ecx, -0x328(%ebp)\n" /* s2 */
        "movl %esi, (%esp)\n" /* line 1098 | c1 */
        "calll I_islower\n"
        "leal -0x20(%esi), %edx\n" /* line 1100 | c1 */
        "testb %al, %al\n"
        "cmovnel %edx, %esi\n" /* c1 */
        "movl %ebx, (%esp)\n" /* line 1102 | c2 */
        "calll I_islower\n"
        "leal -0x20(%ebx), %edx\n" /* line 1104 | c2 */
        "testb %al, %al\n"
        "cmovnel %edx, %ebx\n" /* c2 */
        "cmpl $0x5c, %esi\n" /* line 1107 | c1 */
        "jne .Lf35d96_00036706\n"
        ".Lf35d96_00036762:\n"
        "movl $0x2f, %esi\n" /* c1 */
        "jmp .Lf35d96_0003670b\n"
        ".Lf35d96_00036769:\n"
        "movl $0x2f, %ebx\n" /* line 1111 | c2 */
        "jmp .Lf35d96_00036715\n"
        /* } scope */
        /* } scope */
        ".Lf35d96_00036770:\n"
        "movb $0, -0x329(%ebp)\n" /* line 1431 | wasSkipped */
        "movl $0, -0x330(%ebp)\n" /* impureIwd */
        "jmp .Lf35d96_000362e0\n"
        ".Lf35d96_00036786:\n"
        "movl -0x340(%ebp), %edx\n" /* line 1406 | search */
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf35d96_00036671\n"
        "leal 0x100(%eax), %edx\n" /* line 1410 */
        "movl 8(%ebp), %ecx\n" /* streamThread */
        "movl %ecx, 4(%esp)\n"
        "leal -0x218(%ebp), %ebx\n" /* netpath, c2 */
        "movl %ebx, (%esp)\n" /* c2 */
        "leal -0x118(%ebp), %ecx\n" /* sanitizedName */
        "calll FS_BuildOSPath_Internal\n"
        "movl $str_00215b98, 4(%esp)\n" /* line 1411 */
        "movl %ebx, (%esp)\n" /* c2 */
        "calll FS_FileOpen\n"
        "testl %eax, %eax\n" /* line 1412 */
        "je .Lf35d96_00036671\n"
        "movl %eax, (%esp)\n" /* line 1416 */
        "calll FS_FileClose\n"
        ".Lf35d96_000367d8:\n"
        "movl $1, %eax\n"
        "jmp .Lf35d96_000362a8\n"
        ".Lf35d96_000367e2:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf35d96_00036176\n"
        ".Lf35d96_000367e9:\n"
        "movl -0x334(%ebp), %eax\n" /* line 1560 | extension */
        "movl %eax, (%esp)\n"
        "calll FS_PureIgnoresExtension\n"
        "testl %eax, %eax\n"
        "je .Lf35d96_000368d2\n"
        "movl -0x348(%ebp), %ebx\n" /* c2 */
        "movl (%ebx), %edx\n" /* c2 */
        "jmp .Lf35d96_00036085\n"
        ".Lf35d96_0003680c:\n"
        "movl fs_cdpath, %eax\n" /* line 1574 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* s1 */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf35d96_00036109\n"
        /* { scope 2 */
        "movl fs_basepath, %eax\n" /* line 1578 */
        "movl 8(%eax), %eax\n"
        "movl 8(%ebp), %edx\n" /* streamThread */
        "movl %edx, 4(%esp)\n"
        "leal -0x318(%ebp), %ebx\n" /* extensions, c2 */
        "movl %ebx, (%esp)\n" /* c2 */
        "leal -0x118(%ebp), %ecx\n" /* sanitizedName */
        "movl %edi, %edx\n" /* hashSize */
        "calll FS_BuildOSPath_Internal\n"
        "movl %ebx, 4(%esp)\n" /* line 1579 | c2 */
        "leal -0x218(%ebp), %ecx\n" /* netpath */
        "movl %ecx, (%esp)\n"
        "calll FS_CopyFile\n"
        "jmp .Lf35d96_00036109\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf35d96_00036864:\n"
        "xorl %esi, %esi\n" /* line 467 | hash */
        "movl $0x77, %ebx\n"
        "jmp .Lf35d96_0003688c\n"
        ".Lf35d96_0003686d:\n"
        "cmpl $0x5c, %eax\n" /* line 473 */
        "movl $0x2f, %eax\n"
        "cmovel %eax, %edx\n"
        "imull %ebx, %edx\n" /* line 478 */
        "addl %edx, %esi\n" /* hash */
        "movzbl -0x18e(%ebx, %ebp), %eax\n" /* line 467 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "je .Lf35d96_0003689e\n"
        ".Lf35d96_0003688c:\n"
        "movsbl %al, %eax\n" /* line 469 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %eax, %edx\n"
        "cmpl $0x2e, %eax\n" /* line 470 */
        "jne .Lf35d96_0003686d\n"
        ".Lf35d96_0003689e:\n"
        "movl %esi, %edx\n" /* line 467 | hash */
        "sarl $0xa, %edx\n"
        "movl %esi, %eax\n" /* hash */
        "sarl $0x14, %eax\n"
        "movl -0x340(%ebp), %ebx\n" /* search */
        "movl 4(%ebx), %ecx\n"
        "jmp .Lf35d96_000366c5\n"
        /* } scope */
        /* } scope */
        ".Lf35d96_000368b6:\n"
        "movl -0x338(%ebp), %ebx\n" /* line 1403 | iwdFile, c2 */
        "movl 8(%ebx), %ebx\n" /* c2 */
        "movl %ebx, -0x338(%ebp)\n" /* c2, iwdFile */
        "testl %ebx, %ebx\n" /* line 1395 | c2 */
        "jne .Lf35d96_000366ed\n"
        "jmp .Lf35d96_00036671\n"
        ".Lf35d96_000368d2:\n"
        "calll rand\n" /* line 1563 */
        "addl $1, %eax\n"
        "movl %eax, fs_fakeChkSum\n"
        "movl -0x348(%ebp), %ecx\n"
        "movl (%ecx), %edx\n"
        "jmp .Lf35d96_00036085\n"
        ".Lf35d96_000368ec:\n"
        "movl %edx, (%esp)\n" /* line 1483 */
        "calll FS_FCloseFile\n"
        "movl -0x348(%ebp), %edx\n" /* line 1484 */
        "movl $0, (%edx)\n"
        "movl $0xffffffff, %eax\n"
        "jmp .Lf35d96_00036345\n"
    );
}

/* line 1655 */
__attribute__((naked))
int FS_FOpenFileRead(const char *filename, fileHandle_t *file, qboolean uniqueFILE)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1655 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* filename */
        "movl 0xc(%ebp), %edi\n" /* file */
        "movl 0x10(%ebp), %esi\n" /* uniqueFILE */
        /* { scope 1 */
        "movl $1, com_fileAccessed\n" /* line 1659 */
        "movl %ebx, (%esp)\n" /* line 1664 | filename */
        "calll Com_GetExtensionSubString\n"
        "movl %eax, (%esp)\n" /* line 1665 */
        "calll FS_PureIgnoresExtension\n"
        "testl %eax, %eax\n"
        "jne .Lf3690a_0003695a\n"
        ".Lf3690a_0003693a:\n"
        "movl $0, 0xc(%ebp)\n" /* line 1675 | file */
        "movl $0, 8(%ebp)\n" /* filename */
        "movl %esi, %ecx\n" /* uniqueFILE */
        "movl %edi, %edx\n" /* file */
        "movl %ebx, %eax\n" /* filename */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1680 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp FS_FOpenFileRead_Internal\n" /* line 1675 */
        ".Lf3690a_0003695a:\n"
        "movl $1, 4(%esp)\n" /* line 1667 */
        "movl $0, (%esp)\n"
        "movl %esi, %ecx\n" /* uniqueFILE */
        "movl %edi, %edx\n" /* file */
        "movl %ebx, %eax\n" /* filename */
        "calll FS_FOpenFileRead_Internal\n"
        "movl %eax, %edx\n"
        "leal 2(%eax), %eax\n"
        "cmpl $1, %eax\n" /* line 1673 */
        "jbe .Lf3690a_0003693a\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 1680 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1636 */
__attribute__((naked))
int FS_FOpenFileReadStream(const char *filename, fileHandle_t *file, qboolean uniqueFILE)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1636 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* filename */
        "movl 0xc(%ebp), %edx\n" /* file */
        "movl 0x10(%ebp), %ecx\n" /* uniqueFILE */
        "movl $0, 0xc(%ebp)\n" /* line 1640 | file */
        "movl $1, 8(%ebp)\n" /* filename */
        "popl %ebp\n" /* line 1642 */
        "jmp FS_FOpenFileRead_Internal\n" /* line 1640 */
    );
}

/* line 1690 */
__attribute__((naked))
qboolean FS_TouchFile(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1690 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        /* { scope 1 */
        /* { scope 2 */
        "movl $1, com_fileAccessed\n" /* line 1659 */
        "movl %ebx, (%esp)\n" /* line 1664 */
        "calll Com_GetExtensionSubString\n"
        "movl %eax, (%esp)\n" /* line 1665 */
        "calll FS_PureIgnoresExtension\n"
        "testl %eax, %eax\n"
        "jne .Lf369a8_00036a05\n"
        ".Lf369a8_000369d0:\n"
        "leal -0xc(%ebp), %edx\n" /* line 1675 | f */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %eax\n"
        "calll FS_FOpenFileRead_Internal\n"
        /* } scope */
        ".Lf369a8_000369eb:\n"
        "movl -0xc(%ebp), %eax\n" /* line 1695 | f */
        "testl %eax, %eax\n"
        "je .Lf369a8_000369ff\n"
        "movl %eax, (%esp)\n" /* line 1697 */
        "calll FS_FCloseFile\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf369a8_000369ff:\n"
        "addl $0x24, %esp\n" /* line 1699 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf369a8_00036a05:\n"
        "leal -0xc(%ebp), %edx\n" /* line 1667 | f */
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %eax\n"
        "calll FS_FOpenFileRead_Internal\n"
        "addl $2, %eax\n"
        "cmpl $1, %eax\n" /* line 1673 */
        "ja .Lf369a8_000369eb\n"
        "jmp .Lf369a8_000369d0\n"
    );
}

/* line 2110 */
__attribute__((naked))
int FS_ReadFile(const char *qpath, float * *buffer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2110 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* qpath */
        "movl 0xc(%ebp), %edi\n" /* buffer */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 2122 | qpath */
        "je .Lf36a2a_00036ada\n"
        "cmpb $0, (%ebx)\n" /* qpath */
        "je .Lf36a2a_00036ada\n"
        /* { scope 2 */
        "movl $1, com_fileAccessed\n" /* line 1659 */
        "movl %ebx, (%esp)\n" /* line 1664 */
        "calll Com_GetExtensionSubString\n"
        "movl %eax, (%esp)\n" /* line 1665 */
        "calll FS_PureIgnoresExtension\n"
        "testl %eax, %eax\n"
        "jne .Lf36a2a_00036b10\n"
        ".Lf36a2a_00036a6c:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 1675 | h */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %eax\n"
        "calll FS_FOpenFileRead_Internal\n"
        "movl %eax, %esi\n"
        /* } scope */
        ".Lf36a2a_00036a89:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2131 | h */
        "testl %eax, %eax\n"
        "je .Lf36a2a_00036b3e\n"
        "testl %edi, %edi\n" /* line 2140 | buffer */
        "je .Lf36a2a_00036ac8\n"
        "addl $1, fs_loadStack\n" /* line 2146 */
        "leal 1(%esi), %eax\n" /* line 2148 | len */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, %ebx\n" /* qpath */
        "movl %eax, (%edi)\n" /* line 2149 | buffer */
        "movl -0x1c(%ebp), %eax\n" /* line 2151 | h */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* len */
        "movl %ebx, (%esp)\n" /* qpath */
        "calll FS_Read\n"
        "movb $0, (%ebx, %esi)\n" /* line 2154 | qpath */
        "movl -0x1c(%ebp), %eax\n" /* line 2155 | h */
        ".Lf36a2a_00036ac8:\n"
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        /* } scope */
        ".Lf36a2a_00036ad0:\n"
        "movl %esi, %eax\n" /* line 2158 | len */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf36a2a_00036ada:\n"
        "movl $str_00217374, 4(%esp)\n" /* line 2124 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        /* { scope 2 */
        "movl $1, com_fileAccessed\n" /* line 1659 */
        "movl %ebx, (%esp)\n" /* line 1664 */
        "calll Com_GetExtensionSubString\n"
        "movl %eax, (%esp)\n" /* line 1665 */
        "calll FS_PureIgnoresExtension\n"
        "testl %eax, %eax\n"
        "je .Lf36a2a_00036a6c\n"
        ".Lf36a2a_00036b10:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 1667 | h */
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %eax\n"
        "calll FS_FOpenFileRead_Internal\n"
        "movl %eax, %esi\n"
        "leal 2(%eax), %eax\n"
        "cmpl $1, %eax\n" /* line 1673 */
        "ja .Lf36a2a_00036a89\n"
        "jmp .Lf36a2a_00036a6c\n"
        /* } scope */
        ".Lf36a2a_00036b3e:\n"
        "testl %edi, %edi\n" /* line 2133 | buffer */
        "jne .Lf36a2a_00036b49\n"
        "movl $0xffffffff, %esi\n" /* line 2135 | len */
        "jmp .Lf36a2a_00036ad0\n"
        ".Lf36a2a_00036b49:\n"
        "movl $0, (%edi)\n" /* buffer */
        "movl $0xffffffff, %esi\n" /* len */
        "jmp .Lf36a2a_00036ad0\n"
    );
}

/* line 957 */
__attribute__((naked))
fileHandle_t FS_FOpenFileWrite(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 957 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1 */
        "movl fs_homepath, %eax\n" /* line 697 */
        "movl 8(%eax), %eax\n"
        "movl $0, 4(%esp)\n"
        "leal -0x118(%ebp), %ebx\n" /* ospath, i */
        "movl %ebx, (%esp)\n" /* i */
        "movl 8(%ebp), %ecx\n" /* filename */
        "movl $fs_gamedir, %edx\n"
        "calll FS_BuildOSPath_Internal\n"
        "movl fs_debug, %eax\n" /* line 966 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf36b5c_00036bcd\n"
        "movl $str_00216ca0, 4(%esp)\n" /* line 715 */
        "movl %ebx, (%esp)\n" /* i */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf36b5c_00036bf1\n"
        ".Lf36b5c_00036bae:\n"
        "movl %ebx, 4(%esp)\n" /* line 717 | i */
        "movl $str_00216ca4, (%esp)\n" /* "WARNING: refusing to create relative path "%s"
" */
        "calll Com_Printf\n"
        "xorl %esi, %esi\n"
        /* } scope */
        ".Lf36b5c_00036bc0:\n"
        "movl %esi, %eax\n" /* line 979 | f */
        "addl $0x11c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf36b5c_00036bcd:\n"
        "movl %ebx, 4(%esp)\n" /* line 967 | i */
        "movl $str_00217394, (%esp)\n" /* "FS_FOpenFileWrite: %s
" */
        "calll Com_Printf\n"
        "movl $str_00216ca0, 4(%esp)\n" /* line 715 */
        "movl %ebx, (%esp)\n" /* i */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "jne .Lf36b5c_00036bae\n"
        ".Lf36b5c_00036bf1:\n"
        "movl $str_00215bf8, 4(%esp)\n" /* "::" */
        "movl %ebx, (%esp)\n" /* i */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "jne .Lf36b5c_00036bae\n"
        "movzbl -0x117(%ebp), %eax\n" /* line 721 */
        "testb %al, %al\n"
        "je .Lf36b5c_00036c35\n"
        "movl %ebx, %esi\n" /* i */
        "jmp .Lf36b5c_00036c1f\n"
        ".Lf36b5c_00036c14:\n"
        "movzbl 2(%esi), %eax\n"
        "addl $1, %esi\n"
        "testb %al, %al\n"
        "je .Lf36b5c_00036c35\n"
        ".Lf36b5c_00036c1f:\n"
        "cmpb $0x2f, %al\n" /* line 723 */
        "jne .Lf36b5c_00036c14\n"
        "movb $0, 1(%esi)\n" /* line 726 */
        "movl %ebx, (%esp)\n" /* line 727 | i */
        "calll Sys_Mkdir\n"
        "movb $0x2f, 1(%esi)\n" /* line 728 */
        "jmp .Lf36b5c_00036c14\n"
        /* { scope 2 */
        ".Lf36b5c_00036c35:\n"
        "movl $str_00216fec, 4(%esp)\n" /* line 933 */
        "movl %ebx, (%esp)\n" /* i */
        "calll FS_FileOpen\n"
        "movl %eax, %edi\n" /* fp */
        "testl %eax, %eax\n" /* line 936 */
        "je .Lf36b5c_00036d00\n"
        /* } scope */
        "xorl %esi, %esi\n" /* line 721 */
        "movl $fsh, %eax\n"
        "jmp .Lf36b5c_00036c62\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf36b5c_00036c58:\n"
        "addl $0x11c, %eax\n" /* line 516 */
        "cmpl $0x3c, %esi\n" /* line 514 */
        "je .Lf36b5c_00036cb6\n"
        ".Lf36b5c_00036c62:\n"
        "addl $1, %esi\n" /* line 516 */
        "movl 0x11c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf36b5c_00036c58\n"
        /* } scope */
        ".Lf36b5c_00036c6f:\n"
        "leal (%esi, %esi, 8), %ebx\n" /* line 940 | f, i */
        "shll $3, %ebx\n" /* i */
        "subl %esi, %ebx\n" /* f, i */
        "shll $2, %ebx\n" /* i */
        "movl $0, fsh+20(%ebx)\n" /* i */
        "movl %edi, fsh(%ebx)\n" /* line 941 | fp, i */
        "movl $0x100, 8(%esp)\n" /* line 942 */
        "movl 8(%ebp), %eax\n" /* filename */
        "movl %eax, 4(%esp)\n"
        "leal fsh+28(%ebx), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0, fsh+8(%ebx)\n" /* line 943 | i */
        "jmp .Lf36b5c_00036bc0\n"
        /* { scope 3 */
        ".Lf36b5c_00036cb6:\n"
        "movl $1, %ebx\n" /* line 514 | i */
        "movl $fsh+312, %esi\n"
        ".Lf36b5c_00036cc0:\n"
        "movl %esi, 8(%esp)\n" /* line 524 */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $str_00216c70, (%esp)\n" /* "FILE %2i: '%s'
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 523 | i */
        "addl $0x11c, %esi\n"
        "cmpl $0x4a, %ebx\n" /* i */
        "jne .Lf36b5c_00036cc0\n"
        "movl $str_00216c80, 4(%esp)\n" /* line 526 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0xffffffff, %esi\n"
        "jmp .Lf36b5c_00036c6f\n"
        /* } scope */
        ".Lf36b5c_00036d00:\n"
        "xorl %esi, %esi\n" /* line 936 | f */
        "jmp .Lf36b5c_00036bc0\n"
    );
}

/* line 2201 */
__attribute__((naked))
qboolean FS_WriteFile(const char *qpath, const float *buffer, int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2201 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x12c, %esp\n"
        /* { scope 1: tries, f, ospath */
        "movl 8(%ebp), %eax\n" /* line 2211 | qpath */
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileWrite\n"
        "movl %eax, %esi\n" /* f */
        "testl %eax, %eax\n" /* line 2212 */
        "je .Lf36d08_00036e12\n"
        /* { scope 2 */
        "leal (%eax, %eax, 8), %eax\n" /* line 544 */
        "shll $3, %eax\n"
        "subl %esi, %eax\n"
        "movl fsh(, %eax, 4), %eax\n"
        "movl %eax, -0x11c(%ebp)\n" /* f */
        "movl 0xc(%ebp), %edi\n" /* line 1912 | buffer, buf */
        "movl 0x10(%ebp), %ecx\n" /* line 1916 | size */
        "testl %ecx, %ecx\n"
        "jne .Lf36d08_00036db7\n"
        ".Lf36d08_00036d48:\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 1936 */
        "shll $3, %eax\n"
        "subl %esi, %eax\n"
        "movl fsh+8(, %eax, 4), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf36d08_00036e32\n"
        ".Lf36d08_00036d5f:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1938 | size */
        /* } scope */
        ".Lf36d08_00036d62:\n"
        "movl %esi, (%esp)\n" /* line 2219 | f */
        "calll FS_FCloseFile\n"
        "cmpl 0x10(%ebp), %ebx\n" /* line 2221 | size, actualSize */
        "je .Lf36d08_00036e45\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 1756 | qpath */
        "cmpb $0, (%eax)\n"
        "jne .Lf36d08_00036d88\n"
        ".Lf36d08_00036d7b:\n"
        "xorl %eax, %eax\n" /* line 1765 */
        /* } scope */
        /* } scope */
        "addl $0x12c, %esp\n" /* line 2226 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf36d08_00036d88:\n"
        "movl %eax, %ecx\n"
        /* { scope 1: tries, f, ospath */
        /* { scope 2 */
        "movl fs_homepath, %eax\n" /* line 697 */
        "movl 8(%eax), %eax\n"
        "movl $0, 4(%esp)\n"
        "leal -0x118(%ebp), %ebx\n" /* ospath */
        "movl %ebx, (%esp)\n"
        "movl $fs_gamedir, %edx\n"
        "calll FS_BuildOSPath_Internal\n"
        "movl %ebx, (%esp)\n" /* line 1765 */
        "calll remove\n"
        "jmp .Lf36d08_00036d7b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf36d08_00036db7:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1916 | size */
        "movl $0, -0x120(%ebp)\n" /* tries */
        "jmp .Lf36d08_00036de4\n"
        ".Lf36d08_00036dc6:\n"
        "movl -0x120(%ebp), %edx\n" /* line 1922 | tries */
        "testl %edx, %edx\n"
        "jne .Lf36d08_00036e0b\n"
        "movl $1, -0x120(%ebp)\n" /* tries */
        ".Lf36d08_00036dda:\n"
        "addl %eax, %edi\n" /* line 1932 | buf */
        "subl %eax, %ebx\n" /* line 1916 */
        "je .Lf36d08_00036d48\n"
        ".Lf36d08_00036de4:\n"
        "movl -0x11c(%ebp), %eax\n" /* line 1919 | f */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* buf */
        "calll FS_FileWrite\n"
        "testl %eax, %eax\n" /* line 1920 */
        "je .Lf36d08_00036dc6\n"
        "cmpl $-1, %eax\n" /* line 1928 */
        "jne .Lf36d08_00036dda\n"
        ".Lf36d08_00036e0b:\n"
        "xorl %ebx, %ebx\n" /* line 1938 */
        "jmp .Lf36d08_00036d62\n"
        /* } scope */
        ".Lf36d08_00036e12:\n"
        "movl 8(%ebp), %eax\n" /* line 2214 | qpath */
        "movl %eax, 4(%esp)\n"
        "movl $str_002173ac, (%esp)\n" /* "Failed to open %s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x12c, %esp\n" /* line 2226 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tries, f, ospath */
        /* { scope 2 */
        ".Lf36d08_00036e32:\n"
        "movl -0x11c(%ebp), %eax\n" /* line 1938 | f */
        "movl %eax, (%esp)\n"
        "calll fflush\n"
        "jmp .Lf36d08_00036d5f\n"
        /* } scope */
        ".Lf36d08_00036e45:\n"
        "movl $1, %eax\n" /* line 2221 */
        /* } scope */
        "addl $0x12c, %esp\n" /* line 2226 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 988 */
__attribute__((naked))
fileHandle_t FS_FOpenTextFileWrite(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 988 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "xorl %esi, %esi\n"
        "movl $fsh, %eax\n"
        "jmp .Lf36e56_00036e79\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf36e56_00036e6b:\n"
        "addl $0x11c, %eax\n" /* line 516 */
        "cmpl $0x3c, %esi\n" /* line 514 */
        "je .Lf36e56_00036f66\n"
        ".Lf36e56_00036e79:\n"
        "addl $1, %esi\n" /* line 516 */
        "movl 0x11c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf36e56_00036e6b\n"
        /* } scope */
        ".Lf36e56_00036e86:\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 999 | h */
        "shll $3, %eax\n"
        "subl %esi, %eax\n" /* h */
        "movl $0, fsh+20(, %eax, 4)\n"
        "movl fs_homepath, %eax\n" /* line 697 */
        "movl 8(%eax), %eax\n"
        "movl $0, 4(%esp)\n"
        "leal -0x118(%ebp), %ebx\n" /* ospath, i */
        "movl %ebx, (%esp)\n" /* i */
        "movl 8(%ebp), %ecx\n" /* filename */
        "movl $fs_gamedir, %edx\n"
        "calll FS_BuildOSPath_Internal\n"
        "movl fs_debug, %eax\n" /* line 1003 */
        "movl 8(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jne .Lf36e56_00036efe\n"
        "movl $str_00216ca0, 4(%esp)\n" /* line 715 */
        "movl %ebx, (%esp)\n" /* i */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf36e56_00036f22\n"
        ".Lf36e56_00036edf:\n"
        "movl %ebx, 4(%esp)\n" /* line 717 | i */
        "movl $str_00216ca4, (%esp)\n" /* "WARNING: refusing to create relative path "%s"
" */
        "calll Com_Printf\n"
        "xorl %esi, %esi\n"
        /* } scope */
        ".Lf36e56_00036ef1:\n"
        "movl %esi, %eax\n" /* line 1029 | h */
        "addl $0x11c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf36e56_00036efe:\n"
        "movl %ebx, 4(%esp)\n" /* line 1004 | i */
        "movl $str_00217394, (%esp)\n" /* "FS_FOpenFileWrite: %s
" */
        "calll Com_Printf\n"
        "movl $str_00216ca0, 4(%esp)\n" /* line 715 */
        "movl %ebx, (%esp)\n" /* i */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "jne .Lf36e56_00036edf\n"
        ".Lf36e56_00036f22:\n"
        "movl $str_00215bf8, 4(%esp)\n" /* "::" */
        "movl %ebx, (%esp)\n" /* i */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "jne .Lf36e56_00036edf\n"
        "movzbl -0x117(%ebp), %eax\n" /* line 721 */
        "testb %al, %al\n"
        "je .Lf36e56_00036fb0\n"
        "movl %ebx, %edi\n" /* i */
        "jmp .Lf36e56_00036f50\n"
        ".Lf36e56_00036f45:\n"
        "movzbl 2(%edi), %eax\n"
        "addl $1, %edi\n"
        "testb %al, %al\n"
        "je .Lf36e56_00036fb0\n"
        ".Lf36e56_00036f50:\n"
        "cmpb $0x2f, %al\n" /* line 723 */
        "jne .Lf36e56_00036f45\n"
        "movb $0, 1(%edi)\n" /* line 726 */
        "movl %ebx, (%esp)\n" /* line 727 | i */
        "calll Sys_Mkdir\n"
        "movb $0x2f, 1(%edi)\n" /* line 728 */
        "jmp .Lf36e56_00036f45\n"
        /* { scope 2 */
        ".Lf36e56_00036f66:\n"
        "movl $1, %ebx\n" /* line 514 | i */
        "movl $fsh+312, %esi\n"
        ".Lf36e56_00036f70:\n"
        "movl %esi, 8(%esp)\n" /* line 524 */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $str_00216c70, (%esp)\n" /* "FILE %2i: '%s'
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 523 | i */
        "addl $0x11c, %esi\n"
        "cmpl $0x4a, %ebx\n" /* i */
        "jne .Lf36e56_00036f70\n"
        "movl $str_00216c80, 4(%esp)\n" /* line 526 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0xffffffff, %esi\n"
        "jmp .Lf36e56_00036e86\n"
        /* } scope */
        ".Lf36e56_00036fb0:\n"
        "movl $str_002173c0, 4(%esp)\n" /* line 1015 */
        "movl %ebx, (%esp)\n" /* i */
        "calll FS_FileOpen\n"
        "leal (%esi, %esi, 8), %ebx\n" /* line 1018 | h, i */
        "shll $3, %ebx\n" /* i */
        "subl %esi, %ebx\n" /* h, i */
        "shll $2, %ebx\n" /* i */
        "movl %eax, fsh(%ebx)\n" /* i */
        "movl $0x100, 8(%esp)\n" /* line 1020 */
        "movl 8(%ebp), %eax\n" /* filename */
        "movl %eax, 4(%esp)\n"
        "leal fsh+28(%ebx), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0, fsh+8(%ebx)\n" /* line 1022 | i */
        "movl fsh(%ebx), %ebx\n" /* line 1023 | i */
        "testl %ebx, %ebx\n" /* i */
        "jne .Lf36e56_00036ef1\n"
        "xorl %esi, %esi\n" /* line 721 */
        "jmp .Lf36e56_00036ef1\n"
    );
}

/* line 1038 */
__attribute__((naked))
fileHandle_t FS_FOpenFileAppend(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1038 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "movl 8(%ebp), %edi\n" /* filename */
        "xorl %ebx, %ebx\n" /* i */
        "movl $fsh, %eax\n"
        "jmp .Lf3700e_00037034\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3700e_00037026:\n"
        "addl $0x11c, %eax\n" /* line 516 */
        "cmpl $0x3c, %ebx\n" /* line 514 | i */
        "je .Lf3700e_0003713b\n"
        ".Lf3700e_00037034:\n"
        "addl $1, %ebx\n" /* line 516 | i */
        "movl 0x11c(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lf3700e_00037026\n"
        /* } scope */
        ".Lf3700e_00037041:\n"
        "leal (%ebx, %ebx, 8), %eax\n" /* line 1049 | h */
        "shll $3, %eax\n"
        "subl %ebx, %eax\n" /* h */
        "shll $2, %eax\n"
        "movl $0, fsh+20(%eax)\n"
        "movl $0x100, 8(%esp)\n" /* line 1051 */
        "movl %edi, 4(%esp)\n" /* filename */
        "addl $fsh+28, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl fs_homepath, %eax\n" /* line 697 */
        "movl 8(%eax), %eax\n"
        "movl $0, 4(%esp)\n"
        "leal -0x118(%ebp), %esi\n" /* ospath */
        "movl %esi, (%esp)\n"
        "movl %edi, %ecx\n"
        "movl $fs_gamedir, %edx\n"
        "calll FS_BuildOSPath_Internal\n"
        "movl fs_debug, %eax\n" /* line 1055 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf3700e_000370d3\n"
        "movl $str_00216ca0, 4(%esp)\n" /* line 715 */
        "movl %esi, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf3700e_000370f7\n"
        ".Lf3700e_000370b4:\n"
        "movl %esi, 4(%esp)\n" /* line 717 */
        "movl $str_00216ca4, (%esp)\n" /* "WARNING: refusing to create relative path "%s"
" */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* i */
        /* } scope */
        ".Lf3700e_000370c6:\n"
        "movl %ebx, %eax\n" /* line 1075 | h */
        "addl $0x11c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3700e_000370d3:\n"
        "movl %esi, 4(%esp)\n" /* line 1056 */
        "movl $str_002173c4, (%esp)\n" /* "FS_FOpenFileAppend: %s
" */
        "calll Com_Printf\n"
        "movl $str_00216ca0, 4(%esp)\n" /* line 715 */
        "movl %esi, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "jne .Lf3700e_000370b4\n"
        ".Lf3700e_000370f7:\n"
        "movl $str_00215bf8, 4(%esp)\n" /* "::" */
        "movl %esi, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "jne .Lf3700e_000370b4\n"
        "movzbl -0x117(%ebp), %eax\n" /* line 721 */
        "testb %al, %al\n"
        "je .Lf3700e_00037182\n"
        "movl %esi, %edi\n"
        "jmp .Lf3700e_00037125\n"
        ".Lf3700e_0003711a:\n"
        "movzbl 2(%edi), %eax\n"
        "addl $1, %edi\n"
        "testb %al, %al\n"
        "je .Lf3700e_00037182\n"
        ".Lf3700e_00037125:\n"
        "cmpb $0x2f, %al\n" /* line 723 */
        "jne .Lf3700e_0003711a\n"
        "movb $0, 1(%edi)\n" /* line 726 */
        "movl %esi, (%esp)\n" /* line 727 */
        "calll Sys_Mkdir\n"
        "movb $0x2f, 1(%edi)\n" /* line 728 */
        "jmp .Lf3700e_0003711a\n"
        /* { scope 2 */
        ".Lf3700e_0003713b:\n"
        "movb $1, %bl\n" /* line 514 | i */
        "movl $fsh+312, %esi\n"
        ".Lf3700e_00037142:\n"
        "movl %esi, 8(%esp)\n" /* line 524 */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $str_00216c70, (%esp)\n" /* "FILE %2i: '%s'
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 523 | i */
        "addl $0x11c, %esi\n"
        "cmpl $0x4a, %ebx\n" /* i */
        "jne .Lf3700e_00037142\n"
        "movl $str_00216c80, 4(%esp)\n" /* line 526 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0xffffffff, %ebx\n" /* i */
        "jmp .Lf3700e_00037041\n"
        /* } scope */
        ".Lf3700e_00037182:\n"
        "movl $str_002173dc, 4(%esp)\n" /* line 1064 */
        "movl %esi, (%esp)\n"
        "calll FS_FileOpen\n"
        "leal (%ebx, %ebx, 8), %edx\n" /* line 1067 | h */
        "shll $3, %edx\n"
        "subl %ebx, %edx\n" /* h */
        "shll $2, %edx\n"
        "movl %eax, fsh(%edx)\n"
        "movl $0, fsh+8(%edx)\n" /* line 1068 */
        "testl %eax, %eax\n" /* line 1069 */
        "jne .Lf3700e_000370c6\n"
        "xorl %ebx, %ebx\n" /* line 721 | i */
        "jmp .Lf3700e_000370c6\n"
    );
}

/* line 3951 */
__attribute__((naked))
int FS_FOpenFileByMode(const char *qpath, fileHandle_t *f, fsMode_t mode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3951 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* f */
        "movl 0x10(%ebp), %eax\n" /* mode */
        /* { scope 1 */
        "cmpl $1, %eax\n" /* line 3958 */
        "je .Lf371bc_0003724a\n"
        "jle .Lf371bc_00037286\n"
        "cmpl $2, %eax\n"
        "je .Lf371bc_00037263\n"
        "cmpl $3, %eax\n"
        "je .Lf371bc_000372d4\n"
        ".Lf371bc_000371e7:\n"
        "movl $str_002173e0, 4(%esp)\n" /* line 4007 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl $0x1b39, %ecx\n"
        ".Lf371bc_00037200:\n"
        "testl %ebx, %ebx\n" /* line 4010 | f */
        "je .Lf371bc_00037241\n"
        "xorl %esi, %esi\n" /* sync */
        "movl (%ebx), %edx\n" /* f */
        ".Lf371bc_00037208:\n"
        "testl %edx, %edx\n" /* line 4014 */
        "je .Lf371bc_00037232\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 4016 */
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl %ecx, fsh+12(, %eax, 4)\n"
        "movl (%ebx), %edx\n" /* line 4017 | f */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl $0, fsh+24(, %eax, 4)\n"
        "movl (%ebx), %edx\n" /* f */
        ".Lf371bc_00037232:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 4019 */
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl %esi, fsh+8(, %eax, 4)\n" /* sync */
        /* } scope */
        ".Lf371bc_00037241:\n"
        "movl %ecx, %eax\n" /* line 4023 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf371bc_0003724a:\n"
        "movl 8(%ebp), %eax\n" /* line 3976 | qpath */
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileWrite\n"
        "movl %eax, (%ebx)\n" /* f */
        "testl %eax, %eax\n" /* line 3978 */
        "je .Lf371bc_0003727b\n"
        "xorl %ecx, %ecx\n"
        "xorl %esi, %esi\n" /* sync */
        "movl (%ebx), %edx\n" /* f */
        "jmp .Lf371bc_00037208\n"
        ".Lf371bc_00037263:\n"
        "xorl %esi, %esi\n" /* line 3958 | sync */
        ".Lf371bc_00037265:\n"
        "movl 8(%ebp), %eax\n" /* line 3999 | qpath */
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileAppend\n"
        "movl %eax, %edx\n"
        "movl %eax, (%ebx)\n" /* f */
        "cmpl $1, %eax\n" /* line 4001 */
        "sbbl %ecx, %ecx\n"
        "jmp .Lf371bc_00037208\n"
        ".Lf371bc_0003727b:\n"
        "movl $0xffffffff, %ecx\n" /* line 3978 */
        "xorl %esi, %esi\n" /* sync */
        "movl (%ebx), %edx\n" /* f */
        "jmp .Lf371bc_00037208\n"
        ".Lf371bc_00037286:\n"
        "testl %eax, %eax\n" /* line 3958 */
        "jne .Lf371bc_000371e7\n"
        /* { scope 2 */
        "movl $1, com_fileAccessed\n" /* line 1659 */
        "movl 8(%ebp), %eax\n" /* line 1664 | qpath, extension */
        "movl %eax, (%esp)\n" /* extension */
        "calll Com_GetExtensionSubString\n"
        "movl %eax, (%esp)\n" /* line 1665 */
        "calll FS_PureIgnoresExtension\n"
        "testl %eax, %eax\n"
        "jne .Lf371bc_000372db\n"
        ".Lf371bc_000372af:\n"
        "movl $0, 4(%esp)\n" /* line 1675 */
        "movl $0, (%esp)\n"
        "movl $1, %ecx\n"
        "movl %ebx, %edx\n"
        "movl 8(%ebp), %eax\n" /* qpath */
        "calll FS_FOpenFileRead_Internal\n"
        "movl %eax, %ecx\n"
        "jmp .Lf371bc_00037200\n"
        /* } scope */
        ".Lf371bc_000372d4:\n"
        "movl $1, %esi\n" /* line 3978 | sync */
        "jmp .Lf371bc_00037265\n"
        /* { scope 2 */
        ".Lf371bc_000372db:\n"
        "movl $1, 4(%esp)\n" /* line 1667 */
        "movl $0, (%esp)\n"
        "movl $1, %ecx\n"
        "movl %ebx, %edx\n"
        "movl 8(%ebp), %eax\n" /* qpath */
        "calll FS_FOpenFileRead_Internal\n"
        "movl %eax, %ecx\n"
        "leal 2(%eax), %eax\n"
        "cmpl $1, %eax\n" /* line 1673 */
        "ja .Lf371bc_00037200\n"
        "jmp .Lf371bc_000372af\n"
    );
}

/* line 3609 */
__attribute__((naked))
float FS_Startup(const char *gameName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3609 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* gameName */
        "movl $str_002173fc, (%esp)\n" /* line 3611 */
        "calll Com_Printf\n"
        "calll FS_RegisterDvars\n" /* line 3613 */
        "movl fs_useOldAssets, %eax\n" /* line 3617 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf3730a_00037354\n"
        "movl fs_basepath, %eax\n" /* line 3619 */
        "movl 8(%eax), %esi\n"
        "cmpb $0, (%esi)\n"
        "jne .Lf3730a_00037a5d\n"
        "movl fs_homepath, %eax\n" /* line 3621 */
        "movl 8(%eax), %esi\n"
        "cmpb $0, (%esi)\n"
        "jne .Lf3730a_00037a22\n"
        ".Lf3730a_00037354:\n"
        "movl fs_basepath, %eax\n" /* line 3625 */
        "movl 8(%eax), %esi\n"
        "cmpb $0, (%esi)\n"
        "jne .Lf3730a_0003792d\n"
        ".Lf3730a_00037365:\n"
        "movl fs_homepath, %eax\n" /* line 3638 */
        "movl 8(%eax), %esi\n" /* path */
        "cmpb $0, (%esi)\n" /* path */
        "jne .Lf3730a_00037838\n"
        ".Lf3730a_00037376:\n"
        "movl fs_cdpath, %eax\n" /* line 3652 */
        "movl 8(%eax), %esi\n" /* path */
        "cmpb $0, (%esi)\n" /* path */
        "jne .Lf3730a_0003770b\n"
        ".Lf3730a_00037387:\n"
        "movl fs_basepath, %eax\n" /* line 3666 */
        "movl 8(%eax), %esi\n" /* path */
        "cmpb $0, (%esi)\n" /* path */
        "jne .Lf3730a_00037671\n"
        ".Lf3730a_00037398:\n"
        "movl fs_basegame, %eax\n" /* line 3675 */
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf3730a_0003752a\n"
        ".Lf3730a_000373a9:\n"
        "movl fs_gameDirVar, %eax\n" /* line 3686 */
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf3730a_00037402\n"
        ".Lf3730a_000373b6:\n"
        "calll Com_ReadCDKey\n" /* line 3698 */
        "calll FS_AddCommands\n" /* line 3703 */
        "movl $1, (%esp)\n" /* line 3091 */
        "calll FS_DisplayPath\n"
        "movl fs_gameDirVar, %eax\n" /* line 3709 */
        "movl %eax, (%esp)\n"
        "calll Dvar_ClearModified\n"
        "movl $str_0021742c, (%esp)\n" /* line 3711 */
        "calll Com_Printf\n"
        "movl fs_packFiles, %eax\n" /* line 3717 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00217444, (%esp)\n" /* "%d files in iwd files
" */
        "calll Com_Printf\n"
        "addl $0x2c, %esp\n" /* line 3718 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf3730a_00037402:\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 3686 */
        "movl %edi, (%esp)\n" /* gameName */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf3730a_000373b6\n"
        "movl %edi, 4(%esp)\n" /* gameName */
        "movl fs_gameDirVar, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf3730a_000373b6\n"
        "movl fs_cdpath, %eax\n" /* line 3688 */
        "movl 8(%eax), %esi\n" /* path */
        "cmpb $0, (%esi)\n" /* path */
        "je .Lf3730a_00037473\n"
        "movl fs_gameDirVar, %eax\n" /* line 3689 */
        "movl 8(%eax), %edi\n" /* dir */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_00037448:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_00037448\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_00037473:\n"
        "movl fs_basepath, %eax\n" /* line 3690 */
        "movl 8(%eax), %esi\n" /* path */
        "cmpb $0, (%esi)\n" /* path */
        "je .Lf3730a_000374b8\n"
        "movl fs_gameDirVar, %eax\n" /* line 3691 */
        "movl 8(%eax), %edi\n" /* dir */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_0003748d:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_0003748d\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_000374b8:\n"
        "movl fs_homepath, %eax\n" /* line 3692 */
        "movl 8(%eax), %edx\n"
        "cmpb $0, (%edx)\n"
        "je .Lf3730a_000373b6\n"
        "movl fs_basepath, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf3730a_000373b6\n"
        "movl fs_gameDirVar, %eax\n" /* line 3693 */
        "movl 8(%eax), %edi\n" /* dir */
        "movl fs_homepath, %eax\n"
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_000374fa:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_000374fa\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "jmp .Lf3730a_000373b6\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_0003752a:\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 3675 */
        "movl %edi, (%esp)\n" /* gameName */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf3730a_000373a9\n"
        "movl %edi, 4(%esp)\n" /* gameName */
        "movl fs_basegame, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf3730a_000373a9\n"
        "movl fs_cdpath, %eax\n" /* line 3677 */
        "movl 8(%eax), %esi\n" /* path */
        "cmpb $0, (%esi)\n" /* path */
        "je .Lf3730a_000375ac\n"
        "movl fs_basegame, %eax\n" /* line 3678 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* dir */
        "movl $0xd, %ebx\n" /* i */
        "movl %eax, %edx\n"
        "jmp .Lf3730a_00037582\n"
        ".Lf3730a_0003757f:\n"
        "movl -0x24(%ebp), %edx\n" /* dir */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_00037582:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_0003757f\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl -0x24(%ebp), %edx\n" /* dir */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_000375ac:\n"
        "movl fs_basepath, %eax\n" /* line 3679 */
        "movl 8(%eax), %esi\n" /* path */
        "cmpb $0, (%esi)\n" /* path */
        "je .Lf3730a_000375fa\n"
        "movl fs_basegame, %eax\n" /* line 3680 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* dir */
        "movl $0xd, %ebx\n" /* i */
        "movl %eax, %edx\n"
        "jmp .Lf3730a_000375d0\n"
        ".Lf3730a_000375cd:\n"
        "movl -0x20(%ebp), %edx\n" /* dir */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_000375d0:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_000375cd\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl -0x20(%ebp), %edx\n" /* dir */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_000375fa:\n"
        "movl fs_homepath, %eax\n" /* line 3681 */
        "movl 8(%eax), %edx\n"
        "cmpb $0, (%edx)\n"
        "je .Lf3730a_000373a9\n"
        "movl fs_basepath, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf3730a_000373a9\n"
        "movl fs_basegame, %eax\n" /* line 3682 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* dir */
        "movl fs_homepath, %eax\n"
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_0003763f:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl -0x1c(%ebp), %edx\n" /* dir */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_0003763f\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl -0x1c(%ebp), %edx\n" /* dir */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "jmp .Lf3730a_000373a9\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_00037671:\n"
        "movl $0xd, %ebx\n" /* line 3666 | i */
        /* { scope 1 */
        ".Lf3730a_00037676:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_00037676\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        "movl fs_basepath, %eax\n" /* line 3671 */
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf3730a_00037398\n"
        "movl %eax, 4(%esp)\n"
        "movl fs_homepath, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf3730a_00037398\n"
        "movl fs_homepath, %eax\n" /* line 3672 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_000376db:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_000376db\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "jmp .Lf3730a_00037398\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_0003770b:\n"
        "movl $0xd, %ebx\n" /* line 3652 | i */
        /* { scope 1 */
        ".Lf3730a_00037710:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_0021741c, %edx\n" /* "devraw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_00037710\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_0021741c, %edx\n" /* "devraw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        "movl fs_cdpath, %eax\n" /* line 3658 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_0003774e:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00216f54, %edx\n" /* "devraw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_0003774e\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00216f54, %edx\n" /* "devraw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        "movl fs_cdpath, %eax\n" /* line 3662 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_0003778c:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00216f48, %edx\n" /* "raw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_0003778c\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00216f48, %edx\n" /* "raw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        "movl fs_cdpath, %eax\n" /* line 3663 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_000377ca:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00216f44, %edx\n" /* "raw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_000377ca\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00216f44, %edx\n" /* "raw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        "movl fs_cdpath, %eax\n" /* line 3664 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_00037808:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_00037808\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "jmp .Lf3730a_00037387\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_00037838:\n"
        "movl $0xd, %ebx\n" /* line 3638 | i */
        /* { scope 1 */
        ".Lf3730a_0003783d:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_0021741c, %edx\n" /* "devraw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_0003783d\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_0021741c, %edx\n" /* "devraw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        "movl fs_homepath, %eax\n" /* line 3644 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_0003787b:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00216f54, %edx\n" /* "devraw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_0003787b\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00216f54, %edx\n" /* "devraw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        "movl fs_homepath, %eax\n" /* line 3648 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_000378b9:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00216f48, %edx\n" /* "raw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_000378b9\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00216f48, %edx\n" /* "raw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        "movl fs_homepath, %eax\n" /* line 3649 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_000378f7:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00216f44, %edx\n" /* "raw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_000378f7\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00216f44, %edx\n" /* "raw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "jmp .Lf3730a_00037376\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_0003792d:\n"
        "movl $0xd, %ebx\n" /* line 3625 | i */
        /* { scope 1 */
        ".Lf3730a_00037932:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_0021741c, %edx\n" /* "devraw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_00037932\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_0021741c, %edx\n" /* "devraw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        "movl fs_basepath, %eax\n" /* line 3631 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_00037970:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00216f54, %edx\n" /* "devraw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_00037970\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00216f54, %edx\n" /* "devraw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        "movl fs_basepath, %eax\n" /* line 3635 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_000379ae:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00216f48, %edx\n" /* "raw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_000379ae\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00216f48, %edx\n" /* "raw_shared" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        /* } scope */
        "movl fs_basepath, %eax\n" /* line 3636 */
        "movl 8(%eax), %esi\n" /* path */
        "movl $0xd, %ebx\n" /* i */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf3730a_000379ec:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00216f44, %edx\n" /* "raw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_000379ec\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00216f44, %edx\n" /* "raw" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "jmp .Lf3730a_00037365\n"
        /* } scope */
        /* } scope */
        ".Lf3730a_00037a22:\n"
        "movl $0xd, %ebx\n" /* line 3621 | i */
        /* { scope 1 */
        ".Lf3730a_00037a27:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00217414, %edx\n" /* "tempcod" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_00037a27\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00217414, %edx\n" /* "tempcod" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "jmp .Lf3730a_00037354\n"
        /* } scope */
        ".Lf3730a_00037a5d:\n"
        "movl $0xd, %ebx\n" /* line 3619 | i */
        /* { scope 1 */
        ".Lf3730a_00037a62:\n"
        "movl %ebx, (%esp)\n" /* line 3402 | i */
        "movl $1, %ecx\n"
        "movl $str_00217414, %edx\n" /* "tempcod" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        "subl $1, %ebx\n" /* line 3401 | i */
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf3730a_00037a62\n"
        "movl $0, (%esp)\n" /* line 3406 */
        "xorl %ecx, %ecx\n"
        "movl $str_00217414, %edx\n" /* "tempcod" */
        "movl %esi, %eax\n"
        "calll FS_AddGameDirectory\n"
        /* } scope */
        "movl fs_homepath, %eax\n" /* line 3621 */
        "movl 8(%eax), %esi\n"
        "cmpb $0, (%esi)\n"
        "je .Lf3730a_00037354\n"
        "jmp .Lf3730a_00037a22\n"
    );
}

/* line 3828 */
__attribute__((naked))
float FS_Restart(int checksumFeed)
{
    __asm__ __volatile__ (
        ".Lf37aaa_00037aaa:\n"
        "pushl %ebp\n" /* line 3828 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* checksumFeed */
        "movl $0, (%esp)\n" /* line 3831 */
        "calll FS_Shutdown\n"
        "movl %ebx, fs_checksumFeed\n" /* line 3835 | checksumFeed */
        "movl fs_searchpaths, %eax\n" /* line 3730 */
        "testl %eax, %eax\n"
        "je .Lf37aaa_00037ae3\n"
        ".Lf37aaa_00037acf:\n"
        "movl 4(%eax), %edx\n" /* line 3733 */
        "testl %edx, %edx\n"
        "je .Lf37aaa_00037add\n"
        "movb $0, 0x310(%edx)\n" /* line 3734 */
        ".Lf37aaa_00037add:\n"
        "movl (%eax), %eax\n" /* line 3730 */
        "testl %eax, %eax\n"
        "jne .Lf37aaa_00037acf\n"
        ".Lf37aaa_00037ae3:\n"
        "movl $str_00216f3c, (%esp)\n" /* line 3843 */
        "calll FS_Startup\n"
        "calll SEH_Init_StringEd\n" /* line 3849 */
        "calll SEH_UpdateLanguageInfo\n" /* line 3850 */
        "calll FS_SetRestrictions\n" /* line 3858 */
        "movl $0, 4(%esp)\n" /* line 3868 */
        "movl $str_0021745c, (%esp)\n" /* "default_mp.cfg" */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n"
        "jle .Lf37aaa_00037ba3\n"
        ".Lf37aaa_00037b1a:\n"
        "movl $lastValidGame, 4(%esp)\n" /* line 3892 */
        "movl fs_gameDirVar, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf37aaa_00037b7c\n"
        ".Lf37aaa_00037b36:\n"
        "movl $0x100, 8(%esp)\n" /* line 3903 */
        "movl fs_basepath, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $lastValidBase, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x100, 8(%esp)\n" /* line 3904 */
        "movl fs_gameDirVar, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $lastValidGame, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x14, %esp\n" /* line 3907 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf37aaa_00037b7c:\n"
        "calll Com_SafeMode\n" /* line 3895 */
        "testl %eax, %eax\n"
        "jne .Lf37aaa_00037b36\n"
        "movl $str_00216300, 4(%esp)\n" /* line 3897 */
        "movl $str_002166d0, (%esp)\n" /* "exec %s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        "jmp .Lf37aaa_00037b36\n"
        ".Lf37aaa_00037ba3:\n"
        "cmpb $0, lastValidBase\n" /* line 3872 */
        "jne .Lf37aaa_00037bcd\n"
        ".Lf37aaa_00037bac:\n"
        "movl $str_0021745c, 8(%esp)\n" /* line 3887 */
        "movl $str_00217484, 4(%esp)\n" /* "Couldn't load %s.  Make sure Call of Duty is run from the co" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf37aaa_00037b1a\n"
        ".Lf37aaa_00037bcd:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 3875 */
        "movl $str_002157b8, (%esp)\n"
        "calll FS_PureServerSetLoadedIwds\n"
        "movl $lastValidBase, 4(%esp)\n" /* line 3877 */
        "movl fs_basepath, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $lastValidGame, 4(%esp)\n" /* line 3878 */
        "movl fs_gameDirVar, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movb $0, lastValidBase\n" /* line 3879 */
        "movb $0, lastValidGame\n" /* line 3880 */
        "movl $0, 4(%esp)\n" /* line 3882 */
        "movl fs_restrict, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "movl %ebx, (%esp)\n" /* line 3884 | checksumFeed */
        "calll FS_Restart\n"
        "movl $str_0021746c, 4(%esp)\n" /* line 3885 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf37aaa_00037bac\n"
    );
}

/* line 3916 */
__attribute__((naked))
qboolean FS_ConditionalRestart(int checksumFeed)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3916 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl imp_com_sv_running, %eax\n" /* line 3919 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf37c50_00037c9a\n"
        "movl fs_gameDirVar, %eax\n" /* line 3923 */
        "cmpb $0, 7(%eax)\n"
        "jne .Lf37c50_00037c88\n"
        "movl 8(%ebp), %eax\n" /* line 3930 | checksumFeed */
        "cmpl %eax, fs_checksumFeed\n"
        "je .Lf37c50_00037c9a\n"
        "movl %eax, (%esp)\n" /* line 3932 */
        "calll FS_Restart\n"
        "movl $1, %eax\n"
        "leave\n" /* line 3938 */
        "retl\n"
        ".Lf37c50_00037c88:\n"
        "movl 8(%ebp), %eax\n" /* line 3925 | checksumFeed */
        "movl %eax, (%esp)\n"
        "calll FS_Restart\n"
        "movl $1, %eax\n"
        "leave\n" /* line 3938 */
        "retl\n"
        ".Lf37c50_00037c9a:\n"
        "xorl %eax, %eax\n" /* line 3933 */
        "leave\n" /* line 3938 */
        "retl\n"
    );
}

/* line 3747 */
__attribute__((naked))
float FS_InitFilesystem(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3747 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $str_00216d24, (%esp)\n" /* line 3754 */
        "calll Com_StartupVariable\n"
        "movl $str_00216d30, (%esp)\n" /* line 3755 */
        "calll Com_StartupVariable\n"
        "movl $str_00216d58, (%esp)\n" /* line 3756 */
        "calll Com_StartupVariable\n"
        "movl $str_00216d64, (%esp)\n" /* line 3757 */
        "calll Com_StartupVariable\n"
        "movl $str_00216d14, (%esp)\n" /* line 3758 */
        "calll Com_StartupVariable\n"
        "movl $str_00216d6c, (%esp)\n" /* line 3760 */
        "calll Com_StartupVariable\n"
        "movl $str_00216a14, (%esp)\n" /* line 3763 */
        "calll Com_StartupVariable\n"
        "calll SEH_InitLanguage\n" /* line 3765 */
        "movl $str_00216f3c, (%esp)\n" /* line 3770 */
        "calll FS_Startup\n"
        "calll SEH_Init_StringEd\n" /* line 3774 */
        "calll SEH_UpdateLanguageInfo\n" /* line 3775 */
        "calll FS_SetRestrictions\n" /* line 3781 */
        "movl $0, 4(%esp)\n" /* line 3789 */
        "movl $str_0021745c, (%esp)\n" /* "default_mp.cfg" */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n"
        "jle .Lf37c9e_00037d72\n"
        ".Lf37c9e_00037d30:\n"
        "movl $0x100, 8(%esp)\n" /* line 3794 */
        "movl fs_basepath, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $lastValidBase, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x100, 8(%esp)\n" /* line 3795 */
        "movl fs_gameDirVar, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $lastValidGame, (%esp)\n"
        "calll I_strncpyz\n"
        "leave\n" /* line 3796 */
        "retl\n"
        ".Lf37c9e_00037d72:\n"
        "movl $str_0021745c, 8(%esp)\n" /* line 3790 */
        "movl $str_00217484, 4(%esp)\n" /* "Couldn't load %s.  Make sure Call of Duty is run from the co" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf37c9e_00037d30\n"
    );
}
#else
float FS_Shutdown(qboolean closemfp) { return 0.0f; }
#endif
