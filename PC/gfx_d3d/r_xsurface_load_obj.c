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
            XVertexInfo *vi = (XVertexInfo *)vertPtr;

            /* Read normal (3 floats) */
            *(int *)&vi->normal[0] = ConsumeInt(pos);
            *(int *)&vi->normal[1] = ConsumeInt(pos);
            *(int *)&vi->normal[2] = ConsumeInt(pos);

            /* Read color (4 bytes) */
            vi->color[0] = (byte)(**pos);
            vi->color[1] = (byte)(*(*pos + 1));
            vi->color[2] = (byte)(*(*pos + 2));
            vi->color[3] = (byte)(*(*pos + 3));
            *pos += 4;

            /* Read texCoordX */
            *(int *)&vi->texCoordX = ConsumeInt(pos);
            /* Read texCoordY */
            *(int *)&vi->texCoordY = ConsumeInt(pos);

            /* Read binormal (3 floats) */
            *(int *)&vi->binormal[0] = ConsumeInt(pos);
            *(int *)&vi->binormal[1] = ConsumeInt(pos);
            *(int *)&vi->binormal[2] = ConsumeInt(pos);

            /* Read tangent (3 floats) */
            *(int *)&vi->tangent[0] = ConsumeInt(pos);
            *(int *)&vi->tangent[1] = ConsumeInt(pos);
            *(int *)&vi->tangent[2] = ConsumeInt(pos);

            if (boneOffsetRaw != -1) {
                /* Rigid: read offset (3 floats) */
                *(int *)&vi->offset[0] = ConsumeInt(pos);
                *(int *)&vi->offset[1] = ConsumeInt(pos);
                *(int *)&vi->offset[2] = ConsumeInt(pos);

                vertPtr += sizeof(XVertexInfo);
            } else {
                /* Skinned: read numWeights, boneOffset per vertex, offset, blend info */
                byte numWeights;
                short vertBoneOffset;
                int k;

                numWeights = ConsumeByte(pos);
                vi->numWeights = numWeights;

                vertBoneOffset = ConsumeShort(pos);
                partBits[vertBoneOffset >> 5] |= (1 << (vertBoneOffset & 0x1f));
                vi->boneOffset = (short)(vertBoneOffset << 6);

                /* Read offset (3 floats) */
                *(int *)&vi->offset[0] = ConsumeInt(pos);
                *(int *)&vi->offset[1] = ConsumeInt(pos);
                *(int *)&vi->offset[2] = ConsumeInt(pos);

                if (numWeights == 0) {
                    vertPtr += sizeof(XVertexInfo);
                } else {
                    /* Read boneWeight for main bone */
                    vi->boneWeight = ConsumeByte(pos);

                    vertPtr += sizeof(XVertexInfo);

                    /* Read extra blend weights */
                    for (k = 0; k < (int)numWeights; k++) {
                        XBlendInfo *blend = (XBlendInfo *)vertPtr;
                        short blendBoneOffset;

                        blendBoneOffset = ConsumeShort(pos);
                        partBits[blendBoneOffset >> 5] |= (1 << (blendBoneOffset & 0x1f));
                        blend->boneOffset = (short)(blendBoneOffset << 6);

                        /* Read blend offset (3 floats) */
                        *(int *)&blend->offset[0] = ConsumeInt(pos);
                        *(int *)&blend->offset[1] = ConsumeInt(pos);
                        *(int *)&blend->offset[2] = ConsumeInt(pos);

                        /* Read blend boneWeight (unsigned short) */
                        blend->boneWeight = ConsumeUShort(pos);

                        vertPtr += sizeof(XBlendInfo);
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
