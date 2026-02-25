/* Converted to C from ASM: cg_animtree_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_animtree_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern void Scr_BeginLoadAnimTrees(int param);
extern void Com_SafeClientDObjFree(int entNum);
extern void XAnimFreeTree(void *tree, void *allocInfo);

extern char **cg_glob; /* 0x195f584 */
extern char **cg_ents; /* 0x195f5cc */
extern void *cg_xanimInfo; /* 0x195f954 */

void CGScr_LoadAnimTrees(void)
{
    Scr_BeginLoadAnimTrees(0);
}

void CG_SetDObjInfo(int iEntNum, int iEntType, struct XModel *pXModel)
{
    char *base = *cg_glob;
    *(int *)(base + 0x285f8 + iEntNum * 4) = iEntType;
    *(struct XModel **)(base + 0x295f8 + iEntNum * 4) = pXModel;
}

qboolean CG_CheckDObjInfoMatches(int iEntNum, int iEntType, struct XModel *pXModel)
{
    char *base = *cg_glob;
    if (*(int *)(base + 0x285f8 + iEntNum * 4) != iEntType)
        return 0;
    if (*(struct XModel **)(base + 0x295f8 + iEntNum * 4) != pXModel)
        return 0;
    return 1;
}

void CG_SafeDObjFree(int iEntNum)
{
    void *tree;

    Com_SafeClientDObjFree(iEntNum);

    char *base = *cg_glob;
    *(int *)(base + 0x285f8 + iEntNum * 4) = 0;
    *(int *)(base + 0x295f8 + iEntNum * 4) = 0;

    char *ents = *cg_ents;
    tree = *(void **)(ents + iEntNum * 0x224 + 0x21c);
    if (tree) {
        XAnimFreeTree(tree, cg_xanimInfo);
        *(void **)(ents + iEntNum * 0x224 + 0x21c) = 0;
    }
}

void CG_FreeClientDObjInfo(void)
{
    int i;
    for (i = 0; i < 0x40; i++) {
        void *tree;

        Com_SafeClientDObjFree(i);

        char *base = *cg_glob;
        *(int *)(base + 0x285f8 + i * 4) = 0;
        *(int *)(base + 0x295f8 + i * 4) = 0;

        char *ents = *cg_ents;
        tree = *(void **)(ents + i * 0x224 + 0x21c);
        if (tree) {
            XAnimFreeTree(tree, cg_xanimInfo);
            *(void **)(ents + i * 0x224 + 0x21c) = 0;
        }
    }
}

void CG_FreeEntityDObjInfo(void)
{
    int i;
    for (i = 0x40; i < 0x400; i++) {
        void *tree;

        Com_SafeClientDObjFree(i);

        char *base = *cg_glob;
        *(int *)(base + 0x285f8 + i * 4) = 0;
        *(int *)(base + 0x295f8 + i * 4) = 0;

        char *ents = *cg_ents;
        tree = *(void **)(ents + i * 0x224 + 0x21c);
        if (tree) {
            XAnimFreeTree(tree, cg_xanimInfo);
            *(void **)(ents + i * 0x224 + 0x21c) = 0;
        }
    }
}
