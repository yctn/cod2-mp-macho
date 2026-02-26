/* Converted to C from ASM: FxChannel.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxChannel.cpp */

#include "common_types.h"
#include "imports.h"

extern const FxCurve *FxCurve_AllocAndCreateWithKeys(const float *keyArray, int dimensionCount, int keyCount);
extern void FxRange_SetRange(void *range, float min, float max);
extern float FxRange_GetValPct(void *range, float pct);
extern float flrand(float min, float max);
extern float cosf(float x);

void FxChannel_CreateDefault(FxChannel *createe, int dimensions, float value1, float value2)
{
    int keySize = dimensions + 1;
    float keys[22]; /* max 2 keys * (max 10 dimensions + 1 time) */

    /* First key at t=0 */
    keys[0] = 0.0f;

    /* Second key at t=1 */
    keys[keySize] = 1.0f;

    /* Fill dimension values */
    int d;
    for (d = 0; d < dimensions; d++) {
        keys[1 + d] = value1;
        keys[keySize + 1 + d] = value2;
    }

    /* Create curve and store in channel */
    createe->curve = FxCurve_AllocAndCreateWithKeys(keys, dimensions, 2);

    /* Set range to [1.0, 1.0] (no variation) */
    FxRange_SetRange(&createe->scaleRange, 1.0f, 1.0f);
}

/* line 190 */
void FxChannel_CreateViaMigration(const FxChannelBackwardCompatible *source, int dimensions, float lifetime, int forceUnitScale, FxChannel *target)
{
    float keys[132]; /* 16 keys * (max 8 dimensions + 1 time) */
    float startVals[3];
    float endVals[3];
    float scaleFactor;
    float delayFraction;
    float waveParm;
    int flags;
    int flagMode;
    int randomize;
    int hasData;
    int keySize;
    int dimensionId;
    int timeStep;
    float t;
    float val;

    /* Determine scale factor */
    if (forceUnitScale) {
        /* line 203: forceUnitScale is true, use 1.0 */
        scaleFactor = 1.0f;
    } else {
        /* line 204: compute scale from source ranges */
        float valLT = FxRange_GetValPct((void *)&source->end[0], 0.5f);
        float valStart = FxRange_GetValPct((void *)&source->start[0], 0.5f);

        /* line 45: pick larger of valStart and valLT */
        float diff = valStart - valLT;
        float maxVal;
        if (diff < 0.0f) {
            maxVal = valLT;
        } else {
            maxVal = valStart;
        }

        /* line 204: scale by 4/3 */
        maxVal *= 1.3333333730697632f;

        /* line 206: clamp scaleFactor */
        if (1.0f > maxVal) {
            scaleFactor = 1.0f;
        } else {
            scaleFactor = 1.0f / maxVal;
        }
    }

    /* line 209: compute half-range of source->start[0] and set target scaleRange */
    {
        float halfRange = (source->start[0].mMax - source->start[0].mMin) * 0.5f;
        float rangeMax = scaleFactor + halfRange;
        float rangeMin = scaleFactor - halfRange;
        FxRange_SetRange(&target->scaleRange, rangeMin, rangeMax);
    }

    /* line 217: sample start, end, and parm values for each dimension */
    if (dimensions == 0) {
        delayFraction = 0.0f;
        waveParm = 0.0f;
    } else {
        /* Pointers walk through the source ranges:
         * source->start[0] is at offset 0, each FxRange is 8 bytes
         * source->end[0] is at offset 0x18
         * source->parm is at offset 0x30
         */
        const FxRange *startPtr = &source->start[0];
        const FxRange *endPtr = &source->end[0];
        const FxRange *parmPtr = &source->parm;

        float lastParmVal = 0.0f;
        for (dimensionId = 0; dimensionId < dimensions; dimensionId++) {
            /* line 219: sample start value at 50% */
            startVals[dimensionId] = FxRange_GetValPct((void *)&startPtr[dimensionId], 0.5f) * scaleFactor;
            /* line 220: sample end value at 50% */
            endVals[dimensionId] = FxRange_GetValPct((void *)&endPtr[dimensionId], 0.5f) * scaleFactor;
            /* line 221: sample parm value at 50% (reuses single parm range for all dims) */
            lastParmVal = FxRange_GetValPct((void *)parmPtr, 0.5f) * scaleFactor;
        }
        delayFraction = lastParmVal * 0.009999999776482582f;
        waveParm = lastParmVal * 0.0031415929552167654f;
    }

    /* line 226: waveParm *= lifetime */
    waveParm *= lifetime;

    /* line 228: read flags from source */
    flags = source->flags;

    /* line 230: check containsData bit (bit 0) */
    hasData = flags & 1;

    if (!hasData) {
        /* line 232: no data flag set */
        flagMode = flags & 0xC;
        if (flagMode == 4) {
            /* 3-key curve with delay: t=0, t=delayFraction, t=1.0 */
            keySize = dimensions + 1;
            keys[0] = 0.0f;
            keys[keySize] = delayFraction;
            *(int *)&keys[keySize * 2] = 0x3f800000; /* 1.0f */
            for (dimensionId = 0; dimensionId < dimensions; dimensionId++) {
                keys[1 + dimensionId] = startVals[dimensionId];
                keys[keySize + 1 + dimensionId] = startVals[dimensionId];
                keys[keySize * 2 + 1 + dimensionId] = endVals[dimensionId];
            }
            target->curve = FxCurve_AllocAndCreateWithKeys(keys, dimensions, 3);
            return;
        }
        /* fall through to general case at acd6b */
    } else {
        /* hasData is true */
        flagMode = flags & 0xC;
        if (flagMode == 0) {
            /* Simple 2-key linear: t=0 and t=1.0 */
            keySize = dimensions + 1;
            keys[0] = 0.0f;
            *(int *)&keys[keySize] = 0x3f800000; /* 1.0f */
            for (dimensionId = 0; dimensionId < dimensions; dimensionId++) {
                keys[1 + dimensionId] = startVals[dimensionId];
                keys[keySize + 1 + dimensionId] = endVals[dimensionId];
            }
            target->curve = FxCurve_AllocAndCreateWithKeys(keys, dimensions, 2);
            return;
        }
        /* fall through to general case at acd6b */
    }

    /* General case: 16-key sampled curve */
    /* acd6b */
    keySize = dimensions + 1;
    randomize = (flags >> 1) & 1;
    t = 0.0f;

    for (timeStep = 0; timeStep < 16; timeStep++) {
        float oneMinusT;
        float t2; /* the "envelope" value for interpolation */

        if (hasData) {
            /* line 135 */
            oneMinusT = 1.0f - t;
        } else {
            oneMinusT = 1.0f;
        }

        /* Compute t2 based on flagMode */
        if (flagMode == 4) {
            /* line 139: fade-in envelope */
            if (t > delayFraction) {
                /* line 140 */
                float progress = (t - delayFraction) / (1.0f - delayFraction);
                t2 = 1.0f - progress;
            } else {
                t2 = 1.0f;
            }
        } else if (flagMode == 8) {
            /* line 149: cosine wave */
            t2 = cosf(waveParm * t) * oneMinusT;
            goto store_key;
        } else if (flagMode == 0xC) {
            /* line 153: fade-out with delay */
            if (delayFraction > t) {
                t2 = (delayFraction - t) / delayFraction;
            } else {
                t2 = 0.0f;
            }
        } else {
            /* default: linear (no special mode) */
            t2 = oneMinusT;
            goto store_key;
        }

        /* line 158: if hasData, blend oneMinusT and t2 */
        if (hasData) {
            oneMinusT *= 0.5f;
            t2 = t2 * 0.5f + oneMinusT;
        }

store_key:
        /* line 164-165: store time value */
        keys[keySize * timeStep] = t;

        /* line 167: store dimension values */
        if (dimensions > 0) {
            float oneMinusT2 = 1.0f - t2;

            if (randomize) {
                /* Randomized path */
                if (t2 > 1.0f) {
                    /* t2 > 1.0: clamp values with random range [0, max(0, val)] or [0, 1.0] */
                    int d;
                    for (d = 0; d < dimensions; d++) {
                        float blended = t2 * startVals[d] + oneMinusT2 * endVals[d];
                        float maxVal;
                        if (0.0f > blended) {
                            maxVal = 0.0f;
                        } else {
                            maxVal = 1.0f;
                        }
                        keys[keySize * timeStep + 1 + d] = flrand(0.0f, maxVal);
                    }
                } else {
                    /* t2 <= 1.0: random range [0, max(0, val)] */
                    int d;
                    for (d = 0; d < dimensions; d++) {
                        float blended = t2 * startVals[d] + oneMinusT2 * endVals[d];
                        if (0.0f > blended) {
                            blended = 0.0f;
                        }
                        keys[keySize * timeStep + 1 + d] = flrand(0.0f, blended);
                    }
                }
            } else if (t2 > 1.0f) {
                /* Non-randomized, t2 > 1.0: clamp negative values to 0 */
                int d;
                for (d = 0; d < dimensions; d++) {
                    float blended = t2 * startVals[d] + oneMinusT2 * endVals[d];
                    if (0.0f > blended) {
                        keys[keySize * timeStep + 1 + d] = 0.0f;
                    } else {
                        keys[keySize * timeStep + 1 + d] = 1.0f;
                    }
                }
            } else {
                /* Non-randomized, t2 <= 1.0: blend, clamp negatives to 0 */
                int d;
                for (d = 0; d < dimensions; d++) {
                    float blended = oneMinusT2 * endVals[d] + t2 * startVals[d];
                    if (0.0f > blended) {
                        blended = 0.0f;
                    }
                    keys[keySize * timeStep + 1 + d] = blended;
                }
            }
        }

        /* line 123: advance time */
        t += 0.06666667014360428f;

        /* line 126: clamp t to 1.0 */
        if (timeStep < 15) {
            if (1.0f < t) {
                t = 1.0f;
            }
        }
    }

    /* line 186: create curve with 16 keys */
    target->curve = FxCurve_AllocAndCreateWithKeys(keys, dimensions, 16);
}
