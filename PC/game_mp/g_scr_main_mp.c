/* ASM dump from: g_scr_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_scr_main_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

#define SCR_CONST() ((const scr_const_t *)imp_scr_const)

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

extern struct scr_data_t g_scr_data; /* 0x0 */
extern unsigned int Scr_AllocString(const char *s, int user);
extern void Scr_AddString(const char *s);
extern void Scr_AddInt(int value);
extern int Scr_GetInt(int argIndex);
extern void Scr_AddEntity(void *ent);
extern void Scr_AddUndefined(void);
extern int SV_AddTestClient(void);
extern int SV_MapExists(const char *name);
extern float Vec3Normalize(vec3_t v);
extern void SV_EnableArchivedSnapshot(int enable);
extern void Scr_Error(const char *msg);
extern const char *va(const char *fmt, ...);
extern const char *Scr_GetString(unsigned int index);
extern int Scr_GetType(unsigned int index);
extern int Scr_GetPointerType(unsigned int index);
extern gentity_t *Scr_GetEntity(unsigned int index);
extern const char *Dvar_GetVariantString(const char *dvarName);
extern void Scr_AddFloat(float value);
extern void Scr_AddBool(int value);
extern unsigned int Scr_GetAnim(unsigned int index, int treeIndex);
extern void *Scr_GetAnims(unsigned int treeIndex);
extern int XAnimIsPrimitive(void *anims, unsigned int animIndex);
extern float XAnimGetLength(void *anims, unsigned int animIndex);
extern void Scr_ParamError(unsigned int index, const char *msg);
extern unsigned int Scr_GetConstString(unsigned int index);
extern int XAnimNotetrackExists(void *anims, unsigned int animIndex, unsigned int notetrack);
extern int Com_FindSoundAlias(const char *name);
extern int G_GetWeaponIndexForName(const char *name);
extern void *BG_GetWeaponDef(int weaponIndex);
extern int I_stricmp(const char *s1, const char *s2);
extern void Com_Printf(const char *fmt, ...);
extern float Scr_GetFloat(unsigned int index);
extern float flrand(float min, float max);
extern int irand(int min, int max);
extern double sin(double x);
extern double cos(double x);
extern unsigned int Scr_ExecThread(unsigned int handle, int paramCount);
extern void Scr_FreeThread(unsigned int threadId);
extern unsigned int Scr_ExecEntThread(gentity_t *ent, unsigned int handle, int paramCount);
extern void SV_GameSendServerCommand(int clientnum, int type, const char *text);
extern void Scr_Notify(gentity_t *ent, unsigned int stringValue, int paramCount);
extern void *SV_XModelGet(const char *name);
extern int XModelNumBones(void *model);
extern int G_ModelIndex(const char *name);
extern void Scr_RemoveClassMap(int classnum);
extern float atanf(float x);
extern float acosf(float x);
extern int Scr_GetTypeName(int index);
extern void Scr_GetVector(unsigned int index, float *out);
extern float Vec3Distance(float *a, float *b);
extern float Vec3DistanceSq(float *a, float *b);
extern void vectoangles(float *vec, float *angles);
extern void Scr_AddVector(float *vec);
extern void AngleVectors(float *angles, float *forward, float *right, float *up);
extern int G_ShellShockIndex(const char *name);
extern int G_ShaderIndex(const char *name);
extern int G_LocalizedStringIndex(const char *name);
extern const char *Scr_GetIString(unsigned int index);
extern int Scr_GetNumParam(void);
extern void SV_GetConfigstring(int index, char *buffer, int bufferSize);
extern int G_EffectIndex(const char *name);
extern const char *SL_ConvertToString(unsigned int stringValue);
extern BuiltinFunctionDef functions[145]; /* 0x0 */
extern BuiltinMethodDef methods[]; /* methods - defined in data.S */
extern const dvar_t *g_NoScriptSpam;
extern level_locals_t level;
extern gentity_t g_entities[1024];

unsigned int GScr_AllocString(const char *s);
unsigned int Scr_LoadLevel(void);
unsigned int GScr_FreeScripts(void);
unsigned int ScrCmd_GetClanId(struct scr_entref_t entref);
unsigned int ScrCmd_GetClanName(scr_entref_t entref);
unsigned int ScrCmd_GetClanMotto(scr_entref_t entref);
unsigned int ScrCmd_GetClanDescription(scr_entref_t entref);
unsigned int ScrCmd_GetClanURL(scr_entref_t entref);
unsigned int print(void);
unsigned int assertCmd(void);
unsigned int assertexCmd(void);
unsigned int assertmsgCmd(void);
unsigned int GScr_IsDefined(void);
unsigned int GScr_IsString(void);
unsigned int GScr_IsAlive(void);
unsigned int GScr_GetDvar(void);
unsigned int GScr_GetDvarInt(void);
unsigned int GScr_GetDvarFloat(void);
unsigned int GScr_GetTime(void);
unsigned int Scr_GetEntByNum(void);
unsigned int Scr_GetWeaponModel(void);
unsigned int GScr_GetAnimLength(void);
unsigned int GScr_AnimHasNotetrack(void);
unsigned int GScr_PrecacheTurret(void);
unsigned int ScrCmd_SoundExists(void);
unsigned int ScrCmd_PlayRumble(scr_entref_t entref);
unsigned int ScrCmd_PlayLoopRumble(scr_entref_t entref);
unsigned int ScrCmd_StopRumble(scr_entref_t entref);
qboolean G_GetHintStringIndex(int *piIndex, const char *pszString);
unsigned int SetObjectiveIcon(void);
unsigned int Scr_Objective_Icon(void);
unsigned int Scr_Objective_OnEntity(void);
unsigned int Scr_Objective_Current(void);
unsigned int GScr_Objective_Team(void);
unsigned int GScr_LogPrint(void);
unsigned int GScr_WorldEntNumber(void);
unsigned int GScr_Obituary(void);
unsigned int GScr_getStartTime(void);
unsigned int GScr_PrecacheMenu(void);
int GScr_GetScriptMenuIndex(const char *pszMenu);
unsigned int GScr_PrecacheStatusIcon(void);
int GScr_GetStatusIconIndex(const char *pszIcon);
unsigned int GScr_PrecacheHeadIcon(void);
int GScr_GetHeadIconIndex(const char *pszIcon);
unsigned int Scr_BulletTracePassed(void);
unsigned int Scr_SightTracePassed(void);
unsigned int Scr_PhysicsTrace(void);
unsigned int Scr_RandomInt(void);
unsigned int Scr_RandomFloat(void);
unsigned int Scr_RandomIntRange(void);
unsigned int Scr_RandomFloatRange(void);
unsigned int GScr_sin(void);
unsigned int GScr_cos(void);
unsigned int GScr_tan(void);
unsigned int GScr_asin(void);
unsigned int GScr_acos(void);
unsigned int GScr_atan(void);
unsigned int GScr_CastInt(void);
unsigned int Scr_Distance(void);
unsigned int Scr_DistanceSquared(void);
unsigned int Scr_LengthSquared(void);
unsigned int Scr_Closer(void);
unsigned int Scr_VectorDot(void);
unsigned int Scr_VectorToAngles(void);
unsigned int Scr_AnglesToUp(void);
unsigned int Scr_AnglesToRight(void);
unsigned int Scr_AnglesToForward(void);
unsigned int Scr_IsSubStr(void);
unsigned int Scr_GetSubStr(void);
unsigned int Scr_ToLower(void);
unsigned int Scr_StrTok(void);
unsigned int Scr_MusicPlay(void);
unsigned int Scr_SoundFade(void);
unsigned int Scr_PrecacheModel(void);
unsigned int Scr_PrecacheShellShock(void);
unsigned int Scr_PrecacheItem(void);
unsigned int Scr_PrecacheShader(void);
unsigned int Scr_PrecacheString(void);
unsigned int Scr_PrecacheRumble(void);
unsigned int GScr_RadiusDamage(void);
unsigned int GScr_SetPlayerIgnoreRadiusDamage(void);
unsigned int GScr_GetMoveDelta(void);
unsigned int GScr_GetAngleDelta(void);
unsigned int GScr_GetNorthYaw(void);
unsigned int Scr_LoadFX(void);
unsigned int Scr_PlayFXOnTag(void);
unsigned int Scr_SetFog(float fNear, float fFar, float fDensity, float fRed, float fGreen, float fBlue, float fTime);
unsigned int Scr_SetLinearFog(void);
unsigned int Scr_SetExponentialFog(void);
unsigned int GScr_IsPlayer(void);
unsigned int GScr_IsPlayerNumber(void);
unsigned int GScr_SetWinningPlayer(void);
unsigned int GScr_SetWinningTeam(void);
unsigned int GScr_GetTeamScore(void);
unsigned int GScr_SetTeamScore(void);
unsigned int GScr_SetClientNameMode(void);
unsigned int GScr_UpdateClientNames(void);
unsigned int GScr_GetTeamPlayersAlive(void);
unsigned int GScr_GetNumParts(void);
unsigned int GScr_GetPartName(void);
unsigned int GScr_Earthquake(void);
unsigned int GScr_MapRestart(void);
unsigned int GScr_LoadMap(void);
unsigned int GScr_ExitLevel(void);
unsigned int GScr_AddTestClient(void);
unsigned int GScr_AllClientsPrint(void);
unsigned int GScr_MapExists(void);
unsigned int GScr_SetVoteString(void);
unsigned int GScr_SetVoteTime(void);
unsigned int GScr_SetVoteYesCount(void);
unsigned int GScr_SetVoteNoCount(void);
unsigned int GScr_KickPlayer(void);
unsigned int GScr_BanPlayer(void);
unsigned int GScr_ClientPrint(void);
unsigned int GScr_OpenFile(void);
unsigned int GScr_CloseFile(void);
unsigned int GScr_FPrintln(void);
unsigned int GScr_FReadLn(void);
unsigned int GScr_FGetArg(void);
unsigned int GScr_SetArchive(void);
unsigned int Scr_PlayRumbleOnPos(void);
unsigned int Scr_PlayLoopRumbleOnPos(void);
unsigned int Scr_StopAllRumbles(void);
unsigned int Scr_IsSplitscreen(void);
unsigned int GScr_MatchEnd(void);
unsigned int GScr_SetPlayerTeamRank(void);
unsigned int GScr_SendXboxLiveRanks(void);
void GScr_EndXboxLiveLobby(void);
unsigned int GScr_ReleaseClaimedTrigger(scr_entref_t entref);
BuiltinFunction Scr_GetFunction(const char * *pName, int *type);
BuiltinMethod Scr_GetMethod(const char * *pName, int *type);
unsigned int Scr_SetOrigin(gentity_t *ent, int offset);
unsigned int Scr_SetAngles(gentity_t *ent, int offset);
unsigned int Scr_SetHealth(gentity_t *ent, int offset);
unsigned int GScr_AddEntity(gentity_t *pEnt);
unsigned int Scr_ParseGameTypeList(void);
const char * Scr_GetGameTypeNameForScript(const char *pszGameTypeScript);
unsigned int Scr_LoadGameType(void);
unsigned int Scr_StartupGameType(void);
unsigned int Scr_PlayerConnect(gentity_t *self);
unsigned int Scr_PlayerDisconnect(gentity_t *self);
unsigned int Scr_VoteCalled(gentity_t *self, char *command, char *param1, char *param2);
unsigned int Scr_PlayerVote(gentity_t *self, char *option);
unsigned int GScr_print3d(void);
unsigned int GScr_line(void);
unsigned int GScr_Spawn(void);
unsigned int GScr_SpawnTurret(void);
unsigned int Scr_VectorNormalize(void);
unsigned int Scr_GrenadeExplosionEffect(void);
unsigned int Scr_Objective_Position(void);
unsigned int GScr_positionWouldTelefrag(void);
unsigned int GScr_GetBrushModelCenter(void);
unsigned int Scr_Objective_Delete(void);
unsigned int G_InitObjectives(void);
unsigned int Scr_BulletTrace(void);
unsigned int Scr_Objective_Add(void);
unsigned int Scr_Objective_State(void);
unsigned int Scr_MusicStop(void);
unsigned int Scr_AmbientPlay(void);
unsigned int Scr_AmbientStop(void);
unsigned int Scr_PlayLoopedFX(void);
unsigned int Scr_ConstructMessageString(int firstParmIndex, int lastParmIndex, const char *errorContext, char *string, int stringLimit);
unsigned int GScr_MakeDvarServerInfo(void);
unsigned int GScr_ClientAnnouncement(void);
unsigned int GScr_Announcement(void);
unsigned int GScr_SetDvar(void);
unsigned int Scr_MakeGameMessage(int iClientNum, const char *pszCmd);
unsigned int GScr_IsValidGameType(void);
qboolean Scr_IsValidGameType(const char *pszGameType);
unsigned int Scr_Length(void);
unsigned int println(void);
unsigned int Scr_PlayerDamage(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int dflags, int meansOfDeath, int iWeapon, const vec_t *vPoint, const vec_t *vDir, const hitLocation_t hitLoc, int timeOffset);
unsigned int Scr_PlayerKilled(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int meansOfDeath, int iWeapon, const vec_t *vDir, const hitLocation_t hitLoc, int psTimeOffset, int deathAnimDuration);
unsigned int ScrCmd_Show(scr_entref_t entref);
unsigned int ScrCmd_Hide(scr_entref_t entref);
unsigned int ScrCmd_ShowToPlayer(scr_entref_t entref);
unsigned int GScr_EnableGrenadeTouchDamage(scr_entref_t entref);
unsigned int GScr_DisableGrenadeTouchDamage(scr_entref_t entref);
unsigned int GScr_EnableGrenadeBounce(scr_entref_t entref);
unsigned int GScr_DisableGrenadeBounce(scr_entref_t entref);
unsigned int GScr_EnableAimAssist(scr_entref_t entref);
unsigned int GScr_DisableAimAssist(scr_entref_t entref);
unsigned int ScrCmd_attach(scr_entref_t entref);
unsigned int ScrCmd_detach(scr_entref_t entref);
unsigned int ScrCmd_detachAll(scr_entref_t entref);
unsigned int ScrCmd_GetAttachSize(scr_entref_t entref);
unsigned int ScrCmd_GetAttachModelName(scr_entref_t entref);
unsigned int ScrCmd_GetAttachTagName(scr_entref_t entref);
unsigned int ScrCmd_GetAttachIgnoreCollision(scr_entref_t entref);
unsigned int ScrCmd_LinkTo(scr_entref_t entref);
unsigned int ScrCmd_Unlink(scr_entref_t entref);
unsigned int ScrCmd_EnableLinkTo(scr_entref_t entref);
unsigned int ScrCmd_GetOrigin(scr_entref_t entref);
unsigned int ScrCmd_GetEye(scr_entref_t entref);
unsigned int ScrCmd_UseBy(scr_entref_t entref);
unsigned int Scr_SetStableMissile(scr_entref_t entref);
unsigned int ScrCmd_IsTouching(scr_entref_t entref);
unsigned int ScrCmd_PlaySound(scr_entref_t entref);
unsigned int ScrCmd_PlaySoundAsMaster(scr_entref_t entref);
unsigned int ScrCmd_PlayLoopSound(scr_entref_t entref);
unsigned int ScrCmd_StopLoopSound(scr_entref_t entref);
unsigned int ScrCmd_Delete(scr_entref_t entref);
unsigned int ScrCmd_SetModel(scr_entref_t entref);
unsigned int ScrCmd_GetNormalHealth(scr_entref_t entref);
unsigned int ScrCmd_SetNormalHealth(scr_entref_t entref);
unsigned int ScrCmd_SetContents(scr_entref_t entref);
unsigned int GScr_SetCursorHint(scr_entref_t entref);
unsigned int GScr_SetHintString(scr_entref_t entref);
static gentity_t * GetPlayerEntity(void);
unsigned int GScr_ViewKick(scr_entref_t entref);
unsigned int GScr_StopShellShock(scr_entref_t entref);
unsigned int GScr_ShellShock(scr_entref_t entref);
unsigned int GScr_GetAmmoCount(scr_entref_t entref);
unsigned int GScr_LocalToWorldCoords(scr_entref_t entref);
unsigned int GScr_SetRightArc(scr_entref_t entref);
unsigned int GScr_SetLeftArc(scr_entref_t entref);
unsigned int GScr_SetTopArc(scr_entref_t entref);
unsigned int GScr_SetBottomArc(scr_entref_t entref);
unsigned int GScr_GetEntityNumber(scr_entref_t entref);
unsigned int GScr_PlaceSpawnPoint(scr_entref_t entref);
unsigned int GScr_UpdateScores(scr_entref_t entref);
unsigned int GScr_SetTeamForTrigger(scr_entref_t entref);
unsigned int GScr_ClientClaimTrigger(scr_entref_t entref);
unsigned int GScr_ClientReleaseTrigger(scr_entref_t entref);
unsigned int Scr_PlayFX(void);
unsigned int iprintln(void);
unsigned int iprintlnbold(void);
unsigned int GScr_LoadGameTypeScript(void);
unsigned int GScr_LoadScripts(void);

/* line 35 */
unsigned int GScr_AllocString(const char *s)
{
    return Scr_AllocString(s, 1);
}

/* line 57 */
unsigned int Scr_LoadLevel(void)
{
    unsigned int handle = g_scr_data.levelscript;
    if (handle)
    {
        unsigned int threadId = Scr_ExecThread(handle, 0);
        Scr_FreeThread(threadId & 0xFFFF);
    }
    return 0;
}

/* line 152 */
unsigned int GScr_FreeScripts(void)
{
    int classnum;
    for (classnum = 0; classnum < 4; classnum++)
    {
        Scr_RemoveClassMap(classnum);
    }
    return 0;
}

/* line 208 */
unsigned int ScrCmd_GetClanId(struct scr_entref_t entref)
{
    Scr_AddString("0");
    return 0;
}

/* line 230 */
unsigned int ScrCmd_GetClanName(scr_entref_t entref)
{
    Scr_AddString("");
    return 0;
}

/* line 251 */
unsigned int ScrCmd_GetClanMotto(scr_entref_t entref)
{
    Scr_AddString("");
    return 0;
}

/* line 272 */
unsigned int ScrCmd_GetClanDescription(scr_entref_t entref)
{
    Scr_AddString("");
    return 0;
}

/* line 293 */
unsigned int ScrCmd_GetClanURL(scr_entref_t entref)
{
    Scr_AddString("");
    return 0;
}

/* line 315 */
extern int Scr_GetNumParam(void);
extern const char *Scr_GetDebugString(unsigned int index);
extern void SV_SetConfigstring(int index, const char *val);
extern void SV_GetConfigstring(int index, char *buf, int size);
extern int G_ShaderIndex(const char *name);

unsigned int print(void) {
    int num;
    int i;

    if (g_NoScriptSpam->current.enabled)
        return 0;

    num = Scr_GetNumParam();
    if (num <= 0)
        return 0;

    for (i = 0; i < num; i++) {
        Com_Printf("%s", Scr_GetDebugString(i));
    }
    return 0;
}

/* line 623 */
unsigned int assertCmd(void)
{
    int v = Scr_GetInt(0);
    Com_Printf("DBG assert: val=%d\n", v);
    if (!v)
        Scr_Error("assert fail");
    return 0;
}

/* line 637 */
unsigned int assertexCmd(void)
{
    if (!Scr_GetInt(0))
        Scr_Error(va("assert fail: %s", Scr_GetString(1)));
    return 0;
}

/* line 651 */
unsigned int assertmsgCmd(void)
{
    Scr_Error(va("assert fail: %s", Scr_GetString(0)));
    return 0;
}

/* line 663 */
unsigned int GScr_IsDefined(void)
{
    int type = Scr_GetType(0);
    int result;

    if (type == 1) {
        int ptype = Scr_GetPointerType(0);
        if (ptype > 0x16 || ptype == 0x14) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        result = (type != 0);
    }
    Scr_AddInt(result);
    return 0;
}

/* line 688 */
unsigned int GScr_IsString(void)
{
    Scr_AddInt(Scr_GetType(0) == 2);
    return 0;
}

/* line 700 */
unsigned int GScr_IsAlive(void)
{
    if (Scr_GetType(0) == 1 && Scr_GetPointerType(0) == 0x15) {
        gentity_t *ent = Scr_GetEntity(0);
        if (ent->health > 0) {
            Scr_AddInt(1);
            return 0;
        }
    }
    Scr_AddInt(0);
    return 0;
}

/* line 730 */
unsigned int GScr_GetDvar(void)
{
    const char *name = Scr_GetString(0);
    const char *val = Dvar_GetVariantString(name);
    Scr_AddString(val);
    return 0;
}

/* line 746 */
unsigned int GScr_GetDvarInt(void)
{
    Scr_AddInt(atoi(Dvar_GetVariantString(Scr_GetString(0))));
    return 0;
}

/* line 762 */
unsigned int GScr_GetDvarFloat(void)
{
    Scr_AddFloat((float)atof(Dvar_GetVariantString(Scr_GetString(0))));
    return 0;
}

/* line 836 */
unsigned int GScr_GetTime(void)
{
    Scr_AddInt(level.time);
    return 0;
}

/* line 847 */
unsigned int Scr_GetEntByNum(void)
{
    unsigned int num = Scr_GetInt(0);
    gentity_t *ent;

    if (num > 0x3ff)
        return 0;
    ent = &g_entities[num];
    if (ent->r.inuse)
        Scr_AddEntity(ent);
    return 0;
}

/* line 867 */
unsigned int Scr_GetWeaponModel(void)
{
    const char *pszWeaponName = Scr_GetString(0);
    int weaponIndex = G_GetWeaponIndexForName(pszWeaponName);

    if (weaponIndex) {
        Scr_AddString(((WeaponDef *)BG_GetWeaponDef(weaponIndex))->szWorldModel);
    } else {
        if (pszWeaponName[0] && I_stricmp(pszWeaponName, "none") != 0) {
            Com_Printf(va("unknown weapon '%s' in getWeaponModel\n", pszWeaponName));
        }
        Scr_AddString("");
    }
    return 0;
}

/* line 916 */
unsigned int GScr_GetAnimLength(void)
{
    unsigned int anim = Scr_GetAnim(0, 0);
    void *anims = Scr_GetAnims(anim >> 16);
    unsigned int animIndex = anim & 0xffff;

    if (!XAnimIsPrimitive(anims, animIndex))
        Scr_ParamError(0, (const char *)str_002b124c);
    Scr_AddFloat(XAnimGetLength(anims, animIndex));
    return 0;
}

/* line 934 */
unsigned int GScr_AnimHasNotetrack(void)
{
    unsigned int anim = Scr_GetAnim(0, 0);
    unsigned int treeIndex = anim >> 16;
    unsigned int animIndex = anim & 0xffff;
    unsigned int notetrack = Scr_GetConstString(1);
    void *anims = Scr_GetAnims(treeIndex);

    Scr_AddBool(XAnimNotetrackExists(anims, animIndex, notetrack));
    return 0;
}

/* line 1031 */
unsigned int GScr_PrecacheTurret(void)
{
    if (!level.initializing)
        Scr_Error("PrecacheTurret must be called before any wait statements in the gametype or level script");
    G_GetWeaponIndexForName(Scr_GetString(0));
    return 0;
}

/* line 1411 */
unsigned int ScrCmd_SoundExists(void)
{
    Scr_AddBool(Com_FindSoundAlias(Scr_GetString(0)) != 0);
    return 0;
}

/* line 1543 */
unsigned int ScrCmd_PlayRumble(scr_entref_t entref)
{
    return 0;
}

/* line 1556 */
unsigned int ScrCmd_PlayLoopRumble(scr_entref_t entref)
{
    return 0;
}

/* line 1569 */
unsigned int ScrCmd_StopRumble(scr_entref_t entref)
{
    return 0;
}

/* line 1862 */
qboolean G_GetHintStringIndex(int *piIndex, const char *pszString) {
    int i;
    char szConfigString[0x400];

    for (i = 0; i < 0x20; i++) {
        int csIndex = 0x4fe + i;
        SV_GetConfigstring(csIndex, szConfigString, 0x400);
        if (szConfigString[0] == '\0') {
            /* Empty slot - use it */
            SV_SetConfigstring(csIndex, pszString);
            *piIndex = i;
            return 1;
        }
        if (strcmp(pszString, szConfigString) == 0) {
            /* Already exists */
            *piIndex = i;
            return 1;
        }
    }

    /* No free slot */
    *piIndex = -1;
    return 0;
}

/* line 2109 */
static void SetObjectiveIcon_impl(objective_t *obj, int paramNum) {
    const char *shaderName;
    int i;
    unsigned char ch;

    shaderName = (const char *)Scr_GetString(paramNum);
    ch = (unsigned char)shaderName[0];
    if (ch != '\0') {
        for (i = 0; shaderName[i] != '\0'; i++) {
            ch = (unsigned char)shaderName[i];
            /* Check printable ASCII range: 0x20..0x7e */
            if ((unsigned char)(ch - 0x20) > 0x5e) {
                Scr_ParamError(3, va("Illegal character '%c'(ascii %i) in objective icon name: %s\n", (int)(signed char)ch, (int)(unsigned char)ch, shaderName));
            }
        }
        if (i > 0x3f) {
            Scr_ParamError(3, va("Objective icon name is too long (> %i): %s\n", 0x3f, shaderName));
        }
    }
    obj->icon = G_ShaderIndex(shaderName);
}
unsigned int SetObjectiveIcon(void) { return 0; /* naked caller only */ }

/* line 2232 */
unsigned int Scr_Objective_Icon(void) {
    int objIndex;
    objective_t *obj;

    objIndex = Scr_GetInt(0);
    if ((unsigned int)objIndex > 0xf) {
        Scr_ParamError(0, va("index %i is an illegal objective index. Valid indexes are 0 to %i\n", objIndex, 0xf));
    }

    obj = &level.objectives[objIndex];
    SetObjectiveIcon_impl(obj, 1);
    return 0;
}

/* line 2274 */
unsigned int Scr_Objective_OnEntity(void) {
    int objIndex;
    objective_t *obj;
    int oldEntityNum;
    gentity_t *oldEnt;
    gentity_t *newEnt;

    objIndex = Scr_GetInt(0);
    if ((unsigned int)objIndex > 0xf) {
        Scr_ParamError(0, va("index %i is an illegal objective index. Valid indexes are 0 to %i\n", objIndex, 0xf));
    }

    obj = &level.objectives[objIndex];

    /* Clear old entity's objective flag */
    oldEntityNum = obj->entNum;
    if (oldEntityNum != 0x3ff) {
        oldEnt = &g_entities[oldEntityNum];
        if (oldEnt->r.inuse) {
            /* Clear EF_OBJECTIVE flag (0x10) */
            oldEnt->r.svFlags &= ~0x10;
        }
        obj->entNum = 0x3ff;
    }

    /* Set new entity */
    newEnt = Scr_GetEntity(1);
    /* Set EF_OBJECTIVE flag */
    newEnt->r.svFlags |= 0x10;
    /* Store entity number */
    obj->entNum = newEnt->s.number;

    return 0;
}
