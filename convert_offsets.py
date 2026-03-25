#!/usr/bin/env python3
"""Convert raw pointer offset patterns to struct field access.

Pattern: *(type *)(ptr + 0xNN)  ->  ptr->field
         *(type *)((byte *)ptr + 0xNN)  ->  ptr->field
         etc.
"""

import re
import sys

# ================================================================
# Struct offset tables
# Derived from:
#  - struct definitions in common_types.h
#  - comments in the C files
#  - FxArchive layout comment in FxArchive.c
#  - EffectTemplate struct (mEffectName, mPrimitiveCount, mPrimitives[24])
#  - PrimitiveTemplate struct (computed from field layout)
#  - ScheduledEffect struct (from common_types.h)
#  - FxScheduler struct (from common_types.h)
#  - GenericParser2 / GPGroup / GPValue layouts (from code patterns)
#  - FxGfxEntity struct (from common_types.h)
#  - Effect struct (from common_types.h)
#  - Particle struct (FxChannelInstance arrays)
#  - FxHelper struct (from common_types.h)
#  - FxBoltFrame layout (from FxPrimitives.c)
#  - TMediaList/MediaHandles layout (from code patterns)
#  - FxBoltInfo struct
#  - EffectCluster struct
#  - orientation_t (from quake types: vec3_t origin + axis[3])
# ================================================================

# FxChannelInstance size: FxCurveIterator(8) + float(4) = 12 bytes
# FxCurveIterator: const FxCurve* (4) + int (4) = 8 bytes
# FxChannel: const FxCurve* (4) + FxRange(8) = 12 bytes
# FxRange: float + float = 8 bytes

STRUCT_OFFSETS = {}

# ----------------------------------------------------------------
# FxArchive
# +0x00: MemoryFile *memFile
# +0x04: char isReading
# +0x05: char (unused)
# +0x08: int byteCounter
# +0x0c: int repeatCount
# +0x10: int zeroCount
# +0x14: int startPos
# ----------------------------------------------------------------
STRUCT_OFFSETS['FxArchive'] = {
    0x00: ('memFile',    'MemoryFile *'),
    0x04: ('isReading',  'char'),
    0x05: ('_flag05',    'char'),
    0x08: ('byteCounter','int'),
    0x0c: ('repeatCount','int'),
    0x10: ('zeroCount',  'int'),
    0x14: ('startPos',   'int'),
}

# ----------------------------------------------------------------
# EffectTemplate (struct in common_types.h)
# +0x00: const char *mEffectName
# +0x04: int mPrimitiveCount
# +0x08: PrimitiveTemplate *mPrimitives[24]  (24 * 4 = 96 bytes)
# size = 4 + 4 + 96 = 104 = 0x68
# ----------------------------------------------------------------
STRUCT_OFFSETS['EffectTemplate'] = {
    0x00: ('mEffectName',     'const char *'),
    0x04: ('mPrimitiveCount', 'int'),
    # mPrimitives[i] at 0x08 + i*4
    **{0x08 + i*4: (f'mPrimitives[{i}]', 'PrimitiveTemplate *') for i in range(24)},
}

# ----------------------------------------------------------------
# PrimitiveTemplate layout (derived from struct definition + Init function comments)
# char mName[32]           = 0x00..0x1f
# char mMaterialImpact[32] = 0x20..0x3f
# PrimType mType           = 0x40 (int=4)
# int mParentPrimIndex     = 0x44
# FxRange mSpawnDelay      = 0x48..0x4f  (min=0x48, max=0x4c)
# FxRange mSpawnCount      = 0x50..0x57  (min=0x50, max=0x54)
# FxRange mLife            = 0x58..0x5f  (min=0x58, max=0x5c)
# FxRange mSpawnRange      = 0x60..0x67  (min=0x60, max=0x64)
# MediaHandles mMediaHandles     = 0x68 (size=8: ptr(4)+count(2)+cap(2))
# MediaHandles mImpactFxHandles  = 0x70
# MediaHandles mDeathFxHandles   = 0x78
# MediaHandles mEmitterFxHandles = 0x80
# MediaHandles mPlayFxHandles    = 0x88
# int mAttributeFlags      = 0x90
# int mSpawnFlags          = 0x94
# int mGroupFlags          = 0x98 (or is it byte at 0x95?)
# Actually from code:
#   offset 0x90 = mAttributeFlags (int, testb $2 = bolting)
#   offset 0x94 = mSpawnFlags (int)
#   offset 0x95 = byte in mSpawnFlags? No...
#   From FxScheduler.c line 418: *(byte *)((byte *)primTemp + 0x95) & 1
#   From FxScheduler.c line 680: *(byte *)((byte *)primTemp + 0x95) & 4
#   From FxScheduler.c line 278: *(byte *)((byte *)primTemp + 0x90) & 2
#   So 0x90 = mAttributeFlags (int), 0x94 = mSpawnFlags (int)
#   byte at 0x95 = second byte of mSpawnFlags (little-endian)
#   Actually MediaHandles is 8 bytes (ptr=4, count+cap=4)?
#   Let's check: MediaHandles has TMediaList mMediaList
#   TMediaList unknown... but from MediaHandles_Shutdown: *(void**)self=ptr, self+4=count, self+6=capacity
#   So TMediaList = {void *elements; short count; short capacity;} = 8 bytes
#   MediaHandles = {TMediaList mMediaList;} = 8 bytes
# So layout:
#   0x68: mMediaHandles (8)
#   0x70: mImpactFxHandles (8)
#   0x78: mDeathFxHandles (8)
#   0x80: mEmitterFxHandles (8)
#   0x88: mPlayFxHandles (8)
#   0x90: mAttributeFlags (int, 4)
#   0x94: mSpawnFlags (int, 4)
#   0x98: mGroupFlags (int, 4)   [but code shows 0x99 = Bool mNonUniformScale?]
# Actually from struct definition:
#   int mAttributeFlags    = 0x90
#   int mSpawnFlags        = 0x94
#   int mGroupFlags        = 0x98
#   Bool mNonUniformScale  = 0x9c (Bool=int=4?)
#   Bool useLength         = 0xa0?
# Hmm. From FxTemplate.c:
#   *(int *)(_this + 0x90) |= flagBits;  for mAttributeFlags
# And FxScheduler line 278:
#   *(byte *)((byte *)primTemp + 0x90) & 2  -- checking bit 1 of mAttributeFlags (byte access)
# This is consistent: mAttributeFlags is at 0x90.
# From FxScheduler line 418:
#   *(byte *)((byte *)primTemp + 0x95) & 1  -- byte 1 of mSpawnFlags (0x94 + 1)
# From FxUtil.c line 1265/1726:
#   int flags = *(int *)(primTemp + 0x94)  <- mSpawnFlags
#   int flags = *(int *)(primTemp + 0x90)  <- mAttributeFlags
# Bool is typedef int. So:
#   0x9c = Bool mNonUniformScale
#   0xa0 = Bool useLength (but wait, that's only if Bool=4. Let's check)
# From FxPrimitives.c line ~1757:
#   *(byte *)(particle + 0x104) = *(byte *)(primTemp + 0x9c);
# 0x9c = mNonUniformScale? Let me check the struct again:
# struct PrimitiveTemplate fields after mPlayFxHandles:
#   int mAttributeFlags, int mSpawnFlags, int mGroupFlags, Bool mNonUniformScale, Bool useLength
# If Bool=int(4): 0x90, 0x94, 0x98, 0x9c, 0xa0
# If Bool=char(1): 0x90, 0x94, 0x98, 0x9c, 0x9d
# From code at 0x9c being accessed as byte, and 0x95 being a byte within mSpawnFlags,
# it seems Bool here might be 1 byte. But in common_types.h Bool is likely int.
# Let's assume Bool=int(4):
#   0x9c = mNonUniformScale
#   0xa0 = useLength
#   0xa4 = vec3_t mMin (12 bytes)
#   0xb0 = vec3_t mMax (12 bytes)
# Hmm, but FxUtil.c uses 0xa9 as a byte flag:
#   if (*(byte *)(eff + 0xa9) & 0x10)
# This could be inside mMin which starts at 0xa4... that doesn't make sense.
# Let me reconsider. Bool might be 1 byte here (typedef bool as char or byte).
# With Bool=1:
#   0x90: mAttributeFlags (int)
#   0x94: mSpawnFlags (int)
#   0x98: mGroupFlags (int)
#   0x9c: mNonUniformScale (Bool=1)
#   0x9d: useLength (Bool=1)
#   0x9e: padding (2 bytes for alignment?)
#   0xa0: vec3_t mMin (12 bytes) = 0xa0..0xab
#   0xac: vec3_t mMax (12 bytes) = 0xac..0xb7
#   0xb8: FxRange mOrigin1X (8) = 0xb8..0xbf
# But from FxUtil line 2101:
#   if (*(byte *)(eff + 0xa9) & 0x10)
# And 'eff' there is NOT a PrimitiveTemplate but an Effect struct (eff = effect).
# Let me separate this - 'eff' in FxUtil.c might be an Effect or some other struct.
#
# The key insight: I need to track the variable type for each pointer variable,
# not just do raw offset matching.
# ----------------------------------------------------------------

# PrimitiveTemplate: from struct definition and comments
# mName[32]=0x00, mMaterialImpact[32]=0x20, mType(int)=0x40, mParentPrimIndex(int)=0x44
# mSpawnDelay(FxRange)=0x48, mSpawnCount=0x50, mLife=0x58, mSpawnRange=0x60
# mMediaHandles=0x68, mImpactFxHandles=0x70, mDeathFxHandles=0x78
# mEmitterFxHandles=0x80, mPlayFxHandles=0x88
# mAttributeFlags(int)=0x90, mSpawnFlags(int)=0x94, mGroupFlags(int)=0x98
# Bool mNonUniformScale=0x9c (assume int=4), Bool useLength=0xa0 -> but
# From Init: channels start at 0x100 (mFxChannels[0])
# So between 0x98 and 0x100 we have:
#   0x98: mGroupFlags (int, 4)
#   0x9c: mNonUniformScale (4 or 1)
#   Let's say 0x9c = mNonUniformScale(Bool=4), 0xa0 = useLength(Bool=4)
#   0xa4: vec3_t mMin (12)
#   0xb0: vec3_t mMax (12)
#   0xbc: FxRange mOrigin1X (8)  <- wait 0xbc is not right
#   Let me check: after mMax(0xb0, size 12) = ends at 0xbc
#   0xbc: FxRange mOrigin1X? but Init doesn't show these directly
# Actually from common_types.h struct PrimitiveTemplate:
#   After FxChannel mFxChannels[24] (at 0x100, size 24*12=288=0x120)
#   FxChannels end at 0x100+0x120 = 0x220
#   Then: FxRange mRotation=0x220, mAngle1=0x228, mAngle2=0x230, mAngle3=0x238
#         mAngle1Delta=0x240, mAngle2Delta=0x248, mAngle3Delta=0x250
#         mGravity=0x258, mDensity=0x260, mVariance=0x268
#         mTexCoordS=0x270, mTexCoordT=0x278 (WRONG - init shows 0x270,0x274 are separate floats)
# From Init function:
#   0x260: mDensity.mMin=10.0  -> but 0x260=mDensity.mMin, 0x264=mDensity.mMax
#   0x268: mVariance.mMin=1.0, 0x26c: mVariance.mMax=1.0
#   0x270: mTexCoordS.mMin=1.0, 0x274: mTexCoordS.mMax=1.0
#   0x278: mTexCoordT.mMin=1.0, 0x27c: mTexCoordT.mMax=1.0
# Then:
#   0x280: mElasticity? -> from FxUtil.c: FxRange_GetVal(primTemp + 0x280) = bounce coefficient
#   0x288: mSequenceStartFrameMode (int)
#   0x28c: mSequenceFixedFrameValue (int)
#   0x290: mSequencePlayRateMode (int)
#   0x294: mSequenceFixedFpsValue (float)
#   0x298: mSequenceLoopMode (int)
#   0x29c: mSequenceLoopTimes (int)
#   0x2a0: spawnFrustumCullRadius (float)
# Total = 0x2a4 bytes (confirmed by Hunk_AllocAlignInternal(0x2a4, 4))
#
# So between 0x100 and 0x220 we have FxChannels, and before 0x100 we need to fit:
# After mPlayFxHandles ends at 0x90, then:
# 0x90: mAttributeFlags, 0x94: mSpawnFlags, 0x98: mGroupFlags
# Then Bool mNonUniformScale and Bool useLength, then vec3_t mMin, mMax, then FxRange fields
# If Bool=int(4): 0x9c=mNonUniformScale, 0xa0=useLength
#   0xa4: vec3_t mMin (12), 0xb0: vec3_t mMax (12) -> ends at 0xbc
#   0xbc: FxRange mOrigin1X (8), 0xc4: mOrigin1Y, 0xcc: mOrigin1Z
#   0xd4: FxRange mOrigin2X, 0xdc: mOrigin2Y, 0xe4: mOrigin2Z
#   0xec: FxRange mRadius -> wait Init shows 0xe8=mRadius.mMin, 0xec=mRadius.mMax
#   So 0xe8: FxRange mRadius -> but 0xec would be max, so 0xe8+4+4=end 0xf0
#   0xf0: FxRange mHeight -> init shows 0xf0=mHeight.mMin, 0xf4=mHeight.mMax
#   0xf8: FxRange mWindModifier -> FxUtil shows bounce at 0xf8 for primTemp
# Wait from FxUtil.c:
#   FxRange_GetVal(primTemp + 0xf8) = bounce
# And struct says FxRange mElasticity is the bounce-related field.
# In struct: mRadius=0xe8, mHeight=0xf0, mWindModifier=0xf8 (8 bytes -> ends at 0x100)
# Then 0x100 = FxChannel mFxChannels[0]
# This all works out perfectly!
# But wait: after mMax=0xb0(12) end at 0xbc, then mOrigin1X=0xbc: but Init doesn't show origin ranges
# Let me check: mOrigin1X thru mOrigin2Z = 6 FxRanges = 6*8 = 48 = 0x30
# 0xbc + 0x30 = 0xec -> too late
# Let me recheck: 0xbc is AFTER vec3 mMax. Then:
#   0xbc: mOrigin1X (8) = ends 0xc4
#   0xc4: mOrigin1Y (8) = ends 0xcc
#   0xcc: mOrigin1Z (8) = ends 0xd4
#   0xd4: mOrigin2X (8) = ends 0xdc
#   0xdc: mOrigin2Y (8) = ends 0xe4
#   0xe4: mOrigin2Z (8) = ends 0xec
#   0xec: mRadius  (8) - but Init shows mRadius.mMin at 0xe8!
# Contradiction. So Bool must be 1 byte each (or different alignment).
# With Bool=1, padding to align vec3 to 4:
#   0x98: mGroupFlags (4), end 0x9c
#   0x9c: mNonUniformScale (Bool=1=char), 0x9d: useLength (Bool=1=char)
#   0x9e-0x9f: 2 bytes padding
#   0xa0: vec3_t mMin (12) = 0xa0..0xab
#   0xac: vec3_t mMax (12) = 0xac..0xb7
#   0xb8: FxRange mOrigin1X (8) = 0xb8..0xbf
#   0xc0: mOrigin1Y (8) = 0xc0..0xc7
#   0xc8: mOrigin1Z (8) = 0xc8..0xcf
#   0xd0: mOrigin2X (8) = 0xd0..0xd7
#   0xd8: mOrigin2Y (8) = 0xd8..0xdf
#   0xe0: mOrigin2Z (8) = 0xe0..0xe7
#   0xe8: mRadius (8) = 0xe8..0xef  <- matches Init 0xe8=mRadius.mMin
#   0xf0: mHeight (8) = 0xf0..0xf7  <- matches Init 0xf0=mHeight.mMin
#   0xf8: mWindModifier (8) = 0xf8..0xff  <- matches FxUtil 0xf8=bounce/elasticity
#   0x100: FxChannel mFxChannels[0]  <- matches Init
# PERFECT! So Bool=1 byte.
#
# Now for FxChannels at 0x100, FxChannel size = 4(ptr) + 8(FxRange) = 12 bytes
# 24 channels * 12 = 288 = 0x120
# mFxChannels ends at 0x100 + 0x120 = 0x220
# Then: mRotation=0x220, mAngle1=0x228, mAngle2=0x230, mAngle3=0x238
#       mAngle1Delta=0x240, mAngle2Delta=0x248, mAngle3Delta=0x250
#       mGravity=0x258, mDensity=0x260, mVariance=0x268
#       mTexCoordS=0x270, mTexCoordT=0x278, mElasticity=0x280
#       mSequenceStartFrameMode=0x288, mSequenceFixedFrameValue=0x28c
#       mSequencePlayRateMode=0x290, mSequenceFixedFpsValue=0x294
#       mSequenceLoopMode=0x298, mSequenceLoopTimes=0x29c
#       spawnFrustumCullRadius=0x2a0
#
# FxChannelId enum: 0=color,1=colorRand,2=alpha,3=alphaRand,4=size,5=sizeRand,
#   6=size2,7=size2Rand,8=length,9=lengthRand,10=rotDelta,11=rotDeltaRand,
#   12=velX,13=velY,14=velZ,15=velXRand,16=velYRand,17=velZRand,
#   18=vel2X,19=vel2Y,20=vel2Z,21=vel2XRand,22=vel2YRand,23=vel2ZRand
#
# Channel offsets at Init match this numbering via 0x100 + id*12

CHANNEL_NAMES = [
    'color', 'colorRand', 'alpha', 'alphaRand',
    'size', 'sizeRand', 'size2', 'size2Rand',
    'length', 'lengthRand', 'rotationDelta', 'rotationDeltaRand',
    'velocityX', 'velocityY', 'velocityZ', 'velocityXRand', 'velocityYRand', 'velocityZRand',
    'velocity2X', 'velocity2Y', 'velocity2Z', 'velocity2XRand', 'velocity2YRand', 'velocity2ZRand',
]

pt_offsets = {
    # mName[0..31]
    **{i: (f'mName[{i}]', 'char') for i in range(0, 32)},
    # mMaterialImpact[0..31]
    **{0x20+i: (f'mMaterialImpact[{i}]', 'char') for i in range(0, 32)},
    0x40: ('mType',            'PrimType'),
    0x44: ('mParentPrimIndex', 'int'),
    0x48: ('mSpawnDelay.mMin', 'float'),
    0x4c: ('mSpawnDelay.mMax', 'float'),
    0x50: ('mSpawnCount.mMin', 'float'),
    0x54: ('mSpawnCount.mMax', 'float'),
    0x58: ('mLife.mMin',       'float'),
    0x5c: ('mLife.mMax',       'float'),
    0x60: ('mSpawnRange.mMin', 'float'),
    0x64: ('mSpawnRange.mMax', 'float'),
    0x68: ('mMediaHandles',    'MediaHandles'),
    0x70: ('mImpactFxHandles', 'MediaHandles'),
    0x78: ('mDeathFxHandles',  'MediaHandles'),
    0x80: ('mEmitterFxHandles','MediaHandles'),
    0x88: ('mPlayFxHandles',   'MediaHandles'),
    0x90: ('mAttributeFlags',  'int'),
    0x94: ('mSpawnFlags',      'int'),
    0x98: ('mGroupFlags',      'int'),
    0x9c: ('mNonUniformScale', 'Bool'),
    0x9d: ('useLength',        'Bool'),
    0xa0: ('mMin',             'vec3_t'),
    0xa4: ('mMin[0]',          'float'),
    0xa8: ('mMin[1]',          'float'),
    0xac: ('mMax',             'vec3_t'),
    0xb0: ('mMax[0]',          'float'),
    0xb4: ('mMax[1]',          'float'),
    0xb8: ('mOrigin1X.mMin',   'float'),
    0xbc: ('mOrigin1X.mMax',   'float'),
    0xc0: ('mOrigin1Y.mMin',   'float'),
    0xc4: ('mOrigin1Y.mMax',   'float'),
    0xc8: ('mOrigin1Z.mMin',   'float'),
    0xcc: ('mOrigin1Z.mMax',   'float'),
    0xd0: ('mOrigin2X.mMin',   'float'),
    0xd4: ('mOrigin2X.mMax',   'float'),
    0xd8: ('mOrigin2Y.mMin',   'float'),
    0xdc: ('mOrigin2Y.mMax',   'float'),
    0xe0: ('mOrigin2Z.mMin',   'float'),
    0xe4: ('mOrigin2Z.mMax',   'float'),
    0xe8: ('mRadius.mMin',     'float'),
    0xec: ('mRadius.mMax',     'float'),
    0xf0: ('mHeight.mMin',     'float'),
    0xf4: ('mHeight.mMax',     'float'),
    0xf8: ('mWindModifier.mMin','float'),
    0xfc: ('mWindModifier.mMax','float'),
    # FxChannel mFxChannels[24] at 0x100, each FxChannel=12 bytes
    # FxChannel: {const FxCurve *curve; FxRange scaleRange;}
    # scaleRange.mMin at +4, scaleRange.mMax at +8
    **{0x100 + i*12:     (f'mFxChannels[{i}].curve',           'const FxCurve *') for i in range(24)},
    **{0x100 + i*12 + 4: (f'mFxChannels[{i}].scaleRange.mMin', 'float')           for i in range(24)},
    **{0x100 + i*12 + 8: (f'mFxChannels[{i}].scaleRange.mMax', 'float')           for i in range(24)},
    0x220: ('mRotation.mMin',    'float'),
    0x224: ('mRotation.mMax',    'float'),
    0x228: ('mAngle1.mMin',      'float'),
    0x22c: ('mAngle1.mMax',      'float'),
    0x230: ('mAngle2.mMin',      'float'),
    0x234: ('mAngle2.mMax',      'float'),
    0x238: ('mAngle3.mMin',      'float'),
    0x23c: ('mAngle3.mMax',      'float'),
    0x240: ('mAngle1Delta.mMin', 'float'),
    0x244: ('mAngle1Delta.mMax', 'float'),
    0x248: ('mAngle2Delta.mMin', 'float'),
    0x24c: ('mAngle2Delta.mMax', 'float'),
    0x250: ('mAngle3Delta.mMin', 'float'),
    0x254: ('mAngle3Delta.mMax', 'float'),
    0x258: ('mGravity.mMin',     'float'),
    0x25c: ('mGravity.mMax',     'float'),
    0x260: ('mDensity.mMin',     'float'),
    0x264: ('mDensity.mMax',     'float'),
    0x268: ('mVariance.mMin',    'float'),
    0x26c: ('mVariance.mMax',    'float'),
    0x270: ('mTexCoordS.mMin',   'float'),
    0x274: ('mTexCoordS.mMax',   'float'),
    0x278: ('mTexCoordT.mMin',   'float'),
    0x27c: ('mTexCoordT.mMax',   'float'),
    0x280: ('mElasticity.mMin',  'float'),
    0x284: ('mElasticity.mMax',  'float'),
    0x288: ('mSequenceStartFrameMode',    'StartFrameMode'),
    0x28c: ('mSequenceFixedFrameValue',   'int'),
    0x290: ('mSequencePlayRateMode',      'PlayRateMode'),
    0x294: ('mSequenceFixedFpsValue',     'float'),
    0x298: ('mSequenceLoopMode',          'LoopMode'),
    0x29c: ('mSequenceLoopTimes',         'int'),
    0x2a0: ('spawnFrustumCullRadius',     'float'),
}
STRUCT_OFFSETS['PrimitiveTemplate'] = pt_offsets

# ----------------------------------------------------------------
# ScheduledEffect (from common_types.h)
# +0x00: const EffectTemplate *mFx
# +0x04: int mPrimIndex
# +0x08: int mStartTime
# +0x0c: FxBoltInfo mBolt (int dobjHandle + int boneIndex = 8 bytes)
#   +0x0c: mBolt.dobjHandle
#   +0x10: mBolt.boneIndex
# +0x14: vec3_t mOrigin (12 bytes = 0x14..0x1f)
# +0x20: vec3_t mAxis[3] (36 bytes = 0x20..0x43)
# +0x44: int mSeed
# +0x48: int mIndexInBatch
# +0x4c: int mScheduledNext  (but code uses as pointer: *(int*)sfx+0x4c = next ptr)
# ----------------------------------------------------------------
STRUCT_OFFSETS['ScheduledEffect'] = {
    0x00: ('mFx',             'const EffectTemplate *'),
    0x04: ('mPrimIndex',      'int'),
    0x08: ('mStartTime',      'int'),
    0x0c: ('mBolt.dobjHandle','int'),
    0x10: ('mBolt.boneIndex', 'int'),
    0x14: ('mOrigin[0]',      'float'),
    0x18: ('mOrigin[1]',      'float'),
    0x1c: ('mOrigin[2]',      'float'),
    0x20: ('mAxis[0]',        'vec3_t'),
    0x2c: ('mAxis[1]',        'vec3_t'),
    0x38: ('mAxis[2]',        'vec3_t'),
    0x44: ('mSeed',           'int'),
    0x48: ('mIndexInBatch',   'int'),
    0x4c: ('mScheduledNext',  'int'),
}

# ----------------------------------------------------------------
# FxScheduler (from common_types.h)
# +0x00: int mSeed (from code: *(int*)_this+0 = seed)
#   Actually from common_types.h: {ScheduledEffect *mScheduledHead; int mScheduledCount;}
#   But code sets _this+0 = seed and uses _this+4 as linked list pointer...
#   Let me re-read FxScheduler_FxScheduler: sets _this+4=0, _this+8=0
#   And FxScheduler_PlayEffect: sets _this+0 = seed
#   And FxScheduler_Clean: while sfx = *(ScheduledEffect**)(_this+4) != NULL
# So layout is:
#   +0x00: int mSeed (set to random seed)
#   +0x04: ScheduledEffect *mScheduledHead  (linked list head)
#   +0x08: int mScheduledCount
# (common_types.h says mScheduledHead is first but order may differ from actual binary)
# ----------------------------------------------------------------
STRUCT_OFFSETS['FxScheduler'] = {
    0x00: ('mSeed',           'int'),
    0x04: ('mScheduledHead',  'ScheduledEffect *'),
    0x08: ('mScheduledCount', 'int'),
}

# ----------------------------------------------------------------
# FxHelper (from common_types.h)
# +0x00: int time
# +0x04: int mTime
# +0x08: int mOldTime
# +0x0c: int mFrameTime
# +0x10: qboolean mTimeFrozen
# +0x14: struct FxCamera mCamera  (vieworg=vec3_t(12), frustum=vec4_t[6](96), numPlanes=int(4))
#   FxCamera: vieworg(12) + frustum[6](96) + numPlanes(4) = 112 = 0x70 bytes
#   mCamera.vieworg at +0x14
# +0x84: FxCamera mPrevCamera  (same size = 0x70)
# +0xf4: int mSeed
# +0xf8: float adsZoomFactor
# Wait - from FxScheduler_PlayEffect:
#   helper + 0x14 = camera origin
#   helper + 4 = mTime
#   helper + 0xf8 = adsZoomFactor? Or some scale factor
# Let me check FxHelper struct fields from common_types.h line 6085-6095
# Actually FxCamera is: vieworg(12) + frustum(6*16=96) + numPlanes(4) = 112 = 0x70
# So mCamera starts at 0x14 (after time(4)+mTime(4)+mOldTime(4)+mFrameTime(4)+mTimeFrozen(4) = 20 = 0x14)
# mCamera.vieworg at +0x14 (correct!)
# mCamera ends at 0x14 + 0x70 = 0x84
# mPrevCamera at 0x84, ends at 0x84 + 0x70 = 0xf4
# mSeed at 0xf4, adsZoomFactor at 0xf8
# FxScheduler_PlayEffect uses helper + 0x14 for camera vieworg (origin)
# And helper + 0xf8 for culldist scale = adsZoomFactor
# ----------------------------------------------------------------
STRUCT_OFFSETS['FxHelper'] = {
    0x00: ('time',          'int'),
    0x04: ('mTime',         'int'),
    0x08: ('mOldTime',      'int'),
    0x0c: ('mFrameTime',    'int'),
    0x10: ('mTimeFrozen',   'qboolean'),
    0x14: ('mCamera.vieworg[0]', 'float'),
    0x18: ('mCamera.vieworg[1]', 'float'),
    0x1c: ('mCamera.vieworg[2]', 'float'),
    0x20: ('mCamera.frustum',    'vec4_t [6]'),  # 0x20..0x7f
    0x80: ('mCamera.numPlanes',  'int'),
    0x84: ('mPrevCamera.vieworg[0]', 'float'),
    0x88: ('mPrevCamera.vieworg[1]', 'float'),
    0x8c: ('mPrevCamera.vieworg[2]', 'float'),
    0xf4: ('mSeed',         'int'),
    0xf8: ('adsZoomFactor', 'float'),
}

# ----------------------------------------------------------------
# FxGfxEntity (from common_types.h line 7336)
# MaterialHandle customMaterial (4)      -> +0x00
# float rotation (4)                     -> +0x04
# vec3_t axis[3] (36)                    -> +0x08..0x2b
# vec3_t dlightColor (12)                -> +0x2c..0x37
# float materialTime (4)                 -> +0x38
# vec3_t origin (12)                     -> +0x3c..0x47
# float radius[2] (8)                    -> +0x48..0x4f
# byte materialRGBA[4]                   -> +0x50..0x53
# int materialSubimageIndex (4)          -> +0x54
# float scale (4)                        -> +0x58
# vec3_t endpos (12)                     -> +0x5c..0x67
# ----------------------------------------------------------------
STRUCT_OFFSETS['FxGfxEntity'] = {
    0x00: ('customMaterial',         'MaterialHandle'),
    0x04: ('rotation',               'float'),
    0x08: ('axis[0]',                'vec3_t'),
    0x14: ('axis[1]',                'vec3_t'),
    0x20: ('axis[2]',                'vec3_t'),
    0x2c: ('dlightColor',            'vec3_t'),
    0x38: ('materialTime',           'float'),
    0x3c: ('origin[0]',              'float'),
    0x40: ('origin[1]',              'float'),
    0x44: ('origin[2]',              'float'),
    0x48: ('radius[0]',              'float'),
    0x4c: ('radius[1]',              'float'),
    0x50: ('materialRGBA[0]',        'byte'),
    0x51: ('materialRGBA[1]',        'byte'),
    0x52: ('materialRGBA[2]',        'byte'),
    0x53: ('materialRGBA[3]',        'byte'),
    0x54: ('materialSubimageIndex',  'int'),
    0x58: ('scale',                  'float'),
    0x5c: ('endpos[0]',              'float'),
    0x60: ('endpos[1]',              'float'),
    0x64: ('endpos[2]',              'float'),
}

# ----------------------------------------------------------------
# Effect struct (from common_types.h line 7350)
# +0x00: int _vptr$Effect (vtable ptr)
# +0x04: struct FxGfxEntity mRefEnt (size 0x68 = 104 bytes)
#   mRefEnt at +0x04, so mRefEnt.customMaterial at +0x04
#   mRefEnt.rotation at +0x08
#   mRefEnt.axis[0] at +0x0c
#   mRefEnt.dlightColor at +0x30
#   mRefEnt.materialTime at +0x3c
#   mRefEnt.origin at +0x40
#   mRefEnt.radius at +0x4c
#   mRefEnt.materialRGBA at +0x54
#   mRefEnt.materialSubimageIndex at +0x58
#   mRefEnt.scale at +0x5c
#   mRefEnt.endpos at +0x60
# mRefEnt ends at 0x04 + 0x68 = 0x6c
# +0x6c: int mFlags
# +0x70: int mClusterId
# +0x74: int mSortGroup
# +0x78: struct XModel *mModel
# +0x7c: int mTimeStart -> wait, but FX_AddFxToScene shows offset 0x7c is origin
#   In FX_AddFxToScene_impl: effect+0x7c = origin -> but Effect has origin in mRefEnt
#   FxGfxEntity.origin is at offset 0x3c within FxGfxEntity
#   Effect.mRefEnt starts at +0x04
#   So Effect.mRefEnt.origin = +0x04 + 0x3c = +0x40... not 0x7c
# Hmm, that doesn't match. Let me recalculate FxGfxEntity size:
# MaterialHandle(4) + float(4) + vec3_t[3](36) + vec3_t(12) + float(4) + vec3_t(12) + float[2](8) + byte[4](4) + int(4) + float(4) + vec3_t(12) = 4+4+36+12+4+12+8+4+4+4+12 = 104 = 0x68
# Effect: vtable(4) + FxGfxEntity(0x68) + ... so mRefEnt at +0x04
# mRefEnt.customMaterial = Effect+0x04+0x00 = Effect+0x04
# mRefEnt.origin = Effect+0x04+0x3c = Effect+0x40 -> NOT 0x7c
#
# But FX_AddFxToScene_impl uses effect+0x40 for hModel/material and effect+0x7c for origin...
# Effect: vtable(4) + FxGfxEntity(?) ...
#
# Let's look at what the decompiled code says for FX_AddFxToScene_impl:
# effect+0x40 = hModel (material handle)
# effect+0x44 = customShader
# effect+0x48..+0x68 = axis (actually 9 floats * 4 = 36 bytes: 0x48+0x24=0x6c)
# effect+0x7c = origin[0]
# effect+0x80 = origin[1]
# effect+0x84 = origin[2]
# effect+0x88 = radius
# effect+0x8c = rotation
# effect+0x90 = shaderRGBA[0] (byte)
# effect+0x93 = shaderRGBA[3] (byte)
# effect+0x94 = shaderTexCoord
# effect+0x98 = frame
# effect+0x9c = oldorigin[0]
# effect+0xa8 = flags
# effect+0xb4 = sortGroup
#
# These match FxGfxEntity if we recompute:
# customMaterial(4)+rotation(4)+axis[3](36)+dlightColor(12)+materialTime(4)+origin(12)+...
# rotation(4)=+0x04, axis[0..2](36)=+0x08..+0x2b, dlightColor(12)=+0x2c..+0x37, materialTime(4)=+0x38
# origin(12)=+0x3c
# If Effect._vptr = 4, then mRefEnt starts at +4:
# mRefEnt.customMaterial = +4+0 = +4 but code shows +0x40... not matching
#
# I think Effect has a larger vtable or different layout. Let me count from code:
# effect+0x40 = customMaterial (MaterialHandle)
# effect+0x44 = customShader? -> but customShader is not in FxGfxEntity...
# Actually wait: from the COMMENT: "ent.hModel (material)" and "ent.customShader"
# The 'ent' here is a GfxEntity, not a FxGfxEntity!
# And 'effect' is the Effect object being QUERIED - its fields are read.
#
# So the layout of Effect/the drawn thing in the effect list:
# effect+0x40 = MaterialHandle (== FxGfxEntity.customMaterial if mRefEnt is at +0x40)
# effect+0x44 = some shader field
# effect+0x48..+0x6b = axis[3]
# effect+0x6c = ???
# effect+0x7c = origin[0]
# ...
#
# If mRefEnt starts at +0x40:
#   mRefEnt.customMaterial = +0x40 ✓
#   mRefEnt.rotation = +0x44 -> but +0x44 is labeled "customShader"?
#   Hmm. Maybe FxGfxEntity has a different layout:
#   MaterialHandle customMaterial (4) -> +0x40
#   float rotation (4) -> +0x44... but comment says "ent.customShader"
#   This doesn't match.
#
# Let me re-examine. The ent fields in FX_AddFxToScene_impl map to GfxEntity, not to FxGfxEntity.
# The EFFECT fields (source) are:
#   effect+0x40 = material handle (read into ent.hModel)
#   effect+0x44 = another handle (read into ent.customShader)
#   effect+0x48..0x6b = axis (copied to ent.axis)
#   effect+0x7c..0x84 = origin vec3
#   effect+0x88 = radius
#   effect+0x8c = rotation (note: radius[2] in FxGfxEntity vs radius scalar)
#   effect+0x90..0x93 = materialRGBA[4]
#   effect+0x94 = materialSubimageIndex (or texcoord)
#   effect+0x98 = materialTime (frame)
#   effect+0x9c..0xa4 = endpos/oldorigin
#   effect+0xa8 = flags
#   effect+0xb4 = sortGroup
#
# FxGfxEntity layout at +0x40 (mRefEnt at +0x40):
#   +0x40: customMaterial (4)
#   +0x44: rotation (4) -> but "customShader"? No, "rotation" -> this doesn't match "customShader"
#
# OK I think the issue is: there are TWO material fields in FxGfxEntity differently named,
# OR the layout I computed is wrong. Let me try:
#   +0x40: customMaterial (4) -> read as hModel
#   +0x44: ??? -> read as customShader (second material?)
# Maybe FxGfxEntity has two material handles? Let me look at the code again more carefully.
# The ent.hModel is the material for rendering, ent.customShader is usually another material.
# In FxGfxEntity there's only one MaterialHandle. So maybe effect has extra fields.
#
# Alternative: Effect's _vptr is NOT 4 bytes? On Mac, vtable ptr is 4 bytes.
# Let's try: Effect starts with a larger structure.
# Actually, from the code Particle_Draw reads from 'p' at 0x88 and 0x8c (radius, height).
# And Particle is a class deriving from something (it has channels at 0x00).
# Actually Particle in common_types.h just has FxChannelInstance fields.
# There's no base class pointer. But when drawn, the Effect base class provides the rendering data.
#
# I think the actual structure used as an effect object is NOT exactly 'struct Effect' from common_types.h.
# The code treats a large opaque blob as the "effect" object. Let me just build the offset table
# from the code patterns directly, without trying to name them from the struct.
# ----------------------------------------------------------------

# Effect (the actual rendered object - layout derived from FX_AddFxToScene_impl + draw functions)
# From Particle_Draw, Emitter_Draw, etc., they all use the same base object:
# The FxGfxEntity fields are embedded.
# From Particle_AddVisibility: p+0x7c=origin[0], p+0x80=origin[1], p+0x84=origin[2],
#   p+0x88=radius, p+0x93=materialRGBA[3]
# From FX_AddFxToScene_impl effect+0x7c=origin...
# Let's assume FxGfxEntity is embedded starting at offset 0x3c from start:
# Then FxGfxEntity.customMaterial at effect+0x3c+0 = effect+0x3c... but code shows 0x40
# Let me try FxGfxEntity starts at +0x40:
#   +0x40: customMaterial (MaterialHandle = pointer = 4)
#   +0x44: rotation (float = 4)  -> aha: maybe this IS the second material?
#   No... Let me look at the raw access:
#   *(int *)(effect + 0x40) read as hModel (material index/handle)
#   *(int *)(effect + 0x44) read as customShader (another handle)
# In GfxEntity: hModel is NOT a field, and the ent is a local stack var with fields by offset...
# Actually the target ent is a GfxEntity-like struct. The SOURCE is an Effect's FxGfxEntity.
#
# I'll just enumerate the known offsets from the code:
STRUCT_OFFSETS['EffectObj'] = {
    # Used in FX_AddFxToScene_impl, Particle_Draw, Flash_Init, Emitter_Draw
    # "effect" or "p" variable pointing to the effect object
    0x04: ('origin[0]',         'float'),   # Flash_Init uses p+4,8,c as origin
    0x08: ('origin[1]',         'float'),
    0x0c: ('origin[2]',         'float'),
    0x40: ('customMaterial',    'MaterialHandle'),
    0x44: ('customShader',      'MaterialHandle'),
    0x48: ('axis[0]',           'vec3_t'),
    0x54: ('axis[1]',           'vec3_t'),
    0x60: ('axis[2]',           'vec3_t'),
    0x6c: ('dlightColor',       'vec3_t'),
    0x78: ('materialTime',      'float'),
    0x7c: ('mOrigin[0]',        'float'),
    0x80: ('mOrigin[1]',        'float'),
    0x84: ('mOrigin[2]',        'float'),
    0x88: ('radius[0]',         'float'),
    0x8c: ('radius[1]',         'float'),   # used as "rotation" or height
    0x90: ('materialRGBA[0]',   'byte'),
    0x91: ('materialRGBA[1]',   'byte'),
    0x92: ('materialRGBA[2]',   'byte'),
    0x93: ('materialRGBA[3]',   'byte'),
    0x94: ('materialSubimageIndex', 'int'),
    0x98: ('materialTime2',     'float'),
    0x9c: ('endpos[0]',         'float'),
    0xa0: ('endpos[1]',         'float'),
    0xa4: ('endpos[2]',         'float'),
    0xa8: ('mFlags',            'int'),
    0xac: ('mClusterId',        'int'),
    0xa9: ('mFlags_b1',         'byte'),    # byte access to mFlags+1
    0xb0: ('mSortGroup_or_B0',  'int'),
    0xb4: ('mSortGroup',        'int'),
    0xb8: ('mTimeStart',        'int'),
    0xbc: ('mTimeEnd',          'int'),
    0xd4: ('flashIntensity',    'float'),
}

# ----------------------------------------------------------------
# GenericParser2 layout (from code in GenericParser2.c line 882+)
# +0x00: const char *name  (set to "Top Level")
# +0x04: int _04
# +0x08: int _08
# +0x0c: int _0c
# GPGroup layout (from GPGroup_Clean):
# +0x10: GPValue *pairs (first pair)
# +0x14: GPValue *pairsLast
# +0x18: GPValue *pairsEnd? (set to 0 in clean)
# +0x1c: GPValue *subgroups (first subgroup)
# +0x20: GPValue *subgroupsLast
# +0x24: GPValue *subgroupsEnd? (set to 0 in clean)
# +0x28: TextPool *textPool
# +0x2c: byte _2c (set to 0)
# GPValue layout (from code):
# +0x00: const char *value string
# +0x04: GPValue *next (next in list)
# +0x08: GPObject *nextSorted
# +0x0c: GPObject *prevSorted
# +0x10: GPValue *list (list of values)
# GPObject layout (assumed similar to GPGroup):
# +0x00: const char *name
# +0x04: GPObject *next (unsorted)
# +0x08: GPObject *nextSorted
# +0x0c: GPObject *prevSorted
# ----------------------------------------------------------------
STRUCT_OFFSETS['GPGroup'] = {
    0x00: ('name',          'const char *'),
    0x04: ('next',          'GPObject *'),
    0x08: ('nextSorted',    'GPObject *'),
    0x0c: ('prevSorted',    'GPObject *'),
    0x10: ('pairs',         'GPValue *'),
    0x14: ('pairsLast',     'GPValue *'),
    0x18: ('pairsEnd',      'GPValue *'),
    0x1c: ('subgroups',     'GPGroup *'),
    0x20: ('subgroupsLast', 'GPGroup *'),
    0x24: ('subgroupsEnd',  'GPGroup *'),
    0x28: ('textPool',      'TextPool *'),
    0x2c: ('_flags',        'byte'),
}

STRUCT_OFFSETS['GenericParser2'] = {
    0x00: ('name',       'const char *'),
    0x04: ('_04',        'int'),
    0x08: ('_08',        'int'),
    0x0c: ('_0c',        'int'),
    0x10: ('pairs',      'GPValue *'),
    0x14: ('pairsLast',  'GPValue *'),
    0x18: ('pairsEnd',   'GPValue *'),
    0x1c: ('subgroups',  'GPGroup *'),  # top-level group list
    0x20: ('subgroupsLast', 'GPGroup *'),
    0x24: ('subgroupsEnd',  'GPGroup *'),
    0x28: ('textPool',   'TextPool *'),
    0x2c: ('_flags',     'byte'),
}

STRUCT_OFFSETS['GPValue'] = {
    0x00: ('value',       'const char *'),
    0x04: ('next',        'GPValue *'),
    0x08: ('nextSorted',  'GPValue *'),
    0x0c: ('prevSorted',  'GPValue *'),
    0x10: ('list',        'GPValue *'),
}

STRUCT_OFFSETS['GPObject'] = {
    0x00: ('name',        'const char *'),
    0x04: ('next',        'GPObject *'),
    0x08: ('nextSorted',  'GPObject *'),
    0x0c: ('prevSorted',  'GPObject *'),
}

# ----------------------------------------------------------------
# FxBoltFrame layout (from FxPrimitives.c code)
# +0x00: int refCount
# +0x04: int mTime (cached time)
# +0x08: orientation_t mOrient (=FxBoltFrame_GetOrientation returns p+8)
#   orientation_t: vec3_t origin(12) + vec3_t axis[3](36) = 48 bytes
#   +0x08: orient.origin
#   +0x14: orient.axis[0]
#   +0x20: orient.axis[1]
#   +0x2c: orient.axis[2]
# +0x38: FxBoltFrame *mNext (linked list next)
# +0x3c: FxBoltInfo mBolt
#   +0x3c: mBolt.dobjHandle
#   +0x40: mBolt.boneIndex
# ----------------------------------------------------------------
STRUCT_OFFSETS['FxBoltFrame'] = {
    0x00: ('refCount',          'int'),
    0x04: ('mTime',             'int'),
    0x08: ('mOrient.origin',    'vec3_t'),
    0x0c: ('mOrient.origin[0]', 'float'),
    0x10: ('mOrient.origin[1]', 'float'),
    0x14: ('mOrient.axis[0]',   'vec3_t'),
    0x20: ('mOrient.axis[1]',   'vec3_t'),
    0x2c: ('mOrient.axis[2]',   'vec3_t'),
    0x38: ('mNext',             'FxBoltFrame *'),
    0x3c: ('mBolt.dobjHandle',  'int'),
    0x40: ('mBolt.boneIndex',   'int'),
}

# ----------------------------------------------------------------
# TMediaList / MediaHandles layout (from MediaHandles_Shutdown/AddHandle)
# +0x00: void *elements (pointer to array)
# +0x04: unsigned short count
# +0x06: unsigned short capacity
# ----------------------------------------------------------------
STRUCT_OFFSETS['MediaHandles'] = {
    0x00: ('mMediaList.elements',  'void *'),
    0x04: ('mMediaList.count',     'unsigned short'),
    0x06: ('mMediaList.capacity',  'unsigned short'),
}

# ----------------------------------------------------------------
# EffectCluster (from common_types.h)
# +0x00: vec3_t origin (12 bytes)
# +0x0c: int refCount
# ----------------------------------------------------------------
STRUCT_OFFSETS['EffectCluster'] = {
    0x00: ('origin[0]', 'float'),
    0x04: ('origin[1]', 'float'),
    0x08: ('origin[2]', 'float'),
    0x0c: ('refCount',  'int'),
}

# ----------------------------------------------------------------
# FxBoltInfo (from common_types.h)
# +0x00: int dobjHandle
# +0x04: int boneIndex
# ----------------------------------------------------------------
STRUCT_OFFSETS['FxBoltInfo'] = {
    0x00: ('dobjHandle', 'int'),
    0x04: ('boneIndex',  'int'),
}

# ----------------------------------------------------------------
# MemoryFile layout (used by FxArchive_BeginReading)
# +0x08: current position or data offset  (from: *(int*)(memFile + 8) -> startPos)
# ----------------------------------------------------------------
STRUCT_OFFSETS['MemoryFile'] = {
    0x08: ('position', 'int'),
}

# ================================================================
# Variable-name to struct type hints
# Maps variable name patterns to struct names
# ================================================================
VAR_TO_STRUCT = {
    # FxArchive
    '_this': None,  # depends on context - handled per file
    'arch': 'FxArchive',
    # EffectTemplate / PrimitiveTemplate
    'fx': 'EffectTemplate',
    'effect': 'EffectTemplate',
    'prim': 'PrimitiveTemplate',
    'primTemp': 'PrimitiveTemplate',
    'pt': 'PrimitiveTemplate',
    't': 'PrimitiveTemplate',  # in FxTemplate.c
    # ScheduledEffect
    'sfx': 'ScheduledEffect',
    'scheduled': 'ScheduledEffect',
    # FxScheduler
    # 'self': handled per context
    # FxHelper / helper
    'helper': 'FxHelper',
    # Effect objects (drawn objects)
    'p': 'EffectObj',  # generic effect object pointer
    'eff': 'EffectObj',
    # FxBoltFrame
    'boltFrame': 'FxBoltFrame',
    'cur': 'FxBoltFrame',
    # Bolt info
    'bolt': 'FxBoltInfo',
    # Cluster
    'cluster': 'EffectCluster',
    'newCluster': 'EffectCluster',
    # GPGroup / GPValue
    'grp': 'GPGroup',
    'pair': 'GPValue',
    # MediaHandles
    # 'self': 'MediaHandles',  # handled per context
}

# ================================================================
# Pattern matching and replacement
# ================================================================

# Pattern: *(type *)((byte *)varname + 0xNN)  or  *(type *)(varname + 0xNN)
# Also handles: *(type *)((byte *)_this + N) etc.
OFFSET_PATTERN = re.compile(
    r'\*\s*\(\s*([^()]+?\*)\s*\)\s*\(\s*(?:\(byte \*\))?\s*(\w+)\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)'
)

def get_offset(off_str):
    """Convert offset string to int."""
    off_str = off_str.strip()
    if off_str.startswith('0x') or off_str.startswith('0X'):
        return int(off_str, 16)
    return int(off_str)

def make_field_access(var, field, cast_type, is_write=False):
    """Generate field access expression."""
    if '[' in field:
        # Array access: var->arr[i] or for sub-struct: var->sub.arr[i]
        return f'{var}->{field}'
    elif '.' in field:
        return f'{var}->{field}'
    else:
        return f'{var}->{field}'

def convert_line(line, struct_hints=None):
    """Convert a single line, replacing offset patterns with field accesses."""
    if struct_hints is None:
        struct_hints = {}

    # Don't touch macro definitions or comments
    stripped = line.strip()
    if stripped.startswith('#define') or stripped.startswith('//') or stripped.startswith('*'):
        return line, 0

    count = 0
    result = line

    # Find all patterns
    matches = list(OFFSET_PATTERN.finditer(result))
    if not matches:
        return line, 0

    # Process in reverse to preserve positions
    for m in reversed(matches):
        cast_type = m.group(1).strip()
        var = m.group(2).strip()
        off_str = m.group(3).strip()
        offset = get_offset(off_str)

        # Determine struct type
        struct_name = struct_hints.get(var)
        if struct_name is None:
            struct_name = VAR_TO_STRUCT.get(var)

        if struct_name is None:
            continue

        offsets = STRUCT_OFFSETS.get(struct_name)
        if offsets is None:
            continue

        field_info = offsets.get(offset)
        if field_info is None:
            continue

        field_name, field_type = field_info

        # Generate replacement
        new_expr = f'({var}->{field_name})'
        result = result[:m.start()] + new_expr + result[m.end():]
        count += 1

    return result, count


def process_file(filepath, struct_hints=None):
    """Process a file, converting offset patterns to field accesses."""
    if struct_hints is None:
        struct_hints = {}

    with open(filepath, 'r', errors='replace') as f:
        lines = f.readlines()

    new_lines = []
    total = 0
    for i, line in enumerate(lines):
        new_line, cnt = convert_line(line, struct_hints)
        new_lines.append(new_line)
        total += cnt

    if total > 0:
        with open(filepath, 'w', errors='replace') as f:
            f.writelines(new_lines)
        print(f"  {filepath}: {total} conversions")
    else:
        print(f"  {filepath}: no changes")

    return total


# ================================================================
# File-specific struct hints (var_name -> struct_name)
# These override the global VAR_TO_STRUCT for specific files
# ================================================================

FILE_HINTS = {
    'FxArchive.c': {
        '_this': 'FxArchive',
        'memFile': 'MemoryFile',
    },
    'FxScheduler_load_obj.c': {
        'fx': 'EffectTemplate',
        'effect': 'EffectTemplate',
        'prim': 'PrimitiveTemplate',
        'parser': 'GenericParser2',
        'primitiveGroup': 'GPGroup',
    },
    'FxScheduler.c': {
        '_this': 'FxScheduler',
        'self': 'FxScheduler',
        'fx': 'EffectTemplate',
        'prim': 'PrimitiveTemplate',
        'primTemp': 'PrimitiveTemplate',
        'sfx': 'ScheduledEffect',
        'helper': 'FxHelper',
        'bolt': 'FxBoltInfo',
    },
    'FxUtil.c': {
        'fx': 'EffectObj',
        'fx0': 'EffectObj',
        'fx1': 'EffectObj',
        'cluster': 'EffectCluster',
        'newCluster': 'EffectCluster',
        'pt': 'PrimitiveTemplate',
        'primTemp': 'PrimitiveTemplate',
        'particle': 'EffectObj',
        'scheduled': 'ScheduledEffect',
        'eff': 'EffectObj',
    },
    'FxPrimitives.c': {
        'p': 'EffectObj',
        'effect': 'EffectObj',
        'boltFrame': 'FxBoltFrame',
        '_this': 'EffectObj',
    },
    'FxTemplate.c': {
        't': 'PrimitiveTemplate',
        '_this': 'PrimitiveTemplate',
        'thisPtr': 'PrimitiveTemplate',
    },
    'GenericParser2.c': {
        '_this': 'GPGroup',
        'self': 'GPGroup',
        'pair': 'GPValue',
        'test': 'GPObject',
        'obj': 'GPObject',
        'last': 'GPObject',
        'subGroup': 'GPGroup',
        'object': 'GPObject',
        'parser': 'GenericParser2',
    },
}


if __name__ == '__main__':
    import os

    base = '/home/user/work/output/PC/EffectsCore'
    files = [
        'FxPrimitives.c',
        'FxUtil.c',
        'FxTemplate.c',
        'GenericParser2.c',
        'FxScheduler.c',
        'FxArchive.c',
        'FxScheduler_load_obj.c',
    ]

    total = 0
    for fname in files:
        fpath = os.path.join(base, fname)
        hints = dict(VAR_TO_STRUCT)
        hints.update(FILE_HINTS.get(fname, {}))
        n = process_file(fpath, hints)
        total += n

    print(f"\nTotal: {total} conversions")
