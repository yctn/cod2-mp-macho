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

#ifndef __EMSCRIPTEN__
/* line 185 */
__attribute__((naked))
SInt32 MacFolders_GetExecutableFolderID(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 185 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x100, %esp\n"
        "movl sExecutableDirID, %edx\n" /* line 187 */
        "testl %edx, %edx\n"
        "je .Lf8f96_00008fba\n"
        /* { scope 1: execRef */
        /* { scope 2: info */
        ".Lf8f96_00008fab:\n"
        "movl sExecutableDirID, %eax\n" /* line 203 */
        /* } scope */
        /* } scope */
        "addl $0x100, %esp\n" /* line 208 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: execRef */
        ".Lf8f96_00008fba:\n"
        "calll CFBundleGetMainBundle\n" /* line 189 */
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyExecutableURL\n"
        "movl %eax, %ebx\n" /* urlRef */
        "testl %eax, %eax\n" /* line 190 */
        "je .Lf8f96_00008fab\n"
        /* { scope 2: info */
        "leal -0x58(%ebp), %esi\n" /* line 193 | execRef */
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFURLGetFSRef\n"
        "testb %al, %al\n"
        "jne .Lf8f96_00008ff7\n"
        ".Lf8f96_00008fe0:\n"
        "movl %ebx, (%esp)\n" /* line 203 | urlRef */
        "calll CFRelease\n"
        "movl sExecutableDirID, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x100, %esp\n" /* line 208 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: execRef */
        /* { scope 2: info */
        /* { scope 3 */
        ".Lf8f96_00008ff7:\n"
        "movl $0, 0x14(%esp)\n" /* line 196 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0xe8(%ebp), %eax\n" /* info */
        "movl %eax, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FSGetCatalogInfo\n"
        "testw %ax, %ax\n" /* line 197 */
        "jne .Lf8f96_00008fe0\n"
        "movl -0xe4(%ebp), %eax\n" /* line 199 */
        "movl %eax, sExecutableDirID\n"
        "jmp .Lf8f96_00008fe0\n"
    );
}
#else
SInt32 MacFolders_GetExecutableFolderID(void)
{
    return 0;
}
#endif

#ifndef __EMSCRIPTEN__
/* line 132 */
__attribute__((naked))
OSStatus MacFolders_GetApplicationFolderItemPath(const char *inItem, char *outPath, int inMaxPath)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 132 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        "movl 8(%ebp), %esi\n" /* inItem */
        "movl 0xc(%ebp), %ebx\n" /* outPath */
        /* { scope 1: ref */
        /* { scope 2 */
        "leal -0x20(%ebp), %edi\n" /* line 95 */
        "movl %edi, (%esp)\n"
        "calll GetCurrentProcess\n"
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 96 */
        "je .Lf903e_000090b2\n"
        /* } scope */
        ".Lf903e_00009063:\n"
        "testl %edx, %edx\n" /* line 135 */
        "jne .Lf903e_000090a5\n"
        "movzbl (%esi), %eax\n" /* line 137 | inItem */
        "cmpb $0x2f, %al\n"
        "je .Lf903e_00009087\n"
        "cmpb $0x5c, %al\n"
        "je .Lf903e_00009087\n"
        "cld\n" /* line 139 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* outPath */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movw $0x2f, -1(%ecx, %ebx)\n"
        ".Lf903e_00009087:\n"
        "movl %esi, 4(%esp)\n" /* line 141 | inItem */
        "movl %ebx, (%esp)\n" /* outPath */
        "calll strcat\n"
        "movl $0, 4(%esp)\n" /* line 142 */
        "movl %ebx, (%esp)\n" /* outPath */
        "calll MacFiles_CleanPath\n"
        "xorl %edx, %edx\n"
        /* } scope */
        ".Lf903e_000090a5:\n"
        "movl %edx, %eax\n" /* line 146 */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ref */
        /* { scope 2 */
        ".Lf903e_000090b2:\n"
        "leal -0xc0(%ebp), %eax\n" /* line 99 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetProcessBundleLocation\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 100 */
        "jne .Lf903e_000090a5\n"
        "leal -0x70(%ebp), %edi\n" /* line 102 | ref */
        "movl %edi, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0xc0(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FSGetCatalogInfo\n"
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 118 */
        "jne .Lf903e_000090a5\n"
        "movl 0x10(%ebp), %eax\n" /* line 120 | inMaxPath */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FSRefMakePath\n"
        "movl %eax, %edx\n"
        "jmp .Lf903e_00009063\n"
    );
}
#else
OSStatus MacFolders_GetApplicationFolderItemPath(const char *inItem, char *outPath, int inMaxPath)
{
    return 0;
}
#endif

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

#ifndef __EMSCRIPTEN__
/* line 215 */
__attribute__((naked))
SInt32 MacFolders_GetDataFolderID(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 215 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x27c, %esp\n"
        "movl sDataFolderDirID, %eax\n" /* line 217 */
        "testl %eax, %eax\n"
        "je .Lf916e_00009193\n"
        ".Lf916e_00009183:\n"
        "movl sDataFolderDirID, %eax\n"
        ".Lf916e_00009188:\n"
        "addl $0x27c, %esp\n" /* line 281 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf916e_00009193:\n"
        "leal -0x262(%ebp), %edi\n" /* line 223 | dataFolderName */
        "movl %edi, 4(%esp)\n"
        "movl $0x32e6a4, (%esp)\n"
        "calll MacResources_GetGameString\n"
        "movl $0, -0xc0(%ebp)\n" /* line 228 */
        "movw $0xffff, -0xb6(%ebp)\n" /* line 229 */
        "movl sAppFolderDirID, %eax\n" /* line 32 */
        "testl %eax, %eax\n"
        "je .Lf916e_000093b9\n"
        ".Lf916e_000091c9:\n"
        "movzwl sAppFolderVRefNum, %eax\n" /* line 230 */
        "movw %ax, -0xbc(%ebp)\n"
        "calll MacFolders_GetExecutableFolderID\n" /* line 231 */
        "movl %eax, -0xa2(%ebp)\n"
        "leal -0xd2(%ebp), %eax\n" /* line 232 | pb, error */
        "movl %eax, (%esp)\n" /* error */
        "calll PBGetCatInfoSync\n"
        "testw %ax, %ax\n" /* line 233 */
        "jne .Lf916e_0000922d\n"
        "movl -0x6e(%ebp), %ebx\n" /* line 236 */
        "movl sAppFolderDirID, %esi\n" /* line 32 */
        "testl %esi, %esi\n"
        "je .Lf916e_00009332\n"
        ".Lf916e_00009206:\n"
        "leal -0x66(%ebp), %eax\n" /* line 236 | spec */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movswl sAppFolderVRefNum, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FSMakeFSSpec\n"
        "testw %ax, %ax\n" /* line 237 */
        "je .Lf916e_000092d8\n"
        ".Lf916e_0000922d:\n"
        "movl sDataFolderDirID, %ebx\n" /* line 257 */
        "testl %ebx, %ebx\n"
        "jne .Lf916e_00009183\n"
        "movl sAppFolderDirID, %ecx\n" /* line 32 */
        "testl %ecx, %ecx\n"
        "je .Lf916e_000094c7\n"
        ".Lf916e_00009249:\n"
        "movl sAppFolderDirID, %ebx\n"
        ".Lf916e_0000924f:\n"
        "testl %ebx, %ebx\n"
        "je .Lf916e_00009440\n"
        ".Lf916e_00009257:\n"
        "leal -0x66(%ebp), %eax\n" /* line 260 | spec */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movswl sAppFolderVRefNum, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FSMakeFSSpec\n"
        "testw %ax, %ax\n" /* line 261 */
        "jne .Lf916e_00009183\n"
        "leal -0x60(%ebp), %eax\n" /* line 264 */
        "movl %eax, -0xc0(%ebp)\n"
        "movw $0, -0xb6(%ebp)\n" /* line 265 */
        "movzwl -0x66(%ebp), %eax\n" /* line 266 | spec */
        "movw %ax, -0xbc(%ebp)\n"
        "movl -0x64(%ebp), %eax\n" /* line 267 */
        "movl %eax, -0xa2(%ebp)\n"
        "leal -0xd2(%ebp), %eax\n" /* line 268 | pb */
        "movl %eax, (%esp)\n"
        "calll PBGetCatInfoSync\n"
        "testw %ax, %ax\n" /* line 269 */
        "jne .Lf916e_00009183\n"
        "testb $0x10, -0xb4(%ebp)\n" /* line 271 */
        "je .Lf916e_00009183\n"
        "movl -0xa2(%ebp), %eax\n" /* line 273 */
        "movl %eax, sDataFolderDirID\n"
        "jmp .Lf916e_00009188\n"
        ".Lf916e_000092d8:\n"
        "leal -0x60(%ebp), %eax\n" /* line 240 */
        "movl %eax, -0xc0(%ebp)\n"
        "movw $0, -0xb6(%ebp)\n" /* line 241 */
        "movzwl -0x66(%ebp), %eax\n" /* line 242 | spec */
        "movw %ax, -0xbc(%ebp)\n"
        "movl -0x64(%ebp), %eax\n" /* line 243 */
        "movl %eax, -0xa2(%ebp)\n"
        "leal -0xd2(%ebp), %eax\n" /* line 244 | pb */
        "movl %eax, (%esp)\n"
        "calll PBGetCatInfoSync\n"
        "testw %ax, %ax\n" /* line 245 */
        "jne .Lf916e_0000922d\n"
        "testb $0x10, -0xb4(%ebp)\n" /* line 247 */
        "je .Lf916e_0000922d\n"
        "movl -0xa2(%ebp), %eax\n" /* line 249 */
        "movl %eax, sDataFolderDirID\n"
        "jmp .Lf916e_0000922d\n"
        ".Lf916e_00009332:\n"
        "leal -0x20(%ebp), %esi\n" /* line 35 */
        "movl %esi, (%esp)\n"
        "calll GetCurrentProcess\n"
        "testw %ax, %ax\n" /* line 36 */
        "jne .Lf916e_00009206\n"
        "movl $sAppBundleRef, 4(%esp)\n" /* line 38 */
        "movl %esi, (%esp)\n"
        "calll GetProcessBundleLocation\n"
        "testl %eax, %eax\n" /* line 39 */
        "jne .Lf916e_00009206\n"
        "movl $0, 0x14(%esp)\n" /* line 42 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x162(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl $sAppBundleRef, (%esp)\n"
        "calll FSGetCatalogInfo\n"
        "testw %ax, %ax\n" /* line 43 */
        "jne .Lf916e_00009206\n"
        "movl -0x160(%ebp), %eax\n" /* line 45 */
        "movw %ax, sAppFolderVRefNum\n"
        "movl -0x15e(%ebp), %eax\n" /* line 46 */
        "movl %eax, sAppFolderDirID\n"
        "jmp .Lf916e_00009206\n"
        ".Lf916e_000093b9:\n"
        "leal -0x20(%ebp), %ebx\n" /* line 35 */
        "movl %ebx, (%esp)\n"
        "calll GetCurrentProcess\n"
        "testw %ax, %ax\n" /* line 36 */
        "jne .Lf916e_000091c9\n"
        "movl $sAppBundleRef, 4(%esp)\n" /* line 38 */
        "movl %ebx, (%esp)\n"
        "calll GetProcessBundleLocation\n"
        "testl %eax, %eax\n" /* line 39 */
        "jne .Lf916e_000091c9\n"
        "movl $0, 0x14(%esp)\n" /* line 42 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x162(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl $sAppBundleRef, (%esp)\n"
        "calll FSGetCatalogInfo\n"
        "testw %ax, %ax\n" /* line 43 */
        "jne .Lf916e_000091c9\n"
        "movl -0x160(%ebp), %eax\n" /* line 45 */
        "movw %ax, sAppFolderVRefNum\n"
        "movl -0x15e(%ebp), %eax\n" /* line 46 */
        "movl %eax, sAppFolderDirID\n"
        "jmp .Lf916e_000091c9\n"
        ".Lf916e_00009440:\n"
        "leal -0x20(%ebp), %esi\n" /* line 35 */
        "movl %esi, (%esp)\n"
        "calll GetCurrentProcess\n"
        "testw %ax, %ax\n" /* line 36 */
        "jne .Lf916e_00009257\n"
        "movl $sAppBundleRef, 4(%esp)\n" /* line 38 */
        "movl %esi, (%esp)\n"
        "calll GetProcessBundleLocation\n"
        "testl %eax, %eax\n" /* line 39 */
        "jne .Lf916e_00009257\n"
        "movl $0, 0x14(%esp)\n" /* line 42 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x162(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl $sAppBundleRef, (%esp)\n"
        "calll FSGetCatalogInfo\n"
        "testw %ax, %ax\n" /* line 43 */
        "jne .Lf916e_00009257\n"
        "movl -0x160(%ebp), %eax\n" /* line 45 */
        "movw %ax, sAppFolderVRefNum\n"
        "movl -0x15e(%ebp), %eax\n" /* line 46 */
        "movl %eax, sAppFolderDirID\n"
        "jmp .Lf916e_00009257\n"
        ".Lf916e_000094c7:\n"
        "leal -0x20(%ebp), %ebx\n" /* line 35 */
        "movl %ebx, (%esp)\n"
        "calll GetCurrentProcess\n"
        "testw %ax, %ax\n" /* line 36 */
        "jne .Lf916e_00009249\n"
        "movl $sAppBundleRef, 4(%esp)\n" /* line 38 */
        "movl %ebx, (%esp)\n"
        "calll GetProcessBundleLocation\n"
        "testl %eax, %eax\n" /* line 39 */
        "jne .Lf916e_00009249\n"
        "movl $0, 0x14(%esp)\n" /* line 42 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x162(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl $sAppBundleRef, (%esp)\n"
        "calll FSGetCatalogInfo\n"
        "testw %ax, %ax\n" /* line 43 */
        "jne .Lf916e_00009249\n"
        "movl -0x160(%ebp), %eax\n" /* line 45 */
        "movw %ax, sAppFolderVRefNum\n"
        "movl -0x15e(%ebp), %eax\n" /* line 46 */
        "movl %eax, sAppFolderDirID\n"
        "movl %eax, %ebx\n"
        "jmp .Lf916e_0000924f\n"
    );
}
#else
SInt32 MacFolders_GetDataFolderID(void)
{
    return 0;
}
#endif

#ifndef __EMSCRIPTEN__
/* line 288 */
__attribute__((naked))
OSStatus MacFolders_GetDataFolderPath(char *outPath, int inMaxPath)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 288 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x154, %esp\n"
        /* { scope 1 */
        "movl sAppFolderDirID, %eax\n" /* line 32 */
        "testl %eax, %eax\n"
        "je .Lf9552_000095bc\n"
        ".Lf9552_00009565:\n"
        "movzwl sAppFolderVRefNum, %eax\n" /* line 291 */
        "movw %ax, -0x56(%ebp)\n" /* spec */
        "calll MacFolders_GetDataFolderID\n" /* line 292 */
        "movl %eax, -0x54(%ebp)\n"
        "movb $0, -0x50(%ebp)\n" /* line 293 */
        "leal -0xa6(%ebp), %ebx\n" /* line 296 | ref */
        "movl %ebx, 4(%esp)\n"
        "leal -0x56(%ebp), %eax\n" /* spec */
        "movl %eax, (%esp)\n"
        "calll FSpMakeFSRef\n"
        "movswl %ax, %edx\n" /* error */
        "testw %ax, %ax\n" /* line 297 */
        "jne .Lf9552_000095b1\n"
        "movl 0xc(%ebp), %eax\n" /* line 299 | inMaxPath */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* outPath */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FSRefMakePath\n"
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf9552_000095b1:\n"
        "movl %edx, %eax\n" /* line 303 */
        "addl $0x154, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9552_000095bc:\n"
        "leal -0x10(%ebp), %ebx\n" /* line 35 */
        "movl %ebx, (%esp)\n"
        "calll GetCurrentProcess\n"
        "testw %ax, %ax\n" /* line 36 */
        "jne .Lf9552_00009565\n"
        "movl $sAppBundleRef, 4(%esp)\n" /* line 38 */
        "movl %ebx, (%esp)\n"
        "calll GetProcessBundleLocation\n"
        "testl %eax, %eax\n" /* line 39 */
        "jne .Lf9552_00009565\n"
        "movl $0, 0x14(%esp)\n" /* line 42 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x136(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl $sAppBundleRef, (%esp)\n"
        "calll FSGetCatalogInfo\n"
        "testw %ax, %ax\n" /* line 43 */
        "jne .Lf9552_00009565\n"
        "movl -0x134(%ebp), %eax\n" /* line 45 */
        "movw %ax, sAppFolderVRefNum\n"
        "movl -0x132(%ebp), %eax\n" /* line 46 */
        "movl %eax, sAppFolderDirID\n"
        "jmp .Lf9552_00009565\n"
    );
}
#else
OSStatus MacFolders_GetDataFolderPath(char *outPath, int inMaxPath)
{
    return 0;
}
#endif

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
