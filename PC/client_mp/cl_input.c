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
extern int atoi(const char *nptr);
extern const char *Cmd_Argv(int arg);
extern void Com_Printf(const char *fmt, ...);
extern void Cmd_AddCommand(const char *cmd, void (*func)(void));
extern void Cmd_RemoveCommand(const char *cmd);
extern const dvar_t *Dvar_RegisterBool_mac(const char *name, int value, int flags);
extern const dvar_t *Dvar_RegisterFloat(const char *name, float value, float min, float max, int flags);
extern const dvar_t *Dvar_RegisterInt(const char *name, int value, int min, int max, int flags);
extern void CL_SyncGpu(void);
extern void CL_SendCmdInternal(void);
extern unsigned int frame_msec; /* 0x0 */

__asm__(".Lclwp_fmt: .asciz \"[CL_WritePacket] serverId=%d\\n\"\n");
static int cl_wp_dbg_count = 0;
void CL_WritePacketDbg(const char *fmt, int serverId) {
    if (cl_wp_dbg_count < 20 || (cl_wp_dbg_count % 500 == 0)) {
        fprintf(stderr, fmt, serverId);
    }
    cl_wp_dbg_count++;
}
extern void UI_MouseEvent(int dx, int dy);
static kbutton_t playersKb[1][28]; /* playersKb */
extern kbutton_t *kb; /* kb */

typedef struct
{
    const char *name;
    void (*handler)(void);
} inputCommandDef_t;

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

static const inputCommandDef_t s_inputCommands[] = {
    {"centerview", IN_CenterView},
    {"+moveup", IN_UpDown},
    {"-moveup", IN_UpUp},
    {"+movedown", IN_DownDown},
    {"-movedown", IN_DownUp},
    {"+left", IN_LeftDown},
    {"-left", IN_LeftUp},
    {"+right", IN_RightDown},
    {"-right", IN_RightUp},
    {"+forward", IN_ForwardDown},
    {"-forward", IN_ForwardUp},
    {"+back", IN_BackDown},
    {"-back", IN_BackUp},
    {"+lookup", IN_LookupDown},
    {"-lookup", IN_LookupUp},
    {"+lookdown", IN_LookdownDown},
    {"-lookdown", IN_LookdownUp},
    {"+strafe", IN_StrafeDown},
    {"-strafe", IN_StrafeUp},
    {"+moveleft", IN_MoveleftDown},
    {"-moveleft", IN_MoveleftUp},
    {"+moveright", IN_MoverightDown},
    {"-moveright", IN_MoverightUp},
    {"+speed", IN_SpeedDown},
    {"-speed", IN_SpeedUp},
    {"+attack", IN_Attack_Down},
    {"-attack", IN_Attack_Up},
    {"+melee", IN_Melee_Down},
    {"-melee", IN_Melee_Up},
    {"+holdbreath", IN_Breath_Down},
    {"-holdbreath", IN_Breath_Up},
    {"+melee_breath", IN_MeleeBreath_Down},
    {"-melee_breath", IN_MeleeBreath_Up},
    {"+frag", IN_Frag_Down},
    {"-frag", IN_Frag_Up},
    {"+smoke", IN_Smoke_Down},
    {"-smoke", IN_Smoke_Up},
    {"+binoculars", IN_Binoculars_Down},
    {"-binoculars", IN_Binoculars_Up},
    {"+breath_binoculars", IN_BreathBinoculars_Down},
    {"-breath_binoculars", IN_BreathBinoculars_Up},
    {"+activate", IN_Activate_Down},
    {"-activate", IN_Activate_Up},
    {"+reload", IN_Reload_Down},
    {"-reload", IN_Reload_Up},
    {"+usereload", IN_UseReload_Down},
    {"-usereload", IN_UseReload_Up},
    {"+leanleft", IN_LeanLeft_Down},
    {"-leanleft", IN_LeanLeft_Up},
    {"+leanright", IN_LeanRight_Down},
    {"-leanright", IN_LeanRight_Up},
    {"+prone", IN_Prone_Down},
    {"-prone", IN_Prone_Up},
    {"+stance", IN_Stance_Down},
    {"-stance", IN_Stance_Up},
    {"+mlook", IN_MLookDown},
    {"-mlook", IN_MLookUp},
    {"toggleads", IN_ToggleADS},
    {"leaveads", IN_LeaveADS},
    {"lowerstance", IN_LowerStance},
    {"raisestance", IN_RaiseStance},
    {"togglecrouch", IN_ToggleCrouch},
    {"toggleprone", IN_ToggleProne},
    {"goprone", IN_GoProne},
    {"gocrouch", IN_GoCrouch},
    {"+gostand", IN_GoStandDown},
    {"-gostand", IN_GoStandUp},
    {"+talk", IN_TalkDown},
    {"-talk", IN_TalkUp},
};
void CL_Input(void);
void CL_SendCmd(void);

/* line 102 */
void IN_MLookDown(void)
{
    *(byte *)((byte *)kb + 0x114) = 1;
}

/* line 654 */
void IN_CenterView(void)
{
    byte *cl = (byte *)*(void **)imp_cl;
    *(float *)(cl + 0x861c) = (float)*(int *)(cl + 0x88) * -0.0054931640625f;
}

/* line 116 */
void IN_KeyDown(kbutton_t *b)
{
    const char *keyText;
    int key;

    keyText = Cmd_Argv(1);
    key = keyText[0] ? atoi(keyText) : -1;

    if (key == b->down[0] || key == b->down[1])
    {
        return;
    }

    if (!b->down[0])
    {
        b->down[0] = key;
    }
    else if (!b->down[1])
    {
        b->down[1] = key;
    }
    else
    {
        Com_Printf(str_002af610);
        return;
    }

    if (b->active)
    {
        return;
    }

    b->downtime = atoi(Cmd_Argv(2));
    b->active = 1;
    b->wasPressed = 1;
}

/* line 164 */
void IN_KeyUp(kbutton_t *b)
{
    const char *keyText;
    int key;
    int uptime;

    keyText = Cmd_Argv(1);
    if (!keyText[0])
    {
        b->down[0] = 0;
        b->down[1] = 0;
        b->active = 0;
        return;
    }

    key = atoi(keyText);
    if (key == b->down[0])
    {
        b->down[0] = 0;
    }
    else if (key == b->down[1])
    {
        b->down[1] = 0;
    }
    else
    {
        return;
    }

    if (b->down[0] || b->down[1])
    {
        return;
    }

    b->active = 0;
    uptime = atoi(Cmd_Argv(2));
    if (uptime)
    {
        b->msec += uptime - b->downtime;
    }
    else
    {
        b->msec += frame_msec / 2;
    }

    b->active = 0;
}

/* line 278 */
void IN_UpDown(void)
{
    int *stance;

    IN_KeyDown((kbutton_t *)((byte *)kb + 0xf0));
    if (*(byte *)((byte *)kb + 0x204) || *(byte *)((byte *)kb + 0xec))
    {
        return;
    }

    stance = (int *)((byte *)(*(void **)imp_legacyHacks) + 8);
    if (*stance > 1)
    {
        *stance = 1;
        return;
    }

    if (*stance == 1)
    {
        *stance = 0;
        return;
    }

    IN_KeyDown((kbutton_t *)((byte *)kb + 0xc8));
}

/* line 300 */
void IN_UpUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0xc8));
}

/* line 322 */
void IN_LeftDown(void)
{
    IN_KeyDown(kb);
}

/* line 328 */
void IN_LeftUp(void)
{
    IN_KeyUp(kb);
}

/* line 334 */
void IN_RightDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x14));
}

/* line 340 */
void IN_RightUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x14));
}

/* line 346 */
void IN_ForwardDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x28));
}

/* line 352 */
void IN_ForwardUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x28));
}

/* line 358 */
void IN_BackDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x3c));
}

/* line 364 */
void IN_BackUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x3c));
}

/* line 370 */
void IN_LookupDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x50));
}

/* line 376 */
void IN_LookupUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x50));
}

/* line 382 */
void IN_LookdownDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x64));
}

/* line 388 */
void IN_LookdownUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x64));
}

/* line 394 */
void IN_MoveleftDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x78));
}

/* line 400 */
void IN_MoveleftUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x78));
}

/* line 406 */
void IN_MoverightDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x8c));
}

/* line 412 */
void IN_MoverightUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x8c));
}

/* line 418 */
void IN_SpeedDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0xb4));
}

/* line 424 */
void IN_SpeedUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0xb4));
}

/* line 430 */
void IN_StrafeDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0xa0));
}

/* line 436 */
void IN_StrafeUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0xa0));
}

/* line 442 */
void IN_Attack_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x118));
}

/* line 448 */
void IN_Attack_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x118));
}

/* line 454 */
void IN_Breath_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x12c));
}

/* line 460 */
void IN_Breath_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x12c));
}

/* line 466 */
void IN_MeleeBreath_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x17c));
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x12c));
}

/* line 473 */
void IN_MeleeBreath_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x12c));
}

/* line 480 */
void IN_Frag_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x140));
}

/* line 486 */
void IN_Frag_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x140));
}

/* line 492 */
void IN_Smoke_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x154));
}

/* line 498 */
void IN_Smoke_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x154));
}

/* line 504 */
void IN_Binoculars_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x168));
}

/* line 510 */
void IN_Binoculars_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x168));
}

/* line 516 */
void IN_BreathBinoculars_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x12c));
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x168));
}

/* line 523 */
void IN_BreathBinoculars_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x168));
}

/* line 530 */
void IN_Melee_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x17c));
}

/* line 536 */
void IN_Melee_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x17c));
}

/* line 542 */
void IN_Activate_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x190));
}

/* line 548 */
void IN_Activate_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x190));
}

/* line 554 */
void IN_Reload_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x1a4));
}

/* line 560 */
void IN_Reload_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x1a4));
}

/* line 566 */
void IN_UseReload_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x1b8));
}

/* line 572 */
void IN_UseReload_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x1b8));
}

/* line 578 */
void IN_LeanLeft_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x1cc));
}

/* line 584 */
void IN_LeanLeft_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x1cc));
}

/* line 590 */
void IN_LeanRight_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x1e0));
}

/* line 596 */
void IN_LeanRight_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x1e0));
}

/* line 616 */
void IN_Stance_Down(void)
{
    byte *cl;

    if (*(byte *)((byte *)kb + 0x204) || *(byte *)((byte *)kb + 0xec))
    {
        return;
    }

    cl = (byte *)*(void **)imp_cl;
    *(byte *)(cl + 0x85ec) = 1;
    *(int *)(cl + 0x85f0) = *(int *)((byte *)(*(void **)imp_legacyHacks) + 8);
    *(int *)(cl + 0x85f4) = *(int *)imp_com_frameTime;
    if (*(int *)(cl + 0x85f0) != 1)
    {
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 8) = 1;
    }
}

/* line 630 */
void IN_Stance_Up(void)
{
    byte *ptr;
    if (*(byte *)((byte *)kb + 0x204) || *(byte *)((byte *)kb + 0xec))
        return;
    ptr = (byte *)*(void **)imp_cl;
    if (*(byte *)(ptr + 0x85ec) && *(int *)(ptr + 0x85f0) == 1)
    {
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 8) = 0;
        ptr = (byte *)*(void **)imp_cl;
    }
    *(byte *)(ptr + 0x85ec) = 0;
}

/* line 660 */
void IN_ToggleADS(void)
{
    byte *p = (byte *)*(void **)imp_cl + 0xb;
    *p = (*p == 0) ? 1 : 0;
}

/* line 666 */
void IN_LeaveADS(void)
{
    *(byte *)((char *)*(void **)imp_cl + 0xb) = 0;
}

/* line 672 */
void IN_LowerStance(void)
{
    int *statePtr;
    int val;
    if (*(byte *)((byte *)kb + 0x204) || *(byte *)((byte *)kb + 0xec))
        return;
    statePtr = (int *)((byte *)(*(void **)imp_legacyHacks) + 8);
    val = *statePtr;
    if (val <= 0)
        *statePtr = 1;
    else if (val == 1)
        *statePtr = 2;
}

/* line 690 */
void IN_RaiseStance(void)
{
    if (*(byte *)((byte *)kb + 0x204) != 0 || *(byte *)((byte *)kb + 0xec) != 0)
        return;
    int *stance = (int *)((byte *)*(void **)imp_legacyHacks + 8);
    if (*stance > 1)
        *stance = 1;
    else if (*stance == 1)
        *stance = 0;
}

/* line 708 */
void IN_ToggleCrouch(void)
{
    if (*(byte *)((byte *)kb + 0x204) != 0 || *(byte *)((byte *)kb + 0xec) != 0)
        return;
    int *stance = (int *)((byte *)*(void **)imp_legacyHacks + 8);
    *stance = (*stance != 1) ? 1 : 0;
}

/* line 726 */
void IN_ToggleProne(void)
{
    if (*(byte *)((byte *)kb + 0x204) != 0 || *(byte *)((byte *)kb + 0xec) != 0)
        return;
    int *stance = (int *)((byte *)*(void **)imp_legacyHacks + 8);
    *stance = (*stance != 2) ? 2 : 0;
}

/* line 744 */
void IN_GoProne(void)
{
    if (*(byte *)((byte *)kb + 0x204) != 0 || *(byte *)((byte *)kb + 0xec) != 0)
        return;
    *(int *)((byte *)*(void **)imp_legacyHacks + 8) = 2;
}

/* line 760 */
void IN_GoCrouch(void)
{
    if (*(byte *)((byte *)kb + 0x204) != 0 || *(byte *)((byte *)kb + 0xec) != 0)
        return;
    *(int *)((byte *)*(void **)imp_legacyHacks + 8) = 1;
}

/* line 776 */
void IN_GoStandDown(void)
{
    int *stance;

    IN_KeyDown((kbutton_t *)((byte *)kb + 0xf0));
    stance = (int *)((byte *)(*(void **)imp_legacyHacks) + 8);
    if (!*stance)
    {
        IN_KeyDown((kbutton_t *)((byte *)kb + 0xc8));
        return;
    }

    if (*(byte *)((byte *)kb + 0x204) || *(byte *)((byte *)kb + 0xec))
    {
        return;
    }

    *stance = 0;
}

/* line 801 */
void IN_GoStandUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0xc8));
}

/* line 837 */
void IN_TalkDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x21c));
}

/* line 842 */
void IN_TalkUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x21c));
}

/* line 847 */
Bool IsTalking(void)
{
    return *(byte *)((byte *)kb + 0x22c);
}

/* line 1006 */
void CL_MouseEvent(const int dx, const int dy)
{
    byte *ptr = (byte *)*(void **)imp_cl;
    int index;
    if (!(*(byte *)(ptr + 4) & 8) || *(byte *)((byte *)cl_bypassMouseInput + 8))
    {
        index = *(int *)(ptr + 0x85e8);
        *(int *)(ptr + 0x85d8 + index * 4) += dx;
        *(int *)(ptr + 0x85e0 + index * 4) += dy;
    }
    else
    {
        UI_MouseEvent(dx, dy);
    }
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
        "movl imp_clc, %eax\n" /* line 1468 */
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
        "movl $str_002a9440, 4(%esp)\n" /* line 1475 */
        "leal -0x3c(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteString\n"
        "movl 4(%ebx), %eax\n" /* line 1478 */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteShort\n"
        "movl imp_cl, %esi\n" /* line 1481 */
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
        "movl imp_cl_showSend, %eax\n" /* line 1499 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf185e60_00185fca\n"
        ".Lf185e60_00185f11:\n"
        "movl imp_clc, %eax\n" /* line 1506 */
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
        "movl imp_cl_showSend, %eax\n" /* line 1499 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf185e60_00185f11\n"
        ".Lf185e60_00185fca:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1501 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002af630, (%esp)\n" /* "voice: %i
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
        "movl imp_clc, %edi\n" /* line 1547 | compressedSize */
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
        "movl imp_cl, %eax\n"
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
        /* DEBUG: print serverId being written */
        "pushl %esi\n"
        "pushl %ebx\n"
        "pushl %eax\n"
        "pushl %eax\n"
        "pushl $.Lclwp_fmt\n"
        "calll CL_WritePacketDbg\n"
        "addl $8, %esp\n"
        "popl %eax\n"
        "popl %ebx\n"
        "popl %esi\n"
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
        "movl imp_cl, %eax\n" /* line 1582 */
        "movl (%eax), %ecx\n"
        "movl imp_cl_packetdup, %eax\n"
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
        "movl imp_cl_showSend, %eax\n" /* line 1590 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf185fe2_0018637b\n"
        ".Lf185fe2_001860f3:\n"
        "movl imp_cl_nodelta, %eax\n" /* line 1596 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf185fe2_00186112\n"
        "movl imp_cl, %eax\n"
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
        "movl imp_clc, %eax\n" /* line 1609 */
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
        "movl imp_clc, %edx\n" /* line 1641 */
        "movl (%edx), %esi\n" /* i */
        "movl 0x407c8(%esi), %eax\n" /* i */
        "andl $0x1f, %eax\n"
        "movl imp_cl, %edx\n" /* line 1642 */
        "movl (%edx), %ebx\n" /* cmd */
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* cmd */
        "movl imp_cls, %ecx\n"
        "movl 0x118(%ecx), %edx\n"
        "movl %edx, 0x49468(%eax)\n"
        "movl -0x805c(%ebp), %edx\n" /* line 1643 */
        "movl (%edx), %edx\n"
        "movl %edx, 0x49464(%eax)\n"
        "movl 0x4945c(%ebx), %edx\n" /* line 1644 | cmd */
        "movl %edx, 0x49460(%eax)\n"
        "movl 0x118(%ecx), %eax\n" /* line 1645 */
        "movl %eax, 0xc(%esi)\n" /* i */
        "movl imp_cl_showSend, %eax\n" /* line 1647 */
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
        "movl imp_clc, %ebx\n" /* cmd */
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
        "movl imp_clc, %eax\n" /* line 1596 */
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
        "movl $str_00217fac, (%esp)\n" /* "%i " */
        "calll Com_Printf\n"
        "jmp .Lf185fe2_00186255\n"
        ".Lf185fe2_00186365:\n"
        "movl $str_002af63c, (%esp)\n" /* line 1586 */
        "calll Com_Printf\n"
        "movl $0x20, %edi\n" /* compressedSize */
        "jmp .Lf185fe2_001860e2\n"
        ".Lf185fe2_0018637b:\n"
        "movl %edi, 4(%esp)\n" /* line 1592 | compressedSize */
        "movl $str_002af654, (%esp)\n" /* "(%i)" */
        "calll Com_Printf\n"
        "jmp .Lf185fe2_001860f3\n"
        ".Lf185fe2_00186390:\n"
        "leal -0x4c(%ebp), %ecx\n" /* line 1623 | nullcmd */
        "xorl %esi, %esi\n" /* i */
        "movl imp_cl, %eax\n"
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
void CL_InitInput(void)
{
    unsigned int i;

    for (i = 0; i < sizeof(s_inputCommands) / sizeof(s_inputCommands[0]); ++i)
    {
        Cmd_AddCommand(s_inputCommands[i].name, s_inputCommands[i].handler);
    }

    cl_analog_attack_threshold = Dvar_RegisterFloat("cl_analog_attack_threshold", 0.8f, 0.0001f, 1.0f, 0);
    cl_stanceHoldTime = Dvar_RegisterInt("cl_stanceHoldTime", 300, 0, 1000, 0);
    *(const dvar_t **)imp_cl_nodelta = Dvar_RegisterBool_mac("cl_nodelta", 0, 0);
}

/* line 1846 */
void CL_ShutdownInput(void)
{
    unsigned int i;

    for (i = 0; i < sizeof(s_inputCommands) / sizeof(s_inputCommands[0]); ++i)
    {
        Cmd_RemoveCommand(s_inputCommands[i].name);
    }
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
        "movl imp_cl, %ebx\n" /* line 1278 */
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
        "movl imp_m_filter, %eax\n" /* line 1177 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf186ef6_00186f76\n"
        "movl imp_cl, %ecx\n" /* line 1179 */
        "movl (%ecx), %edx\n"
        "movl 0x85d8(%edx), %eax\n"
        "addl 0x85dc(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm4\n"
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
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
        "movl imp_frame_msec, %eax\n" /* line 1191 */
        "movl (%eax), %edx\n"
        "cmpl $0, %edx\n"
        "jne .Lf186ef6_00186f98\n"
        /* } scope */
        ".Lf186ef6_00186f74:\n"
        "leave\n" /* line 1251 */
        "retl\n"
        /* { scope 1 */
        ".Lf186ef6_00186f76:\n"
        "movl imp_cl, %ecx\n" /* line 1184 */
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
        "movl imp_cl_sensitivity, %eax\n" /* line 1195 */
        "movl (%eax), %edx\n"
        "movl imp_cl_mouseAccel, %eax\n"
        "movl (%eax), %eax\n"
        "movaps %xmm1, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "addss 8(%edx), %xmm2\n"
        "movl (%ecx), %eax\n" /* line 1198 */
        "mulss 0x8604(%eax), %xmm2\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 1199 | 0.0f */
        "jp .Lf186ef6_00186fef\n"
        "je .Lf186ef6_00187004\n"
        ".Lf186ef6_00186fef:\n"
        "movl imp_cl_showMouseRate, %eax\n"
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
        "mulss lit4_002ed6c0, %xmm0\n" /* 2.5f */
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
        "movl imp_m_yaw, %eax\n" /* line 1227 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "movss 0x860c(%edx), %xmm1\n" /* line 1228 */
        "ucomiss %xmm4, %xmm1\n"
        "jp .Lf186ef6_00187076\n"
        "je .Lf186ef6_001870d2\n"
        ".Lf186ef6_00187076:\n"
        "movl imp_frame_msec, %eax\n" /* line 1230 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "js .Lf186ef6_0018727a\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        ".Lf186ef6_00187089:\n"
        "mulss %xmm1, %xmm0\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm5\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm5\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm5, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "xorps g_color_table+544, %xmm0\n" /* line 1231 */
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
        "movl imp_cl_freelook, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf186ef6_00187205\n"
        ".Lf186ef6_00187106:\n"
        "cmpb $0, 0xb0(%edx)\n"
        "jne .Lf186ef6_00187205\n"
        /* { scope 2 */
        "movl imp_m_pitch, %eax\n" /* line 1238 */
        "movl (%eax), %eax\n"
        "movaps %xmm3, %xmm2\n" /* delta */
        "mulss 8(%eax), %xmm2\n" /* delta */
        "movl imp_cl, %eax\n" /* line 1240 */
        "movl (%eax), %ecx\n"
        "movss 0x8608(%ecx), %xmm1\n"
        "pxor %xmm4, %xmm4\n"
        "ucomiss %xmm4, %xmm1\n"
        "jp .Lf186ef6_0018713c\n"
        "je .Lf186ef6_00187198\n"
        ".Lf186ef6_0018713c:\n"
        "movl imp_frame_msec, %eax\n" /* line 1242 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf186ef6_00187290\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf186ef6_0018714f:\n"
        "mulss %xmm1, %xmm0\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm3\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm3\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm3, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "xorps g_color_table+544, %xmm0\n" /* line 1243 */
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
        "movl $str_002af7cc, (%esp)\n" /* "%f : %f
" */
        "movss %xmm2, -0x18(%ebp)\n"
        "movss %xmm3, -0x28(%ebp)\n"
        "movss %xmm4, -0x38(%ebp)\n"
        "calll Com_Printf\n"
        "movl imp_cl, %ecx\n"
        "movss -0x38(%ebp), %xmm4\n"
        "movss -0x28(%ebp), %xmm3\n"
        "movss -0x18(%ebp), %xmm2\n"
        "movl (%ecx), %edx\n"
        "jmp .Lf186ef6_00187006\n"
        ".Lf186ef6_00187205:\n"
        "movl 8(%ebp), %eax\n" /* line 1249 | cmd */
        "movsbl 0x18(%eax), %edx\n"
        "movl imp_m_forward, %eax\n"
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
        "movl imp_m_side, %eax\n"
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
void IN_DownDown(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0xdc));
    if (*(byte *)((byte *)kb + 0x204) || *(byte *)((byte *)kb + 0xec))
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 0xc) = 1;
    else
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 0xc) = 0;
}

/* line 315 */
void IN_DownUp(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0xdc));
    if (*(byte *)((byte *)kb + 0x204) || *(byte *)((byte *)kb + 0xec))
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 0xc) = 1;
    else
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 0xc) = 0;
}

/* line 602 */
void IN_Prone_Down(void)
{
    IN_KeyDown((kbutton_t *)((byte *)kb + 0x1f4));
    if (*(byte *)((byte *)kb + 0x204) || *(byte *)((byte *)kb + 0xec))
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 0xc) = 1;
    else
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 0xc) = 0;
}

/* line 609 */
void IN_Prone_Up(void)
{
    IN_KeyUp((kbutton_t *)((byte *)kb + 0x1f4));
    if (*(byte *)((byte *)kb + 0x204) || *(byte *)((byte *)kb + 0xec))
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 0xc) = 1;
    else
        *(int *)((byte *)(*(void **)imp_legacyHacks) + 0xc) = 0;
}

/* line 108 */
void IN_MLookUp(void)
{
    *(byte *)((byte *)kb + 0x114) = 0;
    if (*(byte *)((byte *)*(void **)imp_cl_freelook + 8) == 0) {
        byte *cl = (byte *)*(void **)imp_cl;
        *(float *)(cl + 0x861c) = (float)*(int *)(cl + 0x88) * -0.0054931640625f;
    }
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
        "movl imp_cls, %eax\n" /* line 884 */
        "cvtsi2ssl 0x114(%eax), %xmm2\n"
        "mulss lit4_002ed658, %xmm2\n" /* 0.0010000000474974513f */
        "movl cl_anglespeedkey, %eax\n"
        "mulss 8(%eax), %xmm2\n"
        ".Lf187424_0018745f:\n"
        "cmpb $0, 0xb0(%esi)\n" /* line 888 */
        "jne .Lf187424_0018754c\n"
        "movl imp_cl, %eax\n" /* line 890 */
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
        "movl imp_frame_msec, %eax\n" /* line 255 */
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
        "movl imp_cl, %edi\n" /* line 891 */
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
        "movl imp_frame_msec, %eax\n" /* line 255 */
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
        "movl imp_cl, %ebx\n" /* line 894 */
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
        "movl imp_com_frameTime, %eax\n" /* line 241 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl imp_com_frameTime, %ebx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf187424_001875a0:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf187424_001875ce\n"
        "movl imp_frame_msec, %eax\n" /* line 255 */
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
        "movl imp_cl, %eax\n" /* line 895 */
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
        "movl imp_com_frameTime, %esi\n" /* line 241 */
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
        "movl imp_frame_msec, %eax\n" /* line 255 */
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
        "movl imp_cls, %eax\n" /* line 886 */
        "cvtsi2ssl 0x114(%eax), %xmm2\n"
        "mulss lit4_002ed658, %xmm2\n" /* 0.0010000000474974513f */
        "jmp .Lf187424_0018745f\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_0018768b:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 255 | 1.0f */
        "jmp .Lf187424_001875ce\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf187424_00187698:\n"
        "movl 8(%esi), %edx\n" /* line 235 */
        "testl %edx, %edx\n"
        "je .Lf187424_0018776a\n"
        "movl imp_com_frameTime, %edi\n" /* line 241 */
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
        "movl imp_com_frameTime, %eax\n" /* line 241 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl imp_com_frameTime, %ebx\n"
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
        "movl imp_com_frameTime, %eax\n" /* line 237 */
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
        "movl imp_com_frameTime, %ebx\n" /* line 237 */
        "movl (%ebx), %ecx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf187424_0018762b\n"
        ".Lf187424_00187721:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 255 | 1.0f */
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
        "movss lit4_002ed5d0, %xmm0\n" /* line 255 | 1.0f */
        "jmp .Lf187424_001874cd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf187424_0018774e:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf187424_0018753c\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf187424_0018775b:\n"
        "movl imp_com_frameTime, %ebx\n" /* line 237 */
        "movl (%ebx), %ecx\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf187424_001876eb\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf187424_0018776a:\n"
        "movl imp_com_frameTime, %eax\n" /* line 237 */
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
        "movl imp_cl, %esi\n" /* side */
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
        "movl imp_com_frameTime, %ebx\n" /* line 237 */
        "movl (%ebx), %ecx\n"
        ".Lf1877d6_0018789e:\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf1877d6_001878a3:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_001878c2\n"
        "movl imp_frame_msec, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jb .Lf1877d6_00187b56\n"
        "movss lit4_002ed718, %xmm0\n" /* 127.0f */
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
        "movl imp_com_frameTime, %eax\n" /* line 237 */
        "movl (%eax), %ecx\n"
        "movl %eax, %ebx\n"
        ".Lf1877d6_001878ef:\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf1877d6_001878f4:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_00187913\n"
        "movl imp_frame_msec, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jb .Lf1877d6_00187b7a\n"
        "movss lit4_002ed718, %xmm0\n" /* 127.0f */
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
        "movl imp_com_frameTime, %esi\n" /* line 237 */
        "movl (%esi), %ecx\n"
        "movl %esi, %ebx\n"
        ".Lf1877d6_00187944:\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf1877d6_00187949:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_00187968\n"
        "movl imp_frame_msec, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jb .Lf1877d6_00187b9e\n"
        "movss lit4_002ed718, %xmm0\n" /* 127.0f */
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
        "movl imp_com_frameTime, %edi\n" /* line 237 */
        "movl (%edi), %ecx\n"
        "movl %edi, %ebx\n"
        ".Lf1877d6_00187994:\n"
        "movl (%ebx), %eax\n" /* line 243 */
        "movl %eax, 8(%edx)\n"
        ".Lf1877d6_00187999:\n"
        "pxor %xmm0, %xmm0\n" /* line 253 */
        "testl %ecx, %ecx\n"
        "jle .Lf1877d6_001879cf\n"
        "movl imp_frame_msec, %eax\n" /* line 255 */
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
        "mulss lit4_002ed718, %xmm0\n" /* 127.0f */
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
        "movl imp_com_frameTime, %esi\n" /* line 241 */
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
        "movl imp_frame_msec, %eax\n" /* line 255 */
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
        "mulss lit4_002ed718, %xmm0\n" /* 127.0f */
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
        "movl imp_com_frameTime, %esi\n" /* line 241 */
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
        "movl imp_frame_msec, %eax\n" /* line 255 */
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
        "mulss lit4_002ed718, %xmm0\n" /* 127.0f */
        /* } scope */
        ".Lf1877d6_00187ae5:\n"
        "cvttss2si %xmm0, %eax\n" /* line 987 */
        "movl %ebx, %esi\n" /* side */
        "subl %eax, %esi\n" /* side */
        "jmp .Lf1877d6_00187875\n"
        ".Lf1877d6_00187af2:\n"
        "movl imp_cl, %esi\n" /* line 903 */
        "movl (%esi), %ecx\n"
        "cmpb $0, 0x85ec(%ecx)\n"
        "jne .Lf1877d6_00187c49\n"
        ".Lf1877d6_00187b07:\n"
        "movl imp_legacyHacks, %edx\n"
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
        "mulss lit4_002ed718, %xmm0\n" /* 127.0f */
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
        "mulss lit4_002ed718, %xmm0\n" /* 127.0f */
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
        "mulss lit4_002ed718, %xmm0\n" /* 127.0f */
        "jmp .Lf1877d6_00187968\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187bc2:\n"
        "movss lit4_002ed718, %xmm0\n" /* 127.0f */
        "jmp .Lf1877d6_001879cf\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187bcf:\n"
        "movl imp_com_frameTime, %esi\n" /* line 241 */
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
        "movl imp_com_frameTime, %edi\n"
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
        "movl imp_com_frameTime, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl imp_com_frameTime, %ebx\n"
        "jmp .Lf1877d6_0018789e\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187c0e:\n"
        "movl imp_com_frameTime, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "subl %ebx, %eax\n"
        "addl %eax, %ecx\n"
        "movl imp_com_frameTime, %ebx\n"
        "jmp .Lf1877d6_001878ef\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1877d6_00187c27:\n"
        "movss lit4_002ed718, %xmm0\n" /* line 255 | 127.0f */
        /* } scope */
        "cvttss2si %xmm0, %eax\n" /* line 987 */
        "movl %ebx, %esi\n" /* side */
        "subl %eax, %esi\n" /* side */
        "jmp .Lf1877d6_00187875\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187c3c:\n"
        "movss lit4_002ed718, %xmm0\n" /* line 255 | 127.0f */
        "jmp .Lf1877d6_00187a7d\n"
        /* } scope */
        /* } scope */
        ".Lf1877d6_00187c49:\n"
        "movl imp_com_frameTime, %eax\n" /* line 906 */
        "movl (%eax), %eax\n"
        "subl 0x85f4(%ecx), %eax\n"
        "movl cl_stanceHoldTime, %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jl .Lf1877d6_00187b07\n"
        "cmpl $2, 0x85f0(%ecx)\n" /* line 909 */
        "je .Lf1877d6_00187d36\n"
        "movl imp_legacyHacks, %edx\n" /* line 912 */
        "movl (%edx), %eax\n"
        "movl $2, 8(%eax)\n"
        ".Lf1877d6_00187c81:\n"
        "movl (%esi), %eax\n" /* line 914 */
        "movb $0, 0x85ec(%eax)\n"
        "jmp .Lf1877d6_00187b0d\n"
        /* { scope 2 */
        ".Lf1877d6_00187c8f:\n"
        "movl imp_com_frameTime, %esi\n" /* line 237 */
        "movl (%esi), %ecx\n"
        "movl %esi, %edx\n"
        "movl (%edx), %eax\n" /* line 243 */
        "movl %eax, 8(%edi)\n"
        "jmp .Lf1877d6_00187aaf\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1877d6_00187ca3:\n"
        "movl imp_com_frameTime, %eax\n" /* line 237 */
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
        "movl imp_legacyHacks, %edx\n" /* line 910 */
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
usercmd_t CL_CreateCmd(void)
{
    clientActive_t *cl;
    usercmd_t cmd;
    float oldPitch;
    float pitchDelta;
    int currentCmdTime;
    int i;

    cl = *(clientActive_t **)imp_cl;
    oldPitch = cl->viewangles[0];

    CL_AdjustAngles();

    cmd.serverTime = 0;
    cmd.buttons = 0;
    cmd.weapon = 0;
    cmd.offHandIndex = 0;
    cmd.angles[0] = 0;
    cmd.angles[1] = 0;
    cmd.angles[2] = 0;
    cmd.forwardmove = 0;
    cmd.rightmove = 0;

    CL_CmdButtons(&cmd);
    CL_KeyMove(&cmd);
    CL_MouseMove(&cmd);

    pitchDelta = cl->viewangles[0] - oldPitch;
    if (pitchDelta > 90.0f)
    {
        cl->viewangles[0] = oldPitch + 90.0f;
    }
    else if (-pitchDelta > 90.0f)
    {
        cl->viewangles[0] = oldPitch - 90.0f;
    }

    cmd.weapon = (byte)cl->cgameUserCmdValue;
    cmd.offHandIndex = (byte)cl->cgameUserHoldableValue;

    currentCmdTime = *(int *)((byte *)cl + 0x26f0);
    if (currentCmdTime > cl->serverTime + 5000)
    {
        currentCmdTime = cl->serverTime + 5000;
    }
    cmd.serverTime = currentCmdTime;

    for (i = 0; i < 3; ++i)
    {
        cmd.angles[i] = ((int)((cl->viewangles[i] + cl->cgameKickAngles[i]) * 182.04444885253906f)) & 0xffff;
    }

    return cmd;
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
        "movl imp_clc, %eax\n" /* line 1376 */
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
        "movl imp_cls, %eax\n"
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
        "movl imp_cls, %eax\n" /* line 1412 */
        "movl 0x118(%eax), %eax\n"
        "subl 0xc(%esi), %eax\n"
        "cmpl $0x31, %eax\n"
        "jg .Lf187e9a_00187edf\n"
        ".Lf187e9a_00187f5a:\n"
        "movl imp_cl_showSend, %eax\n" /* line 1678 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf187e9a_00187f6e\n"
        "leal -8(%ebp), %esp\n" /* line 1685 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf187e9a_00187f6e:\n"
        "movl $str_002af7d8, (%esp)\n" /* line 1679 */
        "calll Com_Printf\n"
        "leal -8(%ebp), %esp\n" /* line 1685 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf187e9a_00187f81:\n"
        "movl imp_cl, %eax\n" /* line 1382 */
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
        "movl imp_clc, %eax\n" /* line 1443 */
        "movl (%eax), %eax\n"
        "movl 0x407c8(%eax), %eax\n"
        "subl $1, %eax\n"
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl imp_cl, %edx\n"
        "addl (%edx), %eax\n"
        "movl imp_cls, %edx\n"
        "movl 0x118(%edx), %ecx\n"
        "subl 0x49468(%eax), %ecx\n"
        "movl imp_cl_maxpackets, %eax\n"
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
void CL_Input(void)
{
    if (*(int *)*(void **)imp_clc != 8)
        return;
    CL_SyncGpu();
    CL_SendCmdInternal();
}

/* line 1693 */
void CL_SendCmd(void)
{
    int state = *(int *)*(void **)imp_clc;
    if (state <= 4 || state == 8)
        return;
    CL_SendCmdInternal();
}
