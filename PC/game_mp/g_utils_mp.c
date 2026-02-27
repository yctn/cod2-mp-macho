/* Decompiled from: g_utils_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_utils_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern const char * SV_GetConfigstringConst(int index);
extern void SV_SetConfigstring(int index, const char *val);
extern void Scr_Error(const char *msg);
extern char * va(const char *format, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern int stricmp(const char *s1, const char *s2);
extern void I_strlwr(char *str);
extern struct XModel * SV_XModelGet(const char *name);
extern void Com_SafeServerDObjFree(int entnum);
extern qboolean SV_DObjUpdateServerTime(gentity_t *ent, float time, qboolean bNotify);
extern qboolean SV_DObjCreateSkelForBones(gentity_t *ent, int *partBits);
extern qboolean SV_DObjCreateSkelForBone(gentity_t *ent, int boneIndex);
extern void SV_DObjGetHierarchyBits(gentity_t *ent, int boneIndex, int *partBits);
extern void SV_DObjCalcAnim(gentity_t *ent, int *partBits);
extern void SV_DObjCalcSkel(gentity_t *ent, int *partBits);
extern int SV_DObjGetBoneIndex(gentity_t *ent, unsigned int tagName);
extern void * SV_DObjGetMatrixArray(gentity_t *ent);
extern void Scr_SetString(scr_string_t *to, unsigned int value);
extern unsigned int SL_GetString(const char *str, int type);
extern const char * SL_ConvertToString(unsigned int id);
extern void AnglesToAxis(const vec_t *angles, vec_t *axis);
extern void AxisToAngles(const vec_t *axis, vec_t *angles);
extern float vectoyaw(const vec_t *vec);
extern void MatrixMultiply(const vec_t *in1, const vec_t *in2, vec_t *out);
extern void MatrixMultiply43(const vec_t *in1, const vec_t *in2, vec_t *out);
extern void MatrixTransformVector43(const vec_t *in, const vec_t *mat, vec_t *out);
extern void MatrixTranspose(const vec_t *in, vec_t *out);
extern void MatrixInverseOrthogonal43(const vec_t *in, vec_t *out);
extern void SetClientViewAngle(gentity_t *ent, const vec_t *angles);
extern void * MT_Alloc(int size, int type);
extern void MT_Free(void *ptr, int size);
extern void SV_LinkEntity(gentity_t *ent);
extern void SV_UnlinkEntity(gentity_t *ent);
extern void * SV_DObjGetTree(gentity_t *ent);
extern void XAnimClearTree(void *tree);
extern void G_FreeTurret(gentity_t *ent);
extern void Scr_FreeEntity(gentity_t *ent);
extern unsigned int Scr_ExecEntThread(gentity_t *ent, int callback, int numArgs);
extern void Scr_FreeThread(unsigned short thread);
extern void BG_AddPredictableEventToPlayerstate(int event, int eventParm, void *ps);
extern qboolean XModelBad(struct XModel *model);
extern void Hunk_OverrideDataForFile(int type, const char *name, void *data);
extern float Vec3DistanceSq(const vec_t *a, const vec_t *b);
extern void Com_ServerDObjCreate(void *models, unsigned short numModels, int unused, int entnum);
extern void SV_LocateGameData(void *gEnts, int numGEntities, int sizeofGEntity, void *clients, int sizeofGameClient);
extern qboolean SV_DObjExists(gentity_t *ent);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 */

static struct XModel * cached_models[256]; /* 0xfdf380 */

/*
 * Binary gentity_s layout (byte offsets):
 *   0x00  s.number           0x04  s.eType            0x08  s.eFlags
 *   0x0C  s.pos (trajectory) 0x18  s.pos.trBase       0x24  s.pos.trDelta
 *   0x30  s.apos             0x3C  s.apos.trBase      0x48  s.apos.trDelta
 *   0x7C  s.otherEntityNum   0x8C  s.weapon
 *   0xA4  s.eventSequence    0xA8  s.events[4]        0xB8  s.eventParms[4]
 *   0xFC  r.inuse            0x138 r.currentOrigin     0x144 r.currentAngles
 *   0x150 r.ownerNum         0x154 r.eventTime
 *   0x158 client             0x15C turretInfo
 *   0x164 s.modelindex       0x165 attachIgnoreCollision
 *   0x166 handler            0x168 classname
 *   0x174 flags              0x178 freetime           0x17C freeAfterEvent
 *   0x18C parent             0x208 tagInfo            0x20C tagChildren
 *   0x210 attachModelIndex[7] 0x218 attachTagNames[7]
 *   0x228 useCount           0x22C nextFreeEnt
 *   Entity stride = 0x230
 */

#define ENT_NUMBER(e)          (*(int *)((byte *)(e) + 0x00))
#define ENT_ETYPE(e)           (*(int *)((byte *)(e) + 0x04))
#define ENT_EFLAGS(e)          (*(int *)((byte *)(e) + 0x08))
#define ENT_POS_TRTYPE(e)      (*(int *)((byte *)(e) + 0x0C))
#define ENT_POS_TRTIME(e)      (*(int *)((byte *)(e) + 0x10))
#define ENT_POS_TRDURATION(e)  (*(int *)((byte *)(e) + 0x14))
#define ENT_POS_TRBASE(e)      ((vec_t *)((byte *)(e) + 0x18))
#define ENT_POS_TRDELTA(e)     ((vec_t *)((byte *)(e) + 0x24))
#define ENT_APOS_TRTYPE(e)     (*(int *)((byte *)(e) + 0x30))
#define ENT_APOS_TRTIME(e)     (*(int *)((byte *)(e) + 0x34))
#define ENT_APOS_TRDURATION(e) (*(int *)((byte *)(e) + 0x38))
#define ENT_APOS_TRBASE(e)     ((vec_t *)((byte *)(e) + 0x3C))
#define ENT_APOS_TRDELTA(e)    ((vec_t *)((byte *)(e) + 0x48))
#define ENT_OTHERENTNUM(e)     (*(int *)((byte *)(e) + 0x7C))
#define ENT_WEAPON(e)          (*(int *)((byte *)(e) + 0x8C))
#define ENT_EVENTSEQ(e)        (*(int *)((byte *)(e) + 0xA4))
#define ENT_EVENTS(e, i)       (*(int *)((byte *)(e) + 0xA8 + (i)*4))
#define ENT_EVENTPARMS(e, i)   (*(int *)((byte *)(e) + 0xB8 + (i)*4))
#define ENT_INUSE(e)           (*(byte *)((byte *)(e) + 0xFC))
#define ENT_CURRENTORIGIN(e)   ((vec_t *)((byte *)(e) + 0x138))
#define ENT_CURRENTANGLES(e)   ((vec_t *)((byte *)(e) + 0x144))
#define ENT_OWNERNUM(e)        (*(int *)((byte *)(e) + 0x150))
#define ENT_EVENTTIME(e)       (*(int *)((byte *)(e) + 0x154))
#define ENT_CLIENT(e)          (*(byte **)((byte *)(e) + 0x158))
#define ENT_TURRET(e)          (*(int *)((byte *)(e) + 0x15C))
#define ENT_MODELINDEX(e)      (*(byte *)((byte *)(e) + 0x164))
#define ENT_IGNORECOLLISION(e) (*(byte *)((byte *)(e) + 0x165))
#define ENT_HANDLER(e)         (*(byte *)((byte *)(e) + 0x166))
#define ENT_CLASSNAME(e)       (*(unsigned short *)((byte *)(e) + 0x168))
#define ENT_FLAGS(e)           (*(int *)((byte *)(e) + 0x174))
#define ENT_FREETIME(e)        (*(int *)((byte *)(e) + 0x178))
#define ENT_FREEAFTEREVENT(e)  (*(int *)((byte *)(e) + 0x17C))
#define ENT_PARENT(e)          (*(gentity_t **)((byte *)(e) + 0x18C))
#define ENT_TAGINFO(e)         (*(byte **)((byte *)(e) + 0x208))
#define ENT_TAGCHILDREN(e)     (*(gentity_t **)((byte *)(e) + 0x20C))
#define ENT_ATTACHMODEL(e, i)  (*(byte *)((byte *)(e) + 0x210 + (i)))
#define ENT_ATTACHTAG(e, i)    (*(unsigned short *)((byte *)(e) + 0x218 + (i)*2))
#define ENT_USECOUNT(e)        (*(int *)((byte *)(e) + 0x228))
#define ENT_NEXTFREEENT(e)     (*(gentity_t **)((byte *)(e) + 0x22C))

#define ENTITY_STRIDE 0x230

/* TagInfo structure (0x70 bytes allocated with MT_Alloc):
 *   0x00  parent (gentity_t *)
 *   0x04  next (gentity_t *)
 *   0x08  tagName (scr_string_t - unsigned short)
 *   0x0C  boneIndex (int)
 *   0x10  axis (vec3_t[3] = 36 bytes) - relative rotation
 *   0x34  origin (vec3_t = 12 bytes) - relative offset
 *   0x40  padding (48 bytes)
 */
#define TAGINFO_PARENT(ti)     (*(gentity_t **)((byte *)(ti) + 0x00))
#define TAGINFO_NEXT(ti)       (*(gentity_t **)((byte *)(ti) + 0x04))
#define TAGINFO_TAGNAME(ti)    (*(unsigned short *)((byte *)(ti) + 0x08))
#define TAGINFO_BONEINDEX(ti)  (*(int *)((byte *)(ti) + 0x0C))
#define TAGINFO_AXIS(ti)       ((vec_t *)((byte *)(ti) + 0x10))
#define TAGINFO_ORIGIN(ti)     ((vec_t *)((byte *)(ti) + 0x34))

/* External globals */
extern byte *level_ptr;              /* 0x195f6a0 */
extern byte *g_entities_ptr;         /* 0x195f688 */
extern byte *scr_const_ptr;          /* 0x195f5bc */
extern byte *entityHandlers_ptr;     /* 0x195f6b4 */
extern byte *playerCorpseInfo_ptr;   /* 0x195f6d0 */

#define LEVEL_GENTITIES     (*(byte **)(level_ptr + 0x04))
#define LEVEL_NUMENTS       (*(int *)(level_ptr + 0x0C))
#define LEVEL_FIRSTFREEENT  (*(gentity_t **)(level_ptr + 0x10))
#define LEVEL_LASTFREEENT   (*(gentity_t **)(level_ptr + 0x14))
#define LEVEL_INITIALIZING  (*(int *)(level_ptr + 0x1C))
#define LEVEL_TIME          (*(int *)(level_ptr + 0x1EC))
#define LEVEL_SERVERTIME    (*(int *)(level_ptr + 0x1F4))
#define LEVEL_CLONEIDX      (*(int *)(level_ptr + 0x1DE4))

/* Handler table: each entry is 40 bytes */
#define HANDLER_ENTRY(h)       (entityHandlers_ptr + (h) * 40)
#define HANDLER_CALCPOSE(h)    (*(void (**)(gentity_t *, int *))(HANDLER_ENTRY(h) + 0x1C))

/* PlayerCorpseInfo: stride 0x4C8, field 0x10AC = callback, 0x10BC = entnum */
#define CORPSE_ENTNUM(ptr, i)  (*(int *)((byte *)(ptr) + (i) * 0x4C8 + 0x10BC))
#define CORPSE_CALLBACK(ptr)   (*(int *)((byte *)(ptr) + 0x10AC))

/* Client structure offsets */
#define CLIENT_EVENTSEQ(c)     (*(int *)((byte *)(c) + 0xA4))
#define CLIENT_EVENTS(c, i)    (*(int *)((byte *)(c) + 0xA8 + (i)*4))
#define CLIENT_EVENTPARMS(c, i)(*(int *)((byte *)(c) + 0xB8 + (i)*4))
#define CLIENT_VIEWANGLES(c)   ((vec_t *)((byte *)(c) + 0xE8))
#define CLIENT_OWNERENT(c)     (*(gentity_t **)((byte *)(c) + 0x282C))
#define CLIENT_OWNERNUM(c)     (*(int *)((byte *)(c) + 0x2830))
#define CLIENT_WEAPENT(c)      (*(int *)((byte *)(c) + 0x5A0))

/* VectorCopy / VectorClear */
#define VectorCopy(a, b) ((b)[0]=(a)[0], (b)[1]=(a)[1], (b)[2]=(a)[2])
#define VectorClear(v)   ((v)[0]=0, (v)[1]=0, (v)[2]=0)

/* Forward declarations */
int G_FindConfigstringIndex(const char *name, int start, int max, qboolean create, const char *errormsg);
int G_LocalizedStringIndex(const char *string);
int G_ShaderIndex(const char *name);
int G_ModelIndex(const char *name);
const char * G_ModelName(int index);
int G_TagIndex(const char *name);
int G_EffectIndex(const char *name);
int G_ShellShockIndex(const char *name);
SoundAlias G_SoundAliasIndex(const char *name);
unsigned char G_SetModel(gentity_t *ent, const char *modelName);
unsigned char G_SafeDObjFree(gentity_t *ent);
qboolean G_DObjUpdateServerTime(gentity_t *ent, qboolean bNotify);
unsigned char G_DObjCalcPose(gentity_t *ent);
unsigned char G_DObjCalcBone(gentity_t *ent, int boneIndex);
DObjAnimMat_s * G_DObjGetLocalTagMatrix(gentity_t *ent, unsigned int tagName);
unsigned char G_InitGentity(gentity_t *e);
unsigned char G_PrintEntities(void);
int G_GetPlayerCorpseIndex(gentity_t *ent);
unsigned char G_FreeEntityDelay(gentity_t *ed);
unsigned char G_AddPredictableEvent(gentity_t *ent, int event, int eventParm);
unsigned char G_AddEvent(gentity_t *ent, int event, int eventParm);
unsigned char G_SetConstString(scr_string_t *to, const char *from);
unsigned char G_SetAngle(gentity_t *ent, const vec_t *angle);
qboolean G_XModelBad(int index);
unsigned char G_SetOrigin(gentity_t *ent, const vec_t *origin);
unsigned char G_PlaySoundAlias(gentity_t *ent, int index);
unsigned char G_OverrideModel(int modelindex, const char *defaultModelName);
int G_AnimScriptSound(int client, snd_alias_list_t *aliasList);
unsigned char G_CalcTagParentAxis(gentity_t *ent, vec3_t *parentAxis);
unsigned char G_SetFixedLink(gentity_t *ent, int eAngles);
unsigned char G_CalcTagAxis(gentity_t *ent, qboolean bAnglesOnly);
unsigned char G_EntUnlink(gentity_t *ent);
static qboolean G_EntLinkToInternal(gentity_t *parent);
qboolean G_EntLinkToWithOffset(gentity_t *ent, gentity_t *parent, unsigned int tagName, const vec_t *originOffset, const vec_t *anglesOffset);
qboolean G_EntLinkTo(gentity_t *ent, gentity_t *parent, unsigned int tagName);
unsigned char G_GeneralLink(gentity_t *ent);
unsigned char G_FreeEntity(gentity_t *ed);
int G_GetFreePlayerCorpseIndex(void);
unsigned char G_DObjUpdate(gentity_t *ent);
unsigned char G_EntDetachAll(gentity_t *ent);
qboolean G_EntDetach(gentity_t *ent, const char *modelName, unsigned int tagName);
qboolean G_EntAttach(gentity_t *ent, const char *modelName, unsigned int tagName, qboolean ignoreCollision);
gentity_t * G_Spawn(void);
gentity_t * G_TempEntity(const vec_t *origin, int event);
gentity_t * G_SpawnPlayerClone(void);
qboolean G_DObjGetWorldTagMatrix(gentity_t *ent, unsigned int tagName, vec3_t *tagMat);
qboolean G_DObjGetWorldTagPos(gentity_t *ent, unsigned int tagName, vec_t *pos);

/* line 44 */
int G_FindConfigstringIndex(const char *name, int start, int max, qboolean create, const char *errormsg)
{
    int i;

    if (!name || !*name) {
        return 0;
    }

    for (i = 1; i < max; i++) {
        const char *s = SV_GetConfigstringConst(start + i);
        if (!*s) {
            break;
        }
        if (!stricmp(s, name)) {
            return i;
        }
    }

    if (!create) {
        if (errormsg) {
            Scr_Error(va("%s \"%s\" not precached", errormsg, name));
        }
        return 0;
    }

    if (i == max) {
        Com_Error(1, va("G_FindConfigstringIndex: overflow (%d): '%s'", start, name));
    }

    SV_SetConfigstring(start + i, name);
    return i;
}

/* line 88 */
int G_LocalizedStringIndex(const char *string)
{
    if (!*string) {
        return 0;
    }
    return G_FindConfigstringIndex(string, 0x51e, 0x100, LEVEL_INITIALIZING, "localizedstring");
}

/* line 102 */
int G_ShaderIndex(const char *name)
{
    char shaderName[64];

    strcpy(shaderName, name);
    I_strlwr(shaderName);

    return G_FindConfigstringIndex(shaderName, 0x61e, 0x80, LEVEL_INITIALIZING, "shader");
}

/* line 121 */
int G_ModelIndex(const char *name)
{
    int i;

    if (!*name) {
        return 0;
    }

    for (i = 1; i < 256; i++) {
        const char *s = SV_GetConfigstringConst(0x14e + i);
        if (!*s) {
            break;
        }
        if (!stricmp(s, name)) {
            return i;
        }
    }

    if (!LEVEL_INITIALIZING) {
        Scr_Error(va("model '%s' not precached", name));
    }

    if (i == 256) {
        Com_Error(1, "G_ModelIndex: overflow");
    }

    cached_models[i] = SV_XModelGet(name);
    SV_SetConfigstring(0x14e + i, name);
    return i;
}

/* line 186 */
const char * G_ModelName(int index)
{
    return SV_GetConfigstringConst(index + 0x14e);
}

/* line 193 */
int G_TagIndex(const char *name)
{
    return G_FindConfigstringIndex(name, 0x6e, 0x20, 1, 0);
}

/* line 200 */
int G_EffectIndex(const char *name)
{
    return G_FindConfigstringIndex(name, 0x34e, 0x40, LEVEL_INITIALIZING, "effect");
}

/* line 207 */
int G_ShellShockIndex(const char *name)
{
    return G_FindConfigstringIndex(name, 0x48e, 0x10, 1, 0);
}

/* line 214 */
SoundAlias G_SoundAliasIndex(const char *name)
{
    return (SoundAlias)(unsigned char)G_FindConfigstringIndex(name, 0x24e, 0x100, 1, 0);
}

/* line 305 */
unsigned char G_SetModel(gentity_t *ent, const char *modelName)
{
    if (!*modelName) {
        ENT_MODELINDEX(ent) = 0;
    } else {
        ENT_MODELINDEX(ent) = (byte)G_ModelIndex(modelName);
    }
}

/* line 824 */
unsigned char G_SafeDObjFree(gentity_t *ent)
{
    Com_SafeServerDObjFree(ENT_NUMBER(ent));
}

/* line 835 */
qboolean G_DObjUpdateServerTime(gentity_t *ent, qboolean bNotify)
{
    return SV_DObjUpdateServerTime(ent, (float)LEVEL_SERVERTIME * 0.001f, bNotify);
}

/* line 846 */
unsigned char G_DObjCalcPose(gentity_t *ent)
{
    int partBits[4];
    void (*calcPoseFunc)(gentity_t *, int *);

    partBits[0] = -1;
    partBits[1] = -1;
    partBits[2] = -1;
    partBits[3] = -1;

    if (SV_DObjCreateSkelForBones(ent, partBits)) {
        return 0;
    }

    SV_DObjCalcAnim(ent, partBits);

    calcPoseFunc = HANDLER_CALCPOSE(ENT_HANDLER(ent));
    if (calcPoseFunc) {
        calcPoseFunc(ent, partBits);
    }

    SV_DObjCalcSkel(ent, partBits);
}

/* line 867 */
unsigned char G_DObjCalcBone(gentity_t *ent, int boneIndex)
{
    int partBits[4];
    void (*calcPoseFunc)(gentity_t *, int *);

    if (SV_DObjCreateSkelForBone(ent, boneIndex)) {
        return 0;
    }

    SV_DObjGetHierarchyBits(ent, boneIndex, partBits);
    SV_DObjCalcAnim(ent, partBits);

    calcPoseFunc = HANDLER_CALCPOSE(ENT_HANDLER(ent));
    if (calcPoseFunc) {
        calcPoseFunc(ent, partBits);
    }

    SV_DObjCalcSkel(ent, partBits);
}

/* line 888 */
DObjAnimMat_s * G_DObjGetLocalTagMatrix(gentity_t *ent, unsigned int tagName)
{
    int boneIndex;

    boneIndex = SV_DObjGetBoneIndex(ent, tagName);
    if (boneIndex < 0) {
        return 0;
    }

    G_DObjCalcBone(ent, boneIndex);

    return (DObjAnimMat_s *)((byte *)SV_DObjGetMatrixArray(ent) + boneIndex * 32);
}

/* line 1070 */
unsigned char G_InitGentity(gentity_t *e)
{
    ENT_NEXTFREEENT(e) = 0;
    ENT_INUSE(e) = 1;
    Scr_SetString((scr_string_t *)((byte *)e + 0x168), *(unsigned short *)(scr_const_ptr + 0x2A));
    /* e->s.number = (e - g_entities) / ENTITY_STRIDE — magic multiply */
    ENT_NUMBER(e) = ((int)((byte *)e - g_entities_ptr) >> 4) * (int)0x8AF8AF8B;
    ENT_OWNERNUM(e) = 0x3FF;
    ENT_FREETIME(e) = 0;
    ENT_FREEAFTEREVENT(e) = 0;
}

/* line 1082 */
unsigned char G_PrintEntities(void)
{
    int entityIndex;
    byte *ent;

    ent = g_entities_ptr;
    for (entityIndex = 0; entityIndex < LEVEL_NUMENTS; entityIndex++) {
        const char *classStr;
        unsigned short cn = ENT_CLASSNAME(ent);
        if (!cn) {
            classStr = "";
        } else {
            classStr = SL_ConvertToString(cn);
        }
        Com_Printf("%4i: '%s', origin: %f %f %f\n",
            entityIndex, classStr,
            (double)ENT_CURRENTORIGIN(ent)[0],
            (double)ENT_CURRENTORIGIN(ent)[1],
            (double)ENT_CURRENTORIGIN(ent)[2]);
        ent += ENTITY_STRIDE;
    }
}

/* line 1248 */
int G_GetPlayerCorpseIndex(gentity_t *ent)
{
    int i;
    int entnum = ENT_NUMBER(ent);

    for (i = 0; i < 8; i++) {
        if (CORPSE_ENTNUM(playerCorpseInfo_ptr, i) == entnum) {
            return i;
        }
    }
    return 0;
}

/* line 1392 */
unsigned char G_FreeEntityDelay(gentity_t *ed)
{
    unsigned short thread;
    thread = (unsigned short)Scr_ExecEntThread(ed, CORPSE_CALLBACK(playerCorpseInfo_ptr), 0);
    Scr_FreeThread(thread);
}

/* line 1492 */
unsigned char G_AddPredictableEvent(gentity_t *ent, int event, int eventParm)
{
    byte *ps = ENT_CLIENT(ent);
    if (ps) {
        BG_AddPredictableEventToPlayerstate(event, eventParm, ps);
    }
}

/* line 1509 */
unsigned char G_AddEvent(gentity_t *ent, int event, int eventParm)
{
    byte *client = ENT_CLIENT(ent);

    if (client) {
        int seq = CLIENT_EVENTSEQ(client);
        CLIENT_EVENTS(client, seq & 3) = event;
        CLIENT_EVENTPARMS(client, seq & 3) = eventParm;
        CLIENT_EVENTSEQ(client) = seq + 1;
    } else {
        int seq = ENT_EVENTSEQ(ent);
        ENT_EVENTS(ent, seq & 3) = event;
        ENT_EVENTPARMS(ent, seq & 3) = eventParm;
        ENT_EVENTSEQ(ent) = seq + 1;
    }

    ENT_FREETIME(ent) = LEVEL_TIME;
    ENT_EVENTTIME(ent) = LEVEL_TIME;
}

/* line 1673 */
unsigned char G_SetConstString(scr_string_t *to, const char *from)
{
    Scr_SetString(to, 0);
    *(unsigned short *)to = (unsigned short)SL_GetString(from, 0);
}

/* line 1617 */
unsigned char G_SetAngle(gentity_t *ent, const vec_t *angle)
{
    VectorCopy(angle, ENT_APOS_TRBASE(ent));
    ENT_APOS_TRTYPE(ent) = 0;
    ENT_APOS_TRTIME(ent) = 0;
    ENT_APOS_TRDURATION(ent) = 0;
    VectorClear(ENT_APOS_TRDELTA(ent));
    VectorCopy(angle, ENT_CURRENTANGLES(ent));
}

/* line 179 */
qboolean G_XModelBad(int index)
{
    return XModelBad(cached_models[index]);
}

/* line 1600 */
unsigned char G_SetOrigin(gentity_t *ent, const vec_t *origin)
{
    VectorCopy(origin, ENT_POS_TRBASE(ent));
    ENT_POS_TRTYPE(ent) = 0;
    ENT_POS_TRTIME(ent) = 0;
    ENT_POS_TRDURATION(ent) = 0;
    VectorClear(ENT_POS_TRDELTA(ent));
    VectorCopy(origin, ENT_CURRENTORIGIN(ent));
}

/* line 1556 - inlined G_AddEvent with event=0xB3 */
unsigned char G_PlaySoundAlias(gentity_t *ent, int index)
{
    byte soundIndex = (byte)index;
    byte *client;

    if (!soundIndex) {
        return 0;
    }

    client = ENT_CLIENT(ent);
    if (client) {
        int seq = CLIENT_EVENTSEQ(client);
        CLIENT_EVENTS(client, seq & 3) = 0xB3;
        CLIENT_EVENTPARMS(client, seq & 3) = (int)soundIndex;
        CLIENT_EVENTSEQ(client) = seq + 1;
    } else {
        int seq = ENT_EVENTSEQ(ent);
        ENT_EVENTS(ent, seq & 3) = 0xB3;
        ENT_EVENTPARMS(ent, seq & 3) = (int)soundIndex;
        ENT_EVENTSEQ(ent) = seq + 1;
    }

    ENT_FREETIME(ent) = LEVEL_TIME;
    ENT_EVENTTIME(ent) = LEVEL_TIME;
}

/* line 325 */
unsigned char G_OverrideModel(int modelindex, const char *defaultModelName)
{
    const char *modelName = SV_GetConfigstringConst(0x14e + modelindex);

    cached_models[modelindex] = SV_XModelGet(defaultModelName);
    Hunk_OverrideDataForFile(4, modelName + 7, cached_models[modelindex]);
}

/* line 1584 - calls G_SoundAliasIndex then inlined G_PlaySoundAlias */
int G_AnimScriptSound(int client, snd_alias_list_t *aliasList)
{
    byte soundIndex;
    byte *ent;

    soundIndex = (byte)G_FindConfigstringIndex(*(const char **)aliasList, 0x24e, 0x100, 1, 0);

    /* compute entity pointer: g_entities + client * ENTITY_STRIDE */
    ent = g_entities_ptr + ((client * 5) * 8 - client * 5) * 16;

    if (soundIndex) {
        byte *cl = ENT_CLIENT(ent);
        if (cl) {
            int seq = CLIENT_EVENTSEQ(cl);
            CLIENT_EVENTS(cl, seq & 3) = 0xB3;
            CLIENT_EVENTPARMS(cl, seq & 3) = (int)soundIndex;
            CLIENT_EVENTSEQ(cl) = seq + 1;
        } else {
            int seq = ENT_EVENTSEQ(ent);
            ENT_EVENTS(ent, seq & 3) = 0xB3;
            ENT_EVENTPARMS(ent, seq & 3) = (int)soundIndex;
            ENT_EVENTSEQ(ent) = seq + 1;
        }

        ENT_FREETIME(ent) = LEVEL_TIME;
        ENT_EVENTTIME(ent) = LEVEL_TIME;
    }

    return 0;
}

/* line 674 */
unsigned char G_CalcTagParentAxis(gentity_t *ent, vec3_t *parentAxis)
{
    byte *tagInfo = ENT_TAGINFO(ent);
    gentity_t *parent = TAGINFO_PARENT(tagInfo);
    int boneIndex = TAGINFO_BONEINDEX(tagInfo);

    if (boneIndex < 0) {
        /* No bone - just use parent's angles and origin */
        AnglesToAxis(ENT_CURRENTANGLES(parent), (vec_t *)parentAxis);
        VectorCopy(ENT_CURRENTORIGIN(parent), ((vec_t *)parentAxis + 9));
    } else {
        vec3_t tempAxis[3];
        vec3_t axis[3];
        vec3_t origin;
        DObjAnimMat_s *mat;

        AnglesToAxis(ENT_CURRENTANGLES(parent), (vec_t *)tempAxis);
        VectorCopy(ENT_CURRENTORIGIN(parent), origin);

        G_DObjCalcBone(parent, boneIndex);
        mat = (DObjAnimMat_s *)((byte *)SV_DObjGetMatrixArray(parent) + boneIndex * 32);

        /* QuatToAxis inline - convert quaternion mat to axis */
        {
            float scale = mat->transWeight;
            float x = scale * mat->quat[0];
            float y = scale * mat->quat[1];
            float z = scale * mat->quat[2];
            float xx = x * mat->quat[0];
            float xy = x * mat->quat[1];
            float xz = x * mat->quat[2];
            float xw = x * mat->quat[3];
            float yy = y * mat->quat[1];
            float yz = y * mat->quat[2];
            float yw = y * mat->quat[3];
            float zz = z * mat->quat[2];
            float zw = z * mat->quat[3];

            axis[0][0] = 1.0f - (yy + zz);
            axis[0][1] = zw + xy;
            axis[0][2] = xz - yw;
            axis[1][0] = xy - zw;
            axis[1][1] = 1.0f - (xx + zz);
            axis[1][2] = xw + yz;
            axis[2][0] = xz + yw;
            axis[2][1] = yz - xw;
            axis[2][2] = 1.0f - (xx + yy);
        }

        MatrixMultiply((vec_t *)axis, (vec_t *)tempAxis, (vec_t *)parentAxis);
        MatrixTransformVector43((vec_t *)&mat->trans, (vec_t *)tempAxis, ((vec_t *)parentAxis + 9));
    }
}

/* line 765 */
unsigned char G_SetFixedLink(gentity_t *ent, int eAngles)
{
    vec3_t parentAxis[4]; /* 3x3 rotation + origin */
    byte *tagInfo;
    vec3_t axis[4]; /* 3x3 rotation + origin */

    G_CalcTagParentAxis(ent, parentAxis);
    tagInfo = ENT_TAGINFO(ent);

    switch (eAngles) {
    case 0:
        MatrixMultiply43(TAGINFO_AXIS(tagInfo), (vec_t *)parentAxis, (vec_t *)axis);
        VectorCopy(((vec_t *)axis + 9), ENT_CURRENTORIGIN(ent));
        AxisToAngles((vec_t *)axis, ENT_CURRENTANGLES(ent));
        break;
    case 1:
        MatrixMultiply43(TAGINFO_AXIS(tagInfo), (vec_t *)parentAxis, (vec_t *)axis);
        VectorCopy(((vec_t *)axis + 9), ENT_CURRENTORIGIN(ent));
        ENT_CURRENTANGLES(ent)[1] = vectoyaw((vec_t *)axis);
        break;
    case 2:
        MatrixTransformVector43(TAGINFO_ORIGIN(tagInfo), (vec_t *)parentAxis, ENT_CURRENTORIGIN(ent));
        break;
    }
}

/* line 732 */
unsigned char G_CalcTagAxis(gentity_t *ent, qboolean bAnglesOnly)
{
    vec3_t parentAxis[4];
    vec3_t axis[3];
    byte *tagInfo;
    vec3_t invParentAxis[4];

    G_CalcTagParentAxis(ent, parentAxis);
    AnglesToAxis(ENT_CURRENTANGLES(ent), (vec_t *)axis);
    tagInfo = ENT_TAGINFO(ent);

    if (bAnglesOnly) {
        MatrixTranspose((vec_t *)parentAxis, (vec_t *)invParentAxis);
        MatrixMultiply((vec_t *)axis, (vec_t *)invParentAxis, TAGINFO_AXIS(tagInfo));
    } else {
        vec3_t origin;
        MatrixInverseOrthogonal43((vec_t *)parentAxis, (vec_t *)invParentAxis);
        VectorCopy(ENT_CURRENTORIGIN(ent), origin);
        MatrixMultiply43((vec_t *)axis, (vec_t *)invParentAxis, TAGINFO_AXIS(tagInfo));
    }
}

/* line 552 */
unsigned char G_EntUnlink(gentity_t *ent)
{
    byte *tagInfo = ENT_TAGINFO(ent);
    if (!tagInfo) {
        return 0;
    }

    /* G_SetOrigin inline - copy currentOrigin to pos.trBase */
    VectorCopy(ENT_CURRENTORIGIN(ent), ENT_POS_TRBASE(ent));
    ENT_POS_TRTYPE(ent) = 0;
    ENT_POS_TRTIME(ent) = 0;
    ENT_POS_TRDURATION(ent) = 0;
    VectorClear(ENT_POS_TRDELTA(ent));

    /* G_SetAngle inline */
    VectorCopy(ENT_CURRENTANGLES(ent), ENT_APOS_TRBASE(ent));
    ENT_APOS_TRTYPE(ent) = 0;
    ENT_APOS_TRTIME(ent) = 0;
    ENT_APOS_TRDURATION(ent) = 0;
    VectorClear(ENT_APOS_TRDELTA(ent));

    /* Set client view angle if has client */
    if (ENT_CLIENT(ent)) {
        byte *client = ENT_CLIENT(ent);
        vec3_t viewAngles;
        viewAngles[0] = CLIENT_VIEWANGLES(client)[0];
        viewAngles[1] = CLIENT_VIEWANGLES(client)[1];
        viewAngles[2] = 0;
        SetClientViewAngle(ent, viewAngles);
    }

    /* Remove from parent's linked list */
    {
        gentity_t *parent = TAGINFO_PARENT(tagInfo);
        gentity_t *child = ENT_TAGCHILDREN(parent);

        if (child == ent) {
            /* First child - just update parent's first child pointer */
            ENT_TAGCHILDREN(parent) = TAGINFO_NEXT(tagInfo);
        } else {
            /* Find in linked list */
            while (child) {
                byte *childTag = ENT_TAGINFO(child);
                gentity_t *next = TAGINFO_NEXT(childTag);
                if (next == ent) {
                    TAGINFO_NEXT(childTag) = TAGINFO_NEXT(tagInfo);
                    break;
                }
                child = next;
            }
        }
    }

    ENT_TAGINFO(ent) = 0;
    Scr_SetString((scr_string_t *)(tagInfo + 0x08), 0);
    MT_Free(tagInfo, 0x70);
}

/* line 458 */
static qboolean G_EntLinkToInternal(gentity_t *parent)
{
    /* NOTE: uses register calling convention in binary:
     * eax=ent, edx=parent, ecx=tagName
     * We replicate with standard C args and let compiler handle it */
    /* This function is only called internally; the binary passes
     * ent in eax, parent in edx, tagName in ecx.
     * We restructure to take parent as the stack arg and ent/tagName
     * are passed by callers via registers. In C we flatten this. */
    return 0; /* placeholder - implemented as naked below */
}

/* line 458 - keep as naked due to register calling convention */
__attribute__((naked))
static qboolean __G_EntLinkToInternal(gentity_t *parent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %esi\n" /* ent */
        "movl %edx, -0x20(%ebp)\n"
        "movl %ecx, %edi\n" /* tagName */
        "movl %eax, (%esp)\n"
        "calll G_EntUnlink\n"
        "testl %edi, %edi\n" /* tagName */
        "jne .Llink_has_tag\n"
        "movl $0xffffffff, -0x1c(%ebp)\n" /* index */
        ".Llink_check_cycle:\n"
        "cmpl -0x20(%ebp), %esi\n" /* ent == parent? */
        "je .Llink_fail\n"
        "movl -0x20(%ebp), %ecx\n"
        "movl 0x208(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Llink_alloc\n"
        ".Llink_walk:\n"
        "movl (%eax), %eax\n"
        "cmpl %eax, %esi\n" /* ent == walk? */
        "je .Llink_fail\n"
        "movl 0x208(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Llink_walk\n"
        ".Llink_alloc:\n"
        "movl $0x10, 4(%esp)\n"
        "movl $0x70, (%esp)\n"
        "calll MT_Alloc\n"
        "movl %eax, %ebx\n"
        "movl -0x20(%ebp), %ecx\n"
        "movl %ecx, (%eax)\n"
        "movw $0, 8(%eax)\n"
        "movl %edi, 4(%esp)\n"
        "leal 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl -0x20(%ebp), %edx\n"
        "movl 0x20c(%edx), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl %ecx, 0xc(%ebx)\n"
        "leal 0x10(%ebx), %edi\n"
        "cld\n"
        "xorl %eax, %eax\n"
        "movl $0xc, %ecx\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %esi, 0x20c(%edx)\n"
        "movl %ebx, 0x208(%esi)\n"
        "leal 0x40(%ebx), %edi\n"
        "movb $0xc, %cl\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movb $1, %al\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Llink_has_tag:\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_DObjExists\n"
        "testl %eax, %eax\n"
        "jne .Llink_get_bone\n"
        ".Llink_fail:\n"
        "xorl %eax, %eax\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Llink_get_bone:\n"
        "movl %edi, 4(%esp)\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll SV_DObjGetBoneIndex\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %eax, %eax\n"
        "jns .Llink_check_cycle\n"
        "xorl %eax, %eax\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 532 */
__attribute__((naked))
qboolean G_EntLinkToWithOffset(gentity_t *ent, gentity_t *parent, unsigned int tagName, const vec_t *originOffset, const vec_t *anglesOffset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl 0xc(%ebp), %edx\n" /* parent */
        "movl 0x10(%ebp), %ecx\n" /* tagName */
        "movl 0x14(%ebp), %esi\n" /* originOffset */
        "movl %ebx, %eax\n"
        "calll __G_EntLinkToInternal\n"
        "testl %eax, %eax\n"
        "je .Llinkoff_done\n"
        "movl 0x208(%ebx), %ebx\n" /* tagInfo */
        "leal 0x10(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* anglesOffset */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x34(%ebx), %edx\n"
        "movl (%esi), %eax\n"
        "movl %eax, 0x34(%ebx)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl $1, %eax\n"
        ".Llinkoff_done:\n"
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 516 */
__attribute__((naked))
qboolean G_EntLinkTo(gentity_t *ent, gentity_t *parent, unsigned int tagName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl 0xc(%ebp), %edx\n" /* parent */
        "movl 0x10(%ebp), %ecx\n" /* tagName */
        "movl %ebx, %eax\n"
        "calll __G_EntLinkToInternal\n"
        "testl %eax, %eax\n"
        "je .Llink_done\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_CalcTagAxis\n"
        "movl $1, %eax\n"
        ".Llink_done:\n"
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 803 */
unsigned char G_GeneralLink(gentity_t *ent)
{
    G_SetFixedLink(ent, 0);

    /* G_SetOrigin inline */
    VectorCopy(ENT_CURRENTORIGIN(ent), ENT_POS_TRBASE(ent));
    ENT_POS_TRTIME(ent) = 0;
    ENT_POS_TRDURATION(ent) = 0;
    VectorClear(ENT_POS_TRDELTA(ent));

    /* G_SetAngle inline */
    VectorCopy(ENT_CURRENTANGLES(ent), ENT_APOS_TRBASE(ent));
    ENT_APOS_TRTIME(ent) = 0;
    ENT_APOS_TRDURATION(ent) = 0;
    VectorClear(ENT_APOS_TRDELTA(ent));

    ENT_POS_TRTYPE(ent) = 1;
    ENT_APOS_TRTYPE(ent) = 1;

    SV_LinkEntity(ent);
}

/* line 1332 */
unsigned char G_FreeEntity(gentity_t *ed)
{
    int entnum;
    int i;
    byte *ent;

    G_EntUnlink(ed);

    /* Unlink all children */
    while (ENT_TAGCHILDREN(ed)) {
        G_EntUnlink(ENT_TAGCHILDREN(ed));
    }

    SV_UnlinkEntity(ed);

    {
        void *tree = SV_DObjGetTree(ed);
        if (tree) {
            XAnimClearTree(tree);
        }
    }

    Com_SafeServerDObjFree(ENT_NUMBER(ed));

    /* Clear references from other entities */
    entnum = ENT_NUMBER(ed);

    ent = g_entities_ptr;
    for (i = 0; i < LEVEL_NUMENTS; i++, ent += ENTITY_STRIDE) {
        if (!ENT_INUSE(ent)) {
            continue;
        }
        if (ENT_PARENT(ent) == ed) {
            ENT_PARENT(ent) = 0;
        }
        if (ENT_OWNERNUM(ent) == entnum) {
            ENT_OWNERNUM(ent) = 0x3FF;
            if (ENT_ETYPE(ent) == 9) {
                *(byte *)((byte *)ent + 0x162) = 0;
            }
        }
        if (ENT_OTHERENTNUM(ent) == entnum) {
            ENT_OTHERENTNUM(ent) = 0x3FF;
        }
    }

    /* Clear references from clients */
    ent = g_entities_ptr;
    for (i = 0; i < 64; i++, ent += ENTITY_STRIDE) {
        if (!ENT_INUSE(ent)) {
            continue;
        }
        byte *client = ENT_CLIENT(ent);
        if (CLIENT_OWNERENT(client) == ed) {
            CLIENT_OWNERENT(client) = 0;
        }
        if (CLIENT_OWNERNUM(client) == entnum) {
            CLIENT_OWNERNUM(client) = 0x3FF;
        }
        if (CLIENT_WEAPENT(client) == entnum) {
            CLIENT_WEAPENT(client) = 0x3FF;
        }
    }

    /* Clear from level entity references */
    {
        byte *p = level_ptr;
        byte *end = level_ptr + 0x80;
        while (p < end) {
            if (*(gentity_t **)(p + 0x1D58) == ed) {
                *(gentity_t **)(p + 0x1D58) = 0;
            }
            p += 4;
        }
    }

    /* Free turret if present */
    if (ENT_TURRET(ed)) {
        G_FreeTurret(ed);
    }

    /* Handle player corpse type */
    if (ENT_ETYPE(ed) == 2) {
        int corpseIdx = G_GetPlayerCorpseIndex(ed);
        /* Clear corpse entry: stride = 0x4C8 * 9/8... complex offset math */
        {
            int offset = (corpseIdx * 9);
            offset = (offset * 16 + offset) * 8;
            *(int *)((byte *)playerCorpseInfo_ptr + 0x10BC + offset) = -1;
        }
    }

    Scr_FreeEntity(ed);

    {
        int useCount = ENT_USECOUNT(ed);
        memset(ed, 0, ENTITY_STRIDE);
        ENT_FREETIME(ed) = LEVEL_TIME;

        /* Check if entity is in the dynamic range */
        if ((byte *)ed - LEVEL_GENTITIES > 0x9D7F) {
            /* Add to free list */
            if (LEVEL_LASTFREEENT) {
                ENT_NEXTFREEENT(LEVEL_LASTFREEENT) = ed;
            } else {
                LEVEL_FIRSTFREEENT = ed;
            }
            LEVEL_LASTFREEENT = ed;
            ENT_NEXTFREEENT(ed) = 0;
        }

        ENT_USECOUNT(ed) = useCount + 1;
    }
}

/* line 1270 */
int G_GetFreePlayerCorpseIndex(void)
{
    int i;
    unsigned short match;
    vec3_t playerPos;
    float bestDistSq;
    int bestIdx;

    match = *(unsigned short *)(scr_const_ptr + 0x32);

    /* Find the player entity with matching classname (inline G_FindEntityByConstString) */
    {
        byte *ent = g_entities_ptr;
        byte *end = g_entities_ptr + LEVEL_NUMENTS * ENTITY_STRIDE;
        gentity_t *found = 0;

        while (ent < end) {
            if (ENT_INUSE(ent)) {
                unsigned short cn = ENT_CLASSNAME(ent);
                if (cn && cn == match) {
                    found = (gentity_t *)ent;
                    break;
                }
            }
            ent += ENTITY_STRIDE;
        }

        if (found) {
            VectorCopy(ENT_POS_TRBASE(found), playerPos);
        } else {
            VectorClear(playerPos);
        }
    }

    bestDistSq = -1.0f;
    bestIdx = 0;

    for (i = 0; i < 8; i++) {
        int entnum = CORPSE_ENTNUM(playerCorpseInfo_ptr, i);
        if (entnum == -1) {
            return i;
        }

        {
            /* Compute entity origin from entity number */
            byte *corpseEnt = LEVEL_GENTITIES + ((entnum * 5) * 8 - entnum * 5) * 16 + 0x138;
            float distSq = Vec3DistanceSq((vec_t *)corpseEnt, playerPos);
            if (distSq > bestDistSq) {
                bestDistSq = distSq;
                bestIdx = i;
            }
        }
    }

    /* Free the farthest corpse */
    {
        int offset = (bestIdx * 9);
        int off2 = (offset * 16 + offset) * 8;
        byte *entry = playerCorpseInfo_ptr + 0x10B0 + off2;
        int entnum2 = *(int *)(entry + 0x0C);
        byte *corpseEnt2 = LEVEL_GENTITIES + ((entnum2 * 5) * 8 - entnum2 * 5) * 16;
        G_FreeEntity((gentity_t *)corpseEnt2);
        *(int *)(entry + 0x0C) = -1;
    }

    return bestIdx;
}

/* line 237 */
unsigned char G_DObjUpdate(gentity_t *ent)
{
    int i;
    int numModels;
    byte *dobjModels[8 * 3]; /* XModel*, boneName, ignoreCollision - 8 models max */

    if (ENT_CLIENT(ent)) {
        return 0;
    }

    /* G_SafeDObjFree */
    Com_SafeServerDObjFree(ENT_NUMBER(ent));

    if (!ENT_MODELINDEX(ent)) {
        /* No model - check children for unlink */
        gentity_t *child = ENT_TAGCHILDREN(ent);
        while (child) {
            byte *childTag = ENT_TAGINFO(child);
            gentity_t *next = TAGINFO_NEXT(childTag);
            if (!TAGINFO_TAGNAME(childTag)) {
                TAGINFO_BONEINDEX(childTag) = -1;
            } else {
                G_EntUnlink(child);
            }
            child = next;
        }
        return 0;
    }

    dobjModels[0] = (byte *)cached_models[ENT_MODELINDEX(ent)];
    dobjModels[1] = 0;
    dobjModels[2] = 0;

    if (ENT_ETYPE(ent) == 0 || ENT_ETYPE(ent) == 6 || ENT_ETYPE(ent) == 9) {
        ENT_WEAPON(ent) = ENT_MODELINDEX(ent);
    }

    numModels = 1;
    for (i = 0; i < 7; i++) {
        byte modelIdx = ENT_ATTACHMODEL(ent, i);
        if (!modelIdx) {
            continue;
        }
        dobjModels[numModels * 3 + 0] = (byte *)cached_models[modelIdx];
        dobjModels[numModels * 3 + 1] = (byte *)SL_ConvertToString(ENT_ATTACHTAG(ent, i));
        dobjModels[numModels * 3 + 2] = (byte *)(int)((ENT_IGNORECOLLISION(ent) >> i) & 1);
        numModels++;
    }

    Com_ServerDObjCreate((void *)dobjModels, (unsigned short)numModels, 0, ENT_NUMBER(ent));

    /* Re-resolve bone indices for children */
    {
        gentity_t *child = ENT_TAGCHILDREN(ent);
        while (child) {
            byte *childTag = ENT_TAGINFO(child);
            gentity_t *next = TAGINFO_NEXT(childTag);
            if (!TAGINFO_TAGNAME(childTag)) {
                TAGINFO_BONEINDEX(childTag) = -1;
            } else {
                int boneIdx = SV_DObjGetBoneIndex(TAGINFO_PARENT(childTag), TAGINFO_TAGNAME(childTag));
                TAGINFO_BONEINDEX(childTag) = boneIdx;
                if (boneIdx < 0) {
                    G_EntUnlink(child);
                }
            }
            child = next;
        }
    }
}

/* line 437 */
unsigned char G_EntDetachAll(gentity_t *ent)
{
    int i;
    byte *base = (byte *)ent;

    for (i = 0; i < 7; i++) {
        ENT_ATTACHMODEL(ent, i) = 0;
        Scr_SetString((scr_string_t *)(base + 0x218 + i * 2), 0);
    }

    ENT_IGNORECOLLISION(ent) = 0;
    G_DObjUpdate(ent);
}

/* line 392 */
qboolean G_EntDetach(gentity_t *ent, const char *modelName, unsigned int tagName)
{
    int i;

    for (i = 0; i < 7; i++) {
        if (ENT_ATTACHTAG(ent, i) != tagName) {
            continue;
        }

        {
            const char *attachedModel = SV_GetConfigstringConst(0x14e + ENT_ATTACHMODEL(ent, i));
            if (stricmp(attachedModel, modelName) != 0) {
                continue;
            }
        }

        /* Found the match - remove it and shift down */
        ENT_ATTACHMODEL(ent, i) = 0;
        Scr_SetString((scr_string_t *)((byte *)ent + 0x218 + i * 2), 0);

        if (i <= 5) {
            int j;
            for (j = i; j < 6; j++) {
                ENT_ATTACHMODEL(ent, j) = ENT_ATTACHMODEL(ent, j + 1);
                ENT_ATTACHTAG(ent, j) = ENT_ATTACHTAG(ent, j + 1);
                if ((ENT_IGNORECOLLISION(ent) >> (j + 1)) & 1) {
                    ENT_IGNORECOLLISION(ent) |= (1 << j);
                } else {
                    ENT_IGNORECOLLISION(ent) &= ~(1 << j);
                }
            }
            i = 6;
        }

        /* Clear the last slot */
        ENT_ATTACHMODEL(ent, i) = 0;
        ENT_ATTACHTAG(ent, i) = 0;
        ENT_IGNORECOLLISION(ent) &= ~(unsigned char)(1 << i) * 2 >> 1; /* clear bit with rotate */
        /* Simplified: */
        {
            unsigned char mask = ~(unsigned char)((0xFFFFFFFE << i) | ~(0xFFFFFFFE << i));
            /* Actually from ASM: rol $cl, 0xFFFFFFFE then AND */
            int rotmask = 0xFFFFFFFE;
            __asm__ __volatile__(
                "roll %%cl, %0\n"
                : "+r"(rotmask)
                : "c"(i)
            );
            ENT_IGNORECOLLISION(ent) &= (byte)rotmask;
        }

        G_DObjUpdate(ent);
        return 1;
    }

    return 0;
}

/* line 356 */
qboolean G_EntAttach(gentity_t *ent, const char *modelName, unsigned int tagName, qboolean ignoreCollision)
{
    int i;

    for (i = 0; i < 7; i++) {
        if (ENT_ATTACHMODEL(ent, i) == 0) {
            break;
        }
    }

    if (i == 7) {
        return 0;
    }

    ENT_ATTACHMODEL(ent, i) = (byte)G_ModelIndex(modelName);
    Scr_SetString((scr_string_t *)((byte *)ent + 0x218 + i * 2), tagName);

    if (ignoreCollision) {
        ENT_IGNORECOLLISION(ent) |= (byte)(1 << i);
    }

    G_DObjUpdate(ent);
    return 1;
}

/* line 1118 */
gentity_t * G_Spawn(void)
{
    gentity_t *e;

    e = LEVEL_FIRSTFREEENT;
    if (e) {
        if (LEVEL_TIME - ENT_FREETIME(e) > 499 || LEVEL_NUMENTS > 0x3FD) {
            LEVEL_FIRSTFREEENT = ENT_NEXTFREEENT(e);
            if (!ENT_NEXTFREEENT(e)) {
                LEVEL_LASTFREEENT = 0;
            }
            ENT_NEXTFREEENT(e) = 0;
            goto init;
        }
    }

    if (LEVEL_NUMENTS == 0x3FE) {
        /* Overflow - print entities and error */
        G_PrintEntities();
        Com_Error(1, "G_Spawn: no free entities");
    }

    /* Allocate from end */
    {
        int num = LEVEL_NUMENTS;
        e = (gentity_t *)(LEVEL_GENTITIES + ((num * 5) * 8 - num * 5) * 16);
        LEVEL_NUMENTS = num + 1;
        SV_LocateGameData(LEVEL_GENTITIES, num + 1, ENTITY_STRIDE, *(byte **)(level_ptr), 0x28A4);
    }

init:
    G_InitGentity(e);
    return e;
}

/* line 1411 */
gentity_t * G_TempEntity(const vec_t *origin, int event)
{
    gentity_t *e;
    vec3_t snapped;

    e = G_Spawn();
    ENT_ETYPE(e) = event + 10;

    Scr_SetString((scr_string_t *)((byte *)e + 0x168), *(unsigned short *)(scr_const_ptr + 0x50));

    ENT_FREETIME(e) = LEVEL_TIME;
    ENT_EVENTTIME(e) = LEVEL_TIME;
    ENT_FREEAFTEREVENT(e) = 1;

    /* Snap origin to integer */
    snapped[0] = (float)(int)origin[0];
    snapped[1] = (float)(int)origin[1];
    snapped[2] = (float)(int)origin[2];

    /* G_SetOrigin inline */
    VectorCopy(snapped, ENT_POS_TRBASE(e));
    ENT_POS_TRTYPE(e) = 0;
    ENT_POS_TRTIME(e) = 0;
    ENT_POS_TRDURATION(e) = 0;
    VectorClear(ENT_POS_TRDELTA(e));
    VectorCopy(snapped, ENT_CURRENTORIGIN(e));

    SV_LinkEntity(e);

    return e;
}

/* line 1157 */
gentity_t * G_SpawnPlayerClone(void)
{
    int idx;
    byte *base;
    gentity_t *e;
    int oldEFlags;

    idx = LEVEL_CLONEIDX;
    base = LEVEL_GENTITIES + ((idx * 5) * 8 - idx * 5) * 16;
    e = (gentity_t *)(base + 0x8C00);

    idx = (idx + 1) & 0x80000007;
    if (idx < 0) {
        idx = ((idx - 1) | 0xFFFFFFF8) + 1;
    }
    LEVEL_CLONEIDX = idx;

    oldEFlags = ENT_EFLAGS(e) & 2;
    oldEFlags ^= 2;

    if (ENT_INUSE(e)) {
        G_FreeEntity(e);
    }

    G_InitGentity(e);
    ENT_EFLAGS(e) = oldEFlags;

    return e;
}

/* line 911 */
qboolean G_DObjGetWorldTagMatrix(gentity_t *ent, unsigned int tagName, vec3_t *tagMat)
{
    DObjAnimMat_s *mat;
    int boneIndex;
    vec3_t ent_axis[3];
    vec3_t origin;
    vec3_t axis[3];

    /* G_DObjGetLocalTagMatrix inline */
    boneIndex = SV_DObjGetBoneIndex(ent, tagName);
    if (boneIndex < 0) {
        return 0;
    }
    G_DObjCalcBone(ent, boneIndex);
    mat = (DObjAnimMat_s *)((byte *)SV_DObjGetMatrixArray(ent) + boneIndex * 32);
    if (!mat) {
        return 0;
    }

    AnglesToAxis(ENT_CURRENTANGLES(ent), (vec_t *)ent_axis);
    VectorCopy(ENT_CURRENTORIGIN(ent), origin);

    /* QuatToAxis inline */
    {
        float scale = mat->transWeight;
        float x = scale * mat->quat[0];
        float y = scale * mat->quat[1];
        float z = scale * mat->quat[2];
        float xx = x * mat->quat[0];
        float xy = x * mat->quat[1];
        float xz = x * mat->quat[2];
        float xw = x * mat->quat[3];
        float yy = y * mat->quat[1];
        float yz = y * mat->quat[2];
        float yw = y * mat->quat[3];
        float zz = z * mat->quat[2];
        float zw = z * mat->quat[3];

        axis[0][0] = 1.0f - (yy + zz);
        axis[0][1] = zw + xy;
        axis[0][2] = xz - yw;
        axis[1][0] = xy - zw;
        axis[1][1] = 1.0f - (xx + zz);
        axis[1][2] = xw + yz;
        axis[2][0] = xz + yw;
        axis[2][1] = yz - xw;
        axis[2][2] = 1.0f - (xx + yy);
    }

    MatrixMultiply((vec_t *)axis, (vec_t *)ent_axis, (vec_t *)tagMat);
    MatrixTransformVector43((vec_t *)&mat->trans, (vec_t *)ent_axis, ((vec_t *)tagMat + 9));

    return 1;
}

/* line 936 */
qboolean G_DObjGetWorldTagPos(gentity_t *ent, unsigned int tagName, vec_t *pos)
{
    DObjAnimMat_s *mat;
    int boneIndex;
    vec3_t ent_axis[3];
    vec3_t origin;

    /* G_DObjGetLocalTagMatrix inline */
    boneIndex = SV_DObjGetBoneIndex(ent, tagName);
    if (boneIndex < 0) {
        return 0;
    }
    G_DObjCalcBone(ent, boneIndex);
    mat = (DObjAnimMat_s *)((byte *)SV_DObjGetMatrixArray(ent) + boneIndex * 32);
    if (!mat) {
        return 0;
    }

    AnglesToAxis(ENT_CURRENTANGLES(ent), (vec_t *)ent_axis);
    VectorCopy(ENT_CURRENTORIGIN(ent), origin);

    MatrixTransformVector43((vec_t *)&mat->trans, (vec_t *)ent_axis, pos);

    return 1;
}
