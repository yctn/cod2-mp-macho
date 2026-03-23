/* ASM dump from: cm_world.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_world.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

static struct cm_world_t cm_world; /* cm_world */

void CM_UnlinkEntity(svEntity_t *ent);
static void CM_AreaEntities_r(void);
int CM_AreaEntities(const vec_t *mins, const vec_t *maxs, int *entityList, int maxcount, int contentmask);
static int CM_PointSightTraceToEntities_r(const vec_t *p2);
int CM_PointSightTraceToEntities(sightpointtrace_t *clip);
static qboolean CM_PointTraceStaticModelsComplete_r(const vec_t *p2);
qboolean CM_PointTraceStaticModelsComplete(const vec_t *start, const vec_t *end, int contentmask);
static int CM_ClipSightTraceToEntities_r(const vec_t *p2);
int CM_ClipSightTraceToEntities(sightclip_t *clip);
static void CM_PointTraceStaticModels_r(locTraceWork_t *tw, const vec_t *p2, trace_t *trace);
void CM_PointTraceStaticModels(trace_t *results, const vec_t *start, const vec_t *end, int contentmask);
static void CM_PointTraceToEntities_r(const vec_t *p2, trace_t *trace);
void CM_PointTraceToEntities(pointtrace_t *clip, trace_t *trace);
static void CM_ClipMoveToEntities_r(const vec_t *p2, trace_t *trace);
void CM_ClipMoveToEntities(moveclip_t *clip, trace_t *trace);
static void CM_SortNode(short unsigned int nodeIndex, vec_t *mins, vec_t *maxs);
void CM_LinkWorld(void);
void CM_LinkEntity(svEntity_t *ent, vec_t *absmin, vec_t *absmax, clipHandle_t clipHandle);

/* line 454 */

extern gentity_t *SV_GEntityForSvEntity(svEntity_t *svEnt);

/*
 * CM_UnlinkEntity: removes an entity from the collision world spatial partition.
 *
 * cm_world layout:
 *   offset 0:  vec3_t mins (12 bytes)
 *   offset 12: vec3_t maxs (12 bytes)
 *   offset 24: Bool lockTree (4 bytes... but freeHead at 26 means it's 2 bytes padding)
 *   offset 26: unsigned short freeHead
 *   offset 28: worldSector_t sectors[1024]  (each 24 bytes)
 *
 * worldSector_t layout (24 bytes):
 *   offset 0:  int contentsStaticModels
 *   offset 4:  int contentsEntities
 *   offset 8:  unsigned short entities       (linked list head, 1-based svEntity index)
 *   offset 10: unsigned short staticModels
 *   offset 12: float dist
 *   offset 16: unsigned short axis
 *   offset 18: unsigned short parent/nextFree
 *   offset 20: unsigned short child[0]
 *   offset 22: unsigned short child[1]
 *
 * svEntity_t is accessed at: (byte *)imp_sv + 0x22a4 + entityIndex * 372
 * where entityIndex is from the u16 linked list (1-based, 0 = end).
 * svEntity_t layout:
 *   offset 0: unsigned short worldSector
 *   offset 2: unsigned short nextEntityInWorldSector
 */
void CM_UnlinkEntity(svEntity_t *ent)
{
    byte *entRaw = (byte *)ent;
    unsigned short nodeIndex;
    byte *node; /* worldSector_t pointer */

    nodeIndex = ent->worldSector;
    if (nodeIndex == 0)
        return;

    /* Get sector node */
    {
        unsigned int idx = (unsigned int)nodeIndex;
        node = (byte *)&cm_world + 28 + idx * 24;
    }

    /* Clear entity's worldSector field */
    ent->worldSector = 0;

    /* Remove entity from the sector's entity linked list */
    {
        worldSector_t *sector = (worldSector_t *)node;
        unsigned short headEntIdx = sector->contents.entities;
        unsigned int ei = (unsigned int)headEntIdx;
        byte *sv = (byte *)imp_sv;
        svEntity_t *cur = (svEntity_t *)(sv + 0x22a4 + ei * 372);

        if (cur == ent) {
            /* Entity is the head: replace head with entity's next */
            sector->contents.entities = ent->nextEntityInWorldSector;
        } else {
            /* Walk the linked list to find the predecessor */
            while (1) {
                unsigned short nextIdx = cur->nextEntityInWorldSector;
                unsigned int ni = (unsigned int)nextIdx;
                svEntity_t *next = (svEntity_t *)(sv + 0x22a4 + ni * 372);
                if (next == ent) {
                    /* Unlink: predecessor's next = entity's next */
                    cur->nextEntityInWorldSector = ent->nextEntityInWorldSector;
                    break;
                }
                cur = next;
                sv = (byte *)imp_sv;
            }
        }
    }

    /* Walk up the tree, updating contents and potentially freeing empty nodes */
    /* Check if node has become empty:
     * 32-bit read at offset 8 checks entities(u16) + staticModels(u16) combined
     * 32-bit read at offset 0x14 checks child[0](u16) + child[1](u16) combined */
check_empty:
    if (((worldSector_t *)node)->contents.entities != 0 || ((worldSector_t *)node)->contents.staticModels != 0)
        goto update_contents;

    if (((worldSector_t *)node)->tree.child[0] != 0 || ((worldSector_t *)node)->tree.child[1] != 0)
        goto update_contents;

    /* Node is empty: contents = 0 */
    ((worldSector_t *)node)->contents.contentsEntities = 0;

    /* Check parent */
    {
        unsigned short parentIdx = ((worldSector_t *)node)->tree.u.parent;
        if (parentIdx == 0)
            goto update_contents;

        /* Free this node: put on free list */
        {
            unsigned short oldFreeHead = cm_world.freeHead;
            ((worldSector_t *)node)->tree.u.nextFree = oldFreeHead;
            cm_world.freeHead = nodeIndex;
        }

        /* Get parent node */
        {
            unsigned int pi = (unsigned int)parentIdx;
            byte *parentNode = (byte *)&cm_world + 28 + pi * 24;

            /* Update parent's child pointer: if we were child[0], clear child[0]; else clear child[1] */
            if (((worldSector_t *)parentNode)->tree.child[0] == nodeIndex) {
                ((worldSector_t *)parentNode)->tree.child[0] = 0;
            } else {
                ((worldSector_t *)parentNode)->tree.child[1] = 0;
            }

            nodeIndex = parentIdx;
            node = parentNode;
        }
    }

    /* Check if this parent node also became empty */
    if (((worldSector_t *)node)->contents.entities == 0 && ((worldSector_t *)node)->contents.staticModels == 0)
        goto check_empty;

update_contents:
    /* Recompute contents by OR-ing children's contents and all entities in linked list */
    {
        unsigned short child0Idx = ((worldSector_t *)node)->tree.child[0];
        unsigned short child1Idx = ((worldSector_t *)node)->tree.child[1];
        int contents;

        /* OR children contents */
        {
            unsigned int c0 = (unsigned int)child0Idx;
            unsigned int c1 = (unsigned int)child1Idx;
            contents = cm_world.sectors[c0].contents.contentsEntities;
            contents |= cm_world.sectors[c1].contents.contentsEntities;
        }

        /* OR entity contents from linked list */
        {
            unsigned short entIdx = ((worldSector_t *)node)->contents.entities;
            if (entIdx != 0) {
                byte *sv = (byte *)imp_sv;
                svEntity_t *svEnt = (svEntity_t *)(sv + 0x22a4 + (unsigned int)entIdx * 372);

                while (1) {
                    gentity_t *gent = SV_GEntityForSvEntity(svEnt);
                    contents |= gent->r.contents;
                    unsigned short nextIdx = svEnt->nextEntityInWorldSector;
                    if (nextIdx == 0)
                        break;
                    {
                        unsigned int ni = (unsigned int)nextIdx;
                        svEnt = (svEntity_t *)((byte *)imp_sv + 0x229c + ni * 372 + 8);
                    }
                }
            }
        }

        /* Store updated contents */
        ((worldSector_t *)node)->contents.contentsEntities = contents;

        /* Walk up to parent and continue updating */
        {
            unsigned short parentIdx = ((worldSector_t *)node)->tree.u.parent;
            if (parentIdx == 0)
                return;
            {
                unsigned int pi = (unsigned int)parentIdx;
                node = (byte *)&cm_world + 28 + pi * 24;
                goto update_contents;
            }
        }
    }
}
