/* ASM dump from: FxPrimitives.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxPrimitives.cpp */

#include "common_types.h"
#include "imports.h"

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
    int refCount = *(int *)boltFrame - 1;
    *(int *)boltFrame = refCount;
    if (refCount != 0) return;
    /* Remove from g_mFrameList linked list */
    byte **prevNext = &__ZN11FxBoltFrame12g_mFrameListE;
    byte *cur = *prevNext;
    while (cur) {
        if (cur == boltFrame) {
            *prevNext = *(byte **)(boltFrame + 0x38);
            break;
        }
        prevNext = (byte **)(cur + 0x38);
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
    byte *p = (byte *)_this;
    byte *cl_ptr;
    int serverTime;
    orientation_t *orient = (orientation_t *)(p + 8);

    /* line 90: if bone index < 0, return NULL */
    if (*(int *)(p + 0x3c) < 0)
        return (const orientation_t *)0;

    /* line 94: check if server time changed */
    cl_ptr = *(byte **)imp_cl;
    serverTime = *(int *)(cl_ptr + 0x864c);
    if (serverTime != *(int *)(p + 4)) {
        /* line 96: update cached time */
        *(int *)(p + 4) = serverTime;
        /* line 102: try to get bone orientation */
        if (!FX_GetBoneOrientation((int *)(p + 0x3c), orient)) {
            /* line 105-106: invalidate */
            *(int *)(p + 0x3c) = -1;
            *(int *)(p + 0x40) = -1;
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
    *(int *)((byte *)_this + 0xb8) = start;
    *(int *)((byte *)_this + 0xbc) = end;
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
    FxCurveIterator_Create(c, *(void **)m);
    /* line 474: get random value from master's range (at offset 4) */
    *(float *)(c + 8) = FxRange_GetVal((void *)(m + 4));
}

/* line 478 */
void Particle_CreateChannelInstances(const Particle * _this, const PrimitiveTemplate *primTemp)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemp;
    FxChannelInstance_Create((const FxChannel *)(p + 0x100), (FxChannelInstance *)(t + 0x144)); /* line 482 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x10c), (FxChannelInstance *)(t + 0x150)); /* line 483 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x118), (FxChannelInstance *)(t + 0x15c)); /* line 484 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x124), (FxChannelInstance *)(t + 0x168)); /* line 485 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x130), (FxChannelInstance *)(t + 0x174)); /* line 486 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x13c), (FxChannelInstance *)(t + 0x180)); /* line 487 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x148), (FxChannelInstance *)(t + 0x18c)); /* line 488 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x154), (FxChannelInstance *)(t + 0x198)); /* line 489 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x178), (FxChannelInstance *)(t + 0x1a4)); /* line 490 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x184), (FxChannelInstance *)(t + 0x1b0)); /* line 491 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x190), (FxChannelInstance *)(t + 0x1bc)); /* line 493 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x19c), (FxChannelInstance *)(t + 0x1c8)); /* line 494 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x1a8), (FxChannelInstance *)(t + 0x1d4)); /* line 495 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x1b4), (FxChannelInstance *)(t + 0x1e0)); /* line 496 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x1c0), (FxChannelInstance *)(t + 0x1ec)); /* line 497 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x1cc), (FxChannelInstance *)(t + 0x1f8)); /* line 498 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x1d8), (FxChannelInstance *)(t + 0x204)); /* line 500 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x1e4), (FxChannelInstance *)(t + 0x210)); /* line 501 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x1f0), (FxChannelInstance *)(t + 0x21c)); /* line 502 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x1fc), (FxChannelInstance *)(t + 0x228)); /* line 503 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x208), (FxChannelInstance *)(t + 0x234)); /* line 504 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x214), (FxChannelInstance *)(t + 0x240)); /* line 505 */
}

/* line 522 */
void Particle_SetRandomVelocity2Weights(const Particle * _this, float weight1, float weight2, float weight3)
{
    *(float *)((byte *)_this + 0x138) = weight1;
    *(float *)((byte *)_this + 0x13c) = weight2;
    *(float *)((byte *)_this + 0x140) = weight3;
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
    FxChannelInstance_Create((const FxChannel *)(p + 0x160), (FxChannelInstance *)(t + 0x264)); /* line 1401 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x16c), (FxChannelInstance *)(t + 0x270)); /* line 1402 */
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
    FxChannelInstance_Create((const FxChannel *)(p + 0x160), (FxChannelInstance *)(t + 0x260)); /* line 1608 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x16c), (FxChannelInstance *)(t + 0x26c)); /* line 1609 */
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
    FxChannelInstance_Create((const FxChannel *)(p + 0x100), (FxChannelInstance *)(t + 0xcc)); /* line 2145 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x10c), (FxChannelInstance *)(t + 0xd8)); /* line 2146 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x130), (FxChannelInstance *)(t + 0xe4)); /* line 2147 */
    FxChannelInstance_Create((const FxChannel *)(p + 0x13c), (FxChannelInstance *)(t + 0xf0)); /* line 2148 */
}

/* line 2158 */
extern void FxHelper_AddLightToScene(void *helper, float *origin, float radius, float r, float g, float b);
void Light_Draw(const Light * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    /* line 2160: args are helper, origin(0x7c), radius(0x88), rgb(0x6c,0x70,0x74) */
    FxHelper_AddLightToScene(helper,
        (float *)(p + 0x7c),
        *(float *)(p + 0x88),
        *(float *)(p + 0x6c),
        *(float *)(p + 0x70),
        *(float *)(p + 0x74));
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
    byte *helper = *(byte **)imp_theFxHelper;
    float dif[3];
    float dist, dot, falloff;
    float *camOrigin, *camDir;

    /* line 2266: dif = this->origin - camera origin */
    camOrigin = (float *)(helper + 0x14);
    dif[0] = *(float *)(p + 4) - camOrigin[0];
    dif[1] = *(float *)(p + 8) - camOrigin[1];
    dif[2] = *(float *)(p + 0xc) - camOrigin[2];

    /* line 2270: normalize dif, get distance */
    dist = Vec3Normalize(dif);

    /* dot product with camera direction */
    camDir = (float *)(helper + 0x20);
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

    /* Apply to flash intensity at offset 0xd4 */
    *(float *)(p + 0xd4) *= dot;
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
    byte *p = (byte *)_this;
    int *countPtr = *(int **)imp_g_effectVisArrayCount;
    byte *visArray = *(byte **)imp_g_effectVisArray;
    int idx = *countPtr;
    byte *entry = visArray + idx * 20; /* 5 floats = 20 bytes per entry */
    float radius, alpha;

    /* line 571: increment count */
    *countPtr = idx + 1;

    /* line 573: copy origin vec3 */
    *(int *)(entry + 0) = *(int *)(p + 0x7c);
    *(int *)(entry + 4) = *(int *)(p + 0x80);
    *(int *)(entry + 8) = *(int *)(p + 0x84);

    /* line 574: radius squared */
    radius = *(float *)(p + 0x88);
    *(float *)(entry + 12) = radius * radius;

    /* line 575: visibility from alpha byte */
    alpha = (float)(*(unsigned char *)(p + 0x93));
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
    *(int *)(ent + 0x00) = reType;                       /* ent.reType */
    *(int *)(ent + 0x54) = *(int *)(effect + 0x40);      /* ent.hModel (material) */
    *(int *)(ent + 0x6c) = *(int *)(effect + 0x44);      /* ent.customShader */
    AxisCopy((vec_t *)(effect + 0x48), (vec_t *)(ent + 0x14)); /* ent.axis */
    /* Copy origin */
    *(float *)(ent + 0x3c) = *(float *)(effect + 0x7c);
    *(float *)(ent + 0x40) = *(float *)(effect + 0x80);
    *(float *)(ent + 0x44) = *(float *)(effect + 0x84);
    /* Copy additional fields */
    *(int *)(ent + 0x64) = *(int *)(effect + 0x88);      /* radius */
    *(int *)(ent + 0x68) = *(int *)(effect + 0x8c);      /* rotation */
    *(byte *)(ent + 0x58) = *(byte *)(effect + 0x90);     /* shaderRGBA[0] */
    *(byte *)(ent + 0x59) = *(byte *)(effect + 0x91);     /* shaderRGBA[1] */
    *(byte *)(ent + 0x5a) = *(byte *)(effect + 0x92);     /* shaderRGBA[2] */
    *(byte *)(ent + 0x5b) = *(byte *)(effect + 0x93);     /* shaderRGBA[3] */
    *(int *)(ent + 0x60) = *(int *)(effect + 0x94);       /* shaderTexCoord */
    *(int *)(ent + 0x38) = *(int *)(effect + 0x98);       /* frame */
    /* Copy oldorigin */
    *(float *)(ent + 0x48) = *(float *)(effect + 0x9c);
    *(float *)(ent + 0x4c) = *(float *)(effect + 0xa0);
    *(float *)(ent + 0x50) = *(float *)(effect + 0xa4);
    /* Flags */
    int flags = *(int *)(effect + 0xa8);
    if (flags & 1) *(int *)(ent + 0x04) |= 8;
    if (flags & 0x4000000) *(int *)(ent + 0x04) |= 0x80;
    FxHelper_AddFxToScene(*(void **)imp_theFxHelper, ent, *(int *)(effect + 0xb4));
}
static __attribute__((naked))
void FX_AddFxToScene(void)
{
    __asm__ __volatile__ (
        "pushl %edx\n"
        "pushl %eax\n"
        "calll FX_AddFxToScene_impl\n"
        "addl $8, %esp\n"
        "retl\n"
    );
}

/* line 1820 */
void Emitter_Draw(const Emitter * _this)
{
    byte *p = (byte *)_this;
    /* line 1823: if not (flags & 0x10), return */
    if (!(*(int *)(p + 0xa8) & 0x10))
        return;
    /* line 1827: if alpha == 0, return */
    if (*(float *)(p + 0x98) == 0.0f)
        return;
    /* FX_AddFxToScene(this, 1) via register convention */
    __asm__ __volatile__ (
        "movl %0, %%eax\n"
        "movl $1, %%edx\n"
        "calll FX_AddFxToScene\n"
        : : "g"(p) : "eax", "ecx", "edx", "memory"
    );
}

/* line 1743 */
void Cylinder_Draw(const Cylinder * _this)
{
    /* FX_AddFxToScene uses register convention: eax=this, edx=reType */
    __asm__ __volatile__ (
        "movl %0, %%eax\n"
        "movl $9, %%edx\n"
        "calll FX_AddFxToScene\n"
        : : "g"(_this) : "eax", "ecx", "edx", "memory"
    );
}

/* line 1613 */
void Tail_Draw(const Tail * _this)
{
    __asm__ __volatile__ (
        "movl %0, %%eax\n"
        "movl $8, %%edx\n"
        "calll FX_AddFxToScene\n"
        : : "g"(_this) : "eax", "ecx", "edx", "memory"
    );
}

/* line 1520 */
void Line_Draw(const Line * _this)
{
    __asm__ __volatile__ (
        "movl %0, %%eax\n"
        "movl $8, %%edx\n"
        "calll FX_AddFxToScene\n"
        : : "g"(_this) : "eax", "ecx", "edx", "memory"
    );
}

/* line 1389 */
void Cloud_Draw(const Cloud * _this)
{
    __asm__ __volatile__ (
        "movl %0, %%eax\n"
        "movl $6, %%edx\n"
        "calll FX_AddFxToScene\n"
        : : "g"(_this) : "eax", "ecx", "edx", "memory"
    );
}

/* line 1276 */
void OrientedParticle_Draw(const OrientedParticle * _this)
{
    __asm__ __volatile__ (
        "movl %0, %%eax\n"
        "movl $7, %%edx\n"
        "calll FX_AddFxToScene\n"
        : : "g"(_this) : "eax", "ecx", "edx", "memory"
    );
}

/* line 401 */
void Particle_Draw(const Particle * _this)
{
    byte *p = (byte *)_this;
    float radius = *(float *)(p + 0x88);
    float height = *(float *)(p + 0x8c);
    /* line 403: if both radius and height are zero, skip */
    if (radius == 0.0f && height == 0.0f)
        return;
    __asm__ __volatile__ (
        "movl %0, %%eax\n"
        "movl $4, %%edx\n"
        "calll FX_AddFxToScene\n"
        : : "g"(p) : "eax", "ecx", "edx", "memory"
    );
}

/* line 227 */
Bool Effect_Update(const Effect * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int startTime = *(int *)(p + 0xb8);
    int curTime = *(int *)(helper + 4);
    int endTime;
    float normDuration;

    /* line 232: if start time > current time, not started yet */
    if (startTime > curTime)
        return 0;

    /* line 239: compute normalized duration */
    endTime = *(int *)(p + 0xbc);
    normDuration = (float)(curTime - startTime) / (float)(endTime - startTime);
    *(float *)(p + 0x3c) = normDuration;

    /* line 241: clamp to 1.0 */
    if (normDuration > 1.0f)
        *(float *)(p + 0x3c) = 1.0f;

    /* line 243: clamp to 0.0 */
    if (0.0f > *(float *)(p + 0x3c))
        *(float *)(p + 0x3c) = 0.0f;

    return 1;
}

/* line 395 */
extern unsigned char FxHelper_CullSphere(void *helper, float *origin, float radius, int cullType);
Bool Particle_Cull(const Particle * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = *(int *)(helper + 0x80);
    /* line 220: if flags & 2, cap cull type at 5 */
    if (*(byte *)(p + 0xab) & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    return (Bool)FxHelper_CullSphere(helper, (float *)(p + 0x7c), *(float *)(p + 0x88), cullType);
}

/* line 1270 */
Bool OrientedParticle_Cull(const OrientedParticle * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = *(int *)(helper + 0x80);
    if (*(byte *)(p + 0xab) & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    return (Bool)FxHelper_CullSphere(helper, (float *)(p + 0x7c), *(float *)(p + 0x88), cullType);
}

/* line 1357 */
Bool Cloud_Cull(const Cloud * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = *(int *)(helper + 0x80);
    float halfLen, height, radius, cullRadius;

    if (*(byte *)(p + 0xab) & 2) {
        if (cullType >= 5)
            cullType = 5;
    }

    /* line 1359: compute cull radius = max(radius, height) + halfLen */
    halfLen = *(float *)(p + 0x98);
    height = *(float *)(p + 0x8c);
    radius = *(float *)(p + 0x88);
    cullRadius = (radius - height < 0.0f ? height : radius) + halfLen;

    return (Bool)FxHelper_CullSphere(helper, (float *)(p + 0x7c), cullRadius, cullType);
}

/* line 1514 */
extern unsigned char FxHelper_CullCylinder(void *helper, float *origin1, float *origin2, float radius1, float radius2, int cullType);
Bool Line_Cull(const Line * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = *(int *)(helper + 0x80);
    float radius;
    if (*(byte *)(p + 0xab) & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    radius = *(float *)(p + 0x88);
    return (Bool)FxHelper_CullCylinder(helper, (float *)(p + 0x7c), (float *)(p + 0x9c), radius, radius, cullType);
}

/* line 1596 */
Bool Tail_Cull(const Tail * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = *(int *)(helper + 0x80);
    float radius;
    if (*(byte *)(p + 0xab) & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    radius = *(float *)(p + 0x88);
    return (Bool)FxHelper_CullCylinder(helper, (float *)(p + 0x7c), (float *)(p + 0x9c), radius, radius, cullType);
}

/* line 1737 */
Bool Cylinder_Cull(const Cylinder * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = *(int *)(helper + 0x80);
    if (*(byte *)(p + 0xab) & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    return (Bool)FxHelper_CullCylinder(helper, (float *)(p + 0x7c), (float *)(p + 0x9c),
        *(float *)(p + 0x88), *(float *)(p + 0x8c), cullType);
}

/* line 2152 */
Bool Light_Cull(const Light * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int cullType = *(int *)(helper + 0x80);
    if (*(byte *)(p + 0xab) & 2) {
        if (cullType >= 5)
            cullType = 5;
    }
    return (Bool)FxHelper_CullSphere(helper, (float *)(p + 0x7c), *(float *)(p + 0x88), cullType);
}

/* line 509 */
void Particle_SetRandomVelocityWeights(const Particle * _this, float weight1, float weight2, float weight3)
{
    *(float *)((byte *)_this + 0x12c) = weight1;
    *(float *)((byte *)_this + 0x130) = weight2;
    *(float *)((byte *)_this + 0x134) = weight3;
}

/* line 535 */
extern float Vec3DistanceSq(float *a, float *b);
float Particle_GetVisibility(const Particle * _this, const vec_t *start, const vec_t *dir, float halfLen)
{
    byte *p = (byte *)_this;
    float *origin = (float *)(p + 0x7c);
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
    radiusSq = *(float *)(p + 0x88);
    radiusSq *= radiusSq;
    if (radiusSq <= distSq)
        return 1.0f;

    /* line 555: return alpha-based visibility */
    return (float)(*(unsigned char *)(p + 0x93)) * (-0.003921568859368563f) + 1.0f;
}

/* line 1225 */
void Particle_FixupArchiveLoad(const Particle * _this, const PrimitiveTemplate *primTemplate)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemplate;
    *(int *)(t + 0x144) = *(int *)(p + 0x100); /* line 1231 */
    *(int *)(t + 0x150) = *(int *)(p + 0x10c); /* line 1232 */
    *(int *)(t + 0x15c) = *(int *)(p + 0x118); /* line 1233 */
    *(int *)(t + 0x168) = *(int *)(p + 0x124); /* line 1234 */
    *(int *)(t + 0x174) = *(int *)(p + 0x130); /* line 1235 */
    *(int *)(t + 0x180) = *(int *)(p + 0x13c); /* line 1236 */
    *(int *)(t + 0x18c) = *(int *)(p + 0x148); /* line 1237 */
    *(int *)(t + 0x198) = *(int *)(p + 0x154); /* line 1238 */
    *(int *)(t + 0x1a4) = *(int *)(p + 0x178); /* line 1239 */
    *(int *)(t + 0x1b0) = *(int *)(p + 0x184); /* line 1240 */
    *(int *)(t + 0x1bc) = *(int *)(p + 0x190); /* line 1242 */
    *(int *)(t + 0x1c8) = *(int *)(p + 0x19c); /* line 1243 */
    *(int *)(t + 0x1d4) = *(int *)(p + 0x1a8); /* line 1244 */
    *(int *)(t + 0x1e0) = *(int *)(p + 0x1b4); /* line 1245 */
    *(int *)(t + 0x1ec) = *(int *)(p + 0x1c0); /* line 1246 */
    *(int *)(t + 0x1f8) = *(int *)(p + 0x1cc); /* line 1247 */
    *(int *)(t + 0x204) = *(int *)(p + 0x1d8); /* line 1249 */
    *(int *)(t + 0x210) = *(int *)(p + 0x1e4); /* line 1250 */
    *(int *)(t + 0x21c) = *(int *)(p + 0x1f0); /* line 1251 */
    *(int *)(t + 0x228) = *(int *)(p + 0x1fc); /* line 1252 */
    *(int *)(t + 0x234) = *(int *)(p + 0x208); /* line 1253 */
    *(int *)(t + 0x240) = *(int *)(p + 0x214); /* line 1254 */
}

/* line 2236 */
void Light_FixupArchiveLoad(const Light * _this, const PrimitiveTemplate *primTemplate)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemplate;
    *(int *)(t + 0xcc) = *(int *)(p + 0x100); /* line 2242 */
    *(int *)(t + 0xd8) = *(int *)(p + 0x10c); /* line 2243 */
    *(int *)(t + 0xe4) = *(int *)(p + 0x130); /* line 2244 */
    *(int *)(t + 0xf0) = *(int *)(p + 0x13c); /* line 2245 */
}

/* line 456 */
void Particle_SetAxis(const Particle * _this, vec3_t *ax)
{
    byte *p = (byte *)_this;
    float *src = (float *)ax;

    /* line 462: axis[0] at offset 0xd0 */
    if (ax) {
        *(float *)(p + 0xd0) = src[0];
        *(float *)(p + 0xd4) = src[1];
        *(float *)(p + 0xd8) = src[2];
    } else {
        *(float *)(p + 0xd0) = 0.0f;
        *(float *)(p + 0xd4) = 0.0f;
        *(float *)(p + 0xd8) = 0.0f;
    }

    /* line 463: axis[1] at offset 0xdc */
    if (ax) {
        *(float *)(p + 0xdc) = src[3];
        *(float *)(p + 0xe0) = src[4];
        *(float *)(p + 0xe4) = src[5];
    } else {
        *(float *)(p + 0xdc) = 0.0f;
        *(float *)(p + 0xe0) = 0.0f;
        *(float *)(p + 0xe4) = 0.0f;
    }

    /* line 464: axis[2] at offset 0xe8 */
    if (ax) {
        *(float *)(p + 0xe8) = src[6];
        *(float *)(p + 0xec) = src[7];
        *(float *)(p + 0xf0) = src[8];
    } else {
        *(float *)(p + 0xe8) = 0.0f;
        *(float *)(p + 0xec) = 0.0f;
        *(float *)(p + 0xf0) = 0.0f;
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

    /* Evaluate 3 color channels from offsets 0x6c/0x70/0x74, clamp [0,1] */
    float color[4];
    int i;
    for (i = 0; i < 3; i++) {
        float v = *(float *)(self + 0x6c + i * 4);
        if (v < 0.0f) v = 0.0f;
        if (v > 1.0f) v = 1.0f;
        color[i] = v;
    }
    color[3] = 1.0f; /* alpha */

    /* Convert to RGBA bytes at offset 0x90 */
    *(byte *)(self + 0x90) = (byte)FloatToByte(color[0]);
    *(byte *)(self + 0x91) = (byte)FloatToByte(color[1]);
    *(byte *)(self + 0x92) = (byte)FloatToByte(color[2]);
    *(byte *)(self + 0x93) = (byte)FloatToByte(color[3]);

    /* Set origin to camera position + forward * 8 */
    byte *helper = *(byte **)imp_theFxHelper;
    *(float *)(self + 0x7c) = *(float *)(helper + 0x14) + *(float *)(helper + 0x20) * 8.0f;
    *(float *)(self + 0x80) = *(float *)(helper + 0x18) + *(float *)(helper + 0x24) * 8.0f;
    *(float *)(self + 0x84) = *(float *)(helper + 0x1c) + *(float *)(helper + 0x28) * 8.0f;

    /* Set radius */
    *(float *)(self + 0x88) = 12.0f;
    *(float *)(self + 0x8c) = 12.0f;

    /* Submit as light entity (reType=4) via register convention */
    FX_AddFxToScene_impl(self, 4);
}
#if 0 /* Original ASM */
__attribute__((naked))
void Flash_Draw_asm(const Flash * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2285 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl %esi, %eax\n" /* this */
        "movl $1, %edx\n"
        "pxor %xmm2, %xmm2\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "leal -0x28(%ebp), %ecx\n" /* color */
        /* { scope 1 */
        ".Lfa1522_000a1544:\n"
        "movss 0x6c(%eax), %xmm0\n" /* line 2291 | x */
        /* { scope 2 */
        "ucomiss %xmm0, %xmm2\n" /* line 406 */
        "ja .Lfa1522_000a1709\n"
        "movaps %xmm1, %xmm3\n" /* line 408 */
        "minss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        ".Lfa1522_000a155c:\n"
        "movss %xmm0, -4(%ecx, %edx, 4)\n" /* line 2291 | x */
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 2290 */
        "jne .Lfa1522_000a1544\n"
        "movl $0x3f800000, -0x1c(%ebp)\n" /* line 2292 */
        "leal 0x90(%esi), %ebx\n" /* line 2293 | this, to */
        /* { scope 2 */
        "movss -0x28(%ebp), %xmm0\n" /* line 428 | color */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x2c(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lfa1522_000a1711\n"
        "movl $0xff, %edx\n"
        /* { scope 3 */
        ".Lfa1522_000a15b3:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfa1522_000a15b5:\n"
        "movb %al, (%ebx)\n" /* line 696 */
        "leal 1(%ebx), %edi\n" /* line 697 */
        "movss -0x24(%ebp), %xmm0\n" /* line 428 */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x30(%ebp)\n"
        "cvttss2si -0x30(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lfa1522_000a174a\n"
        "movl $0xff, %edx\n"
        /* { scope 3 */
        ".Lfa1522_000a15f3:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfa1522_000a15f5:\n"
        "movb %al, (%edi)\n" /* line 697 */
        "leal 2(%ebx), %edi\n" /* line 698 */
        "movss -0x20(%ebp), %xmm0\n" /* line 428 */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x34(%ebp)\n"
        "cvttss2si -0x34(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lfa1522_000a1737\n"
        "movl $0xff, %edx\n"
        /* { scope 3 */
        ".Lfa1522_000a1633:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfa1522_000a1635:\n"
        "movb %al, (%edi)\n" /* line 698 */
        "addl $3, %ebx\n" /* line 699 */
        "movss lit4_002ed5d4, %xmm0\n" /* line 428 | 255.0f */
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x38(%ebp)\n"
        "cvttss2si -0x38(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lfa1522_000a1724\n"
        "movl $0xff, %edx\n"
        /* { scope 3 */
        ".Lfa1522_000a1673:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfa1522_000a1675:\n"
        "movb %al, (%ebx)\n" /* line 699 */
        /* } scope */
        "leal 0x7c(%esi), %ebx\n" /* line 2295 | this, to */
        "movl imp_theFxHelper, %ecx\n"
        "movl (%ecx), %eax\n"
        "leal 0x14(%eax), %edx\n" /* from */
        /* { scope 2 */
        "movl 0x14(%eax), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 0x80(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0x84(%esi)\n"
        "movl (%ecx), %eax\n"
        "leal 0x20(%eax), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movss lit4_002ed740, %xmm1\n" /* line 288 | 8.0f */
        "movss 0x20(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 0x7c(%esi), %xmm0\n"
        "movss %xmm0, 0x7c(%esi)\n"
        "movss 4(%edx), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, 0x80(%esi)\n"
        "mulss 8(%edx), %xmm1\n" /* line 290 */
        "addss 8(%ebx), %xmm1\n"
        "movss %xmm1, 0x84(%esi)\n"
        /* } scope */
        "movl $0x41400000, %eax\n" /* line 2297 */
        "movl %eax, 0x88(%esi)\n" /* this */
        "movl %eax, 0x8c(%esi)\n" /* line 2298 | this */
        "movl $4, %edx\n" /* line 2300 */
        "movl %esi, %eax\n" /* this */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2301 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp FX_AddFxToScene\n" /* line 2300 */
        /* { scope 2 */
        ".Lfa1522_000a1709:\n"
        "movaps %xmm2, %xmm0\n" /* line 406 */
        "jmp .Lfa1522_000a155c\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa1522_000a1711:\n"
        "movl %edx, %eax\n" /* line 154 */
        "negl %eax\n"
        /* { scope 3 */
        "testl %eax, %eax\n"
        "js .Lfa1522_000a15b3\n"
        "xorl %eax, %eax\n"
        "jmp .Lfa1522_000a15b5\n"
        /* } scope */
        ".Lfa1522_000a1724:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 3 */
        "testl %eax, %eax\n"
        "js .Lfa1522_000a1673\n"
        "xorl %eax, %eax\n"
        "jmp .Lfa1522_000a1675\n"
        /* } scope */
        ".Lfa1522_000a1737:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 3 */
        "testl %eax, %eax\n"
        "js .Lfa1522_000a1633\n"
        "xorl %eax, %eax\n"
        "jmp .Lfa1522_000a1635\n"
        /* } scope */
        ".Lfa1522_000a174a:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 3 */
        "testl %eax, %eax\n"
        "js .Lfa1522_000a15f3\n"
        "xorl %eax, %eax\n"
        "jmp .Lfa1522_000a15f5\n"
    );
}
#endif

/* FxBoltFrame_Acquire — find or create bolt frame for bolt info. Returns struct by value via hidden ptr.
 * Hidden return ptr at 8(%ebp), bolt at 0xc(%ebp). Uses retl $4 (struct return convention). */
static void FxBoltFrame_Acquire_impl(byte *retPtr, byte *bolt)
{
    /* Search existing bolt frames for matching entity+bone */
    byte *frame = __ZN11FxBoltFrame12g_mFrameListE;
    int entity = *(int *)bolt;
    int bone = *(int *)(bolt + 4);
    while (frame) {
        if (*(int *)(frame + 0x3c) == entity && *(int *)(frame + 0x40) == bone) {
            *(int *)frame += 1; /* addref */
            *(byte **)retPtr = frame;
            return;
        }
        frame = *(byte **)(frame + 0x38);
    }
    /* Not found — allocate new bolt frame */
    byte *newFrame = (byte *)__Znam(0x44);
    if (newFrame) memset(newFrame, 0, 0x44);
    *(int *)newFrame = 0;       /* refCount */
    *(int *)(newFrame + 4) = 0; /* lastTime */
    *(int *)(newFrame + 0x3c) = entity;
    *(int *)(newFrame + 0x40) = bone;
    *(byte **)(newFrame + 0x38) = __ZN11FxBoltFrame12g_mFrameListE;
    __ZN11FxBoltFrame12g_mFrameListE = newFrame;
    *(int *)newFrame += 1; /* addref */
    *(byte **)retPtr = newFrame;
}
__attribute__((naked))
const FxBoltFramePtr FxBoltFrame_Acquire(const FxBoltInfo *bolt)
{
    (void)bolt;
    __asm__ __volatile__ (
        "pushl 0xc(%esp)\n"
        "pushl 0xc(%esp)\n"
        "calll FxBoltFrame_Acquire_impl\n"
        "addl $8, %esp\n"
        "movl 4(%esp), %eax\n"
        "retl $4\n"
    );
}

/* line 371 */
extern float flrand(float min, float max);
extern void FxScheduler_PlayEffect(void *scheduler, void *fx, float *origin, float *dir);
void Particle_Die(const Particle * _this)
{
    byte *p = (byte *)_this;
    int flags;
    float x, y, z, lenSq, len, scale;
    float norm[3];
    void *scheduler;

    /* line 376: check death effect flags */
    flags = *(int *)(p + 0xa8);
    if (!(flags & 0x200))  /* testb $2, %ah  => bit 9 of flags */
        return;
    if (flags & 0x400)     /* testb $4, %ah  => bit 10 */
        return;

    /* line 379: check if death effect template exists */
    if (*(void **)(p + 0x30) == 0)
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
    FxScheduler_PlayEffect(scheduler, *(void **)(p + 0x30), (float *)(p + 4), norm);
}

/* Tail_CalcNewEndpoint — compute new endpoint from origin + normalized direction * length */
void Tail_CalcNewEndpoint(const Tail *_this, const orientation_t *or_)
{
    byte *self = (byte *)_this;
    /* direction = endpoint - origin */
    float dx = *(float *)(self + 0x24c) - *(float *)(self + 4);
    float dy = *(float *)(self + 0x250) - *(float *)(self + 8);
    float dz = *(float *)(self + 0x254) - *(float *)(self + 0xc);

    /* Normalize direction */
    float lenSq = dx * dx + dy * dy + dz * dz;
    float len;
    __asm__ __volatile__ ("sqrtss %1, %0" : "=x"(len) : "x"(lenSq));
    if (len <= 0.0f) return;

    float invLen = 1.0f / len;
    dx *= invLen;
    dy *= invLen;
    dz *= invLen;

    /* Scale by tail length at 0x258 and offset from origin */
    float scale = *(float *)(self + 0x258);
    float newX = dx * scale + *(float *)(self + 4);
    float newY = dy * scale + *(float *)(self + 8);
    float newZ = dz * scale + *(float *)(self + 0xc);

    if (or_) {
        /* Transform local endpoint to world space via orientation */
        vec3_t localPt;
        localPt[0] = newX; localPt[1] = newY; localPt[2] = newZ;
        OrientationPosToWorldPos((void *)or_, localPt, (vec_t *)(self + 0x9c));
    } else {
        *(float *)(self + 0x9c) = newX;
        *(float *)(self + 0xa0) = newY;
        *(float *)(self + 0xa4) = newZ;
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
    *(int *)(t + 0x264) = *(int *)(p + 0x160); /* line 1492 */
    *(int *)(t + 0x270) = *(int *)(p + 0x16c); /* line 1493 */
}

/* line 1714 */
void Tail_FixupArchiveLoad(const Tail * _this, const PrimitiveTemplate *primTemplate)
{
    byte *t = (byte *)_this;
    byte *p = (byte *)primTemplate;
    /* Particle base fixup (lines 1231-1254) */
    Particle_FixupArchiveLoad((const Particle *)_this, primTemplate);
    /* Tail-specific channels */
    *(int *)(t + 0x260) = *(int *)(p + 0x160); /* line 1720 */
    *(int *)(t + 0x26c) = *(int *)(p + 0x16c); /* line 1721 */
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
    float normTime = *(float *)(self + 0x3c);
    float *rgb = (float *)(self + 0x6c);

    if (*(byte *)(self + 0xa9) & 0x20) {
        /* Blend path: interpolate between two curve sources */
        float blendFactor = *(float *)(self + 0xc4);
        float val0[3], val1[3];
        EvalCurve3(self + 0xcc, normTime, val0);
        EvalCurve3(self + 0xd8, normTime, val1);
        float scale = *(float *)(self + 0xcc + 8);
        rgb[0] = (val0[0] + (val1[0] - val0[0]) * blendFactor) * scale;
        rgb[1] = (val0[1] + (val1[1] - val0[1]) * blendFactor) * scale;
        rgb[2] = (val0[2] + (val1[2] - val0[2]) * blendFactor) * scale;
    } else {
        /* Simple path: single curve source */
        float val[3];
        EvalCurve3(self + 0xcc, normTime, val);
        float scale = *(float *)(self + 0xcc + 8);
        rgb[0] = val[0] * scale;
        rgb[1] = val[1] * scale;
        rgb[2] = val[2] * scale;
    }
}
#if 0 /* Original ASM */
__attribute__((naked))
void Light_UpdateRGB_asm(const Light * _this, const Light * _this_1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2199 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "testb $0x20, 0xa9(%eax)\n" /* line 2203 */
        "je .Lfa1cb4_000a1edb\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 2204 */
        "leal 0x6c(%eax), %ecx\n"
        "movss 0xc4(%eax), %xmm5\n"
        "leal 0xd8(%eax), %edi\n" /* source1 */
        "leal 0xcc(%eax), %esi\n" /* source0 */
        /* { scope 1: keySize */
        /* { scope 2 */
        "movl 0xcc(%eax), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* keySize */
        "imull 4(%esi), %eax\n" /* line 92 | keySize */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja 0xa2007\n"
        "movl -0x1c(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa1cb4_000a1ebc\n"
        /* } scope */
        ".Lfa1cb4_000a1d21:\n"
        "movl 4(%esi), %eax\n" /* line 148 | keySize */
        "shll $4, %eax\n"
        "addl (%esi), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "movaps %xmm3, %xmm2\n" /* line 74 | frac */
        "subss %xmm1, %xmm2\n" /* frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm2\n" /* scale, frac */
        /* { scope 4 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "leal 4(%ecx), %ebx\n" /* line 265 | key */
        "movl %ebx, -0x18(%ebp)\n" /* key */
        "movss 8(%edx), %xmm1\n"
        "movss 0x18(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "leal 8(%ecx), %eax\n" /* line 266 */
        "movl %eax, -0x14(%ebp)\n"
        "movss 0xc(%edx), %xmm1\n"
        "movss 0x1c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl (%edi), %ebx\n" /* line 91 | keySize, key */
        "movl %ebx, -0x24(%ebp)\n" /* key */
        "movl (%ebx), %edx\n" /* key */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%edi), %eax\n" /* keySize */
        "leal (%ebx, %eax, 4), %eax\n" /* key */
        "movl %eax, -0x20(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe 0xa1fff\n"
        "movl $0, 4(%edi)\n" /* line 96 | keySize */
        "addl $8, %ebx\n" /* line 97 | key */
        "movl %ebx, -0x10(%ebp)\n" /* key */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa1cb4_000a1df1\n"
        ".Lfa1cb4_000a1de6:\n"
        "addl $1, 4(%edi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa1cb4_000a1de6\n"
        /* } scope */
        ".Lfa1cb4_000a1df1:\n"
        "movl 4(%edi), %eax\n" /* line 148 | keySize */
        "shll $4, %eax\n"
        "addl -0x24(%ebp), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "subss %xmm1, %xmm3\n" /* line 74 | frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm3\n" /* scale, frac */
        /* { scope 4 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 8(%edx), %xmm2\n" /* line 265 */
        "movss 0xc(%edx), %xmm4\n" /* line 266 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movss 0x18(%edx), %xmm0\n" /* line 249 */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "subss 4(%ecx), %xmm2\n"
        "movss 0x1c(%edx), %xmm0\n" /* line 250 */
        "subss %xmm4, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "subss 8(%ecx), %xmm4\n"
        /* { scope 2 */
        "movss 0x14(%edx), %xmm0\n" /* line 288 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss (%ecx), %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss (%ecx), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "mulss %xmm5, %xmm2\n" /* line 289 */
        "addss 4(%ecx), %xmm2\n"
        "movl -0x18(%ebp), %eax\n"
        "movss %xmm2, (%eax)\n"
        "mulss %xmm4, %xmm5\n" /* line 290 */
        "addss 8(%ecx), %xmm5\n"
        "movl -0x14(%ebp), %ebx\n" /* key */
        "movss %xmm5, (%ebx)\n" /* key */
        /* } scope */
        "movss 8(%esi), %xmm0\n" /* line 74 | scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss (%ecx), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%ecx), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 274 */
        "movss %xmm0, (%ebx)\n" /* key */
        /* } scope */
        /* } scope */
        "addl $0x18, %esp\n" /* line 2209 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keySize */
        /* { scope 2 */
        ".Lfa1cb4_000a1ebc:\n"
        "addl $1, 4(%esi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa1cb4_000a1d21\n"
        "addl $1, 4(%esi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa1cb4_000a1ebc\n"
        "jmp .Lfa1cb4_000a1d21\n"
        /* } scope */
        /* } scope */
        ".Lfa1cb4_000a1edb:\n"
        "movss 0x3c(%eax), %xmm2\n" /* line 2206 */
        "leal 0x6c(%eax), %ebx\n" /* source1 */
        "leal 0xcc(%eax), %ecx\n" /* source */
        /* { scope 1: keySize */
        /* { scope 2 */
        "movl 0xcc(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm2, %xmm0\n"
        "ja 0xa1fe0\n"
    );
}
#endif

/* line 182 */
/* Effect D1 destructor — cleanup bolt frame */
void ZN6EffectD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN6EffectD1Ev(void) /* Effect_~Effect */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN6EffectD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* FxBoltFramePtr_Archive — serialize bolt frame ptr: entity+bone IDs, acquire on read, release temp */
void FxBoltFramePtr_Archive(const FxBoltFramePtr *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;

    if (*(byte *)(a + 4)) {
        /* Reading */
        int entity, bone;
        FxArchive_ReadData(arch, &entity, 4);
        if (entity < 0) {
            /* No bolt — release current and set NULL */
            FxBoltFrame_ReleaseHelper(*(byte **)self);
            *(byte **)self = NULL;
            return;
        }
        FxArchive_ReadData(arch, &bone, 4);
        /* Acquire bolt frame for entity+bone */
        byte boltInfo[8];
        *(int *)boltInfo = entity;
        *(int *)(boltInfo + 4) = bone;
        byte *acquired = NULL;
        /* Call FxBoltFrame_Acquire which returns struct by value */
        __asm__ __volatile__ (
            "leal %1, %%eax\n"
            "pushl %%eax\n"
            "leal %2, %%eax\n"
            "pushl %%eax\n"
            "calll FxBoltFrame_Acquire\n"
            "addl $4, %%esp\n"
            "movl (%0), %%eax\n"
            : : "r"(&acquired), "m"(boltInfo), "m"(acquired)
            : "eax", "ecx", "edx", "memory"
        );
        /* Assign to this with refcount (use Effect_SetBoltFrame pattern) */
        byte *oldBf = *(byte **)self;
        byte *newBf = acquired;
        if (oldBf != newBf) {
            if (oldBf) FxBoltFrame_ReleaseHelper(oldBf);
            *(byte **)self = NULL;
            if (newBf) { *(int *)newBf += 1; *(byte **)self = newBf; }
        }
        /* Release the temp acquired frame */
        if (newBf) FxBoltFrame_ReleaseHelper(newBf);
    } else {
        /* Writing */
        byte *bf = *(byte **)self;
        if (!bf) {
            int neg = -1;
            FxArchive_WriteData(arch, &neg, 4);
        } else {
            int entity = *(int *)(bf + 0x3c);
            int bone = *(int *)(bf + 0x40);
            FxArchive_WriteData(arch, &entity, 4);
            FxArchive_WriteData(arch, &bone, 4);
        }
    }
}
#if 0 /* Original ASM */
__attribute__((naked))
void FxBoltFramePtr_Archive_asm(const FxBoltFramePtr * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 132 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* arch */
        "cmpb $0, 4(%esi)\n" /* line 134 | arch */
        "jne .Lfa2086_000a20e6\n"
        "movl (%edi), %eax\n" /* line 150 | this */
        "testl %eax, %eax\n"
        "je .Lfa2086_000a223b\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* i */
        /* { scope 1: i */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x20(%ebp), %ebx\n" /* i */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* arch */
        "calll FxArchive_WriteData\n"
        "movl (%edi), %eax\n" /* this */
        "movl 0x40(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* i */
        /* } scope */
        /* { scope 1: i */
        "movl $4, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* arch */
        "calll FxArchive_WriteData\n"
        /* } scope */
        ".Lfa2086_000a20de:\n"
        "leal -0xc(%ebp), %esp\n" /* line 160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        /* { scope 2 */
        ".Lfa2086_000a20e6:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x20(%ebp), %ebx\n" /* i */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "movl -0x20(%ebp), %eax\n" /* line 46 | i */
        /* } scope */
        "movl %eax, -0x28(%ebp)\n" /* line 137 | bolt */
        "testl %eax, %eax\n" /* line 138 */
        "js .Lfa2086_000a21e5\n"
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 100 */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 140 | i */
        "movl %eax, -0x24(%ebp)\n"
        "leal -0x1c(%ebp), %edx\n" /* line 141 */
        "leal -0x28(%ebp), %eax\n" /* bolt */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FxBoltFrame_Acquire\n"
        "subl $4, %esp\n"
        "movl (%edi), %edx\n" /* line 78 */
        "cmpl -0x1c(%ebp), %edx\n"
        "je .Lfa2086_000a2195\n"
        "testl %edx, %edx\n" /* line 80 */
        "je .Lfa2086_000a2186\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2086_000a2180\n"
        /* { scope 2 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2086_000a2174\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa2086_000a226b\n"
        ".Lfa2086_000a2161:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2086_000a2174\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2086_000a2161\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2086_000a2174:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2086_000a2180\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa2086_000a2180:\n"
        "movl $0, (%edi)\n" /* line 83 */
        ".Lfa2086_000a2186:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 106 */
        "testl %edx, %edx\n" /* line 85 */
        "je .Lfa2086_000a2195\n"
        "addl $1, (%edx)\n" /* line 39 */
        "movl %edx, (%edi)\n" /* line 86 */
        "movl -0x1c(%ebp), %edx\n"
        ".Lfa2086_000a2195:\n"
        "testl %edx, %edx\n" /* line 60 */
        "je .Lfa2086_000a20de\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2086_000a20de\n"
        /* { scope 2 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2086_000a21d0\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa2086_000a2261\n"
        ".Lfa2086_000a21bd:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2086_000a21d0\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2086_000a21bd\n"
        ".Lfa2086_000a21cb:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2086_000a21d0:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2086_000a20de\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        "jmp .Lfa2086_000a20de\n"
        /* } scope */
        ".Lfa2086_000a21e5:\n"
        "movl (%edi), %edx\n" /* line 91 */
        "testl %edx, %edx\n"
        "je .Lfa2086_000a20de\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2086_000a2226\n"
        /* { scope 2 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2086_000a221a\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa2086_000a227a\n"
        ".Lfa2086_000a2207:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2086_000a221a\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2086_000a2207\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2086_000a221a:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2086_000a2226\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa2086_000a2226:\n"
        "addl $1, 0\n" /* line 39 */
        "movl $0, (%edi)\n" /* line 95 */
        /* } scope */
        "leal -0xc(%ebp), %esp\n" /* line 160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lfa2086_000a223b:\n"
        "movl $0xffffffff, -0x20(%ebp)\n" /* line 137 | i */
        /* } scope */
        /* { scope 1: i */
        "movl $4, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* arch */
        "calll FxArchive_WriteData\n"
        /* } scope */
        "leal -0xc(%ebp), %esp\n" /* line 160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        /* { scope 2 */
        ".Lfa2086_000a2261:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfa2086_000a21cb\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa2086_000a226b:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa2086_000a2174\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa2086_000a227a:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa2086_000a221a\n"
    );
}
#endif

/* line 182 */
/* Effect D0 destructor — cleanup bolt frame + delete this */
void ZN6EffectD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN6EffectD0Ev(void) /* Effect_~Effect */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN6EffectD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 269 */
/* Effect_SetBoltFrame — assign bolt frame with reference counting */
void Effect_SetBoltFrame(const Effect *_this, FxBoltFramePtr *boltFrame)
{
    byte *self = (byte *)_this;
    byte **bfSlot = (byte **)(self + 0xc0);
    byte *newBf = *(byte **)boltFrame;
    byte *oldBf = *bfSlot;

    if (oldBf == newBf)
        return;

    /* Release old bolt frame */
    if (oldBf) {
        int rc = *(int *)oldBf - 1;
        *(int *)oldBf = rc;
        if (rc == 0) {
            /* Remove from linked list and free */
            byte **prevNext = &__ZN11FxBoltFrame12g_mFrameListE;
            byte *cur = *prevNext;
            while (cur) {
                if (cur == oldBf) { *prevNext = *(byte **)(oldBf + 0x38); break; }
                prevNext = (byte **)(cur + 0x38);
                cur = *prevNext;
            }
            if (oldBf) __ZdaPv(oldBf);
        }
        *bfSlot = NULL;
    }

    /* Acquire new bolt frame */
    if (newBf) {
        *(int *)newBf += 1;
        *bfSlot = newBf;
    }
}

/* Particle_UpdateRGB — evaluate 3-component RGB curve, convert to RGBA bytes */
void Particle_UpdateRGB(const Particle *_this)
{
    byte *self = (byte *)_this;
    float normTime = *(float *)(self + 0x3c);
    float rgb[3];

    if (*(byte *)(self + 0xa9) & 0x20) {
        /* Blend path */
        float blendFactor = *(float *)(self + 0x118);
        float v0[3], v1[3];
        EvalCurve3(self + 0x144, normTime, v0);
        EvalCurve3(self + 0x150, normTime, v1);
        float scale = *(float *)(self + 0x144 + 8);
        rgb[0] = (v0[0] + (v1[0] - v0[0]) * blendFactor) * scale;
        rgb[1] = (v0[1] + (v1[1] - v0[1]) * blendFactor) * scale;
        rgb[2] = (v0[2] + (v1[2] - v0[2]) * blendFactor) * scale;
    } else {
        EvalCurve3(self + 0x144, normTime, rgb);
        float scale = *(float *)(self + 0x144 + 8);
        rgb[0] *= scale;
        rgb[1] *= scale;
        rgb[2] *= scale;
    }

    /* Convert to bytes at offset 0x90 */
    *(byte *)(self + 0x90) = (byte)FloatToByte(rgb[0]);
    *(byte *)(self + 0x91) = (byte)FloatToByte(rgb[1]);
    *(byte *)(self + 0x92) = (byte)FloatToByte(rgb[2]);
}
#if 0 /* Original ASM (313 lines) */
__attribute__((naked))
void Particle_UpdateRGB_asm(const Particle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1041 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1047 | this */
        "testb $0x20, 0xa9(%eax)\n"
        "je .Lfa236e_000a25d8\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1048 */
        "movss 0x118(%eax), %xmm6\n"
        "movl %eax, %esi\n" /* source1 */
        "addl $0x150, %esi\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x144, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x144(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa236e_000a2719\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa236e_000a259a\n"
        /* } scope */
        ".Lfa236e_000a23dc:\n"
        "movl 4(%ecx), %eax\n" /* line 148 */
        "shll $4, %eax\n"
        "addl (%ecx), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "movaps %xmm3, %xmm2\n" /* line 74 | frac */
        "subss %xmm1, %xmm2\n" /* frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm2\n" /* scale, frac */
        /* { scope 5 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x18(%ebp)\n" /* rgbVal */
        "movss 8(%edx), %xmm1\n" /* line 265 */
        "movss 0x18(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "movss 0xc(%edx), %xmm1\n" /* line 266 */
        "movss 0x1c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%esi), %ebx\n" /* line 91 | keySize */
        "movl (%ebx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%esi), %eax\n" /* keySize */
        "leal (%ebx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa236e_000a26fb\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa236e_000a25b9\n"
        /* } scope */
        ".Lfa236e_000a2481:\n"
        "movl 4(%esi), %eax\n" /* line 148 | keySize */
        "shll $4, %eax\n"
        "addl %ebx, %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "subss %xmm1, %xmm3\n" /* line 74 | frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm3\n" /* scale, frac */
        /* { scope 5 */
        "movss 4(%edx), %xmm2\n" /* line 264 */
        "movss 8(%edx), %xmm1\n" /* line 265 */
        "movss 0xc(%edx), %xmm4\n" /* line 266 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movss -0x18(%ebp), %xmm5\n" /* line 248 | rgbVal */
        "movss 0x18(%edx), %xmm0\n" /* line 249 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss -0x14(%ebp), %xmm1\n"
        "movss 0x1c(%edx), %xmm0\n" /* line 250 */
        "subss %xmm4, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "subss -0x10(%ebp), %xmm4\n"
        /* { scope 3 */
        "movss 0x14(%edx), %xmm0\n" /* line 288 */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm6, %xmm2\n"
        "addss %xmm2, %xmm5\n"
        "movss %xmm5, -0x18(%ebp)\n" /* rgbVal */
        "mulss %xmm6, %xmm1\n" /* line 289 */
        "addss -0x14(%ebp), %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "mulss %xmm4, %xmm6\n" /* line 290 */
        "addss -0x10(%ebp), %xmm6\n"
        "movss %xmm6, -0x10(%ebp)\n"
        /* } scope */
        "movss 8(%ecx), %xmm0\n" /* line 74 | scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss %xmm5, %xmm1\n"
        "movss %xmm1, -0x18(%ebp)\n" /* rgbVal */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x14(%ebp), %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "mulss %xmm6, %xmm0\n" /* line 274 */
        "movss %xmm0, -0x10(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lfa236e_000a2547:\n"
        "movl 8(%ebp), %esi\n" /* line 1052 | this, res */
        "addl $0x90, %esi\n" /* res */
        "movl $1, %ebx\n"
        "leal -0x18(%ebp), %edi\n" /* rgbVal, keySize */
        "movss lit4_002ed5d4, %xmm1\n" /* 255.0f */
        /* { scope 2 */
        ".Lfa236e_000a2560:\n"
        "movss -4(%edi, %ebx, 4), %xmm0\n" /* line 49 */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "movl $0xff, %ecx\n" /* line 154 */
        "movl %edx, %eax\n"
        "subl $0xff, %eax\n"
        "cmovsl %edx, %ecx\n"
        "negl %edx\n"
        "xorl %eax, %eax\n"
        "testl %edx, %edx\n"
        "cmovsl %ecx, %eax\n"
        "movb %al, -1(%esi, %ebx)\n" /* line 50 */
        "addl $1, %ebx\n"
        "cmpl $4, %ebx\n" /* line 47 */
        "jne .Lfa236e_000a2560\n"
        /* } scope */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1055 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa236e_000a259a:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa236e_000a23dc\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa236e_000a259a\n"
        "jmp .Lfa236e_000a23dc\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa236e_000a25b9:\n"
        "addl $1, 4(%esi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa236e_000a2481\n"
        "addl $1, 4(%esi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa236e_000a25b9\n"
        "jmp .Lfa236e_000a2481\n"
        /* } scope */
        /* } scope */
        ".Lfa236e_000a25d8:\n"
        "movss 0x3c(%eax), %xmm2\n" /* line 1050 */
        "movl %eax, %ecx\n" /* source */
        "addl $0x144, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x144(%eax), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lfa236e_000a26dc\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n"
        "ucomiss (%eax), %xmm2\n"
        "ja .Lfa236e_000a26bd\n"
        /* } scope */
        ".Lfa236e_000a261d:\n"
        "movl 4(%ecx), %eax\n" /* line 148 */
        "shll $4, %eax\n"
        "addl (%ecx), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "subss %xmm1, %xmm2\n" /* line 74 | frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm2\n" /* scale, frac */
        /* { scope 5 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x18(%ebp)\n" /* rgbVal */
        "movss 8(%edx), %xmm1\n" /* line 265 */
        "movss 0x18(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "movss 0xc(%edx), %xmm1\n" /* line 266 */
        "movss 0x1c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movss 8(%ecx), %xmm0\n" /* line 39 | scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x18(%ebp), %xmm1\n" /* rgbVal */
        "movss %xmm1, -0x18(%ebp)\n" /* rgbVal */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x14(%ebp), %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "mulss -0x10(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x10(%ebp)\n"
        "jmp .Lfa236e_000a2547\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa236e_000a26bd:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm2\n"
        "jbe .Lfa236e_000a261d\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm2\n"
        "ja .Lfa236e_000a26bd\n"
        "jmp .Lfa236e_000a261d\n"
        ".Lfa236e_000a26dc:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n"
        "ucomiss (%eax), %xmm2\n"
        "jbe .Lfa236e_000a261d\n"
        "jmp .Lfa236e_000a26bd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa236e_000a26fb:\n"
        "movl $0, 4(%esi)\n" /* line 96 | keySize */
        "leal 8(%ebx), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa236e_000a2481\n"
        "jmp .Lfa236e_000a25b9\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa236e_000a2719:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa236e_000a23dc\n"
        "jmp .Lfa236e_000a259a\n"
    );
}
#endif

/* line 2251 */
Bool Flash_Update(const Flash * _this)
{
    byte *p = (byte *)_this;
    byte *helper = *(byte **)imp_theFxHelper;
    int startTime = *(int *)(p + 0xb8);
    int curTime = *(int *)(helper + 4);
    int endTime;
    float normDuration;

    if (startTime > curTime)
        return 0;

    endTime = *(int *)(p + 0xbc);
    normDuration = (float)(curTime - startTime) / (float)(endTime - startTime);
    *(float *)(p + 0x3c) = normDuration;

    if (normDuration > 1.0f)
        *(float *)(p + 0x3c) = 1.0f;

    if (0.0f > *(float *)(p + 0x3c))
        *(float *)(p + 0x3c) = 0.0f;

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
    int useBlend = (*(byte *)(self + 0xaa) & 8) != 0;
    float vx, vy, vz;

    if (useBlend) {
        vx = IntegrateChannel(self, 0x1bc, 0x1e0, *(float *)(self + 0x12c), 0x1bc + 8, normDuration, 1);
        vy = IntegrateChannel(self, 0x1c8, 0x1ec, *(float *)(self + 0x130), 0x1c8 + 8, normDuration, 1);
        vz = IntegrateChannel(self, 0x1d4, 0x1f8, *(float *)(self + 0x134), 0x1d4 + 8, normDuration, 1);
    } else {
        vx = IntegrateChannel(self, 0x1bc, 0, 0, 0x1bc + 8, normDuration, 0);
        vy = IntegrateChannel(self, 0x1c8, 0, 0, 0x1c8 + 8, normDuration, 0);
        vz = IntegrateChannel(self, 0x1d4, 0, 0, 0x1d4 + 8, normDuration, 0);
    }

    /* Optional axis transform (if NOT flag bit 5) */
    if (!(*(byte *)(self + 0xaa) & 0x20)) {
        AxisTransformVector(self + 0xd0, vx, vy, vz, outVector);
    } else {
        outVector[0] = vx;
        outVector[1] = vy;
        outVector[2] = vz;
    }

    /* Scale by lifetime in seconds */
    float lifetimeSec = (float)(*(int *)(self + 0xbc) - *(int *)(self + 0xb8)) * 0.001f;
    outVector[0] *= lifetimeSec;
    outVector[1] *= lifetimeSec;
    outVector[2] *= lifetimeSec;
}
#if 0 /* Original ASM */
__attribute__((naked))
void Particle_IntegrateVelocity_asm(const Particle * _this, float normDuration, vec_t *outVector)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 880 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0x10(%ebp), %edi\n" /* outVector */
        "testb $8, 0xaa(%esi)\n" /* line 884 | this */
        "je .Lfa27b8_000a2987\n"
        "movss 0x12c(%esi), %xmm0\n" /* line 886 | this */
        "movss %xmm0, -0x24(%ebp)\n"
        "leal 0x1bc(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x2c(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x1e0(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x2c(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x24(%ebp), %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "mulss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        /* } scope */
        "movss 0x130(%esi), %xmm0\n" /* line 887 | this */
        "movss %xmm0, -0x28(%ebp)\n"
        "leal 0x1c8(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1c8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x20(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x1ec(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x20(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x28(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "mulss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* } scope */
        "movss 0x134(%esi), %xmm0\n" /* line 888 | this */
        "movss %xmm0, -0x30(%ebp)\n" /* blendFactor */
        "leal 0x1d4(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1d4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x1c(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x1f8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x1c(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x30(%ebp), %xmm0\n" /* blendFactor */
        "addss -0x1c(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        /* } scope */
        "testb $0x20, 0xaa(%esi)\n" /* line 897 | this */
        "je .Lfa27b8_000a2a22\n"
        ".Lfa27b8_000a2929:\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 199 */
        "movss %xmm1, (%edi)\n"
        "leal 4(%edi), %ecx\n" /* line 200 */
        "movss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "leal 8(%edi), %edx\n" /* line 201 */
        "movss %xmm0, 8(%edi)\n"
        ".Lfa27b8_000a2947:\n"
        "movl 0xbc(%esi), %eax\n" /* line 902 | this */
        "subl 0xb8(%esi), %eax\n" /* this */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f, scale */
        /* { scope 1 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss (%edi), %xmm1\n"
        "movss %xmm1, (%edi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%edi), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "mulss 8(%edi), %xmm0\n" /* line 274 */
        "movss %xmm0, (%edx)\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 903 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa27b8_000a2987:\n"
        "leal 0x1bc(%esi), %ebx\n" /* line 892 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x24(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        /* } scope */
        "leal 0x1c8(%esi), %ebx\n" /* line 893 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1c8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x28(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "leal 0x1d4(%esi), %ebx\n" /* line 894 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1d4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        /* } scope */
        "testb $0x20, 0xaa(%esi)\n" /* line 897 | this */
        "jne .Lfa27b8_000a2929\n"
        ".Lfa27b8_000a2a22:\n"
        "movl %edi, 0x10(%esp)\n" /* line 900 | outVector */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x24(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "leal 0xd0(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "leal 4(%edi), %ecx\n" /* outVector */
        "leal 8(%edi), %edx\n" /* outVector */
        "jmp .Lfa27b8_000a2947\n"
    );
}
#endif

/* line 906 — Particle_IntegrateVelocity2 — same pattern as IntegrateVelocity but different channel offsets */
void Particle_IntegrateVelocity2(const Particle *_this, float normDuration, vec_t *outVector)
{
    byte *self = (byte *)_this;
    int useBlend = (*(byte *)(self + 0xaa) & 8) != 0;
    float vx, vy, vz;

    /* Velocity2 channels are at offsets 0x204, 0x210, 0x21c with blend variants at 0x228, 0x234, 0x240 */
    if (useBlend) {
        vx = IntegrateChannel(self, 0x204, 0x228, *(float *)(self + 0x138), 0x204 + 8, normDuration, 1);
        vy = IntegrateChannel(self, 0x210, 0x234, *(float *)(self + 0x13c), 0x210 + 8, normDuration, 1);
        vz = IntegrateChannel(self, 0x21c, 0x240, *(float *)(self + 0x140), 0x21c + 8, normDuration, 1);
    } else {
        vx = IntegrateChannel(self, 0x204, 0, 0, 0x204 + 8, normDuration, 0);
        vy = IntegrateChannel(self, 0x210, 0, 0, 0x210 + 8, normDuration, 0);
        vz = IntegrateChannel(self, 0x21c, 0, 0, 0x21c + 8, normDuration, 0);
    }

    if (!(*(byte *)(self + 0xaa) & 0x20)) {
        AxisTransformVector(self + 0xd0, vx, vy, vz, outVector);
    } else {
        outVector[0] = vx; outVector[1] = vy; outVector[2] = vz;
    }

    float lifetimeSec = (float)(*(int *)(self + 0xbc) - *(int *)(self + 0xb8)) * 0.001f;
    outVector[0] *= lifetimeSec; outVector[1] *= lifetimeSec; outVector[2] *= lifetimeSec;
}
#if 0 /* Original IntegrateVelocity2 ASM */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 906 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0x10(%ebp), %edi\n" /* outVector */
        "testb $8, 0xaa(%esi)\n" /* line 910 | this */
        "je .Lfa2a5c_000a2c2b\n"
        "movss 0x138(%esi), %xmm0\n" /* line 912 | this */
        "movss %xmm0, -0x24(%ebp)\n"
        "leal 0x204(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x204(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x2c(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x228(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x2c(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x24(%ebp), %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "mulss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        /* } scope */
        "movss 0x13c(%esi), %xmm0\n" /* line 913 | this */
        "movss %xmm0, -0x28(%ebp)\n"
        "leal 0x210(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x210(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x20(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x234(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x20(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x28(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "mulss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* } scope */
        "movss 0x140(%esi), %xmm0\n" /* line 914 | this */
        "movss %xmm0, -0x30(%ebp)\n" /* blendFactor */
        "leal 0x21c(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x21c(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x1c(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x240(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x1c(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x30(%ebp), %xmm0\n" /* blendFactor */
        "addss -0x1c(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        /* } scope */
        "testb $0x40, 0xaa(%esi)\n" /* line 923 | this */
        "je .Lfa2a5c_000a2cc6\n"
        ".Lfa2a5c_000a2bcd:\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 199 */
        "movss %xmm1, (%edi)\n"
        "leal 4(%edi), %ecx\n" /* line 200 */
        "movss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "leal 8(%edi), %edx\n" /* line 201 */
        "movss %xmm0, 8(%edi)\n"
        ".Lfa2a5c_000a2beb:\n"
        "movl 0xbc(%esi), %eax\n" /* line 928 | this */
        "subl 0xb8(%esi), %eax\n" /* this */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f, scale */
        /* { scope 1 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss (%edi), %xmm1\n"
        "movss %xmm1, (%edi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%edi), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "mulss 8(%edi), %xmm0\n" /* line 274 */
        "movss %xmm0, (%edx)\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 929 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa2a5c_000a2c2b:\n"
        "leal 0x204(%esi), %ebx\n" /* line 918 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x204(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x24(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        /* } scope */
        "leal 0x210(%esi), %ebx\n" /* line 919 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x210(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x28(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "leal 0x21c(%esi), %ebx\n" /* line 920 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x21c(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        /* } scope */
        "testb $0x40, 0xaa(%esi)\n" /* line 923 | this */
        "jne .Lfa2a5c_000a2bcd\n"
        ".Lfa2a5c_000a2cc6:\n"
        "movl %edi, 0x10(%esp)\n" /* line 926 | outVector */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x24(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "leal 0xd0(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "leal 4(%edi), %ecx\n" /* outVector */
        "leal 8(%edi), %edx\n" /* outVector */
        "jmp .Lfa2a5c_000a2beb\n"
    );
}
#endif

/* Particle_IntegrateTotalVelocity — integrate vel1 + vel2 + gravity over duration */
void Particle_IntegrateTotalVelocity(const Particle *_this, int duration, vec_t *outVector)
{
    byte *self = (byte *)_this;
    int lifetime = *(int *)(self + 0xbc) - *(int *)(self + 0xb8);
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
    float gravityAccum = durationF * *(float *)(self + 0xf4) * 0.001f;
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
    *(int *)((byte *)_this + 0xc0) = 0;
    *(int *)_this = 0x32ffc8;
    *(int *)((byte *)_this + 0xc4) = 0;
    *(int *)((byte *)_this + 0xc8) = 0;
    *(int *)((byte *)_this + 0xcc) = 0;
}

/* overload skip: Particle_Particle (0xa2e3c) */

/* Particle D1 destructor — cleanup bolt frame, set vtable to Effect base */
void ZN8ParticleD1Ev_impl(void *_this)
{
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN8ParticleD1Ev(void) /* Particle_~Particle */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN8ParticleD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* Particle D0 destructor — cleanup bolt frame + delete this */
void ZN8ParticleD0Ev_impl(void *_this)
{
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN8ParticleD0Ev(void) /* Particle_~Particle */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN8ParticleD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 2131 */
void Light_Light(const Light * _this)
{
    *(int *)((byte *)_this + 0xc0) = 0;
    *(int *)_this = 0x330188;
}

/* overload skip: Light_Light (0xa2f4c) */

/* line 2136 */
/* Light D1 destructor — cleanup bolt frame */
void ZN5LightD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN5LightD1Ev(void) /* Light_~Light */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN5LightD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 2136 */
/* Light D0 destructor — cleanup bolt frame + delete this */
void ZN5LightD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN5LightD0Ev(void) /* Light_~Light */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN5LightD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* Tail_InitEndPoint — evaluate tail length curve(s) at normTime, store in endLength at 0x258, call CalcNewEndpoint */
void Tail_InitEndPoint(const Tail *_this)
{
    byte *self = (byte *)_this;
    float normTime = *(float *)(self + 0x3c);

    /* Evaluate tail length curve (1-component, optional blend) */
    float tailLen;
    if (*(byte *)(self + 0xaa) & 2) {
        float blendFactor = *(float *)(self + 0x25c);
        float v0 = EvalCurve1(self + 0x260, normTime);
        float v1 = EvalCurve1(self + 0x26c, normTime);
        tailLen = (v0 + (v1 - v0) * blendFactor) * *(float *)(self + 0x260 + 8);
    } else {
        tailLen = EvalCurve1(self + 0x260, normTime) * *(float *)(self + 0x260 + 8);
    }
    *(float *)(self + 0x258) = tailLen;

    /* Get bolt orientation for CalcNewEndpoint */
    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx >= 0) {
            int clTime = *(int *)(*(byte *)imp_cl + 0x864c);
            if (*(int *)(boltFrame + 4) != clTime) {
                *(int *)(boltFrame + 4) = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8)))
                    { *(int *)(boltFrame + 0x3c) = -1; *(int *)(boltFrame + 0x40) = -1; }
            }
            if (*(int *)(boltFrame + 0x3c) >= 0)
                orient = boltFrame + 8;
        }
    }

    Tail_CalcNewEndpoint(_this, (const orientation_t *)orient);
}
#if 0 /* Original ASM (230 lines) */
__attribute__((naked))
void Tail_InitEndPoint_asm(const Tail * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1589 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 1658 | this */
        "testb $2, 0xaa(%eax)\n"
        "je .Lfa3030_000a31b2\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1659 */
        "movss 0x25c(%eax), %xmm5\n" /* blendFactor */
        "movl %eax, %ebx\n" /* source1 */
        "addl $0x26c, %ebx\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x260, %ecx\n" /* source0 */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x260(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa3030_000a32aa\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3174\n"
        /* } scope */
        ".Lfa3030_000a309e:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa3030_000a328c\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3193\n"
        /* } scope */
        ".Lfa3030_000a3108:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1659 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movss %xmm4, 0x258(%eax)\n"
        "movl $0, 4(%esp)\n" /* line 1592 */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll Tail_CalcNewEndpoint\n"
        "addl $0x1c, %esp\n" /* line 1593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa3030_000a3174:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a309e\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3174\n"
        "jmp .Lfa3030_000a309e\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa3030_000a3193:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a3108\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3193\n"
        "jmp .Lfa3030_000a3108\n"
        /* } scope */
        /* } scope */
        ".Lfa3030_000a31b2:\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1661 */
        "movl %eax, %ecx\n" /* source */
        "addl $0x260, %ecx\n" /* source */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x260(%eax), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa3030_000a326d\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3255\n"
        /* } scope */
        ".Lfa3030_000a31f3:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1661 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movss %xmm1, 0x258(%eax)\n"
        "movl $0, 4(%esp)\n" /* line 1592 */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll Tail_CalcNewEndpoint\n"
        "addl $0x1c, %esp\n" /* line 1593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa3030_000a3255:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a31f3\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3255\n"
        "jmp .Lfa3030_000a31f3\n"
        ".Lfa3030_000a326d:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a31f3\n"
        "jmp .Lfa3030_000a3255\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa3030_000a328c:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a3108\n"
        "jmp .Lfa3030_000a3193\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa3030_000a32aa:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a309e\n"
        "jmp .Lfa3030_000a3174\n"
    );
}
#endif

/* Light_Update — normTime computation, bolt orientation, radius eval, RGB update */
Bool Light_Update(const Light *_this)
{
    byte *self = (byte *)_this;
    int startTime = *(int *)(self + 0xb8);
    int killTime = *(int *)(self + 0xbc);
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;

    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    *(float *)(self + 0x3c) = normTime;
    if (normTime < 0.0f) return 0;

    /* Get bolt orientation */
    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx >= 0) {
            int clTime = *(int *)(*(byte *)imp_cl + 0x864c);
            if (*(int *)(boltFrame + 4) != clTime) {
                *(int *)(boltFrame + 4) = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8)))
                    { *(int *)(boltFrame + 0x3c) = -1; *(int *)(boltFrame + 0x40) = -1; }
            }
            if (*(int *)(boltFrame + 0x3c) >= 0)
                orient = boltFrame + 8;
        }
    }

    /* World position from bolt or direct */
    if (orient) {
        OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)(self + 0x7c));
    } else {
        *(float *)(self + 0x7c) = *(float *)(self + 4);
        *(float *)(self + 0x80) = *(float *)(self + 8);
        *(float *)(self + 0x84) = *(float *)(self + 0xc);
    }

    /* Evaluate radius curve */
    float radius;
    if (*(byte *)(self + 0xa9) & 0x10) {
        float bf = *(float *)(self + 0xc8);
        float v0 = EvalCurve1(self + 0xe4, normTime);
        float v1 = EvalCurve1(self + 0xf0, normTime);
        radius = (v0 + (v1 - v0) * bf) * *(float *)(self + 0xe4 + 8);
    } else {
        radius = EvalCurve1(self + 0xe4, normTime) * *(float *)(self + 0xe4 + 8);
    }
    *(float *)(self + 0x88) = radius;
    *(float *)(self + 0x8c) = radius;

    if (radius == 0.0f) {
        *(int *)(self + 0xa8) |= 0x01000000;
        return 1;
    }

    /* Update RGB */
    Light_UpdateRGB(_this, NULL);
    return 1;
}
#if 0 /* Original ASM (296 lines) */
__attribute__((naked))
Bool Light_Update_asm(const Light * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2164 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa32cc_000a3468\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa32cc_000a331d\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa32cc_000a331d:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa32cc_000a35e6\n"
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa32cc_000a341a\n"
        ".Lfa32cc_000a3339:\n"
        "movl $0, -0x24(%ebp)\n" /* or_ */
        ".Lfa32cc_000a3340:\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 2192 | this */
        "js .Lfa32cc_000a3472\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 2195 | this */
        "leal 0xe4(%esi), %ecx\n" /* this, source */
        /* { scope 2: keySize */
        /* { scope 3 */
        "movl 0xe4(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa32cc_000a3384\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        ".Lfa32cc_000a3384:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa32cc_000a339e\n"
        ".Lfa32cc_000a3393:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa32cc_000a3393\n"
        /* } scope */
        ".Lfa32cc_000a339e:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 2195 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n" /* this */
        "movl %esi, (%esp)\n" /* line 2178 | this */
        "calll Light_UpdateRGB\n"
        "movl -0x24(%ebp), %edi\n" /* line 2181 | or_, keySize */
        "testl %edi, %edi\n" /* keySize */
        "jne .Lfa32cc_000a35c0\n"
        ".Lfa32cc_000a33f5:\n"
        "leal 0x7c(%esi), %ecx\n" /* line 2184 | this, to */
        "leal 4(%esi), %edx\n" /* this, from */
        /* { scope 2: keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa32cc_000a341a:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 */
        /* { scope 2: keySize */
        "movl 0x3c(%ebx), %eax\n" /* line 90 */
        "testl %eax, %eax\n"
        "js .Lfa32cc_000a3468\n"
        "movl imp_cl, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n"
        "je .Lfa32cc_000a35fe\n"
        "movl %eax, 4(%ebx)\n" /* line 96 */
        "leal 8(%ebx), %edi\n" /* line 102 | keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa32cc_000a3601\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 */
        /* } scope */
        /* { scope 2: keySize */
        ".Lfa32cc_000a3468:\n"
        "xorl %eax, %eax\n" /* line 201 */
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa32cc_000a3472:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 2193 | this */
        "movss 0xc8(%esi), %xmm5\n" /* this, blendFactor */
        "leal 0xf0(%esi), %ebx\n" /* this, source1 */
        "leal 0xe4(%esi), %ecx\n" /* this, source0 */
        /* { scope 2: keySize */
        /* { scope 3 */
        "movl 0xe4(%esi), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa32cc_000a34b7\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa32cc_000a34b7:\n"
        "movl -0x20(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa32cc_000a34d0\n"
        ".Lfa32cc_000a34c5:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa32cc_000a34c5\n"
        /* } scope */
        ".Lfa32cc_000a34d0:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edx\n" /* line 91 */
        "movl %edx, -0x30(%ebp)\n"
        "movl %edx, %edi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x2c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa32cc_000a3611\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x1c(%ebp)\n" /* keySize */
        ".Lfa32cc_000a3546:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa32cc_000a355c\n"
        ".Lfa32cc_000a3551:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa32cc_000a3551\n"
        /* } scope */
        ".Lfa32cc_000a355c:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "movl -0x30(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 2193 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n" /* this */
        "movl %esi, (%esp)\n" /* line 2178 | this */
        "calll Light_UpdateRGB\n"
        "movl -0x24(%ebp), %edi\n" /* line 2181 | or_, keySize */
        "testl %edi, %edi\n" /* keySize */
        "je .Lfa32cc_000a33f5\n"
        ".Lfa32cc_000a35c0:\n"
        "leal 0x7c(%esi), %eax\n" /* line 2182 | this */
        "movl %eax, 8(%esp)\n"
        "leal 4(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl -0x24(%ebp), %edi\n" /* or_, keySize */
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa32cc_000a35e6:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa32cc_000a341a\n"
        "jmp .Lfa32cc_000a3339\n"
        ".Lfa32cc_000a35fe:\n"
        "leal 8(%ebx), %edi\n" /* keySize */
        /* { scope 2: keySize */
        ".Lfa32cc_000a3601:\n"
        "movl %edi, -0x24(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa32cc_000a3340\n"
        "jmp .Lfa32cc_000a3468\n"
        ".Lfa32cc_000a3611:\n"
        "movl -0x1c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa32cc_000a3546\n"
    );
}
#endif

/* line 782 */
__attribute__((naked))
void Particle_CalcVelocityValue(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 782 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movss 0xc(%ebp), %xmm4\n" /* normTime */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 786 | this */
        "testb $8, 0xaa(%eax)\n"
        "je .Lfa361a_000a3a70\n"
        "movss 0x12c(%eax), %xmm6\n" /* line 788 | blendFactor */
        "movl %eax, %ebx\n" /* source1 */
        "addl $0x1e0, %ebx\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x1bc, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x1bc(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3d04\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a398f\n"
        /* } scope */
        ".Lfa361a_000a3688:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm5\n" /* line 56 */
        "subss %xmm1, %xmm5\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm5\n"
        "addss %xmm2, %xmm5\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3ce6\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39ae\n"
        /* } scope */
        ".Lfa361a_000a36f2:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 788 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm2, %xmm6\n" /* blendFactor */
        "addss %xmm6, %xmm5\n" /* blendFactor */
        "mulss 8(%ecx), %xmm5\n"
        "movss %xmm5, -0x24(%ebp)\n" /* sampledVel */
        "movl 8(%ebp), %edx\n" /* line 789 | this */
        "movss 0x130(%edx), %xmm6\n" /* blendFactor */
        "movl %edx, %ebx\n" /* source1 */
        "addl $0x1ec, %ebx\n" /* source1 */
        "movl %edx, %ecx\n" /* source0 */
        "addl $0x1c8, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x1c8(%edx), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3cc4\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39cd\n"
        /* } scope */
        ".Lfa361a_000a3793:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm5\n" /* line 56 */
        "subss %xmm1, %xmm5\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm5\n"
        "addss %xmm2, %xmm5\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3ca6\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39ec\n"
        /* } scope */
        ".Lfa361a_000a37fd:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 789 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm2, %xmm6\n" /* blendFactor */
        "addss %xmm6, %xmm5\n" /* blendFactor */
        "mulss 8(%ecx), %xmm5\n"
        "movss %xmm5, -0x20(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 790 | this */
        "movss 0x134(%edx), %xmm5\n" /* blendFactor */
        "movl %edx, %ebx\n" /* source1 */
        "addl $0x1f8, %ebx\n" /* source1 */
        "movl %edx, %ecx\n" /* source0 */
        "addl $0x1d4, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x1d4(%edx), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3c84\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3a0b\n"
        /* } scope */
        ".Lfa361a_000a389e:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm3\n" /* line 56 */
        "subss %xmm1, %xmm3\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3c66\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3a2a\n"
        /* } scope */
        ".Lfa361a_000a3908:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm4\n" /* line 790 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "subss %xmm3, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm3\n" /* blendFactor */
        "mulss 8(%ecx), %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        ".Lfa361a_000a3953:\n"
        "movl 8(%ebp), %edx\n" /* line 799 | this */
        "testb $0x20, 0xaa(%edx)\n"
        "je .Lfa361a_000a3a49\n"
        "movl 0x14(%ebp), %eax\n" /* line 801 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa361a_000a3a54\n"
        "movl 0x10(%ebp), %eax\n" /* line 802 | outVector */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* sampledVel */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* or_ */
        "movl %edx, (%esp)\n"
        "calll OrientationDirFromWorldDir\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a398f:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3688\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a398f\n"
        "jmp .Lfa361a_000a3688\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a39ae:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a36f2\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39ae\n"
        "jmp .Lfa361a_000a36f2\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a39cd:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3793\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39cd\n"
        "jmp .Lfa361a_000a3793\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a39ec:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a37fd\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39ec\n"
        "jmp .Lfa361a_000a37fd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3a0b:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a389e\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3a0b\n"
        "jmp .Lfa361a_000a389e\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a3a2a:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3908\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3a2a\n"
        "jmp .Lfa361a_000a3908\n"
        /* } scope */
        /* } scope */
        ".Lfa361a_000a3a49:\n"
        "movl 0x14(%ebp), %eax\n" /* line 808 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa361a_000a3d8c\n"
        ".Lfa361a_000a3a54:\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | sampledVel */
        "movl 0x10(%ebp), %edx\n" /* outVector */
        "movl %eax, (%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lfa361a_000a3a68:\n"
        "addl $0x3c, %esp\n" /* line 813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa361a_000a3a70:\n"
        "movl %eax, %ecx\n"
        /* { scope 1 */
        "addl $0x1bc, %ecx\n" /* line 794 | source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x1bc(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3d6a\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c09\n"
        /* } scope */
        ".Lfa361a_000a3ab3:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 794 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss 8(%ecx), %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* sampledVel */
        "movl 8(%ebp), %ecx\n" /* line 795 | this, source */
        "addl $0x1c8, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x1c8(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3d48\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c28\n"
        /* } scope */
        ".Lfa361a_000a3b3b:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 795 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss 8(%ecx), %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 796 | this, source */
        "addl $0x1d4, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x1d4(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3d26\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c47\n"
        /* } scope */
        ".Lfa361a_000a3bc3:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm4\n" /* line 796 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "jmp .Lfa361a_000a3953\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3c09:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3ab3\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c09\n"
        "jmp .Lfa361a_000a3ab3\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3c28:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3b3b\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c28\n"
        "jmp .Lfa361a_000a3b3b\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3c47:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3bc3\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c47\n"
        "jmp .Lfa361a_000a3bc3\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3c66:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3908\n"
        "jmp .Lfa361a_000a3a2a\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a3c84:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a389e\n"
        "jmp .Lfa361a_000a3a0b\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3ca6:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a37fd\n"
        "jmp .Lfa361a_000a39ec\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a3cc4:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3793\n"
        "jmp .Lfa361a_000a39cd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3ce6:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a36f2\n"
        "jmp .Lfa361a_000a39ae\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a3d04:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3688\n"
        "jmp .Lfa361a_000a398f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3d26:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3bc3\n"
        "jmp .Lfa361a_000a3c47\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3d48:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3b3b\n"
        "jmp .Lfa361a_000a3c28\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3d6a:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3ab3\n"
        "jmp .Lfa361a_000a3c09\n"
        /* } scope */
        /* } scope */
        ".Lfa361a_000a3d8c:\n"
        "movl 0x10(%ebp), %eax\n" /* line 811 | outVector */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* sampledVel */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0xd0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "jmp .Lfa361a_000a3a68\n"
    );
}

/* line 816 */
__attribute__((naked))
void Particle_CalcVelocity2Value(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 816 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movss 0xc(%ebp), %xmm4\n" /* normTime */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 820 | this */
        "testb $0x10, 0xaa(%eax)\n"
        "je .Lfa3dbe_000a4214\n"
        "movss 0x138(%eax), %xmm6\n" /* line 822 | blendFactor */
        "movl %eax, %ebx\n" /* source1 */
        "addl $0x228, %ebx\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x204, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x204(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a44a8\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4133\n"
        /* } scope */
        ".Lfa3dbe_000a3e2c:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm5\n" /* line 56 */
        "subss %xmm1, %xmm5\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm5\n"
        "addss %xmm2, %xmm5\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a448a\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4152\n"
        /* } scope */
        ".Lfa3dbe_000a3e96:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 822 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm2, %xmm6\n" /* blendFactor */
        "addss %xmm6, %xmm5\n" /* blendFactor */
        "mulss 8(%ecx), %xmm5\n"
        "movss %xmm5, -0x24(%ebp)\n" /* sampledVel */
        "movl 8(%ebp), %edx\n" /* line 823 | this */
        "movss 0x13c(%edx), %xmm6\n" /* blendFactor */
        "movl %edx, %ebx\n" /* source1 */
        "addl $0x234, %ebx\n" /* source1 */
        "movl %edx, %ecx\n" /* source0 */
        "addl $0x210, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x210(%edx), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a4468\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4171\n"
        /* } scope */
        ".Lfa3dbe_000a3f37:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm5\n" /* line 56 */
        "subss %xmm1, %xmm5\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm5\n"
        "addss %xmm2, %xmm5\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a444a\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4190\n"
        /* } scope */
        ".Lfa3dbe_000a3fa1:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 823 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm2, %xmm6\n" /* blendFactor */
        "addss %xmm6, %xmm5\n" /* blendFactor */
        "mulss 8(%ecx), %xmm5\n"
        "movss %xmm5, -0x20(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 824 | this */
        "movss 0x140(%edx), %xmm5\n" /* blendFactor */
        "movl %edx, %ebx\n" /* source1 */
        "addl $0x240, %ebx\n" /* source1 */
        "movl %edx, %ecx\n" /* source0 */
        "addl $0x21c, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x21c(%edx), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a4428\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a41af\n"
        /* } scope */
        ".Lfa3dbe_000a4042:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm3\n" /* line 56 */
        "subss %xmm1, %xmm3\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a440a\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a41ce\n"
        /* } scope */
        ".Lfa3dbe_000a40ac:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm4\n" /* line 824 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "subss %xmm3, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm3\n" /* blendFactor */
        "mulss 8(%ecx), %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        ".Lfa3dbe_000a40f7:\n"
        "movl 8(%ebp), %edx\n" /* line 833 | this */
        "testb $0x40, 0xaa(%edx)\n"
        "je .Lfa3dbe_000a41ed\n"
        "movl 0x14(%ebp), %eax\n" /* line 835 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa3dbe_000a41f8\n"
        "movl 0x10(%ebp), %eax\n" /* line 836 | outVector */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* sampledVel */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* or_ */
        "movl %edx, (%esp)\n"
        "calll OrientationDirFromWorldDir\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 847 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a4133:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3e2c\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4133\n"
        "jmp .Lfa3dbe_000a3e2c\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a4152:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3e96\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4152\n"
        "jmp .Lfa3dbe_000a3e96\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a4171:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3f37\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4171\n"
        "jmp .Lfa3dbe_000a3f37\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a4190:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3fa1\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4190\n"
        "jmp .Lfa3dbe_000a3fa1\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a41af:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4042\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a41af\n"
        "jmp .Lfa3dbe_000a4042\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a41ce:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a40ac\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a41ce\n"
        "jmp .Lfa3dbe_000a40ac\n"
        /* } scope */
        /* } scope */
        ".Lfa3dbe_000a41ed:\n"
        "movl 0x14(%ebp), %eax\n" /* line 842 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa3dbe_000a4530\n"
        ".Lfa3dbe_000a41f8:\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | sampledVel */
        "movl 0x10(%ebp), %edx\n" /* outVector */
        "movl %eax, (%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lfa3dbe_000a420c:\n"
        "addl $0x3c, %esp\n" /* line 847 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa3dbe_000a4214:\n"
        "movl %eax, %ecx\n"
        /* { scope 1 */
        "addl $0x204, %ecx\n" /* line 828 | source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x204(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a450e\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43ad\n"
        /* } scope */
        ".Lfa3dbe_000a4257:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 828 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss 8(%ecx), %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* sampledVel */
        "movl 8(%ebp), %ecx\n" /* line 829 | this, source */
        "addl $0x210, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x210(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a44ec\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43cc\n"
        /* } scope */
        ".Lfa3dbe_000a42df:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 829 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss 8(%ecx), %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 830 | this, source */
        "addl $0x21c, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x21c(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a44ca\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43eb\n"
        /* } scope */
        ".Lfa3dbe_000a4367:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm4\n" /* line 830 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "jmp .Lfa3dbe_000a40f7\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a43ad:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4257\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43ad\n"
        "jmp .Lfa3dbe_000a4257\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a43cc:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a42df\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43cc\n"
        "jmp .Lfa3dbe_000a42df\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a43eb:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4367\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43eb\n"
        "jmp .Lfa3dbe_000a4367\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a440a:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a40ac\n"
        "jmp .Lfa3dbe_000a41ce\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a4428:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4042\n"
        "jmp .Lfa3dbe_000a41af\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a444a:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3fa1\n"
        "jmp .Lfa3dbe_000a4190\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a4468:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3f37\n"
        "jmp .Lfa3dbe_000a4171\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a448a:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3e96\n"
        "jmp .Lfa3dbe_000a4152\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a44a8:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3e2c\n"
        "jmp .Lfa3dbe_000a4133\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a44ca:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4367\n"
        "jmp .Lfa3dbe_000a43eb\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a44ec:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a42df\n"
        "jmp .Lfa3dbe_000a43cc\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a450e:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4257\n"
        "jmp .Lfa3dbe_000a43ad\n"
        /* } scope */
        /* } scope */
        ".Lfa3dbe_000a4530:\n"
        "movl 0x10(%ebp), %eax\n" /* line 845 | outVector */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* sampledVel */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0xd0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "jmp .Lfa3dbe_000a420c\n"
    );
}

/* Particle_GetTotalVelocity — compute total velocity (vel1 + vel2 + gravity + impact offset) at normTime */
void Particle_GetTotalVelocity(const Particle *_this, float normTime, vec_t *outVector, const orientation_t *or_)
{
    byte *self = (byte *)_this;
    vec3_t velocityValue, velocity2Value, gravityValue;

    Particle_CalcVelocityValue(_this, normTime, velocityValue, or_);
    Particle_CalcVelocity2Value(_this, normTime, velocity2Value, or_);

    /* Compute gravity contribution */
    int lifetime = *(int *)(self + 0xbc) - *(int *)(self + 0xb8);
    int duration = (int)((float)lifetime * normTime);
    gravityValue[0] = 0.0f;
    gravityValue[1] = 0.0f;
    float gravZ = (float)duration * *(float *)(self + 0xf4) * 0.001f;

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

    /* Sum all velocity components + impact offset at 0xc4 */
    outVector[0] = velocityValue[0] + velocity2Value[0] + gravityValue[0] + *(float *)(self + 0xc4);
    outVector[1] = velocityValue[1] + velocity2Value[1] + gravityValue[1] + *(float *)(self + 0xc8);
    outVector[2] = velocityValue[2] + velocity2Value[2] + gravityValue[2] + *(float *)(self + 0xcc);
}

/* Emitter_UpdateEmitFx — spawn sub-effects along emitter trajectory at step intervals */
void Emitter_UpdateEmitFx(const Emitter *_this, vec_t *bindVelocity, const orientation_t *or_)
{
    byte *self = (byte *)_this;

    /* Check emit flag */
    if (!(*(byte *)(self + 0xa9) & 1))
        return;

    byte *helper = *(byte **)imp_theFxHelper;
    int frameTimeMs = *(int *)(helper + 0xc);
    if (frameTimeMs == 0)
        return;

    float step = *(float *)(self + 0x274);
    float step2 = step * step;
    int t = *(int *)(self + 0x270);
    int startTime = *(int *)(self + 0xb8);
    float age = (float)(*(int *)(helper + 4) - startTime) * 0.001f;
    float lifeTime = (float)(*(int *)(self + 0xbc) - startTime) * 0.001f;

    int dif = 0;
    float ftimeTotal = 0.0f;

    /* Time-stepping loop: advance by 12ms per step */
    while (t < *(int *)(helper + 4)) {
        dif += 12;
        float ftime = (float)dif * 0.001f;

        /* Save old position */
        vec3_t oldorg;
        oldorg[0] = *(float *)(self + 0x24c) + *(float *)(self + 0x264);
        oldorg[1] = *(float *)(self + 0x250) + *(float *)(self + 0x268);
        oldorg[2] = *(float *)(self + 0x254) + *(float *)(self + 0x26c);

        /* Compute normalized time */
        float normTime = (ftimeTotal + age) / lifeTime;
        if (normTime > 1.0f) normTime = 1.0f;

        /* Get velocity at normTime */
        vec3_t velocity;
        Particle_GetTotalVelocity((const Particle *)_this, normTime, velocity, or_);

        /* Compute new position = base + velocity * ftime */
        vec3_t org;
        org[0] = *(float *)(self + 0x24c) + velocity[0] * ftime;
        org[1] = *(float *)(self + 0x250) + velocity[1] * ftime;
        org[2] = *(float *)(self + 0x254) + velocity[2] * ftime;

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
        void *boltInfo = NULL;
        if (*(byte **)(self + 0xc0))
            boltInfo = (byte *)(*(byte **)(self + 0xc0)) + 0x3c;

        void *emitEffect = *(void **)(self + 0x290);
        FxScheduler_PlayEffect(*(void **)imp_theFxScheduler, emitEffect, spawnPos, NULL);

        /* Advance with adaptive time step based on velocity */
        float velLenSq = velocity[0]*velocity[0] + velocity[1]*velocity[1] + velocity[2]*velocity[2];
        float dF = (velLenSq + velLenSq) * ftime;
        float nextFtime;
        if (dF != 0.0f) {
            /* Adaptive: nextFtime based on step/velocity ratio */
            float sq; __asm__ __volatile__("sqrtss %1,%0":"=x"(sq):"x"(step2 / dF));
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
        *(float *)(self + 0x24c) = org[0];
        *(float *)(self + 0x250) = org[1];
        *(float *)(self + 0x254) = org[2];
        *(float *)(self + 0x264) = nextVel[0] * nextFtime - velocity[0] * ftime;
        *(float *)(self + 0x268) = nextVel[1] * nextFtime - velocity[1] * ftime;
        *(float *)(self + 0x26c) = nextVel[2] * nextFtime - velocity[2] * ftime;

        ftimeTotal += nextFtime;
        dif = (int)(ftimeTotal * 1000.0f);
        t = startTime + dif;
        *(int *)(self + 0x270) = t;
    }
}
#if 0 /* Original ASM (367 lines) */
__attribute__((naked))
void Emitter_UpdateEmitFx_asm(const Emitter * _this, vec_t *bindVelocity, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1911 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: time, worldorg */
        "testb $1, 0xa9(%ebx)\n" /* line 1927 | this */
        "je .Lfa467a_000a48c2\n"
        "movl imp_theFxHelper, %ecx\n" /* line 1930 */
        "movl (%ecx), %eax\n"
        "movl 0xc(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfa467a_000a48c2\n"
        "movss 0x274(%ebx), %xmm0\n" /* line 1937 | this */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n" /* step2 */
        "movl 0x270(%ebx), %esi\n" /* line 1942 | this, t */
        "movl 0xb8(%ebx), %edx\n" /* line 261 */
        "movl 4(%eax), %eax\n" /* line 1944 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x88(%ebp)\n" /* age */
        "movl 0xbc(%ebx), %eax\n" /* line 1945 | this */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n" /* lifeTime */
        "xorl %edi, %edi\n" /* dif */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n" /* ftimeTotal */
        "leal 0x264(%ebx), %eax\n" /* this */
        "movl %eax, -0xa4(%ebp)\n"
        "leal 0x24c(%ebx), %edx\n" /* this */
        "movl %edx, -0xa8(%ebp)\n"
        "leal 0x250(%ebx), %eax\n" /* this */
        "movl %eax, -0xac(%ebp)\n"
        "leal 0x268(%ebx), %edx\n" /* this */
        "movl %edx, -0xb0(%ebp)\n"
        "leal 0x254(%ebx), %eax\n" /* this */
        "movl %eax, -0xb4(%ebp)\n"
        "leal 0x26c(%ebx), %edx\n" /* this */
        "movl %edx, -0xb8(%ebp)\n"
        ".Lfa467a_000a4754:\n"
        "movl (%ecx), %eax\n" /* line 1949 */
        "cmpl 4(%eax), %esi\n" /* t */
        "jge .Lfa467a_000a48c2\n"
        ".Lfa467a_000a475f:\n"
        "addl $0xc, %edi\n" /* line 1951 | dif */
        "cvtsi2ssl %edi, %xmm0\n" /* line 1954 | dif */
        "movss %xmm0, -0xa0(%ebp)\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x94(%ebp)\n" /* ftime */
        "movss 0x24c(%ebx), %xmm0\n" /* line 240 */
        "addss 0x264(%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* oldorg */
        "movss 0x250(%ebx), %xmm0\n" /* line 241 */
        "addss 0x268(%ebx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 0x254(%ebx), %xmm0\n" /* line 242 */
        "addss 0x26c(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss -0x8c(%ebp), %xmm1\n" /* line 1966 | ftimeTotal */
        "addss -0x88(%ebp), %xmm1\n" /* age */
        "movss %xmm1, -0x80(%ebp)\n" /* time */
        /* { scope 2 */
        "divss -0x84(%ebp), %xmm1\n" /* line 588 | lifeTime */
        "movss lit4_002ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss %xmm1, %xmm0\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 1967 | or_ */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* velocity */
        "movl %edx, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_GetTotalVelocity\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 288 | ftime */
        "mulss -0x48(%ebp), %xmm0\n" /* velocity */
        "addss 0x24c(%ebx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* org */
        "movss -0x94(%ebp), %xmm0\n" /* line 289 | ftime */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss 0x250(%ebx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 290 | ftime */
        "mulss -0x40(%ebp), %xmm0\n"
        "addss 0x254(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1972 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa467a_000a4885\n"
        "movl $1, %edx\n"
        "leal -0x20(%ebp), %eax\n"
        ".Lfa467a_000a485f:\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 1977 | ftime */
        "movl 0xc(%ebp), %ecx\n" /* bindVelocity */
        "mulss -4(%ecx, %edx, 4), %xmm0\n"
        "addss -4(%eax), %xmm0\n"
        "movss %xmm0, -4(%eax)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 1976 */
        "jne .Lfa467a_000a485f\n"
        ".Lfa467a_000a4885:\n"
        "leal -0x30(%ebp), %eax\n" /* line 1983 | oldorg */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* org */
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x98(%ebp)\n"
        "movss -0x90(%ebp), %xmm0\n" /* step2 */
        "ucomiss -0x98(%ebp), %xmm0\n"
        "jbe .Lfa467a_000a48cd\n"
        "addl $0xc, %esi\n" /* line 1985 | t */
        "movl imp_theFxHelper, %ecx\n"
        "movl (%ecx), %eax\n" /* line 1949 */
        "cmpl 4(%eax), %esi\n" /* t */
        "jl .Lfa467a_000a475f\n"
        /* } scope */
        ".Lfa467a_000a48c2:\n"
        "addl $0xec, %esp\n" /* line 2082 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: time, worldorg */
        ".Lfa467a_000a48cd:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1990 | or_ */
        "testl %ecx, %ecx\n"
        "je .Lfa467a_000a4bb9\n"
        /* { scope 2 */
        "leal -0x54(%ebp), %eax\n" /* line 1993 | worldorg */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* org */
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* or_ */
        "movl %ecx, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        "movl 0xc0(%ebx), %eax\n" /* line 1994 | this */
        "addl $0x3c, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* worldorg */
        /* } scope */
        ".Lfa467a_000a4909:\n"
        "movl %eax, 8(%esp)\n" /* line 2015 */
        "movl 0x290(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl imp_theFxScheduler, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        /* { scope 2 */
        "movss -0x48(%ebp), %xmm2\n" /* line 304 | velocity */
        "movss -0x44(%ebp), %xmm0\n"
        "movss -0x40(%ebp), %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "movss -0x94(%ebp), %xmm1\n" /* line 2024 | ftime, t2 */
        "mulss %xmm1, %xmm1\n" /* t2 */
        "movaps %xmm2, %xmm0\n" /* line 2026 | dF */
        "addss %xmm2, %xmm0\n" /* dF */
        "mulss -0x94(%ebp), %xmm0\n" /* ftime, dF */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 2027 | 0.0f */
        "jne .Lfa467a_000a4ab4\n"
        "jp .Lfa467a_000a4ab4\n"
        "movss -0x94(%ebp), %xmm1\n" /* ftime */
        "addss -0x80(%ebp), %xmm1\n" /* time */
        "divss -0x84(%ebp), %xmm1\n" /* lifeTime */
        /* } scope */
        ".Lfa467a_000a498c:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2052 | or_ */
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* v */
        "movl %eax, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_GetTotalVelocity\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | org */
        "movl -0xa8(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x258(%ebx), %edx\n" /* line 2061 | this, to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | v */
        "movl %eax, 0x258(%ebx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x10(%ebp), %edx\n" /* line 2065 | or_ */
        "testl %edx, %edx\n"
        "je .Lfa467a_000a4a40\n"
        "movss -0xa0(%ebp), %xmm0\n" /* line 2069 | scale */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f, scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 288 */
        "movl 0xc(%ebp), %ecx\n" /* bindVelocity */
        "mulss (%ecx), %xmm1\n"
        "movl -0xa4(%ebp), %eax\n"
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss 4(%ecx), %xmm1\n"
        "movl -0xb0(%ebp), %edx\n"
        "addss (%edx), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 290 */
        "movl -0xb8(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        ".Lfa467a_000a4a40:\n"
        "movl %edi, %esi\n" /* line 2073 | dif, t */
        "addl 0x270(%ebx), %esi\n" /* this, t */
        "movl %esi, 0x270(%ebx)\n" /* t, this */
        "movss -0x8c(%ebp), %xmm0\n" /* line 2074 | ftimeTotal */
        "addss -0x94(%ebp), %xmm0\n" /* ftime */
        "movss %xmm0, -0x8c(%ebp)\n" /* ftimeTotal */
        "movss 0x294(%ebx), %xmm1\n" /* line 668 */
        "movss %xmm1, -0x7c(%ebp)\n"
        "calll crandom\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm0\n"
        "mulss 0x298(%ebx), %xmm0\n"
        "addss -0x7c(%ebp), %xmm0\n"
        "movss %xmm0, 0x274(%ebx)\n"
        "mulss %xmm0, %xmm0\n" /* line 2080 */
        "movss %xmm0, -0x90(%ebp)\n" /* step2 */
        "xorl %edi, %edi\n" /* dif */
        "movl imp_theFxHelper, %ecx\n"
        "jmp .Lfa467a_000a4754\n"
        /* { scope 2 */
        ".Lfa467a_000a4ab4:\n"
        "mulss %xmm1, %xmm2\n" /* line 428 */
        "subss -0x90(%ebp), %xmm2\n" /* step2 */
        "divss %xmm0, %xmm2\n"
        "mulss lit4_002ed5c8, %xmm2\n" /* 1000.0f */
        "addss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "movss %xmm2, (%esp)\n"
        "calll floorf\n"
        "fstps -0x9c(%ebp)\n"
        "cvttss2si -0x9c(%ebp), %eax\n"
        "subl %eax, %edi\n"
        "movl %esi, %eax\n" /* line 2033 | t */
        "subl 0x270(%ebx), %eax\n" /* this */
        "cmpl %eax, %edi\n" /* dif */
        "cmovll %eax, %edi\n" /* dif */
        "cvtsi2ssl %edi, %xmm0\n" /* line 2039 | dif */
        "movss %xmm0, -0xa0(%ebp)\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x94(%ebp)\n" /* ftime */
        "movss -0x80(%ebp), %xmm1\n" /* line 588 | time */
        "addss %xmm0, %xmm1\n"
        "divss -0x84(%ebp), %xmm1\n" /* lifeTime */
        "movss lit4_002ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movl 0x10(%ebp), %eax\n" /* line 2041 | or_ */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* velocity */
        "movl %edx, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "movss %xmm1, -0xc8(%ebp)\n"
        "calll Particle_GetTotalVelocity\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 288 | ftime */
        "mulss -0x48(%ebp), %xmm0\n" /* velocity */
        "movl -0xa8(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* org */
        "movss -0x94(%ebp), %xmm0\n" /* line 289 | ftime */
        "mulss -0x44(%ebp), %xmm0\n"
        "movl -0xac(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 290 | ftime */
        "mulss -0x40(%ebp), %xmm0\n"
        "movl -0xb4(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0xc8(%ebp), %xmm1\n"
        "jmp .Lfa467a_000a498c\n"
        /* } scope */
        ".Lfa467a_000a4bb9:\n"
        "movss -0x48(%ebp), %xmm3\n" /* line 324 | velocity */
        "movss -0x44(%ebp), %xmm0\n"
        "movss -0x40(%ebp), %xmm2\n"
        "movaps %xmm3, %xmm1\n" /* line 81 */
        "mulss %xmm3, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 1999 | 0.0f */
        "jbe .Lfa467a_000a4c48\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 2001 | 1.0f, scale */
        "divss %xmm1, %xmm0\n" /* scale */
        /* { scope 2 */
        "mulss %xmm0, %xmm3\n" /* line 272 */
        "movss %xmm3, -0x78(%ebp)\n" /* newEffectAxis */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x44(%ebp), %xmm1\n"
        "movss %xmm1, -0x74(%ebp)\n"
        "mulss -0x40(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x70(%ebp)\n"
        /* } scope */
        "leal -0x60(%ebp), %eax\n" /* line 2002 */
        "movl %eax, 8(%esp)\n"
        "leal -0x6c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %edx\n" /* newEffectAxis */
        "movl %edx, (%esp)\n"
        "calll MakeNormalVectors\n"
        ".Lfa467a_000a4c31:\n"
        "movl $0, 0x10(%esp)\n" /* line 2015 */
        "leal -0x78(%ebp), %ecx\n" /* newEffectAxis */
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* org */
        "jmp .Lfa467a_000a4909\n"
        ".Lfa467a_000a4c48:\n"
        "leal 0x48(%ebx), %edx\n" /* line 2002 | this */
        /* { scope 2 */
        "movl 0x48(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x78(%ebp)\n" /* newEffectAxis */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x70(%ebp)\n"
        "leal 0x54(%ebx), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x54(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x68(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x64(%ebp)\n"
        "leal 0x60(%ebx), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x60(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x60(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "jmp .Lfa467a_000a4c31\n"
    );
}
#endif

/* Particle_GetTotalVelocityAtTime0 — get velocity at t=0 using bolt orientation if available */
extern void *imp_cl;
void Particle_GetTotalVelocityAtTime0(const Particle *_this, vec_t *outVector)
{
    byte *self = (byte *)_this;
    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;

    if (boltFrame) {
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx < 0) {
            outVector[0] = outVector[1] = outVector[2] = 0.0f;
            return;
        }
        int curTime = *(int *)(*(int *)imp_cl + 0x864c);
        if (curTime != *(int *)(boltFrame + 4)) {
            *(int *)(boltFrame + 4) = curTime;
            Bool ok = FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8));
            if (!ok) {
                *(int *)(boltFrame + 0x3c) = -1;
                *(int *)(boltFrame + 0x40) = -1;
                outVector[0] = outVector[1] = outVector[2] = 0.0f;
                return;
            }
        }
        orient = boltFrame + 8;
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
        int flags = *(int *)(self + 0xa8);
        flags &= ~0x0800; /* clear bit 11 */
        flags &= ~0x0020; /* clear bit 5 */
        flags |= 0x01000000; /* set bit 24 */
        *(int *)(self + 0xa8) = flags;
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
    float oldVx = reflectVelocity[0] - *(float *)(self + 0xc4);
    float oldVy = reflectVelocity[1] - *(float *)(self + 0xc8);
    float oldVz = reflectVelocity[2] - *(float *)(self + 0xcc);

    /* Scale velocity by bounce coefficient */
    float bounceScale = *(float *)(self + 0x100);
    reflectVelocity[0] *= bounceScale;
    reflectVelocity[1] *= bounceScale;
    reflectVelocity[2] *= bounceScale;

    /* Update impact offset = scaled - old */
    *(float *)(self + 0xc4) = reflectVelocity[0] - oldVx;
    *(float *)(self + 0xc8) = reflectVelocity[1] - oldVy;
    *(float *)(self + 0xcc) = reflectVelocity[2] - oldVz;

    /* Compute reflection: v' = v + 2 * (-dot(v, n)) * n */
    float dot = reflectVelocity[0]*normal[0] + reflectVelocity[1]*normal[1] + reflectVelocity[2]*normal[2];
    float reflScale = -2.0f * dot;
    *(float *)(self + 0xc4) += reflScale * normal[0];
    *(float *)(self + 0xc8) += reflScale * normal[1];
    *(float *)(self + 0xcc) += reflScale * normal[2];
}
#if 0 /* Original ASM preserved */
__attribute__((naked))
void Particle_ApplyImpact_asm(const Particle * _this, const orientation_t *or_, float normTime, const vec_t *velocity, float traceFraction, const vec_t *traceNormal)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 621 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* velocity */
        "movl 0x1c(%ebp), %edx\n" /* traceNormal */
        /* { scope 1 */
        "leal 8(%edx), %ecx\n" /* line 602 */
        "pxor %xmm3, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa4d30_000a4d80\n"
        "movss (%eax), %xmm0\n" /* line 316 */
        "movss 4(%eax), %xmm1\n"
        "movss 8(%eax), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 602 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "ucomiss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "jb .Lfa4d30_000a4ebc\n"
        ".Lfa4d30_000a4d80:\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 607 | traceFraction */
        "ucomiss %xmm3, %xmm0\n"
        "jp .Lfa4d30_000a4d90\n"
        "je .Lfa4d30_000a4ec2\n"
        ".Lfa4d30_000a4d90:\n"
        "movl 0xc(%ebp), %eax\n" /* line 636 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa4d30_000a4ede\n"
        "leal -0x14(%ebp), %eax\n" /* line 637 | normal */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* or_ */
        "movl %eax, (%esp)\n"
        "calll OrientationDirFromWorldDir\n"
        ".Lfa4d30_000a4db1:\n"
        "movl 0xc(%ebp), %eax\n" /* line 641 | or_ */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* reflectVelocity */
        "movl %eax, 8(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* normTime */
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_GetTotalVelocity\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 248 | reflectVelocity */
        "movaps %xmm0, %xmm5\n"
        "subss 0xc4(%ebx), %xmm5\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 249 */
        "subss 0xc8(%ebx), %xmm1\n"
        "movss -0x18(%ebp), %xmm4\n" /* line 250 */
        "subss 0xcc(%ebx), %xmm4\n"
        "movss 0x100(%ebx), %xmm2\n" /* line 646 | this, scale */
        /* { scope 2 */
        "mulss %xmm2, %xmm0\n" /* line 272 */
        "movss %xmm0, -0x20(%ebp)\n" /* reflectVelocity */
        "movaps %xmm2, %xmm3\n" /* line 273 */
        "mulss -0x1c(%ebp), %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        "mulss -0x18(%ebp), %xmm2\n" /* line 274 */
        "movss %xmm2, -0x18(%ebp)\n"
        /* } scope */
        "subss %xmm5, %xmm0\n" /* line 248 */
        "movss %xmm0, 0xc4(%ebx)\n"
        "movaps %xmm3, %xmm0\n" /* line 249 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc8(%ebx)\n"
        "movaps %xmm2, %xmm0\n" /* line 250 */
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, 0xcc(%ebx)\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 304 | normal */
        "movaps %xmm0, %xmm1\n" /* line 655 | scale */
        "mulss -0x20(%ebp), %xmm1\n" /* reflectVelocity, scale */
        "mulss -0x10(%ebp), %xmm3\n"
        "addss %xmm3, %xmm1\n" /* scale */
        "mulss -0xc(%ebp), %xmm2\n"
        "addss %xmm2, %xmm1\n" /* scale */
        "mulss lit4_002ed628, %xmm1\n" /* -2.0f, scale */
        /* { scope 2 */
        "mulss %xmm1, %xmm0\n" /* line 288 */
        "addss 0xc4(%ebx), %xmm0\n"
        "movss %xmm0, 0xc4(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x10(%ebp), %xmm0\n"
        "addss 0xc8(%ebx), %xmm0\n"
        "movss %xmm0, 0xc8(%ebx)\n"
        "mulss -0xc(%ebp), %xmm1\n" /* line 290 */
        "addss 0xcc(%ebx), %xmm1\n"
        "movss %xmm1, 0xcc(%ebx)\n"
        /* } scope */
        /* } scope */
        "addl $0x34, %esp\n" /* line 657 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa4d30_000a4ebc:\n"
        "jp .Lfa4d30_000a4d80\n" /* line 602 */
        ".Lfa4d30_000a4ec2:\n"
        "movl 0xa8(%ebx), %eax\n" /* line 616 */
        "andl $0xfffff7df, %eax\n"
        "orl $0x01000000, %eax\n" /* line 617 */
        "movl %eax, 0xa8(%ebx)\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 657 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa4d30_000a4ede:\n"
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n" /* normal */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        "jmp .Lfa4d30_000a4db1\n"
    );
}
#endif

/* Particle_UpdateOrigin — integrate velocity, trace collision, apply impact, update position */
extern void FxHelper_Trace(void *helper, void *trace, vec_t *start, vec_t *mins, vec_t *maxs, vec_t *end, int contents, int mask);
extern void *imp_vec3_origin;
Bool Particle_UpdateOrigin(const Particle *_this, const orientation_t *or_)
{
    byte *self = (byte *)_this;

    /* Check locked flag */
    if (*(byte *)(self + 0xab) & 1)
        return 1;

    /* Get frame time */
    byte *helper = *(byte **)imp_theFxHelper;
    int frameTimeMs = *(int *)(helper + 0xc);
    if (frameTimeMs == 0)
        return 1;

    float ftime = (float)frameTimeMs * 0.001f;
    int startTime = *(int *)(self + 0xb8);
    float age = (float)(*(int *)(helper + 4) - startTime) * 0.001f;
    float lifeTime = (float)(*(int *)(self + 0xbc) - startTime) * 0.001f;
    float normTime = age / lifeTime;
    if (normTime > 1.0f) normTime = 1.0f;

    /* Get total velocity at normTime */
    vec3_t velocity;
    Particle_GetTotalVelocity(_this, normTime, velocity, or_);

    /* Compute new origin = old + velocity * ftime */
    float *origin = (float *)(self + 4);
    vec3_t new_origin;
    new_origin[0] = origin[0] + velocity[0] * ftime;
    new_origin[1] = origin[1] + velocity[1] * ftime;
    new_origin[2] = origin[2] + velocity[2] * ftime;

    /* Check for collision trace */
    int flags = *(int *)(self + 0xa8);
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
                FxScheduler_PlayEffect(*(void **)imp_theFxScheduler, *(void **)(self + 0x2c), endpos, (vec_t *)(trace + 0x24));
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
            Particle_ApplyImpact(_this, or_, newNormTime, velocity, fraction, (vec_t *)(trace + 0x24));

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
#if 0 /* Original ASM (263 lines) */
__attribute__((naked))
Bool Particle_UpdateOrigin_asm(const Particle * _this, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 677 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "testb $1, 0xab(%ebx)\n" /* line 694 | this */
        "jne .Lfa4ef4_000a510f\n"
        "movl imp_theFxHelper, %eax\n" /* line 697 */
        "movl (%eax), %eax\n"
        "movl 0xc(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfa4ef4_000a510f\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 703 */
        "movss %xmm0, -0xac(%ebp)\n" /* ftime */
        "movss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss -0xac(%ebp), %xmm1\n" /* ftime */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0xac(%ebp)\n" /* ftime */
        "movl 0xb8(%ebx), %edx\n" /* line 261 */
        "movl 4(%eax), %eax\n" /* line 707 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0xa4(%ebp)\n" /* age */
        "movl 0xbc(%ebx), %eax\n" /* line 708 | this */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xa8(%ebp)\n" /* lifeTime */
        "movss -0xa4(%ebp), %xmm1\n" /* line 588 | age */
        "divss %xmm0, %xmm1\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* line 712 | or_ */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* velocity */
        "movl %eax, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_GetTotalVelocity\n"
        "leal 4(%ebx), %esi\n" /* line 714 | this */
        "movss -0xac(%ebp), %xmm2\n" /* line 288 | ftime */
        "mulss -0x3c(%ebp), %xmm2\n" /* velocity */
        "addss 4(%ebx), %xmm2\n"
        "movss %xmm2, -0x30(%ebp)\n" /* new_origin */
        "leal 8(%ebx), %eax\n" /* line 289 */
        "movl %eax, -0xa0(%ebp)\n"
        "movss -0xac(%ebp), %xmm1\n" /* ftime */
        "mulss -0x38(%ebp), %xmm1\n"
        "addss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "leal 0xc(%ebx), %eax\n" /* line 290 */
        "movl %eax, -0x9c(%ebp)\n"
        "movss -0xac(%ebp), %xmm0\n" /* ftime */
        "mulss -0x34(%ebp), %xmm0\n"
        "addss 0xc(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movl 0xa8(%ebx), %edx\n" /* line 719 | this */
        "testb $0x20, %dl\n"
        "je .Lfa4ef4_000a50ee\n"
        "movl 0xc(%ebp), %eax\n" /* line 721 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa4ef4_000a511f\n"
        "leal -0x60(%ebp), %eax\n" /* line 723 | start */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* or_ */
        "movl %eax, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        "leal -0x6c(%ebp), %edi\n" /* line 724 | end */
        "movl %edi, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* new_origin */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* or_ */
        "movl %eax, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        "movl 0xa8(%ebx), %edx\n" /* this */
        ".Lfa4ef4_000a505a:\n"
        "andb $0x40, %dl\n" /* line 734 */
        "je .Lfa4ef4_000a5148\n"
        "leal 0x14(%ebx), %edx\n" /* this */
        /* { scope 2 */
        "movl 0x14(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x48(%ebp)\n" /* mins */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x40(%ebp)\n"
        "leal 0x20(%ebx), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x20(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x54(%ebp)\n" /* maxs */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x50(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x4c(%ebp)\n"
        /* } scope */
        "movl $1, 0x1c(%esp)\n" /* line 738 */
        "movl $0xffffffff, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* maxs */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* mins */
        ".Lfa4ef4_000a50ab:\n"
        "movl %eax, 0xc(%esp)\n" /* line 742 */
        "leal -0x60(%ebp), %eax\n" /* start */
        "movl %eax, 8(%esp)\n"
        "leal -0x90(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_Trace\n"
        "cmpb $0, -0x6d(%ebp)\n" /* line 664 */
        "jne .Lfa4ef4_000a50ee\n"
        "cmpb $0, -0x6e(%ebp)\n" /* line 667 */
        "jne .Lfa4ef4_000a50ee\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 670 | 1.0f */
        "ucomiss -0x90(%ebp), %xmm0\n" /* trace */
        "jp .Lfa4ef4_000a516a\n"
        "jne .Lfa4ef4_000a516a\n"
        ".Lfa4ef4_000a50ee:\n"
        "movl -0x30(%ebp), %eax\n" /* line 199 | new_origin */
        "movl %eax, (%esi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 779 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa4ef4_000a510f:\n"
        "movl $1, %eax\n" /* line 778 */
        /* } scope */
        ".Lfa4ef4_000a5114:\n"
        "addl $0xcc, %esp\n" /* line 779 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa4ef4_000a511f:\n"
        "movl 4(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x60(%ebp)\n" /* start */
        "movl 8(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "movss %xmm2, -0x6c(%ebp)\n" /* line 199 | end */
        "movss %xmm1, -0x68(%ebp)\n" /* line 200 */
        "movss %xmm0, -0x64(%ebp)\n" /* line 201 */
        "leal -0x6c(%ebp), %edi\n" /* end */
        "jmp .Lfa4ef4_000a505a\n"
        ".Lfa4ef4_000a5148:\n"
        "movl $1, 0x1c(%esp)\n" /* line 742 */
        "movl $0xffffffff, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "movl imp_vec3_origin, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "jmp .Lfa4ef4_000a50ab\n"
        ".Lfa4ef4_000a516a:\n"
        "movl 0xa8(%ebx), %edx\n" /* line 748 | this */
        "testb $8, %dh\n"
        "je .Lfa4ef4_000a51ff\n"
        "movss -0x90(%ebp), %xmm2\n" /* line 750 | trace, fraction */
        /* { scope 2 */
        "movss -0x60(%ebp), %xmm1\n" /* line 1203 | start */
        "movss -0x6c(%ebp), %xmm0\n" /* end */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* endpos */
        "movss -0x5c(%ebp), %xmm1\n" /* line 1204 */
        "movss -0x68(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x58(%ebp), %xmm1\n" /* line 1205 */
        "movss -0x64(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "leal -0x8c(%ebp), %eax\n" /* line 751 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* endpos */
        "movl %eax, 8(%esp)\n"
        "movl 0x2c(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl imp_theFxScheduler, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        "movl 0xa8(%ebx), %edx\n" /* this */
        ".Lfa4ef4_000a51ff:\n"
        "andb $4, %dh\n" /* line 754 */
        "jne .Lfa4ef4_000a52eb\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 761 | trace */
        "movss -0xac(%ebp), %xmm0\n" /* line 588 | ftime */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xac(%ebp)\n" /* ftime */
        "movss -0xa4(%ebp), %xmm0\n" /* age */
        "addss -0xac(%ebp), %xmm0\n" /* ftime */
        "divss -0xa8(%ebp), %xmm0\n" /* lifeTime */
        "movss %xmm0, -0xa4(%ebp)\n" /* age */
        "movss lit4_002ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss -0xa4(%ebp), %xmm0\n" /* age */
        "leal -0x8c(%ebp), %eax\n" /* line 762 */
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm1, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* velocity */
        "movl %eax, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* or_ */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_ApplyImpact\n"
        "movss -0x90(%ebp), %xmm2\n" /* line 766 | trace, fraction */
        /* { scope 2 */
        "movss (%esi), %xmm1\n" /* line 1203 */
        "movss -0x30(%ebp), %xmm0\n" /* new_origin */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movl -0xa0(%ebp), %eax\n" /* line 1204 */
        "movss (%eax), %xmm1\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movl -0x9c(%ebp), %eax\n" /* line 1205 */
        "movss (%eax), %xmm1\n"
        "movss -0x28(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        "movl $1, %eax\n"
        "jmp .Lfa4ef4_000a5114\n"
        /* } scope */
        ".Lfa4ef4_000a52eb:\n"
        "xorl %eax, %eax\n" /* line 754 */
        "jmp .Lfa4ef4_000a5114\n"
    );
}
#endif

/* Emitter_Update — full emitter tick: normTime, bolt, origin, emit sub-effects, endpoint, radius, RGB, alpha */
Bool Emitter_Update(const Emitter *_this)
{
    byte *self = (byte *)_this;
    int startTime = *(int *)(self + 0xb8);
    int killTime = *(int *)(self + 0xbc);
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;

    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    *(float *)(self + 0x3c) = normTime;
    if (normTime < 0.0f) return 0;

    /* Get bolt orientation */
    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx >= 0) {
            int clTime = *(int *)(*(byte *)imp_cl + 0x864c);
            if (*(int *)(boltFrame + 4) != clTime) {
                *(int *)(boltFrame + 4) = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8)))
                    { *(int *)(boltFrame + 0x3c) = -1; *(int *)(boltFrame + 0x40) = -1; }
            }
            if (*(int *)(boltFrame + 0x3c) >= 0)
                orient = boltFrame + 8;
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
        int frameTime = *(int *)(helper + 0xc);
        if (frameTime > 0) {
            float invFt = 1.0f / ((float)frameTime * 0.001f);
            vec3_t worldPos;
            OrientationPosToWorldPos(orient, (vec_t *)(self + 4), worldPos);
            bindVelocity[0] = (worldPos[0] - *(float *)(self + 0x7c)) * invFt;
            bindVelocity[1] = (worldPos[1] - *(float *)(self + 0x80)) * invFt;
            bindVelocity[2] = (worldPos[2] - *(float *)(self + 0x84)) * invFt;
            *(float *)(self + 0x7c) = worldPos[0];
            *(float *)(self + 0x80) = worldPos[1];
            *(float *)(self + 0x84) = worldPos[2];
        }
    } else {
        *(float *)(self + 0x7c) = *(float *)(self + 4);
        *(float *)(self + 0x80) = *(float *)(self + 8);
        *(float *)(self + 0x84) = *(float *)(self + 0xc);
    }

    /* Emit sub-effects */
    Emitter_UpdateEmitFx(_this, bindVelocity, (const orientation_t *)orient);

    /* Evaluate radius */
    float radius;
    if (*(short *)(self + 0xa8) < 0) {
        float bf = *(float *)(self + 0x120);
        float v0 = EvalCurve1(self + 0x174, normTime);
        float v1 = EvalCurve1(self + 0x180, normTime);
        radius = (v0 + (v1 - v0) * bf) * *(float *)(self + 0x174 + 8);
    } else {
        radius = EvalCurve1(self + 0x174, normTime) * *(float *)(self + 0x174 + 8);
    }
    *(float *)(self + 0x88) = radius;

    if (radius == 0.0f) {
        *(int *)(self + 0xa8) |= 0x01000000;
        return 1;
    }

    /* Update RGB and alpha */
    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);

    return 1;
}
#if 0 /* Original ASM (445 lines) */
__attribute__((naked))
Bool Emitter_Update_asm(const Emitter * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1833 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1: axis */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa52f2_000a56e9\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa52f2_000a5346\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa52f2_000a5346:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa52f2_000a5701\n"
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa52f2_000a56a3\n"
        ".Lfa52f2_000a5362:\n"
        "movl $0, -0x6c(%ebp)\n" /* or_ */
        ".Lfa52f2_000a5369:\n"
        "leal 4(%esi), %eax\n" /* line 1851 | this */
        "movl %eax, -0x70(%ebp)\n"
        "movss 4(%esi), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x50(%ebp)\n"
        "leal 8(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x68(%ebp)\n"
        "movss 8(%esi), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "leal 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x64(%ebp)\n"
        "movss 0xc(%esi), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1853 | or_ */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je .Lfa52f2_000a56e9\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 310 */
        "ucomiss 4(%esi), %xmm0\n"
        "jne .Lfa52f2_000a53d9\n"
        "jp .Lfa52f2_000a53d9\n"
        "movss -0x54(%ebp), %xmm0\n"
        "ucomiss 8(%esi), %xmm0\n"
        "jne .Lfa52f2_000a53d9\n"
        "jp .Lfa52f2_000a53d9\n"
        "movss -0x58(%ebp), %xmm0\n"
        "ucomiss 0xc(%esi), %xmm0\n"
        "je .Lfa52f2_000a583a\n"
        ".Lfa52f2_000a53d9:\n"
        "xorl %eax, %eax\n"
        ".Lfa52f2_000a53db:\n"
        "testl %eax, %eax\n" /* line 1858 */
        "je .Lfa52f2_000a56f6\n"
        "leal 0x284(%esi), %ecx\n" /* line 1859 | this */
        "movss lit4_002ed6ac, %xmm0\n" /* line 272 | 0.699999988079071f */
        "movss 0x284(%esi), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 0x284(%esi)\n"
        "movss 4(%ecx), %xmm1\n" /* line 273 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%ecx)\n"
        ".Lfa52f2_000a541d:\n"
        "movl imp_theFxHelper, %eax\n" /* line 2089 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0xc(%eax), %xmm1\n" /* scale */
        "mulss lit4_002ed738, %xmm1\n" /* 0.009999999776482582f, scale */
        "leal 0x278(%esi), %edx\n" /* this, result */
        /* { scope 2: keySize, i */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x284(%esi), %xmm0\n"
        "addss 0x278(%esi), %xmm0\n"
        "movss %xmm0, 0x278(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%ecx), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "mulss 8(%ecx), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, 8(%edx)\n"
        /* } scope */
        "leal 0x48(%esi), %eax\n" /* line 2090 | this */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll AnglesToAxis\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "jns .Lfa52f2_000a5725\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, i */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa52f2_000a54d5\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa52f2_000a54d5:\n"
        "movl -0x60(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa52f2_000a54ee\n"
        ".Lfa52f2_000a54e3:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa52f2_000a54e3\n"
        /* } scope */
        ".Lfa52f2_000a54ee:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edx\n" /* line 91 | key */
        "movl %edx, -0x80(%ebp)\n"
        "movl %edx, %edi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x7c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa52f2_000a57be\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x4c(%ebp)\n" /* keySize */
        ".Lfa52f2_000a5564:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa52f2_000a557a\n"
        ".Lfa52f2_000a556f:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa52f2_000a556f\n"
        /* } scope */
        ".Lfa52f2_000a557a:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x80(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        ".Lfa52f2_000a55cb:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1866 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa52f2_000a55dd\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x24(%ebp)\n" /* bindVelocity */
        "movl %eax, -0x20(%ebp)\n" /* line 184 */
        "movl %eax, -0x1c(%ebp)\n" /* line 185 */
        ".Lfa52f2_000a55dd:\n"
        "testb $0x10, 0xa8(%esi)\n" /* line 1869 | this */
        "je .Lfa52f2_000a567d\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1872 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa52f2_000a584a\n"
        /* { scope 2: keySize, i */
        "leal 0x7c(%esi), %eax\n" /* line 1876 | this */
        "movl %eax, 8(%esp)\n"
        "movl -0x70(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x6c(%ebp), %ebx\n" /* or_, source1 */
        "movl %ebx, (%esp)\n" /* source1 */
        "calll OrientationPosToWorldPos\n"
        "movl $0, -0x5c(%ebp)\n" /* i */
        "leal 0x40(%esi), %edi\n" /* this, keySize */
        "xorl %ebx, %ebx\n" /* source1 */
        /* { scope 3 */
        ".Lfa52f2_000a561a:\n"
        "leal -0x48(%ebp), %edx\n" /* line 1879 | axis, to */
        "addl %ebx, %edx\n" /* source1, to */
        "leal 8(%edi), %ecx\n" /* keySize */
        /* { scope 4 */
        "movl 0x48(%ebx, %esi), %eax\n" /* line 199 | key */
        "movl %eax, (%edx)\n"
        "movl 0x4c(%ebx, %esi), %eax\n" /* line 200 | key */
        "movl %eax, -0x44(%ebx, %ebp)\n" /* key */
        "movl 0x50(%ebx, %esi), %eax\n" /* line 201 | key */
        "movl %eax, -0x40(%ebx, %ebp)\n" /* key */
        /* } scope */
        "movl %ecx, 8(%esp)\n" /* line 1880 */
        "movl %edx, 4(%esp)\n"
        "movl -0x6c(%ebp), %eax\n" /* or_ */
        "movl %eax, (%esp)\n"
        "calll OrientationDirToWorldDir\n"
        "addl $1, -0x5c(%ebp)\n" /* line 1877 | i */
        "addl $0xc, %ebx\n" /* source1 */
        "addl $0xc, %edi\n" /* keySize */
        "cmpl $3, -0x5c(%ebp)\n" /* i */
        "jne .Lfa52f2_000a561a\n"
        /* } scope */
        "movl 0x88(%esi), %eax\n" /* line 1882 | this */
        "movl %eax, 0x98(%esi)\n" /* this */
        "movl imp_theFxHelper, %eax\n" /* line 1884 */
        "movl (%eax), %edx\n"
        "movl 0x270(%esi), %ecx\n" /* this */
        "cmpl 4(%edx), %ecx\n"
        "jl .Lfa52f2_000a57c6\n"
        ".Lfa52f2_000a567d:\n"
        "movl -0x6c(%ebp), %edi\n" /* or_, keySize */
        /* } scope */
        ".Lfa52f2_000a5680:\n"
        "movl %edi, 8(%esp)\n" /* line 1905 | keySize */
        "leal -0x24(%ebp), %eax\n" /* bindVelocity */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Emitter_UpdateEmitFx\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1908 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: axis */
        ".Lfa52f2_000a56a3:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, i */
        "movl 0x3c(%ebx), %eax\n" /* line 90 | key */
        "testl %eax, %eax\n"
        "js .Lfa52f2_000a56e9\n"
        "movl imp_cl, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa52f2_000a5715\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %edi\n" /* line 102 | key, keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa52f2_000a5718\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        ".Lfa52f2_000a56e9:\n"
        "xorl %eax, %eax\n" /* line 1907 */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1908 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa52f2_000a56f6:\n"
        "leal 0x284(%esi), %ecx\n" /* this */
        "jmp .Lfa52f2_000a541d\n"
        /* { scope 1: axis */
        ".Lfa52f2_000a5701:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa52f2_000a56a3\n"
        "jmp .Lfa52f2_000a5362\n"
        ".Lfa52f2_000a5715:\n"
        "leal 8(%ebx), %edi\n" /* key, keySize */
        /* { scope 2: keySize, i */
        ".Lfa52f2_000a5718:\n"
        "movl %edi, -0x6c(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa52f2_000a5369\n"
        "jmp .Lfa52f2_000a56e9\n"
        ".Lfa52f2_000a5725:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, i */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa52f2_000a575b\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa52f2_000a575b:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n" /* key */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa52f2_000a5775\n"
        ".Lfa52f2_000a576a:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa52f2_000a576a\n"
        /* } scope */
        ".Lfa52f2_000a5775:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "jmp .Lfa52f2_000a55cb\n"
        ".Lfa52f2_000a57be:\n"
        "movl -0x4c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa52f2_000a5564\n"
        /* { scope 2: keySize, i */
        ".Lfa52f2_000a57c6:\n"
        "leal 0x264(%esi), %eax\n" /* line 1889 | this, b */
        /* { scope 3 */
        "movl -0x6c(%ebp), %ebx\n" /* line 248 | or_, this */
        "movss (%ebx), %xmm0\n" /* this */
        "subss 0x264(%esi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* bindVelocity */
        "movss 4(%ebx), %xmm0\n" /* line 249 | this */
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%ebx), %xmm0\n" /* line 250 | this */
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "movl 4(%edx), %eax\n" /* line 1893 */
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f, scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm1\n" /* bindVelocity */
        "movss %xmm1, -0x24(%ebp)\n" /* bindVelocity */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl %ebx, %edi\n" /* this, keySize */
        "jmp .Lfa52f2_000a5680\n"
        /* } scope */
        /* } scope */
        ".Lfa52f2_000a583a:\n"
        "jp .Lfa52f2_000a53d9\n" /* line 310 */
        "movl $1, %eax\n"
        "jmp .Lfa52f2_000a53db\n"
        ".Lfa52f2_000a584a:\n"
        "leal 0x7c(%esi), %edx\n" /* line 1900 | this, to */
        /* { scope 2: keySize, i */
        "movl -0x70(%ebp), %edi\n" /* line 199 | keySize */
        "movl (%edi), %eax\n" /* keySize */
        "movl %eax, 0x7c(%esi)\n"
        "movl -0x68(%ebp), %ecx\n" /* line 200 */
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x64(%ebp), %ebx\n" /* line 201 | key */
        "movl (%ebx), %eax\n" /* key */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x88(%esi), %eax\n" /* line 1901 | this */
        "movl %eax, 0x98(%esi)\n" /* this */
        "movl -0x6c(%ebp), %edi\n" /* or_, keySize */
        "jmp .Lfa52f2_000a5680\n"
    );
}
#endif

/* Particle_UpdateAlpha — evaluate alpha channel at normTime, apply to particle */
void Particle_UpdateAlpha(const Particle *_this)
{
    byte *self = (byte *)_this;
    float normTime = *(float *)(self + 0x3c);
    float alpha;

    if (*(byte *)(self + 0xa9) & 0x40) {
        /* Blend path */
        float blendFactor = *(float *)(self + 0x11c);
        float v0 = EvalCurve1(self + 0x15c, normTime);
        float v1 = EvalCurve1(self + 0x168, normTime);
        alpha = v0 + (v1 - v0) * blendFactor;
    } else {
        alpha = EvalCurve1(self + 0x15c, normTime);
    }
    alpha *= *(float *)(self + 0x15c + 8); /* scale */

    /* Clamp and convert to byte */
    if (alpha < 0.0f) alpha = 0.0f;
    if (alpha > 1.0f) alpha = 1.0f;
    int a = (int)floorf(alpha * 255.0f + 0.5f);
    if (a < 0) a = 0;
    if (a > 255) a = 255;
    *(byte *)(self + 0x93) = (byte)a;
}
#if 0 /* Original ASM */
__attribute__((naked))
void Particle_UpdateAlpha_asm(const Particle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1058 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1062 | this */
        "testb $0x40, 0xa9(%eax)\n"
        "je .Lfa587c_000a5a92\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1063 */
        "movss 0x11c(%eax), %xmm5\n" /* blendFactor */
        "movl %eax, %ebx\n" /* source1 */
        "addl $0x168, %ebx\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x15c, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x15c(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa587c_000a5b61\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a59fb\n"
        /* } scope */
        ".Lfa587c_000a58e7:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa587c_000a5b43\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a5a1a\n"
        /* } scope */
        ".Lfa587c_000a5951:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 55 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "addss %xmm4, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        /* } scope */
        ".Lfa587c_000a5997:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 45 | 1.0f */
        "movaps %xmm3, %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "pxor %xmm1, %xmm1\n"
        "movaps %xmm0, %xmm2\n"
        "cmpnltss %xmm1, %xmm4\n"
        "andps %xmm4, %xmm2\n"
        "andnps %xmm3, %xmm4\n"
        "orps %xmm2, %xmm4\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movaps %xmm4, %xmm2\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm4\n"
        "movl 8(%ebp), %eax\n" /* line 1069 | this */
        "cmpb $0, 0xa8(%eax)\n"
        "jns .Lfa587c_000a5a39\n"
        "movl %eax, %edx\n"
        "mulss lit4_002ed5d4, %xmm4\n" /* line 1072 | 255.0f */
        "cvttss2si %xmm4, %eax\n"
        "movb %al, 0x93(%edx)\n"
        /* } scope */
        "popl %ebx\n" /* line 1082 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa587c_000a59fb:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a58e7\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a59fb\n"
        "jmp .Lfa587c_000a58e7\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa587c_000a5a1a:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a5951\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a5a1a\n"
        "jmp .Lfa587c_000a5951\n"
        ".Lfa587c_000a5a39:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* } scope */
        "movzbl 0x90(%eax), %eax\n" /* line 1077 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movb %al, 0x90(%edx)\n"
        "movzbl 0x91(%edx), %eax\n" /* line 1078 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movb %al, 0x91(%edx)\n"
        "movzbl 0x92(%edx), %eax\n" /* line 1079 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "cvttss2si %xmm4, %eax\n"
        "movb %al, 0x92(%edx)\n"
        "movb $0xff, 0x93(%edx)\n" /* line 1080 */
        /* } scope */
        "popl %ebx\n" /* line 1082 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa587c_000a5a92:\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1065 */
        "movl %eax, %ecx\n" /* source */
        "addl $0x15c, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x15c(%eax), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa587c_000a5b28\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a5b10\n"
        /* } scope */
        ".Lfa587c_000a5acf:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 32 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        "jmp .Lfa587c_000a5997\n"
        /* { scope 3 */
        ".Lfa587c_000a5b10:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a5acf\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a5b10\n"
        "jmp .Lfa587c_000a5acf\n"
        ".Lfa587c_000a5b28:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a5acf\n"
        "jmp .Lfa587c_000a5b10\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa587c_000a5b43:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a5951\n"
        "jmp .Lfa587c_000a5a1a\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa587c_000a5b61:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a58e7\n"
        "jmp .Lfa587c_000a59fb\n"
    );
}
#endif

/* line 1749 — Cylinder_Update converted to C */
Bool Cylinder_Update(const Cylinder *_this)
{
    /* Cylinder_Update follows Tail_Update pattern: normTime + bolt + origin + tail length + endpoint + radius + RGB + alpha */
    byte *self = (byte *)_this;
    int startTime = *(int *)(self + 0xb8);
    int killTime = *(int *)(self + 0xbc);
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    *(float *)(self + 0x3c) = normTime;
    if (normTime < 0.0f) return 0;

    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx >= 0) {
            int clTime = *(int *)(*(byte *)imp_cl + 0x864c);
            if (*(int *)(boltFrame + 4) != clTime) {
                *(int *)(boltFrame + 4) = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8)))
                    { *(int *)(boltFrame + 0x3c) = -1; *(int *)(boltFrame + 0x40) = -1; }
            }
            if (*(int *)(boltFrame + 0x3c) >= 0) orient = boltFrame + 8;
        }
    }

    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient)) return 0;

    if (orient) OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)(self + 0x7c));
    else { *(float *)(self + 0x7c) = *(float *)(self + 4); *(float *)(self + 0x80) = *(float *)(self + 8); *(float *)(self + 0x84) = *(float *)(self + 0xc); }

    /* Tail length curves */
    float tailLen;
    if (*(byte *)(self + 0xaa) & 2) {
        float bf = *(float *)(self + 0x25c);
        tailLen = (EvalCurve1(self + 0x260, normTime) + (EvalCurve1(self + 0x26c, normTime) - EvalCurve1(self + 0x260, normTime)) * bf) * *(float *)(self + 0x260 + 8);
    } else {
        tailLen = EvalCurve1(self + 0x260, normTime) * *(float *)(self + 0x260 + 8);
    }
    *(float *)(self + 0x258) = tailLen;

    Tail_CalcNewEndpoint((const Tail *)_this, (const orientation_t *)orient);
    if (orient) OrientationPosToWorldPos(orient, (vec_t *)(self + 0x9c), (vec_t *)(self + 0x9c));

    /* Evaluate two radii for cylinder (start + end) */
    float radius1, radius2;
    if (*(short *)(self + 0xa8) < 0) {
        float bf = *(float *)(self + 0x120);
        radius1 = (EvalCurve1(self + 0x174, normTime) + (EvalCurve1(self + 0x180, normTime) - EvalCurve1(self + 0x174, normTime)) * bf) * *(float *)(self + 0x174 + 8);
        /* Second radius uses different curve at 0x198/0x1a4 */
        if (*(byte *)(self + 0xaa) & 4) {
            float bf2 = *(float *)(self + 0x124);
            radius2 = (EvalCurve1(self + 0x198, normTime) + (EvalCurve1(self + 0x1a4, normTime) - EvalCurve1(self + 0x198, normTime)) * bf2) * *(float *)(self + 0x198 + 8);
        } else {
            radius2 = EvalCurve1(self + 0x198, normTime) * *(float *)(self + 0x198 + 8);
        }
    } else {
        radius1 = EvalCurve1(self + 0x174, normTime) * *(float *)(self + 0x174 + 8);
        if (*(byte *)(self + 0xaa) & 4) {
            float bf2 = *(float *)(self + 0x124);
            radius2 = (EvalCurve1(self + 0x198, normTime) + (EvalCurve1(self + 0x1a4, normTime) - EvalCurve1(self + 0x198, normTime)) * bf2) * *(float *)(self + 0x198 + 8);
        } else {
            radius2 = EvalCurve1(self + 0x198, normTime) * *(float *)(self + 0x198 + 8);
        }
    }
    *(float *)(self + 0x88) = radius1;
    *(float *)(self + 0x8c) = radius2;

    if (radius1 == 0.0f && radius2 == 0.0f) { *(int *)(self + 0xa8) |= 0x01000000; return 1; }

    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);
    return 1;
}
#if 0 /* Original ASM (693 lines) */
__attribute__((naked))
Bool Cylinder_Update_asm(const Cylinder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1749 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa5b84_000a5ee4\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa5b84_000a5bd5\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa5b84_000a5bd5:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa5b84_000a6179\n"
        "movl 0xc0(%esi), %ebx\n" /* line 207 | key */
        "testl %ebx, %ebx\n" /* key */
        "jne .Lfa5b84_000a5e96\n"
        ".Lfa5b84_000a5bf1:\n"
        "movl $0, -0x44(%ebp)\n" /* or_ */
        ".Lfa5b84_000a5bf8:\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "js .Lfa5b84_000a5eee\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a5c3c\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa5b84_000a5c3c:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5c56\n"
        ".Lfa5b84_000a5c4b:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5c4b\n"
        /* } scope */
        ".Lfa5b84_000a5c56:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "cmpb $0, 0x104(%esi)\n" /* line 1027 */
        "jne .Lfa5b84_000a6036\n"
        ".Lfa5b84_000a5ca7:\n"
        "movl 0x88(%esi), %eax\n" /* line 1036 */
        "movl %eax, 0x8c(%esi)\n"
        ".Lfa5b84_000a5cb3:\n"
        "testb $2, 0xaa(%esi)\n" /* line 1658 */
        "je .Lfa5b84_000a61b0\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1659 */
        "movss 0x25c(%esi), %xmm5\n" /* blendFactor */
        "leal 0x26c(%esi), %ebx\n" /* source1 */
        "leal 0x260(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x260(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x38(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a5d07\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa5b84_000a5d07:\n"
        "movl -0x38(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5d20\n"
        ".Lfa5b84_000a5d15:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5d15\n"
        /* } scope */
        ".Lfa5b84_000a5d20:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x50(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x50(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x4c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a62db\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x2c(%ebp)\n" /* keySize */
        ".Lfa5b84_000a5d97:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5dad\n"
        ".Lfa5b84_000a5da2:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5da2\n"
        /* } scope */
        ".Lfa5b84_000a5dad:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x50(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1659 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x258(%esi)\n"
        "movl %esi, (%esp)\n" /* line 1766 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1767 | this */
        "calll Particle_UpdateAlpha\n"
        "movl -0x44(%ebp), %edx\n" /* line 1770 | or_ */
        "testl %edx, %edx\n"
        "je .Lfa5b84_000a625f\n"
        ".Lfa5b84_000a5e19:\n"
        "leal 4(%esi), %ebx\n" /* line 1772 | this, source1 */
        "leal 0x7c(%esi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* source1 */
        "movl -0x44(%ebp), %edi\n" /* or_, keySize */
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "movss 0x258(%esi), %xmm1\n" /* line 1773 | this, scale */
        "leal 0x48(%esi), %eax\n" /* this, dir */
        /* { scope 2: keySize, keySize, keySize */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x48(%esi), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* endpos */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%ebx), %xmm0\n" /* this */
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%ebx), %xmm1\n" /* this */
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "leal 0x9c(%esi), %eax\n" /* line 1774 | this */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* endpos */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa5b84_000a5e96:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, keySize, keySize */
        "movl 0x3c(%ebx), %ecx\n" /* line 90 | key */
        "testl %ecx, %ecx\n"
        "js .Lfa5b84_000a5ee4\n"
        "movl imp_cl, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa5b84_000a62c8\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %edi\n" /* line 102 | key, keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa5b84_000a62cb\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa5b84_000a5ee4:\n"
        "xorl %eax, %eax\n" /* line 290 */
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa5b84_000a5eee:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a5f33\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa5b84_000a5f33:\n"
        "movl -0x40(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5f4c\n"
        ".Lfa5b84_000a5f41:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5f41\n"
        /* } scope */
        ".Lfa5b84_000a5f4c:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edx\n" /* line 91 | key */
        "movl %edx, -0x50(%ebp)\n"
        "movl %edx, %edi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x4c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a62e3\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x34(%ebp)\n" /* keySize */
        ".Lfa5b84_000a5fc2:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5fd8\n"
        ".Lfa5b84_000a5fcd:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5fcd\n"
        /* } scope */
        ".Lfa5b84_000a5fd8:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x50(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        "cmpb $0, 0x104(%esi)\n" /* line 1027 */
        "je .Lfa5b84_000a5ca7\n"
        ".Lfa5b84_000a6036:\n"
        "testb $1, 0xaa(%esi)\n" /* line 1029 */
        "je .Lfa5b84_000a62eb\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1030 */
        "movss 0x124(%esi), %xmm5\n" /* blendFactor */
        "leal 0x198(%esi), %ebx\n" /* source1 */
        "leal 0x18c(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x18c(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x3c(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa5b84_000a639b\n"
        ".Lfa5b84_000a6084:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a6191\n"
        /* } scope */
        ".Lfa5b84_000a6096:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x50(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x50(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x4c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a6393\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x30(%ebp)\n" /* keySize */
        ".Lfa5b84_000a610d:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a6123\n"
        ".Lfa5b84_000a6118:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a6118\n"
        /* } scope */
        ".Lfa5b84_000a6123:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x50(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1030 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x8c(%esi)\n"
        "jmp .Lfa5b84_000a5cb3\n"
        ".Lfa5b84_000a6179:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %ebx\n" /* line 207 | key */
        "testl %ebx, %ebx\n" /* key */
        "jne .Lfa5b84_000a5e96\n"
        "jmp .Lfa5b84_000a5bf1\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        ".Lfa5b84_000a6191:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a6096\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a6191\n"
        "jmp .Lfa5b84_000a6096\n"
        /* } scope */
        /* } scope */
        ".Lfa5b84_000a61b0:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1661 */
        "leal 0x260(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x260(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a61e6\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa5b84_000a61e6:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a6200\n"
        ".Lfa5b84_000a61f5:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a61f5\n"
        /* } scope */
        ".Lfa5b84_000a6200:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1661 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x258(%esi)\n"
        "movl %esi, (%esp)\n" /* line 1766 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1767 | this */
        "calll Particle_UpdateAlpha\n"
        "movl -0x44(%ebp), %edx\n" /* line 1770 | or_ */
        "testl %edx, %edx\n"
        "jne .Lfa5b84_000a5e19\n"
        ".Lfa5b84_000a625f:\n"
        "leal 0x7c(%esi), %edx\n" /* line 1778 | this, to */
        /* { scope 2: keySize, keySize, keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 8(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x9c(%esi), %edx\n" /* line 1779 | this, result */
        "movss 0x258(%esi), %xmm1\n" /* this, scale */
        "leal 0x48(%esi), %eax\n" /* this, dir */
        /* { scope 2: keySize, keySize, keySize */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x48(%esi), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 0x9c(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 8(%esi), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 0xc(%esi), %xmm1\n"
        "movss %xmm1, 8(%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa5b84_000a62c8:\n"
        "leal 8(%ebx), %edi\n" /* source1, keySize */
        /* { scope 1 */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa5b84_000a62cb:\n"
        "movl %edi, -0x44(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa5b84_000a5bf8\n"
        "jmp .Lfa5b84_000a5ee4\n"
        ".Lfa5b84_000a62db:\n"
        "movl -0x2c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa5b84_000a5d97\n"
        ".Lfa5b84_000a62e3:\n"
        "movl -0x34(%ebp), %edi\n" /* keySize */
        "jmp .Lfa5b84_000a5fc2\n"
        ".Lfa5b84_000a62eb:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1032 */
        "leal 0x18c(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x18c(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa5b84_000a6387\n"
        ".Lfa5b84_000a6317:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a636f\n"
        /* } scope */
        ".Lfa5b84_000a6326:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1032 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x8c(%esi)\n"
        "jmp .Lfa5b84_000a5cb3\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        ".Lfa5b84_000a636f:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a6326\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a636f\n"
        "jmp .Lfa5b84_000a6326\n"
        ".Lfa5b84_000a6387:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        "jmp .Lfa5b84_000a6317\n"
        ".Lfa5b84_000a6393:\n"
        "movl -0x30(%ebp), %edi\n" /* keySize */
        "jmp .Lfa5b84_000a610d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        ".Lfa5b84_000a639b:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        "jmp .Lfa5b84_000a6084\n"
    );
}
#endif

/* Tail_Update — Particle_Update + tail length eval + endpoint computation */
Bool Tail_Update(const Tail *_this)
{
    byte *self = (byte *)_this;
    int startTime = *(int *)(self + 0xb8);
    int killTime = *(int *)(self + 0xbc);
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    *(float *)(self + 0x3c) = normTime;
    if (normTime < 0.0f) return 0;

    /* Get bolt orientation */
    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx >= 0) {
            int clTime = *(int *)(*(byte *)imp_cl + 0x864c);
            if (*(int *)(boltFrame + 4) != clTime) {
                *(int *)(boltFrame + 4) = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8)))
                    { *(int *)(boltFrame + 0x3c) = -1; *(int *)(boltFrame + 0x40) = -1; }
            }
            if (*(int *)(boltFrame + 0x3c) >= 0)
                orient = boltFrame + 8;
        }
    }

    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient))
        return 0;

    /* Transform origin to world */
    if (orient) OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)(self + 0x7c));
    else { *(float *)(self + 0x7c) = *(float *)(self + 4); *(float *)(self + 0x80) = *(float *)(self + 8); *(float *)(self + 0x84) = *(float *)(self + 0xc); }

    /* Evaluate tail length curve(s) */
    float tailLen;
    if (*(byte *)(self + 0xaa) & 2) {
        float bf = *(float *)(self + 0x25c);
        float v0 = EvalCurve1(self + 0x260, normTime);
        float v1 = EvalCurve1(self + 0x26c, normTime);
        tailLen = (v0 + (v1 - v0) * bf) * *(float *)(self + 0x260 + 8);
    } else {
        tailLen = EvalCurve1(self + 0x260, normTime) * *(float *)(self + 0x260 + 8);
    }
    *(float *)(self + 0x258) = tailLen;

    /* Compute new endpoint */
    Tail_CalcNewEndpoint(_this, (const orientation_t *)orient);

    /* Transform endpoint to world */
    if (orient) OrientationPosToWorldPos(orient, (vec_t *)(self + 0x9c), (vec_t *)(self + 0x9c));

    /* Evaluate radius */
    float radius;
    if (*(short *)(self + 0xa8) < 0) {
        float bf = *(float *)(self + 0x120);
        radius = (EvalCurve1(self + 0x174, normTime) + (EvalCurve1(self + 0x180, normTime) - EvalCurve1(self + 0x174, normTime)) * bf) * *(float *)(self + 0x174 + 8);
    } else {
        radius = EvalCurve1(self + 0x174, normTime) * *(float *)(self + 0x174 + 8);
    }
    *(float *)(self + 0x88) = radius;
    *(float *)(self + 0x8c) = radius;

    if (radius == 0.0f) { *(int *)(self + 0xa8) |= 0x01000000; return 1; }

    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);
    return 1;
}
#if 0 /* Original ASM (524 lines) */
__attribute__((naked))
Bool Tail_Update_asm(const Tail * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1619 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa63aa_000a67d2\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa63aa_000a63fb\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa63aa_000a63fb:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa63aa_000a67dc\n"
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa63aa_000a678c\n"
        ".Lfa63aa_000a6417:\n"
        "movl $0, -0x2c(%ebp)\n" /* or_ */
        ".Lfa63aa_000a641e:\n"
        "leal 0x24c(%esi), %edx\n" /* line 1631 | this, to */
        "leal 4(%esi), %ebx\n" /* this, source1 */
        /* { scope 2: keySize, keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x24c(%esi)\n"
        "movl 8(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 1634 | or_ */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je .Lfa63aa_000a67d2\n"
        "movl -0x2c(%ebp), %edi\n" /* line 1637 | or_, keySize */
        "testl %edi, %edi\n" /* keySize */
        "je .Lfa63aa_000a67f0\n"
        "leal 0x7c(%esi), %eax\n" /* line 1638 | this */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* source1 */
        "movl -0x2c(%ebp), %edx\n" /* or_ */
        "movl %edx, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        ".Lfa63aa_000a6474:\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "jns .Lfa63aa_000a682a\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x28(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a64c9\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa63aa_000a64c9:\n"
        "movl -0x28(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a64e2\n"
        ".Lfa63aa_000a64d7:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a64d7\n"
        /* } scope */
        ".Lfa63aa_000a64e2:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x40(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x40(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a69bc\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x20(%ebp)\n" /* keySize */
        ".Lfa63aa_000a6559:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a656f\n"
        ".Lfa63aa_000a6564:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a6564\n"
        /* } scope */
        ".Lfa63aa_000a656f:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        "testb $2, 0xaa(%esi)\n" /* line 1658 | this */
        "je .Lfa63aa_000a68cb\n"
        ".Lfa63aa_000a65cd:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1659 | this */
        "movss 0x25c(%esi), %xmm5\n" /* this, blendFactor */
        "leal 0x26c(%esi), %ebx\n" /* this, source1 */
        "leal 0x260(%esi), %ecx\n" /* this, source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3 */
        "movl 0x260(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x24(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a6614\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa63aa_000a6614:\n"
        "movl -0x24(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edi, %edx), %eax\n" /* keySize */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a662d\n"
        ".Lfa63aa_000a6622:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a6622\n"
        /* } scope */
        ".Lfa63aa_000a662d:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edi\n" /* line 91 | key, keySize */
        "movl (%edi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a69b4\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%edi), %eax\n" /* line 97 | keySize */
        "movl %eax, -0x1c(%ebp)\n"
        ".Lfa63aa_000a669e:\n"
        "shll $2, %edx\n" /* line 100 */
        "addl %edx, %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a66b3\n"
        ".Lfa63aa_000a66a8:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a66a8\n"
        /* } scope */
        ".Lfa63aa_000a66b3:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "leal (%edi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1659 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x258(%esi)\n" /* this */
        ".Lfa63aa_000a6701:\n"
        "movl %esi, (%esp)\n" /* line 1645 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1646 | this */
        "calll Particle_UpdateAlpha\n"
        /* { scope 2: keySize, keySize */
        "movl 0x40(%esi), %eax\n" /* line 1110 */
        "movl %eax, 4(%esp)\n"
        "movl imp_theFxHelper, %ebx\n" /* source1 */
        "movl (%ebx), %eax\n" /* source1 */
        "movl %eax, (%esp)\n"
        "calll FxHelper_GetMaterialSubimageCount\n"
        "movl %eax, %ecx\n"
        "cmpl $1, %eax\n" /* line 1112 */
        "je .Lfa63aa_000a69a5\n"
        "movl (%ebx), %eax\n" /* line 1118 | source1 */
        "movl 4(%eax), %eax\n"
        "subl 0xb8(%esi), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x10c(%esi), %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "addl 0x108(%esi), %edx\n"
        "movl %edx, 0x94(%esi)\n"
        "movl 0x110(%esi), %eax\n" /* line 1120 */
        "testl %eax, %eax\n"
        "jne .Lfa63aa_000a6964\n"
        "cmpl %edx, %ecx\n" /* line 1122 */
        "jle .Lfa63aa_000a680a\n"
        /* } scope */
        ".Lfa63aa_000a6770:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1650 | or_ */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Tail_CalcNewEndpoint\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa63aa_000a678c:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, keySize */
        "movl 0x3c(%ebx), %eax\n" /* line 90 | key */
        "testl %eax, %eax\n"
        "js .Lfa63aa_000a67d2\n"
        "movl imp_cl, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa63aa_000a681a\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %edi\n" /* line 102 | key, keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa63aa_000a681d\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        ".Lfa63aa_000a67d2:\n"
        "xorl %eax, %eax\n" /* line 1652 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa63aa_000a67dc:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa63aa_000a678c\n"
        "jmp .Lfa63aa_000a6417\n"
        ".Lfa63aa_000a67f0:\n"
        "leal 0x7c(%esi), %edx\n" /* line 1640 | this, to */
        /* { scope 2: keySize, keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 8(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lfa63aa_000a6474\n"
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa63aa_000a680a:\n"
        "movl %edx, %eax\n" /* line 1138 */
        "cltd\n"
        "idivl %ecx\n"
        "movl %edx, 0x94(%esi)\n"
        "jmp .Lfa63aa_000a6770\n"
        ".Lfa63aa_000a681a:\n"
        "leal 8(%ebx), %edi\n" /* source1, keySize */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa63aa_000a681d:\n"
        "movl %edi, -0x2c(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa63aa_000a641e\n"
        "jmp .Lfa63aa_000a67d2\n"
        ".Lfa63aa_000a682a:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a6860\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa63aa_000a6860:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a687a\n"
        ".Lfa63aa_000a686f:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a686f\n"
        /* } scope */
        ".Lfa63aa_000a687a:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "testb $2, 0xaa(%esi)\n" /* line 1658 | this */
        "jne .Lfa63aa_000a65cd\n"
        ".Lfa63aa_000a68cb:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1661 | this */
        "leal 0x260(%esi), %ecx\n" /* this, source */
        /* { scope 2: keySize, keySize */
        /* { scope 3 */
        "movl 0x260(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a6901\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa63aa_000a6901:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n" /* key */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a691b\n"
        ".Lfa63aa_000a6910:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a6910\n"
        /* } scope */
        ".Lfa63aa_000a691b:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1661 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x258(%esi)\n" /* this */
        "jmp .Lfa63aa_000a6701\n"
        /* { scope 2: keySize, keySize */
        ".Lfa63aa_000a6964:\n"
        "subl $1, %eax\n" /* line 1125 */
        "jne .Lfa63aa_000a6770\n"
        "movl 0x114(%esi), %eax\n" /* line 1127 */
        "testl %eax, %eax\n"
        "jle .Lfa63aa_000a69c4\n"
        "cmpl %edx, %ecx\n" /* line 1129 */
        "jg .Lfa63aa_000a6770\n"
        "addl $1, %eax\n" /* line 1131 */
        "imull %ecx, %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lfa63aa_000a680a\n"
        "movl $0, 0x114(%esi)\n" /* line 1133 */
        "leal -1(%ecx), %eax\n" /* line 1134 */
        "movl %eax, 0x94(%esi)\n"
        "jmp .Lfa63aa_000a6770\n"
        ".Lfa63aa_000a69a5:\n"
        "movl $0, 0x94(%esi)\n" /* line 1114 */
        "jmp .Lfa63aa_000a6770\n"
        ".Lfa63aa_000a69b4:\n"
        "movl -0x1c(%ebp), %eax\n"
        "jmp .Lfa63aa_000a669e\n"
        ".Lfa63aa_000a69bc:\n"
        "movl -0x20(%ebp), %edi\n" /* keySize */
        "jmp .Lfa63aa_000a6559\n"
        ".Lfa63aa_000a69c4:\n"
        "cmpl %edx, %ecx\n" /* line 1144 */
        "jg .Lfa63aa_000a6770\n"
        "leal -1(%ecx), %eax\n" /* line 1145 */
        "movl %eax, 0x94(%esi)\n"
        "jmp .Lfa63aa_000a6770\n"
    );
}
#endif

/* Line_Update — Particle_Update + endpoint transform for line/cylinder */
extern void OrientationPosToWorldPos(void *orient, vec_t *localPos, vec_t *worldPos);
Bool Line_Update(const Line *_this)
{
    byte *self = (byte *)_this;
    int startTime = *(int *)(self + 0xb8);
    int killTime = *(int *)(self + 0xbc);
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;

    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    *(float *)(self + 0x3c) = normTime;
    if (normTime < 0.0f) return 0;

    /* Get bolt orientation */
    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx >= 0) {
            int clTime = *(int *)(*(byte *)imp_cl + 0x864c);
            if (*(int *)(boltFrame + 4) != clTime) {
                *(int *)(boltFrame + 4) = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8)))
                    { *(int *)(boltFrame + 0x3c) = -1; *(int *)(boltFrame + 0x40) = -1; }
            }
            if (*(int *)(boltFrame + 0x3c) >= 0)
                orient = boltFrame + 8;
        }
    }

    /* Update origin */
    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient))
        return 0;

    /* Transform origin to world space */
    if (orient)
        OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)(self + 0x7c));
    else {
        *(float *)(self + 0x7c) = *(float *)(self + 4);
        *(float *)(self + 0x80) = *(float *)(self + 8);
        *(float *)(self + 0x84) = *(float *)(self + 0xc);
    }

    /* Transform endpoint (0x24c) to world space (0x9c) */
    if (orient)
        OrientationPosToWorldPos(orient, (vec_t *)(self + 0x24c), (vec_t *)(self + 0x9c));
    else {
        *(float *)(self + 0x9c) = *(float *)(self + 0x24c);
        *(float *)(self + 0xa0) = *(float *)(self + 0x250);
        *(float *)(self + 0xa4) = *(float *)(self + 0x254);
    }

    /* Evaluate radius */
    float radius;
    if (*(short *)(self + 0xa8) < 0) {
        float bf = *(float *)(self + 0x120);
        radius = (EvalCurve1(self + 0x174, normTime) + (EvalCurve1(self + 0x180, normTime) - EvalCurve1(self + 0x174, normTime)) * bf) * *(float *)(self + 0x174 + 8);
    } else {
        radius = EvalCurve1(self + 0x174, normTime) * *(float *)(self + 0x174 + 8);
    }
    *(float *)(self + 0x88) = radius;
    *(float *)(self + 0x8c) = radius;

    if (radius == 0.0f) {
        *(int *)(self + 0xa8) |= 0x01000000;
        return 1;
    }

    /* Update RGB and alpha */
    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);

    return 1;
}
#if 0 /* Original ASM (290 lines) */
__attribute__((naked))
Bool Line_Update_asm(const Line * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1526 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa69da_000a6b78\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa69da_000a6a2b\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa69da_000a6a2b:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa69da_000a6cda\n"
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa69da_000a6b2a\n"
        ".Lfa69da_000a6a47:\n"
        "leal 0x7c(%esi), %ecx\n" /* line 1545 | this, to */
        "leal 4(%esi), %edx\n" /* this, from */
        /* { scope 2: keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x9c(%esi), %ecx\n" /* line 1546 | this, to */
        "leal 0x24c(%esi), %edx\n" /* this, from */
        /* { scope 2: keySize */
        "movl 0x24c(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x9c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lfa69da_000a6a83:\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "js .Lfa69da_000a6b82\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa69da_000a6ac7\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        ".Lfa69da_000a6ac7:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa69da_000a6ae1\n"
        ".Lfa69da_000a6ad6:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa69da_000a6ad6\n"
        /* } scope */
        ".Lfa69da_000a6ae1:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "jmp .Lfa69da_000a6cbd\n"
        ".Lfa69da_000a6b2a:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 */
        /* { scope 2: keySize */
        "movl 0x3c(%ebx), %eax\n" /* line 90 */
        "testl %eax, %eax\n"
        "js .Lfa69da_000a6b78\n"
        "movl imp_cl, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n"
        "je .Lfa69da_000a6cf2\n"
        "movl %eax, 4(%ebx)\n" /* line 96 */
        "leal 8(%ebx), %edi\n" /* line 102 | keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa69da_000a6cf5\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 */
        /* } scope */
        ".Lfa69da_000a6b78:\n"
        "xorl %eax, %eax\n" /* line 1555 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1556 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa69da_000a6b82:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa69da_000a6bc7\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa69da_000a6bc7:\n"
        "movl -0x20(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa69da_000a6be0\n"
        ".Lfa69da_000a6bd5:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa69da_000a6bd5\n"
        /* } scope */
        ".Lfa69da_000a6be0:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edx\n" /* line 91 */
        "movl %edx, -0x30(%ebp)\n"
        "movl %edx, %edi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x2c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa69da_000a6d34\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x1c(%ebp)\n" /* keySize */
        ".Lfa69da_000a6c56:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa69da_000a6c6c\n"
        ".Lfa69da_000a6c61:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa69da_000a6c61\n"
        /* } scope */
        ".Lfa69da_000a6c6c:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "movl -0x30(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        ".Lfa69da_000a6cbd:\n"
        "movl %esi, (%esp)\n" /* line 1551 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1552 | this */
        "calll Particle_UpdateAlpha\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1556 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa69da_000a6cda:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "je .Lfa69da_000a6a47\n"
        "jmp .Lfa69da_000a6b2a\n"
        ".Lfa69da_000a6cf2:\n"
        "leal 8(%ebx), %edi\n" /* keySize */
        ".Lfa69da_000a6cf5:\n"
        "testl %edi, %edi\n" /* line 210 | keySize */
        "je .Lfa69da_000a6b78\n"
        "leal 0x7c(%esi), %eax\n" /* line 1540 | this */
        "movl %eax, 8(%esp)\n"
        "leal 4(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "leal 0x9c(%esi), %eax\n" /* line 1541 | this */
        "movl %eax, 8(%esp)\n"
        "leal 0x24c(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "jmp .Lfa69da_000a6a83\n"
        ".Lfa69da_000a6d34:\n"
        "movl -0x1c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa69da_000a6c56\n"
    );
}
#endif

/* line 1418 — Cloud_Update converted to C */
Bool Cloud_Update(const Cloud *_this)
{
    /* Cloud follows Particle_Update + height/density channel eval + cloud-specific endpoint */
    byte *self = (byte *)_this;
    int startTime = *(int *)(self + 0xb8);
    int killTime = *(int *)(self + 0xbc);
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    *(float *)(self + 0x3c) = normTime;
    if (normTime < 0.0f) return 0;

    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx >= 0) {
            int clTime = *(int *)(*(byte *)imp_cl + 0x864c);
            if (*(int *)(boltFrame + 4) != clTime) {
                *(int *)(boltFrame + 4) = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8)))
                    { *(int *)(boltFrame + 0x3c) = -1; *(int *)(boltFrame + 0x40) = -1; }
            }
            if (*(int *)(boltFrame + 0x3c) >= 0) orient = boltFrame + 8;
        }
    }

    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient)) return 0;

    if (orient) OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)(self + 0x7c));
    else { *(float *)(self + 0x7c) = *(float *)(self + 4); *(float *)(self + 0x80) = *(float *)(self + 8); *(float *)(self + 0x84) = *(float *)(self + 0xc); }

    /* Evaluate radius */
    float radius;
    if (*(short *)(self + 0xa8) < 0) {
        float bf = *(float *)(self + 0x120);
        radius = (EvalCurve1(self + 0x174, normTime) + (EvalCurve1(self + 0x180, normTime) - EvalCurve1(self + 0x174, normTime)) * bf) * *(float *)(self + 0x174 + 8);
    } else {
        radius = EvalCurve1(self + 0x174, normTime) * *(float *)(self + 0x174 + 8);
    }
    *(float *)(self + 0x88) = radius;
    if (radius == 0.0f) { *(int *)(self + 0xa8) |= 0x01000000; return 1; }

    /* Cloud-specific: height channel at 0x264/0x270 */
    float height;
    if (*(byte *)(self + 0xaa) & 2) {
        float bf = *(float *)(self + 0x25c); /* cloud blend factor from 0x260 random weight */
        height = (EvalCurve1(self + 0x264, normTime) + (EvalCurve1(self + 0x270, normTime) - EvalCurve1(self + 0x264, normTime)) * bf) * *(float *)(self + 0x264 + 8);
    } else {
        height = EvalCurve1(self + 0x264, normTime) * *(float *)(self + 0x264 + 8);
    }
    *(float *)(self + 0x8c) = height;
    if (height == 0.0f) { *(int *)(self + 0xa8) |= 0x01000000; return 1; }

    /* Rotation */
    if (*(byte *)(self + 0xaa) & 1) {
        float rot;
        if (*(byte *)(self + 0xaa) & 0x10) {
            float bf = *(float *)(self + 0x128);
            rot = (EvalCurve1(self + 0x18c, normTime) + (EvalCurve1(self + 0x198, normTime) - EvalCurve1(self + 0x18c, normTime)) * bf) * *(float *)(self + 0x18c + 8);
        } else {
            rot = EvalCurve1(self + 0x18c, normTime) * *(float *)(self + 0x18c + 8);
        }
        *(float *)(self + 0x94) = rot;
    }

    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);
    return 1;
}
#if 0 /* Original ASM (907 lines) */
__attribute__((naked))
Bool Cloud_Update_asm(const Cloud * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1418 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa6d3c_000a7265\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa6d3c_000a6d8d\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa6d3c_000a6d8d:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa6d3c_000a74f3\n"
        "movl 0xc0(%esi), %edx\n" /* line 207 */
        "testl %edx, %edx\n"
        "jne .Lfa6d3c_000a7217\n"
        ".Lfa6d3c_000a6da9:\n"
        "movl $0, -0x60(%ebp)\n" /* or_ */
        ".Lfa6d3c_000a6db0:\n"
        "leal 4(%esi), %eax\n" /* line 1432 | this */
        "movl %eax, -0x64(%ebp)\n"
        "movss 4(%esi), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "leal 8(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movss 8(%esi), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "leal 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "movss 0xc(%esi), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movl -0x60(%ebp), %eax\n" /* line 1435 | or_ */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je .Lfa6d3c_000a7265\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "js .Lfa6d3c_000a726f\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a6e3b\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa6d3c_000a6e3b:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n" /* key */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a6e55\n"
        ".Lfa6d3c_000a6e4a:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a6e4a\n"
        /* } scope */
        ".Lfa6d3c_000a6e55:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "cmpb $0, 0x104(%esi)\n" /* line 1027 */
        "jne .Lfa6d3c_000a73ba\n"
        ".Lfa6d3c_000a6ea6:\n"
        "movl 0x88(%esi), %eax\n" /* line 1036 */
        "movl %eax, 0x8c(%esi)\n"
        ".Lfa6d3c_000a6eb2:\n"
        "cmpb $0, 0x25c(%esi)\n" /* line 1408 */
        "je .Lfa6d3c_000a6ff3\n"
        "testb $2, 0xaa(%esi)\n" /* line 1411 */
        "je .Lfa6d3c_000a761d\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1412 */
        "movss 0x260(%esi), %xmm5\n" /* blendFactor */
        "leal 0x270(%esi), %ebx\n" /* source1 */
        "leal 0x264(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x264(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x4c(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a775d\n"
        ".Lfa6d3c_000a6f0d:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a753d\n"
        /* } scope */
        ".Lfa6d3c_000a6f1f:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x70(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x70(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x6c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a77ab\n"
        "movl -0x30(%ebp), %edi\n" /* keySize */
        ".Lfa6d3c_000a6f8c:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a6fa2\n"
        ".Lfa6d3c_000a6f97:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a6f97\n"
        /* } scope */
        ".Lfa6d3c_000a6fa2:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x70(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1412 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x258(%esi)\n"
        ".Lfa6d3c_000a6ff3:\n"
        "movl %esi, (%esp)\n" /* line 1442 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1443 | this */
        "calll Particle_UpdateAlpha\n"
        /* { scope 2: keySize, keySize, keySize */
        "testb $4, 0xaa(%esi)\n" /* line 1089 */
        "je .Lfa6d3c_000a755c\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1090 */
        "movss 0x128(%esi), %xmm5\n" /* blendFactor */
        "leal 0x1b0(%esi), %ebx\n" /* source1 */
        "leal 0x1a4(%esi), %ecx\n" /* source0 */
        /* { scope 3: keySize */
        /* { scope 4 */
        "movl 0x1a4(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x48(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a7057\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa6d3c_000a7057:\n"
        "movl -0x48(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a7070\n"
        ".Lfa6d3c_000a7065:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7065\n"
        /* } scope */
        ".Lfa6d3c_000a7070:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 4 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x70(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x70(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x6c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a7615\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x2c(%ebp)\n" /* keySize */
        ".Lfa6d3c_000a70e7:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a70fd\n"
        ".Lfa6d3c_000a70f2:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a70f2\n"
        /* } scope */
        ".Lfa6d3c_000a70fd:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x70(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 55 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "addss %xmm4, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        /* } scope */
        ".Lfa6d3c_000a7146:\n"
        "movl imp_theFxHelper, %eax\n" /* line 1094 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0xc(%eax), %xmm0\n"
        "mulss lit4_002ed738, %xmm0\n" /* 0.009999999776482582f */
        "mulss %xmm3, %xmm0\n"
        "addss 0x44(%esi), %xmm0\n"
        "movss %xmm0, 0x44(%esi)\n"
        /* } scope */
        "leal -0x28(%ebp), %ebx\n" /* line 1447 | quat, source1 */
        "movl %ebx, 8(%esp)\n" /* source1 */
        "leal 0x24c(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleAxisToQuat\n"
        "leal 0x48(%esi), %eax\n" /* line 1448 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* source1 */
        "calll QuatToAxis\n"
        "movl 0x88(%esi), %eax\n" /* line 1450 | this */
        "movl %eax, 0x98(%esi)\n" /* this */
        "movl 0x8c(%esi), %eax\n" /* line 1451 | this */
        "movl %eax, 0x88(%esi)\n" /* this */
        "cmpb $0, 0x25c(%esi)\n" /* line 1452 | this */
        "je .Lfa6d3c_000a71b9\n"
        "movl 0x258(%esi), %eax\n" /* this */
        ".Lfa6d3c_000a71b9:\n"
        "movl %eax, 0x8c(%esi)\n" /* this */
        "movl -0x60(%ebp), %eax\n" /* line 1454 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa6d3c_000a75ed\n"
        "leal 0x7c(%esi), %eax\n" /* line 1455 | this */
        "movl %eax, 8(%esp)\n"
        "movl -0x64(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x60(%ebp), %edi\n" /* or_, keySize */
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        ".Lfa6d3c_000a71e3:\n"
        "leal 0x9c(%esi), %eax\n" /* line 1458 | this, to */
        /* { scope 2: keySize, keySize, keySize */
        "movss -0x3c(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x9c(%esi)\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%eax)\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1461 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa6d3c_000a7217:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, keySize, keySize */
        "movl 0x3c(%ebx), %eax\n" /* line 90 | key */
        "testl %eax, %eax\n"
        "js .Lfa6d3c_000a7265\n"
        "movl imp_cl, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa6d3c_000a752a\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %edi\n" /* line 102 | key, keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa6d3c_000a752d\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa6d3c_000a7265:\n"
        "xorl %eax, %eax\n" /* line 1460 */
        /* } scope */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1461 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa6d3c_000a726f:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x54(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a72b6\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa6d3c_000a72b6:\n"
        "movl -0x54(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a72cf\n"
        ".Lfa6d3c_000a72c4:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a72c4\n"
        /* } scope */
        ".Lfa6d3c_000a72cf:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x70(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x70(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x6c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a760d\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x38(%ebp)\n" /* keySize */
        ".Lfa6d3c_000a7346:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a735c\n"
        ".Lfa6d3c_000a7351:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7351\n"
        /* } scope */
        ".Lfa6d3c_000a735c:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x70(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        "cmpb $0, 0x104(%esi)\n" /* line 1027 */
        "je .Lfa6d3c_000a6ea6\n"
        ".Lfa6d3c_000a73ba:\n"
        "testb $1, 0xaa(%esi)\n" /* line 1029 */
        "je .Lfa6d3c_000a76bd\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1030 */
        "movss 0x124(%esi), %xmm5\n" /* blendFactor */
        "leal 0x198(%esi), %ebx\n" /* source1 */
        "leal 0x18c(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x50(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a777e\n"
        ".Lfa6d3c_000a7408:\n"
        "movl -0x50(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a750b\n"
        /* } scope */
        ".Lfa6d3c_000a741a:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x70(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x70(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x6c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a776c\n"
        "movl -0x34(%ebp), %edi\n" /* keySize */
        ".Lfa6d3c_000a7487:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a749d\n"
        ".Lfa6d3c_000a7492:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7492\n"
        /* } scope */
        ".Lfa6d3c_000a749d:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x70(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1030 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x8c(%esi)\n"
        "jmp .Lfa6d3c_000a6eb2\n"
        ".Lfa6d3c_000a74f3:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %edx\n" /* line 207 */
        "testl %edx, %edx\n"
        "jne .Lfa6d3c_000a7217\n"
        "jmp .Lfa6d3c_000a6da9\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a750b:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a741a\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a750b\n"
        "jmp .Lfa6d3c_000a741a\n"
        ".Lfa6d3c_000a752a:\n"
        "leal 8(%ebx), %edi\n" /* key, keySize */
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa6d3c_000a752d:\n"
        "movl %edi, -0x60(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa6d3c_000a6db0\n"
        "jmp .Lfa6d3c_000a7265\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a753d:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a6f1f\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a753d\n"
        "jmp .Lfa6d3c_000a6f1f\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa6d3c_000a755c:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1092 */
        "leal 0x1a4(%esi), %ecx\n" /* source */
        /* { scope 3: keySize */
        /* { scope 4 */
        "movl 0x1a4(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a7592\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa6d3c_000a7592:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a75ac\n"
        ".Lfa6d3c_000a75a1:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a75a1\n"
        /* } scope */
        ".Lfa6d3c_000a75ac:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 32 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        "jmp .Lfa6d3c_000a7146\n"
        /* } scope */
        /* } scope */
        ".Lfa6d3c_000a75ed:\n"
        "leal 0x7c(%esi), %edx\n" /* line 1457 | this, to */
        /* { scope 2: keySize, keySize, keySize */
        "movl -0x64(%ebp), %ecx\n" /* line 199 */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x7c(%esi)\n"
        "movl -0x5c(%ebp), %edi\n" /* line 200 | keySize */
        "movl (%edi), %eax\n" /* keySize */
        "movl %eax, 4(%edx)\n"
        "movl -0x58(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "jmp .Lfa6d3c_000a71e3\n"
        ".Lfa6d3c_000a760d:\n"
        "movl -0x38(%ebp), %edi\n" /* keySize */
        "jmp .Lfa6d3c_000a7346\n"
        ".Lfa6d3c_000a7615:\n"
        "movl -0x2c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa6d3c_000a70e7\n"
        /* } scope */
        ".Lfa6d3c_000a761d:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1414 */
        "leal 0x264(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x264(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a779c\n"
        ".Lfa6d3c_000a764d:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a76a5\n"
        /* } scope */
        ".Lfa6d3c_000a765c:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1414 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x258(%esi)\n"
        "jmp .Lfa6d3c_000a6ff3\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a76a5:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a765c\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a76a5\n"
        "jmp .Lfa6d3c_000a765c\n"
        /* } scope */
        /* } scope */
        ".Lfa6d3c_000a76bd:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1032 */
        "leal 0x18c(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a778d\n"
        ".Lfa6d3c_000a76ed:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7745\n"
        /* } scope */
        ".Lfa6d3c_000a76fc:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1032 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x8c(%esi)\n"
        "jmp .Lfa6d3c_000a6eb2\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a7745:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a76fc\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7745\n"
        "jmp .Lfa6d3c_000a76fc\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a775d:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        "jmp .Lfa6d3c_000a6f0d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a776c:\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x34(%ebp)\n" /* keySize */
        "jmp .Lfa6d3c_000a7487\n"
        /* } scope */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a777e:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        "jmp .Lfa6d3c_000a7408\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a778d:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        "jmp .Lfa6d3c_000a76ed\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a779c:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        "jmp .Lfa6d3c_000a764d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a77ab:\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x30(%ebp)\n" /* keySize */
        "jmp .Lfa6d3c_000a6f8c\n"
    );
}
#endif

/* line 1282 — OrientedParticle_Update converted to C */
Bool OrientedParticle_Update(const OrientedParticle *_this)
{
    /* Same as Particle_Update + normal vector transform to world (0x24c → orient transform → 0x9c) */
    byte *self = (byte *)_this;
    int startTime = *(int *)(self + 0xb8);
    int killTime = *(int *)(self + 0xbc);
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime) return 0;
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    *(float *)(self + 0x3c) = normTime;
    if (normTime < 0.0f) return 0;

    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;
    if (boltFrame) {
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx >= 0) {
            int clTime = *(int *)(*(byte *)imp_cl + 0x864c);
            if (*(int *)(boltFrame + 4) != clTime) {
                *(int *)(boltFrame + 4) = clTime;
                if (!FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8)))
                    { *(int *)(boltFrame + 0x3c) = -1; *(int *)(boltFrame + 0x40) = -1; }
            }
            if (*(int *)(boltFrame + 0x3c) >= 0) orient = boltFrame + 8;
        }
    }

    if (!Particle_UpdateOrigin((const Particle *)_this, (const orientation_t *)orient)) return 0;

    if (orient) {
        OrientationPosToWorldPos(orient, (vec_t *)(self + 4), (vec_t *)(self + 0x7c));
        /* Transform normal direction to world */
        OrientationDirFromWorldDir(orient, (vec_t *)(self + 0x24c), (vec_t *)(self + 0x9c));
    } else {
        *(float *)(self + 0x7c) = *(float *)(self + 4); *(float *)(self + 0x80) = *(float *)(self + 8); *(float *)(self + 0x84) = *(float *)(self + 0xc);
        *(float *)(self + 0x9c) = *(float *)(self + 0x24c); *(float *)(self + 0xa0) = *(float *)(self + 0x250); *(float *)(self + 0xa4) = *(float *)(self + 0x254);
    }

    float radius;
    if (*(short *)(self + 0xa8) < 0) {
        float bf = *(float *)(self + 0x120);
        radius = (EvalCurve1(self + 0x174, normTime) + (EvalCurve1(self + 0x180, normTime) - EvalCurve1(self + 0x174, normTime)) * bf) * *(float *)(self + 0x174 + 8);
    } else {
        radius = EvalCurve1(self + 0x174, normTime) * *(float *)(self + 0x174 + 8);
    }
    *(float *)(self + 0x88) = radius;
    if (radius == 0.0f) { *(int *)(self + 0xa8) |= 0x01000000; return 1; }

    /* Rotation eval */
    if (*(byte *)(self + 0xaa) & 1) {
        float rot;
        if (*(byte *)(self + 0xaa) & 0x10) {
            float bf = *(float *)(self + 0x128);
            rot = (EvalCurve1(self + 0x18c, normTime) + (EvalCurve1(self + 0x198, normTime) - EvalCurve1(self + 0x18c, normTime)) * bf) * *(float *)(self + 0x18c + 8);
        } else {
            rot = EvalCurve1(self + 0x18c, normTime) * *(float *)(self + 0x18c + 8);
        }
        *(float *)(self + 0x8c) = rot;
    }

    Particle_UpdateRGB((const Particle *)_this);
    Particle_UpdateAlpha((const Particle *)_this);
    return 1;
}
#if 0 /* Original ASM (751 lines) */
__attribute__((naked))
Bool OrientedParticle_Update_asm(const OrientedParticle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1282 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%edi), %edx\n" /* line 232 */
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa77be_000a7b6e\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%edi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%edi)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa77be_000a780f\n"
        "movss %xmm1, 0x3c(%edi)\n" /* line 242 */
        ".Lfa77be_000a780f:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%edi), %xmm0\n"
        "ja .Lfa77be_000a7dfc\n"
        "movl 0xc0(%edi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa77be_000a7b20\n"
        ".Lfa77be_000a782b:\n"
        "movl $0, -0x34(%ebp)\n" /* or_ */
        "movl -0x34(%ebp), %eax\n" /* or_ */
        ".Lfa77be_000a7835:\n"
        "movl %eax, 4(%esp)\n" /* line 1294 */
        "movl %edi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je .Lfa77be_000a7b6e\n"
        "cmpw $0, 0xa8(%edi)\n" /* line 1018 */
        "js .Lfa77be_000a7b78\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1021 */
        "leal 0x174(%edi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a788d\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa77be_000a788d:\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a78a7\n"
        ".Lfa77be_000a789c:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a789c\n"
        /* } scope */
        ".Lfa77be_000a78a7:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%edi)\n"
        "cmpb $0, 0x104(%edi)\n" /* line 1027 */
        "jne .Lfa77be_000a7cc3\n"
        ".Lfa77be_000a78f8:\n"
        "movl 0x88(%edi), %eax\n" /* line 1036 */
        "movl %eax, 0x8c(%edi)\n"
        ".Lfa77be_000a7904:\n"
        "movl %edi, (%esp)\n" /* line 1300 | this */
        "calll Particle_UpdateRGB\n"
        "movl %edi, (%esp)\n" /* line 1301 | this */
        "calll Particle_UpdateAlpha\n"
        /* { scope 2: keySize, keySize */
        "testb $4, 0xaa(%edi)\n" /* line 1089 */
        "je .Lfa77be_000a7e58\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1090 */
        "movss 0x128(%edi), %xmm5\n" /* blendFactor */
        "leal 0x1b0(%edi), %ebx\n" /* source1 */
        "leal 0x1a4(%edi), %ecx\n" /* source0 */
        /* { scope 3: keySize */
        /* { scope 4 */
        "movl 0x1a4(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, -0x28(%ebp)\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a7968\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        ".Lfa77be_000a7968:\n"
        "movl -0x28(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7981\n"
        ".Lfa77be_000a7976:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7976\n"
        /* } scope */
        ".Lfa77be_000a7981:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 4 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x40(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x40(%ebp), %esi\n" /* keySize */
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a7f7d\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %esi\n" /* line 97 | keySize */
        "movl %esi, -0x1c(%ebp)\n" /* keySize */
        ".Lfa77be_000a79f8:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7a0e\n"
        ".Lfa77be_000a7a03:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7a03\n"
        /* } scope */
        ".Lfa77be_000a7a0e:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 55 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "addss %xmm4, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        /* } scope */
        ".Lfa77be_000a7a57:\n"
        "movl imp_theFxHelper, %ebx\n" /* line 1094 | source1 */
        "movl (%ebx), %eax\n" /* source1 */
        "cvtsi2ssl 0xc(%eax), %xmm0\n"
        "mulss lit4_002ed738, %xmm0\n" /* 0.009999999776482582f */
        "mulss %xmm0, %xmm3\n"
        "addss 0x44(%edi), %xmm3\n"
        "movss %xmm3, 0x44(%edi)\n"
        /* } scope */
        /* { scope 2: keySize, keySize */
        "movl 0x40(%edi), %eax\n" /* line 1110 */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* source1 */
        "movl %eax, (%esp)\n"
        "calll FxHelper_GetMaterialSubimageCount\n"
        "movl %eax, %ecx\n"
        "cmpl $1, %eax\n" /* line 1112 */
        "je .Lfa77be_000a7f6e\n"
        "movl (%ebx), %eax\n" /* line 1118 | source1 */
        "movl 4(%eax), %eax\n"
        "subl 0xb8(%edi), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x10c(%edi), %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "addl 0x108(%edi), %edx\n"
        "movl %edx, 0x94(%edi)\n"
        "movl 0x110(%edi), %eax\n" /* line 1120 */
        "testl %eax, %eax\n"
        "jne .Lfa77be_000a7ee9\n"
        "cmpl %edx, %ecx\n" /* line 1122 */
        "jle .Lfa77be_000a7e48\n"
        /* } scope */
        ".Lfa77be_000a7ad3:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 1306 | or_ */
        "testl %ecx, %ecx\n"
        "je .Lfa77be_000a7f2e\n"
        "leal 0x7c(%edi), %eax\n" /* line 1308 | this */
        "movl %eax, 8(%esp)\n"
        "leal 4(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n" /* or_ */
        "movl %edx, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        "leal 0x48(%edi), %eax\n" /* line 1309 | this */
        "movl %eax, 8(%esp)\n"
        "leal 0x24c(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %esi\n" /* or_, keySize */
        "movl %esi, (%esp)\n" /* keySize */
        "calll OrientationDirToWorldDir\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1318 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa77be_000a7b20:\n"
        "movl 0xc0(%edi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, keySize */
        "movl 0x3c(%ebx), %esi\n" /* line 90 | key, keySize */
        "testl %esi, %esi\n" /* keySize */
        "js .Lfa77be_000a7b6e\n"
        "movl imp_cl, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa77be_000a7e33\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %esi\n" /* line 102 | key, keySize */
        "movl %esi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa77be_000a7e36\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7b6e:\n"
        "xorl %eax, %eax\n" /* line 201 */
        /* } scope */
        /* } scope */
        ".Lfa77be_000a7b70:\n"
        "addl $0x4c, %esp\n" /* line 1318 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa77be_000a7b78:\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1019 */
        "movss 0x120(%edi), %xmm5\n" /* blendFactor */
        "leal 0x180(%edi), %ebx\n" /* source1 */
        "leal 0x174(%edi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, -0x30(%ebp)\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a7bbf\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        ".Lfa77be_000a7bbf:\n"
        "movl -0x30(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7bd8\n"
        ".Lfa77be_000a7bcd:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7bcd\n"
        /* } scope */
        ".Lfa77be_000a7bd8:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x40(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x40(%ebp), %esi\n" /* keySize */
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a8025\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %esi\n" /* line 97 | keySize */
        "movl %esi, -0x24(%ebp)\n" /* keySize */
        ".Lfa77be_000a7c4f:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7c65\n"
        ".Lfa77be_000a7c5a:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7c5a\n"
        /* } scope */
        ".Lfa77be_000a7c65:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%edi)\n"
        "cmpb $0, 0x104(%edi)\n" /* line 1027 */
        "je .Lfa77be_000a78f8\n"
        ".Lfa77be_000a7cc3:\n"
        "testb $1, 0xaa(%edi)\n" /* line 1029 */
        "je .Lfa77be_000a7f85\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1030 */
        "movss 0x124(%edi), %xmm5\n" /* blendFactor */
        "leal 0x198(%edi), %ebx\n" /* source1 */
        "leal 0x18c(%edi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, -0x2c(%ebp)\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa77be_000a802d\n"
        ".Lfa77be_000a7d11:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7e14\n"
        /* } scope */
        ".Lfa77be_000a7d23:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x40(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x40(%ebp), %esi\n" /* keySize */
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa77be_000a804b\n"
        "movl -0x20(%ebp), %esi\n" /* keySize */
        ".Lfa77be_000a7d90:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7da6\n"
        ".Lfa77be_000a7d9b:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7d9b\n"
        /* } scope */
        ".Lfa77be_000a7da6:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1030 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x8c(%edi)\n"
        "jmp .Lfa77be_000a7904\n"
        ".Lfa77be_000a7dfc:\n"
        "movss %xmm0, 0x3c(%edi)\n" /* line 244 */
        "movl 0xc0(%edi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa77be_000a7b20\n"
        "jmp .Lfa77be_000a782b\n"
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a7e14:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7d23\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7e14\n"
        "jmp .Lfa77be_000a7d23\n"
        ".Lfa77be_000a7e33:\n"
        "leal 8(%ebx), %esi\n" /* key, keySize */
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7e36:\n"
        "movl %esi, -0x34(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %esi, %esi\n" /* line 210 | keySize */
        "je .Lfa77be_000a7b6e\n"
        "movl %esi, %eax\n" /* keySize */
        "jmp .Lfa77be_000a7835\n"
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7e48:\n"
        "movl %edx, %eax\n" /* line 1138 */
        "cltd\n"
        "idivl %ecx\n"
        "movl %edx, 0x94(%edi)\n"
        "jmp .Lfa77be_000a7ad3\n"
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7e58:\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1092 */
        "leal 0x1a4(%edi), %ecx\n" /* source */
        /* { scope 3: keySize */
        /* { scope 4 */
        "movl 0x1a4(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a7e8e\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa77be_000a7e8e:\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7ea8\n"
        ".Lfa77be_000a7e9d:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7e9d\n"
        /* } scope */
        ".Lfa77be_000a7ea8:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 32 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        "jmp .Lfa77be_000a7a57\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7ee9:\n"
        "subl $1, %eax\n" /* line 1125 */
        "jne .Lfa77be_000a7ad3\n"
        "movl 0x114(%edi), %eax\n" /* line 1127 */
        "testl %eax, %eax\n"
        "jle .Lfa77be_000a805d\n"
        "cmpl %edx, %ecx\n" /* line 1129 */
        "jg .Lfa77be_000a7ad3\n"
        "addl $1, %eax\n" /* line 1131 */
        "imull %ecx, %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lfa77be_000a7e48\n"
        "movl $0, 0x114(%edi)\n" /* line 1133 */
        "leal -1(%ecx), %eax\n" /* line 1134 */
        "movl %eax, 0x94(%edi)\n"
        "jmp .Lfa77be_000a7ad3\n"
        /* } scope */
        ".Lfa77be_000a7f2e:\n"
        "leal 0x7c(%edi), %ecx\n" /* line 1313 | this, to */
        "leal 4(%edi), %edx\n" /* this, from */
        /* { scope 2: keySize, keySize */
        "movl 4(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x48(%edi), %ecx\n" /* line 1314 | this, to */
        "leal 0x24c(%edi), %edx\n" /* this, from */
        /* { scope 2: keySize, keySize */
        "movl 0x24c(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x48(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lfa77be_000a7b70\n"
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7f6e:\n"
        "movl $0, 0x94(%edi)\n" /* line 1114 */
        "jmp .Lfa77be_000a7ad3\n"
        ".Lfa77be_000a7f7d:\n"
        "movl -0x1c(%ebp), %esi\n" /* keySize */
        "jmp .Lfa77be_000a79f8\n"
        /* } scope */
        ".Lfa77be_000a7f85:\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1032 */
        "leal 0x18c(%edi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa77be_000a803c\n"
        ".Lfa77be_000a7fb5:\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a800d\n"
        /* } scope */
        ".Lfa77be_000a7fc4:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1032 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x8c(%edi)\n"
        "jmp .Lfa77be_000a7904\n"
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a800d:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7fc4\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a800d\n"
        "jmp .Lfa77be_000a7fc4\n"
        ".Lfa77be_000a8025:\n"
        "movl -0x24(%ebp), %esi\n" /* keySize */
        "jmp .Lfa77be_000a7c4f\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a802d:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "jmp .Lfa77be_000a7d11\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a803c:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        "jmp .Lfa77be_000a7fb5\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a804b:\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %esi\n" /* line 97 | keySize */
        "movl %esi, -0x20(%ebp)\n" /* keySize */
        "jmp .Lfa77be_000a7d90\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a805d:\n"
        "cmpl %edx, %ecx\n" /* line 1144 */
        "jg .Lfa77be_000a7ad3\n"
        "leal -1(%ecx), %eax\n" /* line 1145 */
        "movl %eax, 0x94(%edi)\n"
        "jmp .Lfa77be_000a7ad3\n"
    );
}
#endif

/* Particle_Update — core particle tick: normTime, origin update, radius eval, RGB/alpha update */
extern void OrientationPosToWorldPos(void *orient, vec_t *localPos, vec_t *worldPos);
Bool Particle_Update(const Particle *_this, const Particle *_this_1, const Cloud *_this_2)
{
    (void)_this_1; (void)_this_2;
    byte *self = (byte *)_this;
    int startTime = *(int *)(self + 0xb8);
    int killTime = *(int *)(self + 0xbc);
    int curTime = *(int *)(*(byte **)imp_theFxHelper + 4);

    if (startTime > curTime)
        return 0; /* not started yet */

    /* Compute normalized time */
    float normTime = (float)(curTime - startTime) / (float)(killTime - startTime);
    if (normTime > 1.0f) normTime = 1.0f;
    *(float *)(self + 0x3c) = normTime;
    if (normTime < 0.0f)
        return 0;

    /* Get bolt orientation if present */
    byte *boltFrame = *(byte **)(self + 0xc0);
    void *orient = NULL;
    if (boltFrame) {
        /* Get cached orientation from bolt frame */
        int boneIdx = *(int *)(boltFrame + 0x3c);
        if (boneIdx >= 0) {
            int cachedTime = *(int *)(boltFrame + 4);
            int clTime = *(int *)(*(byte *)imp_cl + 0x864c);
            if (cachedTime != clTime) {
                *(int *)(boltFrame + 4) = clTime;
                Bool ok = FX_GetBoneOrientation((void *)(boltFrame + 0x3c), (void *)(boltFrame + 8));
                if (!ok) { *(int *)(boltFrame + 0x3c) = -1; *(int *)(boltFrame + 0x40) = -1; }
            }
            if (*(int *)(boltFrame + 0x3c) >= 0)
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
        *(float *)(self + 0x7c) = worldPos[0];
        *(float *)(self + 0x80) = worldPos[1];
        *(float *)(self + 0x84) = worldPos[2];
    } else {
        *(float *)(self + 0x7c) = *(float *)(self + 4);
        *(float *)(self + 0x80) = *(float *)(self + 8);
        *(float *)(self + 0x84) = *(float *)(self + 0xc);
    }

    /* Evaluate radius (1-component curve with blend) */
    float radius;
    if (*(short *)(self + 0xa8) < 0) {
        /* Blend path */
        float blendFactor = *(float *)(self + 0x120);
        float v0 = EvalCurve1(self + 0x174, normTime);
        float v1 = EvalCurve1(self + 0x180, normTime);
        radius = (v0 + (v1 - v0) * blendFactor) * *(float *)(self + 0x174 + 8);
    } else {
        radius = EvalCurve1(self + 0x174, normTime) * *(float *)(self + 0x174 + 8);
    }
    *(float *)(self + 0x88) = radius;

    if (radius == 0.0f) {
        *(int *)(self + 0xa8) |= 0x01000000; /* mark for removal */
        return 1;
    }

    /* Check sequence params */
    if (*(byte *)(self + 0x104)) {
        if (*(byte *)(self + 0xaa) & 1) {
            /* TODO: evaluate rotation curve — complex, skip for now */
        }
    }

    /* Evaluate rotation */
    float rotation;
    if (*(byte *)(self + 0xaa) & 1) {
        rotation = EvalCurve1(self + 0x18c, normTime) * *(float *)(self + 0x18c + 8);
    } else {
        rotation = 0.0f;
    }
    *(float *)(self + 0x8c) = rotation;

    /* Update RGB and Alpha */
    Particle_UpdateRGB(_this);
    Particle_UpdateAlpha(_this);

    return 1;
}
#if 0 /* Original ASM (209 lines) */
__attribute__((naked))
Bool Particle_Update_asm(const Particle * _this, const Particle * _this_1, const Cloud * _this_2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 410 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%edi), %edx\n" /* line 232 | keySize */
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg 0xa8369\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%edi), %eax\n" /* keySize */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%edi)\n" /* keySize */
        "movss lit4_002ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa8074_000a80c5\n"
        "movss %xmm1, 0x3c(%edi)\n" /* line 242 | keySize */
        ".Lfa8074_000a80c5:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%edi), %xmm0\n" /* keySize */
        "ja 0xa8373\n"
        "movl 0xc0(%edi), %eax\n" /* line 207 | keySize */
        "testl %eax, %eax\n"
        "jne 0xa8323\n"
        "xorl %ebx, %ebx\n" /* key */
        "movl %ebx, 4(%esp)\n" /* line 422 | or_ */
        "movl %edi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je 0xa8369\n"
        "testl %ebx, %ebx\n" /* line 425 | or_ */
        "je 0xa8387\n"
        "leal 0x7c(%edi), %eax\n" /* line 426 | this */
        "movl %eax, 8(%esp)\n"
        "leal 4(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* or_ */
        "calll OrientationPosToWorldPos\n"
        "cmpw $0, 0xa8(%edi)\n" /* line 1018 | this */
        "jns 0xa83c0\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1019 | this */
        "movss 0x120(%edi), %xmm5\n" /* this, blendFactor */
        "leal 0x180(%edi), %ebx\n" /* this, source1 */
        "leal 0x174(%edi), %ecx\n" /* this, source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%edi), %edx\n" /* line 91 | keySize */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa8074_000a8168\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        ".Lfa8074_000a8168:\n"
        "movl -0x30(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa8074_000a8181\n"
        ".Lfa8074_000a8176:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa8074_000a8176\n"
        /* } scope */
        ".Lfa8074_000a8181:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %edx\n" /* line 91 | key */
        "movl %edx, -0x40(%ebp)\n"
        "movl %edx, %esi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe 0xa8521\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %esi\n" /* line 97 | keySize */
        "movl %esi, -0x24(%ebp)\n" /* keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa8074_000a820d\n"
        ".Lfa8074_000a8202:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa8074_000a8202\n"
        /* } scope */
        ".Lfa8074_000a820d:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%edi)\n" /* this */
        "movaps %xmm4, %xmm0\n"
        "pxor %xmm6, %xmm6\n" /* line 433 */
        "ucomiss %xmm6, %xmm0\n"
        "jp .Lfa8074_000a8270\n"
        "je 0xa83a4\n"
        ".Lfa8074_000a8270:\n"
        "cmpb $0, 0x104(%edi)\n" /* line 1027 | this */
        "je 0xa845c\n"
        "testb $1, 0xaa(%edi)\n" /* line 1029 | this */
        "jne 0xa8529\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1032 | this */
        "leal 0x18c(%edi), %ecx\n" /* this, source */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%edi), %edx\n" /* line 91 | keySize */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa8074_000a82c0\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa8074_000a82c0:\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa8074_000a82da\n"
        ".Lfa8074_000a82cf:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa8074_000a82cf\n"
        /* } scope */
        ".Lfa8074_000a82da:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1032 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
    );
}
#endif

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
    if (*(byte *)(a + 4)) { /* isReading */
        int v; FxArchive_ReadData(arch, &v, 4); *(int *)(self + offset) = v;
    } else {
        int v = *(int *)(self + offset); FxArchive_WriteData(arch, &v, 4);
    }
}
static void ArchiveVec3(void *arch, byte *self, int offset)
{
    byte *a = (byte *)arch;
    if (*(byte *)(a + 4)) {
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
    FxBoltFramePtr_Archive((const FxBoltFramePtr *)(self + 0xc0), arch);   /* boltFrame */

    if (*(byte *)(a + 4)) { /* isReading: post-load setup */
        *(int *)(self + 0xac) = FX_GetCluster((vec_t *)(self + 0x7c));
        FX_SetSortGroup(self);
    }
}
#if 0 /* Original ASM */
__attribute__((naked))
void Effect_Archive_asm(const Effect * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 285 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "leal 4(%edi), %esi\n" /* line 289 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa88b2_000a8a83\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8ae4\n"
        /* { scope 1: f */
        ".Lfa88b2_000a88ec:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0xb8(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8b0e\n"
        /* { scope 1: f */
        ".Lfa88b2_000a8916:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0xbc(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8b38\n"
        /* { scope 1: f */
        ".Lfa88b2_000a8940:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0xa8(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8b62\n"
        /* { scope 1: f */
        ".Lfa88b2_000a896a:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0x10(%edi)\n"
        "leal 0x14(%edi), %esi\n" /* line 294 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa88b2_000a8b8c\n"
        ".Lfa88b2_000a8994:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x20(%edi), %esi\n" /* line 295 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa88b2_000a8bf0\n"
        ".Lfa88b2_000a89b5:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        ".Lfa88b2_000a89c9:\n"
        "leal 0x2c(%edi), %eax\n" /* line 296 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "leal 0x30(%edi), %eax\n" /* line 297 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "leal 0x40(%edi), %esi\n" /* line 300 | this, v */
        "movl %esi, 4(%esp)\n" /* v */
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveFxGfxEntity\n"
        "leal 0x34(%edi), %eax\n" /* line 305 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8c4c\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0x38(%edi)\n"
        ".Lfa88b2_000a8a2c:\n"
        "movl %esi, 4(%esp)\n" /* line 309 | v */
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveMaterial\n"
        "leal 0xb4(%edi), %eax\n" /* line 310 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveModel\n"
        "movl %ebx, 4(%esp)\n" /* line 312 | arch */
        "leal 0xc0(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxBoltFramePtr_Archive\n"
        "cmpb $0, 4(%ebx)\n" /* line 314 | arch */
        "je .Lfa88b2_000a8a7b\n"
        "leal 0x7c(%edi), %eax\n" /* line 316 | this */
        "movl %eax, (%esp)\n"
        "calll FX_GetCluster\n"
        "movl %eax, 0xac(%edi)\n" /* this */
        "movl %edi, (%esp)\n" /* line 317 | this */
        "calll FX_SetSortGroup\n"
        ".Lfa88b2_000a8a7b:\n"
        "addl $0x2c, %esp\n" /* line 319 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa88b2_000a8a83:\n"
        "movl 4(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa88b2_000a88ec\n"
        ".Lfa88b2_000a8ae4:\n"
        "movl 0xb8(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa88b2_000a8916\n"
        ".Lfa88b2_000a8b0e:\n"
        "movl 0xbc(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa88b2_000a8940\n"
        ".Lfa88b2_000a8b38:\n"
        "movl 0xa8(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa88b2_000a896a\n"
        ".Lfa88b2_000a8b62:\n"
        "movl 0x10(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "leal 0x14(%edi), %esi\n" /* line 294 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa88b2_000a8994\n"
        ".Lfa88b2_000a8b8c:\n"
        "movl 0x14(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x20(%edi), %esi\n" /* line 295 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa88b2_000a89b5\n"
        ".Lfa88b2_000a8bf0:\n"
        "movl 0x20(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa88b2_000a89c9\n"
        /* } scope */
        /* } scope */
        ".Lfa88b2_000a8c4c:\n"
        "movl 0x38(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa88b2_000a8a2c\n"
    );
}
#endif

/* Light_Archive — Effect_Archive + 4 channels + 2 floats (0xc4, 0xc8) */
void Light_Archive(const Light *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;
    Effect_Archive((const Effect *)_this, arch);
    FxArchive_ArchiveChannelInstance(arch, self + 0xcc);
    FxArchive_ArchiveChannelInstance(arch, self + 0xd8);
    FxArchive_ArchiveChannelInstance(arch, self + 0xe4);
    FxArchive_ArchiveChannelInstance(arch, self + 0xf0);
    /* Float at 0xc4 */
    if (*(byte *)(a + 4)) { float f; FxArchive_ReadData(arch, &f, 4); *(float *)(self + 0xc4) = f; }
    else { float f = *(float *)(self + 0xc4); FxArchive_WriteData(arch, &f, 4); }
    /* Float at 0xc8 */
    if (*(byte *)(a + 4)) { float f; FxArchive_ReadData(arch, &f, 4); *(float *)(self + 0xc8) = f; }
    else { float f = *(float *)(self + 0xc8); FxArchive_WriteData(arch, &f, 4); }
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
        0x1a4, 0x1b0, 0x1bc, 0x1c8, 0x1d4, 0x1e0, 0x1ec, 0x1f8,
        0x204, 0x210, 0x21c, 0x228, 0x234, 0x240, -1
    };
    for (i = 0; chOffsets[i] >= 0; i++)
        FxArchive_ArchiveChannelInstance(arch, self + chOffsets[i]);
}
#if 0 /* Original ASM (608 lines) */
__attribute__((naked))
void Particle_Archive_asm(const Particle * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1166 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "movl %ebx, 4(%esp)\n" /* line 1170 | arch */
        "movl %esi, (%esp)\n" /* this */
        "calll Effect_Archive\n"
        "leal 0xc4(%esi), %edi\n" /* line 1172 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a91ce\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0xd0(%esi), %edi\n" /* line 1174 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a9238\n"
        ".Lfa8d78_000a8dc7:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0xdc(%esi), %edi\n" /* line 1175 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a92a2\n"
        ".Lfa8d78_000a8deb:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0xe8(%esi), %edi\n" /* line 1176 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a930c\n"
        ".Lfa8d78_000a8e0f:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a9370\n"
        /* { scope 1: f */
        ".Lfa8d78_000a8e2d:\n"
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x100(%esi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 164 */
        "je .Lfa8d78_000a939a\n"
        /* { scope 1: f */
        ".Lfa8d78_000a8e57:\n"
        "movl $1, 8(%esp)\n" /* line 84 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movzbl -0x1c(%ebp), %eax\n" /* line 165 | f */
        "movb %al, 0x104(%esi)\n"
        ".Lfa8d78_000a8e78:\n"
        "leal 0x144(%esi), %eax\n" /* line 1186 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x150(%esi), %eax\n" /* line 1187 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x15c(%esi), %eax\n" /* line 1188 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x168(%esi), %eax\n" /* line 1189 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x174(%esi), %eax\n" /* line 1190 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x180(%esi), %eax\n" /* line 1191 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x18c(%esi), %eax\n" /* line 1192 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x198(%esi), %eax\n" /* line 1193 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1a4(%esi), %eax\n" /* line 1194 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1b0(%esi), %eax\n" /* line 1195 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1bc(%esi), %eax\n" /* line 1197 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1c8(%esi), %eax\n" /* line 1198 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1d4(%esi), %eax\n" /* line 1199 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1e0(%esi), %eax\n" /* line 1200 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1ec(%esi), %eax\n" /* line 1201 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1f8(%esi), %eax\n" /* line 1202 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x204(%esi), %eax\n" /* line 1204 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x210(%esi), %eax\n" /* line 1205 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x21c(%esi), %eax\n" /* line 1206 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x228(%esi), %eax\n" /* line 1207 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x234(%esi), %eax\n" /* line 1208 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x240(%esi), %eax\n" /* line 1209 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa8d78_000a95a9\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | f */
        "movl %eax, 0x108(%esi)\n"
        ".Lfa8d78_000a902e:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a9584\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x10c(%esi)\n"
        ".Lfa8d78_000a9058:\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa8d78_000a955f\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | f */
        "movl %eax, 0x110(%esi)\n"
        ".Lfa8d78_000a9082:\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa8d78_000a953a\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | f */
        "movl %eax, 0x114(%esi)\n"
        ".Lfa8d78_000a90ac:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a9515\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x118(%esi)\n"
        ".Lfa8d78_000a90d6:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a94f0\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x11c(%esi)\n"
        ".Lfa8d78_000a9100:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a94cb\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x120(%esi)\n"
        ".Lfa8d78_000a912a:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a94a6\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x124(%esi)\n"
        ".Lfa8d78_000a9154:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a9481\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x128(%esi)\n"
        ".Lfa8d78_000a917e:\n"
        "leal 0x12c(%esi), %edi\n" /* line 1220 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a9422\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        ".Lfa8d78_000a91a2:\n"
        "leal 0x138(%esi), %edi\n" /* line 1221 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a93c0\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "addl $0x2c, %esp\n" /* line 1222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa8d78_000a91ce:\n"
        "movl 0xc4(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0xd0(%esi), %edi\n" /* line 1174 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa8d78_000a8dc7\n"
        ".Lfa8d78_000a9238:\n"
        "movl 0xd0(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0xdc(%esi), %edi\n" /* line 1175 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa8d78_000a8deb\n"
        ".Lfa8d78_000a92a2:\n"
        "movl 0xdc(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0xe8(%esi), %edi\n" /* line 1176 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa8d78_000a8e0f\n"
        ".Lfa8d78_000a930c:\n"
        "movl 0xe8(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "jne .Lfa8d78_000a8e2d\n"
        ".Lfa8d78_000a9370:\n"
        "movl 0x100(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 164 */
        "jne .Lfa8d78_000a8e57\n"
        ".Lfa8d78_000a939a:\n"
        "movzbl 0x104(%esi), %eax\n" /* line 165 */
        "movb %al, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $1, 8(%esp)\n" /* line 123 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a8e78\n"
        /* } scope */
        ".Lfa8d78_000a93c0:\n"
        "movl 0x138(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa8d78_000a9422:\n"
        "movl 0x12c(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a91a2\n"
        /* } scope */
        /* } scope */
        ".Lfa8d78_000a9481:\n"
        "movl 0x128(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a917e\n"
        /* } scope */
        ".Lfa8d78_000a94a6:\n"
        "movl 0x124(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a9154\n"
        /* } scope */
        ".Lfa8d78_000a94cb:\n"
        "movl 0x120(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a912a\n"
        /* } scope */
        ".Lfa8d78_000a94f0:\n"
        "movl 0x11c(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a9100\n"
        /* } scope */
        ".Lfa8d78_000a9515:\n"
        "movl 0x118(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a90d6\n"
        /* } scope */
        ".Lfa8d78_000a953a:\n"
        "movl 0x114(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a90ac\n"
        /* } scope */
        ".Lfa8d78_000a955f:\n"
        "movl 0x110(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a9082\n"
        /* } scope */
        ".Lfa8d78_000a9584:\n"
        "movl 0x10c(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a9058\n"
        /* } scope */
        ".Lfa8d78_000a95a9:\n"
        "movl 0x108(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a902e\n"
    );
}
#endif

/* OrientedParticle_Archive — serialize normal vec3 at offset 0x24c */
extern void FxArchive_ReadData(void *arch, void *data, int size);
extern void FxArchive_WriteData(void *arch, void *data, int size);
void OrientedParticle_Archive(const OrientedParticle *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;
    Particle_Archive((const Particle *)_this, arch);
    if (*(byte *)(a + 4)) { /* isReading */
        FxArchive_ReadData(arch, self + 0x24c, 0xc);
    } else {
        float f;
        f = *(float *)(self + 0x24c); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + 0x250); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + 0x254); FxArchive_WriteData(arch, &f, 4);
    }
}

/* Cloud_Archive — serialize vec3, 2 channel instances, float, byte */
void Cloud_Archive(const Cloud *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;
    Particle_Archive((const Particle *)_this, arch);
    /* Vec3 at 0x24c */
    if (*(byte *)(a + 4)) {
        FxArchive_ReadData(arch, self + 0x24c, 0xc);
    } else {
        float f;
        f = *(float *)(self + 0x24c); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + 0x250); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + 0x254); FxArchive_WriteData(arch, &f, 4);
    }
    /* Two ChannelInstances */
    FxArchive_ArchiveChannelInstance(arch, self + 0x264);
    FxArchive_ArchiveChannelInstance(arch, self + 0x270);
    /* Float at 0x260 */
    if (*(byte *)(a + 4)) {
        float f; FxArchive_ReadData(arch, &f, 4); *(float *)(self + 0x260) = f;
    } else {
        float f = *(float *)(self + 0x260); FxArchive_WriteData(arch, &f, 4);
    }
    /* Byte at 0x25c */
    if (*(byte *)(a + 4)) {
        byte b; FxArchive_ReadData(arch, &b, 1); *(byte *)(self + 0x25c) = b;
    } else {
        byte b = *(byte *)(self + 0x25c); FxArchive_WriteData(arch, &b, 1);
    }
}
#if 0 /* Original ASM — partial preserved */
__attribute__((naked))
void Cloud_Archive_asm(const Cloud * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x260(%edi)\n"
        ".Lfa966e_000a96fb:\n"
        "cmpb $0, 4(%esi)\n" /* line 164 */
        "je .Lfa966e_000a978d\n"
        /* { scope 1: f */
        "movl $1, 8(%esp)\n" /* line 84 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movzbl -0x1c(%ebp), %eax\n" /* line 165 | f */
        "movb %al, 0x25c(%edi)\n"
        "addl $0x2c, %esp\n" /* line 1483 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa966e_000a972e:\n"
        "movl 0x24c(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa966e_000a96ad\n"
        /* } scope */
        /* } scope */
        ".Lfa966e_000a978d:\n"
        "movzbl 0x25c(%edi), %eax\n" /* line 165 */
        "movb %al, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $1, 8(%esp)\n" /* line 123 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1483 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa966e_000a97b6:\n"
        "movl 0x260(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa966e_000a96fb\n"
    );
}
#endif

/* Line_Archive — serialize normal vec3 at offset 0x24c (same as OrientedParticle) */
void Line_Archive(const Line *_this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    byte *a = (byte *)arch;
    Particle_Archive((const Particle *)_this, arch);
    if (*(byte *)(a + 4)) {
        FxArchive_ReadData(arch, self + 0x24c, 0xc);
    } else {
        float f;
        f = *(float *)(self + 0x24c); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + 0x250); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + 0x254); FxArchive_WriteData(arch, &f, 4);
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
    if (*(byte *)(a + 4)) {
        FxArchive_ReadData(arch, self + 0x24c, 0xc);
    } else {
        float f;
        f = *(float *)(self + 0x24c); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + 0x250); FxArchive_WriteData(arch, &f, 4);
        f = *(float *)(self + 0x254); FxArchive_WriteData(arch, &f, 4);
    }
    /* Two ChannelInstances */
    FxArchive_ArchiveChannelInstance(arch, self + 0x260);
    FxArchive_ArchiveChannelInstance(arch, self + 0x26c);
    /* Float at 0x25c */
    if (*(byte *)(a + 4)) {
        float f; FxArchive_ReadData(arch, &f, 4); *(float *)(self + 0x25c) = f;
    } else {
        float f = *(float *)(self + 0x25c); FxArchive_WriteData(arch, &f, 4);
    }
}
#if 0 /* Original ASM — partial, rest is below */
__attribute__((naked))
void Tail_Archive_asm(const Tail * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        ".Lfa987c_000a990d:\n"
        "movl 0x24c(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa987c_000a98b7\n"
        /* } scope */
        /* } scope */
        ".Lfa987c_000a996c:\n"
        "movl 0x25c(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1711 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

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
#if 0 /* Original ASM */
__attribute__((naked))
void Emitter_Archive_asm(const Emitter * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2104 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "movl %ebx, 4(%esp)\n" /* line 2108 | arch */
        "movl %edi, (%esp)\n" /* this */
        "calll Particle_Archive\n"
        "leal 0x24c(%edi), %esi\n" /* line 2110 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9b3d\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x258(%edi), %esi\n" /* line 2111 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9ba7\n"
        ".Lfa999e_000a99ed:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x264(%edi), %esi\n" /* line 2112 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9c11\n"
        ".Lfa999e_000a9a11:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa999e_000a9c75\n"
        /* { scope 1: f */
        ".Lfa999e_000a9a2f:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0x270(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa999e_000a9c9f\n"
        /* { scope 1: f */
        ".Lfa999e_000a9a59:\n"
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | i */
        "movl %eax, 0x274(%edi)\n"
        "leal 0x278(%edi), %esi\n" /* line 2116 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9ccf\n"
        ".Lfa999e_000a9a89:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x284(%edi), %esi\n" /* line 2117 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9d39\n"
        ".Lfa999e_000a9aad:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x290(%edi), %eax\n" /* line 2119 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa999e_000a9daf\n"
        /* { scope 1: f */
        ".Lfa999e_000a9add:\n"
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | i */
        "movl %eax, 0x294(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa999e_000a9dd9\n"
        /* { scope 1: f */
        ".Lfa999e_000a9b07:\n"
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | i */
        "movl %eax, 0x298(%edi)\n"
        "movl 0xb4(%edi), %eax\n" /* line 2124 | this */
        "testl %eax, %eax\n"
        "je .Lfa999e_000a9e07\n"
        ".Lfa999e_000a9b35:\n"
        "addl $0x2c, %esp\n" /* line 2126 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa999e_000a9b3d:\n"
        "movl 0x24c(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x258(%edi), %esi\n" /* line 2111 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa999e_000a99ed\n"
        ".Lfa999e_000a9ba7:\n"
        "movl 0x258(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x264(%edi), %esi\n" /* line 2112 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa999e_000a9a11\n"
        ".Lfa999e_000a9c11:\n"
        "movl 0x264(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa999e_000a9a2f\n"
        ".Lfa999e_000a9c75:\n"
        "movl 0x270(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "jne .Lfa999e_000a9a59\n"
        ".Lfa999e_000a9c9f:\n"
        "movl 0x274(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "leal 0x278(%edi), %esi\n" /* line 2116 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa999e_000a9a89\n"
        ".Lfa999e_000a9ccf:\n"
        "movl 0x278(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x284(%edi), %esi\n" /* line 2117 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa999e_000a9aad\n"
        ".Lfa999e_000a9d39:\n"
        "movl 0x284(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x290(%edi), %eax\n" /* line 2119 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "jne .Lfa999e_000a9add\n"
        ".Lfa999e_000a9daf:\n"
        "movl 0x294(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "jne .Lfa999e_000a9b07\n"
        ".Lfa999e_000a9dd9:\n"
        "movl 0x298(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "movl 0xb4(%edi), %eax\n" /* line 2124 | this */
        "testl %eax, %eax\n"
        "jne .Lfa999e_000a9b35\n"
        ".Lfa999e_000a9e07:\n"
        "andl $0xffffffef, 0xa8(%edi)\n" /* line 2125 | this */
        "addl $0x2c, %esp\n" /* line 2126 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

/* line 1732 */
/* Cylinder D0 destructor — cleanup bolt frame + delete this */
void ZN8CylinderD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN8CylinderD0Ev(void) /* Cylinder_~Cylinder */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN8CylinderD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 1732 */
/* Cylinder D1 destructor — cleanup bolt frame */
void ZN8CylinderD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN8CylinderD1Ev(void) /* Cylinder_~Cylinder */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN8CylinderD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
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
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN16OrientedParticleD1Ev(void) /* OrientedParticle_~OrientedParticle */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN16OrientedParticleD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 1265 */
/* OrientedParticle D0 destructor — cleanup bolt frame + delete this */
void ZN16OrientedParticleD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN16OrientedParticleD0Ev(void) /* OrientedParticle_~OrientedParticle */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN16OrientedParticleD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
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
        *(float *)(p + 0x24c + i * 4) = flrand(-1.0f, 1.0f);
    }
}

/* line 1347 */
/* Cloud D1 destructor — cleanup bolt frame */
void ZN5CloudD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN5CloudD1Ev(void) /* Cloud_~Cloud */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN5CloudD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 1347 */
/* Cloud D0 destructor — cleanup bolt frame + delete this */
void ZN5CloudD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN5CloudD0Ev(void) /* Cloud_~Cloud */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN5CloudD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
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
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN4LineD1Ev(void) /* Line_~Line */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN4LineD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 1504 */
/* Line D0 destructor — cleanup bolt frame + delete this */
void ZN4LineD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN4LineD0Ev(void) /* Line_~Line */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN4LineD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
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
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN4TailD1Ev(void) /* Tail_~Tail */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN4TailD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 1584 */
/* Tail D0 destructor — cleanup bolt frame + delete this */
void ZN4TailD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN4TailD0Ev(void) /* Tail_~Tail */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN4TailD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
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
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN7EmitterD1Ev(void) /* Emitter_~Emitter */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN7EmitterD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 1809 */
/* Emitter D0 destructor — cleanup bolt frame + delete this */
void ZN7EmitterD0Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN7EmitterD0Ev(void) /* Emitter_~Emitter */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN7EmitterD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
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
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
    if (self) __ZdaPv(self);
}
__attribute__((naked))
void ZN5FlashD0Ev(void) /* Flash_~Flash */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN5FlashD0Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 282 */
/* Flash D1 destructor — cleanup bolt frame */
void ZN5FlashD1Ev_impl(void *_this) {
    byte *self = (byte *)_this;
    *(void **)self = __ZTV6Effect + 8;
    FxBoltFrame_ReleaseHelper(*(byte **)(self + 0xc0));
}
__attribute__((naked))
void ZN5FlashD1Ev(void) /* Flash_~Flash */
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "calll ZN5FlashD1Ev_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}


