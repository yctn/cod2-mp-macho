/* ASM dump from: xmodel.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/xmodel.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 *   #include "PC/universal/com_math.h"
 */

extern struct XModelDefault g_default; /* 0x0 */

int XModelBad(const XModel *model);
J_COLOR_SPACE XModelPartsFree(XModelParts *model);
XModelParts * XModelPartsFindData(const char *name);
J_COLOR_SPACE XModelPartsSetData(const char *name, XModelParts *modelParts, Alloc_t Alloc);
XModelSurfs * XModelSurfsFindData(const char *name);
J_COLOR_SPACE XModelSurfsSetData(const char *name, XModelSurfs *modelSurfs, Alloc_t Alloc);
XModel * XModelPrecache(const char *name, Alloc_t Alloc, Alloc_t AllocColl);
int XModelBoneNames(XModel *model);
int XModelGetBoneIndex(const XModel *model, unsigned int name);
const char * XModelGetLodName(const XModel *model, int lod);
int XModelGetContents(const XModel *model);
const struct trXSkin_t * XModelGetSkins(const XModel *model);
int XModelGetMemUsage(const XModel *model);
Bool Com_ValidXModelName(const char *name);
J_COLOR_SPACE XModelGetBounds(const XModel *model, vec_t *mins, vec_t *maxs);
J_COLOR_SPACE XModelFree(XModel *model);
int XModelTraceLine(const XModel *model, trace_t *results, const DObjAnimMat *boneMtxList, vec_t *localStart, vec_t *localEnd, int contentmask);

/* line 37 */
__attribute__((naked))
int XModelBad(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 37 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movzbl 0x8d(%eax), %eax\n" /* model */
        "popl %ebp\n" /* line 45 */
        "retl\n"
    );
}

/* line 69 */
__attribute__((naked))
J_COLOR_SPACE XModelPartsFree(XModelParts *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edx\n" /* model */
        /* { scope 1 */
        "movl 4(%edx), %eax\n" /* line 79 */
        "movl (%eax), %edi\n" /* boneNames */
        "movswl (%edx), %esi\n" /* line 80 | size */
        "testl %esi, %esi\n" /* line 81 | size */
        "jg .Lf4619e_000461be\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 83 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4619e_000461be:\n"
        "xorl %ebx, %ebx\n" /* line 81 | i */
        ".Lf4619e_000461c0:\n"
        "movzwl (%edi, %ebx, 2), %eax\n" /* line 82 | boneNames */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "addl $1, %ebx\n" /* line 81 | i */
        "cmpl %ebx, %esi\n" /* i, size */
        "jne .Lf4619e_000461c0\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 83 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 208 */
__attribute__((naked))
XModelParts * XModelPartsFindData(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 208 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 210 | name */
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll Hunk_FindDataForFile\n"
        "leave\n" /* line 211 */
        "retl\n"
    );
}

/* line 214 */
__attribute__((naked))
J_COLOR_SPACE XModelPartsSetData(const char *name, XModelParts *modelParts, Alloc_t Alloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 214 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* line 216 | Alloc */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* modelParts */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll Hunk_SetDataForFile\n"
        "leave\n" /* line 217 */
        "retl\n"
    );
}

/* line 220 */
__attribute__((naked))
XModelSurfs * XModelSurfsFindData(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 222 | name */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Hunk_FindDataForFile\n"
        "leave\n" /* line 223 */
        "retl\n"
    );
}

/* line 226 */
__attribute__((naked))
J_COLOR_SPACE XModelSurfsSetData(const char *name, XModelSurfs *modelSurfs, Alloc_t Alloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 226 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* line 228 | Alloc */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* modelSurfs */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Hunk_SetDataForFile\n"
        "leave\n" /* line 229 */
        "retl\n"
    );
}

/* line 285 */
__attribute__((naked))
XModel * XModelPrecache(const char *name, Alloc_t Alloc, Alloc_t AllocColl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 285 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* name */
        /* { scope 1 */
        "movl %esi, 4(%esp)\n" /* line 289 | name */
        "movl $4, (%esp)\n"
        "calll Hunk_FindDataForFile\n"
        "movl %eax, %ebx\n" /* model */
        "testl %eax, %eax\n" /* line 290 */
        "je .Lf46268_00046292\n"
        /* } scope */
        ".Lf46268_00046289:\n"
        "movl %ebx, %eax\n" /* line 306 | model */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf46268_00046292:\n"
        "movl 0x10(%ebp), %eax\n" /* line 293 | AllocColl */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Alloc */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* name */
        "calll XModelLoad\n"
        "movl %eax, %ebx\n" /* model */
        "testl %eax, %eax\n" /* line 294 */
        "je .Lf46268_000462d8\n"
        "movl 0xc(%ebp), %eax\n" /* line 296 | Alloc */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* model */
        "movl %esi, 4(%esp)\n" /* name */
        "movl $4, (%esp)\n"
        "calll Hunk_SetDataForFile\n"
        "movl %eax, 0x88(%ebx)\n" /* model */
        /* } scope */
        "movl %ebx, %eax\n" /* line 306 | model */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf46268_000462d8:\n"
        "movl %esi, 4(%esp)\n" /* line 303 | name */
        "movl $0x217d9c, (%esp)\n" /* "^1ERROR: Cannot find xmodel '%s'.
" */
        "calll Com_Printf\n"
        "movl $0x90, (%esp)\n" /* line 201 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, %ebx\n"
        "movb $1, 0x8d(%eax)\n" /* line 159 */
        "movl $g_default, 0xffd6a4\n" /* line 123 */
        "movl $0xffd6a4, 0xffd6b0\n" /* line 126 */
        "movl $0, 0xffd6b4\n" /* line 127 */
        "movl $0, 0xffd6b8\n" /* line 128 */
        "movw $1, 0xffd6ac\n" /* line 129 */
        "movw $1, 0xffd6ae\n" /* line 130 */
        "movl $0xffd74c, 0xffd6bc\n" /* line 131 */
        "movb $0, 0xffd74c\n" /* line 132 */
        "movw $0, g_default\n" /* line 134 */
        "movl $0xffd6ac, (%eax)\n" /* line 161 */
        "movl $4, %edx\n"
        ".Lf46268_0004635a:\n"
        "movl $0, 0x14(%eax)\n" /* line 165 */
        "movl $0x2157b8, 8(%eax)\n" /* line 166 */
        "movl $0, 4(%eax)\n" /* line 167 */
        "movw $1, 0xc(%eax)\n" /* line 168 */
        "movl $0xffd74e, 0x10(%eax)\n" /* line 169 */
        "movw $0, 0xffd74e\n" /* line 170 */
        "addl $0x14, %eax\n"
        "subl $1, %edx\n" /* line 163 */
        "jne .Lf46268_0004635a\n"
        "movl $0, 0xffd710\n" /* line 145 */
        "movl $0xffd710, 0x14(%ebx)\n" /* line 173 */
        "movw $1, 0x7c(%ebx)\n" /* line 175 */
        "movw $0, 0x7e(%ebx)\n" /* line 176 */
        "movl $0x217dc0, 0x88(%ebx)\n" /* line 177 */
        "movl $0xc1800000, %eax\n" /* line 183 */
        "movl %eax, 0xffd724\n"
        "movl %eax, 0xffd728\n" /* line 184 */
        "movl %eax, 0xffd72c\n" /* line 185 */
        "movl $0x41800000, %eax\n" /* line 189 */
        "movl %eax, 0xffd730\n"
        "movl %eax, 0xffd734\n" /* line 190 */
        "movl %eax, 0xffd738\n" /* line 191 */
        "movl $0xffd724, 0x60(%ebx)\n" /* line 193 */
        "movl 0xc(%ebp), %eax\n" /* line 252 | Alloc */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll Hunk_SetDataForFile\n"
        "jmp .Lf46268_00046289\n"
    );
}

/* line 329 */
__attribute__((naked))
int XModelBoneNames(XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 329 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl (%eax), %eax\n" /* model */
        "movl 4(%eax), %eax\n" /* model */
        "movl (%eax), %eax\n" /* model */
        "popl %ebp\n" /* line 332 */
        "retl\n"
    );
}

/* line 340 */
__attribute__((naked))
int XModelGetBoneIndex(const XModel *model, unsigned int name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 340 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 348 | model */
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n" /* line 350 */
        "movl (%eax), %ecx\n"
        "movswl (%edx), %eax\n" /* line 355 */
        "movl %eax, %ebx\n" /* localBoneIndex */
        "subl $1, %ebx\n" /* localBoneIndex */
        "js .Lf46414_00046455\n"
        "movl %ebx, %esi\n" /* line 357 | localBoneIndex */
        "movzwl (%ecx, %ebx, 2), %eax\n"
        "cmpl %eax, %edi\n" /* name */
        "je .Lf46414_00046455\n"
        "leal (%ecx, %ebx, 2), %ecx\n" /* line 340 */
        "xorl %edx, %edx\n"
        ".Lf46414_00046440:\n"
        "subl $1, %ebx\n" /* line 355 | localBoneIndex */
        "cmpl %esi, %edx\n"
        "je .Lf46414_00046455\n"
        "movzwl -2(%ecx), %eax\n" /* line 357 */
        "addl $1, %edx\n"
        "subl $2, %ecx\n"
        "cmpl %eax, %edi\n" /* name */
        "jne .Lf46414_00046440\n"
        /* } scope */
        ".Lf46414_00046455:\n"
        "movl %ebx, %eax\n" /* line 362 | localBoneIndex */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 382 */
__attribute__((naked))
const char * XModelGetLodName(const XModel *model, int lod)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 382 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* lod */
        "leal (%eax, %eax, 4), %eax\n" /* lod */
        "shll $2, %eax\n" /* lod */
        "addl 8(%ebp), %eax\n" /* model, lod */
        "movl 8(%eax), %eax\n" /* lod */
        "popl %ebp\n" /* line 386 */
        "retl\n"
    );
}

/* line 394 */
__attribute__((naked))
int XModelGetContents(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 394 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl 0x5c(%eax), %eax\n" /* model */
        "popl %ebp\n" /* line 399 */
        "retl\n"
    );
}

/* line 458 */
__attribute__((naked))
const struct trXSkin_t * XModelGetSkins(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 458 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl 0x80(%eax), %eax\n" /* model */
        "popl %ebp\n" /* line 461 */
        "retl\n"
    );
}

/* line 470 */
__attribute__((naked))
int XModelGetMemUsage(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 470 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl 0x84(%eax), %eax\n" /* model */
        "popl %ebp\n" /* line 473 */
        "retl\n"
    );
}

/* line 595 */
__attribute__((naked))
Bool Com_ValidXModelName(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 595 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        "movl $6, 8(%esp)\n" /* line 597 */
        "movl $0x217dc8, 4(%esp)\n" /* "xmodel" */
        "movl %ebx, (%esp)\n" /* name */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf46498_000464c4\n"
        "cmpb $0x2f, 6(%ebx)\n" /* name */
        "je .Lf46498_000464cc\n"
        ".Lf46498_000464c4:\n"
        "xorl %eax, %eax\n"
        "addl $0x14, %esp\n" /* line 598 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf46498_000464cc:\n"
        "movb $1, %al\n" /* line 597 */
        "addl $0x14, %esp\n" /* line 598 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 370 */
__attribute__((naked))
J_COLOR_SPACE XModelGetBounds(const XModel *model, vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 370 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* model */
        "movl 0xc(%ebp), %edx\n" /* mins */
        "movl 0x10(%ebp), %esi\n" /* maxs */
        "leal 0x64(%ecx), %ebx\n" /* line 372 | from */
        /* { scope 1 */
        "movl 0x64(%ecx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x70(%ecx), %edx\n" /* line 373 | from */
        /* { scope 1 */
        "movl 0x70(%ecx), %eax\n" /* line 199 */
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        /* } scope */
        "popl %ebx\n" /* line 374 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 86 */
__attribute__((naked))
J_COLOR_SPACE XModelFree(XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 86 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* model */
        /* { scope 1 */
        "cmpb $0, 0x8d(%eax)\n" /* line 91 */
        "jne .Lf4650e_00046555\n"
        "movl %eax, %esi\n" /* line 92 */
        "movl $4, -0x20(%ebp)\n"
        ".Lf4650e_0004652c:\n"
        "leal 0x10(%esi), %eax\n" /* line 86 | model */
        "movl %eax, -0x1c(%ebp)\n" /* model */
        "movl 0x10(%esi), %eax\n" /* line 96 */
        "testl %eax, %eax\n"
        "je .Lf4650e_0004654c\n"
        "leal 0xc(%esi), %edi\n" /* line 86 */
        "cmpw $0, 0xc(%esi)\n" /* line 99 */
        "jg .Lf4650e_0004655d\n"
        ".Lf4650e_00046543:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 102 */
        "movl $0, (%eax)\n"
        ".Lf4650e_0004654c:\n"
        "addl $0x14, %esi\n"
        "subl $1, -0x20(%ebp)\n" /* line 94 */
        "jne .Lf4650e_0004652c\n"
        /* } scope */
        ".Lf4650e_00046555:\n"
        "addl $0x2c, %esp\n" /* line 104 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4650e_0004655d:\n"
        "xorl %ebx, %ebx\n" /* line 99 | j */
        ".Lf4650e_0004655f:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 100 */
        "movl (%edx), %eax\n"
        "movzwl (%eax, %ebx, 2), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "addl $1, %ebx\n" /* line 99 | j */
        "movswl (%edi), %eax\n"
        "cmpl %ebx, %eax\n" /* j */
        "jg .Lf4650e_0004655f\n"
        "jmp .Lf4650e_00046543\n"
    );
}

/* line 483 */
__attribute__((naked))
int XModelTraceLine(const XModel *model, trace_t *results, const DObjAnimMat *boneMtxList, vec_t *localStart, vec_t *localEnd, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 483 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        /* { scope 1: xx, xz, yy, yz, ... */
        "movl 8(%ebp), %eax\n" /* line 505 | model */
        "movl %eax, (%esp)\n"
        "calll XModelNumBones\n"
        "movl 8(%ebp), %edx\n" /* line 508 | model */
        "movl 0x58(%edx), %ebx\n" /* csurf */
        "testl %ebx, %ebx\n" /* csurf */
        "jle .Lf4657c_00046ca0\n"
        "movl $0, -0xa8(%ebp)\n" /* i */
        "movl $0xffffffff, -0xac(%ebp)\n" /* partIndex */
        "xorl %edi, %edi\n"
        "movl 0xc(%ebp), %ecx\n" /* results */
        "addl $4, %ecx\n"
        "movl %ecx, -0xc8(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* model */
        "jmp .Lf4657c_000465e1\n"
        ".Lf4657c_000465c8:\n"
        "addl $1, -0xa8(%ebp)\n" /* i */
        "addl $0x2c, %edi\n"
        "movl -0xa8(%ebp), %edx\n" /* i */
        "cmpl %edx, 0x58(%eax)\n"
        "jle .Lf4657c_00046b02\n"
        ".Lf4657c_000465e1:\n"
        "movl %edi, %ebx\n" /* line 510 | csurf */
        "addl 0x54(%eax), %ebx\n" /* csurf */
        "movl 0x1c(%ebp), %edx\n" /* line 512 | contentmask */
        "testl %edx, 0x24(%ebx)\n" /* csurf */
        "je .Lf4657c_000465c8\n"
        "movl 0x20(%ebx), %ecx\n" /* line 515 | csurf */
        "movl %ecx, -0xb0(%ebp)\n" /* boneIdx */
        "movl %ecx, %eax\n" /* line 519 */
        "shll $5, %eax\n"
        "addl 0x10(%ebp), %eax\n" /* boneMtxList */
        "leal 0x10(%eax), %edx\n" /* line 522 | b */
        /* { scope 2 */
        "movss 0x10(%eax), %xmm2\n" /* line 248 */
        "movl 0x14(%ebp), %ecx\n" /* localStart */
        "movss (%ecx), %xmm7\n"
        "subss %xmm2, %xmm7\n"
        "movss 4(%edx), %xmm1\n" /* line 249 */
        "movss 4(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 250 */
        "movss 8(%ecx), %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "movss %xmm3, -0x78(%ebp)\n"
        /* } scope */
        "movl 0x18(%ebp), %edx\n" /* line 248 | localEnd */
        "movss (%edx), %xmm3\n"
        "subss %xmm2, %xmm3\n"
        "movss %xmm3, -0x68(%ebp)\n"
        "movss 4(%edx), %xmm4\n" /* line 249 */
        "subss %xmm1, %xmm4\n"
        "movss %xmm4, -0x6c(%ebp)\n"
        "movss 8(%edx), %xmm1\n" /* line 250 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x70(%ebp)\n"
        /* { scope 2 */
        "movss 0x1c(%eax), %xmm1\n" /* line 306 | scale */
        /* { scope 3 */
        "movaps %xmm1, %xmm3\n" /* line 272 */
        "mulss (%eax), %xmm3\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss 4(%eax), %xmm6\n"
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm3, %xmm2\n" /* line 308 */
        "mulss (%eax), %xmm2\n"
        "movss %xmm2, -0xa4(%ebp)\n" /* xx */
        "movss 4(%eax), %xmm4\n" /* line 309 */
        "movaps %xmm3, %xmm5\n"
        "mulss %xmm4, %xmm5\n"
        "movss 8(%eax), %xmm2\n" /* line 310 */
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n" /* xz */
        "movss 0xc(%eax), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm6, %xmm4\n" /* line 313 */
        "movss %xmm4, -0x9c(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm4\n" /* line 314 */
        "mulss %xmm2, %xmm4\n"
        "movss %xmm4, -0x98(%ebp)\n" /* yz */
        "mulss %xmm0, %xmm6\n" /* line 315 */
        "mulss %xmm1, %xmm2\n" /* line 317 */
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss -0x9c(%ebp), %xmm0\n" /* line 320 | yy */
        "addss %xmm2, %xmm0\n"
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "subss %xmm0, %xmm4\n"
        "movaps %xmm5, %xmm0\n" /* line 321 */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss -0xa0(%ebp), %xmm0\n" /* line 322 | xz */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "subss %xmm1, %xmm5\n" /* line 324 */
        "addss -0xa4(%ebp), %xmm2\n" /* line 325 | xx */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 326 | yz */
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "addss -0xa0(%ebp), %xmm6\n" /* line 328 | xz */
        "movss -0x98(%ebp), %xmm1\n" /* line 329 | yz */
        "subss %xmm3, %xmm1\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "movss -0xa4(%ebp), %xmm3\n" /* line 330 | xx */
        "addss -0x9c(%ebp), %xmm3\n" /* yy */
        "movss %xmm3, -0xa4(%ebp)\n" /* xx */
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "subss -0xa4(%ebp), %xmm3\n" /* xx */
        /* } scope */
        "movaps %xmm7, %xmm0\n" /* line 435 */
        "mulss %xmm4, %xmm0\n"
        "movss -0x74(%ebp), %xmm1\n"
        "mulss -0x4c(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss -0x50(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* boneExtents */
        "movaps %xmm7, %xmm0\n" /* line 436 */
        "mulss %xmm5, %xmm0\n"
        "movss -0x74(%ebp), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss -0x54(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "mulss %xmm6, %xmm7\n" /* line 437 */
        "movss -0x74(%ebp), %xmm0\n"
        "mulss -0x58(%ebp), %xmm0\n"
        "addss %xmm0, %xmm7\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm1, %xmm7\n"
        "movss %xmm7, -0x34(%ebp)\n"
        "mulss -0x68(%ebp), %xmm4\n" /* line 435 */
        "movss -0x6c(%ebp), %xmm0\n"
        "mulss -0x4c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss -0x70(%ebp), %xmm1\n"
        "mulss -0x50(%ebp), %xmm1\n"
        "addss %xmm1, %xmm4\n"
        "movss %xmm4, -0x30(%ebp)\n"
        "mulss -0x68(%ebp), %xmm5\n" /* line 436 */
        "mulss -0x6c(%ebp), %xmm2\n"
        "addss %xmm2, %xmm5\n"
        "movss -0x70(%ebp), %xmm2\n"
        "mulss -0x54(%ebp), %xmm2\n"
        "addss %xmm2, %xmm5\n"
        "movss %xmm5, -0x2c(%ebp)\n"
        "mulss -0x68(%ebp), %xmm6\n" /* line 437 */
        "movss -0x6c(%ebp), %xmm4\n"
        "mulss -0x58(%ebp), %xmm4\n"
        "movaps %xmm6, %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "mulss -0x70(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 528 | boneExtents */
        "movl %eax, (%esp)\n"
        "calll CM_CalcTraceEntents\n"
        "movl 0xc(%ebp), %edx\n" /* line 531 | results */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal 0x14(%ebx), %eax\n" /* csurf */
        "movl %eax, 8(%esp)\n"
        "leal 8(%ebx), %eax\n" /* csurf */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %ecx\n" /* boneExtents */
        "movl %ecx, (%esp)\n"
        "calll CM_TraceBox\n"
        "testl %eax, %eax\n"
        "jne .Lf4657c_00046ae6\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 248 */
        "movss %xmm0, -0xb8(%ebp)\n"
        "subss -0x3c(%ebp), %xmm0\n" /* boneExtents */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 249 */
        "movss %xmm1, -0xb4(%ebp)\n"
        "subss -0x38(%ebp), %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n"
        "movss -0x28(%ebp), %xmm7\n" /* line 250 */
        "movaps %xmm7, %xmm2\n"
        "subss -0x34(%ebp), %xmm2\n"
        "movss %xmm2, -0x64(%ebp)\n"
        "movl 4(%ebx), %ecx\n" /* line 537 | csurf */
        "testl %ecx, %ecx\n"
        "jle .Lf4657c_00046ae6\n"
        "xorl %esi, %esi\n" /* j */
        "movl $0, -0xcc(%ebp)\n"
        "pxor %xmm6, %xmm6\n"
        "movss -0x3c(%ebp), %xmm3\n" /* boneExtents */
        "movss %xmm3, -0xbc(%ebp)\n"
        "movss -0x38(%ebp), %xmm4\n"
        "movss %xmm4, -0xc0(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "jmp .Lf4657c_0004692d\n"
        ".Lf4657c_0004691a:\n"
        "addl $1, %esi\n" /* j */
        "addl $0x30, -0xcc(%ebp)\n"
        "cmpl %esi, 4(%ebx)\n" /* j, csurf */
        "jle .Lf4657c_00046ae6\n"
        ".Lf4657c_0004692d:\n"
        "movl -0xcc(%ebp), %edx\n" /* line 539 */
        "addl (%ebx), %edx\n" /* csurf */
        "movss 4(%edx), %xmm2\n" /* line 304 */
        "movss 8(%edx), %xmm3\n"
        "movss 0xc(%edx), %xmm4\n" /* line 541 */
        "movss -0xb8(%ebp), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss -0xb4(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "ucomiss %xmm6, %xmm1\n" /* line 542 */
        "jae .Lf4657c_0004691a\n"
        "movss -0xbc(%ebp), %xmm0\n" /* line 545 */
        "mulss (%edx), %xmm0\n"
        "mulss -0xc0(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss -0xc4(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "ucomiss %xmm0, %xmm6\n" /* line 546 */
        "jae .Lf4657c_0004691a\n"
        "movaps %xmm0, %xmm2\n" /* line 549 */
        "subss %xmm1, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "movaps %xmm0, %xmm2\n"
        "subss 0x2ed610, %xmm2\n" /* 0.125f */
        "divss %xmm1, %xmm2\n"
        "movaps %xmm6, %xmm3\n" /* line 45 */
        "maxss %xmm2, %xmm3\n"
        "movaps %xmm3, %xmm2\n"
        "movl 0xc(%ebp), %eax\n" /* line 552 | results */
        "ucomiss (%eax), %xmm3\n"
        "jae .Lf4657c_0004691a\n"
        "divss %xmm1, %xmm0\n" /* line 556 */
        "movss -0x5c(%ebp), %xmm5\n" /* line 288 */
        "mulss %xmm0, %xmm5\n"
        "addss -0xbc(%ebp), %xmm5\n"
        "movss -0x60(%ebp), %xmm3\n" /* line 289 */
        "mulss %xmm0, %xmm3\n"
        "addss -0xc0(%ebp), %xmm3\n"
        "movss -0x64(%ebp), %xmm4\n" /* line 290 */
        "mulss %xmm0, %xmm4\n"
        "addss -0xc4(%ebp), %xmm4\n"
        "leal 0x10(%edx), %eax\n"
        "movaps %xmm5, %xmm1\n" /* line 559 */
        "mulss 0x10(%edx), %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss 0x1c(%edx), %xmm1\n"
        "movss 0x2ed670, %xmm0\n" /* line 560 | -0.0010000000474974513f */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf4657c_0004691a\n"
        "ucomiss 0x2ed674, %xmm1\n" /* 1.0010000467300415f */
        "ja .Lf4657c_0004691a\n"
        "leal 0x20(%edx), %eax\n"
        "movaps %xmm5, %xmm0\n" /* line 563 */
        "mulss 0x20(%edx), %xmm0\n"
        "mulss 4(%eax), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "mulss 8(%eax), %xmm4\n"
        "addss %xmm4, %xmm0\n"
        "subss 0x2c(%edx), %xmm0\n"
        "movss 0x2ed670, %xmm3\n" /* line 564 | -0.0010000000474974513f */
        "ucomiss %xmm0, %xmm3\n"
        "ja .Lf4657c_0004691a\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss 0x2ed674, %xmm1\n" /* 1.0010000467300415f */
        "ja .Lf4657c_0004691a\n"
        "movl 0xc(%ebp), %eax\n" /* line 570 | results */
        "movb $0, 0x23(%eax)\n"
        "movb $0, 0x22(%eax)\n" /* line 571 */
        "movss %xmm2, (%eax)\n" /* line 572 */
        "movl 0x28(%ebx), %ecx\n" /* line 574 | csurf */
        "movl %ecx, 0x10(%eax)\n"
        "movl 0x24(%ebx), %ecx\n" /* line 575 | csurf */
        "movl %ecx, 0x14(%eax)\n"
        "movss (%edx), %xmm0\n" /* line 199 */
        "movss %xmm0, 4(%eax)\n"
        "movss 4(%edx), %xmm0\n" /* line 200 */
        "movl -0xc8(%ebp), %eax\n"
        "movss %xmm0, 4(%eax)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl -0xc8(%ebp), %edx\n"
        "movl %eax, 8(%edx)\n"
        "movl -0xb0(%ebp), %ecx\n" /* boneIdx */
        "movl %ecx, -0xac(%ebp)\n" /* partIndex */
        "jmp .Lf4657c_0004691a\n"
        ".Lf4657c_00046ae6:\n"
        "movl 8(%ebp), %eax\n" /* model */
        "addl $1, -0xa8(%ebp)\n" /* line 508 | i */
        "addl $0x2c, %edi\n"
        "movl -0xa8(%ebp), %edx\n" /* i */
        "cmpl %edx, 0x58(%eax)\n"
        "jg .Lf4657c_000465e1\n"
        ".Lf4657c_00046b02:\n"
        "movl -0xac(%ebp), %edx\n" /* line 581 | partIndex */
        "testl %edx, %edx\n"
        "js .Lf4657c_00046ca0\n"
        "movl -0xac(%ebp), %eax\n" /* line 584 | partIndex */
        "shll $5, %eax\n"
        "addl 0x10(%ebp), %eax\n" /* boneMtxList */
        /* { scope 2 */
        "movss 0x1c(%eax), %xmm4\n" /* line 306 | scale */
        /* { scope 3 */
        "movaps %xmm4, %xmm5\n" /* line 272 */
        "mulss (%eax), %xmm5\n"
        "movaps %xmm4, %xmm7\n" /* line 273 */
        "mulss 4(%eax), %xmm7\n"
        "mulss 8(%eax), %xmm4\n" /* line 274 */
        /* } scope */
        "movaps %xmm5, %xmm0\n" /* line 308 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n" /* xx */
        "movss 4(%eax), %xmm2\n" /* line 309 */
        "movaps %xmm5, %xmm3\n"
        "mulss %xmm2, %xmm3\n"
        "movss 8(%eax), %xmm1\n" /* line 310 */
        "movaps %xmm5, %xmm6\n"
        "mulss %xmm1, %xmm6\n"
        "movss 0xc(%eax), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm5\n"
        "mulss %xmm7, %xmm2\n" /* line 313 */
        "movss %xmm2, -0x90(%ebp)\n" /* yy */
        "movaps %xmm7, %xmm2\n" /* line 314 */
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x8c(%ebp)\n" /* yz */
        "mulss %xmm0, %xmm7\n" /* line 315 */
        "movss %xmm7, -0x88(%ebp)\n" /* yw */
        "movaps %xmm4, %xmm7\n" /* line 317 */
        "mulss %xmm1, %xmm7\n"
        "mulss %xmm0, %xmm4\n" /* line 318 */
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 586 | results */
        "addl $4, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* line 422 | results */
        "movss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n"
        "movss 4(%eax), %xmm1\n"
        "movss %xmm1, -0x80(%ebp)\n"
        "movss 8(%eax), %xmm2\n"
        "movss %xmm2, -0x7c(%ebp)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 199 | yy */
        "addss %xmm7, %xmm0\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss -0x84(%ebp), %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "mulss -0x80(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x88(%ebp), %xmm0\n" /* yw */
        "addss %xmm6, %xmm0\n"
        "mulss -0x7c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%edx)\n"
        "addss %xmm4, %xmm3\n" /* line 200 */
        "mulss -0x84(%ebp), %xmm3\n"
        "addss -0x94(%ebp), %xmm7\n" /* xx */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm7, %xmm0\n"
        "mulss -0x80(%ebp), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss -0x8c(%ebp), %xmm0\n" /* yz */
        "subss %xmm5, %xmm0\n"
        "mulss -0x7c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, 4(%eax)\n"
        "subss -0x88(%ebp), %xmm6\n" /* line 201 | yw */
        "mulss -0x84(%ebp), %xmm6\n"
        "addss -0x8c(%ebp), %xmm5\n" /* yz */
        "mulss -0x80(%ebp), %xmm5\n"
        "addss %xmm5, %xmm6\n"
        "movss -0x94(%ebp), %xmm3\n" /* xx */
        "addss -0x90(%ebp), %xmm3\n" /* yy */
        "subss %xmm3, %xmm2\n"
        "mulss -0x7c(%ebp), %xmm2\n"
        "addss %xmm2, %xmm6\n"
        "movss %xmm6, 8(%eax)\n"
        /* } scope */
        "movl -0xac(%ebp), %eax\n" /* line 592 | partIndex */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xx, xz, yy, yz, ... */
        ".Lf4657c_00046ca0:\n"
        "movl $0xffffffff, -0xac(%ebp)\n" /* line 590 | partIndex */
        /* } scope */
        "movl -0xac(%ebp), %eax\n" /* line 592 | partIndex */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

