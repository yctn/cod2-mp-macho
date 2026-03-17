/* ASM dump from: cm_trace.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_trace.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern void * Sys_GetValue(int key);
cmodel_t * CM_ClipHandleToModel(clipHandle_t handle);
static int CM_TestInLeafBrushNode_r(void);
static int CM_SightTraceThroughBrush(cbrush_t *brush);
static int CM_SightTraceThroughLeafBrushNode_r(const vec_t *p2);
static int CM_SightTraceThroughLeaf(trace_t *trace);
static int CM_TraceThroughLeafBrushNode_r(const vec_t *p2, trace_t *trace);
static int CM_SightTraceThroughTree(const traceWork_t *tw, const vec_t *p2, trace_t *trace);
static Bool CM_TraceThroughLeafBrushNode(void);
static qboolean CM_TraceSphereThroughSphere(const vec_t *vStationary, trace_t *trace);
static qboolean CM_SightTraceSphereThroughSphere(const vec_t *vStationary, trace_t *trace);
clipHandle_t CM_TempBoxModel(const vec_t *mins, const vec_t *maxs, int contents);
static int CM_TraceThroughTree(const vec_t *p2, trace_t *trace);
int CM_ContentsOfModel(clipHandle_t handle);
float CM_RadiusOfModel(clipHandle_t handle);
static int CM_Trace(trace_t *results, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask);
int CM_BoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask);
int CM_BoxSightTrace(int oldHitNum, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask);
int CM_TransformedBoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask, const vec_t *origin, const vec_t *angles);
int CM_TransformedBoxTraceExternal(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask, const vec_t *origin, const vec_t *angles);
int CM_TransformedBoxSightTrace(int hitNum, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask, const vec_t *origin, const vec_t *angles);

/* line 79 */
cmodel_t * CM_ClipHandleToModel(clipHandle_t handle)
{
    char *cm = (char *)imp_cm;
    if (handle < *(int *)(cm + 0x74)) {
        return (cmodel_t *)(*(char **)(cm + 0x78) + handle * 72);
    }
    return *(cmodel_t **)((char *)Sys_GetValue(3) + 0x14);
}

/* line 254 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
int CM_TestInLeafBrushNode_r(void)
{
    __asm__ __volatile__ (
        ".Lf62e1c_00062e1c:\n"
        "pushl %ebp\n" /* line 254 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %esi\n" /* tw */
        "movl %edx, %ebx\n" /* node */
        "movl %ecx, %edi\n" /* trace */
        /* { scope 1: i */
        ".Lf62e1c_00062e2b:\n"
        "movl 0x80(%esi), %edx\n" /* line 263 | tw */
        "testl %edx, 4(%ebx)\n" /* node */
        "je .Lf62e1c_00062e79\n"
        ".Lf62e1c_00062e36:\n"
        "cmpw $0, 2(%ebx)\n" /* line 266 | node */
        "je .Lf62e1c_00062e51\n"
        "jg .Lf62e1c_00062eb3\n" /* line 268 */
        "leal 0x14(%ebx), %edx\n" /* line 285 | node */
        "movl %edi, %ecx\n" /* trace */
        "movl %esi, %eax\n" /* tw */
        "calll CM_TestInLeafBrushNode_r\n"
        "cmpb $0, 0x22(%edi)\n" /* line 286 | trace */
        "jne .Lf62e1c_00062e79\n"
        ".Lf62e1c_00062e51:\n"
        "movzbl (%ebx), %eax\n" /* line 290 | node */
        "movss 8(%ebx), %xmm1\n" /* node */
        "movss 0x68(%esi, %eax, 4), %xmm0\n" /* tw */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf62e1c_00062e81\n"
        "movzwl 0x10(%ebx), %eax\n" /* line 292 | node */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* node */
        "movl 0x80(%esi), %edx\n" /* line 263 | tw */
        "testl %edx, 4(%ebx)\n" /* node */
        "jne .Lf62e1c_00062e36\n"
        /* } scope */
        ".Lf62e1c_00062e79:\n"
        "addl $0x2c, %esp\n" /* line 305 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lf62e1c_00062e81:\n"
        "movss 0x74(%esi, %eax, 4), %xmm0\n" /* line 296 | tw */
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf62e1c_00062e98\n"
        ".Lf62e1c_00062e8c:\n"
        "movzwl 0x12(%ebx), %eax\n" /* line 303 | node */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* node */
        "jmp .Lf62e1c_00062e2b\n"
        ".Lf62e1c_00062e98:\n"
        "movzwl 0x10(%ebx), %edx\n" /* line 298 | node */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%ebx, %edx, 4), %edx\n" /* node */
        "movl %edi, %ecx\n" /* trace */
        "movl %esi, %eax\n" /* tw */
        "calll CM_TestInLeafBrushNode_r\n"
        "cmpb $0, 0x22(%edi)\n" /* line 299 | trace */
        "je .Lf62e1c_00062e8c\n"
        "jmp .Lf62e1c_00062e79\n"
        ".Lf62e1c_00062eb3:\n"
        "cmpw $0, 2(%ebx)\n" /* line 270 | node */
        "jle .Lf62e1c_00062e79\n"
        "movl $0, -0x28(%ebp)\n" /* k */
        ".Lf62e1c_00062ec1:\n"
        "movl 8(%ebx), %eax\n" /* line 273 | node */
        "movl -0x28(%ebp), %ecx\n" /* k */
        "movzwl (%eax, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 2), %ecx\n"
        "shll $4, %ecx\n"
        "movl imp_cm, %eax\n"
        "addl 0x80(%eax), %ecx\n"
        "testl %edx, 0xc(%ecx)\n" /* line 274 */
        "je .Lf62e1c_0006304a\n"
        /* { scope 2 */
        "movss 0x68(%esi), %xmm0\n" /* line 199 */
        "ucomiss 0x10(%ecx), %xmm0\n"
        "ja .Lf62e1c_00063040\n"
        "movss 0x6c(%esi), %xmm0\n" /* line 201 */
        "ucomiss 0x14(%ecx), %xmm0\n"
        "ja .Lf62e1c_00063040\n"
        "movss 0x70(%esi), %xmm0\n" /* line 203 */
        "ucomiss 0x18(%ecx), %xmm0\n"
        "ja .Lf62e1c_00063040\n"
        "movss (%ecx), %xmm0\n" /* line 205 */
        "ucomiss 0x74(%esi), %xmm0\n"
        "ja .Lf62e1c_00063040\n"
        "movss 4(%ecx), %xmm0\n" /* line 207 */
        "ucomiss 0x78(%esi), %xmm0\n"
        "ja .Lf62e1c_00063040\n"
        "movss 8(%ecx), %xmm0\n" /* line 209 */
        "ucomiss 0x7c(%esi), %xmm0\n"
        "ja .Lf62e1c_00063040\n"
        "movl 0x20(%ecx), %edx\n" /* line 214 */
        "movl 0x1c(%ecx), %eax\n" /* line 215 */
        "movl %eax, -0x20(%ebp)\n" /* i */
        "testl %eax, %eax\n" /* line 218 */
        "je .Lf62e1c_0006302c\n"
        "movl (%edx), %eax\n" /* line 220 */
        "movss 0x90(%esi), %xmm0\n" /* line 227 */
        "movss %xmm0, -0x24(%ebp)\n"
        "movss 0x8c(%esi), %xmm7\n" /* line 228 */
        "movss (%esi), %xmm6\n" /* line 304 | tw */
        "movss 4(%esi), %xmm5\n" /* tw */
        "movss 8(%esi), %xmm4\n" /* tw */
        "movaps %xmm6, %xmm1\n" /* line 236 */
        "mulss (%eax), %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x24(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+192, %xmm3\n"
        "andps %xmm3, %xmm0\n"
        "movaps %xmm7, %xmm2\n"
        "addss 0xc(%eax), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf62e1c_00063040\n"
        "addl $8, %edx\n"
        "movl $0, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* i */
        "subl $1, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf62e1c_00063024\n"
        ".Lf62e1c_00062fd6:\n"
        "movl (%edx), %eax\n" /* line 220 */
        "addl $1, -0x1c(%ebp)\n"
        "addl $8, %edx\n"
        "movaps %xmm6, %xmm1\n" /* line 236 */
        "mulss (%eax), %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x24(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "andps %xmm3, %xmm0\n"
        "movaps %xmm7, %xmm2\n"
        "addss 0xc(%eax), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf62e1c_00063040\n"
        ".Lf62e1c_00063024:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 218 */
        "cmpl %eax, -0x2c(%ebp)\n"
        "jne .Lf62e1c_00062fd6\n"
        ".Lf62e1c_0006302c:\n"
        "movb $1, 0x22(%edi)\n" /* line 241 */
        "movb $1, 0x23(%edi)\n"
        "movl $0, (%edi)\n" /* line 242 */
        "movl 0xc(%ecx), %eax\n" /* line 243 */
        "movl %eax, 0x14(%edi)\n"
        /* } scope */
        ".Lf62e1c_00063040:\n"
        "cmpb $0, 0x22(%edi)\n" /* line 278 | trace */
        "jne .Lf62e1c_00062e79\n"
        ".Lf62e1c_0006304a:\n"
        "addl $1, -0x28(%ebp)\n" /* line 270 | k */
        "movswl 2(%ebx), %eax\n" /* node */
        "cmpl %eax, -0x28(%ebp)\n" /* k */
        "jge .Lf62e1c_00062e79\n"
        "movl 0x80(%esi), %edx\n" /* tw */
        "jmp .Lf62e1c_00062ec1\n"
    );
}

/* line 1533 */
static __attribute__((naked))
int CM_SightTraceThroughBrush(cbrush_t *brush)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1533 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl %eax, %ebx\n" /* tw */
        "movl %edx, -0x30(%ebp)\n"
        /* { scope 1 */
        "pxor %xmm7, %xmm7\n" /* line 1563 */
        "movaps %xmm7, %xmm5\n"
        "movss lit4_002ed5d0, %xmm6\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm4\n" /* -1.0f */
        "xorl %edi, %edi\n" /* index */
        "movl %edx, %esi\n" /* i */
        "addl $0x10, %esi\n" /* i */
        ".Lf63066_00063092:\n"
        "movl %ebx, %eax\n" /* tw */
        "movl $1, %ecx\n"
        ".Lf63066_00063099:\n"
        "movss -4(%edx, %ecx, 4), %xmm0\n" /* line 1574 */
        "movss 0x94(%eax), %xmm1\n"
        "movss (%eax), %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "mulss %xmm4, %xmm3\n"
        "subss %xmm1, %xmm3\n"
        "movss 0xc(%eax), %xmm2\n" /* line 1575 */
        "subss %xmm0, %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "ucomiss %xmm5, %xmm3\n" /* line 1579 */
        "jbe .Lf63066_00063119\n"
        "ucomiss %xmm5, %xmm2\n" /* line 1581 */
        "ja .Lf63066_000632be\n"
        "movaps %xmm3, %xmm1\n" /* line 1584 */
        "mulss 0x18(%eax), %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "ucomiss %xmm6, %xmm1\n" /* line 1585 */
        "jae .Lf63066_000632be\n"
        "movaps %xmm7, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm5\n"
        "ja .Lf63066_00063158\n"
        ".Lf63066_000630f7:\n"
        "addl $1, %ecx\n"
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 1572 */
        "jne .Lf63066_00063099\n"
        "testl %edi, %edi\n" /* line 1598 | index */
        "jne .Lf63066_0006315d\n"
        "movl %esi, %edx\n" /* line 1601 | i */
        "movw $1, %di\n" /* index */
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f */
        "jmp .Lf63066_00063092\n"
        ".Lf63066_00063119:\n"
        "pxor %xmm0, %xmm0\n" /* line 1589 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf63066_000630f7\n"
        "movaps %xmm3, %xmm1\n" /* line 1591 */
        "mulss 0x18(%eax), %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "ucomiss %xmm1, %xmm7\n" /* line 1592 */
        "jae .Lf63066_000632be\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm6, %xmm0\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm6, %xmm2\n"
        "cmpnltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm6\n"
        "jmp .Lf63066_000630f7\n"
        ".Lf63066_00063158:\n"
        "movaps %xmm1, %xmm7\n"
        "jmp .Lf63066_000630f7\n"
        ".Lf63066_0006315d:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1605 */
        "movl 0x20(%eax), %ecx\n"
        "movl 0x1c(%eax), %esi\n" /* line 1606 | i */
        "testl %esi, %esi\n" /* line 1609 | i */
        "je .Lf63066_000632c8\n"
        "movss 0x90(%ebx), %xmm0\n" /* line 1618 | tw */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 0x8c(%ebx), %xmm1\n" /* line 1619 | tw */
        "movss %xmm1, -0x28(%ebp)\n"
        "movss (%ebx), %xmm2\n" /* line 304 */
        "movss %xmm2, -0x24(%ebp)\n"
        "movss 4(%ebx), %xmm3\n"
        "movss %xmm3, -0x20(%ebp)\n"
        "movss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal 0xc(%ebx), %eax\n" /* line 1624 | tw, a */
        /* { scope 2 */
        "movss 0xc(%ebx), %xmm1\n" /* line 304 */
        "movss %xmm1, -0x18(%ebp)\n"
        "movss 4(%eax), %xmm2\n"
        "movss %xmm2, -0x14(%ebp)\n"
        "movss 8(%eax), %xmm3\n"
        "movss %xmm3, -0x10(%ebp)\n"
        "xorl %edx, %edx\n"
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+208, %xmm5\n"
        "jmp .Lf63066_00063210\n"
        /* } scope */
        ".Lf63066_000631d2:\n"
        "movaps %xmm4, %xmm1\n" /* line 1630 */
        "subss %xmm0, %xmm1\n"
        "pxor %xmm2, %xmm2\n" /* line 1632 */
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lf63066_000632be\n"
        "movaps %xmm7, %xmm0\n" /* line 1635 */
        "mulss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "jbe .Lf63066_00063202\n"
        "movaps %xmm4, %xmm7\n" /* line 1637 */
        "divss %xmm1, %xmm7\n"
        "ucomiss %xmm6, %xmm7\n" /* line 1638 */
        "jae .Lf63066_000632be\n"
        ".Lf63066_00063202:\n"
        "addl $8, %ecx\n" /* line 1609 */
        "addl $1, %edx\n"
        "cmpl %edx, %esi\n" /* i */
        "je .Lf63066_000632fc\n"
        ".Lf63066_00063210:\n"
        "movl (%ecx), %eax\n" /* line 1611 */
        "movss -0x2c(%ebp), %xmm3\n" /* line 1619 */
        "mulss 8(%eax), %xmm3\n"
        "andps %xmm5, %xmm3\n"
        "movss -0x28(%ebp), %xmm0\n"
        "addss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss 4(%eax), %xmm1\n" /* line 304 */
        "movss 8(%eax), %xmm2\n"
        "movss -0x24(%ebp), %xmm4\n" /* line 1623 */
        "mulss (%eax), %xmm4\n"
        "movss -0x20(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "subss %xmm3, %xmm4\n"
        "movss -0x18(%ebp), %xmm0\n" /* line 1624 */
        "mulss (%eax), %xmm0\n"
        "mulss -0x14(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss -0x10(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "pxor %xmm1, %xmm1\n" /* line 1628 */
        "ucomiss %xmm1, %xmm4\n"
        "ja .Lf63066_000631d2\n"
        "pxor %xmm3, %xmm3\n" /* line 1642 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf63066_00063202\n"
        "movaps %xmm4, %xmm1\n" /* line 1644 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm6, %xmm0\n" /* line 1646 */
        "mulss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "jbe .Lf63066_00063202\n"
        "movaps %xmm4, %xmm6\n" /* line 1648 */
        "divss %xmm1, %xmm6\n"
        "ucomiss %xmm6, %xmm7\n" /* line 1649 */
        "jb .Lf63066_00063202\n"
        ".Lf63066_000632be:\n"
        "xorl %eax, %eax\n" /* line 1655 */
        /* } scope */
        "addl $0x24, %esp\n" /* line 1656 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf63066_000632c8:\n"
        "movl %eax, %ecx\n"
        /* { scope 1 */
        ".Lf63066_000632ca:\n"
        "movl imp_cm, %eax\n" /* line 1655 */
        "subl 0x80(%eax), %ecx\n"
        "sarl $4, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal 1(%ecx, %eax, 2), %eax\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 1656 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf63066_000632fc:\n"
        "movl -0x30(%ebp), %ecx\n"
        "jmp .Lf63066_000632ca\n"
    );
}

/* line 1666 */
static __attribute__((naked))
int CM_SightTraceThroughLeafBrushNode_r(const vec_t *p2)
{
    __asm__ __volatile__ (
        ".Lf63302_00063302:\n"
        "pushl %ebp\n" /* line 1666 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %esi\n" /* tw */
        "movl %edx, %ebx\n" /* node */
        "movl 8(%ebp), %edi\n" /* p2 */
        /* { scope 1 */
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n" /* p1 */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf63302_00063323:\n"
        "movl 0x80(%esi), %ecx\n" /* line 1692 | tw, p1_ */
        "testl %ecx, 4(%ebx)\n" /* p1_, node */
        "je .Lf63302_000633e9\n"
        ".Lf63302_00063332:\n"
        "cmpw $0, 2(%ebx)\n" /* line 1695 | node */
        "je .Lf63302_00063357\n"
        "jg .Lf63302_000635aa\n" /* line 1697 */
        "leal -0x24(%ebp), %ecx\n" /* line 1714 | p1, p1_ */
        "leal 0x14(%ebx), %edx\n" /* node */
        "movl %edi, (%esp)\n" /* k */
        "movl %esi, %eax\n" /* tw */
        "calll CM_SightTraceThroughLeafBrushNode_r\n"
        "testl %eax, %eax\n" /* line 1715 */
        "jne .Lf63302_000633eb\n"
        ".Lf63302_00063357:\n"
        "movzbl (%ebx), %eax\n" /* line 1719 | node */
        "movss 8(%ebx), %xmm1\n" /* node */
        "movss -0x24(%ebp, %eax, 4), %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movss (%edi, %eax, 4), %xmm0\n" /* line 1720 | k */
        "subss %xmm1, %xmm0\n"
        "movss lit4_002ed610, %xmm3\n" /* line 1721 | 0.125f */
        "addss 0x5c(%esi, %eax, 4), %xmm3\n" /* tw */
        "subss 0xc(%ebx), %xmm3\n" /* node */
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "subss %xmm0, %xmm1\n"
        "pxor %xmm6, %xmm6\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm6, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movaps %xmm0, %xmm5\n" /* line 166 | comparand */
        "subss %xmm2, %xmm5\n" /* comparand */
        /* { scope 2 */
        "movaps %xmm5, %xmm7\n" /* line 45 */
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm6, %xmm7\n"
        "andps %xmm7, %xmm4\n"
        "andnps %xmm0, %xmm7\n"
        "orps %xmm4, %xmm7\n"
        "movaps %xmm7, %xmm0\n"
        /* } scope */
        "ucomiss %xmm3, %xmm0\n" /* line 1725 */
        "jb .Lf63302_000633f3\n"
        "xorps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+224, %xmm3\n" /* line 1727 */
        "ucomiss %xmm1, %xmm3\n"
        "jae .Lf63302_000633e9\n"
        "movzwl 0x10(%ebx), %eax\n" /* line 1730 | node */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* node */
        "movl 0x80(%esi), %ecx\n" /* line 1692 | tw, p1_ */
        "testl %ecx, 4(%ebx)\n" /* p1_, node */
        "jne .Lf63302_00063332\n"
        ".Lf63302_000633e9:\n"
        "xorl %eax, %eax\n" /* line 1777 */
        /* } scope */
        ".Lf63302_000633eb:\n"
        "addl $0x6c, %esp\n" /* line 1778 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf63302_000633f3:\n"
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+224, %xmm4\n" /* line 1734 */
        "movaps %xmm3, %xmm0\n"
        "xorps %xmm4, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf63302_00063415\n"
        "movzwl 0x12(%ebx), %eax\n" /* line 1736 | node */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* node */
        "jmp .Lf63302_00063323\n"
        ".Lf63302_00063415:\n"
        "movaps %xmm5, %xmm1\n" /* line 54 */
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+240, %xmm1\n"
        "ucomiss lit4_002ed6a0, %xmm1\n" /* line 1743 | 4.76837158203125e-07f */
        "ja .Lf63302_0006354e\n"
        "movaps %xmm6, %xmm4\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm7\n"
        "movl $0, -0x3c(%ebp)\n" /* side */
        "movaps %xmm6, %xmm0\n"
        "movl -0x3c(%ebp), %eax\n" /* side */
        ".Lf63302_00063447:\n"
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "cmpnltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm7, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 1761 | p1 */
        "movss (%edi), %xmm0\n" /* k */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* mid */
        "movss -0x20(%ebp), %xmm1\n" /* line 1762 */
        "movss 4(%edi), %xmm0\n" /* k */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 1763 */
        "movss 8(%edi), %xmm0\n" /* k */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "leal -0x24(%ebp), %ecx\n" /* line 1765 | p1, p1_ */
        "movzwl 0x10(%ebx, %eax, 2), %edx\n" /* node */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%ebx, %edx, 4), %edx\n" /* node */
        "leal -0x30(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "movl %esi, %eax\n" /* tw */
        "movss %xmm4, -0x58(%ebp)\n"
        "movss %xmm6, -0x68(%ebp)\n"
        "calll CM_SightTraceThroughLeafBrushNode_r\n"
        "testl %eax, %eax\n" /* line 1766 */
        "movss -0x58(%ebp), %xmm4\n"
        "movss -0x68(%ebp), %xmm6\n"
        "jne .Lf63302_000633eb\n"
        "maxss %xmm4, %xmm6\n" /* line 45 */
        "movaps %xmm6, %xmm4\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 1772 | p1 */
        "movss (%edi), %xmm0\n" /* k */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* p1 */
        "movss -0x20(%ebp), %xmm1\n" /* line 1773 */
        "movss 4(%edi), %xmm0\n" /* k */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 1774 */
        "movss 8(%edi), %xmm0\n" /* k */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movb $1, %al\n" /* line 1776 */
        "subl -0x3c(%ebp), %eax\n" /* side */
        "movzwl 0x10(%ebx, %eax, 2), %eax\n" /* node */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* node */
        "jmp .Lf63302_00063323\n"
        ".Lf63302_0006354e:\n"
        "movaps %xmm2, %xmm0\n" /* line 1745 */
        "xorps %xmm4, %xmm0\n"
        "movaps %xmm5, %xmm7\n" /* line 45 */
        "movaps %xmm0, %xmm4\n"
        "cmpnltss %xmm6, %xmm7\n"
        "andps %xmm7, %xmm4\n"
        "andnps %xmm2, %xmm7\n"
        "orps %xmm4, %xmm7\n"
        "movaps %xmm7, %xmm0\n"
        "movss lit4_002ed5d0, %xmm7\n" /* line 1746 | 1.0f */
        "movaps %xmm7, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "movaps %xmm0, %xmm4\n" /* line 1747 */
        "subss %xmm3, %xmm4\n"
        "mulss %xmm2, %xmm4\n"
        "movaps %xmm0, %xmm2\n" /* line 1748 */
        "addss %xmm3, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "xorl %eax, %eax\n" /* line 96 */
        "ucomiss %xmm5, %xmm6\n"
        "setbe %al\n"
        "movl %eax, -0x3c(%ebp)\n" /* side */
        "movaps %xmm7, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "jmp .Lf63302_00063447\n"
        ".Lf63302_000635aa:\n"
        "cmpw $0, 2(%ebx)\n" /* line 1699 | node */
        "jle .Lf63302_000633e9\n"
        "xorl %edi, %edi\n" /* k */
        "jmp .Lf63302_000635ce\n"
        ".Lf63302_000635b9:\n"
        "addl $1, %edi\n" /* k */
        "movswl 2(%ebx), %eax\n" /* node */
        "cmpl %edi, %eax\n" /* k */
        "jle .Lf63302_000633e9\n"
        "movl 0x80(%esi), %ecx\n" /* tw, p1_ */
        ".Lf63302_000635ce:\n"
        "movl 8(%ebx), %eax\n" /* line 1702 | node */
        "movzwl (%eax, %edi, 2), %eax\n"
        "leal (%eax, %eax, 2), %edx\n"
        "shll $4, %edx\n"
        "movl imp_cm, %eax\n"
        "addl 0x80(%eax), %edx\n"
        "testl %ecx, 0xc(%edx)\n" /* line 1703 | p1_ */
        "je .Lf63302_000635b9\n"
        "movl %esi, %eax\n" /* line 1706 | tw */
        "calll CM_SightTraceThroughBrush\n"
        "testl %eax, %eax\n" /* line 1707 */
        "je .Lf63302_000635b9\n"
        "jmp .Lf63302_000633eb\n"
    );
}

/* line 1807 */
static __attribute__((naked))
int CM_SightTraceThroughLeaf(trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1807 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, %edi\n" /* tw */
        "movl %edx, %esi\n" /* leaf */
        "movl %ecx, -0x3c(%ebp)\n"
        /* { scope 1: absmin, absmax */
        "movl 0x80(%eax), %eax\n" /* line 1812 */
        "testl %eax, 4(%edx)\n"
        "jne .Lf635fc_00063631\n"
        ".Lf635fc_00063617:\n"
        "testl %eax, 8(%esi)\n" /* line 1823 | leaf */
        "je .Lf635fc_00063627\n"
        "cmpw $0, 2(%esi)\n" /* line 1826 | leaf */
        "jne .Lf635fc_000636be\n"
        ".Lf635fc_00063627:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf635fc_00063629:\n"
        "addl $0x4c, %esp\n" /* line 1839 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: absmin, absmax */
        /* { scope 2 */
        ".Lf635fc_00063631:\n"
        "leal 0xc(%edx), %eax\n" /* line 1793 | a */
        /* { scope 3 */
        "movss 0xc(%edx), %xmm0\n" /* line 248 */
        "subss 0x5c(%edi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* absmin */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 0x60(%edi), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 0x64(%edi), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal 0x18(%edx), %eax\n"
        /* } scope */
        /* { scope 3 */
        "movss 0x18(%edx), %xmm0\n" /* line 240 */
        "addss 0x5c(%edi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* absmax */
        "movss 4(%eax), %xmm0\n" /* line 241 */
        "addss 0x60(%edi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "addss 0x64(%edi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "movl $0x3f800000, 0xc(%esp)\n" /* line 1795 */
        "leal -0x30(%ebp), %eax\n" /* absmax */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* absmin */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CM_TraceBox\n"
        "testl %eax, %eax\n"
        "je .Lf635fc_00063706\n"
        ".Lf635fc_000636b3:\n"
        "movl 0x80(%edi), %eax\n"
        "jmp .Lf635fc_00063617\n"
        /* } scope */
        ".Lf635fc_000636be:\n"
        "xorl %ebx, %ebx\n" /* line 1826 | k */
        ".Lf635fc_000636c0:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1828 */
        "movl %eax, 8(%esp)\n"
        "movzwl (%esi), %eax\n" /* leaf */
        "addl %ebx, %eax\n" /* k */
        "shll $5, %eax\n"
        "movl imp_cm, %edx\n"
        "addl 0x70(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* tw */
        "calll CM_SightTraceThroughAabbTree\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1829 | 1.0f */
        "movl -0x3c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "jne .Lf635fc_0006372f\n"
        "jp .Lf635fc_0006372f\n"
        "addl $1, %ebx\n" /* line 1826 | k */
        "movzwl 2(%esi), %eax\n" /* leaf */
        "cmpl %eax, %ebx\n" /* k */
        "jl .Lf635fc_000636c0\n"
        "jmp .Lf635fc_00063627\n"
        /* { scope 2 */
        ".Lf635fc_00063706:\n"
        "movl 0x24(%esi), %edx\n" /* line 1798 */
        "leal (%edx, %edx, 4), %edx\n"
        "movl imp_cm, %eax\n"
        "movl 0x30(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "leal 0xc(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "movl %edi, %ecx\n"
        "movl %edi, %eax\n"
        "calll CM_SightTraceThroughLeafBrushNode_r\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1817 */
        "je .Lf635fc_000636b3\n"
        "jmp .Lf635fc_00063629\n"
        ".Lf635fc_0006372f:\n"
        "movl imp_cm, %edx\n" /* line 1832 */
        "movzwl 0x7c(%edx), %eax\n"
        "movzwl (%esi), %edx\n" /* leaf */
        "addl %edx, %eax\n"
        "leal 1(%ebx, %eax), %eax\n" /* k */
        "jmp .Lf635fc_00063629\n"
    );
}

/* line 705 */
static __attribute__((naked))
int CM_TraceThroughLeafBrushNode_r(const vec_t *p2, trace_t *trace)
{
    __asm__ __volatile__ (
        ".Lf63748_00063748:\n"
        "pushl %ebp\n" /* line 705 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "movl %eax, %edi\n" /* tw */
        "movl %edx, %ebx\n" /* node */
        "movl 8(%ebp), %esi\n" /* p2 */
        /* { scope 1: enterFrac, allsolid, leadside, bounds, ... */
        "movl (%ecx), %eax\n" /* line 456 */
        "movl %eax, -0x30(%ebp)\n" /* p1 */
        "movl 4(%ecx), %eax\n" /* line 457 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 458 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 0xc(%ecx), %eax\n" /* line 459 */
        "movl %eax, -0x24(%ebp)\n"
        ".Lf63748_00063772:\n"
        "movl 0x80(%edi), %edx\n" /* line 730 | tw */
        "testl %edx, 4(%ebx)\n" /* node */
        "je .Lf63748_00063837\n"
        ".Lf63748_00063781:\n"
        "cmpw $0, 2(%ebx)\n" /* line 733 | node */
        "je .Lf63748_000637a5\n"
        "jg .Lf63748_00063a64\n" /* line 735 */
        "leal -0x30(%ebp), %ecx\n" /* line 750 | p1, p1_ */
        "leal 0x14(%ebx), %edx\n" /* node */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* p2 */
        "movl %edi, %eax\n" /* tw */
        "calll CM_TraceThroughLeafBrushNode_r\n"
        ".Lf63748_000637a5:\n"
        "movzbl (%ebx), %eax\n" /* line 753 | node */
        "movss 8(%ebx), %xmm1\n" /* node */
        "movss -0x30(%ebp, %eax, 4), %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movss (%esi, %eax, 4), %xmm0\n" /* line 754 | p2 */
        "subss %xmm1, %xmm0\n"
        "movss lit4_002ed610, %xmm3\n" /* line 755 | 0.125f */
        "addss 0x5c(%edi, %eax, 4), %xmm3\n" /* tw */
        "subss 0xc(%ebx), %xmm3\n" /* node */
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "subss %xmm0, %xmm1\n"
        "pxor %xmm7, %xmm7\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm7, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movaps %xmm0, %xmm4\n" /* line 166 | comparand */
        "subss %xmm2, %xmm4\n" /* comparand */
        /* { scope 2 */
        "movaps %xmm4, %xmm5\n" /* line 45 */
        "movaps %xmm2, %xmm6\n"
        "cmpnltss %xmm7, %xmm5\n"
        "andps %xmm5, %xmm6\n"
        "andnps %xmm0, %xmm5\n"
        "orps %xmm6, %xmm5\n"
        "movaps %xmm5, %xmm0\n"
        /* } scope */
        "ucomiss %xmm0, %xmm3\n" /* line 759 */
        "ja .Lf63748_00063842\n"
        "xorps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+272, %xmm3\n" /* line 761 */
        "ucomiss %xmm3, %xmm1\n"
        "jbe .Lf63748_00063837\n"
        "movzwl 0x10(%ebx), %eax\n" /* line 764 | node */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* node */
        "movl 0x80(%edi), %edx\n" /* line 730 | tw */
        "testl %edx, 4(%ebx)\n" /* node */
        "jne .Lf63748_00063781\n"
        /* } scope */
        ".Lf63748_00063837:\n"
        "addl $0xec, %esp\n" /* line 815 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: enterFrac, allsolid, leadside, bounds, ... */
        ".Lf63748_00063842:\n"
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+272, %xmm5\n" /* line 768 */
        "movaps %xmm3, %xmm0\n"
        "xorps %xmm5, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf63748_00063864\n"
        "movzwl 0x12(%ebx), %eax\n" /* line 770 | node */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* node */
        "jmp .Lf63748_00063772\n"
        ".Lf63748_00063864:\n"
        "movss -0x24(%ebp), %xmm6\n" /* line 774 */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm6, %xmm0\n"
        "jbe .Lf63748_00063837\n"
        "movaps %xmm4, %xmm0\n" /* line 54 */
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+256, %xmm0\n"
        "movss %xmm0, -0xdc(%ebp)\n" /* absDiff */
        "ucomiss lit4_002ed6a0, %xmm0\n" /* line 780 | 4.76837158203125e-07f */
        "ja .Lf63748_000639ef\n"
        "movaps %xmm7, %xmm5\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "xorl %eax, %eax\n"
        "movaps %xmm7, %xmm0\n"
        "movl $1, -0x60(%ebp)\n"
        "movaps %xmm2, %xmm3\n"
        ".Lf63748_000638ae:\n"
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "cmpnltss %xmm7, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 798 | p1 */
        "movss (%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n" /* mid */
        "movss -0x2c(%ebp), %xmm1\n" /* line 799 */
        "movss 4(%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 800 */
        "movss 8(%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movss 0xc(%esi), %xmm0\n" /* line 801 | p2 */
        "subss %xmm6, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm6\n"
        "movss %xmm6, -0x34(%ebp)\n"
        "leal -0x30(%ebp), %ecx\n" /* line 803 | p1, p1_ */
        "movzwl 0x10(%ebx, %eax, 2), %edx\n" /* node */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%ebx, %edx, 4), %edx\n" /* node */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "movl %edi, %eax\n" /* tw */
        "movss %xmm5, -0xb8(%ebp)\n"
        "movss %xmm7, -0xc8(%ebp)\n"
        "calll CM_TraceThroughLeafBrushNode_r\n"
        "movss -0xb8(%ebp), %xmm5\n" /* line 45 */
        "movss -0xc8(%ebp), %xmm7\n"
        "maxss %xmm5, %xmm7\n"
        "movaps %xmm7, %xmm5\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 808 | p1 */
        "movss (%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* p1 */
        "movss -0x2c(%ebp), %xmm1\n" /* line 809 */
        "movss 4(%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 810 */
        "movss 8(%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 811 */
        "movss 0xc(%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movl -0x60(%ebp), %edx\n" /* line 813 */
        "movzwl 0x10(%ebx, %edx, 2), %eax\n" /* node */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* node */
        "jmp .Lf63748_00063772\n"
        ".Lf63748_000639ef:\n"
        "movaps %xmm2, %xmm1\n" /* line 782 */
        "xorps %xmm5, %xmm1\n"
        "movaps %xmm4, %xmm5\n" /* line 45 */
        "movaps %xmm1, %xmm0\n"
        "cmpnltss %xmm7, %xmm5\n"
        "andps %xmm5, %xmm0\n"
        "andnps %xmm2, %xmm5\n"
        "orps %xmm0, %xmm5\n"
        "movss %xmm5, -0xcc(%ebp)\n" /* t */
        "movss lit4_002ed5d0, %xmm1\n" /* line 783 | 1.0f */
        "divss -0xdc(%ebp), %xmm1\n" /* absDiff */
        "subss %xmm3, %xmm5\n" /* line 784 */
        "mulss %xmm1, %xmm5\n"
        "movss -0xcc(%ebp), %xmm2\n" /* line 785 | t */
        "addss %xmm3, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "xorl %eax, %eax\n" /* line 96 */
        "ucomiss %xmm4, %xmm7\n"
        "setbe %al\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movl $1, -0x60(%ebp)\n"
        "subl %eax, -0x60(%ebp)\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "jmp .Lf63748_000638ae\n"
        ".Lf63748_00063a64:\n"
        "cmpw $0, 2(%ebx)\n" /* line 737 | node */
        "jle .Lf63748_00063837\n"
        "movl $0, -0x98(%ebp)\n" /* k */
        ".Lf63748_00063a79:\n"
        "movl 8(%ebx), %eax\n" /* line 740 | node */
        "movl -0x98(%ebp), %ecx\n" /* k, p1_ */
        "movzwl (%eax, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl imp_cm, %esi\n" /* p2 */
        "movl 0x80(%esi), %esi\n" /* p2 */
        "addl %esi, %eax\n" /* p2 */
        "movl %eax, -0x5c(%ebp)\n"
        "testl %edx, 0xc(%eax)\n" /* line 741 */
        "je .Lf63748_00063cdc\n"
        "movl %eax, %edx\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 519 | trace */
        "movss (%eax), %xmm6\n"
        "movl %edx, -0x80(%ebp)\n" /* line 526 | bounds */
        "pxor %xmm7, %xmm7\n"
        "movss %xmm7, -0x8c(%ebp)\n" /* enterFrac */
        "movl $1, -0x88(%ebp)\n" /* allsolid */
        "movl $0, -0x84(%ebp)\n" /* leadside */
        "movss lit4_002ed5dc, %xmm4\n" /* -1.0f */
        "movl $0, -0x7c(%ebp)\n" /* index */
        "movl %edx, %ecx\n"
        "addl $0x10, %ecx\n"
        "movl %ecx, -0x9c(%ebp)\n"
        "movl %edx, %esi\n" /* i */
        ".Lf63748_00063aee:\n"
        "movl %edi, %edx\n"
        "movl -0x7c(%ebp), %eax\n" /* index */
        "addl %eax, %eax\n"
        "addl -0x7c(%ebp), %eax\n" /* index */
        "leal 0x24(%esi, %eax, 2), %ecx\n" /* i */
        "movl $1, %esi\n" /* i */
        ".Lf63748_00063b01:\n"
        "movl -0x80(%ebp), %eax\n" /* line 542 | bounds */
        "movss -4(%eax, %esi, 4), %xmm0\n"
        "movss 0x94(%edx), %xmm1\n"
        "movss (%edx), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movss 0xc(%edx), %xmm3\n" /* line 543 */
        "subss %xmm0, %xmm3\n"
        "mulss %xmm4, %xmm3\n"
        "subss %xmm1, %xmm3\n"
        "ucomiss %xmm7, %xmm2\n" /* line 547 */
        "jbe .Lf63748_00063c1d\n"
        "movss lit4_002ed610, %xmm1\n" /* line 45 | 0.125f */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movaps %xmm2, %xmm5\n"
        "cmpnltss %xmm7, %xmm0\n"
        "andps %xmm0, %xmm5\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm5, %xmm0\n"
        "ucomiss %xmm3, %xmm0\n" /* line 550 */
        "jbe .Lf63748_00063cdc\n"
        "movaps %xmm2, %xmm0\n" /* line 556 */
        "subss %xmm1, %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "ucomiss %xmm0, %xmm6\n" /* line 558 */
        "jbe .Lf63748_00063cdc\n"
        "ucomiss %xmm7, %xmm3\n" /* line 564 */
        "movl $0, %eax\n"
        "cmovbel -0x88(%ebp), %eax\n" /* allsolid */
        "movl %eax, -0x88(%ebp)\n" /* allsolid */
        "ucomiss -0x8c(%ebp), %xmm0\n" /* line 567 | enterFrac */
        "jbe .Lf63748_00063c11\n"
        "movss %xmm0, -0x8c(%ebp)\n" /* enterFrac */
        ".Lf63748_00063ba4:\n"
        "movswl (%ecx), %eax\n" /* line 572 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x54(%ebp)\n" /* line 183 | axialPlane */
        "movl $0, -0x50(%ebp)\n" /* line 184 */
        "movl $0, -0x4c(%ebp)\n" /* line 185 */
        "movss %xmm4, -0x58(%ebp, %esi, 4)\n" /* line 574 */
        "leal -0x54(%ebp), %eax\n" /* line 575 | axialPlane */
        "movl %eax, -0x20(%ebp)\n" /* axialSide */
        "leal -0x20(%ebp), %eax\n" /* axialSide */
        "movl %eax, -0x84(%ebp)\n" /* leadside */
        ".Lf63748_00063bd4:\n"
        "addl $1, %esi\n" /* line 45 */
        "addl $4, %edx\n"
        "addl $2, %ecx\n"
        "cmpl $4, %esi\n" /* line 540 | i */
        "jne .Lf63748_00063b01\n"
        "movl -0x7c(%ebp), %eax\n" /* line 592 | index */
        "testl %eax, %eax\n"
        "jne .Lf63748_00063d10\n"
        "movl -0x9c(%ebp), %eax\n" /* line 595 */
        "movl %eax, -0x80(%ebp)\n" /* bounds */
        "movl $1, -0x7c(%ebp)\n" /* index */
        "movss lit4_002ed5d0, %xmm4\n" /* line 535 | 1.0f */
        "movl -0x5c(%ebp), %esi\n" /* i */
        "jmp .Lf63748_00063aee\n"
        ".Lf63748_00063c11:\n"
        "movl -0x84(%ebp), %eax\n" /* line 569 | leadside */
        "testl %eax, %eax\n"
        "jne .Lf63748_00063bd4\n"
        "jmp .Lf63748_00063ba4\n"
        ".Lf63748_00063c1d:\n"
        "pxor %xmm0, %xmm0\n" /* line 578 */
        "ucomiss %xmm0, %xmm3\n"
        "jbe .Lf63748_00063bd4\n"
        "movaps %xmm2, %xmm1\n" /* line 580 */
        "mulss 0x18(%edx), %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "ucomiss -0x8c(%ebp), %xmm1\n" /* line 582 | enterFrac */
        "jbe .Lf63748_00063cdc\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm6, %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf63748_00063cfe\n"
        "movl $0, -0x88(%ebp)\n" /* allsolid */
        "jmp .Lf63748_00063bd4\n"
        ".Lf63748_00063c62:\n"
        "movl %ecx, %edx\n"
        ".Lf63748_00063c64:\n"
        "movl 0xc(%edx), %eax\n" /* line 673 */
        "movl 0xc(%ebp), %ecx\n" /* trace */
        "movl %eax, 0x14(%ecx)\n"
        "movl -0x84(%ebp), %edx\n" /* line 679 | leadside */
        "testl %edx, %edx\n"
        "je .Lf63748_00063eeb\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 690 | enterFrac */
        "movl 0xc(%ebp), %esi\n" /* trace, i */
        "movss %xmm0, (%esi)\n" /* i */
        "movl %esi, %ecx\n" /* line 692 | i, to */
        "addl $4, %ecx\n" /* to */
        "movl -0x84(%ebp), %eax\n" /* leadside */
        "movl (%eax), %edx\n" /* from */
        /* { scope 3 */
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, 4(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl -0x84(%ebp), %edx\n" /* line 693 | leadside */
        "movl 4(%edx), %eax\n"
        "movl imp_cm, %ecx\n"
        "movl 0x10(%ecx), %edx\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl 0x40(%edx, %eax, 8), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* i */
        "movl -0x84(%ebp), %esi\n" /* line 694 | leadside, i */
        "movl 4(%esi), %eax\n" /* i */
        "leal (%eax, %eax, 8), %eax\n"
        "movl 0x10(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* trace */
        "movl %eax, 0x18(%edx)\n"
        /* } scope */
        ".Lf63748_00063cdc:\n"
        "addl $1, -0x98(%ebp)\n" /* line 737 | k */
        "movswl 2(%ebx), %eax\n" /* node */
        "cmpl -0x98(%ebp), %eax\n" /* k */
        "jle .Lf63748_00063837\n"
        "movl 0x80(%edi), %edx\n" /* tw */
        "jmp .Lf63748_00063a79\n"
        /* { scope 2 */
        ".Lf63748_00063cfe:\n"
        "movaps %xmm1, %xmm6\n" /* line 45 */
        "movl $0, -0x88(%ebp)\n" /* allsolid */
        "jmp .Lf63748_00063bd4\n"
        ".Lf63748_00063d10:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 599 */
        "movl 0x20(%ecx), %edx\n"
        "movl 0x1c(%ecx), %esi\n" /* line 600 | i */
        "testl %esi, %esi\n" /* line 603 | i */
        "je .Lf63748_00063c62\n"
        "movss 0x90(%edi), %xmm0\n" /* line 612 */
        "movss %xmm0, -0x94(%ebp)\n"
        "movss 0x8c(%edi), %xmm1\n" /* line 613 */
        "movss %xmm1, -0x90(%ebp)\n"
        "movss (%edi), %xmm2\n" /* line 304 */
        "movss %xmm2, -0x78(%ebp)\n"
        "movss 4(%edi), %xmm3\n"
        "movss %xmm3, -0x74(%ebp)\n"
        "movss 8(%edi), %xmm4\n"
        "movss %xmm4, -0x70(%ebp)\n"
        "leal 0xc(%edi), %eax\n" /* line 618 | a */
        /* { scope 3 */
        "movss 0xc(%edi), %xmm5\n" /* line 304 */
        "movss %xmm5, -0x6c(%ebp)\n"
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "movss 8(%eax), %xmm1\n"
        "movss %xmm1, -0x64(%ebp)\n"
        "xorl %ecx, %ecx\n"
        "movaps %xmm2, %xmm5\n"
        "jmp .Lf63748_00063db4\n"
        /* } scope */
        ".Lf63748_00063d86:\n"
        "divss %xmm2, %xmm1\n" /* line 641 */
        "movss %xmm1, -0x8c(%ebp)\n" /* enterFrac */
        "ucomiss %xmm1, %xmm6\n" /* line 643 */
        "jbe .Lf63748_00063cdc\n"
        ".Lf63748_00063d9b:\n"
        "movl %edx, -0x84(%ebp)\n" /* line 663 | leadside */
        ".Lf63748_00063da1:\n"
        "addl $8, %edx\n" /* line 603 */
        "addl $1, %ecx\n"
        "cmpl %ecx, %esi\n" /* i */
        "je .Lf63748_00063ee3\n"
        "movss -0x78(%ebp), %xmm5\n"
        ".Lf63748_00063db4:\n"
        "movl (%edx), %eax\n" /* line 605 */
        "movss -0x94(%ebp), %xmm3\n" /* line 613 */
        "mulss 8(%eax), %xmm3\n"
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+256, %xmm3\n"
        "movss -0x90(%ebp), %xmm0\n"
        "addss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss 4(%eax), %xmm1\n" /* line 304 */
        "movss 8(%eax), %xmm2\n"
        "mulss (%eax), %xmm5\n" /* line 617 */
        "movss -0x74(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movss -0x70(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "subss %xmm3, %xmm5\n"
        "movss -0x6c(%ebp), %xmm4\n" /* line 618 */
        "mulss (%eax), %xmm4\n"
        "mulss -0x68(%ebp), %xmm1\n"
        "addss %xmm1, %xmm4\n"
        "mulss -0x64(%ebp), %xmm2\n"
        "addss %xmm2, %xmm4\n"
        "subss %xmm3, %xmm4\n"
        "ucomiss %xmm7, %xmm5\n" /* line 622 */
        "jbe .Lf63748_00063e9f\n"
        "movss lit4_002ed610, %xmm1\n" /* line 45 | 0.125f */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm5, %xmm0\n"
        "movaps %xmm5, %xmm2\n"
        "cmpnltss %xmm7, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "ucomiss %xmm4, %xmm0\n" /* line 625 */
        "jbe .Lf63748_00063cdc\n"
        "ucomiss %xmm7, %xmm4\n" /* line 631 */
        "movl $0, %eax\n"
        "cmovbel -0x88(%ebp), %eax\n" /* allsolid */
        "movl %eax, -0x88(%ebp)\n" /* allsolid */
        "movaps %xmm5, %xmm2\n" /* line 634 */
        "subss %xmm4, %xmm2\n"
        "subss %xmm1, %xmm5\n" /* line 638 */
        "movaps %xmm5, %xmm1\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 639 | enterFrac */
        "mulss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm5\n"
        "ja .Lf63748_00063d86\n"
        "movl -0x84(%ebp), %eax\n" /* line 649 | leadside */
        "testl %eax, %eax\n"
        "jne .Lf63748_00063da1\n"
        "jmp .Lf63748_00063d9b\n"
        ".Lf63748_00063e9f:\n"
        "pxor %xmm3, %xmm3\n" /* line 655 */
        "ucomiss %xmm3, %xmm4\n"
        "jbe .Lf63748_00063da1\n"
        "movaps %xmm5, %xmm1\n" /* line 657 */
        "subss %xmm4, %xmm1\n"
        "movaps %xmm6, %xmm0\n" /* line 659 */
        "mulss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm5\n"
        "ja .Lf63748_00063ece\n"
        ".Lf63748_00063ebf:\n"
        "movl $0, -0x88(%ebp)\n" /* line 663 | allsolid */
        "jmp .Lf63748_00063da1\n"
        ".Lf63748_00063ece:\n"
        "movaps %xmm5, %xmm6\n" /* line 661 */
        "divss %xmm1, %xmm6\n"
        "ucomiss -0x8c(%ebp), %xmm6\n" /* line 663 | enterFrac */
        "ja .Lf63748_00063ebf\n"
        "jmp .Lf63748_00063cdc\n"
        ".Lf63748_00063ee3:\n"
        "movl -0x5c(%ebp), %edx\n"
        "jmp .Lf63748_00063c64\n"
        ".Lf63748_00063eeb:\n"
        "movb $1, 0x23(%ecx)\n" /* line 681 */
        "movl -0x88(%ebp), %eax\n" /* line 682 | allsolid */
        "testl %eax, %eax\n"
        "je .Lf63748_00063cdc\n"
        "movb $1, 0x22(%ecx)\n" /* line 684 */
        "movl $0, (%ecx)\n" /* line 685 */
        "jmp .Lf63748_00063cdc\n"
    );
}

/* line 2055 */
static __attribute__((naked))
int CM_SightTraceThroughTree(const traceWork_t *tw, const vec_t *p2, trace_t *trace)
{
    __asm__ __volatile__ (
        ".Lf63f0c_00063f0c:\n"
        "pushl %ebp\n" /* line 2055 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%ebp), %esi\n" /* p2 */
        /* { scope 1 */
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* p1 */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "testl %edx, %edx\n" /* line 2077 */
        "js .Lf63f0c_00064223\n"
        "movl imp_cm, %ecx\n" /* p1_ */
        "jmp .Lf63f0c_00063f9c\n"
        ".Lf63f0c_00063f3c:\n"
        "movzbl %al, %eax\n" /* line 2090 */
        "movss 0xc(%edx), %xmm0\n"
        "movss -0x30(%ebp, %eax, 4), %xmm5\n"
        "subss %xmm0, %xmm5\n"
        "movss (%esi, %eax, 4), %xmm3\n" /* line 2091 | p2 */
        "subss %xmm0, %xmm3\n"
        "movss lit4_002ed610, %xmm6\n" /* line 2092 | 0.125f */
        "movl -0x3c(%ebp), %edx\n"
        "addss 0x5c(%edx, %eax, 4), %xmm6\n"
        ".Lf63f0c_00063f68:\n"
        "movaps %xmm3, %xmm4\n" /* line 166 | comparand */
        "subss %xmm5, %xmm4\n" /* comparand */
        /* { scope 2 */
        "pxor %xmm7, %xmm7\n" /* line 45 */
        "movaps %xmm4, %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "cmpnltss %xmm7, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        /* } scope */
        "ucomiss %xmm6, %xmm0\n" /* line 2105 */
        "jb .Lf63f0c_0006403e\n"
        ".Lf63f0c_00063f90:\n"
        "movswl 4(%ebx), %edx\n" /* line 2107 | node */
        ".Lf63f0c_00063f94:\n"
        "testl %edx, %edx\n" /* line 2077 */
        "js .Lf63f0c_00064075\n"
        ".Lf63f0c_00063f9c:\n"
        "movl 0x20(%ecx), %eax\n" /* line 2084 | p1_ */
        "leal (%eax, %edx, 8), %ebx\n" /* node */
        "movl (%ebx), %edx\n" /* line 2085 | node */
        "movzbl 0x10(%edx), %eax\n" /* line 2088 */
        "cmpb $2, %al\n"
        "jbe .Lf63f0c_00063f3c\n"
        "movss 4(%edx), %xmm1\n" /* line 304 */
        "movss 8(%edx), %xmm2\n"
        "movss 0xc(%edx), %xmm4\n" /* line 2096 */
        "movss (%edx), %xmm3\n"
        "movaps %xmm3, %xmm5\n"
        "mulss -0x30(%ebp), %xmm5\n" /* p1 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movaps %xmm2, %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "subss %xmm4, %xmm5\n"
        "mulss (%esi), %xmm3\n" /* line 2097 | p2 */
        "mulss 4(%esi), %xmm1\n" /* p2 */
        "addss %xmm1, %xmm3\n"
        "mulss 8(%esi), %xmm2\n" /* p2 */
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2098 */
        "movl 0x84(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf63f0c_00064098\n"
        "movss lit4_002ed610, %xmm6\n" /* 0.125f */
        "movaps %xmm3, %xmm4\n" /* line 166 | comparand */
        "subss %xmm5, %xmm4\n" /* comparand */
        /* { scope 2 */
        "pxor %xmm7, %xmm7\n" /* line 45 */
        "movaps %xmm4, %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "cmpnltss %xmm7, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        /* } scope */
        "ucomiss %xmm6, %xmm0\n" /* line 2105 */
        "jae .Lf63f0c_00063f90\n"
        ".Lf63f0c_0006403e:\n"
        "movaps %xmm5, %xmm0\n" /* line 45 */
        "subss %xmm3, %xmm0\n"
        "movaps %xmm3, %xmm2\n"
        "cmpltss %xmm7, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm5, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+288, %xmm2\n" /* line 2111 */
        "movaps %xmm6, %xmm1\n"
        "xorps %xmm2, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf63f0c_000640a5\n"
        "movswl 6(%ebx), %edx\n" /* line 2113 | node */
        "testl %edx, %edx\n" /* line 2077 */
        "jns .Lf63f0c_00063f9c\n"
        ".Lf63f0c_00064075:\n"
        "movl %edx, %eax\n" /* line 2078 */
        "notl %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x28(%ecx), %eax\n" /* p1_ */
        "leal (%eax, %edx, 4), %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* trace, p1_ */
        "movl -0x3c(%ebp), %eax\n"
        "calll CM_SightTraceThroughLeaf\n"
        /* } scope */
        ".Lf63f0c_00064090:\n"
        "addl $0x6c, %esp\n" /* line 2157 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf63f0c_00064098:\n"
        "movss lit4_002ed6a4, %xmm6\n" /* line 2098 | 2048.0f */
        "jmp .Lf63f0c_00063f68\n"
        ".Lf63f0c_000640a5:\n"
        "movaps %xmm4, %xmm0\n" /* line 54 */
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+304, %xmm0\n"
        "ucomiss lit4_002ed6a0, %xmm0\n" /* line 2120 | 4.76837158203125e-07f */
        "ja .Lf63f0c_000641d6\n"
        "movaps %xmm7, %xmm3\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm5\n"
        "xorl %edi, %edi\n" /* side */
        "movaps %xmm7, %xmm0\n"
        ".Lf63f0c_000640cf:\n"
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "cmpnltss %xmm7, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm5, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 2139 | p1 */
        "movss (%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* mid */
        "movss -0x2c(%ebp), %xmm1\n" /* line 2140 */
        "movss 4(%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 2141 */
        "movss 8(%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "leal -0x30(%ebp), %ecx\n" /* line 2143 | p1, p1_ */
        "movswl 4(%ebx, %edi, 2), %edx\n" /* node */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movss %xmm3, -0x58(%ebp)\n"
        "movss %xmm7, -0x68(%ebp)\n"
        "calll CM_SightTraceThroughTree\n"
        "testl %eax, %eax\n" /* line 2144 */
        "movss -0x58(%ebp), %xmm3\n"
        "movss -0x68(%ebp), %xmm7\n"
        "jne .Lf63f0c_00064090\n"
        "maxss %xmm3, %xmm7\n" /* line 45 */
        "movaps %xmm7, %xmm3\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 2151 | p1 */
        "movss (%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* p1 */
        "movss -0x2c(%ebp), %xmm1\n" /* line 2152 */
        "movss 4(%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 2153 */
        "movss 8(%esi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "xorl $1, %edi\n" /* line 2155 | side */
        "movswl 4(%ebx, %edi, 2), %edx\n" /* node */
        "movl imp_cm, %ecx\n" /* p1_ */
        "jmp .Lf63f0c_00063f94\n"
        ".Lf63f0c_000641d6:\n"
        "movaps %xmm5, %xmm1\n" /* line 2122 */
        "xorps %xmm2, %xmm1\n"
        "ucomiss %xmm4, %xmm7\n" /* line 45 */
        "ja .Lf63f0c_0006421e\n"
        ".Lf63f0c_000641e1:\n"
        "movss lit4_002ed5d0, %xmm5\n" /* line 2123 | 1.0f */
        "movaps %xmm5, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm1, %xmm3\n" /* line 2124 */
        "subss %xmm6, %xmm3\n"
        "mulss %xmm2, %xmm3\n"
        "movaps %xmm6, %xmm2\n" /* line 2125 */
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "ucomiss %xmm4, %xmm7\n" /* line 96 */
        "setbe %al\n"
        "movzbl %al, %edi\n"
        "movaps %xmm5, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "jmp .Lf63f0c_000640cf\n"
        ".Lf63f0c_0006421e:\n"
        "movaps %xmm5, %xmm1\n" /* line 45 */
        "jmp .Lf63f0c_000641e1\n"
        ".Lf63f0c_00064223:\n"
        "movl imp_cm, %ecx\n"
        "movl %edx, %eax\n" /* line 2078 */
        "notl %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x28(%ecx), %eax\n" /* p1_ */
        "leal (%eax, %edx, 4), %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* trace, p1_ */
        "movl -0x3c(%ebp), %eax\n"
        "calll CM_SightTraceThroughLeaf\n"
        "jmp .Lf63f0c_00064090\n"
    );
}

/* line 823 */
static __attribute__((naked))
Bool CM_TraceThroughLeafBrushNode(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 823 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %ebx\n" /* tw */
        "movl %edx, %esi\n" /* leaf */
        "movl %ecx, %edi\n" /* trace */
        /* { scope 1 */
        "leal 0xc(%edx), %eax\n" /* line 832 | a */
        /* { scope 2 */
        "movss 0xc(%edx), %xmm0\n" /* line 248 */
        "subss 0x5c(%ebx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* absmin */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 0x60(%ebx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 0x64(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal 0x18(%edx), %eax\n"
        /* } scope */
        /* { scope 2 */
        "movss 0x18(%edx), %xmm0\n" /* line 240 */
        "addss 0x5c(%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* absmax */
        "movss 4(%eax), %xmm0\n" /* line 241 */
        "addss 0x60(%ebx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "addss 0x64(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "movl (%ecx), %eax\n" /* line 834 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* absmax */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* absmin */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* tw */
        "calll CM_TraceBox\n"
        "testl %eax, %eax\n"
        "je .Lf6424a_000642e3\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 844 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6424a_000642e3:\n"
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x40(%ebp)\n" /* start */
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, -0x38(%ebp)\n"
        "leal 0xc(%ebx), %edx\n" /* line 838 | tw, from */
        /* { scope 2 */
        "movl 0xc(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x50(%ebp)\n" /* end */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x48(%ebp)\n"
        /* } scope */
        "movl $0, -0x34(%ebp)\n" /* line 839 */
        "movl (%edi), %eax\n" /* line 840 | trace */
        "movl %eax, -0x44(%ebp)\n"
        "leal -0x40(%ebp), %ecx\n" /* line 842 | start */
        "movl 0x24(%esi), %edx\n" /* leaf */
        "leal (%edx, %edx, 4), %edx\n"
        "movl imp_cm, %eax\n"
        "movl 0x30(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edi, 4(%esp)\n" /* trace */
        "leal -0x50(%ebp), %eax\n" /* end */
        "movl %eax, (%esp)\n"
        "movl %ebx, %eax\n" /* tw */
        "calll CM_TraceThroughLeafBrushNode_r\n"
        "pxor %xmm0, %xmm0\n" /* line 843 */
        "ucomiss (%edi), %xmm0\n" /* trace */
        "sete %al\n"
        "setnp %dl\n"
        "andb %dl, %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 844 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 892 */
static __attribute__((naked))
qboolean CM_TraceSphereThroughSphere(const vec_t *vStationary, trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 892 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %ebx\n" /* tw */
        "movl %ecx, %edi\n" /* vEnd */
        "movl 8(%ebp), %esi\n" /* vStationary */
        /* { scope 1 */
        "movss (%edx), %xmm4\n" /* line 248 */
        "subss (%esi), %xmm4\n"
        "movss %xmm4, -0x24(%ebp)\n" /* vDelta */
        "movss 4(%edx), %xmm2\n" /* line 249 */
        "subss 4(%esi), %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n"
        "movss 8(%edx), %xmm1\n" /* line 250 */
        "subss 8(%esi), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movaps %xmm0, %xmm5\n" /* line 905 */
        "addss 0x8c(%eax), %xmm5\n"
        "mulss %xmm5, %xmm5\n"
        "movaps %xmm4, %xmm3\n" /* line 906 */
        "mulss %xmm4, %xmm3\n"
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "subss %xmm5, %xmm3\n"
        "pxor %xmm6, %xmm6\n" /* line 907 */
        "ucomiss %xmm3, %xmm6\n"
        "jae .Lf64354_000644d3\n"
        "leal 0x24(%eax), %eax\n" /* line 922 | a */
        /* { scope 2 */
        "mulss 0x24(%ebx), %xmm4\n" /* line 304 */
        "mulss 4(%eax), %xmm2\n"
        "addss %xmm2, %xmm4\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm4\n"
        /* } scope */
        "ucomiss %xmm6, %xmm4\n" /* line 923 */
        "jb .Lf64354_000643fe\n"
        ".Lf64354_000643ee:\n"
        "movl $1, %eax\n" /* line 943 */
        /* } scope */
        ".Lf64354_000643f3:\n"
        "addl $0x9c, %esp\n" /* line 947 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf64354_000643fe:\n"
        "movss 0x34(%ebx), %xmm0\n" /* line 926 | tw */
        "movss %xmm0, -0x3c(%ebp)\n" /* fA */
        "movaps %xmm4, %xmm0\n" /* line 929 */
        "mulss %xmm4, %xmm0\n"
        "mulss -0x3c(%ebp), %xmm3\n" /* fA */
        "subss %xmm3, %xmm0\n"
        "ucomiss %xmm0, %xmm6\n" /* line 930 */
        "ja .Lf64354_000643ee\n"
        "leal -0x30(%ebp), %eax\n" /* line 935 | vNormal */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* vDelta */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movss %xmm4, -0x68(%ebp)\n"
        "movss %xmm6, -0x88(%ebp)\n"
        "calll Vec3NormalizeTo\n"
        "fstps -0x8c(%ebp)\n"
        "movss -0x8c(%ebp), %xmm1\n"
        "movss -0x68(%ebp), %xmm4\n" /* line 936 */
        "movaps %xmm4, %xmm2\n"
        "xorps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+320, %xmm2\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 81 */
        "sqrtss %xmm0, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "divss -0x3c(%ebp), %xmm2\n" /* fA */
        "mulss lit4_002ed610, %xmm1\n" /* 0.125f */
        "divss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "movl 0xc(%ebp), %eax\n" /* line 937 | trace */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "movss -0x88(%ebp), %xmm6\n"
        "jbe .Lf64354_000643ee\n"
        "maxss %xmm2, %xmm6\n" /* line 45 */
        "movss %xmm6, (%eax)\n" /* line 939 */
        "movl %eax, %edx\n" /* line 941 | to */
        "addl $4, %edx\n" /* to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | vNormal */
        "movl 0xc(%ebp), %ecx\n" /* trace */
        "movl %eax, 4(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0xb0(%ebx), %eax\n" /* line 942 | tw */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        ".Lf64354_000644c6:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 947 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf64354_000644d3:\n"
        "movl 0xc(%ebp), %eax\n" /* line 910 | trace */
        "movss %xmm6, (%eax)\n"
        "movb $1, 0x23(%eax)\n" /* line 911 */
        "movl 0xc(%ebp), %eax\n" /* line 912 | trace */
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* vDelta */
        "movl %eax, (%esp)\n"
        "movss %xmm5, -0x78(%ebp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movl 0xb0(%ebx), %eax\n" /* line 913 | tw */
        "movl 0xc(%eax), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* trace, vStart */
        "movl %eax, 0x14(%edx)\n" /* vStart */
        "movss (%edi), %xmm2\n" /* line 248 */
        "subss (%esi), %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* vDelta */
        "movss 4(%edi), %xmm1\n" /* line 249 */
        "subss 4(%esi), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 */
        "subss 8(%esi), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "mulss %xmm2, %xmm2\n" /* line 916 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss -0x78(%ebp), %xmm5\n"
        "ucomiss %xmm2, %xmm5\n"
        "jb .Lf64354_000644c6\n"
        "movl 0xc(%ebp), %ecx\n" /* line 917 | trace */
        "movb $1, 0x22(%ecx)\n"
        "xorl %eax, %eax\n" /* line 942 */
        "jmp .Lf64354_000643f3\n"
    );
}

/* line 1849 */
static __attribute__((naked))
qboolean CM_SightTraceSphereThroughSphere(const vec_t *vStationary, trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1849 */
        "movl %esp, %ebp\n"
        "subl $0x68, %esp\n"
        "movl %eax, %ecx\n" /* vStationary, vEnd */
        "movl 8(%ebp), %eax\n" /* vStationary */
        /* { scope 1 */
        "movss (%edx), %xmm5\n" /* line 248 */
        "subss (%eax), %xmm5\n"
        "movss %xmm5, -0x14(%ebp)\n" /* vDelta */
        "movss 4(%edx), %xmm3\n" /* line 249 */
        "subss 4(%eax), %xmm3\n"
        "movss %xmm3, -0x10(%ebp)\n"
        "movss 8(%edx), %xmm2\n" /* line 250 */
        "subss 8(%eax), %xmm2\n"
        "movss %xmm2, -0xc(%ebp)\n"
        "addss 0x8c(%ecx), %xmm0\n" /* line 1862 | vEnd, radius */
        "movaps %xmm5, %xmm4\n" /* line 1863 */
        "mulss %xmm5, %xmm4\n"
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm1, %xmm4\n"
        "movaps %xmm2, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm4\n"
        "mulss %xmm0, %xmm0\n" /* radius */
        "subss %xmm0, %xmm4\n" /* radius */
        "pxor %xmm0, %xmm0\n" /* line 1864 | radius */
        "ucomiss %xmm4, %xmm0\n" /* radius */
        "jae .Lf64564_00064678\n"
        "leal 0x24(%ecx), %eax\n" /* line 1867 | vEnd, a */
        /* { scope 2 */
        "mulss 0x24(%ecx), %xmm5\n" /* line 304 */
        "mulss 4(%eax), %xmm3\n"
        "addss %xmm3, %xmm5\n"
        "mulss 8(%eax), %xmm2\n"
        "addss %xmm2, %xmm5\n"
        /* } scope */
        "ucomiss %xmm0, %xmm5\n" /* line 1868 | radius */
        "jb .Lf64564_000645fa\n"
        ".Lf64564_000645f3:\n"
        "movl $1, %eax\n" /* line 1880 */
        /* } scope */
        "leave\n" /* line 1881 */
        "retl\n"
        /* { scope 1 */
        ".Lf64564_000645fa:\n"
        "movss 0x34(%ecx), %xmm1\n" /* line 1871 | vEnd */
        "movss %xmm1, -0x30(%ebp)\n" /* fA */
        "movaps %xmm5, %xmm1\n" /* line 1872 */
        "mulss %xmm5, %xmm1\n"
        "mulss -0x30(%ebp), %xmm4\n" /* fA */
        "subss %xmm4, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n" /* line 1873 | radius */
        "ja .Lf64564_000645f3\n"
        "leal -0x20(%ebp), %eax\n" /* line 1878 | vNormal */
        "movl %eax, 4(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* vDelta */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movss %xmm5, -0x58(%ebp)\n"
        "calll Vec3NormalizeTo\n"
        "fstps -0x2c(%ebp)\n" /* fDeltaLen */
        "movss -0x58(%ebp), %xmm5\n" /* line 1880 */
        "movaps %xmm5, %xmm0\n" /* radius */
        "xorps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+336, %xmm0\n" /* radius */
        "movss -0x48(%ebp), %xmm1\n" /* line 81 */
        "sqrtss %xmm1, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "divss -0x30(%ebp), %xmm0\n" /* fA */
        "mulss lit4_002ed610, %xmm5\n" /* 0.125f */
        "divss -0x2c(%ebp), %xmm5\n" /* fDeltaLen */
        "addss %xmm5, %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* trace */
        "ucomiss (%eax), %xmm0\n"
        "setae %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "leave\n" /* line 1881 */
        "retl\n"
        /* { scope 1 */
        ".Lf64564_00064678:\n"
        "xorl %eax, %eax\n" /* line 1864 */
        /* } scope */
        "leave\n" /* line 1881 */
        "retl\n"
    );
}

/* line 60 */
__attribute__((naked))
clipHandle_t CM_TempBoxModel(const vec_t *mins, const vec_t *maxs, int contents)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* mins */
        "movl 0xc(%ebp), %edi\n" /* maxs */
        /* { scope 1 */
        "movl $3, (%esp)\n" /* line 43 */
        "calll Sys_GetValue\n"
        "movl 0x10(%eax), %esi\n" /* line 46 */
        "movl 0x14(%eax), %edx\n" /* line 47 */
        "movl (%ebx), %eax\n" /* line 199 | mins */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 | mins */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 | mins */
        "movl %eax, 8(%edx)\n"
        "leal 0xc(%edx), %ecx\n" /* line 68 | to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | maxs */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edi), %eax\n" /* line 200 | maxs */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edi), %eax\n" /* line 201 | maxs */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl (%ebx), %eax\n" /* line 199 | mins */
        "movl %eax, (%esi)\n" /* box_brush */
        "movl 4(%ebx), %eax\n" /* line 200 | mins */
        "movl %eax, 4(%esi)\n" /* box_brush */
        "movl 8(%ebx), %eax\n" /* line 201 | mins */
        "movl %eax, 8(%esi)\n" /* box_brush */
        "leal 0x10(%esi), %edx\n" /* line 71 | box_brush, to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | maxs */
        "movl %eax, 0x10(%esi)\n" /* box_brush */
        "movl 4(%edi), %eax\n" /* line 200 | maxs */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 201 | maxs */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 73 | contents */
        "movl %eax, 0xc(%esi)\n" /* box_brush */
        /* } scope */
        "movl $0x3ff, %eax\n" /* line 76 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1133 */
static __attribute__((naked))
int CM_TraceThroughTree(const vec_t *p2, trace_t *trace)
{
    __asm__ __volatile__ (
        ".Lf646f8_000646f8:\n"
        "pushl %ebp\n" /* line 1133 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* tw */
        "movl 8(%ebp), %esi\n" /* p2 */
        /* { scope 1 */
        "movl (%ecx), %eax\n" /* line 456 */
        "movl %eax, -0x38(%ebp)\n" /* p1 */
        "movl 4(%ecx), %eax\n" /* line 457 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 458 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%ecx), %eax\n" /* line 459 */
        "movl %eax, -0x2c(%ebp)\n"
        "testl %edx, %edx\n" /* line 1154 */
        "js .Lf646f8_00064a94\n"
        "movl imp_cm, %ecx\n" /* p1_ */
        "jmp .Lf646f8_0006478a\n"
        ".Lf646f8_0006472d:\n"
        "movzbl %al, %eax\n" /* line 1170 */
        "movss 0xc(%edx), %xmm0\n"
        "movss -0x38(%ebp, %eax, 4), %xmm5\n"
        "subss %xmm0, %xmm5\n"
        "movss (%esi, %eax, 4), %xmm3\n" /* line 1171 | leaf */
        "subss %xmm0, %xmm3\n"
        "movss lit4_002ed610, %xmm6\n" /* line 1172 | 0.125f */
        "addss 0x5c(%edi, %eax, 4), %xmm6\n" /* tw */
        ".Lf646f8_00064756:\n"
        "movaps %xmm3, %xmm4\n" /* line 166 | comparand */
        "subss %xmm5, %xmm4\n" /* comparand */
        /* { scope 2 */
        "movaps %xmm4, %xmm0\n" /* line 45 */
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm5, %xmm1\n"
        "cmpnltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        /* } scope */
        "ucomiss %xmm0, %xmm6\n" /* line 1185 */
        "ja .Lf646f8_00064829\n"
        ".Lf646f8_0006477e:\n"
        "movswl 4(%ebx), %edx\n" /* line 1187 | node */
        ".Lf646f8_00064782:\n"
        "testl %edx, %edx\n" /* line 1154 */
        "js .Lf646f8_00064864\n"
        ".Lf646f8_0006478a:\n"
        "movl 0x20(%ecx), %eax\n" /* line 1164 | p1_ */
        "leal (%eax, %edx, 8), %ebx\n" /* node */
        "movl (%ebx), %edx\n" /* line 1165 | node */
        "movzbl 0x10(%edx), %eax\n" /* line 1168 */
        "cmpb $2, %al\n"
        "jbe .Lf646f8_0006472d\n"
        "movss 4(%edx), %xmm1\n" /* line 304 */
        "movss 8(%edx), %xmm2\n"
        "movss 0xc(%edx), %xmm4\n" /* line 1176 */
        "movss (%edx), %xmm3\n"
        "movaps %xmm3, %xmm5\n"
        "mulss -0x38(%ebp), %xmm5\n" /* p1 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x34(%ebp), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movaps %xmm2, %xmm0\n"
        "mulss -0x30(%ebp), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "subss %xmm4, %xmm5\n"
        "mulss (%esi), %xmm3\n" /* line 1177 | leaf */
        "mulss 4(%esi), %xmm1\n" /* leaf */
        "addss %xmm1, %xmm3\n"
        "mulss 8(%esi), %xmm2\n" /* leaf */
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "movl 0x84(%edi), %eax\n" /* line 1178 | tw */
        "testl %eax, %eax\n"
        "je .Lf646f8_000648bb\n"
        "movss lit4_002ed610, %xmm6\n" /* 0.125f */
        "movaps %xmm3, %xmm4\n" /* line 166 | comparand */
        "subss %xmm5, %xmm4\n" /* comparand */
        /* { scope 2 */
        "movaps %xmm4, %xmm0\n" /* line 45 */
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm5, %xmm1\n"
        "cmpnltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        /* } scope */
        "ucomiss %xmm0, %xmm6\n" /* line 1185 */
        "jbe .Lf646f8_0006477e\n"
        ".Lf646f8_00064829:\n"
        "movaps %xmm5, %xmm0\n" /* line 45 */
        "subss %xmm3, %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm3, %xmm1\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm5, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+352, %xmm2\n" /* line 1191 */
        "movaps %xmm6, %xmm1\n"
        "xorps %xmm2, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf646f8_000648c8\n"
        "movswl 6(%ebx), %edx\n" /* line 1193 | node */
        "testl %edx, %edx\n" /* line 1154 */
        "jns .Lf646f8_0006478a\n"
        ".Lf646f8_00064864:\n"
        "movl %edx, %eax\n" /* line 1156 */
        "notl %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x28(%ecx), %eax\n" /* p1_ */
        "leal (%eax, %edx, 4), %esi\n" /* leaf */
        /* { scope 2 */
        /* { scope 3 */
        "pxor %xmm0, %xmm0\n" /* line 856 */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "ucomiss (%eax), %xmm0\n"
        "jp .Lf646f8_00064882\n"
        "je .Lf646f8_000648b3\n"
        ".Lf646f8_00064882:\n"
        "movl 0x80(%edi), %eax\n" /* line 859 */
        "testl %eax, 4(%esi)\n"
        "jne .Lf646f8_00064a9f\n"
        "testl %eax, 8(%esi)\n" /* line 870 */
        "je .Lf646f8_000648b3\n"
        ".Lf646f8_00064896:\n"
        "cmpw $0, 2(%esi)\n" /* line 873 */
        "je .Lf646f8_000648b3\n"
        "pxor %xmm0, %xmm0\n" /* line 875 */
        "movl 0xc(%ebp), %edx\n" /* trace */
        "ucomiss (%edx), %xmm0\n"
        "jp .Lf646f8_00064ac7\n"
        "jne .Lf646f8_00064ac7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf646f8_000648b3:\n"
        "addl $0x5c, %esp\n" /* line 1240 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf646f8_000648bb:\n"
        "movss lit4_002ed6a4, %xmm6\n" /* line 1178 | 2048.0f */
        "jmp .Lf646f8_00064756\n"
        ".Lf646f8_000648c8:\n"
        "movss -0x2c(%ebp), %xmm3\n" /* line 1197 */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf646f8_000648b3\n"
        "movaps %xmm4, %xmm0\n" /* line 54 */
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+368, %xmm0\n"
        "ucomiss lit4_002ed6a0, %xmm0\n" /* line 1203 | 4.76837158203125e-07f */
        "ja .Lf646f8_00064a39\n"
        "pxor %xmm5, %xmm5\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm7\n"
        "xorl %eax, %eax\n"
        "pxor %xmm0, %xmm0\n"
        "movl $1, -0x3c(%ebp)\n"
        ".Lf646f8_0006490c:\n"
        "pxor %xmm4, %xmm4\n" /* line 45 */
        "movaps %xmm2, %xmm1\n"
        "cmpnltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm7, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 1222 | p1 */
        "movss (%esi), %xmm0\n" /* leaf */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* mid */
        "movss -0x34(%ebp), %xmm1\n" /* line 1223 */
        "movss 4(%esi), %xmm0\n" /* leaf */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1224 */
        "movss 8(%esi), %xmm0\n" /* leaf */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss 0xc(%esi), %xmm0\n" /* line 1225 | leaf */
        "subss %xmm3, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        "leal -0x38(%ebp), %ecx\n" /* line 1227 | p1, p1_ */
        "movswl 4(%ebx, %eax, 2), %edx\n" /* node */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "movl %edi, %eax\n" /* tw */
        "movss %xmm5, -0x58(%ebp)\n"
        "calll CM_TraceThroughTree\n"
        "movss -0x58(%ebp), %xmm5\n" /* line 45 */
        "pxor %xmm0, %xmm0\n"
        "maxss %xmm5, %xmm0\n"
        "movaps %xmm0, %xmm5\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 1233 | p1 */
        "movss (%esi), %xmm0\n" /* leaf */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n" /* p1 */
        "movss -0x34(%ebp), %xmm1\n" /* line 1234 */
        "movss 4(%esi), %xmm0\n" /* leaf */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1235 */
        "movss 8(%esi), %xmm0\n" /* leaf */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 1236 */
        "movss 0xc(%esi), %xmm0\n" /* leaf */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1238 */
        "movswl 4(%ebx, %eax, 2), %edx\n" /* node */
        "movl imp_cm, %ecx\n" /* p1_ */
        "jmp .Lf646f8_00064782\n"
        ".Lf646f8_00064a39:\n"
        "movaps %xmm5, %xmm1\n" /* line 1205 */
        "xorps %xmm2, %xmm1\n"
        "pxor %xmm2, %xmm2\n" /* line 45 */
        "ucomiss %xmm4, %xmm2\n"
        "ja .Lf646f8_00064b13\n"
        ".Lf646f8_00064a4c:\n"
        "movss lit4_002ed5d0, %xmm7\n" /* line 1206 | 1.0f */
        "movaps %xmm7, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm1, %xmm5\n" /* line 1207 */
        "subss %xmm6, %xmm5\n"
        "mulss %xmm2, %xmm5\n"
        "movaps %xmm6, %xmm2\n" /* line 1208 */
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 96 */
        "xorl %eax, %eax\n"
        "ucomiss %xmm4, %xmm0\n"
        "setbe %al\n"
        "movaps %xmm7, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movl %eax, %edx\n"
        "xorl $1, %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "jmp .Lf646f8_0006490c\n"
        ".Lf646f8_00064a94:\n"
        "movl imp_cm, %ecx\n"
        "jmp .Lf646f8_00064864\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf646f8_00064a9f:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 862 | trace */
        "movl %esi, %edx\n"
        "movl %edi, %eax\n"
        "calll CM_TraceThroughLeafBrushNode\n"
        "testb %al, %al\n"
        "jne .Lf646f8_000648b3\n"
        "movl 0x80(%edi), %eax\n"
        "testl %eax, 8(%esi)\n" /* line 870 */
        "jne .Lf646f8_00064896\n"
        "jmp .Lf646f8_000648b3\n"
        ".Lf646f8_00064ac7:\n"
        "xorl %ebx, %ebx\n" /* line 875 | k */
        "movl 0xc(%ebp), %edx\n" /* trace */
        ".Lf646f8_00064acc:\n"
        "movl %edx, 8(%esp)\n" /* line 880 */
        "movzwl (%esi), %eax\n"
        "leal (%ebx, %eax), %eax\n" /* k */
        "shll $5, %eax\n"
        "movl imp_cm, %edx\n"
        "addl 0x70(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CM_TraceThroughAabbTree\n"
        "addl $1, %ebx\n" /* line 873 | k */
        "movzwl 2(%esi), %eax\n"
        "cmpl %ebx, %eax\n" /* k */
        "jle .Lf646f8_000648b3\n"
        "pxor %xmm0, %xmm0\n" /* line 875 */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "ucomiss (%eax), %xmm0\n"
        "jp .Lf646f8_00064b0f\n"
        "je .Lf646f8_000648b3\n"
        ".Lf646f8_00064b0f:\n"
        "movl %eax, %edx\n"
        "jmp .Lf646f8_00064acc\n"
        /* } scope */
        /* } scope */
        ".Lf646f8_00064b13:\n"
        "movaps %xmm5, %xmm1\n" /* line 45 */
        "jmp .Lf646f8_00064a4c\n"
    );
}

/* line 95 */
__attribute__((naked))
int CM_ContentsOfModel(clipHandle_t handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* handle */
        /* { scope 1 */
        "movl imp_cm, %ecx\n" /* line 85 */
        "cmpl 0x74(%ecx), %eax\n"
        "jge .Lf64b1c_00064b41\n"
        "leal (%eax, %eax, 8), %edx\n" /* line 86 */
        "movl 0x78(%ecx), %eax\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl 0x20(%edx), %eax\n" /* line 47 */
        "orl 0x24(%edx), %eax\n"
        /* } scope */
        "leave\n" /* line 101 */
        "retl\n"
        /* { scope 1 */
        ".Lf64b1c_00064b41:\n"
        "movl $3, (%esp)\n" /* line 43 */
        "calll Sys_GetValue\n"
        "movl 0x14(%eax), %edx\n" /* line 47 */
        "movl 0x20(%edx), %eax\n"
        "orl 0x24(%edx), %eax\n"
        /* } scope */
        "leave\n" /* line 101 */
        "retl\n"
    );
}

/* line 104 */
__attribute__((naked))
float CM_RadiusOfModel(clipHandle_t handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* handle */
        /* { scope 1 */
        "movl imp_cm, %ecx\n" /* line 85 */
        "cmpl 0x74(%ecx), %eax\n"
        "jge .Lf64b58_00064b7a\n"
        "leal (%eax, %eax, 8), %edx\n" /* line 86 */
        "movl 0x78(%ecx), %eax\n"
        "leal (%eax, %edx, 8), %eax\n"
        "flds 0x18(%eax)\n" /* line 47 */
        /* } scope */
        "leave\n" /* line 110 */
        "retl\n"
        /* { scope 1 */
        ".Lf64b58_00064b7a:\n"
        "movl $3, (%esp)\n" /* line 43 */
        "calll Sys_GetValue\n"
        "movl 0x14(%eax), %eax\n" /* line 47 */
        "flds 0x18(%eax)\n"
        /* } scope */
        "leave\n" /* line 110 */
        "retl\n"
    );
}

/* line 1267 */
static __attribute__((naked))
int CM_Trace(trace_t *results, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1267 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x122c, %esp\n"
        "movl %eax, -0x11b8(%ebp)\n" /* brushmask */
        "movl %edx, %ebx\n" /* start */
        "movl %ecx, %esi\n" /* end */
        /* { scope 1: box_model, leafs, ll, offset, ... */
        /* { scope 2: radius, fStationaryHalfHeight */
        "movl imp_cm, %eax\n" /* line 85 */
        "movl 0x10(%ebp), %edx\n" /* model */
        "cmpl 0x74(%eax), %edx\n"
        "jge .Lf64b8e_00065291\n"
        "leal (%edx, %edx, 8), %edx\n" /* line 86 */
        "movl 0x78(%eax), %eax\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl %edx, -0x11b4(%ebp)\n" /* box_model */
        /* } scope */
        ".Lf64b8e_00064bc4:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1285 | brushmask */
        "movl %eax, -0xfc(%ebp)\n"
        "movl $1, %ecx\n"
        "movss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+384, %xmm2\n"
        "movl $4, %edx\n"
        "leal -0x12c(%ebp), %eax\n"
        ".Lf64b8e_00064bed:\n"
        "movl 0xc(%ebp), %edi\n" /* line 1293 | maxs, i */
        "movss -4(%edx, %edi), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movl 8(%ebp), %edi\n" /* mins, i */
        "addss -4(%edx, %edi), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "subss %xmm0, %xmm1\n" /* line 1294 */
        "movss %xmm1, 0xc(%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 1295 */
        "addss -4(%edx, %ebx), %xmm1\n"
        "movss %xmm1, -0x50(%eax)\n"
        "addss -4(%edx, %esi), %xmm0\n" /* line 1296 */
        "movss %xmm0, -0x44(%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 1297 */
        "addss -0x50(%eax), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, -0x18(%eax)\n"
        "subss -0x50(%eax), %xmm0\n" /* line 1298 */
        "movss %xmm0, -0x15c(%edx, %ebp)\n"
        "mulss %xmm3, %xmm0\n" /* line 1299 */
        "movss %xmm0, -0x13c(%edx, %ebp)\n"
        "andps %xmm2, %xmm0\n" /* line 1300 */
        "movss %xmm0, (%eax)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 1290 */
        "jne .Lf64b8e_00064bed\n"
        "leal -0x17c(%ebp), %eax\n" /* line 1302 | tw */
        "movl %eax, (%esp)\n"
        "calll CM_CalcTraceEntents\n"
        "movss -0x158(%ebp), %xmm0\n" /* line 316 */
        "movss -0x154(%ebp), %xmm1\n"
        "movss -0x150(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x148(%ebp)\n" /* line 1303 */
        "sqrtss %xmm0, %xmm0\n" /* line 81 */
        "movss %xmm0, -0x14c(%ebp)\n"
        "movss -0x120(%ebp), %xmm3\n" /* line 1309 */
        "movss -0x118(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movaps %xmm3, %xmm1\n"
        "cmpnltss %xmm3, %xmm2\n"
        "andps %xmm2, %xmm1\n"
        "andnps %xmm0, %xmm2\n"
        "orps %xmm1, %xmm2\n"
        "movss %xmm2, -0xf0(%ebp)\n"
        "subss %xmm2, %xmm0\n" /* line 1311 */
        "movss %xmm0, -0xec(%ebp)\n"
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "leal -0x174(%ebp), %edx\n"
        ".Lf64b8e_00064cfb:\n"
        "movss (%eax), %xmm1\n" /* line 1318 */
        "movss 0xc(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf64b8e_0006503c\n"
        "subss %xmm2, %xmm1\n" /* line 1320 */
        "movss %xmm1, 0x68(%eax)\n"
        "addss %xmm2, %xmm0\n" /* line 1321 */
        "movss %xmm0, 0x74(%eax)\n"
        ".Lf64b8e_00064d1f:\n"
        "addl $4, %eax\n" /* line 1326 */
        "cmpl %edx, %eax\n" /* line 1316 */
        "jne .Lf64b8e_00064cfb\n"
        "movss -0x174(%ebp), %xmm1\n" /* line 1332 */
        "movss -0x168(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf64b8e_00065053\n"
        "subss -0xec(%ebp), %xmm1\n" /* line 1334 */
        "subss -0xf0(%ebp), %xmm1\n"
        "movss %xmm1, -0x10c(%ebp)\n"
        "addss -0xec(%ebp), %xmm0\n" /* line 1335 */
        "addss -0xf0(%ebp), %xmm0\n"
        "movss %xmm0, -0x100(%ebp)\n"
        "movaps %xmm0, %xmm2\n"
        ".Lf64b8e_00064d72:\n"
        "subss -0x10c(%ebp), %xmm2\n" /* line 1258 */
        "movss -0x108(%ebp), %xmm1\n"
        "subss -0x114(%ebp), %xmm1\n"
        "movss -0x104(%ebp), %xmm0\n"
        "subss -0x110(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "mulss -0x11c(%ebp), %xmm3\n"
        "mulss -0x118(%ebp), %xmm3\n"
        "mulss lit4_002ed6a8, %xmm3\n" /* 16.0f */
        "mulss -0x14c(%ebp), %xmm3\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm2, %xmm3\n"
        "seta %al\n"
        "movl %eax, -0xf4(%ebp)\n"
        "movl $3, (%esp)\n" /* line 22 */
        "calll Sys_GetValue\n"
        "movl (%eax), %edx\n" /* line 25 */
        "addl $1, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %edx, -0xdc(%ebp)\n" /* line 27 */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0xd8(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0xd4(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0xd0(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0xc8(%ebp)\n"
        "movss (%ebx), %xmm0\n" /* line 310 */
        "ucomiss (%esi), %xmm0\n"
        "jne .Lf64b8e_00064e30\n"
        "jp .Lf64b8e_00064e30\n"
        "movss 4(%ebx), %xmm0\n"
        "ucomiss 4(%esi), %xmm0\n"
        "je .Lf64b8e_0006526c\n"
        ".Lf64b8e_00064e30:\n"
        "xorl %eax, %eax\n"
        ".Lf64b8e_00064e32:\n"
        "testl %eax, %eax\n" /* line 1350 */
        "je .Lf64b8e_0006508b\n"
        "movl $0, -0xf8(%ebp)\n" /* line 1352 */
        "movl 0x10(%ebp), %edx\n" /* line 1354 | model */
        "testl %edx, %edx\n"
        "jne .Lf64b8e_000651a7\n"
        /* { scope 2: radius, fStationaryHalfHeight */
        "movl -0x11b8(%ebp), %edx\n" /* line 444 */
        "cmpb $0, 0x22(%edx)\n"
        "jne .Lf64b8e_00065031\n"
        "movss -0x17c(%ebp), %xmm3\n" /* line 248 | tw */
        "movaps %xmm3, %xmm0\n"
        "subss -0x120(%ebp), %xmm0\n"
        "movss %xmm0, -0xb4(%ebp)\n"
        "leal -0xc4(%ebp), %ecx\n" /* line 249 | ll */
        "movss -0x178(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "subss -0x11c(%ebp), %xmm0\n"
        "movss %xmm0, -0xb0(%ebp)\n"
        "movss -0x174(%ebp), %xmm1\n" /* line 250 */
        "movaps %xmm1, %xmm0\n"
        "subss -0x118(%ebp), %xmm0\n"
        "movss %xmm0, -0xac(%ebp)\n"
        "addss -0x120(%ebp), %xmm3\n" /* line 240 */
        "movss %xmm3, -0xa8(%ebp)\n"
        "addss -0x11c(%ebp), %xmm2\n" /* line 241 */
        "movss %xmm2, -0xa4(%ebp)\n"
        "addss -0x118(%ebp), %xmm1\n" /* line 242 */
        "movss %xmm1, -0xa0(%ebp)\n"
        "movl %ecx, %eax\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "leal -0xb8(%ebp), %edx\n"
        ".Lf64b8e_00064ef6:\n"
        "movss 0x10(%eax), %xmm0\n" /* line 453 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%eax)\n"
        "movss 0x1c(%eax), %xmm0\n" /* line 454 */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x1c(%eax)\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n" /* line 451 */
        "jne .Lf64b8e_00064ef6\n"
        "movl $0, -0xc4(%ebp)\n" /* line 457 | ll */
        "movl $0x400, -0xc0(%ebp)\n" /* line 458 */
        "leal -0x117c(%ebp), %eax\n" /* line 459 | leafs */
        "movl %eax, -0xb8(%ebp)\n"
        "movl $0, -0x9c(%ebp)\n" /* line 461 */
        "movl $0, -0xbc(%ebp)\n" /* line 463 */
        "movl $0, 4(%esp)\n" /* line 465 */
        "movl %ecx, (%esp)\n"
        "calll CM_BoxLeafnums_r\n"
        "cmpl $0, -0xc4(%ebp)\n" /* line 467 | ll */
        "je .Lf64b8e_00065031\n"
        "jle .Lf64b8e_00065031\n" /* line 471 */
        "movl -0x11b8(%ebp), %edi\n" /* line 473 | i */
        "cmpb $0, 0x22(%edi)\n" /* i */
        "jne .Lf64b8e_00065031\n"
        "xorl %edi, %edi\n" /* line 474 | i */
        ".Lf64b8e_00064f82:\n"
        "movl -0x117c(%ebp, %edi, 4), %eax\n" /* line 475 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl imp_cm, %ecx\n"
        "movl 0x28(%ecx), %eax\n"
        "leal (%eax, %edx, 4), %esi\n" /* leaf */
        "movl -0xfc(%ebp), %edx\n" /* line 339 */
        "testl %edx, 4(%esi)\n"
        "je .Lf64b8e_0006500d\n"
        "movl %esi, %eax\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %ecx, %ecx\n"
        /* { scope 3: vDelta, vNormal */
        /* { scope 4 */
        ".Lf64b8e_00064fac:\n"
        "movss 0xc(%eax), %xmm0\n" /* line 321 */
        "ucomiss -0x108(%ecx, %ebp), %xmm0\n"
        "jae .Lf64b8e_0006500d\n"
        "movss -0x114(%ecx, %ebp), %xmm0\n" /* line 323 */
        "ucomiss 0x18(%eax), %xmm0\n"
        "jae .Lf64b8e_0006500d\n"
        "addl $1, %ebx\n" /* line 319 | i */
        "addl $4, %ecx\n"
        "addl $4, %eax\n"
        "cmpl $3, %ebx\n" /* i */
        "jne .Lf64b8e_00064fac\n"
        "movl 0x24(%esi), %edx\n" /* line 327 */
        "leal (%edx, %edx, 4), %edx\n"
        "movl imp_cm, %ecx\n"
        "movl 0x30(%ecx), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl -0x11b8(%ebp), %ecx\n"
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "calll CM_TestInLeafBrushNode_r\n"
        /* } scope */
        /* } scope */
        "movl -0x11b8(%ebp), %eax\n" /* line 341 */
        "cmpb $0, 0x22(%eax)\n"
        "jne .Lf64b8e_00065016\n"
        "movl -0xfc(%ebp), %edx\n"
        ".Lf64b8e_0006500d:\n"
        "testl %edx, 8(%esi)\n" /* line 345 | leaf */
        "jne .Lf64b8e_000658f4\n"
        ".Lf64b8e_00065016:\n"
        "addl $1, %edi\n" /* line 471 | i */
        "cmpl %edi, -0xc4(%ebp)\n" /* i, ll */
        "jle .Lf64b8e_00065031\n"
        "movl -0x11b8(%ebp), %ecx\n" /* line 473 */
        "cmpb $0, 0x22(%ecx)\n"
        "je .Lf64b8e_00064f82\n"
        /* } scope */
        /* } scope */
        ".Lf64b8e_00065031:\n"
        "addl $0x122c, %esp\n" /* line 1420 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: box_model, leafs, ll, offset, ... */
        ".Lf64b8e_0006503c:\n"
        "subss %xmm2, %xmm0\n" /* line 1325 */
        "movss %xmm0, 0x68(%eax)\n"
        "addss %xmm2, %xmm1\n" /* line 1326 */
        "movss %xmm1, 0x74(%eax)\n"
        "jmp .Lf64b8e_00064d1f\n"
        ".Lf64b8e_00065053:\n"
        "subss -0xec(%ebp), %xmm0\n" /* line 1339 */
        "subss -0xf0(%ebp), %xmm0\n"
        "movss %xmm0, -0x10c(%ebp)\n"
        "addss -0xec(%ebp), %xmm1\n" /* line 1340 */
        "addss -0xf0(%ebp), %xmm1\n"
        "movss %xmm1, -0x100(%ebp)\n"
        "movaps %xmm1, %xmm2\n"
        "jmp .Lf64b8e_00064d72\n"
        ".Lf64b8e_0006508b:\n"
        "movss -0x120(%ebp), %xmm0\n" /* line 1385 */
        "addss -0x11c(%ebp), %xmm0\n"
        "addss -0x118(%ebp), %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "movaps %xmm1, %xmm7\n"
        "ucomiss %xmm1, %xmm0\n"
        "sete %al\n"
        "setnp %dl\n"
        "andb %dl, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0xf8(%ebp)\n"
        "movss -0xf0(%ebp), %xmm4\n" /* line 1389 */
        "movss %xmm4, -0xe8(%ebp)\n"
        "movss %xmm4, -0xe4(%ebp)\n" /* line 1390 */
        "movaps %xmm4, %xmm0\n" /* line 1391 */
        "addss -0xec(%ebp), %xmm0\n"
        "movss %xmm0, -0xe0(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1396 | model */
        "testl %eax, %eax\n"
        "je .Lf64b8e_000652ab\n"
        "cmpl $0x3ff, 0x10(%ebp)\n" /* line 1398 | model */
        "je .Lf64b8e_00065592\n"
        "movl -0x11b4(%ebp), %esi\n" /* line 1405 | box_model, leaf */
        "addl $0x1c, %esi\n" /* leaf */
        /* { scope 2: radius, fStationaryHalfHeight */
        /* { scope 3: vDelta, vNormal */
        "movl -0x11b8(%ebp), %edx\n" /* line 856 */
        "ucomiss (%edx), %xmm1\n"
        "jp .Lf64b8e_0006511b\n"
        "je .Lf64b8e_00065031\n"
        ".Lf64b8e_0006511b:\n"
        "movl -0xfc(%ebp), %edx\n" /* line 859 */
        "testl %edx, 4(%esi)\n" /* leaf */
        "jne .Lf64b8e_000658be\n"
        ".Lf64b8e_0006512a:\n"
        "testl %edx, 8(%esi)\n" /* line 870 | leaf */
        "je .Lf64b8e_00065031\n"
        "cmpw $0, 2(%esi)\n" /* line 873 | leaf */
        "je .Lf64b8e_00065031\n"
        "movl -0x11b8(%ebp), %ecx\n" /* line 875 */
        "ucomiss (%ecx), %xmm1\n"
        "jp .Lf64b8e_0006514f\n"
        "je .Lf64b8e_00065031\n"
        ".Lf64b8e_0006514f:\n"
        "xorl %ebx, %ebx\n" /* k */
        "movl -0x11b8(%ebp), %edi\n" /* i */
        ".Lf64b8e_00065157:\n"
        "movl %edi, 8(%esp)\n" /* line 880 | i */
        "movzwl (%esi), %eax\n" /* leaf */
        "leal (%ebx, %eax), %eax\n" /* k */
        "shll $5, %eax\n"
        "movl imp_cm, %edx\n"
        "addl 0x70(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "movl %eax, (%esp)\n"
        "calll CM_TraceThroughAabbTree\n"
        "addl $1, %ebx\n" /* line 873 | k */
        "movzwl 2(%esi), %eax\n" /* leaf */
        "cmpl %eax, %ebx\n" /* k */
        "jge .Lf64b8e_00065031\n"
        "pxor %xmm0, %xmm0\n" /* line 875 */
        "movl -0x11b8(%ebp), %ecx\n"
        "ucomiss (%ecx), %xmm0\n"
        "jp .Lf64b8e_000651a3\n"
        "je .Lf64b8e_00065031\n"
        ".Lf64b8e_000651a3:\n"
        "movl %ecx, %edi\n" /* i */
        "jmp .Lf64b8e_00065157\n"
        /* } scope */
        /* } scope */
        ".Lf64b8e_000651a7:\n"
        "cmpl $0x3ff, 0x10(%ebp)\n" /* line 1356 | model */
        "je .Lf64b8e_00065330\n"
        "movl -0x11b8(%ebp), %edx\n" /* line 1365 */
        "cmpb $0, 0x22(%edx)\n"
        "jne .Lf64b8e_00065031\n"
        "movl -0x11b4(%ebp), %esi\n" /* line 1366 | box_model, end */
        "addl $0x1c, %esi\n" /* end */
        "movl -0xfc(%ebp), %edx\n" /* line 339 */
        "testl %edx, 4(%esi)\n"
        "je .Lf64b8e_00065242\n"
        "movl %esi, %eax\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %ecx, %ecx\n"
        /* { scope 2: radius, fStationaryHalfHeight */
        /* { scope 3: vDelta, vNormal */
        ".Lf64b8e_000651de:\n"
        "movss 0xc(%eax), %xmm0\n" /* line 321 */
        "ucomiss -0x108(%ecx, %ebp), %xmm0\n"
        "jae .Lf64b8e_00065242\n"
        "movss -0x114(%ecx, %ebp), %xmm0\n" /* line 323 */
        "ucomiss 0x18(%eax), %xmm0\n"
        "jae .Lf64b8e_00065242\n"
        "addl $1, %ebx\n" /* line 319 | i */
        "addl $4, %ecx\n"
        "addl $4, %eax\n"
        "cmpl $3, %ebx\n" /* i */
        "jne .Lf64b8e_000651de\n"
        "movl 0x24(%esi), %edx\n" /* line 327 */
        "leal (%edx, %edx, 4), %edx\n"
        "movl imp_cm, %eax\n"
        "movl 0x30(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl -0x11b8(%ebp), %ecx\n"
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "calll CM_TestInLeafBrushNode_r\n"
        /* } scope */
        /* } scope */
        "movl -0x11b8(%ebp), %ecx\n" /* line 341 */
        "cmpb $0, 0x22(%ecx)\n"
        "jne .Lf64b8e_00065031\n"
        "movl -0xfc(%ebp), %edx\n"
        ".Lf64b8e_00065242:\n"
        "testl %edx, 8(%esi)\n" /* line 345 | leaf */
        "je .Lf64b8e_00065031\n"
        "movl -0x11b8(%ebp), %edi\n" /* line 346 */
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* leaf */
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "movl %eax, (%esp)\n"
        "calll CM_MeshTestInLeaf\n"
        "jmp .Lf64b8e_00065031\n"
        ".Lf64b8e_0006526c:\n"
        "jp .Lf64b8e_00064e30\n" /* line 310 */
        "movss 8(%ebx), %xmm0\n"
        "ucomiss 8(%esi), %xmm0\n"
        "jne .Lf64b8e_00064e30\n"
        "jp .Lf64b8e_00064e30\n"
        "movl $1, %eax\n"
        "jmp .Lf64b8e_00064e32\n"
        /* { scope 2: radius, fStationaryHalfHeight */
        ".Lf64b8e_00065291:\n"
        "movl $3, (%esp)\n" /* line 43 */
        "calll Sys_GetValue\n"
        "movl 0x14(%eax), %eax\n" /* line 47 */
        "movl %eax, -0x11b4(%ebp)\n" /* box_model */
        "jmp .Lf64b8e_00064bc4\n"
        /* } scope */
        ".Lf64b8e_000652ab:\n"
        "movl -0x17c(%ebp), %eax\n" /* line 199 | tw */
        "movl %eax, -0x98(%ebp)\n" /* start_ */
        "movl -0x178(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x94(%ebp)\n"
        "movl -0x174(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x90(%ebp)\n"
        "movl $0, -0x8c(%ebp)\n" /* line 1411 */
        "movl -0x170(%ebp), %eax\n" /* line 199 */
        "movl %eax, -0x88(%ebp)\n" /* end_ */
        "movl -0x16c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x84(%ebp)\n"
        "movl -0x168(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x80(%ebp)\n"
        "movl -0x11b8(%ebp), %edx\n" /* line 1413 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "leal -0x98(%ebp), %ecx\n" /* line 1415 | start_ */
        "movl %edx, 4(%esp)\n"
        "leal -0x88(%ebp), %eax\n" /* end_ */
        "movl %eax, (%esp)\n"
        "xorl %edx, %edx\n"
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "calll CM_TraceThroughTree\n"
        /* } scope */
        "addl $0x122c, %esp\n" /* line 1420 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: box_model, leafs, ll, offset, ... */
        ".Lf64b8e_00065330:\n"
        "movl -0xcc(%ebp), %eax\n" /* line 1358 */
        "movl 0xc(%eax), %eax\n"
        "testl %eax, -0xfc(%ebp)\n"
        "je .Lf64b8e_00065031\n"
        /* { scope 2: radius, fStationaryHalfHeight */
        "movss -0x17c(%ebp), %xmm6\n" /* line 199 | tw */
        "movss -0x178(%ebp), %xmm7\n" /* line 200 */
        "movss -0x174(%ebp), %xmm2\n" /* line 201 */
        "movss %xmm2, -0x11bc(%ebp)\n"
        "movss -0xec(%ebp), %xmm0\n" /* line 368 */
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x118c(%ebp)\n"
        "movss -0x11bc(%ebp), %xmm1\n" /* line 370 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x119c(%ebp)\n"
        "movl -0xc8(%ebp), %eax\n"
        "movl $1, %ecx\n"
        "movss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "leal -0x78(%ebp), %esi\n" /* offset, leaf */
        "leal -0x117c(%ebp), %ebx\n" /* leafs, i */
        "movl $4, %edx\n"
        ".Lf64b8e_000653ae:\n"
        "movss (%eax), %xmm0\n" /* line 374 */
        "movss 0xc(%eax), %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, -4(%edx, %esi)\n"
        "subss %xmm1, %xmm0\n" /* line 375 */
        "movss %xmm0, -4(%edx, %ebx)\n"
        "subss %xmm1, %xmm2\n" /* line 376 */
        "movss %xmm2, 8(%edx, %ebx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 372 */
        "jne .Lf64b8e_000653ae\n"
        "movss -0x1170(%ebp), %xmm1\n" /* line 378 */
        "movss -0x1168(%ebp), %xmm0\n" /* line 379 */
        "movaps %xmm0, %xmm2\n" /* line 380 */
        "minss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm4\n" /* line 381 */
        "subss %xmm2, %xmm4\n"
        "movaps %xmm2, %xmm5\n" /* line 383 */
        "addss -0xf0(%ebp), %xmm5\n"
        "mulss %xmm5, %xmm5\n"
        "movss -0x78(%ebp), %xmm0\n" /* line 199 | offset */
        "movss %xmm0, -0x1190(%ebp)\n"
        "movss -0x74(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, -0x1194(%ebp)\n"
        "movss -0x70(%ebp), %xmm2\n" /* line 201 */
        "movss %xmm2, -0x1198(%ebp)\n"
        "addss %xmm4, %xmm2\n" /* line 386 */
        "movaps %xmm0, %xmm3\n" /* line 248 */
        "subss %xmm6, %xmm3\n"
        "movaps %xmm1, %xmm0\n" /* line 249 */
        "subss %xmm7, %xmm0\n"
        "movaps %xmm2, %xmm1\n" /* line 250 */
        "subss -0x118c(%ebp), %xmm1\n"
        "mulss %xmm3, %xmm3\n" /* line 316 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "mulss %xmm1, %xmm1\n" /* line 388 */
        "addss %xmm3, %xmm1\n"
        "ucomiss %xmm1, %xmm5\n"
        "jbe .Lf64b8e_00065488\n"
        "movl -0x11b8(%ebp), %eax\n" /* line 390 */
        "movb $1, 0x22(%eax)\n"
        "movb $1, 0x23(%eax)\n"
        "movl $0, (%eax)\n" /* line 391 */
        ".Lf64b8e_00065488:\n"
        "subss -0x119c(%ebp), %xmm2\n" /* line 250 */
        "mulss %xmm2, %xmm2\n" /* line 394 */
        "addss %xmm3, %xmm2\n"
        "ucomiss %xmm2, %xmm5\n"
        "jbe .Lf64b8e_000654b1\n"
        "movl -0x11b8(%ebp), %edx\n" /* line 396 */
        "movb $1, 0x22(%edx)\n"
        "movb $1, 0x23(%edx)\n"
        "movl $0, (%edx)\n" /* line 397 */
        ".Lf64b8e_000654b1:\n"
        "movss -0x1198(%ebp), %xmm1\n" /* line 400 */
        "subss %xmm4, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 250 */
        "subss -0x118c(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n" /* line 402 */
        "addss %xmm3, %xmm0\n"
        "ucomiss %xmm0, %xmm5\n"
        "jbe .Lf64b8e_000654e9\n"
        "movl -0x11b8(%ebp), %ecx\n" /* line 404 */
        "movb $1, 0x22(%ecx)\n"
        "movb $1, 0x23(%ecx)\n"
        "movl $0, (%ecx)\n" /* line 405 */
        ".Lf64b8e_000654e9:\n"
        "subss -0x119c(%ebp), %xmm1\n" /* line 250 */
        "mulss %xmm1, %xmm1\n" /* line 408 */
        "addss %xmm1, %xmm3\n"
        "ucomiss %xmm3, %xmm5\n"
        "jbe .Lf64b8e_00065512\n"
        "movl -0x11b8(%ebp), %edi\n" /* line 410 */
        "movb $1, 0x22(%edi)\n"
        "movb $1, 0x23(%edi)\n"
        "movl $0, (%edi)\n" /* line 411 */
        ".Lf64b8e_00065512:\n"
        "addss -0x118(%ebp), %xmm4\n" /* line 417 */
        "subss -0xf0(%ebp), %xmm4\n"
        "movss -0x11bc(%ebp), %xmm0\n"
        "subss -0x70(%ebp), %xmm0\n"
        "movss %xmm0, -0x11bc(%ebp)\n"
        "andl $0x7fffffff, -0x11bc(%ebp)\n"
        "ucomiss -0x11bc(%ebp), %xmm4\n"
        "jb .Lf64b8e_00065031\n"
        "subss -0x1190(%ebp), %xmm6\n" /* line 248 */
        "subss -0x1194(%ebp), %xmm7\n" /* line 249 */
        "mulss %xmm6, %xmm6\n" /* line 423 */
        "mulss %xmm7, %xmm7\n"
        "addss %xmm7, %xmm6\n"
        "pxor %xmm0, %xmm0\n"
        "addss %xmm0, %xmm6\n"
        "ucomiss %xmm6, %xmm5\n"
        "jbe .Lf64b8e_00065031\n"
        "movl -0x11b8(%ebp), %eax\n" /* line 425 */
        "movb $1, 0x22(%eax)\n"
        "movb $1, 0x23(%eax)\n"
        "movss %xmm0, (%eax)\n" /* line 426 */
        "jmp .Lf64b8e_00065031\n"
        /* } scope */
        ".Lf64b8e_00065592:\n"
        "movl -0xcc(%ebp), %eax\n" /* line 1400 */
        "movl 0xc(%eax), %eax\n"
        "testl %eax, -0xfc(%ebp)\n"
        "je .Lf64b8e_00065031\n"
        /* { scope 2: radius, fStationaryHalfHeight */
        "movl -0xc8(%ebp), %ecx\n" /* line 1045 */
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movss 0xc(%ecx), %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movss -0x114(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf64b8e_00065031\n"
        "movss 0x10(%ecx), %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movss -0x110(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf64b8e_00065031\n"
        "movss 0x14(%ecx), %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movss -0x10c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf64b8e_00065031\n"
        "movss (%ecx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss -0x108(%ebp), %xmm0\n"
        "ja .Lf64b8e_00065031\n"
        "movss 4(%ecx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss -0x104(%ebp), %xmm0\n"
        "ja .Lf64b8e_00065031\n"
        "movss 8(%ecx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss -0x100(%ebp), %xmm0\n"
        "ja .Lf64b8e_00065031\n"
        "movss -0x17c(%ebp), %xmm5\n" /* line 199 | tw */
        "movss %xmm5, -0x3c(%ebp)\n" /* starttop */
        "movss -0x178(%ebp), %xmm6\n" /* line 200 */
        "movss %xmm6, -0x38(%ebp)\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x11bc(%ebp)\n"
        "addss -0xec(%ebp), %xmm0\n" /* line 1062 */
        "movss %xmm0, -0x34(%ebp)\n"
        "movss %xmm5, -0x48(%ebp)\n" /* line 199 | startbottom */
        "movss %xmm6, -0x44(%ebp)\n" /* line 200 */
        "movss -0x11bc(%ebp), %xmm0\n" /* line 1064 */
        "subss -0xec(%ebp), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movl -0x170(%ebp), %edx\n" /* line 199 */
        "movl %edx, -0x54(%ebp)\n" /* endtop */
        "movl -0x16c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x50(%ebp)\n"
        "movss -0x168(%ebp), %xmm1\n" /* line 201 */
        "movaps %xmm1, %xmm0\n" /* line 1067 */
        "addss -0xec(%ebp), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movl %edx, -0x60(%ebp)\n" /* line 199 | endbottom */
        "movl %eax, -0x5c(%ebp)\n" /* line 200 */
        "subss -0xec(%ebp), %xmm1\n" /* line 1069 */
        "movss %xmm1, -0x58(%ebp)\n"
        "movl %ecx, %eax\n"
        "movl $1, %ebx\n" /* k */
        "movss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "leal -0xc4(%ebp), %ecx\n" /* ll */
        "leal -0x6c(%ebp), %esi\n" /* offset, leaf */
        "movl $4, %edx\n"
        ".Lf64b8e_000656f4:\n"
        "movss (%eax), %xmm0\n" /* line 1074 */
        "movss 0xc(%eax), %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, -4(%edx, %esi)\n"
        "subss %xmm1, %xmm0\n" /* line 1075 */
        "movss %xmm0, -4(%edx, %ecx)\n"
        "subss %xmm1, %xmm2\n" /* line 1076 */
        "movss %xmm2, 8(%edx, %ecx)\n"
        "addl $1, %ebx\n" /* k */
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %ebx\n" /* line 1072 | k */
        "jne .Lf64b8e_000656f4\n"
        "movss -0xb8(%ebp), %xmm1\n" /* line 1078 */
        "movss -0xb0(%ebp), %xmm0\n" /* line 1079 */
        "movaps %xmm0, %xmm2\n" /* line 1080 */
        "minss %xmm1, %xmm2\n"
        "movss %xmm2, -0x11a4(%ebp)\n" /* radius */
        "subss %xmm2, %xmm0\n" /* line 1081 */
        "movss %xmm0, -0x11a0(%ebp)\n" /* fStationaryHalfHeight */
        "movss -0x6c(%ebp), %xmm0\n" /* line 199 | offset */
        "movss %xmm0, -0x11b0(%ebp)\n"
        "movss %xmm0, -0x117c(%ebp)\n" /* leafs */
        "movss -0x68(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, -0x11ac(%ebp)\n"
        "movss %xmm1, -0x1178(%ebp)\n"
        "movss -0x64(%ebp), %xmm2\n" /* line 201 */
        "movss %xmm2, -0x11a8(%ebp)\n"
        "movss -0x11a0(%ebp), %xmm0\n" /* line 1083 | fStationaryHalfHeight */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x1174(%ebp)\n"
        "movss -0x11b0(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x30(%ebp)\n" /* bottom */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 200 */
        "movaps %xmm2, %xmm1\n" /* line 1085 */
        "subss -0x11a0(%ebp), %xmm1\n" /* fStationaryHalfHeight */
        "movss %xmm1, -0x28(%ebp)\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 1088 */
        "ucomiss -0x1174(%ebp), %xmm0\n"
        "ja .Lf64b8e_00065960\n"
        "ucomiss -0x34(%ebp), %xmm1\n" /* line 1095 */
        "ja .Lf64b8e_000659d6\n"
        /* { scope 3: vDelta, vNormal */
        /* { scope 4 */
        ".Lf64b8e_000657e4:\n"
        "movaps %xmm5, %xmm3\n" /* line 248 */
        "subss -0x11b0(%ebp), %xmm3\n"
        "movss %xmm3, -0x78(%ebp)\n" /* offset */
        "movaps %xmm6, %xmm5\n" /* line 249 */
        "subss -0x11ac(%ebp), %xmm5\n"
        "movss %xmm5, -0x74(%ebp)\n"
        "movss -0x11bc(%ebp), %xmm6\n" /* line 250 */
        "subss -0x11a8(%ebp), %xmm6\n"
        "movss %xmm6, -0x70(%ebp)\n"
        "movss -0x11a4(%ebp), %xmm0\n" /* line 971 | radius */
        "addss %xmm4, %xmm0\n"
        "movaps %xmm3, %xmm2\n" /* line 972 */
        "mulss %xmm3, %xmm2\n"
        "movaps %xmm5, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "ucomiss %xmm2, %xmm7\n" /* line 973 */
        "jae .Lf64b8e_00065a19\n"
        "movss -0x158(%ebp), %xmm1\n" /* line 114 */
        "movss -0x154(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm3\n"
        "mulss %xmm0, %xmm5\n"
        "addss %xmm5, %xmm3\n"
        "ucomiss %xmm7, %xmm3\n" /* line 996 */
        "jb .Lf64b8e_00065ae4\n"
        /* } scope */
        /* } scope */
        ".Lf64b8e_0006586d:\n"
        "movss -0x1174(%ebp), %xmm1\n" /* line 1108 */
        "movss -0x58(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf64b8e_00065915\n"
        "ucomiss -0x40(%ebp), %xmm1\n" /* line 1110 */
        "jb .Lf64b8e_00065031\n"
        "leal -0x60(%ebp), %ecx\n" /* line 1111 | endbottom */
        "leal -0x48(%ebp), %edx\n" /* startbottom */
        "movl -0x11b8(%ebp), %edi\n" /* i */
        "movl %edi, 4(%esp)\n" /* i */
        "leal -0x117c(%ebp), %eax\n" /* leafs */
        "movl %eax, (%esp)\n"
        "movss -0x11a4(%ebp), %xmm0\n" /* radius */
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "calll CM_TraceSphereThroughSphere\n"
        "jmp .Lf64b8e_00065031\n"
        /* } scope */
        /* { scope 2: radius, fStationaryHalfHeight */
        /* { scope 3: vDelta, vNormal */
        ".Lf64b8e_000658be:\n"
        "movl -0x11b8(%ebp), %ecx\n" /* line 862 */
        "movl %esi, %edx\n" /* leaf */
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "movss %xmm1, -0x11e8(%ebp)\n"
        "calll CM_TraceThroughLeafBrushNode\n"
        "testb %al, %al\n"
        "movss -0x11e8(%ebp), %xmm1\n"
        "jne .Lf64b8e_00065031\n"
        "movl -0xfc(%ebp), %edx\n"
        "jmp .Lf64b8e_0006512a\n"
        /* } scope */
        /* } scope */
        /* { scope 2: radius, fStationaryHalfHeight */
        ".Lf64b8e_000658f4:\n"
        "movl -0x11b8(%ebp), %edx\n" /* line 346 */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* leaf */
        "leal -0x17c(%ebp), %ecx\n" /* tw */
        "movl %ecx, (%esp)\n"
        "calll CM_MeshTestInLeaf\n"
        "jmp .Lf64b8e_00065016\n"
        /* } scope */
        /* { scope 2: radius, fStationaryHalfHeight */
        ".Lf64b8e_00065915:\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 1113 */
        "ucomiss -0x4c(%ebp), %xmm1\n"
        "jbe .Lf64b8e_00065031\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 1115 */
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf64b8e_00065031\n"
        "leal -0x54(%ebp), %ecx\n" /* line 1116 | endtop */
        "leal -0x3c(%ebp), %edx\n" /* starttop */
        "movl -0x11b8(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* bottom */
        "movl %eax, (%esp)\n"
        "movss -0x11a4(%ebp), %xmm0\n" /* radius */
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "calll CM_TraceSphereThroughSphere\n"
        "jmp .Lf64b8e_00065031\n"
        ".Lf64b8e_00065960:\n"
        "leal -0x60(%ebp), %ecx\n" /* line 1090 | endbottom */
        "leal -0x48(%ebp), %edx\n" /* startbottom */
        "movl -0x11b8(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x117c(%ebp), %eax\n" /* leafs */
        "movl %eax, (%esp)\n"
        "movss -0x11a4(%ebp), %xmm0\n" /* radius */
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "calll CM_TraceSphereThroughSphere\n"
        "testl %eax, %eax\n"
        "je .Lf64b8e_00065031\n"
        "pxor %xmm7, %xmm7\n" /* line 1092 */
        "movss -0x150(%ebp), %xmm0\n"
        "ucomiss %xmm7, %xmm0\n"
        "jae .Lf64b8e_00065031\n"
        ".Lf64b8e_000659a9:\n"
        "movss -0x174(%ebp), %xmm0\n"
        "movss %xmm0, -0x11bc(%ebp)\n"
        "movss -0x17c(%ebp), %xmm5\n" /* tw */
        "movss -0x178(%ebp), %xmm6\n"
        "movss -0xf0(%ebp), %xmm4\n"
        "jmp .Lf64b8e_000657e4\n"
        ".Lf64b8e_000659d6:\n"
        "leal -0x54(%ebp), %ecx\n" /* line 1097 | endtop */
        "leal -0x3c(%ebp), %edx\n" /* starttop */
        "movl -0x11b8(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* bottom */
        "movl %eax, (%esp)\n"
        "movss -0x11a4(%ebp), %xmm0\n" /* radius */
        "leal -0x17c(%ebp), %eax\n" /* tw */
        "calll CM_TraceSphereThroughSphere\n"
        "testl %eax, %eax\n"
        "je .Lf64b8e_00065031\n"
        "pxor %xmm7, %xmm7\n" /* line 1099 */
        "ucomiss -0x150(%ebp), %xmm7\n"
        "jb .Lf64b8e_000659a9\n"
        "jmp .Lf64b8e_00065031\n"
        /* { scope 3: vDelta, vNormal */
        /* { scope 4 */
        ".Lf64b8e_00065a19:\n"
        "movss -0x118(%ebp), %xmm1\n" /* line 976 */
        "subss %xmm4, %xmm1\n"
        "addss -0x11a0(%ebp), %xmm1\n" /* fStationaryHalfHeight */
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+384, %xmm6\n" /* line 978 */
        "ucomiss %xmm1, %xmm6\n"
        "ja .Lf64b8e_0006586d\n"
        "movl -0x11b8(%ebp), %eax\n" /* line 981 */
        "movss %xmm7, (%eax)\n"
        "movb $1, 0x23(%eax)\n" /* line 982 */
        "movss %xmm7, -0x70(%ebp)\n" /* line 983 */
        "movl -0x11b8(%ebp), %eax\n" /* line 984 */
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* offset */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x11e8(%ebp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movl -0xcc(%ebp), %eax\n" /* line 985 */
        "movl 0xc(%eax), %eax\n"
        "movl -0x11b8(%ebp), %edx\n"
        "movl %eax, 0x14(%edx)\n"
        "movss -0x170(%ebp), %xmm0\n" /* line 248 */
        "subss -0x11b0(%ebp), %xmm0\n"
        "movss %xmm0, -0x78(%ebp)\n" /* offset */
        "movss -0x16c(%ebp), %xmm0\n" /* line 249 */
        "subss -0x11ac(%ebp), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movss -0x168(%ebp), %xmm0\n" /* line 250 */
        "subss -0x11a8(%ebp), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+384, %xmm0\n" /* line 989 */
        "movss -0x11e8(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf64b8e_00065031\n"
        "movb $1, 0x22(%edx)\n" /* line 990 */
        "jmp .Lf64b8e_00065031\n"
        ".Lf64b8e_00065ae4:\n"
        "movaps %xmm1, %xmm4\n" /* line 114 */
        "mulss %xmm1, %xmm4\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm3, %xmm0\n" /* line 1001 */
        "mulss %xmm3, %xmm0\n"
        "mulss %xmm4, %xmm2\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm7\n" /* line 1002 */
        "ja .Lf64b8e_0006586d\n"
        "movss %xmm7, -0x70(%ebp)\n" /* line 1007 */
        "leal -0x24(%ebp), %eax\n" /* line 1008 | vNormal */
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* offset */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x11d8(%ebp)\n"
        "movss %xmm3, -0x11f8(%ebp)\n"
        "movss %xmm4, -0x1208(%ebp)\n"
        "movss %xmm7, -0x1218(%ebp)\n"
        "calll Vec3NormalizeTo\n"
        "fstps -0x121c(%ebp)\n"
        "movss -0x121c(%ebp), %xmm2\n"
        "mulss lit4_002ed610, %xmm2\n" /* line 1009 | 0.125f */
        "movss -0x11f8(%ebp), %xmm3\n"
        "divss %xmm3, %xmm2\n"
        "movaps %xmm3, %xmm1\n" /* line 1010 */
        "xorps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+400, %xmm1\n"
        "movss -0x11d8(%ebp), %xmm0\n" /* line 81 */
        "sqrtss %xmm0, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss -0x1208(%ebp), %xmm4\n"
        "divss %xmm4, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movl -0x11b8(%ebp), %ecx\n" /* line 1011 */
        "movss (%ecx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "movss -0x1218(%ebp), %xmm7\n"
        "jbe .Lf64b8e_0006586d\n"
        "movss -0x118(%ebp), %xmm0\n" /* line 1016 */
        "subss -0xf0(%ebp), %xmm0\n"
        "addss -0x11a0(%ebp), %xmm0\n" /* fStationaryHalfHeight */
        "movss %xmm0, -0x11a0(%ebp)\n" /* fStationaryHalfHeight */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss -0x150(%ebp), %xmm0\n"
        "addss -0x174(%ebp), %xmm0\n"
        "subss -0x11a8(%ebp), %xmm0\n"
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+384, %xmm0\n"
        "ucomiss -0x11a0(%ebp), %xmm0\n" /* fStationaryHalfHeight */
        "ja .Lf64b8e_0006586d\n"
        /* { scope 5 */
        "maxss %xmm1, %xmm7\n" /* line 45 */
        /* } scope */
        "movss %xmm7, (%ecx)\n" /* line 1019 */
        "movl %ecx, %edx\n" /* line 1021 | to */
        "addl $4, %edx\n" /* to */
        /* { scope 5 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | vNormal */
        "movl %eax, 4(%ecx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl -0xcc(%ebp), %eax\n" /* line 1022 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "jmp .Lf64b8e_00065031\n"
    );
}

/* line 1428 */
__attribute__((naked))
int CM_BoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1428 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %eax\n" /* results, model */
        "movl %eax, -0x10(%ebp)\n" /* model, results */
        "movl 0xc(%ebp), %edx\n" /* start */
        "movl 0x10(%ebp), %ecx\n" /* end */
        "movl %ecx, -0x14(%ebp)\n" /* end */
        "movl 0x14(%ebp), %esi\n" /* mins */
        "cld\n" /* line 1430 */
        "movl $9, %ebx\n"
        "xorl %eax, %eax\n"
        "movl -0x10(%ebp), %edi\n" /* results */
        "movl %ebx, %ecx\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl -0x10(%ebp), %eax\n" /* line 1431 | results */
        "movl $0x3f800000, (%eax)\n"
        "movl 0x20(%ebp), %eax\n" /* line 1432 | brushmask */
        "movl %eax, 0x14(%ebp)\n" /* mins */
        "movl 0x1c(%ebp), %eax\n" /* model */
        "movl %eax, 0x10(%ebp)\n" /* end */
        "movl 0x18(%ebp), %eax\n" /* maxs */
        "movl %eax, 0xc(%ebp)\n" /* start */
        "movl %esi, 8(%ebp)\n" /* mins, results */
        "movl -0x14(%ebp), %ecx\n" /* end */
        "movl -0x10(%ebp), %eax\n" /* results */
        "addl $8, %esp\n" /* line 1433 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp CM_Trace\n" /* line 1432 */
    );
}

/* line 2167 */
__attribute__((naked))
int CM_BoxSightTrace(int oldHitNum, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2167 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1cc, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* end */
        "movl 0x14(%ebp), %esi\n" /* mins */
        /* { scope 1: box_model, top, bottom, starttop, ... */
        /* { scope 2: radius, fStationaryHalfHeight */
        "movl imp_cm, %eax\n" /* line 85 */
        "movl 0x1c(%ebp), %edx\n" /* model */
        "cmpl 0x74(%eax), %edx\n"
        "jge .Lf65c86_00066373\n"
        "leal (%edx, %edx, 8), %edx\n" /* line 86 */
        "movl 0x78(%eax), %eax\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl %edx, -0x19c(%ebp)\n" /* box_model */
        /* } scope */
        ".Lf65c86_00065cb8:\n"
        "movl $0x3f800000, -0xc0(%ebp)\n" /* line 2183 | trace */
        "movb $0, -0x9d(%ebp)\n" /* line 2184 */
        "movb $0, -0x9e(%ebp)\n" /* line 2185 */
        "movl 0x20(%ebp), %eax\n" /* line 2188 | brushmask */
        "movl %eax, -0xf8(%ebp)\n"
        "movl $1, %ecx\n"
        "movss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+416, %xmm2\n"
        "movl $4, %edx\n"
        "leal -0x128(%ebp), %eax\n"
        ".Lf65c86_00065cf9:\n"
        "movl 0x18(%ebp), %ebx\n" /* line 2196 | maxs */
        "movss -4(%edx, %ebx), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "addss -4(%edx, %esi), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "subss %xmm0, %xmm1\n" /* line 2197 */
        "movss %xmm1, 0xc(%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 2198 */
        "movl 0xc(%ebp), %ebx\n" /* start */
        "addss -4(%edx, %ebx), %xmm1\n"
        "movss %xmm1, -0x50(%eax)\n"
        "addss -4(%edx, %edi), %xmm0\n" /* line 2199 */
        "movss %xmm0, -0x44(%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 2200 */
        "addss -0x50(%eax), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, -0x18(%eax)\n"
        "subss -0x50(%eax), %xmm0\n" /* line 2201 */
        "movss %xmm0, -0x158(%edx, %ebp)\n"
        "mulss %xmm3, %xmm0\n" /* line 2202 */
        "movss %xmm0, -0x138(%edx, %ebp)\n"
        "andps %xmm2, %xmm0\n" /* line 2203 */
        "movss %xmm0, (%eax)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 2193 */
        "jne .Lf65c86_00065cf9\n"
        "leal -0x178(%ebp), %eax\n" /* line 2205 | tw */
        "movl %eax, (%esp)\n"
        "calll CM_CalcTraceEntents\n"
        "movss -0x154(%ebp), %xmm0\n" /* line 316 */
        "movss -0x150(%ebp), %xmm1\n"
        "movss -0x14c(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x144(%ebp)\n" /* line 2206 */
        "sqrtss %xmm0, %xmm0\n" /* line 81 */
        "movss %xmm0, -0x148(%ebp)\n"
        "movss -0x11c(%ebp), %xmm3\n" /* line 2212 */
        "movss -0x114(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movaps %xmm3, %xmm1\n"
        "cmpnltss %xmm3, %xmm2\n"
        "andps %xmm2, %xmm1\n"
        "andnps %xmm0, %xmm2\n"
        "orps %xmm1, %xmm2\n"
        "movss %xmm2, -0xec(%ebp)\n"
        "subss %xmm2, %xmm0\n" /* line 2214 */
        "movss %xmm0, -0xe8(%ebp)\n"
        "leal -0x178(%ebp), %eax\n" /* tw */
        "leal -0x170(%ebp), %edx\n"
        ".Lf65c86_00065e07:\n"
        "movss (%eax), %xmm1\n" /* line 2221 */
        "movss 0xc(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf65c86_00065fae\n"
        "subss %xmm2, %xmm1\n" /* line 2223 */
        "movss %xmm1, 0x68(%eax)\n"
        "addss %xmm2, %xmm0\n" /* line 2224 */
        "movss %xmm0, 0x74(%eax)\n"
        ".Lf65c86_00065e2b:\n"
        "addl $4, %eax\n" /* line 2229 */
        "cmpl %eax, %edx\n" /* line 2219 */
        "jne .Lf65c86_00065e07\n"
        "movss -0x170(%ebp), %xmm1\n" /* line 2235 */
        "movss -0x164(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf65c86_00066011\n"
        "subss -0xe8(%ebp), %xmm1\n" /* line 2237 */
        "subss -0xec(%ebp), %xmm1\n"
        "movss %xmm1, -0x108(%ebp)\n"
        "addss -0xe8(%ebp), %xmm0\n" /* line 2238 */
        "addss -0xec(%ebp), %xmm0\n"
        "movss %xmm0, -0xfc(%ebp)\n"
        "movaps %xmm0, %xmm2\n"
        ".Lf65c86_00065e7e:\n"
        "subss -0x108(%ebp), %xmm2\n" /* line 1258 */
        "movss -0x104(%ebp), %xmm1\n"
        "subss -0x110(%ebp), %xmm1\n"
        "movss -0x100(%ebp), %xmm0\n"
        "subss -0x10c(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "movaps %xmm3, %xmm0\n"
        "mulss -0x118(%ebp), %xmm0\n"
        "mulss -0x114(%ebp), %xmm0\n"
        "mulss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "mulss -0x148(%ebp), %xmm0\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm2, %xmm0\n"
        "seta %al\n"
        "movl %eax, -0xf0(%ebp)\n"
        "addss -0x118(%ebp), %xmm3\n" /* line 2255 */
        "addss -0x114(%ebp), %xmm3\n"
        "ucomiss lit4_002ed5e8, %xmm3\n" /* 0.0f */
        "sete %al\n"
        "setnp %dl\n"
        "andb %dl, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0xf4(%ebp)\n"
        "movss -0xec(%ebp), %xmm0\n" /* line 2259 */
        "movss %xmm0, -0xe4(%ebp)\n"
        "movss %xmm0, -0xe0(%ebp)\n" /* line 2260 */
        "addss -0xe8(%ebp), %xmm0\n" /* line 2261 */
        "movss %xmm0, -0xdc(%ebp)\n"
        "movl $3, (%esp)\n" /* line 22 */
        "calll Sys_GetValue\n"
        "movl (%eax), %edx\n" /* line 25 */
        "addl $1, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %edx, -0xd8(%ebp)\n" /* line 27 */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0xd4(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0xd0(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0xc8(%ebp)\n"
        "movl 0x14(%eax), %ecx\n"
        "movl %ecx, -0xc4(%ebp)\n"
        "movl 0x1c(%ebp), %ebx\n" /* line 2268 | model */
        "testl %ebx, %ebx\n"
        "je .Lf65c86_00065fc5\n"
        "cmpl $0x3ff, 0x1c(%ebp)\n" /* line 2270 | model */
        "je .Lf65c86_00066049\n"
        "leal -0xc0(%ebp), %ecx\n" /* line 2279 | trace */
        "movl -0x19c(%ebp), %edx\n" /* box_model */
        "addl $0x1c, %edx\n"
        "leal -0x178(%ebp), %eax\n" /* tw */
        "calll CM_SightTraceThroughLeaf\n"
        /* } scope */
        "addl $0x1cc, %esp\n" /* line 2299 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: box_model, top, bottom, starttop, ... */
        ".Lf65c86_00065fae:\n"
        "subss %xmm2, %xmm0\n" /* line 2228 */
        "movss %xmm0, 0x68(%eax)\n"
        "addss %xmm2, %xmm1\n" /* line 2229 */
        "movss %xmm1, 0x74(%eax)\n"
        "jmp .Lf65c86_00065e2b\n"
        ".Lf65c86_00065fc5:\n"
        "movl 8(%ebp), %ecx\n" /* line 2285 | oldHitNum */
        "testl %ecx, %ecx\n"
        "jle .Lf65c86_00065fe4\n"
        "movl 8(%ebp), %edx\n" /* line 2288 | oldHitNum */
        "subl $1, %edx\n"
        "movl imp_cm, %ecx\n" /* line 2289 */
        "movzwl 0x7c(%ecx), %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lf65c86_0006638d\n"
        ".Lf65c86_00065fe4:\n"
        "leal -0xc0(%ebp), %eax\n" /* line 2294 | trace */
        "movl %eax, 4(%esp)\n"
        "leal -0x16c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "leal -0x178(%ebp), %ecx\n" /* tw */
        "xorl %edx, %edx\n"
        "movl %ecx, %eax\n"
        "calll CM_SightTraceThroughTree\n"
        /* } scope */
        ".Lf65c86_00066006:\n"
        "addl $0x1cc, %esp\n" /* line 2299 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: box_model, top, bottom, starttop, ... */
        ".Lf65c86_00066011:\n"
        "subss -0xe8(%ebp), %xmm0\n" /* line 2242 */
        "subss -0xec(%ebp), %xmm0\n"
        "movss %xmm0, -0x108(%ebp)\n"
        "addss -0xe8(%ebp), %xmm1\n" /* line 2243 */
        "addss -0xec(%ebp), %xmm1\n"
        "movss %xmm1, -0xfc(%ebp)\n"
        "movaps %xmm1, %xmm2\n"
        "jmp .Lf65c86_00065e7e\n"
        ".Lf65c86_00066049:\n"
        "movl 0xc(%edx), %eax\n" /* line 2272 */
        "testl %eax, -0xf8(%ebp)\n"
        "je .Lf65c86_00066366\n"
        /* { scope 2: radius, fStationaryHalfHeight */
        "movss lit4_002ed5d0, %xmm2\n" /* line 1959 | 1.0f */
        "movss 0xc(%ecx), %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movss -0x110(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf65c86_00066366\n"
        "movss 0x10(%ecx), %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movss -0x10c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf65c86_00066366\n"
        "movss 0x14(%ecx), %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movss -0x108(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf65c86_00066366\n"
        "movss (%ecx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss -0x104(%ebp), %xmm0\n"
        "ja .Lf65c86_00066366\n"
        "movss 4(%ecx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss -0x100(%ebp), %xmm0\n"
        "ja .Lf65c86_00066366\n"
        "movss 8(%ecx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss -0xfc(%ebp), %xmm0\n"
        "ja .Lf65c86_00066366\n"
        "movss -0x178(%ebp), %xmm4\n" /* line 199 | tw */
        "movss %xmm4, -0x6c(%ebp)\n" /* starttop */
        "movss -0x174(%ebp), %xmm5\n" /* line 200 */
        "movss %xmm5, -0x68(%ebp)\n"
        "movss -0x170(%ebp), %xmm6\n" /* line 201 */
        "movss -0xe8(%ebp), %xmm2\n" /* line 1976 */
        "movaps %xmm2, %xmm0\n"
        "addss %xmm6, %xmm0\n"
        "movss %xmm0, -0x198(%ebp)\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "movss %xmm4, -0x78(%ebp)\n" /* line 199 | startbottom */
        "movss %xmm5, -0x74(%ebp)\n" /* line 200 */
        "movaps %xmm6, %xmm7\n" /* line 1978 */
        "subss %xmm2, %xmm7\n"
        "movss %xmm7, -0x70(%ebp)\n"
        "movl -0x16c(%ebp), %edx\n" /* line 199 */
        "movl %edx, -0x84(%ebp)\n" /* endtop */
        "movl -0x168(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x80(%ebp)\n"
        "movss -0x164(%ebp), %xmm1\n" /* line 201 */
        "movaps %xmm2, %xmm0\n" /* line 1981 */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        "movl %edx, -0x30(%ebp)\n" /* line 199 | endbottom */
        "movl %eax, -0x2c(%ebp)\n" /* line 200 */
        "subss %xmm2, %xmm1\n" /* line 1983 */
        "movss %xmm1, -0x28(%ebp)\n"
        "movl %ecx, %eax\n"
        "movl $1, %ecx\n"
        "movss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "leal -0x3c(%ebp), %esi\n" /* offset */
        "leal -0x9c(%ebp), %ebx\n" /* symetricSize */
        "movl $4, %edx\n"
        ".Lf65c86_00066198:\n"
        "movss (%eax), %xmm0\n" /* line 1988 */
        "movss 0xc(%eax), %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, -4(%edx, %esi)\n"
        "subss %xmm1, %xmm0\n" /* line 1989 */
        "movss %xmm0, -4(%edx, %ebx)\n"
        "subss %xmm1, %xmm2\n" /* line 1990 */
        "movss %xmm2, 8(%edx, %ebx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 1986 */
        "jne .Lf65c86_00066198\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 1992 */
        "movss %xmm1, -0x188(%ebp)\n" /* radius */
        "movss -0x88(%ebp), %xmm0\n" /* line 1993 */
        "movaps %xmm0, %xmm1\n" /* line 1994 */
        "minss -0x188(%ebp), %xmm1\n" /* radius */
        "movss %xmm1, -0x188(%ebp)\n" /* radius */
        "subss %xmm1, %xmm0\n" /* line 1995 */
        "movss %xmm0, -0x184(%ebp)\n" /* fStationaryHalfHeight */
        "movss -0x3c(%ebp), %xmm0\n" /* line 199 | offset */
        "movss %xmm0, -0x194(%ebp)\n"
        "movss %xmm0, -0x54(%ebp)\n" /* top */
        "movss -0x38(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, -0x190(%ebp)\n"
        "movss %xmm1, -0x50(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x18c(%ebp)\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss -0x184(%ebp), %xmm0\n" /* line 1997 | fStationaryHalfHeight */
        "addss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss -0x194(%ebp), %xmm1\n" /* line 199 */
        "movss %xmm1, -0x60(%ebp)\n" /* bottom */
        "movss -0x190(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, -0x5c(%ebp)\n"
        "movss -0x18c(%ebp), %xmm1\n" /* line 1999 */
        "subss -0x184(%ebp), %xmm1\n" /* fStationaryHalfHeight */
        "movss %xmm1, -0x58(%ebp)\n"
        "ucomiss %xmm0, %xmm7\n" /* line 2002 */
        "ja .Lf65c86_0006656b\n"
        "pxor %xmm7, %xmm7\n"
        "ucomiss -0x198(%ebp), %xmm1\n" /* line 2009 */
        "ja .Lf65c86_00066509\n"
        /* { scope 3: vDelta, fA, fDeltaLen, vNormal */
        /* { scope 4 */
        ".Lf65c86_0006629c:\n"
        "subss -0x194(%ebp), %xmm4\n" /* line 248 */
        "movss %xmm4, -0x48(%ebp)\n" /* vDelta */
        "movaps %xmm5, %xmm3\n" /* line 249 */
        "subss -0x190(%ebp), %xmm3\n"
        "movss %xmm3, -0x44(%ebp)\n"
        "movaps %xmm6, %xmm5\n" /* line 250 */
        "subss -0x18c(%ebp), %xmm5\n"
        "movss %xmm5, -0x40(%ebp)\n"
        "movss -0xec(%ebp), %xmm6\n" /* line 1907 */
        "movss -0x188(%ebp), %xmm0\n" /* radius */
        "addss %xmm6, %xmm0\n"
        "movaps %xmm4, %xmm2\n" /* line 1908 */
        "mulss %xmm4, %xmm2\n"
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "ucomiss %xmm2, %xmm7\n" /* line 1909 */
        "jae .Lf65c86_000663b1\n"
        "movaps %xmm4, %xmm0\n" /* line 114 */
        "mulss -0x154(%ebp), %xmm0\n"
        "mulss -0x150(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "ucomiss %xmm7, %xmm0\n" /* line 1918 */
        "jb .Lf65c86_0006641e\n"
        /* } scope */
        /* } scope */
        ".Lf65c86_00066320:\n"
        "movss -0x4c(%ebp), %xmm1\n" /* line 2022 */
        "movss -0x28(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf65c86_000663e6\n"
        "ucomiss -0x70(%ebp), %xmm1\n" /* line 2024 */
        "jb .Lf65c86_00066366\n"
        "leal -0x30(%ebp), %ecx\n" /* line 2026 | endbottom */
        "leal -0x78(%ebp), %edx\n" /* startbottom */
        "leal -0xc0(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* top */
        ".Lf65c86_0006634c:\n"
        "movl %eax, (%esp)\n" /* line 2034 */
        "movss -0x188(%ebp), %xmm0\n" /* radius */
        "leal -0x178(%ebp), %eax\n" /* tw */
        "calll CM_SightTraceSphereThroughSphere\n"
        "testl %eax, %eax\n"
        "je .Lf65c86_000663dc\n"
        /* } scope */
        ".Lf65c86_00066366:\n"
        "xorl %eax, %eax\n" /* line 2294 */
        /* } scope */
        ".Lf65c86_00066368:\n"
        "addl $0x1cc, %esp\n" /* line 2299 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: box_model, top, bottom, starttop, ... */
        /* { scope 2: radius, fStationaryHalfHeight */
        ".Lf65c86_00066373:\n"
        "movl $3, (%esp)\n" /* line 43 */
        "calll Sys_GetValue\n"
        "movl 0x14(%eax), %eax\n" /* line 47 */
        "movl %eax, -0x19c(%ebp)\n" /* box_model */
        "jmp .Lf65c86_00065cb8\n"
        /* } scope */
        ".Lf65c86_0006638d:\n"
        "leal (%edx, %edx, 2), %edx\n" /* line 2290 */
        "shll $4, %edx\n"
        "addl 0x80(%ecx), %edx\n"
        "leal -0x178(%ebp), %eax\n" /* tw */
        "calll CM_SightTraceThroughBrush\n"
        "testl %eax, %eax\n" /* line 2293 */
        "je .Lf65c86_00065fe4\n"
        "jmp .Lf65c86_00066006\n"
        /* { scope 2: radius, fStationaryHalfHeight */
        /* { scope 3: vDelta, fA, fDeltaLen, vNormal */
        /* { scope 4 */
        ".Lf65c86_000663b1:\n"
        "movss -0x114(%ebp), %xmm0\n" /* line 1914 */
        "subss %xmm6, %xmm0\n"
        "addss -0x184(%ebp), %xmm0\n" /* fStationaryHalfHeight */
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+416, %xmm5\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm0, %xmm5\n"
        "seta %al\n"
        /* } scope */
        /* } scope */
        ".Lf65c86_000663d4:\n"
        "testl %eax, %eax\n" /* line 2018 */
        "jne .Lf65c86_00066320\n"
        ".Lf65c86_000663dc:\n"
        "movl $0xffffffff, %eax\n" /* line 2034 */
        "jmp .Lf65c86_00066006\n"
        ".Lf65c86_000663e6:\n"
        "movss -0x58(%ebp), %xmm1\n" /* line 2030 */
        "ucomiss -0x7c(%ebp), %xmm1\n"
        "jbe .Lf65c86_00066366\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 2032 */
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf65c86_00066366\n"
        "leal -0x84(%ebp), %ecx\n" /* line 2034 | endtop */
        "leal -0x6c(%ebp), %edx\n" /* starttop */
        "leal -0xc0(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* bottom */
        "jmp .Lf65c86_0006634c\n"
        /* { scope 3: vDelta, fA, fDeltaLen, vNormal */
        /* { scope 4 */
        ".Lf65c86_0006641e:\n"
        "movss -0x144(%ebp), %xmm1\n" /* line 1921 */
        "movss %xmm1, -0x180(%ebp)\n" /* fA */
        "movaps %xmm0, %xmm3\n" /* line 1922 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm1, %xmm2\n"
        "subss %xmm2, %xmm3\n"
        "ucomiss %xmm3, %xmm7\n" /* line 1923 */
        "ja .Lf65c86_00066320\n"
        "movss %xmm7, -0x40(%ebp)\n" /* line 1928 */
        "leal -0x24(%ebp), %eax\n" /* line 1929 | vNormal */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* vDelta */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x1b8(%ebp)\n"
        "movss %xmm3, -0x1c8(%ebp)\n"
        "calll Vec3NormalizeTo\n"
        "fstps -0x17c(%ebp)\n" /* fDeltaLen */
        "movss -0x1b8(%ebp), %xmm0\n" /* line 1930 */
        "movaps %xmm0, %xmm2\n"
        "mulss lit4_002ed610, %xmm2\n" /* 0.125f */
        "divss -0x17c(%ebp), %xmm2\n" /* fDeltaLen */
        "movaps %xmm0, %xmm1\n" /* line 1931 */
        "xorps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+432, %xmm1\n"
        "movss -0x1c8(%ebp), %xmm3\n" /* line 81 */
        "sqrtss %xmm3, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "divss -0x180(%ebp), %xmm1\n" /* fA */
        "addss %xmm2, %xmm1\n"
        "ucomiss -0xc0(%ebp), %xmm1\n" /* line 1932 | trace */
        "jae .Lf65c86_00066320\n"
        "movss -0x114(%ebp), %xmm0\n" /* line 1938 */
        "subss -0xec(%ebp), %xmm0\n"
        "addss -0x184(%ebp), %xmm0\n" /* fStationaryHalfHeight */
        "subss %xmm2, %xmm1\n"
        "mulss -0x14c(%ebp), %xmm1\n"
        "addss -0x170(%ebp), %xmm1\n"
        "subss -0x18c(%ebp), %xmm1\n"
        "andps __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+416, %xmm1\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm0, %xmm1\n"
        "seta %al\n"
        "jmp .Lf65c86_000663d4\n"
        /* } scope */
        /* } scope */
        ".Lf65c86_00066509:\n"
        "leal -0x84(%ebp), %ecx\n" /* line 2011 | endtop */
        "leal -0x6c(%ebp), %edx\n" /* starttop */
        "leal -0xc0(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* bottom */
        "movl %eax, (%esp)\n"
        "movss -0x188(%ebp), %xmm0\n" /* radius */
        "leal -0x178(%ebp), %eax\n" /* tw */
        "calll CM_SightTraceSphereThroughSphere\n"
        "testl %eax, %eax\n"
        "je .Lf65c86_000663dc\n"
        "pxor %xmm7, %xmm7\n" /* line 2013 */
        "ucomiss -0x14c(%ebp), %xmm7\n"
        "jae .Lf65c86_00066366\n"
        ".Lf65c86_0006654e:\n"
        "movss -0x170(%ebp), %xmm6\n"
        "movss -0x178(%ebp), %xmm4\n" /* tw */
        "movss -0x174(%ebp), %xmm5\n"
        "jmp .Lf65c86_0006629c\n"
        ".Lf65c86_0006656b:\n"
        "leal -0x30(%ebp), %ecx\n" /* line 2004 | endbottom */
        "leal -0x78(%ebp), %edx\n" /* startbottom */
        "leal -0xc0(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* top */
        "movl %eax, (%esp)\n"
        "movss -0x188(%ebp), %xmm0\n" /* radius */
        "leal -0x178(%ebp), %eax\n" /* tw */
        "calll CM_SightTraceSphereThroughSphere\n"
        "testl %eax, %eax\n"
        "je .Lf65c86_000663dc\n"
        "pxor %xmm7, %xmm7\n" /* line 2006 */
        "movss -0x14c(%ebp), %xmm0\n"
        "ucomiss %xmm7, %xmm0\n"
        "jb .Lf65c86_0006654e\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 2294 */
        "jmp .Lf65c86_00066368\n"
    );
}

/* line 1444 */
__attribute__((naked))
int CM_TransformedBoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask, const vec_t *origin, const vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1444 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* end */
        "movl 0x18(%ebp), %ebx\n" /* maxs */
        "movl 0x24(%ebp), %ecx\n" /* origin */
        "movl $1, %edx\n"
        "movss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "movl $4, %eax\n" /* model */
        /* { scope 1 */
        ".Lf665b4_000665db:\n"
        "movl 0x14(%ebp), %esi\n" /* line 1464 | mins, i */
        "movss -4(%eax, %esi), %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "addss -4(%eax, %ebx), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "subss %xmm1, %xmm0\n" /* line 1465 */
        "movss %xmm0, -0x4c(%eax, %ebp)\n"
        "movss -4(%eax, %ebx), %xmm0\n" /* line 1466 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x40(%eax, %ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 1467 */
        "movl 0xc(%ebp), %esi\n" /* start, i */
        "addss -4(%eax, %esi), %xmm0\n"
        "movss %xmm0, -0x28(%eax, %ebp)\n"
        "addss -4(%eax, %edi), %xmm1\n" /* line 1468 */
        "movss %xmm1, -0x34(%eax, %ebp)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 1462 */
        "jne .Lf665b4_000665db\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 248 | start_l */
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* start_l */
        "movss -0x20(%ebp), %xmm0\n" /* line 249 */
        "subss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 250 */
        "subss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 248 | end_l */
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* end_l */
        "movss -0x2c(%ebp), %xmm0\n" /* line 249 */
        "subss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 250 */
        "subss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "pxor %xmm0, %xmm0\n" /* line 1476 */
        "movl 0x28(%ebp), %eax\n" /* angles */
        "ucomiss (%eax), %xmm0\n"
        "jne .Lf665b4_000666a4\n"
        "jp .Lf665b4_000666a4\n"
        "ucomiss 4(%eax), %xmm0\n"
        "je .Lf665b4_00066935\n"
        ".Lf665b4_000666a4:\n"
        "leal -0x6c(%ebp), %edi\n" /* line 167 | matrix */
        "leal -0x54(%ebp), %eax\n"
        "leal -0x60(%ebp), %edx\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl 0x28(%ebp), %edx\n" /* angles */
        "movl %edx, (%esp)\n"
        "calll AngleVectors\n"
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+448, %xmm0\n" /* line 224 */
        "movss -0x60(%ebp), %xmm1\n"
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n"
        "movss -0x5c(%ebp), %xmm3\n" /* line 225 */
        "xorps %xmm0, %xmm3\n"
        "movss %xmm3, -0x5c(%ebp)\n"
        "movss -0x58(%ebp), %xmm4\n" /* line 226 */
        "xorps %xmm0, %xmm4\n"
        "movss %xmm4, -0x58(%ebp)\n"
        "movss -0x24(%ebp), %xmm2\n" /* line 199 | start_l */
        "movss -0x20(%ebp), %xmm5\n" /* line 200 */
        "movss -0x1c(%ebp), %xmm6\n" /* line 201 */
        "movss -0x68(%ebp), %xmm7\n" /* line 304 */
        "movss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, -0xa4(%ebp)\n"
        "movaps %xmm2, %xmm0\n" /* line 133 */
        "mulss -0x6c(%ebp), %xmm0\n" /* matrix */
        "movaps %xmm5, %xmm1\n"
        "mulss %xmm7, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0xa4(%ebp), %xmm1\n"
        "mulss %xmm6, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* start_l */
        "movaps %xmm2, %xmm0\n" /* line 134 */
        "mulss -0x60(%ebp), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 304 */
        "movss %xmm0, -0xa0(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "mulss -0x54(%ebp), %xmm2\n" /* line 135 */
        "mulss -0xa0(%ebp), %xmm5\n"
        "addss %xmm5, %xmm2\n"
        "mulss %xmm0, %xmm6\n"
        "addss %xmm6, %xmm2\n"
        "movss %xmm2, -0x1c(%ebp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 199 | end_l */
        "movss -0x2c(%ebp), %xmm2\n" /* line 200 */
        "movss -0x28(%ebp), %xmm5\n" /* line 201 */
        "movaps %xmm1, %xmm0\n" /* line 133 */
        "mulss -0x6c(%ebp), %xmm0\n" /* matrix */
        "mulss %xmm2, %xmm7\n"
        "addss %xmm7, %xmm0\n"
        "movss -0xa4(%ebp), %xmm6\n"
        "mulss %xmm5, %xmm6\n"
        "addss %xmm6, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* end_l */
        "movaps %xmm1, %xmm0\n" /* line 134 */
        "mulss -0x60(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "mulss %xmm5, %xmm4\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss -0x54(%ebp), %xmm1\n" /* line 135 */
        "mulss -0xa0(%ebp), %xmm2\n"
        "movss %xmm2, -0xa0(%ebp)\n"
        "addss %xmm2, %xmm1\n"
        "mulss -0x9c(%ebp), %xmm5\n"
        "movss %xmm5, -0x9c(%ebp)\n"
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movl $1, %ebx\n"
        ".Lf665b4_0006681f:\n"
        "movl 8(%ebp), %eax\n" /* line 1490 | results */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0xa8(%ebp)\n" /* oldFraction */
        "movl 0x20(%ebp), %eax\n" /* line 1491 | brushmask */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* model */
        "movl %eax, 8(%esp)\n"
        "leal -0x3c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* symetricSize */
        "movl %eax, (%esp)\n"
        "leal -0x30(%ebp), %ecx\n" /* end_l */
        "leal -0x24(%ebp), %edx\n" /* start_l */
        "movl 8(%ebp), %eax\n" /* results */
        "calll CM_Trace\n"
        "testb %bl, %bl\n" /* line 1494 | maxs */
        "je .Lf665b4_0006692a\n"
        "movss -0xa8(%ebp), %xmm0\n" /* oldFraction */
        "movl 8(%ebp), %edx\n" /* results */
        "ucomiss (%edx), %xmm0\n"
        "jbe .Lf665b4_0006692a\n"
        "xorl %esi, %esi\n" /* i */
        "leal -0x90(%ebp), %eax\n" /* transpose */
        "leal -0x6c(%ebp), %edi\n" /* matrix, end */
        ".Lf665b4_0006687e:\n"
        "leal (%edi, %esi, 4), %ecx\n" /* end */
        "movl %eax, %edx\n"
        "leal 0xc(%eax), %ebx\n" /* maxs */
        /* { scope 2 */
        ".Lf665b4_00066886:\n"
        "movl (%ecx), %eax\n" /* line 154 */
        "movl %eax, (%edx)\n"
        "addl $0xc, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %edx, %ebx\n" /* line 152 */
        "jne .Lf665b4_00066886\n"
        "addl $1, %esi\n" /* line 150 | i */
        "cmpl $3, %esi\n" /* i */
        "je .Lf665b4_000668a0\n"
        "movl %ebx, %eax\n"
        "jmp .Lf665b4_0006687e\n"
        /* } scope */
        ".Lf665b4_000668a0:\n"
        "movl 8(%ebp), %eax\n" /* line 1498 | results, point */
        "addl $4, %eax\n" /* point */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 199 | results */
        "movss 4(%edx), %xmm2\n"
        "movss 4(%eax), %xmm3\n" /* line 200 */
        "movss 8(%eax), %xmm4\n" /* line 201 */
        "movaps %xmm2, %xmm0\n" /* line 133 */
        "mulss -0x90(%ebp), %xmm0\n" /* transpose */
        "movaps %xmm3, %xmm1\n"
        "mulss -0x8c(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0x88(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movaps %xmm2, %xmm0\n" /* line 134 */
        "mulss -0x84(%ebp), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss -0x80(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0x7c(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss -0x78(%ebp), %xmm2\n" /* line 135 */
        "mulss -0x74(%ebp), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss -0x70(%ebp), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss %xmm2, 8(%eax)\n"
        /* } scope */
        /* } scope */
        ".Lf665b4_0006692a:\n"
        "addl $0xac, %esp\n" /* line 1500 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf665b4_00066935:\n"
        "jp .Lf665b4_000666a4\n" /* line 1476 */
        "ucomiss 8(%eax), %xmm0\n"
        "jne .Lf665b4_000666a4\n"
        "jp .Lf665b4_000666a4\n"
        "xorl %ebx, %ebx\n" /* maxs */
        "jmp .Lf665b4_0006681f\n"
    );
}

/* line 1511 */
__attribute__((naked))
int CM_TransformedBoxTraceExternal(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask, const vec_t *origin, const vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1511 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "movl 8(%ebp), %edx\n" /* results */
        "cld\n" /* line 1513 */
        "movl $9, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl $0x3f800000, (%edx)\n" /* line 1514 */
        "movl %edx, 8(%ebp)\n" /* line 1515 | results */
        "popl %edi\n" /* line 1516 */
        "popl %ebp\n"
        "jmp CM_TransformedBoxTrace\n" /* line 1515 */
    );
}

/* line 2310 */
__attribute__((naked))
int CM_TransformedBoxSightTrace(int hitNum, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask, const vec_t *origin, const vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2310 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 0x18(%ebp), %ebx\n" /* maxs */
        "movl 0x24(%ebp), %ecx\n" /* origin */
        "movl $1, %edx\n"
        "movss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "leal -0x48(%ebp), %esi\n" /* symetricSize */
        "movl $4, %eax\n" /* model */
        /* { scope 1 */
        ".Lf66976_0006699d:\n"
        "movl 0x14(%ebp), %edi\n" /* line 2329 | mins */
        "movss -4(%eax, %edi), %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "addss -4(%eax, %ebx), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "subss %xmm1, %xmm0\n" /* line 2330 */
        "movss %xmm0, -4(%eax, %esi)\n"
        "movss -4(%eax, %ebx), %xmm0\n" /* line 2331 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%eax, %esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 2332 */
        "movl 0xc(%ebp), %edi\n" /* start */
        "addss -4(%eax, %edi), %xmm0\n"
        "movss %xmm0, -0x28(%eax, %ebp)\n"
        "movl 0x10(%ebp), %edi\n" /* line 2333 | end */
        "addss -4(%eax, %edi), %xmm1\n"
        "movss %xmm1, -0x34(%eax, %ebp)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 2327 */
        "jne .Lf66976_0006699d\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 248 | start_l */
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* start_l */
        "movss -0x20(%ebp), %xmm0\n" /* line 249 */
        "subss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 250 */
        "subss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 248 | end_l */
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* end_l */
        "movss -0x2c(%ebp), %xmm0\n" /* line 249 */
        "subss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 250 */
        "subss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "pxor %xmm0, %xmm0\n" /* line 2341 */
        "movl 0x28(%ebp), %eax\n" /* angles */
        "ucomiss (%eax), %xmm0\n"
        "jne .Lf66976_00066a78\n"
        "jp .Lf66976_00066a78\n"
        "ucomiss 4(%eax), %xmm0\n"
        "jne .Lf66976_00066a73\n"
        "jp .Lf66976_00066a73\n"
        "ucomiss 8(%eax), %xmm0\n"
        "jp .Lf66976_00066a73\n"
        "je .Lf66976_00066bd8\n"
        ".Lf66976_00066a73:\n"
        "movl 0x28(%ebp), %edi\n" /* angles */
        "jmp .Lf66976_00066a7a\n"
        ".Lf66976_00066a78:\n"
        "movl %eax, %edi\n"
        ".Lf66976_00066a7a:\n"
        "leal -0x6c(%ebp), %ecx\n" /* line 167 | matrix */
        "leal -0x54(%ebp), %eax\n"
        "leal -0x60(%ebp), %edx\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll AngleVectors\n"
        "movss __ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148+464, %xmm0\n" /* line 224 */
        "movss -0x60(%ebp), %xmm1\n"
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n"
        "movss -0x5c(%ebp), %xmm3\n" /* line 225 */
        "xorps %xmm0, %xmm3\n"
        "movss %xmm3, -0x5c(%ebp)\n"
        "movss -0x58(%ebp), %xmm4\n" /* line 226 */
        "xorps %xmm0, %xmm4\n"
        "movss %xmm4, -0x58(%ebp)\n"
        "movss -0x24(%ebp), %xmm2\n" /* line 199 | start_l */
        "movss -0x20(%ebp), %xmm5\n" /* line 200 */
        "movss -0x1c(%ebp), %xmm6\n" /* line 201 */
        "movss -0x68(%ebp), %xmm7\n" /* line 304 */
        "movss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n"
        "movaps %xmm2, %xmm0\n" /* line 133 */
        "mulss -0x6c(%ebp), %xmm0\n" /* matrix */
        "movaps %xmm5, %xmm1\n"
        "mulss %xmm7, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0x84(%ebp), %xmm1\n"
        "mulss %xmm6, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* start_l */
        "movaps %xmm2, %xmm0\n" /* line 134 */
        "mulss -0x60(%ebp), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 304 */
        "movss %xmm0, -0x80(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        "mulss -0x54(%ebp), %xmm2\n" /* line 135 */
        "mulss -0x80(%ebp), %xmm5\n"
        "addss %xmm5, %xmm2\n"
        "mulss %xmm0, %xmm6\n"
        "addss %xmm6, %xmm2\n"
        "movss %xmm2, -0x1c(%ebp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 199 | end_l */
        "movss -0x2c(%ebp), %xmm2\n" /* line 200 */
        "movss -0x28(%ebp), %xmm5\n" /* line 201 */
        "movaps %xmm1, %xmm0\n" /* line 133 */
        "mulss -0x6c(%ebp), %xmm0\n" /* matrix */
        "mulss %xmm2, %xmm7\n"
        "addss %xmm7, %xmm0\n"
        "movss -0x84(%ebp), %xmm6\n"
        "mulss %xmm5, %xmm6\n"
        "addss %xmm6, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* end_l */
        "movaps %xmm1, %xmm0\n" /* line 134 */
        "mulss -0x60(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "mulss %xmm5, %xmm4\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss -0x54(%ebp), %xmm1\n" /* line 135 */
        "mulss -0x80(%ebp), %xmm2\n"
        "movss %xmm2, -0x80(%ebp)\n"
        "addss %xmm2, %xmm1\n"
        "mulss -0x7c(%ebp), %xmm5\n"
        "movss %xmm5, -0x7c(%ebp)\n"
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        ".Lf66976_00066bd8:\n"
        "movl 0x20(%ebp), %eax\n" /* line 2355 | brushmask */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* model */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* end_l */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %edi\n" /* start_l */
        "movl %edi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* hitNum */
        "movl %eax, (%esp)\n"
        "calll CM_BoxSightTrace\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 2356 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

#else
static int CM_TestInLeafBrushNode_r(void) { return 0; }
#endif
