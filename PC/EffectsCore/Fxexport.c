/* ASM dump from: Fxexport.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/Fxexport.cpp */

#include "common_types.h"
#include "imports.h"

extern volatile qboolean fx_camera_valid; /* 0x0 */

int FX_GetBoneIndex(const int entNum, unsigned int bone);
void FX_PlaySimpleEffect(EffectTemplate *fx, const vec_t *org);
void FX_PlayEffect(EffectTemplate *fx, const vec_t *org, const vec_t *fwd);
void FX_PlayEntityEffect(EffectTemplate *fx, const vec_t *org, vec3_t *axis, const FxBoltInfo *bolt);
int FX_InitSystem(int rendererExists);
void FX_FreeSystem(void);
void FX_FreeActive(void);
void FX_AdjustCamera(PrimType (*refdef)[256], float zfar);
void FX_AdjustTime(int time);
void FX_WarpTime(int time);
float FX_GetEffectLength(EffectTemplate *fx);
void Server_SwitchToValidFxScheduler(void);

/* line 49 */
__attribute__((naked))
int FX_GetBoneIndex(const int entNum, unsigned int bone)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 49 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* bone */
        /* { scope 1 */
        "movl $0, 4(%esp)\n" /* line 53 */
        "movl 8(%ebp), %eax\n" /* entNum, pObj */
        "movl %eax, (%esp)\n" /* pObj */
        "calll Com_GetClientDObj\n"
        "testl %eax, %eax\n" /* line 54 */
        "je .Lf613ba_000613eb\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 56 | bone */
        "movl %eax, 8(%ebp)\n" /* entNum */
        /* } scope */
        "addl $0x14, %esp\n" /* line 57 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjGetBoneIndex\n" /* line 56 */
        /* } scope */
        ".Lf613ba_000613eb:\n"
        "movl $0xffffffff, %eax\n" /* line 57 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 60 */
__attribute__((naked))
void FX_PlaySimpleEffect(EffectTemplate *fx, const vec_t *org)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 63 | org */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* fx */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        "leave\n" /* line 64 */
        "retl\n"
    );
}

/* line 67 */
__attribute__((naked))
void FX_PlayEffect(EffectTemplate *fx, const vec_t *org, const vec_t *fwd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 67 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* line 70 | fwd */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* org */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* fx */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        "leave\n" /* line 71 */
        "retl\n"
    );
}

/* overload skip: FX_PlayEffect (0x61448) */

/* line 81 */
__attribute__((naked))
void FX_PlayEntityEffect(EffectTemplate *fx, const vec_t *org, vec3_t *axis, const FxBoltInfo *bolt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 81 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 0x14(%ebp), %eax\n" /* line 85 | bolt */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* axis */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* org */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* fx */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        "leave\n" /* line 86 */
        "retl\n"
    );
}

/* line 89 */
__attribute__((naked))
int FX_InitSystem(int rendererExists)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "movzbl 8(%ebp), %eax\n" /* line 91 | rendererExists */
        "movl %eax, 8(%ebp)\n" /* rendererExists */
        "popl %ebp\n" /* line 92 */
        "jmp FX_Init\n" /* line 91 */
    );
}

/* line 95 */
__attribute__((naked))
void FX_FreeSystem(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, (%esp)\n" /* line 97 */
        "calll FX_Free\n"
        "leave\n" /* line 98 */
        "retl\n"
    );
}

/* line 101 */
__attribute__((naked))
void FX_FreeActive(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 101 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, (%esp)\n" /* line 103 */
        "calll FX_Free\n"
        "leave\n" /* line 104 */
        "retl\n"
    );
}

/* line 107 */
__attribute__((naked))
void FX_AdjustCamera(PrimType (*refdef)[256], float zfar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 107 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 110 | zfar */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* refdef */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_AdjustCamera\n"
        "movl $1, fx_camera_valid\n" /* line 115 */
        "leave\n" /* line 117 */
        "retl\n"
    );
}

/* line 120 */
__attribute__((naked))
void FX_AdjustTime(int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 120 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, fx_camera_valid\n" /* line 125 */
        "movl 8(%ebp), %eax\n" /* line 127 | time */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_AdjustTime\n"
        "movl 0x195ed84, %eax\n" /* line 129 */
        "movl (%eax), %edx\n"
        "movl 0x195ed90, %eax\n"
        "movl %edx, (%eax)\n"
        "movl 0x195ed8c, %eax\n" /* line 130 */
        "movl (%eax), %edx\n"
        "movl 0x195ed94, %eax\n"
        "movl %edx, (%eax)\n"
        "leave\n" /* line 131 */
        "retl\n"
    );
}

/* line 135 */
__attribute__((naked))
void FX_WarpTime(int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 135 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 138 | time */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_WarpTime\n"
        "leave\n" /* line 139 */
        "retl\n"
    );
}

/* line 143 */
__attribute__((naked))
float FX_GetEffectLength(EffectTemplate *fx)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 143 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 146 | fx */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_GetEffectLength\n"
        "leave\n" /* line 147 */
        "retl\n"
    );
}

/* line 29 */
__attribute__((naked))
void Server_SwitchToValidFxScheduler(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 43 */
        "retl\n"
    );
}

