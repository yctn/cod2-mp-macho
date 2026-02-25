/* ASM dump from: offhandweapons_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/offhandweapons_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

static const char * offhandStrings[3]; /* 0x314500 */
static const dvar_t *hud_flash_time_offhand; /* 0xfdf304 */
static const dvar_t *hud_flash_period_offhand; /* 0xfdf300 */

void CG_OffhandRegisterDvars(void);
void CG_DrawOffHandName(rectDef_s *rect, struct Font_s *font, float scale, vec_t *color, int textStyle, int weaponType);
void CG_PrepOffHand(entityState_t *ent, int event, int eventParam);
void CG_UseOffHand(centity_t *cent, int event, int eventParam);
void CG_SetEquippedOffHand(int offHandIndex);
void CG_SwitchOffHandCmd(void);
void CG_DrawOffHandIcon(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType);
void CG_DrawOffHandHighlight(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType);
void CG_DrawOffHandAmmo(rectDef_s *rect, struct Font_s *font, float scale, vec_t *color, int textStyle, int weaponType);

/* line 30 */
__attribute__((naked))
void CG_OffhandRegisterDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 30 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 32 */
        "movl $0x41f00000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40000000, 4(%esp)\n"
        "movl $0x2b51e4, (%esp)\n" /* "hud_flash_time_offhand" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_flash_time_offhand\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 33 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f000000, 4(%esp)\n"
        "movl $0x2b51fc, (%esp)\n" /* "hud_flash_period_offhand" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_flash_period_offhand\n"
        "addl $0x20, %esp\n" /* line 34 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 251 */
__attribute__((naked))
void CG_DrawOffHandName(rectDef_s *rect, struct Font_s *font, float scale, vec_t *color, int textStyle, int weaponType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 251 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 58 */
        "movl (%eax), %esi\n"
        "cmpl $5, 0x25bc8(%esi)\n" /* line 259 */
        "jle .Lf1b2a9c_001b2abb\n"
        /* } scope */
        ".Lf1b2a9c_001b2ab4:\n"
        "addl $0x50, %esp\n" /* line 272 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b2a9c_001b2abb:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 44 | weaponType */
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstAvailableOffhand\n"
        "testl %eax, %eax\n" /* line 46 */
        "je .Lf1b2a9c_001b2baf\n"
        /* } scope */
        ".Lf1b2a9c_001b2ad8:\n"
        "movl 0x195f730, %eax\n" /* line 265 */
        "movl (%eax), %ebx\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%ebx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x20(%ebp)\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x2c5d0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CG_FadeHudMenu\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 265 */
        "movss %xmm0, -0xc(%ebp)\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 266 | 0.0f */
        "jp .Lf1b2a9c_001b2b34\n"
        "je .Lf1b2a9c_001b2ab4\n"
        ".Lf1b2a9c_001b2b34:\n"
        "movl 0x14(%ebp), %edx\n" /* line 199 | color */
        "movl (%edx), %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* drawColor */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x14(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x10(%ebp)\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 270 | weaponType */
        "movl offhandStrings(, %ecx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl 0x18(%ebp), %edx\n" /* line 271 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "leal -0x18(%ebp), %edx\n" /* drawColor */
        "movl %edx, 0x20(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* rect */
        "movl 0x14(%ecx), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl (%ecx), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 272 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b2a9c_001b2baf:\n"
        "movl 0x1c(%ebp), %edx\n" /* line 47 | weaponType */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstEquippedOffhand\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 262 */
        "je .Lf1b2a9c_001b2ab4\n"
        "jmp .Lf1b2a9c_001b2ad8\n"
    );
}

/* line 301 */
__attribute__((naked))
void CG_PrepOffHand(entityState_t *ent, int event, int eventParam)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 301 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x10(%ebp), %edx\n" /* eventParam */
        "movl 0x195f5c8, %eax\n" /* line 311 */
        "movl (%eax), %ecx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0xd8(%ecx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1b2bcc_001b2c01\n"
        "movl %eax, 4(%esp)\n" /* line 312 */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        ".Lf1b2bcc_001b2c01:\n"
        "leave\n" /* line 313 */
        "retl\n"
    );
}

/* line 319 */
__attribute__((naked))
void CG_UseOffHand(centity_t *cent, int event, int eventParam)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 319 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* cent */
        "movl 0x10(%ebp), %edx\n" /* eventParam */
        /* { scope 1 */
        "leal (%edx, %edx, 2), %eax\n" /* line 329 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x195f5c8, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* weapInfo */
        "movl 0xdc(%ebx), %eax\n" /* line 331 | weapInfo */
        "testl %eax, %eax\n"
        "je .Lf1b2c04_001b2ca7\n"
        "movl 0xf0(%edi), %edx\n" /* line 333 | cent */
        "movl 0x195f584, %eax\n"
        "movl (%eax), %esi\n"
        "movl 0x24(%esi), %eax\n"
        "cmpl 0xd8(%eax), %edx\n"
        "je .Lf1b2c04_001b2caf\n"
        "movl 0x220(%edi), %eax\n" /* line 341 | cent */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 342 */
        "je .Lf1b2c04_001b2cd8\n"
        "leal -0x24(%ebp), %eax\n" /* origin */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x8c(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cent */
        "calll CG_DObjGetWorldTagPos\n"
        "testl %eax, %eax\n"
        "je .Lf1b2c04_001b2cd8\n"
        ".Lf1b2c04_001b2c88:\n"
        "movl 0xdc(%ebx), %eax\n" /* line 346 | weapInfo */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* origin */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        /* } scope */
        ".Lf1b2c04_001b2ca7:\n"
        "addl $0x2c, %esp\n" /* line 348 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b2c04_001b2caf:\n"
        "movl (%ebx), %edx\n" /* line 335 | weapInfo */
        "testl %edx, %edx\n" /* line 336 */
        "je .Lf1b2c04_001b2cd8\n"
        "leal -0x24(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x8c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_DObjGetViewModelTagPos\n"
        "testl %eax, %eax\n"
        "jne .Lf1b2c04_001b2c88\n"
        ".Lf1b2c04_001b2cd8:\n"
        "leal -0x24(%ebp), %eax\n" /* line 343 | origin */
        "movl %eax, 8(%esp)\n"
        "movl 0x25bb0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xfc(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl 0xdc(%ebx), %eax\n" /* line 346 | weapInfo */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* origin */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "jmp .Lf1b2c04_001b2ca7\n"
    );
}

/* line 354 */
__attribute__((naked))
void CG_SetEquippedOffHand(int offHandIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 354 */
        "movl %esp, %ebp\n"
        "movl 0x195f584, %eax\n" /* line 358 */
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* offHandIndex */
        "movl %eax, 0x2be70(%edx)\n"
        "movl $4, 8(%ebp)\n" /* line 359 | offHandIndex */
        "popl %ebp\n" /* line 360 */
        "jmp CG_MenuShowNotify\n" /* line 359 */
    );
}

/* line 279 */
__attribute__((naked))
void CG_SwitchOffHandCmd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 279 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 284 */
        "movl (%eax), %ebx\n"
        "movl 0x2be70(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1b2d38_001b2d56\n"
        /* } scope */
        ".Lf1b2d38_001b2d50:\n"
        "addl $0x14, %esp\n" /* line 295 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b2d38_001b2d56:\n"
        "movl %eax, (%esp)\n" /* line 287 */
        "calll BG_GetWeaponDef\n"
        "movl 0x84(%eax), %eax\n" /* line 291 */
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetFirstAvailableOffhand\n"
        "testl %eax, %eax\n" /* line 293 */
        "je .Lf1b2d38_001b2d50\n"
        "movl %eax, 0x2be70(%ebx)\n" /* line 358 */
        "movl $4, (%esp)\n" /* line 359 */
        "calll CG_MenuShowNotify\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 295 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 68 */
__attribute__((naked))
void CG_DrawOffHandIcon(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 68 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0x18(%ebp), %edi\n" /* weaponType */
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 58 */
        "movl (%eax), %esi\n"
        "cmpl $5, 0x25bc8(%esi)\n" /* line 80 */
        "jle .Lf1b2d92_001b2db6\n"
        /* } scope */
        ".Lf1b2d92_001b2dae:\n"
        "addl $0x4c, %esp\n" /* line 109 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b2d92_001b2db6:\n"
        "movl %edi, 4(%esp)\n" /* line 44 */
        "leal 0x25bc4(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstAvailableOffhand\n"
        "testl %eax, %eax\n" /* line 46 */
        "je .Lf1b2d92_001b2f01\n"
        /* } scope */
        ".Lf1b2d92_001b2dd0:\n"
        "movl 0x195f730, %eax\n" /* line 86 */
        "movl (%eax), %ebx\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%ebx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x30(%ebp)\n"
        "cvttss2si -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x2c5d0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CG_FadeHudMenu\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 86 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 87 | 0.0f */
        "jp .Lf1b2d92_001b2e2c\n"
        "je .Lf1b2d92_001b2dae\n"
        ".Lf1b2d92_001b2e2c:\n"
        "movl 0x10(%ebp), %edx\n" /* line 199 | color */
        "movl (%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* drawColor */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x2be70(%esi), %eax\n" /* line 93 */
        "testl %eax, %eax\n"
        "jne .Lf1b2d92_001b2ec3\n"
        ".Lf1b2d92_001b2e4a:\n"
        "movl %edi, 4(%esp)\n" /* line 44 */
        "movl 0x195f584, %eax\n"
        "movl (%eax), %ebx\n"
        "addl $0x25bc4, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstAvailableOffhand\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 46 */
        "je .Lf1b2d92_001b2ee6\n"
        ".Lf1b2d92_001b2e69:\n"
        "movl 0x195f5c8, %eax\n" /* line 108 */
        "movl (%eax), %edx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x138(%edx, %eax, 4), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* drawColor */
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%ebp), %edx\n" /* rect */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 109 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b2d92_001b2ec3:\n"
        "movl %eax, (%esp)\n" /* line 95 */
        "calll BG_GetWeaponDef\n"
        "cmpl 0x84(%eax), %edi\n" /* line 96 | weaponType */
        "jne .Lf1b2d92_001b2e4a\n"
        "movl 0x2be70(%esi), %ecx\n" /* line 97 */
        "testl %ecx, %ecx\n" /* line 100 */
        "jne .Lf1b2d92_001b2e69\n"
        "jmp .Lf1b2d92_001b2e4a\n"
        ".Lf1b2d92_001b2ee6:\n"
        "movl %edi, 4(%esp)\n" /* line 47 */
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstEquippedOffhand\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 103 */
        "je .Lf1b2d92_001b2dae\n"
        "jmp .Lf1b2d92_001b2e69\n"
        /* { scope 2 */
        ".Lf1b2d92_001b2f01:\n"
        "movl %edi, 4(%esp)\n" /* line 47 */
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstEquippedOffhand\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 83 */
        "je .Lf1b2d92_001b2dae\n"
        "jmp .Lf1b2d92_001b2dd0\n"
    );
}

/* line 173 */
__attribute__((naked))
void CG_DrawOffHandHighlight(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 173 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1: ammoCount, weapCount */
        "movl 0x195f584, %edi\n" /* line 58 */
        "movl (%edi), %esi\n"
        "cmpl $5, 0x25bc8(%esi)\n" /* line 184 */
        "jle .Lf1b2f1a_001b2f3c\n"
        /* } scope */
        ".Lf1b2f1a_001b2f34:\n"
        "addl $0x5c, %esp\n" /* line 209 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ammoCount, weapCount */
        /* { scope 2 */
        ".Lf1b2f1a_001b2f3c:\n"
        "movl 0x18(%ebp), %eax\n" /* line 44 | weaponType */
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstAvailableOffhand\n"
        "testl %eax, %eax\n" /* line 46 */
        "je .Lf1b2f1a_001b303b\n"
        /* } scope */
        ".Lf1b2f1a_001b2f59:\n"
        "movl 0x2be70(%esi), %ebx\n" /* line 190 */
        "testl %ebx, %ebx\n"
        "je .Lf1b2f1a_001b2f34\n"
        "movl 0x195f730, %eax\n" /* line 193 */
        "movl (%eax), %ebx\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%ebx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x38(%ebp)\n"
        "cvttss2si -0x38(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x2c5d0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CG_FadeHudMenu\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 194 */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1b2f1a_001b2fbe\n"
        "je .Lf1b2f1a_001b2f34\n"
        ".Lf1b2f1a_001b2fbe:\n"
        "movl 0x2be70(%esi), %eax\n" /* line 197 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x18(%ebp), %edx\n" /* line 199 | weaponType */
        "cmpl 0x84(%eax), %edx\n"
        "jne .Lf1b2f1a_001b2f34\n"
        /* { scope 2 */
        "calll BG_GetNumWeapons\n" /* line 152 */
        "movl %eax, -0x30(%ebp)\n" /* weapCount */
        "testl %eax, %eax\n" /* line 154 */
        "jle .Lf1b2f1a_001b305a\n"
        "movl $1, %ebx\n"
        "movl $0, -0x34(%ebp)\n" /* ammoCount */
        "movl %edi, %edx\n"
        "jmp .Lf1b2f1a_001b3003\n"
        ".Lf1b2f1a_001b2ff7:\n"
        "addl $1, %ebx\n"
        "cmpl %ebx, -0x30(%ebp)\n" /* weapCount */
        "jl .Lf1b2f1a_001b30ea\n"
        ".Lf1b2f1a_001b3003:\n"
        "movl %ebx, %eax\n" /* line 156 */
        "sarl $5, %eax\n"
        "movl (%edx), %esi\n"
        "movl %ebx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1b2f1a_001b2ff7\n"
        "movl %ebx, (%esp)\n" /* line 159 */
        "calll BG_GetWeaponDef\n"
        "movl 0x18(%ebp), %ecx\n" /* line 162 | weaponType */
        "cmpl 0x84(%eax), %ecx\n"
        "je .Lf1b2f1a_001b314a\n"
        ".Lf1b2f1a_001b3033:\n"
        "movl 0x195f584, %edx\n"
        "jmp .Lf1b2f1a_001b2ff7\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1b2f1a_001b303b:\n"
        "movl 0x18(%ebp), %edx\n" /* line 47 | weaponType */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstEquippedOffhand\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 187 */
        "jne .Lf1b2f1a_001b2f59\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 209 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b2f1a_001b305a:\n"
        "movl %edi, %edx\n"
        /* { scope 1: ammoCount, weapCount */
        ".Lf1b2f1a_001b305c:\n"
        "movl $0x3c23d70a, %ebx\n" /* line 202 */
        "movl $0x3e3851ec, %ecx\n"
        "movl $0x3f63d70a, %eax\n"
        /* { scope 2 */
        ".Lf1b2f1a_001b306b:\n"
        "movl %eax, -0x28(%ebp)\n" /* line 456 | flashColor */
        "movl %ecx, -0x24(%ebp)\n" /* line 457 */
        "movl %ebx, -0x20(%ebp)\n" /* line 458 */
        "movss -0x2c(%ebp), %xmm0\n" /* line 459 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl (%edx), %edx\n" /* line 128 */
        "movl 0x25bb0(%edx), %eax\n"
        "subl 0x2c5d4(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss 0x2ed5c8, %xmm1\n" /* 1000.0f */
        "movl hud_flash_time_offhand, %eax\n" /* line 129 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1b2f1a_001b3107\n"
        /* } scope */
        ".Lf1b2f1a_001b30a7:\n"
        "movl 0x14(%ebp), %eax\n" /* line 208 | material */
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* flashColor */
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%ebp), %edx\n" /* rect */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf1b2f1a_001b2f34\n"
        ".Lf1b2f1a_001b30ea:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 202 | ammoCount */
        "testl %ecx, %ecx\n"
        "je .Lf1b2f1a_001b305c\n"
        "movl 0x10(%ebp), %ecx\n" /* line 199 | color */
        "movl (%ecx), %eax\n"
        "movl %ecx, %ebx\n" /* line 200 */
        "movl 4(%ecx), %ecx\n"
        "movl 8(%ebx), %ebx\n" /* line 201 */
        "jmp .Lf1b2f1a_001b306b\n"
        /* { scope 2 */
        ".Lf1b2f1a_001b3107:\n"
        "mulss 0x2ed9a4, %xmm1\n" /* line 133 | 6.2831854820251465f */
        "movl hud_flash_period_offhand, %eax\n"
        "divss 8(%eax), %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll cosf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "jmp .Lf1b2f1a_001b30a7\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1b2f1a_001b314a:\n"
        "movl %ebx, (%esp)\n" /* line 163 */
        "calll BG_ClipForWeapon\n"
        "movl 0x25f08(%esi, %eax, 4), %edx\n"
        "addl %edx, -0x34(%ebp)\n" /* ammoCount */
        "jmp .Lf1b2f1a_001b3033\n"
    );
}

/* line 215 */
__attribute__((naked))
void CG_DrawOffHandAmmo(rectDef_s *rect, struct Font_s *font, float scale, vec_t *color, int textStyle, int weaponType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 215 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 58 */
        "movl (%eax), %esi\n"
        "cmpl $5, 0x25bc8(%esi)\n" /* line 226 */
        "jle .Lf1b3162_001b3183\n"
        /* } scope */
        ".Lf1b3162_001b317b:\n"
        "addl $0x5c, %esp\n" /* line 245 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b3162_001b3183:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 44 | weaponType */
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstAvailableOffhand\n"
        "testl %eax, %eax\n" /* line 46 */
        "je .Lf1b3162_001b32f0\n"
        /* } scope */
        ".Lf1b3162_001b31a0:\n"
        "movl 0x195f730, %eax\n" /* line 232 */
        "movl (%eax), %ebx\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%ebx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x34(%ebp)\n"
        "cvttss2si -0x34(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x2c5d0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CG_FadeHudMenu\n"
        "fstps -0x30(%ebp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 232 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 233 | 0.0f */
        "jp .Lf1b3162_001b3200\n"
        "je .Lf1b3162_001b317b\n"
        /* { scope 2 */
        ".Lf1b3162_001b3200:\n"
        "calll BG_GetNumWeapons\n" /* line 152 */
        "movl %eax, %edi\n" /* weapCount */
        "testl %eax, %eax\n" /* line 154 */
        "jle .Lf1b3162_001b325e\n"
        "movl $1, %ebx\n"
        "movl $0, -0x2c(%ebp)\n" /* ammoCount */
        "jmp .Lf1b3162_001b3220\n"
        ".Lf1b3162_001b3219:\n"
        "addl $1, %ebx\n"
        "cmpl %ebx, %edi\n" /* weapCount */
        "jl .Lf1b3162_001b3265\n"
        ".Lf1b3162_001b3220:\n"
        "movl %ebx, %eax\n" /* line 156 */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1b3162_001b3219\n"
        "movl %ebx, (%esp)\n" /* line 159 */
        "calll BG_GetWeaponDef\n"
        "movl 0x1c(%ebp), %edx\n" /* line 162 | weaponType */
        "cmpl 0x84(%eax), %edx\n"
        "jne .Lf1b3162_001b3219\n"
        "movl %ebx, (%esp)\n" /* line 163 */
        "calll BG_ClipForWeapon\n"
        "movl 0x25f08(%esi, %eax, 4), %ecx\n"
        "addl %ecx, -0x2c(%ebp)\n" /* ammoCount */
        "jmp .Lf1b3162_001b3219\n"
        ".Lf1b3162_001b325e:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 154 | ammoCount */
        /* } scope */
        ".Lf1b3162_001b3265:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 237 | ammoCount */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, %edx\n"
        "movl -0x2c(%ebp), %esi\n" /* line 239 | ammoCount */
        "testl %esi, %esi\n"
        "jne .Lf1b3162_001b330c\n"
        "movl $0x3f63d70a, -0x28(%ebp)\n" /* line 191 | drawColor */
        "movl $0x3e3851ec, -0x24(%ebp)\n" /* line 192 */
        "movl $0x3c23d70a, -0x20(%ebp)\n" /* line 193 */
        ".Lf1b3162_001b329a:\n"
        "movl 0x18(%ebp), %eax\n" /* line 244 | textStyle */
        "movl %eax, 0x24(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* drawColor */
        "movl %eax, 0x20(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* rect */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 245 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b3162_001b32f0:\n"
        "movl 0x1c(%ebp), %edx\n" /* line 47 | weaponType */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll BG_GetFirstEquippedOffhand\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 229 */
        "je .Lf1b3162_001b317b\n"
        "jmp .Lf1b3162_001b31a0\n"
        ".Lf1b3162_001b330c:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 199 | color */
        "movl (%ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* drawColor */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x20(%ebp)\n"
        "jmp .Lf1b3162_001b329a\n"
    );
}

