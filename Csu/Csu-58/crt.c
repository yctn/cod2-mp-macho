/* ASM dump from: crt.c */
/* Original path: /SourceCache/Csu/Csu-58/crt.c */

#include "common_types.h"
#include "imports.h"

extern int NXArgc; /* 0x0 */
extern char * *NXArgv; /* 0x0 */
extern char * *environ; /* 0x0 */
extern char *__progname; /* 0x0 */

void start(int argc, char * *argv, char * *envp);
static void call_mod_init_funcs(void);

/* line 181 */
__attribute__((naked))
void start(int argc, char * *argv, char * *envp)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 181 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 195 | argc */
        "movl %eax, 0x30583c(%ebx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 196 | argv */
        "movl %eax, 0x305840(%ebx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 197 | envp */
        "movl %eax, 0x305844(%ebx)\n"
        "movl 0x3135a4(%ebx), %eax\n" /* line 199 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf27b6_000027ed\n"
        "calll *%eax\n" /* line 200 */
        ".Lf27b6_000027ed:\n"
        "movl 0x3135ac(%ebx), %eax\n" /* line 201 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf27b6_000027fb\n"
        "calll *%eax\n" /* line 202 */
        ".Lf27b6_000027fb:\n"
        "calll 0x2ba6dd\n" /* line 205 */
        "calll call_mod_init_funcs\n" /* line 222 */
        "leal -0x1c(%ebp), %eax\n" /* line 240 | term */
        "movl %eax, 4(%esp)\n"
        "leal 0x212ff8(%ebx), %eax\n" /* "__dyld_mod_term_funcs" */
        "movl %eax, (%esp)\n"
        "calll __dyld_func_lookup\n"
        "movl -0x1c(%ebp), %eax\n" /* line 241 | term */
        "testl %eax, %eax\n"
        "je .Lf27b6_00002829\n"
        "movl %eax, (%esp)\n" /* line 242 */
        "calll 0x2ba6f6\n"
        ".Lf27b6_00002829:\n"
        "movl 0x3135a8(%ebx), %eax\n" /* line 245 */
        "movl $0, (%eax)\n"
        "movl 0xc(%ebp), %eax\n" /* line 247 | argv */
        "movl (%eax), %edi\n" /* p */
        "testl %edi, %edi\n" /* p */
        "jne .Lf27b6_000028a2\n"
        "jmp .Lf27b6_00002867\n"
        ".Lf27b6_00002840:\n"
        "cmpb $0x2f, %cl\n" /* line 250 */
        "cmovel %edx, %eax\n"
        "movl %esi, %edx\n"
        "movzbl (%esi), %ecx\n" /* line 249 */
        "leal 1(%esi), %esi\n"
        "testb %cl, %cl\n"
        "jne .Lf27b6_00002840\n"
        "testl %eax, %eax\n" /* line 253 */
        "je .Lf27b6_00002861\n"
        "addl $1, %eax\n" /* line 254 */
        "movl %eax, 0x305848(%ebx)\n"
        "jmp .Lf27b6_00002867\n"
        ".Lf27b6_00002861:\n"
        "movl %edi, 0x305848(%ebx)\n" /* line 256 | p */
        ".Lf27b6_00002867:\n"
        "movl 0x10(%ebp), %eax\n" /* line 267 | envp */
        "cmpl $0, (%eax)\n"
        "je .Lf27b6_0000287a\n"
        "movl 0x10(%ebp), %eax\n" /* envp */
        ".Lf27b6_00002872:\n"
        "addl $4, %eax\n"
        "cmpl $0, (%eax)\n"
        "jne .Lf27b6_00002872\n"
        ".Lf27b6_0000287a:\n"
        "addl $4, %eax\n" /* line 272 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* envp */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* argv */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* argc */
        "movl %eax, (%esp)\n"
        "calll main\n"
        "movl %eax, (%esp)\n"
        "calll 0x2ba6c4\n"
        ".Lf27b6_000028a2:\n"
        "movzbl (%edi), %ecx\n" /* line 249 | p */
        "testb %cl, %cl\n"
        "je .Lf27b6_00002861\n"
        "leal 1(%edi), %esi\n" /* p */
        "movl %edi, %edx\n" /* p */
        "movl $0, %eax\n"
        "jmp .Lf27b6_00002840\n"
    );
}

/* line 299 */
static __attribute__((naked))
void call_mod_init_funcs(void)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 299 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "leal -0xc(%ebp), %eax\n" /* line 302 | p */
        "movl %eax, 4(%esp)\n"
        "leal 0x212f13(%ebx), %eax\n" /* "__dyld_make_delayed_module_initializer_calls" */
        "movl %eax, (%esp)\n"
        "calll __dyld_func_lookup\n"
        "calll *-0xc(%ebp)\n" /* line 304 | p */
        "addl $0x24, %esp\n" /* line 305 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

