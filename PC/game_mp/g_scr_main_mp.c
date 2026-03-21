/* ASM dump from: g_scr_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_scr_main_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

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
    unsigned int handle = *(unsigned int *)&g_scr_data;
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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
unsigned int print(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 315 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl imp_g_NoScriptSpam, %eax\n" /* line 320 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf19544e_0019546a\n"
        /* } scope */
        ".Lf19544e_00195463:\n"
        "addl $0x10, %esp\n" /* line 326 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19544e_0019546a:\n"
        "calll Scr_GetNumParam\n" /* line 323 */
        "movl %eax, %esi\n" /* num */
        "testl %eax, %eax\n" /* line 324 */
        "jle .Lf19544e_00195463\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf19544e_00195477:\n"
        "movl %ebx, (%esp)\n" /* line 325 | i */
        "calll Scr_GetDebugString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 324 | i */
        "cmpl %ebx, %esi\n" /* i, num */
        "jne .Lf19544e_00195477\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 326 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
extern int Scr_GetNumParam(void);
extern const char *Scr_GetDebugString(unsigned int index);
extern void SV_SetConfigstring(int index, const char *val);
extern void SV_GetConfigstring(int index, char *buf, int size);
extern int G_ShaderIndex(const char *name);

unsigned int print(void) {
    int num;
    int i;

    if (*(byte *)(*(int *)(*(int *)imp_g_NoScriptSpam) + 8))
        return 0;

    num = Scr_GetNumParam();
    if (num <= 0)
        return 0;

    for (i = 0; i < num; i++) {
        Com_Printf("%s", Scr_GetDebugString(i));
    }
    return 0;
}
#endif

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
    Scr_AddInt(((level_locals_t *)imp_level)->time);
    return 0;
}

/* line 847 */
unsigned int Scr_GetEntByNum(void)
{
    unsigned int num = Scr_GetInt(0);
    gentity_t *ent;

    if (num > 0x3ff)
        return 0;
    ent = (gentity_t *)((byte *)*(void **)imp_g_entities + num * 560);
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
        Scr_AddString(*(const char **)((byte *)BG_GetWeaponDef(weaponIndex) + 0x1b4)); /* TODO: unknown weaponDef offset 0x1b4 */
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
    if (!((level_locals_t *)imp_level)->initializing)
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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
qboolean G_GetHintStringIndex(int *piIndex, const char *pszString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1862 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        "xorl %esi, %esi\n"
        "leal -0x418(%ebp), %edi\n" /* szConfigString */
        "jmp .Lf1958b6_001958e7\n"
        /* { scope 1 */
        ".Lf1958b6_001958cc:\n"
        "movl %edi, 4(%esp)\n" /* line 1876 */
        "movl 0xc(%ebp), %eax\n" /* pszString */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1958b6_0019592e\n"
        "addl $1, %esi\n" /* line 1867 | i */
        "cmpl $0x20, %esi\n" /* i */
        "je .Lf1958b6_00195943\n"
        /* } scope */
        ".Lf1958b6_001958e7:\n"
        "leal 0x4fe(%esi), %ebx\n" /* line 1862 */
        /* { scope 1 */
        "movl $0x400, 8(%esp)\n" /* line 1869 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "cmpb $0, -0x418(%ebp)\n" /* line 1870 | szConfigString */
        "jne .Lf1958b6_001958cc\n"
        "movl 0xc(%ebp), %eax\n" /* line 1872 | pszString */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 8(%ebp), %eax\n" /* line 1873 | piIndex */
        "movl %esi, (%eax)\n" /* i */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x41c, %esp\n" /* line 1885 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1958b6_0019592e:\n"
        "movl 8(%ebp), %eax\n" /* line 1878 | piIndex */
        "movl %esi, (%eax)\n" /* i */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x41c, %esp\n" /* line 1885 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1958b6_00195943:\n"
        "movl 8(%ebp), %eax\n" /* line 1883 | piIndex */
        "movl $0xffffffff, (%eax)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x41c, %esp\n" /* line 1885 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
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
#endif

/* line 2109 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
unsigned int SetObjectiveIcon(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2109 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %edi\n" /* obj */
        /* { scope 1 */
        "movl %edx, (%esp)\n" /* line 2114 | paramNum */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* shaderName */
        "movzbl (%eax), %edx\n" /* line 2115 | paramNum */
        "testb %dl, %dl\n" /* paramNum */
        "je .Lf19595c_001959f4\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf19595c_00195987\n"
        ".Lf19595c_0019597c:\n"
        "addl $1, %ebx\n" /* i */
        "movzbl (%esi, %ebx), %edx\n" /* shaderName, paramNum */
        "testb %dl, %dl\n" /* paramNum */
        "je .Lf19595c_001959c7\n"
        ".Lf19595c_00195987:\n"
        "leal -0x20(%edx), %eax\n" /* line 2117 | paramNum */
        "cmpb $0x5e, %al\n"
        "jbe .Lf19595c_0019597c\n"
        "movl %esi, 0xc(%esp)\n" /* line 2118 | shaderName */
        "movzbl %dl, %eax\n" /* paramNum */
        "movl %eax, 8(%esp)\n"
        "movsbl %dl, %eax\n" /* paramNum */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b12d0, (%esp)\n" /* "Illegal character '%c'(ascii %i) in objective icon name: %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll Scr_ParamError\n"
        "addl $1, %ebx\n" /* line 2115 | i */
        "movzbl (%esi, %ebx), %edx\n" /* shaderName, paramNum */
        "testb %dl, %dl\n" /* paramNum */
        "jne .Lf19595c_00195987\n"
        ".Lf19595c_001959c7:\n"
        "cmpl $0x3f, %ebx\n" /* line 2120 | i */
        "jle .Lf19595c_001959f4\n"
        "movl %esi, 8(%esp)\n" /* line 2121 | shaderName */
        "movl $0x3f, 4(%esp)\n"
        "movl $str_002b1310, (%esp)\n" /* "Objective icon name is too long (> %i): %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf19595c_001959f4:\n"
        "movl %esi, (%esp)\n" /* line 2123 | shaderName */
        "calll G_ShaderIndex\n"
        "movl %eax, 0x18(%edi)\n" /* obj */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2124 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
static void SetObjectiveIcon_impl(byte *obj, int paramNum) {
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
    ((objective_t *)obj)->icon = G_ShaderIndex(shaderName);
}
unsigned int SetObjectiveIcon(void) { return 0; /* naked caller only */ }
#endif

/* line 2232 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
unsigned int Scr_Objective_Icon(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2232 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $0, (%esp)\n" /* line 2236 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n"
        "cmpl $0xf, %eax\n" /* line 2237 */
        "jbe .Lf195a08_00195a4a\n"
        "movl $0xf, 8(%esp)\n" /* line 2238 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b133c, (%esp)\n" /* "index %i is an illegal objective index. Valid indexes are 0 " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf195a08_00195a4a:\n"
        "leal (, %ebx, 4), %eax\n" /* line 2240 */
        "shll $5, %ebx\n"
        "subl %eax, %ebx\n"
        "movl imp_level, %eax\n"
        "addl $0x24, %eax\n"
        "leal (%ebx, %eax), %eax\n"
        "movl $1, %edx\n"
        "addl $0x14, %esp\n" /* line 2241 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SetObjectiveIcon\n" /* line 2240 */
    );
}
#else
unsigned int Scr_Objective_Icon(void) {
    int objIndex;
    byte *obj;

    objIndex = Scr_GetInt(0);
    if ((unsigned int)objIndex > 0xf) {
        Scr_ParamError(0, va("index %i is an illegal objective index. Valid indexes are 0 to %i\n", objIndex, 0xf));
    }

    /* obj = &level.objectives[objIndex] */
    obj = (byte *)&((level_locals_t *)imp_level)->objectives[objIndex];
    SetObjectiveIcon_impl(obj, 1);
    return 0;
}
#endif

/* line 2274 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
unsigned int Scr_Objective_OnEntity(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2274 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 2280 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* obj */
        "cmpl $0xf, %eax\n" /* line 2281 */
        "ja .Lf195a70_00195af6\n"
        ".Lf195a70_00195a8a:\n"
        "leal (, %ebx, 4), %eax\n" /* line 2283 */
        "shll $5, %ebx\n" /* obj */
        "subl %eax, %ebx\n" /* obj */
        "movl imp_level, %eax\n"
        "addl $0x24, %eax\n"
        "addl %eax, %ebx\n" /* obj */
        "movl 0x10(%ebx), %eax\n" /* line 2077 */
        "cmpl $0x3ff, %eax\n"
        "je .Lf195a70_00195acf\n"
        /* { scope 2 */
        "leal (%eax, %eax, 4), %eax\n" /* line 2081 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "cmpb $0, 0xfc(%edx)\n" /* line 2082 */
        "jne .Lf195a70_00195aed\n"
        ".Lf195a70_00195ac8:\n"
        "movl $0x3ff, 0x10(%ebx)\n" /* line 2085 */
        /* } scope */
        ".Lf195a70_00195acf:\n"
        "movl $1, (%esp)\n" /* line 2286 */
        "calll Scr_GetEntity\n"
        "orb $0x10, 0xf2(%eax)\n" /* line 2287 */
        "movl (%eax), %eax\n" /* line 2288 */
        "movl %eax, 0x10(%ebx)\n" /* obj */
        /* } scope */
        "addl $0x14, %esp\n" /* line 2289 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf195a70_00195aed:\n"
        "andb $0xef, 0xf2(%edx)\n" /* line 2083 */
        "jmp .Lf195a70_00195ac8\n"
        /* } scope */
        ".Lf195a70_00195af6:\n"
        "movl $0xf, 8(%esp)\n" /* line 2282 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b133c, (%esp)\n" /* "index %i is an illegal objective index. Valid indexes are 0 " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf195a70_00195a8a\n"
    );
}

/* line 2301 */
__attribute__((naked))
unsigned int Scr_Objective_Current(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2301 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 2309 */
        "movl %eax, -0x5c(%ebp)\n" /* numParam */
        "leal -0x58(%ebp), %esi\n" /* line 2310 | makeCurrent */
        "cld\n"
        "movl $0x10, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* objNum */
        "rep stosl %eax, %es:(%edi)\n" /* objNum */
        "movl -0x5c(%ebp), %ebx\n" /* line 2311 | numParam, i */
        "testl %ebx, %ebx\n" /* i */
        "jg .Lf195b24_00195b92\n"
        ".Lf195b24_00195b4b:\n"
        "movl $1, %eax\n"
        "movl imp_level, %edx\n"
        "addl $0x24, %edx\n"
        "jmp .Lf195b24_00195b6c\n"
        ".Lf195b24_00195b5b:\n"
        "movl $4, (%edx)\n" /* line 2323 */
        ".Lf195b24_00195b61:\n"
        "addl $1, %eax\n" /* line 2325 */
        "addl $0x1c, %edx\n"
        "cmpl $0x11, %eax\n" /* line 2319 */
        "je .Lf195b24_00195b8a\n"
        ".Lf195b24_00195b6c:\n"
        "movl -4(%esi, %eax, 4), %ecx\n" /* line 2322 */
        "testl %ecx, %ecx\n"
        "jne .Lf195b24_00195b5b\n"
        "cmpl $4, (%edx)\n" /* line 2324 */
        "jne .Lf195b24_00195b61\n"
        "movl $1, (%edx)\n" /* line 2325 */
        "addl $1, %eax\n"
        "addl $0x1c, %edx\n"
        "cmpl $0x11, %eax\n" /* line 2319 */
        "jne .Lf195b24_00195b6c\n"
        /* } scope */
        ".Lf195b24_00195b8a:\n"
        "addl $0x6c, %esp\n" /* line 2327 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195b24_00195b92:\n"
        "xorl %ebx, %ebx\n" /* line 2311 | i */
        "jmp .Lf195b24_00195ba6\n"
        ".Lf195b24_00195b96:\n"
        "movl $1, -0x58(%ebp, %edi, 4)\n" /* line 2316 */
        "addl $1, %ebx\n" /* line 2311 | i */
        "cmpl %ebx, -0x5c(%ebp)\n" /* i, numParam */
        "je .Lf195b24_00195b4b\n"
        ".Lf195b24_00195ba6:\n"
        "movl %ebx, (%esp)\n" /* line 2313 | i */
        "calll Scr_GetInt\n"
        "movl %eax, %edi\n" /* objNum */
        "cmpl $0xf, %eax\n" /* line 2314 */
        "jbe .Lf195b24_00195b96\n"
        "movl $0xf, 8(%esp)\n" /* line 2315 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b133c, (%esp)\n" /* "index %i is an illegal objective index. Valid indexes are 0 " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll Scr_ParamError\n"
        "jmp .Lf195b24_00195b96\n"
    );
}

/* line 2340 */
__attribute__((naked))
unsigned int GScr_Objective_Team(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2340 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 2346 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* obj */
        "cmpl $0xf, %eax\n" /* line 2347 */
        "ja .Lf195bdc_00195c6e\n"
        ".Lf195bdc_00195bf6:\n"
        "leal (, %ebx, 4), %eax\n" /* line 2349 */
        "shll $5, %ebx\n" /* obj */
        "subl %eax, %ebx\n" /* obj */
        "movl imp_level, %eax\n"
        "addl $0x24, %eax\n"
        "addl %eax, %ebx\n" /* obj */
        "movl $1, (%esp)\n" /* line 2351 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 2352 */
        "cmpw 2(%edx), %ax\n"
        "je .Lf195bdc_00195c9b\n"
        "cmpw 4(%edx), %ax\n" /* line 2354 */
        "je .Lf195bdc_00195ca8\n"
        "cmpw 0x74(%edx), %ax\n" /* line 2356 */
        "je .Lf195bdc_00195c61\n"
        "movzwl %ax, %eax\n" /* line 2359 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b1380, (%esp)\n" /* "Illegal team string '%s'. Must be allies, axis, or none." */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 2360 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195bdc_00195c61:\n"
        "movl $0, 0x14(%ebx)\n" /* line 2357 | obj */
        /* } scope */
        "addl $0x14, %esp\n" /* line 2360 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195bdc_00195c6e:\n"
        "movl $0xf, 8(%esp)\n" /* line 2348 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b133c, (%esp)\n" /* "index %i is an illegal objective index. Valid indexes are 0 " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf195bdc_00195bf6\n"
        ".Lf195bdc_00195c9b:\n"
        "movl $2, 0x14(%ebx)\n" /* line 2353 | obj */
        /* } scope */
        "addl $0x14, %esp\n" /* line 2360 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195bdc_00195ca8:\n"
        "movl $1, 0x14(%ebx)\n" /* line 2355 | obj */
        /* } scope */
        "addl $0x14, %esp\n" /* line 2360 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2370 */
__attribute__((naked))
unsigned int GScr_LogPrint(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2370 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "movb $0, -0x418(%ebp)\n" /* line 2379 | string */
        "calll Scr_GetNumParam\n" /* line 2382 */
        "movl %eax, -0x41c(%ebp)\n" /* iNumParms */
        "testl %eax, %eax\n" /* line 2383 */
        "jg .Lf195cb6_00195cf1\n"
        ".Lf195cb6_00195cd8:\n"
        "leal -0x418(%ebp), %eax\n" /* line 2396 | string */
        "movl %eax, (%esp)\n"
        "calll G_LogPrintf\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2397 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195cb6_00195cf1:\n"
        "xorl %esi, %esi\n" /* line 2383 | iStringLen */
        "xorl %ebx, %ebx\n" /* i */
        ".Lf195cb6_00195cf5:\n"
        "movl %ebx, (%esp)\n" /* line 2385 | i */
        "calll Scr_GetString\n"
        "movl %eax, %edx\n"
        "cld\n" /* line 2386 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %esi), %esi\n" /* iStringLen */
        "cmpl $0x3ff, %esi\n" /* line 2387 | iStringLen */
        "jg .Lf195cb6_00195cd8\n"
        "movl %edx, 8(%esp)\n" /* line 2389 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll I_strncat\n"
        "addl $1, %ebx\n" /* line 2383 | i */
        "cmpl %ebx, -0x41c(%ebp)\n" /* i, iNumParms */
        "jne .Lf195cb6_00195cf5\n"
        "leal -0x418(%ebp), %eax\n" /* line 2396 | string */
        "movl %eax, (%esp)\n"
        "calll G_LogPrintf\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2397 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2407 */
unsigned int GScr_WorldEntNumber(void)
{
    Scr_AddInt(0x3fe);
    return 0;
}

/* line 2418 */
__attribute__((naked))
unsigned int GScr_Obituary(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2418 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $2, (%esp)\n" /* line 2434 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 2435 */
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, -0x1c(%ebp)\n" /* iWeaponNum */
        "movl $3, (%esp)\n" /* line 2437 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 2438 */
        "calll G_IndexForMeansOfDeath\n"
        "movl %eax, %esi\n" /* iMODNum */
        "movl $0, (%esp)\n" /* line 2441 */
        "calll Scr_GetEntity\n"
        "movl %eax, %ebx\n" /* pOtherEnt */
        "movl $0xc6, 4(%esp)\n" /* line 2446 */
        "movl imp_vec3_origin, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_TempEntity\n"
        "movl %eax, %edi\n" /* pEnt */
        "movl (%ebx), %eax\n" /* line 2447 | pOtherEnt */
        "movl %eax, 0x74(%edi)\n" /* pEnt */
        "movl $1, (%esp)\n" /* line 2451 */
        "calll Scr_GetType\n"
        "subl $1, %eax\n"
        "je .Lf195d6c_00195e27\n"
        ".Lf195d6c_00195ddd:\n"
        "movl $0x3fe, 0x78(%edi)\n" /* line 2465 | pEnt */
        ".Lf195d6c_00195de4:\n"
        "movb $8, 0xf2(%edi)\n" /* line 2470 | pEnt */
        "leal -7(%esi), %eax\n" /* line 2474 | iMODNum */
        "cmpl $1, %eax\n"
        "jbe .Lf195d6c_00195e13\n"
        "cmpl $0xc, %esi\n" /* iMODNum */
        "je .Lf195d6c_00195e13\n"
        "cmpl $0xb, %esi\n" /* iMODNum */
        "je .Lf195d6c_00195e13\n"
        "cmpl $9, %esi\n" /* iMODNum */
        "je .Lf195d6c_00195e13\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2488 | iWeaponNum */
        "movl %eax, 0xa0(%edi)\n" /* pEnt */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2495 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195d6c_00195e13:\n"
        "orl $0x80, %esi\n" /* line 2480 | iMODNum */
        "movl %esi, 0xa0(%edi)\n" /* iMODNum, pEnt */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2495 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195d6c_00195e27:\n"
        "movl $1, (%esp)\n" /* line 2451 */
        "calll Scr_GetPointerType\n"
        "cmpl $0x15, %eax\n"
        "jne .Lf195d6c_00195ddd\n"
        "movl $1, (%esp)\n" /* line 2453 */
        "calll Scr_GetEntity\n"
        "movl (%eax), %eax\n" /* line 2457 */
        "movl %eax, 0x78(%edi)\n" /* pEnt */
        "jmp .Lf195d6c_00195de4\n"
    );
}

/* line 2541 */
unsigned int GScr_getStartTime(void)
{
    Scr_AddInt(((level_locals_t *)imp_level)->startTime);
    return 0;
}

/* line 2552 */
__attribute__((naked))
unsigned int GScr_PrecacheMenu(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2552 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 2558 */
        "calll Scr_GetString\n"
        "movl %eax, -0x41c(%ebp)\n" /* pszNewMenu */
        "movl $0x4de, %ebx\n"
        "leal -0x418(%ebp), %edi\n" /* szConfigString */
        "jmp .Lf195e68_00195e9e\n"
        ".Lf195e68_00195e93:\n"
        "addl $1, %ebx\n" /* line 2568 */
        "cmpl $0x4fe, %ebx\n" /* line 2561 */
        "je .Lf195e68_00195ee9\n"
        ".Lf195e68_00195e9e:\n"
        "movl $0x400, 8(%esp)\n" /* line 2563 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2564 | pszNewMenu */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf195e68_00195e93\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2567 | pszNewMenu */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b13bc, (%esp)\n" /* "Script tried to precache the menu '%s' more than once
" */
        "calll Com_DPrintf\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2586 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195e68_00195ee9:\n"
        "xorl %esi, %esi\n" /* line 2561 | iConfigNum */
        "jmp .Lf195e68_00195ef5\n"
        ".Lf195e68_00195eed:\n"
        "addl $1, %esi\n" /* line 2573 | iConfigNum */
        "cmpl $0x20, %esi\n" /* iConfigNum */
        "je .Lf195e68_00195f35\n"
        ".Lf195e68_00195ef5:\n"
        "leal 0x4de(%esi), %ebx\n" /* line 2561 | iConfigNum */
        "movl $0x400, 8(%esp)\n" /* line 2575 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "cmpb $0, -0x418(%ebp)\n" /* line 2576 | szConfigString */
        "jne .Lf195e68_00195eed\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2585 | pszNewMenu */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        ".Lf195e68_00195f2a:\n"
        "addl $0x42c, %esp\n" /* line 2586 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195e68_00195f35:\n"
        "movl $0x20, 4(%esp)\n" /* line 2582 */
        "movl $str_002b13f4, (%esp)\n" /* "Too many menus precached. Max allowed menus is %i" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl $0x4fe, %ebx\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2585 | pszNewMenu */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "jmp .Lf195e68_00195f2a\n"
    );
}

/* line 2596 */
__attribute__((naked))
int GScr_GetScriptMenuIndex(const char *pszMenu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2596 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        "movl 8(%ebp), %edi\n" /* pszMenu */
        "xorl %ebx, %ebx\n"
        "leal -0x418(%ebp), %esi\n" /* szConfigString */
        "jmp .Lf195f6a_00195f8b\n"
        /* { scope 1 */
        ".Lf195f6a_00195f83:\n"
        "addl $1, %ebx\n" /* line 2601 | iConfigNum */
        "cmpl $0x20, %ebx\n" /* iConfigNum */
        "je .Lf195f6a_00195fc2\n"
        ".Lf195f6a_00195f8b:\n"
        "movl $0x400, 8(%esp)\n" /* line 2603 */
        "movl %esi, 4(%esp)\n"
        "leal 0x4de(%ebx), %eax\n" /* iConfigNum */
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl %edi, 4(%esp)\n" /* line 2604 | pszMenu */
        "movl %esi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf195f6a_00195f83\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 2611 | iConfigNum */
        "addl $0x41c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195f6a_00195fc2:\n"
        "movl %edi, 4(%esp)\n" /* line 2609 | pszMenu */
        "movl $str_002b1428, (%esp)\n" /* "Menu '%s' was not precached
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "xorb %bl, %bl\n" /* iConfigNum */
        /* } scope */
        "movl %ebx, %eax\n" /* line 2611 | iConfigNum */
        "addl $0x41c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2619 */
__attribute__((naked))
unsigned int GScr_PrecacheStatusIcon(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2619 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 2625 */
        "calll Scr_GetString\n"
        "movl %eax, -0x41c(%ebp)\n" /* pszNewIcon */
        "movl $0x17, %ebx\n"
        "leal -0x418(%ebp), %edi\n" /* szConfigString */
        ".Lf195fea_00196013:\n"
        "movl $0x400, 8(%esp)\n" /* line 2630 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2631 | pszNewIcon */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf195fea_001960ad\n"
        "addl $1, %ebx\n" /* line 2635 */
        "cmpl $0x1f, %ebx\n" /* line 2628 */
        "jne .Lf195fea_00196013\n"
        "xorl %esi, %esi\n" /* iConfigNum */
        ".Lf195fea_00196047:\n"
        "leal 0x17(%esi), %ebx\n" /* iConfigNum */
        "movl $0x400, 8(%esp)\n" /* line 2642 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "cmpb $0, -0x418(%ebp)\n" /* line 2643 | szConfigString */
        "je .Lf195fea_00196090\n"
        "addl $1, %esi\n" /* line 2640 | iConfigNum */
        "cmpl $8, %esi\n" /* iConfigNum */
        "jne .Lf195fea_00196047\n"
        "movl $8, 4(%esp)\n" /* line 2649 */
        "movl $str_002b1490, (%esp)\n" /* "Too many player status icons precached. Max allowed is %i" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl $0x1f, %ebx\n"
        ".Lf195fea_00196090:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2652 | pszNewIcon */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195fea_001960ad:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2634 | pszNewIcon */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b1448, (%esp)\n" /* "Script tried to precache the player status icon '%s' more th" */
        "calll Com_DPrintf\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2664 */
__attribute__((naked))
int GScr_GetStatusIconIndex(const char *pszIcon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2664 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pszIcon */
        /* { scope 1 */
        "cmpb $0, (%esi)\n" /* line 2669 | pszIcon */
        "jne .Lf1960ce_001960ef\n"
        ".Lf1960ce_001960e2:\n"
        "xorl %eax, %eax\n" /* line 2680 */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 2682 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1960ce_001960ef:\n"
        "xorl %ebx, %ebx\n" /* line 2669 | iConfigNum */
        "leal -0x418(%ebp), %edi\n" /* szConfigString */
        ".Lf1960ce_001960f7:\n"
        "movl $0x400, 8(%esp)\n" /* line 2674 */
        "movl %edi, 4(%esp)\n"
        "leal 0x17(%ebx), %eax\n" /* iConfigNum */
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl %esi, 4(%esp)\n" /* line 2675 | pszIcon */
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1960ce_00196140\n"
        "addl $1, %ebx\n" /* line 2672 | iConfigNum */
        "cmpl $8, %ebx\n" /* iConfigNum */
        "jne .Lf1960ce_001960f7\n"
        "movl %esi, 4(%esp)\n" /* line 2680 | pszIcon */
        "movl $str_002b14cc, (%esp)\n" /* "Status icon '%s' was not precached
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf1960ce_001960e2\n"
        ".Lf1960ce_00196140:\n"
        "leal 1(%ebx), %eax\n" /* line 2676 | iConfigNum */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 2682 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2690 */
__attribute__((naked))
unsigned int GScr_PrecacheHeadIcon(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2690 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 2696 */
        "calll Scr_GetString\n"
        "movl %eax, -0x41c(%ebp)\n" /* pszNewIcon */
        "movl $0x1f, %ebx\n"
        "leal -0x418(%ebp), %edi\n" /* szConfigString */
        ".Lf19614e_00196177:\n"
        "movl $0x400, 8(%esp)\n" /* line 2701 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2702 | pszNewIcon */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf19614e_00196211\n"
        "addl $1, %ebx\n" /* line 2706 */
        "cmpl $0x2e, %ebx\n" /* line 2699 */
        "jne .Lf19614e_00196177\n"
        "xorl %esi, %esi\n" /* iConfigNum */
        ".Lf19614e_001961ab:\n"
        "leal 0x1f(%esi), %ebx\n" /* iConfigNum */
        "movl $0x400, 8(%esp)\n" /* line 2713 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "cmpb $0, -0x418(%ebp)\n" /* line 2714 | szConfigString */
        "je .Lf19614e_001961f4\n"
        "addl $1, %esi\n" /* line 2711 | iConfigNum */
        "cmpl $0xf, %esi\n" /* iConfigNum */
        "jne .Lf19614e_001961ab\n"
        "movl $0xf, 4(%esp)\n" /* line 2720 */
        "movl $str_002b1534, (%esp)\n" /* "Too many player head icons precached. Max allowed is %i" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl $0x2e, %ebx\n"
        ".Lf19614e_001961f4:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2723 | pszNewIcon */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2724 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19614e_00196211:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 2705 | pszNewIcon */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b14f0, (%esp)\n" /* "Script tried to precache the player head icon '%s' more than" */
        "calll Com_DPrintf\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2724 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2735 */
__attribute__((naked))
int GScr_GetHeadIconIndex(const char *pszIcon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2735 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pszIcon */
        /* { scope 1 */
        "cmpb $0, (%esi)\n" /* line 2740 | pszIcon */
        "jne .Lf196232_00196253\n"
        ".Lf196232_00196246:\n"
        "xorl %eax, %eax\n" /* line 2751 */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 2753 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf196232_00196253:\n"
        "xorl %ebx, %ebx\n" /* line 2740 | iConfigNum */
        "leal -0x418(%ebp), %edi\n" /* szConfigString */
        ".Lf196232_0019625b:\n"
        "movl $0x400, 8(%esp)\n" /* line 2745 */
        "movl %edi, 4(%esp)\n"
        "leal 0x1f(%ebx), %eax\n" /* iConfigNum */
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl %esi, 4(%esp)\n" /* line 2746 | pszIcon */
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf196232_001962a4\n"
        "addl $1, %ebx\n" /* line 2743 | iConfigNum */
        "cmpl $0xf, %ebx\n" /* iConfigNum */
        "jne .Lf196232_0019625b\n"
        "movl %esi, 4(%esp)\n" /* line 2751 | pszIcon */
        "movl $str_002b156c, (%esp)\n" /* "Head icon '%s' was not precached
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf196232_00196246\n"
        ".Lf196232_001962a4:\n"
        "leal 1(%ebx), %eax\n" /* line 2747 | iConfigNum */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 2753 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2845 */
__attribute__((naked))
unsigned int Scr_BulletTracePassed(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2845 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "leal -0x24(%ebp), %edi\n" /* line 2854 | vStart */
        "movl %edi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x30(%ebp), %esi\n" /* line 2855 | vEnd */
        "movl %esi, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $2, (%esp)\n" /* line 2857 */
        "calll Scr_GetInt\n"
        "cmpl $1, %eax\n" /* line 2858 */
        "sbbl %ebx, %ebx\n" /* iClipMask */
        "andl $0xfe000000, %ebx\n" /* iClipMask */
        "addl $0x2802831, %ebx\n" /* iClipMask */
        "movl $3, (%esp)\n" /* line 2861 */
        "calll Scr_GetType\n"
        "subl $1, %eax\n"
        "je .Lf1962b2_00196338\n"
        ".Lf1962b2_0019630f:\n"
        "movl $0x3ff, %eax\n" /* line 2864 */
        ".Lf1962b2_00196314:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 2867 | iClipMask */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll G_LocationalTracePassed\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddBool\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2868 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1962b2_00196338:\n"
        "movl $3, (%esp)\n" /* line 2861 */
        "calll Scr_GetPointerType\n"
        "cmpl $0x15, %eax\n"
        "jne .Lf1962b2_0019630f\n"
        "movl $3, (%esp)\n" /* line 2863 */
        "calll Scr_GetEntity\n"
        "movl (%eax), %eax\n" /* line 2864 */
        "jmp .Lf1962b2_00196314\n"
    );
}

/* line 2877 */
__attribute__((naked))
unsigned int Scr_SightTracePassed(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2877 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "leal -0x28(%ebp), %edi\n" /* line 2887 | vStart */
        "movl %edi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x34(%ebp), %esi\n" /* line 2888 | vEnd */
        "movl %esi, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $2, (%esp)\n" /* line 2890 */
        "calll Scr_GetInt\n"
        "cmpl $1, %eax\n" /* line 2891 */
        "sbbl %ebx, %ebx\n" /* iClipMask */
        "andl $0xfe000000, %ebx\n" /* iClipMask */
        "addl $0x2801803, %ebx\n" /* iClipMask */
        "movl $3, (%esp)\n" /* line 2894 */
        "calll Scr_GetType\n"
        "subl $1, %eax\n"
        "je .Lf19635a_0019641e\n"
        ".Lf19635a_001963b7:\n"
        "movl $0x3ff, %eax\n" /* line 2897 */
        ".Lf19635a_001963bc:\n"
        "movl %ebx, 0x10(%esp)\n" /* line 2900 | iClipMask */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* hitNum */
        "movl %eax, (%esp)\n"
        "calll G_SightTrace\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2902 | hitNum */
        "testl %eax, %eax\n"
        "jne .Lf19635a_00196405\n"
        "movl %esi, 4(%esp)\n" /* line 2904 */
        "movl %edi, (%esp)\n"
        "calll SV_FX_GetVisibility\n"
        "fstps -0x3c(%ebp)\n"
        "movl $1, %eax\n" /* line 2905 */
        "movss lit4_002ed724, %xmm0\n" /* 0.20000000298023224f */
        "ucomiss -0x3c(%ebp), %xmm0\n"
        "cmovbel -0x1c(%ebp), %eax\n" /* hitNum */
        "movl %eax, -0x1c(%ebp)\n" /* hitNum */
        ".Lf19635a_00196405:\n"
        "xorl %eax, %eax\n" /* line 2908 */
        "cmpl $0, -0x1c(%ebp)\n" /* hitNum */
        "sete %al\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddBool\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2909 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19635a_0019641e:\n"
        "movl $3, (%esp)\n" /* line 2894 */
        "calll Scr_GetPointerType\n"
        "cmpl $0x15, %eax\n"
        "jne .Lf19635a_001963b7\n"
        "movl $3, (%esp)\n" /* line 2896 */
        "calll Scr_GetEntity\n"
        "movl (%eax), %eax\n" /* line 2897 */
        "jmp .Lf19635a_001963bc\n"
    );
}

/* line 2918 */
__attribute__((naked))
unsigned int Scr_PhysicsTrace(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2918 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x70, %esp\n"
        /* { scope 1 */
        "leal -0x14(%ebp), %esi\n" /* line 2925 | start */
        "movl %esi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x20(%ebp), %ebx\n" /* line 2926 | end */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $0x00820011, 0x18(%esp)\n" /* line 2928 */
        "movl $0x3ff, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl imp_vec3_origin, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movss -0x50(%ebp), %xmm2\n" /* line 2929 | trace, fraction */
        /* { scope 2 */
        "movss -0x14(%ebp), %xmm1\n" /* line 1203 | start */
        "movss -0x20(%ebp), %xmm0\n" /* end */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n" /* endpos */
        "movss -0x10(%ebp), %xmm1\n" /* line 1204 */
        "movss -0x1c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movss -0xc(%ebp), %xmm1\n" /* line 1205 */
        "movss -0x18(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        /* } scope */
        "leal -0x2c(%ebp), %eax\n" /* line 2930 | endpos */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        /* } scope */
        "addl $0x70, %esp\n" /* line 2931 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2941 */
unsigned int Scr_RandomInt(void)
{
    int max = Scr_GetInt(0);
    if (max <= 0) {
        Com_Printf("RandomInt parm: %d  ", max);
        Scr_Error("RandomInt parm must be a positive integer");
        return 0;
    }
    Scr_AddInt(irand(0, max));
    return 0;
}

/* line 2960 */
unsigned int Scr_RandomFloat(void)
{
    float max = Scr_GetFloat(0);

    Scr_AddFloat(flrand(0, max));
    return 0;
}

/* line 2973 */
unsigned int Scr_RandomIntRange(void)
{
    int iMin = Scr_GetInt(0);
    int iMax = Scr_GetInt(1);

    if (iMin >= iMax) {
        Com_Printf("RandomIntRange parms: %d %d ", iMin, iMax);
        Scr_Error("RandomIntRange's second parameter must be greater than the first parameter");
    }
    Scr_AddInt(irand(iMin, iMax));
    return 0;
}

/* line 2992 */
unsigned int Scr_RandomFloatRange(void)
{
    float fMin = Scr_GetFloat(0);
    float fMax = Scr_GetFloat(1);

    if (fMin >= fMax) {
        Com_Printf("Scr_RandomFloatRange parms: %d %d ", (double)fMin, (double)fMax);
        Scr_Error("RandomFloatRange's second parameter must be greater than the first parameter");
    }
    Scr_AddFloat(flrand(fMin, fMax));
    return 0;
}

/* line 3011 */
unsigned int GScr_sin(void)
{
    float val = Scr_GetFloat(0);

    Scr_AddFloat((float)sin((double)val * 0.017453292519943295));
    return 0;
}

/* line 3022 */
unsigned int GScr_cos(void)
{
    float val = Scr_GetFloat(0);

    Scr_AddFloat((float)cos((double)val * 0.017453292519943295));
    return 0;
}

/* line 3033 */
__attribute__((naked))
unsigned int GScr_tan(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3033 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0, (%esp)\n" /* line 3037 */
        "calll Scr_GetFloat\n"
        "fstps -0x18(%ebp)\n"
        "cvtss2sd -0x18(%ebp), %xmm0\n"
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* radians */
        /* { scope 1 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x10(%ebp)\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0xc(%ebp)\n"
        /* } scope */
        "movss -0xc(%ebp), %xmm0\n" /* line 3038 */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "je .Lf1966e8_00196756\n"
        ".Lf1966e8_00196740:\n"
        "movss -0x10(%ebp), %xmm0\n" /* line 3040 */
        "divss -0xc(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll Scr_AddFloat\n"
        "leave\n" /* line 3041 */
        "retl\n"
        ".Lf1966e8_00196756:\n"
        "jp .Lf1966e8_00196740\n" /* line 3038 */
        "movl $str_0021d694, (%esp)\n" /* line 3039 */
        "calll Scr_Error\n"
        "movss -0x10(%ebp), %xmm0\n" /* line 3040 */
        "divss -0xc(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll Scr_AddFloat\n"
        "leave\n" /* line 3041 */
        "retl\n"
    );
}

/* line 3049 */
__attribute__((naked))
unsigned int GScr_asin(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3049 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 3053 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* x */
        "movss -0xc(%ebp), %xmm0\n" /* line 3054 | x */
        "ucomiss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        "jp .Lf19677a_0019679f\n"
        "jb .Lf19677a_001967a8\n"
        ".Lf19677a_0019679f:\n"
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf19677a_001967c7\n"
        ".Lf19677a_001967a8:\n"
        "cvtss2sd -0xc(%ebp), %xmm0\n" /* line 3055 | x */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b167c, (%esp)\n" /* "%g out of range" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf19677a_001967c7:\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 3056 | x */
        "movss %xmm0, (%esp)\n"
        "calll asinf\n"
        "fstps -0x10(%ebp)\n"
        "cvtss2sd -0x10(%ebp), %xmm0\n"
        "mulsd lit8_00307c40, %xmm0\n" /* 57.29577951308232 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll Scr_AddFloat\n"
        /* } scope */
        "leave\n" /* line 3057 */
        "retl\n"
    );
}

/* line 3065 */
unsigned int GScr_acos(void)
{
    float x = Scr_GetFloat(0);
    if (x < -1.0f || x > 1.0f)
    {
        Scr_Error(va("%g out of range", (double)x));
    }
    Scr_AddFloat((float)((double)acosf(x) * 57.29577951308232));
    return 0;
}

/* line 3081 */
unsigned int GScr_atan(void)
{
    float val = Scr_GetFloat(0);
    Scr_AddFloat((float)((double)atanf(val) * 57.29577951308232));
    return 0;
}

/* line 3092 */
unsigned int GScr_CastInt(void)
{
    int type = Scr_GetType(0);
    switch (type)
    {
    case 5:
        Scr_AddInt((int)Scr_GetFloat(0));
        break;
    case 6:
        Scr_AddInt(Scr_GetInt(0));
        break;
    case 2:
        Scr_AddInt(atoi(Scr_GetString(0)));
        break;
    default:
        Scr_ParamError(0, va("cannot cast %s to int", (const char *)Scr_GetTypeName(0)));
        break;
    }
    return 0;
}

/* line 3120 */
unsigned int Scr_Distance(void)
{
    float v0[3], v1[3];
    Scr_GetVector(0, v0);
    Scr_GetVector(1, v1);
    Scr_AddFloat(Vec3Distance(v0, v1));
    return 0;
}

/* line 3136 */
unsigned int Scr_DistanceSquared(void)
{
    float v0[3], v1[3];
    Scr_GetVector(0, v0);
    Scr_GetVector(1, v1);
    Scr_AddFloat(Vec3DistanceSq(v0, v1));
    return 0;
}

/* line 3166 */
unsigned int Scr_LengthSquared(void)
{
    float v[3];
    Scr_GetVector(0, v);
    Scr_AddFloat(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    return 0;
}

/* line 3180 */
unsigned int Scr_Closer(void)
{
    float vRef[3], vA[3], vB[3];
    float fDistASqrd, fDistBSqrd;
    Scr_GetVector(0, vRef);
    Scr_GetVector(1, vA);
    Scr_GetVector(2, vB);
    fDistASqrd = Vec3DistanceSq(vA, vRef);
    fDistBSqrd = Vec3DistanceSq(vB, vRef);
    Scr_AddInt(fDistBSqrd > fDistASqrd);
    return 0;
}

/* line 3204 */
unsigned int Scr_VectorDot(void)
{
    float a[3], b[3];
    Scr_GetVector(0, a);
    Scr_GetVector(1, b);
    Scr_AddFloat(a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
    return 0;
}

/* line 3237 */
unsigned int Scr_VectorToAngles(void)
{
    float vec[3], angles[3];
    Scr_GetVector(0, vec);
    vectoangles(vec, angles);
    Scr_AddVector(angles);
    return 0;
}

/* line 3254 */
unsigned int Scr_AnglesToUp(void)
{
    float angles[3], up[3];
    Scr_GetVector(0, angles);
    AngleVectors(angles, 0, 0, up);
    Scr_AddVector(up);
    return 0;
}

/* line 3270 */
unsigned int Scr_AnglesToRight(void)
{
    float angles[3], right[3];
    Scr_GetVector(0, angles);
    AngleVectors(angles, 0, right, 0);
    Scr_AddVector(right);
    return 0;
}

/* line 3286 */
unsigned int Scr_AnglesToForward(void)
{
    float angles[3], forward[3];
    Scr_GetVector(0, angles);
    AngleVectors(angles, forward, 0, 0);
    Scr_AddVector(forward);
    return 0;
}

/* line 3302 */
unsigned int Scr_IsSubStr(void)
{
    const char *sub = Scr_GetString(1);
    const char *s = Scr_GetString(0);
    Scr_AddBool(strstr(s, sub) != 0);
    return 0;
}

/* line 3315 */
__attribute__((naked))
unsigned int Scr_GetSubStr(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3315 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 3325 */
        "calll Scr_GetString\n"
        "movl %eax, -0x41c(%ebp)\n" /* s */
        "movl $1, (%esp)\n" /* line 3326 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* start */
        "calll Scr_GetNumParam\n" /* line 3327 */
        "cmpl $2, %eax\n"
        "ja .Lf196c62_00196cfe\n"
        "movl $0x7fffffff, %eax\n"
        ".Lf196c62_00196c9d:\n"
        "cmpl %ebx, %eax\n" /* line 3329 | start */
        "jg .Lf196c62_00196cc4\n"
        "xorl %esi, %esi\n" /* dest */
        ".Lf196c62_00196ca3:\n"
        "movb $0, -0x418(%ebp, %esi)\n" /* line 3340 */
        "leal -0x418(%ebp), %eax\n" /* line 3341 | tempString */
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 3342 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf196c62_00196cc4:\n"
        "xorl %esi, %esi\n" /* line 3329 | dest */
        "movl %eax, %edi\n"
        "subl %ebx, %edi\n" /* start */
        "addl -0x41c(%ebp), %ebx\n" /* s, start */
        ".Lf196c62_00196cd0:\n"
        "movzbl (%ebx), %eax\n" /* line 3334 | start */
        "testb %al, %al\n" /* line 3335 */
        "je .Lf196c62_00196ca3\n"
        "movb %al, -0x418(%esi, %ebp)\n" /* line 3337 | dest */
        "addl $1, %esi\n" /* line 3329 | dest */
        "addl $1, %ebx\n" /* start */
        "cmpl %esi, %edi\n" /* dest */
        "je .Lf196c62_00196ca3\n"
        "cmpl $0x3ff, %esi\n" /* line 3331 | dest */
        "jle .Lf196c62_00196cd0\n"
        "movl $str_002b16a4, (%esp)\n" /* line 3332 */
        "calll Scr_Error\n"
        "jmp .Lf196c62_00196cd0\n"
        ".Lf196c62_00196cfe:\n"
        "movl $2, (%esp)\n" /* line 3327 */
        "calll Scr_GetInt\n"
        "jmp .Lf196c62_00196c9d\n"
    );
}

/* line 3350 */
__attribute__((naked))
unsigned int Scr_ToLower(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3350 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 3357 */
        "calll Scr_GetString\n"
        "movl %eax, %ebx\n" /* s */
        "movl $1, %esi\n"
        "leal -0x418(%ebp), %edi\n" /* tempString */
        "jmp .Lf196d0c_00196d41\n"
        ".Lf196d0c_00196d33:\n"
        "addl $1, %ebx\n" /* line 3359 | s */
        "addl $1, %esi\n"
        "cmpl $0x401, %esi\n"
        "je .Lf196d0c_00196d67\n"
        ".Lf196d0c_00196d41:\n"
        "movsbl (%ebx), %eax\n" /* line 3361 | s */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, -1(%esi, %edi)\n" /* line 3362 */
        "testb %al, %al\n" /* line 3363 */
        "jne .Lf196d0c_00196d33\n"
        "movl %edi, (%esp)\n" /* line 3365 */
        "calll Scr_AddString\n"
        /* } scope */
        ".Lf196d0c_00196d5c:\n"
        "addl $0x41c, %esp\n" /* line 3371 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf196d0c_00196d67:\n"
        "movl $str_002b16a4, (%esp)\n" /* line 3370 */
        "calll Scr_Error\n"
        "jmp .Lf196d0c_00196d5c\n"
    );
}

/* line 3379 */
__attribute__((naked))
unsigned int Scr_StrTok(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3379 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 3390 */
        "calll Scr_GetString\n"
        "movl %eax, %ebx\n" /* s */
        "movl $1, (%esp)\n" /* line 3391 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* delim */
        "cld\n" /* line 3393 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* delim */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x420(%ebp)\n" /* delimLen */
        "calll Scr_MakeArray\n" /* line 3396 */
        "movzbl (%ebx), %ecx\n" /* line 3400 | s */
        "testb %cl, %cl\n" /* line 3401 */
        "je .Lf196d76_00196e31\n"
        "movl $0, -0x41c(%ebp)\n" /* line 3402 | dest */
        ".Lf196d76_00196dcb:\n"
        "movl -0x420(%ebp), %eax\n" /* line 3404 | delimLen */
        "testl %eax, %eax\n"
        "jle .Lf196d76_00196e3c\n"
        "movsbl %cl, %edi\n" /* line 3406 */
        "cmpb %cl, (%esi)\n" /* delim */
        "je .Lf196d76_00196df1\n"
        "xorl %edx, %edx\n" /* line 3413 */
        ".Lf196d76_00196dde:\n"
        "addl $1, %edx\n" /* line 3404 */
        "cmpl %edx, -0x420(%ebp)\n" /* delimLen */
        "je .Lf196d76_00196e3c\n"
        "movsbl (%edx, %esi), %eax\n" /* line 3406 */
        "cmpl %edi, %eax\n"
        "jne .Lf196d76_00196dde\n"
        ".Lf196d76_00196df1:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 3409 | dest */
        "testl %eax, %eax\n"
        "jne .Lf196d76_00196e67\n"
        ".Lf196d76_00196dfb:\n"
        "movzbl 1(%ebx), %ecx\n" /* line 3400 | s */
        "addl $1, %ebx\n" /* s */
        "testb %cl, %cl\n" /* line 3401 */
        "jne .Lf196d76_00196dcb\n"
        "movl -0x41c(%ebp), %eax\n" /* line 3428 | dest */
        "testl %eax, %eax\n"
        "je .Lf196d76_00196e31\n"
        "movl -0x41c(%ebp), %eax\n" /* line 3430 | dest */
        "movb $0, -0x418(%ebp, %eax)\n"
        "leal -0x418(%ebp), %eax\n" /* line 3431 | tempString */
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        "calll Scr_AddArray\n" /* line 3432 */
        /* } scope */
        ".Lf196d76_00196e31:\n"
        "addl $0x42c, %esp\n" /* line 3435 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf196d76_00196e3c:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 3420 | dest */
        "movb %cl, -0x418(%ebp, %eax)\n"
        "addl $1, %eax\n" /* line 3421 */
        "movl %eax, -0x41c(%ebp)\n" /* dest */
        "cmpl $0x3ff, %eax\n" /* line 3422 */
        "jle .Lf196d76_00196dfb\n"
        "movl $str_002b16a4, (%esp)\n" /* line 3423 */
        "calll Scr_Error\n"
        "jmp .Lf196d76_00196dfb\n"
        ".Lf196d76_00196e67:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 3411 | dest */
        "movb $0, -0x418(%ebp, %eax)\n"
        "leal -0x418(%ebp), %eax\n" /* line 3412 | tempString */
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        "calll Scr_AddArray\n" /* line 3413 */
        "movl $0, -0x41c(%ebp)\n" /* dest */
        "jmp .Lf196d76_00196dfb\n"
    );
}

/* line 3445 */
unsigned int Scr_MusicPlay(void)
{
    SV_GameSendServerCommand(-1, 1, va("%c %s", 'o', Scr_GetString(0)));
    return 0;
}

/* line 3485 */
__attribute__((naked))
unsigned int Scr_SoundFade(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3485 */
        "movl %esp, %ebp\n"
        "subl $0x48, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 3490 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* fTargetVol */
        "calll Scr_GetNumParam\n" /* line 3492 */
        "cmpl $1, %eax\n"
        "jbe .Lf196edc_00196f58\n"
        "movl $1, (%esp)\n" /* line 3493 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "cvttss2si %xmm0, %eax\n"
        ".Lf196edc_00196f1b:\n"
        "movl %eax, 0x10(%esp)\n" /* line 3497 */
        "cvtss2sd -0xc(%ebp), %xmm0\n" /* fTargetVol */
        "movsd %xmm0, 8(%esp)\n"
        "movl $0x71, 4(%esp)\n"
        "movl $str_002b16bc, (%esp)\n" /* "%c %f %i
" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "leave\n" /* line 3498 */
        "retl\n"
        /* { scope 1 */
        ".Lf196edc_00196f58:\n"
        "xorl %eax, %eax\n" /* line 3492 */
        "jmp .Lf196edc_00196f1b\n"
    );
}

/* line 3506 */
unsigned int Scr_PrecacheModel(void)
{
    if (!((level_locals_t *)imp_level)->initializing)
        Scr_Error("precacheModel must be called before any wait statements in the gametype or level script\n");
    G_ModelIndex(Scr_GetString(0));
    return 0;
}

/* line 3520 */
unsigned int Scr_PrecacheShellShock(void)
{
    if (!((level_locals_t *)imp_level)->initializing)
        Scr_Error("PrecacheShellShock must be called before any wait statements in the gametype or level script");
    G_ShellShockIndex(Scr_GetString(0));
    return 0;
}

/* line 3534 */
__attribute__((naked))
unsigned int Scr_PrecacheItem(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3534 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl imp_level, %eax\n" /* line 3540 */
        "movl 0x1c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf196fc4_00197033\n"
        "movl $0, (%esp)\n" /* line 3543 */
        "calll Scr_GetString\n"
        "movl %eax, %ebx\n" /* pszItemName */
        "movl %eax, (%esp)\n" /* line 3544 */
        "calll G_FindItem\n"
        "movl %eax, %esi\n" /* pItem */
        "testl %eax, %eax\n" /* line 3545 */
        "je .Lf196fc4_0019705b\n"
        ".Lf196fc4_00196ff4:\n"
        "movl $1, 4(%esp)\n" /* line 3549 */
        "movl %esi, %ecx\n" /* pItem */
        "subl imp_bg_itemlist, %ecx\n"
        "sarl $2, %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "movl %ecx, %eax\n"
        "shll $0xa, %eax\n"
        "subl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $0xf, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 4), %edx\n"
        "negl %edx\n"
        "movl %edx, (%esp)\n"
        "calll RegisterItem\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 3550 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf196fc4_00197033:\n"
        "movl $str_002b1784, (%esp)\n" /* line 3541 */
        "calll Scr_Error\n"
        "movl $0, (%esp)\n" /* line 3543 */
        "calll Scr_GetString\n"
        "movl %eax, %ebx\n" /* pszItemName */
        "movl %eax, (%esp)\n" /* line 3544 */
        "calll G_FindItem\n"
        "movl %eax, %esi\n" /* pItem */
        "testl %eax, %eax\n" /* line 3545 */
        "jne .Lf196fc4_00196ff4\n"
        ".Lf196fc4_0019705b:\n"
        "movl %ebx, 4(%esp)\n" /* line 3546 | pszItemName */
        "movl $str_002b17dc, (%esp)\n" /* "unknown item '%s'" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf196fc4_00196ff4\n"
    );
}

/* line 3558 */
unsigned int Scr_PrecacheShader(void)
{
    const char *shaderName;
    if (!((level_locals_t *)imp_level)->initializing)
        Scr_Error("PrecacheShader must be called before any wait statements in the gametype or level script");
    {
        int ptype = Scr_GetType(0);
        shaderName = Scr_GetString(0);
        Com_Printf("DBG PrecacheShader: '%s' type=%d\n", shaderName, ptype);
    }
    if (!shaderName[0])
        Scr_ParamError(0, "shader name can't be empty");
    G_ShaderIndex(shaderName);
    return 0;
}

/* line 3578 */
unsigned int Scr_PrecacheString(void)
{
    const char *s;
    if (!((level_locals_t *)imp_level)->initializing)
        Scr_Error("PrecacheString must be called before any wait statements in the gametype or level script");
    s = Scr_GetIString(0);
    if (s[0])
        G_LocalizedStringIndex(s);
    return 0;
}

/* line 3596 */
unsigned int Scr_PrecacheRumble(void)
{
    return 0;
}

/* line 3711 */
__attribute__((naked))
unsigned int GScr_RadiusDamage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3711 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        /* { scope 1 */
        "leal -0x14(%ebp), %esi\n" /* line 3718 | origin */
        "movl %esi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $1, (%esp)\n" /* line 3719 */
        "calll Scr_GetFloat\n"
        "fstps -0x20(%ebp)\n" /* range */
        "movl $2, (%esp)\n" /* line 3720 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n" /* max_damage */
        "movl $3, (%esp)\n" /* line 3721 */
        "calll Scr_GetFloat\n"
        "movl imp_level, %ebx\n" /* line 3723 */
        "movl 0x35f8(%ebx), %eax\n"
        "movl %eax, 0x35f4(%ebx)\n"
        "movl $0xe, 0x1c(%esp)\n" /* line 3724 */
        "movl $0, 0x18(%esp)\n"
        "movss -0x20(%ebp), %xmm0\n" /* range */
        "movss %xmm0, 0x14(%esp)\n"
        "fstps 0x10(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* max_damage */
        "movss %xmm0, 0xc(%esp)\n"
        "movl imp_g_entities, %eax\n"
        "addl $0x8bba0, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_RadiusDamage\n"
        "movl $0, 0x35f4(%ebx)\n" /* line 3725 */
        /* } scope */
        "addl $0x40, %esp\n" /* line 3726 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3734 */
unsigned int GScr_SetPlayerIgnoreRadiusDamage(void)
{
    *(int *)((byte *)(void *)imp_level + 0x35f8) = Scr_GetInt(0); /* TODO: level offset 0x35f8 - likely bPlayerIgnoreRadiusDamage or bPlayerIgnoreRadiusDamageLatched */
    return 0;
}

/* line 3747 */
__attribute__((naked))
unsigned int GScr_GetMoveDelta(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3747 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 3758 */
        "cmpl $1, %eax\n"
        "je .Lf1971ea_001972e2\n"
        "cmpl $2, %eax\n"
        "je .Lf1971ea_001972fa\n"
        "movl $2, (%esp)\n" /* line 3761 */
        "calll Scr_GetFloat\n"
        "fstps -0x2c(%ebp)\n" /* endTime */
        "movss -0x2c(%ebp), %xmm0\n" /* line 3762 | endTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1971ea_00197228\n"
        "jb .Lf1971ea_00197231\n"
        ".Lf1971ea_00197228:\n"
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf1971ea_00197245\n"
        ".Lf1971ea_00197231:\n"
        "movl $str_002b18c4, 4(%esp)\n" /* line 3763 */
        "movl $2, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf1971ea_00197245:\n"
        "movl $1, (%esp)\n" /* line 3767 */
        "calll Scr_GetFloat\n"
        "fstps -0x30(%ebp)\n" /* startTime */
        "movss -0x30(%ebp), %xmm0\n" /* line 3768 | startTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1971ea_00197264\n"
        "jb .Lf1971ea_0019726d\n"
        ".Lf1971ea_00197264:\n"
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf1971ea_00197281\n"
        ".Lf1971ea_0019726d:\n"
        "movl $str_002b18e8, 4(%esp)\n" /* line 3769 */
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf1971ea_00197281:\n"
        "movl $0, 4(%esp)\n" /* line 3773 */
        "movl $0, (%esp)\n"
        "calll Scr_GetAnim\n"
        "movzwl %ax, %esi\n" /* line 3777 */
        "shrl $0x10, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_GetAnims\n"
        "movss -0x2c(%ebp), %xmm0\n" /* endTime */
        "movss %xmm0, 0x14(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* startTime */
        "movss %xmm0, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %ebx\n" /* trans */
        "movl %ebx, 0xc(%esp)\n"
        "leal -0x10(%ebp), %edx\n" /* rot */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetRelDelta\n"
        "movl %ebx, (%esp)\n" /* line 3778 */
        "calll Scr_AddVector\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 3779 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1971ea_001972e2:\n"
        "pxor %xmm0, %xmm0\n" /* line 3758 */
        "movss %xmm0, -0x30(%ebp)\n" /* startTime */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x2c(%ebp)\n" /* endTime */
        "jmp .Lf1971ea_00197281\n"
        ".Lf1971ea_001972fa:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x2c(%ebp)\n" /* endTime */
        "jmp .Lf1971ea_00197245\n"
    );
}

/* line 3787 */
__attribute__((naked))
unsigned int GScr_GetAngleDelta(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3787 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 3798 */
        "cmpl $1, %eax\n"
        "je .Lf19730c_0019740c\n"
        "cmpl $2, %eax\n"
        "je .Lf19730c_00197427\n"
        "movl $2, (%esp)\n" /* line 3801 */
        "calll Scr_GetFloat\n"
        "fstps -0x2c(%ebp)\n" /* endTime */
        "movss -0x2c(%ebp), %xmm0\n" /* line 3802 | endTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf19730c_0019734a\n"
        "jb .Lf19730c_00197353\n"
        ".Lf19730c_0019734a:\n"
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf19730c_00197367\n"
        ".Lf19730c_00197353:\n"
        "movl $str_002b18c4, 4(%esp)\n" /* line 3803 */
        "movl $2, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf19730c_00197367:\n"
        "movl $1, (%esp)\n" /* line 3807 */
        "calll Scr_GetFloat\n"
        "fstps -0x30(%ebp)\n" /* startTime */
        "movss -0x30(%ebp), %xmm0\n" /* line 3808 | startTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf19730c_00197386\n"
        "jb .Lf19730c_0019738f\n"
        ".Lf19730c_00197386:\n"
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf19730c_001973a3\n"
        ".Lf19730c_0019738f:\n"
        "movl $str_002b18e8, 4(%esp)\n" /* line 3809 */
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf19730c_001973a3:\n"
        "movl $0, 4(%esp)\n" /* line 3813 */
        "movl $0, (%esp)\n"
        "calll Scr_GetAnim\n"
        "movzwl %ax, %esi\n" /* line 3817 */
        "shrl $0x10, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_GetAnims\n"
        "movss -0x2c(%ebp), %xmm0\n" /* endTime */
        "movss %xmm0, 0x14(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* startTime */
        "movss %xmm0, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* trans */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x10(%ebp), %ebx\n" /* rot */
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetRelDelta\n"
        "movl %ebx, (%esp)\n" /* line 3818 */
        "calll RotationToYaw\n"
        "fstps (%esp)\n"
        "calll Scr_AddFloat\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 3819 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19730c_0019740c:\n"
        "pxor %xmm0, %xmm0\n" /* line 3798 */
        "movss %xmm0, -0x30(%ebp)\n" /* startTime */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x2c(%ebp)\n" /* endTime */
        "jmp .Lf19730c_001973a3\n"
        ".Lf19730c_00197427:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x2c(%ebp)\n" /* endTime */
        "jmp .Lf19730c_00197367\n"
    );
}

/* line 3827 */
unsigned int GScr_GetNorthYaw(void)
{
    char northYawString[32];
    SV_GetConfigstring(11, northYawString, 32);
    Scr_AddFloat((float)atof(northYawString));
    return 0;
}

/* line 3839 */
unsigned int Scr_LoadFX(void)
{
    int id;
    id = G_EffectIndex(Scr_GetString(0));
    if (!id && !((level_locals_t *)imp_level)->initializing)
        Scr_Error("loadfx must be called before any wait statements in the gametype or level script");
    Scr_AddInt(id);
    return 0;
}

/* line 3941 */
__attribute__((naked))
unsigned int Scr_PlayFXOnTag(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3941 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 3951 */
        "cmpl $3, %eax\n"
        "je .Lf1974d2_001974f1\n"
        "movl $str_002b1980, (%esp)\n" /* line 3952 */
        "calll Scr_Error\n"
        ".Lf1974d2_001974f1:\n"
        "movl $0, (%esp)\n" /* line 3954 */
        "calll Scr_GetInt\n"
        "movl %eax, %edi\n" /* fxId */
        "leal -1(%eax), %eax\n" /* line 3955 */
        "cmpl $0x3e, %eax\n"
        "ja .Lf1974d2_001975d8\n"
        "movl $1, (%esp)\n" /* line 3958 */
        "calll Scr_GetEntity\n"
        "movl %eax, %esi\n" /* ent */
        "cmpb $0, 0x164(%eax)\n" /* line 3959 */
        "je .Lf1974d2_00197613\n"
        ".Lf1974d2_00197526:\n"
        "movl $2, (%esp)\n" /* line 3962 */
        "calll Scr_GetConstLowercaseString\n"
        "movl %eax, %ebx\n" /* tag */
        "movl %eax, (%esp)\n" /* line 3963 */
        "calll SL_ConvertToString\n"
        "movl $0x22, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf1974d2_00197564\n"
        "movl $str_002b1a04, 4(%esp)\n" /* line 3964 */
        "movl $2, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf1974d2_00197564:\n"
        "movl %ebx, 4(%esp)\n" /* line 3966 | tag */
        "movl %esi, (%esp)\n" /* ent */
        "calll SV_DObjGetBoneIndex\n"
        "testl %eax, %eax\n"
        "js .Lf1974d2_0019762c\n"
        ".Lf1974d2_00197578:\n"
        "movl %ebx, (%esp)\n" /* line 3972 | tag */
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* fxId */
        "movl $str_002b1a60, (%esp)\n" /* "%02d%s" */
        "calll va\n"
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0x100, 8(%esp)\n"
        "movl $0x38e, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll G_FindConfigstringIndex\n"
        "movl %eax, 8(%esp)\n" /* line 3974 */
        "movl $0xc3, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_AddEvent\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3975 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1974d2_001975d8:\n"
        "movl %edi, 4(%esp)\n" /* line 3956 | fxId */
        "movl $str_002b19c0, (%esp)\n" /* "effect id %i is invalid
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "movl $1, (%esp)\n" /* line 3958 */
        "calll Scr_GetEntity\n"
        "movl %eax, %esi\n" /* ent */
        "cmpb $0, 0x164(%eax)\n" /* line 3959 */
        "jne .Lf1974d2_00197526\n"
        ".Lf1974d2_00197613:\n"
        "movl $str_002b19dc, 4(%esp)\n" /* line 3960 */
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1974d2_00197526\n"
        ".Lf1974d2_0019762c:\n"
        "movl %esi, (%esp)\n" /* line 3968 | ent */
        "calll SV_DObjDumpInfo\n"
        "movzbl 0x164(%esi), %eax\n" /* line 3969 | ent */
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* tag */
        "movl $str_002b1a2c, (%esp)\n" /* "tag '%s' does not exist on entity with model '%s'" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1974d2_00197578\n"
    );
}

/* line 4052 */
__attribute__((naked))
unsigned int Scr_SetFog(float fNear, float fFar, float fDensity, float fRed, float fGreen, float fBlue, float fTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4052 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x64, %esp\n"
        "movl %eax, %ebx\n" /* cmd */
        "movss %xmm0, -0xc(%ebp)\n"
        "movss %xmm1, -0x10(%ebp)\n"
        "movss %xmm2, -0x14(%ebp)\n"
        "movss %xmm3, -0x18(%ebp)\n"
        "movss 8(%ebp), %xmm0\n" /* fGreen */
        "movss %xmm0, -0x1c(%ebp)\n" /* fGreen */
        "movss 0xc(%ebp), %xmm1\n" /* fBlue */
        "movss %xmm1, -0x20(%ebp)\n" /* fBlue */
        "movss 0x10(%ebp), %xmm0\n" /* fTime */
        "movss %xmm0, -0x24(%ebp)\n" /* fTime */
        "movss -0xc(%ebp), %xmm1\n" /* line 4054 */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "jb .Lf19766c_001977c5\n"
        ".Lf19766c_001976b9:\n"
        "movaps %xmm1, %xmm0\n"
        ".Lf19766c_001976bc:\n"
        "ucomiss -0x10(%ebp), %xmm0\n" /* line 4056 */
        "jae .Lf19766c_00197780\n"
        ".Lf19766c_001976c6:\n"
        "pxor %xmm1, %xmm1\n" /* line 4058 */
        "ucomiss -0x18(%ebp), %xmm1\n"
        "ja .Lf19766c_001976e6\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x18(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf19766c_001977ed\n"
        ".Lf19766c_001976e6:\n"
        "movl %ebx, 4(%esp)\n" /* line 4059 | cmd */
        "movl $str_002b1abc, (%esp)\n" /* "%s: red/green/blue color components must be in the range [0," */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf19766c_001976fe:\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 4060 | fTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jb .Lf19766c_0019779d\n"
        ".Lf19766c_00197710:\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf19766c_00197713:\n"
        "mulss lit4_002ed5c8, %xmm1\n" /* line 4063 | 1000.0f */
        "cvtss2sd %xmm1, %xmm0\n"
        "movsd %xmm0, 0x34(%esp)\n"
        "cvtss2sd -0x20(%ebp), %xmm1\n" /* fBlue */
        "movsd %xmm1, 0x2c(%esp)\n"
        "cvtss2sd -0x1c(%ebp), %xmm0\n" /* fGreen */
        "movsd %xmm0, 0x24(%esp)\n"
        "cvtss2sd -0x18(%ebp), %xmm1\n"
        "movsd %xmm1, 0x1c(%esp)\n"
        "cvtss2sd -0x14(%ebp), %xmm0\n"
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd -0x10(%ebp), %xmm1\n"
        "movsd %xmm1, 0xc(%esp)\n"
        "cvtss2sd -0xc(%ebp), %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b1b28, (%esp)\n" /* "%g %g %g %g %g %g %.0f" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* fGreen */
        "addl $0x64, %esp\n" /* line 4064 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp G_setfog\n" /* line 4063 */
        ".Lf19766c_00197780:\n"
        "movl %ebx, 4(%esp)\n" /* line 4057 | cmd */
        "movl $str_002b1a88, (%esp)\n" /* "%s: near distance must be less than far distance" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf19766c_001976c6\n"
        ".Lf19766c_0019779d:\n"
        "jp .Lf19766c_00197710\n" /* line 4060 */
        "movl %ebx, 4(%esp)\n" /* line 4061 | cmd */
        "movl $str_002b1afc, (%esp)\n" /* "%s: transition time must be >= 0 seconds" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movss -0x24(%ebp), %xmm1\n" /* fTime */
        "jmp .Lf19766c_00197713\n"
        ".Lf19766c_001977c5:\n"
        "jp .Lf19766c_001976b9\n" /* line 4054 */
        "movl %eax, 4(%esp)\n" /* line 4055 */
        "movl $str_002b1a68, (%esp)\n" /* "%s: near distance must be >= 0" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movss -0xc(%ebp), %xmm0\n"
        "jmp .Lf19766c_001976bc\n"
        ".Lf19766c_001977ed:\n"
        "pxor %xmm1, %xmm1\n" /* line 4058 */
        "ucomiss -0x1c(%ebp), %xmm1\n" /* fGreen */
        "ja .Lf19766c_001976e6\n"
        "movss -0x1c(%ebp), %xmm1\n" /* fGreen */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf19766c_001976e6\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss -0x20(%ebp), %xmm1\n" /* fBlue */
        "ja .Lf19766c_001976e6\n"
        "movss -0x20(%ebp), %xmm1\n" /* fBlue */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf19766c_001976e6\n"
        "jmp .Lf19766c_001976fe\n"
    );
}

/* line 4067 */
__attribute__((naked))
unsigned int Scr_SetLinearFog(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4067 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 4076 */
        "cmpl $6, %eax\n"
        "je .Lf19782a_00197846\n"
        "movl $str_002b1b40, (%esp)\n" /* line 4077 */
        "calll Scr_Error\n"
        ".Lf19782a_00197846:\n"
        "movl $0, (%esp)\n" /* line 4079 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n" /* fNear */
        "movl $1, (%esp)\n" /* line 4080 */
        "calll Scr_GetFloat\n"
        "fstps -0x18(%ebp)\n" /* fFar */
        "movl $2, (%esp)\n" /* line 4081 */
        "calll Scr_GetFloat\n"
        "fstps -0x14(%ebp)\n" /* fRed */
        "movl $3, (%esp)\n" /* line 4082 */
        "calll Scr_GetFloat\n"
        "fstps -0x10(%ebp)\n" /* fGreen */
        "movl $4, (%esp)\n" /* line 4083 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* fBlue */
        "movl $5, (%esp)\n" /* line 4084 */
        "calll Scr_GetFloat\n"
        "fstps 8(%esp)\n" /* line 4086 */
        "movss -0xc(%ebp), %xmm0\n" /* fBlue */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x10(%ebp), %xmm0\n" /* fGreen */
        "movss %xmm0, (%esp)\n"
        "movss -0x14(%ebp), %xmm3\n" /* fRed */
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movss -0x18(%ebp), %xmm1\n" /* fFar */
        "movss -0x1c(%ebp), %xmm0\n" /* fNear */
        "movl $str_002b1b94, %eax\n" /* "setCullFog" */
        "calll Scr_SetFog\n"
        /* } scope */
        "leave\n" /* line 4087 */
        "retl\n"
    );
}

/* line 4090 */
__attribute__((naked))
unsigned int Scr_SetExponentialFog(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4090 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 4098 */
        "cmpl $5, %eax\n"
        "je .Lf1978da_001978f6\n"
        "movl $str_002b1ba0, (%esp)\n" /* line 4100 */
        "calll Scr_Error\n"
        ".Lf1978da_001978f6:\n"
        "movl $0, (%esp)\n" /* line 4103 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n" /* fDensity */
        "movl $1, (%esp)\n" /* line 4104 */
        "calll Scr_GetFloat\n"
        "fstps -0x18(%ebp)\n" /* fRed */
        "movl $2, (%esp)\n" /* line 4105 */
        "calll Scr_GetFloat\n"
        "fstps -0x14(%ebp)\n" /* fGreen */
        "movl $3, (%esp)\n" /* line 4106 */
        "calll Scr_GetFloat\n"
        "fstps -0x10(%ebp)\n" /* fBlue */
        "movl $4, (%esp)\n" /* line 4107 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* fTime */
        "movss -0x1c(%ebp), %xmm0\n" /* line 4109 | fDensity */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1978da_00197951\n"
        "jbe .Lf1978da_0019795a\n"
        ".Lf1978da_00197951:\n"
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "jb .Lf1978da_00197966\n"
        ".Lf1978da_0019795a:\n"
        "movl $str_002b1cb4, (%esp)\n" /* line 4110 */
        "calll Scr_Error\n"
        ".Lf1978da_00197966:\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 4112 | fTime */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x10(%ebp), %xmm0\n" /* fBlue */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x14(%ebp), %xmm0\n" /* fGreen */
        "movss %xmm0, (%esp)\n"
        "movss -0x18(%ebp), %xmm3\n" /* fRed */
        "movss -0x1c(%ebp), %xmm2\n" /* fDensity */
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "pxor %xmm0, %xmm0\n"
        "movl $str_002b1cf0, %eax\n" /* "setExpFog" */
        "calll Scr_SetFog\n"
        /* } scope */
        "leave\n" /* line 4113 */
        "retl\n"
    );
}

/* line 4123 */
__attribute__((naked))
unsigned int GScr_IsPlayer(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4123 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4127 */
        "calll Scr_GetType\n"
        "subl $1, %eax\n"
        "je .Lf1979a8_001979cd\n"
        ".Lf1979a8_001979bf:\n"
        "movl $0, (%esp)\n" /* line 4138 */
        "calll Scr_AddInt\n"
        /* } scope */
        "leave\n" /* line 4139 */
        "retl\n"
        /* { scope 1 */
        ".Lf1979a8_001979cd:\n"
        "movl $0, (%esp)\n" /* line 4127 */
        "calll Scr_GetPointerType\n"
        "cmpl $0x15, %eax\n"
        "jne .Lf1979a8_001979bf\n"
        "movl $0, (%esp)\n" /* line 4129 */
        "calll Scr_GetEntity\n"
        "movl 0x158(%eax), %eax\n" /* line 4131 */
        "testl %eax, %eax\n"
        "je .Lf1979a8_001979bf\n"
        "movl $1, (%esp)\n" /* line 4133 */
        "calll Scr_AddInt\n"
        /* } scope */
        "leave\n" /* line 4139 */
        "retl\n"
    );
}

/* line 4149 */
unsigned int GScr_IsPlayerNumber(void)
{
    int num = Scr_GetInt(0);
    if ((unsigned int)num > 0x3f)
        Scr_AddInt(0);
    else
        Scr_AddInt(1);
    return 0;
}

/* line 4165 */
__attribute__((naked))
unsigned int GScr_SetWinningPlayer(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4165 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x410, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4172 */
        "calll Scr_GetEntity\n"
        "movl (%eax), %ebx\n" /* line 4173 | iWinner */
        "addl $1, %ebx\n" /* iWinner */
        "movl $0x400, 8(%esp)\n" /* line 4175 */
        "leal -0x408(%ebp), %esi\n" /* cs */
        "movl %esi, 4(%esp)\n"
        "movl $0x16, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl %ebx, 4(%esp)\n" /* line 4178 | iWinner */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, %ebx\n" /* iWinner */
        "movl $str_002b1cfc, 4(%esp)\n" /* line 4179 */
        "movl %esi, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %ebx, 4(%esp)\n" /* iWinner */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf197a36_00197ac6\n"
        "movl %ebx, 8(%esp)\n" /* line 4181 | iWinner */
        "movl $str_002b1cfc, 4(%esp)\n" /* "winner" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl %esi, 4(%esp)\n" /* line 4182 */
        "movl $0x16, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        ".Lf197a36_00197ac6:\n"
        "addl $0x410, %esp\n" /* line 4183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4191 */
__attribute__((naked))
unsigned int GScr_SetWinningTeam(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4191 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x410, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4198 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 4200 */
        "cmpw 2(%edx), %ax\n"
        "je .Lf197ad0_00197bc6\n"
        "cmpw 4(%edx), %ax\n" /* line 4202 */
        "je .Lf197ad0_00197bbc\n"
        "cmpw 0x74(%edx), %ax\n" /* line 4204 */
        "je .Lf197ad0_00197b3c\n"
        "movzwl %ax, %eax\n" /* line 4208 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b1380, (%esp)\n" /* "Illegal team string '%s'. Must be allies, axis, or none." */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        /* } scope */
        ".Lf197ad0_00197b32:\n"
        "addl $0x410, %esp\n" /* line 4220 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf197ad0_00197b3c:\n"
        "xorl %ebx, %ebx\n" /* line 4204 | iWinner */
        ".Lf197ad0_00197b3e:\n"
        "movl $0x400, 8(%esp)\n" /* line 4212 */
        "leal -0x408(%ebp), %esi\n" /* cs */
        "movl %esi, 4(%esp)\n"
        "movl $0x16, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl %ebx, 4(%esp)\n" /* line 4215 | iWinner */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, %ebx\n" /* iWinner */
        "movl $str_002b1cfc, 4(%esp)\n" /* line 4216 */
        "movl %esi, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %ebx, 4(%esp)\n" /* iWinner */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf197ad0_00197b32\n"
        "movl %ebx, 8(%esp)\n" /* line 4218 | iWinner */
        "movl $str_002b1cfc, 4(%esp)\n" /* "winner" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl %esi, 4(%esp)\n" /* line 4219 */
        "movl $0x16, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "addl $0x410, %esp\n" /* line 4220 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf197ad0_00197bbc:\n"
        "movl $0xffffffff, %ebx\n" /* line 4202 | iWinner */
        "jmp .Lf197ad0_00197b3e\n"
        ".Lf197ad0_00197bc6:\n"
        "movl $0xfffffffe, %ebx\n" /* line 4209 | iWinner */
        "jmp .Lf197ad0_00197b3e\n"
    );
}

/* line 4258 */
__attribute__((naked))
unsigned int GScr_GetTeamScore(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4258 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4263 */
        "calll Scr_GetConstString\n"
        "movl %eax, %ebx\n" /* team */
        "movl imp_scr_const, %esi\n" /* line 4265 */
        "cmpw 2(%esi), %ax\n"
        "je .Lf197bd0_00197c3b\n"
        "cmpw 4(%esi), %ax\n"
        "je .Lf197bd0_00197c21\n"
        "movzwl %ax, %eax\n" /* line 4267 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b1d04, (%esp)\n" /* "Illegal team string '%s'. Must be allies, or axis." */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "cmpw 2(%esi), %bx\n" /* line 4270 | team */
        "je .Lf197bd0_00197c3b\n"
        ".Lf197bd0_00197c21:\n"
        "movl imp_level, %eax\n" /* line 4273 */
        "movl 0x200(%eax), %eax\n"
        "movl %eax, (%esp)\n" /* line 4275 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 4276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf197bd0_00197c3b:\n"
        "movl imp_level, %eax\n" /* line 4271 */
        "movl 0x204(%eax), %eax\n"
        "movl %eax, (%esp)\n" /* line 4275 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 4276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4284 */
__attribute__((naked))
unsigned int GScr_SetTeamScore(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4284 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4289 */
        "calll Scr_GetConstString\n"
        "movl %eax, %ebx\n" /* team */
        "movl imp_scr_const, %eax\n" /* line 4291 */
        "cmpw 2(%eax), %bx\n" /* team */
        "je .Lf197c56_00197c9f\n"
        "cmpw 4(%eax), %bx\n" /* team */
        "je .Lf197c56_00197c9f\n"
        "movzwl %bx, %eax\n" /* line 4293 | team */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b1d04, (%esp)\n" /* "Illegal team string '%s'. Must be allies, or axis." */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf197c56_00197c9f:\n"
        "movl $1, (%esp)\n" /* line 4296 */
        "calll Scr_GetInt\n"
        "movl %eax, %edx\n"
        "movl imp_scr_const, %eax\n" /* line 4298 */
        "cmpw 2(%eax), %bx\n" /* team */
        "je .Lf197c56_00197d08\n"
        "movl imp_level, %eax\n" /* line 4306 */
        "movl %edx, 0x200(%eax)\n"
        "movl %edx, 8(%esp)\n" /* line 4308 */
        "movl $0x47, 4(%esp)\n"
        ".Lf197c56_00197ccf:\n"
        "movl $str_002b1d38, (%esp)\n" /* "%c %i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl imp_level, %eax\n" /* line 4311 */
        "movl $1, 0x210(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 4312 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf197c56_00197d08:\n"
        "movl imp_level, %eax\n" /* line 4300 */
        "movl %edx, 0x204(%eax)\n"
        "movl %edx, 8(%esp)\n" /* line 4302 */
        "movl $0x48, 4(%esp)\n"
        "jmp .Lf197c56_00197ccf\n"
    );
}

/* line 4320 */
__attribute__((naked))
unsigned int GScr_SetClientNameMode(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4320 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4322 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 4324 */
        "cmpw 0x78(%edx), %ax\n"
        "je .Lf197d22_00197d65\n"
        "cmpw 0x7a(%edx), %ax\n" /* line 4326 */
        "je .Lf197d22_00197d54\n"
        "movl $str_002b1d40, (%esp)\n" /* line 4329 */
        "calll Scr_Error\n"
        /* } scope */
        "leave\n" /* line 4330 */
        "retl\n"
        /* { scope 1 */
        ".Lf197d22_00197d54:\n"
        "movl imp_level, %eax\n" /* line 4327 */
        "movl $1, 0x214(%eax)\n"
        /* } scope */
        "leave\n" /* line 4330 */
        "retl\n"
        /* { scope 1 */
        ".Lf197d22_00197d65:\n"
        "movl imp_level, %eax\n" /* line 4325 */
        "movl $0, 0x214(%eax)\n"
        /* } scope */
        "leave\n" /* line 4330 */
        "retl\n"
    );
}

/* line 4338 */
__attribute__((naked))
unsigned int GScr_UpdateClientNames(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4338 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl imp_level, %edi\n" /* line 4344 */
        "movl 0x214(%edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf197d76_00197e38\n"
        ".Lf197d76_00197d93:\n"
        "movl (%edi), %ebx\n" /* line 4347 | cl */
        "movl 0x1e4(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf197d76_00197e30\n"
        "xorl %esi, %esi\n" /* i */
        "movl %edi, -0x40(%ebp)\n"
        "jmp .Lf197d76_00197dbe\n"
        ".Lf197d76_00197daa:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x28a4, %ebx\n" /* cl */
        "movl -0x40(%ebp), %eax\n"
        "cmpl 0x1e4(%eax), %esi\n" /* i */
        "jge .Lf197d76_00197e30\n"
        ".Lf197d76_00197dbe:\n"
        "cmpl $2, 0x26c4(%ebx)\n" /* line 4349 | cl */
        "jne .Lf197d76_00197daa\n"
        "leal 0x2708(%ebx), %eax\n" /* line 4352 | cl */
        "movl %eax, -0x3c(%ebp)\n"
        "leal 0x2784(%ebx), %edi\n" /* cl */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf197d76_00197daa\n"
        "movl $0x20, 8(%esp)\n" /* line 4355 */
        "movl %edi, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* oldname */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x20, 8(%esp)\n" /* line 4356 */
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %esi, (%esp)\n" /* line 4358 | i */
        "calll ClientUserinfoChanged\n"
        "addl $1, %esi\n" /* line 4347 | i */
        "addl $0x28a4, %ebx\n" /* cl */
        "movl -0x40(%ebp), %eax\n"
        "cmpl 0x1e4(%eax), %esi\n" /* i */
        "jl .Lf197d76_00197dbe\n"
        /* } scope */
        ".Lf197d76_00197e30:\n"
        "addl $0x4c, %esp\n" /* line 4360 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf197d76_00197e38:\n"
        "movl $str_002b1d50, (%esp)\n" /* line 4345 */
        "calll Scr_Error\n"
        "jmp .Lf197d76_00197d93\n"
    );
}

/* line 4368 */
__attribute__((naked))
unsigned int GScr_GetTeamPlayersAlive(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4368 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4376 */
        "calll Scr_GetConstString\n"
        "movl %eax, %ebx\n" /* team */
        "movl imp_scr_const, %esi\n" /* line 4378 | iLivePlayers */
        "cmpw 2(%esi), %ax\n" /* iLivePlayers */
        "je .Lf197e4a_00197f03\n"
        "cmpw 4(%esi), %ax\n" /* iLivePlayers */
        "je .Lf197e4a_00197ea0\n"
        "movzwl %ax, %eax\n" /* line 4380 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b1d04, (%esp)\n" /* "Illegal team string '%s'. Must be allies, or axis." */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "cmpw 2(%esi), %bx\n" /* line 4383 | iLivePlayers, team */
        "je .Lf197e4a_00197f03\n"
        ".Lf197e4a_00197ea0:\n"
        "movl $1, %edi\n" /* iTeamNum */
        ".Lf197e4a_00197ea5:\n"
        "movl imp_g_maxclients, %eax\n" /* line 4389 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* team */
        "testl %ebx, %ebx\n" /* team */
        "jg .Lf197e4a_00197ec5\n"
        "xorl %esi, %esi\n" /* iLivePlayers */
        ".Lf197e4a_00197eb5:\n"
        "movl %esi, (%esp)\n" /* line 4399 | iLivePlayers */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 4400 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf197e4a_00197ec5:\n"
        "xorl %ecx, %ecx\n" /* line 4389 */
        "xorl %esi, %esi\n" /* iLivePlayers */
        "movl imp_g_entities, %edx\n"
        "addl $0xfc, %edx\n"
        "jmp .Lf197e4a_00197ee4\n"
        ".Lf197e4a_00197ed7:\n"
        "addl $1, %ecx\n"
        "addl $0x230, %edx\n"
        "cmpl %ebx, %ecx\n" /* team */
        "je .Lf197e4a_00197eb5\n"
        ".Lf197e4a_00197ee4:\n"
        "cmpb $0, (%edx)\n" /* line 4392 */
        "je .Lf197e4a_00197ed7\n"
        "movl 0x5c(%edx), %eax\n" /* line 4394 */
        "cmpl 0x274c(%eax), %edi\n" /* iTeamNum */
        "jne .Lf197e4a_00197ed7\n"
        "leal 1(%esi), %eax\n" /* line 4395 | iLivePlayers */
        "cmpl $1, 0x98(%edx)\n"
        "cmovgel %eax, %esi\n" /* iLivePlayers */
        "jmp .Lf197e4a_00197ed7\n"
        ".Lf197e4a_00197f03:\n"
        "movl $2, %edi\n" /* line 4383 | iTeamNum */
        "jmp .Lf197e4a_00197ea5\n"
    );
}

/* line 4408 */
unsigned int GScr_GetNumParts(void)
{
    Scr_AddInt(XModelNumBones(SV_XModelGet(Scr_GetString(0))));
    return 0;
}

/* line 4422 */
__attribute__((naked))
unsigned int GScr_GetPartName(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4422 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4429 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n"
        "calll SV_XModelGet\n"
        "movl %eax, %esi\n" /* model */
        "movl $1, (%esp)\n" /* line 4430 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* name */
        "movl %esi, (%esp)\n" /* line 4431 | model */
        "calll XModelNumBones\n"
        "cmpl %eax, %ebx\n" /* line 4432 | name */
        "jae .Lf197f36_00197fa5\n"
        ".Lf197f36_00197f6e:\n"
        "movl %esi, (%esp)\n" /* line 4434 | model */
        "calll XModelBoneNames\n"
        "movzwl (%eax, %ebx, 2), %ebx\n" /* name */
        "testw %bx, %bx\n" /* line 4435 | name */
        "jne .Lf197f36_00197f93\n"
        "movl $str_002b1d90, 4(%esp)\n" /* line 4436 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf197f36_00197f93:\n"
        "movzwl %bx, %eax\n" /* line 4437 | name */
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 4438 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf197f36_00197fa5:\n"
        "subl $1, %eax\n" /* line 4433 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b1d74, (%esp)\n" /* "index out of range (0 - %d)" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf197f36_00197f6e\n"
    );
}

/* line 4446 */
__attribute__((naked))
unsigned int GScr_Earthquake(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4446 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4454 */
        "calll Scr_GetFloat\n"
        "fstps -0x20(%ebp)\n" /* scale */
        "movl $1, (%esp)\n" /* line 4455 */
        "calll Scr_GetFloat\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x24(%ebp)\n"
        "cvttss2si -0x24(%ebp), %ebx\n"
        "leal -0x14(%ebp), %esi\n" /* line 4456 | source */
        "movl %esi, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $3, (%esp)\n" /* line 4457 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n" /* radius */
        "movss -0x20(%ebp), %xmm0\n" /* line 4459 | scale */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf197fca_00198099\n"
        ".Lf197fca_00198047:\n"
        "testl %ebx, %ebx\n" /* line 4462 | duration */
        "jle .Lf197fca_001980b3\n"
        ".Lf197fca_0019804b:\n"
        "pxor %xmm0, %xmm0\n" /* line 4465 */
        "ucomiss -0x1c(%ebp), %xmm0\n" /* radius */
        "jae .Lf197fca_00198083\n"
        ".Lf197fca_00198055:\n"
        "movl $0xc4, 4(%esp)\n" /* line 4468 */
        "movl %esi, (%esp)\n"
        "calll G_TempEntity\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 4470 | scale */
        "movss %xmm0, 0x68(%eax)\n"
        "movl %ebx, 0x54(%eax)\n" /* line 4471 | duration */
        "movss -0x1c(%ebp), %xmm0\n" /* line 4472 | radius */
        "movss %xmm0, 0x6c(%eax)\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 4473 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf197fca_00198083:\n"
        "movl $str_002b1ddc, 4(%esp)\n" /* line 4466 */
        "movl $3, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf197fca_00198055\n"
        ".Lf197fca_00198099:\n"
        "jp .Lf197fca_00198047\n" /* line 4459 */
        "movl $str_002b1d9c, 4(%esp)\n" /* line 4460 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "testl %ebx, %ebx\n" /* line 4462 | duration */
        "jg .Lf197fca_0019804b\n"
        ".Lf197fca_001980b3:\n"
        "movl $str_002b1dbc, 4(%esp)\n" /* line 4463 */
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf197fca_0019804b\n"
    );
}

/* line 4744 */
__attribute__((naked))
unsigned int GScr_MapRestart(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4744 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_level, %ebx\n" /* line 4746 */
        "movl 0x35f0(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1980ca_001980f9\n"
        "movl $str_002b1dfc, %eax\n" /* line 4747 */
        "subl $1, %edx\n"
        "movl $str_002b1e18, %edx\n" /* "exitlevel already called" */
        "cmovnel %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf1980ca_001980f9:\n"
        "movl $1, 0x35f0(%ebx)\n" /* line 4748 */
        "movl $0, 0x1d54(%ebx)\n" /* line 4750 */
        "calll Scr_GetNumParam\n" /* line 4751 */
        "testl %eax, %eax\n"
        "je .Lf1980ca_00198128\n"
        "movl $0, (%esp)\n" /* line 4752 */
        "calll Scr_GetInt\n"
        "movl %eax, 0x1d54(%ebx)\n"
        ".Lf1980ca_00198128:\n"
        "movl $str_002b1e34, 4(%esp)\n" /* line 4754 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "addl $0x14, %esp\n" /* line 4755 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4762 */
__attribute__((naked))
unsigned int GScr_LoadMap(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4762 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 4766 */
        "testl %eax, %eax\n"
        "jne .Lf198142_0019815a\n"
        /* } scope */
        ".Lf198142_00198153:\n"
        "addl $0x10, %esp\n" /* line 4788 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198142_0019815a:\n"
        "movl $0, (%esp)\n" /* line 4772 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* mapname */
        "movl %eax, (%esp)\n" /* line 4773 */
        "calll SV_MapExists\n"
        "testl %eax, %eax\n"
        "je .Lf198142_00198153\n"
        "movl imp_level, %ebx\n" /* line 4779 */
        "movl 0x35f0(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf198142_001981db\n"
        "movl $2, 0x35f0(%ebx)\n" /* line 4781 */
        "movl $0, 0x1d54(%ebx)\n" /* line 4783 */
        "calll Scr_GetNumParam\n" /* line 4784 */
        "cmpl $1, %eax\n"
        "jbe .Lf198142_001981b4\n"
        ".Lf198142_001981a2:\n"
        "movl $1, (%esp)\n" /* line 4785 */
        "calll Scr_GetInt\n"
        "movl %eax, 0x1d54(%ebx)\n"
        ".Lf198142_001981b4:\n"
        "movl %esi, 4(%esp)\n" /* line 4787 | mapname */
        "movl $str_002ab5ac, (%esp)\n" /* "map %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 4788 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198142_001981db:\n"
        "movl $str_002b1e44, %eax\n" /* line 4780 */
        "cmpl $2, %edx\n"
        "movl $str_002b1e18, %edx\n" /* "exitlevel already called" */
        "cmovnel %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl $2, 0x35f0(%ebx)\n" /* line 4781 */
        "movl $0, 0x1d54(%ebx)\n" /* line 4783 */
        "calll Scr_GetNumParam\n" /* line 4784 */
        "cmpl $1, %eax\n"
        "ja .Lf198142_001981a2\n"
        "jmp .Lf198142_001981b4\n"
    );
}

/* line 4797 */
__attribute__((naked))
unsigned int GScr_ExitLevel(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4797 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_level, %ebx\n" /* line 4799 */
        "movl 0x35f0(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf198214_00198243\n"
        "movl $str_002b1dfc, %eax\n" /* line 4800 */
        "subl $1, %edx\n"
        "movl $str_002b1e18, %edx\n" /* "exitlevel already called" */
        "cmovnel %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf198214_00198243:\n"
        "movl $3, 0x35f0(%ebx)\n" /* line 4801 */
        "movl $0, 0x1d54(%ebx)\n" /* line 4803 */
        "calll Scr_GetNumParam\n" /* line 4804 */
        "testl %eax, %eax\n"
        "je .Lf198214_00198272\n"
        "movl $0, (%esp)\n" /* line 4805 */
        "calll Scr_GetInt\n"
        "movl %eax, 0x1d54(%ebx)\n"
        ".Lf198214_00198272:\n"
        "calll SV_MatchEnd\n" /* line 4807 */
        "addl $0x14, %esp\n" /* line 4809 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp ExitLevel\n" /* line 4808 */
    );
}

/* line 4817 */
unsigned int GScr_AddTestClient(void)
{
    void *ent = (void *)SV_AddTestClient();
    if (ent)
        Scr_AddEntity(ent);
    return 0;
}

/* line 4887 */
unsigned int GScr_AllClientsPrint(void)
{
    if (!Scr_GetNumParam())
        return 0;
    const char *msg = Scr_GetString(0);
    SV_GameSendServerCommand(-1, 0, va("%c \"%s\"", 0x65, msg));
    return 0;
}

/* line 4906 */
unsigned int GScr_MapExists(void)
{
    if (!Scr_GetNumParam())
        return 0;
    const char *name = Scr_GetString(0);
    if (SV_MapExists(name))
        Scr_AddInt(1);
    else
        Scr_AddInt(0);
    return 0;
}

/* line 4950 */
__attribute__((naked))
unsigned int GScr_SetVoteString(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4950 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 4954 */
        "testl %eax, %eax\n"
        "je .Lf198332_001983da\n"
        "movl $0, (%esp)\n" /* line 4957 */
        "calll Scr_GetString\n"
        "movl %eax, 4(%esp)\n" /* line 4959 */
        "movl $0x10, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl imp_level, %ebx\n" /* line 4960 */
        "movl 0xb1c(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xf, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 0xb24(%ebx), %eax\n" /* line 4961 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x11, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 0xb28(%ebx), %eax\n" /* line 4962 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x12, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        ".Lf198332_001983da:\n"
        "addl $0x14, %esp\n" /* line 4963 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4972 */
__attribute__((naked))
unsigned int GScr_SetVoteTime(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4972 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 4976 */
        "testl %eax, %eax\n"
        "je .Lf1983e0_0019846e\n"
        "movl $0, (%esp)\n" /* line 4979 */
        "calll Scr_GetInt\n"
        "movl %eax, 4(%esp)\n" /* line 4981 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xf, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl imp_level, %ebx\n" /* line 4983 */
        "movl 0xb24(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x11, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 0xb28(%ebx), %eax\n" /* line 4984 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x12, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        ".Lf1983e0_0019846e:\n"
        "addl $0x14, %esp\n" /* line 4985 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4994 */
__attribute__((naked))
unsigned int GScr_SetVoteYesCount(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4994 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 4998 */
        "testl %eax, %eax\n"
        "jne .Lf198474_00198485\n"
        /* } scope */
        "leave\n" /* line 5005 */
        "retl\n"
        /* { scope 1 */
        ".Lf198474_00198485:\n"
        "movl $0, (%esp)\n" /* line 5001 */
        "calll Scr_GetInt\n"
        "movl %eax, 4(%esp)\n" /* line 5003 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x11, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl imp_level, %eax\n" /* line 5004 */
        "movl 0xb28(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x12, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "leave\n" /* line 5005 */
        "retl\n"
    );
}

/* line 5014 */
__attribute__((naked))
unsigned int GScr_SetVoteNoCount(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5014 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 5018 */
        "testl %eax, %eax\n"
        "jne .Lf1984de_001984ef\n"
        /* } scope */
        "leave\n" /* line 5024 */
        "retl\n"
        /* { scope 1 */
        ".Lf1984de_001984ef:\n"
        "movl $0, (%esp)\n" /* line 5021 */
        "calll Scr_GetInt\n"
        "movl %eax, 4(%esp)\n" /* line 5023 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x12, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "leave\n" /* line 5024 */
        "retl\n"
    );
}

/* line 5033 */
__attribute__((naked))
unsigned int GScr_KickPlayer(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5033 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 5037 */
        "testl %eax, %eax\n"
        "jne .Lf19851e_0019852f\n"
        /* } scope */
        "leave\n" /* line 5043 */
        "retl\n"
        /* { scope 1 */
        ".Lf19851e_0019852f:\n"
        "movl $0, (%esp)\n" /* line 5040 */
        "calll Scr_GetInt\n"
        "movl %eax, 4(%esp)\n" /* line 5042 */
        "movl $str_002b1e58, (%esp)\n" /* "tempBanClient %i
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        /* } scope */
        "leave\n" /* line 5043 */
        "retl\n"
    );
}

/* line 5052 */
__attribute__((naked))
unsigned int GScr_BanPlayer(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5052 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 5056 */
        "testl %eax, %eax\n"
        "jne .Lf19855e_0019856f\n"
        /* } scope */
        "leave\n" /* line 5062 */
        "retl\n"
        /* { scope 1 */
        ".Lf19855e_0019856f:\n"
        "movl $0, (%esp)\n" /* line 5059 */
        "calll Scr_GetInt\n"
        "movl %eax, 4(%esp)\n" /* line 5061 */
        "movl $str_002b1e6c, (%esp)\n" /* "banClient %i
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        /* } scope */
        "leave\n" /* line 5062 */
        "retl\n"
    );
}

/* line 5071 */
__attribute__((naked))
unsigned int GScr_ClientPrint(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5071 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 5076 */
        "testl %eax, %eax\n"
        "je .Lf19859e_00198603\n"
        "movl $0, (%esp)\n" /* line 5079 */
        "calll Scr_GetEntity\n"
        "movl %eax, %ebx\n" /* ent */
        "movl $1, (%esp)\n" /* line 5080 */
        "calll Scr_GetString\n"
        "movl %eax, 8(%esp)\n" /* line 5082 */
        "movl $0x65, 4(%esp)\n"
        "movl $str_002a737c, (%esp)\n" /* "%c "%s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "subl imp_g_entities, %ebx\n" /* ent */
        "sarl $4, %ebx\n" /* ent */
        "imull $0x8af8af8b, %ebx, %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        ".Lf19859e_00198603:\n"
        "addl $0x14, %esp\n" /* line 5083 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5092 */
__attribute__((naked))
unsigned int GScr_OpenFile(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5092 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 5100 */
        "cmpl $1, %eax\n"
        "jbe .Lf19860a_0019866b\n"
        "movl $0, (%esp)\n" /* line 5103 */
        "calll Scr_GetString\n"
        "movl %eax, -0x50(%ebp)\n" /* filename */
        "movl $1, (%esp)\n" /* line 5104 */
        "calll Scr_GetString\n"
        "movl %eax, -0x4c(%ebp)\n" /* mode */
        "movl imp_level, %ebx\n" /* line 5108 */
        "movl 0x3608(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf19860a_00198673\n"
        "movl $1, 4(%esp)\n" /* line 5117 */
        "movl $str_002b1e7c, (%esp)\n" /* "OpenFile failed.  %i files already open
" */
        "calll Com_Printf\n"
        "movl $0xffffffff, (%esp)\n" /* line 5119 */
        "calll Scr_AddInt\n"
        /* } scope */
        ".Lf19860a_0019866b:\n"
        "addl $0x5c, %esp\n" /* line 5175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19860a_00198673:\n"
        "movl %eax, %esi\n" /* filesize */
        /* { scope 1 */
        "leal 0x3608(%ebx), %eax\n" /* line 5110 */
        "movl %eax, -0x2c(%ebp)\n" /* f */
        "movl $str_002b1ea8, -0x30(%ebp)\n" /* line 5123 */
        "movl $5, -0x34(%ebp)\n"
        "cld\n"
        "movl $str_002b1ea8, %edi\n" /* "read" */
        "movl $5, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* filesize */
        "movl $0, %edx\n"
        "je .Lf19860a_001986aa\n"
        "movzbl -1(%esi), %edx\n" /* filesize */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf19860a_001986aa:\n"
        "testl %edx, %edx\n"
        "jne .Lf19860a_00198759\n"
        "movl -0x50(%ebp), %eax\n" /* line 5128 | filename */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b1eb0, 4(%esp)\n" /* "scriptdata" */
        "movl $str_00216e18, (%esp)\n" /* "%s/%s" */
        "calll va\n"
        "movl $0, 8(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* tempFile */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %esi\n" /* filesize */
        "testl %eax, %eax\n" /* line 5129 */
        "js .Lf19860a_001987da\n"
        "leal 1(%eax), %eax\n" /* line 5135 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 0x360c(%ebx)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 5136 | tempFile */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* filesize */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "movl -0x1c(%ebp), %eax\n" /* line 5137 | tempFile */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl 0x360c(%ebx), %eax\n" /* line 5139 */
        "movb $0, (%eax, %esi)\n"
        "movl -0x50(%ebp), %edx\n" /* line 5141 | filename */
        "movl %edx, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "movl $1, (%esp)\n" /* line 5142 */
        "calll Com_SetCSV\n"
        "movl $0, 0x3610(%ebx)\n" /* line 5144 */
        "movl $0, (%esp)\n" /* line 5146 */
        "calll Scr_AddInt\n"
        "jmp .Lf19860a_0019866b\n"
        ".Lf19860a_00198759:\n"
        "movl $str_002b1ebc, -0x38(%ebp)\n" /* line 5149 */
        "movl $6, %ebx\n"
        "cld\n"
        "movl -0x4c(%ebp), %esi\n" /* mode, filesize */
        "movl $str_002b1ebc, %edi\n" /* "write" */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* filesize */
        "movl $0, %edx\n"
        "je .Lf19860a_00198783\n"
        "movzbl -1(%esi), %edx\n" /* filesize */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf19860a_00198783:\n"
        "testl %edx, %edx\n"
        "jne .Lf19860a_001987eb\n"
        "movl -0x50(%ebp), %eax\n" /* line 5152 | filename */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b1eb0, 4(%esp)\n" /* "scriptdata" */
        "movl $str_00216e18, (%esp)\n" /* "%s/%s" */
        "calll va\n"
        "movl $1, 8(%esp)\n"
        ".Lf19860a_001987aa:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 5162 | f */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "testl %eax, %eax\n" /* line 5163 */
        "js .Lf19860a_001987da\n"
        "movl $0, (%esp)\n" /* line 5166 */
        "calll Scr_AddInt\n"
        "jmp .Lf19860a_0019866b\n"
        ".Lf19860a_001987ce:\n"
        "movl $str_002b1ecc, (%esp)\n" /* line 5171 */
        "calll Com_Printf\n"
        ".Lf19860a_001987da:\n"
        "movl $0xffffffff, (%esp)\n" /* line 5172 */
        "calll Scr_AddInt\n"
        "jmp .Lf19860a_0019866b\n"
        ".Lf19860a_001987eb:\n"
        "movl $str_002b1ec4, -0x3c(%ebp)\n" /* line 5159 */
        "movl $7, %ebx\n"
        "cld\n"
        "movl -0x4c(%ebp), %esi\n" /* mode, filesize */
        "movl $str_002b1ec4, %edi\n" /* "append" */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* filesize */
        "movl $0, %edx\n"
        "je .Lf19860a_00198815\n"
        "movzbl -1(%esi), %edx\n" /* filesize */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf19860a_00198815:\n"
        "testl %edx, %edx\n"
        "jne .Lf19860a_001987ce\n"
        "movl -0x50(%ebp), %eax\n" /* line 5162 | filename */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b1eb0, 4(%esp)\n" /* "scriptdata" */
        "movl $str_00216e18, (%esp)\n" /* "%s/%s" */
        "calll va\n"
        "movl $2, 8(%esp)\n"
        "jmp .Lf19860a_001987aa\n"
    );
}

/* line 5184 */
__attribute__((naked))
unsigned int GScr_CloseFile(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5184 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 5188 */
        "testl %eax, %eax\n"
        "jne .Lf198842_0019885a\n"
        /* } scope */
        ".Lf198842_00198853:\n"
        "addl $0x10, %esp\n" /* line 5223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198842_0019885a:\n"
        "movl $0, (%esp)\n" /* line 5191 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* filenum */
        "cmpl $1, %eax\n" /* line 5193 */
        "jbe .Lf198842_00198890\n"
        "movl %eax, 4(%esp)\n" /* line 5195 */
        "movl $str_002b1f04, (%esp)\n" /* "CloseFile failed, invalid file number %i
" */
        "calll Com_Printf\n"
        "movl $0xffffffff, (%esp)\n" /* line 5196 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 5223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198842_00198890:\n"
        "movl imp_level, %esi\n" /* line 5203 */
        "movl 0x3608(%esi, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf198842_001988c7\n"
        "movl %eax, (%esp)\n" /* line 5205 */
        "calll FS_FCloseFile\n"
        "movl $0xffffffff, 0x3608(%esi, %ebx, 4)\n" /* line 5206 */
        ".Lf198842_001988b4:\n"
        "movl $1, (%esp)\n" /* line 5221 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 5223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198842_001988c7:\n"
        "movl 0x360c(%esi, %ebx, 4), %ecx\n" /* line 5208 */
        "testl %ecx, %ecx\n"
        "je .Lf198842_001988f3\n"
        "calll Com_EndParseSession\n" /* line 5210 */
        "movl 0x360c(%esi, %ebx, 4), %eax\n" /* line 5211 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $0, 0x360c(%esi, %ebx, 4)\n" /* line 5212 */
        "jmp .Lf198842_001988b4\n"
        ".Lf198842_001988f3:\n"
        "movl %ebx, 4(%esp)\n" /* line 5216 | filenum */
        "movl $str_002b1f30, (%esp)\n" /* "CloseFile failed, file number %i was not open
" */
        "calll Com_Printf\n"
        "movl $0xffffffff, (%esp)\n" /* line 5217 */
        "calll Scr_AddInt\n"
        "jmp .Lf198842_00198853\n"
    );
}

/* line 5232 */
__attribute__((naked))
unsigned int GScr_FPrintln(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5232 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 5237 */
        "cmpl $1, %eax\n"
        "jbe .Lf198914_00198a04\n"
        "movl $0, (%esp)\n" /* line 5245 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* filenum */
        "cmpl $1, %eax\n" /* line 5247 */
        "jbe .Lf198914_00198962\n"
        "movl %eax, 4(%esp)\n" /* line 5249 */
        "movl $str_002b1f98, (%esp)\n" /* "FPrintln failed, invalid file number %i
" */
        "calll Com_Printf\n"
        "movl $0xffffffff, (%esp)\n" /* line 5250 */
        "calll Scr_AddInt\n"
        /* } scope */
        ".Lf198914_0019895a:\n"
        "addl $0x3c, %esp\n" /* line 5270 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198914_00198962:\n"
        "movl imp_level, %eax\n" /* line 5254 */
        "movl 0x3608(%eax, %esi, 4), %ebx\n"
        "testl %ebx, %ebx\n"
        "js .Lf198914_00198a24\n"
        "movl $1, -0x1c(%ebp)\n" /* arg */
        "jmp .Lf198914_001989e2\n"
        ".Lf198914_0019897f:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 5263 | arg */
        "movl %eax, (%esp)\n"
        "calll Scr_GetString\n"
        "movl %eax, -0x2c(%ebp)\n" /* s */
        "movl imp_level, %ebx\n" /* line 5264 */
        "movl 0x3608(%ebx, %esi, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x2c(%ebp), %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "movl 0x3608(%ebx, %esi, 4), %eax\n" /* line 5265 */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_0021f88c, (%esp)\n" /* "," */
        "calll FS_Write\n"
        "addl $1, -0x1c(%ebp)\n" /* line 5261 | arg */
        ".Lf198914_001989e2:\n"
        "calll Scr_GetNumParam\n"
        "cmpl -0x1c(%ebp), %eax\n" /* arg */
        "ja .Lf198914_0019897f\n"
        "calll Scr_GetNumParam\n" /* line 5268 */
        "subl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 5270 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198914_00198a04:\n"
        "movl $str_002b1f60, (%esp)\n" /* line 5239 */
        "calll Com_Printf\n"
        "movl $0xffffffff, (%esp)\n" /* line 5241 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 5270 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198914_00198a24:\n"
        "movl %esi, 4(%esp)\n" /* line 5256 | filenum */
        "movl $str_002b1fc4, (%esp)\n" /* "FPrintln failed, file number %i was not open for writing
" */
        "calll Com_Printf\n"
        "movl $0xffffffff, (%esp)\n" /* line 5257 */
        "calll Scr_AddInt\n"
        "jmp .Lf198914_0019895a\n"
    );
}

/* line 5279 */
__attribute__((naked))
unsigned int GScr_FReadLn(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5279 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 5286 */
        "testl %eax, %eax\n"
        "jne .Lf198a46_00198a78\n"
        "movl $str_002b2000, (%esp)\n" /* line 5288 */
        "calll Com_Printf\n"
        "movl $0xffffffff, (%esp)\n" /* line 5290 */
        "calll Scr_AddInt\n"
        /* } scope */
        ".Lf198a46_00198a70:\n"
        "addl $0x2c, %esp\n" /* line 5345 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198a46_00198a78:\n"
        "movl $0, (%esp)\n" /* line 5294 */
        "calll Scr_GetInt\n"
        "cmpl $1, %eax\n" /* line 5296 */
        "jbe .Lf198a46_00198aad\n"
        "movl %eax, 4(%esp)\n" /* line 5298 */
        "movl $str_002b2038, (%esp)\n" /* "freadln failed, invalid file number %i
" */
        "calll Com_Printf\n"
        "movl $0xffffffff, (%esp)\n" /* line 5299 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 5345 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198a46_00198aad:\n"
        "movl imp_level, %ecx\n" /* line 5303 */
        "movl 0x360c(%ecx, %eax, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf198a46_00198b6e\n"
        "movl %edx, -0x1c(%ebp)\n" /* line 5310 | buf */
        "leal (%eax, %eax, 4), %eax\n" /* line 5315 */
        "shll $2, %eax\n"
        "movl 0x3610(%eax, %ecx), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lf198a46_00198b01\n"
        "leal 0x3610(%eax, %ecx), %eax\n" /* line 5317 */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %ebx\n" /* buf */
        "movl %ebx, (%esp)\n"
        "calll Com_ParseSetMark\n"
        "movl %ebx, (%esp)\n" /* line 5318 */
        "calll Com_GetArgCountOnLine\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "jmp .Lf198a46_00198a70\n"
        ".Lf198a46_00198b01:\n"
        "leal 0x3610(%eax, %ecx), %ebx\n" /* line 5322 */
        "movl %ebx, 4(%esp)\n"
        "leal -0x1c(%ebp), %edi\n" /* buf */
        "movl %edi, (%esp)\n"
        "calll Com_ParseReturnToMark\n"
        "movl %edi, (%esp)\n" /* line 5325 */
        "calll Com_SkipRestOfLine\n"
        "movl %ebx, 4(%esp)\n" /* line 5328 */
        "movl %edi, (%esp)\n"
        "calll Com_ParseSetMark\n"
        "movl %edi, (%esp)\n" /* line 5331 */
        "calll Com_Parse\n"
        "movzbl (%eax), %esi\n" /* line 5332 */
        "movl %ebx, 4(%esp)\n" /* line 5338 */
        "movl %edi, (%esp)\n"
        "calll Com_ParseReturnToMark\n"
        "movl %esi, %eax\n" /* line 5340 */
        "testb %al, %al\n"
        "je .Lf198a46_00198b5d\n"
        "movl %edi, (%esp)\n" /* line 5343 */
        "calll Com_GetArgCountOnLine\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "jmp .Lf198a46_00198a70\n"
        ".Lf198a46_00198b5d:\n"
        "movl $0xffffffff, (%esp)\n" /* line 5341 */
        "calll Scr_AddInt\n"
        "jmp .Lf198a46_00198a70\n"
        ".Lf198a46_00198b6e:\n"
        "movl %eax, 4(%esp)\n" /* line 5305 */
        "movl $str_002b2060, (%esp)\n" /* "freadln failed, file number %i was not open for reading
" */
        "calll Com_Printf\n"
        "movl $0xffffffff, (%esp)\n" /* line 5306 */
        "calll Scr_AddInt\n"
        "jmp .Lf198a46_00198a70\n"
    );
}

/* line 5354 */
__attribute__((naked))
unsigned int GScr_FGetArg(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5354 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 5361 */
        "cmpl $1, %eax\n"
        "jbe .Lf198b90_00198c4b\n"
        "movl $0, (%esp)\n" /* line 5369 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* i */
        "movl $1, (%esp)\n" /* line 5370 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* arg */
        "cmpl $1, %ebx\n" /* line 5372 | i */
        "jbe .Lf198b90_00198bec\n"
        "movl %ebx, 4(%esp)\n" /* line 5374 | i */
        "movl $str_002b20d8, (%esp)\n" /* "freadline failed, invalid file number %i
" */
        "calll Com_Printf\n"
        "movl $str_002157b8, (%esp)\n" /* line 5375 */
        "calll Scr_AddString\n"
        /* } scope */
        ".Lf198b90_00198be4:\n"
        "addl $0x2c, %esp\n" /* line 5412 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198b90_00198bec:\n"
        "testl %eax, %eax\n" /* line 5379 */
        "js .Lf198b90_00198cb4\n"
        "movl imp_level, %edx\n" /* line 5386 */
        "movl 0x360c(%edx, %ebx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf198b90_00198c93\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 5394 | buf */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 5397 | i */
        "leal 0x3610(%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %edi\n" /* buf */
        "movl %edi, (%esp)\n"
        "calll Com_ParseReturnToMark\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf198b90_00198c27:\n"
        "movl %edi, (%esp)\n" /* line 5401 */
        "calll Com_ParseOnLine\n"
        "cmpb $0, (%eax)\n" /* line 5402 */
        "je .Lf198b90_00198c6b\n"
        "addl $1, %ebx\n" /* line 5399 | i */
        "cmpl %ebx, %esi\n" /* i, arg */
        "jge .Lf198b90_00198c27\n"
        "movl %eax, (%esp)\n" /* line 5410 */
        "calll Scr_AddString\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 5412 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198b90_00198c4b:\n"
        "movl $str_002b209c, (%esp)\n" /* line 5363 */
        "calll Com_Printf\n"
        "movl $str_002157b8, (%esp)\n" /* line 5365 */
        "calll Scr_AddString\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 5412 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198b90_00198c6b:\n"
        "movl %ebx, 8(%esp)\n" /* line 5404 | i */
        "leal 1(%esi), %eax\n" /* arg */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2170, (%esp)\n" /* "freadline failed, there aren't %i arguments on this line, th" */
        "calll Com_Printf\n"
        "movl $str_002157b8, (%esp)\n" /* line 5405 */
        "calll Scr_AddString\n"
        "jmp .Lf198b90_00198be4\n"
        ".Lf198b90_00198c93:\n"
        "movl %ebx, 4(%esp)\n" /* line 5388 | i */
        "movl $str_002b2134, (%esp)\n" /* "freadline failed, file number %i was not open for reading
" */
        "calll Com_Printf\n"
        "movl $str_002157b8, (%esp)\n" /* line 5389 */
        "calll Scr_AddString\n"
        "jmp .Lf198b90_00198be4\n"
        ".Lf198b90_00198cb4:\n"
        "movl %eax, 4(%esp)\n" /* line 5381 */
        "movl $str_002b2104, (%esp)\n" /* "freadline failed, invalid argument number %i
" */
        "calll Com_Printf\n"
        "movl $str_002157b8, (%esp)\n" /* line 5382 */
        "calll Scr_AddString\n"
        "jmp .Lf198b90_00198be4\n"
    );
}

/* line 5420 */
unsigned int GScr_SetArchive(void)
{
    SV_EnableArchivedSnapshot(Scr_GetInt(0));
    return 0;
}

/* line 5448 */
unsigned int Scr_PlayRumbleOnPos(void)
{
    return 0;
}

/* line 5459 */
unsigned int Scr_PlayLoopRumbleOnPos(void)
{
    return 0;
}

/* line 5470 */
unsigned int Scr_StopAllRumbles(void)
{
    return 0;
}

/* line 5484 */
unsigned int Scr_IsSplitscreen(void)
{
    Scr_AddInt(0);
    return 0;
}

/* line 5497 */
unsigned int GScr_MatchEnd(void)
{
    return 0;
}

/* line 5581 */
unsigned int GScr_SetPlayerTeamRank(void)
{
    return 0;
}

/* line 5586 */
unsigned int GScr_SendXboxLiveRanks(void)
{
    return 0;
}

/* 1.3 stub - endparty (no-op on PC) */
void GScr_EndXboxLiveLobby(void)
{
}

/* line 5678 */
__attribute__((naked))
unsigned int GScr_ReleaseClaimedTrigger(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5678 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf198d2a_00198dbb\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n"
        "subl %eax, %esi\n"
        "shll $4, %esi\n"
        "addl imp_g_entities, %esi\n"
        ".Lf198d2a_00198d58:\n"
        "movzwl 0x168(%esi), %edx\n" /* line 5683 | triggerEnt */
        "movl imp_scr_const, %edi\n"
        "cmpw 0x56(%edi), %dx\n"
        "je .Lf198d2a_00198da9\n"
        "movzwl 0x58(%edi), %eax\n"
        "cmpw %ax, %dx\n"
        "je .Lf198d2a_00198da9\n"
        "movzwl %ax, %eax\n" /* line 5684 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n"
        "movzwl 0x56(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b21d8, (%esp)\n" /* "releaseclaimedtrigger: trigger entity must be of type %s or " */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf198d2a_00198da9:\n"
        "movl $0x3ff, 0x1b4(%esi)\n" /* line 5686 | triggerEnt */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 5687 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198d2a_00198dbb:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n"
        "jmp .Lf198d2a_00198d58\n"
    );
}

/* line 5893 */
__attribute__((naked))
BuiltinFunction Scr_GetFunction(const char * *pName, int *type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5893 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 5898 | pName */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* name */
        "xorl %esi, %esi\n" /* i */
        "movl $functions, %ebx\n"
        "xorl %edi, %edi\n"
        "movl %eax, %edx\n"
        "jmp .Lf198dcc_00198dfe\n"
        ".Lf198dcc_00198dea:\n"
        "addl $1, %esi\n" /* line 5900 | i */
        "addl $0xc, %edi\n"
        "addl $0xc, %ebx\n"
        "cmpl $0x91, %esi\n" /* i: 145 entries (144 base + endparty) */
        "je .Lf198dcc_00198e34\n"
        "movl -0x1c(%ebp), %edx\n" /* name */
        ".Lf198dcc_00198dfe:\n"
        "movl (%ebx), %eax\n" /* line 5902 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf198dcc_00198dea\n"
        "movl functions(%edi), %eax\n" /* line 5904 */
        "movl 8(%ebp), %edx\n" /* pName */
        "movl %eax, (%edx)\n"
        "movl functions+8(%edi), %eax\n" /* line 5905 */
        "movl 0xc(%ebp), %edx\n" /* type */
        "movl %eax, (%edx)\n"
        "movl functions+4(%edi), %eax\n" /* line 5906 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 5910 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198dcc_00198e34:\n"
        "xorl %eax, %eax\n" /* line 5900 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 5910 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 6008 */
__attribute__((naked))
BuiltinMethod Scr_GetMethod(const char * *pName, int *type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6008 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pName */
        "movl 0xc(%ebp), %esi\n" /* type */
        /* { scope 1: i, name */
        "movl $0, (%esi)\n" /* line 6014 | type */
        "movl %ebx, (%esp)\n" /* line 6016 | pName */
        "calll Player_GetMethod\n"
        "testl %eax, %eax\n" /* line 6017 */
        "je .Lf198e3e_00198e67\n"
        /* } scope */
        ".Lf198e3e_00198e5f:\n"
        "addl $0x2c, %esp\n" /* line 6056 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i, name */
        ".Lf198e3e_00198e67:\n"
        "movl %ebx, (%esp)\n" /* line 6020 | pName */
        "calll ScriptEnt_GetMethod\n"
        "testl %eax, %eax\n" /* line 6021 */
        "jne .Lf198e3e_00198e5f\n"
        "movl %ebx, (%esp)\n" /* line 6024 | pName */
        "calll HudElem_GetMethod\n"
        "testl %eax, %eax\n" /* line 6025 */
        "jne .Lf198e3e_00198e5f\n"
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 5992 */
        "movl %eax, -0x1c(%ebp)\n" /* name */
        "movl $0, -0x20(%ebp)\n" /* i */
        "movl $methods, %edi\n"
        "movl $0, -0x24(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf198e3e_00198eaf\n"
        ".Lf198e3e_00198e9b:\n"
        "addl $1, -0x20(%ebp)\n" /* line 5994 | i */
        "addl $0xc, -0x24(%ebp)\n"
        "addl $0xc, %edi\n"
        "cmpl $0x3b, -0x20(%ebp)\n" /* i */
        "je .Lf198e3e_00198edc\n"
        "movl -0x1c(%ebp), %edx\n" /* name */
        ".Lf198e3e_00198eaf:\n"
        "movl (%edi), %eax\n" /* line 5996 */
        "testl %eax, %eax\n"  /* NULL check for zero-init methods table */
        "je .Lf198e3e_00198e9b\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf198e3e_00198e9b\n"
        "movl -0x24(%ebp), %edx\n" /* line 5998 */
        "movl methods(%edx), %eax\n"
        "movl %eax, (%ebx)\n"
        "movl methods+8(%edx), %eax\n" /* line 5999 */
        "movl %eax, (%esi)\n"
        "movl methods+4(%edx), %eax\n" /* line 6000 */
        "jmp .Lf198e3e_00198e5f\n"
        ".Lf198e3e_00198edc:\n"
        "xorl %eax, %eax\n" /* line 5994 */
        "jmp .Lf198e3e_00198e5f\n"
    );
}

/* line 6059 */
__attribute__((naked))
unsigned int Scr_SetOrigin(gentity_t *ent, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6059 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1 */
        "leal -0x14(%ebp), %ebx\n" /* line 6063 | org */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, 4(%esp)\n" /* line 6064 */
        "movl %esi, (%esp)\n" /* ent */
        "calll G_SetOrigin\n"
        "cmpb $0, 0xf0(%esi)\n" /* line 6066 | ent */
        "je .Lf198ee4_00198f1f\n"
        "movl %esi, (%esp)\n" /* line 6067 | ent */
        "calll SV_LinkEntity\n"
        /* } scope */
        ".Lf198ee4_00198f1f:\n"
        "addl $0x20, %esp\n" /* line 6068 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 6071 */
__attribute__((naked))
unsigned int Scr_SetAngles(gentity_t *ent, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6071 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "leal -0x14(%ebp), %ebx\n" /* line 6075 | angles */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, 4(%esp)\n" /* line 6076 */
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll G_SetAngle\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 6077 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 6080 */
__attribute__((naked))
unsigned int Scr_SetHealth(gentity_t *ent, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6080 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 6084 */
        "calll Scr_GetInt\n"
        "movl %eax, %edx\n"
        "movl 0x158(%ebx), %eax\n" /* line 6087 | ent */
        "testl %eax, %eax\n"
        "je .Lf198f56_00198f90\n"
        "movl %edx, 0x194(%ebx)\n" /* line 6089 | ent */
        "movl 0x158(%ebx), %eax\n" /* line 6090 | ent */
        "movl %edx, 0x12c(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 6097 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198f56_00198f90:\n"
        "movl %edx, 0x198(%ebx)\n" /* line 6094 | ent */
        "movl %edx, 0x194(%ebx)\n" /* line 6095 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 6097 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 6125 */
unsigned int GScr_AddEntity(gentity_t *pEnt)
{
    if (pEnt)
        Scr_AddEntity(pEnt);
    else
        Scr_AddUndefined();
    return 0;
}

/* line 6159 */
__attribute__((naked))
unsigned int Scr_ParseGameTypeList(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6159 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x145c, %esp\n"
        /* { scope 1 */
        "movl $0x1080, 8(%esp)\n" /* line 6183 */
        "movl $0, 4(%esp)\n"
        "movl $g_scr_data+44, (%esp)\n"
        "calll memset\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 6186 */
        "leal -0x1420(%ebp), %edi\n" /* szGameTypeList, iFileLength */
        "movl %edi, 0xc(%esp)\n" /* iFileLength */
        "movl $0, 8(%esp)\n"
        "movl $str_002aa304, 4(%esp)\n" /* "gsc" */
        "movl $str_002aa308, (%esp)\n" /* "maps/mp/gametypes" */
        "calll FS_GetFileList\n"
        "movl %eax, -0x1430(%ebp)\n" /* iNumGameTypeScripts */
        "testl %eax, %eax\n" /* line 6194 */
        "jg .Lf198fba_0019903a\n"
        "movl $0, -0x1434(%ebp)\n" /* iNumGameTypes */
        ".Lf198fba_00199024:\n"
        "movl -0x1434(%ebp), %eax\n" /* line 6290 | iNumGameTypes */
        "movl %eax, g_scr_data+40\n"
        /* } scope */
        "addl $0x145c, %esp\n" /* line 6291 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf198fba_0019903a:\n"
        "movl %edi, %esi\n" /* line 6194 | iFileLength, pszFileName */
        "movl $0, -0x1438(%ebp)\n" /* i */
        "movl $0, -0x1434(%ebp)\n" /* iNumGameTypes */
        "movl $g_scr_data+32, -0x1440(%ebp)\n"
        "jmp .Lf198fba_00199075\n"
        ".Lf198fba_0019905c:\n"
        "leal 1(%esi, %ebx), %esi\n" /* line 6205 | pszFileName */
        ".Lf198fba_00199060:\n"
        "addl $1, -0x1438(%ebp)\n" /* line 6194 | i */
        "movl -0x1438(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x1430(%ebp)\n" /* iNumGameTypeScripts */
        "je .Lf198fba_00199024\n"
        ".Lf198fba_00199075:\n"
        "movl -0x1440(%ebp), %eax\n" /* line 6196 */
        "addl $0xc, %eax\n"
        "movl %eax, -0x142c(%ebp)\n" /* pGameType */
        "cld\n" /* line 6199 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* pszFileName, iFileLength */
        "repne scasb %es:(%edi), %al\n" /* iFileLength */
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n" /* len */
        "cmpb $0x5f, (%esi)\n" /* line 6202 | pszFileName */
        "je .Lf198fba_0019905c\n"
        "movl $str_002aa31c, 4(%esp)\n" /* line 6210 */
        "leal (%esi, %ebx), %eax\n" /* pszFileName */
        "movl %eax, -0x143c(%ebp)\n"
        "subl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf198fba_001990bf\n"
        "movb $0, -4(%esi, %ebx)\n" /* line 6211 | pszFileName */
        ".Lf198fba_001990bf:\n"
        "cmpl $0x20, -0x1434(%ebp)\n" /* line 6219 | iNumGameTypes */
        "je .Lf198fba_00199268\n"
        "movl $0x40, 8(%esp)\n" /* line 6226 */
        "movl %esi, 4(%esp)\n" /* pszFileName */
        "movl -0x142c(%ebp), %eax\n" /* pGameType */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x142c(%ebp), %eax\n" /* line 6227 | pGameType */
        "movl %eax, (%esp)\n"
        "calll strlwr\n"
        "movl %esi, 4(%esp)\n" /* line 6229 | pszFileName */
        "movl $str_002aa364, (%esp)\n" /* "maps/mp/gametypes/%s.txt" */
        "calll va\n"
        "movl $0, 8(%esp)\n" /* line 6233 */
        "leal -0x20(%ebp), %edx\n" /* hFile */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %edi\n" /* iFileLength */
        "leal -1(%eax), %eax\n" /* line 6241 */
        "cmpl $0x3fe, %eax\n"
        "jbe .Lf198fba_001991ae\n"
        "testl %edi, %edi\n" /* line 6243 | iFileLength */
        "jle .Lf198fba_0019923f\n"
        "movl %esi, 4(%esp)\n" /* line 6246 | pszFileName */
        "movl $str_002aa364, (%esp)\n" /* "maps/mp/gametypes/%s.txt" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2260, (%esp)\n" /* "WARNING: GameType description file %s is too big to load.
" */
        "calll Com_Printf\n"
        ".Lf198fba_00199153:\n"
        "movl $0x40, 8(%esp)\n" /* line 6248 */
        "movl -0x142c(%ebp), %eax\n" /* pGameType */
        "movl %eax, 4(%esp)\n"
        "addl $0x40, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x1440(%ebp), %eax\n" /* line 6251 */
        "movl $0, 0x8c(%eax)\n"
        ".Lf198fba_00199180:\n"
        "addl $1, -0x1434(%ebp)\n" /* line 6277 | iNumGameTypes */
        "addl $0x84, -0x1440(%ebp)\n"
        "testl %edi, %edi\n" /* line 6281 | iFileLength */
        "jle .Lf198fba_001991a0\n"
        "movl -0x20(%ebp), %eax\n" /* line 6282 | hFile */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        ".Lf198fba_001991a0:\n"
        "movl -0x143c(%ebp), %esi\n" /* line 6285 | pszFileName */
        "addl $1, %esi\n" /* pszFileName */
        "jmp .Lf198fba_00199060\n"
        ".Lf198fba_001991ae:\n"
        "movl -0x20(%ebp), %eax\n" /* line 6256 | hFile */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* iFileLength */
        "leal -0x420(%ebp), %ebx\n" /* szBuffer, len */
        "movl %ebx, (%esp)\n" /* len */
        "calll FS_Read\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 6257 | len, pBuffParse */
        "leal -0x1c(%ebp), %eax\n" /* line 6265 | pBuffParse */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl $0x40, 8(%esp)\n" /* line 6267 */
        "movl %eax, 4(%esp)\n"
        "movl -0x1440(%ebp), %eax\n"
        "addl $0x4c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "leal -0x1c(%ebp), %eax\n" /* line 6270 | pBuffParse */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "testl %eax, %eax\n" /* line 6271 */
        "je .Lf198fba_0019922a\n"
        "movl $str_002aa728, 4(%esp)\n" /* "team" */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf198fba_0019922a\n"
        "movl -0x1440(%ebp), %eax\n" /* line 6272 */
        "movl $1, 0x8c(%eax)\n"
        "jmp .Lf198fba_00199180\n"
        ".Lf198fba_0019922a:\n"
        "movl -0x1440(%ebp), %eax\n" /* line 6274 */
        "movl $0, 0x8c(%eax)\n"
        "jmp .Lf198fba_00199180\n"
        ".Lf198fba_0019923f:\n"
        "movl %esi, 4(%esp)\n" /* line 6244 | pszFileName */
        "movl $str_002aa364, (%esp)\n" /* "maps/mp/gametypes/%s.txt" */
        "calll va\n"
        "movl %esi, 8(%esp)\n" /* pszFileName */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2218, (%esp)\n" /* "WARNING: Could not load GameType description file %s for gam" */
        "calll Com_Printf\n"
        "jmp .Lf198fba_00199153\n"
        ".Lf198fba_00199268:\n"
        "movl $0x1f, 4(%esp)\n" /* line 6221 */
        "movl $str_002aa324, (%esp)\n" /* "Too many game type scripts found! Only loading the first %i
" */
        "calll Com_Printf\n"
        "jmp .Lf198fba_00199024\n"
    );
}

/* line 6302 */
__attribute__((naked))
const char * Scr_GetGameTypeNameForScript(const char *pszGameTypeScript)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6302 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl g_scr_data+40, %eax\n" /* line 6306 */
        "testl %eax, %eax\n"
        "jg .Lf199282_0019929e\n"
        ".Lf199282_00199294:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf199282_00199296:\n"
        "addl $0x1c, %esp\n" /* line 6313 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf199282_0019929e:\n"
        "xorl %esi, %esi\n" /* line 6306 | i */
        "movl $g_scr_data+108, %edi\n"
        "movl $g_scr_data+44, %ebx\n"
        ".Lf199282_001992aa:\n"
        "movl 8(%ebp), %eax\n" /* line 6308 | pszGameTypeScript */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf199282_001992d6\n"
        "addl $1, %esi\n" /* line 6306 | i */
        "addl $0x84, %ebx\n"
        "addl $0x84, %edi\n"
        "cmpl %esi, g_scr_data+40\n" /* i */
        "jg .Lf199282_001992aa\n"
        "jmp .Lf199282_00199294\n"
        ".Lf199282_001992d6:\n"
        "movl %edi, %eax\n" /* line 6309 */
        "jmp .Lf199282_00199296\n"
    );
}

/* line 6341 */
extern void DBG_PrintFreeVars(const char *label);
unsigned int Scr_LoadGameType(void)
{
    unsigned int handle = g_scr_data.gametype.main;
    extern void *imp_scrVarPub;
    unsigned int codeBase = (unsigned int)((scrVarPub_t *)imp_scrVarPub)->programBuffer;
    /* Print all g_scr_data handles for debugging */
    Com_Printf("[Scr_LoadGameType] g_scr_data handles: +0=%u +4=%u +8=%u +12=%u +16=%u +20=%u +24=%u +28=%u\n",
        (unsigned int)g_scr_data.levelscript,
        (unsigned int)g_scr_data.gametypescript,
        (unsigned int)g_scr_data.gametype.main,
        (unsigned int)g_scr_data.gametype.startupgametype,
        (unsigned int)g_scr_data.gametype.playerconnect,
        (unsigned int)g_scr_data.gametype.playerdisconnect,
        (unsigned int)g_scr_data.gametype.playerdamage,
        (unsigned int)g_scr_data.gametype.playerkilled);
    Com_Printf("[Scr_LoadGameType] handle=%u codeBase=0x%x pos=0x%x\n", handle, codeBase, codeBase + handle);
    /* Print first 32 bytes of bytecode at pos */
    unsigned char *pos = (unsigned char *)(codeBase + handle);
    Com_Printf("[Scr_LoadGameType] bytecode: %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
        pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7],
        pos[8], pos[9], pos[10], pos[11], pos[12], pos[13], pos[14], pos[15]);
    Com_Printf("[Scr_LoadGameType]          %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
        pos[16], pos[17], pos[18], pos[19], pos[20], pos[21], pos[22], pos[23],
        pos[24], pos[25], pos[26], pos[27], pos[28], pos[29], pos[30], pos[31]);
    /* Dump compiled builtin function table */
    extern void *imp_scrCompilePub;
    unsigned int *ftable = (unsigned int *)((scrCompilePub_t *)imp_scrCompilePub)->func_table;
    Com_Printf("[Scr_LoadGameType] scrCompilePub builtins: [0]=%p [1]=%p [2]=%p [3]=%p [4]=%p [5]=%p [6]=%p [7]=%p\n",
        (void *)ftable[0], (void *)ftable[1], (void *)ftable[2], (void *)ftable[3],
        (void *)ftable[4], (void *)ftable[5], (void *)ftable[6], (void *)ftable[7]);
    Com_Printf("[Scr_LoadGameType] builtins cont: [8]=%p [9]=%p [10]=%p [11]=%p [12]=%p [13]=%p [14]=%p [15]=%p\n",
        (void *)ftable[8], (void *)ftable[9], (void *)ftable[10], (void *)ftable[11],
        (void *)ftable[12], (void *)ftable[13], (void *)ftable[14], (void *)ftable[15]);
    extern int dbg_alloc_counter;
    extern int dbg_getvar_counter;
    dbg_alloc_counter = 0;
    dbg_getvar_counter = 0;
    extern void *imp_scrVarPub;
    unsigned int levelId = ((scrVarPub_t *)imp_scrVarPub)->levelId;
    unsigned int timeArrayId = ((scrVarPub_t *)imp_scrVarPub)->timeArrayId;
    unsigned int pauseArrayId = ((scrVarPub_t *)imp_scrVarPub)->pauseArrayId;
    Com_Printf("[Scr_LoadGameType] scrVarPub: levelId=%u timeArrayId=%u pauseArrayId=%u\n", levelId, timeArrayId, pauseArrayId);
    /* Dump first 80 bytes of scrVarPub */
    unsigned char *svp = (unsigned char *)imp_scrVarPub;
    Com_Printf("[Scr_LoadGameType] scrVarPub raw: ");
    for (int i = 0; i < 80; i++) Com_Printf("%02x ", svp[i]);
    Com_Printf("\n");
    DBG_PrintFreeVars("before Scr_LoadGameType exec");
    unsigned int threadId = Scr_ExecThread(handle, 0);
    Com_Printf("[Scr_LoadGameType] total allocations: %d\n", dbg_alloc_counter);
    DBG_PrintFreeVars("after Scr_LoadGameType exec");
    Scr_FreeThread(threadId & 0xffff);
    return 0;
}

/* line 6356 */
unsigned int Scr_StartupGameType(void)
{
    extern void *imp_scrVarPub;
    unsigned int handle = g_scr_data.gametype.startupgametype;
    const char *codeBase = ((scrVarPub_t *)imp_scrVarPub)->programBuffer;
    const char *endBuf = ((scrVarPub_t *)imp_scrVarPub)->endScriptBuffer;
    const char *pos = codeBase + handle;
    {
        int i;
        Com_Printf("DBG [Scr_StartupGameType] handle=%u codeBase=%p endBuf=%p pos=%p level_init=%d\n",
                   handle, codeBase, endBuf, pos, ((level_locals_t *)imp_level)->initializing);
        {
            extern unsigned char scrCompilePub_bss[];
            __asm__(".set scrCompilePub_bss, scrCompilePub");
            Com_Printf("DBG scrCompilePub count=%d (at offset 0x34)\n",
                       ((scrCompilePub_t *)scrCompilePub_bss)->func_table_size);
        }
        Com_Printf("DBG bytecode dump (offset 0x150-0x1a0):\n");
        for (i = 0x150; i < 0x1a0; i += 16) {
            Com_Printf("  +%03x: %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
                i,
                (unsigned char)pos[i+0], (unsigned char)pos[i+1], (unsigned char)pos[i+2], (unsigned char)pos[i+3],
                (unsigned char)pos[i+4], (unsigned char)pos[i+5], (unsigned char)pos[i+6], (unsigned char)pos[i+7],
                (unsigned char)pos[i+8], (unsigned char)pos[i+9], (unsigned char)pos[i+10], (unsigned char)pos[i+11],
                (unsigned char)pos[i+12], (unsigned char)pos[i+13], (unsigned char)pos[i+14], (unsigned char)pos[i+15]);
        }
    }
    unsigned int threadId = Scr_ExecThread(handle, 0);
    Scr_FreeThread(threadId & 0xffff);
    return 0;
}

/* line 6370 */
unsigned int Scr_PlayerConnect(gentity_t *self)
{
    unsigned int handle = g_scr_data.gametype.playerconnect;
    unsigned int threadId = Scr_ExecEntThread(self, handle, 0);
    Scr_FreeThread(threadId & 0xffff);
    return 0;
}

/* line 6384 */
unsigned int Scr_PlayerDisconnect(gentity_t *self)
{
    unsigned int threadId = Scr_ExecEntThread(self, g_scr_data.gametype.playerdisconnect, 0);
    Scr_FreeThread(threadId & 0xffff);
    return 0;
}

/* line 6454 */
__attribute__((naked))
unsigned int Scr_VoteCalled(gentity_t *self, char *command, char *param1, char *param2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6454 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* self */
        "movl 0xc(%ebp), %esi\n" /* command */
        "movl 0x10(%ebp), %ebx\n" /* param1 */
        "movl 0x14(%ebp), %eax\n" /* line 6457 | param2 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        "movl %ebx, (%esp)\n" /* line 6458 | param1 */
        "calll Scr_AddString\n"
        "movl %esi, (%esp)\n" /* line 6459 | command */
        "calll Scr_AddString\n"
        "movl $3, 0x10(%ebp)\n" /* line 6461 | param1 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x7e(%eax), %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* command */
        "movl %edi, 8(%ebp)\n" /* self */
        "addl $0x1c, %esp\n" /* line 6462 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Scr_Notify\n" /* line 6461 */
    );
}

/* line 6469 */
unsigned int Scr_PlayerVote(gentity_t *self, char *option)
{
    Scr_AddString(option);
    Scr_Notify(self, ((scr_const_t *)imp_scr_const)->vote, 1);
    return 0;
}

/* line 533 */
__attribute__((naked))
unsigned int GScr_print3d(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 533 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "movl $0x3f800000, %ebx\n" /* line 542 | text */
        "movl %ebx, -0x30(%ebp)\n" /* text, color */
        "movl %ebx, -0x2c(%ebp)\n" /* line 543 | text */
        "movl %ebx, -0x28(%ebp)\n" /* line 544 | text */
        "movl %ebx, -0x24(%ebp)\n" /* line 545 | text */
        "calll Scr_GetNumParam\n" /* line 547 */
        "cmpl $3, %eax\n"
        "je .Lf19940c_001994ce\n"
        "cmpl $4, %eax\n"
        "je .Lf19940c_001994d3\n"
        "cmpl $2, %eax\n"
        "je .Lf19940c_001994db\n"
        "movl $4, (%esp)\n" /* line 550 */
        "calll Scr_GetFloat\n"
        "fstps -0x3c(%ebp)\n" /* scale */
        ".Lf19940c_00199454:\n"
        "movl $3, (%esp)\n" /* line 554 */
        "calll Scr_GetFloat\n"
        "fstps -0x24(%ebp)\n"
        ".Lf19940c_00199463:\n"
        "leal -0x20(%ebp), %eax\n" /* line 558 | rgb */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl -0x20(%ebp), %eax\n" /* line 199 | rgb */
        "movl %eax, -0x30(%ebp)\n" /* color */
        "movl -0x1c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x18(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        ".Lf19940c_00199488:\n"
        "movl $1, (%esp)\n" /* line 563 */
        "calll Scr_GetString\n"
        "movl %eax, %ebx\n" /* text */
        "leal -0x14(%ebp), %esi\n" /* line 564 | origin */
        "movl %esi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, 0xc(%esp)\n" /* line 568 | text */
        "movss -0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_AddDebugString\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 569 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19940c_001994ce:\n"
        "movl %ebx, -0x3c(%ebp)\n" /* line 547 | text, scale */
        "jmp .Lf19940c_00199463\n"
        ".Lf19940c_001994d3:\n"
        "movl %ebx, -0x3c(%ebp)\n" /* text, scale */
        "jmp .Lf19940c_00199454\n"
        ".Lf19940c_001994db:\n"
        "movl %ebx, -0x3c(%ebp)\n" /* text, scale */
        "jmp .Lf19940c_00199488\n"
    );
}

/* line 578 */
__attribute__((naked))
unsigned int GScr_line(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 578 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl $0x3f800000, %eax\n" /* line 587 */
        "movl %eax, -0x4c(%ebp)\n" /* color */
        "movl %eax, -0x48(%ebp)\n" /* line 588 */
        "movl %eax, -0x44(%ebp)\n" /* line 589 */
        "movl %eax, -0x40(%ebp)\n" /* line 590 */
        "calll Scr_GetNumParam\n" /* line 592 */
        "cmpl $3, %eax\n"
        "je .Lf1994e0_001995b1\n"
        "cmpl $4, %eax\n"
        "je .Lf1994e0_001995b5\n"
        "cmpl $2, %eax\n"
        "je .Lf1994e0_001995bc\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll Scr_GetInt\n"
        "movl %eax, %edi\n" /* depthTest */
        ".Lf1994e0_00199528:\n"
        "movl $3, (%esp)\n" /* line 599 */
        "calll Scr_GetFloat\n"
        "fstps -0x40(%ebp)\n"
        ".Lf1994e0_00199537:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 603 | rgb */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl -0x3c(%ebp), %eax\n" /* line 199 | rgb */
        "movl %eax, -0x4c(%ebp)\n" /* color */
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x48(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x44(%ebp)\n"
        ".Lf1994e0_0019955c:\n"
        "leal -0x30(%ebp), %esi\n" /* line 608 | end */
        "movl %esi, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x24(%ebp), %ebx\n" /* line 609 | start */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $1, 0x14(%esp)\n" /* line 613 */
        "movl $0, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n" /* depthTest */
        "leal -0x4c(%ebp), %eax\n" /* color */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_AddDebugLine\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 614 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1994e0_001995b1:\n"
        "xorl %edi, %edi\n" /* line 592 | depthTest */
        "jmp .Lf1994e0_00199537\n"
        ".Lf1994e0_001995b5:\n"
        "xorl %edi, %edi\n" /* depthTest */
        "jmp .Lf1994e0_00199528\n"
        ".Lf1994e0_001995bc:\n"
        "xorl %edi, %edi\n" /* depthTest */
        "jmp .Lf1994e0_0019955c\n"
    );
}

/* line 967 */
__attribute__((naked))
unsigned int GScr_Spawn(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 967 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 974 */
        "calll Scr_GetConstString\n"
        "movl %eax, %esi\n" /* classname */
        "leal -0x24(%ebp), %eax\n" /* line 975 | origin */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "calll Scr_GetNumParam\n" /* line 977 */
        "cmpl $2, %eax\n"
        "ja .Lf1995c0_0019967b\n"
        "xorl %edi, %edi\n" /* iSpawnFlags */
        ".Lf1995c0_001995fa:\n"
        "calll G_Spawn\n" /* line 982 */
        "movl %eax, %ebx\n" /* ent */
        "movzwl %si, %esi\n" /* line 983 | classname */
        "movl %esi, 4(%esp)\n" /* classname */
        "leal 0x168(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "leal 0x138(%ebx), %edx\n" /* line 984 | ent, to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | origin */
        "movl %eax, 0x138(%ebx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl %edi, 0x170(%ebx)\n" /* line 985 | iSpawnFlags, ent */
        "movl %ebx, (%esp)\n" /* line 987 | ent */
        "calll G_CallSpawnEntity\n"
        "testl %eax, %eax\n"
        "je .Lf1995c0_00199653\n"
        "movl %ebx, (%esp)\n" /* line 989 | ent */
        "calll Scr_AddEntity\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 994 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1995c0_00199653:\n"
        "movl %esi, (%esp)\n" /* line 993 | classname */
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b229c, (%esp)\n" /* "unable to spawn "%s" entity" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 994 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1995c0_0019967b:\n"
        "movl $2, (%esp)\n" /* line 978 */
        "calll Scr_GetInt\n"
        "movl %eax, %edi\n" /* iSpawnFlags */
        "jmp .Lf1995c0_001995fa\n"
    );
}

/* line 1005 */
__attribute__((naked))
unsigned int GScr_SpawnTurret(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1005 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 1012 */
        "calll Scr_GetConstString\n"
        "movl %eax, %edi\n"
        "leal -0x24(%ebp), %eax\n" /* line 1013 | origin */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $2, (%esp)\n" /* line 1014 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* weaponinfoname */
        "calll G_Spawn\n" /* line 1016 */
        "movl %eax, %ebx\n" /* ent */
        "movzwl %di, %eax\n" /* line 1017 */
        "movl %eax, 4(%esp)\n"
        "leal 0x168(%ebx), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "leal 0x138(%ebx), %edx\n" /* line 1018 | ent, to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | origin */
        "movl %eax, 0x138(%ebx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl %esi, 4(%esp)\n" /* line 1020 | weaponinfoname */
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_SpawnTurret\n"
        "movl %ebx, (%esp)\n" /* line 1021 | ent */
        "calll Scr_AddEntity\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1022 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3220 */
unsigned int Scr_VectorNormalize(void)
{
    vec3_t a, b;
    Scr_GetVector(0, a);
    b[0] = a[0];
    b[1] = a[1];
    b[2] = a[2];
    Vec3Normalize(b);
    Scr_AddVector(b);
    return 0;
}

/* line 3679 */
__attribute__((naked))
unsigned int Scr_GrenadeExplosionEffect(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3679 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "addl $-0x80, %esp\n"
        /* { scope 1 */
        "leal -0x14(%ebp), %eax\n" /* line 3688 | vOrg */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl -0x14(%ebp), %eax\n" /* line 199 | vOrg */
        "movl %eax, -0x2c(%ebp)\n" /* vPos */
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 3690 */
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x24(%ebp)\n"
        "movl $0xbc, 4(%esp)\n" /* line 3692 */
        "leal -0x2c(%ebp), %ebx\n" /* vPos */
        "movl %ebx, (%esp)\n"
        "calll G_TempEntity\n"
        "movl %eax, %esi\n" /* pEnt */
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, -0x20(%ebp)\n" /* vDir */
        "movl %eax, -0x1c(%ebp)\n" /* line 192 */
        "movl $0x3f800000, -0x18(%ebp)\n" /* line 193 */
        "leal -0x20(%ebp), %eax\n" /* line 3695 | vDir */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0xa0(%esi)\n" /* pEnt */
        "movl -0x2c(%ebp), %eax\n" /* line 199 | vPos */
        "movl %eax, -0x38(%ebp)\n" /* vEnd */
        "movl -0x28(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x34(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 201 */
        "subss lit4_002ed97c, %xmm0\n" /* line 3698 | 17.0f */
        "movss %xmm0, -0x30(%ebp)\n"
        "movl $0x811, 0x18(%esp)\n" /* line 3699 */
        "movl $0x3ff, 0x14(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* vEnd */
        "movl %eax, 0x10(%esp)\n"
        "movl imp_vec3_origin, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x5c(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movl -0x4c(%ebp), %eax\n" /* line 3700 */
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        "movl %eax, 0x88(%esi)\n" /* pEnt */
        /* } scope */
        "subl $-0x80, %esp\n" /* line 3701 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2251 */
__attribute__((naked))
unsigned int Scr_Objective_Position(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2251 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 2256 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* obj */
        "cmpl $0xf, %eax\n" /* line 2257 */
        "ja .Lf19983c_001998eb\n"
        ".Lf19983c_0019985a:\n"
        "leal (, %ebx, 4), %eax\n" /* line 2259 */
        "shll $5, %ebx\n" /* obj */
        "subl %eax, %ebx\n" /* obj */
        "movl imp_level, %eax\n"
        "addl $0x24, %eax\n"
        "addl %eax, %ebx\n" /* obj */
        "movl 0x10(%ebx), %eax\n" /* line 2077 */
        "cmpl $0x3ff, %eax\n"
        "je .Lf19983c_0019989f\n"
        /* { scope 2 */
        "leal (%eax, %eax, 4), %eax\n" /* line 2081 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "cmpb $0, 0xfc(%edx)\n" /* line 2082 */
        "jne .Lf19983c_001998e2\n"
        ".Lf19983c_00199898:\n"
        "movl $0x3ff, 0x10(%ebx)\n" /* line 2085 */
        /* } scope */
        ".Lf19983c_0019989f:\n"
        "leal 4(%ebx), %eax\n" /* line 2262 | obj */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "cvttss2si 4(%ebx), %eax\n" /* line 2263 | obj */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%ebx)\n" /* obj */
        "cvttss2si 8(%ebx), %eax\n" /* obj */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 8(%ebx)\n" /* obj */
        "cvttss2si 0xc(%ebx), %eax\n" /* obj */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n" /* obj */
        /* } scope */
        "addl $0x14, %esp\n" /* line 2264 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf19983c_001998e2:\n"
        "andb $0xef, 0xf2(%edx)\n" /* line 2083 */
        "jmp .Lf19983c_00199898\n"
        /* } scope */
        ".Lf19983c_001998eb:\n"
        "movl $0xf, 8(%esp)\n" /* line 2258 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b133c, (%esp)\n" /* "index %i is an illegal objective index. Valid indexes are 0 " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf19983c_0019985a\n"
    );
}

/* line 2506 */
__attribute__((naked))
unsigned int GScr_positionWouldTelefrag(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2506 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1050, %esp\n"
        /* { scope 1 */
        "leal -0x2c(%ebp), %eax\n" /* line 2514 | vPos */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movss -0x2c(%ebp), %xmm3\n" /* line 240 | vPos */
        "movl imp_playerMins, %eax\n"
        "movaps %xmm3, %xmm0\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* mins */
        "movss -0x28(%ebp), %xmm2\n" /* line 241 */
        "movaps %xmm2, %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 242 */
        "movaps %xmm1, %xmm0\n"
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "movl imp_playerMaxs, %eax\n" /* line 240 */
        "addss (%eax), %xmm3\n"
        "movss %xmm3, -0x20(%ebp)\n" /* maxs */
        "addss 4(%eax), %xmm2\n" /* line 241 */
        "movss %xmm2, -0x1c(%ebp)\n"
        "addss 8(%eax), %xmm1\n" /* line 242 */
        "movss %xmm1, -0x18(%ebp)\n"
        "movl $0x2000000, 0x10(%esp)\n" /* line 2518 */
        "movl $0x400, 0xc(%esp)\n"
        "leal -0x102c(%ebp), %eax\n" /* touch */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* maxs */
        "movl %eax, 4(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* mins */
        "movl %eax, (%esp)\n"
        "calll CM_AreaEntities\n"
        "movl %eax, %ebx\n" /* num */
        "testl %eax, %eax\n" /* line 2520 */
        "jle .Lf199918_001999fa\n"
        "xorl %ecx, %ecx\n"
        "movl imp_g_entities, %esi\n"
        ".Lf199918_001999cc:\n"
        "movl -0x102c(%ebp, %ecx, 4), %eax\n" /* line 2523 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl 0x158(%esi, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf199918_001999f3\n"
        "cmpl $5, 4(%eax)\n"
        "jle .Lf199918_00199a10\n"
        ".Lf199918_001999f3:\n"
        "addl $1, %ecx\n" /* line 2520 */
        "cmpl %ecx, %ebx\n" /* num */
        "jne .Lf199918_001999cc\n"
        ".Lf199918_001999fa:\n"
        "movl $0, (%esp)\n" /* line 2530 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x1050, %esp\n" /* line 2531 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf199918_00199a10:\n"
        "movl $1, (%esp)\n" /* line 2525 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x1050, %esp\n" /* line 2531 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 950 */
__attribute__((naked))
unsigned int GScr_GetBrushModelCenter(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 950 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 953 */
        "calll Scr_GetEntity\n"
        "leal 0x120(%eax), %edx\n"
        "leal 0x12c(%eax), %ecx\n"
        /* { scope 2 */
        "movss 0x120(%eax), %xmm3\n" /* line 240 */
        "addss 0x12c(%eax), %xmm3\n"
        "movss %xmm3, -0x14(%ebp)\n" /* vCenter */
        "movss 4(%edx), %xmm1\n" /* line 241 */
        "addss 4(%ecx), %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n"
        "movss 8(%edx), %xmm2\n" /* line 242 */
        "addss 8(%ecx), %xmm2\n"
        /* } scope */
        "movss lit4_002ed5d8, %xmm0\n" /* line 272 | 0.5f */
        "mulss %xmm0, %xmm3\n"
        "movss %xmm3, -0x14(%ebp)\n" /* vCenter */
        "mulss %xmm0, %xmm1\n" /* line 273 */
        "movss %xmm1, -0x10(%ebp)\n"
        "mulss %xmm0, %xmm2\n" /* line 274 */
        "movss %xmm2, -0xc(%ebp)\n"
        "leal -0x14(%ebp), %eax\n" /* line 958 | vCenter */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        /* } scope */
        "leave\n" /* line 959 */
        "retl\n"
    );
}

/* line 2182 */
__attribute__((naked))
unsigned int Scr_Objective_Delete(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2182 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $0, (%esp)\n" /* line 2186 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n"
        "cmpl $0xf, %eax\n" /* line 2187 */
        "ja .Lf199aa2_00199b3a\n"
        ".Lf199aa2_00199abc:\n"
        "leal (, %ebx, 4), %eax\n" /* line 2189 */
        "shll $5, %ebx\n"
        "subl %eax, %ebx\n"
        "movl imp_level, %eax\n"
        "addl $0x24, %eax\n"
        "leal (%ebx, %eax), %ecx\n" /* obj */
        /* { scope 1 */
        "movl 0x10(%ecx), %eax\n" /* line 2077 */
        "cmpl $0x3ff, %eax\n"
        "je .Lf199aa2_00199b02\n"
        /* { scope 2 */
        "leal (%eax, %eax, 4), %eax\n" /* line 2081 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "cmpb $0, 0xfc(%edx)\n" /* line 2082 */
        "jne .Lf199aa2_00199b31\n"
        ".Lf199aa2_00199afb:\n"
        "movl $0x3ff, 0x10(%ecx)\n" /* line 2085 */
        /* } scope */
        /* } scope */
        ".Lf199aa2_00199b02:\n"
        "movl $0, (%ecx)\n" /* line 2097 */
        "leal 4(%ecx), %edx\n" /* line 2098 | v */
        /* { scope 1 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 4(%ecx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "movl $0x3ff, 0x10(%ecx)\n" /* line 2099 */
        "movl $0, 0x14(%ecx)\n" /* line 2100 */
        "movl $0, 0x18(%ecx)\n" /* line 2101 */
        "addl $0x14, %esp\n" /* line 2191 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf199aa2_00199b31:\n"
        "andb $0xef, 0xf2(%edx)\n" /* line 2083 */
        "jmp .Lf199aa2_00199afb\n"
        /* } scope */
        /* } scope */
        ".Lf199aa2_00199b3a:\n"
        "movl $0xf, 8(%esp)\n" /* line 2188 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b133c, (%esp)\n" /* "index %i is an illegal objective index. Valid indexes are 0 " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf199aa2_00199abc\n"
    );
}

/* line 2038 */
__attribute__((naked))
unsigned int G_InitObjectives(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2038 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl imp_level, %edx\n"
        "addl $0x24, %edx\n"
        "movl %edx, %ecx\n"
        "movl imp_level, %ebx\n"
        "addl $0x1e4, %ebx\n"
        ".Lf199b68_00199b83:\n"
        "movl $0, (%edx)\n" /* line 2097 */
        "leal 4(%ecx), %eax\n" /* line 2098 | v */
        /* { scope 1 */
        "movl $0, 4(%ecx)\n" /* line 183 */
        "movl $0, 4(%eax)\n" /* line 184 */
        "movl $0, 8(%eax)\n" /* line 185 */
        /* } scope */
        "movl $0x3ff, 0x10(%edx)\n" /* line 2099 */
        "movl $0, 0x14(%edx)\n" /* line 2100 */
        "movl $0, 0x18(%edx)\n" /* line 2101 */
        "addl $0x1c, %edx\n"
        "addl $0x1c, %ecx\n"
        "cmpl %ebx, %edx\n" /* line 2042 */
        "jne .Lf199b68_00199b83\n"
        "popl %ebx\n" /* line 2044 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2766 */
__attribute__((naked))
unsigned int Scr_BulletTrace(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2766 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        /* { scope 1: vNorm */
        "leal -0x24(%ebp), %edi\n" /* line 2778 | vStart */
        "movl %edi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x30(%ebp), %esi\n" /* line 2779 | vEnd */
        "movl %esi, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $2, (%esp)\n" /* line 2781 */
        "calll Scr_GetInt\n"
        "cmpl $1, %eax\n" /* line 2782 */
        "sbbl %ebx, %ebx\n" /* iClipMask */
        "andl $0xfe000000, %ebx\n" /* iClipMask */
        "addl $0x2802831, %ebx\n" /* iClipMask */
        "movl $3, (%esp)\n" /* line 2785 */
        "calll Scr_GetType\n"
        "subl $1, %eax\n"
        "je .Lf199bc4_00199df6\n"
        ".Lf199bc4_00199c28:\n"
        "movl $0x3ff, %eax\n" /* line 2788 */
        ".Lf199bc4_00199c2d:\n"
        "movl $0, 0x14(%esp)\n" /* line 2791 */
        "movl %ebx, 0x10(%esp)\n" /* iClipMask */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "calll Scr_MakeArray\n" /* line 2793 */
        "movl -0x6c(%ebp), %eax\n" /* line 2796 | trace */
        "movl %eax, (%esp)\n"
        "calll Scr_AddFloat\n"
        "movl imp_scr_const, %ebx\n" /* line 2797 | iClipMask */
        "movzwl 0x16(%ebx), %eax\n" /* iClipMask */
        "movl %eax, (%esp)\n"
        "calll Scr_AddArrayStringIndexed\n"
        "movss -0x6c(%ebp), %xmm2\n" /* line 2800 | trace, fraction */
        /* { scope 2 */
        "movss -0x24(%ebp), %xmm1\n" /* line 1203 | vStart */
        "movss -0x30(%ebp), %xmm0\n" /* vEnd */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* endpos */
        "movss -0x20(%ebp), %xmm1\n" /* line 1204 */
        "movss -0x2c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 1205 */
        "movss -0x28(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        /* } scope */
        "leal -0x3c(%ebp), %eax\n" /* line 2801 | endpos */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        "movzwl 0x34(%ebx), %eax\n" /* line 2802 | iClipMask */
        "movl %eax, (%esp)\n"
        "calll Scr_AddArrayStringIndexed\n"
        "movl -0x50(%ebp), %edx\n" /* line 2805 */
        "leal -0x3fe(%edx), %eax\n"
        "cmpw $1, %ax\n"
        "jbe .Lf199bc4_00199dec\n"
        "movzwl %dx, %edx\n" /* line 2808 */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl imp_g_entities, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddEntity\n"
        ".Lf199bc4_00199d12:\n"
        "movl imp_scr_const, %esi\n" /* line 2809 */
        "movzwl 0x12(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddArrayStringIndexed\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 2811 | 1.0f */
        "ucomiss -0x6c(%ebp), %xmm0\n" /* trace */
        "ja .Lf199bc4_00199da3\n"
        /* { scope 2 */
        "movss -0x30(%ebp), %xmm0\n" /* line 248 | vEnd */
        "subss -0x24(%ebp), %xmm0\n" /* vStart */
        "movss %xmm0, -0x48(%ebp)\n" /* vNorm */
        "movss -0x2c(%ebp), %xmm0\n" /* line 249 */
        "subss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 250 */
        "subss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "leal -0x48(%ebp), %ebx\n" /* line 2828 | vNorm, iClipMask */
        "movl %ebx, (%esp)\n" /* iClipMask */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl %ebx, (%esp)\n" /* line 2829 | iClipMask */
        "calll Scr_AddVector\n"
        "movzwl 0x2c(%esi), %eax\n" /* line 2830 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddArrayStringIndexed\n"
        "movzwl 0x74(%esi), %eax\n" /* line 2833 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        /* } scope */
        "movzwl 0x4c(%esi), %eax\n" /* line 2820 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddArrayStringIndexed\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 2836 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vNorm */
        ".Lf199bc4_00199da3:\n"
        "leal -0x68(%ebp), %eax\n" /* line 2814 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        "movzwl 0x2c(%esi), %eax\n" /* line 2815 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddArrayStringIndexed\n"
        "movl -0x5c(%ebp), %eax\n" /* line 2819 */
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        "movzwl 0x4c(%esi), %eax\n" /* line 2820 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddArrayStringIndexed\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 2836 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vNorm */
        ".Lf199bc4_00199dec:\n"
        "calll Scr_AddUndefined\n" /* line 2806 */
        "jmp .Lf199bc4_00199d12\n"
        ".Lf199bc4_00199df6:\n"
        "movl $3, (%esp)\n" /* line 2785 */
        "calll Scr_GetPointerType\n"
        "cmpl $0x15, %eax\n"
        "jne .Lf199bc4_00199c28\n"
        "movl $3, (%esp)\n" /* line 2787 */
        "calll Scr_GetEntity\n"
        "movl (%eax), %eax\n" /* line 2788 */
        "jmp .Lf199bc4_00199c2d\n"
    );
}

/* line 2136 */
__attribute__((naked))
unsigned int Scr_Objective_Add(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2136 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 2144 */
        "movl %eax, %esi\n" /* numParam */
        "cmpl $1, %eax\n" /* line 2146 */
        "jle .Lf199e1e_00199fb4\n"
        ".Lf199e1e_00199e36:\n"
        "movl $0, (%esp)\n" /* line 2149 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* obj */
        "cmpl $0xf, %eax\n" /* line 2150 */
        "ja .Lf199e1e_00199f73\n"
        ".Lf199e1e_00199e4d:\n"
        "leal (, %ebx, 4), %eax\n" /* line 2152 */
        "shll $5, %ebx\n" /* obj */
        "subl %eax, %ebx\n" /* obj */
        "movl imp_level, %eax\n"
        "addl $0x24, %eax\n"
        "addl %eax, %ebx\n" /* obj */
        "movl 0x10(%ebx), %eax\n" /* line 2077 */
        "cmpl $0x3ff, %eax\n"
        "je .Lf199e1e_00199e92\n"
        /* { scope 2 */
        "leal (%eax, %eax, 4), %eax\n" /* line 2081 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "cmpb $0, 0xfc(%edx)\n" /* line 2082 */
        "jne .Lf199e1e_00199f04\n"
        ".Lf199e1e_00199e8b:\n"
        "movl $0x3ff, 0x10(%ebx)\n" /* line 2085 */
        /* } scope */
        ".Lf199e1e_00199e92:\n"
        "movl $1, (%esp)\n" /* line 2156 */
        "calll Scr_GetConstString\n"
        /* { scope 2 */
        "movl imp_scr_const, %ecx\n" /* line 2054 */
        "movzwl %ax, %edx\n"
        "cmpw %ax, 0x10(%ecx)\n"
        "je .Lf199e1e_00199eed\n"
        "movzwl 0x1e(%ecx), %eax\n" /* line 2056 */
        "cmpl %eax, %edx\n"
        "je .Lf199e1e_00199fa0\n"
        "movzwl 6(%ecx), %eax\n" /* line 2058 */
        "cmpl %eax, %edx\n"
        "je .Lf199e1e_00199faa\n"
        /* } scope */
        "movl %edx, (%esp)\n" /* line 2158 */
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2330, (%esp)\n" /* "Illegal objective state "%s". Valid states are "empty", "inv" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf199e1e_00199eed:\n"
        "xorl %eax, %eax\n"
        ".Lf199e1e_00199eef:\n"
        "movl %eax, (%ebx)\n" /* line 2159 | obj */
        "cmpl $2, %esi\n" /* line 2161 | numParam */
        "jg .Lf199e1e_00199f10\n"
        ".Lf199e1e_00199ef6:\n"
        "movl $0, 0x14(%ebx)\n" /* line 2171 | obj */
        /* } scope */
        "addl $0x10, %esp\n" /* line 2172 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf199e1e_00199f04:\n"
        "andb $0xef, 0xf2(%edx)\n" /* line 2083 */
        "jmp .Lf199e1e_00199e8b\n"
        /* } scope */
        ".Lf199e1e_00199f10:\n"
        "leal 4(%ebx), %eax\n" /* line 2163 | obj */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Scr_GetVector\n"
        "cvttss2si 4(%ebx), %eax\n" /* line 2164 | obj */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%ebx)\n" /* obj */
        "cvttss2si 8(%ebx), %eax\n" /* obj */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 8(%ebx)\n" /* obj */
        "cvttss2si 0xc(%ebx), %eax\n" /* obj */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n" /* obj */
        "movl $0x3ff, 0x10(%ebx)\n" /* line 2165 | obj */
        "cmpl $3, %esi\n" /* line 2167 | numParam */
        "jle .Lf199e1e_00199ef6\n"
        "movl $3, %edx\n" /* line 2168 */
        "movl %ebx, %eax\n" /* obj */
        "calll SetObjectiveIcon\n"
        "movl $0, 0x14(%ebx)\n" /* line 2171 | obj */
        /* } scope */
        "addl $0x10, %esp\n" /* line 2172 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf199e1e_00199f73:\n"
        "movl $0xf, 8(%esp)\n" /* line 2151 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b133c, (%esp)\n" /* "index %i is an illegal objective index. Valid indexes are 0 " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf199e1e_00199e4d\n"
        /* { scope 2 */
        ".Lf199e1e_00199fa0:\n"
        "movl $2, %eax\n" /* line 2056 */
        "jmp .Lf199e1e_00199eef\n"
        /* } scope */
        ".Lf199e1e_00199faa:\n"
        "movl $4, %eax\n" /* line 2172 */
        "jmp .Lf199e1e_00199eef\n"
        ".Lf199e1e_00199fb4:\n"
        "movl $str_002b22b8, (%esp)\n" /* line 2147 */
        "calll Scr_Error\n"
        "jmp .Lf199e1e_00199e36\n"
    );
}

/* line 2201 */
__attribute__((naked))
unsigned int Scr_Objective_State(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2201 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 2208 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* obj */
        "cmpl $0xf, %eax\n" /* line 2209 */
        "ja .Lf199fc6_0019a0b1\n"
        ".Lf199fc6_00199fe4:\n"
        "leal (, %ebx, 4), %eax\n" /* line 2211 */
        "shll $5, %ebx\n" /* obj */
        "subl %eax, %ebx\n" /* obj */
        "movl imp_level, %eax\n"
        "addl $0x24, %eax\n"
        "addl %eax, %ebx\n" /* obj */
        "movl $1, (%esp)\n" /* line 2213 */
        "calll Scr_GetConstString\n"
        /* { scope 2 */
        "movl imp_scr_const, %edx\n" /* line 2054 */
        "movzwl %ax, %ecx\n"
        "cmpw %ax, 0x10(%edx)\n"
        "je .Lf199fc6_0019a059\n"
        "movzwl 0x1e(%edx), %eax\n" /* line 2056 */
        "cmpl %eax, %ecx\n"
        "je .Lf199fc6_0019a0de\n"
        "movzwl 6(%edx), %eax\n" /* line 2058 */
        "cmpl %eax, %ecx\n"
        "je .Lf199fc6_0019a0e8\n"
        /* } scope */
        "movl $1, (%esp)\n" /* line 2215 */
        "calll Scr_GetString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2330, (%esp)\n" /* "Illegal objective state "%s". Valid states are "empty", "inv" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf199fc6_0019a059:\n"
        "xorl %eax, %eax\n"
        ".Lf199fc6_0019a05b:\n"
        "movl %eax, (%ebx)\n" /* line 2216 | obj */
        "testl %eax, %eax\n" /* line 2219 */
        "je .Lf199fc6_0019a06c\n"
        "cmpl $2, %eax\n"
        "je .Lf199fc6_0019a06c\n"
        /* } scope */
        ".Lf199fc6_0019a066:\n"
        "addl $0x14, %esp\n" /* line 2222 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf199fc6_0019a06c:\n"
        "movl 0x10(%ebx), %eax\n" /* line 2077 */
        "cmpl $0x3ff, %eax\n"
        "je .Lf199fc6_0019a066\n"
        /* { scope 2 */
        "leal (%eax, %eax, 4), %eax\n" /* line 2081 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "cmpb $0, 0xfc(%edx)\n" /* line 2082 */
        "jne .Lf199fc6_0019a0a1\n"
        "movl $0x3ff, 0x10(%ebx)\n" /* line 2085 */
        /* } scope */
        /* } scope */
        ".Lf199fc6_0019a09b:\n"
        "addl $0x14, %esp\n" /* line 2222 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf199fc6_0019a0a1:\n"
        "andb $0xef, 0xf2(%edx)\n" /* line 2083 */
        "movl $0x3ff, 0x10(%ebx)\n" /* line 2085 */
        "jmp .Lf199fc6_0019a09b\n"
        /* } scope */
        ".Lf199fc6_0019a0b1:\n"
        "movl $0xf, 8(%esp)\n" /* line 2210 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b133c, (%esp)\n" /* "index %i is an illegal objective index. Valid indexes are 0 " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf199fc6_00199fe4\n"
        /* { scope 2 */
        ".Lf199fc6_0019a0de:\n"
        "movl $2, %eax\n" /* line 2056 */
        "jmp .Lf199fc6_0019a05b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf199fc6_0019a0e8:\n"
        "movl $4, %eax\n" /* line 2222 */
        "jmp .Lf199fc6_0019a05b\n"
    );
}

/* line 3456 */
__attribute__((naked))
unsigned int Scr_MusicStop(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3456 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 3460 */
        "testl %eax, %eax\n"
        "je .Lf19a0f2_0019a121\n"
        "subl $1, %eax\n"
        "je .Lf19a0f2_0019a159\n"
        "movl $str_002b2380, (%esp)\n" /* line 3469 */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 3477 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19a0f2_0019a121:\n"
        "xorl %ebx, %ebx\n" /* line 3460 | fadeTime */
        ".Lf19a0f2_0019a123:\n"
        "movl %ebx, 8(%esp)\n" /* line 3476 | fadeTime */
        "movl $0x70, 4(%esp)\n"
        "movl $str_002b1d38, (%esp)\n" /* "%c %i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 3477 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19a0f2_0019a159:\n"
        "movl $0, (%esp)\n" /* line 3463 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xc(%ebp)\n"
        "cvttss2si -0xc(%ebp), %ebx\n"
        "testl %ebx, %ebx\n" /* line 3473 | fadeTime */
        "jns .Lf19a0f2_0019a123\n"
        "movl $str_002b23a0, (%esp)\n" /* line 3474 */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf19a0f2_0019a123\n"
    );
}

/* line 3612 */
__attribute__((naked))
unsigned int Scr_AmbientPlay(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3612 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 3620 */
        "cmpl $1, %eax\n"
        "je .Lf19a1ac_0019a1de\n"
        "cmpl $2, %eax\n"
        "je .Lf19a1ac_0019a235\n"
        "movl $str_002b23c4, (%esp)\n" /* line 3629 */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 3639 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19a1ac_0019a1de:\n"
        "xorl %ebx, %ebx\n" /* line 3620 | iFadeTime */
        "movl $0, (%esp)\n" /* line 3626 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* pszAliasName */
        "cmpb $0, (%eax)\n" /* line 3633 */
        "je .Lf19a1ac_0019a282\n"
        ".Lf19a1ac_0019a1f7:\n"
        "testl %ebx, %ebx\n" /* line 3635 | iFadeTime */
        "js .Lf19a1ac_0019a29b\n"
        ".Lf19a1ac_0019a1ff:\n"
        "movl imp_level, %eax\n" /* line 3638 */
        "addl 0x1ec(%eax), %ebx\n" /* iFadeTime */
        "movl %ebx, 8(%esp)\n" /* iFadeTime */
        "movl %esi, 4(%esp)\n" /* pszAliasName */
        "movl $str_002b246c, (%esp)\n" /* "n\%s\t\%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 3639 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19a1ac_0019a235:\n"
        "movl $1, (%esp)\n" /* line 3623 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xc(%ebp)\n"
        "cvttss2si -0xc(%ebp), %ebx\n"
        "movl $0, (%esp)\n" /* line 3626 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* pszAliasName */
        "cmpb $0, (%eax)\n" /* line 3633 */
        "jne .Lf19a1ac_0019a1f7\n"
        ".Lf19a1ac_0019a282:\n"
        "movl $str_002b23f4, (%esp)\n" /* line 3634 */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf19a1ac_0019a1f7\n"
        ".Lf19a1ac_0019a29b:\n"
        "movl $str_002b2444, (%esp)\n" /* line 3636 */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf19a1ac_0019a1ff\n"
    );
}

/* line 3647 */
__attribute__((naked))
unsigned int Scr_AmbientStop(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3647 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 3651 */
        "testl %eax, %eax\n"
        "je .Lf19a2b4_0019a2e3\n"
        "subl $1, %eax\n"
        "je .Lf19a2b4_0019a316\n"
        "movl $str_002b2478, (%esp)\n" /* line 3660 */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 3668 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19a2b4_0019a2e3:\n"
        "xorl %ebx, %ebx\n" /* line 3651 | iFadeTime */
        ".Lf19a2b4_0019a2e5:\n"
        "movl imp_level, %eax\n" /* line 3667 */
        "addl 0x1ec(%eax), %ebx\n" /* iFadeTime */
        "movl %ebx, 4(%esp)\n" /* iFadeTime */
        "movl $str_002b24c4, (%esp)\n" /* "t\%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 3668 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19a2b4_0019a316:\n"
        "movl $0, (%esp)\n" /* line 3654 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xc(%ebp)\n"
        "cvttss2si -0xc(%ebp), %ebx\n"
        "testl %ebx, %ebx\n" /* line 3664 | iFadeTime */
        "jns .Lf19a2b4_0019a2e5\n"
        "movl $str_002b249c, (%esp)\n" /* line 3665 */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf19a2b4_0019a2e5\n"
    );
}

/* line 3978 */
__attribute__((naked))
unsigned int Scr_PlayLoopedFX(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3978 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        /* { scope 1: fxName */
        "calll Scr_GetNumParam\n" /* line 3988 */
        "cmpl $2, %eax\n"
        "jbe .Lf19a36a_0019a3f1\n"
        "calll Scr_GetNumParam\n"
        "cmpl $6, %eax\n"
        "ja .Lf19a36a_0019a3f1\n"
        ".Lf19a36a_0019a38a:\n"
        "movl $0, -0x30(%ebp)\n" /* line 183 | fwd */
        "movl $0, -0x2c(%ebp)\n" /* line 184 */
        "movl $0, -0x28(%ebp)\n" /* line 185 */
        "movl $0, -0x3c(%ebp)\n" /* line 183 | up */
        "movl $0, -0x38(%ebp)\n" /* line 184 */
        "movl $0, -0x34(%ebp)\n" /* line 185 */
        "movl $0, (%esp)\n" /* line 3994 */
        "calll Scr_GetInt\n"
        "movl %eax, -0x450(%ebp)\n" /* fxId */
        "calll Scr_GetNumParam\n" /* line 3995 */
        "cmpl $5, %eax\n"
        "je .Lf19a36a_0019a481\n"
        "cmpl $6, %eax\n"
        "je .Lf19a36a_0019a3ff\n"
        "cmpl $4, %eax\n"
        "je .Lf19a36a_0019a500\n"
        "movl $0, -0x44c(%ebp)\n" /* cullDist */
        "jmp .Lf19a36a_0019a512\n"
        ".Lf19a36a_0019a3f1:\n"
        "movl $str_002b24cc, (%esp)\n" /* line 3989 */
        "calll Scr_Error\n"
        "jmp .Lf19a36a_0019a38a\n"
        ".Lf19a36a_0019a3ff:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 3998 | up */
        "movl %eax, 4(%esp)\n"
        "movl $5, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x3c(%ebp), %eax\n" /* line 3999 | up */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x458(%ebp)\n"
        "movss -0x458(%ebp), %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf19a36a_0019a481\n"
        "jp .Lf19a36a_0019a481\n"
        /* { scope 2 */
        "movl -0x450(%ebp), %eax\n" /* line 4003 | fxId */
        "testl %eax, %eax\n"
        "je .Lf19a36a_0019a65b\n"
        "movl $0x400, 8(%esp)\n" /* line 4004 */
        "leal -0x43c(%ebp), %ebx\n" /* fxName, ent */
        "movl %ebx, 4(%esp)\n" /* ent */
        "movl -0x450(%ebp), %eax\n" /* fxId */
        "addl $0x34e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        ".Lf19a36a_0019a469:\n"
        "movl %ebx, 4(%esp)\n" /* line 4007 | ent */
        "movl $str_002b257c, (%esp)\n" /* "playLoopedFx called with (0 0 0) up direction (effect = %s)
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        ".Lf19a36a_0019a481:\n"
        "leal -0x30(%ebp), %ebx\n" /* line 4011 | fwd, ent */
        "movl %ebx, 4(%esp)\n" /* ent */
        "movl $4, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, (%esp)\n" /* line 4012 | ent */
        "calll Vec3Normalize\n"
        "fstps -0x454(%ebp)\n"
        "movss -0x454(%ebp), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jne .Lf19a36a_0019a500\n"
        "jp .Lf19a36a_0019a500\n"
        /* { scope 2 */
        "movl -0x450(%ebp), %eax\n" /* line 4016 | fxId */
        "testl %eax, %eax\n"
        "je .Lf19a36a_0019a5f7\n"
        "movl $0x400, 8(%esp)\n" /* line 4017 */
        "leal -0x43c(%ebp), %ebx\n" /* fxName, ent */
        "movl %ebx, 4(%esp)\n" /* ent */
        "movl -0x450(%ebp), %eax\n" /* fxId */
        "addl $0x34e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        ".Lf19a36a_0019a4e8:\n"
        "movl %ebx, 4(%esp)\n" /* line 4020 | ent */
        "movl $str_002b25bc, (%esp)\n" /* "playLoopedFx called with (0 0 0) forward direction (effect =" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        ".Lf19a36a_0019a500:\n"
        "movl $3, (%esp)\n" /* line 4024 */
        "calll Scr_GetFloat\n"
        "fstps -0x44c(%ebp)\n" /* cullDist */
        ".Lf19a36a_0019a512:\n"
        "leal -0x24(%ebp), %edi\n" /* line 4027 | pos */
        "movl %edi, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $1, (%esp)\n" /* line 4028 */
        "calll Scr_GetFloat\n"
        "fstps -0x46c(%ebp)\n"
        "movss -0x46c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x45c(%ebp)\n"
        "cvttss2si -0x45c(%ebp), %esi\n"
        "testl %esi, %esi\n" /* line 4029 | repeat */
        "jle .Lf19a36a_0019a63e\n"
        ".Lf19a36a_0019a56f:\n"
        "calll G_Spawn\n" /* line 4034 */
        "movl %eax, %ebx\n" /* ent */
        "movl $8, 4(%eax)\n" /* line 4035 */
        "orb $8, 0xf2(%eax)\n" /* line 4036 */
        "movzbl -0x450(%ebp), %eax\n" /* line 4037 | fxId */
        "movl %eax, 0xd8(%ebx)\n" /* ent */
        "movl %edi, 4(%esp)\n" /* line 4039 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_SetOrigin\n"
        "leal 0x5c(%ebx), %edx\n" /* line 4040 | ent, to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | fwd */
        "movl %eax, 0x5c(%ebx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal -0x3c(%ebp), %eax\n" /* line 4041 | up */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0xa0(%ebx)\n" /* ent */
        "movss -0x44c(%ebp), %xmm0\n" /* line 4042 | cullDist */
        "movss %xmm0, 0x68(%ebx)\n" /* ent */
        "cvtsi2ssl %esi, %xmm0\n" /* line 4043 | repeat */
        "movss %xmm0, 0x6c(%ebx)\n" /* ent */
        "movl %ebx, (%esp)\n" /* line 4044 | ent */
        "calll SV_LinkEntity\n"
        "movl %ebx, (%esp)\n" /* line 4046 | ent */
        "calll Scr_AddEntity\n"
        /* } scope */
        "addl $0x47c, %esp\n" /* line 4047 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fxName */
        /* { scope 2 */
        ".Lf19a36a_0019a5f7:\n"
        "movl $0x20746f6e, -0x43c(%ebp)\n" /* line 4019 | fxName */
        "movl $0x63637573, -0x438(%ebp)\n"
        "movl $0x66737365, -0x434(%ebp)\n"
        "movl $0x796c6c75, -0x430(%ebp)\n"
        "movl $0x616f6c20, -0x42c(%ebp)\n"
        "movl $0x646564, -0x428(%ebp)\n"
        "leal -0x43c(%ebp), %ebx\n" /* fxName, ent */
        "jmp .Lf19a36a_0019a4e8\n"
        /* } scope */
        ".Lf19a36a_0019a63e:\n"
        "movl %esi, 4(%esp)\n" /* line 4030 | repeat */
        "movl $str_002b2600, (%esp)\n" /* "playLoopedFx called with %f s repeat (should be >= 0.0005s)
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf19a36a_0019a56f\n"
        /* { scope 2 */
        ".Lf19a36a_0019a65b:\n"
        "movl $0x20746f6e, -0x43c(%ebp)\n" /* line 4006 | fxName */
        "movl $0x63637573, -0x438(%ebp)\n"
        "movl $0x66737365, -0x434(%ebp)\n"
        "movl $0x796c6c75, -0x430(%ebp)\n"
        "movl $0x616f6c20, -0x42c(%ebp)\n"
        "movl $0x646564, -0x428(%ebp)\n"
        "leal -0x43c(%ebp), %ebx\n" /* fxName, ent */
        "jmp .Lf19a36a_0019a469\n"
    );
}

/* line 384 */
__attribute__((naked))
unsigned int Scr_ConstructMessageString(int firstParmIndex, int lastParmIndex, const char *errorContext, char *string, int stringLimit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 384 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* firstParmIndex */
        /* { scope 1 */
        "cmpl 0xc(%ebp), %eax\n" /* line 398 | lastParmIndex */
        "jle .Lf19a6a2_0019a6c4\n"
        "xorl %eax, %eax\n"
        "movl 0x14(%ebp), %edx\n" /* line 485 | string */
        "movb $0, (%eax, %edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 486 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19a6a2_0019a6c4:\n"
        "movl %eax, -0x28(%ebp)\n" /* line 398 | parmIndex */
        "movb $1, -0x19(%ebp)\n" /* useLocalization */
        "movl $0, -0x24(%ebp)\n" /* stringLen */
        ".Lf19a6a2_0019a6d2:\n"
        "movl %eax, (%esp)\n" /* line 400 */
        "calll Scr_GetType\n"
        "cmpl $3, %eax\n" /* line 403 */
        "je .Lf19a6a2_0019a8e1\n"
        "subl $1, %eax\n" /* line 420 */
        "je .Lf19a6a2_0019a845\n"
        ".Lf19a6a2_0019a6ec:\n"
        "movl -0x28(%ebp), %eax\n" /* line 443 | parmIndex */
        "movl %eax, (%esp)\n"
        "calll Scr_GetString\n"
        "movl %eax, -0x20(%ebp)\n" /* token */
        "cld\n" /* line 444 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n" /* charIndex */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* charIndex */
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* tokenLen */
        "testl %esi, %esi\n" /* line 446 | tokenLen */
        "jle .Lf19a6a2_0019a7c3\n"
        "xorl %edi, %edi\n" /* line 436 | charIndex */
        "jmp .Lf19a6a2_0019a740\n"
        ".Lf19a6a2_0019a717:\n"
        "movsbl (%ebx), %edx\n" /* line 452 | ent, _c */
        /* { scope 2 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "jne .Lf19a6a2_0019a77c\n"
        ".Lf19a6a2_0019a722:\n"
        "movl __DefaultRuneLocale, %eax\n"
        "movl 0x34(%eax, %edx, 4), %eax\n"
        "shrl $8, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 452 */
        "jne .Lf19a6a2_0019a798\n"
        ".Lf19a6a2_0019a735:\n"
        "addl $1, %edi\n" /* line 446 | charIndex */
        "cmpl %edi, %esi\n" /* charIndex, tokenLen */
        "je .Lf19a6a2_0019a7c3\n"
        ".Lf19a6a2_0019a740:\n"
        "movl -0x20(%ebp), %ebx\n" /* line 384 | token */
        "addl %edi, %ebx\n" /* charIter */
        "movzbl (%ebx), %edx\n" /* line 449 | ent */
        "leal -0x14(%edx), %eax\n"
        "cmpb $2, %al\n"
        "ja .Lf19a6a2_0019a717\n"
        "movsbl %dl, %eax\n" /* line 450 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b26e0, (%esp)\n" /* "bad escape character (%i) present in string" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* parmIndex */
        "movl %edx, (%esp)\n"
        "calll Scr_ParamError\n"
        "movsbl (%ebx), %edx\n" /* line 452 | ent, _c */
        /* { scope 2 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf19a6a2_0019a722\n"
        ".Lf19a6a2_0019a77c:\n"
        "movl $0x100, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 452 */
        "je .Lf19a6a2_0019a735\n"
        ".Lf19a6a2_0019a798:\n"
        "movl imp_loc_warningsAsErrors, %eax\n" /* line 454 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf19a6a2_0019a9a4\n"
        "movl -0x20(%ebp), %eax\n" /* line 457 | token */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* errorContext */
        "movl %edx, 4(%esp)\n"
        "movl $str_002b2754, (%esp)\n" /* "^3WARNING: Non-localized %s string is not allowed to have le" */
        "calll Com_Printf\n"
        ".Lf19a6a2_0019a7c3:\n"
        "movl -0x24(%ebp), %edx\n" /* line 462 | stringLen */
        "leal 1(%edx, %esi), %eax\n"
        "cmpl 0x18(%ebp), %eax\n" /* stringLimit */
        "jge .Lf19a6a2_0019a8b3\n"
        ".Lf19a6a2_0019a7d3:\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 465 | useLocalization */
        "je .Lf19a6a2_0019a83f\n"
        "movl 0x14(%ebp), %edx\n" /* line 467 | string */
        "movl -0x24(%ebp), %eax\n" /* stringLen */
        "movb $0x15, (%edx, %eax)\n"
        "addl $1, %eax\n" /* line 468 */
        "movl %eax, -0x24(%ebp)\n" /* stringLen */
        "movb $0, -0x19(%ebp)\n" /* useLocalization */
        ".Lf19a6a2_0019a7ed:\n"
        "testl %esi, %esi\n" /* line 475 | tokenLen */
        "jle .Lf19a6a2_0019a81d\n"
        "movl 0x14(%ebp), %edi\n" /* line 384 | string, charIter */
        "addl -0x24(%ebp), %edi\n" /* stringLen, charIter */
        "xorl %ebx, %ebx\n"
        ".Lf19a6a2_0019a7f9:\n"
        "movl -0x20(%ebp), %edx\n" /* line 477 | token */
        "movzbl (%edx, %ebx), %ecx\n"
        "leal -0x14(%ecx), %edx\n"
        "movl $0x2e, %eax\n" /* line 478 */
        "cmpb $2, %dl\n"
        "cmoval %ecx, %eax\n"
        "movb %al, (%edi)\n" /* charIndex */
        "addl $1, %ebx\n" /* line 475 | ent */
        "addl $1, %edi\n" /* charIndex */
        "cmpl %ebx, %esi\n" /* ent, tokenLen */
        "jne .Lf19a6a2_0019a7f9\n"
        "addl %ebx, -0x24(%ebp)\n" /* ent, stringLen */
        ".Lf19a6a2_0019a81d:\n"
        "addl $1, -0x28(%ebp)\n" /* line 398 | parmIndex */
        "movl -0x28(%ebp), %eax\n" /* parmIndex */
        "cmpl %eax, 0xc(%ebp)\n" /* lastParmIndex */
        "jge .Lf19a6a2_0019a6d2\n"
        "movl -0x24(%ebp), %eax\n" /* stringLen */
        "movl 0x14(%ebp), %edx\n" /* line 485 | string */
        "movb $0, (%eax, %edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 486 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19a6a2_0019a83f:\n"
        "movb $0, -0x19(%ebp)\n" /* line 468 | useLocalization */
        "jmp .Lf19a6a2_0019a7ed\n"
        ".Lf19a6a2_0019a845:\n"
        "movl -0x28(%ebp), %edx\n" /* line 420 | parmIndex */
        "movl %edx, (%esp)\n"
        "calll Scr_GetPointerType\n"
        "cmpl $0x15, %eax\n"
        "jne .Lf19a6a2_0019a6ec\n"
        "movl -0x28(%ebp), %edx\n" /* line 422 | parmIndex */
        "movl %edx, (%esp)\n"
        "calll Scr_GetEntity\n"
        "movl %eax, %ebx\n" /* ent */
        "movl 0x158(%eax), %eax\n" /* line 424 */
        "testl %eax, %eax\n"
        "je .Lf19a6a2_0019a9fe\n"
        ".Lf19a6a2_0019a874:\n"
        "movl 0x158(%ebx), %eax\n" /* line 427 | ent */
        "addl $0x2784, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac668, (%esp)\n" /* "%s^7" */
        "calll va\n"
        "movl %eax, -0x20(%ebp)\n" /* token */
        "cld\n" /* line 428 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n" /* charIndex */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* charIndex */
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* tokenLen */
        "movl -0x24(%ebp), %edx\n" /* line 430 | stringLen */
        "leal 1(%edx, %esi), %eax\n"
        "cmpl %eax, 0x18(%ebp)\n" /* stringLimit */
        "jg .Lf19a6a2_0019a7d3\n"
        ".Lf19a6a2_0019a8b3:\n"
        "movl 0x18(%ebp), %eax\n" /* line 463 | stringLimit */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* errorContext */
        "movl %edx, 4(%esp)\n"
        "movl $str_002b26a4, (%esp)\n" /* "%s is too long. Max length is %i
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* parmIndex */
        "movl %eax, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf19a6a2_0019a7d3\n"
        ".Lf19a6a2_0019a8e1:\n"
        "movl -0x28(%ebp), %edx\n" /* line 405 | parmIndex */
        "movl %edx, (%esp)\n"
        "calll Scr_GetIString\n"
        "movl %eax, -0x20(%ebp)\n" /* token */
        "cld\n" /* line 406 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n" /* charIndex */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* charIndex */
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* tokenLen */
        /* { scope 2 */
        "cmpl $1, %esi\n" /* line 366 */
        "jle .Lf19a6a2_0019a978\n"
        "xorl %edi, %edi\n" /* charIter */
        "jmp .Lf19a6a2_0019a94e\n"
        /* { scope 3 */
        ".Lf19a6a2_0019a909:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "testl $0x500, 0x34(%eax, %edx, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lf19a6a2_0019a91c:\n"
        "testl %eax, %eax\n" /* line 371 */
        "jne .Lf19a6a2_0019a947\n"
        "cmpb $0x5f, (%ebx)\n"
        "je .Lf19a6a2_0019a947\n"
        "movl -0x20(%ebp), %edx\n" /* line 372 | token */
        "movl %edx, 4(%esp)\n"
        "movl $str_002b2640, (%esp)\n" /* "Illegal localized string reference: %s must contain only alp" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* parmIndex */
        "movl %eax, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf19a6a2_0019a947:\n"
        "addl $1, %edi\n" /* line 369 | charIter */
        "cmpl %edi, %esi\n" /* charIter */
        "je .Lf19a6a2_0019a978\n"
        ".Lf19a6a2_0019a94e:\n"
        "movl -0x20(%ebp), %ebx\n" /* line 384 | token */
        "addl %edi, %ebx\n" /* charIter */
        "movsbl (%ebx), %edx\n" /* line 371 | _c */
        /* { scope 3 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf19a6a2_0019a909\n"
        "movl $0x500, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf19a6a2_0019a91c\n"
        /* } scope */
        /* } scope */
        ".Lf19a6a2_0019a978:\n"
        "movl -0x24(%ebp), %edx\n" /* line 409 | stringLen */
        "leal 1(%edx, %esi), %eax\n"
        "cmpl %eax, 0x18(%ebp)\n" /* stringLimit */
        "jle .Lf19a6a2_0019a9d3\n"
        ".Lf19a6a2_0019a984:\n"
        "movl -0x24(%ebp), %eax\n" /* line 412 | stringLen */
        "testl %eax, %eax\n"
        "je .Lf19a6a2_0019a99b\n"
        "movl 0x14(%ebp), %edx\n" /* line 414 | string */
        "movl -0x24(%ebp), %eax\n" /* stringLen */
        "movb $0x14, (%edx, %eax)\n"
        "addl $1, %eax\n" /* line 415 */
        "movl %eax, -0x24(%ebp)\n" /* stringLen */
        ".Lf19a6a2_0019a99b:\n"
        "movb $1, -0x19(%ebp)\n" /* useLocalization */
        "jmp .Lf19a6a2_0019a7ed\n"
        ".Lf19a6a2_0019a9a4:\n"
        "movl -0x20(%ebp), %edx\n" /* line 455 | token */
        "movl %edx, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* errorContext */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b270c, (%esp)\n" /* "non-localized %s strings are not allowed to have letters in " */
        "calll va\n"
        "movl %eax, 4(%esp)\n" /* line 354 */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19a6a2_0019a7c3\n"
        ".Lf19a6a2_0019a9d3:\n"
        "movl 0x18(%ebp), %eax\n" /* line 410 | stringLimit */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* errorContext */
        "movl %edx, 4(%esp)\n"
        "movl $str_002b26a4, (%esp)\n" /* "%s is too long. Max length is %i
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* parmIndex */
        "movl %eax, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf19a6a2_0019a984\n"
        ".Lf19a6a2_0019a9fe:\n"
        "movl $str_002b26c8, 4(%esp)\n" /* line 425 */
        "movl -0x28(%ebp), %eax\n" /* parmIndex */
        "movl %eax, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf19a6a2_0019a874\n"
    );
}

/* line 4834 */
__attribute__((naked))
unsigned int GScr_MakeDvarServerInfo(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4834 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x83c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4846 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* dvarName */
        "movl %eax, (%esp)\n" /* line 4847 */
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 4848 */
        "je .Lf19aa16_0019aa57\n"
        "movl $0x100, 4(%esp)\n" /* line 4850 */
        "movl %eax, (%esp)\n"
        "calll Dvar_AddFlags\n"
        /* } scope */
        "addl $0x83c, %esp\n" /* line 4877 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19aa16_0019aa57:\n"
        "movl $1, (%esp)\n" /* line 4854 */
        "calll Scr_GetType\n"
        "cmpl $3, %eax\n" /* line 4855 */
        "je .Lf19aa16_0019aaf1\n"
        "movl $1, (%esp)\n" /* line 4862 */
        "calll Scr_GetString\n"
        "movl %eax, -0x81c(%ebp)\n" /* dvarValue */
        "movl %eax, %edx\n"
        ".Lf19aa16_0019aa80:\n"
        "movzbl (%edx), %eax\n" /* line 4868 */
        "testb %al, %al\n"
        "jne .Lf19aa16_0019aab5\n"
        "leal -0x818(%ebp), %ecx\n" /* outString */
        ".Lf19aa16_0019aa8d:\n"
        "movb $0, (%ecx)\n" /* line 4874 */
        "movl $0x4100, 8(%esp)\n" /* line 4876 */
        "movl -0x81c(%ebp), %edx\n" /* dvarValue */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* dvarName */
        "calll Dvar_RegisterString_mac\n"
        /* } scope */
        "addl $0x83c, %esp\n" /* line 4877 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19aa16_0019aab5:\n"
        "movl %edx, %ebx\n"
        /* { scope 1 */
        "leal -0x817(%ebp), %esi\n" /* line 4868 */
        ".Lf19aa16_0019aabd:\n"
        "movsbl %al, %eax\n" /* line 4870 */
        "movl %eax, (%esp)\n"
        "calll I_CleanChar\n"
        "movl %esi, %ecx\n" /* line 4834 */
        "movl $0x27, %edx\n" /* line 4872 */
        "cmpb $0x22, %al\n"
        "cmovnel %eax, %edx\n"
        "movb %dl, -1(%esi)\n"
        "leal -0x419(%ebp), %eax\n" /* line 4868 */
        "cmpl %eax, %esi\n"
        "je .Lf19aa16_0019aa8d\n"
        "movzbl 1(%ebx), %eax\n"
        "leal 1(%esi), %esi\n"
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf19aa16_0019aabd\n"
        "jmp .Lf19aa16_0019aa8d\n"
        ".Lf19aa16_0019aaf1:\n"
        "calll Scr_GetNumParam\n" /* line 4857 */
        "movl $0x400, 0x10(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* string */
        "movl %ebx, 0xc(%esp)\n"
        "movl $str_002b27d0, 8(%esp)\n" /* "Dvar Value" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "movl %ebx, -0x81c(%ebp)\n" /* dvarValue */
        "movl %ebx, %edx\n"
        "jmp .Lf19aa16_0019aa80\n"
    );
}

/* line 4242 */
__attribute__((naked))
unsigned int GScr_ClientAnnouncement(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4242 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 4247 */
        "calll Scr_GetEntity\n"
        "movl %eax, %esi\n" /* pEnt */
        "calll Scr_GetNumParam\n" /* line 4248 */
        "movl $0x400, 0x10(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* string */
        "movl %ebx, 0xc(%esp)\n"
        "movl $str_002b27dc, 8(%esp)\n" /* "Announcement" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "movl %ebx, 8(%esp)\n" /* line 4249 */
        "movl $0x63, 4(%esp)\n"
        "movl $str_002b27ec, (%esp)\n" /* "%c "%s" 2" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl (%esi), %eax\n" /* pEnt */
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 4250 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4228 */
unsigned int GScr_Announcement(void)
{
    char string[0x400];
    int numParams = Scr_GetNumParam();
    Scr_ConstructMessageString(0, numParams - 1, "Announcement", string, 0x400);
    SV_GameSendServerCommand(-1, 0, va("%c \"%s\" 2", 0x63, string));
    return 0;
}

/* line 778 */
__attribute__((naked))
unsigned int GScr_SetDvar(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 778 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x83c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 791 */
        "calll Scr_GetString\n"
        "movl %eax, -0x81c(%ebp)\n" /* dvarName */
        "movl $1, (%esp)\n" /* line 793 */
        "calll Scr_GetType\n"
        "cmpl $3, %eax\n" /* line 794 */
        "je .Lf19ac2a_0019ad43\n"
        "movl $1, (%esp)\n" /* line 800 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* dvarValue */
        ".Lf19ac2a_0019ac6b:\n"
        "leal -0x818(%ebp), %edi\n" /* line 805 | outString */
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memset\n"
        "movl $1, %ebx\n"
        "jmp .Lf19ac2a_0019acb4\n"
        ".Lf19ac2a_0019ac90:\n"
        "movsbl %al, %eax\n" /* line 808 */
        "movl %eax, (%esp)\n"
        "calll I_CleanChar\n"
        "movl $0x27, %edx\n" /* line 810 */
        "cmpb $0x22, %al\n"
        "cmovnel %eax, %edx\n"
        "movb %dl, -1(%ebx, %edi)\n"
        "addl $1, %ebx\n"
        "cmpl $0x2001, %ebx\n" /* line 806 */
        "je .Lf19ac2a_0019acbd\n"
        ".Lf19ac2a_0019acb4:\n"
        "movzbl -1(%esi, %ebx), %eax\n" /* dvarValue */
        "testb %al, %al\n"
        "jne .Lf19ac2a_0019ac90\n"
        ".Lf19ac2a_0019acbd:\n"
        "movl -0x81c(%ebp), %eax\n" /* line 813 | dvarName */
        "movl %eax, (%esp)\n"
        "calll Dvar_IsValidName\n"
        "testb %al, %al\n"
        "jne .Lf19ac2a_0019acf8\n"
        "movl -0x81c(%ebp), %eax\n" /* line 815 | dvarName */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b27f8, (%esp)\n" /* "Dvar %s has an invalid dvar name" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        ".Lf19ac2a_0019aced:\n"
        "addl $0x83c, %esp\n" /* line 828 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19ac2a_0019acf8:\n"
        "calll Scr_GetNumParam\n" /* line 819 */
        "cmpl $2, %eax\n"
        "ja .Lf19ac2a_0019ad7c\n"
        ".Lf19ac2a_0019ad02:\n"
        "xorl %ebx, %ebx\n"
        ".Lf19ac2a_0019ad04:\n"
        "movl %esi, 4(%esp)\n" /* line 821 | dvarValue */
        "movl -0x81c(%ebp), %eax\n" /* dvarName */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        "testb %bl, %bl\n" /* line 822 */
        "je .Lf19ac2a_0019aced\n"
        "movl -0x81c(%ebp), %eax\n" /* line 824 | dvarName */
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "movl $0x400, 4(%esp)\n" /* line 826 */
        "movl %eax, (%esp)\n"
        "calll Dvar_AddFlags\n"
        /* } scope */
        "addl $0x83c, %esp\n" /* line 828 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19ac2a_0019ad43:\n"
        "calll Scr_GetNumParam\n" /* line 796 */
        "movl $0x400, 0x10(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* string */
        "movl %ebx, 0xc(%esp)\n"
        "movl $str_002b27d0, 8(%esp)\n" /* "Dvar Value" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "movl %ebx, %esi\n" /* dvarValue */
        "jmp .Lf19ac2a_0019ac6b\n"
        ".Lf19ac2a_0019ad7c:\n"
        "movl $2, (%esp)\n" /* line 819 */
        "calll Scr_GetInt\n"
        "testl %eax, %eax\n"
        "je .Lf19ac2a_0019ad02\n"
        "movl $1, %ebx\n"
        "jmp .Lf19ac2a_0019ad04\n"
    );
}

/* line 494 */
__attribute__((naked))
unsigned int Scr_MakeGameMessage(int iClientNum, const char *pszCmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 494 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x424, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 498 */
        "movl $0x400, 0x10(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* string */
        "movl %ebx, 0xc(%esp)\n"
        "movl $str_002b281c, 8(%esp)\n" /* "Game Message" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "movl %ebx, 8(%esp)\n" /* line 499 */
        "movl 0xc(%ebp), %eax\n" /* pszCmd */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b282c, (%esp)\n" /* "%s "%s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* iClientNum */
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x424, %esp\n" /* line 500 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4928 */
__attribute__((naked))
unsigned int GScr_IsValidGameType(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4928 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 4932 */
        "testl %eax, %eax\n"
        "jne .Lf19ae0e_0019ae28\n"
        /* } scope */
        ".Lf19ae0e_0019ae20:\n"
        "addl $0x2c, %esp\n" /* line 4941 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19ae0e_0019ae28:\n"
        "movl $0, (%esp)\n" /* line 4935 */
        "calll Scr_GetString\n"
        "movl %eax, -0x1c(%ebp)\n" /* gametype */
        /* { scope 2 */
        "movl g_scr_data+40, %edx\n" /* line 6306 */
        "testl %edx, %edx\n"
        "jg .Lf19ae0e_0019ae55\n"
        /* } scope */
        ".Lf19ae0e_0019ae41:\n"
        "movl $0, (%esp)\n" /* line 4940 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 4941 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf19ae0e_0019ae55:\n"
        "xorl %esi, %esi\n" /* line 6306 | i */
        "movl $g_scr_data+108, %edi\n"
        "movl $g_scr_data+44, %ebx\n"
        "jmp .Lf19ae0e_0019ae7a\n"
        ".Lf19ae0e_0019ae63:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x84, %ebx\n"
        "addl $0x84, %edi\n"
        "cmpl g_scr_data+40, %esi\n" /* i */
        "jge .Lf19ae0e_0019ae41\n"
        ".Lf19ae0e_0019ae7a:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 6308 | gametype */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf19ae0e_0019ae63\n"
        /* } scope */
        "testl %edi, %edi\n" /* line 4937 */
        "je .Lf19ae0e_0019ae41\n"
        "movl $1, (%esp)\n" /* line 4938 */
        "calll Scr_AddInt\n"
        "jmp .Lf19ae0e_0019ae20\n"
    );
}

/* line 6323 */
__attribute__((naked))
qboolean Scr_IsValidGameType(const char *pszGameType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6323 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl g_scr_data+40, %ecx\n" /* line 6306 */
        "testl %ecx, %ecx\n"
        "jg .Lf19aea0_0019aec5\n"
        ".Lf19aea0_0019aeb3:\n"
        "xorl %eax, %eax\n"
        ".Lf19aea0_0019aeb5:\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 6334 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19aea0_0019aec5:\n"
        "xorl %esi, %esi\n" /* line 6306 | i */
        "movl $g_scr_data+108, %edi\n"
        "movl $g_scr_data+44, %ebx\n"
        ".Lf19aea0_0019aed1:\n"
        "movl 8(%ebp), %eax\n" /* line 6308 | pszGameType */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf19aea0_0019aefd\n"
        "addl $1, %esi\n" /* line 6306 | i */
        "addl $0x84, %ebx\n"
        "addl $0x84, %edi\n"
        "cmpl %esi, g_scr_data+40\n" /* i */
        "jg .Lf19aea0_0019aed1\n"
        "jmp .Lf19aea0_0019aeb3\n"
        ".Lf19aea0_0019aefd:\n"
        "movl %edi, %eax\n" /* line 6309 */
        "jmp .Lf19aea0_0019aeb5\n"
    );
}

/* line 3152 */
__attribute__((naked))
unsigned int Scr_Length(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3152 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "leal -0x14(%ebp), %eax\n" /* line 3156 | v */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 324 | v */
        "movss -0x10(%ebp), %xmm1\n"
        "movss -0xc(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll Scr_AddFloat\n"
        /* } scope */
        "leave\n" /* line 3158 */
        "retl\n"
    );
}

/* line 335 */
__attribute__((naked))
unsigned int println(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 335 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl imp_g_NoScriptSpam, %eax\n" /* line 337 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf19af4e_0019af6a\n"
        "addl $0x10, %esp\n" /* line 341 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19af4e_0019af6a:\n"
        "calll Scr_GetNumParam\n" /* line 323 */
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 324 */
        "jg .Lf19af4e_0019af88\n"
        ".Lf19af4e_0019af75:\n"
        "movl $str_002160e8, (%esp)\n" /* line 340 */
        "calll Com_Printf\n"
        "addl $0x10, %esp\n" /* line 341 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19af4e_0019af88:\n"
        "xorl %ebx, %ebx\n" /* line 324 */
        ".Lf19af4e_0019af8a:\n"
        "movl %ebx, (%esp)\n" /* line 325 */
        "calll Scr_GetDebugString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 324 */
        "cmpl %ebx, %esi\n"
        "jne .Lf19af4e_0019af8a\n"
        "jmp .Lf19af4e_0019af75\n"
    );
}

/* line 6398 */
__attribute__((naked))
unsigned int Scr_PlayerDamage(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int dflags, int meansOfDeath, int iWeapon, const vec_t *vPoint, const vec_t *vDir, const hitLocation_t hitLoc, int timeOffset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6398 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* self, timeOffset */
        "movl %eax, -0x1c(%ebp)\n" /* timeOffset, self */
        "movl 0xc(%ebp), %edx\n" /* inflictor */
        "movl %edx, -0x20(%ebp)\n" /* inflictor */
        "movl 0x10(%ebp), %eax\n" /* attacker, timeOffset */
        "movl %eax, -0x24(%ebp)\n" /* timeOffset, attacker */
        "movl 0x14(%ebp), %edx\n" /* damage */
        "movl %edx, -0x28(%ebp)\n" /* damage */
        "movl 0x18(%ebp), %eax\n" /* dflags, timeOffset */
        "movl %eax, -0x2c(%ebp)\n" /* timeOffset, dflags */
        "movl 0x1c(%ebp), %edx\n" /* meansOfDeath */
        "movl %edx, -0x30(%ebp)\n" /* meansOfDeath */
        "movl 0x20(%ebp), %eax\n" /* iWeapon, timeOffset */
        "movl %eax, -0x34(%ebp)\n" /* timeOffset, iWeapon */
        "movl 0x24(%ebp), %edi\n" /* vPoint */
        "movl 0x28(%ebp), %esi\n" /* vDir */
        "movl 0x2c(%ebp), %ebx\n" /* hitLoc */
        /* { scope 1 */
        "movl 0x30(%ebp), %eax\n" /* line 6403 | timeOffset */
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl %ebx, (%esp)\n" /* line 6404 | hitLoc */
        "calll G_GetHitLocationString\n"
        "movzwl %ax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        "testl %esi, %esi\n" /* line 6111 */
        "je .Lf19afac_0019b0f8\n"
        "movl %esi, (%esp)\n" /* line 6112 */
        "calll Scr_AddVector\n"
        "testl %edi, %edi\n" /* line 6111 */
        "je .Lf19afac_0019b105\n"
        ".Lf19afac_0019b01e:\n"
        "movl %edi, (%esp)\n" /* line 6112 */
        "calll Scr_AddVector\n"
        ".Lf19afac_0019b026:\n"
        "movl -0x34(%ebp), %edx\n" /* line 6407 | iWeapon */
        "movl %edx, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        "cmpl $0xe, -0x30(%ebp)\n" /* line 6408 | meansOfDeath */
        "jbe .Lf19afac_0019b0b5\n"
        "movl $str_002b2834, (%esp)\n" /* line 6409 */
        "calll Scr_AddString\n"
        "movl -0x2c(%ebp), %eax\n" /* line 6412 | dflags */
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl -0x28(%ebp), %edx\n" /* line 6413 | damage */
        "movl %edx, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl -0x24(%ebp), %esi\n" /* line 6127 | attacker */
        "testl %esi, %esi\n"
        "je .Lf19afac_0019b0e5\n"
        ".Lf19afac_0019b06a:\n"
        "movl -0x24(%ebp), %eax\n" /* line 6128 | attacker */
        "movl %eax, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl -0x20(%ebp), %ebx\n" /* line 6127 | inflictor */
        "testl %ebx, %ebx\n"
        "je .Lf19afac_0019b0f1\n"
        ".Lf19afac_0019b07c:\n"
        "movl -0x20(%ebp), %edx\n" /* line 6128 | inflictor */
        "movl %edx, (%esp)\n"
        "calll Scr_AddEntity\n"
        ".Lf19afac_0019b087:\n"
        "movl $0xa, 8(%esp)\n" /* line 6417 */
        "movl g_scr_data+24, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* self */
        "movl %eax, (%esp)\n"
        "calll Scr_ExecEntThread\n"
        "movzwl %ax, %eax\n" /* line 6418 */
        "movl %eax, 8(%ebp)\n" /* self */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 6419 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_FreeThread\n" /* line 6418 */
        ".Lf19afac_0019b0b5:\n"
        "movl imp_modNames, %eax\n" /* line 6411 */
        "movl -0x30(%ebp), %edx\n" /* meansOfDeath */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        "movl -0x2c(%ebp), %eax\n" /* line 6412 | dflags */
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl -0x28(%ebp), %edx\n" /* line 6413 | damage */
        "movl %edx, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl -0x24(%ebp), %esi\n" /* line 6127 | attacker */
        "testl %esi, %esi\n"
        "jne .Lf19afac_0019b06a\n"
        ".Lf19afac_0019b0e5:\n"
        "calll Scr_AddUndefined\n" /* line 6130 */
        "movl -0x20(%ebp), %ebx\n" /* line 6127 | inflictor */
        "testl %ebx, %ebx\n"
        "jne .Lf19afac_0019b07c\n"
        ".Lf19afac_0019b0f1:\n"
        "calll Scr_AddUndefined\n" /* line 6130 */
        "jmp .Lf19afac_0019b087\n"
        ".Lf19afac_0019b0f8:\n"
        "calll Scr_AddUndefined\n" /* line 6114 */
        "testl %edi, %edi\n" /* line 6111 */
        "jne .Lf19afac_0019b01e\n"
        ".Lf19afac_0019b105:\n"
        "calll Scr_AddUndefined\n" /* line 6114 */
        "jmp .Lf19afac_0019b026\n"
    );
}

/* line 6427 */
__attribute__((naked))
unsigned int Scr_PlayerKilled(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int meansOfDeath, int iWeapon, const vec_t *vDir, const hitLocation_t hitLoc, int psTimeOffset, int deathAnimDuration)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 6427 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* self, deathAnimDuration */
        "movl %eax, -0x1c(%ebp)\n" /* deathAnimDuration, self */
        "movl 0xc(%ebp), %edx\n" /* inflictor */
        "movl %edx, -0x20(%ebp)\n" /* inflictor */
        "movl 0x10(%ebp), %eax\n" /* attacker, deathAnimDuration */
        "movl %eax, -0x24(%ebp)\n" /* deathAnimDuration, attacker */
        "movl 0x14(%ebp), %edx\n" /* damage */
        "movl %edx, -0x28(%ebp)\n" /* damage */
        "movl 0x18(%ebp), %eax\n" /* meansOfDeath, deathAnimDuration */
        "movl %eax, -0x2c(%ebp)\n" /* deathAnimDuration, meansOfDeath */
        "movl 0x1c(%ebp), %edx\n" /* iWeapon */
        "movl %edx, -0x30(%ebp)\n" /* iWeapon */
        "movl 0x20(%ebp), %edi\n" /* vDir */
        "movl 0x24(%ebp), %esi\n" /* hitLoc */
        "movl 0x28(%ebp), %ebx\n" /* psTimeOffset */
        /* { scope 1 */
        "movl 0x2c(%ebp), %eax\n" /* line 6432 | deathAnimDuration */
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl %ebx, (%esp)\n" /* line 6433 | psTimeOffset */
        "calll Scr_AddInt\n"
        "movl %esi, (%esp)\n" /* line 6434 | hitLoc */
        "calll G_GetHitLocationString\n"
        "movzwl %ax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        "testl %edi, %edi\n" /* line 6111 */
        "je .Lf19b110_0019b238\n"
        "movl %edi, (%esp)\n" /* line 6112 */
        "calll Scr_AddVector\n"
        ".Lf19b110_0019b17c:\n"
        "movl -0x30(%ebp), %eax\n" /* line 6436 | iWeapon */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        "cmpl $0xe, -0x2c(%ebp)\n" /* line 6437 | meansOfDeath */
        "jbe .Lf19b110_0019b200\n"
        "movl $str_002b2834, (%esp)\n" /* line 6438 */
        "calll Scr_AddString\n"
        "movl -0x28(%ebp), %eax\n" /* line 6441 | damage */
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl -0x24(%ebp), %eax\n" /* line 6127 | attacker */
        "testl %eax, %eax\n"
        "je .Lf19b110_0019b225\n"
        ".Lf19b110_0019b1b5:\n"
        "movl -0x24(%ebp), %edx\n" /* line 6128 | attacker */
        "movl %edx, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl -0x20(%ebp), %edi\n" /* line 6127 | inflictor */
        "testl %edi, %edi\n"
        "je .Lf19b110_0019b231\n"
        ".Lf19b110_0019b1c7:\n"
        "movl -0x20(%ebp), %eax\n" /* line 6128 | inflictor */
        "movl %eax, (%esp)\n"
        "calll Scr_AddEntity\n"
        ".Lf19b110_0019b1d2:\n"
        "movl $9, 8(%esp)\n" /* line 6445 */
        "movl g_scr_data+28, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* self */
        "movl %edx, (%esp)\n"
        "calll Scr_ExecEntThread\n"
        "movzwl %ax, %eax\n" /* line 6446 */
        "movl %eax, 8(%ebp)\n" /* self */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 6447 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_FreeThread\n" /* line 6446 */
        ".Lf19b110_0019b200:\n"
        "movl imp_modNames, %eax\n" /* line 6440 */
        "movl -0x2c(%ebp), %edx\n" /* meansOfDeath */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddString\n"
        "movl -0x28(%ebp), %eax\n" /* line 6441 | damage */
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl -0x24(%ebp), %eax\n" /* line 6127 | attacker */
        "testl %eax, %eax\n"
        "jne .Lf19b110_0019b1b5\n"
        ".Lf19b110_0019b225:\n"
        "calll Scr_AddUndefined\n" /* line 6130 */
        "movl -0x20(%ebp), %edi\n" /* line 6127 | inflictor */
        "testl %edi, %edi\n"
        "jne .Lf19b110_0019b1c7\n"
        ".Lf19b110_0019b231:\n"
        "calll Scr_AddUndefined\n" /* line 6130 */
        "jmp .Lf19b110_0019b1d2\n"
        ".Lf19b110_0019b238:\n"
        "calll Scr_AddUndefined\n" /* line 6114 */
        "jmp .Lf19b110_0019b17c\n"
    );
}

/* line 1718 */
__attribute__((naked))
unsigned int ScrCmd_Show(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1718 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b242_0019b28d\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "andl $0xfffff7ff, 0x174(%edx)\n" /* line 1723 */
        "movl $0, 0xf4(%edx)\n" /* line 1724 */
        "movl $0, 0xf8(%edx)\n" /* line 1725 */
        /* } scope */
        "leave\n" /* line 1726 */
        "retl\n"
        /* { scope 1 */
        ".Lf19b242_0019b28d:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "andl $0xfffff7ff, 0x174(%edx)\n" /* line 1723 */
        "movl $0, 0xf4(%edx)\n" /* line 1724 */
        "movl $0, 0xf8(%edx)\n" /* line 1725 */
        /* } scope */
        "leave\n" /* line 1726 */
        "retl\n"
    );
}

/* line 1734 */
__attribute__((naked))
unsigned int ScrCmd_Hide(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1734 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b2bc_0019b307\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "orl $0x800, 0x174(%edx)\n" /* line 1739 */
        "movl $0xffffffff, 0xf4(%edx)\n" /* line 1740 */
        "movl $0xffffffff, 0xf8(%edx)\n" /* line 1741 */
        /* } scope */
        "leave\n" /* line 1742 */
        "retl\n"
        /* { scope 1 */
        ".Lf19b2bc_0019b307:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "orl $0x800, 0x174(%edx)\n" /* line 1739 */
        "movl $0xffffffff, 0xf4(%edx)\n" /* line 1740 */
        "movl $0xffffffff, 0xf8(%edx)\n" /* line 1741 */
        /* } scope */
        "leave\n" /* line 1742 */
        "retl\n"
    );
}

/* line 1750 */
__attribute__((naked))
unsigned int ScrCmd_ShowToPlayer(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1750 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b336_0019b39b\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        "movl $0, (%esp)\n" /* line 1756 */
        "calll Scr_GetEntity\n"
        "cmpl $0x3f, (%eax)\n" /* line 1758 */
        "jg .Lf19b336_0019b3ba\n"
        ".Lf19b336_0019b373:\n"
        "andl $0xfffff7ff, 0x174(%ebx)\n" /* line 1764 | pEnt */
        "movl (%eax), %ecx\n" /* line 1765 */
        "movl %ecx, %edx\n"
        "sarl $5, %edx\n"
        "andl $0x1f, %ecx\n"
        "movl $0xfffffffe, %eax\n"
        "roll %cl, %eax\n"
        "andl %eax, 0xf4(%ebx, %edx, 4)\n" /* pEnt */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1767 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19b336_0019b39b:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "movl $0, (%esp)\n" /* line 1756 */
        "calll Scr_GetEntity\n"
        "cmpl $0x3f, (%eax)\n" /* line 1758 */
        "jle .Lf19b336_0019b373\n"
        ".Lf19b336_0019b3ba:\n"
        "movl $str_002b283c, 8(%ebp)\n" /* line 1760 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1767 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 1760 */
    );
}

/* line 1948 */
__attribute__((naked))
unsigned int GScr_EnableGrenadeTouchDamage(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1948 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b3cc_0019b426\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19b3cc_0019b3f8:\n"
        "movzwl 0x168(%ebx), %edx\n" /* line 1952 | ent */
        "movl imp_scr_const, %eax\n"
        "cmpw 0x5a(%eax), %dx\n"
        "je .Lf19b3cc_0019b416\n"
        "movl $str_002b2870, (%esp)\n" /* line 1953 */
        "calll Scr_Error\n"
        ".Lf19b3cc_0019b416:\n"
        "orl $0x4000, 0x174(%ebx)\n" /* line 1955 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1956 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19b3cc_0019b426:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19b3cc_0019b3f8\n"
    );
}

/* line 1964 */
__attribute__((naked))
unsigned int GScr_DisableGrenadeTouchDamage(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1964 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b436_0019b490\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19b436_0019b462:\n"
        "movzwl 0x168(%ebx), %edx\n" /* line 1968 | ent */
        "movl imp_scr_const, %eax\n"
        "cmpw 0x5a(%eax), %dx\n"
        "je .Lf19b436_0019b480\n"
        "movl $str_002b2870, (%esp)\n" /* line 1969 */
        "calll Scr_Error\n"
        ".Lf19b436_0019b480:\n"
        "andl $0xffffbfff, 0x174(%ebx)\n" /* line 1971 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1972 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19b436_0019b490:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19b436_0019b462\n"
    );
}

/* line 1980 */
__attribute__((naked))
unsigned int GScr_EnableGrenadeBounce(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1980 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b4a0_0019b4d7\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "andl $0xffff7fff, 0x174(%edx)\n" /* line 1984 */
        /* } scope */
        "leave\n" /* line 1985 */
        "retl\n"
        /* { scope 1 */
        ".Lf19b4a0_0019b4d7:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "andl $0xffff7fff, 0x174(%edx)\n" /* line 1984 */
        /* } scope */
        "leave\n" /* line 1985 */
        "retl\n"
    );
}

/* line 1993 */
__attribute__((naked))
unsigned int GScr_DisableGrenadeBounce(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1993 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b4f2_0019b529\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "orl $0x8000, 0x174(%edx)\n" /* line 1997 */
        /* } scope */
        "leave\n" /* line 1998 */
        "retl\n"
        /* { scope 1 */
        ".Lf19b4f2_0019b529:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "orl $0x8000, 0x174(%edx)\n" /* line 1997 */
        /* } scope */
        "leave\n" /* line 1998 */
        "retl\n"
    );
}

/* line 2001 */
__attribute__((naked))
unsigned int GScr_EnableAimAssist(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2001 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b544_0019b592\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19b544_0019b570:\n"
        "cmpb $0, 0xf1(%ebx)\n" /* line 2007 | ent */
        "jne .Lf19b544_0019b585\n"
        "movl $str_002b289c, (%esp)\n" /* line 2008 */
        "calll Scr_Error\n"
        ".Lf19b544_0019b585:\n"
        "orl $0x800, 8(%ebx)\n" /* line 2010 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 2011 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19b544_0019b592:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19b544_0019b570\n"
    );
}

/* line 2014 */
__attribute__((naked))
unsigned int GScr_DisableAimAssist(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2014 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b5a2_0019b5f0\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19b5a2_0019b5ce:\n"
        "cmpb $0, 0xf1(%ebx)\n" /* line 2020 | ent */
        "jne .Lf19b5a2_0019b5e3\n"
        "movl $str_002b289c, (%esp)\n" /* line 2021 */
        "calll Scr_Error\n"
        ".Lf19b5a2_0019b5e3:\n"
        "andl $0xfffff7ff, 8(%ebx)\n" /* line 2023 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 2024 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19b5a2_0019b5f0:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19b5a2_0019b5ce\n"
    );
}

/* line 1048 */
__attribute__((naked))
unsigned int ScrCmd_attach(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1048 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b600_0019b711\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19b600_0019b632:\n"
        "movl $0, (%esp)\n" /* line 1057 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* modelName */
        "calll Scr_GetNumParam\n" /* line 1058 */
        "cmpl $1, %eax\n"
        "jbe .Lf19b600_0019b6b3\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetConstLowercaseString\n"
        "movl %eax, %esi\n" /* tagName */
        "calll Scr_GetNumParam\n" /* line 1059 */
        "cmpl $2, %eax\n"
        "ja .Lf19b600_0019b6c5\n"
        ".Lf19b600_0019b662:\n"
        "movl $0, -0x1c(%ebp)\n" /* ignoreCollision */
        "movl %esi, 8(%esp)\n" /* line 1062 | tagName */
        "movl %edi, 4(%esp)\n" /* modelName */
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_EntDetach\n"
        "testl %eax, %eax\n"
        "jne .Lf19b600_0019b6e8\n"
        ".Lf19b600_0019b67d:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1065 | ignoreCollision */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* tagName */
        "movl %edi, 4(%esp)\n" /* modelName */
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_EntAttach\n"
        "testl %eax, %eax\n"
        "je .Lf19b600_0019b6a0\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1067 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19b600_0019b6a0:\n"
        "movl $str_002b28fc, 8(%ebp)\n" /* line 1066 | entref */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1067 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 1066 */
        ".Lf19b600_0019b6b3:\n"
        "movl imp_scr_const, %eax\n" /* line 1058 */
        "movzwl (%eax), %esi\n" /* tagName */
        "calll Scr_GetNumParam\n" /* line 1059 */
        "cmpl $2, %eax\n"
        "jbe .Lf19b600_0019b662\n"
        ".Lf19b600_0019b6c5:\n"
        "movl $2, (%esp)\n"
        "calll Scr_GetInt\n"
        "movl %eax, -0x1c(%ebp)\n" /* ignoreCollision */
        "movl %esi, 8(%esp)\n" /* line 1062 | tagName */
        "movl %edi, 4(%esp)\n" /* modelName */
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_EntDetach\n"
        "testl %eax, %eax\n"
        "je .Lf19b600_0019b67d\n"
        ".Lf19b600_0019b6e8:\n"
        "movl %esi, (%esp)\n" /* line 1063 | tagName */
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* modelName */
        "movl $str_002b28d4, (%esp)\n" /* "model '%s' already attached to tag '%s'" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf19b600_0019b67d\n"
        ".Lf19b600_0019b711:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19b600_0019b632\n"
    );
}

/* line 1075 */
__attribute__((naked))
unsigned int ScrCmd_detach(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1075 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b724_0019b858\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19b724_0019b756:\n"
        "movl $0, (%esp)\n" /* line 1084 */
        "calll Scr_GetString\n"
        "movl %eax, -0x24(%ebp)\n" /* modelName */
        "calll Scr_GetNumParam\n" /* line 1085 */
        "cmpl $1, %eax\n"
        "jbe .Lf19b724_0019b848\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetConstLowercaseString\n"
        "movl %eax, -0x20(%ebp)\n" /* tagName */
        ".Lf19b724_0019b782:\n"
        "movl %eax, 8(%esp)\n" /* line 1087 */
        "movl -0x24(%ebp), %eax\n" /* modelName */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_EntDetach\n"
        "testl %eax, %eax\n"
        "je .Lf19b724_0019b7a1\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1102 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19b724_0019b7a1:\n"
        "movl $str_002b2920, (%esp)\n" /* line 1090 */
        "calll Com_Printf\n"
        "movl %ebx, %edi\n" /* ent */
        "movl %ebx, %esi\n" /* ent */
        "movl $7, -0x1c(%ebp)\n"
        "jmp .Lf19b724_0019b7c6\n"
        ".Lf19b724_0019b7ba:\n"
        "addl $1, %esi\n" /* line 1098 */
        "addl $2, %edi\n"
        "subl $1, -0x1c(%ebp)\n" /* line 1091 */
        "je .Lf19b724_0019b817\n"
        ".Lf19b724_0019b7c6:\n"
        "cmpb $0, 0x210(%esi)\n" /* line 1093 */
        "je .Lf19b724_0019b7ba\n"
        "movzwl 0x218(%edi), %eax\n" /* line 1095 */
        "testw %ax, %ax\n"
        "je .Lf19b724_0019b7ba\n"
        "movzwl %ax, %eax\n" /* line 1098 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n" /* ent */
        "movzbl 0x210(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %ebx, 8(%esp)\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2938, (%esp)\n" /* "model: '%s', tag: '%s'
" */
        "calll Com_Printf\n"
        "addl $1, %esi\n"
        "addl $2, %edi\n"
        "subl $1, -0x1c(%ebp)\n" /* line 1091 */
        "jne .Lf19b724_0019b7c6\n"
        ".Lf19b724_0019b817:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1101 | tagName */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* modelName */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2950, (%esp)\n" /* "failed to detach model '%s' from tag '%s'" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1102 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 1101 */
        ".Lf19b724_0019b848:\n"
        "movl imp_scr_const, %eax\n" /* line 1085 */
        "movzwl (%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* tagName */
        "jmp .Lf19b724_0019b782\n"
        ".Lf19b724_0019b858:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19b724_0019b756\n"
    );
}

/* line 1110 */
__attribute__((naked))
unsigned int ScrCmd_detachAll(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1110 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b86c_0019b8a0\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "movl %edx, 8(%ebp)\n" /* line 1115 | entref */
        /* } scope */
        "leave\n" /* line 1116 */
        /* { scope 1 */
        "jmp G_EntDetachAll\n" /* line 1115 */
        ".Lf19b86c_0019b8a0:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "movl %edx, 8(%ebp)\n" /* line 1115 | entref */
        /* } scope */
        "leave\n" /* line 1116 */
        /* { scope 1 */
        "jmp G_EntDetachAll\n" /* line 1115 */
    );
}

/* line 1124 */
__attribute__((naked))
unsigned int ScrCmd_GetAttachSize(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1124 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b8b8_0019b904\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        ".Lf19b8b8_0019b8e3:\n"
        "movl %edx, %eax\n" /* line 177 */
        "xorl %edx, %edx\n"
        ".Lf19b8b8_0019b8e7:\n"
        "cmpb $0, 0x210(%eax)\n" /* line 1133 */
        "je .Lf19b8b8_0019b8fb\n"
        "addl $1, %edx\n" /* line 1131 */
        "addl $1, %eax\n"
        "cmpl $7, %edx\n"
        "jne .Lf19b8b8_0019b8e7\n"
        ".Lf19b8b8_0019b8fb:\n"
        "movl %edx, 8(%ebp)\n" /* line 1137 | entref */
        /* } scope */
        "leave\n" /* line 1138 */
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1137 */
        ".Lf19b8b8_0019b904:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "jmp .Lf19b8b8_0019b8e3\n"
    );
}

/* line 1146 */
__attribute__((naked))
unsigned int ScrCmd_GetAttachModelName(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1146 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b914_0019b990\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19b914_0019b941:\n"
        "movl $0, (%esp)\n" /* line 1153 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* i */
        "cmpl $6, %eax\n" /* line 1154 */
        "ja .Lf19b914_0019b95e\n"
        "cmpb $0, 0x210(%eax, %ebx)\n"
        "jne .Lf19b914_0019b972\n"
        ".Lf19b914_0019b95e:\n"
        "movl $str_002b297c, 4(%esp)\n" /* line 1155 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf19b914_0019b972:\n"
        "movzbl 0x210(%esi, %ebx), %eax\n" /* line 1157 | i */
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1158 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 1157 */
        ".Lf19b914_0019b990:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19b914_0019b941\n"
    );
}

/* line 1166 */
__attribute__((naked))
unsigned int ScrCmd_GetAttachTagName(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1166 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19b9a0_0019ba14\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19b9a0_0019b9cd:\n"
        "movl $0, (%esp)\n" /* line 1173 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* i */
        "cmpl $6, %eax\n" /* line 1174 */
        "ja .Lf19b9a0_0019b9ea\n"
        "cmpb $0, 0x210(%eax, %ebx)\n"
        "jne .Lf19b9a0_0019b9fe\n"
        ".Lf19b9a0_0019b9ea:\n"
        "movl $str_002b297c, 4(%esp)\n" /* line 1175 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf19b9a0_0019b9fe:\n"
        "movzwl 0x218(%ebx, %esi, 2), %eax\n" /* line 1178 | ent */
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1179 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddConstString\n" /* line 1178 */
        ".Lf19b9a0_0019ba14:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19b9a0_0019b9cd\n"
    );
}

/* line 1187 */
__attribute__((naked))
unsigned int ScrCmd_GetAttachIgnoreCollision(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1187 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19ba24_0019ba9e\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19ba24_0019ba51:\n"
        "movl $0, (%esp)\n" /* line 1194 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* i */
        "cmpl $6, %eax\n" /* line 1195 */
        "ja .Lf19ba24_0019ba6e\n"
        "cmpb $0, 0x210(%eax, %ebx)\n"
        "jne .Lf19ba24_0019ba82\n"
        ".Lf19ba24_0019ba6e:\n"
        "movl $str_002b297c, 4(%esp)\n" /* line 1196 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf19ba24_0019ba82:\n"
        "movzbl 0x165(%ebx), %eax\n" /* line 1198 | ent */
        "movl %esi, %ecx\n" /* i */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1199 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddBool\n" /* line 1198 */
        ".Lf19ba24_0019ba9e:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19ba24_0019ba51\n"
    );
}

/* line 1207 */
__attribute__((naked))
unsigned int ScrCmd_LinkTo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1207 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19baae_0019bcb2\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edi\n"
        "subl %eax, %edi\n"
        "shll $4, %edi\n"
        "addl imp_g_entities, %edi\n"
        "movl $0, (%esp)\n" /* line 1218 */
        "calll Scr_GetType\n"
        "subl $1, %eax\n"
        "je .Lf19baae_0019bcd5\n"
        ".Lf19baae_0019baf5:\n"
        "movl $str_002b21c8, 4(%esp)\n" /* line 1219 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        ".Lf19baae_0019bb09:\n"
        "testb $0x10, 0x175(%edi)\n" /* line 1221 | ent */
        "je .Lf19baae_0019bcef\n"
        ".Lf19baae_0019bb16:\n"
        "movl $0, (%esp)\n" /* line 1224 */
        "calll Scr_GetEntity\n"
        "movl %eax, -0x40(%ebp)\n" /* parent */
        "calll Scr_GetNumParam\n" /* line 1225 */
        "movl %eax, %ebx\n" /* numParam */
        "cmpl $1, %eax\n" /* line 1227 */
        "jle .Lf19baae_0019bbdd\n"
        "movl $1, (%esp)\n" /* line 1229 */
        "calll Scr_GetConstLowercaseString\n"
        "movl %eax, -0x3c(%ebp)\n" /* tagName */
        "movl %eax, (%esp)\n" /* line 1230 */
        "calll SL_ConvertToString\n"
        "cmpb $0, (%eax)\n"
        "je .Lf19baae_0019bbdd\n"
        "cmpl $2, %ebx\n" /* line 1234 | numParam */
        "jg .Lf19baae_0019bbed\n"
        ".Lf19baae_0019bb5e:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1236 | tagName */
        "movl %eax, 8(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* parent */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_EntLinkTo\n"
        "testl %eax, %eax\n"
        "jne .Lf19baae_0019bbd5\n"
        "movl -0x40(%ebp), %eax\n" /* line 1247 | parent */
        "movl %eax, (%esp)\n"
        "calll SV_DObjExists\n"
        "testl %eax, %eax\n"
        "jne .Lf19baae_0019bbbe\n"
        ".Lf19baae_0019bb87:\n"
        "movl -0x40(%ebp), %edx\n" /* line 1249 | parent */
        "cmpb $0, 0x164(%edx)\n"
        "je .Lf19baae_0019bd1b\n"
        ".Lf19baae_0019bb97:\n"
        "movzbl 0x164(%edx), %eax\n" /* line 1251 */
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b29f4, (%esp)\n" /* "failed to link entity since parent model '%s' is invalid" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf19baae_0019bbbe:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1256 | tagName */
        "testl %eax, %eax\n"
        "jne .Lf19baae_0019bc4d\n"
        ".Lf19baae_0019bbc9:\n"
        "movl $str_002b2a7c, (%esp)\n" /* line 1262 */
        "calll Scr_Error\n"
        /* } scope */
        ".Lf19baae_0019bbd5:\n"
        "addl $0x5c, %esp\n" /* line 1263 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19baae_0019bbdd:\n"
        "movl $0, -0x3c(%ebp)\n" /* line 1230 | tagName */
        "cmpl $2, %ebx\n" /* line 1234 | numParam */
        "jle .Lf19baae_0019bb5e\n"
        ".Lf19baae_0019bbed:\n"
        "leal -0x24(%ebp), %esi\n" /* line 1241 | originOffset */
        "movl %esi, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x30(%ebp), %ebx\n" /* line 1242 | anglesOffset, numParam */
        "movl %ebx, 4(%esp)\n" /* numParam */
        "movl $3, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl %ebx, 0x10(%esp)\n" /* line 1243 | numParam */
        "movl %esi, 0xc(%esp)\n"
        "movl -0x3c(%ebp), %eax\n" /* tagName */
        "movl %eax, 8(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* parent */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_EntLinkToWithOffset\n"
        "testl %eax, %eax\n"
        "jne .Lf19baae_0019bbd5\n"
        "movl -0x40(%ebp), %eax\n" /* line 1247 | parent */
        "movl %eax, (%esp)\n"
        "calll SV_DObjExists\n"
        "testl %eax, %eax\n"
        "jne .Lf19baae_0019bbbe\n"
        "jmp .Lf19baae_0019bb87\n"
        ".Lf19baae_0019bc4d:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1256 | tagName */
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* parent */
        "movl %edx, (%esp)\n"
        "calll SV_DObjGetBoneIndex\n"
        "testl %eax, %eax\n"
        "jns .Lf19baae_0019bbc9\n"
        "movl -0x40(%ebp), %eax\n" /* line 1258 | parent */
        "movl %eax, (%esp)\n"
        "calll SV_DObjDumpInfo\n"
        "movl -0x40(%ebp), %edx\n" /* line 1259 | parent */
        "movzbl 0x164(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, %ebx\n" /* numParam */
        "movl -0x3c(%ebp), %eax\n" /* tagName */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 8(%esp)\n" /* numParam */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2a30, (%esp)\n" /* "failed to link entity since tag '%s' does not exist in paren" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf19baae_0019bbc9\n"
        ".Lf19baae_0019bcb2:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n"
        "movl $0, (%esp)\n" /* line 1218 */
        "calll Scr_GetType\n"
        "subl $1, %eax\n"
        "jne .Lf19baae_0019baf5\n"
        ".Lf19baae_0019bcd5:\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetPointerType\n"
        "cmpl $0x15, %eax\n"
        "jne .Lf19baae_0019baf5\n"
        "jmp .Lf19baae_0019bb09\n"
        ".Lf19baae_0019bcef:\n"
        "movzwl 0x168(%edi), %eax\n" /* line 1222 | ent */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2988, (%esp)\n" /* "entity (classname: '%s') does not currently support linkTo" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        "jmp .Lf19baae_0019bb16\n"
        ".Lf19baae_0019bd1b:\n"
        "movl $str_002b29c4, (%esp)\n" /* line 1250 */
        "calll Scr_Error\n"
        "movl -0x40(%ebp), %edx\n" /* parent */
        "jmp .Lf19baae_0019bb97\n"
    );
}

/* line 1271 */
__attribute__((naked))
unsigned int ScrCmd_Unlink(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1271 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19bd30_0019bd64\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "movl %edx, 8(%ebp)\n" /* line 1277 | entref */
        /* } scope */
        "leave\n" /* line 1278 */
        /* { scope 1 */
        "jmp G_EntUnlink\n" /* line 1277 */
        ".Lf19bd30_0019bd64:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "movl %edx, 8(%ebp)\n" /* line 1277 | entref */
        /* } scope */
        "leave\n" /* line 1278 */
        /* { scope 1 */
        "jmp G_EntUnlink\n" /* line 1277 */
    );
}

/* line 1286 */
__attribute__((naked))
unsigned int ScrCmd_EnableLinkTo(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1286 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19bd7c_0019bdf8\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        "testb $0x10, 0x175(%ebx)\n" /* line 1292 | ent */
        "jne .Lf19bd7c_0019be0f\n"
        ".Lf19bd7c_0019bdb1:\n"
        "movl 4(%ebx), %eax\n" /* line 1295 | ent */
        "testl %eax, %eax\n"
        "jne .Lf19bd7c_0019bdc1\n"
        "cmpb $0, 0x160(%ebx)\n" /* ent */
        "je .Lf19bd7c_0019bde8\n"
        ".Lf19bd7c_0019bdc1:\n"
        "movzwl 0x168(%ebx), %eax\n" /* line 1296 | ent */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2ac8, (%esp)\n" /* "entity (classname: '%s') does not currently support enableLi" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ObjectError\n"
        ".Lf19bd7c_0019bde8:\n"
        "orl $__mh_execute_header, 0x174(%ebx)\n" /* line 1300 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1301 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19bd7c_0019bdf8:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "testb $0x10, 0x175(%ebx)\n" /* line 1292 | ent */
        "je .Lf19bd7c_0019bdb1\n"
        ".Lf19bd7c_0019be0f:\n"
        "movl $str_002b2aa4, (%esp)\n" /* line 1293 */
        "calll Scr_ObjectError\n"
        "jmp .Lf19bd7c_0019bdb1\n"
    );
}

/* line 1309 */
__attribute__((naked))
unsigned int ScrCmd_GetOrigin(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1309 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19be1e_0019be71\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ecx\n"
        "subl %eax, %ecx\n"
        "shll $4, %ecx\n"
        "addl imp_g_entities, %ecx\n"
        "leal 0x138(%ecx), %edx\n" /* line 177 */
        /* { scope 2 */
        "movl 0x138(%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n" /* origin */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        /* } scope */
        "leal -0x14(%ebp), %eax\n" /* line 1317 | origin */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        /* } scope */
        "leave\n" /* line 1318 */
        "retl\n"
        /* { scope 1 */
        ".Lf19be1e_0019be71:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ecx, %ecx\n"
        "leal 0x138(%ecx), %edx\n"
        /* { scope 2 */
        "movl 0x138(%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n" /* origin */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        /* } scope */
        "leal -0x14(%ebp), %eax\n" /* line 1317 | origin */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        /* } scope */
        "leave\n" /* line 1318 */
        "retl\n"
    );
}

/* line 1326 */
__attribute__((naked))
unsigned int ScrCmd_GetEye(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1326 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19bea8_0019bf07\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ecx\n"
        "subl %eax, %ecx\n"
        "shll $4, %ecx\n"
        "addl imp_g_entities, %ecx\n"
        ".Lf19bea8_0019bed3:\n"
        "leal 0x138(%ecx), %edx\n" /* line 177 */
        /* { scope 2 */
        "movl 0x138(%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n" /* eye */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        /* } scope */
        "movss lit4_002ed73c, %xmm0\n" /* line 1333 | 40.0f */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "leal -0x14(%ebp), %eax\n" /* line 1334 | eye */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        /* } scope */
        "leave\n" /* line 1335 */
        "retl\n"
        /* { scope 1 */
        ".Lf19bea8_0019bf07:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf19bea8_0019bed3\n"
    );
}

/* line 1345 */
__attribute__((naked))
unsigned int ScrCmd_UseBy(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1345 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19bf18_0019bfa6\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19bf18_0019bf45:\n"
        "movl $0, (%esp)\n" /* line 1352 */
        "calll Scr_GetEntity\n"
        "movl %eax, %esi\n" /* pOther */
        "movl %eax, (%esp)\n" /* line 1355 */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 1356 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pEnt */
        "calll Scr_Notify\n"
        "movzbl 0x166(%ebx), %eax\n" /* line 1358 | pEnt */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl imp_entityHandlers, %eax\n"
        "movl 0x10(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 1359 */
        "je .Lf19bf18_0019bf9f\n"
        "movl %esi, 8(%esp)\n" /* line 1360 | pOther */
        "movl %esi, 4(%esp)\n" /* pOther */
        "movl %ebx, (%esp)\n" /* pEnt */
        "calll *%eax\n"
        /* } scope */
        ".Lf19bf18_0019bf9f:\n"
        "addl $0x10, %esp\n" /* line 1361 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19bf18_0019bfa6:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19bf18_0019bf45\n"
    );
}

/* line 1791 */
__attribute__((naked))
unsigned int Scr_SetStableMissile(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1791 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19bfb6_0019c029\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19bfb6_0019bfe3:\n"
        "movl $0, (%esp)\n" /* line 1797 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* stableMissile */
        "cmpl $1, 4(%ebx)\n" /* line 1799 | ent */
        "je .Lf19bfb6_0019c003\n"
        "movl $str_002b2b0c, (%esp)\n" /* line 1800 */
        "calll Scr_Error\n"
        ".Lf19bfb6_0019c003:\n"
        "testl %esi, %esi\n" /* line 1802 | stableMissile */
        "je .Lf19bfb6_0019c018\n"
        "orl $0x20000, 0x174(%ebx)\n" /* line 1803 | ent */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1806 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19bfb6_0019c018:\n"
        "andl $0xfffdffff, 0x174(%ebx)\n" /* line 1805 | ent */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1806 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19bfb6_0019c029:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19bfb6_0019bfe3\n"
    );
}

/* line 1369 */
__attribute__((naked))
unsigned int ScrCmd_IsTouching(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1369 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c03a_0019c179\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n"
        "subl %eax, %esi\n"
        "shll $4, %esi\n"
        "addl imp_g_entities, %esi\n"
        ".Lf19c03a_0019c06c:\n"
        "cmpb $0, 0xf1(%esi)\n" /* line 1379 | pEnt */
        "jne .Lf19c03a_0019c084\n"
        "movzbl 0xf2(%esi), %eax\n" /* pEnt */
        "testb $0x60, %al\n"
        "je .Lf19c03a_0019c164\n"
        ".Lf19c03a_0019c084:\n"
        "movl $0, (%esp)\n" /* line 1382 */
        "calll Scr_GetEntity\n"
        "movl %eax, %ebx\n"
        "cmpb $0, 0xf1(%eax)\n" /* line 1383 */
        "jne .Lf19c03a_0019c0a6\n"
        "movzbl 0xf2(%eax), %eax\n"
        "testb $0x60, %al\n"
        "je .Lf19c03a_0019c0b2\n"
        ".Lf19c03a_0019c0a6:\n"
        "movl $str_002b2b24, (%esp)\n" /* line 1384 */
        "calll Scr_Error\n"
        ".Lf19c03a_0019c0b2:\n"
        "movl %esi, %edi\n" /* pEnt, pOther */
        ".Lf19c03a_0019c0b4:\n"
        "leal 0x104(%ebx), %eax\n" /* line 1396 | b */
        /* { scope 2 */
        "movss 0x138(%ebx), %xmm0\n" /* line 240 */
        "addss 0x104(%ebx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* vMins */
        "movss 0x13c(%ebx), %xmm0\n" /* line 241 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 0x140(%ebx), %xmm0\n" /* line 242 */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal 0x110(%ebx), %eax\n"
        /* } scope */
        /* { scope 2 */
        "movss 0x138(%ebx), %xmm0\n" /* line 240 */
        "addss 0x110(%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* vMaxs */
        "movss 0x13c(%ebx), %xmm0\n" /* line 241 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 0x140(%ebx), %xmm0\n" /* line 242 */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "leal -0x30(%ebp), %esi\n" /* line 1399 | vMaxs, pEnt */
        "movl %esi, 4(%esp)\n" /* pEnt */
        "leal -0x24(%ebp), %ebx\n" /* vMins */
        "movl %ebx, (%esp)\n"
        "calll ExpandBoundsToWidth\n"
        "movl %edi, 8(%esp)\n" /* line 1401 | pOther */
        "movl %esi, 4(%esp)\n" /* pEnt */
        "movl %ebx, (%esp)\n"
        "calll SV_EntityContact\n"
        "movl %eax, (%esp)\n" /* line 1402 */
        "calll Scr_AddInt\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1403 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19c03a_0019c164:\n"
        "movl $0, (%esp)\n" /* line 1389 */
        "calll Scr_GetEntity\n"
        "movl %eax, %edi\n" /* pOther */
        "movl %esi, %ebx\n" /* pEnt */
        "jmp .Lf19c03a_0019c0b4\n"
        ".Lf19c03a_0019c179:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n"
        "jmp .Lf19c03a_0019c06c\n"
    );
}

/* line 1425 */
__attribute__((naked))
unsigned int ScrCmd_PlaySound(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1425 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c18c_0019c1fe\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19c18c_0019c1b9:\n"
        "movl $0, (%esp)\n" /* line 1433 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 1434 */
        "calll G_SoundAliasIndex\n"
        "movl %eax, %esi\n" /* iSoundIndex */
        "movl $0xb3, 4(%esp)\n" /* line 1436 */
        "leal 0x138(%ebx), %eax\n" /* pEnt */
        "movl %eax, (%esp)\n"
        "calll G_TempEntity\n"
        "orb $8, 0xf2(%eax)\n" /* line 1437 */
        "movl %esi, %ecx\n" /* line 1438 | iSoundIndex */
        "movzbl %cl, %edx\n"
        "movl %edx, 0xa0(%eax)\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1439 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19c18c_0019c1fe:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19c18c_0019c1b9\n"
    );
}

/* line 1447 */
__attribute__((naked))
unsigned int ScrCmd_PlaySoundAsMaster(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1447 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c20e_0019c280\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19c20e_0019c23b:\n"
        "movl $0, (%esp)\n" /* line 1455 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 1456 */
        "calll G_SoundAliasIndex\n"
        "movl %eax, %esi\n" /* iSoundIndex */
        "movl $0xb4, 4(%esp)\n" /* line 1458 */
        "leal 0x138(%ebx), %eax\n" /* pEnt */
        "movl %eax, (%esp)\n"
        "calll G_TempEntity\n"
        "orb $8, 0xf2(%eax)\n" /* line 1459 */
        "movl %esi, %ecx\n" /* line 1460 | iSoundIndex */
        "movzbl %cl, %edx\n"
        "movl %edx, 0xa0(%eax)\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1461 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19c20e_0019c280:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19c20e_0019c23b\n"
    );
}

/* line 1469 */
__attribute__((naked))
unsigned int ScrCmd_PlayLoopSound(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1469 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c290_0019c2e9\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19c290_0019c2bc:\n"
        "movl $0, (%esp)\n" /* line 1476 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 1477 */
        "calll G_SoundAliasIndex\n"
        "movl $0xffffffff, 0x100(%ebx)\n" /* line 1479 | pEnt */
        "movzbl %al, %eax\n" /* line 1481 */
        "movl %eax, 0x84(%ebx)\n" /* pEnt */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1482 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19c290_0019c2e9:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19c290_0019c2bc\n"
    );
}

/* line 1490 */
__attribute__((naked))
unsigned int ScrCmd_StopLoopSound(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1490 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c2fa_0019c347\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "movl imp_level, %eax\n" /* line 1496 */
        "movl 0x1ec(%eax), %eax\n"
        "addl $0x12c, %eax\n"
        "movl %eax, 0x100(%edx)\n"
        "movl $0, 0x84(%edx)\n" /* line 1498 */
        /* } scope */
        "leave\n" /* line 1499 */
        "retl\n"
        /* { scope 1 */
        ".Lf19c2fa_0019c347:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "movl imp_level, %eax\n" /* line 1496 */
        "movl 0x1ec(%eax), %eax\n"
        "addl $0x12c, %eax\n"
        "movl %eax, 0x100(%edx)\n"
        "movl $0, 0x84(%edx)\n" /* line 1498 */
        /* } scope */
        "leave\n" /* line 1499 */
        "retl\n"
    );
}

/* line 1611 */
__attribute__((naked))
unsigned int ScrCmd_Delete(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1611 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c378_0019c3f3\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19c378_0019c3a4:\n"
        "movl 0x158(%ebx), %eax\n" /* line 1618 | pEnt */
        "testl %eax, %eax\n"
        "je .Lf19c378_0019c3ba\n"
        "movl $str_002b2b60, (%esp)\n" /* line 1619 */
        "calll Scr_Error\n"
        ".Lf19c378_0019c3ba:\n"
        "movl imp_level, %eax\n" /* line 1621 */
        "movl 0x3604(%eax), %eax\n"
        "cmpl (%ebx), %eax\n" /* pEnt */
        "je .Lf19c378_0019c403\n"
        ".Lf19c378_0019c3c9:\n"
        "movl $0, 8(%esp)\n" /* line 1625 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0xa(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pEnt */
        "calll Scr_Notify\n"
        "movl %ebx, 8(%ebp)\n" /* line 1627 | pEnt, entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1628 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp G_FreeEntity\n" /* line 1627 */
        ".Lf19c378_0019c3f3:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19c378_0019c3a4\n"
        ".Lf19c378_0019c403:\n"
        "movl $str_002b2b80, (%esp)\n" /* line 1622 */
        "calll Scr_Error\n"
        "jmp .Lf19c378_0019c3c9\n"
    );
}

/* line 1636 */
__attribute__((naked))
unsigned int ScrCmd_SetModel(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1636 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c412_0019c46b\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19c412_0019c43e:\n"
        "movl $0, (%esp)\n" /* line 1642 */
        "calll Scr_GetString\n"
        "movl %eax, 4(%esp)\n" /* line 1644 */
        "movl %ebx, (%esp)\n" /* pEnt */
        "calll G_SetModel\n"
        "movl %ebx, (%esp)\n" /* line 1646 | pEnt */
        "calll G_DObjUpdate\n"
        "movl %ebx, 8(%ebp)\n" /* line 1647 | pEnt, entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1648 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_LinkEntity\n" /* line 1647 */
        ".Lf19c412_0019c46b:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19c412_0019c43e\n"
    );
}

/* line 1656 */
__attribute__((naked))
unsigned int ScrCmd_GetNormalHealth(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1656 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c47c_0019c4e3\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        ".Lf19c47c_0019c4a7:\n"
        "movl 0x158(%edx), %ecx\n" /* line 1662 */
        "testl %ecx, %ecx\n"
        "je .Lf19c47c_0019c4f3\n"
        "movl 0x194(%edx), %eax\n" /* line 1664 */
        "testl %eax, %eax\n"
        "jne .Lf19c47c_0019c4c8\n"
        "movl $0, 8(%ebp)\n" /* line 1667 | entref */
        /* } scope */
        "leave\n" /* line 1673 */
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 1667 */
        ".Lf19c47c_0019c4c8:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1665 */
        "cvtsi2ssl 0x2728(%ecx), %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%ebp)\n" /* entref */
        /* } scope */
        "leave\n" /* line 1673 */
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 1665 */
        ".Lf19c47c_0019c4e3:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "jmp .Lf19c47c_0019c4a7\n"
        ".Lf19c47c_0019c4f3:\n"
        "cvtsi2ssl 0x194(%edx), %xmm0\n" /* line 1671 */
        "movss %xmm0, 8(%ebp)\n" /* entref */
        /* } scope */
        "leave\n" /* line 1673 */
        /* { scope 1 */
        "jmp Scr_AddFloat\n" /* line 1671 */
    );
}

/* line 1681 */
__attribute__((naked))
unsigned int ScrCmd_SetNormalHealth(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1681 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c506_0019c600\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19c506_0019c537:\n"
        "movl $0, (%esp)\n" /* line 1688 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm1\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1690 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movl 0x158(%ebx), %eax\n" /* line 1692 | ent */
        "testl %eax, %eax\n"
        "je .Lf19c506_0019c5dc\n"
        "cvtsi2ssl 0x2728(%eax), %xmm0\n" /* line 428 */
        "mulss %xmm0, %xmm1\n"
        "addss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0xc(%ebp)\n"
        "cvttss2si -0xc(%ebp), %esi\n"
        "movl $0, 8(%esp)\n" /* line 1695 */
        "movl $0x49, 4(%esp)\n"
        "movl $str_002b2ba8, (%esp)\n" /* "%c "%i"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, %eax\n" /* ent */
        "subl imp_g_entities, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        ".Lf19c506_0019c5cb:\n"
        "testl %esi, %esi\n" /* line 1703 | newHealth */
        "jle .Lf19c506_0019c5ee\n"
        ".Lf19c506_0019c5cf:\n"
        "movl %esi, 0x194(%ebx)\n" /* line 1709 | newHealth, ent */
        /* } scope */
        "addl $0x30, %esp\n" /* line 1710 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19c506_0019c5dc:\n"
        "movl 0x198(%ebx), %eax\n" /* line 1697 | ent */
        "testl %eax, %eax\n"
        "jne .Lf19c506_0019c613\n"
        "cvttss2si %xmm0, %esi\n" /* line 1700 | newHealth */
        "testl %esi, %esi\n" /* line 1703 | newHealth */
        "jg .Lf19c506_0019c5cf\n"
        ".Lf19c506_0019c5ee:\n"
        "movl $str_002b2bb0, 8(%ebp)\n" /* line 1705 | entref */
        /* } scope */
        "addl $0x30, %esp\n" /* line 1710 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 1705 */
        ".Lf19c506_0019c600:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19c506_0019c537\n"
        ".Lf19c506_0019c613:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1698 */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %esi\n" /* newHealth */
        "jmp .Lf19c506_0019c5cb\n"
    );
}

/* line 1775 */
__attribute__((naked))
unsigned int ScrCmd_SetContents(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1775 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c622_0019c67f\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n"
        "subl %eax, %esi\n"
        "shll $4, %esi\n"
        "addl imp_g_entities, %esi\n"
        ".Lf19c622_0019c64f:\n"
        "movl $0, (%esp)\n" /* line 1781 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* contents */
        "movl 0x11c(%esi), %eax\n" /* line 1782 | ent */
        "movl %eax, (%esp)\n"
        "calll Scr_AddInt\n"
        "movl %ebx, 0x11c(%esi)\n" /* line 1783 | contents, ent */
        "movl %esi, 8(%ebp)\n" /* line 1784 | ent, entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1785 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_LinkEntity\n" /* line 1784 */
        ".Lf19c622_0019c67f:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n"
        "jmp .Lf19c622_0019c64f\n"
    );
}

/* line 1817 */
__attribute__((naked))
unsigned int GScr_SetCursorHint(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1817 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c690_0019c7ea\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* pEnt */
        "movl imp_g_entities, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* pEnt */
        ".Lf19c690_0019c6c9:\n"
        "movl $0, (%esp)\n" /* line 1824 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* pszHint */
        "movl -0x1c(%ebp), %edx\n" /* line 1827 | pEnt */
        "movzwl 0x168(%edx), %eax\n"
        "movl imp_scr_const, %edx\n"
        "cmpw 0x56(%edx), %ax\n"
        "je .Lf19c690_0019c7ac\n"
        "cmpw 0x58(%edx), %ax\n"
        "je .Lf19c690_0019c7ac\n"
        ".Lf19c690_0019c6fb:\n"
        "movl $1, %esi\n" /* line 1832 | i */
        "movl imp_hintStrings, %ebx\n"
        "jmp .Lf19c690_0019c72a\n"
        ".Lf19c690_0019c708:\n"
        "movl %eax, 4(%esp)\n" /* line 1838 */
        "movl %edi, (%esp)\n" /* pszHint */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf19c690_0019c7d9\n"
        "addl $1, %esi\n" /* line 1836 | i */
        "addl $4, %ebx\n"
        "cmpl $0x85, %esi\n" /* i */
        "je .Lf19c690_0019c731\n"
        ".Lf19c690_0019c72a:\n"
        "movl 4(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf19c690_0019c708\n"
        ".Lf19c690_0019c731:\n"
        "movl $str_002b2bf0, (%esp)\n" /* line 1846 */
        "calll Com_Printf\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1847 | pEnt */
        "movzwl 0x168(%edx), %eax\n"
        "movl imp_scr_const, %edx\n"
        "cmpw 0x56(%edx), %ax\n"
        "je .Lf19c690_0019c802\n"
        "cmpw 0x58(%edx), %ax\n"
        "je .Lf19c690_0019c802\n"
        ".Lf19c690_0019c761:\n"
        "movl imp_hintStrings, %ebx\n" /* line 1848 */
        "leal 0x210(%ebx), %esi\n" /* i */
        "jmp .Lf19c690_0019c786\n"
        ".Lf19c690_0019c76f:\n"
        "movl %eax, 4(%esp)\n" /* line 1851 */
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "addl $4, %ebx\n"
        "cmpl %ebx, %esi\n" /* line 1849 | i */
        "je .Lf19c690_0019c78d\n"
        ".Lf19c690_0019c786:\n"
        "movl 4(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf19c690_0019c76f\n"
        ".Lf19c690_0019c78d:\n"
        "movl %edi, 4(%esp)\n" /* line 1853 | pszHint */
        "movl $str_002b2c58, (%esp)\n" /* "%s is not a valid hint type. See above for list of valid hin" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1854 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 1853 */
        ".Lf19c690_0019c7ac:\n"
        "movl $str_002b2be0, 4(%esp)\n" /* line 1829 */
        "movl %edi, (%esp)\n" /* pszHint */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf19c690_0019c6fb\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1831 | pEnt */
        "movl $0xffffffff, 0xdc(%eax)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1854 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19c690_0019c7d9:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1840 | pEnt */
        "movl %esi, 0xdc(%eax)\n" /* i */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1854 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19c690_0019c7ea:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "movl $0, -0x1c(%ebp)\n" /* pEnt */
        "jmp .Lf19c690_0019c6c9\n"
        ".Lf19c690_0019c802:\n"
        "movl $str_002b2c14, (%esp)\n" /* line 1848 */
        "calll Com_Printf\n"
        "jmp .Lf19c690_0019c761\n"
    );
}

/* line 1894 */
__attribute__((naked))
unsigned int GScr_SetHintString(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1894 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x83c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1: szConfigString */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c814_0019c939\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x81c(%ebp)\n" /* pEnt */
        ".Lf19c814_0019c850:\n"
        "movzwl 0x168(%edx), %eax\n" /* line 1906 */
        "movl imp_scr_const, %edx\n"
        "cmpw 0x56(%edx), %ax\n"
        "je .Lf19c814_0019c875\n"
        "cmpw 0x58(%edx), %ax\n"
        "je .Lf19c814_0019c875\n"
        "movl $str_002b2ca0, (%esp)\n" /* line 1907 */
        "calll Scr_Error\n"
        ".Lf19c814_0019c875:\n"
        "movl $0, (%esp)\n" /* line 1910 */
        "calll Scr_GetType\n"
        "cmpl $2, %eax\n" /* line 1911 */
        "je .Lf19c814_0019c95a\n"
        ".Lf19c814_0019c88a:\n"
        "calll Scr_GetNumParam\n" /* line 1920 */
        "movl $0x400, 0x10(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* szHint */
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002afa6c, 8(%esp)\n" /* "Hint String" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "xorl %esi, %esi\n" /* i */
        "leal -0x818(%ebp), %edi\n" /* szConfigString */
        "jmp .Lf19c814_0019c8e8\n"
        /* { scope 2 */
        ".Lf19c814_0019c8c6:\n"
        "movl %edi, 4(%esp)\n" /* line 1876 */
        "leal -0x418(%ebp), %eax\n" /* szHint */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf19c814_0019c91d\n"
        "addl $1, %esi\n" /* line 1867 */
        "cmpl $0x20, %esi\n"
        "je .Lf19c814_0019c999\n"
        /* } scope */
        ".Lf19c814_0019c8e8:\n"
        "leal 0x4fe(%esi), %ebx\n" /* line 1920 | i */
        /* { scope 2 */
        "movl $0x400, 8(%esp)\n" /* line 1869 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "cmpb $0, -0x818(%ebp)\n" /* line 1870 | szConfigString */
        "jne .Lf19c814_0019c8c6\n"
        "leal -0x418(%ebp), %edx\n" /* line 1872 | szHint */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_SetConfigstring\n"
        ".Lf19c814_0019c91d:\n"
        "movl %esi, %eax\n" /* line 1867 */
        /* } scope */
        ".Lf19c814_0019c91f:\n"
        "movzbl %al, %eax\n" /* line 1925 */
        "movl -0x81c(%ebp), %edx\n" /* pEnt */
        "movl %eax, 0xd8(%edx)\n"
        /* } scope */
        "addl $0x83c, %esp\n" /* line 1926 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: szConfigString */
        ".Lf19c814_0019c939:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "movl $0, -0x81c(%ebp)\n" /* pEnt */
        "movl -0x81c(%ebp), %edx\n" /* pEnt */
        "jmp .Lf19c814_0019c850\n"
        ".Lf19c814_0019c95a:\n"
        "movl $0, (%esp)\n" /* line 1913 */
        "calll Scr_GetString\n"
        "movl $str_002157b8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf19c814_0019c88a\n"
        "movl -0x81c(%ebp), %eax\n" /* line 1915 | pEnt */
        "movl $0xff, 0xd8(%eax)\n"
        /* } scope */
        "addl $0x83c, %esp\n" /* line 1926 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: szConfigString */
        ".Lf19c814_0019c999:\n"
        "movl $0x20, 4(%esp)\n" /* line 1923 */
        "movl $str_002b2cf4, (%esp)\n" /* "Too many different hintstring values. Max allowed is %i diff" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl $0xffffffff, %eax\n"
        "jmp .Lf19c814_0019c91f\n"
    );
}

/* line 189 */
__attribute__((naked))
gentity_t * GetPlayerEntity(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %esi\n" /* entref */
        /* { scope 1 */
        "movl %eax, %edx\n" /* line 191 | entref */
        "xorw %dx, %dx\n"
        "andl $0xffff, %eax\n" /* entref */
        "orl %edx, %eax\n" /* entref */
        "movw %si, %ax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19c9c0_0019ca9a\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19c9c0_0019ca00:\n"
        "movl 0x158(%ebx), %eax\n" /* line 195 | ent, entref */
        "testl %eax, %eax\n" /* entref */
        "je .Lf19c9c0_0019ca14\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 200 | ent, entref */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19c9c0_0019ca14:\n"
        "movzwl 0x16c(%ebx), %eax\n" /* line 197 | ent, entref */
        "testw %ax, %ax\n" /* entref */
        "jne .Lf19c9c0_0019ca8b\n"
        "movl $str_002b2d40, %edi\n" /* "<undefined>" */
        ".Lf19c9c0_0019ca25:\n"
        "movzwl 0x168(%ebx), %eax\n" /* ent, entref */
        "movl %eax, (%esp)\n" /* entref */
        "calll SL_ConvertToString\n"
        "movl %edi, 0x24(%esp)\n"
        "movl %eax, 0x20(%esp)\n" /* entref */
        "cvtss2sd 0x140(%ebx), %xmm0\n" /* ent */
        "movsd %xmm0, 0x18(%esp)\n"
        "cvtss2sd 0x13c(%ebx), %xmm0\n" /* ent */
        "movsd %xmm0, 0x10(%esp)\n"
        "cvtss2sd 0x138(%ebx), %xmm0\n" /* ent */
        "movsd %xmm0, 8(%esp)\n"
        "movzwl %si, %eax\n" /* entref */
        "movl %eax, 4(%esp)\n" /* entref */
        "movl $str_002b2d4c, (%esp)\n" /* "only valid on players; called on entity %i at %.0f %.0f %.0f" */
        "calll va\n"
        "movl %eax, (%esp)\n" /* entref */
        "calll Scr_Error\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 200 | ent, entref */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19c9c0_0019ca8b:\n"
        "movzwl %ax, %eax\n" /* line 197 | entref */
        "movl %eax, (%esp)\n" /* entref */
        "calll SL_ConvertToString\n"
        "movl %eax, %edi\n" /* entref */
        "jmp .Lf19c9c0_0019ca25\n"
        ".Lf19c9c0_0019ca9a:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19c9c0_0019ca00\n"
    );
}

/* line 4548 */
__attribute__((naked))
unsigned int GScr_ViewKick(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4548 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        /* { scope 1 */
        "calll GetPlayerEntity\n" /* line 4553 */
        "movl %eax, %esi\n" /* ent */
        "calll Scr_GetNumParam\n" /* line 4555 */
        "cmpl $2, %eax\n"
        "je .Lf19caae_0019cad6\n"
        "movl $str_002b2da8, (%esp)\n" /* line 4556 */
        "calll Scr_Error\n"
        ".Lf19caae_0019cad6:\n"
        "movl 0x158(%esi), %ebx\n" /* line 4558 | ent */
        "movl $0, (%esp)\n"
        "calll Scr_GetInt\n"
        "imull 0x198(%esi), %eax\n" /* ent */
        "leal 0x32(%eax), %ecx\n"
        "movl $0x51eb851f, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $5, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, 0x27e0(%ebx)\n"
        "movl 0x158(%esi), %eax\n" /* line 4559 | ent */
        "movl 0x27e0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf19caae_0019cb74\n"
        ".Lf19caae_0019cb1b:\n"
        "leal -0x14(%ebp), %eax\n" /* line 4562 | origin */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl 0x158(%esi), %eax\n" /* line 4563 | ent */
        "leal 0x27e4(%eax), %ecx\n" /* diff */
        "leal 0x14(%eax), %edx\n" /* a */
        /* { scope 2 */
        "movss 0x14(%eax), %xmm0\n" /* line 248 */
        "subss -0x14(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, 0x27e4(%eax)\n"
        "movss 4(%edx), %xmm0\n" /* line 249 */
        "subss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss 8(%edx), %xmm0\n" /* line 250 */
        "subss -0xc(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        /* } scope */
        /* } scope */
        "addl $0x30, %esp\n" /* line 4564 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19caae_0019cb74:\n"
        "movl $0, (%esp)\n" /* line 4560 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n"
        "cvtss2sd -0x1c(%ebp), %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b2de4, (%esp)\n" /* "viewkick: damage %g < 0
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf19caae_0019cb1b\n"
    );
}

/* line 4528 */
__attribute__((naked))
unsigned int GScr_StopShellShock(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4528 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        /* { scope 1 */
        "calll GetPlayerEntity\n" /* line 4532 */
        "movl %eax, %ebx\n" /* ent */
        "calll Scr_GetNumParam\n" /* line 4534 */
        "testl %eax, %eax\n"
        "je .Lf19cba8_0019cbce\n"
        "movl $str_002b2e00, (%esp)\n" /* line 4535 */
        "calll Scr_Error\n"
        ".Lf19cba8_0019cbce:\n"
        "movl 0x158(%ebx), %eax\n" /* line 4537 | ent */
        "movl $0, 0x5d8(%eax)\n"
        "movl 0x158(%ebx), %eax\n" /* line 4538 | ent */
        "movl $0, 0x5dc(%eax)\n"
        "movl 0x158(%ebx), %eax\n" /* line 4539 | ent */
        "movl $0, 0x5e0(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 4540 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4481 */
__attribute__((naked))
unsigned int GScr_ShellShock(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4481 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        /* { scope 1 */
        "calll GetPlayerEntity\n" /* line 4491 */
        "movl %eax, -0x41c(%ebp)\n" /* ent */
        "calll Scr_GetNumParam\n" /* line 4493 */
        "cmpl $2, %eax\n"
        "je .Lf19cc04_0019cc34\n"
        "movl $str_002b2e24, (%esp)\n" /* line 4494 */
        "calll Scr_Error\n"
        ".Lf19cc04_0019cc34:\n"
        "movl $0, (%esp)\n" /* line 4496 */
        "calll Scr_GetString\n"
        "movl %eax, %edi\n" /* shock */
        "movl $1, %ebx\n" /* id */
        "leal -0x418(%ebp), %esi\n" /* s, duration */
        ".Lf19cc04_0019cc4d:\n"
        "movl $0x400, 8(%esp)\n" /* line 4499 */
        "movl %esi, 4(%esp)\n" /* duration */
        "leal 0x48e(%ebx), %eax\n" /* id */
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl %edi, 4(%esp)\n" /* line 4500 | shock */
        "movl %esi, (%esp)\n" /* duration */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf19cc04_0019cca2\n"
        "addl $1, %ebx\n" /* line 4497 | id */
        "cmpl $0x10, %ebx\n" /* id */
        "jne .Lf19cc04_0019cc4d\n"
        "movl %edi, 4(%esp)\n" /* line 4519 | shock */
        "movl $str_002b2e88, (%esp)\n" /* "shellshock '%s' was not precached
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        ".Lf19cc04_0019cc97:\n"
        "addl $0x43c, %esp\n" /* line 4520 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19cc04_0019cca2:\n"
        "movl $1, (%esp)\n" /* line 4502 */
        "calll Scr_GetFloat\n"
        "fstps -0x42c(%ebp)\n"
        "movss -0x42c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x420(%ebp)\n"
        "cvttss2si -0x420(%ebp), %esi\n"
        "cmpl $0xea60, %esi\n" /* line 4503 | duration */
        "ja .Lf19cc04_0019cd83\n"
        ".Lf19cc04_0019ccf0:\n"
        "movl -0x41c(%ebp), %edx\n" /* line 4506 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl %ebx, 0x5d8(%eax)\n" /* id */
        "movl -0x41c(%ebp), %eax\n" /* line 4507 | ent */
        "movl 0x158(%eax), %edx\n"
        "movl imp_level, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x5dc(%edx)\n"
        "movl -0x41c(%ebp), %edx\n" /* line 4508 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl %esi, 0x5e0(%eax)\n" /* duration */
        "movl 0x194(%edx), %edx\n" /* line 4510 */
        "testl %edx, %edx\n"
        "jle .Lf19cc04_0019cc97\n"
        "movl imp_level_bgs, %eax\n" /* line 4512 */
        "movl imp_bgs, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $1, 0xc(%esp)\n" /* line 4513 */
        "movl $0, 8(%esp)\n"
        "movl $0x12, 4(%esp)\n"
        "movl -0x41c(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_AnimScriptEvent\n"
        /* } scope */
        "addl $0x43c, %esp\n" /* line 4520 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19cc04_0019cd83:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 4504 | duration */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b2e60, (%esp)\n" /* "duration %g should be >= 0 and <= 60" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf19cc04_0019ccf0\n"
    );
}

/* line 890 */
__attribute__((naked))
unsigned int GScr_GetAmmoCount(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 890 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        /* { scope 1 */
        "calll GetPlayerEntity\n" /* line 896 */
        "movl %eax, %ebx\n" /* ent */
        "movl $0, (%esp)\n" /* line 901 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 902 */
        "calll G_GetWeaponIndexForName\n"
        "testl %eax, %eax\n" /* line 904 */
        "jne .Lf19cdba_0019cdf4\n"
        "movl $0, 8(%ebp)\n" /* line 905 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 908 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 905 */
        ".Lf19cdba_0019cdf4:\n"
        "movl %eax, 4(%esp)\n" /* line 907 */
        "movl 0x158(%ebx), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll BG_WeaponAmmo\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 908 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 907 */
    );
}

/* line 4573 */
__attribute__((naked))
unsigned int GScr_LocalToWorldCoords(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4573 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19ce14_0019ceca\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edi\n"
        "subl %eax, %edi\n"
        "shll $4, %edi\n"
        "addl imp_g_entities, %edi\n"
        ".Lf19ce14_0019ce46:\n"
        "leal -0x24(%ebp), %esi\n" /* line 4581 | vLocal */
        "movl %esi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "leal -0x54(%ebp), %ebx\n" /* line 4582 | axis */
        "movl %ebx, 4(%esp)\n"
        "leal 0x144(%edi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal -0x30(%ebp), %eax\n" /* line 4583 | vWorld */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MatrixTransformVector\n"
        "leal 0x138(%edi), %eax\n" /* ent */
        /* { scope 2 */
        "movss -0x30(%ebp), %xmm0\n" /* line 240 | vWorld */
        "addss 0x138(%edi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* vWorld */
        "movss -0x2c(%ebp), %xmm0\n" /* line 241 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 242 */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "leal -0x30(%ebp), %eax\n" /* line 4585 | vWorld */
        "movl %eax, (%esp)\n"
        "calll Scr_AddVector\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 4586 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19ce14_0019ceca:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n"
        "jmp .Lf19ce14_0019ce46\n"
    );
}

/* line 4595 */
__attribute__((naked))
unsigned int GScr_SetRightArc(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4595 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19cede_0019cf48\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        ".Lf19cede_0019cf0a:\n"
        "movl 0x15c(%edx), %ebx\n" /* line 4602 | pTurretInfo */
        "testl %ebx, %ebx\n" /* line 4603 | pTurretInfo */
        "je .Lf19cede_0019cf58\n"
        ".Lf19cede_0019cf14:\n"
        "movl $0, (%esp)\n" /* line 4606 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n"
        "movss -0xc(%ebp), %xmm0\n"
        "xorps color+640, %xmm0\n"
        "movss %xmm0, 0x10(%ebx)\n" /* pTurretInfo */
        "pxor %xmm1, %xmm1\n" /* line 4607 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf19cede_0019cf42\n"
        "movss %xmm1, 0x10(%ebx)\n" /* line 4608 | pTurretInfo */
        /* } scope */
        ".Lf19cede_0019cf42:\n"
        "addl $0x24, %esp\n" /* line 4609 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19cede_0019cf48:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "jmp .Lf19cede_0019cf0a\n"
        ".Lf19cede_0019cf58:\n"
        "movl $str_002b2eac, (%esp)\n" /* line 4604 */
        "calll Scr_Error\n"
        "jmp .Lf19cede_0019cf14\n"
    );
}

/* line 4618 */
__attribute__((naked))
unsigned int GScr_SetLeftArc(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4618 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19cf66_0019cfd1\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        ".Lf19cf66_0019cf92:\n"
        "movl 0x15c(%edx), %ebx\n" /* line 4625 | pTurretInfo */
        "testl %ebx, %ebx\n" /* line 4626 | pTurretInfo */
        "je .Lf19cf66_0019cfe1\n"
        ".Lf19cf66_0019cf9c:\n"
        "movl $0, (%esp)\n" /* line 4629 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n"
        "movss -0xc(%ebp), %xmm0\n"
        "movss %xmm0, 0x18(%ebx)\n" /* pTurretInfo */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 4630 | 0.0f */
        "jb .Lf19cf66_0019cfc4\n"
        /* } scope */
        ".Lf19cf66_0019cfbe:\n"
        "addl $0x24, %esp\n" /* line 4632 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19cf66_0019cfc4:\n"
        "jp .Lf19cf66_0019cfbe\n" /* line 4630 */
        "xorl %eax, %eax\n" /* line 4631 */
        "movl %eax, 0x18(%ebx)\n" /* pTurretInfo */
        /* } scope */
        "addl $0x24, %esp\n" /* line 4632 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19cf66_0019cfd1:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "jmp .Lf19cf66_0019cf92\n"
        ".Lf19cf66_0019cfe1:\n"
        "movl $str_002b2eac, (%esp)\n" /* line 4627 */
        "calll Scr_Error\n"
        "jmp .Lf19cf66_0019cf9c\n"
    );
}

/* line 4641 */
__attribute__((naked))
unsigned int GScr_SetTopArc(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4641 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19cff0_0019d05a\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        ".Lf19cff0_0019d01c:\n"
        "movl 0x15c(%edx), %ebx\n" /* line 4648 | pTurretInfo */
        "testl %ebx, %ebx\n" /* line 4649 | pTurretInfo */
        "je .Lf19cff0_0019d06a\n"
        ".Lf19cff0_0019d026:\n"
        "movl $0, (%esp)\n" /* line 4652 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n"
        "movss -0xc(%ebp), %xmm0\n"
        "xorps color+656, %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n" /* pTurretInfo */
        "pxor %xmm1, %xmm1\n" /* line 4653 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf19cff0_0019d054\n"
        "movss %xmm1, 0xc(%ebx)\n" /* line 4654 | pTurretInfo */
        /* } scope */
        ".Lf19cff0_0019d054:\n"
        "addl $0x24, %esp\n" /* line 4655 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19cff0_0019d05a:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "jmp .Lf19cff0_0019d01c\n"
        ".Lf19cff0_0019d06a:\n"
        "movl $str_002b2eac, (%esp)\n" /* line 4650 */
        "calll Scr_Error\n"
        "jmp .Lf19cff0_0019d026\n"
    );
}

/* line 4664 */
__attribute__((naked))
unsigned int GScr_SetBottomArc(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4664 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19d078_0019d0e3\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        ".Lf19d078_0019d0a4:\n"
        "movl 0x15c(%edx), %ebx\n" /* line 4671 | pTurretInfo */
        "testl %ebx, %ebx\n" /* line 4672 | pTurretInfo */
        "je .Lf19d078_0019d0f3\n"
        ".Lf19d078_0019d0ae:\n"
        "movl $0, (%esp)\n" /* line 4675 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n"
        "movss -0xc(%ebp), %xmm0\n"
        "movss %xmm0, 0x14(%ebx)\n" /* pTurretInfo */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 4676 | 0.0f */
        "jb .Lf19d078_0019d0d6\n"
        /* } scope */
        ".Lf19d078_0019d0d0:\n"
        "addl $0x24, %esp\n" /* line 4678 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19d078_0019d0d6:\n"
        "jp .Lf19d078_0019d0d0\n" /* line 4676 */
        "xorl %eax, %eax\n" /* line 4677 */
        "movl %eax, 0x14(%ebx)\n" /* pTurretInfo */
        /* } scope */
        "addl $0x24, %esp\n" /* line 4678 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19d078_0019d0e3:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "jmp .Lf19d078_0019d0a4\n"
        ".Lf19d078_0019d0f3:\n"
        "movl $str_002b2eac, (%esp)\n" /* line 4673 */
        "calll Scr_Error\n"
        "jmp .Lf19d078_0019d0ae\n"
    );
}

/* line 1934 */
__attribute__((naked))
unsigned int GScr_GetEntityNumber(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1934 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19d102_0019d138\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "movl (%edx), %eax\n" /* line 1939 */
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "leave\n" /* line 1940 */
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1939 */
        ".Lf19d102_0019d138:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        "movl (%edx), %eax\n" /* line 1939 */
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "leave\n" /* line 1940 */
        /* { scope 1 */
        "jmp Scr_AddInt\n" /* line 1939 */
    );
}

/* line 4688 */
__attribute__((naked))
unsigned int GScr_PlaceSpawnPoint(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4688 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19d152_0019d37f\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edi\n"
        "subl %eax, %edi\n"
        "shll $4, %edi\n"
        "addl imp_g_entities, %edi\n"
        ".Lf19d152_0019d184:\n"
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n" /* vStart */
        "movl 0x13c(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x140(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* vEnd */
        "movl 0x13c(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss lit4_002ed7cc, %xmm0\n" /* line 4699 | 128.0f */
        "addss 0x140(%edi), %xmm0\n" /* pEnt */
        "movss %xmm0, -0x28(%ebp)\n"
        "movl $0x2810011, 0x18(%esp)\n" /* line 4700 */
        "movl (%edi), %eax\n" /* pEnt */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x30(%ebp), %ebx\n" /* vEnd */
        "movl %ebx, 0x10(%esp)\n"
        "movl imp_playerMaxs, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_playerMins, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %esi\n" /* vStart */
        "movl %esi, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movss -0x54(%ebp), %xmm4\n" /* line 4702 | trace, fraction */
        /* { scope 2 */
        "movss -0x24(%ebp), %xmm0\n" /* line 1203 | vStart */
        "movss -0x30(%ebp), %xmm2\n" /* vEnd */
        "subss %xmm0, %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* vStart */
        "movss -0x20(%ebp), %xmm0\n" /* line 1204 */
        "movss -0x2c(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x1c(%ebp), %xmm3\n" /* line 1205 */
        "movss -0x28(%ebp), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "movss %xmm2, -0x30(%ebp)\n" /* line 199 | vEnd */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 200 */
        "subss lit4_002ed864, %xmm0\n" /* line 4704 | 262144.0f */
        "movss %xmm0, -0x28(%ebp)\n"
        "movl $0x2810011, 0x18(%esp)\n" /* line 4705 */
        "movl (%edi), %eax\n" /* pEnt */
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl imp_playerMaxs, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_playerMins, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movzwl -0x38(%ebp), %eax\n" /* line 4708 */
        "movl %eax, 0x7c(%edi)\n" /* pEnt */
        "movss -0x54(%ebp), %xmm2\n" /* line 4711 | trace, fraction */
        /* { scope 2 */
        "movss -0x24(%ebp), %xmm1\n" /* line 1203 | vStart */
        "movss -0x30(%ebp), %xmm0\n" /* vEnd */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* vStart */
        "movss -0x20(%ebp), %xmm1\n" /* line 1204 */
        "movss -0x2c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 1205 */
        "movss -0x28(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "movl $0x2810011, 0x18(%esp)\n" /* line 4712 */
        "movl (%edi), %eax\n" /* pEnt */
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl imp_playerMaxs, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_playerMins, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "cmpb $0, -0x32(%ebp)\n" /* line 4713 */
        "je .Lf19d152_0019d36b\n"
        "cvttss2si 0x140(%edi), %eax\n" /* line 4714 | pEnt */
        "movl %eax, 0x10(%esp)\n"
        "cvttss2si 0x13c(%edi), %eax\n" /* pEnt */
        "movl %eax, 0xc(%esp)\n"
        "cvttss2si 0x138(%edi), %eax\n" /* pEnt */
        "movl %eax, 8(%esp)\n"
        "movl (%edi), %eax\n" /* pEnt */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2ec4, (%esp)\n" /* "WARNING: Spawn point entity %i is in solid at (%i, %i, %i)
" */
        "calll Com_Printf\n"
        ".Lf19d152_0019d36b:\n"
        "movl %esi, 4(%esp)\n" /* line 4716 */
        "movl %edi, (%esp)\n" /* pEnt */
        "calll G_SetOrigin\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 4717 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19d152_0019d37f:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n"
        "jmp .Lf19d152_0019d184\n"
    );
}

/* line 4720 */
__attribute__((naked))
unsigned int GScr_UpdateScores(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4720 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19d392_0019d443\n"
        "movzwl %dx, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl imp_g_entities, %ebx\n"
        ".Lf19d392_0019d3c3:\n"
        "movl imp_level, %esi\n" /* line 4726 */
        "movl 0x204(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x48, 4(%esp)\n"
        "movl $str_002b1d38, (%esp)\n" /* "%c %i" */
        "calll va\n"
        "subl imp_g_entities, %ebx\n"
        "sarl $4, %ebx\n"
        "imull $0x8af8af8b, %ebx, %ebx\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl 0x200(%esi), %eax\n" /* line 4727 */
        "movl %eax, 8(%esp)\n"
        "movl $0x47, 4(%esp)\n"
        "movl $str_002b1d38, (%esp)\n" /* "%c %i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "addl $0x10, %esp\n" /* line 4728 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19d392_0019d443:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf19d392_0019d3c3\n"
    );
}

/* line 5600 */
__attribute__((naked))
unsigned int GScr_SetTeamForTrigger(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5600 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19d456_0019d565\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n"
        "subl %eax, %esi\n"
        "shll $4, %esi\n"
        "addl imp_g_entities, %esi\n"
        ".Lf19d456_0019d488:\n"
        "movzwl 0x168(%esi), %edx\n" /* line 5606 | ent */
        "movl imp_scr_const, %edi\n"
        "cmpw 0x56(%edi), %dx\n"
        "je .Lf19d456_0019d4d9\n"
        "movzwl 0x58(%edi), %eax\n"
        "cmpw %ax, %dx\n"
        "je .Lf19d456_0019d4d9\n"
        "movzwl %ax, %eax\n" /* line 5607 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n"
        "movzwl 0x56(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2f00, (%esp)\n" /* "setteamfortrigger: trigger entity must be of type %s or %s" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf19d456_0019d4d9:\n"
        "movl $0, (%esp)\n" /* line 5609 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edi\n" /* line 5610 */
        "cmpw 2(%edi), %ax\n"
        "je .Lf19d456_0019d578\n"
        "cmpw 4(%edi), %ax\n" /* line 5612 */
        "je .Lf19d456_0019d587\n"
        "movzwl 0x74(%edi), %edx\n" /* line 5614 */
        "cmpw %dx, %ax\n"
        "je .Lf19d456_0019d556\n"
        "movzwl %dx, %eax\n" /* line 5617 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %esi\n" /* ent */
        "movzwl 4(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n"
        "movzwl 2(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %esi, 0xc(%esp)\n" /* ent */
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2f3c, (%esp)\n" /* "setteamfortrigger: invalid team used must be %s, %s or %s" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* entref */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 5618 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 5617 */
        ".Lf19d456_0019d556:\n"
        "movb $0, 0x167(%esi)\n" /* line 5615 | ent */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 5618 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19d456_0019d565:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n"
        "jmp .Lf19d456_0019d488\n"
        ".Lf19d456_0019d578:\n"
        "movb $2, 0x167(%esi)\n" /* line 5611 | ent */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 5618 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19d456_0019d587:\n"
        "movb $1, 0x167(%esi)\n" /* line 5613 | ent */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 5618 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5626 */
__attribute__((naked))
unsigned int GScr_ClientClaimTrigger(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5626 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19d596_0019d67f\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n"
        "subl %eax, %esi\n"
        "shll $4, %esi\n"
        "addl imp_g_entities, %esi\n"
        ".Lf19d596_0019d5c8:\n"
        "movl 0x158(%esi), %ecx\n" /* line 5632 | clientEnt */
        "testl %ecx, %ecx\n"
        "je .Lf19d596_0019d692\n"
        ".Lf19d596_0019d5d6:\n"
        "movl $0, (%esp)\n" /* line 5635 */
        "calll Scr_GetEntity\n"
        "movl %eax, -0x1c(%ebp)\n" /* triggerEnt */
        "movzwl 0x168(%eax), %edx\n" /* line 5637 */
        "movl imp_scr_const, %edi\n"
        "cmpw 0x56(%edi), %dx\n"
        "je .Lf19d596_0019d639\n"
        "movzwl 0x58(%edi), %eax\n"
        "cmpw %ax, %dx\n"
        "je .Lf19d596_0019d67a\n"
        "movzwl %ax, %eax\n" /* line 5638 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n"
        "movzwl 0x56(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b2fa8, (%esp)\n" /* "clientclaimtrigger: trigger entity must be of type %s or %s" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "movl -0x1c(%ebp), %eax\n" /* triggerEnt */
        ".Lf19d596_0019d639:\n"
        "movl 0x1b4(%eax), %edx\n" /* line 5640 */
        "cmpl $0x3ff, %edx\n"
        "je .Lf19d596_0019d65d\n"
        "movl 0x158(%esi), %eax\n" /* clientEnt */
        "cmpl 0xcc(%eax), %edx\n"
        "je .Lf19d596_0019d663\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 5644 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19d596_0019d65d:\n"
        "movl 0x158(%esi), %eax\n" /* clientEnt */
        /* { scope 1 */
        ".Lf19d596_0019d663:\n"
        "movl 0xcc(%eax), %eax\n" /* line 5643 */
        "movl -0x1c(%ebp), %edx\n" /* triggerEnt */
        "movl %eax, 0x1b4(%edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 5644 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19d596_0019d67a:\n"
        "movl -0x1c(%ebp), %eax\n" /* triggerEnt */
        "jmp .Lf19d596_0019d639\n"
        /* { scope 1 */
        ".Lf19d596_0019d67f:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n"
        "jmp .Lf19d596_0019d5c8\n"
        ".Lf19d596_0019d692:\n"
        "movl $str_002b2f78, (%esp)\n" /* line 5633 */
        "calll Scr_Error\n"
        "jmp .Lf19d596_0019d5d6\n"
    );
}

/* line 5652 */
__attribute__((naked))
unsigned int GScr_ClientReleaseTrigger(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5652 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 171 */
        "testw %ax, %ax\n"
        "jne .Lf19d6a4_0019d76d\n"
        "movzwl %dx, %eax\n" /* line 174 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n"
        "subl %eax, %esi\n"
        "shll $4, %esi\n"
        "addl imp_g_entities, %esi\n"
        ".Lf19d6a4_0019d6d6:\n"
        "movl 0x158(%esi), %ebx\n" /* line 5658 | clientEnt, triggerEnt */
        "testl %ebx, %ebx\n" /* triggerEnt */
        "je .Lf19d6a4_0019d780\n"
        ".Lf19d6a4_0019d6e4:\n"
        "movl $0, (%esp)\n" /* line 5661 */
        "calll Scr_GetEntity\n"
        "movl %eax, %ebx\n" /* triggerEnt */
        "movzwl 0x168(%eax), %edx\n" /* line 5663 */
        "movl imp_scr_const, %edi\n"
        "cmpw 0x56(%edi), %dx\n"
        "je .Lf19d6a4_0019d747\n"
        "movzwl 0x58(%edi), %eax\n"
        "cmpw %ax, %dx\n"
        "je .Lf19d6a4_0019d747\n"
        "movzwl %ax, %eax\n" /* line 5664 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movzwl 0x56(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b3018, (%esp)\n" /* "clientreleasetrigger: trigger entity must be of type %s or %" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf19d6a4_0019d747:\n"
        "movl 0x158(%esi), %edx\n" /* line 5666 | clientEnt */
        "movl 0x1b4(%ebx), %eax\n" /* triggerEnt */
        "cmpl 0xcc(%edx), %eax\n"
        "jne .Lf19d6a4_0019d765\n"
        "movl $0x3ff, 0x1b4(%ebx)\n" /* line 5669 | triggerEnt */
        /* } scope */
        ".Lf19d6a4_0019d765:\n"
        "addl $0x2c, %esp\n" /* line 5670 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19d6a4_0019d76d:\n"
        "movl $str_002b21c8, (%esp)\n" /* line 177 */
        "calll Scr_ObjectError\n"
        "xorl %esi, %esi\n"
        "jmp .Lf19d6a4_0019d6d6\n"
        ".Lf19d6a4_0019d780:\n"
        "movl $str_002b2fe4, (%esp)\n" /* line 5659 */
        "calll Scr_Error\n"
        "jmp .Lf19d6a4_0019d6e4\n"
    );
}

/* line 3868 */
__attribute__((naked))
unsigned int Scr_PlayFX(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3868 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        /* { scope 1: fxName */
        "calll Scr_GetNumParam\n" /* line 3877 */
        "movl %eax, %esi\n"
        "leal -2(%eax), %eax\n" /* line 3879 */
        "cmpl $2, %eax\n"
        "ja .Lf19d792_0019da6f\n"
        ".Lf19d792_0019d7b1:\n"
        "movl $0, (%esp)\n" /* line 3882 */
        "calll Scr_GetInt\n"
        "movl %eax, %edi\n" /* fxId */
        "leal -0x24(%ebp), %ebx\n" /* line 3883 | pos, ent */
        "movl %ebx, 4(%esp)\n" /* ent */
        "movl $1, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl $0xc2, 4(%esp)\n" /* line 3885 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_TempEntity\n"
        "movl %eax, %ebx\n" /* ent */
        "movl %edi, %edx\n" /* line 3888 | fxId */
        "movzbl %dl, %eax\n"
        "movl %eax, 0xa0(%ebx)\n" /* ent */
        "cmpl $2, %esi\n" /* line 3889 */
        "je .Lf19d792_0019da5d\n"
        "leal -0x48(%ebp), %eax\n" /* line 3896 | axis */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Scr_GetVector\n"
        "movss -0x48(%ebp), %xmm0\n" /* line 324 | axis */
        "movss -0x44(%ebp), %xmm1\n"
        "movss -0x40(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "movss %xmm0, -0x450(%ebp)\n" /* vecLength */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 3899 | 0.0f */
        "jne .Lf19d792_0019d893\n"
        "jp .Lf19d792_0019d893\n"
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 3859 */
        "je .Lf19d792_0019daef\n"
        "movl $0x400, 8(%esp)\n" /* line 3860 */
        "leal -0x448(%ebp), %edx\n" /* fxName */
        "movl %edx, 4(%esp)\n"
        "leal 0x34e(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        ".Lf19d792_0019d86d:\n"
        "leal -0x448(%ebp), %eax\n" /* line 3864 | fxName */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b3078, 4(%esp)\n" /* "playFx called with (0 0 0) forward direction" */
        "movl $str_002b30a8, (%esp)\n" /* "%s (effect = %s)
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        ".Lf19d792_0019d893:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 3903 | 1.0f, scale */
        "divss -0x450(%ebp), %xmm0\n" /* vecLength, scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x48(%ebp), %xmm1\n" /* axis */
        "movss %xmm1, -0x48(%ebp)\n" /* axis */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x44(%ebp), %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "mulss -0x40(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        "cmpl $3, %esi\n" /* line 3905 */
        "je .Lf19d792_0019dad2\n"
        "leal -0x30(%ebp), %esi\n" /* line 3912 */
        "movl %esi, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll Scr_GetVector\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 324 */
        "movss -0x2c(%ebp), %xmm1\n"
        "movss -0x28(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "movss %xmm0, -0x44c(%ebp)\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 3915 | 0.0f */
        "jne .Lf19d792_0019d96b\n"
        "jp .Lf19d792_0019d96b\n"
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 3859 */
        "je .Lf19d792_0019db71\n"
        "movl $0x400, 8(%esp)\n" /* line 3860 */
        "leal -0x448(%ebp), %eax\n" /* fxName */
        "movl %eax, 4(%esp)\n"
        "leal 0x34e(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        ".Lf19d792_0019d945:\n"
        "leal -0x448(%ebp), %edx\n" /* line 3864 | fxName */
        "movl %edx, 8(%esp)\n"
        "movl $str_002b30bc, 4(%esp)\n" /* "playFx called with (0 0 0) up direction" */
        "movl $str_002b30a8, (%esp)\n" /* "%s (effect = %s)
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        ".Lf19d792_0019d96b:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 3919 | 1.0f, scale */
        "divss -0x44c(%ebp), %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x2c(%ebp), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "mulss -0x28(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "leal -0x3c(%ebp), %eax\n" /* line 3923 */
        "movl %eax, 8(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* axis */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        "movss -0x3c(%ebp), %xmm3\n" /* line 324 */
        "movss -0x38(%ebp), %xmm0\n"
        "movss -0x34(%ebp), %xmm2\n"
        "movaps %xmm3, %xmm1\n" /* line 81 */
        "mulss %xmm3, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "ucomiss lit4_002ed658, %xmm1\n" /* line 3925 | 0.0010000000474974513f */
        "jae .Lf19d792_0019da80\n"
        "jp .Lf19d792_0019da80\n"
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 3859 */
        "je .Lf19d792_0019db30\n"
        "movl $0x400, 8(%esp)\n" /* line 3860 */
        "leal -0x448(%ebp), %eax\n" /* fxName */
        "movl %eax, 4(%esp)\n"
        "leal 0x34e(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        ".Lf19d792_0019da1a:\n"
        "leal -0x448(%ebp), %edx\n" /* line 3864 | fxName */
        "movl %edx, 8(%esp)\n"
        "movl $str_002b30e4, 4(%esp)\n" /* "playFx called an up direction 0 or 180 degrees from forward" */
        "movl $str_002b30a8, (%esp)\n" /* "%s (effect = %s)
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        /* } scope */
        ".Lf19d792_0019da40:\n"
        "leal 0x3c(%ebx), %eax\n" /* line 3937 | ent */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll AxisToAngles\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 3938 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fxName */
        ".Lf19d792_0019da5d:\n"
        "movl $0xc2b40000, 0x3c(%ebx)\n" /* line 3891 | ent */
        /* } scope */
        "addl $0x45c, %esp\n" /* line 3938 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fxName */
        ".Lf19d792_0019da6f:\n"
        "movl $str_002b3058, (%esp)\n" /* line 3880 */
        "calll Scr_Error\n"
        "jmp .Lf19d792_0019d7b1\n"
        ".Lf19d792_0019da80:\n"
        "ucomiss lit4_002ed690, %xmm1\n" /* line 3929 | 0.9990000128746033f */
        "jae .Lf19d792_0019da40\n"
        "jp .Lf19d792_0019da40\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 3931 | 1.0f, scale */
        "divss %xmm1, %xmm0\n" /* scale */
        /* { scope 2 */
        "mulss %xmm0, %xmm3\n" /* line 272 */
        "movss %xmm3, -0x3c(%ebp)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x38(%ebp), %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "mulss -0x34(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        "movl %esi, 8(%esp)\n" /* line 3932 */
        "leal -0x3c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* axis */
        "movl %edx, (%esp)\n"
        "calll Vec3Cross\n"
        "jmp .Lf19d792_0019da40\n"
        ".Lf19d792_0019dad2:\n"
        "leal 0x3c(%ebx), %eax\n" /* line 3907 | ent */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* axis */
        "movl %edx, (%esp)\n"
        "calll vectoangles\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 3938 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fxName */
        /* { scope 2 */
        ".Lf19d792_0019daef:\n"
        "movl $0x20746f6e, -0x448(%ebp)\n" /* line 3862 | fxName */
        "movl $0x63637573, -0x444(%ebp)\n"
        "movl $0x66737365, -0x440(%ebp)\n"
        "movl $0x796c6c75, -0x43c(%ebp)\n"
        "movl $0x616f6c20, -0x438(%ebp)\n"
        "movl $0x646564, -0x434(%ebp)\n"
        "jmp .Lf19d792_0019d86d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19d792_0019db30:\n"
        "movl $0x20746f6e, -0x448(%ebp)\n" /* fxName */
        "movl $0x63637573, -0x444(%ebp)\n"
        "movl $0x66737365, -0x440(%ebp)\n"
        "movl $0x796c6c75, -0x43c(%ebp)\n"
        "movl $0x616f6c20, -0x438(%ebp)\n"
        "movl $0x646564, -0x434(%ebp)\n"
        "jmp .Lf19d792_0019da1a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19d792_0019db71:\n"
        "movl $0x20746f6e, -0x448(%ebp)\n" /* fxName */
        "movl $0x63637573, -0x444(%ebp)\n"
        "movl $0x66737365, -0x440(%ebp)\n"
        "movl $0x796c6c75, -0x43c(%ebp)\n"
        "movl $0x616f6c20, -0x438(%ebp)\n"
        "movl $0x646564, -0x434(%ebp)\n"
        "jmp .Lf19d792_0019d945\n"
    );
}

/* line 509 */
__attribute__((naked))
unsigned int iprintln(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 509 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl $0x66, 4(%esp)\n" /* line 511 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, %esi\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 498 */
        "movl $0x400, 0x10(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* string */
        "movl %ebx, 0xc(%esp)\n"
        "movl $str_002b281c, 8(%esp)\n" /* "Game Message" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "movl %ebx, 8(%esp)\n" /* line 499 */
        "movl %esi, 4(%esp)\n"
        "movl $str_002b282c, (%esp)\n" /* "%s "%s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 512 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 521 */
__attribute__((naked))
unsigned int iprintlnbold(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 521 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl $0x67, 4(%esp)\n" /* line 523 */
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, %esi\n"
        /* { scope 1 */
        "calll Scr_GetNumParam\n" /* line 498 */
        "movl $0x400, 0x10(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* string */
        "movl %ebx, 0xc(%esp)\n"
        "movl $str_002b281c, 8(%esp)\n" /* "Game Message" */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ConstructMessageString\n"
        "movl %ebx, 8(%esp)\n" /* line 499 */
        "movl %esi, 4(%esp)\n"
        "movl $str_002b282c, (%esp)\n" /* "%s "%s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 524 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 89 */
__attribute__((naked))
unsigned int GScr_LoadGameTypeScript(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "movl imp_g_gametype, %eax\n" /* line 93 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3120, 8(%esp)\n" /* "maps/mp/gametypes/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x48(%ebp), %esi\n" /* filename */
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        /* { scope 2 */
        "movl %esi, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "je .Lf19dcc6_0019dfc9\n"
        ".Lf19dcc6_0019dd07:\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 77 */
        "movl %esi, (%esp)\n"
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "je .Lf19dcc6_0019dfa4\n"
        /* } scope */
        ".Lf19dcc6_0019dd21:\n"
        "movl %ebx, g_scr_data+8\n" /* line 95 | func */
        /* { scope 2 */
        "movl $str_002b3180, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "je .Lf19dcc6_0019df83\n"
        ".Lf19dcc6_0019dd3b:\n"
        "movl $str_002b31a4, 4(%esp)\n" /* line 77 */
        "movl $str_002b3180, (%esp)\n" /* "maps/mp/gametypes/_callbacksetup" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "je .Lf19dcc6_0019df5a\n"
        /* } scope */
        ".Lf19dcc6_0019dd59:\n"
        "movl %ebx, g_scr_data+12\n" /* line 98 | func */
        /* { scope 2 */
        "movl $str_002b3180, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "je .Lf19dcc6_0019df39\n"
        ".Lf19dcc6_0019dd73:\n"
        "movl $str_002b31c0, 4(%esp)\n" /* line 77 */
        "movl $str_002b3180, (%esp)\n" /* "maps/mp/gametypes/_callbacksetup" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "je .Lf19dcc6_0019df10\n"
        /* } scope */
        ".Lf19dcc6_0019dd91:\n"
        "movl %ebx, g_scr_data+16\n" /* line 99 | func */
        /* { scope 2 */
        "movl $str_002b3180, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "je .Lf19dcc6_0019deef\n"
        ".Lf19dcc6_0019ddab:\n"
        "movl $str_002b31dc, 4(%esp)\n" /* line 77 */
        "movl $str_002b3180, (%esp)\n" /* "maps/mp/gametypes/_callbacksetup" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "je .Lf19dcc6_0019dec6\n"
        /* } scope */
        ".Lf19dcc6_0019ddc9:\n"
        "movl %ebx, g_scr_data+20\n" /* line 100 | func */
        /* { scope 2 */
        "movl $str_002b3180, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "je .Lf19dcc6_0019dea5\n"
        ".Lf19dcc6_0019dde3:\n"
        "movl $str_002b31fc, 4(%esp)\n" /* line 77 */
        "movl $str_002b3180, (%esp)\n" /* "maps/mp/gametypes/_callbacksetup" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "je .Lf19dcc6_0019de7c\n"
        /* } scope */
        ".Lf19dcc6_0019ddfd:\n"
        "movl %ebx, g_scr_data+24\n" /* line 101 | func */
        /* { scope 2 */
        "movl $str_002b3180, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "je .Lf19dcc6_0019de5e\n"
        ".Lf19dcc6_0019de13:\n"
        "movl $str_002b3218, 4(%esp)\n" /* line 77 */
        "movl $str_002b3180, (%esp)\n" /* "maps/mp/gametypes/_callbacksetup" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "jne .Lf19dcc6_0019de51\n"
        "movl $str_002b3180, 0xc(%esp)\n" /* line 81 */
        "movl $str_002b3218, 8(%esp)\n" /* "CodeCallback_PlayerKilled" */
        "movl $str_002b3154, 4(%esp)\n" /* "Could not find label '%s' in script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf19dcc6_0019de51:\n"
        "movl %ebx, g_scr_data+28\n" /* line 102 | func */
        /* } scope */
        "addl $0x50, %esp\n" /* line 103 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf19dcc6_0019de5e:\n"
        "movl $str_002b3180, 8(%esp)\n" /* line 75 */
        "movl $str_002b3138, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019de13\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19dcc6_0019de7c:\n"
        "movl $str_002b3180, 0xc(%esp)\n" /* line 81 */
        "movl $str_002b31fc, 8(%esp)\n" /* "CodeCallback_PlayerDamage" */
        "movl $str_002b3154, 4(%esp)\n" /* "Could not find label '%s' in script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019ddfd\n"
        ".Lf19dcc6_0019dea5:\n"
        "movl $str_002b3180, 8(%esp)\n" /* line 75 */
        "movl $str_002b3138, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019dde3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19dcc6_0019dec6:\n"
        "movl $str_002b3180, 0xc(%esp)\n" /* line 81 */
        "movl $str_002b31dc, 8(%esp)\n" /* "CodeCallback_PlayerDisconnect" */
        "movl $str_002b3154, 4(%esp)\n" /* "Could not find label '%s' in script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019ddc9\n"
        ".Lf19dcc6_0019deef:\n"
        "movl $str_002b3180, 8(%esp)\n" /* line 75 */
        "movl $str_002b3138, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019ddab\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19dcc6_0019df10:\n"
        "movl $str_002b3180, 0xc(%esp)\n" /* line 81 */
        "movl $str_002b31c0, 8(%esp)\n" /* "CodeCallback_PlayerConnect" */
        "movl $str_002b3154, 4(%esp)\n" /* "Could not find label '%s' in script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019dd91\n"
        ".Lf19dcc6_0019df39:\n"
        "movl $str_002b3180, 8(%esp)\n" /* line 75 */
        "movl $str_002b3138, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019dd73\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19dcc6_0019df5a:\n"
        "movl $str_002b3180, 0xc(%esp)\n" /* line 81 */
        "movl $str_002b31a4, 8(%esp)\n" /* "CodeCallback_StartGameType" */
        "movl $str_002b3154, 4(%esp)\n" /* "Could not find label '%s' in script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019dd59\n"
        ".Lf19dcc6_0019df83:\n"
        "movl $str_002b3180, 8(%esp)\n" /* line 75 */
        "movl $str_002b3138, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019dd3b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19dcc6_0019dfa4:\n"
        "movl %esi, 0xc(%esp)\n" /* line 81 */
        "movl $str_00216f3c, 8(%esp)\n" /* "main" */
        "movl $str_002b3154, 4(%esp)\n" /* "Could not find label '%s' in script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019dd21\n"
        ".Lf19dcc6_0019dfc9:\n"
        "movl %esi, 8(%esp)\n" /* line 75 */
        "movl $str_002b3138, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dcc6_0019dd07\n"
    );
}

/* line 133 */
__attribute__((naked))
unsigned int GScr_LoadScripts(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 133 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        "calll Scr_BeginLoadScripts\n" /* line 135 */
        /* { scope 1 */
        "movl $str_002b3234, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "je .Lf19dfe6_0019e12b\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 77 */
        "movl $str_002b3234, (%esp)\n" /* "codescripts/delete" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "je .Lf19dfe6_0019e165\n"
        /* } scope */
        ".Lf19dfe6_0019e024:\n"
        "movl %ebx, g_scr_data+4268\n" /* line 137 | func */
        /* { scope 1 */
        "movl $str_002b3248, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "je .Lf19dfe6_0019e1a3\n"
        ".Lf19dfe6_0019e03e:\n"
        "movl $str_002b325c, 4(%esp)\n" /* line 77 */
        "movl $str_002b3248, (%esp)\n" /* "codescripts/struct" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "je .Lf19dfe6_0019e1dd\n"
        /* } scope */
        ".Lf19dfe6_0019e05c:\n"
        "movl %ebx, g_scr_data+4272\n" /* line 138 | func */
        /* { scope 1 */
        "movl $str_002b3248, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "je .Lf19dfe6_0019e21b\n"
        ".Lf19dfe6_0019e076:\n"
        "movl $str_002b3268, 4(%esp)\n" /* line 77 */
        "movl $str_002b3248, (%esp)\n" /* "codescripts/struct" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "je .Lf19dfe6_0019e255\n"
        /* } scope */
        ".Lf19dfe6_0019e094:\n"
        "movl %ebx, g_scr_data+4276\n" /* line 139 | func */
        "calll GScr_LoadGameTypeScript\n" /* line 141 */
        "movl $0x1044, 8(%esp)\n" /* line 111 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002a7124, (%esp)\n" /* "mapname" */
        "calll Dvar_RegisterString_mac\n"
        "movl 8(%eax), %eax\n" /* line 112 */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3278, 8(%esp)\n" /* "maps/mp/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x48(%ebp), %ebx\n" /* func */
        "movl %ebx, (%esp)\n" /* func */
        "calll Com_sprintf\n"
        "movl %ebx, (%esp)\n" /* line 72 | func */
        "calll Scr_LoadScript\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 77 */
        "movl %ebx, (%esp)\n" /* func */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, g_scr_data\n" /* line 114 */
        "calll Scr_PostCompileScripts\n" /* line 144 */
        "xorl %ebx, %ebx\n" /* func */
        ".Lf19dfe6_0019e101:\n"
        "movl %ebx, (%esp)\n" /* line 124 | func */
        "calll Scr_SetClassMap\n"
        "addl $1, %ebx\n" /* line 123 | func */
        "cmpl $4, %ebx\n" /* func */
        "jne .Lf19dfe6_0019e101\n"
        "calll GScr_AddFieldsForEntity\n" /* line 126 */
        "calll GScr_AddFieldsForHudElems\n" /* line 127 */
        "calll GScr_AddFieldsForRadiant\n" /* line 129 */
        "calll Scr_EndLoadScripts\n" /* line 148 */
        "addl $0x54, %esp\n" /* line 149 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19dfe6_0019e12b:\n"
        "movl $str_002b3234, 8(%esp)\n" /* line 75 */
        "movl $str_002b3138, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 77 */
        "movl $str_002b3234, (%esp)\n" /* "codescripts/delete" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "jne .Lf19dfe6_0019e024\n"
        ".Lf19dfe6_0019e165:\n"
        "movl $str_002b3234, 0xc(%esp)\n" /* line 81 */
        "movl $str_00216f3c, 8(%esp)\n" /* "main" */
        "movl $str_002b3154, 4(%esp)\n" /* "Could not find label '%s' in script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "movl %ebx, g_scr_data+4268\n" /* line 137 | func */
        /* { scope 1 */
        "movl $str_002b3248, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "jne .Lf19dfe6_0019e03e\n"
        ".Lf19dfe6_0019e1a3:\n"
        "movl $str_002b3248, 8(%esp)\n" /* line 75 */
        "movl $str_002b3138, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $str_002b325c, 4(%esp)\n" /* line 77 */
        "movl $str_002b3248, (%esp)\n" /* "codescripts/struct" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "jne .Lf19dfe6_0019e05c\n"
        ".Lf19dfe6_0019e1dd:\n"
        "movl $str_002b3248, 0xc(%esp)\n" /* line 81 */
        "movl $str_002b325c, 8(%esp)\n" /* "initstructs" */
        "movl $str_002b3154, 4(%esp)\n" /* "Could not find label '%s' in script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "movl %ebx, g_scr_data+4272\n" /* line 138 | func */
        /* { scope 1 */
        "movl $str_002b3248, (%esp)\n" /* line 72 */
        "calll Scr_LoadScript\n"
        "testl %eax, %eax\n"
        "jne .Lf19dfe6_0019e076\n"
        ".Lf19dfe6_0019e21b:\n"
        "movl $str_002b3248, 8(%esp)\n" /* line 75 */
        "movl $str_002b3138, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $str_002b3268, 4(%esp)\n" /* line 77 */
        "movl $str_002b3248, (%esp)\n" /* "codescripts/struct" */
        "calll Scr_GetFunctionHandle\n"
        "movl %eax, %ebx\n" /* func */
        "testl %eax, %eax\n" /* line 78 */
        "jne .Lf19dfe6_0019e094\n"
        ".Lf19dfe6_0019e255:\n"
        "movl $str_002b3248, 0xc(%esp)\n" /* line 81 */
        "movl $str_002b3268, 8(%esp)\n" /* "createstruct" */
        "movl $str_002b3154, 4(%esp)\n" /* "Could not find label '%s' in script '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19dfe6_0019e094\n"
    );
}

#else
unsigned int Scr_Objective_OnEntity(void) {
    int objIndex;
    byte *obj;
    int oldEntityNum;
    gentity_t *oldEnt;
    gentity_t *newEnt;

    objIndex = Scr_GetInt(0);
    if ((unsigned int)objIndex > 0xf) {
        Scr_ParamError(0, va("index %i is an illegal objective index. Valid indexes are 0 to %i\n", objIndex, 0xf));
    }

    /* obj = &level.objectives[objIndex] */
    obj = (byte *)&((level_locals_t *)imp_level)->objectives[objIndex];

    /* Clear old entity's objective flag */
    oldEntityNum = ((objective_t *)obj)->entNum;
    if (oldEntityNum != 0x3ff) {
        oldEnt = (gentity_t *)((byte *)imp_g_entities + oldEntityNum * 0x230);
        if (oldEnt->r.inuse) {
            /* Clear EF_OBJECTIVE flag (0x10) */
            oldEnt->r.svFlags &= ~0x10;
        }
        ((objective_t *)obj)->entNum = 0x3ff;
    }

    /* Set new entity */
    newEnt = Scr_GetEntity(1);
    /* Set EF_OBJECTIVE flag */
    newEnt->r.svFlags |= 0x10;
    /* Store entity number */
    ((objective_t *)obj)->entNum = newEnt->s.number;

    return 0;
}
#endif
