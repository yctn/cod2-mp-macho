/* ASM dump from: bg_weapons_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_weapons_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

static WeaponDef bg_defaultWeaponDefs; /* 0x7ef500 */
static int g_playerAnimTypeNamesCount; /* 0x7efc20 */
static char * g_playerAnimTypeNames[64]; /* 0x7efb20 */
static char * szWeapTypeNames[4]; /* 0x310c88 */
static char * szWeapSlotNames[3]; /* 0x310c2c */
static char * szProjectileExplosionNames[3]; /* 0x310c14 */
static char * szWeapOverlayReticleNames[5]; /* 0x310c38 */
static char * szWeapClassNames[10]; /* 0x310c60 */
static char * szWeapStanceNames[3]; /* 0x310c20 */
static char * offhandClassNames[3]; /* 0x310c08 */
static cspField_t weaponDefFields[366]; /* 0x30fae0 */

int BG_GetWeaponSlotForName(const char *pszSlotName);
const char * BG_GetWeaponSlotNameForIndex(int iSlot);
long int BG_LoadWeaponStrings(void);
long int BG_LoadPlayerAnimTypes(void);
long int SetConfigString(char * *ppszConfigString, const char *pszKeyValue);
WeaponDef * BG_LoadDefaultWeaponDef(void);
static qboolean BG_ParseWeaponDefSpecificFieldType(byte *pStruct, const char *pValue, const int iFieldType);
static long int SetConfigString2(byte *pMember, const char *pszKeyValue);
WeaponDef * BG_LoadWeaponDefInternal(const char *folder, const char *name);

/* line 613 */
__attribute__((naked))
int BG_GetWeaponSlotForName(const char *pszSlotName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 613 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* pszSlotName */
        "xorl %esi, %esi\n"
        "movl $szWeapSlotNames, %ebx\n"
        /* { scope 1 */
        ".Lfbd218_000bd22b:\n"
        "movl (%ebx), %eax\n" /* line 619 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pszSlotName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbd218_000bd24b\n"
        "addl $1, %esi\n" /* line 617 | i */
        "addl $4, %ebx\n"
        "cmpl $3, %esi\n" /* i */
        "jne .Lfbd218_000bd22b\n"
        "xorw %si, %si\n" /* i */
        /* } scope */
        ".Lfbd218_000bd24b:\n"
        "movl %esi, %eax\n" /* line 625 | i */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 635 */
__attribute__((naked))
const char * BG_GetWeaponSlotNameForIndex(int iSlot)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 635 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* iSlot */
        "movl szWeapSlotNames(, %eax, 4), %eax\n" /* iSlot */
        "popl %ebp\n" /* line 640 */
        "retl\n"
    );
}

/* line 650 */
__attribute__((naked))
long int BG_LoadWeaponStrings(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 650 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl g_playerAnimTypeNamesCount, %eax\n" /* line 654 */
        "testl %eax, %eax\n"
        "jg .Lfbd266_000bd27e\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 656 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbd266_000bd27e:\n"
        "xorl %ebx, %ebx\n" /* line 654 | i */
        "movl $g_playerAnimTypeNames, %esi\n"
        ".Lfbd266_000bd285:\n"
        "movl (%esi), %eax\n" /* line 655 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll BG_InitWeaponString\n"
        "addl $1, %ebx\n" /* line 654 | i */
        "addl $4, %esi\n"
        "cmpl %ebx, g_playerAnimTypeNamesCount\n" /* i */
        "jg .Lfbd266_000bd285\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 656 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 668 */
__attribute__((naked))
long int BG_LoadPlayerAnimTypes(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 668 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x102c, %esp\n"
        /* { scope 1 */
        "movl $0, g_playerAnimTypeNamesCount\n" /* line 686 */
        "movl $0, 8(%esp)\n" /* line 690 */
        "leal -0x20(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl $0x221c28, (%esp)\n" /* "mp/playeranimtypes.txt" */
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %esi\n" /* iLen */
        "testl %eax, %eax\n" /* line 691 */
        "js .Lfbd2a8_000bd3df\n"
        ".Lfbd2a8_000bd2e3:\n"
        "cmpl $0xfff, %esi\n" /* line 694 | iLen */
        "ja .Lfbd2a8_000bd3b3\n"
        ".Lfbd2a8_000bd2ef:\n"
        "movl -0x20(%ebp), %eax\n" /* line 700 | f */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* iLen */
        "leal -0x1020(%ebp), %ebx\n" /* buf */
        "movl %ebx, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x1020(%ebp, %esi)\n" /* line 701 */
        "movl -0x20(%ebp), %eax\n" /* line 702 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 715 | text_p */
        "movl $0x221c74, (%esp)\n" /* line 716 */
        "calll Com_BeginParseSession\n"
        "jmp .Lfbd2a8_000bd36e\n"
        ".Lfbd2a8_000bd32c:\n"
        "movl g_playerAnimTypeNamesCount, %ebx\n" /* line 728 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* iLen */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocLowInternal\n"
        "movl %eax, g_playerAnimTypeNames(, %ebx, 4)\n"
        "movl %esi, 4(%esp)\n" /* line 729 | iLen */
        "movl g_playerAnimTypeNamesCount, %eax\n"
        "movl g_playerAnimTypeNames(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "addl $1, g_playerAnimTypeNamesCount\n" /* line 730 */
        ".Lfbd2a8_000bd36e:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 721 | text_p */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* iLen */
        "testl %eax, %eax\n" /* line 722 */
        "je .Lfbd2a8_000bd3a3\n"
        "cmpb $0, (%eax)\n"
        "je .Lfbd2a8_000bd3a3\n"
        "cmpl $0x3f, g_playerAnimTypeNamesCount\n" /* line 725 */
        "jbe .Lfbd2a8_000bd32c\n"
        "movl $0x221c8c, 4(%esp)\n" /* line 726 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbd2a8_000bd32c\n"
        ".Lfbd2a8_000bd3a3:\n"
        "calll Com_EndParseSession\n" /* line 733 */
        /* } scope */
        "addl $0x102c, %esp\n" /* line 734 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbd2a8_000bd3b3:\n"
        "movl -0x20(%ebp), %eax\n" /* line 696 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl $0x221c28, 8(%esp)\n" /* line 697 */
        "movl $0x221c5c, 4(%esp)\n" /* "'%s' max size exceeded" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbd2a8_000bd2ef\n"
        ".Lfbd2a8_000bd3df:\n"
        "movl $0x221c28, 8(%esp)\n" /* line 692 */
        "movl $0x221c40, 4(%esp)\n" /* "Couldn't load file '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbd2a8_000bd2e3\n"
    );
}

/* line 916 */
__attribute__((naked))
long int SetConfigString(char * *ppszConfigString, const char *pszKeyValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 916 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* pszKeyValue */
        "cmpb $0, (%esi)\n" /* line 920 | pszKeyValue */
        "jne .Lfbd400_000bd422\n"
        "movl 8(%ebp), %eax\n" /* line 922 | ppszConfigString */
        "movl $0x2157b8, (%eax)\n"
        "addl $0x1c, %esp\n" /* line 930 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfbd400_000bd422:\n"
        "movl $1, 4(%esp)\n" /* line 926 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* pszKeyValue */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocLowAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl %esi, 4(%esp)\n" /* line 928 | pszKeyValue */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl 8(%ebp), %eax\n" /* line 929 | ppszConfigString */
        "movl %ebx, (%eax)\n"
        "addl $0x1c, %esp\n" /* line 930 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1051 */
__attribute__((naked))
WeaponDef * BG_LoadDefaultWeaponDef(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1051 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2157b8, bg_defaultWeaponDefs\n" /* line 949 */
        "movl $0x30fae8, %edx\n"
        "movl $0x310c10, %ecx\n"
        ".Lfbd45c_000bd476:\n"
        "movl (%edx), %eax\n" /* line 953 */
        "testl %eax, %eax\n"
        "jne .Lfbd45c_000bd489\n"
        "movl -4(%edx), %eax\n" /* line 956 */
        "movl $0x2157b8, bg_defaultWeaponDefs(%eax)\n"
        ".Lfbd45c_000bd489:\n"
        "addl $0xc, %edx\n"
        "cmpl %edx, %ecx\n" /* line 951 */
        "jne .Lfbd45c_000bd476\n"
        "movl $0x218298, bg_defaultWeaponDefs\n" /* line 1057 */
        "movl $0x221cb4, 0x7efa0c\n" /* line 1058 */
        "movl $0x221cb4, 0x7efa10\n" /* line 1059 */
        "movl $bg_defaultWeaponDefs, (%esp)\n" /* line 1061 */
        "calll G_ParseWeaponAccurayGraphs\n"
        "movl $bg_defaultWeaponDefs, %eax\n" /* line 1064 */
        "leave\n"
        "retl\n"
    );
}

/* line 778 */
static __attribute__((naked))
qboolean BG_ParseWeaponDefSpecificFieldType(byte *pStruct, const char *pValue, const int iFieldType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 778 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* pValue */
        "movl 0x10(%ebp), %edx\n" /* iFieldType */
        /* { scope 1: arraySize */
        "leal -8(%edx), %eax\n" /* line 788 */
        "cmpl $7, %eax\n"
        "ja .Lfbd4c2_000bd4e0\n"
        "jmpl *0x2f1dc0(, %eax, 4)\n"
        ".Lfbd4c2_000bd4e0:\n"
        "movl 8(%ebp), %ecx\n" /* line 855 | pStruct */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x221e04, 4(%esp)\n" /* "Bad field type %i in %s
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfbd4c2_000bd503:\n"
        "addl $0x2c, %esp\n" /* line 860 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: arraySize */
        "xorl %esi, %esi\n" /* line 788 | arrayIndex */
        "movl $szWeapTypeNames, %ebx\n"
        ".Lfbd4c2_000bd512:\n"
        "movl (%ebx), %eax\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbd4c2_000bd827\n"
        "addl $1, %esi\n" /* line 763 */
        "addl $4, %ebx\n"
        "cmpl $4, %esi\n"
        "jne .Lfbd4c2_000bd512\n"
        "movl $0xffffffff, %ebx\n"
        ".Lfbd4c2_000bd538:\n"
        "movl 8(%ebp), %edx\n" /* line 793 | pStruct */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* pValue */
        "movl $0x221cc4, 4(%esp)\n" /* "Unknown weapon type "%s" in "%s"
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd4c2_000bd559:\n"
        "movl 8(%ebp), %ecx\n" /* line 795 | pStruct */
        "movl %ebx, 0x78(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lfbd4c2_000bd503\n"
        "movl g_playerAnimTypeNamesCount, %eax\n" /* line 847 */
        "movl %eax, -0x1c(%ebp)\n" /* arraySize */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 763 */
        "jg .Lfbd4c2_000bd7eb\n"
        ".Lfbd4c2_000bd576:\n"
        "movl $0xffffffff, %esi\n"
        /* } scope */
        ".Lfbd4c2_000bd57b:\n"
        "movl 8(%ebp), %edx\n" /* line 849 | pStruct */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* pValue */
        "movl $0x221ddc, 4(%esp)\n" /* "Unknown playerAnimType "%s" in "%s"
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd4c2_000bd59c:\n"
        "movl 8(%ebp), %ecx\n" /* line 851 | pStruct */
        "movl %esi, 0x74(%ecx)\n" /* arrayIndex */
        "movl $1, %eax\n"
        "jmp .Lfbd4c2_000bd503\n"
        "xorl %esi, %esi\n" /* line 836 | arrayIndex */
        "movl $offhandClassNames, %ebx\n"
        ".Lfbd4c2_000bd5b3:\n"
        "movl (%ebx), %eax\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbd4c2_000bd83f\n"
        "addl $1, %esi\n" /* line 763 */
        "addl $4, %ebx\n"
        "cmpl $3, %esi\n"
        "jne .Lfbd4c2_000bd5b3\n"
        "movl $0xffffffff, %ebx\n"
        ".Lfbd4c2_000bd5d9:\n"
        "movl 8(%ebp), %edx\n" /* line 841 | pStruct */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* pValue */
        "movl $0x221db4, 4(%esp)\n" /* "Unknown offhand class "%s" in "%s"
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd4c2_000bd5fa:\n"
        "movl 8(%ebp), %ecx\n" /* line 843 | pStruct */
        "movl %ebx, 0x84(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lfbd4c2_000bd503\n"
        "xorl %esi, %esi\n" /* line 828 | arrayIndex */
        "movl $szProjectileExplosionNames, %ebx\n"
        ".Lfbd4c2_000bd614:\n"
        "movl (%ebx), %eax\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbd4c2_000bd855\n"
        "addl $1, %esi\n" /* line 763 */
        "addl $4, %ebx\n"
        "cmpl $3, %esi\n"
        "jne .Lfbd4c2_000bd614\n"
        "movl $0xffffffff, %ebx\n"
        ".Lfbd4c2_000bd63a:\n"
        "movl 8(%ebp), %edx\n" /* line 833 | pStruct */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* pValue */
        "movl $0x221d88, 4(%esp)\n" /* "Unknown projectile explosion "%s" in "%s"
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd4c2_000bd65b:\n"
        "movl 8(%ebp), %ecx\n" /* line 835 | pStruct */
        "movl %ebx, 0x390(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lfbd4c2_000bd503\n"
        "xorl %esi, %esi\n" /* line 820 | arrayIndex */
        "movl $szWeapStanceNames, %ebx\n"
        ".Lfbd4c2_000bd675:\n"
        "movl (%ebx), %eax\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbd4c2_000bd84a\n"
        "addl $1, %esi\n" /* line 763 */
        "addl $4, %ebx\n"
        "cmpl $3, %esi\n"
        "jne .Lfbd4c2_000bd675\n"
        "movl $0xffffffff, %ebx\n"
        ".Lfbd4c2_000bd69b:\n"
        "movl 8(%ebp), %edx\n" /* line 825 | pStruct */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* pValue */
        "movl $0x221d60, 4(%esp)\n" /* "Unknown weapon stance "%s" in "%s"
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd4c2_000bd6bc:\n"
        "movl 8(%ebp), %ecx\n" /* line 827 | pStruct */
        "movl %ebx, 0x8c(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lfbd4c2_000bd503\n"
        "xorl %esi, %esi\n" /* line 804 | arrayIndex */
        "movl $szWeapOverlayReticleNames, %ebx\n"
        ".Lfbd4c2_000bd6d6:\n"
        "movl (%ebx), %eax\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbd4c2_000bd81c\n"
        "addl $1, %esi\n" /* line 763 */
        "addl $4, %ebx\n"
        "cmpl $5, %esi\n"
        "jne .Lfbd4c2_000bd6d6\n"
        "movl $0xffffffff, %ebx\n"
        ".Lfbd4c2_000bd6fc:\n"
        "movl 8(%ebp), %edx\n" /* line 809 | pStruct */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* pValue */
        "movl $0x221d0c, 4(%esp)\n" /* "Unknown weapon overlay reticle "%s" in "%s"
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd4c2_000bd71d:\n"
        "movl 8(%ebp), %ecx\n" /* line 811 | pStruct */
        "movl %ebx, 0x278(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lfbd4c2_000bd503\n"
        "xorl %esi, %esi\n" /* line 812 | arrayIndex */
        "movl $szWeapSlotNames, %ebx\n"
        ".Lfbd4c2_000bd737:\n"
        "movl (%ebx), %eax\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbd4c2_000bd860\n"
        "addl $1, %esi\n" /* line 763 */
        "addl $4, %ebx\n"
        "cmpl $3, %esi\n"
        "jne .Lfbd4c2_000bd737\n"
        "movl $0xffffffff, %ebx\n"
        ".Lfbd4c2_000bd75d:\n"
        "movl 8(%ebp), %edx\n" /* line 817 | pStruct */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* pValue */
        "movl $0x221d3c, 4(%esp)\n" /* "Unknown weapon slot "%s" in "%s"
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd4c2_000bd77e:\n"
        "movl 8(%ebp), %ecx\n" /* line 819 | pStruct */
        "movl %ebx, 0x80(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lfbd4c2_000bd503\n"
        "xorl %esi, %esi\n" /* line 796 | arrayIndex */
        "movl $szWeapClassNames, %ebx\n"
        ".Lfbd4c2_000bd798:\n"
        "movl (%ebx), %eax\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbd4c2_000bd814\n"
        "addl $1, %esi\n" /* line 763 */
        "addl $4, %ebx\n"
        "cmpl $0xa, %esi\n"
        "jne .Lfbd4c2_000bd798\n"
        "movl $0xffffffff, %ebx\n"
        ".Lfbd4c2_000bd7ba:\n"
        "movl 8(%ebp), %edx\n" /* line 801 | pStruct */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* pValue */
        "movl $0x221ce8, 4(%esp)\n" /* "Unknown weapon class "%s" in "%s"
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd4c2_000bd7db:\n"
        "movl 8(%ebp), %ecx\n" /* line 803 | pStruct */
        "movl %ebx, 0x7c(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lfbd4c2_000bd503\n"
        /* { scope 2 */
        ".Lfbd4c2_000bd7eb:\n"
        "xorl %esi, %esi\n" /* line 763 */
        "movl $g_playerAnimTypeNames, %ebx\n"
        ".Lfbd4c2_000bd7f2:\n"
        "movl (%ebx), %eax\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbd4c2_000bd832\n"
        "addl $1, %esi\n" /* line 763 */
        "addl $4, %ebx\n"
        "cmpl %esi, -0x1c(%ebp)\n" /* arraySize */
        "jne .Lfbd4c2_000bd7f2\n"
        "jmp .Lfbd4c2_000bd576\n"
        /* } scope */
        ".Lfbd4c2_000bd814:\n"
        "testl %esi, %esi\n" /* line 800 | arrayIndex */
        "js .Lfbd4c2_000bd86b\n"
        "movl %esi, %ebx\n" /* arrayIndex */
        "jmp .Lfbd4c2_000bd7db\n"
        ".Lfbd4c2_000bd81c:\n"
        "testl %esi, %esi\n" /* line 808 | arrayIndex */
        "js .Lfbd4c2_000bd872\n"
        "movl %esi, %ebx\n" /* arrayIndex */
        "jmp .Lfbd4c2_000bd71d\n"
        ".Lfbd4c2_000bd827:\n"
        "testl %esi, %esi\n" /* line 792 | arrayIndex */
        "js .Lfbd4c2_000bd879\n"
        "movl %esi, %ebx\n" /* arrayIndex */
        "jmp .Lfbd4c2_000bd559\n"
        ".Lfbd4c2_000bd832:\n"
        "testl %esi, %esi\n" /* line 848 | arrayIndex */
        "jns .Lfbd4c2_000bd59c\n"
        "jmp .Lfbd4c2_000bd57b\n"
        ".Lfbd4c2_000bd83f:\n"
        "testl %esi, %esi\n" /* line 840 | arrayIndex */
        "js .Lfbd4c2_000bd88e\n"
        "movl %esi, %ebx\n" /* arrayIndex */
        "jmp .Lfbd4c2_000bd5fa\n"
        ".Lfbd4c2_000bd84a:\n"
        "testl %esi, %esi\n" /* line 824 | arrayIndex */
        "js .Lfbd4c2_000bd895\n"
        "movl %esi, %ebx\n" /* arrayIndex */
        "jmp .Lfbd4c2_000bd6bc\n"
        ".Lfbd4c2_000bd855:\n"
        "testl %esi, %esi\n" /* line 832 | arrayIndex */
        "js .Lfbd4c2_000bd887\n"
        "movl %esi, %ebx\n" /* arrayIndex */
        "jmp .Lfbd4c2_000bd65b\n"
        ".Lfbd4c2_000bd860:\n"
        "testl %esi, %esi\n" /* line 816 | arrayIndex */
        "js .Lfbd4c2_000bd880\n"
        "movl %esi, %ebx\n" /* arrayIndex */
        "jmp .Lfbd4c2_000bd77e\n"
        ".Lfbd4c2_000bd86b:\n"
        "movl %esi, %ebx\n" /* line 800 | arrayIndex */
        "jmp .Lfbd4c2_000bd7ba\n"
        ".Lfbd4c2_000bd872:\n"
        "movl %esi, %ebx\n" /* line 808 | arrayIndex */
        "jmp .Lfbd4c2_000bd6fc\n"
        ".Lfbd4c2_000bd879:\n"
        "movl %esi, %ebx\n" /* line 792 | arrayIndex */
        "jmp .Lfbd4c2_000bd538\n"
        ".Lfbd4c2_000bd880:\n"
        "movl %esi, %ebx\n" /* line 816 | arrayIndex */
        "jmp .Lfbd4c2_000bd75d\n"
        ".Lfbd4c2_000bd887:\n"
        "movl %esi, %ebx\n" /* line 832 | arrayIndex */
        "jmp .Lfbd4c2_000bd63a\n"
        ".Lfbd4c2_000bd88e:\n"
        "movl %esi, %ebx\n" /* line 840 | arrayIndex */
        "jmp .Lfbd4c2_000bd5d9\n"
        ".Lfbd4c2_000bd895:\n"
        "movl %esi, %ebx\n" /* line 824 | arrayIndex */
        "jmp .Lfbd4c2_000bd69b\n"
    );
}

/* line 933 */
static __attribute__((naked))
long int SetConfigString2(byte *pMember, const char *pszKeyValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 933 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* pszKeyValue */
        "cmpb $0, (%esi)\n" /* line 920 */
        "jne .Lfbd89c_000bd8be\n"
        "movl 8(%ebp), %eax\n" /* line 922 | pMember */
        "movl $0x2157b8, (%eax)\n"
        "addl $0x1c, %esp\n" /* line 936 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfbd89c_000bd8be:\n"
        "movl $1, 4(%esp)\n" /* line 926 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocLowAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl %esi, 4(%esp)\n" /* line 928 */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl 8(%ebp), %eax\n" /* line 929 | pMember */
        "movl %ebx, (%eax)\n"
        "addl $0x1c, %esp\n" /* line 936 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 968 */
__attribute__((naked))
WeaponDef * BG_LoadWeaponDefInternal(const char *folder, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 968 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x209c, %esp\n"
        /* { scope 1 */
        "movl $0x604, (%esp)\n" /* line 978 */
        "calll Hunk_AllocLowInternal\n"
        "movl %eax, -0x207c(%ebp)\n" /* weapDef */
        "movl $0x2157b8, (%eax)\n" /* line 949 */
        "movl $0x30fae8, %edx\n"
        "movl $0x310c10, %ecx\n"
        ".Lfbd8f8_000bd926:\n"
        "movl (%edx), %eax\n" /* line 953 */
        "testl %eax, %eax\n"
        "jne .Lfbd8f8_000bd93c\n"
        "movl -4(%edx), %eax\n" /* line 956 */
        "movl -0x207c(%ebp), %ebx\n" /* weapDef */
        "movl $0x2157b8, (%eax, %ebx)\n"
        ".Lfbd8f8_000bd93c:\n"
        "addl $0xc, %edx\n"
        "cmpl %edx, %ecx\n" /* line 951 */
        "jne .Lfbd8f8_000bd926\n"
        "movl 0xc(%ebp), %edi\n" /* line 981 | name */
        "movl %edi, 0x10(%esp)\n"
        "movl 8(%ebp), %eax\n" /* folder */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x221e20, 8(%esp)\n" /* "weapons/%s/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x5c(%ebp), %eax\n" /* szFileName */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $0, 8(%esp)\n" /* line 983 */
        "leal -0x1c(%ebp), %eax\n" /* hFile */
        "movl %eax, 4(%esp)\n"
        "leal -0x5c(%ebp), %edx\n" /* szFileName */
        "movl %edx, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, -0x206c(%ebp)\n" /* iFileLength */
        "testl %eax, %eax\n" /* line 984 */
        "js .Lfbd8f8_000bdc48\n"
        "movl -0x1c(%ebp), %eax\n" /* line 991 | hFile */
        "movl %eax, 8(%esp)\n"
        "movl $0xa, 4(%esp)\n"
        "leal -0x205c(%ebp), %edi\n" /* szBuffer */
        "movl %edi, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x2052(%ebp)\n" /* line 992 */
        "movl $0x221e5c, %ebx\n" /* line 993 */
        "movl $0xa, %ecx\n"
        "cld\n"
        "movl %edi, %esi\n"
        "movl %ebx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lfbd8f8_000bd9da\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfbd8f8_000bd9da:\n"
        "testl %eax, %eax\n"
        "jne .Lfbd8f8_000bdc6a\n"
        "movl -0x206c(%ebp), %ebx\n" /* line 1001 | iFileLength */
        "subl $0xa, %ebx\n"
        "cmpl $0x1fff, %ebx\n"
        "jg .Lfbd8f8_000bdb2d\n"
        "movl $0x2000, 8(%esp)\n" /* line 1009 */
        "movl $0, 4(%esp)\n"
        "leal -0x205c(%ebp), %edi\n" /* szBuffer */
        "movl %edi, (%esp)\n"
        "calll memset\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1010 | hFile */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x205c(%ebp, %ebx)\n" /* line 1011 */
        "movl -0x1c(%ebp), %eax\n" /* line 1012 | hFile */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %edi, (%esp)\n" /* line 1014 */
        "calll Info_Validate\n"
        "testl %eax, %eax\n"
        "je .Lfbd8f8_000bdaff\n"
        "movl 0xc(%ebp), %edi\n" /* line 920 | name */
        "cmpb $0, (%edi)\n"
        "jne .Lfbd8f8_000bdac2\n"
        "movl -0x207c(%ebp), %eax\n" /* line 922 | weapDef */
        "movl $0x2157b8, (%eax)\n"
        ".Lfbd8f8_000bda5f:\n"
        "movl $SetConfigString2, 0x18(%esp)\n" /* line 1024 */
        "movl $BG_ParseWeaponDefSpecificFieldType, 0x14(%esp)\n"
        "movl $0x10, 0x10(%esp)\n"
        "leal -0x205c(%ebp), %ebx\n" /* szBuffer */
        "movl %ebx, 0xc(%esp)\n"
        "movl $0x16e, 8(%esp)\n"
        "movl $weaponDefFields, 4(%esp)\n"
        "movl -0x207c(%ebp), %edi\n" /* weapDef */
        "movl %edi, (%esp)\n"
        "calll ParseConfigStringToStruct\n"
        "testl %eax, %eax\n"
        "jne .Lfbd8f8_000bdb66\n"
        ".Lfbd8f8_000bdaa7:\n"
        "movl $0, -0x207c(%ebp)\n" /* line 1042 | weapDef */
        /* } scope */
        ".Lfbd8f8_000bdab1:\n"
        "movl -0x207c(%ebp), %eax\n" /* line 1043 | weapDef */
        "addl $0x209c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbd8f8_000bdac2:\n"
        "movl $1, 4(%esp)\n" /* line 926 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* name */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocLowAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl 0xc(%ebp), %eax\n" /* line 928 | name */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "movl -0x207c(%ebp), %edx\n" /* line 929 | weapDef */
        "movl %ebx, (%edx)\n"
        "jmp .Lfbd8f8_000bda5f\n"
        ".Lfbd8f8_000bdaff:\n"
        "leal -0x5c(%ebp), %ebx\n" /* line 1016 | szFileName */
        "movl %ebx, 4(%esp)\n"
        "movl $0x221ed8, (%esp)\n" /* "^3WARNING: "%s" is not a valid weapon file
" */
        "calll Com_Printf\n"
        "movl $0, -0x207c(%ebp)\n" /* weapDef */
        /* } scope */
        "movl -0x207c(%ebp), %eax\n" /* line 1043 | weapDef */
        "addl $0x209c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbd8f8_000bdb2d:\n"
        "leal -0x5c(%ebp), %edx\n" /* line 1003 | szFileName */
        "movl %edx, 4(%esp)\n"
        "movl $0x221ea0, (%esp)\n" /* "^3WARNING: "%s" Is too long of a weapon file to parse
" */
        ".Lfbd8f8_000bdb3b:\n"
        "calll Com_Printf\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1004 | hFile */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl $0, -0x207c(%ebp)\n" /* weapDef */
        /* } scope */
        "movl -0x207c(%ebp), %eax\n" /* line 1043 | weapDef */
        "addl $0x209c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbd8f8_000bdb66:\n"
        "movl 0x2c0(%edi), %eax\n" /* line 873 */
        "testl %eax, %eax\n"
        "jle .Lfbd8f8_000bdc7d\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 874 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x588(%edi)\n"
        ".Lfbd8f8_000bdb8c:\n"
        "movl -0x207c(%ebp), %edx\n" /* line 878 | weapDef */
        "movl 0x2c4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfbd8f8_000bddb0\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 879 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x58c(%edx)\n"
        ".Lfbd8f8_000bdbb8:\n"
        "pxor %xmm0, %xmm0\n" /* line 889 */
        "movl -0x207c(%ebp), %edi\n" /* weapDef */
        "ucomiss 0x598(%edi), %xmm0\n"
        "jae .Lfbd8f8_000bdda1\n"
        ".Lfbd8f8_000bdbcf:\n"
        "pxor %xmm0, %xmm0\n" /* line 892 */
        "movl -0x207c(%ebp), %eax\n" /* weapDef */
        "ucomiss 0x59c(%eax), %xmm0\n"
        "jae .Lfbd8f8_000bdd92\n"
        ".Lfbd8f8_000bdbe6:\n"
        "movl -0x207c(%ebp), %eax\n" /* line 1030 | weapDef */
        "movss 0x260(%eax), %xmm0\n"
        "ucomiss 0x2ed848, %xmm0\n" /* 15000.0f */
        "ja .Lfbd8f8_000bdc92\n"
        ".Lfbd8f8_000bdc01:\n"
        "movl -0x207c(%ebp), %edx\n" /* line 1033 | weapDef */
        "cmpl $2, 0x78(%edx)\n"
        "je .Lfbd8f8_000bdcbb\n"
        ".Lfbd8f8_000bdc11:\n"
        "movl -0x207c(%ebp), %ebx\n" /* line 1036 | weapDef */
        "movl %ebx, (%esp)\n"
        "calll G_ParseWeaponAccurayGraphs\n"
        "testb %al, %al\n"
        "je .Lfbd8f8_000bdaa7\n"
        "movl 0x1c4(%ebx), %eax\n" /* line 1039 */
        "movl %eax, (%esp)\n"
        "calll I_strlwr\n"
        "movl 0x1cc(%ebx), %eax\n" /* line 1040 */
        "movl %eax, (%esp)\n"
        "calll I_strlwr\n"
        "jmp .Lfbd8f8_000bdab1\n"
        ".Lfbd8f8_000bdc48:\n"
        "leal -0x5c(%ebp), %ebx\n" /* line 986 | szFileName */
        "movl %ebx, 4(%esp)\n"
        "movl $0x221e30, (%esp)\n" /* "^3WARNING: Could not load weapon file '%s'
" */
        "calll Com_Printf\n"
        "movl $0, -0x207c(%ebp)\n" /* weapDef */
        "jmp .Lfbd8f8_000bdab1\n"
        ".Lfbd8f8_000bdc6a:\n"
        "leal -0x5c(%ebp), %eax\n" /* line 995 | szFileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x221e68, (%esp)\n" /* "^3WARNING: "%s" does not appear to be a weapon file
" */
        "jmp .Lfbd8f8_000bdb3b\n"
        ".Lfbd8f8_000bdc7d:\n"
        "movl -0x207c(%ebp), %eax\n" /* line 876 | weapDef */
        "movl $0x3b5a740e, 0x588(%eax)\n"
        "jmp .Lfbd8f8_000bdb8c\n"
        ".Lfbd8f8_000bdc92:\n"
        "movl $0, 8(%esp)\n" /* line 1031 */
        "movl $0x40cd4c00, 0xc(%esp)\n"
        "movl $0x221f04, 4(%esp)\n" /* "Enemy crosshair ranges should be less than %f " */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbd8f8_000bdc01\n"
        ".Lfbd8f8_000bdcbb:\n"
        "cvtsi2ssl 0x384(%edx), %xmm0\n" /* line 900 */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lfbd8f8_000bdce7\n"
        "movl 4(%edx), %eax\n" /* line 901 */
        "movl %eax, 8(%esp)\n"
        "movl $0x221f34, 4(%esp)\n" /* "Projectile speed for WeapType %s must be greater than 0.0" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd8f8_000bdce7:\n"
        "movl -0x207c(%ebp), %eax\n" /* line 902 | weapDef */
        "movss 0x5a8(%eax), %xmm0\n"
        "ucomiss 0x2ed6ec, %xmm0\n" /* 45.0f */
        "jae .Lfbd8f8_000bdd6c\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lfbd8f8_000bdd6c\n"
        ".Lfbd8f8_000bdd07:\n"
        "pxor %xmm0, %xmm0\n" /* line 904 */
        "movl -0x207c(%ebp), %ebx\n" /* weapDef */
        "ucomiss 0x5a0(%ebx), %xmm0\n"
        "jb .Lfbd8f8_000bdd35\n"
        "movl 4(%ebx), %eax\n" /* line 905 */
        "movl %eax, 8(%esp)\n"
        "movl $0x221fbc, 4(%esp)\n" /* "Destabilization base time for for WeapType %s must be positi" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfbd8f8_000bdd35:\n"
        "pxor %xmm0, %xmm0\n" /* line 906 */
        "movl -0x207c(%ebp), %eax\n" /* weapDef */
        "ucomiss 0x5a4(%eax), %xmm0\n"
        "jb .Lfbd8f8_000bdc11\n"
        "movl 4(%eax), %eax\n" /* line 907 */
        "movl %eax, 8(%esp)\n"
        "movl $0x221ffc, 4(%esp)\n" /* "Destabilization reduction ratio for for WeapType %s must be " */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbd8f8_000bdc11\n"
        ".Lfbd8f8_000bdd6c:\n"
        "movl -0x207c(%ebp), %edx\n" /* line 903 | weapDef */
        "movl 4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x221f70, 4(%esp)\n" /* "Destabilization angle for for WeapType %s must be between 0 " */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbd8f8_000bdd07\n"
        ".Lfbd8f8_000bdd92:\n"
        "movl $0x497423f2, 0x59c(%eax)\n" /* line 893 */
        "jmp .Lfbd8f8_000bdbe6\n"
        ".Lfbd8f8_000bdda1:\n"
        "movl $0x497423f0, 0x598(%edi)\n" /* line 890 */
        "jmp .Lfbd8f8_000bdbcf\n"
        ".Lfbd8f8_000bddb0:\n"
        "movl -0x207c(%ebp), %ebx\n" /* line 881 | weapDef */
        "movl $0x3b03126f, 0x58c(%ebx)\n"
        "jmp .Lfbd8f8_000bdbb8\n"
    );
}

