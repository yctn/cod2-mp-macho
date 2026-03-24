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
void CL_MapLoading(const char *server) {}
void CL_ShutdownAll(void) {}
void CM_LinkWorld(void) {}
void SV_RunFrame(void) {}
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
