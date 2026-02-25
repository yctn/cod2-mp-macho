/* ASM dump from: stringed_hooks.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/stringed/stringed_hooks.cpp */

#include "common_types.h"
#include "imports.h"

extern const dvar_t *loc_language; /* 0x0 */
extern const dvar_t *loc_forceEnglish; /* 0x0 */
extern const dvar_t *loc_translate; /* 0x0 */
extern const dvar_t *loc_warnings; /* 0x0 */
extern const dvar_t *loc_warningsAsErrors; /* 0x0 */
static char szErrorString[1024]; /* 0x33c1a0 */
static int iCurrString; /* 0x33cda0 */
static char szStrings[2][1024]; /* 0x33c5a0 */
static languageInfo_t g_languages[14]; /* 0x308bc0 */
static qboolean g_currentAsian; /* 0x33c180 */

int SEH_GetCurrentLanguage(void);
int SEH_VerifyLanguageSelection(int iLanguageSelection);
int SEH_Init_StringEd(void);
int SEH_Shutdown_StringEd(void);
const char * SEH_GetLanguageName(const int iLanguage);
const char * SEH_StringEd_GetString(const char *pszReference);
qboolean SEH_GetLanguageIndexForName(const char *pszLanguageName, int *piLanguageIndex);
int SEH_InitLanguage(void);
static qboolean SEH_StringEd_SetLanguageStrings(void);
int SEH_UpdateLanguageInfo(void);
unsigned int SEH_ReadCharFromString(const char * *ppsText, qboolean *pbIsTrailingPunctuation);
int SEH_PrintStrlen(const char *string);
const char * SEH_SafeTranslateString(const char *pszReference);
const char * SEH_LocalizeTextMessage(const char *pszInputBuffer, const char *pszMessageType, msgLocErrType_t errType);

/* line 119 */
__attribute__((naked))
int SEH_GetCurrentLanguage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 119 */
        "movl %esp, %ebp\n"
        "movl loc_language, %eax\n"
        "movl 8(%eax), %eax\n"
        "popl %ebp\n" /* line 123 */
        "retl\n"
    );
}

/* line 207 */
__attribute__((naked))
int SEH_VerifyLanguageSelection(int iLanguageSelection)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 207 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edi\n" /* iLanguageSelection */
        /* { scope 1 */
        "movl 0x308bc4(, %edi, 8), %edx\n" /* line 211 */
        "testl %edx, %edx\n"
        "jne .Lf31fba_0003200a\n"
        "xorl %esi, %esi\n" /* i */
        ".Lf31fba_00031fd0:\n"
        "leal (%esi, %edi), %ecx\n" /* line 216 | i */
        "movl $0x92492493, %eax\n"
        "imull %ecx\n"
        "leal (%edx, %ecx), %ebx\n"
        "sarl $3, %ebx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n"
        "leal (%ebx, %ebx), %edx\n"
        "movl %ebx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %ecx, %ebx\n"
        "subl %eax, %ebx\n"
        "movl 0x308bc4(, %ebx, 8), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf31fba_00032011\n"
        "addl $1, %esi\n" /* line 214 | i */
        "cmpl $0xe, %esi\n" /* i */
        "jne .Lf31fba_00031fd0\n"
        "xorl %edi, %edi\n" /* iLanguageSelection */
        /* } scope */
        ".Lf31fba_0003200a:\n"
        "movl %edi, %eax\n" /* line 222 | iLanguageSelection */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf31fba_00032011:\n"
        "movl %ebx, %edi\n" /* line 216 | iLanguageSelection */
        /* } scope */
        "movl %edi, %eax\n" /* line 222 | iLanguageSelection */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 235 */
__attribute__((naked))
int SEH_Init_StringEd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 235 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 238 */
        "jmp SE_Init\n" /* line 237 */
    );
}

/* line 246 */
__attribute__((naked))
int SEH_Shutdown_StringEd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 246 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 249 */
        "jmp SE_ShutDown\n" /* line 248 */
    );
}

/* line 954 */
__attribute__((naked))
const char * SEH_GetLanguageName(const int iLanguage)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 954 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* iLanguage */
        "cmpl $0xd, %eax\n" /* line 956 */
        "jbe .Lf3202e_00032040\n"
        "movl g_languages, %eax\n" /* line 957 */
        "popl %ebp\n" /* line 960 */
        "retl\n"
        ".Lf3202e_00032040:\n"
        "movl g_languages(, %eax, 8), %eax\n" /* line 959 */
        "popl %ebp\n" /* line 960 */
        "retl\n"
    );
}

/* line 301 */
__attribute__((naked))
const char * SEH_StringEd_GetString(const char *pszReference)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 301 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* pszReference */
        "movl loc_translate, %edx\n" /* line 304 */
        "testl %edx, %edx\n"
        "je .Lf3204a_0003206b\n"
        "cmpb $0, 8(%edx)\n"
        "je .Lf3204a_0003206b\n"
        "cmpb $0, (%eax)\n" /* line 308 */
        "je .Lf3204a_0003206b\n"
        "cmpb $0, 1(%eax)\n"
        "jne .Lf3204a_0003206d\n"
        ".Lf3204a_0003206b:\n"
        "popl %ebp\n" /* line 312 */
        "retl\n"
        ".Lf3204a_0003206d:\n"
        "popl %ebp\n"
        "jmp SE_GetString\n" /* line 311 */
    );
}

/* line 971 */
__attribute__((naked))
qboolean SEH_GetLanguageIndexForName(const char *pszLanguageName, int *piLanguageIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 971 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* pszLanguageName */
        "xorl %esi, %esi\n"
        "movl $g_languages, %ebx\n"
        /* { scope 1 */
        ".Lf32076_00032089:\n"
        "movl (%ebx), %eax\n" /* line 977 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pszLanguageName */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf32076_000320b9\n"
        "addl $1, %esi\n" /* line 975 | i */
        "addl $8, %ebx\n"
        "cmpl $0xe, %esi\n" /* i */
        "jne .Lf32076_00032089\n"
        "movl 0xc(%ebp), %eax\n" /* line 985 | piLanguageIndex */
        "movl $0, (%eax)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 987 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf32076_000320b9:\n"
        "movl 0xc(%ebp), %eax\n" /* line 979 | piLanguageIndex */
        "movl %esi, (%eax)\n" /* i */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 987 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 131 */
__attribute__((naked))
int SEH_InitLanguage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 131 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0x1021, 0x10(%esp)\n" /* line 133 */
        "movl $0xd, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x216a14, (%esp)\n" /* "loc_language" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, loc_language\n"
        "movl $0x1021, 8(%esp)\n" /* line 134 */
        "movl $0, 4(%esp)\n"
        "movl $0x216a24, (%esp)\n" /* "loc_forceEnglish" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, loc_forceEnglish\n"
        "movl $0x1020, 8(%esp)\n" /* line 135 */
        "movl $1, 4(%esp)\n"
        "movl $0x216a38, (%esp)\n" /* "loc_translate" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, loc_translate\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 136 */
        "movl $0, 4(%esp)\n"
        "movl $0x216a48, (%esp)\n" /* "loc_warnings" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, loc_warnings\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 137 */
        "movl $0, 4(%esp)\n"
        "movl $0x216a58, (%esp)\n" /* "loc_warningsAsErrors" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, loc_warningsAsErrors\n"
        "movl loc_language, %eax\n" /* line 93 */
        "movl 8(%eax), %eax\n"
        "subl $8, %eax\n"
        "cmpl $4, %eax\n" /* line 100 */
        "setbe %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, g_currentAsian\n"
        "leave\n" /* line 140 */
        "retl\n"
    );
}

/* line 257 */
static __attribute__((naked))
qboolean SEH_StringEd_SetLanguageStrings(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 257 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl %eax, %ebx\n" /* iLanguage */
        /* { scope 1 */
        "movl 0x308bc4(, %eax, 8), %ecx\n" /* line 261 */
        "testl %ecx, %ecx\n"
        "jne .Lf321a4_000321c0\n"
        ".Lf321a4_000321b8:\n"
        "xorl %eax, %eax\n" /* line 275 */
        /* } scope */
        ".Lf321a4_000321ba:\n"
        "addl $0x14, %esp\n" /* line 278 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf321a4_000321c0:\n"
        "movl loc_forceEnglish, %eax\n" /* line 265 */
        "movzbl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SE_LoadLanguage\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 266 */
        "je .Lf321a4_0003225f\n"
        "movl 0x195ecb8, %eax\n" /* line 270 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf321a4_000321b8\n"
        "movl loc_warnings, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf321a4_000321b8\n"
        "movl loc_warningsAsErrors, %eax\n" /* line 272 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf321a4_00032228\n"
        "cmpl $0xd, %ebx\n" /* line 956 | iLanguage */
        "jbe .Lf321a4_00032256\n"
        "movl g_languages, %eax\n" /* line 957 */
        ".Lf321a4_00032208:\n"
        "movl %edx, 0xc(%esp)\n" /* line 273 */
        "movl %eax, 8(%esp)\n"
        "movl $0x216a70, 4(%esp)\n" /* "Could not load localization strings for %s: %s" */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf321a4_000321ba\n"
        ".Lf321a4_00032228:\n"
        "cmpl $0xd, %ebx\n" /* line 956 | iLanguage */
        "jbe .Lf321a4_0003224d\n"
        "movl g_languages, %eax\n" /* line 957 */
        ".Lf321a4_00032232:\n"
        "movl %edx, 8(%esp)\n" /* line 275 */
        "movl %eax, 4(%esp)\n"
        "movl $0x216aa0, (%esp)\n" /* "^3WARNING: Could not load localization strings for %s: %s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf321a4_000321ba\n"
        ".Lf321a4_0003224d:\n"
        "movl g_languages(, %ebx, 8), %eax\n" /* line 959 */
        "jmp .Lf321a4_00032232\n"
        ".Lf321a4_00032256:\n"
        "movl g_languages(, %ebx, 8), %eax\n"
        "jmp .Lf321a4_00032208\n"
        ".Lf321a4_0003225f:\n"
        "movl $1, %eax\n" /* line 266 */
        "jmp .Lf321a4_000321ba\n"
    );
}

/* line 153 */
__attribute__((naked))
int SEH_UpdateLanguageInfo(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 153 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $0x1021, 0x10(%esp)\n" /* line 160 */
        "movl $0xd, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl loc_language, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl $0x1021, 8(%esp)\n" /* line 161 */
        "movl $0, 4(%esp)\n"
        "movl loc_forceEnglish, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_RegisterBool\n"
        "movl loc_language, %eax\n" /* line 93 */
        "movl 8(%eax), %eax\n"
        "subl $8, %eax\n"
        "cmpl $4, %eax\n" /* line 100 */
        "setbe %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, g_currentAsian\n"
        "xorl %edi, %edi\n" /* line 104 */
        "xorl %ebx, %ebx\n"
        "movl $g_languages, %esi\n"
        "jmp .Lf3226a_000322fa\n"
        ".Lf3226a_000322e5:\n"
        "movl $1, 4(%esi)\n" /* line 170 */
        "addl $1, %edi\n" /* line 171 | iNumLanguages */
        "addl $1, %ebx\n" /* line 166 | i */
        "addl $8, %esi\n"
        "cmpl $0xe, %ebx\n" /* i */
        "je .Lf3226a_00032318\n"
        ".Lf3226a_000322fa:\n"
        "movl %ebx, (%esp)\n" /* line 168 | i */
        "calll FS_LanguageHasAssets\n"
        "testl %eax, %eax\n"
        "jne .Lf3226a_000322e5\n"
        "movl $0, 4(%esi)\n" /* line 175 */
        "addl $1, %ebx\n" /* line 166 | i */
        "addl $8, %esi\n"
        "cmpl $0xe, %ebx\n" /* i */
        "jne .Lf3226a_000322fa\n"
        ".Lf3226a_00032318:\n"
        "testl %edi, %edi\n" /* line 180 | iNumLanguages */
        "jle .Lf3226a_000323ae\n"
        ".Lf3226a_00032320:\n"
        "movl loc_language, %eax\n" /* line 183 */
        "movl 8(%eax), %eax\n"
        "calll SEH_StringEd_SetLanguageStrings\n"
        "testl %eax, %eax\n"
        "je .Lf3226a_00032339\n"
        /* } scope */
        ".Lf3226a_00032331:\n"
        "addl $0x2c, %esp\n" /* line 197 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3226a_00032339:\n"
        "xorl %ebx, %ebx\n" /* line 184 | i */
        ".Lf3226a_0003233b:\n"
        "movl %ebx, 4(%esp)\n" /* line 188 | i */
        "movl loc_language, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl loc_language, %eax\n" /* line 93 */
        "movl 8(%eax), %eax\n"
        "subl $8, %eax\n"
        "cmpl $4, %eax\n" /* line 100 */
        "setbe %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, g_currentAsian\n"
        "movl %ebx, %eax\n" /* line 190 | i */
        "calll SEH_StringEd_SetLanguageStrings\n"
        "testl %eax, %eax\n"
        "jne .Lf3226a_00032331\n"
        "addl $1, %ebx\n" /* line 186 | i */
        "cmpl $0xe, %ebx\n" /* i */
        "jne .Lf3226a_0003233b\n"
        "movl $0, 4(%esp)\n" /* line 195 */
        "movl loc_language, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl loc_language, %eax\n" /* line 93 */
        "movl 8(%eax), %eax\n"
        "subl $8, %eax\n"
        "cmpl $4, %eax\n" /* line 100 */
        "setbe %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, g_currentAsian\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 197 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3226a_000323ae:\n"
        "movl $0x216adc, (%esp)\n" /* line 181 */
        "calll Com_Printf\n"
        "jmp .Lf3226a_00032320\n"
    );
}

/* line 796 */
__attribute__((naked))
unsigned int SEH_ReadCharFromString(const char * *ppsText, qboolean *pbIsTrailingPunctuation)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 796 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %edi\n" /* ppsText */
        "movl 0xc(%ebp), %esi\n" /* pbIsTrailingPunctuation */
        /* { scope 1: _iLo */
        "movl (%edi), %ecx\n" /* line 798 | ppsText */
        "movl g_currentAsian, %ebx\n" /* line 801 | uiLetter */
        "testl %ebx, %ebx\n" /* uiLetter */
        "je .Lf323c0_00032400\n"
        "movl loc_language, %eax\n" /* line 803 */
        "movl 8(%eax), %eax\n"
        "cmpl $9, %eax\n"
        "je .Lf323c0_0003247d\n"
        "jle .Lf323c0_00032442\n"
        "cmpl $0xa, %eax\n"
        "je .Lf323c0_000324d8\n"
        "cmpl $0xb, %eax\n"
        "je .Lf323c0_00032531\n"
        ".Lf323c0_00032400:\n"
        "movzbl (%ecx), %edx\n" /* line 876 */
        "movzbl %dl, %ebx\n" /* _iLo */
        "leal 1(%ecx), %eax\n" /* line 877 */
        "movl %eax, (%edi)\n" /* ppsText */
        "testl %esi, %esi\n" /* line 879 | pbIsTrailingPunctuation */
        "je .Lf323c0_00032431\n"
        "cmpb $0x21, %dl\n" /* line 880 */
        "je .Lf323c0_0003243b\n"
        "cmpb $0x3f, %dl\n"
        "je .Lf323c0_0003243b\n"
        "cmpb $0x2c, %dl\n"
        "je .Lf323c0_0003243b\n"
        "cmpb $0x2e, %dl\n"
        "je .Lf323c0_0003243b\n"
        "cmpb $0x3b, %dl\n"
        "je .Lf323c0_0003243b\n"
        "cmpb $0x3a, %dl\n"
        "je .Lf323c0_0003243b\n"
        "xorl %eax, %eax\n"
        ".Lf323c0_0003242f:\n"
        "movl %eax, (%esi)\n" /* pbIsTrailingPunctuation */
        /* } scope */
        ".Lf323c0_00032431:\n"
        "movl %ebx, %eax\n" /* line 883 | _iLo */
        "addl $0xc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: _iLo */
        ".Lf323c0_0003243b:\n"
        "movl $1, %eax\n" /* line 880 */
        "jmp .Lf323c0_0003242f\n"
        ".Lf323c0_00032442:\n"
        "cmpl $8, %eax\n" /* line 803 */
        "jne .Lf323c0_00032400\n"
        "movzbl 1(%ecx), %eax\n" /* line 806 */
        "movl %eax, -0x10(%ebp)\n"
        "movzbl (%ecx), %edx\n"
        "movl %eax, %ebx\n" /* _iLo */
        /* { scope 2 */
        "leal 0x50(%edx), %eax\n" /* line 567 */
        "cmpb $0x18, %al\n"
        "jbe .Lf323c0_00032593\n"
        ".Lf323c0_0003245e:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf323c0_00032460:\n"
        "testl %eax, %eax\n" /* line 806 */
        "je .Lf323c0_00032400\n"
        "shll $8, %edx\n" /* line 808 */
        "movl -0x10(%ebp), %ebx\n" /* _iLo */
        "addl %edx, %ebx\n" /* _iLo */
        "leal 2(%ecx), %eax\n" /* line 809 */
        "movl %eax, (%edi)\n" /* ppsText */
        "testl %esi, %esi\n" /* line 814 | pbIsTrailingPunctuation */
        "je .Lf323c0_00032431\n"
        "movl $0, (%esi)\n" /* line 815 | pbIsTrailingPunctuation */
        "jmp .Lf323c0_00032431\n"
        ".Lf323c0_0003247d:\n"
        "movzbl (%ecx), %eax\n" /* line 822 */
        "shll $8, %eax\n"
        "movzbl 1(%ecx), %edx\n"
        "leal (%eax, %edx), %ebx\n" /* _iLo */
        /* { scope 2 */
        "movl %ebx, %edx\n" /* line 612 | _iHi */
        "shrl $8, %edx\n" /* _iHi */
        "leal 0x5f(%edx), %eax\n" /* line 614 */
        "cmpb $0x25, %al\n"
        "jbe .Lf323c0_000324a1\n"
        "leal 0x37(%edx), %eax\n"
        "cmpb $0x30, %al\n"
        "ja .Lf323c0_00032400\n"
        /* { scope 3 */
        ".Lf323c0_000324a1:\n"
        "movl %ebx, %edx\n" /* line 616 | _iLo */
        "leal -0x40(%edx), %eax\n" /* line 618 */
        "cmpb $0x3e, %al\n"
        "jbe .Lf323c0_000324b5\n"
        "leal 0x5f(%edx), %eax\n"
        "cmpb $0x5d, %al\n"
        "ja .Lf323c0_00032400\n"
        /* } scope */
        /* } scope */
        ".Lf323c0_000324b5:\n"
        "leal 2(%ecx), %eax\n" /* line 825 */
        "movl %eax, (%edi)\n" /* ppsText */
        "testl %esi, %esi\n" /* line 829 | pbIsTrailingPunctuation */
        "je .Lf323c0_00032431\n"
        "leal -0xa140(%ebx), %eax\n" /* line 830 | _iLo */
        "cmpl $0x13, %eax\n"
        "setbe %al\n"
        "andl $1, %eax\n"
        "movl %eax, (%esi)\n" /* pbIsTrailingPunctuation */
        "jmp .Lf323c0_00032431\n"
        ".Lf323c0_000324d8:\n"
        "movzbl 1(%ecx), %eax\n" /* line 837 */
        "movl %eax, -0x14(%ebp)\n"
        "movzbl (%ecx), %ebx\n" /* _iLo */
        "movb %al, -0x15(%ebp)\n" /* _iLo */
        /* { scope 2 */
        "leal 0x7f(%ebx), %eax\n" /* line 683 */
        "cmpb $0x1e, %al\n"
        "ja .Lf323c0_00032583\n"
        ".Lf323c0_000324f0:\n"
        "movzbl -0x15(%ebp), %eax\n" /* line 685 | _iLo */
        "subb $0x40, %al\n"
        "cmpb $0x3e, %al\n"
        "jbe .Lf323c0_00032508\n"
        "movzbl -0x15(%ebp), %eax\n" /* _iLo */
        "addb $0x80, %al\n"
        "cmpb $0x7c, %al\n"
        "ja .Lf323c0_00032400\n"
        /* } scope */
        ".Lf323c0_00032508:\n"
        "shll $8, %ebx\n" /* line 839 | _iLo */
        "addl -0x14(%ebp), %ebx\n" /* _iLo */
        "leal 2(%ecx), %eax\n" /* line 840 */
        "movl %eax, (%edi)\n" /* ppsText */
        "testl %esi, %esi\n" /* line 844 | pbIsTrailingPunctuation */
        "je .Lf323c0_00032431\n"
        "leal -0x8140(%ebx), %eax\n" /* line 845 | _iLo */
        "cmpl $0x11, %eax\n"
        "setbe %al\n"
        "andl $1, %eax\n"
        "movl %eax, (%esi)\n" /* pbIsTrailingPunctuation */
        "jmp .Lf323c0_00032431\n"
        ".Lf323c0_00032531:\n"
        "movzbl (%ecx), %eax\n" /* line 852 */
        "shll $8, %eax\n"
        "movzbl 1(%ecx), %edx\n"
        "leal (%eax, %edx), %ebx\n" /* _iLo */
        "movl %ebx, %edx\n" /* _iLo */
        /* { scope 2 */
        "movzbl %bh, %eax\n" /* line 748 */
        "addb $0x5f, %al\n"
        "cmpb $0x56, %al\n"
        "ja .Lf323c0_000325af\n"
        "cmpb $0xa0, %bl\n"
        "jbe .Lf323c0_000325af\n"
        "addb $1, %dl\n"
        "je .Lf323c0_000325af\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf323c0_00032558:\n"
        "testl %eax, %eax\n" /* line 852 */
        "je .Lf323c0_00032400\n"
        "leal 2(%ecx), %eax\n" /* line 855 */
        "movl %eax, (%edi)\n" /* ppsText */
        "testl %esi, %esi\n" /* line 859 | pbIsTrailingPunctuation */
        "je .Lf323c0_00032431\n"
        "leal -0xa1a1(%ebx), %eax\n" /* line 861 | _iLo */
        "cmpl $0xc, %eax\n"
        "setbe %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esi)\n" /* pbIsTrailingPunctuation */
        "jmp .Lf323c0_00032431\n"
        /* { scope 2 */
        ".Lf323c0_00032583:\n"
        "leal 0x20(%ebx), %eax\n" /* line 683 */
        "cmpb $0xf, %al\n"
        "ja .Lf323c0_00032400\n"
        "jmp .Lf323c0_000324f0\n"
        /* } scope */
        /* { scope 2 */
        ".Lf323c0_00032593:\n"
        "cmpb $0xa0, %bl\n" /* line 567 */
        "jbe .Lf323c0_0003245e\n"
        "addb $1, %bl\n"
        "je .Lf323c0_0003245e\n"
        "movl $1, %eax\n"
        "jmp .Lf323c0_00032460\n"
        /* } scope */
        /* { scope 2 */
        ".Lf323c0_000325af:\n"
        "xorl %eax, %eax\n" /* line 748 */
        "jmp .Lf323c0_00032558\n"
    );
}

/* line 909 */
__attribute__((naked))
int SEH_PrintStrlen(const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 909 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* string */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 915 */
        "je .Lf325b4_00032627\n"
        "movl %eax, -0xc(%ebp)\n" /* line 919 | p */
        "xorl %ebx, %ebx\n" /* len */
        ".Lf325b4_000325c7:\n"
        "cmpb $0, (%eax)\n" /* line 920 */
        "je .Lf325b4_000325f9\n"
        ".Lf325b4_000325cc:\n"
        "movl $0, 4(%esp)\n" /* line 922 */
        "leal -0xc(%ebp), %eax\n" /* p */
        "movl %eax, (%esp)\n"
        "calll SEH_ReadCharFromString\n"
        "cmpl $0x5e, %eax\n" /* line 924 */
        "je .Lf325b4_00032606\n"
        "cmpl $0xa, %eax\n" /* line 931 */
        "je .Lf325b4_00032601\n"
        "cmpl $0xd, %eax\n"
        "je .Lf325b4_00032601\n"
        "movl -0xc(%ebp), %eax\n" /* p */
        ".Lf325b4_000325f1:\n"
        "addl $1, %ebx\n" /* line 934 | len */
        "cmpb $0, (%eax)\n" /* line 920 */
        "jne .Lf325b4_000325cc\n"
        /* } scope */
        ".Lf325b4_000325f9:\n"
        "movl %ebx, %eax\n" /* line 938 | len */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf325b4_00032601:\n"
        "movl -0xc(%ebp), %eax\n" /* p */
        "jmp .Lf325b4_000325c7\n"
        /* { scope 1 */
        ".Lf325b4_00032606:\n"
        "movl -0xc(%ebp), %eax\n" /* line 924 | p */
        "testl %eax, %eax\n"
        "je .Lf325b4_000325f1\n"
        "movzbl (%eax), %edx\n"
        "cmpb $0x5e, %dl\n"
        "je .Lf325b4_000325f1\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf325b4_000325f1\n"
        "cmpb $0x39, %dl\n"
        "jg .Lf325b4_000325f1\n"
        "addl $1, %eax\n" /* line 927 */
        "movl %eax, -0xc(%ebp)\n" /* p */
        "jmp .Lf325b4_000325c7\n"
        ".Lf325b4_00032627:\n"
        "xorl %ebx, %ebx\n" /* line 915 | len */
        /* } scope */
        "movl %ebx, %eax\n" /* line 938 | len */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 323 */
__attribute__((naked))
const char * SEH_SafeTranslateString(const char *pszReference)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 323 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pszReference */
        /* { scope 1 */
        "movl loc_translate, %eax\n" /* line 304 */
        "testl %eax, %eax\n"
        "je .Lf32632_0003264b\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf32632_00032657\n"
        ".Lf32632_0003264b:\n"
        "movl %ebx, %eax\n" /* line 311 */
        ".Lf32632_0003264d:\n"
        "testl %eax, %eax\n" /* line 329 */
        "je .Lf32632_0003266e\n"
        /* } scope */
        ".Lf32632_00032651:\n"
        "addl $0x14, %esp\n" /* line 349 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf32632_00032657:\n"
        "cmpb $0, (%ebx)\n" /* line 308 */
        "je .Lf32632_00032666\n"
        "cmpb $0, 1(%ebx)\n"
        "jne .Lf32632_00032712\n"
        ".Lf32632_00032666:\n"
        "movl %ebx, %eax\n" /* line 343 | pszReference */
        /* } scope */
        "addl $0x14, %esp\n" /* line 349 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf32632_0003266e:\n"
        "movl loc_warnings, %eax\n" /* line 331 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf32632_0003271f\n"
        "movl loc_warningsAsErrors, %eax\n" /* line 333 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf32632_00032741\n"
        "movl %ebx, 8(%esp)\n" /* line 334 | pszReference */
        "movl $0x216b24, 4(%esp)\n" /* "Could not translate exe string "%s"" */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        ".Lf32632_000326a4:\n"
        "movl $0x4e55315e, szErrorString\n" /* line 338 */
        "movl $0x41434f4c, 0x33c1a4\n"
        "movl $0x455a494c, 0x33c1a8\n"
        "movl $0x375e2844, 0x33c1ac\n"
        "movb $0, 0x33c1b0\n"
        "movl %ebx, 8(%esp)\n" /* line 339 | pszReference */
        "movl $0x400, 4(%esp)\n"
        "movl $szErrorString, (%esp)\n"
        "calll I_strncat\n"
        "movl $0x216b78, 8(%esp)\n" /* line 340 */
        "movl $0x400, 4(%esp)\n"
        "movl $szErrorString, (%esp)\n"
        "calll I_strncat\n"
        "movl $szErrorString, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 349 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf32632_00032712:\n"
        "movl %ebx, (%esp)\n" /* line 311 */
        "calll SE_GetString\n"
        "jmp .Lf32632_0003264d\n"
        ".Lf32632_0003271f:\n"
        "movl $0x400, 8(%esp)\n" /* line 343 */
        "movl %ebx, 4(%esp)\n" /* pszReference */
        "movl $szErrorString, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $szErrorString, %eax\n"
        "jmp .Lf32632_00032651\n"
        ".Lf32632_00032741:\n"
        "movl %ebx, 4(%esp)\n" /* line 336 | pszReference */
        "movl $0x216b48, (%esp)\n" /* "^3WARNING: Could not translate exe string "%s"
" */
        "calll Com_Printf\n"
        "jmp .Lf32632_000326a4\n"
    );
}

/* line 400 */
__attribute__((naked))
const char * SEH_LocalizeTextMessage(const char *pszInputBuffer, const char *pszMessageType, msgLocErrType_t errType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 400 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x86c, %esp\n"
        /* { scope 1 */
        "movl iCurrString, %eax\n" /* line 420 */
        "addl $1, %eax\n"
        "andl $0x80000001, %eax\n"
        "js .Lf32756_00032c23\n"
        ".Lf32756_00032775:\n"
        "movl %eax, iCurrString\n"
        "shll $0xa, %eax\n" /* line 421 */
        "addl $szStrings, %eax\n"
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl iCurrString, %eax\n" /* line 422 */
        "shll $0xa, %eax\n"
        "addl $szStrings, %eax\n"
        "movl %eax, -0x844(%ebp)\n" /* pszString */
        "movl 8(%ebp), %edx\n" /* pszInputBuffer */
        "movl %edx, -0x840(%ebp)\n" /* pszIn */
        "movl $0, -0x820(%ebp)\n"
        "movl $1, -0x83c(%ebp)\n" /* bLocOn */
        "movl $1, %ebx\n" /* bInsertEnabled */
        "movl $0, -0x838(%ebp)\n" /* iInsertLevel */
        "movl $1, -0x830(%ebp)\n" /* insertIndex */
        "movl $0, -0x834(%ebp)\n" /* bLocSkipped */
        ".Lf32756_000327ed:\n"
        "cmpb $0, (%edx)\n" /* line 434 */
        "je .Lf32756_00032817\n"
        ".Lf32756_000327f2:\n"
        "movl -0x840(%ebp), %ecx\n" /* line 436 | pszIn */
        "movzbl (%ecx), %eax\n"
        "testb %al, %al\n"
        "je .Lf32756_00032866\n"
        "cmpb $0x14, %al\n"
        "je .Lf32756_00032866\n"
        "cmpb $0x15, %al\n"
        "je .Lf32756_00032866\n"
        "cmpb $0x16, %al\n"
        "je .Lf32756_00032866\n"
        "addl $1, -0x840(%ebp)\n" /* line 534 | pszIn */
        "cmpb $0, (%edx)\n" /* line 434 */
        "jne .Lf32756_000327f2\n"
        ".Lf32756_00032817:\n"
        "movl -0x834(%ebp), %edi\n" /* line 538 | bLocSkipped, digit */
        "testl %edi, %edi\n" /* digit */
        "je .Lf32756_00032855\n"
        "movl -0x820(%ebp), %esi\n" /* line 540 | _c */
        "testl %esi, %esi\n" /* _c */
        "jle .Lf32756_00032855\n"
        "xorl %edx, %edx\n" /* line 538 */
        "jmp .Lf32756_0003283a\n"
        ".Lf32756_0003282f:\n"
        "addl $1, %edx\n" /* line 540 */
        "cmpl -0x820(%ebp), %edx\n"
        "je .Lf32756_00032855\n"
        ".Lf32756_0003283a:\n"
        "movl -0x844(%ebp), %eax\n" /* line 400 | pszString */
        "addl %edx, %eax\n"
        "cmpb $0x16, (%eax)\n" /* line 542 */
        "jne .Lf32756_0003282f\n"
        "movb $0x25, (%eax)\n" /* line 543 */
        "addl $1, %edx\n" /* line 540 */
        "cmpl -0x820(%ebp), %edx\n"
        "jne .Lf32756_0003283a\n"
        ".Lf32756_00032855:\n"
        "movl -0x844(%ebp), %eax\n" /* line 547 | pszString */
        /* } scope */
        ".Lf32756_0003285b:\n"
        "addl $0x86c, %esp\n" /* line 548 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf32756_00032866:\n"
        "cmpl -0x840(%ebp), %edx\n" /* line 438 | pszIn */
        "jb .Lf32756_00032899\n"
        ".Lf32756_0003286e:\n"
        "cmpb $0x14, %al\n" /* line 513 */
        "je .Lf32756_000329e8\n"
        ".Lf32756_00032876:\n"
        "cmpb $0x15, %al\n" /* line 518 */
        "je .Lf32756_00032a1c\n"
        ".Lf32756_0003287e:\n"
        "movl -0x840(%ebp), %ecx\n" /* line 524 | pszIn */
        "cmpb $0x16, (%ecx)\n"
        "je .Lf32756_00032a08\n"
        ".Lf32756_0003288d:\n"
        "movl %ecx, %edx\n"
        "movl $1, %ebx\n" /* bInsertEnabled */
        "jmp .Lf32756_000327ed\n"
        ".Lf32756_00032899:\n"
        "movl -0x840(%ebp), %eax\n" /* line 440 | pszIn */
        "subl %edx, %eax\n"
        "movl %eax, -0x848(%ebp)\n" /* iTokenLen */
        "addl $1, %eax\n" /* line 441 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* szTokenBuf */
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x83c(%ebp), %eax\n" /* line 443 | bLocOn */
        "testl %eax, %eax\n"
        "jne .Lf32756_00032bb2\n"
        "movl -0x848(%ebp), %edx\n" /* iTokenLen */
        ".Lf32756_000328d4:\n"
        "addl -0x820(%ebp), %edx\n" /* line 450 */
        "movl %edx, -0x84c(%ebp)\n" /* iLen */
        "cmpl $0x3ff, %edx\n"
        "jle .Lf32756_00032924\n"
        "movl loc_warnings, %eax\n" /* line 452 */
        "testl %eax, %eax\n"
        "je .Lf32756_0003290a\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf32756_0003290a\n"
        "movl loc_warningsAsErrors, %eax\n" /* line 454 */
        "testl %eax, %eax\n"
        "je .Lf32756_0003290a\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf32756_00032b81\n"
        ".Lf32756_0003290a:\n"
        "movl 8(%ebp), %edx\n" /* line 457 | pszInputBuffer */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* pszMessageType */
        "movl %ecx, 4(%esp)\n"
        "movl $0x216c18, (%esp)\n" /* "%s too long when translated: "%s"
" */
        "calll Com_Printf\n"
        ".Lf32756_00032924:\n"
        "movl -0x848(%ebp), %eax\n" /* line 460 | iTokenLen */
        "subl $2, %eax\n"
        "movl %eax, -0x854(%ebp)\n"
        "testl %eax, %eax\n"
        "jg .Lf32756_00032a32\n"
        ".Lf32756_0003293b:\n"
        "movl -0x838(%ebp), %eax\n" /* line 476 | iInsertLevel */
        "testl %eax, %eax\n"
        "jle .Lf32756_00032aad\n"
        "movl -0x820(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf32756_00032aad\n"
        "movl -0x820(%ebp), %eax\n" /* line 478 */
        "subl $2, %eax\n"
        "movl %eax, -0x82c(%ebp)\n"
        "testl %eax, %eax\n"
        "jg .Lf32756_00032ae5\n"
        "movl -0x844(%ebp), %edx\n" /* pszString */
        "movl %edx, -0x81c(%ebp)\n"
        "movl $0, -0x82c(%ebp)\n"
        "leal -0x818(%ebp), %edi\n" /* szInsertBuf, digit */
        ".Lf32756_0003298a:\n"
        "leal -0x418(%ebp), %eax\n" /* line 497 | szTokenBuf */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "movl %edi, 4(%esp)\n" /* line 498 | digit */
        "movl -0x848(%ebp), %eax\n" /* iTokenLen */
        "addl -0x82c(%ebp), %eax\n"
        "addl -0x844(%ebp), %eax\n" /* pszString */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "subl $1, -0x838(%ebp)\n" /* line 501 | iInsertLevel */
        "movl -0x820(%ebp), %ecx\n"
        "movl -0x848(%ebp), %eax\n" /* iTokenLen */
        "leal -3(%ecx, %eax), %ecx\n"
        "movl %ecx, -0x820(%ebp)\n"
        "movl -0x840(%ebp), %edx\n" /* pszIn */
        "movzbl (%edx), %eax\n"
        "cmpb $0x14, %al\n" /* line 513 */
        "jne .Lf32756_00032876\n"
        ".Lf32756_000329e8:\n"
        "addl $1, -0x840(%ebp)\n" /* line 516 | pszIn */
        "movl $1, -0x83c(%ebp)\n" /* bLocOn */
        "movl -0x840(%ebp), %ecx\n" /* line 524 | pszIn */
        "cmpb $0x16, (%ecx)\n"
        "jne .Lf32756_0003288d\n"
        ".Lf32756_00032a08:\n"
        "addl $1, -0x840(%ebp)\n" /* line 527 | pszIn */
        "movl -0x840(%ebp), %edx\n" /* pszIn */
        "xorl %ebx, %ebx\n" /* bInsertEnabled */
        "jmp .Lf32756_000327ed\n"
        ".Lf32756_00032a1c:\n"
        "addl $1, -0x840(%ebp)\n" /* line 521 | pszIn */
        "movl $0, -0x83c(%ebp)\n" /* bLocOn */
        "jmp .Lf32756_0003287e\n"
        ".Lf32756_00032a32:\n"
        "testl %ebx, %ebx\n" /* line 478 | bInsertEnabled */
        "je .Lf32756_00032d10\n"
        "movl $0, -0x824(%ebp)\n"
        "cld\n"
        "leal -0x418(%ebp), %ebx\n" /* szTokenBuf, bInsertEnabled */
        "jmp .Lf32756_00032a69\n"
        ".Lf32756_00032a4d:\n"
        "addl $1, -0x824(%ebp)\n" /* line 460 */
        "addl $1, %ebx\n" /* bInsertEnabled */
        "movl -0x824(%ebp), %ecx\n"
        "cmpl %ecx, -0x854(%ebp)\n"
        "je .Lf32756_0003293b\n"
        ".Lf32756_00032a69:\n"
        "movl $2, %ecx\n" /* line 462 */
        "movl %ebx, %esi\n" /* bInsertEnabled */
        "movl $0x216c3c, %edi\n" /* digit */
        "repe cmpsb %es:(%edi), (%esi)\n" /* digit */
        "movl $0, %eax\n" /* _c */
        "je .Lf32756_00032a88\n"
        "movzbl -1(%esi), %eax\n" /* _c */
        "movzbl -1(%edi), %ecx\n" /* digit */
        "subl %ecx, %eax\n" /* _c */
        ".Lf32756_00032a88:\n"
        "testl %eax, %eax\n" /* _c */
        "jne .Lf32756_00032a4d\n"
        "movsbl 2(%ebx), %eax\n" /* bInsertEnabled, _c */
        /* { scope 2 */
        "cmpl $0xff, %eax\n" /* line 231 */
        "ja .Lf32756_00032a4d\n"
        "movl __DefaultRuneLocale, %edx\n"
        "testb $4, 0x35(%edx, %eax, 4)\n"
        "je .Lf32756_00032a4d\n"
        /* } scope */
        "addl $1, -0x838(%ebp)\n" /* line 471 | iInsertLevel */
        "jmp .Lf32756_00032a4d\n"
        ".Lf32756_00032aad:\n"
        "leal -0x418(%ebp), %ecx\n" /* line 505 | szTokenBuf */
        "movl %ecx, 4(%esp)\n"
        "movl -0x844(%ebp), %eax\n" /* pszString */
        "addl -0x820(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x84c(%ebp), %eax\n" /* iLen */
        "movl %eax, -0x820(%ebp)\n"
        "movl -0x840(%ebp), %edx\n" /* pszIn */
        "movzbl (%edx), %eax\n"
        "jmp .Lf32756_0003286e\n"
        ".Lf32756_00032ae5:\n"
        "movl -0x844(%ebp), %ebx\n" /* line 478 | pszString, bInsertEnabled */
        "movl $0, -0x828(%ebp)\n"
        ".Lf32756_00032af5:\n"
        "movl %ebx, -0x81c(%ebp)\n" /* line 476 | bInsertEnabled */
        "movl $2, %ecx\n" /* line 480 */
        "cld\n"
        "movl %ebx, %esi\n" /* bInsertEnabled, _c */
        "movl $0x216c3c, %edi\n" /* digit */
        "repe cmpsb %es:(%edi), (%esi)\n" /* digit, _c */
        "movl $0, %eax\n"
        "je .Lf32756_00032b1b\n"
        "movzbl -1(%esi), %eax\n" /* _c */
        "movzbl -1(%edi), %ecx\n" /* digit */
        "subl %ecx, %eax\n"
        ".Lf32756_00032b1b:\n"
        "testl %eax, %eax\n"
        "jne .Lf32756_00032b4e\n"
        "movsbl 2(%ebx), %esi\n" /* bInsertEnabled, _c */
        /* { scope 2 */
        "cmpl $0xff, %esi\n" /* line 231 */
        "ja .Lf32756_00032b4e\n"
        "movl __DefaultRuneLocale, %eax\n"
        "testb $4, 0x35(%eax, %esi, 4)\n"
        "je .Lf32756_00032b4e\n"
        /* } scope */
        "movl %esi, %edi\n" /* line 483 | _c, digit */
        "subl $0x30, %edi\n" /* digit */
        "je .Lf32756_00032c04\n"
        ".Lf32756_00032b42:\n"
        "cmpl %edi, -0x830(%ebp)\n" /* line 486 | digit, insertIndex */
        "je .Lf32756_00032cc0\n"
        ".Lf32756_00032b4e:\n"
        "addl $1, -0x828(%ebp)\n" /* line 478 */
        "addl $1, %ebx\n" /* bInsertEnabled */
        "movl -0x828(%ebp), %edx\n"
        "cmpl %edx, -0x82c(%ebp)\n"
        "jne .Lf32756_00032af5\n"
        "movl -0x844(%ebp), %ecx\n" /* pszString */
        "addl %edx, %ecx\n"
        "movl %ecx, -0x81c(%ebp)\n"
        "leal -0x818(%ebp), %edi\n" /* szInsertBuf, digit */
        "movl %ecx, %edx\n"
        "jmp .Lf32756_0003298a\n"
        ".Lf32756_00032b81:\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 454 | errType */
        "je .Lf32756_0003290a\n"
        "movl 8(%ebp), %ecx\n" /* line 455 | pszInputBuffer */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pszMessageType */
        "movl %eax, 8(%esp)\n"
        "movl $0x216bf4, 4(%esp)\n" /* "%s too long when translated: "%s"" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf32756_0003290a\n"
        /* { scope 2 */
        ".Lf32756_00032bb2:\n"
        "movl loc_translate, %eax\n" /* line 304 */
        "testl %eax, %eax\n"
        "je .Lf32756_00032bca\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf32756_00032bca\n"
        "cmpb $0, -0x418(%ebp)\n" /* line 308 | szTokenBuf */
        "jne .Lf32756_00032c31\n"
        ".Lf32756_00032bca:\n"
        "leal -0x418(%ebp), %eax\n" /* line 378 | szTokenBuf */
        ".Lf32756_00032bd0:\n"
        "movl %eax, 4(%esp)\n" /* line 382 */
        "leal -0x418(%ebp), %eax\n" /* szTokenBuf */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        /* } scope */
        "cld\n" /* line 447 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x418(%ebp), %edi\n" /* szTokenBuf, digit */
        "repne scasb %es:(%edi), %al\n" /* digit */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x848(%ebp)\n" /* iTokenLen */
        "movl %ecx, %edx\n"
        "jmp .Lf32756_000328d4\n"
        ".Lf32756_00032c04:\n"
        "movl 8(%ebp), %ecx\n" /* line 484 | pszInputBuffer */
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pszMessageType */
        "movl %eax, 4(%esp)\n"
        "movl $0x216c40, (%esp)\n" /* "%s cannot have &&0 as conversion format: "%s"
" */
        "calll Com_Printf\n"
        "jmp .Lf32756_00032b42\n"
        ".Lf32756_00032c23:\n"
        "subl $1, %eax\n" /* line 420 */
        "orl $0xfffffffe, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf32756_00032775\n"
        /* { scope 2 */
        ".Lf32756_00032c31:\n"
        "cmpb $0, -0x417(%ebp)\n" /* line 308 */
        "je .Lf32756_00032bca\n"
        "leal -0x418(%ebp), %ecx\n" /* line 311 | szTokenBuf */
        "movl %ecx, (%esp)\n"
        "calll SE_GetString\n"
        "testl %eax, %eax\n" /* line 362 */
        "jne .Lf32756_00032bd0\n"
        "movl loc_warnings, %eax\n" /* line 364 */
        "testl %eax, %eax\n"
        "je .Lf32756_00032cf8\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf32756_00032cf8\n"
        "movl loc_warningsAsErrors, %eax\n" /* line 366 */
        "testl %eax, %eax\n"
        "je .Lf32756_00032c7c\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf32756_00032c7c\n"
        "cmpl $1, 0x10(%ebp)\n" /* errType */
        "jne .Lf32756_00032d9c\n"
        ".Lf32756_00032c7c:\n"
        "leal -0x418(%ebp), %ecx\n" /* line 369 | szTokenBuf */
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pszMessageType */
        "movl %eax, 4(%esp)\n"
        "movl $0x216ba8, (%esp)\n" /* "^3WARNING: Could not translate part of %s: "%s"
" */
        "calll Com_Printf\n"
        ".Lf32756_00032c99:\n"
        "leal -0x418(%ebp), %edx\n" /* line 371 | szTokenBuf */
        "movl %edx, 4(%esp)\n"
        "movl $0x216bdc, (%esp)\n" /* "^1UNLOCALIZED(^7%s^1)^7" */
        "calll va\n"
        ".Lf32756_00032caf:\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 378 | errType */
        "jne .Lf32756_00032bd0\n"
        "xorl %eax, %eax\n"
        "jmp .Lf32756_0003285b\n"
        /* } scope */
        ".Lf32756_00032cc0:\n"
        "leal 3(%ebx), %eax\n" /* line 488 | bInsertEnabled */
        "movl %eax, 4(%esp)\n"
        "leal -0x818(%ebp), %edi\n" /* szInsertBuf, digit */
        "movl %edi, (%esp)\n" /* digit */
        "calll strcpy\n"
        "movb $0, (%ebx)\n" /* line 489 | bInsertEnabled */
        "subl $0x2f, %esi\n" /* line 490 | _c */
        "movl %esi, -0x830(%ebp)\n" /* _c, insertIndex */
        "movl -0x828(%ebp), %edx\n"
        "movl %edx, -0x82c(%ebp)\n"
        "movl -0x81c(%ebp), %edx\n"
        "jmp .Lf32756_0003298a\n"
        /* { scope 2 */
        ".Lf32756_00032cf8:\n"
        "leal -0x418(%ebp), %ecx\n" /* line 375 | szTokenBuf */
        "movl %ecx, 4(%esp)\n"
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "jmp .Lf32756_00032caf\n"
        /* } scope */
        ".Lf32756_00032d10:\n"
        "movl $0, -0x850(%ebp)\n" /* line 460 | i */
        "cld\n"
        "leal -0x418(%ebp), %edx\n" /* szTokenBuf */
        "movl %edx, -0x85c(%ebp)\n"
        ".Lf32756_00032d27:\n"
        "movl $2, %ebx\n" /* line 462 | bInsertEnabled */
        "movl -0x85c(%ebp), %esi\n"
        "movl $0x216c3c, %edi\n" /* digit */
        "movl %ebx, %ecx\n" /* bInsertEnabled */
        "repe cmpsb %es:(%edi), (%esi)\n" /* digit */
        "movl $0, %eax\n" /* _c */
        "je .Lf32756_00032d4c\n"
        "movzbl -1(%esi), %eax\n" /* _c */
        "movzbl -1(%edi), %ecx\n" /* digit */
        "subl %ecx, %eax\n" /* _c */
        ".Lf32756_00032d4c:\n"
        "testl %eax, %eax\n" /* _c */
        "jne .Lf32756_00032d7b\n"
        "movl -0x85c(%ebp), %edx\n"
        "movsbl 2(%edx), %eax\n" /* _c */
        /* { scope 2 */
        "cmpl $0xff, %eax\n" /* line 231 */
        "ja .Lf32756_00032d7b\n"
        "movl __DefaultRuneLocale, %ecx\n"
        "testb $4, 0x35(%ecx, %eax, 4)\n"
        "je .Lf32756_00032d7b\n"
        /* } scope */
        "movb $0x16, (%edx)\n" /* line 466 */
        "movl $1, -0x834(%ebp)\n" /* bLocSkipped */
        ".Lf32756_00032d7b:\n"
        "addl $1, -0x850(%ebp)\n" /* line 460 | i */
        "addl $1, -0x85c(%ebp)\n"
        "movl -0x854(%ebp), %eax\n"
        "cmpl %eax, -0x850(%ebp)\n" /* i */
        "jne .Lf32756_00032d27\n"
        "jmp .Lf32756_0003293b\n"
        /* { scope 2 */
        ".Lf32756_00032d9c:\n"
        "leal -0x418(%ebp), %eax\n" /* line 367 | szTokenBuf */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* pszMessageType */
        "movl %edx, 8(%esp)\n"
        "movl $0x216b80, 4(%esp)\n" /* "Could not translate part of %s: "%s"" */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf32756_00032c99\n"
    );
}

