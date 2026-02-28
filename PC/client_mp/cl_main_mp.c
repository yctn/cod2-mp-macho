/* ASM dump from: cl_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_main_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern Bool Sys_IsMainThread(void);
extern int UI_IsFullscreen(void);
extern void Com_Printf(const char *fmt, ...);
extern const char * FS_LoadedIwdNames(void);
extern const char * FS_ReferencedIwdNames(void);
extern Bool Voice_IsClientTalking(int clientIndex);
extern void Com_SetRecommended(int);
extern void Sys_StartProcess(const char *exeName, int doexit);
extern void UI_SetActiveMenu(int menu);
extern void Sys_ShowIP(void);
extern void Com_Error(int code, const char *fmt, ...);
extern void FS_FCloseFile(int f);
extern void MSG_WriteReliableCommandToBuffer(const char *cmd, char *buf, int bufSize);
extern void FS_Write(const void *buffer, int len, int f);
extern void CL_ShutdownCGame(void);
extern void CL_ShutdownUI(void);

extern refexport_t re; /* 0x0 */
extern const clientActive_t * cl; /* 0x0 */
extern const clientConnection_t * clc; /* 0x0 */
extern struct clientStatic_t cls; /* 0x0 */
extern const dvar_t *cl_nodelta; /* 0x0 */
extern const dvar_t *cl_noprint; /* 0x0 */
extern const dvar_t *cl_maxpackets; /* 0x0 */
extern const dvar_t *cl_packetdup; /* 0x0 */
extern const dvar_t *cl_shownet; /* 0x0 */
extern const dvar_t *cl_shownuments; /* 0x0 */
extern const dvar_t *cl_showSend; /* 0x0 */
extern const dvar_t *cl_showServerCommands; /* 0x0 */
extern const dvar_t *cl_showTimeDelta; /* 0x0 */
extern const dvar_t *cl_freezeDemo; /* 0x0 */
extern const dvar_t *cl_sensitivity; /* 0x0 */
extern const dvar_t *cl_freelook; /* 0x0 */
extern const dvar_t *cl_mouseAccel; /* 0x0 */
extern const dvar_t *cl_showMouseRate; /* 0x0 */
extern const dvar_t *m_pitch; /* 0x0 */
extern const dvar_t *m_yaw; /* 0x0 */
extern const dvar_t *m_forward; /* 0x0 */
extern const dvar_t *m_side; /* 0x0 */
extern const dvar_t *m_filter; /* 0x0 */
extern const dvar_t *cl_activeAction; /* 0x0 */
extern const dvar_t *cl_allowDownload; /* 0x0 */
extern const dvar_t *cl_inGameVideo; /* 0x0 */
extern const dvar_t *fx_enable; /* 0x0 */
extern const dvar_t *fx_draw; /* 0x0 */
extern const dvar_t *fx_cull; /* 0x0 */
extern const dvar_t *fx_sort; /* 0x0 */
extern const dvar_t *fx_debug; /* 0x0 */
extern const dvar_t *fx_debugBolt; /* 0x0 */
extern const dvar_t *fx_freeze; /* 0x0 */
extern const dvar_t *fx_count; /* 0x0 */
extern const dvar_t *fx_visMinTraceDist; /* 0x0 */
extern const dvar_t *fx_profile; /* 0x0 */
extern const dvar_t *nextdemo; /* 0x0 */
extern const dvar_t *cl_timeout; /* 0x0 */
extern const dvar_t *cl_connectTimeout; /* 0x0 */
extern const dvar_t *cl_avidemo; /* 0x0 */
extern const dvar_t *cl_forceavidemo; /* 0x0 */
extern const dvar_t *cl_motdString; /* 0x0 */
extern const dvar_t *cl_serverStatusResendTime; /* 0x0 */
extern const dvar_t *cl_ingame; /* 0x0 */
extern const dvar_t *name; /* 0x0 */
extern const dvar_t *cl_voice; /* 0x0 */
extern clientActive_t clients[1]; /* 0x0 */
extern clientConnection_t clientConnections[1]; /* 0x0 */
extern Bool g_waitingForServer; /* 0x0 */
extern ping_t cl_pinglist[16]; /* 0x0 */
extern unsigned int frame_msec; /* 0x0 */
extern int old_com_frameTime; /* 0x0 */
static char szServerIPAddress[128]; /* 0xe86ea0 */
static qboolean recursive; /* 0xe86f20 */
static const dvar_t *input_viewSensitivity; /* 0xe86e80 */

void CL_SwitchToLocalClient(int clientNum);
Bool CL_GetLocalClientActive(int clientNum);
int CL_GetLocalClientActiveCount(void);
Bool CL_AllLocalClientsDisconnected(void);
Bool CL_AnyLocalClientChallenging(void);
Bool CL_IsRenderingSplitScreen(void);
const char * CL_GetUsernameForLocalClient(int controllerIndex);
void CL_AddReliableCommand(const char *cmd);
void CL_StopRecord_f(void);
void CL_ShutdownDemo(void);
int CL_GetSkelTimeStamp(int localClientNum);
char * CL_AllocSkelMemory(int localClientNum, unsigned int size);
void CL_ResetSkeletonCache(int localClientNum);
void CL_ClearState(void);
void CL_Setenv_f(void);
void CL_Reconnect_f(void);
void CL_OpenedIWDList_f(void);
void CL_ReferencedIWDList_f(void);
void CL_Configstrings_f(void);
void CL_Clientinfo_f(void);
void CL_VoicePacket(msg_t *msg);
Bool CL_IsPlayerTalking(int clientIndex);
void CL_SetupForNewServerMap(const char *pszMapName, const char *pszGametype);
void CL_VoiceTransmit(void);
Bool Voice_SendVoiceData(void);
void CL_SyncGpu(void);
void CL_SetRecommended_f(void);
void CL_RefPrintf(int print_level, const char *fmt);
void CL_ShutdownRef(void);
void CL_InitRenderer(void);
void CL_StartHunkUsers(void);
int CL_ScaledMilliseconds(void);
void CL_InitRef(void);
void CL_startSingleplayer_f(void);
void CL_StopLogo(void);
void CL_ToggleMenu_f(void);
void CL_OpenScriptMenu_f(void);
void CL_InitOnceForAllClients(void);
void CL_ShutdownDebugData(void);
void CL_GetPing(int n, char *buf, int buflen, int *pingtime);
void CL_ShowIP_f(void);
const char * CL_GetServerIPAddress(void);
void CL_FlushDebugData(qboolean fromServer);
void CL_UpdateDebugData(void);
int CL_TextWidth(const char *text, int maxChars, FontHandle font);
int CL_TextHeight(FontHandle font);
float CL_NormalizedTextScale(FontHandle font, float scale);
void CL_DrawTextPhysical(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style);
void CL_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec_t *color, int style);
void CL_DrawTextPhysicalWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor);
void CL_DrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor);
int CL_GetKeyCatchers(void);
Bool CL_GetDisplayHUDWithKeycatchUI(void);
FontHandle CL_RegisterFont(const char *fontName, int imageTrack);
void CL_WriteDemoMessage(msg_t *msg, int headerBytes);
void CL_Record_f(void);
void CL_ShutdownHunkUsers(void);
void CL_InitLoad(const char *mapname, const char *gametype);
void CL_DrawLogo(void);
void CL_StopLogoOrCinematic(void);
void CL_AddDebugLine(const vec_t *start, const vec_t *end, const vec_t *color, qboolean depthTest, int duration, qboolean fromServer);
void CL_AddDebugString(const vec_t *xyz, const vec_t *color, float scale, const char *text, qboolean fromServer);
void CL_RequestAuthorization(void);
void CL_CheckForResend(void);
void CL_LocalServers_f(void);
void CL_PlayLogo_f(void);
qboolean CL_UpdateDirtyPings_f(int source);
void CL_RunOncePerClientFrame(int msec);
int Client_SendVoiceData(int bytes, char *enc_buffer);
Bool CL_ConnectionlessPacket(netadr_t from, msg_t *msg, int time);
Bool CL_PacketEvent(netadr_t from, msg_t *msg, int time);
void CL_Init(void);
void CL_ShutdownAll(void);
void CL_Frame(int msec);
void CL_Vid_Restart_f(void);
void CL_Snd_Restart_f(void);
void CL_Disconnect(void);
void CL_Shutdown(void);
void CL_Disconnect_f(void);
void CL_MapLoading(const char *mapname);
void CL_DemoCompleted(void);
void CL_ReadDemoMessage(void);
void CL_PlayDemo_f(void);
void CL_ForwardCommandToServer(const char *string);
void CL_ForwardToServer_f(void);
void CL_DownloadsComplete(void);
void CL_BeginDownload(const char *localName, const char *remoteName);
void CL_NextDownload(void);
void CL_InitDownloads(void);

/* line 250 */
void CL_SwitchToLocalClient(int clientNum)
{
    /* no-op - single client */
}

/* line 331 */
Bool CL_GetLocalClientActive(int clientNum)
{
    return 1;
}

/* line 343 */
int CL_GetLocalClientActiveCount(void)
{
    return 1;
}

/* line 462 */
Bool CL_AllLocalClientsDisconnected(void)
{
    if (!Sys_IsMainThread())
        return 1;
    if (UI_IsFullscreen())
        return 1;
    if (*(byte *)&clients[0] == 0)
        return 1;
    if (*(int *)&clientConnections[0] > 2)
        return 0;
    return 1;
}

/* line 517 */
Bool CL_AnyLocalClientChallenging(void)
{
    if (*(byte *)&clients[0] != 0 && *(int *)&clientConnections[0] == 4)
        return 1;
    return 0;
}

/* line 537 */
Bool CL_IsRenderingSplitScreen(void)
{
    return 0;
}

/* line 609 */
const char * CL_GetUsernameForLocalClient(int controllerIndex)
{
    return name->current.string;
}

/* line 645 */
void CL_AddReliableCommand(const char *cmd)
{
    int index;
    if (*(int *)0x14c1550 - *(int *)0x14c1554 - 128 > 0)
    {
        Com_Error(1, "CL_AddReliableCommand: too many commands");
    }
    *(int *)((byte *)clc + 0x130) += 1;
    index = *(int *)((byte *)clc + 0x130) & 0x7f;
    MSG_WriteReliableCommandToBuffer(cmd, (char *)((byte *)clc + 0x138 + index * 0x400), 0x400);
}

/* line 700 */
__attribute__((naked))
void CL_StopRecord_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 700 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "movl 0x1501bbc, %eax\n" /* line 704 */
        "testl %eax, %eax\n"
        "jne .Lf147862_00147886\n"
        "movl $0x2a8a78, (%esp)\n" /* line 706 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 718 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf147862_00147886:\n"
        "movl $0xffffffff, -0xc(%ebp)\n" /* line 711 | len */
        "movl 0x1501bd0, %eax\n" /* line 712 */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0xc(%ebp), %esi\n" /* len */
        "movl %esi, (%esp)\n"
        "calll FS_Write\n"
        "movl clc, %ebx\n" /* line 713 */
        "movl 0x407b0(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FS_Write\n"
        "movl 0x407b0(%ebx), %eax\n" /* line 714 */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl $0, 0x407b0(%ebx)\n" /* line 715 */
        "movl $0, 0x4079c(%ebx)\n" /* line 716 */
        "movl $0x2a8a90, (%esp)\n" /* line 717 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 718 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1161 */
void CL_ShutdownDemo(void)
{
    if (!*(int *)0x1501bd0)
        return;
    FS_FCloseFile(*(int *)0x1501bd0);
    *(int *)((byte *)clc + 0x407b0) = 0;
    *(int *)((byte *)clc + 0x407a0) = 0;
    *(int *)((byte *)clc + 0x4079c) = 0;
}

/* line 1272 */
int CL_GetSkelTimeStamp(int localClientNum)
{
    /* stride: localClientNum * 386821 * 4 = localClientNum * 1547284 */
    return *(int *)(0x151228c + (unsigned)localClientNum * 386821 * 4);
}

/* line 1279 */
char * CL_AllocSkelMemory(int localClientNum, unsigned int size)
{
    char *client = (char *)&clients + (unsigned)localClientNum * 386821 * 4;
    int pos = *(int *)(client + 0x8650);
    char *buf = (char *)(pos + *(int *)(client + 0x48654));
    int newPos = pos + ((size + 15) & ~15);
    *(int *)(client + 0x8650) = newPos;
    if (newPos >= 0x3fff1)
        return 0;
    return buf;
}

/* line 1318 */
void CL_ResetSkeletonCache(int localClientNum)
{
    char *client = (char *)&clients + (unsigned)localClientNum * 386821 * 4;
    unsigned int count = *(unsigned int *)(client + 0x864c) + 1;
    if (!count)
        count = 1;
    *(unsigned int *)(client + 0x864c) = count;
    *(int *)(client + 0x48654) = ((int)(client + 0x8663)) & ~15;
    *(int *)(client + 0x8650) = 0;
}

/* line 1343 */
__attribute__((naked))
void CL_ClearState(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1343 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movzbl 0x1509c49, %ebx\n" /* line 1353 | cgameInitialized */
        "movzbl 0x1509c4a, %esi\n" /* line 1354 | cgameInitCalled */
        "movl 0x1509c44, %edi\n" /* line 1355 | keyCatchers */
        "movzbl 0x1509c48, %eax\n" /* line 1356 */
        "movb %al, -0x1a(%ebp)\n" /* displayHUDWithKeycatchUI */
        "movzbl clients, %edx\n" /* line 1357 */
        "movb %dl, -0x19(%ebp)\n" /* active */
        "movl $0x179c14, 8(%esp)\n" /* line 1359 */
        "movl $0, 4(%esp)\n"
        "movl $clients, (%esp)\n"
        "calll memset\n"
        "movl cl, %eax\n" /* line 1361 */
        "movb %bl, 9(%eax)\n" /* cgameInitialized */
        "movl %esi, %edx\n" /* line 1362 | cgameInitCalled */
        "movb %dl, 0xa(%eax)\n"
        "movl %edi, 4(%eax)\n" /* line 1363 | keyCatchers */
        "movzbl -0x1a(%ebp), %edx\n" /* line 1364 | displayHUDWithKeycatchUI */
        "movb %dl, 8(%eax)\n"
        "movzbl -0x19(%ebp), %edx\n" /* line 1365 | active */
        "movb %dl, (%eax)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1368 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_ClientDObjClearAllSkel\n" /* line 1367 */
    );
}

/* line 1669 */
__attribute__((naked))
void CL_Setenv_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1669 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        /* { scope 1: buffer */
        "calll Cmd_Argc\n" /* line 1671 */
        "movl %eax, %edi\n" /* argc */
        "cmpl $2, %eax\n" /* line 1673 */
        "jg .Lf147a76_00147a9f\n"
        "je .Lf147a76_00147b30\n" /* line 1692 */
        /* } scope */
        ".Lf147a76_00147a94:\n"
        "addl $0x41c, %esp\n" /* line 1713 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buffer */
        /* { scope 2 */
        ".Lf147a76_00147a9f:\n"
        "movl $1, (%esp)\n" /* line 1678 */
        "calll Cmd_Argv\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %esi\n" /* buffer */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x222904, 8(%esp)\n" /* line 1679 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        "movl $2, %ebx\n" /* i */
        ".Lf147a76_00147ae2:\n"
        "movl %ebx, (%esp)\n" /* line 1683 | i */
        "calll Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        "movl $0x217914, 8(%esp)\n" /* line 1684 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        "addl $1, %ebx\n" /* line 1681 | i */
        "cmpl %ebx, %edi\n" /* i, argc */
        "jne .Lf147a76_00147ae2\n"
        "movl %esi, (%esp)\n" /* line 1688 */
        "calll putenv\n"
        /* } scope */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 1713 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buffer */
        /* { scope 2 */
        ".Lf147a76_00147b30:\n"
        "movl $1, (%esp)\n" /* line 1697 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll getenv\n"
        "movl %eax, %ebx\n" /* env */
        "testl %eax, %eax\n" /* line 1704 */
        "je .Lf147a76_00147b75\n"
        "movl $1, (%esp)\n" /* line 1706 */
        "calll Cmd_Argv\n"
        "movl %ebx, 8(%esp)\n" /* env */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a8aa0, (%esp)\n" /* "%s=%s
" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 1713 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buffer */
        /* { scope 2 */
        ".Lf147a76_00147b75:\n"
        "movl $1, (%esp)\n" /* line 1710 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2a8aa8, (%esp)\n" /* "%s undefined
" */
        "calll Com_Printf\n"
        "jmp .Lf147a76_00147a94\n"
    );
}

/* line 1744 */
__attribute__((naked))
void CL_Reconnect_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1744 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "cmpb $0, 0x1220968\n" /* line 1746 */
        "je .Lf147b96_00147bce\n"
        "movl $0x1220968, %esi\n"
        "movl $0x2a8ab8, %edi\n" /* "localhost" */
        "movl $0xa, %ecx\n"
        "cld\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf147b96_00147bca\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf147b96_00147bca:\n"
        "testl %eax, %eax\n"
        "jne .Lf147b96_00147be1\n"
        ".Lf147b96_00147bce:\n"
        "movl $0x2a8ac4, (%esp)\n" /* line 1748 */
        "calll Com_Printf\n"
        "addl $0x10, %esp\n" /* line 1752 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf147b96_00147be1:\n"
        "movl $0x1220968, 4(%esp)\n" /* line 1751 */
        "movl $0x2a8ae4, (%esp)\n" /* "connect %s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        "addl $0x10, %esp\n" /* line 1752 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1946 */
void CL_OpenedIWDList_f(void)
{
    Com_Printf("Opened IWD Names: %s\n", FS_LoadedIwdNames());
}

/* line 1957 */
void CL_ReferencedIWDList_f(void)
{
    Com_Printf("Referenced IWD Names: %s\n", FS_ReferencedIwdNames());
}

/* line 1970 */
__attribute__((naked))
void CL_Configstrings_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1970 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "cmpl $8, clientConnections\n" /* line 1975 */
        "je .Lf147c40_00147c64\n"
        "movl $0x2a8b24, (%esp)\n" /* line 1977 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf147c40_00147c5d:\n"
        "addl $0x10, %esp\n" /* line 1990 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf147c40_00147c64:\n"
        "xorl %ebx, %ebx\n" /* line 1978 | i */
        "movl cl, %esi\n"
        "jmp .Lf147c40_00147c79\n"
        ".Lf147c40_00147c6e:\n"
        "addl $1, %ebx\n" /* line 1981 | i */
        "cmpl $0x800, %ebx\n" /* i */
        "je .Lf147c40_00147c5d\n"
        ".Lf147c40_00147c79:\n"
        "movl 0x270c(%esi, %ebx, 4), %eax\n" /* line 1983 */
        "testl %eax, %eax\n" /* line 1984 */
        "je .Lf147c40_00147c6e\n"
        "leal 0x470c(%esi, %eax), %eax\n" /* line 1988 */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $0x2a8b40, (%esp)\n" /* "%4i: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf147c40_00147c6e\n"
    );
}

/* line 1998 */
__attribute__((naked))
void CL_Clientinfo_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1998 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2a8b4c, (%esp)\n" /* line 2000 */
        "calll Com_Printf\n"
        "movl clc, %eax\n" /* line 2001 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2a8b74, (%esp)\n" /* "state: %i
" */
        "calll Com_Printf\n"
        "movl $0x1220968, 4(%esp)\n" /* line 2002 */
        "movl $0x2a74a0, (%esp)\n" /* "Server: %s
" */
        "calll Com_Printf\n"
        "movl $0x2a8b80, (%esp)\n" /* line 2003 */
        "calll Com_Printf\n"
        "movl $2, (%esp)\n" /* line 2004 */
        "calll Dvar_InfoString\n"
        "movl %eax, (%esp)\n"
        "calll Info_Print\n"
        "movl $0x2a8b98, (%esp)\n" /* line 2005 */
        "calll Com_Printf\n"
        "leave\n" /* line 2006 */
        "retl\n"
    );
}

/* line 2413 */
__attribute__((naked))
void CL_VoicePacket(msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2413 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x12c, %esp\n"
        "movl 8(%ebp), %esi\n" /* msg */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 2419 | msg */
        "calll MSG_ReadByte\n"
        "movl %eax, %ebx\n" /* numPackets */
        "cmpl $0x28, %eax\n" /* line 2421 */
        "ja .Lf147d0e_00147d30\n"
        "testl %eax, %eax\n" /* line 2424 */
        "jg .Lf147d0e_00147d3b\n"
        /* } scope */
        ".Lf147d0e_00147d30:\n"
        "addl $0x12c, %esp\n" /* line 2460 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf147d0e_00147d3b:\n"
        "xorl %edi, %edi\n" /* line 2421 | packet */
        "jmp .Lf147d0e_00147d46\n"
        ".Lf147d0e_00147d3f:\n"
        "addl $1, %edi\n" /* line 2424 | packet */
        "cmpl %edi, %ebx\n" /* packet, numPackets */
        "je .Lf147d0e_00147d30\n"
        ".Lf147d0e_00147d46:\n"
        "movl %esi, (%esp)\n" /* line 2427 | msg */
        "calll MSG_ReadByte\n"
        "movb %al, -0x11d(%ebp)\n" /* voicePacket */
        "movl %esi, (%esp)\n" /* line 2428 | msg */
        "calll MSG_ReadByte\n"
        "movl %eax, %edx\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal -1(%eax), %eax\n" /* line 2429 */
        "cmpl $0xff, %eax\n"
        "ja .Lf147d0e_00147dcb\n"
        "movl %edx, 8(%esp)\n" /* line 2435 */
        "leal -0x11c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* msg */
        "calll MSG_ReadData\n"
        "movzbl -0x11d(%ebp), %eax\n" /* line 2437 | voicePacket */
        "cmpb $0x3f, %al\n"
        "ja .Lf147d0e_00147de0\n"
        "movzbl %al, %eax\n" /* line 2443 */
        "movl %eax, (%esp)\n"
        "calll CL_IsPlayerMuted\n"
        "testb %al, %al\n"
        "jne .Lf147d0e_00147d3f\n"
        "movl cl_voice, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf147d0e_00147d3f\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2444 */
        "movl %eax, 8(%esp)\n"
        "leal -0x11c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movzbl -0x11d(%ebp), %eax\n" /* voicePacket */
        "movl %eax, (%esp)\n"
        "calll Voice_IncomingVoiceData\n"
        "jmp .Lf147d0e_00147d3f\n"
        ".Lf147d0e_00147dcb:\n"
        "movl %edx, 4(%esp)\n" /* line 2431 */
        "movl $0x2a8bc0, (%esp)\n" /* "Invalid server voice packet of %i bytes
" */
        "calll Com_Printf\n"
        "jmp .Lf147d0e_00147d30\n"
        ".Lf147d0e_00147de0:\n"
        "movzbl %al, %eax\n" /* line 2439 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a8bec, (%esp)\n" /* "Invalid voice packet - talker was %i
" */
        "calll Com_Printf\n"
        "jmp .Lf147d0e_00147d30\n"
    );
}

/* line 2463 */
Bool CL_IsPlayerTalking(int clientIndex)
{
    return Voice_IsClientTalking(clientIndex);
}

/* line 4736 */
__attribute__((naked))
void CL_SetupForNewServerMap(const char *pszMapName, const char *pszGametype)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4736 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* pszMapName */
        "movl 0xc(%ebp), %esi\n" /* pszGametype */
        "movl %esi, 8(%esp)\n" /* line 4738 | pszGametype */
        "movl %edi, 4(%esp)\n" /* pszMapName */
        "movl $0x2a8c14, (%esp)\n" /* "Server changing map %s, gametype %s
" */
        "calll Com_Printf\n"
        "movl $0x40, 8(%esp)\n" /* line 4740 */
        "movl %edi, 4(%esp)\n" /* pszMapName */
        "movl 0x195ecb4, %ebx\n"
        "movl (%ebx), %eax\n"
        "addl $0x5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x40, 8(%esp)\n" /* line 4741 */
        "movl %esi, 4(%esp)\n" /* pszGametype */
        "movl (%ebx), %eax\n"
        "addl $0x9c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl (%ebx), %eax\n" /* line 4742 */
        "movb $0, 0xdc(%eax)\n"
        "movl 0x195ecbc, %eax\n" /* line 4745 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf147e0e_00147e9f\n"
        "movl $0, 4(%esp)\n" /* line 4748 */
        "movl 0x195f2fc, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movb $1, g_waitingForServer\n" /* line 4750 */
        ".Lf147e0e_00147e9f:\n"
        "movl %esi, 4(%esp)\n" /* line 4753 | pszGametype */
        "movl %edi, (%esp)\n" /* pszMapName */
        "calll UI_SetMap\n"
        "addl $0x1c, %esp\n" /* line 4755 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp SCR_UpdateScreenInternal\n" /* line 4754 */
    );
}

/* line 2894 */
__attribute__((naked))
void CL_VoiceTransmit(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2894 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 0x168384c, %edx\n" /* line 2896 */
        "testl %edx, %edx\n"
        "jle .Lf147eba_00147f01\n"
        "movl 0x150c330, %eax\n" /* line 2899 */
        "subl 0x1683850, %eax\n"
        "cmpl $0xc7, %eax\n"
        "jg .Lf147eba_00147ee1\n"
        "cmpl $9, %edx\n"
        "jle .Lf147eba_00147f01\n"
        ".Lf147eba_00147ee1:\n"
        "calll CL_WriteVoicePacket\n" /* line 2903 */
        "movl cl, %eax\n" /* line 2905 */
        "movl $0, 0x179c0c(%eax)\n"
        "movl 0x26f0(%eax), %edx\n" /* line 2906 */
        "movl %edx, 0x179c10(%eax)\n"
        ".Lf147eba_00147f01:\n"
        "leave\n" /* line 2907 */
        "retl\n"
    );
}

/* line 2927 */
__attribute__((naked))
Bool Voice_SendVoiceData(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2927 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195f2a4, %eax\n" /* line 2929 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf147f04_00147f22\n"
        "movl cl_voice, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf147f04_00147f26\n"
        ".Lf147f04_00147f22:\n"
        "xorl %eax, %eax\n" /* line 2934 */
        "leave\n" /* line 2939 */
        "retl\n"
        ".Lf147f04_00147f26:\n"
        "movl $0x2a8c54, (%esp)\n" /* line 2929 */
        "calll Dvar_GetInt\n"
        "cmpl $0x1387, %eax\n"
        "jle .Lf147f04_00147f22\n"
        "movl clc, %eax\n" /* line 2932 */
        "cmpl $8, (%eax)\n"
        "jne .Lf147f04_00147f22\n"
        "movl 0x195f3f0, %eax\n" /* line 2934 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf147f04_00147f57\n"
        ".Lf147f04_00147f50:\n"
        "movl $1, %eax\n"
        ".Lf147f04_00147f55:\n"
        "leave\n" /* line 2939 */
        "retl\n"
        ".Lf147f04_00147f57:\n"
        "calll IsTalking\n" /* line 2934 */
        "testb %al, %al\n"
        "jne .Lf147f04_00147f50\n"
        "movl cl, %eax\n"
        "movl 0x179c0c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf147f04_00147f22\n"
        "movl $1, %eax\n"
        "jmp .Lf147f04_00147f55\n"
    );
}

/* line 4979 */
void CL_SyncGpu(void)
{
    ((void (*)(void))*(int *)0x121c7f4)();
}

/* line 3141 */
void CL_SetRecommended_f(void)
{
    Com_SetRecommended(1);
}

/* line 3181 */
__attribute__((naked))
void CL_RefPrintf(int print_level, const char *fmt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3181 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1020, %esp\n"
        "movl 8(%ebp), %ebx\n" /* print_level */
        /* { scope 1 */
        "leal 0x10(%ebp), %eax\n" /* line 3186 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 3187 */
        "movl 0xc(%ebp), %eax\n" /* fmt */
        "movl %eax, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "leal -0x100c(%ebp), %esi\n" /* msg */
        "movl %esi, (%esp)\n"
        "calll vsnprintf\n"
        "testl %ebx, %ebx\n" /* line 3190 | print_level */
        "je .Lf147f9a_00147fec\n"
        "cmpl $2, %ebx\n" /* line 3192 | print_level */
        "je .Lf147f9a_00148020\n"
        "cmpl $3, %ebx\n" /* line 3194 | print_level */
        "je .Lf147f9a_0014803a\n"
        "subl $1, %ebx\n" /* line 3196 | print_level */
        "je .Lf147f9a_00148006\n"
        /* } scope */
        ".Lf147f9a_00147fe2:\n"
        "addl $0x1020, %esp\n" /* line 3198 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf147f9a_00147fec:\n"
        "movl %esi, 4(%esp)\n" /* line 3191 */
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x1020, %esp\n" /* line 3198 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf147f9a_00148006:\n"
        "movl %esi, 4(%esp)\n" /* line 3197 */
        "movl $0x2a8c64, (%esp)\n" /* "^1%s" */
        "calll Com_DPrintf\n"
        /* } scope */
        "addl $0x1020, %esp\n" /* line 3198 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf147f9a_00148020:\n"
        "movl %esi, 4(%esp)\n" /* line 3193 */
        "movl $0x2a8c5c, (%esp)\n" /* "^3%s" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x1020, %esp\n" /* line 3198 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf147f9a_0014803a:\n"
        "movl %esi, 4(%esp)\n" /* line 3195 */
        "movl $0x2a8c64, (%esp)\n" /* "^1%s" */
        "calll Com_Printf\n"
        "jmp .Lf147f9a_00147fe2\n"
    );
}

/* line 3206 */
__attribute__((naked))
void CL_ShutdownRef(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3206 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x121c7e8, %eax\n" /* line 3208 */
        "testl %eax, %eax\n"
        "je .Lf14804c_0014805d\n"
        "calll *%eax\n" /* line 3209 */
        ".Lf14804c_0014805d:\n"
        "movl re, %eax\n" /* line 3211 */
        "testl %eax, %eax\n"
        "je .Lf14804c_0014808b\n"
        "movl $1, (%esp)\n" /* line 3213 */
        "calll *%eax\n"
        "movl $0x160, 8(%esp)\n" /* line 3219 */
        "movl $0, 4(%esp)\n"
        "movl $re, (%esp)\n"
        "calll memset\n"
        ".Lf14804c_0014808b:\n"
        "leave\n" /* line 3228 */
        "jmp StatMon_Reset\n" /* line 3223 */
    );
}

/* line 3236 */
__attribute__((naked))
void CL_InitRenderer(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3236 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0x14c13c4, (%esp)\n" /* line 3240 */
        "calll *0x121c6a4\n"
        "movl 0x14c13c8, %eax\n" /* line 3244 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x14c13c4, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetScreenScaling\n"
        "movl $3, 8(%esp)\n" /* line 3247 */
        "movl $3, 4(%esp)\n"
        "movl $0x224184, (%esp)\n" /* "white" */
        "calll *0x121c6b0\n"
        "movl %eax, 0x14c13b8\n"
        "movl $3, 8(%esp)\n" /* line 3248 */
        "movl $3, 4(%esp)\n"
        "movl $0x2a8c6c, (%esp)\n" /* "console" */
        "calll *0x121c6b0\n"
        "movl %eax, 0x14c13bc\n"
        "movl $3, 4(%esp)\n" /* line 3249 */
        "movl $0x2a8c74, (%esp)\n" /* "fonts/consoleFont" */
        "calll *0x121c780\n"
        "movl %eax, 0x14c13c0\n"
        "movl 0x14c13c4, %ecx\n" /* line 3250 */
        "subl $0x20, %ecx\n"
        "movl 0x195f260, %eax\n"
        "movl %ecx, (%eax)\n"
        "movl 0x195f480, %edx\n" /* line 3251 */
        "movl %ecx, 0xc(%edx)\n"
        "movl 0x195f258, %eax\n" /* line 3252 */
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl $1, 0x14(%edx)\n" /* line 3253 */
        "leave\n" /* line 3257 */
        "jmp StatMon_Reset\n" /* line 3256 */
    );
}

/* line 3342 */
__attribute__((naked))
void CL_StartHunkUsers(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3342 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 0x195ecb4, %eax\n" /* line 3346 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf148166_0014819f\n"
        "movl 0x1220a6c, %eax\n" /* line 3349 */
        "testl %eax, %eax\n"
        "je .Lf148166_001481d6\n"
        "movl 0x1220a68, %eax\n" /* line 3356 */
        "testl %eax, %eax\n"
        "je .Lf148166_001481b7\n"
        ".Lf148166_0014818c:\n"
        "movl 0x1220a70, %eax\n" /* line 3363 */
        "testl %eax, %eax\n"
        "je .Lf148166_001481a1\n"
        ".Lf148166_00148195:\n"
        "movl $1, 0x1220964\n" /* line 3382 */
        ".Lf148166_0014819f:\n"
        "leave\n" /* line 3383 */
        "retl\n"
        ".Lf148166_001481a1:\n"
        "calll CL_InitUI\n" /* line 3365 */
        "calll Sys_LoadingKeepAlive\n" /* line 3366 */
        "movl $1, 0x1220964\n" /* line 3382 */
        "jmp .Lf148166_0014819f\n"
        ".Lf148166_001481b7:\n"
        "movl $1, 0x1220a68\n" /* line 3358 */
        "calll CL_InitRenderer\n" /* line 3359 */
        "calll Sys_LoadingKeepAlive\n" /* line 3360 */
        "movl 0x1220a70, %eax\n" /* line 3363 */
        "testl %eax, %eax\n"
        "jne .Lf148166_00148195\n"
        "jmp .Lf148166_001481a1\n"
        ".Lf148166_001481d6:\n"
        "movl $1, 0x1220a6c\n" /* line 3351 */
        "calll SND_Init\n" /* line 3352 */
        "calll Sys_LoadingKeepAlive\n" /* line 3353 */
        "movl 0x1220a68, %eax\n" /* line 3356 */
        "testl %eax, %eax\n"
        "jne .Lf148166_0014818c\n"
        "jmp .Lf148166_001481b7\n"
    );
}

/* line 3386 */
int CL_ScaledMilliseconds(void)
{
    return *(int *)0x1220a78;
}

/* line 3422 */
__attribute__((naked))
void CL_InitRef(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3422 */
        "movl %esp, %ebp\n"
        "subl $0x238, %esp\n"
        /* { scope 1 */
        "movl $0x2a8c88, (%esp)\n" /* line 3432 */
        "calll Com_Printf\n"
        "movl 0x195f528, %eax\n" /* line 3439 */
        "movl %eax, -0x12c(%ebp)\n"
        "movl 0x195f418, %eax\n" /* line 3440 */
        "movl %eax, -0x128(%ebp)\n"
        "movl 0x195f558, %eax\n" /* line 3441 */
        "movl %eax, -0x124(%ebp)\n"
        "movl 0x195f4cc, %eax\n" /* line 3442 */
        "movl %eax, -0x120(%ebp)\n"
        "movl 0x195f388, %eax\n" /* line 3443 */
        "movl %eax, -0x11c(%ebp)\n"
        "movl $CL_RefPrintf, -0x224(%ebp)\n" /* line 3444 | ri */
        "movl 0x195f504, %eax\n" /* line 3445 */
        "movl %eax, -0x220(%ebp)\n"
        "movl $CL_ScaledMilliseconds, -0x21c(%ebp)\n" /* line 3446 */
        "movl 0x195f320, %eax\n" /* line 3458 */
        "movl %eax, -0x218(%ebp)\n"
        "movl 0x195f4b4, %eax\n" /* line 3459 */
        "movl %eax, -0x214(%ebp)\n"
        "movl 0x195f404, %eax\n" /* line 3460 */
        "movl %eax, -0x210(%ebp)\n"
        "movl 0x195f52c, %eax\n" /* line 3461 */
        "movl %eax, -0x20c(%ebp)\n"
        "movl 0x195f4c4, %eax\n" /* line 3462 */
        "movl %eax, -0x208(%ebp)\n"
        "movl 0x195f42c, %eax\n" /* line 3463 */
        "movl %eax, -0x204(%ebp)\n"
        "movl 0x195f34c, %eax\n" /* line 3464 */
        "movl %eax, -0x200(%ebp)\n"
        "movl 0x195f33c, %eax\n" /* line 3465 */
        "movl %eax, -0x1fc(%ebp)\n"
        "movl 0x195f35c, %eax\n" /* line 3466 */
        "movl %eax, -0x1f8(%ebp)\n"
        "movl 0x195f38c, %eax\n" /* line 3468 */
        "movl %eax, -0x1f4(%ebp)\n"
        "movl 0x195f434, %eax\n" /* line 3475 */
        "movl %eax, -0x1e4(%ebp)\n"
        "movl 0x195f4f4, %eax\n" /* line 3478 */
        "movl %eax, -0x1f0(%ebp)\n"
        "movl 0x195f44c, %eax\n" /* line 3479 */
        "movl %eax, -0x1e0(%ebp)\n"
        "movl 0x195f510, %eax\n" /* line 3494 */
        "movl %eax, -0x1dc(%ebp)\n"
        "movl 0x195f328, %eax\n" /* line 3495 */
        "movl %eax, -0x1d8(%ebp)\n"
        "movl 0x195f530, %eax\n" /* line 3496 */
        "movl %eax, -0x1d4(%ebp)\n"
        "movl 0x195f514, %eax\n" /* line 3499 */
        "movl %eax, -0x1d0(%ebp)\n"
        "movl 0x195f370, %eax\n" /* line 3500 */
        "movl %eax, -0xfc(%ebp)\n"
        "movl 0x195f3bc, %eax\n" /* line 3501 */
        "movl %eax, -0xf8(%ebp)\n"
        "movl 0x195f360, %eax\n" /* line 3502 */
        "movl %eax, -0xf4(%ebp)\n"
        "movl 0x195f3a8, %eax\n" /* line 3503 */
        "movl %eax, -0xe4(%ebp)\n"
        "movl 0x195f494, %eax\n" /* line 3505 */
        "movl %eax, -0xec(%ebp)\n"
        "movl 0x195f484, %eax\n" /* line 3506 */
        "movl %eax, -0xf0(%ebp)\n"
        "movl 0x195f548, %eax\n" /* line 3507 */
        "movl %eax, -0xe8(%ebp)\n"
        "movl 0x195f500, %eax\n" /* line 3509 */
        "movl %eax, -0xe0(%ebp)\n"
        "movl 0x195f3b8, %eax\n" /* line 3510 */
        "movl %eax, -0xdc(%ebp)\n"
        "movl 0x195f470, %eax\n" /* line 3511 */
        "movl %eax, -0xd8(%ebp)\n"
        "movl 0x195f488, %eax\n" /* line 3512 */
        "movl %eax, -0xd4(%ebp)\n"
        "movl 0x195f4a4, %eax\n" /* line 3515 */
        "movl %eax, -0xd0(%ebp)\n"
        "movl 0x195f424, %eax\n" /* line 3518 */
        "movl %eax, -0xcc(%ebp)\n"
        "movl 0x195f54c, %eax\n" /* line 3519 */
        "movl %eax, -0xc8(%ebp)\n"
        "movl 0x195f36c, %eax\n" /* line 3521 */
        "movl %eax, -0x1cc(%ebp)\n"
        "movl 0x195f55c, %eax\n" /* line 3522 */
        "movl %eax, -0x1c8(%ebp)\n"
        "movl 0x195f3d4, %eax\n" /* line 3523 */
        "movl %eax, -0x1c4(%ebp)\n"
        "movl 0x195f540, %eax\n" /* line 3524 */
        "movl %eax, -0x1c0(%ebp)\n"
        "movl 0x195f4f8, %eax\n" /* line 3525 */
        "movl %eax, -0x1bc(%ebp)\n"
        "movl 0x195f3e0, %eax\n" /* line 3526 */
        "movl %eax, -0x1b8(%ebp)\n"
        "movl 0x195f3c4, %eax\n" /* line 3527 */
        "movl %eax, -0x1b4(%ebp)\n"
        "movl 0x195f398, %eax\n" /* line 3528 */
        "movl %eax, -0x1b0(%ebp)\n"
        "movl 0x195f47c, %eax\n" /* line 3529 */
        "movl %eax, -0x1ac(%ebp)\n"
        "movl 0x195f384, %eax\n" /* line 3530 */
        "movl %eax, -0x19c(%ebp)\n"
        "movl 0x195f330, %eax\n" /* line 3531 */
        "movl %eax, -0x198(%ebp)\n"
        "movl 0x195f3a0, %eax\n" /* line 3532 */
        "movl %eax, -0x194(%ebp)\n"
        "movl 0x195f39c, %eax\n" /* line 3533 */
        "movl %eax, -0x1a8(%ebp)\n"
        "movl 0x195f518, %eax\n" /* line 3534 */
        "movl %eax, -0x1a4(%ebp)\n"
        "movl 0x195f440, %eax\n" /* line 3535 */
        "movl %eax, -0x1a0(%ebp)\n"
        "movl 0x195f464, %eax\n" /* line 3536 */
        "movl %eax, -0x190(%ebp)\n"
        "movl 0x195f478, %eax\n" /* line 3537 */
        "movl %eax, -0x18c(%ebp)\n"
        "movl 0x195f310, %eax\n" /* line 3538 */
        "movl %eax, -0x188(%ebp)\n"
        "movl 0x195f438, %eax\n" /* line 3539 */
        "movl %eax, -0x184(%ebp)\n"
        "movl 0x195f498, %eax\n" /* line 3540 */
        "movl %eax, -0x180(%ebp)\n"
        "movl 0x195f3a4, %eax\n" /* line 3541 */
        "movl %eax, -0x17c(%ebp)\n"
        "movl 0x195f4e0, %eax\n" /* line 3542 */
        "movl %eax, -0x178(%ebp)\n"
        "movl 0x195f3b0, %eax\n" /* line 3543 */
        "movl %eax, -0x174(%ebp)\n"
        "movl 0x195f410, %eax\n" /* line 3544 */
        "movl %eax, -0x170(%ebp)\n"
        "movl 0x195f41c, %eax\n" /* line 3545 */
        "movl %eax, -0x16c(%ebp)\n"
        "movl 0x195f538, %eax\n" /* line 3546 */
        "movl %eax, -0x168(%ebp)\n"
        "movl 0x195f544, %eax\n" /* line 3547 */
        "movl %eax, -0x164(%ebp)\n"
        "movl 0x195f350, %eax\n" /* line 3548 */
        "movl %eax, -0x160(%ebp)\n"
        "movl 0x195f550, %eax\n" /* line 3549 */
        "movl %eax, -0x15c(%ebp)\n"
        "movl 0x195f40c, %eax\n" /* line 3550 */
        "movl %eax, -0x158(%ebp)\n"
        "movl 0x195f4ec, %eax\n" /* line 3551 */
        "movl %eax, -0x154(%ebp)\n"
        "movl 0x195f428, %eax\n" /* line 3552 */
        "movl %eax, -0x150(%ebp)\n"
        "movl 0x195f3cc, %eax\n" /* line 3553 */
        "movl %eax, -0x14c(%ebp)\n"
        "movl 0x195f338, %eax\n" /* line 3554 */
        "movl %eax, -0x148(%ebp)\n"
        "movl 0x195f4fc, %eax\n" /* line 3555 */
        "movl %eax, -0x144(%ebp)\n"
        "movl 0x195f4ac, %eax\n" /* line 3556 */
        "movl %eax, -0x140(%ebp)\n"
        "movl 0x195f560, %eax\n" /* line 3557 */
        "movl %eax, -0x13c(%ebp)\n"
        "movl 0x195f508, %eax\n" /* line 3558 */
        "movl %eax, -0x138(%ebp)\n"
        "movl 0x195f3ac, %eax\n" /* line 3559 */
        "movl %eax, -0x134(%ebp)\n"
        "movl 0x195f458, %eax\n" /* line 3560 */
        "movl %eax, -0x130(%ebp)\n"
        "movl 0x195f31c, %eax\n" /* line 3562 */
        "movl %eax, -0x118(%ebp)\n"
        "movl 0x195f344, %eax\n" /* line 3563 */
        "movl %eax, -0x114(%ebp)\n"
        "movl 0x195f524, %eax\n" /* line 3565 */
        "movl %eax, -0x110(%ebp)\n"
        "movl 0x195f53c, %eax\n" /* line 3570 */
        "movl %eax, -0x10c(%ebp)\n"
        "movl $CL_UpdateDebugData, -0x108(%ebp)\n" /* line 3572 */
        "movl $CL_FlushDebugData, -0x104(%ebp)\n" /* line 3573 */
        "movl 0x195f4c8, %eax\n" /* line 3574 */
        "movl %eax, -0x100(%ebp)\n"
        "movl 0x195f490, %eax\n" /* line 3587 */
        "movl %eax, -0xc0(%ebp)\n"
        "movl 0x195f3b4, %eax\n" /* line 3588 */
        "movl %eax, -0xbc(%ebp)\n"
        "movl 0x195f420, %eax\n" /* line 3589 */
        "movl %eax, -0xb8(%ebp)\n"
        "movl 0x195f444, %eax\n" /* line 3590 */
        "movl %eax, -0xb4(%ebp)\n"
        "movl 0x195f554, %eax\n" /* line 3591 */
        "movl %eax, -0xb0(%ebp)\n"
        "movl 0x195f48c, %eax\n" /* line 3592 */
        "movl %eax, -0xac(%ebp)\n"
        "movl 0x195f37c, %eax\n" /* line 3593 */
        "movl %eax, -0xa8(%ebp)\n"
        "movl 0x195f460, %eax\n" /* line 3594 */
        "movl %eax, -0xa4(%ebp)\n"
        "movl 0x195f390, %eax\n" /* line 3595 */
        "movl %eax, -0xa0(%ebp)\n"
        "movl 0x195f348, %eax\n" /* line 3596 */
        "movl %eax, -0x9c(%ebp)\n"
        "movl 0x195f4dc, %eax\n" /* line 3597 */
        "movl %eax, -0x98(%ebp)\n"
        "movl 0x195f468, %eax\n" /* line 3598 */
        "movl %eax, -0x94(%ebp)\n"
        "movl 0x195f450, %eax\n" /* line 3599 */
        "movl %eax, -0x90(%ebp)\n"
        "movl 0x195f3f8, %eax\n" /* line 3600 */
        "movl %eax, -0x8c(%ebp)\n"
        "movl 0x195f534, %eax\n" /* line 3602 */
        "movl %eax, -0x88(%ebp)\n"
        "movl 0x195f380, %eax\n" /* line 3603 */
        "movl %eax, -0x84(%ebp)\n"
        "movl 0x195f49c, %eax\n" /* line 3604 */
        "movl %eax, -0x80(%ebp)\n"
        "movl 0x195f324, %eax\n" /* line 3607 */
        "movl %eax, -0x7c(%ebp)\n"
        "movl 0x195f414, %eax\n" /* line 3610 */
        "movl %eax, -0x74(%ebp)\n"
        "movl 0x195f3fc, %eax\n" /* line 3611 */
        "movl %eax, -0x70(%ebp)\n"
        "movl 0x195f4f0, %eax\n" /* line 3612 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 0x195f374, %eax\n" /* line 3613 */
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x195f32c, %eax\n" /* line 3614 */
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x195f474, %eax\n" /* line 3616 */
        "movl %eax, -0x50(%ebp)\n"
        "movl 0x195f4d0, %eax\n" /* line 3617 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0x195f3dc, %eax\n" /* line 3618 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x195f334, %eax\n" /* line 3619 */
        "movl %eax, -0x44(%ebp)\n"
        "movl 0x195f4d4, %eax\n" /* line 3620 */
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x195f364, %eax\n" /* line 3621 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0x195f51c, %eax\n" /* line 3622 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x195f454, %eax\n" /* line 3623 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0x195f400, %eax\n" /* line 3624 */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x195f3d8, %eax\n" /* line 3625 */
        "movl %eax, -0x54(%ebp)\n"
        "movl 0x195f46c, %eax\n" /* line 3626 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x195f3e4, %eax\n" /* line 3627 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x195f4bc, %eax\n" /* line 3628 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x195f4b0, %eax\n" /* line 3629 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x195f4d8, %eax\n" /* line 3630 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x195f3d0, %eax\n" /* line 3631 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x195f4c0, %eax\n" /* line 3634 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x195f43c, %eax\n" /* line 3635 */
        "movl %eax, -0x18(%ebp)\n"
        "movl 0x195f45c, %eax\n" /* line 3636 */
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x195f448, %eax\n" /* line 3638 */
        "movl %eax, -0x10(%ebp)\n"
        "movl 0x195f3c0, %eax\n" /* line 3708 */
        "movl %eax, -0xc(%ebp)\n"
        "leal -0x224(%ebp), %eax\n" /* line 3727 | ri */
        "movl %eax, 4(%esp)\n"
        "movl $0x3b, (%esp)\n"
        "calll GetRefAPI\n"
        "movl $0x160, 8(%esp)\n" /* line 3731 */
        "movl %eax, 4(%esp)\n"
        "movl $re, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 4(%esp)\n" /* line 3734 */
        "movl 0x195ed18, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        /* } scope */
        "leave\n" /* line 3735 */
        "retl\n"
    );
}

/* line 3739 */
void CL_startSingleplayer_f(void)
{
    Sys_StartProcess("cod2sp_s.exe", 1);
}

/* line 3824 */
void CL_StopLogo(void)
{
    *(int *)&clientConnections[0] = 0;
}

/* line 3893 */
void CL_ToggleMenu_f(void)
{
    if (*(int *)0x1501bc0 != 0 || *(byte *)(*(int *)(*(int *)0x195ecb4) + 0xdc) != 0) {
        UI_SetActiveMenu(1);
    } else {
        UI_SetActiveMenu(2);
    }
}

/* line 3911 */
__attribute__((naked))
void CL_OpenScriptMenu_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3911 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 3918 */
        "cmpl $3, %eax\n"
        "je .Lf148802_00148835\n"
        "movl $0x2a8cbc, (%esp)\n" /* line 3920 */
        "calll Com_Printf\n"
        "movl $0x2a8d00, (%esp)\n" /* line 3921 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf148802_0014882d:\n"
        "addl $0x1c, %esp\n" /* line 3955 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf148802_00148835:\n"
        "movl 0x195ecb4, %eax\n" /* line 3925 */
        "movl (%eax), %eax\n"
        "cmpb $0, 0x4ed(%eax)\n"
        "je .Lf148802_0014882d\n"
        "movl 0x1220a70, %ecx\n" /* line 3928 */
        "testl %ecx, %ecx\n"
        "je .Lf148802_0014882d\n"
        "movl $1, (%esp)\n" /* line 3931 */
        "calll Cmd_Argv\n"
        "movl %eax, %esi\n" /* parentMenuName */
        "movl $2, (%esp)\n" /* line 3932 */
        "calll Cmd_Argv\n"
        "movl %eax, %edi\n" /* menuResponse */
        "testl %esi, %esi\n" /* line 3935 | parentMenuName */
        "je .Lf148802_0014882d\n"
        "testl %eax, %eax\n"
        "je .Lf148802_0014882d\n"
        "xorl %ebx, %ebx\n" /* menuIndex */
        "jmp .Lf148802_0014887f\n"
        ".Lf148802_00148877:\n"
        "addl $1, %ebx\n" /* line 3938 | menuIndex */
        "cmpl $0x20, %ebx\n" /* menuIndex */
        "je .Lf148802_001488de\n"
        ".Lf148802_0014887f:\n"
        "leal 0x4de(%ebx), %eax\n" /* line 3940 | menuIndex */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "cmpb $0, (%eax)\n" /* line 3941 */
        "je .Lf148802_00148877\n"
        "movl %eax, 4(%esp)\n" /* line 3944 */
        "movl %esi, (%esp)\n" /* parentMenuName */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf148802_00148877\n"
        ".Lf148802_001488a2:\n"
        "movl $0x2a8d30, (%esp)\n" /* line 3953 */
        "calll Dvar_GetInt\n"
        "movl %edi, 0xc(%esp)\n" /* menuResponse */
        "movl %ebx, 8(%esp)\n" /* menuIndex */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a8d3c, (%esp)\n" /* "cmd mr %i %i %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3955 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf148802_001488de:\n"
        "movl $0xffffffff, %ebx\n" /* line 3938 | menuIndex */
        "jmp .Lf148802_001488a2\n"
    );
}

/* line 3970 */
__attribute__((naked))
void CL_InitOnceForAllClients(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3970 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "calll Sys_MillisecondsRaw\n" /* line 3972 */
        "movl %eax, (%esp)\n"
        "calll srand\n"
        "calll Con_Init\n" /* line 3974 */
        "calll CL_InitInput\n" /* line 3976 */
        "movl $__mh_execute_header, 8(%esp)\n" /* line 3981 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8d50, (%esp)\n" /* "cl_noprint" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_noprint\n"
        "movl $0x1003, 8(%esp)\n" /* line 3991 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a8d5c, (%esp)\n" /* "cl_voice" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_voice\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 3997 */
        "movl $0x45610000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x43480000, %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2a8d68, (%esp)\n" /* "cl_timeout" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cl_timeout\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 4000 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2a8d74, (%esp)\n" /* "cl_connectTimeout" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cl_connectTimeout\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 4002 */
        "movl $4, 0xc(%esp)\n"
        "movl $0xfffffffe, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a8d88, (%esp)\n" /* "cl_shownet" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cl_shownet\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4003 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8d94, (%esp)\n" /* "cl_shownuments" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_shownuments\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4004 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8da4, (%esp)\n" /* "cl_showServerCommands" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_showServerCommands\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4005 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8dbc, (%esp)\n" /* "cl_showSend" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_showSend\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4006 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8dc8, (%esp)\n" /* "cl_showTimeDelta" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_showTimeDelta\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4007 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8ddc, (%esp)\n" /* "cl_freezeDemo" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_freezeDemo\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4008 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a8dec, (%esp)\n" /* "activeAction" */
        "calll Dvar_RegisterString\n"
        "movl %eax, cl_activeAction\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 4010 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a8dfc, (%esp)\n" /* "cl_avidemo" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cl_avidemo\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4011 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8e08, (%esp)\n" /* "cl_forceavidemo" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_forceavidemo\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4013 */
        "movl $0x7f7fffff, %ebx\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $0xff7fffff, %edi\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x430c0000, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2a8e18, (%esp)\n" /* "cl_yawspeed" */
        "calll Dvar_RegisterFloat\n"
        "movl 0x195f408, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4014 */
        "movl %ebx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2a8e24, (%esp)\n" /* "cl_pitchspeed" */
        "calll Dvar_RegisterFloat\n"
        "movl 0x195f3e8, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 4015 */
        "movl %ebx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3fc00000, 4(%esp)\n"
        "movl $0x2a8e34, (%esp)\n" /* "cl_anglespeedkey" */
        "calll Dvar_RegisterFloat\n"
        "movl 0x195f4e8, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4017 */
        "movl $0x64, 0xc(%esp)\n"
        "movl $0xf, 8(%esp)\n"
        "movl $0x1e, 4(%esp)\n"
        "movl $0x2a8e48, (%esp)\n" /* "cl_maxpackets" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cl_maxpackets\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4018 */
        "movl $5, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0x2a8e58, (%esp)\n" /* "cl_packetdup" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cl_packetdup\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4020 */
        "movl $0x42c80000, 0xc(%esp)\n"
        "movl $0x3c23d70a, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $0x2a8e68, (%esp)\n" /* "sensitivity" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cl_sensitivity\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4021 */
        "movl $0x42c80000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a8e74, (%esp)\n" /* "cl_mouseAccel" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cl_mouseAccel\n"
        "movl $0x1001, 8(%esp)\n" /* line 4022 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a8e84, (%esp)\n" /* "cl_freelook" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_freelook\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4024 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8e90, (%esp)\n" /* "cl_showmouserate" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_showMouseRate\n"
        "movl $0x1001, 8(%esp)\n" /* line 4027 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a8ea4, (%esp)\n" /* "cl_allowDownload" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_allowDownload\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4031 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8eb8, (%esp)\n" /* "cl_talking" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f3f0, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1001, 8(%esp)\n" /* line 4034 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a8ec4, (%esp)\n" /* "r_inGameVideo" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_inGameVideo\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 4036 */
        "movl $0xe10, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x2ee, 4(%esp)\n"
        "movl $0x2a8ed4, (%esp)\n" /* "cl_serverStatusResendTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cl_serverStatusResendTime\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4038 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8ef0, (%esp)\n" /* "cl_bypassMouseInput" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f254, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4040 */
        "movl $0x3f800000, %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "movl $0xbf800000, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3cb43958, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2a8f04, (%esp)\n" /* "m_pitch" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, m_pitch\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4041 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2a8f0c, (%esp)\n" /* "m_yaw" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, m_yaw\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4042 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3e800000, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2a8f14, (%esp)\n" /* "m_forward" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, m_forward\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4043 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2a8f20, (%esp)\n" /* "m_side" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, m_side\n"
        "movl $0x1001, 8(%esp)\n" /* line 4044 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8f28, (%esp)\n" /* "m_filter" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, m_filter\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4049 */
        "movl $0x40a00000, 0xc(%esp)\n"
        "movl $0x38d1b717, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2a8f34, (%esp)\n" /* "input_viewSensitivity" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, input_viewSensitivity\n"
        "movl $0x1001, 8(%esp)\n" /* line 4050 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a8f4c, (%esp)\n" /* "cg_drawCrosshair" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f358, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1040, 8(%esp)\n" /* line 4056 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a8f60, (%esp)\n" /* "cl_motdString" */
        "calll Dvar_RegisterString\n"
        "movl %eax, cl_motdString\n"
        "movl $0x1040, 8(%esp)\n" /* line 4058 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8f70, (%esp)\n" /* "cl_ingame" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cl_ingame\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 4060 */
        "movl $0x7d0, 0xc(%esp)\n"
        "movl $0x14, 8(%esp)\n"
        "movl $0x320, 4(%esp)\n"
        "movl $0x2a8f7c, (%esp)\n" /* "cl_maxPing" */
        "calll Dvar_RegisterInt\n"
        "movl $0x1003, 8(%esp)\n" /* line 4068 */
        "movl $0x2a8f88, 4(%esp)\n" /* "Unknown Soldier" */
        "movl $0x2194b4, (%esp)\n" /* "name" */
        "calll Dvar_RegisterString\n"
        "movl %eax, name\n"
        "movl $0x1003, 0x10(%esp)\n" /* line 4069 */
        "movl $0x61a8, 0xc(%esp)\n"
        "movl $0x3e8, 8(%esp)\n"
        "movl $0x1388, 4(%esp)\n"
        "movl $0x2a8c54, (%esp)\n" /* "rate" */
        "calll Dvar_RegisterInt\n"
        "movl $0x1003, 0x10(%esp)\n" /* line 4072 */
        "movl $0x1e, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x14, 4(%esp)\n"
        "movl $0x2a8f98, (%esp)\n" /* "snaps" */
        "calll Dvar_RegisterInt\n"
        "movl $0x1002, 8(%esp)\n" /* line 4074 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a8fa0, (%esp)\n" /* "password" */
        "calll Dvar_RegisterString\n"
        "movl $0x1080, 8(%esp)\n" /* line 4076 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a8fac, (%esp)\n" /* "fx_enable" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, fx_enable\n"
        "movl $0x1080, 8(%esp)\n" /* line 4077 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a8fb8, (%esp)\n" /* "fx_draw" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, fx_draw\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4078 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a8fc0, (%esp)\n" /* "fx_cull" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, fx_cull\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4079 */
        "movl $1, 4(%esp)\n"
        "movl $0x223858, (%esp)\n" /* "fx_sort" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, fx_sort\n"
        "movl $0x1080, 8(%esp)\n" /* line 4080 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8fc8, (%esp)\n" /* "fx_freeze" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, fx_freeze\n"
        "movl $0x1080, 8(%esp)\n" /* line 4081 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8fd4, (%esp)\n" /* "fx_debug" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, fx_debug\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 4082 */
        "movl $0x42c80000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a8fe0, (%esp)\n" /* "fx_debugBolt" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, fx_debugBolt\n"
        "movl $0x1080, 8(%esp)\n" /* line 4083 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8ff0, (%esp)\n" /* "fx_count" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, fx_count\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 4084 */
        "movl $0x447a0000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x42a00000, 4(%esp)\n"
        "movl $0x2a8ffc, (%esp)\n" /* "fx_visMinTraceDist" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, fx_visMinTraceDist\n"
        "movl $0x1080, 8(%esp)\n" /* line 4085 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a9010, (%esp)\n" /* "fx_profile" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, fx_profile\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 4087 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a901c, (%esp)\n" /* "nextdemo" */
        "calll Dvar_RegisterString\n"
        "movl %eax, nextdemo\n"
        "movl $0x1001, 8(%esp)\n" /* line 4090 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a9028, (%esp)\n" /* "hud_enable" */
        "calll Dvar_RegisterBool\n"
        "movl $0x1001, 8(%esp)\n" /* line 4092 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a892c, (%esp)\n" /* "cg_blood" */
        "calll Dvar_RegisterBool\n"
        "movl $CL_ForwardToServer_f, 4(%esp)\n" /* line 4118 */
        "movl $0x2a9034, (%esp)\n" /* "cmd" */
        "calll Cmd_AddCommand\n"
        "movl $CL_Configstrings_f, 4(%esp)\n" /* line 4119 */
        "movl $0x2a9038, (%esp)\n" /* "configstrings" */
        "calll Cmd_AddCommand\n"
        "movl $CL_Clientinfo_f, 4(%esp)\n" /* line 4120 */
        "movl $0x2a9048, (%esp)\n" /* "clientinfo" */
        "calll Cmd_AddCommand\n"
        "movl $CL_Vid_Restart_f, 4(%esp)\n" /* line 4122 */
        "movl $0x2a9054, (%esp)\n" /* "vid_restart" */
        "calll Cmd_AddCommand\n"
        "movl $CL_Snd_Restart_f, 4(%esp)\n" /* line 4125 */
        "movl $0x2a9060, (%esp)\n" /* "snd_restart" */
        "calll Cmd_AddCommand\n"
        "movl $CL_Disconnect_f, 4(%esp)\n" /* line 4127 */
        "movl $0x228e90, (%esp)\n" /* "disconnect" */
        "calll Cmd_AddCommand\n"
        "movl $CL_Record_f, 4(%esp)\n" /* line 4129 */
        "movl $0x2a906c, (%esp)\n" /* "record" */
        "calll Cmd_AddCommand\n"
        "movl $CL_StopRecord_f, 4(%esp)\n" /* line 4130 */
        "movl $0x2a9074, (%esp)\n" /* "stoprecord" */
        "calll Cmd_AddCommand\n"
        "movl $CL_PlayDemo_f, 4(%esp)\n" /* line 4131 */
        "movl $0x2a9080, (%esp)\n" /* "demo" */
        "calll Cmd_AddCommand\n"
        "movl $CL_PlayDemo_f, 4(%esp)\n" /* line 4132 */
        "movl $0x2a9088, (%esp)\n" /* "timedemo" */
        "calll Cmd_AddCommand\n"
        "movl $0x2a9094, 8(%esp)\n" /* line 4134 */
        "movl $0x2a909c, 4(%esp)\n" /* "demos" */
        "movl $0x2a9080, (%esp)\n" /* "demo" */
        "calll Cmd_SetAutoComplete\n"
        "movl $0x2a9094, 8(%esp)\n" /* line 4135 */
        "movl $0x2a909c, 4(%esp)\n" /* "demos" */
        "movl $0x2a9088, (%esp)\n" /* "timedemo" */
        "calll Cmd_SetAutoComplete\n"
        "movl 0x195f394, %eax\n" /* line 4137 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a90a4, (%esp)\n" /* "cinematic" */
        "calll Cmd_AddCommand\n"
        "movl $0x216ce4, 8(%esp)\n" /* line 4142 */
        "movl $0x2a90b0, 4(%esp)\n" /* "video" */
        "movl $0x2a90a4, (%esp)\n" /* "cinematic" */
        "calll Cmd_SetAutoComplete\n"
        "movl $CL_PlayLogo_f, 4(%esp)\n" /* line 4145 */
        "movl $0x2a90b8, (%esp)\n" /* "logo" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f318, %eax\n" /* line 4146 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a90c0, (%esp)\n" /* "connect" */
        "calll Cmd_AddCommand\n"
        "movl $CL_Reconnect_f, 4(%esp)\n" /* line 4147 */
        "movl $0x2a90c8, (%esp)\n" /* "reconnect" */
        "calll Cmd_AddCommand\n"
        "movl $CL_LocalServers_f, 4(%esp)\n" /* line 4148 */
        "movl $0x2a90d4, (%esp)\n" /* "localservers" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f340, %eax\n" /* line 4150 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a90e4, (%esp)\n" /* "globalservers" */
        "calll Cmd_AddCommand\n"
        "calll CL_RconInit\n" /* line 4153 */
        "movl 0x195f50c, %eax\n" /* line 4154 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a6fbc, (%esp)\n" /* "rcon" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f568, %eax\n" /* line 4157 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a90f4, (%esp)\n" /* "ping" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f3ec, %eax\n" /* line 4158 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a90fc, (%esp)\n" /* "serverstatus" */
        "calll Cmd_AddCommand\n"
        "movl $CL_ToggleMenu_f, 4(%esp)\n" /* line 4161 */
        "movl $0x2a910c, (%esp)\n" /* "toggleMenu" */
        "calll Cmd_AddCommand\n"
        "movl $CL_Setenv_f, 4(%esp)\n" /* line 4162 */
        "movl $0x2a9118, (%esp)\n" /* "setenv" */
        "calll Cmd_AddCommand\n"
        "movl $CL_ShowIP_f, 4(%esp)\n" /* line 4163 */
        "movl $0x2a9120, (%esp)\n" /* "showip" */
        "calll Cmd_AddCommand\n"
        "movl $CL_OpenedIWDList_f, 4(%esp)\n" /* line 4166 */
        "movl $0x2a9128, (%esp)\n" /* "fs_openedList" */
        "calll Cmd_AddCommand\n"
        "movl $CL_ReferencedIWDList_f, 4(%esp)\n" /* line 4167 */
        "movl $0x2a9138, (%esp)\n" /* "fs_referencedList" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f520, %eax\n" /* line 4171 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a914c, (%esp)\n" /* "updatehunkusage" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f4b8, %eax\n" /* line 4173 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a915c, (%esp)\n" /* "updatescreen" */
        "calll Cmd_AddCommand\n"
        "movl $CL_startSingleplayer_f, 4(%esp)\n" /* line 4175 */
        "movl $0x2a916c, (%esp)\n" /* "startSingleplayer" */
        "calll Cmd_AddCommand\n"
        "movl $CL_SetRecommended_f, 4(%esp)\n" /* line 4178 */
        "movl $0x2a9180, (%esp)\n" /* "setRecommended" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f4a0, %eax\n" /* line 4187 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a9190, (%esp)\n" /* "cubemapShot" */
        "calll Cmd_AddCommand\n"
        "movl $CL_OpenScriptMenu_f, 4(%esp)\n" /* line 4191 */
        "movl $0x2a919c, (%esp)\n" /* "openScriptMenu" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f3c8, %eax\n" /* line 4195 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a91ac, (%esp)\n" /* "localizeSoundAliasFiles" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f3f4, %eax\n" /* line 4198 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a91c4, (%esp)\n" /* "openmenu" */
        "calll Cmd_AddCommand\n"
        "movl 0x195f378, %eax\n" /* line 4199 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a91d0, (%esp)\n" /* "closemenu" */
        "calll Cmd_AddCommand\n"
        "calll CL_InitRef\n" /* line 4215 */
        "addl $0x2c, %esp\n" /* line 4218 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp SCR_Init\n" /* line 4217 */
    );
}

/* line 4937 */
__attribute__((naked))
void CL_ShutdownDebugData(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4937 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "subl $0x14, %esp\n"
        "movl 0x14c1408, %eax\n" /* line 4939 */
        "testl %eax, %eax\n"
        "je .Lf149428_0014944a\n"
        "movl %eax, (%esp)\n" /* line 4941 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x14c1408\n" /* line 4942 */
        ".Lf149428_0014944a:\n"
        "movl 0x14c140c, %eax\n" /* line 4944 */
        "testl %eax, %eax\n"
        "je .Lf149428_00149465\n"
        "movl %eax, (%esp)\n" /* line 4946 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x14c140c\n" /* line 4947 */
        ".Lf149428_00149465:\n"
        "movl 0x14c1410, %eax\n" /* line 4949 */
        "testl %eax, %eax\n"
        "je .Lf149428_00149480\n"
        "movl %eax, (%esp)\n" /* line 4951 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x14c1410\n" /* line 4952 */
        ".Lf149428_00149480:\n"
        "movl 0x14c13f8, %eax\n" /* line 4954 */
        "testl %eax, %eax\n"
        "je .Lf149428_0014949b\n"
        "movl %eax, (%esp)\n" /* line 4956 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x14c13f8\n" /* line 4957 */
        ".Lf149428_0014949b:\n"
        "movl 0x14c13fc, %eax\n" /* line 4959 */
        "testl %eax, %eax\n"
        "je .Lf149428_001494b6\n"
        "movl %eax, (%esp)\n" /* line 4961 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x14c13fc\n" /* line 4962 */
        ".Lf149428_001494b6:\n"
        "movl $0x14c13f0, %edi\n" /* line 4965 */
        "cld\n"
        "movl $9, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl 0x121c7a8, %ecx\n" /* line 4967 */
        "testl %ecx, %ecx\n"
        "je .Lf149428_001494d6\n"
        "addl $0x14, %esp\n" /* line 4969 */
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 4968 */
        ".Lf149428_001494d6:\n"
        "addl $0x14, %esp\n" /* line 4969 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4449 */
__attribute__((naked))
void CL_GetPing(int n, char *buf, int buflen, int *pingtime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4449 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edx\n" /* n */
        "movl 0xc(%ebp), %ebx\n" /* buf */
        /* { scope 1 */
        "movl %edx, %eax\n" /* line 4457 */
        "shll $6, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (, %eax, 4), %esi\n"
        "cmpw $0, 0x121c808(%esi)\n"
        "jne .Lf1494dc_0014951a\n"
        "movb $0, (%ebx)\n" /* line 4460 | buf */
        "movl 0x14(%ebp), %eax\n" /* line 4461 | pingtime */
        "movl $0, (%eax)\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 4490 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1494dc_0014951a:\n"
        "movl cl_pinglist(%esi), %ecx\n" /* line 4466 */
        "movl %ecx, -0x30(%ebp)\n"
        "movl 0x121c804(%esi), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x121c808(%esi), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl 0x10(%ebp), %edx\n" /* line 4467 | buflen */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* buf */
        "calll I_strncpyz\n"
        "movl 0x121c810(%esi), %edi\n" /* line 4470 | time */
        "testl %edi, %edi\n" /* line 4471 | time */
        "je .Lf1494dc_001495aa\n"
        "movl %edi, %eax\n" /* time */
        ".Lf1494dc_00149564:\n"
        "movl cl_pinglist(%esi), %ebx\n" /* line 4487 | buf */
        "movl %ebx, -0x24(%ebp)\n" /* buf */
        "movl 0x121c804(%esi), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl 0x121c808(%esi), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "leal 0x121c814(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, (%esp)\n" /* buf */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "calll CL_SetServerInfoByAddress\n"
        "movl 0x14(%ebp), %eax\n" /* line 4489 | pingtime */
        "movl %edi, (%eax)\n" /* time */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 4490 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1494dc_001495aa:\n"
        "calll Sys_Milliseconds\n" /* line 4474 */
        "movl %eax, %edi\n" /* time */
        "subl 0x121c80c(%esi), %edi\n" /* time */
        "movl $0x2a8f7c, (%esp)\n" /* line 4475 */
        "calll Dvar_GetInt\n"
        "cmpl $0x63, %eax\n" /* line 4476 */
        "movl $0x64, %edx\n"
        "cmovlel %edx, %eax\n"
        "cmpl %edi, %eax\n" /* line 4480 | time */
        "movl $0, %eax\n"
        "cmovgl %eax, %edi\n" /* time */
        "movl 0x121c810(%esi), %eax\n"
        "jmp .Lf1494dc_00149564\n"
    );
}

/* line 4704 */
void CL_ShowIP_f(void)
{
    Sys_ShowIP();
}

/* line 4715 */
__attribute__((naked))
const char * CL_GetServerIPAddress(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4715 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "cmpl $4, clientConnections\n" /* line 4719 */
        "jg .Lf1495ea_0014961c\n"
        "movl $0x80, 8(%esp)\n" /* line 4721 */
        "movl $0, 4(%esp)\n"
        "movl $szServerIPAddress, (%esp)\n"
        "calll memset\n"
        /* } scope */
        "movl $szServerIPAddress, %eax\n" /* line 4728 */
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1495ea_0014961c:\n"
        "movzwl 0x14c143c, %eax\n" /* line 4722 */
        "rolw $8, %ax\n" /* line 925 */
        "cwtl\n" /* line 4725 */
        "movl %eax, 0x1c(%esp)\n"
        "movzbl 0x14c143b, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movzbl 0x14c143a, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl 0x14c1439, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl 0x14c1438, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2a91dc, 8(%esp)\n" /* "%i.%i.%i.%i:%i" */
        "movl $0x80, 4(%esp)\n"
        "movl $szServerIPAddress, (%esp)\n"
        "calll Com_sprintf\n"
        /* } scope */
        "movl $szServerIPAddress, %eax\n" /* line 4728 */
        "leave\n"
        "retl\n"
    );
}

/* line 4844 */
__attribute__((naked))
void CL_FlushDebugData(qboolean fromServer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4844 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* fromServer */
        /* { scope 1 */
        "movl 0x1220a68, %eax\n" /* line 4848 */
        "testl %eax, %eax\n"
        "je .Lf14967c_00149722\n"
        "movl 0x14c13f8, %eax\n" /* line 4852 */
        "testl %eax, %eax\n"
        "je .Lf14967c_001496de\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl 0x14c13f4, %ecx\n"
        ".Lf14967c_001496a6:\n"
        "cmpl %ecx, %ebx\n" /* line 4858 | i */
        "jge .Lf14967c_001496c3\n"
        ".Lf14967c_001496aa:\n"
        "movl 0x14c13fc, %edx\n" /* line 4860 */
        "movzbl (%edx, %ebx), %eax\n"
        "cmpl %eax, %edi\n" /* fromServer */
        "je .Lf14967c_00149753\n"
        "addl $1, %ebx\n" /* line 4868 | i */
        "cmpl %ecx, %ebx\n" /* line 4858 | i */
        "jl .Lf14967c_001496aa\n"
        ".Lf14967c_001496c3:\n"
        "movl 0x14c13f0, %eax\n" /* line 4872 */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl 0x14c13f8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x121c79c\n"
        ".Lf14967c_001496de:\n"
        "movl 0x14c1408, %eax\n" /* line 4876 */
        "testl %eax, %eax\n"
        "je .Lf14967c_00149722\n"
        "xorl %esi, %esi\n"
        "movl 0x14c1404, %ecx\n"
        ".Lf14967c_001496ef:\n"
        "cmpl %ecx, %esi\n" /* line 4882 */
        "jge .Lf14967c_00149707\n"
        ".Lf14967c_001496f3:\n"
        "movl 0x14c140c, %eax\n" /* line 4884 */
        "movzbl (%eax, %esi), %eax\n"
        "cmpl %edi, %eax\n" /* fromServer */
        "je .Lf14967c_0014972a\n"
        "addl $1, %esi\n" /* line 4896 */
        ".Lf14967c_00149703:\n"
        "cmpl %ecx, %esi\n" /* line 4882 */
        "jl .Lf14967c_001496f3\n"
        ".Lf14967c_00149707:\n"
        "movl 0x14c1400, %eax\n" /* line 4899 */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl 0x14c1408, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x121c7a0\n"
        /* } scope */
        ".Lf14967c_00149722:\n"
        "addl $0x1c, %esp\n" /* line 4901 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14967c_0014972a:\n"
        "leal (, %esi, 4), %ebx\n" /* line 4886 | i */
        "movl %ebx, %eax\n" /* i */
        "addl 0x14c1410, %eax\n"
        "subl $1, (%eax)\n"
        "movl 0x14c1410, %eax\n" /* line 4887 */
        "movl (%ebx, %eax), %eax\n" /* i */
        "testl %eax, %eax\n"
        "jle .Lf14967c_00149799\n"
        "movl 0x14c1404, %ecx\n"
        "addl $1, %esi\n" /* line 4896 */
        "jmp .Lf14967c_00149703\n"
        ".Lf14967c_00149753:\n"
        "subl $1, %ecx\n" /* line 4862 */
        "movl %ecx, 0x14c13f4\n"
        "movzbl (%edx, %ecx), %eax\n" /* line 4863 */
        "movb %al, (%ebx, %edx)\n" /* i */
        "movl 0x14c13f8, %ecx\n" /* line 4864 */
        "movl %ebx, %edx\n" /* i */
        "shll $7, %edx\n"
        "movl 0x14c13f4, %eax\n"
        "shll $7, %eax\n"
        "addl %ecx, %edx\n"
        "addl %ecx, %eax\n"
        "movl $0x80, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x14c13f4, %ecx\n"
        "jmp .Lf14967c_001496a6\n"
        ".Lf14967c_00149799:\n"
        "movl 0x14c1404, %ecx\n" /* line 4889 */
        "subl $1, %ecx\n"
        "movl %ecx, 0x14c1404\n"
        "movl 0x14c140c, %edx\n" /* line 4890 */
        "movzbl (%edx, %ecx), %eax\n"
        "movb %al, (%esi, %edx)\n"
        "movl 0x14c1410, %edx\n" /* line 4891 */
        "movl 0x14c1404, %eax\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, (%ebx, %edx)\n" /* i */
        "movl 0x14c1408, %edx\n" /* line 4892 */
        "addl %esi, %ebx\n" /* i */
        "leal (%esi, %ebx, 2), %ebx\n" /* i */
        "shll $2, %ebx\n" /* i */
        "movl 0x14c1404, %eax\n"
        "leal (%eax, %eax, 4), %ecx\n"
        "leal (%eax, %ecx, 2), %ecx\n"
        "shll $2, %ecx\n"
        "movl (%ecx, %edx), %eax\n"
        "movl %eax, (%ebx, %edx)\n" /* i */
        "movl 4(%ecx, %edx), %eax\n"
        "movl %eax, 4(%ebx, %edx)\n" /* i */
        "movl 8(%ecx, %edx), %eax\n"
        "movl %eax, 8(%ebx, %edx)\n" /* i */
        "movl 0xc(%ecx, %edx), %eax\n"
        "movl %eax, 0xc(%ebx, %edx)\n" /* i */
        "movl 0x10(%ecx, %edx), %eax\n"
        "movl %eax, 0x10(%ebx, %edx)\n" /* i */
        "movl 0x14(%ecx, %edx), %eax\n"
        "movl %eax, 0x14(%ebx, %edx)\n" /* i */
        "movl 0x18(%ecx, %edx), %eax\n"
        "movl %eax, 0x18(%ebx, %edx)\n" /* i */
        "movl 0x1c(%ecx, %edx), %eax\n"
        "movl %eax, 0x1c(%ebx, %edx)\n" /* i */
        "movl 0x20(%ecx, %edx), %eax\n"
        "movl %eax, 0x20(%ebx, %edx)\n" /* i */
        "movl 0x24(%ecx, %edx), %eax\n"
        "movl %eax, 0x24(%ebx, %edx)\n" /* i */
        "movl 0x28(%ecx, %edx), %eax\n"
        "movl %eax, 0x28(%ebx, %edx)\n" /* i */
        "movl 0x14c1404, %ecx\n"
        "jmp .Lf14967c_001496ef\n"
    );
}

/* line 4909 */
__attribute__((naked))
void CL_UpdateDebugData(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4909 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x1220a68, %eax\n" /* line 4911 */
        "testl %eax, %eax\n"
        "je .Lf149844_0014989d\n"
        "movl 0x14c13f8, %edx\n" /* line 4914 */
        "testl %edx, %edx\n"
        "je .Lf149844_00149878\n"
        "movl 0x14c13f0, %eax\n" /* line 4919 */
        "movl %eax, 8(%esp)\n"
        "movl 0x14c13f4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x121c79c\n"
        ".Lf149844_00149878:\n"
        "movl 0x14c1408, %edx\n" /* line 4922 */
        "testl %edx, %edx\n"
        "je .Lf149844_0014989d\n"
        "movl 0x14c1400, %eax\n" /* line 4927 */
        "movl %eax, 8(%esp)\n"
        "movl 0x14c1404, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x121c7a0\n"
        ".Lf149844_0014989d:\n"
        "leave\n" /* line 4929 */
        "retl\n"
    );
}

/* line 4991 */
int CL_TextWidth(const char *text, int maxChars, FontHandle font)
{
    return ((int (*)(const char *, int, FontHandle))*(int *)0x121c7b4)(text, maxChars, font);
}

/* line 5002 */
int CL_TextHeight(FontHandle font)
{
    return ((int (*)(FontHandle))*(int *)0x121c7b8)(font);
}

/* line 5013 */
float CL_NormalizedTextScale(FontHandle font, float scale)
{
    return ((float (*)(FontHandle, float))*(int *)0x121c7b0)(font, scale);
}

/* line 5019 */
void CL_DrawTextPhysical(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style)
{
    ((void (*)(const char *, int, FontHandle, float, float, float, float, const vec_t *, int))*(int *)0x121c7bc)(text, maxChars, font, x, y, xScale, yScale, color, style);
}

/* line 5025 */
__attribute__((naked))
void CL_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec_t *color, int style)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5025 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* font */
        "leal 0x18(%ebp), %ebx\n" /* line 5027 | y */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* font */
        "calll CalcSplitScreenTextOffset\n"
        "movl 0x20(%ebp), %eax\n" /* line 5028 | vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x28(%ebp), %eax\n" /* yScale */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x24(%ebp), %eax\n" /* xScale */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x14(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movl 0x30(%ebp), %eax\n" /* line 5029 | style */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x2c(%ebp), %eax\n" /* color */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* yScale */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* xScale */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* y */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* x */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* font */
        "movl 0xc(%ebp), %eax\n" /* maxChars */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll *0x121c7bc\n"
        "addl $0x30, %esp\n" /* line 5030 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5033 */
void CL_DrawTextPhysicalWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor)
{
    cursor = (signed char)cursor;
    ((void (*)(const char *, int, FontHandle, float, float, float, float, const vec_t *, int, int, int))*(int *)0x121c7cc)(text, maxChars, font, x, y, xScale, yScale, color, style, cursorPos, cursor);
}

/* line 5039 */
__attribute__((naked))
void CL_DrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5039 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* font */
        "movsbl 0x38(%ebp), %ebx\n" /* cursor */
        "leal 0x18(%ebp), %esi\n" /* line 5041 | y */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* font */
        "calll CalcSplitScreenTextOffset\n"
        "movl 0x20(%ebp), %eax\n" /* line 5042 | vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x28(%ebp), %eax\n" /* yScale */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x24(%ebp), %eax\n" /* xScale */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal 0x14(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movl %ebx, 0x28(%esp)\n" /* line 5043 | cursor */
        "movl 0x34(%ebp), %eax\n" /* cursorPos */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x30(%ebp), %eax\n" /* style */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x2c(%ebp), %eax\n" /* color */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* yScale */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* xScale */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* y */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* x */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* font */
        "movl 0xc(%ebp), %eax\n" /* maxChars */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll *0x121c7cc\n"
        "addl $0x3c, %esp\n" /* line 5044 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5052 */
int CL_GetKeyCatchers(void)
{
    return *(int *)0x1509c44;
}

/* line 5062 */
Bool CL_GetDisplayHUDWithKeycatchUI(void)
{
    return *(byte *)0x1509c48;
}

/* line 5072 */
FontHandle CL_RegisterFont(const char *fontName, int imageTrack)
{
    return ((FontHandle (*)(const char *, int))*(int *)0x121c780)(fontName, imageTrack);
}

/* line 676 */
__attribute__((naked))
void CL_WriteDemoMessage(msg_t *msg, int headerBytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 676 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* headerBytes */
        /* { scope 1 */
        "movl 0x14e1558, %eax\n" /* line 682 */
        "movl %eax, -0x1c(%ebp)\n" /* swlen */
        "movl 0x1501bd0, %eax\n" /* line 683 */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* swlen */
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "movl 8(%ebp), %eax\n" /* line 686 | msg */
        "movl 0xc(%eax), %ebx\n"
        "subl %edi, %ebx\n" /* headerBytes */
        "movl %ebx, -0x1c(%ebp)\n" /* line 687 | swlen */
        "movl clc, %esi\n" /* line 688 */
        "movl 0x407b0(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* swlen */
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "movl 0x407b0(%esi), %eax\n" /* line 689 */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "addl 4(%eax), %edi\n" /* headerBytes */
        "movl %edi, (%esp)\n" /* headerBytes */
        "calll FS_Write\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 690 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 730 */
__attribute__((naked))
void CL_Record_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 730 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x828c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 744 */
        "cmpl $2, %eax\n"
        "jg .Lf149ab4_00149b0c\n"
        "movl clc, %eax\n" /* line 750 */
        "movl 0x4079c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf149ab4_00149af5\n"
        "cmpl $8, (%eax)\n" /* line 756 */
        "je .Lf149ab4_00149b23\n"
        "movl $0x2a9214, (%esp)\n" /* line 758 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf149ab4_00149aea:\n"
        "addl $0x828c, %esp\n" /* line 870 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf149ab4_00149af5:\n"
        "movl $0x2a9200, (%esp)\n" /* line 752 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x828c, %esp\n" /* line 870 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf149ab4_00149b0c:\n"
        "movl $0x2a91ec, (%esp)\n" /* line 746 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x828c, %esp\n" /* line 870 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf149ab4_00149b23:\n"
        "calll Cmd_Argc\n" /* line 762 */
        "cmpl $2, %eax\n"
        "je .Lf149ab4_00149e1c\n"
        "xorl %ebx, %ebx\n" /* line 766 */
        "leal -0x74(%ebp), %edi\n" /* demoName */
        "leal -0x264(%ebp), %esi\n" /* name, i */
        "jmp .Lf149ab4_00149b49\n"
        /* { scope 2 */
        ".Lf149ab4_00149b3e:\n"
        "addl $1, %ebx\n" /* line 774 | number */
        "cmpl $0x2710, %ebx\n" /* number */
        "je .Lf149ab4_00149b95\n"
        ".Lf149ab4_00149b49:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 776 | number */
        "movl $0x2a9248, 8(%esp)\n" /* "demo%04i" */
        "movl $0x40, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $1, 0x10(%esp)\n" /* line 777 */
        "movl %edi, 0xc(%esp)\n"
        "movl $0x2a9238, 8(%esp)\n" /* "demos/%s.dm_%d" */
        "movl $0x100, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll Com_sprintf\n"
        "movl %esi, (%esp)\n" /* line 778 | i */
        "calll FS_FileExists\n"
        "testl %eax, %eax\n"
        "jne .Lf149ab4_00149b3e\n"
        /* } scope */
        ".Lf149ab4_00149b95:\n"
        "movl %esi, 4(%esp)\n" /* line 797 | i */
        "movl $0x2a9254, (%esp)\n" /* "recording to %s.
" */
        "calll Com_Printf\n"
        "movl clc, %ebx\n" /* line 798 | number */
        "movl %esi, (%esp)\n" /* i */
        "calll FS_FOpenFileWrite\n"
        "movl %eax, 0x407b0(%ebx)\n" /* number */
        "testl %eax, %eax\n" /* line 799 */
        "jne .Lf149ab4_00149bce\n"
        "movl $0x2a9268, (%esp)\n" /* line 801 */
        "calll Com_Printf\n"
        "jmp .Lf149ab4_00149aea\n"
        ".Lf149ab4_00149bce:\n"
        "movl $1, 0x4079c(%ebx)\n" /* line 804 | number */
        "movl $0x40, 8(%esp)\n" /* line 805 */
        "movl %edi, 4(%esp)\n"
        "leal 0x4075c(%ebx), %eax\n" /* number */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $1, 0x407a8(%ebx)\n" /* line 808 | number */
        "movl $0x4000, 8(%esp)\n" /* line 811 */
        "leal -0x4264(%ebp), %eax\n" /* bufData */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_Init\n"
        "movl 0x130(%ebx), %eax\n" /* line 814 | number */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl $1, 4(%esp)\n" /* line 816 */
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 0x2013c(%ebx), %eax\n" /* line 817 | number */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "xorl %esi, %esi\n" /* i */
        "movl cl, %edi\n"
        "jmp .Lf149ab4_00149c6b\n"
        ".Lf149ab4_00149c60:\n"
        "addl $1, %esi\n" /* line 820 | i */
        "cmpl $0x800, %esi\n" /* i */
        "je .Lf149ab4_00149cb0\n"
        ".Lf149ab4_00149c6b:\n"
        "movl 0x270c(%edi, %esi, 4), %ebx\n" /* line 822 | number */
        "testl %ebx, %ebx\n" /* number */
        "je .Lf149ab4_00149c60\n"
        "movl $2, 4(%esp)\n" /* line 827 */
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl %esi, 4(%esp)\n" /* line 828 | i */
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteShort\n"
        "leal 0x470c(%edi, %ebx), %eax\n" /* line 829 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBigString\n"
        "jmp .Lf149ab4_00149c60\n"
        ".Lf149ab4_00149cb0:\n"
        "leal -0x164(%ebp), %edi\n" /* line 833 | nullstate */
        "movl $0xf0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memset\n"
        "xorw %si, %si\n" /* i */
        "movl cl, %ebx\n" /* number */
        "addl $0x970e0, %ebx\n" /* number */
        "jmp .Lf149ab4_00149cf0\n"
        ".Lf149ab4_00149cdf:\n"
        "addl $1, %esi\n" /* line 834 | i */
        "addl $0xf0, %ebx\n" /* number */
        "cmpl $0x400, %esi\n" /* i */
        "je .Lf149ab4_00149d26\n"
        ".Lf149ab4_00149cf0:\n"
        "movl (%ebx), %eax\n" /* line 837 | number */
        "testl %eax, %eax\n"
        "je .Lf149ab4_00149cdf\n"
        "movl $3, 4(%esp)\n" /* line 841 */
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl $1, 0xc(%esp)\n" /* line 842 */
        "movl %ebx, 8(%esp)\n" /* number */
        "movl %edi, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaEntity\n"
        "jmp .Lf149ab4_00149cdf\n"
        ".Lf149ab4_00149d26:\n"
        "movl $7, 4(%esp)\n" /* line 845 */
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl clc, %esi\n" /* line 850 | i */
        "movl 8(%esi), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl 0x12c(%esi), %eax\n" /* line 852 | i */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl $7, 4(%esp)\n" /* line 855 */
        "leal -0x34(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "leal -0x8264(%ebp), %edi\n" /* line 858 | compressedBuf */
        "movl -0x30(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, -0x8264(%ebp)\n" /* compressedBuf */
        "movl -0x28(%ebp), %eax\n" /* line 859 */
        "subl $4, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x8260(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "addl $4, %edx\n"
        "movl %edx, (%esp)\n"
        "calll MSG_WriteBitsCompress\n"
        "addl $4, %eax\n"
        "movl %eax, -0x826c(%ebp)\n" /* compressedSize */
        "movl 0x20138(%esi), %eax\n" /* line 862 | i */
        "movl %eax, -0x1c(%ebp)\n" /* len */
        "movl 0x407b0(%esi), %eax\n" /* line 863 | i */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %ebx\n" /* len, number */
        "movl %ebx, (%esp)\n" /* number */
        "calll FS_Write\n"
        "movl -0x826c(%ebp), %eax\n" /* line 865 | compressedSize */
        "movl %eax, -0x1c(%ebp)\n" /* len */
        "movl 0x407b0(%esi), %eax\n" /* line 866 | i */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* number */
        "calll FS_Write\n"
        "movl 0x407b0(%esi), %eax\n" /* line 867 | i */
        "movl %eax, 8(%esp)\n"
        "movl -0x826c(%ebp), %eax\n" /* compressedSize */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FS_Write\n"
        "jmp .Lf149ab4_00149aea\n"
        ".Lf149ab4_00149e1c:\n"
        "movl $1, (%esp)\n" /* line 764 */
        "calll Cmd_Argv\n"
        "movl $0x40, 8(%esp)\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "leal -0x74(%ebp), %edi\n" /* demoName */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $1, 0x10(%esp)\n" /* line 766 */
        "movl %edi, 0xc(%esp)\n"
        "movl $0x2a9238, 8(%esp)\n" /* "demos/%s.dm_%d" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x264(%ebp), %esi\n" /* name, i */
        "movl %esi, (%esp)\n" /* i */
        "calll Com_sprintf\n"
        "jmp .Lf149ab4_00149b95\n"
    );
}

/* line 1100 */
void CL_ShutdownHunkUsers(void)
{
    if (!*(int *)0x1220964)
        return;
    CL_ShutdownCGame();
    CL_ShutdownUI();
    *(int *)0x14c13b8 = 0;
    *(int *)0x14c13bc = 0;
    *(int *)0x14c13c0 = 0;
    *(int *)0x1220964 = 0;
}

/* line 2705 */
__attribute__((naked))
void CL_InitLoad(const char *mapname, const char *gametype)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2705 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* mapname */
        "movl 0xc(%ebp), %ebx\n" /* gametype */
        "movl 0x195ecb4, %eax\n" /* line 2707 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf149eb4_00149ed7\n"
        "addl $0x10, %esp\n" /* line 2719 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf149eb4_00149ed7:\n"
        "movl $0, 4(%esp)\n" /* line 2711 */
        "movl 0x195f2fc, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl %ebx, 4(%esp)\n" /* line 2714 | gametype */
        "movl %esi, (%esp)\n" /* mapname */
        "calll UI_SetMap\n"
        "movl clc, %edx\n" /* line 2717 */
        "xorl %eax, %eax\n"
        "cmpl $5, (%edx)\n"
        "setge %al\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl %eax, (%edx)\n"
        "addl $0x10, %esp\n" /* line 2719 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp SCR_UpdateScreenInternal\n" /* line 2718 */
    );
}

/* line 3781 */
__attribute__((naked))
void CL_DrawLogo(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3781 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x70, %esp\n"
        /* { scope 1 */
        "movl 0x1220a78, %esi\n" /* line 3791 | time */
        "subl 0x1220a80, %esi\n" /* time */
        "movl 0x1220a88, %eax\n" /* line 3792 */
        "cmpl %eax, %esi\n" /* time */
        "jge .Lf149f18_0014a074\n"
        "cvtsi2ssl %esi, %xmm1\n" /* line 3793 | time */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 3798 | 0.0f */
        "jb .Lf149f18_0014a0a3\n"
        ".Lf149f18_00149f52:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 3800 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf149f18_00149f61:\n"
        "movss %xmm1, -0x18(%ebp)\n" /* line 3802 | color */
        "movss %xmm1, -0x14(%ebp)\n" /* line 3803 */
        "movss %xmm1, -0x10(%ebp)\n" /* line 3804 */
        "movl $0x3f800000, -0xc(%ebp)\n" /* line 3805 */
        "cvtsi2ssl 0x14c13c4, %xmm0\n" /* line 3807 */
        "movss %xmm0, -0x1c(%ebp)\n" /* w */
        "cvtsi2ssl 0x14c13c8, %xmm0\n" /* line 3808 */
        "movaps %xmm0, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "divss 0x2ed720, %xmm1\n" /* 3.0f */
        "movl 0x1220a90, %eax\n" /* line 3811 */
        "movl %eax, 0x24(%esp)\n"
        "leal -0x18(%ebp), %ebx\n" /* color */
        "movl %ebx, 0x20(%esp)\n"
        "movl $0x3f800000, 0x1c(%esp)\n"
        "movl $0x3f800000, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0x1c(%ebp), %xmm2\n" /* w */
        "movss %xmm2, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll *0x121c734\n"
        "movl 0x1220a94, %eax\n" /* line 3812 */
        "movl %eax, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl $0x3f800000, 0x1c(%esp)\n"
        "movl $0x3f800000, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "movss -0x48(%ebp), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* w */
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll *0x121c734\n"
        "cmpl 0x1220a84, %esi\n" /* line 3814 | time */
        "jle .Lf149f18_0014a06d\n"
        "movl clc, %eax\n" /* line 3826 */
        "movl $0, (%eax)\n"
        /* } scope */
        ".Lf149f18_0014a06d:\n"
        "addl $0x70, %esp\n" /* line 3816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf149f18_0014a074:\n"
        "movl 0x1220a84, %edx\n" /* line 3794 */
        "movl 0x1220a8c, %ecx\n"
        "movl %edx, %eax\n"
        "subl %ecx, %eax\n"
        "cmpl %eax, %esi\n" /* time */
        "jle .Lf149f18_0014a0b2\n"
        "subl %esi, %edx\n" /* line 3795 | time */
        "cvtsi2ssl %edx, %xmm1\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 3798 | 0.0f */
        "jae .Lf149f18_00149f52\n"
        ".Lf149f18_0014a0a3:\n"
        "jp .Lf149f18_00149f52\n"
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf149f18_00149f61\n"
        ".Lf149f18_0014a0b2:\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 3794 | 1.0f */
        "jmp .Lf149f18_00149f61\n"
    );
}

/* line 3873 */
__attribute__((naked))
void CL_StopLogoOrCinematic(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3873 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpl $1, clientConnections\n" /* line 3880 */
        "je .Lf14a0c0_0014a10c\n"
        "movl $0, clientConnections\n" /* line 3826 */
        ".Lf14a0c0_0014a0d9:\n"
        "movl $0, (%esp)\n" /* line 3885 */
        "calll SND_StopSounds\n"
        "movl clc, %eax\n" /* line 3886 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf14a0c0_0014a0fe\n"
        "movl $1, (%esp)\n" /* line 3887 */
        "calll UI_SetActiveMenu\n"
        "leave\n" /* line 3890 */
        "retl\n"
        ".Lf14a0c0_0014a0fe:\n"
        "movl $0, (%esp)\n" /* line 3889 */
        "calll UI_SetActiveMenu\n"
        "leave\n" /* line 3890 */
        "retl\n"
        ".Lf14a0c0_0014a10c:\n"
        "calll SCR_StopCinematic\n" /* line 3881 */
        "jmp .Lf14a0c0_0014a0d9\n"
    );
}

/* line 4804 */
__attribute__((naked))
void CL_AddDebugLine(const vec_t *start, const vec_t *end, const vec_t *color, qboolean depthTest, int duration, qboolean fromServer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4804 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* start */
        "movl 0xc(%ebp), %edi\n" /* end */
        "movl 0x10(%ebp), %esi\n" /* color */
        /* { scope 1 */
        "movl 0x1220a68, %eax\n" /* line 4809 */
        "testl %eax, %eax\n"
        "je .Lf14a114_0014a1da\n"
        "movl $__mh_execute_header, 0x14c1400\n" /* line 4812 */
        "movl 0x14c1404, %ecx\n" /* line 4813 */
        "leal 1(%ecx), %eax\n"
        "cmpl $__mh_execute_header, %eax\n"
        "jg .Lf14a114_0014a1da\n"
        "movl 0x14c1408, %eax\n" /* line 4817 */
        "testl %eax, %eax\n"
        "je .Lf14a114_0014a1e2\n"
        ".Lf14a114_0014a15e:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 4826 */
        "leal (%ecx, %edx, 2), %edx\n"
        "movl 0x14c1408, %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0xc(%edx), %ecx\n" /* line 4828 | to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edi), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x18(%edx), %ecx\n" /* line 4829 | to */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 456 */
        "movl %eax, 0x18(%edx)\n"
        "movl 4(%esi), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%esi), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%esi), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 4830 | depthTest */
        "movl %eax, 0x28(%edx)\n"
        "movl 0x14c140c, %edx\n" /* line 4832 */
        "movl 0x14c1404, %eax\n"
        "movzbl 0x1c(%ebp), %ecx\n" /* fromServer */
        "movb %cl, (%edx, %eax)\n"
        "movl 0x14c1404, %edx\n" /* line 4833 */
        "movl 0x14c1410, %eax\n"
        "movl 0x18(%ebp), %ecx\n" /* duration */
        "movl %ecx, (%eax, %edx, 4)\n"
        "addl $1, 0x14c1404\n" /* line 4835 */
        /* } scope */
        ".Lf14a114_0014a1da:\n"
        "addl $0x1c, %esp\n" /* line 4836 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14a114_0014a1e2:\n"
        "movl $0x2c000, (%esp)\n" /* line 4819 */
        "calll Z_MallocInternal\n"
        "movl %eax, 0x14c1408\n"
        "movl 0x14c1400, %eax\n" /* line 4820 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 0x14c140c\n"
        "movl 0x14c1400, %eax\n" /* line 4821 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 0x14c1410\n"
        "xorl %ecx, %ecx\n" /* line 4822 */
        "movl $0, 0x14c1404\n"
        "jmp .Lf14a114_0014a15e\n"
    );
}

/* line 4765 */
__attribute__((naked))
void CL_AddDebugString(const vec_t *xyz, const vec_t *color, float scale, const char *text, qboolean fromServer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4765 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* xyz */
        "movl 0xc(%ebp), %edi\n" /* color */
        /* { scope 1 */
        "movl 0x1220a68, %eax\n" /* line 4770 */
        "testl %eax, %eax\n"
        "je .Lf14a22c_0014a2e1\n"
        "movl $0x100, 0x14c13f0\n" /* line 4773 */
        "movl 0x14c13f4, %edx\n" /* line 4774 */
        "leal 1(%edx), %eax\n"
        "cmpl $0x100, %eax\n"
        "jg .Lf14a22c_0014a2e1\n"
        "movl 0x14c13f8, %eax\n" /* line 4778 */
        "testl %eax, %eax\n"
        "je .Lf14a22c_0014a2e9\n"
        ".Lf14a22c_0014a26b:\n"
        "movl %edx, %ebx\n" /* line 4786 | string */
        "shll $7, %ebx\n" /* string */
        "addl 0x14c13f8, %ebx\n" /* string */
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        "leal 0xc(%ebx), %edx\n" /* line 4788 | string, to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 456 */
        "movl %eax, 0xc(%ebx)\n"
        "movl 4(%edi), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%edi), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movss 0x10(%ebp), %xmm0\n" /* line 4789 | scale */
        "movss %xmm0, 0x1c(%ebx)\n" /* string */
        "movl $0x5f, 8(%esp)\n" /* line 4790 */
        "movl 0x14(%ebp), %eax\n" /* text */
        "movl %eax, 4(%esp)\n"
        "leal 0x20(%ebx), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "movb $0, 0x7f(%ebx)\n" /* line 4791 | string */
        "movl 0x14c13fc, %edx\n" /* line 4793 */
        "movl 0x14c13f4, %eax\n"
        "movzbl 0x18(%ebp), %ecx\n" /* fromServer */
        "movb %cl, (%edx, %eax)\n"
        "addl $1, 0x14c13f4\n" /* line 4795 */
        /* } scope */
        ".Lf14a22c_0014a2e1:\n"
        "addl $0x1c, %esp\n" /* line 4796 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14a22c_0014a2e9:\n"
        "movl $0x8000, (%esp)\n" /* line 4780 */
        "calll Z_MallocInternal\n"
        "movl %eax, 0x14c13f8\n"
        "movl 0x14c13f0, %eax\n" /* line 4781 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 0x14c13fc\n"
        "xorl %edx, %edx\n" /* line 4782 */
        "movl $0, 0x14c13f4\n"
        "jmp .Lf14a22c_0014a26b\n"
    );
}

/* line 1571 */
__attribute__((naked))
void CL_RequestAuthorization(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1571 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "movl 0x195f314, %eax\n" /* line 1581 */
        "movl %eax, 4(%esp)\n"
        "movl 0x195f4e4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_CDKeyValidate\n"
        "testl %eax, %eax\n"
        "je .Lf14a31e_0014a495\n"
        "cmpw $0, 0x14c13b4\n" /* line 1587 */
        "je .Lf14a31e_0014a402\n"
        "cmpl $1, 0x14c13ac\n" /* line 1599 */
        "je .Lf14a31e_0014a3fa\n"
        ".Lf14a31e_0014a360:\n"
        "movl $0x216d6c, (%esp)\n" /* line 1604 */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "je .Lf14a31e_0014a4b1\n"
        "movl $0x40, 8(%esp)\n" /* line 1606 */
        "movl $0x2a9080, 4(%esp)\n" /* "demo" */
        "leal -0x64(%ebp), %ebx\n" /* nums, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll I_strncpyz\n"
        ".Lf14a31e_0014a38f:\n"
        "movl $0x101b, 8(%esp)\n" /* line 1628 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a9300, (%esp)\n" /* "cl_anonymous" */
        "calll Dvar_RegisterBool\n"
        "movl %ebx, 8(%esp)\n" /* line 1629 | i */
        "movzbl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2a9310, (%esp)\n" /* "getKeyAuthorize %i %s" */
        "calll va\n"
        "movl 0x14c13ac, %ebx\n" /* i */
        "movl %ebx, -0x24(%ebp)\n" /* i */
        "movl 0x14c13b0, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl 0x14c13b4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        /* } scope */
        ".Lf14a31e_0014a3fa:\n"
        "addl $0x7c, %esp\n" /* line 1631 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14a31e_0014a402:\n"
        "movl $0x2a9298, 4(%esp)\n" /* line 1589 */
        "movl $0x2a92b4, (%esp)\n" /* "Resolving %s
" */
        "calll Com_Printf\n"
        "movl $0x14c13ac, 4(%esp)\n" /* line 1590 */
        "movl $0x2a9298, (%esp)\n" /* "cod2master.activision.com" */
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "je .Lf14a31e_0014a4de\n"
        "movw $0xdc50, 0x14c13b4\n" /* line 1596 */
        "movl $0x50dc, 0x18(%esp)\n" /* line 1597 */
        "movzbl 0x14c13b3, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl 0x14c13b2, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl 0x14c13b1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movzbl 0x14c13b0, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a9298, 4(%esp)\n" /* "cod2master.activision.com" */
        "movl $0x2a92e0, (%esp)\n" /* "%s resolved to %i.%i.%i.%i:%i
" */
        "calll Com_Printf\n"
        "cmpl $1, 0x14c13ac\n" /* line 1599 */
        "jne .Lf14a31e_0014a360\n"
        "jmp .Lf14a31e_0014a3fa\n"
        ".Lf14a31e_0014a495:\n"
        "movl $0x2a9280, 4(%esp)\n" /* line 1583 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1631 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14a31e_0014a4b1:\n"
        "movl 0x195f4e4, %esi\n" /* line 1612 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* j */
        "repne scasb %es:(%edi), %al\n" /* j */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x20, %ecx\n" /* line 1613 */
        "jg .Lf14a31e_0014a4f2\n"
        "testl %ecx, %ecx\n" /* line 1617 */
        "jg .Lf14a31e_0014a4f7\n"
        "xorl %edi, %edi\n" /* j */
        "movb $0, -0x64(%ebp, %edi)\n" /* line 1625 */
        "leal -0x64(%ebp), %ebx\n" /* nums, i */
        "jmp .Lf14a31e_0014a38f\n"
        ".Lf14a31e_0014a4de:\n"
        "movl $0x2a92c4, (%esp)\n" /* line 1592 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1631 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14a31e_0014a4f2:\n"
        "movl $0x20, %ecx\n" /* line 1613 */
        ".Lf14a31e_0014a4f7:\n"
        "xorl %ebx, %ebx\n" /* line 1617 | i */
        "xorl %edi, %edi\n" /* j */
        ".Lf14a31e_0014a4fb:\n"
        "movzbl (%ebx, %esi), %edx\n" /* line 1619 | i */
        "leal -0x30(%edx), %eax\n"
        "cmpb $9, %al\n"
        "jbe .Lf14a31e_0014a514\n"
        "leal -0x61(%edx), %eax\n"
        "cmpb $0x19, %al\n"
        "jbe .Lf14a31e_0014a514\n"
        "leal -0x41(%edx), %eax\n"
        "cmpb $0x19, %al\n"
        "ja .Lf14a31e_0014a51b\n"
        ".Lf14a31e_0014a514:\n"
        "movb %dl, -0x64(%ebp, %edi)\n" /* line 1621 */
        "addl $1, %edi\n" /* line 1622 | j */
        ".Lf14a31e_0014a51b:\n"
        "addl $1, %ebx\n" /* line 1617 | i */
        "cmpl %ebx, %ecx\n" /* i */
        "jne .Lf14a31e_0014a4fb\n"
        "movb $0, -0x64(%ebp, %edi)\n" /* line 1625 */
        "leal -0x64(%ebp), %ebx\n" /* nums, i */
        "jmp .Lf14a31e_0014a38f\n"
    );
}

/* line 2291 */
__attribute__((naked))
void CL_CheckForResend(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2291 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x85c, %esp\n"
        /* { scope 1 */
        "movl 0x1501bc0, %edx\n" /* line 2298 */
        "testl %edx, %edx\n"
        "jne .Lf14a530_0014a553\n"
        "movl clientConnections, %eax\n" /* line 2304 */
        "subl $3, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf14a530_0014a55e\n"
        /* } scope */
        ".Lf14a530_0014a553:\n"
        "addl $0x85c, %esp\n" /* line 2368 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14a530_0014a55e:\n"
        "movl 0x1220a78, %edx\n" /* line 2309 */
        "movl %edx, %eax\n"
        "subl 0x14c1440, %eax\n"
        "cmpl $0xbb7, %eax\n"
        "jle .Lf14a530_0014a553\n"
        "movl %edx, 0x14c1440\n" /* line 2314 */
        "movl clc, %ebx\n" /* line 2315 */
        "addl $1, 0x24(%ebx)\n"
        "movl (%ebx), %eax\n" /* line 2317 */
        "cmpl $3, %eax\n"
        "je .Lf14a530_0014a5a9\n"
        "cmpl $4, %eax\n"
        "je .Lf14a530_0014a61f\n"
        "movl $0x2a934c, 4(%esp)\n" /* line 2366 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14a530_0014a553\n"
        ".Lf14a530_0014a5a9:\n"
        "movl 0x195f354, %eax\n" /* line 2321 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf14a530_0014a618\n"
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 0x18(%ebx), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x1c(%ebx), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll Sys_IsLANAddress\n"
        "testl %eax, %eax\n"
        "je .Lf14a530_0014a618\n"
        ".Lf14a530_0014a5dc:\n"
        "movl clc, %eax\n" /* line 2323 */
        "movl 0x14(%eax), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl $0x2a9328, 0x10(%esp)\n" /* "getchallenge" */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "jmp .Lf14a530_0014a553\n"
        ".Lf14a530_0014a618:\n"
        "calll CL_RequestAuthorization\n" /* line 2322 */
        "jmp .Lf14a530_0014a5dc\n"
        ".Lf14a530_0014a61f:\n"
        "movl $2, (%esp)\n" /* line 2334 */
        "calll Dvar_InfoString\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x43c(%ebp), %esi\n" /* info */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x73, 4(%esp)\n" /* line 2335 */
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a7118, 4(%esp)\n" /* "protocol" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl 0x128(%ebx), %eax\n" /* line 2336 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a9338, 4(%esp)\n" /* "challenge" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl 4(%ebx), %eax\n" /* line 2339 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a9344, 4(%esp)\n" /* "qport" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl $0x6e6e6f63, -0x83c(%ebp)\n" /* line 2342 | data */
        "movl $0x20746365, -0x838(%ebp)\n"
        "movb $0x22, -0x834(%ebp)\n" /* line 2344 */
        "xorl %edx, %edx\n"
        "xorl %ebx, %ebx\n"
        "cld\n"
        "jmp .Lf14a530_0014a6ee\n"
        ".Lf14a530_0014a6e0:\n"
        "movzbl (%edx, %esi), %eax\n" /* line 2348 */
        "movb %al, -0x833(%ebp, %edx)\n"
        "addl $1, %edx\n" /* line 2346 */
        ".Lf14a530_0014a6ee:\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "movl %ebx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl %edx, %ecx\n"
        "ja .Lf14a530_0014a6e0\n"
        "movb $0x22, -0x833(%ebp, %edx)\n" /* line 2350 */
        "leal 0xa(%edx), %ebx\n" /* line 2351 */
        "movb $0, -0x83c(%ebp, %ebx)\n"
        "movl clc, %eax\n" /* line 2353 */
        "movl 0x14(%eax), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "leal -0x83c(%ebp), %ebx\n" /* data */
        "movl %ebx, 0x10(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_OutOfBandData\n"
        "movl 0x195ec9c, %eax\n" /* line 2362 */
        "andl $0xfffffffd, (%eax)\n"
        "jmp .Lf14a530_0014a553\n"
    );
}

/* line 4400 */
__attribute__((naked))
void CL_LocalServers_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4400 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl $0x2a9370, (%esp)\n" /* line 4407 */
        "calll Com_Printf\n"
        "movl $0, 0x1220a98\n" /* line 4410 */
        "movl $0, 0x14c13a8\n" /* line 4411 */
        "movl $0, -0x3c(%ebp)\n" /* i */
        "movl $cls, %esi\n"
        "movl $0x1220a9c, %edi\n"
        /* { scope 2 */
        ".Lf14a760_0014a79a:\n"
        "movzbl 0x14b(%esi), %ebx\n" /* line 4415 | b */
        "movl $0x88, 8(%esp)\n" /* line 4417 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Com_Memset\n"
        "movb %bl, 0x14b(%esi)\n" /* line 4418 | b */
        /* } scope */
        "addl $1, -0x3c(%ebp)\n" /* line 4413 | i */
        "addl $0x88, %edi\n"
        "addl $0x88, %esi\n"
        "cmpl $0x80, -0x3c(%ebp)\n" /* i */
        "jne .Lf14a760_0014a79a\n"
        "movl $0xc, 8(%esp)\n" /* line 4420 */
        "movl $0, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* to */
        "movl %eax, (%esp)\n"
        "calll Com_Memset\n"
        "movl $2, %esi\n"
        ".Lf14a760_0014a7f8:\n"
        "movl $0x7120, %ebx\n" /* b */
        /* { scope 2 */
        ".Lf14a760_0014a7fd:\n"
        "movl %ebx, %eax\n" /* line 46 */
        "rolw $8, %ax\n"
        /* } scope */
        "movw %ax, -0x28(%ebp)\n" /* line 4435 */
        "movl $3, -0x30(%ebp)\n" /* line 4437 | to */
        "movl $3, -0x24(%ebp)\n" /* line 4438 */
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl $3, 8(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x2a93a0, 4(%esp)\n" /* "����getinfo xxx" */
        "movl $0xf, (%esp)\n"
        "calll CL_Netchan_SendOOBPacket\n"
        "addl $1, %ebx\n" /* b */
        "cmpl $0x7124, %ebx\n" /* line 4433 | b */
        "jne .Lf14a760_0014a7fd\n"
        "subl $1, %esi\n" /* line 4428 */
        "jne .Lf14a760_0014a7f8\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 4441 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3835 */
__attribute__((naked))
void CL_PlayLogo_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3835 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 3839 */
        "cmpl $5, %eax\n"
        "je .Lf14a85e_0014a883\n"
        "movl $0x2a93b0, (%esp)\n" /* line 3841 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf14a85e_0014a87c:\n"
        "addl $0x40, %esp\n" /* line 3870 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14a85e_0014a883:\n"
        "movl $0x2a9408, (%esp)\n" /* line 3844 */
        "calll Com_DPrintf\n"
        "movl clc, %ebx\n" /* line 3845 */
        "movl (%ebx), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf14a85e_0014aa54\n"
        "cmpl $2, %eax\n" /* line 3847 */
        "je .Lf14a85e_0014aa38\n"
        "testl %eax, %eax\n" /* line 3849 */
        "jne .Lf14a85e_0014a87c\n"
        ".Lf14a85e_0014a8ad:\n"
        "movl $2, (%ebx)\n" /* line 3852 */
        "movl 0x1220a70, %ecx\n" /* line 3853 */
        "testl %ecx, %ecx\n"
        "jne .Lf14a85e_0014aa43\n"
        ".Lf14a85e_0014a8c1:\n"
        "movl $0, (%esp)\n" /* line 3856 */
        "calll SND_StopSounds\n"
        "movl $0, 4(%esp)\n" /* line 3858 */
        "movl $0x3f800000, (%esp)\n"
        "calll SND_FadeAllSounds\n"
        "movl $1, (%esp)\n" /* line 3860 */
        "calll Cmd_Argv\n"
        "movl %eax, %esi\n" /* name */
        "movl $2, (%esp)\n" /* line 3861 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x20(%ebp)\n"
        "cvtsd2ss -0x20(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x24(%ebp)\n"
        "cvttss2si -0x24(%ebp), %eax\n"
        "movl %eax, 0x1220a88\n"
        "movl $3, (%esp)\n" /* line 3862 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x18(%ebp)\n"
        "cvtsd2ss -0x18(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x28(%ebp)\n"
        "cvttss2si -0x28(%ebp), %eax\n"
        "movl %eax, 0x1220a84\n"
        "movl $4, (%esp)\n" /* line 3863 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x2c(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %eax\n"
        "movl %eax, 0x1220a8c\n" /* line 3863 */
        "addl 0x1220a88, %eax\n" /* line 3864 */
        "addl %eax, 0x1220a84\n"
        "movl 0x121c6b0, %ebx\n" /* line 3866 */
        "movl %esi, 4(%esp)\n" /* name */
        "movl $0x2a9418, (%esp)\n" /* "%s1" */
        "calll va\n"
        "movl $3, 8(%esp)\n"
        "movl $0x30, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *%ebx\n"
        "movl %eax, 0x1220a90\n"
        "movl 0x121c6b0, %ebx\n" /* line 3867 */
        "movl %esi, 4(%esp)\n" /* name */
        "movl $0x2a941c, (%esp)\n" /* "%s2" */
        "calll va\n"
        "movl $3, 8(%esp)\n"
        "movl $0x30, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *%ebx\n"
        "movl %eax, 0x1220a94\n"
        "movl 0x1220a78, %eax\n" /* line 3869 */
        "addl $0x64, %eax\n"
        "movl %eax, 0x1220a80\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 3870 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14a85e_0014aa38:\n"
        "movl $0, (%ebx)\n" /* line 3826 */
        "jmp .Lf14a85e_0014a8ad\n"
        ".Lf14a85e_0014aa43:\n"
        "movl $0, (%esp)\n" /* line 3854 */
        "calll UI_SetActiveMenu\n"
        "jmp .Lf14a85e_0014a8c1\n"
        ".Lf14a85e_0014aa54:\n"
        "calll SCR_StopCinematic\n" /* line 3846 */
        "jmp .Lf14a85e_0014a8ad\n"
    );
}

/* line 4573 */
__attribute__((naked))
qboolean CL_UpdateDirtyPings_f(int source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4573 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        "movl 8(%ebp), %edx\n" /* source */
        /* { scope 1 */
        "movl clientConnections, %ecx\n" /* line 4581 */
        "testl %ecx, %ecx\n"
        "jne .Lf14aa5e_0014ac6e\n"
        "cmpl $2, %edx\n" /* line 4584 */
        "ja .Lf14aa5e_0014ac6e\n"
        "movl %edx, 0x14c13a8\n" /* line 4589 */
        "movl $0, -0x45c(%ebp)\n" /* slots */
        "movl $0x121c808, %eax\n"
        ".Lf14aa5e_0014aa99:\n"
        "cmpw $1, (%eax)\n" /* line 4560 */
        "sbbl $-1, -0x45c(%ebp)\n" /* slots */
        "addl $0x414, %eax\n"
        "movl $0x1220948, %ecx\n" /* line 4556 */
        "cmpl %eax, %ecx\n"
        "jne .Lf14aa5e_0014aa99\n"
        "cmpl $0xf, -0x45c(%ebp)\n" /* line 4592 | slots */
        "jg .Lf14aa5e_0014aca8\n"
        /* { scope 2 */
        "cmpl $1, %edx\n" /* line 4596 */
        "je .Lf14aa5e_0014ac89\n"
        "cmpl $2, %edx\n" /* line 4597 */
        "je .Lf14aa5e_0014ad38\n"
        "testl %edx, %edx\n"
        "je .Lf14aa5e_0014ad23\n"
        "xorl %eax, %eax\n"
        "movl $0x80, -0x454(%ebp)\n" /* max */
        ".Lf14aa5e_0014aae5:\n"
        "movl %eax, -0x44c(%ebp)\n" /* line 4617 */
        "movl $0, -0x450(%ebp)\n" /* status */
        "movl $0, -0x458(%ebp)\n" /* i */
        "movl %eax, %ecx\n"
        "jmp .Lf14aa5e_0014ab2c\n"
        ".Lf14aa5e_0014ab03:\n"
        "addl $1, -0x458(%ebp)\n" /* i */
        "addl $0x88, -0x44c(%ebp)\n"
        "movl -0x458(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x454(%ebp)\n" /* max */
        "je .Lf14aa5e_0014acb2\n"
        "movl -0x44c(%ebp), %ecx\n"
        ".Lf14aa5e_0014ab2c:\n"
        "cmpb $0, 0xf(%ecx)\n" /* line 4619 */
        "je .Lf14aa5e_0014ab03\n"
        "cmpw $-1, 0x1e(%ecx)\n" /* line 4621 */
        "jne .Lf14aa5e_0014ab03\n"
        /* { scope 3 */
        "cmpl $0xf, -0x45c(%ebp)\n" /* line 4625 | slots */
        "jg .Lf14aa5e_0014acbc\n"
        "movl $0x121c808, %edi\n" /* line 4627 */
        "jmp .Lf14aa5e_0014ab5c\n"
        ".Lf14aa5e_0014ab4d:\n"
        "addl $0x414, %edi\n" /* line 4646 */
        "movl $0x1220948, %eax\n" /* line 4629 */
        "cmpl %edi, %eax\n"
        "je .Lf14aa5e_0014abc0\n"
        ".Lf14aa5e_0014ab5c:\n"
        "cmpw $0, (%edi)\n" /* line 4631 */
        "je .Lf14aa5e_0014ab4d\n"
        "movl -0x44c(%ebp), %eax\n" /* line 4643 */
        "movl (%eax), %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl 4(%eax), %esi\n"
        "movl %esi, -0x3c(%ebp)\n"
        "movl 8(%eax), %ebx\n"
        "movl %ebx, -0x38(%ebp)\n"
        "movl -8(%edi), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl -4(%edi), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl (%edi), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl -8(%edi), %ecx\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf14aa5e_0014ab03\n"
        "addl $0x414, %edi\n" /* line 4646 */
        "movl $0x1220948, %eax\n" /* line 4629 */
        "cmpl %edi, %eax\n"
        "jne .Lf14aa5e_0014ab5c\n"
        ".Lf14aa5e_0014abc0:\n"
        "xorl %edx, %edx\n"
        "movl $cl_pinglist, %eax\n"
        ".Lf14aa5e_0014abc7:\n"
        "cmpw $0, 8(%eax)\n" /* line 4655 */
        "je .Lf14aa5e_0014abdb\n"
        "addl $1, %edx\n" /* line 4653 */
        "addl $0x414, %eax\n"
        "cmpl $0x10, %edx\n"
        "jne .Lf14aa5e_0014abc7\n"
        ".Lf14aa5e_0014abdb:\n"
        "movl %edx, %ebx\n" /* line 4664 */
        "shll $6, %ebx\n"
        "addl %edx, %ebx\n"
        "leal (%edx, %ebx, 4), %ebx\n"
        "shll $2, %ebx\n"
        "leal cl_pinglist(%ebx), %edx\n"
        "movl -0x44c(%ebp), %ecx\n"
        "movl (%ecx), %eax\n"
        "movl %eax, cl_pinglist(%ebx)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "calll Sys_Milliseconds\n" /* line 4667 */
        "movl %eax, 0x121c80c(%ebx)\n"
        "movl $0, 0x121c810(%ebx)\n" /* line 4668 */
        "movl cl_pinglist(%ebx), %esi\n" /* line 4669 */
        "movl %esi, -0x28(%ebp)\n"
        "movl 0x121c804(%ebx), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl 0x121c808(%ebx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl $0x2a9420, 0x10(%esp)\n" /* "getinfo xxx" */
        "movl %esi, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "addl $1, -0x45c(%ebp)\n" /* line 4670 | slots */
        "movl $1, -0x450(%ebp)\n" /* status */
        "jmp .Lf14aa5e_0014ab03\n"
        /* } scope */
        /* } scope */
        ".Lf14aa5e_0014ac6e:\n"
        "movl $0, -0x450(%ebp)\n" /* line 4681 | status */
        /* } scope */
        ".Lf14aa5e_0014ac78:\n"
        "movl -0x450(%ebp), %eax\n" /* line 4696 | status */
        "addl $0x47c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf14aa5e_0014ac89:\n"
        "movl 0x1224ea0, %ecx\n" /* line 4606 */
        "movl %ecx, -0x454(%ebp)\n" /* max */
        "movl $0x1224ea4, %eax\n"
        ".Lf14aa5e_0014ac9a:\n"
        "movl -0x454(%ebp), %edx\n" /* line 4617 | max */
        "testl %edx, %edx\n"
        "jg .Lf14aa5e_0014aae5\n"
        ".Lf14aa5e_0014aca8:\n"
        "movl $0, -0x450(%ebp)\n" /* status */
        /* } scope */
        ".Lf14aa5e_0014acb2:\n"
        "movl -0x45c(%ebp), %eax\n" /* line 4677 | slots */
        "testl %eax, %eax\n"
        "je .Lf14aa5e_0014acc6\n"
        ".Lf14aa5e_0014acbc:\n"
        "movl $1, -0x450(%ebp)\n" /* status */
        ".Lf14aa5e_0014acc6:\n"
        "xorl %ebx, %ebx\n"
        "movl $cl_pinglist, %esi\n"
        "leal -0x440(%ebp), %edi\n" /* buff */
        "jmp .Lf14aa5e_0014ace3\n"
        ".Lf14aa5e_0014acd5:\n"
        "addl $1, %ebx\n" /* line 4681 */
        "addl $0x414, %esi\n"
        "cmpl $0x10, %ebx\n"
        "je .Lf14aa5e_0014ac78\n"
        ".Lf14aa5e_0014ace3:\n"
        "cmpw $0, 8(%esi)\n" /* line 4683 */
        "je .Lf14aa5e_0014acd5\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 4687 | pingTime */
        "movl %ecx, 0xc(%esp)\n"
        "movl $0x400, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_GetPing\n"
        "movl -0x1c(%ebp), %eax\n" /* line 4688 | pingTime */
        "testl %eax, %eax\n"
        "je .Lf14aa5e_0014acd5\n"
        "cmpl $0xf, %ebx\n" /* line 4535 */
        "ja .Lf14aa5e_0014ad17\n"
        "movw $0, 8(%esi)\n" /* line 4538 */
        ".Lf14aa5e_0014ad17:\n"
        "movl $1, -0x450(%ebp)\n" /* status */
        "jmp .Lf14aa5e_0014acd5\n"
        /* { scope 2 */
        ".Lf14aa5e_0014ad23:\n"
        "movl 0x1220a98, %eax\n" /* line 4601 */
        "movl %eax, -0x454(%ebp)\n" /* max */
        "movl $0x1220a9c, %eax\n"
        "jmp .Lf14aa5e_0014ac9a\n"
        ".Lf14aa5e_0014ad38:\n"
        "movl 0x14bcfa4, %eax\n" /* line 4612 */
        "movl %eax, -0x454(%ebp)\n" /* max */
        "movl $0x14bcfa8, %eax\n"
        "jmp .Lf14aa5e_0014ac9a\n"
    );
}

/* line 2981 */
__attribute__((naked))
void CL_RunOncePerClientFrame(int msec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2981 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* msec */
        "calll UI_IsFullscreen\n" /* line 2998 */
        "testl %eax, %eax\n"
        "jne .Lf14ad4e_0014ae2c\n"
        ".Lf14ad4e_0014ad65:\n"
        "movl cl_avidemo, %edx\n" /* line 3006 */
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14ad4e_0014ad76\n"
        "testl %ebx, %ebx\n" /* msec */
        "jne .Lf14ad4e_0014add8\n"
        ".Lf14ad4e_0014ad76:\n"
        "movl 0x1220a70, %eax\n" /* line 3021 */
        "testl %eax, %eax\n"
        "jne .Lf14ad4e_0014ae22\n"
        ".Lf14ad4e_0014ad83:\n"
        "movl %ebx, 0x1220a7c\n" /* line 3025 | msec */
        "movl %ebx, 0x1220a74\n" /* line 3028 | msec */
        "addl %ebx, 0x1220a78\n" /* line 3030 | msec */
        "movl 0x195f2d8, %eax\n" /* line 3032 */
        "movl (%eax), %ecx\n"
        "movl $1, %eax\n" /* line 3034 */
        "movl %ecx, %edx\n"
        "subl old_com_frameTime, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl %eax, frame_msec\n"
        "movl $0xc8, %eax\n" /* line 3040 */
        "cmpl $0xc9, frame_msec\n"
        "cmovbl frame_msec, %eax\n"
        "movl %eax, frame_msec\n"
        "movl %ecx, old_com_frameTime\n" /* line 3042 */
        "addl $0x14, %esp\n" /* line 3043 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14ad4e_0014add8:\n"
        "movl clc, %eax\n" /* line 3009 */
        "cmpl $8, (%eax)\n"
        "je .Lf14ad4e_0014ae37\n"
        "movl cl_forceavidemo, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf14ad4e_0014ae37\n"
        ".Lf14ad4e_0014aded:\n"
        "cvtsi2ssl 8(%edx), %xmm1\n" /* line 3014 */
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "movl 0x195f4a8, %eax\n"
        "mulss (%eax), %xmm0\n"
        "cvttss2si %xmm0, %ebx\n" /* msec */
        "testl %ebx, %ebx\n" /* line 3015 | msec */
        "movl $1, %eax\n"
        "cmovel %eax, %ebx\n" /* msec */
        "movl 0x1220a70, %eax\n" /* line 3021 */
        "testl %eax, %eax\n"
        "je .Lf14ad4e_0014ad83\n"
        ".Lf14ad4e_0014ae22:\n"
        "calll CG_CalculateFPS\n" /* line 3022 */
        "jmp .Lf14ad4e_0014ad83\n"
        ".Lf14ad4e_0014ae2c:\n"
        "calll *0x121c7f4\n" /* line 4981 */
        "jmp .Lf14ad4e_0014ad65\n"
        ".Lf14ad4e_0014ae37:\n"
        "movl $0x2a942c, 4(%esp)\n" /* line 3011 */
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl cl_avidemo, %edx\n"
        "jmp .Lf14ad4e_0014aded\n"
    );
}

/* line 2911 */
__attribute__((naked))
int Client_SendVoiceData(int bytes, char *enc_buffer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2911 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* bytes */
        "testl %esi, %esi\n" /* line 2913 | bytes */
        "jle .Lf14ae54_0014aeed\n"
        "movl 0x168384c, %edx\n" /* line 2915 */
        "movl %edx, %eax\n"
        "shll $8, %eax\n"
        "leal 0x1682e28(%eax, %edx, 4), %edx\n"
        "movl %esi, 8(%esp)\n" /* bytes */
        "movl 0xc(%ebp), %eax\n" /* enc_buffer */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl cl, %ebx\n" /* line 2916 */
        "movl 0x179c0c(%ebx), %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %esi, 0x1791e4(%eax, %ebx)\n" /* bytes */
        "movl 0x179c0c(%ebx), %edx\n" /* line 2917 */
        "addl $1, %edx\n"
        "movl %edx, 0x179c0c(%ebx)\n"
        "testl %edx, %edx\n" /* line 2896 */
        "jle .Lf14ae54_0014aeed\n"
        "movl 0x26f0(%ebx), %eax\n" /* line 2899 */
        "subl 0x179c10(%ebx), %eax\n"
        "cmpl $0xc7, %eax\n"
        "jg .Lf14ae54_0014aed2\n"
        "cmpl $9, %edx\n"
        "jle .Lf14ae54_0014aeed\n"
        ".Lf14ae54_0014aed2:\n"
        "calll CL_WriteVoicePacket\n" /* line 2903 */
        "movl $0, 0x179c0c(%ebx)\n" /* line 2905 */
        "movl 0x26f0(%ebx), %eax\n" /* line 2906 */
        "movl %eax, 0x179c10(%ebx)\n"
        ".Lf14ae54_0014aeed:\n"
        "movl %esi, %eax\n" /* line 2922 | bytes */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2482 */
__attribute__((naked))
Bool CL_ConnectionlessPacket(netadr_t from, msg_t *msg, int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2482 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        "movl 0x14(%ebp), %esi\n" /* msg */
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0x11a(%ebp)\n"
        "movzbl 0xf(%ebp), %edx\n"
        "movb %dl, -0x11b(%ebp)\n"
        "movzbl 0xe(%ebp), %ebx\n"
        "movb %bl, -0x11c(%ebp)\n"
        "movzbl 0xd(%ebp), %eax\n"
        "movb %al, -0x11d(%ebp)\n"
        "movzbl 0xc(%ebp), %edx\n"
        "movb %dl, -0x11e(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* from */
        /* { scope 1 */
        "movl $0x4000, 4(%esp)\n" /* line 2490 */
        "leal -0x1c(%ebp), %ebx\n" /* printBuf_large_local, c */
        "movl %ebx, (%esp)\n" /* c */
        "calll LargeLocal_LargeLocal\n"
        "movl %ebx, (%esp)\n" /* c */
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x124(%ebp)\n" /* printBuf */
        "movl %esi, (%esp)\n" /* line 2492 | msg */
        "calll MSG_BeginReading\n"
        "movl %esi, (%esp)\n" /* line 2493 | msg */
        "calll MSG_ReadLong\n"
        "movl 0xc(%esi), %eax\n" /* line 2496 | msg */
        "movl %eax, (%esp)\n"
        "calll CL_Netchan_AddOOBProfilePacket\n"
        "movl %esi, (%esp)\n" /* line 2498 | msg */
        "calll MSG_ReadStringLine\n"
        "movl %eax, (%esp)\n" /* line 2500 */
        "calll Cmd_TokenizeString\n"
        "movl $0, (%esp)\n" /* line 2502 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* c */
        "movl $0x2a9440, 4(%esp)\n" /* line 2504 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014afcd\n"
        "movl %esi, (%esp)\n" /* line 2507 | msg */
        "calll CL_VoicePacket\n"
        ".Lf14aef6_0014afb0:\n"
        "movl $1, %ebx\n" /* line 2695 | c */
        ".Lf14aef6_0014afb5:\n"
        "leal -0x1c(%ebp), %esi\n" /* printBuf_large_local, msg */
        "movl %esi, (%esp)\n" /* msg */
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 2696 | c */
        "addl $0x14c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14aef6_0014afcd:\n"
        "movl $0x2a9444, 4(%esp)\n" /* line 2523 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b012\n"
        "movl clc, %ebx\n" /* line 2525 | c */
        "cmpl $3, (%ebx)\n" /* c */
        "je .Lf14aef6_0014b04f\n"
        "movl $0x2a9458, (%esp)\n" /* line 2527 */
        "calll Com_Printf\n"
        ".Lf14aef6_0014aff8:\n"
        "xorl %ebx, %ebx\n" /* line 2695 | c */
        ".Lf14aef6_0014affa:\n"
        "leal -0x1c(%ebp), %esi\n" /* printBuf_large_local, msg */
        "movl %esi, (%esp)\n" /* msg */
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 2696 | c */
        "addl $0x14c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14aef6_0014b012:\n"
        "movl $0x2a949c, 4(%esp)\n" /* line 2547 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b0c8\n"
        "movl clc, %ebx\n" /* line 2549 | c */
        "cmpl $4, (%ebx)\n" /* c */
        "jg .Lf14aef6_0014b14e\n"
        "je .Lf14aef6_0014b1e6\n" /* line 2554 */
        "movl $0x2a94d0, (%esp)\n" /* line 2556 */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* line 2695 | c */
        "jmp .Lf14aef6_0014affa\n"
        ".Lf14aef6_0014b04f:\n"
        "movl $1, (%esp)\n" /* line 2533 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x128(%ebx)\n" /* c */
        "movl $4, (%ebx)\n" /* line 2534 | c */
        "movl $0, 0x24(%ebx)\n" /* line 2535 | c */
        "movl $0xfffe7961, 0x20(%ebx)\n" /* line 2536 | c */
        "movzwl -0x11a(%ebp), %edx\n" /* line 2540 */
        "movw %dx, 0x1c(%ebx)\n" /* c */
        "movzbl -0x11b(%ebp), %edx\n"
        "movb %dl, 0x1b(%ebx)\n" /* c */
        "movzbl -0x11c(%ebp), %edx\n"
        "movb %dl, 0x1a(%ebx)\n" /* c */
        "movzbl -0x11d(%ebp), %edx\n"
        "movb %dl, 0x19(%ebx)\n" /* c */
        "movzbl -0x11e(%ebp), %edx\n"
        "movb %dl, 0x18(%ebx)\n" /* c */
        "movl %edi, 0x14(%ebx)\n" /* c */
        "movl %eax, 4(%esp)\n" /* line 2541 */
        "movl $0x2a948c, (%esp)\n" /* "challenge: %d
" */
        "calll Com_DPrintf\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b0c8:\n"
        "movl $0x2a9558, 4(%esp)\n" /* line 2592 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b161\n"
        "movzwl -0x11a(%ebp), %ebx\n" /* line 2594 | c */
        "movw %bx, -0x80(%ebp)\n" /* c */
        "movzbl -0x11b(%ebp), %eax\n"
        "movb %al, -0x81(%ebp)\n"
        "movzbl -0x11c(%ebp), %edx\n"
        "movb %dl, -0x82(%ebp)\n"
        "movzbl -0x11d(%ebp), %ebx\n" /* c */
        "movb %bl, -0x83(%ebp)\n" /* c */
        "movzbl -0x11e(%ebp), %eax\n"
        "movb %al, -0x84(%ebp)\n"
        "movl %edi, -0x88(%ebp)\n"
        "movl 0x18(%ebp), %edx\n" /* time */
        "movl %edx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* msg */
        "movl %edi, (%esp)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll CL_ServerInfoPacket\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b14e:\n"
        "movl $0x2a94ac, (%esp)\n" /* line 2551 */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* line 2695 | c */
        "jmp .Lf14aef6_0014affa\n"
        ".Lf14aef6_0014b161:\n"
        "movl $0x2a9568, 4(%esp)\n" /* line 2599 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b331\n"
        "movzwl -0x11a(%ebp), %ebx\n" /* line 2601 | c */
        "movw %bx, -0xc8(%ebp)\n" /* c */
        "movzbl -0x11b(%ebp), %eax\n"
        "movb %al, -0xc9(%ebp)\n"
        "movzbl -0x11c(%ebp), %edx\n"
        "movb %dl, -0xca(%ebp)\n"
        "movzbl -0x11d(%ebp), %ebx\n" /* c */
        "movb %bl, -0xcb(%ebp)\n" /* c */
        "movzbl -0x11e(%ebp), %eax\n"
        "movb %al, -0xcc(%ebp)\n"
        "movl %edi, -0xd0(%ebp)\n"
        "movl %esi, 0xc(%esp)\n" /* msg */
        "movl %edi, (%esp)\n"
        "movl -0xcc(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xc8(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll CL_ServerStatusResponse\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b1e6:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 2561 | c */
        "movl %ecx, -0xc4(%ebp)\n"
        "movl 0x18(%ebx), %edx\n" /* c */
        "movl %edx, -0xc0(%ebp)\n"
        "movl 0x1c(%ebx), %esi\n" /* c, msg */
        "movl %esi, 0x14(%esp)\n" /* msg */
        "movl %esi, -0xbc(%ebp)\n" /* msg */
        "movzwl -0x11a(%ebp), %eax\n"
        "movw %ax, -0xb0(%ebp)\n"
        "movzbl -0x11b(%ebp), %eax\n"
        "movb %al, -0xb1(%ebp)\n"
        "movzbl -0x11c(%ebp), %eax\n"
        "movb %al, -0xb2(%ebp)\n"
        "movzbl -0x11d(%ebp), %eax\n"
        "movb %al, -0xb3(%ebp)\n"
        "movzbl -0x11e(%ebp), %eax\n"
        "movb %al, -0xb4(%ebp)\n"
        "movl %edi, -0xb8(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0xb4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xb0(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareBaseAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b40c\n"
        "movl $0x2a9508, (%esp)\n" /* line 2563 */
        "calll Com_Printf\n"
        "movl 0x14(%ebx), %ecx\n" /* line 2564 | c */
        "movl %ecx, -0xac(%ebp)\n"
        "movl 0x18(%ebx), %edx\n" /* c */
        "movl %edx, -0xa8(%ebp)\n"
        "movl 0x1c(%ebx), %eax\n" /* c */
        "movl %eax, -0xa4(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, %ebx\n" /* c */
        "movzwl -0x11a(%ebp), %edx\n"
        "movw %dx, -0x98(%ebp)\n"
        "movzbl -0x11b(%ebp), %eax\n"
        "movb %al, -0x99(%ebp)\n"
        "movzbl -0x11c(%ebp), %edx\n"
        "movb %dl, -0x9a(%ebp)\n"
        "movzbl -0x11d(%ebp), %eax\n"
        "movb %al, -0x9b(%ebp)\n"
        "movzbl -0x11e(%ebp), %edx\n"
        "movb %dl, -0x9c(%ebp)\n"
        "movl %edi, -0xa0(%ebp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x98(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %ebx, 8(%esp)\n" /* c */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a9540, (%esp)\n" /* "%s should have been %s
" */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* line 2695 | c */
        "jmp .Lf14aef6_0014affa\n"
        ".Lf14aef6_0014b331:\n"
        "movl $0x228e90, 4(%esp)\n" /* line 2607 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b4ac\n"
        "movl clc, %ebx\n" /* line 2383 */
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14aef6_0014afb0\n"
        "movl 0x407d8(%ebx), %ecx\n" /* line 2389 */
        "movl %ecx, -0x28(%ebp)\n"
        "movl 0x407dc(%ebx), %edx\n"
        "movl %edx, -0x12c(%ebp)\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl 0x407e0(%ebx), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movzwl -0x11a(%ebp), %esi\n"
        "movw %si, -0x74(%ebp)\n"
        "movzbl -0x11b(%ebp), %eax\n"
        "movb %al, -0x75(%ebp)\n"
        "movzbl -0x11c(%ebp), %eax\n"
        "movb %al, -0x76(%ebp)\n"
        "movzbl -0x11d(%ebp), %eax\n"
        "movb %al, -0x77(%ebp)\n"
        "movzbl -0x11e(%ebp), %eax\n"
        "movb %al, -0x78(%ebp)\n"
        "movl %edi, -0x7c(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x12c(%ebp), %esi\n"
        "movl %esi, 0x10(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x78(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf14aef6_0014afb0\n"
        "movl 0x1220a78, %eax\n" /* line 2396 */
        "subl 0x10(%ebx), %eax\n"
        "cmpl $0xbb7, %eax\n"
        "jle .Lf14aef6_0014afb0\n"
        "movl $0x215f8c, 4(%esp)\n" /* line 2401 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b40c:\n"
        "movl 0x195f368, %eax\n" /* line 2580 */
        "movl (%eax), %eax\n"
        "movzwl -0x11a(%ebp), %esi\n" /* msg */
        "movw %si, -0x8c(%ebp)\n" /* msg */
        "movzbl -0x11b(%ebp), %edx\n"
        "movb %dl, -0x8d(%ebp)\n"
        "movzbl -0x11c(%ebp), %edx\n"
        "movb %dl, -0x8e(%ebp)\n"
        "movzbl -0x11d(%ebp), %edx\n"
        "movb %dl, -0x8f(%ebp)\n"
        "movzbl -0x11e(%ebp), %edx\n"
        "movb %dl, -0x90(%ebp)\n"
        "movl %edi, -0x94(%ebp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal 0x407c8(%ebx), %eax\n" /* c */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Netchan_Setup\n"
        "movl $5, (%ebx)\n" /* line 2585 | c */
        "movl 0x1220a78, %eax\n" /* line 2586 */
        "movl %eax, 0x10(%ebx)\n" /* c */
        "movl $0xffffd8f1, 0xc(%ebx)\n" /* line 2587 | c */
        "movl $1, %ebx\n" /* c */
        "jmp .Lf14aef6_0014afb5\n"
        ".Lf14aef6_0014b4ac:\n"
        "movl $0x2a9578, 4(%esp)\n" /* line 2614 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b539\n"
        "movl $1, (%esp)\n" /* line 2616 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "movzwl -0x11a(%ebp), %edx\n"
        "movw %dx, -0x68(%ebp)\n"
        "movzbl -0x11b(%ebp), %ebx\n" /* c */
        "movb %bl, -0x69(%ebp)\n" /* c */
        "movzbl -0x11c(%ebp), %edx\n"
        "movb %dl, -0x6a(%ebp)\n"
        "movzbl -0x11d(%ebp), %ebx\n" /* c */
        "movb %bl, -0x6b(%ebp)\n" /* c */
        "movzbl -0x11e(%ebp), %edx\n"
        "movb %dl, -0x6c(%ebp)\n"
        "movl %edi, -0x70(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b539:\n"
        "movl $0x2a9580, 4(%esp)\n" /* line 2621 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf14aef6_0014afb0\n"
        "movl $0x2a9590, 4(%esp)\n" /* line 2628 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b5c2\n"
        "movl %esi, (%esp)\n" /* line 2630 | msg */
        "calll MSG_ReadBigString\n"
        "movl %eax, %ebx\n" /* c */
        "movl $0x100, 8(%esp)\n" /* line 2631 */
        "movl %eax, 4(%esp)\n"
        "movl clc, %eax\n"
        "addl $0x28, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %ebx, 0xc(%esp)\n" /* line 2632 | c */
        "movl $0x216058, 8(%esp)\n" /* "%s" */
        "movl $0x4000, 4(%esp)\n"
        "movl -0x124(%ebp), %ebx\n" /* printBuf, c */
        "movl %ebx, (%esp)\n" /* c */
        "calll Com_sprintf\n"
        "movl %ebx, 4(%esp)\n" /* line 2633 | c */
        "movl $0, (%esp)\n"
        "calll Com_PrintMessage\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b5c2:\n"
        "movl $0x2168a4, 4(%esp)\n" /* line 2638 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b681\n"
        "movl clc, %ecx\n" /* line 2641 */
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14aef6_0014aff8\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x18(%ecx), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl 0x1c(%ecx), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n"
        "movzwl -0x11a(%ebp), %ebx\n" /* c */
        "movw %bx, -0x50(%ebp)\n" /* c */
        "movzbl -0x11b(%ebp), %ebx\n" /* c */
        "movb %bl, -0x51(%ebp)\n" /* c */
        "movzbl -0x11c(%ebp), %ebx\n" /* c */
        "movb %bl, -0x52(%ebp)\n" /* c */
        "movzbl -0x11d(%ebp), %ebx\n" /* c */
        "movb %bl, -0x53(%ebp)\n" /* c */
        "movzbl -0x11e(%ebp), %ebx\n" /* c */
        "movb %bl, -0x54(%ebp)\n" /* c */
        "movl %edi, -0x58(%ebp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareBaseAdr\n"
        "testl %eax, %eax\n"
        "je .Lf14aef6_0014aff8\n"
        "movl %esi, (%esp)\n" /* line 2643 | msg */
        "calll MSG_ReadBigString\n"
        "movl %eax, 8(%esp)\n" /* line 2644 */
        "movl $0x216058, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b681:\n"
        "movl $0x12, 8(%esp)\n" /* line 2662 */
        "movl $0x2a9598, 4(%esp)\n" /* "getserversResponse" */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b6f2\n"
        "movzwl -0x11a(%ebp), %eax\n" /* line 2664 */
        "movw %ax, -0x44(%ebp)\n"
        "movzbl -0x11b(%ebp), %edx\n"
        "movb %dl, -0x45(%ebp)\n"
        "movzbl -0x11c(%ebp), %ebx\n" /* c */
        "movb %bl, -0x46(%ebp)\n" /* c */
        "movzbl -0x11d(%ebp), %eax\n"
        "movb %al, -0x47(%ebp)\n"
        "movzbl -0x11e(%ebp), %edx\n"
        "movb %dl, -0x48(%ebp)\n"
        "movl %edi, -0x4c(%ebp)\n"
        "movl %esi, 0xc(%esp)\n" /* msg */
        "movl %edi, (%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll CL_ServersResponsePacket\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b6f2:\n"
        "movl $9, 8(%esp)\n" /* line 2670 */
        "movl $0x2a95ac, 4(%esp)\n" /* "needcdkey" */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b77a\n"
        "movl $0x100, 8(%esp)\n" /* line 2673 */
        "movl $0x2a95b8, 4(%esp)\n" /* "EXE_AWAITINGCDKEYAUTH" */
        "movl clc, %ebx\n" /* c */
        "addl $0x28, %ebx\n" /* c */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_strncpyz\n"
        "movl $0, 8(%esp)\n" /* line 2674 */
        "movl $0x2a95d0, 4(%esp)\n" /* "need cd key message" */
        "movl $0x2a95b8, (%esp)\n" /* "EXE_AWAITINGCDKEYAUTH" */
        "calll SEH_LocalizeTextMessage\n"
        "movl %ebx, 4(%esp)\n" /* line 2675 | c */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "calll CL_RequestAuthorization\n" /* line 2677 */
        "jmp .Lf14aef6_0014afb0\n"
        "movl %eax, %ebx\n" /* c */
        "leal -0x1c(%ebp), %edx\n" /* line 2695 | printBuf_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* c */
        "calll __Unwind_Resume\n"
        ".Lf14aef6_0014b77a:\n"
        "movl $0x2a95e4, 4(%esp)\n" /* line 2683 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014aff8\n"
        "movl clc, %ebx\n" /* line 2685 | c */
        "movl 0x14(%ebx), %eax\n" /* c */
        "movl %eax, -0x12c(%ebp)\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x18(%ebx), %edx\n" /* c */
        "movl %edx, -0x3c(%ebp)\n"
        "movl 0x1c(%ebx), %ecx\n" /* c */
        "movl %ecx, -0x38(%ebp)\n"
        "movzwl -0x11a(%ebp), %eax\n"
        "movw %ax, -0x2c(%ebp)\n"
        "movzbl -0x11b(%ebp), %eax\n"
        "movb %al, -0x2d(%ebp)\n"
        "movzbl -0x11c(%ebp), %eax\n"
        "movb %al, -0x2e(%ebp)\n"
        "movzbl -0x11d(%ebp), %eax\n"
        "movb %al, -0x2f(%ebp)\n"
        "movzbl -0x11e(%ebp), %eax\n"
        "movb %al, -0x30(%ebp)\n"
        "movl %edi, -0x34(%ebp)\n"
        "movl -0x12c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareBaseAdr\n"
        "testl %eax, %eax\n"
        "je .Lf14aef6_0014afb0\n"
        "movl %esi, (%esp)\n" /* line 2687 | msg */
        "calll MSG_ReadStringLine\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x110(%ebp), %edi\n" /* mapname */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %esi, (%esp)\n" /* line 2688 | msg */
        "calll MSG_ReadStringLine\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CL_SetupForNewServerMap\n"
        "movl $5, (%ebx)\n" /* line 2689 | c */
        "calll UI_DrawConnectScreen\n" /* line 2690 */
        "jmp .Lf14aef6_0014afb0\n"
    );
}

/* line 2733 */
__attribute__((naked))
Bool CL_PacketEvent(netadr_t from, msg_t *msg, int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2733 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 0x10(%ebp), %esi\n"
        "movzbl 0xf(%ebp), %edi\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x59(%ebp)\n"
        "movzbl 0xd(%ebp), %edx\n"
        "movb %dl, -0x5a(%ebp)\n"
        "movzbl 0xc(%ebp), %ecx\n"
        "movb %cl, -0x5b(%ebp)\n"
        "movl 8(%ebp), %ebx\n" /* from */
        /* { scope 1 */
        "movl 0x14(%ebp), %eax\n" /* line 2739 | msg */
        "movl 0xc(%eax), %edx\n"
        "cmpl $3, %edx\n"
        "jle .Lf14b85c_0014b89b\n"
        "movl 4(%eax), %eax\n"
        "cmpl $-1, (%eax)\n"
        "je .Lf14b85c_0014ba41\n"
        ".Lf14b85c_0014b89b:\n"
        "cmpl $4, clientConnections\n" /* line 2744 */
        "jle .Lf14b85c_0014b9e6\n"
        "cmpl $3, %edx\n" /* line 2749 */
        "jg .Lf14b85c_0014b901\n"
        "movw %si, -0x40(%ebp)\n" /* line 2751 | savedReliableAcknowledge */
        "movl %edi, %eax\n" /* savedServerMessageSequence */
        "movb %al, -0x41(%ebp)\n"
        "movzbl -0x59(%ebp), %edx\n"
        "movb %dl, -0x42(%ebp)\n"
        "movzbl -0x5a(%ebp), %ecx\n"
        "movb %cl, -0x43(%ebp)\n"
        "movzbl -0x5b(%ebp), %eax\n"
        "movb %al, -0x44(%ebp)\n"
        "movl %ebx, -0x48(%ebp)\n"
        "movl %ebx, (%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2a95f4, (%esp)\n" /* "%s: Runt packet
" */
        "calll Com_Printf\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf14b85c_0014b8f9:\n"
        "addl $0x7c, %esp\n" /* line 2816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14b85c_0014b901:\n"
        "movl 0x1501bf8, %ecx\n" /* line 2759 */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 0x1501bfc, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x1501c00, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movw %si, -0x28(%ebp)\n" /* savedReliableAcknowledge */
        "movl %edi, %eax\n" /* savedServerMessageSequence */
        "movb %al, -0x29(%ebp)\n"
        "movzbl -0x59(%ebp), %eax\n"
        "movb %al, -0x2a(%ebp)\n"
        "movzbl -0x5a(%ebp), %eax\n"
        "movb %al, -0x2b(%ebp)\n"
        "movzbl -0x5b(%ebp), %eax\n"
        "movb %al, -0x2c(%ebp)\n"
        "movl %ebx, -0x30(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x1501c00, %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf14b85c_0014b9f0\n"
        "movl clc, %ebx\n" /* line 2770 */
        "movl 0x1220a78, %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 2772 | msg */
        "movl %eax, 4(%esp)\n"
        "leal 0x407c8(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Netchan_Process\n"
        "testl %eax, %eax\n"
        "je .Lf14b85c_0014b9e6\n"
        "movl 0x14(%ebp), %edx\n" /* line 2776 | msg */
        "movl 0x10(%edx), %edx\n"
        "movl %edx, -0x60(%ebp)\n" /* headerBytes */
        "movl 0x20138(%ebx), %edi\n" /* line 2778 | savedServerMessageSequence */
        "movl 0x134(%ebx), %esi\n" /* line 2779 | savedReliableAcknowledge */
        "movl 0x14(%ebp), %ecx\n" /* line 2784 | msg */
        "movl 4(%ecx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x20138(%ebx)\n"
        "movl %ecx, (%esp)\n" /* line 2787 */
        "calll MSG_ReadLong\n"
        "movl %eax, 0x134(%ebx)\n"
        "movl 0x130(%ebx), %edx\n" /* line 2789 */
        "leal -0x80(%edx), %eax\n"
        "cmpl %eax, 0x134(%ebx)\n"
        "jge .Lf14b85c_0014ba8e\n"
        "movl %edx, 0x134(%ebx)\n" /* line 2791 */
        "xorl %eax, %eax\n"
        "jmp .Lf14b85c_0014b8f9\n"
        ".Lf14b85c_0014b9e6:\n"
        "xorl %eax, %eax\n" /* line 2813 */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 2816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14b85c_0014b9f0:\n"
        "movw %si, -0x1c(%ebp)\n" /* line 2761 | savedReliableAcknowledge */
        "movl %edi, %ecx\n" /* savedServerMessageSequence */
        "movb %cl, -0x1d(%ebp)\n"
        "movzbl -0x59(%ebp), %eax\n"
        "movb %al, -0x1e(%ebp)\n"
        "movzbl -0x5a(%ebp), %edx\n"
        "movb %dl, -0x1f(%ebp)\n"
        "movzbl -0x5b(%ebp), %ecx\n"
        "movb %cl, -0x20(%ebp)\n"
        "movl %ebx, -0x24(%ebp)\n"
        "movl %ebx, (%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2a9608, (%esp)\n" /* "%s:sequenced packet without connection
" */
        "calll Com_DPrintf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 2816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14b85c_0014ba41:\n"
        "movw %si, -0x4c(%ebp)\n" /* line 2741 | savedReliableAcknowledge */
        "movl %edi, %eax\n" /* savedServerMessageSequence */
        "movb %al, -0x4d(%ebp)\n"
        "movzbl -0x59(%ebp), %edx\n"
        "movb %dl, -0x4e(%ebp)\n"
        "movzbl -0x5a(%ebp), %ecx\n"
        "movb %cl, -0x4f(%ebp)\n"
        "movzbl -0x5b(%ebp), %eax\n"
        "movb %al, -0x50(%ebp)\n"
        "movl %ebx, -0x54(%ebp)\n"
        "movl 0x18(%ebp), %edx\n" /* time */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* msg */
        "movl %ecx, 0xc(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll CL_ConnectionlessPacket\n"
        "movzbl %al, %eax\n"
        "jmp .Lf14b85c_0014b8f9\n"
        ".Lf14b85c_0014ba8e:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2796 | msg */
        "movl 0x10(%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movl 0xc(%eax), %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "addl 4(%ecx), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CL_Netchan_Decode\n"
        "movl 0x14(%ebp), %eax\n" /* line 2799 | msg */
        "movl %eax, (%esp)\n"
        "calll CL_ParseServerMessage\n"
        "movl 0x14(%ebp), %edx\n" /* line 2800 | msg */
        "movl (%edx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf14b85c_0014baf8\n"
        "movl 0x4079c(%ebx), %eax\n" /* line 2812 */
        "testl %eax, %eax\n"
        "je .Lf14b85c_0014bad2\n"
        "movl 0x407a8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14b85c_0014badc\n"
        ".Lf14b85c_0014bad2:\n"
        "movl $1, %eax\n" /* line 2813 */
        "jmp .Lf14b85c_0014b8f9\n"
        ".Lf14b85c_0014badc:\n"
        "movl -0x60(%ebp), %ecx\n" /* headerBytes */
        "movl %ecx, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll CL_WriteDemoMessage\n"
        "movl $1, %eax\n"
        "jmp .Lf14b85c_0014b8f9\n"
        ".Lf14b85c_0014baf8:\n"
        "movl $0x2a9630, (%esp)\n" /* line 2802 */
        "calll Com_DPrintf\n"
        "movl %edi, 0x20138(%ebx)\n" /* line 2803 | savedServerMessageSequence */
        "movl %esi, 0x134(%ebx)\n" /* line 2804 | savedReliableAcknowledge */
        "xorl %eax, %eax\n"
        "jmp .Lf14b85c_0014b8f9\n"
    );
}

/* line 4225 */
__attribute__((naked))
void CL_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4225 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $0x2a964c, (%esp)\n" /* line 4227 */
        "calll Com_Printf\n"
        "movl cl, %ebx\n" /* line 1353 */
        "movzbl 9(%ebx), %esi\n"
        "movzbl 0xa(%ebx), %edi\n" /* line 1354 */
        "movl 4(%ebx), %eax\n" /* line 1355 */
        "movl %eax, -0x20(%ebp)\n"
        "movzbl 8(%ebx), %eax\n" /* line 1356 */
        "movb %al, -0x1a(%ebp)\n"
        "movzbl (%ebx), %eax\n" /* line 1357 */
        "movb %al, -0x19(%ebp)\n"
        "movl $0x179c14, 8(%esp)\n" /* line 1359 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memset\n"
        "movl %esi, %eax\n" /* line 1361 */
        "movb %al, 9(%ebx)\n"
        "movl %edi, %eax\n" /* line 1362 */
        "movb %al, 0xa(%ebx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 1363 */
        "movl %eax, 4(%ebx)\n"
        "movzbl -0x1a(%ebp), %eax\n" /* line 1364 */
        "movb %al, 8(%ebx)\n"
        "movzbl -0x19(%ebp), %eax\n" /* line 1365 */
        "movb %al, (%ebx)\n"
        "calll Com_ClientDObjClearAllSkel\n" /* line 1367 */
        "calll CL_ClearMutedList\n" /* line 4236 */
        "movl $0, 0x179c0c(%ebx)\n" /* line 4237 */
        "movl clc, %eax\n" /* line 4240 */
        "movl $0, (%eax)\n"
        "movl $0, 0x1220a78\n" /* line 4242 */
        "movb $1, (%ebx)\n" /* line 4244 */
        "movl 0x195ecb4, %ebx\n" /* line 4246 */
        "movl (%ebx), %eax\n"
        "movb $0, 0x5c(%eax)\n"
        "movl (%ebx), %eax\n" /* line 4247 */
        "movb $0, 0x9c(%eax)\n"
        "movl (%ebx), %eax\n" /* line 4248 */
        "movb $0, 0xdc(%eax)\n"
        "calll Cbuf_Execute\n" /* line 4250 */
        "movl (%ebx), %eax\n" /* line 4252 */
        "movl $1, 4(%eax)\n"
        "movl $0, (%esp)\n" /* line 4254 */
        "calll CL_SetADS\n"
        "movl $0x2a9670, (%esp)\n" /* line 4256 */
        "calll Com_Printf\n"
        "addl $0x2c, %esp\n" /* line 4257 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1139 */
__attribute__((naked))
void CL_ShutdownAll(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1139 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x121c7e8, %eax\n" /* line 1141 */
        "testl %eax, %eax\n"
        "je .Lf14bbfc_0014bc0d\n"
        "calll *%eax\n" /* line 1142 */
        ".Lf14bbfc_0014bc0d:\n"
        "movl 0x1220964, %ecx\n" /* line 1108 */
        "testl %ecx, %ecx\n"
        "jne .Lf14bbfc_0014bc35\n"
        ".Lf14bbfc_0014bc17:\n"
        "movl re, %eax\n" /* line 1147 */
        "testl %eax, %eax\n"
        "je .Lf14bbfc_0014bc29\n"
        "movl $0, (%esp)\n" /* line 1149 */
        "calll *%eax\n"
        ".Lf14bbfc_0014bc29:\n"
        "movl $0, 0x1220a68\n" /* line 1156 */
        "leave\n" /* line 1157 */
        "retl\n"
        ".Lf14bbfc_0014bc35:\n"
        "calll CL_ShutdownCGame\n" /* line 1115 */
        "calll CL_ShutdownUI\n" /* line 1118 */
        "movl $0, 0x14c13b8\n" /* line 3267 */
        "movl $0, 0x14c13bc\n" /* line 3268 */
        "movl $0, 0x14c13c0\n" /* line 3269 */
        "movl $0, 0x1220964\n" /* line 1130 */
        "jmp .Lf14bbfc_0014bc17\n"
    );
}

/* line 3062 */
__attribute__((naked))
void CL_Frame(int msec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3062 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0x195ecb4, %eax\n" /* line 3077 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf14bc6a_0014bc89\n"
        "addl $0x1c, %esp\n" /* line 3121 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14bc6a_0014bc89:\n"
        "movl 0x168384c, %eax\n" /* line 2944 */
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "leal 0x1682e24(%edx, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Voice_GetLocalVoiceData\n"
        "calll Voice_Playback\n" /* line 2945 */
        "calll CL_UpdateColor\n" /* line 3096 */
        "movl clc, %ebx\n" /* line 2854 */
        "cmpl $3, (%ebx)\n"
        "jle .Lf14bc6a_0014bd94\n"
        "movl 0x195ed18, %esi\n" /* line 2859 */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf14bc6a_0014bda1\n"
        ".Lf14bc6a_0014bcce:\n"
        "movl 8(%eax), %edi\n" /* line 2827 */
        "testl %edi, %edi\n"
        "je .Lf14bc6a_0014bd30\n"
        "movl 0x195f564, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf14bc6a_0014bd30\n"
        ".Lf14bc6a_0014bce3:\n"
        "movl (%ebx), %eax\n"
        ".Lf14bc6a_0014bce5:\n"
        "subl $3, %eax\n" /* line 2832 */
        "cmpl $1, %eax\n"
        "jbe .Lf14bc6a_0014bded\n"
        ".Lf14bc6a_0014bcf1:\n"
        "movl cl, %eax\n" /* line 2838 */
        "movl $0, 0x14(%eax)\n"
        ".Lf14bc6a_0014bcfd:\n"
        "calll CL_CheckForResend\n" /* line 3106 */
        "movl clc, %eax\n" /* line 2879 */
        "cmpl $8, (%eax)\n"
        "je .Lf14bc6a_0014bdb4\n"
        "movl cl_ingame, %eax\n" /* line 2886 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf14bc6a_0014bdd8\n"
        ".Lf14bc6a_0014bd1f:\n"
        "calll CL_SetCGameTime\n" /* line 3117 */
        "addl $0x1c, %esp\n" /* line 3121 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp CL_SendCmd\n" /* line 3120 */
        ".Lf14bc6a_0014bd30:\n"
        "movl (%ebx), %eax\n" /* line 2827 */
        "cmpl $4, %eax\n"
        "jle .Lf14bc6a_0014bce5\n"
        "cmpl $1, %eax\n"
        "je .Lf14bc6a_0014bce3\n"
        "cmpl $2, %eax\n"
        "je .Lf14bc6a_0014bce3\n"
        "movl 0x1220a78, %eax\n"
        "subl 0x10(%ebx), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "movl cl_timeout, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf14bc6a_0014bce3\n"
        "movl cl, %eax\n" /* line 2829 */
        "movl 0x14(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0x14(%eax)\n"
        "cmpl $5, %edx\n"
        "jle .Lf14bc6a_0014bcfd\n"
        ".Lf14bc6a_0014bd7b:\n"
        "movl $0x2a8c3c, 4(%esp)\n" /* line 2834 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14bc6a_0014bcfd\n"
        ".Lf14bc6a_0014bd94:\n"
        "movl 0x195ed18, %esi\n"
        "movl (%esi), %eax\n"
        "jmp .Lf14bc6a_0014bcce\n"
        ".Lf14bc6a_0014bda1:\n"
        "movl 0x195ec9c, %edx\n" /* line 2864 */
        "movl (%edx), %eax\n"
        "testb $2, %al\n"
        "jne .Lf14bc6a_0014be23\n"
        "movl (%esi), %eax\n"
        "jmp .Lf14bc6a_0014bcce\n"
        ".Lf14bc6a_0014bdb4:\n"
        "movl cl_ingame, %eax\n" /* line 2881 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf14bc6a_0014bd1f\n"
        "movl $1, 4(%esp)\n" /* line 2882 */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "jmp .Lf14bc6a_0014bd1f\n"
        ".Lf14bc6a_0014bdd8:\n"
        "movl $0, 4(%esp)\n" /* line 2887 */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "jmp .Lf14bc6a_0014bd1f\n"
        ".Lf14bc6a_0014bded:\n"
        "movl 0x10(%ebx), %edx\n" /* line 2832 */
        "testl %edx, %edx\n"
        "jle .Lf14bc6a_0014bcf1\n"
        "movl 0x1220a78, %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "movl cl_connectTimeout, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf14bc6a_0014bcf1\n"
        "jmp .Lf14bc6a_0014bd7b\n"
        ".Lf14bc6a_0014be23:\n"
        "andl $0xfffffffd, %eax\n" /* line 2866 */
        "movl %eax, (%edx)\n"
        "movl $2, (%esp)\n" /* line 2867 */
        "calll Dvar_InfoString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2a969c, (%esp)\n" /* "userinfo "%s"" */
        "calll va\n"
        "movl %eax, %edi\n"
        "movl 0x130(%ebx), %edx\n" /* line 651 */
        "movl %edx, %eax\n"
        "subl 0x134(%ebx), %eax\n"
        "addl $-0x80, %eax\n"
        "jg .Lf14bc6a_0014be90\n"
        ".Lf14bc6a_0014be59:\n"
        "leal 1(%edx), %eax\n" /* line 655 */
        "movl %eax, 0x130(%ebx)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%ebx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MSG_WriteReliableCommandToBuffer\n"
        "movl (%esi), %eax\n"
        "jmp .Lf14bc6a_0014bcce\n"
        ".Lf14bc6a_0014be90:\n"
        "movl $0x2a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%ebx), %edx\n"
        "jmp .Lf14bc6a_0014be59\n"
    );
}

/* line 1807 */
__attribute__((naked))
void CL_Vid_Restart_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1807 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        /* { scope 1 */
        "movl 0x195ecbc, %eax\n" /* line 1813 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf14beac_0014c0ff\n"
        "cmpb $0, 0x1509c49\n" /* line 1821 */
        "jne .Lf14beac_0014c090\n"
        "xorl %edi, %edi\n" /* clientStateBuf */
        "movl $0, -0x43c(%ebp)\n" /* clientStateBytes */
        ".Lf14beac_0014bee2:\n"
        "movl $0, 4(%esp)\n" /* line 1833 */
        "movl 0x195f2fc, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movb $0, g_waitingForServer\n" /* line 1835 */
        "movl $1, (%esp)\n" /* line 1838 */
        "calll SND_StopSounds\n"
        "movl 0x1220964, %ebx\n" /* line 1108 */
        "testl %ebx, %ebx\n"
        "jne .Lf14beac_0014c1db\n"
        ".Lf14beac_0014bf1a:\n"
        "movl 0x121c7e8, %eax\n" /* line 3208 */
        "testl %eax, %eax\n"
        "je .Lf14beac_0014bf25\n"
        "calll *%eax\n" /* line 3209 */
        ".Lf14beac_0014bf25:\n"
        "movl re, %eax\n" /* line 3211 */
        "testl %eax, %eax\n"
        "je .Lf14beac_0014bf53\n"
        "movl $1, (%esp)\n" /* line 3213 */
        "calll *%eax\n"
        "movl $0x160, 8(%esp)\n" /* line 3219 */
        "movl $0, 4(%esp)\n"
        "movl $re, (%esp)\n"
        "calll memset\n"
        ".Lf14beac_0014bf53:\n"
        "calll StatMon_Reset\n" /* line 3223 */
        "movl $0, 0x1220a68\n" /* line 1844 */
        "movl $0x2a96d4, (%esp)\n" /* line 1788 */
        "calll va\n"
        "movl %eax, %esi\n"
        "movl clc, %ebx\n" /* line 651 */
        "movl 0x130(%ebx), %edx\n"
        "movl %edx, %eax\n"
        "subl 0x134(%ebx), %eax\n"
        "addl $-0x80, %eax\n"
        "jg .Lf14beac_0014c1bc\n"
        ".Lf14beac_0014bf8d:\n"
        "leal 1(%edx), %eax\n" /* line 655 */
        "movl %eax, 0x130(%ebx)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%ebx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MSG_WriteReliableCommandToBuffer\n"
        "calll Com_Restart\n" /* line 1852 */
        "movl $0x1021, 0x10(%esp)\n" /* line 1854 */
        "movl $0xd, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x216a14, (%esp)\n" /* "loc_language" */
        "calll Dvar_RegisterInt\n"
        "movl $0x1020, 8(%esp)\n" /* line 1855 */
        "movl $1, 4(%esp)\n"
        "movl $0x216a38, (%esp)\n" /* "loc_translate" */
        "calll Dvar_RegisterBool\n"
        "movl $0x10a0, 8(%esp)\n" /* line 1856 */
        "movl $0, 4(%esp)\n"
        "movl $0x216d78, (%esp)\n" /* "fs_ignoreLocalized" */
        "calll Dvar_RegisterBool\n"
        "movl 0x12c(%ebx), %eax\n" /* line 1860 */
        "movl %eax, (%esp)\n"
        "calll FS_ConditionalRestart\n"
        "calll SEH_UpdateLanguageInfo\n" /* line 1861 */
        "movl $0, 4(%esp)\n" /* line 1865 */
        "movl 0x195ed18, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "calll CL_InitRef\n" /* line 1868 */
        "calll CL_StartHunkUsers\n" /* line 1870 */
        "movl (%ebx), %eax\n" /* line 1873 */
        "subl $6, %eax\n"
        "cmpl $0x7ffffff9, %eax\n"
        "jbe .Lf14beac_0014c116\n"
        ".Lf14beac_0014c06a:\n"
        "testl %edi, %edi\n" /* line 1883 | clientStateBuf */
        "je .Lf14beac_0014c085\n"
        "movl cl, %eax\n" /* line 1885 */
        "cmpb $0, 9(%eax)\n"
        "jne .Lf14beac_0014c231\n"
        ".Lf14beac_0014c07d:\n"
        "movl %edi, (%esp)\n" /* line 1890 | clientStateBuf */
        "calll Z_FreeInternal\n"
        /* } scope */
        ".Lf14beac_0014c085:\n"
        "addl $0x45c, %esp\n" /* line 1892 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14beac_0014c090:\n"
        "movl $0xa00000, (%esp)\n" /* line 1823 */
        "calll Z_VirtualAllocInternal\n"
        "movl $1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xa00000, 4(%esp)\n"
        "leal -0x2c(%ebp), %ebx\n" /* memFile */
        "movl %ebx, (%esp)\n"
        "calll MemFile_InitForWriting\n"
        "movl %ebx, (%esp)\n" /* line 1824 */
        "calll CL_ArchiveClientState\n"
        "movl -0x24(%ebp), %eax\n" /* line 1825 */
        "movl %eax, -0x43c(%ebp)\n" /* clientStateBytes */
        "movl %eax, (%esp)\n" /* line 1826 */
        "calll Z_MallocInternal\n"
        "movl %eax, %edi\n" /* clientStateBuf */
        "movl -0x43c(%ebp), %eax\n" /* line 1827 | clientStateBytes */
        "movl %eax, 8(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* memFile */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* clientStateBuf */
        "calll memcpy\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1828 | memFile */
        "movl %eax, (%esp)\n"
        "calll Z_VirtualFreeInternal\n"
        "jmp .Lf14beac_0014bee2\n"
        ".Lf14beac_0014c0ff:\n"
        "movl $0x2a96ac, (%esp)\n" /* line 1815 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 1892 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14beac_0014c116:\n"
        "calll CL_InitCGame\n" /* line 1875 */
        "calll FS_ReferencedIwdPureChecksums\n" /* line 1769 */
        "movl %eax, %ebx\n"
        "movl $0x2a96d8, 8(%esp)\n" /* line 1772 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x42c(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, 8(%esp)\n" /* line 1773 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        "xorl %ecx, %ecx\n"
        ".Lf14beac_0014c156:\n"
        "leal (%ecx, %esi), %edx\n" /* line 1807 */
        "movzbl (%edx), %eax\n" /* line 1776 */
        "leal 0xd(%eax, %ecx, 2), %eax\n"
        "movb %al, (%edx)\n"
        "addl $1, %ecx\n" /* line 1774 */
        "cmpl $2, %ecx\n"
        "jne .Lf14beac_0014c156\n"
        "movl clc, %ebx\n" /* line 651 */
        "movl 0x130(%ebx), %edx\n"
        "movl %edx, %eax\n"
        "subl 0x134(%ebx), %eax\n"
        "addl $-0x80, %eax\n"
        "jg .Lf14beac_0014c212\n"
        ".Lf14beac_0014c187:\n"
        "leal 1(%edx), %eax\n" /* line 655 */
        "movl %eax, 0x130(%ebx)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%ebx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MSG_WriteReliableCommandToBuffer\n"
        "jmp .Lf14beac_0014c06a\n"
        ".Lf14beac_0014c1bc:\n"
        "movl $0x2a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%ebx), %edx\n"
        "jmp .Lf14beac_0014bf8d\n"
        ".Lf14beac_0014c1db:\n"
        "calll CL_ShutdownCGame\n" /* line 1115 */
        "calll CL_ShutdownUI\n" /* line 1118 */
        "movl $0, 0x14c13b8\n" /* line 3267 */
        "movl $0, 0x14c13bc\n" /* line 3268 */
        "movl $0, 0x14c13c0\n" /* line 3269 */
        "movl $0, 0x1220964\n" /* line 1130 */
        "jmp .Lf14beac_0014bf1a\n"
        ".Lf14beac_0014c212:\n"
        "movl $0x2a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%ebx), %edx\n"
        "jmp .Lf14beac_0014c187\n"
        ".Lf14beac_0014c231:\n"
        "movl %edi, 8(%esp)\n" /* line 1887 | clientStateBuf */
        "movl -0x43c(%ebp), %eax\n" /* clientStateBytes */
        "movl %eax, 4(%esp)\n"
        "leal -0x2c(%ebp), %ebx\n" /* memFile */
        "movl %ebx, (%esp)\n"
        "calll MemFile_InitForReading\n"
        "movl %ebx, (%esp)\n" /* line 1888 */
        "calll CL_ArchiveClientState\n"
        "jmp .Lf14beac_0014c07d\n"
    );
}

/* line 1904 */
__attribute__((naked))
void CL_Snd_Restart_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1904 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl 0x195ecbc, %eax\n" /* line 1910 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf14c258_0014c282\n"
        "movl $0x2a96dc, (%esp)\n" /* line 1912 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1936 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14c258_0014c282:\n"
        "movl $0xa00000, (%esp)\n" /* line 1917 */
        "calll Z_VirtualAllocInternal\n"
        "movl $1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xa00000, 4(%esp)\n"
        "leal -0x2c(%ebp), %esi\n" /* memFile */
        "movl %esi, (%esp)\n"
        "calll MemFile_InitForWriting\n"
        "movl %esi, (%esp)\n" /* line 1918 */
        "calll SND_Save\n"
        "movl -0x24(%ebp), %eax\n" /* line 1919 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %edi\n"
        "movl -0x24(%ebp), %eax\n" /* line 1920 */
        "movl %eax, 8(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* memFile */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memcpy\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1921 | memFile */
        "movl %eax, (%esp)\n"
        "calll Z_VirtualFreeInternal\n"
        "leal -0x64(%ebp), %ebx\n" /* line 1923 | listeners */
        "movl %ebx, (%esp)\n"
        "calll SND_SaveListeners\n"
        "calll SND_Shutdown\n" /* line 1924 */
        "calll SND_Init\n" /* line 1925 */
        "movl %ebx, (%esp)\n" /* line 1926 */
        "calll SND_RestoreListeners\n"
        "calll CL_Vid_Restart_f\n" /* line 1930 */
        "movl %edi, 8(%esp)\n" /* line 1933 */
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MemFile_InitForReading\n"
        "movl %esi, (%esp)\n" /* line 1934 */
        "calll SND_Restore\n"
        "movl %edi, (%esp)\n" /* line 1935 */
        "calll Z_FreeInternal\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1936 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1381 */
__attribute__((naked))
void CL_Disconnect(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1381 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x195ecb4, %esi\n" /* line 1387 */
        "movl (%esi), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14c330_0014c47c\n"
        "movl 0x1501bbc, %edi\n" /* line 1390 */
        "testl %edi, %edi\n"
        "jne .Lf14c330_0014c564\n"
        "movl clc, %ebx\n" /* line 1396 */
        "movl 0x40144(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf14c330_0014c52e\n"
        ".Lf14c330_0014c36e:\n"
        "movb $0, 0x40248(%ebx)\n" /* line 1401 */
        "movb $0, 0x40148(%ebx)\n"
        "movl (%esi), %eax\n" /* line 1402 */
        "movb $0, 0x1c(%eax)\n"
        "movl 0x407b0(%ebx), %eax\n" /* line 1405 */
        "testl %eax, %eax\n"
        "jne .Lf14c330_0014c4f5\n"
        ".Lf14c330_0014c390:\n"
        "calll SCR_StopCinematic\n" /* line 1413 */
        "cmpl $4, (%ebx)\n" /* line 1417 */
        "jg .Lf14c330_0014c496\n"
        ".Lf14c330_0014c39e:\n"
        "movl clc, %ebx\n" /* line 1425 */
        "movl (%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl cl, %edi\n" /* line 1353 */
        "movzbl 9(%edi), %esi\n"
        "movzbl 0xa(%edi), %eax\n" /* line 1354 */
        "movb %al, -0x25(%ebp)\n"
        "movl 4(%edi), %eax\n" /* line 1355 */
        "movl %eax, -0x24(%ebp)\n"
        "movzbl 8(%edi), %eax\n" /* line 1356 */
        "movb %al, -0x1e(%ebp)\n"
        "movzbl (%edi), %eax\n" /* line 1357 */
        "movb %al, -0x1d(%ebp)\n"
        "movl $0x179c14, 8(%esp)\n" /* line 1359 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memset\n"
        "movl %esi, %eax\n" /* line 1361 */
        "movb %al, 9(%edi)\n"
        "movzbl -0x25(%ebp), %eax\n" /* line 1362 */
        "movb %al, 0xa(%edi)\n"
        "movl -0x24(%ebp), %eax\n" /* line 1363 */
        "movl %eax, 4(%edi)\n"
        "movzbl -0x1e(%ebp), %eax\n" /* line 1364 */
        "movb %al, 8(%edi)\n"
        "movzbl -0x1d(%ebp), %eax\n" /* line 1365 */
        "movb %al, (%edi)\n"
        "calll Com_ClientDObjClearAllSkel\n" /* line 1367 */
        "calll CL_ClearMutedList\n" /* line 1435 */
        "movl $0x48804, 8(%esp)\n" /* line 1439 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memset\n"
        "movl $0, (%ebx)\n" /* line 1441 */
        "calll SND_DisconnectListener\n" /* line 1442 */
        "cmpl $2, -0x1c(%ebp)\n" /* line 1443 */
        "jg .Lf14c330_0014c484\n"
        "calll Sys_IsMainThread\n" /* line 468 */
        "testb %al, %al\n"
        "jne .Lf14c330_0014c57f\n"
        ".Lf14c330_0014c444:\n"
        "movl $0, 4(%esp)\n" /* line 1459 */
        "movl 0x195f264, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "movl 0x195f430, %eax\n" /* line 1463 */
        "movl $0, (%eax)\n"
        "movl 0x195ecd0, %eax\n" /* line 1464 */
        "movl $0, (%eax)\n"
        "movl 0x195edb4, %eax\n" /* line 1492 */
        "movl $0, (%eax)\n"
        ".Lf14c330_0014c47c:\n"
        "addl $0x2c, %esp\n" /* line 1494 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14c330_0014c484:\n"
        "andl $1, 4(%edi)\n" /* line 1444 */
        "calll Sys_IsMainThread\n" /* line 468 */
        "testb %al, %al\n"
        "je .Lf14c330_0014c444\n"
        "jmp .Lf14c330_0014c57f\n"
        ".Lf14c330_0014c496:\n"
        "movl 0x130(%ebx), %edx\n" /* line 1417 */
        "movl %edx, %eax\n"
        "subl 0x134(%ebx), %eax\n"
        "addl $-0x80, %eax\n"
        "jg .Lf14c330_0014c39e\n"
        "leal 1(%edx), %eax\n" /* line 655 */
        "movl %eax, 0x130(%ebx)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%ebx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x228e90, (%esp)\n" /* "disconnect" */
        "calll MSG_WriteReliableCommandToBuffer\n"
        "calll CL_WritePacket\n" /* line 1420 */
        "calll CL_WritePacket\n" /* line 1421 */
        "calll CL_WritePacket\n" /* line 1422 */
        "jmp .Lf14c330_0014c39e\n"
        ".Lf14c330_0014c4f5:\n"
        "movl %eax, (%esp)\n" /* line 1407 */
        "calll FS_FCloseFile\n"
        "movl $0, 0x407b0(%ebx)\n" /* line 1408 */
        "movl $0, 0x407a0(%ebx)\n" /* line 1409 */
        "movl $0, 0x4079c(%ebx)\n" /* line 1410 */
        "calll SCR_StopCinematic\n" /* line 1413 */
        "cmpl $4, (%ebx)\n" /* line 1417 */
        "jle .Lf14c330_0014c39e\n"
        "jmp .Lf14c330_0014c496\n"
        ".Lf14c330_0014c52e:\n"
        "movl %eax, (%esp)\n" /* line 1398 */
        "calll FS_FCloseFile\n"
        "movl $0, 0x40144(%ebx)\n" /* line 1399 */
        "movb $0, 0x40248(%ebx)\n" /* line 1401 */
        "movb $0, 0x40148(%ebx)\n"
        "movl (%esi), %eax\n" /* line 1402 */
        "movb $0, 0x1c(%eax)\n"
        "movl 0x407b0(%ebx), %eax\n" /* line 1405 */
        "testl %eax, %eax\n"
        "je .Lf14c330_0014c390\n"
        "jmp .Lf14c330_0014c4f5\n"
        ".Lf14c330_0014c564:\n"
        "calll CL_StopRecord_f\n" /* line 1392 */
        "movl clc, %ebx\n" /* line 1396 */
        "movl 0x40144(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14c330_0014c36e\n"
        "jmp .Lf14c330_0014c52e\n"
        ".Lf14c330_0014c57f:\n"
        "calll UI_IsFullscreen\n" /* line 471 */
        "testl %eax, %eax\n"
        "jne .Lf14c330_0014c444\n"
        "cmpb $0, clients\n" /* line 476 */
        "je .Lf14c330_0014c444\n"
        "cmpl $2, clientConnections\n"
        "jle .Lf14c330_0014c444\n"
        "jmp .Lf14c330_0014c47c\n"
    );
}

/* line 4266 */
__attribute__((naked))
void CL_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4266 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $0x2a9704, (%esp)\n" /* line 4276 */
        "calll Com_Printf\n"
        "movl recursive, %eax\n" /* line 4278 */
        "testl %eax, %eax\n"
        "je .Lf14c5ac_0014c5d5\n"
        "movl $0x2a9720, (%esp)\n" /* line 4280 */
        "calll puts\n"
        /* } scope */
        "leave\n" /* line 4354 */
        "retl\n"
        /* { scope 1 */
        ".Lf14c5ac_0014c5d5:\n"
        "movl $1, recursive\n" /* line 4283 */
        "calll CL_Disconnect\n" /* line 4285 */
        "calll Sys_IsMainThread\n" /* line 468 */
        "testb %al, %al\n"
        "jne .Lf14c5ac_0014c831\n"
        ".Lf14c5ac_0014c5f1:\n"
        "calll CL_ShutdownDebugData\n" /* line 4289 */
        "movl 0x1220964, %eax\n" /* line 1108 */
        "testl %eax, %eax\n"
        "jne .Lf14c5ac_0014c85a\n"
        ".Lf14c5ac_0014c603:\n"
        "calll SND_Shutdown\n" /* line 4293 */
        "movl 0x121c7e8, %eax\n" /* line 3208 */
        "testl %eax, %eax\n"
        "je .Lf14c5ac_0014c613\n"
        "calll *%eax\n" /* line 3209 */
        ".Lf14c5ac_0014c613:\n"
        "movl re, %eax\n" /* line 3211 */
        "testl %eax, %eax\n"
        "je .Lf14c5ac_0014c641\n"
        "movl $1, (%esp)\n" /* line 3213 */
        "calll *%eax\n"
        "movl $0x160, 8(%esp)\n" /* line 3219 */
        "movl $0, 4(%esp)\n"
        "movl $re, (%esp)\n"
        "calll memset\n"
        ".Lf14c5ac_0014c641:\n"
        "calll StatMon_Reset\n" /* line 3223 */
        "calll CL_ShutdownInput\n" /* line 4296 */
        "movl $0x2a9034, (%esp)\n" /* line 4298 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9038, (%esp)\n" /* line 4299 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9048, (%esp)\n" /* line 4300 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9054, (%esp)\n" /* line 4302 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9060, (%esp)\n" /* line 4305 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x228e90, (%esp)\n" /* line 4307 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a906c, (%esp)\n" /* line 4308 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9080, (%esp)\n" /* line 4309 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a90a4, (%esp)\n" /* line 4310 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a90b8, (%esp)\n" /* line 4311 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9074, (%esp)\n" /* line 4312 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a90c0, (%esp)\n" /* line 4313 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a90c8, (%esp)\n" /* line 4314 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a90d4, (%esp)\n" /* line 4315 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a90e4, (%esp)\n" /* line 4316 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a6fbc, (%esp)\n" /* line 4317 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9118, (%esp)\n" /* line 4318 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a90f4, (%esp)\n" /* line 4319 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a90fc, (%esp)\n" /* line 4320 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9120, (%esp)\n" /* line 4321 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9128, (%esp)\n" /* line 4322 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9138, (%esp)\n" /* line 4323 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a914c, (%esp)\n" /* line 4325 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a915c, (%esp)\n" /* line 4326 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9734, (%esp)\n" /* line 4329 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9748, (%esp)\n" /* line 4330 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a975c, (%esp)\n" /* line 4331 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a916c, (%esp)\n" /* line 4334 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9770, (%esp)\n" /* line 4335 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9778, (%esp)\n" /* line 4336 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9180, (%esp)\n" /* line 4338 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a9190, (%esp)\n" /* line 4340 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a919c, (%esp)\n" /* line 4341 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a91c4, (%esp)\n" /* line 4343 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a91d0, (%esp)\n" /* line 4344 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a0ab4, 8(%esp)\n" /* line 4346 */
        "movl $0, 4(%esp)\n"
        "movl $cls, (%esp)\n"
        "calll memset\n"
        ".Lf14c5ac_0014c80b:\n"
        "movl 0x195ecb4, %eax\n" /* line 4349 */
        "movl (%eax), %eax\n"
        "movl $0, 4(%eax)\n"
        "movl $0, recursive\n" /* line 4351 */
        "movl $0x2a9788, (%esp)\n" /* line 4353 */
        "calll Com_Printf\n"
        /* } scope */
        "leave\n" /* line 4354 */
        "retl\n"
        /* { scope 1 */
        ".Lf14c5ac_0014c831:\n"
        "calll UI_IsFullscreen\n" /* line 471 */
        "testl %eax, %eax\n"
        "jne .Lf14c5ac_0014c5f1\n"
        "cmpb $0, clients\n" /* line 476 */
        "je .Lf14c5ac_0014c5f1\n"
        "cmpl $2, clientConnections\n"
        "jle .Lf14c5ac_0014c5f1\n"
        "jmp .Lf14c5ac_0014c80b\n"
        ".Lf14c5ac_0014c85a:\n"
        "calll CL_ShutdownCGame\n" /* line 1115 */
        "calll CL_ShutdownUI\n" /* line 1118 */
        "movl $0, 0x14c13b8\n" /* line 3267 */
        "movl $0, 0x14c13bc\n" /* line 3268 */
        "movl $0, 0x14c13c0\n" /* line 3269 */
        "movl $0, 0x1220964\n" /* line 1130 */
        "jmp .Lf14c5ac_0014c603\n"
    );
}

/* line 1721 */
__attribute__((naked))
void CL_Disconnect_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1721 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "calll SCR_StopCinematic\n" /* line 1725 */
        "movl clc, %eax\n" /* line 1727 */
        "movl (%eax), %ebx\n"
        "calll CL_Disconnect\n" /* line 1729 */
        "cmpl $2, %ebx\n" /* line 1731 */
        "ja .Lf14c892_0014c8b5\n"
        ".Lf14c892_0014c8af:\n"
        "addl $0x14, %esp\n" /* line 1735 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14c892_0014c8b5:\n"
        "calll Sys_IsMainThread\n" /* line 468 */
        "testb %al, %al\n"
        "jne .Lf14c892_0014c8d8\n"
        ".Lf14c892_0014c8be:\n"
        "movl $0x2a97a4, 4(%esp)\n" /* line 1733 */
        "movl $3, (%esp)\n"
        "calll Com_Error\n"
        "addl $0x14, %esp\n" /* line 1735 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14c892_0014c8d8:\n"
        "calll UI_IsFullscreen\n" /* line 471 */
        "testl %eax, %eax\n"
        "jne .Lf14c892_0014c8be\n"
        "cmpb $0, clients\n" /* line 476 */
        "je .Lf14c892_0014c8be\n"
        "cmpl $2, clientConnections\n"
        "jle .Lf14c892_0014c8be\n"
        "jmp .Lf14c892_0014c8af\n"
    );
}

/* line 1183 */
__attribute__((naked))
void CL_MapLoading(const char *mapname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1183 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0x195ecb4, %esi\n" /* line 1188 */
        "movl (%esi), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf14c8f6_0014c914\n"
        "addl $0x10, %esp\n" /* line 1269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14c8f6_0014c914:\n"
        "movb $0, g_waitingForServer\n" /* line 1191 */
        "calll Con_Close\n" /* line 1193 */
        "movl $0, 0x1509c44\n" /* line 1197 */
        "movb $0, 0x1509c48\n" /* line 1198 */
        "cmpl $4, clientConnections\n" /* line 1211 */
        "jg .Lf14c8f6_0014c9f6\n"
        ".Lf14c8f6_0014c93e:\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 1239 */
        "movl 0x195ee88, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $0x100, 8(%esp)\n" /* line 1240 */
        "movl $0x2a8ab8, 4(%esp)\n" /* "localhost" */
        "movl $0x1220968, (%esp)\n"
        "calll I_strncpyz\n"
        "calll CL_Disconnect\n" /* line 1249 */
        "calll UI_CloseAll\n" /* line 1251 */
        "movl clc, %eax\n" /* line 1253 */
        "movl $4, (%eax)\n"
        "movl $0xfffff448, 0x20(%eax)\n" /* line 1254 */
        "movl 0x195f368, %edx\n" /* line 1255 */
        "movl (%edx), %edx\n"
        "movl %edx, 4(%eax)\n"
        "addl $0x14, %eax\n" /* line 1256 */
        "movl %eax, 4(%esp)\n"
        "movl $0x1220968, (%esp)\n"
        "calll NET_StringToAdr\n"
        "calll CL_CheckForResend\n" /* line 1258 */
        "movl $0x40, 8(%esp)\n" /* line 1260 */
        "movl 8(%ebp), %eax\n" /* mapname */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ecb4, %ebx\n"
        "movl (%ebx), %eax\n"
        "addl $0x5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl (%ebx), %eax\n" /* line 1261 */
        "movb $0, 0xdc(%eax)\n"
        ".Lf14c8f6_0014c9db:\n"
        "movl $0, 4(%esp)\n" /* line 1268 */
        "movl $0, (%esp)\n"
        "calll SND_FadeAllSounds\n"
        "addl $0x10, %esp\n" /* line 1269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14c8f6_0014c9f6:\n"
        "movl $0x2a8ab8, 4(%esp)\n" /* line 1211 */
        "movl $0x1220968, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14c8f6_0014c93e\n"
        "movl clc, %ebx\n" /* line 1227 */
        "movl $5, (%ebx)\n"
        "leal 0x28(%ebx), %eax\n" /* line 1228 */
        "movl $0x100, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl cl, %eax\n" /* line 1229 */
        "addl $0x270c, %eax\n"
        "movl $0x5e84, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0xffffd8f1, 0xc(%ebx)\n" /* line 1230 */
        "movl $0x40, 8(%esp)\n" /* line 1232 */
        "movl 8(%ebp), %eax\n" /* mapname */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "addl $0x5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl (%esi), %eax\n" /* line 1233 */
        "movb $0, 0xdc(%eax)\n"
        "jmp .Lf14c8f6_0014c9db\n"
    );
}

/* line 886 */
__attribute__((naked))
void CL_DemoCompleted(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 886 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0x1501bc4, %eax\n" /* line 888 */
        "testl %eax, %eax\n"
        "jne .Lf14ca8c_0014cafe\n"
        "movl clc, %ebx\n"
        ".Lf14ca8c_0014caa2:\n"
        "movl 0x407b4(%ebx), %eax\n" /* line 899 */
        "testl %eax, %eax\n"
        "jne .Lf14ca8c_0014caea\n"
        ".Lf14ca8c_0014caac:\n"
        "calll SCR_StopCinematic\n" /* line 1725 */
        "movl (%ebx), %ebx\n" /* line 1727 */
        "calll CL_Disconnect\n" /* line 1729 */
        "cmpl $2, %ebx\n" /* line 1731 */
        "ja .Lf14ca8c_0014cac3\n"
        ".Lf14ca8c_0014cabd:\n"
        "addl $0x24, %esp\n" /* line 906 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14ca8c_0014cac3:\n"
        "calll Sys_IsMainThread\n" /* line 468 */
        "testb %al, %al\n"
        "jne .Lf14ca8c_0014cb58\n"
        ".Lf14ca8c_0014cad0:\n"
        "movl $0x2a97a4, 4(%esp)\n" /* line 1733 */
        "movl $3, (%esp)\n"
        "calll Com_Error\n"
        "addl $0x24, %esp\n" /* line 906 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14ca8c_0014caea:\n"
        "movl %eax, (%esp)\n" /* line 901 */
        "calll FS_FCloseFile\n"
        "movl $0, 0x407b4(%ebx)\n" /* line 902 */
        "jmp .Lf14ca8c_0014caac\n"
        /* { scope 1 */
        ".Lf14ca8c_0014cafe:\n"
        "calll Sys_Milliseconds\n" /* line 892 */
        "movl %eax, %edx\n"
        "movl clc, %ebx\n"
        "subl 0x407bc(%ebx), %edx\n"
        "testl %edx, %edx\n" /* line 893 */
        "jle .Lf14ca8c_0014caa2\n"
        "movl 0x407b8(%ebx), %eax\n" /* line 895 */
        "cvtsi2sdl %edx, %xmm1\n"
        "cvtsi2sdl %eax, %xmm0\n"
        "movsd 0x307d50, %xmm2\n" /* 1000.0 */
        "mulsd %xmm2, %xmm0\n"
        "divsd %xmm1, %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "divsd %xmm2, %xmm1\n"
        "movsd %xmm1, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2a97c4, (%esp)\n" /* "%i frames, %3.1f seconds: %3.1f fps
" */
        "calll Com_Printf\n"
        "jmp .Lf14ca8c_0014caa2\n"
        /* } scope */
        ".Lf14ca8c_0014cb58:\n"
        "calll UI_IsFullscreen\n" /* line 471 */
        "testl %eax, %eax\n"
        "jne .Lf14ca8c_0014cad0\n"
        "cmpb $0, clients\n" /* line 476 */
        "je .Lf14ca8c_0014cad0\n"
        "cmpl $2, clientConnections\n"
        "jle .Lf14ca8c_0014cad0\n"
        "jmp .Lf14ca8c_0014cabd\n"
    );
}

/* line 914 */
__attribute__((naked))
void CL_ReadDemoMessage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 914 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4030, %esp\n"
        /* { scope 1 */
        "movl 0x1501bd0, %eax\n" /* line 921 */
        "testl %eax, %eax\n"
        "je .Lf14cb84_0014cbb4\n"
        "movl %eax, 8(%esp)\n" /* line 928 */
        "movl $4, 4(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "cmpl $4, %eax\n" /* line 929 */
        "je .Lf14cb84_0014cbc3\n"
        ".Lf14cb84_0014cbb4:\n"
        "calll CL_DemoCompleted\n" /* line 960 */
        /* } scope */
        ".Lf14cb84_0014cbb9:\n"
        "addl $0x4030, %esp\n" /* line 977 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14cb84_0014cbc3:\n"
        "movl clc, %ebx\n" /* line 934 */
        "movl -0xc(%ebp), %eax\n" /* s */
        "movl %eax, 0x20138(%ebx)\n"
        "movl $0x4000, 8(%esp)\n" /* line 937 */
        "leal -0x4024(%ebp), %eax\n" /* bufData */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %esi\n" /* buf */
        "movl %esi, (%esp)\n"
        "calll MSG_Init\n"
        "movl 0x407b0(%ebx), %eax\n" /* line 940 */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x18(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "cmpl $4, %eax\n" /* line 941 */
        "jne .Lf14cb84_0014cbb4\n"
        "movl -0x18(%ebp), %eax\n" /* line 946 */
        "cmpl $-1, %eax\n" /* line 947 */
        "je .Lf14cb84_0014cbb4\n"
        "cmpl -0x1c(%ebp), %eax\n" /* line 952 */
        "jg .Lf14cb84_0014cc50\n"
        ".Lf14cb84_0014cc1e:\n"
        "movl 0x407b0(%ebx), %eax\n" /* line 956 */
        "movl %eax, 8(%esp)\n"
        "movl -0x18(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "cmpl -0x18(%ebp), %eax\n" /* line 957 */
        "je .Lf14cb84_0014cc66\n"
        "movl $0x2a981c, (%esp)\n" /* line 959 */
        "calll Com_Printf\n"
        "jmp .Lf14cb84_0014cbb4\n"
        ".Lf14cb84_0014cc50:\n"
        "movl $0x2a97ec, 4(%esp)\n" /* line 954 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14cb84_0014cc1e\n"
        ".Lf14cb84_0014cc66:\n"
        "movl 0x1220a78, %eax\n" /* line 964 */
        "movl %eax, 0x10(%ebx)\n"
        "movl $0, -0x14(%ebp)\n" /* line 965 */
        "movl %esi, (%esp)\n" /* line 968 */
        "calll MSG_ReadLong\n"
        "movl %eax, 0x134(%ebx)\n"
        "movl 0x130(%ebx), %edx\n" /* line 970 */
        "leal -0x80(%edx), %eax\n"
        "cmpl %eax, 0x134(%ebx)\n"
        "jge .Lf14cb84_0014cc9f\n"
        "movl %edx, 0x134(%ebx)\n" /* line 972 */
        "jmp .Lf14cb84_0014cbb9\n"
        ".Lf14cb84_0014cc9f:\n"
        "movl %esi, (%esp)\n" /* line 976 */
        "calll CL_ParseServerMessage\n"
        "jmp .Lf14cb84_0014cbb9\n"
    );
}

/* line 988 */
__attribute__((naked))
void CL_PlayDemo_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 988 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 993 */
        "cmpl $2, %eax\n"
        "je .Lf14ccac_0014cce9\n"
        "movl $0, (%esp)\n" /* line 995 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2a9838, (%esp)\n" /* "%s <demoname>
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x14c, %esp\n" /* line 1043 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14ccac_0014cce9:\n"
        "movl 0x195ecbc, %eax\n" /* line 999 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf14ccac_0014cd0d\n"
        "movl $0x2a9848, (%esp)\n" /* line 1001 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x14c, %esp\n" /* line 1043 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14ccac_0014cd0d:\n"
        "calll CL_Disconnect\n" /* line 1006 */
        "movl $1, (%esp)\n" /* line 1009 */
        "calll Cmd_Argv\n"
        "movl %eax, %esi\n" /* arg */
        "movl $1, 0xc(%esp)\n" /* line 1010 */
        "movl $0x2a986c, 8(%esp)\n" /* ".dm_%d" */
        "movl $0x20, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* extension */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x38(%ebp), %ecx\n" /* line 1011 | extension */
        "movl %ecx, 4(%esp)\n"
        "xorl %eax, %eax\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* arg */
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %edx\n"
        "notl %edx\n"
        "movl $0xffffffff, %ecx\n"
        "leal -0x38(%ebp), %edi\n" /* extension */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %esi, %eax\n" /* arg */
        "subl %ecx, %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14ccac_0014ce94\n"
        "movl %esi, 0xc(%esp)\n" /* line 1013 | arg */
        "movl $0x2a9874, 8(%esp)\n" /* "demos/%s" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x138(%ebp), %esi\n" /* name, arg */
        "movl %esi, (%esp)\n" /* arg */
        "calll Com_sprintf\n"
        ".Lf14ccac_0014cd9e:\n"
        "movl $1, 8(%esp)\n" /* line 1020 */
        "movl clc, %ebx\n"
        "leal 0x407b0(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* arg */
        "calll FS_FOpenFileRead\n"
        "movl 0x407b0(%ebx), %eax\n" /* line 1021 */
        "testl %eax, %eax\n"
        "je .Lf14ccac_0014cec3\n"
        ".Lf14ccac_0014cdcc:\n"
        "movl $1, (%esp)\n" /* line 1025 */
        "calll Cmd_Argv\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x4075c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "calll Con_Close\n" /* line 1027 */
        "movl $5, (%ebx)\n" /* line 1029 */
        "movl $1, 0x407a0(%ebx)\n" /* line 1030 */
        "movl $0, (%esp)\n" /* line 1031 */
        "calll Cmd_Argv\n"
        "movl $0x2a9088, 4(%esp)\n" /* "timedemo" */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0x407a4(%ebx)\n"
        "movl $1, (%esp)\n" /* line 1033 */
        "calll Cmd_Argv\n"
        "movl $0x100, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x1220968, (%esp)\n"
        "calll I_strncpyz\n"
        "movl (%ebx), %eax\n" /* line 1036 */
        "subl $5, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf14ccac_0014ce74\n"
        ".Lf14ccac_0014ce5f:\n"
        "movl $0, 0x407ac(%ebx)\n" /* line 1042 */
        /* } scope */
        "addl $0x14c, %esp\n" /* line 1043 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14ccac_0014ce74:\n"
        "calll CL_ReadDemoMessage\n" /* line 1038 */
        "movl (%ebx), %eax\n" /* line 1036 */
        "subl $5, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf14ccac_0014ce5f\n"
        "calll CL_ReadDemoMessage\n" /* line 1038 */
        "movl (%ebx), %eax\n" /* line 1036 */
        "subl $5, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf14ccac_0014ce74\n"
        "jmp .Lf14ccac_0014ce5f\n"
        ".Lf14ccac_0014ce94:\n"
        "movl $1, 0x10(%esp)\n" /* line 1017 */
        "movl %esi, 0xc(%esp)\n" /* arg */
        "movl $0x2a9238, 8(%esp)\n" /* "demos/%s.dm_%d" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x138(%ebp), %esi\n" /* name, arg */
        "movl %esi, (%esp)\n" /* arg */
        "calll Com_sprintf\n"
        "jmp .Lf14ccac_0014cd9e\n"
        ".Lf14ccac_0014cec3:\n"
        "movl %esi, 4(%esp)\n" /* line 1023 | arg */
        "movl $0x2a9880, (%esp)\n" /* "EXE_ERR_NOT_FOUND%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14ccac_0014cdcc\n"
    );
}

/* line 1506 */
__attribute__((naked))
void CL_ForwardCommandToServer(const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1506 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 1510 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* cmd */
        "movzbl (%eax), %eax\n" /* line 1513 */
        "cmpb $0x2d, %al\n"
        "je .Lf14cee8_0014cf2a\n"
        "movl clc, %esi\n" /* line 1518 */
        "movl 0x407a0(%esi), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf14cee8_0014cf1a\n"
        "cmpl $4, (%esi)\n"
        "jg .Lf14cee8_0014cf31\n"
        ".Lf14cee8_0014cf1a:\n"
        "movl %ebx, 4(%esp)\n" /* line 1520 | cmd */
        "movl $0x2a9898, (%esp)\n" /* "Unknown command "%s"
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf14cee8_0014cf2a:\n"
        "addl $0x10, %esp\n" /* line 1532 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14cee8_0014cf31:\n"
        "cmpb $0x2b, %al\n" /* line 1518 */
        "je .Lf14cee8_0014cf1a\n"
        "calll Cmd_Argc\n" /* line 1524 */
        "subl $1, %eax\n"
        "jle .Lf14cee8_0014cfa8\n"
        "movl 0x130(%esi), %edx\n" /* line 651 */
        "movl %edx, %eax\n"
        "subl 0x134(%esi), %eax\n"
        "addl $-0x80, %eax\n"
        "jg .Lf14cee8_0014cf8c\n"
        ".Lf14cee8_0014cf52:\n"
        "addl $1, %edx\n" /* line 655 */
        "movl %edx, 0x130(%esi)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%esi), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteReliableCommandToBuffer\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1532 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14cee8_0014cf8c:\n"
        "movl $0x2a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%esi), %edx\n"
        "jmp .Lf14cee8_0014cf52\n"
        ".Lf14cee8_0014cfa8:\n"
        "movl 0x130(%esi), %edx\n" /* line 651 */
        "movl %edx, %eax\n"
        "subl 0x134(%esi), %eax\n"
        "addl $-0x80, %eax\n"
        "jg .Lf14cee8_0014cff0\n"
        ".Lf14cee8_0014cfbb:\n"
        "leal 1(%edx), %eax\n" /* line 655 */
        "movl %eax, 0x130(%esi)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%esi), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MSG_WriteReliableCommandToBuffer\n"
        "jmp .Lf14cee8_0014cf2a\n"
        ".Lf14cee8_0014cff0:\n"
        "movl $0x2a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%esi), %edx\n"
        "jmp .Lf14cee8_0014cfbb\n"
    );
}

/* line 1647 */
__attribute__((naked))
void CL_ForwardToServer_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1647 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "cmpl $8, clientConnections\n" /* line 1649 */
        "je .Lf14d00c_0014d030\n"
        ".Lf14d00c_0014d01d:\n"
        "movl $0x2a8b24, (%esp)\n" /* line 1651 */
        "calll Com_Printf\n"
        ".Lf14d00c_0014d029:\n"
        "addl $0x10, %esp\n" /* line 1660 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14d00c_0014d030:\n"
        "movl 0x1501bc0, %ecx\n" /* line 1649 */
        "testl %ecx, %ecx\n"
        "jne .Lf14d00c_0014d01d\n"
        "calll Cmd_Argc\n" /* line 1656 */
        "subl $1, %eax\n"
        "jle .Lf14d00c_0014d029\n"
        "movl $1, (%esp)\n" /* line 1658 */
        "calll Cmd_Args\n"
        "movl %eax, %esi\n" /* cmd */
        /* { scope 1 */
        "movl clc, %ebx\n" /* line 651 */
        "movl 0x130(%ebx), %edx\n"
        "movl %edx, %eax\n"
        "subl 0x134(%ebx), %eax\n"
        "addl $-0x80, %eax\n"
        "jg .Lf14d00c_0014d0a2\n"
        ".Lf14d00c_0014d06b:\n"
        "leal 1(%edx), %eax\n" /* line 655 */
        "movl %eax, 0x130(%ebx)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%ebx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MSG_WriteReliableCommandToBuffer\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1660 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14d00c_0014d0a2:\n"
        "movl $0x2a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%ebx), %edx\n"
        "jmp .Lf14d00c_0014d06b\n"
    );
}

/* line 2020 */
__attribute__((naked))
void CL_DownloadsComplete(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2020 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x490, %esp\n"
        /* { scope 1 */
        "movl 0x1501b78, %esi\n" /* line 2059 */
        "testl %esi, %esi\n"
        "jne .Lf14d0be_0014d28b\n"
        "movl $6, clientConnections\n" /* line 2081 */
        "movl 0x195ecbc, %eax\n" /* line 2083 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf14d0be_0014d1d2\n"
        "movl cl, %eax\n" /* line 2119 */
        "cmpb $0, 9(%eax)\n"
        "jne .Lf14d0be_0014d1c8\n"
        ".Lf14d0be_0014d101:\n"
        "movl $1, 4(%esp)\n" /* line 2123 */
        "movl 0x195ed18, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "calll CL_InitCGame\n" /* line 2126 */
        "calll FS_ReferencedIwdPureChecksums\n" /* line 1769 */
        "movl %eax, %ebx\n"
        "movl $0x2a96d8, 8(%esp)\n" /* line 1772 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x488(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, 8(%esp)\n" /* line 1773 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        "xorl %ecx, %ecx\n"
        ".Lf14d0be_0014d158:\n"
        "leal (%ecx, %esi), %edx\n" /* line 2020 */
        "movzbl (%edx), %eax\n" /* line 1776 */
        "leal 0xd(%eax, %ecx, 2), %eax\n"
        "movb %al, (%edx)\n"
        "addl $1, %ecx\n" /* line 1774 */
        "cmpl $2, %ecx\n"
        "jne .Lf14d0be_0014d158\n"
        "movl clc, %ebx\n" /* line 651 */
        "movl 0x130(%ebx), %edx\n"
        "movl %edx, %eax\n"
        "subl 0x134(%ebx), %eax\n"
        "addl $-0x80, %eax\n"
        "jg .Lf14d0be_0014d335\n"
        ".Lf14d0be_0014d189:\n"
        "leal 1(%edx), %eax\n" /* line 655 */
        "movl %eax, 0x130(%ebx)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%ebx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MSG_WriteReliableCommandToBuffer\n"
        "calll CL_WritePacket\n" /* line 2133 */
        "calll CL_WritePacket\n" /* line 2134 */
        "calll CL_WritePacket\n" /* line 2135 */
        /* } scope */
        ".Lf14d0be_0014d1c8:\n"
        "addl $0x490, %esp\n" /* line 2136 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14d0be_0014d1d2:\n"
        "movl $0, (%esp)\n" /* line 2085 */
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n" /* info */
        "movl $0x2a7124, 4(%esp)\n" /* line 2086 */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %esi\n" /* mapname */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x2a7100, 4(%esp)\n" /* line 2087 */
        "movl %ebx, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x88(%ebp), %ebx\n" /* gametype, info */
        "movl %ebx, (%esp)\n" /* info */
        "calll I_strncpyz\n"
        "movl %ebx, 4(%esp)\n" /* line 2095 | info */
        "movl %esi, (%esp)\n"
        "calll UI_SetMap\n"
        "calll SCR_UpdateScreenInternal\n" /* line 2096 */
        "movl 0x121c7e8, %eax\n" /* line 1141 */
        "testl %eax, %eax\n"
        "je .Lf14d0be_0014d24d\n"
        "calll *%eax\n" /* line 1142 */
        ".Lf14d0be_0014d24d:\n"
        "movl 0x1220964, %ebx\n" /* line 1108 */
        "testl %ebx, %ebx\n"
        "jne .Lf14d0be_0014d2fe\n"
        ".Lf14d0be_0014d25b:\n"
        "movl re, %eax\n" /* line 1147 */
        "testl %eax, %eax\n"
        "je .Lf14d0be_0014d26d\n"
        "movl $0, (%esp)\n" /* line 1149 */
        "calll *%eax\n"
        ".Lf14d0be_0014d26d:\n"
        "movl $0, 0x1220a68\n" /* line 1156 */
        "calll Com_Restart\n" /* line 2103 */
        "calll CL_StartHunkUsers\n" /* line 2111 */
        "calll SCR_UpdateScreenInternal\n" /* line 2113 */
        "jmp .Lf14d0be_0014d101\n"
        ".Lf14d0be_0014d28b:\n"
        "movl $0, 0x1501b78\n" /* line 2062 */
        "movl clc, %ebx\n" /* line 2064 | info */
        "movl 0x12c(%ebx), %eax\n" /* info */
        "movl %eax, (%esp)\n"
        "calll FS_Restart\n"
        "movl 0x130(%ebx), %edx\n" /* line 651 */
        "movl %edx, %eax\n"
        "subl 0x134(%ebx), %eax\n"
        "addl $-0x80, %eax\n"
        "jg .Lf14d0be_0014d354\n"
        ".Lf14d0be_0014d2c0:\n"
        "leal 1(%edx), %eax\n" /* line 655 */
        "movl %eax, 0x130(%ebx)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%ebx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2a98b0, (%esp)\n" /* "donedl" */
        "calll MSG_WriteReliableCommandToBuffer\n"
        /* } scope */
        "addl $0x490, %esp\n" /* line 2136 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14d0be_0014d2fe:\n"
        "calll CL_ShutdownCGame\n" /* line 1115 */
        "calll CL_ShutdownUI\n" /* line 1118 */
        "movl $0, 0x14c13b8\n" /* line 3267 */
        "movl $0, 0x14c13bc\n" /* line 3268 */
        "movl $0, 0x14c13c0\n" /* line 3269 */
        "movl $0, 0x1220964\n" /* line 1130 */
        "jmp .Lf14d0be_0014d25b\n"
        ".Lf14d0be_0014d335:\n"
        "movl $0x2a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%ebx), %edx\n"
        "jmp .Lf14d0be_0014d189\n"
        ".Lf14d0be_0014d354:\n"
        "movl $0x2a8a5c, 4(%esp)\n" /* "EXE_ERR_CLIENT_CMD_OVERFLOW" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%ebx), %edx\n"
        "jmp .Lf14d0be_0014d2c0\n"
    );
}

/* line 2149 */
__attribute__((naked))
void CL_BeginDownload(const char *localName, const char *remoteName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2149 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* localName */
        "movl 0xc(%ebp), %esi\n" /* remoteName */
        "movl %esi, 8(%esp)\n" /* line 2152 | remoteName */
        "movl %ebx, 4(%esp)\n" /* localName */
        "movl $0x2a98b8, (%esp)\n" /* "***** CL_BeginDownload *****
Localname: %s
Remotename: %s
**" */
        "calll Com_DPrintf\n"
        "movl $0x100, 8(%esp)\n" /* line 2154 */
        "movl %ebx, 4(%esp)\n" /* localName */
        "movl clc, %edi\n"
        "leal 0x40248(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %ebx, 0xc(%esp)\n" /* line 2155 | localName */
        "movl $0x2a9910, 8(%esp)\n" /* "%s.tmp" */
        "movl $0x100, 4(%esp)\n"
        "leal 0x40148(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $0x40, 8(%esp)\n" /* line 2158 */
        "movl %esi, 4(%esp)\n" /* remoteName */
        "movl 0x195ecb4, %ebx\n" /* localName */
        "movl (%ebx), %eax\n" /* localName */
        "addl $0x1c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl (%ebx), %eax\n" /* line 2159 | localName */
        "movl $0, 0x10(%eax)\n"
        "movl (%ebx), %eax\n" /* line 2160 | localName */
        "movl $0, 0x14(%eax)\n"
        "movl (%ebx), %edx\n" /* line 2161 | localName */
        "movl 0x1220a78, %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl $0, 0x4034c(%edi)\n" /* line 2163 */
        "movl $0, 0x40350(%edi)\n" /* line 2164 */
        "movl %esi, 4(%esp)\n" /* line 2166 | remoteName */
        "movl $0x2a9918, (%esp)\n" /* "download %s" */
        "calll va\n"
        "movl %eax, %ebx\n" /* cmd */
        /* { scope 1 */
        "movl 0x130(%edi), %edx\n" /* line 651 */
        "movl %edx, %eax\n"
        "subl 0x134(%edi), %eax\n"
        "addl $-0x80, %eax\n"
        "jle .Lf14d374_0014d467\n"
        "movl $0x2a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%edi), %edx\n"
        ".Lf14d374_0014d467:\n"
        "leal 1(%edx), %eax\n" /* line 655 */
        "movl %eax, 0x130(%edi)\n"
        "movl $0x400, 8(%esp)\n" /* line 657 */
        "movl 0x130(%edi), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MSG_WriteReliableCommandToBuffer\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2167 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2177 */
__attribute__((naked))
void CL_NextDownload(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2177 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "cmpb $0, 0x1501778\n" /* line 2183 */
        "je .Lf14d4a0_0014d54f\n"
        "movl $0x1501778, -0x1c(%ebp)\n" /* line 2191 | s */
        "cmpb $0x40, 0x1501778\n"
        "movl $0x1501779, %eax\n"
        "cmovnel -0x1c(%ebp), %eax\n" /* s */
        "movl %eax, -0x1c(%ebp)\n" /* s */
        "movl $0x40, 4(%esp)\n" /* line 2195 */
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf14d4a0_0014d54f\n"
        "movb $0, (%eax)\n" /* line 2201 */
        "leal 1(%eax), %esi\n"
        "movl $0x40, 4(%esp)\n" /* line 2203 */
        "movl %esi, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf14d4a0_0014d55b\n"
        "movb $0, (%eax)\n" /* line 2204 */
        "leal 1(%eax), %ebx\n"
        ".Lf14d4a0_0014d504:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2208 | s */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CL_BeginDownload\n"
        "movl clc, %edx\n" /* line 2210 */
        "movl $1, 0x40758(%edx)\n"
        "cld\n" /* line 2213 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "addl $0x40358, %edx\n"
        "movl %edx, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2219 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14d4a0_0014d54f:\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CL_DownloadsComplete\n" /* line 2218 */
        ".Lf14d4a0_0014d55b:\n"
        "cld\n" /* line 2206 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %esi), %ebx\n"
        "jmp .Lf14d4a0_0014d504\n"
    );
}

/* line 2230 */
__attribute__((naked))
void CL_InitDownloads(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2230 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x410, %esp\n"
        /* { scope 1 */
        "movl $7, 4(%esp)\n" /* line 2234 */
        "movl $0x2a9924, (%esp)\n" /* "ni]Zm^l" */
        "calll FS_ShiftStr\n"
        "movl 0x195ecbc, %eax\n" /* line 2249 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf14d570_0014d5a7\n"
        "movl cl_allowDownload, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf14d570_0014d5ea\n"
        ".Lf14d570_0014d5a7:\n"
        "movl $0, 8(%esp)\n" /* line 2257 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* missingfiles */
        "movl %ebx, (%esp)\n"
        "calll FS_CompareIwds\n"
        "testl %eax, %eax\n"
        "jne .Lf14d570_0014d5d8\n"
        ".Lf14d570_0014d5c9:\n"
        "calll CL_DownloadsComplete\n" /* line 2279 */
        /* } scope */
        ".Lf14d570_0014d5ce:\n"
        "addl $0x410, %esp\n" /* line 2280 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14d570_0014d5d8:\n"
        "movl %ebx, 4(%esp)\n" /* line 2261 */
        "movl $0x2a992c, (%esp)\n" /* "
WARNING: You are missing some files referenced by the serve" */
        "calll Com_Printf\n"
        "jmp .Lf14d570_0014d5c9\n"
        ".Lf14d570_0014d5ea:\n"
        "movl $1, 8(%esp)\n" /* line 2264 */
        "movl $0x400, 4(%esp)\n"
        "movl clc, %ebx\n"
        "leal 0x40358(%ebx), %esi\n"
        "movl %esi, (%esp)\n"
        "calll FS_CompareIwds\n"
        "testl %eax, %eax\n"
        "je .Lf14d570_0014d5c9\n"
        "movl %esi, 4(%esp)\n" /* line 2266 */
        "movl $0x218054, (%esp)\n" /* "Need iwds: %s
" */
        "calll Com_Printf\n"
        "cmpb $0, 0x40358(%ebx)\n" /* line 2268 */
        "je .Lf14d570_0014d5c9\n"
        "movl $5, (%ebx)\n" /* line 2271 */
        "calll CL_NextDownload\n" /* line 2272 */
        "jmp .Lf14d570_0014d5ce\n"
    );
}

