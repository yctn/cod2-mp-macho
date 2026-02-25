/* ASM dump from: cl_input.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_input.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

extern const dvar_t *cl_yawspeed; /* 0x0 */
extern const dvar_t *cl_pitchspeed; /* 0x0 */
extern const dvar_t *cl_anglespeedkey; /* 0x0 */
extern const dvar_t *cl_talking; /* 0x0 */
extern const dvar_t *cl_bypassMouseInput; /* 0x0 */
extern const dvar_t *cl_analog_attack_threshold; /* 0x0 */
extern const dvar_t *cl_stanceHoldTime; /* 0x0 */
static kbutton_t playersKb[1][28]; /* 0xf2ee80 */
static kbutton_t *kb; /* 0x313180 */

void IN_MLookDown(void);
void IN_CenterView(void);
void IN_KeyDown(kbutton_t *b);
void IN_KeyUp(kbutton_t *b);
void IN_UpDown(void);
void IN_UpUp(void);
void IN_LeftDown(void);
void IN_LeftUp(void);
void IN_RightDown(void);
void IN_RightUp(void);
void IN_ForwardDown(void);
void IN_ForwardUp(void);
void IN_BackDown(void);
void IN_BackUp(void);
void IN_LookupDown(void);
void IN_LookupUp(void);
void IN_LookdownDown(void);
void IN_LookdownUp(void);
void IN_MoveleftDown(void);
void IN_MoveleftUp(void);
void IN_MoverightDown(void);
void IN_MoverightUp(void);
void IN_SpeedDown(void);
void IN_SpeedUp(void);
void IN_StrafeDown(void);
void IN_StrafeUp(void);
void IN_Attack_Down(void);
void IN_Attack_Up(void);
void IN_Breath_Down(void);
void IN_Breath_Up(void);
void IN_MeleeBreath_Down(void);
void IN_MeleeBreath_Up(void);
void IN_Frag_Down(void);
void IN_Frag_Up(void);
void IN_Smoke_Down(void);
void IN_Smoke_Up(void);
void IN_Binoculars_Down(void);
void IN_Binoculars_Up(void);
void IN_BreathBinoculars_Down(void);
void IN_BreathBinoculars_Up(void);
void IN_Melee_Down(void);
void IN_Melee_Up(void);
void IN_Activate_Down(void);
void IN_Activate_Up(void);
void IN_Reload_Down(void);
void IN_Reload_Up(void);
void IN_UseReload_Down(void);
void IN_UseReload_Up(void);
void IN_LeanLeft_Down(void);
void IN_LeanLeft_Up(void);
void IN_LeanRight_Down(void);
void IN_LeanRight_Up(void);
void IN_Stance_Down(void);
void IN_Stance_Up(void);
void IN_ToggleADS(void);
void IN_LeaveADS(void);
void IN_LowerStance(void);
void IN_RaiseStance(void);
void IN_ToggleCrouch(void);
void IN_ToggleProne(void);
void IN_GoProne(void);
void IN_GoCrouch(void);
void IN_GoStandDown(void);
void IN_GoStandUp(void);
void IN_TalkDown(void);
void IN_TalkUp(void);
Bool IsTalking(void);
void CL_MouseEvent(const int dx, const int dy);
void CL_WriteVoicePacket(void);
void CL_WritePacket(void);
void CL_InitInput(void);
void CL_ShutdownInput(void);
void CL_CmdButtons(usercmd_t *cmd);
void CL_MouseMove(usercmd_t *cmd);
void IN_DownDown(void);
void IN_DownUp(void);
void IN_Prone_Down(void);
void IN_Prone_Up(void);
void IN_MLookUp(void);
void CL_AdjustAngles(void);
void CL_KeyMove(usercmd_t *cmd);
usercmd_t CL_CreateCmd(void);
void CL_SendCmdInternal(void);
void CL_Input(void);
void CL_SendCmd(void);

/* line 102 */
__attribute__((naked))
void IN_MLookDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 104 */
        "movb $1, 0x114(%eax)\n"
        "popl %ebp\n" /* line 105 */
        "retl\n"
    );
}

/* line 654 */
__attribute__((naked))
void IN_CenterView(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 654 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 656 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x88(%eax), %xmm0\n"
        "mulss 0x2ed948, %xmm0\n" /* -0.0054931640625f */
        "movss %xmm0, 0x861c(%eax)\n"
        "popl %ebp\n" /* line 657 */
        "retl\n"
    );
}

/* line 116 */
__attribute__((naked))
void IN_KeyDown(kbutton_t *b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 116 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* b */
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 121 */
        "calll Cmd_Argv\n"
        "cmpb $0, (%eax)\n" /* line 122 */
        "jne .Lf1854c8_0018552f\n"
        "movl $0xffffffff, %eax\n"
        ".Lf1854c8_001854e8:\n"
        "movl (%ebx), %edx\n" /* line 131 | b */
        "cmpl %edx, %eax\n"
        "je .Lf1854c8_00185520\n"
        "movl 4(%ebx), %ecx\n" /* b */
        "cmpl %ecx, %eax\n"
        "je .Lf1854c8_00185520\n"
        "testl %edx, %edx\n" /* line 136 */
        "jne .Lf1854c8_00185526\n"
        "movl %eax, (%ebx)\n" /* line 138 | b */
        ".Lf1854c8_001854fb:\n"
        "cmpb $0, 0x10(%ebx)\n" /* line 150 | b */
        "jne .Lf1854c8_00185520\n"
        "movl $2, (%esp)\n" /* line 156 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n" /* line 157 */
        "calll atoi\n"
        "movl %eax, 8(%ebx)\n" /* b */
        "movb $1, 0x10(%ebx)\n" /* line 159 | b */
        "movb $1, 0x11(%ebx)\n" /* line 160 | b */
        /* } scope */
        ".Lf1854c8_00185520:\n"
        "addl $0x14, %esp\n" /* line 161 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1854c8_00185526:\n"
        "testl %ecx, %ecx\n" /* line 140 */
        "jne .Lf1854c8_00185539\n"
        "movl %eax, 4(%ebx)\n" /* line 142 | b */
        "jmp .Lf1854c8_001854fb\n"
        ".Lf1854c8_0018552f:\n"
        "movl %eax, (%esp)\n" /* line 124 */
        "calll atoi\n"
        "jmp .Lf1854c8_001854e8\n"
        ".Lf1854c8_00185539:\n"
        "movl $0x2af610, 8(%ebp)\n" /* line 146 | b */
        /* } scope */
        "addl $0x14, %esp\n" /* line 161 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 146 */
    );
}

/* line 164 */
__attribute__((naked))
void IN_KeyUp(kbutton_t *b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 164 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* b */
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 170 */
        "calll Cmd_Argv\n"
        "cmpb $0, (%eax)\n" /* line 171 */
        "jne .Lf18554a_0018557c\n"
        "movl $0, 4(%ebx)\n" /* line 178 | b */
        "movl $0, (%ebx)\n" /* b */
        "movb $0, 0x10(%ebx)\n" /* line 179 | b */
        /* } scope */
        ".Lf18554a_00185576:\n"
        "addl $0x14, %esp\n" /* line 215 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18554a_0018557c:\n"
        "movl %eax, (%esp)\n" /* line 173 */
        "calll atoi\n"
        "cmpl (%ebx), %eax\n" /* line 183 | b */
        "je .Lf18554a_001855cf\n"
        "cmpl 4(%ebx), %eax\n" /* line 187 | b */
        "jne .Lf18554a_00185576\n"
        "movl $0, 4(%ebx)\n" /* line 189 | b */
        ".Lf18554a_00185594:\n"
        "movl (%ebx), %edx\n" /* line 195 | b */
        "testl %edx, %edx\n"
        "jne .Lf18554a_00185576\n"
        "movl 4(%ebx), %eax\n" /* b */
        "testl %eax, %eax\n"
        "jne .Lf18554a_00185576\n"
        "movb $0, 0x10(%ebx)\n" /* line 200 | b */
        "movl $2, (%esp)\n" /* line 203 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n" /* line 204 */
        "calll atoi\n"
        "testl %eax, %eax\n" /* line 205 */
        "jne .Lf18554a_001855d7\n"
        "movl 0x195f638, %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, 0xc(%ebx)\n" /* b */
        "movb $0, 0x10(%ebx)\n" /* line 214 | b */
        "jmp .Lf18554a_00185576\n"
        ".Lf18554a_001855cf:\n"
        "movl $0, (%ebx)\n" /* line 185 | b */
        "jmp .Lf18554a_00185594\n"
        ".Lf18554a_001855d7:\n"
        "subl 8(%ebx), %eax\n" /* line 207 | b */
        "addl %eax, 0xc(%ebx)\n" /* b */
        "movb $0, 0x10(%ebx)\n" /* line 214 | b */
        "jmp .Lf18554a_00185576\n"
    );
}

/* line 278 */
__attribute__((naked))
void IN_UpDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 278 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 280 */
        "addl $0xf0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "movl kb, %edx\n" /* line 283 */
        "cmpb $0, 0x204(%edx)\n"
        "jne .Lf1855e6_0018562a\n"
        "cmpb $0, 0xec(%edx)\n"
        "jne .Lf1855e6_0018562a\n"
        "movl 0x195ecb4, %eax\n" /* line 290 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jle .Lf1855e6_0018562c\n"
        "movl $1, 8(%eax)\n" /* line 291 */
        ".Lf1855e6_0018562a:\n"
        "leave\n" /* line 297 */
        "retl\n"
        ".Lf1855e6_0018562c:\n"
        "je .Lf1855e6_0018563e\n" /* line 292 */
        "leal 0xc8(%edx), %eax\n" /* line 295 */
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 297 */
        "retl\n"
        ".Lf1855e6_0018563e:\n"
        "movl $0, 8(%eax)\n" /* line 293 */
        "leave\n" /* line 297 */
        "retl\n"
    );
}

/* line 300 */
__attribute__((naked))
void IN_UpUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 300 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 302 */
        "addl $0xf0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "movl kb, %eax\n" /* line 303 */
        "addl $0xc8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 304 */
        "retl\n"
    );
}

/* line 322 */
__attribute__((naked))
void IN_LeftDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 322 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 324 */
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 325 */
        "retl\n"
    );
}

/* line 328 */
__attribute__((naked))
void IN_LeftUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 328 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 330 */
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 331 */
        "retl\n"
    );
}

/* line 334 */
__attribute__((naked))
void IN_RightDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 334 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 336 */
        "addl $0x14, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 337 */
        "retl\n"
    );
}

/* line 340 */
__attribute__((naked))
void IN_RightUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 340 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 342 */
        "addl $0x14, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 343 */
        "retl\n"
    );
}

/* line 346 */
__attribute__((naked))
void IN_ForwardDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 346 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 348 */
        "addl $0x28, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 349 */
        "retl\n"
    );
}

/* line 352 */
__attribute__((naked))
void IN_ForwardUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 352 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 354 */
        "addl $0x28, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 355 */
        "retl\n"
    );
}

/* line 358 */
__attribute__((naked))
void IN_BackDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 358 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 360 */
        "addl $0x3c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 361 */
        "retl\n"
    );
}

/* line 364 */
__attribute__((naked))
void IN_BackUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 364 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 366 */
        "addl $0x3c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 367 */
        "retl\n"
    );
}

/* line 370 */
__attribute__((naked))
void IN_LookupDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 370 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 372 */
        "addl $0x50, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 373 */
        "retl\n"
    );
}

/* line 376 */
__attribute__((naked))
void IN_LookupUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 376 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 378 */
        "addl $0x50, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 379 */
        "retl\n"
    );
}

/* line 382 */
__attribute__((naked))
void IN_LookdownDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 382 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 384 */
        "addl $0x64, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 385 */
        "retl\n"
    );
}

/* line 388 */
__attribute__((naked))
void IN_LookdownUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 388 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 390 */
        "addl $0x64, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 391 */
        "retl\n"
    );
}

/* line 394 */
__attribute__((naked))
void IN_MoveleftDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 394 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 396 */
        "addl $0x78, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 397 */
        "retl\n"
    );
}

/* line 400 */
__attribute__((naked))
void IN_MoveleftUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 400 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 402 */
        "addl $0x78, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 403 */
        "retl\n"
    );
}

/* line 406 */
__attribute__((naked))
void IN_MoverightDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 406 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 408 */
        "addl $0x8c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 409 */
        "retl\n"
    );
}

/* line 412 */
__attribute__((naked))
void IN_MoverightUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 412 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 414 */
        "addl $0x8c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 415 */
        "retl\n"
    );
}

/* line 418 */
__attribute__((naked))
void IN_SpeedDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 418 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 420 */
        "addl $0xb4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 421 */
        "retl\n"
    );
}

/* line 424 */
__attribute__((naked))
void IN_SpeedUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 424 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 426 */
        "addl $0xb4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 427 */
        "retl\n"
    );
}

/* line 430 */
__attribute__((naked))
void IN_StrafeDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 430 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 432 */
        "addl $0xa0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 433 */
        "retl\n"
    );
}

/* line 436 */
__attribute__((naked))
void IN_StrafeUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 436 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 438 */
        "addl $0xa0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 439 */
        "retl\n"
    );
}

/* line 442 */
__attribute__((naked))
void IN_Attack_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 442 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 444 */
        "addl $0x118, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 445 */
        "retl\n"
    );
}

/* line 448 */
__attribute__((naked))
void IN_Attack_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 448 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 450 */
        "addl $0x118, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 451 */
        "retl\n"
    );
}

/* line 454 */
__attribute__((naked))
void IN_Breath_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 454 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 456 */
        "addl $0x12c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 457 */
        "retl\n"
    );
}

/* line 460 */
__attribute__((naked))
void IN_Breath_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 460 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 462 */
        "addl $0x12c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 463 */
        "retl\n"
    );
}

/* line 466 */
__attribute__((naked))
void IN_MeleeBreath_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 466 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 468 */
        "addl $0x17c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "movl kb, %eax\n" /* line 469 */
        "addl $0x12c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 470 */
        "retl\n"
    );
}

/* line 473 */
__attribute__((naked))
void IN_MeleeBreath_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 473 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 475 */
        "addl $0x17c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "movl kb, %eax\n" /* line 476 */
        "addl $0x12c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 477 */
        "retl\n"
    );
}

/* line 480 */
__attribute__((naked))
void IN_Frag_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 480 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 482 */
        "addl $0x140, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 483 */
        "retl\n"
    );
}

/* line 486 */
__attribute__((naked))
void IN_Frag_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 486 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 488 */
        "addl $0x140, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 489 */
        "retl\n"
    );
}

/* line 492 */
__attribute__((naked))
void IN_Smoke_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 492 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 494 */
        "addl $0x154, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 495 */
        "retl\n"
    );
}

/* line 498 */
__attribute__((naked))
void IN_Smoke_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 498 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 500 */
        "addl $0x154, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 501 */
        "retl\n"
    );
}

/* line 504 */
__attribute__((naked))
void IN_Binoculars_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 504 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 506 */
        "addl $0x168, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 507 */
        "retl\n"
    );
}

/* line 510 */
__attribute__((naked))
void IN_Binoculars_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 510 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 512 */
        "addl $0x168, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 513 */
        "retl\n"
    );
}

/* line 516 */
__attribute__((naked))
void IN_BreathBinoculars_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 516 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 518 */
        "addl $0x12c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "movl kb, %eax\n" /* line 519 */
        "addl $0x168, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 520 */
        "retl\n"
    );
}

/* line 523 */
__attribute__((naked))
void IN_BreathBinoculars_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 523 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 525 */
        "addl $0x12c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "movl kb, %eax\n" /* line 526 */
        "addl $0x168, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 527 */
        "retl\n"
    );
}

/* line 530 */
__attribute__((naked))
void IN_Melee_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 530 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 532 */
        "addl $0x17c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 533 */
        "retl\n"
    );
}

/* line 536 */
__attribute__((naked))
void IN_Melee_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 536 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 538 */
        "addl $0x17c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 539 */
        "retl\n"
    );
}

/* line 542 */
__attribute__((naked))
void IN_Activate_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 542 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 544 */
        "addl $0x190, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 545 */
        "retl\n"
    );
}

/* line 548 */
__attribute__((naked))
void IN_Activate_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 548 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 550 */
        "addl $0x190, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 551 */
        "retl\n"
    );
}

/* line 554 */
__attribute__((naked))
void IN_Reload_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 554 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 556 */
        "addl $0x1a4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 557 */
        "retl\n"
    );
}

/* line 560 */
__attribute__((naked))
void IN_Reload_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 560 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 562 */
        "addl $0x1a4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 563 */
        "retl\n"
    );
}

/* line 566 */
__attribute__((naked))
void IN_UseReload_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 566 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 568 */
        "addl $0x1b8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 569 */
        "retl\n"
    );
}

/* line 572 */
__attribute__((naked))
void IN_UseReload_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 572 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 574 */
        "addl $0x1b8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 575 */
        "retl\n"
    );
}

/* line 578 */
__attribute__((naked))
void IN_LeanLeft_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 578 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 580 */
        "addl $0x1cc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 581 */
        "retl\n"
    );
}

/* line 584 */
__attribute__((naked))
void IN_LeanLeft_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 584 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 586 */
        "addl $0x1cc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 587 */
        "retl\n"
    );
}

/* line 590 */
__attribute__((naked))
void IN_LeanRight_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 590 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 592 */
        "addl $0x1e0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 593 */
        "retl\n"
    );
}

/* line 596 */
__attribute__((naked))
void IN_LeanRight_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 596 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 598 */
        "addl $0x1e0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 599 */
        "retl\n"
    );
}

/* line 616 */
__attribute__((naked))
void IN_Stance_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 616 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 618 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf185b48_00185ba0\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf185b48_00185ba0\n"
        "movl 0x195ee78, %eax\n" /* line 621 */
        "movl (%eax), %edx\n"
        "movb $1, 0x85ec(%edx)\n"
        "movl 0x195ecb4, %ecx\n" /* line 622 */
        "movl (%ecx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x85f0(%edx)\n"
        "movl 0x195f2d8, %eax\n" /* line 623 */
        "movl (%eax), %eax\n"
        "movl %eax, 0x85f4(%edx)\n"
        "cmpl $1, 0x85f0(%edx)\n" /* line 625 */
        "je .Lf185b48_00185ba0\n"
        "movl (%ecx), %eax\n" /* line 626 */
        "movl $1, 8(%eax)\n"
        ".Lf185b48_00185ba0:\n"
        "popl %ebp\n" /* line 627 */
        "retl\n"
    );
}

/* line 630 */
__attribute__((naked))
void IN_Stance_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 630 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 632 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf185ba2_00185bdf\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf185ba2_00185bdf\n"
        "movl 0x195ee78, %edx\n" /* line 635 */
        "movl (%edx), %eax\n"
        "cmpb $0, 0x85ec(%eax)\n"
        "je .Lf185ba2_00185bd8\n"
        "cmpl $1, 0x85f0(%eax)\n"
        "je .Lf185ba2_00185be1\n"
        "movl (%edx), %eax\n"
        ".Lf185ba2_00185bd8:\n"
        "movb $0, 0x85ec(%eax)\n" /* line 638 */
        ".Lf185ba2_00185bdf:\n"
        "popl %ebp\n" /* line 639 */
        "retl\n"
        ".Lf185ba2_00185be1:\n"
        "movl 0x195ecb4, %eax\n" /* line 636 */
        "movl (%eax), %eax\n"
        "movl $0, 8(%eax)\n"
        "movl (%edx), %eax\n"
        "jmp .Lf185ba2_00185bd8\n"
    );
}

/* line 660 */
__attribute__((naked))
void IN_ToggleADS(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 660 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 662 */
        "movl (%eax), %eax\n"
        "cmpb $0, 0xb(%eax)\n"
        "sete 0xb(%eax)\n"
        "popl %ebp\n" /* line 663 */
        "retl\n"
    );
}

/* line 666 */
__attribute__((naked))
void IN_LeaveADS(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 666 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 668 */
        "movl (%eax), %eax\n"
        "movb $0, 0xb(%eax)\n"
        "popl %ebp\n" /* line 669 */
        "retl\n"
    );
}

/* line 672 */
__attribute__((naked))
void IN_LowerStance(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 672 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 675 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf185c18_00185c45\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf185c18_00185c45\n"
        "movl 0x195ecb4, %eax\n" /* line 682 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf185c18_00185c50\n"
        "subl $1, %edx\n" /* line 684 */
        "je .Lf185c18_00185c47\n"
        ".Lf185c18_00185c45:\n"
        "popl %ebp\n" /* line 687 */
        "retl\n"
        ".Lf185c18_00185c47:\n"
        "movl $2, 8(%eax)\n" /* line 685 */
        "popl %ebp\n" /* line 687 */
        "retl\n"
        ".Lf185c18_00185c50:\n"
        "movl $1, 8(%eax)\n" /* line 683 */
        "popl %ebp\n" /* line 687 */
        "retl\n"
    );
}

/* line 690 */
__attribute__((naked))
void IN_RaiseStance(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 690 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 693 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf185c5a_00185c88\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf185c5a_00185c88\n"
        "movl 0x195ecb4, %eax\n" /* line 700 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jle .Lf185c5a_00185c8a\n"
        "movl $1, 8(%eax)\n" /* line 701 */
        ".Lf185c5a_00185c88:\n"
        "popl %ebp\n" /* line 705 */
        "retl\n"
        ".Lf185c5a_00185c8a:\n"
        "jne .Lf185c5a_00185c88\n" /* line 702 */
        "movl $0, 8(%eax)\n" /* line 703 */
        "popl %ebp\n" /* line 705 */
        "retl\n"
    );
}

/* line 708 */
__attribute__((naked))
void IN_ToggleCrouch(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 708 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 711 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf185c96_00185cc3\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf185c96_00185cc3\n"
        "movl 0x195ecb4, %eax\n" /* line 718 */
        "movl (%eax), %edx\n"
        "xorl %eax, %eax\n" /* line 719 */
        "cmpl $1, 8(%edx)\n"
        "setne %al\n"
        "movl %eax, 8(%edx)\n"
        ".Lf185c96_00185cc3:\n"
        "popl %ebp\n" /* line 723 */
        "retl\n"
    );
}

/* line 726 */
__attribute__((naked))
void IN_ToggleProne(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 726 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 729 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf185cc6_00185cf5\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf185cc6_00185cf5\n"
        "movl 0x195ecb4, %eax\n" /* line 736 */
        "movl (%eax), %edx\n"
        "xorl %eax, %eax\n" /* line 737 */
        "cmpl $2, 8(%edx)\n"
        "setne %al\n"
        "addl %eax, %eax\n"
        "movl %eax, 8(%edx)\n"
        ".Lf185cc6_00185cf5:\n"
        "popl %ebp\n" /* line 741 */
        "retl\n"
    );
}

/* line 744 */
__attribute__((naked))
void IN_GoProne(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 744 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 747 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf185cf8_00185d20\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf185cf8_00185d20\n"
        "movl 0x195ecb4, %eax\n" /* line 755 */
        "movl (%eax), %eax\n"
        "movl $2, 8(%eax)\n"
        ".Lf185cf8_00185d20:\n"
        "popl %ebp\n" /* line 757 */
        "retl\n"
    );
}

/* line 760 */
__attribute__((naked))
void IN_GoCrouch(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 760 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 763 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf185d22_00185d4a\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf185d22_00185d4a\n"
        "movl 0x195ecb4, %eax\n" /* line 771 */
        "movl (%eax), %eax\n"
        "movl $1, 8(%eax)\n"
        ".Lf185d22_00185d4a:\n"
        "popl %ebp\n" /* line 773 */
        "retl\n"
    );
}

/* line 776 */
__attribute__((naked))
void IN_GoStandDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 776 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 778 */
        "addl $0xf0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "movl 0x195ecb4, %eax\n" /* line 781 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf185d4c_00185d93\n"
        "movl kb, %edx\n" /* line 788 */
        "cmpb $0, 0x204(%edx)\n"
        "jne .Lf185d4c_00185d91\n"
        "cmpb $0, 0xec(%edx)\n"
        "jne .Lf185d4c_00185d91\n"
        "movl $0, 8(%eax)\n" /* line 796 */
        ".Lf185d4c_00185d91:\n"
        "leave\n" /* line 798 */
        "retl\n"
        ".Lf185d4c_00185d93:\n"
        "movl kb, %eax\n" /* line 783 */
        "addl $0xc8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 798 */
        "retl\n"
    );
}

/* line 801 */
__attribute__((naked))
void IN_GoStandUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 801 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 803 */
        "addl $0xf0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "movl kb, %eax\n" /* line 804 */
        "addl $0xc8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 805 */
        "retl\n"
    );
}

/* line 837 */
__attribute__((naked))
void IN_TalkDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 837 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 839 */
        "addl $0x21c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "leave\n" /* line 840 */
        "retl\n"
    );
}

/* line 842 */
__attribute__((naked))
void IN_TalkUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 842 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 844 */
        "addl $0x21c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "leave\n" /* line 845 */
        "retl\n"
    );
}

/* line 847 */
__attribute__((naked))
Bool IsTalking(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 847 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n"
        "movzbl 0x22c(%eax), %eax\n"
        "popl %ebp\n" /* line 850 */
        "retl\n"
    );
}

/* line 1006 */
__attribute__((naked))
void CL_MouseEvent(const int dx, const int dy)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1006 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* dx */
        "movl 0xc(%ebp), %ebx\n" /* dy */
        "movl 0x195ee78, %eax\n" /* line 1016 */
        "movl (%eax), %edx\n"
        "testb $8, 4(%edx)\n"
        "je .Lf185e1a_00185e3c\n"
        "movl cl_bypassMouseInput, %eax\n" /* line 1019 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf185e1a_00185e53\n"
        ".Lf185e1a_00185e3c:\n"
        "movl 0x85e8(%edx), %eax\n" /* line 1029 */
        "addl %ecx, 0x85d8(%edx, %eax, 4)\n"
        "addl %ebx, 0x85e0(%edx, %eax, 4)\n" /* line 1030 | dy */
        "popl %ebx\n" /* line 1032 */
        "popl %ebp\n"
        "retl\n"
        ".Lf185e1a_00185e53:\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 1025 | dy */
        "movl %ecx, 8(%ebp)\n" /* dx */
        "popl %ebx\n" /* line 1032 */
        "popl %ebp\n"
        "jmp UI_MouseEvent\n" /* line 1025 */
    );
}

/* line 1461 */
__attribute__((naked))
void CL_WriteVoicePacket(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1461 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x406c, %esp\n"
        /* { scope 1 */
        "movl 0x195ee8c, %eax\n" /* line 1468 */
        "movl (%eax), %ebx\n"
        "movl 0x407a0(%ebx), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lf185e60_00185e89\n"
        "movl (%ebx), %eax\n"
        "cmpl $8, %eax\n"
        "je .Lf185e60_00185e94\n"
        "cmpl $6, %eax\n"
        "je .Lf185e60_00185e94\n"
        /* } scope */
        ".Lf185e60_00185e89:\n"
        "addl $0x406c, %esp\n" /* line 1507 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf185e60_00185e94:\n"
        "movl $0x4000, 8(%esp)\n" /* line 1473 */
        "leal -0x403c(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_Init\n"
        "movl $0x2a9440, 4(%esp)\n" /* line 1475 */
        "leal -0x3c(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteString\n"
        "movl 4(%ebx), %eax\n" /* line 1478 */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteShort\n"
        "movl 0x195ee78, %esi\n" /* line 1481 */
        "movl (%esi), %ebx\n"
        "movzbl 0x179c0c(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl %ebx, %eax\n" /* line 1489 */
        "movl 0x179c0c(%ebx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jg .Lf185e60_00185f5d\n"
        "movl 0x195f618, %eax\n" /* line 1499 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf185e60_00185fca\n"
        ".Lf185e60_00185f11:\n"
        "movl 0x195ee8c, %eax\n" /* line 1506 */
        "movl (%eax), %edx\n"
        "movl 0x14(%edx), %esi\n"
        "movl %esi, -0x24(%ebp)\n"
        "movl 0x18(%edx), %ebx\n"
        "movl %ebx, -0x20(%ebp)\n"
        "movl 0x1c(%edx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x407cc(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll NET_OutOfBandVoiceData\n"
        /* } scope */
        "addl $0x406c, %esp\n" /* line 1507 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf185e60_00185f5d:\n"
        "xorl %edi, %edi\n" /* line 1489 | voicePacket */
        "movl %esi, -0x404c(%ebp)\n"
        "xorl %esi, %esi\n"
        ".Lf185e60_00185f67:\n"
        "movl 0x1791e4(%esi, %eax), %eax\n" /* line 1494 */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl -0x404c(%ebp), %eax\n" /* line 1495 */
        "movl (%eax), %ebx\n"
        "movl 0x1791e4(%esi, %ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x1791e8(%esi, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteData\n"
        "addl $1, %edi\n" /* line 1489 | voicePacket */
        "addl $0x104, %esi\n"
        "movl %ebx, %eax\n"
        "cmpl 0x179c0c(%ebx), %edi\n" /* voicePacket */
        "jl .Lf185e60_00185f67\n"
        "movl 0x195f618, %eax\n" /* line 1499 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf185e60_00185f11\n"
        ".Lf185e60_00185fca:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1501 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2af630, (%esp)\n" /* "voice: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf185e60_00185f11\n"
    );
}

/* line 1533 */
__attribute__((naked))
void CL_WritePacket(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1533 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x806c, %esp\n"
        /* { scope 1 */
        "movl 0x195ee8c, %edi\n" /* line 1547 | compressedSize */
        "movl (%edi), %esi\n" /* compressedSize, i */
        "movl 0x407a0(%esi), %eax\n" /* i */
        "testl %eax, %eax\n"
        "jne .Lf185fe2_0018627d\n"
        "movl (%esi), %eax\n" /* i */
        "cmpl $1, %eax\n"
        "je .Lf185fe2_0018627d\n"
        "cmpl $2, %eax\n"
        "je .Lf185fe2_0018627d\n"
        "leal -0x4c(%ebp), %eax\n" /* line 1552 | nullcmd */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ee78, %eax\n"
        "movl (%eax), %ebx\n" /* cmd */
        "leal 0x34(%ebx), %eax\n" /* cmd */
        "movl %eax, (%esp)\n"
        "calll MSG_SetDefaultUserCmd\n"
        "movl $0x4000, 8(%esp)\n" /* line 1556 */
        "leal -0x404c(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* buf */
        "movl %edx, (%esp)\n"
        "calll MSG_Init\n"
        "movl 0x8628(%ebx), %eax\n" /* line 1560 | cmd */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 0x20138(%esi), %eax\n" /* line 1565 | i */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* buf */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl 0x2013c(%esi), %eax\n" /* line 1568 | i */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl %esi, %ebx\n" /* line 1571 | i, cmd */
        "movl 0x134(%esi), %esi\n" /* i */
        "addl $1, %esi\n" /* i */
        "cmpl 0x130(%ebx), %esi\n" /* cmd, i */
        "jle .Lf185fe2_00186288\n"
        ".Lf185fe2_001860a4:\n"
        "movl 0x195ee78, %eax\n" /* line 1582 */
        "movl (%eax), %ecx\n"
        "movl 0x195f60c, %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x407c8(%ebx), %eax\n" /* cmd */
        "subl 8(%edx), %eax\n"
        "subl $1, %eax\n"
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x4945c(%ecx), %edi\n" /* compressedSize */
        "subl 0x49460(%ecx, %eax, 4), %edi\n" /* compressedSize */
        "cmpl $0x20, %edi\n" /* line 1583 | compressedSize */
        "jg .Lf185fe2_00186365\n"
        "testl %edi, %edi\n" /* line 1588 | compressedSize */
        "jle .Lf185fe2_00186405\n"
        ".Lf185fe2_001860e2:\n"
        "movl 0x195f618, %eax\n" /* line 1590 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf185fe2_0018637b\n"
        ".Lf185fe2_001860f3:\n"
        "movl 0x195f61c, %eax\n" /* line 1596 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf185fe2_00186112\n"
        "movl 0x195ee78, %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x18(%edx), %ebx\n" /* cmd */
        "testl %ebx, %ebx\n" /* cmd */
        "jne .Lf185fe2_0018630c\n"
        ".Lf185fe2_00186112:\n"
        "movl $3, 8(%esp)\n" /* line 1598 */
        "movl $1, 4(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* buf */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteBits\n"
        ".Lf185fe2_0018612d:\n"
        "movl %edi, 4(%esp)\n" /* line 1606 | compressedSize */
        "leal -0x30(%ebp), %edx\n" /* buf */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 0x195ee8c, %eax\n" /* line 1609 */
        "movl (%eax), %edx\n"
        "movl 0x20138(%edx), %eax\n" /* line 1611 */
        "movl %eax, -0x8060(%ebp)\n"
        "movl 0x12c(%edx), %eax\n"
        "xorl %eax, -0x8060(%ebp)\n"
        "movl $0x20, 4(%esp)\n" /* line 1613 */
        "movl 0x2013c(%edx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x20144(%eax, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_HashKey\n"
        "xorl %eax, -0x8060(%ebp)\n"
        "testl %edi, %edi\n" /* line 1623 | compressedSize */
        "jg .Lf185fe2_00186390\n"
        "leal -0x4c(%ebp), %edx\n" /* nullcmd */
        "movl %edx, -0x805c(%ebp)\n"
        ".Lf185fe2_00186195:\n"
        "movl $3, 8(%esp)\n" /* line 1632 */
        "movl $3, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBits\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1635 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x804c(%ebp)\n" /* compressedBuf */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x8048(%ebp)\n"
        "movzbl 8(%edx), %eax\n"
        "movb %al, -0x8044(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* line 1636 */
        "subl $9, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x8043(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "addl $9, %edx\n"
        "movl %edx, (%esp)\n"
        "calll MSG_WriteBitsCompress\n"
        "leal 9(%eax), %edi\n" /* compressedSize */
        "movl 0x195ee8c, %edx\n" /* line 1641 */
        "movl (%edx), %esi\n" /* i */
        "movl 0x407c8(%esi), %eax\n" /* i */
        "andl $0x1f, %eax\n"
        "movl 0x195ee78, %edx\n" /* line 1642 */
        "movl (%edx), %ebx\n" /* cmd */
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* cmd */
        "movl 0x195ecac, %ecx\n"
        "movl 0x118(%ecx), %edx\n"
        "movl %edx, 0x49468(%eax)\n"
        "movl -0x805c(%ebp), %edx\n" /* line 1643 */
        "movl (%edx), %edx\n"
        "movl %edx, 0x49464(%eax)\n"
        "movl 0x4945c(%ebx), %edx\n" /* line 1644 | cmd */
        "movl %edx, 0x49460(%eax)\n"
        "movl 0x118(%ecx), %eax\n" /* line 1645 */
        "movl %eax, 0xc(%esi)\n" /* i */
        "movl 0x195f618, %eax\n" /* line 1647 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf185fe2_00186350\n"
        ".Lf185fe2_00186255:\n"
        "movl %edi, 8(%esp)\n" /* line 1652 | compressedSize */
        "leal -0x804c(%ebp), %eax\n" /* compressedBuf */
        "movl %eax, 4(%esp)\n"
        "leal 0x407c8(%esi), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll CL_Netchan_Transmit\n"
        "movl %esi, %eax\n" /* line 1657 | i */
        "movl 0x447f0(%esi), %edx\n" /* i */
        "testl %edx, %edx\n"
        "jne .Lf185fe2_001862e2\n"
        /* } scope */
        ".Lf185fe2_0018627d:\n"
        "addl $0x806c, %esp\n" /* line 1661 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf185fe2_00186288:\n"
        "movl $3, 8(%esp)\n" /* line 1573 */
        "movl $2, 4(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* buf */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteBits\n"
        "movl %esi, 4(%esp)\n" /* line 1574 | i */
        "leal -0x30(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl %esi, %eax\n" /* line 1575 | i */
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "movl (%edi), %ebx\n" /* compressedSize, cmd */
        "leal 0x138(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* buf */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteString\n"
        "addl $1, %esi\n" /* line 1571 | i */
        "cmpl 0x130(%ebx), %esi\n" /* cmd, i */
        "jle .Lf185fe2_00186288\n"
        "jmp .Lf185fe2_001860a4\n"
        ".Lf185fe2_001862e2:\n"
        "movl 0x195ee8c, %ebx\n" /* cmd */
        ".Lf185fe2_001862e8:\n"
        "addl $0x407c8, %eax\n" /* line 1659 */
        "movl %eax, (%esp)\n"
        "calll CL_Netchan_TransmitNextFragment\n"
        "movl (%ebx), %eax\n" /* line 1657 | cmd */
        "movl 0x447f0(%eax), %edi\n" /* compressedSize */
        "testl %edi, %edi\n" /* compressedSize */
        "jne .Lf185fe2_001862e8\n"
        /* } scope */
        "addl $0x806c, %esp\n" /* line 1661 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf185fe2_0018630c:\n"
        "movl 0x195ee8c, %eax\n" /* line 1596 */
        "movl (%eax), %eax\n"
        "movl 0x407a8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf185fe2_00186112\n"
        "movl 0x20138(%eax), %eax\n"
        "cmpl 0x24(%edx), %eax\n"
        "jne .Lf185fe2_00186112\n"
        "movl $3, 8(%esp)\n" /* line 1602 */
        "movl $0, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBits\n"
        "jmp .Lf185fe2_0018612d\n"
        ".Lf185fe2_00186350:\n"
        "movl %edi, 4(%esp)\n" /* line 1649 | compressedSize */
        "movl $0x217fac, (%esp)\n" /* "%i " */
        "calll Com_Printf\n"
        "jmp .Lf185fe2_00186255\n"
        ".Lf185fe2_00186365:\n"
        "movl $0x2af63c, (%esp)\n" /* line 1586 */
        "calll Com_Printf\n"
        "movl $0x20, %edi\n" /* compressedSize */
        "jmp .Lf185fe2_001860e2\n"
        ".Lf185fe2_0018637b:\n"
        "movl %edi, 4(%esp)\n" /* line 1592 | compressedSize */
        "movl $0x2af654, (%esp)\n" /* "(%i)" */
        "calll Com_Printf\n"
        "jmp .Lf185fe2_001860f3\n"
        ".Lf185fe2_00186390:\n"
        "leal -0x4c(%ebp), %ecx\n" /* line 1623 | nullcmd */
        "xorl %esi, %esi\n" /* i */
        "movl 0x195ee78, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x8064(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf185fe2_001863ac\n"
        ".Lf185fe2_001863a6:\n"
        "movl -0x8064(%ebp), %edx\n"
        ".Lf185fe2_001863ac:\n"
        "movl 0x4945c(%edx), %eax\n" /* line 1626 */
        "subl %edi, %eax\n" /* compressedSize */
        "leal 1(%esi, %eax), %eax\n" /* i */
        "andl $0x7f, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "movl -0x8064(%ebp), %edx\n"
        "leal 0x4865c(%eax, %edx), %ebx\n" /* cmd */
        "movl %ebx, 0xc(%esp)\n" /* line 1627 | cmd */
        "movl %ecx, 8(%esp)\n"
        "movl -0x8060(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* buf */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaUsercmdKey\n"
        "addl $1, %esi\n" /* line 1623 | i */
        "movl %ebx, %ecx\n" /* cmd */
        "cmpl %edi, %esi\n" /* compressedSize, i */
        "jne .Lf185fe2_001863a6\n"
        "movl %ebx, -0x805c(%ebp)\n" /* cmd */
        "jmp .Lf185fe2_00186195\n"
        ".Lf185fe2_00186405:\n"
        "leal -0x4c(%ebp), %eax\n" /* line 1588 | nullcmd */
        "movl %eax, -0x805c(%ebp)\n"
        "jmp .Lf185fe2_00186195\n"
    );
}

/* line 1730 */
__attribute__((naked))
void CL_InitInput(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1730 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $IN_CenterView, 4(%esp)\n" /* line 1732 */
        "movl $0x2abfcc, (%esp)\n" /* "centerview" */
        "calll Cmd_AddCommand\n"
        "movl $IN_UpDown, 4(%esp)\n" /* line 1734 */
        "movl $0x2abf84, (%esp)\n" /* "+moveup" */
        "calll Cmd_AddCommand\n"
        "movl $IN_UpUp, 4(%esp)\n" /* line 1735 */
        "movl $0x2af65c, (%esp)\n" /* "-moveup" */
        "calll Cmd_AddCommand\n"
        "movl $IN_DownDown, 4(%esp)\n" /* line 1736 */
        "movl $0x2abf8c, (%esp)\n" /* "+movedown" */
        "calll Cmd_AddCommand\n"
        "movl $IN_DownUp, 4(%esp)\n" /* line 1737 */
        "movl $0x2af664, (%esp)\n" /* "-movedown" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LeftDown, 4(%esp)\n" /* line 1738 */
        "movl $0x2abf98, (%esp)\n" /* "+left" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LeftUp, 4(%esp)\n" /* line 1739 */
        "movl $0x2af670, (%esp)\n" /* "-left" */
        "calll Cmd_AddCommand\n"
        "movl $IN_RightDown, 4(%esp)\n" /* line 1740 */
        "movl $0x2abfa0, (%esp)\n" /* "+right" */
        "calll Cmd_AddCommand\n"
        "movl $IN_RightUp, 4(%esp)\n" /* line 1741 */
        "movl $0x2af678, (%esp)\n" /* "-right" */
        "calll Cmd_AddCommand\n"
        "movl $IN_ForwardDown, 4(%esp)\n" /* line 1742 */
        "movl $0x2abf58, (%esp)\n" /* "+forward" */
        "calll Cmd_AddCommand\n"
        "movl $IN_ForwardUp, 4(%esp)\n" /* line 1743 */
        "movl $0x2af680, (%esp)\n" /* "-forward" */
        "calll Cmd_AddCommand\n"
        "movl $IN_BackDown, 4(%esp)\n" /* line 1744 */
        "movl $0x2abf64, (%esp)\n" /* "+back" */
        "calll Cmd_AddCommand\n"
        "movl $IN_BackUp, 4(%esp)\n" /* line 1745 */
        "movl $0x2af68c, (%esp)\n" /* "-back" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LookupDown, 4(%esp)\n" /* line 1746 */
        "movl $0x2abfb0, (%esp)\n" /* "+lookup" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LookupUp, 4(%esp)\n" /* line 1747 */
        "movl $0x2af694, (%esp)\n" /* "-lookup" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LookdownDown, 4(%esp)\n" /* line 1748 */
        "movl $0x2abfb8, (%esp)\n" /* "+lookdown" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LookdownUp, 4(%esp)\n" /* line 1749 */
        "movl $0x2af69c, (%esp)\n" /* "-lookdown" */
        "calll Cmd_AddCommand\n"
        "movl $IN_StrafeDown, 4(%esp)\n" /* line 1750 */
        "movl $0x2abfa8, (%esp)\n" /* "+strafe" */
        "calll Cmd_AddCommand\n"
        "movl $IN_StrafeUp, 4(%esp)\n" /* line 1751 */
        "movl $0x2af6a8, (%esp)\n" /* "-strafe" */
        "calll Cmd_AddCommand\n"
        "movl $IN_MoveleftDown, 4(%esp)\n" /* line 1752 */
        "movl $0x2abf6c, (%esp)\n" /* "+moveleft" */
        "calll Cmd_AddCommand\n"
        "movl $IN_MoveleftUp, 4(%esp)\n" /* line 1753 */
        "movl $0x2af6b0, (%esp)\n" /* "-moveleft" */
        "calll Cmd_AddCommand\n"
        "movl $IN_MoverightDown, 4(%esp)\n" /* line 1754 */
        "movl $0x2abf78, (%esp)\n" /* "+moveright" */
        "calll Cmd_AddCommand\n"
        "movl $IN_MoverightUp, 4(%esp)\n" /* line 1755 */
        "movl $0x2af6bc, (%esp)\n" /* "-moveright" */
        "calll Cmd_AddCommand\n"
        "movl $IN_SpeedDown, 4(%esp)\n" /* line 1756 */
        "movl $0x2abf50, (%esp)\n" /* "+speed" */
        "calll Cmd_AddCommand\n"
        "movl $IN_SpeedUp, 4(%esp)\n" /* line 1757 */
        "movl $0x2af6c8, (%esp)\n" /* "-speed" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Attack_Down, 4(%esp)\n" /* line 1759 */
        "movl $0x2abfd8, (%esp)\n" /* "+attack" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Attack_Up, 4(%esp)\n" /* line 1760 */
        "movl $0x2af6d0, (%esp)\n" /* "-attack" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Melee_Down, 4(%esp)\n" /* line 1762 */
        "movl $0x2ac0cc, (%esp)\n" /* "+melee" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Melee_Up, 4(%esp)\n" /* line 1763 */
        "movl $0x2af6d8, (%esp)\n" /* "-melee" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Breath_Down, 4(%esp)\n" /* line 1765 */
        "movl $0x2ac0d4, (%esp)\n" /* "+holdbreath" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Breath_Up, 4(%esp)\n" /* line 1766 */
        "movl $0x2af6e0, (%esp)\n" /* "-holdbreath" */
        "calll Cmd_AddCommand\n"
        "movl $IN_MeleeBreath_Down, 4(%esp)\n" /* line 1768 */
        "movl $0x2ac0e0, (%esp)\n" /* "+melee_breath" */
        "calll Cmd_AddCommand\n"
        "movl $IN_MeleeBreath_Up, 4(%esp)\n" /* line 1769 */
        "movl $0x2af6ec, (%esp)\n" /* "-melee_breath" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Frag_Down, 4(%esp)\n" /* line 1771 */
        "movl $0x2abff8, (%esp)\n" /* "+frag" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Frag_Up, 4(%esp)\n" /* line 1772 */
        "movl $0x2af6fc, (%esp)\n" /* "-frag" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Smoke_Down, 4(%esp)\n" /* line 1774 */
        "movl $0x2ac000, (%esp)\n" /* "+smoke" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Smoke_Up, 4(%esp)\n" /* line 1775 */
        "movl $0x2af704, (%esp)\n" /* "-smoke" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Binoculars_Down, 4(%esp)\n" /* line 1777 */
        "movl $0x2ac0ac, (%esp)\n" /* "+binoculars" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Binoculars_Up, 4(%esp)\n" /* line 1778 */
        "movl $0x2af70c, (%esp)\n" /* "-binoculars" */
        "calll Cmd_AddCommand\n"
        "movl $IN_BreathBinoculars_Down, 4(%esp)\n" /* line 1780 */
        "movl $0x2ac0b8, (%esp)\n" /* "+breath_binoculars" */
        "calll Cmd_AddCommand\n"
        "movl $IN_BreathBinoculars_Up, 4(%esp)\n" /* line 1781 */
        "movl $0x2af718, (%esp)\n" /* "-breath_binoculars" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Activate_Down, 4(%esp)\n" /* line 1783 */
        "movl $0x2ac020, (%esp)\n" /* "+activate" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Activate_Up, 4(%esp)\n" /* line 1784 */
        "movl $0x2af72c, (%esp)\n" /* "-activate" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Reload_Down, 4(%esp)\n" /* line 1786 */
        "movl $0x2ac02c, (%esp)\n" /* "+reload" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Reload_Up, 4(%esp)\n" /* line 1787 */
        "movl $0x2af738, (%esp)\n" /* "-reload" */
        "calll Cmd_AddCommand\n"
        "movl $IN_UseReload_Down, 4(%esp)\n" /* line 1789 */
        "movl $0x2ac054, (%esp)\n" /* "+usereload" */
        "calll Cmd_AddCommand\n"
        "movl $IN_UseReload_Up, 4(%esp)\n" /* line 1790 */
        "movl $0x2af740, (%esp)\n" /* "-usereload" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LeanLeft_Down, 4(%esp)\n" /* line 1792 */
        "movl $0x2ac03c, (%esp)\n" /* "+leanleft" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LeanLeft_Up, 4(%esp)\n" /* line 1793 */
        "movl $0x2af74c, (%esp)\n" /* "-leanleft" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LeanRight_Down, 4(%esp)\n" /* line 1795 */
        "movl $0x2ac048, (%esp)\n" /* "+leanright" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LeanRight_Up, 4(%esp)\n" /* line 1796 */
        "movl $0x2af758, (%esp)\n" /* "-leanright" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Prone_Down, 4(%esp)\n" /* line 1798 */
        "movl $0x2ac0f0, (%esp)\n" /* "+prone" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Prone_Up, 4(%esp)\n" /* line 1799 */
        "movl $0x2af764, (%esp)\n" /* "-prone" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Stance_Down, 4(%esp)\n" /* line 1801 */
        "movl $0x2ac0f8, (%esp)\n" /* "+stance" */
        "calll Cmd_AddCommand\n"
        "movl $IN_Stance_Up, 4(%esp)\n" /* line 1802 */
        "movl $0x2af76c, (%esp)\n" /* "-stance" */
        "calll Cmd_AddCommand\n"
        "movl $IN_MLookDown, 4(%esp)\n" /* line 1804 */
        "movl $0x2abfc4, (%esp)\n" /* "+mlook" */
        "calll Cmd_AddCommand\n"
        "movl $IN_MLookUp, 4(%esp)\n" /* line 1805 */
        "movl $0x2af774, (%esp)\n" /* "-mlook" */
        "calll Cmd_AddCommand\n"
        "movl $IN_ToggleADS, 4(%esp)\n" /* line 1807 */
        "movl $0x2ac154, (%esp)\n" /* "toggleads" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LeaveADS, 4(%esp)\n" /* line 1808 */
        "movl $0x2ac160, (%esp)\n" /* "leaveads" */
        "calll Cmd_AddCommand\n"
        "movl $IN_LowerStance, 4(%esp)\n" /* line 1810 */
        "movl $0x2ac100, (%esp)\n" /* "lowerstance" */
        "calll Cmd_AddCommand\n"
        "movl $IN_RaiseStance, 4(%esp)\n" /* line 1812 */
        "movl $0x2ac10c, (%esp)\n" /* "raisestance" */
        "calll Cmd_AddCommand\n"
        "movl $IN_ToggleCrouch, 4(%esp)\n" /* line 1814 */
        "movl $0x2ac118, (%esp)\n" /* "togglecrouch" */
        "calll Cmd_AddCommand\n"
        "movl $IN_ToggleProne, 4(%esp)\n" /* line 1816 */
        "movl $0x2ac128, (%esp)\n" /* "toggleprone" */
        "calll Cmd_AddCommand\n"
        "movl $IN_GoProne, 4(%esp)\n" /* line 1818 */
        "movl $0x2ac134, (%esp)\n" /* "goprone" */
        "calll Cmd_AddCommand\n"
        "movl $IN_GoCrouch, 4(%esp)\n" /* line 1819 */
        "movl $0x2ac13c, (%esp)\n" /* "gocrouch" */
        "calll Cmd_AddCommand\n"
        "movl $IN_GoStandDown, 4(%esp)\n" /* line 1820 */
        "movl $0x2ac148, (%esp)\n" /* "+gostand" */
        "calll Cmd_AddCommand\n"
        "movl $IN_GoStandUp, 4(%esp)\n" /* line 1821 */
        "movl $0x2af77c, (%esp)\n" /* "-gostand" */
        "calll Cmd_AddCommand\n"
        "movl $IN_TalkDown, 4(%esp)\n" /* line 1831 */
        "movl $0x2ac16c, (%esp)\n" /* "+talk" */
        "calll Cmd_AddCommand\n"
        "movl $IN_TalkUp, 4(%esp)\n" /* line 1832 */
        "movl $0x2af788, (%esp)\n" /* "-talk" */
        "calll Cmd_AddCommand\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 1835 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $0x38d1b717, 8(%esp)\n"
        "movl $0x3f4ccccd, 4(%esp)\n"
        "movl $0x2af790, (%esp)\n" /* "cl_analog_attack_threshold" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cl_analog_attack_threshold\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 1836 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x12c, 4(%esp)\n"
        "movl $0x2af7ac, (%esp)\n" /* "cl_stanceHoldTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cl_stanceHoldTime\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1837 */
        "movl $0, 4(%esp)\n"
        "movl $0x2af7c0, (%esp)\n" /* "cl_nodelta" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f61c, %edx\n"
        "movl %eax, (%edx)\n"
        "leave\n" /* line 1838 */
        "retl\n"
    );
}

/* line 1846 */
__attribute__((naked))
void CL_ShutdownInput(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1846 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2abfcc, (%esp)\n" /* line 1848 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abf84, (%esp)\n" /* line 1850 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af65c, (%esp)\n" /* line 1851 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abf8c, (%esp)\n" /* line 1852 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af664, (%esp)\n" /* line 1853 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abf98, (%esp)\n" /* line 1854 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af670, (%esp)\n" /* line 1855 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abfa0, (%esp)\n" /* line 1856 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af678, (%esp)\n" /* line 1857 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abf58, (%esp)\n" /* line 1858 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af680, (%esp)\n" /* line 1859 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abf64, (%esp)\n" /* line 1860 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af68c, (%esp)\n" /* line 1861 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abfb0, (%esp)\n" /* line 1862 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af694, (%esp)\n" /* line 1863 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abfb8, (%esp)\n" /* line 1864 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af69c, (%esp)\n" /* line 1865 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abfa8, (%esp)\n" /* line 1866 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af6a8, (%esp)\n" /* line 1867 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abf6c, (%esp)\n" /* line 1868 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af6b0, (%esp)\n" /* line 1869 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abf78, (%esp)\n" /* line 1870 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af6bc, (%esp)\n" /* line 1871 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abf50, (%esp)\n" /* line 1872 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af6c8, (%esp)\n" /* line 1873 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abfd8, (%esp)\n" /* line 1875 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af6d0, (%esp)\n" /* line 1876 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac0cc, (%esp)\n" /* line 1878 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af6d8, (%esp)\n" /* line 1879 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac0d4, (%esp)\n" /* line 1881 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af6e0, (%esp)\n" /* line 1882 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac0e0, (%esp)\n" /* line 1884 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af6ec, (%esp)\n" /* line 1885 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abff8, (%esp)\n" /* line 1887 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af6fc, (%esp)\n" /* line 1888 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac000, (%esp)\n" /* line 1890 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af704, (%esp)\n" /* line 1891 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac0ac, (%esp)\n" /* line 1893 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af70c, (%esp)\n" /* line 1894 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac0b8, (%esp)\n" /* line 1896 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af718, (%esp)\n" /* line 1897 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac020, (%esp)\n" /* line 1899 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af72c, (%esp)\n" /* line 1900 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac02c, (%esp)\n" /* line 1902 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af738, (%esp)\n" /* line 1903 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac054, (%esp)\n" /* line 1905 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af740, (%esp)\n" /* line 1906 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac03c, (%esp)\n" /* line 1908 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af74c, (%esp)\n" /* line 1909 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac048, (%esp)\n" /* line 1911 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af758, (%esp)\n" /* line 1912 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac0f0, (%esp)\n" /* line 1914 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af764, (%esp)\n" /* line 1915 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac0f8, (%esp)\n" /* line 1917 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af76c, (%esp)\n" /* line 1918 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2abfc4, (%esp)\n" /* line 1920 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af774, (%esp)\n" /* line 1921 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac154, (%esp)\n" /* line 1923 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac160, (%esp)\n" /* line 1924 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac100, (%esp)\n" /* line 1926 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac10c, (%esp)\n" /* line 1928 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac118, (%esp)\n" /* line 1930 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac128, (%esp)\n" /* line 1932 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac134, (%esp)\n" /* line 1934 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac13c, (%esp)\n" /* line 1935 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac148, (%esp)\n" /* line 1936 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af77c, (%esp)\n" /* line 1937 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2ac16c, (%esp)\n" /* line 1947 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2af788, (%esp)\n" /* line 1948 */
        "calll Cmd_RemoveCommand\n"
        "leave\n" /* line 1950 */
        "retl\n"
    );
}

/* line 1259 */
__attribute__((naked))
void CL_CmdButtons(usercmd_t *cmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1259 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* cmd */
        "leal 4(%ecx), %esi\n" /* line 1263 | cmdButtons */
        /* { scope 1 */
        "movl kb, %edx\n" /* line 1061 */
        "leal 0x118(%edx), %eax\n"
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186d6c\n"
        "orl $1, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186d6c:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        /* } scope */
        "leal 0x12c(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186d84\n"
        "orl $0x8000, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186d84:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x140(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186d9c\n"
        "orl $0x10000, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186d9c:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x154(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186db4\n"
        "orl $0x20000, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186db4:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x168(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186dcc\n"
        "orl $0x4000, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186dcc:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x17c(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186de1\n"
        "orl $4, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186de1:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x190(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186df6\n"
        "orl $8, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186df6:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x1a4(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186e0b\n"
        "orl $0x10, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186e0b:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x1b8(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186e20\n"
        "orl $0x20, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186e20:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x1cc(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186e35\n"
        "orl $0x40, 4(%ecx)\n" /* line 1063 */
        ".Lf186d4a_00186e35:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x1e0(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186e4c\n"
        "orl $0x80, (%esi)\n" /* line 1063 */
        ".Lf186d4a_00186e4c:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x1f4(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186e63\n"
        "orl $0x100, (%esi)\n" /* line 1063 */
        ".Lf186d4a_00186e63:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0x208(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186e7a\n"
        "orl $0x200, (%esi)\n" /* line 1063 */
        ".Lf186d4a_00186e7a:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "leal 0xc8(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf186d4a_00186e91\n"
        "orl $0x400, (%esi)\n" /* line 1063 */
        ".Lf186d4a_00186e91:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        "movl 0x195ee78, %ebx\n" /* line 1278 */
        "movl (%ebx), %eax\n"
        "cmpl $0, 4(%eax)\n"
        "je .Lf186d4a_00186eb0\n"
        "movl cl_bypassMouseInput, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf186d4a_00186eeb\n"
        "movl (%ebx), %eax\n"
        ".Lf186d4a_00186eb0:\n"
        "movl 0x38(%eax), %eax\n" /* line 1285 */
        "subl $2, %eax\n"
        "cmpl $2, %eax\n"
        "ja .Lf186d4a_00186ecc\n"
        "leal 0xf0(%edx), %eax\n" /* line 1061 */
        "cmpw $0, 0x10(%eax)\n"
        "jne .Lf186d4a_00186ee3\n"
        ".Lf186d4a_00186ec8:\n"
        "movb $0, 0x11(%eax)\n" /* line 1066 */
        ".Lf186d4a_00186ecc:\n"
        "movl (%ebx), %eax\n" /* line 1288 */
        "movl 0x8600(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf186d4a_00186edf\n"
        "orl $0x800, 4(%ecx)\n" /* line 1289 */
        ".Lf186d4a_00186edf:\n"
        "popl %ebx\n" /* line 1292 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf186d4a_00186ee3:\n"
        "orl $0x400, (%esi)\n" /* line 1063 */
        "jmp .Lf186d4a_00186ec8\n"
        ".Lf186d4a_00186eeb:\n"
        "orl $0x40000, 4(%ecx)\n" /* line 1283 */
        "movl (%ebx), %eax\n"
        "jmp .Lf186d4a_00186eb0\n"
    );
}

/* line 1168 */
__attribute__((naked))
void CL_MouseMove(usercmd_t *cmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1168 */
        "movl %esp, %ebp\n"
        "subl $0x58, %esp\n"
        /* { scope 1 */
        "movl 0x195f630, %eax\n" /* line 1177 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf186ef6_00186f76\n"
        "movl 0x195ee78, %ecx\n" /* line 1179 */
        "movl (%ecx), %edx\n"
        "movl 0x85d8(%edx), %eax\n"
        "addl 0x85dc(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm4\n"
        "movss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm0, %xmm4\n"
        "movl 0x85e0(%edx), %eax\n" /* line 1180 */
        "addl 0x85e4(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm3\n"
        "mulss %xmm0, %xmm3\n"
        "movl %edx, %eax\n"
        ".Lf186ef6_00186f43:\n"
        "movl 0x85e8(%eax), %edx\n" /* line 1187 */
        "xorl $1, %edx\n"
        "movl %edx, 0x85e8(%eax)\n"
        "movl $0, 0x85d8(%eax, %edx, 4)\n" /* line 1188 */
        "movl $0, 0x85e0(%eax, %edx, 4)\n" /* line 1189 */
        "movl 0x195f638, %eax\n" /* line 1191 */
        "movl (%eax), %edx\n"
        "cmpl $0, %edx\n"
        "jne .Lf186ef6_00186f98\n"
        /* } scope */
        ".Lf186ef6_00186f74:\n"
        "leave\n" /* line 1251 */
        "retl\n"
        /* { scope 1 */
        ".Lf186ef6_00186f76:\n"
        "movl 0x195ee78, %ecx\n" /* line 1184 */
        "movl (%ecx), %eax\n"
        "movl 0x85e8(%eax), %edx\n"
        "cvtsi2ssl 0x85d8(%eax, %edx, 4), %xmm4\n"
        "cvtsi2ssl 0x85e0(%eax, %edx, 4), %xmm3\n" /* line 1185 */
        "jmp .Lf186ef6_00186f43\n"
        ".Lf186ef6_00186f98:\n"
        "movaps %xmm4, %xmm0\n" /* line 81 */
        "mulss %xmm4, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "jl .Lf186ef6_0018722e\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf186ef6_00186fb8:\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movl 0x195f614, %eax\n" /* line 1195 */
        "movl (%eax), %edx\n"
        "movl 0x195f620, %eax\n"
        "movl (%eax), %eax\n"
        "movaps %xmm1, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "addss 8(%edx), %xmm2\n"
        "movl (%ecx), %eax\n" /* line 1198 */
        "mulss 0x8604(%eax), %xmm2\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 1199 | 0.0f */
        "jp .Lf186ef6_00186fef\n"
        "je .Lf186ef6_00187004\n"
        ".Lf186ef6_00186fef:\n"
        "movl 0x195f62c, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf186ef6_001871ba\n"
        "movl (%ecx), %edx\n"
        "jmp .Lf186ef6_00187006\n"
        ".Lf186ef6_00187004:\n"
        "movl %eax, %edx\n"
        ".Lf186ef6_00187006:\n"
        "cmpw $0, 0x40(%edx)\n" /* line 1203 */
        "js .Lf186ef6_00186f74\n"
        "testl $0x300, 0xd4(%edx)\n" /* line 1206 */
        "je .Lf186ef6_001871aa\n"
        "movaps %xmm4, %xmm0\n" /* line 1208 */
        "mulss 0x2ed6c0, %xmm0\n" /* 2.5f */
        "addss %xmm3, %xmm3\n" /* line 1209 */
        ".Lf186ef6_00187030:\n"
        "pxor %xmm4, %xmm4\n" /* line 1217 */
        "ucomiss %xmm4, %xmm0\n"
        "jne .Lf186ef6_00187046\n"
        "jp .Lf186ef6_00187046\n"
        "ucomiss %xmm4, %xmm3\n"
        "jp .Lf186ef6_00187046\n"
        "je .Lf186ef6_00186f74\n"
        ".Lf186ef6_00187046:\n"
        "movl kb, %eax\n" /* line 1221 */
        "cmpb $0, 0xb0(%eax)\n"
        "jne .Lf186ef6_00187244\n"
        "movl 0x195f628, %eax\n" /* line 1227 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "movss 0x860c(%edx), %xmm1\n" /* line 1228 */
        "ucomiss %xmm4, %xmm1\n"
        "jp .Lf186ef6_00187076\n"
        "je .Lf186ef6_001870d2\n"
        ".Lf186ef6_00187076:\n"
        "movl 0x195f638, %eax\n" /* line 1230 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "js .Lf186ef6_0018727a\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        ".Lf186ef6_00187089:\n"
        "mulss %xmm1, %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm5\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm5\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm5, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "xorps 0x302d40, %xmm0\n" /* line 1231 */
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm2, %xmm1\n"
        "movaps %xmm2, %xmm5\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm5\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm5, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        ".Lf186ef6_001870d2:\n"
        "movss 0x8620(%edx), %xmm0\n" /* line 1233 */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 0x8620(%edx)\n"
        ".Lf186ef6_001870e6:\n"
        "movl kb, %edx\n" /* line 1236 */
        "cmpb $0, 0x114(%edx)\n"
        "jne .Lf186ef6_00187106\n"
        "movl 0x195f624, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf186ef6_00187205\n"
        ".Lf186ef6_00187106:\n"
        "cmpb $0, 0xb0(%edx)\n"
        "jne .Lf186ef6_00187205\n"
        /* { scope 2 */
        "movl 0x195f634, %eax\n" /* line 1238 */
        "movl (%eax), %eax\n"
        "movaps %xmm3, %xmm2\n" /* delta */
        "mulss 8(%eax), %xmm2\n" /* delta */
        "movl 0x195ee78, %eax\n" /* line 1240 */
        "movl (%eax), %ecx\n"
        "movss 0x8608(%ecx), %xmm1\n"
        "pxor %xmm4, %xmm4\n"
        "ucomiss %xmm4, %xmm1\n"
        "jp .Lf186ef6_0018713c\n"
        "je .Lf186ef6_00187198\n"
        ".Lf186ef6_0018713c:\n"
        "movl 0x195f638, %eax\n" /* line 1242 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf186ef6_00187290\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf186ef6_0018714f:\n"
        "mulss %xmm1, %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm3\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm3\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm3, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "xorps 0x302d40, %xmm0\n" /* line 1243 */
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm2, %xmm1\n"
        "movaps %xmm2, %xmm5\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm5\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm5, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        ".Lf186ef6_00187198:\n"
        "addss 0x861c(%ecx), %xmm2\n" /* line 1245 */
        "movss %xmm2, 0x861c(%ecx)\n"
        /* } scope */
        /* } scope */
        "leave\n" /* line 1251 */
        "retl\n"
        /* { scope 1 */
        ".Lf186ef6_001871aa:\n"
        "movaps %xmm4, %xmm0\n" /* line 1213 */
        "mulss %xmm2, %xmm0\n"
        "mulss %xmm2, %xmm3\n" /* line 1214 */
        "jmp .Lf186ef6_00187030\n"
        ".Lf186ef6_001871ba:\n"
        "cvtss2sd %xmm2, %xmm1\n" /* line 1200 */
        "movsd %xmm1, 0xc(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x2af7cc, (%esp)\n" /* "%f : %f
" */
        "movss %xmm2, -0x18(%ebp)\n"
        "movss %xmm3, -0x28(%ebp)\n"
        "movss %xmm4, -0x38(%ebp)\n"
        "calll Com_Printf\n"
        "movl 0x195ee78, %ecx\n"
        "movss -0x38(%ebp), %xmm4\n"
        "movss -0x28(%ebp), %xmm3\n"
        "movss -0x18(%ebp), %xmm2\n"
        "movl (%ecx), %edx\n"
        "jmp .Lf186ef6_00187006\n"
        ".Lf186ef6_00187205:\n"
        "movl 8(%ebp), %eax\n" /* line 1249 | cmd */
        "movsbl 0x18(%eax), %edx\n"
        "movl 0x195f610, %eax\n"
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm3\n"
        "cvttss2si %xmm3, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, (%esp)\n"
        "calll ClampChar\n"
        "movl 8(%ebp), %edx\n" /* cmd */
        "movb %al, 0x18(%edx)\n"
        /* } scope */
        "leave\n" /* line 1251 */
        "retl\n"
        /* { scope 1 */
        ".Lf186ef6_0018722e:\n"
        "movl %edx, %eax\n" /* line 81 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf186ef6_00186fb8\n"
        ".Lf186ef6_00187244:\n"
        "movl 8(%ebp), %eax\n" /* line 1223 | cmd */
        "movsbl 0x19(%eax), %edx\n"
        "movl 0x195f608, %eax\n"
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, (%esp)\n"
        "movss %xmm3, -0x28(%ebp)\n"
        "calll ClampChar\n"
        "movl 8(%ebp), %edx\n" /* cmd */
        "movb %al, 0x19(%edx)\n"
        "movss -0x28(%ebp), %xmm3\n"
        "jmp .Lf186ef6_001870e6\n"
        ".Lf186ef6_0018727a:\n"
        "movl %ecx, %eax\n" /* line 1230 */
        "shrl $1, %eax\n"
        "andl $1, %ecx\n"
        "orl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf186ef6_00187089\n"
        /* { scope 2 */
        ".Lf186ef6_00187290:\n"
        "movl %edx, %eax\n" /* line 1242 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf186ef6_0018714f\n"
    );
}

/* line 308 */
__attribute__((naked))
void IN_DownDown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 308 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 310 */
        "addl $0xdc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "movl kb, %eax\n" /* line 271 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf1872a6_001872e5\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf1872a6_001872e5\n"
        "movl 0x195ecb4, %eax\n" /* line 274 */
        "movl (%eax), %eax\n"
        "movl $0, 0xc(%eax)\n"
        "leave\n" /* line 312 */
        "retl\n"
        ".Lf1872a6_001872e5:\n"
        "movl 0x195ecb4, %eax\n" /* line 272 */
        "movl (%eax), %eax\n"
        "movl $1, 0xc(%eax)\n"
        "leave\n" /* line 312 */
        "retl\n"
    );
}

/* line 315 */
__attribute__((naked))
void IN_DownUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 315 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 317 */
        "addl $0xdc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "movl kb, %eax\n" /* line 271 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf1872f6_00187335\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf1872f6_00187335\n"
        "movl 0x195ecb4, %eax\n" /* line 274 */
        "movl (%eax), %eax\n"
        "movl $0, 0xc(%eax)\n"
        "leave\n" /* line 319 */
        "retl\n"
        ".Lf1872f6_00187335:\n"
        "movl 0x195ecb4, %eax\n" /* line 272 */
        "movl (%eax), %eax\n"
        "movl $1, 0xc(%eax)\n"
        "leave\n" /* line 319 */
        "retl\n"
    );
}

/* line 602 */
__attribute__((naked))
void IN_Prone_Down(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 602 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 604 */
        "addl $0x1f4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyDown\n"
        "movl kb, %eax\n" /* line 271 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf187346_00187385\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf187346_00187385\n"
        "movl 0x195ecb4, %eax\n" /* line 274 */
        "movl (%eax), %eax\n"
        "movl $0, 0xc(%eax)\n"
        "leave\n" /* line 606 */
        "retl\n"
        ".Lf187346_00187385:\n"
        "movl 0x195ecb4, %eax\n" /* line 272 */
        "movl (%eax), %eax\n"
        "movl $1, 0xc(%eax)\n"
        "leave\n" /* line 606 */
        "retl\n"
    );
}

/* line 609 */
__attribute__((naked))
void IN_Prone_Up(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 609 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kb, %eax\n" /* line 611 */
        "addl $0x1f4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll IN_KeyUp\n"
        "movl kb, %eax\n" /* line 271 */
        "cmpb $0, 0x204(%eax)\n"
        "jne .Lf187396_001873d5\n"
        "cmpb $0, 0xec(%eax)\n"
        "jne .Lf187396_001873d5\n"
        "movl 0x195ecb4, %eax\n" /* line 274 */
        "movl (%eax), %eax\n"
        "movl $0, 0xc(%eax)\n"
        "leave\n" /* line 613 */
        "retl\n"
        ".Lf187396_001873d5:\n"
        "movl 0x195ecb4, %eax\n" /* line 272 */
        "movl (%eax), %eax\n"
        "movl $1, 0xc(%eax)\n"
        "leave\n" /* line 613 */
        "retl\n"
    );
}

/* line 108 */
__attribute__((naked))
void IN_MLookUp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 108 */
        "movl %esp, %ebp\n"
        "movl kb, %eax\n" /* line 110 */
        "movb $0, 0x114(%eax)\n"
        "movl 0x195f624, %eax\n" /* line 111 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1873e6_00187421\n"
        "movl 0x195ee78, %eax\n" /* line 656 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x88(%eax), %xmm0\n"
        "mulss 0x2ed948, %xmm0\n" /* -0.0054931640625f */
        "movss %xmm0, 0x861c(%eax)\n"
        ".Lf1873e6_00187421:\n"
        "popl %ebp\n" /* line 113 */
        "retl\n"
    );
}

/* line 879 */
__attribute__((naked))
void CL_AdjustAngles(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 879 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        /* { scope 1 */
        "movl kb, %esi\n" /* line 883 */
        "cmpb $0, 0xc4(%esi)\n"
        "je .Lf187424_00187671\n"
        "movl 0x195ecac, %eax\n" /* line 884 */
        "cvtsi2ssl 0x114(%eax), %xmm2\n"
        "mulss 0x2ed658, %xmm2\n" /* 0.0010000000474974513f */
        "movl cl_anglespeedkey, %eax\n"
        "mulss 8(%eax), %xmm2\n"
        ".Lf187424_0018745f:\n"
        "cmpb $0, 0xb0(%esi)\n" /* line 888 */
        "jne .Lf187424_0018754c\n"
        "movl 0x195ee78, %eax\n" /* line 890 */
        "movl (%eax), %edi\n"
        "movss 0x8620(%edi), %xmm1\n"
        "movl cl_yawspeed, %eax\n"
        "movaps %xmm2, %xmm4\n"
        "mulss 8(%eax), %xmm4\n"
        "leal 0x14(%esi), %edx\n" /* key */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%edx), %ecx\n" /* line 229 */
        "movl $0, 0xc(%edx)\n" /* line 230 */
        "cmpb $0, 0x10(%edx)\n" /* line 232 */
        "jne .Lf187424_001876c7\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf187424_001874cd\n"
        ".Lf187424_001874a7:\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jae .Lf187424_00187741\n"
        "cvtsi2ssl %ecx, %xmm3\n" /* line 258 */
        "testl %edx, %edx\n"
        "js .Lf187424_001877a9\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf187424_001874c6:\n"
        "divss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf187424_001874cd:\n"
        "mulss %xmm4, %xmm0\n" /* line 890 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x8620(%edi)\n"
        "movl 0x195ee78, %edi\n" /* line 891 */
        "movl (%edi), %ebx\n"
        "movss 0x8620(%ebx), %xmm1\n"
        "movl cl_yawspeed, %eax\n"
        "movaps %xmm2, %xmm4\n"
        "mulss 8(%eax), %xmm4\n"
        /* { scope 2 */
        "movl 0xc(%esi), %ecx\n" /* line 229 */
        "movl $0, 0xc(%esi)\n" /* line 230 */
        "cmpb $0, 0x10(%esi)\n" /* line 232 */
        "jne .Lf187424_00187698\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf187424_0018753c\n"
        ".Lf187424_00187516:\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jae .Lf187424_0018774e\n"
        "cvtsi2ssl %ecx, %xmm3\n" /* line 258 */
        "testl %edx, %edx\n"
        "js .Lf187424_001877bf\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf187424_00187535:\n"
        "divss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        ".Lf187424_0018753c:\n"
        "mulss %xmm4, %xmm0\n" /* line 891 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x8620(%ebx)\n"
        ".Lf187424_0018754c:\n"
        "movl 0x195ee78, %ebx\n" /* line 894 */
        "movl (%ebx), %edi\n"
        "movss 0x861c(%edi), %xmm1\n"
        "movl cl_pitchspeed, %eax\n"
        "movaps %xmm2, %xmm4\n"
        "mulss 8(%eax), %xmm4\n"
        "leal 0x50(%esi), %edx\n" /* key */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%edx), %ecx\n" /* line 229 */
        "movl $0, 0xc(%edx)\n" /* line 230 */
        "cmpb $0, 0x10(%edx)\n" /* line 232 */
        "je .Lf187424_001875a0\n"
        "movl 8(%edx), %ebx\n" /* line 235 */
        "testl %ebx, %ebx\n"
        "je .Lf187424_001876fc\n"
        "movl 0x195f2d8, %eax\n" /* line 241 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl 0x195f2d8, %ebx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf187424_001875a0:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf187424_001875ce\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jae .Lf187424_0018768b\n"
        "cvtsi2ssl %ecx, %xmm3\n" /* line 258 */
        "testl %edx, %edx\n"
        "js .Lf187424_00187793\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf187424_001875c7:\n"
        "divss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf187424_001875ce:\n"
        "mulss %xmm4, %xmm0\n" /* line 894 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x861c(%edi)\n"
        "movl 0x195ee78, %eax\n" /* line 895 */
        "movl (%eax), %edi\n"
        "movss 0x861c(%edi), %xmm1\n"
        "movl cl_pitchspeed, %eax\n"
        "movaps %xmm2, %xmm3\n"
        "mulss 8(%eax), %xmm3\n"
        "leal 0x64(%esi), %edx\n" /* key */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%edx), %ecx\n" /* line 229 */
        "movl $0, 0xc(%edx)\n" /* line 230 */
        "cmpb $0, 0x10(%edx)\n" /* line 232 */
        "je .Lf187424_0018762b\n"
        "movl 8(%edx), %ebx\n" /* line 235 */
        "testl %ebx, %ebx\n"
        "je .Lf187424_0018770f\n"
        "movl 0x195f2d8, %esi\n" /* line 241 */
        "movl (%esi), %eax\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl %esi, %ebx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf187424_0018762b:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf187424_00187659\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jae .Lf187424_00187721\n"
        "cvtsi2ssl %ecx, %xmm2\n" /* line 258 */
        "testl %edx, %edx\n"
        "js .Lf187424_0018777d\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf187424_00187652:\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf187424_00187659:\n"
        "mulss %xmm3, %xmm0\n" /* line 895 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x861c(%edi)\n"
        /* } scope */
        "addl $4, %esp\n" /* line 896 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf187424_00187671:\n"
        "movl 0x195ecac, %eax\n" /* line 886 */
        "cvtsi2ssl 0x114(%eax), %xmm2\n"
        "mulss 0x2ed658, %xmm2\n" /* 0.0010000000474974513f */
        "jmp .Lf187424_0018745f\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_0018768b:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 255 | 1.0f */
        "jmp .Lf187424_001875ce\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf187424_00187698:\n"
        "movl 8(%esi), %edx\n" /* line 235 */
        "testl %edx, %edx\n"
        "je .Lf187424_0018776a\n"
        "movl 0x195f2d8, %edi\n" /* line 241 */
        "movl (%edi), %eax\n"
        "subl %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movl %edi, %edx\n"
        "movl (%edx), %eax\n" /* line 243 */
        "movl %eax, 8(%esi)\n"
        ".Lf187424_001876b6:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jg .Lf187424_00187516\n"
        "jmp .Lf187424_0018753c\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_001876c7:\n"
        "movl 8(%edx), %ebx\n" /* line 235 */
        "testl %ebx, %ebx\n"
        "je .Lf187424_0018775b\n"
        "movl 0x195f2d8, %eax\n" /* line 241 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl 0x195f2d8, %ebx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf187424_001876eb:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jg .Lf187424_001874a7\n"
        "jmp .Lf187424_001874cd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_001876fc:\n"
        "movl 0x195f2d8, %eax\n" /* line 237 */
        "movl (%eax), %ecx\n"
        "movl %eax, %ebx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf187424_001875a0\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_0018770f:\n"
        "movl 0x195f2d8, %ebx\n" /* line 237 */
        "movl (%ebx), %ecx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf187424_0018762b\n"
        ".Lf187424_00187721:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 255 | 1.0f */
        /* } scope */
        /* } scope */
        "mulss %xmm3, %xmm0\n" /* line 895 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x861c(%edi)\n"
        /* } scope */
        "addl $4, %esp\n" /* line 896 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_00187741:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 255 | 1.0f */
        "jmp .Lf187424_001874cd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf187424_0018774e:\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf187424_0018753c\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_0018775b:\n"
        "movl 0x195f2d8, %ebx\n" /* line 237 */
        "movl (%ebx), %ecx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf187424_001876eb\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf187424_0018776a:\n"
        "movl 0x195f2d8, %eax\n" /* line 237 */
        "movl (%eax), %ecx\n"
        "movl %eax, %edx\n"
        "movl (%edx), %eax\n" /* line 243 */
        "movl %eax, 8(%esi)\n"
        "jmp .Lf187424_001876b6\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_0018777d:\n"
        "movl %edx, %eax\n" /* line 258 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf187424_00187652\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_00187793:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf187424_001875c7\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_001877a9:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf187424_001874c6\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf187424_001877bf:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf187424_00187535\n"
    );
}

/* line 925 */
__attribute__((naked))
void CL_KeyMove(usercmd_t *cmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 925 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl kb, %ebx\n" /* line 931 */
        "cmpb $0, 0x204(%ebx)\n"
        "jne .Lf1877d6_0018780c\n"
        "cmpb $0, 0xec(%ebx)\n"
        "je .Lf1877d6_00187af2\n"
        "movl 8(%ebp), %esi\n" /* line 940 | cmd, side */
        "movl 4(%esi), %edx\n" /* side */
        "orb $2, %dh\n"
        "andb $0xfe, %dh\n" /* line 941 */
        "movl %edx, 4(%esi)\n" /* side */
        "jmp .Lf1877d6_0018781b\n"
        ".Lf1877d6_0018780c:\n"
        "movl 8(%ebp), %eax\n" /* line 935 | cmd */
        "movl 4(%eax), %edx\n"
        "orb $1, %dh\n"
        "andb $0xfd, %dh\n" /* line 936 */
        "movl %edx, 4(%eax)\n"
        ".Lf1877d6_0018781b:\n"
        "orb $0x20, %dh\n" /* line 945 */
        "movl 8(%ebp), %edi\n" /* cmd */
        "movl %edx, 4(%edi)\n"
        "movl 0x195ee78, %esi\n" /* side */
        "movl (%esi), %ecx\n" /* line 976 | side */
        "cmpb $0, 0xb(%ecx)\n"
        "sete %al\n"
        "cmpb 0xc4(%ebx), %al\n"
        "je .Lf1877d6_00187b4e\n"
        ".Lf1877d6_0018783f:\n"
        "leal 0x34(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll PM_IsBinocularsADS\n"
        "testb %al, %al\n"
        "je .Lf1877d6_001879f9\n"
        "movl 8(%ebp), %eax\n" /* cmd */
        "movl 4(%eax), %edx\n"
        "movl %eax, %ebx\n"
        ".Lf1877d6_0018785a:\n"
        "orb $0x10, %dh\n" /* line 979 */
        "movl %edx, 4(%ebx)\n"
        "movl kb, %edi\n" /* line 984 */
        "cmpb $0, 0xb0(%edi)\n"
        "jne .Lf1877d6_00187a16\n"
        ".Lf1877d6_00187873:\n"
        "xorl %esi, %esi\n" /* side */
        ".Lf1877d6_00187875:\n"
        "leal 0x8c(%edi), %edx\n" /* line 990 | key */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%edx), %ecx\n" /* line 229 */
        "movl $0, 0xc(%edx)\n" /* line 230 */
        "cmpb $0, 0x10(%edx)\n" /* line 232 */
        "je .Lf1877d6_001878a3\n"
        "movl 8(%edx), %ebx\n" /* line 235 */
        "testl %ebx, %ebx\n"
        "jne .Lf1877d6_00187bf5\n"
        "movl 0x195f2d8, %ebx\n" /* line 237 */
        "movl (%ebx), %ecx\n"
        ".Lf1877d6_0018789e:\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf1877d6_001878a3:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_001878c2\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jb .Lf1877d6_00187b56\n"
        "movss 0x2ed718, %xmm0\n" /* 127.0f */
        /* } scope */
        /* } scope */
        ".Lf1877d6_001878c2:\n"
        "cvttss2si %xmm0, %eax\n" /* line 990 */
        "addl %eax, %esi\n" /* side */
        "leal 0x78(%edi), %edx\n" /* line 991 | key */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%edx), %ecx\n" /* line 229 */
        "movl $0, 0xc(%edx)\n" /* line 230 */
        "cmpb $0, 0x10(%edx)\n" /* line 232 */
        "je .Lf1877d6_001878f4\n"
        "movl 8(%edx), %ebx\n" /* line 235 */
        "testl %ebx, %ebx\n"
        "jne .Lf1877d6_00187c0e\n"
        "movl 0x195f2d8, %eax\n" /* line 237 */
        "movl (%eax), %ecx\n"
        "movl %eax, %ebx\n"
        ".Lf1877d6_001878ef:\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf1877d6_001878f4:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_00187913\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jb .Lf1877d6_00187b7a\n"
        "movss 0x2ed718, %xmm0\n" /* 127.0f */
        /* } scope */
        /* } scope */
        ".Lf1877d6_00187913:\n"
        "cvttss2si %xmm0, %eax\n" /* line 991 */
        "subl %eax, %esi\n" /* side */
        "movl %esi, -0x1c(%ebp)\n" /* side */
        "leal 0x28(%edi), %edx\n" /* line 993 | key */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%edx), %ecx\n" /* line 229 */
        "movl $0, 0xc(%edx)\n" /* line 230 */
        "cmpb $0, 0x10(%edx)\n" /* line 232 */
        "je .Lf1877d6_00187949\n"
        "movl 8(%edx), %ebx\n" /* line 235 */
        "testl %ebx, %ebx\n"
        "jne .Lf1877d6_00187bcf\n"
        "movl 0x195f2d8, %esi\n" /* line 237 */
        "movl (%esi), %ecx\n"
        "movl %esi, %ebx\n"
        ".Lf1877d6_00187944:\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf1877d6_00187949:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_00187968\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jb .Lf1877d6_00187b9e\n"
        "movss 0x2ed718, %xmm0\n" /* 127.0f */
        /* } scope */
        /* } scope */
        ".Lf1877d6_00187968:\n"
        "cvttss2si %xmm0, %esi\n" /* line 993 | side */
        "leal 0x3c(%edi), %edx\n" /* line 994 | key */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%edx), %ecx\n" /* line 229 */
        "movl $0, 0xc(%edx)\n" /* line 230 */
        "cmpb $0, 0x10(%edx)\n" /* line 232 */
        "je .Lf1877d6_00187999\n"
        "movl 8(%edx), %ebx\n" /* line 235 */
        "testl %ebx, %ebx\n"
        "jne .Lf1877d6_00187be2\n"
        "movl 0x195f2d8, %edi\n" /* line 237 */
        "movl (%edi), %ecx\n"
        "movl %edi, %ebx\n"
        ".Lf1877d6_00187994:\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf1877d6_00187999:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_001879cf\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jae .Lf1877d6_00187bc2\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "testl %edx, %edx\n"
        "js .Lf1877d6_00187cb6\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1877d6_001879c0:\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed718, %xmm0\n" /* 127.0f */
        /* } scope */
        /* } scope */
        ".Lf1877d6_001879cf:\n"
        "cvttss2si %xmm0, %eax\n" /* line 996 */
        "subl %eax, %esi\n" /* side */
        "movl %esi, (%esp)\n" /* side */
        "calll ClampChar\n"
        "movl 8(%ebp), %esi\n" /* cmd, side */
        "movb %al, 0x18(%esi)\n" /* side */
        "movl -0x1c(%ebp), %edi\n" /* line 997 */
        "movl %edi, (%esp)\n"
        "calll ClampChar\n"
        "movb %al, 0x19(%esi)\n" /* side */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 998 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1877d6_001879f9:\n"
        "movl 8(%ebp), %esi\n" /* line 977 | cmd, side */
        "andl $0xffffefff, 4(%esi)\n" /* side */
        "movl kb, %edi\n" /* line 984 */
        "cmpb $0, 0xb0(%edi)\n"
        "je .Lf1877d6_00187873\n"
        ".Lf1877d6_00187a16:\n"
        "leal 0x14(%edi), %edx\n" /* line 986 | key */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%edx), %ecx\n" /* line 229 */
        "movl $0, 0xc(%edx)\n" /* line 230 */
        "cmpb $0, 0x10(%edx)\n" /* line 232 */
        "je .Lf1877d6_00187a47\n"
        "movl 8(%edx), %ebx\n" /* line 235 */
        "testl %ebx, %ebx\n"
        "je .Lf1877d6_00187ca3\n"
        "movl 0x195f2d8, %esi\n" /* line 241 */
        "movl (%esi), %eax\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl %esi, %ebx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf1877d6_00187a47:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_00187a7d\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jae .Lf1877d6_00187c3c\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "testl %edx, %edx\n"
        "js .Lf1877d6_00187d4a\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1877d6_00187a6e:\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed718, %xmm0\n" /* 127.0f */
        /* } scope */
        /* } scope */
        ".Lf1877d6_00187a7d:\n"
        "cvttss2si %xmm0, %ebx\n" /* line 986 */
        /* { scope 2 */
        "movl 0xc(%edi), %ecx\n" /* line 229 */
        "movl $0, 0xc(%edi)\n" /* line 230 */
        "cmpb $0, 0x10(%edi)\n" /* line 232 */
        "je .Lf1877d6_00187aaf\n"
        "movl 8(%edi), %edx\n" /* line 235 */
        "testl %edx, %edx\n"
        "je .Lf1877d6_00187c8f\n"
        "movl 0x195f2d8, %esi\n" /* line 241 */
        "movl (%esi), %eax\n"
        "subl %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movl %esi, %edx\n"
        "movl (%edx), %eax\n" /* line 243 */
        "movl %eax, 8(%edi)\n"
        ".Lf1877d6_00187aaf:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_00187ae5\n"
        "movl 0x195f638, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jae .Lf1877d6_00187c27\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "testl %edx, %edx\n"
        "js .Lf1877d6_00187d60\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1877d6_00187ad6:\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed718, %xmm0\n" /* 127.0f */
        /* } scope */
        ".Lf1877d6_00187ae5:\n"
        "cvttss2si %xmm0, %eax\n" /* line 987 */
        "movl %ebx, %esi\n" /* side */
        "subl %eax, %esi\n" /* side */
        "jmp .Lf1877d6_00187875\n"
        ".Lf1877d6_00187af2:\n"
        "movl 0x195ee78, %esi\n" /* line 903 */
        "movl (%esi), %ecx\n"
        "cmpb $0, 0x85ec(%ecx)\n"
        "jne .Lf1877d6_00187c49\n"
        ".Lf1877d6_00187b07:\n"
        "movl 0x195ecb4, %edx\n"
        ".Lf1877d6_00187b0d:\n"
        "movl (%edx), %eax\n" /* line 951 */
        "movl 8(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1877d6_00187d0e\n"
        "cmpl $2, %eax\n"
        "je .Lf1877d6_00187d22\n"
        "movl 8(%ebp), %eax\n" /* line 963 | cmd */
        "movl 4(%eax), %edx\n"
        "andb $0xfc, %dh\n"
        "movl %edx, 4(%eax)\n"
        ".Lf1877d6_00187b30:\n"
        "andb $0xdf, %dh\n" /* line 968 */
        "movl 8(%ebp), %edi\n" /* cmd */
        "movl %edx, 4(%edi)\n"
        "movl (%esi), %ecx\n" /* line 976 | side */
        "cmpb $0, 0xb(%ecx)\n"
        "sete %al\n"
        "cmpb 0xc4(%ebx), %al\n"
        "jne .Lf1877d6_0018783f\n"
        ".Lf1877d6_00187b4e:\n"
        "movl 8(%ebp), %ebx\n" /* cmd */
        "jmp .Lf1877d6_0018785a\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187b56:\n"
        "cvtsi2ssl %ecx, %xmm1\n" /* line 255 */
        "testl %edx, %edx\n"
        "js .Lf1877d6_00187cf8\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1877d6_00187b66:\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed718, %xmm0\n" /* 127.0f */
        "jmp .Lf1877d6_001878c2\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187b7a:\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "testl %edx, %edx\n"
        "js .Lf1877d6_00187ce2\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1877d6_00187b8a:\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed718, %xmm0\n" /* 127.0f */
        "jmp .Lf1877d6_00187913\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187b9e:\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "testl %edx, %edx\n"
        "js .Lf1877d6_00187ccc\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1877d6_00187bae:\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed718, %xmm0\n" /* 127.0f */
        "jmp .Lf1877d6_00187968\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187bc2:\n"
        "movss 0x2ed718, %xmm0\n" /* 127.0f */
        "jmp .Lf1877d6_001879cf\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187bcf:\n"
        "movl 0x195f2d8, %esi\n" /* line 241 */
        "movl (%esi), %eax\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl %esi, %ebx\n"
        "jmp .Lf1877d6_00187944\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187be2:\n"
        "movl 0x195f2d8, %edi\n"
        "movl (%edi), %eax\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl %edi, %ebx\n"
        "jmp .Lf1877d6_00187994\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187bf5:\n"
        "movl 0x195f2d8, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl 0x195f2d8, %ebx\n"
        "jmp .Lf1877d6_0018789e\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187c0e:\n"
        "movl 0x195f2d8, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl 0x195f2d8, %ebx\n"
        "jmp .Lf1877d6_001878ef\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1877d6_00187c27:\n"
        "movss 0x2ed718, %xmm0\n" /* line 255 | 127.0f */
        /* } scope */
        "cvttss2si %xmm0, %eax\n" /* line 987 */
        "movl %ebx, %esi\n" /* side */
        "subl %eax, %esi\n" /* side */
        "jmp .Lf1877d6_00187875\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187c3c:\n"
        "movss 0x2ed718, %xmm0\n" /* line 255 | 127.0f */
        "jmp .Lf1877d6_00187a7d\n"
        /* } scope */
        /* } scope */
        ".Lf1877d6_00187c49:\n"
        "movl 0x195f2d8, %eax\n" /* line 906 */
        "movl (%eax), %eax\n"
        "subl 0x85f4(%ecx), %eax\n"
        "movl cl_stanceHoldTime, %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jl .Lf1877d6_00187b07\n"
        "cmpl $2, 0x85f0(%ecx)\n" /* line 909 */
        "je .Lf1877d6_00187d36\n"
        "movl 0x195ecb4, %edx\n" /* line 912 */
        "movl (%edx), %eax\n"
        "movl $2, 8(%eax)\n"
        ".Lf1877d6_00187c81:\n"
        "movl (%esi), %eax\n" /* line 914 */
        "movb $0, 0x85ec(%eax)\n"
        "jmp .Lf1877d6_00187b0d\n"
        /* { scope 2 */
        ".Lf1877d6_00187c8f:\n"
        "movl 0x195f2d8, %esi\n" /* line 237 */
        "movl (%esi), %ecx\n"
        "movl %esi, %edx\n"
        "movl (%edx), %eax\n" /* line 243 */
        "movl %eax, 8(%edi)\n"
        "jmp .Lf1877d6_00187aaf\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187ca3:\n"
        "movl 0x195f2d8, %eax\n" /* line 237 */
        "movl (%eax), %ecx\n"
        "movl %eax, %ebx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf1877d6_00187a47\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187cb6:\n"
        "movl %edx, %eax\n" /* line 255 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1877d6_001879c0\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187ccc:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1877d6_00187bae\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187ce2:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1877d6_00187b8a\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187cf8:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1877d6_00187b66\n"
        /* } scope */
        /* } scope */
        ".Lf1877d6_00187d0e:\n"
        "movl 8(%ebp), %eax\n" /* line 954 | cmd */
        "movl 4(%eax), %edx\n"
        "orb $2, %dh\n"
        "andb $0xfe, %dh\n" /* line 955 */
        "movl %edx, 4(%eax)\n"
        "jmp .Lf1877d6_00187b30\n"
        ".Lf1877d6_00187d22:\n"
        "movl 8(%ebp), %edi\n" /* line 958 | cmd */
        "movl 4(%edi), %edx\n"
        "orb $1, %dh\n"
        "andb $0xfd, %dh\n" /* line 959 */
        "movl %edx, 4(%edi)\n"
        "jmp .Lf1877d6_00187b30\n"
        ".Lf1877d6_00187d36:\n"
        "movl 0x195ecb4, %edx\n" /* line 910 */
        "movl (%edx), %eax\n"
        "movl $0, 8(%eax)\n"
        "jmp .Lf1877d6_00187c81\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187d4a:\n"
        "movl %edx, %eax\n" /* line 255 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1877d6_00187a6e\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1877d6_00187d60:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1877d6_00187ad6\n"
    );
}

/* line 1322 */
__attribute__((naked))
usercmd_t CL_CreateCmd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1322 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n"
        "movl 0x195ee78, %eax\n" /* line 199 */
        "movl (%eax), %ebx\n"
        "movss 0x861c(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "calll CL_AdjustAngles\n" /* line 1330 */
        "cld\n" /* line 1332 */
        "movl $7, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* cmd */
        "rep stosl %eax, %es:(%edi)\n"
        "movl %esi, (%esp)\n" /* line 1334 | cmd */
        "calll CL_CmdButtons\n"
        "movl %esi, (%esp)\n" /* line 1337 | cmd */
        "calll CL_KeyMove\n"
        "movl %esi, (%esp)\n" /* line 1340 | cmd */
        "calll CL_MouseMove\n"
        "movss 0x861c(%ebx), %xmm1\n" /* line 1348 */
        "movaps %xmm1, %xmm0\n"
        "subss -0x1c(%ebp), %xmm0\n"
        "ucomiss 0x2ed5f8, %xmm0\n" /* 90.0f */
        "jbe .Lf187d76_00187e6a\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1350 */
        "addss 0x2ed5f8, %xmm0\n" /* 90.0f */
        "movss %xmm0, 0x861c(%ebx)\n"
        ".Lf187d76_00187df1:\n"
        "movl 0x195ee78, %eax\n" /* line 1305 */
        "movl (%eax), %ecx\n"
        "movl 0x85f8(%ecx), %eax\n"
        "movb %al, 8(%esi)\n"
        "movl 0x85fc(%ecx), %eax\n" /* line 1306 */
        "movb %al, 9(%esi)\n"
        "movl 0x26f0(%ecx), %edx\n" /* line 1310 */
        "movl 0x20(%ecx), %eax\n"
        "movl %edx, %ebx\n"
        "subl %eax, %ebx\n"
        "addl $0x1388, %eax\n"
        "cmpl $0x1389, %ebx\n"
        "cmovgel %eax, %edx\n"
        "movl %edx, (%esi)\n"
        "movl %esi, %edx\n"
        "movss 0x2ed644, %xmm1\n" /* 182.04444885253906f */
        "leal 0xc(%esi), %ebx\n"
        ".Lf187d76_00187e34:\n"
        "movss 0x861c(%ecx), %xmm0\n" /* line 1313 */
        "addss 0x8610(%ecx), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %edx, %ebx\n" /* line 1312 */
        "jne .Lf187d76_00187e34\n"
        "movl %esi, %eax\n" /* line 1361 | cmd */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl $4\n"
        ".Lf187d76_00187e6a:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1352 */
        "subss %xmm1, %xmm0\n"
        "ucomiss 0x2ed5f8, %xmm0\n" /* 90.0f */
        "jbe .Lf187d76_00187df1\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1354 */
        "subss 0x2ed5f8, %xmm0\n" /* 90.0f */
        "movss %xmm0, 0x861c(%ebx)\n"
        "jmp .Lf187d76_00187df1\n"
    );
}

/* line 1671 */
__attribute__((naked))
void CL_SendCmdInternal(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1671 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 0x195ee8c, %eax\n" /* line 1376 */
        "movl (%eax), %esi\n"
        "cmpl $6, (%esi)\n"
        "jg .Lf187e9a_00187f81\n"
        ".Lf187e9a_00187eb2:\n"
        "movl 0x407a0(%esi), %eax\n" /* line 1405 */
        "testl %eax, %eax\n"
        "jne .Lf187e9a_00187f5a\n"
        "movl (%esi), %edx\n"
        "cmpl $1, %edx\n"
        "je .Lf187e9a_00187f5a\n"
        "cmpl $2, %edx\n"
        "je .Lf187e9a_00187f5a\n"
        "movzbl 0x40148(%esi), %ecx\n" /* line 1412 */
        "testb %cl, %cl\n"
        "jne .Lf187e9a_00187f47\n"
        ".Lf187e9a_00187edf:\n"
        "leal -7(%edx), %eax\n" /* line 1421 */
        "cmpl $1, %eax\n"
        "jbe .Lf187e9a_00187f00\n"
        "testb %cl, %cl\n"
        "jne .Lf187e9a_00187f00\n"
        "movl 0x195ecac, %eax\n"
        "movl 0x118(%eax), %eax\n"
        "subl 0xc(%esi), %eax\n"
        "cmpl $0x3e7, %eax\n"
        "jle .Lf187e9a_00187f5a\n"
        ".Lf187e9a_00187f00:\n"
        "cmpl $2, 0x407d8(%esi)\n" /* line 1430 */
        "je .Lf187e9a_00187f3c\n"
        "movl 0x407d8(%esi), %ecx\n" /* line 1436 */
        "movl %ecx, -0x14(%ebp)\n"
        "movl 0x407dc(%esi), %edx\n"
        "movl %edx, -0x10(%ebp)\n"
        "movl 0x407e0(%esi), %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll Sys_IsLANAddress\n"
        "testl %eax, %eax\n"
        "je .Lf187e9a_00187fea\n"
        ".Lf187e9a_00187f3c:\n"
        "leal -8(%ebp), %esp\n" /* line 1685 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp CL_WritePacket\n" /* line 1684 */
        ".Lf187e9a_00187f47:\n"
        "movl 0x195ecac, %eax\n" /* line 1412 */
        "movl 0x118(%eax), %eax\n"
        "subl 0xc(%esi), %eax\n"
        "cmpl $0x31, %eax\n"
        "jg .Lf187e9a_00187edf\n"
        ".Lf187e9a_00187f5a:\n"
        "movl 0x195f618, %eax\n" /* line 1678 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf187e9a_00187f6e\n"
        "leal -8(%ebp), %esp\n" /* line 1685 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf187e9a_00187f6e:\n"
        "movl $0x2af7d8, (%esp)\n" /* line 1679 */
        "calll Com_Printf\n"
        "leal -8(%ebp), %esp\n" /* line 1685 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf187e9a_00187f81:\n"
        "movl 0x195ee78, %eax\n" /* line 1382 */
        "movl (%eax), %eax\n"
        "movl 0x4945c(%eax), %ebx\n"
        "addl $1, %ebx\n"
        "movl %ebx, 0x4945c(%eax)\n"
        "andl $0x7f, %ebx\n" /* line 1384 */
        "leal (, %ebx, 4), %edx\n"
        "shll $5, %ebx\n"
        "subl %edx, %ebx\n"
        "leal 0x48650(%ebx, %eax), %ebx\n"
        "leal -0x38(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_CreateCmd\n"
        "subl $4, %esp\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x1c(%ebx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x20(%ebx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x24(%ebx)\n"
        "jmp .Lf187e9a_00187eb2\n"
        ".Lf187e9a_00187fea:\n"
        "movl 0x195ee8c, %eax\n" /* line 1443 */
        "movl (%eax), %eax\n"
        "movl 0x407c8(%eax), %eax\n"
        "subl $1, %eax\n"
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl 0x195ee78, %edx\n"
        "addl (%edx), %eax\n"
        "movl 0x195ecac, %edx\n"
        "movl 0x118(%edx), %ecx\n"
        "subl 0x49468(%eax), %ecx\n"
        "movl 0x195f604, %eax\n"
        "movl (%eax), %ebx\n"
        "movl $0x3e8, %eax\n"
        "cltd\n"
        "idivl 8(%ebx)\n"
        "cmpl %eax, %ecx\n"
        "jge .Lf187e9a_00187f3c\n"
        "jmp .Lf187e9a_00187f5a\n"
    );
}

/* line 1713 */
__attribute__((naked))
void CL_Input(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1713 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 0x195ee8c, %eax\n" /* line 1715 */
        "movl (%eax), %eax\n"
        "cmpl $8, (%eax)\n"
        "je .Lf18803a_0018804e\n"
        "leave\n" /* line 1721 */
        "retl\n"
        ".Lf18803a_0018804e:\n"
        "calll CL_SyncGpu\n" /* line 1718 */
        "leave\n" /* line 1721 */
        "jmp CL_SendCmdInternal\n" /* line 1720 */
    );
}

/* line 1693 */
__attribute__((naked))
void CL_SendCmd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1693 */
        "movl %esp, %ebp\n"
        "movl 0x195ee8c, %eax\n" /* line 1696 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl $4, %eax\n"
        "jle .Lf18805a_00188076\n"
        "cmpl $8, %eax\n" /* line 1699 */
        "je .Lf18805a_00188076\n"
        "popl %ebp\n" /* line 1704 */
        "jmp CL_SendCmdInternal\n" /* line 1703 */
        ".Lf18805a_00188076:\n"
        "popl %ebp\n" /* line 1704 */
        "retl\n"
    );
}

