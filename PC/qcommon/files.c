/* ASM dump from: files.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/files.cpp */

#include "common_types.h"
#include "imports.h"

static char buf[1024]; /* buf */
static char basename[64]; /* basename */
static char info2[8192]; /* info2 */
static char info3[8192]; /* info3 */
static char info4[8192]; /* info4 */
static char info5[8192]; /* info5 */
static char info6[8192]; /* info6 */
static char info8[8192]; /* info8 */
extern fileHandleData_t fsh[74];
extern const dvar_t *fs_basepath;
extern const dvar_t *fs_cdpath;
extern const dvar_t *fs_debug;
extern const dvar_t *fs_homepath;

fileHandle_t FS_SV_FOpenFileWrite(const char *filename);
int FS_SV_FOpenFileRead(const char *filename, fileHandle_t *fp);
double FS_SV_Rename(const char *from, const char *to);
char * FS_ShiftStr(const char *string, int shift);
double FS_Dir_f(void);
double FS_NewDir_f(void);
double FS_TouchFile_f(void);
qboolean FS_iwIwd(char *iwd, char *base);
double FS_AddCommands(void);
double FS_SetRestrictions(void);
const char * FS_LoadedIwdChecksums(void);
const char * FS_LoadedIwdNames(void);
const char * FS_LoadedIwdPureChecksums(void);
const char * FS_ReferencedIwdChecksums(void);
const char * FS_ReferencedIwdNames(void);
const char * FS_ReferencedIwdPureChecksums(void);
double FS_PureServerSetLoadedIwds(const char *iwdSums, const char *iwdNames);
double FS_PureServerSetReferencedIwds(const char *iwdSums, const char *iwdNames);
const char * FS_GetMapBaseName(const char *mapname);
int FS_GetModList(char *listbuf, int bufsize);
qboolean FS_CompareIwds(char *needediwds, int len, qboolean dlstring);

/* External function declarations */
extern void FS_CheckFileSystemStarted(void);
extern void FS_BuildOSPath(const char *base, const char *game, const char *qpath, char *ospath);
extern fileHandle_t FS_HandleForFile(int flags);
extern int FS_CreatePath(const char *OSPath);
extern void Com_DPrintf(const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern FILE * FS_FileOpen(const char *filename, const char *mode);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern int FS_filelength(fileHandle_t f);
extern int I_stricmp(const char *s1, const char *s2);
extern void FS_CopyFile(const char *from, const char *to);
extern void FS_Remove(const char *ospath);
extern int Cmd_Argc(void);
extern char * Cmd_Argv(int arg);
extern char ** FS_ListFiles(const char *path, const char *extension, int wantSubs, int *numfiles, int flags);
extern void FS_FreeFileList(char **list, int flags);
extern char ** FS_ListFilteredFiles(void *searchPath, const char *path, const char *extension, const char *filter, int *numfiles, int flags);
extern void FS_SortFileList(char **list, int numfiles);
extern void FS_ConvertPath(char *s);
extern void FS_TouchFile(const char *filename);
extern void Cmd_AddCommand(const char *cmdName, void *function);
extern void Dvar_SetBool(const void *dvar, int val);
extern void FS_Shutdown(int flags);
extern void FS_Startup(const char *gameName);
extern int FS_UseSearchPath(void *sp);
extern void Com_Error(int level, const char *fmt, ...);
extern void I_strncat(char *dest, int destsize, const char *src);
extern char * va(const char *fmt, ...);
extern int FS_FilenameCompare(const char *s1, const char *s2);
extern char * strstr(const char *haystack, const char *needle);
extern void I_strlwr(char *s);
extern void Cmd_TokenizeString(const char *text);
extern int atoi(const char *nptr);
extern char * CopyStringInternal(const char *str);
extern void Z_FreeInternal(void *ptr);
extern void FS_ShutdownServerIwdNames(void);
extern void * Com_Memcpy(void *dest, const void *src, size_t count);
extern void SND_StopSounds(int flags);
extern void FS_ShutdownServerReferencedIwds(void);
extern int I_strnicmp(const char *s1, const char *s2, int n);
extern char * stricmp(const char *s1, const char *s2);
extern void * Z_MallocInternal(int size);
extern char ** Sys_ListFiles(const char *directory, const char *extension, const char *filter, int *numfiles, int wantSubs);
extern void Sys_FreeFileList(char **list);
extern void FS_FCloseFile(fileHandle_t f);
extern FILE * FS_FileForHandle(fileHandle_t f);
extern void * Com_Memset(void *dest, int val, size_t count);
extern int FS_FileRead(void *buf, int len, int count, FILE *f);
extern FILE * FS_FileClose(FILE *f);
extern void Com_sprintf(char *dest, int destsize, const char *fmt, ...);

static void FS_SV_BuildOSPath(const char *base, const char *filename, char *ospath, size_t ospathSize)
{
    if (base != NULL && base[0] != '\0') {
        Com_sprintf(ospath, (int)ospathSize, "%s/%s", base, filename);
    } else {
        Com_sprintf(ospath, (int)ospathSize, "%s", filename);
    }
    FS_ConvertPath(ospath);
}

/* line 94 */
fileHandle_t FS_SV_FOpenFileWrite(const char *filename)
{
    char ospath[260];
    fileHandle_t f;
    fileHandleData_t *entry;

    FS_CheckFileSystemStarted(); /* line 99 */

    /* line 101 | build ospath using fs_homepath */
    {
        const dvar_t *homepath_dvar = fs_homepath;
        FS_SV_BuildOSPath(*(const char **)((char *)homepath_dvar + 8), filename, ospath, sizeof(ospath));
    }

    f = FS_HandleForFile(0); /* line 104 */
    entry = &fsh[f];
    entry->zipFile = NULL;
    entry->zipFilePos = 0;
    entry->streamed = 0;

    /* line 107 | if fs_debug, print */
    {
        const dvar_t *debug_dvar = fs_debug;
        if (*(int *)((char *)debug_dvar + 8)) {
            Com_Printf("FS_SV_FOpenFileWrite: %s\n", ospath); /* line 108 */
        }
    }

    /* line 110 */
    if (FS_CreatePath(ospath)) {
        /* line 119 | create path failed */
        return 0;
    }

    /* line 113 */
    Com_DPrintf("writing to: %s\n", ospath);

    /* line 114 | open file for writing */
    entry->handleFiles.file.o = FS_FileOpen(ospath, "wb");

    /* line 116 | store filename in fsh */
    I_strncpyz(entry->name, filename, sizeof(entry->name));

    /* line 118 */
    entry->handleSync = 0;

    /* line 119 | if open failed, return 0 */
    if (entry->handleFiles.file.o == NULL) {
        return 0;
    }

    return f; /* line 124 */
}

/* line 134 */
int FS_SV_FOpenFileRead(const char *filename, fileHandle_t *fp)
{
    char ospath[260];
    fileHandle_t f;
    fileHandleData_t *entry;
    FILE *file;

    FS_CheckFileSystemStarted(); /* line 139 */

    f = FS_HandleForFile(0); /* line 141 */
    entry = &fsh[f];
    entry->zipFile = NULL;
    entry->zipFilePos = 0;
    entry->streamed = 0;
    entry->handleSync = 0;
    entry->handleFiles.file.o = NULL;

    /* line 144 | copy filename into fsh entry */
    I_strncpyz(entry->name, filename, sizeof(entry->name));

    /* line 147 | try homepath */
    {
        const dvar_t *homepath_dvar = fs_homepath;
        FS_SV_BuildOSPath(*(const char **)((char *)homepath_dvar + 8), filename, ospath, sizeof(ospath));
    }

    /* line 151 | if fs_debug, print */
    {
        const dvar_t *debug_dvar = fs_debug;
        if (*(int *)((char *)debug_dvar + 8)) {
            Com_Printf("FS_SV_FOpenFileRead (fs_homepath): %s\n", ospath); /* line 152 */
        }
    }

    /* line 154 | try opening from homepath */
    file = FS_FileOpen(ospath, "rb");
    entry->handleFiles.file.o = file;

    /* line 156 */
    if (file != NULL) {
        goto done; /* file opened successfully */
    }

    /* file not found on homepath; check if homepath == basepath */
    {
        const dvar_t *basepath_dvar = fs_basepath;
        const dvar_t *homepath_dvar = fs_homepath;
        const char *basepath_str = *(const char **)((char *)basepath_dvar + 8);
        const char *homepath_str = *(const char **)((char *)homepath_dvar + 8);

        /* line 159 */
        if (I_stricmp(homepath_str, basepath_str) != 0) {
            /* homepath != basepath; try basepath */
            /* line 162 */
            FS_SV_BuildOSPath(basepath_str, filename, ospath, sizeof(ospath));

            /* line 165 */
            {
                const dvar_t *debug_dvar = fs_debug;
                if (*(int *)((char *)debug_dvar + 8)) {
                    Com_Printf("FS_SV_FOpenFileRead (fs_basepath): %s\n", ospath); /* line 166 */
                }
            }

            /* line 168 */
            file = FS_FileOpen(ospath, "rb");
            entry->handleFiles.file.o = file;

            /* line 171 */
            if (file != NULL) {
                goto done;
            }
        }
    }

    /* line 178 | if fsh slot has no file, try cdpath */
    if (entry->handleFiles.file.o != NULL) {
        goto done;
    }

    /* line 181 | try cdpath */
    {
        const dvar_t *cdpath_dvar = fs_cdpath;
        FS_SV_BuildOSPath(*(const char **)((char *)cdpath_dvar + 8), filename, ospath, sizeof(ospath));
    }

    /* line 184 */
    {
        const dvar_t *debug_dvar = fs_debug;
        if (*(int *)((char *)debug_dvar + 8)) {
            Com_Printf("FS_SV_FOpenFileRead (fs_cdpath) : %s\n", ospath); /* line 185 */
        }
    }

    /* line 187 | try cdpath open */
    file = FS_FileOpen(ospath, "rb");
    entry->handleFiles.file.o = file;
    if (file == NULL) {
        f = 0;
    }

done:
    /* line 196 */
    *fp = f;

    /* line 197 */
    if (f == 0) {
        return 0; /* line 202 */
    }

    return FS_filelength(f); /* line 199 */
}

/* line 211 */
double FS_SV_Rename(const char *from, const char *to)
{
    char from_ospath[260];
    char to_ospath[260];

    FS_CheckFileSystemStarted(); /* line 217 */

    /* line 219 | build from_ospath using fs_homepath */
    {
        const dvar_t *homepath_dvar = fs_homepath;
        FS_BuildOSPath(*(const char **)((char *)homepath_dvar + 8), from, "", from_ospath);
    }

    /* line 220 | build to_ospath using fs_homepath */
    {
        const dvar_t *homepath_dvar = fs_homepath;
        FS_BuildOSPath(*(const char **)((char *)homepath_dvar + 8), to, "", to_ospath);
    }

    from_ospath[strlen(from_ospath) - 1] = '\0'; /* line 221 */
    to_ospath[strlen(to_ospath) - 1] = '\0'; /* line 222 */

    /* line 224 | if fs_debug, print */
    {
        const dvar_t *debug_dvar = fs_debug;
        if (*(int *)((char *)debug_dvar + 8)) {
            Com_Printf("FS_SV_Rename: %s --> %s\n", from_ospath, to_ospath); /* line 225 */
        }
    }

    /* line 227 | try rename */
    if (rename(from_ospath, to_ospath) != 0) {
        /* line 230 | rename failed, try copy+remove */
        FS_CopyFile(from_ospath, to_ospath);
        FS_Remove(from_ospath); /* line 231 */
    }

    return 0.0; /* line 234 */
}

/* line 243 */
char * FS_ShiftStr(const char *string, int shift)
{
    int len;
    int i;

    len = (int)strlen(string); /* line 248 */

    /* line 249 */
    if (len <= 0) {
        buf[0] = '\0'; /* line 251 */
        return buf; /* line 253 */
    }

    /* line 249-251 | shift each character */
    for (i = 0; i < len; i++) { /* line 250 */
        buf[i] = (char)((unsigned char)string[i] + (unsigned char)shift);
    }
    buf[len] = '\0'; /* line 251 */

    return buf; /* line 253 */
}

/* line 607 */
double FS_Dir_f(void)
{
    int argc;
    char *path;
    char *extension;
    char **dirnames;
    int ndirs;
    int i;

    argc = Cmd_Argc(); /* line 615 */

    if (argc - 1 <= 0 || argc > 3) {
        /* line 617 */
        Com_Printf("usage: dir <directory> [extension]\n");
        return 0.0; /* line 642 */
    }

    if (argc == 2) { /* line 621 */
        path = Cmd_Argv(1); /* line 623 */
        extension = ""; /* dirnames used as extension placeholder */
    } else {
        path = Cmd_Argv(1); /* line 628 */
        extension = Cmd_Argv(2); /* line 629 */
    }

    /* line 632 */
    Com_Printf("Directory of %s %s\n", path, extension);
    Com_Printf("---------------\n"); /* line 633 */

    /* line 635 */
    dirnames = FS_ListFiles(path, extension, 0, &ndirs, 10);

    /* line 637 */
    if (ndirs > 0) {
        /* line 637-639 */
        for (i = 0; i < ndirs; i++) {
            Com_Printf("%s\n", dirnames[i]); /* line 639 */
        }
    }

    /* line 641 */
    FS_FreeFileList(dirnames, 10);

    return 0.0; /* line 642 */
}

/* line 650 */
double FS_NewDir_f(void)
{
    char *filter;
    char **dirnames;
    int ndirs;
    int i;

    if (Cmd_Argc() - 1 <= 0) { /* line 657 */
        /* line 659-660 */
        Com_Printf("usage: fdir <filter>\n");
        Com_Printf("example: fdir *q3dm*.bsp\n");
        return 0.0; /* line 679 */
    }

    filter = Cmd_Argv(1); /* line 664 */

    Com_Printf("---------------\n"); /* line 666 */

    /* line 668 | list filtered files starting from fs_searchpaths */
    {
        void *searchpaths = *(void **)*(void **)imp_fs_searchpaths;
        dirnames = FS_ListFilteredFiles(searchpaths, "", "", filter, &ndirs, 10);
    }

    FS_SortFileList(dirnames, ndirs); /* line 670 */

    /* line 672 */
    if (ndirs > 0) {
        for (i = 0; i < ndirs; i++) { /* line 672 */
            FS_ConvertPath(dirnames[i]); /* line 674 */
            Com_Printf("%s\n", dirnames[i]); /* line 675 */
        }
    }

    Com_Printf("%d files listed\n", ndirs); /* line 677 */
    FS_FreeFileList(dirnames, 10); /* line 678 */

    return 0.0; /* line 679 */
}

/* line 690 */
double FS_TouchFile_f(void)
{
    if (Cmd_Argc() != 2) { /* line 692 */
        Com_Printf("Usage: touchFile <file>\n"); /* line 694 */
        return 0.0; /* line 698 */
    }

    FS_TouchFile(Cmd_Argv(1)); /* line 697 */
    return 0.0; /* line 698 */
}

/* line 711 */
qboolean FS_iwIwd(char *iwd, char *base)
{
    int i;
    char *p;
    char szFile[80];

    /* line 717-719 | check iw_NN pattern */
    for (i = 0; i < 25; i++) {
        if (FS_FilenameCompare(iwd, va("%s/iw_%02d", base, i)) == 0) { /* line 719 */
            return 1; /* line 734 */
        }
    }

    /* line 724 | check localized_ pattern */
    p = strstr(iwd, "/localized_"); /* line 724 */
    if (p == NULL) { /* line 725 */
        return 0; /* line 734 */
    }

    /* line 727 | copy iwd path and null-terminate at the localized_ position */
    strcpy(szFile, iwd);
    szFile[p - iwd] = '\0'; /* line 728 */

    /* line 730 | check if it matches "%s/localized_" prefix */
    if (FS_FilenameCompare(szFile, va("%s/localized_", base)) != 0) { /* line 730 */
        return 0; /* line 734 */
    }

    /* line 732 | copy the part after "/localized_" (10 chars) */
    strcpy(szFile, p + 10);
    I_strlwr(szFile); /* line 733 */

    /* line 734-736 | check _iwNN suffix */
    for (i = 0; i < 25; i++) {
        if (strstr(szFile, va("_iw%02d", i)) != NULL) { /* line 736 */
            return 1; /* line 734 */
        }
    }

    return 0; /* line 734 */
}

/* line 875 */
double FS_AddCommands(void)
{
    Cmd_AddCommand("path", *(void **)imp_FS_Path_f); /* line 877 */
    Cmd_AddCommand("fullpath", *(void **)imp_FS_FullPath_f); /* line 878 */
    Cmd_AddCommand("dir", FS_Dir_f); /* line 879 */
    Cmd_AddCommand("fdir", FS_NewDir_f); /* line 880 */
    Cmd_AddCommand("touchFile", FS_TouchFile_f); /* line 881 */
    return 0.0; /* line 882 */
}

/* line 894 */
double FS_SetRestrictions(void)
{
    void *path;
    void *iwd;
    unsigned int checksum;

    /* line 901 | check fs_restrict */
    {
        const dvar_t *restrict_dvar = *(const dvar_t **)imp_fs_restrict;
        if (*(char *)((char *)restrict_dvar + 8) == 0) {
            return 0.0; /* line 936 */
        }

        /* line 906 */
        Dvar_SetBool(restrict_dvar, 1);
    }

    Com_Printf("Restricting pure client, full media required.\n"); /* line 908 */

    FS_Shutdown(0); /* line 911 */
    FS_Startup("main"); /* line 914 */

    /* line 923 | walk search paths and verify checksums */
    path = *(void **)*(void **)imp_fs_searchpaths;
    while (path != NULL) {
        /* line 925 */
        if (FS_UseSearchPath(path)) {
            iwd = *(void **)((char *)path + 4); /* line 928 */
            if (iwd != NULL) {
                checksum = *(unsigned int *)((char *)iwd + 0x304); /* line 931 */
                if (checksum != 0xb1f595f5u) {
                    /* line 932 */
                    Com_Error(0, "Corrupted iw0.iwd: %u", checksum);
                }
            }
        }
        path = *(void **)path; /* line 923 | next */
    }

    return 0.0; /* line 936 */
}

/* line 951 */
const char * FS_LoadedIwdChecksums(void)
{
    void *search;

    info2[0] = '\0'; /* line 955 */

    /* line 957 | walk search paths */
    search = *(void **)*(void **)imp_fs_searchpaths;
    while (search != NULL) {
        void *iwd = *(void **)((char *)search + 4); /* line 960 */
        if (iwd != NULL) {
            void *localized = *(void **)((char *)search + 0xc); /* line 964 */
            if (localized == NULL) {
                int checksum = *(int *)((char *)iwd + 0x304); /* line 967 */
                I_strncat(info2, 0x2000, va("%i ", checksum)); /* line 967 */
            }
        }
        search = *(void **)search; /* line 957 | next */
    }

    return info2; /* line 971 */
}

/* line 982 */
const char * FS_LoadedIwdNames(void)
{
    void *search;

    info3[0] = '\0'; /* line 986 */

    /* line 988 | walk search paths */
    search = *(void **)*(void **)imp_fs_searchpaths;
    while (search != NULL) {
        void *iwd = *(void **)((char *)search + 4); /* line 991 */
        if (iwd != NULL) {
            void *localized = *(void **)((char *)search + 0xc); /* line 995 */
            if (localized == NULL) {
                /* line 998 | append separator if not first */
                if (info3[0] != '\0') {
                    I_strncat(info3, 0x2000, " "); /* line 999 */
                }
                /* line 1001 | append iwd name (at offset 0x100 = gamename) */
                I_strncat(info3, 0x2000, (char *)iwd + 0x100);
            }
        }
        search = *(void **)search; /* line 988 | next */
    }

    return info3; /* line 1005 */
}

/* line 1017 */
const char * FS_LoadedIwdPureChecksums(void)
{
    void *search;

    info4[0] = '\0'; /* line 1021 */

    /* line 1023 | walk search paths */
    search = *(void **)*(void **)imp_fs_searchpaths;
    while (search != NULL) {
        void *iwd = *(void **)((char *)search + 4); /* line 1026 */
        if (iwd != NULL) {
            void *localized = *(void **)((char *)search + 0xc); /* line 1030 */
            if (localized == NULL) {
                int checksum = *(int *)((char *)iwd + 0x308); /* line 1033 */
                I_strncat(info4, 0x2000, va("%i ", checksum));
            }
        }
        search = *(void **)search; /* line 1023 | next */
    }

    return info4; /* line 1037 */
}

/* line 1048 */
const char * FS_ReferencedIwdChecksums(void)
{
    void *search;

    info5[0] = '\0'; /* line 1052 */

    /* line 1054 | walk search paths */
    search = *(void **)*(void **)imp_fs_searchpaths;
    while (search != NULL) {
        void *iwd = *(void **)((char *)search + 4); /* line 1057 */
        if (iwd != NULL) {
            /* line 1060 | skip if gamedir is "main" and no referenced flag */
            int referenced = *(char *)((char *)iwd + 0x310);
            if (!referenced) {
                /* check if gamename == "main" */
                if (I_strnicmp((char *)iwd + 0x200, "main", 4) == 0) {
                    /* skip this entry */
                    search = *(void **)search;
                    continue;
                }
                /* re-fetch iwd after I_strnicmp path */
                iwd = *(void **)((char *)search + 4);
            }
            /* line 1061 */
            {
                int checksum = *(int *)((char *)iwd + 0x304);
                I_strncat(info5, 0x2000, va("%i ", checksum));
            }
        }
        search = *(void **)search; /* line 1054 | next */
    }

    return info5; /* line 1065 */
}

/* line 1076 */
const char * FS_ReferencedIwdNames(void)
{
    void *search;

    info8[0] = '\0'; /* line 1080 */

    /* line 1084 | walk search paths */
    search = *(void **)*(void **)imp_fs_searchpaths;
    while (search != NULL) {
        void *iwd = *(void **)((char *)search + 4); /* line 1087 */
        if (iwd != NULL) {
            int referenced = *(char *)((char *)iwd + 0x310); /* line 1090 */
            if (!referenced) {
                /* check if gamename == "main" */
                if (I_strnicmp((char *)iwd + 0x200, "main", 4) == 0) {
                    /* skip: move to next */
                    search = *(void **)search;
                    continue;
                }
            }
            /* line 1092 | append separator if not first */
            if (info8[0] != '\0') {
                I_strncat(info8, 0x2000, " "); /* line 1093 */
            }
            /* line 1095 | append gamedir (at offset 0x200) */
            I_strncat(info8, 0x2000, (char *)iwd + 0x200);
            I_strncat(info8, 0x2000, " "); /* line 1096 | separator */
            /* line 1097 | append iwd name (at offset 0x100) */
            I_strncat(info8, 0x2000, (char *)iwd + 0x100);
        }
        search = *(void **)search; /* line 1084 | next */
    }

    return info8; /* line 1102 */
}

/* line 1119 */
const char * FS_ReferencedIwdPureChecksums(void)
{
    void *search;
    int numIwds;
    int checksumFeed;

    info6[0] = '\0'; /* line 1124 */

    checksumFeed = *(int *)*(void **)imp_fs_checksumFeed; /* line 1125 */

    /* line 1136 | walk search paths */
    search = *(void **)*(void **)imp_fs_searchpaths;
    numIwds = 0;
    if (search == NULL) {
        goto no_searchpaths;
    }

    while (search != NULL) {
        void *iwd = *(void **)((char *)search + 4); /* line 1139 */
        if (iwd != NULL) {
            void *localized = *(void **)((char *)search + 0xc); /* line 1143 */
            if (localized == NULL) {
                int referenced = *(char *)((char *)iwd + 0x310); /* line 1147 */
                if (referenced) {
                    int checksum = *(int *)((char *)iwd + 0x308); /* line 1149 */
                    I_strncat(info6, 0x2000, va("%i ", checksum));
                    checksumFeed ^= checksum; /* line 1150 */
                    numIwds++; /* line 1151 */
                }
            }
        }
        search = *(void **)search; /* line 1136 | next */
    }

    /* line 1155 | optionally append fakeChkSum */
    {
        int fakeChk = *(int *)*(void **)imp_fs_fakeChkSum;
        if (fakeChk != 0) {
            I_strncat(info6, 0x2000, va("%i ", fakeChk)); /* line 1156 */
        }
    }

    /* line 1160 | append final XOR of numIwds and checksumFeed */
    numIwds ^= checksumFeed;
    I_strncat(info6, 0x2000, va("%i ", numIwds));

    return info6; /* line 1163 */

no_searchpaths:
    numIwds = 0;
    /* jump to fakeChkSum check */
    {
        int fakeChk = *(int *)*(void **)imp_fs_fakeChkSum;
        if (fakeChk != 0) {
            I_strncat(info6, 0x2000, va("%i ", fakeChk));
        }
    }
    numIwds ^= checksumFeed;
    I_strncat(info6, 0x2000, va("%i ", numIwds));

    return info6;
}

/* line 1514 */
double FS_PureServerSetLoadedIwds(const char *iwdSums, const char *iwdNames)
{
    int serverIwds[1024];
    char *serverIwdNames[1024];
    int c;
    int d;
    int i;
    int j;

    /* line 1523 | tokenize sums string */
    Cmd_TokenizeString(iwdSums);
    c = Cmd_Argc(); /* line 1524 */
    if (c > 0x400) { /* line 1525 */
        c = 0x400;
    }

    /* line 1529 | parse sums into array */
    if (c > 0) {
        for (i = 0; i < c; i++) { /* line 1529 */
            serverIwds[i] = atoi(Cmd_Argv(i)); /* line 1531 */
        }
    }

    /* line 1534 | tokenize names string */
    Cmd_TokenizeString(iwdNames);
    d = Cmd_Argc(); /* line 1535 */
    if (d > 0x400) { /* line 1536 */
        d = 0x400;
    }

    /* line 1540 | parse names into array */
    if (d > 0) {
        for (i = 0; i < d; i++) { /* line 1540 */
            serverIwdNames[i] = CopyStringInternal(Cmd_Argv(i)); /* line 1542 */
        }
    }

    /* line 1544 | counts must match */
    if (c != d) {
        Com_Error(1, "FS_PureServerSetLoadedIwds: count mismatch"); /* line 1545 */
    }

    /* line 1548 | check if list changed */
    {
        int *fs_numServerIwds = (int *)*(void **)imp_fs_numServerIwds;
        if (c == *fs_numServerIwds) {
            /* line 1550 | same count; check each entry */
            int changed = 0;
            int local_i;

            if (c <= 0) {
                goto free_names_and_return;
            }

            for (local_i = 0; local_i < c; local_i++) {
                /* line 1552 | for each new entry, find it in old list */
                int numOld = *fs_numServerIwds;
                if (numOld <= 0) {
                    goto do_reload;
                }

                {
                    int *fs_serverIwds = (int *)*(void **)imp_fs_serverIwds;
                    char **fs_serverIwdNames = (char **)*(void **)imp_fs_serverIwdNames;

                    for (j = 0; j < numOld; j++) { /* line 1552 */
                        /* line 1554 | compare sum */
                        if (serverIwds[local_i] == fs_serverIwds[j]) {
                            /* line 1556 | compare name */
                            if (I_stricmp(fs_serverIwdNames[j], serverIwdNames[local_i]) == 0) {
                                break; /* found match */
                            }
                        }
                    }

                    if (j >= numOld) {
                        /* not found => list changed */
                        goto do_reload;
                    }
                }
            }

            /* all matched */
            goto free_names_and_return;

free_names_and_return:
            /* line 1560 | free temp names */
            if (d > 0) {
                for (i = 0; i < d; i++) {
                    Z_FreeInternal(serverIwdNames[i]); /* line 1561 */
                }
            }
            return 0.0; /* line 1581 */
        }
    }

do_reload:
    /* line 1568 */
    SND_StopSounds(8);
    FS_ShutdownServerIwdNames(); /* line 1571 */

    {
        int *fs_numServerIwds = (int *)*(void **)imp_fs_numServerIwds;
        *fs_numServerIwds = c; /* line 1573 */

        if (c == 0) {
            return 0.0; /* line 1581 */
        }

        Com_DPrintf("Setting pure server iwds\n"); /* line 1576 */

        /* line 1577 | copy sums */
        Com_Memcpy(*(void **)imp_fs_serverIwds, serverIwds, c * 4);
        /* line 1578 | copy names */
        Com_Memcpy(*(void **)imp_fs_serverIwdNames, serverIwdNames, c * 4);

        /* line 1579 */
        *(int *)*(void **)imp_fs_fakeChkSum = 0;
    }

    return 0.0; /* line 1581 */
}

/* line 1593 */
double FS_PureServerSetReferencedIwds(const char *iwdSums, const char *iwdNames)
{
    int c;
    int d;
    int i;
    int *fs_serverReferencedIwds;
    char **fs_serverReferencedIwdNames;

    /* line 1597 */
    Cmd_TokenizeString(iwdSums);
    c = Cmd_Argc(); /* line 1599 */
    if (c >= 0x401) { /* line 1600 */
        c = 0x400;
    }

    FS_ShutdownServerReferencedIwds(); /* line 1605 */

    /* line 1607 | fill referenced iwds array with sums */
    fs_serverReferencedIwds = (int *)*(void **)imp_fs_serverReferencedIwds;
    if (c > 0) {
        for (i = 0; i < c; i++) { /* line 1607 */
            fs_serverReferencedIwds[i] = atoi(Cmd_Argv(i)); /* line 1609 */
        }
    }

    /* line 1611 | if no names string or empty, skip names parsing */
    if (iwdNames == NULL || iwdNames[0] == '\0') {
        /* line 1631 | count must be 0 if no names provided */
        if (c != 0) {
            Com_Error(1, "FS_PureServerSetReferencedIwds: count mismatch"); /* line 1632 */
        }
        /* line 1635 */
        *(int *)*(void **)imp_fs_numServerReferencedIwds = c;
        return 0.0; /* line 1636 */
    }

    /* line 1613 | tokenize names */
    Cmd_TokenizeString(iwdNames);
    d = Cmd_Argc(); /* line 1615 */
    if (d >= 0x401) { /* line 1616 */
        d = 0x400;
    }

    /* line 1621 | counts must match */
    if (c != d) {
        Com_Error(1, "FS_PureServerSetReferencedIwds: count mismatch"); /* line 1622 */
    }

    /* line 1624 | fill referenced iwd names */
    if (d > 0) {
        fs_serverReferencedIwdNames = (char **)*(void **)imp_fs_serverReferencedIwdNames;
        for (i = 0; i < d; i++) { /* line 1624 */
            fs_serverReferencedIwdNames[i] = CopyStringInternal(Cmd_Argv(i)); /* line 1626 */
        }
    }

    /* line 1635 */
    *(int *)*(void **)imp_fs_numServerReferencedIwds = c;
    return 0.0; /* line 1636 */
}

/* line 1644 */
const char * FS_GetMapBaseName(const char *mapname)
{
    int len;
    int i;
    char *p;

    /* line 1652 | strip "maps/mp/" prefix if present */
    if (I_strnicmp(mapname, "maps/mp/", 8) == 0) {
        mapname += 8; /* line 1653 */
    }

    len = (int)strlen(mapname); /* line 1654 */

    /* line 1655 | strip ".bsp" extension if present */
    if (stricmp(mapname + len - 3, ".bsp") == 0) { /* actually last 4 chars: ".bsp" */
        len -= 4; /* line 1656 */
    }

    /* line 1657 | copy len bytes */
    memcpy(basename, mapname, len);
    basename[len] = '\0'; /* line 1658 */

    /* line 1661-1664 | replace '%' with '_' */
    p = basename;
    while (p < basename + len) {
        if (*p == '%') { /* line 1663 */
            *p = '_'; /* line 1664 */
        }
        p++;
    }

    return basename; /* line 1668 */
}

/* line 465 */
int FS_GetModList(char *listbuf, int bufsize)
{
    char **pFiles0;
    char **pFiles1;
    char **pFiles2;
    char **pFiles;
    int dummy;
    int nTotal;
    int nMods;
    int nFiles;
    int i;
    int j;
    int bDrop;
    char *name;
    int nameLen;
    int descLen;
    char path[256];
    char descPath[256];
    fileHandle_t descHandle;
    FILE *descFile;
    int nIwds;

    listbuf[0] = '\0'; /* line 481 */

    /* line 484 | list directories in homepath */
    {
        const dvar_t *homepath_dvar = fs_homepath;
        pFiles0 = Sys_ListFiles(*(const char **)((char *)homepath_dvar + 8), NULL, NULL, &dummy, 1);
    }

    /* line 485 | list directories in basepath */
    {
        const dvar_t *basepath_dvar = fs_basepath;
        pFiles1 = Sys_ListFiles(*(const char **)((char *)basepath_dvar + 8), NULL, NULL, &dummy, 1);
    }

    /* line 486 | list directories in cdpath if set */
    {
        const dvar_t *cdpath_dvar = fs_cdpath;
        const char *cdpath_str = *(const char **)((char *)cdpath_dvar + 8);
        if (cdpath_str == NULL || cdpath_str[0] == '\0') {
            pFiles2 = NULL; /* line 487 */
        } else {
            pFiles2 = Sys_ListFiles(cdpath_str, NULL, NULL, &dummy, 1); /* line 487 */
        }
    }

    /* Count total files from all three lists */
    {
        int n0 = 0, n1 = 0, n2 = 0;
        if (pFiles0 != NULL && pFiles0[0] != NULL) {
            while (pFiles0[n0] != NULL) n0++;
        }
        if (pFiles1 != NULL && pFiles1[0] != NULL) {
            while (pFiles1[n1] != NULL) n1++;
        }
        if (pFiles2 != NULL && pFiles2[0] != NULL) {
            while (pFiles2[n2] != NULL) n2++;
        }

        /* line 421 | allocate merged list */
        pFiles = (char **)Z_MallocInternal((n0 + n1 + n2 + 1) * 4);

        /* line 424-441 | copy all lists into merged list */
        {
            int idx = 0;
            if (pFiles0 != NULL) {
                for (j = 0; pFiles0[j] != NULL; j++) {
                    pFiles[idx++] = pFiles0[j];
                }
            }
            if (pFiles1 != NULL) {
                for (j = 0; pFiles1[j] != NULL; j++) {
                    pFiles[idx++] = pFiles1[j];
                }
            }
            if (pFiles2 != NULL) {
                for (j = 0; pFiles2[j] != NULL; j++) {
                    pFiles[idx++] = pFiles2[j];
                }
            }
            pFiles[idx] = NULL;
        }

        /* line 445-450 | free original lists */
        if (pFiles0 != NULL) Z_FreeInternal(pFiles0);
        if (pFiles1 != NULL) Z_FreeInternal(pFiles1);
        if (pFiles2 != NULL) Z_FreeInternal(pFiles2);
    }

    /* line 493 | count entries in merged list */
    nFiles = 0;
    if (pFiles == NULL || pFiles[0] == NULL) {
        nMods = 0;
        goto cleanup;
    }
    while (pFiles[nFiles] != NULL) nFiles++;

    if (nFiles <= 0) {
        nMods = 0;
        goto cleanup;
    }

    bDrop = 0;
    nTotal = 0;
    nMods = 0;

    /* line 493 | iterate all directory entries */
    for (i = 0; i < nFiles; i++) {
        name = pFiles[i];
        nameLen = (int)strlen(name);

        /* line 498 | skip if first entry (i==0 special case in asm) */
        if (i != 0) {
            /* line 501 | check for duplicate in already-processed entries */
            bDrop = 0;
            for (j = 0; j < i; j++) {
                if (I_stricmp(pFiles[j], name) == 0) { /* line 503 */
                    bDrop = 1; /* line 511 */
                    break;
                }
            }
        } else {
            bDrop = 0;
        }

        if (bDrop) {
            continue; /* line 511 */
        }

        /* line 516 | skip hidden dirs starting with "." */
        if (I_strnicmp(name, ".", 1) == 0) {
            continue;
        }

        /* line 523 | build path for this mod dir using basepath */
        {
            const dvar_t *basepath_dvar = fs_basepath;
            FS_BuildOSPath(*(const char **)((char *)basepath_dvar + 8), name, "", path);
        }

        /* line 524-525 | check if this dir has any iwd files */
        nIwds = 0;
        Sys_FreeFileList(Sys_ListFiles(path, "iwd", NULL, &nIwds, 0)); /* line 525-526 */

        if (nIwds <= 0) { /* line 529 */
            /* try cdpath */
            {
                const dvar_t *cdpath_dvar = fs_cdpath;
                FS_BuildOSPath(*(const char **)((char *)cdpath_dvar + 8), name, "", path);
            }
            nIwds = 0;
            Sys_FreeFileList(Sys_ListFiles(path, "iwd", NULL, &nIwds, 0)); /* line 533-534 */

            if (nIwds <= 0) { /* line 538 */
                /* try homepath */
                {
                    const dvar_t *homepath_dvar = fs_homepath;
                    FS_BuildOSPath(*(const char **)((char *)homepath_dvar + 8), name, "", path);
                }
                nIwds = 0;
                Sys_FreeFileList(Sys_ListFiles(path, "iwd", NULL, &nIwds, 0)); /* line 542-543 */

                if (nIwds <= 0) { /* line 546 */
                    continue;
                }
            }
        }

        /* line 548 | compute nameLen */
        nameLen = (int)strlen(name);

        /* line 551 | build descPath = name + "/description.txt" */
        strcpy(descPath, name);
        I_strncat(descPath, 0x100, "/description.txt"); /* line 552 */

        /* line 553 | try to open description file */
        if (FS_SV_FOpenFileRead(descPath, &descHandle) > 0 && descHandle != 0) {
            /* line 558 | read description */
            descFile = FS_FileForHandle(descHandle);
            Com_Memset(descPath, 0, 0x100); /* line 559 */
            {
                int nread = FS_FileRead(descPath, 1, 0x30, descFile); /* line 560 */
                if (nread >= 0) { /* line 561 */
                    descPath[nread] = '\0'; /* line 563 */
                }
            }
            FS_FCloseFile(descHandle); /* line 565 */
        } else if (I_stricmp(name, "main") == 0) { /* line 568 */
            /* line 570 | hardcoded description for "main" */
            strcpy(descPath, "Call of 2 Multiplayer");
        } else {
            /* line 574 | use mod dir name as description */
            strcpy(descPath, name);
        }

        /* line 576 | compute descLen */
        descLen = (int)strlen(descPath);

        /* line 578 | check if we have room */
        if (nTotal + nameLen + descLen + 2 >= bufsize) {
            break; /* line 585 => line 594 */
        }

        /* line 580 | append name to listbuf */
        strcpy(listbuf, name);
        /* line 581 | listbuf now points past name */
        listbuf += nameLen;
        /* line 582 | append desc */
        strcpy(listbuf, descPath);
        listbuf += descLen; /* line 583 */
        /* line 584 | update total */
        nTotal += nameLen + descLen;
        nMods++; /* line 585 */
    }

cleanup:
    /* line 594 */
    Sys_FreeFileList(pFiles);

    return nMods; /* line 597 */
}

/* line 772 */
qboolean FS_CompareIwds(char *needediwds, int len, qboolean dlstring)
{
    int i;
    int numServerIwds;
    int *fs_serverReferencedIwds;
    char **fs_serverReferencedIwdNames;
    char testpath[264];

    /* line 778 */
    numServerIwds = *(int *)*(void **)imp_fs_numServerReferencedIwds;
    if (numServerIwds == 0) {
        return 0; /* line 848 */
    }

    needediwds[0] = '\0'; /* line 781 */

    if (numServerIwds <= 0) {
        /* line 845 */
        if (needediwds[0] != '\0') {
            goto need_iwds;
        }
        return 0; /* line 848 */
    }

    /* line 783 | iterate server-referenced iwds */
    fs_serverReferencedIwdNames = (char **)*(void **)imp_fs_serverReferencedIwdNames;
    fs_serverReferencedIwds = (int *)*(void **)imp_fs_serverReferencedIwds;

    for (i = 0; i < numServerIwds; i++) { /* line 783 */
        char *iwdName = fs_serverReferencedIwdNames[i];
        int iwdChecksum = fs_serverReferencedIwds[i];

        /* line 790 | skip if it's a base iwd */
        if (FS_iwIwd(iwdName, "main") != 0) {
            goto next_iwd; /* line 672 */
        }

        /* line 793 | check if this iwd is in search paths */
        {
            void *search = *(void **)*(void **)imp_fs_searchpaths;
            int found = 0;
            while (search != NULL) {
                void *iwd = *(void **)((char *)search + 4); /* line 795 */
                if (iwd != NULL) {
                    int chk = *(int *)((char *)iwd + 0x304);
                    if (chk == iwdChecksum) { /* line 795 */
                        found = 1;
                        break;
                    }
                }
                search = *(void **)search; /* line 793 | next */
            }
            if (found) {
                goto next_iwd;
            }
        }

        /* line 802 | iwd not found; check name */
        if (iwdName == NULL || iwdName[0] == '\0') {
            goto next_iwd;
        }

        /* line 806 | dlstring or not */
        if (!dlstring) {
            /* line 833 | non-dlstring: append name to needediwds */
            I_strncat(needediwds, len, iwdName);
            I_strncat(needediwds, len, " ");

            /* line 836 | build testpath and check if file exists locally */
            {
                char *iwdFile = va("%s.iwd", iwdName);
                const dvar_t *homepath_dvar = fs_homepath;
                FS_BuildOSPath(*(const char **)((char *)homepath_dvar + 8), iwdFile, "", testpath);
                testpath[strlen(testpath) - 1] = '\0'; /* line 76 */

                {
                    FILE *f = FS_FileOpen(testpath, "rb"); /* line 78 */
                    if (f != NULL) {
                        FS_FileClose(f); /* line 81 */
                        /* line 838 | file exists, append marker */
                        I_strncat(needediwds, len, "@");
                    }
                }
            }

            I_strncat(needediwds, len, " "); /* line 840 */
        } else {
            /* line 809 | dlstring mode */
            I_strncat(needediwds, len, "@");
            I_strncat(needediwds, len, iwdName); /* line 810 */
            I_strncat(needediwds, len, " "); /* line 811 */

            /* line 814 */
            I_strncat(needediwds, len, "@");

            /* line 816 | build checksum filename */
            {
                char *iwdFile = va("%s.iwd", iwdName);
                const dvar_t *homepath_dvar = fs_homepath;
                FS_BuildOSPath(*(const char **)((char *)homepath_dvar + 8), iwdFile, "", testpath);
                testpath[strlen(testpath) - 1] = '\0';

                {
                    FILE *f = FS_FileOpen(testpath, "rb");
                    if (f != NULL) {
                        FS_FileClose(f);
                        /* line 822 | file exists; append sum.checksum.iwd */
                        Com_sprintf(testpath, 0x100, "%s.%08x.iwd", iwdName, iwdChecksum);
                        I_strncat(needediwds, len, testpath); /* line 823 */
                    } else {
                        /* line 827 | file not found; append name alone */
                        I_strncat(needediwds, len, iwdName);
                        I_strncat(needediwds, len, " "); /* line 828 */
                    }
                }
            }

            I_strncat(needediwds, len, " "); /* line 840 */
        }

next_iwd:
        /* advance pointers (i incremented by loop) */
        ;
    }

    /* line 845 */
    if (needediwds[0] == '\0') {
        return 0; /* line 848 */
    }

need_iwds:
    Com_Printf("Need iwds: %s\n", needediwds); /* line 847 */
    return 1;
}
