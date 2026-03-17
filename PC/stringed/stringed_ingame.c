/* ASM dump from: stringed_ingame.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/stringed/stringed_ingame.cpp */

#include "common_types.h"
#include "imports.h"
#include <ctype.h>

extern CStringEdPackage *TheStringPackage; /* 0x0 */
static char sString[64]; /* sString */
static char sString_00482f80[64]; /* sString */
static char sTemp[64]; /* sTemp */

qboolean CStringEdPackage_ReadLine(const CStringEdPackage * _this, const char * *psParsePos, char *psDest);
double CStringEdPackage_SetupNewFileParse(const CStringEdPackage * _this, const char *psFileName);
static const char * SE_GetFoundFile(LocalizeString *strResult);
LocalizeString CStringEdPackage_ConvertCRLiterals_Read(const CStringEdPackage * _this, LocalizeString *string);
LocalizeString CStringEdPackage_InsideQuotes(const CStringEdPackage * _this, const char *psLine);
double CStringEdPackage_AddEntry(const CStringEdPackage * _this, const char *psLocalReference);
double CStringEdPackage_SetString(const CStringEdPackage * _this, const char *psLocalReference, const char *psNewString, qboolean bSentenceIsEnglish);
const char * CStringEdPackage_ParseLine(const CStringEdPackage * _this, const char *psLine, int forceEnglish);
const char * SE_Load(const char *psFileName, int forceEnglish);
const char * SE_GetString(const char *psPackageAndStringReference);
double CStringEdPackage_Clear(const CStringEdPackage * _this);
const char * SE_LoadLanguage(int forceEnglish);
double SE_Init(void);
double SE_ShutDown(void);
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE11lower_boundERS1_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_lower_bound */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE4findERS1_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_find */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE9_M_insertEPSt18_Rb_tree_node_baseSA_RKS2_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >__M_insert */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE13insert_uniqueERKS2_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_insert_unique */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE13insert_uniqueESt17_Rb_tree_iteratorIS2_ERKS2_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_insert_unique */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >__M_erase */

/* line 474 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
qboolean CStringEdPackage_ReadLine(const CStringEdPackage * _this, const char * *psParsePos, char *psDest)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 474 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* psDest */
        "movl 0xc(%ebp), %eax\n" /* line 476 | psParsePos */
        "movl (%eax), %edi\n"
        "cmpb $0, (%edi)\n"
        "jne .Lf48cbe_00048cde\n"
        "xorl %eax, %eax\n"
        "addl $0x2c, %esp\n" /* line 517 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf48cbe_00048cde:\n"
        "movl $0xa, 4(%esp)\n" /* line 478 */
        "movl %edi, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 480 */
        "je .Lf48cbe_00048e2b\n"
        /* { scope 1 */
        "movl %eax, %ebx\n" /* line 482 | iCharsToCopy */
        "subl %edi, %ebx\n" /* iCharsToCopy */
        "movl %ebx, 8(%esp)\n" /* line 484 | iCharsToCopy */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* psDest */
        "calll strncpy\n"
        "movb $0, (%esi, %ebx)\n" /* line 485 | psDest */
        "movl 0xc(%ebp), %edi\n" /* line 486 | psParsePos */
        "addl (%edi), %ebx\n" /* iCharsToCopy */
        "movl %ebx, (%edi)\n" /* iCharsToCopy */
        "movzbl (%ebx), %eax\n" /* line 487 | iCharsToCopy */
        "testb %al, %al\n"
        "jne .Lf48cbe_00048d2e\n"
        /* } scope */
        ".Lf48cbe_00048d1c:\n"
        "cmpb $0, (%esi)\n" /* line 502 | psDest */
        "jne .Lf48cbe_00048d56\n"
        /* { scope 1 */
        ".Lf48cbe_00048d21:\n"
        "movl $1, %eax\n" /* line 432 */
        /* } scope */
        ".Lf48cbe_00048d26:\n"
        "addl $0x2c, %esp\n" /* line 517 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf48cbe_00048d2e:\n"
        "movsbl %al, %eax\n" /* line 487 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00218068, (%esp)\n" /* "
" */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf48cbe_00048d1c\n"
        "addl $1, %ebx\n" /* line 489 | iCharsToCopy */
        "movl 0xc(%ebp), %eax\n" /* psParsePos */
        "movl %ebx, (%eax)\n" /* iCharsToCopy */
        "movzbl (%ebx), %eax\n" /* line 487 | iCharsToCopy */
        "testb %al, %al\n"
        "jne .Lf48cbe_00048d2e\n"
        "jmp .Lf48cbe_00048d1c\n"
        /* } scope */
        /* { scope 1 */
        ".Lf48cbe_00048d56:\n"
        "cld\n" /* line 504 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n" /* iWhiteSpaceScanPos */
        "movl %esi, %edi\n" /* psDest */
        "repne scasb %es:(%edi), %al\n" /* iWhiteSpaceScanPos */
        "notl %ecx\n"
        "movl %ecx, %eax\n" /* line 506 */
        "subl $2, %eax\n"
        "js .Lf48cbe_00048d93\n"
        "leal (%esi, %eax), %ebx\n" /* line 474 | psDest, iDoubleQuoteCount */
        "xorl %edi, %edi\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lf48cbe_00048d76:\n"
        "movsbl (%ebx), %eax\n" /* line 506 | iCharsToCopy */
        "movl %eax, (%esp)\n"
        "calll isspace\n"
        "testl %eax, %eax\n"
        "je .Lf48cbe_00048d93\n"
        "movb $0, (%ebx)\n" /* line 508 | iCharsToCopy */
        "addl $1, %edi\n"
        "subl $1, %ebx\n" /* iCharsToCopy */
        "cmpl -0x1c(%ebp), %edi\n" /* line 506 */
        "jne .Lf48cbe_00048d76\n"
        ".Lf48cbe_00048d93:\n"
        "xorl %ebx, %ebx\n" /* iCharsToCopy */
        ".Lf48cbe_00048d95:\n"
        "movl $str_00218064, 4(%esp)\n" /* line 125 */
        "movl %esi, (%esp)\n"
        "calll strstr\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 432 */
        "je .Lf48cbe_00048d21\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, %ecx\n" /* line 438 */
        "subl %esi, %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf48cbe_00048dca\n"
        /* } scope */
        /* } scope */
        "xorl %edx, %edx\n" /* line 506 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf48cbe_00048db9:\n"
        "leal 1(%ebx), %eax\n" /* line 441 | iDoubleQuoteCount */
        "cmpb $0x22, (%edx, %esi)\n"
        "cmovel %eax, %ebx\n" /* iDoubleQuoteCount */
        "addl $1, %edx\n" /* line 438 | i */
        "cmpl %ecx, %edx\n" /* i */
        "jne .Lf48cbe_00048db9\n"
        /* } scope */
        ".Lf48cbe_00048dca:\n"
        "testb $1, %bl\n" /* line 443 | iDoubleQuoteCount */
        "je .Lf48cbe_00048dd4\n"
        "leal 1(%edi), %esi\n" /* line 465 */
        "jmp .Lf48cbe_00048d95\n"
        ".Lf48cbe_00048dd4:\n"
        "movb $0, (%edi)\n" /* line 447 */
        "cmpb $0, (%esi)\n" /* line 451 */
        "je .Lf48cbe_00048d21\n"
        /* { scope 3 */
        "cld\n" /* line 453 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n" /* iWhiteSpaceScanPos */
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n" /* iWhiteSpaceScanPos */
        "notl %ecx\n"
        "movl %ecx, %eax\n" /* line 455 */
        "subl $2, %eax\n"
        "js .Lf48cbe_00048d21\n"
        "leal (%eax, %esi), %ebx\n" /* line 474 | iDoubleQuoteCount */
        "xorl %esi, %esi\n" /* psDest */
        "leal -1(%ecx), %edi\n"
        ".Lf48cbe_00048e01:\n"
        "movsbl (%ebx), %eax\n" /* line 455 | iDoubleQuoteCount */
        "movl %eax, (%esp)\n"
        "calll isspace\n"
        "testl %eax, %eax\n"
        "je .Lf48cbe_00048d21\n"
        "movb $0, (%ebx)\n" /* line 456 | iDoubleQuoteCount */
        "addl $1, %esi\n"
        "subl $1, %ebx\n" /* iDoubleQuoteCount */
        "cmpl %esi, %edi\n" /* line 455 */
        "jne .Lf48cbe_00048e01\n"
        /* } scope */
        /* } scope */
        "movl $1, %eax\n" /* line 432 */
        "jmp .Lf48cbe_00048d26\n"
        /* } scope */
        ".Lf48cbe_00048e2b:\n"
        "movl %edi, 4(%esp)\n" /* line 496 */
        "movl %esi, (%esp)\n" /* psDest */
        "calll strcpy\n"
        "movl 0xc(%ebp), %edi\n" /* line 497 | psParsePos */
        "movl (%edi), %ebx\n" /* iCharsToCopy */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* iCharsToCopy */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl 0xc(%ebp), %eax\n" /* psParsePos */
        "movl %ecx, (%eax)\n"
        "jmp .Lf48cbe_00048d1c\n"
    );
}
#else
qboolean CStringEdPackage_ReadLine(const CStringEdPackage * _this, const char * *psParsePos, char *psDest) {
    const char *p = *psParsePos;
    const char *nl;
    int len, i;

    if (!*p)
        return 0;

    nl = strchr(p, '\n');
    if (nl) {
        int charsToCopy = nl - p;
        strncpy(psDest, p, charsToCopy);
        psDest[charsToCopy] = '\0';
        *psParsePos = p + charsToCopy;
        /* skip newline-like characters */
        while (**psParsePos && strchr((const char *)str_00218068, **psParsePos)) {
            (*psParsePos)++;
        }
    } else {
        strcpy(psDest, p);
        *psParsePos = p + strlen(p);
    }

    if (!psDest[0])
        return 1;

    /* strip trailing whitespace */
    len = strlen(psDest);
    for (i = len - 2; i >= 0; i--) {
        if (!isspace((unsigned char)psDest[i]))
            break;
        psDest[i] = '\0';
    }

    /* strip // comments respecting double-quote escaping */
    {
        char *s = psDest;
        for (;;) {
            char *comment = strstr(s, (const char *)str_00218064);
            int quoteCount = 0;
            if (!comment)
                return 1;

            /* count double quotes before the comment */
            for (i = 0; i < (int)(comment - s); i++) {
                if (s[i] == '"')
                    quoteCount++;
            }

            if (quoteCount & 1) {
                /* odd number of quotes means // is inside a string */
                s = comment + 1;
                continue;
            }

            *comment = '\0';
            if (!*s)
                return 1;

            /* strip trailing whitespace after removing comment */
            len = strlen(s);
            for (i = len - 2; i >= 0; i--) {
                if (!isspace((unsigned char)s[i]))
                    break;
                s[i] = '\0';
            }
            return 1;
        }
    }
}
#endif

/* line 298 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CStringEdPackage_SetupNewFileParse(const CStringEdPackage * _this, const char *psFileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 298 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 252 | psFileName */
        "movl %eax, 4(%esp)\n"
        "movl $sString, (%esp)\n"
        "calll strcpy\n"
        "movl $0x2e, 4(%esp)\n" /* line 119 */
        "movl $sString, (%esp)\n"
        "calll strrchr\n"
        "movl %eax, %edi\n"
        "movl $0x5c, 4(%esp)\n"
        "movl $sString, (%esp)\n"
        "calll strrchr\n"
        "movl %eax, %ebx\n"
        "movl $0x2f, 4(%esp)\n"
        "movl $sString, (%esp)\n"
        "calll strrchr\n"
        "testl %edi, %edi\n" /* line 260 */
        "je .Lf48e58_00048ec7\n"
        "testl %ebx, %ebx\n"
        "je .Lf48e58_00048f60\n"
        "cmpl %ebx, %edi\n"
        "ja .Lf48e58_00048f60\n"
        /* { scope 2 */
        ".Lf48e58_00048ec7:\n"
        "movzbl sString, %eax\n" /* line 279 */
        "testb %al, %al\n"
        "je .Lf48e58_00048f59\n"
        "movl $sString, %edx\n"
        "movl $sString, %ecx\n"
        "jmp .Lf48e58_00048ef0\n"
        ".Lf48e58_00048ee2:\n"
        "cmpb $0x5c, %al\n" /* line 281 */
        "je .Lf48e58_00048ef4\n"
        "addl $1, %edx\n"
        "movzbl (%edx), %eax\n" /* line 279 */
        "testb %al, %al\n"
        "je .Lf48e58_00048f00\n"
        ".Lf48e58_00048ef0:\n"
        "cmpb $0x2f, %al\n" /* line 281 */
        "jne .Lf48e58_00048ee2\n"
        ".Lf48e58_00048ef4:\n"
        "leal 1(%edx), %ecx\n" /* line 282 */
        "movl %ecx, %edx\n"
        "movzbl (%edx), %eax\n" /* line 279 */
        "testb %al, %al\n"
        "jne .Lf48e58_00048ef0\n"
        ".Lf48e58_00048f00:\n"
        "movl %ecx, 4(%esp)\n" /* line 286 */
        "movl $sString, (%esp)\n"
        "calll strcpy\n"
        /* } scope */
        "movl $sString, 4(%esp)\n" /* line 302 */
        "leal -0x48(%ebp), %ebx\n" /* sString */
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "movl %ebx, (%esp)\n" /* line 303 */
        "calll strupr\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0xc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 306 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf48e58_00048f59:\n"
        "movl $sString, %ecx\n" /* line 279 */
        "jmp .Lf48e58_00048f00\n"
        /* } scope */
        ".Lf48e58_00048f60:\n"
        "testl %eax, %eax\n" /* line 260 */
        "je .Lf48e58_00048f6c\n"
        "cmpl %eax, %edi\n"
        "jbe .Lf48e58_00048ec7\n"
        ".Lf48e58_00048f6c:\n"
        "movb $0, (%edi)\n" /* line 261 */
        "jmp .Lf48e58_00048ec7\n"
    );
}

/* line 712 */
static __attribute__((naked))
const char * SE_GetFoundFile(LocalizeString *strResult)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 712 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* strResult */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 716 | strResult */
        "cmpb $0, (%eax)\n"
        "jne .Lf48f74_00048f8d\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 738 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf48f74_00048f8d:\n"
        "movl $0x3f, 8(%esp)\n" /* line 719 */
        "movl %eax, 4(%esp)\n"
        "movl $sTemp, (%esp)\n"
        "calll strncpy\n"
        "movb $0, sTemp+63\n" /* line 720 */
        "movl $0x3b, 4(%esp)\n" /* line 107 */
        "movl $sTemp, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 724 */
        "je .Lf48f74_00048ffd\n"
        "movb $0, (%eax)\n" /* line 726 */
        "subl $sTemp-1, %eax\n" /* line 728 — was subl $0x482fbf (= sTemp-1) */
        /* { scope 2 */
        "movl (%ebx), %edx\n" /* line 585 */
        "movl -0xc(%edx), %edx\n"
        "cmpl %edx, %eax\n" /* line 316 */
        "cmovael %edx, %eax\n"
        /* } scope */
        "movl $0, 0xc(%esp)\n" /* line 1108 */
        ".Lf48f74_00048fde:\n"
        "movl %eax, 8(%esp)\n" /* __off */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* strResult */
        "calll __ZNSs9_M_mutateEmmm\n"
        "movl $sTemp, %eax\n" /* __off */
        /* } scope */
        "addl $0x14, %esp\n" /* line 738 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf48f74_00048ffd:\n"
        "movl $0, 0xc(%esp)\n" /* line 1108 */
        "movl (%ebx), %eax\n" /* strResult, __off */
        "movl -0xc(%eax), %eax\n" /* __off */
        "jmp .Lf48f74_00048fde\n"
    );
}

/* line 367 */
__attribute__((naked))
LocalizeString CStringEdPackage_ConvertCRLiterals_Read(const CStringEdPackage * _this, LocalizeString *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 367 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n"
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "leal 0xc(%edi), %eax\n" /* line 251 */
        "movl %eax, (%esi)\n"
        "movl 0x10(%ebp), %eax\n" /* line 480 | string */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* str */
        "calll __ZNSs6assignERKSs\n"
        "jmp .Lf4900c_0004907e\n"
        ".Lf4900c_00049034:\n"
        "movl (%esi), %eax\n" /* line 269 */
        "movl -4(%eax), %edx\n" /* line 292 */
        "testl %edx, %edx\n"
        "js .Lf4900c_00049047\n"
        "movl %esi, (%esp)\n" /* line 293 */
        "calll __ZNSs12_M_leak_hardEv\n"
        "movl (%esi), %eax\n"
        ".Lf4900c_00049047:\n"
        "movb $0xa, (%eax, %ebx)\n" /* line 383 */
        "leal 1(%ebx), %ecx\n" /* line 384 | loc */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 269 */
        "movl -0xc(%eax), %edx\n" /* line 585 */
        "movl %edx, %eax\n" /* line 316 */
        "subl %ecx, %eax\n"
        "movl $1, %ebx\n"
        "cmpl $2, %eax\n"
        "cmovbl %eax, %ebx\n"
        /* } scope */
        /* { scope 2 */
        "cmpl %edx, %ecx\n" /* line 299 */
        "ja .Lf4900c_000490b1\n"
        /* } scope */
        "movl $0, 0xc(%esp)\n" /* line 1108 */
        "movl %ebx, 8(%esp)\n" /* __off */
        "movl %ecx, 4(%esp)\n" /* __pos */
        "movl %esi, (%esp)\n" /* str */
        "calll __ZNSs9_M_mutateEmmm\n"
        ".Lf4900c_0004907e:\n"
        "movl $2, 0xc(%esp)\n" /* line 1570 */
        "movl $0, 8(%esp)\n"
        "movl $str_00218080, 4(%esp)\n" /* "\n" */
        "movl %esi, (%esp)\n" /* str */
        "calll __ZNKSs4findEPKcmm\n"
        "movl %eax, %ebx\n" /* __off */
        "cmpl $-1, %eax\n" /* line 381 */
        "jne .Lf4900c_00049034\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 419 | str */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl $4\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf4900c_000490b1:\n"
        "movl $str_0021806c, (%esp)\n" /* line 300 */
        "calll __ZSt20__throw_out_of_rangePKc\n"
        "movl %eax, -0x2c(%ebp)\n"
        /* } scope */
        "movl (%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 2 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf4900c_000490d4\n"
        /* } scope */
        ".Lf4900c_000490c9:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 472 */
        ".Lf4900c_000490cc:\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        /* { scope 2 */
        ".Lf4900c_000490d4:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4900c_000490c9\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4900c_000490c9\n"
        "jmp .Lf4900c_000490cc\n"
    );
}

/* line 522 */
__attribute__((naked))
LocalizeString CStringEdPackage_InsideQuotes(const CStringEdPackage * _this, const char *psLine)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 522 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* psLine */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n" /* line 178 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, %esi\n" /* line 251 */
        "addl $0xc, %esi\n"
        "movl 8(%ebp), %edx\n" /* str */
        "movl %esi, (%edx)\n"
        "movl $0, 8(%esp)\n" /* line 906 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        ".Lf490fe_00049134:\n"
        "movzbl (%ebx), %edx\n" /* line 533 | psLine */
        "cmpb $0x20, %dl\n"
        "je .Lf490fe_00049141\n"
        "cmpb $9, %dl\n"
        "jne .Lf490fe_00049146\n"
        ".Lf490fe_00049141:\n"
        "addl $1, %ebx\n" /* line 534 | psLine */
        "jmp .Lf490fe_00049134\n"
        ".Lf490fe_00049146:\n"
        "leal 1(%ebx), %eax\n" /* line 539 | psLine */
        "cmpb $0x22, %dl\n"
        "cmovel %eax, %ebx\n" /* psLine */
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* str */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        "cmpb $0, (%ebx)\n" /* line 545 | psLine */
        "jne .Lf490fe_000491c4\n"
        ".Lf490fe_00049178:\n"
        "movl 8(%ebp), %eax\n" /* line 561 | str */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl $4\n"
        ".Lf490fe_00049185:\n"
        "cld\n" /* line 550 */
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -2(%ecx), %edx\n"
        /* { scope 1 */
        "movl -0xc(%esi), %eax\n" /* line 585 */
        "subl %edx, %eax\n" /* line 316 */
        "cmpl $1, %eax\n"
        "jbe .Lf490fe_000491a0\n"
        "movl $1, %eax\n"
        /* } scope */
        /* { scope 1 */
        ".Lf490fe_000491a0:\n"
        "cmpl -0xc(%esi), %edx\n" /* line 299 */
        "ja .Lf490fe_0004924a\n"
        /* } scope */
        "movl $0, 0xc(%esp)\n" /* line 1108 */
        "movl %eax, 8(%esp)\n" /* __off */
        "movl %edx, 4(%esp)\n" /* __pos */
        "movl 8(%ebp), %edx\n" /* str, __pos */
        "movl %edx, (%esp)\n" /* __pos */
        "calll __ZNSs9_M_mutateEmmm\n"
        ".Lf490fe_000491c4:\n"
        "movl 8(%ebp), %eax\n" /* line 269 | str */
        "movl (%eax), %esi\n"
        "movl $0xffffffff, %edx\n" /* line 549 */
        "xorl %eax, %eax\n"
        "cld\n"
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "cmpb $0x20, -2(%ecx, %esi)\n"
        "je .Lf490fe_00049185\n"
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "cmpb $9, -2(%ecx, %esi)\n"
        "je .Lf490fe_00049185\n"
        "cld\n" /* line 554 */
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "cmpb $0x22, -2(%ecx, %esi)\n"
        "jne .Lf490fe_00049178\n"
        "cld\n" /* line 555 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $2, %ecx\n"
        /* { scope 1 */
        "movl -0xc(%esi), %edx\n" /* line 585 */
        "movl %edx, %eax\n" /* line 316 */
        "subl %ecx, %eax\n"
        "movl $1, %ebx\n"
        "cmpl $2, %eax\n"
        "cmovbl %eax, %ebx\n"
        /* } scope */
        /* { scope 1 */
        "cmpl %edx, %ecx\n" /* line 299 */
        "ja .Lf490fe_0004924a\n"
        /* } scope */
        "movl $0, 0xc(%esp)\n" /* line 1108 */
        "movl %ebx, 8(%esp)\n" /* __off */
        "movl %ecx, 4(%esp)\n" /* __pos */
        "movl 8(%ebp), %edx\n" /* str, __pos */
        "movl %edx, (%esp)\n" /* __pos */
        "calll __ZNSs9_M_mutateEmmm\n"
        "jmp .Lf490fe_00049178\n"
        /* { scope 1 */
        ".Lf490fe_0004924a:\n"
        "movl $str_0021806c, (%esp)\n" /* line 300 */
        "calll __ZSt20__throw_out_of_rangePKc\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 269 | str */
        "movl (%edx), %eax\n"
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl %ebx, -0x2c(%ebp)\n" /* line 224 */
        "jne .Lf490fe_0004926d\n"
        /* } scope */
        ".Lf490fe_00049265:\n"
        "movl %esi, (%esp)\n" /* line 472 */
        "calll __Unwind_Resume\n"
        /* { scope 1 */
        ".Lf490fe_0004926d:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf490fe_00049265\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf490fe_00049265\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
    );
}

/* line 665 */
__attribute__((naked))
double CStringEdPackage_AddEntry(const CStringEdPackage * _this, const char *psLocalReference)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 665 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 8(%ebp), %edx\n" /* line 269 | this */
        "movl 0xc(%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* line 670 | psLocalReference */
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00218084, (%esp)\n" /* "%s_%s" */
        "calll va\n"
        "leal -0x21(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %esi\n" /* this */
        "movl %esi, (%esp)\n" /* this */
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl 8(%ebp), %edi\n" /* this */
        "addl $0x10, %edi\n"
        "movl %edi, -0x60(%ebp)\n"
        "movl %esi, 4(%esp)\n" /* line 498 | this */
        "movl %edi, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE4findERS1_\n"
        "movl %eax, %esi\n" /* this */
        "movl -0x28(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        /* { scope 1: __size, __osize, __r */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 178 */
        "movl %edx, -0x5c(%ebp)\n"
        "cmpl %edx, %ebx\n" /* line 224 */
        "jne .Lf4929e_00049513\n"
        /* } scope */
        ".Lf4929e_0004930b:\n"
        "movl 8(%ebp), %eax\n" /* line 593 | this */
        "addl $0x14, %eax\n"
        "cmpl %eax, %esi\n" /* line 671 | this */
        "jne .Lf4929e_00049401\n"
        /* { scope 1: __size, __osize, __r */
        "movl -0x5c(%ebp), %ecx\n" /* line 207 */
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x58(%ebp)\n"
        "movl %ecx, -0x3c(%ebp)\n" /* line 251 | SE_Entry */
        "movl 8(%ebp), %edi\n" /* line 269 | this */
        "movl 0xc(%edi), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* line 675 | psLocalReference, this */
        "movl %edx, 8(%esp)\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl $str_00218084, (%esp)\n" /* "%s_%s" */
        "calll va\n"
        "leal -0x20(%ebp), %edx\n" /* this */
        "movl %edx, 8(%esp)\n" /* this */
        "movl %eax, 4(%esp)\n"
        "leal -0x2c(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "leal -0x2c(%ebp), %edi\n" /* line 540 */
        "movl %edi, 4(%esp)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE11lower_boundERS1_\n"
        "movl %eax, -0x54(%ebp)\n"
        "cmpl %eax, %esi\n" /* line 338 */
        "je .Lf4929e_0004943f\n"
        "movl %eax, -0x4c(%ebp)\n" /* line 172 */
        "movl %eax, %edx\n"
        "addl $0x10, %edx\n"
        /* { scope 2 */
        "movl -0x2c(%ebp), %ecx\n" /* line 277 */
        "movl %ecx, -0x64(%ebp)\n"
        "movl -0xc(%ecx), %ebx\n" /* line 585 | this */
        "movl %ebx, -0x34(%ebp)\n" /* line 1915 | this, __size */
        "movl 0x10(%eax), %eax\n" /* line 269 */
        "movl -0xc(%eax), %eax\n" /* line 585 */
        "movl %eax, -0x50(%ebp)\n"
        "movl %eax, -0x30(%ebp)\n" /* line 1916 | __osize */
        "cmpl %ebx, %eax\n" /* line 189 */
        "jae .Lf4929e_00049437\n"
        "leal -0x30(%ebp), %eax\n" /* __osize */
        ".Lf4929e_000493a0:\n"
        "movl (%edx), %edx\n" /* line 269 */
        "movl (%eax), %ecx\n" /* line 253 */
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl -0x64(%ebp), %esi\n"
        "movl %edx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf4929e_000493bf\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf4929e_000493bf:\n"
        "subl -0x50(%ebp), %ebx\n" /* line 1921 | this */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n" /* this */
        "movl %ebx, -0x6c(%ebp)\n" /* this, __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 338 */
        "js .Lf4929e_0004943f\n"
        "movl -0x4c(%ebp), %edx\n"
        ".Lf4929e_000493d1:\n"
        "addl $0x14, %edx\n" /* line 340 */
        /* { scope 2 */
        "leal -0x3c(%ebp), %eax\n" /* line 480 | SE_Entry */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        /* { scope 2 */
        "cmpl %ebx, -0x5c(%ebp)\n" /* line 224 */
        "jne .Lf4929e_00049542\n"
        /* } scope */
        ".Lf4929e_000493f2:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 277 | SE_Entry */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, -0x5c(%ebp)\n" /* line 224 */
        "jne .Lf4929e_000494b4\n"
        /* } scope */
        ".Lf4929e_00049401:\n"
        "movl 8(%ebp), %edx\n" /* line 677 | this */
        "addl $4, %edx\n"
        /* { scope 1: __size, __osize, __r */
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* psLocalReference */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* psLocalReference */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 678 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __size, __osize, __r */
        /* { scope 2 */
        ".Lf4929e_00049437:\n"
        "leal -0x34(%ebp), %eax\n" /* line 189 | __size */
        "jmp .Lf4929e_000493a0\n"
        /* } scope */
        ".Lf4929e_0004943f:\n"
        "movl -0x58(%ebp), %ecx\n" /* line 251 */
        "movl %ecx, -0x38(%ebp)\n"
        "leal -0x2c(%ebp), %edi\n" /* line 85 */
        "movl %edi, 4(%esp)\n"
        "leal -0x44(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSsC1ERKSs\n"
        "leal -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsC1ERKSs\n"
        "movl %ebx, 8(%esp)\n" /* line 384 */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x60(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE13insert_uniqueESt17_Rb_tree_iteratorIS2_ERKS2_\n"
        "movl %eax, %esi\n"
        "movl -0x40(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, -0x5c(%ebp)\n" /* line 224 */
        "jne .Lf4929e_000495a0\n"
        ".Lf4929e_00049490:\n"
        "movl -0x44(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, -0x5c(%ebp)\n" /* line 224 */
        "jne .Lf4929e_00049571\n"
        ".Lf4929e_0004949f:\n"
        "movl -0x38(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, -0x5c(%ebp)\n" /* line 224 */
        "jne .Lf4929e_000494e3\n"
        ".Lf4929e_000494aa:\n"
        "movl %esi, -0x4c(%ebp)\n" /* line 227 */
        "movl %esi, %edx\n"
        "jmp .Lf4929e_000493d1\n"
        ".Lf4929e_000494b4:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_00049401\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_00049401\n"
        ".Lf4929e_000494e3:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_000494aa\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "movl %esi, -0x4c(%ebp)\n"
        "movl %esi, %edx\n"
        "jmp .Lf4929e_000493d1\n"
        /* } scope */
        /* { scope 1: __size, __osize, __r */
        ".Lf4929e_00049513:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_0004930b\n"
        "leal -0x1f(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_0004930b\n"
        /* } scope */
        /* { scope 1: __size, __osize, __r */
        /* { scope 2 */
        ".Lf4929e_00049542:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_000493f2\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_000493f2\n"
        /* } scope */
        ".Lf4929e_00049571:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_0004949f\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_0004949f\n"
        ".Lf4929e_000495a0:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_00049490\n"
        "leal -0x1d(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_00049490\n"
        ".Lf4929e_000495cf:\n"
        "movl %eax, %ebx\n"
        ".Lf4929e_000495d1:\n"
        "movl %ebx, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl -0x44(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x5c(%ebp)\n" /* line 224 */
        "jne .Lf4929e_00049733\n"
        ".Lf4929e_000495ea:\n"
        "movl -0x38(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x5c(%ebp)\n" /* line 224 */
        "jne .Lf4929e_00049704\n"
        ".Lf4929e_000495f9:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        /* { scope 2 */
        "cmpl %esi, -0x5c(%ebp)\n" /* line 224 */
        "jne .Lf4929e_000496d5\n"
        /* } scope */
        ".Lf4929e_00049608:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 277 | SE_Entry */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x5c(%ebp)\n" /* line 224 */
        "je .Lf4929e_000495d1\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_000495d1\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_000495d1\n"
        ".Lf4929e_0004963b:\n"
        "movl %eax, %ebx\n"
        "jmp .Lf4929e_00049608\n"
        ".Lf4929e_0004963f:\n"
        "movl %eax, %ebx\n"
        "jmp .Lf4929e_000495ea\n"
        "jmp .Lf4929e_000495cf\n"
        "movl %eax, %ebx\n"
        "movl -0x40(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x5c(%ebp)\n" /* line 224 */
        "jne .Lf4929e_0004975c\n"
        ".Lf4929e_00049656:\n"
        "movl -0x44(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x5c(%ebp)\n" /* line 224 */
        "je .Lf4929e_000495ea\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        ".Lf4929e_00049674:\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_000495ea\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_000495ea\n"
        "movl %eax, %ebx\n"
        "movl -0x44(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        /* { scope 2 */
        "cmpl %esi, -0x5c(%ebp)\n" /* line 224 */
        "je .Lf4929e_000495ea\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_000495ea\n"
        "leal -0x1e(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_000495ea\n"
        "jmp .Lf4929e_0004963f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4929e_000496d5:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_00049608\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_00049608\n"
        /* } scope */
        ".Lf4929e_00049704:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_000495f9\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_000495f9\n"
        ".Lf4929e_00049733:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "jmp .Lf4929e_00049674\n"
        "jmp .Lf4929e_0004963b\n"
        ".Lf4929e_00049750:\n"
        "movl %eax, %ebx\n"
        "jmp .Lf4929e_000495f9\n"
        "jmp .Lf4929e_0004963f\n"
        ".Lf4929e_0004975c:\n"
        "subl $4, %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4929e_00049656\n"
        "leal -0x1d(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4929e_00049656\n"
        "jmp .Lf4929e_0004963f\n"
        "movl %eax, %ebx\n"
        "movl -0x44(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x5c(%ebp)\n" /* line 224 */
        "je .Lf4929e_000495ea\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "jmp .Lf4929e_00049674\n"
        "jmp .Lf4929e_00049750\n"
        "jmp .Lf4929e_000495cf\n"
        "jmp .Lf4929e_0004963f\n"
    );
}

/* line 681 */
__attribute__((naked))
double CStringEdPackage_SetString(const CStringEdPackage * _this, const char *psLocalReference, const char *psNewString, qboolean bSentenceIsEnglish)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 681 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* psNewString */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 269 | this */
        "movl 0xc(%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* line 683 | psLocalReference, this */
        "movl %eax, 8(%esp)\n" /* this */
        "movl %edx, 4(%esp)\n"
        "movl $str_00218084, (%esp)\n" /* "%s_%s" */
        "calll va\n"
        "leal -0x1a(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n" /* this */
        "leal -0x20(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x10, %eax\n" /* this */
        /* { scope 2 */
        "movl %ebx, 4(%esp)\n" /* line 498 | this */
        "movl %eax, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE4findERS1_\n"
        "movl %eax, %edi\n"
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        /* { scope 2 */
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 224 */
        "jne .Lf497c6_000498ea\n"
        /* } scope */
        ".Lf497c6_0004982b:\n"
        "addl $0x14, %edi\n" /* line 686 */
        "movl %edi, -0x2c(%ebp)\n" /* Entry */
        "movl 0x14(%ebp), %edi\n" /* line 688 | bSentenceIsEnglish */
        "testl %edi, %edi\n"
        "je .Lf497c6_0004988d\n"
        "xorl %ebx, %ebx\n" /* line 257 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "movl %ebx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Entry */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        "movl 8(%ebp), %edx\n" /* line 694 | this */
        "addl $8, %edx\n"
        /* { scope 2 */
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "movl %ebx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 709 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf497c6_0004988d:\n"
        "movl $str_0021808c, 4(%esp)\n" /* line 700 */
        "movl %esi, (%esp)\n" /* psNewString */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf497c6_000498cd\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Entry */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 709 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf497c6_000498cd:\n"
        "movl 8(%ebp), %eax\n" /* line 701 | this */
        "addl $8, %eax\n"
        "movl %eax, 4(%esp)\n" /* line 480 */
        "movl -0x2c(%ebp), %eax\n" /* Entry */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 709 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf497c6_000498ea:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf497c6_0004982b\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf497c6_0004982b\n"
        /* } scope */
        ".Lf497c6_00049919:\n"
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
        "jmp .Lf497c6_00049919\n"
    );
}

/* line 566 */
__attribute__((naked))
const char * CStringEdPackage_ParseLine(const CStringEdPackage * _this, const char *psLine, int forceEnglish)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 566 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* psLine */
        "movzbl 0x10(%ebp), %esi\n" /* forceEnglish */
        /* { scope 1: versionNumber, psReference */
        "testl %ebx, %ebx\n" /* line 570 | psErrorMessage */
        "je .Lf49924_000499c0\n"
        "movl $7, 8(%esp)\n" /* line 315 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_00218094, (%esp)\n" /* "VERSION" */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf49924_000499cc\n"
        "movl $6, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_00218150, (%esp)\n" /* "CONFIG" */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf49924_0004998a\n"
        "leal 6(%ebx), %edx\n" /* line 317 */
        ".Lf49924_0004997a:\n"
        "movzbl (%edx), %eax\n" /* line 321 */
        "cmpb $9, %al\n"
        "je .Lf49924_00049985\n"
        "cmpb $0x20, %al\n"
        "jne .Lf49924_000499c0\n"
        ".Lf49924_00049985:\n"
        "addl $1, %edx\n" /* line 323 */
        "jmp .Lf49924_0004997a\n"
        ".Lf49924_0004998a:\n"
        "movl $9, 8(%esp)\n" /* line 315 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_00218134, (%esp)\n" /* "FILENOTES" */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf49924_00049a6b\n"
        "leal 9(%ebx), %edx\n" /* line 317 */
        ".Lf49924_000499ad:\n"
        "movzbl (%edx), %eax\n" /* line 321 */
        "cmpb $9, %al\n"
        "je .Lf49924_00049a5f\n"
        "cmpb $0x20, %al\n"
        "je .Lf49924_00049a5f\n"
        ".Lf49924_000499c0:\n"
        "xorl %ebx, %ebx\n" /* line 647 | psErrorMessage */
        /* } scope */
        ".Lf49924_000499c2:\n"
        "movl %ebx, %eax\n" /* line 652 | psErrorMessage */
        "leal -0xc(%ebp), %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: versionNumber, psReference */
        ".Lf49924_000499cc:\n"
        "leal 7(%ebx), %edx\n" /* line 317 */
        ".Lf49924_000499cf:\n"
        "movzbl (%edx), %eax\n" /* line 321 */
        "cmpb $9, %al\n"
        "je .Lf49924_000499da\n"
        "cmpb $0x20, %al\n"
        "jne .Lf49924_000499df\n"
        ".Lf49924_000499da:\n"
        "addl $1, %edx\n" /* line 323 */
        "jmp .Lf49924_000499cf\n"
        /* { scope 2: sThisLanguage, sentence */
        ".Lf49924_000499df:\n"
        "leal -0x24(%ebp), %eax\n" /* line 576 | versionNumber */
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CStringEdPackage_InsideQuotes\n"
        "subl $4, %esp\n"
        "movl -0x24(%ebp), %eax\n" /* line 577 | versionNumber, iVersionNumber */
        "movl %eax, (%esp)\n" /* iVersionNumber */
        "calll atoi\n"
        "cmpl $1, %eax\n" /* line 579 */
        "je .Lf49924_00049a67\n"
        "movl $1, 8(%esp)\n" /* line 580 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021809c, (%esp)\n" /* "Unexpected version number %d, expecting %d!
" */
        "calll va\n"
        "movl %eax, %ebx\n" /* psErrorMessage */
        ".Lf49924_00049a22:\n"
        "movl -0x24(%ebp), %eax\n" /* line 277 | versionNumber */
        "leal -0xc(%eax), %edi\n"
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 224 */
        "je .Lf49924_000499c2\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf49924_000499c2\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf49924_000499c2\n"
        /* } scope */
        ".Lf49924_00049a5f:\n"
        "addl $1, %edx\n" /* line 323 */
        "jmp .Lf49924_000499ad\n"
        /* { scope 2: sThisLanguage, sentence */
        ".Lf49924_00049a67:\n"
        "xorl %ebx, %ebx\n" /* line 472 */
        "jmp .Lf49924_00049a22\n"
        /* } scope */
        ".Lf49924_00049a6b:\n"
        "movl $5, 8(%esp)\n" /* line 315 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_00218140, (%esp)\n" /* "NOTES" */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf49924_00049a9e\n"
        "leal 5(%ebx), %edx\n" /* line 317 */
        ".Lf49924_00049a8a:\n"
        "movzbl (%edx), %eax\n" /* line 321 */
        "cmpb $9, %al\n"
        "je .Lf49924_00049a99\n"
        "cmpb $0x20, %al\n"
        "jne .Lf49924_000499c0\n"
        ".Lf49924_00049a99:\n"
        "addl $1, %edx\n" /* line 323 */
        "jmp .Lf49924_00049a8a\n"
        ".Lf49924_00049a9e:\n"
        "movl $5, 8(%esp)\n" /* line 315 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_00218148, (%esp)\n" /* "FLAGS" */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf49924_00049ad1\n"
        "leal 5(%ebx), %edx\n" /* line 317 */
        ".Lf49924_00049abd:\n"
        "movzbl (%edx), %eax\n" /* line 321 */
        "cmpb $9, %al\n"
        "je .Lf49924_00049acc\n"
        "cmpb $0x20, %al\n"
        "jne .Lf49924_000499c0\n"
        ".Lf49924_00049acc:\n"
        "addl $1, %edx\n" /* line 323 */
        "jmp .Lf49924_00049abd\n"
        ".Lf49924_00049ad1:\n"
        "movl $9, 8(%esp)\n" /* line 315 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_00218158, (%esp)\n" /* "REFERENCE" */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf49924_00049d35\n"
        "movl $9, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_00218164, (%esp)\n" /* "ENDMARKER" */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf49924_00049db6\n"
        "movl $5, 8(%esp)\n" /* line 600 */
        "movl %ebx, 4(%esp)\n" /* psErrorMessage */
        "movl $str_00218170, (%esp)\n" /* "LANG_" */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf49924_00049de5\n"
        /* { scope 2: sThisLanguage, sentence */
        "movl 8(%ebp), %eax\n" /* line 269 | this */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x440(%ebp)\n" /* psReference */
        "cmpb $0, (%eax)\n" /* line 606 */
        "je .Lf49924_00049ddb\n"
        /* { scope 3: args */
        "leal 5(%ebx), %edx\n" /* line 608 | psErrorMessage */
        "movl %edx, -0x43c(%ebp)\n"
        "cmpb $0, 5(%ebx)\n" /* line 614 | psErrorMessage */
        "jne .Lf49924_00049cb9\n"
        ".Lf49924_00049b59:\n"
        "xorl %ebx, %ebx\n" /* psErrorMessage */
        ".Lf49924_00049b5b:\n"
        "movl $0x400, 8(%esp)\n" /* line 617 */
        "movl $__ZZN16CStringEdPackage9ParseLineEPKchE5C.208, 4(%esp)\n"
        "leal -0x42d(%ebp), %eax\n" /* sThisLanguage */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0x3ff, %eax\n" /* line 620 */
        "cmpl $0x400, %ebx\n" /* psErrorMessage */
        "cmovbl %ebx, %eax\n" /* psErrorMessage */
        "movl %eax, 8(%esp)\n" /* line 622 */
        "movl -0x43c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x42d(%ebp), %eax\n" /* sThisLanguage */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "leal -0x20(%ebp), %ebx\n" /* line 625 | psErrorMessage */
        "cld\n" /* line 624 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x42d(%ebp), %edi\n" /* sThisLanguage */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0x43c(%ebp), %edx\n"
        "leal -1(%ecx, %edx), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* psErrorMessage */
        "calll CStringEdPackage_InsideQuotes\n"
        "subl $4, %esp\n"
        "leal -0x24(%ebp), %eax\n" /* line 625 | versionNumber */
        "movl %ebx, 8(%esp)\n" /* psErrorMessage */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CStringEdPackage_ConvertCRLiterals_Read\n"
        "subl $4, %esp\n"
        "movl -0x20(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %ebx\n" /* line 224 */
        "jne .Lf49924_00049dfc\n"
        ".Lf49924_00049c05:\n"
        "movl -0x24(%ebp), %ebx\n" /* line 1509 | versionNumber, psErrorMessage */
        /* { scope 4 */
        "movl $0, -0x2d(%ebp)\n" /* line 340 | args */
        "movl $0, -0x29(%ebp)\n"
        "movb $0, -0x25(%ebp)\n"
        "movl $str_00216c3c, 4(%esp)\n" /* line 342 */
        "movl %ebx, (%esp)\n"
        "calll strstr\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 343 */
        "je .Lf49924_00049d2e\n"
        "movsbl 2(%eax), %edx\n" /* line 346 */
        "leal -0x30(%edx), %eax\n"
        "cmpl $9, %eax\n"
        "jbe .Lf49924_00049d02\n"
        /* } scope */
        ".Lf49924_00049c44:\n"
        "movl %ebx, 4(%esp)\n" /* line 628 | psErrorMessage */
        "movl $str_002180f4, (%esp)\n" /* "Illegal string format "%s"
" */
        "calll va\n"
        "movl %eax, %ebx\n" /* psErrorMessage */
        ".Lf49924_00049c56:\n"
        "movl $str_0021699c, 4(%esp)\n" /* line 632 */
        "leal -0x42d(%ebp), %eax\n" /* sThisLanguage */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "sete %al\n"
        "movzbl %al, %edx\n" /* bSentenceIsEnglish */
        "testl %ebx, %ebx\n" /* line 634 | psErrorMessage */
        "je .Lf49924_00049ef4\n"
        ".Lf49924_00049c7c:\n"
        "movl -0x24(%ebp), %eax\n" /* line 277 | versionNumber */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "je .Lf49924_000499c2\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf49924_000499c2\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf49924_000499c2\n"
        ".Lf49924_00049cb9:\n"
        "movl -0x43c(%ebp), %edx\n" /* line 614 */
        "movzbl (%edx), %eax\n"
        "cmpb $0x20, %al\n"
        "je .Lf49924_00049b59\n"
        "cmpb $9, %al\n"
        "jne .Lf49924_00049cdb\n"
        "jmp .Lf49924_00049b59\n"
        ".Lf49924_00049cd3:\n"
        "cmpb $0x20, %al\n"
        "je .Lf49924_00049ce5\n"
        "cmpb $9, %al\n"
        "je .Lf49924_00049ce5\n"
        ".Lf49924_00049cdb:\n"
        "addl $1, %edx\n" /* line 615 */
        "movzbl (%edx), %eax\n" /* line 614 */
        "testb %al, %al\n"
        "jne .Lf49924_00049cd3\n"
        ".Lf49924_00049ce5:\n"
        "movl %edx, %ebx\n" /* psErrorMessage */
        "subl -0x43c(%ebp), %ebx\n" /* psErrorMessage */
        "jmp .Lf49924_00049b5b\n"
        /* { scope 4 */
        ".Lf49924_00049cf2:\n"
        "movsbl 2(%ecx), %edx\n" /* line 346 */
        "leal -0x30(%edx), %eax\n"
        "cmpl $9, %eax\n"
        "ja .Lf49924_00049c44\n"
        ".Lf49924_00049d02:\n"
        "leal -0x31(%edx), %eax\n" /* line 351 */
        "cmpb $0, -0x2d(%ebp, %eax)\n" /* line 352 */
        "jne .Lf49924_00049c44\n"
        "movb $1, -0x2d(%ebp, %eax)\n" /* line 355 */
        "leal 3(%ecx), %eax\n" /* line 356 */
        "movl $str_00216c3c, 4(%esp)\n" /* line 357 */
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 343 */
        "jne .Lf49924_00049cf2\n"
        /* } scope */
        ".Lf49924_00049d2e:\n"
        "xorl %ebx, %ebx\n" /* line 627 | psErrorMessage */
        "jmp .Lf49924_00049c56\n"
        /* } scope */
        /* } scope */
        ".Lf49924_00049d35:\n"
        "leal 9(%ebx), %edx\n" /* line 317 */
        ".Lf49924_00049d38:\n"
        "movzbl (%edx), %eax\n" /* line 321 */
        "cmpb $9, %al\n"
        "je .Lf49924_00049d43\n"
        "cmpb $0x20, %al\n"
        "jne .Lf49924_00049d48\n"
        ".Lf49924_00049d43:\n"
        "addl $1, %edx\n" /* line 323 */
        "jmp .Lf49924_00049d38\n"
        /* { scope 2: sThisLanguage, sentence */
        ".Lf49924_00049d48:\n"
        "leal -0x24(%ebp), %eax\n" /* line 590 | versionNumber */
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CStringEdPackage_InsideQuotes\n"
        "subl $4, %esp\n"
        "movl -0x24(%ebp), %eax\n" /* line 592 | versionNumber */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CStringEdPackage_AddEntry\n"
        "movl -0x24(%ebp), %eax\n" /* line 277 | versionNumber */
        "leal -0xc(%eax), %ebx\n"
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 224 */
        "je .Lf49924_000499c0\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf49924_000499c0\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf49924_000499c2\n"
        /* } scope */
        ".Lf49924_00049db6:\n"
        "leal 9(%ebx), %eax\n" /* line 317 */
        ".Lf49924_00049db9:\n"
        "movzbl (%eax), %edx\n" /* line 321 */
        "cmpb $9, %dl\n"
        "je .Lf49924_00049dc6\n"
        "cmpb $0x20, %dl\n"
        "jne .Lf49924_00049dcb\n"
        ".Lf49924_00049dc6:\n"
        "addl $1, %eax\n" /* line 323 */
        "jmp .Lf49924_00049db9\n"
        ".Lf49924_00049dcb:\n"
        "movl 8(%ebp), %edx\n" /* line 598 | this */
        "movl $1, (%edx)\n"
        "xorl %ebx, %ebx\n" /* psErrorMessage */
        "jmp .Lf49924_000499c2\n"
        /* { scope 2: sThisLanguage, sentence */
        ".Lf49924_00049ddb:\n"
        "movl $str_002180cc, %ebx\n" /* line 606 | psErrorMessage */
        "jmp .Lf49924_000499c2\n"
        /* } scope */
        ".Lf49924_00049de5:\n"
        "movl %ebx, 4(%esp)\n" /* line 647 | psErrorMessage */
        "movl $str_00218110, (%esp)\n" /* "Unknown keyword at linestart: "%s"
" */
        "calll va\n"
        "movl %eax, %ebx\n" /* psErrorMessage */
        "jmp .Lf49924_000499c2\n"
        /* { scope 2: sThisLanguage, sentence */
        /* { scope 3: args */
        ".Lf49924_00049dfc:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf49924_00049c05\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf49924_00049c05\n"
        "movl %eax, %ebx\n"
        "movl -0x20(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 224 */
        "jne .Lf49924_00049e4b\n"
        ".Lf49924_00049e3b:\n"
        "movl %ebx, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        ".Lf49924_00049e43:\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        ".Lf49924_00049e4b:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf49924_00049e3b\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf49924_00049e3b\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* } scope */
        /* { scope 2: sThisLanguage, sentence */
        "movl -0x24(%ebp), %eax\n" /* line 277 | versionNumber */
        "leal -0xc(%eax), %esi\n"
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 224 */
        "je .Lf49924_00049e3b\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf49924_00049e3b\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf49924_00049e3b\n"
        "jmp .Lf49924_00049e43\n"
        "jmp .Lf49924_00049e43\n"
        "jmp .Lf49924_00049e43\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* { scope 2: sThisLanguage, sentence */
        "movl -0x24(%ebp), %eax\n" /* line 277 | versionNumber */
        "leal -0xc(%eax), %esi\n"
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 224 */
        "je .Lf49924_00049e3b\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf49924_00049e3b\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf49924_00049e3b\n"
        /* } scope */
        /* { scope 2: sThisLanguage, sentence */
        /* { scope 3: args */
        ".Lf49924_00049ef4:\n"
        "testb %al, %al\n" /* line 636 */
        "jne .Lf49924_00049f02\n"
        "movl %esi, %eax\n" /* forceEnglish */
        "testb %al, %al\n"
        "jne .Lf49924_00049c7c\n"
        ".Lf49924_00049f02:\n"
        "movl %edx, 0xc(%esp)\n" /* line 637 */
        "movl -0x24(%ebp), %eax\n" /* versionNumber */
        "movl %eax, 8(%esp)\n"
        "movl -0x440(%ebp), %edx\n" /* psReference */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CStringEdPackage_SetString\n"
        "jmp .Lf49924_00049c7c\n"
        "movl %eax, %ebx\n" /* psErrorMessage */
        "jmp .Lf49924_00049e3b\n"
        "jmp .Lf49924_00049e43\n"
        "movl %eax, %ebx\n" /* psErrorMessage */
        "movl -0x24(%ebp), %eax\n" /* line 277 | versionNumber */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "je .Lf49924_00049e3b\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf49924_00049e3b\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf49924_00049e3b\n"
        "jmp .Lf49924_00049e43\n"
    );
}

/* line 748 */
__attribute__((naked))
const char * SE_Load(const char *psFileName, int forceEnglish)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 748 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x403c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* psFileName */
        "movzbl 0xc(%ebp), %eax\n" /* forceEnglish */
        "movb %al, -0x4029(%ebp)\n" /* forceEnglish */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 752 | psErrorMessage */
        "calll SE_LoadFileData\n"
        "movl %eax, %esi\n" /* psLoadedData */
        "testl %eax, %eax\n" /* line 754 */
        "je .Lf49f78_0004a068\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 759 | psParsePos */
        "movl %ebx, 4(%esp)\n" /* line 761 | psErrorMessage */
        "movl TheStringPackage, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CStringEdPackage_SetupNewFileParse\n"
        "leal -0x401c(%ebp), %edi\n" /* sLineBuffer */
        ".Lf49f78_00049fbd:\n"
        "movl %edi, 8(%esp)\n" /* line 763 */
        "leal -0x1c(%ebp), %eax\n" /* psParsePos */
        "movl %eax, 4(%esp)\n"
        "movl TheStringPackage, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CStringEdPackage_ReadLine\n"
        "testl %eax, %eax\n"
        "je .Lf49f78_0004a01d\n"
        "cmpb $0, -0x401c(%ebp)\n" /* line 765 | sLineBuffer */
        "je .Lf49f78_00049fbd\n"
        "movzbl -0x4029(%ebp), %eax\n" /* line 766 | forceEnglish */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl TheStringPackage, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CStringEdPackage_ParseLine\n"
        "movl %eax, %ebx\n" /* psErrorMessage */
        "testl %eax, %eax\n" /* line 763 */
        "je .Lf49f78_00049fbd\n"
        "movl %esi, (%esp)\n" /* line 769 | psLoadedData */
        "calll SE_FreeFileDataAfterLoad\n"
        "testl %ebx, %ebx\n" /* line 771 | psErrorMessage */
        "je .Lf49f78_0004a02b\n"
        /* } scope */
        ".Lf49f78_0004a010:\n"
        "movl %ebx, %eax\n" /* line 775 | psErrorMessage */
        "addl $0x403c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf49f78_0004a01d:\n"
        "xorl %ebx, %ebx\n" /* line 763 | psErrorMessage */
        "movl %esi, (%esp)\n" /* line 769 | psLoadedData */
        "calll SE_FreeFileDataAfterLoad\n"
        "testl %ebx, %ebx\n" /* line 771 | psErrorMessage */
        "jne .Lf49f78_0004a010\n"
        ".Lf49f78_0004a02b:\n"
        "movl TheStringPackage, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf49f78_0004a045\n"
        "xorl %ebx, %ebx\n" /* psErrorMessage */
        /* } scope */
        "movl %ebx, %eax\n" /* line 775 | psErrorMessage */
        "addl $0x403c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf49f78_0004a045:\n"
        "movl $str_00218164, 4(%esp)\n" /* line 772 */
        "movl $str_00218190, (%esp)\n" /* "Truncated file, failed to find "%s" at file end!" */
        "calll va\n"
        "movl %eax, %ebx\n" /* psErrorMessage */
        /* } scope */
        "movl %ebx, %eax\n" /* line 775 | psErrorMessage */
        "addl $0x403c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf49f78_0004a068:\n"
        "movl %ebx, 4(%esp)\n" /* line 755 | psErrorMessage */
        "movl $str_00218178, (%esp)\n" /* "Unable to load "%s"!" */
        "calll va\n"
        "movl %eax, %ebx\n" /* psErrorMessage */
        /* } scope */
        "movl %ebx, %eax\n" /* line 775 | psErrorMessage */
        "addl $0x403c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 778 */
__attribute__((naked))
const char * SE_GetString(const char *psPackageAndStringReference)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 778 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "leal -0xa(%ebp), %eax\n" /* line 780 | this */
        "movl %eax, 8(%esp)\n" /* this */
        "movl 8(%ebp), %eax\n" /* psPackageAndStringReference, this */
        "movl %eax, 4(%esp)\n" /* this */
        "leal -0x10(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl TheStringPackage, %eax\n" /* this */
        "addl $0x10, %eax\n" /* this */
        /* { scope 1 */
        "movl %ebx, 4(%esp)\n" /* line 498 | this */
        "movl %eax, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE4findERS1_\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl -0x10(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        /* { scope 1 */
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 224 */
        "jne .Lf4a088_0004a0ec\n"
        /* } scope */
        ".Lf4a088_0004a0cd:\n"
        "movl TheStringPackage, %eax\n" /* line 593 */
        "addl $0x14, %eax\n"
        "cmpl %esi, %eax\n" /* line 781 */
        "je .Lf4a088_0004a0e3\n"
        "movl 0x14(%esi), %eax\n" /* line 269 */
        "addl $0x20, %esp\n" /* line 790 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf4a088_0004a0e3:\n"
        "xorl %eax, %eax\n" /* line 781 */
        "addl $0x20, %esp\n" /* line 790 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4a088_0004a0ec:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4a088_0004a0cd\n"
        "leal -9(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4a088_0004a0cd\n"
        /* } scope */
        ".Lf4a088_0004a114:\n"
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
        "jmp .Lf4a088_0004a114\n"
    );
}

/* line 206 */
__attribute__((naked))
double CStringEdPackage_Clear(const CStringEdPackage * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 206 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "leal 0x10(%esi), %ebx\n" /* line 465 | this */
        "movl 8(%ebx), %eax\n" /* line 666 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E\n"
        "leal 0x14(%esi), %eax\n" /* line 667 | this */
        "movl %eax, 0xc(%ebx)\n"
        "movl $0, 8(%ebx)\n" /* line 668 */
        "movl %eax, 0x10(%ebx)\n" /* line 669 */
        "movl $0, 0x14(%ebx)\n" /* line 670 */
        "movl $0, (%esi)\n" /* line 210 | this */
        "movl $0, 8(%esp)\n" /* line 906 */
        "movl $str_002157b8, 4(%esp)\n"
        "leal 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        "movl $0, 8(%esp)\n"
        "movl $str_002157b8, 4(%esp)\n"
        "addl $8, %esi\n" /* this */
        "movl %esi, (%esp)\n" /* this */
        "calll __ZNSs6assignEPKcm\n"
        "addl $0x10, %esp\n" /* line 216 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 829 */
__attribute__((naked))
const char * SE_LoadLanguage(int forceEnglish)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 829 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movzbl 8(%ebp), %ebx\n" /* forceEnglish */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n" /* line 178 */
        "movl %eax, -0x2c(%ebp)\n"
        "addl $0xc, %eax\n" /* line 251 */
        "movl %eax, -0x20(%ebp)\n" /* strResults */
        "movl TheStringPackage, %eax\n" /* line 796 */
        "movl %eax, (%esp)\n"
        "calll CStringEdPackage_Clear\n"
        "leal -0x20(%ebp), %edi\n" /* line 836 | strResults */
        "movl %edi, 4(%esp)\n"
        "movl $str_002181c4, (%esp)\n" /* "localizedstrings" */
        "calll SE_BuildFileList\n"
        "xorl %esi, %esi\n" /* psErrorMessage */
        "movzbl %bl, %ebx\n" /* forceEnglish */
        "jmp .Lf4a198_0004a1ec\n"
        ".Lf4a198_0004a1da:\n"
        "testl %esi, %esi\n" /* line 838 | psErrorMessage */
        "jne .Lf4a198_0004a1f8\n"
        "movl %ebx, 4(%esp)\n" /* line 839 | forceEnglish */
        "movl %eax, (%esp)\n"
        "calll SE_Load\n"
        "movl %eax, %esi\n" /* psErrorMessage */
        ".Lf4a198_0004a1ec:\n"
        "movl %edi, (%esp)\n" /* line 838 */
        "calll SE_GetFoundFile\n"
        "testl %eax, %eax\n"
        "jne .Lf4a198_0004a1da\n"
        ".Lf4a198_0004a1f8:\n"
        "movl -0x20(%ebp), %eax\n" /* line 277 | strResults */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, -0x2c(%ebp)\n" /* line 224 */
        "jne .Lf4a198_0004a20d\n"
        /* } scope */
        ".Lf4a198_0004a203:\n"
        "movl %esi, %eax\n" /* line 842 | psErrorMessage */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4a198_0004a20d:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4a198_0004a203\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4a198_0004a203\n"
        "movl %eax, %ebx\n"
        "movl -0x20(%ebp), %eax\n" /* line 277 | strResults */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x2c(%ebp)\n" /* line 224 */
        "jne .Lf4a198_0004a24e\n"
        ".Lf4a198_0004a242:\n"
        "movl %ebx, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "jmp .Lf4a198_0004a242\n"
        ".Lf4a198_0004a24e:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4a198_0004a242\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4a198_0004a242\n"
    );
}

/* line 805 */
__attribute__((naked))
double SE_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 805 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x28, (%esp)\n" /* line 165 */
        "calll Z_MallocInternal\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 207 */
        "addl $0xc, %edx\n"
        /* { scope 1 */
        "movl %edx, 4(%eax)\n" /* line 251 */
        /* } scope */
        "movl %edx, 8(%eax)\n"
        "movl %edx, 0xc(%eax)\n"
        "leal 0x10(%eax), %edx\n" /* line 554 | this */
        /* { scope 1 */
        "movl $0, 0x14(%edx)\n" /* line 404 */
        "movl $0, 4(%edx)\n" /* line 406 */
        "movl $0, 8(%edx)\n" /* line 407 */
        "leal 0x14(%eax), %ecx\n" /* line 408 */
        "movl %ecx, 0xc(%edx)\n"
        "movl %ecx, 0x10(%edx)\n" /* line 409 */
        /* } scope */
        "movl %eax, TheStringPackage\n" /* line 808 */
        "movl %eax, (%esp)\n" /* line 809 */
        "calll CStringEdPackage_Clear\n"
        "leave\n" /* line 810 */
        "retl\n"
    );
}

/* line 813 */
__attribute__((naked))
double SE_ShutDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 813 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl TheStringPackage, %eax\n" /* line 815 */
        "testl %eax, %eax\n"
        "je .Lf4a2ca_0004a336\n"
        "movl %eax, (%esp)\n" /* line 818 */
        "calll CStringEdPackage_Clear\n"
        "movl TheStringPackage, %ebx\n" /* line 819 | this */
        "testl %ebx, %ebx\n" /* this */
        "je .Lf4a2ca_0004a32c\n"
        /* { scope 1: this */
        "leal 0x10(%ebx), %edx\n" /* line 154 | this */
        /* { scope 2 */
        "movl 8(%edx), %eax\n" /* line 462 */
        "movl %eax, 4(%esp)\n" /* line 570 */
        "movl %edx, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E\n"
        /* } scope */
        "movl 0xc(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 2 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %esi\n" /* line 224 */
        "jne .Lf4a2ca_0004a33e\n"
        /* } scope */
        ".Lf4a2ca_0004a310:\n"
        "movl 8(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 2 */
        "cmpl %esi, %edi\n" /* line 224 */
        "jne .Lf4a2ca_0004a38e\n"
        /* } scope */
        ".Lf4a2ca_0004a31a:\n"
        "movl 4(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 2 */
        "cmpl %esi, %edi\n" /* line 224 */
        "jne .Lf4a2ca_0004a366\n"
        /* } scope */
        /* } scope */
        ".Lf4a2ca_0004a324:\n"
        "movl %ebx, (%esp)\n" /* line 170 */
        "calll Z_FreeInternal\n"
        ".Lf4a2ca_0004a32c:\n"
        "movl $0, TheStringPackage\n" /* line 821 */
        ".Lf4a2ca_0004a336:\n"
        "addl $0x3c, %esp\n" /* line 822 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: this */
        /* { scope 2 */
        ".Lf4a2ca_0004a33e:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4a2ca_0004a310\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4a2ca_0004a310\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4a2ca_0004a366:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4a2ca_0004a324\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4a2ca_0004a324\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4a2ca_0004a38e:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4a2ca_0004a31a\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4a2ca_0004a31a\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl 0xc(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %edx\n" /* line 277 */
        "movl %edx, -0x2c(%ebp)\n"
        /* { scope 2 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %edx\n" /* line 224 */
        "jne .Lf4a2ca_0004a465\n"
        /* } scope */
        ".Lf4a2ca_0004a3d6:\n"
        "movl 8(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %edx\n" /* line 277 */
        "movl %edx, -0x30(%ebp)\n" /* this */
        /* { scope 2 */
        "cmpl %edi, %edx\n" /* line 224 */
        "jne .Lf4a2ca_0004a427\n"
        /* } scope */
        ".Lf4a2ca_0004a3e3:\n"
        "movl 4(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 2 */
        "cmpl %edi, %ebx\n" /* line 224 */
        "jne .Lf4a2ca_0004a3ff\n"
        /* } scope */
        ".Lf4a2ca_0004a3ed:\n"
        "movl %esi, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        "movl %eax, %esi\n"
        ".Lf4a2ca_0004a3f7:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n"
        "jmp .Lf4a2ca_0004a3e3\n"
        /* { scope 2 */
        ".Lf4a2ca_0004a3ff:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4a2ca_0004a3ed\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4a2ca_0004a3ed\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4a2ca_0004a427:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4a2ca_0004a3f7\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n"
        "jmp .Lf4a2ca_0004a3e3\n"
        "movl %eax, %esi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n"
        "jmp .Lf4a2ca_0004a3d6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4a2ca_0004a465:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf4a2ca_0004a3d6\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf4a2ca_0004a3d6\n"
        "movl %eax, %esi\n"
        "jmp .Lf4a2ca_0004a3ed\n"
    );
}

/* line 1144 */
__attribute__((naked))
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE11lower_boundERS1_(void) /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_lower_bound */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1144 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        /* { scope 1: __size, __osize, __r */
        "movl 8(%eax), %edx\n" /* line 462 */
        "movl %edx, -0x2c(%ebp)\n" /* __x */
        "addl $4, %eax\n" /* line 473 */
        "movl %eax, -0x28(%ebp)\n" /* __y */
        "testl %edx, %edx\n" /* line 1149 */
        "je .Lf2be942_002bea10\n"
        "movl 0xc(%ebp), %ecx\n" /* __k */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "cld\n"
        "movl -0x2c(%ebp), %edx\n" /* __x */
        "movl -0x2c(%ebp), %esi\n" /* __x */
        "jmp .Lf2be942_002be9b7\n"
        /* { scope 2 */
        ".Lf2be942_002be973:\n"
        "leal -0x18(%ebp), %eax\n" /* line 189 | __osize */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cmpl %ecx, %ecx\n"
        "movl %edx, %esi\n"
        "movl -0x30(%ebp), %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2be942_002be994\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2be942_002be994:\n"
        "subl -0x24(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x34(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1150 */
        "js .Lf2be942_002bea03\n"
        ".Lf2be942_002be9a3:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 489 | __x */
        "movl 8(%ecx), %eax\n"
        "movl %ecx, -0x28(%ebp)\n" /* __y */
        "testl %eax, %eax\n" /* line 1149 */
        "je .Lf2be942_002bea0d\n"
        ".Lf2be942_002be9b0:\n"
        "movl %eax, -0x2c(%ebp)\n" /* __x */
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        ".Lf2be942_002be9b7:\n"
        "addl $0x10, %edx\n" /* line 551 */
        /* { scope 2 */
        "movl 0x10(%esi), %eax\n" /* line 585 */
        "movl -0xc(%eax), %ebx\n"
        "movl %ebx, -0x14(%ebp)\n" /* line 1915 | __size */
        "movl -0x30(%ebp), %eax\n" /* line 585 */
        "movl -0xc(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, -0x18(%ebp)\n" /* line 1916 | __osize */
        "cmpl %eax, %ebx\n" /* line 189 */
        "ja .Lf2be942_002be973\n"
        "leal -0x14(%ebp), %eax\n" /* __size */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cmpl %ecx, %ecx\n"
        "movl %edx, %esi\n"
        "movl -0x30(%ebp), %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2be942_002be9f4\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2be942_002be9f4:\n"
        "subl -0x24(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x34(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1150 */
        "jns .Lf2be942_002be9a3\n"
        ".Lf2be942_002bea03:\n"
        "movl -0x2c(%ebp), %esi\n" /* line 497 | __x */
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n" /* line 1149 */
        "jne .Lf2be942_002be9b0\n"
        ".Lf2be942_002bea0d:\n"
        "movl -0x28(%ebp), %eax\n" /* __y */
        /* } scope */
        ".Lf2be942_002bea10:\n"
        "addl $0x3c, %esp\n" /* line 1155 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1090 */
__attribute__((naked))
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE4findERS1_(void) /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_find */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1090 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        /* { scope 1: __size, __osize, __r, __r */
        "movl 8(%eax), %edx\n" /* line 462 */
        "movl %edx, -0x38(%ebp)\n" /* __x */
        "addl $4, %eax\n" /* line 473 */
        "movl %eax, -0x34(%ebp)\n" /* __y */
        "testl %edx, %edx\n" /* line 1095 */
        "je .Lf2bea18_002beba3\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 0xc(%ebp), %ecx\n" /* __k */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movl -0x38(%ebp), %edx\n" /* __x */
        "movl -0x38(%ebp), %esi\n" /* __x */
        "movl %ecx, %edi\n"
        "jmp .Lf2bea18_002bea95\n"
        /* { scope 2 */
        ".Lf2bea18_002bea4d:\n"
        "leal -0x14(%ebp), %eax\n" /* line 189 | __osize */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl %edx, %esi\n"
        "movl -0x3c(%ebp), %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bea18_002bea6f\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bea18_002bea6f:\n"
        "subl -0x30(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x48(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1096 */
        "js .Lf2bea18_002beadf\n"
        ".Lf2bea18_002bea7e:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 489 | __x */
        "movl 8(%ecx), %eax\n"
        "movl %ecx, -0x24(%ebp)\n"
        "testl %eax, %eax\n" /* line 1095 */
        "je .Lf2bea18_002beae9\n"
        ".Lf2bea18_002bea8b:\n"
        "movl %eax, -0x38(%ebp)\n" /* __x */
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        "movl -0x3c(%ebp), %edi\n"
        ".Lf2bea18_002bea95:\n"
        "addl $0x10, %edx\n" /* line 551 */
        /* { scope 2 */
        "movl 0x10(%esi), %eax\n" /* line 585 */
        "movl -0xc(%eax), %ebx\n"
        "movl %ebx, -0x18(%ebp)\n" /* line 1915 | __size */
        "movl -0xc(%edi), %edi\n" /* line 585 */
        "movl %edi, -0x30(%ebp)\n"
        "movl %edi, -0x14(%ebp)\n" /* line 1916 | __osize */
        "cmpl %edi, %ebx\n" /* line 189 */
        "ja .Lf2bea18_002bea4d\n"
        "leal -0x18(%ebp), %eax\n" /* __size */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl %edx, %esi\n"
        "movl -0x3c(%ebp), %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bea18_002bead0\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bea18_002bead0:\n"
        "subl -0x30(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x48(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1096 */
        "jns .Lf2bea18_002bea7e\n"
        ".Lf2bea18_002beadf:\n"
        "movl -0x38(%ebp), %esi\n" /* line 497 | __x */
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n" /* line 1095 */
        "jne .Lf2bea18_002bea8b\n"
        ".Lf2bea18_002beae9:\n"
        "movl -0x24(%ebp), %eax\n"
        "movl -0x34(%ebp), %edx\n" /* __y */
        ".Lf2bea18_002beaef:\n"
        "movl %eax, -0x28(%ebp)\n" /* line 168 */
        "cmpl %edx, %eax\n" /* line 1104 */
        "je .Lf2bea18_002beb9a\n"
        "movl %eax, %edx\n" /* line 551 */
        "addl $0x10, %edx\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %ecx\n" /* line 585 | __k */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movl -0xc(%ecx), %ebx\n"
        "movl %ebx, -0x14(%ebp)\n" /* line 1915 | __osize */
        "movl 0x10(%eax), %eax\n" /* line 585 */
        "movl -0xc(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, -0x18(%ebp)\n" /* line 1916 | __size */
        "cmpl %eax, %ebx\n" /* line 189 */
        "jbe .Lf2bea18_002beb59\n"
        "leal -0x18(%ebp), %eax\n" /* __size */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl -0x3c(%ebp), %esi\n"
        "movl %edx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bea18_002beb3f\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bea18_002beb3f:\n"
        "subl -0x2c(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x44(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1104 */
        "js .Lf2bea18_002beb8a\n"
        ".Lf2bea18_002beb4e:\n"
        "movl -0x28(%ebp), %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __size, __osize, __r, __r */
        /* { scope 2 */
        ".Lf2bea18_002beb59:\n"
        "leal -0x14(%ebp), %eax\n" /* line 189 | __osize */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl -0x3c(%ebp), %esi\n"
        "movl %edx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bea18_002beb7b\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bea18_002beb7b:\n"
        "subl -0x2c(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x44(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1104 */
        "jns .Lf2bea18_002beb4e\n"
        ".Lf2bea18_002beb8a:\n"
        "movl -0x34(%ebp), %ecx\n" /* __y */
        "movl %ecx, -0x28(%ebp)\n"
        "movl %ecx, %eax\n"
        /* } scope */
        ".Lf2bea18_002beb92:\n"
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bea18_002beb9a:\n"
        "movl %edx, %ecx\n"
        /* { scope 1: __size, __osize, __r, __r */
        "movl %ecx, -0x28(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf2bea18_002beb92\n"
        ".Lf2bea18_002beba3:\n"
        "movl %eax, %edi\n"
        "movl %eax, -0x24(%ebp)\n" /* line 1095 */
        "movl %edi, %edx\n"
        "jmp .Lf2bea18_002beaef\n"
    );
}

/* line 787 */
__attribute__((naked))
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE9_M_insertEPSt18_Rb_tree_node_baseSA_RKS2_(void) /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >__M_insert */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 787 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 0x14(%ebp), %esi\n" /* __v */
        /* { scope 1: __size, __osize, __r */
        "movl $0x18, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %eax, -0x30(%ebp)\n" /* __z */
        /* { scope 2 */
        "movl %eax, %ebx\n" /* line 104 */
        "addl $0x10, %ebx\n"
        "je .Lf2bebb0_002bebf3\n"
        "movl %esi, 4(%esp)\n" /* line 69 */
        "movl %ebx, (%esp)\n"
        "calll __ZNSsC1ERKSs\n"
        "leal 4(%esi), %eax\n"
        "movl -0x30(%ebp), %edx\n" /* __z */
        "addl $0x14, %edx\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll __ZNSsC1ERKSs\n"
        /* } scope */
        ".Lf2bebb0_002bebf3:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 792 | __x */
        "testl %ecx, %ecx\n"
        "je .Lf2bebb0_002bec37\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "addl $4, %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        ".Lf2bebb0_002bec03:\n"
        "movl $1, %eax\n"
        ".Lf2bebb0_002bec08:\n"
        "movl -0x38(%ebp), %edi\n" /* line 796 */
        "movl %edi, 0xc(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* __p */
        "movl %edx, 8(%esp)\n"
        "movl -0x30(%ebp), %ecx\n" /* __z */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_\n"
        "movl 8(%ebp), %edi\n" /* line 798 | this */
        "addl $1, 0x14(%edi)\n"
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 799 | __z */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __size, __osize, __r */
        ".Lf2bebb0_002bec37:\n"
        "movl 8(%ebp), %edx\n" /* line 473 | this */
        "addl $4, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "cmpl %edx, 0x10(%ebp)\n" /* line 792 | __p */
        "je .Lf2bebb0_002bec03\n"
        "movl 0x10(%ebp), %edx\n" /* line 505 | __p */
        "addl $0x10, %edx\n"
        /* { scope 2 */
        "movl (%esi), %esi\n" /* line 269 */
        "movl %esi, -0x34(%ebp)\n"
        "movl -0xc(%esi), %ebx\n" /* line 585 | this */
        "movl %ebx, -0x20(%ebp)\n" /* line 1915 | this, __size */
        "movl 0x10(%ebp), %edi\n" /* line 269 | __p */
        "movl 0x10(%edi), %eax\n"
        "movl -0xc(%eax), %eax\n" /* line 585 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, -0x24(%ebp)\n" /* line 1916 | __osize */
        "cmpl %eax, %ebx\n" /* line 189 */
        "jbe .Lf2bebb0_002beca5\n"
        "leal -0x24(%ebp), %eax\n" /* __osize */
        ".Lf2bebb0_002bec6c:\n"
        "movl (%edx), %edx\n" /* line 269 */
        "movl (%eax), %ecx\n" /* line 253 */
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl -0x34(%ebp), %esi\n"
        "movl %edx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bebb0_002bec8b\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bebb0_002bec8b:\n"
        "subl -0x2c(%ebp), %ebx\n" /* line 1921 | this */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n" /* this */
        "movl %ebx, -0x3c(%ebp)\n" /* this, __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 792 | this */
        "js .Lf2bebb0_002bec03\n"
        "xorl %eax, %eax\n"
        "jmp .Lf2bebb0_002bec08\n"
        /* { scope 2 */
        ".Lf2bebb0_002beca5:\n"
        "leal -0x20(%ebp), %eax\n" /* line 189 | __size */
        "jmp .Lf2bebb0_002bec6c\n"
        "movl %eax, %esi\n"
        /* } scope */
        ".Lf2bebb0_002becac:\n"
        "movl %esi, (%esp)\n" /* line 368 */
        "calll ___cxa_begin_catch\n"
        "movl -0x30(%ebp), %eax\n" /* line 94 | __z */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "calll ___cxa_rethrow\n" /* line 371 */
        "movl %eax, %esi\n"
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 3 */
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 224 */
        "je .Lf2bebb0_002becac\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bebb0_002becac\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bebb0_002becac\n"
        "movl %eax, %esi\n"
        /* } scope */
        /* } scope */
        "calll ___cxa_end_catch\n" /* line 368 */
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 869 */
__attribute__((naked))
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE13insert_uniqueERKS2_(void) /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_insert_unique */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 869 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl $0, -0x48(%ebp)\n"
        "movl $0, -0x44(%ebp)\n"
        /* { scope 1: __size, __osize, __r, __r */
        "movl 8(%ebp), %eax\n" /* line 462 | this */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* __x */
        "movl 8(%ebp), %edx\n" /* line 473 | this */
        "addl $4, %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* __y */
        "testl %eax, %eax\n" /* line 874 */
        "je .Lf2bed0a_002bee03\n"
        "movl 0xc(%ebp), %ecx\n" /* __v */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n" /* __x */
        "movl %ecx, %esi\n"
        "movl -0x3c(%ebp), %edi\n" /* __x */
        "jmp .Lf2bed0a_002bed9a\n"
        /* { scope 2 */
        ".Lf2bed0a_002bed50:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 189 | __osize */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl -0x4c(%ebp), %esi\n"
        "movl %edx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bed0a_002bed72\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bed0a_002bed72:\n"
        "subl -0x34(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x60(%ebp)\n" /* __r */
        /* } scope */
        "movl %ebx, %edx\n" /* line 877 */
        "shrl $0x1f, %edx\n"
        "testb %dl, %dl\n" /* line 878 */
        "je .Lf2bed0a_002bede9\n"
        ".Lf2bed0a_002bed86:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 489 | __x */
        "movl 8(%ecx), %eax\n"
        "testl %eax, %eax\n" /* line 874 */
        "je .Lf2bed0a_002bedf3\n"
        ".Lf2bed0a_002bed90:\n"
        "movl %eax, -0x3c(%ebp)\n" /* __x */
        "movl %eax, %edx\n"
        "movl -0x4c(%ebp), %esi\n"
        "movl %eax, %edi\n"
        ".Lf2bed0a_002bed9a:\n"
        "addl $0x10, %edx\n" /* line 551 */
        /* { scope 2 */
        "movl -0xc(%esi), %ebx\n" /* line 585 */
        "movl %ebx, -0x20(%ebp)\n" /* line 1915 | __size */
        "movl 0x10(%edi), %eax\n" /* line 585 */
        "movl -0xc(%eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 1916 | __osize */
        "cmpl %eax, %ebx\n" /* line 189 */
        "ja .Lf2bed0a_002bed50\n"
        "leal -0x20(%ebp), %eax\n" /* __size */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl -0x4c(%ebp), %esi\n"
        "movl %edx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bed0a_002bedd5\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bed0a_002bedd5:\n"
        "subl -0x34(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x60(%ebp)\n" /* __r */
        /* } scope */
        "movl %ebx, %edx\n" /* line 877 */
        "shrl $0x1f, %edx\n"
        "testb %dl, %dl\n" /* line 878 */
        "jne .Lf2bed0a_002bed86\n"
        ".Lf2bed0a_002bede9:\n"
        "movl -0x3c(%ebp), %esi\n" /* line 497 | __x */
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n" /* line 874 */
        "jne .Lf2bed0a_002bed90\n"
        ".Lf2bed0a_002bedf3:\n"
        "movl -0x3c(%ebp), %edi\n" /* __x */
        "movl %edi, -0x38(%ebp)\n" /* __y */
        "testb %dl, %dl\n" /* line 881 */
        "je .Lf2bed0a_002bee90\n"
        "movl %edi, %edx\n"
        ".Lf2bed0a_002bee03:\n"
        "movl 8(%ebp), %eax\n" /* line 882 | this */
        "cmpl 0xc(%eax), %edx\n"
        "je .Lf2bed0a_002beebe\n"
        "movl %edx, (%esp)\n" /* line 196 */
        "calll __ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, %edx\n"
        "movl %eax, %edi\n"
        "addl $0x10, %edx\n" /* line 551 */
        /* { scope 2 */
        "movl 0x10(%edi), %eax\n" /* line 585 */
        "movl -0xc(%eax), %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 1915 | __osize */
        "movl 0xc(%ebp), %eax\n" /* line 585 | __v */
        "movl (%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl -0xc(%eax), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n" /* line 1916 | __size */
        "cmpl %ecx, %ebx\n" /* line 189 */
        "jbe .Lf2bed0a_002beeb9\n"
        ".Lf2bed0a_002bee3f:\n"
        "leal -0x20(%ebp), %eax\n" /* __size */
        ".Lf2bed0a_002bee42:\n"
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl %edx, %esi\n"
        "movl -0x4c(%ebp), %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bed0a_002bee61\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bed0a_002bee61:\n"
        "subl -0x30(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x5c(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 886 */
        "js .Lf2bed0a_002beef5\n"
        "movl -0x2c(%ebp), %eax\n" /* line 85 */
        "xorl %edx, %edx\n"
        ".Lf2bed0a_002bee79:\n"
        "movb %dl, -0x44(%ebp)\n"
        "movl %eax, -0x48(%ebp)\n"
        /* } scope */
        "movl -0x48(%ebp), %eax\n" /* line 888 */
        "movl -0x44(%ebp), %edx\n"
        "addl $0x8c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __size, __osize, __r, __r */
        ".Lf2bed0a_002bee90:\n"
        "movl %edi, -0x2c(%ebp)\n" /* line 881 */
        "movl %edi, %edx\n"
        "movl -0x2c(%ebp), %edi\n"
        "addl $0x10, %edx\n" /* line 551 */
        /* { scope 2 */
        "movl 0x10(%edi), %eax\n" /* line 585 */
        "movl -0xc(%eax), %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 1915 | __osize */
        "movl 0xc(%ebp), %eax\n" /* line 585 | __v */
        "movl (%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl -0xc(%eax), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n" /* line 1916 | __size */
        "cmpl %ecx, %ebx\n" /* line 189 */
        "ja .Lf2bed0a_002bee3f\n"
        ".Lf2bed0a_002beeb9:\n"
        "leal -0x1c(%ebp), %eax\n" /* __osize */
        "jmp .Lf2bed0a_002bee42\n"
        /* } scope */
        ".Lf2bed0a_002beebe:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 883 | __v */
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE9_M_insertEPSt18_Rb_tree_node_baseSA_RKS2_\n"
        "movl $1, %edx\n" /* line 85 */
        "movb %dl, -0x44(%ebp)\n"
        "movl %eax, -0x48(%ebp)\n"
        /* } scope */
        "movl -0x48(%ebp), %eax\n" /* line 888 */
        "movl -0x44(%ebp), %edx\n"
        "addl $0x8c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __size, __osize, __r, __r */
        ".Lf2bed0a_002beef5:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 887 | __v */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x38(%ebp), %esi\n" /* __y */
        "movl %esi, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl %edi, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE9_M_insertEPSt18_Rb_tree_node_baseSA_RKS2_\n"
        "movl $1, %edx\n" /* line 85 */
        "jmp .Lf2bed0a_002bee79\n"
    );
}

/* line 895 */
__attribute__((naked))
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE13insert_uniqueESt17_Rb_tree_iteratorIS2_ERKS2_(void) /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_insert_unique */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 895 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 897 | this */
        "addl $4, %eax\n"
        "cmpl 0xc(%ebp), %eax\n" /* __position */
        "je .Lf2bef20_002bf111\n"
        "movl 0xc(%ebp), %edx\n" /* __position */
        "movl 8(%ebp), %eax\n" /* this */
        "cmpl 0x10(%eax), %edx\n"
        "je .Lf2bef20_002bf080\n"
        "movl %edx, (%esp)\n" /* line 181 */
        "calll __ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 551 | __position */
        "addl $0x10, %edx\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %ecx\n" /* line 585 | __position */
        "movl 0x10(%ecx), %eax\n"
        "movl -0xc(%eax), %ebx\n"
        "movl %ebx, -0x20(%ebp)\n" /* line 1915 | __size */
        "movl 0x10(%ebp), %esi\n" /* line 585 | __v */
        "movl (%esi), %esi\n"
        "movl %esi, -0x40(%ebp)\n"
        "movl -0xc(%esi), %edi\n"
        "movl %edi, -0x34(%ebp)\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 1916 | __osize */
        "cmpl %edi, %ebx\n" /* line 189 */
        "ja .Lf2bef20_002befc4\n"
        "leal -0x20(%ebp), %eax\n" /* __size */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl %edx, %esi\n"
        "movl -0x40(%ebp), %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bef20_002bef9b\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bef20_002bef9b:\n"
        "subl -0x34(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x50(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 911 */
        "js .Lf2bef20_002beff5\n"
        ".Lf2bef20_002befaa:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 923 | __v */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl %esi, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE13insert_uniqueERKS2_\n"
        ".Lf2bef20_002befbc:\n"
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bef20_002befc4:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 903 | __osize */
        /* { scope 1 */
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl %edx, %esi\n"
        "movl -0x40(%ebp), %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bef20_002befe6\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bef20_002befe6:\n"
        "subl -0x34(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x50(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 911 */
        "jns .Lf2bef20_002befaa\n"
        ".Lf2bef20_002beff5:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 551 */
        "addl $0x10, %edx\n"
        /* { scope 1 */
        "movl -0x40(%ebp), %ecx\n" /* line 585 */
        "movl -0xc(%ecx), %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 1915 | __osize */
        "movl -0x2c(%ebp), %esi\n" /* line 585 */
        "movl 0x10(%esi), %eax\n"
        "movl -0xc(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl %eax, -0x20(%ebp)\n" /* line 1916 | __size */
        "cmpl %eax, %ebx\n" /* line 189 */
        "jbe .Lf2bef20_002bf109\n"
        "leal -0x20(%ebp), %eax\n" /* __size */
        ".Lf2bef20_002bf01e:\n"
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl -0x40(%ebp), %esi\n"
        "movl %edx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bef20_002bf03d\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bef20_002bf03d:\n"
        "subl -0x30(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x4c(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 911 */
        "jns .Lf2bef20_002befaa\n"
        "movl 0xc(%ebp), %edi\n" /* line 916 | __position */
        "movl 0xc(%edi), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf2bef20_002bf14b\n"
        "movl 0x10(%ebp), %ecx\n" /* line 919 | __v */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x2c(%ebp), %esi\n"
        "movl %esi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl %edi, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE9_M_insertEPSt18_Rb_tree_node_baseSA_RKS2_\n"
        "jmp .Lf2bef20_002befbc\n"
        ".Lf2bef20_002bf080:\n"
        "movl %eax, %ecx\n"
        "movl 0x14(%ecx), %esi\n" /* line 900 */
        "testl %esi, %esi\n"
        "je .Lf2bef20_002bf11f\n"
        ".Lf2bef20_002bf08d:\n"
        "movl %ecx, %esi\n"
        "addl $0x10, %ecx\n" /* line 454 */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 0x10(%esi), %eax\n" /* line 551 */
        "leal 0x10(%eax), %edx\n"
        /* { scope 1 */
        "movl 0x10(%eax), %eax\n" /* line 585 */
        "movl -0xc(%eax), %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 1915 | __osize */
        "movl 0x10(%ebp), %edi\n" /* line 585 | __v */
        "movl (%edi), %edi\n"
        "movl %edi, -0x40(%ebp)\n"
        "movl -0xc(%edi), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, -0x20(%ebp)\n" /* line 1916 | __size */
        "cmpl %eax, %ebx\n" /* line 189 */
        "jbe .Lf2bef20_002bf104\n"
        "leal -0x20(%ebp), %eax\n" /* __size */
        ".Lf2bef20_002bf0bc:\n"
        "movl (%edx), %edx\n" /* line 253 */
        "movl (%eax), %ecx\n"
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "movl %edx, %esi\n"
        "movl -0x40(%ebp), %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2bef20_002bf0db\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf2bef20_002bf0db:\n"
        "subl -0x38(%ebp), %ebx\n" /* line 1921 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, -0x50(%ebp)\n" /* __r */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 900 */
        "js .Lf2bef20_002bf123\n"
        "movl 8(%ebp), %esi\n" /* this */
        ".Lf2bef20_002bf0ed:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 905 | __v */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE13insert_uniqueERKS2_\n"
        "addl $0x7c, %esp\n" /* line 923 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bef20_002bf104:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 189 | __osize */
        "jmp .Lf2bef20_002bf0bc\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2bef20_002bf109:\n"
        "leal -0x1c(%ebp), %eax\n" /* __osize */
        "jmp .Lf2bef20_002bf01e\n"
        ".Lf2bef20_002bf111:\n"
        "movl 8(%ebp), %ecx\n" /* this */
        /* } scope */
        "movl 0x14(%ecx), %esi\n" /* line 900 */
        "testl %esi, %esi\n"
        "jne .Lf2bef20_002bf08d\n"
        ".Lf2bef20_002bf11f:\n"
        "movl %ecx, %esi\n"
        "jmp .Lf2bef20_002bf0ed\n"
        ".Lf2bef20_002bf123:\n"
        "movl 0x10(%ebp), %edi\n" /* line 903 | __v */
        "movl %edi, 0xc(%esp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE9_M_insertEPSt18_Rb_tree_node_baseSA_RKS2_\n"
        "jmp .Lf2bef20_002befbc\n"
        ".Lf2bef20_002bf14b:\n"
        "movl 0x10(%ebp), %eax\n" /* line 917 | __v */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE9_M_insertEPSt18_Rb_tree_node_baseSA_RKS2_\n"
        "jmp .Lf2bef20_002befbc\n"
    );
}

/* line 1051 */
__attribute__((naked))
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E(void) /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >__M_erase */
{
    __asm__ __volatile__ (
        ".Lf2bf16e_002bf16e:\n"
        "pushl %ebp\n" /* line 1051 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* __x */
        "testl %ebx, %ebx\n" /* line 1054 | __x */
        "jne .Lf2bf16e_002bf183\n"
        "jmp .Lf2bf16e_002bf1cc\n"
        ".Lf2bf16e_002bf180:\n"
        "movl -0x30(%ebp), %ebx\n" /* __y, __x */
        /* { scope 1: this */
        ".Lf2bf16e_002bf183:\n"
        "movl 0xc(%ebx), %eax\n" /* line 497 */
        "movl %eax, 4(%esp)\n" /* line 1056 */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E\n"
        "movl 8(%ebx), %edx\n" /* line 489 */
        "movl %edx, -0x30(%ebp)\n" /* __y */
        "leal 0x10(%ebx), %eax\n" /* line 389 */
        "movl %eax, -0x2c(%ebp)\n" /* this */
        /* { scope 2 */
        "movl 0x14(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 3 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %esi\n" /* line 224 */
        "jne .Lf2bf16e_002bf1d4\n"
        /* } scope */
        ".Lf2bf16e_002bf1b1:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 269 | this */
        "movl (%edx), %eax\n"
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 3 */
        "cmpl %edi, %esi\n" /* line 224 */
        "jne .Lf2bf16e_002bf1fc\n"
        /* } scope */
        /* } scope */
        ".Lf2bf16e_002bf1bd:\n"
        "movl %ebx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 1054 | __y */
        "testl %eax, %eax\n"
        "jne .Lf2bf16e_002bf180\n"
        ".Lf2bf16e_002bf1cc:\n"
        "addl $0x3c, %esp\n" /* line 1059 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: this */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf2bf16e_002bf1d4:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bf16e_002bf1b1\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bf16e_002bf1b1\n"
        /* } scope */
        /* { scope 3 */
        ".Lf2bf16e_002bf1fc:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bf16e_002bf1bd\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bf16e_002bf1bd\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* } scope */
        ".Lf2bf16e_002bf226:\n"
        "movl %ebx, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        /* { scope 2 */
        "movl -0x2c(%ebp), %edx\n" /* line 269 | this */
        "movl (%edx), %eax\n"
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 3 */
        "cmpl %edi, %esi\n" /* line 224 */
        "je .Lf2bf16e_002bf226\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bf16e_002bf226\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bf16e_002bf226\n"
    );
}

#else
double CStringEdPackage_SetupNewFileParse(const CStringEdPackage * _this, const char *psFileName) { return 0.0f; }
#endif
