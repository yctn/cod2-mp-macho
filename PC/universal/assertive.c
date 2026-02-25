/* ASM dump from: assertive.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/assertive.cpp */

#include "common_types.h"
#include "imports.h"

static Bool shouldQuitOnError; /* 0x4ea680 */

void RefreshQuitOnErrorCondition(void);
Bool QuitOnError(void);

/* line 1310 */
__attribute__((naked))
void RefreshQuitOnErrorCondition(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1310 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll Dvar_IsSystemActive\n" /* line 1314 */
        "testb %al, %al\n"
        "jne .Lf77e0c_00077e1d\n"
        "leave\n" /* line 1325 */
        "retl\n"
        ".Lf77e0c_00077e1d:\n"
        "movl $0x21c1fc, (%esp)\n" /* line 1320 */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "je .Lf77e0c_00077e3a\n"
        ".Lf77e0c_00077e2d:\n"
        "movl $1, %eax\n"
        ".Lf77e0c_00077e32:\n"
        "movb %al, shouldQuitOnError\n"
        "leave\n" /* line 1325 */
        "retl\n"
        ".Lf77e0c_00077e3a:\n"
        "movl $0x219aa8, (%esp)\n" /* line 1320 */
        "calll Dvar_GetInt\n"
        "cmpl $2, %eax\n"
        "je .Lf77e0c_00077e2d\n"
        "xorl %eax, %eax\n"
        "jmp .Lf77e0c_00077e32\n"
    );
}

/* line 1328 */
__attribute__((naked))
Bool QuitOnError(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1328 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll Dvar_IsSystemActive\n" /* line 1314 */
        "testb %al, %al\n"
        "jne .Lf77e50_00077e68\n"
        "movzbl shouldQuitOnError, %eax\n" /* line 1320 */
        "leave\n" /* line 1332 */
        "retl\n"
        ".Lf77e50_00077e68:\n"
        "movl $0x21c1fc, (%esp)\n" /* line 1320 */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "je .Lf77e50_00077e8c\n"
        ".Lf77e50_00077e78:\n"
        "movl $1, %eax\n"
        ".Lf77e50_00077e7d:\n"
        "movb %al, shouldQuitOnError\n"
        "movzbl shouldQuitOnError, %eax\n"
        "leave\n" /* line 1332 */
        "retl\n"
        ".Lf77e50_00077e8c:\n"
        "movl $0x219aa8, (%esp)\n" /* line 1320 */
        "calll Dvar_GetInt\n"
        "cmpl $2, %eax\n"
        "je .Lf77e50_00077e78\n"
        "xorl %eax, %eax\n"
        "jmp .Lf77e50_00077e7d\n"
    );
}

