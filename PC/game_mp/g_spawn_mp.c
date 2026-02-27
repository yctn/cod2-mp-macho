/* ASM dump from: g_spawn_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_spawn_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern qboolean G_SpawnStringInternal(const char *spawnVars, const char *key, const char *defaultString, const char **out);
extern void Scr_AddFields(const char *name, const void *fields);
extern void Scr_AddEntityNum(int entNum, int classnum);
extern int Scr_ExecEntThreadNum(int entNum, int classnum, scr_func_t handle, unsigned int paramcount);
extern void Scr_NotifyNum(int entNum, int classnum, int stringValue, unsigned int paramcount);
extern void Scr_Error(const char *msg);

extern spawn_t spawns[22]; /* 0x0 */
static const ent_field_t fields[11]; /* 0x333360 */

qboolean G_SpawnString(const char *key, const char *defaultString, const char * *out);
static my_upsampler Scr_ReadOnlyField(gentity_t *ent, int offset);
static unsigned int G_SetEntityScriptVariableInternal(void);
my_upsampler G_DuplicateEntityFields(gentity_t *dest, const gentity_t *source);
static const gitem_t * G_GetItemForClassname(void);
qboolean G_CallSpawnEntity(gentity_t *ent);
my_upsampler GScr_AddFieldsForEntity(void);
my_upsampler GScr_AddFieldsForRadiant(void);
my_upsampler Scr_AddEntity(gentity_t *ent);
gentity_t * Scr_GetEntity(unsigned int index);
my_upsampler Scr_FreeHudElem(game_hudelem_t *hud);
my_upsampler Scr_AddHudElem(game_hudelem_t *hud);
scr_thread_t Scr_ExecEntThread(gentity_t *ent, scr_func_t handle, unsigned int paramcount);
my_upsampler Scr_Notify(gentity_t *ent, int stringValue, unsigned int paramcount);
static my_upsampler G_ParseEntityField(gentity_t *ent);
my_upsampler Scr_GetGenericField(byte *b, fieldtype_t type, int ofs);
my_upsampler Scr_GetEnt(void);
my_upsampler Scr_GetEntArray(void);
qboolean G_SpawnFloat(const char *key, const char *defaultString, float *out);
qboolean G_SpawnInt(const char *key, const char *defaultString, int *out);
qboolean G_SpawnVector(const char *key, const char *defaultString, float *out);
my_upsampler SP_worldspawn(void);
my_upsampler G_LoadStructs(void);
my_upsampler Scr_SetGenericField(byte *b, fieldtype_t type, int ofs);
qboolean Scr_SetObjectField(unsigned int classnum, int entnum, int offset);
my_upsampler Scr_GetObjectField(unsigned int classnum, int entnum, int offset);
my_upsampler Scr_FreeEntity(gentity_t *ent);
my_upsampler G_CallSpawn(void);
my_upsampler G_SpawnEntitiesFromString(void);

/* line 7 */
qboolean G_SpawnString(const char *key, const char *defaultString, const char * *out)
{
    return G_SpawnStringInternal((const char *)(*(int *)0x195f6a0 + 0x1348), key, defaultString, out);
}

/* line 47 */
static __attribute__((naked))
my_upsampler Scr_ReadOnlyField(gentity_t *ent, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 47 */
        "movl %esp, %ebp\n"
        "movl $0x2b33d0, 8(%ebp)\n" /* line 49 | ent */
        "popl %ebp\n" /* line 50 */
        "jmp Scr_Error\n" /* line 49 */
    );
}

/* line 160 */
static __attribute__((naked))
unsigned int G_SetEntityScriptVariableInternal(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 160 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %edx, %esi\n" /* value */
        /* { scope 1 */
        "leal -0x1c(%ebp), %edx\n" /* line 166 | type */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n" /* key */
        "calll Scr_FindField\n"
        "movl %eax, %edi\n" /* key, index */
        "testl %eax, %eax\n" /* line 167 | key */
        "je .Lf19e2c0_0019e2ef\n"
        "movl -0x1c(%ebp), %eax\n" /* line 170 | type, key */
        "cmpl $4, %eax\n" /* key */
        "je .Lf19e2c0_0019e315\n"
        "jg .Lf19e2c0_0019e2f9\n"
        "cmpl $2, %eax\n" /* key */
        "je .Lf19e2c0_0019e357\n"
        /* } scope */
        ".Lf19e2c0_0019e2ef:\n"
        "movl %edi, %eax\n" /* line 196 | index, key */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19e2c0_0019e2f9:\n"
        "cmpl $5, %eax\n" /* line 170 | key */
        "je .Lf19e2c0_0019e361\n"
        "cmpl $6, %eax\n" /* key */
        "jne .Lf19e2c0_0019e2ef\n"
        "movl %esi, (%esp)\n" /* line 181 | value */
        "calll atoi\n"
        "movl %eax, (%esp)\n" /* key */
        "calll Scr_AddInt\n"
        "jmp .Lf19e2c0_0019e2ef\n"
        ".Lf19e2c0_0019e315:\n"
        "xorl %eax, %eax\n" /* line 183 | key */
        "movl %eax, -0x28(%ebp)\n" /* key, vec */
        "movl %eax, -0x24(%ebp)\n" /* line 184 | key */
        "movl %eax, -0x20(%ebp)\n" /* line 185 | key */
        "leal -0x28(%ebp), %ebx\n" /* line 186 | vec */
        "leal -0x20(%ebp), %eax\n" /* key */
        "movl %eax, 0x10(%esp)\n" /* key */
        "leal -0x24(%ebp), %eax\n" /* key */
        "movl %eax, 0xc(%esp)\n" /* key */
        "movl %ebx, 8(%esp)\n"
        "movl $0x21c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %esi, (%esp)\n" /* value */
        "calll sscanf\n"
        "movl %ebx, (%esp)\n" /* line 187 */
        "calll Scr_AddVector\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 196 | index, key */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19e2c0_0019e357:\n"
        "movl %esi, (%esp)\n" /* line 173 | value */
        "calll Scr_AddString\n"
        "jmp .Lf19e2c0_0019e2ef\n"
        ".Lf19e2c0_0019e361:\n"
        "movl %esi, (%esp)\n" /* line 177 | value */
        "calll atof\n"
        "fstpl -0x30(%ebp)\n"
        "cvtsd2ss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll Scr_AddFloat\n"
        "jmp .Lf19e2c0_0019e2ef\n"
    );
}

/* line 337 */
__attribute__((naked))
my_upsampler G_DuplicateEntityFields(gentity_t *dest, const gentity_t *source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 337 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dest */
        "movl 0xc(%ebp), %esi\n" /* source */
        "movl fields, %eax\n" /* line 346 */
        "testl %eax, %eax\n"
        "je .Lf19e380_0019e3bf\n"
        "movl $0x333368, %ebx\n"
        ".Lf19e380_0019e39d:\n"
        "cmpl $8, (%ebx)\n" /* line 348 */
        "ja .Lf19e380_0019e3b5\n"
        "movl (%ebx), %eax\n"
        "jmpl *0x303020(, %eax, 4)\n"
        "movl -4(%ebx), %edx\n" /* line 363 */
        "movzbl (%esi, %edx), %eax\n" /* source */
        "movb %al, (%edi, %edx)\n" /* dest */
        ".Lf19e380_0019e3b5:\n"
        "movl 8(%ebx), %eax\n" /* line 346 */
        "addl $0x10, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf19e380_0019e39d\n"
        ".Lf19e380_0019e3bf:\n"
        "addl $0x1c, %esp\n" /* line 370 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl -4(%ebx), %edx\n" /* line 357 */
        "movl (%esi, %edx), %eax\n" /* source */
        "movl %eax, (%edi, %edx)\n" /* dest */
        "movl 8(%ebx), %eax\n" /* line 346 */
        "addl $0x10, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf19e380_0019e39d\n"
        "jmp .Lf19e380_0019e3bf\n"
        "movl -4(%ebx), %edx\n" /* line 360 */
        "movl (%esi, %edx), %eax\n" /* source */
        "movl %eax, (%edi, %edx)\n" /* dest */
        "movl 8(%ebx), %eax\n" /* line 346 */
        "addl $0x10, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf19e380_0019e39d\n"
        "jmp .Lf19e380_0019e3bf\n"
        "movl -4(%ebx), %eax\n" /* line 351 */
        "movzwl (%esi, %eax), %edx\n" /* source */
        "movl %edx, 4(%esp)\n"
        "leal (%edi, %eax), %eax\n" /* dest */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 8(%ebx), %eax\n" /* line 346 */
        "addl $0x10, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf19e380_0019e39d\n"
        "jmp .Lf19e380_0019e3bf\n"
        "movl -4(%ebx), %eax\n" /* line 354 | from */
        "leal (%edi, %eax), %ecx\n" /* dest, to */
        "leal (%esi, %eax), %eax\n" /* source, from */
        /* { scope 1 */
        "movl (%eax), %edx\n" /* line 199 */
        "movl %edx, (%ecx)\n"
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl 8(%eax), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl 8(%ebx), %eax\n" /* line 346 */
        "addl $0x10, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf19e380_0019e39d\n"
        "jmp .Lf19e380_0019e3bf\n"
    );
}

/* line 392 */
static __attribute__((naked))
const gitem_t * G_GetItemForClassname(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 392 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %ebx\n" /* classname */
        /* { scope 1 */
        "movl $0x2b33f8, %edi\n" /* line 399 | itemIndex */
        "movl $7, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n" /* weapIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* itemIndex, weapIndex */
        "movl $0, %edx\n"
        "je .Lf19e43e_0019e469\n"
        "movzbl -1(%esi), %edx\n" /* weapIndex */
        "movzbl -1(%edi), %ecx\n" /* itemIndex */
        "subl %ecx, %edx\n"
        ".Lf19e43e_0019e469:\n"
        "testl %edx, %edx\n"
        "jne .Lf19e43e_0019e47e\n"
        "leal 7(%ebx), %eax\n" /* line 401 | classname */
        "movl %eax, (%esp)\n"
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, %esi\n" /* weapIndex */
        "testl %eax, %eax\n" /* line 402 */
        "jne .Lf19e43e_0019e4cb\n"
        ".Lf19e43e_0019e47e:\n"
        "movl 0x195edac, %eax\n" /* line 409 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl $0x81, %eax\n"
        "jg .Lf19e43e_0019e49b\n"
        ".Lf19e43e_0019e48f:\n"
        "xorl %esi, %esi\n" /* weapIndex */
        /* } scope */
        ".Lf19e43e_0019e491:\n"
        "movl %esi, %eax\n" /* line 418 | weapIndex */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19e43e_0019e49b:\n"
        "movl $0x81, %edi\n" /* line 409 | itemIndex */
        "movl 0x195eda8, %eax\n"
        "addl $0x162c, %eax\n"
        ".Lf19e43e_0019e4aa:\n"
        "movl %eax, %esi\n" /* line 411 | weapIndex */
        "movl %ebx, 4(%esp)\n" /* line 413 | classname */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf19e43e_0019e491\n"
        "addl $1, %edi\n" /* line 409 | itemIndex */
        "leal 0x2c(%esi), %eax\n" /* weapIndex */
        "cmpl %edi, -0x1c(%ebp)\n" /* itemIndex */
        "jne .Lf19e43e_0019e4aa\n"
        "jmp .Lf19e43e_0019e48f\n"
        ".Lf19e43e_0019e4cb:\n"
        "movl %eax, (%esp)\n" /* line 404 */
        "calll BG_GetWeaponDef\n"
        "movl %esi, (%esp)\n" /* line 405 | weapIndex */
        "calll BG_FindItemForWeapon\n"
        "movl %eax, %esi\n" /* weapIndex */
        /* } scope */
        "movl %esi, %eax\n" /* line 418 | weapIndex */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 481 */
__attribute__((naked))
qboolean G_CallSpawnEntity(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 481 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1 */
        "movzwl 0x168(%edi), %eax\n" /* line 487 | ent */
        "testw %ax, %ax\n"
        "jne .Lf19e4e8_0019e516\n"
        "movl $0x2b3400, (%esp)\n" /* line 489 */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf19e4e8_0019e50e:\n"
        "addl $0x1c, %esp\n" /* line 515 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19e4e8_0019e516:\n"
        "movzwl %ax, %eax\n" /* line 493 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %esi\n" /* classname */
        "calll G_GetItemForClassname\n" /* line 495 */
        "testl %eax, %eax\n" /* line 496 */
        "je .Lf19e4e8_0019e545\n"
        "movl %eax, 4(%esp)\n" /* line 498 */
        "movl %edi, (%esp)\n" /* ent */
        "calll G_SpawnItem\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 515 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19e4e8_0019e545:\n"
        "movl spawns, %eax\n" /* line 503 */
        "testl %eax, %eax\n"
        "je .Lf19e4e8_0019e56c\n"
        "movl $spawns, %ebx\n"
        ".Lf19e4e8_0019e553:\n"
        "movl %esi, 4(%esp)\n" /* line 505 | classname */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf19e4e8_0019e595\n"
        "addl $8, %ebx\n" /* line 503 */
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf19e4e8_0019e553\n"
        ".Lf19e4e8_0019e56c:\n"
        "movzwl 0x168(%edi), %eax\n" /* line 513 | ent */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b3424, (%esp)\n" /* "%s doesn't have a spawn function
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 515 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19e4e8_0019e595:\n"
        "movl %edi, (%esp)\n" /* line 508 | ent */
        "calll *4(%ebx)\n"
        "movl $1, %eax\n"
        "jmp .Lf19e4e8_0019e50e\n"
    );
}

/* line 523 */
__attribute__((naked))
my_upsampler GScr_AddFieldsForEntity(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 523 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl fields, %edx\n" /* line 527 */
        "testl %edx, %edx\n"
        "je .Lf19e5a6_0019e5e7\n"
        "xorl %esi, %esi\n" /* line 523 */
        "movl $0x333370, %ebx\n"
        ".Lf19e5a6_0019e5bf:\n"
        "movl %esi, %eax\n" /* line 531 */
        "sarl $4, %eax\n"
        "movzwl %ax, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_AddClassField\n"
        "movl (%ebx), %edx\n" /* line 527 */
        "addl $0x10, %esi\n"
        "addl $0x10, %ebx\n"
        "testl %edx, %edx\n"
        "jne .Lf19e5a6_0019e5bf\n"
        ".Lf19e5a6_0019e5e7:\n"
        "addl $0x10, %esp\n" /* line 535 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp GScr_AddFieldsForClient\n" /* line 534 */
    );
}

/* line 543 */
my_upsampler GScr_AddFieldsForRadiant(void)
{
    Scr_AddFields("radiant", (const void *)0x2b3448);
}

/* line 814 */
my_upsampler Scr_AddEntity(gentity_t *ent)
{
    Scr_AddEntityNum(*(int *)ent, 0);
}

/* line 829 */
__attribute__((naked))
gentity_t * Scr_GetEntity(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 829 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl %ebx, (%esp)\n" /* line 833 | index */
        "calll Scr_GetEntityRef\n"
        "movl %eax, %edx\n"
        "shrl $0x10, %eax\n" /* line 834 */
        "testw %ax, %ax\n"
        "jne .Lf19e62c_0019e668\n"
        "movzwl %dx, %eax\n" /* line 837 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl 0x195f688, %edx\n"
        ".Lf19e62c_0019e660:\n"
        "movl %edx, %eax\n" /* line 841 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19e62c_0019e668:\n"
        "movl $0x2b21c8, 4(%esp)\n" /* line 839 */
        "movl %ebx, (%esp)\n" /* index */
        "calll Scr_ParamError\n"
        "xorl %edx, %edx\n"
        "jmp .Lf19e62c_0019e660\n"
    );
}

/* line 849 */
__attribute__((naked))
my_upsampler Scr_FreeHudElem(game_hudelem_t *hud)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 849 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* hud */
        "movl %ebx, (%esp)\n" /* line 855 | hud */
        "calll Scr_FreeHudElemConstStrings\n"
        "movl $1, 4(%esp)\n" /* line 856 */
        "subl 0x195f6c4, %ebx\n" /* hud */
        "sarl $2, %ebx\n" /* hud */
        "imull $0x8af8af8b, %ebx, %ebx\n" /* hud */
        "movl %ebx, (%esp)\n" /* hud */
        "calll Scr_FreeEntityNum\n"
        "addl $0x14, %esp\n" /* line 857 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 865 */
__attribute__((naked))
my_upsampler Scr_AddHudElem(game_hudelem_t *hud)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 865 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl $1, 4(%esp)\n" /* line 871 */
        "subl 0x195f6c4, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddEntityNum\n"
        "leave\n" /* line 872 */
        "retl\n"
    );
}

/* line 900 */
scr_thread_t Scr_ExecEntThread(gentity_t *ent, scr_func_t handle, unsigned int paramcount)
{
    return (unsigned short)Scr_ExecEntThreadNum(*(int *)ent, 0, handle, paramcount);
}

/* line 930 */
my_upsampler Scr_Notify(gentity_t *ent, int stringValue, unsigned int paramcount)
{
    Scr_NotifyNum(*(int *)ent, 0, (unsigned short)stringValue, paramcount);
}

/* line 225 */
static __attribute__((naked))
my_upsampler G_ParseEntityField(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 225 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, %esi\n" /* key */
        "movl %edx, %edi\n" /* value */
        "movl %ecx, -0x34(%ebp)\n"
        /* { scope 1 */
        "movl fields, %eax\n" /* line 232 */
        "testl %eax, %eax\n"
        "je .Lf19e73a_0019e771\n"
        "movl $fields, %ebx\n"
        ".Lf19e73a_0019e758:\n"
        "movl %esi, 4(%esp)\n" /* line 234 | key */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf19e73a_0019e7a7\n"
        "addl $0x10, %ebx\n" /* line 232 */
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf19e73a_0019e758\n"
        ".Lf19e73a_0019e771:\n"
        "movl %edi, %edx\n" /* line 209 */
        "movl %esi, %eax\n"
        "calll G_SetEntityScriptVariableInternal\n"
        "testl %eax, %eax\n" /* line 210 */
        "jne .Lf19e73a_0019e786\n"
        /* } scope */
        ".Lf19e73a_0019e77e:\n"
        "addl $0x4c, %esp\n" /* line 280 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf19e73a_0019e786:\n"
        "movl %eax, 8(%esp)\n" /* line 1059 */
        "movl $0, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetDynamicEntityField\n"
        /* } scope */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 280 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19e73a_0019e7a7:\n"
        "cmpl $8, 8(%ebx)\n" /* line 239 */
        "ja .Lf19e73a_0019e77e\n"
        "movl 8(%ebx), %eax\n"
        "jmpl *0x303044(, %eax, 4)\n"
        "movl 4(%ebx), %eax\n" /* line 253 */
        "addl %eax, -0x34(%ebp)\n"
        "movl %edi, (%esp)\n" /* value */
        "calll atoi\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "jmp .Lf19e73a_0019e77e\n"
        "movl 4(%ebx), %ecx\n" /* line 256 */
        "addl %ecx, -0x34(%ebp)\n"
        "movl %edi, (%esp)\n" /* value */
        "calll atof\n"
        "fstpl -0x30(%ebp)\n"
        "cvtsd2ss -0x30(%ebp), %xmm0\n"
        "movl -0x34(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "jmp .Lf19e73a_0019e77e\n"
        "movl $0, 4(%esp)\n" /* line 242 */
        "movl -0x34(%ebp), %eax\n"
        "addl 4(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 4(%ebx), %eax\n" /* line 243 */
        "addl %eax, -0x34(%ebp)\n"
        "movl %edi, (%esp)\n" /* value */
        "calll G_NewString\n"
        "movl -0x34(%ebp), %edx\n"
        "movw %ax, (%edx)\n"
        "jmp .Lf19e73a_0019e77e\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x24(%ebp)\n" /* vec */
        "movl %eax, -0x20(%ebp)\n" /* line 184 */
        "movl %eax, -0x1c(%ebp)\n" /* line 185 */
        "leal -0x24(%ebp), %edx\n" /* line 247 | vec */
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x20(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x21c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %edi, (%esp)\n" /* value */
        "calll sscanf\n"
        "movl 4(%ebx), %edx\n" /* line 248 */
        "movl -0x24(%ebp), %eax\n" /* vec */
        "movl -0x34(%ebp), %ecx\n"
        "movl %eax, (%ecx, %edx)\n"
        "movl 4(%ebx), %edx\n" /* line 249 */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%ecx, %edx)\n"
        "movl 4(%ebx), %edx\n" /* line 250 */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%ecx, %edx)\n"
        "jmp .Lf19e73a_0019e77e\n"
        "cmpb $0x2a, (%edi)\n" /* line 259 | value */
        "je .Lf19e73a_0019e888\n"
        "movl %edi, 4(%esp)\n" /* line 267 | value */
        "movl -0x34(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll G_SetModel\n"
        "jmp .Lf19e73a_0019e77e\n"
        ".Lf19e73a_0019e888:\n"
        "leal 1(%edi), %eax\n" /* line 261 | value */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movzwl %ax, %eax\n" /* line 263 */
        "movl -0x34(%ebp), %edx\n"
        "movl %eax, 0x8c(%edx)\n"
        "jmp .Lf19e73a_0019e77e\n"
    );
}

/* line 689 */
__attribute__((naked))
my_upsampler Scr_GetGenericField(byte *b, fieldtype_t type, int ofs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 689 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* type */
        /* { scope 1 */
        "cmpl $8, %eax\n" /* line 696 */
        "ja .Lf19e8a4_0019e8d4\n"
        "jmpl *0x303068(, %eax, 4)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 732 | ofs */
        "movl 8(%ebp), %ebx\n" /* b */
        "movzbl (%ecx, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        /* } scope */
        ".Lf19e8a4_0019e8d4:\n"
        "addl $0x24, %esp\n" /* line 738 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl 8(%ebp), %ebx\n" /* line 711 | b */
        "movl 0x10(%ebp), %edx\n" /* ofs */
        "movl (%ebx, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "jmp .Lf19e8a4_0019e8d4\n"
        "movl 8(%ebp), %ebx\n" /* line 727 | b */
        "movl 0x10(%ebp), %edx\n" /* ofs */
        "movzwl (%ebx, %edx), %eax\n"
        "testw %ax, %ax\n" /* line 728 */
        "je .Lf19e8a4_0019e8d4\n"
        "movzwl %ax, %eax\n" /* line 729 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddObject\n"
        "jmp .Lf19e8a4_0019e8d4\n"
        "xorl %eax, %eax\n" /* line 717 */
        "movl %eax, -0x14(%ebp)\n" /* vec */
        "movl 8(%ebp), %ecx\n" /* line 718 | b */
        "movl 0x10(%ebp), %ebx\n" /* ofs */
        "movl (%ecx, %ebx), %edx\n"
        "movl %edx, -0x10(%ebp)\n"
        "movl %eax, -0xc(%ebp)\n" /* line 719 */
        "leal -0x14(%ebp), %eax\n" /* line 720 | vec */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        "jmp .Lf19e8a4_0019e8d4\n"
        "movl 8(%ebp), %edx\n" /* line 723 | b */
        "movl 0x10(%ebp), %ecx\n" /* ofs */
        "movl (%edx, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf19e8a4_0019e8d4\n"
        "movl $0, 4(%esp)\n" /* line 820 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddEntityNum\n"
        "jmp .Lf19e8a4_0019e8d4\n"
        "movl 8(%ebp), %eax\n" /* line 708 | b */
        "addl 0x10(%ebp), %eax\n" /* ofs */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        "jmp .Lf19e8a4_0019e8d4\n"
        "movl 8(%ebp), %edx\n" /* line 699 | b */
        "movl 0x10(%ebp), %ecx\n" /* ofs */
        "movzwl (%edx, %ecx), %eax\n"
        "testw %ax, %ax\n" /* line 700 */
        "je .Lf19e8a4_0019e8d4\n"
        "movzwl %ax, %eax\n" /* line 701 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        "jmp .Lf19e8a4_0019e8d4\n"
        "movl 8(%ebp), %eax\n" /* line 705 | b */
        "addl 0x10(%ebp), %eax\n" /* ofs */
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        "jmp .Lf19e8a4_0019e8d4\n"
        "movl 8(%ebp), %ecx\n" /* line 714 | b */
        "movl 0x10(%ebp), %ebx\n" /* ofs */
        "movl (%ecx, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddFloat\n"
        "jmp .Lf19e8a4_0019e8d4\n"
    );
}

/* line 945 */
__attribute__((naked))
my_upsampler Scr_GetEnt(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 945 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 957 */
        "calll Scr_GetConstString\n"
        "movw %ax, -0x1a(%ebp)\n" /* name */
        "movl $1, (%esp)\n" /* line 958 */
        "calll Scr_GetString\n"
        "movl %eax, 4(%esp)\n" /* line 960 */
        "movl $0, (%esp)\n"
        "calll Scr_GetOffset\n"
        "testl %eax, %eax\n" /* line 961 */
        "js .Lf19e9ac_0019e9f4\n"
        "shll $4, %eax\n" /* line 966 */
        "leal fields(%eax), %edi\n" /* f */
        "cmpl $3, 8(%edi)\n" /* line 969 | f */
        "je .Lf19e9ac_0019e9fc\n"
        /* } scope */
        ".Lf19e9ac_0019e9f4:\n"
        "addl $0x2c, %esp\n" /* line 990 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19e9ac_0019e9fc:\n"
        "movl 0x195f6a0, %ecx\n" /* line 973 */
        "movl 0xc(%ecx), %ebx\n" /* ent */
        "testl %ebx, %ebx\n" /* ent */
        "jle .Lf19e9ac_0019e9f4\n"
        "xorl %esi, %esi\n" /* i */
        "movl 0x195f688, %ebx\n" /* ent */
        "xorl %edx, %edx\n"
        ".Lf19e9ac_0019ea13:\n"
        "cmpb $0, 0xfc(%ebx)\n" /* line 975 | ent */
        "je .Lf19e9ac_0019ea2e\n"
        "movl 4(%edi), %eax\n" /* line 978 | f */
        "movzwl (%ebx, %eax), %eax\n" /* ent */
        "testw %ax, %ax\n" /* line 979 */
        "je .Lf19e9ac_0019ea2e\n"
        "cmpw %ax, -0x1a(%ebp)\n" /* line 981 | name */
        "je .Lf19e9ac_0019ea5a\n"
        ".Lf19e9ac_0019ea2e:\n"
        "addl $1, %esi\n" /* line 973 | i */
        "addl $0x230, %ebx\n" /* ent */
        "cmpl 0xc(%ecx), %esi\n" /* i */
        "jl .Lf19e9ac_0019ea13\n"
        "testl %edx, %edx\n" /* line 988 */
        "je .Lf19e9ac_0019e9f4\n"
        "movl $0, 4(%esp)\n" /* line 820 */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddEntityNum\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 990 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19e9ac_0019ea5a:\n"
        "testl %edx, %edx\n" /* line 983 */
        "je .Lf19e9ac_0019ea74\n"
        "movl $0x2b3454, (%esp)\n" /* line 984 */
        "calll Scr_Error\n"
        "movl %ebx, %edx\n" /* ent */
        "movl 0x195f6a0, %ecx\n"
        "jmp .Lf19e9ac_0019ea2e\n"
        ".Lf19e9ac_0019ea74:\n"
        "movl %ebx, %edx\n" /* line 983 | ent */
        "jmp .Lf19e9ac_0019ea2e\n"
    );
}

/* line 998 */
__attribute__((naked))
my_upsampler Scr_GetEntArray(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 998 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 1009 */
        "testl %eax, %eax\n"
        "jne .Lf19ea78_0019eaf4\n"
        "calll Scr_MakeArray\n" /* line 1011 */
        "movl 0x195f6a0, %edx\n" /* line 1012 */
        "movl 0xc(%edx), %edi\n" /* ent */
        "testl %edi, %edi\n" /* ent */
        "jle .Lf19ea78_0019eaec\n"
        "xorl %esi, %esi\n" /* i */
        "movl 0x195f688, %ebx\n"
        "addl $0xfc, %ebx\n"
        "movl %edx, %edi\n" /* ent */
        "jmp .Lf19ea78_0019eabc\n"
        ".Lf19ea78_0019eaae:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x230, %ebx\n"
        "cmpl 0xc(%edx), %esi\n" /* i */
        "jge .Lf19ea78_0019eaec\n"
        ".Lf19ea78_0019eabc:\n"
        "cmpb $0, (%ebx)\n" /* line 1014 */
        "je .Lf19ea78_0019eaae\n"
        "movl $0, 4(%esp)\n" /* line 820 */
        "movl -0xfc(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddEntityNum\n"
        "calll Scr_AddArray\n" /* line 1017 */
        "movl %edi, %edx\n" /* ent */
        "addl $1, %esi\n" /* line 1012 | i */
        "addl $0x230, %ebx\n"
        "cmpl 0xc(%edx), %esi\n" /* i */
        "jl .Lf19ea78_0019eabc\n"
        /* } scope */
        ".Lf19ea78_0019eaec:\n"
        "addl $0x2c, %esp\n" /* line 1049 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19ea78_0019eaf4:\n"
        "movl $0, (%esp)\n" /* line 1022 */
        "calll Scr_GetConstString\n"
        "movw %ax, -0x1a(%ebp)\n" /* name */
        "movl $1, (%esp)\n" /* line 1023 */
        "calll Scr_GetString\n"
        "movl %eax, 4(%esp)\n" /* line 1025 */
        "movl $0, (%esp)\n"
        "calll Scr_GetOffset\n"
        "testl %eax, %eax\n" /* line 1026 */
        "js .Lf19ea78_0019eaec\n"
        "shll $4, %eax\n" /* line 1031 */
        "addl $fields, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* f */
        "cmpl $3, 8(%eax)\n" /* line 1032 */
        "jne .Lf19ea78_0019eaec\n"
        "calll Scr_MakeArray\n" /* line 1035 */
        "movl 0x195f6a0, %edx\n" /* line 1036 */
        "movl 0xc(%edx), %esi\n" /* i */
        "testl %esi, %esi\n" /* i */
        "jle .Lf19ea78_0019eaec\n"
        "xorl %esi, %esi\n" /* i */
        "movl 0x195f688, %ebx\n"
        "movl %ebx, %edi\n" /* ent */
        "addl $0xfc, %ebx\n"
        "movl %edx, -0x24(%ebp)\n"
        ".Lf19ea78_0019eb5a:\n"
        "cmpb $0, (%ebx)\n" /* line 1038 */
        "je .Lf19ea78_0019eb74\n"
        "movl -0x20(%ebp), %ecx\n" /* line 1041 | f */
        "movl 4(%ecx), %eax\n"
        "movzwl (%eax, %edi), %eax\n"
        "testw %ax, %ax\n" /* line 1042 */
        "je .Lf19ea78_0019eb74\n"
        "cmpw %ax, -0x1a(%ebp)\n" /* line 1044 | name */
        "je .Lf19ea78_0019eb8d\n"
        ".Lf19ea78_0019eb74:\n"
        "addl $1, %esi\n" /* line 1036 | i */
        "addl $0x230, %edi\n" /* ent */
        "addl $0x230, %ebx\n"
        "cmpl %esi, 0xc(%edx)\n" /* i */
        "jg .Lf19ea78_0019eb5a\n"
        "jmp .Lf19ea78_0019eaec\n"
        ".Lf19ea78_0019eb8d:\n"
        "movl $0, 4(%esp)\n" /* line 820 */
        "movl -0xfc(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddEntityNum\n"
        "calll Scr_AddArray\n" /* line 1047 */
        "movl -0x24(%ebp), %edx\n"
        "jmp .Lf19ea78_0019eb74\n"
    );
}

/* line 13 */
__attribute__((naked))
qboolean G_SpawnFloat(const char *key, const char *defaultString, float *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 13 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1 */
        "leal -0xc(%ebp), %eax\n" /* line 9 | s */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* defaultString */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* key */
        "movl %eax, 4(%esp)\n"
        "movl 0x195f6a0, %eax\n"
        "addl $0x1348, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl %eax, %ebx\n"
        "movl -0xc(%ebp), %eax\n" /* line 19 | s */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x20(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* out */
        "cvtsd2ss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 21 | present */
        "addl $0x34, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 24 */
__attribute__((naked))
qboolean G_SpawnInt(const char *key, const char *defaultString, int *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 24 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "leal -0xc(%ebp), %eax\n" /* line 9 | s */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* defaultString */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* key */
        "movl %eax, 4(%esp)\n"
        "movl 0x195f6a0, %eax\n"
        "addl $0x1348, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl %eax, %ebx\n"
        "movl -0xc(%ebp), %eax\n" /* line 30 | s */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl 0x10(%ebp), %edx\n" /* out */
        "movl %eax, (%edx)\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 32 | present */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 35 */
__attribute__((naked))
qboolean G_SpawnVector(const char *key, const char *defaultString, float *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 35 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* out */
        /* { scope 1 */
        "leal -0xc(%ebp), %eax\n" /* line 9 | s */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* defaultString */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* key */
        "movl %eax, 4(%esp)\n"
        "movl 0x195f6a0, %eax\n"
        "addl $0x1348, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl %eax, %esi\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, (%ebx)\n" /* out */
        "leal 4(%ebx), %ecx\n" /* line 184 | out */
        "movl %eax, 4(%ebx)\n" /* out */
        "leal 8(%ebx), %edx\n" /* line 185 | out */
        "movl %eax, 8(%ebx)\n" /* out */
        "movl %edx, 0x10(%esp)\n" /* line 42 */
        "movl %ecx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* out */
        "movl $0x21c238, 4(%esp)\n" /* "%f %f %f" */
        "movl -0xc(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 44 | present */
        "addl $0x30, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1063 */
__attribute__((naked))
my_upsampler SP_worldspawn(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1063 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "leal -0x1c(%ebp), %edi\n" /* line 9 | s */
        "movl %edi, 0xc(%esp)\n"
        "movl $0x2157b8, 8(%esp)\n"
        "movl $0x21c208, 4(%esp)\n" /* "classname" */
        "movl 0x195f6a0, %esi\n"
        "leal 0x1348(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl $0x2b347c, 4(%esp)\n" /* line 1068 */
        "movl -0x1c(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf19ecb4_0019eef9\n"
        ".Lf19ecb4_0019ed03:\n"
        "movl $0x2a89ec, 4(%esp)\n" /* line 1074 */
        "movl $2, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 0x1f8(%esi), %eax\n" /* line 1076 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xd, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $0x2157b8, 8(%esp)\n"
        "movl $0x2b34bc, 4(%esp)\n" /* "ambienttrack" */
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1079 | s */
        "cmpb $0, (%eax)\n"
        "je .Lf19ecb4_0019eec7\n"
        "movl %eax, 4(%esp)\n" /* line 1080 */
        "movl $0x2b34cc, (%esp)\n" /* "n\%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll SV_SetConfigstring\n"
        ".Lf19ecb4_0019ed85:\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $0x2157b8, 8(%esp)\n"
        "movl $0x2b34d4, 4(%esp)\n" /* "message" */
        "movl 0x195f6a0, %ebx\n"
        "addl $0x1348, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1085 | s */
        "movl %eax, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 0x195f6d4, %eax\n" /* line 1087 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xe, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $0x2b34dc, 8(%esp)\n" /* "800" */
        "movl $0x21a8b4, 4(%esp)\n" /* "gravity" */
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1091 | s */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x30(%ebp)\n"
        "cvtsd2ss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl 0x195f6c8, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFloat\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $0x2157b8, 8(%esp)\n"
        "movl $0x2b34e0, 4(%esp)\n" /* "northyaw" */
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1094 | s */
        "cmpb $0, (%eax)\n"
        "je .Lf19ecb4_0019eee0\n"
        "movl %eax, 4(%esp)\n" /* line 1095 */
        "movl $0xb, (%esp)\n"
        "calll SV_SetConfigstring\n"
        ".Lf19ecb4_0019ee56:\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $0x21952c, 8(%esp)\n" /* "0" */
        "movl $0x2b33a4, 4(%esp)\n" /* "spawnflags" */
        "movl 0x195f6a0, %eax\n"
        "addl $0x1348, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1100 | s */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl 0x195f688, %ebx\n"
        "movl %eax, 0x8bd10(%ebx)\n"
        "movl $0x3fe, 0x8bba0(%ebx)\n" /* line 1102 */
        "movl 0x195f5bc, %eax\n" /* line 1103 */
        "movzwl 0x60(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x8bd08(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movb $1, 0x8bc9c(%ebx)\n" /* line 1104 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1105 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19ecb4_0019eec7:\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 1082 */
        "movl $3, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "jmp .Lf19ecb4_0019ed85\n"
        ".Lf19ecb4_0019eee0:\n"
        "movl $0x21952c, 4(%esp)\n" /* line 1097 */
        "movl $0xb, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "jmp .Lf19ecb4_0019ee56\n"
        ".Lf19ecb4_0019eef9:\n"
        "movl $0x2b3488, 4(%esp)\n" /* line 1070 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19ecb4_0019ed03\n"
    );
}

/* line 1137 */
__attribute__((naked))
my_upsampler G_LoadStructs(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1137 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl $0, 4(%esp)\n" /* line 1143 */
        "movl 0x195f6d0, %eax\n"
        "movl 0x10b0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ExecThread\n"
        "movzwl %ax, %eax\n" /* line 1144 */
        "movl %eax, (%esp)\n"
        "calll Scr_FreeThread\n"
        "movl 0x195f6a0, %ebx\n"
        "movl %ebx, -0x30(%ebp)\n"
        "jmp .Lf19ef12_0019ef52\n"
        ".Lf19ef12_0019ef4c:\n"
        "movl 0x195f6a0, %ebx\n"
        ".Lf19ef12_0019ef52:\n"
        "leal 0x1348(%ebx), %esi\n" /* line 1146 */
        "movl %esi, (%esp)\n"
        "calll G_ParseSpawnVars\n"
        "testl %eax, %eax\n"
        "je .Lf19ef12_0019f027\n"
        "leal -0x1c(%ebp), %eax\n" /* line 9 | classname */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2157b8, 8(%esp)\n"
        "movl $0x21c208, 4(%esp)\n" /* "classname" */
        "movl %esi, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1149 | classname */
        "movl $0x2b3394, %esi\n" /* "script_struct" */
        "movl $0xe, %ecx\n"
        "cld\n"
        "movl %eax, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf19ef12_0019efaa\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf19ef12_0019efaa:\n"
        "testl %eax, %eax\n"
        "jne .Lf19ef12_0019ef4c\n"
        "movl $0, 4(%esp)\n" /* line 318 */
        "movl 0x195f6d0, %eax\n"
        "movl 0x10b4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddExecThread\n"
        "movl $0, (%esp)\n" /* line 319 */
        "calll Scr_GetObject\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x134c(%ebx), %eax\n" /* line 321 */
        "testl %eax, %eax\n"
        "jle .Lf19ef12_0019ef4c\n"
        "xorl %edi, %edi\n"
        "movl %ebx, %esi\n"
        "jmp .Lf19ef12_0019f001\n"
        ".Lf19ef12_0019efec:\n"
        "addl $1, %edi\n"
        "addl $8, %esi\n"
        "movl -0x30(%ebp), %ebx\n"
        "cmpl 0x134c(%ebx), %edi\n"
        "jge .Lf19ef12_0019ef52\n"
        ".Lf19ef12_0019f001:\n"
        "movl 0x1354(%esi), %edx\n" /* line 323 */
        "movl 0x1350(%esi), %eax\n"
        "calll G_SetEntityScriptVariableInternal\n"
        "testl %eax, %eax\n" /* line 324 */
        "je .Lf19ef12_0019efec\n"
        "movl %eax, 4(%esp)\n" /* line 327 */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetStructField\n"
        "jmp .Lf19ef12_0019efec\n"
        ".Lf19ef12_0019f027:\n"
        "calll SV_ResetEntityParsePoint\n" /* line 1153 */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1154 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 594 */
__attribute__((naked))
my_upsampler Scr_SetGenericField(byte *b, fieldtype_t type, int ofs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 594 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* type */
        /* { scope 1 */
        "cmpl $6, %eax\n" /* line 598 */
        "ja .Lf19f034_0019f084\n"
        "jmpl *0x30308c(, %eax, 4)\n"
        "movl 0x10(%ebp), %ebx\n" /* line 620 | ofs */
        "addl 8(%ebp), %ebx\n" /* b */
        "movl $0, (%esp)\n" /* line 833 */
        "calll Scr_GetEntityRef\n"
        "movl %eax, %edx\n"
        "shrl $0x10, %eax\n" /* line 834 */
        "testw %ax, %ax\n"
        "jne .Lf19f034_0019f12b\n"
        "movzwl %dx, %eax\n" /* line 837 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl 0x195f688, %edx\n"
        "movl %edx, (%ebx)\n" /* line 620 */
        /* } scope */
        ".Lf19f034_0019f084:\n"
        "addl $0x24, %esp\n" /* line 626 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 610 */
        "calll Scr_GetInt\n"
        "movl 8(%ebp), %edx\n" /* b */
        "movl 0x10(%ebp), %ecx\n" /* ofs */
        "movl %eax, (%edx, %ecx)\n"
        "jmp .Lf19f034_0019f084\n"
        "leal -0x14(%ebp), %eax\n" /* line 616 | vec */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl -0x10(%ebp), %eax\n" /* line 617 */
        "movl 8(%ebp), %ecx\n" /* b */
        "movl 0x10(%ebp), %edx\n" /* ofs */
        "movl %eax, (%ecx, %edx)\n"
        "jmp .Lf19f034_0019f084\n"
        "leal -0x14(%ebp), %eax\n" /* line 604 | vec */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl 8(%ebp), %edx\n" /* line 605 | b */
        "addl 0x10(%ebp), %edx\n" /* ofs */
        "movl -0x14(%ebp), %eax\n" /* vec */
        "movl %eax, (%edx)\n"
        "movl -0x10(%ebp), %eax\n" /* line 606 */
        "movl %eax, 4(%edx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 607 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf19f034_0019f084\n"
        "movl $0, (%esp)\n" /* line 601 */
        "calll Scr_GetConstStringIncludeNull\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* b */
        "addl 0x10(%ebp), %eax\n" /* ofs */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "jmp .Lf19f034_0019f084\n"
        "movl $0, (%esp)\n" /* line 613 */
        "calll Scr_GetFloat\n"
        "movl 8(%ebp), %eax\n" /* b */
        "movl 0x10(%ebp), %edx\n" /* ofs */
        "fstps (%eax, %edx)\n"
        "jmp .Lf19f034_0019f084\n"
        ".Lf19f034_0019f12b:\n"
        "movl $0x2b21c8, 4(%esp)\n" /* line 839 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "xorl %edx, %edx\n"
        "movl %edx, (%ebx)\n" /* line 620 */
        "jmp .Lf19f034_0019f084\n"
    );
}

/* line 634 */
__attribute__((naked))
qboolean Scr_SetObjectField(unsigned int classnum, int entnum, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 634 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* classnum */
        "movl 0xc(%ebp), %eax\n" /* entnum */
        "movl 0x10(%ebp), %ecx\n" /* offset */
        "testl %edx, %edx\n" /* line 636 */
        "je .Lf19f148_0019f16c\n"
        "subl $1, %edx\n"
        "je .Lf19f148_0019f1b5\n"
        ".Lf19f148_0019f161:\n"
        "movl $1, %eax\n" /* line 641 */
        ".Lf19f148_0019f166:\n"
        "addl $0x14, %esp\n" /* line 649 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f148_0019f16c:\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 561 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl 0x195f688, %edx\n"
        "movl %ecx, %eax\n" /* line 564 */
        "andl $0xc000, %eax\n"
        "cmpl $0xc000, %eax\n"
        "je .Lf19f148_0019f1c3\n"
        "movl %ecx, %eax\n" /* line 576 */
        "shll $4, %eax\n"
        "leal fields(%eax), %ebx\n" /* f */
        "movl 0xc(%ebx), %eax\n" /* line 578 | f */
        "testl %eax, %eax\n"
        "je .Lf19f148_0019f1e7\n"
        "movl %ecx, 4(%esp)\n" /* line 580 */
        "movl %edx, (%esp)\n"
        "calll *%eax\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 649 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19f148_0019f1b5:\n"
        "movl %ecx, 4(%esp)\n" /* line 641 */
        "movl %eax, (%esp)\n"
        "calll Scr_SetHudElemField\n"
        "jmp .Lf19f148_0019f161\n"
        /* { scope 1 */
        ".Lf19f148_0019f1c3:\n"
        "movl 0x158(%edx), %eax\n" /* line 566 */
        "testl %eax, %eax\n"
        "je .Lf19f148_0019f166\n"
        "andb $0x3f, %ch\n" /* line 569 */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetClientField\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 649 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f148_0019f1e7:\n"
        "movl 4(%ebx), %eax\n" /* line 584 | f */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebx), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Scr_SetGenericField\n"
        "movl $1, %eax\n"
        "jmp .Lf19f148_0019f166\n"
    );
}

/* line 746 */
__attribute__((naked))
my_upsampler Scr_GetObjectField(unsigned int classnum, int entnum, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 746 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* classnum */
        "movl 0xc(%ebp), %eax\n" /* entnum */
        "movl 0x10(%ebp), %ebx\n" /* offset */
        "testl %edx, %edx\n" /* line 748 */
        "je .Lf19f208_0019f221\n"
        "subl $1, %edx\n"
        "je .Lf19f208_0019f27d\n"
        ".Lf19f208_0019f21e:\n"
        "popl %ebx\n" /* line 760 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f208_0019f221:\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 664 */
        "leal (, %eax, 8), %ecx\n"
        "subl %eax, %ecx\n"
        "shll $4, %ecx\n"
        "addl 0x195f688, %ecx\n"
        "movl %ebx, %eax\n" /* line 667 */
        "andl $0xc000, %eax\n"
        "cmpl $0xc000, %eax\n"
        "je .Lf19f208_0019f263\n"
        "shll $4, %ebx\n" /* line 679 */
        "leal fields(%ebx), %eax\n"
        "movl 4(%eax), %edx\n" /* line 680 */
        "movl %edx, 0x10(%ebp)\n" /* offset */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* entnum */
        "movl %ecx, 8(%ebp)\n" /* classnum */
        /* } scope */
        "popl %ebx\n" /* line 760 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_GetGenericField\n" /* line 680 */
        ".Lf19f208_0019f263:\n"
        "movl 0x158(%ecx), %eax\n" /* line 669 */
        "testl %eax, %eax\n"
        "je .Lf19f208_0019f21e\n"
        "andb $0x3f, %bh\n" /* line 672 */
        "movl %ebx, 0xc(%ebp)\n" /* entnum */
        "movl %eax, 8(%ebp)\n" /* classnum */
        /* } scope */
        "popl %ebx\n" /* line 760 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_GetClientField\n" /* line 672 */
        /* } scope */
        ".Lf19f208_0019f27d:\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 754 | offset, entnum */
        "movl %eax, 8(%ebp)\n" /* classnum */
        "popl %ebx\n" /* line 760 */
        "popl %ebp\n"
        "jmp Scr_GetHudElemField\n" /* line 754 */
    );
}

/* line 798 */
__attribute__((naked))
my_upsampler Scr_FreeEntity(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 798 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl fields, %eax\n" /* line 776 */
        "testl %eax, %eax\n"
        "je .Lf19f28a_0019f2d2\n"
        "movl $0x333368, %ebx\n"
        "jmp .Lf19f28a_0019f2ad\n"
        ".Lf19f28a_0019f2a3:\n"
        "movl 8(%ebx), %eax\n"
        "addl $0x10, %ebx\n"
        "testl %eax, %eax\n"
        "je .Lf19f28a_0019f2d2\n"
        ".Lf19f28a_0019f2ad:\n"
        "cmpl $3, (%ebx)\n" /* line 778 */
        "jne .Lf19f28a_0019f2a3\n"
        "movl $0, 4(%esp)\n" /* line 781 */
        "movl 8(%ebp), %eax\n" /* ent */
        "addl -4(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 8(%ebx), %eax\n" /* line 776 */
        "addl $0x10, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf19f28a_0019f2ad\n"
        ".Lf19f28a_0019f2d2:\n"
        "movl 8(%ebp), %esi\n" /* ent */
        "xorl %edi, %edi\n" /* i */
        "movl %esi, %ebx\n"
        "addl $0x218, %ebx\n"
        ".Lf19f28a_0019f2df:\n"
        "movb $0, 0x210(%esi)\n" /* line 787 */
        "movl $0, 4(%esp)\n" /* line 788 */
        "movl %ebx, (%esp)\n"
        "calll Scr_SetString\n"
        "addl $1, %edi\n" /* line 785 | i */
        "addl $2, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $7, %edi\n" /* i */
        "jne .Lf19f28a_0019f2df\n"
        /* } scope */
        "movl $0, 4(%esp)\n" /* line 805 */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_FreeEntityNum\n"
        "addl $0x1c, %esp\n" /* line 806 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 429 */
__attribute__((naked))
my_upsampler G_CallSpawn(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 429 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1: i */
        "leal -0x1c(%ebp), %eax\n" /* line 9 | classname */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2157b8, 8(%esp)\n"
        "movl $0x21c208, 4(%esp)\n" /* "classname" */
        "movl 0x195f6a0, %ebx\n"
        "leal 0x1348(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 438 | classname */
        "testl %eax, %eax\n"
        "je .Lf19f322_0019f48b\n"
        "calll G_GetItemForClassname\n" /* line 444 */
        "movl %eax, -0x30(%ebp)\n" /* item */
        "testl %eax, %eax\n" /* line 445 */
        "je .Lf19f322_0019f3bd\n"
        "calll G_Spawn\n" /* line 447 */
        "movl %eax, %esi\n" /* ent */
        /* { scope 2 */
        "movl 0x134c(%ebx), %edi\n" /* line 295 | i */
        "testl %edi, %edi\n" /* i */
        "jg .Lf19f322_0019f42d\n"
        ".Lf19f322_0019f382:\n"
        "leal 0x138(%esi), %eax\n" /* line 298 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetOrigin\n"
        "leal 0x144(%esi), %eax\n" /* line 299 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetAngle\n"
        /* } scope */
        "movl -0x30(%ebp), %edx\n" /* line 449 | item */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_SpawnItem\n"
        /* } scope */
        ".Lf19f322_0019f3b5:\n"
        "addl $0x4c, %esp\n" /* line 470 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lf19f322_0019f3bd:\n"
        "movl spawns, %eax\n" /* line 454 */
        "testl %eax, %eax\n"
        "je .Lf19f322_0019f3eb\n"
        "movl -0x1c(%ebp), %esi\n" /* line 456 | classname, ent */
        "movl $spawns, %ebx\n" /* s */
        ".Lf19f322_0019f3ce:\n"
        "movl %esi, 4(%esp)\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf19f322_0019f49f\n"
        "addl $8, %ebx\n" /* line 454 | s */
        "movl (%ebx), %eax\n" /* s */
        "testl %eax, %eax\n"
        "jne .Lf19f322_0019f3ce\n"
        ".Lf19f322_0019f3eb:\n"
        "calll G_Spawn\n" /* line 468 */
        "movl %eax, %esi\n" /* ent */
        /* { scope 2 */
        "movl 0x195f6a0, %eax\n" /* line 295 */
        "movl 0x134c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf19f322_0019f45b\n"
        ".Lf19f322_0019f401:\n"
        "leal 0x138(%esi), %eax\n" /* line 298 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetOrigin\n"
        "leal 0x144(%esi), %eax\n" /* line 299 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetAngle\n"
        /* } scope */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 470 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        /* { scope 2 */
        ".Lf19f322_0019f42d:\n"
        "xorl %edi, %edi\n" /* line 295 | i */
        "movl %ebx, -0x34(%ebp)\n"
        ".Lf19f322_0019f432:\n"
        "movl 0x1354(%ebx), %edx\n" /* line 296 */
        "movl 0x1350(%ebx), %eax\n"
        "movl %esi, %ecx\n"
        "calll G_ParseEntityField\n"
        "addl $1, %edi\n" /* line 295 | i */
        "addl $8, %ebx\n"
        "movl -0x34(%ebp), %eax\n"
        "cmpl 0x134c(%eax), %edi\n" /* i */
        "jl .Lf19f322_0019f432\n"
        "jmp .Lf19f322_0019f382\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19f322_0019f45b:\n"
        "xorl %edi, %edi\n" /* i */
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, %ebx\n"
        ".Lf19f322_0019f462:\n"
        "movl 0x1354(%ebx), %edx\n" /* line 296 */
        "movl 0x1350(%ebx), %eax\n"
        "movl %esi, %ecx\n"
        "calll G_ParseEntityField\n"
        "addl $1, %edi\n" /* line 295 | i */
        "addl $8, %ebx\n"
        "movl -0x3c(%ebp), %eax\n"
        "cmpl 0x134c(%eax), %edi\n" /* i */
        "jl .Lf19f322_0019f462\n"
        "jmp .Lf19f322_0019f401\n"
        /* } scope */
        ".Lf19f322_0019f48b:\n"
        "movl $0x2b34ec, (%esp)\n" /* line 440 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 470 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lf19f322_0019f49f:\n"
        "movl 0x195f6cc, %eax\n" /* line 458 */
        "cmpl %eax, 4(%ebx)\n" /* s */
        "je .Lf19f322_0019f3b5\n"
        "calll G_Spawn\n" /* line 460 */
        "movl %eax, %edi\n" /* i */
        /* { scope 2 */
        "movl 0x195f6a0, %eax\n" /* line 295 */
        "movl 0x134c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf19f322_0019f4f2\n"
        ".Lf19f322_0019f4c3:\n"
        "leal 0x138(%edi), %eax\n" /* line 298 | i */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* i */
        "calll G_SetOrigin\n"
        "leal 0x144(%edi), %eax\n" /* line 299 | i */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* i */
        "calll G_SetAngle\n"
        /* } scope */
        "movl %edi, (%esp)\n" /* line 462 | i */
        "calll *4(%ebx)\n" /* s */
        "jmp .Lf19f322_0019f3b5\n"
        /* { scope 2 */
        ".Lf19f322_0019f4f2:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 295 | i */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, %esi\n"
        ".Lf19f322_0019f4fe:\n"
        "movl 0x1354(%esi), %edx\n" /* line 296 */
        "movl 0x1350(%esi), %eax\n"
        "movl %edi, %ecx\n" /* i */
        "calll G_ParseEntityField\n"
        "addl $1, -0x2c(%ebp)\n" /* line 295 | i */
        "addl $8, %esi\n"
        "movl -0x2c(%ebp), %edx\n" /* i */
        "movl -0x38(%ebp), %eax\n"
        "cmpl 0x134c(%eax), %edx\n"
        "jl .Lf19f322_0019f4fe\n"
        "jmp .Lf19f322_0019f4c3\n"
    );
}

/* line 1115 */
__attribute__((naked))
my_upsampler G_SpawnEntitiesFromString(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1115 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195f6a0, %eax\n" /* line 1120 */
        "addl $0x1348, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ParseSpawnVars\n"
        "testl %eax, %eax\n"
        "je .Lf19f528_0019f56f\n"
        ".Lf19f528_0019f545:\n"
        "calll SP_worldspawn\n" /* line 1123 */
        "movl 0x195f6a0, %ebx\n"
        "addl $0x1348, %ebx\n"
        "jmp .Lf19f528_0019f55d\n"
        ".Lf19f528_0019f558:\n"
        "calll G_CallSpawn\n" /* line 1127 */
        ".Lf19f528_0019f55d:\n"
        "movl %ebx, (%esp)\n" /* line 1126 */
        "calll G_ParseSpawnVars\n"
        "testl %eax, %eax\n"
        "jne .Lf19f528_0019f558\n"
        "addl $0x14, %esp\n" /* line 1128 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19f528_0019f56f:\n"
        "movl $0x2b350c, 4(%esp)\n" /* line 1121 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19f528_0019f545\n"
    );
}

