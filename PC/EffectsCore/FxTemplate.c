/* ASM dump from: FxTemplate.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxTemplate.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/GenericParser2.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/EffectsCore/FxTemplate.h"
 *   #include "PC/universal/com_vector.h"
 */

extern const FxFlagEntry fxAttributeFlags[26]; /* 0x0 */
extern const FxFlagEntry fxSpawnFlags[13]; /* 0x0 */
extern Bool g_rendererExists; /* 0x0 */

extern MaterialHandle Material_RegisterHandle(const char *name, int imageTrack, int materialType);
extern void MediaHandles_Shutdown(MediaHandles *handles);
extern void Com_Printf(const char *fmt, ...);
extern Bool Com_ValidXModelName(const char *name);
extern struct XModel * FX_XModelPrecache(const char *name);
extern float flrand(float min, float max);

/* Additional externs needed by converted functions */
extern void *Hunk_AllocateTempMemoryInternal(int size);
extern void Hunk_FreeTempMemory(void *buf);
extern const FxCurve *FxCurve_AllocAndCreateWithKeys(const float *keyArray, int dimensionCount, int keyCount);
extern void FxChannel_CreateDefault(FxChannel *createe, int dimensions, float value1, float value2);
extern void FxChannel_CreateViaMigration(const FxChannelBackwardCompatible *source, int dimensions, float lifetime, int forceUnitScale, FxChannel *target);
extern Bool GPValue_IsList(const GPValue *_this);
extern const char *GPValue_GetTopValue(const GPValue *_this);
extern float MediaHandles_AddHandle(const MediaHandles *_this, TMediaElement item);
extern float MediaHandles_AddEffect(const MediaHandles *_this, EffectTemplate *fx);
extern EffectTemplate *FX_RegisterEffect(const char *fileName);
extern int I_stricmp(const char *s1, const char *s2);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern int atoi(const char *s);
extern double atof(const char *s);

#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <strings.h>

extern int stricmp(const char *s1, const char *s2);

void FxRange_SetRange(const FxRange * _this, float min, float max);
void PrimitiveTemplate_Shutdown(const PrimitiveTemplate * _this);
float FxRange_GetValPct(const FxRange * _this, float percent);
Bool PrimitiveTemplate_ParseGroupFlags(const PrimitiveTemplate * _this, const char *val, int *groupFlags, const PrimitiveTemplate * _this_3, const char *flag, const FxFlagEntry *flagEntries, int flagEntryCount);
void FX_Print(const char *msg, ...);
MaterialHandle FX_RegisterMaterial(const char *material);
struct XModel * FX_ModelRegister(const char *name);
float FxRange_GetVal(const FxRange * _this);
void PrimitiveTemplate_Init(const PrimitiveTemplate * _this);
void PrimitiveTemplate_ParseChannelCurve(const PrimitiveTemplate * _this, GPValue *pairs, FxChannelId channel);
Bool PrimitiveTemplate_ParseImpactFxStrings(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParseDeathFxStrings(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParseEmitterFxStrings(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParsePlayFxStrings(const PrimitiveTemplate * _this, GPValue *grp);
void PrimitiveTemplate_ParseChannelRgbCurve(const PrimitiveTemplate * _this, GPValue *pairs, FxChannelId channel);
void PrimitiveTemplate_CreateBackCompatibleRotationDeltaCurve(const PrimitiveTemplate * _this, float initialValue, float keyScale, float lifetime, int channelId, float graphScale);
Bool PrimitiveTemplate_ParseMaterials(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParseFlags(const PrimitiveTemplate * _this, const char *line, const FxFlagEntry *flagEntries, int flagEntryCount);
Bool PrimitiveTemplate_ParseModels(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParseRotationDelta(const PrimitiveTemplate * _this, const char *val);
Bool PrimitiveTemplate_ParseChannel(const PrimitiveTemplate * _this, BackCompatibleParameters *backCompatibleParameters, GPGroup *grp, FxChannelId channelId, const PrimitiveTemplate * _this_4, const char *val, const PrimitiveTemplate * _this_6, const char *val_7, const PrimitiveTemplate * _this_8, const char *val_9, const PrimitiveTemplate * _this_10, const char *val_11);
Bool PrimitiveTemplate_ParseVelocity(const PrimitiveTemplate * _this, const char *val);
Bool PrimitiveTemplate_ParseAcceleration(const PrimitiveTemplate * _this, const char *val);
Bool PrimitiveTemplate_ParsePrimitiveInternal(const PrimitiveTemplate * _this, BackCompatibleParameters *backCompatibleParameters, GPGroup *grp);
Bool PrimitiveTemplate_ParsePrimitive(const PrimitiveTemplate * _this, GPGroup *grp);

/* ==================== Helper macros for GPValue field access ==================== */
/* GPValue: offset 0x00 = value string, offset 0x04 = next, offset 0x10 = list */
#define GPV_STRING(v) (*(const char **)((byte *)(v)))
#define GPV_NEXT(v)   (*(GPValue **)((byte *)(v) + 4))
#define GPV_LIST(v)   (*(GPValue **)((byte *)(v) + 0x10))

/* GPGroup: offset 0x10 = pairs, offset 0x1c = subgroups */
#define GPG_PAIRS(g)     (*(GPValue **)((byte *)(g) + 0x10))
#define GPG_SUBGROUPS(g) (*(GPValue **)((byte *)(g) + 0x1c))

/* ==================== Helper: parse "%f %f" with fallback ==================== */
/* Returns 0 on sscanf==0 (error), otherwise sets min/max (if 1 arg, max=min) */
static int ParseFloatRange(const char *val, float *outMin, float *outMax)
{
    float a, b;
    int n = sscanf(val, "%f %f", &a, &b);
    if (n == 0)
        return 0;
    if (n == 1)
        b = a;
    *outMin = a;
    *outMax = b;
    return 1;
}

/* Helper: parse "%f %f %f  %f %f %f" — returns count or 0 on error */
static int ParseVec3Range(const char *val, float *minV, float *maxV)
{
    int n = sscanf(val, "%f %f %f   %f %f %f",
                   &minV[0], &minV[1], &minV[2],
                   &maxV[0], &maxV[1], &maxV[2]);
    if (n <= 2 || n == 4 || n == 5)
        return 0;
    if (n == 3) {
        maxV[0] = minV[0];
        maxV[1] = minV[1];
        maxV[2] = minV[2];
    }
    return n;
}

/* Helper: ensure min <= max (swap if needed) */
static void EnsureMinMax(float *a, float *b)
{
    if (*a > *b) {
        float t = *a;
        *a = *b;
        *b = t;
    }
}

/* Helper: abs-ceil for velocity/accel max computation:
   int(val), take abs, convert back to float, then max with other */
static float AbsCeil(float val)
{
    int iv = (int)val;
    if (iv <= -1) {
        iv = -iv;
    }
    return (float)iv;
}

/* Helper: create a 2-key velocity/accel curve
   keys[0] = 0.0, keys[1] = initialValue/maxRange (or 0), keys[2] = 1.0, keys[3] = val */
static void CreateTwoKeyCurve(byte *_this, int channelOffset, float initialValue, float maxRange)
{
    float keys[4];
    keys[0] = 0.0f;
    if (maxRange != 0.0f) {
        keys[1] = initialValue / maxRange;
    } else {
        keys[1] = 0.0f;
    }
    keys[2] = 1.0f;
    keys[3] = keys[1];

    const FxCurve *curve = FxCurve_AllocAndCreateWithKeys(keys, 1, 2);
    *(const FxCurve **)(_this + channelOffset) = curve;
    *(float *)(_this + channelOffset + 4) = maxRange;
    *(float *)(_this + channelOffset + 8) = maxRange;
}

/* Helper: create a 2-key accel curve with scale
   keys[0] = 0.0, keys[1] = 0.0, keys[2] = 1.0, keys[3] = initialValue * maxScale * 0.001 / maxRange (or 0) */
static void CreateAccelCurve(byte *_this, int channelOffset, float initialValue, float maxScale, float maxRange)
{
    float keys[4];
    keys[0] = 0.0f;
    keys[1] = 0.0f;
    keys[2] = 1.0f;
    float endVal = initialValue * maxScale * 0.001f;
    if (maxRange != 0.0f) {
        keys[3] = endVal / maxRange;
    } else {
        keys[3] = 0.0f;
    }

    const FxCurve *curve = FxCurve_AllocAndCreateWithKeys(keys, 1, 2);
    *(const FxCurve **)(_this + channelOffset) = curve;
    *(float *)(_this + channelOffset + 4) = maxRange;
    *(float *)(_this + channelOffset + 8) = maxRange;
}

/* Helper: create a 2-key accel curve with 1.0 scale range */
static void CreateAccelCurveUnit(byte *_this, int channelOffset, float initialValue, float maxScale, float maxRange)
{
    float keys[4];
    keys[0] = 0.0f;
    keys[1] = 0.0f;
    keys[2] = 1.0f;
    float endVal = initialValue * maxScale * 0.001f;
    if (maxRange != 0.0f) {
        keys[3] = endVal / maxRange;
    } else {
        keys[3] = 0.0f;
    }

    const FxCurve *curve = FxCurve_AllocAndCreateWithKeys(keys, 1, 2);
    *(const FxCurve **)(_this + channelOffset) = curve;
    *(float *)(_this + channelOffset + 4) = 1.0f;
    *(float *)(_this + channelOffset + 8) = 1.0f;
}

/* ==================== Non-naked functions (unchanged) ==================== */

/* line 2199 */
void FxRange_SetRange(const FxRange * _this, float min, float max)
{
    *(float *)_this = min;
    *(float *)((byte *)_this + 4) = max;
}

/* line 151 */
void PrimitiveTemplate_Shutdown(const PrimitiveTemplate * _this)
{
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x68));
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x70));
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x78));
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x80));
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x88));
}

/* line 2213 */
float FxRange_GetValPct(const FxRange * _this, float percent)
{
    float base = *(float *)((byte *)_this);
    float range = *(float *)((byte *)_this + 4) - base;
    return base + range * percent;
}

/* line 351 — NOTE: This function's ASM is incomplete/truncated in the original dump.
   Keeping as naked to preserve existing behavior. */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
Bool PrimitiveTemplate_ParseGroupFlags(const PrimitiveTemplate * _this, const char *val, int *groupFlags, const PrimitiveTemplate * _this_3, const char *flag, const FxFlagEntry *flagEntries, int flagEntryCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 351 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* groupFlags */
        /* { scope 1 */
        "movl $0x80, 8(%esp)\n" /* line 353 */
        "movl $__ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148, 4(%esp)\n"
        "leal -0x98(%ebp), %eax\n" /* flag */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leal -0x38(%ebp), %eax\n" /* line 359 */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x58(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x78(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x98(%ebp), %eax\n" /* flag */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021a198, 4(%esp)\n" /* "%s %s %s %s" */
        "movl 0xc(%ebp), %eax\n" /* val */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        "movl %eax, -0x9c(%ebp)\n" /* v */
    );
}

/* line 2127 */
void FX_Print(const char *msg, ...)
{
    char text[1024];
    va_list argptr;

    va_start(argptr, msg);
    vsnprintf(text, 0x400, msg, argptr);
    va_end(argptr);

    Com_Printf("%s", text);
}

/* line 2151 */
MaterialHandle FX_RegisterMaterial(const char *material)
{
    return Material_RegisterHandle(material, 3, 6);
}

/* line 2161 */
struct XModel * FX_ModelRegister(const char *name)
{
    if (!Com_ValidXModelName(name)) {
        return NULL;
    }

    return FX_XModelPrecache(name + 7);
}

/* line 2205 */
float FxRange_GetVal(const FxRange * _this)
{
    float base = *(float *)((byte *)_this);
    float amplitude = *(float *)((byte *)_this + 4);

    if (base == amplitude) {
        return base;
    }

    return flrand(base, amplitude);
}

/* ==================== Converted naked functions ==================== */

/* line 94 */
void PrimitiveTemplate_Init(const PrimitiveTemplate * _this)
{
    byte *t = (byte *)_this;

    /* Set scale ranges to 1.0 */
    *(float *)(t + 0x58) = 1.0f;  /* mLife.mMin */
    *(float *)(t + 0x5c) = 1.0f;  /* mLife.mMax */
    *(float *)(t + 0x50) = 1.0f;  /* mSpawnCount.mMin */
    *(float *)(t + 0x54) = 1.0f;  /* mSpawnCount.mMax */
    *(float *)(t + 0xe8) = 1.0f;  /* mRadius.mMin */
    *(float *)(t + 0xec) = 1.0f;  /* mRadius.mMax */
    *(float *)(t + 0xf0) = 1.0f;  /* mHeight.mMin */
    *(float *)(t + 0xf4) = 1.0f;  /* mHeight.mMax */

    /* Create default channels */
    FxChannel_CreateDefault((FxChannel *)(t + 0x100), 3, 1.0f, 0.0f);  /* line 105: color */
    FxChannel_CreateDefault((FxChannel *)(t + 0x10c), 3, 1.0f, 0.0f);  /* line 106: colorRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x118), 1, 1.0f, 0.0f);  /* line 107: alpha */
    FxChannel_CreateDefault((FxChannel *)(t + 0x124), 1, 1.0f, 0.0f);  /* line 108: alphaRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x130), 1, 1.0f, 0.0f);  /* line 109: size */
    FxChannel_CreateDefault((FxChannel *)(t + 0x13c), 1, 1.0f, 0.0f);  /* line 110: sizeRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x148), 1, 1.0f, 0.0f);  /* line 111: size2 */
    FxChannel_CreateDefault((FxChannel *)(t + 0x154), 1, 1.0f, 0.0f);  /* line 112: size2Rand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x160), 1, 1.0f, 0.0f);  /* line 113: length */
    FxChannel_CreateDefault((FxChannel *)(t + 0x16c), 1, 1.0f, 0.0f);  /* line 114: lengthRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x178), 1, 0.0f, 0.0f);  /* line 115: rotationDelta */
    FxChannel_CreateDefault((FxChannel *)(t + 0x184), 1, 0.0f, 0.0f);  /* line 116: rotationDeltaRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x190), 1, 0.0f, 0.0f);  /* line 118: velocityX */
    FxChannel_CreateDefault((FxChannel *)(t + 0x19c), 1, 0.0f, 0.0f);  /* line 119: velocityY */
    FxChannel_CreateDefault((FxChannel *)(t + 0x1a8), 1, 0.0f, 0.0f);  /* line 120: velocityZ */
    FxChannel_CreateDefault((FxChannel *)(t + 0x1b4), 1, 0.0f, 0.0f);  /* line 121: velocityXRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x1c0), 1, 0.0f, 0.0f);  /* line 122: velocityYRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x1cc), 1, 0.0f, 0.0f);  /* line 123: velocityZRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x1d8), 1, 0.0f, 0.0f);  /* line 125: velocity2X */
    FxChannel_CreateDefault((FxChannel *)(t + 0x1e4), 1, 0.0f, 0.0f);  /* line 126: velocity2Y */
    FxChannel_CreateDefault((FxChannel *)(t + 0x1f0), 1, 0.0f, 0.0f);  /* line 127: velocity2Z */
    FxChannel_CreateDefault((FxChannel *)(t + 0x1fc), 1, 0.0f, 0.0f);  /* line 128: velocity2XRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x208), 1, 0.0f, 0.0f);  /* line 129: velocity2YRand */
    FxChannel_CreateDefault((FxChannel *)(t + 0x214), 1, 0.0f, 0.0f);  /* line 130: velocity2ZRand */

    /* Set remaining ranges */
    *(float *)(t + 0x270) = 1.0f;
    *(float *)(t + 0x274) = 1.0f;
    *(float *)(t + 0x278) = 1.0f;
    *(float *)(t + 0x27c) = 1.0f;
    *(float *)(t + 0x268) = 1.0f;
    *(float *)(t + 0x26c) = 1.0f;
    *(float *)(t + 0x260) = 10.0f;  /* 0x41200000 */
    *(float *)(t + 0x264) = 10.0f;

    /* line 138-148 */
    *(int *)(t + 0x288) = 0;    /* mSequenceStartFrameMode */
    *(int *)(t + 0x28c) = 1;    /* mSequenceFixedFrameValue */
    *(int *)(t + 0x290) = 0;    /* mSequencePlayRateMode */
    *(float *)(t + 0x294) = 1.0f; /* mSequenceFixedFpsValue */
    *(int *)(t + 0x298) = 0;    /* mSequenceLoopMode */
    *(int *)(t + 0x29c) = 1;    /* mSequenceLoopTimes */
    *(float *)(t + 0x2a0) = 0.0f; /* spawnFrustumCullRadius */
}

#if 0 /* Original ASM for PrimitiveTemplate_Init preserved for reference */
__attribute__((naked))
void PrimitiveTemplate_Init(const PrimitiveTemplate * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        /* ... original ASM ... */
        "retl\n"
    );
}
#endif

/* line 1590 */
void PrimitiveTemplate_ParseChannelCurve(const PrimitiveTemplate * _this, GPValue *pairs, FxChannelId channel)
{
    byte *thisPtr = (byte *)_this;
    GPValue *list;
    int keyCount;
    float *keys;

    /* Get list from pairs (offset 0x10) */
    list = GPV_LIST(pairs);

    /* Count entries */
    keyCount = 0;
    if (list) {
        GPValue *p = list;
        while (p) {
            keyCount++;
            p = GPV_NEXT(p);
        }
    }

    /* Allocate temp memory: 2 floats per key (time + value) */
    keys = (float *)Hunk_AllocateTempMemoryInternal(keyCount * 8);

    /* Parse keys */
    if (list) {
        int i = 0;
        GPValue *p = list;
        while (p) {
            sscanf(GPV_STRING(p), "%f %f", &keys[i * 2], &keys[i * 2 + 1]);
            i++;
            p = GPV_NEXT(p);
        }
        keyCount = i;
    } else {
        keyCount = 0;
    }

    /* Create curve and store */
    int channelOffset = channel * 3;
    *(const FxCurve **)(thisPtr + 0x100 + channelOffset * 4) =
        FxCurve_AllocAndCreateWithKeys(keys, 1, keyCount);

    /* Free temp memory (tail call) */
    Hunk_FreeTempMemory(keys);
}

#if 0 /* Original ASM for PrimitiveTemplate_ParseChannelCurve */
#endif

/* line 1310 — Helper for ParseFxStrings pattern (impact/death/emitter/play) */
static Bool ParseFxStringsHelper(byte *_this, GPValue *grp, int handleOffset, int flagBits,
                                  const char *errNotFound, const char *errEmptyList)
{
    if (GPValue_IsList(grp)) {
        GPValue *list = GPV_LIST(grp);
        while (list) {
            EffectTemplate *fx = FX_RegisterEffect(GPV_STRING(list));
            if (!fx) {
                FX_Print(errNotFound);
                return 0;
            }
            MediaHandles_AddEffect((MediaHandles *)(_this + handleOffset), fx);
            list = GPV_NEXT(list);
        }
        if (flagBits)
            *(int *)(_this + 0x90) |= flagBits;
        return 1;
    } else {
        const char *val = GPValue_GetTopValue(grp);
        if (!val) {
            FX_Print(errEmptyList);
            return 0;
        }
        EffectTemplate *fx = FX_RegisterEffect(val);
        if (!fx) {
            FX_Print(errNotFound);
            return 0;
        }
        MediaHandles_AddEffect((MediaHandles *)(_this + handleOffset), fx);
        if (flagBits)
            *(int *)(_this + 0x90) |= flagBits;
        return 1;
    }
}

/* line 1310 */
Bool PrimitiveTemplate_ParseImpactFxStrings(const PrimitiveTemplate * _this, GPValue *grp)
{
    return ParseFxStringsHelper((byte *)_this, grp, 0x70, 0x820,
        "FxTemplate: Impact effect file not found.\n",
        "PrimitiveTemplate::ParseImpactFxStrings called with an empty list!\n");
}

/* line 1372 */
Bool PrimitiveTemplate_ParseDeathFxStrings(const PrimitiveTemplate * _this, GPValue *grp)
{
    return ParseFxStringsHelper((byte *)_this, grp, 0x78, 0x200,
        "FxTemplate: Death effect file not found.\n",
        "PrimitiveTemplate::ParseDeathFxStrings called with an empty list!\n");
}

/* line 1434 */
Bool PrimitiveTemplate_ParseEmitterFxStrings(const PrimitiveTemplate * _this, GPValue *grp)
{
    return ParseFxStringsHelper((byte *)_this, grp, 0x80, 0x100,
        "FxTemplate: Emitter effect file not found.\n",
        "PrimitiveTemplate::ParseEmitterFxStrings called with an empty list!\n");
}

/* line 1496 */
Bool PrimitiveTemplate_ParsePlayFxStrings(const PrimitiveTemplate * _this, GPValue *grp)
{
    return ParseFxStringsHelper((byte *)_this, grp, 0x88, 0,
        "FxTemplate: Effect file not found.\n",
        "PrimitiveTemplate::ParsePlayFxStrings called with an empty list!\n");
}

/* line 1556 */
void PrimitiveTemplate_ParseChannelRgbCurve(const PrimitiveTemplate * _this, GPValue *pairs, FxChannelId channel)
{
    byte *thisPtr = (byte *)_this;
    GPValue *list;
    int keyCount;
    float *keys;

    /* Get list from pairs (offset 0x10) */
    list = GPV_LIST(pairs);

    /* Count entries */
    keyCount = 0;
    if (list) {
        GPValue *p = list;
        while (p) {
            keyCount++;
            p = GPV_NEXT(p);
        }
    }

    /* Allocate temp memory: 4 floats per key (time + r + g + b) = 16 bytes */
    keys = (float *)Hunk_AllocateTempMemoryInternal(keyCount * 16);

    /* Parse keys */
    if (list) {
        int i = 0;
        GPValue *p = list;
        while (p) {
            sscanf(GPV_STRING(p), "%f %f %f %f",
                   &keys[i * 4], &keys[i * 4 + 1], &keys[i * 4 + 2], &keys[i * 4 + 3]);
            i++;
            p = GPV_NEXT(p);
        }
        keyCount = i;
    } else {
        keyCount = 0;
    }

    /* Create curve and store */
    int channelOffset = channel * 3;
    *(const FxCurve **)(thisPtr + 0x100 + channelOffset * 4) =
        FxCurve_AllocAndCreateWithKeys(keys, 3, keyCount);

    /* Free temp memory (tail call) */
    Hunk_FreeTempMemory(keys);
}

#if 0 /* Original ASM for PrimitiveTemplate_ParseChannelRgbCurve */
#endif

/* line 626 */
void PrimitiveTemplate_CreateBackCompatibleRotationDeltaCurve(const PrimitiveTemplate * _this, float initialValue, float keyScale, float lifetime, int channelId, float graphScale)
{
    byte *thisPtr = (byte *)_this;
    float keys[40]; /* 20 keys * 2 floats (time + value) */
    int i;

    /* Compute time step factor */
    float timeStep = lifetime / 20.0f * 0.00065f;
    float oneF = 1.0f;
    float endT = timeStep - oneF;
    float negT = -timeStep;

    for (i = 0; i < 20; i++) {
        keys[i * 2] = (float)i / 19.0f;

        if (i == 0) {
            if (keyScale == 0.0f) {
                /* keyScale is exactly zero */
                keys[1] = initialValue;
            } else {
                keys[1] = initialValue / keyScale;
            }
        } else {
            /* For subsequent keys, compute based on ranges:
               The compiler unrolled this into many paths based on whether
               negT < 0, endT < 0, and keyScale == 0. But the core logic is:
               - if negT < 0 and endT < 0: value = previous_time * (1-timeStep) / -timeStep = prev * negFactor
               - Various combinations control whether we copy prev value or multiply
               The simplest correct interpretation: */
            if (keyScale == 0.0f) {
                /* zero scale: just copy previous key value */
                keys[i * 2 + 1] = keys[(i - 1) * 2 + 1];
            } else if (negT < 0.0f && endT < 0.0f) {
                /* Both negative: multiply previous by (1 - timeStep) */
                float factor = oneF - timeStep;
                keys[i * 2 + 1] = keys[(i - 1) * 2 + 1] * factor;
            } else if (negT < 0.0f) {
                /* negT < 0, endT >= 0: multiply by negative timeStep */
                keys[i * 2 + 1] = keys[(i - 1) * 2 + 1] * negT;
            } else if (endT < 0.0f) {
                /* negT >= 0, endT < 0: copy previous */
                keys[i * 2 + 1] = keys[(i - 1) * 2 + 1];
            } else {
                /* Both non-negative: copy previous */
                keys[i * 2 + 1] = keys[(i - 1) * 2 + 1];
            }
        }
    }

    /* Store curve */
    int chanOff = channelId * 3 * 4;
    *(const FxCurve **)(thisPtr + 0x100 + chanOff) =
        FxCurve_AllocAndCreateWithKeys(keys, 1, 20);

    /* Store graph scale as the range */
    *(unsigned int *)(thisPtr + 0x100 + chanOff + 4) = *(unsigned int *)&graphScale;
    *(unsigned int *)(thisPtr + 0x100 + chanOff + 8) = *(unsigned int *)&graphScale;
}

#if 0 /* Original ASM for PrimitiveTemplate_CreateBackCompatibleRotationDeltaCurve */
#endif

/* line 1206 */
Bool PrimitiveTemplate_ParseMaterials(const PrimitiveTemplate * _this, GPValue *grp)
{
    byte *thisPtr = (byte *)_this;

    if (!g_rendererExists)
        return 1;

    if (GPValue_IsList(grp)) {
        GPValue *list = GPV_LIST(grp);
        while (list) {
            MaterialHandle h = Material_RegisterHandle(GPV_STRING(list), 3, 6);
            TMediaElement elem;
            elem.material = (struct Material *)(uintptr_t)h;
            MediaHandles_AddHandle((MediaHandles *)(thisPtr + 0x68), elem);
            list = GPV_NEXT(list);
        }
        return 1;
    } else {
        const char *val = GPValue_GetTopValue(grp);
        if (!val) {
            FX_Print("PrimitiveTemplate::ParseMaterials called with an empty list!\n");
            return 0;
        }
        MaterialHandle h = Material_RegisterHandle(val, 3, 6);
        TMediaElement elem;
        elem.material = (struct Material *)(uintptr_t)h;
        MediaHandles_AddHandle((MediaHandles *)(thisPtr + 0x68), elem);
        return 1;
    }
}

#if 0 /* Original ASM for PrimitiveTemplate_ParseMaterials */
#endif

/* line 852 */
Bool PrimitiveTemplate_ParseFlags(const PrimitiveTemplate * _this, const char *line, const FxFlagEntry *flagEntries, int flagEntryCount)
{
    byte *thisPtr = (byte *)_this;
    int lineLen;
    char *flag;
    int parsedLength;
    int flagLength;
    int entryIndex;

    /* strlen of line */
    lineLen = strlen(line);
    if (lineLen == 0)
        return 0;

    /* Allocate temp buffer for flag tokens */
    flag = (char *)Hunk_AllocateTempMemoryInternal(lineLen);

    parsedLength = 0;
    while (parsedLength < lineLen) {
        if (sscanf(line + parsedLength, "%s", flag) != 1) {
            Hunk_FreeTempMemory(flag);
            return 0;
        }

        flagLength = strlen(flag);

        /* Search flag entries */
        int found = 0;
        for (entryIndex = 0; entryIndex < flagEntryCount; entryIndex++) {
            if (stricmp(flagEntries[entryIndex].flag, flag) == 0) {
                *(unsigned int *)(thisPtr + 0x90) |= flagEntries[entryIndex].masks[0];
                *(unsigned int *)(thisPtr + 0x94) |= flagEntries[entryIndex].masks[1];
                found = 1;
                break;
            }
        }

        if (!found) {
            Hunk_FreeTempMemory(flag);
            return 0;
        }

        parsedLength += flagLength + 1;
    }

    Hunk_FreeTempMemory(flag);
    return 1;
}

#if 0 /* Original ASM for PrimitiveTemplate_ParseFlags */
#endif

/* line 1257 */
Bool PrimitiveTemplate_ParseModels(const PrimitiveTemplate * _this, GPValue *grp)
{
    byte *thisPtr = (byte *)_this;

    if (GPValue_IsList(grp)) {
        GPValue *list = GPV_LIST(grp);
        while (list) {
            const char *val = GPV_STRING(list);
            if (!Com_ValidXModelName(val)) {
                FX_Print("PrimitiveTemplate::ParseModels, could not register model '%s'\n", val);
                return 0;
            }
            struct XModel *model = FX_XModelPrecache(val + 7);
            if (!model) {
                FX_Print("PrimitiveTemplate::ParseModels, could not register model '%s'\n", val);
                return 0;
            }
            TMediaElement elem;
            elem.model = model;
            MediaHandles_AddHandle((MediaHandles *)(thisPtr + 0x68), elem);
            list = GPV_NEXT(list);
        }
        return 1;
    } else {
        const char *val = GPValue_GetTopValue(grp);
        if (!val) {
            FX_Print("PrimitiveTemplate::ParseModels called with an empty list!\n");
            return 0;
        }
        if (!Com_ValidXModelName(val)) {
            FX_Print("PrimitiveTemplate::ParseModels, could not register model '%s'\n", val);
            return 0;
        }
        struct XModel *model = FX_XModelPrecache(val + 7);
        if (!model) {
            FX_Print("PrimitiveTemplate::ParseModels, could not register model '%s'\n", val);
            return 0;
        }
        TMediaElement elem;
        elem.model = model;
        MediaHandles_AddHandle((MediaHandles *)(thisPtr + 0x68), elem);
        return 1;
    }
}

#if 0 /* Original ASM for PrimitiveTemplate_ParseModels */
#endif

/* line 718 */
Bool PrimitiveTemplate_ParseRotationDelta(const PrimitiveTemplate * _this, const char *val)
{
    byte *thisPtr = (byte *)_this;
    float minVal, maxVal;

    int n = sscanf(val, "%f %f", &minVal, &maxVal);
    if (n == 0)
        return 0; /* sscanf failed, fall through to caller who checks return */
    if (n == 1)
        maxVal = minVal;

    /* Ensure min <= max */
    EnsureMinMax(&minVal, &maxVal);

    /* Compute key scale: abs(ceil(min)), max with max, doubled */
    float absMin = AbsCeil(minVal);
    float keyScaleVal = absMin;
    if (keyScaleVal < maxVal)
        keyScaleVal = maxVal;
    keyScaleVal = keyScaleVal + keyScaleVal; /* doubled */

    /* Create rotation delta curve (channel 10 = FXCHAN_ROTATION_DELTA) */
    float lifetime = *(float *)(thisPtr + 0x58); /* mLife.mMin */
    PrimitiveTemplate_CreateBackCompatibleRotationDeltaCurve(_this, minVal, keyScaleVal, lifetime, 0xa, keyScaleVal);

    /* If min != max, also create ROTATION_DELTA_RAND curve (channel 11) */
    if (minVal != maxVal) {
        *(unsigned int *)(thisPtr + 0x90) |= 0x40000; /* useRandomRotationDelta flag */
        float lifetime2 = *(float *)(thisPtr + 0x5c); /* mLife.mMax */
        PrimitiveTemplate_CreateBackCompatibleRotationDeltaCurve(_this, maxVal, keyScaleVal, lifetime2, 0xb, 1.0f);
    }

    return 1;
}

#if 0 /* Original ASM for PrimitiveTemplate_ParseRotationDelta */
#endif

/* line 1633 */
Bool PrimitiveTemplate_ParseChannel(const PrimitiveTemplate * _this, BackCompatibleParameters *backCompatibleParameters, GPGroup *grp, FxChannelId channelId, const PrimitiveTemplate * _this_4, const char *val, const PrimitiveTemplate * _this_6, const char *val_7, const PrimitiveTemplate * _this_8, const char *val_9, const PrimitiveTemplate * _this_10, const char *val_11)
{
    byte *thisPtr = (byte *)_this;
    GPValue *pairs;
    const char *key;
    const char *valStr;
    float minVal, maxVal;

    pairs = GPV_LIST(grp);
    if (!pairs)
        return 1;

    int chanOffset = channelId * 64; /* sizeof(FxChannelBackwardCompatible) = 0x40 */
    FxChannelBackwardCompatible *backCompat = (FxChannelBackwardCompatible *)((byte *)backCompatibleParameters + chanOffset);

    while (pairs) {
        key = GPV_STRING(pairs);
        valStr = GPValue_GetTopValue(pairs);

        if (stricmp(key, "curve") == 0) {
            /* Parse curve data */
            if (channelId <= 1) {
                PrimitiveTemplate_ParseChannelRgbCurve(_this, pairs, channelId);
            } else {
                PrimitiveTemplate_ParseChannelCurve(_this, pairs, channelId);
            }
        } else if (stricmp(key, "scale") == 0) {
            /* Parse scale min/max */
            sscanf(valStr, "%f %f", &minVal, &maxVal);
            backCompat->end[0].mMin = minVal;  /* offset 0x18 */
            backCompat->end[0].mMax = maxVal;   /* offset 0x1c */
        } else if (stricmp(key, "start") == 0) {
            /* Parse start min/max */
            sscanf(valStr, "%f %f", &minVal, &maxVal);
            backCompat->start[1].mMin = minVal;  /* offset 0x08 */
            backCompat->start[1].mMax = maxVal;   /* offset 0x0c */
        } else if (stricmp(key, "parm") == 0) {
            /* skip parm */
        } else if (stricmp(key, "parms") == 0) {
            /* skip parms */
        } else if (stricmp(key, "flag") == 0 || stricmp(key, "flags") == 0) {
            /* Parse flags */
            PrimitiveTemplate_ParseFlags(_this, valStr, fxAttributeFlags, 26);
        } else {
            FX_Print("Unknown key parsing a channel: %s\n", key);
        }

        pairs = GPV_NEXT(pairs);
    }

    return 1;
}

#if 0 /* Original ASM for PrimitiveTemplate_ParseChannel */
#endif

/* line 781 */
Bool PrimitiveTemplate_ParseVelocity(const PrimitiveTemplate * _this, const char *val)
{
    byte *thisPtr = (byte *)_this;
    float minV[3], maxV[3];

    int n = ParseVec3Range(val, minV, maxV);
    if (!n)
        return 0;

    /* Ensure min <= max for each axis */
    EnsureMinMax(&minV[0], &maxV[0]);
    EnsureMinMax(&minV[1], &maxV[1]);
    EnsureMinMax(&minV[2], &maxV[2]);

    /* Compute max range per axis: abs(ceil(min)), max with max, doubled */
    float maxX = AbsCeil(minV[0]);
    if (maxX < maxV[0]) maxX = maxV[0];
    float maxY = AbsCeil(minV[1]);
    if (maxY < maxV[1]) maxY = maxV[1];
    float maxZ = AbsCeil(minV[2]);
    if (maxZ < maxV[2]) maxZ = maxV[2];
    maxX *= 2.0f;
    maxY *= 2.0f;
    maxZ *= 2.0f;

    /* Compute max of all three (for unified range): max(max(|x|, |y|), |z|) */
    float totalMax;
    /* abs comparison: pick the larger of x, y */
    if (maxX - maxY >= 0.0f)
        totalMax = maxX;
    else
        totalMax = maxY;
    /* then pick the larger of that and z */
    if (totalMax - maxZ >= 0.0f)
        ; /* totalMax stays */
    else
        totalMax = maxZ;

    /* Create velocity X curve (channel at offset 0x190) */
    CreateTwoKeyCurve(thisPtr, 0x190, minV[1], totalMax);

    /* Create velocity Y curve (channel at offset 0x19c) */
    CreateTwoKeyCurve(thisPtr, 0x19c, minV[2], totalMax);

    /* Create velocity Z curve (channel at offset 0x1a8) */
    CreateTwoKeyCurve(thisPtr, 0x1a8, minV[0], totalMax);

    /* Check if min == max (all axes) */
    int allEqual = 1;
    if (minV[0] != maxV[0] || minV[1] != maxV[1] || minV[2] != maxV[2])
        allEqual = 0;

    if (!allEqual) {
        /* Set useRandomVelocity flag */
        *(unsigned int *)(thisPtr + 0x90) |= 0x80000;

        /* Create velocity X rand curve (channel at offset 0x1b4) */
        CreateTwoKeyCurve(thisPtr, 0x1b4, maxV[0], 1.0f);

        /* Create velocity Y rand curve (channel at offset 0x1c0) */
        CreateTwoKeyCurve(thisPtr, 0x1c0, maxV[1], 1.0f);

        /* Create velocity Z rand curve (channel at offset 0x1cc) */
        CreateTwoKeyCurve(thisPtr, 0x1cc, maxV[2], 1.0f);
    }

    return 1;
}

#if 0 /* Original ASM for PrimitiveTemplate_ParseVelocity */
#endif

/* line 913 */
Bool PrimitiveTemplate_ParseAcceleration(const PrimitiveTemplate * _this, const char *val)
{
    byte *thisPtr = (byte *)_this;
    float minV[3], maxV[3];

    int n = ParseVec3Range(val, minV, maxV);
    if (!n)
        return 0;

    /* Ensure min <= max for each axis */
    EnsureMinMax(&minV[0], &maxV[0]);
    EnsureMinMax(&minV[1], &maxV[1]);
    EnsureMinMax(&minV[2], &maxV[2]);

    float maxScale = *(float *)(thisPtr + 0x5c); /* mLife.mMax */

    /* Compute max range per axis */
    float maxX = AbsCeil(minV[0]);
    if (maxX < maxV[0]) maxX = maxV[0];
    float maxY = AbsCeil(minV[1]);
    if (maxY < maxV[1]) maxY = maxV[1];
    float maxZ = AbsCeil(minV[2]);
    if (maxZ < maxV[2]) maxZ = maxV[2];
    maxX *= 2.0f;
    maxY *= 2.0f;
    maxZ *= 2.0f;

    /* Compute max of all three */
    float totalMax;
    if (maxX - maxY >= 0.0f)
        totalMax = maxX;
    else
        totalMax = maxY;
    if (totalMax - maxZ >= 0.0f)
        ; /* stays */
    else
        totalMax = maxZ;

    /* Scale by maxScale * 0.001 */
    float rangeScale = totalMax * maxScale * 0.001f;

    /* Create accel X curve (channel at offset 0x1d8) */
    CreateAccelCurve(thisPtr, 0x1d8, minV[0], maxScale, rangeScale);

    /* Create accel Y curve (channel at offset 0x1e4) */
    CreateAccelCurve(thisPtr, 0x1e4, minV[1], maxScale, rangeScale);

    /* Create accel Z curve (channel at offset 0x1f0) */
    CreateAccelCurve(thisPtr, 0x1f0, minV[2], maxScale, rangeScale);

    /* Check if min == max (all axes) */
    int allEqual = 1;
    if (minV[0] != maxV[0] || minV[1] != maxV[1] || minV[2] != maxV[2])
        allEqual = 0;

    if (!allEqual) {
        /* Set flag */
        *(unsigned int *)(thisPtr + 0x90) |= 0x100000;

        /* Create accel X rand (channel at offset 0x1fc) */
        CreateAccelCurveUnit(thisPtr, 0x1fc, maxV[0], maxScale, rangeScale);

        /* Create accel Y rand (channel at offset 0x208) */
        CreateAccelCurveUnit(thisPtr, 0x208, maxV[1], maxScale, rangeScale);

        /* Create accel Z rand (channel at offset 0x214) */
        CreateAccelCurveUnit(thisPtr, 0x214, maxV[2], maxScale, rangeScale);
    }

    return 1;
}

#if 0 /* Original ASM for PrimitiveTemplate_ParseAcceleration */
#endif

/* line 1701 */
Bool PrimitiveTemplate_ParsePrimitiveInternal(const PrimitiveTemplate * _this, BackCompatibleParameters *backCompatibleParameters, GPGroup *grp)
{
    byte *thisPtr = (byte *)_this;
    GPValue *pairs;
    const char *key;
    const char *val;
    float minVal, maxVal;
    float minV[3], maxV[3];
    int n;

    /* Get pairs from grp */
    pairs = GPV_LIST(grp);

    /* Initialize backCompatibleParameters */
    memset(backCompatibleParameters, 0, 0x600);
    {
        int channelId;
        byte *bcp = (byte *)backCompatibleParameters;
        for (channelId = 0; channelId < 24; channelId++) {
            byte *chan = bcp + channelId * 0x40;
            int d;
            for (d = 0; d < 3; d++) {
                /* start[d] range = (1.0, 1.0) — offset 0x00 + d*8 */
                *(float *)(chan + d * 8 + 0x00) = 1.0f;
                *(float *)(chan + d * 8 + 0x04) = 1.0f;
                /* end[d] range = (1.0, 1.0) — offset 0x18 + d*8 */
                *(float *)(chan + 0x18 + d * 8 + 0x00) = 1.0f;
                *(float *)(chan + 0x18 + d * 8 + 0x04) = 1.0f;
                /* parm range offset 0x30 — handled in d==0 only */
                *(float *)(chan + 0x30) = 1.0f;
                *(float *)(chan + 0x34) = 1.0f;
            }
        }
    }

    /* Parse key-value pairs */
    while (pairs) {
        key = GPV_STRING(pairs);
        val = GPValue_GetTopValue(pairs);

        /* "count" */
        if (stricmp(key, "count") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            *(float *)(thisPtr + 0x50) = minVal;
            *(float *)(thisPtr + 0x54) = maxVal;
        }
        /* "shaders" or "shader" */
        else if (stricmp(key, "shaders") == 0 || stricmp(key, "shader") == 0) {
            if (!PrimitiveTemplate_ParseMaterials(_this, pairs))
                goto error_key;
        }
        /* "models" or "model" */
        else if (stricmp(key, "models") == 0 || stricmp(key, "model") == 0) {
            if (!PrimitiveTemplate_ParseModels(_this, pairs))
                goto error_key;
        }
        /* "impactfx" */
        else if (stricmp(key, "impactfx") == 0) {
            if (!PrimitiveTemplate_ParseImpactFxStrings(_this, pairs))
                goto error_key;
        }
        /* "deathfx" */
        else if (stricmp(key, "deathfx") == 0) {
            if (!PrimitiveTemplate_ParseDeathFxStrings(_this, pairs))
                goto error_key;
        }
        /* "emitfx" */
        else if (stricmp(key, "emitfx") == 0) {
            if (!PrimitiveTemplate_ParseEmitterFxStrings(_this, pairs))
                goto error_key;
        }
        /* "playfx" */
        else if (stricmp(key, "playfx") == 0) {
            if (!PrimitiveTemplate_ParsePlayFxStrings(_this, pairs))
                goto error_key;
        }
        /* "life" */
        else if (stricmp(key, "life") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            /* Note: reversed storage order from normal — mMin=max, mMax=min */
            *(float *)(thisPtr + 0x58) = maxVal;
            *(float *)(thisPtr + 0x5c) = minVal;
        }
        /* "cullrange" */
        else if (stricmp(key, "cullrange") == 0) {
            *(float *)(thisPtr + 0x64) = (float)atof(val);
        }
        /* "spawnRange" */
        else if (stricmp(key, "spawnRange") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            if (minVal > maxVal)
                goto error_key;
            *(float *)(thisPtr + 0x60) = minVal;
            *(float *)(thisPtr + 0x64) = maxVal;
        }
        /* "delay" */
        else if (stricmp(key, "delay") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            /* reversed storage */
            *(float *)(thisPtr + 0x48) = maxVal;
            *(float *)(thisPtr + 0x4c) = minVal;
        }
        /* "bounce" / "intensity" */
        else if (stricmp(key, "bounce") == 0 || stricmp(key, "intensity") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            if (minVal > maxVal)
                goto error_key;
            if (minVal < 0.0f)
                goto error_key;
            if (minVal > 1.0f)
                goto error_key;
            if (0.0f > maxVal)
                goto error_key;
            if (maxVal > 1.0f)
                goto error_key;
            *(float *)(thisPtr + 0x280) = minVal;
            *(float *)(thisPtr + 0x284) = maxVal;
            *(unsigned int *)(thisPtr + 0x90) |= 0x20;
        }
        /* "min" — bounding box min */
        else if (stricmp(key, "min") == 0) {
            n = sscanf(val, "%f %f %f   %f %f %f",
                       &minV[0], &minV[1], &minV[2],
                       &maxV[0], &maxV[1], &maxV[2]);
            if (n <= 2 || n == 4 || n == 5)
                goto error_key;
            *(float *)(thisPtr + 0xa0) = minV[0];
            *(float *)(thisPtr + 0xa4) = minV[1];
            *(float *)(thisPtr + 0xa8) = minV[2];
            *(unsigned int *)(thisPtr + 0x90) |= 0x60;
        }
        /* "max" — bounding box max */
        else if (stricmp(key, "max") == 0) {
            n = sscanf(val, "%f %f %f   %f %f %f",
                       &maxV[0], &maxV[1], &maxV[2],
                       &minV[0], &minV[1], &minV[2]);
            if (n <= 2 || n == 4 || n == 5)
                goto error_key;
            *(float *)(thisPtr + 0xac) = maxV[0];
            *(float *)(thisPtr + 0xb0) = maxV[1];
            *(float *)(thisPtr + 0xb4) = maxV[2];
            *(unsigned int *)(thisPtr + 0x90) |= 0x60;
        }
        /* "angle" / "angles" */
        else if (stricmp(key, "angle") == 0 || stricmp(key, "angles") == 0) {
            n = ParseVec3Range(val, minV, maxV);
            if (!n)
                goto error_key;
            /* Store angle ranges */
            *(float *)(thisPtr + 0x228) = maxV[0];
            *(float *)(thisPtr + 0x22c) = minV[0];
            *(float *)(thisPtr + 0x230) = maxV[1];
            *(float *)(thisPtr + 0x234) = minV[1];
            *(float *)(thisPtr + 0x238) = maxV[2];
            *(float *)(thisPtr + 0x23c) = minV[2];
        }
        /* "angleDelta" */
        else if (stricmp(key, "angleDelta") == 0) {
            n = ParseVec3Range(val, minV, maxV);
            if (!n)
                goto error_key;
            *(float *)(thisPtr + 0x240) = minV[0];
            *(float *)(thisPtr + 0x244) = maxV[0];
            *(float *)(thisPtr + 0x248) = minV[1];
            *(float *)(thisPtr + 0x24c) = maxV[1];
            *(float *)(thisPtr + 0x250) = minV[2];
            *(float *)(thisPtr + 0x254) = maxV[2];
        }
        /* "velocity" / "vel" */
        else if (stricmp(key, "velocity") == 0 || stricmp(key, "vel") == 0) {
            if (!PrimitiveTemplate_ParseVelocity(_this, val))
                goto error_key;
        }
        /* "acceleration" / "accel" */
        else if (stricmp(key, "acceleration") == 0 || stricmp(key, "accel") == 0) {
            if (!PrimitiveTemplate_ParseAcceleration(_this, val))
                goto error_key;
        }
        /* "gravity" */
        else if (stricmp(key, "gravity") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            *(float *)(thisPtr + 0x258) = minVal;
            *(float *)(thisPtr + 0x25c) = maxVal;
        }
        /* "density" */
        else if (stricmp(key, "density") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            /* reversed */
            *(float *)(thisPtr + 0x260) = maxVal;
            *(float *)(thisPtr + 0x264) = minVal;
        }
        /* "variance" */
        else if (stricmp(key, "variance") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            /* reversed */
            *(float *)(thisPtr + 0x268) = maxVal;
            *(float *)(thisPtr + 0x26c) = minVal;
        }
        /* "origin" */
        else if (stricmp(key, "origin") == 0) {
            n = ParseVec3Range(val, minV, maxV);
            if (!n)
                goto error_key;
            *(float *)(thisPtr + 0xb8) = minV[0];
            *(float *)(thisPtr + 0xbc) = maxV[0];
            *(float *)(thisPtr + 0xc0) = minV[1];
            *(float *)(thisPtr + 0xc4) = maxV[1];
            *(float *)(thisPtr + 0xc8) = minV[2];
            *(float *)(thisPtr + 0xcc) = maxV[2];
        }
        /* "origin2" */
        else if (stricmp(key, "origin2") == 0) {
            n = ParseVec3Range(val, minV, maxV);
            if (!n)
                goto error_key;
            /* reversed: max first, then min */
            *(float *)(thisPtr + 0xd0) = maxV[0];
            *(float *)(thisPtr + 0xd4) = minV[0];
            *(float *)(thisPtr + 0xd8) = maxV[1];
            *(float *)(thisPtr + 0xdc) = minV[1];
            *(float *)(thisPtr + 0xe0) = maxV[2];
            *(float *)(thisPtr + 0xe4) = minV[2];
        }
        /* "radius" */
        else if (stricmp(key, "radius") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            *(float *)(thisPtr + 0xe8) = minVal;
            *(float *)(thisPtr + 0xec) = maxVal;
        }
        /* "height" */
        else if (stricmp(key, "height") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            /* reversed */
            *(float *)(thisPtr + 0xf0) = maxVal;
            *(float *)(thisPtr + 0xf4) = minVal;
        }
        /* "wind" */
        else if (stricmp(key, "wind") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            *(float *)(thisPtr + 0xf8) = minVal;
            *(float *)(thisPtr + 0xfc) = maxVal;
        }
        /* "rotation" */
        else if (stricmp(key, "rotation") == 0) {
            if (!ParseFloatRange(val, &minVal, &maxVal))
                goto error_key;
            *(float *)(thisPtr + 0x220) = minVal;
            *(float *)(thisPtr + 0x224) = maxVal;
        }
        /* "rotationDelta" — I_stricmp used here in the original */
        else if (I_stricmp(key, "rotationDelta") == 0) {
            if (!PrimitiveTemplate_ParseRotationDelta(_this, val))
                goto error_key;
        }
        /* "flags" / "flag" */
        else if (stricmp(key, "flags") == 0 || stricmp(key, "flag") == 0) {
            if (!PrimitiveTemplate_ParseFlags(_this, val, fxAttributeFlags, 26))
                goto error_key;
        }
        /* "spawnFlags" / "spawnFlag" */
        else if (stricmp(key, "spawnFlags") == 0 || stricmp(key, "spawnFlag") == 0) {
            if (!PrimitiveTemplate_ParseFlags(_this, val, fxSpawnFlags, 13))
                goto error_key;
        }
        /* "nonUniformScale" */
        else if (stricmp(key, "nonUniformScale") == 0) {
            *(Bool *)(thisPtr + 0x9c) = (atoi(val) != 0);
        }
        /* "useLength" */
        else if (stricmp(key, "useLength") == 0) {
            *(Bool *)(thisPtr + 0x9d) = (atoi(val) != 0);
        }
        /* "name" */
        else if (stricmp(key, "name") == 0) {
            if (!val)
                goto error_key;
            I_strncpyz((char *)thisPtr, val, 0x20);
        }
        /* "shaderImpact" */
        else if (stricmp(key, "shaderImpact") == 0) {
            I_strncpyz((char *)(thisPtr + 0x20), val, 0x20);
        }
        /* "sequenceStartFrameMode" */
        else if (stricmp(key, "sequenceStartFrameMode") == 0) {
            n = atoi(val);
            if ((unsigned int)n > 2)
                goto error_key;
            *(int *)(thisPtr + 0x288) = n;
        }
        /* "sequenceFixedFrameValue" */
        else if (stricmp(key, "sequenceFixedFrameValue") == 0) {
            n = atoi(val);
            *(int *)(thisPtr + 0x28c) = n;
            if (n <= 0)
                goto error_key;
        }
        /* "sequencePlayRateMode" */
        else if (stricmp(key, "sequencePlayRateMode") == 0) {
            n = atoi(val);
            if ((unsigned int)n > 1)
                goto error_key;
            *(int *)(thisPtr + 0x290) = n;
        }
        /* "sequenceFixedFpsValue" */
        else if (stricmp(key, "sequenceFixedFpsValue") == 0) {
            float fpsVal = (float)atof(val);
            *(float *)(thisPtr + 0x294) = fpsVal;
            if (fpsVal < 0.0f)
                goto error_key;
        }
        /* "sequenceLoopMode" */
        else if (stricmp(key, "sequenceLoopMode") == 0) {
            n = atoi(val);
            if ((unsigned int)n > 1)
                goto error_key;
            *(int *)(thisPtr + 0x298) = n;
        }
        /* "sequenceLoopTimes" */
        else if (stricmp(key, "sequenceLoopTimes") == 0) {
            n = atoi(val);
            *(int *)(thisPtr + 0x29c) = n;
            if (n < 0)
                goto error_key;
        }
        /* "spawnFrustumCullRadius" */
        else if (stricmp(key, "spawnFrustumCullRadius") == 0) {
            float radius = (float)atof(val);
            *(float *)(thisPtr + 0x2a0) = radius;
            if (radius < 0.0f)
                goto error_key;
        }
        /* Channel group keys: rgb, rgb2, rgbRand, alpha, etc. */
        else if (stricmp(key, "rgb") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 0, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "rgb2") == 0 || stricmp(key, "rgbRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 1, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "alpha") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 2, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "alphaRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 3, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "size") == 0 || stricmp(key, "width") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 4, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "sizeRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 5, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "size2") == 0 || stricmp(key, "width2") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 6, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "size2Rand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 7, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "length") == 0 || stricmp(key, "height") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 8, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "lengthRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 9, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "rotationDelta") == 0) {
            /* Already handled via I_stricmp above for single-value form;
               This handles the group/channel form */
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 10, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "rotationDeltaRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 11, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocityX") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 12, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocityY") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 13, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocityZ") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 14, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocityXRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 15, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocityYRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 16, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocityZRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 17, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocity2X") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 18, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocity2Y") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 19, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocity2Z") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 20, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocity2XRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 21, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocity2YRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 22, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else if (stricmp(key, "velocity2ZRand") == 0) {
            if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)pairs, 23, 0, 0, 0, 0, 0, 0, 0, 0))
                goto check_key_error;
        }
        else {
            FX_Print("Unknown key parsing an effect primitive: %s\n", key);
            return 0;
        }

        pairs = GPV_NEXT(pairs);
        continue;

check_key_error:
        if (key) {
            FX_Print("^1FX Error while parsing key '%s'\n", key);
            return 0;
        }
        /* If key is null, skip to post-parse validation */
        goto post_parse;
error_key:
        if (key) {
            FX_Print("^1FX Error while parsing key '%s'\n", key);
            return 0;
        }
        goto post_parse;
    }

post_parse:
    /* Post-parse: process subgroups for channel migration */
    {
        GPValue *sub = GPG_SUBGROUPS(grp);
        while (sub) {
            const char *subKey = GPV_STRING(sub);

            if (stricmp(subKey, "rgb") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 0, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "rgb2") == 0 || stricmp(subKey, "rgbRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 1, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "alpha") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 2, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "alphaRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 3, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "size") == 0 || stricmp(subKey, "width") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 4, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "sizeRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 5, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "size2") == 0 || stricmp(subKey, "width2") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 6, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "size2Rand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 7, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "length") == 0 || stricmp(subKey, "height") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 8, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "lengthRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 9, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "rotationDelta") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 10, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "rotationDeltaRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 11, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocityX") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 12, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocityY") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 13, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocityZ") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 14, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocityXRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 15, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocityYRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 16, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocityZRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 17, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocity2X") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 18, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocity2Y") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 19, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocity2Z") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 20, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocity2XRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 21, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocity2YRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 22, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else if (stricmp(subKey, "velocity2ZRand") == 0) {
                if (!PrimitiveTemplate_ParseChannel(_this, backCompatibleParameters, (GPGroup *)sub, 23, 0, 0, 0, 0, 0, 0, 0, 0)) {
                    if (subKey) {
                        FX_Print("^1FX Error while parsing key '%s'\n", subKey);
                        return 0;
                    }
                    goto do_migration;
                }
            }
            else {
                FX_Print("Unknown group key parsing a particle: %s\n", subKey);
                return 0;
            }

            sub = GPV_NEXT(sub);
        }
    }

do_migration:
    /* Backward compatible channel migration */
    {
        int channelId;
        byte *bcp = (byte *)backCompatibleParameters;
        FxChannel *channels = (FxChannel *)(thisPtr + 0x100);
        float *lifePtr = (float *)(thisPtr + 0x58);

        for (channelId = 0; channelId < 24; channelId++) {
            FxChannelBackwardCompatible *bc = (FxChannelBackwardCompatible *)(bcp + channelId * 0x40);
            if (!bc->containsData)
                continue;

            int dimensions;
            int forceUnitScale;
            if (channelId == 2) {
                /* alpha: 1 dimension, forceUnitScale=1 */
                dimensions = 1;
                forceUnitScale = 1;
            } else if (channelId == 0) {
                /* rgb: 3 dimensions, forceUnitScale=0 */
                dimensions = 3;
                forceUnitScale = 0;
            } else if (channelId == 1) {
                /* rgb2/rgbRand: 3 dimensions, forceUnitScale=0 */
                dimensions = 1; /* Actually — re-checking: channel 1 is FXCHAN_COLOR_RAND */
                forceUnitScale = 0;
            } else {
                dimensions = 1;
                forceUnitScale = 0;
            }

            /* Compute lifetime midpoint */
            float lifetime = lifePtr[0]; /* mLife.mMin */
            float lifeMax = lifePtr[1]; /* mLife.mMax */
            float lifeMid = lifetime + (lifeMax - lifetime) * 0.5f;

            FxChannel_CreateViaMigration(bc, dimensions, lifeMid, forceUnitScale, &channels[channelId]);
        }
    }

    /* Bounding box validation */
    {
        float *thisf = (float *)thisPtr;
        float minX = *(float *)(thisPtr + 0xa0);
        float maxX = *(float *)(thisPtr + 0xac);
        if (minX > maxX) {
            FX_Print("^1FX bounding box mins / maxs invalid for effect '%s'\n", _this);
            return 0;
        }
        float minY = *(float *)(thisPtr + 0xa4);
        float maxY = *(float *)(thisPtr + 0xb0);
        if (minY > maxY) {
            FX_Print("^1FX bounding box mins / maxs invalid for effect '%s'\n", _this);
            return 0;
        }
        float minZ = *(float *)(thisPtr + 0xa8);
        float maxZ = *(float *)(thisPtr + 0xb4);
        if (minZ > maxZ) {
            FX_Print("^1FX bounding box mins / maxs invalid for effect '%s'\n", _this);
            return 0;
        }

        float rangeZ = maxZ - minZ;
        float rangeX = maxX - minX;
        float rangeY = maxY - minY;
        if (rangeX > rangeZ || rangeY > rangeZ) {
            FX_Print("^1FX bounding box width or depth is larger than height for effect '%s'\n", _this);
            return 0;
        }
    }

    return 1;
}

#if 0 /* Original ASM for PrimitiveTemplate_ParsePrimitiveInternal */
#endif

/* line 2102 */
Bool PrimitiveTemplate_ParsePrimitive(const PrimitiveTemplate * _this, GPGroup *grp)
{
    BackCompatibleParameters *bcp;
    Bool success;

    bcp = (BackCompatibleParameters *)Hunk_AllocateTempMemoryInternal(0x600);
    success = PrimitiveTemplate_ParsePrimitiveInternal(_this, bcp, grp);
    Hunk_FreeTempMemory(bcp);

    return (Bool)(unsigned char)success;
}

#if 0 /* Original ASM for PrimitiveTemplate_ParsePrimitive */
#endif
#else
Bool PrimitiveTemplate_ParseGroupFlags(const PrimitiveTemplate * _this, const char *val, int *groupFlags, const PrimitiveTemplate * _this_3, const char *flag, const FxFlagEntry *flagEntries, int flagEntryCount)
{
    byte *thisPtr = (byte *)_this;
    char flags_buf[0x80]; /* 4 tokens * 0x20 each */
    char token0[0x20], token1[0x20], token2[0x20], token3[0x20];
    int v; /* number of tokens parsed */
    int i, j;
    int found;

    /* line 353: zero the flag buffer (128 bytes = 4 tokens * 0x20 each) */
    memset(flags_buf, 0, 0x80);

    /* line 359: parse up to 4 space-separated flag names from val */
    v = sscanf(val, "%s %s %s %s", flags_buf, flags_buf + 0x20, flags_buf + 0x40, flags_buf + 0x60);

    if (v <= 0)
        return 1;

    /* Reset groupFlags */
    *groupFlags = 0;

    /* For each parsed token, match against flagEntries */
    for (i = 0; i < v; i++) {
        const char *tok = flags_buf + i * 0x20;
        if (*tok == '\0')
            continue;

        found = 0;
        for (j = 0; j < flagEntryCount; j++) {
            if (stricmp(flagEntries[j].flag, tok) == 0) {
                /* OR in both mask words */
                *(unsigned int *)(thisPtr + 0x90) |= flagEntries[j].masks[0];
                *(unsigned int *)(thisPtr + 0x94) |= flagEntries[j].masks[1];
                found = 1;
                break;
            }
        }

        if (!found) {
            FX_Print("FxTemplate: Unknown flag '%s'\n", tok);
            return 0;
        }
    }

    return 1;
}
#endif
