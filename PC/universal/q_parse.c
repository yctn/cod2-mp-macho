/* ASM dump from: q_parse.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/q_parse.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

static const char * punctuation[15]; /* 0x30f540 */
static ParseThreadInfo g_parse[1]; /* 0x30ab60 */

int Com_Compress(char *data_p);
int Com_BeginParseSession(const char *filename);
int Com_EndParseSession(void);
int Com_ResetParseSessions(void);
int Com_SetSpaceDelimited(qboolean spaceDelimited);
int Com_SetKeepStringQuotes(qboolean keepStringQuotes);
int Com_SetCSV(qboolean csv);
int Com_GetCurrentParseLine(void);
int Com_SetScriptWarningPrefix(const char *prefix);
int Com_ScriptError(const char *msg);
int Com_ScriptWarning(const char *msg);
int Com_UngetToken(void);
int Com_ParseSetMark(const char * *text, com_parse_mark_t *mark);
int Com_ParseReturnToMark(const char * *text, com_parse_mark_t *mark);
const char * Com_GetLastTokenPos(void);
static char * Com_ParseExt(const char * *data_p);
const char * Com_Parse(const char * *data_p);
const char * Com_ParseOnLine(const char * *data_p);
int Com_SkipRestOfLine(const char * *data);
qboolean Com_MatchToken(const char * *buf_p, const char *match, qboolean warning);
float Com_ParseFloat(const char * *buf_p);
int Com_ParseInt(const char * *buf_p);
int Com_GetArgCountOnLine(const char * *data_p);

/* line 424 */
__attribute__((naked))
int Com_Compress(char *data_p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 424 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* data_p */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 433 */
        "je .Lfae240_000ae26b\n"
        "movl %eax, %ecx\n"
        "movl %eax, -0x10(%ebp)\n"
        "xorl %ebx, %ebx\n" /* size */
        "movzbl (%eax), %edx\n"
        ".Lfae240_000ae25a:\n"
        "testb %dl, %dl\n" /* line 435 */
        "jne .Lfae240_000ae27c\n"
        ".Lfae240_000ae25e:\n"
        "movb $0, (%ecx)\n" /* line 488 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 490 | size */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfae240_000ae26b:\n"
        "xorl %ecx, %ecx\n" /* line 433 */
        "xorl %ebx, %ebx\n" /* size */
        "movb $0, (%ecx)\n" /* line 488 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 490 | size */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfae240_000ae27c:\n"
        "cmpb $0xd, %dl\n" /* line 437 */
        "je .Lfae240_000ae29f\n"
        "cmpb $0xa, %dl\n"
        "je .Lfae240_000ae29f\n"
        "cmpb $0x2f, %dl\n" /* line 446 */
        "je .Lfae240_000ae2b3\n"
        "addl $1, -0x10(%ebp)\n" /* line 457 */
        ".Lfae240_000ae28f:\n"
        "movb %dl, (%ecx)\n" /* line 480 */
        "addl $1, %ecx\n" /* line 481 */
        "addl $1, %ebx\n" /* line 482 | size */
        "movl -0x10(%ebp), %eax\n"
        "movzbl (%eax), %edx\n"
        "jmp .Lfae240_000ae25a\n"
        ".Lfae240_000ae29f:\n"
        "movb %dl, (%ecx)\n" /* line 439 */
        "addl $1, %ecx\n" /* line 440 */
        "addl $1, %ebx\n" /* line 441 | size */
        "addl $1, -0x10(%ebp)\n" /* line 443 */
        "movl -0x10(%ebp), %eax\n"
        "movzbl (%eax), %edx\n"
        "jmp .Lfae240_000ae25a\n"
        ".Lfae240_000ae2b3:\n"
        "movl -0x10(%ebp), %edi\n" /* line 446 */
        "addl $1, %edi\n"
        "movl -0x10(%ebp), %eax\n"
        "movzbl 1(%eax), %esi\n"
        "movl %esi, %eax\n"
        "cmpb $0x2f, %al\n"
        "je .Lfae240_000ae2d1\n"
        "movl %esi, %eax\n" /* line 455 */
        "cmpb $0x2a, %al\n"
        "je .Lfae240_000ae2e9\n"
        "movl %edi, -0x10(%ebp)\n"
        "jmp .Lfae240_000ae28f\n"
        ".Lfae240_000ae2d1:\n"
        "movl %edi, -0x10(%ebp)\n" /* line 450 */
        "movzbl (%edi), %edx\n" /* line 448 */
        "testb %dl, %dl\n"
        "je .Lfae240_000ae25e\n"
        "cmpb $0xa, %dl\n"
        "je .Lfae240_000ae25a\n"
        "addl $1, %edi\n"
        "jmp .Lfae240_000ae2d1\n"
        ".Lfae240_000ae2e9:\n"
        "movl %edi, %edx\n" /* line 465 */
        "movl %esi, %eax\n" /* line 457 */
        "testb %al, %al\n"
        "je .Lfae240_000ae328\n"
        "cmpb $0x2a, %al\n"
        "je .Lfae240_000ae310\n"
        "movl %esi, %eax\n" /* line 459 */
        "cmpb $0xa, %al\n"
        "jne .Lfae240_000ae304\n"
        "movb $0xa, (%ecx)\n" /* line 461 */
        "addl $1, %ecx\n" /* line 462 */
        "addl $1, %ebx\n" /* line 463 | size */
        ".Lfae240_000ae304:\n"
        "movl %edi, -0x10(%ebp)\n"
        "addl $1, %edi\n"
        "movzbl 1(%edx), %esi\n"
        "jmp .Lfae240_000ae2e9\n"
        ".Lfae240_000ae310:\n"
        "movl -0x10(%ebp), %eax\n" /* line 457 */
        "cmpb $0x2f, 2(%eax)\n"
        "jne .Lfae240_000ae304\n"
        "leal 2(%edi), %eax\n" /* line 469 */
        "movl %eax, -0x10(%ebp)\n"
        "movzbl 2(%edi), %edx\n"
        "jmp .Lfae240_000ae25a\n"
        ".Lfae240_000ae328:\n"
        "movl %edi, -0x10(%ebp)\n" /* line 457 */
        "movzbl (%edi), %edx\n"
        "jmp .Lfae240_000ae25a\n"
    );
}

/* line 137 */
__attribute__((naked))
int Com_BeginParseSession(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 137 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* filename */
        /* { scope 1 */
        "cmpl $0xf, 0x30f120\n" /* line 145 */
        "je .Lfae334_000ae3e3\n"
        ".Lfae334_000ae34d:\n"
        "movl 0x30f120, %edx\n" /* line 152 */
        "addl $1, %edx\n"
        "movl %edx, 0x30f120\n"
        "leal (%edx, %edx, 8), %edx\n" /* line 153 */
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "leal g_parse(, %eax, 4), %eax\n"
        "movl $1, 0x400(%eax)\n" /* line 103 */
        "movb $0, 0x404(%eax)\n" /* line 104 */
        "movb $1, 0x405(%eax)\n" /* line 105 */
        "movb $0, 0x406(%eax)\n" /* line 106 */
        "movb $0, 0x407(%eax)\n" /* line 107 */
        "movb $0, 0x408(%eax)\n" /* line 108 */
        "movl $0x2157b8, 0x40c(%eax)\n" /* line 109 */
        "movl $0x2157b8, 0x410(%eax)\n" /* line 110 */
        "movl $0, 0x414(%eax)\n" /* line 111 */
        "movl $0, 0x418(%eax)\n" /* line 112 */
        "movl $0x40, 8(%esp)\n" /* line 155 */
        "movl %edi, 4(%esp)\n" /* filename */
        "addl $0x41c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 156 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfae334_000ae3e3:\n"
        "movl $0x21e878, (%esp)\n" /* line 147 */
        "calll Com_Printf\n"
        "movl 0x30f120, %eax\n" /* line 148 */
        "testl %eax, %eax\n"
        "jg .Lfae334_000ae415\n"
        ".Lfae334_000ae3f8:\n"
        "movl %edi, 8(%esp)\n" /* line 150 | filename */
        "movl $0x21e894, 4(%esp)\n" /* "Com_BeginParseSession: session overflow trying to parse %s
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfae334_000ae34d\n"
        ".Lfae334_000ae415:\n"
        "xorl %ebx, %ebx\n" /* line 148 | i */
        "movl $0x30af7c, %esi\n"
        ".Lfae334_000ae41c:\n"
        "movl %esi, 8(%esp)\n" /* line 149 */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $0x21e88c, (%esp)\n" /* "%i. %s
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 148 | i */
        "addl $0x45c, %esi\n"
        "cmpl %ebx, 0x30f120\n" /* i */
        "jg .Lfae334_000ae41c\n"
        "jmp .Lfae334_000ae3f8\n"
    );
}

/* line 164 */
__attribute__((naked))
int Com_EndParseSession(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 164 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x30f120, %edx\n" /* line 170 */
        "testl %edx, %edx\n"
        "jne .Lfae444_000ae468\n"
        "movl $0x21e8d4, 4(%esp)\n" /* line 171 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lfae444_000ae468:\n"
        "subl $1, 0x30f120\n" /* line 172 */
        "leave\n" /* line 173 */
        "retl\n"
    );
}

/* line 176 */
__attribute__((naked))
int Com_ResetParseSessions(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 176 */
        "movl %esp, %ebp\n"
        "movl $0, 0x30f120\n" /* line 182 */
        "popl %ebp\n" /* line 183 */
        "retl\n"
    );
}

/* line 186 */
__attribute__((naked))
int Com_SetSpaceDelimited(qboolean spaceDelimited)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 186 */
        "movl %esp, %ebp\n"
        "movl 0x30f120, %eax\n" /* line 194 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 8(%ebp), %ecx\n" /* spaceDelimited */
        "testl %ecx, %ecx\n"
        "setne 0x30af65(, %edx, 4)\n"
        "popl %ebp\n" /* line 195 */
        "retl\n"
    );
}

/* line 198 */
__attribute__((naked))
int Com_SetKeepStringQuotes(qboolean keepStringQuotes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 198 */
        "movl %esp, %ebp\n"
        "movl 0x30f120, %eax\n" /* line 206 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 8(%ebp), %eax\n" /* keepStringQuotes */
        "testl %eax, %eax\n"
        "setne 0x30af66(, %edx, 4)\n"
        "popl %ebp\n" /* line 207 */
        "retl\n"
    );
}

/* line 210 */
__attribute__((naked))
int Com_SetCSV(qboolean csv)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 210 */
        "movl %esp, %ebp\n"
        "movl 0x30f120, %eax\n" /* line 218 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 8(%ebp), %eax\n" /* csv */
        "testl %eax, %eax\n"
        "setne 0x30af67(, %edx, 4)\n"
        "popl %ebp\n" /* line 219 */
        "retl\n"
    );
}

/* line 239 */
__attribute__((naked))
int Com_GetCurrentParseLine(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 239 */
        "movl %esp, %ebp\n"
        "movl 0x30f120, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x30af60(, %edx, 4), %eax\n"
        "popl %ebp\n" /* line 248 */
        "retl\n"
    );
}

/* line 265 */
__attribute__((naked))
int Com_SetScriptWarningPrefix(const char *prefix)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 265 */
        "movl %esp, %ebp\n"
        "movl 0x30f120, %eax\n" /* line 275 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 8(%ebp), %eax\n" /* prefix */
        "movl %eax, 0x30af70(, %edx, 4)\n"
        "popl %ebp\n" /* line 276 */
        "retl\n"
    );
}

/* line 279 */
__attribute__((naked))
int Com_ScriptError(const char *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 279 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1030, %esp\n"
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 287 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %esi\n" /* pi_ */
        "leal 0xc(%ebp), %eax\n" /* line 289 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 8(%esp)\n" /* line 290 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %eax, 4(%esp)\n"
        "leal -0x100c(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll vsprintf\n"
        "movl 0x30f120, %eax\n" /* line 293 */
        "testl %eax, %eax\n"
        "je .Lfae526_000ae5af\n"
        "movl %ebx, 0x14(%esp)\n" /* line 294 */
        "movl 0x400(%esi), %eax\n" /* pi_ */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x41c(%esi), %eax\n" /* pi_ */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x40c(%esi), %eax\n" /* pi_ */
        "movl %eax, 8(%esp)\n"
        "movl $0x21e8fc, 4(%esp)\n" /* "%sFile %s, line %i: %s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x1030, %esp\n" /* line 297 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfae526_000ae5af:\n"
        "movl %ebx, 8(%esp)\n" /* line 296 */
        "movl $0x21cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x1030, %esp\n" /* line 297 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 300 */
__attribute__((naked))
int Com_ScriptWarning(const char *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 300 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1030, %esp\n"
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 308 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %esi\n" /* pi_ */
        "leal 0xc(%ebp), %eax\n" /* line 310 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 8(%esp)\n" /* line 311 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %eax, 4(%esp)\n"
        "leal -0x100c(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll vsprintf\n"
        "movl 0x30f120, %eax\n" /* line 314 */
        "testl %eax, %eax\n"
        "je .Lfae5d2_000ae653\n"
        "movl %ebx, 0x10(%esp)\n" /* line 315 */
        "movl 0x400(%esi), %eax\n" /* pi_ */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x41c(%esi), %eax\n" /* pi_ */
        "movl %eax, 8(%esp)\n"
        "movl 0x410(%esi), %eax\n" /* pi_ */
        "movl %eax, 4(%esp)\n"
        "movl $0x21e914, (%esp)\n" /* "%sFile %s, line %i: %s" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x1030, %esp\n" /* line 318 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfae5d2_000ae653:\n"
        "movl %ebx, 4(%esp)\n" /* line 317 */
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x1030, %esp\n" /* line 318 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 329 */
__attribute__((naked))
int Com_UngetToken(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 329 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 335 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %ebx\n" /* pi_ */
        "cmpb $0, 0x404(%ebx)\n" /* line 337 | pi_ */
        "je .Lfae66e_000ae6a0\n"
        "movl $0x21e92c, (%esp)\n" /* line 338 */
        "calll Com_ScriptError\n"
        ".Lfae66e_000ae6a0:\n"
        "movb $1, 0x404(%ebx)\n" /* line 339 | pi_ */
        "movl 0x30f128, %eax\n" /* line 340 */
        "movl %eax, 0x30f124\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 341 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 349 */
__attribute__((naked))
int Com_ParseSetMark(const char * *text, com_parse_mark_t *mark)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 349 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %ecx\n" /* mark */
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 355 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %edx\n"
        "movl 0x400(%edx), %eax\n" /* line 360 */
        "movl %eax, (%ecx)\n"
        "movl 8(%ebp), %eax\n" /* line 361 | text */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movzbl 0x404(%edx), %eax\n" /* line 362 */
        "movl %eax, 8(%ecx)\n"
        "movl 0x414(%edx), %eax\n" /* line 363 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x418(%edx), %eax\n" /* line 364 */
        "movl %eax, 0x10(%ecx)\n"
        /* } scope */
        "popl %ebp\n" /* line 365 */
        "retl\n"
    );
}

/* line 373 */
__attribute__((naked))
int Com_ParseReturnToMark(const char * *text, com_parse_mark_t *mark)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 373 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %ebx\n" /* mark */
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 379 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %edx\n"
        "movl (%ebx), %eax\n" /* line 384 | mark */
        "movl %eax, 0x400(%edx)\n"
        "movl 4(%ebx), %ecx\n" /* line 385 | mark */
        "movl 8(%ebp), %eax\n" /* text */
        "movl %ecx, (%eax)\n"
        "movl 8(%ebx), %eax\n" /* line 386 | mark */
        "testl %eax, %eax\n"
        "setne 0x404(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 387 | mark */
        "movl %eax, 0x414(%edx)\n"
        "movl 0x10(%ebx), %eax\n" /* line 388 | mark */
        "movl %eax, 0x418(%edx)\n"
        /* } scope */
        "popl %ebx\n" /* line 389 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 499 */
__attribute__((naked))
const char * Com_GetLastTokenPos(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 499 */
        "movl %esp, %ebp\n"
        "movl 0x30f124, %eax\n"
        "popl %ebp\n" /* line 506 */
        "retl\n"
    );
}

/* line 623 */
static __attribute__((naked))
char * Com_ParseExt(const char * *data_p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 623 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, %edi\n" /* allowLineBreaks */
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 634 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "leal g_parse(%edx), %esi\n" /* pi_ */
        "movl -0x24(%ebp), %eax\n" /* line 638 */
        "movl (%eax), %ebx\n" /* pi_ */
        "movb $0, g_parse(%edx)\n" /* line 640 */
        "testl %ebx, %ebx\n" /* line 643 | pi_ */
        "je .Lfae75a_000ae98a\n"
        "movl %eax, %edx\n"
        "movl 0x400(%esi), %eax\n" /* line 650 | pi_ */
        "movl %eax, 0x414(%esi)\n" /* pi_ */
        "movl (%edx), %eax\n" /* line 651 */
        "movl %eax, 0x418(%esi)\n" /* pi_ */
        "cmpb $0, 0x407(%esi)\n" /* line 654 | pi_ */
        "jne .Lfae75a_000ae85b\n"
        "xorl %ecx, %ecx\n"
        /* { scope 2 */
        ".Lfae75a_000ae7b9:\n"
        "movl 0x30f120, %eax\n" /* line 399 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %edx\n"
        "movzbl (%ebx), %eax\n" /* line 401 */
        "cmpb $0x20, %al\n"
        "jg .Lfae75a_000ae804\n"
        "jmp .Lfae75a_000ae7e2\n"
        ".Lfae75a_000ae7d8:\n"
        "addl $1, %ebx\n" /* line 412 */
        "movzbl (%ebx), %eax\n" /* line 401 */
        "cmpb $0x20, %al\n"
        "jg .Lfae75a_000ae804\n"
        ".Lfae75a_000ae7e2:\n"
        "testb %al, %al\n" /* line 403 */
        "je .Lfae75a_000ae964\n"
        "cmpb $0xa, %al\n" /* line 407 */
        "jne .Lfae75a_000ae7d8\n"
        "addl $1, 0x400(%edx)\n" /* line 409 */
        "movl $1, %ecx\n"
        "addl $1, %ebx\n" /* line 412 */
        "movzbl (%ebx), %eax\n" /* line 401 */
        "cmpb $0x20, %al\n"
        "jle .Lfae75a_000ae7e2\n"
        /* } scope */
        ".Lfae75a_000ae804:\n"
        "testl %ecx, %ecx\n" /* line 667 */
        "je .Lfae75a_000ae810\n"
        "testl %edi, %edi\n" /* allowLineBreaks */
        "je .Lfae75a_000aea07\n"
        ".Lfae75a_000ae810:\n"
        "movl %eax, %edx\n" /* line 673 */
        "cmpb $0x2f, %al\n" /* line 676 */
        "jne .Lfae75a_000ae99c\n"
        "movzbl 1(%ebx), %eax\n" /* pi_ */
        "cmpb $0x2f, %al\n"
        "je .Lfae75a_000ae909\n"
        "cmpb $0x2a, %al\n" /* line 686 */
        "je .Lfae75a_000ae840\n"
        "jmp .Lfae75a_000ae9fb\n"
        ".Lfae75a_000ae82f:\n"
        "cmpb $0xa, %al\n" /* line 690 */
        "jne .Lfae75a_000ae83a\n"
        "addl $1, 0x400(%esi)\n" /* line 692 | pi_ */
        ".Lfae75a_000ae83a:\n"
        "movl %edx, %ebx\n" /* pi_ */
        "movzbl 1(%edx), %eax\n"
        ".Lfae75a_000ae840:\n"
        "leal 1(%ebx), %edx\n" /* line 694 | pi_ */
        "testb %al, %al\n" /* line 688 */
        "je .Lfae75a_000ae854\n"
        "cmpb $0x2a, %al\n"
        "jne .Lfae75a_000ae82f\n"
        "cmpb $0x2f, 2(%ebx)\n" /* pi_ */
        "jne .Lfae75a_000ae83a\n"
        "addl $2, %edx\n" /* line 698 */
        /* { scope 2 */
        ".Lfae75a_000ae854:\n"
        "movl %edx, %ebx\n" /* line 606 | pi_ */
        "jmp .Lfae75a_000ae7b9\n"
        ".Lfae75a_000ae85b:\n"
        "movl 0x30f120, %eax\n" /* line 522 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "leal g_parse(%edx), %ebx\n" /* pi_ */
        "movl -0x24(%ebp), %eax\n" /* line 524 */
        "movl (%eax), %ecx\n"
        "movb $0, g_parse(%edx)\n" /* line 526 */
        "testl %edi, %edi\n" /* line 528 | len */
        "jne .Lfae75a_000ae8f3\n"
        "movzbl (%ecx), %eax\n" /* line 530 */
        "cmpb $0xd, %al\n"
        "je .Lfae75a_000ae8e4\n"
        "cmpb $0xa, %al\n"
        "je .Lfae75a_000ae8e4\n"
        ".Lfae75a_000ae88e:\n"
        "movl 0x30f124, %eax\n" /* line 539 */
        "movl %eax, 0x30f128\n"
        "movl %ecx, 0x30f124\n" /* line 540 */
        "xorl %edi, %edi\n" /* len */
        ".Lfae75a_000ae8a0:\n"
        "movzbl (%ecx), %eax\n" /* line 542 */
        "testb %al, %al\n"
        "je .Lfae75a_000ae8d7\n"
        ".Lfae75a_000ae8a7:\n"
        "cmpb $0x2c, %al\n"
        "je .Lfae75a_000ae979\n"
        "cmpb $0xa, %al\n"
        "je .Lfae75a_000ae97c\n"
        "cmpb $0xd, %al\n" /* line 544 */
        "je .Lfae75a_000ae8cd\n"
        "cmpb $0x22, %al\n" /* line 550 */
        "je .Lfae75a_000ae91f\n"
        "cmpl $0x3fe, %edi\n" /* line 552 | len */
        "ja .Lfae75a_000ae8cd\n"
        "movb %al, (%ebx, %edi)\n" /* line 554 | pi_ */
        "addl $1, %edi\n" /* line 555 | len */
        ".Lfae75a_000ae8cd:\n"
        "addl $1, %ecx\n" /* line 557 */
        "movzbl (%ecx), %eax\n" /* line 542 */
        "testb %al, %al\n"
        "jne .Lfae75a_000ae8a7\n"
        ".Lfae75a_000ae8d7:\n"
        "movl -0x24(%ebp), %edx\n" /* line 603 */
        "movl $0, (%edx)\n"
        "movb $0, (%ebx, %edi)\n" /* line 605 | pi_ */
        ".Lfae75a_000ae8e4:\n"
        "movl %ebx, %edi\n" /* line 606 | pi_, len */
        /* } scope */
        /* } scope */
        ".Lfae75a_000ae8e6:\n"
        "movl %edi, %eax\n" /* line 892 | allowLineBreaks */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfae75a_000ae8f0:\n"
        "addl $1, %ecx\n" /* line 536 */
        ".Lfae75a_000ae8f3:\n"
        "movzbl (%ecx), %eax\n" /* line 535 */
        "cmpb $0xd, %al\n"
        "je .Lfae75a_000ae8f0\n"
        "cmpb $0xa, %al\n"
        "jne .Lfae75a_000ae88e\n"
        "addl $1, %ecx\n" /* line 536 */
        "jmp .Lfae75a_000ae8f3\n"
        /* } scope */
        ".Lfae75a_000ae903:\n"
        "movl %edx, %ebx\n" /* line 678 | pi_ */
        "movzbl 1(%edx), %eax\n"
        ".Lfae75a_000ae909:\n"
        "leal 1(%ebx), %edx\n" /* line 680 | pi_ */
        "testb %al, %al\n" /* line 678 */
        "je .Lfae75a_000ae854\n"
        "cmpb $0xa, %al\n"
        "jne .Lfae75a_000ae903\n"
        /* { scope 2 */
        "movl %edx, %ebx\n" /* line 606 | pi_ */
        "jmp .Lfae75a_000ae7b9\n"
        ".Lfae75a_000ae91f:\n"
        "leal 1(%ecx), %eax\n" /* line 561 */
        ".Lfae75a_000ae922:\n"
        "movzbl (%eax), %edx\n" /* line 565 */
        "cmpb $0x22, %dl\n"
        "je .Lfae75a_000ae943\n"
        ".Lfae75a_000ae92a:\n"
        "cmpl $0x3fe, %edi\n" /* line 584 | len */
        "ja .Lfae75a_000ae938\n"
        "movb %dl, (%ebx, %edi)\n" /* line 586 | pi_ */
        "addl $1, %edi\n" /* line 587 | len */
        ".Lfae75a_000ae938:\n"
        "addl $1, %eax\n" /* line 589 */
        "movzbl (%eax), %edx\n" /* line 565 */
        "cmpb $0x22, %dl\n"
        "jne .Lfae75a_000ae92a\n"
        ".Lfae75a_000ae943:\n"
        "leal 1(%eax), %ecx\n" /* line 567 */
        "cmpb $0x22, 1(%eax)\n"
        "jne .Lfae75a_000ae8a0\n"
        "cmpl $0x3fe, %edi\n" /* line 569 | len */
        "ja .Lfae75a_000ae95f\n"
        "movb $0x22, (%ebx, %edi)\n" /* line 571 | pi_ */
        "addl $1, %edi\n" /* line 572 | len */
        ".Lfae75a_000ae95f:\n"
        "addl $2, %eax\n" /* line 574 */
        "jmp .Lfae75a_000ae922\n"
        /* } scope */
        ".Lfae75a_000ae964:\n"
        "movl -0x24(%ebp), %edx\n" /* line 664 */
        "movl $0, (%edx)\n"
        "movl %esi, %edi\n" /* line 665 | pi_, allowLineBreaks */
        /* } scope */
        "movl %edi, %eax\n" /* line 892 | allowLineBreaks */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfae75a_000ae979:\n"
        "addl $1, %ecx\n" /* line 598 */
        ".Lfae75a_000ae97c:\n"
        "movl -0x24(%ebp), %eax\n" /* line 599 */
        "movl %ecx, (%eax)\n"
        "movb $0, (%ebx, %edi)\n" /* line 605 | pi_ */
        "jmp .Lfae75a_000ae8e4\n"
        /* } scope */
        ".Lfae75a_000ae98a:\n"
        "movl $0, (%eax)\n" /* line 645 */
        "movl %esi, %edi\n" /* line 646 | pi_, allowLineBreaks */
        /* } scope */
        "movl %edi, %eax\n" /* line 892 | allowLineBreaks */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfae75a_000ae99c:\n"
        "movl %eax, %ecx\n" /* line 676 */
        ".Lfae75a_000ae99e:\n"
        "movl 0x30f124, %eax\n" /* line 707 */
        "movl %eax, 0x30f128\n"
        "movl %ebx, 0x30f124\n" /* line 708 | pi_ */
        "cmpb $0x22, %cl\n" /* line 711 */
        "je .Lfae75a_000aebb8\n"
        "cmpb $0, 0x405(%esi)\n" /* line 751 | pi_ */
        "je .Lfae75a_000aea0e\n"
        "movl %esi, %eax\n" /* pi_ */
        "xorl %ecx, %ecx\n"
        ".Lfae75a_000ae9c4:\n"
        "movb %dl, (%eax)\n" /* line 757 */
        "addl $1, %ecx\n" /* line 758 */
        "cmpl $0x3fe, %ecx\n"
        "jle .Lfae75a_000aeccd\n"
        ".Lfae75a_000ae9d5:\n"
        "addl $1, %ebx\n" /* line 760 | pi_ */
        "cmpb $0x20, (%ebx)\n" /* line 753 | pi_ */
        "jg .Lfae75a_000ae9d5\n"
        "cmpl $0x400, %ecx\n" /* line 765 */
        "movl $0, %eax\n"
        "cmovel %eax, %ecx\n"
        ".Lfae75a_000ae9eb:\n"
        "movb $0, (%esi, %ecx)\n" /* line 767 | pi_ */
        "movl -0x24(%ebp), %edx\n" /* line 769 */
        "movl %ebx, (%edx)\n" /* pi_ */
        "movl %esi, %edi\n" /* line 770 | pi_, allowLineBreaks */
        "jmp .Lfae75a_000ae8e6\n"
        ".Lfae75a_000ae9fb:\n"
        "movl $0x2f, %ecx\n" /* line 688 */
        "movl $0x2f, %edx\n"
        "jmp .Lfae75a_000ae99e\n"
        ".Lfae75a_000aea07:\n"
        "movl %esi, %edi\n" /* line 670 | pi_, allowLineBreaks */
        "jmp .Lfae75a_000ae8e6\n"
        ".Lfae75a_000aea0e:\n"
        "leal -0x30(%ecx), %eax\n" /* line 775 */
        "cmpb $9, %al\n"
        "jbe .Lfae75a_000aeb0e\n"
        "cmpb $0, 0x408(%esi)\n" /* pi_ */
        "je .Lfae75a_000aea2b\n"
        "cmpb $0x2d, %cl\n"
        "je .Lfae75a_000aeaf5\n"
        ".Lfae75a_000aea2b:\n"
        "cmpb $0x2e, %cl\n"
        "je .Lfae75a_000aec39\n"
        ".Lfae75a_000aea34:\n"
        "leal -0x61(%ecx), %eax\n" /* line 836 */
        "cmpb $0x19, %al\n"
        "jbe .Lfae75a_000aeb65\n"
        "leal -0x41(%ecx), %eax\n"
        "cmpb $0x19, %al\n"
        "jbe .Lfae75a_000aeb65\n"
        "cmpb $0x5f, %cl\n"
        "je .Lfae75a_000aeb65\n"
        "cmpb $0x2f, %cl\n"
        "je .Lfae75a_000aeb65\n"
        "cmpb $0x5c, %cl\n"
        "je .Lfae75a_000aeb65\n"
        "movl punctuation, %edx\n" /* line 861 */
        "testl %edx, %edx\n"
        "je .Lfae75a_000aece4\n"
        "movl $punctuation, -0x1c(%ebp)\n"
        "jmp .Lfae75a_000aea97\n"
        /* { scope 2 */
        ".Lfae75a_000aea7c:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 874 */
        "testl %ecx, %ecx\n"
        "je .Lfae75a_000aeacb\n"
        /* } scope */
        ".Lfae75a_000aea83:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 861 */
        "movl 4(%eax), %edx\n"
        "addl $4, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %edx, %edx\n"
        "je .Lfae75a_000aece4\n"
        /* { scope 2 */
        ".Lfae75a_000aea97:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n" /* allowLineBreaks */
        "repne scasb %es:(%edi), %al\n" /* allowLineBreaks */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "testl %ecx, %ecx\n" /* line 867 */
        "jle .Lfae75a_000aea7c\n"
        "movzbl (%edx), %eax\n" /* line 869 */
        "cmpb (%ebx), %al\n" /* pi_ */
        "jne .Lfae75a_000aea7c\n"
        "xorl %ecx, %ecx\n" /* line 871 */
        "jmp .Lfae75a_000aeac3\n"
        ".Lfae75a_000aeaba:\n"
        "movzbl (%ecx, %edx), %eax\n" /* line 869 */
        "cmpb (%ecx, %ebx), %al\n"
        "jne .Lfae75a_000aea83\n"
        ".Lfae75a_000aeac3:\n"
        "addl $1, %ecx\n" /* line 867 */
        "cmpl -0x20(%ebp), %ecx\n"
        "jne .Lfae75a_000aeaba\n"
        ".Lfae75a_000aeacb:\n"
        "movl %esi, %edi\n" /* line 877 | pi_, allowLineBreaks */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pi_ */
        "calll memcpy\n"
        "movl -0x20(%ebp), %edx\n" /* line 878 */
        "movb $0, (%esi, %edx)\n" /* pi_ */
        "movl %edx, %eax\n" /* line 880 */
        "addl %ebx, %eax\n" /* pi_ */
        "movl -0x24(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "jmp .Lfae75a_000ae8e6\n"
        /* } scope */
        ".Lfae75a_000aeaf5:\n"
        "movzbl 1(%ebx), %eax\n" /* line 775 | pi_ */
        "cmpb $0x2f, %al\n"
        "jle .Lfae75a_000aea34\n"
        "cmpb $0x39, %al\n"
        "jg .Lfae75a_000aea34\n"
        "movl $0x2d, %edx\n"
        ".Lfae75a_000aeb0e:\n"
        "movl %esi, %edi\n" /* pi_, allowLineBreaks */
        "xorl %ecx, %ecx\n"
        ".Lfae75a_000aeb12:\n"
        "movb %dl, (%edi)\n" /* line 782 | allowLineBreaks */
        "addl $1, %ecx\n" /* line 783 */
        "cmpl $0x3fe, %ecx\n"
        "jle .Lfae75a_000aecaf\n"
        ".Lfae75a_000aeb23:\n"
        "addl $1, %ebx\n" /* line 785 | pi_ */
        "movzbl (%ebx), %edx\n" /* line 787 | pi_ */
        "leal -0x30(%edx), %eax\n" /* line 777 */
        "cmpb $9, %al\n"
        "jbe .Lfae75a_000aeb23\n"
        "cmpb $0x2e, %dl\n"
        "je .Lfae75a_000aeb23\n"
        ".Lfae75a_000aeb35:\n"
        "cmpb $0x65, %dl\n" /* line 791 */
        "je .Lfae75a_000aec57\n"
        "cmpb $0x45, %dl\n"
        "je .Lfae75a_000aec57\n"
        ".Lfae75a_000aeb47:\n"
        "cmpl $0x400, %ecx\n" /* line 825 */
        "movl $0, %eax\n"
        "cmovel %eax, %ecx\n"
        "movb $0, (%esi, %ecx)\n" /* line 829 | pi_ */
        "movl -0x24(%ebp), %eax\n" /* line 831 */
        "movl %ebx, (%eax)\n" /* pi_ */
        "movl %esi, %edi\n" /* line 832 | pi_, allowLineBreaks */
        "jmp .Lfae75a_000ae8e6\n"
        ".Lfae75a_000aeb65:\n"
        "movl %esi, %ecx\n" /* line 836 | pi_ */
        "xorl %edi, %edi\n" /* allowLineBreaks */
        ".Lfae75a_000aeb69:\n"
        "movb %dl, (%ecx)\n" /* line 842 */
        "addl $1, %edi\n" /* line 843 | allowLineBreaks */
        "cmpl $0x3fe, %edi\n" /* allowLineBreaks */
        "jle .Lfae75a_000aecfc\n"
        ".Lfae75a_000aeb7a:\n"
        "addl $1, %ebx\n" /* line 845 | pi_ */
        "movzbl (%ebx), %edx\n" /* line 847 | pi_ */
        "leal -0x61(%edx), %eax\n" /* line 838 */
        "cmpb $0x19, %al\n"
        "jbe .Lfae75a_000aeb7a\n"
        "leal -0x41(%edx), %eax\n"
        "cmpb $0x19, %al\n"
        "jbe .Lfae75a_000aeb7a\n"
        "cmpb $0x5f, %dl\n"
        "je .Lfae75a_000aeb7a\n"
        "leal -0x30(%edx), %eax\n"
        "cmpb $9, %al\n"
        "jbe .Lfae75a_000aeb7a\n"
        "cmpl $0x400, %edi\n" /* line 850 | allowLineBreaks */
        "movl $0, %eax\n"
        "cmovel %eax, %edi\n" /* allowLineBreaks */
        ".Lfae75a_000aeba8:\n"
        "movb $0, (%esi, %edi)\n" /* line 854 | pi_ */
        "movl -0x24(%ebp), %edx\n" /* line 856 */
        "movl %ebx, (%edx)\n" /* pi_ */
        "movl %esi, %edi\n" /* line 857 | pi_, allowLineBreaks */
        "jmp .Lfae75a_000ae8e6\n"
        ".Lfae75a_000aebb8:\n"
        "cmpb $0, 0x406(%esi)\n" /* line 713 | pi_ */
        "jne .Lfae75a_000aec2f\n"
        "xorl %edi, %edi\n" /* allowLineBreaks */
        ".Lfae75a_000aebc3:\n"
        "leal 1(%ebx), %eax\n" /* line 718 | pi_ */
        ".Lfae75a_000aebc6:\n"
        "movzbl (%eax), %edx\n" /* line 721 */
        "leal 1(%eax), %ebx\n" /* pi_ */
        "cmpb $0x5c, %dl\n" /* line 722 */
        "je .Lfae75a_000aebf1\n"
        "cmpb $0x22, %dl\n" /* line 727 */
        "je .Lfae75a_000aec0f\n"
        "testb %dl, %dl\n"
        "je .Lfae75a_000aec0f\n"
        ".Lfae75a_000aebda:\n"
        "cmpb $0xa, (%ebx)\n" /* line 738 | pi_ */
        "je .Lfae75a_000aec06\n"
        ".Lfae75a_000aebdf:\n"
        "cmpl $0x3fe, %edi\n" /* line 742 | allowLineBreaks */
        "jg .Lfae75a_000aebed\n"
        "movb %dl, (%esi, %edi)\n" /* line 744 | pi_ */
        "addl $1, %edi\n" /* line 745 | allowLineBreaks */
        ".Lfae75a_000aebed:\n"
        "movl %ebx, %eax\n" /* line 718 | pi_ */
        "jmp .Lfae75a_000aebc6\n"
        ".Lfae75a_000aebf1:\n"
        "movzbl 1(%eax), %ecx\n" /* line 722 */
        "cmpb $0x22, %cl\n"
        "je .Lfae75a_000aebff\n"
        "cmpb $0x5c, %cl\n"
        "jne .Lfae75a_000aebda\n"
        ".Lfae75a_000aebff:\n"
        "leal 2(%eax), %ebx\n" /* line 725 | pi_ */
        "movl %ecx, %edx\n"
        "jmp .Lfae75a_000aebdf\n"
        ".Lfae75a_000aec06:\n"
        "addl $1, 0x400(%esi)\n" /* line 740 | pi_ */
        "jmp .Lfae75a_000aebdf\n"
        ".Lfae75a_000aec0f:\n"
        "cmpb $0, 0x406(%esi)\n" /* line 729 | pi_ */
        "je .Lfae75a_000aec1f\n"
        "movb $0x22, (%esi, %edi)\n" /* line 731 | pi_ */
        "addl $1, %edi\n" /* line 732 | allowLineBreaks */
        ".Lfae75a_000aec1f:\n"
        "movb $0, (%esi, %edi)\n" /* line 734 | pi_ */
        "movl -0x24(%ebp), %eax\n" /* line 735 */
        "movl %ebx, (%eax)\n" /* pi_ */
        "movl %esi, %edi\n" /* line 736 | pi_, allowLineBreaks */
        "jmp .Lfae75a_000ae8e6\n"
        ".Lfae75a_000aec2f:\n"
        "movb $0x22, (%esi)\n" /* line 715 | pi_ */
        "movl $1, %edi\n" /* allowLineBreaks */
        "jmp .Lfae75a_000aebc3\n"
        ".Lfae75a_000aec39:\n"
        "movzbl 1(%ebx), %eax\n" /* line 775 | pi_ */
        "cmpb $0x2f, %al\n"
        "jle .Lfae75a_000aea34\n"
        "cmpb $0x39, %al\n"
        "jg .Lfae75a_000aea34\n"
        "movl $0x2e, %edx\n"
        "jmp .Lfae75a_000aeb0e\n"
        ".Lfae75a_000aec57:\n"
        "cmpl $0x3fe, %ecx\n" /* line 793 */
        "jg .Lfae75a_000aec65\n"
        "movb %dl, (%esi, %ecx)\n" /* line 795 | pi_ */
        "addl $1, %ecx\n" /* line 796 */
        ".Lfae75a_000aec65:\n"
        "leal 1(%ebx), %eax\n" /* line 798 | pi_ */
        "movzbl 1(%ebx), %edx\n" /* line 799 | pi_ */
        "cmpb $0x2d, %dl\n" /* line 801 */
        "je .Lfae75a_000aec98\n"
        "cmpb $0x2b, %dl\n"
        "je .Lfae75a_000aec98\n"
        ".Lfae75a_000aec76:\n"
        "movl %eax, %ebx\n" /* line 809 | pi_ */
        ".Lfae75a_000aec78:\n"
        "cmpl $0x3fe, %ecx\n" /* line 814 */
        "jg .Lfae75a_000aec86\n"
        "movb %dl, (%esi, %ecx)\n" /* line 816 | pi_ */
        "addl $1, %ecx\n" /* line 817 */
        ".Lfae75a_000aec86:\n"
        "addl $1, %ebx\n" /* line 819 | pi_ */
        "movzbl (%ebx), %edx\n" /* line 821 | pi_ */
        "leal -0x30(%edx), %eax\n" /* line 812 */
        "cmpb $9, %al\n"
        "jbe .Lfae75a_000aec78\n"
        "jmp .Lfae75a_000aeb47\n"
        ".Lfae75a_000aec98:\n"
        "cmpl $0x3fe, %ecx\n" /* line 803 */
        "jg .Lfae75a_000aeca6\n"
        "movb %dl, (%esi, %ecx)\n" /* line 805 | pi_ */
        "addl $1, %ecx\n" /* line 806 */
        ".Lfae75a_000aeca6:\n"
        "leal 2(%ebx), %eax\n" /* line 808 | pi_ */
        "movzbl 2(%ebx), %edx\n" /* line 809 | pi_ */
        "jmp .Lfae75a_000aec76\n"
        ".Lfae75a_000aecaf:\n"
        "addl $1, %ebx\n" /* line 785 | pi_ */
        "movzbl (%ebx), %edx\n" /* line 787 | pi_ */
        "leal -0x30(%edx), %eax\n" /* line 777 */
        "cmpb $9, %al\n"
        "jbe .Lfae75a_000aecc5\n"
        "cmpb $0x2e, %dl\n"
        "jne .Lfae75a_000aeb35\n"
        ".Lfae75a_000aecc5:\n"
        "addl $1, %edi\n" /* line 775 | allowLineBreaks */
        "jmp .Lfae75a_000aeb12\n"
        ".Lfae75a_000aeccd:\n"
        "addl $1, %ebx\n" /* line 760 | pi_ */
        "movzbl (%ebx), %edx\n" /* line 762 | pi_ */
        "cmpb $0x20, %dl\n" /* line 753 */
        "jle .Lfae75a_000ae9eb\n"
        "addl $1, %eax\n" /* line 751 */
        "jmp .Lfae75a_000ae9c4\n"
        ".Lfae75a_000aece4:\n"
        "movzbl (%ebx), %eax\n" /* line 886 | pi_ */
        "movb %al, (%esi)\n" /* pi_ */
        "movb $0, 1(%esi)\n" /* line 887 | pi_ */
        "leal 1(%ebx), %eax\n" /* line 889 | pi_ */
        "movl -0x24(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl %esi, %edi\n" /* line 891 | pi_, allowLineBreaks */
        "jmp .Lfae75a_000ae8e6\n"
        ".Lfae75a_000aecfc:\n"
        "addl $1, %ebx\n" /* line 845 | pi_ */
        "movzbl (%ebx), %edx\n" /* line 847 | pi_ */
        "leal -0x61(%edx), %eax\n" /* line 838 */
        "cmpb $0x19, %al\n"
        "jbe .Lfae75a_000aed20\n"
        "leal -0x41(%edx), %eax\n"
        "cmpb $0x19, %al\n"
        "jbe .Lfae75a_000aed20\n"
        "cmpb $0x5f, %dl\n"
        "je .Lfae75a_000aed20\n"
        "leal -0x30(%edx), %eax\n"
        "cmpb $9, %al\n"
        "ja .Lfae75a_000aeba8\n"
        ".Lfae75a_000aed20:\n"
        "addl $1, %ecx\n" /* line 836 */
        "jmp .Lfae75a_000aeb69\n"
    );
}

/* line 900 */
__attribute__((naked))
const char * Com_Parse(const char * *data_p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 900 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* data_p */
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 906 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %edx\n"
        "cmpb $0, 0x404(%edx)\n" /* line 908 */
        "je .Lfaed28_000aed68\n"
        "movb $0, 0x404(%edx)\n" /* line 910 */
        "movl 0x418(%edx), %eax\n" /* line 911 */
        "movl %eax, (%ecx)\n"
        "movl 0x414(%edx), %eax\n" /* line 912 */
        "movl %eax, 0x400(%edx)\n"
        ".Lfaed28_000aed68:\n"
        "movl $1, %edx\n" /* line 914 */
        "movl %ecx, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 915 */
        /* { scope 1 */
        "jmp Com_ParseExt\n" /* line 914 */
    );
}

/* line 923 */
__attribute__((naked))
const char * Com_ParseOnLine(const char * *data_p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 923 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* data_p */
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 929 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %edx\n"
        "cmpb $0, 0x404(%edx)\n" /* line 931 */
        "je .Lfaed76_000aedc3\n"
        "movb $0, 0x404(%edx)\n" /* line 933 */
        "cmpb $0, 0x405(%edx)\n" /* line 934 */
        "jne .Lfaed76_000aedaf\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 940 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaed76_000aedaf:\n"
        "movl 0x418(%edx), %eax\n" /* line 936 */
        "movl %eax, (%ecx)\n"
        "movl 0x414(%edx), %eax\n" /* line 937 */
        "movl %eax, 0x400(%edx)\n"
        ".Lfaed76_000aedc3:\n"
        "xorl %edx, %edx\n" /* line 939 */
        "movl %ecx, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 940 */
        /* { scope 1 */
        "jmp Com_ParseExt\n" /* line 939 */
    );
}

/* line 1008 */
__attribute__((naked))
int Com_SkipRestOfLine(const char * *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1008 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* data */
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 1016 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %ecx\n"
        "movl (%ebx), %edx\n" /* line 1018 | data */
        "testl %edx, %edx\n" /* line 1019 */
        "je .Lfaedce_000aee08\n"
        ".Lfaedce_000aedf1:\n"
        "movzbl (%edx), %eax\n" /* line 1021 */
        "testb %al, %al\n"
        "je .Lfaedce_000aee06\n"
        "addl $1, %edx\n" /* line 1023 */
        "cmpb $0xa, %al\n" /* line 1024 */
        "jne .Lfaedce_000aedf1\n"
        "addl $1, 0x400(%ecx)\n" /* line 1026 */
        ".Lfaedce_000aee06:\n"
        "movl %edx, (%ebx)\n" /* line 1031 | data */
        /* } scope */
        ".Lfaedce_000aee08:\n"
        "popl %ebx\n" /* line 1032 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 948 */
__attribute__((naked))
qboolean Com_MatchToken(const char * *buf_p, const char *match, qboolean warning)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 948 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* buf_p */
        "movl 0xc(%ebp), %esi\n" /* match */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x30f120, %eax\n" /* line 906 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %edx\n"
        "cmpb $0, 0x404(%edx)\n" /* line 908 */
        "je .Lfaee0c_000aee54\n"
        "movb $0, 0x404(%edx)\n" /* line 910 */
        "movl 0x418(%edx), %eax\n" /* line 911 */
        "movl %eax, (%ecx)\n"
        "movl 0x414(%edx), %eax\n" /* line 912 */
        "movl %eax, 0x400(%edx)\n"
        ".Lfaee0c_000aee54:\n"
        "movl $1, %edx\n" /* line 914 */
        "movl %ecx, %eax\n"
        "calll Com_ParseExt\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl %esi, 4(%esp)\n" /* line 953 | match */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfaee0c_000aeeb3\n"
        "movl 0x10(%ebp), %eax\n" /* line 956 | warning */
        "testl %eax, %eax\n"
        "je .Lfaee0c_000aee96\n"
        "movl %esi, 8(%esp)\n" /* line 957 | match */
        "movl %ebx, 4(%esp)\n" /* token */
        "movl $0x21e944, (%esp)\n" /* "MatchToken: %s != %s
" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 961 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaee0c_000aee96:\n"
        "movl %esi, 8(%esp)\n" /* line 959 | match */
        "movl %ebx, 4(%esp)\n" /* token */
        "movl $0x21e944, (%esp)\n" /* "MatchToken: %s != %s
" */
        "calll Com_ScriptError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 961 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaee0c_000aeeb3:\n"
        "movb $1, %al\n" /* line 953 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 961 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1088 */
__attribute__((naked))
float Com_ParseFloat(const char * *buf_p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1088 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %ecx\n" /* buf_p */
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 906 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %edx\n"
        "cmpb $0, 0x404(%edx)\n" /* line 908 */
        "je .Lfaeebe_000aef01\n"
        "movb $0, 0x404(%edx)\n" /* line 910 */
        "movl 0x418(%edx), %eax\n" /* line 911 */
        "movl %eax, (%ecx)\n"
        "movl 0x414(%edx), %eax\n" /* line 912 */
        "movl %eax, 0x400(%edx)\n"
        ".Lfaeebe_000aef01:\n"
        "movl $1, %edx\n" /* line 914 */
        "movl %ecx, %eax\n"
        "calll Com_ParseExt\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 1093 */
        "calll atof\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n"
        "flds -0x14(%ebp)\n" /* line 1094 */
        "leave\n"
        "retl\n"
    );
}

/* line 1106 */
__attribute__((naked))
int Com_ParseInt(const char * *buf_p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1106 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %ecx\n" /* buf_p */
        /* { scope 1 */
        "movl 0x30f120, %eax\n" /* line 906 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %edx\n"
        "cmpb $0, 0x404(%edx)\n" /* line 908 */
        "je .Lfaef28_000aef6b\n"
        "movb $0, 0x404(%edx)\n" /* line 910 */
        "movl 0x418(%edx), %eax\n" /* line 911 */
        "movl %eax, (%ecx)\n"
        "movl 0x414(%edx), %eax\n" /* line 912 */
        "movl %eax, 0x400(%edx)\n"
        ".Lfaef28_000aef6b:\n"
        "movl $1, %edx\n" /* line 914 */
        "movl %ecx, %eax\n"
        "calll Com_ParseExt\n"
        /* } scope */
        "movl %eax, 8(%ebp)\n" /* line 1111 | buf_p */
        "leave\n" /* line 1112 */
        "jmp atoi\n" /* line 1111 */
    );
}

/* line 1034 */
__attribute__((naked))
int Com_GetArgCountOnLine(const char * *data_p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1034 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* data_p */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x30f120, %ecx\n" /* line 355 */
        "leal (%ecx, %ecx, 8), %edx\n"
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "leal g_parse(, %eax, 4), %eax\n"
        "movl 0x400(%eax), %edi\n" /* line 360 */
        "movl (%esi), %edx\n" /* line 361 */
        "movl %edx, -0x1c(%ebp)\n"
        "movzbl 0x404(%eax), %edx\n" /* line 362 */
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x414(%eax), %edx\n" /* line 363 */
        "movl %edx, -0x24(%ebp)\n"
        "movl 0x418(%eax), %eax\n" /* line 364 */
        "movl %eax, -0x28(%ebp)\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lfaef80_000aefde\n"
        /* } scope */
        /* { scope 2 */
        ".Lfaef80_000aefce:\n"
        "movl %edx, %eax\n" /* line 935 */
        /* } scope */
        "cmpb $0, (%eax)\n" /* line 1046 */
        "je .Lfaef80_000af02a\n"
        ".Lfaef80_000aefd5:\n"
        "addl $1, %ebx\n" /* line 1051 | count */
        "movl 0x30f120, %ecx\n"
        /* { scope 2 */
        ".Lfaef80_000aefde:\n"
        "leal (%ecx, %ecx, 8), %edx\n" /* line 929 */
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "leal g_parse(, %eax, 4), %edx\n"
        "cmpb $0, 0x404(%edx)\n" /* line 931 */
        "je .Lfaef80_000af01c\n"
        "movb $0, 0x404(%edx)\n" /* line 933 */
        "cmpb $0, 0x405(%edx)\n" /* line 934 */
        "je .Lfaef80_000aefce\n"
        "movl 0x418(%edx), %eax\n" /* line 936 */
        "movl %eax, (%esi)\n"
        "movl 0x414(%edx), %eax\n" /* line 937 */
        "movl %eax, 0x400(%edx)\n"
        ".Lfaef80_000af01c:\n"
        "xorl %edx, %edx\n" /* line 939 */
        "movl %esi, %eax\n"
        "calll Com_ParseExt\n"
        /* } scope */
        "cmpb $0, (%eax)\n" /* line 1046 */
        "jne .Lfaef80_000aefd5\n"
        /* { scope 2 */
        ".Lfaef80_000af02a:\n"
        "movl 0x30f120, %eax\n" /* line 379 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal g_parse(, %edx, 4), %edx\n"
        "movl %edi, 0x400(%edx)\n" /* line 384 */
        "movl -0x1c(%ebp), %eax\n" /* line 385 */
        "movl %eax, (%esi)\n"
        "movl -0x20(%ebp), %eax\n" /* line 386 */
        "testl %eax, %eax\n"
        "setne 0x404(%edx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 387 */
        "movl %eax, 0x414(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 388 */
        "movl %eax, 0x418(%edx)\n"
        /* } scope */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1057 | count */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

