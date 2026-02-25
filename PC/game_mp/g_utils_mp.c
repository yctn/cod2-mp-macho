/* ASM dump from: g_utils_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_utils_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 */

static struct XModel * cached_models[256]; /* 0xfdf380 */

int G_FindConfigstringIndex(const char *name, int start, int max, qboolean create, const char *errormsg);
int G_LocalizedStringIndex(const char *string);
int G_ShaderIndex(const char *name);
int G_ModelIndex(const char *name);
const char * G_ModelName(int index);
int G_TagIndex(const char *name);
int G_EffectIndex(const char *name);
int G_ShellShockIndex(const char *name);
SoundAlias G_SoundAliasIndex(const char *name);
unsigned char G_SetModel(gentity_t *ent, const char *modelName);
unsigned char G_SafeDObjFree(gentity_t *ent);
qboolean G_DObjUpdateServerTime(gentity_t *ent, qboolean bNotify);
unsigned char G_DObjCalcPose(gentity_t *ent);
unsigned char G_DObjCalcBone(gentity_t *ent, int boneIndex);
DObjAnimMat_s * G_DObjGetLocalTagMatrix(gentity_t *ent, unsigned int tagName);
unsigned char G_InitGentity(gentity_t *e);
unsigned char G_PrintEntities(void);
int G_GetPlayerCorpseIndex(gentity_t *ent);
unsigned char G_FreeEntityDelay(gentity_t *ed);
unsigned char G_AddPredictableEvent(gentity_t *ent, int event, int eventParm);
unsigned char G_AddEvent(gentity_t *ent, int event, int eventParm);
unsigned char G_SetConstString(scr_string_t *to, const char *from);
unsigned char G_SetAngle(gentity_t *ent, const vec_t *angle);
qboolean G_XModelBad(int index);
unsigned char G_SetOrigin(gentity_t *ent, const vec_t *origin);
unsigned char G_PlaySoundAlias(gentity_t *ent, int index);
unsigned char G_OverrideModel(int modelindex, const char *defaultModelName);
int G_AnimScriptSound(int client, snd_alias_list_t *aliasList);
unsigned char G_CalcTagParentAxis(gentity_t *ent, vec3_t *parentAxis);
unsigned char G_SetFixedLink(gentity_t *ent, int eAngles);
unsigned char G_CalcTagAxis(gentity_t *ent, qboolean bAnglesOnly);
unsigned char G_EntUnlink(gentity_t *ent);
static qboolean G_EntLinkToInternal(gentity_t *parent);
qboolean G_EntLinkToWithOffset(gentity_t *ent, gentity_t *parent, unsigned int tagName, const vec_t *originOffset, const vec_t *anglesOffset);
qboolean G_EntLinkTo(gentity_t *ent, gentity_t *parent, unsigned int tagName);
unsigned char G_GeneralLink(gentity_t *ent);
unsigned char G_FreeEntity(gentity_t *ed);
int G_GetFreePlayerCorpseIndex(void);
unsigned char G_DObjUpdate(gentity_t *ent);
unsigned char G_EntDetachAll(gentity_t *ent);
qboolean G_EntDetach(gentity_t *ent, const char *modelName, unsigned int tagName);
qboolean G_EntAttach(gentity_t *ent, const char *modelName, unsigned int tagName, qboolean ignoreCollision);
gentity_t * G_Spawn(void);
gentity_t * G_TempEntity(const vec_t *origin, int event);
gentity_t * G_SpawnPlayerClone(void);
qboolean G_DObjGetWorldTagMatrix(gentity_t *ent, unsigned int tagName, vec3_t *tagMat);
qboolean G_DObjGetWorldTagPos(gentity_t *ent, unsigned int tagName, vec_t *pos);

/* line 44 */
__attribute__((naked))
int G_FindConfigstringIndex(const char *name, int start, int max, qboolean create, const char *errormsg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 44 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl 0x10(%ebp), %edi\n" /* max */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 49 | name */
        "je .Lf1b33f0_001b344b\n"
        "cmpb $0, (%esi)\n" /* name */
        "je .Lf1b33f0_001b344b\n"
        "cmpl $1, %edi\n" /* line 54 | max */
        "jg .Lf1b33f0_001b3476\n"
        "movl $1, %ebx\n" /* i */
        ".Lf1b33f0_001b3412:\n"
        "movl 0x14(%ebp), %edx\n" /* line 67 | create */
        "testl %edx, %edx\n"
        "jne .Lf1b33f0_001b3457\n"
        "movl 0x18(%ebp), %eax\n" /* line 69 | errormsg */
        "testl %eax, %eax\n"
        "je .Lf1b33f0_001b344b\n"
        "movl %esi, 8(%esp)\n" /* line 70 | name */
        "movl 0x18(%ebp), %eax\n" /* errormsg */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b522c, (%esp)\n" /* "%s "%s" not precached" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "xorl %ebx, %ebx\n" /* i */
        /* } scope */
        ".Lf1b33f0_001b3441:\n"
        "movl %ebx, %eax\n" /* line 80 | i */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b33f0_001b344b:\n"
        "xorl %ebx, %ebx\n" /* line 79 | i */
        /* } scope */
        "movl %ebx, %eax\n" /* line 80 | i */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b33f0_001b3457:\n"
        "cmpl %ebx, %edi\n" /* line 74 | i, max */
        "je .Lf1b33f0_001b34aa\n"
        ".Lf1b33f0_001b345b:\n"
        "movl %esi, 4(%esp)\n" /* line 77 | name */
        "movl 0xc(%ebp), %eax\n" /* start */
        "addl %ebx, %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 80 | i */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b33f0_001b3476:\n"
        "movl $1, %ebx\n" /* line 49 | i */
        ".Lf1b33f0_001b347b:\n"
        "movl 0xc(%ebp), %edx\n" /* line 56 | start */
        "leal (%ebx, %edx), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstringConst\n"
        "cmpb $0, (%eax)\n" /* line 57 */
        "je .Lf1b33f0_001b3412\n"
        "movl %esi, 4(%esp)\n" /* line 61 | name */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1b33f0_001b3441\n"
        "addl $1, %ebx\n" /* line 54 | i */
        "cmpl %ebx, %edi\n" /* i, max */
        "jne .Lf1b33f0_001b347b\n"
        "jmp .Lf1b33f0_001b3412\n"
        ".Lf1b33f0_001b34aa:\n"
        "movl %esi, 8(%esp)\n" /* line 75 | name */
        "movl 0xc(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "movl $0x2b5244, (%esp)\n" /* "G_FindConfigstringIndex: overflow (%d): '%s'" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1b33f0_001b345b\n"
    );
}

/* line 88 */
__attribute__((naked))
int G_LocalizedStringIndex(const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %edx\n" /* string */
        "cmpb $0, (%edx)\n" /* line 91 */
        "jne .Lf1b34d4_001b34e6\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 94 */
        "retl\n"
        ".Lf1b34d4_001b34e6:\n"
        "movl $0x21d258, 0x10(%esp)\n" /* line 93 */
        "movl 0x195f6a0, %eax\n"
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x100, 8(%esp)\n"
        "movl $0x51e, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll G_FindConfigstringIndex\n"
        "leave\n" /* line 94 */
        "retl\n"
    );
}

/* line 102 */
__attribute__((naked))
int G_ShaderIndex(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x64, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 109 | name */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %ebx\n" /* shaderName */
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "movl %ebx, (%esp)\n" /* line 110 */
        "calll I_strlwr\n"
        "movl $0x21a4d4, 0x10(%esp)\n" /* line 112 */
        "movl 0x195f6a0, %eax\n"
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x80, 8(%esp)\n"
        "movl $0x61e, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_FindConfigstringIndex\n"
        /* } scope */
        "addl $0x64, %esp\n" /* line 113 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 121 */
__attribute__((naked))
int G_ModelIndex(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 121 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "cmpb $0, (%edi)\n" /* line 130 | name */
        "jne .Lf1b3568_001b3585\n"
        "xorl %esi, %esi\n" /* i */
        /* } scope */
        ".Lf1b3568_001b357b:\n"
        "movl %esi, %eax\n" /* line 168 | i */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b3568_001b3585:\n"
        "movl $1, %esi\n" /* line 130 | i */
        "jmp .Lf1b3568_001b35a7\n"
        ".Lf1b3568_001b358c:\n"
        "movl %edi, 4(%esp)\n" /* line 143 | name */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1b3568_001b357b\n"
        "addl $1, %esi\n" /* line 136 | i */
        "cmpl $0x100, %esi\n" /* i */
        "je .Lf1b3568_001b3623\n"
        ".Lf1b3568_001b35a7:\n"
        "leal 0x14e(%esi), %ebx\n" /* line 130 | i */
        "movl %ebx, (%esp)\n" /* line 138 */
        "calll SV_GetConfigstringConst\n"
        "cmpb $0, (%eax)\n" /* line 139 */
        "jne .Lf1b3568_001b358c\n"
        ".Lf1b3568_001b35ba:\n"
        "movl 0x195f6a0, %eax\n" /* line 151 */
        "movl 0x1c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1b3568_001b35f3\n"
        ".Lf1b3568_001b35c6:\n"
        "cmpl $0x100, %esi\n" /* line 157 | i */
        "je .Lf1b3568_001b360d\n"
        ".Lf1b3568_001b35ce:\n"
        "movl %edi, (%esp)\n" /* line 162 | name */
        "calll SV_XModelGet\n"
        "movl %eax, cached_models(, %esi, 4)\n"
        "movl %edi, 4(%esp)\n" /* line 164 | name */
        "movl %ebx, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 168 | i */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b3568_001b35f3:\n"
        "movl %edi, 4(%esp)\n" /* line 154 | name */
        "movl $0x2b5274, (%esp)\n" /* "model '%s' not precached" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf1b3568_001b35c6\n"
        ".Lf1b3568_001b360d:\n"
        "movl $0x2b5290, 4(%esp)\n" /* line 159 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1b3568_001b35ce\n"
        ".Lf1b3568_001b3623:\n"
        "movl $0x24e, %ebx\n" /* line 136 */
        "jmp .Lf1b3568_001b35ba\n"
    );
}

/* line 186 */
__attribute__((naked))
const char * G_ModelName(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 186 */
        "movl %esp, %ebp\n"
        "addl $0x14e, 8(%ebp)\n" /* line 189 | index */
        "popl %ebp\n" /* line 190 */
        "jmp SV_GetConfigstringConst\n" /* line 189 */
    );
}

/* line 193 */
__attribute__((naked))
int G_TagIndex(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 193 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0, 0x10(%esp)\n" /* line 196 */
        "movl $1, 0xc(%esp)\n"
        "movl $0x20, 8(%esp)\n"
        "movl $0x6e, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll G_FindConfigstringIndex\n"
        "leave\n" /* line 197 */
        "retl\n"
    );
}

/* line 200 */
__attribute__((naked))
int G_EffectIndex(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 200 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0x2b52a8, 0x10(%esp)\n" /* line 203 */
        "movl 0x195f6a0, %eax\n"
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x40, 8(%esp)\n"
        "movl $0x34e, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll G_FindConfigstringIndex\n"
        "leave\n" /* line 204 */
        "retl\n"
    );
}

/* line 207 */
__attribute__((naked))
int G_ShellShockIndex(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 207 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0, 0x10(%esp)\n" /* line 210 */
        "movl $1, 0xc(%esp)\n"
        "movl $0x10, 8(%esp)\n"
        "movl $0x48e, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll G_FindConfigstringIndex\n"
        "leave\n" /* line 211 */
        "retl\n"
    );
}

/* line 214 */
__attribute__((naked))
SoundAlias G_SoundAliasIndex(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 214 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0, 0x10(%esp)\n" /* line 218 */
        "movl $1, 0xc(%esp)\n"
        "movl $0x100, 8(%esp)\n"
        "movl $0x24e, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll G_FindConfigstringIndex\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 219 */
        "retl\n"
    );
}

/* line 305 */
__attribute__((naked))
unsigned char G_SetModel(gentity_t *ent, const char *modelName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 305 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl 0xc(%ebp), %eax\n" /* modelName */
        /* { scope 1 */
        "cmpb $0, (%eax)\n" /* line 309 */
        "jne .Lf1b3710_001b372f\n"
        "movb $0, 0x164(%ebx)\n" /* line 311 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 317 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b3710_001b372f:\n"
        "movl %eax, (%esp)\n" /* line 314 */
        "calll G_ModelIndex\n"
        "movb %al, 0x164(%ebx)\n" /* line 316 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 317 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 824 */
__attribute__((naked))
unsigned char G_SafeDObjFree(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 824 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 826 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* ent */
        "popl %ebp\n" /* line 827 */
        "jmp Com_SafeServerDObjFree\n" /* line 826 */
    );
}

/* line 835 */
__attribute__((naked))
qboolean G_DObjUpdateServerTime(gentity_t *ent, qboolean bNotify)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 835 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 837 | bNotify */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f6a0, %eax\n"
        "cvtsi2ssl 0x1f4(%eax), %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll SV_DObjUpdateServerTime\n"
        "leave\n" /* line 838 */
        "retl\n"
    );
}

/* line 846 */
__attribute__((naked))
unsigned char G_DObjCalcPose(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 846 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1 */
        "leal -0x18(%ebp), %esi\n" /* line 851 | partBits */
        "movl $0xffffffff, -0x18(%ebp)\n" /* partBits */
        "movl $0xffffffff, -0x14(%ebp)\n"
        "movl $0xffffffff, -0x10(%ebp)\n"
        "movl $0xffffffff, -0xc(%ebp)\n"
        "movl %esi, 4(%esp)\n" /* line 852 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll SV_DObjCreateSkelForBones\n"
        "testl %eax, %eax\n"
        "je .Lf1b378e_001b37cf\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 859 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b378e_001b37cf:\n"
        "movl %esi, 4(%esp)\n" /* line 854 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll SV_DObjCalcAnim\n"
        "movzbl 0x166(%ebx), %eax\n" /* line 855 | ent */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 0x1c(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 856 */
        "je .Lf1b378e_001b37fe\n"
        "movl %esi, 4(%esp)\n" /* line 857 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll *%eax\n"
        ".Lf1b378e_001b37fe:\n"
        "movl %esi, 4(%esp)\n" /* line 858 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll SV_DObjCalcSkel\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 859 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 867 */
__attribute__((naked))
unsigned char G_DObjCalcBone(gentity_t *ent, int boneIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 867 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl 0xc(%ebp), %esi\n" /* boneIndex */
        /* { scope 1 */
        "movl %esi, 4(%esp)\n" /* line 872 | boneIndex */
        "movl %ebx, (%esp)\n" /* ent */
        "calll SV_DObjCreateSkelForBone\n"
        "testl %eax, %eax\n"
        "je .Lf1b3812_001b3839\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 880 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b3812_001b3839:\n"
        "leal -0x28(%ebp), %edi\n" /* line 874 | partBits */
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* boneIndex */
        "movl %ebx, (%esp)\n" /* ent */
        "calll SV_DObjGetHierarchyBits\n"
        "movl %edi, 4(%esp)\n" /* line 875 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll SV_DObjCalcAnim\n"
        "movzbl 0x166(%ebx), %eax\n" /* line 876 | ent */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 0x1c(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 877 */
        "je .Lf1b3812_001b387b\n"
        "movl %edi, 4(%esp)\n" /* line 878 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll *%eax\n"
        ".Lf1b3812_001b387b:\n"
        "movl %edi, 4(%esp)\n" /* line 879 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll SV_DObjCalcSkel\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 880 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 888 */
__attribute__((naked))
DObjAnimMat_s * G_DObjGetLocalTagMatrix(gentity_t *ent, unsigned int tagName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 888 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 893 | tagName */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll SV_DObjGetBoneIndex\n"
        "movl %eax, %ebx\n" /* boneIndex */
        "testl %eax, %eax\n" /* line 894 */
        "js .Lf1b3890_001b38d0\n"
        "movl %eax, 4(%esp)\n" /* line 898 */
        "movl %esi, (%esp)\n" /* ent */
        "calll G_DObjCalcBone\n"
        "movl %esi, (%esp)\n" /* line 901 | ent */
        "calll SV_DObjGetMatrixArray\n"
        "shll $5, %ebx\n" /* line 902 | boneIndex */
        "addl %ebx, %eax\n" /* boneIndex */
        /* } scope */
        "addl $0x10, %esp\n" /* line 903 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b3890_001b38d0:\n"
        "xorl %eax, %eax\n" /* line 894 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 903 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1070 */
__attribute__((naked))
unsigned char G_InitGentity(gentity_t *e)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1070 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* e */
        "movl $0, 0x22c(%ebx)\n" /* line 1072 | e */
        "movb $1, 0xfc(%ebx)\n" /* line 1073 | e */
        "movl 0x195f5bc, %eax\n" /* line 1074 */
        "movzwl 0x2a(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x168(%ebx), %eax\n" /* e */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl %ebx, %eax\n" /* line 1075 | e */
        "subl 0x195f688, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, (%ebx)\n" /* e */
        "movl $0x3ff, 0x150(%ebx)\n" /* line 1076 | e */
        "movl $0, 0x178(%ebx)\n" /* line 1077 | e */
        "movl $0, 0x17c(%ebx)\n" /* line 1078 | e */
        "addl $0x14, %esp\n" /* line 1079 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1082 */
__attribute__((naked))
unsigned char G_PrintEntities(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1082 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 1086 */
        "movl 0xc(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf1b3948_001b39f8\n"
        "xorl %esi, %esi\n" /* entityIndex */
        "movl 0x195f688, %ebx\n"
        "movl %eax, %edi\n"
        "jmp .Lf1b3948_001b39b5\n"
        ".Lf1b3948_001b396d:\n"
        "movl $0x2157b8, %eax\n" /* line 1087 */
        ".Lf1b3948_001b3972:\n"
        "movsd -0x30(%ebp), %xmm0\n"
        "movsd %xmm0, 0x1c(%esp)\n"
        "movsd -0x28(%ebp), %xmm0\n"
        "movsd %xmm0, 0x14(%esp)\n"
        "movsd -0x20(%ebp), %xmm0\n"
        "movsd %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* entityIndex */
        "movl $0x2b52b0, (%esp)\n" /* "%4i: '%s', origin: %f %f %f
" */
        "calll Com_Printf\n"
        "addl $1, %esi\n" /* line 1086 | entityIndex */
        "addl $0x230, %ebx\n"
        "cmpl 0xc(%edi), %esi\n" /* entityIndex */
        "jge .Lf1b3948_001b39f8\n"
        ".Lf1b3948_001b39b5:\n"
        "cvtss2sd 0x140(%ebx), %xmm0\n" /* line 1087 */
        "movsd %xmm0, -0x30(%ebp)\n"
        "cvtss2sd 0x13c(%ebx), %xmm0\n"
        "movsd %xmm0, -0x28(%ebp)\n"
        "cvtss2sd 0x138(%ebx), %xmm0\n"
        "movsd %xmm0, -0x20(%ebp)\n"
        "movzwl 0x168(%ebx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf1b3948_001b396d\n"
        "movzwl %ax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "jmp .Lf1b3948_001b3972\n"
        /* } scope */
        ".Lf1b3948_001b39f8:\n"
        "addl $0x5c, %esp\n" /* line 1088 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1248 */
__attribute__((naked))
int G_GetPlayerCorpseIndex(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1248 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1253 | ent */
        "movl (%eax), %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0x195f6d0, %edx\n"
        ".Lf1b3a00_001b3a10:\n"
        "cmpl 0x10bc(%edx), %ecx\n" /* line 1256 */
        "je .Lf1b3a00_001b3a28\n"
        "addl $1, %eax\n" /* line 1254 */
        "addl $0x4c8, %edx\n"
        "cmpl $8, %eax\n"
        "jne .Lf1b3a00_001b3a10\n"
        "xorb %al, %al\n"
        /* } scope */
        ".Lf1b3a00_001b3a28:\n"
        "popl %ebp\n" /* line 1262 */
        "retl\n"
    );
}

/* line 1392 */
__attribute__((naked))
unsigned char G_FreeEntityDelay(gentity_t *ed)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1392 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $0, 8(%esp)\n" /* line 1397 */
        "movl 0x195f6d0, %eax\n"
        "movl 0x10ac(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ed */
        "movl %eax, (%esp)\n"
        "calll Scr_ExecEntThread\n"
        "movzwl %ax, %eax\n" /* line 1398 */
        "movl %eax, 8(%ebp)\n" /* ed */
        /* } scope */
        "leave\n" /* line 1399 */
        /* { scope 1 */
        "jmp Scr_FreeThread\n" /* line 1398 */
    );
}

/* line 1492 */
__attribute__((naked))
unsigned char G_AddPredictableEvent(gentity_t *ent, int event, int eventParm)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1492 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %ecx\n" /* event */
        "movl 0x10(%ebp), %edx\n" /* eventParm */
        "movl 8(%ebp), %eax\n" /* line 1494 | ent */
        "movl 0x158(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1b3a5e_001b3a83\n"
        "movl %eax, 0x10(%ebp)\n" /* line 1498 | eventParm */
        "movl %edx, 0xc(%ebp)\n" /* event */
        "movl %ecx, 8(%ebp)\n" /* ent */
        "popl %ebp\n" /* line 1499 */
        "jmp BG_AddPredictableEventToPlayerstate\n" /* line 1498 */
        ".Lf1b3a5e_001b3a83:\n"
        "popl %ebp\n" /* line 1499 */
        "retl\n"
    );
}

/* line 1509 */
__attribute__((naked))
unsigned char G_AddEvent(gentity_t *ent, int event, int eventParm)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1509 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl 0xc(%ebp), %ebx\n" /* event */
        "movl 0x10(%ebp), %esi\n" /* eventParm */
        "movl 0x158(%ecx), %edx\n" /* line 1517 */
        "testl %edx, %edx\n"
        "je .Lf1b3a86_001b3af2\n"
        "movl 0xa4(%edx), %eax\n" /* line 1519 */
        "andl $3, %eax\n"
        "movl %ebx, 0xa8(%edx, %eax, 4)\n" /* event */
        "movl 0x158(%ecx), %edx\n" /* line 1520 */
        "movl 0xa4(%edx), %eax\n"
        "andl $3, %eax\n"
        "movl %esi, 0xb8(%edx, %eax, 4)\n" /* eventParm */
        "movl 0x158(%ecx), %eax\n" /* line 1521 */
        "addl $1, 0xa4(%eax)\n"
        "movl 0x195f6a0, %eax\n" /* line 1529 */
        "movl 0x1ec(%eax), %edx\n"
        "movl %edx, 0x178(%ecx)\n"
        "movl 0x1ec(%eax), %eax\n" /* line 1530 */
        "movl %eax, 0x154(%ecx)\n"
        "popl %ebx\n" /* line 1531 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b3a86_001b3af2:\n"
        "movl 0xa4(%ecx), %eax\n" /* line 1525 */
        "movl %eax, %edx\n"
        "andl $3, %edx\n"
        "movl %ebx, 0xa8(%ecx, %edx, 4)\n" /* event */
        "movl %esi, 0xb8(%ecx, %edx, 4)\n" /* line 1526 | eventParm */
        "addl $1, %eax\n" /* line 1527 */
        "movl %eax, 0xa4(%ecx)\n"
        "movl 0x195f6a0, %eax\n" /* line 1529 */
        "movl 0x1ec(%eax), %edx\n"
        "movl %edx, 0x178(%ecx)\n"
        "movl 0x1ec(%eax), %eax\n" /* line 1530 */
        "movl %eax, 0x154(%ecx)\n"
        "popl %ebx\n" /* line 1531 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1673 */
__attribute__((naked))
unsigned char G_SetConstString(scr_string_t *to, const char *from)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1673 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* to */
        "movl $0, 4(%esp)\n" /* line 1675 */
        "movl %ebx, (%esp)\n" /* to */
        "calll Scr_SetString\n"
        "movl $0, 4(%esp)\n" /* line 1676 */
        "movl 0xc(%ebp), %eax\n" /* from */
        "movl %eax, (%esp)\n"
        "calll SL_GetString\n"
        "movw %ax, (%ebx)\n" /* to */
        "addl $0x14, %esp\n" /* line 1677 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1617 */
__attribute__((naked))
unsigned char G_SetAngle(gentity_t *ent, const vec_t *angle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1617 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0xc(%ebp), %ebx\n" /* angle */
        "leal 0x3c(%edx), %ecx\n" /* line 1620 | to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x3c(%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0, 0x30(%edx)\n" /* line 1621 */
        "movl $0, 0x34(%edx)\n" /* line 1622 */
        "movl $0, 0x38(%edx)\n" /* line 1623 */
        "leal 0x48(%edx), %ecx\n" /* line 1624 | v */
        /* { scope 1 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x48(%edx)\n"
        "movl %eax, 4(%ecx)\n" /* line 184 */
        "movl %eax, 8(%ecx)\n" /* line 185 */
        /* } scope */
        "leal 0x144(%edx), %ecx\n" /* line 1626 | to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x144(%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "popl %ebx\n" /* line 1627 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 179 */
__attribute__((naked))
qboolean G_XModelBad(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 179 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 182 | index */
        "movl cached_models(, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* index */
        "popl %ebp\n" /* line 183 */
        "jmp XModelBad\n" /* line 182 */
    );
}

/* line 1600 */
__attribute__((naked))
unsigned char G_SetOrigin(gentity_t *ent, const vec_t *origin)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1600 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0xc(%ebp), %ebx\n" /* origin */
        "leal 0x18(%edx), %ecx\n" /* line 1602 | to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x18(%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0, 0xc(%edx)\n" /* line 1603 */
        "movl $0, 0x10(%edx)\n" /* line 1604 */
        "movl $0, 0x14(%edx)\n" /* line 1605 */
        "leal 0x24(%edx), %ecx\n" /* line 1606 | v */
        /* { scope 1 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x24(%edx)\n"
        "movl %eax, 4(%ecx)\n" /* line 184 */
        "movl %eax, 8(%ecx)\n" /* line 185 */
        /* } scope */
        "leal 0x138(%edx), %ecx\n" /* line 1608 | to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x138(%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "popl %ebx\n" /* line 1609 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1556 */
__attribute__((naked))
unsigned char G_PlaySoundAlias(gentity_t *ent, int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1556 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "movzbl 0xc(%ebp), %eax\n" /* index */
        "testb %al, %al\n" /* line 1560 */
        "je .Lf1b3c40_001b3cb0\n"
        "movzbl %al, %ebx\n" /* line 1561 | eventParm */
        /* { scope 1 */
        "movl 0x158(%ecx), %edx\n" /* line 1517 */
        "testl %edx, %edx\n"
        "je .Lf1b3c40_001b3cb3\n"
        "movl 0xa4(%edx), %eax\n" /* line 1519 */
        "andl $3, %eax\n"
        "movl $0xb3, 0xa8(%edx, %eax, 4)\n"
        "movl 0x158(%ecx), %edx\n" /* line 1520 */
        "movl 0xa4(%edx), %eax\n"
        "andl $3, %eax\n"
        "movl %ebx, 0xb8(%edx, %eax, 4)\n"
        "movl 0x158(%ecx), %eax\n" /* line 1521 */
        "addl $1, 0xa4(%eax)\n"
        ".Lf1b3c40_001b3c93:\n"
        "movl 0x195f6a0, %eax\n" /* line 1529 */
        "movl 0x1ec(%eax), %edx\n"
        "movl %edx, 0x178(%ecx)\n"
        "movl 0x1ec(%eax), %eax\n" /* line 1530 */
        "movl %eax, 0x154(%ecx)\n"
        /* } scope */
        ".Lf1b3c40_001b3cb0:\n"
        "popl %ebx\n" /* line 1562 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b3c40_001b3cb3:\n"
        "movl 0xa4(%ecx), %eax\n" /* line 1525 */
        "movl %eax, %edx\n"
        "andl $3, %edx\n"
        "movl $0xb3, 0xa8(%ecx, %edx, 4)\n"
        "movl %ebx, 0xb8(%ecx, %edx, 4)\n" /* line 1526 */
        "addl $1, %eax\n" /* line 1527 */
        "movl %eax, 0xa4(%ecx)\n"
        "jmp .Lf1b3c40_001b3c93\n"
    );
}

/* line 325 */
__attribute__((naked))
unsigned char G_OverrideModel(int modelindex, const char *defaultModelName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 325 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* modelindex */
        /* { scope 1 */
        "leal 0x14e(%ebx), %eax\n" /* line 189 */
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstringConst\n"
        "movl %eax, %esi\n"
        "movl 0xc(%ebp), %eax\n" /* line 338 | defaultModelName */
        "movl %eax, (%esp)\n"
        "calll SV_XModelGet\n"
        "movl %eax, cached_models(, %ebx, 4)\n" /* line 339 */
        "movl %eax, 8(%esp)\n" /* line 340 */
        "leal 7(%esi), %eax\n" /* modelName */
        "movl %eax, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll Hunk_OverrideDataForFile\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 346 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1584 */
__attribute__((naked))
int G_AnimScriptSound(int client, snd_alias_list_t *aliasList)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1584 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* client */
        "movl $0, 0x10(%esp)\n" /* line 218 */
        "movl $1, 0xc(%esp)\n"
        "movl $0x100, 8(%esp)\n"
        "movl $0x24e, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* aliasList */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_FindConfigstringIndex\n"
        "leal (%ebx, %ebx, 4), %ebx\n" /* line 1586 | client */
        "leal (, %ebx, 8), %ecx\n"
        "subl %ebx, %ecx\n" /* client */
        "shll $4, %ecx\n"
        "addl 0x195f688, %ecx\n"
        /* { scope 1 */
        "testb %al, %al\n" /* line 1560 */
        "je .Lf1b3d28_001b3dd3\n"
        "movzbl %al, %ebx\n" /* line 1561 | eventParm */
        /* { scope 2 */
        "movl 0x158(%ecx), %edx\n" /* line 1517 */
        "testl %edx, %edx\n"
        "je .Lf1b3d28_001b3ddb\n"
        "movl 0xa4(%edx), %eax\n" /* line 1519 */
        "andl $3, %eax\n"
        "movl $0xb3, 0xa8(%edx, %eax, 4)\n"
        "movl 0x158(%ecx), %edx\n" /* line 1520 */
        "movl 0xa4(%edx), %eax\n"
        "andl $3, %eax\n"
        "movl %ebx, 0xb8(%edx, %eax, 4)\n"
        "movl 0x158(%ecx), %eax\n" /* line 1521 */
        "addl $1, 0xa4(%eax)\n"
        ".Lf1b3d28_001b3dbc:\n"
        "movl 0x195f6a0, %eax\n" /* line 1529 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x178(%ecx)\n"
        "movl %eax, 0x154(%ecx)\n" /* line 1530 */
        /* } scope */
        /* } scope */
        ".Lf1b3d28_001b3dd3:\n"
        "xorl %eax, %eax\n" /* line 1588 */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b3d28_001b3ddb:\n"
        "movl 0xa4(%ecx), %eax\n" /* line 1525 */
        "movl %eax, %edx\n"
        "andl $3, %edx\n"
        "movl $0xb3, 0xa8(%ecx, %edx, 4)\n"
        "movl %ebx, 0xb8(%ecx, %edx, 4)\n" /* line 1526 */
        "addl $1, %eax\n" /* line 1527 */
        "movl %eax, 0xa4(%ecx)\n"
        "jmp .Lf1b3d28_001b3dbc\n"
    );
}

/* line 674 */
__attribute__((naked))
unsigned char G_CalcTagParentAxis(gentity_t *ent, vec3_t *parentAxis)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 674 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1: xx, xz, yy, zw */
        "movl 8(%ebp), %eax\n" /* line 682 | ent */
        "movl 0x208(%eax), %edi\n" /* tagInfo */
        "movl (%edi), %esi\n" /* line 684 | tagInfo, mat */
        "movl 0xc(%edi), %eax\n" /* line 687 | tagInfo */
        "testl %eax, %eax\n"
        "js .Lf1b3e04_001b3fb9\n"
        "leal -0x6c(%ebp), %ebx\n" /* line 689 | tempAxis */
        "movl %ebx, 4(%esp)\n"
        "leal 0x144(%esi), %eax\n" /* mat */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x138(%esi), %edx\n" /* mat */
        /* { scope 2 */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x40(%ebp)\n"
        /* } scope */
        "movl 0xc(%edi), %eax\n" /* line 693 | tagInfo */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* mat */
        "calll G_DObjCalcBone\n"
        "movl %esi, (%esp)\n" /* line 696 | mat */
        "calll SV_DObjGetMatrixArray\n"
        "movl %eax, %edx\n"
        "movl 0xc(%edi), %eax\n" /* tagInfo */
        "shll $5, %eax\n"
        "leal (%edx, %eax), %esi\n" /* mat */
        /* { scope 2 */
        "movss 0x1c(%esi), %xmm1\n" /* line 306 | scale */
        /* { scope 3 */
        "movaps %xmm1, %xmm4\n" /* line 272 */
        "mulss (%esi), %xmm4\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss 4(%esi), %xmm6\n"
        "mulss 8(%esi), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm4, %xmm0\n" /* line 308 */
        "mulss (%esi), %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n" /* xx */
        "movss 4(%esi), %xmm3\n" /* line 309 */
        "movaps %xmm4, %xmm5\n"
        "mulss %xmm3, %xmm5\n"
        "movss 8(%esi), %xmm2\n" /* line 310 */
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n" /* xz */
        "movss 0xc(%esi), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm4\n"
        "mulss %xmm6, %xmm3\n" /* line 313 */
        "movss %xmm3, -0x7c(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm7\n" /* line 314 */
        "mulss %xmm2, %xmm7\n"
        "mulss %xmm0, %xmm6\n" /* line 315 */
        "movaps %xmm1, %xmm3\n" /* line 317 */
        "mulss %xmm2, %xmm3\n"
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss %xmm1, -0x8c(%ebp)\n" /* zw */
        "movss -0x7c(%ebp), %xmm0\n" /* line 320 | yy */
        "addss %xmm3, %xmm0\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* axis */
        "movss -0x8c(%ebp), %xmm0\n" /* line 321 | zw */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 322 | xz */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "subss -0x8c(%ebp), %xmm5\n" /* line 324 | zw */
        "movss %xmm5, -0x30(%ebp)\n"
        "addss -0x84(%ebp), %xmm3\n" /* line 325 | xx */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 326 */
        "addss %xmm7, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "addss -0x80(%ebp), %xmm6\n" /* line 328 | xz */
        "movss %xmm6, -0x24(%ebp)\n"
        "subss %xmm4, %xmm7\n" /* line 329 */
        "movss %xmm7, -0x20(%ebp)\n"
        "movss -0x84(%ebp), %xmm1\n" /* line 330 | xx */
        "addss -0x7c(%ebp), %xmm1\n" /* yy */
        "subss %xmm1, %xmm2\n"
        "movss %xmm2, -0x1c(%ebp)\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 698 | parentAxis */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply\n"
        "movl 0xc(%ebp), %eax\n" /* line 699 | parentAxis */
        "addl $0x24, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x10(%esi), %eax\n" /* mat */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector43\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 706 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xx, xz, yy, zw */
        ".Lf1b3e04_001b3fb9:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 703 | parentAxis */
        "movl %ebx, 4(%esp)\n"
        "leal 0x144(%esi), %eax\n" /* mat */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl %ebx, %ecx\n" /* line 704 | to */
        "addl $0x24, %ecx\n" /* to */
        "leal 0x138(%esi), %edx\n" /* mat, from */
        /* { scope 2 */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x24(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 706 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 765 */
__attribute__((naked))
unsigned char G_SetFixedLink(gentity_t *ent, int eAngles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 765 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        "movl 0xc(%ebp), %ebx\n" /* eAngles */
        /* { scope 1 */
        "leal -0x78(%ebp), %edi\n" /* line 771 | parentAxis */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_CalcTagParentAxis\n"
        "movl 0x208(%esi), %edx\n" /* line 773 | ent */
        "cmpl $1, %ebx\n" /* line 776 | eAngles */
        "je .Lf1b3ffa_001b4083\n"
        "cmpl $2, %ebx\n" /* eAngles */
        "je .Lf1b3ffa_001b40ca\n"
        "testl %ebx, %ebx\n" /* eAngles */
        "je .Lf1b3ffa_001b4038\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 795 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b3ffa_001b4038:\n"
        "leal -0x48(%ebp), %ebx\n" /* line 779 | axis, eAngles */
        "movl %ebx, 8(%esp)\n" /* eAngles */
        "movl %edi, 4(%esp)\n"
        "leal 0x10(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply43\n"
        "leal 0x138(%esi), %edx\n" /* line 780 | ent, to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x138(%esi)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x144(%esi), %eax\n" /* line 781 | ent */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* eAngles */
        "calll AxisToAngles\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 795 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b3ffa_001b4083:\n"
        "leal -0x48(%ebp), %ebx\n" /* line 785 | axis, eAngles */
        "movl %ebx, 8(%esp)\n" /* eAngles */
        "movl %edi, 4(%esp)\n"
        "leal 0x10(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply43\n"
        "leal 0x138(%esi), %edx\n" /* line 786 | ent, to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x138(%esi)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 787 | eAngles */
        "calll vectoyaw\n"
        "fstps 0x148(%esi)\n" /* ent */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 795 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b3ffa_001b40ca:\n"
        "leal -0x24(%ebp), %eax\n" /* line 791 */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal 0x34(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector43\n"
        "leal 0x138(%esi), %edx\n" /* line 792 | ent, to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x138(%esi)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 795 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 732 */
__attribute__((naked))
unsigned char G_CalcTagAxis(gentity_t *ent, qboolean bAnglesOnly)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 732 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1 */
        "leal -0x78(%ebp), %edi\n" /* line 739 | parentAxis */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_CalcTagParentAxis\n"
        "leal -0x48(%ebp), %eax\n" /* line 741 | axis */
        "movl %eax, 4(%esp)\n"
        "leal 0x144(%esi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl 0x208(%esi), %eax\n" /* line 743 | ent */
        "movl %eax, -0xac(%ebp)\n" /* tagInfo */
        "movl 0xc(%ebp), %eax\n" /* line 746 | bAnglesOnly */
        "testl %eax, %eax\n"
        "je .Lf1b4104_001b4183\n"
        "leal -0xa8(%ebp), %ebx\n" /* line 748 | invParentAxis */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MatrixTranspose\n"
        "movl -0xac(%ebp), %eax\n" /* line 749 | tagInfo */
        "addl $0x10, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 757 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b4104_001b4183:\n"
        "leal -0xa8(%ebp), %ebx\n" /* line 753 | invParentAxis */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MatrixInverseOrthogonal43\n"
        "leal 0x138(%esi), %edx\n" /* ent */
        /* { scope 2 */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        /* } scope */
        "movl -0xac(%ebp), %eax\n" /* line 755 | tagInfo */
        "addl $0x10, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply43\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 757 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 552 */
__attribute__((naked))
unsigned char G_EntUnlink(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 552 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1 */
        "movl 0x208(%ebx), %esi\n" /* line 560 | ent, tagInfo */
        "testl %esi, %esi\n" /* line 561 | tagInfo */
        "je .Lf1b41da_001b42ed\n"
        "leal 0x18(%ebx), %edx\n" /* line 1602 | ent, to */
        /* { scope 2 */
        "movl 0x138(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x18(%ebx)\n"
        "movl 0x13c(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0x140(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $0, 0xc(%ebx)\n" /* line 1603 | ent */
        "movl $0, 0x10(%ebx)\n" /* line 1604 | ent */
        "movl $0, 0x14(%ebx)\n" /* line 1605 | ent */
        "leal 0x24(%ebx), %eax\n" /* line 1606 | ent, v */
        /* { scope 2 */
        "xorl %ecx, %ecx\n" /* line 183 */
        "movl %ecx, 0x24(%ebx)\n"
        "movl %ecx, 4(%eax)\n" /* line 184 */
        "movl %ecx, 8(%eax)\n" /* line 185 */
        /* } scope */
        "leal 0x3c(%ebx), %edx\n" /* line 1620 | ent, to */
        /* { scope 2 */
        "movl 0x144(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x3c(%ebx)\n"
        "movl 0x148(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0x14c(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $0, 0x30(%ebx)\n" /* line 1621 | ent */
        "movl $0, 0x34(%ebx)\n" /* line 1622 | ent */
        "movl $0, 0x38(%ebx)\n" /* line 1623 | ent */
        "leal 0x48(%ebx), %eax\n" /* line 1624 | ent, v */
        /* { scope 2 */
        "movl %ecx, 0x48(%ebx)\n" /* line 183 */
        "movl %ecx, 4(%eax)\n" /* line 184 */
        "movl %ecx, 8(%eax)\n" /* line 185 */
        /* } scope */
        "movl 0x158(%ebx), %edx\n" /* line 567 | ent */
        "testl %edx, %edx\n"
        "je .Lf1b41da_001b42a1\n"
        "movl 0xe8(%edx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n" /* viewAngles */
        "movl 0xec(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl %ecx, -0xc(%ebp)\n" /* line 570 */
        "leal -0x14(%ebp), %eax\n" /* line 572 | viewAngles */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll SetClientViewAngle\n"
        ".Lf1b41da_001b42a1:\n"
        "movl (%esi), %edx\n" /* line 575 | tagInfo */
        "movl 0x20c(%edx), %eax\n" /* line 579 */
        "cmpl %eax, %ebx\n" /* line 580 | ent */
        "je .Lf1b41da_001b42f4\n"
        ".Lf1b41da_001b42ad:\n"
        "movl 0x208(%eax), %edx\n" /* line 584 */
        "movl 4(%edx), %eax\n"
        "cmpl %eax, %ebx\n" /* line 580 | ent */
        "jne .Lf1b41da_001b42ad\n"
        "movl 4(%esi), %eax\n" /* line 590 | tagInfo */
        "movl %eax, 4(%edx)\n"
        ".Lf1b41da_001b42c0:\n"
        "movl $0, 0x208(%ebx)\n" /* line 597 | ent */
        "movl $0, 4(%esp)\n" /* line 599 */
        "leal 8(%esi), %eax\n" /* tagInfo */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl $0x70, 4(%esp)\n" /* line 601 */
        "movl %esi, (%esp)\n" /* tagInfo */
        "calll MT_Free\n"
        /* } scope */
        ".Lf1b41da_001b42ed:\n"
        "addl $0x20, %esp\n" /* line 602 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b41da_001b42f4:\n"
        "movl 4(%esi), %eax\n" /* line 594 | tagInfo */
        "movl %eax, 0x20c(%edx)\n"
        "jmp .Lf1b41da_001b42c0\n"
    );
}

/* line 458 */
static __attribute__((naked))
qboolean G_EntLinkToInternal(gentity_t *parent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 458 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %esi\n" /* ent */
        "movl %edx, -0x20(%ebp)\n"
        "movl %ecx, %edi\n" /* tagName */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 467 */
        "calll G_EntUnlink\n"
        "testl %edi, %edi\n" /* line 471 | tagName */
        "jne .Lf1b4300_001b43c0\n"
        "movl $0xffffffff, -0x1c(%ebp)\n" /* index */
        ".Lf1b4300_001b4327:\n"
        "cmpl -0x20(%ebp), %esi\n" /* line 489 | ent */
        "je .Lf1b4300_001b43cf\n"
        "movl -0x20(%ebp), %ecx\n" /* line 491 */
        "movl 0x208(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1b4300_001b4351\n"
        ".Lf1b4300_001b433d:\n"
        "movl (%eax), %eax\n" /* line 493 */
        "cmpl %eax, %esi\n" /* line 489 | ent */
        "je .Lf1b4300_001b43cf\n"
        "movl 0x208(%eax), %eax\n" /* line 491 */
        "testl %eax, %eax\n"
        "jne .Lf1b4300_001b433d\n"
        ".Lf1b4300_001b4351:\n"
        "movl $0x10, 4(%esp)\n" /* line 496 */
        "movl $0x70, (%esp)\n"
        "calll MT_Alloc\n"
        "movl %eax, %ebx\n"
        "movl -0x20(%ebp), %ecx\n" /* line 497 */
        "movl %ecx, (%eax)\n"
        "movw $0, 8(%eax)\n" /* line 498 */
        "movl %edi, 4(%esp)\n" /* line 500 | tagName */
        "leal 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl -0x20(%ebp), %edx\n" /* line 501 */
        "movl 0x20c(%edx), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 502 | index */
        "movl %ecx, 0xc(%ebx)\n"
        "leal 0x10(%ebx), %edi\n" /* line 503 | tagName */
        "cld\n"
        "xorl %eax, %eax\n"
        "movl $0xc, %ecx\n"
        "rep stosl %eax, %es:(%edi)\n" /* tagName */
        "movl -0x20(%ebp), %edx\n" /* line 504 */
        "movl %esi, 0x20c(%edx)\n" /* ent */
        "movl %ebx, 0x208(%esi)\n" /* line 505 | ent */
        "leal 0x40(%ebx), %edi\n" /* line 506 | tagName */
        "movb $0xc, %cl\n"
        "rep stosl %eax, %es:(%edi)\n" /* tagName */
        "movb $1, %al\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 508 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b4300_001b43c0:\n"
        "movl -0x20(%ebp), %eax\n" /* line 473 */
        "movl %eax, (%esp)\n"
        "calll SV_DObjExists\n"
        "testl %eax, %eax\n"
        "jne .Lf1b4300_001b43d9\n"
        ".Lf1b4300_001b43cf:\n"
        "xorl %eax, %eax\n" /* line 507 */
        /* } scope */
        ".Lf1b4300_001b43d1:\n"
        "addl $0x2c, %esp\n" /* line 508 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b4300_001b43d9:\n"
        "movl %edi, 4(%esp)\n" /* line 475 | tagName */
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll SV_DObjGetBoneIndex\n"
        "movl %eax, -0x1c(%ebp)\n" /* index */
        "testl %eax, %eax\n" /* line 476 */
        "jns .Lf1b4300_001b4327\n"
        "xorl %eax, %eax\n" /* line 507 */
        "jmp .Lf1b4300_001b43d1\n"
    );
}

/* line 532 */
__attribute__((naked))
qboolean G_EntLinkToWithOffset(gentity_t *ent, gentity_t *parent, unsigned int tagName, const vec_t *originOffset, const vec_t *anglesOffset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 532 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl 0xc(%ebp), %edx\n" /* parent */
        "movl 0x10(%ebp), %ecx\n" /* tagName */
        "movl 0x14(%ebp), %esi\n" /* originOffset */
        /* { scope 1 */
        "movl %ebx, %eax\n" /* line 536 | tagInfo */
        "calll G_EntLinkToInternal\n"
        "testl %eax, %eax\n"
        "je .Lf1b43f8_001b4448\n"
        "movl 0x208(%ebx), %ebx\n" /* line 539 | tagInfo */
        "leal 0x10(%ebx), %eax\n" /* line 540 | tagInfo */
        "movl %eax, 4(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* anglesOffset */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x34(%ebx), %edx\n" /* line 541 | tagInfo, to */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, 0x34(%ebx)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf1b43f8_001b4448:\n"
        "addl $0x10, %esp\n" /* line 544 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 516 */
__attribute__((naked))
qboolean G_EntLinkTo(gentity_t *ent, gentity_t *parent, unsigned int tagName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 516 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl 0xc(%ebp), %edx\n" /* parent */
        "movl 0x10(%ebp), %ecx\n" /* tagName */
        "movl %ebx, %eax\n" /* line 518 | ent */
        "calll G_EntLinkToInternal\n"
        "testl %eax, %eax\n"
        "je .Lf1b4450_001b4480\n"
        "movl $0, 4(%esp)\n" /* line 521 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_CalcTagAxis\n"
        "movl $1, %eax\n"
        ".Lf1b4450_001b4480:\n"
        "addl $0x14, %esp\n" /* line 524 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 803 */
__attribute__((naked))
unsigned char G_GeneralLink(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 803 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl $0, 4(%esp)\n" /* line 807 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_SetFixedLink\n"
        "leal 0x18(%ebx), %edx\n" /* line 1602 | ent, to */
        /* { scope 1 */
        "movl 0x138(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x18(%ebx)\n"
        "movl 0x13c(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0x140(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $0, 0x10(%ebx)\n" /* line 1604 | ent */
        "movl $0, 0x14(%ebx)\n" /* line 1605 | ent */
        "leal 0x24(%ebx), %eax\n" /* line 1606 | ent, v */
        /* { scope 1 */
        "xorl %edx, %edx\n" /* line 183 */
        "movl %edx, 0x24(%ebx)\n"
        "movl %edx, 4(%eax)\n" /* line 184 */
        "movl %edx, 8(%eax)\n" /* line 185 */
        /* } scope */
        "leal 0x3c(%ebx), %ecx\n" /* line 1620 | ent, to */
        /* { scope 1 */
        "movl 0x144(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x3c(%ebx)\n"
        "movl 0x148(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 0x14c(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0, 0x34(%ebx)\n" /* line 1622 | ent */
        "movl $0, 0x38(%ebx)\n" /* line 1623 | ent */
        "leal 0x48(%ebx), %eax\n" /* line 1624 | ent, v */
        /* { scope 1 */
        "movl %edx, 0x48(%ebx)\n" /* line 183 */
        "movl %edx, 4(%eax)\n" /* line 184 */
        "movl %edx, 8(%eax)\n" /* line 185 */
        /* } scope */
        "movl $1, 0xc(%ebx)\n" /* line 812 | ent */
        "movl $1, 0x30(%ebx)\n" /* line 813 | ent */
        "movl %ebx, 8(%ebp)\n" /* line 815 | ent */
        "addl $0x14, %esp\n" /* line 816 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SV_LinkEntity\n" /* line 815 */
    );
}

/* line 1332 */
__attribute__((naked))
unsigned char G_FreeEntity(gentity_t *ed)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1332 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ed */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 1337 | ed */
        "calll G_EntUnlink\n"
        "movl 0x20c(%esi), %eax\n" /* line 1338 | ed */
        "testl %eax, %eax\n"
        "je .Lf1b452e_001b455e\n"
        ".Lf1b452e_001b454c:\n"
        "movl %eax, (%esp)\n" /* line 1339 */
        "calll G_EntUnlink\n"
        "movl 0x20c(%esi), %eax\n" /* line 1338 | ed */
        "testl %eax, %eax\n"
        "jne .Lf1b452e_001b454c\n"
        ".Lf1b452e_001b455e:\n"
        "movl %esi, (%esp)\n" /* line 1341 | ed */
        "calll SV_UnlinkEntity\n"
        "movl %esi, (%esp)\n" /* line 1343 | ed */
        "calll SV_DObjGetTree\n"
        "testl %eax, %eax\n" /* line 1344 */
        "je .Lf1b452e_001b457a\n"
        "movl %eax, (%esp)\n" /* line 1345 */
        "calll XAnimClearTree\n"
        ".Lf1b452e_001b457a:\n"
        "movl (%esi), %eax\n" /* line 1347 | ed */
        "movl %eax, (%esp)\n"
        "calll Com_SafeServerDObjFree\n"
        /* { scope 2 */
        "movl (%esi), %ebx\n" /* line 1191 | entnum */
        "movl 0x195f6a0, %edi\n" /* line 1193 */
        "movl 0xc(%edi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf1b452e_001b45f9\n"
        "xorl %edx, %edx\n"
        "movl 0x195f688, %eax\n"
        "jmp .Lf1b452e_001b45ad\n"
        ".Lf1b452e_001b459c:\n"
        "cmpl 0x7c(%eax), %ebx\n" /* line 1211 | entnum */
        "je .Lf1b452e_001b45e6\n"
        ".Lf1b452e_001b45a1:\n"
        "addl $1, %edx\n" /* line 1193 */
        "addl $0x230, %eax\n"
        "cmpl %ecx, %edx\n"
        "je .Lf1b452e_001b45f9\n"
        ".Lf1b452e_001b45ad:\n"
        "cmpb $0, 0xfc(%eax)\n" /* line 1196 */
        "je .Lf1b452e_001b45a1\n"
        "cmpl 0x18c(%eax), %esi\n" /* line 1199 */
        "je .Lf1b452e_001b472d\n"
        ".Lf1b452e_001b45c2:\n"
        "cmpl 0x150(%eax), %ebx\n" /* line 1202 | entnum */
        "jne .Lf1b452e_001b459c\n"
        "movl $0x3ff, 0x150(%eax)\n" /* line 1204 */
        "cmpl $9, 4(%eax)\n" /* line 1207 */
        "jne .Lf1b452e_001b459c\n"
        "movb $0, 0x162(%eax)\n" /* line 1208 */
        "cmpl 0x7c(%eax), %ebx\n" /* line 1211 | entnum */
        "jne .Lf1b452e_001b45a1\n"
        ".Lf1b452e_001b45e6:\n"
        "movl $0x3ff, 0x7c(%eax)\n" /* line 1212 */
        "addl $1, %edx\n" /* line 1193 */
        "addl $0x230, %eax\n"
        "cmpl %ecx, %edx\n"
        "jne .Lf1b452e_001b45ad\n"
        ".Lf1b452e_001b45f9:\n"
        "xorl %ecx, %ecx\n"
        "movl 0x195f688, %edx\n"
        "jmp .Lf1b452e_001b4619\n"
        ".Lf1b452e_001b4603:\n"
        "cmpl 0x5a0(%eax), %ebx\n" /* line 1230 | entnum */
        "je .Lf1b452e_001b464e\n"
        ".Lf1b452e_001b460b:\n"
        "addl $1, %ecx\n" /* line 1215 */
        "addl $0x230, %edx\n"
        "cmpl $0x40, %ecx\n"
        "je .Lf1b452e_001b4666\n"
        ".Lf1b452e_001b4619:\n"
        "cmpb $0, 0xfc(%edx)\n" /* line 1218 */
        "je .Lf1b452e_001b460b\n"
        "movl 0x158(%edx), %eax\n" /* line 1221 */
        "cmpl 0x282c(%eax), %esi\n" /* line 1224 */
        "je .Lf1b452e_001b471e\n"
        ".Lf1b452e_001b4634:\n"
        "cmpl 0x2830(%eax), %ebx\n" /* line 1227 | entnum */
        "jne .Lf1b452e_001b4603\n"
        "movl $0x3ff, 0x2830(%eax)\n" /* line 1228 */
        "cmpl 0x5a0(%eax), %ebx\n" /* line 1230 | entnum */
        "jne .Lf1b452e_001b460b\n"
        ".Lf1b452e_001b464e:\n"
        "movl $0x3ff, 0x5a0(%eax)\n" /* line 1231 */
        "addl $1, %ecx\n" /* line 1215 */
        "addl $0x230, %edx\n"
        "cmpl $0x40, %ecx\n"
        "jne .Lf1b452e_001b4619\n"
        ".Lf1b452e_001b4666:\n"
        "movl %edi, %eax\n"
        "movl 0x195f6a0, %edx\n"
        "subl $-0x80, %edx\n"
        "jmp .Lf1b452e_001b467a\n"
        ".Lf1b452e_001b4673:\n"
        "addl $4, %eax\n" /* line 1237 */
        "cmpl %eax, %edx\n" /* line 1234 */
        "je .Lf1b452e_001b4693\n"
        ".Lf1b452e_001b467a:\n"
        "cmpl 0x1d58(%eax), %esi\n" /* line 1236 */
        "jne .Lf1b452e_001b4673\n"
        "movl $0, 0x1d58(%eax)\n" /* line 1237 */
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n" /* line 1234 */
        "jne .Lf1b452e_001b467a\n"
        /* } scope */
        ".Lf1b452e_001b4693:\n"
        "movl 0x15c(%esi), %eax\n" /* line 1351 | ed */
        "testl %eax, %eax\n"
        "je .Lf1b452e_001b46a5\n"
        "movl %esi, (%esp)\n" /* line 1354 | ed */
        "calll G_FreeTurret\n"
        ".Lf1b452e_001b46a5:\n"
        "cmpl $2, 4(%esi)\n" /* line 1359 | ed */
        "je .Lf1b452e_001b473c\n"
        ".Lf1b452e_001b46af:\n"
        "movl %esi, (%esp)\n" /* line 1365 | ed */
        "calll Scr_FreeEntity\n"
        "movl 0x228(%esi), %ebx\n" /* line 1367 | ed, useCount */
        "movl $0x230, 8(%esp)\n" /* line 1368 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ed */
        "calll memset\n"
        "movl 0x195f6a0, %edi\n" /* line 1369 */
        "movl 0x1ec(%edi), %eax\n"
        "movl %eax, 0x178(%esi)\n" /* ed */
        "movl %esi, %eax\n" /* line 1371 | ed */
        "subl 4(%edi), %eax\n"
        "cmpl $0x9d7f, %eax\n"
        "jle .Lf1b452e_001b470d\n"
        "movl 0x14(%edi), %eax\n" /* line 1373 */
        "testl %eax, %eax\n"
        "je .Lf1b452e_001b4779\n"
        "movl %esi, 0x22c(%eax)\n" /* line 1374 | ed */
        ".Lf1b452e_001b4700:\n"
        "movl %esi, 0x14(%edi)\n" /* line 1377 | ed */
        "movl $0, 0x22c(%esi)\n" /* line 1378 | ed */
        ".Lf1b452e_001b470d:\n"
        "leal 1(%ebx), %eax\n" /* line 1381 | useCount */
        "movl %eax, 0x228(%esi)\n" /* ed */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1383 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b452e_001b471e:\n"
        "movl $0, 0x282c(%eax)\n" /* line 1225 */
        "jmp .Lf1b452e_001b4634\n"
        ".Lf1b452e_001b472d:\n"
        "movl $0, 0x18c(%eax)\n" /* line 1200 */
        "jmp .Lf1b452e_001b45c2\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1b452e_001b473c:\n"
        "movl (%esi), %ecx\n" /* line 1253 */
        "xorl %edx, %edx\n"
        "movl 0x195f6d0, %ebx\n" /* entnum */
        "movl %ebx, %eax\n" /* entnum */
        ".Lf1b452e_001b4748:\n"
        "cmpl 0x10bc(%eax), %ecx\n" /* line 1256 */
        "je .Lf1b452e_001b475f\n"
        "addl $1, %edx\n" /* line 1254 */
        "addl $0x4c8, %eax\n"
        "cmpl $8, %edx\n"
        "jne .Lf1b452e_001b4748\n"
        "xorb %dl, %dl\n"
        /* } scope */
        ".Lf1b452e_001b475f:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 1319 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl $0xffffffff, 0x10bc(%ebx, %eax, 8)\n" /* entnum */
        "jmp .Lf1b452e_001b46af\n"
        /* } scope */
        ".Lf1b452e_001b4779:\n"
        "movl %esi, 0x10(%edi)\n" /* line 1376 | ed */
        "jmp .Lf1b452e_001b4700\n"
    );
}

/* line 1270 */
__attribute__((naked))
int G_GetFreePlayerCorpseIndex(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1270 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x195f5bc, %eax\n" /* line 1282 */
        "movzwl 0x32(%eax), %edi\n" /* match */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x195f6a0, %eax\n" /* line 976 */
        "movl 0xc(%eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl 0x195f688, %eax\n"
        "addl %eax, %edx\n"
        "cmpl %eax, %edx\n"
        "jbe .Lf1b477e_001b47e7\n"
        "leal 0x168(%eax), %esi\n" /* line 1270 */
        "movl %eax, %ecx\n"
        "leal 0xfc(%eax), %eax\n"
        ".Lf1b477e_001b47c0:\n"
        "cmpb $0, (%eax)\n" /* line 978 */
        "je .Lf1b477e_001b47d2\n"
        "movzwl (%esi), %ebx\n" /* line 980 | s */
        "testw %bx, %bx\n" /* line 981 | s */
        "je .Lf1b477e_001b47d2\n"
        "cmpw %bx, %di\n" /* line 983 | s */
        "je .Lf1b477e_001b47e9\n"
        ".Lf1b477e_001b47d2:\n"
        "addl $0x230, %ecx\n" /* line 976 */
        "addl $0x230, %eax\n"
        "addl $0x230, %esi\n"
        "cmpl %ecx, %edx\n"
        "ja .Lf1b477e_001b47c0\n"
        ".Lf1b477e_001b47e7:\n"
        "xorl %ecx, %ecx\n"
        ".Lf1b477e_001b47e9:\n"
        "leal 0x18(%ecx), %edx\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl 0x18(%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n" /* playerPos */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        "movss %xmm0, -0x2c(%ebp)\n" /* bestDistSq */
        "xorl %edi, %edi\n"
        "xorl %ebx, %ebx\n"
        "movl 0x195f6d0, %esi\n"
        /* } scope */
        ".Lf1b477e_001b4815:\n"
        "movl 0x10bc(%esi), %eax\n" /* line 1288 */
        "cmpl $-1, %eax\n"
        "je .Lf1b477e_001b48b8\n"
        "leal -0x24(%ebp), %edx\n" /* line 1291 | playerPos */
        "movl %edx, 4(%esp)\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl 0x195f6a0, %edx\n"
        "addl 4(%edx), %eax\n"
        "addl $0x138, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x30(%ebp)\n" /* distSq */
        "movss -0x30(%ebp), %xmm0\n" /* line 1292 | distSq */
        "ucomiss -0x2c(%ebp), %xmm0\n" /* bestDistSq */
        "jbe .Lf1b477e_001b4865\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* bestDistSq */
        "movl %ebx, %edi\n" /* i, match */
        ".Lf1b477e_001b4865:\n"
        "addl $1, %ebx\n" /* line 1286 | i */
        "addl $0x4c8, %esi\n"
        "cmpl $8, %ebx\n" /* i */
        "jne .Lf1b477e_001b4815\n"
        "leal (%edi, %edi, 8), %ebx\n" /* line 1300 | match, i */
        "movl %ebx, %eax\n" /* i */
        "shll $4, %eax\n"
        "addl %eax, %ebx\n" /* i */
        "shll $3, %ebx\n" /* i */
        "addl 0x195f6d0, %ebx\n" /* i */
        "addl $0x10b0, %ebx\n" /* i */
        "movl 0xc(%ebx), %edx\n" /* i */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl 0x195f6a0, %edx\n"
        "addl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_FreeEntity\n"
        "movl $0xffffffff, 0xc(%ebx)\n" /* line 1301 | i */
        "movl %edi, %ebx\n" /* match, i */
        /* } scope */
        ".Lf1b477e_001b48b8:\n"
        "movl %ebx, %eax\n" /* line 1304 | i */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 237 */
__attribute__((naked))
unsigned char G_DObjUpdate(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 237 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 247 | ent */
        "movl 0x158(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1b48c2_001b48e6\n"
        /* } scope */
        ".Lf1b48c2_001b48db:\n"
        "addl $0x8c, %esp\n" /* line 295 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b48c2_001b48e6:\n"
        "movl (%eax), %eax\n" /* line 826 */
        "movl %eax, (%esp)\n"
        "calll Com_SafeServerDObjFree\n"
        "movl 8(%ebp), %ecx\n" /* line 252 | ent */
        "movzbl 0x164(%ecx), %eax\n"
        "movzbl %al, %edx\n"
        "testb %al, %al\n" /* line 253 */
        "jne .Lf1b48c2_001b4934\n"
        "movl 0x20c(%ecx), %eax\n" /* line 658 */
        "testl %eax, %eax\n" /* line 659 */
        "jne .Lf1b48c2_001b491a\n"
        "jmp .Lf1b48c2_001b48db\n"
        /* { scope 2 */
        ".Lf1b48c2_001b490d:\n"
        "movl $0xffffffff, 0xc(%edx)\n" /* line 644 */
        /* } scope */
        ".Lf1b48c2_001b4914:\n"
        "testl %ebx, %ebx\n" /* line 659 */
        "je .Lf1b48c2_001b48db\n"
        "movl %ebx, %eax\n"
        ".Lf1b48c2_001b491a:\n"
        "movl 0x208(%eax), %edx\n" /* line 661 */
        "movl 4(%edx), %ebx\n"
        /* { scope 2 */
        "cmpw $0, 8(%edx)\n" /* line 633 */
        "je .Lf1b48c2_001b490d\n"
        "movl %eax, (%esp)\n" /* line 641 */
        "calll G_EntUnlink\n"
        "jmp .Lf1b48c2_001b4914\n"
        /* } scope */
        ".Lf1b48c2_001b4934:\n"
        "movl cached_models(, %edx, 4), %eax\n" /* line 265 */
        "movl %eax, -0x78(%ebp)\n" /* dobjModels */
        "movl $0, -0x74(%ebp)\n" /* line 266 */
        "movl $0, -0x70(%ebp)\n" /* line 267 */
        "movl 4(%ecx), %eax\n" /* line 271 */
        "testl %eax, %eax\n"
        "je .Lf1b48c2_001b49dd\n"
        "cmpl $6, %eax\n"
        "je .Lf1b48c2_001b4a62\n"
        "cmpl $9, %eax\n"
        "je .Lf1b48c2_001b4a62\n"
        ".Lf1b48c2_001b4969:\n"
        "movl 8(%ebp), %ebx\n" /* line 274 | ent */
        "movl %ebx, %esi\n"
        "movl $1, -0x7c(%ebp)\n" /* numModels */
        "xorl %edi, %edi\n" /* i */
        "leal -0xc(%ebp), %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "jmp .Lf1b48c2_001b498d\n"
        ".Lf1b48c2_001b497f:\n"
        "addl $1, %edi\n" /* line 277 | i */
        "addl $1, %ebx\n"
        "addl $2, %esi\n"
        "cmpl $7, %edi\n" /* i */
        "je .Lf1b48c2_001b49e7\n"
        ".Lf1b48c2_001b498d:\n"
        "movzbl 0x210(%ebx), %eax\n" /* line 279 */
        "movzbl %al, %edx\n"
        "testb %al, %al\n" /* line 280 */
        "je .Lf1b48c2_001b497f\n"
        "movl cached_models(, %edx, 4), %eax\n" /* line 284 */
        "movl -0x80(%ebp), %ecx\n"
        "movl %eax, -0x60(%ecx)\n"
        "movzwl 0x218(%esi), %eax\n" /* line 287 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl -0x80(%ebp), %edx\n"
        "movl %eax, -0x5c(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 288 | ent */
        "movzbl 0x165(%ecx), %eax\n"
        "movl %edi, %ecx\n" /* i */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, -0x58(%edx)\n"
        "addl $1, -0x7c(%ebp)\n" /* line 289 | numModels */
        "addl $0xc, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "jmp .Lf1b48c2_001b497f\n"
        ".Lf1b48c2_001b49dd:\n"
        "movl %ecx, %eax\n"
        ".Lf1b48c2_001b49df:\n"
        "movl %edx, 0x8c(%eax)\n" /* line 274 */
        "jmp .Lf1b48c2_001b4969\n"
        ".Lf1b48c2_001b49e7:\n"
        "movl 8(%ebp), %edx\n" /* line 292 | ent */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movzwl -0x7c(%ebp), %eax\n" /* numModels */
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* dobjModels */
        "movl %eax, (%esp)\n"
        "calll Com_ServerDObjCreate\n"
        "movl 8(%ebp), %ecx\n" /* line 658 | ent */
        "movl 0x20c(%ecx), %esi\n"
        "testl %esi, %esi\n" /* line 659 */
        "jne .Lf1b48c2_001b4a2e\n"
        "jmp .Lf1b48c2_001b48db\n"
        /* { scope 2 */
        ".Lf1b48c2_001b4a1d:\n"
        "movl $0xffffffff, 0xc(%ebx)\n" /* line 644 */
        /* } scope */
        ".Lf1b48c2_001b4a24:\n"
        "testl %edi, %edi\n" /* line 659 | i */
        "je .Lf1b48c2_001b48db\n"
        "movl %edi, %esi\n" /* i */
        ".Lf1b48c2_001b4a2e:\n"
        "movl 0x208(%esi), %ebx\n" /* line 661 */
        "movl 4(%ebx), %edi\n" /* i */
        /* { scope 2 */
        "movzwl 8(%ebx), %eax\n" /* line 633 */
        "testw %ax, %ax\n"
        "je .Lf1b48c2_001b4a1d\n"
        "movzwl %ax, %eax\n" /* line 637 */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_DObjGetBoneIndex\n"
        "movl %eax, 0xc(%ebx)\n"
        "testl %eax, %eax\n" /* line 638 */
        "jns .Lf1b48c2_001b4a24\n"
        "movl %esi, (%esp)\n" /* line 641 */
        "calll G_EntUnlink\n"
        "jmp .Lf1b48c2_001b4a24\n"
        ".Lf1b48c2_001b4a62:\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "jmp .Lf1b48c2_001b49df\n"
    );
}

/* line 437 */
__attribute__((naked))
unsigned char G_EntDetachAll(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 437 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, -0x1c(%ebp)\n" /* ent */
        "movl %eax, %esi\n"
        "xorl %edi, %edi\n"
        "movl %eax, %ebx\n"
        "addl $0x218, %ebx\n"
        /* { scope 1 */
        ".Lf1b4a6a_001b4a85:\n"
        "movb $0, 0x210(%esi)\n" /* line 443 */
        "movl $0, 4(%esp)\n" /* line 444 */
        "movl %ebx, (%esp)\n"
        "calll Scr_SetString\n"
        "addl $1, %edi\n" /* line 441 | i */
        "addl $2, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $7, %edi\n" /* i */
        "jne .Lf1b4a6a_001b4a85\n"
        "movl -0x1c(%ebp), %eax\n" /* line 447 | ent */
        "movb $0, 0x165(%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 449 | ent */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 450 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp G_DObjUpdate\n" /* line 449 */
    );
}

/* line 392 */
__attribute__((naked))
qboolean G_EntDetach(gentity_t *ent, const char *modelName, unsigned int tagName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 392 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        "movl %esi, %ebx\n"
        "xorl %edi, %edi\n"
        "jmp .Lf1b4ac4_001b4ae8\n"
        /* { scope 1 */
        ".Lf1b4ac4_001b4ad6:\n"
        "addl $1, %edi\n" /* line 398 | i */
        "addl $2, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $7, %edi\n" /* i */
        "je .Lf1b4ac4_001b4be3\n"
        ".Lf1b4ac4_001b4ae8:\n"
        "movzwl 0x218(%ebx), %eax\n" /* line 400 */
        "cmpl 0x10(%ebp), %eax\n" /* tagName */
        "jne .Lf1b4ac4_001b4ad6\n"
        "movzbl 0x210(%esi), %eax\n" /* line 189 */
        "addl $0x14e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstringConst\n"
        "movl 0xc(%ebp), %edx\n" /* line 403 | modelName */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1b4ac4_001b4ad6\n"
        "movl 8(%ebp), %ecx\n" /* line 406 | ent */
        "movb $0, 0x210(%edi, %ecx)\n" /* i */
        "leal 0x218(%ecx, %edi, 2), %eax\n" /* line 407 */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "cmpl $5, %edi\n" /* line 409 | i */
        "jg .Lf1b4ac4_001b4bf2\n"
        "movl 8(%ebp), %edx\n" /* line 392 | ent */
        "leal 0x211(%edi, %edx), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "leal 0x21a(%ecx, %edi, 2), %esi\n"
        "movl %edi, %ebx\n"
        "leal 0x210(%edi, %ecx), %edi\n"
        "subl %edx, %edi\n"
        "movl -0x20(%ebp), %eax\n"
        "subl %esi, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lf1b4ac4_001b4b9e\n"
        ".Lf1b4ac4_001b4b77:\n"
        "movl $1, %eax\n" /* line 415 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, %dl\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movb %dl, 0x165(%eax)\n"
        ".Lf1b4ac4_001b4b8b:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 417 */
        "addl $2, %esi\n"
        "cmpl $6, -0x2c(%ebp)\n" /* line 409 */
        "je .Lf1b4ac4_001b4bed\n"
        "movl -0x2c(%ebp), %ebx\n"
        "movl -0x1c(%ebp), %ecx\n"
        ".Lf1b4ac4_001b4b9e:\n"
        "leal 1(%ebx), %edx\n" /* line 411 */
        "movl %edx, -0x2c(%ebp)\n"
        "movzbl (%ecx), %eax\n"
        "movb %al, (%ecx, %edi)\n"
        "movzwl (%esi), %eax\n" /* line 412 */
        "movl -0x24(%ebp), %edx\n"
        "movw %ax, (%esi, %edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 414 | ent */
        "movzbl 0x165(%ecx), %edx\n"
        "movzbl %dl, %eax\n"
        "movzbl -0x2c(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1b4ac4_001b4b77\n"
        "movl $1, %eax\n" /* line 417 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "notb %al\n"
        "andb %al, %dl\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movb %dl, 0x165(%eax)\n"
        "jmp .Lf1b4ac4_001b4b8b\n"
        ".Lf1b4ac4_001b4be3:\n"
        "xorl %eax, %eax\n" /* line 398 */
        /* } scope */
        ".Lf1b4ac4_001b4be5:\n"
        "addl $0x3c, %esp\n" /* line 429 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b4ac4_001b4bed:\n"
        "movl $6, %edi\n" /* line 409 | i */
        ".Lf1b4ac4_001b4bf2:\n"
        "movl 8(%ebp), %edx\n" /* line 420 | ent */
        "movb $0, 0x210(%edi, %edx)\n" /* i */
        "movw $0, 0x218(%edx, %edi, 2)\n" /* line 421 */
        "movl $0xfffffffe, %eax\n" /* line 422 */
        "movl %edi, %ecx\n" /* i */
        "roll %cl, %eax\n"
        "andb %al, 0x165(%edx)\n"
        "movl %edx, (%esp)\n" /* line 424 */
        "calll G_DObjUpdate\n"
        "movl $1, %eax\n"
        "jmp .Lf1b4ac4_001b4be5\n"
    );
}

/* line 356 */
__attribute__((naked))
qboolean G_EntAttach(gentity_t *ent, const char *modelName, unsigned int tagName, qboolean ignoreCollision)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 356 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        "movl %edi, %eax\n" /* ent */
        "xorl %esi, %esi\n"
        "movl $1, -0x1c(%ebp)\n"
        "leal 0x218(%edi), %ebx\n" /* ent */
        /* { scope 1 */
        ".Lf1b4c26_001b4c43:\n"
        "cmpb $0, 0x210(%eax)\n" /* line 368 */
        "je .Lf1b4c26_001b4c64\n"
        "addl $1, %esi\n" /* line 366 | i */
        "addl $2, %ebx\n"
        "addl $1, %eax\n"
        "cmpl $7, %esi\n" /* i */
        "jne .Lf1b4c26_001b4c43\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 384 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b4c26_001b4c64:\n"
        "movl 0xc(%ebp), %eax\n" /* line 371 | modelName */
        "movl %eax, (%esp)\n"
        "calll G_ModelIndex\n"
        "movb %al, 0x210(%esi, %edi)\n" /* line 373 | i */
        "movl 0x10(%ebp), %ecx\n" /* line 375 | tagName */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 0x14(%ebp), %ecx\n" /* line 377 | ignoreCollision */
        "testl %ecx, %ecx\n"
        "jne .Lf1b4c26_001b4ca1\n"
        "movl %edi, (%esp)\n" /* line 379 | ent */
        "calll G_DObjUpdate\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1b4c26_001b4c99:\n"
        "addl $0x2c, %esp\n" /* line 384 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b4c26_001b4ca1:\n"
        "movl %esi, %ecx\n" /* line 378 | i */
        "shll %cl, -0x1c(%ebp)\n"
        "movzbl -0x1c(%ebp), %eax\n"
        "orb %al, 0x165(%edi)\n" /* ent */
        "movl %edi, (%esp)\n" /* line 379 | ent */
        "calll G_DObjUpdate\n"
        "movl $1, %eax\n"
        "jmp .Lf1b4c26_001b4c99\n"
    );
}

/* line 1118 */
__attribute__((naked))
gentity_t * G_Spawn(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1118 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 0x195f6a0, %ecx\n" /* line 1122 */
        "movl 0x10(%ecx), %ebx\n" /* e */
        "testl %ebx, %ebx\n" /* line 1093 */
        "je .Lf1b4cc0_001b4d0f\n"
        "movl 0x1ec(%ecx), %eax\n" /* line 1096 */
        "subl 0x178(%ebx), %eax\n"
        "cmpl $0x1f3, %eax\n"
        "jle .Lf1b4cc0_001b4d06\n"
        ".Lf1b4cc0_001b4ce9:\n"
        "movl 0x22c(%ebx), %eax\n" /* line 1140 | e */
        "movl %eax, 0x10(%ecx)\n"
        "testl %eax, %eax\n" /* line 1141 */
        "je .Lf1b4cc0_001b4e75\n"
        ".Lf1b4cc0_001b4cfa:\n"
        "movl $0, 0x22c(%ebx)\n" /* line 1143 | e */
        "jmp .Lf1b4cc0_001b4d5c\n"
        ".Lf1b4cc0_001b4d06:\n"
        "cmpl $0x3fd, 0xc(%ecx)\n" /* line 1096 */
        "jg .Lf1b4cc0_001b4ce9\n"
        ".Lf1b4cc0_001b4d0f:\n"
        "cmpl $0x3fe, 0xc(%ecx)\n" /* line 1125 */
        "je .Lf1b4cc0_001b4dc3\n"
        ".Lf1b4cc0_001b4d1c:\n"
        "movl 0xc(%ecx), %edx\n" /* line 1132 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* e */
        "subl %eax, %ebx\n" /* e */
        "shll $4, %ebx\n" /* e */
        "addl 4(%ecx), %ebx\n" /* e */
        "addl $1, %edx\n" /* line 1133 */
        "movl %edx, 0xc(%ecx)\n"
        "movl $0x28a4, 0x10(%esp)\n" /* line 1136 */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x230, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_LocateGameData\n"
        ".Lf1b4cc0_001b4d5c:\n"
        "movl $0, 0x22c(%ebx)\n" /* line 1072 */
        "movb $1, 0xfc(%ebx)\n" /* line 1073 */
        "movl 0x195f5bc, %eax\n" /* line 1074 */
        "movzwl 0x2a(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x168(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl %ebx, %eax\n" /* line 1075 */
        "subl 0x195f688, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, (%ebx)\n"
        "movl $0x3ff, 0x150(%ebx)\n" /* line 1076 */
        "movl $0, 0x178(%ebx)\n" /* line 1077 */
        "movl $0, 0x17c(%ebx)\n" /* line 1078 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1148 | e */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b4cc0_001b4dc3:\n"
        "xorl %esi, %esi\n" /* line 1125 */
        "movl 0x195f688, %ebx\n" /* e */
        "movl %ecx, %edi\n"
        "jmp .Lf1b4cc0_001b4e17\n"
        ".Lf1b4cc0_001b4dcf:\n"
        "movl $0x2157b8, %eax\n" /* line 1087 */
        ".Lf1b4cc0_001b4dd4:\n"
        "movsd -0x30(%ebp), %xmm0\n"
        "movsd %xmm0, 0x1c(%esp)\n"
        "movsd -0x28(%ebp), %xmm0\n"
        "movsd %xmm0, 0x14(%esp)\n"
        "movsd -0x20(%ebp), %xmm0\n"
        "movsd %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2b52b0, (%esp)\n" /* "%4i: '%s', origin: %f %f %f
" */
        "calll Com_Printf\n"
        "addl $1, %esi\n" /* line 1086 */
        "addl $0x230, %ebx\n"
        "cmpl 0xc(%edi), %esi\n"
        "jge .Lf1b4cc0_001b4e5a\n"
        ".Lf1b4cc0_001b4e17:\n"
        "cvtss2sd 0x140(%ebx), %xmm0\n" /* line 1087 */
        "movsd %xmm0, -0x30(%ebp)\n"
        "cvtss2sd 0x13c(%ebx), %xmm0\n"
        "movsd %xmm0, -0x28(%ebp)\n"
        "cvtss2sd 0x138(%ebx), %xmm0\n"
        "movsd %xmm0, -0x20(%ebp)\n"
        "movzwl 0x168(%ebx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf1b4cc0_001b4dcf\n"
        "movzwl %ax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "jmp .Lf1b4cc0_001b4dd4\n"
        ".Lf1b4cc0_001b4e5a:\n"
        "movl $0x2b52d0, 4(%esp)\n" /* line 1128 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl %edi, %ecx\n"
        "jmp .Lf1b4cc0_001b4d1c\n"
        ".Lf1b4cc0_001b4e75:\n"
        "movl $0, 0x14(%ecx)\n" /* line 1142 */
        "jmp .Lf1b4cc0_001b4cfa\n"
    );
}

/* line 1411 */
__attribute__((naked))
gentity_t * G_TempEntity(const vec_t *origin, int event)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1411 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* origin */
        /* { scope 1 */
        "calll G_Spawn\n" /* line 1416 */
        "movl %eax, %ebx\n" /* e */
        "movl 0xc(%ebp), %eax\n" /* line 1417 | event */
        "addl $0xa, %eax\n"
        "movl %eax, 4(%ebx)\n" /* e */
        "movl 0x195f5bc, %eax\n" /* line 1419 */
        "movzwl 0x50(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x168(%ebx), %eax\n" /* e */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 0x195f6a0, %edx\n" /* line 1420 */
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, 0x178(%ebx)\n" /* e */
        "movl 0x1ec(%edx), %eax\n" /* line 1421 */
        "movl %eax, 0x154(%ebx)\n" /* e */
        "movl $1, 0x17c(%ebx)\n" /* line 1422 | e */
        "cvttss2si (%esi), %eax\n" /* line 1425 | origin */
        "cvtsi2ssl %eax, %xmm2\n"
        "cvttss2si 4(%esi), %eax\n" /* origin */
        "cvtsi2ssl %eax, %xmm1\n"
        "cvttss2si 8(%esi), %eax\n" /* origin */
        "cvtsi2ssl %eax, %xmm0\n"
        "leal 0x18(%ebx), %eax\n" /* line 1602 | e, to */
        /* { scope 2 */
        "movss %xmm2, 0x18(%ebx)\n" /* line 199 */
        "movss %xmm1, 4(%eax)\n" /* line 200 */
        "movss %xmm0, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl $0, 0xc(%ebx)\n" /* line 1603 | e */
        "movl $0, 0x10(%ebx)\n" /* line 1604 | e */
        "movl $0, 0x14(%ebx)\n" /* line 1605 | e */
        "leal 0x24(%ebx), %edx\n" /* line 1606 | e, v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x24(%ebx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "leal 0x138(%ebx), %eax\n" /* line 1608 | e, to */
        /* { scope 2 */
        "movss %xmm2, 0x138(%ebx)\n" /* line 199 */
        "movss %xmm1, 4(%eax)\n" /* line 200 */
        "movss %xmm0, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 1429 | e */
        "calll SV_LinkEntity\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1432 | e */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1157 */
__attribute__((naked))
gentity_t * G_SpawnPlayerClone(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1157 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0x195f6a0, %ecx\n" /* line 1162 */
        "movl 0x1de4(%ecx), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (, %edx, 8), %esi\n"
        "subl %edx, %esi\n"
        "shll $4, %esi\n"
        "addl 4(%ecx), %esi\n"
        "leal 0x8c00(%esi), %ebx\n" /* e */
        "addl $1, %eax\n" /* line 1163 */
        "andl $0x80000007, %eax\n"
        "js .Lf1b4f5a_001b5023\n"
        ".Lf1b4f5a_001b4f95:\n"
        "movl %eax, 0x1de4(%ecx)\n"
        "movl 8(%ebx), %edi\n" /* line 1165 | e */
        "andl $2, %edi\n"
        "xorl $2, %edi\n" /* line 1166 */
        "cmpb $0, 0xfc(%ebx)\n" /* line 1168 | e */
        "je .Lf1b4f5a_001b4fb5\n"
        "movl %ebx, (%esp)\n" /* line 1169 | e */
        "calll G_FreeEntity\n"
        ".Lf1b4f5a_001b4fb5:\n"
        "movl $0, 0x22c(%ebx)\n" /* line 1072 */
        "movb $1, 0xfc(%ebx)\n" /* line 1073 */
        "movl 0x195f5bc, %eax\n" /* line 1074 */
        "movzwl 0x2a(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x8d68(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl %ebx, %eax\n" /* line 1075 */
        "subl 0x195f688, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, 0x8c00(%esi)\n"
        "movl $0x3ff, 0x150(%ebx)\n" /* line 1076 */
        "movl $0, 0x178(%ebx)\n" /* line 1077 */
        "movl $0, 0x17c(%ebx)\n" /* line 1078 */
        "movl %edi, 8(%ebx)\n" /* line 1172 | e */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1175 | e */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b4f5a_001b5023:\n"
        "subl $1, %eax\n" /* line 1163 */
        "orl $0xfffffff8, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf1b4f5a_001b4f95\n"
    );
}

/* line 911 */
__attribute__((naked))
qboolean G_DObjGetWorldTagMatrix(gentity_t *ent, unsigned int tagName, vec3_t *tagMat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 911 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1: xx, xz, yy, zw */
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 893 | tagName */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll SV_DObjGetBoneIndex\n"
        "movl %eax, %ebx\n" /* boneIndex */
        "testl %eax, %eax\n" /* line 894 */
        "js .Lf1b5032_001b51f1\n"
        "movl %eax, 4(%esp)\n" /* line 898 */
        "movl %edi, (%esp)\n"
        "calll G_DObjCalcBone\n"
        "movl %edi, (%esp)\n" /* line 901 */
        "calll SV_DObjGetMatrixArray\n"
        "shll $5, %ebx\n" /* line 902 | boneIndex */
        /* } scope */
        "movl %eax, %esi\n" /* line 918 | mat */
        "addl %ebx, %esi\n" /* boneIndex, mat */
        "je .Lf1b5032_001b51f1\n"
        "leal -0x6c(%ebp), %ebx\n" /* line 921 | ent_axis, boneIndex */
        "movl %ebx, 4(%esp)\n" /* boneIndex */
        "leal 0x144(%edi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x138(%edi), %edx\n" /* ent */
        /* { scope 2 */
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x40(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movss 0x1c(%esi), %xmm1\n" /* line 306 | scale */
        /* { scope 3 */
        "movaps %xmm1, %xmm4\n" /* line 272 */
        "mulss (%esi), %xmm4\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss 4(%esi), %xmm6\n"
        "mulss 8(%esi), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm4, %xmm0\n" /* line 308 */
        "mulss (%esi), %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n" /* xx */
        "movss 4(%esi), %xmm3\n" /* line 309 */
        "movaps %xmm4, %xmm5\n"
        "mulss %xmm3, %xmm5\n"
        "movss 8(%esi), %xmm2\n" /* line 310 */
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n" /* xz */
        "movss 0xc(%esi), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm4\n"
        "mulss %xmm6, %xmm3\n" /* line 313 */
        "movss %xmm3, -0x7c(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm7\n" /* line 314 */
        "mulss %xmm2, %xmm7\n"
        "mulss %xmm0, %xmm6\n" /* line 315 */
        "movaps %xmm1, %xmm3\n" /* line 317 */
        "mulss %xmm2, %xmm3\n"
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss %xmm1, -0x8c(%ebp)\n" /* zw */
        "movss -0x7c(%ebp), %xmm0\n" /* line 320 | yy */
        "addss %xmm3, %xmm0\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* axis */
        "movss -0x8c(%ebp), %xmm0\n" /* line 321 | zw */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 322 | xz */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "subss -0x8c(%ebp), %xmm5\n" /* line 324 | zw */
        "movss %xmm5, -0x30(%ebp)\n"
        "addss -0x84(%ebp), %xmm3\n" /* line 325 | xx */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 326 */
        "addss %xmm7, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "addss -0x80(%ebp), %xmm6\n" /* line 328 | xz */
        "movss %xmm6, -0x24(%ebp)\n"
        "subss %xmm4, %xmm7\n" /* line 329 */
        "movss %xmm7, -0x20(%ebp)\n"
        "movss -0x84(%ebp), %xmm1\n" /* line 330 | xx */
        "addss -0x7c(%ebp), %xmm1\n" /* yy */
        "subss %xmm1, %xmm2\n"
        "movss %xmm2, -0x1c(%ebp)\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 925 | tagMat */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* boneIndex */
        "leal -0x3c(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply\n"
        "movl 0x10(%ebp), %eax\n" /* line 926 | tagMat */
        "addl $0x24, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* boneIndex */
        "leal 0x10(%esi), %eax\n" /* mat */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector43\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 928 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xx, xz, yy, zw */
        ".Lf1b5032_001b51f1:\n"
        "xorl %eax, %eax\n" /* line 927 */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 928 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 936 */
__attribute__((naked))
qboolean G_DObjGetWorldTagPos(gentity_t *ent, unsigned int tagName, vec_t *pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 936 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 893 | tagName */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SV_DObjGetBoneIndex\n"
        "movl %eax, %ebx\n" /* boneIndex */
        "testl %eax, %eax\n" /* line 894 */
        "js .Lf1b51fe_001b528f\n"
        "movl %eax, 4(%esp)\n" /* line 898 */
        "movl %esi, (%esp)\n"
        "calll G_DObjCalcBone\n"
        "movl %esi, (%esp)\n" /* line 901 */
        "calll SV_DObjGetMatrixArray\n"
        "shll $5, %ebx\n" /* line 902 | boneIndex */
        /* } scope */
        "movl %eax, %edi\n" /* line 942 | mat */
        "addl %ebx, %edi\n" /* boneIndex, mat */
        "je .Lf1b51fe_001b528f\n"
        "leal -0x48(%ebp), %ebx\n" /* line 945 | ent_axis, boneIndex */
        "movl %ebx, 4(%esp)\n" /* boneIndex */
        "leal 0x144(%esi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x138(%esi), %edx\n" /* ent */
        /* { scope 2 */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 948 | pos */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* boneIndex */
        "leal 0x10(%edi), %eax\n" /* mat */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector43\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 950 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b51fe_001b528f:\n"
        "xorl %eax, %eax\n" /* line 949 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 950 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

