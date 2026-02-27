/* ASM dump from: g_items_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_items_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 */

extern qboolean itemRegistered[256]; /* 0x0 */

/* Entity accessor macros */
#define ENT_CLIENTNUM(e)  (*(int *)((byte *)(e) + 0x90))
#define ENT_ACTIVE(e)     (*(byte *)((byte *)(e) + 0x162))

void DroppedItemClearOwner(gentity_t *pSelf);
void G_GetItemClassname(const gitem_t *item, scr_string_t *out);
void ClearRegisteredItems(void);
void SaveRegisteredWeapons(void);
void SaveRegisteredItems(void);
void RegisterItem(int iItemIndex, qboolean bUpdateCS);
void G_RegisterWeapon(int weapIndex);
qboolean IsItemRegistered(int iItemIndex);
void FinishSpawningItem(gentity_t *ent);
void G_RunCorpseMove(gentity_t *ent);
void G_RunCorpse(gentity_t *ent);
void G_RunItem(gentity_t *ent);
int Add_Ammo(gentity_t *ent, int weapon, int count, qboolean fillClip);
gentity_t * Drop_Item(gentity_t *ent, const gitem_t *item, float angle, qboolean novelocity);
gentity_t * Drop_Weapon(gentity_t *pEnt, int iWeaponIndex, unsigned int tag);
void Touch_Item(gentity_t *ent, gentity_t *other, qboolean bTouched);
void Touch_Item_Auto(gentity_t *ent, gentity_t *other, qboolean bTouched);
void G_SpawnItem(gentity_t *ent, const gitem_t *item);

/* line 711 */
void DroppedItemClearOwner(gentity_t *pSelf)
{
    ENT_CLIENTNUM(pSelf) = 0x3FE; /* ENTITYNUM_NONE - 1 */
}

/* line 724 */
__attribute__((naked))
void G_GetItemClassname(const gitem_t *item, scr_string_t *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 724 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "movl 8(%ebp), %esi\n" /* item */
        "movl 0xc(%ebp), %edi\n" /* out */
        /* { scope 1 */
        "movl %esi, %ecx\n" /* line 730 | item */
        "subl 0x195eda8, %ecx\n"
        "sarl $2, %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "movl %ecx, %eax\n"
        "shll $0xa, %eax\n"
        "subl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $0xf, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 4), %ebx\n"
        "negl %ebx\n"
        "calll BG_GetNumWeapons\n" /* line 731 */
        "cmpl %eax, %ebx\n"
        "jg .Lf1ad72a_001ad7b0\n"
        "movl %ebx, (%esp)\n" /* line 733 */
        "calll BG_GetWeaponDef\n"
        "movl (%eax), %eax\n" /* line 734 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2b4978, 8(%esp)\n" /* "weapon_%s" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x118(%ebp), %ebx\n" /* classname */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, 4(%esp)\n" /* line 735 */
        "movl %edi, (%esp)\n" /* out */
        "calll G_SetConstString\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 742 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ad72a_001ad7b0:\n"
        "movl (%esi), %eax\n" /* line 740 | item */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* out */
        "calll G_SetConstString\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 742 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1109 */
void ClearRegisteredItems(void)
{
    memset(itemRegistered, 0, sizeof(itemRegistered));
    itemRegistered[0] = 1;
}

/* line 1124 */
__attribute__((naked))
void SaveRegisteredWeapons(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1124 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x201c, %esp\n"
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 1130 */
        "movl $0, 0x35fc(%eax)\n"
        "movb $0, -0x2018(%ebp)\n" /* line 1133 | szConfigString */
        "xorl %ebx, %ebx\n" /* weapDef */
        "movl $1, %esi\n" /* weapIndex */
        "leal -0x2018(%ebp), %edi\n" /* szConfigString */
        "jmp .Lf1ad7f8_001ad868\n"
        ".Lf1ad7f8_001ad829:\n"
        "testl %ebx, %ebx\n" /* line 1138 | weapDef */
        "je .Lf1ad7f8_001ad845\n"
        "movl $0x217914, 8(%esp)\n" /* line 1139 */
        "movl $0x2000, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_strncat\n"
        ".Lf1ad7f8_001ad845:\n"
        "movl %esi, (%esp)\n" /* line 1140 | weapIndex */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ebx\n" /* weapDef */
        "movl (%eax), %eax\n" /* line 1141 */
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_strncat\n"
        "addl $1, %esi\n" /* line 1136 | weapIndex */
        ".Lf1ad7f8_001ad868:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %esi\n" /* weapIndex */
        "jle .Lf1ad7f8_001ad829\n"
        "movl %edi, 4(%esp)\n" /* line 1143 */
        "movl $7, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "addl $0x201c, %esp\n" /* line 1144 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1155 */
__attribute__((naked))
void SaveRegisteredItems(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1155 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 1163 */
        "movl $0, 0x3600(%eax)\n"
        "movl 0x195edac, %eax\n" /* line 1168 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x130(%ebp)\n"
        "testl %eax, %eax\n"
        "jg .Lf1ad88c_001ad8f1\n"
        "movl $0, -0x12c(%ebp)\n" /* n */
        "movl -0x12c(%ebp), %eax\n" /* n */
        ".Lf1ad88c_001ad8c8:\n"
        "movb $0, -0x119(%ebp, %eax)\n" /* line 1182 */
        "leal -0x119(%ebp), %eax\n" /* line 1184 | string */
        "movl %eax, 4(%esp)\n"
        "movl $8, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "addl $0x13c, %esp\n" /* line 1185 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ad88c_001ad8f1:\n"
        "xorl %esi, %esi\n" /* line 1168 | i */
        "xorl %ecx, %ecx\n"
        "xorl %edi, %edi\n" /* digit */
        "movl $0, -0x12c(%ebp)\n" /* n */
        "movl $itemRegistered, %ebx\n"
        "jmp .Lf1ad88c_001ad916\n"
        ".Lf1ad88c_001ad908:\n"
        "addl $1, %esi\n" /* i */
        "addl $4, %ebx\n"
        "cmpl %esi, -0x130(%ebp)\n" /* i */
        "je .Lf1ad88c_001ad967\n"
        ".Lf1ad88c_001ad916:\n"
        "movl (%ebx), %eax\n" /* line 1170 */
        "testl %eax, %eax\n"
        "je .Lf1ad88c_001ad925\n"
        "movl $1, %eax\n" /* line 1171 */
        "shll %cl, %eax\n"
        "addl %eax, %edi\n" /* digit */
        ".Lf1ad88c_001ad925:\n"
        "addl $1, %ecx\n" /* line 1172 */
        "cmpl $4, %ecx\n" /* line 1173 */
        "jne .Lf1ad88c_001ad908\n"
        "movl $0x30, %eax\n" /* line 1175 */
        "cmpl $9, %edi\n" /* digit */
        "movl $0x57, %edx\n"
        "cmovgl %edx, %eax\n"
        "addl %edi, %eax\n" /* digit */
        "movl -0x12c(%ebp), %edx\n" /* n */
        "movb %al, -0x119(%ebp, %edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x12c(%ebp)\n" /* n */
        "xorl %edi, %edi\n" /* digit */
        "xorb %cl, %cl\n"
        "addl $1, %esi\n" /* line 1168 | i */
        "addl $4, %ebx\n"
        "cmpl %esi, -0x130(%ebp)\n" /* i */
        "jne .Lf1ad88c_001ad916\n"
        ".Lf1ad88c_001ad967:\n"
        "testl %ecx, %ecx\n" /* line 1180 */
        "je .Lf1ad88c_001ad99a\n"
        "movl $0x30, %eax\n" /* line 1181 */
        "cmpl $9, %edi\n" /* digit */
        "movl $0x57, %edx\n"
        "cmovgl %edx, %eax\n"
        "addl %edi, %eax\n" /* digit */
        "movl -0x12c(%ebp), %edx\n" /* n */
        "movb %al, -0x119(%ebp, %edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x12c(%ebp)\n" /* n */
        "movl %edx, %eax\n"
        "jmp .Lf1ad88c_001ad8c8\n"
        ".Lf1ad88c_001ad99a:\n"
        "movl -0x12c(%ebp), %eax\n" /* n */
        "jmp .Lf1ad88c_001ad8c8\n"
    );
}

/* line 1214 */
__attribute__((naked))
void RegisterItem(int iItemIndex, qboolean bUpdateCS)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1214 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* iItemIndex */
        "movl itemRegistered(, %ebx, 4), %eax\n" /* line 1218 */
        "testl %eax, %eax\n"
        "jne .Lf1ad9a6_001ada50\n"
        "movl 0x195f6a0, %eax\n" /* line 1224 */
        "movl 0x1c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1ad9a6_001ad9fe\n"
        /* { scope 1 */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 1228 | iItemIndex */
        "leal (%ebx, %eax, 2), %eax\n" /* iItemIndex */
        "shll $2, %eax\n"
        "addl 0x195eda8, %eax\n"
        "movl 0x14(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 1229 */
        "je .Lf1ad9a6_001ada56\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1ad9a6_001ada56\n"
        "movl %eax, 4(%esp)\n" /* line 1231 */
        "movl $0x2b4990, (%esp)\n" /* "game tried to register the item '%s' after initialization fi" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        ".Lf1ad9a6_001ad9fe:\n"
        "movl $1, itemRegistered(, %ebx, 4)\n" /* line 1233 */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 1235 | iItemIndex */
        "leal (%ebx, %eax, 2), %eax\n" /* iItemIndex */
        "leal (, %eax, 4), %ebx\n" /* iItemIndex */
        "addl 0x195eda8, %ebx\n" /* iItemIndex */
        "movl 8(%ebx), %eax\n" /* iItemIndex */
        "testl %eax, %eax\n"
        "je .Lf1ad9a6_001ada2b\n"
        "movl %eax, (%esp)\n" /* line 1236 */
        "calll G_ModelIndex\n"
        ".Lf1ad9a6_001ada2b:\n"
        "movl 0xc(%ebx), %eax\n" /* line 1237 | iItemIndex */
        "testl %eax, %eax\n"
        "je .Lf1ad9a6_001ada3a\n"
        "movl %eax, (%esp)\n" /* line 1238 */
        "calll G_ModelIndex\n"
        ".Lf1ad9a6_001ada3a:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1240 | bUpdateCS */
        "testl %edx, %edx\n"
        "je .Lf1ad9a6_001ada50\n"
        "movl 0x195f6a0, %eax\n" /* line 1241 */
        "movl $1, 0x3600(%eax)\n"
        ".Lf1ad9a6_001ada50:\n"
        "addl $0x14, %esp\n" /* line 1242 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ad9a6_001ada56:\n"
        "movl $0x2b4984, %eax\n" /* line 1229 */
        "movl %eax, 4(%esp)\n" /* line 1231 */
        "movl $0x2b4990, (%esp)\n" /* "game tried to register the item '%s' after initialization fi" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf1ad9a6_001ad9fe\n"
    );
}

/* line 1251 */
__attribute__((naked))
void G_RegisterWeapon(int weapIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1251 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edx\n" /* weapIndex */
        /* { scope 1 */
        "movl $1, itemRegistered(, %edx, 4)\n" /* line 1257 */
        "movl 0x195f6a0, %eax\n" /* line 1258 */
        "movl $1, 0x3600(%eax)\n"
        "movl $1, 0x35fc(%eax)\n" /* line 1259 */
        "movl %edx, (%esp)\n" /* line 1261 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %esi\n" /* weapDef */
        "movl 0x56c(%eax), %eax\n" /* line 1263 */
        "cmpb $0, (%eax)\n"
        "jne .Lf1ada76_001adb5a\n"
        ".Lf1ada76_001adabe:\n"
        "movl 0x570(%esi), %eax\n" /* line 1268 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1ada76_001adb23\n"
        ".Lf1ada76_001adac9:\n"
        "movl 0x1b4(%esi), %eax\n" /* line 1274 | weapDef */
        "movl %eax, (%esp)\n"
        "calll G_ModelIndex\n"
        "movl %eax, %ebx\n" /* modelindex */
        "testl %eax, %eax\n" /* line 1276 */
        "jne .Lf1ada76_001adaf2\n"
        ".Lf1ada76_001adadd:\n"
        "movl 0x38c(%esi), %eax\n" /* line 1279 | weapDef */
        "movl %eax, (%esp)\n"
        "calll G_ModelIndex\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1284 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ada76_001adaf2:\n"
        "movl %eax, (%esp)\n" /* line 1276 */
        "calll G_XModelBad\n"
        "testl %eax, %eax\n"
        "je .Lf1ada76_001adadd\n"
        "movl $0x2b4a2c, 4(%esp)\n" /* line 1277 */
        "movl %ebx, (%esp)\n" /* modelindex */
        "calll G_OverrideModel\n"
        "movl 0x38c(%esi), %eax\n" /* line 1279 | weapDef */
        "movl %eax, (%esp)\n"
        "calll G_ModelIndex\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1284 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ada76_001adb23:\n"
        "movl %eax, 4(%esp)\n" /* line 1270 */
        "leal 0x578(%esi), %eax\n" /* weapDef */
        "movl %eax, (%esp)\n"
        "calll G_GetHintStringIndex\n"
        "testl %eax, %eax\n"
        "jne .Lf1ada76_001adac9\n"
        "movl $0x20, 8(%esp)\n" /* line 1271 */
        "movl $0x2b49d4, 4(%esp)\n" /* "Too many different hintstring values on weapons. Max allowe" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1ada76_001adac9\n"
        ".Lf1ada76_001adb5a:\n"
        "movl %eax, 4(%esp)\n" /* line 1265 */
        "leal 0x574(%esi), %eax\n" /* weapDef */
        "movl %eax, (%esp)\n"
        "calll G_GetHintStringIndex\n"
        "testl %eax, %eax\n"
        "jne .Lf1ada76_001adabe\n"
        "movl $0x20, 8(%esp)\n" /* line 1266 */
        "movl $0x2b49d4, 4(%esp)\n" /* "Too many different hintstring values on weapons. Max allowe" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1ada76_001adabe\n"
    );
}

/* line 1294 */
qboolean IsItemRegistered(int iItemIndex)
{
    return itemRegistered[iItemIndex];
}

/* line 1021 */
__attribute__((naked))
void FinishSpawningItem(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1021 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1: vAngles, vAxis */
        "movb $0x11, 0x166(%edi)\n" /* line 1032 | ent */
        "testb $1, 0x170(%edi)\n" /* line 1034 | ent */
        "jne .Lf1adba6_001addc8\n"
        "movzwl 0x1ac(%edi), %eax\n" /* line 1042 | ent */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x195eda8, %eax\n"
        "cmpl $1, 0x1c(%eax, %edx, 4)\n"
        "je .Lf1adba6_001adda7\n"
        "movl $0xbf800000, %eax\n" /* line 191 */
        "movl %eax, -0x3c(%ebp)\n" /* mins */
        "movl %eax, -0x38(%ebp)\n" /* line 192 */
        "movl $0, -0x34(%ebp)\n" /* line 193 */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x48(%ebp)\n" /* maxs */
        "movl %eax, -0x44(%ebp)\n" /* line 192 */
        "movl $0x40000000, -0x40(%ebp)\n" /* line 193 */
        ".Lf1adba6_001adc0a:\n"
        "movl 0x184(%edi), %ebx\n" /* line 749 */
        "testl %ebx, %ebx\n"
        "movl $0x491, %eax\n"
        "cmovel %eax, %ebx\n"
        "leal 0x138(%edi), %eax\n" /* line 1054 | ent */
        "movl %eax, -0xac(%ebp)\n"
        "movl 0x138(%edi), %edx\n" /* line 199 */
        "movl %edx, -0x54(%ebp)\n" /* start */
        "movl 0x13c(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x50(%ebp)\n"
        "movss 0x140(%edi), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x4c(%ebp)\n"
        "subss 0x2ed99c, %xmm0\n" /* line 1055 | 4096.0f */
        "movl %edx, -0x30(%ebp)\n" /* line 191 | dest */
        "movl %eax, -0x2c(%ebp)\n" /* line 192 */
        "movss %xmm0, -0x28(%ebp)\n" /* line 193 */
        "movl %ebx, 0x18(%esp)\n" /* line 1056 | clipMask */
        "movl (%edi), %eax\n" /* ent */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* dest */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* maxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* mins */
        "movl %eax, 8(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "leal -0xa8(%ebp), %esi\n" /* tr */
        "movl %esi, (%esp)\n"
        "calll G_TraceCapsule\n"
        "cmpb $0, -0x85(%ebp)\n" /* line 1058 */
        "je .Lf1adba6_001add0d\n"
        "movl 0x138(%edi), %edx\n" /* line 199 */
        "movl %edx, -0x54(%ebp)\n" /* start */
        "movl 0x13c(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x50(%ebp)\n"
        "movss 0x140(%edi), %xmm1\n" /* line 201 */
        "movaps %xmm1, %xmm0\n" /* line 1061 */
        "subss 0x2ed908, %xmm0\n" /* 15.0f */
        "movss %xmm0, -0x4c(%ebp)\n"
        "subss 0x2ed99c, %xmm1\n" /* line 1063 | 4096.0f */
        "movl %edx, -0x30(%ebp)\n" /* line 191 | dest */
        "movl %eax, -0x2c(%ebp)\n" /* line 192 */
        "movss %xmm1, -0x28(%ebp)\n" /* line 193 */
        "movl %ebx, 0x18(%esp)\n" /* line 1064 | clipMask */
        "movl (%edi), %eax\n" /* ent */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* dest */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* maxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* mins */
        "movl %eax, 8(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_TraceCapsule\n"
        "cmpb $0, -0x85(%ebp)\n" /* line 1067 */
        "jne .Lf1adba6_001adddc\n"
        ".Lf1adba6_001add0d:\n"
        "movzwl -0x8c(%ebp), %eax\n" /* line 1075 */
        "movl %eax, 0x7c(%edi)\n" /* ent */
        "movss -0xa8(%ebp), %xmm2\n" /* line 1077 | tr, fraction */
        /* { scope 2 */
        "movss -0x54(%ebp), %xmm1\n" /* line 1203 | start */
        "movss -0x30(%ebp), %xmm0\n" /* dest */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n" /* endpos */
        "movss -0x50(%ebp), %xmm1\n" /* line 1204 */
        "movss -0x2c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm1\n" /* line 1205 */
        "movss -0x28(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x58(%ebp)\n"
        /* } scope */
        "leal -0x60(%ebp), %eax\n" /* line 1079 | endpos */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_SetOrigin\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 1082 | 1.0f */
        "ucomiss -0xa8(%ebp), %xmm0\n" /* tr */
        "ja .Lf1adba6_001ade22\n"
        ".Lf1adba6_001add94:\n"
        "movl %edi, (%esp)\n" /* line 1098 | ent */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 1099 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vAngles, vAxis */
        ".Lf1adba6_001adda7:\n"
        "movl $0xbf800000, %eax\n" /* line 191 */
        "movl %eax, -0x3c(%ebp)\n" /* mins */
        "movl %eax, -0x38(%ebp)\n" /* line 192 */
        "movl %eax, -0x34(%ebp)\n" /* line 193 */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x48(%ebp)\n" /* maxs */
        "movl %eax, -0x44(%ebp)\n" /* line 192 */
        "movl %eax, -0x40(%ebp)\n" /* line 193 */
        "jmp .Lf1adba6_001adc0a\n"
        ".Lf1adba6_001addc8:\n"
        "leal 0x138(%edi), %eax\n" /* line 1036 | ent */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_SetOrigin\n"
        "jmp .Lf1adba6_001add94\n"
        ".Lf1adba6_001adddc:\n"
        "movl -0xac(%ebp), %eax\n" /* line 1069 */
        "movl %eax, (%esp)\n"
        "calll vtos\n"
        "movl %eax, %ebx\n" /* clipMask */
        "movzwl 0x168(%edi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 8(%esp)\n" /* clipMask */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b4a44, (%esp)\n" /* "FinishSpawningItem: %s startsolid at %s
" */
        "calll Com_Printf\n"
        "movl %edi, (%esp)\n" /* line 1070 | ent */
        "calll G_FreeEntity\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 1099 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vAngles, vAxis */
        /* { scope 2 */
        ".Lf1adba6_001ade22:\n"
        "movl -0xa4(%ebp), %eax\n" /* line 199 */
        "movl %eax, -0x6c(%ebp)\n"
        "leal -0x84(%ebp), %ebx\n" /* line 200 | vAxis */
        "movl -0xa0(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x64(%ebp)\n"
        "movl $0, 0xc(%esp)\n" /* line 1088 */
        "movl $0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* clipMask */
        "leal 0x144(%edi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "leal -0x78(%ebp), %esi\n" /* line 1089 */
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* clipMask */
        "leal -0x6c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %ebx, 8(%esp)\n" /* line 1090 | clipMask */
        "leal -0x6c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        "leal -0x24(%ebp), %esi\n" /* line 1091 | vAngles */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* clipMask */
        "calll AxisToAngles\n"
        "movl 0x8c(%edi), %edx\n" /* line 1092 | ent */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "addl 0x195eda8, %eax\n"
        "cmpl $1, 0x1c(%eax)\n"
        "je .Lf1adba6_001adec9\n"
        ".Lf1adba6_001adeb8:\n"
        "movl %esi, 4(%esp)\n" /* line 1094 */
        "movl %edi, (%esp)\n" /* ent */
        "calll G_SetAngle\n"
        "jmp .Lf1adba6_001add94\n"
        ".Lf1adba6_001adec9:\n"
        "movss 0x2ed5f8, %xmm0\n" /* line 1093 | 90.0f */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "jmp .Lf1adba6_001adeb8\n"
    );
}

/* line 1471 */
__attribute__((naked))
void G_RunCorpseMove(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1471 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xfc, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1: rot, vAxis */
        "movl %edi, (%esp)\n" /* line 1491 | ent */
        "calll G_GetPlayerCorpseIndex\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 1492 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x195f6d0, %edx\n"
        "leal 0x10b0(%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        "movl %edx, -0xd0(%ebp)\n" /* corpseInfo */
        /* { scope 2 */
        "movl $1, 0x10(%esp)\n" /* line 1450 */
        "leal -0x48(%ebp), %edx\n" /* deltaChange */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* rot */
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimCalcDelta\n"
        /* } scope */
        "movl -0xd0(%ebp), %eax\n" /* line 1497 | corpseInfo */
        "cmpb $0, 0x4c4(%eax)\n"
        "je .Lf1adede_001ae0f8\n"
        "movb $0, -0xd9(%ebp)\n"
        ".Lf1adede_001adf58:\n"
        "leal -0x30(%ebp), %edx\n" /* line 1508 | origin */
        "movl %edx, 8(%esp)\n"
        "movl 0x195f6a0, %ecx\n"
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%edi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "cmpb $0, -0xd9(%ebp)\n" /* line 1511 */
        "jne .Lf1adede_001ae13f\n"
        ".Lf1adede_001adf87:\n"
        "movl 0x184(%edi), %esi\n" /* line 1525 | ent, mask */
        "leal 0x110(%edi), %eax\n" /* line 1530 | ent */
        "movl %eax, -0xd8(%ebp)\n"
        "leal 0x104(%edi), %edx\n" /* ent */
        "movl %edx, -0xd4(%ebp)\n"
        "leal 0x138(%edi), %ebx\n" /* ent */
        "movl %esi, 0x18(%esp)\n" /* mask */
        "movl 0x150(%edi), %eax\n" /* ent */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x30(%ebp), %ecx\n" /* origin */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0xd8(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x90(%ebp), %edx\n" /* tr */
        "movl %edx, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 1532 | tr, fraction */
        /* { scope 2 */
        "movss 0x138(%edi), %xmm0\n" /* line 1203 */
        "movss -0x30(%ebp), %xmm2\n" /* origin */
        "subss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n"
        "leal 0x13c(%edi), %eax\n" /* line 1204 */
        "movl %eax, -0xcc(%ebp)\n"
        "movss 0x13c(%edi), %xmm0\n"
        "movss -0x2c(%ebp), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "leal 0x140(%edi), %eax\n" /* line 1205 */
        "movl %eax, -0xc8(%ebp)\n"
        "movss 0x140(%edi), %xmm0\n"
        "movss -0x28(%ebp), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        /* } scope */
        "movss -0xbc(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x138(%edi)\n"
        "movss -0xc0(%ebp), %xmm2\n" /* line 200 */
        "movss %xmm2, 0x13c(%edi)\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 0x140(%edi)\n"
        "cmpb $0, -0x6d(%ebp)\n" /* line 1535 */
        "jne .Lf1adede_001ae130\n"
        ".Lf1adede_001ae09d:\n"
        "movl %edi, (%esp)\n" /* line 1538 | ent */
        "calll SV_LinkEntity\n"
        "movl %edi, (%esp)\n" /* line 1541 | ent */
        "calll G_RunThink\n"
        "cmpb $0, 0xfc(%edi)\n" /* line 1544 | ent */
        "je .Lf1adede_001ae0ed\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 1547 | 1.0f */
        "ucomiss -0x90(%ebp), %xmm1\n" /* tr */
        "jne .Lf1adede_001ae21e\n"
        "jp .Lf1adede_001ae21e\n"
        "movl -0xd0(%ebp), %eax\n" /* line 1550 | corpseInfo */
        "cmpb $0, 0x4c4(%eax)\n"
        "jne .Lf1adede_001ae0ed\n"
        "cmpb $0, -0xd9(%ebp)\n"
        "jne .Lf1adede_001ae2f6\n"
        /* } scope */
        ".Lf1adede_001ae0ed:\n"
        "addl $0xfc, %esp\n" /* line 1603 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: rot, vAxis */
        ".Lf1adede_001ae0f8:\n"
        "movss -0x48(%ebp), %xmm0\n" /* line 316 | deltaChange */
        "movss -0x44(%ebp), %xmm1\n"
        "movss -0x40(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 1497 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf1adede_001ae0ed\n"
        "movb $1, -0xd9(%ebp)\n"
        "jmp .Lf1adede_001adf58\n"
        ".Lf1adede_001ae130:\n"
        "movl $0, -0x90(%ebp)\n" /* line 1536 | tr */
        "jmp .Lf1adede_001ae09d\n"
        ".Lf1adede_001ae13f:\n"
        "movl $0, 0xc(%esp)\n" /* line 1513 */
        "leal -0x60(%ebp), %eax\n" /* right */
        "movl %eax, 8(%esp)\n"
        "leal -0x54(%ebp), %ebx\n" /* forward */
        "movl %ebx, 4(%esp)\n"
        "leal 0x144(%edi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "movss 0x3031e0, %xmm0\n" /* line 272 */
        "movss -0x60(%ebp), %xmm1\n" /* right */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x6c(%ebp)\n" /* left */
        "movss -0x5c(%ebp), %xmm1\n" /* line 273 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "movss -0x58(%ebp), %xmm1\n" /* line 274 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x64(%ebp)\n"
        "movl %ebx, (%esp)\n" /* line 1516 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x6c(%ebp), %eax\n" /* line 1517 | left */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x48(%ebp), %xmm1\n" /* line 1518 | deltaChange, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x54(%ebp), %xmm0\n" /* forward */
        "addss -0x30(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, -0x30(%ebp)\n" /* origin */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x50(%ebp), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss -0x4c(%ebp), %xmm1\n" /* line 290 */
        "addss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* } scope */
        "movss -0x44(%ebp), %xmm1\n" /* line 1519 | scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x6c(%ebp), %xmm0\n" /* left */
        "addss -0x30(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, -0x30(%ebp)\n" /* origin */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x68(%ebp), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss -0x64(%ebp), %xmm1\n" /* line 290 */
        "addss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "jmp .Lf1adede_001adf87\n"
        /* } scope */
        ".Lf1adede_001ae21e:\n"
        "movl $0x80000000, 8(%esp)\n" /* line 1579 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_PointContents\n"
        "testl %eax, %eax\n" /* line 1580 */
        "jne .Lf1adede_001ae6a4\n"
        "movl -0xd0(%ebp), %ecx\n" /* line 1586 | corpseInfo */
        "cmpb $0, 0x4c4(%ecx)\n"
        "je .Lf1adede_001ae0ed\n"
        "cmpb $0, -0x6e(%ebp)\n" /* line 1589 */
        "jne .Lf1adede_001ae592\n"
        ".Lf1adede_001ae25b:\n"
        "pxor %xmm1, %xmm1\n" /* line 183 */
        "movss %xmm1, 0x24(%edi)\n"
        "movss %xmm1, 0x28(%edi)\n" /* line 184 */
        "movss %xmm1, 0x2c(%edi)\n" /* line 185 */
        "cmpb $0, -0x6e(%ebp)\n" /* line 1379 */
        "jne .Lf1adede_001ae469\n"
        "movss -0x84(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1adede_001ae469\n"
        "movss (%ebx), %xmm0\n" /* line 240 */
        "addss -0x8c(%ebp), %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "movl -0xcc(%ebp), %edx\n" /* line 241 */
        "movss (%edx), %xmm0\n"
        "addss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movl -0xc8(%ebp), %ecx\n" /* line 242 */
        "movss (%ecx), %xmm0\n"
        "addss -0x84(%ebp), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "leal 0x18(%edi), %edx\n" /* line 1413 | to */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x18(%edi)\n"
        "movl -0xcc(%ebp), %ecx\n" /* line 200 */
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0xc8(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x195f6a0, %eax\n" /* line 1415 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "jmp .Lf1adede_001ae0ed\n"
        ".Lf1adede_001ae2f6:\n"
        "movl $1, 0xc(%edi)\n" /* line 1554 | ent */
        "movss -0xbc(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x18(%edi)\n"
        "movss -0xc0(%ebp), %xmm2\n" /* line 200 */
        "movss %xmm2, 0x1c(%edi)\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 0x20(%edi)\n"
        "movl $0, 0x10(%edi)\n" /* line 1556 | ent */
        "movl $0, 0x14(%edi)\n" /* line 1557 | ent */
        "movl $0, 0x24(%edi)\n" /* line 183 */
        "movl $0, 0x28(%edi)\n" /* line 184 */
        "movl $0, 0x2c(%edi)\n" /* line 185 */
        "movss -0x28(%ebp), %xmm0\n" /* line 1561 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movl %esi, 0x14(%esp)\n" /* line 1562 | mask */
        "movl 0x150(%edi), %eax\n" /* ent */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* origin */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xd8(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl -0xd4(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_TraceCapsuleComplete\n"
        "testl %eax, %eax\n"
        "je .Lf1adede_001ae0ed\n"
        "movl -0xd0(%ebp), %eax\n" /* line 1564 | corpseInfo */
        "movb $1, 0x4c4(%eax)\n"
        "movl $5, 0xc(%edi)\n" /* line 1566 | ent */
        "movss -0xbc(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x18(%edi)\n"
        "movss -0xc0(%ebp), %xmm2\n" /* line 200 */
        "movss %xmm2, 0x1c(%edi)\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 0x20(%edi)\n"
        "movl $0, 0x24(%edi)\n" /* line 183 */
        "movl $0, 0x28(%edi)\n" /* line 184 */
        "movl $0, 0x2c(%edi)\n" /* line 185 */
        "movss -0x48(%ebp), %xmm1\n" /* line 1569 | deltaChange, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x54(%ebp), %xmm0\n" /* forward */
        "addss 0x24(%edi), %xmm0\n"
        "movss %xmm0, 0x24(%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x50(%ebp), %xmm0\n"
        "addss 0x28(%edi), %xmm0\n"
        "movss %xmm0, 0x28(%edi)\n"
        "mulss -0x4c(%ebp), %xmm1\n" /* line 290 */
        "addss 0x2c(%edi), %xmm1\n"
        "movss %xmm1, 0x2c(%edi)\n"
        /* } scope */
        "movss -0x44(%ebp), %xmm1\n" /* line 1570 | scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x6c(%ebp), %xmm0\n" /* left */
        "addss 0x24(%edi), %xmm0\n"
        "movss %xmm0, 0x24(%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x68(%ebp), %xmm0\n"
        "addss 0x28(%edi), %xmm0\n"
        "movss %xmm0, 0x28(%edi)\n"
        "mulss -0x64(%ebp), %xmm1\n" /* line 290 */
        "addss 0x2c(%edi), %xmm1\n"
        "movss %xmm1, 0x2c(%edi)\n"
        /* } scope */
        "movl 0x195f6a0, %edx\n" /* line 1571 */
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, 0x10(%edi)\n" /* ent */
        "movl $0, 0x14(%edi)\n" /* line 1572 | ent */
        "jmp .Lf1adede_001ae0ed\n"
        /* { scope 2 */
        ".Lf1adede_001ae469:\n"
        "movl -0xd0(%ebp), %eax\n" /* line 1384 | corpseInfo */
        "movb $0, 0x4c4(%eax)\n"
        "movl $1, 0xc(%edi)\n" /* line 1385 */
        "leal 0x18(%edi), %eax\n" /* line 1386 | to */
        /* { scope 3 */
        "movss -0xbc(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x18(%edi)\n"
        "movss -0xc0(%ebp), %xmm2\n" /* line 200 */
        "movss %xmm2, 4(%eax)\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movl $0, 0x10(%edi)\n" /* line 1387 */
        "movl $0, 0x14(%edi)\n" /* line 1388 */
        "movss %xmm1, 0x24(%edi)\n" /* line 183 */
        "movss %xmm1, 0x28(%edi)\n" /* line 184 */
        "movss %xmm1, 0x2c(%edi)\n" /* line 185 */
        "movzwl -0x74(%ebp), %eax\n" /* line 1391 */
        "movl %eax, 0x7c(%edi)\n"
        "cmpb $0, -0x6e(%ebp)\n" /* line 1393 */
        "jne .Lf1adede_001ae57e\n"
        "movl -0x8c(%ebp), %eax\n" /* line 199 */
        "movl %eax, -0x9c(%ebp)\n"
        "leal -0xb4(%ebp), %ebx\n" /* line 200 | vAxis */
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, -0x98(%ebp)\n"
        "movl -0x84(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x94(%ebp)\n"
        "movl $0, 0xc(%esp)\n" /* line 1397 */
        "movl $0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x144(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "leal -0xa8(%ebp), %esi\n" /* line 1398 */
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x9c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %ebx, 8(%esp)\n" /* line 1399 */
        "leal -0x9c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        "leal -0x24(%ebp), %ecx\n" /* line 1400 | rot */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll AxisToAngles\n"
        "leal -0x24(%ebp), %eax\n" /* line 1401 | rot */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll G_SetAngle\n"
        ".Lf1adede_001ae571:\n"
        "movl %edi, (%esp)\n" /* line 1408 */
        "calll SV_LinkEntity\n"
        "jmp .Lf1adede_001ae0ed\n"
        ".Lf1adede_001ae57e:\n"
        "leal 0x144(%edi), %eax\n" /* line 1405 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll G_SetAngle\n"
        "jmp .Lf1adede_001ae571\n"
        /* } scope */
        ".Lf1adede_001ae592:\n"
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x3c(%ebp)\n" /* start */
        "movl -0xcc(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movss 0x2ed78c, %xmm0\n" /* line 1592 | 64.0f */
        "movl -0xc8(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "andl $0xfffeffff, %esi\n" /* line 1593 | mask */
        "movl %esi, 0x18(%esp)\n" /* mask */
        "movl 0x150(%edi), %eax\n" /* ent */
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl -0xd8(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0xd4(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "leal -0x90(%ebp), %ecx\n" /* tr */
        "movl %ecx, (%esp)\n"
        "calll G_TraceCapsule\n"
        "cmpb $0, -0x6e(%ebp)\n" /* line 1595 */
        "jne .Lf1adede_001ae25b\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 1597 | tr, fraction */
        /* { scope 2 */
        "movss -0x3c(%ebp), %xmm0\n" /* line 1203 | start */
        "movss (%ebx), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 1204 */
        "movl -0xcc(%ebp), %eax\n"
        "movss (%eax), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 1205 */
        "movl -0xc8(%ebp), %eax\n"
        "movss (%eax), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        /* } scope */
        "movss -0xbc(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, (%ebx)\n"
        "movss -0xc0(%ebp), %xmm0\n" /* line 200 */
        "movl -0xcc(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 201 */
        "movl -0xc8(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "jmp .Lf1adede_001ae25b\n"
        ".Lf1adede_001ae6a4:\n"
        "movl %edi, (%esp)\n" /* line 1582 | ent */
        "calll G_FreeEntity\n"
        "jmp .Lf1adede_001ae0ed\n"
    );
}

/* line 1627 */
__attribute__((naked))
void G_RunCorpse(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1627 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl %ebx, (%esp)\n" /* line 1629 | ent */
        "calll G_RunCorpseMove\n"
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 1612 */
        "calll G_GetPlayerCorpseIndex\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 1617 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x195f6d0, %edx\n"
        "leal 0x10c4(%edx, %eax, 8), %esi\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll BG_UpdatePlayerDObj\n"
        "movl (%ebx), %eax\n" /* line 1619 */
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n" /* line 1620 */
        "je .Lf1ae6b2_001ae724\n"
        "movl %esi, 8(%esp)\n" /* line 1623 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll BG_PlayerAnimation\n"
        /* } scope */
        ".Lf1ae6b2_001ae724:\n"
        "movl %ebx, 8(%ebp)\n" /* line 1631 | ent */
        "addl $0x10, %esp\n" /* line 1632 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp G_RunThink\n" /* line 1631 */
    );
}

/* line 1641 */
__attribute__((naked))
void G_RunItem(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1641 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1: vAxis, vAngles */
        "movl 0x7c(%edi), %edx\n" /* line 1654 | ent */
        "cmpl $0x3ff, %edx\n"
        "je .Lf1ae732_001ae794\n"
        "movl 0x195f6a0, %eax\n"
        "movl 4(%eax), %ecx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl 0xc(%eax, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1ae732_001ae794\n"
        ".Lf1ae732_001ae76b:\n"
        "movl 0xc(%edi), %eax\n" /* line 1669 | ent */
        "testl %eax, %eax\n"
        "je .Lf1ae732_001ae781\n"
        "cmpl $6, %eax\n"
        "je .Lf1ae732_001ae781\n"
        "movl 0x208(%edi), %eax\n" /* ent */
        "testl %eax, %eax\n"
        "je .Lf1ae732_001ae7e6\n"
        ".Lf1ae732_001ae781:\n"
        "movl %edi, (%esp)\n" /* line 1672 | ent */
        "calll G_RunThink\n"
        /* } scope */
        ".Lf1ae732_001ae789:\n"
        "addl $0xbc, %esp\n" /* line 1750 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vAxis, vAngles */
        ".Lf1ae732_001ae794:\n"
        "cmpl $5, 0xc(%edi)\n" /* line 1656 | ent */
        "je .Lf1ae732_001ae76b\n"
        "testb $1, 0x170(%edi)\n" /* line 1659 | ent */
        "jne .Lf1ae732_001ae76b\n"
        "movl $5, 0xc(%edi)\n" /* line 1661 | ent */
        "movl 0x195f6a0, %eax\n" /* line 1662 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x10(%edi)\n" /* ent */
        "leal 0x18(%edi), %ecx\n" /* line 1663 | ent, to */
        "leal 0x138(%edi), %edx\n" /* ent, from */
        /* { scope 2 */
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x18(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x24(%edi), %edx\n" /* line 1664 | ent, v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x24(%edi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "jmp .Lf1ae732_001ae76b\n"
        /* } scope */
        ".Lf1ae732_001ae7e6:\n"
        "leal -0x24(%ebp), %eax\n" /* line 1677 | origin */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f6a0, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "addl $0x32, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%edi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl 0x184(%edi), %ebx\n" /* line 749 */
        "testl %ebx, %ebx\n"
        "movl $0x491, %eax\n"
        "cmovel %eax, %ebx\n"
        "leal 0x138(%edi), %esi\n" /* line 1685 | ent */
        "leal -0x24(%ebp), %edx\n" /* origin */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0xa0(%ebp)\n"
        "movss -0xa0(%ebp), %xmm0\n"
        "ucomiss 0x2ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "jae .Lf1ae732_001ae85a\n"
        "jp .Lf1ae732_001ae85a\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1686 */
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x1c(%ebp)\n"
        ".Lf1ae732_001ae85a:\n"
        "leal 0x110(%edi), %eax\n" /* line 1688 | ent */
        "movl %eax, -0x9c(%ebp)\n"
        "leal 0x104(%edi), %edx\n" /* ent */
        "movl %edx, -0x98(%ebp)\n"
        "movl %ebx, 0x18(%esp)\n" /* mask */
        "movl 0x150(%edi), %eax\n" /* ent */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* origin */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x60(%ebp), %edx\n" /* tr */
        "movl %edx, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movss -0x60(%ebp), %xmm1\n" /* line 1690 | tr */
        "ucomiss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "jb .Lf1ae732_001ae92d\n"
        ".Lf1ae732_001ae8b2:\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | origin */
        "movl %eax, 0x138(%edi)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        ".Lf1ae732_001ae8c7:\n"
        "movl %edi, (%esp)\n" /* line 1718 | ent */
        "calll SV_LinkEntity\n"
        "movl %edi, (%esp)\n" /* line 1721 | ent */
        "calll G_RunThink\n"
        "cmpb $0, 0xfc(%edi)\n" /* line 1724 | ent */
        "je .Lf1ae732_001ae789\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 1727 | tr */
        "ucomiss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "jae .Lf1ae732_001ae789\n"
        "pxor %xmm0, %xmm0\n" /* line 1731 */
        "ucomiss -0x54(%ebp), %xmm0\n"
        "jae .Lf1ae732_001ae920\n"
        "movl $0x80000000, 8(%esp)\n" /* line 1738 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SV_PointContents\n"
        "testl %eax, %eax\n" /* line 1739 */
        "je .Lf1ae732_001aea7d\n"
        ".Lf1ae732_001ae920:\n"
        "movl %edi, (%esp)\n" /* line 1741 | ent */
        "calll G_FreeEntity\n"
        "jmp .Lf1ae732_001ae789\n"
        ".Lf1ae732_001ae92d:\n"
        "jp .Lf1ae732_001ae8b2\n" /* line 1690 */
        "movss -0x24(%ebp), %xmm0\n" /* line 1203 | origin */
        "movss %xmm0, -0x94(%ebp)\n"
        "movss 0x138(%edi), %xmm0\n"
        "movss -0x94(%ebp), %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "mulss %xmm1, %xmm4\n"
        "addss %xmm0, %xmm4\n"
        "movss %xmm4, -0x30(%ebp)\n" /* endpos */
        "movss -0x20(%ebp), %xmm6\n" /* line 1204 */
        "leal 0x13c(%edi), %eax\n"
        "movl %eax, -0x90(%ebp)\n"
        "movss 0x13c(%edi), %xmm0\n"
        "movaps %xmm6, %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "mulss %xmm1, %xmm3\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0x2c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm5\n" /* line 1205 */
        "leal 0x140(%edi), %edx\n"
        "movl %edx, -0x8c(%ebp)\n"
        "movss 0x140(%edi), %xmm0\n"
        "movaps %xmm5, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 1695 */
        "jne .Lf1ae732_001ae9da\n"
        "ucomiss 0x2ed738, %xmm1\n" /* 0.009999999776482582f */
        "jae .Lf1ae732_001ae9da\n"
        "jp .Lf1ae732_001ae9da\n"
        "movss -0x54(%ebp), %xmm7\n"
        "ucomiss 0x2ed5d8, %xmm7\n" /* 0.5f */
        "jb .Lf1ae732_001aeb4d\n"
        ".Lf1ae732_001ae9da:\n"
        "movl $3, 0xc(%edi)\n" /* line 1704 | ent */
        "movl 0x195f6a0, %eax\n" /* line 1705 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x10(%edi)\n" /* ent */
        "movl $0x32, 0x14(%edi)\n" /* line 1706 | ent */
        "leal 0x18(%edi), %edx\n" /* line 1707 | ent, to */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, 0x18(%edi)\n"
        "movl -0x90(%ebp), %ecx\n" /* line 200 */
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x24(%edi), %eax\n" /* line 1708 | ent, diff */
        /* { scope 2 */
        "movaps %xmm4, %xmm1\n" /* line 248 */
        "subss (%esi), %xmm1\n"
        "movss %xmm1, 0x24(%edi)\n"
        "movaps %xmm3, %xmm0\n" /* line 249 */
        "movl -0x90(%ebp), %edx\n"
        "subss (%edx), %xmm0\n"
        "movss %xmm0, 0x28(%edi)\n"
        "movaps %xmm2, %xmm0\n" /* line 250 */
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, 0x2c(%edi)\n"
        /* } scope */
        "movss 0x2ed694, %xmm0\n" /* line 272 | 20.0f */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 0x24(%edi)\n"
        "movss 4(%eax), %xmm1\n" /* line 273 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 0x28(%edi)\n"
        "mulss 8(%eax), %xmm0\n" /* line 274 */
        "movss %xmm0, 0x2c(%edi)\n"
        "movss %xmm4, (%esi)\n" /* line 199 */
        "movss %xmm3, 4(%esi)\n" /* line 200 */
        "movss %xmm2, 8(%esi)\n" /* line 201 */
        "jmp .Lf1ae732_001ae8c7\n"
        /* { scope 2 */
        ".Lf1ae732_001aea7d:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 199 */
        "movl %eax, -0x6c(%ebp)\n"
        "leal -0x84(%ebp), %ebx\n" /* line 200 | vAxis */
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x54(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x64(%ebp)\n"
        "movl $0, 0xc(%esp)\n" /* line 1431 */
        "movl $0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x144(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "leal -0x78(%ebp), %esi\n" /* line 1432 */
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x6c(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %ebx, 8(%esp)\n" /* line 1433 */
        "leal -0x6c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        "leal -0x3c(%ebp), %esi\n" /* line 1434 | vAngles */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll AxisToAngles\n"
        "movl 0x8c(%edi), %edx\n" /* line 1435 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "addl 0x195eda8, %eax\n"
        "cmpl $1, 0x1c(%eax)\n"
        "je .Lf1ae732_001aeb39\n"
        ".Lf1ae732_001aeb0a:\n"
        "movl %esi, 4(%esp)\n" /* line 1437 */
        "movl %edi, (%esp)\n"
        "calll G_SetAngle\n"
        /* } scope */
        "leal -0x30(%ebp), %eax\n" /* line 1747 | endpos */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_SetOrigin\n"
        "movzwl -0x44(%ebp), %eax\n" /* line 1748 */
        "movl %eax, 0x7c(%edi)\n" /* ent */
        "movl %edi, (%esp)\n" /* line 1749 | ent */
        "calll SV_LinkEntity\n"
        "jmp .Lf1ae732_001ae789\n"
        /* { scope 2 */
        ".Lf1ae732_001aeb39:\n"
        "movss 0x2ed5f8, %xmm0\n" /* line 1436 | 90.0f */
        "addss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "jmp .Lf1ae732_001aeb0a\n"
        /* } scope */
        ".Lf1ae732_001aeb4d:\n"
        "jp .Lf1ae732_001ae9da\n" /* line 1695 */
        "movss -0x5c(%ebp), %xmm3\n" /* line 304 */
        "movss -0x58(%ebp), %xmm2\n"
        "movss -0x94(%ebp), %xmm1\n" /* line 1698 */
        "subss 0x138(%edi), %xmm1\n" /* ent */
        "mulss %xmm3, %xmm1\n"
        "subss 0x13c(%edi), %xmm6\n" /* ent */
        "mulss %xmm2, %xmm6\n"
        "addss %xmm6, %xmm1\n"
        "subss 0x140(%edi), %xmm5\n" /* ent */
        "mulss %xmm7, %xmm5\n"
        "addss %xmm5, %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n" /* line 288 */
        "addss -0x94(%ebp), %xmm3\n"
        "movss %xmm3, -0x24(%ebp)\n" /* origin */
        "mulss %xmm0, %xmm2\n" /* line 289 */
        "addss -0x20(%ebp), %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n"
        "mulss %xmm0, %xmm7\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm7\n"
        "movss %xmm7, -0x1c(%ebp)\n"
        "movl %ebx, 0x18(%esp)\n" /* line 1700 | mask */
        "movl 0x150(%edi), %eax\n" /* ent */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* origin */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x9c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl -0x98(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* endpos */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movss -0x60(%ebp), %xmm1\n" /* line 1701 | tr, fraction */
        /* { scope 2 */
        "movss -0x30(%ebp), %xmm4\n" /* line 1203 | endpos */
        "movss -0x24(%ebp), %xmm0\n" /* origin */
        "subss %xmm4, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss %xmm4, -0x30(%ebp)\n" /* endpos */
        "movss -0x2c(%ebp), %xmm3\n" /* line 1204 */
        "movss -0x20(%ebp), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm2\n" /* line 1205 */
        "movss -0x1c(%ebp), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "jmp .Lf1ae732_001ae9da\n"
    );
}

/* line 69 */
__attribute__((naked))
int Add_Ammo(gentity_t *ent, int weapon, int count, qboolean fillClip)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1: ps */
        "movl 0xc(%ebp), %eax\n" /* line 71 | weapon */
        "movl %eax, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "movl %eax, %esi\n" /* ammoIndex */
        "movl 0xc(%ebp), %edx\n" /* line 72 | weapon */
        "movl %edx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl %eax, %edi\n" /* clipIndex */
        "movl 8(%ebp), %ecx\n" /* line 77 | ent */
        "movl 0x158(%ecx), %eax\n"
        "movl 0x144(%eax, %esi, 4), %ebx\n" /* inclip */
        "movl %ebx, -0x2c(%ebp)\n" /* inclip, oldAmmo */
        "movl 0x344(%eax, %edi, 4), %edx\n" /* line 78 */
        "movl %edx, -0x28(%ebp)\n" /* oldClip */
        "movl %ebx, %edx\n" /* line 80 | inclip */
        "addl 0x10(%ebp), %edx\n" /* count */
        "movl %edx, 0x144(%eax, %esi, 4)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 82 | weapon */
        "movl %ecx, (%esp)\n"
        "calll BG_WeaponIsClipOnly\n"
        "testl %eax, %eax\n"
        "jne .Lf1aec60_001aee4d\n"
        "movl $0, -0x30(%ebp)\n" /* noPack */
        ".Lf1aec60_001aecc6:\n"
        "movl 0x14(%ebp), %eax\n" /* line 88 | fillClip */
        "testl %eax, %eax\n"
        "jne .Lf1aec60_001aed7c\n"
        "movl -0x30(%ebp), %eax\n" /* noPack */
        "testl %eax, %eax\n"
        "jne .Lf1aec60_001aed7c\n"
        ".Lf1aec60_001aecdc:\n"
        "movl 8(%ebp), %ebx\n" /* line 98 | ent, inclip */
        "movl 0x158(%ebx), %eax\n" /* inclip */
        "movl 0x144(%eax, %esi, 4), %ebx\n" /* inclip */
        "movl %esi, (%esp)\n" /* ammoIndex */
        "calll BG_GetAmmoTypeMax\n"
        "cmpl %eax, %ebx\n" /* inclip */
        "jg .Lf1aec60_001aee30\n"
        ".Lf1aec60_001aecfc:\n"
        "movl 8(%ebp), %edx\n" /* line 103 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl 0x344(%eax, %edi, 4), %ebx\n" /* inclip */
        "movl %edi, (%esp)\n" /* clipIndex */
        "calll BG_GetAmmoClipSize\n"
        "cmpl %eax, %ebx\n" /* inclip */
        "jg .Lf1aec60_001aedf1\n"
        ".Lf1aec60_001aed1c:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 107 | weapon, inclip */
        "movl %ebx, (%esp)\n" /* inclip */
        "calll BG_GetWeaponDef\n"
        "movl 0x1e4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf1aec60_001aee22\n"
        ".Lf1aec60_001aed35:\n"
        "movl %ebx, 4(%esp)\n" /* line 109 | inclip */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetMaxPickupableAmmo\n"
        "movl %eax, %ebx\n" /* inclip */
        "testl %eax, %eax\n" /* line 110 */
        "js .Lf1aec60_001aeec1\n"
        "movl 8(%ebp), %ebx\n" /* ent, inclip */
        "movl 0x158(%ebx), %eax\n" /* inclip */
        ".Lf1aec60_001aed5d:\n"
        "movl 0x144(%eax, %esi, 4), %edx\n" /* line 131 */
        "subl -0x2c(%ebp), %edx\n" /* oldAmmo */
        "movl 0x344(%eax, %edi, 4), %eax\n"
        "subl -0x28(%ebp), %eax\n" /* oldClip */
        "leal (%edx, %eax), %eax\n"
        /* } scope */
        ".Lf1aec60_001aed74:\n"
        "addl $0x3c, %esp\n" /* line 132 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ps */
        ".Lf1aec60_001aed7c:\n"
        "movl 8(%ebp), %ecx\n" /* line 89 | ent */
        "movl 0x158(%ecx), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* ps */
        /* { scope 2: iAmmoIndex, iClipIndex */
        /* { scope 3 */
        "movl 0xc(%ebp), %ebx\n" /* line 35 | weapon, inclip */
        "movl %ebx, (%esp)\n" /* inclip */
        "calll BG_AmmoForWeapon\n"
        "movl %eax, -0x20(%ebp)\n" /* iAmmoIndex */
        "movl %ebx, (%esp)\n" /* line 36 | inclip */
        "calll BG_ClipForWeapon\n"
        "movl %eax, -0x1c(%ebp)\n" /* iClipIndex */
        "testl %ebx, %ebx\n" /* line 38 | inclip */
        "jle .Lf1aec60_001aedb2\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n" /* inclip */
        "jle .Lf1aec60_001aee71\n"
        /* } scope */
        /* } scope */
        ".Lf1aec60_001aedb2:\n"
        "movl -0x30(%ebp), %eax\n" /* line 92 | noPack */
        "testl %eax, %eax\n"
        "je .Lf1aec60_001aecdc\n"
        "movl 8(%ebp), %ecx\n" /* line 94 | ent */
        "movl 0x158(%ecx), %eax\n"
        "movl $0, 0x144(%eax, %esi, 4)\n"
        "movl 8(%ebp), %edx\n" /* line 103 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl 0x344(%eax, %edi, 4), %ebx\n" /* inclip */
        "movl %edi, (%esp)\n" /* clipIndex */
        "calll BG_GetAmmoClipSize\n"
        "cmpl %eax, %ebx\n" /* inclip */
        "jle .Lf1aec60_001aed1c\n"
        ".Lf1aec60_001aedf1:\n"
        "movl 8(%ebp), %ecx\n" /* line 104 | ent */
        "movl 0x158(%ecx), %ebx\n" /* inclip */
        "movl %edi, (%esp)\n" /* clipIndex */
        "calll BG_GetAmmoClipSize\n"
        "movl %eax, 0x344(%ebx, %edi, 4)\n" /* inclip */
        "movl 0xc(%ebp), %ebx\n" /* line 107 | weapon, inclip */
        "movl %ebx, (%esp)\n" /* inclip */
        "calll BG_GetWeaponDef\n"
        "movl 0x1e4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jns .Lf1aec60_001aed35\n"
        ".Lf1aec60_001aee22:\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl 0x158(%ecx), %eax\n"
        "jmp .Lf1aec60_001aed5d\n"
        ".Lf1aec60_001aee30:\n"
        "movl 8(%ebp), %eax\n" /* line 99 | ent */
        "movl 0x158(%eax), %ebx\n" /* inclip */
        "movl %esi, (%esp)\n" /* ammoIndex */
        "calll BG_GetAmmoTypeMax\n"
        "movl %eax, 0x144(%ebx, %esi, 4)\n" /* inclip */
        "jmp .Lf1aec60_001aecfc\n"
        ".Lf1aec60_001aee4d:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 84 | weapon, inclip */
        "movl %ebx, 4(%esp)\n" /* inclip */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_GivePlayerWeapon\n"
        "movl $1, -0x30(%ebp)\n" /* noPack */
        "jmp .Lf1aec60_001aecc6\n"
        /* { scope 2: iAmmoIndex, iClipIndex */
        /* { scope 3 */
        ".Lf1aec60_001aee71:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 41 | iClipIndex */
        "movl -0x24(%ebp), %edx\n" /* ps */
        "movl 0x344(%edx, %eax, 4), %ebx\n" /* inclip */
        "movl %eax, (%esp)\n" /* line 42 */
        "calll BG_GetAmmoClipSize\n"
        "subl %ebx, %eax\n" /* line 44 | inclip */
        "movl -0x20(%ebp), %ecx\n" /* line 47 | iAmmoIndex */
        "movl -0x24(%ebp), %ebx\n" /* ps, inclip */
        "movl 0x144(%ebx, %ecx, 4), %edx\n" /* inclip */
        "cmpl %edx, %eax\n"
        "jle .Lf1aec60_001aee9b\n"
        "movl %edx, %eax\n" /* line 38 */
        ".Lf1aec60_001aee9b:\n"
        "testl %eax, %eax\n" /* line 50 */
        "je .Lf1aec60_001aedb2\n"
        "subl %eax, %edx\n" /* line 52 */
        "movl -0x20(%ebp), %ecx\n" /* iAmmoIndex */
        "movl -0x24(%ebp), %ebx\n" /* ps, inclip */
        "movl %edx, 0x144(%ebx, %ecx, 4)\n" /* inclip */
        "movl -0x1c(%ebp), %edx\n" /* line 53 | iClipIndex */
        "addl %eax, 0x344(%ebx, %edx, 4)\n" /* inclip */
        "jmp .Lf1aec60_001aedb2\n"
        /* } scope */
        /* } scope */
        ".Lf1aec60_001aeec1:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 112 | weapon */
        "movl %ecx, (%esp)\n"
        "calll BG_WeaponIsClipOnly\n"
        "testl %eax, %eax\n"
        "jne .Lf1aec60_001aef0b\n"
        "movl 8(%ebp), %edx\n" /* line 124 | ent */
        "movl 0x158(%edx), %eax\n"
        "addl %ebx, 0x144(%eax, %esi, 4)\n" /* inclip */
        "movl 0x158(%edx), %eax\n" /* line 125 */
        "movl 0x144(%eax, %esi, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "jns .Lf1aec60_001aed5d\n"
        "movl $0, 0x144(%eax, %esi, 4)\n" /* line 126 */
        "movl 0x158(%edx), %eax\n"
        "jmp .Lf1aec60_001aed5d\n"
        ".Lf1aec60_001aef0b:\n"
        "movl 8(%ebp), %edx\n" /* line 114 | ent */
        "movl 0x158(%edx), %eax\n"
        "addl %ebx, 0x344(%eax, %edi, 4)\n" /* inclip */
        "movl 0x158(%edx), %eax\n" /* line 115 */
        "movl 0x344(%eax, %edi, 4), %ebx\n" /* inclip */
        "testl %ebx, %ebx\n" /* inclip */
        "jg .Lf1aec60_001aed5d\n"
        "movl $0, 0x344(%eax, %edi, 4)\n" /* line 117 */
        "movl 0xc(%ebp), %ecx\n" /* line 118 | weapon */
        "movl %ecx, 4(%esp)\n"
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1aec60_001aed74\n"
    );
}

/* line 825 */
__attribute__((naked))
gentity_t * Drop_Item(gentity_t *ent, const gitem_t *item, float angle, qboolean novelocity)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 825 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movss 0x10(%ebp), %xmm0\n" /* angle */
        /* { scope 1: ownerNum */
        "movl 0x148(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "addss -0x2c(%ebp), %xmm0\n" /* line 832 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "xorl %eax, %eax\n" /* line 833 */
        "movl %eax, -0x30(%ebp)\n" /* angles */
        "movl %eax, -0x28(%ebp)\n" /* line 834 */
        "movl 0x14(%ebp), %edi\n" /* line 836 | novelocity */
        "testl %edi, %edi\n"
        "je .Lf1aef58_001af370\n"
        "movl %eax, -0x24(%ebp)\n" /* line 183 | velocity */
        "movl %eax, -0x20(%ebp)\n" /* line 184 */
        "movl %eax, -0x1c(%ebp)\n" /* line 185 */
        ".Lf1aef58_001aef9b:\n"
        "leal 0x138(%ebx), %edx\n" /* line 844 | ent */
        /* { scope 2: dropped */
        "movl 0x138(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x3c(%ebp)\n" /* vPos */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x34(%ebp)\n"
        /* } scope */
        "movss 0x118(%ebx), %xmm0\n" /* line 848 | ent */
        "subss 0x10c(%ebx), %xmm0\n" /* ent */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl (%ebx), %ebx\n" /* line 850 | ent */
        "movl %ebx, -0x68(%ebp)\n" /* ent, ownerNum */
        /* { scope 2: dropped */
        /* { scope 3 */
        "movl 0x195eda8, %ebx\n" /* line 765 */
        "movl 0xc(%ebp), %ecx\n" /* item */
        "subl %ebx, %ecx\n"
        "sarl $2, %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "movl %ecx, %eax\n"
        "shll $0xa, %eax\n"
        "subl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $0xf, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 4), %edx\n"
        "negl %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movl itemRegistered(, %edx, 4), %esi\n" /* line 1218 */
        "testl %esi, %esi\n"
        "jne .Lf1aef58_001af0a5\n"
        "movl 0x195f6a0, %eax\n" /* line 1224 */
        "movl 0x1c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1aef58_001af05f\n"
        /* { scope 4 */
        "leal (%edx, %edx, 4), %eax\n" /* line 1228 */
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0x14(%ebx, %eax, 4), %eax\n" /* ent */
        "testl %eax, %eax\n" /* line 1229 */
        "je .Lf1aef58_001af450\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1aef58_001af450\n"
        "movl %eax, 4(%esp)\n" /* line 1231 */
        "movl $0x2b4990, (%esp)\n" /* "game tried to register the item '%s' after initialization fi" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl 0x195eda8, %ebx\n" /* ent */
        /* } scope */
        ".Lf1aef58_001af05f:\n"
        "movl -0x70(%ebp), %eax\n" /* line 1233 */
        "movl $1, itemRegistered(, %eax, 4)\n"
        "movl %eax, %edx\n" /* line 1235 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* ent */
        "movl 8(%ebx), %eax\n" /* ent */
        "testl %eax, %eax\n"
        "je .Lf1aef58_001af087\n"
        "movl %eax, (%esp)\n" /* line 1236 */
        "calll G_ModelIndex\n"
        ".Lf1aef58_001af087:\n"
        "movl 0xc(%ebx), %eax\n" /* line 1237 | ent */
        "testl %eax, %eax\n"
        "je .Lf1aef58_001af096\n"
        "movl %eax, (%esp)\n" /* line 1238 */
        "calll G_ModelIndex\n"
        ".Lf1aef58_001af096:\n"
        "movl 0x195f6a0, %eax\n" /* line 1241 */
        "movl $1, 0x3600(%eax)\n"
        ".Lf1aef58_001af0a5:\n"
        "calll G_Spawn\n" /* line 768 */
        "movl %eax, -0x64(%ebp)\n" /* dropped */
        "movl 0x195f724, %eax\n" /* line 667 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "testl %eax, %eax\n" /* line 670 */
        "jle .Lf1aef58_001af1e3\n"
        "movl 0x195f6a0, %ecx\n" /* line 672 */
        "movl 0x1d58(%ecx), %eax\n"
        "testl %eax, %eax\n" /* line 673 */
        "je .Lf1aef58_001af478\n"
        "movl %ecx, %edx\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movl $0, -0x60(%ebp)\n"
        "movl $0, -0x4c(%ebp)\n"
        "movl %ecx, -0x54(%ebp)\n"
        "movl 0x1e4(%edx), %edx\n" /* line 677 */
        "testl %edx, %edx\n"
        "jg .Lf1aef58_001af150\n"
        ".Lf1aef58_001af100:\n"
        "movss 0x2ed9a0, %xmm0\n" /* 999998029824.0f */
        ".Lf1aef58_001af108:\n"
        "ucomiss -0x5c(%ebp), %xmm0\n" /* line 690 */
        "jbe .Lf1aef58_001af119\n"
        "movl -0x60(%ebp), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        ".Lf1aef58_001af119:\n"
        "addl $1, -0x60(%ebp)\n" /* line 670 */
        "movl -0x60(%ebp), %ebx\n"
        "cmpl %ebx, -0x58(%ebp)\n"
        "je .Lf1aef58_001af1ea\n"
        "movl -0x54(%ebp), %ebx\n" /* line 672 */
        "movl 0x1d5c(%ebx), %eax\n"
        "addl $4, %ebx\n"
        "movl %ebx, -0x54(%ebp)\n"
        "testl %eax, %eax\n" /* line 673 */
        "je .Lf1aef58_001af35d\n"
        "movl 0x195f6a0, %edx\n"
        "movl 0x1e4(%edx), %edx\n" /* line 677 */
        "testl %edx, %edx\n"
        "jle .Lf1aef58_001af100\n"
        ".Lf1aef58_001af150:\n"
        "xorl %esi, %esi\n"
        "movss 0x2ed9a0, %xmm0\n" /* 999998029824.0f */
        "xorl %ebx, %ebx\n"
        "addl $0x138, %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl 0x195f688, %edi\n"
        "addl $0x138, %edi\n"
        "jmp .Lf1aef58_001af18f\n"
        ".Lf1aef58_001af172:\n"
        "movl %ecx, %edx\n"
        ".Lf1aef58_001af174:\n"
        "addl $1, %esi\n"
        "addl $0x230, %edi\n"
        "addl $0x28a4, %ebx\n"
        "cmpl %esi, 0x1e4(%edx)\n"
        "jle .Lf1aef58_001af108\n"
        ".Lf1aef58_001af18f:\n"
        "movl %ebx, %eax\n" /* line 679 */
        "movl 0x195f6a0, %ecx\n"
        "addl (%ecx), %eax\n"
        "cmpl $2, 0x26c4(%eax)\n" /* line 680 */
        "jne .Lf1aef58_001af172\n"
        "movl 0x26a8(%eax), %eax\n" /* line 682 */
        "testl %eax, %eax\n"
        "je .Lf1aef58_001af1b4\n"
        ".Lf1aef58_001af1ac:\n"
        "movl 0x195f6a0, %edx\n"
        "jmp .Lf1aef58_001af174\n"
        ".Lf1aef58_001af1b4:\n"
        "movl -0x74(%ebp), %eax\n" /* line 685 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x50(%ebp)\n"
        "movss -0x88(%ebp), %xmm0\n" /* line 686 */
        "ucomiss -0x50(%ebp), %xmm0\n"
        "jbe .Lf1aef58_001af1ac\n"
        "movss -0x50(%ebp), %xmm0\n"
        "jmp .Lf1aef58_001af1ac\n"
        ".Lf1aef58_001af1e3:\n"
        "movl $0, -0x4c(%ebp)\n" /* line 670 */
        ".Lf1aef58_001af1ea:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 699 */
        "movl 0x195f6a0, %ecx\n"
        "movl 0x1d58(%ecx, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_FreeEntity\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 700 */
        "movl 0x195f6a0, %eax\n"
        "movl $0, 0x1d58(%eax, %ebx, 4)\n"
        "movl %ebx, %edx\n"
        "movl %eax, %ecx\n"
        ".Lf1aef58_001af219:\n"
        "movl -0x64(%ebp), %ebx\n" /* line 769 | dropped */
        "movl %ebx, 0x1d58(%ecx, %edx, 4)\n"
        "movl $3, 4(%ebx)\n" /* line 771 */
        "movl -0x70(%ebp), %eax\n" /* line 772 */
        "movl %eax, 0x8c(%ebx)\n"
        "movl %ebx, %eax\n" /* line 774 */
        "addl $0x168, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl %edx, (%esp)\n"
        "calll G_GetItemClassname\n"
        "movl -0x70(%ebp), %ecx\n" /* line 776 */
        "movw %cx, 0x1ac(%ebx)\n"
        "movl 0xc(%ebp), %ebx\n" /* line 777 | item */
        "cmpl $1, 0x1c(%ebx)\n"
        "je .Lf1aef58_001af415\n"
        "movl -0x64(%ebp), %edx\n" /* line 784 | dropped, v */
        "addl $0x104, %edx\n" /* v */
        /* { scope 4 */
        "movl $0xbf800000, %eax\n" /* line 191 */
        "movl -0x64(%ebp), %ebx\n" /* dropped */
        "movl %eax, 0x104(%ebx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "movl %ebx, %edx\n" /* line 785 | v */
        "addl $0x110, %edx\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, 0x110(%ebx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl $0x40000000, 8(%edx)\n" /* line 193 */
        /* } scope */
        ".Lf1aef58_001af29e:\n"
        "movl -0x64(%ebp), %eax\n" /* line 787 | dropped */
        "movl $0x405c0108, 0x11c(%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 788 | item */
        "cmpl $2, 0x1c(%edx)\n"
        "je .Lf1aef58_001af2be\n"
        "movl $0x407c0108, 0x11c(%eax)\n" /* line 790 */
        ".Lf1aef58_001af2be:\n"
        "movl -0x68(%ebp), %ebx\n" /* line 794 | ownerNum */
        "movl -0x64(%ebp), %ecx\n" /* dropped */
        "movl %ebx, 0x90(%ecx)\n"
        "movl 0xc(%ebp), %edx\n" /* line 796 | item */
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll G_SetModel\n"
        "movl -0x64(%ebp), %ecx\n" /* line 798 | dropped */
        "movl %ecx, (%esp)\n"
        "calll G_DObjUpdate\n"
        "movl -0x64(%ebp), %ebx\n" /* line 800 | dropped */
        "movb $0xf, 0x166(%ebx)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 802 | vPos */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_SetOrigin\n"
        "movl $5, 0xc(%ebx)\n" /* line 803 */
        "movl 0x195f6a0, %ecx\n" /* line 804 */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %ebx, %edx\n" /* line 805 | to */
        "addl $0x24, %edx\n" /* to */
        /* { scope 4 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | velocity */
        "movl %eax, 0x24(%ebx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x1ec(%ecx), %eax\n" /* line 808 */
        "addl $0x3e8, %eax\n"
        "movl %eax, 0x190(%ebx)\n"
        "movl $0x10, 0x174(%ebx)\n" /* line 810 */
        "movl %ebx, (%esp)\n" /* line 812 */
        "calll SV_LinkEntity\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %ebx, %eax\n" /* line 851 | ent */
        "addl $0xac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ownerNum */
        /* { scope 2: dropped */
        /* { scope 3 */
        ".Lf1aef58_001af35d:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 673 */
        "movl %ecx, -0x4c(%ebp)\n"
        "movl %ecx, %edx\n"
        "movl 0x195f6a0, %ecx\n"
        "jmp .Lf1aef58_001af219\n"
        /* } scope */
        /* } scope */
        ".Lf1aef58_001af370:\n"
        "movl $0, 0xc(%esp)\n" /* line 842 */
        "movl $0, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* velocity */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* angles */
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "movl 0x195f728, %eax\n" /* line 843 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n" /* scale */
        /* { scope 2: dropped */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm0\n" /* velocity */
        "movss %xmm0, -0x24(%ebp)\n" /* velocity */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 274 */
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "movl 0x195f71c, %eax\n" /* line 844 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "calll crandom\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "movl 0x195f720, %eax\n"
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss -0x6c(%ebp), %xmm0\n"
        "movss -0x98(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "jmp .Lf1aef58_001aef9b\n"
        /* { scope 2: dropped */
        /* { scope 3 */
        ".Lf1aef58_001af415:\n"
        "movl -0x64(%ebp), %edx\n" /* line 779 | dropped, v */
        "addl $0x104, %edx\n" /* v */
        /* { scope 4 */
        "movl $0xbf800000, %eax\n" /* line 191 */
        "movl -0x64(%ebp), %ecx\n" /* dropped */
        "movl %eax, 0x104(%ecx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl %eax, 8(%edx)\n" /* line 193 */
        /* } scope */
        "movl %ecx, %edx\n" /* line 780 | v */
        "addl $0x110, %edx\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, 0x110(%ecx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl %eax, 8(%edx)\n" /* line 193 */
        "jmp .Lf1aef58_001af29e\n"
        /* } scope */
        /* { scope 4 */
        ".Lf1aef58_001af450:\n"
        "movl $0x2b4984, %eax\n" /* line 1229 */
        "movl %eax, 4(%esp)\n" /* line 1231 */
        "movl $0x2b4990, (%esp)\n" /* "game tried to register the item '%s' after initialization fi" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl 0x195eda8, %ebx\n" /* ent */
        "jmp .Lf1aef58_001af05f\n"
        /* } scope */
        ".Lf1aef58_001af478:\n"
        "movl $0, -0x4c(%ebp)\n" /* line 673 */
        "movl -0x4c(%ebp), %edx\n"
        "movl 0x195f6a0, %ecx\n"
        "jmp .Lf1aef58_001af219\n"
    );
}

/* line 862 */
__attribute__((naked))
gentity_t * Drop_Weapon(gentity_t *pEnt, int iWeaponIndex, unsigned int tag)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 862 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* iWeaponIndex */
        /* { scope 1: tagMat, vAngles */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 872 | size */
        "leal (%ebx, %eax, 2), %eax\n" /* size */
        "movl 0x195eda8, %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* pWeapItem */
        "movl 8(%ebp), %eax\n" /* line 876 | pEnt */
        "movl 0x158(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1af48e_001af4d4\n"
        "movl %ebx, %eax\n" /* size */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n" /* size */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%edx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1af48e_001af905\n"
        ".Lf1af48e_001af4d4:\n"
        "movl %ebx, (%esp)\n" /* line 882 | size */
        "calll BG_AmmoForWeapon\n"
        "movl %eax, %esi\n" /* iAmmoIndex */
        "movl %ebx, (%esp)\n" /* line 883 | size */
        "calll BG_ClipForWeapon\n"
        "movl %eax, -0x90(%ebp)\n" /* iClipIndex */
        "movl %ebx, (%esp)\n" /* line 886 | size */
        "calll BG_GetWeaponDef\n"
        "movl 0x340(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1af48e_001af856\n"
        "movl 8(%ebp), %edx\n" /* line 888 | pEnt */
        "movl 0x158(%edx), %eax\n"
        "movl -0x90(%ebp), %ecx\n" /* iClipIndex */
        "movl 0x344(%eax, %ecx, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1af48e_001af920\n"
        "movl %edx, %eax\n"
        ".Lf1af48e_001af522:\n"
        "movl $0, 0xc(%esp)\n" /* line 895 */
        "movl $0, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* pWeapItem */
        "movl %eax, (%esp)\n"
        "calll Drop_Item\n"
        "movl %eax, -0x8c(%ebp)\n" /* pDrop */
        "movl 8(%ebp), %edx\n" /* line 897 | pEnt */
        "movl 0x158(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1af48e_001af884\n"
        "movl 0x144(%eax, %esi, 4), %edi\n" /* line 899 | pWeapItem */
        "movl $0, 0x144(%eax, %esi, 4)\n" /* line 900 */
        "movl 0x158(%edx), %eax\n" /* line 902 */
        "movl -0x90(%ebp), %ecx\n" /* iClipIndex */
        "movl 0x344(%eax, %ecx, 4), %esi\n" /* iAmmoIndex */
        "movl $0, 0x344(%eax, %ecx, 4)\n" /* line 903 */
        "movl %ebx, 4(%esp)\n" /* line 905 | size */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        ".Lf1af48e_001af597:\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 960 | pDrop */
        "movl %edi, 0x1a0(%ecx)\n" /* iMin */
        "movl %esi, 0x1a8(%ecx)\n" /* line 961 | iMax */
        "testl %edi, %edi\n" /* line 963 | iMin */
        "je .Lf1af48e_001af5fd\n"
        "movl -0x8c(%ebp), %eax\n" /* line 966 | pDrop */
        "movl 0x1a8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1af48e_001af5ed\n"
        ".Lf1af48e_001af5bd:\n"
        "testl %edi, %edi\n" /* line 969 | iMin */
        "jne .Lf1af48e_001af5d5\n"
        ".Lf1af48e_001af5c1:\n"
        "testl %esi, %esi\n" /* iMax */
        "jne .Lf1af48e_001af5d5\n"
        "movl -0x8c(%ebp), %edx\n" /* line 970 | pDrop */
        "andl $0xffdfffff, 0x11c(%edx)\n"
        ".Lf1af48e_001af5d5:\n"
        "movl 0x10(%ebp), %eax\n" /* line 973 | tag */
        "testl %eax, %eax\n"
        "jne .Lf1af48e_001af619\n"
        /* } scope */
        ".Lf1af48e_001af5dc:\n"
        "movl -0x8c(%ebp), %eax\n" /* line 1008 | pDrop */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tagMat, vAngles */
        ".Lf1af48e_001af5ed:\n"
        "movl $0xffffffff, 0x1a8(%eax)\n" /* line 967 */
        "testl %edi, %edi\n" /* line 969 | iMin */
        "jne .Lf1af48e_001af5d5\n"
        "jmp .Lf1af48e_001af5c1\n"
        ".Lf1af48e_001af5fd:\n"
        "movl $0xffffffff, 0x1a0(%ecx)\n" /* line 964 */
        "movl -0x8c(%ebp), %eax\n" /* line 966 | pDrop */
        "movl 0x1a8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1af48e_001af5bd\n"
        "jmp .Lf1af48e_001af5ed\n"
        /* { scope 2: vCenter, trace */
        ".Lf1af48e_001af619:\n"
        "leal -0x84(%ebp), %ebx\n" /* line 979 | tagMat, size */
        "movl %ebx, 8(%esp)\n" /* size */
        "movl 0x10(%ebp), %ecx\n" /* tag */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %esi\n" /* pEnt, iMax */
        "movl %esi, (%esp)\n" /* iMax */
        "calll G_DObjGetWorldTagMatrix\n"
        "testl %eax, %eax\n"
        "je .Lf1af48e_001af85e\n"
        "movl %esi, %eax\n" /* iMax */
        "addl $0x104, %eax\n"
        "movl %esi, %edx\n" /* iMax */
        "addl $0x110, %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 0x104(%esi), %xmm2\n" /* line 256 */
        "addss 0x110(%esi), %xmm2\n"
        "movss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "mulss %xmm3, %xmm2\n"
        "movss 4(%eax), %xmm1\n" /* line 257 */
        "addss 4(%edx), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss 8(%eax), %xmm0\n" /* line 258 */
        "addss 8(%edx), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addl $0x34, %eax\n"
        /* } scope */
        /* { scope 4 */
        "addss 0x138(%esi), %xmm2\n" /* line 240 */
        "movss %xmm2, -0x30(%ebp)\n" /* vCenter */
        "addss 4(%eax), %xmm1\n" /* line 241 */
        "movss %xmm1, -0x2c(%ebp)\n"
        "addss 8(%eax), %xmm0\n" /* line 242 */
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "movl -0x8c(%ebp), %edx\n" /* line 749 | pDrop */
        "movl 0x184(%edx), %eax\n"
        "testl %eax, %eax\n"
        "movl $0x491, %edx\n"
        "cmovel %edx, %eax\n"
        "movl %eax, 0x18(%esp)\n" /* line 986 */
        "movl (%esi), %eax\n" /* iMax */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x60(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x8c(%ebp), %eax\n" /* pDrop */
        "addl $0x110, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x8c(%ebp), %eax\n" /* pDrop */
        "addl $0x104, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vCenter */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 987 | pDrop, endpos */
        "addl $0x18, %ecx\n" /* endpos */
        "movss -0x54(%ebp), %xmm2\n" /* trace, fraction */
        /* { scope 4 */
        "movss -0x30(%ebp), %xmm1\n" /* line 1203 | vCenter */
        "movss -0x60(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x8c(%ebp), %esi\n" /* pDrop, iMax */
        "movss %xmm1, 0x18(%esi)\n" /* iMax */
        "movss -0x2c(%ebp), %xmm1\n" /* line 1204 */
        "movss -0x5c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 1205 */
        "movss -0x58(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        /* } scope */
        "movl %esi, %edx\n" /* line 988 | iMax, to */
        "addl $0x138, %edx\n" /* to */
        /* { scope 4 */
        "movl 0x18(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x138(%esi)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x195f6a0, %eax\n" /* line 989 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* iMax */
        "leal -0x24(%ebp), %eax\n" /* line 991 | vAngles */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* size */
        "calll AxisToAngles\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "leal 0x144(%eax), %edx\n"
        /* } scope */
        ".Lf1af48e_001af7a7:\n"
        "movss 0x2ed5f8, %xmm0\n" /* line 997 | 90.0f */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl %edx, 4(%esp)\n" /* line 998 */
        "movl -0x8c(%ebp), %esi\n" /* pDrop, iMax */
        "movl %esi, (%esp)\n" /* iMax */
        "calll G_SetAngle\n"
        "calll crandom\n" /* line 1001 */
        "fstps -0x98(%ebp)\n"
        "calll crandom\n"
        "fstps -0x94(%ebp)\n"
        "calll crandom\n"
        "fstps -0xbc(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "movl $2, 0x30(%esi)\n" /* line 1002 | iMax */
        "movl 0x195f6a0, %eax\n" /* line 1003 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x34(%esi)\n" /* iMax */
        "movl %esi, %eax\n" /* line 1004 | iMax, to */
        "addl $0x48, %eax\n" /* to */
        /* { scope 3 */
        "mulss 0x2ed910, %xmm0\n" /* line 199 | 50.0f */
        "movss %xmm0, 0x48(%esi)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 200 */
        "mulss 0x2ed73c, %xmm0\n" /* 40.0f */
        "movss %xmm0, 4(%eax)\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 201 */
        "mulss 0x2ed7c8, %xmm0\n" /* 60.0f */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x8c(%ebp), %eax\n" /* line 1008 | pDrop */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1af48e_001af856:\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "jmp .Lf1af48e_001af522\n"
        /* { scope 1: tagMat, vAngles */
        /* { scope 2: vCenter, trace */
        /* { scope 3 */
        ".Lf1af48e_001af85e:\n"
        "movl 8(%ebp), %edx\n" /* line 991 | pEnt */
        "addl $0x144, %edx\n"
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 199 | pEnt */
        "movl 0x144(%ecx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* vAngles */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "jmp .Lf1af48e_001af7a7\n"
        /* } scope */
        /* { scope 2: vCenter, trace */
        ".Lf1af48e_001af884:\n"
        "movl %ebx, (%esp)\n" /* line 912 | size */
        "calll BG_GetWeaponDef\n"
        "movl 0x374(%eax), %esi\n" /* iMax */
        "movl %ebx, (%esp)\n" /* line 913 | size */
        "calll BG_GetWeaponDef\n"
        "movl 0x370(%eax), %edi\n" /* iMin */
        "cmpl %edi, %esi\n" /* line 914 | iMin, iMax */
        "jl .Lf1af48e_001af8f3\n"
        ".Lf1af48e_001af8a4:\n"
        "cmpl $0, %esi\n" /* line 921 | iMax */
        "jne .Lf1af48e_001af8e2\n"
        "testl %edi, %edi\n" /* iMin */
        "je .Lf1af48e_001af93b\n"
        ".Lf1af48e_001af8b1:\n"
        "calll rand\n" /* line 935 */
        "subl %edi, %esi\n" /* iMin, iMax */
        "cltd\n"
        "idivl %esi\n" /* iMax */
        "addl %edx, %edi\n" /* iMin */
        ".Lf1af48e_001af8bd:\n"
        "testl %edi, %edi\n" /* line 936 | iMin */
        "jle .Lf1af48e_001af8ea\n"
        "movl -0x90(%ebp), %eax\n" /* line 944 | iClipIndex */
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoClipSize\n"
        "movl %eax, %ebx\n" /* size */
        "testl %eax, %eax\n" /* line 946 */
        "jne .Lf1af48e_001af9fe\n"
        "xorl %esi, %esi\n" /* iMax */
        ".Lf1af48e_001af8db:\n"
        "subl %esi, %edi\n" /* line 925 | iMax, iMin */
        "jmp .Lf1af48e_001af597\n"
        ".Lf1af48e_001af8e2:\n"
        "jl .Lf1af48e_001af8ea\n" /* line 927 */
        "cmpl %edi, %esi\n" /* line 935 | iMin, iMax */
        "jne .Lf1af48e_001af8b1\n"
        "jmp .Lf1af48e_001af8bd\n"
        ".Lf1af48e_001af8ea:\n"
        "xorl %edi, %edi\n" /* line 954 | iMin */
        "xorl %esi, %esi\n" /* iMax */
        "jmp .Lf1af48e_001af597\n"
        ".Lf1af48e_001af8f3:\n"
        "movl %ebx, (%esp)\n" /* line 917 | size */
        "calll BG_GetWeaponDef\n"
        "movl %edi, %esi\n" /* iMin, iMax */
        "movl 0x374(%eax), %edi\n" /* iMin */
        "jmp .Lf1af48e_001af8a4\n"
        /* } scope */
        ".Lf1af48e_001af905:\n"
        "movl %ebx, 4(%esp)\n" /* line 878 | size */
        "movl %edx, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        "movl $0, -0x8c(%ebp)\n" /* pDrop */
        "jmp .Lf1af48e_001af5dc\n"
        ".Lf1af48e_001af920:\n"
        "movl %ebx, 4(%esp)\n" /* line 890 | size */
        "movl %eax, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        "movl $0, -0x8c(%ebp)\n" /* pDrop */
        "jmp .Lf1af48e_001af5dc\n"
        /* { scope 2: vCenter, trace */
        ".Lf1af48e_001af93b:\n"
        "calll randomf\n" /* line 923 */
        "fstps -0xbc(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "movl -0x90(%ebp), %esi\n" /* iClipIndex, iMax */
        "movl %esi, (%esp)\n" /* iMax */
        "movss %xmm0, -0xb8(%ebp)\n"
        "calll BG_GetAmmoClipSize\n"
        "movss -0xb8(%ebp), %xmm0\n" /* line 428 */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "subl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x9c(%ebp)\n"
        "cvttss2si -0x9c(%ebp), %ebx\n"
        "addl $1, %ebx\n"
        "calll randomf\n" /* line 924 */
        "fstps -0xbc(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "addss 0x2ed604, %xmm0\n" /* 0.25f */
        "cvtsi2ssl %ebx, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xa0(%ebp)\n"
        "cvttss2si -0xa0(%ebp), %esi\n"
        "movl %ebx, %edi\n" /* line 925 | size, iMin */
        "subl %esi, %edi\n" /* iMax, iMin */
        "jmp .Lf1af48e_001af597\n"
        ".Lf1af48e_001af9fe:\n"
        "calll rand\n" /* line 946 */
        "cltd\n"
        "idivl %ebx\n" /* size */
        "movl %edx, %esi\n" /* iMax */
        "cmpl %edx, %edi\n" /* line 947 | iMin */
        "jg .Lf1af48e_001af8db\n"
        "movl %edi, %esi\n" /* iMin, iMax */
        "xorl %edi, %edi\n" /* iMin */
        "jmp .Lf1af48e_001af597\n"
    );
}

/* line 528 */
__attribute__((naked))
void Touch_Item(gentity_t *ent, gentity_t *other, qboolean bTouched)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 528 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* other */
        /* { scope 1: quantity, iClipAmmo, pDropped, weapDef, ... */
        "movl 8(%ebp), %eax\n" /* line 536 | ent */
        "cmpb $0, 0x162(%eax)\n"
        "je .Lf1afa1a_001afa5c\n"
        "movb $0, 0x162(%eax)\n" /* line 540 */
        "movl 0x158(%edi), %ecx\n" /* line 542 | other */
        "testl %ecx, %ecx\n"
        "je .Lf1afa1a_001afa5c\n"
        "movl 0x194(%edi), %eax\n" /* line 544 | other */
        "testl %eax, %eax\n"
        "jle .Lf1afa1a_001afa5c\n"
        "movl 0x195f6a0, %eax\n" /* line 548 */
        "movl 0x20(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1afa1a_001afa67\n"
        /* } scope */
        ".Lf1afa1a_001afa5c:\n"
        "addl $0xbc, %esp\n" /* line 639 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: quantity, iClipAmmo, pDropped, weapDef, ... */
        ".Lf1afa1a_001afa67:\n"
        "movl 8(%ebp), %edx\n" /* line 551 | ent */
        "movzwl 0x1ac(%edx), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x195eda8, %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* item */
        "movl 0x10(%ebp), %ebx\n" /* line 554 | bTouched, makenoise */
        "movl %ebx, 8(%esp)\n" /* makenoise */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll BG_CanItemBeGrabbed\n"
        "testl %eax, %eax\n"
        "jne .Lf1afa1a_001afb2f\n"
        "testl %ebx, %ebx\n" /* line 556 | makenoise */
        "jne .Lf1afa1a_001afa5c\n"
        "movl 8(%ebp), %edx\n" /* line 559 | ent */
        "movl 0x90(%edx), %eax\n"
        "cmpl (%edi), %eax\n" /* other */
        "je .Lf1afa1a_001afa5c\n"
        "movl -0x84(%ebp), %ebx\n" /* line 563 | item, makenoise */
        "cmpl $1, 0x1c(%ebx)\n" /* makenoise */
        "jne .Lf1afa1a_001afa5c\n"
        "movl 0x20(%ebx), %ebx\n" /* line 566 | makenoise */
        "movl %ebx, %edx\n" /* makenoise */
        "sarl $5, %edx\n"
        "movl 0x158(%edi), %eax\n" /* other */
        "movl %ebx, %ecx\n" /* makenoise */
        "andl $0x1f, %ecx\n"
        "movl 0x544(%eax, %edx, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1afa1a_001b0254\n"
        "movl %ebx, (%esp)\n" /* line 568 | makenoise */
        "calll BG_GetWeaponDef\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x66, 4(%esp)\n"
        "movl $0x2b4a70, (%esp)\n" /* "%c "GAME_PICKUP_CANTCARRYMOREAMMO%s"" */
        ".Lf1afa1a_001afb02:\n"
        "calll va\n" /* line 576 */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "subl 0x195f688, %edi\n" /* other */
        "sarl $4, %edi\n" /* other */
        "imull $0x8af8af8b, %edi, %eax\n" /* other */
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "jmp .Lf1afa1a_001afa5c\n"
        ".Lf1afa1a_001afb2f:\n"
        "movl $0x40, 8(%esp)\n" /* line 593 */
        "movl 0x158(%edi), %eax\n" /* other */
        "addl $0x2784, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %edx\n" /* cleanname */
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "leal -0x58(%ebp), %ebx\n" /* line 594 | cleanname, makenoise */
        "movl %ebx, (%esp)\n" /* makenoise */
        "calll I_CleanStr\n"
        "movl -0x84(%ebp), %eax\n" /* line 599 | item */
        "cmpl $1, 0x1c(%eax)\n"
        "je .Lf1afa1a_001b01fb\n"
        "movl (%eax), %ebx\n" /* line 606 | makenoise */
        "movl (%edi), %esi\n" /* other */
        "movl %esi, (%esp)\n"
        "calll SV_GetGuid\n"
        "movl %ebx, 0x10(%esp)\n" /* makenoise */
        "leal -0x58(%ebp), %edx\n" /* cleanname */
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b4ad4, (%esp)\n" /* "Item;%d;%d;%s;%s
" */
        "calll G_LogPrintf\n"
        ".Lf1afa1a_001afb97:\n"
        "movl -0x84(%ebp), %ebx\n" /* line 610 | item, makenoise */
        "movl 0x1c(%ebx), %eax\n" /* makenoise */
        "cmpl $2, %eax\n"
        "je .Lf1afa1a_001b00d7\n"
        "cmpl $3, %eax\n"
        "je .Lf1afa1a_001aff29\n"
        "subl $1, %eax\n"
        "jne .Lf1afa1a_001afa5c\n"
        /* { scope 2: iMax, iDropSlot, iWeap */
        "movl 8(%ebp), %edx\n" /* line 195 | ent */
        "movzwl 0x1ac(%edx), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x195eda8, %eax\n"
        "movl 0x20(%eax, %edx, 4), %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        "movl %edx, (%esp)\n" /* line 196 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x74(%ebp)\n" /* weapDef */
        "movl 8(%ebp), %ebx\n" /* line 198 | ent, iAddedAmount */
        "movl 0x1a0(%ebx), %esi\n" /* iAddedAmount */
        "cmpl $0, %esi\n"
        "jl .Lf1afa1a_001b03ae\n"
        "jne .Lf1afa1a_001afc4b\n" /* line 204 */
        /* { scope 3 */
        "movl -0x74(%ebp), %eax\n" /* line 209 | weapDef */
        "movl 0x374(%eax), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* iMax */
        "movl -0x74(%ebp), %edx\n" /* line 210 | weapDef */
        "movl 0x370(%edx), %ebx\n" /* iAddedAmount */
        "cmpl %ebx, %eax\n" /* line 211 | iAddedAmount */
        "jl .Lf1afa1a_001afc14\n"
        "movl %ebx, -0x70(%ebp)\n" /* iAddedAmount, iMax */
        "movl %eax, %ebx\n" /* iAddedAmount */
        ".Lf1afa1a_001afc14:\n"
        "cmpl $0, %ebx\n" /* line 218 | iAddedAmount */
        "jne .Lf1afa1a_001b03c5\n"
        "movl -0x70(%ebp), %esi\n" /* iMax */
        "testl %esi, %esi\n"
        "je .Lf1afa1a_001b04f1\n"
        ".Lf1afa1a_001afc28:\n"
        "calll rand\n" /* line 229 */
        "subl -0x70(%ebp), %ebx\n" /* iMax, iAddedAmount */
        "cltd\n"
        "idivl %ebx\n" /* iAddedAmount */
        "movl -0x70(%ebp), %ebx\n" /* iMax, iAddedAmount */
        "addl %edx, %ebx\n" /* iAddedAmount */
        ".Lf1afa1a_001afc38:\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %ebx, 0x1a0(%eax)\n" /* iAddedAmount */
        "testl %ebx, %ebx\n" /* line 230 | iAddedAmount */
        "jle .Lf1afa1a_001b04e0\n"
        "movl %ebx, %esi\n" /* iAddedAmount */
        /* } scope */
        ".Lf1afa1a_001afc4b:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 235 */
        "movl %edx, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoTypeMax\n"
        "cmpl %eax, %esi\n"
        "jg .Lf1afa1a_001b0381\n"
        ".Lf1afa1a_001afc66:\n"
        "movl 8(%ebp), %ebx\n" /* line 238 | ent, iAddedAmount */
        "movl 0x1a0(%ebx), %ebx\n" /* iAddedAmount */
        "movl %ebx, -0x80(%ebp)\n" /* iAddedAmount, quantity */
        ".Lf1afa1a_001afc72:\n"
        "movl 8(%ebp), %eax\n" /* line 242 | ent */
        "movl 0x1a8(%eax), %ebx\n" /* iAddedAmount */
        "cmpl $0, %ebx\n" /* iAddedAmount */
        "jl .Lf1afa1a_001b03a2\n"
        "jne .Lf1afa1a_001afcd7\n" /* line 248 */
        "movl 8(%ebp), %edx\n" /* line 250 | ent */
        "movl 0x1a0(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "js .Lf1afa1a_001b046c\n"
        "movl -0x6c(%ebp), %ebx\n" /* line 256 | iAddedAmount */
        "movl %ebx, (%esp)\n" /* iAddedAmount */
        "calll BG_ClipForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoClipSize\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %eax, 0x1a8(%edx)\n"
        "movl 0x1a0(%edx), %esi\n" /* line 257 */
        "cmpl %esi, %eax\n"
        "jle .Lf1afa1a_001afcc3\n"
        "movl %esi, 0x1a8(%edx)\n" /* line 258 */
        ".Lf1afa1a_001afcc3:\n"
        "movl 8(%ebp), %eax\n" /* line 259 | ent */
        "movl 0x1a8(%eax), %ebx\n" /* iAddedAmount */
        "subl %ebx, %esi\n" /* iAddedAmount */
        "movl %esi, -0x80(%ebp)\n" /* quantity */
        "movl %esi, 0x1a0(%eax)\n"
        ".Lf1afa1a_001afcd7:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 264 */
        "movl %eax, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoClipSize\n"
        "cmpl %eax, %ebx\n" /* iAddedAmount */
        "jg .Lf1afa1a_001b0360\n"
        ".Lf1afa1a_001afcf2:\n"
        "movl 8(%ebp), %eax\n" /* line 267 | ent */
        "movl 0x1a8(%eax), %eax\n"
        "movl %eax, -0x7c(%ebp)\n" /* iClipAmmo */
        ".Lf1afa1a_001afcfe:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 274 */
        "sarl $5, %edx\n"
        "movl 0x158(%edi), %eax\n"
        "movl -0x6c(%ebp), %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x544(%eax, %edx, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1afa1a_001b0296\n"
        "movl -0x6c(%ebp), %edx\n" /* line 276 */
        "movl %edx, (%esp)\n"
        "calll BG_DoesWeaponNeedSlot\n"
        "testb %al, %al\n"
        "je .Lf1afa1a_001b03d9\n"
        "movl 0x158(%edi), %esi\n" /* line 283 */
        "movl 0xd4(%esi), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1afa1a_001afd81\n"
        "movl %edx, %eax\n" /* line 287 */
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x544(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1afa1a_001afa5c\n"
        "movl $1, 8(%esp)\n" /* line 291 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll BG_IsPlayerWeaponInSlot\n"
        "testl %eax, %eax\n"
        "je .Lf1afa1a_001b066f\n"
        ".Lf1afa1a_001afd7b:\n"
        "movl 0x158(%edi), %esi\n"
        ".Lf1afa1a_001afd81:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 302 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll BG_GetEmptySlotForWeapon\n"
        "testl %eax, %eax\n"
        "jne .Lf1afa1a_001afdcf\n"
        "movl 0x158(%edi), %eax\n"
        "movl 0xd4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x80(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x6c(%ebp), %ebx\n" /* iAddedAmount */
        "movl %ebx, 4(%esp)\n" /* iAddedAmount */
        "movl 0x158(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetStackSlotForWeapon\n"
        "testl %eax, %eax\n"
        "je .Lf1afa1a_001b05e3\n"
        ".Lf1afa1a_001afdcf:\n"
        "movl $0, -0x78(%ebp)\n" /* line 348 | pDropped */
        ".Lf1afa1a_001afdd6:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 360 */
        "movl %eax, 4(%esp)\n"
        "movl 0x158(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_GivePlayerWeapon\n"
        "movl 0x10(%ebp), %edx\n" /* line 363 | bTouched */
        "testl %edx, %edx\n"
        "je .Lf1afa1a_001b05ac\n"
        /* { scope 3 */
        "movl %edi, %eax\n" /* line 333 */
        "subl 0x195f688, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %esi\n"
        /* } scope */
        ".Lf1afa1a_001afe07:\n"
        "movl -0x7c(%ebp), %ebx\n" /* line 408 | iClipAmmo, iAmmoIndex */
        "testl %ebx, %ebx\n" /* iAmmoIndex */
        "js .Lf1afa1a_001afe45\n"
        "movl -0x6c(%ebp), %eax\n" /* line 410 */
        "movl %eax, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoClipSize\n"
        "cmpl %eax, -0x7c(%ebp)\n" /* iClipAmmo */
        "jg .Lf1afa1a_001b0575\n"
        ".Lf1afa1a_001afe2a:\n"
        "movl 0x158(%edi), %ebx\n" /* line 415 | iAmmoIndex */
        "movl -0x6c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl -0x7c(%ebp), %edx\n" /* iClipAmmo */
        "movl %edx, 0x344(%ebx, %eax, 4)\n" /* iAmmoIndex */
        ".Lf1afa1a_001afe45:\n"
        "xorl %eax, %eax\n" /* line 418 */
        "cmpl $-1, -0x7c(%ebp)\n" /* iClipAmmo */
        "sete %al\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x80(%ebp), %ebx\n" /* quantity, iAmmoIndex */
        "movl %ebx, 8(%esp)\n" /* iAmmoIndex */
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Add_Ammo\n"
        "movl -0x78(%ebp), %eax\n" /* line 422 | pDropped */
        "testl %eax, %eax\n"
        "je .Lf1afa1a_001b047b\n"
        "movl -0x78(%ebp), %edx\n" /* line 423 | pDropped */
        "movl %edx, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl $0x90, %ebx\n" /* iAmmoIndex */
        ".Lf1afa1a_001afe83:\n"
        "movl %edi, (%esp)\n" /* line 426 */
        "calll Scr_AddEntity\n"
        "movl $2, 8(%esp)\n" /* line 427 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll Scr_Notify\n"
        "movl -0x74(%ebp), %edx\n" /* line 429 | weapDef */
        "movl 0x84(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1afa1a_001b0320\n"
        "movl $4, 8(%esp)\n" /* line 430 */
        ".Lf1afa1a_001afec4:\n"
        "movl $0x49, 4(%esp)\n" /* line 432 */
        "movl $0x2b2ba8, (%esp)\n" /* "%c "%i"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        ".Lf1afa1a_001afeec:\n"
        "movl 0x158(%edi), %eax\n" /* line 629 | other */
        "movl 0x2704(%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf1afa1a_001b0236\n"
        "movl 8(%ebp), %edx\n" /* line 631 | ent */
        "movl 0x8c(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* makenoise */
        "movl %edi, (%esp)\n" /* other */
        "calll G_AddPredictableEvent\n"
        ".Lf1afa1a_001aff19:\n"
        "movl 8(%ebp), %ebx\n" /* line 638 | ent, makenoise */
        "movl %ebx, (%esp)\n" /* makenoise */
        "calll G_FreeEntity\n"
        "jmp .Lf1afa1a_001afa5c\n"
        /* { scope 2: iMax, iDropSlot, iWeap */
        ".Lf1afa1a_001aff29:\n"
        "movl 8(%ebp), %edx\n" /* line 450 | ent */
        "movzwl 0x1ac(%edx), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x195eda8, %eax\n"
        "movl 0x18(%eax, %edx, 4), %ecx\n"
        "cmpl $5, %ecx\n"
        "je .Lf1afa1a_001b0282\n"
        "cmpl $0x64, %ecx\n"
        "je .Lf1afa1a_001b0282\n"
        "movl 0x158(%edi), %esi\n" /* line 451 */
        "movl 0x134(%esi), %edx\n"
        ".Lf1afa1a_001aff60:\n"
        "movl 8(%ebp), %ebx\n" /* line 455 | ent, iAmmoIndex */
        "movl 0x1a0(%ebx), %eax\n" /* iAmmoIndex */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ecx\n"
        "movl 0x194(%edi), %eax\n" /* line 460 */
        "movl %eax, -0x60(%ebp)\n" /* iOldHealth */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 463 */
        "cvtsi2ssl 0x134(%esi), %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "mulss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "cvttss2si %xmm0, %eax\n"
        "addl -0x60(%ebp), %eax\n" /* iOldHealth */
        "movl %eax, 0x194(%edi)\n"
        "cmpl %eax, %edx\n" /* line 466 */
        "jl .Lf1afa1a_001b002a\n"
        /* { scope 3 */
        "movl 0x134(%esi), %edx\n" /* line 473 */
        "movl %edx, -0x5c(%ebp)\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %ebx\n" /* iNormVal */
        "testl %ebx, %ebx\n" /* line 474 | iNormVal */
        "jle .Lf1afa1a_001b040b\n"
        "cmpl $0x65, %ebx\n" /* line 476 | iNormVal */
        "movl $0x64, %eax\n"
        "cmovgel %eax, %ebx\n" /* iNormVal */
        ".Lf1afa1a_001affd9:\n"
        "movl -0x60(%ebp), %edx\n" /* line 480 | iOldHealth */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "testl %eax, %eax\n" /* line 481 */
        "movl $1, %edx\n"
        "cmovlel %edx, %eax\n"
        "leal (%ecx, %eax), %edx\n" /* line 483 */
        "cmpl $0x65, %edx\n" /* line 484 */
        "movl $0x64, %eax\n"
        "cmovgel %eax, %edx\n"
        "cmpl %edx, %ebx\n" /* line 488 | iNormVal */
        "je .Lf1afa1a_001b03ba\n"
        "movl -0x5c(%ebp), %ebx\n" /* line 491 | iNormVal */
        "imull %edx, %ebx\n" /* iNormVal */
        "movl $0x51eb851f, %edx\n"
        "movl %ebx, %eax\n" /* iNormVal */
        "imull %edx\n"
        "sarl $5, %edx\n"
        "movl %ebx, %eax\n" /* iNormVal */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        ".Lf1afa1a_001b002a:\n"
        "movl %edx, 0x194(%edi)\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lf1afa1a_001b0032:\n"
        "movl %eax, 0x12c(%esi)\n" /* line 495 */
        "movl %ecx, 8(%esp)\n" /* line 498 */
        "movl $0x66, 4(%esp)\n"
        "movl $0x2b4b88, (%esp)\n" /* "%c "GAME_PICKUP_HEALTH%i"" */
        "calll va\n"
        "movl %edi, %ebx\n" /* iNormVal */
        "subl 0x195f688, %ebx\n" /* iNormVal */
        "sarl $4, %ebx\n" /* iNormVal */
        "imull $0x8af8af8b, %ebx, %ebx\n" /* iNormVal */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* iNormVal */
        "calll SV_GameSendServerCommand\n"
        "movl $0, 8(%esp)\n" /* line 499 */
        "movl $0x49, 4(%esp)\n"
        "movl $0x2b2ba8, (%esp)\n" /* "%c "%i"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* iNormVal */
        "calll SV_GameSendServerCommand\n"
        "movl %edi, (%esp)\n" /* line 502 */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 503 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll Scr_Notify\n"
        "movl $0x90, %ebx\n" /* iNormVal */
        "jmp .Lf1afa1a_001afeec\n"
        /* } scope */
        /* { scope 2: iMax, iDropSlot, iWeap */
        ".Lf1afa1a_001b00d7:\n"
        "movl 8(%ebp), %ebx\n" /* line 147 | ent, item */
        "movzwl 0x1ac(%ebx), %eax\n" /* item */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x195eda8, %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* item */
        "movl 8(%ebp), %edx\n" /* line 149 | ent */
        "movl 0x1a0(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1afa1a_001b00ff\n"
        "movl 0x18(%ebx), %eax\n" /* line 152 | item */
        ".Lf1afa1a_001b00ff:\n"
        "movl $0, 0xc(%esp)\n" /* line 154 */
        "movl %eax, 8(%esp)\n"
        "movl 0x20(%ebx), %eax\n" /* item */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Add_Ammo\n"
        "testl %eax, %eax\n" /* line 156 */
        "je .Lf1afa1a_001afa5c\n"
        "movl 0x20(%ebx), %eax\n" /* line 160 | item */
        "movl %eax, (%esp)\n"
        "calll BG_WeaponIsClipOnly\n"
        "testl %eax, %eax\n"
        "je .Lf1afa1a_001b033a\n"
        "movl 0x20(%ebx), %eax\n" /* line 161 | item */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x66, 4(%esp)\n"
        "movl $0x2b4b48, (%esp)\n" /* "%c "GAME_PICKUP_CLIPONLY_AMMO%s"" */
        ".Lf1afa1a_001b0156:\n"
        "calll va\n" /* line 163 */
        "movl %edi, %edx\n"
        "subl 0x195f688, %edx\n"
        "sarl $4, %edx\n"
        "imull $0x8af8af8b, %edx, %esi\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl %edi, (%esp)\n" /* line 166 */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 167 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll Scr_Notify\n"
        "movl 0x20(%ebx), %eax\n" /* line 169 | item */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x84(%eax), %eax\n" /* line 172 */
        "testl %eax, %eax\n"
        "je .Lf1afa1a_001b032d\n"
        "movl $4, 8(%esp)\n" /* line 173 */
        ".Lf1afa1a_001b01c9:\n"
        "movl $0x49, 4(%esp)\n" /* line 175 */
        "movl $0x2b2ba8, (%esp)\n" /* "%c "%i"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl $0x90, %ebx\n" /* item */
        "jmp .Lf1afa1a_001afeec\n"
        /* } scope */
        ".Lf1afa1a_001b01fb:\n"
        "movl 0x20(%eax), %eax\n" /* line 601 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl (%eax), %esi\n"
        "movl (%edi), %ebx\n" /* other, makenoise */
        "movl %ebx, (%esp)\n" /* makenoise */
        "calll SV_GetGuid\n"
        "movl %esi, 0x10(%esp)\n"
        "leal -0x58(%ebp), %edx\n" /* cleanname */
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* makenoise */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b4ac0, (%esp)\n" /* "Weapon;%d;%d;%s;%s
" */
        "calll G_LogPrintf\n"
        "jmp .Lf1afa1a_001afb97\n"
        ".Lf1afa1a_001b0236:\n"
        "movl 8(%ebp), %edx\n" /* line 635 | ent */
        "movl 0x8c(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* makenoise */
        "movl %edi, (%esp)\n" /* other */
        "calll G_AddEvent\n"
        "jmp .Lf1afa1a_001aff19\n"
        ".Lf1afa1a_001b0254:\n"
        "movl %ebx, (%esp)\n" /* line 572 | makenoise */
        "calll BG_GetWeaponDef\n"
        "movl 0x80(%eax), %eax\n"
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf1afa1a_001afa5c\n"
        ".Lf1afa1a_001b026e:\n"
        "movl $0x66, 4(%esp)\n" /* line 576 */
        "movl $0x2b4a98, (%esp)\n" /* "%c "GAME_CANT_GET_PRIMARY_WEAP_MESSAGE"" */
        "jmp .Lf1afa1a_001afb02\n"
        /* { scope 2: iMax, iDropSlot, iWeap */
        ".Lf1afa1a_001b0282:\n"
        "movl 0x158(%edi), %esi\n" /* line 453 */
        "movl 0x134(%esi), %eax\n"
        "leal (%eax, %eax), %edx\n"
        "jmp .Lf1afa1a_001aff60\n"
        /* } scope */
        /* { scope 2: iMax, iDropSlot, iWeap */
        ".Lf1afa1a_001b0296:\n"
        "movl -0x80(%ebp), %esi\n" /* line 374 | quantity */
        "addl -0x7c(%ebp), %esi\n" /* iClipAmmo */
        "movl $0, 0xc(%esp)\n" /* line 377 */
        "movl %esi, 8(%esp)\n"
        "movl -0x6c(%ebp), %ebx\n" /* iAmmoIndex */
        "movl %ebx, 4(%esp)\n" /* iAmmoIndex */
        "movl %edi, (%esp)\n"
        "calll Add_Ammo\n"
        "movl %eax, %ebx\n" /* iAmmoIndex */
        "testl %eax, %eax\n" /* line 379 */
        "jne .Lf1afa1a_001b0415\n"
        ".Lf1afa1a_001b02c1:\n"
        "cmpl %ebx, %esi\n" /* line 389 | iAmmoIndex */
        "je .Lf1afa1a_001b0300\n"
        "movl 8(%ebp), %edx\n" /* line 392 | ent */
        "movl 0x1a0(%edx), %eax\n"
        "subl %ebx, %eax\n" /* iAmmoIndex */
        "movl %eax, 0x1a0(%edx)\n"
        "testl %eax, %eax\n" /* line 393 */
        "jle .Lf1afa1a_001b04b3\n"
        ".Lf1afa1a_001b02de:\n"
        "movl 8(%ebp), %ebx\n" /* line 401 | ent, iAmmoIndex */
        "movl 0x1a0(%ebx), %eax\n" /* iAmmoIndex */
        "testl %eax, %eax\n"
        "jle .Lf1afa1a_001b04a0\n"
        ".Lf1afa1a_001b02ef:\n"
        "movl 0x195f72c, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1afa1a_001afa5c\n"
        ".Lf1afa1a_001b0300:\n"
        "movl $0x91, %ebx\n" /* line 423 | iAmmoIndex */
        ".Lf1afa1a_001b0305:\n"
        "calll Scr_AddUndefined\n" /* line 425 */
        "movl %edi, %eax\n"
        "subl 0x195f688, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %esi\n"
        "jmp .Lf1afa1a_001afe83\n"
        ".Lf1afa1a_001b0320:\n"
        "movl $1, 8(%esp)\n" /* line 432 */
        "jmp .Lf1afa1a_001afec4\n"
        /* } scope */
        /* { scope 2: iMax, iDropSlot, iWeap */
        ".Lf1afa1a_001b032d:\n"
        "movl $1, 8(%esp)\n" /* line 175 */
        "jmp .Lf1afa1a_001b01c9\n"
        ".Lf1afa1a_001b033a:\n"
        "movl 0x20(%ebx), %eax\n" /* line 163 | item */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x66, 4(%esp)\n"
        "movl $0x2b4b6c, (%esp)\n" /* "%c "GAME_PICKUP_AMMO%s"" */
        "jmp .Lf1afa1a_001b0156\n"
        /* } scope */
        /* { scope 2: iMax, iDropSlot, iWeap */
        ".Lf1afa1a_001b0360:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 265 */
        "movl %edx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoClipSize\n"
        "movl 8(%ebp), %ebx\n" /* ent, iAddedAmount */
        "movl %eax, 0x1a8(%ebx)\n" /* iAddedAmount */
        "jmp .Lf1afa1a_001afcf2\n"
        ".Lf1afa1a_001b0381:\n"
        "movl -0x6c(%ebp), %ebx\n" /* line 236 | iAddedAmount */
        "movl %ebx, (%esp)\n" /* iAddedAmount */
        "calll BG_AmmoForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoTypeMax\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %eax, 0x1a0(%edx)\n"
        "jmp .Lf1afa1a_001afc66\n"
        ".Lf1afa1a_001b03a2:\n"
        "movl $0, -0x7c(%ebp)\n" /* line 242 | iClipAmmo */
        "jmp .Lf1afa1a_001afcfe\n"
        ".Lf1afa1a_001b03ae:\n"
        "movl $0, -0x80(%ebp)\n" /* line 198 | quantity */
        "jmp .Lf1afa1a_001afc72\n"
        ".Lf1afa1a_001b03ba:\n"
        "movl 0x194(%edi), %eax\n"
        "jmp .Lf1afa1a_001b0032\n"
        /* { scope 3 */
        ".Lf1afa1a_001b03c5:\n"
        "jl .Lf1afa1a_001b05d1\n" /* line 222 */
        "cmpl -0x70(%ebp), %ebx\n" /* line 229 | iMax, iAddedAmount */
        "jne .Lf1afa1a_001afc28\n"
        "jmp .Lf1afa1a_001afc38\n"
        /* } scope */
        ".Lf1afa1a_001b03d9:\n"
        "movl -0x6c(%ebp), %ebx\n" /* line 279 | iAddedAmount */
        "movl %ebx, 4(%esp)\n" /* iAddedAmount */
        "movl 0x158(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_GivePlayerWeapon\n"
        "movl %edi, %eax\n"
        "subl 0x195f688, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %esi\n"
        "movl $0, -0x78(%ebp)\n" /* pDropped */
        "jmp .Lf1afa1a_001afe07\n"
        /* } scope */
        /* { scope 2: iMax, iDropSlot, iWeap */
        /* { scope 3 */
        ".Lf1afa1a_001b040b:\n"
        "movl $1, %ebx\n" /* line 474 | iNormVal */
        "jmp .Lf1afa1a_001affd9\n"
        /* } scope */
        /* } scope */
        /* { scope 2: iMax, iDropSlot, iWeap */
        ".Lf1afa1a_001b0415:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 382 */
        "movl %eax, (%esp)\n"
        "calll BG_WeaponIsClipOnly\n"
        "testl %eax, %eax\n"
        "je .Lf1afa1a_001b0485\n"
        "movl -0x74(%ebp), %edx\n" /* line 383 | weapDef */
        "movl 4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x66, 4(%esp)\n"
        "movl $0x2b4b48, (%esp)\n" /* "%c "GAME_PICKUP_CLIPONLY_AMMO%s"" */
        ".Lf1afa1a_001b043d:\n"
        "calll va\n" /* line 385 */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, %eax\n"
        "subl 0x195f688, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "jmp .Lf1afa1a_001b02c1\n"
        ".Lf1afa1a_001b046c:\n"
        "movl $0, 0x1a8(%edx)\n" /* line 252 */
        "jmp .Lf1afa1a_001afcd7\n"
        ".Lf1afa1a_001b047b:\n"
        "movl $0x90, %ebx\n" /* line 423 | iAmmoIndex */
        "jmp .Lf1afa1a_001b0305\n"
        ".Lf1afa1a_001b0485:\n"
        "movl -0x74(%ebp), %edx\n" /* line 385 | weapDef */
        "movl 4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x66, 4(%esp)\n"
        "movl $0x2b4b6c, (%esp)\n" /* "%c "GAME_PICKUP_AMMO%s"" */
        "jmp .Lf1afa1a_001b043d\n"
        ".Lf1afa1a_001b04a0:\n"
        "movl 0x1a8(%ebx), %eax\n" /* line 401 | iAmmoIndex */
        "testl %eax, %eax\n"
        "jg .Lf1afa1a_001b02ef\n"
        "jmp .Lf1afa1a_001b0300\n"
        ".Lf1afa1a_001b04b3:\n"
        "addl %eax, 0x1a8(%edx)\n" /* line 395 */
        "movl $0xffffffff, 0x1a0(%edx)\n" /* line 396 */
        "movl 0x1a8(%edx), %eax\n" /* line 397 */
        "testl %eax, %eax\n"
        "jg .Lf1afa1a_001b02de\n"
        "movl $0xffffffff, 0x1a8(%edx)\n" /* line 398 */
        "jmp .Lf1afa1a_001b02de\n"
        /* { scope 3 */
        ".Lf1afa1a_001b04e0:\n"
        "movl $0, 0x1a0(%eax)\n" /* line 231 */
        "xorl %esi, %esi\n"
        "jmp .Lf1afa1a_001afc4b\n"
        ".Lf1afa1a_001b04f1:\n"
        "calll randomf\n" /* line 220 */
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "movl -0x6c(%ebp), %ebx\n" /* iAddedAmount */
        "movl %ebx, (%esp)\n" /* iAddedAmount */
        "movss %xmm0, -0x98(%ebp)\n"
        "calll BG_ClipForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoClipSize\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 428 */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss 0x2ed5d8, %xmm2\n" /* 0.5f */
        "mulss %xmm2, %xmm0\n"
        "subl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x88(%ebp)\n"
        "cvttss2si -0x88(%ebp), %eax\n"
        "addl $1, %eax\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %eax, 0x1a0(%edx)\n"
        "movl %eax, %esi\n"
        "jmp .Lf1afa1a_001afc4b\n"
        /* } scope */
        ".Lf1afa1a_001b0575:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 412 */
        "movl %edx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoClipSize\n"
        "subl %eax, -0x7c(%ebp)\n" /* iClipAmmo */
        "movl -0x7c(%ebp), %ebx\n" /* iClipAmmo, iAmmoIndex */
        "addl %ebx, -0x80(%ebp)\n" /* iAmmoIndex, quantity */
        "movl -0x6c(%ebp), %eax\n" /* line 413 */
        "movl %eax, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoClipSize\n"
        "movl %eax, -0x7c(%ebp)\n" /* iClipAmmo */
        "jmp .Lf1afa1a_001afe2a\n"
        ".Lf1afa1a_001b05ac:\n"
        "movl %edi, %eax\n" /* line 364 */
        "subl 0x195f688, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %esi\n"
        "movl -0x6c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SelectWeaponIndex\n"
        "jmp .Lf1afa1a_001afe07\n"
        /* { scope 3 */
        ".Lf1afa1a_001b05d1:\n"
        "movl 8(%ebp), %ebx\n" /* line 224 | ent, iAddedAmount */
        "movl $0, 0x1a0(%ebx)\n" /* iAddedAmount */
        "jmp .Lf1afa1a_001afc4b\n"
        /* } scope */
        ".Lf1afa1a_001b05e3:\n"
        "movl -0x74(%ebp), %eax\n" /* line 304 | weapDef */
        "movl 0x80(%eax), %ebx\n" /* iAddedAmount */
        "movl 0x158(%edi), %eax\n"
        "movl 0xd4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "cmpl 0x80(%eax), %ebx\n" /* iAddedAmount */
        "je .Lf1afa1a_001b06db\n"
        "movl $1, -0x68(%ebp)\n" /* line 307 | iDropSlot */
        "movl 0x158(%edi), %esi\n"
        /* { scope 3 */
        ".Lf1afa1a_001b0619:\n"
        "movl -0x68(%ebp), %edx\n" /* line 319 | iDropSlot */
        "movsbl 0x554(%edx, %esi), %esi\n"
        "movl %esi, -0x64(%ebp)\n" /* iWeap */
        "movl -0x6c(%ebp), %ebx\n" /* line 320 | iAmmoIndex */
        "movl %ebx, (%esp)\n" /* iAmmoIndex */
        "calll BG_AmmoForWeapon\n"
        "movl %eax, %ebx\n" /* iAmmoIndex */
        "movl -0x6c(%ebp), %eax\n" /* line 321 */
        "movl %eax, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl 0x158(%edi), %esi\n" /* line 322 */
        "movl 0x144(%esi, %ebx, 4), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1afa1a_001b065f\n"
        "movl 0x344(%esi, %eax, 4), %ebx\n" /* iAmmoIndex */
        "testl %ebx, %ebx\n" /* iAmmoIndex */
        "je .Lf1afa1a_001b0757\n"
        ".Lf1afa1a_001b065f:\n"
        "addl $1, -0x68(%ebp)\n" /* line 317 | iDropSlot */
        "cmpl $3, -0x68(%ebp)\n" /* iDropSlot */
        "je .Lf1afa1a_001b026e\n"
        "jmp .Lf1afa1a_001b0619\n"
        /* } scope */
        ".Lf1afa1a_001b066f:\n"
        "movl 0x158(%edi), %eax\n" /* line 291 */
        "movl 0xd4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x158(%edi), %edx\n"
        "movl 0x80(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xd4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll BG_GetStackSlotForWeapon\n"
        "testl %eax, %eax\n"
        "jne .Lf1afa1a_001afd7b\n"
        "movl -0x6c(%ebp), %eax\n" /* line 294 */
        "movl %eax, 4(%esp)\n"
        "movl 0x158(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetEmptySlotForWeapon\n"
        "testl %eax, %eax\n"
        "jne .Lf1afa1a_001afd7b\n"
        "movl $0x2b4ae8, (%esp)\n" /* line 296 */
        "calll Com_Printf\n"
        "jmp .Lf1afa1a_001afa5c\n"
        ".Lf1afa1a_001b06db:\n"
        "movl $0, 8(%esp)\n" /* line 307 */
        "movl 0x158(%edi), %eax\n"
        "movl 0xd4(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Drop_Weapon\n"
        "movl %eax, -0x78(%ebp)\n" /* pDropped */
        ".Lf1afa1a_001b06fe:\n"
        "movl -0x78(%ebp), %ecx\n" /* line 338 | pDropped */
        "testl %ecx, %ecx\n"
        "je .Lf1afa1a_001afa5c\n"
        "movl 8(%ebp), %ebx\n" /* line 342 | ent, iAmmoIndex */
        "movl 0x170(%ebx), %eax\n" /* iAmmoIndex */
        "movl -0x78(%ebp), %edx\n" /* pDropped */
        "movl %eax, 0x170(%edx)\n"
        "movl 0x7c(%ebx), %eax\n" /* line 343 | iAmmoIndex */
        "movl %eax, 0x7c(%edx)\n"
        "movl %ebx, %eax\n" /* line 345 | iAmmoIndex */
        "addl $0x138, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll G_SetOrigin\n"
        "movl %ebx, %eax\n" /* line 346 | iAmmoIndex */
        "addl $0x144, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x78(%ebp), %ebx\n" /* pDropped, iAmmoIndex */
        "movl %ebx, (%esp)\n" /* iAmmoIndex */
        "calll G_SetAngle\n"
        "movl %ebx, (%esp)\n" /* line 348 | iAmmoIndex */
        "calll SV_LinkEntity\n"
        "jmp .Lf1afa1a_001afdd6\n"
        /* { scope 3 */
        ".Lf1afa1a_001b0757:\n"
        "movl $0, 8(%esp)\n" /* line 325 */
        "movl -0x64(%ebp), %edx\n" /* iWeap */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Drop_Weapon\n"
        "movl %eax, -0x78(%ebp)\n" /* pDropped */
        "jmp .Lf1afa1a_001b06fe\n"
    );
}

/* line 516 */
void Touch_Item_Auto(gentity_t *ent, gentity_t *other, qboolean bTouched)
{
    ENT_ACTIVE(ent) = 1;
    Touch_Item(ent, other, bTouched);
}

/* line 1311 */
__attribute__((naked))
void G_SpawnItem(gentity_t *ent, const gitem_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1311 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, -0x1c(%ebp)\n" /* item */
        "movl 0x195eda8, %edi\n" /* line 1313 */
        "movl %eax, %ecx\n"
        "subl %edi, %ecx\n"
        "sarl $2, %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "movl %ecx, %eax\n"
        "shll $0xa, %eax\n"
        "subl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $0xf, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 4), %esi\n"
        "negl %esi\n"
        "movl itemRegistered(, %esi, 4), %eax\n" /* line 1218 */
        "testl %eax, %eax\n"
        "jne .Lf1b078a_001b0848\n"
        "movl 0x195f6a0, %eax\n" /* line 1224 */
        "movl 0x1c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1b078a_001b0816\n"
        /* { scope 1 */
        "leal (%esi, %esi, 4), %eax\n" /* line 1228 */
        "leal (%esi, %eax, 2), %eax\n"
        "movl 0x14(%edi, %eax, 4), %eax\n"
        "testl %eax, %eax\n" /* line 1229 */
        "je .Lf1b078a_001b09d0\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1b078a_001b09d0\n"
        "movl %eax, 4(%esp)\n" /* line 1231 */
        "movl $0x2b4990, (%esp)\n" /* "game tried to register the item '%s' after initialization fi" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl 0x195eda8, %edi\n"
        /* } scope */
        ".Lf1b078a_001b0816:\n"
        "movl $1, itemRegistered(, %esi, 4)\n" /* line 1233 */
        "leal (%esi, %esi, 4), %eax\n" /* line 1235 */
        "leal (%esi, %eax, 2), %eax\n"
        "leal (%edi, %eax, 4), %edi\n"
        "movl 8(%edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1b078a_001b0839\n"
        "movl %eax, (%esp)\n" /* line 1236 */
        "calll G_ModelIndex\n"
        ".Lf1b078a_001b0839:\n"
        "movl 0xc(%edi), %eax\n" /* line 1237 */
        "testl %eax, %eax\n"
        "je .Lf1b078a_001b0848\n"
        "movl %eax, (%esp)\n" /* line 1238 */
        "calll G_ModelIndex\n"
        ".Lf1b078a_001b0848:\n"
        "movw %si, 0x1ac(%ebx)\n" /* line 1314 | ent */
        "movl -0x1c(%ebp), %edx\n" /* line 1316 | item */
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_SetModel\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1318 | item */
        "cmpl $1, 0x1c(%eax)\n"
        "je .Lf1b078a_001b099d\n"
        "leal 0x104(%ebx), %edx\n" /* line 1325 | ent, v */
        /* { scope 1 */
        "movl $0xbf800000, %eax\n" /* line 191 */
        "movl %eax, 0x104(%ebx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0x110(%ebx), %edx\n" /* line 1326 | ent, v */
        /* { scope 1 */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, 0x110(%ebx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl $0x40000000, 8(%edx)\n" /* line 193 */
        /* } scope */
        ".Lf1b078a_001b08a4:\n"
        "movl $0x405c0108, 0x11c(%ebx)\n" /* line 1329 | ent */
        "movl -0x1c(%ebp), %edx\n" /* line 1330 | item */
        "cmpl $2, 0x1c(%edx)\n"
        "je .Lf1b078a_001b08c1\n"
        "movl $0x407c0108, 0x11c(%ebx)\n" /* line 1332 | ent */
        ".Lf1b078a_001b08c1:\n"
        "movl $3, 4(%ebx)\n" /* line 1335 | ent */
        "movzwl 0x1ac(%ebx), %eax\n" /* line 1336 | ent */
        "movl %eax, 0x8c(%ebx)\n" /* ent */
        "movl %ebx, (%esp)\n" /* line 1338 | ent */
        "calll G_DObjUpdate\n"
        "movl $0x3fe, 0x90(%ebx)\n" /* line 1341 | ent */
        "orl $__mh_execute_header, 0x174(%ebx)\n" /* line 1343 | ent */
        "movl 0x195f6a0, %esi\n" /* line 1345 */
        "cmpb $0, 0x1348(%esi)\n"
        "jne .Lf1b078a_001b096d\n"
        "movb $0x11, 0x166(%ebx)\n" /* line 1355 | ent */
        "testb $1, 0x170(%ebx)\n" /* line 1356 | ent */
        "je .Lf1b078a_001b0943\n"
        ".Lf1b078a_001b0910:\n"
        "leal 0x144(%ebx), %eax\n" /* line 1362 | ent */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_SetAngle\n"
        "leal 0x138(%ebx), %eax\n" /* line 1363 | ent */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_SetOrigin\n"
        "movl %ebx, 8(%ebp)\n" /* line 1364 | ent */
        "addl $0x2c, %esp\n" /* line 1366 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp SV_LinkEntity\n" /* line 1364 */
        ".Lf1b078a_001b0943:\n"
        "movl $0x3ff, 0x7c(%ebx)\n" /* line 1358 | ent */
        "movl -0x1c(%ebp), %eax\n" /* line 1359 | item */
        "cmpl $1, 0x1c(%eax)\n"
        "jne .Lf1b078a_001b0910\n"
        "movss 0x2ed5f8, %xmm0\n" /* line 1360 | 90.0f */
        "addss 0x14c(%ebx), %xmm0\n" /* ent */
        "movss %xmm0, 0x14c(%ebx)\n" /* ent */
        "jmp .Lf1b078a_001b0910\n"
        ".Lf1b078a_001b096d:\n"
        "leal 0x144(%ebx), %eax\n" /* line 1349 | ent */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_SetAngle\n"
        "movl 0x1ec(%esi), %eax\n" /* line 1350 */
        "addl $0x64, %eax\n"
        "movl %eax, 0x190(%ebx)\n" /* ent */
        "movb $0x10, 0x166(%ebx)\n" /* line 1351 | ent */
        "addl $0x2c, %esp\n" /* line 1366 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b078a_001b099d:\n"
        "leal 0x104(%ebx), %edx\n" /* line 1320 | ent, v */
        /* { scope 1 */
        "movl $0xbf800000, %eax\n" /* line 191 */
        "movl %eax, 0x104(%ebx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl %eax, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0x110(%ebx), %edx\n" /* line 1321 | ent, v */
        /* { scope 1 */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, 0x110(%ebx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl %eax, 8(%edx)\n" /* line 193 */
        "jmp .Lf1b078a_001b08a4\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1b078a_001b09d0:\n"
        "movl $0x2b4984, %eax\n" /* line 1229 */
        "movl %eax, 4(%esp)\n" /* line 1231 */
        "movl $0x2b4990, (%esp)\n" /* "game tried to register the item '%s' after initialization fi" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl 0x195eda8, %edi\n"
        "jmp .Lf1b078a_001b0816\n"
    );
}

