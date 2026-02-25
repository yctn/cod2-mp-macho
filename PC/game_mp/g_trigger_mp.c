/* ASM dump from: g_trigger_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_trigger_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

void G_Trigger(gentity_t *self, gentity_t *other);
void hurt_use(gentity_t *self, gentity_t *other, gentity_t *activator);
void SP_trigger_lookat(gentity_t *self);
void SP_trigger_hurt(gentity_t *self);
void SP_trigger_damage(gentity_t *pSelf);
void SP_trigger_multiple(gentity_t *ent);
void SP_trigger_radius(gentity_t *ent);
void SP_trigger_disk(gentity_t *ent);
void SP_trigger_once(gentity_t *ent);
void Touch_Multi(gentity_t *self, gentity_t *other, qboolean bTouched);
void hurt_touch(gentity_t *self, gentity_t *other, qboolean bTouched);
void Activate_trigger_damage(gentity_t *pEnt, gentity_t *pOther, int iDamage, int iMOD);
void G_GrenadeTouchTriggerDamage(gentity_t *pActivator, vec_t *vStart, vec_t *vEnd, int iDamage, int iMOD);
void G_CheckHitTriggerDamage(gentity_t *pActivator, vec_t *vStart, vec_t *vEnd, int iDamage, int iMOD);
void Die_trigger_damage(gentity_t *pSelf, gentity_t *pInflictor, gentity_t *pAttacker, int iDamage, int iMod, int iWeapon, const vec_t *vDir, const hitLocation_t hitLoc, int timeOffset);
void Pain_trigger_damage(gentity_t *pSelf, gentity_t *pAttacker, int iDamage, const vec_t *vPoint, const int iMod, const vec_t *vDir, const hitLocation_t hitLoc);
void Use_trigger_damage(gentity_t *pEnt, gentity_t *pOther, gentity_t *pActivator);

/* line 3 */
__attribute__((naked))
void G_Trigger(gentity_t *self, gentity_t *other)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* self */
        "movl 0xc(%ebp), %esi\n" /* other */
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 9 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "je .Lf1b529c_001b5302\n"
        "movl 0x195f6a0, %ebx\n" /* line 11 */
        "movl 0x35e8(%ebx), %eax\n"
        "cmpl $0x100, %eax\n"
        "je .Lf1b529c_001b530a\n"
        "leal (%eax, %eax, 2), %edx\n" /* line 17 */
        "leal 0x1de0(%ebx, %edx, 4), %edx\n"
        "leal 8(%edx), %ecx\n"
        "addl $1, %eax\n" /* line 18 */
        "movl %eax, 0x35e8(%ebx)\n"
        "movl (%edi), %eax\n" /* line 20 | self */
        "movw %ax, 8(%edx)\n"
        "movl (%esi), %eax\n" /* line 21 | other */
        "movw %ax, 2(%ecx)\n"
        "movl 0x228(%edi), %eax\n" /* line 22 | self */
        "movl %eax, 4(%ecx)\n"
        "movl 0x228(%esi), %eax\n" /* line 23 | other */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lf1b529c_001b5302:\n"
        "addl $0x1c, %esp\n" /* line 24 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b529c_001b530a:\n"
        "movl %esi, (%esp)\n" /* line 13 | other */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 14 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* self */
        "calll Scr_Notify\n"
        "jmp .Lf1b529c_001b5302\n"
    );
}

/* line 235 */
__attribute__((naked))
void hurt_use(gentity_t *self, gentity_t *other, gentity_t *activator)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 235 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* self */
        "cmpb $3, 0x166(%edx)\n" /* line 239 */
        "setne %al\n"
        "addb $2, %al\n"
        "movb %al, 0x166(%edx)\n"
        "popl %ebp\n" /* line 246 */
        "retl\n"
    );
}

/* line 596 */
__attribute__((naked))
void SP_trigger_lookat(gentity_t *self)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 596 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* self */
        "movl %ebx, (%esp)\n" /* line 598 | self */
        "calll SV_SetBrushModel\n"
        "movl $0x20000000, 0x11c(%ebx)\n" /* line 600 | self */
        "movb $1, 0xf2(%ebx)\n" /* line 601 | self */
        "orl $1, 8(%ebx)\n" /* line 602 | self */
        "movl %ebx, 8(%ebp)\n" /* line 604 | self */
        "addl $0x14, %esp\n" /* line 605 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SV_LinkEntity\n" /* line 604 */
    );
}

/* line 254 */
__attribute__((naked))
void SP_trigger_hurt(gentity_t *self)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 254 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* self */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 29 */
        "calll SV_SetBrushModel\n"
        "movl $0x405c0008, 0x11c(%ebx)\n" /* line 31 */
        "movb $1, 0xf2(%ebx)\n" /* line 32 */
        "orl $1, 8(%ebx)\n" /* line 33 */
        "leal -0xc(%ebp), %eax\n" /* line 260 | sound */
        "movl %eax, 8(%esp)\n"
        "movl $0x2b52ec, 4(%esp)\n" /* "world_hurt_me" */
        "movl $0x2af1bc, (%esp)\n" /* "sound" */
        "calll G_SpawnString\n"
        "movl 0x19c(%ebx), %eax\n" /* line 262 | self */
        "testl %eax, %eax\n"
        "jne .Lf1b5384_001b53da\n"
        "movl $5, 0x19c(%ebx)\n" /* line 264 | self */
        ".Lf1b5384_001b53da:\n"
        "movl $0x405c0008, 0x11c(%ebx)\n" /* line 267 | self */
        "movl 0x170(%ebx), %eax\n" /* line 269 | self */
        "andl $1, %eax\n"
        "negb %al\n" /* line 271 */
        "addb $3, %al\n"
        "movb %al, 0x166(%ebx)\n" /* self */
        /* } scope */
        "addl $0x24, %esp\n" /* line 277 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 464 */
__attribute__((naked))
void SP_trigger_damage(gentity_t *pSelf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 464 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        "leal 0x1ac(%ebx), %eax\n" /* line 466 | pSelf */
        "movl %eax, 8(%esp)\n"
        "movl $0x21952c, 4(%esp)\n" /* "0" */
        "movl $0x2b52fc, (%esp)\n" /* "accumulate" */
        "calll G_SpawnInt\n"
        "leal 0x1a8(%ebx), %eax\n" /* line 467 | pSelf */
        "movl %eax, 8(%esp)\n"
        "movl $0x21952c, 4(%esp)\n" /* "0" */
        "movl $0x2b5308, (%esp)\n" /* "threshold" */
        "calll G_SpawnInt\n"
        "movl $0x7d00, 0x194(%ebx)\n" /* line 469 | pSelf */
        "movb $1, 0x161(%ebx)\n" /* line 470 | pSelf */
        "movb $4, 0x166(%ebx)\n" /* line 472 | pSelf */
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 47 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1b53fe_001b5495\n"
        /* } scope */
        ".Lf1b53fe_001b546a:\n"
        "movl %ebx, (%esp)\n" /* line 29 */
        "calll SV_SetBrushModel\n"
        "movl $0x405c0008, 0x11c(%ebx)\n" /* line 31 */
        "movb $1, 0xf2(%ebx)\n" /* line 32 */
        "orl $1, 8(%ebx)\n" /* line 33 */
        "movl %ebx, (%esp)\n" /* line 476 | pSelf */
        "calll SV_LinkEntity\n"
        "addl $0x24, %esp\n" /* line 477 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b53fe_001b5495:\n"
        "leal -0xc(%ebp), %eax\n" /* line 50 | wait */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x219070, (%esp)\n" /* "wait" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "je .Lf1b53fe_001b546a\n"
        "pxor %xmm0, %xmm0\n" /* line 53 */
        "ucomiss -0xc(%ebp), %xmm0\n" /* wait */
        "jb .Lf1b53fe_001b546a\n"
        "orl $0x200, 0x170(%ebx)\n" /* line 54 */
        "jmp .Lf1b53fe_001b546a\n"
    );
}

/* line 96 */
__attribute__((naked))
void SP_trigger_multiple(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 96 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movb $1, 0x166(%ebx)\n" /* line 98 | ent */
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 47 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1b54ca_001b5552\n"
        /* } scope */
        ".Lf1b54ca_001b54e9:\n"
        "movl %ebx, (%esp)\n" /* line 29 */
        "calll SV_SetBrushModel\n"
        "movb $1, 0xf2(%ebx)\n" /* line 32 */
        "orl $1, 8(%ebx)\n" /* line 33 */
        "movl $0, 0x11c(%ebx)\n" /* line 62 */
        "movl 0x170(%ebx), %eax\n" /* line 64 */
        "testb $8, %al\n"
        "jne .Lf1b54ca_001b551a\n"
        "movl $0x40000000, 0x11c(%ebx)\n" /* line 65 */
        ".Lf1b54ca_001b551a:\n"
        "testb $1, %al\n" /* line 66 */
        "je .Lf1b54ca_001b5528\n"
        "orl $0x40000, 0x11c(%ebx)\n" /* line 67 */
        ".Lf1b54ca_001b5528:\n"
        "testb $2, %al\n" /* line 68 */
        "je .Lf1b54ca_001b5536\n"
        "orl $0x80000, 0x11c(%ebx)\n" /* line 69 */
        ".Lf1b54ca_001b5536:\n"
        "testb $4, %al\n" /* line 70 */
        "je .Lf1b54ca_001b5544\n"
        "orl $0x100000, 0x11c(%ebx)\n" /* line 71 */
        ".Lf1b54ca_001b5544:\n"
        "movl %ebx, (%esp)\n" /* line 102 | ent */
        "calll SV_LinkEntity\n"
        "addl $0x24, %esp\n" /* line 103 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b54ca_001b5552:\n"
        "leal -0xc(%ebp), %eax\n" /* line 50 | wait */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x219070, (%esp)\n" /* "wait" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "je .Lf1b54ca_001b54e9\n"
        "pxor %xmm0, %xmm0\n" /* line 53 */
        "ucomiss -0xc(%ebp), %xmm0\n" /* wait */
        "jb .Lf1b54ca_001b54e9\n"
        "orl $0x10, 0x170(%ebx)\n" /* line 54 */
        "jmp .Lf1b54ca_001b54e9\n"
    );
}

/* line 114 */
__attribute__((naked))
void SP_trigger_radius(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 114 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1: wait */
        "movl 0x195f6a0, %eax\n" /* line 119 */
        "cmpb $0, 0x1348(%eax)\n"
        "je .Lf1b5590_001b56ad\n"
        "leal -0xc(%ebp), %eax\n" /* line 121 | radius */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x21a580, (%esp)\n" /* "radius" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "je .Lf1b5590_001b5723\n"
        "leal -0x10(%ebp), %eax\n" /* line 123 | height */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x21a588, (%esp)\n" /* "height" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "je .Lf1b5590_001b578c\n"
        ".Lf1b5590_001b55f2:\n"
        "movb $1, 0x166(%ebx)\n" /* line 134 | ent */
        "movl -0xc(%ebp), %edx\n" /* line 136 | radius */
        "movl %edx, -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "xorps 0x303200, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x104(%ebx)\n" /* ent */
        "movl %eax, 0x108(%ebx)\n" /* line 137 | ent */
        "movl $0, 0x10c(%ebx)\n" /* line 138 | ent */
        "movl %edx, 0x110(%ebx)\n" /* line 140 | ent */
        "movl %edx, 0x114(%ebx)\n" /* line 141 | ent */
        "movl -0x10(%ebp), %eax\n" /* line 142 | height */
        "movl %eax, 0x118(%ebx)\n" /* ent */
        "movb $0x21, 0xf2(%ebx)\n" /* line 144 | ent */
        /* { scope 2 */
        "movl 0x195f6a0, %eax\n" /* line 47 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1b5590_001b56de\n"
        ".Lf1b5590_001b5657:\n"
        "movl 0x170(%ebx), %eax\n"
        /* } scope */
        ".Lf1b5590_001b565d:\n"
        "movl $0, 0x11c(%ebx)\n" /* line 62 */
        "testb $8, %al\n" /* line 64 */
        "jne .Lf1b5590_001b5675\n"
        "movl $0x40000000, 0x11c(%ebx)\n" /* line 65 */
        ".Lf1b5590_001b5675:\n"
        "testb $1, %al\n" /* line 66 */
        "je .Lf1b5590_001b5683\n"
        "orl $0x40000, 0x11c(%ebx)\n" /* line 67 */
        ".Lf1b5590_001b5683:\n"
        "testb $2, %al\n" /* line 68 */
        "je .Lf1b5590_001b5691\n"
        "orl $0x80000, 0x11c(%ebx)\n" /* line 69 */
        ".Lf1b5590_001b5691:\n"
        "testb $4, %al\n" /* line 70 */
        "je .Lf1b5590_001b569f\n"
        "orl $0x100000, 0x11c(%ebx)\n" /* line 71 */
        ".Lf1b5590_001b569f:\n"
        "movl %ebx, (%esp)\n" /* line 148 | ent */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0x44, %esp\n" /* line 149 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: wait */
        ".Lf1b5590_001b56ad:\n"
        "calll Scr_GetNumParam\n" /* line 128 */
        "cmpl $4, %eax\n"
        "jbe .Lf1b5590_001b57d7\n"
        "movl $3, (%esp)\n" /* line 130 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* radius */
        "movl $4, (%esp)\n" /* line 131 */
        "calll Scr_GetFloat\n"
        "fstps -0x10(%ebp)\n" /* height */
        "jmp .Lf1b5590_001b55f2\n"
        /* { scope 2 */
        ".Lf1b5590_001b56de:\n"
        "leal -0x14(%ebp), %eax\n" /* line 50 | wait */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x219070, (%esp)\n" /* "wait" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "je .Lf1b5590_001b5657\n"
        "pxor %xmm0, %xmm0\n" /* line 53 */
        "ucomiss -0x14(%ebp), %xmm0\n" /* wait */
        "jb .Lf1b5590_001b5657\n"
        "movl 0x170(%ebx), %eax\n" /* line 54 */
        "orl $0x10, %eax\n"
        "movl %eax, 0x170(%ebx)\n"
        "jmp .Lf1b5590_001b565d\n"
        /* } scope */
        ".Lf1b5590_001b5723:\n"
        "cvtss2sd 0x140(%ebx), %xmm0\n" /* line 122 | ent */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0x13c(%ebx), %xmm0\n" /* ent */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd 0x138(%ebx), %xmm0\n" /* ent */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x2b5314, (%esp)\n" /* "radius not specified for trigger_radius at (%g %g %g)" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "leal -0x10(%ebp), %eax\n" /* line 123 | height */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x21a588, (%esp)\n" /* "height" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "jne .Lf1b5590_001b55f2\n"
        ".Lf1b5590_001b578c:\n"
        "cvtss2sd 0x140(%ebx), %xmm0\n" /* line 124 | ent */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0x13c(%ebx), %xmm0\n" /* ent */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd 0x138(%ebx), %xmm0\n" /* ent */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x2b534c, (%esp)\n" /* "height not specified for trigger_radius at (%g %g %g)" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1b5590_001b55f2\n"
        ".Lf1b5590_001b57d7:\n"
        "movl $0x2b5384, (%esp)\n" /* line 129 */
        "calll Scr_Error\n"
        "movl $3, (%esp)\n" /* line 130 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* radius */
        "movl $4, (%esp)\n" /* line 131 */
        "calll Scr_GetFloat\n"
        "fstps -0x10(%ebp)\n" /* height */
        "jmp .Lf1b5590_001b55f2\n"
    );
}

/* line 160 */
__attribute__((naked))
void SP_trigger_disk(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 160 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1: wait */
        "leal -0xc(%ebp), %eax\n" /* line 164 | radius */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x21a580, (%esp)\n" /* "radius" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "je .Lf1b5806_001b58f9\n"
        ".Lf1b5806_001b5833:\n"
        "movb $1, 0x166(%ebx)\n" /* line 167 | ent */
        "movss 0x2ed78c, %xmm0\n" /* line 169 | 64.0f */
        "addss -0xc(%ebp), %xmm0\n" /* radius */
        "movss %xmm0, -0xc(%ebp)\n" /* radius */
        "movaps %xmm0, %xmm1\n" /* line 171 */
        "xorps 0x303210, %xmm1\n"
        "movss %xmm1, 0x104(%ebx)\n" /* ent */
        "movss %xmm1, 0x108(%ebx)\n" /* line 172 | ent */
        "movl $0xc7c35000, 0x10c(%ebx)\n" /* line 173 | ent */
        "movss %xmm0, 0x110(%ebx)\n" /* line 175 | ent */
        "movss %xmm0, 0x114(%ebx)\n" /* line 176 | ent */
        "movl $0x47c35000, 0x118(%ebx)\n" /* line 177 | ent */
        "movb $0x41, 0xf2(%ebx)\n" /* line 179 | ent */
        /* { scope 2 */
        "movl 0x195f6a0, %eax\n" /* line 47 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1b5806_001b5944\n"
        ".Lf1b5806_001b58a3:\n"
        "movl 0x170(%ebx), %eax\n"
        /* } scope */
        ".Lf1b5806_001b58a9:\n"
        "movl $0, 0x11c(%ebx)\n" /* line 62 */
        "testb $8, %al\n" /* line 64 */
        "jne .Lf1b5806_001b58c1\n"
        "movl $0x40000000, 0x11c(%ebx)\n" /* line 65 */
        ".Lf1b5806_001b58c1:\n"
        "testb $1, %al\n" /* line 66 */
        "je .Lf1b5806_001b58cf\n"
        "orl $0x40000, 0x11c(%ebx)\n" /* line 67 */
        ".Lf1b5806_001b58cf:\n"
        "testb $2, %al\n" /* line 68 */
        "je .Lf1b5806_001b58dd\n"
        "orl $0x80000, 0x11c(%ebx)\n" /* line 69 */
        ".Lf1b5806_001b58dd:\n"
        "testb $4, %al\n" /* line 70 */
        "je .Lf1b5806_001b58eb\n"
        "orl $0x100000, 0x11c(%ebx)\n" /* line 71 */
        ".Lf1b5806_001b58eb:\n"
        "movl %ebx, (%esp)\n" /* line 183 | ent */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 184 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: wait */
        ".Lf1b5806_001b58f9:\n"
        "cvtss2sd 0x140(%ebx), %xmm0\n" /* line 165 | ent */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0x13c(%ebx), %xmm0\n" /* ent */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd 0x138(%ebx), %xmm0\n" /* ent */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x2b5314, (%esp)\n" /* "radius not specified for trigger_radius at (%g %g %g)" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1b5806_001b5833\n"
        /* { scope 2 */
        ".Lf1b5806_001b5944:\n"
        "leal -0x10(%ebp), %eax\n" /* line 50 | wait */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x219070, (%esp)\n" /* "wait" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "je .Lf1b5806_001b58a3\n"
        "pxor %xmm0, %xmm0\n" /* line 53 */
        "ucomiss -0x10(%ebp), %xmm0\n" /* wait */
        "jb .Lf1b5806_001b58a3\n"
        "movl 0x170(%ebx), %eax\n" /* line 54 */
        "orl $0x10, %eax\n"
        "movl %eax, 0x170(%ebx)\n"
        "jmp .Lf1b5806_001b58a9\n"
    );
}

/* line 282 */
__attribute__((naked))
void SP_trigger_once(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 282 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movb $1, 0x166(%ebx)\n" /* line 284 | ent */
        "orl $0x10, 0x170(%ebx)\n" /* line 285 | ent */
        "movl %ebx, (%esp)\n" /* line 29 */
        "calll SV_SetBrushModel\n"
        "movb $1, 0xf2(%ebx)\n" /* line 32 */
        "orl $1, 8(%ebx)\n" /* line 33 */
        "movl $0, 0x11c(%ebx)\n" /* line 62 */
        "movl 0x170(%ebx), %eax\n" /* line 64 */
        "testb $8, %al\n"
        "jne .Lf1b598a_001b59d3\n"
        "movl $0x40000000, 0x11c(%ebx)\n" /* line 65 */
        ".Lf1b598a_001b59d3:\n"
        "testb $1, %al\n" /* line 66 */
        "je .Lf1b598a_001b59e1\n"
        "orl $0x40000, 0x11c(%ebx)\n" /* line 67 */
        ".Lf1b598a_001b59e1:\n"
        "testb $2, %al\n" /* line 68 */
        "je .Lf1b598a_001b59ef\n"
        "orl $0x80000, 0x11c(%ebx)\n" /* line 69 */
        ".Lf1b598a_001b59ef:\n"
        "testb $4, %al\n" /* line 70 */
        "je .Lf1b598a_001b59fd\n"
        "orl $0x100000, 0x11c(%ebx)\n" /* line 71 */
        ".Lf1b598a_001b59fd:\n"
        "movl %ebx, 8(%ebp)\n" /* line 289 | ent */
        "addl $0x14, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SV_LinkEntity\n" /* line 289 */
    );
}

/* line 89 */
__attribute__((naked))
void Touch_Multi(gentity_t *self, gentity_t *other, qboolean bTouched)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* self */
        "movl 0xc(%ebp), %edi\n" /* other */
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 9 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "je .Lf1b5a0a_001b5a70\n"
        "movl 0x195f6a0, %ebx\n" /* line 11 */
        "movl 0x35e8(%ebx), %eax\n"
        "cmpl $0x100, %eax\n"
        "je .Lf1b5a0a_001b5a90\n"
        "leal (%eax, %eax, 2), %edx\n" /* line 17 */
        "leal 0x1de0(%ebx, %edx, 4), %edx\n"
        "leal 8(%edx), %ecx\n"
        "addl $1, %eax\n" /* line 18 */
        "movl %eax, 0x35e8(%ebx)\n"
        "movl (%esi), %eax\n" /* line 20 */
        "movw %ax, 8(%edx)\n"
        "movl (%edi), %eax\n" /* line 21 */
        "movw %ax, 2(%ecx)\n"
        "movl 0x228(%esi), %eax\n" /* line 22 */
        "movl %eax, 4(%ecx)\n"
        "movl 0x228(%edi), %eax\n" /* line 23 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lf1b5a0a_001b5a70:\n"
        "testb $0x10, 0x170(%esi)\n" /* line 80 */
        "jne .Lf1b5a0a_001b5a81\n"
        "addl $0x1c, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b5a0a_001b5a81:\n"
        "movl %esi, 8(%ebp)\n" /* line 85 | self */
        "addl $0x1c, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp G_FreeEntityDelay\n" /* line 85 */
        /* { scope 1 */
        ".Lf1b5a0a_001b5a90:\n"
        "movl %edi, (%esp)\n" /* line 13 */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 14 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Scr_Notify\n"
        "jmp .Lf1b5a0a_001b5a70\n"
    );
}

/* line 195 */
__attribute__((naked))
void hurt_touch(gentity_t *self, gentity_t *other, qboolean bTouched)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 195 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* self */
        "movl 0xc(%ebp), %edi\n" /* other */
        /* { scope 1 */
        "cmpb $0, 0x161(%edi)\n" /* line 199 | other */
        "je .Lf1b5ab8_001b5ae4\n"
        "movl 0x195f6a0, %ebx\n" /* line 204 */
        "movl 0x1b0(%esi), %eax\n" /* self */
        "cmpl 0x1ec(%ebx), %eax\n"
        "jle .Lf1b5ab8_001b5aec\n"
        /* } scope */
        ".Lf1b5ab8_001b5ae4:\n"
        "addl $0x3c, %esp\n" /* line 232 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b5ab8_001b5aec:\n"
        "movl $1, (%esp)\n" /* line 9 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "je .Lf1b5ab8_001b5b41\n"
        "movl 0x35e8(%ebx), %eax\n" /* line 11 */
        "cmpl $0x100, %eax\n"
        "je .Lf1b5ab8_001b5bee\n"
        "leal (%eax, %eax, 2), %edx\n" /* line 17 */
        "leal 0x1de0(%ebx, %edx, 4), %edx\n"
        "leal 8(%edx), %ecx\n"
        "addl $1, %eax\n" /* line 18 */
        "movl %eax, 0x35e8(%ebx)\n"
        "movl (%esi), %eax\n" /* line 20 */
        "movw %ax, 8(%edx)\n"
        "movl (%edi), %eax\n" /* line 21 */
        "movw %ax, 2(%ecx)\n"
        "movl 0x228(%esi), %eax\n" /* line 22 */
        "movl %eax, 4(%ecx)\n"
        "movl 0x228(%edi), %eax\n" /* line 23 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lf1b5ab8_001b5b41:\n"
        "movl 0x170(%esi), %edx\n" /* line 211 | self */
        "testb $0x10, %dl\n"
        "je .Lf1b5ab8_001b5bd5\n"
        "movl 0x195f6a0, %eax\n" /* line 213 */
        "movl 0x1ec(%eax), %eax\n"
        "addl $0x3e8, %eax\n"
        "movl %eax, 0x1b0(%esi)\n" /* self */
        ".Lf1b5ab8_001b5b66:\n"
        "andl $8, %edx\n" /* line 220 */
        "cmpl $1, %edx\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $0x10, %eax\n"
        "movl $0, 0x24(%esp)\n" /* line 225 */
        "movl $0, 0x20(%esp)\n"
        "movl $0xd, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x19c(%esi), %eax\n" /* self */
        "movl %eax, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* self */
        "movl %esi, 4(%esp)\n" /* self */
        "movl %edi, (%esp)\n" /* other */
        "calll G_Damage\n"
        "testb $0x20, 0x170(%esi)\n" /* line 227 | self */
        "je .Lf1b5ab8_001b5ae4\n"
        "movb $2, 0x166(%esi)\n" /* line 230 | self */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 232 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b5ab8_001b5bd5:\n"
        "movl 0x195f6a0, %eax\n" /* line 217 */
        "movl 0x1ec(%eax), %eax\n"
        "addl $0x32, %eax\n"
        "movl %eax, 0x1b0(%esi)\n" /* self */
        "jmp .Lf1b5ab8_001b5b66\n"
        /* { scope 2 */
        ".Lf1b5ab8_001b5bee:\n"
        "movl %edi, (%esp)\n" /* line 13 */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 14 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Scr_Notify\n"
        "jmp .Lf1b5ab8_001b5b41\n"
    );
}

/* line 388 */
__attribute__((naked))
void Activate_trigger_damage(gentity_t *pEnt, gentity_t *pOther, int iDamage, int iMOD)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 388 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pEnt */
        "movl 0xc(%ebp), %edi\n" /* pOther */
        "movl 0x10(%ebp), %edx\n" /* iDamage */
        "movl 0x14(%ebp), %ecx\n" /* iMOD */
        "movl 0x1a8(%ebx), %eax\n" /* line 391 | pEnt */
        "testl %eax, %eax\n"
        "jle .Lf1b5c18_001b5c3f\n"
        "cmpl %edx, %eax\n"
        "jg .Lf1b5c18_001b5d57\n"
        ".Lf1b5c18_001b5c3f:\n"
        "movl 0x170(%ebx), %edx\n" /* line 321 */
        "testb $1, %dl\n"
        "jne .Lf1b5c18_001b5d5f\n"
        "testb $2, %dl\n" /* line 324 */
        "jne .Lf1b5c18_001b5d6d\n"
        ".Lf1b5c18_001b5c57:\n"
        "testb $4, %dl\n" /* line 327 */
        "jne .Lf1b5c18_001b5d7b\n"
        ".Lf1b5c18_001b5c60:\n"
        "testb $8, %dl\n" /* line 339 */
        "je .Lf1b5c18_001b5c6e\n"
        "cmpl $0xe, %ecx\n" /* line 341 */
        "jbe .Lf1b5c18_001b5d9a\n"
        ".Lf1b5c18_001b5c6e:\n"
        "testb $0x10, %dl\n" /* line 352 */
        "je .Lf1b5c18_001b5c85\n"
        "cmpl $4, %ecx\n" /* line 354 */
        "je .Lf1b5c18_001b5d57\n"
        "cmpl $6, %ecx\n"
        "je .Lf1b5c18_001b5d57\n"
        ".Lf1b5c18_001b5c85:\n"
        "testb $0x20, %dl\n" /* line 362 */
        "jne .Lf1b5c18_001b5d8f\n"
        ".Lf1b5c18_001b5c8e:\n"
        "testb $1, %dh\n" /* line 365 */
        "jne .Lf1b5c18_001b5d3c\n"
        ".Lf1b5c18_001b5c97:\n"
        "movl 0x1ac(%ebx), %esi\n" /* line 399 | pEnt */
        "testl %esi, %esi\n"
        "je .Lf1b5c18_001b5cb4\n"
        "movl $0x7d00, %eax\n"
        "subl 0x194(%ebx), %eax\n" /* pEnt */
        "cmpl %eax, %esi\n"
        "jg .Lf1b5c18_001b5d57\n"
        ".Lf1b5c18_001b5cb4:\n"
        "addl $1, %ecx\n" /* line 403 */
        "je .Lf1b5c18_001b5d1e\n"
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 9 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "je .Lf1b5c18_001b5dad\n"
        "movl 0x195f6a0, %esi\n" /* line 11 */
        "movl 0x35e8(%esi), %eax\n"
        "cmpl $0x100, %eax\n"
        "je .Lf1b5c18_001b5db8\n"
        "leal (%eax, %eax, 2), %edx\n" /* line 17 */
        "leal 0x1de0(%esi, %edx, 4), %edx\n"
        "leal 8(%edx), %ecx\n"
        "addl $1, %eax\n" /* line 18 */
        "movl %eax, 0x35e8(%esi)\n"
        "movl (%ebx), %eax\n" /* line 20 */
        "movw %ax, 8(%edx)\n"
        "movl (%edi), %eax\n" /* line 21 */
        "movw %ax, 2(%ecx)\n"
        "movl 0x228(%ebx), %eax\n" /* line 22 */
        "movl %eax, 4(%ecx)\n"
        "movl 0x228(%edi), %eax\n" /* line 23 */
        "movl %eax, 8(%ecx)\n"
        "movl 0x170(%ebx), %edx\n"
        /* } scope */
        ".Lf1b5c18_001b5d1e:\n"
        "movl $0x7d00, 0x194(%ebx)\n" /* line 407 | pEnt */
        "andb $2, %dh\n" /* line 409 */
        "je .Lf1b5c18_001b5d57\n"
        "movl %ebx, 8(%ebp)\n" /* line 414 | pEnt */
        "addl $0x1c, %esp\n" /* line 415 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp G_FreeEntityDelay\n" /* line 414 */
        ".Lf1b5c18_001b5d3c:\n"
        "cmpl $0xd, %ecx\n" /* line 367 */
        "ja .Lf1b5c18_001b5c97\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x3e01, %eax\n"
        "je .Lf1b5c18_001b5c97\n"
        ".Lf1b5c18_001b5d57:\n"
        "addl $0x1c, %esp\n" /* line 415 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b5c18_001b5d5f:\n"
        "cmpl $1, %ecx\n" /* line 321 */
        "je .Lf1b5c18_001b5d57\n"
        "testb $2, %dl\n" /* line 324 */
        "je .Lf1b5c18_001b5c57\n"
        ".Lf1b5c18_001b5d6d:\n"
        "cmpl $2, %ecx\n"
        "je .Lf1b5c18_001b5d57\n"
        "testb $4, %dl\n" /* line 327 */
        "je .Lf1b5c18_001b5c60\n"
        ".Lf1b5c18_001b5d7b:\n"
        "leal -3(%ecx), %eax\n" /* line 329 */
        "cmpl $3, %eax\n"
        "ja .Lf1b5c18_001b5c60\n"
        "addl $0x1c, %esp\n" /* line 415 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b5c18_001b5d8f:\n"
        "cmpl $7, %ecx\n" /* line 362 */
        "jne .Lf1b5c18_001b5c8e\n"
        "jmp .Lf1b5c18_001b5d57\n"
        ".Lf1b5c18_001b5d9a:\n"
        "movl $1, %eax\n" /* line 341 */
        "shll %cl, %eax\n"
        "testl $0x4078, %eax\n"
        "jne .Lf1b5c18_001b5d57\n"
        "jmp .Lf1b5c18_001b5c6e\n"
        ".Lf1b5c18_001b5dad:\n"
        "movl 0x170(%ebx), %edx\n"
        "jmp .Lf1b5c18_001b5d1e\n"
        /* { scope 1 */
        ".Lf1b5c18_001b5db8:\n"
        "movl %edi, (%esp)\n" /* line 13 */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 14 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_Notify\n"
        "movl 0x170(%ebx), %edx\n"
        "jmp .Lf1b5c18_001b5d1e\n"
    );
}

/* line 540 */
__attribute__((naked))
void G_GrenadeTouchTriggerDamage(gentity_t *pActivator, vec_t *vStart, vec_t *vEnd, int iDamage, int iMOD)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 540 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x104c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 199 | vStart */
        "movl (%eax), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* vMins */
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, -0x20(%ebp)\n"
        "movl 8(%eax), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, -0x30(%ebp)\n" /* line 199 | vMaxs */
        "movl %edx, -0x2c(%ebp)\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n" /* line 201 */
        "leal -0x30(%ebp), %esi\n" /* line 550 | vMaxs, i */
        "movl %esi, 8(%esp)\n" /* i */
        "leal -0x24(%ebp), %ebx\n" /* vMins, pHit */
        "movl %ebx, 4(%esp)\n" /* pHit */
        "movl 0x10(%ebp), %eax\n" /* vEnd */
        "movl %eax, (%esp)\n"
        "calll AddPointToBounds\n"
        "movl $0x400000, 0x10(%esp)\n" /* line 552 */
        "movl $0x400, 0xc(%esp)\n"
        "leal -0x1030(%ebp), %eax\n" /* iTouch */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* i */
        "movl %ebx, (%esp)\n" /* pHit */
        "calll CM_AreaEntities\n"
        "movl %eax, %edi\n" /* iNum */
        "testl %eax, %eax\n" /* line 554 */
        "jle .Lf1b5de8_001b5f41\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf1b5de8_001b5e69\n"
        ".Lf1b5de8_001b5e5e:\n"
        "addl $1, %esi\n" /* i */
        "cmpl %esi, %edi\n" /* i, iNum */
        "je .Lf1b5de8_001b5f41\n"
        ".Lf1b5de8_001b5e69:\n"
        "movl -0x1030(%ebp, %esi, 4), %eax\n" /* line 556 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pHit */
        "subl %eax, %ebx\n" /* pHit */
        "shll $4, %ebx\n" /* pHit */
        "addl 0x195f688, %ebx\n" /* pHit */
        "movzwl 0x168(%ebx), %eax\n" /* line 558 | pHit */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x5a(%edx), %ax\n"
        "jne .Lf1b5de8_001b5e5e\n"
        "testb $0x40, 0x175(%ebx)\n" /* line 561 | pHit */
        "je .Lf1b5de8_001b5e5e\n"
        "movl $0xffffffff, 0x14(%esp)\n" /* line 567 */
        "movl (%ebx), %eax\n" /* pHit */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* vEnd */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x195ed4c, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* vStart */
        "movl %eax, (%esp)\n"
        "calll SV_SightTraceToEntity\n"
        "testl %eax, %eax\n"
        "je .Lf1b5de8_001b5e5e\n"
        "movl 8(%ebp), %edx\n" /* line 575 | pActivator */
        "movl %edx, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl 0x14(%ebp), %eax\n" /* line 576 | iDamage */
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl $2, 8(%esp)\n" /* line 577 */
        "movl 0x195f5bc, %edx\n"
        "movzwl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pHit */
        "calll Scr_Notify\n"
        "movl 0x18(%ebp), %eax\n" /* line 580 | iMOD */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* iDamage */
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pActivator */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pHit */
        "calll Activate_trigger_damage\n"
        "movl 0x1ac(%ebx), %edx\n" /* line 583 | pHit */
        "testl %edx, %edx\n"
        "jne .Lf1b5de8_001b5e5e\n"
        "movl $0x7d00, 0x194(%ebx)\n" /* line 584 | pHit */
        "jmp .Lf1b5de8_001b5e5e\n"
        /* } scope */
        ".Lf1b5de8_001b5f41:\n"
        "addl $0x104c, %esp\n" /* line 586 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 485 */
__attribute__((naked))
void G_CheckHitTriggerDamage(gentity_t *pActivator, vec_t *vStart, vec_t *vEnd, int iDamage, int iMOD)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 485 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x104c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 199 | vStart */
        "movl (%eax), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* vMins */
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, -0x20(%ebp)\n"
        "movl 8(%eax), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, -0x30(%ebp)\n" /* line 199 | vMaxs */
        "movl %edx, -0x2c(%ebp)\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n" /* line 201 */
        "leal -0x30(%ebp), %esi\n" /* line 496 | vMaxs, i */
        "movl %esi, 8(%esp)\n" /* i */
        "leal -0x24(%ebp), %ebx\n" /* vMins, pHit */
        "movl %ebx, 4(%esp)\n" /* pHit */
        "movl 0x10(%ebp), %eax\n" /* vEnd */
        "movl %eax, (%esp)\n"
        "calll AddPointToBounds\n"
        "movl $0x400000, 0x10(%esp)\n" /* line 498 */
        "movl $0x400, 0xc(%esp)\n"
        "leal -0x1030(%ebp), %eax\n" /* iTouch */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* i */
        "movl %ebx, (%esp)\n" /* pHit */
        "calll CM_AreaEntities\n"
        "movl %eax, %edi\n" /* iNum */
        "testl %eax, %eax\n" /* line 500 */
        "jle .Lf1b5f4c_001b60a2\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf1b5f4c_001b5fcd\n"
        ".Lf1b5f4c_001b5fc2:\n"
        "addl $1, %esi\n" /* i */
        "cmpl %esi, %edi\n" /* i, iNum */
        "je .Lf1b5f4c_001b60a2\n"
        ".Lf1b5f4c_001b5fcd:\n"
        "movl -0x1030(%ebp, %esi, 4), %eax\n" /* line 502 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pHit */
        "subl %eax, %ebx\n" /* pHit */
        "shll $4, %ebx\n" /* pHit */
        "addl 0x195f688, %ebx\n" /* pHit */
        "movzwl 0x168(%ebx), %eax\n" /* line 504 | pHit */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x5a(%edx), %ax\n"
        "jne .Lf1b5f4c_001b5fc2\n"
        "movl $0xffffffff, 0x14(%esp)\n" /* line 513 */
        "movl (%ebx), %eax\n" /* pHit */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* vEnd */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x195ed4c, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* vStart */
        "movl %eax, (%esp)\n"
        "calll SV_SightTraceToEntity\n"
        "testl %eax, %eax\n"
        "je .Lf1b5f4c_001b5fc2\n"
        "movl 8(%ebp), %edx\n" /* line 521 | pActivator */
        "movl %edx, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl 0x14(%ebp), %eax\n" /* line 522 | iDamage */
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl $2, 8(%esp)\n" /* line 523 */
        "movl 0x195f5bc, %edx\n"
        "movzwl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pHit */
        "calll Scr_Notify\n"
        "movl 0x18(%ebp), %eax\n" /* line 526 | iMOD */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* iDamage */
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pActivator */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pHit */
        "calll Activate_trigger_damage\n"
        "movl 0x1ac(%ebx), %ecx\n" /* line 529 | pHit */
        "testl %ecx, %ecx\n"
        "jne .Lf1b5f4c_001b5fc2\n"
        "movl $0x7d00, 0x194(%ebx)\n" /* line 530 | pHit */
        "addl $1, %esi\n" /* line 500 | i */
        "cmpl %esi, %edi\n" /* i, iNum */
        "jne .Lf1b5f4c_001b5fcd\n"
        /* } scope */
        ".Lf1b5f4c_001b60a2:\n"
        "addl $0x104c, %esp\n" /* line 532 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 449 */
__attribute__((naked))
void Die_trigger_damage(gentity_t *pSelf, gentity_t *pInflictor, gentity_t *pAttacker, int iDamage, int iMod, int iWeapon, const vec_t *vDir, const hitLocation_t hitLoc, int timeOffset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 449 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        "movl 0x18(%ebp), %eax\n" /* line 451 | iMod */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* iDamage */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* pAttacker */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pSelf */
        "calll Activate_trigger_damage\n"
        "movl 0x1ac(%ebx), %eax\n" /* line 454 | pSelf */
        "testl %eax, %eax\n"
        "jne .Lf1b60ae_001b60e9\n"
        "movl $0x7d00, 0x194(%ebx)\n" /* line 455 | pSelf */
        ".Lf1b60ae_001b60e9:\n"
        "addl $0x14, %esp\n" /* line 456 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 434 */
__attribute__((naked))
void Pain_trigger_damage(gentity_t *pSelf, gentity_t *pAttacker, int iDamage, const vec_t *vPoint, const int iMod, const vec_t *vDir, const hitLocation_t hitLoc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 434 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        "movl 0x18(%ebp), %eax\n" /* line 436 | iMod */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* iDamage */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pAttacker */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pSelf */
        "calll Activate_trigger_damage\n"
        "movl 0x1ac(%ebx), %eax\n" /* line 439 | pSelf */
        "testl %eax, %eax\n"
        "jne .Lf1b60f0_001b612b\n"
        "movl $0x7d00, 0x194(%ebx)\n" /* line 440 | pSelf */
        ".Lf1b60f0_001b612b:\n"
        "addl $0x14, %esp\n" /* line 441 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 423 */
__attribute__((naked))
void Use_trigger_damage(gentity_t *pEnt, gentity_t *pOther, gentity_t *pActivator)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 423 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "movl $0xffffffff, 0xc(%esp)\n" /* line 425 */
        "movl 0x1ac(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* pOther */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Activate_trigger_damage\n"
        "leave\n" /* line 426 */
        "retl\n"
    );
}

