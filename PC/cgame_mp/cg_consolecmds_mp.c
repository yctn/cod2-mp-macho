/* Converted to C from ASM: cg_consolecmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_consolecmds_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

extern int CG_CrosshairPlayer(void);
extern void Cmd_ArgvBuffer(int arg, char *buf, int bufSize);
extern const char * va(const char *fmt, ...);
extern void Cbuf_AddText(const char *text);
extern void Dvar_SetInt(void *dvar, int value);
extern void Com_Printf(const char *fmt, ...);
extern int CG_ScoreboardDisplayed(void);
extern int Cmd_Argc(void);
extern void CG_SetShellShockParmsFromDvars(byte *parms);
extern int CG_LoadShellShockDvars(const char *name);
extern void CG_SaveShellShockDvars(const char *name);
extern float floorf(float x);
extern void Cmd_ArgsBuffer(char *buf, int bufSize);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void CL_AddReliableCommand(const char *cmd);
extern const char * CG_Argv(int arg);
extern int I_stricmp(const char *s1, const char *s2);
extern void CL_AddCgameCommand(const char *cmdName);
extern void CL_Popup(const char *name);
extern const char * UI_SafeTranslateString(const char *key);

extern byte *cg_viewscreen_ptr; /* imp_cg_viewsize */
extern byte *cgs_ptr;           /* imp_cgs */
extern byte *cg_ptr;            /* imp_cg */

static const consoleCommand_t commandsList[21]; /* commandsList */

void CG_TargetCommand_f(void);
static void CG_SizeUp_f(void);
static void CG_SizeDown_f(void);
static void CG_Viewpos_f(void);
void CG_ScoresUp_f(void);
void CG_ScoresDown_f(void);
static void CG_ShellShock_f(void);
static void CG_ShellShock_Load_f(void);
static void CG_ShellShock_Save_f(void);
static void CG_TellTarget_f(void);
static void CG_QuickMessage_f(void);
static void CG_VoiceChat_f(void);
static void CG_TeamVoiceChat_f(void);
qboolean CG_ConsoleCommand(void);
void CG_InitConsoleCommands(void);

/* line 17 */
void CG_TargetCommand_f(void)
{
    int targetNum;
    char test[4];

    targetNum = CG_CrosshairPlayer();
    if (targetNum == 0)
        return;

    Cmd_ArgvBuffer(1, test, 4);
    Cbuf_AddText(va("gc %i %i", targetNum, atoi(test)));
}

/* line 40 */
static void CG_SizeUp_f(void)
{
    byte *dvar_ptr = *(byte **)cg_viewscreen_ptr;
    byte *dvar = *(byte **)dvar_ptr;
    int val = *(int *)(dvar + 8);

    Dvar_SetInt(dvar, val + 10);
}

/* line 53 */
static void CG_SizeDown_f(void)
{
    byte *dvar_ptr = *(byte **)cg_viewscreen_ptr;
    byte *dvar = *(byte **)dvar_ptr;
    int val = *(int *)(dvar + 8);

    Dvar_SetInt(dvar, val - 10);
}

/* line 66 */
static void CG_Viewpos_f(void)
{
    cg_t *cg = *(cg_t **)cg_ptr;

    Com_Printf("(%i %i %i) : %i\n",
        (int)cg->refdef.vieworg[0],
        (int)cg->refdef.vieworg[1],
        (int)cg->refdef.vieworg[2],
        (int)cg->refdefViewAngles[1]);
}

/* line 77 */
void CG_ScoresUp_f(void)
{
    cg_t *cg;

    if (!CG_ScoreboardDisplayed())
        return;

    cg = *(cg_t **)cg_ptr;
    cg->showScores = 0;
    cg->scoreFadeTime = cg->time;
}

/* line 95 */
void CG_ScoresDown_f(void)
{
    cg_t *cg = *(cg_t **)cg_ptr;
    int currentTime = cg->time;
    int lastScoreTime = cg->scoresRequestTime;

    if (lastScoreTime + 2000 < currentTime) {
        cg->scoresRequestTime = currentTime;
        CL_AddReliableCommand("score");

        if (!CG_ScoreboardDisplayed()) {
            cg->numScores = 0;
            cg->scoresTop = 0;
        }
    }

    cg->showScores = 1;
}

/* line 153 */
static void CG_ShellShock_f(void)
{
    char arg[256];
    int argc;
    double duration;
    cg_t *cg;

    argc = Cmd_Argc();

    if (argc == 3) {
        Cmd_ArgvBuffer(2, arg, 256);
        if (!CG_LoadShellShockDvars(arg))
            return;
    } else if (argc != 2) {
        Com_Printf("USAGE: cg_shellshock <duration> <filename?>\n");
        return;
    }

    Cmd_ArgvBuffer(1, arg, 256);
    duration = atof(arg);

    cg = *(cg_t **)cg_ptr;
    CG_SetShellShockParmsFromDvars((byte *)cg + 0x68c4); /* TODO: unknown offset - likely cgs shellshockParms */

    cg->testShock.time = cg->time;
    cg->testShock.duration = (int)floorf((float)(duration * 1000.0) + 0.5f);
}

/* line 185 */
static void CG_ShellShock_Load_f(void)
{
    char name[64];

    if (Cmd_Argc() != 2) {
        Com_Printf("USAGE: cg_shellshock_load <name>\n");
        return;
    }

    Cmd_ArgvBuffer(1, name, 64);
    CG_LoadShellShockDvars(name);
}

/* line 205 */
static void CG_ShellShock_Save_f(void)
{
    char name[64];

    if (Cmd_Argc() != 2) {
        Com_Printf("USAGE: cg_shellshock_save <name>\n");
        return;
    }

    Cmd_ArgvBuffer(1, name, 64);
    CG_SaveShellShockDvars(name);
}

/* line 220 */
static void CG_TellTarget_f(void)
{
    int clientNum;
    char message[128];
    char command[128];

    clientNum = CG_CrosshairPlayer();
    if (clientNum == -1)
        return;

    Cmd_ArgsBuffer(message, 128);
    Com_sprintf(command, 128, "tell %i \"%s\"", clientNum, message);
    CL_AddReliableCommand(command);
}

/* line 238 */
static void CG_QuickMessage_f(void)
{
    cg_t *cg = *(cg_t **)cg_ptr;
    snapshot_t *nextSnap = cg->nextSnap;

    if (nextSnap == NULL)
        return;
    if (!(nextSnap->ps.pm_flags & 0x800000))
        return;

    CL_Popup("UIMENU_WM_QUICKMESSAGE");
}

/* line 249 */
static void CG_VoiceChat_f(void)
{
    char chatCmd[64];
    cg_t *cg;
    snapshot_t *nextSnap;

    if (Cmd_Argc() != 2)
        return;

    cg = *(cg_t **)cg_ptr;
    nextSnap = cg->nextSnap;

    if (nextSnap != NULL && nextSnap->ps.pm_type != 5 && !(nextSnap->ps.pm_flags & 0x800000)) {
        Com_Printf("%s\n", UI_SafeTranslateString("CGAME_NOSPECTATORVOICECHAT"));
        return;
    }

    Cmd_ArgvBuffer(1, chatCmd, 64);
    Cbuf_AddText(va("cmd vsay %s\n", chatCmd));
}

/* line 272 */
static void CG_TeamVoiceChat_f(void)
{
    char chatCmd[64];
    cg_t *cg;
    snapshot_t *nextSnap;

    if (Cmd_Argc() != 2)
        return;

    cg = *(cg_t **)cg_ptr;
    nextSnap = cg->nextSnap;

    if (nextSnap != NULL && nextSnap->ps.pm_type != 5 && !(nextSnap->ps.pm_flags & 0x800000)) {
        Com_Printf("%s\n", UI_SafeTranslateString("CGAME_NOSPECTATORVOICECHAT"));
        return;
    }

    Cmd_ArgvBuffer(1, chatCmd, 64);
    Cbuf_AddText(va("cmd vsay_team %s\n", chatCmd));
}

/* line 365 */
qboolean CG_ConsoleCommand(void)
{
    byte *cg;
    byte *snap;
    const char *cmd;
    byte *cmdList = (byte *)commandsList;
    int i;
    const char *name;
    void (*func)(void);

    cg = *(byte **)cg_ptr;
    {
        cg_t *cg_s = (cg_t *)cg;
        if (cg_s->snap == NULL || cg_s->nextSnap == NULL)
            return 0;
    }

    cmd = CG_Argv(0);
    name = *(const char **)cmdList;
    if (name == NULL)
        return 0;

    i = 0;
    while (name != NULL) {
        if (I_stricmp(cmd, name) == 0) {
            func = *(void (**)(void))(cmdList + 4);
            if (func != NULL) {
                func();
            }
            return 1;
        }
        i++;
        cmdList += 8;
        name = *(const char **)cmdList;
    }

    return 0;
}

/* line 400 */
void CG_InitConsoleCommands(void)
{
    byte *cmdList = (byte *)commandsList;
    const char *name;

    name = *(const char **)cmdList;
    while (name != NULL) {
        CL_AddCgameCommand(name);
        cmdList += 8;
        name = *(const char **)cmdList;
    }

    CL_AddCgameCommand("kill");
    CL_AddCgameCommand("give");
    CL_AddCgameCommand("take");
    CL_AddCgameCommand("god");
    CL_AddCgameCommand("demigod");
    CL_AddCgameCommand("notarget");
    CL_AddCgameCommand("noclip");
    CL_AddCgameCommand("ufo");
    CL_AddCgameCommand("levelshot");
    CL_AddCgameCommand("setviewpos");
    CL_AddCgameCommand("jumptonode");
    CL_AddCgameCommand("stats");
    CL_AddCgameCommand("say");
    CL_AddCgameCommand("say_team");
    CL_AddCgameCommand("tell");
    CL_AddCgameCommand("team");
    CL_AddCgameCommand("follow");
    CL_AddCgameCommand("callvote");
    CL_AddCgameCommand("vote");
    CL_AddCgameCommand("follownext");
    CL_AddCgameCommand("followprev");
    CL_AddCgameCommand("printentities");
    CL_AddCgameCommand("muteplayer");
    CL_AddCgameCommand("unmuteplayer");
}
