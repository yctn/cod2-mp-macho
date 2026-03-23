/* ASM dump from: MacFolders.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacFolders.cp */

#include "common_types.h"
#include "imports.h"

#include <string.h>

#define noErr 0

static SInt16 sAppFolderVRefNum; /* 0x334a0c */
static SInt32 sAppFolderDirID; /* 0x334a08 */
static FSRef sAppBundleRef; /* 0x334a20 */
static SInt32 sExecutableDirID; /* 0x334a04 */
static SInt32 sDataFolderDirID; /* 0x334a00 */

SInt32 MacFolders_GetExecutableFolderID(void);
OSStatus MacFolders_GetApplicationFolderItemPath(const char *inItem, char *outPath, int inMaxPath);
OSStatus MacFolders_GetApplicationFolderItemRef(const char *inItem, FSRef *outRef);
SInt32 MacFolders_GetDataFolderID(void);
OSStatus MacFolders_GetDataFolderPath(char *outPath, int inMaxPath);
OSStatus MacFolders_GetDataFolderItemPath(const char *inItem, char *outPath, int inMaxPath);
OSStatus MacFolders_GetDataFolderItemRef(const char *inItem, FSRef *outRef);
SInt16 MacFolders_GetApplicationVRefNum(void);
unsigned char MacFolders_GetApplicationRef(FSRef *outRef);

extern void MacFiles_CleanPath(const char *inPath, char *outPath, int inForHFS);

/*
 * Inline helper: ensure sAppFolderVRefNum and sAppFolderDirID are initialized.
 * Corresponds to the repeated "EnsureAppFolderInitialized" pattern at line 32-46.
 */
static void EnsureAppFolderInitialized(void)
{
    ProcessSerialNumber psn;
    FSCatalogInfo info;

    if (sAppFolderDirID != 0)
        return;

    if (GetCurrentProcess(&psn) != noErr)
        return;

    if (GetProcessBundleLocation(&psn, &sAppBundleRef) != noErr)
        return;

    if (FSGetCatalogInfo(&sAppBundleRef, 0xC, &info, NULL, NULL, NULL) != noErr)
        return;

    sAppFolderVRefNum = info.volume;
    sAppFolderDirID = info.parentDirID;
}

SInt32 MacFolders_GetExecutableFolderID(void)
{
    return 0;
}

OSStatus MacFolders_GetApplicationFolderItemPath(const char *inItem, char *outPath, int inMaxPath)
{
    return 0;
}

/* line 153 */
OSStatus MacFolders_GetApplicationFolderItemRef(const char *inItem, FSRef *outRef)
{
    char path[0x400];
    OSStatus error;

    error = MacFolders_GetApplicationFolderItemPath(inItem, path, 0x400);
    if (error != noErr)
        return error;

    return FSPathMakeRef((const UInt8 *)path, outRef, NULL);
}

SInt32 MacFolders_GetDataFolderID(void)
{
    return 0;
}

OSStatus MacFolders_GetDataFolderPath(char *outPath, int inMaxPath)
{
    return 0;
}

/* line 311 */
OSStatus MacFolders_GetDataFolderItemPath(const char *inItem, char *outPath, int inMaxPath)
{
    FSSpec spec;
    FSRef ref;
    OSStatus error;

    EnsureAppFolderInitialized();

    /* Build FSSpec from app folder vRefNum + data folder dir ID */
    spec.vRefNum = sAppFolderVRefNum;
    spec.parID = MacFolders_GetDataFolderID();
    spec.name[0] = 0;

    /* Convert FSSpec -> FSRef */
    error = FSpMakeFSRef(&spec, &ref);
    if (error != noErr)
        return error;

    /* Convert FSRef -> POSIX path */
    error = FSRefMakePath(&ref, (UInt8 *)outPath, inMaxPath);
    if (error != noErr)
        return error;

    /* Append inItem with '/' separator if needed */
    if (inItem[0] != '/' && inItem[0] != '\\') {
        size_t len = strlen(outPath);
        outPath[len] = '/';
        outPath[len + 1] = '\0';
    }

    strcat(outPath, inItem);
    MacFiles_CleanPath(outPath, outPath, 0);

    return noErr;
}

/* line 332 */
OSStatus MacFolders_GetDataFolderItemRef(const char *inItem, FSRef *outRef)
{
    char path[0x400];
    OSStatus error;

    error = MacFolders_GetDataFolderItemPath(inItem, path, 0x400);
    if (error != noErr)
        return error;

    return FSPathMakeRef((const UInt8 *)path, outRef, NULL);
}

/* line 58 */
SInt16 MacFolders_GetApplicationVRefNum(void)
{
    EnsureAppFolderInitialized();

    return sAppFolderVRefNum;
}

/* line 69 */
unsigned char MacFolders_GetApplicationRef(FSRef *outRef)
{
    EnsureAppFolderInitialized();

    memcpy(outRef, &sAppBundleRef, sizeof(FSRef));

    return 0;
}
