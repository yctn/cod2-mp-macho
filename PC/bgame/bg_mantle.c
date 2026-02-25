/* ASM dump from: bg_mantle.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_mantle.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static const dvar_t *mantle_enable; /* 0x4ed300 */
static const dvar_t *mantle_debug; /* 0x4ed30c */
static const dvar_t *mantle_check_range; /* 0x4ed314 */
static const dvar_t *mantle_check_radius; /* 0x4ed318 */
static const dvar_t *mantle_check_angle; /* 0x4ed310 */
static const dvar_t *mantle_view_yawcap; /* 0x4ed304 */
static MantleAnimTransition s_mantleTrans[7]; /* 0x30aaa0 */
static char * s_mantleAnimNames[11]; /* 0x30ab00 */
static char (*s_mantleAnims)[64]; /* 0x4ed308 */

void Mantle_RegisterDvars(void);
static void * MantleXAnimPrecacheAlloc(int size);
void Mantle_ShutdownAnims(void);
void Mantle_ClearHint(playerState_t *ps);
void Mantle_CapView(playerState_t *ps);
Bool Mantle_IsWeaponInactive(playerState_t *ps);
void Mantle_CreateAnims(MantleAnimAlloc xanimAlloc);
static void Mantle_GetAnimDelta(int time);
void Mantle_Move(pmove_t *pm, playerState_t *ps, pml_t *pml);
static Bool Mantle_CheckLedge(float height);
void Mantle_Check(pmove_t *pm, pml_t *pml);

/* line 161 */
__attribute__((naked))
void Mantle_RegisterDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 161 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $0x1180, 8(%esp)\n" /* line 170 */
        "movl $1, 4(%esp)\n"
        "movl $0x21e064, (%esp)\n" /* "mantle_enable" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, mantle_enable\n"
        "movl $0x1180, 8(%esp)\n" /* line 171 */
        "movl $0, 4(%esp)\n"
        "movl $0x21e074, (%esp)\n" /* "mantle_debug" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, mantle_debug\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 172 */
        "movl $0x43000000, 0xc(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x41a00000, 4(%esp)\n"
        "movl $0x21e084, (%esp)\n" /* "mantle_check_range" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, mantle_check_range\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 173 */
        "movl $0x41700000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3dcccccd, 4(%esp)\n"
        "movl $0x21e098, (%esp)\n" /* "mantle_check_radius" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, mantle_check_radius\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 174 */
        "movl $0x43340000, %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x42700000, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x21e0ac, (%esp)\n" /* "mantle_check_angle" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, mantle_check_angle\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 175 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x21e0c0, (%esp)\n" /* "mantle_view_yawcap" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, mantle_view_yawcap\n"
        "addl $0x2c, %esp\n" /* line 176 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 183 */
static __attribute__((naked))
void * MantleXAnimPrecacheAlloc(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 183 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $4, 4(%esp)\n" /* line 185 */
        "movl 8(%ebp), %eax\n" /* size */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "leave\n" /* line 186 */
        "retl\n"
    );
}

/* line 577 */
__attribute__((naked))
void Mantle_ShutdownAnims(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 577 */
        "movl %esp, %ebp\n"
        "movl $0, s_mantleAnims\n" /* line 579 */
        "popl %ebp\n" /* line 580 */
        "retl\n"
    );
}

/* line 857 */
__attribute__((naked))
void Mantle_ClearHint(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 857 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* ps */
        "andl $0xfffffff7, 0x5c8(%eax)\n" /* line 861 */
        "popl %ebp\n" /* line 862 */
        "retl\n"
    );
}

/* line 825 */
__attribute__((naked))
void Mantle_CapView(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 825 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ps */
        /* { scope 1 */
        "movl mantle_enable, %eax\n" /* line 833 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf9ee5c_0009ee77\n"
        /* } scope */
        ".Lf9ee5c_0009ee71:\n"
        "addl $0x24, %esp\n" /* line 851 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9ee5c_0009ee77:\n"
        "movl 0xec(%ebx), %eax\n" /* line 836 | ps */
        "movl %eax, 4(%esp)\n"
        "movl 0x5bc(%ebx), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0xc(%ebp)\n"
        "movss -0xc(%ebp), %xmm1\n"
        "movl mantle_view_yawcap, %eax\n" /* line 838 */
        "movss 8(%eax), %xmm2\n"
        "movaps %xmm2, %xmm3\n"
        "xorps 0x2f1ba0, %xmm3\n"
        "ucomiss %xmm3, %xmm1\n"
        "jb .Lf9ee5c_0009eebe\n"
        "ucomiss %xmm1, %xmm2\n"
        "jae .Lf9ee5c_0009ee71\n"
        "ucomiss %xmm1, %xmm3\n" /* line 841 */
        "jbe .Lf9ee5c_0009eecc\n"
        ".Lf9ee5c_0009eeba:\n"
        "addss %xmm2, %xmm1\n" /* line 842 */
        ".Lf9ee5c_0009eebe:\n"
        "ucomiss %xmm1, %xmm3\n" /* line 841 */
        "ja .Lf9ee5c_0009eeba\n"
        "ucomiss %xmm2, %xmm1\n" /* line 844 */
        "jbe .Lf9ee5c_0009eed1\n"
        ".Lf9ee5c_0009eec8:\n"
        "subss %xmm2, %xmm1\n" /* line 845 */
        ".Lf9ee5c_0009eecc:\n"
        "ucomiss %xmm2, %xmm1\n" /* line 844 */
        "ja .Lf9ee5c_0009eec8\n"
        ".Lf9ee5c_0009eed1:\n"
        "pxor %xmm0, %xmm0\n" /* line 847 */
        "movaps %xmm3, %xmm4\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "mulss 0x2ed644, %xmm1\n" /* line 849 | 182.04444885253906f */
        "cvttss2si %xmm1, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x58(%ebx)\n" /* ps */
        "addss 0x5bc(%ebx), %xmm0\n" /* line 850 | ps */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps 0xec(%ebx)\n" /* ps */
        /* } scope */
        "addl $0x24, %esp\n" /* line 851 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 868 */
__attribute__((naked))
Bool Mantle_IsWeaponInactive(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 868 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* ps */
        /* { scope 1 */
        "movl mantle_enable, %eax\n" /* line 873 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9ef18_0009ef4b\n"
        "leal 0x5bc(%edx), %eax\n" /* line 876 */
        "testb $4, 0xc(%edx)\n" /* line 878 */
        "je .Lf9ef18_0009ef4b\n"
        "movl 8(%eax), %eax\n" /* line 883 */
        "leal (%eax, %eax, 2), %eax\n"
        "cmpl $0xa, 0x30aaa4(, %eax, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 884 */
        "retl\n"
        /* { scope 1 */
        ".Lf9ef18_0009ef4b:\n"
        "xorl %eax, %eax\n" /* line 883 */
        /* } scope */
        "popl %ebp\n" /* line 884 */
        "retl\n"
    );
}

/* line 519 */
__attribute__((naked))
void Mantle_CreateAnims(MantleAnimAlloc xanimAlloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 519 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl s_mantleAnims, %eax\n" /* line 526 */
        "testl %eax, %eax\n"
        "je .Lf9ef50_0009ef6a\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 571 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9ef50_0009ef6a:\n"
        "movl 8(%ebp), %eax\n" /* line 529 | xanimAlloc */
        "movl %eax, 8(%esp)\n"
        "movl $0xb, 4(%esp)\n"
        "movl $0x21e0d4, (%esp)\n" /* "PLAYER_MANTLE" */
        "calll XAnimCreateAnims\n"
        "movl %eax, s_mantleAnims\n"
        "movl $0, 0x14(%esp)\n" /* line 532 */
        "movl $0xa, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl s_mantleAnimNames, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimBlend\n"
        "movl $1, %edi\n"
        "movl $s_mantleAnimNames, %esi\n"
        ".Lf9ef50_0009efc6:\n"
        "leal 4(%esi), %ebx\n" /* line 519 */
        "movl $MantleXAnimPrecacheAlloc, 4(%esp)\n" /* line 537 */
        "movl 4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimPrecache\n"
        "movl 4(%esi), %eax\n" /* line 539 */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimCreate\n"
        "addl $1, %edi\n" /* line 534 */
        "movl %ebx, %esi\n" /* animIndex */
        "cmpl $0xb, %edi\n"
        "jne .Lf9ef50_0009efc6\n"
        "movl $s_mantleTrans, %esi\n"
        "leal -0x30(%ebp), %edi\n" /* rot */
        ".Lf9ef50_0009f006:\n"
        "movl (%esi), %ebx\n" /* line 546 | animIndex */
        "movl $0x3f800000, 0x10(%esp)\n" /* line 547 */
        "leal -0x24(%ebp), %eax\n" /* delta */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* animIndex */
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetAbsDelta\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 549 | delta */
        "movaps %xmm1, %xmm0\n"
        "subss 0x2ed6a8, %xmm0\n" /* 16.0f */
        "andps 0x2f1bb0, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf9ef50_0009f085\n"
        "movl $0, 0x14(%esp)\n" /* line 550 */
        "movl $0x40300000, 0x18(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0xc(%esp)\n"
        "movl s_mantleAnimNames(, %ebx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21e0e4, 4(%esp)\n" /* "Mantle anim [%s] has X translation %f, should be %f
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf9ef50_0009f085:\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 552 */
        "movaps %xmm1, %xmm0\n"
        "andps 0x2f1bb0, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf9ef50_0009f0d6\n"
        "movl $0, 0x14(%esp)\n" /* line 553 */
        "movl $0, 0x18(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0xc(%esp)\n"
        "movl s_mantleAnimNames(, %ebx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21e11c, 4(%esp)\n" /* "Mantle anim [%s] has Y translation %f, should be %f
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf9ef50_0009f0d6:\n"
        "movss -0x1c(%ebp), %xmm2\n" /* line 555 */
        "movss 8(%esi), %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "andps 0x2f1bb0, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf9ef50_0009f12a\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 556 */
        "movsd %xmm1, 0x14(%esp)\n"
        "cvtss2sd %xmm2, %xmm2\n"
        "movsd %xmm2, 0xc(%esp)\n"
        "movl s_mantleAnimNames(, %ebx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21e154, 4(%esp)\n" /* "Mantle anim [%s] has Z translation %f, should be %f
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf9ef50_0009f12a:\n"
        "movl 4(%esi), %ebx\n" /* line 559 | animIndex */
        "movl $0x3f800000, 0x10(%esp)\n" /* line 560 */
        "leal -0x24(%ebp), %eax\n" /* delta */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* animIndex */
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetAbsDelta\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 562 | delta */
        "movaps %xmm1, %xmm0\n"
        "subss 0x2ed800, %xmm0\n" /* 31.0f */
        "andps 0x2f1bb0, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf9ef50_0009f1aa\n"
        "movl $0, 0x14(%esp)\n" /* line 563 */
        "movl $0x403f0000, 0x18(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0xc(%esp)\n"
        "movl s_mantleAnimNames(, %ebx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21e0e4, 4(%esp)\n" /* "Mantle anim [%s] has X translation %f, should be %f
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf9ef50_0009f1aa:\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 565 */
        "movaps %xmm1, %xmm0\n"
        "andps 0x2f1bb0, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf9ef50_0009f1fb\n"
        "movl $0, 0x14(%esp)\n" /* line 566 */
        "movl $0, 0x18(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0xc(%esp)\n"
        "movl s_mantleAnimNames(, %ebx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21e11c, 4(%esp)\n" /* "Mantle anim [%s] has Y translation %f, should be %f
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf9ef50_0009f1fb:\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 568 */
        "movaps %xmm1, %xmm0\n"
        "addss 0x2ed6c8, %xmm0\n" /* 18.0f */
        "andps 0x2f1bb0, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf9ef50_0009f254\n"
        "movl $0, 0x14(%esp)\n" /* line 569 */
        "movl $0xc0320000, 0x18(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0xc(%esp)\n"
        "movl s_mantleAnimNames(, %ebx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21e154, 4(%esp)\n" /* "Mantle anim [%s] has Z translation %f, should be %f
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf9ef50_0009f254:\n"
        "addl $0xc, %esi\n"
        "cmpl $0x30aaf4, %esi\n" /* line 543 */
        "jne .Lf9ef50_0009f006\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 571 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 263 */
static __attribute__((naked))
void Mantle_GetAnimDelta(int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 263 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* mstate */
        "movl %edx, -0x40(%ebp)\n"
        "movl %ecx, %esi\n" /* delta */
        /* { scope 1 */
        "movl 8(%eax), %eax\n" /* line 213 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl s_mantleTrans(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "movl %eax, %ebx\n"
        "testb $1, 0xc(%edi)\n" /* line 227 */
        "jne .Lf9f26c_0009f3b9\n"
        "movl $0, -0x3c(%ebp)\n" /* overTime */
        ".Lf9f26c_0009f2ad:\n"
        "cmpl -0x40(%ebp), %ebx\n" /* line 277 | upTime */
        "jl .Lf9f26c_0009f304\n"
        "cvtsi2ssl -0x40(%ebp), %xmm0\n" /* line 282 */
        "cvtsi2ssl %ebx, %xmm1\n" /* upTime */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* delta */
        "leal -0x20(%ebp), %eax\n" /* rot */
        "movl %eax, 8(%esp)\n"
        "movl 8(%edi), %eax\n" /* mstate */
        "leal (%eax, %eax, 2), %eax\n"
        "movl s_mantleTrans(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetAbsDelta\n"
        "movl (%edi), %eax\n" /* line 297 | mstate */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* delta */
        "calll VectorAngleMultiply\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 298 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9f26c_0009f304:\n"
        "movl $0x3f800000, 0x10(%esp)\n" /* line 289 */
        "leal -0x2c(%ebp), %eax\n" /* trans */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* rot */
        "movl %eax, 8(%esp)\n"
        "movl 8(%edi), %eax\n" /* mstate */
        "leal (%eax, %eax, 2), %eax\n"
        "movl s_mantleTrans(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetAbsDelta\n"
        "subl %ebx, -0x40(%ebp)\n" /* line 292 | upTime */
        "cvtsi2ssl -0x40(%ebp), %xmm0\n"
        "cvtsi2ssl -0x3c(%ebp), %xmm1\n" /* overTime */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* delta */
        "leal -0x20(%ebp), %eax\n" /* rot */
        "movl %eax, 8(%esp)\n"
        "movl 8(%edi), %eax\n" /* mstate */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x30aaa4(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetAbsDelta\n"
        "movss (%esi), %xmm0\n" /* line 240 */
        "addss -0x2c(%ebp), %xmm0\n" /* trans */
        "movss %xmm0, (%esi)\n"
        "movss 4(%esi), %xmm0\n" /* line 241 */
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss 8(%esi), %xmm0\n" /* line 242 */
        "addss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        "movl (%edi), %eax\n" /* line 297 | mstate */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* delta */
        "calll VectorAngleMultiply\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 298 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9f26c_0009f3b9:\n"
        "movl 8(%edi), %eax\n" /* line 231 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x30aaa4(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "movl %eax, -0x3c(%ebp)\n" /* overTime */
        "jmp .Lf9f26c_0009f2ad\n"
    );
}

/* line 744 */
__attribute__((naked))
void Mantle_Move(pmove_t *pm, playerState_t *ps, pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 744 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* ps */
        /* { scope 1 */
        "movl mantle_enable, %eax\n" /* line 757 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9f3e0_0009f58a\n"
        "leal 0x5bc(%edi), %ebx\n" /* line 760 | ps, mstate */
        "movl 0xc(%ebx), %eax\n" /* line 762 | mstate */
        "movl %eax, %edx\n"
        "andl $0xfffffff7, %edx\n"
        "movl %edx, 0xc(%ebx)\n" /* mstate */
        "testb $2, %al\n" /* line 765 */
        "jne .Lf9f3e0_0009f5b5\n"
        /* { scope 2 */
        ".Lf9f3e0_0009f414:\n"
        "movl 8(%ebx), %eax\n" /* line 213 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl s_mantleTrans(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "movl %eax, %esi\n" /* time */
        /* } scope */
        /* { scope 2 */
        "testb $1, 0xc(%ebx)\n" /* line 227 */
        "jne .Lf9f3e0_0009f592\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf9f3e0_0009f440:\n"
        "addl %esi, %eax\n" /* line 768 | upTime */
        "movl %eax, -0x3c(%ebp)\n" /* mantleLength */
        "movl 4(%ebx), %edx\n" /* line 770 | mstate */
        "movl %edx, %eax\n" /* line 771 */
        "movl 0x10(%ebp), %ecx\n" /* pml */
        "addl 0x28(%ecx), %eax\n"
        "cmpl %eax, -0x3c(%ebp)\n" /* line 774 | mantleLength */
        "cmovll -0x3c(%ebp), %eax\n" /* mantleLength */
        "movl %eax, 4(%ebx)\n" /* mstate */
        "subl %edx, %eax\n" /* line 776 */
        "movl %eax, -0x40(%ebp)\n" /* deltaTime */
        "leal -0x30(%ebp), %ecx\n" /* line 778 | prevTrans */
        "movl %ebx, %eax\n" /* mstate */
        "calll Mantle_GetAnimDelta\n"
        "leal -0x24(%ebp), %ecx\n" /* line 779 | trans */
        "movl 4(%ebx), %edx\n" /* mstate */
        "movl %ebx, %eax\n" /* mstate */
        "calll Mantle_GetAnimDelta\n"
        /* { scope 2 */
        "movl 8(%ebx), %eax\n" /* line 213 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl s_mantleTrans(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "movl %eax, %esi\n" /* time */
        "testb $1, 0xc(%ebx)\n" /* line 227 */
        "jne .Lf9f3e0_0009f5e4\n"
        ".Lf9f3e0_0009f4a0:\n"
        "cmpl 4(%ebx), %esi\n" /* line 251 | upTime */
        "jl .Lf9f3e0_0009f5d2\n"
        "movl 8(%ebx), %eax\n" /* line 252 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl s_mantleTrans(, %eax, 4), %eax\n"
        /* } scope */
        ".Lf9f3e0_0009f4b6:\n"
        "movl $1, 0xc(%esp)\n" /* line 785 */
        "addl $0x14, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movss -0x24(%ebp), %xmm2\n" /* line 248 | trans */
        "subss -0x30(%ebp), %xmm2\n" /* prevTrans */
        "movss %xmm2, -0x24(%ebp)\n" /* trans */
        "movss -0x20(%ebp), %xmm1\n" /* line 249 */
        "subss -0x2c(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 250 */
        "subss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal 0x14(%edi), %eax\n" /* line 790 | ps, sum */
        /* { scope 2 */
        "addss 0x14(%edi), %xmm2\n" /* line 240 */
        "movss %xmm2, 0x14(%edi)\n"
        "addss 4(%eax), %xmm1\n" /* line 241 */
        "movss %xmm1, 4(%eax)\n"
        "addss 8(%eax), %xmm0\n" /* line 242 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "leal 0x20(%edi), %eax\n" /* line 791 | ps, result */
        "cvtsi2ssl -0x40(%ebp), %xmm1\n" /* deltaTime */
        "mulss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f, scale */
        "divss %xmm1, %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm1\n" /* trans */
        "movss %xmm1, 0x20(%edi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movl -0x3c(%ebp), %eax\n" /* line 793 | mantleLength */
        "cmpl 4(%ebx), %eax\n" /* mstate */
        "jne .Lf9f3e0_0009f58a\n"
        "andl $0xfffffffb, 0xc(%edi)\n" /* line 796 | ps */
        "movl 8(%ebp), %ecx\n" /* line 800 | pm */
        "movb $0, 0xe5(%ecx)\n"
        "movl 0xc(%ebx), %edx\n" /* line 802 | mstate */
        "testb $1, %dl\n"
        "jne .Lf9f3e0_0009f631\n"
        ".Lf9f3e0_0009f585:\n"
        "andb $4, %dl\n" /* line 810 */
        "jne .Lf9f3e0_0009f607\n"
        /* } scope */
        ".Lf9f3e0_0009f58a:\n"
        "addl $0x4c, %esp\n" /* line 819 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf9f3e0_0009f592:\n"
        "movl 8(%ebx), %eax\n" /* line 231 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x30aaa4(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "jmp .Lf9f3e0_0009f440\n"
        /* } scope */
        ".Lf9f3e0_0009f5b5:\n"
        "movl %edi, 8(%esp)\n" /* line 766 | ps */
        "movl $0, 4(%esp)\n"
        "movl $0x8d, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "jmp .Lf9f3e0_0009f414\n"
        /* { scope 2 */
        ".Lf9f3e0_0009f5d2:\n"
        "movl 8(%ebx), %eax\n" /* line 254 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x30aaa4(, %eax, 4), %eax\n"
        "jmp .Lf9f3e0_0009f4b6\n"
        ".Lf9f3e0_0009f5e4:\n"
        "movl 8(%ebx), %eax\n" /* line 231 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x30aaa4(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "jmp .Lf9f3e0_0009f4a0\n"
        /* } scope */
        ".Lf9f3e0_0009f607:\n"
        "movl %edi, 8(%esp)\n" /* line 812 | ps */
        "movl $0, 4(%esp)\n"
        "movl $0x8c, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "andl $0xffffbfff, 0xa0(%edi)\n" /* line 815 | ps */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 819 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9f3e0_0009f631:\n"
        "movl $1, 0xc(%esp)\n" /* line 804 */
        "movl $0, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "movl 0xc(%ebx), %edx\n" /* mstate */
        "jmp .Lf9f3e0_0009f585\n"
    );
}

/* line 418 */
static __attribute__((naked))
Bool Mantle_CheckLedge(float height)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 418 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10c, %esp\n"
        "movl %eax, %edi\n" /* pm */
        "movl %ecx, %esi\n" /* mresults */
        "movss %xmm0, -0xf0(%ebp)\n"
        /* { scope 1: to, trace, start, end, ... */
        "movl (%eax), %ebx\n" /* line 428 | ps */
        "movss 0x578(%ebx), %xmm0\n" /* line 431 | ps */
        "movss %xmm0, -0xe4(%ebp)\n" /* playerRadius */
        "cvtss2sd -0xf0(%ebp), %xmm0\n" /* line 433 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x21e18c, (%esp)\n" /* "Checking for ledge at %f units" */
        "calll va\n"
        "movl %eax, %edx\n" /* pml */
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf9f65a_0009f878\n"
        ".Lf9f65a_0009f6af:\n"
        "movss -0xe4(%ebp), %xmm0\n" /* line 435 | playerRadius, y */
        "xorps 0x2f1bc0, %xmm0\n" /* y */
        /* { scope 2: time, mstate */
        "movss %xmm0, -0x3c(%ebp)\n" /* line 191 | mins */
        "movss %xmm0, -0x38(%ebp)\n" /* line 192 */
        "movl $0, -0x34(%ebp)\n" /* line 193 */
        /* } scope */
        "movss -0xe4(%ebp), %xmm0\n" /* line 191 | playerRadius */
        "movss %xmm0, -0x48(%ebp)\n" /* maxs */
        "movss %xmm0, -0x44(%ebp)\n" /* line 192 */
        "addss %xmm0, %xmm0\n" /* line 193 */
        "movss %xmm0, -0x40(%ebp)\n"
        "leal 0xc(%esi), %edx\n"
        /* { scope 2: time, mstate */
        "movl 0xc(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x54(%ebp)\n" /* start */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x50(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x4c(%ebp)\n"
        /* } scope */
        "movss -0xf0(%ebp), %xmm0\n" /* line 439 */
        "addss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss 0x2ed6a8, %xmm1\n" /* line 288 | 16.0f */
        "movss (%esi), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0x54(%ebp), %xmm0\n" /* start */
        "movss %xmm0, -0x30(%ebp)\n" /* end */
        "leal 4(%esi), %eax\n" /* line 289 */
        "movl %eax, -0xe0(%ebp)\n"
        "movss 4(%esi), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "leal 8(%esi), %edx\n" /* line 290 */
        "movl %edx, -0xdc(%ebp)\n"
        "mulss 8(%esi), %xmm1\n"
        "addss -0x4c(%ebp), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movl 0x3c(%edi), %eax\n" /* line 443 | pm */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* end */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* maxs */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* mins */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x54(%ebp), %edx\n" /* start */
        "movl %edx, 8(%esp)\n"
        "leal -0xc0(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pm */
        "calll PM_trace\n"
        "cmpb $0, -0x9d(%ebp)\n" /* line 445 */
        "jne .Lf9f65a_0009f857\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss -0xc0(%ebp), %xmm0\n" /* trace */
        "ja .Lf9f65a_0009f857\n"
        "movl -0x30(%ebp), %eax\n" /* line 199 | end */
        "movl %eax, -0x54(%ebp)\n" /* start */
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x50(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x4c(%ebp)\n"
        "movss 0x2ed6c8, %xmm0\n" /* line 453 | 18.0f */
        "addss 0x14(%esi), %xmm0\n" /* mresults */
        "movss %xmm0, -0x28(%ebp)\n"
        "movl 0x3c(%edi), %eax\n" /* line 455 | pm */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* end */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* maxs */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* mins */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x54(%ebp), %edx\n" /* start */
        "movl %edx, 8(%esp)\n"
        "leal -0xc0(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pm */
        "calll PM_trace\n"
        "cmpb $0, -0x9d(%ebp)\n" /* line 457 */
        "jne .Lf9f65a_0009f83f\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss -0xc0(%ebp), %xmm0\n" /* trace */
        "jne .Lf9f65a_0009f8ae\n"
        "jp .Lf9f65a_0009f8ae\n"
        ".Lf9f65a_0009f83f:\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf9f65a_0009f88d\n"
        ".Lf9f65a_0009f84a:\n"
        "xorl %eax, %eax\n" /* line 200 */
        /* } scope */
        ".Lf9f65a_0009f84c:\n"
        "addl $0x10c, %esp\n" /* line 513 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: to, trace, start, end, ... */
        ".Lf9f65a_0009f857:\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9f65a_0009f84a\n"
        "movl $0x21e1ac, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9f65a_0009f84a\n"
        ".Lf9f65a_0009f878:\n"
        "movl %edx, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9f65a_0009f6af\n"
        ".Lf9f65a_0009f88d:\n"
        "movl $0x21e1d4, 4(%esp)\n" /* "Mantle Failed: Can't find ledge" */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10c, %esp\n" /* line 513 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: to, trace, start, end, ... */
        ".Lf9f65a_0009f8ae:\n"
        "movss 0x2ed6ac, %xmm0\n" /* line 464 | 0.699999988079071f */
        "ucomiss -0xb4(%ebp), %xmm0\n"
        "jbe .Lf9f65a_0009f8e5\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9f65a_0009f84a\n"
        "movl $0x21e1f4, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf9f65a_0009f84c\n"
        ".Lf9f65a_0009f8e5:\n"
        "leal 0x18(%esi), %eax\n" /* line 471 | mresults */
        "movl %eax, -0xd8(%ebp)\n" /* to */
        /* { scope 2: time, mstate */
        "movl -0x30(%ebp), %eax\n" /* line 199 | end */
        "movl %eax, 0x18(%esi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl -0xd8(%ebp), %edx\n" /* to */
        "movl %eax, 4(%edx)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "movss -0x4c(%ebp), %xmm1\n" /* line 472 */
        "subss %xmm1, %xmm0\n"
        "mulss -0xc0(%ebp), %xmm0\n" /* trace */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x20(%esi)\n" /* mresults */
        "movl $0x42480000, -0x40(%ebp)\n" /* line 477 */
        "movl 0x3c(%edi), %eax\n" /* line 478 | pm */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* maxs */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* mins */
        "movl %edx, 0xc(%esp)\n"
        "movl -0xd8(%ebp), %eax\n" /* to */
        "movl %eax, 8(%esp)\n"
        "leal -0xc0(%ebp), %edx\n" /* trace */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pm */
        "calll PM_trace\n"
        "cmpb $0, -0x9d(%ebp)\n" /* line 480 */
        "je .Lf9f65a_0009f99d\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9f65a_0009f84a\n"
        "movl $0x21e218, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf9f65a_0009f84c\n"
        ".Lf9f65a_0009f99d:\n"
        "orl $8, 0x5c8(%ebx)\n" /* line 487 | ps */
        "orl $8, 0x30(%esi)\n" /* line 488 | mresults */
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf9f65a_0009fb5c\n"
        ".Lf9f65a_0009f9b7:\n"
        "testb $4, 9(%edi)\n" /* line 494 | pm */
        "je .Lf9f65a_0009fb52\n"
        /* { scope 2: time, mstate */
        "movl (%edi), %ecx\n" /* line 344 */
        "testb $1, 0x30(%esi)\n" /* line 347 */
        "jne .Lf9f65a_0009fc69\n"
        "leal 0x24(%esi), %eax\n" /* line 349 */
        "movl %eax, -0xf4(%ebp)\n"
        "movl 0x18(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x24(%esi)\n"
        "movl -0xd8(%ebp), %edx\n" /* line 200 | to */
        "movl 4(%edx), %eax\n"
        "movl -0xf4(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "movl -0xd8(%ebp), %edx\n" /* line 201 | to */
        "movl 8(%edx), %eax\n"
        "movl -0xf4(%ebp), %edx\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lf9f65a_0009fa00:\n"
        "testb $4, 0xa0(%ebx)\n" /* line 500 | ps */
        "je .Lf9f65a_0009fb98\n"
        /* { scope 2: time, mstate */
        ".Lf9f65a_0009fa0d:\n"
        "leal 0x5bc(%ebx), %eax\n" /* line 388 */
        "movl %eax, -0xcc(%ebp)\n" /* mstate */
        "movl %esi, (%esp)\n" /* line 390 */
        "calll vectoyaw\n"
        "fstps 0x5bc(%ebx)\n"
        "movl -0xcc(%ebp), %edx\n" /* line 391 | mstate */
        "movl $0, 4(%edx)\n"
        /* { scope 3 */
        "movss 0x20(%esi), %xmm3\n" /* line 312 */
        "subss 0x14(%esi), %xmm3\n"
        "movss 0x30aaa8, %xmm1\n" /* line 54 */
        "subss %xmm3, %xmm1\n"
        "movss 0x2f1bd0, %xmm2\n"
        "andps %xmm2, %xmm1\n"
        "xorl %ecx, %ecx\n"
        "movl $1, %eax\n"
        "movl $s_mantleTrans, %edx\n"
        ".Lf9f65a_0009fa61:\n"
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "andps %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n" /* line 321 */
        "jbe .Lf9f65a_0009fa77\n"
        "movl %eax, %ecx\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf9f65a_0009fa77:\n"
        "addl $1, %eax\n" /* line 318 */
        "addl $0xc, %edx\n"
        "cmpl $7, %eax\n"
        "jne .Lf9f65a_0009fa61\n"
        /* } scope */
        "movl -0xcc(%ebp), %eax\n" /* line 392 | mstate */
        "movl %ecx, 8(%eax)\n"
        "movl 0x30(%esi), %eax\n" /* line 393 */
        "movl -0xcc(%ebp), %edx\n" /* mstate */
        "movl %eax, 0xc(%edx)\n"
        /* { scope 3 */
        "leal (%ecx, %ecx, 2), %eax\n" /* line 213 */
        "movl s_mantleTrans(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "movl %eax, -0xd0(%ebp)\n" /* time */
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        "movl -0xcc(%ebp), %eax\n" /* line 227 | mstate */
        "testb $1, 0xc(%eax)\n"
        "jne .Lf9f65a_0009fb75\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf9f65a_0009faca:\n"
        "addl -0xd0(%ebp), %eax\n" /* line 395 | time */
        "movl %eax, -0xd4(%ebp)\n" /* mantleTime */
        "leal -0x24(%ebp), %ecx\n" /* line 398 | mins */
        "movl %eax, %edx\n"
        "movl -0xcc(%ebp), %eax\n" /* mstate */
        "calll Mantle_GetAnimDelta\n"
        "leal 0x14(%ebx), %eax\n" /* line 399 | diff */
        /* { scope 3 */
        "movss 0x24(%esi), %xmm0\n" /* line 248 */
        "subss -0x24(%ebp), %xmm0\n" /* mins */
        "movss %xmm0, 0x14(%ebx)\n"
        "movss 0x28(%esi), %xmm0\n" /* line 249 */
        "subss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 0x2c(%esi), %xmm0\n" /* line 250 */
        "subss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "orl $4, 0xc(%ebx)\n" /* line 402 */
        "orl $0x4000, 0xa0(%ebx)\n" /* line 406 */
        "leal 0xe8(%edi), %edx\n" /* line 407 | to */
        /* { scope 3 */
        "movl 0x24(%esi), %eax\n" /* line 199 */
        "movl %eax, 0xe8(%edi)\n"
        "movl 0x28(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0x2c(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl -0xd4(%ebp), %eax\n" /* line 408 | mantleTime */
        "movl %eax, 0xf4(%edi)\n"
        "movb $1, 0xe5(%edi)\n" /* line 409 */
        ".Lf9f65a_0009fb52:\n"
        "movl $1, %eax\n"
        "jmp .Lf9f65a_0009f84c\n"
        /* } scope */
        ".Lf9f65a_0009fb5c:\n"
        "movl $0x21e24c, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9f65a_0009f9b7\n"
        /* { scope 2: time, mstate */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf9f65a_0009fb75:\n"
        "movl 8(%eax), %eax\n" /* line 231 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x30aaa4(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_mantleAnims, %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "jmp .Lf9f65a_0009faca\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf9f65a_0009fb98:\n"
        "leal 0x578(%ebx), %eax\n" /* line 502 | ps */
        "movl %eax, -0xec(%ebp)\n"
        "leal 0x56c(%ebx), %edx\n" /* ps */
        "movl %edx, -0xe8(%ebp)\n"
        "movl 0x3c(%edi), %eax\n" /* pm */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "movl -0xd8(%ebp), %eax\n" /* to */
        "movl %eax, 0x14(%esp)\n"
        "movl -0xec(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl -0xe8(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0xd8(%ebp), %edx\n" /* to */
        "movl %edx, 8(%esp)\n"
        "leal -0xc0(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pm */
        "calll PM_trace\n"
        "cmpb $0, -0x9d(%ebp)\n" /* line 503 */
        "je .Lf9f65a_0009fc08\n"
        "orl $2, 0x30(%esi)\n" /* line 504 | mresults */
        ".Lf9f65a_0009fc08:\n"
        "movl 0x3c(%edi), %eax\n" /* line 506 | pm */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "movl -0xf4(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl -0xec(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0xe8(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl -0xf4(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0xc0(%ebp), %edx\n" /* trace */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pm */
        "calll PM_trace\n"
        "cmpb $0, -0x9d(%ebp)\n" /* line 507 */
        "jne .Lf9f65a_0009fa0d\n"
        "orl $4, 0x30(%esi)\n" /* line 508 | mresults */
        "jmp .Lf9f65a_0009fa0d\n"
        /* { scope 2: time, mstate */
        ".Lf9f65a_0009fc69:\n"
        "leal 0x56c(%ecx), %edx\n" /* line 201 */
        /* { scope 3 */
        "movl 0x56c(%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n" /* mins */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        /* } scope */
        "movl 0x578(%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x78(%ebp)\n" /* maxs */
        "movl 0x57c(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x74(%ebp)\n"
        "movl $0x42480000, -0x70(%ebp)\n" /* line 356 */
        "movl 0x18(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x60(%ebp)\n" /* start */
        "movl 0x1c(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0x20(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "movss 0x2ed800, %xmm0\n" /* line 288 | 31.0f */
        "movss (%esi), %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "addss -0x60(%ebp), %xmm2\n" /* start */
        "movss %xmm2, -0x60(%ebp)\n" /* start */
        "movl -0xe0(%ebp), %eax\n" /* line 289 */
        "movss (%eax), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "addss -0x5c(%ebp), %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n"
        "movl -0xdc(%ebp), %edx\n" /* line 290 */
        "mulss (%edx), %xmm0\n"
        "addss -0x58(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movss %xmm2, -0x6c(%ebp)\n" /* line 199 | end */
        "movss %xmm1, -0x68(%ebp)\n" /* line 200 */
        "subss 0x2ed6c8, %xmm0\n" /* line 363 | 18.0f */
        "movss %xmm0, -0x64(%ebp)\n"
        "movl 0x3c(%edi), %eax\n" /* line 365 */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xcc(%ecx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* end */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* maxs */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* mins */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* start */
        "movl %eax, 8(%esp)\n"
        "leal -0x9c(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_trace\n"
        "cmpb $0, -0x79(%ebp)\n" /* line 367 */
        "jne .Lf9f65a_0009fda6\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss -0x9c(%ebp), %xmm0\n" /* trace */
        "ja .Lf9f65a_0009fda6\n"
        "leal 0x24(%esi), %eax\n" /* line 374 */
        "movl %eax, -0xf4(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 199 | end */
        "movl %eax, 0x24(%esi)\n"
        "movl -0x68(%ebp), %eax\n" /* line 200 */
        "movl -0xf4(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%edx)\n"
        "movss -0x58(%ebp), %xmm1\n" /* line 375 */
        "subss %xmm1, %xmm0\n"
        "mulss -0x9c(%ebp), %xmm0\n" /* trace */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c(%esi)\n"
        "jmp .Lf9f65a_0009fa00\n"
        ".Lf9f65a_0009fda6:\n"
        "andl $0xfffffffe, 0x30(%esi)\n" /* line 369 */
        "leal 0x24(%esi), %edx\n" /* line 370 */
        "movl %edx, -0xf4(%ebp)\n"
        "movl 0x18(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x24(%esi)\n"
        "movl 0x1c(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0x20(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf9f65a_0009fa00\n"
    );
}

/* line 669 */
__attribute__((naked))
void Mantle_Check(pmove_t *pm, pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 669 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1: mins, maxs, start, end, ... */
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf9fdca_0009fe99\n"
        ".Lf9fdca_0009fde5:\n"
        "movl mantle_enable, %eax\n" /* line 678 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf9fdca_0009fe06\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf9fdca_0009fe7a\n"
        /* } scope */
        ".Lf9fdca_0009fdfb:\n"
        "addl $0x11c, %esp\n" /* line 738 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: mins, maxs, start, end, ... */
        ".Lf9fdca_0009fe06:\n"
        "movl 8(%ebp), %eax\n" /* line 684 | pm */
        "movl (%eax), %esi\n" /* ps */
        "andl $0xfffffff7, 0x5c8(%esi)\n" /* line 861 | ps */
        "cmpl $5, 4(%esi)\n" /* line 689 | ps */
        "jg .Lf9fdca_0009fe50\n"
        "testb $4, 0xc(%esi)\n" /* line 695 | ps */
        "jne .Lf9fdca_0009feb2\n"
        "testb $0xc, 0xa0(%esi)\n" /* line 701 | ps */
        "je .Lf9fdca_0009feda\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9fdca_0009fdfb\n"
        "movl $0x21e2e0, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9fdca_0009fdfb\n"
        ".Lf9fdca_0009fe50:\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9fdca_0009fdfb\n"
        "movl $0x21e298, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 738 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: mins, maxs, start, end, ... */
        ".Lf9fdca_0009fe7a:\n"
        "movl $0x21e27c, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 738 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: mins, maxs, start, end, ... */
        ".Lf9fdca_0009fe99:\n"
        "movl $0x21e260, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9fdca_0009fde5\n"
        ".Lf9fdca_0009feb2:\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9fdca_0009fdfb\n"
        "movl $0x21e2b8, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9fdca_0009fdfb\n"
        ".Lf9fdca_0009feda:\n"
        "movl 0xd8(%esi), %eax\n" /* line 707 | ps */
        "subl $0x11, %eax\n"
        "cmpl $5, %eax\n"
        "ja .Lf9fdca_0009ff10\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9fdca_0009fdfb\n"
        "movl $0x21e304, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9fdca_0009fdfb\n"
        /* { scope 2 */
        ".Lf9fdca_0009ff10:\n"
        "movl 8(%ebp), %edx\n" /* line 600 | pm */
        "movl (%edx), %ebx\n" /* ps */
        "movss 0x578(%ebx), %xmm1\n" /* line 603 | ps */
        "movl 0x574(%ebx), %eax\n" /* line 606 | ps, z */
        "movl mantle_check_radius, %edx\n"
        "movss 8(%edx), %xmm0\n" /* y */
        "xorps 0x2f1be0, %xmm0\n" /* y */
        /* { scope 3 */
        "movss %xmm0, -0x54(%ebp)\n" /* line 191 | mins */
        "movss %xmm0, -0x50(%ebp)\n" /* line 192 */
        "movl %eax, -0x4c(%ebp)\n" /* line 193 */
        /* } scope */
        "movl 0x580(%ebx), %ecx\n" /* line 607 | ps, z */
        "movl 8(%edx), %eax\n" /* y */
        /* { scope 3 */
        "movl %eax, -0x60(%ebp)\n" /* line 191 | maxs */
        "movl %eax, -0x5c(%ebp)\n" /* line 192 */
        "movl %ecx, -0x58(%ebp)\n" /* line 193 */
        /* } scope */
        "subss 8(%edx), %xmm1\n" /* line 612 */
        "movl mantle_check_range, %eax\n" /* line 613 */
        "movaps %xmm1, %xmm4\n"
        "addss 8(%eax), %xmm4\n"
        "movl 0xc(%ebp), %edx\n" /* line 199 | pml */
        "movl (%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* traceDir */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 616 */
        "leal -0x24(%ebp), %eax\n" /* line 617 | traceDir */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0xe8(%ebp)\n"
        "movss %xmm4, -0xf8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0xe8(%ebp), %xmm1\n" /* line 619 | scale */
        "xorps 0x2f1be0, %xmm1\n" /* scale */
        /* { scope 3 */
        "movss -0x24(%ebp), %xmm3\n" /* line 288 | traceDir */
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 0x14(%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* start */
        "movss -0x20(%ebp), %xmm2\n" /* line 289 */
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss 0x18(%ebx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 290 */
        "mulss %xmm0, %xmm1\n"
        "addss 0x1c(%ebx), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* } scope */
        /* { scope 3 */
        "movss -0xf8(%ebp), %xmm4\n" /* line 288 */
        "mulss %xmm4, %xmm3\n"
        "addss 0x14(%ebx), %xmm3\n"
        "movss %xmm3, -0x3c(%ebp)\n" /* end */
        "mulss %xmm4, %xmm2\n" /* line 289 */
        "addss 0x18(%ebx), %xmm2\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "mulss %xmm0, %xmm4\n" /* line 290 */
        "addss 0x1c(%ebx), %xmm4\n"
        "movss %xmm4, -0x34(%ebp)\n"
        /* } scope */
        "movl $0x1000000, 0x1c(%esp)\n" /* line 623 */
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* end */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* maxs */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* mins */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* start */
        "movl %eax, 8(%esp)\n"
        "leal -0x84(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pm */
        "movl %eax, (%esp)\n"
        "calll PM_trace\n"
        "cmpw $0, -0x62(%ebp)\n" /* line 625 */
        "je .Lf9fdca_000a008a\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9fdca_0009fdfb\n"
        "movl $0x21e32c, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9fdca_0009fdfb\n"
        ".Lf9fdca_000a008a:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 631 | 1.0f */
        "ucomiss -0x84(%ebp), %xmm0\n" /* trace */
        "jne .Lf9fdca_000a00c5\n"
        "jp .Lf9fdca_000a00c5\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9fdca_0009fdfb\n"
        "movl $0x21e358, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9fdca_0009fdfb\n"
        ".Lf9fdca_000a00c5:\n"
        "testl $0x6000000, -0x74(%ebp)\n" /* line 637 */
        "jne .Lf9fdca_000a00f6\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9fdca_0009fdfb\n"
        "movl $0x21e380, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9fdca_0009fdfb\n"
        ".Lf9fdca_000a00f6:\n"
        "movss 0x2f1be0, %xmm1\n" /* line 216 */
        "movss -0x80(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* mantleDir */
        "movss -0x7c(%ebp), %xmm0\n" /* line 217 */
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movl $0, -0x40(%ebp)\n" /* line 645 */
        "leal -0x48(%ebp), %eax\n" /* line 647 | mantleDir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0xcc(%ebp)\n" /* len */
        "movss -0xcc(%ebp), %xmm0\n" /* line 648 | len */
        "ucomiss 0x2ed5f0, %xmm0\n" /* 9.999999747378752e-05f */
        "jae .Lf9fdca_000a016b\n"
        "jp .Lf9fdca_000a016b\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9fdca_0009fdfb\n"
        "movl $0x21e3c8, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9fdca_0009fdfb\n"
        ".Lf9fdca_000a016b:\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 656 | traceDir */
        "mulss -0x48(%ebp), %xmm1\n" /* mantleDir */
        "movss -0x20(%ebp), %xmm0\n"
        "mulss -0x44(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss -0x40(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, (%esp)\n"
        "calll acos\n"
        "fstpl -0x100(%ebp)\n"
        "movsd -0x100(%ebp), %xmm0\n"
        "mulsd 0x307c40, %xmm0\n" /* 57.29577951308232 */
        "movl mantle_check_angle, %eax\n"
        "cvtss2sd 8(%eax), %xmm1\n"
        "ucomisd %xmm1, %xmm0\n"
        "jbe .Lf9fdca_000a01ed\n"
        "movl mantle_debug, %eax\n" /* line 197 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9fdca_0009fdfb\n"
        "movl $0x21e3fc, 4(%esp)\n" /* line 200 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf9fdca_0009fdfb\n"
        /* } scope */
        ".Lf9fdca_000a01ed:\n"
        "leal -0xbc(%ebp), %ebx\n" /* line 716 | mresults, ps */
        "cld\n"
        "movl $0xe, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* ps */
        "rep stosl %eax, %es:(%edi)\n"
        "movl -0x48(%ebp), %eax\n" /* line 199 | mantleDir */
        "movl %eax, -0xbc(%ebp)\n" /* mresults */
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0xb8(%ebp)\n"
        "movl -0x40(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0xb4(%ebp)\n"
        "leal 0x14(%esi), %edx\n"
        /* { scope 2 */
        "movl 0x14(%esi), %eax\n" /* line 199 */
        "movl %eax, -0xb0(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0xac(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xa8(%ebp)\n"
        /* } scope */
        "testb $4, -0x71(%ebp)\n" /* line 724 */
        "je .Lf9fdca_000a0245\n"
        "orl $1, -0x8c(%ebp)\n" /* line 725 */
        ".Lf9fdca_000a0245:\n"
        "movss 0x2ed7c8, %xmm0\n" /* line 728 | 60.0f */
        "movl %ebx, %ecx\n" /* ps */
        "movl 0xc(%ebp), %edx\n" /* pml */
        "movl 8(%ebp), %eax\n" /* pm */
        "calll Mantle_CheckLedge\n"
        "testb %al, %al\n"
        "jne .Lf9fdca_0009fdfb\n"
        "movss 0x2ed73c, %xmm0\n" /* line 732 | 40.0f */
        "movl %ebx, %ecx\n" /* ps */
        "movl 0xc(%ebp), %edx\n" /* pml */
        "movl 8(%ebp), %eax\n" /* pm */
        "calll Mantle_CheckLedge\n"
        "testb %al, %al\n"
        "jne .Lf9fdca_0009fdfb\n"
        "movss 0x2ed694, %xmm0\n" /* line 736 | 20.0f */
        "movl %ebx, %ecx\n" /* ps */
        "movl 0xc(%ebp), %edx\n" /* pml */
        "movl 8(%ebp), %eax\n" /* pm */
        "calll Mantle_CheckLedge\n"
        "jmp .Lf9fdca_0009fdfb\n"
    );
}

