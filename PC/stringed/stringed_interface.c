/* ASM dump from: stringed_interface.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/stringed/stringed_interface.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern int giFilesFound; /* 0x0 */

extern int FS_ReadFile(const char *qpath, void **buffer);
extern void FS_FreeFile(void *buffer);
extern const char **FS_ListFiles(const char *path, const char *extension, int behavior, int *numfiles, int allocTrackType);
extern void FS_FreeFileList(const char **list, int allocTrackType);

/* C++ std::string mangled imports (already declared in imports/libc.h with different signatures) */
/* std::string::append(const char*, size_t) */
extern void *__ZNSs6appendEPKcm(void *_this, const char *s, unsigned int n);
/* std::string::reserve(size_t) */
extern void __ZNSs7reserveEm(void *_this, unsigned int n);
/* std::string::assign(const char*, size_t) */
extern void *__ZNSs6assignEPKcm(void *_this, const char *s, unsigned int n);
/* std::string::_Rep::_S_terminal - the null terminator */
extern char __ZNSs4_Rep11_S_terminalE;

unsigned char * SE_LoadFileData(const char *psFileName);
void SE_FreeFileDataAfterLoad(unsigned char *psLoadedFile);
static void SE_R_ListFiles(const char *psExtension, const char *psDir, LocalizeString *strResults) __attribute_regparm__(3);
int SE_BuildFileList(const char *psStartDir, LocalizeString *strResults);

/* line 31 */
unsigned char * SE_LoadFileData(const char *psFileName)
{
    void *pvLoadedData;

    if (FS_ReadFile(psFileName, &pvLoadedData) > 0) {
        return (unsigned char *)pvLoadedData;
    }
    return (unsigned char *)0;
}

/* line 43 */
void SE_FreeFileDataAfterLoad(unsigned char *psLoadedFile)
{
    FS_FreeFile(psLoadedFile);
}

/* line 53 */
static void __attribute_regparm__(3)
SE_R_ListFiles(const char *psExtension, const char *psDir, LocalizeString *strResults)
{
    char sDirName[64];
    int numdirs;
    int numSysFiles;
    const char **dirFiles;
    const char **sysFiles;
    int i;
    int j;

    /* List subdirectories */
    dirFiles = FS_ListFiles(psDir, "/", 0, &numdirs, 10);
    for (i = 0; i < numdirs; i++) {
        const char *entry = dirFiles[i];
        if (entry[0] == '\0' || entry[0] == '.') {
            continue;
        }
        sprintf(sDirName, "%s/%s", psDir, entry);
        SE_R_ListFiles(psExtension, sDirName, strResults);
    }

    /* List files matching extension */
    sysFiles = FS_ListFiles(psDir, psExtension, 0, &numSysFiles, 10);
    for (j = 0; j < numSysFiles; j++) {
        char *data;
        unsigned int size;
        unsigned int new_size;

        sprintf(sDirName, "%s/%s", psDir, sysFiles[j]);

        /* Append full path to the std::string */
        __ZNSs6appendEPKcm(strResults, sDirName, strlen(sDirName));

        /* Append ';' separator — direct std::string _Rep manipulation */
        data = *(char **)strResults;
        size = *(unsigned int *)(data - 12);
        new_size = size + 1;

        if (new_size > *(unsigned int *)(data - 8) ||
            *(int *)(data - 4) > 0) {
            __ZNSs7reserveEm(strResults, new_size);
            data = *(char **)strResults;
        }

        data[size] = ';';
        *(char **)strResults = data;  /* reload after possible realloc */
        data = *(char **)strResults;
        *(int *)(data - 4) = 0;       /* refcount = 0 */
        *(unsigned int *)(data - 12) = new_size; /* size = new_size */
        data[new_size] = __ZNSs4_Rep11_S_terminalE; /* null terminator */

        giFilesFound++;
    }

    FS_FreeFileList(sysFiles, 10);
    FS_FreeFileList(dirFiles, 10);
}

/* line 90 */
int SE_BuildFileList(const char *psStartDir, LocalizeString *strResults)
{
    giFilesFound = 0;
    __ZNSs6assignEPKcm(strResults, "", 0);
    SE_R_ListFiles("str", psStartDir, strResults);
    return giFilesFound;
}
