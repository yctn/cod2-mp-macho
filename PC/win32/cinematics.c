/* ASM dump from: cinematics.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/cinematics.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

static Boolean sAspyrIntroPlayed; /* 0x7eefe0 */
static long int ROQ_YY_tab[256]; /* 0x745be0 */
static long int ROQ_UB_tab[256]; /* 0x746be0 */
static long int ROQ_UG_tab[256]; /* 0x7463e0 */
static long int ROQ_VG_tab[256]; /* 0x745fe0 */
static long int ROQ_VR_tab[256]; /* 0x7467e0 */
static short unsigned int vq2[16384]; /* 0x746fe0 */
static short unsigned int vq4[65536]; /* 0x74efe0 */
static short unsigned int vq8[262144]; /* 0x76efe0 */
static struct cinematics_t cin; /* 0x4f55c0 */
static cin_cache cinTable[16]; /* 0x4f3900 */
static int currentHandle; /* 0x30f584 */
static int CL_handle; /* 0x30f580 */

static inflate_blocks_statef recurseQuad(long int startX, long int startY, long int xOff, long int yOff);
static inflate_blocks_statef RoQShutdown(void);
e_status ROQ_StopCinematicFromHandle(int handle);
inflate_blocks_statef ROQ_SetExtentsFromHandle(int handle, int x, int y, int w, int h);
inflate_blocks_statef ROQ_UploadCinematicFromHandle(int handle);
static inflate_blocks_statef blitVQQuad32fs(byte * *status, unsigned char *data);
int ROQ_PlayCinematic(const char *arg, int x, int y, int w, int h, int systemBits);
inflate_blocks_statef ROQ_DrawCinematicFromHandle(int handle);
inflate_blocks_statef ROQ_DrawCinematic(void);
static inflate_blocks_statef RoQReset(void);
inflate_blocks_statef ROQ_CloseAllVideos(void);
inflate_blocks_statef ROQ_StopCinematic(void);
e_status ROQ_RunCinematicFromHandle(int handle);
inflate_blocks_statef ROQ_RunCinematic(void);
inflate_blocks_statef ROQ_PlayCinematic_f(void);

/* line 1171 */
static __attribute__((naked))
inflate_blocks_statef recurseQuad(long int startX, long int startY, long int xOff, long int yOff)
{
    __asm__ __volatile__ (
        ".Lfb1ace_000b1ace:\n"
        "pushl %ebp\n" /* line 1171 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl %ecx, %edi\n" /* quadSize */
        "jmp .Lfb1ace_000b1b3b\n"
        /* { scope 1 */
        ".Lfb1ace_000b1ae1:\n"
        "sarl $1, %edi\n" /* line 1199 | quadSize */
        "movl 0xc(%ebp), %eax\n" /* line 1200 | yOff */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* xOff */
        "movl %edx, (%esp)\n"
        "movl %edi, %ecx\n" /* quadSize */
        "movl -0x24(%ebp), %edx\n"
        "movl -0x20(%ebp), %eax\n"
        "calll recurseQuad\n"
        "movl -0x20(%ebp), %ebx\n" /* line 1201 */
        "addl %edi, %ebx\n" /* quadSize */
        "movl 0xc(%ebp), %eax\n" /* yOff */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* xOff */
        "movl %edx, (%esp)\n"
        "movl %edi, %ecx\n" /* quadSize */
        "movl -0x24(%ebp), %edx\n"
        "movl %ebx, %eax\n"
        "calll recurseQuad\n"
        "addl %edi, -0x24(%ebp)\n" /* line 1202 | quadSize */
        "movl 0xc(%ebp), %eax\n" /* yOff */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* xOff */
        "movl %edx, (%esp)\n"
        "movl %edi, %ecx\n" /* quadSize */
        "movl -0x24(%ebp), %edx\n"
        "movl -0x20(%ebp), %eax\n"
        "calll recurseQuad\n"
        "movl %ebx, -0x20(%ebp)\n"
        ".Lfb1ace_000b1b3b:\n"
        "movl currentHandle, %ecx\n" /* line 1177 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %ecx\n"
        "movl 0x4f3a6c(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* offset */
        "movl 0x4f3a88(%ecx), %edx\n" /* line 1180 */
        "movl 0x4f3a8c(%ecx), %esi\n" /* line 1181 | bigy */
        "movl 0x4f3a00(%ecx), %eax\n" /* line 1183 */
        "cmpl %eax, %edx\n"
        "cmovgl %eax, %edx\n"
        "movl 0x4f3a04(%ecx), %ebx\n" /* line 1185 */
        "cmpl %ebx, %esi\n" /* bigy */
        "cmovgl %ebx, %esi\n" /* bigy */
        "movl -0x20(%ebp), %eax\n" /* line 1188 */
        "testl %eax, %eax\n"
        "js .Lfb1ace_000b1be5\n"
        "movl -0x20(%ebp), %eax\n"
        "addl %edi, %eax\n" /* quadSize */
        "cmpl %eax, %edx\n"
        "jl .Lfb1ace_000b1be5\n"
        "movl -0x24(%ebp), %edx\n"
        "leal (%edi, %edx), %eax\n" /* quadSize */
        "cmpl %eax, %esi\n" /* bigy */
        "jl .Lfb1ace_000b1be5\n"
        "testl %edx, %edx\n"
        "js .Lfb1ace_000b1be5\n"
        "cmpl $8, %edi\n" /* quadSize */
        "jg .Lfb1ace_000b1be5\n"
        "subl %esi, %ebx\n" /* line 1191 | bigy */
        "sarl $1, %ebx\n"
        "movl %edx, %eax\n"
        "addl %ebx, %eax\n"
        "addl 0xc(%ebp), %eax\n" /* yOff */
        "imull 0x4f3a64(%ecx), %eax\n"
        "movl -0x20(%ebp), %edx\n"
        "addl 8(%ebp), %edx\n" /* xOff */
        "imull 0x4f3a80(%ecx), %edx\n"
        "leal cin(%eax, %edx), %eax\n"
        "movl 0x4f3a5c(%ecx), %edx\n" /* line 1193 */
        "movl %eax, 0x705bc0(, %edx, 4)\n"
        "addl -0x1c(%ebp), %eax\n" /* line 1194 | offset */
        "movl %eax, 0x725bc0(, %edx, 4)\n"
        "addl $1, %edx\n"
        "movl %edx, 0x4f3a5c(%ecx)\n"
        ".Lfb1ace_000b1be5:\n"
        "cmpl $4, %edi\n" /* line 1197 | quadSize */
        "jne .Lfb1ace_000b1ae1\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1205 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1561 */
static __attribute__((naked))
inflate_blocks_statef RoQShutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1561 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl currentHandle, %eax\n" /* line 1563 */
        "leal (%eax, %eax, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "leal (%edx, %eax), %eax\n"
        "movl 0x4f3ac4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfb1bf6_000b1c2b\n"
        "movl $0x4f3a30, %ebx\n" /* line 1568 */
        "movl 0x4f3a3c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfb1bf6_000b1c31\n"
        ".Lfb1bf6_000b1c2b:\n"
        "addl $0x14, %esp\n" /* line 1637 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfb1bf6_000b1c31:\n"
        "movl $0x21e9b0, (%esp)\n" /* line 1572 */
        "calll Com_DPrintf\n"
        "movl currentHandle, %ecx\n" /* line 1573 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl $0, 0xc(%eax, %ebx)\n"
        "movl 0x4f3a34(%eax), %eax\n" /* line 1575 */
        "testl %eax, %eax\n"
        "jne .Lfb1bf6_000b1dd4\n"
        ".Lfb1bf6_000b1c68:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1580 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a38(%eax, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfb1bf6_000b1d88\n"
        ".Lfb1bf6_000b1c84:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1587 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %ecx\n"
        "movl 0x4f3a24(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfb1bf6_000b1d28\n"
        "movl 0x195ee8c, %eax\n" /* line 1589 */
        "movl (%eax), %edx\n"
        "movl 0x4f3ac8(%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl $0xffffffff, CL_handle\n" /* line 1591 */
        "movl (%edx), %eax\n" /* line 1596 */
        "testl %eax, %eax\n"
        "jne .Lfb1bf6_000b1d7a\n"
        "movl 0x195ee88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n"
        "cmpb $0, (%ebx)\n"
        "je .Lfb1bf6_000b1d7a\n"
        /* { scope 1 */
        "cmpb $0, sAspyrIntroPlayed\n" /* line 1604 */
        "je .Lfb1bf6_000b1de4\n"
        ".Lfb1bf6_000b1ce5:\n"
        "movl %ebx, 4(%esp)\n" /* line 1612 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 1613 */
        "movl 0x195ee88, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        ".Lfb1bf6_000b1d1c:\n"
        "movl $1, (%esp)\n" /* line 1619 */
        "calll UI_SetActiveMenu\n"
        /* } scope */
        ".Lfb1bf6_000b1d28:\n"
        "movl 0x195eca8, %eax\n" /* line 1632 */
        "movl 0x148(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfb1bf6_000b1d39\n"
        "calll *%eax\n" /* line 1633 */
        ".Lfb1bf6_000b1d39:\n"
        "movl currentHandle, %eax\n" /* line 1635 */
        "leal (%eax, %eax, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "leal cinTable(%edx, %eax), %edx\n"
        "movl $0x1cc, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl $0xffffffff, currentHandle\n" /* line 1636 */
        "addl $0x14, %esp\n" /* line 1637 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfb1bf6_000b1d7a:\n"
        "movl $0, (%esp)\n" /* line 1623 */
        "calll UI_SetActiveMenu\n"
        "jmp .Lfb1bf6_000b1d28\n"
        ".Lfb1bf6_000b1d88:\n"
        "movl %eax, (%esp)\n" /* line 1582 */
        "calll Sys_EndStreamedFile\n"
        "movl currentHandle, %ecx\n" /* line 1583 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a38(%eax, %ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl currentHandle, %ecx\n" /* line 1584 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl $0, 8(%eax, %ebx)\n"
        "jmp .Lfb1bf6_000b1c84\n"
        ".Lfb1bf6_000b1dd4:\n"
        "calll SND_EndRawSamples\n" /* line 1577 */
        "movl currentHandle, %ecx\n"
        "jmp .Lfb1bf6_000b1c68\n"
        /* { scope 1 */
        ".Lfb1bf6_000b1de4:\n"
        "movl $0x21e9c4, 4(%esp)\n" /* line 1604 */
        "movl %ebx, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lfb1bf6_000b1ce5\n"
        "movl $0x21e9cc, 4(%esp)\n" /* line 1606 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movb $1, sAspyrIntroPlayed\n" /* line 1608 */
        "jmp .Lfb1bf6_000b1d1c\n"
    );
}

/* line 1645 */
__attribute__((naked))
e_status ROQ_StopCinematicFromHandle(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1645 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* handle */
        "cmpl $0xf, %ecx\n" /* line 1648 */
        "ja .Lfb1e2c_000b1ec3\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "cmpl $2, 0x4f3a3c(%eax)\n"
        "je .Lfb1e2c_000b1ec3\n"
        "movl %ecx, currentHandle\n" /* line 1650 */
        "addl $cinTable, %eax\n" /* line 1652 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21e9e4, (%esp)\n" /* "trFMV::stop(), closing %s
" */
        "calll Com_DPrintf\n"
        "movl currentHandle, %ecx\n" /* line 1654 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %edx\n"
        "movl 0x4f3ac4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfb1e2c_000b1ec3\n"
        "movl 0x4f3a24(%edx), %eax\n" /* line 1659 */
        "testl %eax, %eax\n"
        "jne .Lfb1e2c_000b1eca\n"
        ".Lfb1e2c_000b1e9b:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1666 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl $0x4f3a30, %edx\n"
        "movl $2, 0xc(%eax, %edx)\n"
        "calll RoQShutdown\n" /* line 1667 */
        "movl $2, %eax\n"
        "leave\n" /* line 1670 */
        "retl\n"
        ".Lfb1e2c_000b1ec3:\n"
        "movl $2, %eax\n" /* line 1669 */
        "leave\n" /* line 1670 */
        "retl\n"
        ".Lfb1e2c_000b1eca:\n"
        "movl 0x195ee8c, %eax\n" /* line 1661 */
        "movl (%eax), %eax\n"
        "cmpl $1, (%eax)\n"
        "je .Lfb1e2c_000b1e9b\n"
        "movl 0x4f3a3c(%edx), %eax\n" /* line 1663 */
        "leave\n" /* line 1670 */
        "retl\n"
    );
}

/* line 1877 */
__attribute__((naked))
inflate_blocks_statef ROQ_SetExtentsFromHandle(int handle, int x, int y, int w, int h)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1877 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* handle */
        "cmpl $0xf, %ecx\n" /* line 1879 */
        "ja .Lfb1ede_000b1f31\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %edx\n"
        "cmpl $2, 0x4f3a3c(%edx)\n"
        "je .Lfb1ede_000b1f31\n"
        "movl $0x4f3a00, %eax\n" /* line 1881 */
        "movl 0xc(%ebp), %ecx\n" /* x */
        "movl %ecx, 8(%edx, %eax)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1882 | y */
        "movl %ecx, 0xc(%edx, %eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 1883 | w */
        "movl %eax, 0x4f3a10(%edx)\n"
        "movl 0x18(%ebp), %ecx\n" /* line 1884 | h */
        "movl %ecx, 0x4f3a14(%edx)\n"
        "movl $1, 0x4f3a20(%edx)\n" /* line 1885 */
        ".Lfb1ede_000b1f31:\n"
        "popl %ebp\n" /* line 1886 */
        "retl\n"
    );
}

/* line 2115 */
__attribute__((naked))
inflate_blocks_statef ROQ_UploadCinematicFromHandle(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2115 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* handle */
        "cmpl $0xf, %ecx\n" /* line 2117 */
        "ja .Lfb1f36_000b1f89\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 2119 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl 0x4f3ac4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfb1f36_000b1f89\n"
        "movl 0x4f3ac0(%eax), %edx\n" /* line 2123 */
        "testl %edx, %edx\n"
        "jle .Lfb1f36_000b1f97\n"
        ".Lfb1f36_000b1f64:\n"
        "movl 0x195ee84, %eax\n" /* line 2142 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfb1f36_000b1f89\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "cmpl $1, 0x4f3ac0(%eax)\n"
        "je .Lfb1f36_000b1f8b\n"
        ".Lfb1f36_000b1f89:\n"
        "popl %ebp\n" /* line 2145 */
        "retl\n"
        ".Lfb1f36_000b1f8b:\n"
        "movl $0, 0x4f3ac0(%eax)\n" /* line 2143 */
        "popl %ebp\n" /* line 2145 */
        "retl\n"
        ".Lfb1f36_000b1f97:\n"
        "cmpl $0, 0x4f3a20(%eax)\n" /* line 2123 */
        "je .Lfb1f36_000b1f64\n"
        "testl %edx, %edx\n" /* line 2125 */
        "je .Lfb1f36_000b1fb5\n"
        "addl $1, %edx\n" /* line 2131 */
        "je .Lfb1f36_000b1fc1\n"
        "movl $0, 0x4f3a20(%eax)\n" /* line 2137 */
        "jmp .Lfb1f36_000b1f64\n"
        ".Lfb1f36_000b1fb5:\n"
        "movl $0xffffffff, 0x4f3ac0(%eax)\n" /* line 2127 */
        "jmp .Lfb1f36_000b1f64\n"
        ".Lfb1f36_000b1fc1:\n"
        "movl $0xfffffffe, 0x4f3ac0(%eax)\n" /* line 2133 */
        "jmp .Lfb1f36_000b1f64\n"
    );
}

/* line 587 */
static __attribute__((naked))
inflate_blocks_statef blitVQQuad32fs(byte * *status, unsigned char *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 587 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl currentHandle, %ecx\n" /* line 597 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a64(%eax, %ecx), %eax\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, %esi\n" /* line 379 */
        "andl $0xfffffff8, %esi\n"
        /* } scope */
        /* } scope */
        "addl %eax, %eax\n" /* line 651 */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x18(%ebp)\n" /* index */
        ".Lfb1fce_000b2002:\n"
        "movl 0xc(%ebp), %eax\n" /* line 604 | data */
        "movzbw (%eax), %dx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "leal (%edx, %eax), %edi\n" /* celdata */
        "addl $2, %ecx\n" /* line 605 */
        "movl %ecx, 0xc(%ebp)\n" /* data */
        "movw $7, -0x1a(%ebp)\n" /* newd */
        "jmp .Lfb1fce_000b2049\n"
        ".Lfb1fce_000b2023:\n"
        "testw %ax, %ax\n" /* line 615 */
        "jne .Lfb1fce_000b202c\n"
        "addl $5, -0x18(%ebp)\n" /* line 670 | index */
        ".Lfb1fce_000b202c:\n"
        "movl -0x18(%ebp), %ecx\n" /* line 599 | index */
        "movl 8(%ebp), %eax\n" /* status */
        "movl (%eax, %ecx, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfb1fce_000b234c\n"
        ".Lfb1fce_000b203d:\n"
        "cmpw $0, -0x1a(%ebp)\n" /* line 601 | newd */
        "je .Lfb1fce_000b2002\n"
        "subw $1, -0x1a(%ebp)\n" /* line 609 | newd */
        ".Lfb1fce_000b2049:\n"
        "movl %edi, %eax\n" /* line 612 | celdata */
        "andw $0xc000, %ax\n"
        "shll $2, %edi\n" /* line 613 | celdata */
        "cmpw $0x4000, %ax\n" /* line 615 */
        "je .Lfb1fce_000b2183\n"
        "jbe .Lfb1fce_000b2023\n"
        "cmpw $0x8000, %ax\n"
        "je .Lfb1fce_000b2354\n"
        "cmpw $0xc000, %ax\n"
        "jne .Lfb1fce_000b202c\n"
        "addl $1, -0x18(%ebp)\n" /* line 623 | index */
        "movl -0x18(%ebp), %ecx\n" /* index */
        "movl 8(%ebp), %eax\n" /* status */
        "leal (%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl $4, -0x14(%ebp)\n"
        "cmpw $0, -0x1a(%ebp)\n" /* line 626 | newd */
        "jne .Lfb1fce_000b20e7\n"
        ".Lfb1fce_000b208c:\n"
        "movl 0xc(%ebp), %eax\n" /* line 629 | data */
        "movzbw (%eax), %dx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "leal (%edx, %eax), %edi\n" /* celdata */
        "addl $2, %ecx\n" /* line 630 */
        "movl %ecx, 0xc(%ebp)\n" /* data */
        "movw $7, -0x1a(%ebp)\n" /* newd */
        "movl %edi, %eax\n" /* line 637 | celdata */
        "andw $0xc000, %ax\n"
        "shll $2, %edi\n" /* line 638 | celdata */
        "cmpw $0x8000, %ax\n" /* line 640 */
        "je .Lfb1fce_000b20fb\n"
        ".Lfb1fce_000b20ba:\n"
        "cmpw $0xc000, %ax\n"
        "je .Lfb1fce_000b2574\n"
        "cmpw $0x4000, %ax\n"
        "je .Lfb1fce_000b2652\n"
        ".Lfb1fce_000b20ce:\n"
        "addl $1, -0x18(%ebp)\n" /* line 661 | index */
        "addl $4, -0x10(%ebp)\n"
        "subl $1, -0x14(%ebp)\n" /* line 624 */
        "je .Lfb1fce_000b202c\n"
        "cmpw $0, -0x1a(%ebp)\n" /* line 626 | newd */
        "je .Lfb1fce_000b208c\n"
        ".Lfb1fce_000b20e7:\n"
        "subw $1, -0x1a(%ebp)\n" /* line 634 | newd */
        "movl %edi, %eax\n" /* line 637 | celdata */
        "andw $0xc000, %ax\n"
        "shll $2, %edi\n" /* line 638 | celdata */
        "cmpw $0x8000, %ax\n" /* line 640 */
        "jne .Lfb1fce_000b20ba\n"
        /* { scope 2 */
        ".Lfb1fce_000b20fb:\n"
        "movl 0xc(%ebp), %edx\n" /* line 536 | data */
        "movzbl (%edx), %eax\n"
        "shll $6, %eax\n"
        "leal vq4(%eax), %ebx\n" /* dsrc */
        "movl -0x10(%ebp), %edx\n" /* line 537 */
        "movl (%edx), %ecx\n"
        "movl 0x74efe4(%eax), %edx\n" /* line 540 */
        "movl vq4(%eax), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 541 | dsrc */
        "movl 0xc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 543 */
        "movl 0x10(%ebx), %eax\n" /* line 544 | dsrc */
        "movl 0x14(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0x18(%ebx), %eax\n" /* line 545 | dsrc */
        "movl 0x1c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 547 */
        "movl 0x20(%ebx), %eax\n" /* line 548 | dsrc */
        "movl 0x24(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0x28(%ebx), %eax\n" /* line 549 | dsrc */
        "movl 0x2c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 551 */
        "movl 0x30(%ebx), %eax\n" /* line 552 | dsrc */
        "movl 0x34(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0x38(%ebx), %eax\n" /* line 553 | dsrc */
        "movl 0x3c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        /* } scope */
        "addl $1, 0xc(%ebp)\n" /* line 644 | data */
        "jmp .Lfb1fce_000b20ce\n"
        ".Lfb1fce_000b2183:\n"
        "movl -0x18(%ebp), %ecx\n" /* line 665 | index */
        "movl 8(%ebp), %eax\n" /* status */
        "movl (%eax, %ecx, 4), %ebx\n" /* dst */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%ebp), %edx\n" /* line 371 | data */
        "movzbl (%edx), %eax\n"
        "movl %ebx, %ecx\n"
        "addl 0x7057c0(, %eax, 4), %ecx\n"
        "movl (%ecx), %eax\n" /* line 375 */
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 376 */
        "movl 0xc(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 377 */
        "movl 0x14(%ecx), %edx\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 0x18(%ecx), %eax\n" /* line 378 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl %edx, 0x1c(%ebx)\n"
        "addl %esi, %ecx\n" /* line 379 */
        "addl %esi, %ebx\n" /* line 380 */
        "movl (%ecx), %eax\n" /* line 381 */
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 382 */
        "movl 0xc(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 383 */
        "movl 0x14(%ecx), %edx\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 0x18(%ecx), %eax\n" /* line 384 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl %edx, 0x1c(%ebx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 385 */
        "leal (%esi, %ebx), %ebx\n" /* line 386 */
        "movl (%ecx), %eax\n" /* line 387 */
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 388 */
        "movl 0xc(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 389 */
        "movl 0x14(%ecx), %edx\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 0x18(%ecx), %eax\n" /* line 390 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl %edx, 0x1c(%ebx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 391 */
        "leal (%esi, %ebx), %ebx\n" /* line 392 */
        "movl (%ecx), %eax\n" /* line 393 */
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 394 */
        "movl 0xc(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 395 */
        "movl 0x14(%ecx), %edx\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 0x18(%ecx), %eax\n" /* line 396 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl %edx, 0x1c(%ebx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 397 */
        "leal (%esi, %ebx), %ebx\n" /* line 398 */
        "movl (%ecx), %eax\n" /* line 399 */
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 400 */
        "movl 0xc(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 401 */
        "movl 0x14(%ecx), %edx\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 0x18(%ecx), %eax\n" /* line 402 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl %edx, 0x1c(%ebx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 403 */
        "leal (%esi, %ebx), %ebx\n" /* line 404 */
        "movl (%ecx), %eax\n" /* line 405 */
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 406 */
        "movl 0xc(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 407 */
        "movl 0x14(%ecx), %edx\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 0x18(%ecx), %eax\n" /* line 408 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl %edx, 0x1c(%ebx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 409 */
        "leal (%esi, %ebx), %ebx\n" /* line 410 */
        "movl (%ecx), %eax\n" /* line 411 */
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 412 */
        "movl 0xc(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 413 */
        "movl 0x14(%ecx), %edx\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 0x18(%ecx), %eax\n" /* line 414 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl %edx, 0x1c(%ebx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 415 */
        "leal (%esi, %ebx), %ebx\n" /* line 416 */
        "movl (%ecx), %eax\n" /* line 417 */
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 418 */
        "movl 0xc(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 419 */
        "movl 0x14(%ecx), %edx\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 0x18(%ecx), %eax\n" /* line 420 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl %edx, 0x1c(%ebx)\n"
        /* } scope */
        /* } scope */
        "addl $1, 0xc(%ebp)\n" /* line 666 | data */
        "addl $5, -0x18(%ebp)\n" /* line 667 | index */
        "movl -0x18(%ebp), %ecx\n" /* line 599 | index */
        "movl 8(%ebp), %eax\n" /* status */
        "movl (%eax, %ecx, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfb1fce_000b203d\n"
        /* } scope */
        ".Lfb1fce_000b234c:\n"
        "addl $0x18, %esp\n" /* line 674 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfb1fce_000b2354:\n"
        "movl 0xc(%ebp), %eax\n" /* line 471 | data */
        "movzbl (%eax), %eax\n"
        "shll $8, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, %ebx\n" /* dsrc */
        "addl $vq8, %ebx\n" /* dsrc */
        "movl -0x18(%ebp), %edx\n" /* line 472 | index */
        "movl 8(%ebp), %eax\n" /* status */
        "movl (%eax, %edx, 4), %ecx\n"
        "movl -0x24(%ebp), %edx\n" /* line 475 */
        "movl vq8(%edx), %eax\n"
        "movl 0x76efe4(%edx), %edx\n"
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 476 | dsrc */
        "movl 0xc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0x10(%ebx), %eax\n" /* line 477 | dsrc */
        "movl 0x14(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x10(%ecx)\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0x18(%ebx), %eax\n" /* line 478 | dsrc */
        "movl 0x1c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 480 */
        "movl 0x20(%ebx), %eax\n" /* line 481 | dsrc */
        "movl 0x24(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0x28(%ebx), %eax\n" /* line 482 | dsrc */
        "movl 0x2c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0x30(%ebx), %eax\n" /* line 483 | dsrc */
        "movl 0x34(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x10(%ecx)\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0x38(%ebx), %eax\n" /* line 484 | dsrc */
        "movl 0x3c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 486 */
        "movl 0x40(%ebx), %eax\n" /* line 487 | dsrc */
        "movl 0x44(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0x48(%ebx), %eax\n" /* line 488 | dsrc */
        "movl 0x4c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0x50(%ebx), %eax\n" /* line 489 | dsrc */
        "movl 0x54(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x10(%ecx)\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0x58(%ebx), %eax\n" /* line 490 | dsrc */
        "movl 0x5c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 492 */
        "movl 0x60(%ebx), %eax\n" /* line 493 | dsrc */
        "movl 0x64(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0x68(%ebx), %eax\n" /* line 494 | dsrc */
        "movl 0x6c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0x70(%ebx), %eax\n" /* line 495 | dsrc */
        "movl 0x74(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x10(%ecx)\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0x78(%ebx), %eax\n" /* line 496 | dsrc */
        "movl 0x7c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 498 */
        "movl 0x80(%ebx), %eax\n" /* line 499 | dsrc */
        "movl 0x84(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0x88(%ebx), %eax\n" /* line 500 | dsrc */
        "movl 0x8c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0x90(%ebx), %eax\n" /* line 501 | dsrc */
        "movl 0x94(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x10(%ecx)\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0x98(%ebx), %eax\n" /* line 502 | dsrc */
        "movl 0x9c(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 504 */
        "movl 0xa0(%ebx), %eax\n" /* line 505 | dsrc */
        "movl 0xa4(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0xa8(%ebx), %eax\n" /* line 506 | dsrc */
        "movl 0xac(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0xb0(%ebx), %eax\n" /* line 507 | dsrc */
        "movl 0xb4(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x10(%ecx)\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0xb8(%ebx), %eax\n" /* line 508 | dsrc */
        "movl 0xbc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 510 */
        "movl 0xc0(%ebx), %eax\n" /* line 511 | dsrc */
        "movl 0xc4(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0xc8(%ebx), %eax\n" /* line 512 | dsrc */
        "movl 0xcc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0xd0(%ebx), %eax\n" /* line 513 | dsrc */
        "movl 0xd4(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x10(%ecx)\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0xd8(%ebx), %eax\n" /* line 514 | dsrc */
        "movl 0xdc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        "leal (%esi, %ecx), %ecx\n" /* line 516 */
        "movl 0xe0(%ebx), %eax\n" /* line 517 | dsrc */
        "movl 0xe4(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0xe8(%ebx), %eax\n" /* line 518 | dsrc */
        "movl 0xec(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0xf0(%ebx), %eax\n" /* line 519 | dsrc */
        "movl 0xf4(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x10(%ecx)\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0xf8(%ebx), %eax\n" /* line 520 | dsrc */
        "movl 0xfc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        /* } scope */
        "addl $1, 0xc(%ebp)\n" /* line 619 | data */
        "addl $5, -0x18(%ebp)\n" /* line 620 | index */
        "jmp .Lfb1fce_000b202c\n"
        /* { scope 2 */
        ".Lfb1fce_000b2574:\n"
        "movl 0xc(%ebp), %eax\n" /* line 570 | data */
        "movzbl (%eax), %ecx\n"
        "shll $4, %ecx\n"
        "movl -0x10(%ebp), %edx\n" /* line 571 */
        "movl (%edx), %ebx\n" /* ddst */
        "movl vq2(%ecx), %eax\n" /* line 574 */
        "movl 0x746fe4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n" /* ddst */
        "movl %edx, 4(%ebx)\n" /* ddst */
        "movl 0x746fe8(%ecx), %eax\n" /* line 575 */
        "movl 0x746fec(%ecx), %edx\n"
        "movl %eax, (%esi, %ebx)\n"
        "movl %edx, 4(%esi, %ebx)\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 570 | data */
        "movzbl 1(%eax), %ecx\n"
        "shll $4, %ecx\n"
        "movl -0x10(%ebp), %edx\n" /* line 571 */
        "movl (%edx), %ebx\n" /* ddst */
        "movl vq2(%ecx), %eax\n" /* line 574 */
        "movl 0x746fe4(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n" /* ddst */
        "movl %edx, 0xc(%ebx)\n" /* ddst */
        "movl 0x746fe8(%ecx), %eax\n" /* line 575 */
        "movl 0x746fec(%ecx), %edx\n"
        "movl %eax, 8(%ebx, %esi)\n" /* ddst */
        "movl %edx, 0xc(%ebx, %esi)\n" /* ddst */
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 570 | data */
        "movzbl 2(%eax), %ecx\n"
        "shll $4, %ecx\n"
        "movl -0x20(%ebp), %ebx\n" /* line 571 | ddst */
        "movl -0x10(%ebp), %edx\n"
        "addl (%edx), %ebx\n" /* ddst */
        "movl vq2(%ecx), %eax\n" /* line 574 */
        "movl 0x746fe4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n" /* ddst */
        "movl %edx, 4(%ebx)\n" /* ddst */
        "movl 0x746fe8(%ecx), %eax\n" /* line 575 */
        "movl 0x746fec(%ecx), %edx\n"
        "movl %eax, (%esi, %ebx)\n"
        "movl %edx, 4(%esi, %ebx)\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 570 | data */
        "movzbl 3(%eax), %ecx\n"
        "shll $4, %ecx\n"
        "movl -0x20(%ebp), %ebx\n" /* line 571 | ddst */
        "movl -0x10(%ebp), %edx\n"
        "addl (%edx), %ebx\n" /* ddst */
        "movl vq2(%ecx), %eax\n" /* line 574 */
        "movl 0x746fe4(%ecx), %edx\n"
        "movl %eax, 8(%ebx)\n" /* ddst */
        "movl %edx, 0xc(%ebx)\n" /* ddst */
        "movl 0x746fe8(%ecx), %eax\n" /* line 575 */
        "movl 0x746fec(%ecx), %edx\n"
        "movl %eax, 8(%ebx, %esi)\n" /* ddst */
        "movl %edx, 0xc(%ebx, %esi)\n" /* ddst */
        "addl $4, 0xc(%ebp)\n" /* line 654 | data */
        "jmp .Lfb1fce_000b20ce\n"
        ".Lfb1fce_000b2652:\n"
        "movl -0x10(%ebp), %eax\n" /* line 657 */
        "movl (%eax), %ecx\n" /* dst */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%ebp), %edx\n" /* line 437 | data */
        "movzbl (%edx), %eax\n"
        "movl %ecx, %ebx\n" /* dsrc */
        "addl 0x7057c0(, %eax, 4), %ebx\n" /* dsrc */
        "movl (%ebx), %eax\n" /* line 441 | dsrc */
        "movl 4(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 442 | dsrc */
        "movl 0xc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "leal (%esi, %ebx), %ebx\n" /* line 443 | dsrc */
        "leal (%esi, %ecx), %ecx\n" /* line 444 */
        "movl (%ebx), %eax\n" /* line 445 | dsrc */
        "movl 4(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 446 | dsrc */
        "movl 0xc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "leal (%esi, %ebx), %ebx\n" /* line 447 | dsrc */
        "leal (%esi, %ecx), %ecx\n" /* line 448 */
        "movl (%ebx), %eax\n" /* line 449 | dsrc */
        "movl 4(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 450 | dsrc */
        "movl 0xc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "leal (%esi, %ebx), %ebx\n" /* line 451 | dsrc */
        "leal (%esi, %ecx), %ecx\n" /* line 452 */
        "movl (%ebx), %eax\n" /* line 453 | dsrc */
        "movl 4(%ebx), %edx\n" /* dsrc */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 454 | dsrc */
        "movl 0xc(%ebx), %edx\n" /* dsrc */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        /* } scope */
        /* } scope */
        "addl $1, 0xc(%ebp)\n" /* line 658 | data */
        "jmp .Lfb1fce_000b20ce\n"
    );
}

/* line 1786 */
__attribute__((naked))
int ROQ_PlayCinematic(const char *arg, int x, int y, int w, int h, int systemBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1786 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x12c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1792 | arg */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x21ea00, 8(%esp)\n" /* "video/%s.roq" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x118(%ebp), %ecx\n" /* name */
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "movzbl 0x1c(%ebp), %eax\n" /* line 1793 | systemBits */
        "andb $1, %al\n"
        "movb %al, -0x119(%ebp)\n"
        "jne .Lfb26da_000b274c\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %esi, %esi\n"
        ".Lfb26da_000b271d:\n"
        "leal -0x118(%ebp), %ecx\n" /* line 1797 | name */
        "movl %ecx, 4(%esp)\n"
        "leal cinTable(%esi, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfb26da_000b2bf3\n"
        "addl $1, %ebx\n" /* line 1795 | i */
        "addl $0x1cb, %esi\n"
        "cmpl $0x10, %ebx\n" /* i */
        "jne .Lfb26da_000b271d\n"
        ".Lfb26da_000b274c:\n"
        "movl 8(%ebp), %eax\n" /* line 1804 | arg */
        "movl %eax, 4(%esp)\n"
        "movl $0x21ea10, (%esp)\n" /* "SCR_PlayCinematic( %s )
" */
        "calll Com_DPrintf\n"
        "movl $0x250614, 8(%esp)\n" /* line 1806 */
        "movl $0, 4(%esp)\n"
        "movl $cin, (%esp)\n"
        "calll Com_Memset\n"
        "xorl %edx, %edx\n"
        "movl $cinTable, %eax\n"
        ".Lfb26da_000b2782:\n"
        "cmpb $0, (%eax)\n" /* line 150 */
        "je .Lfb26da_000b27aa\n"
        "addl $1, %edx\n" /* line 148 */
        "addl $0x1cc, %eax\n"
        "cmpl $0x10, %edx\n"
        "jne .Lfb26da_000b2782\n"
        "movl $0x21ea2c, 4(%esp)\n" /* line 155 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %edx, %edx\n"
        ".Lfb26da_000b27aa:\n"
        "movl %edx, %edi\n" /* line 1807 */
        "movl %edx, currentHandle\n"
        "movl %edx, 0x745bd0\n" /* line 1809 */
        "leal -0x118(%ebp), %ecx\n" /* line 1811 | name */
        "movl %ecx, 4(%esp)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal cinTable(%eax, %edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl currentHandle, %edx\n" /* line 1813 */
        "movl $0x4f3a50, %esi\n"
        "leal (%edx, %edx, 2), %ebx\n" /* i */
        "leal (%ebx, %ebx, 8), %ebx\n" /* i */
        "movl %ebx, %eax\n" /* i */
        "shll $4, %eax\n"
        "addl %eax, %ebx\n" /* i */
        "addl %edx, %ebx\n" /* i */
        "movl $0, 4(%ebx, %esi)\n" /* i */
        "movl $1, 8(%esp)\n" /* line 1814 */
        "leal 0x4f3a38(%ebx), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "leal cinTable(%ebx), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileRead\n"
        "movl %eax, 4(%ebx, %esi)\n" /* i */
        "movl currentHandle, %edi\n" /* line 1816 */
        "leal (%edi, %edi, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %edi), %edx\n"
        "movl 0x4f3a54(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfb26da_000b2c64\n"
        "cmpl $0xf, %edi\n" /* line 1879 */
        "ja .Lfb26da_000b2c00\n"
        "movl $0x4f3a30, %esi\n"
        "cmpl $2, 0x4f3a3c(%edx)\n"
        "je .Lfb26da_000b2c2b\n"
        "movl $0x4f3a00, %eax\n" /* line 1881 */
        "movl 0xc(%ebp), %ecx\n" /* x */
        "movl %ecx, 8(%edx, %eax)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1882 | y */
        "movl %ecx, 0xc(%edx, %eax)\n"
        "movl $0x4f3a10, %ebx\n" /* line 1883 | i */
        "movl 0x14(%ebp), %eax\n" /* w */
        "movl %eax, 0x4f3a10(%edx)\n"
        "movl 0x18(%ebp), %ecx\n" /* line 1884 | h */
        "movl %ecx, 4(%edx, %ebx)\n"
        "movl $1, 0x4f3a20(%edx)\n" /* line 1885 */
        ".Lfb26da_000b2895:\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 1824 | systemBits, loop */
        "shrl $1, %ecx\n" /* loop */
        "andl $1, %ecx\n" /* loop */
        /* { scope 2 */
        "cmpl $0xf, %edi\n" /* line 1891 */
        "ja .Lfb26da_000b28be\n"
        "leal (%edi, %edi, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %edi, %eax\n"
        "cmpl $2, 0x4f3a3c(%eax)\n"
        "je .Lfb26da_000b28be\n"
        "movl %ecx, 8(%eax, %ebx)\n" /* line 1893 */
        /* } scope */
        ".Lfb26da_000b28be:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 1826 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %edi), %ecx\n"
        "movl 0x1c(%ebp), %eax\n" /* systemBits */
        "shrl $2, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 0xc(%ecx, %ebx)\n"
        "movl $0x4f3a20, %edx\n" /* line 1827 */
        "movzbl -0x119(%ebp), %eax\n"
        "movl %eax, 4(%ecx, %edx)\n"
        "movl $1, 0x4f3ac0(%ecx)\n" /* line 1828 */
        "movl 0x1c(%ebp), %eax\n" /* line 1829 | systemBits */
        "shrl $3, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 8(%ecx, %edx)\n"
        "shrl $4, 0x1c(%ebp)\n" /* line 1830 | systemBits */
        "movl 0x1c(%ebp), %eax\n" /* systemBits */
        "andl $1, %eax\n"
        "movl %eax, 0xc(%ecx, %edx)\n"
        "shrl 0x1c(%ebp)\n" /* line 1831 | systemBits */
        "andl $1, 0x1c(%ebp)\n" /* systemBits */
        "movl 0x1c(%ebp), %eax\n" /* systemBits */
        "movl %eax, 0x4f3a30(%ecx)\n"
        "movl $0, 4(%ecx, %esi)\n" /* line 1832 */
        "movl 0x4f3a24(%ecx), %eax\n" /* line 1834 */
        "testl %eax, %eax\n"
        "je .Lfb26da_000b2c0f\n"
        "movl 0x195ecac, %eax\n" /* line 1837 */
        "movl 0x110(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lfb26da_000b2c35\n"
        ".Lfb26da_000b2949:\n"
        "testl %edi, %edi\n" /* line 1316 */
        "js .Lfb26da_000b2a4a\n"
        "movl $0x4f3a70, %eax\n" /* line 1319 */
        "leal (%edi, %edi, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "addl %edi, %edx\n"
        "movl $blitVQQuad32fs, 8(%edx, %eax)\n"
        "movl $blitVQQuad32fs, 0xc(%edx, %eax)\n" /* line 1320 */
        "movl $4, 0x4f3a80(%edx)\n" /* line 1321 */
        "xorl %ebx, %ebx\n"
        "movl $0xffffff01, %esi\n"
        "xorl %ecx, %ecx\n"
        "movss 0x2ed82c, %xmm6\n" /* 57.20399856567383f */
        "movss 0x2ed830, %xmm2\n" /* 32.0f */
        "movss 0x2ed834, %xmm5\n" /* 45.36399841308594f */
        "movss 0x2ed838, %xmm4\n" /* -11.512479782104492f */
        "movss 0x2ed83c, %xmm3\n" /* -23.352479934692383f */
        ".Lfb26da_000b29b0:\n"
        "cvtsi2ssl %esi, %xmm1\n" /* line 696 */
        "movaps %xmm1, %xmm0\n" /* line 698 */
        "mulss %xmm6, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, ROQ_UB_tab(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 699 */
        "mulss %xmm5, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, ROQ_VR_tab(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 700 */
        "mulss %xmm4, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, ROQ_UG_tab(%ecx)\n"
        "mulss %xmm3, %xmm1\n" /* line 701 */
        "addss %xmm2, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movl %eax, ROQ_VG_tab(%ecx)\n"
        "movl %ebx, %eax\n" /* line 702 */
        "shll $6, %eax\n"
        "movl %ebx, %edx\n"
        "sarl $2, %edx\n"
        "orl %edx, %eax\n"
        "movl %eax, ROQ_YY_tab(%ecx)\n"
        "addl $1, %ebx\n" /* line 694 */
        "addl $2, %esi\n"
        "addl $4, %ecx\n"
        "cmpl $0x100, %ebx\n"
        "jne .Lfb26da_000b29b0\n"
        "xorl %edx, %edx\n"
        "movl $0x7055c0, %ecx\n"
        ".Lfb26da_000b2a2b:\n"
        "movl %edx, %eax\n" /* line 201 */
        "imull %edx, %eax\n"
        "movw %ax, (%ecx)\n"
        "negl %eax\n" /* line 202 */
        "movw %ax, 0x100(%ecx)\n"
        "addl $1, %edx\n" /* line 199 */
        "addl $2, %ecx\n"
        "cmpl $0x80, %edx\n"
        "jne .Lfb26da_000b2a2b\n"
        ".Lfb26da_000b2a4a:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 1847 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a38(%eax, %edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl $0x6f55c0, (%esp)\n"
        "calll FS_Read\n"
        "movzbw 0x6f55c0, %dx\n" /* line 1850 */
        "movzbl 0x6f55c1, %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %edx\n"
        "cmpw $0x1084, %dx\n"
        "jne .Lfb26da_000b2c4c\n"
        "movl currentHandle, %ebx\n" /* line 1533 */
        "calll CL_ScaledMilliseconds\n"
        "movl $0x4f3a40, %esi\n"
        "leal (%ebx, %ebx, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "movl %eax, 0x4f3a40(%edx, %ebx)\n"
        "movl currentHandle, %edx\n" /* line 1534 */
        "leal (%edx, %edx, 2), %ecx\n"
        "leal (%ecx, %ecx, 8), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %eax, %ecx\n"
        "addl %edx, %ecx\n"
        "movl 0x4f3a40(%ecx), %eax\n"
        "movl %eax, 8(%ecx, %esi)\n"
        "movl %eax, 4(%ecx, %esi)\n" /* line 1535 */
        "movl $0x18, 0x4f3a50(%ecx)\n" /* line 1537 */
        "movzbl 0x6f55c6, %ebx\n" /* line 1540 */
        "movzbl 0x6f55c7, %eax\n"
        "shll $8, %eax\n"
        "movl $0x1e, %edx\n" /* line 1543 */
        "addl %eax, %ebx\n"
        "cmovnel %ebx, %edx\n"
        "movl %edx, 0x4f3abc(%ecx)\n"
        "movl $0xffffffff, 0x4f3a60(%ecx)\n" /* line 1545 */
        "movzbl 0x6f55c8, %edx\n" /* line 1547 */
        "movzbl 0x6f55c9, %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, 0x4f3a68(%ecx)\n"
        "movzbl 0x6f55ca, %ebx\n" /* line 1548 */
        "movzbl 0x6f55cc, %eax\n"
        "shll $8, %eax\n"
        "movzbl 0x6f55cb, %edx\n"
        "addl %edx, %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %ebx\n"
        "movl %ebx, 0x4f3a58(%ecx)\n"
        "movzbl 0x6f55ce, %edx\n" /* line 1549 */
        "movzbl 0x6f55cf, %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, 0x4f3aa8(%ecx)\n"
        "movl $0x10000, 4(%esp)\n" /* line 1855 */
        "movl 0x4f3a38(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sys_BeginStreamedFile\n"
        "movl currentHandle, %ecx\n" /* line 1857 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl $0x4f3a30, %edx\n"
        "movl $1, 0xc(%eax, %edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 1858 | arg */
        "movl %ecx, 4(%esp)\n"
        "movl $0x21ea64, (%esp)\n" /* "trFMV::play(), playing %s
" */
        "calll Com_DPrintf\n"
        "movl currentHandle, %ecx\n" /* line 1860 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %ecx\n"
        "movl 0x4f3a24(%ecx), %ebx\n" /* i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lfb26da_000b2be8\n"
        "movl 0x195ee8c, %eax\n" /* line 1862 */
        "movl (%eax), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, 0x4f3ac8(%ecx)\n"
        "movl $1, (%edx)\n" /* line 1863 */
        ".Lfb26da_000b2be8:\n"
        "calll Con_Close\n" /* line 1866 */
        "movl currentHandle, %ebx\n" /* line 1868 | i */
        /* } scope */
        ".Lfb26da_000b2bf3:\n"
        "movl %ebx, %eax\n" /* line 1874 | i */
        "addl $0x12c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfb26da_000b2c00:\n"
        "movl $0x4f3a30, %esi\n"
        "movl $0x4f3a10, %ebx\n" /* i */
        "jmp .Lfb26da_000b2895\n"
        /* { scope 1 */
        ".Lfb26da_000b2c0f:\n"
        "movl 0x195ee84, %eax\n" /* line 1842 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0x4f3ac0(%ecx)\n"
        "jmp .Lfb26da_000b2949\n"
        ".Lfb26da_000b2c2b:\n"
        "movl $0x4f3a10, %ebx\n" /* i */
        "jmp .Lfb26da_000b2895\n"
        ".Lfb26da_000b2c35:\n"
        "movl $0, (%esp)\n" /* line 1838 */
        "calll UI_SetActiveMenu\n"
        "movl currentHandle, %edi\n"
        "jmp .Lfb26da_000b2949\n"
        ".Lfb26da_000b2c4c:\n"
        "movl $0x21ea80, (%esp)\n" /* line 1870 */
        "calll Com_DPrintf\n"
        "calll RoQShutdown\n" /* line 1872 */
        "movl $0xffffffff, %ebx\n" /* i */
        "jmp .Lfb26da_000b2bf3\n"
        ".Lfb26da_000b2c64:\n"
        "movl 8(%ebp), %eax\n" /* line 1818 | arg */
        "movl %eax, 4(%esp)\n"
        "movl $0x21ea4c, (%esp)\n" /* "play(%s), ROQSize<=0
" */
        "calll Com_DPrintf\n"
        "movl currentHandle, %eax\n" /* line 1819 */
        "leal (%eax, %eax, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "movb $0, cinTable(%edx, %eax)\n"
        "movl $0xffffffff, %ebx\n" /* i */
        "jmp .Lfb26da_000b2bf3\n"
    );
}

/* line 1994 */
__attribute__((naked))
inflate_blocks_statef ROQ_DrawCinematicFromHandle(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1994 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %esi\n" /* handle */
        /* { scope 1 */
        "cmpl $0xf, %esi\n" /* line 2006 | handle */
        "ja .Lfb2c9c_000b2f07\n"
        "leal (%esi, %esi, 2), %eax\n" /* handle */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %esi, %eax\n" /* handle */
        "cmpl $2, 0x4f3a3c(%eax)\n"
        "je .Lfb2c9c_000b2f07\n"
        "movl 0x4f3ac4(%eax), %edx\n" /* line 2009 */
        "movl %edx, -0x34(%ebp)\n" /* buf */
        "testl %edx, %edx\n" /* line 2010 */
        "je .Lfb2c9c_000b2f07\n"
        "cvtsi2ssl 0x4f3a10(%eax), %xmm2\n" /* line 2015 */
        "cvtsi2ssl 0x4f3a14(%eax), %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "leal -0x28(%ebp), %eax\n" /* line 2017 | clearColor */
        "movl %eax, 4(%esp)\n"
        "movl $0x30, (%esp)\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "calll CL_LookupColor\n"
        "movl 0x195ecac, %edi\n" /* line 1911 */
        "movss 0x2a0a74(%edi), %xmm1\n"
        "movss -0x88(%ebp), %xmm2\n"
        "ucomiss %xmm1, %xmm2\n"
        "jne .Lfb2c9c_000b2f12\n"
        "jp .Lfb2c9c_000b2f12\n"
        "movl 0x2a0a64(%edi), %edx\n" /* line 1915 */
        "movl %edx, -0x3c(%ebp)\n" /* w */
        "movl 0x2a0a68(%edi), %edi\n" /* line 1916 */
        "movl %edi, -0x38(%ebp)\n" /* h */
        "movl $0, -0x44(%ebp)\n" /* x */
        "movl $0, -0x40(%ebp)\n" /* y */
        ".Lfb2c9c_000b2d55:\n"
        "movl $0, 0xc(%esp)\n" /* line 2021 */
        "xorl %edi, %edi\n"
        "movl %edi, 8(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* clearColor */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "movl 0x195eca8, %edx\n"
        "calll *0xc8(%edx)\n"
        "leal (%esi, %esi, 2), %ebx\n" /* line 2023 | handle */
        "leal (%ebx, %ebx, 8), %ebx\n"
        "movl %ebx, %eax\n"
        "shll $4, %eax\n"
        "addl %eax, %ebx\n"
        "addl %esi, %ebx\n" /* handle */
        "movl 0x4f3a20(%ebx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %esi, 0x1c(%esp)\n" /* handle */
        "movl -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x4f3a04(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x4f3a00(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x38(%ebp), %edx\n" /* h */
        "movl %edx, 0xc(%esp)\n"
        "movl -0x3c(%ebp), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* y */
        "movl %edx, 4(%esp)\n"
        "movl -0x44(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "movl 0x195eca8, %edx\n"
        "calll *0x9c(%edx)\n"
        "movl $0, 0x4f3a20(%ebx)\n" /* line 2024 */
        "movl 0x4f3a30(%ebx), %eax\n" /* line 2026 */
        "testl %eax, %eax\n"
        "je .Lfb2c9c_000b2f07\n"
        /* { scope 2 */
        "movl 0x195ecac, %ebx\n" /* line 1974 */
        "cvtsi2ssl 0x2a0a68(%ebx), %xmm0\n"
        "divss 0x2ed840, %xmm0\n" /* 480.0f */
        "mulss 0x2ed844, %xmm0\n" /* 105.0f */
        /* { scope 3 */
        "movss %xmm0, (%esp)\n" /* line 458 */
        "movss %xmm0, -0x78(%ebp)\n"
        "calll ceilf\n"
        "fstps -0x58(%ebp)\n"
        "cvttss2si -0x58(%ebp), %esi\n"
        /* } scope */
        "cvtsi2ssl -0x44(%ebp), %xmm1\n" /* line 1979 | x */
        "movss %xmm1, -0x30(%ebp)\n"
        "cvtsi2ssl -0x3c(%ebp), %xmm1\n" /* line 1981 | w */
        "movss %xmm1, -0x2c(%ebp)\n"
        "movl 0x2a0a58(%ebx), %eax\n" /* line 1956 */
        "movl %eax, 0x24(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* clearColor */
        "movl %eax, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n"
        "movss -0x78(%ebp), %xmm0\n" /* line 443 */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x5c(%ebp)\n"
        "cvttss2si -0x5c(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "cvtsi2ssl -0x40(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "movl 0x195eca8, %eax\n"
        "calll *0x94(%eax)\n"
        "movl 0x2a0a58(%ebx), %eax\n" /* line 1956 */
        "movl %eax, 0x24(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* clearColor */
        "movl %edx, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n"
        "cvtsi2ssl %esi, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* y */
        "addl -0x38(%ebp), %eax\n" /* h */
        "subl %esi, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "movl 0x195eca8, %eax\n"
        "calll *0x94(%eax)\n"
        /* } scope */
        /* } scope */
        ".Lfb2c9c_000b2f07:\n"
        "addl $0xac, %esp\n" /* line 2028 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb2c9c_000b2f12:\n"
        "ucomiss %xmm1, %xmm2\n" /* line 1920 */
        "ja .Lfb2c9c_000b2f82\n"
        "movl 0x2a0a64(%edi), %ebx\n" /* line 1935 */
        "cvtsi2ssl %ebx, %xmm0\n"
        "divss %xmm1, %xmm2\n" /* line 1937 */
        "mulss %xmm0, %xmm2\n"
        "subss %xmm2, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n" /* line 443 */
        "movss %xmm0, -0x78(%ebp)\n"
        "calll floorf\n"
        "fstps -0x50(%ebp)\n"
        "cvttss2si -0x50(%ebp), %edx\n"
        "movl %edx, -0x44(%ebp)\n" /* x */
        "movss -0x78(%ebp), %xmm0\n" /* line 458 */
        "movss %xmm0, (%esp)\n"
        "calll ceilf\n"
        "fstps -0x54(%ebp)\n"
        "cvttss2si -0x54(%ebp), %eax\n"
        "addl %eax, %eax\n"
        "subl %eax, %ebx\n"
        "movl %ebx, -0x3c(%ebp)\n" /* w */
        "movl 0x2a0a68(%edi), %edi\n" /* line 1944 */
        "movl %edi, -0x38(%ebp)\n" /* h */
        "movl $0, -0x40(%ebp)\n" /* y */
        "jmp .Lfb2c9c_000b2d55\n"
        ".Lfb2c9c_000b2f82:\n"
        "movl 0x2a0a68(%edi), %ebx\n" /* line 1922 */
        "cvtsi2ssl %ebx, %xmm0\n"
        "divss %xmm2, %xmm1\n" /* line 1924 */
        "mulss %xmm0, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n" /* line 443 */
        "movss %xmm0, -0x78(%ebp)\n"
        "calll floorf\n"
        "fstps -0x48(%ebp)\n"
        "cvttss2si -0x48(%ebp), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* y */
        "movl 0x2a0a64(%edi), %edi\n" /* line 1930 */
        "movl %edi, -0x3c(%ebp)\n" /* w */
        "movss -0x78(%ebp), %xmm0\n" /* line 458 */
        "movss %xmm0, (%esp)\n"
        "calll ceilf\n"
        "fstps -0x4c(%ebp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "addl %eax, %eax\n"
        "subl %eax, %ebx\n"
        "movl %ebx, -0x38(%ebp)\n" /* h */
        "movl $0, -0x44(%ebp)\n" /* x */
        "jmp .Lfb2c9c_000b2d55\n"
    );
}

/* line 2086 */
__attribute__((naked))
inflate_blocks_statef ROQ_DrawCinematic(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2086 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl CL_handle, %eax\n" /* line 2088 */
        "cmpl $0xf, %eax\n"
        "jbe .Lfb2fee_000b3000\n"
        "leave\n" /* line 2092 */
        "retl\n"
        ".Lfb2fee_000b3000:\n"
        "movl %eax, (%esp)\n" /* line 2090 */
        "calll ROQ_DrawCinematicFromHandle\n"
        "leave\n" /* line 2092 */
        "retl\n"
    );
}

/* line 1327 */
static __attribute__((naked))
inflate_blocks_statef RoQReset(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1327 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl currentHandle, %ecx\n" /* line 1330 */
        "testl %ecx, %ecx\n"
        "js .Lfb300a_000b31df\n"
        "movl $0x4f3a30, %edi\n" /* line 1333 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a38(%eax, %ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sys_EndStreamedFile\n"
        "movl currentHandle, %ecx\n" /* line 1336 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a38(%eax, %ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl currentHandle, %ecx\n" /* line 1337 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl $0, 8(%eax, %edi)\n"
        "movl $1, 8(%esp)\n" /* line 1340 */
        "leal 0x4f3a38(%eax), %edx\n"
        "movl %edx, 4(%esp)\n"
        "addl $cinTable, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileRead\n"
        "movl $0x10000, 4(%esp)\n" /* line 1342 */
        "movl currentHandle, %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a38(%eax, %ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sys_BeginStreamedFile\n"
        "movl currentHandle, %ecx\n" /* line 1343 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a38(%eax, %ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl $0x6f55c0, (%esp)\n"
        "calll Sys_StreamedRead\n"
        "movl currentHandle, %ebx\n" /* line 1533 */
        "calll CL_ScaledMilliseconds\n"
        "movl $0x4f3a40, %esi\n"
        "leal (%ebx, %ebx, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "movl %eax, 0x4f3a40(%edx, %ebx)\n"
        "movl currentHandle, %edx\n" /* line 1534 */
        "leal (%edx, %edx, 2), %ecx\n"
        "leal (%ecx, %ecx, 8), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %eax, %ecx\n"
        "addl %edx, %ecx\n"
        "movl 0x4f3a40(%ecx), %eax\n"
        "movl %eax, 8(%ecx, %esi)\n"
        "movl %eax, 4(%ecx, %esi)\n" /* line 1535 */
        "movl $0x18, 0x4f3a50(%ecx)\n" /* line 1537 */
        "movzbl 0x6f55c6, %ebx\n" /* line 1540 */
        "movzbl 0x6f55c7, %eax\n"
        "shll $8, %eax\n"
        "movl $0x1e, %edx\n" /* line 1543 */
        "addl %eax, %ebx\n"
        "cmovnel %ebx, %edx\n"
        "movl %edx, 0x4f3abc(%ecx)\n"
        "movl $0xffffffff, 0x4f3a60(%ecx)\n" /* line 1545 */
        "movzbl 0x6f55c8, %edx\n" /* line 1547 */
        "movzbl 0x6f55c9, %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, 0x4f3a68(%ecx)\n"
        "movzbl 0x6f55ca, %ebx\n" /* line 1548 */
        "movzbl 0x6f55cc, %eax\n"
        "shll $8, %eax\n"
        "movzbl 0x6f55cb, %edx\n"
        "addl %edx, %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %ebx\n"
        "movl %ebx, 0x4f3a58(%ecx)\n"
        "movzbl 0x6f55ce, %edx\n" /* line 1549 */
        "movzbl 0x6f55cf, %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, 0x4f3aa8(%ecx)\n"
        "movl $5, 0xc(%ecx, %edi)\n" /* line 1345 */
        ".Lfb300a_000b31df:\n"
        "addl $0x1c, %esp\n" /* line 1346 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 130 */
__attribute__((naked))
inflate_blocks_statef ROQ_CloseAllVideos(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 130 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "xorl %ebx, %ebx\n"
        "movl $cinTable, %esi\n"
        "xorl %edi, %edi\n"
        /* { scope 1 */
        ".Lfb31e8_000b31fa:\n"
        "cmpb $0, (%esi)\n" /* line 136 */
        "je .Lfb31e8_000b3260\n"
        "cmpl $0xf, %ebx\n" /* line 1648 | i */
        "ja .Lfb31e8_000b3260\n"
        "cmpl $2, 0x13c(%esi)\n"
        "je .Lfb31e8_000b3260\n"
        "movl %ebx, currentHandle\n" /* line 1650 | i */
        "leal cinTable(%edi, %ebx), %eax\n" /* line 1652 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21e9e4, (%esp)\n" /* "trFMV::stop(), closing %s
" */
        "calll Com_DPrintf\n"
        "movl currentHandle, %ecx\n" /* line 1654 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %edx\n"
        "movl 0x4f3ac4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfb31e8_000b3260\n"
        "movl 0x4f3a24(%edx), %eax\n" /* line 1659 */
        "testl %eax, %eax\n"
        "je .Lfb31e8_000b327c\n"
        "movl 0x195ee8c, %eax\n" /* line 1661 */
        "movl (%eax), %eax\n"
        "cmpl $1, (%eax)\n"
        "je .Lfb31e8_000b327c\n"
        ".Lfb31e8_000b3260:\n"
        "addl $1, %ebx\n" /* line 134 | i */
        "addl $0x1cb, %edi\n"
        "addl $0x1cc, %esi\n"
        "cmpl $0x10, %ebx\n" /* i */
        "jne .Lfb31e8_000b31fa\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 141 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb31e8_000b327c:\n"
        "movl $2, 0x4f3a3c(%edx)\n" /* line 1666 */
        "calll RoQShutdown\n" /* line 1667 */
        "jmp .Lfb31e8_000b3260\n"
    );
}

/* line 2104 */
__attribute__((naked))
inflate_blocks_statef ROQ_StopCinematic(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2104 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl CL_handle, %ecx\n" /* line 2106 */
        "cmpl $0xf, %ecx\n"
        "ja .Lfb328e_000b3334\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1648 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "cmpl $2, 0x4f3a3c(%eax)\n"
        "je .Lfb328e_000b331e\n"
        "movl %ecx, currentHandle\n" /* line 1650 */
        "addl $cinTable, %eax\n" /* line 1652 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21e9e4, (%esp)\n" /* "trFMV::stop(), closing %s
" */
        "calll Com_DPrintf\n"
        "movl currentHandle, %ecx\n" /* line 1654 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %edx\n"
        "movl 0x4f3ac4(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfb328e_000b331e\n"
        "movl 0x4f3a24(%edx), %eax\n" /* line 1659 */
        "testl %eax, %eax\n"
        "je .Lfb328e_000b330c\n"
        "movl 0x195ee8c, %eax\n" /* line 1661 */
        "movl (%eax), %eax\n"
        "cmpl $1, (%eax)\n"
        "jne .Lfb328e_000b331e\n"
        ".Lfb328e_000b330c:\n"
        "movl $0x4f3a30, %eax\n" /* line 1666 */
        "movl $2, 0xc(%edx, %eax)\n"
        "calll RoQShutdown\n" /* line 1667 */
        ".Lfb328e_000b331e:\n"
        "movl $0, (%esp)\n" /* line 2109 */
        "calll SND_StopSounds\n"
        "movl $0xffffffff, CL_handle\n" /* line 2110 */
        ".Lfb328e_000b3334:\n"
        "leave\n" /* line 2112 */
        "retl\n"
    );
}

/* line 1681 */
__attribute__((naked))
e_status ROQ_RunCinematicFromHandle(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1681 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1026c, %esp\n"
        "movl 8(%ebp), %esi\n" /* handle */
        /* { scope 1 */
        "cmpl $0xf, %esi\n" /* line 1689 | handle */
        "ja .Lfb3336_000b33ef\n"
        "leal (%esi, %esi, 2), %eax\n" /* handle */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %esi), %ebx\n"
        "cmpl $2, 0x4f3a3c(%ebx)\n"
        "je .Lfb3336_000b33ef\n"
        "cmpl 0x745bd0, %esi\n" /* line 1692 | handle */
        "je .Lfb3336_000b3394\n"
        "movl %esi, -0x101fc(%ebp)\n" /* line 1694 | handle */
        "movl %esi, currentHandle\n" /* handle */
        "movl %esi, 0x745bd0\n" /* line 1695 | handle */
        "movl $2, 0x4f3a3c(%ebx)\n" /* line 1696 */
        "calll RoQReset\n" /* line 1697 */
        ".Lfb3336_000b3394:\n"
        "cmpl $-1, 0x4f3ac0(%ebx)\n" /* line 1700 */
        "jl .Lfb3336_000b33de\n"
        "movl %esi, currentHandle\n" /* line 1705 | handle */
        "movl 0x4f3a24(%ebx), %edi\n" /* line 1707 */
        "testl %edi, %edi\n"
        "jne .Lfb3336_000b33d2\n"
        ".Lfb3336_000b33ad:\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 1715 | handle */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a3c(%eax, %esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfb3336_000b33ff\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1026c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb3336_000b33d2:\n"
        "movl 0x195ee8c, %eax\n" /* line 1709 */
        "movl (%eax), %eax\n"
        "cmpl $1, (%eax)\n"
        "je .Lfb3336_000b33ad\n"
        ".Lfb3336_000b33de:\n"
        "movl 0x4f3a3c(%ebx), %eax\n" /* line 1711 */
        /* } scope */
        "addl $0x1026c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb3336_000b33ef:\n"
        "movl $2, %eax\n" /* line 1782 */
        /* } scope */
        "addl $0x1026c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb3336_000b33ff:\n"
        "calll CL_ScaledMilliseconds\n" /* line 1721 */
        "movl %eax, -0x10198(%ebp)\n" /* thisTime */
        "movl currentHandle, %edx\n" /* line 1722 */
        "movl %edx, -0x101fc(%ebp)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl -0x101fc(%ebp), %eax\n"
        "movl 0x4f3a2c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfb3336_000b4126\n"
        "movl -0x10198(%ebp), %ecx\n" /* thisTime */
        "subl 0x4f3a48(%eax), %ecx\n"
        "js .Lfb3336_000b5029\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        ".Lfb3336_000b344d:\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cmpl $0x64, %eax\n"
        "jle .Lfb3336_000b4126\n"
        "movl -0x101fc(%ebp), %ebx\n" /* line 1724 */
        "leal (%ebx, %ebx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, 0x4f3a40(%eax, %ebx)\n"
        "movl %ebx, %esi\n" /* handle */
        ".Lfb3336_000b3480:\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 1727 | handle */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %esi), %edx\n"
        "movl 0x4f3a34(%edx), %edi\n"
        "testl %edi, %edi\n"
        "jne .Lfb3336_000b4622\n"
        "movl -0x10198(%ebp), %eax\n" /* line 1736 | thisTime */
        "subl 0x4f3a40(%edx), %eax\n"
        "imull 0x4f3abc(%edx), %eax\n"
        "movl $0x10624dd3, %ecx\n"
        "mull %ecx\n"
        "movl %edx, %ecx\n"
        "shrl $6, %ecx\n"
        "movl -0x101fc(%ebp), %ebx\n"
        ".Lfb3336_000b34c3:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1738 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ebx), %edx\n"
        "cmpl 0x4f3a4c(%edx), %ecx\n"
        "jle .Lfb3336_000b4131\n"
        "movl %ecx, 0x4f3a4c(%edx)\n" /* line 1740 */
        "movl -0x10198(%ebp), %esi\n" /* line 1741 | thisTime, handle */
        "movl %esi, 0x4f3a44(%edx)\n" /* handle */
        ".Lfb3336_000b34f1:\n"
        "movl -0x101fc(%ebp), %edi\n" /* line 1749 */
        "leal (%edi, %edi, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a40(%eax, %edi), %eax\n"
        "movl %eax, -0x1019c(%ebp)\n" /* start */
        "movl %edi, %ecx\n"
        ".Lfb3336_000b3513:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1750 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %edx\n"
        "movl 0x4f3a4c(%edx), %eax\n"
        "cmpl 0x4f3a60(%edx), %eax\n"
        "je .Lfb3336_000b366e\n"
        ".Lfb3336_000b3535:\n"
        "movl $0x4f3a30, %ebx\n"
        "cmpl $1, 0x4f3a3c(%edx)\n"
        "jne .Lfb3336_000b366e\n"
        "movl -0x101fc(%ebp), %esi\n" /* line 1363 */
        "testl %esi, %esi\n"
        "js .Lfb3336_000b36c9\n"
        "movl 0x4f3a38(%edx), %eax\n" /* line 1366 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl 0x4f3a58(%edx), %eax\n"
        "addl $8, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x6f55c0, (%esp)\n"
        "calll Sys_StreamedRead\n"
        "movl currentHandle, %eax\n" /* line 1367 */
        "movl %eax, -0x101fc(%ebp)\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl -0x101fc(%ebp), %ecx\n"
        "leal (%eax, %ecx), %edx\n"
        "movl 0x4f3a50(%edx), %eax\n"
        "cmpl 0x4f3a54(%edx), %eax\n"
        "jl .Lfb3336_000b36d4\n"
        "movl 0x4f3a1c(%edx), %ecx\n" /* line 1369 */
        "testl %ecx, %ecx\n"
        "jne .Lfb3336_000b3d6e\n"
        "movl 0x4f3a18(%edx), %eax\n" /* line 1371 */
        "testl %eax, %eax\n"
        "jne .Lfb3336_000b441f\n"
        "movl $2, 0xc(%edx, %ebx)\n" /* line 1377 */
        "movl -0x101fc(%ebp), %esi\n"
        ".Lfb3336_000b35dd:\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 1753 | handle */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl -0x1019c(%ebp), %edi\n" /* start */
        "cmpl 0x4f3a40(%eax, %esi), %edi\n"
        "je .Lfb3336_000b36c2\n"
        "calll CL_ScaledMilliseconds\n" /* line 1756 */
        "movl currentHandle, %edx\n"
        "movl %edx, -0x101fc(%ebp)\n"
        "leal (%edx, %edx, 2), %ecx\n"
        "leal (%ecx, %ecx, 8), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %ecx\n"
        "addl -0x101fc(%ebp), %ecx\n"
        "movl 0x4f3a40(%ecx), %ebx\n"
        "subl %ebx, %eax\n"
        "imull 0x4f3abc(%ecx), %eax\n"
        "movl $0x10624dd3, %edx\n"
        "mull %edx\n"
        "shrl $6, %edx\n"
        "movl %edx, 0x4f3a4c(%ecx)\n"
        "movl %ebx, -0x1019c(%ebp)\n" /* line 1758 | start */
        "movl -0x101fc(%ebp), %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1750 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %edx\n"
        "movl 0x4f3a4c(%edx), %eax\n"
        "cmpl 0x4f3a60(%edx), %eax\n"
        "jne .Lfb3336_000b3535\n"
        ".Lfb3336_000b366e:\n"
        "movl $0x4f3a40, %eax\n" /* line 1763 */
        "movl -0x10198(%ebp), %ebx\n" /* thisTime */
        "movl %ebx, 8(%edx, %eax)\n"
        "cmpl $5, 0x4f3a3c(%edx)\n" /* line 1765 */
        "je .Lfb3336_000b4613\n"
        ".Lfb3336_000b368a:\n"
        "cmpl $2, 0x4f3a3c(%edx)\n" /* line 1770 */
        "je .Lfb3336_000b45eb\n"
        "movl -0x101fc(%ebp), %edx\n"
        "movl -0x101fc(%ebp), %ecx\n"
        ".Lfb3336_000b36a3:\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 1782 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a3c(%eax, %ecx), %eax\n"
        /* } scope */
        "addl $0x1026c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfb3336_000b36c2:\n"
        "movl %esi, %ecx\n" /* handle */
        "jmp .Lfb3336_000b3513\n"
        ".Lfb3336_000b36c9:\n"
        "movl -0x101fc(%ebp), %esi\n" /* handle */
        "jmp .Lfb3336_000b35dd\n"
        /* { scope 1 */
        ".Lfb3336_000b36d4:\n"
        "movl $0x6f55c0, -0x1012c(%ebp)\n" /* line 1382 */
        ".Lfb3336_000b36de:\n"
        "movl -0x101fc(%ebp), %edi\n" /* line 1391 */
        "leal (%edi, %edi, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a68(%eax, %edi), %eax\n"
        "subl $0x1001, %eax\n"
        "cmpl $0x2f, %eax\n"
        "ja .Lfb3336_000b3d67\n"
        "jmpl *0x2f1ca0(, %eax, 4)\n"
        "movl -0x101fc(%ebp), %edx\n" /* line 1422 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl -0x101fc(%ebp), %eax\n"
        "movl 0x4f3a28(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfb3336_000b37c3\n"
        "movl 0x4f3a58(%eax), %esi\n" /* line 1424 */
        "movzwl 0x4f3aa8(%eax), %edx\n" /* line 260 */
        "testl %esi, %esi\n" /* line 262 */
        "je .Lfb3336_000b3770\n"
        "xorl %ebx, %ebx\n"
        "leal -0x10018(%ebp), %ecx\n"
        ".Lfb3336_000b374d:\n"
        "movl -0x1012c(%ebp), %edi\n" /* line 264 */
        "movzbl (%edi, %ebx), %eax\n"
        "addw 0x7055c0(%eax, %eax), %dx\n"
        "movw %dx, 2(%ecx)\n" /* line 265 */
        "movw %dx, (%ecx)\n"
        "addl $1, %ebx\n" /* line 262 */
        "addl $4, %ecx\n"
        "cmpl %ebx, %esi\n"
        "jne .Lfb3336_000b374d\n"
        ".Lfb3336_000b3770:\n"
        "leal -0x10018(%ebp), %eax\n" /* line 1425 */
        "movl %eax, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0x5622, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SND_RawSamples\n"
        "movl currentHandle, %edx\n" /* line 1426 */
        "movl %edx, -0x101fc(%ebp)\n"
        ".Lfb3336_000b37a6:\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 1434 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl -0x101fc(%ebp), %eax\n"
        "movl $1, 0x4f3a34(%eax)\n"
        ".Lfb3336_000b37c3:\n"
        "movl -0x101fc(%ebp), %esi\n"
        ".Lfb3336_000b37c9:\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 1464 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %esi), %ebx\n"
        "movl 0x4f3a50(%ebx), %eax\n"
        "cmpl 0x4f3a54(%ebx), %eax\n"
        "jge .Lfb3336_000b38ed\n"
        ".Lfb3336_000b37eb:\n"
        "movl -0x1012c(%ebp), %esi\n" /* line 1484 */
        "addl 0x4f3a58(%ebx), %esi\n"
        "movzbl (%esi), %edx\n" /* line 1485 */
        "movzbl 1(%esi), %eax\n"
        "shll $8, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl %eax, -0x101b0(%ebp)\n"
        "movl %eax, 0x4f3a68(%ebx)\n"
        "movzbl 2(%esi), %ecx\n" /* line 1486 */
        "movzbl 4(%esi), %eax\n"
        "shll $8, %eax\n"
        "movzbl 3(%esi), %edx\n"
        "addl %edx, %eax\n"
        "shll $8, %eax\n"
        "leal (%ecx, %eax), %edi\n"
        "movl $0x4f3a50, %eax\n"
        "movl %edi, 8(%ebx, %eax)\n"
        "movl $0x4f3aa0, %ecx\n" /* line 1487 */
        "movzbl 6(%esi), %edx\n"
        "movzbl 7(%esi), %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, 8(%ebx, %ecx)\n"
        "movsbl 7(%esi), %eax\n" /* line 1488 */
        "movl %eax, 0xc(%ebx, %ecx)\n"
        "movsbl 6(%esi), %eax\n" /* line 1489 */
        "movl %eax, 0x4f3ab0(%ebx)\n"
        "cmpl $0x10000, 0x4f3a58(%ebx)\n" /* line 1491 */
        "ja .Lfb3336_000b3d81\n"
        "cmpl $0x1084, 0x4f3a68(%ebx)\n"
        "je .Lfb3336_000b3d81\n"
        "movl 0x4f3aa0(%ebx), %eax\n" /* line 1501 */
        "testl %eax, %eax\n"
        "je .Lfb3336_000b3dea\n"
        "cmpl $2, 0x4f3a3c(%ebx)\n"
        "je .Lfb3336_000b3dea\n"
        "subl $1, %eax\n" /* line 1503 */
        "movl %eax, 0x4f3aa0(%ebx)\n"
        "addl $8, %esi\n" /* line 1504 */
        "movl %esi, -0x1012c(%ebp)\n"
        "jmp .Lfb3336_000b36de\n"
        "movl -0x101fc(%ebp), %ecx\n" /* line 1453 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl $0, 0x4f3a58(%eax)\n"
        "movl %ecx, %esi\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 1464 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %esi), %ebx\n"
        "movl 0x4f3a50(%ebx), %eax\n"
        "cmpl 0x4f3a54(%ebx), %eax\n"
        "jl .Lfb3336_000b37eb\n"
        ".Lfb3336_000b38ed:\n"
        "movl 0x4f3a1c(%ebx), %eax\n" /* line 1466 */
        "testl %eax, %eax\n"
        "jne .Lfb3336_000b4667\n"
        "movl 0x4f3a18(%ebx), %edi\n" /* line 1468 */
        "testl %edi, %edi\n"
        "jne .Lfb3336_000b482b\n"
        "movl $2, 0x4f3a3c(%ebx)\n" /* line 1474 */
        "movl -0x101fc(%ebp), %esi\n"
        "jmp .Lfb3336_000b35dd\n"
        "movl -0x101fc(%ebp), %ecx\n" /* line 1430 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl 0x4f3a28(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfb3336_000b3ef9\n"
        "movl 0x4f3a58(%eax), %ebx\n" /* line 1432 */
        "movl %ebx, -0x10130(%ebp)\n"
        "movzwl 0x4f3aa8(%eax), %eax\n"
        "movl %eax, %ebx\n" /* line 300 */
        "xorb %bl, %bl\n"
        "movl %eax, %ecx\n" /* line 301 */
        "shll $8, %ecx\n"
        "movl -0x10130(%ebp), %eax\n" /* line 304 */
        "testl %eax, %eax\n"
        "je .Lfb3336_000b39a4\n"
        "movl -0x1012c(%ebp), %edx\n"
        "xorl %edi, %edi\n"
        "leal -0x10018(%ebp), %esi\n"
        ".Lfb3336_000b3975:\n"
        "movzbl (%edx), %eax\n" /* line 306 */
        "addw 0x7055c0(%eax, %eax), %bx\n"
        "movzbl 1(%edx), %eax\n" /* line 307 */
        "addw 0x7055c0(%eax, %eax), %cx\n"
        "addl $2, %edx\n"
        "movw %bx, (%esi)\n" /* line 308 */
        "movw %cx, 2(%esi)\n" /* line 309 */
        "addl $2, %edi\n" /* line 304 */
        "addl $4, %esi\n"
        "cmpl %edi, -0x10130(%ebp)\n"
        "ja .Lfb3336_000b3975\n"
        ".Lfb3336_000b39a4:\n"
        "leal -0x10018(%ebp), %esi\n" /* line 1433 */
        "movl %esi, 0x10(%esp)\n"
        "movl $2, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0x5622, 4(%esp)\n"
        "shrl -0x10130(%ebp)\n"
        "movl -0x10130(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll SND_RawSamples\n"
        "movl currentHandle, %eax\n" /* line 1434 */
        "movl %eax, -0x101fc(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfb3336_000b37a6\n"
        "movl -0x101fc(%ebp), %ebx\n"
        ".Lfb3336_000b39f2:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1458 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ebx, %eax\n"
        "movl $2, 0x4f3a3c(%eax)\n"
        "movl %ebx, %esi\n"
        "jmp .Lfb3336_000b37c9\n"
        "movl -0x101fc(%ebp), %ecx\n" /* line 1438 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %edi\n"
        "cmpl $-1, 0x4f3a60(%edi)\n"
        "je .Lfb3336_000b41a3\n"
        "movl %ecx, %edi\n"
        ".Lfb3336_000b3a37:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 1445 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %edi, %eax\n"
        "cmpl $1, 0x4f3a60(%eax)\n"
        "je .Lfb3336_000b419c\n"
        "movl $0, 0x4f3a60(%eax)\n" /* line 1446 */
        "movl -0x101fc(%ebp), %esi\n"
        "jmp .Lfb3336_000b37c9\n"
        "movl -0x101fc(%ebp), %ecx\n" /* line 1417 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movzwl 0x4f3aa8(%eax, %ecx), %edx\n"
        "testw %dx, %dx\n" /* line 862 */
        "jne .Lfb3336_000b40f8\n"
        "movl $0x100, -0x1017c(%ebp)\n"
        "movl $0x200, -0x10128(%ebp)\n"
        ".Lfb3336_000b3aa0:\n"
        "movl -0x101fc(%ebp), %esi\n" /* line 878 */
        "leal (%esi, %esi, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %esi, %eax\n"
        "movl 0x4f3a98(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfb3336_000b3fe3\n"
        "movl 0x4f3a9c(%eax), %edi\n" /* line 880 */
        "testl %edi, %edi\n"
        "jne .Lfb3336_000b4437\n"
        "movl 0x4f3a80(%eax), %edx\n" /* line 885 */
        "cmpl $2, %edx\n"
        "je .Lfb3336_000b4d2a\n"
        "cmpl $4, %edx\n" /* line 912 */
        "je .Lfb3336_000b4841\n"
        "subl $1, %edx\n" /* line 940 */
        "jne .Lfb3336_000b37c3\n"
        "movl $vq2, %ebx\n" /* line 942 */
        "movl -0x1017c(%ebp), %edx\n" /* line 943 */
        "testl %edx, %edx\n"
        "jg .Lfb3336_000b637a\n"
        "movl -0x1012c(%ebp), %ecx\n"
        "movl %ecx, -0x1005c(%ebp)\n"
        ".Lfb3336_000b3b11:\n"
        "movl -0x10128(%ebp), %eax\n" /* line 955 */
        "testl %eax, %eax\n"
        "jle .Lfb3336_000b37c3\n"
        "movl $vq8, -0x100e4(%ebp)\n"
        "movl $vq4, -0x100e0(%ebp)\n"
        "movl $0, -0x10048(%ebp)\n"
        "jmp .Lfb3336_000b3b66\n"
        ".Lfb3336_000b3b3f:\n"
        "addl $1, -0x10048(%ebp)\n"
        "addl $0x20, -0x100e4(%ebp)\n"
        "addl $8, -0x100e0(%ebp)\n"
        "movl -0x10048(%ebp), %edx\n"
        "cmpl %edx, -0x10128(%ebp)\n"
        "je .Lfb3336_000b37c3\n"
        ".Lfb3336_000b3b66:\n"
        "movl -0x100e0(%ebp), %edi\n"
        "movl -0x100e4(%ebp), %esi\n"
        "movl -0x1005c(%ebp), %edx\n" /* line 957 */
        "movzbl (%edx), %eax\n"
        "movl %edx, %ecx\n" /* line 958 */
        "movzbl 1(%edx), %edx\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x1005c(%ebp)\n"
        "leal 0x746fe2(, %eax, 4), %eax\n"
        "movl %eax, -0x100ec(%ebp)\n"
        "leal 0x746fe2(, %edx, 4), %edx\n"
        "movl %edx, -0x100e8(%ebp)\n"
        "movl $2, -0x10118(%ebp)\n"
        ".Lfb3336_000b3bae:\n"
        "movzbl -2(%eax), %ebx\n" /* line 960 */
        "movb %bl, (%edi)\n"
        "movb %bl, (%esi)\n"
        "movb %bl, 1(%esi)\n"
        "movzbl -1(%eax), %ecx\n"
        "movb %cl, 1(%edi)\n"
        "movb %cl, 2(%esi)\n"
        "movb %cl, 3(%esi)\n"
        "movl -0x100e8(%ebp), %eax\n"
        "movzbl -2(%eax), %edx\n"
        "movb %dl, 2(%edi)\n"
        "movb %dl, 4(%esi)\n"
        "movb %dl, 5(%esi)\n"
        "movzbl -1(%eax), %eax\n"
        "movb %al, 3(%edi)\n"
        "addl $4, %edi\n"
        "movb %al, 6(%esi)\n"
        "movb %al, 7(%esi)\n"
        "movb %bl, 8(%esi)\n"
        "movb %bl, 9(%esi)\n"
        "movb %cl, 0xa(%esi)\n"
        "movb %cl, 0xb(%esi)\n"
        "movb %dl, 0xc(%esi)\n"
        "movb %dl, 0xd(%esi)\n"
        "movb %al, 0xe(%esi)\n"
        "movb %al, 0xf(%esi)\n"
        "addl $0x10, %esi\n"
        "addl $2, -0x100ec(%ebp)\n"
        "addl $2, -0x100e8(%ebp)\n"
        "subl $1, -0x10118(%ebp)\n" /* line 959 */
        "je .Lfb3336_000b3b3f\n"
        "movl -0x100ec(%ebp), %eax\n"
        "jmp .Lfb3336_000b3bae\n"
        "movl 0x195eca8, %eax\n" /* line 1395 */
        "calll *0x148(%eax)\n"
        "movl currentHandle, %ebx\n" /* line 1397 */
        "leal (%ebx, %ebx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ebx), %edx\n"
        "testb $1, 0x4f3a60(%edx)\n"
        "je .Lfb3336_000b3e1b\n"
        "movl 0x4f3ab8(%edx), %eax\n" /* line 1399 */
        "movl %eax, 0x4f3aa4(%edx)\n"
        "movl 0x4f3ab0(%edx), %edi\n" /* line 1400 */
        "movl 0x4f3aac(%edx), %ecx\n"
        "movl 0x4f3a64(%edx), %eax\n" /* line 1286 */
        "movl %eax, -0x10194(%ebp)\n"
        "movl 0x4f3a80(%edx), %esi\n" /* line 1287 */
        "movl 0x4f3a8c(%edx), %eax\n" /* line 1288 */
        "shll $2, %eax\n"
        "cmpl %eax, 0x4f3a88(%edx)\n"
        "je .Lfb3336_000b497c\n"
        ".Lfb3336_000b3c94:\n"
        "subl $8, %edi\n" /* line 1291 */
        "movl $0, -0x10190(%ebp)\n"
        "leal -8(%ecx), %eax\n"
        "leal (%ebx, %ebx, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "addl %ebx, %edx\n"
        "movl %edx, -0x101a0(%ebp)\n"
        "movl 0x4f3aa4(%edx), %edx\n"
        "movl %edx, -0x101a4(%ebp)\n"
        "imull -0x10194(%ebp), %edi\n"
        "movl $0x210200, -0x1020c(%ebp)\n"
        "imull %esi, %eax\n"
        "movl %eax, -0x10204(%ebp)\n"
        "negl %esi\n"
        ".Lfb3336_000b3ce1:\n"
        "movl -0x1020c(%ebp), %ecx\n" /* line 1296 */
        "addl $cin, %ecx\n"
        "movl $0x10, %ebx\n"
        "addl %edi, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        ".Lfb3336_000b3cf8:\n"
        "movl %eax, (%ecx)\n" /* line 1300 */
        "addl %esi, %eax\n"
        "addl $0x40, %ecx\n"
        "subl $1, %ebx\n" /* line 1297 */
        "jne .Lfb3336_000b3cf8\n"
        "addl $1, -0x10190(%ebp)\n" /* line 1294 */
        "addl $4, -0x1020c(%ebp)\n"
        "addl -0x10194(%ebp), %edi\n"
        "cmpl $0x10, -0x10190(%ebp)\n"
        "je .Lfb3336_000b3f00\n"
        "movl -0x10204(%ebp), %eax\n"
        "movl -0x101a4(%ebp), %edx\n"
        "jmp .Lfb3336_000b3ce1\n"
        "movl -0x101fc(%ebp), %edx\n" /* line 1449 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl -0x101fc(%ebp), %eax\n"
        "movl 0x4f3aa8(%eax), %edx\n"
        "movl %edx, 0x4f3aa0(%eax)\n"
        "movl $0, 0x4f3a58(%eax)\n" /* line 1450 */
        "jmp .Lfb3336_000b37c3\n"
        ".Lfb3336_000b3d67:\n"
        "movl %edi, %ebx\n"
        "jmp .Lfb3336_000b39f2\n"
        ".Lfb3336_000b3d6e:\n"
        "movl $0, 0xc(%edx, %ebx)\n" /* line 1382 */
        "movl -0x101fc(%ebp), %esi\n"
        "jmp .Lfb3336_000b35dd\n"
        ".Lfb3336_000b3d81:\n"
        "movl -0x101b0(%ebp), %eax\n" /* line 1493 */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21eaa0, (%esp)\n" /* "roq_size>65536||roq_id==0x1084 (roq_size=%i,roq_id=%i)
" */
        "calll Com_DPrintf\n"
        "movl currentHandle, %edx\n" /* line 1494 */
        "movl %edx, -0x101fc(%ebp)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl -0x101fc(%ebp), %eax\n"
        "movl $2, 0x4f3a3c(%eax)\n"
        "movl 0x4f3a18(%eax), %esi\n" /* line 1495 */
        "testl %esi, %esi\n"
        "je .Lfb3336_000b36c9\n"
        "calll RoQReset\n" /* line 1497 */
        "movl currentHandle, %ecx\n"
        "movl %ecx, -0x101fc(%ebp)\n"
        "movl %ecx, %esi\n"
        "jmp .Lfb3336_000b35dd\n"
        ".Lfb3336_000b3dea:\n"
        "movl -0x101fc(%ebp), %ebx\n" /* line 1518 */
        "leal (%ebx, %ebx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ebx, %eax\n"
        "movl 0x4f3a50(%eax), %edx\n"
        "addl 0x4f3a58(%eax), %edx\n"
        "addl $8, %edx\n"
        "movl %edx, 0x4f3a50(%eax)\n"
        "movl %ebx, %esi\n"
        "jmp .Lfb3336_000b35dd\n"
        ".Lfb3336_000b3e1b:\n"
        "movl 0x4f3ab4(%edx), %eax\n" /* line 1406 */
        "movl %eax, 0x4f3aa4(%edx)\n"
        "movl 0x4f3ab0(%edx), %edi\n" /* line 1407 */
        "movl 0x4f3aac(%edx), %ecx\n"
        "movl 0x4f3a64(%edx), %esi\n" /* line 1286 */
        "movl %esi, -0x1018c(%ebp)\n"
        "movl 0x4f3a80(%edx), %esi\n" /* line 1287 */
        "movl 0x4f3a8c(%edx), %eax\n" /* line 1288 */
        "shll $2, %eax\n"
        "cmpl %eax, 0x4f3a88(%edx)\n"
        "je .Lfb3336_000b4a8d\n"
        ".Lfb3336_000b3e5a:\n"
        "subl $8, %edi\n" /* line 1291 */
        "movl $0, -0x10188(%ebp)\n"
        "leal -8(%ecx), %eax\n"
        "leal (%ebx, %ebx, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "addl %ebx, %edx\n"
        "movl %edx, -0x101a8(%ebp)\n"
        "movl 0x4f3aa4(%edx), %edx\n"
        "movl %edx, -0x101ac(%ebp)\n"
        "imull -0x1018c(%ebp), %edi\n"
        "movl $0x210200, -0x1020c(%ebp)\n"
        "imull %esi, %eax\n"
        "movl %eax, -0x10200(%ebp)\n"
        "negl %esi\n"
        ".Lfb3336_000b3ea7:\n"
        "movl -0x1020c(%ebp), %ecx\n" /* line 1296 */
        "addl $cin, %ecx\n"
        "movl $0x10, %ebx\n"
        "addl %edi, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        ".Lfb3336_000b3ebe:\n"
        "movl %eax, (%ecx)\n" /* line 1300 */
        "addl %esi, %eax\n"
        "addl $0x40, %ecx\n"
        "subl $1, %ebx\n" /* line 1297 */
        "jne .Lfb3336_000b3ebe\n"
        "addl $1, -0x10188(%ebp)\n" /* line 1294 */
        "addl $4, -0x1020c(%ebp)\n"
        "addl -0x1018c(%ebp), %edi\n"
        "cmpl $0x10, -0x10188(%ebp)\n"
        "je .Lfb3336_000b3f9b\n"
        "movl -0x10200(%ebp), %eax\n"
        "movl -0x101ac(%ebp), %edx\n"
        "jmp .Lfb3336_000b3ea7\n"
        ".Lfb3336_000b3ef9:\n"
        "movl %ecx, %esi\n"
        "jmp .Lfb3336_000b37c9\n"
        ".Lfb3336_000b3f00:\n"
        "movl -0x1012c(%ebp), %ecx\n" /* line 1401 */
        "movl %ecx, 4(%esp)\n"
        "movl $0x725bc0, (%esp)\n"
        "movl -0x101a0(%ebp), %ebx\n"
        "calll *0x4f3a74(%ebx)\n"
        "movl currentHandle, %esi\n" /* line 1402 */
        "movl %esi, -0x101fc(%ebp)\n"
        "leal (%esi, %esi, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %esi, %eax\n"
        "movl 0x4f3a6c(%eax), %edx\n"
        "addl $cin, %edx\n"
        "movl %edx, 0x4f3ac4(%eax)\n"
        "movl %esi, %edi\n"
        ".Lfb3336_000b3f4c:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 1411 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %edi), %edx\n"
        "movl 0x4f3a60(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfb3336_000b415e\n"
        "movl %edi, %edx\n"
        ".Lfb3336_000b3f6c:\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 1415 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl -0x101fc(%ebp), %eax\n"
        "addl $1, 0x4f3a60(%eax)\n"
        "movl $1, 0x4f3a20(%eax)\n" /* line 1416 */
        "movl -0x101fc(%ebp), %esi\n"
        "jmp .Lfb3336_000b37c9\n"
        ".Lfb3336_000b3f9b:\n"
        "movl -0x1012c(%ebp), %ecx\n" /* line 1408 */
        "movl %ecx, 4(%esp)\n"
        "movl $0x705bc0, (%esp)\n"
        "movl -0x101a8(%ebp), %ebx\n"
        "calll *0x4f3a70(%ebx)\n"
        "movl currentHandle, %esi\n" /* line 1409 */
        "movl %esi, -0x101fc(%ebp)\n"
        "leal (%esi, %esi, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl $cin, 0x4f3ac4(%eax, %esi)\n"
        "movl %esi, %edi\n"
        "jmp .Lfb3336_000b3f4c\n"
        ".Lfb3336_000b3fe3:\n"
        "movl 0x4f3a80(%eax), %edx\n" /* line 1079 */
        "cmpl $2, %edx\n"
        "je .Lfb3336_000b4997\n"
        "cmpl $1, %edx\n" /* line 1106 */
        "je .Lfb3336_000b4aa8\n"
        "cmpl $4, %edx\n" /* line 1131 */
        "jne .Lfb3336_000b37c3\n"
        "movl $vq2, -0x10088(%ebp)\n" /* line 1133 */
        "movl -0x1017c(%ebp), %esi\n" /* line 1134 */
        "testl %esi, %esi\n"
        "jg .Lfb3336_000b584d\n"
        "movl -0x1012c(%ebp), %edx\n"
        "movl %edx, -0x10070(%ebp)\n"
        ".Lfb3336_000b4028:\n"
        "movl -0x10128(%ebp), %ebx\n" /* line 1149 */
        "testl %ebx, %ebx\n"
        "jle .Lfb3336_000b37c3\n"
        "movl $vq8, -0x1009c(%ebp)\n"
        "movl $vq4, -0x10098(%ebp)\n"
        "movl $0, -0x1001c(%ebp)\n"
        ".Lfb3336_000b4054:\n"
        "movl -0x10098(%ebp), %esi\n"
        "movl -0x1009c(%ebp), %ecx\n"
        "movl -0x10070(%ebp), %edi\n" /* line 1151 */
        "movzbl (%edi), %eax\n"
        "movzbl 1(%edi), %edx\n" /* line 1152 */
        "addl $2, %edi\n"
        "movl %edi, -0x10070(%ebp)\n"
        "leal 0x746fe4(, %eax, 8), %edi\n"
        "leal 0x746fe4(, %edx, 8), %ebx\n"
        "movl $0, -0x10180(%ebp)\n"
        ".Lfb3336_000b408e:\n"
        "movl -4(%edi), %edx\n" /* line 1155 */
        "movl %edx, (%esi)\n"
        "movl %edx, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl -4(%ebx), %eax\n"
        "movl %eax, 4(%esi)\n"
        "addl $8, %esi\n"
        "movl %eax, 8(%ecx)\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl %edx, 0x10(%ecx)\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl %eax, 0x18(%ecx)\n"
        "movl %eax, 0x1c(%ecx)\n"
        "addl $0x20, %ecx\n"
        "addl $1, -0x10180(%ebp)\n" /* line 1153 */
        "addl $4, %edi\n"
        "addl $4, %ebx\n"
        "cmpl $2, -0x10180(%ebp)\n"
        "jne .Lfb3336_000b408e\n"
        "addl $1, -0x1001c(%ebp)\n" /* line 1149 */
        "addl $0x40, -0x1009c(%ebp)\n"
        "addl $0x10, -0x10098(%ebp)\n"
        "movl -0x1001c(%ebp), %eax\n"
        "cmpl %eax, -0x10128(%ebp)\n"
        "jne .Lfb3336_000b4054\n"
        "jmp .Lfb3336_000b37c3\n"
        ".Lfb3336_000b40f8:\n"
        "movl %edx, %eax\n" /* line 868 */
        "shrw $8, %ax\n"
        "movzwl %ax, %ebx\n"
        "movl %ebx, -0x1017c(%ebp)\n"
        "testw %ax, %ax\n" /* line 869 */
        "jne .Lfb3336_000b4116\n"
        "movl $0x100, -0x1017c(%ebp)\n"
        ".Lfb3336_000b4116:\n"
        "movzbl %dl, %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, -0x10128(%ebp)\n"
        "jmp .Lfb3336_000b3aa0\n"
        ".Lfb3336_000b4126:\n"
        "movl -0x101fc(%ebp), %esi\n"
        "jmp .Lfb3336_000b3480\n"
        ".Lfb3336_000b4131:\n"
        "movl -0x10198(%ebp), %eax\n" /* line 1743 | thisTime */
        "subl 0x4f3a44(%edx), %eax\n"
        "imull 0x4f3abc(%edx), %eax\n"
        "cmpl $0xfa0, %eax\n"
        "jbe .Lfb3336_000b34f1\n"
        "movl $2, 0x4f3a3c(%edx)\n" /* line 1746 */
        "jmp .Lfb3336_000b34f1\n"
        ".Lfb3336_000b415e:\n"
        "movl 0x4f3a64(%edx), %eax\n" /* line 1413 */
        "imull 0x4f3a8c(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $cin, 4(%esp)\n"
        "movl 0x4f3a6c(%edx), %eax\n"
        "addl $cin, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl currentHandle, %eax\n"
        "movl %eax, -0x101fc(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfb3336_000b3f6c\n"
        ".Lfb3336_000b419c:\n"
        "movl %edi, %esi\n"
        "jmp .Lfb3336_000b37c9\n"
        ".Lfb3336_000b41a3:\n"
        "testl %ecx, %ecx\n" /* line 1257 */
        "js .Lfb3336_000b4292\n"
        "movl $0x4f3a80, %edx\n" /* line 1260 */
        "movl -0x1012c(%ebp), %ebx\n"
        "movzbl (%ebx), %ecx\n"
        "movzbl 1(%ebx), %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %ecx\n"
        "movl %ecx, 8(%edi, %edx)\n"
        "movl -0x1012c(%ebp), %esi\n" /* line 1261 */
        "movzbl 2(%esi), %ebx\n"
        "movzbl 3(%esi), %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %ebx\n"
        "movl %ebx, 0xc(%edi, %edx)\n"
        "movl $0x4f3a90, %esi\n" /* line 1262 */
        "movl -0x1012c(%ebp), %eax\n"
        "movzbl 4(%eax), %eax\n"
        "movl %eax, -0x1020c(%ebp)\n"
        "movl -0x1012c(%ebp), %edx\n"
        "movzbl 5(%edx), %eax\n"
        "shll $8, %eax\n"
        "movl -0x1020c(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, 0x4f3a90(%edi)\n"
        "movl -0x1012c(%ebp), %eax\n" /* line 1263 */
        "movzbl 6(%eax), %eax\n"
        "movl %eax, -0x1020c(%ebp)\n"
        "movl -0x1012c(%ebp), %edx\n"
        "movzbl 7(%edx), %eax\n"
        "shll $8, %eax\n"
        "movl -0x1020c(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, 4(%edi, %esi)\n"
        "movl %ebx, 0x4f3a04(%edi)\n" /* line 1265 */
        "movl %ecx, 0x4f3a00(%edi)\n" /* line 1266 */
        "imull 0x4f3a80(%edi), %ecx\n" /* line 1268 */
        "movl %ecx, 0x4f3a64(%edi)\n"
        "imull 0x4f3a04(%edi), %ecx\n" /* line 1269 */
        "movl %ecx, 0x4f3a6c(%edi)\n"
        "movl $0, 8(%edi, %esi)\n" /* line 1271 */
        "movl $0, 0xc(%edi, %esi)\n" /* line 1272 */
        "movl 0x4f3a78(%edi), %eax\n" /* line 1274 */
        "movl %eax, 0x4f3a70(%edi)\n"
        "movl 0x4f3a7c(%edi), %eax\n" /* line 1275 */
        "movl %eax, 0x4f3a74(%edi)\n"
        "movl %ecx, 0x4f3ab4(%edi)\n" /* line 1277 */
        "negl %ecx\n" /* line 1278 */
        "movl %ecx, 0x4f3ab8(%edi)\n"
        ".Lfb3336_000b4292:\n"
        "movl 0x745bc0, %eax\n" /* line 1221 */
        "testl %eax, %eax\n"
        "jne .Lfb3336_000b42c4\n"
        "movl 0x745bc4, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfb3336_000b42c4\n"
        "movl 0x4f3a8c(%edi), %eax\n"
        "cmpl 0x745bc8, %eax\n"
        "jne .Lfb3336_000b42c4\n"
        "movl 0x4f3a88(%edi), %eax\n"
        "cmpl 0x745bcc, %eax\n"
        "je .Lfb3336_000b43e6\n"
        ".Lfb3336_000b42c4:\n"
        "movl $0, 0x745bc0\n" /* line 1226 */
        "movl $0, 0x745bc4\n" /* line 1227 */
        "movl -0x101fc(%ebp), %ecx\n" /* line 1228 */
        "leal (%ecx, %ecx, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %eax, %edx\n"
        "addl %ecx, %edx\n"
        "movl 0x4f3a8c(%edx), %eax\n"
        "movl %eax, 0x745bc8\n"
        "movl 0x4f3a88(%edx), %eax\n" /* line 1229 */
        "movl %eax, 0x745bcc\n"
        "imull 0x4f3a8c(%edx), %eax\n" /* line 1235 */
        "shrl $4, %eax\n"
        "movl %eax, %ecx\n" /* line 1236 */
        "sarl $2, %ecx\n"
        "leal 0x40(%eax, %ecx), %edi\n" /* line 1237 */
        "movl $0, 0x4f3a5c(%edx)\n" /* line 1239 */
        "movl 0x4f3a8c(%edx), %eax\n" /* line 1241 */
        "testl %eax, %eax\n"
        "jle .Lfb3336_000b43bc\n"
        "xorl %esi, %esi\n"
        "movl -0x101fc(%ebp), %edx\n"
        "movl -0x101fc(%ebp), %ecx\n"
        "jmp .Lfb3336_000b4359\n"
        ".Lfb3336_000b433e:\n"
        "addl $0x10, %esi\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "cmpl 0x4f3a8c(%eax, %ecx), %esi\n"
        "jge .Lfb3336_000b43bc\n"
        "movl %ecx, %edx\n"
        ".Lfb3336_000b4359:\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 1242 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x4f3a88(%eax, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfb3336_000b433e\n"
        "xorl %ebx, %ebx\n"
        ".Lfb3336_000b4373:\n"
        "movl $0, 4(%esp)\n" /* line 1243 */
        "movl $0, (%esp)\n"
        "movl $0x10, %ecx\n"
        "movl %esi, %edx\n"
        "movl %ebx, %eax\n"
        "calll recurseQuad\n"
        "addl $0x10, %ebx\n" /* line 1242 */
        "movl currentHandle, %eax\n"
        "movl %eax, -0x101fc(%ebp)\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl -0x101fc(%ebp), %ecx\n"
        "cmpl 0x4f3a88(%eax, %ecx), %ebx\n"
        "jl .Lfb3336_000b4373\n"
        "jmp .Lfb3336_000b433e\n"
        ".Lfb3336_000b43bc:\n"
        "leal -0x40(%edi), %eax\n" /* line 1247 */
        "leal 0x705bc0(, %eax, 4), %edx\n"
        "xorl %ecx, %ecx\n"
        "subl %eax, %edi\n"
        "movl %edi, %eax\n"
        ".Lfb3336_000b43cc:\n"
        "movl $0, (%edx)\n" /* line 1249 */
        "movl $0, 0x20000(%edx)\n" /* line 1250 */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %ecx, %eax\n" /* line 1247 */
        "jne .Lfb3336_000b43cc\n"
        ".Lfb3336_000b43e6:\n"
        "calll CL_ScaledMilliseconds\n" /* line 1443 */
        "movl -0x101fc(%ebp), %ebx\n"
        "leal (%ebx, %ebx, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "addl %ebx, %edx\n"
        "movl %eax, 0x4f3a48(%edx)\n"
        "movl %eax, 0x4f3a40(%edx)\n"
        "movl currentHandle, %esi\n"
        "movl %esi, -0x101fc(%ebp)\n"
        "movl %esi, %edi\n"
        "jmp .Lfb3336_000b3a37\n"
        ".Lfb3336_000b441f:\n"
        "calll RoQReset\n" /* line 1373 */
        "movl currentHandle, %ebx\n"
        "movl %ebx, -0x101fc(%ebp)\n"
        "movl %ebx, %esi\n"
        "jmp .Lfb3336_000b35dd\n"
        ".Lfb3336_000b4437:\n"
        "movl 0x4f3a80(%eax), %edx\n" /* line 969 */
        "cmpl $2, %edx\n"
        "je .Lfb3336_000b4e71\n"
        "cmpl $4, %edx\n" /* line 1003 */
        "je .Lfb3336_000b4696\n"
        "subl $1, %edx\n" /* line 1038 */
        "jne .Lfb3336_000b37c3\n"
        "movl $vq2, -0x10084(%ebp)\n" /* line 1040 */
        "movl -0x1017c(%ebp), %esi\n" /* line 1041 */
        "testl %esi, %esi\n"
        "jg .Lfb3336_000b6284\n"
        "movl -0x1012c(%ebp), %ecx\n"
        "movl %ecx, -0x10068(%ebp)\n"
        ".Lfb3336_000b447c:\n"
        "movl -0x10128(%ebp), %ebx\n" /* line 1061 */
        "testl %ebx, %ebx\n"
        "jle .Lfb3336_000b37c3\n"
        "movl $vq8, -0x100b4(%ebp)\n"
        "movl $vq4, -0x100b0(%ebp)\n"
        "movl $0, -0x10030(%ebp)\n"
        "jmp .Lfb3336_000b44d1\n"
        ".Lfb3336_000b44aa:\n"
        "addl $1, -0x10030(%ebp)\n"
        "addl $0x40, -0x100b4(%ebp)\n"
        "addl $0x10, -0x100b0(%ebp)\n"
        "movl -0x10030(%ebp), %edx\n"
        "cmpl %edx, -0x10128(%ebp)\n"
        "je .Lfb3336_000b37c3\n"
        ".Lfb3336_000b44d1:\n"
        "movl -0x100b0(%ebp), %edi\n"
        "movl -0x100b4(%ebp), %esi\n"
        "movl -0x10068(%ebp), %ebx\n" /* line 1063 */
        "movzbl (%ebx), %eax\n"
        "movzbl 1(%ebx), %edx\n" /* line 1064 */
        "addl $2, %ebx\n"
        "movl %ebx, -0x10068(%ebp)\n"
        "leal 0x746fe4(, %eax, 8), %eax\n"
        "movl %eax, -0x100bc(%ebp)\n"
        "leal 0x746fe4(, %edx, 8), %edx\n"
        "movl %edx, -0x100b8(%ebp)\n"
        "movl $2, -0x10124(%ebp)\n"
        ".Lfb3336_000b4517:\n"
        "movzbl -4(%eax), %ebx\n" /* line 1067 */
        "movb %bl, (%edi)\n"
        "movb %bl, (%esi)\n"
        "movb %bl, 1(%esi)\n"
        "movzbl -3(%eax), %ecx\n"
        "movb %cl, 1(%edi)\n"
        "movb %cl, 2(%esi)\n"
        "movb %cl, 3(%esi)\n"
        "movl -0x100b8(%ebp), %eax\n"
        "movzbl -4(%eax), %edx\n"
        "movb %dl, 2(%edi)\n"
        "movb %dl, 4(%esi)\n"
        "movb %dl, 5(%esi)\n"
        "movzbl -3(%eax), %eax\n"
        "movb %al, 3(%edi)\n"
        "movb %al, 6(%esi)\n"
        "movb %al, 7(%esi)\n"
        "movb %bl, 8(%esi)\n"
        "movb %bl, 9(%esi)\n"
        "movb %cl, 0xa(%esi)\n"
        "movb %cl, 0xb(%esi)\n"
        "movb %dl, 0xc(%esi)\n"
        "movb %dl, 0xd(%esi)\n"
        "movb %al, 0xe(%esi)\n"
        "movb %al, 0xf(%esi)\n"
        "movl -0x100bc(%ebp), %edx\n" /* line 1068 */
        "movzbl -2(%edx), %ebx\n"
        "movb %bl, 4(%edi)\n"
        "movb %bl, 0x10(%esi)\n"
        "movb %bl, 0x11(%esi)\n"
        "movzbl -1(%edx), %ecx\n"
        "movb %cl, 5(%edi)\n"
        "movb %cl, 0x12(%esi)\n"
        "movb %cl, 0x13(%esi)\n"
        "movl -0x100b8(%ebp), %eax\n"
        "movzbl -2(%eax), %edx\n"
        "movb %dl, 6(%edi)\n"
        "movb %dl, 0x14(%esi)\n"
        "movb %dl, 0x15(%esi)\n"
        "movzbl -1(%eax), %eax\n"
        "movb %al, 7(%edi)\n"
        "addl $8, %edi\n"
        "movb %al, 0x16(%esi)\n"
        "movb %al, 0x17(%esi)\n"
        "movb %bl, 0x18(%esi)\n"
        "movb %bl, 0x19(%esi)\n"
        "movb %cl, 0x1a(%esi)\n"
        "movb %cl, 0x1b(%esi)\n"
        "movb %dl, 0x1c(%esi)\n"
        "movb %dl, 0x1d(%esi)\n"
        "movb %al, 0x1e(%esi)\n"
        "movb %al, 0x1f(%esi)\n"
        "addl $0x20, %esi\n"
        "addl $4, -0x100bc(%ebp)\n"
        "addl $4, -0x100b8(%ebp)\n"
        "subl $1, -0x10124(%ebp)\n" /* line 1065 */
        "je .Lfb3336_000b44aa\n"
        "movl -0x100bc(%ebp), %eax\n"
        "jmp .Lfb3336_000b4517\n"
        ".Lfb3336_000b45eb:\n"
        "movl 0x4f3a18(%edx), %ebx\n" /* line 1772 */
        "testl %ebx, %ebx\n"
        "jne .Lfb3336_000b467c\n"
        "calll RoQShutdown\n" /* line 1778 */
        "movl currentHandle, %edi\n"
        "movl %edi, -0x101fc(%ebp)\n"
        "movl %edi, %edx\n"
        "movl %edi, %ecx\n"
        "jmp .Lfb3336_000b36a3\n"
        ".Lfb3336_000b4613:\n"
        "movl $1, 0x4f3a3c(%edx)\n" /* line 1767 */
        "jmp .Lfb3336_000b368a\n"
        ".Lfb3336_000b4622:\n"
        "calll SND_RawSamplesTime\n" /* line 1730 */
        "movl %eax, %ebx\n"
        "movl currentHandle, %edi\n"
        "movl %edi, -0x101fc(%ebp)\n"
        "leal (%edi, %edi, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "imull 0x4f3abc(%edx, %edi), %ebx\n"
        "movl $0x10624dd3, %edx\n"
        "movl %ebx, %eax\n"
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %ebx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal 1(%edx), %ecx\n"
        "movl %edi, %ebx\n"
        "jmp .Lfb3336_000b34c3\n"
        ".Lfb3336_000b4667:\n"
        "movl $0, 0x4f3a3c(%ebx)\n" /* line 1479 */
        "movl -0x101fc(%ebp), %esi\n"
        "jmp .Lfb3336_000b35dd\n"
        ".Lfb3336_000b467c:\n"
        "calll RoQReset\n" /* line 1774 */
        "movl currentHandle, %esi\n" /* handle */
        "movl %esi, -0x101fc(%ebp)\n" /* handle */
        "movl %esi, %edx\n" /* handle */
        "movl %esi, %ecx\n" /* handle */
        "jmp .Lfb3336_000b36a3\n"
        ".Lfb3336_000b4696:\n"
        "movl $vq2, -0x1008c(%ebp)\n" /* line 1005 */
        "movl -0x1017c(%ebp), %eax\n" /* line 1006 */
        "testl %eax, %eax\n"
        "jg .Lfb3336_000b5ce1\n"
        "movl -0x1012c(%ebp), %ecx\n"
        "movl %ecx, -0x10060(%ebp)\n"
        ".Lfb3336_000b46ba:\n"
        "movl -0x10128(%ebp), %edi\n" /* line 1027 */
        "testl %edi, %edi\n"
        "jle .Lfb3336_000b37c3\n"
        "movl $vq8, -0x100c4(%ebp)\n"
        "movl $vq4, -0x100c0(%ebp)\n"
        "movl $0, -0x10038(%ebp)\n"
        "jmp .Lfb3336_000b4712\n"
        ".Lfb3336_000b46e8:\n"
        "addl $1, -0x10038(%ebp)\n"
        "addl $0x100, -0x100c4(%ebp)\n"
        "addl $0x40, -0x100c0(%ebp)\n"
        "movl -0x10038(%ebp), %edx\n"
        "cmpl %edx, -0x10128(%ebp)\n"
        "je .Lfb3336_000b37c3\n"
        ".Lfb3336_000b4712:\n"
        "movl -0x100c0(%ebp), %edi\n"
        "movl -0x100c4(%ebp), %esi\n"
        "movl -0x10060(%ebp), %eax\n" /* line 1029 */
        "movzbl (%eax), %edx\n"
        "shll $5, %edx\n"
        "movl %eax, %ecx\n" /* line 1030 */
        "movzbl 1(%eax), %eax\n"
        "shll $5, %eax\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x10060(%ebp)\n"
        "addl $0x746ff0, %edx\n"
        "movl %edx, -0x100cc(%ebp)\n"
        "addl $0x746ff0, %eax\n"
        "movl %eax, -0x100c8(%ebp)\n"
        "movl $2, -0x10120(%ebp)\n"
        "movl %edx, %eax\n"
        ".Lfb3336_000b475f:\n"
        "movl -0x10(%eax), %ebx\n" /* line 1033 */
        "movl %ebx, (%edi)\n"
        "movl %ebx, (%esi)\n"
        "movl %ebx, 4(%esi)\n"
        "movl -0xc(%eax), %ecx\n"
        "movl %ecx, 4(%edi)\n"
        "movl %ecx, 8(%esi)\n"
        "movl %ecx, 0xc(%esi)\n"
        "movl -0x100c8(%ebp), %eax\n"
        "movl -0x10(%eax), %edx\n"
        "movl %edx, 8(%edi)\n"
        "movl %edx, 0x10(%esi)\n"
        "movl %edx, 0x14(%esi)\n"
        "movl -0xc(%eax), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        "movl %eax, 0x18(%esi)\n"
        "movl %eax, 0x1c(%esi)\n"
        "movl %ebx, 0x20(%esi)\n"
        "movl %ebx, 0x24(%esi)\n"
        "movl %ecx, 0x28(%esi)\n"
        "movl %ecx, 0x2c(%esi)\n"
        "movl %edx, 0x30(%esi)\n"
        "movl %edx, 0x34(%esi)\n"
        "movl %eax, 0x38(%esi)\n"
        "movl %eax, 0x3c(%esi)\n"
        "movl -0x100cc(%ebp), %edx\n" /* line 1034 */
        "movl -8(%edx), %ebx\n"
        "movl %ebx, 0x10(%edi)\n"
        "movl %ebx, 0x40(%esi)\n"
        "movl %ebx, 0x44(%esi)\n"
        "movl -4(%edx), %ecx\n"
        "movl %ecx, 0x14(%edi)\n"
        "movl %ecx, 0x48(%esi)\n"
        "movl %ecx, 0x4c(%esi)\n"
        "movl -0x100c8(%ebp), %eax\n"
        "movl -8(%eax), %edx\n"
        "movl %edx, 0x18(%edi)\n"
        "movl %edx, 0x50(%esi)\n"
        "movl %edx, 0x54(%esi)\n"
        "movl -4(%eax), %eax\n"
        "movl %eax, 0x1c(%edi)\n"
        "addl $0x20, %edi\n"
        "movl %eax, 0x58(%esi)\n"
        "movl %eax, 0x5c(%esi)\n"
        "movl %ebx, 0x60(%esi)\n"
        "movl %ebx, 0x64(%esi)\n"
        "movl %ecx, 0x68(%esi)\n"
        "movl %ecx, 0x6c(%esi)\n"
        "movl %edx, 0x70(%esi)\n"
        "movl %edx, 0x74(%esi)\n"
        "movl %eax, 0x78(%esi)\n"
        "movl %eax, 0x7c(%esi)\n"
        "subl $-0x80, %esi\n"
        "addl $0x10, -0x100cc(%ebp)\n"
        "addl $0x10, -0x100c8(%ebp)\n"
        "subl $1, -0x10120(%ebp)\n" /* line 1031 */
        "je .Lfb3336_000b46e8\n"
        "movl -0x100cc(%ebp), %eax\n"
        "jmp .Lfb3336_000b475f\n"
        ".Lfb3336_000b482b:\n"
        "calll RoQReset\n" /* line 1470 */
        "movl currentHandle, %esi\n"
        "movl %esi, -0x101fc(%ebp)\n"
        "jmp .Lfb3336_000b35dd\n"
        ".Lfb3336_000b4841:\n"
        "movl $vq2, -0x10174(%ebp)\n" /* line 914 */
        "movl -0x1017c(%ebp), %ebx\n" /* line 915 */
        "testl %ebx, %ebx\n"
        "jg .Lfb3336_000b59f8\n"
        "movl -0x1012c(%ebp), %ecx\n"
        "movl %ecx, -0x10058(%ebp)\n"
        ".Lfb3336_000b4865:\n"
        "movl -0x10128(%ebp), %ecx\n" /* line 932 */
        "testl %ecx, %ecx\n"
        "jle .Lfb3336_000b37c3\n"
        "movl $vq8, -0x100f4(%ebp)\n"
        "movl $vq4, -0x100f0(%ebp)\n"
        "movl $0, -0x1004c(%ebp)\n"
        "jmp .Lfb3336_000b48ba\n"
        ".Lfb3336_000b4893:\n"
        "addl $1, -0x1004c(%ebp)\n"
        "subl $-0x80, -0x100f4(%ebp)\n"
        "addl $0x20, -0x100f0(%ebp)\n"
        "movl -0x1004c(%ebp), %edx\n"
        "cmpl %edx, -0x10128(%ebp)\n"
        "je .Lfb3336_000b37c3\n"
        ".Lfb3336_000b48ba:\n"
        "movl -0x100f0(%ebp), %edi\n"
        "movl -0x100f4(%ebp), %esi\n"
        "movl -0x10058(%ebp), %eax\n" /* line 934 */
        "movzbl (%eax), %edx\n"
        "shll $4, %edx\n"
        "movl %eax, %ecx\n" /* line 935 */
        "movzbl 1(%eax), %eax\n"
        "shll $4, %eax\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x10058(%ebp)\n"
        "addl $0x746fe8, %edx\n"
        "movl %edx, -0x100fc(%ebp)\n"
        "addl $0x746fe8, %eax\n"
        "movl %eax, -0x100f8(%ebp)\n"
        "movl $2, -0x10114(%ebp)\n"
        "movl %edx, %eax\n"
        ".Lfb3336_000b4907:\n"
        "movl -8(%eax), %ebx\n" /* line 937 */
        "movl %ebx, (%edi)\n"
        "movl %ebx, (%esi)\n"
        "movl %ebx, 4(%esi)\n"
        "movl -4(%eax), %ecx\n"
        "movl %ecx, 4(%edi)\n"
        "movl %ecx, 8(%esi)\n"
        "movl %ecx, 0xc(%esi)\n"
        "movl -0x100f8(%ebp), %eax\n"
        "movl -8(%eax), %edx\n"
        "movl %edx, 8(%edi)\n"
        "movl %edx, 0x10(%esi)\n"
        "movl %edx, 0x14(%esi)\n"
        "movl -4(%eax), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        "addl $0x10, %edi\n"
        "movl %eax, 0x18(%esi)\n"
        "movl %eax, 0x1c(%esi)\n"
        "movl %ebx, 0x20(%esi)\n"
        "movl %ebx, 0x24(%esi)\n"
        "movl %ecx, 0x28(%esi)\n"
        "movl %ecx, 0x2c(%esi)\n"
        "movl %edx, 0x30(%esi)\n"
        "movl %edx, 0x34(%esi)\n"
        "movl %eax, 0x38(%esi)\n"
        "movl %eax, 0x3c(%esi)\n"
        "addl $0x40, %esi\n"
        "addl $8, -0x100fc(%ebp)\n"
        "addl $8, -0x100f8(%ebp)\n"
        "subl $1, -0x10114(%ebp)\n" /* line 936 */
        "je .Lfb3336_000b4893\n"
        "movl -0x100fc(%ebp), %eax\n"
        "jmp .Lfb3336_000b4907\n"
        ".Lfb3336_000b497c:\n"
        "movl 0x4f3a98(%edx), %eax\n" /* line 1288 */
        "testl %eax, %eax\n"
        "jne .Lfb3336_000b3c94\n"
        "addl %esi, %esi\n" /* line 1290 */
        "shll -0x10194(%ebp)\n" /* line 1291 */
        "jmp .Lfb3336_000b3c94\n"
        ".Lfb3336_000b4997:\n"
        "movl -0x1017c(%ebp), %eax\n" /* line 1081 */
        "testl %eax, %eax\n"
        "jg .Lfb3336_000b4b99\n"
        "movl -0x1012c(%ebp), %edi\n"
        "movl %edi, -0x1006c(%ebp)\n"
        ".Lfb3336_000b49b1:\n"
        "movl -0x10128(%ebp), %ecx\n" /* line 1096 */
        "testl %ecx, %ecx\n"
        "jle .Lfb3336_000b37c3\n"
        "movl $0, -0x10028(%ebp)\n"
        "movl $vq8, -0x100ac(%ebp)\n"
        "movl $vq4, -0x100a8(%ebp)\n"
        ".Lfb3336_000b49dd:\n"
        "movl -0x100a8(%ebp), %ebx\n"
        "movl -0x100ac(%ebp), %ecx\n"
        "movl -0x1006c(%ebp), %edi\n" /* line 1098 */
        "movzbl (%edi), %eax\n"
        "movzbl 1(%edi), %edx\n" /* line 1099 */
        "addl $2, %edi\n"
        "movl %edi, -0x1006c(%ebp)\n"
        "leal 0x746fe2(, %eax, 4), %edi\n"
        "leal 0x746fe2(, %edx, 4), %esi\n"
        "movl $0, -0x1007c(%ebp)\n"
        ".Lfb3336_000b4a17:\n"
        "movzwl -2(%edi), %edx\n" /* line 1102 */
        "movw %dx, (%ebx)\n"
        "movw %dx, (%ecx)\n"
        "movw %dx, 2(%ecx)\n"
        "movzwl -2(%esi), %eax\n"
        "movw %ax, 2(%ebx)\n"
        "addl $4, %ebx\n"
        "movw %ax, 4(%ecx)\n"
        "movw %ax, 6(%ecx)\n"
        "movw %dx, 8(%ecx)\n"
        "movw %dx, 0xa(%ecx)\n"
        "movw %ax, 0xc(%ecx)\n"
        "movw %ax, 0xe(%ecx)\n"
        "addl $0x10, %ecx\n"
        "addl $1, -0x1007c(%ebp)\n" /* line 1100 */
        "addl $2, %edi\n"
        "addl $2, %esi\n"
        "cmpl $2, -0x1007c(%ebp)\n"
        "jne .Lfb3336_000b4a17\n"
        "addl $1, -0x10028(%ebp)\n" /* line 1096 */
        "addl $0x20, -0x100ac(%ebp)\n"
        "addl $8, -0x100a8(%ebp)\n"
        "movl -0x10028(%ebp), %eax\n"
        "cmpl %eax, -0x10128(%ebp)\n"
        "jne .Lfb3336_000b49dd\n"
        "jmp .Lfb3336_000b37c3\n"
        ".Lfb3336_000b4a8d:\n"
        "movl 0x4f3a98(%edx), %eax\n" /* line 1288 */
        "testl %eax, %eax\n"
        "jne .Lfb3336_000b3e5a\n"
        "addl %esi, %esi\n" /* line 1290 */
        "shll -0x1018c(%ebp)\n" /* line 1291 */
        "jmp .Lfb3336_000b3e5a\n"
        ".Lfb3336_000b4aa8:\n"
        "movl $vq2, %ecx\n" /* line 1108 */
        "movl -0x1017c(%ebp), %edx\n" /* line 1110 */
        "testl %edx, %edx\n"
        "jg .Lfb3336_000b5041\n"
        "movl -0x1012c(%ebp), %edx\n"
        "movl %edx, -0x10074(%ebp)\n"
        ".Lfb3336_000b4ac7:\n"
        "movl -0x10128(%ebp), %edi\n" /* line 1121 */
        "testl %edi, %edi\n"
        "jle .Lfb3336_000b37c3\n"
        "movl $vq8, -0x100a4(%ebp)\n"
        "movl $vq4, -0x100a0(%ebp)\n"
        "movl $0, -0x10024(%ebp)\n"
        ".Lfb3336_000b4af3:\n"
        "movl -0x100a0(%ebp), %ebx\n"
        "movl -0x100a4(%ebp), %ecx\n"
        "movl -0x10074(%ebp), %edi\n" /* line 1123 */
        "movzbl (%edi), %eax\n"
        "movzbl 1(%edi), %edx\n" /* line 1124 */
        "addl $2, %edi\n"
        "movl %edi, -0x10074(%ebp)\n"
        "leal 0x746fe1(%eax, %eax), %edi\n"
        "leal 0x746fe1(%edx, %edx), %esi\n"
        "movl $0, -0x10080(%ebp)\n"
        ".Lfb3336_000b4b2d:\n"
        "movzbl -1(%edi), %edx\n" /* line 1127 */
        "movb %dl, (%ebx)\n"
        "movb %dl, (%ecx)\n"
        "movb %dl, 1(%ecx)\n"
        "movzbl -1(%esi), %eax\n"
        "movb %al, 1(%ebx)\n"
        "addl $2, %ebx\n"
        "movb %al, 2(%ecx)\n"
        "movb %al, 3(%ecx)\n"
        "movb %dl, 4(%ecx)\n"
        "movb %dl, 5(%ecx)\n"
        "movb %al, 6(%ecx)\n"
        "movb %al, 7(%ecx)\n"
        "addl $8, %ecx\n"
        "addl $1, -0x10080(%ebp)\n" /* line 1125 */
        "addl $1, %edi\n"
        "addl $1, %esi\n"
        "cmpl $2, -0x10080(%ebp)\n"
        "jne .Lfb3336_000b4b2d\n"
        "addl $1, -0x10024(%ebp)\n" /* line 1121 */
        "addl $0x10, -0x100a4(%ebp)\n"
        "addl $4, -0x100a0(%ebp)\n"
        "movl -0x10024(%ebp), %eax\n"
        "cmpl %eax, -0x10128(%ebp)\n"
        "jne .Lfb3336_000b4af3\n"
        "jmp .Lfb3336_000b37c3\n"
        ".Lfb3336_000b4b99:\n"
        "movl -0x1012c(%ebp), %ecx\n" /* line 1079 */
        "movl %ecx, -0x1006c(%ebp)\n"
        "movl $vq2, -0x10090(%ebp)\n"
        "movl $0, -0x1002c(%ebp)\n"
        "movl %ecx, %ebx\n"
        "jmp .Lfb3336_000b4c86\n"
        ".Lfb3336_000b4bc0:\n"
        "movl $0xf800, %ebx\n" /* line 765 */
        "cmpl $0x3f, %edx\n" /* line 767 */
        "jle .Lfb3336_000b4d10\n"
        ".Lfb3336_000b4bce:\n"
        "movl $0x7e0, %edx\n"
        ".Lfb3336_000b4bd3:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %ecx\n"
        "cmovll %ecx, %eax\n"
        "leal (%ebx, %edx), %edx\n" /* line 1089 */
        "addl %edx, %eax\n"
        "movl -0x10090(%ebp), %edx\n"
        "movw %ax, (%edx)\n"
        "movl -0x10138(%ebp), %ecx\n" /* line 753 */
        "movl ROQ_YY_tab(, %ecx, 4), %edx\n"
        "movl -0x101e8(%ebp), %esi\n" /* line 755 */
        "leal (%edx, %esi), %ebx\n"
        "movl -0x101c0(%ebp), %ecx\n" /* line 756 */
        "leal (%edx, %ecx), %eax\n"
        "addl -0x101b8(%ebp), %eax\n"
        "addl %edi, %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "movl %edx, %esi\n" /* line 763 */
        "sarl $9, %esi\n"
        "cmovsl %ecx, %esi\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b4d20\n"
        "movw $0xf800, %cx\n"
        ".Lfb3336_000b4c36:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b4d18\n"
        "movl $0x7e0, %eax\n"
        ".Lfb3336_000b4c44:\n"
        "movl $0x1f, %edx\n" /* line 769 */
        "cmpl $0x20, %esi\n"
        "cmovll %esi, %edx\n"
        "leal (%ecx, %eax), %eax\n" /* line 1090 */
        "addl %edx, %eax\n"
        "movl -0x10090(%ebp), %ebx\n"
        "movw %ax, 2(%ebx)\n"
        "addl $4, %ebx\n"
        "movl %ebx, -0x10090(%ebp)\n"
        "addl $1, -0x1002c(%ebp)\n" /* line 1081 */
        "movl -0x1002c(%ebp), %esi\n"
        "cmpl %esi, -0x1017c(%ebp)\n"
        "je .Lfb3336_000b49b1\n"
        "movl -0x1006c(%ebp), %ebx\n"
        ".Lfb3336_000b4c86:\n"
        "movzbl (%ebx), %eax\n" /* line 1083 */
        "movzbl 2(%ebx), %esi\n" /* line 1085 */
        "movl %esi, -0x10138(%ebp)\n"
        "movzbl 4(%ebx), %edi\n" /* line 1087 */
        "movl %ebx, %edx\n" /* line 1088 */
        "movzbl 5(%ebx), %ebx\n"
        "addl $6, %edx\n"
        "movl %edx, -0x1006c(%ebp)\n"
        "movl ROQ_YY_tab(, %eax, 4), %ecx\n" /* line 753 */
        "movl ROQ_VR_tab(, %ebx, 4), %esi\n" /* line 755 */
        "movl %esi, -0x101e8(%ebp)\n"
        "leal (%ecx, %esi), %esi\n"
        "movl ROQ_UG_tab(, %edi, 4), %edx\n" /* line 756 */
        "movl %edx, -0x101c0(%ebp)\n"
        "leal (%ecx, %edx), %edx\n"
        "movl ROQ_VG_tab(, %ebx, 4), %ebx\n"
        "movl %ebx, -0x101b8(%ebp)\n"
        "addl %ebx, %edx\n"
        "movl ROQ_UB_tab(, %edi, 4), %edi\n" /* line 757 */
        "addl %edi, %ecx\n"
        "xorl %eax, %eax\n" /* line 759 */
        "movl %esi, %ebx\n"
        "sarl $9, %ebx\n"
        "cmovsl %eax, %ebx\n"
        "sarl $8, %edx\n" /* line 761 */
        "cmovsl %eax, %edx\n"
        "sarl $9, %ecx\n" /* line 763 */
        "cmovsl %eax, %ecx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jg .Lfb3336_000b4bc0\n"
        "shll $0xb, %ebx\n"
        "cmpl $0x3f, %edx\n" /* line 767 */
        "jg .Lfb3336_000b4bce\n"
        ".Lfb3336_000b4d10:\n"
        "shll $5, %edx\n"
        "jmp .Lfb3336_000b4bd3\n"
        ".Lfb3336_000b4d18:\n"
        "shll $5, %eax\n"
        "jmp .Lfb3336_000b4c44\n"
        ".Lfb3336_000b4d20:\n"
        "movl %ebx, %ecx\n" /* line 765 */
        "shll $0xb, %ecx\n"
        "jmp .Lfb3336_000b4c36\n"
        ".Lfb3336_000b4d2a:\n"
        "movl -0x1017c(%ebp), %eax\n" /* line 887 */
        "testl %eax, %eax\n"
        "jg .Lfb3336_000b508b\n"
        "movl -0x1012c(%ebp), %edx\n"
        "movl %edx, -0x10064(%ebp)\n"
        ".Lfb3336_000b4d44:\n"
        "movl -0x10128(%ebp), %esi\n" /* line 904 */
        "testl %esi, %esi\n"
        "jle .Lfb3336_000b37c3\n"
        "movl $0, -0x10054(%ebp)\n"
        "movl $vq8, -0x10104(%ebp)\n"
        "movl $vq4, -0x10100(%ebp)\n"
        "jmp .Lfb3336_000b4d99\n"
        ".Lfb3336_000b4d72:\n"
        "addl $1, -0x10054(%ebp)\n"
        "addl $0x40, -0x10104(%ebp)\n"
        "addl $0x10, -0x10100(%ebp)\n"
        "movl -0x10054(%ebp), %edx\n"
        "cmpl %edx, -0x10128(%ebp)\n"
        "je .Lfb3336_000b37c3\n"
        ".Lfb3336_000b4d99:\n"
        "movl -0x10100(%ebp), %edi\n"
        "movl -0x10104(%ebp), %esi\n"
        "movl -0x10064(%ebp), %edx\n" /* line 906 */
        "movzbl (%edx), %eax\n"
        "movl %edx, %ecx\n" /* line 907 */
        "movzbl 1(%edx), %edx\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x10064(%ebp)\n"
        "leal 0x746fe4(, %eax, 8), %eax\n"
        "movl %eax, -0x1010c(%ebp)\n"
        "leal 0x746fe4(, %edx, 8), %edx\n"
        "movl %edx, -0x10108(%ebp)\n"
        "movl $2, -0x10110(%ebp)\n"
        ".Lfb3336_000b4de1:\n"
        "movzwl -4(%eax), %ebx\n" /* line 909 */
        "movw %bx, (%edi)\n"
        "movw %bx, (%esi)\n"
        "movw %bx, 2(%esi)\n"
        "movzwl -2(%eax), %ecx\n"
        "movw %cx, 2(%edi)\n"
        "movw %cx, 4(%esi)\n"
        "movw %cx, 6(%esi)\n"
        "movl -0x10108(%ebp), %eax\n"
        "movzwl -4(%eax), %edx\n"
        "movw %dx, 4(%edi)\n"
        "movw %dx, 8(%esi)\n"
        "movw %dx, 0xa(%esi)\n"
        "movzwl -2(%eax), %eax\n"
        "movw %ax, 6(%edi)\n"
        "addl $8, %edi\n"
        "movw %ax, 0xc(%esi)\n"
        "movw %ax, 0xe(%esi)\n"
        "movw %bx, 0x10(%esi)\n"
        "movw %bx, 0x12(%esi)\n"
        "movw %cx, 0x14(%esi)\n"
        "movw %cx, 0x16(%esi)\n"
        "movw %dx, 0x18(%esi)\n"
        "movw %dx, 0x1a(%esi)\n"
        "movw %ax, 0x1c(%esi)\n"
        "movw %ax, 0x1e(%esi)\n"
        "addl $0x20, %esi\n"
        "addl $4, -0x1010c(%ebp)\n"
        "addl $4, -0x10108(%ebp)\n"
        "subl $1, -0x10110(%ebp)\n" /* line 908 */
        "je .Lfb3336_000b4d72\n"
        "movl -0x1010c(%ebp), %eax\n"
        "jmp .Lfb3336_000b4de1\n"
        ".Lfb3336_000b4e71:\n"
        "movl -0x1017c(%ebp), %eax\n" /* line 971 */
        "testl %eax, %eax\n"
        "jg .Lfb3336_000b5331\n"
        "movl -0x1012c(%ebp), %eax\n"
        "movl %eax, -0x10078(%ebp)\n"
        ".Lfb3336_000b4e8b:\n"
        "movl -0x10128(%ebp), %eax\n" /* line 992 */
        "testl %eax, %eax\n"
        "jle .Lfb3336_000b37c3\n"
        "movl $0, -0x10040(%ebp)\n"
        "movl $vq8, -0x100d4(%ebp)\n"
        "movl $vq4, -0x100d0(%ebp)\n"
        "jmp .Lfb3336_000b4ee0\n"
        ".Lfb3336_000b4eb9:\n"
        "addl $1, -0x10040(%ebp)\n"
        "subl $-0x80, -0x100d4(%ebp)\n"
        "addl $0x20, -0x100d0(%ebp)\n"
        "movl -0x10040(%ebp), %edx\n"
        "cmpl %edx, -0x10128(%ebp)\n"
        "je .Lfb3336_000b37c3\n"
        ".Lfb3336_000b4ee0:\n"
        "movl -0x100d0(%ebp), %edi\n"
        "movl -0x100d4(%ebp), %esi\n"
        "movl -0x10078(%ebp), %eax\n" /* line 994 */
        "movzbl (%eax), %edx\n"
        "shll $4, %edx\n"
        "movl %eax, %ecx\n" /* line 995 */
        "movzbl 1(%eax), %eax\n"
        "shll $4, %eax\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x10078(%ebp)\n"
        "addl $0x746fe8, %edx\n"
        "movl %edx, -0x100dc(%ebp)\n"
        "addl $0x746fe8, %eax\n"
        "movl %eax, -0x100d8(%ebp)\n"
        "movl $2, -0x1011c(%ebp)\n"
        "movl %edx, %eax\n"
        ".Lfb3336_000b4f2d:\n"
        "movzwl -8(%eax), %ebx\n" /* line 998 */
        "movw %bx, (%edi)\n"
        "movw %bx, (%esi)\n"
        "movw %bx, 2(%esi)\n"
        "movzwl -6(%eax), %ecx\n"
        "movw %cx, 2(%edi)\n"
        "movw %cx, 4(%esi)\n"
        "movw %cx, 6(%esi)\n"
        "movl -0x100d8(%ebp), %eax\n"
        "movzwl -8(%eax), %edx\n"
        "movw %dx, 4(%edi)\n"
        "movw %dx, 8(%esi)\n"
        "movw %dx, 0xa(%esi)\n"
        "movzwl -6(%eax), %eax\n"
        "movw %ax, 6(%edi)\n"
        "movw %ax, 0xc(%esi)\n"
        "movw %ax, 0xe(%esi)\n"
        "movw %bx, 0x10(%esi)\n"
        "movw %bx, 0x12(%esi)\n"
        "movw %cx, 0x14(%esi)\n"
        "movw %cx, 0x16(%esi)\n"
        "movw %dx, 0x18(%esi)\n"
        "movw %dx, 0x1a(%esi)\n"
        "movw %ax, 0x1c(%esi)\n"
        "movw %ax, 0x1e(%esi)\n"
        "movl -0x100dc(%ebp), %edx\n" /* line 999 */
        "movzwl -4(%edx), %ebx\n"
        "movw %bx, 8(%edi)\n"
        "movw %bx, 0x20(%esi)\n"
        "movw %bx, 0x22(%esi)\n"
        "movzwl -2(%edx), %ecx\n"
        "movw %cx, 0xa(%edi)\n"
        "movw %cx, 0x24(%esi)\n"
        "movw %cx, 0x26(%esi)\n"
        "movl -0x100d8(%ebp), %eax\n"
        "movzwl -4(%eax), %edx\n"
        "movw %dx, 0xc(%edi)\n"
        "movw %dx, 0x28(%esi)\n"
        "movw %dx, 0x2a(%esi)\n"
        "movzwl -2(%eax), %eax\n"
        "movw %ax, 0xe(%edi)\n"
        "addl $0x10, %edi\n"
        "movw %ax, 0x2c(%esi)\n"
        "movw %ax, 0x2e(%esi)\n"
        "movw %bx, 0x30(%esi)\n"
        "movw %bx, 0x32(%esi)\n"
        "movw %cx, 0x34(%esi)\n"
        "movw %cx, 0x36(%esi)\n"
        "movw %dx, 0x38(%esi)\n"
        "movw %dx, 0x3a(%esi)\n"
        "movw %ax, 0x3c(%esi)\n"
        "movw %ax, 0x3e(%esi)\n"
        "addl $0x40, %esi\n"
        "addl $8, -0x100dc(%ebp)\n"
        "addl $8, -0x100d8(%ebp)\n"
        "subl $1, -0x1011c(%ebp)\n" /* line 996 */
        "je .Lfb3336_000b4eb9\n"
        "movl -0x100dc(%ebp), %eax\n"
        "jmp .Lfb3336_000b4f2d\n"
        ".Lfb3336_000b5029:\n"
        "movl %ecx, %eax\n" /* line 1722 */
        "shrl $1, %eax\n"
        "movl %ecx, %edx\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfb3336_000b344d\n"
        ".Lfb3336_000b5041:\n"
        "movl -0x1012c(%ebp), %ebx\n" /* line 1110 */
        "movl %ebx, -0x10074(%ebp)\n"
        "xorl %edx, %edx\n"
        "movl 0x4f3a84(%eax), %ebx\n"
        "movl -0x10074(%ebp), %esi\n"
        ".Lfb3336_000b505b:\n"
        "movzbl (%esi), %eax\n" /* line 1112 */
        "movzbl (%ebx, %eax), %eax\n"
        "movb %al, (%ecx)\n"
        "movzbl 2(%esi), %eax\n" /* line 1114 */
        "movzbl (%ebx, %eax), %eax\n"
        "movb %al, 1(%ecx)\n"
        "addl $2, %ecx\n"
        "addl $6, %esi\n" /* line 1115 */
        "movl %esi, -0x10074(%ebp)\n"
        "addl $1, %edx\n" /* line 1110 */
        "cmpl %edx, -0x1017c(%ebp)\n"
        "jne .Lfb3336_000b505b\n"
        "jmp .Lfb3336_000b4ac7\n"
        ".Lfb3336_000b508b:\n"
        "movl -0x1012c(%ebp), %edi\n" /* line 885 */
        "movl %edi, -0x10064(%ebp)\n"
        "movl $vq2, -0x10178(%ebp)\n"
        "movl $0, -0x10184(%ebp)\n"
        "movl %edi, %eax\n"
        "jmp .Lfb3336_000b5259\n"
        ".Lfb3336_000b50b2:\n"
        "movl $0xf800, %ebx\n" /* line 765 */
        ".Lfb3336_000b50b7:\n"
        "cmpl $0x3f, %edx\n" /* line 767 */
        "jle .Lfb3336_000b5329\n"
        "movl $0x7e0, %edx\n"
        ".Lfb3336_000b50c5:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %ecx\n"
        "cmovll %ecx, %eax\n"
        "leal (%ebx, %edx), %edx\n" /* line 895 */
        "addl %edx, %eax\n"
        "movl -0x10178(%ebp), %edx\n"
        "movw %ax, (%edx)\n"
        "movl -0x10170(%ebp), %ecx\n" /* line 753 */
        "movl ROQ_YY_tab(, %ecx, 4), %edx\n"
        "movl -0x101f8(%ebp), %esi\n" /* line 755 */
        "leal (%edx, %esi), %ebx\n"
        "movl -0x101d8(%ebp), %ecx\n" /* line 756 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101e0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "sarl $9, %edx\n" /* line 763 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b5321\n"
        "movl $0xf800, %ebx\n"
        ".Lfb3336_000b5127:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b5317\n"
        "movl $0x7e0, %ecx\n"
        ".Lfb3336_000b5135:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %edx\n"
        "cmovll %edx, %eax\n"
        "leal (%ebx, %ecx), %edx\n" /* line 896 */
        "addl %edx, %eax\n"
        "movl -0x10178(%ebp), %ebx\n"
        "movw %ax, 2(%ebx)\n"
        "movl -0x1016c(%ebp), %esi\n" /* line 753 */
        "movl ROQ_YY_tab(, %esi, 4), %edx\n"
        "movl -0x101f8(%ebp), %eax\n" /* line 755 */
        "leal (%edx, %eax), %ebx\n"
        "movl -0x101d8(%ebp), %ecx\n" /* line 756 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101e0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "sarl $9, %edx\n" /* line 763 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b530f\n"
        "movl $0xf800, %ebx\n"
        ".Lfb3336_000b5198:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b5305\n"
        "movl $0x7e0, %ecx\n"
        ".Lfb3336_000b51a6:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %edx\n"
        "cmovll %edx, %eax\n"
        "leal (%ebx, %ecx), %edx\n" /* line 897 */
        "addl %edx, %eax\n"
        "movl -0x10178(%ebp), %ebx\n"
        "movw %ax, 4(%ebx)\n"
        "movl -0x10168(%ebp), %esi\n" /* line 753 */
        "movl ROQ_YY_tab(, %esi, 4), %edx\n"
        "movl -0x101f8(%ebp), %eax\n" /* line 755 */
        "leal (%edx, %eax), %ebx\n"
        "movl -0x101d8(%ebp), %ecx\n" /* line 756 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101e0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "sarl $9, %edx\n" /* line 763 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b52fd\n"
        "movl $0xf800, %ebx\n"
        ".Lfb3336_000b5209:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b52f3\n"
        "movl $0x7e0, %ecx\n"
        ".Lfb3336_000b5217:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %edx\n"
        "cmovll %edx, %eax\n"
        "leal (%ebx, %ecx), %edx\n" /* line 898 */
        "addl %edx, %eax\n"
        "movl -0x10178(%ebp), %ebx\n"
        "movw %ax, 6(%ebx)\n"
        "addl $8, %ebx\n"
        "movl %ebx, -0x10178(%ebp)\n"
        "addl $1, -0x10184(%ebp)\n" /* line 887 */
        "movl -0x10184(%ebp), %esi\n"
        "cmpl %esi, -0x1017c(%ebp)\n"
        "je .Lfb3336_000b4d44\n"
        "movl -0x10064(%ebp), %eax\n"
        ".Lfb3336_000b5259:\n"
        "movzbl (%eax), %edx\n" /* line 889 */
        "movzbl 1(%eax), %ecx\n" /* line 890 */
        "movl %ecx, -0x10170(%ebp)\n"
        "movzbl 2(%eax), %ebx\n" /* line 891 */
        "movl %ebx, -0x1016c(%ebp)\n"
        "movzbl 3(%eax), %esi\n" /* line 892 */
        "movl %esi, -0x10168(%ebp)\n"
        "movzbl 4(%eax), %ebx\n" /* line 893 */
        "movl %eax, %edi\n" /* line 894 */
        "movzbl 5(%eax), %eax\n"
        "addl $6, %edi\n"
        "movl %edi, -0x10064(%ebp)\n"
        "movl ROQ_YY_tab(, %edx, 4), %ecx\n" /* line 753 */
        "movl ROQ_VR_tab(, %eax, 4), %edx\n" /* line 755 */
        "movl %edx, -0x101f8(%ebp)\n"
        "leal (%ecx, %edx), %esi\n"
        "movl ROQ_UG_tab(, %ebx, 4), %edi\n" /* line 756 */
        "movl %edi, -0x101d8(%ebp)\n"
        "leal (%ecx, %edi), %edx\n"
        "movl ROQ_VG_tab(, %eax, 4), %edi\n"
        "addl %edi, %edx\n"
        "movl ROQ_UB_tab(, %ebx, 4), %ebx\n" /* line 757 */
        "movl %ebx, -0x101e0(%ebp)\n"
        "addl %ebx, %ecx\n"
        "xorl %eax, %eax\n" /* line 759 */
        "movl %esi, %ebx\n"
        "sarl $9, %ebx\n"
        "cmovsl %eax, %ebx\n"
        "sarl $8, %edx\n" /* line 761 */
        "cmovsl %eax, %edx\n"
        "sarl $9, %ecx\n" /* line 763 */
        "cmovsl %eax, %ecx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jg .Lfb3336_000b50b2\n"
        "shll $0xb, %ebx\n"
        "jmp .Lfb3336_000b50b7\n"
        ".Lfb3336_000b52f3:\n"
        "movl %eax, %ecx\n" /* line 767 */
        "shll $5, %ecx\n"
        "jmp .Lfb3336_000b5217\n"
        ".Lfb3336_000b52fd:\n"
        "shll $0xb, %ebx\n" /* line 765 */
        "jmp .Lfb3336_000b5209\n"
        ".Lfb3336_000b5305:\n"
        "movl %eax, %ecx\n" /* line 767 */
        "shll $5, %ecx\n"
        "jmp .Lfb3336_000b51a6\n"
        ".Lfb3336_000b530f:\n"
        "shll $0xb, %ebx\n" /* line 765 */
        "jmp .Lfb3336_000b5198\n"
        ".Lfb3336_000b5317:\n"
        "movl %eax, %ecx\n" /* line 767 */
        "shll $5, %ecx\n"
        "jmp .Lfb3336_000b5135\n"
        ".Lfb3336_000b5321:\n"
        "shll $0xb, %ebx\n" /* line 765 */
        "jmp .Lfb3336_000b5127\n"
        ".Lfb3336_000b5329:\n"
        "shll $5, %edx\n" /* line 767 */
        "jmp .Lfb3336_000b50c5\n"
        ".Lfb3336_000b5331:\n"
        "movl -0x1012c(%ebp), %ecx\n" /* line 969 */
        "movl %ecx, -0x10078(%ebp)\n"
        "movl $vq2, -0x10094(%ebp)\n"
        "movl $0, -0x10044(%ebp)\n"
        "movl %ecx, %ebx\n"
        "movl %ecx, %esi\n"
        "movl %ecx, %edi\n"
        "movl %ecx, %eax\n"
        "movl %ecx, %edx\n"
        "jmp .Lfb3336_000b5721\n"
        ".Lfb3336_000b5360:\n"
        "movl $0xf800, %ebx\n" /* line 765 */
        ".Lfb3336_000b5365:\n"
        "cmpl $0x3f, %edx\n" /* line 767 */
        "jle .Lfb3336_000b5843\n"
        "movl $0x7e0, %eax\n"
        ".Lfb3336_000b5373:\n"
        "movl $0x1f, %edx\n" /* line 769 */
        "cmpl $0x20, %ecx\n"
        "cmovll %ecx, %edx\n"
        "leal (%ebx, %eax), %eax\n" /* line 979 */
        "addl %edx, %eax\n"
        "movl -0x10094(%ebp), %edx\n"
        "movw %ax, (%edx)\n"
        "movl -0x10154(%ebp), %ecx\n" /* line 753 */
        "movl ROQ_YY_tab(, %ecx, 4), %edx\n"
        "movl -0x101f0(%ebp), %esi\n" /* line 755 */
        "leal (%edx, %esi), %ebx\n"
        "movl -0x101cc(%ebp), %ecx\n" /* line 756 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101d0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "movl %edx, %esi\n" /* line 763 */
        "sarl $9, %esi\n"
        "cmovsl %ecx, %esi\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b5839\n"
        "movw $0xf800, %cx\n"
        ".Lfb3336_000b53d6:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b5831\n"
        "movl $0x7e0, %eax\n"
        ".Lfb3336_000b53e4:\n"
        "movl $0x1f, %edx\n" /* line 769 */
        "cmpl $0x20, %esi\n"
        "cmovll %esi, %edx\n"
        "leal (%ecx, %eax), %eax\n" /* line 980 */
        "addl %edx, %eax\n"
        "movl -0x10094(%ebp), %ebx\n"
        "movw %ax, 2(%ebx)\n"
        "movl -0x10158(%ebp), %esi\n" /* line 753 */
        "leal (%esi, %esi, 2), %eax\n"
        "movl -0x10150(%ebp), %edx\n"
        "leal (%edx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movl ROQ_YY_tab(, %eax, 4), %edx\n"
        "movl -0x101f0(%ebp), %ecx\n" /* line 755 */
        "leal (%edx, %ecx), %ebx\n"
        "movl -0x101cc(%ebp), %esi\n" /* line 756 */
        "leal (%edx, %esi), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101d0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "movl %edx, %esi\n" /* line 763 */
        "sarl $9, %esi\n"
        "cmovsl %ecx, %esi\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b5827\n"
        "movw $0xf800, %cx\n"
        ".Lfb3336_000b5457:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b581f\n"
        "movl $0x7e0, %eax\n"
        ".Lfb3336_000b5465:\n"
        "movl $0x1f, %edx\n" /* line 769 */
        "cmpl $0x20, %esi\n"
        "cmovll %esi, %edx\n"
        "leal (%ecx, %eax), %eax\n" /* line 981 */
        "addl %edx, %eax\n"
        "movl -0x10094(%ebp), %edx\n"
        "movw %ax, 4(%edx)\n"
        "movl -0x10154(%ebp), %ecx\n" /* line 753 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl -0x1014c(%ebp), %ebx\n"
        "leal (%ebx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movl ROQ_YY_tab(, %eax, 4), %edx\n"
        "movl -0x101f0(%ebp), %esi\n" /* line 755 */
        "leal (%edx, %esi), %ebx\n"
        "movl -0x101cc(%ebp), %ecx\n" /* line 756 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101d0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "sarl $9, %edx\n" /* line 763 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b5817\n"
        "movl $0xf800, %ebx\n"
        ".Lfb3336_000b54d7:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b580d\n"
        "movl $0x7e0, %ecx\n"
        ".Lfb3336_000b54e5:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %edx\n"
        "cmovll %edx, %eax\n"
        "leal (%ebx, %ecx), %edx\n" /* line 982 */
        "addl %edx, %eax\n"
        "movl -0x10094(%ebp), %ebx\n"
        "movw %ax, 6(%ebx)\n"
        "movl -0x10150(%ebp), %esi\n" /* line 753 */
        "leal (%esi, %esi, 2), %eax\n"
        "movl -0x10158(%ebp), %edx\n"
        "leal (%edx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movl ROQ_YY_tab(, %eax, 4), %edx\n"
        "movl -0x101f0(%ebp), %ecx\n" /* line 755 */
        "leal (%edx, %ecx), %ebx\n"
        "movl -0x101cc(%ebp), %esi\n" /* line 756 */
        "leal (%edx, %esi), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101d0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "sarl $9, %edx\n" /* line 763 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b5805\n"
        "movl $0xf800, %ebx\n"
        ".Lfb3336_000b5557:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b57fb\n"
        "movl $0x7e0, %ecx\n"
        ".Lfb3336_000b5565:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %edx\n"
        "cmovll %edx, %eax\n"
        "leal (%ebx, %ecx), %edx\n" /* line 983 */
        "addl %edx, %eax\n"
        "movl -0x10094(%ebp), %edx\n"
        "movw %ax, 8(%edx)\n"
        "movl -0x1014c(%ebp), %ecx\n" /* line 753 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl -0x10154(%ebp), %ebx\n"
        "leal (%ebx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movl ROQ_YY_tab(, %eax, 4), %edx\n"
        "movl -0x101f0(%ebp), %esi\n" /* line 755 */
        "leal (%edx, %esi), %ebx\n"
        "movl -0x101cc(%ebp), %ecx\n" /* line 756 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101d0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "sarl $9, %edx\n" /* line 763 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b57f3\n"
        "movl $0xf800, %ebx\n"
        ".Lfb3336_000b55d7:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b57e9\n"
        "movl $0x7e0, %ecx\n"
        ".Lfb3336_000b55e5:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %edx\n"
        "cmovll %edx, %eax\n"
        "leal (%ebx, %ecx), %edx\n" /* line 984 */
        "addl %edx, %eax\n"
        "movl -0x10094(%ebp), %ebx\n"
        "movw %ax, 0xa(%ebx)\n"
        "movl -0x10150(%ebp), %esi\n" /* line 753 */
        "movl ROQ_YY_tab(, %esi, 4), %edx\n"
        "movl -0x101f0(%ebp), %eax\n" /* line 755 */
        "leal (%edx, %eax), %ebx\n"
        "movl -0x101cc(%ebp), %ecx\n" /* line 756 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101d0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "sarl $9, %edx\n" /* line 763 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b57e1\n"
        "movl $0xf800, %ebx\n"
        ".Lfb3336_000b5648:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b57d7\n"
        "movl $0x7e0, %ecx\n"
        ".Lfb3336_000b5656:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %edx\n"
        "cmovll %edx, %eax\n"
        "leal (%ebx, %ecx), %edx\n" /* line 985 */
        "addl %edx, %eax\n"
        "movl -0x10094(%ebp), %ebx\n"
        "movw %ax, 0xc(%ebx)\n"
        "movl -0x1014c(%ebp), %esi\n" /* line 753 */
        "movl ROQ_YY_tab(, %esi, 4), %edx\n"
        "movl -0x101f0(%ebp), %eax\n" /* line 755 */
        "leal (%edx, %eax), %ebx\n"
        "movl -0x101cc(%ebp), %ecx\n" /* line 756 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101d0(%ebp), %edx\n" /* line 757 */
        "xorl %ecx, %ecx\n" /* line 759 */
        "sarl $9, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $8, %eax\n" /* line 761 */
        "cmovsl %ecx, %eax\n"
        "sarl $9, %edx\n" /* line 763 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jle .Lfb3336_000b57cf\n"
        "movl $0xf800, %ebx\n"
        ".Lfb3336_000b56b9:\n"
        "cmpl $0x3f, %eax\n" /* line 767 */
        "jle .Lfb3336_000b57c5\n"
        "movl $0x7e0, %ecx\n"
        ".Lfb3336_000b56c7:\n"
        "movl $0x1f, %eax\n" /* line 769 */
        "cmpl $0x20, %edx\n"
        "cmovll %edx, %eax\n"
        "leal (%ebx, %ecx), %edx\n" /* line 986 */
        "addl %edx, %eax\n"
        "movl -0x10094(%ebp), %ebx\n"
        "movw %ax, 0xe(%ebx)\n"
        "addl $0x10, %ebx\n"
        "movl %ebx, -0x10094(%ebp)\n"
        "addl $1, -0x10044(%ebp)\n" /* line 971 */
        "movl -0x10044(%ebp), %esi\n"
        "cmpl %esi, -0x1017c(%ebp)\n"
        "je .Lfb3336_000b4e8b\n"
        "movl -0x10078(%ebp), %ebx\n"
        "movl -0x10078(%ebp), %esi\n"
        "movl -0x10078(%ebp), %edi\n"
        "movl -0x10078(%ebp), %eax\n"
        "movl -0x10078(%ebp), %edx\n"
        ".Lfb3336_000b5721:\n"
        "movzbl (%ebx), %ebx\n" /* line 973 */
        "movl %ebx, -0x10158(%ebp)\n"
        "movzbl 1(%esi), %esi\n" /* line 974 */
        "movl %esi, -0x10154(%ebp)\n"
        "movzbl 2(%edi), %edi\n" /* line 975 */
        "movl %edi, -0x10150(%ebp)\n"
        "movzbl 3(%eax), %eax\n" /* line 976 */
        "movl %eax, -0x1014c(%ebp)\n"
        "movzbl 4(%edx), %ebx\n" /* line 977 */
        "movzbl 5(%edx), %eax\n" /* line 978 */
        "addl $6, %edx\n"
        "movl %edx, -0x10078(%ebp)\n"
        "movl -0x10158(%ebp), %esi\n" /* line 753 */
        "movl ROQ_YY_tab(, %esi, 4), %ecx\n"
        "movl ROQ_VR_tab(, %eax, 4), %edi\n" /* line 755 */
        "movl %edi, -0x101f0(%ebp)\n"
        "leal (%ecx, %edi), %esi\n"
        "movl ROQ_UG_tab(, %ebx, 4), %edx\n" /* line 756 */
        "movl %edx, -0x101cc(%ebp)\n"
        "leal (%ecx, %edx), %edx\n"
        "movl ROQ_VG_tab(, %eax, 4), %edi\n"
        "addl %edi, %edx\n"
        "movl ROQ_UB_tab(, %ebx, 4), %ebx\n" /* line 757 */
        "movl %ebx, -0x101d0(%ebp)\n"
        "addl %ebx, %ecx\n"
        "xorl %eax, %eax\n" /* line 759 */
        "movl %esi, %ebx\n"
        "sarl $9, %ebx\n"
        "cmovsl %eax, %ebx\n"
        "sarl $8, %edx\n" /* line 761 */
        "cmovsl %eax, %edx\n"
        "sarl $9, %ecx\n" /* line 763 */
        "cmovsl %eax, %ecx\n"
        "cmpl $0x1f, %ebx\n" /* line 765 */
        "jg .Lfb3336_000b5360\n"
        "shll $0xb, %ebx\n"
        "jmp .Lfb3336_000b5365\n"
        ".Lfb3336_000b57c5:\n"
        "movl %eax, %ecx\n" /* line 767 */
        "shll $5, %ecx\n"
        "jmp .Lfb3336_000b56c7\n"
        ".Lfb3336_000b57cf:\n"
        "shll $0xb, %ebx\n" /* line 765 */
        "jmp .Lfb3336_000b56b9\n"
        ".Lfb3336_000b57d7:\n"
        "movl %eax, %ecx\n" /* line 767 */
        "shll $5, %ecx\n"
        "jmp .Lfb3336_000b5656\n"
        ".Lfb3336_000b57e1:\n"
        "shll $0xb, %ebx\n" /* line 765 */
        "jmp .Lfb3336_000b5648\n"
        ".Lfb3336_000b57e9:\n"
        "movl %eax, %ecx\n" /* line 767 */
        "shll $5, %ecx\n"
        "jmp .Lfb3336_000b55e5\n"
        ".Lfb3336_000b57f3:\n"
        "shll $0xb, %ebx\n" /* line 765 */
        "jmp .Lfb3336_000b55d7\n"
        ".Lfb3336_000b57fb:\n"
        "movl %eax, %ecx\n" /* line 767 */
        "shll $5, %ecx\n"
        "jmp .Lfb3336_000b5565\n"
        ".Lfb3336_000b5805:\n"
        "shll $0xb, %ebx\n" /* line 765 */
        "jmp .Lfb3336_000b5557\n"
        ".Lfb3336_000b580d:\n"
        "movl %eax, %ecx\n" /* line 767 */
        "shll $5, %ecx\n"
        "jmp .Lfb3336_000b54e5\n"
        ".Lfb3336_000b5817:\n"
        "shll $0xb, %ebx\n" /* line 765 */
        "jmp .Lfb3336_000b54d7\n"
        ".Lfb3336_000b581f:\n"
        "shll $5, %eax\n" /* line 767 */
        "jmp .Lfb3336_000b5465\n"
        ".Lfb3336_000b5827:\n"
        "movl %ebx, %ecx\n" /* line 765 */
        "shll $0xb, %ecx\n"
        "jmp .Lfb3336_000b5457\n"
        ".Lfb3336_000b5831:\n"
        "shll $5, %eax\n" /* line 767 */
        "jmp .Lfb3336_000b53e4\n"
        ".Lfb3336_000b5839:\n"
        "movl %ebx, %ecx\n" /* line 765 */
        "shll $0xb, %ecx\n"
        "jmp .Lfb3336_000b53d6\n"
        ".Lfb3336_000b5843:\n"
        "movl %edx, %eax\n" /* line 767 */
        "shll $5, %eax\n"
        "jmp .Lfb3336_000b5373\n"
        ".Lfb3336_000b584d:\n"
        "movl -0x1012c(%ebp), %ecx\n" /* line 1134 */
        "movl %ecx, -0x10070(%ebp)\n"
        "movl $0, -0x10020(%ebp)\n"
        "movl %ecx, %ebx\n"
        "jmp .Lfb3336_000b5943\n"
        ".Lfb3336_000b586a:\n"
        "movl $0xff00, %ebx\n" /* line 827 */
        ".Lfb3336_000b586f:\n"
        "cmpl $0xff, %edx\n" /* line 829 */
        "jle .Lfb3336_000b59f0\n"
        "movl $0xff0000, %edx\n"
        ".Lfb3336_000b5880:\n"
        "cmpl $0xff, %ecx\n" /* line 831 */
        "jle .Lfb3336_000b59e6\n"
        "movl $0xff000000, %eax\n"
        ".Lfb3336_000b5891:\n"
        "orl %edx, %eax\n" /* line 1142 */
        "orl %ebx, %eax\n"
        "orb $0xff, %al\n"
        "movl -0x10088(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl -0x10134(%ebp), %ecx\n" /* line 815 */
        "movl ROQ_YY_tab(, %ecx, 4), %edx\n"
        "movl -0x101e4(%ebp), %edi\n" /* line 817 */
        "leal (%edx, %edi), %ebx\n"
        "movl -0x101bc(%ebp), %ecx\n" /* line 818 */
        "leal (%edx, %ecx), %eax\n"
        "addl -0x101b4(%ebp), %eax\n"
        "addl %esi, %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b59dc\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b58ea:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b59d4\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b58fa:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b59cc\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b590b:\n"
        "orl %eax, %edx\n" /* line 1143 */
        "orl %ecx, %edx\n"
        "orb $0xff, %dl\n"
        "movl -0x10088(%ebp), %ebx\n"
        "movl %edx, 4(%ebx)\n"
        "addl $8, %ebx\n"
        "movl %ebx, -0x10088(%ebp)\n"
        "addl $1, -0x10020(%ebp)\n" /* line 1134 */
        "movl -0x10020(%ebp), %esi\n"
        "cmpl %esi, -0x1017c(%ebp)\n"
        "je .Lfb3336_000b4028\n"
        "movl -0x10070(%ebp), %ebx\n"
        ".Lfb3336_000b5943:\n"
        "movzbl (%ebx), %eax\n" /* line 1136 */
        "movzbl 2(%ebx), %esi\n" /* line 1138 */
        "movl %esi, -0x10134(%ebp)\n"
        "movzbl 4(%ebx), %esi\n" /* line 1140 */
        "movl %ebx, %edi\n" /* line 1141 */
        "movzbl 5(%ebx), %ebx\n"
        "addl $6, %edi\n"
        "movl %edi, -0x10070(%ebp)\n"
        "movl ROQ_YY_tab(, %eax, 4), %ecx\n" /* line 815 */
        "movl ROQ_VR_tab(, %ebx, 4), %eax\n" /* line 817 */
        "movl %eax, -0x101e4(%ebp)\n"
        "leal (%ecx, %eax), %edi\n"
        "movl ROQ_UG_tab(, %esi, 4), %edx\n" /* line 818 */
        "movl %edx, -0x101bc(%ebp)\n"
        "leal (%ecx, %edx), %edx\n"
        "movl ROQ_VG_tab(, %ebx, 4), %ebx\n"
        "movl %ebx, -0x101b4(%ebp)\n"
        "addl %ebx, %edx\n"
        "movl ROQ_UB_tab(, %esi, 4), %esi\n" /* line 819 */
        "addl %esi, %ecx\n"
        "xorl %eax, %eax\n" /* line 821 */
        "movl %edi, %ebx\n"
        "sarl $6, %ebx\n"
        "cmovsl %eax, %ebx\n"
        "sarl $6, %edx\n" /* line 823 */
        "cmovsl %eax, %edx\n"
        "sarl $6, %ecx\n" /* line 825 */
        "cmovsl %eax, %ecx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jg .Lfb3336_000b586a\n"
        "shll $8, %ebx\n"
        "jmp .Lfb3336_000b586f\n"
        ".Lfb3336_000b59cc:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b590b\n"
        ".Lfb3336_000b59d4:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b58fa\n"
        ".Lfb3336_000b59dc:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b58ea\n"
        ".Lfb3336_000b59e6:\n"
        "movl %ecx, %eax\n" /* line 831 */
        "shll $0x18, %eax\n"
        "jmp .Lfb3336_000b5891\n"
        ".Lfb3336_000b59f0:\n"
        "shll $0x10, %edx\n" /* line 829 */
        "jmp .Lfb3336_000b5880\n"
        ".Lfb3336_000b59f8:\n"
        "movl -0x1012c(%ebp), %ebx\n" /* line 915 */
        "movl %ebx, -0x10058(%ebp)\n"
        "movl $0, -0x10050(%ebp)\n"
        "movl %ebx, %esi\n"
        "jmp .Lfb3336_000b5be6\n"
        ".Lfb3336_000b5a15:\n"
        "movl $0xff00, %ebx\n" /* line 827 */
        ".Lfb3336_000b5a1a:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b5cd9\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5a2a:\n"
        "cmpl $0xff, %ecx\n" /* line 831 */
        "jle .Lfb3336_000b5ccf\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5a3b:\n"
        "orl %eax, %edx\n" /* line 923 */
        "orl %edx, %ebx\n"
        "orb $0xff, %bl\n"
        "movl -0x10174(%ebp), %eax\n"
        "movl %ebx, (%eax)\n"
        "movl -0x10164(%ebp), %ecx\n" /* line 815 */
        "movl ROQ_YY_tab(, %ecx, 4), %edx\n"
        "movl -0x101f4(%ebp), %esi\n" /* line 817 */
        "leal (%edx, %esi), %ebx\n"
        "movl -0x101d4(%ebp), %ecx\n" /* line 818 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101dc(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b5cc5\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b5a95:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b5cbd\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5aa5:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b5cb5\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5ab6:\n"
        "orl %eax, %edx\n" /* line 924 */
        "orl %edx, %ecx\n"
        "orb $0xff, %cl\n"
        "movl -0x10174(%ebp), %ebx\n"
        "movl %ecx, 4(%ebx)\n"
        "movl -0x10160(%ebp), %esi\n" /* line 815 */
        "movl ROQ_YY_tab(, %esi, 4), %edx\n"
        "movl -0x101f4(%ebp), %eax\n" /* line 817 */
        "leal (%edx, %eax), %ebx\n"
        "movl -0x101d4(%ebp), %ecx\n" /* line 818 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101dc(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b5cab\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b5b11:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b5ca3\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5b21:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b5c9b\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5b32:\n"
        "orl %eax, %edx\n" /* line 925 */
        "orl %edx, %ecx\n"
        "orb $0xff, %cl\n"
        "movl -0x10174(%ebp), %ebx\n"
        "movl %ecx, 8(%ebx)\n"
        "movl -0x1015c(%ebp), %esi\n" /* line 815 */
        "movl ROQ_YY_tab(, %esi, 4), %edx\n"
        "movl -0x101f4(%ebp), %eax\n" /* line 817 */
        "leal (%edx, %eax), %ebx\n"
        "movl -0x101d4(%ebp), %ecx\n" /* line 818 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101dc(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b5c91\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b5b8d:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b5c89\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5b9d:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b5c81\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5bae:\n"
        "orl %eax, %edx\n" /* line 926 */
        "orl %edx, %ecx\n"
        "orb $0xff, %cl\n"
        "movl -0x10174(%ebp), %ebx\n"
        "movl %ecx, 0xc(%ebx)\n"
        "addl $0x10, %ebx\n"
        "movl %ebx, -0x10174(%ebp)\n"
        "addl $1, -0x10050(%ebp)\n" /* line 915 */
        "movl -0x10050(%ebp), %esi\n"
        "cmpl %esi, -0x1017c(%ebp)\n"
        "je .Lfb3336_000b4865\n"
        "movl -0x10058(%ebp), %esi\n"
        ".Lfb3336_000b5be6:\n"
        "movzbl (%esi), %eax\n" /* line 917 */
        "movzbl 1(%esi), %edi\n" /* line 918 */
        "movl %edi, -0x10164(%ebp)\n"
        "movzbl 2(%esi), %edx\n" /* line 919 */
        "movl %edx, -0x10160(%ebp)\n"
        "movzbl 3(%esi), %ecx\n" /* line 920 */
        "movl %ecx, -0x1015c(%ebp)\n"
        "movzbl 4(%esi), %ebx\n" /* line 921 */
        "movzbl 5(%esi), %edx\n" /* line 922 */
        "addl $6, %esi\n"
        "movl %esi, -0x10058(%ebp)\n"
        "movl ROQ_YY_tab(, %eax, 4), %ecx\n" /* line 815 */
        "movl ROQ_VR_tab(, %edx, 4), %esi\n" /* line 817 */
        "movl %esi, -0x101f4(%ebp)\n"
        "leal (%ecx, %esi), %esi\n"
        "movl ROQ_UG_tab(, %ebx, 4), %eax\n" /* line 818 */
        "movl %eax, -0x101d4(%ebp)\n"
        "leal (%ecx, %eax), %eax\n"
        "movl ROQ_VG_tab(, %edx, 4), %edi\n"
        "addl %edi, %eax\n"
        "movl ROQ_UB_tab(, %ebx, 4), %ebx\n" /* line 819 */
        "movl %ebx, -0x101dc(%ebp)\n"
        "addl %ebx, %ecx\n"
        "xorl %edx, %edx\n" /* line 821 */
        "movl %esi, %ebx\n"
        "sarl $6, %ebx\n"
        "cmovsl %edx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %edx, %eax\n"
        "sarl $6, %ecx\n" /* line 825 */
        "cmovsl %edx, %ecx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jg .Lfb3336_000b5a15\n"
        "shll $8, %ebx\n"
        "jmp .Lfb3336_000b5a1a\n"
        ".Lfb3336_000b5c81:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b5bae\n"
        ".Lfb3336_000b5c89:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5b9d\n"
        ".Lfb3336_000b5c91:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b5b8d\n"
        ".Lfb3336_000b5c9b:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b5b32\n"
        ".Lfb3336_000b5ca3:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5b21\n"
        ".Lfb3336_000b5cab:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b5b11\n"
        ".Lfb3336_000b5cb5:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b5ab6\n"
        ".Lfb3336_000b5cbd:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5aa5\n"
        ".Lfb3336_000b5cc5:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b5a95\n"
        ".Lfb3336_000b5ccf:\n"
        "movl %ecx, %edx\n" /* line 831 */
        "shll $0x18, %edx\n"
        "jmp .Lfb3336_000b5a3b\n"
        ".Lfb3336_000b5cd9:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5a2a\n"
        ".Lfb3336_000b5ce1:\n"
        "movl -0x1012c(%ebp), %ebx\n" /* line 1006 */
        "movl %ebx, -0x10060(%ebp)\n"
        "movl $0, -0x1003c(%ebp)\n"
        "movl %ebx, %esi\n"
        "movl %ebx, %edi\n"
        "movl %ebx, %eax\n"
        "movl %ebx, %edx\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfb3336_000b611b\n"
        ".Lfb3336_000b5d06:\n"
        "movl $0xff00, %ebx\n" /* line 827 */
        ".Lfb3336_000b5d0b:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b627c\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5d1b:\n"
        "cmpl $0xff, %ecx\n" /* line 831 */
        "jle .Lfb3336_000b6272\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5d2c:\n"
        "orl %eax, %edx\n" /* line 1014 */
        "orl %ebx, %edx\n"
        "orb $0xff, %dl\n"
        "movl -0x1008c(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "movl -0x10144(%ebp), %ecx\n" /* line 815 */
        "movl ROQ_YY_tab(, %ecx, 4), %edx\n"
        "movl -0x101ec(%ebp), %esi\n" /* line 817 */
        "leal (%edx, %esi), %ebx\n"
        "movl -0x101c4(%ebp), %ecx\n" /* line 818 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101c8(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b6268\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b5d86:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b6260\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5d96:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b6258\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5da7:\n"
        "orl %eax, %edx\n" /* line 1015 */
        "orl %ecx, %edx\n"
        "orb $0xff, %dl\n"
        "movl -0x1008c(%ebp), %ebx\n"
        "movl %edx, 4(%ebx)\n"
        "movl -0x10148(%ebp), %esi\n" /* line 815 */
        "leal (%esi, %esi, 2), %eax\n"
        "movl -0x10140(%ebp), %edx\n"
        "leal (%edx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movl ROQ_YY_tab(, %eax, 4), %edx\n"
        "movl -0x101ec(%ebp), %ecx\n" /* line 817 */
        "leal (%edx, %ecx), %ebx\n"
        "movl -0x101c4(%ebp), %esi\n" /* line 818 */
        "leal (%edx, %esi), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101c8(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b624e\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b5e11:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b6246\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5e21:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b623e\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5e32:\n"
        "orl %eax, %edx\n" /* line 1016 */
        "orl %ecx, %edx\n"
        "orb $0xff, %dl\n"
        "movl -0x1008c(%ebp), %eax\n"
        "movl %edx, 8(%eax)\n"
        "movl -0x10144(%ebp), %edx\n" /* line 815 */
        "leal (%edx, %edx, 2), %eax\n"
        "movl -0x1013c(%ebp), %ecx\n"
        "leal (%ecx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movl ROQ_YY_tab(, %eax, 4), %edx\n"
        "movl -0x101ec(%ebp), %esi\n" /* line 817 */
        "leal (%edx, %esi), %ebx\n"
        "movl -0x101c4(%ebp), %ecx\n" /* line 818 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101c8(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b6234\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b5e9c:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b622c\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5eac:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b6224\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5ebd:\n"
        "orl %eax, %edx\n" /* line 1017 */
        "orl %ecx, %edx\n"
        "orb $0xff, %dl\n"
        "movl -0x1008c(%ebp), %ebx\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl -0x10140(%ebp), %esi\n" /* line 815 */
        "leal (%esi, %esi, 2), %eax\n"
        "movl -0x10148(%ebp), %edx\n"
        "leal (%edx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movl ROQ_YY_tab(, %eax, 4), %edx\n"
        "movl -0x101ec(%ebp), %ecx\n" /* line 817 */
        "leal (%edx, %ecx), %ebx\n"
        "movl -0x101c4(%ebp), %esi\n" /* line 818 */
        "leal (%edx, %esi), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101c8(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b621a\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b5f27:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b6212\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5f37:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b620a\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5f48:\n"
        "orl %eax, %edx\n" /* line 1018 */
        "orl %edx, %ecx\n"
        "orb $0xff, %cl\n"
        "movl -0x1008c(%ebp), %eax\n"
        "movl %ecx, 0x10(%eax)\n"
        "movl -0x1013c(%ebp), %edx\n" /* line 815 */
        "leal (%edx, %edx, 2), %eax\n"
        "movl -0x10144(%ebp), %ecx\n"
        "leal (%ecx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movl ROQ_YY_tab(, %eax, 4), %edx\n"
        "movl -0x101ec(%ebp), %esi\n" /* line 817 */
        "leal (%edx, %esi), %ebx\n"
        "movl -0x101c4(%ebp), %ecx\n" /* line 818 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101c8(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b6200\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b5fb2:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b61f8\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b5fc2:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b61f0\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b5fd3:\n"
        "orl %eax, %edx\n" /* line 1019 */
        "orl %edx, %ecx\n"
        "orb $0xff, %cl\n"
        "movl -0x1008c(%ebp), %ebx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl -0x10140(%ebp), %esi\n" /* line 815 */
        "movl ROQ_YY_tab(, %esi, 4), %edx\n"
        "movl -0x101ec(%ebp), %eax\n" /* line 817 */
        "leal (%edx, %eax), %ebx\n"
        "movl -0x101c4(%ebp), %ecx\n" /* line 818 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101c8(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b61e6\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b602e:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b61de\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b603e:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b61d6\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b604f:\n"
        "orl %eax, %edx\n" /* line 1020 */
        "orl %edx, %ecx\n"
        "orb $0xff, %cl\n"
        "movl -0x1008c(%ebp), %ebx\n"
        "movl %ecx, 0x18(%ebx)\n"
        "movl -0x1013c(%ebp), %esi\n" /* line 815 */
        "movl ROQ_YY_tab(, %esi, 4), %edx\n"
        "movl -0x101ec(%ebp), %eax\n" /* line 817 */
        "leal (%edx, %eax), %ebx\n"
        "movl -0x101c4(%ebp), %ecx\n" /* line 818 */
        "leal (%edx, %ecx), %eax\n"
        "addl %edi, %eax\n"
        "addl -0x101c8(%ebp), %edx\n" /* line 819 */
        "xorl %ecx, %ecx\n" /* line 821 */
        "sarl $6, %ebx\n"
        "cmovsl %ecx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %ecx, %eax\n"
        "sarl $6, %edx\n" /* line 825 */
        "cmovsl %ecx, %edx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jle .Lfb3336_000b61cc\n"
        "movw $0xff00, %cx\n"
        ".Lfb3336_000b60aa:\n"
        "cmpl $0xff, %eax\n" /* line 829 */
        "jle .Lfb3336_000b61c4\n"
        "movl $0xff0000, %eax\n"
        ".Lfb3336_000b60ba:\n"
        "cmpl $0xff, %edx\n" /* line 831 */
        "jle .Lfb3336_000b61bc\n"
        "movl $0xff000000, %edx\n"
        ".Lfb3336_000b60cb:\n"
        "orl %eax, %edx\n" /* line 1021 */
        "orl %edx, %ecx\n"
        "orb $0xff, %cl\n"
        "movl -0x1008c(%ebp), %ebx\n"
        "movl %ecx, 0x1c(%ebx)\n"
        "addl $0x20, %ebx\n"
        "movl %ebx, -0x1008c(%ebp)\n"
        "addl $1, -0x1003c(%ebp)\n" /* line 1006 */
        "movl -0x1003c(%ebp), %esi\n"
        "cmpl %esi, -0x1017c(%ebp)\n"
        "je .Lfb3336_000b46ba\n"
        "movl -0x10060(%ebp), %esi\n"
        "movl -0x10060(%ebp), %edi\n"
        "movl -0x10060(%ebp), %eax\n"
        "movl -0x10060(%ebp), %edx\n"
        "movl -0x10060(%ebp), %ecx\n"
        ".Lfb3336_000b611b:\n"
        "movzbl (%esi), %esi\n" /* line 1008 */
        "movl %esi, -0x10148(%ebp)\n"
        "movzbl 1(%edi), %edi\n" /* line 1009 */
        "movl %edi, -0x10144(%ebp)\n"
        "movzbl 2(%eax), %eax\n" /* line 1010 */
        "movl %eax, -0x10140(%ebp)\n"
        "movzbl 3(%edx), %edx\n" /* line 1011 */
        "movl %edx, -0x1013c(%ebp)\n"
        "movzbl 4(%ecx), %ebx\n" /* line 1012 */
        "movzbl 5(%ecx), %edx\n" /* line 1013 */
        "addl $6, %ecx\n"
        "movl %ecx, -0x10060(%ebp)\n"
        "movl ROQ_YY_tab(, %esi, 4), %ecx\n" /* line 815 */
        "movl ROQ_VR_tab(, %edx, 4), %esi\n" /* line 817 */
        "movl %esi, -0x101ec(%ebp)\n"
        "leal (%ecx, %esi), %esi\n"
        "movl ROQ_UG_tab(, %ebx, 4), %eax\n" /* line 818 */
        "movl %eax, -0x101c4(%ebp)\n"
        "leal (%ecx, %eax), %eax\n"
        "movl ROQ_VG_tab(, %edx, 4), %edi\n"
        "addl %edi, %eax\n"
        "movl ROQ_UB_tab(, %ebx, 4), %ebx\n" /* line 819 */
        "movl %ebx, -0x101c8(%ebp)\n"
        "addl %ebx, %ecx\n"
        "xorl %edx, %edx\n" /* line 821 */
        "movl %esi, %ebx\n"
        "sarl $6, %ebx\n"
        "cmovsl %edx, %ebx\n"
        "sarl $6, %eax\n" /* line 823 */
        "cmovsl %edx, %eax\n"
        "sarl $6, %ecx\n" /* line 825 */
        "cmovsl %edx, %ecx\n"
        "cmpl $0xff, %ebx\n" /* line 827 */
        "jg .Lfb3336_000b5d06\n"
        "shll $8, %ebx\n"
        "jmp .Lfb3336_000b5d0b\n"
        ".Lfb3336_000b61bc:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b60cb\n"
        ".Lfb3336_000b61c4:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b60ba\n"
        ".Lfb3336_000b61cc:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b60aa\n"
        ".Lfb3336_000b61d6:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b604f\n"
        ".Lfb3336_000b61de:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b603e\n"
        ".Lfb3336_000b61e6:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b602e\n"
        ".Lfb3336_000b61f0:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b5fd3\n"
        ".Lfb3336_000b61f8:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5fc2\n"
        ".Lfb3336_000b6200:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b5fb2\n"
        ".Lfb3336_000b620a:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b5f48\n"
        ".Lfb3336_000b6212:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5f37\n"
        ".Lfb3336_000b621a:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b5f27\n"
        ".Lfb3336_000b6224:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b5ebd\n"
        ".Lfb3336_000b622c:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5eac\n"
        ".Lfb3336_000b6234:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b5e9c\n"
        ".Lfb3336_000b623e:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b5e32\n"
        ".Lfb3336_000b6246:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5e21\n"
        ".Lfb3336_000b624e:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b5e11\n"
        ".Lfb3336_000b6258:\n"
        "shll $0x18, %edx\n" /* line 831 */
        "jmp .Lfb3336_000b5da7\n"
        ".Lfb3336_000b6260:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5d96\n"
        ".Lfb3336_000b6268:\n"
        "movl %ebx, %ecx\n" /* line 827 */
        "shll $8, %ecx\n"
        "jmp .Lfb3336_000b5d86\n"
        ".Lfb3336_000b6272:\n"
        "movl %ecx, %edx\n" /* line 831 */
        "shll $0x18, %edx\n"
        "jmp .Lfb3336_000b5d2c\n"
        ".Lfb3336_000b627c:\n"
        "shll $0x10, %eax\n" /* line 829 */
        "jmp .Lfb3336_000b5d1b\n"
        ".Lfb3336_000b6284:\n"
        "movl -0x1012c(%ebp), %ebx\n" /* line 1041 */
        "movl %ebx, -0x10068(%ebp)\n"
        "movl $0, -0x10034(%ebp)\n"
        "movl 0x4f3a84(%eax), %edi\n"
        "movl %ebx, %esi\n"
        "movl %ebx, %eax\n"
        "jmp .Lfb3336_000b62b2\n"
        ".Lfb3336_000b62a6:\n"
        "movl -0x10068(%ebp), %esi\n"
        "movl -0x10068(%ebp), %eax\n"
        ".Lfb3336_000b62b2:\n"
        "movzbl (%esi), %esi\n" /* line 1043 */
        "movl %esi, -0x1020c(%ebp)\n"
        "movzbl 1(%eax), %ecx\n" /* line 1044 */
        "movzbl 2(%eax), %ebx\n" /* line 1045 */
        "movzbl 3(%eax), %esi\n" /* line 1046 */
        "addl $6, %eax\n" /* line 1047 */
        "movl %eax, -0x10068(%ebp)\n"
        "movl -0x1020c(%ebp), %edx\n" /* line 1048 */
        "movzbl (%edi, %edx), %edx\n"
        "movl -0x10084(%ebp), %eax\n"
        "movb %dl, (%eax)\n"
        "movzbl (%edi, %ecx), %edx\n" /* line 1049 */
        "movb %dl, 1(%eax)\n"
        "movl -0x1020c(%ebp), %edx\n" /* line 1050 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%ebx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "movl -0x10084(%ebp), %edx\n"
        "movb %al, 2(%edx)\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1051 */
        "leal (%esi, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "movb %al, 3(%edx)\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1052 */
        "movl -0x1020c(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, -0x1020c(%ebp)\n"
        "movzbl (%edi, %edx), %eax\n"
        "movl -0x10084(%ebp), %edx\n"
        "movb %al, 4(%edx)\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 1053 */
        "addl %eax, %ecx\n"
        "sarl $2, %ecx\n"
        "movzbl (%edi, %ecx), %eax\n"
        "movb %al, 5(%edx)\n"
        "movzbl (%edi, %ebx), %eax\n" /* line 1054 */
        "movb %al, 6(%edx)\n"
        "movzbl (%edi, %esi), %eax\n" /* line 1055 */
        "movb %al, 7(%edx)\n"
        "addl $8, %edx\n"
        "movl %edx, -0x10084(%ebp)\n"
        "addl $1, -0x10034(%ebp)\n" /* line 1041 */
        "movl -0x10034(%ebp), %ecx\n"
        "cmpl %ecx, -0x1017c(%ebp)\n"
        "jne .Lfb3336_000b62a6\n"
        "jmp .Lfb3336_000b447c\n"
        ".Lfb3336_000b637a:\n"
        "movl -0x1012c(%ebp), %esi\n" /* line 943 */
        "movl %esi, -0x1005c(%ebp)\n"
        "xorl %ecx, %ecx\n"
        "movl 0x4f3a84(%eax), %edx\n"
        "movl %esi, %edi\n"
        ".Lfb3336_000b6390:\n"
        "movzbl (%edi), %eax\n" /* line 945 */
        "movzbl (%edx, %eax), %eax\n"
        "movb %al, (%ebx)\n"
        "movzbl 1(%edi), %eax\n" /* line 946 */
        "movzbl (%edx, %eax), %eax\n"
        "movb %al, 1(%ebx)\n"
        "movzbl 2(%edi), %eax\n" /* line 947 */
        "movzbl (%edx, %eax), %eax\n"
        "movb %al, 2(%ebx)\n"
        "movzbl 3(%edi), %eax\n" /* line 948 */
        "movzbl (%edx, %eax), %eax\n"
        "movb %al, 3(%ebx)\n"
        "addl $4, %ebx\n"
        "addl $6, %edi\n" /* line 949 */
        "movl %edi, -0x1005c(%ebp)\n"
        "addl $1, %ecx\n" /* line 943 */
        "cmpl %ecx, -0x1017c(%ebp)\n"
        "jne .Lfb3336_000b6390\n"
        "jmp .Lfb3336_000b3b11\n"
    );
}

/* line 2095 */
__attribute__((naked))
inflate_blocks_statef ROQ_RunCinematic(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2095 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl CL_handle, %eax\n" /* line 2097 */
        "cmpl $0xf, %eax\n"
        "jbe .Lfb63d6_000b63e8\n"
        "leave\n" /* line 2101 */
        "retl\n"
        ".Lfb63d6_000b63e8:\n"
        "movl %eax, (%esp)\n" /* line 2099 */
        "calll ROQ_RunCinematicFromHandle\n"
        "leave\n" /* line 2101 */
        "retl\n"
    );
}

/* line 2031 */
__attribute__((naked))
inflate_blocks_statef ROQ_PlayCinematic_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2031 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "movl $0x21ead8, (%esp)\n" /* line 2037 */
        "calll Com_DPrintf\n"
        "movl 0x195ee8c, %eax\n" /* line 2038 */
        "movl (%eax), %ebx\n" /* arg */
        "movl (%ebx), %eax\n" /* arg */
        "cmpl $1, %eax\n"
        "je .Lfb63f2_000b6559\n"
        "cmpl $2, %eax\n" /* line 2040 */
        "je .Lfb63f2_000b662c\n"
        ".Lfb63f2_000b6420:\n"
        "movl $1, (%esp)\n" /* line 2043 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* arg */
        "movl $2, (%esp)\n" /* line 2044 */
        "calll Cmd_Argv\n"
        "testl %eax, %eax\n" /* line 2046 */
        "je .Lfb63f2_000b6614\n"
        ".Lfb63f2_000b6442:\n"
        "movzbl (%eax), %eax\n"
        "cmpb $0x31, %al\n"
        "je .Lfb63f2_000b6620\n"
        "cmpb $0x32, %al\n" /* line 2050 */
        "jne .Lfb63f2_000b6636\n"
        "movl $3, %edx\n"
        "movl $3, %eax\n"
        ".Lfb63f2_000b645f:\n"
        "testb $0x20, %al\n" /* line 2059 */
        "je .Lfb63f2_000b6523\n"
        "movl %edx, 0x14(%esp)\n" /* line 2061 */
        "movl $0x10e, 0x10(%esp)\n"
        "movl $0x280, 0xc(%esp)\n"
        "movl $0x69, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arg */
        "calll ROQ_PlayCinematic\n"
        "movl %eax, CL_handle\n"
        ".Lfb63f2_000b6498:\n"
        "movl CL_handle, %ecx\n" /* line 2068 */
        "testl %ecx, %ecx\n"
        "js .Lfb63f2_000b651d\n"
        "movl $0, (%esp)\n" /* line 2070 */
        "calll SND_StopSounds\n"
        "movl $0, 4(%esp)\n" /* line 2072 */
        "movl $0x3f800000, (%esp)\n"
        "calll SND_FadeAllSounds\n"
        "jmp .Lfb63f2_000b64ec\n"
        ".Lfb63f2_000b64c4:\n"
        "movl currentHandle, %eax\n" /* line 2074 */
        "leal (%eax, %eax, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "leal (%edx, %eax), %eax\n"
        "movl 0x4f3ac4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfb63f2_000b651d\n"
        ".Lfb63f2_000b64e3:\n"
        "cmpl $1, 0x4f3a3c(%eax)\n"
        "jne .Lfb63f2_000b651d\n"
        ".Lfb63f2_000b64ec:\n"
        "movl CL_handle, %eax\n" /* line 2097 */
        "cmpl $0xf, %eax\n"
        "ja .Lfb63f2_000b64c4\n"
        "movl %eax, (%esp)\n" /* line 2099 */
        "calll ROQ_RunCinematicFromHandle\n"
        "movl currentHandle, %eax\n" /* line 2074 */
        "leal (%eax, %eax, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "leal (%edx, %eax), %eax\n"
        "movl 0x4f3ac4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfb63f2_000b64e3\n"
        /* } scope */
        ".Lfb63f2_000b651d:\n"
        "addl $0x24, %esp\n" /* line 2083 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb63f2_000b6523:\n"
        "movl %edx, 0x14(%esp)\n" /* line 2065 */
        "movl $0x1e0, 0x10(%esp)\n"
        "movl $0x280, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arg */
        "calll ROQ_PlayCinematic\n"
        "movl %eax, CL_handle\n"
        "jmp .Lfb63f2_000b6498\n"
        ".Lfb63f2_000b6559:\n"
        "movl CL_handle, %ecx\n" /* line 2106 */
        "cmpl $0xf, %ecx\n"
        "ja .Lfb63f2_000b6420\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1648 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "cmpl $2, 0x4f3a3c(%eax)\n"
        "je .Lfb63f2_000b65dc\n"
        "movl %ecx, currentHandle\n" /* line 1650 */
        "addl $cinTable, %eax\n" /* line 1652 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21e9e4, (%esp)\n" /* "trFMV::stop(), closing %s
" */
        "calll Com_DPrintf\n"
        "movl currentHandle, %ecx\n" /* line 1654 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "leal (%eax, %ecx), %edx\n"
        "movl 0x4f3ac4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfb63f2_000b65dc\n"
        "movl 0x4f3a24(%edx), %eax\n" /* line 1659 */
        "testl %eax, %eax\n"
        "je .Lfb63f2_000b65ca\n"
        "cmpl $1, (%ebx)\n" /* line 1661 */
        "jne .Lfb63f2_000b65dc\n"
        ".Lfb63f2_000b65ca:\n"
        "movl $0x4f3a30, %eax\n" /* line 1666 */
        "movl $2, 0xc(%edx, %eax)\n"
        "calll RoQShutdown\n" /* line 1667 */
        ".Lfb63f2_000b65dc:\n"
        "movl $0, (%esp)\n" /* line 2109 */
        "calll SND_StopSounds\n"
        "movl $0xffffffff, CL_handle\n" /* line 2110 */
        "movl $1, (%esp)\n" /* line 2043 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* arg */
        "movl $2, (%esp)\n" /* line 2044 */
        "calll Cmd_Argv\n"
        "testl %eax, %eax\n" /* line 2046 */
        "jne .Lfb63f2_000b6442\n"
        ".Lfb63f2_000b6614:\n"
        "movl $1, %edx\n"
        "movb $1, %al\n"
        "jmp .Lfb63f2_000b645f\n"
        ".Lfb63f2_000b6620:\n"
        "movl $5, %edx\n" /* line 2050 */
        ".Lfb63f2_000b6625:\n"
        "movl %edx, %eax\n" /* line 2054 */
        "jmp .Lfb63f2_000b645f\n"
        ".Lfb63f2_000b662c:\n"
        "calll CL_StopLogo\n" /* line 2041 */
        "jmp .Lfb63f2_000b6420\n"
        ".Lfb63f2_000b6636:\n"
        "movl $1, %edx\n" /* line 2050 */
        "cmpb $0x33, %al\n" /* line 2054 */
        "jne .Lfb63f2_000b6625\n"
        "movl $0x21, %edx\n" /* line 2056 */
        "movl $0x21, %eax\n"
        "jmp .Lfb63f2_000b645f\n"
    );
}

