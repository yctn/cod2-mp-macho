/* ASM dump from: r_xsurface.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_xsurface.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

int XSurfaceGetNumVerts(const XSurface *surface);
int XSurfaceGetNumTris(const XSurface *surface);
long unsigned int XSurfaceGetTris(const XSurface *surface, r_index_t *dstIndices, int offset);
XVertexInfo * XSurfaceGetVertexInfoArray(const XSurface *surf);
int XSurfaceGetBoneOffset(const XSurface *surf);
long unsigned int XSurfaceTransferDx7(const XVertexBuffer *surfVerts, GfxVertexDx7 *verts, int vertCount);
long unsigned int XSurfaceTransfer(const XVertexBuffer *surfVerts, GfxVertex *verts, int vertCount);
long unsigned int XSurfaceGetVerts(const XSurface *surf, DObjSkelMat *boneMatrix, float *pVert, float *pTexCoord, float *pNormal);

/* line 39 */
int XSurfaceGetNumVerts(const XSurface *surface)
{
    return surface->vertCount;
}

/* line 45 */
int XSurfaceGetNumTris(const XSurface *surface)
{
    return surface->triCount;
}

/* line 51 */
long unsigned int XSurfaceGetTris(const XSurface *surface, r_index_t *dstIndices, int offset)
{
    short sOffset = (short)offset;

    if (sOffset != 0)
    {
        /* Pack offset into both halves of a 32-bit word */
        unsigned int twoOffsets = ((unsigned int)(unsigned short)sOffset << 16) | (unsigned short)sOffset;
        unsigned int *dst = (unsigned int *)dstIndices;
        unsigned int *src = (unsigned int *)surface->triIndices;
        short numMoves = surface->triCount >> 1;
        int i;

        for (i = 0; i < numMoves; i++)
        {
            dst[0] = src[0] + twoOffsets;
            dst[1] = src[1] + twoOffsets;
            dst[2] = src[2] + twoOffsets;
            dst += 3;
            src += 3;
        }
    }
    else
    {
        memcpy(dstIndices, surface->triIndices, surface->triCount * 6);
    }
}

/* line 89 */
XVertexInfo * XSurfaceGetVertexInfoArray(const XSurface *surf)
{
    return (XVertexInfo *)surf->verts;
}

/* line 95 */
int XSurfaceGetBoneOffset(const XSurface *surf)
{
    return surf->boneOffset;
}

/* line 241 */
long unsigned int XSurfaceTransferDx7(const XVertexBuffer *surfVerts, GfxVertexDx7 *verts, int vertCount)
{
    int vertIndex;
    const char *v = (const char *)surfVerts;

    if (vertCount <= 0)
        return 0;

    for (vertIndex = 0; vertIndex < vertCount; vertIndex++)
    {
        /* Copy position (offset 0x30 in XVertexInfo = offset field) to xyz */
        verts[vertIndex].xyz[0] = *(const float *)(v + 0x30);
        verts[vertIndex].xyz[1] = *(const float *)(v + 0x34);
        verts[vertIndex].xyz[2] = *(const float *)(v + 0x38);

        /* Copy normal (offset 0x00 in XVertexInfo = normal field) */
        verts[vertIndex].normal[0] = *(const float *)(v + 0x00);
        verts[vertIndex].normal[1] = *(const float *)(v + 0x04);
        verts[vertIndex].normal[2] = *(const float *)(v + 0x08);

        /* Copy color (offset 0x0C) */
        verts[vertIndex].color.packed = *(const unsigned int *)(v + 0x0C);

        /* Copy texCoord (texCoordX at 0x1C, texCoordY at 0x2C) */
        verts[vertIndex].texCoord[0] = *(const float *)(v + 0x1C);
        verts[vertIndex].texCoord[1] = *(const float *)(v + 0x2C);

        v += 0x40;
    }
}

/* line 218 */
long unsigned int XSurfaceTransfer(const XVertexBuffer *surfVerts, GfxVertex *verts, int vertCount)
{
    int vertIndex;
    const char *v = (const char *)surfVerts;

    if (vertCount <= 0)
        return 0;

    for (vertIndex = 0; vertIndex < vertCount; vertIndex++)
    {
        /* Copy position (offset 0x30 = offset field) to xyzw */
        verts[vertIndex].xyzw[0] = *(const float *)(v + 0x30);
        verts[vertIndex].xyzw[1] = *(const float *)(v + 0x34);
        verts[vertIndex].xyzw[2] = *(const float *)(v + 0x38);

        /* W component = 1.0f (0x3f800000) */
        verts[vertIndex].xyzw[3] = 1.0f;

        /* Copy normal (offset 0x00 = normal field) */
        verts[vertIndex].normal[0] = *(const float *)(v + 0x00);
        verts[vertIndex].normal[1] = *(const float *)(v + 0x04);
        verts[vertIndex].normal[2] = *(const float *)(v + 0x08);

        /* Copy color (offset 0x0C) */
        verts[vertIndex].color.packed = *(const unsigned int *)(v + 0x0C);

        /* Copy texCoord (texCoordX at 0x1C, texCoordY at 0x2C) */
        verts[vertIndex].texCoord[0] = *(const float *)(v + 0x1C);
        verts[vertIndex].texCoord[1] = *(const float *)(v + 0x2C);

        /* Copy binormal (offset 0x10 = binormal field) */
        verts[vertIndex].binormal[0] = *(const float *)(v + 0x10);
        verts[vertIndex].binormal[1] = *(const float *)(v + 0x14);
        verts[vertIndex].binormal[2] = *(const float *)(v + 0x18);

        /* Copy tangent (offset 0x20 = tangent field) */
        verts[vertIndex].tangent[0] = *(const float *)(v + 0x20);
        verts[vertIndex].tangent[1] = *(const float *)(v + 0x24);
        verts[vertIndex].tangent[2] = *(const float *)(v + 0x28);

        v += 0x40;
    }
}

/* Helper: Rotate normal by bone matrix (mat * normal, no translation) */
static void XSurfaceRotateNormal(const float *normal, const DObjSkelMat *mat, float *out)
{
    out[0] = normal[0] * mat->axis[0][0] + normal[1] * mat->axis[1][0] + normal[2] * mat->axis[2][0];
    out[1] = normal[0] * mat->axis[0][1] + normal[1] * mat->axis[1][1] + normal[2] * mat->axis[2][1];
    out[2] = normal[0] * mat->axis[0][2] + normal[1] * mat->axis[1][2] + normal[2] * mat->axis[2][2];
}

/* Helper: Transform position by bone matrix (mat * pos + origin) */
static void XSurfaceTransformPos(const float *pos, const DObjSkelMat *mat, float *out)
{
    out[0] = pos[0] * mat->axis[0][0] + pos[1] * mat->axis[1][0] + pos[2] * mat->axis[2][0] + mat->origin[0];
    out[1] = pos[0] * mat->axis[0][1] + pos[1] * mat->axis[1][1] + pos[2] * mat->axis[2][1] + mat->origin[1];
    out[2] = pos[0] * mat->axis[0][2] + pos[1] * mat->axis[1][2] + pos[2] * mat->axis[2][2] + mat->origin[2];
}

/* Helper: Transform position by bone matrix, multiply by scale, add to existing output */
static void XSurfaceTransformPosWeighted(const float *pos, const DObjSkelMat *mat, float scale, float *out)
{
    out[0] += (pos[0] * mat->axis[0][0] + pos[1] * mat->axis[1][0] + pos[2] * mat->axis[2][0] + mat->origin[0]) * scale;
    out[1] += (pos[0] * mat->axis[0][1] + pos[1] * mat->axis[1][1] + pos[2] * mat->axis[2][1] + mat->origin[1]) * scale;
    out[2] += (pos[0] * mat->axis[0][2] + pos[1] * mat->axis[1][2] + pos[2] * mat->axis[2][2] + mat->origin[2]) * scale;
}

/* line 106 */
long unsigned int XSurfaceGetVerts(const XSurface *surf, DObjSkelMat *boneMatrix, float *pVert, float *pTexCoord, float *pNormal)
{
    XVertexInfo *vertInfo;
    int vertCount;
    int i;

    vertInfo = (XVertexInfo *)surf->verts;
    short boneOffset = surf->boneOffset;

    if ((short)(boneOffset + 1) != 0)
    {
        /* Single bone - all vertices use the same bone matrix */
        DObjSkelMat *mat = (DObjSkelMat *)((char *)boneMatrix + boneOffset);

        vertCount = surf->vertCount;
        if (vertCount == 0)
            return 0;

        for (i = 0; i < vertCount; i++)
        {
            if (pNormal)
            {
                XSurfaceRotateNormal(vertInfo->normal, mat, pNormal);
                pNormal += 3;
            }

            if (pTexCoord)
            {
                pTexCoord[0] = vertInfo->texCoordX;
                pTexCoord[1] = vertInfo->texCoordY;
                pTexCoord += 2;
            }

            XSurfaceTransformPos(vertInfo->offset, mat, pVert);
            pVert += 3;
            vertInfo = (XVertexInfo *)((char *)vertInfo + 0x40);
        }
    }
    else
    {
        /* Per-vertex bone assignment with optional blend weights */
        const char *vdata = (const char *)vertInfo;

        vertCount = surf->vertCount;
        if (vertCount == 0)
            return 0;

        pVert += 3;

        for (i = 0; i < vertCount; i++)
        {
            const XVertexInfo *v = (const XVertexInfo *)vdata;

            if (pNormal)
            {
                DObjSkelMat *mat = (DObjSkelMat *)((char *)boneMatrix + v->boneOffset);
                XSurfaceRotateNormal(v->normal, mat, pNormal);
                pNormal += 3;
            }

            {
                DObjSkelMat *mat = (DObjSkelMat *)((char *)boneMatrix + v->boneOffset);
                XSurfaceTransformPos(v->offset, mat, pVert - 3);
            }

            if (v->numWeights != 0)
            {
                float scale;
                int numWeights;
                int j;
                const XBlendInfo *blend;

                scale = (float)v->boneWeight * 0.00390625f;
                pVert[-3] *= scale;
                pVert[-2] *= scale;
                pVert[-1] *= scale;

                blend = (const XBlendInfo *)(vdata + 0x40);
                for (j = 0; j < v->numWeights; j++)
                {
                    DObjSkelMat *mat2 = (DObjSkelMat *)((char *)boneMatrix + blend->boneOffset);
                    float s = (float)blend->boneWeight * 1.52587890625e-05f;
                    XSurfaceTransformPosWeighted(blend->offset, mat2, s, pVert - 3);
                    blend++;
                }
                vdata = (const char *)blend;
            }
            else
            {
                vdata += 0x40;
            }

            pVert += 3;
        }
    }
}
