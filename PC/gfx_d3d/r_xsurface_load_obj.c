/* ASM dump from: r_xsurface_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_xsurface_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/consumedata.h"
 */

/* Helper: read an unsigned short from pos and advance */
static unsigned short ConsumeUShort(const byte **pos) {
    unsigned short val = *(const unsigned short *)(*pos);
    *pos += 2;
    return val;
}

/* Helper: read a signed short from pos and advance */
static short ConsumeShort(const byte **pos) {
    short val = *(const short *)(*pos);
    *pos += 2;
    return val;
}

/* Helper: read a 4-byte int/float from pos and advance */
static int ConsumeInt(const byte **pos) {
    int val = *(const int *)(*pos);
    *pos += 4;
    return val;
}

/* Helper: read a byte from pos and advance */
static unsigned char ConsumeByte(const byte **pos) {
    unsigned char val = **pos;
    *pos += 1;
    return val;
}

/* line 32 */
XSurface * XModelReadSurface(XModel *model, int *partBits, const byte * *pos, Alloc_t Alloc)
{
    XSurface *surface;
    int j;
    int i;
    short boneOffsetRaw;
    int numTriIndices;
    int allocSize;
    int size;
    short *triIndicesShort;

    /* Allocate the XSurface struct (0x18 = 24 bytes) */
    surface = (XSurface *)Alloc(0x18);
    model->memUsage += 0x18;

    /* Read tileMode (byte) */
    surface->tileMode = ConsumeByte(pos);

    /* Read vertCount (unsigned short stored into signed short field) */
    surface->vertCount = (short)ConsumeUShort(pos);

    /* Read triCount */
    surface->triCount = (short)ConsumeUShort(pos);

    /* Read boneOffset raw value */
    boneOffsetRaw = ConsumeShort(pos);

    if (boneOffsetRaw == -1) {
        /* Skinned surface with per-vertex bone weights */
        short extraBlendCount;
        extraBlendCount = ConsumeShort(pos);

        surface->boneOffset = (short)0xFFFF;

        /* Allocation: (extraBlendCount + vertCount * 4) * 16 */
        size = ((int)extraBlendCount + (int)surface->vertCount * 4) * 16;
        surface->verts = (XVertexBuffer *)Alloc(size);
        model->memUsage += size;
    } else {
        /* Rigid surface with a single bone */
        surface->boneOffset = (short)(boneOffsetRaw << 6);
        partBits[boneOffsetRaw >> 5] |= (1 << (boneOffsetRaw & 0x1f));

        /* Allocation: vertCount * 64 (each XVertexInfo is 0x40) */
        size = (int)surface->vertCount * 64;
        surface->verts = (XVertexBuffer *)Alloc(size);
        model->memUsage += size;
    }

    /* Read vertex data */
    {
        byte *vertPtr = (byte *)surface->verts;

        for (j = 0; j < (int)surface->vertCount; j++) {
            /* Read normal (3 floats = 12 bytes at offset 0x00) */
            *(int *)(vertPtr + 0x00) = ConsumeInt(pos);
            *(int *)(vertPtr + 0x04) = ConsumeInt(pos);
            *(int *)(vertPtr + 0x08) = ConsumeInt(pos);

            /* Read color (4 bytes at offset 0x0C) */
            *(vertPtr + 0x0C) = (byte)(**pos);
            *(vertPtr + 0x0D) = (byte)(*(*pos + 1));
            *(vertPtr + 0x0E) = (byte)(*(*pos + 2));
            *(vertPtr + 0x0F) = (byte)(*(*pos + 3));
            *pos += 4;

            /* Read texCoordX (float at offset 0x1C) */
            *(int *)(vertPtr + 0x1C) = ConsumeInt(pos);
            /* Read texCoordY (float at offset 0x2C) */
            *(int *)(vertPtr + 0x2C) = ConsumeInt(pos);

            /* Read binormal (3 floats at offset 0x10) */
            *(int *)(vertPtr + 0x10) = ConsumeInt(pos);
            *(int *)(vertPtr + 0x14) = ConsumeInt(pos);
            *(int *)(vertPtr + 0x18) = ConsumeInt(pos);

            /* Read tangent (3 floats at offset 0x20) */
            *(int *)(vertPtr + 0x20) = ConsumeInt(pos);
            *(int *)(vertPtr + 0x24) = ConsumeInt(pos);
            *(int *)(vertPtr + 0x28) = ConsumeInt(pos);

            if (boneOffsetRaw != -1) {
                /* Rigid: read offset (3 floats at 0x30) */
                *(int *)(vertPtr + 0x30) = ConsumeInt(pos);
                *(int *)(vertPtr + 0x34) = ConsumeInt(pos);
                *(int *)(vertPtr + 0x38) = ConsumeInt(pos);

                vertPtr += 0x40;
            } else {
                /* Skinned: read numWeights, boneOffset per vertex, offset, blend info */
                byte numWeights;
                short vertBoneOffset;
                int k;

                numWeights = ConsumeByte(pos);
                *(vertPtr + 0x3C) = numWeights;

                vertBoneOffset = ConsumeShort(pos);
                partBits[vertBoneOffset >> 5] |= (1 << (vertBoneOffset & 0x1f));
                *(short *)(vertPtr + 0x3E) = (short)(vertBoneOffset << 6);

                /* Read offset (3 floats at 0x30) */
                *(int *)(vertPtr + 0x30) = ConsumeInt(pos);
                *(int *)(vertPtr + 0x34) = ConsumeInt(pos);
                *(int *)(vertPtr + 0x38) = ConsumeInt(pos);

                if (numWeights == 0) {
                    vertPtr += 0x40;
                } else {
                    /* Read boneWeight for main bone */
                    *(vertPtr + 0x3D) = ConsumeByte(pos);

                    vertPtr += 0x40;

                    /* Read extra blend weights */
                    for (k = 0; k < (int)numWeights; k++) {
                        short blendBoneOffset;

                        blendBoneOffset = ConsumeShort(pos);
                        partBits[blendBoneOffset >> 5] |= (1 << (blendBoneOffset & 0x1f));
                        *(short *)(vertPtr + 0x0C) = (short)(blendBoneOffset << 6);

                        /* Read blend offset (3 floats) */
                        *(int *)(vertPtr + 0x00) = ConsumeInt(pos);
                        *(int *)(vertPtr + 0x04) = ConsumeInt(pos);
                        *(int *)(vertPtr + 0x08) = ConsumeInt(pos);

                        /* Read blend boneWeight (unsigned short) */
                        *(unsigned short *)(vertPtr + 0x0E) = ConsumeUShort(pos);

                        vertPtr += 0x10;
                    }
                }
            }
        }
    }

    /* Read triIndices */
    {
        int roundedTriCount = ((int)surface->triCount + 1) & ~1;

        /* Allocate: triCount * 6 + 6 bytes = (triCount * 3 + 3) * 2 */
        numTriIndices = (int)surface->triCount * 3;
        allocSize = numTriIndices * 2 + 6;
        surface->triIndices = (int (*)[4])Alloc(allocSize);

        triIndicesShort = (short *)surface->triIndices;

        /* Read triCount * 3 index values */
        for (i = 0; i < numTriIndices; i++) {
            triIndicesShort[i] = (short)ConsumeUShort(pos);
        }

        /* Pad with degenerate triangle if triCount is odd */
        if ((int)surface->triCount != roundedTriCount) {
            triIndicesShort[numTriIndices + 0] = triIndicesShort[numTriIndices - 1];
            triIndicesShort[numTriIndices + 1] = triIndicesShort[numTriIndices + 0];
            triIndicesShort[numTriIndices + 2] = triIndicesShort[numTriIndices + 0];
            surface->triCount += 1;
        }
    }

    return surface;
}
