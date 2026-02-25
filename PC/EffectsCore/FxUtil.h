#ifndef PC_EFFECTSCORE_FXUTIL_H_H
#define PC_EFFECTSCORE_FXUTIL_H_H

/* Reconstructed from: PC/EffectsCore/FxUtil.h */
/* Types attributed via N_BINCL cross-reference */

#include "PC/EffectsCore/FxPrimitives.h"

struct EffectPrimitive;

struct EffectPrimitive {
    const EffectTemplate *fx;
    const PrimitiveTemplate *primTemp;
    FxBoltFramePtr boltFrame;
};

#endif /* PC_EFFECTSCORE_FXUTIL_H_H */
