/* ASM dump from: r_caps.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_caps.cpp */

#include "common_types.h"
#include "imports.h"

static const DxCapsCheckBits s_capsCheckBits[36]; /* 0x3304a0 */
static const DxCapsCheckInteger s_capsCheckInt[8]; /* 0x330400 */

int R_CheckDxCaps(const D3DCAPS9 *caps);

/* line 193 */
__attribute__((naked))
int R_CheckDxCaps(const D3DCAPS9 *caps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 193 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1: msg, msg */
        "leal -0x20(%ebp), %eax\n" /* line 204 | textureMemory */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* videoMemory */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetVideoMemoryInfo\n"
        "xorl %eax, %eax\n" /* line 205 */
        "cmpl $0x4000001, -0x1c(%ebp)\n" /* videoMemory */
        "setge %al\n"
        "leal 4(%eax, %eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* allowedPaths */
        "movl $s_capsCheckBits, %esi\n"
        "jmp .Lff63cc_000f6461\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lff63cc_000f6401:\n"
        "cmpl $3, %ebx\n" /* line 165 */
        "je .Lff63cc_000f6495\n"
        "xorl %edi, %edi\n" /* printLevel */
        "movl -0x30(%ebp), %edx\n" /* line 170 | msg */
        "movl %edx, 8(%esp)\n"
        "movl $0x22637c, 4(%esp)\n" /* "Video card or driver %s.
" */
        "movl %edi, (%esp)\n" /* printLevel */
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "cmpl $3, %ebx\n" /* line 171 */
        "je .Lff63cc_000f64bc\n"
        ".Lff63cc_000f642e:\n"
        "cmpl $4, %ebx\n"
        "je .Lff63cc_000f65ab\n"
        "testl %ebx, %ebx\n"
        "jne .Lff63cc_000f6456\n"
        "movl -0x30(%ebp), %edx\n" /* line 174 | msg */
        "movl %edx, 8(%esp)\n"
        "movl $0x22637c, 4(%esp)\n" /* "Video card or driver %s.
" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        ".Lff63cc_000f6456:\n"
        "addl $0x14, %esi\n" /* line 184 */
        /* } scope */
        /* } scope */
        "cmpl $0x330770, %esi\n" /* line 213 */
        "je .Lff63cc_000f64dd\n"
        ".Lff63cc_000f6461:\n"
        "movl (%esi), %eax\n" /* line 215 */
        "movl 8(%ebp), %edx\n" /* caps */
        "movl (%eax, %edx), %ecx\n"
        "movl 8(%esi), %edx\n" /* line 216 */
        "testl %edx, %edx\n"
        "je .Lff63cc_000f6478\n"
        "movl %ecx, %eax\n"
        "notl %eax\n"
        "testl %eax, %edx\n"
        "je .Lff63cc_000f6456\n"
        ".Lff63cc_000f6478:\n"
        "movl 4(%esi), %eax\n" /* line 218 */
        "testl %eax, %eax\n"
        "je .Lff63cc_000f6483\n"
        "testl %eax, %ecx\n"
        "je .Lff63cc_000f6456\n"
        ".Lff63cc_000f6483:\n"
        "movl 0x10(%esi), %eax\n" /* line 221 */
        "movl %eax, -0x30(%ebp)\n" /* msg */
        "movl 0xc(%esi), %ebx\n" /* response */
        /* { scope 2 */
        /* { scope 3 */
        "cmpl $1, %ebx\n" /* line 165 */
        "jne .Lff63cc_000f6401\n"
        ".Lff63cc_000f6495:\n"
        "movl $2, %edi\n" /* printLevel */
        "movl -0x30(%ebp), %edx\n" /* line 170 | msg */
        "movl %edx, 8(%esp)\n"
        "movl $0x22637c, 4(%esp)\n" /* "Video card or driver %s.
" */
        "movl %edi, (%esp)\n" /* printLevel */
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "cmpl $3, %ebx\n" /* line 171 */
        "jne .Lff63cc_000f642e\n"
        ".Lff63cc_000f64bc:\n"
        "andl $0xfffffffb, -0x34(%ebp)\n" /* line 178 | allowedPaths */
        "movl $0x226398, 4(%esp)\n" /* line 179 */
        "movl %edi, (%esp)\n" /* printLevel */
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "addl $0x14, %esi\n" /* line 184 */
        /* } scope */
        /* } scope */
        "cmpl $0x330770, %esi\n" /* line 213 */
        "jne .Lff63cc_000f6461\n"
        ".Lff63cc_000f64dd:\n"
        "movl $s_capsCheckInt, %esi\n"
        "jmp .Lff63cc_000f653c\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lff63cc_000f64e4:\n"
        "cmpl $3, %ebx\n" /* line 165 */
        "je .Lff63cc_000f655c\n"
        "xorl %edi, %edi\n" /* printLevel */
        "movl -0x2c(%ebp), %edx\n" /* line 170 | msg */
        "movl %edx, 8(%esp)\n"
        "movl $0x22637c, 4(%esp)\n" /* "Video card or driver %s.
" */
        "movl %edi, (%esp)\n" /* printLevel */
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "cmpl $3, %ebx\n" /* line 171 */
        "je .Lff63cc_000f657f\n"
        ".Lff63cc_000f6509:\n"
        "cmpl $4, %ebx\n"
        "je .Lff63cc_000f65c7\n"
        "testl %ebx, %ebx\n"
        "jne .Lff63cc_000f6531\n"
        "movl -0x2c(%ebp), %edx\n" /* line 174 | msg */
        "movl %edx, 8(%esp)\n"
        "movl $0x22637c, 4(%esp)\n" /* "Video card or driver %s.
" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        ".Lff63cc_000f6531:\n"
        "addl $0x14, %esi\n" /* line 184 */
        /* } scope */
        /* } scope */
        "cmpl $s_capsCheckBits, %esi\n" /* line 224 */
        "je .Lff63cc_000f65a0\n"
        ".Lff63cc_000f653c:\n"
        "movl (%esi), %eax\n" /* line 226 */
        "movl 8(%ebp), %edx\n" /* caps */
        "movl (%eax, %edx), %eax\n"
        "cmpl 4(%esi), %eax\n" /* line 227 */
        "jb .Lff63cc_000f654e\n"
        "cmpl 8(%esi), %eax\n"
        "jbe .Lff63cc_000f6531\n"
        ".Lff63cc_000f654e:\n"
        "movl 0x10(%esi), %eax\n" /* line 230 */
        "movl %eax, -0x2c(%ebp)\n" /* msg */
        "movl 0xc(%esi), %ebx\n" /* response */
        /* { scope 2 */
        /* { scope 3 */
        "cmpl $1, %ebx\n" /* line 165 */
        "jne .Lff63cc_000f64e4\n"
        ".Lff63cc_000f655c:\n"
        "movl $2, %edi\n" /* printLevel */
        "movl -0x2c(%ebp), %edx\n" /* line 170 | msg */
        "movl %edx, 8(%esp)\n"
        "movl $0x22637c, 4(%esp)\n" /* "Video card or driver %s.
" */
        "movl %edi, (%esp)\n" /* printLevel */
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "cmpl $3, %ebx\n" /* line 171 */
        "jne .Lff63cc_000f6509\n"
        ".Lff63cc_000f657f:\n"
        "andl $0xfffffffb, -0x34(%ebp)\n" /* line 178 | allowedPaths */
        "movl $0x226398, 4(%esp)\n" /* line 179 */
        "movl %edi, (%esp)\n" /* printLevel */
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "addl $0x14, %esi\n" /* line 184 */
        /* } scope */
        /* } scope */
        "cmpl $s_capsCheckBits, %esi\n" /* line 224 */
        "jne .Lff63cc_000f653c\n"
        /* } scope */
        ".Lff63cc_000f65a0:\n"
        "movl -0x34(%ebp), %eax\n" /* line 234 | allowedPaths */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: msg, msg */
        /* { scope 2 */
        /* { scope 3 */
        ".Lff63cc_000f65ab:\n"
        "andl $0xfffffffd, -0x34(%ebp)\n" /* line 183 | allowedPaths */
        "movl $0x2263cc, 4(%esp)\n" /* line 184 */
        "movl %edi, (%esp)\n" /* printLevel */
        "movl 0x195eee0, %edx\n"
        "calll *(%edx)\n"
        "jmp .Lff63cc_000f6456\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lff63cc_000f65c7:\n"
        "andl $0xfffffffd, -0x34(%ebp)\n" /* line 183 | allowedPaths */
        "movl $0x2263cc, 4(%esp)\n" /* line 184 */
        "movl %edi, (%esp)\n" /* printLevel */
        "movl 0x195eee0, %edx\n"
        "calll *(%edx)\n"
        "jmp .Lff63cc_000f6531\n"
    );
}

