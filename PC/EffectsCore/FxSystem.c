/* ASM dump from: FxSystem.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxSystem.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/EffectsCore/FxArchive.h"
 */

void FxHelper_FxHelper(const FxHelper * _this);
void FxHelper_Init(const FxHelper * _this);
void FxHelper_AdjustTime(const FxHelper * _this, int intime);
void FxHelper_WarpTime(const FxHelper * _this, int intime);
void FxHelper_Trace(const FxHelper * _this, trace_t *tr, vec_t *start, const vec_t *min, const vec_t *max, vec_t *end, int skipEntNum, int flags);
void FxHelper_AddFxToScene(const FxHelper * _this, GfxEntity *ent, const struct XModel *model);
void FxHelper_SetIgnorePrecacheErrors(const FxHelper * _this, int ignore);
const char * FxHelper_GetMaterialName(const FxHelper * _this, MaterialHandle handle);
int FxHelper_GetMaterialSubimageCount(const FxHelper * _this, MaterialHandle handle);
Bool FxHelper_IsMaterialRefractive(const FxHelper * _this, MaterialHandle handle);
void FxHelper_AddLightToScene(const FxHelper * _this, vec_t *org, float radius, float red, float green, float blue);
void FxHelper_CameraShake(const FxHelper * _this, vec_t *origin, float intensity, int radius, int time_);
int FxHelper_GetSeed(const FxHelper * _this);
Bool FxHelper_CullSphere(const FxHelper * _this, const vec_t *worldPos, float radius, int planeCount);
Bool FxHelper_CullSpherePreviousFrame(const FxHelper * _this, const vec_t *worldPos, float radius);
Bool FxHelper_CullCylinder(const FxHelper * _this, const vec_t *worldPos0, const vec_t *worldPos1, float radius0, float radius1, int planeCount);
void FxHelper_CalcFrustumPlanes(const FxHelper * _this, refdef_t *refdef, float zfar);
void FxHelper_AdjustCamera(const FxHelper * _this, refdef_t *refdef, float zfar);
void FxHelper_Archive(const FxHelper * _this, FxArchive *arch);

/* line 28 */
__attribute__((naked))
void FxHelper_FxHelper(const FxHelper * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 28 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0, 4(%eax)\n" /* line 32 */
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "popl %ebp\n" /* line 34 */
        "retl\n"
    );
}

/* line 37 */
__attribute__((naked))
void FxHelper_Init(const FxHelper * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 37 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0, (%eax)\n" /* line 39 */
        "movl $0, 4(%eax)\n" /* line 40 */
        "movl $0, 8(%eax)\n" /* line 41 */
        "movl $0, 0xc(%eax)\n" /* line 42 */
        "movl $0, 0x10(%eax)\n" /* line 43 */
        "movl $0, 0xf4(%eax)\n" /* line 45 */
        "popl %ebp\n" /* line 47 */
        "retl\n"
    );
}

/* line 53 */
__attribute__((naked))
void FxHelper_AdjustTime(const FxHelper * _this, int intime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 53 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* intime */
        "movl 0x195eda0, %eax\n" /* line 56 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfab568_000ab5b4\n"
        "movl $0, 0xc(%ecx)\n" /* line 58 */
        ".Lfab568_000ab589:\n"
        "movl %edx, (%ecx)\n" /* line 77 */
        "movl %edx, 0xf4(%ecx)\n" /* line 80 */
        "leal 0x84(%ecx), %edx\n" /* line 83 */
        "leal 0x14(%ecx), %eax\n"
        "movl $0x70, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "addl $0x14, %esp\n" /* line 84 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfab568_000ab5b4:\n"
        "movl (%ecx), %eax\n" /* line 63 */
        "testl %eax, %eax\n"
        "jne .Lfab568_000ab5cf\n"
        ".Lfab568_000ab5ba:\n"
        "movl $0, 0xc(%ecx)\n" /* line 69 */
        ".Lfab568_000ab5c1:\n"
        "movl 4(%ecx), %eax\n" /* line 74 */
        "movl %eax, 8(%ecx)\n"
        "addl 0xc(%ecx), %eax\n" /* line 75 */
        "movl %eax, 4(%ecx)\n"
        "jmp .Lfab568_000ab589\n"
        ".Lfab568_000ab5cf:\n"
        "movl %edx, %ebx\n" /* line 67 */
        "subl %eax, %ebx\n"
        "movl %ebx, 0xc(%ecx)\n"
        "testl %ebx, %ebx\n" /* line 68 */
        "js .Lfab568_000ab5ba\n"
        "cmpl $0xc8, %ebx\n" /* line 70 */
        "jle .Lfab568_000ab5c1\n"
        "movl $0xc8, 0xc(%ecx)\n" /* line 71 */
        "jmp .Lfab568_000ab5c1\n"
    );
}

/* line 100 */
__attribute__((naked))
void FxHelper_WarpTime(const FxHelper * _this, int intime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 100 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* intime */
        /* { scope 1 */
        "movl 0x195eda0, %eax\n" /* line 108 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfab5ec_000ab60e\n"
        "movl (%ebx), %eax\n" /* line 115 | this */
        "testl %eax, %eax\n"
        "jne .Lfab5ec_000ab625\n"
        ".Lfab5ec_000ab60e:\n"
        "movl $0, 0xc(%ebx)\n" /* line 116 | this */
        ".Lfab5ec_000ab615:\n"
        "movl %edi, (%ebx)\n" /* line 158 | intime, this */
        "movl %edi, 0xf4(%ebx)\n" /* line 160 | intime, this */
        /* } scope */
        "addl $0xc, %esp\n" /* line 161 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfab5ec_000ab625:\n"
        "movl 4(%ebx), %eax\n" /* line 119 | this */
        "movl %eax, 8(%ebx)\n" /* this */
        "movl %edi, %esi\n" /* line 122 | intime, frameTime */
        "subl %eax, %esi\n" /* frameTime */
        "js .Lfab5ec_000ab69d\n"
        "movl $0, 0xc(%ebx)\n" /* line 131 | this */
        "cmpl $0xc8, %esi\n" /* line 134 | frameTime */
        "jg .Lfab5ec_000ab66b\n"
        ".Lfab5ec_000ab640:\n"
        "movl %esi, 0xc(%ebx)\n" /* line 147 | frameTime, this */
        "calll FX_AddScheduledEffects\n" /* line 149 */
        "calll FX_UpdateAllNonBolt\n" /* line 150 */
        "calll FX_UpdateAllBolt\n" /* line 151 */
        "movl 4(%ebx), %eax\n" /* line 153 | this */
        "addl 0xc(%ebx), %eax\n" /* this */
        "movl %eax, 4(%ebx)\n" /* this */
        "movl %edi, (%ebx)\n" /* line 158 | intime, this */
        "movl %edi, 0xf4(%ebx)\n" /* line 160 | intime, this */
        /* } scope */
        "addl $0xc, %esp\n" /* line 161 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfab5ec_000ab66b:\n"
        "movl $0xc8, 0xc(%ebx)\n" /* line 137 | this */
        "calll FX_AddScheduledEffects\n" /* line 139 */
        "calll FX_UpdateAllNonBolt\n" /* line 140 */
        "calll FX_UpdateAllBolt\n" /* line 141 */
        "movl 4(%ebx), %eax\n" /* line 143 | this */
        "movl %eax, 8(%ebx)\n" /* this */
        "addl 0xc(%ebx), %eax\n" /* line 144 | this */
        "movl %eax, 4(%ebx)\n" /* this */
        "subl $0xc8, %esi\n" /* line 145 | frameTime */
        "cmpl $0xc8, %esi\n" /* line 134 | frameTime */
        "jg .Lfab5ec_000ab66b\n"
        "jmp .Lfab5ec_000ab640\n"
        ".Lfab5ec_000ab69d:\n"
        "movl %edi, 4(%ebx)\n" /* line 127 | intime, this */
        "jmp .Lfab5ec_000ab615\n"
    );
}

/* line 307 */
__attribute__((naked))
void FxHelper_Trace(const FxHelper * _this, trace_t *tr, vec_t *start, const vec_t *min, const vec_t *max, vec_t *end, int skipEntNum, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 307 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* tr */
        "movl 0x24(%ebp), %eax\n" /* line 313 | flags */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* max */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* min */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* tr */
        "calll CM_BoxTrace\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 314 | 1.0f */
        "ucomiss (%ebx), %xmm0\n" /* tr */
        "sete %al\n"
        "setnp %dl\n"
        "andb %dl, %al\n"
        "movzbw %al, %ax\n"
        "addw $0x3fe, %ax\n"
        "movw %ax, 0x1c(%ebx)\n" /* tr */
        "addl $0x24, %esp\n" /* line 317 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 320 */
__attribute__((naked))
void FxHelper_AddFxToScene(const FxHelper * _this, GfxEntity *ent, const struct XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 320 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, 8(%esp)\n" /* line 325 */
        "movl 0x10(%ebp), %eax\n" /* model */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll R_AddRefEntityToScene\n"
        "leave\n" /* line 326 */
        "retl\n"
    );
}

/* line 331 */
__attribute__((naked))
void FxHelper_SetIgnorePrecacheErrors(const FxHelper * _this, int ignore)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 331 */
        "movl %esp, %ebp\n"
        "movzbl 0xc(%ebp), %eax\n" /* line 334 | ignore */
        "movl %eax, 8(%ebp)\n" /* this */
        "movl 0x195eca8, %eax\n"
        "movl 0x28(%eax), %ecx\n"
        "popl %ebp\n" /* line 335 */
        "jmpl *%ecx\n" /* line 334 */
    );
}

/* line 338 */
__attribute__((naked))
const char * FxHelper_GetMaterialName(const FxHelper * _this, MaterialHandle handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 338 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* line 341 | handle */
        "movl %eax, 8(%ebp)\n" /* this */
        "movl 0x195eca8, %eax\n"
        "movl 0x34(%eax), %ecx\n"
        "popl %ebp\n" /* line 342 */
        "jmpl *%ecx\n" /* line 341 */
    );
}

/* line 361 */
__attribute__((naked))
int FxHelper_GetMaterialSubimageCount(const FxHelper * _this, MaterialHandle handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 361 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* line 364 | handle */
        "movl %eax, 8(%ebp)\n" /* this */
        "movl 0x195eca8, %eax\n"
        "movl 0x38(%eax), %ecx\n"
        "popl %ebp\n" /* line 365 */
        "jmpl *%ecx\n" /* line 364 */
    );
}

/* line 368 */
__attribute__((naked))
Bool FxHelper_IsMaterialRefractive(const FxHelper * _this, MaterialHandle handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 368 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 371 | handle */
        "movl %eax, (%esp)\n"
        "movl 0x195eca8, %eax\n"
        "calll *0x3c(%eax)\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 372 */
        "retl\n"
    );
}

/* line 375 */
__attribute__((naked))
void FxHelper_AddLightToScene(const FxHelper * _this, vec_t *org, float radius, float red, float green, float blue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 375 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %esi\n" /* org */
        "movl 0x10(%ebp), %ebx\n" /* radius */
        "movl 0x14(%ebp), %ecx\n" /* red */
        "movl 0x18(%ebp), %edx\n" /* green */
        "movl 0x1c(%ebp), %eax\n" /* line 379 | blue */
        "movl %eax, 0x18(%ebp)\n" /* green */
        "movl %edx, 0x14(%ebp)\n" /* red */
        "movl %ecx, 0x10(%ebp)\n" /* radius */
        "movl %ebx, 0xc(%ebp)\n" /* radius, org */
        "movl %esi, 8(%ebp)\n" /* org, this */
        "movl 0x195eca8, %eax\n"
        "movl 0x54(%eax), %ecx\n"
        "popl %ebx\n" /* line 380 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 379 */
    );
}

/* line 390 */
__attribute__((naked))
void FxHelper_CameraShake(const FxHelper * _this, vec_t *origin, float intensity, int radius, int time_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 390 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 393 */
        "retl\n"
    );
}

/* line 398 */
__attribute__((naked))
int FxHelper_GetSeed(const FxHelper * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 398 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        /* { scope 1 */
        "movl 0xf4(%edx), %eax\n" /* line 401 */
        "imull $0x369d035, %eax, %ecx\n" /* line 402 */
        "movl %ecx, 0xf4(%edx)\n"
        /* } scope */
        "popl %ebp\n" /* line 404 */
        "retl\n"
    );
}

/* line 228 */
__attribute__((naked))
Bool FxHelper_CullSphere(const FxHelper * _this, const vec_t *worldPos, float radius, int planeCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 228 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* worldPos */
        "movl 0x14(%ebp), %edi\n" /* planeCount */
        /* { scope 1 */
        "testl %edi, %edi\n" /* line 239 | planeCount */
        "jle .Lfab7d4_000ab887\n"
        "movl 0x195ed88, %eax\n" /* line 243 */
        "movl (%eax), %esi\n"
        "leal 0x20(%esi), %eax\n"
        /* { scope 2 */
        "movss (%edx), %xmm5\n" /* line 304 */
        "movss 4(%edx), %xmm4\n"
        "movss 8(%edx), %xmm3\n"
        /* } scope */
        "movss 0x10(%ebp), %xmm0\n" /* line 244 | radius */
        "movaps %xmm0, %xmm2\n"
        "xorps 0x2f1c20, %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 0x20(%esi), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "subss 0x2c(%esi), %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lfab7d4_000ab87d\n"
        "movl %esi, %ebx\n"
        "xorl %ecx, %ecx\n"
        ".Lfab7d4_000ab83d:\n"
        "addl $1, %ecx\n" /* line 239 */
        "cmpl %ecx, %edi\n" /* planeCount */
        "je .Lfab7d4_000ab887\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "leal 0x10(%eax, %esi), %eax\n"
        "leal 0x10(%eax), %edx\n"
        "movaps %xmm5, %xmm0\n" /* line 243 */
        "mulss 0x10(%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "subss 0x3c(%ebx), %xmm0\n"
        "addl $0x10, %ebx\n"
        "ucomiss %xmm0, %xmm2\n" /* line 244 */
        "jbe .Lfab7d4_000ab83d\n"
        ".Lfab7d4_000ab87d:\n"
        "movl $1, %eax\n" /* line 239 */
        /* } scope */
        "popl %ebx\n" /* line 249 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfab7d4_000ab887:\n"
        "xorl %eax, %eax\n" /* line 239 */
        /* } scope */
        "popl %ebx\n" /* line 249 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 253 */
__attribute__((naked))
Bool FxHelper_CullSpherePreviousFrame(const FxHelper * _this, const vec_t *worldPos, float radius)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 253 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* worldPos */
        /* { scope 1 */
        "movl 0x195ed88, %eax\n" /* line 263 */
        "movl (%eax), %esi\n"
        "movl 0xf0(%esi), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lfab88e_000ab953\n"
        "leal 0x90(%esi), %eax\n"
        /* { scope 2 */
        "movss (%edx), %xmm5\n" /* line 304 */
        "movss 4(%edx), %xmm4\n"
        "movss 8(%edx), %xmm3\n"
        /* } scope */
        "movss 0x10(%ebp), %xmm0\n" /* line 268 | radius */
        "movaps %xmm0, %xmm2\n"
        "xorps 0x2f1c30, %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 0x90(%esi), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "subss 0x9c(%esi), %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lfab88e_000ab949\n"
        "movl %esi, %ebx\n"
        "xorl %ecx, %ecx\n"
        ".Lfab88e_000ab903:\n"
        "addl $1, %ecx\n" /* line 263 */
        "cmpl %edi, %ecx\n"
        "je .Lfab88e_000ab953\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "leal 0x80(%eax, %esi), %eax\n"
        "leal 0x10(%eax), %edx\n"
        "movaps %xmm5, %xmm0\n" /* line 267 */
        "mulss 0x10(%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "subss 0xac(%ebx), %xmm0\n"
        "addl $0x10, %ebx\n"
        "ucomiss %xmm0, %xmm2\n" /* line 268 */
        "jbe .Lfab88e_000ab903\n"
        ".Lfab88e_000ab949:\n"
        "movl $1, %eax\n" /* line 263 */
        /* } scope */
        "popl %ebx\n" /* line 273 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfab88e_000ab953:\n"
        "xorl %eax, %eax\n" /* line 263 */
        /* } scope */
        "popl %ebx\n" /* line 273 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 276 */
__attribute__((naked))
Bool FxHelper_CullCylinder(const FxHelper * _this, const vec_t *worldPos0, const vec_t *worldPos1, float radius0, float radius1, int planeCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 276 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* worldPos0 */
        "movl 0x10(%ebp), %ebx\n" /* worldPos1 */
        "movl 0x1c(%ebp), %esi\n" /* planeCount */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 288 | planeCount */
        "jle .Lfab95a_000aba18\n"
        "movss 0x2f1c40, %xmm1\n"
        "movss 0x14(%ebp), %xmm0\n" /* radius0 */
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "movss (%eax), %xmm7\n" /* line 304 */
        "movss 4(%eax), %xmm6\n"
        "movss 8(%eax), %xmm5\n"
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "xorl %ecx, %ecx\n"
        "movss 0x18(%ebp), %xmm0\n" /* radius1 */
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "leal 0x10(%eax), %edx\n"
        ".Lfab95a_000ab9af:\n"
        "movss 0x14(%edx), %xmm2\n"
        "movss 0x18(%edx), %xmm3\n"
        "movss 0x2c(%eax), %xmm4\n" /* line 292 */
        "movaps %xmm7, %xmm0\n" /* line 293 */
        "mulss 0x10(%edx), %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss %xmm6, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "ucomiss -0xc(%ebp), %xmm0\n"
        "ja .Lfab95a_000aba0b\n"
        "movss 0x10(%edx), %xmm0\n" /* line 297 */
        "mulss (%ebx), %xmm0\n" /* worldPos1 */
        "mulss 4(%ebx), %xmm2\n" /* worldPos1 */
        "addss %xmm2, %xmm0\n"
        "mulss 8(%ebx), %xmm3\n" /* worldPos1 */
        "addss %xmm3, %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "ucomiss -0x10(%ebp), %xmm0\n"
        "jbe .Lfab95a_000aba21\n"
        ".Lfab95a_000aba0b:\n"
        "addl $1, %ecx\n" /* line 288 */
        "addl $0x10, %edx\n"
        "addl $0x10, %eax\n"
        "cmpl %ecx, %esi\n" /* planeCount */
        "jne .Lfab95a_000ab9af\n"
        ".Lfab95a_000aba18:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfab95a_000aba1a:\n"
        "addl $8, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfab95a_000aba21:\n"
        "movl $1, %eax\n" /* line 298 */
        "jmp .Lfab95a_000aba1a\n"
    );
}

/* line 165 */
__attribute__((naked))
void FxHelper_CalcFrustumPlanes(const FxHelper * _this, refdef_t *refdef, float zfar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 165 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* refdef */
        /* { scope 1 */
        "leal 0x20(%ebx), %edx\n" /* line 174 | this, to */
        /* { scope 2 */
        "movl 0x24(%esi), %eax\n" /* line 199 | refdef */
        "movl %eax, 0x20(%ebx)\n" /* this */
        "movl 0x28(%esi), %eax\n" /* line 200 | refdef */
        "movl %eax, 4(%edx)\n"
        "movl 0x2c(%esi), %eax\n" /* line 201 | refdef */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "cvtss2sd 0x10(%esi), %xmm0\n" /* line 176 | refdef */
        "mulsd 0x307c68, %xmm0\n" /* 0.008726646259971648 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* fAngle */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 486 | fAngle */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll cosf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm1\n"
        "leal 0x30(%ebx), %eax\n" /* line 179 | this, result */
        /* { scope 2 */
        "movss -0x38(%ebp), %xmm2\n" /* line 272 */
        "movaps %xmm2, %xmm0\n"
        "mulss 0x24(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x30(%ebx)\n" /* this */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss 0x28(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x34(%ebx)\n" /* this */
        "movaps %xmm2, %xmm0\n" /* line 274 */
        "mulss 0x2c(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x38(%ebx)\n" /* this */
        /* } scope */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x30(%esi), %xmm0\n" /* refdef */
        "addss 0x30(%ebx), %xmm0\n" /* this */
        "movss %xmm0, 0x30(%ebx)\n" /* this */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x34(%esi), %xmm0\n" /* refdef */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 0x34(%ebx)\n" /* this */
        "movaps %xmm1, %xmm0\n" /* line 290 */
        "mulss 0x38(%esi), %xmm0\n" /* refdef */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, 0x38(%ebx)\n" /* this */
        "leal 0x40(%ebx), %eax\n" /* line 182 | this, result */
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss 0x24(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x40(%ebx)\n" /* this */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss 0x28(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x44(%ebx)\n" /* this */
        "mulss 0x2c(%esi), %xmm2\n" /* line 274 | refdef */
        "movss %xmm2, 0x48(%ebx)\n" /* this */
        /* } scope */
        "xorps 0x2f1c50, %xmm1\n" /* line 183 | scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x30(%esi), %xmm0\n" /* refdef */
        "addss 0x40(%ebx), %xmm0\n" /* this */
        "movss %xmm0, 0x40(%ebx)\n" /* this */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x34(%esi), %xmm0\n" /* refdef */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 0x44(%ebx)\n" /* this */
        "mulss 0x38(%esi), %xmm1\n" /* line 290 | refdef */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 0x48(%ebx)\n" /* this */
        /* } scope */
        "cvtss2sd 0x14(%esi), %xmm0\n" /* line 185 | refdef */
        "mulsd 0x307c68, %xmm0\n" /* 0.008726646259971648 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 486 */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll cosf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm1\n"
        "leal 0x50(%ebx), %eax\n" /* line 188 | this, result */
        /* { scope 2 */
        "movss -0x38(%ebp), %xmm2\n" /* line 272 */
        "movaps %xmm2, %xmm0\n"
        "mulss 0x24(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x50(%ebx)\n" /* this */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss 0x28(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x54(%ebx)\n" /* this */
        "movaps %xmm2, %xmm0\n" /* line 274 */
        "mulss 0x2c(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x58(%ebx)\n" /* this */
        /* } scope */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x3c(%esi), %xmm0\n" /* refdef */
        "addss 0x50(%ebx), %xmm0\n" /* this */
        "movss %xmm0, 0x50(%ebx)\n" /* this */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x40(%esi), %xmm0\n" /* refdef */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 0x54(%ebx)\n" /* this */
        "movaps %xmm1, %xmm0\n" /* line 290 */
        "mulss 0x44(%esi), %xmm0\n" /* refdef */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, 0x58(%ebx)\n" /* this */
        "leal 0x60(%ebx), %eax\n" /* line 191 | this, result */
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss 0x24(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x60(%ebx)\n" /* this */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss 0x28(%esi), %xmm0\n" /* refdef */
        "movss %xmm0, 0x64(%ebx)\n" /* this */
        "mulss 0x2c(%esi), %xmm2\n" /* line 274 | refdef */
        "movss %xmm2, 0x68(%ebx)\n" /* this */
        /* } scope */
        "xorps 0x2f1c50, %xmm1\n" /* line 192 | scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x3c(%esi), %xmm0\n" /* refdef */
        "addss 0x60(%ebx), %xmm0\n" /* this */
        "movss %xmm0, 0x60(%ebx)\n" /* this */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x40(%esi), %xmm0\n" /* refdef */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 0x64(%ebx)\n" /* this */
        "mulss 0x44(%esi), %xmm1\n" /* line 290 | refdef */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 0x68(%ebx)\n" /* this */
        /* } scope */
        "movl $5, 0x80(%ebx)\n" /* line 194 | this */
        "pxor %xmm2, %xmm2\n" /* line 195 */
        "movss 0x10(%ebp), %xmm0\n" /* zfar */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lfaba28_000abcb8\n"
        "leal 0x70(%ebx), %eax\n" /* line 197 | this, to */
        /* { scope 2 */
        "movss 0x24(%esi), %xmm0\n" /* line 216 | refdef */
        "xorps 0x2f1c50, %xmm0\n"
        "movss %xmm0, 0x70(%ebx)\n" /* this */
        "movss 0x28(%esi), %xmm0\n" /* line 217 | refdef */
        "xorps 0x2f1c50, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 0x2c(%esi), %xmm0\n" /* line 218 | refdef */
        "xorps 0x2f1c50, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movl $6, 0x80(%ebx)\n" /* line 198 | this */
        ".Lfaba28_000abcb8:\n"
        "movl 0x80(%ebx), %edx\n" /* line 201 | this */
        "testl %edx, %edx\n"
        "jle .Lfaba28_000abd0a\n"
        "movl %ebx, %edx\n" /* this */
        "xorl %ecx, %ecx\n"
        "leal 0x14(%ebx), %esi\n" /* this, refdef */
        "movl 0x80(%ebx), %edi\n" /* this */
        "leal 0x10(%ebx), %eax\n" /* this */
        ".Lfaba28_000abcd2:\n"
        "movss 0x14(%ebx), %xmm0\n" /* line 204 | this */
        "mulss 0x10(%eax), %xmm0\n"
        "movss 4(%esi), %xmm1\n" /* refdef */
        "mulss 0x14(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss 8(%esi), %xmm1\n" /* refdef */
        "mulss 0x18(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x2c(%edx)\n"
        "addl $1, %ecx\n" /* line 201 */
        "addl $0x10, %eax\n"
        "addl $0x10, %edx\n"
        "cmpl %ecx, %edi\n"
        "jg .Lfaba28_000abcd2\n"
        ".Lfaba28_000abd0a:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 207 | zfar */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lfaba28_000abd23\n"
        "movss 0x7c(%ebx), %xmm0\n" /* line 208 | this */
        "subss 0x10(%ebp), %xmm0\n" /* zfar */
        "movss %xmm0, 0x7c(%ebx)\n" /* this */
        /* } scope */
        ".Lfaba28_000abd23:\n"
        "addl $0x4c, %esp\n" /* line 209 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 212 */
__attribute__((naked))
void FxHelper_AdjustCamera(const FxHelper * _this, refdef_t *refdef, float zfar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 212 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* refdef */
        "leal 0x14(%esi), %ecx\n" /* line 217 | this, to */
        "leal 0x18(%ebx), %edx\n" /* refdef, from */
        /* { scope 1 */
        "movl 0x18(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x14(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 219 | zfar */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* refdef */
        "movl %esi, (%esp)\n" /* this */
        "calll FxHelper_CalcFrustumPlanes\n"
        "movss 0x10(%ebx), %xmm0\n" /* line 221 | refdef */
        "ucomiss 0x2ed7d8, %xmm0\n" /* 80.0f */
        "jp .Lfabd2c_000abd86\n"
        "jne .Lfabd2c_000abd86\n"
        "movl $0x3f800000, 0xf8(%esi)\n" /* line 224 | this */
        "addl $0x30, %esp\n" /* line 225 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfabd2c_000abd86:\n"
        "movl $0x4ae74487, (%esp)\n" /* line 222 */
        "movl $0x3fe65718, 4(%esp)\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "calll tan\n"
        "fstpl -0x10(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll tan\n"
        "fstpl -0x18(%ebp)\n"
        "movsd -0x10(%ebp), %xmm0\n"
        "divsd -0x18(%ebp), %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0xf8(%esi)\n" /* this */
        "addl $0x30, %esp\n" /* line 225 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 345 */
__attribute__((naked))
void FxHelper_Archive(const FxHelper * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 345 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfabde6_000abeeb\n"
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %edi\n" /* i */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 4(%esi)\n"
        ".Lfabde6_000abe1c:\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfabde6_000abecc\n"
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 100 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 8(%esi)\n"
        ".Lfabde6_000abe40:\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfabde6_000abeb0\n"
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 100 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0xc(%esi)\n"
        ".Lfabde6_000abe60:\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfabde6_000abe94\n"
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 100 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0x10(%esi)\n"
        ".Lfabde6_000abe80:\n"
        "cmpb $0, 4(%ebx)\n" /* line 354 | arch */
        "je .Lfabde6_000abe8c\n"
        "movl $0, (%esi)\n" /* line 355 | this */
        ".Lfabde6_000abe8c:\n"
        "addl $0x2c, %esp\n" /* line 356 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfabde6_000abe94:\n"
        "movl 0x10(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 137 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfabde6_000abe80\n"
        /* } scope */
        ".Lfabde6_000abeb0:\n"
        "movl 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 137 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfabde6_000abe60\n"
        /* } scope */
        ".Lfabde6_000abecc:\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 137 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfabde6_000abe40\n"
        /* } scope */
        ".Lfabde6_000abeeb:\n"
        "movl 4(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %edi\n" /* i */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfabde6_000abe1c\n"
    );
}

