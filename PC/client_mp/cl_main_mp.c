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
extern void Dvar_SetInt(const dvar_t *dvar, int value);
extern void Dvar_SetBool(const dvar_t *dvar, int value);
extern void Dvar_SetString(const dvar_t *dvar, const char *value);
extern void UI_SetMap(const char *mapname, const char *gametype);
extern void SCR_UpdateScreenInternal(void);
extern void SetScreenScaling(float safeAreaH, float safeAreaV, int vpX, int vpY, int vpW, int vpH);
extern void SND_Init(void);
extern void SND_StopSounds(int);
extern void SND_FadeAllSounds(float, float);
extern void SND_Shutdown(void);
extern void SND_Save(void *memFile);
extern void SND_Restore(void *memFile);
extern void SND_SaveListeners(void *listeners);
extern void SND_RestoreListeners(void *listeners);
extern void SND_DisconnectListener(void);
extern void CL_InitUI(void);
extern void Sys_LoadingKeepAlive(void);
extern void SCR_Init(void);
extern void SCR_StopCinematic(void);
extern void Con_Init(void);
extern void Con_Close(void);
extern void CL_InitInput(void);
extern void CL_ShutdownInput(void);
extern void CL_RconInit(void);
extern void CL_ClearMutedList(void);
extern void CL_SetADS(int);
extern void CL_SetCGameTime(void);
extern void CL_SendCmd(void);
extern void CL_WritePacket(void);
extern void CL_UpdateColor(void);
extern void CL_InitCGame(void);
extern void UI_CloseAll(void);
extern void UI_DrawConnectScreen(void);
extern void Cbuf_Execute(void);
extern void Cbuf_ExecuteText(int, const char *);
extern void Com_DPrintf(const char *fmt, ...);
extern void Com_PrintMessage(int, const char *);
extern void Com_Restart(void);
extern const dvar_t *Dvar_RegisterBool_mac(const char *name, int defaultValue, int flags);
extern const dvar_t *Dvar_RegisterInt(const char *name, int defaultValue, int min, int max, int flags);
extern const dvar_t *Dvar_RegisterFloat(const char *name, float defaultValue, float min, float max, int flags);
extern const dvar_t *Dvar_RegisterString_mac(const char *name, const char *defaultValue, int flags);
extern int Dvar_GetBool(const char *name);
extern void Cmd_AddCommand(const char *name, void (*cmd)(void));
extern void Cmd_RemoveCommand(const char *name);
extern void Cmd_SetAutoComplete(const char *cmd, const char *dir, const char *ext);
extern char *Cmd_Args(int start);
extern int atoi(const char *);
extern double atof(const char *);
extern int I_stricmp(const char *a, const char *b);
extern int I_strncmp(const char *a, const char *b, int n);
extern void Info_SetValueForKey(char *s, const char *key, const char *value);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern void Com_Memset(void *dest, int c, int count);
extern int NET_CompareAdr(int t1, int a1, int p1, int t2, int a2, int p2);
extern int NET_CompareBaseAdr(int t1, int a1, int p1, int t2, int a2, int p2);
extern const char *NET_AdrToString(int type, int addr, int port);
extern int NET_StringToAdr(const char *s, void *a);
extern void NET_OutOfBandPrint(int sock, int type, int addr, int port, const char *data);
extern void NET_OutOfBandData(int sock, int type, int addr, int port, const char *data, int len);
extern int Sys_IsLANAddress(int type, int addr, int port);
extern int Sys_Milliseconds(void);
extern int Sys_MillisecondsRaw(void);
extern void srand(unsigned int seed);
extern int FS_FileExists(const char *path);
extern int FS_FOpenFileWrite(const char *path);
extern int FS_FOpenFileRead(const char *path, int *file, int uniqueFILE);
extern int FS_Read(void *buffer, int len, int f);
extern int FS_ConditionalRestart(int checksumFeed);
extern void FS_Restart(int checksumFeed);
extern const char *FS_ReferencedIwdPureChecksums(void);
extern int FS_CompareIwds(char *buf, int bufLen, int flag);
extern void FS_ShiftStr(const char *name, int shift);
extern void MSG_Init(void *msg, void *data, int length);
extern void MSG_WriteLong(void *msg, int value);
extern void MSG_WriteShort(void *msg, int value);
extern void MSG_WriteByte(void *msg, int value);
extern void MSG_WriteBigString(void *msg, const char *s);
extern void MSG_WriteDeltaEntity(void *msg, void *from, void *to, int force);
extern int MSG_ReadLong(msg_t *msg);
extern const char *MSG_ReadStringLine(msg_t *msg);
extern const char *MSG_ReadBigString(msg_t *msg);
extern void MSG_BeginReading(msg_t *msg);
extern int MSG_WriteBitsCompress(void *src, void *dst, int len);
extern void CL_SetServerInfoByAddress(int type, int addr, int port, const char *info, int ping);
extern void Netchan_Setup(int sock, void *chan, int type, int addr, int port, int qport);
extern int Netchan_Process(void *chan, msg_t *msg);
extern void CL_Netchan_AddOOBProfilePacket(int size);
extern void CL_Netchan_Decode(void *data, int len);
extern void CL_Netchan_SendOOBPacket(int len, const char *data, int type, int addr, int port);
extern int CL_CDKeyValidate(void *cdkey, void *checksum);
extern void CL_ServerInfoPacket(int type, int addr, int port, msg_t *msg, int time);
extern void CL_ServerStatusResponse(int type, int addr, int port, msg_t *msg);
extern void CL_ServersResponsePacket(int type, int addr, int port, msg_t *msg);
extern const char *CL_GetConfigString(int index);
extern void CL_ParseServerMessage(msg_t *msg);
extern void CL_ArchiveClientState(void *memFile);
extern void LargeLocal_LargeLocal(void *ll, int size);
extern void *LargeLocal_GetBuf(void *ll);
extern void ZN10LargeLocalD1Ev(void *ll);
extern void Cmd_TokenizeString(const char *text);
extern refexport_t GetRefAPI(int apiVersion, void *ri);
extern void MemFile_InitForWriting(void *mf, void *buf, int size, int flag);
extern void MemFile_InitForReading(void *mf, void *buf, int size);
extern void *Z_MallocInternal(int size);
extern void *Z_VirtualAllocInternal(int size);
extern void Z_VirtualFreeInternal(void *ptr);
extern void CG_CalculateFPS(void);
extern void Voice_GetLocalVoiceData(void *dest);
extern void Voice_Playback(void);
extern void SEH_UpdateLanguageInfo(void);
extern void SEH_LocalizeTextMessage(const char *ref, const char *defaultText, int flags);
extern char *strchr(const char *, int);
extern float floorf(float);

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
extern void Com_ClientDObjClearAllSkel(void);
extern Bool g_waitingForServer; /* 0x0 */
extern ping_t cl_pinglist[16]; /* 0x0 */
extern unsigned int frame_msec; /* 0x0 */
extern int old_com_frameTime; /* 0x0 */
static char szServerIPAddress[128]; /* szServerIPAddress */
static qboolean recursive; /* recursive */
static const dvar_t *input_viewSensitivity; /* input_viewSensitivity */

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
void CL_RefPrintf(int print_level, const char *fmt, ...);
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
    if (*(int *)((char *)&clientConnections + 304) - *(int *)((char *)&clientConnections + 308) - 128 > 0)
    {
        Com_Error(1, "CL_AddReliableCommand: too many commands");
    }
    *(int *)((byte *)clc + 0x130) += 1;
    index = *(int *)((byte *)clc + 0x130) & 0x7f;
    MSG_WriteReliableCommandToBuffer(cmd, (char *)((byte *)clc + 0x138 + index * 0x400), 0x400);
}

/* line 700 */
void CL_StopRecord_f(void)
{
    byte *cc = (byte *)&clientConnections[0];
    int len;

    if (!*(int *)(cc + 0x4079c)) {
        Com_Printf(str_002a8a78);
        return;
    }

    len = -1;
    FS_Write(&len, 4, *(int *)(cc + 0x407b0));
    FS_Write(&len, 4, *(int *)(cc + 0x407b0));
    FS_FCloseFile(*(int *)(cc + 0x407b0));
    *(int *)(cc + 0x407b0) = 0;
    *(int *)(cc + 0x4079c) = 0;
    Com_Printf(str_002a8a90);
}

/* line 1161 */
void CL_ShutdownDemo(void)
{
    if (!*(int *)((char *)&clientConnections + 264112))
        return;
    FS_FCloseFile(*(int *)((char *)&clientConnections + 264112));
    *(int *)((byte *)clc + 0x407b0) = 0;
    *(int *)((byte *)clc + 0x407a0) = 0;
    *(int *)((byte *)clc + 0x4079c) = 0;
}

/* line 1272 */
int CL_GetSkelTimeStamp(int localClientNum)
{
    char *client = (char *)&clients + (unsigned)localClientNum * 386821 * 4;
    return *(int *)(client + 0x864c);
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
void CL_ClearState(void)
{
    byte *cl = (byte *)&clients[0];
    byte cgameInitialized, cgameInitCalled, displayHUD, active;
    int keyCatchers;

    /* Save fields that survive the clear */
    cgameInitialized = cl[9];
    cgameInitCalled = cl[10];
    keyCatchers = *(int *)(cl + 4);
    displayHUD = cl[8];
    active = cl[0];

    memset(&clients[0], 0, 0x179c14);

    /* Restore preserved fields */
    cl = (byte *)&clients[0];
    cl[9] = cgameInitialized;
    cl[10] = cgameInitCalled;
    *(int *)(cl + 4) = keyCatchers;
    cl[8] = displayHUD;
    cl[0] = active;

    Com_ClientDObjClearAllSkel();
}

/* line 1669 */
extern int Cmd_Argc(void);
extern char *Cmd_Argv(int arg);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void I_strncat(char *dest, int maxlen, const char *src);
extern int putenv(const char *string);
extern char *getenv(const char *name);
void CL_Setenv_f(void)
{
    char buffer[1024];
    int argc, i;
    const char *env;

    argc = Cmd_Argc();

    if (argc > 2) {
        /* Set environment variable: "setenv VAR value1 value2 ..." */
        I_strncpyz(buffer, Cmd_Argv(1), 0x400);
        I_strncat(buffer, 0x400, str_00222904); /* "=" */
        for (i = 2; i < argc; i++) {
            I_strncat(buffer, 0x400, Cmd_Argv(i));
            I_strncat(buffer, 0x400, str_00217914); /* " " */
        }
        putenv(buffer);
    } else if (argc == 2) {
        /* Print environment variable */
        env = getenv(Cmd_Argv(1));
        if (env)
            Com_Printf(str_002a8aa0, Cmd_Argv(1), env);
        else
            Com_Printf(str_002a8aa8, Cmd_Argv(1));
    }
}

/* line 1744 */
extern void Cbuf_AddText(const char *text);
extern const char *va(const char *fmt, ...);
void CL_Reconnect_f(void)
{
    char *server = (char *)&cls + 8;

    /* Don't reconnect to empty or localhost */
    if (!*server || !memcmp(server, str_002a8ab8, 10)) {
        Com_Printf(str_002a8ac4);
        return;
    }

    Cbuf_AddText(va(str_002a8ae4, server));
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
void CL_Configstrings_f(void)
{
    int i;
    byte *cl;
    int offset;

    if (*(int *)&clientConnections[0] != 8) {
        Com_Printf(str_002a8b24);
        return;
    }

    cl = *(byte **)imp_cl;
    for (i = 0; i < 0x800; i++) {
        offset = *(int *)(cl + 0x270c + i * 4);
        if (offset)
            Com_Printf(str_002a8b40, i, cl + 0x470c + offset);
    }
}

/* line 1998 */
extern const char *Dvar_InfoString(int bit);
extern void Info_Print(const char *s);
void CL_Clientinfo_f(void)
{
    Com_Printf(str_002a8b4c);
    Com_Printf(str_002a8b74, **(int **)imp_clc);
    Com_Printf(str_002a74a0, (char *)&cls + 8);
    Com_Printf(str_002a8b80);
    Info_Print(Dvar_InfoString(2));
    Com_Printf(str_002a8b98);
}

/* line 2413 */
extern int MSG_ReadByte(msg_t *msg);
extern void MSG_ReadData(msg_t *msg, void *data, int len);
extern Bool CL_IsPlayerMuted(int clientNum);
extern void Voice_IncomingVoiceData(int talker, const byte *data, int dataLen);
void CL_VoicePacket(msg_t *msg)
{
    byte voiceData[256];
    int numPackets, packet, talker, dataLen;

    numPackets = MSG_ReadByte(msg);
    if (numPackets > 40 || numPackets <= 0)
        return;

    for (packet = 0; packet < numPackets; packet++) {
        talker = MSG_ReadByte(msg);
        dataLen = MSG_ReadByte(msg);

        if (dataLen < 1 || dataLen > 256) {
            Com_Printf(str_002a8bc0, dataLen);
            return;
        }

        MSG_ReadData(msg, voiceData, dataLen);

        if (talker > 63) {
            Com_Printf(str_002a8bec, talker);
            return;
        }

        if (CL_IsPlayerMuted(talker))
            continue;
        if (!cl_voice->current.enabled)
            continue;

        Voice_IncomingVoiceData(talker, voiceData, dataLen);
    }
}

/* line 2463 */
Bool CL_IsPlayerTalking(int clientIndex)
{
    return Voice_IsClientTalking(clientIndex);
}

/* line 4736 */
void CL_SetupForNewServerMap(const char *pszMapName, const char *pszGametype)
{
    byte *hacks = *(byte **)imp_legacyHacks;

    Com_Printf("Server changing map %s, gametype %s\n", pszMapName, pszGametype);
    I_strncpyz((char *)(hacks + 0x5c), pszMapName, 0x40);
    I_strncpyz((char *)(hacks + 0x9c), pszGametype, 0x40);
    *(byte *)(hacks + 0xdc) = 0;

    if (!(*(const dvar_t **)imp_com_sv_running)->current.enabled) {
        Dvar_SetInt(*(const dvar_t **)imp_com_expectedHunkUsage, 0);
        g_waitingForServer = 1;
    }

    UI_SetMap(pszMapName, pszGametype);
    SCR_UpdateScreenInternal();
}

/* line 2894 */
extern void CL_WriteVoicePacket(void);
void CL_VoiceTransmit(void)
{
    byte *cl = *(byte **)imp_cl;
    int voiceLen = *(int *)(cl + 0x179c0c);

    if (voiceLen <= 0)
        return;

    /* Send if enough time passed or enough data buffered */
    if (*(int *)((byte *)&clients[0] + 9968) - *(int *)(cl + 0x179c10) > 199 || voiceLen > 9) {
        CL_WriteVoicePacket();
        cl = *(byte **)imp_cl;
        *(int *)(cl + 0x179c0c) = 0;
        *(int *)(cl + 0x179c10) = *(int *)(cl + 0x26f0);
    }
}

/* line 2927 */
extern int Dvar_GetInt(const char *name);
extern Bool IsTalking(void);
Bool Voice_SendVoiceData(void)
{
    /* Check sv_voice and cl_voice dvars */
    if (!(*(const dvar_t **)imp_sv_voice)->current.enabled)
        return 0;
    if (!cl_voice->current.enabled)
        return 0;

    /* Check voice rate limit */
    if (Dvar_GetInt(str_002a8c54) <= 0x1387)
        return 0;

    /* Must be fully connected */
    if (**(int **)imp_clc != 8)
        return 0;

    /* Check if actively talking or have buffered data */
    if ((*(const dvar_t **)imp_cl_talking)->current.enabled)
        return 1;
    if (IsTalking())
        return 1;
    if (*(int *)(*(byte **)imp_cl + 0x179c0c))
        return 1;

    return 0;
}

/* line 4979 */
void CL_SyncGpu(void)
{
    ((void (*)(void))*(int *)((char *)&re + 340))();
}

/* line 3141 */
void CL_SetRecommended_f(void)
{
    Com_SetRecommended(1);
}

/* line 3181 */
void CL_RefPrintf(int print_level, const char *fmt, ...)
{
    char msg[4096];
    __builtin_va_list argptr;

    __builtin_va_start(argptr, fmt);
    vsnprintf(msg, sizeof(msg), fmt, argptr);
    __builtin_va_end(argptr);

    switch (print_level) {
        case 0: Com_Printf("%s", msg); break;
        case 1: Com_DPrintf("^1%s", msg); break;
        case 2: Com_Printf("^3%s", msg); break;
        case 3: Com_Printf("^1%s", msg); break;
        default: break;
    }
}

/* line 3206 */
extern void StatMon_Reset(void);
extern refexport_t re;
void CL_ShutdownRef(void)
{
    void (*shutdownInput)(void) = *(void (**)(void))((char *)&re + 328);
    void (*shutdown)(int) = *(void (**)(int))&re;

    if (shutdownInput)
        shutdownInput();

    if (shutdown) {
        shutdown(1);
        memset(&re, 0, 0x160);
    }

    StatMon_Reset();
}

/* line 3236 */
void CL_InitRenderer(void)
{
    int fieldWidth;

    /* re.BeginRegistration */
    ((void (*)(int *))*(int *)((char *)&re + 4))((int *)((char *)&cls + 0x2a0a64));
    /* Parameters: safeAreaH, safeAreaV, viewportX, viewportY, viewportW, viewportH */
    {
        int vw = *(int *)((char *)&cls + 0x2a0a64); /* vidConfig.width from BeginRegistration output */
        int vh = *(int *)((char *)&cls + 0x2a0a68); /* vidConfig.height */
        SetScreenScaling(1.0f, 1.0f, 0, 0, vw, vh);
    }

    /* cls.charSetShader = re.RegisterShaderNoMip("white", 3, 3) */
    *(int *)((char *)&cls + 0x2a0a58) = ((int (*)(const char *, int, int))*(int *)((char *)&re + 16))("white", 3, 3);
    /* cls.whiteShader = re.RegisterShaderNoMip("console", 3, 3) */
    *(int *)((char *)&cls + 0x2a0a5c) = ((int (*)(const char *, int, int))*(int *)((char *)&re + 16))("console", 3, 3);
    /* cls.consoleFont = re.RegisterFont("fonts/consoleFont", 3) */
    *(int *)((char *)&cls + 0x2a0a60) = ((int (*)(const char *, int))*(int *)((char *)&re + 224))("fonts/consoleFont", 3);

    fieldWidth = *(int *)((char *)&cls + 0x2a0a64) - 0x20;
    *(int *)imp_g_console_field_width = fieldWidth;

    *(int *)((char *)imp_g_consoleField + 0xc) = fieldWidth;
    *(int *)((char *)imp_g_consoleField + 0x10) = *(int *)imp_g_console_char_height;
    *(int *)((char *)imp_g_consoleField + 0x14) = 1;

    StatMon_Reset();
}

/* line 3342 */
void CL_StartHunkUsers(void)
{
    byte *hacks = *(byte **)imp_legacyHacks;

    if (!*(int *)(hacks + 4))
        return;

    if (!*(int *)((char *)&cls + 268)) {
        *(int *)((char *)&cls + 268) = 1;
        SND_Init();
        Sys_LoadingKeepAlive();
    }

    if (!*(int *)((char *)&cls + 264)) {
        *(int *)((char *)&cls + 264) = 1;
        CL_InitRenderer();
        Sys_LoadingKeepAlive();
    }

    if (!*(int *)((char *)&cls + 272)) {
        CL_InitUI();
        Sys_LoadingKeepAlive();
    }

    *(int *)((char *)&cls + 4) = 1;
}

/* line 3386 */
int CL_ScaledMilliseconds(void)
{
    return *(int *)((char *)&cls + 280);
}

/* line 3422 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void CL_InitRef(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3422 */
        "movl %esp, %ebp\n"
        "subl $0x238, %esp\n"
        /* { scope 1 */
        "movl $str_002a8c88, (%esp)\n" /* line 3432 */
        "calll Com_Printf\n"
        "movl imp_Cmd_AddCommand, %eax\n" /* line 3439 */
        "movl %eax, -0x12c(%ebp)\n"
        "movl imp_Cmd_RemoveCommand, %eax\n" /* line 3440 */
        "movl %eax, -0x128(%ebp)\n"
        "movl imp_Cmd_Argc, %eax\n" /* line 3441 */
        "movl %eax, -0x124(%ebp)\n"
        "movl imp_Cmd_Argv, %eax\n" /* line 3442 */
        "movl %eax, -0x120(%ebp)\n"
        "movl imp_Cbuf_ExecuteText, %eax\n" /* line 3443 */
        "movl %eax, -0x11c(%ebp)\n"
        "movl $CL_RefPrintf, -0x224(%ebp)\n" /* line 3444 | ri */
        "movl imp_Com_Error, %eax\n" /* line 3445 */
        "movl %eax, -0x220(%ebp)\n"
        "movl $CL_ScaledMilliseconds, -0x21c(%ebp)\n" /* line 3446 */
        "movl imp_Hunk_AllocInternal, %eax\n" /* line 3458 */
        "movl %eax, -0x218(%ebp)\n"
        "movl imp_Hunk_AllocateTempMemoryInternal, %eax\n" /* line 3459 */
        "movl %eax, -0x214(%ebp)\n"
        "movl imp_Z_MallocInternal, %eax\n" /* line 3460 */
        "movl %eax, -0x210(%ebp)\n"
        "movl imp_Z_FreeInternal, %eax\n" /* line 3461 */
        "movl %eax, -0x20c(%ebp)\n"
        "movl imp_Hunk_AllocAlignInternal, %eax\n" /* line 3462 */
        "movl %eax, -0x208(%ebp)\n"
        "movl imp_Z_VirtualReserveInternal, %eax\n" /* line 3463 */
        "movl %eax, -0x204(%ebp)\n"
        "movl imp_Z_VirtualCommitInternal, %eax\n" /* line 3464 */
        "movl %eax, -0x200(%ebp)\n"
        "movl imp_Z_VirtualDecommitInternal, %eax\n" /* line 3465 */
        "movl %eax, -0x1fc(%ebp)\n"
        "movl imp_Z_VirtualFreeInternal, %eax\n" /* line 3466 */
        "movl %eax, -0x1f8(%ebp)\n"
        "movl imp_Hunk_FreeTempMemory, %eax\n" /* line 3468 */
        "movl %eax, -0x1f4(%ebp)\n"
        "movl imp_Hunk_AllocateTempMemoryHighInternal, %eax\n" /* line 3475 */
        "movl %eax, -0x1e4(%ebp)\n"
        "movl imp_Hunk_ClearTempMemory, %eax\n" /* line 3478 */
        "movl %eax, -0x1f0(%ebp)\n"
        "movl imp_Hunk_ClearTempMemoryHigh, %eax\n" /* line 3479 */
        "movl %eax, -0x1e0(%ebp)\n"
        "movl imp_Sys_DirectXFatalError, %eax\n" /* line 3494 */
        "movl %eax, -0x1dc(%ebp)\n"
        "movl imp_Sys_ShowSplashWindow, %eax\n" /* line 3495 */
        "movl %eax, -0x1d8(%ebp)\n"
        "movl imp_Sys_HideSplashWindow, %eax\n" /* line 3496 */
        "movl %eax, -0x1d4(%ebp)\n"
        "movl imp_Sys_LoadingKeepAlive, %eax\n" /* line 3499 */
        "movl %eax, -0x1d0(%ebp)\n"
        "movl imp_FS_ReadFile, %eax\n" /* line 3500 */
        "movl %eax, -0xfc(%ebp)\n"
        "movl imp_FS_FreeFile, %eax\n" /* line 3501 */
        "movl %eax, -0xf8(%ebp)\n"
        "movl imp_FS_FOpenFileRead, %eax\n" /* line 3502 */
        "movl %eax, -0xf4(%ebp)\n"
        "movl imp_FS_WriteFile, %eax\n" /* line 3503 */
        "movl %eax, -0xe4(%ebp)\n"
        "movl imp_FS_FreeFileList, %eax\n" /* line 3505 */
        "movl %eax, -0xec(%ebp)\n"
        "movl imp_FS_ListFiles, %eax\n" /* line 3506 */
        "movl %eax, -0xf0(%ebp)\n"
        "movl imp_FS_FileExists, %eax\n" /* line 3507 */
        "movl %eax, -0xe8(%ebp)\n"
        "movl imp_FS_FOpenFileByMode, %eax\n" /* line 3509 */
        "movl %eax, -0xe0(%ebp)\n"
        "movl imp_FS_FCloseFile, %eax\n" /* line 3510 */
        "movl %eax, -0xdc(%ebp)\n"
        "movl imp_FS_Read, %eax\n" /* line 3511 */
        "movl %eax, -0xd8(%ebp)\n"
        "movl imp_FS_Write, %eax\n" /* line 3512 */
        "movl %eax, -0xd4(%ebp)\n"
        "movl imp_CM_SaveLump, %eax\n" /* line 3515 */
        "movl %eax, -0xd0(%ebp)\n"
        "movl imp_CM_BoxTrace, %eax\n" /* line 3518 */
        "movl %eax, -0xcc(%ebp)\n"
        "movl imp_CM_BoxSightTrace, %eax\n" /* line 3519 */
        "movl %eax, -0xc8(%ebp)\n"
        "movl imp_Dvar_RegisterBool, %eax\n" /* line 3521 */
        "movl %eax, -0x1cc(%ebp)\n"
        "movl imp_Dvar_RegisterInt, %eax\n" /* line 3522 */
        "movl %eax, -0x1c8(%ebp)\n"
        "movl imp_Dvar_RegisterFloat, %eax\n" /* line 3523 */
        "movl %eax, -0x1c4(%ebp)\n"
        "movl imp_Dvar_RegisterString, %eax\n" /* line 3524 */
        "movl %eax, -0x1c0(%ebp)\n"
        "movl imp_Dvar_RegisterEnum, %eax\n" /* line 3525 */
        "movl %eax, -0x1bc(%ebp)\n"
        "movl imp_Dvar_RegisterColor, %eax\n" /* line 3526 */
        "movl %eax, -0x1b8(%ebp)\n"
        "movl imp_Dvar_RegisterVec2, %eax\n" /* line 3527 */
        "movl %eax, -0x1b4(%ebp)\n"
        "movl imp_Dvar_RegisterVec3, %eax\n" /* line 3528 */
        "movl %eax, -0x1b0(%ebp)\n"
        "movl imp_Dvar_RegisterVec4, %eax\n" /* line 3529 */
        "movl %eax, -0x1ac(%ebp)\n"
        "movl imp_Dvar_ClearModified, %eax\n" /* line 3530 */
        "movl %eax, -0x19c(%ebp)\n"
        "movl imp_Dvar_SetModified, %eax\n" /* line 3531 */
        "movl %eax, -0x198(%ebp)\n"
        "movl imp_Dvar_UpdateEnumDomain, %eax\n" /* line 3532 */
        "movl %eax, -0x194(%ebp)\n"
        "movl imp_Dvar_UnregisterSystem, %eax\n" /* line 3533 */
        "movl %eax, -0x1a8(%ebp)\n"
        "movl imp_Dvar_ChangeResetValue, %eax\n" /* line 3534 */
        "movl %eax, -0x1a4(%ebp)\n"
        "movl imp_Dvar_IsAtDefaultValue, %eax\n" /* line 3535 */
        "movl %eax, -0x1a0(%ebp)\n"
        "movl imp_Dvar_SetBool, %eax\n" /* line 3536 */
        "movl %eax, -0x190(%ebp)\n"
        "movl imp_Dvar_SetInt, %eax\n" /* line 3537 */
        "movl %eax, -0x18c(%ebp)\n"
        "movl imp_Dvar_SetFloat, %eax\n" /* line 3538 */
        "movl %eax, -0x188(%ebp)\n"
        "movl imp_Dvar_SetString, %eax\n" /* line 3539 */
        "movl %eax, -0x184(%ebp)\n"
        "movl imp_Dvar_SetColor, %eax\n" /* line 3540 */
        "movl %eax, -0x180(%ebp)\n"
        "movl imp_Dvar_SetVec2, %eax\n" /* line 3541 */
        "movl %eax, -0x17c(%ebp)\n"
        "movl imp_Dvar_SetVec3, %eax\n" /* line 3542 */
        "movl %eax, -0x178(%ebp)\n"
        "movl imp_Dvar_SetVec4, %eax\n" /* line 3543 */
        "movl %eax, -0x174(%ebp)\n"
        "movl imp_Dvar_SetFromString, %eax\n" /* line 3544 */
        "movl %eax, -0x170(%ebp)\n"
        "movl imp_Dvar_SetBoolByName, %eax\n" /* line 3545 */
        "movl %eax, -0x16c(%ebp)\n"
        "movl imp_Dvar_SetIntByName, %eax\n" /* line 3546 */
        "movl %eax, -0x168(%ebp)\n"
        "movl imp_Dvar_SetFloatByName, %eax\n" /* line 3547 */
        "movl %eax, -0x164(%ebp)\n"
        "movl imp_Dvar_SetStringByName, %eax\n" /* line 3548 */
        "movl %eax, -0x160(%ebp)\n"
        "movl imp_Dvar_SetColorByName, %eax\n" /* line 3549 */
        "movl %eax, -0x15c(%ebp)\n"
        "movl imp_Dvar_SetVec2ByName, %eax\n" /* line 3550 */
        "movl %eax, -0x158(%ebp)\n"
        "movl imp_Dvar_SetVec3ByName, %eax\n" /* line 3551 */
        "movl %eax, -0x154(%ebp)\n"
        "movl imp_Dvar_SetVec4ByName, %eax\n" /* line 3552 */
        "movl %eax, -0x150(%ebp)\n"
        "movl imp_Dvar_SetFromStringByName, %eax\n" /* line 3553 */
        "movl %eax, -0x14c(%ebp)\n"
        "movl imp_Dvar_GetBool, %eax\n" /* line 3554 */
        "movl %eax, -0x148(%ebp)\n"
        "movl imp_Dvar_GetInt, %eax\n" /* line 3555 */
        "movl %eax, -0x144(%ebp)\n"
        "movl imp_Dvar_GetFloat, %eax\n" /* line 3556 */
        "movl %eax, -0x140(%ebp)\n"
        "movl imp_Dvar_GetString, %eax\n" /* line 3557 */
        "movl %eax, -0x13c(%ebp)\n"
        "movl imp_Dvar_GetVariantString, %eax\n" /* line 3558 */
        "movl %eax, -0x138(%ebp)\n"
        "movl imp_Dvar_EnumToString, %eax\n" /* line 3559 */
        "movl %eax, -0x134(%ebp)\n"
        "movl imp_Dvar_Reset, %eax\n" /* line 3560 */
        "movl %eax, -0x130(%ebp)\n"
        "movl imp_Com_SaveDvarsToBuffer, %eax\n" /* line 3562 */
        "movl %eax, -0x118(%ebp)\n"
        "movl imp_Com_LoadDvarsFromBuffer, %eax\n" /* line 3563 */
        "movl %eax, -0x114(%ebp)\n"
        "movl imp_Com_GetBsp, %eax\n" /* line 3565 */
        "movl %eax, -0x110(%ebp)\n"
        "movl imp_SEH_ReadCharFromString, %eax\n" /* line 3570 */
        "movl %eax, -0x10c(%ebp)\n"
        "movl $CL_UpdateDebugData, -0x108(%ebp)\n" /* line 3572 */
        "movl $CL_FlushDebugData, -0x104(%ebp)\n" /* line 3573 */
        "movl imp_StatMon_Warning, %eax\n" /* line 3574 */
        "movl %eax, -0x100(%ebp)\n"
        "movl imp_XModelPrecache, %eax\n" /* line 3587 */
        "movl %eax, -0xc0(%ebp)\n"
        "movl imp_XModelGetSurfaces, %eax\n" /* line 3588 */
        "movl %eax, -0xbc(%ebp)\n"
        "movl imp_XModelBad, %eax\n" /* line 3589 */
        "movl %eax, -0xb8(%ebp)\n"
        "movl imp_Hunk_OverrideDataForFile, %eax\n" /* line 3590 */
        "movl %eax, -0xb4(%ebp)\n"
        "movl imp_XModelGetNumLods, %eax\n" /* line 3591 */
        "movl %eax, -0xb0(%ebp)\n"
        "movl imp_XModelSetTestLods, %eax\n" /* line 3592 */
        "movl %eax, -0xac(%ebp)\n"
        "movl imp_XModelGetLodForDist, %eax\n" /* line 3593 */
        "movl %eax, -0xa8(%ebp)\n"
        "movl imp_XModelGetLodOutDist, %eax\n" /* line 3594 */
        "movl %eax, -0xa4(%ebp)\n"
        "movl imp_XModelGetSurfaceName, %eax\n" /* line 3595 */
        "movl %eax, -0xa0(%ebp)\n"
        "movl imp_XModelGetName, %eax\n" /* line 3596 */
        "movl %eax, -0x9c(%ebp)\n"
        "movl imp_XModelGetFlags, %eax\n" /* line 3597 */
        "movl %eax, -0x98(%ebp)\n"
        "movl imp_XModelNumBones, %eax\n" /* line 3598 */
        "movl %eax, -0x94(%ebp)\n"
        "movl imp_XModelGetSkins, %eax\n" /* line 3599 */
        "movl %eax, -0x90(%ebp)\n"
        "movl imp_XModelGetMemUsage, %eax\n" /* line 3600 */
        "movl %eax, -0x8c(%ebp)\n"
        "movl imp_XModelGetLodName, %eax\n" /* line 3602 */
        "movl %eax, -0x88(%ebp)\n"
        "movl imp_XModelGetBasePose, %eax\n" /* line 3603 */
        "movl %eax, -0x84(%ebp)\n"
        "movl imp_XModelGetBasePoseBone, %eax\n" /* line 3604 */
        "movl %eax, -0x80(%ebp)\n"
        "movl imp_DObjBad, %eax\n" /* line 3607 */
        "movl %eax, -0x7c(%ebp)\n"
        "movl imp_DObjGetBounds, %eax\n" /* line 3610 */
        "movl %eax, -0x74(%ebp)\n"
        "movl imp_DObjGetSurface, %eax\n" /* line 3611 */
        "movl %eax, -0x70(%ebp)\n"
        "movl imp_DObjGetNumModels, %eax\n" /* line 3612 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl imp_DObjGetNumSurfaces, %eax\n" /* line 3613 */
        "movl %eax, -0x68(%ebp)\n"
        "movl imp_DObjGetSurfaces, %eax\n" /* line 3614 */
        "movl %eax, -0x64(%ebp)\n"
        "movl imp_DObjGetModel, %eax\n" /* line 3616 */
        "movl %eax, -0x50(%ebp)\n"
        "movl imp_DObjGetSurfaceName, %eax\n" /* line 3617 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl imp_DObjCreate, %eax\n" /* line 3618 */
        "movl %eax, -0x48(%ebp)\n"
        "movl imp_DObjGetAllocSkelSize, %eax\n" /* line 3619 */
        "movl %eax, -0x44(%ebp)\n"
        "movl imp_DObjCreateSkel, %eax\n" /* line 3620 */
        "movl %eax, -0x40(%ebp)\n"
        "movl imp_DObjCalcAnim, %eax\n" /* line 3621 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl imp_DObjCalcSkel, %eax\n" /* line 3622 */
        "movl %eax, -0x38(%ebp)\n"
        "movl imp_DObjGetRotTransArray, %eax\n" /* line 3623 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl imp_DObjSkelAreBonesUpToDate, %eax\n" /* line 3624 */
        "movl %eax, -0x58(%ebp)\n"
        "movl imp_DObjGetMatOffset, %eax\n" /* line 3625 */
        "movl %eax, -0x54(%ebp)\n"
        "movl imp_DObjNumBones, %eax\n" /* line 3626 */
        "movl %eax, -0x34(%ebp)\n"
        "movl imp_DObjGetBoneInfo, %eax\n" /* line 3627 */
        "movl %eax, -0x30(%ebp)\n"
        "movl imp_DObjGetLodForDist, %eax\n" /* line 3628 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl imp_DObjGetLodOutDist, %eax\n" /* line 3629 */
        "movl %eax, -0x28(%ebp)\n"
        "movl imp_DObjCompleteHierarchyBits, %eax\n" /* line 3630 */
        "movl %eax, -0x24(%ebp)\n"
        "movl imp_DObjSetModel, %eax\n" /* line 3631 */
        "movl %eax, -0x20(%ebp)\n"
        "movl imp_CIN_UploadCinematic, %eax\n" /* line 3634 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl imp_CIN_PlayCinematic, %eax\n" /* line 3635 */
        "movl %eax, -0x18(%ebp)\n"
        "movl imp_CIN_RunCinematic, %eax\n" /* line 3636 */
        "movl %eax, -0x14(%ebp)\n"
        "movl imp_CG_DObjCalcPose, %eax\n" /* line 3638 */
        "movl %eax, -0x10(%ebp)\n"
        "movl imp_CL_GetHudMsgIconMaterialName, %eax\n" /* line 3708 */
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
        "movl imp_cl_paused, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        /* } scope */
        "leave\n" /* line 3735 */
        "retl\n"
    );
}
#else
void CL_InitRef(void) {
    refimport_t ri_local;
    void *ret;

    Com_Printf("----- Initializing Renderer ----\n");

    /* Fill refimport function pointer table */
    ri_local.Cmd_AddCommand = *(void **)imp_Cmd_AddCommand;
    ri_local.Cmd_RemoveCommand = *(void **)imp_Cmd_RemoveCommand;
    ri_local.Cmd_Argc = *(void **)imp_Cmd_Argc;
    ri_local.Cmd_Argv = *(void **)imp_Cmd_Argv;
    ri_local.Cbuf_ExecuteText = *(void **)imp_Cbuf_ExecuteText;
    ri_local.Printf = (void *)CL_RefPrintf;
    ri_local.Error = *(void **)imp_Com_Error;
    ri_local.Milliseconds = (void *)CL_ScaledMilliseconds;
    ri_local.Hunk_AllocInternal = *(void **)imp_Hunk_AllocInternal;
    ri_local.Hunk_AllocateTempMemoryInternal = *(void **)imp_Hunk_AllocateTempMemoryInternal;
    ri_local.Z_MallocInternal = *(void **)imp_Z_MallocInternal;
    ri_local.Z_FreeInternal = *(void **)imp_Z_FreeInternal;
    ri_local.Hunk_AllocAlignInternal = *(void **)imp_Hunk_AllocAlignInternal;
    ri_local.Z_VirtualReserveInternal = *(void **)imp_Z_VirtualReserveInternal;
    ri_local.Z_VirtualCommitInternal = *(void **)imp_Z_VirtualCommitInternal;
    ri_local.Z_VirtualDecommitInternal = *(void **)imp_Z_VirtualDecommitInternal;
    ri_local.Z_VirtualFreeInternal = *(void **)imp_Z_VirtualFreeInternal;
    ri_local.Hunk_FreeTempMemory = *(void **)imp_Hunk_FreeTempMemory;
    ri_local.Hunk_AllocateTempMemoryHighInternal = *(void **)imp_Hunk_AllocateTempMemoryHighInternal;
    ri_local.Hunk_ClearTempMemory = *(void **)imp_Hunk_ClearTempMemory;
    ri_local.Hunk_ClearTempMemoryHigh = *(void **)imp_Hunk_ClearTempMemoryHigh;
    ri_local.Sys_DirectXFatalError = *(void **)imp_Sys_DirectXFatalError;
    ri_local.Sys_ShowSplashWindow = *(void **)imp_Sys_ShowSplashWindow;
    ri_local.Sys_HideSplashWindow = *(void **)imp_Sys_HideSplashWindow;
    ri_local.Sys_LoadingKeepAlive = *(void **)imp_Sys_LoadingKeepAlive;
    ri_local.FS_ReadFile = *(void **)imp_FS_ReadFile;
    ri_local.FS_FreeFile = *(void **)imp_FS_FreeFile;
    ri_local.FS_FOpenFileRead = *(void **)imp_FS_FOpenFileRead;
    ri_local.FS_WriteFile = *(void **)imp_FS_WriteFile;
    ri_local.FS_FreeFileList = *(void **)imp_FS_FreeFileList;
    ri_local.FS_ListFiles = *(void **)imp_FS_ListFiles;
    ri_local.FS_FileExists = *(void **)imp_FS_FileExists;
    ri_local.FS_FOpenFileByMode = *(void **)imp_FS_FOpenFileByMode;
    ri_local.FS_FCloseFile = *(void **)imp_FS_FCloseFile;
    ri_local.FS_Read = *(void **)imp_FS_Read;
    ri_local.FS_Write = *(void **)imp_FS_Write;
    ri_local.CM_SaveLump = *(void **)imp_CM_SaveLump;
    ri_local.CM_BoxTrace = *(void **)imp_CM_BoxTrace;
    ri_local.CM_BoxSightTrace = *(void **)imp_CM_BoxSightTrace;
    ri_local.Dvar_RegisterBool = *(void **)imp_Dvar_RegisterBool;
    ri_local.Dvar_RegisterInt = *(void **)imp_Dvar_RegisterInt;
    ri_local.Dvar_RegisterFloat = *(void **)imp_Dvar_RegisterFloat;
    ri_local.Dvar_RegisterString = *(void **)imp_Dvar_RegisterString;
    ri_local.Dvar_RegisterEnum = *(void **)imp_Dvar_RegisterEnum;
    ri_local.Dvar_RegisterColor = *(void **)imp_Dvar_RegisterColor;
    ri_local.Dvar_RegisterVec2 = *(void **)imp_Dvar_RegisterVec2;
    ri_local.Dvar_RegisterVec3 = *(void **)imp_Dvar_RegisterVec3;
    ri_local.Dvar_RegisterVec4 = *(void **)imp_Dvar_RegisterVec4;
    ri_local.Dvar_ClearModified = *(void **)imp_Dvar_ClearModified;
    ri_local.Dvar_SetModified = *(void **)imp_Dvar_SetModified;
    ri_local.Dvar_UpdateEnumDomain = *(void **)imp_Dvar_UpdateEnumDomain;
    ri_local.Dvar_UnregisterSystem = *(void **)imp_Dvar_UnregisterSystem;
    ri_local.Dvar_ChangeResetValue = *(void **)imp_Dvar_ChangeResetValue;
    ri_local.Dvar_IsAtDefaultValue = *(void **)imp_Dvar_IsAtDefaultValue;
    ri_local.Dvar_SetBool = *(void **)imp_Dvar_SetBool;
    ri_local.Dvar_SetInt = *(void **)imp_Dvar_SetInt;
    ri_local.Dvar_SetFloat = *(void **)imp_Dvar_SetFloat;
    ri_local.Dvar_SetString = *(void **)imp_Dvar_SetString;
    ri_local.Dvar_SetColor = *(void **)imp_Dvar_SetColor;
    ri_local.Dvar_SetVec2 = *(void **)imp_Dvar_SetVec2;
    ri_local.Dvar_SetVec3 = *(void **)imp_Dvar_SetVec3;
    ri_local.Dvar_SetVec4 = *(void **)imp_Dvar_SetVec4;
    ri_local.Dvar_SetFromString = *(void **)imp_Dvar_SetFromString;
    ri_local.Dvar_SetBoolByName = *(void **)imp_Dvar_SetBoolByName;
    ri_local.Dvar_SetIntByName = *(void **)imp_Dvar_SetIntByName;
    ri_local.Dvar_SetFloatByName = *(void **)imp_Dvar_SetFloatByName;
    ri_local.Dvar_SetStringByName = *(void **)imp_Dvar_SetStringByName;
    ri_local.Dvar_SetColorByName = *(void **)imp_Dvar_SetColorByName;
    ri_local.Dvar_SetVec2ByName = *(void **)imp_Dvar_SetVec2ByName;
    ri_local.Dvar_SetVec3ByName = *(void **)imp_Dvar_SetVec3ByName;
    ri_local.Dvar_SetVec4ByName = *(void **)imp_Dvar_SetVec4ByName;
    ri_local.Dvar_SetFromStringByName = *(void **)imp_Dvar_SetFromStringByName;
    ri_local.Dvar_GetBool = *(void **)imp_Dvar_GetBool;
    ri_local.Dvar_GetInt = *(void **)imp_Dvar_GetInt;
    ri_local.Dvar_GetFloat = *(void **)imp_Dvar_GetFloat;
    ri_local.Dvar_GetString = *(void **)imp_Dvar_GetString;
    ri_local.Dvar_GetVariantString = *(void **)imp_Dvar_GetVariantString;
    ri_local.Dvar_EnumToString = *(void **)imp_Dvar_EnumToString;
    ri_local.Dvar_Reset = *(void **)imp_Dvar_Reset;
    ri_local.Com_SaveDvarsToBuffer = *(void **)imp_Com_SaveDvarsToBuffer;
    ri_local.Com_LoadDvarsFromBuffer = *(void **)imp_Com_LoadDvarsFromBuffer;
    ri_local.Com_GetBsp = *(void **)imp_Com_GetBsp;
    ri_local.SEH_ReadCharFromString = *(void **)imp_SEH_ReadCharFromString;
    ri_local.CL_UpdateDebugData = (void *)CL_UpdateDebugData;
    ri_local.CL_FlushDebugData = (void *)CL_FlushDebugData;
    ri_local.StatMon_Warning = *(void **)imp_StatMon_Warning;
    ri_local.XModelPrecache = *(void **)imp_XModelPrecache;
    ri_local.XModelGetSurfaces = *(void **)imp_XModelGetSurfaces;
    ri_local.XModelBad = *(void **)imp_XModelBad;
    ri_local.Hunk_OverrideDataForFile = *(void **)imp_Hunk_OverrideDataForFile;
    ri_local.XModelGetNumLods = *(void **)imp_XModelGetNumLods;
    ri_local.XModelSetTestLods = *(void **)imp_XModelSetTestLods;
    ri_local.XModelGetLodForDist = *(void **)imp_XModelGetLodForDist;
    ri_local.XModelGetLodOutDist = *(void **)imp_XModelGetLodOutDist;
    ri_local.XModelGetSurfaceName = *(void **)imp_XModelGetSurfaceName;
    ri_local.XModelGetName = *(void **)imp_XModelGetName;
    ri_local.XModelGetFlags = *(void **)imp_XModelGetFlags;
    ri_local.XModelNumBones = *(void **)imp_XModelNumBones;
    ri_local.XModelGetSkins = *(void **)imp_XModelGetSkins;
    ri_local.XModelGetMemUsage = *(void **)imp_XModelGetMemUsage;
    ri_local.XModelGetLodName = *(void **)imp_XModelGetLodName;
    ri_local.XModelGetBasePose = *(void **)imp_XModelGetBasePose;
    ri_local.XModelGetBasePoseBone = *(void **)imp_XModelGetBasePoseBone;
    ri_local.DObjBad = *(void **)imp_DObjBad;
    ri_local.DObjGetBounds = *(void **)imp_DObjGetBounds;
    ri_local.DObjGetSurface = *(void **)imp_DObjGetSurface;
    ri_local.DObjGetNumModels = *(void **)imp_DObjGetNumModels;
    ri_local.DObjGetNumSurfaces = *(void **)imp_DObjGetNumSurfaces;
    ri_local.DObjGetSurfaces = *(void **)imp_DObjGetSurfaces;
    ri_local.DObjGetModel = *(void **)imp_DObjGetModel;
    ri_local.DObjGetSurfaceName = *(void **)imp_DObjGetSurfaceName;
    ri_local.DObjCreate = *(void **)imp_DObjCreate;
    ri_local.DObjGetAllocSkelSize = *(void **)imp_DObjGetAllocSkelSize;
    ri_local.DObjCreateSkel = *(void **)imp_DObjCreateSkel;
    ri_local.DObjCalcAnim = *(void **)imp_DObjCalcAnim;
    ri_local.DObjCalcSkel = *(void **)imp_DObjCalcSkel;
    ri_local.DObjGetRotTransArray = *(void **)imp_DObjGetRotTransArray;
    ri_local.DObjSkelAreBonesUpToDate = *(void **)imp_DObjSkelAreBonesUpToDate;
    ri_local.DObjGetMatOffset = *(void **)imp_DObjGetMatOffset;
    ri_local.DObjNumBones = *(void **)imp_DObjNumBones;
    ri_local.DObjGetBoneInfo = *(void **)imp_DObjGetBoneInfo;
    ri_local.DObjGetLodForDist = *(void **)imp_DObjGetLodForDist;
    ri_local.DObjGetLodOutDist = *(void **)imp_DObjGetLodOutDist;
    ri_local.DObjCompleteHierarchyBits = *(void **)imp_DObjCompleteHierarchyBits;
    ri_local.DObjSetModel = *(void **)imp_DObjSetModel;
    ri_local.CIN_UploadCinematic = *(void **)imp_CIN_UploadCinematic;
    ri_local.CIN_PlayCinematic = *(void **)imp_CIN_PlayCinematic;
    ri_local.CIN_RunCinematic = *(void **)imp_CIN_RunCinematic;
    ri_local.CG_DObjCalcPose = *(void **)imp_CG_DObjCalcPose;
    ri_local.CL_GetHudMsgIconMaterialName = *(void **)imp_CL_GetHudMsgIconMaterialName;

    /* Call GetRefAPI to get refexport table */
    ret = ((void *(*)(int, void *))GetRefAPI)(0x3b, &ri_local);
    memcpy(&re, ret, 0x160);

    /* Reset cl_paused dvar */
    Dvar_SetInt(*(void **)imp_cl_paused, 0);
}
#endif

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
    if (*(int *)((char *)&clientConnections + 264096) != 0 || *(byte *)(*(int *)(*(int *)imp_legacyHacks) + 0xdc) != 0) {
        UI_SetActiveMenu(1);
    } else {
        UI_SetActiveMenu(2);
    }
}

/* line 3911 */
void CL_OpenScriptMenu_f(void)
{
    char *parentMenuName, *menuResponse;
    const char *configStr;
    int menuIndex;

    if (Cmd_Argc() != 3) {
        Com_Printf(str_002a8cbc);
        Com_Printf(str_002a8d00);
        return;
    }

    if (!*(byte *)(*(byte **)imp_legacyHacks + 0x4ed))
        return;
    if (!*(int *)((char *)&cls + 272))
        return;

    parentMenuName = Cmd_Argv(1);
    menuResponse = Cmd_Argv(2);

    if (!parentMenuName || !menuResponse)
        return;

    menuIndex = -1;
    for (int i = 0; i < 0x20; i++) {
        configStr = CL_GetConfigString(0x4de + i);
        if (!*configStr)
            continue;
        if (I_stricmp(parentMenuName, configStr) == 0) {
            menuIndex = i;
            break;
        }
    }

    Cbuf_ExecuteText(2, va("cmd mr %i %i %s\n", Dvar_GetInt(str_002a8d30), menuIndex, menuResponse));
}

/* line 3970 */
void CL_InitOnceForAllClients(void)
{
    srand(Sys_MillisecondsRaw());
    Con_Init();
    CL_InitInput();

    cl_noprint = Dvar_RegisterBool_mac("cl_noprint", 0, 0);
    cl_voice = Dvar_RegisterBool_mac("cl_voice", 1, 0x1003);
    cl_timeout = Dvar_RegisterFloat("cl_timeout", 200.0f, 0.0f, 3600.0f, 0);
    cl_connectTimeout = Dvar_RegisterFloat("cl_connectTimeout", 200.0f, 0.0f, 3600.0f, 0);
    cl_shownet = Dvar_RegisterInt("cl_shownet", 0, -2, 4, 0);
    cl_shownuments = Dvar_RegisterBool_mac("cl_shownuments", 0, 0);
    cl_showServerCommands = Dvar_RegisterBool_mac("cl_showServerCommands", 0, 0);
    cl_showSend = Dvar_RegisterBool_mac("cl_showSend", 0, 0);
    cl_showTimeDelta = Dvar_RegisterBool_mac("cl_showTimeDelta", 0, 0);
    cl_freezeDemo = Dvar_RegisterBool_mac("cl_freezeDemo", 0, 0);
    cl_activeAction = Dvar_RegisterString_mac("activeAction", str_002157b8, 0);
    cl_avidemo = Dvar_RegisterInt("cl_avidemo", 0, 0, 0x7fffffff, 0);
    cl_forceavidemo = Dvar_RegisterBool_mac("cl_forceavidemo", 0, 0);

    { /* Use union to convert hex float constants */
        union { int i; float f; } flt_max = {0x7f7fffff}, flt_nmax = {0xff7fffff};
        *(const dvar_t **)imp_cl_yawspeed = Dvar_RegisterFloat("cl_yawspeed", 140.0f, flt_nmax.f, flt_max.f, 0x1001);
        *(const dvar_t **)imp_cl_pitchspeed = Dvar_RegisterFloat("cl_pitchspeed", 140.0f, flt_nmax.f, flt_max.f, 0x1001);
        *(const dvar_t **)imp_cl_anglespeedkey = Dvar_RegisterFloat("cl_anglespeedkey", 1.5f, 0.0f, flt_max.f, 0);
    }

    cl_maxpackets = Dvar_RegisterInt("cl_maxpackets", 30, 15, 100, 0x1001);
    cl_packetdup = Dvar_RegisterInt("cl_packetdup", 1, 0, 5, 0x1001);
    cl_sensitivity = Dvar_RegisterFloat("sensitivity", 5.0f, 0.01f, 100.0f, 0x1001);
    cl_mouseAccel = Dvar_RegisterFloat("cl_mouseAccel", 0.0f, 0.0f, 100.0f, 0x1001);
    cl_freelook = Dvar_RegisterBool_mac("cl_freelook", 1, 0x1001);
    cl_showMouseRate = Dvar_RegisterBool_mac("cl_showmouserate", 0, 0);
    cl_allowDownload = Dvar_RegisterBool_mac("cl_allowDownload", 1, 0x1001);
    *(const dvar_t **)imp_cl_talking = Dvar_RegisterBool_mac("cl_talking", 0, 0);
    cl_inGameVideo = Dvar_RegisterBool_mac("r_inGameVideo", 1, 0x1001);
    cl_serverStatusResendTime = Dvar_RegisterInt("cl_serverStatusResendTime", 750, 0, 3600, 0);
    *(const dvar_t **)imp_cl_bypassMouseInput = Dvar_RegisterBool_mac("cl_bypassMouseInput", 0, 0);

    m_pitch = Dvar_RegisterFloat("m_pitch", 0.022f, -1.0f, 1.0f, 0x1001);
    m_yaw = Dvar_RegisterFloat("m_yaw", 0.022f, -1.0f, 1.0f, 0x1001);
    m_forward = Dvar_RegisterFloat("m_forward", 0.25f, -1.0f, 1.0f, 0x1001);
    m_side = Dvar_RegisterFloat("m_side", 0.25f, -1.0f, 1.0f, 0x1001);
    m_filter = Dvar_RegisterBool_mac("m_filter", 0, 0x1001);
    input_viewSensitivity = Dvar_RegisterFloat("input_viewSensitivity", 1.0f, 0.0001f, 5.0f, 0x1001);
    *(const dvar_t **)imp_cg_drawCrosshair = Dvar_RegisterBool_mac("cg_drawCrosshair", 1, 0x1001);
    cl_motdString = Dvar_RegisterString_mac("cl_motdString", str_002157b8, 0x1040);
    cl_ingame = Dvar_RegisterBool_mac("cl_ingame", 0, 0x1040);
    Dvar_RegisterInt("cl_maxPing", 800, 20, 2000, 0x1001);
    name = Dvar_RegisterString_mac("name", "Unknown Soldier", 0x1003);
    Dvar_RegisterInt("rate", 5000, 1000, 25000, 0x1003);
    Dvar_RegisterInt("snaps", 20, 1, 30, 0x1003);
    Dvar_RegisterString_mac("password", str_002157b8, 0x1002);

    fx_enable = Dvar_RegisterBool_mac("fx_enable", 1, 0x1080);
    fx_draw = Dvar_RegisterBool_mac("fx_draw", 1, 0x1080);
    fx_cull = Dvar_RegisterBool_mac("fx_cull", 1, 0);
    fx_sort = Dvar_RegisterBool_mac("fx_sort", 1, 0);
    fx_freeze = Dvar_RegisterBool_mac("fx_freeze", 0, 0x1080);
    fx_debug = Dvar_RegisterBool_mac("fx_debug", 0, 0x1080);
    fx_debugBolt = Dvar_RegisterFloat("fx_debugBolt", 0.0f, 0.0f, 100.0f, 0x1080);
    fx_count = Dvar_RegisterBool_mac("fx_count", 0, 0x1080);
    fx_visMinTraceDist = Dvar_RegisterFloat("fx_visMinTraceDist", 80.0f, 0.0f, 1000.0f, 0x1080);
    fx_profile = Dvar_RegisterBool_mac("fx_profile", 0, 0x1080);
    nextdemo = Dvar_RegisterString_mac("nextdemo", str_002157b8, 0);
    Dvar_RegisterBool_mac("hud_enable", 1, 0x1001);
    Dvar_RegisterBool_mac("cg_blood", 1, 0x1001);

    /* Register commands */
    Cmd_AddCommand("cmd", CL_ForwardToServer_f);
    Cmd_AddCommand("configstrings", CL_Configstrings_f);
    Cmd_AddCommand("clientinfo", CL_Clientinfo_f);
    Cmd_AddCommand("vid_restart", CL_Vid_Restart_f);
    Cmd_AddCommand("snd_restart", CL_Snd_Restart_f);
    Cmd_AddCommand("disconnect", CL_Disconnect_f);
    Cmd_AddCommand("record", CL_Record_f);
    Cmd_AddCommand("stoprecord", CL_StopRecord_f);
    Cmd_AddCommand("demo", CL_PlayDemo_f);
    Cmd_AddCommand("timedemo", CL_PlayDemo_f);
    Cmd_SetAutoComplete("demo", "demos", str_002a9094);
    Cmd_SetAutoComplete("timedemo", "demos", str_002a9094);
    Cmd_AddCommand("cinematic", *(void (**)(void))imp_CL_PlayCinematic_f);
    Cmd_SetAutoComplete("cinematic", "video", str_00216ce4);
    Cmd_AddCommand("logo", CL_PlayLogo_f);
    Cmd_AddCommand("connect", *(void (**)(void))imp_CL_Connect_f);
    Cmd_AddCommand("reconnect", CL_Reconnect_f);
    Cmd_AddCommand("localservers", CL_LocalServers_f);
    Cmd_AddCommand("globalservers", *(void (**)(void))imp_CL_GlobalServers_f);
    CL_RconInit();
    Cmd_AddCommand("rcon", *(void (**)(void))imp_CL_Rcon_f);
    Cmd_AddCommand("ping", *(void (**)(void))imp_CL_Ping_f);
    Cmd_AddCommand("serverstatus", *(void (**)(void))imp_CL_ServerStatus_f);
    Cmd_AddCommand("toggleMenu", CL_ToggleMenu_f);
    Cmd_AddCommand("setenv", CL_Setenv_f);
    Cmd_AddCommand("showip", CL_ShowIP_f);
    Cmd_AddCommand("fs_openedList", CL_OpenedIWDList_f);
    Cmd_AddCommand("fs_referencedList", CL_ReferencedIWDList_f);
    Cmd_AddCommand("updatehunkusage", *(void (**)(void))imp_CL_UpdateLevelHunkUsage);
    Cmd_AddCommand("updatescreen", *(void (**)(void))imp_SCR_UpdateScreen);
    Cmd_AddCommand("startSingleplayer", CL_startSingleplayer_f);
    Cmd_AddCommand("setRecommended", CL_SetRecommended_f);
    Cmd_AddCommand("cubemapShot", *(void (**)(void))imp_CL_CubemapShot_f);
    Cmd_AddCommand("openScriptMenu", CL_OpenScriptMenu_f);
    Cmd_AddCommand("localizeSoundAliasFiles", *(void (**)(void))imp_Com_WriteLocalizedSoundAliasFiles);
    Cmd_AddCommand("openmenu", *(void (**)(void))imp_UI_OpenMenu_f);
    Cmd_AddCommand("closemenu", *(void (**)(void))imp_UI_CloseMenu_f);

    CL_InitRef();
    SCR_Init();
}

/* line 4937 */
extern void Z_FreeInternal(void *ptr);
void CL_ShutdownDebugData(void)
{
    byte *c = (byte *)&cls;
    int i;
    void (*shutdownDebug)(void);

    /* Free debug data allocations */
    static const int offsets[] = { 0x2a0aa8, 0x2a0aac, 0x2a0ab0, 0x2a0a98, 0x2a0a9c };
    for (i = 0; i < 5; i++) {
        void **ptr = (void **)(c + offsets[i]);
        if (*ptr) {
            Z_FreeInternal(*ptr);
            *ptr = 0;
        }
    }

    /* Zero the debug state block (9 ints at offset 0x2a0a90) */
    memset(c + 0x2a0a90, 0, 36);

    /* Call renderer debug shutdown if available */
    shutdownDebug = *(void (**)(void))((char *)&re + 264);
    if (shutdownDebug)
        shutdownDebug();
}

/* line 4449 */
#ifndef __EMSCRIPTEN__
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
        "cmpw $0, cl_pinglist+8(%esi)\n"
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
        "movl cl_pinglist+4(%esi), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl cl_pinglist+8(%esi), %eax\n"
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
        "movl cl_pinglist+16(%esi), %edi\n" /* line 4470 | time */
        "testl %edi, %edi\n" /* line 4471 | time */
        "je .Lf1494dc_001495aa\n"
        "movl %edi, %eax\n" /* time */
        ".Lf1494dc_00149564:\n"
        "movl cl_pinglist(%esi), %ebx\n" /* line 4487 | buf */
        "movl %ebx, -0x24(%ebp)\n" /* buf */
        "movl cl_pinglist+4(%esi), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl cl_pinglist+8(%esi), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "leal cl_pinglist+20(%esi), %eax\n"
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
        "subl cl_pinglist+12(%esi), %edi\n" /* time */
        "movl $str_002a8f7c, (%esp)\n" /* line 4475 */
        "calll Dvar_GetInt\n"
        "cmpl $0x63, %eax\n" /* line 4476 */
        "movl $0x64, %edx\n"
        "cmovlel %edx, %eax\n"
        "cmpl %edi, %eax\n" /* line 4480 | time */
        "movl $0, %eax\n"
        "cmovgl %eax, %edi\n" /* time */
        "movl cl_pinglist+16(%esi), %eax\n"
        "jmp .Lf1494dc_00149564\n"
    );
}

/* line 4704 */
void CL_ShowIP_f(void)
{
    Sys_ShowIP();
}

/* line 4715 */
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
const char * CL_GetServerIPAddress(void)
{
    byte *cc = (byte *)&clientConnections[0];

    if (*(int *)cc <= 4) {
        memset(szServerIPAddress, 0, 128);
    } else {
        /* Format IP:port from connection address */
        unsigned short port = *(unsigned short *)(cc + 28);
        port = (port >> 8) | (port << 8); /* byte swap */
        Com_sprintf(szServerIPAddress, 128, str_002a91dc,
            cc[24], cc[25], cc[26], cc[27], (int)(short)port);
    }

    return szServerIPAddress;
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
        "movl cls+264, %eax\n" /* line 4848 */
        "testl %eax, %eax\n"
        "je .Lf14967c_00149722\n"
        "movl cls+0x2a0a98, %eax\n" /* line 4852 */
        "testl %eax, %eax\n"
        "je .Lf14967c_001496de\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl cls+0x2a0a94, %ecx\n"
        ".Lf14967c_001496a6:\n"
        "cmpl %ecx, %ebx\n" /* line 4858 | i */
        "jge .Lf14967c_001496c3\n"
        ".Lf14967c_001496aa:\n"
        "movl cls+0x2a0a9c, %edx\n" /* line 4860 */
        "movzbl (%edx, %ebx), %eax\n"
        "cmpl %eax, %edi\n" /* fromServer */
        "je .Lf14967c_00149753\n"
        "addl $1, %ebx\n" /* line 4868 | i */
        "cmpl %ecx, %ebx\n" /* line 4858 | i */
        "jl .Lf14967c_001496aa\n"
        ".Lf14967c_001496c3:\n"
        "movl cls+0x2a0a90, %eax\n" /* line 4872 */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl cls+0x2a0a98, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *re+252\n"
        ".Lf14967c_001496de:\n"
        "movl cls+0x2a0aa8, %eax\n" /* line 4876 */
        "testl %eax, %eax\n"
        "je .Lf14967c_00149722\n"
        "xorl %esi, %esi\n"
        "movl cls+0x2a0aa4, %ecx\n"
        ".Lf14967c_001496ef:\n"
        "cmpl %ecx, %esi\n" /* line 4882 */
        "jge .Lf14967c_00149707\n"
        ".Lf14967c_001496f3:\n"
        "movl cls+0x2a0aac, %eax\n" /* line 4884 */
        "movzbl (%eax, %esi), %eax\n"
        "cmpl %edi, %eax\n" /* fromServer */
        "je .Lf14967c_0014972a\n"
        "addl $1, %esi\n" /* line 4896 */
        ".Lf14967c_00149703:\n"
        "cmpl %ecx, %esi\n" /* line 4882 */
        "jl .Lf14967c_001496f3\n"
        ".Lf14967c_00149707:\n"
        "movl cls+0x2a0aa0, %eax\n" /* line 4899 */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl cls+0x2a0aa8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *re+256\n"
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
        "addl cls+0x2a0ab0, %eax\n"
        "subl $1, (%eax)\n"
        "movl cls+0x2a0ab0, %eax\n" /* line 4887 */
        "movl (%ebx, %eax), %eax\n" /* i */
        "testl %eax, %eax\n"
        "jle .Lf14967c_00149799\n"
        "movl cls+0x2a0aa4, %ecx\n"
        "addl $1, %esi\n" /* line 4896 */
        "jmp .Lf14967c_00149703\n"
        ".Lf14967c_00149753:\n"
        "subl $1, %ecx\n" /* line 4862 */
        "movl %ecx, cls+0x2a0a94\n"
        "movzbl (%edx, %ecx), %eax\n" /* line 4863 */
        "movb %al, (%ebx, %edx)\n" /* i */
        "movl cls+0x2a0a98, %ecx\n" /* line 4864 */
        "movl %ebx, %edx\n" /* i */
        "shll $7, %edx\n"
        "movl cls+0x2a0a94, %eax\n"
        "shll $7, %eax\n"
        "addl %ecx, %edx\n"
        "addl %ecx, %eax\n"
        "movl $0x80, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl cls+0x2a0a94, %ecx\n"
        "jmp .Lf14967c_001496a6\n"
        ".Lf14967c_00149799:\n"
        "movl cls+0x2a0aa4, %ecx\n" /* line 4889 */
        "subl $1, %ecx\n"
        "movl %ecx, cls+0x2a0aa4\n"
        "movl cls+0x2a0aac, %edx\n" /* line 4890 */
        "movzbl (%edx, %ecx), %eax\n"
        "movb %al, (%esi, %edx)\n"
        "movl cls+0x2a0ab0, %edx\n" /* line 4891 */
        "movl cls+0x2a0aa4, %eax\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, (%ebx, %edx)\n" /* i */
        "movl cls+0x2a0aa8, %edx\n" /* line 4892 */
        "addl %esi, %ebx\n" /* i */
        "leal (%esi, %ebx, 2), %ebx\n" /* i */
        "shll $2, %ebx\n" /* i */
        "movl cls+0x2a0aa4, %eax\n"
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
        "movl cls+0x2a0aa4, %ecx\n"
        "jmp .Lf14967c_001496ef\n"
    );
}

/* line 4909 */
void CL_UpdateDebugData(void)
{
    byte *c = (byte *)&cls;

    if (!*(int *)(c + 264))
        return;

    if (*(int *)(c + 0x2a0a98)) {
        /* re.AddDebugString */
        ((void (*)(void *, int, int))*(int *)((char *)&re + 252))(
            *(void **)(c + 0x2a0a98), *(int *)(c + 0x2a0a94), *(int *)(c + 0x2a0a90));
    }

    if (*(int *)(c + 0x2a0aa8)) {
        /* re.AddDebugLine */
        ((void (*)(void *, int, int))*(int *)((char *)&re + 256))(
            *(void **)(c + 0x2a0aa8), *(int *)(c + 0x2a0aa4), *(int *)(c + 0x2a0aa0));
    }
}

/* line 4991 */
int CL_TextWidth(const char *text, int maxChars, FontHandle font)
{
    if (!text || !font)
        return 0;
    return ((int (*)(const char *, int, FontHandle))*(int *)((char *)&re + 276))(text, maxChars, font);
}

/* line 5002 */
int CL_TextHeight(FontHandle font)
{
    return ((int (*)(FontHandle))*(int *)((char *)&re + 280))(font);
}

/* line 5013 */
float CL_NormalizedTextScale(FontHandle font, float scale)
{
    return ((float (*)(FontHandle, float))*(int *)((char *)&re + 272))(font, scale);
}

/* line 5019 */
void CL_DrawTextPhysical(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style)
{
    if (!text || !font)
        return;
    ((void (*)(const char *, int, FontHandle, float, float, float, float, const vec_t *, int))*(int *)((char *)&re + 284))(text, maxChars, font, x, y, xScale, yScale, color, style);
}

/* line 5025 */
extern void CalcSplitScreenTextOffset(FontHandle font, float *y);
extern void CalcScreenPlacement(float *x, float *y, float *xScale, float *yScale, int horzAlign, int vertAlign);
void CL_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec_t *color, int style)
{
    CalcSplitScreenTextOffset(font, &y);
    CalcScreenPlacement(&x, &y, &xScale, &yScale, horzAlign, vertAlign);
    ((void (*)(const char *, int, FontHandle, float, float, float, float, const vec_t *, int))*(int *)((char *)&re + 284))(text, maxChars, font, x, y, xScale, yScale, color, style);
}

/* line 5033 */
void CL_DrawTextPhysicalWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor)
{
    if (!text || !font)
        return;
    cursor = (signed char)cursor;
    ((void (*)(const char *, int, FontHandle, float, float, float, float, const vec_t *, int, int, int))*(int *)((char *)&re + 300))(text, maxChars, font, x, y, xScale, yScale, color, style, cursorPos, cursor);
}

/* line 5039 */
void CL_DrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor)
{
    cursor = (signed char)cursor;
    CalcSplitScreenTextOffset(font, &y);
    CalcScreenPlacement(&x, &y, &xScale, &yScale, horzAlign, vertAlign);
    ((void (*)(const char *, int, FontHandle, float, float, float, float, const vec_t *, int, int, int))*(int *)((char *)&re + 300))(text, maxChars, font, x, y, xScale, yScale, color, style, cursorPos, cursor);
}

/* line 5052 */
int CL_GetKeyCatchers(void)
{
    return *(int *)((char *)&clients + 4);
}

/* line 5062 */
Bool CL_GetDisplayHUDWithKeycatchUI(void)
{
    return *(byte *)((char *)&clients + 8);
}

/* line 5072 */
FontHandle CL_RegisterFont(const char *fontName, int imageTrack)
{
    return ((FontHandle (*)(const char *, int))*(int *)((char *)&re + 224))(fontName, imageTrack);
}

/* line 676 */
void CL_WriteDemoMessage(msg_t *msg, int headerBytes)
{
    byte *cc = (byte *)&clientConnections[0];
    int swlen;
    int len;
    int demofile;

    /* Write sequence number */
    swlen = *(int *)(cc + 131384);
    FS_Write(&swlen, 4, *(int *)(cc + 0x407b0));

    /* Write message length minus header */
    len = msg->cursize - headerBytes;
    swlen = len;
    demofile = *(int *)(cc + 0x407b0);
    FS_Write(&swlen, 4, demofile);

    /* Write message data after header */
    FS_Write(msg->data + headerBytes, len, demofile);
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
        "movl $str_002a9214, (%esp)\n" /* line 758 */
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
        "movl $str_002a9200, (%esp)\n" /* line 752 */
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
        "movl $str_002a91ec, (%esp)\n" /* line 746 */
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
        "movl $str_002a9248, 8(%esp)\n" /* "demo%04i" */
        "movl $0x40, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $1, 0x10(%esp)\n" /* line 777 */
        "movl %edi, 0xc(%esp)\n"
        "movl $str_002a9238, 8(%esp)\n" /* "demos/%s.dm_%d" */
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
        "movl $str_002a9254, (%esp)\n" /* "recording to %s.
" */
        "calll Com_Printf\n"
        "movl clc, %ebx\n" /* line 798 | number */
        "movl %esi, (%esp)\n" /* i */
        "calll FS_FOpenFileWrite\n"
        "movl %eax, 0x407b0(%ebx)\n" /* number */
        "testl %eax, %eax\n" /* line 799 */
        "jne .Lf149ab4_00149bce\n"
        "movl $str_002a9268, (%esp)\n" /* line 801 */
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
        "movl $str_002a9238, 8(%esp)\n" /* "demos/%s.dm_%d" */
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
    if (!*(int *)((char *)&cls + 4))
        return;
    CL_ShutdownCGame();
    CL_ShutdownUI();
    *(int *)((char *)&cls + 2755160) = 0;
    *(int *)((char *)&cls + 2755164) = 0;
    *(int *)((char *)&cls + 2755168) = 0;
    *(int *)((char *)&cls + 4) = 0;
}

/* line 2705 */
void CL_InitLoad(const char *mapname, const char *gametype)
{
    byte *cc;

    if (!*(int *)(*(byte **)imp_legacyHacks + 4))
        return;

    Dvar_SetInt(*(const dvar_t **)imp_com_expectedHunkUsage, 0);
    UI_SetMap(mapname, gametype);

    /* Set connstate: if >= 5, set to 5; else set to 0 */
    cc = *(byte **)imp_clc;
    *(int *)cc = (*(int *)cc >= 5) ? 5 : 0;

    SCR_UpdateScreenInternal();
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
        "movl cls+280, %esi\n" /* line 3791 | time */
        "subl cls+288, %esi\n" /* time */
        "movl cls+296, %eax\n" /* line 3792 */
        "cmpl %eax, %esi\n" /* time */
        "jge .Lf149f18_0014a074\n"
        "cvtsi2ssl %esi, %xmm1\n" /* line 3793 | time */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3798 | 0.0f */
        "jb .Lf149f18_0014a0a3\n"
        ".Lf149f18_00149f52:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 3800 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf149f18_00149f61:\n"
        "movss %xmm1, -0x18(%ebp)\n" /* line 3802 | color */
        "movss %xmm1, -0x14(%ebp)\n" /* line 3803 */
        "movss %xmm1, -0x10(%ebp)\n" /* line 3804 */
        "movl $0x3f800000, -0xc(%ebp)\n" /* line 3805 */
        "cvtsi2ssl cls+0x2a0a64, %xmm0\n" /* line 3807 */
        "movss %xmm0, -0x1c(%ebp)\n" /* w */
        "cvtsi2ssl cls+0x2a0a68, %xmm0\n" /* line 3808 */
        "movaps %xmm0, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "divss lit4_002ed720, %xmm1\n" /* 3.0f */
        "movl cls+304, %eax\n" /* line 3811 */
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
        "calll *re+148\n"
        "movl cls+308, %eax\n" /* line 3812 */
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
        "calll *re+148\n"
        "cmpl cls+292, %esi\n" /* line 3814 | time */
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
        "movl cls+292, %edx\n" /* line 3794 */
        "movl cls+300, %ecx\n"
        "movl %edx, %eax\n"
        "subl %ecx, %eax\n"
        "cmpl %eax, %esi\n" /* time */
        "jle .Lf149f18_0014a0b2\n"
        "subl %esi, %edx\n" /* line 3795 | time */
        "cvtsi2ssl %edx, %xmm1\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3798 | 0.0f */
        "jae .Lf149f18_00149f52\n"
        ".Lf149f18_0014a0a3:\n"
        "jp .Lf149f18_00149f52\n"
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf149f18_00149f61\n"
        ".Lf149f18_0014a0b2:\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 3794 | 1.0f */
        "jmp .Lf149f18_00149f61\n"
    );
}

/* line 3873 */
void CL_StopLogoOrCinematic(void)
{
    if (*(int *)&clientConnections[0] == 1) {
        SCR_StopCinematic();
    } else {
        *(int *)&clientConnections[0] = 0;
    }

    SND_StopSounds(0);

    if (**(int **)imp_clc)
        UI_SetActiveMenu(0);
    else
        UI_SetActiveMenu(1);
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
        "movl cls+264, %eax\n" /* line 4809 */
        "testl %eax, %eax\n"
        "je .Lf14a114_0014a1da\n"
        "movl $__mh_execute_header, cls+0x2a0aa0\n" /* line 4812 */
        "movl cls+0x2a0aa4, %ecx\n" /* line 4813 */
        "leal 1(%ecx), %eax\n"
        "cmpl $__mh_execute_header, %eax\n"
        "jg .Lf14a114_0014a1da\n"
        "movl cls+0x2a0aa8, %eax\n" /* line 4817 */
        "testl %eax, %eax\n"
        "je .Lf14a114_0014a1e2\n"
        ".Lf14a114_0014a15e:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 4826 */
        "leal (%ecx, %edx, 2), %edx\n"
        "movl cls+0x2a0aa8, %eax\n"
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
        "movl cls+0x2a0aac, %edx\n" /* line 4832 */
        "movl cls+0x2a0aa4, %eax\n"
        "movzbl 0x1c(%ebp), %ecx\n" /* fromServer */
        "movb %cl, (%edx, %eax)\n"
        "movl cls+0x2a0aa4, %edx\n" /* line 4833 */
        "movl cls+0x2a0ab0, %eax\n"
        "movl 0x18(%ebp), %ecx\n" /* duration */
        "movl %ecx, (%eax, %edx, 4)\n"
        "addl $1, cls+0x2a0aa4\n" /* line 4835 */
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
        "movl %eax, cls+0x2a0aa8\n"
        "movl cls+0x2a0aa0, %eax\n" /* line 4820 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, cls+0x2a0aac\n"
        "movl cls+0x2a0aa0, %eax\n" /* line 4821 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, cls+0x2a0ab0\n"
        "xorl %ecx, %ecx\n" /* line 4822 */
        "movl $0, cls+0x2a0aa4\n"
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
        "movl cls+264, %eax\n" /* line 4770 */
        "testl %eax, %eax\n"
        "je .Lf14a22c_0014a2e1\n"
        "movl $0x100, cls+0x2a0a90\n" /* line 4773 */
        "movl cls+0x2a0a94, %edx\n" /* line 4774 */
        "leal 1(%edx), %eax\n"
        "cmpl $0x100, %eax\n"
        "jg .Lf14a22c_0014a2e1\n"
        "movl cls+0x2a0a98, %eax\n" /* line 4778 */
        "testl %eax, %eax\n"
        "je .Lf14a22c_0014a2e9\n"
        ".Lf14a22c_0014a26b:\n"
        "movl %edx, %ebx\n" /* line 4786 | string */
        "shll $7, %ebx\n" /* string */
        "addl cls+0x2a0a98, %ebx\n" /* string */
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
        "movl cls+0x2a0a9c, %edx\n" /* line 4793 */
        "movl cls+0x2a0a94, %eax\n"
        "movzbl 0x18(%ebp), %ecx\n" /* fromServer */
        "movb %cl, (%edx, %eax)\n"
        "addl $1, cls+0x2a0a94\n" /* line 4795 */
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
        "movl %eax, cls+0x2a0a98\n"
        "movl cls+0x2a0a90, %eax\n" /* line 4781 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, cls+0x2a0a9c\n"
        "xorl %edx, %edx\n" /* line 4782 */
        "movl $0, cls+0x2a0a94\n"
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
        "movl imp_cl_cdkeychecksum, %eax\n" /* line 1581 */
        "movl %eax, 4(%esp)\n"
        "movl imp_cl_cdkey, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_CDKeyValidate\n"
        "testl %eax, %eax\n"
        "je .Lf14a31e_0014a495\n"
        "cmpw $0, cls+0x2a0a54\n" /* line 1587 */
        "je .Lf14a31e_0014a402\n"
        "cmpl $1, cls+0x2a0a4c\n" /* line 1599 */
        "je .Lf14a31e_0014a3fa\n"
        ".Lf14a31e_0014a360:\n"
        "movl $str_00216d6c, (%esp)\n" /* line 1604 */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "je .Lf14a31e_0014a4b1\n"
        "movl $0x40, 8(%esp)\n" /* line 1606 */
        "movl $str_002a9080, 4(%esp)\n" /* "demo" */
        "leal -0x64(%ebp), %ebx\n" /* nums, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll I_strncpyz\n"
        ".Lf14a31e_0014a38f:\n"
        "movl $0x101b, 8(%esp)\n" /* line 1628 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a9300, (%esp)\n" /* "cl_anonymous" */
        "calll Dvar_RegisterBool_mac\n"
        "movl %ebx, 8(%esp)\n" /* line 1629 | i */
        "movzbl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002a9310, (%esp)\n" /* "getKeyAuthorize %i %s" */
        "calll va\n"
        "movl cls+0x2a0a4c, %ebx\n" /* i */
        "movl %ebx, -0x24(%ebp)\n" /* i */
        "movl cls+0x2a0a50, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl cls+0x2a0a54, %edx\n"
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
        "movl $str_002a9298, 4(%esp)\n" /* line 1589 */
        "movl $str_002a92b4, (%esp)\n" /* "Resolving %s
" */
        "calll Com_Printf\n"
        "movl $cls+0x2a0a4c, 4(%esp)\n" /* line 1590 */
        "movl $str_002a9298, (%esp)\n" /* "cod2master.activision.com" */
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "je .Lf14a31e_0014a4de\n"
        "movw $0xdc50, cls+0x2a0a54\n" /* line 1596 */
        "movl $0x50dc, 0x18(%esp)\n" /* line 1597 */
        "movzbl cls+0x2a0a53, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl cls+0x2a0a52, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl cls+0x2a0a51, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movzbl cls+0x2a0a50, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a9298, 4(%esp)\n" /* "cod2master.activision.com" */
        "movl $str_002a92e0, (%esp)\n" /* "%s resolved to %i.%i.%i.%i:%i
" */
        "calll Com_Printf\n"
        "cmpl $1, cls+0x2a0a4c\n" /* line 1599 */
        "jne .Lf14a31e_0014a360\n"
        "jmp .Lf14a31e_0014a3fa\n"
        ".Lf14a31e_0014a495:\n"
        "movl $str_002a9280, 4(%esp)\n" /* line 1583 */
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
        "movl imp_cl_cdkey, %esi\n" /* line 1612 */
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
        "movl $str_002a92c4, (%esp)\n" /* line 1592 */
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
        "movl clientConnections+264096, %edx\n" /* line 2298 */
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
        "movl cls+280, %edx\n" /* line 2309 */
        "movl %edx, %eax\n"
        "subl clientConnections+32, %eax\n"
        "cmpl $0xbb7, %eax\n"
        "jle .Lf14a530_0014a553\n"
        "movl %edx, clientConnections+32\n" /* line 2314 */
        "movl clc, %ebx\n" /* line 2315 */
        "addl $1, 0x24(%ebx)\n"
        "movl (%ebx), %eax\n" /* line 2317 */
        "cmpl $3, %eax\n"
        "je .Lf14a530_0014a5a9\n"
        "cmpl $4, %eax\n"
        "je .Lf14a530_0014a61f\n"
        "movl $str_002a934c, 4(%esp)\n" /* line 2366 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14a530_0014a553\n"
        ".Lf14a530_0014a5a9:\n"
        "movl imp_net_lanauthorize, %eax\n" /* line 2321 */
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
        "movl $str_002a9328, 0x10(%esp)\n" /* "getchallenge" */
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
        "movl $0x76, 4(%esp)\n" /* line 2335 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a7118, 4(%esp)\n" /* "protocol" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl 0x128(%ebx), %eax\n" /* line 2336 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a9338, 4(%esp)\n" /* "challenge" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl 4(%ebx), %eax\n" /* line 2339 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a9344, 4(%esp)\n" /* "qport" */
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
        "movl imp_dvar_modifiedFlags, %eax\n" /* line 2362 */
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
        "movl $str_002a9370, (%esp)\n" /* line 4407 */
        "calll Com_Printf\n"
        "movl $0, cls+312\n" /* line 4410 */
        "movl $0, cls+0x2a0a48\n" /* line 4411 */
        "movl $0, -0x3c(%ebp)\n" /* i */
        "movl $cls, %esi\n"
        "movl $cls+316, %edi\n"
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
        "movl $str_002a93a0, 4(%esp)\n" /* "����getinfo xxx" */
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
        "movl $str_002a93b0, (%esp)\n" /* line 3841 */
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
        "movl $str_002a9408, (%esp)\n" /* line 3844 */
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
        "movl cls+272, %ecx\n" /* line 3853 */
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
        "mulss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x24(%ebp)\n"
        "cvttss2si -0x24(%ebp), %eax\n"
        "movl %eax, cls+296\n"
        "movl $3, (%esp)\n" /* line 3862 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x18(%ebp)\n"
        "cvtsd2ss -0x18(%ebp), %xmm0\n" /* line 428 */
        "mulss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x28(%ebp)\n"
        "cvttss2si -0x28(%ebp), %eax\n"
        "movl %eax, cls+292\n"
        "movl $4, (%esp)\n" /* line 3863 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n" /* line 428 */
        "mulss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x2c(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %eax\n"
        "movl %eax, cls+300\n" /* line 3863 */
        "addl cls+296, %eax\n" /* line 3864 */
        "addl %eax, cls+292\n"
        "movl re+16, %ebx\n" /* line 3866 */
        "movl %esi, 4(%esp)\n" /* name */
        "movl $str_002a9418, (%esp)\n" /* "%s1" */
        "calll va\n"
        "movl $3, 8(%esp)\n"
        "movl $0x30, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *%ebx\n"
        "movl %eax, cls+304\n"
        "movl re+16, %ebx\n" /* line 3867 */
        "movl %esi, 4(%esp)\n" /* name */
        "movl $str_002a941c, (%esp)\n" /* "%s2" */
        "calll va\n"
        "movl $3, 8(%esp)\n"
        "movl $0x30, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *%ebx\n"
        "movl %eax, cls+308\n"
        "movl cls+280, %eax\n" /* line 3869 */
        "addl $0x64, %eax\n"
        "movl %eax, cls+288\n"
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
        "movl %edx, cls+0x2a0a48\n" /* line 4589 */
        "movl $0, -0x45c(%ebp)\n" /* slots */
        "movl $cl_pinglist+8, %eax\n"
        ".Lf14aa5e_0014aa99:\n"
        "cmpw $1, (%eax)\n" /* line 4560 */
        "sbbl $-1, -0x45c(%ebp)\n" /* slots */
        "addl $0x414, %eax\n"
        "movl $g_waitingForServer+8, %ecx\n" /* line 4556 */
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
        "movl $cl_pinglist+8, %edi\n" /* line 4627 */
        "jmp .Lf14aa5e_0014ab5c\n"
        ".Lf14aa5e_0014ab4d:\n"
        "addl $0x414, %edi\n" /* line 4646 */
        "movl $g_waitingForServer+8, %eax\n" /* line 4629 */
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
        "movl $g_waitingForServer+8, %eax\n" /* line 4629 */
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
        "movl %eax, cl_pinglist+12(%ebx)\n"
        "movl $0, cl_pinglist+16(%ebx)\n" /* line 4668 */
        "movl cl_pinglist(%ebx), %esi\n" /* line 4669 */
        "movl %esi, -0x28(%ebp)\n"
        "movl cl_pinglist+4(%ebx), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl cl_pinglist+8(%ebx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl $str_002a9420, 0x10(%esp)\n" /* "getinfo xxx" */
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
        "movl cls+17728, %ecx\n" /* line 4606 */
        "movl %ecx, -0x454(%ebp)\n" /* max */
        "movl $cls+17732, %eax\n"
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
        "movl cls+312, %eax\n" /* line 4601 */
        "movl %eax, -0x454(%ebp)\n" /* max */
        "movl $cls+316, %eax\n"
        "jmp .Lf14aa5e_0014ac9a\n"
        ".Lf14aa5e_0014ad38:\n"
        "movl cls+0x29c644, %eax\n" /* line 4612 */
        "movl %eax, -0x454(%ebp)\n" /* max */
        "movl $cls+0x29c648, %eax\n"
        "jmp .Lf14aa5e_0014ac9a\n"
    );
}

/* CL_RunOncePerClientFrame — per-frame timing: avidemo, FPS calc, frame_msec computation */
/* externs already declared */
void CL_RunOncePerClientFrame(int msec)
{
    /* If fullscreen UI, call re.EndRegistration (re+340) */
    if (UI_IsFullscreen()) {
        typedef void (*Fn)(void);
        ((Fn)(*(void **)((byte *)&re + 340)))();
    }

    /* Avidemo override: adjust msec based on demo framerate */
    int avidemoVal = *(int *)((byte *)cl_avidemo + 8);
    if (avidemoVal && msec) {
        /* Check if connected or force avidemo */
        if (*(int *)(byte *)&clc == 8 || *(byte *)((byte *)cl_forceavidemo + 8)) {
            Cbuf_ExecuteText(0, "screenshot silent\n");
        }
        float timescale = *(float *)imp_com_timescaleValue;
        msec = (int)(1000.0f / (float)avidemoVal * timescale);
        if (msec == 0) msec = 1;
    }

    /* FPS calculation if active */
    if (*(int *)((byte *)&cls + 272))
        CG_CalculateFPS();

    /* Set frame timing */
    *(int *)((byte *)&cls + 284) = msec;
    *(int *)((byte *)&cls + 276) = msec;
    *(int *)((byte *)&cls + 280) += msec;

    /* Compute frame_msec from com_frameTime delta */
    int curFrameTime = *(int *)imp_com_frameTime;
    int delta = curFrameTime - old_com_frameTime;
    frame_msec = (delta != 0) ? delta : 1;
    if (frame_msec > 200) frame_msec = 200;
    old_com_frameTime = curFrameTime;
}

/* line 2911 */
int Client_SendVoiceData(int bytes, char *enc_buffer)
{
    byte *c;
    int voiceIdx, newIdx;

    if (bytes > 0) {
        c = *(byte **)imp_cl;
        voiceIdx = *(int *)(c + 0x179c0c);

        /* Copy voice data: dest = cl + voiceIdx*256 + voiceIdx*4 + 0x1791e8 */
        memcpy(c + (voiceIdx << 8) + (voiceIdx * 4) + 0x1791e8, enc_buffer, bytes);

        /* Store size */
        *(int *)(c + (voiceIdx << 8) + (voiceIdx * 4) + 0x1791e4) = bytes;

        /* Increment voice packet count */
        newIdx = voiceIdx + 1;
        *(int *)(c + 0x179c0c) = newIdx;

        /* CL_VoiceTransmit inline */
        if (newIdx > 0) {
            if (*(int *)(c + 0x26f0) - *(int *)(c + 0x179c10) > 199 || newIdx > 9) {
                CL_WriteVoicePacket();
                c = *(byte **)imp_cl;
                *(int *)(c + 0x179c0c) = 0;
                *(int *)(c + 0x179c10) = *(int *)(c + 0x26f0);
            }
        }
    }

    return bytes;
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
        "movl $str_002a9440, 4(%esp)\n" /* line 2504 */
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
        "movl $str_002a9444, 4(%esp)\n" /* line 2523 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b012\n"
        "movl clc, %ebx\n" /* line 2525 | c */
        "cmpl $3, (%ebx)\n" /* c */
        "je .Lf14aef6_0014b04f\n"
        "movl $str_002a9458, (%esp)\n" /* line 2527 */
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
        "movl $str_002a949c, 4(%esp)\n" /* line 2547 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b0c8\n"
        "movl clc, %ebx\n" /* line 2549 | c */
        "cmpl $4, (%ebx)\n" /* c */
        "jg .Lf14aef6_0014b14e\n"
        "je .Lf14aef6_0014b1e6\n" /* line 2554 */
        "movl $str_002a94d0, (%esp)\n" /* line 2556 */
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
        "movl $str_002a948c, (%esp)\n" /* "challenge: %d
" */
        "calll Com_DPrintf\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b0c8:\n"
        "movl $str_002a9558, 4(%esp)\n" /* line 2592 */
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
        "movl $str_002a94ac, (%esp)\n" /* line 2551 */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* line 2695 | c */
        "jmp .Lf14aef6_0014affa\n"
        ".Lf14aef6_0014b161:\n"
        "movl $str_002a9568, 4(%esp)\n" /* line 2599 */
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
        "movl $str_002a9508, (%esp)\n" /* line 2563 */
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
        "movl $str_002a9540, (%esp)\n" /* "%s should have been %s
" */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* line 2695 | c */
        "jmp .Lf14aef6_0014affa\n"
        ".Lf14aef6_0014b331:\n"
        "movl $str_00228e90, 4(%esp)\n" /* line 2607 */
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
        "movl cls+280, %eax\n" /* line 2396 */
        "subl 0x10(%ebx), %eax\n"
        "cmpl $0xbb7, %eax\n"
        "jle .Lf14aef6_0014afb0\n"
        "movl $str_00215f8c, 4(%esp)\n" /* line 2401 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b40c:\n"
        "movl imp_g_qport, %eax\n" /* line 2580 */
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
        "movl cls+280, %eax\n" /* line 2586 */
        "movl %eax, 0x10(%ebx)\n" /* c */
        "movl $0xffffd8f1, 0xc(%ebx)\n" /* line 2587 | c */
        "movl $1, %ebx\n" /* c */
        "jmp .Lf14aef6_0014afb5\n"
        ".Lf14aef6_0014b4ac:\n"
        "movl $str_002a9578, 4(%esp)\n" /* line 2614 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b539\n"
        "movl $1, (%esp)\n" /* line 2616 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00216058, (%esp)\n" /* "%s" */
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
        "movl $str_002a9580, 4(%esp)\n" /* line 2621 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf14aef6_0014afb0\n"
        "movl $str_002a9590, 4(%esp)\n" /* line 2628 */
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
        "movl $str_00216058, 8(%esp)\n" /* "%s" */
        "movl $0x4000, 4(%esp)\n"
        "movl -0x124(%ebp), %ebx\n" /* printBuf, c */
        "movl %ebx, (%esp)\n" /* c */
        "calll Com_sprintf\n"
        "movl %ebx, 4(%esp)\n" /* line 2633 | c */
        "movl $0, (%esp)\n"
        "calll Com_PrintMessage\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b5c2:\n"
        "movl $str_002168a4, 4(%esp)\n" /* line 2638 */
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
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14aef6_0014afb0\n"
        ".Lf14aef6_0014b681:\n"
        "movl $0x12, 8(%esp)\n" /* line 2662 */
        "movl $str_002a9598, 4(%esp)\n" /* "getserversResponse" */
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
        "movl $str_002a95ac, 4(%esp)\n" /* "needcdkey" */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14aef6_0014b77a\n"
        "movl $0x100, 8(%esp)\n" /* line 2673 */
        "movl $str_002a95b8, 4(%esp)\n" /* "EXE_AWAITINGCDKEYAUTH" */
        "movl clc, %ebx\n" /* c */
        "addl $0x28, %ebx\n" /* c */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_strncpyz\n"
        "movl $0, 8(%esp)\n" /* line 2674 */
        "movl $str_002a95d0, 4(%esp)\n" /* "need cd key message" */
        "movl $str_002a95b8, (%esp)\n" /* "EXE_AWAITINGCDKEYAUTH" */
        "calll SEH_LocalizeTextMessage\n"
        "movl %ebx, 4(%esp)\n" /* line 2675 | c */
        "movl $str_00215bbc, (%esp)\n" /* "%s
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
        "movl $str_002a95e4, 4(%esp)\n" /* line 2683 */
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
        /* Fix #151: Don't downgrade connstate if already past 'connected' (5).
           The 'loadingnewmap' OOB packet can arrive via loopback AFTER the
           gamestate has already been processed (state 6/7/8). */
        "cmpl $5, (%ebx)\n"
        "jg .Lf14aef6_skip_state5\n"
        "movl $5, (%ebx)\n" /* line 2689 | c */
        ".Lf14aef6_skip_state5:\n"
        "calll UI_DrawConnectScreen\n" /* line 2690 */
        "jmp .Lf14aef6_0014afb0\n"
    );
}

/* line 2733 */
__attribute__((naked))
Bool CL_PacketEvent_real(netadr_t from, msg_t *msg, int time);

Bool CL_PacketEvent(netadr_t from, msg_t *msg, int time)
{
    static int _cpe_cnt = 0;
    Bool ret;
    int first4 = (msg && msg->cursize >= 4) ? *(int *)msg->data : 0;
    if (_cpe_cnt < 30) {
        fprintf(stderr, "[CPE-pre#%d] from.type=%d cursize=%d cs=%d first4=0x%x\n",
            _cpe_cnt, *(int *)&from, msg ? msg->cursize : -1, *(int *)&clientConnections[0], first4);
    }
    ret = CL_PacketEvent_real(from, msg, time);
    if (_cpe_cnt < 30) {
        fprintf(stderr, "[CPE-post#%d] ret=%d cs=%d\n", _cpe_cnt, ret, *(int *)&clientConnections[0]);
        _cpe_cnt++;
    }
    return ret;
}

Bool CL_PacketEvent_real(netadr_t from, msg_t *msg, int time)
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
        "movl $str_002a95f4, (%esp)\n" /* "%s: Runt packet
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
        "movl clientConnections+264152, %ecx\n" /* line 2759 */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl clientConnections+264156, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl clientConnections+264160, %eax\n"
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
        "movl clientConnections+264160, %edx\n"
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
        "movl cls+280, %eax\n"
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
        "movl $str_002a9608, (%esp)\n" /* "%s:sequenced packet without connection
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
        /* Diagnostic: print connstate after ParseServerMessage */
        "jmp .Ldbg_psm_skip\n"
        ".Ldbg_psm_str: .asciz \"DBG: after ParseServerMessage connstate=%d\\n\"\n"
        ".Ldbg_psm_skip:\n"
        "pushl clientConnections\n"
        "pushl $.Ldbg_psm_str\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
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
        "movl $str_002a9630, (%esp)\n" /* line 2802 */
        "calll Com_DPrintf\n"
        "movl %edi, 0x20138(%ebx)\n" /* line 2803 | savedServerMessageSequence */
        "movl %esi, 0x134(%ebx)\n" /* line 2804 | savedReliableAcknowledge */
        "xorl %eax, %eax\n"
        "jmp .Lf14b85c_0014b8f9\n"
    );
}

/* CL_Init — initialize client: clear state, reset connections, init subsystems */
extern void Com_ClientDObjClearAllSkel(void);
extern void CL_ClearMutedList(void);
extern void Cbuf_Execute(void);
extern void CL_SetADS(int ads);
extern void *imp_legacyHacks;
void CL_Init(void)
{
    Com_Printf("CL_Init\n");

    /* Save fields that survive the memset — cl is a pointer to the buffer */
    byte *c = *(byte **)&cl;
    byte saved9 = c[9];
    byte savedA = c[0xa];
    int saved4 = *(int *)(c + 4);
    byte saved8 = c[8];
    byte saved0 = c[0];

    /* Clear client state buffer (not the cl pointer itself) */
    memset(c, 0, 0x179c14);

    /* Restore preserved fields */
    c[9] = saved9;
    c[0xa] = savedA;
    *(int *)(c + 4) = saved4;
    c[8] = saved8;
    c[0] = saved0;

    Com_ClientDObjClearAllSkel();
    CL_ClearMutedList();
    *(int *)(c + 0x179c0c) = 0;

    /* Reset connection state */
    *(int *)(byte *)clc = 0;
    *(int *)((byte *)&cls + 280) = 0;

    /* Set initialized flag */
    c[0] = 1;

    /* Clear legacy hack flags */
    byte **lh = (byte **)imp_legacyHacks;
    (*lh)[0x5c] = 0;
    (*lh)[0x9c] = 0;
    (*lh)[0xdc] = 0;

    Cbuf_Execute();

    /* Set active flag */
    *(int *)(*lh + 4) = 1;
    CL_SetADS(0);

    Com_Printf("CL_InitDone\n");
}

/* line 1139 */
void CL_ShutdownAll(void)
{
    void (*shutdownInput)(void) = *(void (**)(void))((char *)&re + 328);
    void (*shutdown)(int) = *(void (**)(int))&re;

    if (shutdownInput)
        shutdownInput();

    if (*(int *)((char *)&cls + 4)) {
        CL_ShutdownCGame();
        CL_ShutdownUI();
        *(int *)((char *)&cls + 0x2a0a58) = 0;
        *(int *)((char *)&cls + 0x2a0a5c) = 0;
        *(int *)((char *)&cls + 0x2a0a60) = 0;
        *(int *)((char *)&cls + 4) = 0;
    }

    if (shutdown)
        shutdown(0);

    *(int *)((char *)&cls + 264) = 0;
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
        "movl imp_legacyHacks, %eax\n" /* line 3077 */
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
        "movl cl, %ecx\n" /* line 2944 */
        "movl 0x179c0c(%ecx), %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "leal (%ecx, %edx), %edx\n"
        "leal 0x1791e4(%edx, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Voice_GetLocalVoiceData\n"
        "calll Voice_Playback\n" /* line 2945 */
        "calll CL_UpdateColor\n" /* line 3096 */
        "movl clc, %ebx\n" /* line 2854 */
        "cmpl $3, (%ebx)\n"
        "jle .Lf14bc6a_0014bd94\n"
        "movl imp_cl_paused, %esi\n" /* line 2859 */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf14bc6a_0014bda1\n"
        ".Lf14bc6a_0014bcce:\n"
        "movl 8(%eax), %edi\n" /* line 2827 */
        "testl %edi, %edi\n"
        "je .Lf14bc6a_0014bd30\n"
        "movl imp_sv_paused, %eax\n"
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
        "movl cls+280, %eax\n"
        "subl 0x10(%ebx), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
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
        "movl $str_002a8c3c, 4(%esp)\n" /* line 2834 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14bc6a_0014bcfd\n"
        ".Lf14bc6a_0014bd94:\n"
        "movl imp_cl_paused, %esi\n"
        "movl (%esi), %eax\n"
        "jmp .Lf14bc6a_0014bcce\n"
        ".Lf14bc6a_0014bda1:\n"
        "movl imp_dvar_modifiedFlags, %edx\n" /* line 2864 */
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
        "movl cls+280, %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
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
        "movl $str_002a969c, (%esp)\n" /* "userinfo "%s"" */
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
        "movl $str_002a8a5c, 4(%esp)\n" /* line 653 */
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
        "movl imp_com_sv_running, %eax\n" /* line 1813 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf14beac_0014c0ff\n"
        "cmpb $0, clients+9\n" /* line 1821 */
        "jne .Lf14beac_0014c090\n"
        "xorl %edi, %edi\n" /* clientStateBuf */
        "movl $0, -0x43c(%ebp)\n" /* clientStateBytes */
        ".Lf14beac_0014bee2:\n"
        "movl $0, 4(%esp)\n" /* line 1833 */
        "movl imp_com_expectedHunkUsage, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movb $0, g_waitingForServer\n" /* line 1835 */
        "movl $1, (%esp)\n" /* line 1838 */
        "calll SND_StopSounds\n"
        "movl cls+4, %ebx\n" /* line 1108 */
        "testl %ebx, %ebx\n"
        "jne .Lf14beac_0014c1db\n"
        ".Lf14beac_0014bf1a:\n"
        "movl re+328, %eax\n" /* line 3208 */
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
        "movl $0, cls+264\n" /* line 1844 */
        "movl $str_002a96d4, (%esp)\n" /* line 1788 */
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
        "movl $str_00216a14, (%esp)\n" /* "loc_language" */
        "calll Dvar_RegisterInt\n"
        "movl $0x1020, 8(%esp)\n" /* line 1855 */
        "movl $1, 4(%esp)\n"
        "movl $str_00216a38, (%esp)\n" /* "loc_translate" */
        "calll Dvar_RegisterBool_mac\n"
        "movl $0x10a0, 8(%esp)\n" /* line 1856 */
        "movl $0, 4(%esp)\n"
        "movl $str_00216d78, (%esp)\n" /* "fs_ignoreLocalized" */
        "calll Dvar_RegisterBool_mac\n"
        "movl 0x12c(%ebx), %eax\n" /* line 1860 */
        "movl %eax, (%esp)\n"
        "calll FS_ConditionalRestart\n"
        "calll SEH_UpdateLanguageInfo\n" /* line 1861 */
        "movl $0, 4(%esp)\n" /* line 1865 */
        "movl imp_cl_paused, %eax\n"
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
        "movl $str_002a96ac, (%esp)\n" /* line 1815 */
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
        "movl $str_002a96d8, 8(%esp)\n" /* line 1772 */
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
        "movl $str_002a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%ebx), %edx\n"
        "jmp .Lf14beac_0014bf8d\n"
        ".Lf14beac_0014c1db:\n"
        "calll CL_ShutdownCGame\n" /* line 1115 */
        "calll CL_ShutdownUI\n" /* line 1118 */
        "movl $0, cls+0x2a0a58\n" /* line 3267 */
        "movl $0, cls+0x2a0a5c\n" /* line 3268 */
        "movl $0, cls+0x2a0a60\n" /* line 3269 */
        "movl $0, cls+4\n" /* line 1130 */
        "jmp .Lf14beac_0014bf1a\n"
        ".Lf14beac_0014c212:\n"
        "movl $str_002a8a5c, 4(%esp)\n" /* line 653 */
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
        "movl imp_com_sv_running, %eax\n" /* line 1910 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf14c258_0014c282\n"
        "movl $str_002a96dc, (%esp)\n" /* line 1912 */
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
        "movl imp_legacyHacks, %esi\n" /* line 1387 */
        "movl (%esi), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14c330_0014c47c\n"
        "movl clientConnections+264092, %edi\n" /* line 1390 */
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
        "movl imp_sv_disableClientConsole, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "movl imp_cl_connectedToPureServer, %eax\n" /* line 1463 */
        "movl $0, (%eax)\n"
        "movl imp_fs_checksumFeed, %eax\n" /* line 1464 */
        "movl $0, (%eax)\n"
        "movl imp_bgs, %eax\n" /* line 1492 */
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
        "movl $str_00228e90, (%esp)\n" /* "disconnect" */
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
        "movl $str_002a9704, (%esp)\n" /* line 4276 */
        "calll Com_Printf\n"
        "movl recursive, %eax\n" /* line 4278 */
        "testl %eax, %eax\n"
        "je .Lf14c5ac_0014c5d5\n"
        "movl $str_002a9720, (%esp)\n" /* line 4280 */
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
        "movl cls+4, %eax\n" /* line 1108 */
        "testl %eax, %eax\n"
        "jne .Lf14c5ac_0014c85a\n"
        ".Lf14c5ac_0014c603:\n"
        "calll SND_Shutdown\n" /* line 4293 */
        "movl re+328, %eax\n" /* line 3208 */
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
        "movl $str_002a9034, (%esp)\n" /* line 4298 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9038, (%esp)\n" /* line 4299 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9048, (%esp)\n" /* line 4300 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9054, (%esp)\n" /* line 4302 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9060, (%esp)\n" /* line 4305 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_00228e90, (%esp)\n" /* line 4307 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a906c, (%esp)\n" /* line 4308 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9080, (%esp)\n" /* line 4309 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a90a4, (%esp)\n" /* line 4310 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a90b8, (%esp)\n" /* line 4311 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9074, (%esp)\n" /* line 4312 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a90c0, (%esp)\n" /* line 4313 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a90c8, (%esp)\n" /* line 4314 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a90d4, (%esp)\n" /* line 4315 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a90e4, (%esp)\n" /* line 4316 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a6fbc, (%esp)\n" /* line 4317 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9118, (%esp)\n" /* line 4318 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a90f4, (%esp)\n" /* line 4319 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a90fc, (%esp)\n" /* line 4320 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9120, (%esp)\n" /* line 4321 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9128, (%esp)\n" /* line 4322 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9138, (%esp)\n" /* line 4323 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a914c, (%esp)\n" /* line 4325 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a915c, (%esp)\n" /* line 4326 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9734, (%esp)\n" /* line 4329 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9748, (%esp)\n" /* line 4330 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a975c, (%esp)\n" /* line 4331 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a916c, (%esp)\n" /* line 4334 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9770, (%esp)\n" /* line 4335 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9778, (%esp)\n" /* line 4336 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9180, (%esp)\n" /* line 4338 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a9190, (%esp)\n" /* line 4340 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a919c, (%esp)\n" /* line 4341 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a91c4, (%esp)\n" /* line 4343 */
        "calll Cmd_RemoveCommand\n"
        "movl $str_002a91d0, (%esp)\n" /* line 4344 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x2a0ab4, 8(%esp)\n" /* line 4346 - sizeof(cls), was symbolized as str_002a0ab4 */
        "movl $0, 4(%esp)\n"
        "movl $cls, (%esp)\n"
        "calll memset\n"
        ".Lf14c5ac_0014c80b:\n"
        "movl imp_legacyHacks, %eax\n" /* line 4349 */
        "movl (%eax), %eax\n"
        "movl $0, 4(%eax)\n"
        "movl $0, recursive\n" /* line 4351 */
        "movl $str_002a9788, (%esp)\n" /* line 4353 */
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
        "movl $0, cls+0x2a0a58\n" /* line 3267 */
        "movl $0, cls+0x2a0a5c\n" /* line 3268 */
        "movl $0, cls+0x2a0a60\n" /* line 3269 */
        "movl $0, cls+4\n" /* line 1130 */
        "jmp .Lf14c5ac_0014c603\n"
    );
}

/* line 1721 */
void CL_Disconnect_f(void)
{
    int prevState;

    SCR_StopCinematic();
    prevState = **(int **)imp_clc;
    CL_Disconnect();

    if (prevState > 2) {
        /* CL_AllLocalClientsDisconnected check */
        if (Sys_IsMainThread() && !UI_IsFullscreen() && *(byte *)&clients[0] != 0 && *(int *)&clientConnections[0] > 2)
            return;
        Com_Error(3, str_002a97a4);
    }
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
        "movl imp_legacyHacks, %esi\n" /* line 1188 */
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
        "movl $0, clients+4\n" /* line 1197 */
        "movb $0, clients+8\n" /* line 1198 */
        "cmpl $4, clientConnections\n" /* line 1211 */
        "jg .Lf14c8f6_0014c9f6\n"
        ".Lf14c8f6_0014c93e:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 1239 */
        "movl imp_nextmap, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $0x100, 8(%esp)\n" /* line 1240 */
        "movl $str_002a8ab8, 4(%esp)\n" /* "localhost" */
        "movl $cls+8, (%esp)\n"
        "calll I_strncpyz\n"
        "calll CL_Disconnect\n" /* line 1249 */
        "calll UI_CloseAll\n" /* line 1251 */
        "movl clc, %eax\n" /* line 1253 */
        "movl $4, (%eax)\n"
        "movl $0xfffff448, 0x20(%eax)\n" /* line 1254 */
        "movl imp_g_qport, %edx\n" /* line 1255 */
        "movl (%edx), %edx\n"
        "movl %edx, 4(%eax)\n"
        "addl $0x14, %eax\n" /* line 1256 */
        "movl %eax, 4(%esp)\n"
        "movl $cls+8, (%esp)\n"
        "calll NET_StringToAdr\n"
        "calll CL_CheckForResend\n" /* line 1258 */
        "movl $0x40, 8(%esp)\n" /* line 1260 */
        "movl 8(%ebp), %eax\n" /* mapname */
        "movl %eax, 4(%esp)\n"
        "movl imp_legacyHacks, %ebx\n"
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
        "movl $str_002a8ab8, 4(%esp)\n" /* line 1211 */
        "movl $cls+8, (%esp)\n"
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
        "movl clientConnections+264100, %eax\n" /* line 888 */
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
        "movl $str_002a97a4, 4(%esp)\n" /* line 1733 */
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
        "movsd lit8_00307d50, %xmm2\n" /* 1000.0 */
        "mulsd %xmm2, %xmm0\n"
        "divsd %xmm1, %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "divsd %xmm2, %xmm1\n"
        "movsd %xmm1, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002a97c4, (%esp)\n" /* "%i frames, %3.1f seconds: %3.1f fps
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
        "movl clientConnections+264112, %eax\n" /* line 921 */
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
        "movl $str_002a981c, (%esp)\n" /* line 959 */
        "calll Com_Printf\n"
        "jmp .Lf14cb84_0014cbb4\n"
        ".Lf14cb84_0014cc50:\n"
        "movl $str_002a97ec, 4(%esp)\n" /* line 954 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf14cb84_0014cc1e\n"
        ".Lf14cb84_0014cc66:\n"
        "movl cls+280, %eax\n" /* line 964 */
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
        "movl $str_002a9838, (%esp)\n" /* "%s <demoname>
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
        "movl imp_com_sv_running, %eax\n" /* line 999 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf14ccac_0014cd0d\n"
        "movl $str_002a9848, (%esp)\n" /* line 1001 */
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
        "movl $str_002a986c, 8(%esp)\n" /* ".dm_%d" */
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
        "movl $str_002a9874, 8(%esp)\n" /* "demos/%s" */
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
        "movl $str_002a9088, 4(%esp)\n" /* "timedemo" */
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
        "movl $cls+8, (%esp)\n"
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
        "movl $str_002a9238, 8(%esp)\n" /* "demos/%s.dm_%d" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x138(%ebp), %esi\n" /* name, arg */
        "movl %esi, (%esp)\n" /* arg */
        "calll Com_sprintf\n"
        "jmp .Lf14ccac_0014cd9e\n"
        ".Lf14ccac_0014cec3:\n"
        "movl %esi, 4(%esp)\n" /* line 1023 | arg */
        "movl $str_002a9880, (%esp)\n" /* "EXE_ERR_NOT_FOUND%s" */
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
        "movl $str_002a9898, (%esp)\n" /* "Unknown command "%s"
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
        "movl $str_002a8a5c, 4(%esp)\n" /* line 653 */
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
        "movl $str_002a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%esi), %edx\n"
        "jmp .Lf14cee8_0014cfbb\n"
    );
}

/* CL_ForwardToServer_f — forward console command to server via reliable command buffer */
/* externs already declared above */
void CL_ForwardToServer_f(void)
{
    if (*(int *)clientConnections != 8 || *(int *)(clientConnections + 264096) != 0) {
        Com_Printf("Not connected to a server.\n");
        return;
    }
    if (Cmd_Argc() <= 1) return;
    const char *cmd = (const char *)Cmd_Args(1);
    /* Write to reliable command buffer */
    byte *c = (byte *)&clc;
    int seq = *(int *)(c + 0x130);
    int acked = *(int *)(c + 0x134);
    if (seq - acked - 128 > 0) {
        Com_Error(1, "CL_ForwardToServer_f: MAX_RELIABLE_COMMANDS exceeded\n");
    }
    seq++;
    *(int *)(c + 0x130) = seq;
    int slot = seq & 0x7f;
    byte *buf = c + 0x138 + slot * 0x400;
    MSG_WriteReliableCommandToBuffer(cmd, buf, 0x400);
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
        "movl clientConnections+264024, %esi\n" /* line 2059 */
        "testl %esi, %esi\n"
        "jne .Lf14d0be_0014d28b\n"
        "movl $6, clientConnections\n" /* line 2081 */
        "movl imp_com_sv_running, %eax\n" /* line 2083 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf14d0be_0014d1d2\n"
        "movl cl, %eax\n" /* line 2119 */
        "cmpb $0, 9(%eax)\n"
        "jne .Lf14d0be_0014d1c8\n"
        ".Lf14d0be_0014d101:\n"
        "movl $1, 4(%esp)\n" /* line 2123 */
        "movl imp_cl_paused, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "jmp .Ldbg_dl1_skip\n"
        ".Ldbg_dl1_str: .asciz \"DBG: CL_DownloadsComplete calling CL_InitCGame\\n\"\n"
        ".Ldbg_dl1_skip:\n"
        "pushl $.Ldbg_dl1_str\n"
        "calll Com_Printf\n"
        "addl $4, %esp\n"
        /* Diagnostic: print connstate before CL_InitCGame */
        "jmp .Ldbg_st1_skip\n"
        ".Ldbg_st1_str: .asciz \"DBG: connstate before CL_InitCGame = %d\\n\"\n"
        ".Ldbg_st1_skip:\n"
        "pushl clientConnections\n"
        "pushl $.Ldbg_st1_str\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        "calll CL_InitCGame\n" /* line 2126 */
        "jmp .Ldbg_dl2_skip\n"
        ".Ldbg_dl2_str: .asciz \"DBG: CL_InitCGame returned, connstate = %d\\n\"\n"
        ".Ldbg_dl2_skip:\n"
        "pushl clientConnections\n"
        "pushl $.Ldbg_dl2_str\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        /* Fix #152: Clear cl_paused after CL_InitCGame to prevent
         * server pause deadlock. cl_paused=1 was set above to tell
         * the server to pause during cgame loading. Now loading is
         * done, so clear it so the server resumes ticking and sends
         * the first snapshot. */
        "movl $0, 4(%esp)\n"
        "movl imp_cl_paused, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "calll FS_ReferencedIwdPureChecksums\n" /* line 1769 */
        "movl %eax, %ebx\n"
        "movl $str_002a96d8, 8(%esp)\n" /* line 1772 */
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
        "movl $str_002a7124, 4(%esp)\n" /* line 2086 */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %esi\n" /* mapname */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002a7100, 4(%esp)\n" /* line 2087 */
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
        "movl re+328, %eax\n" /* line 1141 */
        "testl %eax, %eax\n"
        "je .Lf14d0be_0014d24d\n"
        "calll *%eax\n" /* line 1142 */
        ".Lf14d0be_0014d24d:\n"
        "movl cls+4, %ebx\n" /* line 1108 */
        "testl %ebx, %ebx\n"
        "jne .Lf14d0be_0014d2fe\n"
        ".Lf14d0be_0014d25b:\n"
        "movl re, %eax\n" /* line 1147 */
        "testl %eax, %eax\n"
        "je .Lf14d0be_0014d26d\n"
        "movl $0, (%esp)\n" /* line 1149 */
        "calll *%eax\n"
        ".Lf14d0be_0014d26d:\n"
        "movl $0, cls+264\n" /* line 1156 */
        "calll Com_Restart\n" /* line 2103 */
        "calll CL_StartHunkUsers\n" /* line 2111 */
        "calll SCR_UpdateScreenInternal\n" /* line 2113 */
        "jmp .Lf14d0be_0014d101\n"
        ".Lf14d0be_0014d28b:\n"
        "movl $0, clientConnections+264024\n" /* line 2062 */
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
        "movl $str_002a98b0, (%esp)\n" /* "donedl" */
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
        "movl $0, cls+0x2a0a58\n" /* line 3267 */
        "movl $0, cls+0x2a0a5c\n" /* line 3268 */
        "movl $0, cls+0x2a0a60\n" /* line 3269 */
        "movl $0, cls+4\n" /* line 1130 */
        "jmp .Lf14d0be_0014d25b\n"
        ".Lf14d0be_0014d335:\n"
        "movl $str_002a8a5c, 4(%esp)\n" /* line 653 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x130(%ebx), %edx\n"
        "jmp .Lf14d0be_0014d189\n"
        ".Lf14d0be_0014d354:\n"
        "movl $str_002a8a5c, 4(%esp)\n" /* "EXE_ERR_CLIENT_CMD_OVERFLOW" */
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
        "movl $str_002a98b8, (%esp)\n" /* "***** CL_BeginDownload *****
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
        "movl $str_002a9910, 8(%esp)\n" /* "%s.tmp" */
        "movl $0x100, 4(%esp)\n"
        "leal 0x40148(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $0x40, 8(%esp)\n" /* line 2158 */
        "movl %esi, 4(%esp)\n" /* remoteName */
        "movl imp_legacyHacks, %ebx\n" /* localName */
        "movl (%ebx), %eax\n" /* localName */
        "addl $0x1c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl (%ebx), %eax\n" /* line 2159 | localName */
        "movl $0, 0x10(%eax)\n"
        "movl (%ebx), %eax\n" /* line 2160 | localName */
        "movl $0, 0x14(%eax)\n"
        "movl (%ebx), %edx\n" /* line 2161 | localName */
        "movl cls+280, %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl $0, 0x4034c(%edi)\n" /* line 2163 */
        "movl $0, 0x40350(%edi)\n" /* line 2164 */
        "movl %esi, 4(%esp)\n" /* line 2166 | remoteName */
        "movl $str_002a9918, (%esp)\n" /* "download %s" */
        "calll va\n"
        "movl %eax, %ebx\n" /* cmd */
        /* { scope 1 */
        "movl 0x130(%edi), %edx\n" /* line 651 */
        "movl %edx, %eax\n"
        "subl 0x134(%edi), %eax\n"
        "addl $-0x80, %eax\n"
        "jle .Lf14d374_0014d467\n"
        "movl $str_002a8a5c, 4(%esp)\n" /* line 653 */
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
        "cmpb $0, clientConnections+263000\n" /* line 2183 */
        "je .Lf14d4a0_0014d54f\n"
        "movl $clientConnections+263000, -0x1c(%ebp)\n" /* line 2191 | s */
        "cmpb $0x40, clientConnections+263000\n"
        "movl $clientConnections+263001, %eax\n"
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
        "jmp .Ldbg_dl3_skip\n"
        ".Ldbg_dl3_str: .asciz \"DBG: CL_InitDownloads entered\\n\"\n"
        ".Ldbg_dl3_skip:\n"
        "movl $.Ldbg_dl3_str, (%esp)\n"
        "calll Com_Printf\n"
        /* { scope 1 */
        "movl $7, 4(%esp)\n" /* line 2234 */
        "movl $str_002a9924, (%esp)\n" /* "ni]Zm^l" */
        "calll FS_ShiftStr\n"
        "movl imp_com_sv_running, %eax\n" /* line 2249 */
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
        "movl $str_002a992c, (%esp)\n" /* "
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
        "movl $str_00218054, (%esp)\n" /* "Need iwds: %s
" */
        "calll Com_Printf\n"
        "cmpb $0, 0x40358(%ebx)\n" /* line 2268 */
        "je .Lf14d570_0014d5c9\n"
        "movl $5, (%ebx)\n" /* line 2271 */
        "calll CL_NextDownload\n" /* line 2272 */
        "jmp .Lf14d570_0014d5ce\n"
    );
}
#else
void CL_GetPing(int n, char *buf, int buflen, int *pingtime) {
    ping_t *ping = &cl_pinglist[n];
    int time;
    const char *adrStr;

    /* Check if ping slot is active (port != 0) */
    if (ping->adr.port == 0) {
        buf[0] = '\0';
        *pingtime = 0;
        return;
    }

    /* Get address string */
    adrStr = NET_AdrToString(ping->adr.type, *(int *)ping->adr.ip, ping->adr.port);
    I_strncpyz(buf, adrStr, buflen);

    /* Get ping time */
    time = ping->time;
    if (time == 0) {
        /* Compute elapsed time */
        int maxPing;
        time = Sys_Milliseconds() - ping->start;
        maxPing = Dvar_GetInt("cl_maxPing");
        if (maxPing <= 99)
            maxPing = 100;
        if (maxPing > time)
            time = 0;
    }

    /* Set server info */
    CL_SetServerInfoByAddress(ping->adr.type, *(int *)ping->adr.ip, ping->adr.port, ping->info, ping->time);
    *pingtime = time;
}
#endif
