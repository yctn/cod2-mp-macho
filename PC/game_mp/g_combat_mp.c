/* ASM dump from: g_combat_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_combat_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern unsigned char bulletPriorityMap[19]; /* 0x0 */
extern unsigned char riflePriorityMap[19]; /* 0x0 */
extern char * modNames[15]; /* 0x0 */
extern float g_fHitLocDamageMult[19]; /* 0x0 */
static const char * g_HitLocNames[19]; /* 0x3145e0 */
static scr_string_t g_HitLocConstNames[19]; /* 0xfe8080 */

static void G_HitLocStrcpy(byte *pMember, const char *pszKeyValue);
void G_ParseHitLocDmgTable(void);
int G_IndexForMeansOfDeath(const char *pszMOD);
scr_string_t G_GetHitLocationString(hitLocation_t hitLoc);
hitLocation_t G_GetHitLocationIndexFromString(int sString);
float CanDamage(gentity_t *targ, const vec_t *origin);
void G_Damage(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, const vec_t *dir, const vec_t *point, int damage, int dflags, int mod, hitLocation_t hitLoc, int timeOffset);
qboolean G_RadiusDamage(const vec_t *origin, gentity_t *inflictor, gentity_t *attacker, float fInnerDamage, float fOuterDamage, float radius, gentity_t *ignore, int mod);
void player_die(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int meansOfDeath, int iWeapon, const vec_t *vDir, const hitLocation_t hitLoc, int psTimeOffset);

/* line 99 */
static __attribute__((naked))
void G_HitLocStrcpy(byte *pMember, const char *pszKeyValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 101 | pszKeyValue */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pMember */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "leave\n" /* line 102 */
        "retl\n"
    );
}

/* line 110 */
__attribute__((naked))
void G_ParseHitLocDmgTable(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 110 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x211c, %esp\n"
        "xorl %esi, %esi\n"
        "leal -0x100(%ebp), %ebx\n" /* hitLocDmgFields */
        "movl $g_HitLocConstNames, %edi\n"
        /* { scope 1 */
        ".Lf1c1aa6_001c1abf:\n"
        "movl $0x3f800000, g_fHitLocDamageMult(%esi)\n" /* line 132 */
        "movl g_HitLocNames(%esi), %eax\n" /* line 133 */
        "movl %eax, (%ebx)\n" /* iFileLength */
        "movl %esi, 4(%ebx)\n" /* line 134 | iFileLength */
        "movl $6, 8(%ebx)\n" /* line 135 | iFileLength */
        "movl $1, 4(%esp)\n" /* line 137 */
        "movl %eax, (%esp)\n"
        "calll Scr_AllocString\n"
        "movw %ax, (%edi)\n"
        "addl $4, %esi\n"
        "addl $0xc, %ebx\n" /* iFileLength */
        "addl $2, %edi\n"
        "cmpl $0x4c, %esi\n" /* line 130 */
        "jne .Lf1c1aa6_001c1abf\n"
        "movl $0, 0x195b048\n" /* line 139 */
        "movl $0, 8(%esp)\n" /* line 149 */
        "leal -0x1c(%ebp), %eax\n" /* hFile */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b66b4, (%esp)\n" /* "info/mp_lochit_dmgtable" */
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %ebx\n" /* iFileLength */
        "testl %eax, %eax\n" /* line 150 */
        "jle .Lf1c1aa6_001c1c96\n"
        ".Lf1c1aa6_001c1b2b:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 154 | hFile */
        "movl %eax, 8(%esp)\n"
        "movl $0xb, 4(%esp)\n"
        "leal -0x2100(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x20f5(%ebp)\n" /* line 155 */
        "movl $0x2b66f4, %edi\n" /* line 158 */
        "movl $0xb, %ecx\n"
        "cld\n"
        "leal -0x2100(%ebp), %esi\n" /* buffer */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1c1aa6_001c1b73\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1c1aa6_001c1b73:\n"
        "testl %eax, %eax\n"
        "jne .Lf1c1aa6_001c1c75\n"
        ".Lf1c1aa6_001c1b7b:\n"
        "subl $0xb, %ebx\n" /* line 163 | iFileLength */
        "cmpl $0x1fff, %ebx\n" /* iFileLength */
        "jg .Lf1c1aa6_001c1c54\n"
        ".Lf1c1aa6_001c1b8a:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 167 | hFile */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* iFileLength */
        "leal -0x2100(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x2100(%ebp, %ebx)\n" /* line 168 */
        "movl -0x1c(%ebp), %eax\n" /* line 169 | hFile */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0x2100(%ebp), %eax\n" /* line 176 | buffer */
        "movl %eax, (%esp)\n"
        "calll Info_Validate\n"
        "testl %eax, %eax\n"
        "je .Lf1c1aa6_001c1c33\n"
        ".Lf1c1aa6_001c1bc8:\n"
        "movl $G_HitLocStrcpy, 0x18(%esp)\n" /* line 179 */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "leal -0x2100(%ebp), %eax\n" /* buffer */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x13, 8(%esp)\n"
        "leal -0x100(%ebp), %eax\n" /* hitLocDmgFields */
        "movl %eax, 4(%esp)\n"
        "movl $g_fHitLocDamageMult, (%esp)\n"
        "calll ParseConfigStringToStruct\n"
        "testl %eax, %eax\n"
        "jne .Lf1c1aa6_001c1c28\n"
        "movl $0x2b66b4, 8(%esp)\n" /* line 180 */
        "movl $0x2b6798, 4(%esp)\n" /* "Error parsing hitloc damage table %s
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf1c1aa6_001c1c28:\n"
        "addl $0x211c, %esp\n" /* line 181 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c1aa6_001c1c33:\n"
        "movl $0x2b66b4, 8(%esp)\n" /* line 177 */
        "movl $0x2b676c, 4(%esp)\n" /* ""%s" is not a valid hitloc damage table
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1c1aa6_001c1bc8\n"
        ".Lf1c1aa6_001c1c54:\n"
        "movl $0x2b66b4, 8(%esp)\n" /* line 164 */
        "movl $0x2b6734, 4(%esp)\n" /* ""%s" Is too long of a hitloc damage table to parse
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1c1aa6_001c1b8a\n"
        ".Lf1c1aa6_001c1c75:\n"
        "movl $0x2b66b4, 8(%esp)\n" /* line 159 */
        "movl $0x2b6700, 4(%esp)\n" /* ""%s" does not appear to be a hitloc damage table
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1c1aa6_001c1b7b\n"
        ".Lf1c1aa6_001c1c96:\n"
        "movl $0x2b66b4, 8(%esp)\n" /* line 151 */
        "movl $0x2b66cc, 4(%esp)\n" /* "Could not load hitloc damage table %s
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1c1aa6_001c1b2b\n"
    );
}

/* line 261 */
__attribute__((naked))
int G_IndexForMeansOfDeath(const char *pszMOD)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 261 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* pszMOD */
        "xorl %esi, %esi\n"
        "movl $modNames, %ebx\n"
        /* { scope 1 */
        ".Lf1c1cba_001c1ccd:\n"
        "movl (%ebx), %eax\n" /* line 267 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pszMOD */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1c1cba_001c1cfd\n"
        "addl $1, %esi\n" /* line 265 | i */
        "addl $4, %ebx\n"
        "cmpl $0xf, %esi\n" /* i */
        "jne .Lf1c1cba_001c1ccd\n"
        "movl %edi, 4(%esp)\n" /* line 272 | pszMOD */
        "movl $0x2b67c0, (%esp)\n" /* "Unknown means of death string '%s'
" */
        "calll Com_Printf\n"
        "xorw %si, %si\n" /* i */
        /* } scope */
        ".Lf1c1cba_001c1cfd:\n"
        "movl %esi, %eax\n" /* line 274 | i */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 766 */
__attribute__((naked))
scr_string_t G_GetHitLocationString(hitLocation_t hitLoc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 766 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* hitLoc */
        "movzwl g_HitLocConstNames(%eax, %eax), %eax\n" /* hitLoc */
        "popl %ebp\n" /* line 771 */
        "retl\n"
    );
}

/* line 781 */
__attribute__((naked))
hitLocation_t G_GetHitLocationIndexFromString(int sString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 781 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* sString */
        "xorl %eax, %eax\n"
        "movl $g_HitLocConstNames, %edx\n"
        "jmp .Lf1c1d18_001c1d32\n"
        /* { scope 1 */
        ".Lf1c1d18_001c1d27:\n"
        "addl $1, %eax\n" /* line 785 */
        "addl $2, %edx\n"
        "cmpl $0x13, %eax\n"
        "je .Lf1c1d18_001c1d39\n"
        ".Lf1c1d18_001c1d32:\n"
        "cmpw %cx, (%edx)\n" /* line 787 */
        "jne .Lf1c1d18_001c1d27\n"
        /* } scope */
        "popl %ebp\n" /* line 793 */
        "retl\n"
        /* { scope 1 */
        ".Lf1c1d18_001c1d39:\n"
        "xorb %al, %al\n" /* line 785 */
        /* } scope */
        "popl %ebp\n" /* line 793 */
        "retl\n"
    );
}

/* line 547 */
__attribute__((naked))
float CanDamage(gentity_t *targ, const vec_t *origin)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 547 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        /* { scope 1: forward, eyeOrigin */
        "movl 8(%ebp), %eax\n" /* line 553 | targ */
        "movl 0x158(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1c1d40_001c1f6f\n"
        "movl %eax, %edx\n"
        /* { scope 2 */
        "leal -0x30(%ebp), %eax\n" /* line 560 | eyeOrigin */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll G_GetPlayerViewOrigin\n"
        "movss -0x28(%ebp), %xmm6\n" /* line 562 */
        "movl 8(%ebp), %ecx\n" /* targ */
        "subss 0x140(%ecx), %xmm6\n"
        "movss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "mulss %xmm3, %xmm6\n"
        "movl 0xc(%ebp), %eax\n" /* line 248 | origin */
        "movss (%eax), %xmm0\n"
        "subss 0x138(%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* forward */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 0x13c(%ecx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 565 */
        "leal -0x24(%ebp), %eax\n" /* line 566 | forward */
        "movl %eax, (%esp)\n"
        "movss %xmm3, -0x88(%ebp)\n"
        "movss %xmm6, -0x98(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x20(%ebp), %xmm4\n" /* line 568 */
        "xorps 0x3032c0, %xmm4\n"
        "movss -0x24(%ebp), %xmm5\n" /* line 569 | forward */
        "movss -0x1c(%ebp), %xmm7\n" /* line 570 */
        "movss -0x30(%ebp), %xmm0\n" /* line 240 | eyeOrigin */
        "movl 8(%ebp), %edx\n" /* targ */
        "addss 0x138(%edx), %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 241 */
        "addss 0x13c(%edx), %xmm1\n"
        "movss -0x28(%ebp), %xmm2\n" /* line 242 */
        "addss 0x140(%edx), %xmm2\n"
        "movss -0x88(%ebp), %xmm3\n" /* line 272 */
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n" /* dest */
        "mulss %xmm3, %xmm1\n" /* line 273 */
        "movss %xmm1, -0x68(%ebp)\n"
        "mulss %xmm3, %xmm2\n" /* line 274 */
        "movss %xmm2, -0x64(%ebp)\n"
        "movss 0x2ed908, %xmm0\n" /* line 288 | 15.0f */
        "movaps %xmm4, %xmm3\n"
        "mulss %xmm0, %xmm3\n"
        "addss -0x6c(%ebp), %xmm3\n" /* dest */
        "movss %xmm3, -0x60(%ebp)\n"
        "movaps %xmm5, %xmm2\n" /* line 289 */
        "mulss %xmm0, %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x5c(%ebp)\n"
        "mulss %xmm7, %xmm0\n" /* line 290 */
        "addss -0x64(%ebp), %xmm0\n"
        "movss -0x98(%ebp), %xmm6\n" /* line 576 */
        "movaps %xmm6, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "movss %xmm3, -0x54(%ebp)\n" /* line 288 */
        "movss %xmm2, -0x50(%ebp)\n" /* line 289 */
        "subss %xmm6, %xmm0\n" /* line 579 */
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss 0x2ed978, %xmm0\n" /* line 288 | -15.0f */
        "mulss %xmm0, %xmm4\n"
        "addss -0x6c(%ebp), %xmm4\n" /* dest */
        "movss %xmm4, -0x48(%ebp)\n"
        "mulss %xmm0, %xmm5\n" /* line 289 */
        "addss -0x68(%ebp), %xmm5\n"
        "movss %xmm5, -0x44(%ebp)\n"
        "mulss %xmm7, %xmm0\n" /* line 290 */
        "addss -0x64(%ebp), %xmm0\n"
        "movaps %xmm6, %xmm1\n" /* line 582 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        "movss %xmm4, -0x3c(%ebp)\n" /* line 288 */
        "movss %xmm5, -0x38(%ebp)\n" /* line 289 */
        "subss %xmm6, %xmm0\n" /* line 585 */
        "movss %xmm0, -0x34(%ebp)\n"
        "xorl %edi, %edi\n" /* hits */
        "xorl %esi, %esi\n" /* i */
        "leal -0x6c(%ebp), %ebx\n" /* dest */
        "movl %edx, %ecx\n"
        ".Lf1c1d40_001c1ee5:\n"
        "movl $0x802891, 0xc(%esp)\n" /* line 590 */
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* origin */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTracePassed\n"
        "cmpl $1, %eax\n" /* line 591 */
        "sbbl $-1, %edi\n" /* hits */
        "addl $1, %esi\n" /* line 588 | i */
        "addl $0xc, %ebx\n"
        "cmpl $5, %esi\n" /* i */
        "je .Lf1c1d40_001c1f18\n"
        "movl 8(%ebp), %ecx\n" /* targ */
        "jmp .Lf1c1d40_001c1ee5\n"
        ".Lf1c1d40_001c1f18:\n"
        "testl %edi, %edi\n" /* line 594 | hits */
        "je .Lf1c1d40_001c1f56\n"
        "cmpl $3, %edi\n" /* line 597 | hits */
        "jg .Lf1c1d40_001c207c\n"
        "cvtsi2ssl %edi, %xmm0\n" /* line 600 | hits */
        "divss 0x2ed720, %xmm0\n" /* 3.0f */
        "movss %xmm0, -0x9c(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n"
        /* } scope */
        /* } scope */
        "movl %eax, -0x9c(%ebp)\n" /* line 633 */
        "flds -0x9c(%ebp)\n"
        "addl $0xac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: forward, eyeOrigin */
        ".Lf1c1d40_001c1f56:\n"
        "xorl %eax, %eax\n" /* line 626 */
        /* } scope */
        "movl %eax, -0x9c(%ebp)\n" /* line 633 */
        "flds -0x9c(%ebp)\n"
        "addl $0xac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: forward, eyeOrigin */
        /* { scope 2 */
        ".Lf1c1d40_001c1f6f:\n"
        "addl $0x120, %eax\n" /* line 600 */
        "movl 8(%ebp), %edx\n" /* targ */
        "addl $0x12c, %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 240 | targ */
        "movss 0x120(%ecx), %xmm3\n"
        "addss 0x12c(%ecx), %xmm3\n"
        "movss 4(%eax), %xmm2\n" /* line 241 */
        "addss 4(%edx), %xmm2\n"
        "movss 8(%eax), %xmm1\n" /* line 242 */
        "addss 8(%edx), %xmm1\n"
        /* } scope */
        "movss 0x2ed5d8, %xmm0\n" /* line 272 | 0.5f */
        "mulss %xmm0, %xmm3\n"
        "movss %xmm3, -0x6c(%ebp)\n" /* dest */
        "mulss %xmm0, %xmm2\n" /* line 273 */
        "movss %xmm2, -0x68(%ebp)\n"
        "mulss %xmm0, %xmm1\n" /* line 274 */
        "movss %xmm1, -0x64(%ebp)\n"
        "movss %xmm1, -0x58(%ebp)\n" /* line 201 */
        "movss 0x2ed908, %xmm0\n" /* line 611 | 15.0f */
        "movaps %xmm3, %xmm4\n"
        "addss %xmm0, %xmm4\n"
        "movss %xmm4, -0x60(%ebp)\n"
        "movaps %xmm2, %xmm5\n" /* line 612 */
        "addss %xmm0, %xmm5\n"
        "movss %xmm5, -0x5c(%ebp)\n"
        "movss %xmm1, -0x4c(%ebp)\n" /* line 201 */
        "movss %xmm4, -0x54(%ebp)\n" /* line 615 */
        "subss %xmm0, %xmm2\n" /* line 616 */
        "movss %xmm2, -0x50(%ebp)\n"
        "movss %xmm1, -0x40(%ebp)\n" /* line 201 */
        "subss %xmm0, %xmm3\n" /* line 619 */
        "movss %xmm3, -0x48(%ebp)\n"
        "movss %xmm5, -0x44(%ebp)\n" /* line 620 */
        "movss %xmm1, -0x34(%ebp)\n" /* line 201 */
        "movss %xmm3, -0x3c(%ebp)\n" /* line 623 */
        "movss %xmm2, -0x38(%ebp)\n" /* line 624 */
        "xorl %esi, %esi\n" /* i */
        "leal -0x6c(%ebp), %ebx\n" /* dest */
        "movl %ecx, %edx\n"
        "movl $0x802891, 0xc(%esp)\n" /* line 628 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* origin */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_LocationalTracePassed\n"
        "testl %eax, %eax\n"
        "jne .Lf1c1d40_001c207c\n"
        ".Lf1c1d40_001c2049:\n"
        "addl $1, %esi\n" /* line 626 | i */
        "addl $0xc, %ebx\n"
        "cmpl $5, %esi\n" /* i */
        "je .Lf1c1d40_001c1f56\n"
        "movl 8(%ebp), %edx\n" /* targ */
        "movl $0x802891, 0xc(%esp)\n" /* line 628 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* origin */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_LocationalTracePassed\n"
        "testl %eax, %eax\n"
        "je .Lf1c1d40_001c2049\n"
        ".Lf1c1d40_001c207c:\n"
        "movl $0x3f800000, %eax\n"
        /* } scope */
        "movl %eax, -0x9c(%ebp)\n" /* line 633 */
        "flds -0x9c(%ebp)\n"
        "addl $0xac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 462 */
__attribute__((naked))
void G_Damage(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, const vec_t *dir, const vec_t *point, int damage, int dflags, int mod, hitLocation_t hitLoc, int timeOffset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 462 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* targ */
        /* { scope 1 */
        "movl 0x158(%ebx), %eax\n" /* line 468 | targ */
        "testl %eax, %eax\n"
        "je .Lf1c209a_001c216e\n"
        /* { scope 2 */
        "cmpb $0, 0x161(%ebx)\n" /* line 405 */
        "je .Lf1c209a_001c20da\n"
        "movl 0x27ac(%eax), %edx\n" /* line 409 */
        "testl %edx, %edx\n"
        "jne .Lf1c209a_001c20da\n"
        "movl 0x27b0(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jne .Lf1c209a_001c20da\n"
        "cmpl $2, 0x26c4(%eax)\n" /* line 413 */
        "je .Lf1c209a_001c20e2\n"
        /* } scope */
        /* } scope */
        ".Lf1c209a_001c20da:\n"
        "addl $0x5c, %esp\n" /* line 536 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1c209a_001c20e2:\n"
        "movl 0xc(%ebp), %esi\n" /* line 418 | inflictor */
        "testl %esi, %esi\n"
        "je .Lf1c209a_001c230d\n"
        "movl 0xc(%ebp), %eax\n" /* line 419 | inflictor */
        "movl 0xc8(%eax), %esi\n"
        ".Lf1c209a_001c20f6:\n"
        "cvtsi2ssl 0x1c(%ebp), %xmm0\n" /* line 428 | damage */
        "movss %xmm0, -0x2c(%ebp)\n"
        /* { scope 3 */
        /* { scope 4 */
        "testl %esi, %esi\n" /* line 382 */
        "jne .Lf1c209a_001c2297\n"
        "movl 0x28(%ebp), %eax\n" /* line 383 | hitLoc */
        "movss g_fHitLocDamageMult(, %eax, 4), %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf1c209a_001c2114:\n"
        "mulss -0x2c(%ebp), %xmm0\n" /* line 428 */
        "cvttss2si %xmm0, %eax\n"
        "testl %eax, %eax\n" /* line 430 */
        "jle .Lf1c209a_001c20da\n"
        "movl 0x2c(%ebp), %edx\n" /* line 434 | timeOffset */
        "movl %edx, 0x28(%esp)\n"
        "movl 0x28(%ebp), %ecx\n" /* hitLoc */
        "movl %ecx, 0x24(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* dir */
        "movl %edx, 0x20(%esp)\n"
        "movl 0x18(%ebp), %ecx\n" /* point */
        "movl %ecx, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n" /* weapon */
        "movl 0x24(%ebp), %edx\n" /* mod */
        "movl %edx, 0x14(%esp)\n"
        "movl 0x20(%ebp), %ecx\n" /* dflags */
        "movl %ecx, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* attacker */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* inflictor */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_PlayerDamage\n"
        "jmp .Lf1c209a_001c20da\n"
        /* } scope */
        ".Lf1c209a_001c216e:\n"
        "cmpb $0, 0x161(%ebx)\n" /* line 474 | targ */
        "je .Lf1c209a_001c20da\n"
        "movl 0xc(%ebp), %eax\n" /* line 477 | inflictor */
        "testl %eax, %eax\n"
        "je .Lf1c209a_001c22f9\n"
        ".Lf1c209a_001c2186:\n"
        "movl 0x10(%ebp), %edi\n" /* line 480 | attacker */
        "testl %edi, %edi\n"
        "je .Lf1c209a_001c22e7\n"
        ".Lf1c209a_001c2191:\n"
        "leal -0x24(%ebp), %edi\n" /* line 486 | localdir */
        "movl %edi, 4(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* dir */
        "movl %edx, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movl 0x174(%ebx), %edx\n" /* line 489 | targ */
        "testb $1, %dl\n"
        "jne .Lf1c209a_001c20da\n"
        "movl 0x1c(%ebp), %esi\n" /* line 492 | damage, weapon */
        "testl %esi, %esi\n" /* weapon */
        "movl $1, %eax\n"
        "cmovgl 0x1c(%ebp), %eax\n" /* damage */
        "movl %eax, 0x1c(%ebp)\n" /* damage */
        "andb $2, %dl\n" /* line 495 */
        "je .Lf1c209a_001c228c\n"
        "movl 0x194(%ebx), %edx\n" /* line 497 | targ */
        "movl %edx, %eax\n"
        "subl 0x1c(%ebp), %eax\n" /* damage */
        "testl %eax, %eax\n"
        "jle .Lf1c209a_001c23ce\n"
        ".Lf1c209a_001c21e1:\n"
        "movl 0x195f748, %eax\n" /* line 501 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1c209a_001c22bf\n"
        ".Lf1c209a_001c21f2:\n"
        "subl 0x1c(%ebp), %edx\n" /* line 505 | damage */
        "movl %edx, 0x194(%ebx)\n" /* targ */
        "movl 0x10(%ebp), %edx\n" /* line 508 | attacker */
        "movl %edx, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 509 | damage */
        "movl %ecx, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl $2, 8(%esp)\n" /* line 510 */
        "movl 0x195f5bc, %esi\n" /* weapon */
        "movzwl 8(%esi), %eax\n" /* weapon */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* targ */
        "calll Scr_Notify\n"
        "movl 0x194(%ebx), %eax\n" /* line 513 | targ */
        "testl %eax, %eax\n"
        "jle .Lf1c209a_001c2326\n"
        "movzbl 0x166(%ebx), %eax\n" /* line 532 | targ */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 0x14(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 533 */
        "je .Lf1c209a_001c20da\n"
        "movl 0x28(%ebp), %edx\n" /* line 534 | hitLoc */
        "movl %edx, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "movl 0x24(%ebp), %ecx\n" /* mod */
        "movl %ecx, 0x10(%esp)\n"
        "movl 0x18(%ebp), %edx\n" /* point */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x1c(%ebp), %ecx\n" /* damage */
        "movl %ecx, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* attacker */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* targ */
        "calll *%eax\n"
        "jmp .Lf1c209a_001c20da\n"
        ".Lf1c209a_001c228c:\n"
        "movl 0x194(%ebx), %edx\n" /* targ */
        "jmp .Lf1c209a_001c21e1\n"
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf1c209a_001c2297:\n"
        "movl %esi, (%esp)\n" /* line 385 */
        "calll BG_GetWeaponDef\n"
        "testl %eax, %eax\n" /* line 388 */
        "je .Lf1c209a_001c22ae\n"
        "movl 0x78(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1c209a_001c23bd\n"
        ".Lf1c209a_001c22ae:\n"
        "movl 0x28(%ebp), %edx\n" /* line 389 | hitLoc */
        "movss g_fHitLocDamageMult(, %edx, 4), %xmm0\n"
        "jmp .Lf1c209a_001c2114\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1c209a_001c22bf:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 502 | damage */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl (%ebx), %eax\n" /* targ */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b67e4, (%esp)\n" /* "target:%i health:%i damage:%i
" */
        "calll Com_Printf\n"
        "movl 0x194(%ebx), %edx\n" /* targ */
        "jmp .Lf1c209a_001c21f2\n"
        ".Lf1c209a_001c22e7:\n"
        "movl 0x195f688, %eax\n" /* line 480 */
        "addl $0x8bba0, %eax\n"
        "movl %eax, 0x10(%ebp)\n" /* attacker */
        "jmp .Lf1c209a_001c2191\n"
        ".Lf1c209a_001c22f9:\n"
        "movl 0x195f688, %ecx\n" /* line 477 */
        "addl $0x8bba0, %ecx\n"
        "movl %ecx, 0xc(%ebp)\n" /* inflictor */
        "jmp .Lf1c209a_001c2186\n"
        /* { scope 2 */
        ".Lf1c209a_001c230d:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 420 | attacker */
        "testl %ecx, %ecx\n"
        "je .Lf1c209a_001c23d9\n"
        "movl 0x10(%ebp), %edx\n" /* line 421 | attacker */
        "movl 0xc8(%edx), %esi\n"
        "jmp .Lf1c209a_001c20f6\n"
        /* } scope */
        ".Lf1c209a_001c2326:\n"
        "cmpl $0xfffffc19, %eax\n" /* line 515 */
        "jge .Lf1c209a_001c2337\n"
        "movl $0xfffffc19, 0x194(%ebx)\n" /* line 516 | targ */
        ".Lf1c209a_001c2337:\n"
        "movl 0x10(%ebp), %eax\n" /* line 519 | attacker */
        "movl %eax, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 520 */
        "movzwl 0xa(%esi), %eax\n" /* weapon */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* targ */
        "calll Scr_Notify\n"
        "movzbl 0x166(%ebx), %eax\n" /* line 522 | targ */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 0x18(%eax), %edx\n"
        "testl %edx, %edx\n" /* line 523 */
        "je .Lf1c209a_001c20da\n"
        "movl 0x2c(%ebp), %ecx\n" /* line 524 | timeOffset */
        "movl %ecx, 0x20(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* hitLoc */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* inflictor */
        "movl 0xc8(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* mod */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x1c(%ebp), %ecx\n" /* damage */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* attacker */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* inflictor */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* targ */
        "calll *%edx\n"
        "jmp .Lf1c209a_001c20da\n"
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf1c209a_001c23bd:\n"
        "movl 0x28(%ebp), %ecx\n" /* line 391 | hitLoc */
        "movss 0x5b0(%eax, %ecx, 4), %xmm0\n"
        "jmp .Lf1c209a_001c2114\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1c209a_001c23ce:\n"
        "leal -1(%edx), %ecx\n" /* line 498 */
        "movl %ecx, 0x1c(%ebp)\n" /* damage */
        "jmp .Lf1c209a_001c21e1\n"
        /* { scope 2 */
        ".Lf1c209a_001c23d9:\n"
        "xorl %esi, %esi\n" /* line 420 */
        "jmp .Lf1c209a_001c20f6\n"
    );
}

/* line 641 */
__attribute__((naked))
qboolean G_RadiusDamage(const vec_t *origin, gentity_t *inflictor, gentity_t *attacker, float fInnerDamage, float fOuterDamage, float radius, gentity_t *ignore, int mod)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 641 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10bc, %esp\n"
        "movl 8(%ebp), %edi\n" /* origin */
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 661 | attacker */
        "testl %eax, %eax\n"
        "je .Lf1c23e0_001c26c9\n"
        "movss 0x1c(%ebp), %xmm0\n" /* line 664 | radius */
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jb .Lf1c23e0_001c2703\n"
        ".Lf1c23e0_001c240c:\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 0x2ed9b4, %xmm1\n" /* 1.4142135381698608f */
        ".Lf1c23e0_001c2417:\n"
        "movl $1, %ecx\n"
        "leal -0x30(%ebp), %esi\n" /* mins, e */
        "leal -0x3c(%ebp), %ebx\n" /* maxs, ent */
        ".Lf1c23e0_001c2422:\n"
        "leal (, %ecx, 4), %eax\n" /* line 641 */
        "leal (%edi, %eax), %edx\n" /* origin */
        "movss -4(%edx), %xmm0\n" /* line 673 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%esi, %eax)\n" /* e */
        "movaps %xmm1, %xmm0\n" /* line 674 */
        "addss -4(%edx), %xmm0\n"
        "movss %xmm0, -4(%ebx, %eax)\n" /* ent */
        "addl $1, %ecx\n"
        "cmpl $4, %ecx\n" /* line 671 */
        "jne .Lf1c23e0_001c2422\n"
        "movl $0xffffffff, 0x10(%esp)\n" /* line 677 */
        "movl $0x400, 0xc(%esp)\n"
        "leal -0x1078(%ebp), %eax\n" /* entityList */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* ent */
        "movl %esi, (%esp)\n" /* e */
        "calll CM_AreaEntities\n"
        "movl %eax, -0x1080(%ebp)\n" /* numListedEntities */
        "testl %eax, %eax\n" /* line 679 */
        "jle .Lf1c23e0_001c26c9\n"
        "movss 0x1c(%ebp), %xmm0\n" /* line 742 | radius */
        "mulss 0x2ed724, %xmm0\n" /* 0.20000000298023224f */
        "movss %xmm0, -0x108c(%ebp)\n"
        "movl $0, -0x107c(%ebp)\n" /* hitClient */
        "xorl %esi, %esi\n" /* e */
        "jmp .Lf1c23e0_001c2655\n"
        ".Lf1c23e0_001c24ab:\n"
        "leal 0x138(%ebx), %eax\n" /* line 689 | ent */
        /* { scope 2 */
        "movss 0x138(%ebx), %xmm0\n" /* line 248 */
        "subss (%edi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* v */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movaps %xmm0, %xmm2\n"
        /* } scope */
        ".Lf1c23e0_001c24e3:\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 324 | v */
        "movss -0x20(%ebp), %xmm1\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "ucomiss 0x1c(%ebp), %xmm0\n" /* line 708 | radius */
        "jae .Lf1c23e0_001c264a\n"
        "movl 0x158(%ebx), %eax\n" /* line 711 | ent */
        "testl %eax, %eax\n"
        "je .Lf1c23e0_001c252c\n"
        "movl 0x195f6a0, %eax\n"
        "movl 0x35f4(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1c23e0_001c264a\n"
        ".Lf1c23e0_001c252c:\n"
        "movss 0x14(%ebp), %xmm1\n" /* line 714 | fInnerDamage */
        "subss 0x18(%ebp), %xmm1\n" /* fOuterDamage */
        "movss %xmm1, -0x1088(%ebp)\n" /* points */
        "divss 0x1c(%ebp), %xmm0\n" /* radius */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss -0x1088(%ebp), %xmm0\n" /* points */
        "movss 0x18(%ebp), %xmm1\n" /* fOuterDamage */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1088(%ebp)\n" /* points */
        "movl %edi, 4(%esp)\n" /* line 717 | origin */
        "movl %ebx, (%esp)\n" /* ent */
        "calll CanDamage\n"
        "fstps -0x1084(%ebp)\n" /* damageScale */
        "movss -0x1084(%ebp), %xmm0\n" /* line 718 | damageScale */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf1c23e0_001c2723\n"
        "movl 0x10(%ebp), %eax\n" /* line 720 | attacker */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll LogAccuracyHit\n"
        "testl %eax, %eax\n"
        "movl $1, %eax\n"
        "cmovel -0x107c(%ebp), %eax\n" /* hitClient */
        "movl %eax, -0x107c(%ebp)\n" /* hitClient */
        "leal 0x138(%ebx), %eax\n" /* ent */
        /* { scope 2 */
        "movss 0x138(%ebx), %xmm0\n" /* line 248 */
        "subss (%edi), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* dir */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edi), %xmm0\n"
        /* } scope */
        "addss 0x2ed8b8, %xmm0\n" /* line 726 | 24.0f */
        "movss %xmm0, -0x40(%ebp)\n"
        "movl $0, 0x24(%esp)\n" /* line 728 */
        "movl $0, 0x20(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* mod */
        "movl %eax, 0x1c(%esp)\n"
        "movl $1, 0x18(%esp)\n"
        "movss -0x1088(%ebp), %xmm0\n" /* points */
        "mulss -0x1084(%ebp), %xmm0\n" /* damageScale */
        ".Lf1c23e0_001c2621:\n"
        "cvttss2si %xmm0, %eax\n" /* line 750 */
        "movl %eax, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n" /* origin */
        "leal -0x48(%ebp), %eax\n" /* dir */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* attacker */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inflictor */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_Damage\n"
        ".Lf1c23e0_001c264a:\n"
        "addl $1, %esi\n" /* line 679 | e */
        "cmpl %esi, -0x1080(%ebp)\n" /* e, numListedEntities */
        "je .Lf1c23e0_001c26d3\n"
        ".Lf1c23e0_001c2655:\n"
        "movl -0x1078(%ebp, %esi, 4), %eax\n" /* line 681 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* ent */
        "subl %eax, %ebx\n" /* ent */
        "shll $4, %ebx\n" /* ent */
        "addl 0x195f688, %ebx\n" /* ent */
        "cmpl 0x20(%ebp), %ebx\n" /* line 683 | ignore, ent */
        "je .Lf1c23e0_001c264a\n"
        "cmpb $0, 0x161(%ebx)\n" /* line 686 | ent */
        "je .Lf1c23e0_001c264a\n"
        "cmpb $0, 0xf1(%ebx)\n" /* line 689 | ent */
        "je .Lf1c23e0_001c24ab\n"
        /* { scope 2 */
        "movl %ebx, %eax\n" /* line 250 */
        "movl $1, %ecx\n"
        "leal -0x24(%ebp), %edx\n" /* v */
        /* } scope */
        ".Lf1c23e0_001c2696:\n"
        "movss -4(%edi, %ecx, 4), %xmm1\n" /* line 697 | origin */
        "movss 0x120(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1c23e0_001c26e4\n"
        "subss %xmm1, %xmm0\n" /* line 698 */
        "movss %xmm0, (%edx)\n"
        ".Lf1c23e0_001c26b1:\n"
        "addl $1, %ecx\n" /* line 702 */
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 695 */
        "jne .Lf1c23e0_001c2696\n"
        "movss -0x1c(%ebp), %xmm2\n"
        "jmp .Lf1c23e0_001c24e3\n"
        ".Lf1c23e0_001c26c9:\n"
        "movl $0, -0x107c(%ebp)\n" /* line 679 | hitClient */
        /* } scope */
        ".Lf1c23e0_001c26d3:\n"
        "movl -0x107c(%ebp), %eax\n" /* line 756 | hitClient */
        "addl $0x10bc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c23e0_001c26e4:\n"
        "movss 0x12c(%eax), %xmm0\n" /* line 699 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1c23e0_001c26fb\n"
        "subss %xmm0, %xmm1\n" /* line 700 */
        "movss %xmm1, (%edx)\n"
        "jmp .Lf1c23e0_001c26b1\n"
        ".Lf1c23e0_001c26fb:\n"
        "movl $0, (%edx)\n" /* line 702 */
        "jmp .Lf1c23e0_001c26b1\n"
        ".Lf1c23e0_001c2703:\n"
        "jp .Lf1c23e0_001c240c\n" /* line 664 */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movss %xmm1, 0x1c(%ebp)\n" /* radius */
        "movss 0x2ed9b4, %xmm1\n" /* 1.4142135381698608f */
        "jmp .Lf1c23e0_001c2417\n"
        ".Lf1c23e0_001c2723:\n"
        "leal 0x120(%ebx), %eax\n" /* line 728 | ent */
        "leal 0x12c(%ebx), %edx\n" /* ent */
        /* { scope 2 */
        "movss 0x120(%ebx), %xmm1\n" /* line 240 */
        "addss 0x12c(%ebx), %xmm1\n"
        "movss 4(%eax), %xmm2\n" /* line 241 */
        "addss 4(%edx), %xmm2\n"
        "movss 8(%eax), %xmm3\n" /* line 242 */
        "addss 8(%edx), %xmm3\n"
        /* } scope */
        "movss 0x2ed5d8, %xmm0\n" /* line 199 | 0.5f */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x54(%ebp)\n" /* dest */
        "mulss %xmm0, %xmm2\n" /* line 200 */
        "movss %xmm2, -0x50(%ebp)\n"
        "mulss %xmm0, %xmm3\n" /* line 201 */
        "movss %xmm3, -0x4c(%ebp)\n"
        "movl $0x811, 0x18(%esp)\n" /* line 737 */
        "movl $0x3ff, 0x14(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* dest */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* origin */
        "leal -0x78(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 738 | 1.0f */
        "ucomiss -0x78(%ebp), %xmm0\n" /* tr */
        "jbe .Lf1c23e0_001c264a\n"
        "movss -0x54(%ebp), %xmm2\n" /* line 248 | dest */
        "subss (%edi), %xmm2\n"
        "movss %xmm2, -0x54(%ebp)\n" /* dest */
        "movss -0x50(%ebp), %xmm1\n" /* line 249 */
        "subss 4(%edi), %xmm1\n"
        "movss %xmm1, -0x50(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 250 */
        "subss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "sqrtss %xmm2, %xmm2\n"
        "movss -0x108c(%ebp), %xmm1\n"
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf1c23e0_001c264a\n"
        "movl 0x10(%ebp), %eax\n" /* line 744 | attacker */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll LogAccuracyHit\n"
        "testl %eax, %eax\n"
        "movl $1, %eax\n"
        "cmovel -0x107c(%ebp), %eax\n" /* hitClient */
        "movl %eax, -0x107c(%ebp)\n" /* hitClient */
        "leal 0x138(%ebx), %eax\n" /* ent */
        /* { scope 2 */
        "movss 0x138(%ebx), %xmm0\n" /* line 248 */
        "subss (%edi), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* dir */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edi), %xmm0\n"
        /* } scope */
        "addss 0x2ed8b8, %xmm0\n" /* line 749 | 24.0f */
        "movss %xmm0, -0x40(%ebp)\n"
        "movl $0, 0x24(%esp)\n" /* line 750 */
        "movl $0, 0x20(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* mod */
        "movl %eax, 0x1c(%esp)\n"
        "movl $1, 0x18(%esp)\n"
        "movss -0x1088(%ebp), %xmm0\n" /* points */
        "mulss 0x2ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "jmp .Lf1c23e0_001c2621\n"
    );
}

/* line 282 */
__attribute__((naked))
void player_die(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int meansOfDeath, int iWeapon, const vec_t *vDir, const hitLocation_t hitLoc, int psTimeOffset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 282 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        /* { scope 1: dir */
        "movl 8(%ebp), %edx\n" /* line 292 | self */
        "movl 0x158(%edx), %eax\n"
        "movl 0xcc(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n"
        "je .Lf1c28a4_001c28da\n"
        "movl 8(%ebp), %ecx\n" /* line 298 | self */
        "movl 0x158(%ecx), %eax\n"
        "cmpl $1, 4(%eax)\n"
        "jbe .Lf1c28a4_001c28e5\n"
        /* } scope */
        ".Lf1c28a4_001c28da:\n"
        "addl $0x8c, %esp\n" /* line 374 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dir */
        ".Lf1c28a4_001c28e5:\n"
        "testb $0x40, 0xe(%eax)\n" /* line 298 */
        "jne .Lf1c28a4_001c28da\n"
        "movl 0x195f68c, %edx\n" /* line 301 */
        "movl 0x195edb4, %eax\n"
        "movl %edx, (%eax)\n"
        "movl 0x10(%ebp), %esi\n" /* line 304 | attacker, i */
        "cmpl $9, 4(%esi)\n" /* i */
        "je .Lf1c28a4_001c2c2d\n"
        ".Lf1c28a4_001c2905:\n"
        "movl %esi, (%esp)\n" /* line 308 | i */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 309 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0xa(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* self */
        "movl %eax, (%esp)\n"
        "calll Scr_Notify\n"
        "movl 0x1c(%ebp), %edx\n" /* line 312 | iWeapon */
        "testl %edx, %edx\n"
        "je .Lf1c28a4_001c2971\n"
        "movl 0x158(%esi), %eax\n" /* i */
        "testl %eax, %eax\n"
        "je .Lf1c28a4_001c2971\n"
        "testl $0x300, 0xa0(%eax)\n"
        "je .Lf1c28a4_001c2971\n"
        /* { scope 2 */
        "movl 0x74(%esi), %eax\n" /* line 314 | i */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n" /* mg42Ent */
        "subl %eax, %edx\n" /* mg42Ent */
        "shll $4, %edx\n" /* mg42Ent */
        "addl 0x195f688, %edx\n" /* mg42Ent */
        "cmpl $9, 4(%edx)\n" /* line 316 */
        "jne .Lf1c28a4_001c2971\n"
        "movl 0xc8(%edx), %edx\n" /* line 317 */
        "movl %edx, 0x1c(%ebp)\n" /* iWeapon */
        /* } scope */
        ".Lf1c28a4_001c2971:\n"
        "movl 8(%ebp), %ecx\n" /* line 321 | self */
        "movl 0x158(%ecx), %edx\n"
        "movl 0x3c(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1c28a4_001c2b7e\n"
        ".Lf1c28a4_001c2985:\n"
        "xorl %eax, %eax\n" /* line 333 */
        "cmpl $1, 4(%edx)\n"
        "sete %al\n"
        "addl $6, %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl $1, 0xc(%esp)\n" /* line 334 */
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* self */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_AnimScriptEvent\n"
        "movl %eax, 0x24(%esp)\n" /* line 337 */
        "movl 0x28(%ebp), %ecx\n" /* psTimeOffset */
        "movl %ecx, 0x20(%esp)\n"
        "movl 0x24(%ebp), %esi\n" /* hitLoc, i */
        "movl %esi, 0x1c(%esp)\n" /* i */
        "movl 0x20(%ebp), %eax\n" /* vDir */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x1c(%ebp), %edx\n" /* iWeapon */
        "movl %edx, 0x14(%esp)\n"
        "movl 0x18(%ebp), %ecx\n" /* meansOfDeath */
        "movl %ecx, 0x10(%esp)\n"
        "movl 0x14(%ebp), %esi\n" /* damage, i */
        "movl %esi, 0xc(%esp)\n" /* i */
        "movl 0x10(%ebp), %eax\n" /* attacker */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* inflictor */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* self */
        "movl %ecx, (%esp)\n"
        "calll Scr_PlayerKilled\n"
        "movl 0x195f6a0, %edx\n" /* line 341 */
        "movl 0x1e4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1c28a4_001c2a6a\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %ebx, %ebx\n"
        "movl 0x195f688, %edi\n"
        "movl %edx, -0x50(%ebp)\n"
        "jmp .Lf1c28a4_001c2a3a\n"
        ".Lf1c28a4_001c2a23:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x28a4, %ebx\n"
        "addl $0x230, %edi\n"
        "cmpl %esi, 0x1e4(%edx)\n" /* i */
        "jle .Lf1c28a4_001c2a6a\n"
        /* { scope 2 */
        ".Lf1c28a4_001c2a3a:\n"
        "movl %ebx, %eax\n" /* line 345 */
        "addl (%edx), %eax\n"
        "cmpl $2, 0x26c4(%eax)\n" /* line 346 */
        "jne .Lf1c28a4_001c2a23\n"
        "cmpl $2, 0x26a8(%eax)\n" /* line 349 */
        "jne .Lf1c28a4_001c2a23\n"
        "movl 0x27a8(%eax), %eax\n" /* line 352 */
        "movl 8(%ebp), %ecx\n" /* self */
        "cmpl (%ecx), %eax\n"
        "jne .Lf1c28a4_001c2a23\n"
        "movl %edi, (%esp)\n" /* line 353 */
        "calll Cmd_Score_f\n"
        "movl -0x50(%ebp), %edx\n"
        "jmp .Lf1c28a4_001c2a23\n"
        /* } scope */
        ".Lf1c28a4_001c2a6a:\n"
        "movl 8(%ebp), %esi\n" /* line 356 | self, i */
        "movb $1, 0x161(%esi)\n" /* i */
        "movl $0x4000000, 0x11c(%esi)\n" /* line 357 | i */
        "movl $0, 0x14c(%esi)\n" /* line 359 | i */
        /* { scope 2 */
        "movl 0x10(%ebp), %eax\n" /* line 210 | attacker */
        "testl %eax, %eax\n"
        "je .Lf1c28a4_001c2c5b\n"
        "cmpl %esi, 0x10(%ebp)\n" /* attacker */
        "je .Lf1c28a4_001c2c5b\n"
        "movl 0x10(%ebp), %eax\n" /* attacker */
        "addl $0x138, %eax\n"
        "movl %esi, %edx\n"
        "addl $0x138, %edx\n"
        /* { scope 3 */
        "movl 0x10(%ebp), %ecx\n" /* line 248 | attacker */
        "movss 0x138(%ecx), %xmm0\n"
        "subss 0x138(%esi), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* dir */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* self */
        /* } scope */
        ".Lf1c28a4_001c2ae5:\n"
        "movl 0x158(%eax), %esi\n" /* line 225 */
        "leal -0x3c(%ebp), %ebx\n" /* dir */
        "movl %ebx, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0x4c(%ebp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "movl %eax, 0x130(%esi)\n"
        "movl %ebx, (%esp)\n" /* line 227 */
        "calll vectoyaw\n"
        "fstp %st(0)\n"
        /* } scope */
        ".Lf1c28a4_001c2b0e:\n"
        "movl 8(%ebp), %ecx\n" /* line 362 | self, from */
        "movl 0x158(%ecx), %edx\n"
        "leal 0xe8(%edx), %ebx\n" /* to */
        "addl $0x144, %ecx\n" /* from */
        /* { scope 2 */
        "movl 8(%ebp), %esi\n" /* line 199 | self */
        "movl 0x144(%esi), %eax\n"
        "movl %eax, 0xe8(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "movl $0, 0x84(%esi)\n" /* line 363 | i */
        "movl %esi, (%esp)\n" /* line 365 | i */
        "calll SV_UnlinkEntity\n"
        "movl $0x41f00000, 0x118(%esi)\n" /* line 366 | i */
        "movl %esi, (%esp)\n" /* line 369 | i */
        "calll SV_LinkEntity\n"
        "movl $0, 0x194(%esi)\n" /* line 371 | i */
        "movb $0xb, 0x166(%esi)\n" /* line 373 | i */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 374 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dir */
        ".Lf1c28a4_001c2b7e:\n"
        "calll crandom\n" /* line 323 */
        "fstps -0x24(%ebp)\n" /* launchvel */
        "calll crandom\n" /* line 324 */
        "fstps -0x20(%ebp)\n"
        "calll randomf\n" /* line 325 */
        "fstps -0x5c(%ebp)\n"
        "movss -0x5c(%ebp), %xmm2\n"
        "movss 0x2ed9b8, %xmm1\n" /* line 272 | 160.0f */
        "movss -0x24(%ebp), %xmm0\n" /* launchvel */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* launchvel */
        "movss -0x20(%ebp), %xmm0\n" /* line 273 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss %xmm1, %xmm2\n" /* line 274 */
        "movss %xmm2, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* self */
        "addl $0x138, %edx\n"
        /* { scope 2 */
        "movl 8(%ebp), %esi\n" /* line 199 | self */
        "movl 0x138(%esi), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* launchspot */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        /* } scope */
        "movss 0x2ed73c, %xmm0\n" /* line 328 | 40.0f */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movl 0x158(%esi), %edx\n" /* line 329 | i */
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xd0(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* launchvel */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* launchspot */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll fire_grenade\n"
        "movl 0x158(%esi), %edx\n" /* i */
        "jmp .Lf1c28a4_001c2985\n"
        ".Lf1c28a4_001c2c2d:\n"
        "movl 0x150(%esi), %eax\n" /* line 304 | i */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1c28a4_001c2cb7\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 305 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl 0x195f688, %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, 0x10(%ebp)\n" /* attacker */
        "movl %edx, %esi\n" /* i */
        "jmp .Lf1c28a4_001c2905\n"
        /* { scope 2 */
        ".Lf1c28a4_001c2c5b:\n"
        "movl 0xc(%ebp), %eax\n" /* line 214 | inflictor */
        "testl %eax, %eax\n"
        "je .Lf1c28a4_001c2cbf\n"
        "movl 0xc(%ebp), %esi\n" /* inflictor */
        "cmpl %esi, 8(%ebp)\n" /* self */
        "je .Lf1c28a4_001c2cbf\n"
        "movl %esi, %eax\n"
        "addl $0x138, %eax\n"
        "movl 8(%ebp), %edx\n" /* self */
        "addl $0x138, %edx\n"
        /* { scope 3 */
        "movss 0x138(%esi), %xmm0\n" /* line 248 */
        "movl 8(%ebp), %ecx\n" /* self */
        "subss 0x138(%ecx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* dir */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf1c28a4_001c2ae5\n"
        ".Lf1c28a4_001c2cb7:\n"
        "movl 0x10(%ebp), %esi\n" /* attacker */
        "jmp .Lf1c28a4_001c2905\n"
        /* } scope */
        ".Lf1c28a4_001c2cbf:\n"
        "movl 8(%ebp), %esi\n" /* line 221 | self */
        "movl 0x158(%esi), %edx\n"
        "cvttss2si 0x148(%esi), %eax\n"
        "movl %eax, 0x130(%edx)\n"
        "jmp .Lf1c28a4_001c2b0e\n"
    );
}

