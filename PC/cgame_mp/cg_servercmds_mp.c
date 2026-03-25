/* Decompiled from: cg_servercmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_servercmds_mp.cpp */

#include "common_types.h"
#include "imports.h"

#include <string.h>
#include <stdlib.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern float floorf(float x);

/* Extern declarations for called functions */
extern const char *CL_GetConfigString(int index);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern void Dvar_SetStringByName(const char *dvarName, const char *value);
extern void Dvar_SetFromStringByName(const char *dvarName, const char *value);
extern const char *GetBspExtension(void);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void Com_Error(errorParm_t code, const char *fmt, ...);
extern const char *CG_Argv(int arg);
extern int Cmd_Argc(void);
extern void Cbuf_AddText(const char *text);
extern const char *va(const char *format, ...);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern int I_stricmp(const char *s1, const char *s2);
extern int CL_Popup(const char *menuName);
extern void CL_ClosePopup(const char *menuName);
extern const char *Com_Parse(const char **data_p);
extern void CL_SwitchFog(int fogIndex, int serverTime, int transitionTime);
extern void CL_SetFog(int fogIndex, float start, float halfDist, int r, int g, int b, float density);
extern void SND_DeactivateChannelVolumes(int prio, int fadeTime);
extern void SND_SetChannelVolumes(int prio, char *volumes, int fadeTime);
extern void SND_DeactivateEnvironmentEffects(int prio, int fadeTime);
extern int Load_ScriptMenu(const char *name, int flags);
extern void CL_RegisterMaterialNoMip(const char *name, int flags);
extern void CL_RegisterMaterial(const char *name, int flags);
extern void CG_InitLocalEntities(void);
extern void CG_InitMarkPolys(void);
extern void FX_FreeActive(void);
extern void SND_StopSounds(int mode);
extern void CG_StartAmbient(void);
extern void Dvar_SetBool(void *dvar, int value);
extern void CL_SetADS(int value);
extern void CL_CloseAllMenus(void);
extern void CG_ScoresUp_f(void);
extern void CL_SyncTimes(void);
extern int CL_GetServerCommand(int seq);
extern int stricmp(const char *s1, const char *s2);

/*
 * Indirect global pointers (absolute addresses from original binary).
 *   imp_cgs -> cgs_t* (game static state)
 *   imp_cg -> cg_t* (main cgame state)
 *   imp_legacyHacks -> cgame UI state
 *   imp_cg_chatHeight -> dvar (cg_teamChatHeight)
 *   imp_cg_chatTime -> dvar (cg_teamChatTime)
 *   imp_cg_showmiss -> dvar (developer)
 *   imp_cg_thirdPerson -> dvar
 *   imp_cg_teamChatsOnly -> dvar (cl_paused)
 */
#define CGS_PTR      (*(cgs_t **)imp_cgs)
#define CG_PTR       (*(cg_t **)imp_cg)
#define CGUI_PTR     ((LegacyHacks *)(void *)imp_legacyHacks)

void CG_ParseServerinfo(void);
void CG_ParseCodinfo(void);
static void CG_AddToTeamChat(void);
static void CG_OpenScriptMenu(void);
void CG_CheckOpenWaitingScriptMenu(void);
void CG_CloseScriptMenu(void);
void CG_MenuShowNotify(int menuToShow);
static void CG_SetClientDvarFromServer(void);
void CG_ParseFog(void);
static void CG_DeactivateChannelVolCmd(void);
static void CG_SetChannelVolCmd(void);
static void CG_DeactivateReverbCmd(void);
void CG_SetConfigValues(void);
void CG_MapRestart(qboolean savepersist);
void CG_ServerCommand(void);
void CG_ExecuteNewServerCommands(int latestSequence);

/* line 148 */
void CG_ParseServerinfo(void)
{
    const char *info;
    const char *val;
    cgs_t *cgs;
    const char *mapname;
    const char *ext;

    info = CL_GetConfigString(0);

    val = Info_ValueForKey(info, (const char *)"sv_hostname");
    cgs = CGS_PTR;
    strncpy(cgs->szHostName, val, 0x100);

    val = Info_ValueForKey(info, (const char *)"g_gametype");
    strncpy(cgs->gametype, val, 0x20);

    if (cgs->localServer == 0) {
        Dvar_SetStringByName((const char *)"g_gametype", cgs->gametype);
    }

    val = Info_ValueForKey(info, (const char *)"sv_maxclients");
    cgs->maxclients = atoi(val);

    mapname = Info_ValueForKey(info, (const char *)"mapname");
    ext = GetBspExtension();
    Com_sprintf(cgs->mapname, 0x40, (const char *)"maps/mp/%s.%s", mapname, ext);
}

/* line 172 */
void CG_ParseCodinfo(void)
{
    cgs_t *cgs;
    int i;
    const char *key;

    cgs = CGS_PTR;
    if (cgs->localServer != 0) {
        return;
    }

    for (i = 0x8e; i < 0xee; i++) {
        key = CL_GetConfigString(i);
        if (*key == '\0') {
            break;
        }
        Dvar_SetFromStringByName(key, CL_GetConfigString(i + 0x60));
    }
}

/* line 540 — uses register calling convention (str in eax), called from naked CG_ServerCommand */
static void CG_AddToTeamChat_impl(const char *str)
{
    cgs_t *cgs_lp;
    cg_t *cg_lp;
    int chatHeight;
    int chatCount;
    int row;
    char *dst;
    int len;
    int lastcolor;
    char *ls;
    const char *p;

    /* line 547: get chat height dvar */
    chatHeight = ((dvar_t *)(void *)imp_cg_chatHeight)->current.integer;
    if (chatHeight == 0)
        goto zero_out;

    if (((dvar_t *)(void *)imp_cg_chatTime)->current.integer <= 0)
        goto zero_out;

    /* line 557: compute destination row */
    cgs_lp = CGS_PTR;
    chatCount = cgs_lp->teamChatPos;
    row = chatCount % chatHeight;

    dst = cgs_lp->teamChatMsgs[row];

    /* line 558 */
    dst[0xc] = '\0';

    len = 0;
    lastcolor = 0x37; /* '7' */
    ls = NULL;
    p = str;
    dst = cgs_lp->teamChatMsgs[row] + 0xc;

    while (*p != '\0') {
        char ch;
        const char *savedp;

        /* line 565 */
        if (len > 0x59) {
            /* line 567: line too long, wrap */
            if (ls != NULL) {
                /* line 569-571: back up to last space */
                int backDist = (int)(dst - ls);
                p = p - backDist + 1;
                dst = ls;
            }

            /* line 573: null terminate */
            *dst = '\0';

            /* line 575: advance to next row */
            cgs_lp = CGS_PTR;
            chatCount = cgs_lp->teamChatPos;
            {
                int r = chatCount % chatHeight;
                cg_lp = CG_PTR;
                cgs_lp->teamChatMsgTimes[r] = cg_lp->time;
            }

            /* line 577 */
            chatCount += 1;
            cgs_lp->teamChatPos = chatCount;

            /* line 578: new row */
            row = chatCount % chatHeight;
            dst = cgs_lp->teamChatMsgs[row] + 0xc;

            /* line 580: prepend color code */
            *dst++ = '^';
            *dst++ = (char)(lastcolor & 0xff);

            if (p == NULL) {
                /* line 591: null str edge case */
                ls = NULL;
                len = 1;
                /* go to end check */
                ch = '\0';
                goto check_space;
            }
            len = 0;
            ls = NULL;

            if (*p == '^')
                goto handle_caret;

            goto copy_char;
        }

        savedp = p;

        /* line 586: check for caret color code */
        if (*p == '^') {
handle_caret:
            p++;
            ch = *(savedp + 1);
            if (ch == '\0' || ch == '^' || ch <= '/' || ch > '9') {
                /* not a valid color code, just advance len */
                len++;
                ch = *savedp;
                goto check_space;
            }
            /* line 588-590: valid color code */
            *dst++ = '^';
            lastcolor = (signed char)ch;
            *dst++ = ch;
            p = savedp + 2;
            continue;
        }

copy_char:
        /* line 565 */
        savedp = p;
        p++;
        len++;

check_space:
        /* line 593: track last space */
        ch = *savedp;
        if (ch == ' ')
            ls = dst;

        /* line 597 */
        *dst++ = ch;
        continue;
    }

    /* line 600: null terminate */
    *dst = '\0';

    /* line 602: record timestamp */
    cgs_lp = CGS_PTR;
    chatCount = cgs_lp->teamChatPos;
    {
        int r = chatCount % chatHeight;
        cg_lp = CG_PTR;
        cgs_lp->teamChatMsgTimes[r] = cg_lp->time;
    }

    /* line 603 */
    chatCount += 1;
    cgs_lp->teamChatPos = chatCount;

    /* line 605 */
    if (chatHeight < chatCount - cgs_lp->teamLastChatPos) {
        /* line 606 */
        cgs_lp->teamLastChatPos = chatCount - chatHeight;
    }
    return;

zero_out:
    /* line 551 */
    cgs_lp = CGS_PTR;
    cgs_lp->teamLastChatPos = 0;
    cgs_lp->teamChatPos = 0;
}

