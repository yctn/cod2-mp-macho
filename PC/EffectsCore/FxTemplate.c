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
#define GPV_STRING(v) (((GPValue *)(v))->name)
#define GPV_NEXT(v)   ((GPValue *)((GPObject *)(v))->next)
#define GPV_LIST(v)   (((GPValue *)(v))->valueList)

/* GPGroup field access macros */
#define GPG_PAIRS(g)     (((GPGroup *)(g))->pairList)
#define GPG_SUBGROUPS(g) ((GPValue *)((GPGroup *)(g))->subGroupList)

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

    FxChannel *chan = (FxChannel *)(_this + channelOffset);
    chan->curve = FxCurve_AllocAndCreateWithKeys(keys, 1, 2);
    chan->scaleRange.mMin = maxRange;
    chan->scaleRange.mMax = maxRange;
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

    FxChannel *chan = (FxChannel *)(_this + channelOffset);
    chan->curve = FxCurve_AllocAndCreateWithKeys(keys, 1, 2);
    chan->scaleRange.mMin = maxRange;
    chan->scaleRange.mMax = maxRange;
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

    FxChannel *chan = (FxChannel *)(_this + channelOffset);
    chan->curve = FxCurve_AllocAndCreateWithKeys(keys, 1, 2);
    chan->scaleRange.mMin = 1.0f;
    chan->scaleRange.mMax = 1.0f;
}

/* ==================== Non-naked functions (unchanged) ==================== */

/* line 2199 */
void FxRange_SetRange(const FxRange * _this, float min, float max)
{
    ((FxRange *)_this)->mMin = min;
    ((FxRange *)_this)->mMax = max;
}

/* line 151 */
void PrimitiveTemplate_Shutdown(const PrimitiveTemplate * _this)
{
    MediaHandles_Shutdown(&((PrimitiveTemplate *)_this)->mMediaHandles);
    MediaHandles_Shutdown(&((PrimitiveTemplate *)_this)->mImpactFxHandles);
    MediaHandles_Shutdown(&((PrimitiveTemplate *)_this)->mDeathFxHandles);
    MediaHandles_Shutdown(&((PrimitiveTemplate *)_this)->mEmitterFxHandles);
    MediaHandles_Shutdown(&((PrimitiveTemplate *)_this)->mPlayFxHandles);
}

/* line 2213 */
float FxRange_GetValPct(const FxRange * _this, float percent)
{
    float base = _this->mMin;
    float range = _this->mMax - base;
    return base + range * percent;
}

/* line 351 — NOTE: This function's ASM is incomplete/truncated in the original dump.
   Keeping as naked to preserve existing behavior. */
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
                ((PrimitiveTemplate *)_this)->mAttributeFlags |= flagEntries[j].masks[0];
                ((PrimitiveTemplate *)_this)->mSpawnFlags |= flagEntries[j].masks[1];
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
