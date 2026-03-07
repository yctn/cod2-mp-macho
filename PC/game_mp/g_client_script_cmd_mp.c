/* ASM dump from: g_client_script_cmd_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_client_script_cmd_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

/* player_methods[] defined at end of file */

void PlayerCmd_takeWeapon(struct scr_entref_t entref);
void PlayerCmd_takeAllWeapons(scr_entref_t entref);
static void PlayerCmd_setAngles(scr_entref_t entref);
static void PlayerCmd_getAngles(scr_entref_t entref);
void PlayerCmd_useButtonPressed(scr_entref_t entref);
void PlayerCmd_attackButtonPressed(scr_entref_t entref);
void PlayerCmd_meleeButtonPressed(scr_entref_t entref);
void PlayerCmd_playerADS(scr_entref_t entref);
void PlayerCmd_isOnGround(scr_entref_t entref);
void PlayerCmd_pingPlayer(scr_entref_t entref);
static void PlayerCmd_SetViewmodel(scr_entref_t entref);
static void PlayerCmd_GetViewmodel(scr_entref_t entref);
static void PlayerCmd_showScoreboard(scr_entref_t entref);
static void PlayerCmd_setSpawnWeapon(scr_entref_t entref);
static void PlayerCmd_dropItem(scr_entref_t entref);
static void PlayerCmd_Suicide(scr_entref_t entref);
static void PlayerCmd_OpenMenu(scr_entref_t entref);
static void PlayerCmd_OpenMenuNoMouse(scr_entref_t entref);
static void PlayerCmd_CloseMenu(scr_entref_t entref);
static void PlayerCmd_CloseInGameMenu(scr_entref_t entref);
static void PlayerCmd_SetWeaponSlotWeapon(scr_entref_t entref);
static void PlayerCmd_SetWeaponSlotAmmo(scr_entref_t entref);
static void PlayerCmd_GetWeaponSlotClipAmmo(scr_entref_t entref);
static void PlayerCmd_SetWeaponSlotClipAmmo(scr_entref_t entref);
static void PlayerCmd_SetWeaponClipAmmo(scr_entref_t entref);
static void iclientprintln(scr_entref_t entref);
static void iclientprintlnbold(scr_entref_t entref);
void PlayerCmd_spawn(scr_entref_t entref);
static void PlayerCmd_setEnterTime(scr_entref_t entref);
void BodyEnd(gentity_t *ent);
static void PlayerCmd_SetClientDvar(scr_entref_t entref);
static void PlayerCmd_IsTalking(scr_entref_t entref);
static void PlayerCmd_FreezeControls(scr_entref_t entref);
static void PlayerCmd_DisableWeapon(scr_entref_t entref);
static void PlayerCmd_EnableWeapon(scr_entref_t entref);
static void PlayerCmd_SetReverb(scr_entref_t entref);
static void PlayerCmd_DeactivateReverb(scr_entref_t entref);
static void PlayerCmd_SetChannelVolumes(scr_entref_t entref);
static void PlayerCmd_DeactivateChannelVolumes(scr_entref_t entref);
static void ScrCmd_IsLookingAt(scr_entref_t entref);
static void ScrCmd_PlayLocalSound(scr_entref_t entref);
static void PlayerCmd_SayAll(scr_entref_t entref);
static void PlayerCmd_SayTeam(scr_entref_t entref);
static void PlayerCmd_AllowSpectateTeam(scr_entref_t entref);
static void PlayerCmd_GetGuid(scr_entref_t entref);
BuiltinMethod Player_GetMethod(const char * *pName);
void PlayerCmd_giveWeapon(scr_entref_t entref);
void PlayerCmd_hasWeapon(scr_entref_t entref);
void PlayerCmd_switchToWeapon(scr_entref_t entref);
void PlayerCmd_switchToOffhand(scr_entref_t entref);
void PlayerCmd_giveStartAmmo(scr_entref_t entref);
void PlayerCmd_giveMaxAmmo(scr_entref_t entref);
void PlayerCmd_getFractionStartAmmo(scr_entref_t entref);
void PlayerCmd_getFractionMaxAmmo(scr_entref_t entref);
static void PlayerCmd_setOrigin(scr_entref_t entref);
static void PlayerCmd_finishPlayerDamage(scr_entref_t entref);
static void PlayerCmd_ClonePlayer(scr_entref_t entref);
void PlayerCmd_getCurrentWeapon(scr_entref_t entref);
void PlayerCmd_getCurrentOffhand(scr_entref_t entref);
static void PlayerCmd_GetWeaponSlotWeapon(scr_entref_t entref);
static void PlayerCmd_GetWeaponSlotAmmo(scr_entref_t entref);

/* line 69 */
__attribute__((naked))
void PlayerCmd_takeWeapon(struct scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 74 */
        "testw %ax, %ax\n"
        "jne .Lf1bda10_001bdaae\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %edi\n" /* pSelf */
        "subl %eax, %edi\n" /* pSelf */
        "shll $4, %edi\n" /* pSelf */
        "addl imp_g_entities, %edi\n" /* pSelf */
        "movl 0x158(%edi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bda10_001bdabe\n"
        ".Lf1bda10_001bda4c:\n"
        "movl $0, (%esp)\n" /* line 76 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 77 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %ebx\n" /* iWeaponIndex */
        "movl 0x158(%edi), %esi\n" /* line 80 | pSelf */
        "movl %eax, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "movl $0, 0x144(%esi, %eax, 4)\n"
        "movl 0x158(%edi), %esi\n" /* line 81 | pSelf */
        "movl %ebx, (%esp)\n" /* iWeaponIndex */
        "calll BG_ClipForWeapon\n"
        "movl $0, 0x344(%esi, %eax, 4)\n"
        "movl %ebx, 4(%esp)\n" /* line 84 | iWeaponIndex */
        "movl 0x158(%edi), %eax\n" /* pSelf */
        "movl %eax, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 85 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bda10_001bdaae:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 74 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n" /* pSelf */
        "jmp .Lf1bda10_001bda4c\n"
        ".Lf1bda10_001bdabe:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bda10_001bda4c\n"
    );
}

/* line 93 */
__attribute__((naked))
void PlayerCmd_takeAllWeapons(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 93 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 97 */
        "testw %ax, %ax\n"
        "jne .Lf1bdadc_001bdb87\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %edi\n" /* pSelf */
        "subl %eax, %edi\n" /* pSelf */
        "shll $4, %edi\n" /* pSelf */
        "addl imp_g_entities, %edi\n" /* pSelf */
        "movl 0x158(%edi), %ecx\n" /* pSelf */
        "testl %ecx, %ecx\n"
        "je .Lf1bdadc_001bdb97\n"
        ".Lf1bdadc_001bdb18:\n"
        "movl 0x158(%edi), %eax\n" /* line 100 | pSelf */
        "movl $0, 0xd4(%eax)\n"
        "movl $1, %esi\n" /* iWeaponIndex */
        "jmp .Lf1bdadc_001bdb76\n"
        ".Lf1bdadc_001bdb2f:\n"
        "movl 0x158(%edi), %ebx\n" /* line 105 | pSelf */
        "movl %esi, (%esp)\n" /* iWeaponIndex */
        "calll BG_AmmoForWeapon\n"
        "movl $0, 0x144(%ebx, %eax, 4)\n"
        "movl 0x158(%edi), %ebx\n" /* line 106 | pSelf */
        "movl %esi, (%esp)\n" /* iWeaponIndex */
        "calll BG_ClipForWeapon\n"
        "movl $0, 0x344(%ebx, %eax, 4)\n"
        "movl %esi, 4(%esp)\n" /* line 109 | iWeaponIndex */
        "movl 0x158(%edi), %eax\n" /* pSelf */
        "movl %eax, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        "addl $1, %esi\n" /* line 102 | iWeaponIndex */
        ".Lf1bdadc_001bdb76:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %esi\n" /* iWeaponIndex */
        "jle .Lf1bdadc_001bdb2f\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 111 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bdadc_001bdb87:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 97 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n" /* pSelf */
        "jmp .Lf1bdadc_001bdb18\n"
        ".Lf1bdadc_001bdb97:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bdadc_001bdb18\n"
    );
}

/* line 438 */
static __attribute__((naked))
void PlayerCmd_setAngles(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 438 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 442 */
        "testw %ax, %ax\n"
        "jne .Lf1bdbb4_001bdc11\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %ebx\n" /* pSelf */
        "testl %ebx, %ebx\n"
        "je .Lf1bdbb4_001bdc45\n"
        "leal -0x14(%ebp), %ebx\n" /* line 444 | angles */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, 4(%esp)\n" /* line 446 */
        "movl %esi, (%esp)\n" /* pSelf */
        "calll SetClientViewAngle\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 447 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bdbb4_001bdc11:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 442 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "leal -0x14(%ebp), %ebx\n" /* line 444 | angles */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, 4(%esp)\n" /* line 446 */
        "movl %esi, (%esp)\n" /* pSelf */
        "calll SetClientViewAngle\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 447 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bdbb4_001bdc45:\n"
        "movl %edx, 4(%esp)\n" /* line 442 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "leal -0x14(%ebp), %ebx\n" /* line 444 | angles */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, 4(%esp)\n" /* line 446 */
        "movl %esi, (%esp)\n" /* pSelf */
        "calll SetClientViewAngle\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 447 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 455 */
static __attribute__((naked))
void PlayerCmd_getAngles(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 455 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 457 */
        "testw %ax, %ax\n"
        "jne .Lf1bdc84_001bdcd2\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bdc84_001bdcf8\n"
        "movl 0x158(%ebx), %eax\n" /* line 459 | pSelf */
        "addl $0xe8, %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 460 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddVector\n" /* line 459 */
        ".Lf1bdc84_001bdcd2:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 457 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* line 459 | pSelf */
        "addl $0xe8, %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 460 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddVector\n" /* line 459 */
        ".Lf1bdc84_001bdcf8:\n"
        "movl %edx, 4(%esp)\n" /* line 457 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl 0x158(%ebx), %eax\n" /* line 459 | pSelf */
        "addl $0xe8, %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 460 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddVector\n" /* line 459 */
    );
}

/* line 468 */
__attribute__((naked))
void PlayerCmd_useButtonPressed(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 468 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 470 */
        "testw %ax, %ax\n"
        "jne .Lf1bdd28_001bdd96\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bdd28_001bdda6\n"
        ".Lf1bdd28_001bdd5e:\n"
        "movl 0x158(%ebx), %edx\n" /* line 472 | pSelf */
        "movl 0x27c8(%edx), %eax\n"
        "orl 0x27bc(%edx), %eax\n"
        "testb $0x28, %al\n"
        "je .Lf1bdd28_001bdd85\n"
        "movl $1, 8(%ebp)\n" /* line 473 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 476 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 473 */
        ".Lf1bdd28_001bdd85:\n"
        "movl $0, 8(%ebp)\n" /* line 475 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 476 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 475 */
        ".Lf1bdd28_001bdd96:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 470 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1bdd28_001bdd5e\n"
        ".Lf1bdd28_001bdda6:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bdd28_001bdd5e\n"
    );
}

/* line 484 */
__attribute__((naked))
void PlayerCmd_attackButtonPressed(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 484 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 486 */
        "testw %ax, %ax\n"
        "jne .Lf1bddc0_001bde2e\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bddc0_001bde3e\n"
        ".Lf1bddc0_001bddf6:\n"
        "movl 0x158(%ebx), %edx\n" /* line 488 | pSelf */
        "movl 0x27c8(%edx), %eax\n"
        "orl 0x27bc(%edx), %eax\n"
        "testb $1, %al\n"
        "je .Lf1bddc0_001bde1d\n"
        "movl $1, 8(%ebp)\n" /* line 489 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 492 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 489 */
        ".Lf1bddc0_001bde1d:\n"
        "movl $0, 8(%ebp)\n" /* line 491 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 492 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 491 */
        ".Lf1bddc0_001bde2e:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 486 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1bddc0_001bddf6\n"
        ".Lf1bddc0_001bde3e:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bddc0_001bddf6\n"
    );
}

/* line 500 */
__attribute__((naked))
void PlayerCmd_meleeButtonPressed(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 500 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 502 */
        "testw %ax, %ax\n"
        "jne .Lf1bde58_001bdec6\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bde58_001bded6\n"
        ".Lf1bde58_001bde8e:\n"
        "movl 0x158(%ebx), %edx\n" /* line 504 | pSelf */
        "movl 0x27c8(%edx), %eax\n"
        "orl 0x27bc(%edx), %eax\n"
        "testb $4, %al\n"
        "je .Lf1bde58_001bdeb5\n"
        "movl $1, 8(%ebp)\n" /* line 505 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 508 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 505 */
        ".Lf1bde58_001bdeb5:\n"
        "movl $0, 8(%ebp)\n" /* line 507 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 508 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 507 */
        ".Lf1bde58_001bdec6:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 502 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1bde58_001bde8e\n"
        ".Lf1bde58_001bded6:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bde58_001bde8e\n"
    );
}

/* line 516 */
__attribute__((naked))
void PlayerCmd_playerADS(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 516 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 518 */
        "testw %ax, %ax\n"
        "jne .Lf1bdef0_001bdf3f\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bdef0_001bdf66\n"
        "movl 0x158(%ebx), %eax\n" /* line 520 | pSelf */
        "movl 0xdc(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 521 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 520 */
        ".Lf1bdef0_001bdf3f:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 518 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* line 520 | pSelf */
        "movl 0xdc(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 521 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 520 */
        ".Lf1bdef0_001bdf66:\n"
        "movl %edx, 4(%esp)\n" /* line 518 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl 0x158(%ebx), %eax\n" /* line 520 | pSelf */
        "movl 0xdc(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 521 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 520 */
    );
}

/* line 529 */
__attribute__((naked))
void PlayerCmd_isOnGround(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 529 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 531 */
        "testw %ax, %ax\n"
        "jne .Lf1bdf98_001bdfee\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bdf98_001be01c\n"
        ".Lf1bdf98_001bdfce:\n"
        "movl 0x158(%ebx), %eax\n" /* line 533 | pSelf */
        "cmpl $0x3ff, 0x60(%eax)\n"
        "je .Lf1bdf98_001be00b\n"
        ".Lf1bdf98_001bdfdd:\n"
        "movl $1, 8(%ebp)\n" /* line 534 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 537 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 534 */
        ".Lf1bdf98_001bdfee:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 531 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* line 533 | pSelf */
        "cmpl $0x3ff, 0x60(%eax)\n"
        "jne .Lf1bdf98_001bdfdd\n"
        ".Lf1bdf98_001be00b:\n"
        "movl $0, 8(%ebp)\n" /* line 536 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 537 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 536 */
        ".Lf1bdf98_001be01c:\n"
        "movl %edx, 4(%esp)\n" /* line 531 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bdf98_001bdfce\n"
    );
}

/* line 545 */
__attribute__((naked))
void PlayerCmd_pingPlayer(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 545 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 547 */
        "testw %ax, %ax\n"
        "jne .Lf1be036_001be09e\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %ecx\n" /* pSelf */
        "testl %ecx, %ecx\n"
        "je .Lf1be036_001be0ae\n"
        ".Lf1be036_001be06c:\n"
        "movl 0x158(%ebx), %eax\n" /* line 549 | pSelf */
        "orl $0x00400000, 0xa0(%eax)\n"
        "movl 0x158(%ebx), %edx\n" /* line 550 | pSelf */
        "movl imp_level, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "addl $0xbb8, %eax\n"
        "movl %eax, 0x283c(%edx)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 551 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1be036_001be09e:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 547 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1be036_001be06c\n"
        ".Lf1be036_001be0ae:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be036_001be06c\n"
    );
}

/* line 559 */
static __attribute__((naked))
void PlayerCmd_SetViewmodel(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 559 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 564 */
        "testw %ax, %ax\n"
        "jne .Lf1be0c8_001be145\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %ebx\n" /* pSelf, modelName */
        "testl %ebx, %ebx\n" /* modelName */
        "je .Lf1be0c8_001be155\n"
        ".Lf1be0c8_001be0ff:\n"
        "movl $0, (%esp)\n" /* line 566 */
        "calll Scr_GetString\n"
        "movl %eax, %ebx\n" /* modelName */
        "testl %eax, %eax\n" /* line 567 */
        "je .Lf1be0c8_001be116\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1be0c8_001be12a\n"
        ".Lf1be0c8_001be116:\n"
        "movl $str_002b5df0, 4(%esp)\n" /* line 568 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf1be0c8_001be12a:\n"
        "movl %ebx, (%esp)\n" /* line 569 | modelName */
        "calll G_ModelIndex\n"
        "movl 0x158(%esi), %edx\n" /* line 573 | pSelf */
        "movl %eax, 0x273c(%edx)\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 574 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1be0c8_001be145:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 564 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1be0c8_001be0ff\n"
        ".Lf1be0c8_001be155:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be0c8_001be0ff\n"
    );
}

/* line 582 */
static __attribute__((naked))
void PlayerCmd_GetViewmodel(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 582 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 586 */
        "testw %ax, %ax\n"
        "jne .Lf1be170_001be1c7\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1be170_001be1f6\n"
        "movl 0x158(%ebx), %eax\n" /* line 588 | pSelf */
        "movl 0x273c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, 8(%ebp)\n" /* line 589 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 590 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 589 */
        ".Lf1be170_001be1c7:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 586 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* line 588 | pSelf */
        "movl 0x273c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, 8(%ebp)\n" /* line 589 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 590 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 589 */
        ".Lf1be170_001be1f6:\n"
        "movl %edx, 4(%esp)\n" /* line 586 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl 0x158(%ebx), %eax\n" /* line 588 | pSelf */
        "movl 0x273c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, 8(%ebp)\n" /* line 589 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 590 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 589 */
    );
}

/* line 598 */
static __attribute__((naked))
void PlayerCmd_showScoreboard(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 598 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 600 */
        "testw %ax, %ax\n"
        "jne .Lf1be230_001be273\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1be230_001be28e\n"
        "movl %ebx, 8(%ebp)\n" /* line 602 | pSelf, entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 603 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Cmd_Score_f\n" /* line 602 */
        ".Lf1be230_001be273:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 600 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl %ebx, 8(%ebp)\n" /* line 602 | pSelf, entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 603 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Cmd_Score_f\n" /* line 602 */
        ".Lf1be230_001be28e:\n"
        "movl %edx, 4(%esp)\n" /* line 600 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl %ebx, 8(%ebp)\n" /* line 602 | pSelf, entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 603 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Cmd_Score_f\n" /* line 602 */
    );
}

/* line 611 */
static __attribute__((naked))
void PlayerCmd_setSpawnWeapon(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 611 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 616 */
        "testw %ax, %ax\n"
        "jne .Lf1be2b4_001be33a\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1be2b4_001be34a\n"
        ".Lf1be2b4_001be2eb:\n"
        "movl $0, (%esp)\n" /* line 618 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 619 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %esi\n" /* iWeaponIndex */
        "movl %eax, 4(%esp)\n" /* line 622 */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "movl %eax, (%esp)\n"
        "calll BG_IsWeaponValid\n"
        "testb %al, %al\n"
        "je .Lf1be2b4_001be333\n"
        "movl 0x158(%ebx), %eax\n" /* line 624 | pSelf */
        "movl %esi, 0xd4(%eax)\n" /* iWeaponIndex */
        "movl 0x158(%ebx), %eax\n" /* line 625 | pSelf */
        "movl $0, 0xd8(%eax)\n"
        /* } scope */
        ".Lf1be2b4_001be333:\n"
        "addl $0x10, %esp\n" /* line 627 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1be2b4_001be33a:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 616 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1be2b4_001be2eb\n"
        ".Lf1be2b4_001be34a:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be2b4_001be2eb\n"
    );
}

/* line 635 */
static __attribute__((naked))
void PlayerCmd_dropItem(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 635 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 643 */
        "testw %ax, %ax\n"
        "jne .Lf1be364_001be42c\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1be364_001be44d\n"
        ".Lf1be364_001be3a4:\n"
        "movl $0, (%esp)\n" /* line 645 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* pszItemName */
        "movl %eax, (%esp)\n" /* line 648 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %edi\n" /* iWeaponIndex */
        "testl %eax, %eax\n" /* line 649 */
        "je .Lf1be364_001be3f5\n"
        "calll Scr_GetNumParam\n" /* line 652 */
        "cmpl $1, %eax\n"
        "jbe .Lf1be364_001be43f\n"
        "movl $1, (%esp)\n" /* line 653 */
        "calll Scr_GetConstLowercaseString\n"
        ".Lf1be364_001be3d6:\n"
        "movl %eax, 8(%esp)\n" /* line 657 */
        "movl %edi, 4(%esp)\n" /* iWeaponIndex */
        "movl %ebx, (%esp)\n" /* pSelf */
        "calll Drop_Weapon\n"
        ".Lf1be364_001be3e6:\n"
        "movl %eax, 8(%ebp)\n" /* line 668 | entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 669 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp GScr_AddEntity\n" /* line 668 */
        ".Lf1be364_001be3f5:\n"
        "movl %esi, (%esp)\n" /* line 661 | pszItemName */
        "calll G_FindItem\n"
        "testl %eax, %eax\n" /* line 662 */
        "je .Lf1be364_001be3e6\n"
        "movl $0, 0xc(%esp)\n" /* line 663 */
        "movl $0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pSelf */
        "calll Drop_Item\n"
        "movl %eax, 8(%ebp)\n" /* line 668 | entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 669 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp GScr_AddEntity\n" /* line 668 */
        ".Lf1be364_001be42c:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 643 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1be364_001be3a4\n"
        ".Lf1be364_001be43f:\n"
        "movl imp_scr_const, %eax\n" /* line 655 */
        "movzwl 0xa6(%eax), %eax\n"
        "jmp .Lf1be364_001be3d6\n"
        ".Lf1be364_001be44d:\n"
        "movl %edx, 4(%esp)\n" /* line 643 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be364_001be3a4\n"
    );
}

/* line 898 */
static __attribute__((naked))
void PlayerCmd_Suicide(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 898 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 900 */
        "testw %ax, %ax\n"
        "jne .Lf1be46a_001be50b\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1be46a_001be51b\n"
        ".Lf1be46a_001be4a4:\n"
        "andl $0xfffffffc, 0x174(%ebx)\n" /* line 902 | pSelf */
        "movl 0x158(%ebx), %eax\n" /* line 903 | pSelf */
        "movl $0, 0x194(%ebx)\n" /* pSelf */
        "movl $0, 0x12c(%eax)\n"
        "movl $0, 0x20(%esp)\n" /* line 904 */
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0xc, 0x10(%esp)\n"
        "movl $0x186a0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* pSelf */
        "movl %ebx, 4(%esp)\n" /* pSelf */
        "movl %ebx, (%esp)\n" /* pSelf */
        "calll player_die\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 905 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1be46a_001be50b:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 900 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1be46a_001be4a4\n"
        ".Lf1be46a_001be51b:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be46a_001be4a4\n"
    );
}

/* line 913 */
static __attribute__((naked))
void PlayerCmd_OpenMenu(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 913 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %esi\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 917 */
        "testw %ax, %ax\n"
        "jne .Lf1be538_001be594\n"
        "movzwl %si, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1be538_001be606\n"
        ".Lf1be538_001be573:\n"
        "movl 0x158(%ebx), %eax\n" /* line 920 | pSelf */
        "cmpl $2, 0x26c4(%eax)\n"
        "je .Lf1be538_001be5b1\n"
        ".Lf1be538_001be582:\n"
        "movl $0, 8(%ebp)\n" /* line 928 | entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 929 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 928 */
        ".Lf1be538_001be594:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 917 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* line 920 | pSelf */
        "cmpl $2, 0x26c4(%eax)\n"
        "jne .Lf1be538_001be582\n"
        ".Lf1be538_001be5b1:\n"
        "movl $0, (%esp)\n" /* line 922 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n"
        "calll GScr_GetScriptMenuIndex\n"
        "movl %eax, 8(%esp)\n" /* line 924 */
        "movl $0x74, 4(%esp)\n"
        "movl $str_002b1d38, (%esp)\n" /* "%c %i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movzwl %si, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl $1, 8(%ebp)\n" /* line 925 | entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 929 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 928 */
        ".Lf1be538_001be606:\n"
        "movl %edx, 4(%esp)\n" /* line 917 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be538_001be573\n"
    );
}

/* line 937 */
static __attribute__((naked))
void PlayerCmd_OpenMenuNoMouse(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 937 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %esi\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 941 */
        "testw %ax, %ax\n"
        "jne .Lf1be624_001be680\n"
        "movzwl %si, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %ecx\n" /* pSelf */
        "testl %ecx, %ecx\n"
        "je .Lf1be624_001be6f2\n"
        ".Lf1be624_001be65f:\n"
        "movl 0x158(%ebx), %eax\n" /* line 944 | pSelf */
        "cmpl $2, 0x26c4(%eax)\n"
        "je .Lf1be624_001be69d\n"
        ".Lf1be624_001be66e:\n"
        "movl $0, 8(%ebp)\n" /* line 953 | entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 954 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 953 */
        ".Lf1be624_001be680:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 941 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* line 944 | pSelf */
        "cmpl $2, 0x26c4(%eax)\n"
        "jne .Lf1be624_001be66e\n"
        ".Lf1be624_001be69d:\n"
        "movl $0, (%esp)\n" /* line 946 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n"
        "calll GScr_GetScriptMenuIndex\n"
        "movl %eax, 8(%esp)\n" /* line 949 */
        "movl $0x74, 4(%esp)\n"
        "movl $str_002b5e14, (%esp)\n" /* "%c %i 1" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movzwl %si, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl $1, 8(%ebp)\n" /* line 950 | entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 954 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 953 */
        ".Lf1be624_001be6f2:\n"
        "movl %edx, 4(%esp)\n" /* line 941 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be624_001be65f\n"
    );
}

/* line 962 */
static __attribute__((naked))
void PlayerCmd_CloseMenu(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 962 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %ebx\n" /* entref */
        "shrl $0x10, %eax\n" /* line 964 */
        "testw %ax, %ax\n"
        "jne .Lf1be710_001be774\n"
        "movzwl %bx, %ebx\n"
        "leal (%ebx, %ebx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1be710_001be785\n"
        ".Lf1be710_001be746:\n"
        "movl $0x75, 4(%esp)\n" /* line 966 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "addl $0x14, %esp\n" /* line 967 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1be710_001be774:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 964 */
        "calll Scr_ObjectError\n"
        "movzwl %bx, %ebx\n"
        "jmp .Lf1be710_001be746\n"
        ".Lf1be710_001be785:\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be710_001be746\n"
    );
}

/* line 975 */
static __attribute__((naked))
void PlayerCmd_CloseInGameMenu(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 975 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %ebx\n" /* entref */
        "shrl $0x10, %eax\n" /* line 977 */
        "testw %ax, %ax\n"
        "jne .Lf1be7a0_001be804\n"
        "movzwl %bx, %ebx\n"
        "leal (%ebx, %ebx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1be7a0_001be815\n"
        ".Lf1be7a0_001be7d6:\n"
        "movl $0x4b, 4(%esp)\n" /* line 979 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "addl $0x14, %esp\n" /* line 980 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1be7a0_001be804:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 977 */
        "calll Scr_ObjectError\n"
        "movzwl %bx, %ebx\n"
        "jmp .Lf1be7a0_001be7d6\n"
        ".Lf1be7a0_001be815:\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be7a0_001be7d6\n"
    );
}

/* line 1025 */
static __attribute__((naked))
void PlayerCmd_SetWeaponSlotWeapon(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1025 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1037 */
        "testw %ax, %ax\n"
        "jne .Lf1be830_001be998\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1be830_001beac6\n"
        ".Lf1be830_001be870:\n"
        "movl $0, (%esp)\n" /* line 1039 */
        "calll Scr_GetConstString\n"
        "movzwl %ax, %ebx\n" /* line 1040 | hadWeapon */
        "movl %ebx, (%esp)\n" /* hadWeapon */
        "calll SL_ConvertToString\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponSlotForName\n"
        "movl %eax, -0x24(%ebp)\n" /* iWeapSlot */
        "testl %eax, %eax\n" /* line 1041 */
        "je .Lf1be830_001bea40\n"
        ".Lf1be830_001be89a:\n"
        "movl $1, (%esp)\n" /* line 1044 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* bSwapToSecondPrimary */
        "movl $str_00218298, 4(%esp)\n" /* line 1045 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1be830_001be9bc\n"
        "movl $0, -0x20(%ebp)\n" /* iWeapIndex */
        "movl $0, -0x1c(%ebp)\n" /* weapDef */
        ".Lf1be830_001be8ce:\n"
        "movl 0x158(%esi), %edx\n" /* line 1062 | pSelf */
        "movl -0x24(%ebp), %ecx\n" /* iWeapSlot */
        "movzbl 0x554(%ecx, %edx), %eax\n"
        "movsbl %al, %ecx\n"
        "testb %al, %al\n" /* line 1063 */
        "jne .Lf1be830_001be9ab\n"
        ".Lf1be830_001be8ea:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1067 | iWeapIndex */
        "testl %eax, %eax\n"
        "je .Lf1be830_001be990\n"
        "cmpl $2, -0x24(%ebp)\n" /* line 1071 | iWeapSlot */
        "je .Lf1be830_001bea6d\n"
        "movl 0x158(%esi), %edx\n" /* pSelf */
        ".Lf1be830_001be905:\n"
        "xorl %edi, %edi\n" /* bSwapToSecondPrimary */
        ".Lf1be830_001be907:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1074 | iWeapIndex */
        "sarl $5, %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* iWeapIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%edx, %eax, 4), %ebx\n" /* hadWeapon */
        "sarl %cl, %ebx\n" /* hadWeapon */
        "andl $1, %ebx\n" /* hadWeapon */
        "movl -0x20(%ebp), %eax\n" /* line 1076 | iWeapIndex */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll G_GivePlayerWeapon\n"
        "testl %edi, %edi\n" /* line 1078 | bSwapToSecondPrimary */
        "je .Lf1be830_001be952\n"
        "movl 0x158(%esi), %eax\n" /* line 1080 | pSelf */
        "movzbl 0x555(%eax), %edx\n"
        "movb %dl, 0x556(%eax)\n"
        "movl 0x158(%esi), %eax\n" /* line 1081 | pSelf */
        "movb $0, 0x555(%eax)\n"
        ".Lf1be830_001be952:\n"
        "movl 0x158(%esi), %edx\n" /* line 1087 | pSelf */
        "movl -0x1c(%ebp), %ecx\n" /* weapDef */
        "movl 0x1c8(%ecx), %eax\n"
        "movl 0x1c0(%ecx), %ecx\n"
        "subl 0x144(%edx, %eax, 4), %ecx\n"
        "testl %ecx, %ecx\n" /* line 1088 */
        "jle .Lf1be830_001be990\n"
        "xorl %eax, %eax\n" /* line 1089 */
        "testl %ebx, %ebx\n" /* hadWeapon */
        "sete %al\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* iWeapIndex */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pSelf */
        "calll Add_Ammo\n"
        /* } scope */
        ".Lf1be830_001be990:\n"
        "addl $0x2c, %esp\n" /* line 1090 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1be830_001be998:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1037 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1be830_001be870\n"
        ".Lf1be830_001be9ab:\n"
        "movl %ecx, 4(%esp)\n" /* line 1064 */
        "movl %edx, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        "jmp .Lf1be830_001be8ea\n"
        ".Lf1be830_001be9bc:\n"
        "movl %edi, (%esp)\n" /* line 1052 | bSwapToSecondPrimary */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, -0x20(%ebp)\n" /* iWeapIndex */
        "testl %eax, %eax\n" /* line 1053 */
        "je .Lf1be830_001bea9e\n"
        ".Lf1be830_001be9cf:\n"
        "movl %eax, (%esp)\n" /* line 1057 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x1c(%ebp)\n" /* weapDef */
        "movl 0x80(%eax), %eax\n" /* line 1058 */
        "cmpl %eax, -0x24(%ebp)\n" /* iWeapSlot */
        "je .Lf1be830_001be8ce\n"
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf1be830_001bea8a\n"
        ".Lf1be830_001be9f5:\n"
        "movl -0x24(%ebp), %ecx\n" /* line 1059 | iWeapSlot */
        "movl %ecx, (%esp)\n"
        "calll BG_GetWeaponSlotNameForIndex\n"
        "movl %eax, %ebx\n" /* hadWeapon */
        "movl -0x1c(%ebp), %edx\n" /* weapDef */
        "movl 0x80(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponSlotNameForIndex\n"
        "movl %ebx, 0xc(%esp)\n" /* hadWeapon */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* bSwapToSecondPrimary */
        "movl $str_002b5e7c, (%esp)\n" /* "Weapon %s goes in the %s weaponslot, not the %s weaponslot." */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1be830_001be8ce\n"
        ".Lf1be830_001bea40:\n"
        "movl %ebx, (%esp)\n" /* line 1042 | hadWeapon */
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b5e1c, (%esp)\n" /* "Unknown weaponslot name %s. Valid weaponslots are "primary" " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1be830_001be89a\n"
        ".Lf1be830_001bea6d:\n"
        "movl 0x158(%esi), %edx\n" /* line 1071 | pSelf */
        "cmpb $0, 0x555(%edx)\n"
        "jne .Lf1be830_001be905\n"
        "movl $1, %edi\n" /* bSwapToSecondPrimary */
        "jmp .Lf1be830_001be907\n"
        ".Lf1be830_001bea8a:\n"
        "movl -0x24(%ebp), %eax\n" /* line 1058 | iWeapSlot */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf1be830_001be9f5\n"
        "jmp .Lf1be830_001be8ce\n"
        ".Lf1be830_001bea9e:\n"
        "movl %edi, 4(%esp)\n" /* line 1054 | bSwapToSecondPrimary */
        "movl $str_002b5e68, (%esp)\n" /* "Unknown weapon %s." */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        "movl -0x20(%ebp), %eax\n" /* iWeapIndex */
        "jmp .Lf1be830_001be9cf\n"
        ".Lf1be830_001beac6:\n"
        "movl %edx, 4(%esp)\n" /* line 1037 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1be830_001be870\n"
    );
}

/* line 1143 */
static __attribute__((naked))
void PlayerCmd_SetWeaponSlotAmmo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1143 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1151 */
        "testw %ax, %ax\n"
        "jne .Lf1beae4_001bebf4\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %ecx\n" /* pSelf */
        "testl %ecx, %ecx\n"
        "je .Lf1beae4_001bec45\n"
        ".Lf1beae4_001beb24:\n"
        "movl $0, (%esp)\n" /* line 1153 */
        "calll Scr_GetConstString\n"
        "movzwl %ax, %ebx\n" /* line 1154 | iAmmoIndex */
        "movl %ebx, (%esp)\n" /* iAmmoIndex */
        "calll SL_ConvertToString\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponSlotForName\n"
        "movl %eax, %edi\n" /* iWeapSlot */
        "testl %eax, %eax\n" /* line 1155 */
        "je .Lf1beae4_001bebc7\n"
        ".Lf1beae4_001beb49:\n"
        "movl $1, (%esp)\n" /* line 1158 */
        "calll Scr_GetInt\n"
        "movl %eax, -0x1c(%ebp)\n" /* iSetAmmo */
        "movl 0x158(%esi), %eax\n" /* line 1160 | pSelf */
        "movzbl 0x554(%edi, %eax), %eax\n" /* iWeapSlot */
        "movsbl %al, %ebx\n" /* iAmmoIndex */
        "testb %al, %al\n" /* line 1161 */
        "jne .Lf1beae4_001beb75\n"
        /* } scope */
        ".Lf1beae4_001beb6d:\n"
        "addl $0x2c, %esp\n" /* line 1190 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1beae4_001beb75:\n"
        "movl %ebx, (%esp)\n" /* line 1164 | iAmmoIndex */
        "calll BG_WeaponIsClipOnly\n"
        "testl %eax, %eax\n"
        "je .Lf1beae4_001bec07\n"
        "movl %ebx, (%esp)\n" /* line 1166 | iAmmoIndex */
        "calll BG_ClipForWeapon\n"
        "movl %eax, %ebx\n" /* iAmmoIndex */
        "testl %eax, %eax\n" /* line 1167 */
        "je .Lf1beae4_001beb6d\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1170 | iSetAmmo */
        "testl %eax, %eax\n"
        "js .Lf1beae4_001bec6e\n"
        "movl %ebx, (%esp)\n" /* line 1172 | iAmmoIndex */
        "calll BG_GetAmmoClipSize\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* iSetAmmo */
        "jg .Lf1beae4_001bec8c\n"
        "movl -0x1c(%ebp), %edx\n" /* iSetAmmo */
        ".Lf1beae4_001bebb2:\n"
        "movl 0x158(%esi), %eax\n" /* line 1175 | pSelf */
        "movl %edx, 0x344(%eax, %ebx, 4)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1190 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1beae4_001bebc7:\n"
        "movl %ebx, (%esp)\n" /* line 1156 | iAmmoIndex */
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b5e1c, (%esp)\n" /* "Unknown weaponslot name %s. Valid weaponslots are "primary" " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1beae4_001beb49\n"
        ".Lf1beae4_001bebf4:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1151 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1beae4_001beb24\n"
        ".Lf1beae4_001bec07:\n"
        "movl %ebx, (%esp)\n" /* line 1179 | iAmmoIndex */
        "calll BG_AmmoForWeapon\n"
        "movl %eax, %ebx\n" /* iAmmoIndex */
        "testl %eax, %eax\n" /* line 1180 */
        "je .Lf1beae4_001beb6d\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1183 | iSetAmmo */
        "testl %eax, %eax\n"
        "js .Lf1beae4_001bec62\n"
        "movl %ebx, (%esp)\n" /* line 1185 | iAmmoIndex */
        "calll BG_GetAmmoTypeMax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* iSetAmmo */
        "jg .Lf1beae4_001bec7d\n"
        "movl -0x1c(%ebp), %edx\n" /* iSetAmmo */
        ".Lf1beae4_001bec30:\n"
        "movl 0x158(%esi), %eax\n" /* line 1188 | pSelf */
        "movl %edx, 0x144(%eax, %ebx, 4)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1190 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1beae4_001bec45:\n"
        "movl %edx, 4(%esp)\n" /* line 1151 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1beae4_001beb24\n"
        ".Lf1beae4_001bec62:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 1183 | iSetAmmo */
        "movl -0x1c(%ebp), %edx\n" /* iSetAmmo */
        "jmp .Lf1beae4_001bec30\n"
        ".Lf1beae4_001bec6e:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 1170 | iSetAmmo */
        "movl -0x1c(%ebp), %edx\n" /* iSetAmmo */
        "jmp .Lf1beae4_001bebb2\n"
        ".Lf1beae4_001bec7d:\n"
        "movl %ebx, (%esp)\n" /* line 1186 | iAmmoIndex */
        "calll BG_GetAmmoTypeMax\n"
        "movl %eax, -0x1c(%ebp)\n" /* iSetAmmo */
        "movl %eax, %edx\n"
        "jmp .Lf1beae4_001bec30\n"
        ".Lf1beae4_001bec8c:\n"
        "movl %ebx, (%esp)\n" /* line 1173 | iAmmoIndex */
        "calll BG_GetAmmoClipSize\n"
        "movl %eax, -0x1c(%ebp)\n" /* iSetAmmo */
        "movl %eax, %edx\n"
        "jmp .Lf1beae4_001bebb2\n"
    );
}

/* line 1198 */
static __attribute__((naked))
void PlayerCmd_GetWeaponSlotClipAmmo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1198 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1205 */
        "testw %ax, %ax\n"
        "jne .Lf1bec9e_001bed65\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %edi\n" /* pSelf, iWeapSlot */
        "testl %edi, %edi\n" /* iWeapSlot */
        "je .Lf1bec9e_001bedbb\n"
        ".Lf1bec9e_001becde:\n"
        "movl 0x158(%ebx), %eax\n" /* line 1207 | pSelf */
        "movl 0x26a8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lf1bec9e_001bed28\n"
        "movl $0, (%esp)\n" /* line 1213 */
        "calll Scr_GetConstString\n"
        "movzwl %ax, %esi\n" /* line 1214 */
        "movl %esi, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponSlotForName\n"
        "movl %eax, %edi\n" /* iWeapSlot */
        "testl %eax, %eax\n" /* line 1215 */
        "je .Lf1bec9e_001bed78\n"
        "movl 0x158(%ebx), %eax\n" /* line 1218 | pSelf */
        "movzbl 0x554(%edi, %eax), %eax\n" /* iWeapSlot */
        "movsbl %al, %edx\n"
        "testb %al, %al\n" /* line 1219 */
        "jne .Lf1bec9e_001bed3b\n"
        ".Lf1bec9e_001bed28:\n"
        "movl $0, 8(%ebp)\n" /* line 1228 | entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1232 */
        ".Lf1bec9e_001bed3b:\n"
        "movl %edx, (%esp)\n" /* line 1225 */
        "calll BG_ClipForWeapon\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 1226 */
        "je .Lf1bec9e_001bed28\n"
        "movl 0x158(%ebx), %eax\n" /* line 1232 | pSelf */
        "movl 0x344(%eax, %edx, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1232 */
        ".Lf1bec9e_001bed65:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1205 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1bec9e_001becde\n"
        ".Lf1bec9e_001bed78:\n"
        "movl %esi, (%esp)\n" /* line 1216 */
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b5e1c, (%esp)\n" /* "Unknown weaponslot name %s. Valid weaponslots are "primary" " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "movl 0x158(%ebx), %eax\n" /* line 1218 | pSelf */
        "movzbl 0x554(%edi, %eax), %eax\n" /* iWeapSlot */
        "movsbl %al, %edx\n"
        "testb %al, %al\n" /* line 1219 */
        "je .Lf1bec9e_001bed28\n"
        "jmp .Lf1bec9e_001bed3b\n"
        ".Lf1bec9e_001bedbb:\n"
        "movl %edx, 4(%esp)\n" /* line 1205 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bec9e_001becde\n"
    );
}

/* line 1241 */
static __attribute__((naked))
void PlayerCmd_SetWeaponSlotClipAmmo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1241 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1249 */
        "testw %ax, %ax\n"
        "jne .Lf1bedd8_001beed9\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bedd8_001beef8\n"
        ".Lf1bedd8_001bee18:\n"
        "movl $0, (%esp)\n" /* line 1251 */
        "calll Scr_GetConstString\n"
        "movzwl %ax, %esi\n" /* line 1252 | iSetClipAmmo */
        "movl %esi, (%esp)\n" /* iSetClipAmmo */
        "calll SL_ConvertToString\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponSlotForName\n"
        "movl %eax, %edi\n" /* iClipIndex */
        "testl %eax, %eax\n" /* line 1253 */
        "je .Lf1bedd8_001beeac\n"
        ".Lf1bedd8_001bee3d:\n"
        "movl $1, (%esp)\n" /* line 1256 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* iSetClipAmmo */
        "movl 0x158(%ebx), %eax\n" /* line 1258 | pSelf */
        "movzbl 0x554(%edi, %eax), %eax\n" /* iClipIndex */
        "movsbl %al, %edx\n"
        "testb %al, %al\n" /* line 1259 */
        "jne .Lf1bedd8_001bee73\n"
        "movl $0, 8(%ebp)\n" /* line 1261 | entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1275 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1261 */
        ".Lf1bedd8_001bee73:\n"
        "movl %edx, (%esp)\n" /* line 1265 */
        "calll BG_ClipForWeapon\n"
        "movl %eax, %edi\n" /* iClipIndex */
        "testl %eax, %eax\n" /* line 1266 */
        "je .Lf1bedd8_001beea4\n"
        "testl %esi, %esi\n" /* line 1269 | iSetClipAmmo */
        "movl $0, %eax\n"
        "cmovsl %eax, %esi\n" /* iSetClipAmmo */
        "movl %edi, (%esp)\n" /* line 1271 | iClipIndex */
        "calll BG_GetAmmoClipSize\n"
        "cmpl %eax, %esi\n" /* iSetClipAmmo */
        "jg .Lf1bedd8_001beeec\n"
        ".Lf1bedd8_001bee97:\n"
        "movl 0x158(%ebx), %eax\n" /* line 1274 | pSelf */
        "movl %esi, 0x344(%eax, %edi, 4)\n" /* iSetClipAmmo */
        /* } scope */
        ".Lf1bedd8_001beea4:\n"
        "addl $0x1c, %esp\n" /* line 1275 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bedd8_001beeac:\n"
        "movl %esi, (%esp)\n" /* line 1254 | iSetClipAmmo */
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b5e1c, (%esp)\n" /* "Unknown weaponslot name %s. Valid weaponslots are "primary" " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1bedd8_001bee3d\n"
        ".Lf1bedd8_001beed9:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1249 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1bedd8_001bee18\n"
        ".Lf1bedd8_001beeec:\n"
        "movl %edi, (%esp)\n" /* line 1272 | iClipIndex */
        "calll BG_GetAmmoClipSize\n"
        "movl %eax, %esi\n" /* iSetClipAmmo */
        "jmp .Lf1bedd8_001bee97\n"
        ".Lf1bedd8_001beef8:\n"
        "movl %edx, 4(%esp)\n" /* line 1249 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bedd8_001bee18\n"
    );
}

/* line 1283 */
static __attribute__((naked))
void PlayerCmd_SetWeaponClipAmmo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1283 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1290 */
        "testw %ax, %ax\n"
        "jne .Lf1bef16_001befca\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bef16_001befe9\n"
        ".Lf1bef16_001bef56:\n"
        "movl $0, (%esp)\n" /* line 1292 */
        "calll Scr_GetString\n"
        "movl %eax, %ebx\n" /* clipIndex */
        "movl $1, (%esp)\n" /* line 1293 */
        "calll Scr_GetInt\n"
        "movl %eax, %edi\n" /* ammoCount */
        "movl %ebx, (%esp)\n" /* line 1294 | clipIndex */
        "calll G_GetWeaponIndexForName\n"
        "testl %eax, %eax\n" /* line 1296 */
        "jne .Lf1bef16_001bef91\n"
        "movl $0, 8(%ebp)\n" /* line 1298 | entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1312 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1298 */
        ".Lf1bef16_001bef91:\n"
        "movl %eax, (%esp)\n" /* line 1302 */
        "calll BG_ClipForWeapon\n"
        "movl %eax, %ebx\n" /* clipIndex */
        "testl %eax, %eax\n" /* line 1303 */
        "je .Lf1bef16_001befc2\n"
        "testl %edi, %edi\n" /* line 1306 | ammoCount */
        "movl $0, %eax\n"
        "cmovsl %eax, %edi\n" /* ammoCount */
        "movl %ebx, (%esp)\n" /* line 1308 | clipIndex */
        "calll BG_GetAmmoClipSize\n"
        "cmpl %eax, %edi\n" /* ammoCount */
        "jg .Lf1bef16_001befdd\n"
        ".Lf1bef16_001befb5:\n"
        "movl 0x158(%esi), %eax\n" /* line 1311 | pSelf */
        "movl %edi, 0x344(%eax, %ebx, 4)\n" /* ammoCount */
        /* } scope */
        ".Lf1bef16_001befc2:\n"
        "addl $0x1c, %esp\n" /* line 1312 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bef16_001befca:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1290 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1bef16_001bef56\n"
        ".Lf1bef16_001befdd:\n"
        "movl %ebx, (%esp)\n" /* line 1309 | clipIndex */
        "calll BG_GetAmmoClipSize\n"
        "movl %eax, %edi\n" /* ammoCount */
        "jmp .Lf1bef16_001befb5\n"
        ".Lf1bef16_001befe9:\n"
        "movl %edx, 4(%esp)\n" /* line 1290 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bef16_001bef56\n"
    );
}

/* line 1323 */
static __attribute__((naked))
void iclientprintln(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1323 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %ebx\n" /* entref */
        "shrl $0x10, %eax\n" /* line 1325 */
        "testw %ax, %ax\n"
        "jne .Lf1bf006_001bf062\n"
        "movzwl %bx, %ebx\n"
        "leal (%ebx, %ebx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1bf006_001bf097\n"
        "movl $0x66, 4(%esp)\n" /* line 1327 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_MakeGameMessage\n"
        "addl $0x14, %esp\n" /* line 1328 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1bf006_001bf062:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1325 */
        "calll Scr_ObjectError\n"
        "movzwl %bx, %ebx\n"
        "movl $0x66, 4(%esp)\n" /* line 1327 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_MakeGameMessage\n"
        "addl $0x14, %esp\n" /* line 1328 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1bf006_001bf097:\n"
        "movl %ebx, 4(%esp)\n" /* line 1325 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl $0x66, 4(%esp)\n" /* line 1327 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_MakeGameMessage\n"
        "addl $0x14, %esp\n" /* line 1328 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1337 */
static __attribute__((naked))
void iclientprintlnbold(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1337 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %ebx\n" /* entref */
        "shrl $0x10, %eax\n" /* line 1339 */
        "testw %ax, %ax\n"
        "jne .Lf1bf0d6_001bf132\n"
        "movzwl %bx, %ebx\n"
        "leal (%ebx, %ebx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1bf0d6_001bf167\n"
        "movl $0x67, 4(%esp)\n" /* line 1341 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_MakeGameMessage\n"
        "addl $0x14, %esp\n" /* line 1342 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1bf0d6_001bf132:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1339 */
        "calll Scr_ObjectError\n"
        "movzwl %bx, %ebx\n"
        "movl $0x67, 4(%esp)\n" /* line 1341 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_MakeGameMessage\n"
        "addl $0x14, %esp\n" /* line 1342 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1bf0d6_001bf167:\n"
        "movl %ebx, 4(%esp)\n" /* line 1339 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl $0x67, 4(%esp)\n" /* line 1341 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_MakeGameMessage\n"
        "addl $0x14, %esp\n" /* line 1342 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1350 */
__attribute__((naked))
void PlayerCmd_spawn(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1350 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1355 */
        "testw %ax, %ax\n"
        "jne .Lf1bf1a6_001bf21c\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %edi\n" /* pSelf */
        "subl %eax, %edi\n" /* pSelf */
        "shll $4, %edi\n" /* pSelf */
        "addl imp_g_entities, %edi\n" /* pSelf */
        "movl 0x158(%edi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bf1a6_001bf22c\n"
        ".Lf1bf1a6_001bf1de:\n"
        "leal -0x24(%ebp), %esi\n" /* line 1357 | spawn_origin */
        "movl %esi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x30(%ebp), %ebx\n" /* line 1358 | spawn_angles */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, 8(%esp)\n" /* line 1359 */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pSelf */
        "calll ClientSpawn\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1360 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf1a6_001bf21c:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1355 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n" /* pSelf */
        "jmp .Lf1bf1a6_001bf1de\n"
        ".Lf1bf1a6_001bf22c:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bf1a6_001bf1de\n"
    );
}

/* line 1368 */
static __attribute__((naked))
void PlayerCmd_setEnterTime(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1368 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1370 */
        "testw %ax, %ax\n"
        "jne .Lf1bf246_001bf29a\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bf246_001bf2c6\n"
        "movl 0x158(%ebx), %ebx\n" /* line 1372 | pSelf */
        "movl $0, (%esp)\n"
        "calll Scr_GetInt\n"
        "movl %eax, 0x272c(%ebx)\n" /* pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1373 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf246_001bf29a:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1370 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %ebx\n" /* line 1372 | pSelf */
        "movl $0, (%esp)\n"
        "calll Scr_GetInt\n"
        "movl %eax, 0x272c(%ebx)\n" /* pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1373 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf246_001bf2c6:\n"
        "movl %edx, 4(%esp)\n" /* line 1370 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl 0x158(%ebx), %ebx\n" /* line 1372 | pSelf */
        "movl $0, (%esp)\n"
        "calll Scr_GetInt\n"
        "movl %eax, 0x272c(%ebx)\n" /* pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1373 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1382 */
void BodyEnd(gentity_t *ent)
{
    *(int *)((byte *)ent + 8) &= 0xfff7ffff;
    *(int *)((byte *)ent + 0x11c) = 0x4000000;
    *(byte *)((byte *)ent + 0xf2) = 0;
}

/* line 1484 */
static __attribute__((naked))
void PlayerCmd_SetClientDvar(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1484 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x83c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movw %ax, -0x81a(%ebp)\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1495 */
        "testw %ax, %ax\n"
        "jne .Lf1bf31c_001bf472\n"
        "movzwl -0x81a(%ebp), %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1bf31c_001bf4de\n"
        ".Lf1bf31c_001bf368:\n"
        "movl $0, (%esp)\n" /* line 1497 */
        "calll Scr_GetString\n"
        "movl %eax, -0x820(%ebp)\n" /* pszDvar */
        "movl $1, (%esp)\n" /* line 1499 */
        "calll Scr_GetType\n"
        "cmpl $3, %eax\n" /* line 1500 */
        "je .Lf1bf31c_001bf4a5\n"
        ".Lf1bf31c_001bf38f:\n"
        "movl $1, (%esp)\n" /* line 1506 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* pszText */
        ".Lf1bf31c_001bf39d:\n"
        "movl -0x820(%ebp), %eax\n" /* line 1509 | pszDvar */
        "movl %eax, (%esp)\n"
        "calll Dvar_IsValidName\n"
        "testb %al, %al\n"
        "jne .Lf1bf31c_001bf3d8\n"
        "movl -0x820(%ebp), %eax\n" /* line 1511 | pszDvar */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b27f8, (%esp)\n" /* "Dvar %s has an invalid dvar name" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        "addl $0x83c, %esp\n" /* line 1526 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf31c_001bf3d8:\n"
        "leal -0x818(%ebp), %esi\n" /* line 1517 | szOutString */
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memset\n"
        "movl $1, %ebx\n"
        "jmp .Lf1bf31c_001bf421\n"
        ".Lf1bf31c_001bf3fd:\n"
        "movsbl %al, %eax\n" /* line 1520 */
        "movl %eax, (%esp)\n"
        "calll I_CleanChar\n"
        "movl $0x27, %edx\n" /* line 1522 */
        "cmpb $0x22, %al\n"
        "cmovnel %eax, %edx\n"
        "movb %dl, -1(%ebx, %esi)\n"
        "addl $1, %ebx\n"
        "cmpl $0x2001, %ebx\n" /* line 1518 */
        "je .Lf1bf31c_001bf42a\n"
        ".Lf1bf31c_001bf421:\n"
        "movzbl -1(%edi, %ebx), %eax\n" /* pszText */
        "testb %al, %al\n"
        "jne .Lf1bf31c_001bf3fd\n"
        ".Lf1bf31c_001bf42a:\n"
        "movl %esi, 0xc(%esp)\n" /* line 1525 */
        "movl -0x820(%ebp), %eax\n" /* pszDvar */
        "movl %eax, 8(%esp)\n"
        "movl $0x76, 4(%esp)\n"
        "movl $str_002b5ecc, (%esp)\n" /* "%c %s "%s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movzwl -0x81a(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x83c, %esp\n" /* line 1526 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf31c_001bf472:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1495 */
        "calll Scr_ObjectError\n"
        "movl $0, (%esp)\n" /* line 1497 */
        "calll Scr_GetString\n"
        "movl %eax, -0x820(%ebp)\n" /* pszDvar */
        "movl $1, (%esp)\n" /* line 1499 */
        "calll Scr_GetType\n"
        "cmpl $3, %eax\n" /* line 1500 */
        "jne .Lf1bf31c_001bf38f\n"
        ".Lf1bf31c_001bf4a5:\n"
        "calll Scr_GetNumParam\n" /* line 1502 */
        "movl $0x400, 0x10(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* szString */
        "movl %ebx, 0xc(%esp)\n"
        "movl $str_002b5eb8, 8(%esp)\n" /* "Client Dvar Value" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "movl %ebx, %edi\n" /* pszText */
        "jmp .Lf1bf31c_001bf39d\n"
        ".Lf1bf31c_001bf4de:\n"
        "movl %ecx, 4(%esp)\n" /* line 1495 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bf31c_001bf368\n"
    );
}

/* line 1534 */
static __attribute__((naked))
void PlayerCmd_IsTalking(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1534 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1538 */
        "testw %ax, %ax\n"
        "jne .Lf1bf4fc_001bf56a\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %ecx\n" /* pSelf */
        "testl %ecx, %ecx\n"
        "je .Lf1bf4fc_001bf58b\n"
        ".Lf1bf4fc_001bf532:\n"
        "movl 0x158(%ebx), %edx\n" /* line 1540 | pSelf */
        "movl imp_level, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "subl 0x2808(%edx), %eax\n" /* line 1541 */
        "movl %eax, %edx\n"
        "js .Lf1bf4fc_001bf559\n"
        "movl imp_g_voiceChatTalkingDuration, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %edx\n"
        "jl .Lf1bf4fc_001bf57a\n"
        ".Lf1bf4fc_001bf559:\n"
        "movl $0, 8(%ebp)\n" /* line 1544 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1545 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1544 */
        ".Lf1bf4fc_001bf56a:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1538 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1bf4fc_001bf532\n"
        ".Lf1bf4fc_001bf57a:\n"
        "movl $1, 8(%ebp)\n" /* line 1542 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1545 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1542 */
        ".Lf1bf4fc_001bf58b:\n"
        "movl %edx, 4(%esp)\n" /* line 1538 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bf4fc_001bf532\n"
    );
}

/* line 1553 */
static __attribute__((naked))
void PlayerCmd_FreezeControls(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1553 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1555 */
        "testw %ax, %ax\n"
        "jne .Lf1bf5a6_001bf5fa\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bf5a6_001bf626\n"
        "movl 0x158(%ebx), %ebx\n" /* line 1556 | pSelf */
        "movl $0, (%esp)\n"
        "calll Scr_GetInt\n"
        "movl %eax, 0x27b4(%ebx)\n" /* pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1557 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf5a6_001bf5fa:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1555 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %ebx\n" /* line 1556 | pSelf */
        "movl $0, (%esp)\n"
        "calll Scr_GetInt\n"
        "movl %eax, 0x27b4(%ebx)\n" /* pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1557 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf5a6_001bf626:\n"
        "movl %edx, 4(%esp)\n" /* line 1555 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl 0x158(%ebx), %ebx\n" /* line 1556 | pSelf */
        "movl $0, (%esp)\n"
        "calll Scr_GetInt\n"
        "movl %eax, 0x27b4(%ebx)\n" /* pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1557 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1565 */
static __attribute__((naked))
void PlayerCmd_DisableWeapon(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1565 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1567 */
        "testw %ax, %ax\n"
        "jne .Lf1bf65c_001bf6a5\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bf65c_001bf6c6\n"
        "movl 0x158(%ebx), %eax\n" /* line 1568 | pSelf */
        "orl $0x4000000, 0xc(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1569 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf65c_001bf6a5:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1567 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* line 1568 | pSelf */
        "orl $0x4000000, 0xc(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1569 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf65c_001bf6c6:\n"
        "movl %edx, 4(%esp)\n" /* line 1567 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl 0x158(%ebx), %eax\n" /* line 1568 | pSelf */
        "orl $0x4000000, 0xc(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1569 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1577 */
static __attribute__((naked))
void PlayerCmd_EnableWeapon(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1577 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1579 */
        "testw %ax, %ax\n"
        "jne .Lf1bf6f2_001bf73b\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bf6f2_001bf75c\n"
        "movl 0x158(%ebx), %eax\n" /* line 1580 | pSelf */
        "andl $0xfbffffff, 0xc(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1581 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf6f2_001bf73b:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1579 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* line 1580 | pSelf */
        "andl $0xfbffffff, 0xc(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1581 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf6f2_001bf75c:\n"
        "movl %edx, 4(%esp)\n" /* line 1579 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movl 0x158(%ebx), %eax\n" /* line 1580 | pSelf */
        "andl $0xfbffffff, 0xc(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1581 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1589 */
static __attribute__((naked))
void PlayerCmd_SetReverb(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1589 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %esi\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1598 */
        "testw %ax, %ax\n"
        "jne .Lf1bf788_001bf818\n"
        "movzwl %si, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1bf788_001bf94c\n"
        ".Lf1bf788_001bf7c3:\n"
        "calll Scr_GetNumParam\n" /* line 1603 */
        "cmpl $3, %eax\n"
        "je .Lf1bf788_001bf82e\n"
        ".Lf1bf788_001bf7cd:\n"
        "jbe .Lf1bf788_001bf7fd\n"
        "cmpl $4, %eax\n"
        "je .Lf1bf788_001bf916\n"
        "cmpl $5, %eax\n"
        "jne .Lf1bf788_001bf806\n"
        "movl $4, (%esp)\n" /* line 1606 */
        "calll Scr_GetFloat\n"
        "fstps -0x24(%ebp)\n" /* fadetime */
        ".Lf1bf788_001bf7ec:\n"
        "movl $3, (%esp)\n" /* line 1609 */
        "calll Scr_GetFloat\n"
        "fstps -0x28(%ebp)\n" /* wetlevel */
        "jmp .Lf1bf788_001bf844\n"
        ".Lf1bf788_001bf7fd:\n"
        "cmpl $2, %eax\n" /* line 1603 */
        "je .Lf1bf788_001bf924\n"
        ".Lf1bf788_001bf806:\n"
        "movl $str_002b5f3c, 8(%ebp)\n" /* line 1629 | entref */
        /* } scope */
        "addl $0x60, %esp\n" /* line 1632 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 1629 */
        ".Lf1bf788_001bf818:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1598 */
        "calll Scr_ObjectError\n"
        "calll Scr_GetNumParam\n" /* line 1603 */
        "cmpl $3, %eax\n"
        "jne .Lf1bf788_001bf7cd\n"
        ".Lf1bf788_001bf82e:\n"
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* fadetime */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, -0x28(%ebp)\n" /* wetlevel */
        ".Lf1bf788_001bf844:\n"
        "movl $2, (%esp)\n" /* line 1612 */
        "calll Scr_GetFloat\n"
        "fstps -0x2c(%ebp)\n" /* drylevel */
        "cvtss2sd -0x24(%ebp), %xmm0\n" /* fadetime */
        "movsd %xmm0, -0x20(%ebp)\n"
        "cvtss2sd -0x28(%ebp), %xmm0\n" /* wetlevel */
        "movsd %xmm0, -0x18(%ebp)\n"
        "cvtss2sd -0x2c(%ebp), %xmm0\n" /* drylevel */
        "movsd %xmm0, -0x10(%ebp)\n"
        ".Lf1bf788_001bf871:\n"
        "movl $1, (%esp)\n" /* line 1615 */
        "calll Scr_GetString\n"
        "movl %eax, %ebx\n" /* pszReverb */
        "movl $0, (%esp)\n" /* line 1616 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 1619 */
        "cmpw 0x82(%edx), %ax\n"
        "je .Lf1bf788_001bf8af\n"
        "cmpw 0x84(%edx), %ax\n" /* line 1621 */
        "je .Lf1bf788_001bf90f\n"
        "movl $str_002b5ed8, (%esp)\n" /* line 1624 */
        "calll Scr_Error\n"
        ".Lf1bf788_001bf8af:\n"
        "movl $1, %eax\n"
        ".Lf1bf788_001bf8b4:\n"
        "movsd -0x20(%ebp), %xmm0\n" /* line 1626 */
        "movsd %xmm0, 0x20(%esp)\n"
        "movsd -0x18(%ebp), %xmm0\n"
        "movsd %xmm0, 0x18(%esp)\n"
        "movsd -0x10(%ebp), %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* pszReverb */
        "movl %eax, 8(%esp)\n"
        "movl $0x72, 4(%esp)\n"
        "movl $str_002b5f28, (%esp)\n" /* "%c %i "%s" %g %g %g" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movzwl %si, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x60, %esp\n" /* line 1632 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf788_001bf90f:\n"
        "movl $2, %eax\n" /* line 1621 */
        "jmp .Lf1bf788_001bf8b4\n"
        ".Lf1bf788_001bf916:\n"
        "pxor %xmm0, %xmm0\n" /* line 1603 */
        "movss %xmm0, -0x24(%ebp)\n" /* fadetime */
        "jmp .Lf1bf788_001bf7ec\n"
        ".Lf1bf788_001bf924:\n"
        "pxor %xmm0, %xmm0\n"
        "movsd %xmm0, -0x20(%ebp)\n"
        "movsd lit8_00307ce0, %xmm0\n" /* 0.5 */
        "movsd %xmm0, -0x18(%ebp)\n"
        "movsd lit8_00307c10, %xmm0\n" /* 1.0 */
        "movsd %xmm0, -0x10(%ebp)\n"
        "jmp .Lf1bf788_001bf871\n"
        ".Lf1bf788_001bf94c:\n"
        "movl %ecx, 4(%esp)\n" /* line 1598 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bf788_001bf7c3\n"
    );
}

/* line 1640 */
static __attribute__((naked))
void PlayerCmd_DeactivateReverb(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1640 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %ebx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1646 */
        "testw %ax, %ax\n"
        "jne .Lf1bf96a_001bf9c8\n"
        "movzwl %bx, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1bf96a_001bfa81\n"
        ".Lf1bf96a_001bf9a4:\n"
        "calll Scr_GetNumParam\n" /* line 1649 */
        "cmpl $1, %eax\n"
        "je .Lf1bf96a_001bf9de\n"
        ".Lf1bf96a_001bf9ae:\n"
        "cmpl $2, %eax\n"
        "je .Lf1bf96a_001bfa5c\n"
        "movl $str_002b60ac, 8(%ebp)\n" /* line 1668 | entref */
        /* } scope */
        "addl $0x34, %esp\n" /* line 1671 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 1668 */
        ".Lf1bf96a_001bf9c8:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1646 */
        "calll Scr_ObjectError\n"
        "calll Scr_GetNumParam\n" /* line 1649 */
        "cmpl $1, %eax\n"
        "jne .Lf1bf96a_001bf9ae\n"
        ".Lf1bf96a_001bf9de:\n"
        "pxor %xmm0, %xmm0\n"
        "movsd %xmm0, -0x10(%ebp)\n"
        ".Lf1bf96a_001bf9e7:\n"
        "movl $0, (%esp)\n" /* line 1655 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 1658 */
        "cmpw 0x82(%edx), %ax\n"
        "je .Lf1bf96a_001bfa17\n"
        "cmpw 0x84(%edx), %ax\n" /* line 1660 */
        "je .Lf1bf96a_001bfa7a\n"
        "movl $str_002b5ed8, (%esp)\n" /* line 1663 */
        "calll Scr_Error\n"
        ".Lf1bf96a_001bfa17:\n"
        "movl $1, %eax\n"
        ".Lf1bf96a_001bfa1c:\n"
        "movsd -0x10(%ebp), %xmm0\n" /* line 1665 */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x44, 4(%esp)\n"
        "movl $str_002b5f28, (%esp)\n" /* "%c %i "%s" %g %g %g" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movzwl %bx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 1671 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bf96a_001bfa5c:\n"
        "movl $1, (%esp)\n" /* line 1652 */
        "calll Scr_GetFloat\n"
        "fstps -0x14(%ebp)\n" /* fadetime */
        "cvtss2sd -0x14(%ebp), %xmm0\n" /* fadetime */
        "movsd %xmm0, -0x10(%ebp)\n"
        "jmp .Lf1bf96a_001bf9e7\n"
        ".Lf1bf96a_001bfa7a:\n"
        "movl $2, %eax\n" /* line 1660 */
        "jmp .Lf1bf96a_001bfa1c\n"
        ".Lf1bf96a_001bfa81:\n"
        "movl %ecx, 4(%esp)\n" /* line 1646 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bf96a_001bf9a4\n"
    );
}

/* line 1679 */
static __attribute__((naked))
void PlayerCmd_SetChannelVolumes(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1679 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %esi\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1686 */
        "testw %ax, %ax\n"
        "jne .Lf1bfa9e_001bfafe\n"
        "movzwl %si, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1bfa9e_001bfc06\n"
        ".Lf1bfa9e_001bfad9:\n"
        "calll Scr_GetNumParam\n" /* line 1689 */
        "cmpl $2, %eax\n"
        "je .Lf1bfa9e_001bfb14\n"
        ".Lf1bfa9e_001bfae3:\n"
        "cmpl $3, %eax\n"
        "je .Lf1bfa9e_001bfbda\n"
        "movl $str_002b6218, 8(%ebp)\n" /* line 1712 | entref */
        /* } scope */
        "addl $0x30, %esp\n" /* line 1715 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 1712 */
        ".Lf1bfa9e_001bfafe:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1686 */
        "calll Scr_ObjectError\n"
        "calll Scr_GetNumParam\n" /* line 1689 */
        "cmpl $2, %eax\n"
        "jne .Lf1bfa9e_001bfae3\n"
        ".Lf1bfa9e_001bfb14:\n"
        "pxor %xmm0, %xmm0\n"
        "movsd %xmm0, -0x10(%ebp)\n"
        ".Lf1bfa9e_001bfb1d:\n"
        "movl $1, (%esp)\n" /* line 1695 */
        "calll Scr_GetString\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x10, 8(%esp)\n"
        "movl $0x48e, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll G_FindConfigstringIndex\n"
        "movl %eax, %ebx\n" /* shockIndex */
        "movl $0, (%esp)\n" /* line 1697 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 1700 */
        "cmpw 0x86(%edx), %ax\n"
        "je .Lf1bfa9e_001bfb90\n"
        "cmpw 0x88(%edx), %ax\n" /* line 1702 */
        "je .Lf1bfa9e_001bfbff\n"
        "cmpw 0x8a(%edx), %ax\n" /* line 1704 */
        "je .Lf1bfa9e_001bfbf8\n"
        "movl $str_002b6198, (%esp)\n" /* line 1707 */
        "calll Scr_Error\n"
        ".Lf1bfa9e_001bfb90:\n"
        "movl $1, %eax\n"
        ".Lf1bfa9e_001bfb95:\n"
        "movsd -0x10(%ebp), %xmm0\n" /* line 1709 */
        "movsd %xmm0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* shockIndex */
        "movl %eax, 8(%esp)\n"
        "movl $0x45, 4(%esp)\n"
        "movl $str_002b620c, (%esp)\n" /* "%c %i %i %g" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movzwl %si, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 1715 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bfa9e_001bfbda:\n"
        "movl $2, (%esp)\n" /* line 1692 */
        "calll Scr_GetFloat\n"
        "fstps -0x14(%ebp)\n" /* fadetime */
        "cvtss2sd -0x14(%ebp), %xmm0\n" /* fadetime */
        "movsd %xmm0, -0x10(%ebp)\n"
        "jmp .Lf1bfa9e_001bfb1d\n"
        ".Lf1bfa9e_001bfbf8:\n"
        "movl $3, %eax\n" /* line 1704 */
        "jmp .Lf1bfa9e_001bfb95\n"
        ".Lf1bfa9e_001bfbff:\n"
        "movl $2, %eax\n" /* line 1702 */
        "jmp .Lf1bfa9e_001bfb95\n"
        ".Lf1bfa9e_001bfc06:\n"
        "movl %ecx, 4(%esp)\n" /* line 1686 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bfa9e_001bfad9\n"
    );
}

/* line 1723 */
static __attribute__((naked))
void PlayerCmd_DeactivateChannelVolumes(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1723 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %ebx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1729 */
        "testw %ax, %ax\n"
        "jne .Lf1bfc24_001bfc82\n"
        "movzwl %bx, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1bfc24_001bfd4b\n"
        ".Lf1bfc24_001bfc5e:\n"
        "calll Scr_GetNumParam\n" /* line 1732 */
        "cmpl $1, %eax\n"
        "je .Lf1bfc24_001bfc98\n"
        ".Lf1bfc24_001bfc68:\n"
        "cmpl $2, %eax\n"
        "je .Lf1bfc24_001bfd1f\n"
        "movl $str_002b62ec, 8(%ebp)\n" /* line 1753 | entref */
        /* } scope */
        "addl $0x34, %esp\n" /* line 1756 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 1753 */
        ".Lf1bfc24_001bfc82:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1729 */
        "calll Scr_ObjectError\n"
        "calll Scr_GetNumParam\n" /* line 1732 */
        "cmpl $1, %eax\n"
        "jne .Lf1bfc24_001bfc68\n"
        ".Lf1bfc24_001bfc98:\n"
        "pxor %xmm0, %xmm0\n"
        "movsd %xmm0, -0x10(%ebp)\n"
        ".Lf1bfc24_001bfca1:\n"
        "movl $0, (%esp)\n" /* line 1738 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 1741 */
        "cmpw 0x86(%edx), %ax\n"
        "je .Lf1bfc24_001bfcda\n"
        "cmpw 0x88(%edx), %ax\n" /* line 1743 */
        "je .Lf1bfc24_001bfd44\n"
        "cmpw 0x8a(%edx), %ax\n" /* line 1745 */
        "je .Lf1bfc24_001bfd3d\n"
        "movl $str_002b6198, (%esp)\n" /* line 1748 */
        "calll Scr_Error\n"
        ".Lf1bfc24_001bfcda:\n"
        "movl $1, %eax\n"
        ".Lf1bfc24_001bfcdf:\n"
        "movsd -0x10(%ebp), %xmm0\n" /* line 1750 */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x46, 4(%esp)\n"
        "movl $str_002b5f28, (%esp)\n" /* "%c %i "%s" %g %g %g" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movzwl %bx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 1756 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bfc24_001bfd1f:\n"
        "movl $1, (%esp)\n" /* line 1735 */
        "calll Scr_GetFloat\n"
        "fstps -0x14(%ebp)\n" /* fadetime */
        "cvtss2sd -0x14(%ebp), %xmm0\n" /* fadetime */
        "movsd %xmm0, -0x10(%ebp)\n"
        "jmp .Lf1bfc24_001bfca1\n"
        ".Lf1bfc24_001bfd3d:\n"
        "movl $3, %eax\n" /* line 1745 */
        "jmp .Lf1bfc24_001bfcdf\n"
        ".Lf1bfc24_001bfd44:\n"
        "movl $2, %eax\n" /* line 1743 */
        "jmp .Lf1bfc24_001bfcdf\n"
        ".Lf1bfc24_001bfd4b:\n"
        "movl %ecx, 4(%esp)\n" /* line 1729 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bfc24_001bfc5e\n"
    );
}

/* line 1764 */
static __attribute__((naked))
void ScrCmd_IsLookingAt(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1764 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1766 */
        "testw %ax, %ax\n"
        "jne .Lf1bfd68_001bfdcb\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %ecx\n" /* pSelf */
        "testl %ecx, %ecx\n"
        "je .Lf1bfd68_001bfddb\n"
        ".Lf1bfd68_001bfd9e:\n"
        "movl 0x158(%ebx), %eax\n" /* line 1767 | pSelf */
        "movl 0x282c(%eax), %ebx\n" /* pSelf */
        "movl $0, (%esp)\n"
        "calll Scr_GetEntity\n"
        "cmpl %eax, %ebx\n" /* pSelf */
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1768 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1767 */
        ".Lf1bfd68_001bfdcb:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1766 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1bfd68_001bfd9e\n"
        ".Lf1bfd68_001bfddb:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bfd68_001bfd9e\n"
    );
}

/* line 1776 */
static __attribute__((naked))
void ScrCmd_PlayLocalSound(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1776 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %ebx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1780 */
        "testw %ax, %ax\n"
        "jne .Lf1bfdf6_001bfe75\n"
        "movzwl %bx, %ebx\n"
        "leal (%ebx, %ebx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1bfdf6_001bfe86\n"
        ".Lf1bfdf6_001bfe2c:\n"
        "movl $0, (%esp)\n" /* line 1782 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 1783 */
        "calll G_SoundAliasIndex\n"
        "movzbl %al, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x73, 4(%esp)\n"
        "movl $str_002b1d38, (%esp)\n" /* "%c %i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1784 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bfdf6_001bfe75:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1780 */
        "calll Scr_ObjectError\n"
        "movzwl %bx, %ebx\n"
        "jmp .Lf1bfdf6_001bfe2c\n"
        ".Lf1bfdf6_001bfe86:\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bfdf6_001bfe2c\n"
    );
}

/* line 1792 */
static __attribute__((naked))
void PlayerCmd_SayAll(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1792 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1796 */
        "testw %ax, %ax\n"
        "jne .Lf1bfea0_001bff43\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bfea0_001bff53\n"
        ".Lf1bfea0_001bfede:\n"
        "calll Scr_GetNumParam\n" /* line 1798 */
        "movl $0x3ff, 0x10(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* szString */
        "leal -0x407(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002b6404, 8(%esp)\n" /* "Client Chat Message" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "movb $0x14, -0x408(%ebp)\n" /* line 1799 | szString */
        "movl %ebx, 0xc(%esp)\n" /* line 1801 */
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pSelf */
        "calll G_Say\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 1802 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bfea0_001bff43:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1796 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1bfea0_001bfede\n"
        ".Lf1bfea0_001bff53:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bfea0_001bfede\n"
    );
}

/* line 1810 */
static __attribute__((naked))
void PlayerCmd_SayTeam(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1810 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1814 */
        "testw %ax, %ax\n"
        "jne .Lf1bff70_001c0013\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1bff70_001c0023\n"
        ".Lf1bff70_001bffae:\n"
        "calll Scr_GetNumParam\n" /* line 1816 */
        "movl $0x3ff, 0x10(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* szString */
        "leal -0x407(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002b6404, 8(%esp)\n" /* "Client Chat Message" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "movb $0x14, -0x408(%ebp)\n" /* line 1817 | szString */
        "movl %ebx, 0xc(%esp)\n" /* line 1819 */
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pSelf */
        "calll G_Say\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 1820 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bff70_001c0013:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1814 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1bff70_001bffae\n"
        ".Lf1bff70_001c0023:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1bff70_001bffae\n"
    );
}

/* line 1828 */
static __attribute__((naked))
void PlayerCmd_AllowSpectateTeam(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1828 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1834 */
        "testw %ax, %ax\n"
        "jne .Lf1c0040_001c00ee\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c0040_001c0153\n"
        ".Lf1c0040_001c007f:\n"
        "movl $0, (%esp)\n" /* line 1836 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 1839 */
        "cmpw 4(%edx), %ax\n"
        "je .Lf1c0040_001c0114\n"
        ".Lf1c0040_001c0097:\n"
        "cmpw 2(%edx), %ax\n" /* line 1841 */
        "je .Lf1c0040_001c013e\n"
        "cmpw 0x74(%edx), %ax\n" /* line 1843 */
        "je .Lf1c0040_001c014c\n"
        "cmpw 0x7c(%edx), %ax\n" /* line 1845 */
        "je .Lf1c0040_001c0145\n"
        "movl $str_002b6418, 4(%esp)\n" /* line 1848 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "xorl %esi, %esi\n" /* teamBit */
        "movl $1, (%esp)\n" /* line 1850 */
        "calll Scr_GetInt\n"
        "testl %eax, %eax\n" /* line 1852 */
        "jne .Lf1c0040_001c0129\n"
        ".Lf1c0040_001c00db:\n"
        "movl 0x158(%ebx), %eax\n" /* line 1855 | pSelf */
        "orl %esi, 0x2740(%eax)\n" /* teamBit */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1856 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c0040_001c00ee:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1834 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl $0, (%esp)\n" /* line 1836 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 1839 */
        "cmpw 4(%edx), %ax\n"
        "jne .Lf1c0040_001c0097\n"
        ".Lf1c0040_001c0114:\n"
        "movl $2, %esi\n" /* teamBit */
        ".Lf1c0040_001c0119:\n"
        "movl $1, (%esp)\n" /* line 1850 */
        "calll Scr_GetInt\n"
        "testl %eax, %eax\n" /* line 1852 */
        "je .Lf1c0040_001c00db\n"
        ".Lf1c0040_001c0129:\n"
        "movl 0x158(%ebx), %eax\n" /* line 1853 | pSelf */
        "notl %esi\n" /* teamBit */
        "andl %esi, 0x2740(%eax)\n" /* teamBit */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1856 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c0040_001c013e:\n"
        "movl $4, %esi\n" /* line 1841 | teamBit */
        "jmp .Lf1c0040_001c0119\n"
        ".Lf1c0040_001c0145:\n"
        "movl $0x10, %esi\n" /* line 1845 | teamBit */
        "jmp .Lf1c0040_001c0119\n"
        ".Lf1c0040_001c014c:\n"
        "movl $1, %esi\n" /* line 1843 | teamBit */
        "jmp .Lf1c0040_001c0119\n"
        ".Lf1c0040_001c0153:\n"
        "movl %edx, 4(%esp)\n" /* line 1834 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c0040_001c007f\n"
    );
}

/* line 1864 */
static __attribute__((naked))
void PlayerCmd_GetGuid(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1864 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %ebx\n" /* entref */
        "shrl $0x10, %eax\n" /* line 1866 */
        "testw %ax, %ax\n"
        "jne .Lf1c0170_001c01d0\n"
        "movzwl %bx, %ebx\n"
        "leal (%ebx, %ebx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1c0170_001c01e1\n"
        ".Lf1c0170_001c01a6:\n"
        "calll Scr_GetNumParam\n" /* line 1868 */
        "testl %eax, %eax\n"
        "je .Lf1c0170_001c01bb\n"
        "movl $str_002b6450, (%esp)\n" /* line 1869 */
        "calll Scr_Error\n"
        ".Lf1c0170_001c01bb:\n"
        "movl %ebx, (%esp)\n" /* line 1871 */
        "calll SV_GetGuid\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        "addl $0x14, %esp\n" /* line 1872 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp Scr_AddInt\n" /* line 1871 */
        ".Lf1c0170_001c01d0:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1866 */
        "calll Scr_ObjectError\n"
        "movzwl %bx, %ebx\n"
        "jmp .Lf1c0170_001c01a6\n"
        ".Lf1c0170_001c01e1:\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c0170_001c01a6\n"
    );
}

/* line 1950 */
__attribute__((naked))
BuiltinMethod Player_GetMethod(const char * *pName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1950 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1955 | pName */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* name */
        "xorl %esi, %esi\n" /* i */
        "movl $player_methods, %ebx\n"
        "xorl %edi, %edi\n"
        "movl %eax, %edx\n"
        "jmp .Lf1c01fc_001c022b\n"
        ".Lf1c01fc_001c021a:\n"
        "addl $1, %esi\n" /* line 1957 | i */
        "addl $0xc, %edi\n"
        "addl $0xc, %ebx\n"
        "cmpl $0x3b, %esi\n" /* i */
        "je .Lf1c01fc_001c0256\n"
        "movl -0x1c(%ebp), %edx\n" /* name */
        ".Lf1c01fc_001c022b:\n"
        "movl (%ebx), %eax\n" /* line 1959 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1c01fc_001c021a\n"
        "movl player_methods(%edi), %eax\n" /* line 1961 */
        "movl 8(%ebp), %edx\n" /* pName */
        "movl %eax, (%edx)\n"
        "movl player_methods+4(%edi), %eax\n" /* line 1962 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1966 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c01fc_001c0256:\n"
        "xorl %eax, %eax\n" /* line 1957 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1966 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 29 */
__attribute__((naked))
void PlayerCmd_giveWeapon(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 38 */
        "testw %ax, %ax\n"
        "jne .Lf1c0260_001c0346\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %edi\n" /* pSelf */
        "subl %eax, %edi\n" /* pSelf */
        "shll $4, %edi\n" /* pSelf */
        "addl imp_g_entities, %edi\n" /* pSelf */
        "movl 0x158(%edi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c0260_001c0428\n"
        ".Lf1c0260_001c02a0:\n"
        "movl $0, (%esp)\n" /* line 41 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 42 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %esi\n" /* weaponIndex */
        "movl 0x158(%edi), %eax\n" /* line 45 | pSelf */
        "movl %eax, -0x1c(%ebp)\n" /* ps */
        "movl %esi, %eax\n" /* line 46 | weaponIndex */
        "sarl $5, %eax\n"
        "movl %esi, %ecx\n" /* weaponIndex */
        "andl $0x1f, %ecx\n"
        "movl -0x1c(%ebp), %edx\n" /* ps */
        "movl 0x544(%edx, %eax, 4), %ebx\n" /* hadWeapon */
        "sarl %cl, %ebx\n" /* hadWeapon */
        "andl $1, %ebx\n" /* hadWeapon */
        "movl %esi, (%esp)\n" /* line 48 | weaponIndex */
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x20(%ebp)\n" /* weapDef */
        "movl %esi, (%esp)\n" /* line 51 | weaponIndex */
        "calll BG_DoesWeaponNeedSlot\n"
        "testb %al, %al\n"
        "jne .Lf1c0260_001c039f\n"
        ".Lf1c0260_001c02f3:\n"
        "movl %esi, 4(%esp)\n" /* line 54 | weaponIndex */
        "movl -0x1c(%ebp), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll G_GivePlayerWeapon\n"
        "testl %eax, %eax\n"
        "jne .Lf1c0260_001c0359\n"
        ".Lf1c0260_001c0306:\n"
        "movl -0x20(%ebp), %edx\n" /* line 58 | weapDef */
        "movl 0x1c8(%edx), %eax\n"
        "movl 0x1c0(%edx), %edx\n"
        "movl -0x1c(%ebp), %ecx\n" /* ps */
        "subl 0x144(%ecx, %eax, 4), %edx\n"
        "testl %edx, %edx\n" /* line 59 */
        "jle .Lf1c0260_001c033e\n"
        "xorl %eax, %eax\n" /* line 60 */
        "testl %ebx, %ebx\n" /* hadWeapon */
        "sete %al\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* weaponIndex */
        "movl %edi, (%esp)\n" /* pSelf */
        "calll Add_Ammo\n"
        /* } scope */
        ".Lf1c0260_001c033e:\n"
        "addl $0x3c, %esp\n" /* line 61 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c0260_001c0346:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 38 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n" /* pSelf */
        "jmp .Lf1c0260_001c02a0\n"
        ".Lf1c0260_001c0359:\n"
        "movl $1, 8(%esp)\n" /* line 55 */
        "movl $0x49, 4(%esp)\n"
        "movl $str_002b2ba8, (%esp)\n" /* "%c "%i"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, %eax\n" /* pSelf */
        "subl imp_g_entities, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "jmp .Lf1c0260_001c0306\n"
        ".Lf1c0260_001c039f:\n"
        "movl %esi, 4(%esp)\n" /* line 51 | weaponIndex */
        "movl -0x1c(%ebp), %ecx\n" /* ps */
        "movl %ecx, (%esp)\n"
        "calll BG_GetEmptySlotForWeapon\n"
        "testl %eax, %eax\n"
        "jne .Lf1c0260_001c02f3\n"
        "movl -0x1c(%ebp), %edx\n" /* line 52 | ps */
        "movsbl 0x556(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x1c(%ebp), %ecx\n" /* ps */
        "movsbl 0x555(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %ecx\n" /* weapDef */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x158(%edi), %eax\n" /* pSelf */
        "addl $0x2784, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b6468, (%esp)\n" /* "Cannot give %s weapon %s without having an empty weapon slot" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1c0260_001c02f3\n"
        ".Lf1c0260_001c0428:\n"
        "movl %edx, 4(%esp)\n" /* line 38 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c0260_001c02a0\n"
    );
}

/* line 195 */
__attribute__((naked))
void PlayerCmd_hasWeapon(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 195 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 200 */
        "testw %ax, %ax\n"
        "jne .Lf1c0446_001c04d3\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %ecx\n" /* pSelf */
        "testl %ecx, %ecx\n"
        "je .Lf1c0446_001c04e3\n"
        ".Lf1c0446_001c047c:\n"
        "movl $0, (%esp)\n" /* line 202 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 203 */
        "calll BG_FindWeaponIndexForName\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 205 */
        "je .Lf1c0446_001c04b1\n"
        "movl %eax, %edx\n"
        "sarl $5, %edx\n"
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%eax, %edx, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1c0446_001c04c2\n"
        ".Lf1c0446_001c04b1:\n"
        "movl $0, 8(%ebp)\n" /* line 208 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 209 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddBool\n" /* line 208 */
        ".Lf1c0446_001c04c2:\n"
        "movl $1, 8(%ebp)\n" /* line 206 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 209 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddBool\n" /* line 206 */
        ".Lf1c0446_001c04d3:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 200 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1c0446_001c047c\n"
        ".Lf1c0446_001c04e3:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c0446_001c047c\n"
    );
}

/* line 217 */
__attribute__((naked))
void PlayerCmd_switchToWeapon(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 217 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movw %ax, -0x1a(%ebp)\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 222 */
        "testw %ax, %ax\n"
        "jne .Lf1c0500_001c05b2\n"
        "movzwl -0x1a(%ebp), %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %esi\n" /* pSelf, iWeaponIndex */
        "testl %esi, %esi\n" /* iWeaponIndex */
        "je .Lf1c0500_001c0601\n"
        ".Lf1c0500_001c0543:\n"
        "movl $0, (%esp)\n" /* line 224 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* pszWeaponName */
        "movl %eax, (%esp)\n" /* line 225 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %esi\n" /* iWeaponIndex */
        "testl %eax, %eax\n" /* line 226 */
        "je .Lf1c0500_001c05dc\n"
        ".Lf1c0500_001c055f:\n"
        "movl %esi, %edx\n" /* line 229 | iWeaponIndex */
        "sarl $5, %edx\n"
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "movl %esi, %ecx\n" /* iWeaponIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%eax, %edx, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1c0500_001c059f\n"
        "movl %esi, 4(%esp)\n" /* line 231 | iWeaponIndex */
        "movzwl -0x1a(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SelectWeaponIndex\n"
        "movl $1, 8(%ebp)\n" /* line 233 | entref */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 237 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddBool\n" /* line 236 */
        ".Lf1c0500_001c059f:\n"
        "movl $0, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 237 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddBool\n" /* line 236 */
        ".Lf1c0500_001c05b2:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 222 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl $0, (%esp)\n" /* line 224 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* pszWeaponName */
        "movl %eax, (%esp)\n" /* line 225 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %esi\n" /* iWeaponIndex */
        "testl %eax, %eax\n" /* line 226 */
        "jne .Lf1c0500_001c055f\n"
        ".Lf1c0500_001c05dc:\n"
        "movl %edi, 4(%esp)\n" /* line 227 | pszWeaponName */
        "movl $str_002b64cc, (%esp)\n" /* "unknown weapon '%s'" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1c0500_001c055f\n"
        ".Lf1c0500_001c0601:\n"
        "movl %edx, 4(%esp)\n" /* line 222 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c0500_001c0543\n"
    );
}

/* line 245 */
__attribute__((naked))
void PlayerCmd_switchToOffhand(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 245 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movw %ax, -0x1a(%ebp)\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 250 */
        "testw %ax, %ax\n"
        "jne .Lf1c061e_001c06d0\n"
        "movzwl -0x1a(%ebp), %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %edi\n" /* pSelf, pszWeaponName */
        "testl %edi, %edi\n" /* pszWeaponName */
        "je .Lf1c061e_001c071f\n"
        ".Lf1c061e_001c0661:\n"
        "movl $0, (%esp)\n" /* line 252 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* pszWeaponName */
        "movl %eax, (%esp)\n" /* line 253 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %esi\n" /* iWeaponIndex */
        "testl %eax, %eax\n" /* line 254 */
        "je .Lf1c061e_001c06fa\n"
        ".Lf1c061e_001c067d:\n"
        "movl %esi, %edx\n" /* line 257 | iWeaponIndex */
        "sarl $5, %edx\n"
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "movl %esi, %ecx\n" /* iWeaponIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%eax, %edx, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1c061e_001c06bd\n"
        "movl %esi, 4(%esp)\n" /* line 259 | iWeaponIndex */
        "movzwl -0x1a(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SetEquippedOffHand\n"
        "movl $1, 8(%ebp)\n" /* line 261 | entref */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 265 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddBool\n" /* line 264 */
        ".Lf1c061e_001c06bd:\n"
        "movl $0, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 265 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddBool\n" /* line 264 */
        ".Lf1c061e_001c06d0:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 250 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl $0, (%esp)\n" /* line 252 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* pszWeaponName */
        "movl %eax, (%esp)\n" /* line 253 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %esi\n" /* iWeaponIndex */
        "testl %eax, %eax\n" /* line 254 */
        "jne .Lf1c061e_001c067d\n"
        ".Lf1c061e_001c06fa:\n"
        "movl %edi, 4(%esp)\n" /* line 255 | pszWeaponName */
        "movl $str_002b64cc, (%esp)\n" /* "unknown weapon '%s'" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1c061e_001c067d\n"
        ".Lf1c061e_001c071f:\n"
        "movl %edx, 4(%esp)\n" /* line 250 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c061e_001c0661\n"
    );
}

/* line 273 */
__attribute__((naked))
void PlayerCmd_giveStartAmmo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 280 */
        "testw %ax, %ax\n"
        "jne .Lf1c073c_001c07f9\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c073c_001c080c\n"
        ".Lf1c073c_001c077b:\n"
        "movl $0, (%esp)\n" /* line 282 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 283 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %esi\n" /* iWeaponIndex */
        "movl %eax, %edx\n" /* line 285 */
        "sarl $5, %edx\n"
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "movl %esi, %ecx\n" /* iWeaponIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%eax, %edx, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1c073c_001c07b5\n"
        /* } scope */
        ".Lf1c073c_001c07ae:\n"
        "addl $0x10, %esp\n" /* line 293 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c073c_001c07b5:\n"
        "movl %esi, (%esp)\n" /* line 288 | iWeaponIndex */
        "calll BG_GetWeaponDef\n"
        "movl 0x158(%ebx), %ecx\n" /* line 289 | pSelf */
        "movl 0x1c8(%eax), %edx\n"
        "movl 0x1c0(%eax), %eax\n"
        "subl 0x144(%ecx, %edx, 4), %eax\n"
        "testl %eax, %eax\n" /* line 290 */
        "jle .Lf1c073c_001c07ae\n"
        "movl $0, 0xc(%esp)\n" /* line 291 */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* iWeaponIndex */
        "movl %ebx, (%esp)\n" /* pSelf */
        "calll Add_Ammo\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 293 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c073c_001c07f9:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 280 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1c073c_001c077b\n"
        ".Lf1c073c_001c080c:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c073c_001c077b\n"
    );
}

/* line 301 */
__attribute__((naked))
void PlayerCmd_giveMaxAmmo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 301 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 308 */
        "testw %ax, %ax\n"
        "jne .Lf1c082a_001c08f6\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c082a_001c0909\n"
        ".Lf1c082a_001c086a:\n"
        "movl $0, (%esp)\n" /* line 310 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 311 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %edi\n" /* iWeaponIndex */
        "movl %eax, %edx\n" /* line 313 */
        "sarl $5, %edx\n"
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "movl %edi, %ecx\n" /* iWeaponIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%eax, %edx, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1c082a_001c08a5\n"
        /* } scope */
        ".Lf1c082a_001c089d:\n"
        "addl $0x1c, %esp\n" /* line 321 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c082a_001c08a5:\n"
        "movl %edi, (%esp)\n" /* line 316 | iWeaponIndex */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ebx\n" /* weapDef */
        "movl 0x1c8(%eax), %eax\n" /* line 317 */
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoTypeMax\n"
        "movl %eax, %ecx\n"
        "movl 0x158(%esi), %edx\n" /* pSelf */
        "movl 0x1c8(%ebx), %eax\n" /* weapDef */
        "subl 0x144(%edx, %eax, 4), %ecx\n"
        "testl %ecx, %ecx\n" /* line 318 */
        "jle .Lf1c082a_001c089d\n"
        "movl $0, 0xc(%esp)\n" /* line 319 */
        "movl %ecx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* iWeaponIndex */
        "movl %esi, (%esp)\n" /* pSelf */
        "calll Add_Ammo\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 321 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c082a_001c08f6:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 308 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1c082a_001c086a\n"
        ".Lf1c082a_001c0909:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c082a_001c086a\n"
    );
}

/* line 329 */
__attribute__((naked))
void PlayerCmd_getFractionStartAmmo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 329 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 336 */
        "testw %ax, %ax\n"
        "jne .Lf1c0926_001c09ef\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c0926_001c0a0b\n"
        ".Lf1c0926_001c0965:\n"
        "movl $0, (%esp)\n" /* line 338 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 339 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %ebx\n" /* iWeaponIndex */
        "movl %eax, %edx\n" /* line 341 */
        "sarl $5, %edx\n"
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "movl %ebx, %ecx\n" /* iWeaponIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%eax, %edx, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1c0926_001c09dd\n"
        "movl %ebx, (%esp)\n" /* line 343 | iWeaponIndex */
        "calll BG_GetWeaponDef\n"
        "movl 0x1c0(%eax), %ecx\n" /* line 345 */
        "testl %ecx, %ecx\n"
        "jle .Lf1c0926_001c09dd\n"
        "movl 0x158(%esi), %edx\n" /* line 347 | pSelf */
        "movl 0x1c8(%eax), %eax\n"
        "movl 0x144(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1c0926_001c0a02\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 352 */
        "cvtsi2ssl %ecx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 360 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 348 */
        ".Lf1c0926_001c09dd:\n"
        "movl $0x3f800000, 8(%ebp)\n" /* line 358 | entref */
        /* } scope */
        ".Lf1c0926_001c09e4:\n"
        "addl $0x10, %esp\n" /* line 360 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 348 */
        ".Lf1c0926_001c09ef:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 336 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1c0926_001c0965\n"
        ".Lf1c0926_001c0a02:\n"
        "movl $0, 8(%ebp)\n" /* line 348 | entref */
        "jmp .Lf1c0926_001c09e4\n"
        ".Lf1c0926_001c0a0b:\n"
        "movl %edx, 4(%esp)\n" /* line 336 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c0926_001c0965\n"
    );
}

/* line 368 */
__attribute__((naked))
void PlayerCmd_getFractionMaxAmmo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 368 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 375 */
        "testw %ax, %ax\n"
        "jne .Lf1c0a28_001c0b03\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl imp_g_entities, %esi\n" /* pSelf */
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c0a28_001c0b1f\n"
        ".Lf1c0a28_001c0a67:\n"
        "movl $0, (%esp)\n" /* line 377 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 378 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %ebx\n" /* iWeaponIndex */
        "movl %eax, %edx\n" /* line 380 */
        "sarl $5, %edx\n"
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "movl %ebx, %ecx\n" /* iWeaponIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%eax, %edx, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1c0a28_001c0af1\n"
        "movl %ebx, (%esp)\n" /* line 382 | iWeaponIndex */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ebx\n" /* iWeaponIndex */
        "movl 0x1c8(%eax), %eax\n" /* line 384 */
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoTypeMax\n"
        "testl %eax, %eax\n"
        "jle .Lf1c0a28_001c0af1\n"
        "movl 0x1c8(%ebx), %edx\n" /* line 386 | iWeaponIndex */
        "movl 0x158(%esi), %eax\n" /* pSelf */
        "movl 0x144(%eax, %edx, 4), %ebx\n" /* iWeaponIndex */
        "testl %ebx, %ebx\n" /* iWeaponIndex */
        "jle .Lf1c0a28_001c0b16\n"
        "movl %edx, (%esp)\n" /* line 390 */
        "calll BG_GetAmmoTypeMax\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 391 | iWeaponIndex */
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 399 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 387 */
        ".Lf1c0a28_001c0af1:\n"
        "movl $0x3f800000, 8(%ebp)\n" /* line 397 | entref */
        /* } scope */
        ".Lf1c0a28_001c0af8:\n"
        "addl $0x10, %esp\n" /* line 399 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 387 */
        ".Lf1c0a28_001c0b03:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 375 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1c0a28_001c0a67\n"
        ".Lf1c0a28_001c0b16:\n"
        "movl $0, 8(%ebp)\n" /* line 387 | entref */
        "jmp .Lf1c0a28_001c0af8\n"
        ".Lf1c0a28_001c0b1f:\n"
        "movl %edx, 4(%esp)\n" /* line 375 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c0a28_001c0a67\n"
    );
}

/* line 407 */
static __attribute__((naked))
void PlayerCmd_setOrigin(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 407 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 411 */
        "testw %ax, %ax\n"
        "jne .Lf1c0b3c_001c0c29\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c0b3c_001c0c3c\n"
        ".Lf1c0b3c_001c0b7a:\n"
        "leal -0x14(%ebp), %eax\n" /* line 413 | vNewOrigin */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, (%esp)\n" /* line 415 | pSelf */
        "calll SV_UnlinkEntity\n"
        "movl 0x158(%ebx), %edx\n" /* line 417 | pSelf */
        "leal 0x14(%edx), %ecx\n" /* to */
        /* { scope 2 */
        "movl -0x14(%ebp), %eax\n" /* line 199 | vNewOrigin */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl 0x158(%ebx), %eax\n" /* line 418 | pSelf */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "addss 0x1c(%eax), %xmm0\n"
        "movss %xmm0, 0x1c(%eax)\n"
        "movl 0x158(%ebx), %eax\n" /* line 421 | pSelf */
        "xorl $2, 0xa0(%eax)\n"
        "movl $1, 0xc(%esp)\n" /* line 424 */
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "movl %eax, (%esp)\n"
        "calll BG_PlayerStateToEntityState\n"
        "leal 0x138(%ebx), %ecx\n" /* line 427 | pSelf, to */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "leal 0x14(%eax), %edx\n" /* from */
        /* { scope 2 */
        "movl 0x14(%eax), %eax\n" /* line 199 */
        "movl %eax, 0x138(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 429 | pSelf */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 430 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c0b3c_001c0c29:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 411 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1c0b3c_001c0b7a\n"
        ".Lf1c0b3c_001c0c3c:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c0b3c_001c0b7a\n"
    );
}

/* line 677 */
static __attribute__((naked))
void PlayerCmd_finishPlayerDamage(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 677 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 709 */
        "testw %ax, %ax\n"
        "jne .Lf1c0c5a_001c0fb0\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %edi\n" /* pSelf */
        "subl %eax, %edi\n" /* pSelf */
        "shll $4, %edi\n" /* pSelf */
        "addl imp_g_entities, %edi\n" /* pSelf */
        "movl 0x158(%edi), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c0c5a_001c1353\n"
        ".Lf1c0c5a_001c0c9d:\n"
        "movl $2, (%esp)\n" /* line 711 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* damage */
        "testl %eax, %eax\n" /* line 712 */
        "jle .Lf1c0c5a_001c0f95\n"
        "movl $0, (%esp)\n" /* line 715 */
        "calll Scr_GetType\n"
        "testl %eax, %eax\n"
        "jne .Lf1c0c5a_001c1022\n"
        ".Lf1c0c5a_001c0cc7:\n"
        "movl imp_g_entities, %eax\n" /* line 716 */
        "addl $0x8bba0, %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* inflictor */
        ".Lf1c0c5a_001c0cd4:\n"
        "movl $1, (%esp)\n" /* line 717 */
        "calll Scr_GetType\n"
        "testl %eax, %eax\n"
        "jne .Lf1c0c5a_001c0ff9\n"
        ".Lf1c0c5a_001c0ce8:\n"
        "movl imp_g_entities, %edx\n" /* line 718 */
        "addl $0x8bba0, %edx\n"
        "movl %edx, -0x6c(%ebp)\n" /* attacker */
        ".Lf1c0c5a_001c0cf7:\n"
        "movl $3, (%esp)\n" /* line 720 */
        "calll Scr_GetInt\n"
        "movl %eax, -0x60(%ebp)\n" /* dflags */
        "movl $4, (%esp)\n" /* line 721 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n"
        "calll G_IndexForMeansOfDeath\n"
        "movl %eax, -0x5c(%ebp)\n" /* mod */
        "movl $5, (%esp)\n" /* line 722 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n"
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, -0x58(%ebp)\n" /* iWeapon */
        "movl $6, (%esp)\n" /* line 723 */
        "calll Scr_GetType\n"
        "testl %eax, %eax\n"
        "jne .Lf1c0c5a_001c0fde\n"
        "movl $0, -0x64(%ebp)\n" /* point */
        ".Lf1c0c5a_001c0d4f:\n"
        "movl $7, (%esp)\n" /* line 728 */
        "calll Scr_GetType\n"
        "testl %eax, %eax\n"
        "jne .Lf1c0c5a_001c0fc3\n"
        "movl $0, -0x68(%ebp)\n" /* dir */
        ".Lf1c0c5a_001c0d6a:\n"
        "movl $8, (%esp)\n" /* line 733 */
        "calll Scr_GetConstString\n"
        "movzwl %ax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_GetHitLocationIndexFromString\n"
        "movl %eax, -0x54(%ebp)\n" /* hitLoc */
        "movl $9, (%esp)\n" /* line 735 */
        "calll Scr_GetInt\n"
        "movl %eax, -0x50(%ebp)\n" /* psTimeOffset */
        "movl -0x68(%ebp), %eax\n" /* line 737 | dir */
        "testl %eax, %eax\n"
        "je .Lf1c0c5a_001c0fa0\n"
        "leal -0x3c(%ebp), %eax\n" /* line 738 | localdir */
        "movl %eax, 4(%esp)\n"
        "movl -0x68(%ebp), %ecx\n" /* dir */
        "movl %ecx, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        ".Lf1c0c5a_001c0db2:\n"
        "movl 0x174(%edi), %eax\n" /* line 743 | pSelf */
        "testb $8, %al\n"
        "jne .Lf1c0c5a_001c0dc6\n"
        "testb $4, -0x60(%ebp)\n" /* dflags */
        "je .Lf1c0c5a_001c104b\n"
        ".Lf1c0c5a_001c0dc6:\n"
        "testb $1, %al\n" /* line 783 */
        "jne .Lf1c0c5a_001c0f95\n"
        "movl -0x58(%ebp), %ebx\n" /* line 786 | iWeapon, tent */
        "testl %ebx, %ebx\n" /* tent */
        "jne .Lf1c0c5a_001c1157\n"
        ".Lf1c0c5a_001c0dd9:\n"
        "movl 0x158(%edi), %ebx\n" /* pSelf, tent */
        ".Lf1c0c5a_001c0ddf:\n"
        "addl %esi, 0x27e0(%ebx)\n" /* line 809 | damage, tent */
        "movl -0x68(%ebp), %edx\n" /* line 811 | dir */
        "testl %edx, %edx\n"
        "je .Lf1c0c5a_001c12f5\n"
        "movl 0x158(%edi), %edx\n" /* line 813 | pSelf */
        "leal 0x27e4(%edx), %ecx\n" /* to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | localdir */
        "movl %eax, 0x27e4(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl 0x158(%edi), %eax\n" /* line 814 | pSelf */
        "movl $0, 0x27f0(%eax)\n"
        ".Lf1c0c5a_001c0e21:\n"
        "testb $2, 0x174(%edi)\n" /* line 822 | pSelf */
        "je .Lf1c0c5a_001c0e3c\n"
        "movl 0x194(%edi), %eax\n" /* line 824 | pSelf */
        "movl %eax, %edx\n"
        "subl %esi, %edx\n" /* damage */
        "subl $1, %eax\n" /* line 825 */
        "testl %edx, %edx\n"
        "cmovlel %eax, %esi\n" /* damage */
        ".Lf1c0c5a_001c0e3c:\n"
        "movl imp_player_dmgtimer_maxTime, %eax\n" /* line 832 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n" /* max_damage_time */
        "movl 0x158(%edi), %edx\n" /* line 837 | pSelf */
        "movl imp_player_dmgtimer_timePerPoint, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl %esi, %xmm0\n" /* damage */
        "mulss 8(%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "addl %eax, 0x90(%edx)\n"
        "movl -0x68(%ebp), %eax\n" /* line 839 | dir */
        "testl %eax, %eax\n"
        "je .Lf1c0c5a_001c1119\n"
        "movl 0x158(%edi), %ebx\n" /* line 840 | pSelf, to */
        "movl -0x68(%ebp), %eax\n" /* dir */
        "movl %eax, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0x74(%ebp)\n"
        "cvttss2si -0x74(%ebp), %eax\n"
        "movl %eax, 0x98(%ebx)\n" /* to */
        "movl 0x158(%edi), %edx\n" /* line 845 | pSelf */
        "movss 0xec(%edx), %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 847 | 0.0f */
        "jb .Lf1c0c5a_001c1144\n"
        ".Lf1c0c5a_001c0eb2:\n"
        "cvtsi2ssl 0x98(%edx), %xmm0\n" /* line 850 */
        "subss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0x98(%edx)\n"
        "movl 0x158(%edi), %ebx\n" /* line 853 | pSelf, to */
        "cvtsi2ssl 0x90(%ebx), %xmm0\n" /* to */
        "ucomiss -0x4c(%ebp), %xmm0\n" /* max_damage_time */
        "jbe .Lf1c0c5a_001c0eed\n"
        "cvttss2si -0x4c(%ebp), %eax\n" /* line 854 | max_damage_time */
        "movl %eax, 0x90(%ebx)\n" /* to */
        "movl 0x158(%edi), %ebx\n" /* pSelf, to */
        ".Lf1c0c5a_001c0eed:\n"
        "movl 0x90(%ebx), %eax\n" /* line 857 | to */
        "movl %eax, 0x94(%ebx)\n" /* to */
        "subl %esi, 0x194(%edi)\n" /* line 861 | damage, pSelf */
        "movl -0x6c(%ebp), %edx\n" /* line 864 | attacker */
        "movl %edx, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl %esi, (%esp)\n" /* line 865 | damage */
        "calll Scr_AddInt\n"
        "movl $2, 8(%esp)\n" /* line 866 */
        "movl imp_scr_const, %eax\n"
        "movzwl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pSelf */
        "calll Scr_Notify\n"
        "movl 0x194(%edi), %edx\n" /* line 868 | pSelf */
        "testl %edx, %edx\n"
        "jle .Lf1c0c5a_001c127d\n"
        "movzbl 0x166(%edi), %eax\n" /* line 883 | pSelf */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl imp_entityHandlers, %eax\n"
        "movl 0x14(%eax), %ecx\n"
        "testl %ecx, %ecx\n" /* line 884 */
        "je .Lf1c0c5a_001c0f89\n"
        "movl -0x54(%ebp), %edx\n" /* line 885 | hitLoc */
        "movl %edx, 0x18(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* localdir */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x5c(%ebp), %eax\n" /* mod */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x64(%ebp), %edx\n" /* point */
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* damage */
        "movl -0x6c(%ebp), %eax\n" /* attacker */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pSelf */
        "calll *%ecx\n"
        ".Lf1c0c5a_001c0f83:\n"
        "movl 0x194(%edi), %edx\n" /* pSelf */
        ".Lf1c0c5a_001c0f89:\n"
        "movl 0x158(%edi), %eax\n" /* line 889 | pSelf */
        "movl %edx, 0x12c(%eax)\n"
        /* } scope */
        ".Lf1c0c5a_001c0f95:\n"
        "addl $0x9c, %esp\n" /* line 890 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c0c5a_001c0fa0:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x3c(%ebp)\n" /* localdir */
        "movl %eax, -0x38(%ebp)\n" /* line 184 */
        "movl %eax, -0x34(%ebp)\n" /* line 185 */
        "jmp .Lf1c0c5a_001c0db2\n"
        ".Lf1c0c5a_001c0fb0:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 709 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n" /* pSelf */
        "jmp .Lf1c0c5a_001c0c9d\n"
        ".Lf1c0c5a_001c0fc3:\n"
        "leal -0x24(%ebp), %ebx\n" /* line 730 | vDir, tent */
        "movl %ebx, 4(%esp)\n" /* tent */
        "movl $7, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, -0x68(%ebp)\n" /* tent, dir */
        "jmp .Lf1c0c5a_001c0d6a\n"
        ".Lf1c0c5a_001c0fde:\n"
        "leal -0x30(%ebp), %ebx\n" /* line 725 | vPoint, tent */
        "movl %ebx, 4(%esp)\n" /* tent */
        "movl $6, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, -0x64(%ebp)\n" /* tent, point */
        "jmp .Lf1c0c5a_001c0d4f\n"
        ".Lf1c0c5a_001c0ff9:\n"
        "movl $1, (%esp)\n" /* line 717 */
        "calll Scr_GetPointerType\n"
        "cmpl $0x15, %eax\n"
        "jne .Lf1c0c5a_001c0ce8\n"
        "movl $1, (%esp)\n" /* line 718 */
        "calll Scr_GetEntity\n"
        "movl %eax, -0x6c(%ebp)\n" /* attacker */
        "jmp .Lf1c0c5a_001c0cf7\n"
        ".Lf1c0c5a_001c1022:\n"
        "movl $0, (%esp)\n" /* line 715 */
        "calll Scr_GetPointerType\n"
        "cmpl $0x15, %eax\n"
        "jne .Lf1c0c5a_001c0cc7\n"
        "movl $1, (%esp)\n" /* line 716 */
        "calll Scr_GetEntity\n"
        "movl %eax, -0x70(%ebp)\n" /* inflictor */
        "jmp .Lf1c0c5a_001c0cd4\n"
        ".Lf1c0c5a_001c104b:\n"
        "movl 0x158(%edi), %ebx\n" /* line 750 | pSelf, tent */
        "movl 0xc(%ebx), %edx\n" /* tent */
        "testb $1, %dl\n"
        "je .Lf1c0c5a_001c1341\n"
        "movss lit4_002ed9ac, %xmm1\n" /* 0.019999999552965164f */
        ".Lf1c0c5a_001c1065:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 754 | damage */
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %edx\n"
        "cmpl $0x3c, %edx\n" /* line 756 */
        "jle .Lf1c0c5a_001c1334\n"
        "movl $0x3c, %edx\n"
        ".Lf1c0c5a_001c107f:\n"
        "testl $0x300, 0xa0(%ebx)\n" /* line 760 | tent */
        "jne .Lf1c0c5a_001c0dc6\n"
        "movl imp_g_knockback, %eax\n" /* line 764 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl %edx, %xmm0\n" /* scale */
        "mulss 8(%eax), %xmm0\n" /* scale */
        "divss lit4_002ed9b0, %xmm0\n" /* 250.0f, scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x38(%ebp), %xmm1\n"
        "movaps %xmm0, %xmm2\n" /* line 274 */
        "mulss -0x34(%ebp), %xmm2\n"
        /* } scope */
        "leal 0x20(%ebx), %eax\n" /* line 765 | tent, sum */
        /* { scope 2 */
        "mulss -0x3c(%ebp), %xmm0\n" /* line 240 | localdir */
        "addss 0x20(%ebx), %xmm0\n"
        "movss %xmm0, 0x20(%ebx)\n"
        "addss 4(%eax), %xmm1\n" /* line 241 */
        "movss %xmm1, 4(%eax)\n"
        "addss 8(%eax), %xmm2\n" /* line 242 */
        "movss %xmm2, 8(%eax)\n"
        /* } scope */
        "movl 0x158(%edi), %ebx\n" /* line 769 | pSelf, tent */
        "movl 0x10(%ebx), %eax\n" /* tent */
        "testl %eax, %eax\n"
        "jne .Lf1c0c5a_001c137d\n"
        "addl %edx, %edx\n" /* line 771 */
        "cmpl $0x31, %edx\n" /* line 772 */
        "jg .Lf1c0c5a_001c1388\n"
        "movl $0x32, %edx\n"
        ".Lf1c0c5a_001c10fe:\n"
        "movl %edx, 0x10(%ebx)\n" /* line 776 | tent */
        "movl 0x158(%edi), %eax\n" /* line 777 | pSelf */
        "orl $0x400, 0xc(%eax)\n"
        "movl 0x174(%edi), %eax\n" /* pSelf */
        "jmp .Lf1c0c5a_001c0dc6\n"
        ".Lf1c0c5a_001c1119:\n"
        "movl 0x158(%edi), %eax\n" /* line 842 | pSelf */
        "movl $0, 0x98(%eax)\n"
        "movl 0x158(%edi), %edx\n" /* line 845 | pSelf */
        "movss 0xec(%edx), %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 847 | 0.0f */
        "jae .Lf1c0c5a_001c0eb2\n"
        ".Lf1c0c5a_001c1144:\n"
        "jp .Lf1c0c5a_001c0eb2\n"
        "addss lit4_002ed638, %xmm1\n" /* line 848 | 360.0f */
        "jmp .Lf1c0c5a_001c0eb2\n"
        ".Lf1c0c5a_001c1157:\n"
        "movl -0x58(%ebp), %eax\n" /* line 786 | iWeapon */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x78(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1c0c5a_001c0dd9\n"
        "movl -0x58(%ebp), %edx\n" /* line 789 | iWeapon */
        "movl %edx, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "cmpl $1, 0x31c(%eax)\n"
        "sbbl %eax, %eax\n"
        "addl $0xb7, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %ecx\n" /* vPoint */
        "movl %ecx, (%esp)\n"
        "calll G_TempEntity\n"
        "movl %eax, %ebx\n" /* tent */
        "leal -0x3c(%ebp), %eax\n" /* line 790 | localdir */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0xa0(%ebx)\n" /* tent */
        "leal -0x3c(%ebp), %edx\n" /* line 791 | localdir */
        "movl %edx, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0xd8(%ebx)\n" /* tent */
        "movl $7, 0x88(%ebx)\n" /* line 792 | tent */
        "movl -0x6c(%ebp), %ecx\n" /* line 793 | attacker */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x74(%ebx)\n" /* tent */
        "movl 0x158(%edi), %eax\n" /* line 794 | pSelf */
        "movl 0xcc(%eax), %ecx\n"
        "movl %ecx, %eax\n"
        "sarl $5, %eax\n"
        "andl $0x1f, %ecx\n"
        "movl $1, -0x78(%ebp)\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "orl %edx, 0xf4(%ebx, %eax, 4)\n" /* tent */
        "movl -0x58(%ebp), %ecx\n" /* line 797 | iWeapon */
        "movl %ecx, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "cmpl $1, 0x31c(%eax)\n"
        "sbbl %eax, %eax\n"
        "addl $0xba, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vPoint */
        "movl %eax, (%esp)\n"
        "calll G_TempEntity\n"
        "movl $7, 0x88(%eax)\n" /* line 798 */
        "movl -0x6c(%ebp), %ecx\n" /* line 799 | attacker */
        "movl (%ecx), %edx\n"
        "movl %edx, 0x74(%eax)\n"
        "movl 0x158(%edi), %ebx\n" /* line 800 | pSelf, tent */
        "movl 0xcc(%ebx), %edx\n" /* tent */
        "movl %edx, 0x90(%eax)\n"
        "movl $0xffffffff, 0xf4(%eax)\n" /* line 801 */
        "movl $0xffffffff, 0xf8(%eax)\n" /* line 802 */
        "movl 0xcc(%ebx), %ecx\n" /* line 803 | tent */
        "movl %ecx, %edx\n"
        "sarl $5, %edx\n"
        "andl $0x1f, %ecx\n"
        "shll %cl, -0x78(%ebp)\n"
        "notl -0x78(%ebp)\n"
        "movl -0x78(%ebp), %ecx\n"
        "andl %ecx, 0xf4(%eax, %edx, 4)\n"
        "jmp .Lf1c0c5a_001c0ddf\n"
        ".Lf1c0c5a_001c127d:\n"
        "cmpl $0xfffffc19, %edx\n" /* line 870 */
        "jge .Lf1c0c5a_001c128f\n"
        "movl $0xfffffc19, 0x194(%edi)\n" /* line 871 | pSelf */
        ".Lf1c0c5a_001c128f:\n"
        "movzbl 0x166(%edi), %eax\n" /* line 873 | pSelf */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl imp_entityHandlers, %eax\n"
        "movl 0x18(%eax), %edx\n"
        "testl %edx, %edx\n" /* line 874 */
        "je .Lf1c0c5a_001c12e3\n"
        "movl -0x50(%ebp), %ecx\n" /* line 875 | psTimeOffset */
        "movl %ecx, 0x20(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* hitLoc */
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* localdir */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x58(%ebp), %ecx\n" /* iWeapon */
        "movl %ecx, 0x14(%esp)\n"
        "movl -0x5c(%ebp), %eax\n" /* mod */
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* damage */
        "movl -0x6c(%ebp), %ecx\n" /* attacker */
        "movl %ecx, 8(%esp)\n"
        "movl -0x70(%ebp), %eax\n" /* inflictor */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pSelf */
        "calll *%edx\n"
        ".Lf1c0c5a_001c12e3:\n"
        "cmpb $0, 0xfc(%edi)\n" /* line 878 | pSelf */
        "jne .Lf1c0c5a_001c0f83\n"
        "jmp .Lf1c0c5a_001c0f95\n"
        ".Lf1c0c5a_001c12f5:\n"
        "movl 0x158(%edi), %edx\n" /* line 818 | pSelf */
        "leal 0x27e4(%edx), %ebx\n" /* to */
        "leal 0x138(%edi), %ecx\n" /* pSelf, from */
        /* { scope 2 */
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x27e4(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "movl 0x158(%edi), %eax\n" /* line 819 | pSelf */
        "movl $1, 0x27f0(%eax)\n"
        "jmp .Lf1c0c5a_001c0e21\n"
        ".Lf1c0c5a_001c1334:\n"
        "testl %edx, %edx\n" /* line 760 */
        "je .Lf1c0c5a_001c0dc6\n"
        "jmp .Lf1c0c5a_001c107f\n"
        ".Lf1c0c5a_001c1341:\n"
        "andb $2, %dl\n" /* line 752 */
        "jne .Lf1c0c5a_001c1370\n"
        "movss lit4_002ed6f4, %xmm1\n" /* 0.30000001192092896f */
        "jmp .Lf1c0c5a_001c1065\n"
        ".Lf1c0c5a_001c1353:\n"
        "movl %edx, 4(%esp)\n" /* line 709 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c0c5a_001c0c9d\n"
        ".Lf1c0c5a_001c1370:\n"
        "movss lit4_002ed764, %xmm1\n" /* line 752 | 0.15000000596046448f */
        "jmp .Lf1c0c5a_001c1065\n"
        ".Lf1c0c5a_001c137d:\n"
        "movl 0x174(%edi), %eax\n" /* pSelf */
        "jmp .Lf1c0c5a_001c0dc6\n"
        ".Lf1c0c5a_001c1388:\n"
        "cmpl $0xc9, %edx\n" /* line 774 */
        "movl $0xc8, %eax\n"
        "cmovgel %eax, %edx\n"
        "jmp .Lf1c0c5a_001c10fe\n"
    );
}

/* line 1395 */
static __attribute__((naked))
void PlayerCmd_ClonePlayer(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1395 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1408 */
        "testw %ax, %ax\n"
        "jne .Lf1c139c_001c167e\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ecx\n"
        "subl %eax, %ecx\n"
        "shll $4, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* pSelf */
        "movl imp_g_entities, %ebx\n" /* corpseInfo */
        "addl %ebx, %ecx\n" /* corpseInfo */
        "movl %ecx, -0x1c(%ebp)\n" /* pSelf */
        "movl 0x158(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1c139c_001c1696\n"
        ".Lf1c139c_001c13e4:\n"
        "movl $0, (%esp)\n" /* line 1410 */
        "calll Scr_GetInt\n"
        "movl %eax, -0x28(%ebp)\n" /* deathAnimDuration */
        "movl -0x1c(%ebp), %eax\n" /* line 1412 | pSelf */
        "movl 0x158(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* client */
        "calll G_SpawnPlayerClone\n" /* line 1416 */
        "movl %eax, %edi\n" /* body */
        "movl -0x24(%ebp), %edx\n" /* line 1418 | client */
        "movl 0xcc(%edx), %eax\n"
        "movl %eax, 0x90(%edi)\n" /* body */
        "movl 0xa0(%edx), %eax\n" /* line 1419 */
        "andl $0xfffffffd, %eax\n"
        "movl 8(%edi), %edx\n" /* body */
        "andl $2, %edx\n"
        "orl %edx, %eax\n"
        "orl $0xa0000, %eax\n"
        "movl %eax, 8(%edi)\n" /* body */
        "movl -0x24(%ebp), %eax\n" /* line 1421 | client */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* body */
        "calll G_SetOrigin\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1422 | pSelf */
        "addl $0x144, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* body */
        "calll G_SetAngle\n"
        "movl $5, 0xc(%edi)\n" /* line 1424 | body */
        "movl imp_level, %eax\n" /* line 1425 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x10(%edi)\n" /* body */
        "leal 0x24(%edi), %ecx\n" /* line 1426 | body, to */
        "movl -0x24(%ebp), %edx\n" /* client, from */
        "addl $0x20, %edx\n" /* from */
        /* { scope 2 */
        "movl -0x24(%ebp), %ebx\n" /* line 199 | client */
        "movl 0x20(%ebx), %eax\n"
        "movl %eax, 0x24(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $2, 4(%edi)\n" /* line 1429 | body */
        "movb $1, 0x160(%edi)\n" /* line 1430 | body */
        "movl 0xcc(%ebx), %eax\n" /* line 1433 | corpseInfo */
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %eax, (%esp)\n" /* line 1434 */
        "calll DObjGetTree\n"
        "movl %eax, -0x20(%ebp)\n" /* tree */
        "movl %edi, %edx\n" /* body */
        "movl $2, %ecx\n"
        "movl imp_g_clonePlayerMaxVelocity, %ebx\n" /* corpseInfo */
        ".Lf1c139c_001c14bb:\n"
        "movl (%ebx), %eax\n" /* line 1438 | corpseInfo */
        "movss 8(%eax), %xmm1\n"
        "movss 0x24(%edx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1c139c_001c14d1\n"
        "movss %xmm1, 0x24(%edx)\n" /* line 1439 */
        ".Lf1c139c_001c14d1:\n"
        "addl $4, %edx\n"
        "subl $1, %ecx\n" /* line 1436 */
        "jne .Lf1c139c_001c14bb\n"
        "movl imp_level, %edx\n" /* line 1443 */
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, 0x1a8(%edi)\n" /* body */
        "calll G_GetFreePlayerCorpseIndex\n" /* line 1444 */
        "leal (%eax, %eax, 8), %edx\n" /* line 1445 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %eax, %edx\n"
        "movl imp_g_scr_data, %eax\n"
        "leal 0x10b0(%eax, %edx, 8), %esi\n"
        "leal 8(%esi), %ebx\n" /* corpseInfo */
        "movl (%edi), %eax\n" /* line 1446 | body */
        "movl %eax, 4(%ebx)\n" /* corpseInfo */
        "movl imp_level, %ecx\n" /* line 1447 */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 8(%ebx)\n" /* corpseInfo */
        "movb $1, 0x4c4(%ebx)\n" /* line 1448 | corpseInfo */
        "leal 0x14(%esi), %eax\n" /* line 1449 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x24(%ebp), %ecx\n" /* client */
        "movl 0xcc(%ecx), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl imp_level_bgs, %edx\n"
        "leal 0xb3bfc(%edx, %eax, 8), %eax\n"
        "movl $0x4b8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%esi), %eax\n" /* line 1450 */
        "movl %eax, 0x4b0(%ebx)\n" /* corpseInfo */
        "movl %eax, 4(%esp)\n" /* line 1451 */
        "movl -0x20(%ebp), %edx\n" /* tree */
        "movl %edx, (%esp)\n"
        "calll XAnimCloneAnimTree\n"
        "movl $0x3ff, 0x7c(%edi)\n" /* line 1454 | body */
        "movb $2, 0xf2(%edi)\n" /* line 1457 | body */
        "leal 0x104(%edi), %ecx\n" /* line 1458 | body, to */
        "movl -0x1c(%ebp), %edx\n" /* pSelf, from */
        "addl $0x104, %edx\n" /* from */
        /* { scope 2 */
        "movl -0x1c(%ebp), %ebx\n" /* line 199 | pSelf */
        "movl 0x104(%ebx), %eax\n"
        "movl %eax, 0x104(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x110(%edi), %ecx\n" /* line 1459 | body, to */
        "movl %ebx, %edx\n" /* corpseInfo, from */
        "addl $0x110, %edx\n" /* from */
        /* { scope 2 */
        "movl 0x110(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x110(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x120(%edi), %ecx\n" /* line 1460 | body, to */
        "addl $0x10, %edx\n" /* from */
        /* { scope 2 */
        "movl 0x120(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x120(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x12c(%edi), %ecx\n" /* line 1461 | body, to */
        "addl $0xc, %edx\n" /* from */
        /* { scope 2 */
        "movl 0x12c(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x12c(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl -0x24(%ebp), %edx\n" /* line 1463 | client */
        "movl 0x7c(%edx), %eax\n"
        "movl %eax, 0xcc(%edi)\n" /* body */
        "movl 0x84(%edx), %eax\n" /* line 1464 */
        "movl %eax, 0xd0(%edi)\n" /* body */
        "movl $0x10001, 0x184(%edi)\n" /* line 1466 | body */
        "movl $0x4002000, 0x11c(%edi)\n" /* line 1467 | body */
        "movl %edi, (%esp)\n" /* line 1468 | body */
        "calll SV_LinkEntity\n"
        "movl imp_level, %ecx\n" /* line 1470 */
        "movl 0x1ec(%ecx), %ecx\n"
        "addl %ecx, -0x28(%ebp)\n" /* deathAnimDuration */
        "movl -0x28(%ebp), %ebx\n" /* deathAnimDuration, corpseInfo */
        "movl %ebx, 0x190(%edi)\n" /* corpseInfo, body */
        "movb $0xc, 0x166(%edi)\n" /* line 1471 | body */
        "movl %edi, 8(%ebp)\n" /* line 1473 | body, entref */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1474 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp GScr_AddEntity\n" /* line 1473 */
        ".Lf1c139c_001c167e:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1408 */
        "calll Scr_ObjectError\n"
        "movl $0, -0x1c(%ebp)\n" /* pSelf */
        "jmp .Lf1c139c_001c13e4\n"
        ".Lf1c139c_001c1696:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c139c_001c13e4\n"
    );
}

/* line 133 */
__attribute__((naked))
void PlayerCmd_getCurrentWeapon(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 133 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 139 */
        "testw %ax, %ax\n"
        "jne .Lf1c16b4_001c172c\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %ecx\n" /* pSelf */
        "testl %ecx, %ecx\n"
        "je .Lf1c16b4_001c173c\n"
        ".Lf1c16b4_001c16ea:\n"
        "movl 0x158(%ebx), %eax\n" /* line 124 */
        "movl 0x26a8(%eax), %edx\n" /* line 141 */
        "testl %edx, %edx\n"
        "jne .Lf1c16b4_001c171b\n"
        "movl 0xd4(%eax), %eax\n" /* line 148 */
        "testl %eax, %eax\n" /* line 149 */
        "jle .Lf1c16b4_001c171b\n"
        "movl %eax, (%esp)\n" /* line 151 */
        "calll BG_GetWeaponDef\n"
        "movl (%eax), %eax\n" /* line 152 */
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 158 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 152 */
        ".Lf1c16b4_001c171b:\n"
        "movl $str_00218298, 8(%ebp)\n" /* line 156 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 158 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 156 */
        ".Lf1c16b4_001c172c:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 139 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1c16b4_001c16ea\n"
        ".Lf1c16b4_001c173c:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c16b4_001c16ea\n"
    );
}

/* line 166 */
__attribute__((naked))
void PlayerCmd_getCurrentOffhand(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 166 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 170 */
        "testw %ax, %ax\n"
        "jne .Lf1c1756_001c17ce\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c1756_001c17de\n"
        ".Lf1c1756_001c178c:\n"
        "movl 0x158(%ebx), %eax\n" /* line 124 */
        "movl 0x26a8(%eax), %ebx\n" /* line 172 | pSelf */
        "testl %ebx, %ebx\n" /* pSelf */
        "jne .Lf1c1756_001c17bd\n"
        "movl 0xd0(%eax), %eax\n" /* line 178 */
        "testl %eax, %eax\n"
        "jle .Lf1c1756_001c17bd\n"
        "movl %eax, (%esp)\n" /* line 180 */
        "calll BG_GetWeaponDef\n"
        "movl (%eax), %eax\n" /* line 181 */
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 187 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 181 */
        ".Lf1c1756_001c17bd:\n"
        "movl $str_00218298, 8(%ebp)\n" /* line 185 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 187 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 185 */
        ".Lf1c1756_001c17ce:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 170 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1c1756_001c178c\n"
        ".Lf1c1756_001c17de:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c1756_001c178c\n"
    );
}

/* line 988 */
static __attribute__((naked))
void PlayerCmd_GetWeaponSlotWeapon(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 988 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 995 */
        "testw %ax, %ax\n"
        "jne .Lf1c17f8_001c18b3\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c17f8_001c1909\n"
        ".Lf1c17f8_001c1838:\n"
        "movl 0x158(%ebx), %eax\n" /* line 997 | pSelf */
        "movl 0x26a8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1c17f8_001c189b\n"
        "movl $0, (%esp)\n" /* line 1003 */
        "calll Scr_GetConstString\n"
        "movzwl %ax, %esi\n" /* line 1004 */
        "movl %esi, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponSlotForName\n"
        "movl %eax, %edi\n" /* iWeapSlot */
        "testl %eax, %eax\n" /* line 1005 */
        "je .Lf1c17f8_001c18c6\n"
        "movl 0x158(%ebx), %eax\n" /* line 1008 | pSelf */
        "movzbl 0x554(%edi, %eax), %eax\n" /* iWeapSlot */
        "movsbl %al, %edx\n"
        "testb %al, %al\n" /* line 1009 */
        "je .Lf1c17f8_001c189b\n"
        ".Lf1c17f8_001c1882:\n"
        "movl %edx, (%esp)\n" /* line 1015 */
        "calll BG_GetWeaponDef\n"
        "movl (%eax), %eax\n" /* line 1016 */
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1017 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 1016 */
        ".Lf1c17f8_001c189b:\n"
        "movl imp_scr_const, %eax\n" /* line 1011 */
        "movzwl 0x74(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1017 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddConstString\n" /* line 1011 */
        ".Lf1c17f8_001c18b3:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 995 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1c17f8_001c1838\n"
        ".Lf1c17f8_001c18c6:\n"
        "movl %esi, (%esp)\n" /* line 1006 */
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b5e1c, (%esp)\n" /* "Unknown weaponslot name %s. Valid weaponslots are "primary" " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "movl 0x158(%ebx), %eax\n" /* line 1008 | pSelf */
        "movzbl 0x554(%edi, %eax), %eax\n" /* iWeapSlot */
        "movsbl %al, %edx\n"
        "testb %al, %al\n" /* line 1009 */
        "jne .Lf1c17f8_001c1882\n"
        "jmp .Lf1c17f8_001c189b\n"
        ".Lf1c17f8_001c1909:\n"
        "movl %edx, 4(%esp)\n" /* line 995 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c17f8_001c1838\n"
    );
}

/* line 1098 */
static __attribute__((naked))
void PlayerCmd_GetWeaponSlotAmmo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1098 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 1105 */
        "testw %ax, %ax\n"
        "jne .Lf1c1926_001c19f3\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl imp_g_entities, %ebx\n" /* pSelf */
        "movl 0x158(%ebx), %eax\n" /* pSelf */
        "testl %eax, %eax\n"
        "je .Lf1c1926_001c1a6c\n"
        ".Lf1c1926_001c1966:\n"
        "movl 0x158(%ebx), %eax\n" /* line 1107 | pSelf */
        "movl 0x26a8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1c1926_001c19b0\n"
        "movl $0, (%esp)\n" /* line 1113 */
        "calll Scr_GetConstString\n"
        "movzwl %ax, %esi\n" /* line 1114 | iWeapIndex */
        "movl %esi, (%esp)\n" /* iWeapIndex */
        "calll SL_ConvertToString\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponSlotForName\n"
        "movl %eax, %edi\n" /* iWeapSlot */
        "testl %eax, %eax\n" /* line 1115 */
        "je .Lf1c1926_001c1a06\n"
        "movl 0x158(%ebx), %eax\n" /* line 1118 | pSelf */
        "movzbl 0x554(%edi, %eax), %eax\n" /* iWeapSlot */
        "movsbl %al, %esi\n" /* iWeapIndex */
        "testb %al, %al\n" /* line 1119 */
        "jne .Lf1c1926_001c19c3\n"
        ".Lf1c1926_001c19b0:\n"
        "movl $0, 8(%ebp)\n" /* line 1121 | entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1133 */
        ".Lf1c1926_001c19c3:\n"
        "movl %esi, (%esp)\n" /* line 1125 | iWeapIndex */
        "calll BG_WeaponIsClipOnly\n"
        "testl %eax, %eax\n"
        "jne .Lf1c1926_001c1a48\n"
        "movl %esi, (%esp)\n" /* line 1132 | iWeapIndex */
        "calll BG_AmmoForWeapon\n"
        "movl 0x158(%ebx), %edx\n" /* line 1133 | pSelf */
        "movl 0x144(%edx, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1133 */
        ".Lf1c1926_001c19f3:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 1105 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "jmp .Lf1c1926_001c1966\n"
        ".Lf1c1926_001c1a06:\n"
        "movl %esi, (%esp)\n" /* line 1116 | iWeapIndex */
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b5e1c, (%esp)\n" /* "Unknown weaponslot name %s. Valid weaponslots are "primary" " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "movl 0x158(%ebx), %eax\n" /* line 1118 | pSelf */
        "movzbl 0x554(%edi, %eax), %eax\n" /* iWeapSlot */
        "movsbl %al, %esi\n" /* iWeapIndex */
        "testb %al, %al\n" /* line 1119 */
        "jne .Lf1c1926_001c19c3\n"
        "jmp .Lf1c1926_001c19b0\n"
        ".Lf1c1926_001c1a48:\n"
        "movl %esi, (%esp)\n" /* line 1127 | iWeapIndex */
        "calll BG_ClipForWeapon\n"
        "movl 0x158(%ebx), %edx\n" /* line 1128 | pSelf */
        "movl 0x344(%edx, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1133 */
        ".Lf1c1926_001c1a6c:\n"
        "movl %edx, 4(%esp)\n" /* line 1105 */
        "movl $str_002b5dd4, (%esp)\n" /* "entity %i is not a player" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf1c1926_001c1966\n"
    );
}

static const BuiltinMethodDef player_methods[] __attribute__((used)) = {
    {"giveweapon", (BuiltinMethod)PlayerCmd_giveWeapon, 0},
    {"takeweapon", (BuiltinMethod)PlayerCmd_takeWeapon, 0},
    {"takeallweapons", (BuiltinMethod)PlayerCmd_takeAllWeapons, 0},
    {"getcurrentweapon", (BuiltinMethod)PlayerCmd_getCurrentWeapon, 0},
    {"getcurrentoffhand", (BuiltinMethod)PlayerCmd_getCurrentOffhand, 0},
    {"hasweapon", (BuiltinMethod)PlayerCmd_hasWeapon, 0},
    {"switchtoweapon", (BuiltinMethod)PlayerCmd_switchToWeapon, 0},
    {"switchtooffhand", (BuiltinMethod)PlayerCmd_switchToOffhand, 0},
    {"givestartammo", (BuiltinMethod)PlayerCmd_giveStartAmmo, 0},
    {"givemaxammo", (BuiltinMethod)PlayerCmd_giveMaxAmmo, 0},
    {"getfractionstartammo", (BuiltinMethod)PlayerCmd_getFractionStartAmmo, 0},
    {"getfractionmaxammo", (BuiltinMethod)PlayerCmd_getFractionMaxAmmo, 0},
    {"setorigin", (BuiltinMethod)PlayerCmd_setOrigin, 0},
    {"setplayerangles", (BuiltinMethod)PlayerCmd_setAngles, 0},
    {"getplayerangles", (BuiltinMethod)PlayerCmd_getAngles, 0},
    {"usebuttonpressed", (BuiltinMethod)PlayerCmd_useButtonPressed, 0},
    {"attackbuttonpressed", (BuiltinMethod)PlayerCmd_attackButtonPressed, 0},
    {"meleebuttonpressed", (BuiltinMethod)PlayerCmd_meleeButtonPressed, 0},
    {"playerads", (BuiltinMethod)PlayerCmd_playerADS, 0},
    {"isonground", (BuiltinMethod)PlayerCmd_isOnGround, 0},
    {"pingplayer", (BuiltinMethod)PlayerCmd_pingPlayer, 0},
    {"setviewmodel", (BuiltinMethod)PlayerCmd_SetViewmodel, 0},
    {"getviewmodel", (BuiltinMethod)PlayerCmd_GetViewmodel, 0},
    {"sayall", (BuiltinMethod)PlayerCmd_SayAll, 0},
    {"sayteam", (BuiltinMethod)PlayerCmd_SayTeam, 0},
    {"showscoreboard", (BuiltinMethod)PlayerCmd_showScoreboard, 0},
    {"setspawnweapon", (BuiltinMethod)PlayerCmd_setSpawnWeapon, 0},
    {"dropitem", (BuiltinMethod)PlayerCmd_dropItem, 0},
    {"finishplayerdamage", (BuiltinMethod)PlayerCmd_finishPlayerDamage, 0},
    {"suicide", (BuiltinMethod)PlayerCmd_Suicide, 0},
    {"openmenu", (BuiltinMethod)PlayerCmd_OpenMenu, 0},
    {"openmenunomouse", (BuiltinMethod)PlayerCmd_OpenMenuNoMouse, 0},
    {"closemenu", (BuiltinMethod)PlayerCmd_CloseMenu, 0},
    {"closeingamemenu", (BuiltinMethod)PlayerCmd_CloseInGameMenu, 0},
    {"freezecontrols", (BuiltinMethod)PlayerCmd_FreezeControls, 0},
    {"disableweapon", (BuiltinMethod)PlayerCmd_DisableWeapon, 0},
    {"enableweapon", (BuiltinMethod)PlayerCmd_EnableWeapon, 0},
    {"setreverb", (BuiltinMethod)PlayerCmd_SetReverb, 0},
    {"deactivatereverb", (BuiltinMethod)PlayerCmd_DeactivateReverb, 0},
    {"setchannelvolumes", (BuiltinMethod)PlayerCmd_SetChannelVolumes, 0},
    {"deactivatechannelvolumes", (BuiltinMethod)PlayerCmd_DeactivateChannelVolumes, 0},
    {"getweaponslotweapon", (BuiltinMethod)PlayerCmd_GetWeaponSlotWeapon, 0},
    {"setweaponslotweapon", (BuiltinMethod)PlayerCmd_SetWeaponSlotWeapon, 0},
    {"getweaponslotammo", (BuiltinMethod)PlayerCmd_GetWeaponSlotAmmo, 0},
    {"setweaponslotammo", (BuiltinMethod)PlayerCmd_SetWeaponSlotAmmo, 0},
    {"getweaponslotclipammo", (BuiltinMethod)PlayerCmd_GetWeaponSlotClipAmmo, 0},
    {"setweaponslotclipammo", (BuiltinMethod)PlayerCmd_SetWeaponSlotClipAmmo, 0},
    {"setweaponclipammo", (BuiltinMethod)PlayerCmd_SetWeaponClipAmmo, 0},
    {"iprintln", (BuiltinMethod)iclientprintln, 0},
    {"iprintlnbold", (BuiltinMethod)iclientprintlnbold, 0},
    {"spawn", (BuiltinMethod)PlayerCmd_spawn, 0},
    {"setentertime", (BuiltinMethod)PlayerCmd_setEnterTime, 0},
    {"cloneplayer", (BuiltinMethod)PlayerCmd_ClonePlayer, 0},
    {"setclientcvar", (BuiltinMethod)PlayerCmd_SetClientDvar, 0},
    {"islookingat", (BuiltinMethod)ScrCmd_IsLookingAt, 0},
    {"playlocalsound", (BuiltinMethod)ScrCmd_PlayLocalSound, 0},
    {"istalking", (BuiltinMethod)PlayerCmd_IsTalking, 0},
    {"allowspectateteam", (BuiltinMethod)PlayerCmd_AllowSpectateTeam, 0},
    {"getguid", (BuiltinMethod)PlayerCmd_GetGuid, 0},
    {0, 0, 0},
};
