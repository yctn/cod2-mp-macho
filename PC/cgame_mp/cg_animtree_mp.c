/* Converted to C from ASM: cg_animtree_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_animtree_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern void Scr_BeginLoadAnimTrees(int param);
extern void Com_SafeClientDObjFree(int entNum);
extern void XAnimFreeTree(void *tree, void *allocInfo);

extern char **cg_glob; /* imp_cg — pointer to cg_t base */
extern centity_s **cg_entities; /* imp_cg_entities — pointer to centity array */
extern void *cg_xanimInfo; /* imp___Z7MT_FreePvi — XAnim allocator */

/* cg_t field offsets (from $_3724 in STABS) */
#define CG_ENTITY_LAST_TYPE    0x285f8
#define CG_ENTITY_LAST_XMODEL  0x295f8

void CGScr_LoadAnimTrees(void)
{
    Scr_BeginLoadAnimTrees(0);
}

void CG_SetDObjInfo(int iEntNum, int iEntType, struct XModel *pXModel)
{
    char *base = *cg_glob;
    *(int *)(base + CG_ENTITY_LAST_TYPE + iEntNum * 4) = iEntType;
    *(struct XModel **)(base + CG_ENTITY_LAST_XMODEL + iEntNum * 4) = pXModel;
}

qboolean CG_CheckDObjInfoMatches(int iEntNum, int iEntType, struct XModel *pXModel)
{
    char *base = *cg_glob;
    if (*(int *)(base + CG_ENTITY_LAST_TYPE + iEntNum * 4) != iEntType)
        return 0;
    if (*(struct XModel **)(base + CG_ENTITY_LAST_XMODEL + iEntNum * 4) != pXModel)
        return 0;
    return 1;
}

void CG_SafeDObjFree(int iEntNum)
{
    Com_SafeClientDObjFree(iEntNum);

    char *base = *cg_glob;
    *(int *)(base + CG_ENTITY_LAST_TYPE + iEntNum * 4) = 0;
    *(int *)(base + CG_ENTITY_LAST_XMODEL + iEntNum * 4) = 0;

    centity_s *ents = *cg_entities;
    if (ents[iEntNum].tree) {
        XAnimFreeTree((void *)ents[iEntNum].tree, cg_xanimInfo);
        ents[iEntNum].tree = 0;
    }
}

void CG_FreeClientDObjInfo(void)
{
    int i;
    for (i = 0; i < 0x40; i++) {
        Com_SafeClientDObjFree(i);

        char *base = *cg_glob;
        *(int *)(base + CG_ENTITY_LAST_TYPE + i * 4) = 0;
        *(int *)(base + CG_ENTITY_LAST_XMODEL + i * 4) = 0;

        centity_s *ents = *cg_entities;
        if (ents[i].tree) {
            XAnimFreeTree((void *)ents[i].tree, cg_xanimInfo);
            ents[i].tree = 0;
        }
    }
}

void CG_FreeEntityDObjInfo(void)
{
    int i;
    for (i = 0x40; i < 0x400; i++) {
        Com_SafeClientDObjFree(i);

        char *base = *cg_glob;
        *(int *)(base + CG_ENTITY_LAST_TYPE + i * 4) = 0;
        *(int *)(base + CG_ENTITY_LAST_XMODEL + i * 4) = 0;

        centity_s *ents = *cg_entities;
        if (ents[i].tree) {
            XAnimFreeTree((void *)ents[i].tree, cg_xanimInfo);
            ents[i].tree = 0;
        }
    }
}
