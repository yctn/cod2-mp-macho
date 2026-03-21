/* ASM dump from: sv_game_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_game_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void SV_SendServerCommand(void *client, int type, const char *fmt, ...);
extern void SV_DropClient(void *client, const char *reason);
extern const char *Dvar_InfoString(int flag);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void *Hunk_AllocInternal(int size);
extern qboolean Com_ValidXModelName(const char *name);
extern struct XModel *XModelPrecache(const char *name, void *alloc, void *allocColl);
extern void *Com_GetServerDObj(int entityNum);
extern void DObjDumpInfo(void *obj);
extern qboolean DObjUpdateServerInfo(void *obj, float dtime, qboolean bNotify);
extern void DObjInitServerTime(void *obj, float dtime);
extern void DObjGetHierarchyBits(void *obj, int boneIndex, int *partBits);
extern void DObjCalcAnim(void *obj, int *partBits);
extern void DObjCalcSkel(void *obj, int *partBits);
extern int DObjGetBoneIndex(void *obj, unsigned int boneName);
extern DObjAnimMat_s *DObjGetRotTransArray(void *obj);
extern void DObjDisplayAnim(void *obj);
extern struct XAnimTree_s *DObjGetTree(void *obj);
extern const char *SV_GetMapBaseName(const char *name);
extern const char *GetBspExtension(void);
extern const char *va(const char *fmt, ...);
extern int FS_ReadFile(const char *path, void *buffer);
extern const char *CM_EntityString(void);
extern const char *Com_Parse(char **data_p);
extern void Com_SetWeaponInfoMemory(int set);
extern void G_ShutdownGame(int restart);
extern void Com_FreeWeaponInfoMemory(int free_flag);
extern void Com_UnloadSoundAliases(int type);
extern void CM_ModelBounds(unsigned int model, vec_t *mins, vec_t *maxs);
extern void SV_LinkEntity(gentity_t *ent);
extern qboolean ConsoleCommand(void);
extern qboolean NET_IsLocalAddress(int a, int b, int c);
extern dvar_t *Dvar_RegisterString(const char *dvarName, const char *defaultValue, int flags);
extern void Dvar_SetString(dvar_t *dvar, const char *value);
extern qboolean Scr_IsValidGameType(const char *gametype);
extern int ___tolower(int c);
extern void FX_InitServer(void);
extern void G_InitGame(int svTime, int msecRaw, int restart, int savepersist);
extern void Sys_LoadingKeepAlive(void);
extern int Sys_MillisecondsRaw(void);
extern void Com_DvarDump(int channel);
extern void *G_GetSavePersist(void);
extern int SV_ClipHandleForEntity(const gentity_t *gEnt);
extern void CM_TransformedBoxTraceExternal(void *trace, const void *p1, const void *p2, const vec_t *mins, const vec_t *maxs, unsigned int model, int brushmask, const vec_t *origin, const vec_t *angles);
extern float Vec2DistanceSq(const float *p1, const float *p2);
extern int CM_PointLeafnum(const vec_t *p);
extern int CM_LeafCluster(int leafnum);
extern byte *CM_ClusterPVS(int cluster);
extern float G_GetFogOpaqueDistSqrd(void);
extern qboolean BoxDistSqrdExceeds(const vec_t *absmin, const vec_t *absmax, const vec_t *origin, float distSqrd);
extern void AnglesToAxis(const vec_t *angles, float (*axis)[3]);
extern int DObjNumBones(void *obj);
extern void DObjGetBoneInfo(void *obj, void *boneInfo);
extern int DObjGetNumModels(void *obj);
extern qboolean DObjIgnoreCollision(void *obj, int modelIndex);
extern void *DObjGetModel(void *obj, int modelIndex);
extern int XModelNumBones(void *model);
extern void MatrixTransformVector43(const vec_t *in, const float *mat, vec_t *out);
extern void MatrixTransformVector(const vec_t *in, const float (*axis)[3], vec_t *out);
extern void CL_AddDebugLine(const vec_t *start, const vec_t *end, const float *color, int depthTest, int outline, int duration);
extern int DObjSkelExists(void *obj, int timeStamp);
extern qboolean DObjSkelIsBoneUpToDate(void *obj, int boneIndex);
extern qboolean DObjSkelAreBonesUpToDate(void *obj, int *partBits);
extern int DObjGetAllocSkelSize(void *obj);
extern void DObjCreateSkel(void *obj, char *buf, int timeStamp);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 */

extern qboolean gameInitialized; /* 0x0 */
static int warnCount; /* warnCount */
extern int boxVerts[24][3]; /* boxVerts */
static char g_sv_skel_memory[262144]; /* g_sv_skel_memory */
static char *g_sv_skel_memory_start; /* g_sv_skel_memory_start */

gentity_t * SV_GentityNum(int num);
playerState_t * SV_GameClientNum(int num);
int SV_SvEntityForGentity(const gentity_t *gEnt);
long unsigned int SV_GameSendServerCommand(int clientNum, svscmd_type type, const char *text);
long unsigned int SV_GameDropClient(int clientNum, const char *reason);
long unsigned int SV_GetServerinfo(char *buffer, int bufferSize);
long unsigned int SV_LocateGameData(gentity_t *gEnts, int numGEntities, int sizeofGEntity_t, playerState_t *clients, int sizeofGameClient);
long unsigned int SV_GetUsercmd(int clientNum, usercmd_t *cmd);
static long unsigned int * SV_AllocXModelPrecache(int size);
static long unsigned int * SV_AllocXModelPrecacheColl(int size);
struct XModel * SV_XModelGet(const char *name);
long unsigned int SV_DObjDumpInfo(gentity_t *ent);
long unsigned int SV_ResetSkeletonCache(void);
qboolean SV_DObjUpdateServerTime(gentity_t *ent, float dtime, qboolean bNotify);
long unsigned int SV_DObjInitServerTime(gentity_t *ent, float dtime);
long unsigned int SV_DObjGetHierarchyBits(gentity_t *ent, int boneIndex, int *partBits);
long unsigned int SV_DObjCalcAnim(gentity_t *ent, int *partBits);
long unsigned int SV_DObjCalcSkel(gentity_t *ent, int *partBits);
int SV_DObjGetBoneIndex(gentity_t *ent, unsigned int boneName);
DObjAnimMat_s * SV_DObjGetMatrixArray(gentity_t *ent);
long unsigned int SV_DObjDisplayAnim(gentity_t *ent);
struct XAnimTree_s * SV_DObjGetTree(gentity_t *ent);
qboolean SV_MapExists(const char *name);
long unsigned int SV_ResetEntityParsePoint(void);
qboolean SV_DObjExists(gentity_t *ent);
long unsigned int SV_SetWeaponInfoMemory(void);
qboolean SV_GetEntityToken(char *buffer, int bufferSize);
int SV_GetGuid(int clientNum);
int SV_GetClientPing(int clientNum);
qboolean SV_IsLocalClient(int clientNum);
void SV_SetGametype(void);
static void SV_InitGameVM(int restart, int savepersist);
void SV_RestartGameProgs(qboolean savepersist);
void SV_InitGameProgs(qboolean savepersist);
qboolean SV_GameCommand(void);
long unsigned int SV_SetBrushModel(gentity_t *ent);
qboolean SV_EntityContact(const vec_t *mins, const vec_t *maxs, const gentity_t *gEnt);
gentity_t * SV_GEntityForSvEntity(gentity_s (*svEnt)[4]);
long unsigned int SV_XModelDebugBoxes(gentity_t *ent);
long unsigned int SV_ShutdownGameProgs(void);
qboolean SV_inSnapshot(const vec_t *origin, int iEntityNum);
qboolean SV_DObjCreateSkelForBone(gentity_t *ent, int boneIndex);
qboolean SV_DObjCreateSkelForBones(gentity_t *ent, int *partBits);

/* line 76 */
gentity_t * SV_GentityNum(int num)
{
    server_t *sv = (server_t *)imp_sv;
    return (gentity_t *)((char *)sv->gentities + num * sv->gentitySize);
}

/* line 86 */
playerState_t * SV_GameClientNum(int num)
{
    server_t *sv = (server_t *)imp_sv;
    return (playerState_t *)((char *)sv->gameClients + num * sv->gameClientSize);
}

/* line 96 */
int SV_SvEntityForGentity(const gentity_t *gEnt)
{
    server_t *sv = (server_t *)imp_sv;
    int number;

    if (gEnt == NULL || gEnt->s.number < 0 || gEnt->s.number > 1023) {
        Com_Error(1, "SV_SvEntityForGentity: bad gEnt");
    }
    number = gEnt->s.number;

    return (int)&sv->svEntities[number];
}

/* line 122 */
long unsigned int SV_GameSendServerCommand(int clientNum, svscmd_type type, const char *text)
{
    char *p;
    int maxClients;
    char *clients_base;
    char *client;

    {
        static int _gssc_cnt = 0;
        if (_gssc_cnt < 50)
            Com_Printf("[GSSC#%d] clientNum=%d type=%d text='%.60s'\n", _gssc_cnt++, clientNum, type, text ? text : "(null)");
    }

    if (clientNum == -1) {
        SV_SendServerCommand((void *)0, type, "%s", text);
    } else if (clientNum >= 0) {
        p = *(char **)imp_sv_maxclients;
        maxClients = *(int *)(p + 8);
        if (clientNum < maxClients) {
            serverStatic_t *svs = (serverStatic_t *)imp_svs;
            SV_SendServerCommand(&svs->clients[clientNum], type, "%s", text);
        }
    }
}

/* line 147 */
long unsigned int SV_GameDropClient(int clientNum, const char *reason)
{
    char *p;
    int maxClients;

    p = *(char **)imp_sv_maxclients;
    maxClients = *(int *)(p + 8);
    if (clientNum >= 0 && clientNum < maxClients) {
        serverStatic_t *svs = (serverStatic_t *)imp_svs;
        SV_DropClient(&svs->clients[clientNum], reason);
    }
}

/* line 316 */
long unsigned int SV_GetServerinfo(char *buffer, int bufferSize)
{
    if (bufferSize <= 0) {
        Com_Error(1, "SV_GetServerinfo: bufferSize == %i", bufferSize);
    }
    I_strncpyz(buffer, Dvar_InfoString(0x404), bufferSize);
}

/* line 424 */
long unsigned int SV_LocateGameData(gentity_t *gEnts, int numGEntities, int sizeofGEntity_t, playerState_t *clients, int sizeofGameClient)
{
    server_t *sv = (server_t *)imp_sv;
    sv->gentities = gEnts;
    sv->gentitySize = sizeofGEntity_t;
    sv->num_entities = numGEntities;
    sv->gameClients = clients;
    sv->gameClientSize = sizeofGameClient;
}

/* line 441 */
long unsigned int SV_GetUsercmd(int clientNum, usercmd_t *cmd)
{
    serverStatic_t *svs = (serverStatic_t *)imp_svs;
    int *dst = (int *)cmd;
    int *src = (int *)&svs->clients[clientNum].lastUsercmd;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
}

/* line 453 */
static long unsigned int * SV_AllocXModelPrecache(int size)
{
    return Hunk_AllocInternal(size);
}

/* line 459 */
static long unsigned int * SV_AllocXModelPrecacheColl(int size)
{
    return Hunk_AllocInternal(size);
}

/* line 471 */
struct XModel * SV_XModelGet(const char *name)
{
    if (!Com_ValidXModelName(name)) {
        Com_Error(1, "bad model name '%s'", name);
    }
    return XModelPrecache(name + 7, SV_AllocXModelPrecache, SV_AllocXModelPrecacheColl);
}

/* line 486 */
long unsigned int SV_DObjDumpInfo(gentity_t *ent)
{
    void *obj;
    char *p = *(char **)imp_com_developer;
    if (*(int *)(p + 8) != 0) {
        obj = Com_GetServerDObj(ent->s.number);
        if (obj) {
            DObjDumpInfo(obj);
        } else {
            Com_Printf("no model.\n");
        }
    }
}

/* line 512 */
long unsigned int SV_ResetSkeletonCache(void)
{
    server_t *sv = (server_t *)imp_sv;
    int idx = sv->skelTimeStamp + 1;
    if (idx == 0) idx = 1;
    sv->skelTimeStamp = idx;
    g_sv_skel_memory_start = (char *)((((unsigned int)g_sv_skel_memory) + 0xf) & ~0xfu);
    sv->skelMemPos = 0;
}

/* line 622 */
qboolean SV_DObjUpdateServerTime(gentity_t *ent, float dtime, qboolean bNotify)
{
    void *obj = Com_GetServerDObj(ent->s.number);
    if (obj) {
        return DObjUpdateServerInfo(obj, dtime, bNotify);
    }
    return 0;
}

/* line 640 */
long unsigned int SV_DObjInitServerTime(gentity_t *ent, float dtime)
{
    void *obj = Com_GetServerDObj(ent->s.number);
    if (obj) {
        DObjInitServerTime(obj, dtime);
    }
}

/* line 658 */
long unsigned int SV_DObjGetHierarchyBits(gentity_t *ent, int boneIndex, int *partBits)
{
    void *obj = Com_GetServerDObj(ent->s.number);
    DObjGetHierarchyBits(obj, boneIndex, partBits);
}

/* line 675 */
long unsigned int SV_DObjCalcAnim(gentity_t *ent, int *partBits)
{
    void *obj = Com_GetServerDObj(ent->s.number);
    DObjCalcAnim(obj, partBits);
}

/* line 693 */
long unsigned int SV_DObjCalcSkel(gentity_t *ent, int *partBits)
{
    void *obj = Com_GetServerDObj(ent->s.number);
    DObjCalcSkel(obj, partBits);
}

/* line 728 */
int SV_DObjGetBoneIndex(gentity_t *ent, unsigned int boneName)
{
    void *obj = Com_GetServerDObj(ent->s.number);
    if (!obj) return -1;
    return DObjGetBoneIndex(obj, boneName);
}

/* line 746 */
DObjAnimMat_s * SV_DObjGetMatrixArray(gentity_t *ent)
{
    void *obj = Com_GetServerDObj(ent->s.number);
    return DObjGetRotTransArray(obj);
}

/* line 763 */
long unsigned int SV_DObjDisplayAnim(gentity_t *ent)
{
    void *obj = Com_GetServerDObj(ent->s.number);
    if (obj) {
        DObjDisplayAnim(obj);
    }
}

/* line 831 */
struct XAnimTree_s * SV_DObjGetTree(gentity_t *ent)
{
    void *obj = Com_GetServerDObj(ent->s.number);
    if (!obj) return 0;
    return DObjGetTree(obj);
}

/* line 923 */
qboolean SV_MapExists(const char *name)
{
    const char *basename = SV_GetMapBaseName(name);
    const char *ext = GetBspExtension();
    const char *path = va("maps/mp/%s.%s", basename, ext);
    return FS_ReadFile(path, (void *)0) >= 0;
}

/* line 946 */
long unsigned int SV_ResetEntityParsePoint(void)
{
    server_t *sv = (server_t *)imp_sv;
    sv->entityParsePoint = CM_EntityString();
}

/* line 957 */
qboolean SV_DObjExists(gentity_t *ent)
{
    return Com_GetServerDObj(ent->s.number) != 0;
}

/* line 969 */
long unsigned int SV_SetWeaponInfoMemory(void)
{
    Com_SetWeaponInfoMemory(1);
}

/* line 993 */
qboolean SV_GetEntityToken(char *buffer, int bufferSize)
{
    server_t *sv = (server_t *)imp_sv;
    const char *s = Com_Parse((char **)&sv->entityParsePoint);
    I_strncpyz(buffer, s, bufferSize);
    if (sv->entityParsePoint || *s) {
        return 1;
    }
    return 0;
}

/* line 1037 */
int SV_GetGuid(int clientNum)
{
    char *p = *(char **)imp_sv_maxclients;
    if (clientNum < 0 || clientNum >= *(int *)(p + 8)) {
        return 0;
    }
    {
        serverStatic_t *svs = (serverStatic_t *)imp_svs;
        return svs->clients[clientNum].guid;
    }
}

/* line 1052 */
int SV_GetClientPing(int clientNum)
{
    serverStatic_t *svs = (serverStatic_t *)imp_svs;
    return svs->clients[clientNum].ping;
}

/* line 1064 */
qboolean SV_IsLocalClient(int clientNum)
{
    serverStatic_t *svs = (serverStatic_t *)imp_svs;
    client_t *client = &svs->clients[clientNum];
    netadr_t *addr = &client->netchan.remoteAddress;
    return NET_IsLocalAddress(((int *)addr)[0], ((int *)addr)[1], ((int *)addr)[2]);
}

/* line 1106 */
void SV_SetGametype(void)
{
    char gametype[64];
    char *s;

    *(dvar_t **)imp_sv_gametype = Dvar_RegisterString("g_gametype", "dm", 0x1024);

    /* If server is running and has save persist, use current gametype from sv */
    if (*(char *)(*(char **)imp_com_sv_running + 8) && G_GetSavePersist()) {
        server_t *sv = (server_t *)imp_sv;
        I_strncpyz(gametype, sv->gametype, 64);
    } else {
        I_strncpyz(gametype, *(char **)((char *)*(void **)imp_sv_gametype + 8), 64);
    }

    /* Lowercase the gametype string */
    for (s = gametype; *s; s++) {
        *s = ___tolower(*s);
    }

    if (!Scr_IsValidGameType(gametype)) {
        Com_Printf("g_gametype %s is not a valid gametype, defaulting to dm\n", gametype);
        gametype[0] = 'd';
        gametype[1] = 'm';
        gametype[2] = '\0';
    }

    Dvar_SetString(*(dvar_t **)imp_sv_gametype, gametype);
}

/* line 1152 */
static void SV_InitGameVM(int restart, int savepersist)
{
    server_t *sv;
    serverStatic_t *svs;
    int i;
    int maxclients;

    FX_InitServer();

    sv = (server_t *)imp_sv;
    sv->entityParsePoint = CM_EntityString();

    Sys_LoadingKeepAlive();

    svs = (serverStatic_t *)imp_svs;
    G_InitGame(svs->time, Sys_MillisecondsRaw(), restart, savepersist);

    /* DBG: count free script variables after G_InitGame */
    {
        extern unsigned char scrVarGlob[];
        int freeCount = 0;
        unsigned short idx = *(unsigned short *)(scrVarGlob + 4);
        while (idx != 0 && freeCount < 70000) {
            freeCount++;
            idx = *(unsigned short *)(scrVarGlob + (unsigned int)idx * 16 + 4);
        }
        Com_Printf("DBG after G_InitGame: %d free script variables\n", freeCount);
    }

    Sys_LoadingKeepAlive();

    /* Clear client gentityNum for all clients */
    maxclients = *(int *)(*(char **)imp_sv_maxclients + 8);
    svs = (serverStatic_t *)imp_svs;
    for (i = 0; i < maxclients; i++) {
        /* offset 0x20c44 in client_t - gentity pointer / oldServerTime */
        *(int *)((char *)&svs->clients[i] + 0x20c44) = 0;
    }

    /* Dump dvars if dedicated */
    if (*(int *)(*(char **)imp_com_dedicated + 8)) {
        Com_DvarDump(4);
    }
}

/* line 1187 */
void SV_RestartGameProgs(qboolean savepersist)
{
    G_ShutdownGame(0);
    *(int *)*(char **)imp_com_fixedConsolePosition = 0;
    SV_InitGameVM(1, savepersist);
}

/* line 1208 */
void SV_InitGameProgs(qboolean savepersist)
{
    gameInitialized = 1;
    SV_InitGameVM(0, savepersist);
}

/* line 1223 */
qboolean SV_GameCommand(void)
{
    server_t *sv = (server_t *)imp_sv;
    if (sv->state != 2) return 0;
    return ConsoleCommand();
}

/* line 165 */
long unsigned int SV_SetBrushModel(gentity_t *ent)
{
    vec3_t mins, maxs;
    CM_ModelBounds(ent->s.index.brushmodel, mins, maxs);
    ent->r.mins[0] = mins[0];
    ent->r.mins[1] = mins[1];
    ent->r.mins[2] = mins[2];
    ent->r.maxs[0] = maxs[0];
    ent->r.maxs[1] = maxs[1];
    ent->r.maxs[2] = maxs[2];
    ent->r.bmodel = 1;
    ent->r.contents = -1;
    SV_LinkEntity(ent);
}

/* line 268 */
qboolean SV_EntityContact(const vec_t *mins, const vec_t *maxs, const gentity_t *gEnt)
{
    unsigned char svFlags = gEnt->r.svFlags;
    float center[2];
    float radius;
    float distSq;

    if (!(svFlags & 0x60)) {
        /* Standard trace-based contact check */
        char trace[0x24];
        int clipHandle = SV_ClipHandleForEntity(gEnt);
        vec_t *vec3_origin = (vec_t *)*(char **)imp_vec3_origin;
        CM_TransformedBoxTraceExternal(trace, vec3_origin, vec3_origin,
            mins, maxs, clipHandle, -1,
            gEnt->r.currentOrigin, gEnt->r.currentAngles);
        return *(unsigned char *)(trace + 0x23);
    }

    if (svFlags & 0x20) {
        /* Capsule: check Z bounds first */
        float entZ = gEnt->r.currentOrigin[2];
        if (entZ < maxs[2]) {
            float topZ = entZ + gEnt->r.maxs[2];
            if (mins[2] >= topZ) {
                return 0;
            }
            /* Z overlap, check 2D radius */
            center[0] = (mins[0] + maxs[0]) * 0.5f;
            center[1] = (mins[1] + maxs[1]) * 0.5f;
            radius = maxs[0] - center[0] + gEnt->r.maxs[0];
            distSq = Vec2DistanceSq((float *)gEnt->r.currentOrigin, center);
            return distSq > radius * radius;
        }
        return 0;
    }

    /* Cylinder without Z check */
    center[0] = (mins[0] + maxs[0]) * 0.5f;
    center[1] = (mins[1] + maxs[1]) * 0.5f;
    radius = maxs[0] - center[0] + gEnt->r.maxs[0] - 64.0f;
    distSq = Vec2DistanceSq((float *)gEnt->r.currentOrigin, center);
    return distSq <= radius * radius;
}

/* line 106 */
gentity_t * SV_GEntityForSvEntity(gentity_s (*svEnt)[4])
{
    server_t *sv = (server_t *)imp_sv;
    int index = ((int)svEnt - (int)sv->svEntities) / sizeof(svEntity_t);
    return (gentity_t *)((char *)sv->gentities + index * sv->gentitySize);
}

/* line 845 */
long unsigned int SV_XModelDebugBoxes(gentity_t *ent)
{
    void *obj;
    DObjAnimMat_s *boneMatrix;
    DObjAnimMat_s *mat;
    float *boneInfoArray[128];
    int numModels, modelIndex, numBones, localBoneIndex;
    float *boneInfo;
    float boneMat[4][3];
    float axis[3][3];
    float color[4];
    float start[3], end[3], vec[3], org[3];
    float sx, sy, sz;
    float xx, xy, xz, xw;
    float yy, yz, yw;
    float zz, zw;
    int edge;

    obj = Com_GetServerDObj(ent->s.number);
    DObjNumBones(obj);
    DObjGetBoneInfo(obj, boneInfoArray);
    boneMatrix = DObjGetRotTransArray(obj);

    color[0] = 1.0f;
    color[1] = 1.0f;
    color[2] = 1.0f;
    color[3] = 0.0f;

    AnglesToAxis(ent->r.currentAngles, axis);

    numModels = DObjGetNumModels(obj);

    for (modelIndex = 0; modelIndex < numModels; modelIndex++) {
        if (DObjIgnoreCollision(obj, modelIndex))
            continue;

        numBones = XModelNumBones(DObjGetModel(obj, modelIndex));
        if (numBones <= 0)
            continue;

        mat = boneMatrix;
        for (localBoneIndex = 0; localBoneIndex < numBones; localBoneIndex++, mat++) {
            boneInfo = boneInfoArray[localBoneIndex];

            /* Quaternion to rotation matrix */
            sx = mat->transWeight * mat->quat[0];
            sy = mat->transWeight * mat->quat[1];
            sz = mat->transWeight * mat->quat[2];

            xx = sx * mat->quat[0];
            xy = sx * mat->quat[1];
            xz = sx * mat->quat[2];
            xw = sx * mat->quat[3];
            yy = sy * mat->quat[1];
            yz = sy * mat->quat[2];
            yw = sy * mat->quat[3];
            zz = sz * mat->quat[2];
            zw = sz * mat->quat[3];

            boneMat[0][0] = 1.0f - (yy + zz);
            boneMat[0][1] = xy + zw;
            boneMat[0][2] = xz - yw;
            boneMat[1][0] = xy - zw;
            boneMat[1][1] = 1.0f - (xx + zz);
            boneMat[1][2] = yz + xw;
            boneMat[2][0] = xz + yw;
            boneMat[2][1] = yz - xw;
            boneMat[2][2] = 1.0f - (xx + yy);
            boneMat[3][0] = mat->trans[0];
            boneMat[3][1] = mat->trans[1];
            boneMat[3][2] = mat->trans[2];

            for (edge = 0; edge < 24; edge += 2) {
                /* Start vertex */
                org[0] = boneInfo[boxVerts[edge][0] * 3 + 0];
                org[1] = boneInfo[boxVerts[edge][1] * 3 + 1];
                org[2] = boneInfo[boxVerts[edge][2] * 3 + 2];
                MatrixTransformVector43(org, (float *)boneMat, vec);
                MatrixTransformVector(vec, axis, start);
                start[0] += ent->r.currentOrigin[0];
                start[1] += ent->r.currentOrigin[1];
                start[2] += ent->r.currentOrigin[2];

                /* End vertex */
                org[0] = boneInfo[boxVerts[edge + 1][0] * 3 + 0];
                org[1] = boneInfo[boxVerts[edge + 1][1] * 3 + 1];
                org[2] = boneInfo[boxVerts[edge + 1][2] * 3 + 2];
                MatrixTransformVector43(org, (float *)boneMat, vec);
                MatrixTransformVector(vec, axis, end);
                end[0] += ent->r.currentOrigin[0];
                end[1] += ent->r.currentOrigin[1];
                end[2] += ent->r.currentOrigin[2];

                CL_AddDebugLine(start, end, color, 0, 0, 1);
            }
        }
        boneMatrix = mat;
    }
}

/* line 1077 */
long unsigned int SV_ShutdownGameProgs(void)
{
    ((server_t *)imp_sv)->state = 0;
    Com_UnloadSoundAliases(2);
    if (gameInitialized) {
        G_ShutdownGame(1);
        Com_FreeWeaponInfoMemory(1);
        gameInitialized = 0;
    }
}

/* line 189 */
qboolean SV_inSnapshot(const vec_t *origin, int iEntityNum)
{
    server_t *sv;
    gentity_t *ent;
    svEntity_t *svEnt;
    int numClusters;
    int cluster;
    byte *clientpvs;
    int broadcastTime;
    unsigned char svFlags;
    int i;
    int lastCluster;
    float fogDistSqrd;

    /* Get entity pointer */
    sv = (server_t *)imp_sv;
    ent = (gentity_t *)((char *)sv->gentities + iEntityNum * sv->gentitySize);

    /* Check if entity is linked */
    if (ent->r.linked == 0)
        return 0;

    /* Check broadcastTime */
    broadcastTime = ent->r.broadcastTime;
    if (broadcastTime)
        return 1;

    svFlags = ent->r.svFlags;

    /* SVF_NOCLIENT */
    if (svFlags & 1)
        return 0;

    /* SVF_BROADCAST */
    if (svFlags & 0x18)
        return 1;

    /* Get svEntity for PVS check */
    {
        int number = ent->s.number;
        if (ent == 0 || number < 0 || number > 1023) {
            Com_Error(1, "SV_SvEntityForGentity: bad gEnt");
            sv = (server_t *)imp_sv;
            number = ent->s.number;
        }
        svEnt = &sv->svEntities[number];
    }

    /* Get leaf for origin */
    cluster = CM_PointLeafnum(origin);

    numClusters = svEnt->numClusters;
    if (numClusters == 0)
        return 0;

    cluster = CM_LeafCluster(cluster);
    clientpvs = CM_ClusterPVS(cluster);

    if (numClusters > 0) {
        /* Check clusternums array */
        int firstCluster = svEnt->clusternums[0];
        if ((clientpvs[firstCluster >> 3] >> (firstCluster & 7)) & 1)
            goto check_fog;

        for (i = 1; i < numClusters; i++) {
            int cl = svEnt->clusternums[i];
            if ((clientpvs[cl >> 3] >> (cl & 7)) & 1)
                goto check_fog;
        }

        /* Check lastCluster */
        lastCluster = svEnt->lastCluster;
        if (lastCluster == 0)
            return 0;

        for (i = 0; i < lastCluster; i++) {
            if ((clientpvs[i >> 3] >> (i & 7)) & 1)
                break;
        }
        if (i == lastCluster)
            return 0;
    } else if (numClusters < 0) {
        /* Too many clusters, check lastCluster range */
        goto check_fog;
    } else {
        /* numClusters == 0, check lastCluster */
        lastCluster = svEnt->lastCluster;
        if (lastCluster == 0)
            return 0;

        for (i = 0; i < lastCluster; i++) {
            if ((clientpvs[i >> 3] >> (i & 7)) & 1)
                break;
        }
        if (i == lastCluster)
            return 0;
    }

check_fog:
    fogDistSqrd = G_GetFogOpaqueDistSqrd();
    if (fogDistSqrd == 3.4028234663852886e+38f)
        return 1;

    return !BoxDistSqrdExceeds(ent->r.absmin, ent->r.absmax, origin, fogDistSqrd);
}

/* line 569 */
qboolean SV_DObjCreateSkelForBone(gentity_t *ent, int boneIndex)
{
    void *obj;
    server_t *sv;
    int allocSize;
    int alignedSize;
    char *buf;
    int timestamp;

    obj = Com_GetServerDObj(ent->s.number);
    sv = (server_t *)imp_sv;

    if (DObjSkelExists(obj, sv->skelTimeStamp)) {
        return DObjSkelIsBoneUpToDate(obj, boneIndex);
    }

    allocSize = DObjGetAllocSkelSize(obj);
    alignedSize = (allocSize + 15) & ~15;
    buf = g_sv_skel_memory_start + sv->skelMemPos;
    sv->skelMemPos += alignedSize;

    if (sv->skelMemPos > 0x3fff0) {
        buf = (char *)(((unsigned int)g_sv_skel_memory + 15) & ~15u);

        do {
            timestamp = sv->skelTimeStamp;
            if (timestamp != warnCount) {
                warnCount = timestamp;
                Com_Printf("^3WARNING: SV_SKEL_MEMORY_SIZE exceeded\n");
            }
            timestamp = sv->skelTimeStamp + 1;
            if (timestamp == 0)
                timestamp = 1;
            sv->skelTimeStamp = timestamp;
            g_sv_skel_memory_start = buf;
            sv->skelMemPos = alignedSize;
        } while (alignedSize > 0x3fff0);
    }

    sv = (server_t *)imp_sv;
    DObjCreateSkel(obj, buf, sv->skelTimeStamp);
    return 0;
}

/* line 596 */
qboolean SV_DObjCreateSkelForBones(gentity_t *ent, int *partBits)
{
    void *obj;
    server_t *sv;
    int allocSize;
    int alignedSize;
    char *buf;
    int timestamp;

    obj = Com_GetServerDObj(ent->s.number);
    sv = (server_t *)imp_sv;

    if (DObjSkelExists(obj, sv->skelTimeStamp)) {
        return DObjSkelAreBonesUpToDate(obj, partBits);
    }

    allocSize = DObjGetAllocSkelSize(obj);
    alignedSize = (allocSize + 15) & ~15;
    buf = g_sv_skel_memory_start + sv->skelMemPos;
    sv->skelMemPos += alignedSize;

    if (sv->skelMemPos > 0x3fff0) {
        buf = (char *)(((unsigned int)g_sv_skel_memory + 15) & ~15u);

        do {
            timestamp = sv->skelTimeStamp;
            if (timestamp != warnCount) {
                warnCount = timestamp;
                Com_Printf("^3WARNING: SV_SKEL_MEMORY_SIZE exceeded\n");
            }
            timestamp = sv->skelTimeStamp + 1;
            if (timestamp == 0)
                timestamp = 1;
            sv->skelTimeStamp = timestamp;
            g_sv_skel_memory_start = buf;
            sv->skelMemPos = alignedSize;
        } while (alignedSize > 0x3fff0);
    }

    sv = (server_t *)imp_sv;
    DObjCreateSkel(obj, buf, sv->skelTimeStamp);
    return 0;
}

