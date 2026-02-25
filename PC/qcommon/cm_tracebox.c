/* ASM dump from: cm_tracebox.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_tracebox.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

void CM_CalcTraceEntents(TraceExtents *extents);
qboolean CM_TraceBox(const TraceExtents *extents, const vec_t *mins, const vec_t *maxs, float fraction);

/* line 9 */
__attribute__((naked))
void CM_CalcTraceEntents(TraceExtents *extents)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 9 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* extents */
        "movl $3, %edx\n"
        "pxor %xmm1, %xmm1\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        /* { scope 1 */
        ".Lfbba60_000bba77:\n"
        "movss (%eax), %xmm0\n" /* line 16 */
        "subss 0xc(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n" /* line 17 */
        "jne .Lfbba60_000bba99\n"
        "jp .Lfbba60_000bba99\n"
        "movaps %xmm1, %xmm0\n"
        ".Lfbba60_000bba8a:\n"
        "movss %xmm0, 0x18(%eax)\n"
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 14 */
        "jne .Lfbba60_000bba77\n"
        /* } scope */
        "popl %ebp\n" /* line 19 */
        "retl\n"
        /* { scope 1 */
        ".Lfbba60_000bba99:\n"
        "movaps %xmm2, %xmm3\n" /* line 17 */
        "divss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "jmp .Lfbba60_000bba8a\n"
    );
}

/* line 27 */
__attribute__((naked))
qboolean CM_TraceBox(const TraceExtents *extents, const vec_t *mins, const vec_t *maxs, float fraction)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* extents */
        "movl 0x10(%ebp), %esi\n" /* maxs */
        "movss 0x14(%ebp), %xmm5\n" /* fraction */
        "movl 0xc(%ebp), %ecx\n" /* mins */
        "pxor %xmm6, %xmm6\n"
        "movss 0x2ed5dc, %xmm3\n" /* -1.0f */
        "movaps %xmm6, %xmm4\n"
        "movss 0x2ed5d0, %xmm7\n" /* 1.0f */
        ".Lfbbaa6_000bbad0:\n"
        "movl %ebx, %eax\n" /* extents */
        "movl $1, %edx\n"
        /* { scope 1 */
        ".Lfbbaa6_000bbad7:\n"
        "movss -4(%ecx, %edx, 4), %xmm0\n" /* line 50 */
        "movss (%eax), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "movss 0xc(%eax), %xmm1\n" /* line 51 */
        "subss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "ucomiss %xmm4, %xmm2\n" /* line 53 */
        "jbe .Lfbbaa6_000bbb37\n"
        "ucomiss %xmm4, %xmm1\n" /* line 55 */
        "ja .Lfbbaa6_000bbb6f\n"
        "movaps %xmm2, %xmm1\n" /* line 58 */
        "mulss 0x18(%eax), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "ucomiss %xmm5, %xmm1\n" /* line 59 */
        "jae .Lfbbaa6_000bbb6f\n"
        "movaps %xmm6, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "ja .Lfbbaa6_000bbb6a\n"
        ".Lfbbaa6_000bbb1d:\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 48 */
        "jne .Lfbbaa6_000bbad7\n"
        "movaps %xmm7, %xmm0\n" /* line 72 */
        "ucomiss %xmm7, %xmm3\n"
        "je .Lfbbaa6_000bbb78\n"
        ".Lfbbaa6_000bbb30:\n"
        "movl %esi, %ecx\n" /* maxs */
        "movaps %xmm0, %xmm3\n"
        "jmp .Lfbbaa6_000bbad0\n"
        ".Lfbbaa6_000bbb37:\n"
        "ucomiss %xmm4, %xmm1\n" /* line 63 */
        "jbe .Lfbbaa6_000bbb1d\n"
        "movaps %xmm2, %xmm1\n" /* line 65 */
        "mulss 0x18(%eax), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "ucomiss %xmm1, %xmm6\n" /* line 66 */
        "jae .Lfbbaa6_000bbb6f\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm5, %xmm0\n"
        "movaps %xmm5, %xmm2\n"
        "cmpnltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm5\n"
        "jmp .Lfbbaa6_000bbb1d\n"
        ".Lfbbaa6_000bbb6a:\n"
        "movaps %xmm1, %xmm6\n"
        "jmp .Lfbbaa6_000bbb1d\n"
        ".Lfbbaa6_000bbb6f:\n"
        "movl $1, %eax\n" /* line 72 */
        /* } scope */
        "popl %ebx\n" /* line 79 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbbaa6_000bbb78:\n"
        "jp .Lfbbaa6_000bbb30\n" /* line 72 */
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebx\n" /* line 79 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

