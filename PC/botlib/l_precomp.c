/* ASM dump from: l_precomp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/botlib/l_precomp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern int numtokens; /* 0x0 */
extern define_t *globaldefines; /* 0x0 */
extern directive_t directives[20]; /* 0x0 */
extern directive_t dollardirectives[20]; /* 0x0 */
extern source_t * sourceFiles[64]; /* 0x0 */

void SourceError(source_t *source, char *str);
void SourceWarning(source_t *source, char *str);
int PC_StringizeTokens(token_t *tokens, token_t *token);
int PC_OperatorPriority(int op);
int PC_Directive_line(source_t *source);
int PC_SourceFileAndLine(int handle, char *filename, int *line);
int PC_ReadSourceToken(source_t *source, token_t *token);
int PC_Directive_error(source_t *source);
int PC_Directive_else(source_t *source);
int PC_Directive_endif(source_t *source);
int PC_EvaluateTokens(source_t *source, token_t *tokens, long int *intvalue, double *floatvalue, int integer);
void FreeSource(source_t *source);
int PC_FreeSourceHandle(int handle);
int PC_ReadDollarDirective(source_t *source);
int PC_ReadDirective(source_t *source);
int PC_Directive_include(source_t *source);
int PC_ReadDefineParms(source_t *source, define_t *define, token_t * *parms, int maxparms);
int PC_ExpandBuiltinDefine(source_t *source, token_t *deftoken, define_t *define, token_t * *firsttoken, token_t * *lasttoken);
int PC_ExpandDefine(source_t *source, token_t *deftoken, define_t *define, token_t * *firsttoken, token_t * *lasttoken);
int PC_ReadLine(source_t *source, token_t *token);
int PC_ReadLineHandle(int handle, pc_token_t *pc_token);
int PC_Directive_pragma(source_t *source);
int PC_Directive_if_def(source_t *source, int type);
int PC_Directive_ifndef(source_t *source);
int PC_Directive_ifdef(source_t *source);
int PC_Directive_undef(source_t *source);
int PC_ReadToken(source_t *source, token_t *token);
int PC_ReadTokenHandle(int handle, pc_token_t *pc_token);
int PC_Directive_define(source_t *source);
define_t * PC_CopyDefine(source_t *source, define_t *define);
source_t * LoadSourceFile(const char *filename);
int PC_LoadSourceHandle(const char *filename);
int PC_Evaluate(source_t *source, long int *intvalue, double *floatvalue, int integer);
int PC_Directive_evalfloat(source_t *source);
int PC_Directive_eval(source_t *source);
int PC_Directive_if(source_t *source);
int PC_Directive_elif(source_t *source);
int PC_DollarEvaluate(source_t *source, long int *intvalue, double *floatvalue, int integer);
int PC_DollarDirective_evalfloat(source_t *source);
int PC_DollarDirective_evalint(source_t *source);
void StripDoubleQuotes(char *string);

/* line 35 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void SourceError(source_t *source, char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 35 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x424, %esp\n"
        /* { scope 1 */
        "leal 0x10(%ebp), %eax\n" /* line 40 */
        "movl %eax, -0xc(%ebp)\n" /* ap */
        "movl %eax, 0xc(%esp)\n" /* line 41 */
        "movl 0xc(%ebp), %eax\n" /* str */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x40c(%ebp), %ebx\n" /* text */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "movl 8(%ebp), %eax\n" /* line 43 | source */
        "movl 0x84(%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002220ac, (%esp)\n" /* "^1Error: file %s, line %d: %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x424, %esp\n" /* line 44 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void SourceError(source_t *source, char *str) { }
#endif

/* line 53 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void SourceWarning(source_t *source, char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 53 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x424, %esp\n"
        /* { scope 1 */
        "leal 0x10(%ebp), %eax\n" /* line 58 */
        "movl %eax, -0xc(%ebp)\n" /* ap */
        "movl %eax, 0xc(%esp)\n" /* line 59 */
        "movl 0xc(%ebp), %eax\n" /* str */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x40c(%ebp), %ebx\n" /* text */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "movl 8(%ebp), %eax\n" /* line 61 | source */
        "movl 0x84(%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002220cc, (%esp)\n" /* "^3Warning: file %s, line %d: %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x424, %esp\n" /* line 62 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void SourceWarning(source_t *source, char *str) { }
#endif

/* line 348 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int PC_StringizeTokens(token_t *tokens, token_t *token)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 348 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edx\n" /* tokens */
        "movl 0xc(%ebp), %esi\n" /* token */
        /* { scope 1 */
        "movl $1, 0x400(%esi)\n" /* line 352 | token */
        "movl $0, 0x420(%esi)\n" /* line 353 | token */
        "movl $0, 0x424(%esi)\n" /* line 354 | token */
        "movb $0, (%esi)\n" /* line 355 | token */
        "cld\n" /* line 356 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movw $0x22, -1(%ecx, %esi)\n"
        "testl %edx, %edx\n" /* line 357 */
        "je .Lfbe0b8_000be135\n"
        "movl %edx, %ebx\n" /* t */
        ".Lfbe0b8_000be103:\n"
        "cld\n" /* line 359 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* token */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl $0x400, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* t */
        "movl %esi, (%esp)\n" /* token */
        "calll strncat\n"
        "movl 0x430(%ebx), %ebx\n" /* line 357 | t */
        "testl %ebx, %ebx\n" /* t */
        "jne .Lfbe0b8_000be103\n"
        ".Lfbe0b8_000be135:\n"
        "cld\n" /* line 361 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl $0x401, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00222120, 4(%esp)\n" /* """ */
        "movl %esi, (%esp)\n" /* token */
        "calll strncat\n"
        /* } scope */
        "movl $1, %eax\n" /* line 363 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
int PC_StringizeTokens(token_t *tokens, token_t *token) { return 0; }
#endif

/* line 1490 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int PC_OperatorPriority(int op)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1490 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 1492 | op */
        "subl $5, %eax\n"
        "cmpl $0x26, %eax\n"
        "ja .Lfbe16e_000be183\n"
        "jmpl *.Ljt_be16e_0(, %eax, 4)\n"
        ".Lfbe16e_000be183:\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be187:\n"
        "movl $7, %eax\n" /* line 1492 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be18e:\n"
        "movl $6, %eax\n" /* line 1506 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be195:\n"
        "movl $0xb, %eax\n" /* line 1535 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be19c:\n"
        "movl $0xd, %eax\n" /* line 1535 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be1a3:\n"
        "movl $0xf, %eax\n" /* line 1535 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be1aa:\n"
        "movl $0xe, %eax\n" /* line 1535 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be1b1:\n"
        "movl $0xa, %eax\n" /* line 1508 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be1b8:\n"
        "movl $8, %eax\n" /* line 1531 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be1bf:\n"
        "movl $9, %eax\n" /* line 1533 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be1c6:\n"
        "movl $0x10, %eax\n" /* line 1535 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be1cd:\n"
        "movl $0xc, %eax\n" /* line 1535 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".Lfbe16e_000be1d4:\n"
        "movl $5, %eax\n" /* line 1492 */
        "popl %ebp\n" /* line 1545 */
        "retl\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_be16e_0:\n"
        ".long .Lfbe16e_000be187\n"
        ".long .Lfbe16e_000be18e\n"
        ".long .Lfbe16e_000be1cd\n"
        ".long .Lfbe16e_000be1cd\n"
        ".long .Lfbe16e_000be195\n"
        ".long .Lfbe16e_000be195\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be19c\n"
        ".long .Lfbe16e_000be19c\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be1a3\n"
        ".long .Lfbe16e_000be1a3\n"
        ".long .Lfbe16e_000be1a3\n"
        ".long .Lfbe16e_000be1aa\n"
        ".long .Lfbe16e_000be1aa\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be1b1\n"
        ".long .Lfbe16e_000be1b8\n"
        ".long .Lfbe16e_000be1bf\n"
        ".long .Lfbe16e_000be1c6\n"
        ".long .Lfbe16e_000be1c6\n"
        ".long .Lfbe16e_000be1cd\n"
        ".long .Lfbe16e_000be1cd\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be183\n"
        ".long .Lfbe16e_000be1d4\n"
        ".long .Lfbe16e_000be1d4\n"
        ".text\n"
    );
}
#else
int PC_OperatorPriority(int op) { return 0; }
#endif

/* line 2312 */
int PC_Directive_line(source_t *source)
{
    SourceError(source, "#line directive not supported");
    return 0;
}

/* line 3150 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int PC_SourceFileAndLine(int handle, char *filename, int *line)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3150 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* handle */
        /* { scope 1 */
        "leal -1(%edx), %eax\n" /* line 3154 */
        "cmpl $0x3e, %eax\n"
        "ja .Lfbe1fc_000be245\n"
        "movl sourceFiles(, %edx, 4), %eax\n" /* line 3156 */
        "testl %eax, %eax\n"
        "je .Lfbe1fc_000be245\n"
        "movl 0x84(%eax), %ebx\n" /* line 3159 | scriptstack */
        "testl %ebx, %ebx\n" /* line 3160 | scriptstack */
        "je .Lfbe1fc_000be24d\n"
        "movl %ebx, 4(%esp)\n" /* line 3162 | scriptstack */
        "movl 0xc(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl 0x5c(%ebx), %eax\n" /* line 3163 | scriptstack */
        "movl 0x10(%ebp), %edx\n" /* line */
        "movl %eax, (%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 3171 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbe1fc_000be245:\n"
        "xorl %eax, %eax\n" /* line 3168 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 3171 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbe1fc_000be24d:\n"
        "movl %eax, 4(%esp)\n" /* line 3167 */
        "movl 0xc(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl 0x10(%ebp), %edx\n" /* line 3168 | line */
        "movl $0, (%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 3171 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
int PC_SourceFileAndLine(int handle, char *filename, int *line) { return 0; }
#endif

/* line 180 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int PC_ReadSourceToken(source_t *source, token_t *token)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 180 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* source */
        "movl 0xc(%ebp), %esi\n" /* token */
        /* { scope 1 */
        "movl 0x88(%ebx), %eax\n" /* line 187 | source */
        "testl %eax, %eax\n"
        "je .Lfbe272_000be2f3\n"
        ".Lfbe272_000be28a:\n"
        "movl $0x440, 8(%esp)\n" /* line 211 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* token */
        "calll memcpy\n"
        "movl 0x88(%ebx), %edx\n" /* line 213 | source */
        "movl 0x430(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x88(%ebx)\n" /* source */
        "movl %edx, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        ".Lfbe272_000be2bf:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lfbe272_000be2c4:\n"
        "addl $0x10, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbe272_000be2cb:\n"
        "movl 0x84(%ebx), %edx\n" /* line 203 | source */
        "movl 0x4c0(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfbe272_000be2c4\n"
        "movl %eax, 0x84(%ebx)\n" /* line 207 | source */
        "movl %edx, (%esp)\n" /* line 208 */
        "calll FreeScript\n"
        "movl 0x88(%ebx), %eax\n" /* line 187 | source */
        "testl %eax, %eax\n"
        "jne .Lfbe272_000be28a\n"
        ".Lfbe272_000be2f3:\n"
        "movl %esi, 4(%esp)\n" /* line 190 | token */
        "movl 0x84(%ebx), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll PS_ReadToken\n"
        "testl %eax, %eax\n"
        "jne .Lfbe272_000be2bf\n"
        "movl 0x84(%ebx), %eax\n" /* line 193 | source */
        "movl %eax, (%esp)\n"
        "calll EndOfScript\n"
        "testl %eax, %eax\n"
        "je .Lfbe272_000be2cb\n"
        "movl 0x94(%ebx), %edx\n" /* source */
        ".Lfbe272_000be321:\n"
        "testl %edx, %edx\n" /* line 196 */
        "je .Lfbe272_000be2cb\n"
        "movl 8(%edx), %eax\n"
        "cmpl 0x84(%ebx), %eax\n" /* source */
        "jne .Lfbe272_000be2cb\n"
        "movl $str_00222144, 4(%esp)\n" /* line 198 */
        "movl %ebx, (%esp)\n" /* source */
        "calll SourceWarning\n"
        /* { scope 2 */
        "movl 0x94(%ebx), %edx\n" /* line 98 */
        "movl %edx, %ecx\n"
        "testl %edx, %edx\n" /* line 99 */
        "je .Lfbe272_000be2cb\n"
        "movl 8(%edx), %eax\n" /* line 103 */
        "cmpl 0x84(%ebx), %eax\n"
        "jne .Lfbe272_000be321\n"
        "movl 0xc(%edx), %edx\n" /* line 108 */
        "movl %edx, 0x94(%ebx)\n"
        "movl 0x98(%ebx), %eax\n" /* line 109 */
        "subl 4(%ecx), %eax\n"
        "movl %eax, 0x98(%ebx)\n"
        "movl %ecx, (%esp)\n" /* line 110 */
        "calll FreeMemory\n"
        "movl 0x94(%ebx), %edx\n"
        "jmp .Lfbe272_000be321\n"
    );
}

/* line 2325 */
__attribute__((naked))
int PC_Directive_error(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2325 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x450, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1 */
        "leal -0x448(%ebp), %ebx\n" /* line 2329 | token */
        "movb $0, -0x448(%ebp)\n" /* token */
        "movl %ebx, 4(%esp)\n" /* line 2330 */
        "movl %esi, (%esp)\n" /* source */
        "calll PC_ReadSourceToken\n"
        "movl %ebx, 8(%esp)\n" /* line 2331 */
        "movl $str_00222154, 4(%esp)\n" /* "#error directive: %s" */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceError\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 2333 */
        "addl $0x450, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1428 */
__attribute__((naked))
int PC_Directive_else(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1428 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* source */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x94(%ebx), %edx\n" /* line 98 */
        "testl %edx, %edx\n" /* line 99 */
        "je .Lfbe3cc_000be3ed\n"
        "movl 8(%edx), %eax\n" /* line 103 */
        "cmpl 0x84(%ebx), %eax\n"
        "je .Lfbe3cc_000be407\n"
        /* } scope */
        ".Lfbe3cc_000be3ed:\n"
        "movl $str_0022216c, 4(%esp)\n" /* line 1435 */
        "movl %ebx, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfbe3cc_000be3ff:\n"
        "addl $0x1c, %esp\n" /* line 1445 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfbe3cc_000be407:\n"
        "movl (%edx), %esi\n" /* line 106 */
        "movl 4(%edx), %edi\n" /* line 107 */
        "movl 0xc(%edx), %eax\n" /* line 108 */
        "movl %eax, 0x94(%ebx)\n"
        "movl 0x98(%ebx), %eax\n" /* line 109 */
        "subl 4(%edx), %eax\n"
        "movl %eax, 0x98(%ebx)\n"
        "movl %edx, (%esp)\n" /* line 110 */
        "calll FreeMemory\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 1433 | type */
        "je .Lfbe3cc_000be3ed\n"
        "cmpl $2, %esi\n" /* line 1438 | type */
        "je .Lfbe3cc_000be476\n"
        "movl $0x10, (%esp)\n" /* line 75 */
        "calll GetMemory\n"
        "movl $2, (%eax)\n" /* line 76 */
        "movl 0x84(%ebx), %edx\n" /* line 77 */
        "movl %edx, 8(%eax)\n"
        "xorl %edx, %edx\n" /* line 78 */
        "testl %edi, %edi\n"
        "sete %dl\n"
        "movl %edx, 4(%eax)\n"
        "addl %edx, 0x98(%ebx)\n" /* line 79 */
        "movl 0x94(%ebx), %edx\n" /* line 80 */
        "movl %edx, 0xc(%eax)\n"
        "movl %eax, 0x94(%ebx)\n" /* line 81 */
        "movl $1, %eax\n"
        "jmp .Lfbe3cc_000be3ff\n"
        ".Lfbe3cc_000be476:\n"
        "movl $str_0022217c, 4(%esp)\n" /* line 1440 */
        "movl %ebx, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfbe3cc_000be3ff\n"
    );
}

/* line 1454 */
__attribute__((naked))
int PC_Directive_endif(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1454 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x94(%esi), %edx\n" /* line 98 */
        "testl %edx, %edx\n" /* line 99 */
        "je .Lfbe48e_000be4ae\n"
        "movl 8(%edx), %eax\n" /* line 103 */
        "cmpl 0x84(%esi), %eax\n"
        "je .Lfbe48e_000be4c7\n"
        /* } scope */
        ".Lfbe48e_000be4ae:\n"
        "movl $str_00222190, 4(%esp)\n" /* line 1461 */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfbe48e_000be4c0:\n"
        "addl $0x10, %esp\n" /* line 1465 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfbe48e_000be4c7:\n"
        "movl (%edx), %ebx\n" /* line 106 */
        "movl 0xc(%edx), %eax\n" /* line 108 */
        "movl %eax, 0x94(%esi)\n"
        "movl 0x98(%esi), %eax\n" /* line 109 */
        "subl 4(%edx), %eax\n"
        "movl %eax, 0x98(%esi)\n"
        "movl %edx, (%esp)\n" /* line 110 */
        "calll FreeMemory\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1459 | type */
        "je .Lfbe48e_000be4ae\n"
        "movl $1, %eax\n"
        "jmp .Lfbe48e_000be4c0\n"
    );
}

/* line 1570 */
__attribute__((naked))
int PC_EvaluateTokens(source_t *source, token_t *tokens, long int *intvalue, double *floatvalue, int integer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1570 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xb6c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* tokens */
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1593 | intvalue */
        "testl %eax, %eax\n"
        "je .Lfbe4f4_000be513\n"
        "movl 0x10(%ebp), %eax\n" /* line 1594 | intvalue */
        "movl $0, (%eax)\n"
        ".Lfbe4f4_000be513:\n"
        "movl 0x14(%ebp), %edi\n" /* line 1595 | floatvalue */
        "testl %edi, %edi\n"
        "je .Lfbe4f4_000be52a\n"
        "movl 0x14(%ebp), %edx\n" /* line 1596 | floatvalue */
        "movl $0, (%edx)\n"
        "movl $0, 4(%edx)\n"
        ".Lfbe4f4_000be52a:\n"
        "testl %esi, %esi\n" /* line 1597 | tokens */
        "je .Lfbe4f4_000bea6b\n"
        "movl %esi, %ebx\n" /* tokens, t */
        "xorl %ecx, %ecx\n"
        "movl $0, -0xb28(%ebp)\n" /* numoperators */
        "movl $0, -0xb24(%ebp)\n" /* numvalues */
        "movl $0, -0xb44(%ebp)\n" /* lastoperator */
        "movl $0, -0xb3c(%ebp)\n" /* lastvalue */
        "movl $0, -0xb34(%ebp)\n" /* parentheses */
        "xorl %edx, %edx\n"
        "movl $0, -0xb48(%ebp)\n" /* firstoperator */
        "movl $0, -0xb40(%ebp)\n" /* firstvalue */
        ".Lfbe4f4_000be57e:\n"
        "movl 0x400(%ebx), %eax\n" /* line 1599 | t */
        "cmpl $4, %eax\n"
        "je .Lfbe4f4_000be65c\n"
        "cmpl $5, %eax\n"
        "je .Lfbe4f4_000be8a5\n"
        "cmpl $3, %eax\n"
        "je .Lfbe4f4_000be92e\n"
        "movl %ebx, 8(%esp)\n" /* line 1816 | t */
        "movl $str_00222358, 4(%esp)\n" /* "unknown %s in #if/#elif" */
        "movl 8(%ebp), %edi\n" /* source */
        "movl %edi, (%esp)\n"
        "calll SourceError\n"
        ".Lfbe4f4_000be5b6:\n"
        "movl $1, %edx\n" /* line 1987 */
        ".Lfbe4f4_000be5bb:\n"
        "movl -0xb40(%ebp), %eax\n" /* line 2031 | firstvalue */
        "testl %eax, %eax\n"
        "je .Lfbe4f4_000be5f2\n"
        "movl 0x10(%ebp), %eax\n" /* line 2033 | intvalue */
        "testl %eax, %eax\n"
        "je .Lfbe4f4_000be5d9\n"
        "movl -0xb40(%ebp), %edi\n" /* line 2034 | firstvalue */
        "movl (%edi), %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* intvalue */
        "movl %eax, (%ecx)\n"
        ".Lfbe4f4_000be5d9:\n"
        "movl 0x14(%ebp), %edi\n" /* line 2035 | floatvalue */
        "testl %edi, %edi\n"
        "je .Lfbe4f4_000be5f2\n"
        "movl -0xb40(%ebp), %edi\n" /* line 2036 | firstvalue */
        "movsd 4(%edi), %xmm0\n"
        "movl 0x14(%ebp), %eax\n" /* floatvalue */
        "movsd %xmm0, (%eax)\n"
        ".Lfbe4f4_000be5f2:\n"
        "movl -0xb48(%ebp), %esi\n" /* line 2038 | firstoperator, definehash */
        "testl %esi, %esi\n" /* definehash */
        "je .Lfbe4f4_000be609\n"
        "movl -0xb48(%ebp), %eax\n" /* firstoperator */
        ".Lfbe4f4_000be602:\n"
        "movl 0x10(%eax), %eax\n" /* line 2040 */
        "testl %eax, %eax\n" /* line 2038 */
        "jne .Lfbe4f4_000be602\n"
        ".Lfbe4f4_000be609:\n"
        "movl -0xb40(%ebp), %eax\n" /* line 2043 | firstvalue */
        "testl %eax, %eax\n"
        "je .Lfbe4f4_000be620\n"
        "movl -0xb40(%ebp), %eax\n" /* firstvalue */
        ".Lfbe4f4_000be619:\n"
        "movl 0x14(%eax), %eax\n" /* line 2045 */
        "testl %eax, %eax\n" /* line 2043 */
        "jne .Lfbe4f4_000be619\n"
        ".Lfbe4f4_000be620:\n"
        "testl %edx, %edx\n" /* line 2048 */
        "je .Lfbe4f4_000be91e\n"
        "movl 0x10(%ebp), %ebx\n" /* line 2050 | intvalue, t */
        "testl %ebx, %ebx\n" /* t */
        "je .Lfbe4f4_000be638\n"
        "movl 0x10(%ebp), %edx\n" /* line 2051 | intvalue */
        "movl $0, (%edx)\n"
        ".Lfbe4f4_000be638:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 2052 | floatvalue */
        "testl %ecx, %ecx\n"
        "je .Lfbe4f4_000be64f\n"
        "movl 0x14(%ebp), %ecx\n" /* line 2053 | floatvalue */
        "movl $0, (%ecx)\n"
        "movl $0, 4(%ecx)\n"
        ".Lfbe4f4_000be64f:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0xb6c, %esp\n" /* line 2055 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbe4f4_000be65c:\n"
        "testl %edx, %edx\n" /* line 1603 */
        "jne .Lfbe4f4_000bef98\n"
        "testl %ecx, %ecx\n"
        "jne .Lfbe4f4_000bef98\n"
        "movl $str_002221c0, %edi\n" /* line 1609 */
        "movl $8, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* t, tokens */
        "repe cmpsb %es:(%edi), (%esi)\n" /* tokens */
        "movl $0, %edx\n"
        "je .Lfbe4f4_000be68c\n"
        "movzbl -1(%esi), %edx\n" /* tokens */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfbe4f4_000be68c:\n"
        "testl %edx, %edx\n"
        "jne .Lfbe4f4_000befbb\n"
        "movl 0x430(%ebx), %ebx\n" /* line 1615 | t */
        "movl $str_002221e8, %edi\n" /* line 1616 */
        "movl $2, %ecx\n"
        "movl %ebx, %esi\n" /* t, tokens */
        "repe cmpsb %es:(%edi), (%esi)\n" /* tokens */
        "movl $0, %edx\n"
        "je .Lfbe4f4_000be6b9\n"
        "movzbl -1(%esi), %edx\n" /* tokens */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfbe4f4_000be6b9:\n"
        "testl %edx, %edx\n"
        "je .Lfbe4f4_000be9d5\n"
        "movl $0, -0xb38(%ebp)\n" /* brace */
        ".Lfbe4f4_000be6cb:\n"
        "testl %ebx, %ebx\n" /* line 1621 | t */
        "je .Lfbe4f4_000bef80\n"
        "cmpl $4, 0x400(%ebx)\n" /* t */
        "jne .Lfbe4f4_000bef80\n"
        "cmpl $0x3f, -0xb24(%ebp)\n" /* line 1628 | numvalues */
        "jg .Lfbe4f4_000befef\n"
        "movl -0xb24(%ebp), %edx\n" /* numvalues */
        "leal (%edx, %edx, 2), %eax\n"
        "leal -0xb18(%ebp, %eax, 8), %eax\n"
        "movl %eax, -0xb64(%ebp)\n"
        "addl $1, %edx\n"
        "movl %edx, -0xb24(%ebp)\n" /* numvalues */
        "movl 8(%ebp), %ecx\n" /* line 1629 | source */
        "movl 0x90(%ecx), %esi\n" /* definehash */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        "movzbl (%ebx), %eax\n" /* line 405 */
        "testb %al, %al\n"
        "jne .Lfbe4f4_000be9ea\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfbe4f4_000be726:\n"
        "xorl %edx, %ecx\n" /* line 444 */
        "xorl %eax, %ecx\n"
        "andl $0x3ff, %ecx\n"
        "movl (%esi, %ecx, 4), %esi\n" /* d */
        "testl %esi, %esi\n" /* d */
        "je .Lfbe4f4_000be754\n"
        ".Lfbe4f4_000be737:\n"
        "movl %ebx, 4(%esp)\n" /* line 446 */
        "movl (%esi), %eax\n" /* d */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfbe4f4_000beaa3\n"
        "movl 0x1c(%esi), %esi\n" /* line 444 | d */
        "testl %esi, %esi\n" /* d */
        "jne .Lfbe4f4_000be737\n"
        /* } scope */
        /* } scope */
        ".Lfbe4f4_000be754:\n"
        "movl -0xb64(%ebp), %edi\n" /* line 1636 */
        "movl $0, (%edi)\n"
        "movl $0, 4(%edi)\n" /* line 1637 */
        "movl $0, 8(%edi)\n"
        ".Lfbe4f4_000be76e:\n"
        "movl -0xb34(%ebp), %edx\n" /* line 1639 | parentheses */
        "movl -0xb64(%ebp), %eax\n"
        "movl %edx, 0xc(%eax)\n"
        "movl $0, 0x14(%eax)\n" /* line 1640 */
        "movl -0xb3c(%ebp), %ecx\n" /* line 1641 | lastvalue */
        "movl %ecx, 0x10(%eax)\n"
        "testl %ecx, %ecx\n" /* line 1642 */
        "je .Lfbe4f4_000beac2\n"
        "movl -0xb64(%ebp), %eax\n" /* line 1643 */
        "movl -0xb3c(%ebp), %edi\n" /* lastvalue */
        "movl %eax, 0x14(%edi)\n"
        ".Lfbe4f4_000be7a4:\n"
        "movl -0xb38(%ebp), %esi\n" /* line 1647 | brace, definehash */
        "testl %esi, %esi\n" /* definehash */
        "je .Lfbe4f4_000be7ee\n"
        "movl 0x430(%ebx), %ebx\n" /* line 1649 | t */
        "testl %ebx, %ebx\n" /* line 1650 | t */
        "je .Lfbe4f4_000befd7\n"
        "movl $str_00222224, -0xb4c(%ebp)\n" /* ")" */
        "movl $2, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* t, definehash */
        "movl $str_00222224, %edi\n" /* ")" */
        "repe cmpsb %es:(%edi), (%esi)\n" /* definehash */
        "movl $0, %edx\n"
        "je .Lfbe4f4_000be7e6\n"
        "movzbl -1(%esi), %edx\n" /* definehash */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfbe4f4_000be7e6:\n"
        "testl %edx, %edx\n"
        "jne .Lfbe4f4_000befd7\n"
        ".Lfbe4f4_000be7ee:\n"
        "movl -0xb64(%ebp), %eax\n" /* line 1816 */
        "movl %eax, -0xb3c(%ebp)\n" /* lastvalue */
        "movl $1, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lfbe4f4_000be801:\n"
        "movl 0x430(%ebx), %ebx\n" /* line 1597 | t */
        "testl %ebx, %ebx\n" /* t */
        "jne .Lfbe4f4_000be57e\n"
        "testl %edx, %edx\n" /* line 1826 */
        "je .Lfbe4f4_000bea7f\n"
        "movl -0xb34(%ebp), %eax\n" /* line 1831 | parentheses */
        "testl %eax, %eax\n"
        "jne .Lfbe4f4_000bef43\n"
        "movl -0xb48(%ebp), %edx\n" /* line 1842 | firstoperator */
        "testl %edx, %edx\n"
        "je .Lfbe4f4_000bec0d\n"
        "movl $0, -0xb30(%ebp)\n" /* questmarkintvalue */
        "pxor %xmm1, %xmm1\n"
        "movapd %xmm1, %xmm2\n"
        "movl $0, -0xb2c(%ebp)\n" /* gotquestmarkvalue */
        ".Lfbe4f4_000be84f:\n"
        "movl -0xb40(%ebp), %ebx\n" /* line 1867 | firstvalue, t */
        "movl -0xb48(%ebp), %esi\n" /* firstoperator, definehash */
        "jmp .Lfbe4f4_000be874\n"
        ".Lfbe4f4_000be85d:\n"
        "movl (%esi), %eax\n" /* line 1860 | definehash */
        "subl $0x23, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lfbe4f4_000be86a\n"
        "movl 0x14(%ebx), %ebx\n" /* line 1861 | t */
        ".Lfbe4f4_000be86a:\n"
        "testl %ebx, %ebx\n" /* line 1863 | t */
        "je .Lfbe4f4_000bef2b\n"
        "movl %edx, %esi\n" /* definehash */
        ".Lfbe4f4_000be874:\n"
        "movl 0x10(%esi), %edx\n" /* line 1845 | definehash */
        "testl %edx, %edx\n"
        "je .Lfbe4f4_000be88d\n"
        "movl 8(%edx), %eax\n" /* line 1849 */
        "cmpl %eax, 8(%esi)\n" /* definehash */
        "jg .Lfbe4f4_000be88d\n"
        "jne .Lfbe4f4_000be85d\n" /* line 1852 */
        "movl 4(%esi), %eax\n" /* line 1856 | definehash */
        "cmpl 4(%edx), %eax\n"
        "jl .Lfbe4f4_000be85d\n"
        ".Lfbe4f4_000be88d:\n"
        "movl 0x14(%ebx), %edi\n" /* line 1873 | t */
        "movl (%esi), %edx\n" /* line 1875 | definehash */
        "leal -5(%edx), %eax\n"
        "cmpl $0x26, %eax\n"
        "ja .Lfbe4f4_000bebba\n"
        "jmpl *CorrectSolidDeltas+6032(, %eax, 4)\n"
        ".Lfbe4f4_000be8a5:\n"
        "testl %ecx, %ecx\n" /* line 1698 */
        "jne .Lfbe4f4_000bf023\n"
        "movl 0x404(%ebx), %eax\n" /* line 1704 | t */
        "cmpl $0x2c, %eax\n"
        "je .Lfbe4f4_000bea97\n"
        "cmpl $0x2d, %eax\n" /* line 1709 */
        "je .Lfbe4f4_000bea2a\n"
        "movl 0x18(%ebp), %ecx\n" /* line 1720 | integer */
        "testl %ecx, %ecx\n"
        "jne .Lfbe4f4_000be90b\n"
        "cmpl $0x23, %eax\n" /* line 1722 */
        "je .Lfbe4f4_000bf007\n"
        "cmpl $0x1c, %eax\n"
        "je .Lfbe4f4_000bf007\n"
        "cmpl $0x15, %eax\n"
        "je .Lfbe4f4_000bf007\n"
        "cmpl $0x16, %eax\n"
        "je .Lfbe4f4_000bf007\n"
        "cmpl $0x20, %eax\n"
        "je .Lfbe4f4_000bf007\n"
        "cmpl $0x21, %eax\n"
        "je .Lfbe4f4_000bf007\n"
        "cmpl $0x22, %eax\n"
        "je .Lfbe4f4_000bf007\n"
        ".Lfbe4f4_000be90b:\n"
        "subl $5, %eax\n" /* line 1729 */
        "cmpl $0x26, %eax\n"
        "ja .Lfbe4f4_000bea4f\n"
        "jmpl *CorrectSolidDeltas+6188(, %eax, 4)\n"
        ".Lfbe4f4_000be91e:\n"
        "movl $1, %eax\n" /* line 2048 */
        /* } scope */
        "addl $0xb6c, %esp\n" /* line 2055 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbe4f4_000be92e:\n"
        "testl %edx, %edx\n" /* line 1664 */
        "jne .Lfbe4f4_000bf053\n"
        "cmpl $0x3f, -0xb24(%ebp)\n" /* line 1671 | numvalues */
        "jg .Lfbe4f4_000bf03b\n"
        "movl -0xb24(%ebp), %edx\n" /* numvalues */
        "leal (%edx, %edx, 2), %eax\n"
        "leal -0xb18(%ebp, %eax, 8), %edx\n"
        "addl $1, -0xb24(%ebp)\n" /* numvalues */
        "testl %ecx, %ecx\n" /* line 1672 */
        "je .Lfbe4f4_000bea14\n"
        "movl 0x408(%ebx), %eax\n" /* line 1674 | t */
        "negl %eax\n"
        "movl %eax, (%edx)\n"
        "fldt 0x410(%ebx)\n" /* line 1675 | t */
        "fstpl -0xb20(%ebp)\n"
        "fldl -0xb20(%ebp)\n"
        "fstpl -0xb60(%ebp)\n"
        "movsd -0xb60(%ebp), %xmm0\n"
        "xorpd CorrectSolidDeltas+6016, %xmm0\n"
        "movsd %xmm0, 4(%edx)\n"
        ".Lfbe4f4_000be999:\n"
        "movl -0xb34(%ebp), %eax\n" /* line 1682 | parentheses */
        "movl %eax, 0xc(%edx)\n"
        "movl $0, 0x14(%edx)\n" /* line 1683 */
        "movl -0xb3c(%ebp), %ecx\n" /* line 1684 | lastvalue */
        "movl %ecx, 0x10(%edx)\n"
        "testl %ecx, %ecx\n" /* line 1685 */
        "je .Lfbe4f4_000bef15\n"
        "movl -0xb3c(%ebp), %edi\n" /* line 1686 | lastvalue */
        "movl %edx, 0x14(%edi)\n"
        "movl %edx, -0xb3c(%ebp)\n" /* lastvalue */
        "movl $1, %edx\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lfbe4f4_000be801\n"
        ".Lfbe4f4_000be9d5:\n"
        "movl 0x430(%ebx), %ebx\n" /* line 1619 | t */
        "movl $1, -0xb38(%ebp)\n" /* brace */
        "jmp .Lfbe4f4_000be6cb\n"
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfbe4f4_000be9ea:\n"
        "xorl %ecx, %ecx\n" /* line 405 */
        "movl $0x77, %edx\n"
        ".Lfbe4f4_000be9f1:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0x76(%ebx, %edx), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfbe4f4_000be9f1\n"
        "movl %ecx, %edx\n"
        "sarl $0xa, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x14, %eax\n"
        "jmp .Lfbe4f4_000be726\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfbe4f4_000bea14:\n"
        "movl 0x408(%ebx), %eax\n" /* line 1679 | t */
        "movl %eax, (%edx)\n"
        "fldt 0x410(%ebx)\n" /* line 1680 | t */
        "fstpl 4(%edx)\n"
        "jmp .Lfbe4f4_000be999\n"
        ".Lfbe4f4_000bea2a:\n"
        "subl $1, -0xb34(%ebp)\n" /* line 1712 | parentheses */
        "jns .Lfbe4f4_000be801\n"
        "movl $str_0022226c, 4(%esp)\n" /* line 1714 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bea4f:\n"
        "movl %ebx, 8(%esp)\n" /* line 1792 | t */
        "movl $str_0022231c, 4(%esp)\n" /* "invalid operator %s in #if/#elif" */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bea6b:\n"
        "movl $0, -0xb48(%ebp)\n" /* line 1597 | firstoperator */
        "movl $0, -0xb40(%ebp)\n" /* firstvalue */
        ".Lfbe4f4_000bea7f:\n"
        "movl $str_00222370, 4(%esp)\n" /* line 1828 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bea97:\n"
        "addl $1, -0xb34(%ebp)\n" /* line 1706 | parentheses */
        "jmp .Lfbe4f4_000be801\n"
        ".Lfbe4f4_000beaa3:\n"
        "movl -0xb64(%ebp), %edi\n" /* line 1631 */
        "movl $1, (%edi)\n"
        "movl $0, 4(%edi)\n" /* line 1632 */
        "movl $0x3ff00000, 8(%edi)\n"
        "jmp .Lfbe4f4_000be76e\n"
        ".Lfbe4f4_000beac2:\n"
        "movl %eax, -0xb40(%ebp)\n" /* line 1642 | firstvalue */
        "jmp .Lfbe4f4_000be7a4\n"
        "movl $str_002222d8, 4(%esp)\n" /* line 1745 */
        "movl 8(%ebp), %edi\n" /* source */
        "movl %edi, (%esp)\n"
        "calll SourceError\n"
        ".Lfbe4f4_000beae0:\n"
        "cmpl $0x3f, -0xb28(%ebp)\n" /* line 1799 | numoperators */
        "jg .Lfbe4f4_000bf072\n"
        "movl -0xb28(%ebp), %ecx\n" /* numoperators */
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal -0x518(%ebp, %eax, 4), %edx\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0xb28(%ebp)\n" /* numoperators */
        "movl 0x404(%ebx), %eax\n" /* line 1800 | t */
        "movl %eax, (%edx)\n"
        "movl 0x404(%ebx), %eax\n" /* line 1492 */
        "subl $5, %eax\n"
        "cmpl $0x26, %eax\n"
        "ja .Lfbe4f4_000bec14\n"
        "jmpl *CorrectSolidDeltas+6344(, %eax, 4)\n"
        "testl %edx, %edx\n" /* line 1734 */
        "je .Lfbe4f4_000beae0\n"
        "movl $str_002222b8, 4(%esp)\n" /* line 1736 */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        "testl %edx, %edx\n" /* line 1782 */
        "jne .Lfbe4f4_000beae0\n"
        "movl %ebx, 8(%esp)\n" /* line 1784 | t */
        "movl $str_002222f4, 4(%esp)\n" /* "operator %s after operator in #if/#elif" */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        "testl %edx, %edx\n" /* line 1750 */
        "jne .Lfbe4f4_000beae0\n"
        "movl $1, %ecx\n" /* line 1816 */
        "jmp .Lfbe4f4_000be801\n"
        "movl (%ebx), %eax\n" /* line 1920 | t */
        "testl %eax, %eax\n"
        "jne .Lfbe4f4_000bf0c5\n"
        "movl (%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfbe4f4_000bf0c5\n"
        "xorl %eax, %eax\n"
        ".Lfbe4f4_000beb8b:\n"
        "movl %eax, (%ebx)\n" /* t */
        "ucomisd 4(%ebx), %xmm1\n" /* line 1921 | t */
        "jne .Lfbe4f4_000becf5\n"
        "jp .Lfbe4f4_000becf5\n"
        "ucomisd 4(%edi), %xmm1\n"
        "jne .Lfbe4f4_000becf5\n"
        "jp .Lfbe4f4_000becf5\n"
        ".Lfbe4f4_000bebaf:\n"
        "movapd %xmm1, %xmm0\n" /* line 1945 */
        ".Lfbe4f4_000bebb3:\n"
        "movsd %xmm0, 4(%ebx)\n" /* line 1896 | t */
        "movl (%esi), %edx\n" /* definehash */
        ".Lfbe4f4_000bebba:\n"
        "leal -0x23(%edx), %eax\n" /* line 2002 */
        "cmpl $1, %eax\n"
        "jbe .Lfbe4f4_000bebe4\n"
        "cmpl $0x2b, %edx\n" /* line 2005 */
        "je .Lfbe4f4_000bebcc\n"
        "movl %edi, %ebx\n" /* line 2006 | t */
        "movl 0x14(%edi), %edi\n"
        ".Lfbe4f4_000bebcc:\n"
        "movl 0x10(%ebx), %eax\n" /* line 2008 | t */
        "testl %eax, %eax\n"
        "je .Lfbe4f4_000befb0\n"
        "movl %edi, 0x14(%eax)\n" /* line 2009 */
        "movl 0x14(%ebx), %edi\n" /* t */
        ".Lfbe4f4_000bebdd:\n"
        "testl %edi, %edi\n" /* line 2013 */
        "je .Lfbe4f4_000bebe4\n"
        "movl %eax, 0x10(%edi)\n" /* line 2014 */
        ".Lfbe4f4_000bebe4:\n"
        "movl 0xc(%esi), %edx\n" /* line 2020 | definehash */
        "testl %edx, %edx\n"
        "je .Lfbe4f4_000bef70\n"
        "movl 0x10(%esi), %eax\n" /* line 2021 | definehash */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x10(%esi), %eax\n" /* definehash */
        ".Lfbe4f4_000bebf8:\n"
        "testl %eax, %eax\n" /* line 2025 */
        "je .Lfbe4f4_000bebff\n"
        "movl %edx, 0xc(%eax)\n" /* line 2026 */
        ".Lfbe4f4_000bebff:\n"
        "movl -0xb48(%ebp), %eax\n" /* line 1842 | firstoperator */
        "testl %eax, %eax\n"
        "jne .Lfbe4f4_000be84f\n"
        ".Lfbe4f4_000bec0d:\n"
        "xorl %edx, %edx\n"
        "jmp .Lfbe4f4_000be5bb\n"
        ".Lfbe4f4_000bec14:\n"
        "xorl %eax, %eax\n" /* line 1492 */
        ".Lfbe4f4_000bec16:\n"
        "movl %eax, 4(%edx)\n" /* line 1801 */
        "movl -0xb34(%ebp), %edi\n" /* line 1802 | parentheses */
        "movl %edi, 8(%edx)\n"
        "movl $0, 0x10(%edx)\n" /* line 1803 */
        "movl -0xb44(%ebp), %eax\n" /* line 1804 | lastoperator */
        "movl %eax, 0xc(%edx)\n"
        "testl %eax, %eax\n" /* line 1805 */
        "je .Lfbe4f4_000bef5b\n"
        "movl -0xb44(%ebp), %ecx\n" /* line 1806 | lastoperator */
        "movl %edx, 0x10(%ecx)\n"
        "movl %edx, -0xb44(%ebp)\n" /* lastoperator */
        "xorl %edx, %edx\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lfbe4f4_000be801\n"
        "movl $0xc, %eax\n" /* line 1492 */
        "jmp .Lfbe4f4_000bec16\n"
        "movl $7, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $6, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $0xb, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $0xd, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $0xf, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $0xe, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $0xa, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $8, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $9, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $0x10, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl $5, %eax\n"
        "jmp .Lfbe4f4_000bec16\n"
        "movl -0xb2c(%ebp), %eax\n" /* line 1985 | gotquestmarkvalue */
        "testl %eax, %eax\n"
        "jne .Lfbe4f4_000bf0ad\n"
        "movl (%ebx), %ecx\n" /* line 1991 | t */
        "movl %ecx, -0xb30(%ebp)\n" /* questmarkintvalue */
        "movsd 4(%ebx), %xmm2\n" /* line 1992 | t */
        "movl $1, -0xb2c(%ebp)\n" /* gotquestmarkvalue */
        "jmp .Lfbe4f4_000bebba\n"
        "movl (%ebx), %eax\n" /* line 1924 | t */
        "cmpl (%edi), %eax\n"
        "setge %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%ebx), %xmm0\n" /* line 1925 | t */
        "ucomisd 4(%edi), %xmm0\n"
        "jb .Lfbe4f4_000bebaf\n"
        ".Lfbe4f4_000becf5:\n"
        "movsd lit8_00307c10, %xmm0\n" /* line 1945 | 1.0 */
        "jmp .Lfbe4f4_000bebb3\n"
        "movl (%ebx), %eax\n" /* line 1944 | t */
        "cmpl (%edi), %eax\n"
        "setl %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%edi), %xmm0\n" /* line 1945 */
        "ucomisd 4(%ebx), %xmm0\n" /* t */
        "jbe .Lfbe4f4_000bebaf\n"
        "jmp .Lfbe4f4_000becf5\n"
        "movl -0xb2c(%ebp), %ecx\n" /* line 1964 | gotquestmarkvalue */
        "testl %ecx, %ecx\n"
        "je .Lfbe4f4_000bf11e\n"
        "movl 0x18(%ebp), %eax\n" /* line 1970 | integer */
        "testl %eax, %eax\n"
        "je .Lfbe4f4_000bf0fb\n"
        "movl -0xb30(%ebp), %eax\n" /* line 1972 | questmarkintvalue */
        "testl %eax, %eax\n"
        "jne .Lfbe4f4_000bf0ec\n"
        "movl (%edi), %eax\n" /* line 1973 */
        "movl %eax, (%ebx)\n" /* t */
        "movl $0, -0xb2c(%ebp)\n" /* gotquestmarkvalue */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        "movl (%ebx), %eax\n" /* line 1960 | t */
        "xorl (%edi), %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        "xorl %eax, %eax\n" /* line 1878 */
        "cmpl $0, (%ebx)\n" /* t */
        "sete %al\n"
        "movl %eax, (%ebx)\n" /* t */
        "ucomisd 4(%ebx), %xmm1\n" /* line 1879 | t */
        "jne .Lfbe4f4_000bebaf\n"
        ".Lfbe4f4_000bed7e:\n"
        "jnp .Lfbe4f4_000becf5\n" /* line 1933 */
        "jmp .Lfbe4f4_000bebaf\n"
        "movl (%ebx), %eax\n" /* line 1940 | t */
        "cmpl (%edi), %eax\n"
        "setg %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%ebx), %xmm0\n" /* line 1941 | t */
        "ucomisd 4(%edi), %xmm0\n"
        "ja .Lfbe4f4_000becf5\n"
        "jmp .Lfbe4f4_000bebaf\n"
        "movl (%ebx), %eax\n" /* line 1916 | t */
        "testl %eax, %eax\n"
        "je .Lfbe4f4_000bf06b\n"
        "movl (%edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfbe4f4_000bf06b\n"
        "movl $1, %eax\n"
        ".Lfbe4f4_000bedc3:\n"
        "movl %eax, (%ebx)\n" /* t */
        "ucomisd 4(%ebx), %xmm1\n" /* line 1917 | t */
        "jne .Lfbe4f4_000bedd2\n"
        "jnp .Lfbe4f4_000bebaf\n"
        ".Lfbe4f4_000bedd2:\n"
        "ucomisd 4(%edi), %xmm1\n"
        "jp .Lfbe4f4_000becf5\n"
        ".Lfbe4f4_000beddd:\n"
        "jne .Lfbe4f4_000becf5\n" /* line 1937 */
        "jmp .Lfbe4f4_000bebaf\n"
        "movl (%ebx), %eax\n" /* line 1928 | t */
        "cmpl (%edi), %eax\n"
        "setle %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%edi), %xmm0\n" /* line 1929 */
        "ucomisd 4(%ebx), %xmm0\n" /* t */
        "jae .Lfbe4f4_000becf5\n"
        "jmp .Lfbe4f4_000bebaf\n"
        "movl (%ebx), %eax\n" /* line 1932 | t */
        "cmpl (%edi), %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%ebx), %xmm0\n" /* line 1933 | t */
        "ucomisd 4(%edi), %xmm0\n"
        "jne .Lfbe4f4_000bebaf\n"
        "jmp .Lfbe4f4_000bed7e\n"
        "movl (%ebx), %eax\n" /* line 1936 | t */
        "cmpl (%edi), %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%ebx), %xmm0\n" /* line 1937 | t */
        "ucomisd 4(%edi), %xmm0\n"
        "jnp .Lfbe4f4_000beddd\n"
        "jmp .Lfbe4f4_000becf5\n"
        "movl (%edi), %ecx\n" /* line 1948 */
        "sarl %cl, (%ebx)\n" /* t */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        "movl (%edi), %ecx\n" /* line 1951 */
        "shll %cl, (%ebx)\n" /* t */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        "movl (%ebx), %eax\n" /* line 1885 | t */
        "imull (%edi), %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%ebx), %xmm0\n" /* line 1886 | t */
        "mulsd 4(%edi), %xmm0\n"
        "jmp .Lfbe4f4_000bebb3\n"
        "movl (%edi), %edx\n" /* line 1889 */
        "testl %edx, %edx\n"
        "je .Lfbe4f4_000bf090\n"
        "ucomisd 4(%edi), %xmm1\n"
        "je .Lfbe4f4_000bf08a\n"
        ".Lfbe4f4_000bee88:\n"
        "movl (%ebx), %eax\n" /* line 1895 | t */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%ebx), %xmm0\n" /* line 1896 | t */
        "divsd 4(%edi), %xmm0\n"
        "jmp .Lfbe4f4_000bebb3\n"
        "movl (%edi), %edx\n" /* line 1899 */
        "testl %edx, %edx\n"
        "je .Lfbe4f4_000bf0cf\n"
        "movl (%ebx), %eax\n" /* line 1905 | t */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "movl %edx, (%ebx)\n" /* t */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        "movl (%ebx), %eax\n" /* line 1908 | t */
        "addl (%edi), %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%ebx), %xmm0\n" /* line 1909 | t */
        "addsd 4(%edi), %xmm0\n"
        "movsd %xmm0, 4(%ebx)\n" /* t */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        "movl (%ebx), %eax\n" /* line 1954 | t */
        "andl (%edi), %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        "movl (%ebx), %eax\n" /* line 1957 | t */
        "orl (%edi), %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        "movl (%ebx), %eax\n" /* line 1912 | t */
        "subl (%edi), %eax\n"
        "movl %eax, (%ebx)\n" /* t */
        "movsd 4(%ebx), %xmm0\n" /* line 1913 | t */
        "subsd 4(%edi), %xmm0\n"
        "movsd %xmm0, 4(%ebx)\n" /* t */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        "notl (%ebx)\n" /* line 1882 | t */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        ".Lfbe4f4_000bef15:\n"
        "movl %edx, -0xb40(%ebp)\n" /* line 1685 | firstvalue */
        "movl %edx, -0xb3c(%ebp)\n" /* lastvalue */
        "movl $1, %edx\n"
        "jmp .Lfbe4f4_000be801\n"
        ".Lfbe4f4_000bef2b:\n"
        "movl $str_002223a8, 4(%esp)\n" /* line 1865 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bef43:\n"
        "movl $str_00222390, 4(%esp)\n" /* line 1833 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bef5b:\n"
        "movl %edx, -0xb44(%ebp)\n" /* line 1805 | lastoperator */
        "movl %edx, -0xb48(%ebp)\n" /* firstoperator */
        "xorl %edx, %edx\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lfbe4f4_000be801\n"
        ".Lfbe4f4_000bef70:\n"
        "movl 0x10(%esi), %esi\n" /* line 2023 | definehash */
        "movl %esi, -0xb48(%ebp)\n" /* definehash, firstoperator */
        "movl %esi, %eax\n" /* definehash */
        "jmp .Lfbe4f4_000bebf8\n"
        ".Lfbe4f4_000bef80:\n"
        "movl $str_002221ec, 4(%esp)\n" /* line 1623 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bef98:\n"
        "movl $str_002221a4, 4(%esp)\n" /* line 1605 */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000befb0:\n"
        "movl %edi, -0xb40(%ebp)\n" /* line 2011 | firstvalue */
        "jmp .Lfbe4f4_000bebdd\n"
        ".Lfbe4f4_000befbb:\n"
        "movl %ebx, 8(%esp)\n" /* line 1611 | t */
        "movl $str_002221c8, 4(%esp)\n" /* "undefined name %s in #if/#elif" */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000befd7:\n"
        "movl $str_00222228, 4(%esp)\n" /* line 1652 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000befef:\n"
        "movl $str_00222210, 4(%esp)\n" /* line 1628 */
        "movl 8(%ebp), %edi\n" /* source */
        "movl %edi, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bf007:\n"
        "movl %ebx, 8(%esp)\n" /* line 1724 | t */
        "movl $str_00222288, 4(%esp)\n" /* "illigal operator %s on floating point operands
" */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bf023:\n"
        "movl $str_00222248, 4(%esp)\n" /* line 1700 */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bf03b:\n"
        "movl $str_00222210, 4(%esp)\n" /* line 1671 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bf053:\n"
        "movl $str_002221a4, 4(%esp)\n" /* line 1666 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bf06b:\n"
        "xorl %eax, %eax\n" /* line 1916 */
        "jmp .Lfbe4f4_000bedc3\n"
        ".Lfbe4f4_000bf072:\n"
        "movl $str_00222340, 4(%esp)\n" /* line 1799 */
        "movl 8(%ebp), %edi\n" /* source */
        "movl %edi, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bf08a:\n"
        "jp .Lfbe4f4_000bee88\n" /* line 1889 */
        ".Lfbe4f4_000bf090:\n"
        "movl $str_002223c4, 4(%esp)\n" /* line 1891 */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "movl $1, %edx\n"
        "jmp .Lfbe4f4_000be5bb\n"
        ".Lfbe4f4_000bf0ad:\n"
        "movl $str_00222400, 4(%esp)\n" /* line 1987 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbe4f4_000be5b6\n"
        ".Lfbe4f4_000bf0c5:\n"
        "movl $1, %eax\n" /* line 1920 */
        "jmp .Lfbe4f4_000beb8b\n"
        ".Lfbe4f4_000bf0cf:\n"
        "movl $str_002223c4, 4(%esp)\n" /* line 1901 */
        "movl 8(%ebp), %edi\n" /* source */
        "movl %edi, (%esp)\n"
        "calll SourceError\n"
        "movl $1, %edx\n"
        "jmp .Lfbe4f4_000be5bb\n"
        ".Lfbe4f4_000bf0ec:\n"
        "movl $0, -0xb2c(%ebp)\n" /* line 1992 | gotquestmarkvalue */
        "jmp .Lfbe4f4_000bebba\n"
        ".Lfbe4f4_000bf0fb:\n"
        "ucomisd %xmm1, %xmm2\n" /* line 1977 */
        "jne .Lfbe4f4_000bf0ec\n"
        "jp .Lfbe4f4_000bf0ec\n"
        "movsd 4(%edi), %xmm0\n" /* line 1978 */
        "movsd %xmm0, 4(%ebx)\n" /* t */
        "movl $0, -0xb2c(%ebp)\n" /* gotquestmarkvalue */
        "movl (%esi), %edx\n" /* definehash */
        "jmp .Lfbe4f4_000bebba\n"
        ".Lfbe4f4_000bf11e:\n"
        "movl $str_002223e4, 4(%esp)\n" /* line 1966 */
        "movl 8(%ebp), %edi\n" /* source */
        "movl %edi, (%esp)\n"
        "calll SourceError\n"
        "movl $1, %edx\n"
        "jmp .Lfbe4f4_000be5bb\n"
    );
}

/* line 2990 */
__attribute__((naked))
void FreeSource(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2990 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, -0x1c(%ebp)\n" /* source */
        "movl 0x84(%eax), %edx\n" /* line 2999 */
        "testl %edx, %edx\n"
        "je .Lfbf13e_000bf17b\n"
        ".Lfbf13e_000bf157:\n"
        "movl 0x4c0(%edx), %eax\n" /* line 3002 */
        "movl -0x1c(%ebp), %ecx\n" /* source */
        "movl %eax, 0x84(%ecx)\n"
        "movl %edx, (%esp)\n" /* line 3003 */
        "calll FreeScript\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2999 | source */
        "movl 0x84(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfbf13e_000bf157\n"
        ".Lfbf13e_000bf17b:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 3006 | source */
        "movl 0x88(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfbf13e_000bf1b3\n"
        ".Lfbf13e_000bf188:\n"
        "movl 0x430(%edx), %eax\n" /* line 3009 */
        "movl -0x1c(%ebp), %ecx\n" /* source */
        "movl %eax, 0x88(%ecx)\n"
        "movl %edx, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        "movl -0x1c(%ebp), %eax\n" /* line 3006 | source */
        "movl 0x88(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfbf13e_000bf188\n"
        ".Lfbf13e_000bf1b3:\n"
        "xorl %edi, %edi\n" /* line 3013 */
        "movl -0x1c(%ebp), %ecx\n" /* source */
        "movl 0x90(%ecx), %eax\n"
        ".Lfbf13e_000bf1be:\n"
        "leal (%edi, %eax), %edx\n" /* line 3015 */
        "movl (%edx), %esi\n"
        "testl %esi, %esi\n"
        "je .Lfbf13e_000bf22e\n"
        ".Lfbf13e_000bf1c7:\n"
        "movl 0x1c(%esi), %eax\n" /* line 3018 */
        "movl %eax, (%edx)\n"
        "movl 0x10(%esi), %eax\n" /* line 506 */
        "testl %eax, %eax\n"
        "jne .Lfbf13e_000bf1d7\n"
        "jmp .Lfbf13e_000bf1f0\n"
        ".Lfbf13e_000bf1d5:\n"
        "movl %ebx, %eax\n"
        ".Lfbf13e_000bf1d7:\n"
        "movl 0x430(%eax), %ebx\n" /* line 508 */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 506 */
        "jne .Lfbf13e_000bf1d5\n"
        ".Lfbf13e_000bf1f0:\n"
        "movl 0x14(%esi), %eax\n" /* line 512 */
        "testl %eax, %eax\n"
        "jne .Lfbf13e_000bf1fb\n"
        "jmp .Lfbf13e_000bf214\n"
        ".Lfbf13e_000bf1f9:\n"
        "movl %ebx, %eax\n"
        ".Lfbf13e_000bf1fb:\n"
        "movl 0x430(%eax), %ebx\n" /* line 514 */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 512 */
        "jne .Lfbf13e_000bf1f9\n"
        ".Lfbf13e_000bf214:\n"
        "movl %esi, (%esp)\n" /* line 518 */
        "calll FreeMemory\n"
        "movl -0x1c(%ebp), %edx\n" /* line 3015 | source */
        "movl 0x90(%edx), %eax\n"
        "leal (%edi, %eax), %edx\n"
        "movl (%edx), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lfbf13e_000bf1c7\n"
        ".Lfbf13e_000bf22e:\n"
        "addl $4, %edi\n"
        "cmpl $__mh_execute_header, %edi\n" /* line 3013 */
        "jne .Lfbf13e_000bf1be\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 3024 | source */
        "movl 0x94(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfbf13e_000bf26d\n"
        ".Lfbf13e_000bf246:\n"
        "movl 0xc(%edx), %eax\n" /* line 3027 */
        "movl -0x1c(%ebp), %ecx\n" /* source */
        "movl %eax, 0x94(%ecx)\n"
        "movl %edx, (%esp)\n" /* line 3028 */
        "calll FreeMemory\n"
        "movl -0x1c(%ebp), %eax\n" /* line 3024 | source */
        "movl 0x94(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfbf13e_000bf246\n"
        "movl 0x90(%eax), %eax\n"
        ".Lfbf13e_000bf26d:\n"
        "testl %eax, %eax\n" /* line 3031 */
        "je .Lfbf13e_000bf279\n"
        "movl %eax, (%esp)\n" /* line 3032 */
        "calll FreeMemory\n"
        ".Lfbf13e_000bf279:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 3034 | source */
        "movl %ecx, 8(%ebp)\n" /* source */
        "addl $0x2c, %esp\n" /* line 3035 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp FreeMemory\n" /* line 3034 */
    );
}

/* line 3075 */
__attribute__((naked))
int PC_FreeSourceHandle(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3075 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* handle */
        "leal -1(%ebx), %eax\n" /* line 3077 | handle */
        "cmpl $0x3e, %eax\n"
        "ja .Lfbf28c_000bf2c7\n"
        "movl sourceFiles(, %ebx, 4), %eax\n" /* line 3079 */
        "testl %eax, %eax\n"
        "je .Lfbf28c_000bf2c7\n"
        "movl %eax, (%esp)\n" /* line 3082 */
        "calll FreeSource\n"
        "movl $0, sourceFiles(, %ebx, 4)\n" /* line 3083 */
        "movl $1, %eax\n"
        "addl $0x14, %esp\n" /* line 3085 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfbf28c_000bf2c7:\n"
        "xorl %eax, %eax\n" /* line 3084 */
        "addl $0x14, %esp\n" /* line 3085 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2578 */
__attribute__((naked))
int PC_ReadDollarDirective(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2578 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        "movl 8(%ebp), %edi\n" /* source */
        /* { scope 1 */
        "leal -0x458(%ebp), %eax\n" /* line 2584 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* source */
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "je .Lfbf2d2_000bf3f6\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2590 */
        "testl %eax, %eax\n"
        "jle .Lfbf2d2_000bf372\n"
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbf2d2_000bf44f\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x458(%ebp), %edx\n" /* token */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfbf2d2_000bf343:\n"
        "movl 0x88(%edi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%edi)\n" /* line 232 | t */
        /* } scope */
        "movl $str_00222430, 4(%esp)\n" /* line 2593 */
        "movl %edi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfbf2d2_000bf367:\n"
        "addl $0x45c, %esp\n" /* line 2611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf2d2_000bf372:\n"
        "cmpl $4, -0x58(%ebp)\n" /* line 2597 */
        "je .Lfbf2d2_000bf413\n"
        /* { scope 2 */
        ".Lfbf2d2_000bf37c:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbf2d2_000bf468\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x458(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfbf2d2_000bf3bd:\n"
        "movl 0x88(%edi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%edi)\n" /* line 232 | t */
        /* } scope */
        "leal -0x458(%ebp), %edx\n" /* line 2609 | token */
        "movl %edx, 8(%esp)\n"
        "movl $str_00222448, 4(%esp)\n" /* "unknown precompiler directive %s" */
        "movl %edi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 2611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf2d2_000bf3f6:\n"
        "movl $str_00222418, 4(%esp)\n" /* line 2586 */
        "movl %edi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 2611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf2d2_000bf413:\n"
        "movl dollardirectives, %eax\n" /* line 2600 */
        "testl %eax, %eax\n"
        "je .Lfbf2d2_000bf37c\n"
        "xorl %esi, %esi\n" /* i */
        "movl $dollardirectives, %ebx\n" /* t */
        ".Lfbf2d2_000bf427:\n"
        "leal -0x458(%ebp), %edx\n" /* line 2602 | token */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfbf2d2_000bf481\n"
        "addl $1, %esi\n" /* line 2600 | i */
        "movl 8(%ebx), %eax\n" /* t */
        "addl $8, %ebx\n" /* t */
        "testl %eax, %eax\n"
        "jne .Lfbf2d2_000bf427\n"
        "jmp .Lfbf2d2_000bf37c\n"
        /* { scope 2 */
        ".Lfbf2d2_000bf44f:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbf2d2_000bf343\n"
        /* } scope */
        /* { scope 2 */
        ".Lfbf2d2_000bf468:\n"
        "movl $str_00222108, 4(%esp)\n" /* "EXE_ERR_OUT_OF_MEMORY" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbf2d2_000bf3bd\n"
        /* } scope */
        ".Lfbf2d2_000bf481:\n"
        "movl %edi, (%esp)\n" /* line 2604 | source */
        "calll *dollardirectives+4(, %esi, 8)\n"
        "jmp .Lfbf2d2_000bf367\n"
    );
}

/* line 2468 */
__attribute__((naked))
int PC_ReadDirective(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2468 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        "movl 8(%ebp), %edi\n" /* source */
        /* { scope 1 */
        "leal -0x458(%ebp), %eax\n" /* line 2474 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* source */
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "je .Lfbf490_000bf55d\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2480 */
        "testl %eax, %eax\n"
        "jle .Lfbf490_000bf530\n"
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbf490_000bf5af\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x458(%ebp), %edx\n" /* token */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfbf490_000bf501:\n"
        "movl 0x88(%edi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%edi)\n" /* line 232 | t */
        /* } scope */
        "movl $str_00222484, 4(%esp)\n" /* line 2483 */
        "movl %edi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfbf490_000bf525:\n"
        "addl $0x45c, %esp\n" /* line 2500 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf490_000bf530:\n"
        "cmpl $4, -0x58(%ebp)\n" /* line 2487 */
        "je .Lfbf490_000bf57a\n"
        ".Lfbf490_000bf536:\n"
        "leal -0x458(%ebp), %eax\n" /* line 2498 | token */
        "movl %eax, 8(%esp)\n"
        "movl $str_00222448, 4(%esp)\n" /* "unknown precompiler directive %s" */
        "movl %edi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 2500 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf490_000bf55d:\n"
        "movl $str_0022246c, 4(%esp)\n" /* line 2476 */
        "movl %edi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 2500 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf490_000bf57a:\n"
        "movl directives, %eax\n" /* line 2490 */
        "testl %eax, %eax\n"
        "je .Lfbf490_000bf536\n"
        "xorl %esi, %esi\n" /* i */
        "movl $directives, %ebx\n" /* t */
        ".Lfbf490_000bf58a:\n"
        "leal -0x458(%ebp), %edx\n" /* line 2492 | token */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfbf490_000bf5c8\n"
        "addl $1, %esi\n" /* line 2490 | i */
        "movl 8(%ebx), %eax\n" /* t */
        "addl $8, %ebx\n" /* t */
        "testl %eax, %eax\n"
        "jne .Lfbf490_000bf58a\n"
        "jmp .Lfbf490_000bf536\n"
        /* { scope 2 */
        ".Lfbf490_000bf5af:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbf490_000bf501\n"
        /* } scope */
        ".Lfbf490_000bf5c8:\n"
        "movl %edi, (%esp)\n" /* line 2494 | source */
        "calll *directives+4(, %esi, 8)\n"
        "jmp .Lfbf490_000bf525\n"
    );
}

/* line 833 */
__attribute__((naked))
int PC_Directive_include(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 833 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x49c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* source */
        /* { scope 1 */
        "movl 0x98(%ebx), %eax\n" /* line 839 | source */
        "testl %eax, %eax\n"
        "jle .Lfbf5d8_000bf601\n"
        /* { scope 2 */
        ".Lfbf5d8_000bf5f1:\n"
        "movl $1, %eax\n" /* line 128 */
        /* } scope */
        /* } scope */
        ".Lfbf5d8_000bf5f6:\n"
        "addl $0x49c, %esp\n" /* line 903 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf5d8_000bf601:\n"
        "leal -0x498(%ebp), %eax\n" /* line 842 | token */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* source */
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "je .Lfbf5d8_000bf61e\n"
        "movl -0x6c(%ebp), %eax\n" /* line 847 */
        "testl %eax, %eax\n"
        "jle .Lfbf5d8_000bf63b\n"
        ".Lfbf5d8_000bf61e:\n"
        "movl $str_0022249c, 4(%esp)\n" /* line 892 */
        "movl %ebx, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x49c, %esp\n" /* line 903 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf5d8_000bf63b:\n"
        "movl -0x98(%ebp), %eax\n" /* line 852 */
        "cmpl $1, %eax\n"
        "je .Lfbf5d8_000bf730\n"
        "cmpl $5, %eax\n" /* line 864 */
        "jne .Lfbf5d8_000bf61e\n"
        "cmpb $0x3c, -0x498(%ebp)\n" /* token */
        "jne .Lfbf5d8_000bf61e\n"
        "leal 0x40(%ebx), %eax\n" /* line 866 | source */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lfbf5d8_000bf6a6\n"
        ".Lfbf5d8_000bf66c:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 869 */
        "testl %eax, %eax\n"
        "jg .Lfbf5d8_000bf872\n"
        "cmpl $5, -0x98(%ebp)\n" /* line 874 */
        "jne .Lfbf5d8_000bf689\n"
        "cmpb $0x3e, -0x498(%ebp)\n" /* token */
        "je .Lfbf5d8_000bf6d5\n"
        ".Lfbf5d8_000bf689:\n"
        "movl $0x40, 8(%esp)\n" /* line 876 */
        "leal -0x498(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll strncat\n"
        ".Lfbf5d8_000bf6a6:\n"
        "leal -0x498(%ebp), %eax\n" /* line 867 | token */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* source */
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "jne .Lfbf5d8_000bf66c\n"
        ".Lfbf5d8_000bf6bc:\n"
        "cmpb $0x3e, -0x498(%ebp)\n" /* line 878 | token */
        "je .Lfbf5d8_000bf6d5\n"
        "movl $str_002224b8, 4(%esp)\n" /* line 880 */
        "movl %ebx, (%esp)\n" /* source */
        "calll SourceWarning\n"
        ".Lfbf5d8_000bf6d5:\n"
        "cmpb $0, -0x58(%ebp)\n" /* line 882 | path */
        "je .Lfbf5d8_000bf8ca\n"
        "leal -0x58(%ebp), %esi\n" /* path, ptr */
        /* { scope 2 */
        ".Lfbf5d8_000bf6e2:\n"
        "movzbl (%esi), %eax\n" /* line 806 | ptr */
        "testb %al, %al\n"
        "je .Lfbf5d8_000bf703\n"
        ".Lfbf5d8_000bf6e9:\n"
        "cmpb $0x5c, %al\n" /* line 808 */
        "je .Lfbf5d8_000bf7a9\n"
        "cmpb $0x2f, %al\n"
        "je .Lfbf5d8_000bf7a9\n"
        "addl $1, %esi\n" /* ptr */
        "movzbl (%esi), %eax\n" /* line 806 | ptr */
        "testb %al, %al\n"
        "jne .Lfbf5d8_000bf6e9\n"
        ".Lfbf5d8_000bf703:\n"
        "movzbl -0x58(%ebp), %eax\n" /* line 818 | path */
        "testb %al, %al\n"
        "je .Lfbf5d8_000bf82a\n"
        "leal -0x58(%ebp), %edx\n" /* path */
        "jmp .Lfbf5d8_000bf727\n"
        ".Lfbf5d8_000bf714:\n"
        "cmpb $0x5c, %al\n" /* line 820 */
        "je .Lfbf5d8_000bf72b\n"
        ".Lfbf5d8_000bf718:\n"
        "movzbl 1(%edx), %eax\n" /* line 818 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "je .Lfbf5d8_000bf82a\n"
        ".Lfbf5d8_000bf727:\n"
        "cmpb $0x2f, %al\n" /* line 820 */
        "jne .Lfbf5d8_000bf714\n"
        ".Lfbf5d8_000bf72b:\n"
        "movb $0x2f, (%edx)\n" /* line 821 */
        "jmp .Lfbf5d8_000bf718\n"
        /* } scope */
        ".Lfbf5d8_000bf730:\n"
        "leal -0x498(%ebp), %eax\n" /* line 854 | token */
        "movl %eax, (%esp)\n"
        "calll StripDoubleQuotes\n"
        "leal -0x498(%ebp), %esi\n" /* token, ptr */
        /* { scope 2 */
        ".Lfbf5d8_000bf744:\n"
        "movzbl (%esi), %eax\n" /* line 806 | ptr */
        "testb %al, %al\n"
        "je .Lfbf5d8_000bf75d\n"
        ".Lfbf5d8_000bf74b:\n"
        "cmpb $0x5c, %al\n" /* line 808 */
        "je .Lfbf5d8_000bf788\n"
        "cmpb $0x2f, %al\n"
        "je .Lfbf5d8_000bf788\n"
        "addl $1, %esi\n" /* ptr */
        "movzbl (%esi), %eax\n" /* line 806 | ptr */
        "testb %al, %al\n"
        "jne .Lfbf5d8_000bf74b\n"
        ".Lfbf5d8_000bf75d:\n"
        "movzbl -0x498(%ebp), %eax\n" /* line 818 | token */
        "testb %al, %al\n"
        "je .Lfbf5d8_000bf7bf\n"
        "leal -0x498(%ebp), %edx\n" /* token */
        "jmp .Lfbf5d8_000bf77f\n"
        ".Lfbf5d8_000bf770:\n"
        "cmpb $0x5c, %al\n" /* line 820 */
        "je .Lfbf5d8_000bf783\n"
        ".Lfbf5d8_000bf774:\n"
        "movzbl 1(%edx), %eax\n" /* line 818 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "je .Lfbf5d8_000bf7bf\n"
        ".Lfbf5d8_000bf77f:\n"
        "cmpb $0x2f, %al\n" /* line 820 */
        "jne .Lfbf5d8_000bf770\n"
        ".Lfbf5d8_000bf783:\n"
        "movb $0x2f, (%edx)\n" /* line 821 */
        "jmp .Lfbf5d8_000bf774\n"
        ".Lfbf5d8_000bf788:\n"
        "leal 1(%esi), %edx\n" /* line 808 | ptr */
        "movzbl 1(%esi), %eax\n" /* ptr */
        "cmpb $0x5c, %al\n"
        "je .Lfbf5d8_000bf79b\n"
        "cmpb $0x2f, %al\n"
        "je .Lfbf5d8_000bf79b\n"
        "movl %edx, %esi\n" /* ptr */
        "jmp .Lfbf5d8_000bf744\n"
        ".Lfbf5d8_000bf79b:\n"
        "movl %edx, 4(%esp)\n" /* line 810 */
        "movl %esi, (%esp)\n" /* ptr */
        "calll strcpy\n"
        "jmp .Lfbf5d8_000bf744\n"
        /* } scope */
        /* { scope 2 */
        ".Lfbf5d8_000bf7a9:\n"
        "leal 1(%esi), %edx\n" /* line 808 | ptr */
        "movzbl 1(%esi), %eax\n" /* ptr */
        "cmpb $0x5c, %al\n"
        "je .Lfbf5d8_000bf819\n"
        "cmpb $0x2f, %al\n"
        "je .Lfbf5d8_000bf819\n"
        "movl %edx, %esi\n" /* ptr */
        "jmp .Lfbf5d8_000bf6e2\n"
        /* } scope */
        ".Lfbf5d8_000bf7bf:\n"
        "leal -0x498(%ebp), %eax\n" /* line 856 | token */
        "movl %eax, (%esp)\n"
        "calll LoadScriptFile\n"
        "movl %eax, %edi\n" /* script */
        "testl %eax, %eax\n" /* line 857 */
        "je .Lfbf5d8_000bf8e1\n"
        /* { scope 2 */
        ".Lfbf5d8_000bf7d7:\n"
        "movl 0x84(%ebx), %eax\n" /* line 124 */
        "movl %eax, %esi\n" /* s */
        "testl %eax, %eax\n"
        "je .Lfbf5d8_000bf803\n"
        ".Lfbf5d8_000bf7e3:\n"
        "movl %edi, 4(%esp)\n" /* line 126 */
        "movl %esi, (%esp)\n" /* s */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfbf5d8_000bf859\n"
        "movl 0x4c0(%esi), %esi\n" /* line 124 | s */
        "testl %esi, %esi\n" /* s */
        "jne .Lfbf5d8_000bf7e3\n"
        "movl 0x84(%ebx), %eax\n"
        ".Lfbf5d8_000bf803:\n"
        "movl %eax, 0x4c0(%edi)\n" /* line 133 */
        "movl %edi, 0x84(%ebx)\n" /* line 134 */
        "movl $1, %eax\n"
        "jmp .Lfbf5d8_000bf5f6\n"
        /* } scope */
        /* { scope 2 */
        ".Lfbf5d8_000bf819:\n"
        "movl %edx, 4(%esp)\n" /* line 810 */
        "movl %esi, (%esp)\n" /* ptr */
        "calll strcpy\n"
        "jmp .Lfbf5d8_000bf6e2\n"
        /* } scope */
        ".Lfbf5d8_000bf82a:\n"
        "leal -0x58(%ebp), %eax\n" /* line 888 | path */
        "movl %eax, (%esp)\n"
        "calll LoadScriptFile\n"
        "movl %eax, %edi\n" /* script */
        ".Lfbf5d8_000bf837:\n"
        "testl %edi, %edi\n" /* line 896 | script */
        "jne .Lfbf5d8_000bf7d7\n"
        "leal -0x58(%ebp), %eax\n" /* line 898 | path */
        "movl %eax, 8(%esp)\n"
        "movl $str_002224fc, 4(%esp)\n" /* "file %s not found" */
        "movl %ebx, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfbf5d8_000bf5f6\n"
        /* { scope 2 */
        ".Lfbf5d8_000bf859:\n"
        "movl %edi, 8(%esp)\n" /* line 128 */
        "movl $str_002220f0, 4(%esp)\n" /* "%s recursively included" */
        "movl %ebx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfbf5d8_000bf5f1\n"
        /* } scope */
        /* { scope 2 */
        ".Lfbf5d8_000bf872:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n" /* s */
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbf5d8_000bf91a\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x498(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* s */
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 | s */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfbf5d8_000bf8b3:\n"
        "movl 0x88(%ebx), %eax\n" /* line 231 */
        "movl %eax, 0x430(%esi)\n" /* t */
        "movl %esi, 0x88(%ebx)\n" /* line 232 | t */
        "jmp .Lfbf5d8_000bf6bc\n"
        /* } scope */
        ".Lfbf5d8_000bf8ca:\n"
        "movl $str_002224d4, 4(%esp)\n" /* line 884 */
        "movl %ebx, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfbf5d8_000bf5f6\n"
        ".Lfbf5d8_000bf8e1:\n"
        "leal 0x40(%ebx), %eax\n" /* line 859 | source */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "leal -0x498(%ebp), %eax\n" /* line 860 | token */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll strcat\n"
        "leal -0x58(%ebp), %eax\n" /* line 861 | path */
        "movl %eax, (%esp)\n"
        "calll LoadScriptFile\n"
        "movl %eax, %edi\n" /* script */
        "jmp .Lfbf5d8_000bf837\n"
        /* { scope 2 */
        ".Lfbf5d8_000bf91a:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbf5d8_000bf8b3\n"
    );
}

/* line 243 */
__attribute__((naked))
int PC_ReadDefineParms(source_t *source, define_t *define, token_t * *parms, int maxparms)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 243 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        /* { scope 1 */
        "leal -0x458(%ebp), %ebx\n" /* line 248 | token */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "je .Lfbf932_000bfbb2\n"
        "movl 0xc(%ebp), %edx\n" /* line 254 | define */
        "movl 0xc(%edx), %eax\n"
        "cmpl 0x14(%ebp), %eax\n" /* maxparms */
        "jg .Lfbf932_000bfb3b\n"
        "testl %eax, %eax\n" /* line 260 */
        "jle .Lfbf932_000bf985\n"
        "xorl %eax, %eax\n"
        ".Lfbf932_000bf970:\n"
        "movl 0x10(%ebp), %edx\n" /* line 261 | parms */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 260 */
        "movl 0xc(%ebp), %edx\n" /* define */
        "cmpl 0xc(%edx), %eax\n"
        "jl .Lfbf932_000bf970\n"
        ".Lfbf932_000bf985:\n"
        "movl $2, %ecx\n" /* line 263 */
        "cld\n"
        "movl %ebx, %esi\n" /* t */
        "movl $str_002221e8, %edi\n" /* "(" */
        "repe cmpsb %es:(%edi), (%esi)\n" /* t */
        "movl $0, %eax\n"
        "je .Lfbf932_000bf9a5\n"
        "movzbl -1(%esi), %eax\n" /* t */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfbf932_000bf9a5:\n"
        "testl %eax, %eax\n"
        "jne .Lfbf932_000bfb62\n"
        "movl 0x14(%ebp), %ecx\n" /* line 272 | maxparms */
        "testl %ecx, %ecx\n"
        "jle .Lfbf932_000bfc27\n"
        "movl 0xc(%ebp), %eax\n" /* line 277 | define */
        "movl 0xc(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lfbf932_000bfbdb\n"
        "movl $0, -0x460(%ebp)\n" /* line 280 | indent */
        "movl $0, -0x464(%ebp)\n" /* numparms */
        "movl -0x464(%ebp), %edx\n" /* numparms */
        ".Lfbf932_000bf9e0:\n"
        "movl 0x10(%ebp), %eax\n" /* line 243 | parms */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x45c(%ebp)\n"
        "movl $0, (%edx)\n" /* line 282 */
        "movl $1, -0x468(%ebp)\n" /* lastcomma */
        "movl $0, -0x46c(%ebp)\n" /* last */
        "jmp .Lfbf932_000bfa19\n"
        ".Lfbf932_000bfa08:\n"
        "addl $1, -0x460(%ebp)\n" /* line 308 | indent */
        ".Lfbf932_000bfa0f:\n"
        "movl $0, -0x468(%ebp)\n" /* line 332 | lastcomma */
        ".Lfbf932_000bfa19:\n"
        "movl %ebx, 4(%esp)\n" /* line 288 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "je .Lfbf932_000bfbfe\n"
        "movl $str_0021f88c, %edi\n" /* line 294 */
        "movl $2, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* t */
        "repe cmpsb %es:(%edi), (%esi)\n" /* t */
        "movl $0, %edx\n"
        "je .Lfbf932_000bfa50\n"
        "movzbl -1(%esi), %edx\n" /* t */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfbf932_000bfa50:\n"
        "testl %edx, %edx\n"
        "jne .Lfbf932_000bfa62\n"
        "movl -0x460(%ebp), %eax\n" /* line 296 | indent */
        "testl %eax, %eax\n"
        "jle .Lfbf932_000bfc50\n"
        ".Lfbf932_000bfa62:\n"
        "movl $2, %ecx\n" /* line 306 */
        "cld\n"
        "movl %ebx, %esi\n" /* t */
        "movl $str_002221e8, %edi\n" /* "(" */
        "repe cmpsb %es:(%edi), (%esi)\n" /* t */
        "movl $0, %eax\n"
        "je .Lfbf932_000bfa82\n"
        "movzbl -1(%esi), %eax\n" /* t */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfbf932_000bfa82:\n"
        "testl %eax, %eax\n"
        "je .Lfbf932_000bfa08\n"
        "movl $str_00222224, %edi\n" /* line 311 */
        "movl $2, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* t */
        "repe cmpsb %es:(%edi), (%esi)\n" /* t */
        "movl $0, %edx\n"
        "je .Lfbf932_000bfaa6\n"
        "movzbl -1(%esi), %edx\n" /* t */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfbf932_000bfaa6:\n"
        "testl %edx, %edx\n"
        "jne .Lfbf932_000bfabf\n"
        "subl $1, -0x460(%ebp)\n" /* line 313 | indent */
        "movl -0x460(%ebp), %eax\n" /* indent */
        "testl %eax, %eax\n"
        "jle .Lfbf932_000bfce3\n"
        ".Lfbf932_000bfabf:\n"
        "movl -0x464(%ebp), %edx\n" /* line 324 | numparms */
        "movl 0xc(%ebp), %eax\n" /* define */
        "cmpl %edx, 0xc(%eax)\n"
        "jle .Lfbf932_000bfa0f\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbf932_000bfc9c\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfbf932_000bfb0c:\n"
        "movl $0, 0x430(%esi)\n" /* line 328 | t */
        "movl -0x46c(%ebp), %edi\n" /* line 329 | last */
        "testl %edi, %edi\n"
        "je .Lfbf932_000bfc89\n"
        "movl -0x46c(%ebp), %edx\n" /* line 330 | last */
        "movl %esi, 0x430(%edx)\n" /* t */
        "movl %esi, -0x46c(%ebp)\n" /* t, last */
        "jmp .Lfbf932_000bfa0f\n"
        ".Lfbf932_000bfb3b:\n"
        "movl 0x14(%ebp), %eax\n" /* line 256 | maxparms */
        "movl %eax, 8(%esp)\n"
        "movl $str_00222528, 4(%esp)\n" /* "define with more than %d parameters" */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfbf932_000bfb57:\n"
        "addl $0x47c, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfbf932_000bfb62:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbf932_000bfcca\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfbf932_000bfb9d:\n"
        "movl 8(%ebp), %edx\n" /* line 231 | source */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 0x430(%esi)\n" /* t */
        "movl %esi, 0x88(%edx)\n" /* line 232 | t */
        /* } scope */
        ".Lfbf932_000bfbb2:\n"
        "movl 0xc(%ebp), %edx\n" /* line 266 | define */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00222510, 4(%esp)\n" /* "define %s missing parms" */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x47c, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfbf932_000bfbdb:\n"
        "movl 0xc(%ebp), %edx\n" /* define */
        /* { scope 1 */
        ".Lfbf932_000bfbde:\n"
        "movl (%edx), %eax\n" /* line 279 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0022256c, 4(%esp)\n" /* "define %s has too many parms" */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lfbf932_000bfb57\n"
        ".Lfbf932_000bfbfe:\n"
        "movl 0xc(%ebp), %edx\n" /* line 290 | define */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0022258c, 4(%esp)\n" /* "define %s incomplete" */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x47c, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf932_000bfc27:\n"
        "movl 0xc(%ebp), %edx\n" /* line 274 | define */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0022254c, 4(%esp)\n" /* "define %s with too many parms" */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x47c, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbf932_000bfc50:\n"
        "movl -0x468(%ebp), %eax\n" /* line 298 | lastcomma */
        "testl %eax, %eax\n"
        "jne .Lfbf932_000bfcb5\n"
        ".Lfbf932_000bfc5a:\n"
        "xorl %eax, %eax\n" /* line 299 */
        ".Lfbf932_000bfc5c:\n"
        "addl $1, -0x464(%ebp)\n" /* line 336 | numparms */
        "testl %eax, %eax\n" /* line 270 */
        "jne .Lfbf932_000bfcfe\n"
        "movl -0x464(%ebp), %edx\n" /* line 272 | numparms */
        "cmpl %edx, 0x14(%ebp)\n" /* maxparms */
        "je .Lfbf932_000bfc27\n"
        "movl 0xc(%ebp), %eax\n" /* line 277 | define */
        "cmpl %edx, 0xc(%eax)\n"
        "jg .Lfbf932_000bf9e0\n"
        "movl %eax, %edx\n"
        "jmp .Lfbf932_000bfbde\n"
        ".Lfbf932_000bfc89:\n"
        "movl -0x45c(%ebp), %eax\n" /* line 332 */
        "movl %esi, (%eax)\n" /* t */
        "movl %esi, -0x46c(%ebp)\n" /* t, last */
        "jmp .Lfbf932_000bfa0f\n"
        ".Lfbf932_000bfc9c:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbf932_000bfb0c\n"
        ".Lfbf932_000bfcb5:\n"
        "movl $str_002225a4, 4(%esp)\n" /* line 299 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceWarning\n"
        "jmp .Lfbf932_000bfc5a\n"
        /* { scope 2 */
        ".Lfbf932_000bfcca:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbf932_000bfb9d\n"
        /* } scope */
        ".Lfbf932_000bfce3:\n"
        "movl 0xc(%ebp), %edx\n" /* line 315 | define */
        "movl 0xc(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* parms */
        "movl -4(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfbf932_000bfd08\n"
        "movl $1, %eax\n" /* line 288 */
        "jmp .Lfbf932_000bfc5c\n"
        ".Lfbf932_000bfcfe:\n"
        "movl $1, %eax\n" /* line 270 */
        "jmp .Lfbf932_000bfb57\n"
        ".Lfbf932_000bfd08:\n"
        "movl $str_002225b8, 4(%esp)\n" /* line 317 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceWarning\n"
        "movl $1, %eax\n"
        "jmp .Lfbf932_000bfc5c\n"
    );
}

/* line 565 */
__attribute__((naked))
int PC_ExpandBuiltinDefine(source_t *source, token_t *deftoken, define_t *define, token_t * *firsttoken, token_t * *lasttoken)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 565 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* deftoken */
        /* { scope 1 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbfd26_000bfe8f\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfbfd26_000bfd6d:\n"
        "movl 0x10(%ebp), %eax\n" /* line 572 | define */
        "movl 8(%eax), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lfbfd26_000bfe42\n"
        "jg .Lfbfd26_000bfda6\n"
        "subl $1, %eax\n"
        "je .Lfbfd26_000bff30\n"
        ".Lfbfd26_000bfd87:\n"
        "movl 0x14(%ebp), %eax\n" /* line 626 | firsttoken */
        "movl $0, (%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 627 | lasttoken */
        "movl $0, (%edx)\n"
        /* } scope */
        ".Lfbfd26_000bfd99:\n"
        "movl $1, %eax\n" /* line 632 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbfd26_000bfda6:\n"
        "cmpl $3, %eax\n" /* line 572 */
        "je .Lfbfd26_000bfea8\n"
        "cmpl $4, %eax\n"
        "jne .Lfbfd26_000bfd87\n"
        "movl $0, (%esp)\n" /* line 611 */
        "calll time\n"
        "movl %eax, -0x1c(%ebp)\n" /* t */
        "leal -0x1c(%ebp), %eax\n" /* line 612 | t */
        "movl %eax, (%esp)\n"
        "calll ctime\n"
        "movl %eax, -0x2c(%ebp)\n" /* curtime */
        "movw $0x22, (%esi)\n" /* line 613 | token */
        "movl $8, 8(%esp)\n" /* line 614 */
        "movl -0x2c(%ebp), %eax\n" /* curtime */
        "addl $0xb, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* token */
        "calll strncat\n"
        "xorl %ebx, %ebx\n" /* line 615 | deftoken */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* token */
        "movl %ebx, %eax\n" /* deftoken */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movw $0x22, -1(%ecx, %esi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 616 | curtime */
        "movl %eax, (%esp)\n"
        "calll free\n"
        "movl $4, 0x400(%esi)\n" /* line 617 | token */
        "cld\n" /* line 618 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* token */
        "movl %ebx, %eax\n" /* deftoken */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 0x404(%esi)\n" /* token */
        "movl 0x14(%ebp), %edx\n" /* line 619 | firsttoken */
        "movl %esi, (%edx)\n" /* token */
        "movl 0x18(%ebp), %edi\n" /* line 620 | lasttoken */
        "movl %esi, (%edi)\n" /* token */
        "jmp .Lfbfd26_000bfd99\n"
        ".Lfbfd26_000bfe42:\n"
        "movl 8(%ebp), %edi\n" /* line 587 | source */
        "movl 0x84(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* token */
        "calll strcpy\n"
        "movl $4, 0x400(%esi)\n" /* line 588 | token */
        "cld\n" /* line 589 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* token */
        ".Lfbfd26_000bfe6b:\n"
        "repne scasb %es:(%edi), %al\n" /* line 604 */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 0x404(%esi)\n" /* token */
        "movl 0x14(%ebp), %eax\n" /* line 605 | firsttoken */
        "movl %esi, (%eax)\n" /* token */
        "movl 0x18(%ebp), %edx\n" /* line 606 | lasttoken */
        "movl %esi, (%edx)\n" /* token */
        /* } scope */
        "movl $1, %eax\n" /* line 632 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbfd26_000bfe8f:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbfd26_000bfd6d\n"
        ".Lfbfd26_000bfea8:\n"
        "movl $0, (%esp)\n" /* line 596 */
        "calll time\n"
        "movl %eax, -0x1c(%ebp)\n" /* t */
        "leal -0x1c(%ebp), %eax\n" /* line 597 | t */
        "movl %eax, (%esp)\n"
        "calll ctime\n"
        "movl %eax, %ebx\n" /* deftoken */
        "movw $0x22, (%esi)\n" /* line 598 | token */
        "movl $7, 8(%esp)\n" /* line 599 */
        "leal 4(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* token */
        "calll strncat\n"
        "movl $4, 8(%esp)\n" /* line 600 */
        "leal 0x14(%ebx), %eax\n" /* deftoken */
        "movl %eax, 4(%esp)\n"
        "leal 7(%esi), %eax\n" /* token */
        "movl %eax, (%esp)\n"
        "calll strncat\n"
        "cld\n" /* line 601 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* token */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movw $0x22, -1(%ecx, %esi)\n"
        "movl %ebx, (%esp)\n" /* line 602 | deftoken */
        "calll free\n"
        "movl $4, 0x400(%esi)\n" /* line 603 | token */
        "cld\n" /* line 604 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* token */
        "xorl %eax, %eax\n"
        "jmp .Lfbfd26_000bfe6b\n"
        ".Lfbfd26_000bff30:\n"
        "movl 0x428(%ebx), %eax\n" /* line 576 | deftoken */
        "movl %eax, 8(%esp)\n"
        "movl $str_00215a64, 4(%esp)\n" /* "%d" */
        "movl %esi, (%esp)\n" /* token */
        "calll sprintf\n"
        "movl 0x428(%ebx), %eax\n" /* line 577 | deftoken */
        "movl %eax, 0x408(%esi)\n" /* token */
        "fildl 0x428(%ebx)\n" /* line 578 | deftoken */
        "fstpt 0x410(%esi)\n" /* token */
        "movl $3, 0x400(%esi)\n" /* line 579 | token */
        "movl $0x1008, 0x404(%esi)\n" /* line 580 | token */
        "movl 0x14(%ebp), %eax\n" /* line 581 | firsttoken */
        "movl %esi, (%eax)\n" /* token */
        "movl 0x18(%ebp), %edx\n" /* line 582 | lasttoken */
        "movl %esi, (%edx)\n" /* token */
        /* } scope */
        "movl $1, %eax\n" /* line 632 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 641 */
__attribute__((naked))
int PC_ExpandDefine(source_t *source, token_t *deftoken, define_t *define, token_t * *firsttoken, token_t * *lasttoken)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 641 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x67c, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 648 | define */
        "movl 8(%eax), %esi\n" /* t2 */
        "testl %esi, %esi\n" /* t2 */
        "jne .Lfbff8e_000c0379\n"
        "movl 0xc(%eax), %ebx\n" /* line 653 | parmnum */
        "testl %ebx, %ebx\n" /* parmnum */
        "jne .Lfbff8e_000c0127\n"
        "movl %eax, %edx\n"
        "movl 0x14(%edx), %esi\n" /* line 662 | t2 */
        "testl %esi, %esi\n" /* t2 */
        "je .Lfbff8e_000c0160\n"
        ".Lfbff8e_000bffc0:\n"
        "movl $0, -0x664(%ebp)\n" /* first */
        "movl $0, -0x660(%ebp)\n" /* last */
        ".Lfbff8e_000bffd4:\n"
        "cmpl $4, 0x400(%esi)\n" /* line 666 | t2 */
        "je .Lfbff8e_000c01e3\n"
        ".Lfbff8e_000bffe1:\n"
        "cmpw $0x23, (%esi)\n" /* line 688 | t2 */
        "jne .Lfbff8e_000c0179\n"
        "movl 0x430(%esi), %eax\n" /* line 691 | t2 */
        "movl %eax, -0x65c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lfbff8e_000c002e\n"
        /* { scope 2 */
        "movl 0x10(%ebp), %edx\n" /* line 485 | define */
        "movl 0x10(%edx), %edi\n" /* p */
        "testl %edi, %edi\n" /* p */
        "je .Lfbff8e_000c002e\n"
        "xorl %ebx, %ebx\n"
        ".Lfbff8e_000c0007:\n"
        "movl -0x65c(%ebp), %eax\n" /* line 487 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* p */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfbff8e_000c0304\n"
        "addl $1, %ebx\n" /* line 489 */
        "movl 0x430(%edi), %edi\n" /* line 485 | p */
        "testl %edi, %edi\n" /* p */
        "jne .Lfbff8e_000c0007\n"
        /* } scope */
        ".Lfbff8e_000c002e:\n"
        "movl $str_002225e8, 4(%esp)\n" /* line 710 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceWarning\n"
        ".Lfbff8e_000c0041:\n"
        "movl 0x430(%esi), %esi\n" /* line 662 | t2 */
        "testl %esi, %esi\n" /* t2 */
        "jne .Lfbff8e_000bffd4\n"
        "movl -0x664(%ebp), %eax\n" /* line 728 | first */
        "testl %eax, %eax\n"
        "je .Lfbff8e_000c0078\n"
        "movl -0x664(%ebp), %ebx\n" /* first, parmnum */
        ".Lfbff8e_000c005b:\n"
        "movl 0x430(%ebx), %edi\n" /* line 730 | parmnum, nextpt */
        "testl %edi, %edi\n" /* nextpt */
        "je .Lfbff8e_000c0078\n"
        ".Lfbff8e_000c0065:\n"
        "cmpw $0x2323, (%edi)\n" /* line 733 | nextpt */
        "je .Lfbff8e_000c00dd\n"
        ".Lfbff8e_000c006c:\n"
        "movl %edi, %ebx\n" /* line 749 | nextpt, parmnum */
        "movl 0x430(%ebx), %edi\n" /* line 730 | parmnum, nextpt */
        "testl %edi, %edi\n" /* nextpt */
        "jne .Lfbff8e_000c0065\n"
        ".Lfbff8e_000c0078:\n"
        "movl -0x664(%ebp), %edx\n" /* line 756 | first */
        "movl 0x14(%ebp), %eax\n" /* firsttoken */
        "movl %edx, (%eax)\n"
        "movl -0x660(%ebp), %edx\n" /* line 757 | last */
        "movl 0x18(%ebp), %eax\n" /* lasttoken */
        "movl %edx, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 759 | define */
        "movl 0xc(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfbff8e_000c00cd\n"
        "xorl %ebx, %ebx\n" /* parmnum */
        ".Lfbff8e_000c009a:\n"
        "movl -0x218(%ebp, %ebx, 4), %eax\n" /* line 761 */
        "testl %eax, %eax\n"
        "jne .Lfbff8e_000c00a9\n"
        "jmp .Lfbff8e_000c00c2\n"
        ".Lfbff8e_000c00a7:\n"
        "movl %edi, %eax\n" /* nextpt */
        ".Lfbff8e_000c00a9:\n"
        "movl 0x430(%eax), %edi\n" /* line 763 | nextpt */
        "movl %eax, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        "testl %edi, %edi\n" /* line 761 | nextpt */
        "jne .Lfbff8e_000c00a7\n"
        ".Lfbff8e_000c00c2:\n"
        "addl $1, %ebx\n" /* line 759 | parmnum */
        "movl 0x10(%ebp), %edx\n" /* define */
        "cmpl 0xc(%edx), %ebx\n" /* parmnum */
        "jl .Lfbff8e_000c009a\n"
        ".Lfbff8e_000c00cd:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lfbff8e_000c00d2:\n"
        "addl $0x67c, %esp\n" /* line 769 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbff8e_000c00dd:\n"
        "movl 0x430(%edi), %esi\n" /* line 736 | nextpt, t2 */
        "testl %esi, %esi\n" /* line 737 | t2 */
        "je .Lfbff8e_000c006c\n"
        "movl 0x400(%ebx), %eax\n" /* line 375 */
        "cmpl $4, %eax\n"
        "je .Lfbff8e_000c03ab\n"
        "subl $1, %eax\n" /* line 381 */
        "je .Lfbff8e_000c0404\n"
        ".Lfbff8e_000c00ff:\n"
        "movl %esi, 0xc(%esp)\n" /* line 741 | t2 */
        "movl %ebx, 8(%esp)\n" /* parmnum */
        "movl $str_00222618, 4(%esp)\n" /* "can't merge %s with %s" */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x67c, %esp\n" /* line 769 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfbff8e_000c0127:\n"
        "movl %eax, %edx\n"
        /* { scope 1 */
        "movl $0x80, 0xc(%esp)\n" /* line 655 */
        "leal -0x218(%ebp), %eax\n" /* parms */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll PC_ReadDefineParms\n"
        "testl %eax, %eax\n"
        "je .Lfbff8e_000c03de\n"
        "movl 0x10(%ebp), %edx\n" /* define */
        "movl 0x14(%edx), %esi\n" /* line 662 | t2 */
        "testl %esi, %esi\n" /* t2 */
        "jne .Lfbff8e_000bffc0\n"
        ".Lfbff8e_000c0160:\n"
        "movl $0, -0x660(%ebp)\n" /* line 749 | last */
        "movl $0, -0x664(%ebp)\n" /* first */
        "jmp .Lfbff8e_000c0078\n"
        ".Lfbff8e_000c0179:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbff8e_000c02eb\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%edi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfbff8e_000c01b4:\n"
        "movl $0, 0x430(%edi)\n" /* line 719 | nextpt */
        "movl -0x660(%ebp), %edx\n" /* line 720 | last */
        "testl %edx, %edx\n"
        "je .Lfbff8e_000c02da\n"
        "movl -0x660(%ebp), %edx\n" /* line 721 | last */
        "movl %edi, 0x430(%edx)\n" /* nextpt */
        ".Lfbff8e_000c01d8:\n"
        "movl %edi, -0x660(%ebp)\n" /* nextpt, last */
        "jmp .Lfbff8e_000c0041\n"
        /* { scope 2 */
        ".Lfbff8e_000c01e3:\n"
        "movl 0x10(%ebp), %eax\n" /* line 485 | define */
        "movl 0x10(%eax), %edi\n" /* p */
        "testl %edi, %edi\n" /* p */
        "je .Lfbff8e_000bffe1\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lfbff8e_000c0206\n"
        ".Lfbff8e_000c01f5:\n"
        "addl $1, %ebx\n" /* line 489 */
        "movl 0x430(%edi), %edi\n" /* line 485 | p */
        "testl %edi, %edi\n" /* p */
        "je .Lfbff8e_000bffe1\n"
        ".Lfbff8e_000c0206:\n"
        "movl %esi, 4(%esp)\n" /* line 487 */
        "movl %edi, (%esp)\n" /* p */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lfbff8e_000c01f5\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 671 | parmnum */
        "js .Lfbff8e_000bffe1\n"
        "movl -0x218(%ebp, %ebx, 4), %ebx\n" /* line 673 | parmnum */
        "testl %ebx, %ebx\n" /* parmnum */
        "je .Lfbff8e_000c0041\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbff8e_000c02aa\n"
        ".Lfbff8e_000c023f:\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%edi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        "movl $0, 0x430(%edi)\n" /* line 677 | nextpt */
        "movl -0x660(%ebp), %ecx\n" /* line 678 | last */
        "testl %ecx, %ecx\n"
        "je .Lfbff8e_000c02d2\n"
        ".Lfbff8e_000c0278:\n"
        "movl -0x660(%ebp), %edx\n" /* line 679 | last */
        "movl %edi, 0x430(%edx)\n" /* nextpt */
        ".Lfbff8e_000c0284:\n"
        "movl 0x430(%ebx), %ebx\n" /* line 673 | parmnum */
        "testl %ebx, %ebx\n" /* parmnum */
        "je .Lfbff8e_000c01d8\n"
        "movl %edi, -0x660(%ebp)\n" /* nextpt, last */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 149 */
        "jne .Lfbff8e_000c023f\n"
        ".Lfbff8e_000c02aa:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl $0, 0x430(%edi)\n" /* line 677 | nextpt */
        "movl -0x660(%ebp), %ecx\n" /* line 678 | last */
        "testl %ecx, %ecx\n"
        "jne .Lfbff8e_000c0278\n"
        ".Lfbff8e_000c02d2:\n"
        "movl %edi, -0x664(%ebp)\n" /* nextpt, first */
        "jmp .Lfbff8e_000c0284\n"
        ".Lfbff8e_000c02da:\n"
        "movl %edi, -0x660(%ebp)\n" /* line 720 | nextpt, last */
        "movl %edi, -0x664(%ebp)\n" /* nextpt, first */
        "jmp .Lfbff8e_000c0041\n"
        ".Lfbff8e_000c02eb:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfbff8e_000c01b4\n"
        ".Lfbff8e_000c0304:\n"
        "testl %ebx, %ebx\n" /* line 696 | parmnum */
        "js .Lfbff8e_000c002e\n"
        "leal -0x658(%ebp), %edx\n" /* line 701 | token */
        "movl %edx, 4(%esp)\n"
        "movl -0x218(%ebp, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll PC_StringizeTokens\n"
        "testl %eax, %eax\n"
        "je .Lfbff8e_000c03cb\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfbff8e_000c03e5\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x658(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%edi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        "movl -0x65c(%ebp), %esi\n"
        "jmp .Lfbff8e_000c01b4\n"
        ".Lfbff8e_000c0379:\n"
        "movl 0x18(%ebp), %edx\n" /* line 650 | lasttoken */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* firsttoken */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* define */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* deftoken */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll PC_ExpandBuiltinDefine\n"
        /* } scope */
        "addl $0x67c, %esp\n" /* line 769 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbff8e_000c03ab:\n"
        "movl 0x400(%esi), %eax\n" /* line 375 */
        "subl $3, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lfbff8e_000c00ff\n"
        "movl %esi, 4(%esp)\n" /* line 377 */
        "movl %ebx, (%esp)\n"
        "calll strcat\n"
        "jmp .Lfbff8e_000c0433\n"
        ".Lfbff8e_000c03cb:\n"
        "movl $str_002225d0, 4(%esp)\n" /* line 703 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        ".Lfbff8e_000c03de:\n"
        "xorl %eax, %eax\n"
        "jmp .Lfbff8e_000c00d2\n"
        ".Lfbff8e_000c03e5:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x65c(%ebp), %esi\n"
        "jmp .Lfbff8e_000c01b4\n"
        ".Lfbff8e_000c0404:\n"
        "cmpl $1, 0x400(%esi)\n" /* line 381 */
        "jne .Lfbff8e_000c00ff\n"
        "cld\n" /* line 384 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -2(%ecx, %ebx)\n"
        "leal 1(%esi), %eax\n" /* line 386 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcat\n"
        ".Lfbff8e_000c0433:\n"
        "movl 0x430(%ebx), %eax\n" /* line 169 */
        "movl %eax, (%esp)\n"
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        "movl 0x430(%esi), %eax\n" /* line 745 | t2 */
        "movl %eax, 0x430(%ebx)\n" /* parmnum */
        "cmpl %esi, -0x660(%ebp)\n" /* line 746 | t2, last */
        "je .Lfbff8e_000c0470\n"
        ".Lfbff8e_000c045c:\n"
        "movl %esi, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        "jmp .Lfbff8e_000c005b\n"
        ".Lfbff8e_000c0470:\n"
        "movl %ebx, -0x660(%ebp)\n" /* line 742 | parmnum, last */
        "jmp .Lfbff8e_000c045c\n"
    );
}

/* line 914 */
__attribute__((naked))
int PC_ReadLine(source_t *source, token_t *token)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 914 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* token */
        "xorl %esi, %esi\n" /* t */
        /* { scope 1: firsttoken, lasttoken */
        ".Lfc0478_000c0486:\n"
        "movl %ebx, 4(%esp)\n" /* line 922 | token */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "je .Lfc0478_000c05b2\n"
        "cmpl 0x42c(%ebx), %esi\n" /* line 925 | token, define */
        "jl .Lfc0478_000c05bc\n"
        "cmpl $4, 0x400(%ebx)\n" /* line 931 | token */
        "jne .Lfc0478_000c04f1\n"
        "movl 8(%ebp), %ecx\n" /* line 933 | source */
        "movl 0x90(%ecx), %esi\n" /* definehash */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl (%ebx), %eax\n" /* line 405 */
        "testb %al, %al\n"
        "jne .Lfc0478_000c051f\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfc0478_000c04c8:\n"
        "xorl %ecx, %edx\n" /* line 444 */
        "xorl %edx, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl (%esi, %eax, 4), %esi\n" /* t */
        "testl %esi, %esi\n" /* t */
        "je .Lfc0478_000c04f1\n"
        ".Lfc0478_000c04d8:\n"
        "movl %ebx, 4(%esp)\n" /* line 446 */
        "movl (%esi), %eax\n" /* t */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfc0478_000c0553\n"
        "movl 0x1c(%esi), %esi\n" /* line 444 | t */
        "testl %esi, %esi\n" /* t */
        "jne .Lfc0478_000c04d8\n"
        /* } scope */
        ".Lfc0478_000c04f1:\n"
        "movl $str_00222630, %edi\n" /* line 920 */
        "movl $2, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* token, define */
        "repe cmpsb %es:(%edi), (%esi)\n" /* define */
        "movl $0, %edx\n"
        "je .Lfc0478_000c0511\n"
        "movzbl -1(%esi), %edx\n" /* define */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfc0478_000c0511:\n"
        "testl %edx, %edx\n"
        "jne .Lfc0478_000c0546\n"
        "movl $1, %esi\n" /* define */
        "jmp .Lfc0478_000c0486\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc0478_000c051f:\n"
        "xorl %ecx, %ecx\n" /* line 405 */
        "movl $0x77, %edx\n"
        ".Lfc0478_000c0526:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0x76(%edx, %ebx), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc0478_000c0526\n"
        "movl %ecx, %edx\n"
        "sarl $0xa, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x14, %eax\n"
        "jmp .Lfc0478_000c04c8\n"
        /* } scope */
        /* } scope */
        ".Lfc0478_000c0546:\n"
        "movl $1, %eax\n" /* line 920 */
        /* } scope */
        ".Lfc0478_000c054b:\n"
        "addl $0x3c, %esp\n" /* line 947 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: firsttoken, lasttoken */
        /* { scope 2 */
        ".Lfc0478_000c0553:\n"
        "leal -0x20(%ebp), %eax\n" /* line 782 | lasttoken */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* firsttoken */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* t */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll PC_ExpandDefine\n"
        "testl %eax, %eax\n"
        "je .Lfc0478_000c05b2\n"
        "movl -0x1c(%ebp), %eax\n" /* line 785 | firsttoken */
        "testl %eax, %eax\n"
        "je .Lfc0478_000c05b2\n"
        "movl -0x20(%ebp), %edx\n" /* lasttoken */
        "testl %edx, %edx\n"
        "je .Lfc0478_000c05b2\n"
        "movl 8(%ebp), %ecx\n" /* line 787 | source */
        "movl 0x88(%ecx), %eax\n"
        "movl %eax, 0x430(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 788 | firsttoken */
        "movl %eax, 0x88(%ecx)\n"
        /* } scope */
        "movl %ebx, 4(%esp)\n" /* line 939 | token */
        "movl %ecx, (%esp)\n"
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "jne .Lfc0478_000c04f1\n"
        ".Lfc0478_000c05b2:\n"
        "xorl %eax, %eax\n" /* line 920 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 947 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: firsttoken, lasttoken */
        /* { scope 2 */
        ".Lfc0478_000c05bc:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc0478_000c060f\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc0478_000c05f3:\n"
        "movl 8(%ebp), %edx\n" /* line 231 | source */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 0x430(%esi)\n" /* t */
        "movl %esi, 0x88(%edx)\n" /* line 232 | t */
        "xorl %eax, %eax\n"
        "jmp .Lfc0478_000c054b\n"
        ".Lfc0478_000c060f:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc0478_000c05f3\n"
    );
}

/* line 3123 */
__attribute__((naked))
int PC_ReadLineHandle(int handle, pc_token_t *pc_token)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3123 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x46c, %esp\n"
        "movl 8(%ebp), %edx\n" /* handle */
        "movl 0xc(%ebp), %esi\n" /* pc_token */
        /* { scope 1 */
        "leal -1(%edx), %eax\n" /* line 3128 */
        "cmpl $0x3e, %eax\n"
        "ja .Lfc0626_000c069d\n"
        "movl sourceFiles(, %edx, 4), %eax\n" /* line 3130 */
        "testl %eax, %eax\n"
        "je .Lfc0626_000c069d\n"
        "leal -0x458(%ebp), %ebx\n" /* line 3133 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll PC_ReadLine\n"
        "movl %eax, %edi\n" /* ret */
        "leal 0x10(%esi), %eax\n" /* line 3134 | pc_token */
        "movl %eax, -0x460(%ebp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x58(%ebp), %eax\n" /* line 3135 */
        "movl %eax, (%esi)\n" /* pc_token */
        "movl -0x54(%ebp), %eax\n" /* line 3136 */
        "movl %eax, 4(%esi)\n" /* pc_token */
        "movl -0x50(%ebp), %eax\n" /* line 3137 */
        "movl %eax, 8(%esi)\n" /* pc_token */
        "fldt -0x48(%ebp)\n" /* line 3138 */
        "fstps 0xc(%esi)\n" /* pc_token */
        "cmpl $1, (%esi)\n" /* line 3139 | pc_token */
        "je .Lfc0626_000c06ac\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 3142 | ret */
        "addl $0x46c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc0626_000c069d:\n"
        "xorl %edi, %edi\n" /* line 3140 | ret */
        /* } scope */
        "movl %edi, %eax\n" /* line 3142 | ret */
        "addl $0x46c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc0626_000c06ac:\n"
        "movl -0x460(%ebp), %eax\n" /* line 3140 */
        "movl %eax, (%esp)\n"
        "calll StripDoubleQuotes\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 3142 | ret */
        "addl $0x46c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2342 */
__attribute__((naked))
int PC_Directive_pragma(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2342 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x450, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1 */
        "movl $str_00222634, 4(%esp)\n" /* line 2346 */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceWarning\n"
        "leal -0x448(%ebp), %ebx\n" /* token */
        ".Lfc06c8_000c06ec:\n"
        "movl %ebx, 4(%esp)\n" /* line 2347 */
        "movl %esi, (%esp)\n" /* source */
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "jne .Lfc06c8_000c06ec\n"
        /* } scope */
        "movb $1, %al\n" /* line 2349 */
        "addl $0x450, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1373 */
__attribute__((naked))
int PC_Directive_if_def(source_t *source, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1373 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1 */
        "leal -0x458(%ebp), %edi\n" /* line 1379 | token */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* source */
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "je .Lfc0708_000c083e\n"
        "cmpl $4, -0x58(%ebp)\n" /* line 1384 */
        "je .Lfc0708_000c07a5\n"
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc0708_000c0885\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc0708_000c0772:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        /* } scope */
        "movl %edi, 8(%esp)\n" /* line 1387 */
        "movl $str_00222668, 4(%esp)\n" /* "expected name after #ifdef, found %s" */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 1395 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc0708_000c07a5:\n"
        "movl 0x90(%esi), %ebx\n" /* line 1391 | source, definehash */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl -0x458(%ebp), %eax\n" /* line 405 | token */
        "testb %al, %al\n"
        "jne .Lfc0708_000c085b\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfc0708_000c07c0:\n"
        "xorl %edx, %ecx\n" /* line 444 */
        "xorl %ecx, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl (%ebx, %eax, 4), %ebx\n" /* t */
        "testl %ebx, %ebx\n" /* t */
        "je .Lfc0708_000c07e9\n"
        ".Lfc0708_000c07d0:\n"
        "movl %edi, 4(%esp)\n" /* line 446 */
        "movl (%ebx), %eax\n" /* t */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfc0708_000c07eb\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 444 | t */
        "testl %ebx, %ebx\n" /* t */
        "jne .Lfc0708_000c07d0\n"
        ".Lfc0708_000c07e9:\n"
        "xorl %ebx, %ebx\n" /* t */
        /* } scope */
        ".Lfc0708_000c07eb:\n"
        "movl $0x10, (%esp)\n" /* line 75 */
        "calll GetMemory\n"
        "movl 0xc(%ebp), %edx\n" /* line 76 | type */
        "movl %edx, (%eax)\n"
        "movl 0x84(%esi), %edx\n" /* line 77 */
        "movl %edx, 8(%eax)\n"
        "cmpl $8, 0xc(%ebp)\n" /* line 78 | type */
        "setne %dl\n"
        "testl %ebx, %ebx\n"
        "sete %cl\n"
        "xorb %cl, %dl\n"
        "movzbl %dl, %edx\n"
        "movl %edx, 4(%eax)\n"
        "addl %edx, 0x98(%esi)\n" /* line 79 */
        "movl 0x94(%esi), %edx\n" /* line 80 */
        "movl %edx, 0xc(%eax)\n"
        "movl %eax, 0x94(%esi)\n" /* line 81 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 1395 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc0708_000c083e:\n"
        "movl $str_00222654, 4(%esp)\n" /* line 1381 */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 1395 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc0708_000c085b:\n"
        "xorl %ecx, %ecx\n" /* line 405 */
        "movl $0x77, %edx\n"
        ".Lfc0708_000c0862:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0x76(%edx, %edi), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc0708_000c0862\n"
        "movl %ecx, %edx\n"
        "sarl $0xa, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x14, %eax\n"
        "jmp .Lfc0708_000c07c0\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfc0708_000c0885:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc0708_000c0772\n"
    );
}

/* line 1416 */
int PC_Directive_ifndef(source_t *source)
{
    return PC_Directive_if_def(source, 0x10);
}

/* line 1404 */
int PC_Directive_ifdef(source_t *source)
{
    return PC_Directive_if_def(source, 8);
}

/* line 982 */
__attribute__((naked))
int PC_Directive_undef(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 982 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x46c, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1 */
        "movl 0x98(%esi), %eax\n" /* line 988 | source */
        "testl %eax, %eax\n"
        "jle .Lfc08d6_000c08ff\n"
        ".Lfc08d6_000c08ef:\n"
        "movl $1, %eax\n" /* line 1010 */
        /* } scope */
        ".Lfc08d6_000c08f4:\n"
        "addl $0x46c, %esp\n" /* line 1026 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc08d6_000c08ff:\n"
        "leal -0x458(%ebp), %eax\n" /* line 991 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* source */
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "je .Lfc08d6_000c09f3\n"
        "cmpl $4, -0x58(%ebp)\n" /* line 996 */
        "je .Lfc08d6_000c0993\n"
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc08d6_000c0aa9\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x458(%ebp), %edx\n" /* token */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc08d6_000c0960:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        /* } scope */
        "leal -0x458(%ebp), %eax\n" /* line 999 | token */
        "movl %eax, 8(%esp)\n"
        "movl $str_002226a4, 4(%esp)\n" /* "expected name, found %s" */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc08d6_000c08f4\n"
        /* { scope 2 */
        ".Lfc08d6_000c0993:\n"
        "movzbl -0x458(%ebp), %eax\n" /* line 405 | token */
        "testb %al, %al\n"
        "jne .Lfc08d6_000c0a0a\n"
        "xorl %ecx, %ecx\n"
        "xorl %eax, %eax\n"
        "xorl %edx, %edx\n"
        /* } scope */
        ".Lfc08d6_000c09a4:\n"
        "xorl %eax, %ecx\n" /* line 1004 */
        "xorl %ecx, %edx\n"
        "andl $0x3ff, %edx\n"
        "movl 0x90(%esi), %eax\n" /* source */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x45c(%ebp)\n"
        "movl (%edx), %ebx\n" /* define */
        "testl %ebx, %ebx\n" /* define */
        "je .Lfc08d6_000c08ef\n"
        "xorl %edi, %edi\n" /* lastdefine */
        "jmp .Lfc08d6_000c09cf\n"
        ".Lfc08d6_000c09cb:\n"
        "movl %ebx, %edi\n" /* define, lastdefine */
        "movl %eax, %ebx\n" /* define */
        ".Lfc08d6_000c09cf:\n"
        "leal -0x458(%ebp), %edx\n" /* line 1006 | token */
        "movl %edx, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* define */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfc08d6_000c0a37\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1004 | define */
        "testl %eax, %eax\n"
        "jne .Lfc08d6_000c09cb\n"
        "jmp .Lfc08d6_000c08ef\n"
        ".Lfc08d6_000c09f3:\n"
        "movl $str_00222690, 4(%esp)\n" /* line 993 */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc08d6_000c08f4\n"
        /* { scope 2 */
        ".Lfc08d6_000c0a0a:\n"
        "xorl %ecx, %ecx\n" /* line 405 */
        "movl $0x77, %edx\n"
        ".Lfc08d6_000c0a11:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0x4ce(%edx, %ebp), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc08d6_000c0a11\n"
        "movl %ecx, %eax\n"
        "sarl $0xa, %eax\n"
        "movl %ecx, %edx\n"
        "sarl $0x14, %edx\n"
        "jmp .Lfc08d6_000c09a4\n"
        /* } scope */
        ".Lfc08d6_000c0a37:\n"
        "testb $1, 4(%ebx)\n" /* line 1008 | define */
        "jne .Lfc08d6_000c0ac2\n"
        "testl %edi, %edi\n" /* line 1014 | lastdefine */
        "je .Lfc08d6_000c0ae1\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1015 | define */
        "movl %eax, 0x1c(%edi)\n" /* lastdefine */
        ".Lfc08d6_000c0a4f:\n"
        "movl 0x10(%ebx), %eax\n" /* line 506 | t */
        "testl %eax, %eax\n"
        "jne .Lfc08d6_000c0a5a\n"
        "jmp .Lfc08d6_000c0a73\n"
        ".Lfc08d6_000c0a58:\n"
        "movl %esi, %eax\n"
        ".Lfc08d6_000c0a5a:\n"
        "movl 0x430(%eax), %esi\n" /* line 508 */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        /* } scope */
        "testl %esi, %esi\n" /* line 506 */
        "jne .Lfc08d6_000c0a58\n"
        ".Lfc08d6_000c0a73:\n"
        "movl 0x14(%ebx), %eax\n" /* line 512 | t */
        "testl %eax, %eax\n"
        "jne .Lfc08d6_000c0a7e\n"
        "jmp .Lfc08d6_000c0a97\n"
        ".Lfc08d6_000c0a7c:\n"
        "movl %esi, %eax\n"
        ".Lfc08d6_000c0a7e:\n"
        "movl 0x430(%eax), %esi\n" /* line 514 */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        /* } scope */
        "testl %esi, %esi\n" /* line 512 */
        "jne .Lfc08d6_000c0a7c\n"
        ".Lfc08d6_000c0a97:\n"
        "movl %ebx, (%esp)\n" /* line 518 | t */
        "calll FreeMemory\n"
        "movl $1, %eax\n"
        "jmp .Lfc08d6_000c08f4\n"
        /* { scope 2 */
        ".Lfc08d6_000c0aa9:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc08d6_000c0960\n"
        /* } scope */
        ".Lfc08d6_000c0ac2:\n"
        "leal -0x458(%ebp), %eax\n" /* line 1010 | token */
        "movl %eax, 8(%esp)\n"
        "movl $str_002226bc, 4(%esp)\n" /* "can't undef %s" */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceWarning\n"
        "jmp .Lfc08d6_000c08ef\n"
        ".Lfc08d6_000c0ae1:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1017 | define */
        "movl -0x45c(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "jmp .Lfc08d6_000c0a4f\n"
    );
}

/* line 2620 */
__attribute__((naked))
int PC_ReadToken(source_t *source, token_t *token)
{
    __asm__ __volatile__ (
        ".Lfc0af2_000c0af2:\n"
        "pushl %ebp\n" /* line 2620 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        "movl 0xc(%ebp), %ebx\n" /* token */
        /* { scope 1: newtoken, firsttoken, lasttoken */
        ".Lfc0af2_000c0b04:\n"
        "movl %ebx, 4(%esp)\n" /* line 2626 | token */
        "movl %esi, (%esp)\n" /* source */
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "je .Lfc0af2_000c0bd4\n"
        "movl 0x400(%ebx), %eax\n" /* line 2629 | token */
        "cmpl $5, %eax\n"
        "je .Lfc0af2_000c0bb1\n"
        "subl $1, %eax\n" /* line 2644 */
        "je .Lfc0af2_000c0be1\n"
        ".Lfc0af2_000c0b30:\n"
        "movl 0x98(%esi), %eax\n" /* line 2667 | source */
        "testl %eax, %eax\n"
        "jne .Lfc0af2_000c0b04\n"
        "cmpl $4, 0x400(%ebx)\n" /* line 2670 | token */
        "jne .Lfc0af2_000c0b87\n"
        "movl 0x90(%esi), %edi\n" /* line 2673 | source, definehash */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl (%ebx), %eax\n" /* line 405 */
        "testb %al, %al\n"
        "jne .Lfc0af2_000c0c5d\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfc0af2_000c0b5a:\n"
        "xorl %ecx, %edx\n" /* line 444 */
        "xorl %edx, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl (%edi, %eax, 4), %edi\n" /* t */
        "testl %edi, %edi\n" /* t */
        "je .Lfc0af2_000c0b87\n"
        ".Lfc0af2_000c0b6a:\n"
        "movl %ebx, 4(%esp)\n" /* line 446 */
        "movl (%edi), %eax\n" /* t */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfc0af2_000c0c87\n"
        "movl 0x1c(%edi), %edi\n" /* line 444 | t */
        "testl %edi, %edi\n" /* t */
        "jne .Lfc0af2_000c0b6a\n"
        /* } scope */
        ".Lfc0af2_000c0b87:\n"
        "leal 0xa0(%esi), %eax\n" /* line 2684 | source */
        "movl $0x440, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* token */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lfc0af2_000c0ba6:\n"
        "addl $0x47c, %esp\n" /* line 2688 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: newtoken, firsttoken, lasttoken */
        ".Lfc0af2_000c0bb1:\n"
        "movzbl (%ebx), %eax\n" /* line 2629 | token */
        "cmpb $0x23, %al\n"
        "je .Lfc0af2_000c0cdd\n"
        "cmpb $0x24, %al\n" /* line 2636 */
        "jne .Lfc0af2_000c0b30\n"
        "movl %esi, (%esp)\n" /* line 2639 | source */
        "calll PC_ReadDollarDirective\n"
        "testl %eax, %eax\n"
        "jne .Lfc0af2_000c0b04\n"
        ".Lfc0af2_000c0bd4:\n"
        "xorl %eax, %eax\n" /* line 2686 */
        /* } scope */
        ".Lfc0af2_000c0bd6:\n"
        "addl $0x47c, %esp\n" /* line 2688 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: newtoken, firsttoken, lasttoken */
        /* { scope 2 */
        ".Lfc0af2_000c0be1:\n"
        "leal -0x468(%ebp), %eax\n" /* line 2648 | newtoken */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* source */
        "calll PC_ReadToken\n"
        "testl %eax, %eax\n"
        "je .Lfc0af2_000c0b30\n"
        "cmpl $1, -0x68(%ebp)\n" /* line 2650 */
        "je .Lfc0af2_000c0cf4\n"
        /* { scope 3 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc0af2_000c0d46\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x468(%ebp), %ecx\n" /* newtoken */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%edi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc0af2_000c0c46:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%edi)\n" /* t */
        "movl %edi, 0x88(%esi)\n" /* line 232 | t */
        "jmp .Lfc0af2_000c0b30\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc0af2_000c0c5d:\n"
        "xorl %ecx, %ecx\n" /* line 405 */
        "movl $0x77, %edx\n"
        ".Lfc0af2_000c0c64:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0x76(%ebx, %edx), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc0af2_000c0c64\n"
        "movl %ecx, %edx\n"
        "sarl $0xa, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x14, %eax\n"
        "jmp .Lfc0af2_000c0b5a\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfc0af2_000c0c87:\n"
        "leal -0x20(%ebp), %eax\n" /* line 782 | lasttoken */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* firsttoken */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* t */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ExpandDefine\n"
        "testl %eax, %eax\n"
        "je .Lfc0af2_000c0bd4\n"
        "movl -0x1c(%ebp), %eax\n" /* line 785 | firsttoken */
        "testl %eax, %eax\n"
        "je .Lfc0af2_000c0bd4\n"
        "movl -0x20(%ebp), %edx\n" /* lasttoken */
        "testl %edx, %edx\n"
        "je .Lfc0af2_000c0bd4\n"
        "movl 0x88(%esi), %eax\n" /* line 787 */
        "movl %eax, 0x430(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 788 | firsttoken */
        "movl %eax, 0x88(%esi)\n"
        "jmp .Lfc0af2_000c0b04\n"
        /* } scope */
        ".Lfc0af2_000c0cdd:\n"
        "movl %esi, (%esp)\n" /* line 2632 | source */
        "calll PC_ReadDirective\n"
        "testl %eax, %eax\n"
        "jne .Lfc0af2_000c0b04\n"
        "xorl %eax, %eax\n" /* line 2686 */
        "jmp .Lfc0af2_000c0bd6\n"
        /* { scope 2 */
        ".Lfc0af2_000c0cf4:\n"
        "cld\n" /* line 2652 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* token, define */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* define */
        "notl %ecx\n"
        "movb $0, -2(%ecx, %ebx)\n"
        "movl $0xffffffff, %ecx\n" /* line 2653 */
        "movl %ebx, %edi\n" /* token, define */
        "repne scasb %es:(%edi), %al\n" /* define */
        "movl %ecx, %edx\n"
        "notl %edx\n"
        "movl $0xffffffff, %ecx\n"
        "leal -0x467(%ebp), %edi\n" /* define */
        "repne scasb %es:(%edi), %al\n" /* define */
        "notl %ecx\n"
        "leal -1(%ecx, %edx), %ecx\n"
        "cmpl $0x3ff, %ecx\n"
        "ja .Lfc0af2_000c0d5f\n"
        "leal -0x467(%ebp), %eax\n" /* line 2658 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* token */
        "calll strcat\n"
        "jmp .Lfc0af2_000c0b30\n"
        /* { scope 3 */
        ".Lfc0af2_000c0d46:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc0af2_000c0c46\n"
        /* } scope */
        ".Lfc0af2_000c0d5f:\n"
        "movl $0x400, 8(%esp)\n" /* line 2655 */
        "movl $str_002226cc, 4(%esp)\n" /* "string longer than MAX_TOKEN %d
" */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0af2_000c0ba6\n"
    );
}

/* line 3094 */
int PC_ReadTokenHandle(int handle, pc_token_t *pc_token)
{
    source_t *source;
    struct script_s *script;
    token_t token;
    int ret;

    if (handle <= 0 || handle >= 64) {
        return 0;
    }

    if (!sourceFiles[handle]) {
        return 0;
    }

    for (;;) {
        source = sourceFiles[handle];
        if (!source) {
            return 0;
        }

        script = (struct script_s *)source->scriptstack;
        while (script != NULL && script->script_p != NULL &&
               script->script_p < script->end_p && *script->script_p == '`') {
            ++script->script_p;
        }

        ret = PC_ReadToken(sourceFiles[handle], &token);
        if (ret) {
            strcpy(pc_token->string, token.string);
            pc_token->type = token.type;
            pc_token->subtype = token.subtype;
            pc_token->intvalue = token.intvalue;
            pc_token->floatvalue = token.floatvalue;
            if (pc_token->type == 1) {
                StripDoubleQuotes(pc_token->string);
            }
            return ret;
        }

        source = sourceFiles[handle];
        if (!source) {
            return 0;
        }

        script = (struct script_s *)source->scriptstack;
        if (!script || !script->script_p || script->script_p >= script->end_p ||
            *script->script_p != '`') {
            return 0;
        }

        ++script->script_p;
    }
}

/* line 1035 */
__attribute__((naked))
int PC_Directive_define(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1035 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8dc, %esp\n"
        /* { scope 1: tok */
        "movl 8(%ebp), %eax\n" /* line 1040 | source */
        "movl 0x98(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lfc0e22_000c0e4b\n"
        ".Lfc0e22_000c0e3b:\n"
        "movl $1, %eax\n" /* line 1163 */
        /* } scope */
        ".Lfc0e22_000c0e40:\n"
        "addl $0x8dc, %esp\n" /* line 1167 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tok */
        ".Lfc0e22_000c0e4b:\n"
        "leal -0x458(%ebp), %edx\n" /* line 1043 | token */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c10b2\n"
        "cmpl $4, -0x58(%ebp)\n" /* line 1048 */
        "je .Lfc0e22_000c0ee2\n"
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc0e22_000c13f3\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x458(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc0e22_000c0eac:\n"
        "movl 8(%ebp), %edx\n" /* line 231 | source */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 0x430(%esi)\n" /* t */
        "movl %esi, 0x88(%edx)\n" /* line 232 | t */
        /* } scope */
        "leal -0x458(%ebp), %ecx\n" /* line 1051 | token */
        "movl %ecx, 8(%esp)\n"
        "movl $str_00222708, 4(%esp)\n" /* "expected name after #define, found %s" */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0e22_000c0e40\n"
        ".Lfc0e22_000c0ee2:\n"
        "movl 8(%ebp), %esi\n" /* line 1056 | source, i */
        "movl 0x90(%esi), %ebx\n" /* i, definehash */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl -0x458(%ebp), %eax\n" /* line 405 | token */
        "testb %al, %al\n"
        "jne .Lfc0e22_000c10cc\n"
        "xorl %ecx, %ecx\n"
        "xorl %eax, %eax\n"
        "xorl %edx, %edx\n"
        /* } scope */
        ".Lfc0e22_000c0f00:\n"
        "xorl %ecx, %eax\n" /* line 444 */
        "xorl %edx, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl (%ebx, %eax, 4), %esi\n" /* t, hash */
        "testl %esi, %esi\n" /* hash */
        "je .Lfc0e22_000c0f33\n"
        ".Lfc0e22_000c0f10:\n"
        "leal -0x458(%ebp), %eax\n" /* line 446 | token */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* hash */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c13c9\n"
        "movl 0x1c(%esi), %esi\n" /* line 444 | hash */
        "testl %esi, %esi\n" /* hash */
        "jne .Lfc0e22_000c0f10\n"
        /* } scope */
        ".Lfc0e22_000c0f33:\n"
        "cld\n" /* line 1073 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x458(%ebp), %edi\n" /* token, last */
        "repne scasb %es:(%edi), %al\n" /* last */
        "notl %ecx\n"
        "addl $0x20, %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll GetMemory\n"
        "movl %eax, -0x89c(%ebp)\n"
        "cld\n" /* line 1074 */
        "movl $8, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x89c(%ebp), %edi\n" /* last */
        "rep stosl %eax, %es:(%edi)\n" /* last */
        "movl -0x89c(%ebp), %eax\n" /* line 1075 */
        "addl $0x20, %eax\n"
        "movl -0x89c(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "leal -0x458(%ebp), %ecx\n" /* line 1076 | token */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl 8(%ebp), %esi\n" /* line 1078 | source, i */
        "movl 0x90(%esi), %ebx\n" /* i, definehash */
        /* { scope 2 */
        "movl -0x89c(%ebp), %eax\n" /* line 426 */
        "movl (%eax), %ecx\n" /* name */
        /* { scope 3 */
        /* { scope 4 */
        "movzbl (%ecx), %eax\n" /* line 405 */
        "testb %al, %al\n"
        "jne .Lfc0e22_000c139f\n"
        "xorl %esi, %esi\n" /* hash */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lfc0e22_000c0fab:\n"
        "xorl %esi, %edx\n" /* line 427 | hash */
        "xorl %edx, %eax\n"
        "andl $0x3ff, %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* t */
        "movl (%eax), %edx\n"
        "movl -0x89c(%ebp), %ecx\n"
        "movl %edx, 0x1c(%ecx)\n"
        "movl %ecx, (%eax)\n" /* line 428 */
        /* } scope */
        "leal -0x458(%ebp), %esi\n" /* line 1080 | token, i */
        "movl %esi, 4(%esp)\n" /* i */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c0e3b\n"
        "movl -0x34(%ebp), %eax\n" /* line 1083 */
        "subl -0x38(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfc0e22_000c10f9\n"
        ".Lfc0e22_000c0fef:\n"
        "xorl %ebx, %ebx\n" /* line 1135 | definehash */
        "jmp .Lfc0e22_000c1083\n"
        ".Lfc0e22_000c0ff6:\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x458(%ebp), %ecx\n" /* token */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc0e22_000c1021:\n"
        "cmpl $4, 0x400(%esi)\n" /* line 1143 | i */
        "je .Lfc0e22_000c12f1\n"
        ".Lfc0e22_000c102e:\n"
        "movl $0, 0x420(%esi)\n" /* line 970 | i */
        "movl $0, 0x424(%esi)\n" /* line 971 | i */
        "movl $0, 0x42c(%esi)\n" /* line 972 | i */
        "movl $0, 0x430(%esi)\n" /* line 1149 | i */
        "testl %ebx, %ebx\n" /* line 1150 | definehash */
        "je .Lfc0e22_000c12e1\n"
        "movl %esi, 0x430(%ebx)\n" /* line 1151 | i, definehash */
        "movl %esi, %ebx\n" /* i, definehash */
        ".Lfc0e22_000c1066:\n"
        "leal -0x458(%ebp), %edx\n" /* line 1140 | token */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c1325\n"
        ".Lfc0e22_000c1083:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "jne .Lfc0e22_000c0ff6\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc0e22_000c1021\n"
        ".Lfc0e22_000c10b2:\n"
        "movl $str_002226f0, 4(%esp)\n" /* line 1045 */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0e22_000c0e40\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc0e22_000c10cc:\n"
        "xorl %ecx, %ecx\n" /* line 405 */
        "movl $0x77, %edx\n"
        ".Lfc0e22_000c10d3:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0x4ce(%edx, %ebp), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc0e22_000c10d3\n"
        "movl %ecx, %eax\n"
        "sarl $0xa, %eax\n"
        "movl %ecx, %edx\n"
        "sarl $0x14, %edx\n"
        "jmp .Lfc0e22_000c0f00\n"
        /* } scope */
        /* } scope */
        ".Lfc0e22_000c10f9:\n"
        "movl $str_002221e8, %edi\n" /* line 1083 | last */
        "movl $2, %ecx\n"
        "cld\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* last, i */
        "movl $0, %edx\n"
        "je .Lfc0e22_000c1117\n"
        "movzbl -1(%esi), %edx\n" /* i */
        "movzbl -1(%edi), %ecx\n" /* last */
        "subl %ecx, %edx\n"
        ".Lfc0e22_000c1117:\n"
        "testl %edx, %edx\n"
        "jne .Lfc0e22_000c0fef\n"
        /* { scope 2 */
        "leal -0x898(%ebp), %edx\n" /* line 2814 | tok */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll PC_ReadToken\n"
        "testl %eax, %eax\n"
        "jne .Lfc0e22_000c1293\n"
        /* { scope 3 */
        ".Lfc0e22_000c113c:\n"
        "xorl %edi, %edi\n" /* line 232 */
        /* } scope */
        /* } scope */
        ".Lfc0e22_000c113e:\n"
        "leal -0x458(%ebp), %ecx\n" /* line 1091 | token */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %esi\n" /* source, i */
        "movl %esi, (%esp)\n" /* i */
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c162c\n"
        "cmpl $4, -0x58(%ebp)\n" /* line 1097 */
        "jne .Lfc0e22_000c1612\n"
        /* { scope 2 */
        "movl -0x89c(%ebp), %eax\n" /* line 485 */
        "movl 0x10(%eax), %ebx\n" /* p */
        "testl %ebx, %ebx\n" /* p */
        "je .Lfc0e22_000c119b\n"
        "xorl %esi, %esi\n" /* i */
        ".Lfc0e22_000c1174:\n"
        "leal -0x458(%ebp), %edx\n" /* line 487 | token */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* p */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c1528\n"
        "addl $1, %esi\n" /* line 489 | i */
        "movl 0x430(%ebx), %ebx\n" /* line 485 | p */
        "testl %ebx, %ebx\n" /* p */
        "jne .Lfc0e22_000c1174\n"
        /* } scope */
        ".Lfc0e22_000c119b:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc0e22_000c1558\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x458(%ebp), %ecx\n" /* token */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc0e22_000c11dc:\n"
        "movl $0, 0x420(%ebx)\n" /* line 970 | p */
        "movl $0, 0x424(%ebx)\n" /* line 971 | p */
        "movl $0, 0x42c(%ebx)\n" /* line 972 | p */
        "movl $0, 0x430(%ebx)\n" /* line 1111 | definehash */
        "testl %edi, %edi\n" /* line 1112 | last */
        "je .Lfc0e22_000c154a\n"
        "movl %ebx, 0x430(%edi)\n" /* line 1113 | definehash, last */
        ".Lfc0e22_000c1212:\n"
        "movl -0x89c(%ebp), %eax\n" /* line 1117 */
        "addl $1, 0xc(%eax)\n"
        "leal -0x458(%ebp), %edx\n" /* line 1119 | token */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c15e2\n"
        "movl $str_00222224, %edi\n" /* line 1125 | last */
        "movl $2, %ecx\n"
        "cld\n"
        "leal -0x458(%ebp), %esi\n" /* token, i */
        "repe cmpsb %es:(%edi), (%esi)\n" /* last, i */
        "movl $0, %edx\n"
        "je .Lfc0e22_000c125d\n"
        "movzbl -1(%esi), %edx\n" /* i */
        "movzbl -1(%edi), %ecx\n" /* last */
        "subl %ecx, %edx\n"
        ".Lfc0e22_000c125d:\n"
        "testl %edx, %edx\n"
        "je .Lfc0e22_000c12bf\n"
        "movl $str_0021f88c, %edi\n" /* line 1128 | last */
        "movl $2, %ecx\n"
        "leal -0x458(%ebp), %esi\n" /* token, i */
        "repe cmpsb %es:(%edi), (%esi)\n" /* last, i */
        "movl $0, %edx\n"
        "je .Lfc0e22_000c1284\n"
        "movzbl -1(%esi), %edx\n" /* i */
        "movzbl -1(%edi), %ecx\n" /* last */
        "subl %ecx, %edx\n"
        ".Lfc0e22_000c1284:\n"
        "testl %edx, %edx\n"
        "jne .Lfc0e22_000c1571\n"
        "movl %ebx, %edi\n" /* definehash, last */
        "jmp .Lfc0e22_000c113e\n"
        /* { scope 2 */
        ".Lfc0e22_000c1293:\n"
        "movl $str_00222224, %edi\n" /* line 2817 | last */
        "movl $2, %ecx\n"
        "cld\n"
        "leal -0x898(%ebp), %esi\n" /* tok, i */
        "repe cmpsb %es:(%edi), (%esi)\n" /* last, i */
        "movl $0, %edx\n"
        "je .Lfc0e22_000c12b7\n"
        "movzbl -1(%esi), %edx\n" /* i */
        "movzbl -1(%edi), %ecx\n" /* last */
        "subl %ecx, %edx\n"
        ".Lfc0e22_000c12b7:\n"
        "testl %edx, %edx\n"
        "jne .Lfc0e22_000c158b\n"
        /* } scope */
        ".Lfc0e22_000c12bf:\n"
        "leal -0x458(%ebp), %eax\n" /* line 1135 | token */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "jne .Lfc0e22_000c0fef\n"
        "jmp .Lfc0e22_000c0e3b\n"
        ".Lfc0e22_000c12e1:\n"
        "movl -0x89c(%ebp), %eax\n" /* line 1153 */
        "movl %esi, 0x14(%eax)\n" /* i */
        "movl %esi, %ebx\n" /* i, definehash */
        "jmp .Lfc0e22_000c1066\n"
        ".Lfc0e22_000c12f1:\n"
        "movl -0x89c(%ebp), %edx\n" /* line 1143 */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lfc0e22_000c102e\n"
        "movl $str_002227ec, 4(%esp)\n" /* line 1145 */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "jmp .Lfc0e22_000c1066\n"
        ".Lfc0e22_000c1325:\n"
        "testl %ebx, %ebx\n" /* line 1157 | definehash */
        "je .Lfc0e22_000c0e3b\n"
        "movl -0x89c(%ebp), %esi\n" /* line 1160 | i */
        "movl 0x14(%esi), %esi\n" /* i */
        "movl %esi, -0x8ac(%ebp)\n" /* i */
        "movl $3, %ecx\n"
        "cld\n"
        "movl $str_00222814, %edi\n" /* last */
        "repe cmpsb %es:(%edi), (%esi)\n" /* last, i */
        "movl $0, %eax\n"
        "je .Lfc0e22_000c135a\n"
        "movzbl -1(%esi), %eax\n" /* i */
        "movzbl -1(%edi), %ecx\n" /* last */
        "subl %ecx, %eax\n"
        ".Lfc0e22_000c135a:\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c1385\n"
        "movl $3, %ecx\n"
        "movl %ebx, %esi\n" /* definehash, i */
        "movl $str_00222814, %edi\n" /* last */
        "repe cmpsb %es:(%edi), (%esi)\n" /* last, i */
        "movl $0, %eax\n"
        "je .Lfc0e22_000c137d\n"
        "movzbl -1(%esi), %eax\n" /* i */
        "movzbl -1(%edi), %ecx\n" /* last */
        "subl %ecx, %eax\n"
        ".Lfc0e22_000c137d:\n"
        "testl %eax, %eax\n"
        "jne .Lfc0e22_000c0e3b\n"
        ".Lfc0e22_000c1385:\n"
        "movl $str_00222818, 4(%esp)\n" /* line 1162 */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0e22_000c0e40\n"
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfc0e22_000c139f:\n"
        "xorl %esi, %esi\n" /* line 405 | hash */
        "movl $0x77, %edx\n"
        ".Lfc0e22_000c13a6:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%ecx, %edx), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc0e22_000c13a6\n"
        "movl %esi, %edx\n" /* hash */
        "sarl $0xa, %edx\n"
        "movl %esi, %eax\n" /* hash */
        "sarl $0x14, %eax\n"
        "jmp .Lfc0e22_000c0fab\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfc0e22_000c13c9:\n"
        "testb $1, 4(%esi)\n" /* line 1059 | i */
        "je .Lfc0e22_000c140c\n"
        "leal -0x458(%ebp), %edx\n" /* line 1061 | token */
        "movl %edx, 8(%esp)\n"
        "movl $str_00222730, 4(%esp)\n" /* "can't redefine %s" */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0e22_000c0e40\n"
        /* { scope 2 */
        ".Lfc0e22_000c13f3:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc0e22_000c0eac\n"
        /* } scope */
        ".Lfc0e22_000c140c:\n"
        "leal -0x458(%ebp), %esi\n" /* line 1064 | token, i */
        "movl %esi, 8(%esp)\n" /* i */
        "movl $str_00222744, 4(%esp)\n" /* "redefinition of %s" */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceWarning\n"
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc0e22_000c150f\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x458(%ebp), %edx\n" /* token */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc0e22_000c146a:\n"
        "movl 8(%ebp), %ecx\n" /* line 231 | source */
        "movl 0x88(%ecx), %eax\n"
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%ecx)\n" /* line 232 | t */
        /* } scope */
        "movl %ecx, (%esp)\n" /* line 1067 */
        "calll PC_Directive_undef\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c0e40\n"
        "movl 8(%ebp), %esi\n" /* line 1070 | source, i */
        "movl 0x90(%esi), %ebx\n" /* i, definehash */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl -0x458(%ebp), %eax\n" /* line 405 | token */
        "testb %al, %al\n"
        "jne .Lfc0e22_000c14e5\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfc0e22_000c14a9:\n"
        "xorl %ecx, %edx\n" /* line 444 */
        "xorl %edx, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl (%ebx, %eax, 4), %ebx\n" /* t */
        "testl %ebx, %ebx\n" /* t */
        "je .Lfc0e22_000c0f33\n"
        ".Lfc0e22_000c14bd:\n"
        "leal -0x458(%ebp), %eax\n" /* line 446 | token */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* t */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfc0e22_000c0f33\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 444 | t */
        "testl %ebx, %ebx\n" /* t */
        "jne .Lfc0e22_000c14bd\n"
        "jmp .Lfc0e22_000c0f33\n"
        /* { scope 3 */
        ".Lfc0e22_000c14e5:\n"
        "xorl %ecx, %ecx\n" /* line 405 */
        "movl $0x77, %edx\n"
        ".Lfc0e22_000c14ec:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0x4ce(%edx, %ebp), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc0e22_000c14ec\n"
        "movl %ecx, %edx\n"
        "sarl $0xa, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x14, %eax\n"
        "jmp .Lfc0e22_000c14a9\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfc0e22_000c150f:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc0e22_000c146a\n"
        /* } scope */
        ".Lfc0e22_000c1528:\n"
        "testl %esi, %esi\n" /* line 1103 | i */
        "js .Lfc0e22_000c119b\n"
        "movl $str_00222790, 4(%esp)\n" /* line 1105 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0e22_000c0e40\n"
        ".Lfc0e22_000c154a:\n"
        "movl -0x89c(%ebp), %esi\n" /* line 1115 | i */
        "movl %ebx, 0x10(%esi)\n" /* definehash, i */
        "jmp .Lfc0e22_000c1212\n"
        ".Lfc0e22_000c1558:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc0e22_000c11dc\n"
        ".Lfc0e22_000c1571:\n"
        "movl $str_002227d4, 4(%esp)\n" /* line 1130 */
        "movl 8(%ebp), %esi\n" /* source, i */
        "movl %esi, (%esp)\n" /* i */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0e22_000c0e40\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc0e22_000c158b:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc0e22_000c15fc\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "leal -0x898(%ebp), %esi\n" /* tok */
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc0e22_000c15c8:\n"
        "movl 8(%ebp), %edx\n" /* line 231 | source */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%edx)\n" /* line 232 | t */
        "jmp .Lfc0e22_000c113c\n"
        /* } scope */
        /* } scope */
        ".Lfc0e22_000c15e2:\n"
        "movl $str_002227b0, 4(%esp)\n" /* line 1121 */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0e22_000c0e40\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc0e22_000c15fc:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc0e22_000c15c8\n"
        /* } scope */
        /* } scope */
        ".Lfc0e22_000c1612:\n"
        "movl $str_00222774, 4(%esp)\n" /* line 1099 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0e22_000c0e40\n"
        ".Lfc0e22_000c162c:\n"
        "movl $str_00222758, 4(%esp)\n" /* line 1093 */
        "movl 8(%ebp), %esi\n" /* source, i */
        "movl %esi, (%esp)\n" /* i */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc0e22_000c0e40\n"
    );
}

/* line 1306 */
__attribute__((naked))
define_t * PC_CopyDefine(source_t *source, define_t *define)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1306 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 1311 | define */
        "movl (%eax), %edi\n" /* token */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* token */
        "notl %ecx\n"
        "addl $0x20, %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll GetMemory\n"
        "movl %eax, -0x1c(%ebp)\n" /* newdefine */
        "movl %eax, %edx\n" /* line 1313 */
        "addl $0x20, %edx\n"
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1314 | define */
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "movl 0xc(%ebp), %edx\n" /* line 1315 | define */
        "movl 4(%edx), %eax\n"
        "movl -0x1c(%ebp), %ecx\n" /* newdefine */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 1316 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 1317 */
        "movl %eax, 0xc(%ecx)\n"
        "movl $0, 0x18(%ecx)\n" /* line 1319 */
        "movl $0, 0x1c(%ecx)\n" /* line 1320 */
        "movl $0, 0x14(%ecx)\n" /* line 1322 */
        "movl 0x14(%edx), %edi\n" /* line 1323 | token */
        "testl %edi, %edi\n" /* token */
        "je .Lfc1646_000c174b\n"
        "xorl %esi, %esi\n" /* lasttoken */
        "jmp .Lfc1646_000c1707\n"
        ".Lfc1646_000c16c2:\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        "movl $0, 0x430(%ebx)\n" /* line 1326 | newtoken */
        "testl %esi, %esi\n" /* line 1327 | lasttoken */
        "je .Lfc1646_000c173b\n"
        ".Lfc1646_000c16f5:\n"
        "movl %ebx, 0x430(%esi)\n" /* line 1328 | newtoken, lasttoken */
        "movl 0x430(%edi), %edi\n" /* line 1323 | token */
        "testl %edi, %edi\n" /* token */
        "je .Lfc1646_000c174b\n"
        ".Lfc1646_000c1705:\n"
        "movl %ebx, %esi\n" /* newtoken, lasttoken */
        ".Lfc1646_000c1707:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "jne .Lfc1646_000c16c2\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl $0, 0x430(%ebx)\n" /* line 1326 | newtoken */
        "testl %esi, %esi\n" /* line 1327 | lasttoken */
        "jne .Lfc1646_000c16f5\n"
        ".Lfc1646_000c173b:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1330 | newdefine */
        "movl %ebx, 0x14(%eax)\n" /* newtoken */
        "movl 0x430(%edi), %edi\n" /* line 1323 | token */
        "testl %edi, %edi\n" /* token */
        "jne .Lfc1646_000c1705\n"
        ".Lfc1646_000c174b:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1334 | newdefine */
        "movl $0, 0x10(%edx)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1335 | define */
        "movl 0x10(%ecx), %edi\n" /* token */
        "testl %edi, %edi\n" /* token */
        "je .Lfc1646_000c17f0\n"
        "xorl %esi, %esi\n" /* lasttoken */
        "jmp .Lfc1646_000c17ac\n"
        ".Lfc1646_000c1767:\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        "movl $0, 0x430(%ebx)\n" /* line 1338 | newtoken */
        "testl %esi, %esi\n" /* line 1339 | lasttoken */
        "je .Lfc1646_000c17e0\n"
        ".Lfc1646_000c179a:\n"
        "movl %ebx, 0x430(%esi)\n" /* line 1340 | newtoken, lasttoken */
        "movl 0x430(%edi), %edi\n" /* line 1335 | token */
        "testl %edi, %edi\n" /* token */
        "je .Lfc1646_000c17f0\n"
        ".Lfc1646_000c17aa:\n"
        "movl %ebx, %esi\n" /* newtoken, lasttoken */
        ".Lfc1646_000c17ac:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "jne .Lfc1646_000c1767\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl $0, 0x430(%ebx)\n" /* line 1338 | newtoken */
        "testl %esi, %esi\n" /* line 1339 | lasttoken */
        "jne .Lfc1646_000c179a\n"
        ".Lfc1646_000c17e0:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1342 | newdefine */
        "movl %ebx, 0x10(%eax)\n" /* newtoken */
        "movl 0x430(%edi), %edi\n" /* line 1335 | token */
        "testl %edi, %edi\n" /* token */
        "jne .Lfc1646_000c17aa\n"
        /* } scope */
        ".Lfc1646_000c17f0:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1346 | newdefine */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2927 */
__attribute__((naked))
source_t * LoadSourceFile(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2927 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* filename */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 2932 | filename */
        "calll LoadScriptFile\n"
        "movl %eax, %ebx\n" /* script */
        "testl %eax, %eax\n" /* line 2933 */
        "je .Lfc17fc_000c194d\n"
        "movl $0, 0x4c0(%eax)\n" /* line 2936 */
        "movl $0x4e0, (%esp)\n" /* line 2938 */
        "calll GetMemory\n"
        "movl %eax, -0x20(%ebp)\n" /* source */
        "movl $0x4e0, 8(%esp)\n" /* line 2939 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0x40, 8(%esp)\n" /* line 2941 */
        "movl %esi, 4(%esp)\n" /* filename */
        "movl -0x20(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "movl -0x20(%ebp), %edx\n" /* line 2942 | source */
        "movl %ebx, 0x84(%edx)\n" /* script */
        "movl $0, 0x88(%edx)\n" /* line 2943 */
        "movl $0, 0x8c(%edx)\n" /* line 2944 */
        "movl $0, 0x94(%edx)\n" /* line 2945 */
        "movl $0, 0x98(%edx)\n" /* line 2946 */
        "movl $__mh_execute_header, (%esp)\n" /* line 2947 */
        "calll GetClearedMemory\n"
        "movl -0x20(%ebp), %ecx\n" /* source */
        "movl %eax, 0x90(%ecx)\n"
        /* { scope 2: definehash */
        "movl globaldefines, %edi\n" /* line 1359 | define */
        "testl %edi, %edi\n" /* define */
        "jne .Lfc17fc_000c18da\n"
        "jmp .Lfc17fc_000c1942\n"
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lfc17fc_000c18b7:\n"
        "xorl %ebx, %ebx\n" /* line 405 | hash */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "xorl %ebx, %edx\n" /* line 427 | hash */
        "xorl %edx, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x1c(%ebp), %ecx\n" /* definehash */
        "leal (%ecx, %eax, 4), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, 0x1c(%esi)\n"
        "movl %esi, (%edx)\n" /* line 428 */
        /* } scope */
        "movl 0x18(%edi), %edi\n" /* line 1359 | define */
        "testl %edi, %edi\n" /* define */
        "je .Lfc17fc_000c1942\n"
        ".Lfc17fc_000c18da:\n"
        "movl %edi, 4(%esp)\n" /* line 1361 | define */
        "movl -0x20(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll PC_CopyDefine\n"
        "movl %eax, %esi\n"
        "movl -0x20(%ebp), %edx\n" /* line 1362 | source */
        "movl 0x90(%edx), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* definehash */
        /* { scope 3 */
        "movl (%eax), %ecx\n" /* line 426 | name */
        /* { scope 4 */
        /* { scope 5 */
        "movzbl (%ecx), %eax\n" /* line 405 */
        "testb %al, %al\n"
        "je .Lfc17fc_000c18b7\n"
        "xorl %ebx, %ebx\n" /* hash */
        "movl $0x77, %edx\n"
        ".Lfc17fc_000c1907:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ebx\n" /* hash */
        "movzbl -0x76(%ecx, %edx), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc17fc_000c1907\n"
        "movl %ebx, %edx\n" /* hash */
        "sarl $0xa, %edx\n"
        "movl %ebx, %eax\n" /* hash */
        "sarl $0x14, %eax\n"
        /* } scope */
        /* } scope */
        "xorl %ebx, %edx\n" /* line 427 | hash */
        "xorl %edx, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x1c(%ebp), %ecx\n" /* definehash */
        "leal (%ecx, %eax, 4), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, 0x1c(%esi)\n"
        "movl %esi, (%edx)\n" /* line 428 */
        /* } scope */
        "movl 0x18(%edi), %edi\n" /* line 1359 | define */
        "testl %edi, %edi\n" /* define */
        "jne .Lfc17fc_000c18da\n"
        /* } scope */
        /* } scope */
        ".Lfc17fc_000c1942:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2950 | source */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: definehash */
        ".Lfc17fc_000c194d:\n"
        "movl $0, -0x20(%ebp)\n" /* line 1359 | source */
        /* } scope */
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 2950 | source */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3049 */
__attribute__((naked))
int PC_LoadSourceHandle(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3049 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $1, %ebx\n"
        "movl $sourceFiles, %eax\n"
        "jmp .Lfc1960_000c197e\n"
        /* { scope 1 */
        ".Lfc1960_000c1973:\n"
        "addl $1, %ebx\n" /* line 3054 | i */
        "addl $4, %eax\n"
        "cmpl $0x40, %ebx\n" /* i */
        "je .Lfc1960_000c19a3\n"
        ".Lfc1960_000c197e:\n"
        "movl 4(%eax), %edx\n" /* line 3056 */
        "testl %edx, %edx\n"
        "jne .Lfc1960_000c1973\n"
        "movl 8(%ebp), %eax\n" /* line 3061 | filename */
        "movl %eax, (%esp)\n"
        "calll LoadSourceFile\n"
        "testl %eax, %eax\n" /* line 3062 */
        "je .Lfc1960_000c19a3\n"
        "movl %eax, sourceFiles(, %ebx, 4)\n" /* line 3064 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 3066 | i */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc1960_000c19a3:\n"
        "xorl %ebx, %ebx\n" /* line 3065 | i */
        /* } scope */
        "movl %ebx, %eax\n" /* line 3066 | i */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2064 */
__attribute__((naked))
int PC_Evaluate(source_t *source, long int *intvalue, double *floatvalue, int integer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2064 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x48c, %esp\n"
        /* { scope 1: firsttoken, lasttoken */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | intvalue */
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c19cc\n"
        "movl 0xc(%ebp), %eax\n" /* line 2072 | intvalue */
        "movl $0, (%eax)\n"
        ".Lfc19b0_000c19cc:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2073 | floatvalue */
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c19e3\n"
        "movl 0x10(%ebp), %edx\n" /* line 2074 | floatvalue */
        "movl $0, (%edx)\n"
        "movl $0, 4(%edx)\n"
        ".Lfc19b0_000c19e3:\n"
        "leal -0x468(%ebp), %ebx\n" /* line 2076 | token */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c1c4c\n"
        "xorl %edi, %edi\n" /* line 2079 | defined */
        "movl $0, -0x470(%ebp)\n" /* firsttoken */
        "movl $0, -0x46c(%ebp)\n" /* lasttoken */
        ".Lfc19b0_000c1a16:\n"
        "movl -0x68(%ebp), %eax\n" /* line 2086 */
        "cmpl $4, %eax\n"
        "je .Lfc19b0_000c1b1b\n"
        "cmpl $3, %eax\n" /* line 2124 */
        "je .Lfc19b0_000c1a30\n"
        "cmpl $5, %eax\n"
        "jne .Lfc19b0_000c1d8f\n"
        ".Lfc19b0_000c1a30:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc19b0_000c1c33\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc19b0_000c1a6b:\n"
        "movl $0, 0x430(%esi)\n" /* line 2127 | definehash */
        "movl -0x46c(%ebp), %eax\n" /* line 2128 | lasttoken */
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c1c22\n"
        "movl -0x46c(%ebp), %edx\n" /* line 2129 | lasttoken */
        "movl %esi, 0x430(%edx)\n" /* definehash */
        "movl %esi, -0x46c(%ebp)\n" /* definehash, lasttoken */
        ".Lfc19b0_000c1a95:\n"
        "movl %ebx, 4(%esp)\n" /* line 2083 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll PC_ReadLine\n"
        "testl %eax, %eax\n"
        "jne .Lfc19b0_000c1a16\n"
        "movl 0x14(%ebp), %ecx\n" /* line 2141 | integer */
        "movl %ecx, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* floatvalue */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* intvalue */
        "movl %edx, 8(%esp)\n"
        "movl -0x470(%ebp), %ecx\n" /* firsttoken */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll PC_EvaluateTokens\n"
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c1c15\n"
        "movl -0x470(%ebp), %ecx\n" /* line 2144 | firsttoken */
        "testl %ecx, %ecx\n"
        "je .Lfc19b0_000c1b0b\n"
        "movl -0x470(%ebp), %eax\n" /* firsttoken */
        "jmp .Lfc19b0_000c1af2\n"
        ".Lfc19b0_000c1af0:\n"
        "movl %esi, %eax\n" /* line 2141 | definehash */
        ".Lfc19b0_000c1af2:\n"
        "movl 0x430(%eax), %esi\n" /* line 2146 | definehash */
        "movl %eax, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        "testl %esi, %esi\n" /* line 2144 | definehash */
        "jne .Lfc19b0_000c1af0\n"
        ".Lfc19b0_000c1b0b:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lfc19b0_000c1b10:\n"
        "addl $0x48c, %esp\n" /* line 2151 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: firsttoken, lasttoken */
        ".Lfc19b0_000c1b1b:\n"
        "testl %edi, %edi\n" /* line 2088 | defined */
        "je .Lfc19b0_000c1b8b\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc19b0_000c1d05\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc19b0_000c1b5a:\n"
        "movl $0, 0x430(%esi)\n" /* line 2092 | define */
        "movl -0x46c(%ebp), %eax\n" /* line 2093 | lasttoken */
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c1d7c\n"
        "movl -0x46c(%ebp), %ecx\n" /* line 2094 | lasttoken */
        "movl %esi, 0x430(%ecx)\n" /* define */
        "movl %esi, -0x46c(%ebp)\n" /* define, lasttoken */
        "xorl %edi, %edi\n" /* defined */
        "jmp .Lfc19b0_000c1a95\n"
        ".Lfc19b0_000c1b8b:\n"
        "movl $str_002221c0, %edi\n" /* line 2099 | defined */
        "movl $8, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* define */
        "repe cmpsb %es:(%edi), (%esi)\n" /* defined, define */
        "movl $0, %edx\n"
        "je .Lfc19b0_000c1bab\n"
        "movzbl -1(%esi), %edx\n" /* define */
        "movzbl -1(%edi), %ecx\n" /* defined */
        "subl %ecx, %edx\n"
        ".Lfc19b0_000c1bab:\n"
        "testl %edx, %edx\n"
        "je .Lfc19b0_000c1c96\n"
        "movl 8(%ebp), %edx\n" /* line 2113 | source */
        "movl 0x90(%edx), %esi\n" /* definehash */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl -0x468(%ebp), %eax\n" /* line 405 | token */
        "testb %al, %al\n"
        "jne .Lfc19b0_000c1c6c\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfc19b0_000c1bd1:\n"
        "xorl %ecx, %edx\n" /* line 444 */
        "xorl %edx, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl (%esi, %eax, 4), %esi\n"
        "testl %esi, %esi\n"
        "je .Lfc19b0_000c1bfe\n"
        ".Lfc19b0_000c1be1:\n"
        "movl %ebx, 4(%esp)\n" /* line 446 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c1d1e\n"
        "movl 0x1c(%esi), %esi\n" /* line 444 */
        "testl %esi, %esi\n"
        "jne .Lfc19b0_000c1be1\n"
        /* } scope */
        ".Lfc19b0_000c1bfe:\n"
        "movl %ebx, 8(%esp)\n" /* line 2116 */
        "movl $str_00222864, 4(%esp)\n" /* "can't evaluate %s, not defined" */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        ".Lfc19b0_000c1c15:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x48c, %esp\n" /* line 2151 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: firsttoken, lasttoken */
        ".Lfc19b0_000c1c22:\n"
        "movl %esi, -0x470(%ebp)\n" /* line 2128 | definehash, firsttoken */
        "movl %esi, -0x46c(%ebp)\n" /* definehash, lasttoken */
        "jmp .Lfc19b0_000c1a95\n"
        ".Lfc19b0_000c1c33:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc19b0_000c1a6b\n"
        ".Lfc19b0_000c1c4c:\n"
        "movl $str_00222834, 4(%esp)\n" /* line 2078 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x48c, %esp\n" /* line 2151 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: firsttoken, lasttoken */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc19b0_000c1c6c:\n"
        "xorl %ecx, %ecx\n" /* line 405 */
        "movl $0x77, %edx\n"
        ".Lfc19b0_000c1c73:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0x76(%edx, %ebx), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc19b0_000c1c73\n"
        "movl %ecx, %edx\n"
        "sarl $0xa, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x14, %eax\n"
        "jmp .Lfc19b0_000c1bd1\n"
        /* } scope */
        /* } scope */
        ".Lfc19b0_000c1c96:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc19b0_000c1dc3\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc19b0_000c1cd1:\n"
        "movl $0, 0x430(%esi)\n" /* line 2103 | define */
        "movl -0x46c(%ebp), %eax\n" /* line 2104 | lasttoken */
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c1dad\n"
        "movl -0x46c(%ebp), %eax\n" /* line 2105 | lasttoken */
        "movl %esi, 0x430(%eax)\n" /* define */
        "movl %esi, -0x46c(%ebp)\n" /* define, lasttoken */
        "movl $1, %edi\n" /* defined */
        "jmp .Lfc19b0_000c1a95\n"
        ".Lfc19b0_000c1d05:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc19b0_000c1b5a\n"
        /* { scope 2 */
        ".Lfc19b0_000c1d1e:\n"
        "leal -0x20(%ebp), %eax\n" /* line 782 | lasttoken */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* firsttoken */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll PC_ExpandDefine\n"
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c1c15\n"
        "movl -0x1c(%ebp), %eax\n" /* line 785 | firsttoken */
        "testl %eax, %eax\n"
        "je .Lfc19b0_000c1c15\n"
        "movl -0x20(%ebp), %edx\n" /* lasttoken */
        "testl %edx, %edx\n"
        "je .Lfc19b0_000c1c15\n"
        "movl 8(%ebp), %ecx\n" /* line 787 | source */
        "movl 0x88(%ecx), %eax\n"
        "movl %eax, 0x430(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 788 | firsttoken */
        "movl %eax, 0x88(%ecx)\n"
        "xorl %edi, %edi\n"
        "jmp .Lfc19b0_000c1a95\n"
        /* } scope */
        ".Lfc19b0_000c1d7c:\n"
        "movl %esi, -0x470(%ebp)\n" /* line 2093 | define, firsttoken */
        "movl %esi, -0x46c(%ebp)\n" /* define, lasttoken */
        "xorl %edi, %edi\n" /* defined */
        "jmp .Lfc19b0_000c1a95\n"
        ".Lfc19b0_000c1d8f:\n"
        "movl %ebx, 8(%esp)\n" /* line 2136 */
        "movl $str_00222850, 4(%esp)\n" /* "can't evaluate %s" */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc19b0_000c1b10\n"
        ".Lfc19b0_000c1dad:\n"
        "movl %esi, -0x470(%ebp)\n" /* line 2137 | definehash, firsttoken */
        "movl %esi, -0x46c(%ebp)\n" /* definehash, lasttoken */
        "movl $1, %edi\n" /* defined */
        "jmp .Lfc19b0_000c1a95\n"
        ".Lfc19b0_000c1dc3:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc19b0_000c1cd1\n"
    );
}

/* line 2407 */
__attribute__((naked))
int PC_Directive_evalfloat(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2407 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8ac, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1: token */
        "movl $0, 0xc(%esp)\n" /* line 2412 */
        "leal -0x20(%ebp), %eax\n" /* value */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* source */
        "calll PC_Evaluate\n"
        "testl %eax, %eax\n"
        "jne .Lfc1ddc_000c1e19\n"
        /* } scope */
        "addl $0x8ac, %esp\n" /* line 2425 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lfc1ddc_000c1e19:\n"
        "movl 0x84(%esi), %edx\n" /* line 2414 | source */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2415 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2416 */
        "movl %eax, -0x44(%ebp)\n"
        "movl $0, -0x3c(%ebp)\n" /* line 2417 */
        "cvtsd2ss -0x20(%ebp), %xmm0\n" /* line 2418 | value */
        "andps CorrectSolidDeltas+6512, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00222884, 4(%esp)\n" /* "%1.2f" */
        "leal -0x468(%ebp), %edi\n" /* token */
        "movl %edi, (%esp)\n"
        "calll sprintf\n"
        "movl $3, -0x68(%ebp)\n" /* line 2419 */
        "movl $0x2808, -0x64(%ebp)\n" /* line 2420 */
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc1ddc_000c1f7b\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc1ddc_000c1ead:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        /* } scope */
        "pxor %xmm0, %xmm0\n" /* line 2422 */
        "ucomisd -0x20(%ebp), %xmm0\n" /* value */
        "ja .Lfc1ddc_000c1eda\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl $1, %eax\n" /* line 232 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfc1ddc_000c1ecf:\n"
        "addl $0x8ac, %esp\n" /* line 2425 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lfc1ddc_000c1eda:\n"
        "movl 0x84(%esi), %edx\n" /* line 2362 */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, -0x480(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2363 */
        "movl %eax, -0x488(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2364 */
        "movl %eax, -0x484(%ebp)\n"
        "movl $0, -0x47c(%ebp)\n" /* line 2365 */
        "leal -0x8a8(%ebp), %edi\n" /* line 2366 | token */
        "movw $0x2d, -0x8a8(%ebp)\n" /* token */
        "movl $5, -0x4a8(%ebp)\n" /* line 2367 */
        "movl $0x1e, -0x4a4(%ebp)\n" /* line 2368 */
        /* { scope 3 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc1ddc_000c1f94\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc1ddc_000c1f5f:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        "movl $1, %eax\n"
        "jmp .Lfc1ddc_000c1ecf\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfc1ddc_000c1f7b:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc1ddc_000c1ead\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc1ddc_000c1f94:\n"
        "movl $str_00222108, 4(%esp)\n" /* "EXE_ERR_OUT_OF_MEMORY" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc1ddc_000c1f5f\n"
    );
}

/* line 2379 */
__attribute__((naked))
int PC_Directive_eval(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2379 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8ac, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1: token */
        "movl $1, 0xc(%esp)\n" /* line 2384 */
        "movl $0, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* value */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* source */
        "calll PC_Evaluate\n"
        "testl %eax, %eax\n"
        "jne .Lfc1faa_000c1fe7\n"
        /* } scope */
        "addl $0x8ac, %esp\n" /* line 2398 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lfc1faa_000c1fe7:\n"
        "movl 0x84(%esi), %edx\n" /* line 2387 | source */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2388 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2389 */
        "movl %eax, -0x44(%ebp)\n"
        "movl $0, -0x3c(%ebp)\n" /* line 2390 */
        "movl -0x1c(%ebp), %eax\n" /* line 2391 | value */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00215a64, 4(%esp)\n" /* "%d" */
        "leal -0x468(%ebp), %edi\n" /* token */
        "movl %edi, (%esp)\n"
        "calll sprintf\n"
        "movl $3, -0x68(%ebp)\n" /* line 2392 */
        "movl $0x3008, -0x64(%ebp)\n" /* line 2393 */
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc1faa_000c2140\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc1faa_000c2076:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        /* } scope */
        "movl -0x1c(%ebp), %edx\n" /* line 2395 | value */
        "testl %edx, %edx\n"
        "js .Lfc1faa_000c209f\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl $1, %eax\n" /* line 232 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfc1faa_000c2094:\n"
        "addl $0x8ac, %esp\n" /* line 2398 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lfc1faa_000c209f:\n"
        "movl 0x84(%esi), %edx\n" /* line 2362 */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, -0x480(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2363 */
        "movl %eax, -0x488(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2364 */
        "movl %eax, -0x484(%ebp)\n"
        "movl $0, -0x47c(%ebp)\n" /* line 2365 */
        "leal -0x8a8(%ebp), %edi\n" /* line 2366 | token */
        "movw $0x2d, -0x8a8(%ebp)\n" /* token */
        "movl $5, -0x4a8(%ebp)\n" /* line 2367 */
        "movl $0x1e, -0x4a4(%ebp)\n" /* line 2368 */
        /* { scope 3 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc1faa_000c2159\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc1faa_000c2124:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        "movl $1, %eax\n"
        "jmp .Lfc1faa_000c2094\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfc1faa_000c2140:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc1faa_000c2076\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc1faa_000c2159:\n"
        "movl $str_00222108, 4(%esp)\n" /* "EXE_ERR_OUT_OF_MEMORY" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc1faa_000c2124\n"
    );
}

/* line 2293 */
__attribute__((naked))
int PC_Directive_if(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2293 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1 */
        "movl $1, 0xc(%esp)\n" /* line 2298 */
        "movl $0, 8(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* value */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* source */
        "calll PC_Evaluate\n"
        "testl %eax, %eax\n"
        "je .Lfc2170_000c21df\n"
        "xorl %ebx, %ebx\n" /* line 2300 | skip */
        "cmpl $0, -0xc(%ebp)\n" /* value */
        "sete %bl\n" /* skip */
        "movl $0x10, (%esp)\n" /* line 75 */
        "calll GetMemory\n"
        "movl $1, (%eax)\n" /* line 76 */
        "movl 0x84(%esi), %edx\n" /* line 77 */
        "movl %edx, 8(%eax)\n"
        "movl %ebx, 4(%eax)\n" /* line 78 */
        "addl %ebx, 0x98(%esi)\n" /* line 79 */
        "movl 0x94(%esi), %edx\n" /* line 80 */
        "movl %edx, 0xc(%eax)\n"
        "movl %eax, 0x94(%esi)\n" /* line 81 */
        "movl $1, %eax\n"
        /* } scope */
        ".Lfc2170_000c21df:\n"
        "addl $0x20, %esp\n" /* line 2303 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2268 */
__attribute__((naked))
int PC_Directive_elif(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2268 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x94(%esi), %edx\n" /* line 98 */
        "testl %edx, %edx\n" /* line 99 */
        "je .Lfc21e6_000c2206\n"
        "movl 8(%edx), %eax\n" /* line 103 */
        "cmpl 0x84(%esi), %eax\n"
        "je .Lfc21e6_000c221f\n"
        /* } scope */
        ".Lfc21e6_000c2206:\n"
        "movl $str_0022288c, 4(%esp)\n" /* line 2276 */
        "movl %esi, (%esp)\n" /* source */
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfc21e6_000c2218:\n"
        "addl $0x20, %esp\n" /* line 2284 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfc21e6_000c221f:\n"
        "movl (%edx), %ebx\n" /* line 106 */
        "movl 0xc(%edx), %eax\n" /* line 108 */
        "movl %eax, 0x94(%esi)\n"
        "movl 0x98(%esi), %eax\n" /* line 109 */
        "subl 4(%edx), %eax\n"
        "movl %eax, 0x98(%esi)\n"
        "movl %edx, (%esp)\n" /* line 110 */
        "calll FreeMemory\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 2274 | type */
        "je .Lfc21e6_000c2206\n"
        "cmpl $2, %ebx\n" /* type */
        "je .Lfc21e6_000c2206\n"
        "movl $1, 0xc(%esp)\n" /* line 2279 */
        "movl $0, 8(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* value */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* source */
        "calll PC_Evaluate\n"
        "testl %eax, %eax\n"
        "je .Lfc21e6_000c2218\n"
        "xorl %ebx, %ebx\n" /* line 2281 | type */
        "cmpl $0, -0xc(%ebp)\n" /* value */
        "sete %bl\n" /* type */
        "movl $0x10, (%esp)\n" /* line 75 */
        "calll GetMemory\n"
        "movl $4, (%eax)\n" /* line 76 */
        "movl 0x84(%esi), %edx\n" /* line 77 */
        "movl %edx, 8(%eax)\n"
        "movl %ebx, 4(%eax)\n" /* line 78 */
        "addl %ebx, 0x98(%esi)\n" /* line 79 */
        "movl 0x94(%esi), %edx\n" /* line 80 */
        "movl %edx, 0xc(%eax)\n"
        "movl %eax, 0x94(%esi)\n" /* line 81 */
        "movl $1, %eax\n"
        "jmp .Lfc21e6_000c2218\n"
    );
}

/* line 2160 */
__attribute__((naked))
int PC_DollarEvaluate(source_t *source, long int *intvalue, double *floatvalue, int integer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2160 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x48c, %esp\n"
        /* { scope 1: firsttoken, lasttoken */
        "movl 0xc(%ebp), %edx\n" /* line 2167 | intvalue */
        "testl %edx, %edx\n"
        "je .Lfc22b4_000c22d0\n"
        "movl 0xc(%ebp), %eax\n" /* line 2168 | intvalue */
        "movl $0, (%eax)\n"
        ".Lfc22b4_000c22d0:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2169 | floatvalue */
        "testl %eax, %eax\n"
        "je .Lfc22b4_000c22e7\n"
        "movl 0x10(%ebp), %edx\n" /* line 2170 | floatvalue */
        "movl $0, (%edx)\n"
        "movl $0, 4(%edx)\n"
        ".Lfc22b4_000c22e7:\n"
        "leal -0x468(%ebp), %ebx\n" /* line 2172 | token */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "jne .Lfc22b4_000c2320\n"
        "movl $str_0022289c, 4(%esp)\n" /* line 2174 */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfc22b4_000c2315:\n"
        "addl $0x48c, %esp\n" /* line 2259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: firsttoken, lasttoken */
        ".Lfc22b4_000c2320:\n"
        "movl %ebx, 4(%esp)\n" /* line 2177 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "je .Lfc22b4_000c25cc\n"
        "xorl %edi, %edi\n" /* line 2180 | defined */
        "movl $1, -0x474(%ebp)\n" /* indent */
        "movl $0, -0x470(%ebp)\n" /* firsttoken */
        "movl $0, -0x46c(%ebp)\n" /* lasttoken */
        ".Lfc22b4_000c2357:\n"
        "movl -0x68(%ebp), %eax\n" /* line 2188 */
        "cmpl $4, %eax\n"
        "je .Lfc22b4_000c248f\n"
        "cmpl $3, %eax\n" /* line 2226 */
        "je .Lfc22b4_000c2371\n"
        "cmpl $5, %eax\n"
        "jne .Lfc22b4_000c270f\n"
        ".Lfc22b4_000c2371:\n"
        "movzbl -0x468(%ebp), %edx\n" /* line 2228 | token */
        "cmpb $0x28, %dl\n"
        "je .Lfc22b4_000c24ff\n"
        "movl -0x474(%ebp), %eax\n" /* line 2231 | indent */
        "subl $1, %eax\n"
        "cmpb $0x29, %dl\n"
        "cmovnel -0x474(%ebp), %eax\n" /* indent */
        "movl %eax, -0x474(%ebp)\n" /* indent */
        ".Lfc22b4_000c239a:\n"
        "movl -0x474(%ebp), %eax\n" /* line 2232 | indent */
        "testl %eax, %eax\n"
        "jle .Lfc22b4_000c2420\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc22b4_000c25b3\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc22b4_000c23df:\n"
        "movl $0, 0x430(%esi)\n" /* line 2235 | definehash */
        "movl -0x46c(%ebp), %eax\n" /* line 2236 | lasttoken */
        "testl %eax, %eax\n"
        "je .Lfc22b4_000c25a2\n"
        "movl -0x46c(%ebp), %edx\n" /* line 2237 | lasttoken */
        "movl %esi, 0x430(%edx)\n" /* definehash */
        "movl %esi, -0x46c(%ebp)\n" /* definehash, lasttoken */
        ".Lfc22b4_000c2409:\n"
        "movl %ebx, 4(%esp)\n" /* line 2185 */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll PC_ReadSourceToken\n"
        "testl %eax, %eax\n"
        "jne .Lfc22b4_000c2357\n"
        ".Lfc22b4_000c2420:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 2249 | integer */
        "movl %ecx, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* floatvalue */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* intvalue */
        "movl %edx, 8(%esp)\n"
        "movl -0x470(%ebp), %ecx\n" /* firsttoken */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll PC_EvaluateTokens\n"
        "testl %eax, %eax\n"
        "je .Lfc22b4_000c2595\n"
        "movl -0x470(%ebp), %ecx\n" /* line 2252 | firsttoken */
        "testl %ecx, %ecx\n"
        "je .Lfc22b4_000c247f\n"
        "movl -0x470(%ebp), %eax\n" /* firsttoken */
        "jmp .Lfc22b4_000c2466\n"
        ".Lfc22b4_000c2464:\n"
        "movl %esi, %eax\n" /* line 2249 | definehash */
        ".Lfc22b4_000c2466:\n"
        "movl 0x430(%eax), %esi\n" /* line 2254 | definehash */
        "movl %eax, (%esp)\n" /* line 169 */
        "calll FreeMemory\n"
        "subl $1, numtokens\n" /* line 170 */
        "testl %esi, %esi\n" /* line 2252 | definehash */
        "jne .Lfc22b4_000c2464\n"
        ".Lfc22b4_000c247f:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x48c, %esp\n" /* line 2259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: firsttoken, lasttoken */
        ".Lfc22b4_000c248f:\n"
        "testl %edi, %edi\n" /* line 2190 | defined */
        "je .Lfc22b4_000c250b\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc22b4_000c26e3\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc22b4_000c24ce:\n"
        "movl $0, 0x430(%esi)\n" /* line 2194 | define */
        "movl -0x46c(%ebp), %eax\n" /* line 2195 | lasttoken */
        "testl %eax, %eax\n"
        "je .Lfc22b4_000c26fc\n"
        "movl -0x46c(%ebp), %edx\n" /* line 2196 | lasttoken */
        "movl %esi, 0x430(%edx)\n" /* define */
        "movl %esi, -0x46c(%ebp)\n" /* define, lasttoken */
        "xorl %edi, %edi\n" /* defined */
        "jmp .Lfc22b4_000c2409\n"
        ".Lfc22b4_000c24ff:\n"
        "addl $1, -0x474(%ebp)\n" /* line 2229 | indent */
        "jmp .Lfc22b4_000c239a\n"
        ".Lfc22b4_000c250b:\n"
        "movl $str_002221c0, %edi\n" /* line 2201 | defined */
        "movl $8, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* define */
        "repe cmpsb %es:(%edi), (%esi)\n" /* defined, define */
        "movl $0, %edx\n"
        "je .Lfc22b4_000c252b\n"
        "movzbl -1(%esi), %edx\n" /* define */
        "movzbl -1(%edi), %ecx\n" /* defined */
        "subl %ecx, %edx\n"
        ".Lfc22b4_000c252b:\n"
        "testl %edx, %edx\n"
        "je .Lfc22b4_000c25ec\n"
        "movl 8(%ebp), %eax\n" /* line 2215 | source */
        "movl 0x90(%eax), %esi\n" /* definehash */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl -0x468(%ebp), %eax\n" /* line 405 | token */
        "testb %al, %al\n"
        "jne .Lfc22b4_000c265b\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfc22b4_000c2551:\n"
        "xorl %ecx, %edx\n" /* line 444 */
        "xorl %edx, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl (%esi, %eax, 4), %esi\n"
        "testl %esi, %esi\n"
        "je .Lfc22b4_000c257e\n"
        ".Lfc22b4_000c2561:\n"
        "movl %ebx, 4(%esp)\n" /* line 446 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfc22b4_000c2685\n"
        "movl 0x1c(%esi), %esi\n" /* line 444 */
        "testl %esi, %esi\n"
        "jne .Lfc22b4_000c2561\n"
        /* } scope */
        ".Lfc22b4_000c257e:\n"
        "movl %ebx, 8(%esp)\n" /* line 2218 */
        "movl $str_00222864, 4(%esp)\n" /* "can't evaluate %s, not defined" */
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll SourceError\n"
        ".Lfc22b4_000c2595:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x48c, %esp\n" /* line 2259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: firsttoken, lasttoken */
        ".Lfc22b4_000c25a2:\n"
        "movl %esi, -0x470(%ebp)\n" /* line 2236 | definehash, firsttoken */
        "movl %esi, -0x46c(%ebp)\n" /* definehash, lasttoken */
        "jmp .Lfc22b4_000c2409\n"
        ".Lfc22b4_000c25b3:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc22b4_000c23df\n"
        ".Lfc22b4_000c25cc:\n"
        "movl $str_002228c4, 4(%esp)\n" /* line 2179 */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x48c, %esp\n" /* line 2259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: firsttoken, lasttoken */
        ".Lfc22b4_000c25ec:\n"
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc22b4_000c272d\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%esi)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc22b4_000c2627:\n"
        "movl $0, 0x430(%esi)\n" /* line 2205 | define */
        "movl -0x46c(%ebp), %eax\n" /* line 2206 | lasttoken */
        "testl %eax, %eax\n"
        "je .Lfc22b4_000c2746\n"
        "movl -0x46c(%ebp), %ecx\n" /* line 2207 | lasttoken */
        "movl %esi, 0x430(%ecx)\n" /* define */
        "movl %esi, -0x46c(%ebp)\n" /* define, lasttoken */
        "movl $1, %edi\n" /* defined */
        "jmp .Lfc22b4_000c2409\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc22b4_000c265b:\n"
        "xorl %ecx, %ecx\n" /* line 405 */
        "movl $0x77, %edx\n"
        ".Lfc22b4_000c2662:\n"
        "movsbl %al, %eax\n" /* line 407 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0x76(%edx, %ebx), %eax\n" /* line 405 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lfc22b4_000c2662\n"
        "movl %ecx, %edx\n"
        "sarl $0xa, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x14, %eax\n"
        "jmp .Lfc22b4_000c2551\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfc22b4_000c2685:\n"
        "leal -0x20(%ebp), %eax\n" /* line 782 | lasttoken */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* firsttoken */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* source */
        "movl %edx, (%esp)\n"
        "calll PC_ExpandDefine\n"
        "testl %eax, %eax\n"
        "je .Lfc22b4_000c2595\n"
        "movl -0x1c(%ebp), %eax\n" /* line 785 | firsttoken */
        "testl %eax, %eax\n"
        "je .Lfc22b4_000c2595\n"
        "movl -0x20(%ebp), %edx\n" /* lasttoken */
        "testl %edx, %edx\n"
        "je .Lfc22b4_000c2595\n"
        "movl 8(%ebp), %ecx\n" /* line 787 | source */
        "movl 0x88(%ecx), %eax\n"
        "movl %eax, 0x430(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 788 | firsttoken */
        "movl %eax, 0x88(%ecx)\n"
        "xorl %edi, %edi\n"
        "jmp .Lfc22b4_000c2409\n"
        /* } scope */
        ".Lfc22b4_000c26e3:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc22b4_000c24ce\n"
        ".Lfc22b4_000c26fc:\n"
        "movl %esi, -0x470(%ebp)\n" /* line 2195 | define, firsttoken */
        "movl %esi, -0x46c(%ebp)\n" /* define, lasttoken */
        "xorl %edi, %edi\n" /* defined */
        "jmp .Lfc22b4_000c2409\n"
        ".Lfc22b4_000c270f:\n"
        "movl %ebx, 8(%esp)\n" /* line 2244 */
        "movl $str_00222850, 4(%esp)\n" /* "can't evaluate %s" */
        "movl 8(%ebp), %ecx\n" /* source */
        "movl %ecx, (%esp)\n"
        "calll SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc22b4_000c2315\n"
        ".Lfc22b4_000c272d:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc22b4_000c2627\n"
        ".Lfc22b4_000c2746:\n"
        "movl %esi, -0x470(%ebp)\n" /* line 2245 | definehash, firsttoken */
        "movl %esi, -0x46c(%ebp)\n" /* definehash, lasttoken */
        "movl $1, %edi\n" /* defined */
        "jmp .Lfc22b4_000c2409\n"
    );
}

/* line 2539 */
__attribute__((naked))
int PC_DollarDirective_evalfloat(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2539 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8bc, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1: token */
        "movl $0, 0xc(%esp)\n" /* line 2544 */
        "leal -0x20(%ebp), %eax\n" /* value */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* source */
        "calll PC_DollarEvaluate\n"
        "testl %eax, %eax\n"
        "jne .Lfc275c_000c2799\n"
        /* } scope */
        ".Lfc275c_000c278e:\n"
        "addl $0x8bc, %esp\n" /* line 2559 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lfc275c_000c2799:\n"
        "movl 0x84(%esi), %edx\n" /* line 2546 | source */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2547 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2548 */
        "movl %eax, -0x44(%ebp)\n"
        "movl $0, -0x3c(%ebp)\n" /* line 2549 */
        "cvtsd2ss -0x20(%ebp), %xmm0\n" /* line 2550 | value */
        "andps CorrectSolidDeltas+6528, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00222884, 4(%esp)\n" /* "%1.2f" */
        "leal -0x468(%ebp), %edi\n" /* token */
        "movl %edi, (%esp)\n"
        "calll sprintf\n"
        "movl $3, -0x68(%ebp)\n" /* line 2551 */
        "movl $0x2808, -0x64(%ebp)\n" /* line 2552 */
        "fldl -0x20(%ebp)\n" /* line 2553 | value */
        "fnstcw -0x8aa(%ebp)\n"
        "movzwl -0x8aa(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x8ac(%ebp)\n"
        "fld %st(0)\n"
        "fldcw -0x8ac(%ebp)\n"
        "fistpll -0x8b8(%ebp)\n"
        "fldcw -0x8aa(%ebp)\n"
        "movl -0x8b8(%ebp), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "fstpt -0x58(%ebp)\n" /* line 2554 */
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc275c_000c288f\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc275c_000c2862:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        /* } scope */
        "pxor %xmm0, %xmm0\n" /* line 2556 */
        "ucomisd -0x20(%ebp), %xmm0\n" /* value */
        "ja .Lfc275c_000c28a5\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl $1, %eax\n" /* line 232 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x8bc, %esp\n" /* line 2559 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lfc275c_000c288f:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc275c_000c2862\n"
        /* } scope */
        /* { scope 2 */
        ".Lfc275c_000c28a5:\n"
        "movl 0x84(%esi), %edx\n" /* line 2362 */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, -0x480(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2363 */
        "movl %eax, -0x488(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2364 */
        "movl %eax, -0x484(%ebp)\n"
        "movl $0, -0x47c(%ebp)\n" /* line 2365 */
        "leal -0x8a8(%ebp), %edi\n" /* line 2366 | token */
        "movw $0x2d, -0x8a8(%ebp)\n" /* token */
        "movl $5, -0x4a8(%ebp)\n" /* line 2367 */
        "movl $0x1e, -0x4a4(%ebp)\n" /* line 2368 */
        /* { scope 3 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc275c_000c2946\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc275c_000c292a:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        "movl $1, %eax\n"
        "jmp .Lfc275c_000c278e\n"
        ".Lfc275c_000c2946:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc275c_000c292a\n"
    );
}

/* line 2509 */
__attribute__((naked))
int PC_DollarDirective_evalint(source_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2509 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8ac, %esp\n"
        "movl 8(%ebp), %esi\n" /* source */
        /* { scope 1: token */
        "movl $1, 0xc(%esp)\n" /* line 2514 */
        "movl $0, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* value */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* source */
        "calll PC_DollarEvaluate\n"
        "testl %eax, %eax\n"
        "jne .Lfc295c_000c2999\n"
        /* } scope */
        ".Lfc295c_000c298e:\n"
        "addl $0x8ac, %esp\n" /* line 2530 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lfc295c_000c2999:\n"
        "movl 0x84(%esi), %edx\n" /* line 2517 | source */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2518 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2519 */
        "movl %eax, -0x44(%ebp)\n"
        "movl $0, -0x3c(%ebp)\n" /* line 2520 */
        "movl -0x1c(%ebp), %eax\n" /* line 2521 | value */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00215a64, 4(%esp)\n" /* "%d" */
        "leal -0x468(%ebp), %edi\n" /* token */
        "movl %edi, (%esp)\n"
        "calll sprintf\n"
        "movl $3, -0x68(%ebp)\n" /* line 2522 */
        "movl $0x3008, -0x64(%ebp)\n" /* line 2523 */
        "movl -0x1c(%ebp), %eax\n" /* line 2524 | value */
        "movl %eax, -0x60(%ebp)\n"
        "pushl %eax\n" /* line 2525 */
        "fildl (%esp)\n"
        "addl $4, %esp\n"
        "fstpt -0x58(%ebp)\n"
        /* { scope 2 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc295c_000c2a5d\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc295c_000c2a34:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        /* } scope */
        "movl -0x1c(%ebp), %ecx\n" /* line 2527 | value */
        "testl %ecx, %ecx\n"
        "js .Lfc295c_000c2a73\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl $1, %eax\n" /* line 232 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x8ac, %esp\n" /* line 2530 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lfc295c_000c2a5d:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc295c_000c2a34\n"
        /* } scope */
        /* { scope 2 */
        ".Lfc295c_000c2a73:\n"
        "movl 0x84(%esi), %edx\n" /* line 2362 */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, -0x480(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2363 */
        "movl %eax, -0x488(%ebp)\n"
        "movl 0x44(%edx), %eax\n" /* line 2364 */
        "movl %eax, -0x484(%ebp)\n"
        "movl $0, -0x47c(%ebp)\n" /* line 2365 */
        "leal -0x8a8(%ebp), %edi\n" /* line 2366 | token */
        "movw $0x2d, -0x8a8(%ebp)\n" /* token */
        "movl $5, -0x4a8(%ebp)\n" /* line 2367 */
        "movl $0x1e, -0x4a4(%ebp)\n" /* line 2368 */
        /* { scope 3 */
        "movl $0x440, (%esp)\n" /* line 148 */
        "calll GetMemory\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lfc295c_000c2b14\n"
        "movl $0x440, 8(%esp)\n" /* line 154 */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 0x430(%ebx)\n" /* line 155 */
        "addl $1, numtokens\n" /* line 156 */
        ".Lfc295c_000c2af8:\n"
        "movl 0x88(%esi), %eax\n" /* line 231 */
        "movl %eax, 0x430(%ebx)\n" /* t */
        "movl %ebx, 0x88(%esi)\n" /* line 232 | t */
        "movl $1, %eax\n"
        "jmp .Lfc295c_000c298e\n"
        ".Lfc295c_000c2b14:\n"
        "movl $str_00222108, 4(%esp)\n" /* line 151 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfc295c_000c2af8\n"
    );
}
#else
int PC_ReadSourceToken(source_t *source, token_t *token) { return 0; }
#endif
