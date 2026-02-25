/* ASM dump from: g_missile_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_missile_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/q_shared.h"
 */

void G_ExplodeMissile(gentity_t *ent);
gentity_t * fire_grenade(gentity_t *self, vec_t *start, vec_t *dir, int grenadeWPID, int time);
gentity_t * fire_rocket(gentity_t *self, vec_t *start, vec_t *dir);
static void G_MissileLandAngles(qboolean bForceAlign);
static qboolean G_BounceMissile(void);
void G_RunMissile(gentity_t *ent);

/* line 274 */
__attribute__((naked))
void G_ExplodeMissile(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 274 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1 */
        "movl 0xc8(%esi), %eax\n" /* line 287 | ent */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edi\n" /* weapDef */
        "cmpl $2, 0x84(%eax)\n" /* line 291 */
        "je .Lf1c6f2c_001c70ce\n"
        ".Lf1c6f2c_001c6f58:\n"
        "leal -0x24(%ebp), %ebx\n" /* line 297 | origin */
        "movl %ebx, 8(%esp)\n"
        "movl 0x195f6a0, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%esi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "cvttss2si -0x24(%ebp), %eax\n" /* line 298 | origin */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* origin */
        "cvttss2si -0x20(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* line 299 */
        "movl %esi, (%esp)\n" /* ent */
        "calll G_SetOrigin\n"
        "movl $0, 4(%esi)\n" /* line 307 | ent */
        "orl $0x20, 8(%esi)\n" /* line 308 | ent */
        "orl $0x800, 0x174(%esi)\n" /* line 309 | ent */
        "orb $8, 0xf2(%esi)\n" /* line 310 | ent */
        "leal 0x138(%esi), %eax\n" /* line 312 | ent */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* end */
        "movl -0x5c(%ebp), %edx\n" /* line 200 */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 201 */
        "subss 0x2ed6a8, %xmm0\n" /* line 313 | 16.0f */
        "movss %xmm0, -0x28(%ebp)\n"
        "movl $0x811, 0x18(%esp)\n" /* line 314 */
        "movl (%esi), %eax\n" /* ent */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* end */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "cmpl $2, 0x390(%edi)\n" /* line 316 | weapDef */
        "je .Lf1c6f2c_001c7152\n"
        "leal -0x50(%ebp), %eax\n" /* line 319 */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xbc, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_AddEvent\n"
        ".Lf1c6f2c_001c7058:\n"
        "movl $0x20, 8(%esp)\n" /* line 322 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_PointContents\n"
        "testl %eax, %eax\n" /* line 323 */
        "je .Lf1c6f2c_001c70bb\n"
        "movl $0x14, 0x88(%esi)\n" /* line 324 | ent */
        ".Lf1c6f2c_001c7081:\n"
        "movl 0x394(%edi), %eax\n" /* line 329 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1c6f2c_001c7094\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1c6f2c_001c7179\n"
        ".Lf1c6f2c_001c7094:\n"
        "movl $1, 0x17c(%esi)\n" /* line 340 | ent */
        ".Lf1c6f2c_001c709e:\n"
        "movl 0x37c(%edi), %edx\n" /* line 344 | weapDef */
        "testl %edx, %edx\n"
        "jne .Lf1c6f2c_001c70f0\n"
        ".Lf1c6f2c_001c70a8:\n"
        "movl %esi, (%esp)\n" /* line 350 | ent */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 351 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c6f2c_001c70bb:\n"
        "movl -0x44(%ebp), %eax\n" /* line 326 */
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        "movl %eax, 0x88(%esi)\n" /* ent */
        "jmp .Lf1c6f2c_001c7081\n"
        ".Lf1c6f2c_001c70ce:\n"
        "cmpl $0x3ff, 0x7c(%esi)\n" /* line 291 | ent */
        "jne .Lf1c6f2c_001c6f58\n"
        "movl $0x32, 0x190(%esi)\n" /* line 293 | ent */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 351 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c6f2c_001c70f0:\n"
        "movzbl 0x166(%esi), %eax\n" /* line 347 | ent */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 0x24(%eax), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n" /* ent */
        "cvtsi2ssl 0x378(%edi), %xmm0\n" /* weapDef */
        "movss %xmm0, 0x14(%esp)\n"
        "cvtsi2ssl 0x380(%edi), %xmm0\n" /* weapDef */
        "movss %xmm0, 0x10(%esp)\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x18c(%esi), %eax\n" /* ent */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* ent */
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll G_RadiusDamage\n"
        "jmp .Lf1c6f2c_001c70a8\n"
        ".Lf1c6f2c_001c7152:\n"
        "leal -0x50(%ebp), %eax\n" /* line 317 */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xbf, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_AddEvent\n"
        "jmp .Lf1c6f2c_001c7058\n"
        ".Lf1c6f2c_001c7179:\n"
        "orl $0x10000, 8(%esi)\n" /* line 332 | ent */
        "calll Server_SwitchToValidFxScheduler\n" /* line 333 */
        "movl 0x394(%edi), %eax\n" /* line 334 | weapDef */
        "movl %eax, (%esp)\n"
        "calll FX_RegisterEffect\n"
        "movl 0x195f6a0, %ecx\n" /* line 335 */
        "movl 0x1ec(%ecx), %edx\n"
        "movl %edx, 0x54(%esi)\n" /* ent */
        "movl 0x1ec(%ecx), %ebx\n" /* line 336 */
        "movl %eax, (%esp)\n"
        "calll FX_GetEffectLength\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "cvttss2si %xmm0, %eax\n"
        "addl %eax, %ebx\n"
        "movl %ebx, 0x58(%esi)\n" /* ent */
        "jmp .Lf1c6f2c_001c709e\n"
    );
}

/* line 622 */
__attribute__((naked))
gentity_t * fire_grenade(gentity_t *self, vec_t *start, vec_t *dir, int grenadeWPID, int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 622 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* self */
        "movl 0x18(%ebp), %ebx\n" /* time */
        /* { scope 1 */
        "calll G_Spawn\n" /* line 627 */
        "movl %eax, %edi\n" /* bolt */
        "movl 0x158(%esi), %ecx\n" /* line 630 | self */
        "testl %ecx, %ecx\n"
        "je .Lf1c71ce_001c71f9\n"
        "movl 0x3c(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1c71ce_001c73d4\n"
        ".Lf1c71ce_001c71f9:\n"
        "movl 0x195f6a0, %eax\n" /* line 637 */
        "addl 0x1ec(%eax), %ebx\n" /* weapDef */
        "movl %ebx, 0x190(%edi)\n" /* weapDef, bolt */
        ".Lf1c71ce_001c720a:\n"
        "testl %ecx, %ecx\n" /* line 641 */
        "je .Lf1c71ce_001c7215\n"
        "movl $0, 0x3c(%ecx)\n" /* line 642 */
        ".Lf1c71ce_001c7215:\n"
        "movb $7, 0x166(%edi)\n" /* line 644 | bolt */
        "movl $4, 4(%edi)\n" /* line 645 | bolt */
        "movb $8, 0xf2(%edi)\n" /* line 646 | bolt */
        "movl 0x14(%ebp), %eax\n" /* line 647 | grenadeWPID */
        "movl %eax, 0xc8(%edi)\n" /* bolt */
        "movl (%esi), %eax\n" /* line 648 | self */
        "movl %eax, 0x150(%edi)\n" /* bolt */
        "movl %esi, 0x18c(%edi)\n" /* line 649 | self, bolt */
        "movl 0x14(%ebp), %ecx\n" /* line 651 | grenadeWPID */
        "movl %ecx, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ebx\n" /* weapDef */
        "movl 0x195f5bc, %eax\n" /* line 652 */
        "movzwl 0x1a(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x168(%edi), %eax\n" /* bolt */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 0x1ec(%ebx), %eax\n" /* line 653 | weapDef */
        "movl %eax, 0x19c(%edi)\n" /* bolt */
        "movl $0x1000000, 8(%edi)\n" /* line 654 | bolt */
        "movl $0x2802891, 0x184(%edi)\n" /* line 655 | bolt */
        "movl 0x195f6a0, %ecx\n" /* line 658 */
        "movl 0x1ec(%ecx), %eax\n"
        "addl $0x32, %eax\n"
        "movl %eax, 0x54(%edi)\n" /* bolt */
        "movl $5, 0xc(%edi)\n" /* line 660 | bolt */
        "movl 0x1ec(%ecx), %eax\n" /* line 661 */
        "movl %eax, 0x10(%edi)\n" /* bolt */
        "leal 0x18(%edi), %edx\n" /* line 662 | bolt, to */
        /* { scope 2 */
        "movl 0xc(%ebp), %ebx\n" /* line 199 | start */
        "movl (%ebx), %eax\n"
        "movl %eax, 0x18(%edi)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x24(%edi), %edx\n" /* line 663 | bolt, to */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 199 | dir */
        "movl (%ebx), %eax\n"
        "movl %eax, 0x24(%edi)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "cvttss2si 0x24(%edi), %eax\n" /* line 664 | bolt */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x24(%edi)\n" /* bolt */
        "cvttss2si 0x28(%edi), %eax\n" /* bolt */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x28(%edi)\n" /* bolt */
        "cvttss2si 0x2c(%edi), %eax\n" /* bolt */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x2c(%edi)\n" /* bolt */
        "movl $2, 0x30(%edi)\n" /* line 666 | bolt */
        "movl 0x1ec(%ecx), %eax\n" /* line 667 */
        "movl %eax, 0x34(%edi)\n" /* bolt */
        "leal 0x3c(%edi), %eax\n" /* line 668 | bolt */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* weapDef */
        "calll vectoangles\n"
        "movss 0x3c(%edi), %xmm0\n" /* line 669 | bolt */
        "subss 0x2ed788, %xmm0\n" /* 120.0f */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x3c(%edi)\n" /* bolt */
        "movl $0x42340000, %esi\n" /* line 670 | self */
        "movl %esi, 4(%esp)\n" /* self */
        "movl $0xc2340000, %ebx\n" /* weapDef */
        "movl %ebx, (%esp)\n" /* weapDef */
        "calll flrand\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "addss 0x2eda04, %xmm0\n" /* 720.0f */
        "movss %xmm0, 0x48(%edi)\n" /* bolt */
        "movl $0, 0x4c(%edi)\n" /* line 671 | bolt */
        "movl %esi, 4(%esp)\n" /* line 672 | self */
        "movl %ebx, (%esp)\n" /* weapDef */
        "calll flrand\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "addss 0x2ed638, %xmm0\n" /* 360.0f */
        "movss %xmm0, 0x50(%edi)\n" /* bolt */
        "leal 0x138(%edi), %edx\n" /* line 674 | bolt, to */
        /* { scope 2 */
        "movl 0xc(%ebp), %ecx\n" /* line 199 | start */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x138(%edi)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x144(%edi), %edx\n" /* line 675 | bolt, to */
        /* { scope 2 */
        "movl 0x3c(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x144(%edi)\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 200 */
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        /* } scope */
        "movl %edi, %eax\n" /* line 678 | bolt */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c71ce_001c73d4:\n"
        "movl 0x195f6a0, %eax\n" /* line 632 */
        "addl 0x1ec(%eax), %edx\n"
        "movl %edx, 0x190(%edi)\n" /* bolt */
        "movl $0, 0x3c(%ecx)\n" /* line 633 */
        "movl 0x158(%esi), %ecx\n" /* self */
        "jmp .Lf1c71ce_001c720a\n"
    );
}

/* line 688 */
__attribute__((naked))
gentity_t * fire_rocket(gentity_t *self, vec_t *start, vec_t *dir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 688 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* start */
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 693 | dir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl 8(%ebp), %edx\n" /* line 696 | self */
        "movl 0xc8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edi\n" /* weapDef */
        "calll G_Spawn\n" /* line 699 */
        "movl %eax, %ebx\n" /* bolt */
        "movl 0x195f5bc, %eax\n" /* line 700 */
        "movzwl 0x3e(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x168(%ebx), %eax\n" /* bolt */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 0x195f6a0, %edx\n" /* line 701 */
        "movl 0x1ec(%edx), %eax\n"
        "addl $0x7530, %eax\n"
        "movl %eax, 0x190(%ebx)\n" /* bolt */
        "movb $8, 0x166(%ebx)\n" /* line 702 | bolt */
        "movl $4, 4(%ebx)\n" /* line 703 | bolt */
        "orl $0x400, 8(%ebx)\n" /* line 704 | bolt */
        "movb $8, 0xf2(%ebx)\n" /* line 705 | bolt */
        "movl 8(%ebp), %ecx\n" /* line 707 | self */
        "movl 0xc8(%ecx), %eax\n"
        "movl %eax, 0xc8(%ebx)\n" /* bolt */
        "movl (%ecx), %eax\n" /* line 709 */
        "movl %eax, 0x150(%ebx)\n" /* bolt */
        "movl %ecx, 0x18c(%ebx)\n" /* line 710 | bolt */
        "movl 0x1ec(%edi), %eax\n" /* line 712 | weapDef */
        "movl %eax, 0x19c(%ebx)\n" /* bolt */
        "movl $0x2802891, 0x184(%ebx)\n" /* line 713 | bolt */
        "movl 0x1ec(%edx), %eax\n" /* line 716 */
        "addl $0x32, %eax\n"
        "movl %eax, 0x54(%ebx)\n" /* bolt */
        "movl $2, 0xc(%ebx)\n" /* line 718 | bolt */
        "movl 0x1ec(%edx), %eax\n" /* line 719 */
        "subl $0x32, %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* bolt */
        "leal 0x18(%ebx), %edx\n" /* line 720 | bolt, to */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, 0x18(%ebx)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x24(%ebx), %eax\n" /* line 721 | bolt, result */
        "cvtsi2ssl 0x384(%edi), %xmm0\n" /* weapDef, scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "movl 0x10(%ebp), %edx\n" /* dir */
        "mulss (%edx), %xmm1\n"
        "movss %xmm1, 0x24(%ebx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%edx), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 8(%edx), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "cvttss2si 0x24(%ebx), %eax\n" /* line 723 | bolt */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x24(%ebx)\n" /* bolt */
        "cvttss2si 0x28(%ebx), %eax\n" /* bolt */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x28(%ebx)\n" /* bolt */
        "cvttss2si 0x2c(%ebx), %eax\n" /* bolt */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x2c(%ebx)\n" /* bolt */
        "leal 0x138(%ebx), %edx\n" /* line 724 | bolt, to */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, 0x138(%ebx)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x144(%ebx), %esi\n" /* line 726 | bolt, start */
        "movl %esi, 4(%esp)\n" /* start */
        "movl 0x10(%ebp), %ecx\n" /* dir */
        "movl %ecx, (%esp)\n"
        "calll vectoangles\n"
        "movl %esi, 4(%esp)\n" /* line 727 | start */
        "movl %ebx, (%esp)\n" /* bolt */
        "calll G_SetAngle\n"
        "cvtsi2ssl 0x5ac(%edi), %xmm0\n" /* line 730 | weapDef */
        "cvtsi2ssl 0x384(%edi), %xmm1\n" /* weapDef */
        "divss %xmm1, %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "movss %xmm0, 0x1a8(%ebx)\n" /* bolt */
        "movl 8(%ebp), %edx\n" /* line 731 | self */
        "movl 0x174(%edx), %eax\n"
        "andl $0x20000, %eax\n"
        "orl %eax, 0x174(%ebx)\n" /* bolt */
        /* } scope */
        "movl %ebx, %eax\n" /* line 733 | bolt */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 20 */
static __attribute__((naked))
void G_MissileLandAngles(qboolean bForceAlign)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 20 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %esi\n" /* ent */
        "movl %edx, %ebx\n" /* trace */
        "movl %ecx, %edi\n" /* vAngles */
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 30 */
        "movl 0x1f0(%eax), %edx\n"
        "movl 0x1ec(%eax), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss (%ebx), %xmm0\n" /* trace */
        "cvttss2si %xmm0, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* hitTime */
        "movl %ecx, 8(%esp)\n" /* line 31 */
        "movl %edx, 4(%esp)\n"
        "leal 0x30(%esi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movss 0xc(%ebx), %xmm0\n" /* line 34 | trace */
        "ucomiss 0x2ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "ja .Lf1c75b8_001c764e\n"
        "movl 8(%ebp), %eax\n" /* line 73 | bForceAlign */
        "testl %eax, %eax\n"
        "je .Lf1c75b8_001c761b\n"
        /* } scope */
        ".Lf1c75b8_001c7613:\n"
        "addl $0x5c, %esp\n" /* line 78 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c75b8_001c761b:\n"
        "movss 0x48(%esi), %xmm0\n" /* line 76 | ent */
        "movss %xmm0, -0x30(%ebp)\n"
        "calll rand\n"
        "andl $0x7f, %eax\n"
        "subl $0x3f, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x48(%esi)\n" /* ent */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 78 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c75b8_001c764e:\n"
        "leal 4(%ebx), %eax\n" /* line 36 | trace */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* vAngles */
        "movl %eax, (%esp)\n"
        "calll PitchForYawOnNormal\n"
        "fstps -0x28(%ebp)\n" /* fSurfacePitch */
        "movl (%edi), %eax\n" /* line 37 | vAngles */
        "movl %eax, 4(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* fSurfacePitch */
        "movss %xmm0, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x24(%ebp)\n" /* fAngleDelta */
        "movss -0x24(%ebp), %xmm1\n" /* line 54 | fAngleDelta */
        "andps 0x303320, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* fAbsAngDelta */
        "movl 8(%ebp), %ecx\n" /* line 41 | bForceAlign */
        "testl %ecx, %ecx\n"
        "jne .Lf1c75b8_001c76fc\n"
        "leal 0x3c(%esi), %edx\n" /* line 43 | ent, to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | vAngles */
        "movl %eax, 0x3c(%esi)\n" /* ent */
        "movl 4(%edi), %eax\n" /* line 200 | vAngles */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 201 | vAngles */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 44 | hitTime */
        "movl %eax, 0x34(%esi)\n" /* ent */
        "ucomiss 0x2ed7d8, %xmm1\n" /* line 46 | 80.0f */
        "jae .Lf1c75b8_001c77a0\n"
        "jp .Lf1c75b8_001c77a0\n"
        "movss 0x48(%esi), %xmm1\n" /* line 49 | ent */
        "movss %xmm1, -0x48(%ebp)\n"
        "calll randomf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "mulss 0x2ed6f4, %xmm0\n" /* 0.30000001192092896f */
        "addss 0x2eda08, %xmm0\n" /* 0.8500000238418579f */
        "movss -0x48(%ebp), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "xorps 0x303330, %xmm1\n"
        "movss %xmm1, 0x48(%esi)\n" /* ent */
        ".Lf1c75b8_001c76fc:\n"
        "movl (%edi), %eax\n" /* line 58 | vAngles */
        "movl %eax, (%esp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, (%edi)\n" /* vAngles */
        "movl 8(%ebp), %edx\n" /* line 61 | bForceAlign */
        "testl %edx, %edx\n"
        "jne .Lf1c75b8_001c7729\n"
        "movss -0x20(%ebp), %xmm1\n" /* fAbsAngDelta */
        "ucomiss 0x2ed6ec, %xmm1\n" /* 45.0f */
        "jae .Lf1c75b8_001c7773\n"
        "jp .Lf1c75b8_001c7773\n"
        ".Lf1c75b8_001c7729:\n"
        "andps 0x303320, %xmm0\n" /* line 63 */
        "ucomiss 0x2ed5f8, %xmm0\n" /* 90.0f */
        "ja .Lf1c75b8_001c7752\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 66 | fSurfacePitch */
        "movss %xmm1, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps (%edi)\n" /* vAngles */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 78 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c75b8_001c7752:\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 64 | fSurfacePitch */
        "addss 0x2ed64c, %xmm0\n" /* 180.0f */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps (%edi)\n" /* vAngles */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 78 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c75b8_001c7773:\n"
        "ucomiss 0x2ed7d8, %xmm1\n" /* line 68 | 80.0f */
        "jae .Lf1c75b8_001c77d6\n"
        "jp .Lf1c75b8_001c77d6\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 69 | fAngleDelta */
        "mulss 0x2ed604, %xmm1\n" /* 0.25f */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps (%edi)\n" /* vAngles */
        "jmp .Lf1c75b8_001c7613\n"
        ".Lf1c75b8_001c77a0:\n"
        "movss 0x48(%esi), %xmm0\n" /* line 54 | ent */
        "movss %xmm0, -0x1c(%ebp)\n"
        "calll randomf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "mulss 0x2ed6f4, %xmm0\n" /* 0.30000001192092896f */
        "addss 0x2eda08, %xmm0\n" /* 0.8500000238418579f */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 0x48(%esi)\n" /* ent */
        "jmp .Lf1c75b8_001c76fc\n"
        ".Lf1c75b8_001c77d6:\n"
        "movss %xmm0, (%esp)\n" /* line 71 */
        "calll AngleNormalize360\n"
        "fstps (%edi)\n" /* vAngles */
        "jmp .Lf1c75b8_001c7613\n"
    );
}

/* line 86 */
static __attribute__((naked))
qboolean G_BounceMissile(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 86 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %edi\n" /* ent */
        "movl %edx, %esi\n" /* trace */
        /* { scope 1: result */
        "movl 0xc8(%eax), %eax\n" /* line 99 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x48(%ebp)\n" /* weapDef */
        "leal 0x138(%edi), %ebx\n" /* line 102 | ent */
        "movl $0x20, 8(%esp)\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_PointContents\n"
        "movl %eax, -0x44(%ebp)\n" /* contents */
        "movl 0x10(%esi), %eax\n" /* line 103 | trace */
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* surfType */
        "movl 0x195f6a0, %ecx\n" /* line 106 */
        "movl 0x1f0(%ecx), %edx\n"
        "leal -0x24(%ebp), %eax\n" /* line 107 | velocity */
        "movl %eax, 8(%esp)\n"
        "movl 0x1ec(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss (%esi), %xmm0\n" /* trace */
        "cvttss2si %xmm0, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal 0xc(%edi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectoryDelta\n"
        "leal 4(%esi), %edx\n" /* line 108 | trace */
        "movl %edx, -0x4c(%ebp)\n"
        "movss -0x24(%ebp), %xmm2\n" /* line 304 | velocity */
        "leal 8(%esi), %eax\n" /* trace */
        "movl %eax, -0x5c(%ebp)\n"
        "leal 0xc(%esi), %ecx\n" /* trace */
        "movaps %xmm2, %xmm3\n"
        "mulss 4(%esi), %xmm3\n" /* trace */
        "movss -0x20(%ebp), %xmm5\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 8(%esi), %xmm0\n" /* trace */
        "addss %xmm0, %xmm3\n"
        "movss -0x1c(%ebp), %xmm4\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 0xc(%esi), %xmm0\n" /* trace */
        "addss %xmm0, %xmm3\n"
        "leal 0x24(%edi), %edx\n" /* line 109 | ent */
        "movl %edx, -0x3c(%ebp)\n" /* result */
        "movaps %xmm3, %xmm1\n" /* scale */
        "mulss 0x2ed628, %xmm1\n" /* -2.0f, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 4(%esi), %xmm0\n" /* trace */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 0x24(%edi)\n" /* ent */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 8(%esi), %xmm0\n" /* trace */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, 0x28(%edi)\n" /* ent */
        "mulss 0xc(%esi), %xmm1\n" /* line 290 | trace */
        "addss %xmm4, %xmm1\n"
        "movss %xmm1, 0x2c(%edi)\n" /* ent */
        /* } scope */
        "cvtss2sd 0xc(%esi), %xmm0\n" /* line 112 | trace */
        "movsd 0x307d70, %xmm6\n" /* 0.7 */
        "ucomisd %xmm6, %xmm0\n"
        "jbe .Lf1c77e8_001c7906\n"
        "movzwl 0x1c(%esi), %eax\n" /* line 114 | trace */
        "movl %eax, 0x7c(%edi)\n" /* ent */
        ".Lf1c77e8_001c7906:\n"
        "testb $1, 0xb(%edi)\n" /* line 117 | ent */
        "jne .Lf1c77e8_001c7a18\n"
        "pxor %xmm4, %xmm4\n"
        ".Lf1c77e8_001c7914:\n"
        "movss 0x2ed7d0, %xmm0\n" /* line 272 | 0.10000000149011612f */
        "movl -0x4c(%ebp), %eax\n"
        "movss (%eax), %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "movl -0x5c(%ebp), %edx\n" /* line 273 */
        "movss (%edx), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "mulss (%ecx), %xmm0\n" /* line 274 */
        "minss %xmm0, %xmm4\n" /* line 142 */
        "addss (%ebx), %xmm2\n" /* line 240 */
        "movss %xmm2, (%ebx)\n"
        "addss 4(%ebx), %xmm1\n" /* line 241 */
        "movss %xmm1, 4(%ebx)\n"
        "addss 8(%ebx), %xmm4\n" /* line 242 */
        "movss %xmm4, 8(%ebx)\n"
        "leal 0x18(%edi), %edx\n" /* line 146 | ent, to */
        /* { scope 2 */
        "movss %xmm2, 0x18(%edi)\n" /* line 199 | ent */
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x195f6a0, %ebx\n" /* line 147 */
        "movl 0x1ec(%ebx), %eax\n"
        "movl %eax, 0x10(%edi)\n" /* ent */
        "leal -0x30(%ebp), %ecx\n" /* line 149 | vAngles */
        "movl $0, (%esp)\n"
        "movl %esi, %edx\n" /* trace */
        "movl %edi, %eax\n" /* ent */
        "calll G_MissileLandAngles\n"
        "leal 0x3c(%edi), %edx\n" /* line 150 | ent, to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | vAngles */
        "movl %eax, 0x3c(%edi)\n" /* ent */
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x1ec(%ebx), %eax\n" /* line 151 */
        "movl %eax, 0x34(%edi)\n" /* ent */
        "movl -0x44(%ebp), %ebx\n" /* line 153 | contents */
        "testl %ebx, %ebx\n"
        "je .Lf1c77e8_001c79bb\n"
        ".Lf1c77e8_001c79b1:\n"
        "xorl %eax, %eax\n" /* line 81 */
        /* } scope */
        ".Lf1c77e8_001c79b3:\n"
        "addl $0x6c, %esp\n" /* line 163 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: result */
        ".Lf1c77e8_001c79bb:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 248 | result */
        "movss (%eax), %xmm2\n"
        "subss -0x24(%ebp), %xmm2\n" /* velocity */
        "movss %xmm2, -0x24(%ebp)\n" /* velocity */
        "movss 4(%eax), %xmm1\n" /* line 249 */
        "subss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "sqrtss %xmm2, %xmm2\n"
        "ucomiss 0x2ed798, %xmm2\n" /* 100.0f */
        "jbe .Lf1c77e8_001c79b1\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 163 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: result */
        ".Lf1c77e8_001c7a18:\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm5, %xmm5\n"
        "addss %xmm5, %xmm2\n"
        "mulss %xmm4, %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "sqrtss %xmm2, %xmm0\n"
        "pxor %xmm4, %xmm4\n" /* line 121 */
        "ucomiss %xmm4, %xmm0\n"
        "jbe .Lf1c77e8_001c7a3e\n"
        "ucomiss %xmm3, %xmm4\n"
        "jae .Lf1c77e8_001c7abd\n"
        ".Lf1c77e8_001c7a3e:\n"
        "cvtss2sd 0xc(%esi), %xmm0\n" /* line 130 | trace */
        "ucomisd %xmm6, %xmm0\n"
        "jbe .Lf1c77e8_001c7914\n"
        "movl -0x3c(%ebp), %edx\n" /* line 324 | result */
        "movss (%edx), %xmm0\n"
        "movss 4(%edx), %xmm1\n"
        "movss 8(%edx), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "ucomiss 0x2ed694, %xmm0\n" /* 20.0f */
        "jae .Lf1c77e8_001c7914\n"
        "jp .Lf1c77e8_001c7914\n"
        "movl %ebx, 4(%esp)\n" /* line 132 */
        "movl %edi, (%esp)\n" /* ent */
        "calll G_SetOrigin\n"
        "leal -0x30(%ebp), %ebx\n" /* line 134 | vAngles */
        "movl $1, (%esp)\n"
        "movl %ebx, %ecx\n"
        "movl %esi, %edx\n" /* trace */
        "movl %edi, %eax\n" /* ent */
        "calll G_MissileLandAngles\n"
        "movl %ebx, 4(%esp)\n" /* line 135 */
        "movl %edi, (%esp)\n" /* ent */
        "calll G_SetAngle\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1c77e8_001c79b3\n"
        ".Lf1c77e8_001c7abd:\n"
        "movl -0x40(%ebp), %eax\n" /* line 124 | surfType */
        "movl -0x48(%ebp), %edx\n" /* weapDef */
        "movss 0x3a0(%edx, %eax, 4), %xmm2\n"
        "xorps 0x303340, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "movss 0x3fc(%edx, %eax, 4), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x24(%edi), %xmm0\n" /* ent */
        "movss %xmm0, 0x24(%edi)\n" /* ent */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "movl -0x3c(%ebp), %eax\n" /* result */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, 0x28(%edi)\n" /* ent */
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        "movss %xmm1, 0x2c(%edi)\n" /* ent */
        "jmp .Lf1c77e8_001c7a3e\n"
    );
}

/* line 490 */
__attribute__((naked))
void G_RunMissile(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 490 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1: dir, hitClient, weapDef, methodOfDeath, ... */
        "movl 0xc(%esi), %eax\n" /* line 500 | ent */
        "testl %eax, %eax\n"
        "jne .Lf1c7b1c_001c7c0e\n"
        "cmpl $0x3fe, 0x7c(%esi)\n" /* ent */
        "je .Lf1c7b1c_001c7c0e\n"
        "leal 0x138(%esi), %edi\n" /* line 502 | ent */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x3c(%ebp)\n" /* origin */
        "movl 0x13c(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movss 0x140(%esi), %xmm0\n" /* line 201 */
        "subss 0x2ed600, %xmm0\n" /* line 503 | 1.5f */
        "movss %xmm0, -0x34(%ebp)\n"
        /* { scope 2: scale, dir */
        "movl 0x195f734, %eax\n" /* line 364 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x184(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x150(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x84(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "cmpb $0, -0x61(%ebp)\n" /* line 366 */
        "jne .Lf1c7b1c_001c8676\n"
        /* } scope */
        ".Lf1c7b1c_001c7bb0:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 505 | 1.0f */
        "ucomiss -0x84(%ebp), %xmm0\n" /* tr */
        "jne .Lf1c7b1c_001c7c14\n"
        "jp .Lf1c7b1c_001c7c14\n"
        "movl $5, 0xc(%esi)\n" /* line 507 | ent */
        "movl 0x195f6a0, %ecx\n" /* line 508 */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* ent */
        "movl $0, 0x14(%esi)\n" /* line 509 | ent */
        "leal 0x18(%esi), %edx\n" /* line 510 | ent, to */
        /* { scope 2: scale, dir */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x18(%esi)\n"
        "movl 0x13c(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0x140(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x24(%esi), %edx\n" /* line 511 | ent, v */
        /* { scope 2: scale, dir */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x24(%esi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "jmp .Lf1c7b1c_001c7c1a\n"
        ".Lf1c7b1c_001c7c0e:\n"
        "leal 0x138(%esi), %edi\n"
        ".Lf1c7b1c_001c7c14:\n"
        "movl 0x195f6a0, %ecx\n"
        /* } scope */
        ".Lf1c7b1c_001c7c1a:\n"
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x48(%ebp)\n" /* vOldOrigin */
        "leal 0x13c(%esi), %edx\n" /* line 200 */
        "movl %edx, -0xcc(%ebp)\n"
        "movl 0x13c(%esi), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "leal 0x140(%esi), %eax\n" /* line 201 */
        "movl %eax, -0xc8(%ebp)\n"
        "movl 0x140(%esi), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "leal 0xc(%esi), %edx\n" /* line 518 | ent */
        "movl %edx, -0xd8(%ebp)\n"
        "leal -0x3c(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 248 | origin */
        "subss 0x138(%esi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* dir */
        "movss -0x38(%ebp), %xmm0\n" /* line 249 */
        "subss 0x13c(%esi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 250 */
        "subss 0x140(%esi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 522 | dir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0xd4(%ebp)\n"
        "movss -0xd4(%ebp), %xmm0\n"
        "ucomiss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "jb .Lf1c7b1c_001c8618\n"
        ".Lf1c7b1c_001c7ccb:\n"
        "movss 0x2c(%esi), %xmm0\n" /* line 531 | ent */
        "andps 0x303350, %xmm0\n"
        "ucomiss 0x2ed7b4, %xmm0\n" /* 30.0f */
        "ja .Lf1c7b1c_001c818c\n"
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c7ce4:\n"
        "movl 0x195f734, %eax\n" /* line 364 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x184(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x150(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x84(%ebp), %edx\n" /* tr */
        "movl %edx, (%esp)\n"
        "calll G_LocationalTrace\n"
        "cmpb $0, -0x61(%ebp)\n" /* line 366 */
        "jne .Lf1c7b1c_001c81ef\n"
        /* } scope */
        ".Lf1c7b1c_001c7d24:\n"
        "movl -0x74(%ebp), %eax\n" /* line 537 */
        "andl $0x1f00000, %eax\n"
        "cmpl $0x1400000, %eax\n"
        "je .Lf1c7b1c_001c8256\n"
        ".Lf1c7b1c_001c7d37:\n"
        "movzbl 0x166(%esi), %eax\n" /* line 546 | ent */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 0x20(%eax), %eax\n"
        "movl %eax, -0xd0(%ebp)\n" /* methodOfDeath */
        "cmpl $3, %eax\n" /* line 547 */
        "je .Lf1c7b1c_001c858a\n"
        ".Lf1c7b1c_001c7d5c:\n"
        "movss -0x84(%ebp), %xmm4\n" /* line 550 | tr, fraction */
        /* { scope 2: scale, dir */
        "movss (%edi), %xmm0\n" /* line 1203 */
        "movss -0x3c(%ebp), %xmm3\n" /* origin */
        "subss %xmm0, %xmm3\n"
        "mulss %xmm4, %xmm3\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0x54(%ebp)\n" /* endpos */
        "movl -0xcc(%ebp), %ecx\n" /* line 1204 */
        "movss (%ecx), %xmm0\n"
        "movss -0x38(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x50(%ebp)\n"
        "movl -0xc8(%ebp), %eax\n" /* line 1205 */
        "movss (%eax), %xmm2\n"
        "movss -0x34(%ebp), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        /* } scope */
        "movss %xmm3, (%edi)\n" /* line 199 */
        "leal 4(%edi), %edx\n" /* line 200 */
        "movl %edx, -0xc0(%ebp)\n"
        "movss %xmm1, 4(%edi)\n"
        "leal 8(%edi), %ebx\n" /* line 201 | other */
        "movss %xmm0, 8(%edi)\n"
        "testb $1, 0xb(%esi)\n" /* line 553 | ent */
        "jne .Lf1c7b1c_001c7fd0\n"
        ".Lf1c7b1c_001c7de2:\n"
        "movl %esi, (%esp)\n" /* line 573 | ent */
        "calll SV_LinkEntity\n"
        "movl 0xc8(%esi), %eax\n" /* line 575 | ent */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ebx\n" /* weapDef */
        "cmpl $3, -0xd0(%ebp)\n" /* line 579 | methodOfDeath */
        "je .Lf1c7b1c_001c86e2\n"
        ".Lf1c7b1c_001c7e07:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 582 | 1.0f */
        "ucomiss -0x84(%ebp), %xmm0\n" /* tr */
        "jp .Lf1c7b1c_001c7e1e\n"
        "je .Lf1c7b1c_001c8363\n"
        ".Lf1c7b1c_001c7e1e:\n"
        "movl -0x74(%ebp), %edx\n" /* line 585 */
        "testb $0x10, %dl\n"
        "jne .Lf1c7b1c_001c86cf\n"
        /* { scope 2: scale, dir */
        "movzwl -0x68(%ebp), %eax\n" /* line 182 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* other */
        "subl %eax, %ebx\n" /* other */
        "shll $4, %ebx\n" /* other */
        "addl 0x195f688, %ebx\n" /* other */
        "andl $0x1f00000, %edx\n" /* line 184 */
        "shrl $0x14, %edx\n"
        "movl %edx, 0x88(%esi)\n"
        "cmpb $0, 0x161(%ebx)\n" /* line 187 | other */
        "jne .Lf1c7b1c_001c7e65\n"
        "testb $1, 0xb(%esi)\n"
        "jne .Lf1c7b1c_001c864c\n"
        ".Lf1c7b1c_001c7e65:\n"
        "movl 0xc8(%esi), %eax\n" /* line 197 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0xb8(%ebp)\n" /* weapDef */
        "movzbl 0x166(%esi), %eax\n" /* line 200 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 0x20(%eax), %eax\n"
        "movl %eax, -0xb4(%ebp)\n" /* methodOfDeath */
        "cmpb $0, 0x161(%ebx)\n" /* line 203 | other */
        "jne .Lf1c7b1c_001c8623\n"
        "movl $0, -0xbc(%ebp)\n" /* line 226 | hitClient */
        ".Lf1c7b1c_001c7eac:\n"
        "movl 0x19c(%esi), %ecx\n" /* line 232 */
        "testl %ecx, %ecx\n"
        "je .Lf1c7b1c_001c7efd\n"
        "movl 0x150(%esi), %eax\n" /* line 233 */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1c7b1c_001c893d\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl 0x195f688, %edx\n"
        ".Lf1c7b1c_001c7edc:\n"
        "movl -0xb4(%ebp), %eax\n" /* methodOfDeath */
        "movl %eax, 0x10(%esp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x54(%ebp), %ecx\n" /* endpos */
        "movl %ecx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll G_CheckHitTriggerDamage\n"
        ".Lf1c7b1c_001c7efd:\n"
        "movl -0xbc(%ebp), %edi\n" /* line 238 | hitClient */
        "testl %edi, %edi\n"
        "jne .Lf1c7b1c_001c7f12\n"
        "cmpw $0, -0x66(%ebp)\n"
        "je .Lf1c7b1c_001c876e\n"
        ".Lf1c7b1c_001c7f12:\n"
        "movl $1, %edi\n"
        ".Lf1c7b1c_001c7f17:\n"
        "leal -0x80(%ebp), %eax\n" /* line 239 */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %edi, %edx\n"
        "cmpb $1, %dl\n"
        "sbbl %edx, %edx\n"
        "addl $0xbe, %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_AddEvent\n"
        "movl -0x74(%ebp), %eax\n" /* line 240 */
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        "movl %eax, 0x88(%esi)\n"
        "movl $1, 0x17c(%esi)\n" /* line 241 */
        "movl $0, 4(%esi)\n" /* line 245 */
        "movl 8(%esi), %eax\n" /* line 249 */
        "xorl $2, %eax\n"
        "orl $0x20, %eax\n"
        "movl %eax, 8(%esi)\n"
        "orl $0x800, 0x174(%esi)\n" /* line 250 */
        "leal 0x18(%esi), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %ecx\n" /* endpos */
        "movl %ecx, (%esp)\n"
        "calll SnapVectorTowards\n"
        "leal -0x54(%ebp), %eax\n" /* line 254 | endpos */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetOrigin\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 257 | weapDef */
        "movl 0x37c(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1c7b1c_001c870c\n"
        ".Lf1c7b1c_001c7faf:\n"
        "movl %esi, (%esp)\n" /* line 263 */
        "calll SV_LinkEntity\n"
        /* } scope */
        "cmpl $4, 4(%esi)\n" /* line 593 | ent */
        "jne .Lf1c7b1c_001c7fc5\n"
        ".Lf1c7b1c_001c7fbd:\n"
        "movl %esi, (%esp)\n" /* line 605 | ent */
        "calll G_RunThink\n"
        /* } scope */
        ".Lf1c7b1c_001c7fc5:\n"
        "addl $0x10c, %esp\n" /* line 606 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dir, hitClient, weapDef, methodOfDeath, ... */
        ".Lf1c7b1c_001c7fd0:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 553 | 1.0f */
        "ucomiss %xmm0, %xmm4\n"
        "jp .Lf1c7b1c_001c7fdf\n"
        "je .Lf1c7b1c_001c7ffa\n"
        ".Lf1c7b1c_001c7fdf:\n"
        "ucomiss %xmm4, %xmm0\n"
        "jbe .Lf1c7b1c_001c7de2\n"
        "movss -0x78(%ebp), %xmm0\n"
        "ucomiss 0x2ed6ac, %xmm0\n" /* 0.699999988079071f */
        "jbe .Lf1c7b1c_001c7de2\n"
        ".Lf1c7b1c_001c7ffa:\n"
        "movss %xmm3, -0x3c(%ebp)\n" /* line 199 | origin */
        "movl -0xcc(%ebp), %ecx\n" /* line 200 */
        "movl (%ecx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl -0xc8(%ebp), %eax\n" /* line 201 */
        "movss (%eax), %xmm0\n"
        "subss 0x2ed600, %xmm0\n" /* line 557 | 1.5f */
        "movss %xmm0, -0x34(%ebp)\n"
        /* { scope 2: scale, dir */
        "movl 0x195f734, %eax\n" /* line 364 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x184(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x150(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* origin */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0xa8(%ebp), %eax\n" /* trDown */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "cmpb $0, -0x85(%ebp)\n" /* line 366 */
        "jne .Lf1c7b1c_001c87c8\n"
        /* } scope */
        ".Lf1c7b1c_001c8064:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 561 | 1.0f */
        "ucomiss -0xa8(%ebp), %xmm0\n" /* trDown */
        "jp .Lf1c7b1c_001c807b\n"
        "je .Lf1c7b1c_001c7de2\n"
        ".Lf1c7b1c_001c807b:\n"
        "cmpw $0x3fe, -0x8c(%ebp)\n"
        "jne .Lf1c7b1c_001c7de2\n"
        "movl -0xa8(%ebp), %eax\n" /* line 563 | trDown */
        "movl %eax, -0x84(%ebp)\n" /* tr */
        "movl -0xa4(%ebp), %eax\n"
        "movl %eax, -0x80(%ebp)\n"
        "movl -0xa0(%ebp), %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "movl -0x98(%ebp), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movss -0x84(%ebp), %xmm4\n" /* line 565 | tr, fraction */
        /* { scope 2: scale, dir */
        "movss (%edi), %xmm0\n" /* line 1203 */
        "movss -0x3c(%ebp), %xmm3\n" /* origin */
        "subss %xmm0, %xmm3\n"
        "mulss %xmm4, %xmm3\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0x54(%ebp)\n" /* endpos */
        "movl -0xcc(%ebp), %edx\n" /* line 1204 */
        "movss (%edx), %xmm0\n"
        "movss -0x38(%ebp), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x50(%ebp)\n"
        "movl -0xc8(%ebp), %ecx\n" /* line 1205 */
        "movss (%ecx), %xmm0\n"
        "movss -0x34(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x4c(%ebp)\n"
        /* } scope */
        "movaps %xmm1, %xmm0\n" /* line 566 */
        "addss 0x2ed600, %xmm0\n" /* 1.5f */
        "subss 0x140(%esi), %xmm0\n" /* ent */
        "addss 0x20(%esi), %xmm0\n" /* ent */
        "movss %xmm0, 0x20(%esi)\n" /* ent */
        "movss %xmm3, (%edi)\n" /* line 199 */
        "movl -0xc0(%ebp), %eax\n" /* line 200 */
        "movss %xmm2, (%eax)\n"
        "movss %xmm1, (%ebx)\n" /* line 201 | other */
        "movss 0x2ed600, %xmm0\n" /* line 569 | 1.5f */
        "addss 0x140(%esi), %xmm0\n" /* ent */
        "movss %xmm0, 0x140(%esi)\n" /* ent */
        "jmp .Lf1c7b1c_001c7de2\n"
        ".Lf1c7b1c_001c818c:\n"
        "movl $0x20, 8(%esp)\n" /* line 531 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll SV_PointContents\n"
        "testl %eax, %eax\n"
        "jne .Lf1c7b1c_001c7ce4\n"
        /* { scope 2: scale, dir */
        "movl 0x195f734, %eax\n" /* line 364 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x184(%esi), %eax\n"
        "orl $0x20, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x150(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %ecx\n" /* origin */
        "movl %ecx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x84(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "cmpb $0, -0x61(%ebp)\n" /* line 366 */
        "je .Lf1c7b1c_001c7d24\n"
        /* } scope */
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c81ef:\n"
        "movl $0, -0x84(%ebp)\n" /* line 368 | tr */
        "movss 0x138(%esi), %xmm0\n" /* line 248 */
        "subss -0x3c(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, -0x60(%ebp)\n" /* dir */
        "movss 0x13c(%esi), %xmm0\n" /* line 249 */
        "subss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss 0x140(%esi), %xmm0\n" /* line 250 */
        "subss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0x80(%ebp), %eax\n" /* line 371 */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* dir */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        /* } scope */
        "movl -0x74(%ebp), %eax\n" /* line 537 */
        "andl $0x1f00000, %eax\n"
        "cmpl $0x1400000, %eax\n"
        "jne .Lf1c7b1c_001c7d37\n"
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c8256:\n"
        "leal -0x60(%ebp), %edx\n" /* line 476 | dir */
        "movl %edx, 4(%esp)\n"
        "leal 0x24(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 477 */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jb .Lf1c7b1c_001c8972\n"
        ".Lf1c7b1c_001c827c:\n"
        "movl $0xb6, 4(%esp)\n" /* line 480 */
        "movl %edi, (%esp)\n"
        "calll G_TempEntity\n"
        "movl %eax, %ebx\n" /* tent */
        "leal -0x80(%ebp), %ecx\n" /* line 481 */
        "movl %ecx, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0xa0(%ebx)\n" /* tent */
        "leal -0x60(%ebp), %eax\n" /* line 482 | dir */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0xd8(%ebx)\n" /* tent */
        "movl -0x74(%ebp), %eax\n" /* line 483 */
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        "movl %eax, 0x88(%ebx)\n" /* tent */
        "movl (%esi), %eax\n" /* line 484 */
        "movl %eax, 0x74(%ebx)\n" /* tent */
        /* } scope */
        /* { scope 2: scale, dir */
        "movl 0x195f734, %eax\n" /* line 364 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x184(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x150(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* origin */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x84(%ebp), %ecx\n" /* tr */
        "movl %ecx, (%esp)\n"
        "calll G_LocationalTrace\n"
        "cmpb $0, -0x61(%ebp)\n" /* line 366 */
        "je .Lf1c7b1c_001c7d37\n"
        "xorl %eax, %eax\n" /* line 368 */
        "movl %eax, -0x84(%ebp)\n" /* tr */
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss -0x3c(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, -0x60(%ebp)\n" /* dir */
        "movl -0xcc(%ebp), %eax\n" /* line 249 */
        "movss (%eax), %xmm0\n"
        "subss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movl -0xc8(%ebp), %edx\n" /* line 250 */
        "movss (%edx), %xmm0\n"
        "subss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0x80(%ebp), %ecx\n" /* line 371 */
        "movl %ecx, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* dir */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "jmp .Lf1c7b1c_001c7d37\n"
        /* } scope */
        ".Lf1c7b1c_001c8363:\n"
        "leal 0x24(%esi), %edx\n" /* line 597 | ent */
        "movl %edx, -0xdc(%ebp)\n"
        "movss 0x24(%esi), %xmm0\n" /* line 324 */
        "movss 0x28(%esi), %xmm1\n"
        "movss 0x2c(%esi), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1c7b1c_001c83a2\n"
        "je .Lf1c7b1c_001c7fbd\n"
        ".Lf1c7b1c_001c83a2:\n"
        "movl $0x3ff, 0x7c(%esi)\n" /* line 599 | ent */
        "cmpl $2, 0x78(%ebx)\n" /* line 600 | weapDef */
        "jne .Lf1c7b1c_001c7fbd\n"
        "testb $2, 0x176(%esi)\n" /* ent */
        "jne .Lf1c7b1c_001c7fbd\n"
        /* { scope 2: scale, dir */
        "cvttss2si 0x1a8(%esi), %eax\n" /* line 427 */
        "addl 0x10(%esi), %eax\n"
        "movl 0x195f6a0, %edx\n"
        "cmpl 0x1ec(%edx), %eax\n"
        "jge .Lf1c7b1c_001c7fbd\n"
        "movl 0xc8(%esi), %eax\n" /* line 429 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0xb0(%ebp)\n" /* weaponDef */
        "movl 0x24(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x60(%ebp)\n" /* dir */
        "movl 0x28(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0x2c(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "leal -0x60(%ebp), %ecx\n" /* line 432 | dir */
        "movl %ecx, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl -0xb0(%ebp), %eax\n" /* line 407 | weaponDef */
        "cvtss2sd 0x5a8(%eax), %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll tanf\n"
        "fstps -0xac(%ebp)\n" /* scale */
        "xorl %ebx, %ebx\n" /* other */
        ".Lf1c7b1c_001c843c:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 437 */
        "movl $0xbf800000, (%esp)\n"
        "calll flrand\n"
        "fstps -0x24(%ebp, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 436 | axis */
        "cmpl $3, %ebx\n" /* axis */
        "jne .Lf1c7b1c_001c843c\n"
        /* { scope 3 */
        "movss -0xac(%ebp), %xmm0\n" /* line 272 | scale */
        "mulss -0x24(%ebp), %xmm0\n" /* perturbation */
        "movss %xmm0, -0x24(%ebp)\n" /* perturbation */
        "movss -0xac(%ebp), %xmm0\n" /* line 273 | scale */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0xac(%ebp), %xmm1\n" /* line 274 | scale */
        "mulss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "movss -0x60(%ebp), %xmm0\n" /* line 240 | dir */
        "addss -0x24(%ebp), %xmm0\n" /* perturbation */
        "movss %xmm0, -0x60(%ebp)\n" /* dir */
        "movss -0x5c(%ebp), %xmm0\n" /* line 241 */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "addss -0x58(%ebp), %xmm1\n" /* line 242 */
        "movss %xmm1, -0x58(%ebp)\n"
        "leal -0x60(%ebp), %edx\n" /* line 442 | dir */
        "movl %edx, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl -0xb0(%ebp), %ecx\n" /* line 444 | weaponDef */
        "cvtsi2ssl 0x384(%ecx), %xmm0\n" /* scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x60(%ebp), %xmm1\n" /* dir */
        "movl -0xdc(%ebp), %eax\n"
        "movss %xmm1, (%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x5c(%ebp), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss -0x58(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "leal 0x18(%esi), %edx\n" /* line 445 | to */
        /* { scope 3 */
        "movl (%edi), %eax\n" /* line 199 */
        "movl %eax, 0x18(%esi)\n"
        "movl -0xcc(%ebp), %ecx\n" /* line 200 */
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0xc8(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x144(%esi), %ebx\n" /* line 448 | axis */
        "movl %ebx, 4(%esp)\n" /* axis */
        "leal -0x60(%ebp), %eax\n" /* dir */
        "movl %eax, (%esp)\n"
        "calll vectoangles\n"
        "movl %ebx, 4(%esp)\n" /* line 449 | axis */
        "movl %esi, (%esp)\n"
        "calll G_SetAngle\n"
        "movl 0x195f6a0, %eax\n" /* line 452 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x174(%esi), %eax\n" /* line 455 */
        "testl $0x10000, %eax\n"
        "jne .Lf1c7b1c_001c8990\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 456 | 1000.0f */
        "movl -0xb0(%ebp), %edx\n" /* weaponDef */
        "mulss 0x5a0(%edx), %xmm0\n"
        "movss %xmm0, 0x1a8(%esi)\n"
        ".Lf1c7b1c_001c857a:\n"
        "orl $0x10000, %eax\n" /* line 460 */
        "movl %eax, 0x174(%esi)\n"
        "jmp .Lf1c7b1c_001c7fbd\n"
        /* } scope */
        ".Lf1c7b1c_001c858a:\n"
        "movzwl -0x68(%ebp), %eax\n" /* line 547 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* weapDef */
        "subl %eax, %ebx\n" /* weapDef */
        "shll $4, %ebx\n" /* weapDef */
        "addl 0x195f688, %ebx\n" /* weapDef */
        "cmpw $0, 0x174(%ebx)\n" /* weapDef */
        "jns .Lf1c7b1c_001c7d5c\n"
        /* { scope 2: scale, dir */
        "movl 0x11c(%ebx), %edx\n" /* line 389 | other */
        "movl %edx, -0xc4(%ebp)\n" /* contents */
        "movl $0, 0x11c(%ebx)\n" /* line 392 | other */
        /* { scope 3 */
        "movl 0x195f734, %eax\n" /* line 364 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x184(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x150(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %ecx\n" /* origin */
        "movl %ecx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x84(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "cmpb $0, -0x61(%ebp)\n" /* line 366 */
        "jne .Lf1c7b1c_001c8775\n"
        /* } scope */
        ".Lf1c7b1c_001c8607:\n"
        "movl -0xc4(%ebp), %edx\n" /* line 394 | contents */
        "movl %edx, 0x11c(%ebx)\n" /* other */
        "jmp .Lf1c7b1c_001c7d5c\n"
        /* } scope */
        ".Lf1c7b1c_001c8618:\n"
        "jnp .Lf1c7b1c_001c7fbd\n" /* line 522 */
        "jmp .Lf1c7b1c_001c7ccb\n"
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c8623:\n"
        "movl 0x19c(%esi), %eax\n" /* line 205 */
        "testl %eax, %eax\n"
        "jne .Lf1c7b1c_001c8824\n"
        "movl 0x158(%ebx), %ecx\n" /* line 222 | other */
        "testl %ecx, %ecx\n"
        "je .Lf1c7b1c_001c864c\n"
        "movl $0x700000, %eax\n" /* line 223 */
        "movl -0x74(%ebp), %edx\n"
        "testl %edx, %edx\n"
        "cmovnel -0x74(%ebp), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        ".Lf1c7b1c_001c864c:\n"
        "leal -0x84(%ebp), %edx\n" /* line 225 | tr */
        "movl %esi, %eax\n"
        "calll G_BounceMissile\n"
        "testl %eax, %eax\n"
        "je .Lf1c7b1c_001c8667\n"
        "cmpb $0, -0x61(%ebp)\n"
        "je .Lf1c7b1c_001c894e\n"
        /* } scope */
        ".Lf1c7b1c_001c8667:\n"
        "cmpl $4, 4(%esi)\n" /* line 593 | ent */
        "jne .Lf1c7b1c_001c7fc5\n"
        "jmp .Lf1c7b1c_001c7fbd\n"
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c8676:\n"
        "movl $0, -0x84(%ebp)\n" /* line 368 | tr */
        "movss 0x138(%esi), %xmm0\n" /* line 248 */
        "subss -0x3c(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, -0x60(%ebp)\n" /* dir */
        "movss 0x13c(%esi), %xmm0\n" /* line 249 */
        "subss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss 0x140(%esi), %xmm0\n" /* line 250 */
        "subss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0x80(%ebp), %eax\n" /* line 371 */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* dir */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "jmp .Lf1c7b1c_001c7bb0\n"
        /* } scope */
        ".Lf1c7b1c_001c86cf:\n"
        "movl %esi, (%esp)\n" /* line 587 | ent */
        "calll G_FreeEntity\n"
        /* } scope */
        "addl $0x10c, %esp\n" /* line 606 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dir, hitClient, weapDef, methodOfDeath, ... */
        ".Lf1c7b1c_001c86e2:\n"
        "movl $3, 0x10(%esp)\n" /* line 580 */
        "movl 0x37c(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* vOldOrigin */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_GrenadeTouchTriggerDamage\n"
        "jmp .Lf1c7b1c_001c7e07\n"
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c870c:\n"
        "movzbl 0x166(%esi), %eax\n" /* line 260 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 0x24(%eax), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n" /* other */
        "cvtsi2ssl 0x378(%ecx), %xmm0\n"
        "movss %xmm0, 0x14(%esp)\n"
        "cvtsi2ssl 0x380(%ecx), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x18c(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* endpos */
        "movl %eax, (%esp)\n"
        "calll G_RadiusDamage\n"
        "jmp .Lf1c7b1c_001c7faf\n"
        ".Lf1c7b1c_001c876e:\n"
        "xorl %edi, %edi\n" /* line 238 */
        "jmp .Lf1c7b1c_001c7f17\n"
        /* } scope */
        /* { scope 2: scale, dir */
        /* { scope 3 */
        ".Lf1c7b1c_001c8775:\n"
        "movl $0, -0x84(%ebp)\n" /* line 368 | tr */
        "movss 0x138(%esi), %xmm0\n" /* line 248 */
        "subss -0x3c(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, -0x60(%ebp)\n" /* dir */
        "movss 4(%edi), %xmm0\n" /* line 249 */
        "subss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 */
        "subss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0x80(%ebp), %eax\n" /* line 371 */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* dir */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "jmp .Lf1c7b1c_001c8607\n"
        /* } scope */
        /* } scope */
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c87c8:\n"
        "movl $0, -0xa8(%ebp)\n" /* line 368 | trDown */
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss -0x3c(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, -0x60(%ebp)\n" /* dir */
        "movl -0xcc(%ebp), %ecx\n" /* line 249 */
        "movss (%ecx), %xmm0\n"
        "subss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movl -0xc8(%ebp), %eax\n" /* line 250 */
        "movss (%eax), %xmm0\n"
        "subss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0xa4(%ebp), %eax\n" /* line 371 */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* dir */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "jmp .Lf1c7b1c_001c8064\n"
        /* } scope */
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c8824:\n"
        "movl 0x150(%esi), %edx\n" /* line 208 */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl 0x195f688, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* other */
        "calll LogAccuracyHit\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0xbc(%ebp)\n" /* hitClient */
        "leal -0x60(%ebp), %edx\n" /* line 212 | dir */
        "movl %edx, 8(%esp)\n"
        "movl 0x195f6a0, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xd8(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll BG_EvaluateTrajectoryDelta\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 324 | dir */
        "movss -0x5c(%ebp), %xmm1\n"
        "movss -0x58(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "movss -0x58(%ebp), %xmm2\n" /* line 215 */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movaps %xmm2, %xmm3\n"
        "cmpneqss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "andps %xmm0, %xmm3\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movl 0x19c(%esi), %ecx\n" /* line 217 */
        "movl 0x150(%esi), %eax\n"
        "cmpl $0x3ff, %eax\n"
        "je .Lf1c7b1c_001c8989\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl 0x195f688, %edx\n"
        ".Lf1c7b1c_001c88f7:\n"
        "movl $0, 0x24(%esp)\n"
        "movl $0, 0x20(%esp)\n"
        "movl -0xb4(%ebp), %eax\n" /* methodOfDeath */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n"
        "leal -0x60(%ebp), %ecx\n" /* dir */
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* other */
        "calll G_Damage\n"
        "jmp .Lf1c7b1c_001c7eac\n"
        ".Lf1c7b1c_001c893d:\n"
        "movl 0x195f688, %edx\n" /* line 233 */
        "addl $0x8bba0, %edx\n"
        "jmp .Lf1c7b1c_001c7edc\n"
        ".Lf1c7b1c_001c894e:\n"
        "movl -0x74(%ebp), %eax\n" /* line 226 */
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xbb, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_AddEvent\n"
        "jmp .Lf1c7b1c_001c8667\n"
        /* } scope */
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c8972:\n"
        "jp .Lf1c7b1c_001c827c\n" /* line 477 */
        "xorps 0x303360, %xmm0\n" /* line 478 */
        "movss %xmm0, -0x58(%ebp)\n"
        "jmp .Lf1c7b1c_001c827c\n"
        /* } scope */
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c8989:\n"
        "xorl %edx, %edx\n" /* line 217 */
        "jmp .Lf1c7b1c_001c88f7\n"
        /* } scope */
        /* { scope 2: scale, dir */
        ".Lf1c7b1c_001c8990:\n"
        "movss 0x1a8(%esi), %xmm0\n" /* line 458 */
        "movl -0xb0(%ebp), %ecx\n" /* weaponDef */
        "mulss 0x5a4(%ecx), %xmm0\n"
        "movss %xmm0, 0x1a8(%esi)\n"
        "jmp .Lf1c7b1c_001c857a\n"
    );
}

