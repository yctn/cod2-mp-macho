/* Converted to C from ASM: sv_snapshot_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_snapshot_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

__attribute__((used, aligned(4)))
int endOffset[1] = {
    1,
}; /* 0x312620 */
__attribute__((used, aligned(4)))
int startOffset[7] = {
    2, 0, 0, 0, 0, 0, 0,
}; /* 0x312624 */

#define endOffset (endOffset[0])
#define startOffset (startOffset[0])

/* Global pointers accessed by absolute address */
extern byte svs_ptr[];              /* imp_svs - serverStatic_t */
extern byte sv_ptr[];               /* imp_sv - server_t */
extern byte *sv_showcommands_dvar; /* imp_sv_debugReliableCmds */
extern byte *sv_maxclients_dvar;   /* imp_sv_maxclients */
extern byte *sv_minPingRate_dvar;  /* imp_sv_maxRate */
extern byte *sv_padPackets_dvar;   /* imp_sv_padPackets */
extern byte *sv_showAverageBPS_dvar; /* imp_sv_showAverageBPS */
extern byte *showpackets_dvar;     /* imp_sv_debugRate */
extern byte *sv_maxRate_dvar;      /* imp_sv_fps */
extern int __mh_execute_header;

/* client_t field offsets */
#define CLIENT_RELIABLESEQUENCE   0x2080c
#define CLIENT_RELIABLEACK        0x20810
#define CLIENT_RELIABLESENT       0x20814
#define CLIENT_NAME               0x20c48
#define CLIENT_STATE              0x0
#define CLIENT_NETCHAN            0x6e5b4
#define CLIENT_SNAPSHOTMSEC       0x20d18
#define CLIENT_PUREAUTH           0x20d1c
#define CLIENT_LASTPACKETTIME     0x20d08
#define CLIENT_RATE               0x6e5a8
#define CLIENT_RATEDELAYED        0x6e5ac
#define CLIENT_NETTYPE            0x6e5c4
#define CLIENT_GAMESTATEMSGSENT   0x20840
#define CLIENT_OLDSERVERTIME      0x20c44
#define CLIENT_LASTCLIENTCMD      0x4
#define CLIENT_CMDENTRY_BASE      0xc
#define CLIENT_CMDENTRY_SIZE      0x408
#define CLIENT_CMDENTRY_STROFF    0x400
#define CLIENT_CMDENTRY_MASK      0x7f
#define CLIENT_STRIDE             0x78f0c
#define CLIENT_NETCHAN_SENDFRAG   0x725dc
#define CLIENT_NETCHAN_SENDLEN    0x725e4
#define CLIENT_NETCHAN_SENDSTART  0x725e0
#define CLIENT_DOWNLOAD           0x20c68

/* cachedClient_t stride */
#define CACHEDCLIENT_STRIDE       9992  /* 0x2708: 4 (valid) + 0x5c (clientState) + 0x26a8 (playerState) */

/* serverStatic_t field offsets */
#define SVS_TIME                  0x4
#define SVS_FLAGS                 0x8
#define SVS_CLIENTS               0xc
#define SVS_NUMENTITIES           0x10
#define SVS_NUMCLIENTS            0x14
#define SVS_NEXTSNAPSHOTENTITIES  0x18
#define SVS_NEXTSNAPSHOTCLIENTS   0x1c
#define SVS_ENTITYSTATES          0x20
#define SVS_CLIENTSTATES          0x24
#define SVS_NUMONEWAYCLIENTS      0x28
#define SVS_ARCHIVEDFRAMECOUNT    0x2c
#define SVS_ARCHIVEDENTITYPARTS   0x30
#define SVS_ARCHIVEDENTITYBUF     0x34
#define SVS_ARCHIVEDENTITYBUFSIZE 0x38
#define SVS_ARCHIVEDENTNUMINDEX   0x3c
#define SVS_ARCHIVEDCLIENTNUMINDEX 0x40
#define SVS_ARCHIVEDFRAMENUM      0x44
#define SVS_ARCHIVEDENTITYDATA    0x48
#define SVS_ARCHIVEDCLIENTDATA    0x4c
#define SVS_CACHEDFRAMES          0x50
#define SVS_NEXTARCHIVEDFRAMENUM  0x54

extern void Com_Printf(const char *fmt, ...);
extern void Com_DPrintf(const char *fmt, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern void MSG_WriteByte(msg_t *msg, int value);
extern void MSG_WriteLong(msg_t *msg, int value);
extern void MSG_WriteString(msg_t *msg, const char *s);
extern void MSG_WriteBit0(msg_t *msg);
extern void MSG_WriteBit1(msg_t *msg);
extern void MSG_WriteBits(msg_t *msg, int value, int bits);
extern int MSG_ReadBit(msg_t *msg);
extern int MSG_ReadBits(msg_t *msg, int bits);
extern int MSG_ReadLong(msg_t *msg);
extern void MSG_Init(msg_t *msg, byte *data, int length);
extern int MSG_WriteBitsCompress(byte *from, byte *to, int size);
extern void MSG_WriteDeltaEntity(msg_t *msg, byte *from, byte *to, int force);
extern void MSG_WriteDeltaClient(msg_t *msg, byte *from, byte *to, int force);
extern void MSG_WriteDeltaPlayerstate(msg_t *msg, byte *from, byte *to);
extern void MSG_WriteDeltaArchivedEntity(msg_t *msg, byte *from, byte *to, int force);
extern void MSG_ReadDeltaClient(msg_t *msg, byte *from, byte *to, int clientNum);
extern void MSG_ReadDeltaPlayerstate(msg_t *msg, byte *from, byte *to);
extern void MSG_ReadDeltaArchivedEntity(msg_t *msg, byte *from, byte *to, int entNum);
extern void SV_DropClient(client_t *client, const char *reason);
extern void SV_Netchan_Transmit(client_t *client, int length, byte *data);
extern void SV_Netchan_TransmitNextFragment(netchan_t *chan);
extern void SV_WriteDownloadToClient(client_t *client, msg_t *msg);
extern void SV_SendClientVoiceData(client_t *client);
extern byte *SV_GentityNum(int num);
extern byte *SV_SvEntityForGentity(byte *gent);
extern void *G_GetClientState(int clientNum);
extern int GetFollowPlayerState(int clientNum, byte *ps);
extern int G_GetClientArchiveTime(int clientNum);
extern void G_SetClientArchiveTime(int clientNum, int archiveTime);
extern float G_GetFogOpaqueDistSqrd(void);
extern int BoxDistSqrdExceeds(byte *absmin, byte *absmax, byte *org, float distSqrd);
extern int CM_PointLeafnum(byte *p);
extern int CM_LeafCluster(int leafnum);
extern byte *CM_ClusterPVS(int cluster);
extern int CM_BoxLeafnums(byte *mins, byte *maxs, int *leafs, int count, int *lastLeaf);
extern void AddLeanToPosition(byte *org, int viewAngleYaw, int leanf, float a, float b);
extern void LargeLocal_LargeLocal(byte *ll, int size);
extern byte *LargeLocal_GetBuf(byte *ll);
extern void ZN10LargeLocalD1Ev(byte *ll);
extern int Sys_IsLANAddress(int a, int b, int c);
extern void Dvar_SetInt(byte *dvar, int value);
extern void NET_OutOfBandPrint(int sock, int a, int b, int c, const char *data);
extern void *SV_GameClientNum(int clientNum);

void SV_UpdateServerCommandsToClient(client_t *client, msg_t *msg);
static cachedSnapshot_t * __attribute_regparm__(1) SV_GetCachedSnapshotInternal(int archivedFrame);
void SV_ArchiveSnapshot(void);
void SV_SendMessageToClient(msg_t *msg, client_t *client);
qboolean SV_GetArchivedClientInfo(int clientNum, int *pArchiveTime, int (*ps)[4], void (*cs)());
Bool SV_GetClientPositionAtTime(int client, int gametime, vec_t *pos);
void SV_SendClientSnapshot(client_t *client);
void SV_SendClientMessages(void);

/* line 483 */
void SV_UpdateServerCommandsToClient(client_t *client, msg_t *msg)
{
    int reliableAck = client->reliableAcknowledge;
    int reliableSeq = client->reliableSequence;
    byte *showdvar = *(byte **)&sv_showcommands_dvar;
    int i;
    int idx;
    char *cmdStr;

    if (reliableAck + 1 < reliableSeq) {
        if (*(byte *)(*(byte **)showdvar + 8) != 0) {
            Com_Printf("Client %s has the following un-ack'd reliable commands:\n", client->name);
            reliableAck = client->reliableAcknowledge;
        }
    }

    for (i = reliableAck + 1; i <= reliableSeq; i++) {
        MSG_WriteByte(msg, 4);
        MSG_WriteLong(msg, i);
        idx = i & CLIENT_CMDENTRY_MASK;
        cmdStr = client->reliableCommandInfo[idx].cmd;
        MSG_WriteString(msg, cmdStr);
        if (*(byte *)(*(byte **)*(byte **)&sv_showcommands_dvar + 8) != 0) {
            Com_Printf("%i: %s\n", i - client->reliableAcknowledge - 1, cmdStr);
        }
    }

    client->reliableSent = reliableSeq;
}

/* line 836 */
static __attribute_regparm__(1)
cachedSnapshot_t * SV_GetCachedSnapshotInternal(int archivedFrame)
{
    byte msg_buf_ll[16]; /* LargeLocal */
    byte *msg_buf;
    msg_t msg;
    serverStatic_t *svs;
    cachedSnapshot_t *cachedFrame = NULL;
    byte *partEntry;

    LargeLocal_LargeLocal(msg_buf_ll, 0x20000);
    msg_buf = LargeLocal_GetBuf(msg_buf_ll);

    svs = (serverStatic_t *)imp_svs;

    /* Compute archived entity part entry (archivedFrame % 1200, stride 8) */
    partEntry = (byte *)svs->archivedSnapshotFrames + (archivedFrame % 1200) * 8;

    /* Check data freshness */
    if (*(int *)partEntry < svs->nextArchivedSnapshotBuffer - 0x2000000)
        goto return_null;

    /* Search existing cached frames */
    {
        int searchStart = svs->nextCachedSnapshotFrames;
        int searchEnd = searchStart - 0x200;
        byte *cfBase;
        int i;

        if (searchEnd < 0) searchEnd = 0;

        if (searchStart - 1 >= searchEnd) {
            cfBase = (byte *)svs->cachedSnapshotFrames;
            for (i = searchStart - 1; i >= searchEnd; i--) {
                cachedSnapshot_t *cf = (cachedSnapshot_t *)(cfBase + (i % 512) * 28);
                if (cf->archivedFrame == archivedFrame) {
                    cachedFrame = cf;
                    svs = (serverStatic_t *)imp_svs;
                    if (cf->first_entity >= svs->nextCachedSnapshotEntities - 0x4000) {
                        if (cf->first_client >= svs->nextCachedSnapshotClients - (int)&__mh_execute_header) {
                            goto cleanup; /* Still valid */
                        }
                    }
                    break;
                }
            }
        }
    }

    /* Decode from archived entity data */
    MSG_Init(&msg, msg_buf, 0x20000);
    msg.cursize = *(int *)(partEntry + 4);

    {
        int dataOffset = *(int *)partEntry % 0x2000000;
        int remaining = 0x2000000 - dataOffset;
        byte *entBuf;

        if (msg.cursize <= remaining) {
            svs = (serverStatic_t *)imp_svs;
            entBuf = svs->archivedSnapshotBuffer;
            memcpy(msg.data, entBuf + dataOffset, msg.cursize);
        } else {
            svs = (serverStatic_t *)imp_svs;
            entBuf = svs->archivedSnapshotBuffer;
            memcpy(msg.data, entBuf + dataOffset, remaining);
            memcpy(msg.data + remaining, entBuf, msg.cursize - remaining);
        }
    }

    if (MSG_ReadBit(&msg) == 0) {
        /* Delta decode from old archived frame */
        int oldArchivedFrame = MSG_ReadLong(&msg);
        cachedSnapshot_t *oldCachedFrame;

        svs = (serverStatic_t *)imp_svs;
        if (oldArchivedFrame < svs->nextArchivedSnapshotFrames - 0x4b0)
            goto return_null;

        /* Validate old data freshness */
        {
            byte *oldPart = (byte *)svs->archivedSnapshotFrames + (oldArchivedFrame % 1200) * 8;
            if (*(int *)oldPart < svs->nextArchivedSnapshotBuffer - 0x2000000)
                goto return_null;
        }

        oldCachedFrame = SV_GetCachedSnapshotInternal(oldArchivedFrame);
        if (oldCachedFrame == NULL)
            goto return_null;

        /* Allocate new cached frame slot */
        {
            int frameIdx = svs->nextCachedSnapshotFrames % 512;
            cachedFrame = (cachedSnapshot_t *)((byte *)svs->cachedSnapshotFrames + frameIdx * 28);
        }
        cachedFrame->archivedFrame = archivedFrame;
        cachedFrame->num_entities = 0;
        cachedFrame->first_entity = svs->nextCachedSnapshotEntities;
        cachedFrame->num_clients = 0;
        cachedFrame->first_client = svs->nextCachedSnapshotClients;
        cachedFrame->usesDelta = 1;
        cachedFrame->time = MSG_ReadLong(&msg);

        /* Decode clients with delta from old cached frame */
        {
            int oldNumClients = oldCachedFrame->num_clients;
            byte *oldCachedClient = NULL;
            int oldClientNum = 0x1869f;
            int oldindex = 0;

            if (oldNumClients > 0) {
                int firstIdx = oldCachedFrame->first_client % 0x1000;
                oldCachedClient = (byte *)svs->cachedSnapshotClients + firstIdx * CACHEDCLIENT_STRIDE;
                oldClientNum = *(int *)(oldCachedClient + 4);
            }

            while (MSG_ReadBit(&msg) != 0) {
                int newClientNum = MSG_ReadBits(&msg, 6);
                int clientIdx;
                byte *newCachedClient;

                if (msg.readcount > msg.cursize)
                    Com_Error(1, "SV_GetCachedSnapshot: msg overflow");

                /* Skip old clients before this one */
                while (oldClientNum < newClientNum) {
                    oldindex++;
                    if (oldindex >= oldNumClients) {
                        oldClientNum = 0x1869f;
                        break;
                    }
                    {
                        svs = (serverStatic_t *)imp_svs;
                        byte *cdata = (byte *)svs->cachedSnapshotClients;
                        int nextIdx = (oldCachedFrame->first_client + oldindex) % 0x1000;
                        oldCachedClient = cdata + nextIdx * CACHEDCLIENT_STRIDE;
                        oldClientNum = *(int *)(oldCachedClient + 4);
                    }
                }

                svs = (serverStatic_t *)imp_svs;
                clientIdx = svs->nextCachedSnapshotClients % 0x1000;
                newCachedClient = (byte *)svs->cachedSnapshotClients + clientIdx * CACHEDCLIENT_STRIDE;

                if (oldClientNum == newClientNum) {
                    /* Delta from old cached client */
                    MSG_ReadDeltaClient(&msg, oldCachedClient + 4, newCachedClient + 4, newClientNum);
                    *(int *)newCachedClient = MSG_ReadBit(&msg);
                    if (*(int *)newCachedClient != 0)
                        MSG_ReadDeltaPlayerstate(&msg, (byte *)&((cachedClient_t *)oldCachedClient)->ps, (byte *)&((cachedClient_t *)newCachedClient)->ps);

                    svs = (serverStatic_t *)imp_svs;
                    svs->nextCachedSnapshotClients += 1;
                    if (svs->nextCachedSnapshotClients > 0x7ffffffd)
                        Com_Error(0, "SV_GetCachedSnapshot: too many clients");

                    cachedFrame->num_clients++;

                    /* Advance old client */
                    oldindex++;
                    if (oldindex >= oldCachedFrame->num_clients) {
                        oldClientNum = 0x1869f;
                    } else {
                        svs = (serverStatic_t *)imp_svs;
                        byte *cdata = (byte *)svs->cachedSnapshotClients;
                        int nextIdx = (oldCachedFrame->first_client + oldindex) % 0x1000;
                        oldCachedClient = cdata + nextIdx * CACHEDCLIENT_STRIDE;
                        oldClientNum = *(int *)(oldCachedClient + 4);
                    }
                } else {
                    /* New client not in old frame - delta from NULL */
                    MSG_ReadDeltaClient(&msg, NULL, newCachedClient + 4, newClientNum);
                    *(int *)newCachedClient = MSG_ReadBit(&msg);
                    if (*(int *)newCachedClient != 0)
                        MSG_ReadDeltaPlayerstate(&msg, NULL, (byte *)&((cachedClient_t *)newCachedClient)->ps);

                    svs = (serverStatic_t *)imp_svs;
                    svs->nextCachedSnapshotClients += 1;
                    if (svs->nextCachedSnapshotClients > 0x7ffffffd)
                        Com_Error(0, "SV_GetCachedSnapshot: too many clients");

                    cachedFrame->num_clients++;
                }
            }
        }
    } else {
        /* Full fresh decode (no delta base) */
        svs = (serverStatic_t *)imp_svs;

        {
            int frameIdx = svs->nextCachedSnapshotFrames % 512;
            cachedFrame = (cachedSnapshot_t *)((byte *)svs->cachedSnapshotFrames + frameIdx * 28);
        }
        cachedFrame->archivedFrame = archivedFrame;
        cachedFrame->num_entities = 0;
        cachedFrame->first_entity = svs->nextCachedSnapshotEntities;
        cachedFrame->num_clients = 0;
        cachedFrame->first_client = svs->nextCachedSnapshotClients;
        cachedFrame->usesDelta = 0;
        cachedFrame->time = MSG_ReadLong(&msg);

        /* Decode clients fresh (no delta base) */
        while (MSG_ReadBit(&msg) != 0) {
            int clientNum = MSG_ReadBits(&msg, 6);
            int clientIdx;
            byte *newCachedClient;

            if (msg.readcount > msg.cursize)
                Com_Error(1, "SV_GetCachedSnapshot: msg overflow");

            clientIdx = svs->nextCachedSnapshotClients % 0x1000;
            newCachedClient = (byte *)svs->cachedSnapshotClients + clientIdx * CACHEDCLIENT_STRIDE;

            MSG_ReadDeltaClient(&msg, NULL, newCachedClient + 4, clientNum);
            *(int *)newCachedClient = MSG_ReadBit(&msg);
            if (*(int *)newCachedClient != 0)
                MSG_ReadDeltaPlayerstate(&msg, NULL, (byte *)&((cachedClient_t *)newCachedClient)->ps);

            svs->nextCachedSnapshotClients += 1;
            if (svs->nextCachedSnapshotClients > 0x7ffffffd)
                Com_Error(0, "SV_GetCachedSnapshot: too many clients");

            cachedFrame->num_clients++;
        }
    }

    /* Decode entities (shared between delta and fresh paths) */
    while (1) {
        int entNum = MSG_ReadBits(&msg, 10);
        int entIdx;
        byte *archivedEnt;
        server_t *sv;

        if (entNum == 0x3ff)
            break;

        if (msg.readcount > msg.cursize)
            Com_Error(1, "SV_GetCachedSnapshot: msg overflow");

        svs = (serverStatic_t *)imp_svs;
        entIdx = svs->nextCachedSnapshotEntities % 0x4000;
        archivedEnt = (byte *)svs->cachedSnapshotEntities + entIdx * 276;

        sv = (server_t *)imp_sv;
        MSG_ReadDeltaArchivedEntity(&msg, (byte *)&sv->svEntities[entNum].baseline, archivedEnt, entNum);

        svs->nextCachedSnapshotEntities += 1;
        if (svs->nextCachedSnapshotEntities > 0x7ffffffd)
            Com_Error(0, "SV_GetCachedSnapshot: too many entities");

        cachedFrame->num_entities++;
    }

    /* Increment archived frame number */
    svs = (serverStatic_t *)imp_svs;
    svs->nextCachedSnapshotFrames += 1;
    if (svs->nextCachedSnapshotFrames > 0x7ffffffd)
        Com_Error(0, "SV_GetCachedSnapshot: too many frames");

    goto cleanup;

return_null:
    cachedFrame = NULL;
cleanup:
    ZN10LargeLocalD1Ev(msg_buf_ll);
    return cachedFrame;
}

/* line 1772 */

/* SV_SvEntityForGentity and __mh_execute_header already declared above */

/*
 * SV_ArchiveSnapshot: archives the current server state as a snapshot.
 *
 * Writes delta-compressed entity and client states to an archived frame.
 * Uses a ring buffer for archived entities and clients.
 *
 * svs (serverStatic_t) field offsets:
 *   0x04: time
 *   0x0c: clients
 *   0x28: numOneWayClients
 *   0x2c: archivedFrameCount
 *   0x30: archivedEntityParts (ptr to 8-byte entries: [startOffset, msgLength])
 *   0x34: archivedEntityBuf
 *   0x38: archivedEntityBufSize
 *   0x3c: archivedEntNumIndex
 *   0x40: archivedClientNumIndex
 *   0x44: archivedFrameNum
 *   0x48: archivedEntityData
 *   0x4c: archivedClientData
 *   0x50: cachedFrames
 *   0x54: nextArchivedFrameNum
 *
 * cachedFrame (at svs.cachedFrames + frameIndex * cachedFrameSize):
 *   0x00: serverTime (int)
 *   0x04: archiveTime (int)
 *   0x08: numEntities (int)
 *   0x0c: firstEntity (int)
 *   0x10: numClients (int)
 *   0x14: firstClient (int)
 *   0x18: usesDelta (int)
 *
 * cachedFrame ring index: archivedFrameNum & 0x1ff
 * cachedFrameSize derived from asm: index * 28 (0x1c each based on 7 fields)
 *   Actually let me compute: idx & 0x800001ff -> idx*4*32 - idx*4 = idx*124.
 *   leal (, %edx, 4), %eax; shll $5, %edx; subl %eax, %edx => edx = idx*32*4 - idx*4 = idx*124
 *   then addl %ecx, %edx => svs.cachedFrames + idx*124
 *   Hmm wait: "leal (, %edx, 4), %eax" => eax = edx*4
 *   "shll $5, %edx" => edx = edx*32
 *   "subl %eax, %edx" => edx = edx*32 - edx*4 = edx*28
 *   "movl 0x50(%ebx), %ecx" => ecx = svs.cachedFrames
 *   "addl %ecx, %edx" => edx = cachedFrames + idx*28
 *   So cachedFrameSize = 28 bytes = 7 ints.
 *
 * For archived entities:
 *   archivedEntNumIndex & 0x3fff -> slot
 *   slotSize: idx*16+idx => idx*17, then *4 => idx*68. So archivedEntitySize = 68 bytes?
 *   Actually: "movl %edx, %eax; shll $4, %eax; addl %edx, %eax; leal (%edx, %eax, 4), %eax"
 *   => eax = edx + (edx*16 + edx)*4 = edx + edx*68 = edx*69? No:
 *   eax = edx*16, eax += edx => eax = edx*17, then eax = edx + eax*4 = edx + edx*68 = edx*69
 *   Hmm, let me re-read: ".Lf192a4c_00192f00:"
 *   "movl %edx, %eax" => eax = idx
 *   "shll $4, %eax" => eax = idx*16
 *   "addl %edx, %eax" => eax = idx*17
 *   "leal (%edx, %eax, 4), %eax" => eax = idx + idx*17*4 = idx + idx*68 = idx*69
 *   "movl 0x48(%ecx), %edx" => edx = svs.archivedEntityData
 *   "leal (%edx, %eax, 4), %esi" => esi = archivedEntityData + idx*69*4 = archivedEntityData + idx*276
 *   So archivedEntitySize = 276 bytes.
 *
 * For archived clients:
 *   archivedClientNumIndex & 0xfff -> slot
 *   slotSize: "leal (%edx, %edx, 4), %eax" => eax = idx*5
 *   "shll $3, %eax" => eax = idx*40
 *   "subl %edx, %eax" => eax = idx*39
 *   "shll $5, %eax" => eax = idx*39*32 = idx*1248
 *   "addl %edx, %eax" => eax = idx*1249
 *   "movl 0x4c(%ecx), %edx" => archivedClientData
 *   "leal (%edx, %eax, 8), %eax" => archivedClientData + idx*1249*8 = archivedClientData + idx*9992
 *   So archivedClientSize = 9992 bytes (matches CACHEDCLIENT_STRIDE).
 *
 * svEntity_t baseline: sv + 0x241c + entityNum * 372 (from sv.svEntities[entityNum].baseline)
 */

/* Helper to compute modular index with proper sign handling (emulating x86 signed modular arithmetic) */
static int signedMod512(int x) {
    int r = x & 0x800001ff;
    if (r < 0) { r = ((r - 1) | (int)0xfffffe00) + 1; }
    return r;
}

static int signedMod4096(int x) {
    int r = x & 0x80000fff;
    if (r < 0) { r = ((r - 1) | (int)0xfffff000) + 1; }
    return r;
}

static int signedMod16384(int x) {
    int r = x & 0x80003fff;
    if (r < 0) { r = ((r - 1) | (int)0xffffc000) + 1; }
    return r;
}

static int signedMod33554432(int x) {
    int r = x & 0x81ffffff;
    if (r < 0) { r = ((r - 1) | (int)0xfe000000) + 1; }
    return r;
}

void SV_ArchiveSnapshot(void)
{
    byte msg_buf_large_local[24]; /* LargeLocal on stack */
    byte *msg_buf;
    byte msg[24]; /* msg_t on stack */
    serverStatic_t *svs_p = (serverStatic_t *)imp_svs;
    server_t *sv_p = (server_t *)imp_sv;
    byte ps[0x26a8]; /* playerState_t buffer */
    byte archivedEnt[0xf0]; /* archived entity buffer */

    LargeLocal_LargeLocal(msg_buf_large_local, 0x20000);
    msg_buf = LargeLocal_GetBuf(msg_buf_large_local);

    /* Check sv.state == 2 (SS_GAME) */
    if (sv_p->state != 2)
        goto cleanup;

    /* Check numOneWayClients > 0 */
    if (svs_p->archiveEnabled == 0)
        goto cleanup;

    /* Init message buffer */
    MSG_Init((msg_t *)msg, msg_buf, 0x20000);

    /* Find old cached frame to delta against */
    {
        int archivedFrameNum = svs_p->nextCachedSnapshotFrames;
        int oldindex = archivedFrameNum - 0x200;
        int newnum;
        byte *cachedFrames;
        byte *cachedFrame;
        int frameSlot;

        if (oldindex < 0)
            oldindex = 0;

        /* Determine the fps-based minimum frame number */
        {
            byte *fps_dvar = *(byte **)&sv_maxRate_dvar; /* imp_sv_fps */
            byte *fps_val = *(byte **)fps_dvar;
            newnum = svs_p->nextArchivedSnapshotFrames - *(int *)(fps_val + 8);
        }

        /* Walk backwards to find a suitable old frame */
        {
            int idx = archivedFrameNum - 1;
            cachedFrames = (byte *)svs_p->cachedSnapshotFrames;

            while (idx >= oldindex) {
                int cfSlot = signedMod512(idx);
                byte *cf = cachedFrames + cfSlot * 28;

                if (*(int *)cf <= newnum) {
                    /* Check if this frame has valid delta data */
                    if (((cachedSnapshot_t *)cf)->usesDelta == 0) {
                        /* This frame doesn't use delta - check if its entity/client indices are recent enough */
                        serverStatic_t *svs2 = (serverStatic_t *)imp_svs;
                        if (((cachedSnapshot_t *)cf)->first_entity < svs2->nextCachedSnapshotEntities - 0x4000)
                            break;
                        if (((cachedSnapshot_t *)cf)->first_client < svs2->nextCachedSnapshotClients - (int)&__mh_execute_header)
                            break;

                        /* Write delta reference */
                        MSG_WriteBit0((msg_t *)msg);
                        MSG_WriteLong((msg_t *)msg, ((cachedSnapshot_t *)cf)->archivedFrame);
                        MSG_WriteLong((msg_t *)msg, svs2->time);

                        /* Write client deltas */
                        {
                            byte *maxclients_dvar = *(byte **)&sv_maxclients_dvar;
                            byte *maxclients_val = *(byte **)maxclients_dvar;
                            int to_num_clients = *(int *)(maxclients_val + 8);
                            int from_num_clients = ((cachedSnapshot_t *)cf)->num_clients;
                            byte *cachedClient = NULL;
                            int newIdx = 0;
                            int oldIdx2 = 0;

                            while (1) {
                                if (newIdx >= to_num_clients) {
                                    /* Process remaining old clients */
                                    while (oldIdx2 < from_num_clients) {
                                        int archClientIdx = oldIdx2 + ((cachedSnapshot_t *)cf)->first_client;
                                        int archSlot = signedMod4096(archClientIdx);
                                        serverStatic_t *svs3 = (serverStatic_t *)imp_svs;
                                        cachedClient = (byte *)svs3->cachedSnapshotClients + archSlot * 9992;

                                        if (*(int *)(cachedClient + 4) >= newIdx)
                                            break;
                                        oldIdx2++;
                                    }
                                    if (oldIdx2 >= from_num_clients)
                                        break;
                                    break;
                                }

                                /* Check if this client is active */
                                {
                                    serverStatic_t *svs4 = (serverStatic_t *)imp_svs;
                                    byte *clients = (byte *)svs4->clients;
                                    /* Client stride: newIdx * 0x78f0c + ... complex calculation */
                                    /* The asm computes: newIdx*5 => *128+val => *64+newIdx => *4-val => *4 */
                                    /* Let me trace: leal (%ebx, %ebx, 4) => ebx*5
                                     * shll $7 => *128  =>  ebx*640
                                     * addl %edx => + ebx*5 => ebx*645
                                     * shll $6 => *64 => ebx*41280
                                     * addl %ebx => + ebx => ebx*41281? No...
                                     * Actually the stride is 0x78f0c = 495372.
                                     * Let me just compute: newIdx * 0x78f0c. */
                                    /* Actually looking at the asm:
                                     * leal (%ebx, %ebx, 4), %eax => eax = newIdx*5
                                     * movl %eax, %edx => edx = newIdx*5
                                     * shll $7, %edx => edx = newIdx*640
                                     * addl %edx, %eax => eax = newIdx*5 + newIdx*640 = newIdx*645
                                     * shll $6, %eax => eax = newIdx*41280
                                     * addl %ebx, %eax => eax = newIdx*41280 + newIdx = newIdx*41281
                                     * leal (, %eax, 4), %edx => edx = newIdx*165124
                                     * subl %eax, %edx => edx = newIdx*165124 - newIdx*41281 = newIdx*123843
                                     * Hmm that doesn't work. Let me read more carefully. */
                                    /* Actually it's: newIdx*5 stored in eax, then:
                                     * %eax = newIdx*5, %edx = (newIdx*5)*128 = newIdx*640
                                     * %eax += %edx => newIdx*645
                                     * %eax <<= 6 => newIdx*41280
                                     * %eax += newIdx => newIdx*41281
                                     * %edx = newIdx*41281*4 - newIdx*41281 = newIdx*41281*3 = newIdx*123843
                                     * clients + edx*4 = clients + newIdx*495372 = clients + newIdx*0x78F0C
                                     * YES! That matches CLIENT_STRIDE = 0x78f0c. */

                                    if (*(int *)(clients + (long)newIdx * 0x78f0c) <= 1) {
                                        newIdx++;
                                        continue;
                                    }
                                }

                                /* Check if we need to process old clients first */
                                if (oldIdx2 < from_num_clients) {
                                    int archClientIdx = oldIdx2 + ((cachedSnapshot_t *)cf)->first_client;
                                    int archSlot = signedMod4096(archClientIdx);
                                    serverStatic_t *svs3 = (serverStatic_t *)imp_svs;
                                    cachedClient = (byte *)svs3->cachedSnapshotClients + archSlot * 9992;
                                    int oldClientNum = *(int *)(cachedClient + 4);

                                    if (oldClientNum == newIdx) {
                                        /* Delta from old */
                                        void *clientState = G_GetClientState(newIdx);
                                        MSG_WriteDeltaClient((msg_t *)msg, cachedClient + 4, (byte *)clientState, 1);

                                        /* Write playerstate */
                                        int hasPS = GetFollowPlayerState(newIdx, ps);
                                        if (hasPS) {
                                            MSG_WriteBit1((msg_t *)msg);
                                            MSG_WriteDeltaPlayerstate((msg_t *)msg, (byte *)&((cachedClient_t *)cachedClient)->ps, ps);
                                        } else {
                                            MSG_WriteBit0((msg_t *)msg);
                                        }
                                        oldIdx2++;
                                        newIdx++;
                                        continue;
                                    }

                                    if (newIdx < oldClientNum) {
                                        /* New client, no old data */
                                        void *clientState = G_GetClientState(newIdx);
                                        MSG_WriteDeltaClient((msg_t *)msg, NULL, (byte *)clientState, 1);
                                        int hasPS = GetFollowPlayerState(newIdx, ps);
                                        if (hasPS) {
                                            MSG_WriteBit1((msg_t *)msg);
                                            MSG_WriteDeltaPlayerstate((msg_t *)msg, NULL, ps);
                                        } else {
                                            MSG_WriteBit0((msg_t *)msg);
                                        }
                                        newIdx++;
                                        continue;
                                    }

                                    /* oldClientNum < newIdx: skip old, advance */
                                    if (newIdx > oldClientNum) {
                                        oldIdx2++;
                                    }
                                    continue;
                                }

                                /* No more old clients - treat as new */
                                {
                                    int fakeOldClientNum = 0x270f;
                                    if (newIdx == fakeOldClientNum) {
                                        /* Should not happen normally */
                                        void *clientState = G_GetClientState(newIdx);
                                        MSG_WriteDeltaClient((msg_t *)msg, cachedClient + 4, (byte *)clientState, 1);
                                        int hasPS = GetFollowPlayerState(newIdx, ps);
                                        if (hasPS) {
                                            MSG_WriteBit1((msg_t *)msg);
                                            MSG_WriteDeltaPlayerstate((msg_t *)msg, (byte *)&((cachedClient_t *)cachedClient)->ps, ps);
                                        } else {
                                            MSG_WriteBit0((msg_t *)msg);
                                        }
                                        oldIdx2++;
                                        newIdx++;
                                        continue;
                                    }

                                    /* New client, delta from NULL */
                                    void *clientState = G_GetClientState(newIdx);
                                    MSG_WriteDeltaClient((msg_t *)msg, NULL, (byte *)clientState, 1);
                                    int hasPS = GetFollowPlayerState(newIdx, ps);
                                    if (hasPS) {
                                        MSG_WriteBit1((msg_t *)msg);
                                        MSG_WriteDeltaPlayerstate((msg_t *)msg, NULL, ps);
                                    } else {
                                        MSG_WriteBit0((msg_t *)msg);
                                    }
                                    newIdx++;
                                    continue;
                                }
                            }
                        }

                        /* Write entity end marker */
                        MSG_WriteBit0((msg_t *)msg);

                        /* Write entity deltas for this frame */
                        {
                            int numEnts = sv_p->num_entities;
                            int i;

                            if (numEnts > 0) {
                                for (i = 0; i < numEnts; i++) {
                                    byte *gent = SV_GentityNum(i);
                                    if (((gentity_t *)gent)->r.linked == 0)
                                        continue;

                                    /* Check if entity has locational data */
                                    int contents = ((gentity_t *)gent)->r.broadcastTime;
                                    if (contents == 0) {
                                        /* Check svFlags bit 0 */
                                        if (!(((gentity_t *)gent)->r.svFlags & 1)) {
                                            /* Check if linked to any clusters */
                                            svEntity_t *svEnt = (svEntity_t *)SV_SvEntityForGentity(gent);
                                            if (!(((gentity_t *)gent)->r.svFlags & 0x18)) {
                                                if (svEnt->numClusters == 0)
                                                    continue;
                                            }
                                        }
                                    }

                                    /* Build archived entity */
                                    memcpy(archivedEnt, gent, 0xf0);
                                    /* Build archivedEntityShared_t from gentity's entityShared_t */
                                    {
                                        gentity_t *ge = (gentity_t *)gent;
                                        archivedEntity_t *ae = (archivedEntity_t *)archivedEnt;
                                        ae->r.svFlags = ge->r.svFlags;
                                        if (ge->r.broadcastTime != 0) {
                                            ae->r.svFlags |= 8;
                                        }
                                        ae->r.clientMask[0] = ge->r.clientMask[0];
                                        ae->r.clientMask[1] = ge->r.clientMask[1];
                                        /* Copy absmin */
                                        ae->r.absmin[0] = ge->r.absmin[0];
                                        ae->r.absmin[1] = ge->r.absmin[1];
                                        ae->r.absmin[2] = ge->r.absmin[2];
                                        /* Copy absmax */
                                        ae->r.absmax[0] = ge->r.absmax[0];
                                        ae->r.absmax[1] = ge->r.absmax[1];
                                        ae->r.absmax[2] = ge->r.absmax[2];
                                    }

                                    /* Write delta from baseline */
                                    {
                                        int entNum = ((gentity_t *)gent)->s.number;
                                        byte *baseline = (byte *)&sv_p->svEntities[entNum].baseline;
                                        MSG_WriteDeltaArchivedEntity((msg_t *)msg, baseline, archivedEnt, 1);
                                    }
                                }
                            }
                        }

                        goto write_frame;
                    }
                    break;
                }
                idx--;
            }
        }
    }

    /* No old frame found - write without delta */
    MSG_WriteBit1((msg_t *)msg);
    {
        serverStatic_t *svs2 = (serverStatic_t *)imp_svs;
        MSG_WriteLong((msg_t *)msg, svs2->time);
    }

    /* Set up cached frame for current archive */
    {
        serverStatic_t *svs2 = (serverStatic_t *)imp_svs;
        int frameNum = svs2->nextCachedSnapshotFrames;
        int frameSlot = signedMod512(frameNum);
        byte *cachedFrames = (byte *)svs2->cachedSnapshotFrames;
        cachedSnapshot_t *cachedFrame = (cachedSnapshot_t *)(cachedFrames + frameSlot * 28);

        cachedFrame->archivedFrame = svs2->nextArchivedSnapshotFrames;
        cachedFrame->num_entities = 0;
        cachedFrame->first_entity = svs2->nextCachedSnapshotEntities;
        cachedFrame->num_clients = 0;
        cachedFrame->first_client = svs2->nextCachedSnapshotClients;
        cachedFrame->usesDelta = 0;
        cachedFrame->time = svs2->time;

        /* Write per-client data */
        {
            byte *clients = (byte *)svs2->clients;
            byte *maxclients_dvar = *(byte **)&sv_maxclients_dvar;
            byte *maxclients_val;
            int maxClients;
            int c;

            maxclients_val = *(byte **)maxclients_dvar;
            maxClients = *(int *)(maxclients_val + 8);

            for (c = 0; c < maxClients; c++) {
                /* Check client state > 1 */
                if (*(int *)(clients + (long)c * 0x78f0c) <= 1)
                    continue;

                /* Get archived client slot */
                {
                    int clientArchIdx = svs2->nextCachedSnapshotClients;
                    int clientSlot = signedMod4096(clientArchIdx);
                    byte *archivedClient = (byte *)svs2->cachedSnapshotClients + clientSlot * 9992;

                    /* Copy client state */
                    {
                        void *clientState = G_GetClientState(c);
                        memcpy(archivedClient + 4, clientState, 0x5c);
                    }

                    /* Write delta */
                    MSG_WriteDeltaClient((msg_t *)msg, NULL, archivedClient + 4, 1);

                    /* Write playerstate */
                    {
                        int hasPS = GetFollowPlayerState(c, (byte *)&((cachedClient_t *)archivedClient)->ps);
                        *(int *)archivedClient = hasPS;

                        if (hasPS) {
                            MSG_WriteBit1((msg_t *)msg);
                            MSG_WriteDeltaPlayerstate((msg_t *)msg, NULL, (byte *)&((cachedClient_t *)archivedClient)->ps);
                        } else {
                            MSG_WriteBit0((msg_t *)msg);
                        }
                    }

                    /* Increment archivedClientNumIndex */
                    {
                        serverStatic_t *svs3 = (serverStatic_t *)imp_svs;
                        int newClientIdx = svs3->nextCachedSnapshotClients + 1;
                        svs3->nextCachedSnapshotClients = newClientIdx;
                        if (newClientIdx > 0x7ffffffd) {
                            Com_Error(0, str_002b0440);
                        }
                    }

                    /* Increment cachedFrame numClients */
                    cachedFrame = (cachedSnapshot_t *)((byte *)((serverStatic_t *)imp_svs)->cachedSnapshotFrames + frameSlot * 28);
                    cachedFrame->num_clients += 1;

                    /* Re-read maxclients_dvar */
                    maxclients_val = *(byte **)(*(byte **)&sv_maxclients_dvar);
                }
            }
        }

        /* Write client end marker */
        MSG_WriteBit0((msg_t *)msg);

        /* Write entity data */
        {
            int numEnts = sv_p->num_entities;
            int i;

            if (numEnts > 0) {
                for (i = 0; i < numEnts; i++) {
                    byte *gent = SV_GentityNum(i);
                    if (((gentity_t *)gent)->r.linked == 0)
                        continue;

                    int entityContents = ((gentity_t *)gent)->r.broadcastTime;
                    if (entityContents == 0) {
                        if (!(((gentity_t *)gent)->r.svFlags & 1)) {
                            svEntity_t *svEnt = (svEntity_t *)SV_SvEntityForGentity(gent);
                            if (!(((gentity_t *)gent)->r.svFlags & 0x18)) {
                                if (svEnt->numClusters == 0)
                                    continue;
                            }
                        }
                    }

                    /* Write archived entity */
                    {
                        serverStatic_t *svs4 = (serverStatic_t *)imp_svs;
                        int entArchIdx = svs4->nextCachedSnapshotEntities;
                        int entSlot = signedMod16384(entArchIdx);

                        byte *archivedEntSlot = (byte *)svs4->cachedSnapshotEntities + entSlot * 276;

                        /* Copy entity state */
                        memcpy(archivedEntSlot, gent, 0xf0);
                        /* Build archivedEntityShared_t from gentity's entityShared_t */
                        {
                            gentity_t *ge = (gentity_t *)gent;
                            archivedEntity_t *ae = (archivedEntity_t *)archivedEntSlot;
                            ae->r.svFlags = ge->r.svFlags;
                            if (ge->r.broadcastTime != 0) {
                                ae->r.svFlags |= 8;
                            }
                            ae->r.clientMask[0] = ge->r.clientMask[0];
                            ae->r.clientMask[1] = ge->r.clientMask[1];
                            /* absmin */
                            ae->r.absmin[0] = ge->r.absmin[0];
                            ae->r.absmin[1] = ge->r.absmin[1];
                            ae->r.absmin[2] = ge->r.absmin[2];
                            /* absmax */
                            ae->r.absmax[0] = ge->r.absmax[0];
                            ae->r.absmax[1] = ge->r.absmax[1];
                            ae->r.absmax[2] = ge->r.absmax[2];
                        }

                        /* Write delta from baseline */
                        {
                            int entNum = ((gentity_t *)gent)->s.number;
                            byte *baseline = (byte *)&sv_p->svEntities[entNum].baseline;
                            MSG_WriteDeltaArchivedEntity((msg_t *)msg, baseline, archivedEntSlot, 1);
                        }

                        /* Increment archivedEntNumIndex */
                        {
                            serverStatic_t *svs5 = (serverStatic_t *)imp_svs;
                            int newEntIdx = svs5->nextCachedSnapshotEntities + 1;
                            svs5->nextCachedSnapshotEntities = newEntIdx;
                            if (newEntIdx > 0x7ffffffd) {
                                Com_Error(0, str_002b0468);
                            }
                        }

                        /* Increment cachedFrame numEntities */
                        {
                            cachedSnapshot_t *cf2 = (cachedSnapshot_t *)((byte *)((serverStatic_t *)imp_svs)->cachedSnapshotFrames + frameSlot * 28);
                            cf2->num_entities += 1;
                        }
                    }
                }
            }
        }

        /* Increment archivedFrameNum */
        {
            serverStatic_t *svs5 = (serverStatic_t *)imp_svs;
            int newFrameNum = svs5->nextCachedSnapshotFrames + 1;
            svs5->nextCachedSnapshotFrames = newFrameNum;
            if (newFrameNum > 0x7ffffffd) {
                Com_Error(0, str_002b0490);
            }
        }
    }

write_frame:
    /* Write end-of-entities marker (0x3ff = 10 bits) */
    MSG_WriteBits((msg_t *)msg, 0x3ff, 10);

    /* Check for message overflow */
    {
        int overflowed = *(int *)msg; /* msg.overflowed at offset 0 */
        if (overflowed != 0) {
            Com_DPrintf(str_002b04b8); /* "SV_ArchiveSnapshot: ignoring snapshot because it overflowed.\n" */
            goto cleanup;
        }
    }

    /* Store archived frame data in ring buffer */
    {
        serverStatic_t *svs2 = (serverStatic_t *)imp_svs;
        int archivedFrameCount = svs2->nextArchivedSnapshotFrames;
        int bufIndex;
        byte *entParts;
        int bufOffset;
        int msgDataLen;
        int bufSize;
        int remaining;

        /* Compute ring buffer index for archivedEntityParts */
        bufIndex = archivedFrameCount % 1200;
        /* The asm uses: imull $0x1b4e81b5 => division by 1200 via magic number multiplication */
        {
            long long tmp = (long long)archivedFrameCount * 0x1b4e81b5;
            int q = (int)(tmp >> 39); /* approximate, but matches the asm's sarl $7 after imull */
            if (archivedFrameCount < 0) q--;
            bufIndex = archivedFrameCount - q * 1200;
        }

        entParts = (byte *)svs2->archivedSnapshotFrames;
        byte *partEntry = entParts + bufIndex * 8;

        bufOffset = svs2->nextArchivedSnapshotBuffer;
        *(int *)partEntry = bufOffset; /* startOffset */

        /* msg data offset and length */
        msgDataLen = ((msg_t *)msg)->cursize;
        *(int *)(partEntry + 4) = msgDataLen;

        /* Copy message data to archived entity buffer with ring wrap */
        bufSize = 0x2000000; /* 33554432 */
        remaining = signedMod33554432(bufOffset);

        if (remaining + msgDataLen <= bufSize) {
            /* No wrap needed */
            byte *archBuf = svs2->archivedSnapshotBuffer;
            byte *msgData = ((msg_t *)msg)->data;
            memcpy(archBuf + remaining, msgData, msgDataLen);
        } else {
            /* Wrap around */
            int firstPart = bufSize - remaining;
            byte *archBuf = svs2->archivedSnapshotBuffer;
            byte *msgData = *(byte **)(msg + 4);

            memcpy(archBuf + remaining, msgData, firstPart);
            memcpy(archBuf, msgData + firstPart, msgDataLen - firstPart);
        }
    }

    /* Increment archivedFrameCount */
    {
        serverStatic_t *svs2 = (serverStatic_t *)imp_svs;
        int newCount = svs2->nextArchivedSnapshotFrames + 1;
        svs2->nextArchivedSnapshotFrames = newCount;
        if (newCount > 0x7ffffffd) {
            Com_Error(0, str_002b0520);
        }
    }

cleanup:
    ZN10LargeLocalD1Ev(msg_buf_large_local);
}
