/* Converted to C from ASM: dobj_management.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/dobj_management.cpp */

#include "common_types.h"
#include "imports.h"

extern void DObjSkelClear(struct DObj_s *dobj);
extern void DObjCreate(DObjModel_s *models, int numModels, struct XAnimTree_s *tree, void *buf, int entNum);
extern void DObjFree(struct DObj_s *dobj);
extern void Com_Error(int level, const char *fmt, ...);
extern void Com_Memset(void *dest, int val, int count);

static objBufEntry objBuf[2048]; /* 0x4b7580 */
static Bool objAlloced[2048]; /* 0x4b6d80 */
static int objFreeCount; /* 0x4b6d00 */
static short int clientObjMap[1152]; /* 0x4b6400 */
static short int serverObjMap[1024]; /* 0x4b5c00 */
static int com_lastDObjIndex; /* 0x4b5b84 */
static qboolean g_bDObjInited; /* 0x4b5b80 */

struct DObj_s * Com_GetClientDObj(int handle, int localClientNum);
struct DObj_s * Com_GetServerDObj(int handle);
int Com_ClientDObjClearAllSkel(void);
int Com_ServerDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle);
int Com_SafeClientDObjFree(int handle);
int Com_SafeServerDObjFree(int handle);
int Com_InitDObj(void);
int Com_ShutdownDObj(void);
int Com_AbortDObj(void);
int Com_ClientDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle);

/* Shared allocation logic (inlined in original binary) */
static int Com_AllocDObj(void)
{
    int idx = com_lastDObjIndex + 1;

    while (idx <= 2047) {
        if (!objAlloced[idx]) {
            com_lastDObjIndex = idx;
            objAlloced[idx] = 1;
            objFreeCount--;
            return idx;
        }
        idx++;
    }

    if (com_lastDObjIndex > 0) {
        for (idx = 1; idx <= com_lastDObjIndex; idx++) {
            if (!objAlloced[idx]) {
                com_lastDObjIndex = idx;
                objAlloced[idx] = 1;
                objFreeCount--;
                return idx;
            }
        }
    }

    return 0;
}

/* line 71 */
struct DObj_s *Com_GetClientDObj(int handle, int localClientNum)
{
    int index = localClientNum * 1152 + handle;
    short mapVal = clientObjMap[index];
    if (mapVal == 0)
        return NULL;
    return (struct DObj_s *)&objBuf[mapVal];
}

/* line 90 */
struct DObj_s *Com_GetServerDObj(int handle)
{
    short mapVal = serverObjMap[handle];
    if (mapVal == 0)
        return NULL;
    return (struct DObj_s *)&objBuf[mapVal];
}

/* line 243 */
int Com_ClientDObjClearAllSkel(void)
{
    int i;
    for (i = 0; i < 1152; i++) {
        short mapVal = clientObjMap[i];
        if (mapVal != 0) {
            DObjSkelClear((struct DObj_s *)&objBuf[mapVal]);
        }
    }
}

/* line 275 */
int Com_ServerDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle)
{
    int idx = Com_AllocDObj();

    serverObjMap[handle] = (short)idx;
    DObjCreate(dobjModels, (unsigned short)numModels, tree, (void *)&objBuf[idx], (unsigned short)(handle + 1));

    if (objFreeCount == 0)
        Com_Error(1, "exceeded maximum number of DObjs");
}

/* line 360 */
int Com_SafeClientDObjFree(int handle)
{
    short mapVal = clientObjMap[handle];
    if (mapVal == 0)
        return 0;

    clientObjMap[handle] = 0;
    objAlloced[mapVal] = 0;
    objFreeCount++;
    DObjFree((struct DObj_s *)&objBuf[mapVal]);
}

/* line 404 */
int Com_SafeServerDObjFree(int handle)
{
    short mapVal = serverObjMap[handle];
    if (mapVal == 0)
        return 0;

    serverObjMap[handle] = 0;
    objAlloced[mapVal] = 0;
    objFreeCount++;
    DObjFree((struct DObj_s *)&objBuf[mapVal]);
}

/* line 443 */
int Com_InitDObj(void)
{
    Com_Memset(objAlloced, 0, 0x800);
    objFreeCount = 2047;
    Com_Memset(clientObjMap, 0, 0x900);
    Com_Memset(serverObjMap, 0, 0x800);
    com_lastDObjIndex = 1;
    g_bDObjInited = 1;
}

/* line 463 */
int Com_ShutdownDObj(void)
{
    g_bDObjInited = 0;
}

/* line 495 */
int Com_AbortDObj(void)
{
    g_bDObjInited = 0;
}

/* line 210 */
int Com_ClientDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle)
{
    int idx = Com_AllocDObj();

    clientObjMap[handle] = (short)idx;
    DObjCreate(dobjModels, (unsigned short)numModels, tree, (void *)&objBuf[idx], 0);

    if (objFreeCount == 0)
        Com_Error(1, "exceeded maximum number of DObjs");
}
