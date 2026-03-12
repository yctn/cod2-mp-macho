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
extern const dvar_t *cl_maxpackets; /* 0x0 */
extern const dvar_t *cl_freelook; /* 0x0 */
extern const dvar_t *cl_showSend; /* 0x0 */
extern const dvar_t *cl_sensitivity; /* 0x0 */
extern const dvar_t *cl_mouseAccel; /* 0x0 */
extern const dvar_t *cl_showMouseRate; /* 0x0 */
extern const dvar_t *m_pitch; /* 0x0 */
extern const dvar_t *m_yaw; /* 0x0 */
extern const dvar_t *m_forward; /* 0x0 */
extern const dvar_t *m_side; /* 0x0 */
extern const dvar_t *m_filter; /* 0x0 */
extern int atoi(const char *nptr);
extern const char *Cmd_Argv(int arg);
extern void Com_Printf(const char *fmt, ...);
extern void Cmd_AddCommand(const char *cmd, void (*func)(void));
extern void Cmd_RemoveCommand(const char *cmd);
extern const dvar_t *Dvar_RegisterBool_mac(const char *name, int value, int flags);
extern const dvar_t *Dvar_RegisterFloat(const char *name, float value, float min, float max, int flags);
extern const dvar_t *Dvar_RegisterInt(const char *name, int value, int min, int max, int flags);
extern void MSG_Init(msg_t *buf, byte *data, int length);
extern void MSG_WriteString(msg_t *msg, const char *s);
extern void MSG_WriteShort(msg_t *msg, int c);
extern void MSG_WriteByte(msg_t *msg, int c);
extern void MSG_WriteData(msg_t *buf, const void *data, int length);
extern void NET_OutOfBandVoiceData(netsrc_t sock, netadr_t adr, byte *format, int len);
extern void CL_SyncGpu(void);
extern void CL_SendCmdInternal(void);
extern Bool PM_IsBinocularsADS(const playerState_t *ps);
extern const signed char ClampChar(const int i);
extern float sqrtf(float x);
extern qboolean Sys_IsLANAddress(int addr0, int addr1, int addr2);
extern struct clientStatic_t cls; /* 0x0 */
extern int com_frameTime; /* 0x0 */
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

static qboolean CL_ConsumeButtonPress(kbutton_t *button)
{
    qboolean pressed;

    pressed = button->active || button->wasPressed;
    button->wasPressed = 0;
    return pressed;
}

static float CL_KeyState(kbutton_t *key)
{
    unsigned int msec;

    msec = key->msec;
    key->msec = 0;

    if (key->active)
    {
        if (key->downtime)
        {
            msec += com_frameTime - key->downtime;
        }
        else
        {
            msec += com_frameTime;
        }

        key->downtime = com_frameTime;
    }

    if ((int)msec <= 0)
    {
        return 0.0f;
    }

    if (msec >= frame_msec)
    {
        return 1.0f;
    }

    return (float)msec / (float)frame_msec;
}

static int CL_KeyMoveValue(kbutton_t *key)
{
    return (int)(CL_KeyState(key) * 127.0f);
}

static float CL_ClampMouseAxisDelta(float delta, float maxSpeed)
{
    float maxDelta;

    if (maxSpeed == 0.0f)
    {
        return delta;
    }

    maxDelta = (float)frame_msec * maxSpeed * 0.0010000000474974513f;
    if (delta > maxDelta)
    {
        return maxDelta;
    }

    if (delta < -maxDelta)
    {
        return -maxDelta;
    }

    return delta;
}

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
void CL_WriteVoicePacket(void)
{
    clientConnection_t *clc;
    clientActive_t *cl;
    msg_t msg;
    byte data[0x4000];
    int voicePacket;

    clc = *(clientConnection_t **)imp_clc;
    if (clc->demoplaying || (clc->state != CA_ACTIVE && clc->state != CA_LOADING))
    {
        return;
    }

    MSG_Init(&msg, data, sizeof(data));
    MSG_WriteString(&msg, (const char *)str_002a9440);
    MSG_WriteShort(&msg, clc->qport);

    cl = *(clientActive_t **)imp_cl;
    MSG_WriteByte(&msg, cl->voicePacketCount);

    for (voicePacket = 0; voicePacket < cl->voicePacketCount; ++voicePacket)
    {
        MSG_WriteByte(&msg, cl->voicePackets[voicePacket].dataSize);
        MSG_WriteData(&msg, cl->voicePackets[voicePacket].data, cl->voicePackets[voicePacket].dataSize);
    }

    if (cl_showSend->current.enabled)
    {
        Com_Printf((const char *)str_002af630, msg.cursize);
    }

    NET_OutOfBandVoiceData(clc->netchan.sock, clc->serverAddress, msg.data, msg.cursize);
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
void CL_CmdButtons(usercmd_t *cmd)
{
    clientActive_t *cl;

#define KB_AT(offset) ((kbutton_t *)((byte *)kb + (offset)))

    cl = *(clientActive_t **)imp_cl;

    if (CL_ConsumeButtonPress(KB_AT(0x118)))
    {
        cmd->buttons |= 0x1;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x12c)))
    {
        cmd->buttons |= 0x8000;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x140)))
    {
        cmd->buttons |= 0x10000;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x154)))
    {
        cmd->buttons |= 0x20000;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x168)))
    {
        cmd->buttons |= 0x4000;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x17c)))
    {
        cmd->buttons |= 0x4;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x190)))
    {
        cmd->buttons |= 0x8;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x1a4)))
    {
        cmd->buttons |= 0x10;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x1b8)))
    {
        cmd->buttons |= 0x20;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x1cc)))
    {
        cmd->buttons |= 0x40;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x1e0)))
    {
        cmd->buttons |= 0x80;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x1f4)))
    {
        cmd->buttons |= 0x100;
    }
    if (CL_ConsumeButtonPress(KB_AT(0x208)))
    {
        cmd->buttons |= 0x200;
    }
    if (CL_ConsumeButtonPress(KB_AT(0xc8)))
    {
        cmd->buttons |= 0x400;
    }

    if (cl->keyCatchers && !cl_bypassMouseInput->current.enabled)
    {
        cmd->buttons |= 0x40000;
    }

    if ((unsigned)(cl->snap.ps.pm_type - 2) <= 2 && CL_ConsumeButtonPress(KB_AT(0xf0)))
    {
        cmd->buttons |= 0x400;
    }

    if (cl->cgameInShellshock)
    {
        cmd->buttons |= 0x800;
    }

#undef KB_AT
}

/* line 1168 */
void CL_MouseMove(usercmd_t *cmd)
{
    clientActive_t *cl;
    float mx;
    float my;
    float rate;
    float sensitivity;
    float yawDelta;
    float pitchDelta;
    int index;

#define KB_AT(offset) ((kbutton_t *)((byte *)kb + (offset)))

    cl = *(clientActive_t **)imp_cl;
    if (m_filter->current.enabled)
    {
        mx = (float)(cl->mouseDx[0] + cl->mouseDx[1]) * 0.5f;
        my = (float)(cl->mouseDy[0] + cl->mouseDy[1]) * 0.5f;
    }
    else
    {
        index = cl->mouseIndex;
        mx = (float)cl->mouseDx[index];
        my = (float)cl->mouseDy[index];
    }

    index = cl->mouseIndex ^ 1;
    cl->mouseIndex = index;
    cl->mouseDx[index] = 0;
    cl->mouseDy[index] = 0;

    if (frame_msec == 0)
    {
        return;
    }

    rate = sqrtf(mx * mx + my * my) / (float)frame_msec;
    sensitivity = (rate * cl_mouseAccel->current.value + cl_sensitivity->current.value) * cl->cgameSensitivity;

    if (rate != 0.0f && cl_showMouseRate->current.enabled)
    {
        Com_Printf((const char *)str_002af7cc, rate, sensitivity);
    }

    if ((short)cl->snap.ps.pm_flags < 0)
    {
        return;
    }

    if (cl->snap.ps.eFlags & 0x300)
    {
        mx *= 2.5f;
        my *= 2.0f;
    }
    else
    {
        mx *= sensitivity;
        my *= sensitivity;
    }

    if (mx == 0.0f && my == 0.0f)
    {
        return;
    }

    if (KB_AT(0xa0)->active)
    {
        cmd->rightmove = ClampChar((int)cmd->rightmove + (int)(mx * m_side->current.value));
    }
    else
    {
        yawDelta = mx * m_yaw->current.value;
        yawDelta = CL_ClampMouseAxisDelta(yawDelta, cl->cgameMaxYawSpeed);
        cl->viewangles[1] -= yawDelta;
    }

    if ((KB_AT(0x104)->active || cl_freelook->current.enabled) && !KB_AT(0xa0)->active)
    {
        pitchDelta = my * m_pitch->current.value;
        pitchDelta = CL_ClampMouseAxisDelta(pitchDelta, cl->cgameMaxPitchSpeed);
        cl->viewangles[0] += pitchDelta;
    }
    else
    {
        cmd->forwardmove = ClampChar((int)cmd->forwardmove - (int)(my * m_forward->current.value));
    }

#undef KB_AT
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
void CL_AdjustAngles(void)
{
    clientActive_t *cl;
    float speed;

#define KB_AT(offset) ((kbutton_t *)((byte *)kb + (offset)))

    speed = (float)cls.frametime * 0.0010000000474974513f;
    if (KB_AT(0xb4)->active)
    {
        speed *= cl_anglespeedkey->current.value;
    }

    if (!KB_AT(0xa0)->active)
    {
        cl = *(clientActive_t **)imp_cl;
        cl->viewangles[1] -= CL_KeyState(KB_AT(0x14)) * speed * cl_yawspeed->current.value;

        cl = *(clientActive_t **)imp_cl;
        cl->viewangles[1] += CL_KeyState(KB_AT(0x00)) * speed * cl_yawspeed->current.value;
    }

    cl = *(clientActive_t **)imp_cl;
    cl->viewangles[0] -= CL_KeyState(KB_AT(0x50)) * speed * cl_pitchspeed->current.value;

    cl = *(clientActive_t **)imp_cl;
    cl->viewangles[0] += CL_KeyState(KB_AT(0x64)) * speed * cl_pitchspeed->current.value;

#undef KB_AT
}

/* line 925 */
void CL_KeyMove(usercmd_t *cmd)
{
    clientActive_t *cl;
    int *legacyStance;
    int side;
    int forward;

#define KB_AT(offset) ((kbutton_t *)((byte *)kb + (offset)))

    cl = *(clientActive_t **)imp_cl;

    if (KB_AT(0x1f4)->active)
    {
        cmd->buttons |= 0x100;
        cmd->buttons &= ~0x200;
        cmd->buttons |= 0x2000;
    }
    else if (KB_AT(0xdc)->active)
    {
        cmd->buttons |= 0x200;
        cmd->buttons &= ~0x100;
        cmd->buttons |= 0x2000;
    }
    else
    {
        if (cl->stanceHeld && com_frameTime - cl->stanceTime >= cl_stanceHoldTime->current.integer)
        {
            legacyStance = (int *)((byte *)*(void **)imp_legacyHacks + 8);
            if (cl->stancePosition == 2)
            {
                *legacyStance = 0;
            }
            else
            {
                *legacyStance = 2;
            }

            cl->stanceHeld = 0;
        }

        legacyStance = (int *)((byte *)*(void **)imp_legacyHacks + 8);
        if (*legacyStance == 1)
        {
            cmd->buttons |= 0x200;
            cmd->buttons &= ~0x100;
        }
        else if (*legacyStance == 2)
        {
            cmd->buttons |= 0x100;
            cmd->buttons &= ~0x200;
        }
        else
        {
            cmd->buttons &= ~(0x100 | 0x200);
        }

        cmd->buttons &= ~0x2000;
    }

    if (((KB_AT(0xb4)->active != 0) == (cl->usingAds == 0)) || PM_IsBinocularsADS(&cl->snap.ps))
    {
        cmd->buttons |= 0x1000;
    }
    else
    {
        cmd->buttons &= ~0x1000;
    }

    if (KB_AT(0xa0)->active)
    {
        side = CL_KeyMoveValue(KB_AT(0x14)) - CL_KeyMoveValue(KB_AT(0x00));
    }
    else
    {
        side = 0;
    }

    side += CL_KeyMoveValue(KB_AT(0x8c));
    side -= CL_KeyMoveValue(KB_AT(0x78));

    forward = CL_KeyMoveValue(KB_AT(0x28)) - CL_KeyMoveValue(KB_AT(0x3c));

    cmd->forwardmove = ClampChar(forward);
    cmd->rightmove = ClampChar(side);

#undef KB_AT
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
void CL_SendCmdInternal(void)
{
    clientConnection_t *clc;
    clientActive_t *cl;
    outPacket_t *outPacket;
    const int *serverAddrWords;
    int connectElapsed;

    clc = *(clientConnection_t **)imp_clc;
    if (clc->state > CA_LOADING)
    {
        cl = *(clientActive_t **)imp_cl;
        ++cl->cmdNumber;
        cl->cmds[cl->cmdNumber & 127] = CL_CreateCmd();
    }

    if (clc->demoplaying || clc->state == CA_CINEMATIC || clc->state == CA_LOGO)
    {
        goto not_ready;
    }

    connectElapsed = cls.realtime - clc->connectTime;
    if (clc->demowaiting)
    {
        if (connectElapsed <= 49)
        {
            goto not_ready;
        }
    }
    else if ((unsigned int)(clc->state - CA_PRIMED) > 1 && connectElapsed <= 999)
    {
        goto not_ready;
    }

    serverAddrWords = (const int *)&clc->serverAddress;
    if (clc->serverAddress.type == NA_LOOPBACK || Sys_IsLANAddress(serverAddrWords[0], serverAddrWords[1], serverAddrWords[2]))
    {
        CL_WritePacket();
        return;
    }

    cl = *(clientActive_t **)imp_cl;
    outPacket = &cl->outPackets[(clc->netchan.outgoingSequence - 1) & 31];
    if (cls.realtime - outPacket->p_realtime >= 1000 / cl_maxpackets->current.integer)
    {
        CL_WritePacket();
        return;
    }

not_ready:
    if (cl_showSend->current.enabled)
    {
        Com_Printf((const char *)str_002af7d8);
    }
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
