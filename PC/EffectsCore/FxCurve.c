/* Converted to C from ASM: FxCurve.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxCurve.cpp */

#include "common_types.h"
#include "imports.h"

void FxCurveIterator_Create(FxCurveIterator *createe, const FxCurve *master)
{
    createe->master = master;
    createe->currentKeyIndex = 0;
}

float FxCurve_Integrate(const FxCurve *curve, float normDuration)
{
    int keyStride = curve->dimensionCount + 1;
    float *keys = (float *)((char *)curve + 8);
    float result = 0.0f;

    /* Walk through complete key segments where normDuration > next key time */
    int i = 0;
    if (normDuration > keys[keyStride]) {
        /* Process full segments */
        int next = 1;
        while (normDuration > keys[next * keyStride]) {
            float dt = keys[next * keyStride] - keys[i * keyStride];
            float avgVal = (keys[next * keyStride + 1] + keys[i * keyStride + 1]) * 0.5f;
            result += avgVal * dt;
            i = next;
            next++;
        }
        /* i now points to the last complete key */
    }

    /* Process partial last segment */
    float dt = normDuration - keys[i * keyStride];
    float t0 = keys[i * keyStride];
    float t1 = keys[(i + 1) * keyStride];
    float v0 = keys[i * keyStride + 1];
    float v1 = keys[(i + 1) * keyStride + 1];
    float interpVal = (v1 - v0) * dt / (t1 - t0) + v0;
    float avgVal = (interpVal + v0) * 0.5f;
    result += avgVal * dt;

    return result;
}
