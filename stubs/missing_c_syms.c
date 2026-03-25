/* Auto-generated stubs for missing symbols */

int CAudioRecorder_GetBuffer(void) { return 0; }
int CAudioRecorder_Initialize(void) { return 0; }
int CAudioRecorder_SetRecordLevel(void) { return 0; }
int CAudioRecorder_Shutdown(void) { return 0; }
int CSoundEngine_NewSampleSound(void) { return 0; }
int CSoundEngine_NewSampleSound3D(void) { return 0; }
int CSoundEngine_set_digital_master_room_type(void) { return 0; }
int CSoundObject_CSoundObject(void) { return 0; }
int CSoundObject_get_3D_position(void) { return 0; }
int CSoundObject_get_sample_length(void) { return 0; }
int CSoundObject_get_sample_playback_rate(void) { return 0; }
int CSoundObject_get_sample_position(void) { return 0; }
int CSoundObject_get_sample_status(void) { return 0; }
int CSoundObject_get_sample_volume(void) { return 0; }
int CSoundObject_get_sample_volume_levels(void) { return 0; }
int CSoundObject_get_sample_volume_pan(void) { return 0; }
int CSoundObject_get_stream_info(void) { return 0; }
int CSoundObject_init_sample(void) { return 0; }
int CSoundObject_load_sample_buffer(void) { return 0; }
int CSoundObject_sample_buffer_ready(void) { return 0; }
int CSoundObject_set_3D_position(void) { return 0; }
int CSoundObject_set_3D_sample_effects_level(void) { return 0; }
int CSoundObject_set_file_callbacks(void) { return 0; }
int CSoundObject_set_sample_adpcm_block_size(void) { return 0; }
int CSoundObject_set_sample_info(void) { return 0; }
int CSoundObject_set_sample_loop_count(void) { return 0; }
int CSoundObject_set_sample_position(void) { return 0; }
int CSoundObject_set_sample_reverb_levels(void) { return 0; }
int CSoundObject_set_sample_volume(void) { return 0; }
int CSoundObject_set_sample_volume_levels(void) { return 0; }
void R_LoadAabbTrees(void) {}
void R_LoadCells(void) {}
void R_LoadCullGroups(void) {}
void R_LoadEntities_stub(void) {}
void R_LoadNodesAndLeafs(void) {}
void R_LoadOccluders(void) {}
void R_LoadPortals(void) {}
void R_LoadPortalVerts(void) {}
void R_LoadSurfaces(void) {}
void ZN14CAudioRecorderD1Ev(void) {}

/* Console/UI stubs */
void CL_ConsolePrint(int channel, const char *txt, int duration, int linewidth) {}

/* MSG_Init: initialize a message buffer */
#include "common_types.h"
void MSG_Init(msg_t *buf, byte *data, int length) {
    memset(buf, 0, sizeof(*buf));
    buf->data = data;
    buf->maxsize = length;
}
void UI_SetMap(const char *mapname, const char *gametype) {}
void CL_StartHunkUsers(void) {}

/* Stubs for functions called during map loading */
int Com_LoadVolumeFalloffCurve(const char *name, void *curve) { return 1; }
int Com_InitDefaultSoundAliasVolumeFalloffCurve(void *curve) { return 1; }

/* FS_FOpenFileByMode - dispatches to read/write/append */
extern int FS_FOpenFileRead(const char *, int *, int);
extern int FS_FOpenFileWrite(const char *);
int FS_FOpenFileByMode(const char *qpath, int *f, int mode) {
    switch (mode) {
    case 0: /* FS_READ */
        return FS_FOpenFileRead(qpath, f, 1);
    case 1: /* FS_WRITE */
        *f = FS_FOpenFileWrite(qpath);
        return (*f == 0) ? -1 : 0;
    case 2: /* FS_APPEND */
    case 3: /* FS_APPEND_SYNC */
        *f = FS_FOpenFileWrite(qpath); /* approximation */
        return (*f == 0) ? -1 : 0;
    default:
        if (f) *f = 0;
        return -1;
    }
}

/* Game init stubs */
void G_SetupWeaponDef(void) {}
void Scr_FreeEntityList(void) {}
void Scr_AllocGameVariable(void) {}
void Scr_LoadGameType(void) {}
void Scr_StartupGameType(void) {}
/* GScr_LoadScripts is now real - in g_scr_main_mp.c */
void Scr_SetClassMap(int classnum) {}
void ScriptParse(void *parseData, int a2) { Com_Printf("ScriptParse: stub (script compiler not yet implemented)\n"); }
void ScriptCompile(void *parseData, unsigned int compiledObj, unsigned int scriptId) {}
void GScr_AddFieldsForHudElems(void) {}

/* UI functions - stub for rendering */
int UI_IsFullscreen(void) { return 0; }
int UI_GetActiveMenu(void) { return 0; }
void UI_SetActiveMenu(int menu) {}
void UI_DrawMenu(void) {}
void UI_Refresh(int time) {}

/* CGame rendering - stubs */
/* CG_DrawActiveFrame moved to PC/cgame_mp/cg_view_mp.c */
void CL_CGameRendering(int serverTime) {}

/* RE_ renderer interface wrappers */
extern void R_BeginFrame(void);
extern void R_EndFrame(void);
extern void R_RenderScene(void *refdef);
void RE_BeginFrame(void) { R_BeginFrame(); }
void RE_EndFrame(void) { R_EndFrame(); }
void RE_RenderScene(void *refdef) { R_RenderScene(refdef); }

/* Client functions needed for render path */
void CL_ShutdownCGame(void) {}
void CIN_CloseAllVideos(void) {}
void SND_ShutdownChannels(void) {}
void Scr_FreeScripts(int a) {}
void Scr_BeginLoadAnimScripts(void) {}
void GScr_LoadAnimScripts(void) {}
void Scr_EndLoadAnimScripts(void) {}
void G_RegisterDvars_impl(void) {}
void Scr_LoadLevel(void) {}
int Scr_ExecThread(int handle, int params) { return 0; }
void Scr_FreeThread(int threadId) {}
void G_LoadStructs(void) {}
void Scr_SetLoading(int loading) {}
void Scr_InitSystem(void) {}
void Scr_BeginLoadScripts(void) {}
void GScr_LoadConsts(void) {}

void Scr_ParseGameTypeList(void) {}
void CL_InitLoad(const char *server, const char *gametype) {}
/* CL_MapLoading: prepare local client for map loading during devmap.
   Sets client connection state so the engine connects to the loopback server. */
void CL_MapLoading(const char *server) {
    extern clientConnection_t clientConnections[];
    extern void *imp_cls;

    clientConnection_t *clc = &clientConnections[0];

    /* If client isn't even initialized, bail */
    if (!*(int *)&imp_cls)
        return;

    /* If already connected or beyond, just set loading state */
    if (clc->state >= CA_CONNECTED) {
        clc->state = CA_LOADING;
        return;
    }

    /* For devmap: set up loopback connection */
    clc->state = CA_CONNECTED;
    clc->clientNum = 0;

    /* Set the server address to loopback */
    clc->serverAddress.type = 3; /* NA_LOOPBACK */
}
void CL_ShutdownAll(void) {}
void CM_LinkWorld(void) {}
void SV_RunFrame(void) {}

/* SV_Frame — server frame processing.
   Runs game logic and sends snapshots to connected clients.
   Decompiled from Mach-O binary at VMA 0x15b00a. */
extern void G_RunFrame(int levelTime);
extern void SV_ResetSkeletonCache(void);
extern void SV_SendClientMessages(void);
extern void *imp_sv;
extern void *imp_svs;
extern void *imp_com_sv_running;

void SV_Frame(int msec) {
    server_t *sv_local = (server_t *)imp_sv;
    serverStatic_t *svs_local = (serverStatic_t *)imp_svs;

    /* Check if server is running */
    {
        const dvar_t *running = *(const dvar_t **)&imp_com_sv_running;
        if (!running || !running->current.enabled)
            return;
    }

    /* Accumulate time */
    svs_local->time += msec;

    /* Check if it's time for a server frame (sv_fps default = 20) */
    if (svs_local->time - sv_local->start_frameTime < 50)
        return;

    /* Advance server time */
    sv_local->start_frameTime = svs_local->time;

    /* Reset skeleton cache */
    SV_ResetSkeletonCache();

    /* Run game logic frame */
    G_RunFrame(svs_local->time);

    /* Send snapshots to clients */
    SV_SendClientMessages();
}
void SV_DropClient(void *cl, const char *reason) {}
void SV_Heartbeat_f(void) {}
void FS_Restart(int checksumFeed) {}

int COpenGL_sOpenGLE = 0;
int CVAOPacket_sAllPackets[16] = {0};
int CVAOPacket_sCurrentPacket[16] = {0};
int CVAOPacket_sGenericPacket[16] = {0};
int CVAOPacket_sVAOStatus[16] = {0};
int faceAxis[64] = {0};
void *imp__ZTV5Flash = 0;
int iSlotPreferenceOrder[64] = {0};
void Con_Init(void) {}

/* === Stubs for unresolved functions causing SIGSEGV === */
void BG_SetupWeaponIndex(int weapIndex) {}
void BG_SetupWeaponAlts(int weapIndex, void *regWeap) {}
void SV_LinkEntity(void *ent) {}
void DObjCreate(void *models, unsigned short numModels, void *tree, void *buf, unsigned short handle) {}
int Scr_IsValidGameType(const char *gt) { return 1; }
void Com_UnloadSoundAliases(int type) {}
void Com_LoadSoundAliasFile(const char *spec, int loadSpec, const char *filename) {}
void Com_MakeSoundAliasesPermanent(int type) {}
void Scr_Error(const char *msg) { Com_Printf("^1Script Error: %s\n", msg); }
void CL_RunOncePerClientFrame(int msec) {}
void Con_ClearSubtitles(void) {}
void Scr_AddClassField(int classnum, const char *name, unsigned int offset) {}
void Scr_AddFields(const char *name, const void *data) {}
void Scr_NotifyNum(int entnum, int classnum, unsigned short stringValue, int paramcount) {}
void Con_ClearNotify(void) {}
void Scr_PlayerConnect(void *ent) {}
void CL_Init(void) {}
