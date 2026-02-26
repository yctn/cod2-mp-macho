/* ASM dump from: xanim_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/xanim_load_obj.cpp */

#include "common_types.h"
#include "imports.h"
extern float floorf(float x);
extern float sqrtf(float x);
extern void *memcpy(void *dest, const void *src, unsigned int n);
extern unsigned int strlen(const char *s);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/consumedata.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

extern int Com_sprintf(char *dest, int size, const char *fmt, ...);
extern int FS_ReadFile(const char *path, void **buffer);
extern void FS_FreeFile(void *buffer);
extern void Com_Printf(const char *fmt, ...);
extern unsigned int SL_GetString_(const char *str, unsigned int user, int type);
extern unsigned int SL_GetStringOfLen(const char *str, unsigned int user, unsigned int len, int type);

XAnimParts * XAnimLoadFile(const char *name, Alloc_t Alloc);

/* Helper: read a short from the data stream and advance pos */
static short int ConsumeShort(const char **pos)
{
    short int val = *(short int *)(*pos);
    *pos += 2;
    return val;
}

/* Helper: read an unsigned short from the data stream and advance pos */
static unsigned short int ConsumeUShort(const char **pos)
{
    unsigned short int val = *(unsigned short int *)(*pos);
    *pos += 2;
    return val;
}

/* Helper: read a 4-byte int from the data stream and advance pos */
static int ConsumeInt(const char **pos)
{
    int val = *(int *)(*pos);
    *pos += 4;
    return val;
}

/* Helper: read a single byte from the data stream and advance pos */
static unsigned char ConsumeByte(const char **pos)
{
    unsigned char val = *(unsigned char *)(*pos);
    *pos += 1;
    return val;
}

/* Helper: compute the sqrt component for quaternion reconstruction */
static short int QuatSqrt(int remainder)
{
    if (remainder > 0) {
        return (short int)floorf(sqrtf((float)remainder) + 0.5f);
    }
    return 0;
}

/* line 15 */
/* ConsumeQuat: reads 3 short components from data stream, computes 4th.
 * Original calling convention was regparm (eax=pos, edx=out).
 * Now a normal C function. */
static void ConsumeQuat_C(const char **pos, short int *out)
{
    short int a, b, c;
    int sum, remainder;

    a = ConsumeShort(pos);
    out[0] = a;

    b = ConsumeShort(pos);
    out[1] = b;

    c = ConsumeShort(pos);
    out[2] = c;

    sum = (int)a * (int)a + (int)b * (int)b + (int)c * (int)c;
    remainder = 0x3fff0001 - sum;
    out[3] = QuatSqrt(remainder);
}

/* Helper: compute 2-component quat from stream (for simpleQuat case) */
static void ConsumeQuat2(const char **pos, short int *out)
{
    short int a;
    int remainder;

    a = ConsumeShort(pos);
    out[0] = a;

    remainder = 0x3fff0001 - (int)a * (int)a;
    out[1] = QuatSqrt(remainder);
}

/* line 90 */
XAnimParts * XAnimLoadFile(const char *name, Alloc_t Alloc)
{
    char filename[64];
    void *buf;
    const char *pos;
    XAnimParts *parts;
    XAnimDeltaPart *deltaPart;
    short int quat[4];
    unsigned short int numBoneCount;
    unsigned short int numloopframes;
    unsigned short int numQuatIndices;
    int numNoteTracks;
    short int version;
    unsigned short int *boneNames;
    const char *flipQuatBits;
    char *simpleQuatBits;
    Bool bSmallIndices;
    Bool bLoop;
    Bool bDelta;
    short int sQ2;
    int i;

    /* line 125 */
    if (Com_sprintf(filename, 64, "xanim/%s", name) < 0) {
        /* line 127 */
        Com_Printf("^1ERROR: filename '%s' too long\n", filename);
        return (XAnimParts *)0;
    }

    /* line 131 */
    {
        int fileLen = FS_ReadFile(filename, &buf);
        if (fileLen < 0) {
            /* line 136 */
            Com_Printf("^1ERROR: xanim '%s' not found\n", name);
            return (XAnimParts *)0;
        }
        if (fileLen == 0) {
            /* line 142 */
            Com_Printf("^1ERROR: xanim '%s' has 0 length\n", name);
            FS_FreeFile(buf);
            return (XAnimParts *)0;
        }
    }

    /* line 149 */
    pos = (const char *)buf;

    /* Read version */
    version = ConsumeShort(&pos);

    /* line 151 */
    if (version != 14) {
        /* line 153-154 */
        FS_FreeFile(buf);
        Com_Printf("^1ERROR: xanim '%s' out of date (version %d, expecting %d)\n", name, (int)version, 14);
        return (XAnimParts *)0;
    }

    /* Read notify count and bone count */
    numNoteTracks = (unsigned short int)ConsumeUShort(&pos);
    numBoneCount = ConsumeUShort(&pos);
    sQ2 = (short int)numBoneCount;

    /* line 161 - read bone names if numBoneCount != 0 */
    if (numBoneCount != 0) {
        boneNames = (unsigned short int *)Alloc(numBoneCount * 2);
    } else {
        boneNames = (unsigned short int *)0;
    }

    /* line 163 - read flags byte */
    {
        unsigned char flags = ConsumeByte(&pos);
        bLoop = (Bool)(flags & 1);
        bDelta = (Bool)((flags >> 1) & 1);
    }

    /* line 168 - read framerate */
    sQ2 = ConsumeShort(&pos);

    /* line 170 - allocate XAnimParts (0x2c = 44 bytes) */
    parts = (XAnimParts *)Alloc(0x2c);

    /* line 173 */
    parts->boneCount = (short int)numBoneCount;
    /* line 174 */
    parts->names = boneNames;
    /* line 175 */
    parts->framerate = (float)sQ2;
    /* line 176 */
    parts->bLoop = bLoop;
    /* line 177 */
    parts->bDelta = bDelta;

    /* line 180 */
    if (bLoop) {
        numloopframes = (unsigned short int)(numNoteTracks + 1);
    } else {
        numloopframes = (unsigned short int)numNoteTracks;
    }

    /* line 181 */
    bSmallIndices = (numloopframes <= 0x100) ? 1 : 0;

    /* line 182 */
    parts->numframes = (unsigned short int)(numloopframes - 1);

    /* line 183 */
    if (parts->numframes != 0) {
        parts->frequency = parts->framerate / (float)(unsigned short int)parts->numframes;
    } else {
        parts->frequency = 0.0f;
    }

    /* line 187 */
    if (bDelta) {
        /* line 189 */
        deltaPart = (XAnimDeltaPart *)Alloc(8);
        parts->deltaPart = deltaPart;

        /* line 191 - read delta quat frame count */
        sQ2 = (short int)ConsumeUShort(&pos);

        if (sQ2 == 0) {
            /* line 195 */
            deltaPart->quat = (XAnimDeltaPartQuat *)0;
        } else if (sQ2 == 1) {
            /* Single frame delta quat */
            short int dq0;
            int rem;

            dq0 = ConsumeShort(&pos);
            quat[0] = dq0;
            rem = 0x3fff0001 - (int)dq0 * (int)dq0;
            quat[1] = QuatSqrt(rem);

            /* line 201 */
            deltaPart->quat = (XAnimDeltaPartQuat *)Alloc(8);
            deltaPart->quat->size = 0;
            /* line 203 */
            deltaPart->quat->u.frame0[0] = quat[0];
            /* line 204 */
            deltaPart->quat->u.frame0[1] = quat[1];
        } else {
            int numFrames;
            if (sQ2 <= (short int)numloopframes) {
                /* numFrames == numloopframes: no index table needed */
                deltaPart->quat = (XAnimDeltaPartQuat *)Alloc(8);
                numFrames = (int)(unsigned short int)sQ2;
            } else if (bSmallIndices) {
                /* line 296 - small indices */
                numFrames = (int)(unsigned short int)sQ2;
                deltaPart->quat = (XAnimDeltaPartQuat *)Alloc(14 + 2 * numFrames);
                /* line 302 */
                memcpy(((char *)deltaPart->quat) + 8, pos, numFrames);
                pos += numFrames;
            } else {
                /* line 308-309 - large indices */
                numFrames = (int)(unsigned short int)sQ2;
                {
                    int idxBytes = numFrames * 2;
                    deltaPart->quat = (XAnimDeltaPartQuat *)Alloc(14 + idxBytes);
                    /* line 315 */
                    memcpy(((char *)deltaPart->quat) + 8, pos, idxBytes);
                    pos += idxBytes;
                }
            }

            /* line 329-330 */
            deltaPart->quat->size = (unsigned short int)(sQ2 - 1);
            deltaPart->quat->u.frames.frames = (XQuat2 *)Alloc(numFrames * 12);

            /* line 332 - read delta quat frames (3 floats each as ints) */
            {
                int k;
                for (k = 0; k < numFrames; k++) {
                    int val0, val1, val2;
                    char *frameBase = (char *)deltaPart->quat->u.frames.frames + k * 12;
                    val0 = ConsumeInt(&pos);
                    *(int *)(frameBase + 0) = val0;
                    val1 = ConsumeInt(&pos);
                    *(int *)(frameBase + 4) = val1;
                    val2 = ConsumeInt(&pos);
                    *(int *)(frameBase + 8) = val2;
                }
            }
        }

        /* Now read delta trans */
        sQ2 = (short int)ConsumeUShort(&pos);

        if (sQ2 == 0) {
            /* line 275 */
            deltaPart->trans = (XAnimDeltaPartTrans *)0;
        } else if (sQ2 == 1) {
            /* Single frame delta trans - read 3 ints (vec3_t as ints) */
            int v0, v1, v2;
            const char *base = pos;
            v0 = *(int *)(base);
            pos += 4;
            v1 = *(int *)(pos);
            pos += 4;
            v2 = *(int *)(pos);
            pos += 4;

            /* line 283 */
            deltaPart->trans = (XAnimDeltaPartTrans *)Alloc(16);
            deltaPart->trans->size = 0;
            /* Store as raw ints into the frame0 union */
            {
                int *to = (int *)&deltaPart->trans->u.frame0[0];
                to[0] = v0;
                to[1] = v1;
                to[2] = v2;
            }
        } else {
            int numFrames;
            if (sQ2 <= (short int)numloopframes) {
                /* No index table */
                deltaPart->trans = (XAnimDeltaPartTrans *)Alloc(8);
                numFrames = (int)(unsigned short int)sQ2;
            } else if (bSmallIndices) {
                /* small indices */
                numFrames = (int)(unsigned short int)sQ2;
                deltaPart->trans = (XAnimDeltaPartTrans *)Alloc(10 + 2 * numFrames);
                memcpy(((char *)deltaPart->trans) + 8, pos, numFrames);
                pos += numFrames;
            } else {
                /* large indices */
                numFrames = (int)(unsigned short int)sQ2;
                {
                    int idxBytes = numFrames * 2;
                    deltaPart->trans = (XAnimDeltaPartTrans *)Alloc(10 + idxBytes);
                    memcpy(((char *)deltaPart->trans) + 8, pos, idxBytes);
                    pos += idxBytes;
                }
            }

            /* line 248-249 */
            deltaPart->trans->size = (unsigned short int)(sQ2 - 1);
            deltaPart->trans->u.frames.frames = (vec3_t *)Alloc(numFrames * 4);

            /* line 251 - read delta trans frames and do sign fixup */
            {
                int k;
                for (k = 0; k < numFrames; k++) {
                    short int v0, v1;
                    short int *framePtr;
                    v0 = ConsumeShort(&pos);
                    framePtr = (short int *)((char *)deltaPart->trans->u.frames.frames + k * 4);
                    framePtr[0] = v0;
                    v1 = QuatSqrt(0x3fff0001 - (int)v0 * (int)v0);
                    framePtr[1] = v1;
                }
            }

            /* Sign fixup loop for delta trans (line 258) */
            {
                int k;
                for (k = 1; k < numFrames; k++) {
                    short int *cur = (short int *)((char *)deltaPart->trans->u.frames.frames + k * 4);
                    short int *prev = (short int *)((char *)deltaPart->trans->u.frames.frames + (k - 1) * 4);
                    int dot = (int)cur[0] * (int)prev[0] + (int)cur[1] * (int)prev[1];
                    if (dot < 0) {
                        cur[0] = -cur[0];
                        cur[1] = -cur[1];
                    }
                }
            }
        }
    }

    /* line 341 - process bone quats and trans */
    if (numBoneCount != 0) {
        int flipSize = (int)(short int)numBoneCount - 1;
        flipSize = (flipSize >> 3) + 1;

        /* line 344 */
        flipQuatBits = pos;
        pos += flipSize;

        /* line 346 */
        simpleQuatBits = (char *)Alloc(flipSize);

        /* line 347 */
        memcpy(simpleQuatBits, pos, flipSize);
        pos += flipSize;

        /* line 350 */
        parts->simpleQuatBits = simpleQuatBits;

        /* line 351 */
        parts->parts = (XAnimPart *)Alloc((int)(short int)numBoneCount * 8);
    } else {
        flipQuatBits = (const char *)0;
        simpleQuatBits = (char *)0;
    }

    /* line 359 - read bone names */
    if ((int)(short int)numBoneCount > 0) {
        const char *namePos;
        int j;
        namePos = pos;
        for (j = 0; j < (int)(short int)numBoneCount; j++) {
            int slen;
            if (j > 0) {
                namePos = pos;
            }
            slen = strlen(namePos) + 1;
            boneNames[j] = (unsigned short int)SL_GetStringOfLen(namePos, 0, slen, 9);
            pos = namePos + slen;
            namePos = pos;
        }

        /* line 366-368 - process each bone */
        for (i = 0; i < (int)(short int)numBoneCount; i++) {
            Bool flipQuat;
            Bool isSimpleQuat;
            XAnimPart *part;
            XAnimPartQuat *partQuatAlloc;
            int numQFrames;

            /* Read flip/simple quat bits */
            flipQuat = (flipQuatBits[i >> 3] >> (i & 7)) & 1;
            isSimpleQuat = (simpleQuatBits[i >> 3] >> (i & 7)) & 1;

            /* line 371 */
            part = &parts->parts[i];

            /* Read numQuatIndices */
            numQuatIndices = ConsumeUShort(&pos);

            /* line 374 */
            if (numQuatIndices == 0) {
                /* line 377 */
                part->quat = (XAnimPartQuat *)0;
            } else if (numQuatIndices == 1) {
                /* line 381 */
                if (isSimpleQuat) {
                    /* 2-component quat */
                    short int dq0;
                    int rem;

                    dq0 = ConsumeShort(&pos);
                    quat[0] = dq0;
                    rem = 0x3fff0001 - (int)dq0 * (int)dq0;
                    quat[1] = QuatSqrt(rem);

                    /* line 385 */
                    if (flipQuat) {
                        quat[0] = -quat[0];
                        quat[1] = -quat[1];
                    }

                    /* line 391 */
                    partQuatAlloc = (XAnimPartQuat *)Alloc(8);
                    part->quat = partQuatAlloc;
                    /* line 392-393 */
                    partQuatAlloc->u.frame02[0] = quat[0];
                    partQuatAlloc->u.frame02[1] = quat[1];
                } else {
                    /* 4-component quat */
                    ConsumeQuat_C(&pos, quat);

                    /* line 399 */
                    if (flipQuat) {
                        quat[0] = -quat[0];
                        quat[1] = -quat[1];
                        quat[2] = -quat[2];
                        quat[3] = -quat[3];
                    }

                    /* line 407 */
                    partQuatAlloc = (XAnimPartQuat *)Alloc(12);
                    part->quat = partQuatAlloc;
                    /* line 408-411 */
                    partQuatAlloc->u.frame0[0] = quat[0];
                    partQuatAlloc->u.frame0[1] = quat[1];
                    partQuatAlloc->u.frame0[2] = quat[2];
                    partQuatAlloc->u.frame0[3] = quat[3];
                }

                /* line 414 */
                part->quat->size = 0;
            } else {
                /* Multiple frames */
                numQFrames = (int)numQuatIndices;

                if (numQuatIndices <= numloopframes) {
                    /* No index table needed */
                    if (isSimpleQuat) {
                        part->quat = (XAnimPartQuat *)Alloc(8);
                    } else {
                        part->quat = (XAnimPartQuat *)Alloc(8);
                    }
                    numQFrames = (int)numQuatIndices;
                } else if (bSmallIndices) {
                    if (isSimpleQuat) {
                        /* line 425-426 */
                        part->quat = (XAnimPartQuat *)Alloc(10 + 2 * numQFrames);
                        memcpy(((char *)part->quat) + 8, pos, numQFrames);
                        pos += numQFrames;
                    } else {
                        /* line 437-438 */
                        int idxBytes = numQFrames * 2;
                        part->quat = (XAnimPartQuat *)Alloc(10 + idxBytes);
                        memcpy(((char *)part->quat) + 8, pos, idxBytes);
                        pos += idxBytes;
                    }
                } else {
                    if (isSimpleQuat) {
                        /* line 437-438 large indices for simple quat */
                        int idxBytes = numQFrames * 2;
                        part->quat = (XAnimPartQuat *)Alloc(10 + idxBytes);
                        memcpy(((char *)part->quat) + 8, pos, idxBytes);
                        pos += idxBytes;
                    } else {
                        /* line 437-438 large indices for full quat */
                        int idxBytes = numQFrames * 2;
                        part->quat = (XAnimPartQuat *)Alloc(10 + idxBytes);
                        memcpy(((char *)part->quat) + 8, pos, idxBytes);
                        pos += idxBytes;
                    }
                }

                if (isSimpleQuat) {
                    /* Simple quat frames (2 components each) */

                    /* Allocate frames: 4 bytes per frame (XQuat2) */
                    part->quat->u.frames.u.frames2 = (XQuat2 *)Alloc(numQFrames * 4);

                    /* Read first frame */
                    ConsumeQuat2(&pos, quat);

                    /* line 464 */
                    if (flipQuat) {
                        quat[0] = -quat[0];
                        quat[1] = -quat[1];
                    }

                    /* line 470-471 */
                    part->quat->u.frames.u.frames2[0][0] = quat[0];
                    part->quat->u.frames.u.frames2[0][1] = quat[1];

                    if (numQFrames > 1) {
                        int k;
                        for (k = 1; k < numQFrames; k++) {
                            ConsumeQuat2(&pos, quat);
                            part->quat->u.frames.u.frames2[k][0] = quat[0];
                            part->quat->u.frames.u.frames2[k][1] = quat[1];
                        }

                        /* Sign fixup loop */
                        for (k = 1; k < numQFrames; k++) {
                            short int *cur = (short int *)&part->quat->u.frames.u.frames2[k];
                            short int *prev = (short int *)&part->quat->u.frames.u.frames2[k - 1];
                            int dot = (int)cur[0] * (int)prev[0] + (int)cur[1] * (int)prev[1];
                            if (dot < 0) {
                                cur[0] = -cur[0];
                                cur[1] = -cur[1];
                            }
                        }
                    }

                    /* Store numframes-1 in size */
                    part->quat->size = (unsigned short int)(numQuatIndices - 1);
                } else {
                    /* Full quat frames (4 components each) */

                    /* Allocate frames: 8 bytes per frame (XQuat) */
                    part->quat->u.frames.u.frames = (XQuat *)Alloc(numQFrames * 8);

                    /* Read first frame */
                    ConsumeQuat_C(&pos, quat);

                    /* line 499 */
                    if (flipQuat) {
                        quat[0] = -quat[0];
                        quat[1] = -quat[1];
                        quat[2] = -quat[2];
                        quat[3] = -quat[3];
                    }

                    /* line 507-510 */
                    part->quat->u.frames.u.frames[0][0] = quat[0];
                    part->quat->u.frames.u.frames[0][1] = quat[1];
                    part->quat->u.frames.u.frames[0][2] = quat[2];
                    part->quat->u.frames.u.frames[0][3] = quat[3];

                    if (numQFrames > 1) {
                        int k;
                        for (k = 1; k < numQFrames; k++) {
                            ConsumeQuat_C(&pos, quat);
                            part->quat->u.frames.u.frames[k][0] = quat[0];
                            part->quat->u.frames.u.frames[k][1] = quat[1];
                            part->quat->u.frames.u.frames[k][2] = quat[2];
                            part->quat->u.frames.u.frames[k][3] = quat[3];
                        }

                        /* Sign fixup loop */
                        for (k = 1; k < numQFrames; k++) {
                            short int *cur = (short int *)part->quat->u.frames.u.frames[k];
                            short int *prev = (short int *)part->quat->u.frames.u.frames[k - 1];
                            int dot = (int)cur[0] * (int)prev[0]
                                    + (int)cur[1] * (int)prev[1]
                                    + (int)cur[2] * (int)prev[2]
                                    + (int)cur[3] * (int)prev[3];
                            if (dot < 0) {
                                cur[0] = -cur[0];
                                cur[1] = -cur[1];
                                cur[2] = -cur[2];
                                cur[3] = -cur[3];
                            }
                        }
                    }

                    /* Store numframes-1 in size */
                    part->quat->size = (unsigned short int)(numQuatIndices - 1);
                }
            }

            /* Now read trans data (numTransIndices) */
            {
                unsigned short int numTransIndices;
                numTransIndices = ConsumeUShort(&pos);

                if (numTransIndices == 0) {
                    /* line 543 */
                    part->trans = (XAnimPartTrans *)0;
                } else if (numTransIndices == 1) {
                    /* Single trans frame: read 3 raw int values */
                    int v0, v1, v2;
                    v0 = ConsumeInt(&pos);
                    v1 = ConsumeInt(&pos);
                    v2 = ConsumeInt(&pos);

                    /* line 551 */
                    part->trans = (XAnimPartTrans *)Alloc(16);
                    part->trans->size = 0;
                    /* line 553 - store vec3 data */
                    {
                        int *to = (int *)&part->trans->u.frame0[0];
                        to[0] = v0;
                        to[1] = v1;
                        to[2] = v2;
                    }
                } else {
                    /* Multiple trans frames */
                    int numTFrames = (int)numTransIndices;

                    if (numTransIndices <= numloopframes) {
                        /* No index table */
                        part->trans = (XAnimPartTrans *)Alloc(8);
                    } else if (bSmallIndices) {
                        /* small indices */
                        part->trans = (XAnimPartTrans *)Alloc(14 + 2 * numTFrames);
                        memcpy(((char *)part->trans) + 8, pos, numTFrames);
                        pos += numTFrames;
                    } else {
                        /* large indices */
                        int idxBytes = numTFrames * 2;
                        part->trans = (XAnimPartTrans *)Alloc(14 + idxBytes);
                        memcpy(((char *)part->trans) + 8, pos, idxBytes);
                        pos += idxBytes;
                    }

                    /* line 597-598 */
                    part->trans->size = (unsigned short int)(numTransIndices - 1);
                    part->trans->u.frames.frames = (vec3_t *)Alloc(numTFrames * 12);

                    /* Read trans frames (3 raw ints each) */
                    {
                        int k;
                        for (k = 0; k < numTFrames; k++) {
                            int val0, val1, val2;
                            int *frameBase = (int *)((char *)part->trans->u.frames.frames + k * 12);
                            val0 = ConsumeInt(&pos);
                            frameBase[0] = val0;
                            val1 = ConsumeInt(&pos);
                            frameBase[1] = val1;
                            val2 = ConsumeInt(&pos);
                            frameBase[2] = val2;
                        }
                    }
                }
            }
        }
    }

    /* line 611 - read notify tracks */
    {
        int numNT;
        XAnimNotifyInfo *notify;

        numNT = ConsumeByte(&pos);

        /* line 66 */
        parts->notifyCount = (byte)(numNT + 1);

        /* line 68 */
        notify = (XAnimNotifyInfo *)Alloc((int)(unsigned char)parts->notifyCount * 8);

        /* line 69 */
        parts->notify = notify;

        /* line 71 */
        if (numNT > 0) {
            int j;
            for (j = 0; j < numNT; j++) {
                /* line 73 */
                notify[j].name = (ScriptString)SL_GetString_(pos, 0, 3);

                /* line 75 - advance past string */
                pos += strlen(pos) + 1;

                /* line 77 - read time */
                {
                    unsigned short int timeVal = ConsumeUShort(&pos);

                    /* line 79 */
                    if (parts->numframes != 0) {
                        notify[j].time = (float)(int)timeVal / (float)(unsigned short int)parts->numframes;
                    } else {
                        notify[j].time = 0.0f;
                    }
                }
            }
        }

        /* line 85-86 - add "end" notify */
        notify[numNT].name = (ScriptString)SL_GetString_("end", 0, 3);
        *(unsigned int *)&notify[numNT].time = 0x3f800000; /* 1.0f */
    }

    /* line 611 */
    FS_FreeFile(buf);

    /* line 614 */
    return parts;
}
