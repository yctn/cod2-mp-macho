/* ASM dump from: l_script.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/botlib/l_script.cpp */

#include "common_types.h"
#include "imports.h"

extern punctuation_t default_punctuations[53]; /* 0x0 */

void PS_CreatePunctuationTable(script_t *script, punctuation_t *punctuations);
void ScriptError(script_t *script, char *str);
void ScriptWarning(script_t *script, char *str);
int PS_ReadEscapeCharacter(script_t *script, char *ch);
void NumberValue(char *string, int subtype, long unsigned int *intvalue, long double *floatvalue);
int PS_ReadNumber(script_t *script, token_t *token);
void StripDoubleQuotes(char *string);
int EndOfScript(script_t *script);
void FreeScript(script_t *script);
script_t * LoadScriptFile(const char *filename);
int PS_ReadString(script_t *script, token_t *token, int quote);
int PS_ReadToken(script_t *script, token_t *token);

/* line 146 */
__attribute__((naked))
void PS_CreatePunctuationTable(script_t *script, punctuation_t *punctuations)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 146 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 152 | script */
        "movl 0x70(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfc2b2c_000c2c34\n"
        "movl %eax, %ecx\n"
        ".Lfc2b2c_000c2b45:\n"
        "movl 0x70(%ecx), %eax\n" /* line 154 */
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0xc(%ebp), %ebx\n" /* line 156 | punctuations */
        "movl (%ebx), %esi\n" /* lastp */
        "testl %esi, %esi\n" /* lastp */
        "je .Lfc2b2c_000c2be7\n"
        "addl $0xc, %ebx\n"
        "movl %ebx, -0x20(%ebp)\n"
        "movl %ebx, -0x1c(%ebp)\n"
        ".Lfc2b2c_000c2b72:\n"
        "movsbl (%esi), %edx\n" /* line 161 | lastp */
        "movl 8(%ebp), %ecx\n" /* script */
        "movl 0x70(%ecx), %eax\n"
        "movl (%eax, %edx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfc2b2c_000c2bef\n"
        "cld\n" /* line 163 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* lastp */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "subl $1, %ebx\n"
        "xorl %esi, %esi\n" /* lastp */
        "jmp .Lfc2b2c_000c2b9d\n"
        ".Lfc2b2c_000c2b99:\n"
        "movl %edx, %esi\n" /* line 161 | lastp */
        "movl %eax, %edx\n"
        ".Lfc2b2c_000c2b9d:\n"
        "movl (%edx), %edi\n" /* line 163 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl %ebx, %ecx\n"
        "jb .Lfc2b2c_000c2c12\n"
        "movl 8(%edx), %eax\n" /* line 161 */
        "testl %eax, %eax\n"
        "jne .Lfc2b2c_000c2b99\n"
        "movl %edx, %eax\n" /* line 183 */
        "movl 0xc(%ebp), %ebx\n" /* line 176 | punctuations */
        "movl $0, 8(%ebx)\n"
        "testl %eax, %eax\n" /* line 177 */
        "je .Lfc2b2c_000c2bff\n"
        ".Lfc2b2c_000c2bc8:\n"
        "movl 0xc(%ebp), %edx\n" /* line 178 | punctuations */
        "movl %edx, 8(%eax)\n"
        ".Lfc2b2c_000c2bce:\n"
        "movl -0x20(%ebp), %ebx\n" /* line 180 */
        "movl %ebx, 0xc(%ebp)\n" /* punctuations */
        "movl -0x1c(%ebp), %eax\n" /* line 156 */
        "movl (%eax), %esi\n" /* lastp */
        "addl $0xc, -0x20(%ebp)\n"
        "addl $0xc, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %esi, %esi\n" /* lastp */
        "jne .Lfc2b2c_000c2b72\n"
        /* } scope */
        ".Lfc2b2c_000c2be7:\n"
        "addl $0x3c, %esp\n" /* line 183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc2b2c_000c2bef:\n"
        "xorl %eax, %eax\n" /* line 161 */
        "movl 0xc(%ebp), %ebx\n" /* line 176 | punctuations */
        "movl $0, 8(%ebx)\n"
        "testl %eax, %eax\n" /* line 177 */
        "jne .Lfc2b2c_000c2bc8\n"
        ".Lfc2b2c_000c2bff:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 180 | punctuations */
        "movl (%ebx), %eax\n"
        "movsbl (%eax), %edx\n"
        "movl 8(%ebp), %ecx\n" /* script */
        "movl 0x70(%ecx), %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n"
        "jmp .Lfc2b2c_000c2bce\n"
        ".Lfc2b2c_000c2c12:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 165 | punctuations */
        "movl %edx, 8(%ecx)\n"
        "testl %esi, %esi\n" /* line 166 | lastp */
        "je .Lfc2b2c_000c2c24\n"
        "movl 0xc(%ebp), %ecx\n" /* line 167 | punctuations */
        "movl %ecx, 8(%esi)\n" /* lastp */
        "jmp .Lfc2b2c_000c2bce\n"
        ".Lfc2b2c_000c2c24:\n"
        "movl (%ecx), %eax\n" /* line 169 */
        "movsbl (%eax), %edx\n"
        "movl 8(%ebp), %ebx\n" /* script */
        "movl 0x70(%ebx), %eax\n"
        "movl %ecx, (%eax, %edx, 4)\n"
        "jmp .Lfc2b2c_000c2bce\n"
        ".Lfc2b2c_000c2c34:\n"
        "movl $0x400, (%esp)\n" /* line 153 */
        "calll GetMemory\n"
        "movl 8(%ebp), %edx\n" /* script */
        "movl %eax, 0x70(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* script */
        "jmp .Lfc2b2c_000c2b45\n"
    );
}

/* line 211 */
__attribute__((naked))
void ScriptError(script_t *script, char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 211 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl 8(%ebp), %esi\n" /* script */
        /* { scope 1 */
        "testb $1, 0x68(%esi)\n" /* line 216 | script */
        "jne .Lfc2c4e_000c2ca4\n"
        "leal 0x10(%ebp), %eax\n" /* line 219 */
        "movl %eax, -0xc(%ebp)\n" /* ap */
        "movl %eax, 0xc(%esp)\n" /* line 220 */
        "movl 0xc(%ebp), %eax\n" /* str */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x40c(%ebp), %ebx\n" /* text */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "movl %ebx, 0xc(%esp)\n" /* line 223 */
        "movl 0x5c(%esi), %eax\n" /* script */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* script */
        "movl $0x2220ac, (%esp)\n" /* "^1Error: file %s, line %d: %s
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lfc2c4e_000c2ca4:\n"
        "addl $0x420, %esp\n" /* line 224 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 233 */
__attribute__((naked))
void ScriptWarning(script_t *script, char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 233 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl 8(%ebp), %esi\n" /* script */
        /* { scope 1 */
        "testb $2, 0x68(%esi)\n" /* line 238 | script */
        "jne .Lfc2cae_000c2d04\n"
        "leal 0x10(%ebp), %eax\n" /* line 241 */
        "movl %eax, -0xc(%ebp)\n" /* ap */
        "movl %eax, 0xc(%esp)\n" /* line 242 */
        "movl 0xc(%ebp), %eax\n" /* str */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x40c(%ebp), %ebx\n" /* text */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "movl %ebx, 0xc(%esp)\n" /* line 244 */
        "movl 0x5c(%esi), %eax\n" /* script */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* script */
        "movl $0x2220cc, (%esp)\n" /* "^3Warning: file %s, line %d: %s
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lfc2cae_000c2d04:\n"
        "addl $0x420, %esp\n" /* line 245 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 346 */
__attribute__((naked))
int PS_ReadEscapeCharacter(script_t *script, char *ch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 346 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* script */
        /* { scope 1 */
        "movl 0x44(%esi), %edx\n" /* line 351 | script */
        "movl %edx, %ebx\n" /* val */
        "addl $1, %edx\n"
        "movl %edx, 0x44(%esi)\n" /* script */
        "movzbl 1(%ebx), %ecx\n" /* line 353 | val */
        "movsbl %cl, %eax\n"
        "subl $0x22, %eax\n"
        "cmpl $0x56, %eax\n"
        "ja .Lfc2d10_000c2d3d\n"
        "jmpl *0x2f20a0(, %eax, 4)\n"
        ".Lfc2d10_000c2d3d:\n"
        "leal -0x30(%ecx), %eax\n" /* line 415 */
        "cmpb $9, %al\n"
        "ja .Lfc2d10_000c2dd6\n"
        "movl %edx, %ecx\n" /* line 419 */
        "movsbl (%edx), %eax\n" /* line 420 */
        "leal -0x30(%eax), %edx\n"
        "cmpl $9, %edx\n"
        "ja .Lfc2d10_000c2d96\n"
        ".Lfc2d10_000c2d55:\n"
        "xorl %ebx, %ebx\n" /* line 423 | val */
        ".Lfc2d10_000c2d57:\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* line 424 | val */
        "leal (%edx, %eax, 2), %ebx\n" /* val */
        "addl $1, %ecx\n" /* line 417 */
        "movl %ecx, 0x44(%esi)\n" /* script */
        "movsbl (%ecx), %eax\n" /* line 420 */
        "leal -0x30(%eax), %edx\n"
        "cmpl $9, %edx\n"
        "jbe .Lfc2d10_000c2d57\n"
        "leal -1(%ecx), %edx\n" /* line 426 */
        "movl %edx, 0x44(%esi)\n" /* script */
        "cmpl $0xff, %ebx\n" /* line 427 | val */
        "jg .Lfc2d10_000c2da6\n"
        ".Lfc2d10_000c2d7c:\n"
        "movl %ebx, %ecx\n" /* val */
        ".Lfc2d10_000c2d7e:\n"
        "leal 1(%edx), %eax\n" /* line 437 */
        "movl %eax, 0x44(%esi)\n" /* script */
        "movl 0xc(%ebp), %eax\n" /* line 439 | ch */
        "movb %cl, (%eax)\n"
        /* } scope */
        "movl $1, %eax\n" /* line 442 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc2d10_000c2d96:\n"
        "xorl %ebx, %ebx\n" /* line 423 | val */
        "leal -1(%ecx), %edx\n" /* line 426 */
        "movl %edx, 0x44(%esi)\n" /* script */
        "cmpl $0xff, %ebx\n" /* line 427 | val */
        "jle .Lfc2d10_000c2d7c\n"
        ".Lfc2d10_000c2da6:\n"
        "movl $0x222938, 4(%esp)\n" /* line 429 */
        "movl %esi, (%esp)\n" /* script */
        "calll ScriptWarning\n"
        "movl $0xffffffff, %ecx\n"
        "movl 0x44(%esi), %edx\n" /* script */
        "leal 1(%edx), %eax\n" /* line 437 */
        "movl %eax, 0x44(%esi)\n" /* script */
        "movl 0xc(%ebp), %eax\n" /* line 439 | ch */
        "movb %cl, (%eax)\n"
        /* } scope */
        "movl $1, %eax\n" /* line 442 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc2d10_000c2dd6:\n"
        "movl $0x22295c, 4(%esp)\n" /* line 416 */
        "movl %esi, (%esp)\n" /* script */
        "calll ScriptError\n"
        "movl 0x44(%esi), %edx\n" /* script */
        "movl %edx, %ecx\n" /* line 419 */
        "movsbl (%edx), %eax\n" /* line 420 */
        "leal -0x30(%eax), %edx\n"
        "cmpl $9, %edx\n"
        "ja .Lfc2d10_000c2d96\n"
        "jmp .Lfc2d10_000c2d55\n"
        "leal 2(%ebx), %edx\n" /* line 390 | val */
        "movl %edx, 0x44(%esi)\n" /* script */
        "xorl %edi, %edi\n"
        "movl %edx, %ebx\n" /* val */
        "jmp .Lfc2d10_000c2e1a\n"
        ".Lfc2d10_000c2e07:\n"
        "leal -0x37(%ecx), %edx\n" /* line 397 */
        ".Lfc2d10_000c2e0a:\n"
        "movl %edi, %eax\n" /* line 402 */
        "shll $4, %eax\n"
        "leal (%edx, %eax), %edi\n"
        "leal 1(%ebx), %edx\n" /* line 391 | val */
        "movl %edx, 0x44(%esi)\n" /* script */
        "movl %edx, %ebx\n" /* val */
        ".Lfc2d10_000c2e1a:\n"
        "movsbl (%ebx), %ecx\n" /* line 393 | val */
        "leal -0x30(%ecx), %edx\n" /* line 394 */
        "cmpl $9, %edx\n"
        "jbe .Lfc2d10_000c2e0a\n"
        "leal -0x41(%ecx), %eax\n" /* line 396 */
        "cmpl $0x19, %eax\n"
        "jbe .Lfc2d10_000c2e07\n"
        "leal -0x61(%ecx), %eax\n" /* line 398 */
        "cmpl $0x19, %eax\n"
        "ja .Lfc2d10_000c2ea8\n"
        "leal -0x57(%ecx), %edx\n" /* line 399 */
        "jmp .Lfc2d10_000c2e0a\n"
        "movl $0x27, %ecx\n" /* line 378 */
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $0x22, %ecx\n" /* line 353 */
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $0x3f, %ecx\n"
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $0x5c, %ecx\n"
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $7, %ecx\n" /* line 375 */
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $8, %ecx\n" /* line 369 */
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $0xc, %ecx\n" /* line 372 */
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $0xa, %ecx\n" /* line 357 */
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $0xd, %ecx\n" /* line 360 */
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $9, %ecx\n" /* line 363 */
        "jmp .Lfc2d10_000c2d7e\n"
        "movl $0xb, %ecx\n" /* line 366 */
        "jmp .Lfc2d10_000c2d7e\n"
        ".Lfc2d10_000c2ea8:\n"
        "leal -1(%ebx), %edx\n" /* line 404 | val */
        "movl %edx, 0x44(%esi)\n" /* script */
        "cmpl $0xff, %edi\n" /* line 405 */
        "jg .Lfc2d10_000c2da6\n"
        "movl %edi, %ecx\n"
        "jmp .Lfc2d10_000c2d7e\n"
    );
}

/* line 578 */
__attribute__((naked))
void NumberValue(char *string, int subtype, long unsigned int *intvalue, long double *floatvalue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 578 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* string */
        "movl 0xc(%ebp), %eax\n" /* subtype */
        "movl 0x10(%ebp), %esi\n" /* intvalue */
        "movl 0x14(%ebp), %edi\n" /* floatvalue */
        /* { scope 1 */
        "movl $0, (%esi)\n" /* line 582 | intvalue */
        "movl $0, (%edi)\n" /* line 583 | floatvalue */
        "movl $0, 4(%edi)\n" /* floatvalue */
        "movl $0, 8(%edi)\n" /* floatvalue */
        "testb $8, %ah\n" /* line 585 */
        "je .Lfc2ec4_000c2f63\n"
        "movzbl (%ecx), %eax\n" /* line 587 */
        "testb %al, %al\n"
        "je .Lfc2ec4_000c2fe5\n"
        "xorl %ebx, %ebx\n" /* dotfound */
        "jmp .Lfc2ec4_000c2f30\n"
        ".Lfc2ec4_000c2f07:\n"
        "fldt (%edi)\n" /* line 603 | floatvalue */
        "fmuls 0x2ed6b4\n" /* 10.0f */
        "movsbl (%ecx), %eax\n"
        "subl $0x30, %eax\n"
        "pushl %eax\n"
        "fiaddl (%esp)\n"
        "addl $4, %esp\n"
        "fld %st(0)\n"
        "fstpt (%edi)\n" /* floatvalue */
        ".Lfc2ec4_000c2f20:\n"
        "addl $1, %ecx\n" /* line 605 */
        "movzbl (%ecx), %eax\n" /* line 587 */
        "testb %al, %al\n"
        "je .Lfc2ec4_000c2fe7\n"
        "fstp %st(0)\n"
        ".Lfc2ec4_000c2f30:\n"
        "cmpb $0x2e, %al\n" /* line 589 */
        "je .Lfc2ec4_000c300a\n"
        "testl %ebx, %ebx\n" /* line 596 | dotfound */
        "je .Lfc2ec4_000c2f07\n"
        "xorl %edx, %edx\n"
        "pushl %edx\n"
        "pushl %ebx\n"
        "fildll (%esp)\n"
        "addl $8, %esp\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* dotfound */
        "leal (%eax, %eax), %ebx\n" /* dotfound */
        ".Lfc2ec4_000c2f4c:\n"
        "movsbl (%ecx), %eax\n" /* line 598 */
        "subl $0x30, %eax\n"
        "pushl %eax\n"
        "fidivrl (%esp)\n"
        "addl $4, %esp\n"
        "fldt (%edi)\n" /* floatvalue */
        "faddp %st(1)\n"
        "fld %st(0)\n"
        "fstpt (%edi)\n" /* floatvalue */
        "jmp .Lfc2ec4_000c2f20\n"
        ".Lfc2ec4_000c2f63:\n"
        "testb $8, %al\n" /* line 609 */
        "je .Lfc2ec4_000c2f9d\n"
        "movzbl (%ecx), %edx\n" /* line 611 */
        "testb %dl, %dl\n"
        "je .Lfc2ec4_000c2f87\n"
        "movl (%esi), %eax\n" /* intvalue */
        ".Lfc2ec4_000c2f70:\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 612 */
        "movsbl %dl, %edx\n"
        "leal -0x30(%edx, %eax, 2), %eax\n"
        "movl %eax, (%esi)\n" /* intvalue */
        "movzbl 1(%ecx), %edx\n" /* line 611 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lfc2ec4_000c2f70\n"
        ".Lfc2ec4_000c2f87:\n"
        "movl (%esi), %eax\n" /* line 646 | intvalue */
        "xorl %edx, %edx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "fildll (%esp)\n"
        "addl $8, %esp\n"
        "fstpt (%edi)\n" /* floatvalue */
        /* } scope */
        "addl $0x10, %esp\n" /* line 648 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc2ec4_000c2f9d:\n"
        "testb $1, %ah\n" /* line 615 */
        "je .Lfc2ec4_000c301e\n"
        "leal 2(%ecx), %ebx\n" /* line 618 | dotfound */
        "cmpb $0, 2(%ecx)\n" /* line 619 */
        "je .Lfc2ec4_000c2f87\n"
        "jmp .Lfc2ec4_000c2fc9\n"
        ".Lfc2ec4_000c2fad:\n"
        "leal -0x41(%edx), %eax\n" /* line 624 */
        "cmpb $5, %al\n"
        "ja .Lfc2ec4_000c304f\n"
        "movsbl %dl, %eax\n" /* line 625 */
        "leal -0x37(%ecx, %eax), %eax\n"
        "movl %eax, (%esi)\n" /* intvalue */
        ".Lfc2ec4_000c2fc1:\n"
        "addl $1, %ebx\n" /* line 628 | dotfound */
        "cmpb $0, (%ebx)\n" /* line 619 | dotfound */
        "je .Lfc2ec4_000c2f87\n"
        ".Lfc2ec4_000c2fc9:\n"
        "movl (%esi), %ecx\n" /* line 621 | intvalue */
        "shll $4, %ecx\n"
        "movl %ecx, (%esi)\n" /* intvalue */
        "movzbl (%ebx), %edx\n" /* line 622 | dotfound */
        "leal -0x61(%edx), %eax\n"
        "cmpb $5, %al\n"
        "ja .Lfc2ec4_000c2fad\n"
        "movsbl %dl, %eax\n" /* line 623 */
        "leal -0x57(%ecx, %eax), %eax\n"
        "movl %eax, (%esi)\n" /* intvalue */
        "jmp .Lfc2ec4_000c2fc1\n"
        ".Lfc2ec4_000c2fe5:\n"
        "fldt (%edi)\n" /* floatvalue */
        ".Lfc2ec4_000c2fe7:\n"
        "fnstcw -0xe(%ebp)\n" /* line 607 */
        "movzwl -0xe(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x10(%ebp)\n"
        "fldcw -0x10(%ebp)\n"
        "fistpll -0x1c(%ebp)\n"
        "fldcw -0xe(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esi)\n" /* intvalue */
        /* } scope */
        ".Lfc2ec4_000c3002:\n"
        "addl $0x10, %esp\n" /* line 648 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc2ec4_000c300a:\n"
        "testl %ebx, %ebx\n" /* line 591 | dotfound */
        "jne .Lfc2ec4_000c3002\n"
        "addl $1, %ecx\n" /* line 594 */
        "flds 0x2ed6b4\n" /* 10.0f */
        "movb $0x64, %bl\n" /* dotfound */
        "jmp .Lfc2ec4_000c2f4c\n"
        ".Lfc2ec4_000c301e:\n"
        "testb $2, %ah\n" /* line 632 */
        "je .Lfc2ec4_000c305d\n"
        "leal 1(%ecx), %eax\n" /* line 635 */
        "movzbl 1(%ecx), %edx\n" /* line 636 */
        "testb %dl, %dl\n"
        "je .Lfc2ec4_000c2f87\n"
        "movl %eax, %ecx\n"
        "movl (%esi), %eax\n" /* intvalue */
        ".Lfc2ec4_000c3036:\n"
        "movsbl %dl, %edx\n" /* line 637 */
        "leal -0x30(%edx, %eax, 8), %eax\n"
        "movl %eax, (%esi)\n" /* intvalue */
        "movzbl 1(%ecx), %edx\n" /* line 636 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lfc2ec4_000c3036\n"
        "jmp .Lfc2ec4_000c2f87\n"
        ".Lfc2ec4_000c304f:\n"
        "movsbl %dl, %eax\n" /* line 627 */
        "leal -0x30(%ecx, %eax), %eax\n"
        "movl %eax, (%esi)\n" /* intvalue */
        "jmp .Lfc2ec4_000c2fc1\n"
        ".Lfc2ec4_000c305d:\n"
        "testb $4, %ah\n" /* line 640 */
        "je .Lfc2ec4_000c3002\n"
        "leal 2(%ecx), %eax\n" /* line 643 */
        "movzbl 2(%ecx), %edx\n" /* line 644 */
        "testb %dl, %dl\n"
        "je .Lfc2ec4_000c2f87\n"
        "movl %eax, %ecx\n"
        "movl (%esi), %eax\n" /* intvalue */
        ".Lfc2ec4_000c3075:\n"
        "movsbl %dl, %edx\n" /* line 645 */
        "leal -0x30(%edx, %eax, 2), %eax\n"
        "movl %eax, (%esi)\n" /* intvalue */
        "movzbl 1(%ecx), %edx\n" /* line 644 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lfc2ec4_000c3075\n"
        "jmp .Lfc2ec4_000c2f87\n"
    );
}

/* line 657 */
__attribute__((naked))
int PS_ReadNumber(script_t *script, token_t *token)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 657 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* script */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 666 | token */
        "movl $3, 0x400(%eax)\n"
        "movl 0x44(%edi), %ecx\n" /* line 668 | script */
        "movl %ecx, %edx\n"
        "movzbl (%ecx), %ebx\n"
        "cmpb $0x30, %bl\n"
        "je .Lfc308e_000c3224\n"
        ".Lfc308e_000c30b8:\n"
        "xorl %eax, %eax\n" /* line 687 */
        "cmpb $0x30, %bl\n"
        "sete %al\n"
        "movl %eax, -0x20(%ebp)\n" /* octal */
        "movl 0xc(%ebp), %ebx\n" /* token */
        "xorl %esi, %esi\n" /* len */
        "movl $0, -0x1c(%ebp)\n" /* dot */
        "jmp .Lfc308e_000c30f9\n"
        ".Lfc308e_000c30d1:\n"
        "leal -0x38(%edx), %eax\n" /* line 716 */
        "cmpb $1, %al\n"
        "jbe .Lfc308e_000c310a\n"
        "leal -0x30(%edx), %eax\n" /* line 718 */
        "cmpb $9, %al\n"
        "ja .Lfc308e_000c3113\n"
        ".Lfc308e_000c30df:\n"
        "movb %dl, (%ebx)\n" /* line 720 */
        "addl $1, %esi\n" /* len */
        "addl $1, %ecx\n"
        "movl %ecx, 0x44(%edi)\n" /* script */
        "addl $1, %ebx\n"
        "cmpl $0x3ff, %esi\n" /* line 721 | len */
        "je .Lfc308e_000c32f3\n"
        ".Lfc308e_000c30f9:\n"
        "movzbl (%ecx), %edx\n" /* line 713 */
        "cmpb $0x2e, %dl\n" /* line 714 */
        "jne .Lfc308e_000c30d1\n"
        "movl $1, -0x1c(%ebp)\n" /* dot */
        "jmp .Lfc308e_000c30df\n"
        ".Lfc308e_000c310a:\n"
        "movl $0, -0x20(%ebp)\n" /* line 716 | octal */
        "jmp .Lfc308e_000c30df\n"
        ".Lfc308e_000c3113:\n"
        "movl -0x20(%ebp), %eax\n" /* line 727 | octal */
        "testl %eax, %eax\n"
        "je .Lfc308e_000c31c1\n"
        "movl 0xc(%ebp), %ecx\n" /* line 728 | token */
        "movl 0x404(%ecx), %edx\n"
        "orb $2, %dh\n"
        "movl %edx, 0x404(%ecx)\n"
        ".Lfc308e_000c3130:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 731 | dot */
        "testl %eax, %eax\n"
        "je .Lfc308e_000c3143\n"
        "orb $8, %dh\n" /* line 732 */
        "movl 0xc(%ebp), %ecx\n" /* token */
        "movl %edx, 0x404(%ecx)\n"
        ".Lfc308e_000c3143:\n"
        "movl $2, %ebx\n"
        ".Lfc308e_000c3148:\n"
        "movl 0x44(%edi), %ecx\n" /* line 736 | script */
        "movzbl (%ecx), %eax\n"
        "cmpb $0x6c, %al\n" /* line 738 */
        "je .Lfc308e_000c31d8\n"
        "cmpb $0x4c, %al\n"
        "je .Lfc308e_000c31d8\n"
        ".Lfc308e_000c315a:\n"
        "cmpb $0x75, %al\n" /* line 744 */
        "je .Lfc308e_000c31fe\n"
        "cmpb $0x55, %al\n"
        "je .Lfc308e_000c31fe\n"
        ".Lfc308e_000c316a:\n"
        "subl $1, %ebx\n" /* line 734 */
        "jne .Lfc308e_000c3148\n"
        "movl 0xc(%ebp), %eax\n" /* line 750 | token */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ebp), %eax\n" /* line 751 | token */
        "addl $0x410, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* token */
        "addl $0x408, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* token */
        "movl %edx, (%esp)\n"
        "calll NumberValue\n"
        "movl 0xc(%ebp), %ecx\n" /* line 752 | token */
        "movl 0x404(%ecx), %eax\n"
        "testb $8, %ah\n"
        "jne .Lfc308e_000c31b4\n"
        "orb $0x10, %ah\n" /* line 753 */
        "movl %eax, 0x404(%ecx)\n"
        ".Lfc308e_000c31b4:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lfc308e_000c31b9:\n"
        "addl $0x2c, %esp\n" /* line 755 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc308e_000c31c1:\n"
        "movl 0xc(%ebp), %eax\n" /* line 730 | token */
        "movl 0x404(%eax), %edx\n"
        "orl $8, %edx\n"
        "movl %edx, 0x404(%eax)\n"
        "jmp .Lfc308e_000c3130\n"
        ".Lfc308e_000c31d8:\n"
        "testb $0x20, %dh\n" /* line 738 */
        "jne .Lfc308e_000c315a\n"
        "addl $1, %ecx\n" /* line 740 */
        "movl %ecx, 0x44(%edi)\n" /* script */
        "movl 0xc(%ebp), %eax\n" /* line 741 | token */
        "movl 0x404(%eax), %edx\n"
        "orb $0x20, %dh\n"
        "movl %edx, 0x404(%eax)\n"
        "jmp .Lfc308e_000c316a\n"
        ".Lfc308e_000c31fe:\n"
        "testb $0x48, %dh\n" /* line 744 */
        "jne .Lfc308e_000c316a\n"
        "addl $1, %ecx\n" /* line 746 */
        "movl %ecx, 0x44(%edi)\n" /* script */
        "movl 0xc(%ebp), %ecx\n" /* line 747 | token */
        "movl 0x404(%ecx), %edx\n"
        "orb $0x40, %dh\n"
        "movl %edx, 0x404(%ecx)\n"
        "jmp .Lfc308e_000c316a\n"
        ".Lfc308e_000c3224:\n"
        "leal 1(%ecx), %esi\n" /* line 668 | len */
        "movzbl 1(%ecx), %eax\n"
        "cmpb $0x78, %al\n"
        "je .Lfc308e_000c3280\n"
        "cmpb $0x58, %al\n"
        "je .Lfc308e_000c3280\n"
        "cmpb $0x62, %al\n" /* line 687 */
        "je .Lfc308e_000c323f\n"
        "cmpb $0x42, %al\n"
        "jne .Lfc308e_000c30b8\n"
        ".Lfc308e_000c323f:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 689 | token */
        "movb $0x30, (%ecx)\n"
        "movl %esi, 0x44(%edi)\n" /* len, script */
        "movzbl 1(%edx), %eax\n" /* line 690 */
        "movb %al, 1(%ecx)\n"
        "leal 2(%edx), %ecx\n"
        "movl %ecx, 0x44(%edi)\n" /* script */
        "movzbl 2(%edx), %ecx\n" /* line 691 */
        "leal -0x30(%ecx), %eax\n" /* line 693 */
        "cmpb $1, %al\n"
        "jbe .Lfc308e_000c3312\n"
        "movl $2, %esi\n" /* len */
        ".Lfc308e_000c3269:\n"
        "movl 0xc(%ebp), %eax\n" /* line 703 | token */
        "movl 0x404(%eax), %edx\n"
        "orb $4, %dh\n"
        "movl %edx, 0x404(%eax)\n"
        "jmp .Lfc308e_000c3143\n"
        ".Lfc308e_000c3280:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 670 | token */
        "movb $0x30, (%ecx)\n"
        "movl %esi, 0x44(%edi)\n" /* len, script */
        "movzbl 1(%edx), %eax\n" /* line 671 */
        "movb %al, 1(%ecx)\n"
        "leal 2(%edx), %ecx\n"
        "movl %ecx, 0x44(%edi)\n" /* script */
        "movzbl 2(%edx), %edx\n" /* line 672 */
        "movl 0xc(%ebp), %ebx\n" /* token */
        "movl $2, %esi\n" /* len */
        "jmp .Lfc308e_000c32c9\n"
        ".Lfc308e_000c32a4:\n"
        "movl 0x44(%edi), %edx\n" /* line 676 | script */
        "movzbl (%edx), %eax\n"
        "movb %al, 2(%ebx)\n"
        "addl $1, %esi\n" /* len */
        "leal 1(%edx), %ecx\n"
        "movl %ecx, 0x44(%edi)\n" /* script */
        "addl $1, %ebx\n"
        "cmpl $0x400, %esi\n" /* line 677 | len */
        "je .Lfc308e_000c336f\n"
        "movzbl 1(%edx), %edx\n" /* line 682 */
        ".Lfc308e_000c32c9:\n"
        "leal -0x30(%edx), %eax\n" /* line 674 */
        "cmpb $9, %al\n"
        "jbe .Lfc308e_000c32a4\n"
        "leal -0x61(%edx), %eax\n"
        "cmpb $5, %al\n"
        "jbe .Lfc308e_000c32a4\n"
        "cmpb $0x41, %dl\n"
        "je .Lfc308e_000c32a4\n"
        "movl 0xc(%ebp), %eax\n" /* line 684 | token */
        "movl 0x404(%eax), %edx\n"
        "orb $1, %dh\n"
        "movl %edx, 0x404(%eax)\n"
        "jmp .Lfc308e_000c3143\n"
        ".Lfc308e_000c32f3:\n"
        "movl $0x400, 8(%esp)\n" /* line 723 */
        "movl $0x2229ec, 4(%esp)\n" /* "number longer than MAX_TOKEN = %d" */
        "movl %edi, (%esp)\n" /* script */
        "calll ScriptError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc308e_000c31b9\n"
        ".Lfc308e_000c3312:\n"
        "movl 0xc(%ebp), %eax\n" /* line 695 | token */
        "movb %cl, 2(%eax)\n"
        "leal 3(%edx), %eax\n"
        "movl %eax, 0x44(%edi)\n" /* script */
        "movl 0xc(%ebp), %ecx\n" /* token */
        "movl $3, %esi\n" /* len */
        ".Lfc308e_000c3326:\n"
        "movzbl (%eax), %eax\n" /* line 693 */
        "subb $0x30, %al\n"
        "cmpb $1, %al\n"
        "ja .Lfc308e_000c3269\n"
        "movl 0x44(%edi), %edx\n" /* line 695 | script */
        "movzbl (%edx), %eax\n"
        "movb %al, 3(%ecx)\n"
        "addl $1, %esi\n" /* len */
        "leal 1(%edx), %eax\n"
        "movl %eax, 0x44(%edi)\n" /* script */
        "addl $1, %ecx\n"
        "cmpl $0x400, %esi\n" /* line 696 | len */
        "jne .Lfc308e_000c3326\n"
        "movl $0x400, 8(%esp)\n" /* line 698 */
        "movl $0x2229c0, 4(%esp)\n" /* "binary number longer than MAX_TOKEN = %d" */
        "movl %edi, (%esp)\n" /* script */
        "calll ScriptError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc308e_000c31b9\n"
        ".Lfc308e_000c336f:\n"
        "movl $0x400, 8(%esp)\n" /* line 679 */
        "movl $0x222990, 4(%esp)\n" /* "hexadecimal number longer than MAX_TOKEN = %d" */
        "movl %edi, (%esp)\n" /* script */
        "calll ScriptError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc308e_000c31b9\n"
    );
}

/* line 1179 */
__attribute__((naked))
void StripDoubleQuotes(char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1179 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* string */
        "cmpb $0x22, (%ebx)\n" /* line 1181 | string */
        "je .Lfc3390_000c33c3\n"
        ".Lfc3390_000c33a0:\n"
        "cld\n" /* line 1185 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* string */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %eax\n"
        "cmpb $0x22, -1(%eax)\n"
        "jne .Lfc3390_000c33bc\n"
        "movb $0, -1(%eax)\n" /* line 1187 */
        ".Lfc3390_000c33bc:\n"
        "addl $0x10, %esp\n" /* line 1189 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc3390_000c33c3:\n"
        "leal 1(%ebx), %eax\n" /* line 1183 | string */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* string */
        "calll strcpy\n"
        "jmp .Lfc3390_000c33a0\n"
    );
}

/* line 1318 */
__attribute__((naked))
int EndOfScript(script_t *script)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1318 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* script */
        "movl 0x44(%edx), %eax\n"
        "cmpl 0x48(%edx), %eax\n"
        "setae %al\n"
        "movzbl %al, %eax\n"
        "popl %ebp\n" /* line 1321 */
        "retl\n"
    );
}

/* line 1457 */
__attribute__((naked))
void FreeScript(script_t *script)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1457 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* script */
        "movl 0x70(%ebx), %eax\n" /* line 1459 | script */
        "testl %eax, %eax\n"
        "je .Lfc33ea_000c3403\n"
        "movl %eax, (%esp)\n" /* line 1460 */
        "calll FreeMemory\n"
        ".Lfc33ea_000c3403:\n"
        "movl %ebx, 8(%ebp)\n" /* line 1461 | script */
        "addl $0x14, %esp\n" /* line 1462 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp FreeMemory\n" /* line 1461 */
    );
}

/* line 1371 */
__attribute__((naked))
script_t * LoadScriptFile(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1371 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %edi\n" /* filename */
        /* { scope 1 */
        "movl %edi, 0xc(%esp)\n" /* line 1379 | filename */
        "movl $0x216058, 8(%esp)\n" /* "%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x5c(%ebp), %ebx\n" /* pathname, script */
        "movl %ebx, (%esp)\n" /* script */
        "calll Com_sprintf\n"
        "movl $1, 8(%esp)\n" /* line 1380 */
        "leal -0x1c(%ebp), %eax\n" /* fp */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* script */
        "calll FS_FOpenFileRead\n"
        "movl %eax, %esi\n" /* length */
        "movl -0x1c(%ebp), %eax\n" /* line 1381 | fp */
        "testl %eax, %eax\n"
        "jne .Lfc3410_000c3467\n"
        "xorl %ebx, %ebx\n" /* script */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1411 | script */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc3410_000c3467:\n"
        "leal 0x4d1(%esi), %eax\n" /* line 1384 | length */
        "movl %eax, (%esp)\n"
        "calll GetClearedMemory\n"
        "movl %eax, %ebx\n" /* script */
        "movl %edi, 4(%esp)\n" /* line 1387 | filename */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "leal 0x4d0(%ebx), %eax\n" /* line 1388 | script */
        "movl %eax, 0x40(%ebx)\n" /* script */
        "movb $0, 0x4d0(%ebx, %esi)\n" /* line 1389 | script */
        "movl %esi, 0x58(%ebx)\n" /* line 1390 | length, script */
        "movl 0x40(%ebx), %eax\n" /* line 1392 | script */
        "movl %eax, 0x44(%ebx)\n" /* script */
        "movl %eax, 0x4c(%ebx)\n" /* line 1394 | script */
        "leal (%esi, %eax), %eax\n" /* line 1396 | length */
        "movl %eax, 0x48(%ebx)\n" /* script */
        "movl $0, 0x64(%ebx)\n" /* line 1398 | script */
        "movl $1, 0x5c(%ebx)\n" /* line 1400 | script */
        "movl $1, 0x60(%ebx)\n" /* line 1401 | script */
        "movl $default_punctuations, 4(%esp)\n" /* line 263 */
        "movl %ebx, (%esp)\n"
        "calll PS_CreatePunctuationTable\n"
        "movl $default_punctuations, 0x6c(%ebx)\n" /* line 264 */
        "movl -0x1c(%ebp), %eax\n" /* line 1405 | fp */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* length */
        "movl 0x40(%ebx), %eax\n" /* script */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1406 | fp */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl 0x40(%ebx), %eax\n" /* line 1408 | script */
        "movl %eax, (%esp)\n"
        "calll Com_Compress\n"
        "movl %eax, 0x58(%ebx)\n" /* script */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1411 | script */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 455 */
__attribute__((naked))
int PS_ReadString(script_t *script, token_t *token, int quote)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 455 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* script */
        /* { scope 1 */
        "cmpl $0x22, 0x10(%ebp)\n" /* line 460 | quote */
        "je .Lfc350c_000c36db\n"
        "movl 0xc(%ebp), %edx\n" /* line 463 | token */
        "movl $2, 0x400(%edx)\n"
        ".Lfc350c_000c352f:\n"
        "movl 0x44(%edi), %edx\n" /* line 467 | script */
        "movzbl (%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* token */
        "movb %al, (%ecx)\n"
        "addl $1, %edx\n"
        "movl %edx, 0x44(%edi)\n" /* script */
        "movl $1, -0x24(%ebp)\n" /* len */
        ".Lfc350c_000c3547:\n"
        "movl 0x44(%edi), %edx\n" /* line 479 | script */
        "movzbl (%edx), %ecx\n"
        "cmpb $0x5c, %cl\n"
        "je .Lfc350c_000c35ab\n"
        ".Lfc350c_000c3552:\n"
        "movsbl %cl, %eax\n" /* line 489 */
        "cmpl %eax, 0x10(%ebp)\n" /* quote */
        "je .Lfc350c_000c35d1\n"
        "testb %cl, %cl\n" /* line 518 */
        "je .Lfc350c_000c3712\n"
        "cmpb $0xa, %cl\n" /* line 524 */
        "je .Lfc350c_000c36ed\n"
        "movl 0xc(%ebp), %eax\n" /* line 530 | token */
        "movl -0x24(%ebp), %ebx\n" /* len */
        "movb %cl, (%eax, %ebx)\n"
        "addl $1, %ebx\n"
        "movl %ebx, -0x24(%ebp)\n" /* len */
        ".Lfc350c_000c357a:\n"
        "addl $1, %edx\n"
        "movl %edx, 0x44(%edi)\n" /* script */
        ".Lfc350c_000c3580:\n"
        "cmpl $0x3fd, -0x24(%ebp)\n" /* line 472 | len */
        "jle .Lfc350c_000c3547\n"
        "movl $0x400, 8(%esp)\n" /* line 474 */
        "movl $0x222a3c, 4(%esp)\n" /* "string longer than MAX_TOKEN = %d" */
        "movl %edi, (%esp)\n" /* script */
        "calll ScriptError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 540 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc350c_000c35ab:\n"
        "testb $8, 0x68(%edi)\n" /* line 479 | script */
        "jne .Lfc350c_000c3552\n"
        "movl 0xc(%ebp), %ebx\n" /* line 481 | token */
        "addl -0x24(%ebp), %ebx\n" /* len */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* script */
        "calll PS_ReadEscapeCharacter\n"
        "testl %eax, %eax\n"
        "je .Lfc350c_000c3750\n"
        "addl $1, -0x24(%ebp)\n" /* line 486 | len */
        "jmp .Lfc350c_000c3580\n"
        ".Lfc350c_000c35d1:\n"
        "addl $1, %edx\n" /* line 492 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %edx, 0x44(%edi)\n" /* script */
        "testb $4, 0x68(%edi)\n" /* line 494 | script */
        "jne .Lfc350c_000c365b\n"
        "movl 0x5c(%edi), %ebx\n" /* line 498 | script */
        "movl %ebx, -0x20(%ebp)\n" /* tmpline */
        "movl %ebx, %esi\n"
        ".Lfc350c_000c35e8:\n"
        "movzbl (%edx), %eax\n" /* line 282 */
        "cmpb $0x20, %al\n"
        "jle .Lfc350c_000c368c\n"
        "cmpb $0x2f, %al\n" /* line 291 */
        "jne .Lfc350c_000c3733\n"
        "leal 1(%edx), %ecx\n" /* line 294 */
        "movzbl 1(%edx), %eax\n"
        "cmpb $0x2f, %al\n"
        "je .Lfc350c_000c36a7\n"
        "cmpb $0x2a, %al\n" /* line 311 */
        "jne .Lfc350c_000c3733\n"
        "movl %ecx, 0x44(%edi)\n" /* line 313 */
        "leal 1(%ecx), %ecx\n"
        ".Lfc350c_000c3618:\n"
        "movl %ecx, %edx\n" /* line 316 */
        "movl %ecx, %ebx\n"
        "leal 1(%ecx), %ecx\n"
        "movl %edx, 0x44(%edi)\n"
        "movzbl -1(%ecx), %eax\n" /* line 317 */
        "testb %al, %al\n"
        "je .Lfc350c_000c364f\n"
        "cmpb $0xa, %al\n" /* line 319 */
        "je .Lfc350c_000c3684\n"
        ".Lfc350c_000c362e:\n"
        "cmpb $0x2a, -1(%ecx)\n" /* line 314 */
        "jne .Lfc350c_000c3618\n"
        "cmpb $0x2f, 1(%edx)\n"
        "jne .Lfc350c_000c3618\n"
        "movl %ecx, 0x44(%edi)\n" /* line 323 */
        "cmpb $0, 1(%ebx)\n" /* line 324 */
        "je .Lfc350c_000c364f\n"
        "leal 2(%ebx), %edx\n" /* line 326 */
        "movl %edx, 0x44(%edi)\n"
        "cmpb $0, 2(%ebx)\n" /* line 327 */
        "jne .Lfc350c_000c35e8\n"
        ".Lfc350c_000c364f:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 502 */
        "movl %eax, 0x44(%edi)\n" /* script */
        "movl -0x20(%ebp), %edx\n" /* line 503 | tmpline */
        "movl %edx, 0x5c(%edi)\n" /* script */
        ".Lfc350c_000c365b:\n"
        "movzbl 0x10(%ebp), %eax\n" /* line 534 | quote */
        "movl 0xc(%ebp), %edx\n" /* token */
        "movl -0x24(%ebp), %ecx\n" /* len */
        "movb %al, (%edx, %ecx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %eax\n"
        "movb $0, (%edx, %eax)\n" /* line 536 */
        "movl %eax, 0x404(%edx)\n" /* line 538 */
        "movl $1, %eax\n"
        /* } scope */
        ".Lfc350c_000c367c:\n"
        "addl $0x2c, %esp\n" /* line 540 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc350c_000c3684:\n"
        "addl $1, %esi\n" /* line 320 */
        "movl %esi, 0x5c(%edi)\n"
        "jmp .Lfc350c_000c362e\n"
        ".Lfc350c_000c368c:\n"
        "testb %al, %al\n" /* line 284 */
        "je .Lfc350c_000c364f\n"
        "cmpb $0xa, %al\n" /* line 286 */
        "je .Lfc350c_000c369f\n"
        ".Lfc350c_000c3694:\n"
        "addl $1, %edx\n" /* line 288 */
        "movl %edx, 0x44(%edi)\n"
        "jmp .Lfc350c_000c35e8\n"
        ".Lfc350c_000c369f:\n"
        "addl $1, %esi\n" /* line 287 */
        "movl %esi, 0x5c(%edi)\n"
        "jmp .Lfc350c_000c3694\n"
        ".Lfc350c_000c36a7:\n"
        "movl %ecx, %edx\n" /* line 296 */
        "movl %ecx, 0x44(%edi)\n"
        ".Lfc350c_000c36ac:\n"
        "movl %edx, %ecx\n" /* line 299 */
        "addl $1, %edx\n"
        "movl %edx, 0x44(%edi)\n"
        "movzbl 1(%ecx), %eax\n" /* line 300 */
        "testb %al, %al\n"
        "je .Lfc350c_000c364f\n"
        "cmpb $0xa, %al\n" /* line 297 */
        "jne .Lfc350c_000c36ac\n"
        "addl $1, %esi\n" /* line 304 */
        "movl %esi, 0x5c(%edi)\n"
        "leal 2(%ecx), %edx\n" /* line 305 */
        "movl %edx, 0x44(%edi)\n"
        "cmpb $0, 2(%ecx)\n" /* line 306 */
        "jne .Lfc350c_000c35e8\n"
        "jmp .Lfc350c_000c364f\n"
        ".Lfc350c_000c36db:\n"
        "movl 0xc(%ebp), %eax\n" /* line 461 | token */
        "movl $1, 0x400(%eax)\n"
        "jmp .Lfc350c_000c352f\n"
        ".Lfc350c_000c36ed:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 526 | token */
        "movl -0x24(%ebp), %eax\n" /* len */
        "movb $0, (%ebx, %eax)\n"
        "movl %ebx, 8(%esp)\n" /* line 527 */
        "movl $0x222a78, 4(%esp)\n" /* "newline inside string %s" */
        "movl %edi, (%esp)\n" /* script */
        "calll ScriptError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc350c_000c367c\n"
        ".Lfc350c_000c3712:\n"
        "movl 0xc(%ebp), %edx\n" /* line 520 | token */
        "movl -0x24(%ebp), %ecx\n" /* len */
        "movb $0, (%edx, %ecx)\n"
        "movl $0x222a60, 4(%esp)\n" /* line 521 */
        "movl %edi, (%esp)\n" /* script */
        "calll ScriptError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc350c_000c367c\n"
        ".Lfc350c_000c3733:\n"
        "movsbl (%edx), %eax\n" /* line 507 */
        "cmpl %eax, 0x10(%ebp)\n" /* quote */
        "je .Lfc350c_000c357a\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 509 */
        "movl %ecx, 0x44(%edi)\n" /* script */
        "movl -0x20(%ebp), %ebx\n" /* line 510 | tmpline */
        "movl %ebx, 0x5c(%edi)\n" /* script */
        "jmp .Lfc350c_000c365b\n"
        ".Lfc350c_000c3750:\n"
        "movb $0, (%ebx)\n" /* line 483 */
        "xorl %eax, %eax\n"
        "jmp .Lfc350c_000c367c\n"
    );
}

/* line 876 */
__attribute__((naked))
int PS_ReadToken(script_t *script, token_t *token)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 876 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* script */
        "movl 0xc(%ebp), %esi\n" /* token */
        "movl 0x64(%ebx), %eax\n" /* line 879 | script */
        "testl %eax, %eax\n"
        "je .Lfc375a_000c379e\n"
        "movl $0, 0x64(%ebx)\n" /* line 881 | script */
        "leal 0x80(%ebx), %eax\n" /* line 882 | script */
        "movl $0x440, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* token */
        "calll memcpy\n"
        "movl $1, %eax\n"
        ".Lfc375a_000c3796:\n"
        "addl $0x3c, %esp\n" /* line 944 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc375a_000c379e:\n"
        "movl 0x44(%ebx), %eax\n" /* line 886 | script */
        "movl %eax, 0x4c(%ebx)\n" /* script */
        "movl 0x5c(%ebx), %eax\n" /* line 888 | script */
        "movl %eax, 0x60(%ebx)\n" /* script */
        "movl $0x440, 8(%esp)\n" /* line 890 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* token */
        "calll memset\n"
        "movl 0x44(%ebx), %eax\n" /* line 892 | script */
        "movl %eax, 0x50(%ebx)\n" /* script */
        "movl %eax, 0x420(%esi)\n" /* line 893 | token */
        "movl 0x44(%ebx), %ecx\n" /* script */
        ".Lfc375a_000c37d1:\n"
        "movzbl (%ecx), %eax\n" /* line 282 */
        "cmpb $0x20, %al\n"
        "jle .Lfc375a_000c3840\n"
        "cmpb $0x2f, %al\n" /* line 291 */
        "jne .Lfc375a_000c3887\n"
        "leal 1(%ecx), %edx\n" /* line 294 */
        "movzbl 1(%ecx), %eax\n"
        "cmpb $0x2f, %al\n"
        "je .Lfc375a_000c3850\n"
        "cmpb $0x2a, %al\n" /* line 311 */
        "jne .Lfc375a_000c3887\n"
        "movl %edx, 0x44(%ebx)\n" /* line 313 */
        "leal 1(%edx), %edx\n"
        ".Lfc375a_000c37f9:\n"
        "movl %edx, %ecx\n" /* line 316 */
        "movl %edx, %edi\n"
        "leal 1(%edx), %edx\n"
        "movl %ecx, 0x44(%ebx)\n"
        "movzbl -1(%edx), %eax\n" /* line 317 */
        "testb %al, %al\n"
        "je .Lfc375a_000c3830\n"
        "cmpb $0xa, %al\n" /* line 319 */
        "je .Lfc375a_000c383a\n"
        ".Lfc375a_000c380f:\n"
        "cmpb $0x2a, -1(%edx)\n" /* line 314 */
        "jne .Lfc375a_000c37f9\n"
        "cmpb $0x2f, 1(%ecx)\n"
        "jne .Lfc375a_000c37f9\n"
        "movl %edx, 0x44(%ebx)\n" /* line 323 */
        "cmpb $0, 1(%edi)\n" /* line 324 */
        "je .Lfc375a_000c3830\n"
        "leal 2(%edi), %ecx\n" /* line 326 */
        "movl %ecx, 0x44(%ebx)\n"
        "cmpb $0, 2(%edi)\n" /* line 327 */
        "jne .Lfc375a_000c37d1\n"
        ".Lfc375a_000c3830:\n"
        "xorl %eax, %eax\n" /* line 937 */
        ".Lfc375a_000c3832:\n"
        "addl $0x3c, %esp\n" /* line 944 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc375a_000c383a:\n"
        "addl $1, 0x5c(%ebx)\n" /* line 320 */
        "jmp .Lfc375a_000c380f\n"
        ".Lfc375a_000c3840:\n"
        "testb %al, %al\n" /* line 284 */
        "je .Lfc375a_000c3830\n"
        "cmpb $0xa, %al\n" /* line 286 */
        "je .Lfc375a_000c3881\n"
        ".Lfc375a_000c3848:\n"
        "addl $1, %ecx\n" /* line 288 */
        "movl %ecx, 0x44(%ebx)\n"
        "jmp .Lfc375a_000c37d1\n"
        ".Lfc375a_000c3850:\n"
        "movl %edx, %ecx\n" /* line 296 */
        "movl %edx, 0x44(%ebx)\n"
        ".Lfc375a_000c3855:\n"
        "movl %ecx, %edx\n" /* line 299 */
        "addl $1, %ecx\n"
        "movl %ecx, 0x44(%ebx)\n"
        "movzbl 1(%edx), %eax\n" /* line 300 */
        "testb %al, %al\n"
        "je .Lfc375a_000c3830\n"
        "cmpb $0xa, %al\n" /* line 297 */
        "jne .Lfc375a_000c3855\n"
        "addl $1, 0x5c(%ebx)\n" /* line 304 */
        "leal 2(%edx), %ecx\n" /* line 305 */
        "movl %ecx, 0x44(%ebx)\n"
        "cmpb $0, 2(%edx)\n" /* line 306 */
        "jne .Lfc375a_000c37d1\n"
        "xorl %eax, %eax\n" /* line 937 */
        "jmp .Lfc375a_000c3832\n"
        ".Lfc375a_000c3881:\n"
        "addl $1, 0x5c(%ebx)\n" /* line 287 */
        "jmp .Lfc375a_000c3848\n"
        ".Lfc375a_000c3887:\n"
        "movl %ecx, 0x54(%ebx)\n" /* line 898 | script */
        "movl %ecx, 0x424(%esi)\n" /* line 899 | token */
        "movl 0x5c(%ebx), %eax\n" /* line 901 | script */
        "movl %eax, 0x428(%esi)\n" /* token */
        "movl 0x5c(%ebx), %eax\n" /* line 903 | script */
        "subl 0x60(%ebx), %eax\n" /* script */
        "movl %eax, 0x42c(%esi)\n" /* token */
        "movl 0x44(%ebx), %eax\n" /* line 905 | script */
        "movl %eax, -0x2c(%ebp)\n"
        "movzbl (%eax), %edx\n"
        "cmpb $0x22, %dl\n"
        "je .Lfc375a_000c3a9e\n"
        "cmpb $0x27, %dl\n" /* line 911 */
        "je .Lfc375a_000c3ac8\n"
        "leal -0x30(%edx), %eax\n" /* line 918 */
        "cmpb $9, %al\n"
        "jbe .Lfc375a_000c3955\n"
        "cmpb $0x2e, %dl\n"
        "je .Lfc375a_000c3944\n"
        ".Lfc375a_000c38d0:\n"
        "testb $0x10, 0x68(%ebx)\n" /* line 924 | script */
        "je .Lfc375a_000c396c\n"
        /* { scope 1 */
        "cmpb $0x20, %dl\n" /* line 853 */
        "jle .Lfc375a_000c3ac1\n"
        "cmpb $0x3b, %dl\n"
        "je .Lfc375a_000c3ac1\n"
        "movl %esi, %ecx\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc375a_000c3905\n"
        ".Lfc375a_000c38f2:\n"
        "cmpb $0x3b, %dl\n"
        "je .Lfc375a_000c391c\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 924 */
        /* { scope 1 */
        "cmpl $0x400, %eax\n" /* line 855 */
        "je .Lfc375a_000c3ae9\n"
        ".Lfc375a_000c3905:\n"
        "movb %dl, (%ecx)\n" /* line 860 */
        "addl $1, %eax\n"
        "addl $1, -0x2c(%ebp)\n"
        "movl -0x2c(%ebp), %edi\n" /* len */
        "movl %edi, 0x44(%ebx)\n" /* len */
        "movzbl (%edi), %edx\n" /* line 853 | len */
        "cmpb $0x20, %dl\n"
        "jg .Lfc375a_000c38f2\n"
        ".Lfc375a_000c391c:\n"
        "movb $0, (%esi, %eax)\n" /* line 862 */
        /* } scope */
        ".Lfc375a_000c3920:\n"
        "leal 0x80(%ebx), %eax\n" /* line 941 | script */
        "movl $0x440, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* token */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $1, %eax\n"
        "jmp .Lfc375a_000c3796\n"
        ".Lfc375a_000c3944:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 918 */
        "movzbl 1(%ecx), %eax\n"
        "subb $0x30, %al\n"
        "cmpb $9, %al\n"
        "ja .Lfc375a_000c38d0\n"
        ".Lfc375a_000c3955:\n"
        "movl %esi, 4(%esp)\n" /* line 920 | token */
        "movl %ebx, (%esp)\n" /* script */
        "calll PS_ReadNumber\n"
        "testl %eax, %eax\n"
        "jne .Lfc375a_000c3920\n"
        "xorl %eax, %eax\n" /* line 937 */
        "jmp .Lfc375a_000c3832\n"
        ".Lfc375a_000c396c:\n"
        "leal -0x61(%edx), %eax\n" /* line 929 */
        "cmpb $0x19, %al\n"
        "jbe .Lfc375a_000c3a2a\n"
        "leal -0x41(%edx), %eax\n"
        "cmpb $0x19, %al\n"
        "jbe .Lfc375a_000c3a2a\n"
        "cmpb $0x5f, %dl\n"
        "je .Lfc375a_000c3a2a\n"
        /* { scope 1 */
        "movsbl %dl, %edx\n" /* line 819 */
        "movl 0x70(%ebx), %eax\n"
        "movl (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* punc */
        "testl %edx, %edx\n"
        "je .Lfc375a_000c3ad2\n"
        "movl 0x48(%ebx), %edi\n" /* line 824 | len */
        "movl %edi, -0x24(%ebp)\n" /* len */
        "jmp .Lfc375a_000c39b8\n"
        ".Lfc375a_000c39a7:\n"
        "movl -0x1c(%ebp), %edi\n" /* line 819 | punc, len */
        "movl 8(%edi), %edi\n" /* len */
        "movl %edi, -0x1c(%ebp)\n" /* len, punc */
        "testl %edi, %edi\n" /* len */
        "je .Lfc375a_000c3ad2\n"
        ".Lfc375a_000c39b8:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 821 | punc */
        "movl (%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* p */
        "cld\n" /* line 822 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n" /* len */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* len */
        "movl -0x2c(%ebp), %eax\n" /* line 824 */
        "addl %edi, %eax\n" /* len */
        "cmpl -0x24(%ebp), %eax\n"
        "ja .Lfc375a_000c39a7\n"
        "movl %edi, 8(%esp)\n" /* line 827 | len */
        "movl -0x20(%ebp), %edx\n" /* p */
        "movl %edx, 4(%esp)\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lfc375a_000c39a7\n"
        "movl $0x400, 8(%esp)\n" /* line 829 */
        "movl -0x20(%ebp), %edx\n" /* p */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll strncpy\n"
        "addl %edi, 0x44(%ebx)\n" /* line 830 | len */
        "movl $5, 0x400(%esi)\n" /* line 831 */
        "movl -0x1c(%ebp), %ecx\n" /* line 833 | punc */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 0x404(%esi)\n"
        "jmp .Lfc375a_000c3920\n"
        /* } scope */
        /* { scope 1 */
        ".Lfc375a_000c3a2a:\n"
        "movl $4, 0x400(%esi)\n" /* line 554 */
        "movl %esi, %edi\n"
        "movl $0, -0x28(%ebp)\n" /* len */
        ".Lfc375a_000c3a3d:\n"
        "movl 0x44(%ebx), %edx\n" /* line 557 */
        "movzbl (%edx), %eax\n"
        "movb %al, (%edi)\n"
        "addl $1, -0x28(%ebp)\n" /* len */
        "leal 1(%edx), %ecx\n"
        "movl %ecx, 0x44(%ebx)\n"
        "cmpl $0x400, -0x28(%ebp)\n" /* line 558 | len */
        "je .Lfc375a_000c3a7f\n"
        "movzbl 1(%edx), %edx\n" /* line 563 */
        "leal -0x61(%edx), %eax\n" /* line 555 */
        "cmpb $0x19, %al\n"
        "jbe .Lfc375a_000c3a7a\n"
        "leal -0x41(%edx), %eax\n"
        "cmpb $0x19, %al\n"
        "jbe .Lfc375a_000c3a7a\n"
        "leal -0x30(%edx), %eax\n"
        "cmpb $9, %al\n"
        "jbe .Lfc375a_000c3a7a\n"
        "cmpb $0x5f, %dl\n"
        "jne .Lfc375a_000c3b08\n"
        ".Lfc375a_000c3a7a:\n"
        "addl $1, %edi\n" /* line 554 */
        "jmp .Lfc375a_000c3a3d\n"
        ".Lfc375a_000c3a7f:\n"
        "movl $0x400, 8(%esp)\n" /* line 560 */
        "movl $0x222970, 4(%esp)\n" /* "name longer than MAX_TOKEN = %d" */
        "movl %ebx, (%esp)\n"
        "calll ScriptError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc375a_000c3796\n"
        /* } scope */
        ".Lfc375a_000c3a9e:\n"
        "movl $0x22, 8(%esp)\n" /* line 907 */
        ".Lfc375a_000c3aa6:\n"
        "movl %esi, 4(%esp)\n" /* line 914 | token */
        "movl %ebx, (%esp)\n" /* script */
        "calll PS_ReadString\n"
        "testl %eax, %eax\n"
        "jne .Lfc375a_000c3920\n"
        "xorl %eax, %eax\n" /* line 937 */
        "jmp .Lfc375a_000c3832\n"
        /* { scope 1 */
        ".Lfc375a_000c3ac1:\n"
        "xorl %eax, %eax\n" /* line 853 */
        "jmp .Lfc375a_000c391c\n"
        /* } scope */
        ".Lfc375a_000c3ac8:\n"
        "movl $0x27, 8(%esp)\n" /* line 914 */
        "jmp .Lfc375a_000c3aa6\n"
        ".Lfc375a_000c3ad2:\n"
        "movl $0x222a94, 4(%esp)\n" /* line 937 */
        "movl %ebx, (%esp)\n" /* script */
        "calll ScriptError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc375a_000c3832\n"
        /* { scope 1 */
        ".Lfc375a_000c3ae9:\n"
        "movl $0x400, 8(%esp)\n" /* line 857 */
        "movl $0x222a10, 4(%esp)\n" /* "primitive token longer than MAX_TOKEN = %d" */
        "movl %ebx, (%esp)\n"
        "calll ScriptError\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc375a_000c3796\n"
        /* } scope */
        /* { scope 1 */
        ".Lfc375a_000c3b08:\n"
        "movl -0x28(%ebp), %eax\n" /* line 565 | len */
        "movb $0, (%esi, %eax)\n"
        "movl %eax, 0x404(%esi)\n" /* line 567 */
        "jmp .Lfc375a_000c3920\n"
    );
}

