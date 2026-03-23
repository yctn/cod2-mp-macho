/* ASM dump from: FxPrimitives.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxPrimitives.cpp */

#include "common_types.h"
#include "imports.h"
#include <math.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/FxMemMgr.h"
 *   #include "PC/EffectsCore/FxPrimitives.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/EffectsCore/FxCurve.h"
 *   #include "PC/EffectsCore/FxChannel.h"
 *   #include "PC/EffectsCore/FxArchive.h"
 *   #include "Mac/Tools/MacSwap.h"
 *   #include "PC/universal/q_shared.h"
 */

extern FxBoltFrame *FxBoltFrame_g_mFrameList; /* 0x0 */
extern void * Hunk_AllocInternal(int size);
extern struct XModel * XModelPrecache(const char *name, void *(*alloc1)(int), void *(*alloc2)(int));

void FxBoltFrame_Release(const FxBoltFrame * _this);
const orientation_t * FxBoltFrame_GetOrientation(const FxBoltFrame * _this);
static void * FxModelAlloc(int size);
struct XModel * FX_XModelPrecache(const char *name);
void Effect_Die(const Effect * _this);
Bool Effect_Cull(const Effect * _this);
void Effect_Draw(const Effect * _this);
void Effect_SetTimeStartEnd(const Effect * _this, int start, int end);
unsigned char Effect_TypeID(const Effect * _this);
void Effect_FixupArchiveLoad(const Effect * _this, const PrimitiveTemplate *primTemplate);
void FxChannelInstance_Create(const FxChannel *master, FxChannelInstance *createe);
void Particle_CreateChannelInstances(const Particle * _this, const PrimitiveTemplate *primTemp);
void Particle_SetRandomVelocity2Weights(const Particle * _this, float weight1, float weight2, float weight3);
unsigned char Particle_TypeID(const Particle * _this);
unsigned char OrientedParticle_TypeID(const OrientedParticle * _this);
void Cloud_Die(const Cloud * _this);
void Cloud_CreateChannelInstances(const Cloud * _this, const PrimitiveTemplate *primTemp);
unsigned char Cloud_TypeID(const Cloud * _this);
void Line_Die(const Line * _this);
unsigned char Line_TypeID(const Line * _this);
void Tail_CreateChannelInstances(const Tail * _this, const PrimitiveTemplate *primTemp);
unsigned char Tail_TypeID(const Tail * _this);
unsigned char Cylinder_TypeID(const Cylinder * _this);
Bool Emitter_Cull(const Emitter * _this);
unsigned char Emitter_TypeID(const Emitter * _this);
void Light_CreateChannelInstances(const Light * _this, const PrimitiveTemplate *primTemp);
void Light_Draw(const Light * _this);
unsigned char Light_TypeID(const Light * _this);
void Flash_Init(const Flash * _this);
unsigned char Flash_TypeID(const Flash * _this);
static void GLOBAL__I__ZN11FxBoltFrame12g_mFrameListE(void); /* global constructors keyed to FxBoltFrame_g_mFrameList */
void Particle_AddVisibility(const Particle * _this);
static void FX_AddFxToScene(void);
void Emitter_Draw(const Emitter * _this);
void Cylinder_Draw(const Cylinder * _this);
void Tail_Draw(const Tail * _this);
void Line_Draw(const Line * _this);
void Cloud_Draw(const Cloud * _this);
void OrientedParticle_Draw(const OrientedParticle * _this);
void Particle_Draw(const Particle * _this);
Bool Effect_Update(const Effect * _this);
Bool Particle_Cull(const Particle * _this);
Bool OrientedParticle_Cull(const OrientedParticle * _this);
Bool Cloud_Cull(const Cloud * _this);
Bool Line_Cull(const Line * _this);
Bool Tail_Cull(const Tail * _this);
Bool Cylinder_Cull(const Cylinder * _this);
Bool Light_Cull(const Light * _this);
void Particle_SetRandomVelocityWeights(const Particle * _this, float weight1, float weight2, float weight3);
float Particle_GetVisibility(const Particle * _this, const vec_t *start, const vec_t *dir, float halfLen);
void Particle_FixupArchiveLoad(const Particle * _this, const PrimitiveTemplate *primTemplate);
void Light_FixupArchiveLoad(const Light * _this, const PrimitiveTemplate *primTemplate);
void Particle_SetAxis(const Particle * _this, vec3_t *ax);
void Flash_Draw(const Flash * _this);
const FxBoltFramePtr FxBoltFrame_Acquire(const FxBoltInfo *bolt);
void Particle_Die(const Particle * _this);
void Tail_CalcNewEndpoint(const Tail * _this, const orientation_t *or_);
void Cloud_FixupArchiveLoad(const Cloud * _this, const PrimitiveTemplate *primTemplate);
void Tail_FixupArchiveLoad(const Tail * _this, const PrimitiveTemplate *primTemplate);
void Light_UpdateRGB(const Light * _this, const Light * _this_1);
void ZN6EffectD1Ev(void); /* Effect_~Effect */
void FxBoltFramePtr_Archive(const FxBoltFramePtr * _this, FxArchive *arch);
void ZN6EffectD0Ev(void); /* Effect_~Effect */
void Effect_SetBoltFrame(const Effect * _this, FxBoltFramePtr *boltFrame);
void Particle_UpdateRGB(const Particle * _this);
Bool Flash_Update(const Flash * _this);
void Particle_IntegrateVelocity(const Particle * _this, float normDuration, vec_t *outVector);
void Particle_IntegrateVelocity2(const Particle * _this, float normDuration, vec_t *outVector);
void Particle_IntegrateTotalVelocity(const Particle * _this, int duration, vec_t *outVector);
void Particle_Particle(const Particle * _this);
void ZN8ParticleD1Ev(void); /* Particle_~Particle */
void ZN8ParticleD0Ev(void); /* Particle_~Particle */
void Light_Light(const Light * _this);
void ZN5LightD1Ev(void); /* Light_~Light */
void ZN5LightD0Ev(void); /* Light_~Light */
void Tail_InitEndPoint(const Tail * _this);
Bool Light_Update(const Light * _this);
void Particle_CalcVelocityValue(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_);
void Particle_CalcVelocity2Value(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_);
void Particle_GetTotalVelocity(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_);
void Emitter_UpdateEmitFx(const Emitter * _this, vec_t *bindVelocity, const orientation_t *or_);
void Particle_GetTotalVelocityAtTime0(const Particle * _this, vec_t *outVector);
void Particle_ApplyImpact(const Particle * _this, const orientation_t *or_, float normTime, const vec_t *velocity, float traceFraction, const vec_t *traceNormal);
Bool Particle_UpdateOrigin(const Particle * _this, const orientation_t *or_);
Bool Emitter_Update(const Emitter * _this);
void Particle_UpdateAlpha(const Particle * _this);
Bool Cylinder_Update(const Cylinder * _this);
Bool Tail_Update(const Tail * _this);
Bool Line_Update(const Line * _this);
Bool Cloud_Update(const Cloud * _this);
Bool OrientedParticle_Update(const OrientedParticle * _this);
Bool Particle_Update(const Particle * _this, const Particle * _this_1, const Cloud * _this_2);
void Effect_Archive(const Effect * _this, FxArchive *arch);
void Light_Archive(const Light * _this, FxArchive *arch);
void Flash_Archive(const Flash * _this, FxArchive *arch);
void Particle_Archive(const Particle * _this, FxArchive *arch);
void OrientedParticle_Archive(const OrientedParticle * _this, FxArchive *arch);
void Cloud_Archive(const Cloud * _this, FxArchive *arch);
void Line_Archive(const Line * _this, FxArchive *arch);
void Tail_Archive(const Tail * _this, FxArchive *arch);
void Cylinder_Archive(const Cylinder * _this, FxArchive *arch);
void Emitter_Archive(const Emitter * _this, FxArchive *arch);
void ZN8CylinderD0Ev(void); /* Cylinder_~Cylinder */
void ZN8CylinderD1Ev(void); /* Cylinder_~Cylinder */
void Cylinder_Cylinder(const Cylinder * _this);
void OrientedParticle_OrientedParticle(const OrientedParticle * _this);
void ZN16OrientedParticleD1Ev(void); /* OrientedParticle_~OrientedParticle */
void ZN16OrientedParticleD0Ev(void); /* OrientedParticle_~OrientedParticle */
void Cloud_Cloud(const Cloud * _this, const Cloud * _this_1);
void ZN5CloudD1Ev(void); /* Cloud_~Cloud */
void ZN5CloudD0Ev(void); /* Cloud_~Cloud */
void Line_Line(const Line * _this);
void ZN4LineD1Ev(void); /* Line_~Line */
void ZN4LineD0Ev(void); /* Line_~Line */
void Tail_Tail(const Tail * _this);
void ZN4TailD1Ev(void); /* Tail_~Tail */
void ZN4TailD0Ev(void); /* Tail_~Tail */
void Emitter_Emitter(const Emitter * _this);
void ZN7EmitterD1Ev(void); /* Emitter_~Emitter */
void ZN7EmitterD0Ev(void); /* Emitter_~Emitter */
float Effect_GetVisibility(const Effect * _this, const vec_t *start, const vec_t *dir, float halfLen);
void Effect_AddVisibility(const Effect * _this);
Bool Flash_Cull(const Flash * _this);
void ZN5FlashD0Ev(void); /* Flash_~Flash */
void ZN5FlashD1Ev(void); /* Flash_~Flash */

/* Shared helper: release bolt frame reference, free if refcount reaches 0 */
extern void __ZdaPv(void *ptr);
extern void *__Znam(int size);
extern void OrientationDirFromWorldDir(void *orient, vec_t *worldDir, vec_t *localDir);
extern void OrientationPosToWorldPos(void *orient, vec_t *localPos, vec_t *worldPos);
extern void AxisTransformVector(void *curve, float x, float y, float z, vec_t *out);
extern void FxArchive_ReadData(void *arch, void *data, int size);
extern void FxArchive_WriteData(void *arch, void *data, int size);
extern void FxArchive_ArchiveChannelInstance(void *arch, void *channelInst);
extern byte *__ZN11FxBoltFrame12g_mFrameListE; /* FxBoltFrame::g_mFrameList */
extern byte __ZTV6Effect[];  /* Effect vtable */
static void FxBoltFrame_ReleaseHelper(byte *boltFrame)
{
    if (!boltFrame) return;
    int refCount = ((FxBoltFrame *)boltFrame)->refCount - 1;
    ((FxBoltFrame *)boltFrame)->refCount = refCount;
    if (refCount != 0) return;
    /* Remove from g_mFrameList linked list */
    byte **prevNext = &__ZN11FxBoltFrame12g_mFrameListE;
    byte *cur = *prevNext;
    while (cur) {
        if (cur == boltFrame) {
            *prevNext = (byte *)((FxBoltFrame *)boltFrame)->next;
            break;
        }
        prevNext = (byte **)&((FxBoltFrame *)cur)->next;
        cur = *prevNext;
    }
    if (boltFrame) __ZdaPv(boltFrame);
}

/* line 69 */
/* FxBoltFrame_Release — decrement refcount, free if zero */
void FxBoltFrame_Release(const FxBoltFrame *_this)
{
    FxBoltFrame_ReleaseHelper((byte *)_this);
}

/* line 88 */
extern int FX_GetBoneOrientation(int *boltInfo, orientation_t *orient);
const orientation_t * FxBoltFrame_GetOrientation(const FxBoltFrame * _this)
{
    byte *cl_ptr;
    int serverTime;
    orientation_t *orient = (orientation_t *)&_this->orientation;

    /* line 90: if bone index < 0, return NULL */
    if (_this->mBolt.dobjHandle < 0)
        return (const orientation_t *)0;

    /* line 94: check if server time changed */
    cl_ptr = *(byte **)imp_cl;
    serverTime = ((clientActive_t *)cl_ptr)->serverTime;
    if (serverTime != ((FxBoltFrame *)_this)->cachedServerTime) {
        /* line 96: update cached time */
        ((FxBoltFrame *)_this)->cachedServerTime = serverTime;
        /* line 102: try to get bone orientation */
        if (!FX_GetBoneOrientation((int *)&_this->mBolt.dobjHandle, orient)) {
            /* line 105-106: invalidate */
            ((FxBoltFrame *)_this)->mBolt.dobjHandle = -1;
            ((FxBoltFrame *)_this)->mBolt.boneIndex = -1;
            return (const orientation_t *)0;
        }
    }

    return orient;
}

/* line 165 */
static void * FxModelAlloc(int size)
{
    return Hunk_AllocInternal(size);
}

/* line 171 */
struct XModel * FX_XModelPrecache(const char *name)
{
    return XModelPrecache(name, FxModelAlloc, FxModelAlloc);
}

/* line 187 */
void Effect_Die(const Effect * _this)
{
}

/* line 192 */
Bool Effect_Cull(const Effect * _this)
{
    return 0;
}

/* line 198 */
void Effect_Draw(const Effect * _this)
{
}

/* line 250 */
void Effect_SetTimeStartEnd(const Effect * _this, int start, int end)
{
    ((Effect *)_this)->mTimeStart = start;
    ((Effect *)_this)->mTimeEnd = end;
}

/* line 278 */
unsigned char Effect_TypeID(const Effect * _this)
{
    return 0;
}

/* line 322 */
void Effect_FixupArchiveLoad(const Effect * _this, const PrimitiveTemplate *primTemplate)
{
}

/* line 468 */
extern void FxCurveIterator_Create(void *inst, void *curve);
extern float FxRange_GetVal(void *range);
void FxChannelInstance_Create(const FxChannel *master, FxChannelInstance *createe)
{
    byte *m = (byte *)master;
    byte *c = (byte *)createe;
    /* line 473: create curve iterator from master's curve ptr */
    FxCurveIterator_Create(c, *(void **)m /* FxChannel.curve */);
    /* line 474: get random value from master's range (at offset 4) */
    ((FxChannelInstance *)c)->scale = FxRange_GetVal((void *)(m + 4));
}

/* line 478 */
void Particle_CreateChannelInstances(const Particle * _this, const PrimitiveTemplate *primTemp)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemp;
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[0], &((Particle *)_this)->colorChannelInstance); /* line 482 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[1], &((Particle *)_this)->colorRandChannelInstance); /* line 483 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[2], &((Particle *)_this)->alphaChannelInstance); /* line 484 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[3], &((Particle *)_this)->alphaRandChannelInstance); /* line 485 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[4], &((Particle *)_this)->sizeChannelInstance); /* line 486 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[5], &((Particle *)_this)->sizeRandChannelInstance); /* line 487 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[6], &((Particle *)_this)->size2ChannelInstance); /* line 488 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[7], &((Particle *)_this)->size2RandChannelInstance); /* line 489 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[10], &((Particle *)_this)->rotationDeltaChannelInstance); /* line 490 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[11], &((Particle *)_this)->rotationDeltaRandChannelInstance); /* line 491 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[12], &((Particle *)_this)->velocityXChannelInstance); /* line 493 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[13], &((Particle *)_this)->velocityYChannelInstance); /* line 494 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[14], &((Particle *)_this)->velocityZChannelInstance); /* line 495 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[15], &((Particle *)_this)->velocityXRandChannelInstance); /* line 496 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[16], &((Particle *)_this)->velocityYRandChannelInstance); /* line 497 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[17], &((Particle *)_this)->velocityZRandChannelInstance); /* line 498 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[18], &((Particle *)_this)->velocity2XChannelInstance); /* line 500 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[19], &((Particle *)_this)->velocity2YChannelInstance); /* line 501 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[20], &((Particle *)_this)->velocity2ZChannelInstance); /* line 502 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[21], &((Particle *)_this)->velocity2XRandChannelInstance); /* line 503 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[22], &((Particle *)_this)->velocity2YRandChannelInstance); /* line 504 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[23], &((Particle *)_this)->velocity2ZRandChannelInstance); /* line 505 */
}

/* line 522 */
void Particle_SetRandomVelocity2Weights(const Particle * _this, float weight1, float weight2, float weight3)
{
    ((Particle *)_this)->velocity2WeightX = weight1;
    ((Particle *)_this)->velocity2WeightY = weight2;
    ((Particle *)_this)->velocity2WeightZ = weight3;
}

/* line 1160 */
unsigned char Particle_TypeID(const Particle * _this)
{
    return 1;
}

/* line 1323 */
unsigned char OrientedParticle_TypeID(const OrientedParticle * _this)
{
    return 7;
}

/* line 1352 */
void Cloud_Die(const Cloud * _this)
{
}

/* line 1395 */
void Cloud_CreateChannelInstances(const Cloud * _this, const PrimitiveTemplate *primTemp)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemp;
    Particle_CreateChannelInstances((const Particle *)_this, primTemp); /* line 1399 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[8], &((Cloud *)_this)->lengthChannelInstance); /* line 1401 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[9], &((Cloud *)_this)->lengthRandChannelInstance); /* line 1402 */
}

/* line 1466 */
unsigned char Cloud_TypeID(const Cloud * _this)
{
    return 12;
}

/* line 1509 */
void Line_Die(const Line * _this)
{
}

/* line 1561 */
unsigned char Line_TypeID(const Line * _this)
{
    return 2;
}

/* line 1602 */
void Tail_CreateChannelInstances(const Tail * _this, const PrimitiveTemplate *primTemp)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemp;
    Particle_CreateChannelInstances((const Particle *)_this, primTemp); /* line 1606 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[8], &((Tail *)_this)->lengthChannelInstance); /* line 1608 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[9], &((Tail *)_this)->lengthRandChannelInstance); /* line 1609 */
}

/* line 1693 */
unsigned char Tail_TypeID(const Tail * _this)
{
    return 3;
}

/* line 1788 */
unsigned char Cylinder_TypeID(const Cylinder * _this)
{
    return 4;
}

/* line 1814 */
Bool Emitter_Cull(const Emitter * _this)
{
    return 0;
}

/* line 2098 */
unsigned char Emitter_TypeID(const Emitter * _this)
{
    return 5;
}

/* line 2141 */
void Light_CreateChannelInstances(const Light * _this, const PrimitiveTemplate *primTemp)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemp;
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[0], &((Light *)_this)->colorChannelInstance); /* line 2145 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[1], &((Light *)_this)->colorRandChannelInstance); /* line 2146 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[4], &((Light *)_this)->sizeChannelInstance); /* line 2147 */
    FxChannelInstance_Create(&((PrimitiveTemplate *)primTemp)->mFxChannels[5], &((Light *)_this)->sizeRandChannelInstance); /* line 2148 */
}

/* line 2158 */
extern void FxHelper_AddLightToScene(void *helper, float *origin, float radius, float r, float g, float b);
void Light_Draw(const Light * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    /* line 2160: args are helper, origin(0x7c), radius(0x88), rgb(0x6c,0x70,0x74) */
    FxHelper_AddLightToScene(helper,
        (float *)((Effect *)p)->worldOrigin,
        ((Effect *)p)->worldRadius[0],
        ((Effect *)p)->worldColor[0],
        ((Effect *)p)->worldColor[1],
        ((Effect *)p)->worldColor[2]);
}

/* line 2214 */
unsigned char Light_TypeID(const Light * _this)
{
    return 9;
}

/* line 2264 */
/* line 2264 */
extern float Vec3Normalize(float *v);
void Flash_Init(const Flash * _this)
{
    byte *p = (byte *)_this;
    Effect *effect = (Effect *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    float dif[3];
    float dist, dot, falloff;
    float *camOrigin, *camDir;

    /* line 2266: dif = this->origin - camera origin */
    camOrigin = ((FxHelper *)helper)->mCamera.vieworg;
    dif[0] = effect->mRefEnt.origin[0];
    dif[1] = effect->mRefEnt.origin[1];
    dif[2] = effect->mRefEnt.origin[2];
    dif[0] -= camOrigin[0];
    dif[1] -= camOrigin[1];
    dif[2] -= camOrigin[2];

    /* line 2270: normalize dif, get distance */
    dist = Vec3Normalize(dif);

    /* dot product with camera direction */
    camDir = ((FxHelper *)helper)->mCamera.frustum[0]; /* camera forward direction */
    dot = dif[0] * camDir[0] + dif[1] * camDir[1] + dif[2] * camDir[2];

    /* line 2274-2277: visibility based on distance and angle */
    if (dist > 600.0f) {
        dot = 0.0f;
    } else if (dot < 0.5f) {
        if (dist > 100.0f)
            dot = 0.0f;
        else if (dist <= 100.0f)
            dot += 1.100000023841858f;
    }

    /* line 2281: distance falloff */
    falloff = dist * dist / (-360000.0f) + 1.0f;
    dot *= falloff;

    /* Apply to flash intensity (colorChannelInstance.scale) */
    ((Light *)p)->colorChannelInstance.scale *= dot;
}

/* line 2305 */
unsigned char Flash_TypeID(const Flash * _this)
{
    return 11;
}

/* line 2322 */
static void GLOBAL__I__ZN11FxBoltFrame12g_mFrameListE(void) /* global constructors keyed to FxBoltFrame_g_mFrameList */
{
}

/* line 563 */
void Particle_AddVisibility(const Particle * _this)
{
    const Effect *effect = (const Effect *)_this;
    int *countPtr = *(int **)imp_g_effectVisArrayCount;
    byte *visArray = *(byte **)imp_g_effectVisArray;
    int idx = *countPtr;
    byte *entry = visArray + idx * 20; /* 5 floats = 20 bytes per entry */
    float radius, alpha;

    /* line 571: increment count */
    *countPtr = idx + 1;

    /* line 573: copy origin vec3 */
    *(float *)(entry + 0) = effect->worldOrigin[0];
    *(float *)(entry + 4) = effect->worldOrigin[1];
    *(float *)(entry + 8) = effect->worldOrigin[2];

    /* line 574: radius squared */
    radius = effect->worldRadius[0];
    *(float *)(entry + 12) = radius * radius;

    /* line 575: visibility from alpha byte */
    alpha = (float)effect->worldRGBA[3];
    *(float *)(entry + 16) = alpha * (-0.003921568859368563f) + 1.0f;
}

/* line 329 */
/* FX_AddFxToScene — build refEntity and submit to scene. Register: eax=effect, edx=reType */
extern void AxisCopy(const vec_t *src, vec_t *dst);
extern void FxHelper_AddFxToScene(void *helper, void *ent, int sortGroup);
static void FX_AddFxToScene_impl(byte *effect, int reType)
{
    byte ent[0x74];
    memset(ent, 0, 0x74);
    Effect *eff = (Effect *)effect;
    GfxEntity *gfxEnt = (GfxEntity *)ent;
    gfxEnt->reType = reType;
    gfxEnt->customMaterial = eff->mRefEnt.customMaterial;
    gfxEnt->rotation = eff->mRefEnt.rotation;
    AxisCopy((vec_t *)eff->mRefEnt.axis, (vec_t *)gfxEnt->axis);
    /* Copy origin */
    gfxEnt->origin[0] = eff->mRefEnt.origin[0];
    gfxEnt->origin[1] = eff->mRefEnt.origin[1];
    gfxEnt->origin[2] = eff->mRefEnt.origin[2];
    /* Copy radius */
    gfxEnt->radius[0] = eff->mRefEnt.radius[0];
    gfxEnt->radius[1] = eff->mRefEnt.radius[1];
    /* Copy material RGBA */
    gfxEnt->materialRGBA[0] = eff->mRefEnt.materialRGBA[0];
    gfxEnt->materialRGBA[1] = eff->mRefEnt.materialRGBA[1];
    gfxEnt->materialRGBA[2] = eff->mRefEnt.materialRGBA[2];
    gfxEnt->materialRGBA[3] = eff->mRefEnt.materialRGBA[3];
    gfxEnt->materialSubimageIndex = eff->mRefEnt.materialSubimageIndex;
    gfxEnt->scale = ((Effect *)effect)->worldScale;
    /* Copy endpos */
    gfxEnt->endpos[0] = eff->mRefEnt.endpos[0];
    gfxEnt->endpos[1] = eff->mRefEnt.endpos[1];
    gfxEnt->endpos[2] = eff->mRefEnt.endpos[2];
    /* Copy materialTime */
    gfxEnt->materialTime = eff->mRefEnt.materialTime;
    /* Flags */
    int flags = eff->mFlags;
    if (flags & 1) gfxEnt->renderFxFlags |= 8;
    if (flags & 0x4000000) gfxEnt->renderFxFlags |= 0x80;
    FxHelper_AddFxToScene(*(void **)imp_theFxHelper, ent, (int)(size_t)eff->mModel);
}
/* Register-convention trampoline: never called directly in Emscripten mode.
   Callers already have #else branches that call FX_AddFxToScene_impl directly. */
static void FX_AddFxToScene(void) { }

/* line 1820 */
void Emitter_Draw(const Emitter * _this)
{
    const Effect *effect = (const Effect *)_this;
    byte *p = (byte *)_this;
    /* line 1823: if not (flags & 0x10), return */
    if (!(effect->mFlags & 0x10))
        return;
    /* line 1827: if alpha == 0, return */
    if (effect->worldScale == 0.0f)
        return;
    /* FX_AddFxToScene(this, 1) via register convention */
    FX_AddFxToScene_impl(p, 1);
}

/* line 1743 */
void Cylinder_Draw(const Cylinder * _this)
{
    /* FX_AddFxToScene uses register convention: eax=this, edx=reType */
    FX_AddFxToScene_impl((byte *)_this, 9);
}

/* line 1613 */
void Tail_Draw(const Tail * _this)
{
    FX_AddFxToScene_impl((byte *)_this, 8);
}

/* line 1520 */
void Line_Draw(const Line * _this)
{
    FX_AddFxToScene_impl((byte *)_this, 8);
}

/* line 1389 */
void Cloud_Draw(const Cloud * _this)
{
    FX_AddFxToScene_impl((byte *)_this, 6);
}

/* line 1276 */
void OrientedParticle_Draw(const OrientedParticle * _this)
{
    FX_AddFxToScene_impl((byte *)_this, 7);
}

/* line 401 */
void Particle_Draw(const Particle * _this)
{
    const Effect *effect = (const Effect *)_this;
    byte *p = (byte *)_this;
    float radius = effect->worldRadius[0];
    float height = effect->worldRadius[1];
    /* line 403: if both radius and height are zero, skip */
    if (radius == 0.0f && height == 0.0f)
        return;
    FX_AddFxToScene_impl(p, 4);
}

/* line 227 */
Bool Effect_Update(const Effect * _this)
{
    Effect *effect = (Effect *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int startTime = effect->mTimeStart;
    int curTime = ((FxHelper *)helper)->mTime;
    int endTime;
    float normDuration;

    /* line 232: if start time > current time, not started yet */
    if (startTime > curTime)
        return 0;

    /* line 239: compute normalized duration */
    endTime = effect->mTimeEnd;
    normDuration = (float)(curTime - startTime) / (float)(endTime - startTime);
    effect->mRefEnt.materialTime /* normTime */ = normDuration;

    /* line 241: clamp to 1.0 */
    if (normDuration > 1.0f)
        effect->mRefEnt.materialTime /* normTime */ = 1.0f;

    /* line 243: clamp to 0.0 */
    if (0.0f > effect->mRefEnt.materialTime /* normTime */)
        effect->mRefEnt.materialTime /* normTime */ = 0.0f;

    return 1;
}

/* line 395 */
extern unsigned char FxHelper_CullSphere(void *helper, float *origin, float radius, int cullType);
Bool Particle_Cull(const Particle * _this)
{
    const Effect *effect = (const Effect *)_this;
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = ((FxHelper *)helper)->mCamera.numPlanes;
    /* line 220: if flags & 2, cap cull type at 5 */
    if (((byte *)&((Effect *)p)->mFlags)[3] & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    return (Bool)FxHelper_CullSphere(helper, (float *)effect->worldOrigin, effect->worldRadius[0], cullType);
}

/* line 1270 */
Bool OrientedParticle_Cull(const OrientedParticle * _this)
{
    const Effect *effect = (const Effect *)_this;
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = ((FxHelper *)helper)->mCamera.numPlanes;
    if (((byte *)&((Effect *)p)->mFlags)[3] & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    return (Bool)FxHelper_CullSphere(helper, (float *)effect->worldOrigin, effect->worldRadius[0], cullType);
}

/* line 1357 */
Bool Cloud_Cull(const Cloud * _this)
{
    const Effect *effect = (const Effect *)_this;
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = ((FxHelper *)helper)->mCamera.numPlanes;
    float halfLen, height, radius, cullRadius;

    if (((byte *)&((Effect *)p)->mFlags)[3] & 2) {
        if (cullType >= 5)
            cullType = 5;
    }

    /* line 1359: compute cull radius = max(radius, height) + halfLen */
    halfLen = effect->worldScale;
    height = effect->worldRadius[1];
    radius = effect->worldRadius[0];
    cullRadius = (radius - height < 0.0f ? height : radius) + halfLen;

    return (Bool)FxHelper_CullSphere(helper, (float *)effect->worldOrigin, cullRadius, cullType);
}

/* line 1514 */
extern unsigned char FxHelper_CullCylinder(void *helper, float *origin1, float *origin2, float radius1, float radius2, int cullType);
Bool Line_Cull(const Line * _this)
{
    const Effect *effect = (const Effect *)_this;
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = ((FxHelper *)helper)->mCamera.numPlanes;
    float radius;
    if (((byte *)&((Effect *)p)->mFlags)[3] & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    radius = effect->worldRadius[0];
    return (Bool)FxHelper_CullCylinder(helper, (float *)effect->worldOrigin, (float *)effect->worldEndpos, radius, radius, cullType);
}

/* line 1596 */
Bool Tail_Cull(const Tail * _this)
{
    const Effect *effect = (const Effect *)_this;
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = ((FxHelper *)helper)->mCamera.numPlanes;
    float radius;
    if (((byte *)&((Effect *)p)->mFlags)[3] & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    radius = effect->worldRadius[0];
    return (Bool)FxHelper_CullCylinder(helper, (float *)effect->worldOrigin, (float *)effect->worldEndpos, radius, radius, cullType);
}

/* line 1737 */
Bool Cylinder_Cull(const Cylinder * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = ((FxHelper *)helper)->mCamera.numPlanes;
    if (((byte *)&((Effect *)p)->mFlags)[3] & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    return (Bool)FxHelper_CullCylinder(helper, (float *)((Effect *)p)->worldOrigin, (float *)((Effect *)p)->worldEndpos,
        ((Effect *)p)->worldRadius[0], ((Effect *)p)->worldRadius[1], cullType);
}

/* line 2152 */
Bool Light_Cull(const Light * _this)
{
    const Effect *effect = (const Effect *)_this;
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = ((FxHelper *)helper)->mCamera.numPlanes;
    if (((byte *)&((Effect *)p)->mFlags)[3] & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    return (Bool)FxHelper_CullSphere(helper, (float *)effect->worldOrigin, effect->worldRadius[0], cullType);
}

/* line 509 */
void Particle_SetRandomVelocityWeights(const Particle * _this, float weight1, float weight2, float weight3)
{
    ((Particle *)_this)->velocityWeightX = weight1;
    ((Particle *)_this)->velocityWeightY = weight2;
    ((Particle *)_this)->velocityWeightZ = weight3;
}

/* line 535 */
extern float Vec3DistanceSq(float *a, float *b);
float Particle_GetVisibility(const Particle * _this, const vec_t *start, const vec_t *dir, float halfLen)
{
    const Effect *effect = (const Effect *)_this;
    float *origin = (float *)effect->worldOrigin;
    float *s = (float *)start;
    float *d = (float *)dir;
    float dot, absDist, projPt[3], distSq, radiusSq;

    /* line 544: dot = (origin - start) . dir */
    dot = (origin[0] - s[0]) * d[0] + (origin[1] - s[1]) * d[1] + (origin[2] - s[2]) * d[2];

    /* line 547: check if abs(dot - halfLen) > halfLen => outside segment */
    absDist = dot - halfLen;
    if (absDist < 0.0f) absDist = -absDist;
    if (absDist > halfLen)
        return 1.0f;

    /* line 288-290: project point along ray */
    projPt[0] = s[0] + d[0] * dot;
    projPt[1] = s[1] + d[1] * dot;
    projPt[2] = s[2] + d[2] * dot;

    /* line 552: compute distance squared from origin to projected point */
    distSq = Vec3DistanceSq(origin, projPt);

    /* line 554: if distance > radius, return 1.0 (fully visible) */
    radiusSq = effect->worldRadius[0];
    radiusSq *= radiusSq;
    if (radiusSq <= distSq)
        return 1.0f;

    /* line 555: return alpha-based visibility */
    return (float)effect->worldRGBA[3] * (-0.003921568859368563f) + 1.0f;
}

/* line 1225 */
void Particle_FixupArchiveLoad(const Particle * _this, const PrimitiveTemplate *primTemplate)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemplate;
    ((Particle *)t)->colorChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[0].curve; /* line 1231 */
    ((Particle *)t)->colorRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[1].curve; /* line 1232 */
    ((Particle *)t)->alphaChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[2].curve; /* line 1233 */
    ((Particle *)t)->alphaRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[3].curve; /* line 1234 */
    ((Particle *)t)->sizeChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[4].curve; /* line 1235 */
    ((Particle *)t)->sizeRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[5].curve; /* line 1236 */
    ((Particle *)t)->size2ChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[6].curve; /* line 1237 */
    ((Particle *)t)->size2RandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[7].curve; /* line 1238 */
    ((Particle *)t)->rotationDeltaChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[10].curve; /* line 1239 */
    ((Particle *)t)->rotationDeltaRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[11].curve; /* line 1240 */
    ((Particle *)t)->velocityXChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[12].curve; /* line 1242 */
    ((Particle *)t)->velocityYChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[13].curve; /* line 1243 */
    ((Particle *)t)->velocityZChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[14].curve; /* line 1244 */
    ((Particle *)t)->velocityXRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[15].curve; /* line 1245 */
    ((Particle *)t)->velocityYRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[16].curve; /* line 1246 */
    ((Particle *)t)->velocityZRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[17].curve; /* line 1247 */
    ((Particle *)t)->velocity2XChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[18].curve; /* line 1249 */
    ((Particle *)t)->velocity2YChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[19].curve; /* line 1250 */
    ((Particle *)t)->velocity2ZChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[20].curve; /* line 1251 */
    ((Particle *)t)->velocity2XRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[21].curve; /* line 1252 */
    ((Particle *)t)->velocity2YRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[22].curve; /* line 1253 */
    ((Particle *)t)->velocity2ZRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[23].curve; /* line 1254 */
}

/* line 2236 */
void Light_FixupArchiveLoad(const Light * _this, const PrimitiveTemplate *primTemplate)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemplate;
    ((Light *)t)->colorChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[0].curve; /* line 2242 */
    ((Light *)t)->colorRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[1].curve; /* line 2243 */
    ((Light *)t)->sizeChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[4].curve; /* line 2244 */
    ((Light *)t)->sizeRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[5].curve; /* line 2245 */
}

/* line 456 */
void Particle_SetAxis(const Particle * _this, vec3_t *ax)
{
    byte *p = (byte *)_this;
    float *src = (float *)ax;

    /* line 462: displayAxis[0] */
    if (ax) {
        ((Particle *)p)->displayAxis[0][0] = src[0];
        ((Particle *)p)->displayAxis[0][1] = src[1];
        ((Particle *)p)->displayAxis[0][2] = src[2];
    } else {
        ((Particle *)p)->displayAxis[0][0] = 0.0f;
        ((Particle *)p)->displayAxis[0][1] = 0.0f;
        ((Particle *)p)->displayAxis[0][2] = 0.0f;
    }

    /* line 463: displayAxis[1] */
    if (ax) {
        ((Particle *)p)->displayAxis[1][0] = src[3];
        ((Particle *)p)->displayAxis[1][1] = src[4];
        ((Particle *)p)->displayAxis[1][2] = src[5];
    } else {
        ((Particle *)p)->displayAxis[1][0] = 0.0f;
        ((Particle *)p)->displayAxis[1][1] = 0.0f;
        ((Particle *)p)->displayAxis[1][2] = 0.0f;
    }

    /* line 464: displayAxis[2] */
    if (ax) {
        ((Particle *)p)->displayAxis[2][0] = src[6];
        ((Particle *)p)->displayAxis[2][1] = src[7];
        ((Particle *)p)->displayAxis[2][2] = src[8];
    } else {
        ((Particle *)p)->displayAxis[2][0] = 0.0f;
        ((Particle *)p)->displayAxis[2][1] = 0.0f;
        ((Particle *)p)->displayAxis[2][2] = 0.0f;
    }
}

/* Flash_Draw — evaluate color, set position to camera+forward*8, submit as light entity */
extern float floorf(float x);
static int FloatToByte(float f)
{
    int v = (int)floorf(f * 255.0f + 0.5f);
    if (v < 0) v = 0;
    if (v > 255) v = 255;
    return v;
}
void Flash_Draw(const Flash *_this)
{
    byte *self = (byte *)_this;

    /* Evaluate 3 worldColor components, clamp [0,1] */
    float color[4];
    int i;
    for (i = 0; i < 3; i++) {
        float v = ((float *)((Effect *)self)->worldColor)[i];
        if (v < 0.0f) v = 0.0f;
        if (v > 1.0f) v = 1.0f;
        color[i] = v;
    }
    color[3] = 1.0f; /* alpha */

    /* Convert to RGBA bytes */
    ((Effect *)self)->worldRGBA[0] = (byte)FloatToByte(color[0]);
    ((Effect *)self)->worldRGBA[1] = (byte)FloatToByte(color[1]);
    ((Effect *)self)->worldRGBA[2] = (byte)FloatToByte(color[2]);
    ((Effect *)self)->worldRGBA[3] = (byte)FloatToByte(color[3]);

    /* Set origin to camera position + forward * 8 */
    byte *helper = *(byte **)imp_theFxHelper;
    ((Effect *)self)->worldOrigin[0] = ((FxHelper *)helper)->mCamera.vieworg[0] + ((FxHelper *)helper)->mCamera.frustum[0][0] * 8.0f;
    ((Effect *)self)->worldOrigin[1] = ((FxHelper *)helper)->mCamera.vieworg[1] + ((FxHelper *)helper)->mCamera.frustum[0][1] * 8.0f;
    ((Effect *)self)->worldOrigin[2] = ((FxHelper *)helper)->mCamera.vieworg[2] + ((FxHelper *)helper)->mCamera.frustum[0][2] * 8.0f;

    /* Set radius */
    ((Effect *)self)->worldRadius[0] = 12.0f;
    ((Effect *)self)->worldRadius[1] = 12.0f;

    /* Submit as light entity (reType=4) via register convention */
    FX_AddFxToScene_impl(self, 4);
}

/* FxBoltFrame_Acquire — find or create bolt frame for bolt info. Returns struct by value via hidden ptr.
 * Hidden return ptr at 8(%ebp), bolt at 0xc(%ebp). Uses retl $4 (struct return convention). */
static void FxBoltFrame_Acquire_impl(byte *retPtr, byte *bolt)
{
    /* Search existing bolt frames for matching entity+bone */
    FxBoltFrame *frame = (FxBoltFrame *)__ZN11FxBoltFrame12g_mFrameListE;
    int entity = ((FxBoltInfo *)bolt)->dobjHandle;
    int bone = ((FxBoltInfo *)bolt)->boneIndex;
    while (frame) {
        if (frame->mBolt.dobjHandle == entity && frame->mBolt.boneIndex == bone) {
            frame->refCount += 1; /* addref */
            *(FxBoltFrame **)retPtr = frame;
            return;
        }
        frame = frame->next;
    }
    /* Not found — allocate new bolt frame */
    FxBoltFrame *newFrame = (FxBoltFrame *)__Znam(0x44);
    if (newFrame) memset(newFrame, 0, 0x44);
    newFrame->refCount = 0;
    newFrame->cachedServerTime = 0;
    newFrame->mBolt.dobjHandle = entity;
    newFrame->mBolt.boneIndex = bone;
    newFrame->next = (FxBoltFrame *)__ZN11FxBoltFrame12g_mFrameListE;
    __ZN11FxBoltFrame12g_mFrameListE = (byte *)newFrame;
    newFrame->refCount += 1; /* addref */
    *(FxBoltFrame **)retPtr = newFrame;
}
const FxBoltFramePtr FxBoltFrame_Acquire(const FxBoltInfo *bolt)
{
    FxBoltFramePtr p = {0};
    (void)bolt;
    return p;
}

/* line 371 */
extern float flrand(float min, float max);
extern void FxScheduler_PlayEffect(void *scheduler, void *fx, float *origin, float *dir);
void Particle_Die(const Particle * _this)
{
    const Effect *effect = (const Effect *)_this;
    byte *p = (byte *)_this;
    int flags;
    float x, y, z, lenSq, len, scale;
    float norm[3];
    void *scheduler;

    /* line 376: check death effect flags */
    flags = effect->mFlags;
    if (!(flags & 0x200))  /* testb $2, %ah  => bit 9 of flags */
        return;
    if (flags & 0x400)     /* testb $4, %ah  => bit 10 */
        return;

    /* line 379: check if death effect template exists */
    if (*(void **)&((Effect *)p)->mRefEnt.dlightColor[1] /* deathFxHandle */ == 0)
        return;

    /* line 381: generate random direction */
    z = flrand(-1.0f, 1.0f);
    y = flrand(-1.0f, 1.0f);
    x = flrand(-1.0f, 1.0f);

    /* Set up normal vector */
    norm[0] = x;
    norm[1] = y;
    norm[2] = z;

    /* line 384: normalize - check length */
    lenSq = x * x + y * y + z * z;
    len = __builtin_sqrtf(lenSq);
    if ((double)len >= 1e-06) {
        /* line 387: scale to unit length */
        scale = 1.0f / len;
        norm[0] *= scale;
        norm[1] *= scale;
        norm[2] *= scale;
    } else {
        norm[0] = 0.0f;
        norm[1] = 0.0f;
        norm[2] = 1.0f;
    }

    /* line 389: play death effect */
    scheduler = *(void **)imp_theFxScheduler;
    FxScheduler_PlayEffect(scheduler, *(void **)&((Effect *)p)->mRefEnt.dlightColor[1] /* deathFxHandle */, (float *)&((Effect *)p)->mRefEnt.customMaterial /* localOrigin[0] */, norm);
}

/* Tail_CalcNewEndpoint — compute new endpoint from origin + normalized direction * length */
void Tail_CalcNewEndpoint(const Tail *_this, const orientation_t *or_)
{
    byte *self = (byte *)_this;
    /* direction = endpoint - origin */
    float dx = ((Tail *)self)->endpoint[0] - *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */;
    float dy = ((Tail *)self)->endpoint[1] - ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */;
    float dz = ((Tail *)self)->endpoint[2] - ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */;

    /* Normalize direction */
    float lenSq = dx * dx + dy * dy + dz * dz;
    float len;
    len = sqrtf(lenSq);
    if (len <= 0.0f) return;

    float invLen = 1.0f / len;
    dx *= invLen;
    dy *= invLen;
    dz *= invLen;

    /* Scale by tailLength and offset from origin */
    float scale = ((Tail *)self)->tailLength;
    float newX = dx * scale + *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */;
    float newY = dy * scale + ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */;
    float newZ = dz * scale + ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */;

    if (or_) {
        /* Transform local endpoint to world space via orientation */
        vec3_t localPt;
        localPt[0] = newX; localPt[1] = newY; localPt[2] = newZ;
        OrientationPosToWorldPos((void *)or_, localPt, (vec_t *)((Effect *)self)->worldEndpos);
    } else {
        ((Effect *)self)->worldEndpos[0] = newX;
        ((Effect *)self)->worldEndpos[1] = newY;
        ((Effect *)self)->worldEndpos[2] = newZ;
    }
}

/* line 1486 */
void Cloud_FixupArchiveLoad(const Cloud * _this, const PrimitiveTemplate *primTemplate)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemplate;
    /* Particle base fixup (lines 1231-1254) */
    Particle_FixupArchiveLoad((const Particle *)_this, primTemplate);
    /* Cloud-specific channels */
    ((Cloud *)t)->lengthChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[8].curve; /* line 1492 */
    ((Cloud *)t)->lengthRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[9].curve; /* line 1493 */
}

/* line 1714 */
void Tail_FixupArchiveLoad(const Tail * _this, const PrimitiveTemplate *primTemplate)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemplate;
    /* Particle base fixup (lines 1231-1254) */
    Particle_FixupArchiveLoad((const Particle *)_this, primTemplate);
    /* Tail-specific channels */
    ((Tail *)t)->lengthChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[8].curve; /* line 1720 */
    ((Tail *)t)->lengthRandChannelInstance.curveIterator.master = ((PrimitiveTemplate *)primTemplate)->mFxChannels[9].curve; /* line 1721 */
}

/* Shared: evaluate a 1-component FxCurve at normTime. Advances key index in channelInst. */
static float EvalCurve1(byte *channelInst, float normTime)
{
    byte *curve = *(byte **)channelInst;
    int numKeys = *(int *)curve;
    int componentCount = numKeys + 1;
    int keyIdx = *(int *)(channelInst + 4);

    /* Key data starts at curve+8, each key has (componentCount) floats: time + values */
    byte *keys = curve + 8;
    int keyStride = componentCount * 4;

    /* Advance key index if needed */
    while (*(float *)(keys + (keyIdx + 1) * keyStride) < normTime && keyIdx < *(int *)curve)
        keyIdx++;
    *(int *)(channelInst + 4) = keyIdx;

    /* Interpolate between key[keyIdx] and key[keyIdx+1] */
    byte *k0 = keys + keyIdx * keyStride;
    byte *k1 = k0 + keyStride;
    float t0 = *(float *)k0;
    float t1 = *(float *)k1;
    float frac = (t1 != t0) ? (normTime - t0) / (t1 - t0) : 0.0f;
    float v0 = *(float *)(k0 + 4);
    float v1 = *(float *)(k1 + 4);
    return v0 + (v1 - v0) * frac;
}

/* Shared: evaluate 3-component FxCurve at normTime */
static void EvalCurve3(byte *channelInst, float normTime, float *out)
{
    byte *curve = *(byte **)channelInst;
    int componentCount = *(int *)curve + 1;
    int keyIdx = *(int *)(channelInst + 4);
    byte *keys = curve + 8;
    int keyStride = componentCount * 4;

    while (*(float *)(keys + (keyIdx + 1) * keyStride) < normTime)
        keyIdx++;
    *(int *)(channelInst + 4) = keyIdx;

    byte *k0 = keys + keyIdx * keyStride;
    byte *k1 = k0 + keyStride;
    float t0 = *(float *)k0;
    float t1 = *(float *)k1;
    float frac = (t1 != t0) ? (normTime - t0) / (t1 - t0) : 0.0f;

    out[0] = *(float *)(k0 + 4) + (*(float *)(k1 + 4) - *(float *)(k0 + 4)) * frac;
    out[1] = *(float *)(k0 + 8) + (*(float *)(k1 + 8) - *(float *)(k0 + 8)) * frac;
    out[2] = *(float *)(k0 + 12) + (*(float *)(k1 + 12) - *(float *)(k0 + 12)) * frac;
}

/* Light_UpdateRGB — evaluate RGB curve(s) at normTime, apply blend and scale */
void Light_UpdateRGB(const Light *_this, const Light *_this_1)
{
    (void)_this_1;
    byte *self = (byte *)_this;
    float normTime = ((Effect *)self)->mRefEnt.materialTime /* normTime */;
    float *rgb = (float *)((Effect *)self)->worldColor;

    if (((byte *)&((Effect *)self)->mFlags)[1] & 0x20) {
        /* Blend path: interpolate between two curve sources */
        float blendFactor = ((Light *)self)->colorBlendFactor;
        float val0[3], val1[3];
        EvalCurve3((byte *)&((Light *)self)->colorChannelInstance, normTime, val0);
        EvalCurve3((byte *)&((Light *)self)->colorRandChannelInstance, normTime, val1);
        float scale = ((Light *)self)->colorChannelInstance.scale;
        rgb[0] = (val0[0] + (val1[0] - val0[0]) * blendFactor) * scale;
        rgb[1] = (val0[1] + (val1[1] - val0[1]) * blendFactor) * scale;
        rgb[2] = (val0[2] + (val1[2] - val0[2]) * blendFactor) * scale;
    } else {
        /* Simple path: single curve source */
        float val[3];
        EvalCurve3((byte *)&((Light *)self)->colorChannelInstance, normTime, val);
        float scale = ((Light *)self)->colorChannelInstance.scale;
        rgb[0] = val[0] * scale;
        rgb[1] = val[1] * scale;
        rgb[2] = val[2] * scale;
    }
}

/* line 182 */
/* Effect D1 destructor — cleanup bolt frame */
void ZN6EffectD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    /* mBolt is at 0xc0 in subclass instances (Particle/Light layout) */
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN6EffectD1Ev(void) /* Effect_~Effect */
{
    /* naked trampoline — not callable under WASM */
}

/* FxBoltFramePtr_Archive — serialize bolt frame ptr: entity+bone IDs, acquire on read, release temp */
void FxBoltFramePtr_Archive(const FxBoltFramePtr *_this, FxArchive *arch)
{
    /* _this is a FxBoltFramePtr which holds a single FxBoltFrame * pointer */
    FxBoltFrame **bfPtr = (FxBoltFrame **)_this;
    byte *a = (byte *)arch;

    if (((FxArchive *)a)->isReading) {
        /* Reading */
        int entity, bone;
        FxArchive_ReadData(arch, &entity, 4);
        if (entity < 0) {
            /* No bolt — release current and set NULL */
            FxBoltFrame_ReleaseHelper((byte *)*bfPtr);
            *bfPtr = NULL;
            return;
        }
        FxArchive_ReadData(arch, &bone, 4);
        /* Acquire bolt frame for entity+bone */
        FxBoltInfo boltInfo;
        boltInfo.dobjHandle = entity;
        boltInfo.boneIndex = bone;
        FxBoltFrame *acquired = NULL;
        /* Call FxBoltFrame_Acquire which returns struct by value */
        FxBoltFrame_Acquire_impl((byte *)&acquired, (byte *)&boltInfo);
        /* Assign to this with refcount (use Effect_SetBoltFrame pattern) */
        FxBoltFrame *oldBf = *bfPtr;
        FxBoltFrame *newBf = acquired;
        if (oldBf != newBf) {
            if (oldBf) FxBoltFrame_ReleaseHelper((byte *)oldBf);
            *bfPtr = NULL;
            if (newBf) { newBf->refCount += 1; *bfPtr = newBf; }
        }
        /* Release the temp acquired frame */
        if (newBf) FxBoltFrame_ReleaseHelper((byte *)newBf);
    } else {
        /* Writing */
        FxBoltFrame *bf = *bfPtr;
        if (!bf) {
            int neg = -1;
            FxArchive_WriteData(arch, &neg, 4);
        } else {
            int entity = bf->mBolt.dobjHandle;
            int bone = bf->mBolt.boneIndex;
            FxArchive_WriteData(arch, &entity, 4);
            FxArchive_WriteData(arch, &bone, 4);
        }
    }
}

/* line 182 */
/* Effect D0 destructor — cleanup bolt frame + delete this */
void ZN6EffectD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    /* mBolt is at 0xc0 in subclass instances (Particle/Light layout) */
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN6EffectD0Ev(void) /* Effect_~Effect */
{
    /* naked trampoline — not callable under WASM */
}

/* line 269 */
/* Effect_SetBoltFrame — assign bolt frame with reference counting */
void Effect_SetBoltFrame(const Effect *_this, FxBoltFramePtr *boltFrame)
{
    FxBoltFrame **bfSlot = (FxBoltFrame **)&((Effect *)_this)->mBolt;
    FxBoltFrame *newBf = *(FxBoltFrame **)boltFrame;
    FxBoltFrame *oldBf = *bfSlot;

    if (oldBf == newBf)
        return;

    /* Release old bolt frame */
    if (oldBf) {
        int rc = oldBf->refCount - 1;
        oldBf->refCount = rc;
        if (rc == 0) {
            /* Remove from linked list and free */
            byte **prevNext = &__ZN11FxBoltFrame12g_mFrameListE;
            FxBoltFrame *cur = (FxBoltFrame *)*prevNext;
            while (cur) {
                if (cur == oldBf) { *prevNext = (byte *)oldBf->next; break; }
                prevNext = (byte **)&cur->next;
                cur = cur->next;
            }
            if (oldBf) __ZdaPv(oldBf);
        }
        *bfSlot = NULL;
    }

    /* Acquire new bolt frame */
    if (newBf) {
        newBf->refCount += 1;
        *bfSlot = newBf;
    }
}

/* Particle_UpdateRGB — evaluate 3-component RGB curve, convert to RGBA bytes */
void Particle_UpdateRGB(const Particle *_this)
{
    byte *self = (byte *)_this;
    float normTime = ((Effect *)self)->mRefEnt.materialTime /* normTime */;
    float rgb[3];

    if (((byte *)&((Effect *)self)->mFlags)[1] & 0x20) {
        /* Blend path */
        float blendFactor = ((Particle *)self)->blendWeight[0];
        float v0[3], v1[3];
        EvalCurve3((byte *)&((Particle *)self)->colorChannelInstance, normTime, v0);
        EvalCurve3((byte *)&((Particle *)self)->colorRandChannelInstance, normTime, v1);
        float scale = ((Particle *)self)->colorChannelInstance.scale;
        rgb[0] = (v0[0] + (v1[0] - v0[0]) * blendFactor) * scale;
        rgb[1] = (v0[1] + (v1[1] - v0[1]) * blendFactor) * scale;
        rgb[2] = (v0[2] + (v1[2] - v0[2]) * blendFactor) * scale;
    } else {
        EvalCurve3((byte *)&((Particle *)self)->colorChannelInstance, normTime, rgb);
        float scale = ((Particle *)self)->colorChannelInstance.scale;
        rgb[0] *= scale;
        rgb[1] *= scale;
        rgb[2] *= scale;
    }

    /* Convert to bytes at offset 0x90 */
    ((Effect *)self)->worldRGBA[0] = (byte)FloatToByte(rgb[0]);
    ((Effect *)self)->worldRGBA[1] = (byte)FloatToByte(rgb[1]);
    ((Effect *)self)->worldRGBA[2] = (byte)FloatToByte(rgb[2]);
}

/* line 2251 */
Bool Flash_Update(const Flash * _this)
{
    Effect *effect = (Effect *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int startTime = effect->mTimeStart;
    int curTime = ((FxHelper *)helper)->mTime;
    int endTime;
    float normDuration;

    if (startTime > curTime)
        return 0;

    endTime = effect->mTimeEnd;
    normDuration = (float)(curTime - startTime) / (float)(endTime - startTime);
    effect->mRefEnt.materialTime /* normTime */ = normDuration;

    if (normDuration > 1.0f)
        effect->mRefEnt.materialTime /* normTime */ = 1.0f;

    if (0.0f > effect->mRefEnt.materialTime /* normTime */)
        effect->mRefEnt.materialTime /* normTime */ = 0.0f;

    /* line 2257: update RGB */
    Light_UpdateRGB((const Light *)_this, (const Light *)_this);
    return 1;
}

/* Particle_IntegrateVelocity — integrate velocity curve over normDuration, 3 axes, optional blend+transform */
extern float FxCurve_Integrate(void *curve, float normDuration);
static float IntegrateChannel(byte *self, int curveOff, int blendCurveOff, float blendFactor, int scaleOff, float normDuration, int useBlend)
{
    float val;
    if (useBlend) {
        float v0 = FxCurve_Integrate(*(void **)(self + curveOff), normDuration);
        float v1 = FxCurve_Integrate(*(void **)(self + blendCurveOff), normDuration);
        val = v0 + (v1 - v0) * blendFactor;
    } else {
        val = FxCurve_Integrate(*(void **)(self + curveOff), normDuration);
    }
    return val * *(float *)(self + scaleOff);
}
void Particle_IntegrateVelocity(const Particle *_this, float normDuration, vec_t *outVector)
{
    byte *self = (byte *)_this;
    int useBlend = (((byte *)&((Effect *)self)->mFlags)[2] & 8) != 0;
    float vx, vy, vz;

    if (useBlend) {
        vx = IntegrateChannel(self, 0x1bc /* velocityXCI */, 0x1e0 /* velocityXRandCI */, ((Particle *)self)->velocityWeightX, 0x1c4 /* velocityXCI.scale */, normDuration, 1);
        vy = IntegrateChannel(self, 0x1c8 /* velocityYCI */, 0x1ec /* velocityYRandCI */, ((Particle *)self)->velocityWeightY, 0x1d0 /* velocityYCI.scale */, normDuration, 1);
        vz = IntegrateChannel(self, 0x1d4 /* velocityZCI */, 0x1f8 /* velocityZRandCI */, ((Particle *)self)->velocityWeightZ, 0x1dc /* velocityZCI.scale */, normDuration, 1);
    } else {
        vx = IntegrateChannel(self, 0x1bc /* velocityXCI */, 0, 0, 0x1c4 /* velocityXCI.scale */, normDuration, 0);
        vy = IntegrateChannel(self, 0x1c8 /* velocityYCI */, 0, 0, 0x1d0 /* velocityYCI.scale */, normDuration, 0);
        vz = IntegrateChannel(self, 0x1d4 /* velocityZCI */, 0, 0, 0x1dc /* velocityZCI.scale */, normDuration, 0);
    }

    /* Optional axis transform (if NOT flag bit 5) */
    if (!(((byte *)&((Effect *)self)->mFlags)[2] & 0x20)) {
        AxisTransformVector((float *)((Particle *)self)->displayAxis, vx, vy, vz, outVector);
    } else {
        outVector[0] = vx;
        outVector[1] = vy;
        outVector[2] = vz;
    }

    /* Scale by lifetime in seconds */
    float lifetimeSec = (float)(((Effect *)self)->mTimeEnd - ((Effect *)self)->mTimeStart) * 0.001f;
    outVector[0] *= lifetimeSec;
    outVector[1] *= lifetimeSec;
    outVector[2] *= lifetimeSec;
}

/* line 906 — Particle_IntegrateVelocity2 — same pattern as IntegrateVelocity but different channel offsets */
void Particle_IntegrateVelocity2(const Particle *_this, float normDuration, vec_t *outVector)
{
    byte *self = (byte *)_this;
    int useBlend = (((byte *)&((Effect *)self)->mFlags)[2] & 8) != 0;
    float vx, vy, vz;

    /* Velocity2 channels are at offsets 0x204, 0x210, 0x21c with blend variants at 0x228, 0x234, 0x240. */
    if (useBlend) {
        vx = IntegrateChannel(self, 0x204 /* velocity2XCI */, 0x228 /* velocity2XRandCI */, ((Particle *)self)->velocity2WeightX, 0x20c /* velocity2XCI.scale */, normDuration, 1);
        vy = IntegrateChannel(self, 0x210 /* velocity2YCI */, 0x234 /* velocity2YRandCI */, ((Particle *)self)->velocity2WeightY, 0x218 /* velocity2YCI.scale */, normDuration, 1);
        vz = IntegrateChannel(self, 0x21c /* velocity2ZCI */, 0x240 /* velocity2ZRandCI */, ((Particle *)self)->velocity2WeightZ, 0x224 /* velocity2ZCI.scale */, normDuration, 1);
    } else {
        vx = IntegrateChannel(self, 0x204 /* velocity2XCI */, 0, 0, 0x20c /* velocity2XCI.scale */, normDuration, 0);
        vy = IntegrateChannel(self, 0x210 /* velocity2YCI */, 0, 0, 0x218 /* velocity2YCI.scale */, normDuration, 0);
        vz = IntegrateChannel(self, 0x21c /* velocity2ZCI */, 0, 0, 0x224 /* velocity2ZCI.scale */, normDuration, 0);
    }

    if (!(((byte *)&((Effect *)self)->mFlags)[2] & 0x20)) {
        AxisTransformVector((float *)((Particle *)self)->displayAxis, vx, vy, vz, outVector);
    } else {
        outVector[0] = vx; outVector[1] = vy; outVector[2] = vz;
    }

    float lifetimeSec = (float)(((Effect *)self)->mTimeEnd - ((Effect *)self)->mTimeStart) * 0.001f;
    outVector[0] *= lifetimeSec; outVector[1] *= lifetimeSec; outVector[2] *= lifetimeSec;
}

/* Particle_IntegrateTotalVelocity — integrate vel1 + vel2 + gravity over duration */
void Particle_IntegrateTotalVelocity(const Particle *_this, int duration, vec_t *outVector)
{
    byte *self = (byte *)_this;
    int lifetime = ((Effect *)self)->mTimeEnd - ((Effect *)self)->mTimeStart;
    float durationF = (float)duration;
    float normDuration;
    if (lifetime > duration) {
        normDuration = durationF / (float)lifetime;
    } else {
        normDuration = 1.0f;
    }
    vec3_t velocitySum, velocity2Sum;
    Particle_IntegrateVelocity(_this, normDuration, velocitySum);
    Particle_IntegrateVelocity2(_this, normDuration, velocity2Sum);

    /* Gravity: gravityScale * duration_ms * 0.001 * duration_ms * 0.001 * {0, 0, gravity} */
    float gravityAccum = durationF * ((Particle *)self)->gravity * 0.001f;
    float scale = durationF * 0.001f;
    float gravX = scale * 0.0f; /* gravity is only in Z */
    float gravY = scale * 0.0f;
    float gravZ = scale * gravityAccum;

    outVector[0] = velocitySum[0] + velocity2Sum[0] + gravX;
    outVector[1] = velocitySum[1] + velocity2Sum[1] + gravY;
    outVector[2] = velocitySum[2] + velocity2Sum[2] + gravZ;
}

/* line 360 */
void Particle_Particle(const Particle * _this)
{
    ((Effect *)_this)->mBolt._placeholder = 0;  /* offset 0xc0 */
    *(int *)_this = 0x32ffc8;  /* vtable pointer */
    ((Particle *)_this)->subclassField0 = 0;
    ((Particle *)_this)->subclassField1 = 0;
    ((Particle *)_this)->subclassField2 = 0;
}

/* overload skip: Particle_Particle (0xa2e3c) */

/* Particle D1 destructor — cleanup bolt frame, set vtable to Effect base */
void ZN8ParticleD1Ev_impl(void *_this)
{
    Particle *self = (Particle *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN8ParticleD1Ev(void) /* Particle_~Particle */
{
    /* naked trampoline — not callable under WASM */
}

/* Particle D0 destructor — cleanup bolt frame + delete this */
void ZN8ParticleD0Ev_impl(void *_this)
{
    Particle *self = (Particle *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN8ParticleD0Ev(void) /* Particle_~Particle */
{
    /* naked trampoline — not callable under WASM */
}

/* line 2131 */
void Light_Light(const Light * _this)
{
    ((Effect *)_this)->mBolt._placeholder = 0;  /* offset 0xc0 */
    *(int *)_this = 0x330188;  /* vtable pointer */
}

/* overload skip: Light_Light (0xa2f4c) */

/* line 2136 */
/* Light D1 destructor — cleanup bolt frame */
void ZN5LightD1Ev_impl(void *_this) {
    Light *self = (Light *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN5LightD1Ev(void) /* Light_~Light */
{
    /* naked trampoline — not callable under WASM */
}

/* line 2136 */
/* Light D0 destructor — cleanup bolt frame + delete this */
void ZN5LightD0Ev_impl(void *_this) {
    Light *self = (Light *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN5LightD0Ev(void) /* Light_~Light */
{
    /* naked trampoline — not callable under WASM */
}

/* Tail_InitEndPoint — evaluate tail length curve(s) at normTime, store in endLength at 0x258, call CalcNewEndpoint */
void Tail_InitEndPoint(const Tail *_this)
{
    byte *self = (byte *)_this;
    float normTime = ((Effect *)self)->mRefEnt.materialTime /* normTime */;

    /* Evaluate tail length curve (1-component, optional blend) */
    float tailLen;
    if (((byte *)&((Effect *)self)->mFlags)[2] & 2) {
        float blendFactor = ((Tail *)self)->lengthBlendFactor;
        float v0 = EvalCurve1((byte *)&((Tail *)self)->lengthChannelInstance, normTime);
        float v1 = EvalCurve1((byte *)&((Tail *)self)->lengthRandChannelInstance, normTime);
        tailLen = (v0 + (v1 - v0) * blendFactor) * ((Tail *)self)->lengthChannelInstance.scale;
    } else {
        tailLen = EvalCurve1((byte *)&((Tail *)self)->lengthChannelInstance, normTime) * ((Tail *)self)->lengthChannelInstance.scale;
    }
    ((Tail *)self)->tailLength = tailLen;

    /* Get bolt orientation for CalcNewEndpoint */
    FxBoltFrame *boltFrame = ((Effect *)self)->mBolt.value;
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = boltFrame->mBolt.dobjHandle;
        if (boneIdx >= 0) {
            int clTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
            if (boltFrame->cachedServerTime != clTime) {
                boltFrame->cachedServerTime = clTime;
                if (!FX_GetBoneOrientation((int *)&boltFrame->mBolt, &boltFrame->orientation))
                    { boltFrame->mBolt.dobjHandle = -1; boltFrame->mBolt.boneIndex = -1; }
            }
            if (boltFrame->mBolt.dobjHandle >= 0)
                orient = &boltFrame->orientation;
        }
    }

    Tail_CalcNewEndpoint(_this, (const orientation_t *)orient);
}

/* Light_Update — normTime computation, bolt orientation, radius eval, RGB update */
Bool Light_Update(const Light *_this)
{
    byte *self = (byte *)_this;
    int startTime = ((Effect *)self)->mTimeStart;
    int killTime = ((Effect *)self)->mTimeEnd;
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;

    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    ((Effect *)self)->mRefEnt.materialTime /* normTime */ = normTime;
    if (normTime < 0.0f) return 0;

    /* Get bolt orientation */
    FxBoltFrame *boltFrame = ((Effect *)self)->mBolt.value;
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = boltFrame->mBolt.dobjHandle;
        if (boneIdx >= 0) {
            int clTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
            if (boltFrame->cachedServerTime != clTime) {
                boltFrame->cachedServerTime = clTime;
                if (!FX_GetBoneOrientation((int *)&boltFrame->mBolt, &boltFrame->orientation))
                    { boltFrame->mBolt.dobjHandle = -1; boltFrame->mBolt.boneIndex = -1; }
            }
            if (boltFrame->mBolt.dobjHandle >= 0)
                orient = &boltFrame->orientation;
        }
    }

    /* World position from bolt or direct */
    if (orient) {
        OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)((Effect *)self)->worldOrigin);
    } else {
        ((Effect *)self)->worldOrigin[0] = *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */;
        ((Effect *)self)->worldOrigin[1] = ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */;
        ((Effect *)self)->worldOrigin[2] = ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */;
    }

    /* Evaluate radius curve */
    float radius;
    if (((byte *)&((Effect *)self)->mFlags)[1] & 0x10) {
        float bf = ((Light *)self)->sizeBlendFactor;
        float v0 = EvalCurve1((byte *)&((Light *)self)->sizeChannelInstance, normTime);
        float v1 = EvalCurve1((byte *)&((Light *)self)->sizeRandChannelInstance, normTime);
        radius = (v0 + (v1 - v0) * bf) * ((Light *)self)->sizeChannelInstance.scale;
    } else {
        radius = EvalCurve1((byte *)&((Light *)self)->sizeChannelInstance, normTime) * ((Light *)self)->sizeChannelInstance.scale;
    }
    ((Effect *)self)->worldRadius[0] = radius;
    ((Effect *)self)->worldRadius[1] = radius;

    if (radius == 0.0f) {
        ((Effect *)self)->mFlags |= 0x01000000;
        return 1;
    }

    /* Update RGB */
    Light_UpdateRGB(_this, NULL);
    return 1;
}

/* Particle_CalcVelocityValue — evaluate 3-component velocity curve at normTime, optional blend + axis transform */
/* Uses FxCurve channels at offsets: X=0x1bc, Y=0x1c8, Z=0x1d4 (source0) and X=0x1e0, Y=0x1ec, Z=0x1f8 (source1) */
/* Blend factors at 0x12c (X), 0x130 (Y), 0x134 (Z). Scale at channelInst+8. */
void Particle_CalcVelocityValue(const Particle *_this, float normTime, vec_t *outVector, const orientation_t *or_)
{
    byte *self = (byte *)_this;
    float vx, vy, vz;

    if (((byte *)&((Effect *)self)->mFlags)[2] & 8) {
        /* Blend path: interpolate between source0 and source1 for each axis */
        float bfx = ((Particle *)self)->velocityWeightX;
        float v0x = EvalCurve1((byte *)&((Particle *)self)->velocityXChannelInstance, normTime);
        float v1x = EvalCurve1((byte *)&((Particle *)self)->velocityXRandChannelInstance, normTime);
        vx = (v0x + (v1x - v0x) * bfx) * ((Particle *)self)->velocityXChannelInstance.scale;

        float bfy = ((Particle *)self)->velocityWeightY;
        float v0y = EvalCurve1((byte *)&((Particle *)self)->velocityYChannelInstance, normTime);
        float v1y = EvalCurve1((byte *)&((Particle *)self)->velocityYRandChannelInstance, normTime);
        vy = (v0y + (v1y - v0y) * bfy) * ((Particle *)self)->velocityYChannelInstance.scale;

        float bfz = ((Particle *)self)->velocityWeightZ;
        float v0z = EvalCurve1((byte *)&((Particle *)self)->velocityZChannelInstance, normTime);
        float v1z = EvalCurve1((byte *)&((Particle *)self)->velocityZRandChannelInstance, normTime);
        vz = (v0z + (v1z - v0z) * bfz) * ((Particle *)self)->velocityZChannelInstance.scale;
    } else {
        /* Direct path: single source per axis */
        vx = EvalCurve1((byte *)&((Particle *)self)->velocityXChannelInstance, normTime) * ((Particle *)self)->velocityXChannelInstance.scale;
        vy = EvalCurve1((byte *)&((Particle *)self)->velocityYChannelInstance, normTime) * ((Particle *)self)->velocityYChannelInstance.scale;
        vz = EvalCurve1((byte *)&((Particle *)self)->velocityZChannelInstance, normTime) * ((Particle *)self)->velocityZChannelInstance.scale;
    }

    /* Optional axis transform (if NOT flag bit 5 at 0xaa) */
    if (!(((byte *)&((Effect *)self)->mFlags)[2] & 0x20)) {
        AxisTransformVector((float *)((Particle *)self)->displayAxis, vx, vy, vz, outVector);
    } else {
        outVector[0] = vx;
        outVector[1] = vy;
        outVector[2] = vz;
    }
}

/* line 816 — Particle_CalcVelocity2Value: same as CalcVelocityValue but for secondary velocity channels */
/* Channels: X=0x204, Y=0x210, Z=0x21c (source0) and X=0x228, Y=0x234, Z=0x240 (source1) */
/* Blend factors at 0x138 (X), 0x13c (Y), 0x140 (Z) */
void Particle_CalcVelocity2Value(const Particle *_this, float normTime, vec_t *outVector, const orientation_t *or_)
{
    (void)or_;
    byte *self = (byte *)_this;
    float vx, vy, vz;

    if (((byte *)&((Effect *)self)->mFlags)[2] & 8) {
        float bfx = ((Particle *)self)->velocity2WeightX;
        float v0x = EvalCurve1((byte *)&((Particle *)self)->velocity2XChannelInstance, normTime);
        float v1x = EvalCurve1((byte *)&((Particle *)self)->velocity2XRandChannelInstance, normTime);
        vx = (v0x + (v1x - v0x) * bfx) * ((Particle *)self)->velocity2XChannelInstance.scale;

        float bfy = ((Particle *)self)->velocity2WeightY;
        float v0y = EvalCurve1((byte *)&((Particle *)self)->velocity2YChannelInstance, normTime);
        float v1y = EvalCurve1((byte *)&((Particle *)self)->velocity2YRandChannelInstance, normTime);
        vy = (v0y + (v1y - v0y) * bfy) * ((Particle *)self)->velocity2YChannelInstance.scale;

        float bfz = ((Particle *)self)->velocity2WeightZ;
        float v0z = EvalCurve1((byte *)&((Particle *)self)->velocity2ZChannelInstance, normTime);
        float v1z = EvalCurve1((byte *)&((Particle *)self)->velocity2ZRandChannelInstance, normTime);
        vz = (v0z + (v1z - v0z) * bfz) * ((Particle *)self)->velocity2ZChannelInstance.scale;
    } else {
        vx = EvalCurve1((byte *)&((Particle *)self)->velocity2XChannelInstance, normTime) * ((Particle *)self)->velocity2XChannelInstance.scale;
        vy = EvalCurve1((byte *)&((Particle *)self)->velocity2YChannelInstance, normTime) * ((Particle *)self)->velocity2YChannelInstance.scale;
        vz = EvalCurve1((byte *)&((Particle *)self)->velocity2ZChannelInstance, normTime) * ((Particle *)self)->velocity2ZChannelInstance.scale;
    }

    if (!(((byte *)&((Effect *)self)->mFlags)[2] & 0x20)) {
        AxisTransformVector((float *)((Particle *)self)->displayAxis, vx, vy, vz, outVector);
    } else {
        outVector[0] = vx; outVector[1] = vy; outVector[2] = vz;
    }
}

/* Particle_GetTotalVelocity — compute total velocity (vel1 + vel2 + gravity + impact offset) at normTime */
void Particle_GetTotalVelocity(const Particle *_this, float normTime, vec_t *outVector, const orientation_t *or_)
{
    byte *self = (byte *)_this;
    vec3_t velocityValue, velocity2Value, gravityValue;

    Particle_CalcVelocityValue(_this, normTime, velocityValue, or_);
    Particle_CalcVelocity2Value(_this, normTime, velocity2Value, or_);

    /* Compute gravity contribution */
    int lifetime = ((Effect *)self)->mTimeEnd - ((Effect *)self)->mTimeStart;
    int duration = (int)((float)lifetime * normTime);
    gravityValue[0] = 0.0f;
    gravityValue[1] = 0.0f;
    float gravZ = (float)duration * ((Particle *)self)->gravity * 0.001f;

    if (or_) {
        /* Transform gravity to local space */
        vec3_t worldGrav;
        worldGrav[0] = 0.0f;
        worldGrav[1] = 0.0f;
        worldGrav[2] = gravZ;
        OrientationDirFromWorldDir((void *)or_, worldGrav, gravityValue);
    } else {
        gravityValue[0] = 0.0f;
        gravityValue[1] = 0.0f;
        gravityValue[2] = gravZ;
    }

    /* Sum all velocity components + impact offset (subclassField0/1/2 = Particle.subclassField0/1/2) */
    outVector[0] = velocityValue[0] + velocity2Value[0] + gravityValue[0] + *(float *)&((Particle *)self)->subclassField0;
    outVector[1] = velocityValue[1] + velocity2Value[1] + gravityValue[1] + *(float *)&((Particle *)self)->subclassField1;
    outVector[2] = velocityValue[2] + velocity2Value[2] + gravityValue[2] + *(float *)&((Particle *)self)->subclassField2;
}

/* Emitter_UpdateEmitFx — spawn sub-effects along emitter trajectory at step intervals */
void Emitter_UpdateEmitFx(const Emitter *_this, vec_t *bindVelocity, const orientation_t *or_)
{
    byte *self = (byte *)_this;

    /* Check emit flag */
    if (!(((byte *)&((Effect *)self)->mFlags)[1] & 1))
        return;

    byte *helper = *(byte **)imp_theFxHelper;
    int frameTimeMs = ((FxHelper *)helper)->mFrameTime;
    if (frameTimeMs == 0)
        return;

    float step = ((Emitter *)self)->emitStep;
    float step2 = step * step;
    int t = ((Emitter *)self)->emitNextTime;
    int startTime = ((Effect *)self)->mTimeStart;
    float age = (float)(((FxHelper *)helper)->mTime - startTime) * 0.001f;
    float lifeTime = (float)(((Effect *)self)->mTimeEnd - startTime) * 0.001f;

    int dif = 0;
    float ftimeTotal = 0.0f;

    /* Time-stepping loop: advance by 12ms per step */
    while (t < ((FxHelper *)helper)->mTime) {
        dif += 12;
        float ftime = (float)dif * 0.001f;

        /* Save old position */
        vec3_t oldorg;
        oldorg[0] = ((Emitter *)self)->emitPos[0] + ((Emitter *)self)->emitVel[0];
        oldorg[1] = ((Emitter *)self)->emitPos[1] + ((Emitter *)self)->emitVel[1];
        oldorg[2] = ((Emitter *)self)->emitPos[2] + ((Emitter *)self)->emitVel[2];

        /* Compute normalized time */
        float normTime = (ftimeTotal + age) / lifeTime;
        if (normTime > 1.0f) normTime = 1.0f;

        /* Get velocity at normTime */
        vec3_t velocity;
        Particle_GetTotalVelocity((const Particle *)_this, normTime, velocity, or_);

        /* Compute new position = base + velocity * ftime */
        vec3_t org;
        org[0] = ((Emitter *)self)->emitPos[0] + velocity[0] * ftime;
        org[1] = ((Emitter *)self)->emitPos[1] + velocity[1] * ftime;
        org[2] = ((Emitter *)self)->emitPos[2] + velocity[2] * ftime;

        /* Add bind velocity if present */
        if (or_ && bindVelocity) {
            org[0] += bindVelocity[0] * ftime;
            org[1] += bindVelocity[1] * ftime;
            org[2] += bindVelocity[2] * ftime;
        }

        /* Check if moved far enough to spawn */
        float distSq = Vec3DistanceSq(org, oldorg);
        if (distSq < step2) {
            t += 12;
            continue;
        }

        /* Spawn effect at computed position */
        vec3_t spawnPos;
        if (or_) {
            OrientationPosToWorldPos((void *)or_, org, spawnPos);
        } else {
            spawnPos[0] = org[0]; spawnPos[1] = org[1]; spawnPos[2] = org[2];
        }

        /* Get bolt info for PlayEffect */
        FxBoltInfo *boltInfo = NULL;
        if (((Effect *)self)->mBolt.value)
            boltInfo = &(((Effect *)self)->mBolt.value)->mBolt;

        void *emitEffect = ((Emitter *)self)->emitFx;
        FxScheduler_PlayEffect(*(void **)imp_theFxScheduler, emitEffect, spawnPos, NULL);

        /* Advance with adaptive time step based on velocity */
        float velLenSq = velocity[0]*velocity[0] + velocity[1]*velocity[1] + velocity[2]*velocity[2];
        float dF = (velLenSq + velLenSq) * ftime;
        float nextFtime;
        if (dF != 0.0f) {
            /* Adaptive: nextFtime based on step/velocity ratio */
            float sq;
            sq = sqrtf(step2 / dF);
            nextFtime = sq * ftime;
        } else {
            nextFtime = ftime;
        }
        float nextTime = nextFtime + (ftimeTotal + age);
        float nextNormTime = nextTime / lifeTime;
        if (nextNormTime > 1.0f) nextNormTime = 1.0f;

        /* Get velocity at next time for position update */
        vec3_t nextVel;
        Particle_GetTotalVelocity((const Particle *)_this, nextNormTime, nextVel, or_);

        /* Update emitter origin to new position */
        ((Emitter *)self)->emitPos[0] = org[0];
        ((Emitter *)self)->emitPos[1] = org[1];
        ((Emitter *)self)->emitPos[2] = org[2];
        ((Emitter *)self)->emitVel[0] = nextVel[0] * nextFtime - velocity[0] * ftime;
        ((Emitter *)self)->emitVel[1] = nextVel[1] * nextFtime - velocity[1] * ftime;
        ((Emitter *)self)->emitVel[2] = nextVel[2] * nextFtime - velocity[2] * ftime;

        ftimeTotal += nextFtime;
        dif = (int)(ftimeTotal * 1000.0f);
        t = startTime + dif;
        ((Emitter *)self)->emitNextTime = t;
    }
}

/* Particle_GetTotalVelocityAtTime0 — get velocity at t=0 using bolt orientation if available */
extern void *imp_cl;
void Particle_GetTotalVelocityAtTime0(const Particle *_this, vec_t *outVector)
{
    byte *self = (byte *)_this;
    FxBoltFrame *boltFrame = ((Effect *)self)->mBolt.value;
    void *orient = NULL;

    if (boltFrame) {
        int boneIdx = boltFrame->mBolt.dobjHandle;
        if (boneIdx < 0) {
            outVector[0] = outVector[1] = outVector[2] = 0.0f;
            return;
        }
        int curTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
        if (curTime != boltFrame->cachedServerTime) {
            boltFrame->cachedServerTime = curTime;
            Bool ok = FX_GetBoneOrientation((int *)&boltFrame->mBolt, &boltFrame->orientation);
            if (!ok) {
                boltFrame->mBolt.dobjHandle = -1;
                boltFrame->mBolt.boneIndex = -1;
                outVector[0] = outVector[1] = outVector[2] = 0.0f;
                return;
            }
        }
        orient = &boltFrame->orientation;
        if (!orient) {
            outVector[0] = outVector[1] = outVector[2] = 0.0f;
            return;
        }
    }
    Particle_GetTotalVelocity(_this, 0.0f, outVector, (const orientation_t *)orient);
}

/* Particle_ApplyImpact — apply collision: bounce velocity via reflection, update impact offset */
void Particle_ApplyImpact(const Particle *_this, const orientation_t *or_, float normTime, const vec_t *velocity, float traceFraction, const vec_t *traceNormal)
{
    byte *self = (byte *)_this;

    /* Check if normal Z > 0 AND velocity has enough speed (> 16 squared = 4.0 per axis) */
    if (traceNormal[2] > 0.0f) {
        float vLenSq = velocity[0]*velocity[0] + velocity[1]*velocity[1] + velocity[2]*velocity[2];
        if (vLenSq >= 16.0f)
            goto do_reflect;
    }

    /* traceFraction == 0 means stuck - disable impact */
    if (traceFraction == 0.0f) {
        int flags = ((Effect *)self)->mFlags;
        flags &= ~0x0800; /* clear bit 11 */
        flags &= ~0x0020; /* clear bit 5 */
        flags |= 0x01000000; /* set bit 24 */
        ((Effect *)self)->mFlags = flags;
        return;
    }

do_reflect:;
    /* Transform traceNormal to local space if orientation exists */
    vec3_t normal;
    if (or_) {
        OrientationDirFromWorldDir((void *)or_, (vec_t *)traceNormal, normal);
    } else {
        normal[0] = traceNormal[0];
        normal[1] = traceNormal[1];
        normal[2] = traceNormal[2];
    }

    /* Get current total velocity and apply bounce scale */
    vec3_t reflectVelocity;
    Particle_GetTotalVelocity(_this, normTime, reflectVelocity, or_);

    /* Save old velocity for delta computation */
    float oldVx = reflectVelocity[0] - *(float *)&((Particle *)self)->subclassField0;
    float oldVy = reflectVelocity[1] - *(float *)&((Particle *)self)->subclassField1;
    float oldVz = reflectVelocity[2] - *(float *)&((Particle *)self)->subclassField2;

    /* Scale velocity by bounce coefficient */
    float bounceScale = ((Particle *)self)->elasticity;
    reflectVelocity[0] *= bounceScale;
    reflectVelocity[1] *= bounceScale;
    reflectVelocity[2] *= bounceScale;

    /* Update impact offset = scaled - old */
    *(float *)&((Particle *)self)->subclassField0 = reflectVelocity[0] - oldVx;
    *(float *)&((Particle *)self)->subclassField1 = reflectVelocity[1] - oldVy;
    *(float *)&((Particle *)self)->subclassField2 = reflectVelocity[2] - oldVz;

    /* Compute reflection: v' = v + 2 * (-dot(v, n)) * n */
    float dot = reflectVelocity[0]*normal[0] + reflectVelocity[1]*normal[1] + reflectVelocity[2]*normal[2];
    float reflScale = -2.0f * dot;
    *(float *)&((Particle *)self)->subclassField0 += reflScale * normal[0];
    *(float *)&((Particle *)self)->subclassField1 += reflScale * normal[1];
    *(float *)&((Particle *)self)->subclassField2 += reflScale * normal[2];
}

/* Particle_UpdateOrigin — integrate velocity, trace collision, apply impact, update position */
extern void FxHelper_Trace(void *helper, void *trace, vec_t *start, vec_t *mins, vec_t *maxs, vec_t *end, int contents, int mask);
extern void *imp_vec3_origin;
Bool Particle_UpdateOrigin(const Particle *_this, const orientation_t *or_)
{
    byte *self = (byte *)_this;

    /* Check locked flag */
    if (((byte *)&((Effect *)self)->mFlags)[3] & 1)
        return 1;

    /* Get frame time */
    byte *helper = *(byte **)imp_theFxHelper;
    int frameTimeMs = ((FxHelper *)helper)->mFrameTime;
    if (frameTimeMs == 0)
        return 1;

    float ftime = (float)frameTimeMs * 0.001f;
    int startTime = ((Effect *)self)->mTimeStart;
    float age = (float)(((FxHelper *)helper)->mTime - startTime) * 0.001f;
    float lifeTime = (float)(((Effect *)self)->mTimeEnd - startTime) * 0.001f;
    float normTime = age / lifeTime;
    if (normTime > 1.0f) normTime = 1.0f;

    /* Get total velocity at normTime */
    vec3_t velocity;
    Particle_GetTotalVelocity(_this, normTime, velocity, or_);

    /* Compute new origin = old + velocity * ftime */
    float *origin = (float *)(self + 4) /* mRefEnt.customMaterial (localOrigin[0]) */;
    vec3_t new_origin;
    new_origin[0] = origin[0] + velocity[0] * ftime;
    new_origin[1] = origin[1] + velocity[1] * ftime;
    new_origin[2] = origin[2] + velocity[2] * ftime;

    /* Check for collision trace */
    int flags = ((Effect *)self)->mFlags;
    if (flags & 0x20) {
        vec3_t start_pt, end_pt;

        if (or_) {
            OrientationPosToWorldPos((void *)or_, origin, start_pt);
            OrientationPosToWorldPos((void *)or_, new_origin, end_pt);
        } else {
            start_pt[0] = origin[0]; start_pt[1] = origin[1]; start_pt[2] = origin[2];
            end_pt[0] = new_origin[0]; end_pt[1] = new_origin[1]; end_pt[2] = new_origin[2];
        }

        /* Do trace */
        byte trace[0x44];
        vec3_t *mins, *maxs;
        if (flags & 0x40) {
            mins = (vec3_t *)(self + 0x14);
            maxs = (vec3_t *)(self + 0x20);
        } else {
            mins = (vec3_t *)imp_vec3_origin;
            maxs = mins;
        }
        FxHelper_Trace(helper, trace, start_pt, (vec_t *)mins, (vec_t *)maxs, end_pt, -1, 1);

        /* Check trace result */
        float fraction = *(float *)trace;
        if (fraction < 1.0f) {
            /* Hit something */
            if (flags & 0x800) {
                /* Death effect at impact point */
                vec3_t endpos;
                endpos[0] = start_pt[0] + (end_pt[0] - start_pt[0]) * fraction;
                endpos[1] = start_pt[1] + (end_pt[1] - start_pt[1]) * fraction;
                endpos[2] = start_pt[2] + (end_pt[2] - start_pt[2]) * fraction;
                FxScheduler_PlayEffect(*(void **)imp_theFxScheduler, *(void **)&((Effect *)self)->mRefEnt.axis[2][2] /* impactFxHandle */, endpos, (vec_t *)(trace + 0x24) /* trace.normal */);
            }

            if (flags & 0x400) {
                /* Kill on impact */
                return 0;
            }

            /* Apply impact (bounce) */
            float newFtime = ftime * fraction;
            float newAge = age + newFtime;
            float newNormTime = newAge / lifeTime;
            if (newNormTime > 1.0f) newNormTime = 1.0f;
            Particle_ApplyImpact(_this, or_, newNormTime, velocity, fraction, (vec_t *)(trace + 0x24) /* trace.normal */);

            /* Interpolate position by fraction */
            origin[0] = origin[0] + (new_origin[0] - origin[0]) * fraction;
            origin[1] = origin[1] + (new_origin[1] - origin[1]) * fraction;
            origin[2] = origin[2] + (new_origin[2] - origin[2]) * fraction;
            return 1;
        }
    }

    /* No collision — just copy new origin */
    origin[0] = new_origin[0];
    origin[1] = new_origin[1];
    origin[2] = new_origin[2];
    return 1;
}

/* Emitter_Update — full emitter tick: normTime, bolt, origin, emit sub-effects, endpoint, radius, RGB, alpha */
Bool Emitter_Update(const Emitter *_this)
{
    byte *self = (byte *)_this;
    int startTime = ((Effect *)self)->mTimeStart;
    int killTime = ((Effect *)self)->mTimeEnd;
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;

    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    ((Effect *)self)->mRefEnt.materialTime /* normTime */ = normTime;
    if (normTime < 0.0f) return 0;

    /* Get bolt orientation */
    FxBoltFrame *boltFrame = ((Effect *)self)->mBolt.value;
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = boltFrame->mBolt.dobjHandle;
        if (boneIdx >= 0) {
            int clTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
            if (boltFrame->cachedServerTime != clTime) {
                boltFrame->cachedServerTime = clTime;
                if (!FX_GetBoneOrientation((int *)&boltFrame->mBolt, &boltFrame->orientation))
                    { boltFrame->mBolt.dobjHandle = -1; boltFrame->mBolt.boneIndex = -1; }
            }
            if (boltFrame->mBolt.dobjHandle >= 0)
                orient = &boltFrame->orientation;
        }
    }

    /* Update origin */
    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient))
        return 0;

    /* Compute bind velocity for emitter */
    vec3_t bindVelocity = {0, 0, 0};
    if (orient) {
        /* Get velocity from bolt position delta */
        byte *helper = *(byte **)imp_theFxHelper;
        int frameTime = ((FxHelper *)helper)->mFrameTime;
        if (frameTime > 0) {
            float invFt = 1.0f / ((float)frameTime * 0.001f);
            vec3_t worldPos;
            OrientationPosToWorldPos(orient, (vec_t *)(self + 4), worldPos);
            bindVelocity[0] = (worldPos[0] - ((Effect *)self)->worldOrigin[0]) * invFt;
            bindVelocity[1] = (worldPos[1] - ((Effect *)self)->worldOrigin[1]) * invFt;
            bindVelocity[2] = (worldPos[2] - ((Effect *)self)->worldOrigin[2]) * invFt;
            ((Effect *)self)->worldOrigin[0] = worldPos[0];
            ((Effect *)self)->worldOrigin[1] = worldPos[1];
            ((Effect *)self)->worldOrigin[2] = worldPos[2];
        }
    } else {
        ((Effect *)self)->worldOrigin[0] = *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */;
        ((Effect *)self)->worldOrigin[1] = ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */;
        ((Effect *)self)->worldOrigin[2] = ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */;
    }

    /* Emit sub-effects */
    Emitter_UpdateEmitFx(_this, bindVelocity, (const orientation_t *)orient);

    /* Evaluate radius */
    float radius;
    if (*(short *)&((Effect *)self)->mFlags < 0) {
        float bf = ((Particle *)self)->blendWeight[2];
        float v0 = EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime);
        float v1 = EvalCurve1((byte *)&((Particle *)self)->sizeRandChannelInstance, normTime);
        radius = (v0 + (v1 - v0) * bf) * ((Particle *)self)->sizeChannelInstance.scale;
    } else {
        radius = EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) * ((Particle *)self)->sizeChannelInstance.scale;
    }
    ((Effect *)self)->worldRadius[0] = radius;

    if (radius == 0.0f) {
        ((Effect *)self)->mFlags |= 0x01000000;
        return 1;
    }

    /* Update RGB and alpha */
    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);

    return 1;
}

/* Particle_UpdateAlpha — evaluate alpha channel at normTime, apply to particle */
void Particle_UpdateAlpha(const Particle *_this)
{
    byte *self = (byte *)_this;
    float normTime = ((Effect *)self)->mRefEnt.materialTime /* normTime */;
    float alpha;

    if (((byte *)&((Effect *)self)->mFlags)[1] & 0x40) {
        /* Blend path */
        float blendFactor = ((Particle *)self)->blendWeight[1];
        float v0 = EvalCurve1((byte *)&((Particle *)self)->alphaChannelInstance, normTime);
        float v1 = EvalCurve1((byte *)&((Particle *)self)->alphaRandChannelInstance, normTime);
        alpha = v0 + (v1 - v0) * blendFactor;
    } else {
        alpha = EvalCurve1((byte *)&((Particle *)self)->alphaChannelInstance, normTime);
    }
    alpha *= ((Particle *)self)->alphaChannelInstance.scale;

    /* Clamp and convert to byte */
    if (alpha < 0.0f) alpha = 0.0f;
    if (alpha > 1.0f) alpha = 1.0f;
    int a = (int)floorf(alpha * 255.0f + 0.5f);
    if (a < 0) a = 0;
    if (a > 255) a = 255;
    ((Effect *)self)->worldRGBA[3] = (byte)a;
}

/* line 1749 — Cylinder_Update converted to C */
Bool Cylinder_Update(const Cylinder *_this)
{
    /* Cylinder_Update follows Tail_Update pattern: normTime + bolt + origin + tail length + endpoint + radius + RGB + alpha */
    byte *self = (byte *)_this;
    int startTime = ((Effect *)self)->mTimeStart;
    int killTime = ((Effect *)self)->mTimeEnd;
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    ((Effect *)self)->mRefEnt.materialTime /* normTime */ = normTime;
    if (normTime < 0.0f) return 0;

    byte *boltFrame = (byte *)((Effect *)self)->mBolt.value;
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle;
        if (boneIdx >= 0) {
            int clTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
            if (((FxBoltFrame *)boltFrame)->cachedServerTime != clTime) {
                ((FxBoltFrame *)boltFrame)->cachedServerTime = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8) /* FxBoltFrame.orientation */ /* FxBoltFrame.orientation */))
                    { ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle = -1; ((FxBoltFrame *)boltFrame)->mBolt.boneIndex = -1; }
            }
            if (((FxBoltFrame *)boltFrame)->mBolt.dobjHandle >= 0) orient = boltFrame + 8;
        }
    }

    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient)) return 0;

    if (orient) OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)((Effect *)self)->worldOrigin);
    else { ((Effect *)self)->worldOrigin[0] = *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */; ((Effect *)self)->worldOrigin[1] = ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */; ((Effect *)self)->worldOrigin[2] = ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */; }

    /* Tail length curves */
    float tailLen;
    if (((byte *)&((Effect *)self)->mFlags)[2] & 2) {
        float bf = ((Tail *)self)->lengthBlendFactor;
        tailLen = (EvalCurve1((byte *)&((Tail *)self)->lengthChannelInstance, normTime) + (EvalCurve1((byte *)&((Tail *)self)->lengthRandChannelInstance, normTime) - EvalCurve1((byte *)&((Tail *)self)->lengthChannelInstance, normTime)) * bf) * ((Tail *)self)->lengthChannelInstance.scale;
    } else {
        tailLen = EvalCurve1((byte *)&((Tail *)self)->lengthChannelInstance, normTime) * ((Tail *)self)->lengthChannelInstance.scale;
    }
    ((Tail *)self)->tailLength = tailLen;

    Tail_CalcNewEndpoint((const Tail *)_this, (const orientation_t *)orient);
    if (orient) OrientationPosToWorldPos(orient, (vec_t *)((Effect *)self)->worldEndpos, (vec_t *)((Effect *)self)->worldEndpos);

    /* Evaluate two radii for cylinder (start + end) */
    float radius1, radius2;
    if (*(short *)&((Effect *)self)->mFlags < 0) {
        float bf = ((Particle *)self)->blendWeight[2];
        radius1 = (EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) + (EvalCurve1((byte *)&((Particle *)self)->sizeRandChannelInstance, normTime) - EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime)) * bf) * ((Particle *)self)->sizeChannelInstance.scale;
        /* Second radius uses different curve at 0x198/0x1a4 */
        if (((byte *)&((Effect *)self)->mFlags)[2] & 4) {
            float bf2 = ((Particle *)self)->blendWeight[3];
            radius2 = (EvalCurve1((byte *)&((Particle *)self)->size2RandChannelInstance, normTime) + (EvalCurve1((byte *)&((Particle *)self)->rotationDeltaChannelInstance, normTime) - EvalCurve1((byte *)&((Particle *)self)->size2RandChannelInstance, normTime)) * bf2) * ((Particle *)self)->size2RandChannelInstance.scale;
        } else {
            radius2 = EvalCurve1((byte *)&((Particle *)self)->size2RandChannelInstance, normTime) * ((Particle *)self)->size2RandChannelInstance.scale;
        }
    } else {
        radius1 = EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) * ((Particle *)self)->sizeChannelInstance.scale;
        if (((byte *)&((Effect *)self)->mFlags)[2] & 4) {
            float bf2 = ((Particle *)self)->blendWeight[3];
            radius2 = (EvalCurve1((byte *)&((Particle *)self)->size2RandChannelInstance, normTime) + (EvalCurve1((byte *)&((Particle *)self)->rotationDeltaChannelInstance, normTime) - EvalCurve1((byte *)&((Particle *)self)->size2RandChannelInstance, normTime)) * bf2) * ((Particle *)self)->size2RandChannelInstance.scale;
        } else {
            radius2 = EvalCurve1((byte *)&((Particle *)self)->size2RandChannelInstance, normTime) * ((Particle *)self)->size2RandChannelInstance.scale;
        }
    }
    ((Effect *)self)->worldRadius[0] = radius1;
    ((Effect *)self)->worldRadius[1] = radius2;

    if (radius1 == 0.0f && radius2 == 0.0f) { ((Effect *)self)->mFlags |= 0x01000000; return 1; }

    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);
    return 1;
}

/* Tail_Update — Particle_Update + tail length eval + endpoint computation */
Bool Tail_Update(const Tail *_this)
{
    byte *self = (byte *)_this;
    int startTime = ((Effect *)self)->mTimeStart;
    int killTime = ((Effect *)self)->mTimeEnd;
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    ((Effect *)self)->mRefEnt.materialTime /* normTime */ = normTime;
    if (normTime < 0.0f) return 0;

    /* Get bolt orientation */
    byte *boltFrame = (byte *)((Effect *)self)->mBolt.value;
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle;
        if (boneIdx >= 0) {
            int clTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
            if (((FxBoltFrame *)boltFrame)->cachedServerTime != clTime) {
                ((FxBoltFrame *)boltFrame)->cachedServerTime = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8) /* FxBoltFrame.orientation */ /* FxBoltFrame.orientation */))
                    { ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle = -1; ((FxBoltFrame *)boltFrame)->mBolt.boneIndex = -1; }
            }
            if (((FxBoltFrame *)boltFrame)->mBolt.dobjHandle >= 0)
                orient = boltFrame + 8;
        }
    }

    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient))
        return 0;

    /* Transform origin to world */
    if (orient) OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)((Effect *)self)->worldOrigin);
    else { ((Effect *)self)->worldOrigin[0] = *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */; ((Effect *)self)->worldOrigin[1] = ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */; ((Effect *)self)->worldOrigin[2] = ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */; }

    /* Evaluate tail length curve(s) */
    float tailLen;
    if (((byte *)&((Effect *)self)->mFlags)[2] & 2) {
        float bf = ((Tail *)self)->lengthBlendFactor;
        float v0 = EvalCurve1((byte *)&((Tail *)self)->lengthChannelInstance, normTime);
        float v1 = EvalCurve1((byte *)&((Tail *)self)->lengthRandChannelInstance, normTime);
        tailLen = (v0 + (v1 - v0) * bf) * ((Tail *)self)->lengthChannelInstance.scale;
    } else {
        tailLen = EvalCurve1((byte *)&((Tail *)self)->lengthChannelInstance, normTime) * ((Tail *)self)->lengthChannelInstance.scale;
    }
    ((Tail *)self)->tailLength = tailLen;

    /* Compute new endpoint */
    Tail_CalcNewEndpoint(_this, (const orientation_t *)orient);

    /* Transform endpoint to world */
    if (orient) OrientationPosToWorldPos(orient, (vec_t *)((Effect *)self)->worldEndpos, (vec_t *)((Effect *)self)->worldEndpos);

    /* Evaluate radius */
    float radius;
    if (*(short *)&((Effect *)self)->mFlags < 0) {
        float bf = ((Particle *)self)->blendWeight[2];
        radius = (EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) + (EvalCurve1((byte *)&((Particle *)self)->sizeRandChannelInstance, normTime) - EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime)) * bf) * ((Particle *)self)->sizeChannelInstance.scale;
    } else {
        radius = EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) * ((Particle *)self)->sizeChannelInstance.scale;
    }
    ((Effect *)self)->worldRadius[0] = radius;
    ((Effect *)self)->worldRadius[1] = radius;

    if (radius == 0.0f) { ((Effect *)self)->mFlags |= 0x01000000; return 1; }

    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);
    return 1;
}

/* Line_Update — Particle_Update + endpoint transform for line/cylinder */
extern void OrientationPosToWorldPos(void *orient, vec_t *localPos, vec_t *worldPos);
Bool Line_Update(const Line *_this)
{
    byte *self = (byte *)_this;
    int startTime = ((Effect *)self)->mTimeStart;
    int killTime = ((Effect *)self)->mTimeEnd;
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;

    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    ((Effect *)self)->mRefEnt.materialTime /* normTime */ = normTime;
    if (normTime < 0.0f) return 0;

    /* Get bolt orientation */
    byte *boltFrame = (byte *)((Effect *)self)->mBolt.value;
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle;
        if (boneIdx >= 0) {
            int clTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
            if (((FxBoltFrame *)boltFrame)->cachedServerTime != clTime) {
                ((FxBoltFrame *)boltFrame)->cachedServerTime = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8) /* FxBoltFrame.orientation */ /* FxBoltFrame.orientation */))
                    { ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle = -1; ((FxBoltFrame *)boltFrame)->mBolt.boneIndex = -1; }
            }
            if (((FxBoltFrame *)boltFrame)->mBolt.dobjHandle >= 0)
                orient = boltFrame + 8;
        }
    }

    /* Update origin */
    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient))
        return 0;

    /* Transform origin to world space */
    if (orient)
        OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)((Effect *)self)->worldOrigin);
    else {
        ((Effect *)self)->worldOrigin[0] = *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */;
        ((Effect *)self)->worldOrigin[1] = ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */;
        ((Effect *)self)->worldOrigin[2] = ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */;
    }

    /* Transform endpoint (0x24c) to world space (0x9c) */
    if (orient)
        OrientationPosToWorldPos(orient, ((Line *)self)->endpoint, (vec_t *)((Effect *)self)->worldEndpos);
    else {
        ((Effect *)self)->worldEndpos[0] = ((Line *)self)->endpoint[0];
        ((Effect *)self)->worldEndpos[1] = ((Line *)self)->endpoint[1];
        ((Effect *)self)->worldEndpos[2] = ((Line *)self)->endpoint[2];
    }

    /* Evaluate radius */
    float radius;
    if (*(short *)&((Effect *)self)->mFlags < 0) {
        float bf = ((Particle *)self)->blendWeight[2];
        radius = (EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) + (EvalCurve1((byte *)&((Particle *)self)->sizeRandChannelInstance, normTime) - EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime)) * bf) * ((Particle *)self)->sizeChannelInstance.scale;
    } else {
        radius = EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) * ((Particle *)self)->sizeChannelInstance.scale;
    }
    ((Effect *)self)->worldRadius[0] = radius;
    ((Effect *)self)->worldRadius[1] = radius;

    if (radius == 0.0f) {
        ((Effect *)self)->mFlags |= 0x01000000;
        return 1;
    }

    /* Update RGB and alpha */
    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);

    return 1;
}

/* line 1418 — Cloud_Update converted to C */
Bool Cloud_Update(const Cloud *_this)
{
    /* Cloud follows Particle_Update + height/density channel eval + cloud-specific endpoint */
    byte *self = (byte *)_this;
    int startTime = ((Effect *)self)->mTimeStart;
    int killTime = ((Effect *)self)->mTimeEnd;
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    ((Effect *)self)->mRefEnt.materialTime /* normTime */ = normTime;
    if (normTime < 0.0f) return 0;

    byte *boltFrame = (byte *)((Effect *)self)->mBolt.value;
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle;
        if (boneIdx >= 0) {
            int clTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
            if (((FxBoltFrame *)boltFrame)->cachedServerTime != clTime) {
                ((FxBoltFrame *)boltFrame)->cachedServerTime = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8) /* FxBoltFrame.orientation */ /* FxBoltFrame.orientation */))
                    { ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle = -1; ((FxBoltFrame *)boltFrame)->mBolt.boneIndex = -1; }
            }
            if (((FxBoltFrame *)boltFrame)->mBolt.dobjHandle >= 0) orient = boltFrame + 8;
        }
    }

    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient)) return 0;

    if (orient) OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)((Effect *)self)->worldOrigin);
    else { ((Effect *)self)->worldOrigin[0] = *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */; ((Effect *)self)->worldOrigin[1] = ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */; ((Effect *)self)->worldOrigin[2] = ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */; }

    /* Evaluate radius */
    float radius;
    if (*(short *)&((Effect *)self)->mFlags < 0) {
        float bf = ((Particle *)self)->blendWeight[2];
        radius = (EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) + (EvalCurve1((byte *)&((Particle *)self)->sizeRandChannelInstance, normTime) - EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime)) * bf) * ((Particle *)self)->sizeChannelInstance.scale;
    } else {
        radius = EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) * ((Particle *)self)->sizeChannelInstance.scale;
    }
    ((Effect *)self)->worldRadius[0] = radius;
    if (radius == 0.0f) { ((Effect *)self)->mFlags |= 0x01000000; return 1; }

    /* Cloud-specific: height channel at 0x264/0x270 */
    float height;
    if (((byte *)&((Effect *)self)->mFlags)[2] & 2) {
        float bf = ((Cloud *)self)->lengthBlendFactor;
        height = (EvalCurve1((byte *)&((Cloud *)self)->lengthChannelInstance, normTime) + (EvalCurve1((byte *)&((Cloud *)self)->lengthRandChannelInstance, normTime) - EvalCurve1((byte *)&((Cloud *)self)->lengthChannelInstance, normTime)) * bf) * ((Cloud *)self)->lengthChannelInstance.scale;
    } else {
        height = EvalCurve1((byte *)&((Cloud *)self)->lengthChannelInstance, normTime) * ((Cloud *)self)->lengthChannelInstance.scale;
    }
    ((Effect *)self)->worldRadius[1] = height;
    if (height == 0.0f) { ((Effect *)self)->mFlags |= 0x01000000; return 1; }

    /* Rotation */
    if (((byte *)&((Effect *)self)->mFlags)[2] & 1) {
        float rot;
        if (((byte *)&((Effect *)self)->mFlags)[2] & 0x10) {
            float bf = ((Particle *)self)->blendWeight[4];
            rot = (EvalCurve1((byte *)&((Particle *)self)->size2ChannelInstance, normTime) + (EvalCurve1((byte *)&((Particle *)self)->size2RandChannelInstance, normTime) - EvalCurve1((byte *)&((Particle *)self)->size2ChannelInstance, normTime)) * bf) * ((Particle *)self)->size2ChannelInstance.scale;
        } else {
            rot = EvalCurve1((byte *)&((Particle *)self)->size2ChannelInstance, normTime) * ((Particle *)self)->size2ChannelInstance.scale;
        }
        ((Effect *)self)->worldSubimageIndex = rot;
    }

    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);
    return 1;
}

/* line 1282 — OrientedParticle_Update converted to C */
Bool OrientedParticle_Update(const OrientedParticle *_this)
{
    /* Same as Particle_Update + normal vector transform to world (0x24c → orient transform → 0x9c) */
    byte *self = (byte *)_this;
    int startTime = ((Effect *)self)->mTimeStart;
    int killTime = ((Effect *)self)->mTimeEnd;
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    ((Effect *)self)->mRefEnt.materialTime /* normTime */ = normTime;
    if (normTime < 0.0f) return 0;

    byte *boltFrame = (byte *)((Effect *)self)->mBolt.value;
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle;
        if (boneIdx >= 0) {
            int clTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
            if (((FxBoltFrame *)boltFrame)->cachedServerTime != clTime) {
                ((FxBoltFrame *)boltFrame)->cachedServerTime = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8) /* FxBoltFrame.orientation */ /* FxBoltFrame.orientation */))
                    { ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle = -1; ((FxBoltFrame *)boltFrame)->mBolt.boneIndex = -1; }
            }
            if (((FxBoltFrame *)boltFrame)->mBolt.dobjHandle >= 0) orient = boltFrame + 8;
        }
    }

    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient)) return 0;

    if (orient) {
        OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)((Effect *)self)->worldOrigin);
        /* Transform normal direction to world */
        OrientationDirFromWorldDir(orient, (vec_t *)(self + 0x24c), (vec_t *)((Effect *)self)->worldEndpos);
    } else {
        ((Effect *)self)->worldOrigin[0] = *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */; ((Effect *)self)->worldOrigin[1] = ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */; ((Effect *)self)->worldOrigin[2] = ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */;
        ((Effect *)self)->worldEndpos[0] = ((OrientedParticle *)self)->normal[0]; ((Effect *)self)->worldEndpos[1] = ((OrientedParticle *)self)->normal[1]; ((Effect *)self)->worldEndpos[2] = ((OrientedParticle *)self)->normal[2];
    }

    float radius;
    if (*(short *)&((Effect *)self)->mFlags < 0) {
        float bf = ((Particle *)self)->blendWeight[2];
        radius = (EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) + (EvalCurve1((byte *)&((Particle *)self)->sizeRandChannelInstance, normTime) - EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime)) * bf) * ((Particle *)self)->sizeChannelInstance.scale;
    } else {
        radius = EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) * ((Particle *)self)->sizeChannelInstance.scale;
    }
    ((Effect *)self)->worldRadius[0] = radius;
    if (radius == 0.0f) { ((Effect *)self)->mFlags |= 0x01000000; return 1; }

    /* Rotation eval */
    if (((byte *)&((Effect *)self)->mFlags)[2] & 1) {
        float rot;
        if (((byte *)&((Effect *)self)->mFlags)[2] & 0x10) {
            float bf = ((Particle *)self)->blendWeight[4];
            rot = (EvalCurve1((byte *)&((Particle *)self)->size2ChannelInstance, normTime) + (EvalCurve1((byte *)&((Particle *)self)->size2RandChannelInstance, normTime) - EvalCurve1((byte *)&((Particle *)self)->size2ChannelInstance, normTime)) * bf) * ((Particle *)self)->size2ChannelInstance.scale;
        } else {
            rot = EvalCurve1((byte *)&((Particle *)self)->size2ChannelInstance, normTime) * ((Particle *)self)->size2ChannelInstance.scale;
        }
        ((Effect *)self)->worldRadius[1] = rot;
    }

    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);
    return 1;
}

/* Particle_Update — core particle tick: normTime, origin update, radius eval, RGB/alpha update */
extern void OrientationPosToWorldPos(void *orient, vec_t *localPos, vec_t *worldPos);
Bool Particle_Update(const Particle *_this, const Particle *_this_1, const Cloud *_this_2)
{
    (void)_this_1; (void)_this_2;
    byte *self = (byte *)_this;
    int startTime = ((Effect *)self)->mTimeStart;
    int killTime = ((Effect *)self)->mTimeEnd;
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime)
        return 0; /* not started yet */

    /* Compute normalized time */
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    ((Effect *)self)->mRefEnt.materialTime /* normTime */ = normTime;
    if (normTime < 0.0f)
        return 0;

    /* Get bolt orientation if present */
    byte *boltFrame = (byte *)((Effect *)self)->mBolt.value;
    void *orient = NULL;
    if (boltFrame) {
        /* Get cached orientation from bolt frame */
        int boneIdx = ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle;
        if (boneIdx >= 0) {
            int cachedTime = ((FxBoltFrame *)boltFrame)->cachedServerTime;
            int clTime = ((clientActive_t *)(*(void **)imp_cl))->serverTime;
            if (cachedTime != clTime) {
                ((FxBoltFrame *)boltFrame)->cachedServerTime = clTime;
                Bool ok = FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8) /* FxBoltFrame.orientation */ /* FxBoltFrame.orientation */);
                if (!ok) { ((FxBoltFrame *)boltFrame)->mBolt.dobjHandle = -1; ((FxBoltFrame *)boltFrame)->mBolt.boneIndex = -1; }
            }
            if (((FxBoltFrame *)boltFrame)->mBolt.dobjHandle >= 0)
                orient = boltFrame + 8;
        }
    }

    /* Update origin */
    if (!Particle_UpdateOrigin(_this, (const orientation_t *)orient))
        return 0;

    /* If has bolt, transform to world space */
    if (orient) {
        vec3_t worldPos;
        OrientationPosToWorldPos(orient, (vec_t *)(self + 4), worldPos);
        ((Effect *)self)->worldOrigin[0] = worldPos[0];
        ((Effect *)self)->worldOrigin[1] = worldPos[1];
        ((Effect *)self)->worldOrigin[2] = worldPos[2];
    } else {
        ((Effect *)self)->worldOrigin[0] = *(float *)&((Effect *)self)->mRefEnt.customMaterial /* localOrigin[0] */;
        ((Effect *)self)->worldOrigin[1] = ((Effect *)self)->mRefEnt.rotation /* localOrigin[1] */;
        ((Effect *)self)->worldOrigin[2] = ((Effect *)self)->mRefEnt.axis[0][0] /* localOrigin[2] */;
    }

    /* Evaluate radius (1-component curve with blend) */
    float radius;
    if (*(short *)&((Effect *)self)->mFlags < 0) {
        /* Blend path */
        float blendFactor = ((Particle *)self)->blendWeight[2];
        float v0 = EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime);
        float v1 = EvalCurve1((byte *)&((Particle *)self)->sizeRandChannelInstance, normTime);
        radius = (v0 + (v1 - v0) * blendFactor) * ((Particle *)self)->sizeChannelInstance.scale;
    } else {
        radius = EvalCurve1((byte *)&((Particle *)self)->sizeChannelInstance, normTime) * ((Particle *)self)->sizeChannelInstance.scale;
    }
    ((Effect *)self)->worldRadius[0] = radius;

    if (radius == 0.0f) {
        ((Effect *)self)->mFlags |= 0x01000000; /* mark for removal */
        return 1;
    }

    /* Check sequence params */
    if (((Particle *)self)->nonUniformScale) {
        if (((byte *)&((Effect *)self)->mFlags)[2] & 1) {
            /* TODO: evaluate rotation curve — complex, skip for now */
        }
    }

    /* Evaluate rotation */
    float rotation;
    if (((byte *)&((Effect *)self)->mFlags)[2] & 1) {
        rotation = EvalCurve1((byte *)&((Particle *)self)->size2ChannelInstance, normTime) * ((Particle *)self)->size2ChannelInstance.scale;
    } else {
        rotation = 0.0f;
    }
    ((Effect *)self)->worldRadius[1] = rotation;

    /* Update RGB and Alpha */
    Particle_UpdateRGB(_this);
    Particle_UpdateAlpha(_this);

    return 1;
}

/* Effect_Archive — serialize all Effect base fields */
extern void FxArchive_ArchiveEffect(void *arch, void *effectPtr);
extern void FxArchive_ArchiveMaterial(void *arch, void *materialPtr);
extern void FxArchive_ArchiveModel(void *arch, void *modelPtr);
extern void FxArchive_ArchiveFxGfxEntity(void *arch, void *entityPtr);
extern void FX_SetSortGroup(void *effect);
extern int FX_GetCluster(const vec_t *origin);

static void ArchiveInt(void *arch, byte *self, int offset)
{
    byte *a = (byte *)arch;
    if (((FxArchive *)a)->isReading) { /* isReading */
        int v; FxArchive_ReadData(arch, &v, 4); *(int *)(self + offset) = v;
    } else {
        int v = *(int *)(self + offset); FxArchive_WriteData(arch, &v, 4);
    }
}
static void ArchiveVec3(void *arch, byte *self, int offset)
{
    byte *a = (byte *)arch;
    if (((FxArchive *)a)->isReading) {
        FxArchive_ReadData(arch, self + offset, 0xc);
    } else {
        float f;
        f = *(float *)(self + offset); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + offset + 4); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + offset + 8); FxArchive_WriteData(arch, &f, 4);
    }
}

void Effect_Archive(const Effect *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;

    ArchiveVec3(arch, self, 0x04);    /* origin */
    ArchiveInt(arch, self, 0xb8);     /* startTime */
    ArchiveInt(arch, self, 0xbc);     /* killTime */
    ArchiveInt(arch, self, 0xa8);     /* flags */
    ArchiveInt(arch, self, 0x10);     /* field_0x10 */
    ArchiveVec3(arch, self, 0x14);    /* axis row 0 */
    ArchiveVec3(arch, self, 0x20);    /* axis row 1 */
    FxArchive_ArchiveEffect(arch, self + 0x2c);  /* deathEffect */
    FxArchive_ArchiveEffect(arch, self + 0x30);  /* emitEffect */
    FxArchive_ArchiveFxGfxEntity(arch, self + 0x40); /* gfxEntity */
    FxArchive_ArchiveEffect(arch, self + 0x34);  /* impactEffect */
    ArchiveInt(arch, self, 0x38);     /* field_0x38 */
    FxArchive_ArchiveMaterial(arch, self + 0x40); /* material (uses same offset as gfxEntity — shared union?) */
    FxArchive_ArchiveModel(arch, self + 0xb4);   /* model */
    FxBoltFramePtr_Archive(&((Effect *)self)->mBolt, arch);   /* boltFrame */

    if (((FxArchive *)a)->isReading) { /* isReading: post-load setup */
        ((Effect *)self)->mClusterId = FX_GetCluster((vec_t *)((Effect *)self)->worldOrigin);
        FX_SetSortGroup(self);
    }
}

/* Light_Archive — Effect_Archive + 4 channels + 2 floats (0xc4, 0xc8) */
void Light_Archive(const Light *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;
    Effect_Archive((const Effect *)_this, arch);
    FxArchive_ArchiveChannelInstance(arch, &((Light *)self)->colorChannelInstance);
    FxArchive_ArchiveChannelInstance(arch, &((Light *)self)->colorRandChannelInstance);
    FxArchive_ArchiveChannelInstance(arch, &((Light *)self)->sizeChannelInstance);
    FxArchive_ArchiveChannelInstance(arch, &((Light *)self)->sizeRandChannelInstance);
    /* Light.colorBlendFactor at 0xc4 */
    if (((FxArchive *)a)->isReading) { float f; FxArchive_ReadData(arch, &f, 4); ((Light *)self)->colorBlendFactor = f; }
    else { float f = ((Light *)self)->colorBlendFactor; FxArchive_WriteData(arch, &f, 4); }
    /* Light.sizeBlendFactor at 0xc8 */
    if (((FxArchive *)a)->isReading) { float f; FxArchive_ReadData(arch, &f, 4); ((Light *)self)->sizeBlendFactor = f; }
    else { float f = ((Light *)self)->sizeBlendFactor; FxArchive_WriteData(arch, &f, 4); }
}

/* line 2311 */

void Flash_Archive(const Flash * _this, FxArchive *arch)
{
    Light_Archive((const Light *)_this, arch);
}

/* Particle_Archive — Effect_Archive + 13 int/float fields + 22 ChannelInstances */
void Particle_Archive(const Particle *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    Effect_Archive((const Effect *)_this, arch);
    /* Archive individual fields */
    static const int intOffsets[] = {
        0x100, 0x104, 0x108, 0x10c, 0x110, 0x114, 0x118, 0x11c,
        0x120, 0x124, 0x128, 0x12c, 0x138, -1
    };
    int i;
    for (i = 0; intOffsets[i] >= 0; i++)
        ArchiveInt(arch, self, intOffsets[i]);
    /* Archive 22 ChannelInstances */
    static const int chOffsets[] = {
        0x144, 0x150, 0x15c, 0x168, 0x174, 0x180, 0x18c, 0x198,
        0x1a4, 0x1b0, 0x1bc /* velocityXCI */, 0x1c8 /* velocityYCI */, 0x1d4 /* velocityZCI */, 0x1e0 /* velocityXRandCI */, 0x1ec /* velocityYRandCI */, 0x1f8 /* velocityZRandCI */,
        0x204, 0x210 /* velocity2YCI */, 0x21c /* velocity2ZCI */, 0x228 /* velocity2XRandCI */, 0x234 /* velocity2YRandCI */, 0x240 /* velocity2ZRandCI */, -1
    };
    for (i = 0; chOffsets[i] >= 0; i++)
        FxArchive_ArchiveChannelInstance(arch, self + chOffsets[i]);
}

/* OrientedParticle_Archive — serialize normal vec3 at offset 0x24c */
extern void FxArchive_ReadData(void *arch, void *data, int size);
extern void FxArchive_WriteData(void *arch, void *data, int size);
void OrientedParticle_Archive(const OrientedParticle *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;
    Particle_Archive((const Particle *)_this, arch);
    if (((FxArchive *)a)->isReading) { /* isReading */
        FxArchive_ReadData(arch, self + 0x24c, 0xc);
    } else {
        float f;
        f = ((OrientedParticle *)self)->normal[0]; FxArchive_WriteData(arch, &f, 4);
        f = ((OrientedParticle *)self)->normal[1]; FxArchive_WriteData(arch, &f, 4);
        f = ((OrientedParticle *)self)->normal[2]; FxArchive_WriteData(arch, &f, 4);
    }
}

/* Cloud_Archive — serialize vec3, 2 channel instances, float, byte */
void Cloud_Archive(const Cloud *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;
    Particle_Archive((const Particle *)_this, arch);
    /* Vec3 at 0x24c */
    if (((FxArchive *)a)->isReading) {
        FxArchive_ReadData(arch, self + 0x24c, 0xc);
    } else {
        float f;
        f = *(float *)&((Cloud *)self)->useLength; FxArchive_WriteData(arch, &f, 4); /* useLength as 4-byte word */
        f = ((Cloud *)self)->randomLengthWeight; FxArchive_WriteData(arch, &f, 4);
        f = ((Cloud *)self)->_unk_0x254; FxArchive_WriteData(arch, &f, 4);
    }
    /* Two ChannelInstances */
    FxArchive_ArchiveChannelInstance(arch, &((Cloud *)self)->lengthChannelInstance);
    FxArchive_ArchiveChannelInstance(arch, &((Cloud *)self)->lengthRandChannelInstance);
    /* Cloud.randomLengthBlend at 0x260 */
    if (((FxArchive *)a)->isReading) {
        float f; FxArchive_ReadData(arch, &f, 4); ((Cloud *)self)->randomLengthBlend = f;
    } else {
        float f = ((Cloud *)self)->randomLengthBlend; FxArchive_WriteData(arch, &f, 4);
    }
    /* Cloud.lengthBlendFactor at 0x25c (archived as 1 byte — only low byte used) */
    if (((FxArchive *)a)->isReading) {
        byte b; FxArchive_ReadData(arch, &b, 1); *(byte *)&((Cloud *)self)->lengthBlendFactor = b;
    } else {
        byte b = *(byte *)&((Cloud *)self)->lengthBlendFactor; FxArchive_WriteData(arch, &b, 1);
    }
}

/* Line_Archive — serialize normal vec3 at offset 0x24c (same as OrientedParticle) */
void Line_Archive(const Line *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;
    Particle_Archive((const Particle *)_this, arch);
    if (((FxArchive *)a)->isReading) {
        FxArchive_ReadData(arch, self + 0x24c, 0xc);
    } else {
        float f;
        f = ((Line *)self)->endpoint[0]; FxArchive_WriteData(arch, &f, 4);
        f = ((Line *)self)->endpoint[1]; FxArchive_WriteData(arch, &f, 4);
        f = ((Line *)self)->endpoint[2]; FxArchive_WriteData(arch, &f, 4);
    }
}

/* Tail_Archive — serialize vec3 at 0x24c, two ChannelInstances, float at 0x25c */
extern void FxArchive_ArchiveChannelInstance(void *arch, void *channelInst);
void Tail_Archive(const Tail *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;
    Particle_Archive((const Particle *)_this, arch);
    /* Vec3 at 0x24c */
    if (((FxArchive *)a)->isReading) {
        FxArchive_ReadData(arch, self + 0x24c, 0xc);
    } else {
        float f;
        f = ((Tail *)self)->endpoint[0]; FxArchive_WriteData(arch, &f, 4);
        f = ((Tail *)self)->endpoint[1]; FxArchive_WriteData(arch, &f, 4);
        f = ((Tail *)self)->endpoint[2]; FxArchive_WriteData(arch, &f, 4);
    }
    /* Two ChannelInstances */
    FxArchive_ArchiveChannelInstance(arch, &((Tail *)self)->lengthChannelInstance);
    FxArchive_ArchiveChannelInstance(arch, &((Tail *)self)->lengthRandChannelInstance);
    /* Float at 0x25c */
    if (((FxArchive *)a)->isReading) {
        float f; FxArchive_ReadData(arch, &f, 4); ((Tail *)self)->lengthBlendFactor = f;
    } else {
        float f = ((Tail *)self)->lengthBlendFactor; FxArchive_WriteData(arch, &f, 4);
    }
}

/* line 1794 */

void Cylinder_Archive(const Cylinder * _this, FxArchive *arch)
{
    Tail_Archive((const Tail *)_this, arch);
}

/* Emitter_Archive — Particle_Archive + 3 vec3s + several ints + effect ref + model ref + flags */
void Emitter_Archive(const Emitter *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    Particle_Archive((const Particle *)_this, arch);
    ArchiveVec3(arch, self, 0x24c);   /* emitter axis[0] or position */
    ArchiveVec3(arch, self, 0x258);   /* emitter axis[1] */
    ArchiveVec3(arch, self, 0x264);   /* emitter axis[2] */
    ArchiveInt(arch, self, 0x270);
    ArchiveInt(arch, self, 0x274);
    ArchiveInt(arch, self, 0x278);
    ArchiveInt(arch, self, 0xa8);     /* flags */
    FxArchive_ArchiveEffect(arch, self + 0x284);  /* emit effect template */
    ArchiveInt(arch, self, 0x290);
    ArchiveInt(arch, self, 0x294);
    ArchiveInt(arch, self, 0x298);
    ArchiveInt(arch, self, 0xb4);
}

/* line 1732 */
/* Cylinder D0 destructor — cleanup bolt frame + delete this */
void ZN8CylinderD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN8CylinderD0Ev(void) /* Cylinder_~Cylinder */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1732 */
/* Cylinder D1 destructor — cleanup bolt frame */
void ZN8CylinderD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN8CylinderD1Ev(void) /* Cylinder_~Cylinder */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1727 */
void Cylinder_Cylinder(const Cylinder * _this)
{
    extern void *__ZTV8Cylinder;
    Particle_Particle((const Particle *)_this);
    *(int *)_this = (int)&__ZTV8Cylinder + 8;
}

/* line 1260 */
void OrientedParticle_OrientedParticle(const OrientedParticle * _this)
{
    extern void *__ZTV16OrientedParticle;
    Particle_Particle((const Particle *)_this);
    *(int *)_this = (int)&__ZTV16OrientedParticle + 8;
}

/* line 1265 */
/* OrientedParticle D1 destructor — cleanup bolt frame */
void ZN16OrientedParticleD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN16OrientedParticleD1Ev(void) /* OrientedParticle_~OrientedParticle */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1265 */
/* OrientedParticle D0 destructor — cleanup bolt frame + delete this */
void ZN16OrientedParticleD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN16OrientedParticleD0Ev(void) /* OrientedParticle_~OrientedParticle */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1341 */
void Cloud_Cloud(const Cloud * _this, const Cloud * _this_1)
{
    extern void *__ZTV5Cloud;
    extern float flrand(float min, float max);
    byte *p = (byte *)_this;
    int i;
    (void)_this_1;
    Particle_Particle((const Particle *)_this);
    *(int *)p = (int)&__ZTV5Cloud + 8;
    for (i = 0; i < 3; i++) {
        ((float *)&((Cloud *)p)->useLength)[i] = flrand(-1.0f, 1.0f);
    }
}

/* line 1347 */
/* Cloud D1 destructor — cleanup bolt frame */
void ZN5CloudD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN5CloudD1Ev(void) /* Cloud_~Cloud */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1347 */
/* Cloud D0 destructor — cleanup bolt frame + delete this */
void ZN5CloudD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN5CloudD0Ev(void) /* Cloud_~Cloud */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1499 */
void Line_Line(const Line * _this)
{
    extern void *__ZTV4Line;
    Particle_Particle((const Particle *)_this);
    *(int *)_this = (int)&__ZTV4Line + 8;
}

/* line 1504 */
/* Line D1 destructor — cleanup bolt frame */
void ZN4LineD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN4LineD1Ev(void) /* Line_~Line */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1504 */
/* Line D0 destructor — cleanup bolt frame + delete this */
void ZN4LineD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN4LineD0Ev(void) /* Line_~Line */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1579 */
void Tail_Tail(const Tail * _this)
{
    extern void *__ZTV4Tail;
    Particle_Particle((const Particle *)_this);
    *(int *)_this = (int)&__ZTV4Tail + 8;
}

/* line 1584 */
/* Tail D1 destructor — cleanup bolt frame */
void ZN4TailD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN4TailD1Ev(void) /* Tail_~Tail */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1584 */
/* Tail D0 destructor — cleanup bolt frame + delete this */
void ZN4TailD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN4TailD0Ev(void) /* Tail_~Tail */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1804 */
void Emitter_Emitter(const Emitter * _this)
{
    extern void *__ZTV7Emitter;
    Particle_Particle((const Particle *)_this);
    *(int *)_this = (int)&__ZTV7Emitter + 8;
}

/* line 1809 */
/* Emitter D1 destructor — cleanup bolt frame */
void ZN7EmitterD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN7EmitterD1Ev(void) /* Emitter_~Emitter */
{
    /* naked trampoline — not callable under WASM */
}

/* line 1809 */
/* Emitter D0 destructor — cleanup bolt frame + delete this */
void ZN7EmitterD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN7EmitterD0Ev(void) /* Emitter_~Emitter */
{
    /* naked trampoline — not callable under WASM */
}

/* line 186 */
float Effect_GetVisibility(const Effect * _this, const vec_t *start, const vec_t *dir, float halfLen)
{
    return 1.0f;
}

/* line 189 */
void Effect_AddVisibility(const Effect * _this)
{
}

/* line 284 */
Bool Flash_Cull(const Flash * _this)
{
    return 0;
}

/* line 282 */
/* Flash D0 destructor — cleanup bolt frame + delete this */
void ZN5FlashD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
    if (self) __ZdaPv(self);
}
void ZN5FlashD0Ev(void) /* Flash_~Flash */
{
    /* naked trampoline — not callable under WASM */
}

/* line 282 */
/* Flash D1 destructor — cleanup bolt frame */
void ZN5FlashD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper((byte *)((Effect *)self)->mBolt.value);
}
void ZN5FlashD1Ev(void) /* Flash_~Flash */
{
    /* naked trampoline — not callable under WASM */
}
