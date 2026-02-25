/* ASM dump from: cg_animtree_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_animtree_mp.cpp */

#include "common_types.h"
#include "imports.h"

void CGScr_LoadAnimTrees(void);
void CG_SetDObjInfo(int iEntNum, int iEntType, struct XModel *pXModel);
qboolean CG_CheckDObjInfoMatches(int iEntNum, int iEntType, struct XModel *pXModel);
void CG_SafeDObjFree(int iEntNum);
void CG_FreeClientDObjInfo(void);
void CG_FreeEntityDObjInfo(void);

/* line 19 */
__attribute__((naked))
void CGScr_LoadAnimTrees(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 19 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, (%esp)\n" /* line 21 */
        "calll Scr_BeginLoadAnimTrees\n"
        "leave\n" /* line 22 */
        "retl\n"
    );
}

/* line 49 */
__attribute__((naked))
void CG_SetDObjInfo(int iEntNum, int iEntType, struct XModel *pXModel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 49 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* iEntNum */
        "movl 0x195f584, %eax\n" /* line 51 */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* iEntType */
        "movl %eax, 0x285f8(%edx, %ecx, 4)\n"
        "movl 0x10(%ebp), %eax\n" /* line 52 | pXModel */
        "movl %eax, 0x295f8(%edx, %ecx, 4)\n"
        "popl %ebp\n" /* line 53 */
        "retl\n"
    );
}

/* line 64 */
__attribute__((naked))
qboolean CG_CheckDObjInfoMatches(int iEntNum, int iEntType, struct XModel *pXModel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 64 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* iEntNum */
        "movl 0x195f584, %eax\n" /* line 66 */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* iEntType */
        "cmpl %eax, 0x285f8(%edx, %ecx, 4)\n"
        "je .Lf1e1ab4_001e1ad1\n"
        ".Lf1e1ab4_001e1acd:\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n" /* line 70 */
        "retl\n"
        ".Lf1e1ab4_001e1ad1:\n"
        "movl 0x10(%ebp), %eax\n" /* line 66 | pXModel */
        "cmpl %eax, 0x295f8(%edx, %ecx, 4)\n"
        "jne .Lf1e1ab4_001e1acd\n"
        "movl $1, %eax\n"
        "popl %ebp\n" /* line 70 */
        "retl\n"
    );
}

/* line 81 */
__attribute__((naked))
void CG_SafeDObjFree(int iEntNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 81 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* iEntNum */
        "movl %ebx, (%esp)\n" /* line 83 | iEntNum */
        "calll Com_SafeClientDObjFree\n"
        "movl 0x195f584, %eax\n" /* line 51 */
        "movl (%eax), %eax\n"
        "movl $0, 0x285f8(%eax, %ebx, 4)\n"
        "movl $0, 0x295f8(%eax, %ebx, 4)\n" /* line 52 */
        "movl %ebx, %eax\n" /* line 86 | iEntNum */
        "shll $4, %eax\n"
        "addl %ebx, %eax\n" /* iEntNum */
        "leal (%ebx, %eax, 8), %eax\n" /* iEntNum */
        "leal (, %eax, 4), %esi\n"
        "movl 0x195f5cc, %eax\n"
        "movl (%eax), %ebx\n" /* iEntNum */
        "movl 0x21c(%esi, %ebx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1e1ae4_001e1b53\n"
        "movl 0x195f954, %eax\n" /* line 88 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll XAnimFreeTree\n"
        "movl $0, 0x21c(%esi, %ebx)\n" /* line 89 */
        ".Lf1e1ae4_001e1b53:\n"
        "addl $0x10, %esp\n" /* line 91 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 32 */
__attribute__((naked))
void CG_FreeClientDObjInfo(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 32 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "xorl %esi, %esi\n"
        "xorl %edi, %edi\n"
        /* { scope 1 */
        ".Lf1e1b5a_001e1b67:\n"
        "movl %esi, (%esp)\n" /* line 83 | i */
        "calll Com_SafeClientDObjFree\n"
        "movl 0x195f584, %edx\n" /* line 51 */
        "movl (%edx), %eax\n"
        "movl $0, 0x285f8(%eax, %esi, 4)\n"
        "movl $0, 0x295f8(%eax, %esi, 4)\n" /* line 52 */
        "movl 0x195f5cc, %eax\n" /* line 86 */
        "movl (%eax), %ebx\n"
        "movl 0x21c(%ebx, %edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1b5a_001e1bbc\n"
        "movl 0x195f954, %edx\n" /* line 88 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimFreeTree\n"
        "movl $0, 0x21c(%edi, %ebx)\n" /* line 89 */
        ".Lf1e1b5a_001e1bbc:\n"
        "addl $1, %esi\n" /* line 36 | i */
        "addl $0x224, %edi\n"
        "cmpl $0x40, %esi\n" /* i */
        "jne .Lf1e1b5a_001e1b67\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 38 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 101 */
__attribute__((naked))
void CG_FreeEntityDObjInfo(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 101 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl $0x40, %esi\n"
        "movl $0x8900, %edi\n"
        /* { scope 1 */
        ".Lf1e1bd2_001e1be5:\n"
        "movl %esi, (%esp)\n" /* line 83 */
        "calll Com_SafeClientDObjFree\n"
        "movl 0x195f584, %edx\n" /* line 51 */
        "movl (%edx), %eax\n"
        "movl $0, 0x285f8(%eax, %esi, 4)\n"
        "movl $0, 0x295f8(%eax, %esi, 4)\n" /* line 52 */
        "movl 0x195f5cc, %eax\n" /* line 86 */
        "movl (%eax), %ebx\n"
        "movl 0x21c(%ebx, %edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1bd2_001e1c3a\n"
        "movl 0x195f954, %edx\n" /* line 88 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimFreeTree\n"
        "movl $0, 0x21c(%edi, %ebx)\n" /* line 89 */
        ".Lf1e1bd2_001e1c3a:\n"
        "addl $1, %esi\n" /* line 105 | i */
        "addl $0x224, %edi\n"
        "cmpl $0x400, %esi\n" /* i */
        "jne .Lf1e1bd2_001e1be5\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 107 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

