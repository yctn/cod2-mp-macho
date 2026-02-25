/* ASM dump from: g_scr_mover_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_scr_mover_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static const BuiltinMethodDef methods[12]; /* 0x3336c0 */

void ScriptEntCmdGetCommandTimes(float *pfTotalTime, float *pfAccelTime, float *pfDecelTime);
void ScriptEntCmd_Solid(struct scr_entref_t entref);
void ScriptEntCmd_NotSolid(scr_entref_t entref);
BuiltinMethod ScriptEnt_GetMethod(const char * *pName);
void InitScriptMover(gentity_t *pSelf);
void SP_script_origin(gentity_t *pSelf);
void SP_script_model(gentity_t *pSelf);
void SP_script_brushmodel(gentity_t *pSelf);
void ScriptEntCmd_GravityMove(scr_entref_t entref);
void ScriptEntCmd_RotateVelocity(scr_entref_t entref);
static qboolean ScriptMover_Updatemove(const float fSpeed, const vec_t *vPos2, const vec_t *vPos3);
void Reached_ScriptMover(gentity_t *pEnt);
static void ScriptMover_SetupMove(const float fAccelTime, float *pfSpeed, float *pfMidTime, float *pfDecelTime, float (*vPos1)[4], float (*vPos2)[4], float (*vPos3)[4]);
void ScriptEnt_RotateAxis(scr_entref_t entref, int iAxis);
void ScriptEntCmd_RotateRoll(scr_entref_t entref);
void ScriptEntCmd_RotateYaw(scr_entref_t entref);
void ScriptEntCmd_RotatePitch(scr_entref_t entref);
void ScriptEnt_MoveAxis(scr_entref_t entref, int iAxis);
void ScriptEntCmd_MoveZ(scr_entref_t entref);
void ScriptEntCmd_MoveY(scr_entref_t entref);
void ScriptEntCmd_MoveX(scr_entref_t entref);
void ScriptEntCmd_RotateTo(scr_entref_t entref);
void ScriptEntCmd_MoveTo(scr_entref_t entref);

/* line 507 */
__attribute__((naked))
void ScriptEntCmdGetCommandTimes(float *pfTotalTime, float *pfAccelTime, float *pfDecelTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 507 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* pfTotalTime */
        "movl %eax, -0x28(%ebp)\n" /* pfTotalTime */
        "movl 0xc(%ebp), %esi\n" /* pfAccelTime */
        "movl 0x10(%ebp), %edi\n" /* pfDecelTime */
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 511 */
        "calll Scr_GetFloat\n"
        "fstps -0x24(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "movl -0x28(%ebp), %eax\n" /* pfTotalTime */
        "movss %xmm0, (%eax)\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 512 | 0.0f */
        "jbe .Lf1b6164_001b6211\n"
        ".Lf1b6164_001b619d:\n"
        "calll Scr_GetNumParam\n" /* line 515 */
        "movl %eax, %ebx\n" /* iNumParms */
        "cmpl $2, %eax\n" /* line 516 */
        "jg .Lf1b6164_001b61e0\n"
        "pxor %xmm0, %xmm0\n" /* line 535 */
        "movss %xmm0, (%esi)\n" /* pfAccelTime */
        "movss %xmm0, (%edi)\n" /* line 536 | pfDecelTime */
        ".Lf1b6164_001b61b5:\n"
        "movss (%esi), %xmm0\n" /* line 540 | pfAccelTime */
        "addss (%edi), %xmm0\n" /* pfDecelTime */
        "movl -0x28(%ebp), %eax\n" /* pfTotalTime */
        "ucomiss (%eax), %xmm0\n"
        "ja .Lf1b6164_001b61cd\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 542 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b6164_001b61cd:\n"
        "movl $0x2b54a8, 8(%ebp)\n" /* line 541 | pfTotalTime */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 542 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 541 */
        ".Lf1b6164_001b61e0:\n"
        "movl $2, (%esp)\n" /* line 518 */
        "calll Scr_GetFloat\n"
        "fstps -0x20(%ebp)\n"
        "movss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, (%esi)\n" /* pfAccelTime */
        "pxor %xmm0, %xmm0\n" /* line 519 */
        "ucomiss -0x20(%ebp), %xmm0\n"
        "ja .Lf1b6164_001b626b\n"
        ".Lf1b6164_001b6202:\n"
        "cmpl $3, %ebx\n" /* line 522 | iNumParms */
        "jg .Lf1b6164_001b622c\n"
        "pxor %xmm0, %xmm0\n" /* line 530 */
        "movss %xmm0, (%edi)\n" /* pfDecelTime */
        "jmp .Lf1b6164_001b61b5\n"
        ".Lf1b6164_001b6211:\n"
        "jp .Lf1b6164_001b619d\n" /* line 512 */
        "movl $0x2b544c, 4(%esp)\n" /* line 513 */
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b6164_001b619d\n"
        ".Lf1b6164_001b622c:\n"
        "movl $3, (%esp)\n" /* line 524 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, (%edi)\n" /* pfDecelTime */
        "pxor %xmm0, %xmm0\n" /* line 525 */
        "ucomiss -0x1c(%ebp), %xmm0\n"
        "jbe .Lf1b6164_001b61b5\n"
        "movl $0x2b5488, 4(%esp)\n" /* line 526 */
        "movl $3, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b6164_001b61b5\n"
        ".Lf1b6164_001b626b:\n"
        "movl $0x2b5468, 4(%esp)\n" /* line 520 */
        "movl $2, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b6164_001b6202\n"
    );
}

/* line 753 */
__attribute__((naked))
void ScriptEntCmd_Solid(struct scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 753 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 755 */
        "testw %ax, %ax\n"
        "jne .Lf1b6282_001b6332\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl 0x195f688, %ebx\n" /* pSelf */
        "movzwl 0x168(%ebx), %eax\n" /* pSelf */
        "movl 0x195f5bc, %esi\n"
        "cmpw 0x42(%esi), %ax\n"
        "je .Lf1b6282_001b62f1\n"
        "cmpw 0x44(%esi), %ax\n"
        "je .Lf1b6282_001b62f1\n"
        "cmpw 0x46(%esi), %ax\n"
        "je .Lf1b6282_001b6319\n"
        "movl %edx, 4(%esp)\n"
        "movl $0x2b54e0, (%esp)\n" /* "entity %i is not a script_brushmodel, script_model, or scrip" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movzwl 0x168(%ebx), %eax\n" /* pSelf */
        ".Lf1b6282_001b62f1:\n"
        "cmpw 0x46(%esi), %ax\n" /* line 758 */
        "je .Lf1b6282_001b6319\n"
        "cmpw %ax, 0x44(%esi)\n" /* line 764 */
        "je .Lf1b6282_001b634d\n"
        "movl $1, 0x11c(%ebx)\n" /* line 766 | pSelf */
        "andl $0xfffffffe, 8(%ebx)\n" /* line 767 | pSelf */
        "movl %ebx, 8(%ebp)\n" /* line 774 | pSelf, entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 775 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_LinkEntity\n" /* line 774 */
        ".Lf1b6282_001b6319:\n"
        "movl (%ebx), %eax\n" /* line 760 | pSelf */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b5528, (%esp)\n" /* "cannot use the solid/notsolid commands on a script_origin en" */
        "calll Com_DPrintf\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 775 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b6282_001b6332:\n"
        "movl $0x2b21c8, (%esp)\n" /* line 755 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x168, %eax\n"
        "movl 0x195f5bc, %esi\n"
        "jmp .Lf1b6282_001b62f1\n"
        ".Lf1b6282_001b634d:\n"
        "movl $0x2080, 0x11c(%ebx)\n" /* line 771 | pSelf */
        "movl %ebx, 8(%ebp)\n" /* line 774 | pSelf, entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 775 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_LinkEntity\n" /* line 774 */
    );
}

/* line 783 */
__attribute__((naked))
void ScriptEntCmd_NotSolid(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 783 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 785 */
        "testw %ax, %ax\n"
        "jne .Lf1b6366_001b6416\n"
        "movzwl %dx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pSelf */
        "subl %eax, %ebx\n" /* pSelf */
        "shll $4, %ebx\n" /* pSelf */
        "addl 0x195f688, %ebx\n" /* pSelf */
        "movzwl 0x168(%ebx), %eax\n" /* pSelf */
        "movl 0x195f5bc, %esi\n"
        "cmpw 0x42(%esi), %ax\n"
        "je .Lf1b6366_001b63d5\n"
        "cmpw 0x44(%esi), %ax\n"
        "je .Lf1b6366_001b63d5\n"
        "cmpw 0x46(%esi), %ax\n"
        "je .Lf1b6366_001b63fd\n"
        "movl %edx, 4(%esp)\n"
        "movl $0x2b54e0, (%esp)\n" /* "entity %i is not a script_brushmodel, script_model, or scrip" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "movzwl 0x168(%ebx), %eax\n" /* pSelf */
        ".Lf1b6366_001b63d5:\n"
        "cmpw 0x46(%esi), %ax\n" /* line 788 */
        "je .Lf1b6366_001b63fd\n"
        "movl $0, 0x11c(%ebx)\n" /* line 794 | pSelf */
        "cmpw 0x44(%esi), %ax\n" /* line 796 */
        "je .Lf1b6366_001b63ef\n"
        "orl $1, 8(%ebx)\n" /* line 797 | pSelf */
        ".Lf1b6366_001b63ef:\n"
        "movl %ebx, 8(%ebp)\n" /* line 799 | pSelf, entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 800 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_LinkEntity\n" /* line 799 */
        ".Lf1b6366_001b63fd:\n"
        "movl (%ebx), %eax\n" /* line 790 | pSelf */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b5528, (%esp)\n" /* "cannot use the solid/notsolid commands on a script_origin en" */
        "calll Com_DPrintf\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 800 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b6366_001b6416:\n"
        "movl $0x2b21c8, (%esp)\n" /* line 785 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n" /* pSelf */
        "movl 0x168, %eax\n"
        "movl 0x195f5bc, %esi\n"
        "jmp .Lf1b6366_001b63d5\n"
    );
}

/* line 823 */
__attribute__((naked))
BuiltinMethod ScriptEnt_GetMethod(const char * *pName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 823 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 828 | pName */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* name */
        "xorl %esi, %esi\n" /* i */
        "movl $methods, %ebx\n"
        "xorl %edi, %edi\n"
        "movl %eax, %edx\n"
        "jmp .Lf1b6432_001b6453\n"
        ".Lf1b6432_001b6450:\n"
        "movl -0x1c(%ebp), %edx\n" /* name */
        ".Lf1b6432_001b6453:\n"
        "movl (%ebx), %eax\n" /* line 832 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1b6432_001b647d\n"
        "addl $1, %esi\n" /* line 830 | i */
        "addl $0xc, %edi\n"
        "addl $0xc, %ebx\n"
        "cmpl $0xc, %esi\n" /* i */
        "jne .Lf1b6432_001b6450\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 839 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b6432_001b647d:\n"
        "movl methods(%edi), %eax\n" /* line 834 */
        "movl 8(%ebp), %edx\n" /* pName */
        "movl %eax, (%edx)\n"
        "movl 0x3336c4(%edi), %eax\n" /* line 835 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 839 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 390 */
__attribute__((naked))
void InitScriptMover(gentity_t *pSelf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 390 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* pSelf */
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 396 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1b6496_001b651f\n"
        ".Lf1b6496_001b64af:\n"
        "movb $5, 0x166(%esi)\n" /* line 425 | pSelf */
        "movb $0, 0xf2(%esi)\n" /* line 427 | pSelf */
        "movl $6, 4(%esi)\n" /* line 428 | pSelf */
        "leal 0x18(%esi), %ecx\n" /* line 430 | pSelf, to */
        "leal 0x138(%esi), %edx\n" /* pSelf, from */
        /* { scope 2 */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x18(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0, 0xc(%esi)\n" /* line 431 | pSelf */
        "leal 0x3c(%esi), %ecx\n" /* line 433 | pSelf, to */
        "leal 0x144(%esi), %edx\n" /* pSelf, from */
        /* { scope 2 */
        "movl 0x144(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x3c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0, 0x30(%esi)\n" /* line 434 | pSelf */
        "orl $__mh_execute_header, 0x174(%esi)\n" /* line 436 | pSelf */
        /* } scope */
        "addl $0x20, %esp\n" /* line 437 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b6496_001b651f:\n"
        "leal -0xc(%ebp), %eax\n" /* line 399 | fLight */
        "movl %eax, 8(%esp)\n"
        "movl $0x2b5578, 4(%esp)\n" /* "100" */
        "movl $0x219e40, (%esp)\n" /* "light" */
        "calll G_SpawnFloat\n"
        "movl %eax, %ebx\n" /* bLightSet */
        "leal -0x18(%ebp), %eax\n" /* line 400 | vColor */
        "movl %eax, 8(%esp)\n"
        "movl $0x224ddc, 4(%esp)\n" /* "1 1 1" */
        "movl $0x2278dc, (%esp)\n" /* "color" */
        "calll G_SpawnVector\n"
        "testl %ebx, %ebx\n" /* line 401 | bLightSet */
        "jne .Lf1b6496_001b6563\n"
        "testl %eax, %eax\n"
        "je .Lf1b6496_001b64af\n"
        /* { scope 2 */
        ".Lf1b6496_001b6563:\n"
        "movss 0x2ed5d4, %xmm1\n" /* line 405 | 255.0f */
        "movss -0x18(%ebp), %xmm0\n" /* vColor */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "cmpl $0x100, %edx\n" /* line 406 */
        "movl $0xff, %eax\n"
        "cmovgel %eax, %edx\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 409 */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "cmpl $0xff, %eax\n" /* line 410 */
        "jle .Lf1b6496_001b65e5\n"
        "movl $0xff00, %ebx\n" /* bLightSet */
        "movaps %xmm1, %xmm0\n" /* line 413 */
        "mulss -0x10(%ebp), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "cmpl $0xff, %eax\n" /* line 414 */
        "jle .Lf1b6496_001b65fd\n"
        ".Lf1b6496_001b65b2:\n"
        "movl $0xff0000, %ecx\n"
        "movss 0x2ed604, %xmm0\n" /* line 417 | 0.25f */
        "mulss -0xc(%ebp), %xmm0\n" /* fLight */
        "cvttss2si %xmm0, %eax\n"
        "cmpl $0xff, %eax\n" /* line 418 */
        "jle .Lf1b6496_001b661a\n"
        ".Lf1b6496_001b65cf:\n"
        "movl $0xff000000, %eax\n"
        ".Lf1b6496_001b65d4:\n"
        "orl %ebx, %edx\n" /* line 421 | bLightSet */
        "orl %ecx, %edx\n"
        "orl %eax, %edx\n"
        "movl %edx, 0x80(%esi)\n" /* pSelf */
        "jmp .Lf1b6496_001b64af\n"
        ".Lf1b6496_001b65e5:\n"
        "movl %eax, %ebx\n" /* line 410 | bLightSet */
        "shll $8, %ebx\n" /* bLightSet */
        "movaps %xmm1, %xmm0\n" /* line 413 */
        "mulss -0x10(%ebp), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "cmpl $0xff, %eax\n" /* line 414 */
        "jg .Lf1b6496_001b65b2\n"
        ".Lf1b6496_001b65fd:\n"
        "movl %eax, %ecx\n"
        "shll $0x10, %ecx\n"
        "movss 0x2ed604, %xmm0\n" /* line 417 | 0.25f */
        "mulss -0xc(%ebp), %xmm0\n" /* fLight */
        "cvttss2si %xmm0, %eax\n"
        "cmpl $0xff, %eax\n" /* line 418 */
        "jg .Lf1b6496_001b65cf\n"
        ".Lf1b6496_001b661a:\n"
        "shll $0x18, %eax\n"
        "jmp .Lf1b6496_001b65d4\n"
    );
}

/* line 463 */
__attribute__((naked))
void SP_script_origin(gentity_t *pSelf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 463 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        "movl %ebx, (%esp)\n" /* line 465 | pSelf */
        "calll InitScriptMover\n"
        "movl $0, 0x11c(%ebx)\n" /* line 466 | pSelf */
        "movl %ebx, (%esp)\n" /* line 467 | pSelf */
        "calll SV_LinkEntity\n"
        "movl 0x80(%ebx), %eax\n" /* line 469 | pSelf */
        "testl %eax, %eax\n"
        "je .Lf1b6620_001b6658\n"
        "orl $0x20, 8(%ebx)\n" /* line 470 | pSelf */
        "addl $0x14, %esp\n" /* line 473 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b6620_001b6658:\n"
        "orb $1, 0xf2(%ebx)\n" /* line 472 | pSelf */
        "addl $0x14, %esp\n" /* line 473 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 452 */
__attribute__((naked))
void SP_script_model(gentity_t *pSelf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 452 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        "movl %ebx, (%esp)\n" /* line 454 | pSelf */
        "calll G_DObjUpdate\n"
        "movl %ebx, (%esp)\n" /* line 456 | pSelf */
        "calll InitScriptMover\n"
        "orb $4, 0xf2(%ebx)\n" /* line 457 | pSelf */
        "movl $0x2080, 0x11c(%ebx)\n" /* line 458 | pSelf */
        "movl %ebx, 8(%ebp)\n" /* line 459 | pSelf */
        "addl $0x14, %esp\n" /* line 460 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SV_LinkEntity\n" /* line 459 */
    );
}

/* line 442 */
__attribute__((naked))
void SP_script_brushmodel(gentity_t *pSelf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 442 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        "movl %ebx, (%esp)\n" /* line 444 | pSelf */
        "calll SV_SetBrushModel\n"
        "movl %ebx, (%esp)\n" /* line 446 | pSelf */
        "calll InitScriptMover\n"
        "movl $1, 0x11c(%ebx)\n" /* line 447 | pSelf */
        "movl %ebx, 8(%ebp)\n" /* line 448 | pSelf */
        "addl $0x14, %esp\n" /* line 449 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SV_LinkEntity\n" /* line 448 */
    );
}

/* line 570 */
__attribute__((naked))
void ScriptEntCmd_GravityMove(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 570 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 575 */
        "testw %ax, %ax\n"
        "jne .Lf1b66d0_001b67e1\n"
        "movzwl %dx, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %edi\n" /* pSelf */
        "subl %eax, %edi\n" /* pSelf */
        "shll $4, %edi\n" /* pSelf */
        "addl 0x195f688, %edi\n" /* pSelf */
        "movzwl 0x168(%edi), %eax\n" /* pSelf */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x42(%edx), %ax\n"
        "je .Lf1b66d0_001b6739\n"
        "cmpw 0x44(%edx), %ax\n"
        "je .Lf1b66d0_001b6739\n"
        "cmpw 0x46(%edx), %ax\n"
        "je .Lf1b66d0_001b6739\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x2b54e0, (%esp)\n" /* "entity %i is not a script_brushmodel, script_model, or scrip" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        ".Lf1b66d0_001b6739:\n"
        "leal -0x24(%ebp), %eax\n" /* line 577 | vVel */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $1, (%esp)\n" /* line 578 */
        "calll Scr_GetFloat\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        /* { scope 2 */
        "leal 0xc(%edi), %ebx\n" /* line 338 | pTr */
        "movl 0x195f6a0, %esi\n" /* line 341 */
        "movl 0x1ec(%esi), %eax\n"
        "movl %eax, 4(%ebx)\n" /* pTr */
        "mulss 0x2ed5c8, %xmm0\n" /* line 342 | 1000.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 8(%ebx)\n" /* pTr */
        "leal 0x18(%edi), %ecx\n" /* line 344 | to */
        "leal 0x138(%edi), %edx\n"
        /* { scope 3 */
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x18(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x24(%edi), %ecx\n" /* line 345 | to */
        /* { scope 3 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | vVel */
        "movl %eax, 0x24(%edi)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $5, 0xc(%edi)\n" /* line 346 */
        "movl %edx, 8(%esp)\n" /* line 347 */
        "movl 0x1ec(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pTr */
        "calll BG_EvaluateTrajectory\n"
        "movl %edi, (%esp)\n" /* line 349 */
        "calll SV_LinkEntity\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 580 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b66d0_001b67e1:\n"
        "movl $0x2b21c8, (%esp)\n" /* line 575 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n" /* pSelf */
        "jmp .Lf1b66d0_001b6739\n"
    );
}

/* line 732 */
__attribute__((naked))
void ScriptEntCmd_RotateVelocity(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 732 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1: pfDecelTime, pfMidTime, pfSpeed, fDecelTime */
        "shrl $0x10, %eax\n" /* line 739 */
        "testw %ax, %ax\n"
        "jne .Lf1b67f4_001b6ba0\n"
        "movzwl %dx, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl 0x195f688, %esi\n" /* pSelf */
        "movzwl 0x168(%esi), %eax\n" /* pSelf */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x42(%edx), %ax\n"
        "je .Lf1b67f4_001b6860\n"
        "cmpw 0x44(%edx), %ax\n"
        "je .Lf1b67f4_001b6860\n"
        "cmpw 0x46(%edx), %ax\n"
        "je .Lf1b67f4_001b6860\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x2b54e0, (%esp)\n" /* "entity %i is not a script_brushmodel, script_model, or scrip" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        ".Lf1b67f4_001b6860:\n"
        "leal -0x30(%ebp), %eax\n" /* line 741 | vSpeed */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x24(%ebp), %eax\n" /* line 742 | fDecelTime */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* fAccelTime */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* fTotalTime */
        "movl %eax, (%esp)\n"
        "calll ScriptEntCmdGetCommandTimes\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 744 | fDecelTime */
        "movss %xmm0, -0x70(%ebp)\n" /* fDecelTime */
        "movss -0x20(%ebp), %xmm3\n" /* fAccelTime */
        "movss -0x1c(%ebp), %xmm1\n" /* fTotalTime */
        "leal 0x1fc(%esi), %eax\n" /* line 377 */
        "movl %eax, -0x5c(%ebp)\n" /* to */
        "leal 0x1f0(%esi), %edx\n"
        "movl %edx, -0x60(%ebp)\n" /* result */
        "leal 0x1e4(%esi), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* to */
        "leal 0x1ac(%esi), %edx\n"
        "movl %edx, -0x7c(%ebp)\n" /* pfDecelTime */
        "leal 0x1bc(%esi), %eax\n"
        "movl %eax, -0x78(%ebp)\n" /* pfMidTime */
        "leal 0x1b4(%esi), %edx\n"
        "movl %edx, -0x74(%ebp)\n" /* pfSpeed */
        "leal 0x144(%esi), %ebx\n" /* vCurrPos */
        "leal 0x30(%esi), %edi\n" /* pTr */
        /* { scope 2: to, result, to, tr */
        "movl 0x30(%esi), %edx\n" /* line 223 */
        "testl %edx, %edx\n"
        "jne .Lf1b67f4_001b6bb3\n"
        ".Lf1b67f4_001b68ea:\n"
        "pxor %xmm4, %xmm4\n" /* line 227 */
        "ucomiss %xmm4, %xmm3\n"
        "jne .Lf1b67f4_001b6903\n"
        "jp .Lf1b67f4_001b6903\n"
        "movss -0x70(%ebp), %xmm0\n" /* fDecelTime */
        "ucomiss %xmm4, %xmm0\n"
        "je .Lf1b67f4_001b6ae4\n"
        ".Lf1b67f4_001b6903:\n"
        "subss %xmm3, %xmm1\n" /* line 247 */
        "subss -0x70(%ebp), %xmm1\n" /* fDecelTime */
        "movl -0x78(%ebp), %eax\n" /* pfMidTime */
        "movss %xmm1, (%eax)\n"
        "movss -0x70(%ebp), %xmm0\n" /* line 248 | fDecelTime */
        "movl -0x7c(%ebp), %edx\n" /* pfDecelTime */
        "movss %xmm0, (%edx)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 324 | vSpeed */
        "movss -0x2c(%ebp), %xmm1\n"
        "movss -0x28(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "movl -0x74(%ebp), %eax\n" /* pfSpeed */
        "movss %xmm0, (%eax)\n"
        "ucomiss %xmm4, %xmm3\n" /* line 253 */
        "jp .Lf1b67f4_001b6bf3\n"
        "jne .Lf1b67f4_001b6bf3\n"
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl -0x6c(%ebp), %edx\n" /* to */
        "movl %eax, (%edx)\n"
        "leal 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0x68(%ebp)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "leal 8(%ebx), %edx\n" /* line 201 */
        "movl %edx, -0x64(%ebp)\n"
        "movl 8(%ebx), %eax\n"
        "movl -0x6c(%ebp), %edx\n" /* to */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl -0x78(%ebp), %eax\n" /* line 268 | pfMidTime */
        "ucomiss (%eax), %xmm4\n"
        "jp .Lf1b67f4_001b6a8b\n"
        "jne .Lf1b67f4_001b6a8b\n"
        "movl 0x195f6a0, %ecx\n" /* line 279 */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 280 | 1000.0f */
        "movl -0x7c(%ebp), %eax\n" /* pfDecelTime */
        "mulss (%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 8(%edi)\n"
        "leal 0xc(%edi), %edx\n" /* line 282 | to */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0xc(%edi)\n"
        "movl -0x68(%ebp), %eax\n" /* line 200 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movl -0x64(%ebp), %eax\n" /* line 201 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0x18(%edi), %edx\n" /* line 283 | to */
        /* { scope 3 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | vSpeed */
        "movl %eax, 0x18(%edi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $8, (%edi)\n" /* line 284 */
        ".Lf1b67f4_001b69f0:\n"
        "movl -0x78(%ebp), %eax\n" /* line 289 | pfMidTime */
        "movss (%eax), %xmm0\n" /* scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 288 */
        "mulss -0x30(%ebp), %xmm1\n" /* vSpeed */
        "movl -0x6c(%ebp), %edx\n" /* to */
        "addss (%edx), %xmm1\n"
        "movl -0x60(%ebp), %eax\n" /* result */
        "movss %xmm1, (%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 289 | scale */
        "mulss -0x2c(%ebp), %xmm1\n"
        "addss 4(%edx), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss -0x28(%ebp), %xmm0\n" /* line 290 */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movl -0x7c(%ebp), %edx\n" /* line 292 | pfDecelTime */
        "ucomiss (%edx), %xmm4\n"
        "jp .Lf1b67f4_001b6c71\n"
        "jne .Lf1b67f4_001b6c71\n"
        /* { scope 3 */
        "movl -0x60(%ebp), %edx\n" /* line 199 | result */
        "movl (%edx), %eax\n"
        "movl -0x5c(%ebp), %edx\n" /* to */
        "movl %eax, (%edx)\n"
        "movl -0x60(%ebp), %edx\n" /* line 200 | result */
        "movl 4(%edx), %eax\n"
        "movl -0x5c(%ebp), %edx\n" /* to */
        "movl %eax, 4(%edx)\n"
        "movl -0x60(%ebp), %edx\n" /* line 201 | result */
        "movl 8(%edx), %eax\n"
        "movl -0x5c(%ebp), %edx\n" /* to */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lf1b67f4_001b6a62:\n"
        "movl %ebx, 8(%esp)\n" /* line 309 */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 379 */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 745 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pfDecelTime, pfMidTime, pfSpeed, fDecelTime */
        /* { scope 2: to, result, to, tr */
        ".Lf1b67f4_001b6a8b:\n"
        "movl 0x195f6a0, %ecx\n" /* line 270 */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 271 | 1000.0f */
        "movl -0x78(%ebp), %edx\n" /* pfMidTime */
        "mulss (%edx), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 8(%edi)\n"
        "leal 0xc(%edi), %edx\n" /* line 273 | to */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0xc(%edi)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x18(%edi), %edx\n" /* line 274 | to */
        /* { scope 3 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | vSpeed */
        "movl %eax, 0x18(%edi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $3, (%edi)\n" /* line 275 */
        "jmp .Lf1b67f4_001b69f0\n"
        ".Lf1b67f4_001b6ae4:\n"
        "jp .Lf1b67f4_001b6903\n" /* line 227 */
        "movl 0x195f6a0, %edx\n" /* line 230 */
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 231 */
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 8(%edi)\n"
        "movss %xmm1, 0x1bc(%esi)\n" /* line 233 */
        "movss %xmm4, 0x1ac(%esi)\n" /* line 234 */
        "leal 0x3c(%esi), %edx\n" /* line 236 | to */
        /* { scope 3 */
        "movl 0x144(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x3c(%esi)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x48(%esi), %edx\n" /* line 237 | to */
        /* { scope 3 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | vSpeed */
        "movl %eax, 0x48(%esi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $3, 0x30(%esi)\n" /* line 238 */
        "movl %ebx, 8(%esp)\n" /* line 240 */
        "movl 0x195f6a0, %edx\n"
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl -0x5c(%ebp), %eax\n" /* line 241 | to */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f6a0, %edx\n"
        "movl 0x1ec(%edx), %eax\n"
        "addl 8(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 379 */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 745 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pfDecelTime, pfMidTime, pfSpeed, fDecelTime */
        ".Lf1b67f4_001b6ba0:\n"
        "movl $0x2b21c8, (%esp)\n" /* line 739 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1b67f4_001b6860\n"
        /* { scope 2: to, result, to, tr */
        ".Lf1b67f4_001b6bb3:\n"
        "movl %ebx, 8(%esp)\n" /* line 224 */
        "movl 0x195f6a0, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "movss %xmm3, -0xa8(%ebp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movss -0xa8(%ebp), %xmm3\n"
        "movss -0x98(%ebp), %xmm1\n"
        "jmp .Lf1b67f4_001b68ea\n"
        ".Lf1b67f4_001b6bf3:\n"
        "movl 0x195f6a0, %edx\n" /* line 255 */
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, 4(%edi)\n"
        "mulss 0x2ed5c8, %xmm3\n" /* line 256 | 1000.0f */
        "cvttss2si %xmm3, %eax\n"
        "movl %eax, 8(%edi)\n"
        "leal 0xc(%edi), %edx\n" /* line 257 | to */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0xc(%edi)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x18(%edi), %edx\n" /* line 258 | to */
        /* { scope 3 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | vSpeed */
        "movl %eax, 0x18(%edi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $7, (%edi)\n" /* line 259 */
        "movl -0x6c(%ebp), %eax\n" /* line 262 | to */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f6a0, %edx\n"
        "movl 0x1ec(%edx), %eax\n"
        "addl 8(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl 0x195f6a0, %ecx\n"
        "pxor %xmm4, %xmm4\n"
        "jmp .Lf1b67f4_001b69f0\n"
        /* { scope 3 */
        ".Lf1b67f4_001b6c71:\n"
        "movl $8, -0x54(%ebp)\n" /* line 296 | tr */
        "movl 0x1ec(%ecx), %eax\n" /* line 297 */
        "movl %eax, -0x50(%ebp)\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 298 | 1000.0f */
        "mulss (%edx), %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl -0x60(%ebp), %eax\n" /* line 199 | result */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "movss 4(%eax), %xmm0\n" /* line 200 */
        "movss %xmm0, -0x44(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x40(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 199 | vSpeed */
        "movl %eax, -0x3c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x5c(%ebp), %eax\n" /* line 301 | to */
        "movl %eax, 8(%esp)\n"
        "addl 0x1ec(%ecx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl 0x195f6a0, %ecx\n"
        "jmp .Lf1b67f4_001b6a62\n"
    );
}

/* line 13 */
static __attribute__((naked))
qboolean ScriptMover_Updatemove(const float fSpeed, const vec_t *vPos2, const vec_t *vPos3)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 13 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ebx\n" /* pTr */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* vPos3 */
        /* { scope 1 */
        "movss 0x2ed5c8, %xmm3\n" /* line 19 | 1000.0f */
        "mulss %xmm3, %xmm1\n" /* fMidTime */
        "cvttss2si %xmm1, %esi\n" /* fMidTime, trDuration */
        "movl (%eax), %eax\n" /* line 23 */
        "cmpl $7, %eax\n"
        "je .Lf1b6cee_001b6d5f\n"
        "cmpl $3, %eax\n" /* line 37 */
        "je .Lf1b6cee_001b6dfc\n"
        ".Lf1b6cee_001b6d21:\n"
        "cmpl $5, %eax\n" /* line 52 */
        "je .Lf1b6cee_001b6ebd\n"
        "leal 0xc(%ebx), %edx\n" /* line 55 | pTr, to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | vPos3 */
        "movl %eax, 0xc(%ebx)\n" /* pTr */
        "movl 4(%edi), %eax\n" /* line 200 | vPos3 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 201 | vPos3 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lf1b6cee_001b6d3e:\n"
        "movl 0x195f6a0, %eax\n" /* line 57 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%ebx)\n" /* pTr */
        "movl $0, (%ebx)\n" /* line 58 | pTr */
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1b6cee_001b6d57:\n"
        "addl $0x3c, %esp\n" /* line 65 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b6cee_001b6d5f:\n"
        "testl %esi, %esi\n" /* line 23 | trDuration */
        "jle .Lf1b6cee_001b6dfc\n"
        "movl 0x195f6a0, %eax\n" /* line 26 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%ebx)\n" /* pTr */
        "movl %esi, 8(%ebx)\n" /* line 27 | trDuration, pTr */
        "leal 0xc(%ebx), %edx\n" /* line 29 | pTr, to */
        /* { scope 2 */
        "movl (%ecx), %eax\n" /* line 199 | vPos1 */
        "movl %eax, 0xc(%ebx)\n" /* pTr */
        "movl 4(%ecx), %eax\n" /* line 200 | vPos1 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 | vPos1 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 248 | vPos2 */
        "movss (%eax), %xmm0\n"
        "subss (%ecx), %xmm0\n" /* vPos1 */
        "movss %xmm0, -0x24(%ebp)\n" /* vMove */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%ecx), %xmm0\n" /* vPos1 */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%ecx), %xmm0\n" /* vPos1 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "cvtsi2ssl %esi, %xmm1\n" /* line 32 | trDuration, fMidTime */
        "movaps %xmm3, %xmm0\n"
        "divss %xmm1, %xmm0\n" /* fMidTime */
        "leal 0x18(%ebx), %eax\n" /* line 33 | pTr, result */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 | fMidTime */
        "mulss -0x24(%ebp), %xmm1\n" /* vMove, fMidTime */
        "movss %xmm1, 0x18(%ebx)\n" /* fMidTime, pTr */
        "movaps %xmm0, %xmm1\n" /* line 273 | fMidTime */
        "mulss -0x20(%ebp), %xmm1\n" /* fMidTime */
        "movss %xmm1, 4(%eax)\n" /* fMidTime */
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movl $3, (%ebx)\n" /* line 34 | pTr */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 65 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b6cee_001b6dfc:\n"
        "ucomiss 0x2ed5e8, %xmm2\n" /* line 37 | 0.0f, fDecelTime */
        "jbe .Lf1b6cee_001b6d21\n"
        "movl 0x195f6a0, %eax\n" /* line 40 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%ebx)\n" /* pTr */
        "mulss %xmm3, %xmm2\n" /* line 41 | fDecelTime */
        "cvttss2si %xmm2, %eax\n" /* fDecelTime */
        "movl %eax, 8(%ebx)\n" /* pTr */
        "leal 0xc(%ebx), %edx\n" /* line 42 | pTr, to */
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 199 | vPos2, vPos1 */
        "movl (%ecx), %eax\n" /* vPos1 */
        "movl %eax, 0xc(%ebx)\n" /* pTr */
        "movl 4(%ecx), %eax\n" /* line 200 | vPos1 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 | vPos1 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movss (%edi), %xmm0\n" /* line 248 | vPos3 */
        "subss (%ecx), %xmm0\n" /* vPos1 */
        "movss %xmm0, -0x24(%ebp)\n" /* vMove */
        "movss 4(%edi), %xmm0\n" /* line 249 | vPos3 */
        "subss 4(%ecx), %xmm0\n" /* vPos1 */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | vPos3 */
        "subss 8(%ecx), %xmm0\n" /* vPos1 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 44 | vMove */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x2c(%ebp), %xmm2\n" /* line 272 | fDecelTime */
        "mulss -0x24(%ebp), %xmm2\n" /* vMove, fDecelTime */
        "movss %xmm2, -0x24(%ebp)\n" /* fDecelTime, vMove */
        "movss -0x2c(%ebp), %xmm1\n" /* line 273 | fMidTime */
        "mulss -0x20(%ebp), %xmm1\n" /* fMidTime */
        "movss %xmm1, -0x20(%ebp)\n" /* fMidTime */
        "movss -0x2c(%ebp), %xmm0\n" /* line 274 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal 0x18(%ebx), %eax\n" /* line 46 | pTr, to */
        /* { scope 2 */
        "movss %xmm2, 0x18(%ebx)\n" /* line 199 | fDecelTime, pTr */
        "movss %xmm1, 4(%eax)\n" /* line 200 | fMidTime */
        "movss %xmm0, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl $8, (%ebx)\n" /* line 47 | pTr */
        "xorl %eax, %eax\n"
        "jmp .Lf1b6cee_001b6d57\n"
        ".Lf1b6cee_001b6ebd:\n"
        "leal 0xc(%ebx), %eax\n" /* line 53 | pTr */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f6a0, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pTr */
        "calll BG_EvaluateTrajectory\n"
        "jmp .Lf1b6cee_001b6d3e\n"
    );
}

/* line 75 */
__attribute__((naked))
void Reached_ScriptMover(gentity_t *pEnt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 79 | pEnt */
        "movl 0xc(%eax), %ebx\n" /* bMoveFinished */
        "testl %ebx, %ebx\n" /* bMoveFinished */
        "je .Lf1b6ee0_001b6f10\n"
        "movl %eax, %edx\n"
        "movl 0x10(%eax), %eax\n"
        "addl 0x14(%edx), %eax\n"
        "movl 0x195f6a0, %edx\n"
        "cmpl 0x1ec(%edx), %eax\n"
        "jle .Lf1b6ee0_001b702c\n"
        ".Lf1b6ee0_001b6f0d:\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        ".Lf1b6ee0_001b6f10:\n"
        "movl 0x30(%eax), %ecx\n" /* line 90 */
        "testl %ecx, %ecx\n"
        "je .Lf1b6ee0_001b6f2d\n"
        "movl %eax, %edx\n"
        "movl 0x34(%eax), %eax\n"
        "addl 0x38(%edx), %eax\n"
        "movl 0x195f6a0, %edx\n"
        "cmpl 0x1ec(%edx), %eax\n"
        "jle .Lf1b6ee0_001b6f35\n"
        /* } scope */
        ".Lf1b6ee0_001b6f2d:\n"
        "addl $0x1c, %esp\n" /* line 106 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b6ee0_001b6f35:\n"
        "movl 8(%ebp), %esi\n" /* line 92 | pEnt */
        "addl $0x144, %esi\n"
        "movl 8(%ebp), %edi\n" /* pEnt */
        "addl $0x30, %edi\n"
        "movl 8(%ebp), %ecx\n" /* pEnt */
        "addl $0x1e4, %ecx\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "movss 0x1ac(%eax), %xmm2\n"
        "movss 0x1bc(%eax), %xmm1\n"
        "movss 0x1b4(%eax), %xmm0\n"
        "addl $0x1fc, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "addl $0x1f0, %eax\n"
        "movl %eax, (%esp)\n"
        "movl %esi, %edx\n"
        "movl %edi, %eax\n"
        "calll ScriptMover_Updatemove\n"
        "movl %eax, %ebx\n" /* bMoveFinished */
        "movl %esi, 8(%esp)\n" /* line 94 */
        "movl 0x195f6a0, %edx\n"
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl 8(%ebp), %eax\n" /* line 95 | pEnt */
        "movl %eax, (%esp)\n"
        "calll SV_LinkEntity\n"
        "testl %ebx, %ebx\n" /* line 97 | bMoveFinished */
        "je .Lf1b6ee0_001b6f2d\n"
        "movl 8(%ebp), %edx\n" /* line 99 | pEnt */
        "movl 0x144(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleNormalize180\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "fstps 0x144(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 100 | pEnt */
        "movl 0x148(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleNormalize360\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "fstps 0x148(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 101 | pEnt */
        "movl 0x14c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleNormalize180\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "fstps 0x14c(%eax)\n"
        "movl $0, 8(%esp)\n" /* line 103 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x40(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* pEnt */
        "movl %edx, (%esp)\n"
        "calll Scr_Notify\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 106 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b6ee0_001b702c:\n"
        "movl 8(%ebp), %esi\n" /* line 81 | pEnt */
        "addl $0x138, %esi\n"
        "movl 8(%ebp), %edi\n" /* pEnt */
        "addl $0xc, %edi\n"
        "movl 8(%ebp), %ecx\n" /* pEnt */
        "addl $0x1c0, %ecx\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "movss 0x1a8(%eax), %xmm2\n"
        "movss 0x1b8(%eax), %xmm1\n"
        "movss 0x1b0(%eax), %xmm0\n"
        "addl $0x1d8, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "addl $0x1cc, %eax\n"
        "movl %eax, (%esp)\n"
        "movl %esi, %edx\n"
        "movl %edi, %eax\n"
        "calll ScriptMover_Updatemove\n"
        "movl %eax, %ebx\n" /* bMoveFinished */
        "movl %esi, 8(%esp)\n" /* line 83 */
        "movl 0x195f6a0, %edx\n"
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl 8(%ebp), %eax\n" /* line 84 | pEnt */
        "movl %eax, (%esp)\n"
        "calll SV_LinkEntity\n"
        "testl %ebx, %ebx\n" /* line 86 | bMoveFinished */
        "je .Lf1b6ee0_001b6f0d\n"
        "movl $0, 8(%esp)\n" /* line 87 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x28(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* pEnt */
        "movl %edx, (%esp)\n"
        "calll Scr_Notify\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "jmp .Lf1b6ee0_001b6f10\n"
    );
}

/* line 118 */
static __attribute__((naked))
void ScriptMover_SetupMove(const float fAccelTime, float *pfSpeed, float *pfMidTime, float *pfDecelTime, float (*vPos1)[4], float (*vPos2)[4], float (*vPos3)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 118 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, %esi\n" /* pTr */
        "movl %edx, %ebx\n" /* vPos */
        "movaps %xmm0, %xmm3\n" /* fTotalTime */
        "movss %xmm1, -0x4c(%ebp)\n"
        "movaps %xmm2, %xmm4\n" /* fDecelTime */
        "movl %ecx, %edi\n" /* vCurrPos */
        /* { scope 1 */
        "movss (%edx), %xmm0\n" /* line 248 */
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* vMove */
        "leal 4(%edx), %eax\n" /* line 249 */
        "movl %eax, -0x48(%ebp)\n"
        "leal 4(%ecx), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "movss 4(%ebx), %xmm0\n" /* vPos */
        "subss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "leal 8(%ebx), %ecx\n" /* line 250 | vPos */
        "movl %ecx, -0x40(%ebp)\n"
        "leal 8(%edi), %eax\n" /* vCurrPos */
        "movl %eax, -0x3c(%ebp)\n"
        "movss 8(%ebx), %xmm0\n" /* vPos */
        "subss 8(%edi), %xmm0\n" /* vCurrPos */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl (%esi), %eax\n" /* line 128 | pTr */
        "testl %eax, %eax\n"
        "jne .Lf1b70d6_001b746b\n"
        "movaps %xmm1, %xmm0\n"
        ".Lf1b70d6_001b7140:\n"
        "pxor %xmm2, %xmm2\n" /* line 132 */
        "ucomiss %xmm2, %xmm0\n"
        "jne .Lf1b70d6_001b7154\n"
        "jp .Lf1b70d6_001b7154\n"
        "ucomiss %xmm2, %xmm4\n" /* fDecelTime */
        "je .Lf1b70d6_001b73b7\n"
        ".Lf1b70d6_001b7154:\n"
        "movaps %xmm3, %xmm0\n" /* line 153 | fTotalTime */
        "subss -0x4c(%ebp), %xmm0\n"
        "subss %xmm4, %xmm0\n" /* fDecelTime */
        "movl 0xc(%ebp), %ecx\n" /* pfMidTime */
        "movss %xmm0, (%ecx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 154 | pfDecelTime */
        "movss %xmm4, (%eax)\n" /* fDecelTime */
        "movss -0x24(%ebp), %xmm0\n" /* line 324 | vMove */
        "movss -0x20(%ebp), %xmm1\n"
        "movss -0x1c(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "addss %xmm3, %xmm3\n"
        "subss -0x4c(%ebp), %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "divss %xmm3, %xmm0\n"
        "movl 8(%ebp), %edx\n" /* pfSpeed */
        "movss %xmm0, (%edx)\n"
        "leal -0x30(%ebp), %eax\n" /* line 159 | vMaxSpeed */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* vMove */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movl 8(%ebp), %ecx\n" /* line 160 | pfSpeed */
        "movss (%ecx), %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm3\n" /* line 272 | fTotalTime */
        "mulss -0x30(%ebp), %xmm3\n" /* vMaxSpeed, fTotalTime */
        "movss %xmm3, -0x30(%ebp)\n" /* fTotalTime, vMaxSpeed */
        "movaps %xmm0, %xmm2\n" /* line 273 */
        "mulss -0x2c(%ebp), %xmm2\n"
        "movss %xmm2, -0x2c(%ebp)\n"
        "mulss -0x28(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "pxor %xmm1, %xmm1\n" /* line 163 */
        "movss -0x4c(%ebp), %xmm4\n" /* fDecelTime */
        "ucomiss %xmm1, %xmm4\n" /* fDecelTime */
        "jp .Lf1b70d6_001b74a4\n"
        "jne .Lf1b70d6_001b74a4\n"
        "movl (%edi), %eax\n" /* line 199 | vCurrPos */
        "movl 0x14(%ebp), %ecx\n" /* vPos1 */
        "movl %eax, (%ecx)\n"
        "movl -0x44(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl 0x14(%ebp), %edx\n" /* vPos1 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 178 | pfMidTime */
        "ucomiss (%ecx), %xmm1\n"
        "jp .Lf1b70d6_001b7230\n"
        "je .Lf1b70d6_001b7352\n"
        ".Lf1b70d6_001b7230:\n"
        "movl 0x195f6a0, %ecx\n" /* line 180 */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%esi)\n" /* pTr */
        "movss 0x2ed5c8, %xmm2\n" /* line 181 | 1000.0f */
        "movl 0xc(%ebp), %eax\n" /* pfMidTime */
        "movss (%eax), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 8(%esi)\n" /* pTr */
        "leal 0xc(%esi), %edx\n" /* line 183 | pTr, to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | vCurrPos */
        "movl %eax, 0xc(%esi)\n" /* pTr */
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 201 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 184 | pfMidTime */
        "movss (%eax), %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x30(%ebp), %xmm1\n" /* vMaxSpeed */
        "movss %xmm1, -0x24(%ebp)\n" /* vMove */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x2c(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss -0x28(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "cvtsi2ssl 8(%esi), %xmm0\n" /* line 186 | pTr */
        "divss %xmm0, %xmm2\n"
        "leal 0x18(%esi), %eax\n" /* line 187 | pTr, result */
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm0\n" /* vMove */
        "movss %xmm0, 0x18(%esi)\n" /* pTr */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss -0x1c(%ebp), %xmm2\n" /* line 274 */
        "movss %xmm2, 8(%eax)\n"
        /* } scope */
        "movl $3, (%esi)\n" /* line 188 | pTr */
        ".Lf1b70d6_001b72d9:\n"
        "movl 0xc(%ebp), %eax\n" /* line 203 | pfMidTime */
        "movss (%eax), %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x30(%ebp), %xmm0\n" /* vMaxSpeed */
        "movl 0x14(%ebp), %edx\n" /* vPos1 */
        "addss (%edx), %xmm0\n"
        "movl 0x18(%ebp), %eax\n" /* vPos2 */
        "movss %xmm0, (%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss -0x28(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "movl (%ebx), %eax\n" /* line 199 | vPos */
        "movl 0x1c(%ebp), %edx\n" /* vPos3 */
        "movl %eax, (%edx)\n"
        "movl -0x48(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl 0x1c(%ebp), %edx\n" /* vPos3 */
        "movl %eax, 4(%edx)\n"
        "movl -0x40(%ebp), %edx\n" /* line 201 */
        "movl (%edx), %eax\n"
        "movl 0x1c(%ebp), %edx\n" /* vPos3 */
        "movl %eax, 8(%edx)\n"
        "movl %edi, 8(%esp)\n" /* line 209 | vCurrPos */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pTr */
        "calll BG_EvaluateTrajectory\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 210 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b70d6_001b7352:\n"
        "movl 0x195f6a0, %ecx\n" /* line 193 */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%esi)\n" /* pTr */
        "movss 0x2ed5c8, %xmm0\n" /* line 194 | 1000.0f */
        "movl 0x10(%ebp), %edx\n" /* pfDecelTime */
        "mulss (%edx), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 8(%esi)\n" /* pTr */
        "leal 0xc(%esi), %edx\n" /* line 196 | pTr, to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | vCurrPos */
        "movl %eax, 0xc(%esi)\n" /* pTr */
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 201 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0x18(%esi), %edx\n" /* line 197 | pTr, to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | vMaxSpeed */
        "movl %eax, 0x18(%esi)\n" /* pTr */
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $8, (%esi)\n" /* line 198 | pTr */
        "jmp .Lf1b70d6_001b72d9\n"
        ".Lf1b70d6_001b73b7:\n"
        "jp .Lf1b70d6_001b7154\n" /* line 132 */
        "movl 0x195f6a0, %ecx\n" /* line 135 */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%esi)\n" /* pTr */
        "movss 0x2ed5c8, %xmm1\n" /* line 136 | 1000.0f */
        "movaps %xmm3, %xmm0\n" /* fTotalTime */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 8(%esi)\n" /* pTr */
        "movl 0xc(%ebp), %eax\n" /* line 138 | pfMidTime */
        "movss %xmm3, (%eax)\n" /* fTotalTime */
        "movl 0x10(%ebp), %edx\n" /* line 139 | pfDecelTime */
        "movss %xmm2, (%edx)\n"
        "movl (%ebx), %eax\n" /* line 199 | vPos */
        "movl 0x1c(%ebp), %edx\n" /* vPos3 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 | vPos */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 | vPos */
        "movl %eax, 8(%edx)\n"
        "leal 0xc(%esi), %edx\n" /* line 142 | pTr, to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | vCurrPos */
        "movl %eax, 0xc(%esi)\n" /* pTr */
        "movl 4(%edi), %eax\n" /* line 200 | vCurrPos */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 201 | vCurrPos */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "cvtsi2ssl 8(%esi), %xmm0\n" /* line 144 | pTr */
        "divss %xmm0, %xmm1\n"
        "leal 0x18(%esi), %eax\n" /* line 145 | pTr, result */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm0\n" /* vMove */
        "movss %xmm0, 0x18(%esi)\n" /* pTr */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 274 */
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "movl $3, (%esi)\n" /* line 146 | pTr */
        "movl %edi, 8(%esp)\n" /* line 209 | vCurrPos */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pTr */
        "calll BG_EvaluateTrajectory\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 210 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b70d6_001b746b:\n"
        "movl %edi, 8(%esp)\n" /* line 129 | vCurrPos */
        "movl 0x195f6a0, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pTr */
        "movss %xmm3, -0x68(%ebp)\n" /* fTotalTime */
        "movss %xmm2, -0x78(%ebp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movss -0x78(%ebp), %xmm4\n" /* fDecelTime */
        "movss -0x68(%ebp), %xmm3\n" /* fTotalTime */
        "movss -0x4c(%ebp), %xmm0\n"
        "jmp .Lf1b70d6_001b7140\n"
        ".Lf1b70d6_001b74a4:\n"
        "movl 0x195f6a0, %edx\n" /* line 165 */
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, 4(%esi)\n" /* pTr */
        "mulss 0x2ed5c8, %xmm4\n" /* line 166 | 1000.0f, fDecelTime */
        "cvttss2si %xmm4, %eax\n" /* fDecelTime */
        "movl %eax, 8(%esi)\n" /* pTr */
        "leal 0xc(%esi), %edx\n" /* line 167 | pTr, to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | vCurrPos */
        "movl %eax, 0xc(%esi)\n" /* pTr */
        "movl -0x44(%ebp), %ecx\n" /* line 200 */
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x18(%esi), %eax\n" /* line 168 | pTr, to */
        /* { scope 2 */
        "movss %xmm3, 0x18(%esi)\n" /* line 199 | fTotalTime, pTr */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm0, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl $7, (%esi)\n" /* line 169 | pTr */
        "movl 0x14(%ebp), %eax\n" /* line 172 | vPos1 */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f6a0, %edx\n"
        "movl 0x1ec(%edx), %eax\n"
        "addl 8(%esi), %eax\n" /* pTr */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pTr */
        "calll BG_EvaluateTrajectory\n"
        "movl 0x195f6a0, %ecx\n"
        "jmp .Lf1b70d6_001b72d9\n"
    );
}

/* line 673 */
__attribute__((naked))
void ScriptEnt_RotateAxis(scr_entref_t entref, int iAxis)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 673 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl 0xc(%ebp), %ebx\n" /* iAxis */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 681 */
        "testw %ax, %ax\n"
        "jne .Lf1b7520_001b7643\n"
        "movzwl %dx, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl 0x195f688, %esi\n" /* pSelf */
        "movzwl 0x168(%esi), %eax\n" /* pSelf */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x42(%edx), %ax\n"
        "je .Lf1b7520_001b758b\n"
        "cmpw 0x44(%edx), %ax\n"
        "je .Lf1b7520_001b758b\n"
        "cmpw 0x46(%edx), %ax\n"
        "je .Lf1b7520_001b758b\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x2b54e0, (%esp)\n" /* "entity %i is not a script_brushmodel, script_model, or scrip" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        ".Lf1b7520_001b758b:\n"
        "movl $0, (%esp)\n" /* line 683 */
        "calll Scr_GetFloat\n"
        "fstps -0x2c(%ebp)\n" /* fMove */
        "leal -0x14(%ebp), %eax\n" /* line 684 | fDecelTime */
        "movl %eax, 8(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* fAccelTime */
        "movl %eax, 4(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* fTotalTime */
        "movl %eax, (%esp)\n"
        "calll ScriptEntCmdGetCommandTimes\n"
        "leal 0x144(%esi), %ecx\n" /* line 686 | pSelf */
        "movl 0x144(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x20(%ebp)\n" /* vRot */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x18(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 687 | fMove */
        "addss -0x20(%ebp, %ebx, 4), %xmm0\n"
        "movss %xmm0, -0x20(%ebp, %ebx, 4)\n"
        "leal -0x20(%ebp), %edx\n" /* line 362 | vRot */
        "leal 0x30(%esi), %eax\n"
        "leal 0x1fc(%esi), %ebx\n"
        "movl %ebx, 0x14(%esp)\n"
        "leal 0x1f0(%esi), %ebx\n"
        "movl %ebx, 0x10(%esp)\n"
        "leal 0x1e4(%esi), %ebx\n"
        "movl %ebx, 0xc(%esp)\n"
        "leal 0x1ac(%esi), %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "leal 0x1bc(%esi), %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x1b4(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "movss -0x14(%ebp), %xmm2\n" /* fDecelTime */
        "movss -0x10(%ebp), %xmm1\n" /* fAccelTime */
        "movss -0xc(%ebp), %xmm0\n" /* fTotalTime */
        "calll ScriptMover_SetupMove\n"
        "movl %esi, (%esp)\n" /* line 364 */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 690 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7520_001b7643:\n"
        "movl $0x2b21c8, (%esp)\n" /* line 681 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1b7520_001b758b\n"
    );
}

/* line 720 */
__attribute__((naked))
void ScriptEntCmd_RotateRoll(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 720 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $2, 4(%esp)\n" /* line 722 */
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, (%esp)\n"
        "calll ScriptEnt_RotateAxis\n"
        "leave\n" /* line 723 */
        "retl\n"
    );
}

/* line 709 */
__attribute__((naked))
void ScriptEntCmd_RotateYaw(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 709 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, 4(%esp)\n" /* line 711 */
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, (%esp)\n"
        "calll ScriptEnt_RotateAxis\n"
        "leave\n" /* line 712 */
        "retl\n"
    );
}

/* line 698 */
__attribute__((naked))
void ScriptEntCmd_RotatePitch(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 698 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, 4(%esp)\n" /* line 700 */
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, (%esp)\n"
        "calll ScriptEnt_RotateAxis\n"
        "leave\n" /* line 701 */
        "retl\n"
    );
}

/* line 588 */
__attribute__((naked))
void ScriptEnt_MoveAxis(scr_entref_t entref, int iAxis)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 588 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl 0xc(%ebp), %ebx\n" /* iAxis */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 596 */
        "testw %ax, %ax\n"
        "jne .Lf1b76aa_001b77cd\n"
        "movzwl %dx, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl 0x195f688, %esi\n" /* pSelf */
        "movzwl 0x168(%esi), %eax\n" /* pSelf */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x42(%edx), %ax\n"
        "je .Lf1b76aa_001b7715\n"
        "cmpw 0x44(%edx), %ax\n"
        "je .Lf1b76aa_001b7715\n"
        "cmpw 0x46(%edx), %ax\n"
        "je .Lf1b76aa_001b7715\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x2b54e0, (%esp)\n" /* "entity %i is not a script_brushmodel, script_model, or scrip" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        ".Lf1b76aa_001b7715:\n"
        "movl $0, (%esp)\n" /* line 598 */
        "calll Scr_GetFloat\n"
        "fstps -0x2c(%ebp)\n" /* fMove */
        "leal -0x14(%ebp), %eax\n" /* line 599 | fDecelTime */
        "movl %eax, 8(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* fAccelTime */
        "movl %eax, 4(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* fTotalTime */
        "movl %eax, (%esp)\n"
        "calll ScriptEntCmdGetCommandTimes\n"
        "leal 0x138(%esi), %ecx\n" /* line 601 | pSelf */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x20(%ebp)\n" /* vPos */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x18(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 602 | fMove */
        "addss -0x20(%ebp, %ebx, 4), %xmm0\n"
        "movss %xmm0, -0x20(%ebp, %ebx, 4)\n"
        "leal -0x20(%ebp), %edx\n" /* line 322 | vPos */
        "leal 0xc(%esi), %eax\n"
        "leal 0x1d8(%esi), %ebx\n"
        "movl %ebx, 0x14(%esp)\n"
        "leal 0x1cc(%esi), %ebx\n"
        "movl %ebx, 0x10(%esp)\n"
        "leal 0x1c0(%esi), %ebx\n"
        "movl %ebx, 0xc(%esp)\n"
        "leal 0x1a8(%esi), %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "leal 0x1b8(%esi), %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x1b0(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "movss -0x14(%ebp), %xmm2\n" /* fDecelTime */
        "movss -0x10(%ebp), %xmm1\n" /* fAccelTime */
        "movss -0xc(%ebp), %xmm0\n" /* fTotalTime */
        "calll ScriptMover_SetupMove\n"
        "movl %esi, (%esp)\n" /* line 323 */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 605 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b76aa_001b77cd:\n"
        "movl $0x2b21c8, (%esp)\n" /* line 596 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1b76aa_001b7715\n"
    );
}

/* line 635 */
__attribute__((naked))
void ScriptEntCmd_MoveZ(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 635 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $2, 4(%esp)\n" /* line 637 */
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, (%esp)\n"
        "calll ScriptEnt_MoveAxis\n"
        "leave\n" /* line 638 */
        "retl\n"
    );
}

/* line 624 */
__attribute__((naked))
void ScriptEntCmd_MoveY(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 624 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, 4(%esp)\n" /* line 626 */
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, (%esp)\n"
        "calll ScriptEnt_MoveAxis\n"
        "leave\n" /* line 627 */
        "retl\n"
    );
}

/* line 613 */
__attribute__((naked))
void ScriptEntCmd_MoveX(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 613 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, 4(%esp)\n" /* line 615 */
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, (%esp)\n"
        "calll ScriptEnt_MoveAxis\n"
        "leave\n" /* line 616 */
        "retl\n"
    );
}

/* line 646 */
__attribute__((naked))
void ScriptEntCmd_RotateTo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 646 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 655 */
        "testw %ax, %ax\n"
        "jne .Lf1b7834_001b7982\n"
        "movzwl %dx, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %edi\n" /* pSelf */
        "subl %eax, %edi\n" /* pSelf */
        "shll $4, %edi\n" /* pSelf */
        "addl 0x195f688, %edi\n" /* pSelf */
        "movzwl 0x168(%edi), %eax\n" /* pSelf */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x42(%edx), %ax\n"
        "je .Lf1b7834_001b789d\n"
        "cmpw 0x44(%edx), %ax\n"
        "je .Lf1b7834_001b789d\n"
        "cmpw 0x46(%edx), %ax\n"
        "je .Lf1b7834_001b789d\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x2b54e0, (%esp)\n" /* "entity %i is not a script_brushmodel, script_model, or scrip" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        ".Lf1b7834_001b789d:\n"
        "leal -0x30(%ebp), %eax\n" /* line 657 | vDest */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x24(%ebp), %eax\n" /* line 658 | fDecelTime */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* fAccelTime */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* fTotalTime */
        "movl %eax, (%esp)\n"
        "calll ScriptEntCmdGetCommandTimes\n"
        "movl %edi, %esi\n" /* pSelf */
        "movl $1, -0x4c(%ebp)\n"
        ".Lf1b7834_001b78d2:\n"
        "movss 0x144(%esi), %xmm0\n" /* line 662 */
        "movss %xmm0, 4(%esp)\n"
        "movl -0x4c(%ebp), %ebx\n"
        "shll $2, %ebx\n"
        "movl -0x34(%ebp, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "calll AngleSubtract\n"
        "fstps -0x50(%ebp)\n"
        "movss -0x68(%ebp), %xmm0\n"
        "addss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, -0x40(%ebp, %ebx)\n"
        "addl $1, -0x4c(%ebp)\n"
        "addl $4, %esi\n"
        "cmpl $4, -0x4c(%ebp)\n" /* line 661 */
        "jne .Lf1b7834_001b78d2\n"
        "leal 0x144(%edi), %ecx\n" /* line 362 */
        "leal 0x30(%edi), %eax\n"
        "leal 0x1fc(%edi), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "leal 0x1f0(%edi), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal 0x1e4(%edi), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "leal 0x1ac(%edi), %edx\n"
        "movl %edx, 8(%esp)\n"
        "leal 0x1bc(%edi), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal 0x1b4(%edi), %edx\n"
        "movl %edx, (%esp)\n"
        "movss -0x24(%ebp), %xmm2\n" /* fDecelTime */
        "movss -0x20(%ebp), %xmm1\n" /* fAccelTime */
        "movss -0x1c(%ebp), %xmm0\n" /* fTotalTime */
        "leal -0x3c(%ebp), %edx\n" /* vRot */
        "calll ScriptMover_SetupMove\n"
        "movl %edi, (%esp)\n" /* line 364 */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 665 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7834_001b7982:\n"
        "movl $0x2b21c8, (%esp)\n" /* line 655 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n" /* pSelf */
        "jmp .Lf1b7834_001b789d\n"
    );
}

/* line 550 */
__attribute__((naked))
void ScriptEntCmd_MoveTo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 550 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 557 */
        "testw %ax, %ax\n"
        "jne .Lf1b7996_001b7a93\n"
        "movzwl %dx, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* pSelf */
        "subl %eax, %esi\n" /* pSelf */
        "shll $4, %esi\n" /* pSelf */
        "addl 0x195f688, %esi\n" /* pSelf */
        "movzwl 0x168(%esi), %eax\n" /* pSelf */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x42(%edx), %ax\n"
        "je .Lf1b7996_001b79fe\n"
        "cmpw 0x44(%edx), %ax\n"
        "je .Lf1b7996_001b79fe\n"
        "cmpw 0x46(%edx), %ax\n"
        "je .Lf1b7996_001b79fe\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x2b54e0, (%esp)\n" /* "entity %i is not a script_brushmodel, script_model, or scrip" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        ".Lf1b7996_001b79fe:\n"
        "leal -0x20(%ebp), %ebx\n" /* line 559 | vPos */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x14(%ebp), %eax\n" /* line 560 | fDecelTime */
        "movl %eax, 8(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* fAccelTime */
        "movl %eax, 4(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* fTotalTime */
        "movl %eax, (%esp)\n"
        "calll ScriptEntCmdGetCommandTimes\n"
        "leal 0x138(%esi), %ecx\n" /* line 322 */
        "leal 0xc(%esi), %eax\n"
        "leal 0x1d8(%esi), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "leal 0x1cc(%esi), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal 0x1c0(%esi), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "leal 0x1a8(%esi), %edx\n"
        "movl %edx, 8(%esp)\n"
        "leal 0x1b8(%esi), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal 0x1b0(%esi), %edx\n"
        "movl %edx, (%esp)\n"
        "movss -0x14(%ebp), %xmm2\n" /* fDecelTime */
        "movss -0x10(%ebp), %xmm1\n" /* fAccelTime */
        "movss -0xc(%ebp), %xmm0\n" /* fTotalTime */
        "movl %ebx, %edx\n"
        "calll ScriptMover_SetupMove\n"
        "movl %esi, (%esp)\n" /* line 323 */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 562 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7996_001b7a93:\n"
        "movl $0x2b21c8, (%esp)\n" /* line 557 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n" /* pSelf */
        "jmp .Lf1b7996_001b79fe\n"
    );
}

