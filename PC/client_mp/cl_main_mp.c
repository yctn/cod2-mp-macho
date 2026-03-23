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
extern void CL_PlayCinematic_f(void);
extern void CL_Connect_f(void);
extern void CL_GlobalServers_f(void);
extern void CL_Rcon_f(void);
extern void CL_Ping_f(void);
extern void CL_ServerStatus_f(void);
extern void CL_UpdateLevelHunkUsage(void);
extern void SCR_UpdateScreen(void);
extern void CL_CubemapShot_f(void);
extern void Com_WriteLocalizedSoundAliasFiles(void);
extern void UI_OpenMenu_f(void);
extern void UI_CloseMenu_f(void);
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
    if (clientConnections[0].reliableSequence - clientConnections[0].reliableAcknowledge - 128 > 0)
    {
        Com_Error(1, "CL_AddReliableCommand: too many commands");
    }
    ((clientConnection_t *)clc)->reliableSequence += 1;
    index = clc->reliableSequence & 0x7f;
    MSG_WriteReliableCommandToBuffer(cmd, (char *)clc->reliableCommands[index], 0x400);
}

/* line 700 */
void CL_StopRecord_f(void)
{
    byte *cc = (byte *)&clientConnections[0];
    int len;

    if (!((clientConnection_t *)cc)->demorecording) {
        Com_Printf(str_002a8a78);
        return;
    }

    len = -1;
    FS_Write(&len, 4, ((clientConnection_t *)cc)->demofile);
    FS_Write(&len, 4, ((clientConnection_t *)cc)->demofile);
    FS_FCloseFile(((clientConnection_t *)cc)->demofile);
    ((clientConnection_t *)cc)->demofile = 0;
    ((clientConnection_t *)cc)->demorecording = 0;
    Com_Printf(str_002a8a90);
}

/* line 1161 */
void CL_ShutdownDemo(void)
{
    if (!clientConnections[0].demofile)
        return;
    FS_FCloseFile(clientConnections[0].demofile);
    ((clientConnection_t *)clc)->demofile = 0;
    ((clientConnection_t *)clc)->demoplaying = 0;
    ((clientConnection_t *)clc)->demorecording = 0;
}

/* line 1272 */
int CL_GetSkelTimeStamp(int localClientNum)
{
    char *client = (char *)&clients + (unsigned)localClientNum * 386821 * 4;
    return ((clientActive_t *)client)->skelTimeStamp;
}

/* line 1279 */
char * CL_AllocSkelMemory(int localClientNum, unsigned int size)
{
    char *client = (char *)&clients + (unsigned)localClientNum * 386821 * 4;
    int pos = ((clientActive_t *)client)->skelMemPos;
    char *buf = (char *)(pos + (int)((clientActive_t *)client)->skelMemoryStart);
    int newPos = pos + ((size + 15) & ~15);
    ((clientActive_t *)client)->skelMemPos = newPos;
    if (newPos >= 0x3fff1)
        return 0;
    return buf;
}

/* line 1318 */
void CL_ResetSkeletonCache(int localClientNum)
{
    char *client = (char *)&clients + (unsigned)localClientNum * 386821 * 4;
    unsigned int count = ((clientActive_t *)client)->skelTimeStamp + 1;
    if (!count)
        count = 1;
    ((clientActive_t *)client)->skelTimeStamp = count;
    ((clientActive_t *)client)->skelMemoryStart = (char *)(((int)(client + 0x8663)) & ~15);
    ((clientActive_t *)client)->skelMemPos = 0;
}

/* line 1343 */
void CL_ClearState(void)
{
    byte *cl = (byte *)&clients[0];
    byte cgameInitialized, cgameInitCalled, displayHUD, active;
    int keyCatchers;

    /* Save fields that survive the clear */
    cgameInitialized = ((clientActive_t *)cl)->cgameInitialized;
    cgameInitCalled = ((clientActive_t *)cl)->cgameInitCalled;
    keyCatchers = ((clientActive_t *)cl)->keyCatchers;
    displayHUD = ((clientActive_t *)cl)->displayHUDWithKeycatchUI;
    active = ((clientActive_t *)cl)->active;

    memset(&clients[0], 0, 0x179c14);

    /* Restore preserved fields */
    cl = (byte *)&clients[0];
    ((clientActive_t *)cl)->cgameInitialized = cgameInitialized;
    ((clientActive_t *)cl)->cgameInitCalled = cgameInitCalled;
    ((clientActive_t *)cl)->keyCatchers = keyCatchers;
    ((clientActive_t *)cl)->displayHUDWithKeycatchUI = displayHUD;
    ((clientActive_t *)cl)->active = active;

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
    char *server = cls.servername;

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
        offset = ((clientActive_t *)cl)->gameState.stringOffsets[i];
        if (offset)
            Com_Printf(str_002a8b40, i, ((clientActive_t *)cl)->gameState.stringData + offset);
    }
}

/* line 1998 */
extern const char *Dvar_InfoString(int bit);
extern void Info_Print(const char *s);
void CL_Clientinfo_f(void)
{
    Com_Printf(str_002a8b4c);
    Com_Printf(str_002a8b74, **(int **)imp_clc);
    Com_Printf(str_002a74a0, cls.servername);
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
    LegacyHacks *hacks = *(LegacyHacks **)imp_legacyHacks;

    Com_Printf("Server changing map %s, gametype %s\n", pszMapName, pszGametype);
    I_strncpyz(hacks->cl_serverloadmap, pszMapName, sizeof(hacks->cl_serverloadmap));
    I_strncpyz(hacks->cl_serverloadgametype, pszGametype, sizeof(hacks->cl_serverloadgametype));
    hacks->cl_serverloadwaiting = 0;

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
    int voiceLen = ((clientActive_t *)cl)->voicePacketCount;

    if (voiceLen <= 0)
        return;

    /* Send if enough time passed or enough data buffered */
    if (*(int *)((byte *)&clients[0] + 9968) - ((clientActive_t *)cl)->voicePacketLastTransmit > 199 || voiceLen > 9) {
        CL_WriteVoicePacket();
        cl = *(byte **)imp_cl;
        ((clientActive_t *)cl)->voicePacketCount = 0;
        ((clientActive_t *)cl)->voicePacketLastTransmit = ((clientActive_t *)cl)->serverTime;
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
    if ((*(clientActive_t **)imp_cl)->voicePacketCount)
        return 1;

    return 0;
}

/* line 4979 */
void CL_SyncGpu(void)
{
    re.SyncGpu();
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
    void (*shutdownInput)(void) = re.SyncRenderThread;
    void (*shutdown)(int) = re.Shutdown;

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
    re.BeginRegistration(&cls.vidConfig);
    /* Parameters: safeAreaH, safeAreaV, viewportX, viewportY, viewportW, viewportH */
    {
        int vw = cls.vidConfig.width; /* vidConfig.width from BeginRegistration output */
        int vh = cls.vidConfig.height; /* vidConfig.height */
        SetScreenScaling(1.0f, 1.0f, 0, 0, vw, vh);
    }

    /* cls.charSetShader = re.RegisterMaterial("white", 3, 3) */
    cls.whiteMaterial = re.RegisterMaterial("white", 3, 3);
    /* cls.whiteShader = re.RegisterMaterial("console", 3, 3) */
    cls.consoleMaterial = re.RegisterMaterial("console", 3, 3);
    /* cls.consoleFont = re.RegisterFont("fonts/consoleFont", 3) */
    cls.consoleFont = re.RegisterFont("fonts/consoleFont", 3);

    fieldWidth = cls.vidConfig.width - 0x20;
    *(int *)imp_g_console_field_width = fieldWidth;

    ((field_t *)imp_g_consoleField)->widthInPixels = fieldWidth;
    *(float *)&((field_t *)imp_g_consoleField)->charHeight = *(float *)imp_g_console_char_height;
    ((field_t *)imp_g_consoleField)->fixedSize = 1;

    StatMon_Reset();
}

/* line 3342 */
void CL_StartHunkUsers(void)
{
    LegacyHacks *hacks = *(LegacyHacks **)imp_legacyHacks;

    if (!hacks->cl_running)
        return;

    if (!cls.soundStarted) {
        cls.soundStarted = 1;
        SND_Init();
        Sys_LoadingKeepAlive();
    }

    if (!cls.rendererStarted) {
        cls.rendererStarted = 1;
        CL_InitRenderer();
        Sys_LoadingKeepAlive();
    }

    if (!cls.uiStarted) {
        CL_InitUI();
        Sys_LoadingKeepAlive();
    }

    cls.hunkUsersStarted = 1;
}

/* line 3386 */
int CL_ScaledMilliseconds(void)
{
    return cls.realtime;
}

/* line 3422 */
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
    if (clientConnections[0].demoplaying != 0 || (*(LegacyHacks **)imp_legacyHacks)->cl_serverloadwaiting != 0) {
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

    if (!(*(LegacyHacks **)imp_legacyHacks)->ui_scriptMenuAllowResponse)
        return;
    if (!cls.uiStarted)
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
    Cmd_AddCommand("cinematic", CL_PlayCinematic_f);
    Cmd_SetAutoComplete("cinematic", "video", str_00216ce4);
    Cmd_AddCommand("logo", CL_PlayLogo_f);
    Cmd_AddCommand("connect", CL_Connect_f);
    Cmd_AddCommand("reconnect", CL_Reconnect_f);
    Cmd_AddCommand("localservers", CL_LocalServers_f);
    Cmd_AddCommand("globalservers", CL_GlobalServers_f);
    CL_RconInit();
    Cmd_AddCommand("rcon", CL_Rcon_f);
    Cmd_AddCommand("ping", CL_Ping_f);
    Cmd_AddCommand("serverstatus", CL_ServerStatus_f);
    Cmd_AddCommand("toggleMenu", CL_ToggleMenu_f);
    Cmd_AddCommand("setenv", CL_Setenv_f);
    Cmd_AddCommand("showip", CL_ShowIP_f);
    Cmd_AddCommand("fs_openedList", CL_OpenedIWDList_f);
    Cmd_AddCommand("fs_referencedList", CL_ReferencedIWDList_f);
    Cmd_AddCommand("updatehunkusage", CL_UpdateLevelHunkUsage);
    Cmd_AddCommand("updatescreen", SCR_UpdateScreen);
    Cmd_AddCommand("startSingleplayer", CL_startSingleplayer_f);
    Cmd_AddCommand("setRecommended", CL_SetRecommended_f);
    Cmd_AddCommand("cubemapShot", CL_CubemapShot_f);
    Cmd_AddCommand("openScriptMenu", CL_OpenScriptMenu_f);
    Cmd_AddCommand("localizeSoundAliasFiles", Com_WriteLocalizedSoundAliasFiles);
    Cmd_AddCommand("openmenu", UI_OpenMenu_f);
    Cmd_AddCommand("closemenu", UI_CloseMenu_f);

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
    shutdownDebug = re.ShutdownDebug;
    if (shutdownDebug)
        shutdownDebug();
}

/* line 4449 */
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
