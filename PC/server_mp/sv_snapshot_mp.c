/* Converted to C from ASM: sv_snapshot_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_snapshot_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern int startOffset; /* startOffset */
extern int endOffset; /* endOffset */

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
    byte *cl = (byte *)client;
    int reliableAck = *(int *)(cl + CLIENT_RELIABLEACK);
    int reliableSeq = *(int *)(cl + CLIENT_RELIABLESEQUENCE);
    byte *showdvar = *(byte **)&sv_showcommands_dvar;
    int i;
    int idx;
    char *cmdStr;

    if (reliableAck + 1 < reliableSeq) {
        if (*(byte *)(*(byte **)showdvar + 8) != 0) {
            Com_Printf("Client %s has the following un-ack'd reliable commands:\n", cl + CLIENT_NAME);
            reliableAck = *(int *)(cl + CLIENT_RELIABLEACK);
        }
    }

    for (i = reliableAck + 1; i <= reliableSeq; i++) {
        MSG_WriteByte(msg, 4);
        MSG_WriteLong(msg, i);
        idx = i & CLIENT_CMDENTRY_MASK;
        cmdStr = (char *)(cl + CLIENT_CMDENTRY_BASE + idx * CLIENT_CMDENTRY_SIZE + CLIENT_CMDENTRY_STROFF);
        MSG_WriteString(msg, cmdStr);
        if (*(byte *)(*(byte **)*(byte **)&sv_showcommands_dvar + 8) != 0) {
            Com_Printf("%i: %s\n", i - *(int *)(cl + CLIENT_RELIABLEACK) - 1, cmdStr);
        }
    }

    *(int *)(cl + CLIENT_RELIABLESENT) = reliableSeq;
}

/* line 836 */
static __attribute_regparm__(1)
cachedSnapshot_t * SV_GetCachedSnapshotInternal(int archivedFrame)
{
    byte msg_buf_ll[16]; /* LargeLocal */
    byte *msg_buf;
    msg_t msg;
    byte *svs;
    cachedSnapshot_t *cachedFrame = NULL;
    byte *partEntry;

    LargeLocal_LargeLocal(msg_buf_ll, 0x20000);
    msg_buf = LargeLocal_GetBuf(msg_buf_ll);

    svs = (byte *)imp_svs;

    /* Compute archived entity part entry (archivedFrame % 1200, stride 8) */
    partEntry = *(byte **)(svs + SVS_ARCHIVEDENTITYPARTS) + (archivedFrame % 1200) * 8;

    /* Check data freshness */
    if (*(int *)partEntry < *(int *)(svs + SVS_ARCHIVEDENTITYBUFSIZE) - 0x2000000)
        goto return_null;

    /* Search existing cached frames */
    {
        int searchStart = *(int *)(svs + SVS_NEXTARCHIVEDFRAMENUM);
        int searchEnd = searchStart - 0x200;
        byte *cfBase;
        int i;

        if (searchEnd < 0) searchEnd = 0;

        if (searchStart - 1 >= searchEnd) {
            cfBase = *(byte **)((byte *)imp_svs + SVS_CACHEDFRAMES);
            for (i = searchStart - 1; i >= searchEnd; i--) {
                cachedSnapshot_t *cf = (cachedSnapshot_t *)(cfBase + (i % 512) * 28);
                if (cf->archivedFrame == archivedFrame) {
                    cachedFrame = cf;
                    svs = (byte *)imp_svs;
                    if (cf->first_entity >= *(int *)(svs + SVS_ARCHIVEDENTNUMINDEX) - 0x4000) {
                        if (cf->first_client >= *(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX) - (int)&__mh_execute_header) {
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
            svs = (byte *)imp_svs;
            entBuf = *(byte **)(svs + SVS_ARCHIVEDENTITYBUF);
            memcpy(msg.data, entBuf + dataOffset, msg.cursize);
        } else {
            svs = (byte *)imp_svs;
            entBuf = *(byte **)(svs + SVS_ARCHIVEDENTITYBUF);
            memcpy(msg.data, entBuf + dataOffset, remaining);
            memcpy(msg.data + remaining, entBuf, msg.cursize - remaining);
        }
    }

    if (MSG_ReadBit(&msg) == 0) {
        /* Delta decode from old archived frame */
        int oldArchivedFrame = MSG_ReadLong(&msg);
        cachedSnapshot_t *oldCachedFrame;

        svs = (byte *)imp_svs;
        if (oldArchivedFrame < *(int *)(svs + SVS_ARCHIVEDFRAMECOUNT) - 0x4b0)
            goto return_null;

        /* Validate old data freshness */
        {
            byte *oldPart = *(byte **)(svs + SVS_ARCHIVEDENTITYPARTS) + (oldArchivedFrame % 1200) * 8;
            if (*(int *)oldPart < *(int *)(svs + SVS_ARCHIVEDENTITYBUFSIZE) - 0x2000000)
                goto return_null;
        }

        oldCachedFrame = SV_GetCachedSnapshotInternal(oldArchivedFrame);
        if (oldCachedFrame == NULL)
            goto return_null;

        /* Allocate new cached frame slot */
        {
            int frameIdx = *(int *)(svs + SVS_NEXTARCHIVEDFRAMENUM) % 512;
            cachedFrame = (cachedSnapshot_t *)(*(byte **)(svs + SVS_CACHEDFRAMES) + frameIdx * 28);
        }
        cachedFrame->archivedFrame = archivedFrame;
        cachedFrame->num_entities = 0;
        cachedFrame->first_entity = *(int *)(svs + SVS_ARCHIVEDENTNUMINDEX);
        cachedFrame->num_clients = 0;
        cachedFrame->first_client = *(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX);
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
                oldCachedClient = *(byte **)(svs + SVS_ARCHIVEDCLIENTDATA) + firstIdx * CACHEDCLIENT_STRIDE;
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
                        byte *cdata = *(byte **)((byte *)imp_svs + SVS_ARCHIVEDCLIENTDATA);
                        int nextIdx = (oldCachedFrame->first_client + oldindex) % 0x1000;
                        oldCachedClient = cdata + nextIdx * CACHEDCLIENT_STRIDE;
                        oldClientNum = *(int *)(oldCachedClient + 4);
                    }
                }

                svs = (byte *)imp_svs;
                clientIdx = *(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX) % 0x1000;
                newCachedClient = *(byte **)(svs + SVS_ARCHIVEDCLIENTDATA) + clientIdx * CACHEDCLIENT_STRIDE;

                if (oldClientNum == newClientNum) {
                    /* Delta from old cached client */
                    MSG_ReadDeltaClient(&msg, oldCachedClient + 4, newCachedClient + 4, newClientNum);
                    *(int *)newCachedClient = MSG_ReadBit(&msg);
                    if (*(int *)newCachedClient != 0)
                        MSG_ReadDeltaPlayerstate(&msg, oldCachedClient + 0x60, newCachedClient + 0x60);

                    svs = (byte *)imp_svs;
                    *(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX) += 1;
                    if (*(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX) > 0x7ffffffd)
                        Com_Error(0, "SV_GetCachedSnapshot: too many clients");

                    cachedFrame->num_clients++;

                    /* Advance old client */
                    oldindex++;
                    if (oldindex >= oldCachedFrame->num_clients) {
                        oldClientNum = 0x1869f;
                    } else {
                        byte *cdata = *(byte **)((byte *)imp_svs + SVS_ARCHIVEDCLIENTDATA);
                        int nextIdx = (oldCachedFrame->first_client + oldindex) % 0x1000;
                        oldCachedClient = cdata + nextIdx * CACHEDCLIENT_STRIDE;
                        oldClientNum = *(int *)(oldCachedClient + 4);
                    }
                } else {
                    /* New client not in old frame - delta from NULL */
                    MSG_ReadDeltaClient(&msg, NULL, newCachedClient + 4, newClientNum);
                    *(int *)newCachedClient = MSG_ReadBit(&msg);
                    if (*(int *)newCachedClient != 0)
                        MSG_ReadDeltaPlayerstate(&msg, NULL, newCachedClient + 0x60);

                    svs = (byte *)imp_svs;
                    *(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX) += 1;
                    if (*(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX) > 0x7ffffffd)
                        Com_Error(0, "SV_GetCachedSnapshot: too many clients");

                    cachedFrame->num_clients++;
                }
            }
        }
    } else {
        /* Full fresh decode (no delta base) */
        svs = (byte *)imp_svs;

        {
            int frameIdx = *(int *)(svs + SVS_NEXTARCHIVEDFRAMENUM) % 512;
            cachedFrame = (cachedSnapshot_t *)(*(byte **)(svs + SVS_CACHEDFRAMES) + frameIdx * 28);
        }
        cachedFrame->archivedFrame = archivedFrame;
        cachedFrame->num_entities = 0;
        cachedFrame->first_entity = *(int *)(svs + SVS_ARCHIVEDENTNUMINDEX);
        cachedFrame->num_clients = 0;
        cachedFrame->first_client = *(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX);
        cachedFrame->usesDelta = 0;
        cachedFrame->time = MSG_ReadLong(&msg);

        /* Decode clients fresh (no delta base) */
        while (MSG_ReadBit(&msg) != 0) {
            int clientNum = MSG_ReadBits(&msg, 6);
            int clientIdx;
            byte *newCachedClient;

            if (msg.readcount > msg.cursize)
                Com_Error(1, "SV_GetCachedSnapshot: msg overflow");

            clientIdx = *(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX) % 0x1000;
            newCachedClient = *(byte **)(svs + SVS_ARCHIVEDCLIENTDATA) + clientIdx * CACHEDCLIENT_STRIDE;

            MSG_ReadDeltaClient(&msg, NULL, newCachedClient + 4, clientNum);
            *(int *)newCachedClient = MSG_ReadBit(&msg);
            if (*(int *)newCachedClient != 0)
                MSG_ReadDeltaPlayerstate(&msg, NULL, newCachedClient + 0x60);

            *(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX) += 1;
            if (*(int *)(svs + SVS_ARCHIVEDCLIENTNUMINDEX) > 0x7ffffffd)
                Com_Error(0, "SV_GetCachedSnapshot: too many clients");

            cachedFrame->num_clients++;
        }
    }

    /* Decode entities (shared between delta and fresh paths) */
    while (1) {
        int entNum = MSG_ReadBits(&msg, 10);
        int entIdx;
        byte *archivedEnt;
        byte *sv;

        if (entNum == 0x3ff)
            break;

        if (msg.readcount > msg.cursize)
            Com_Error(1, "SV_GetCachedSnapshot: msg overflow");

        svs = (byte *)imp_svs;
        entIdx = *(int *)(svs + SVS_ARCHIVEDENTNUMINDEX) % 0x4000;
        archivedEnt = *(byte **)(svs + SVS_ARCHIVEDENTITYDATA) + entIdx * 276;

        sv = (byte *)imp_sv;
        MSG_ReadDeltaArchivedEntity(&msg, sv + 0x241c + entNum * 372, archivedEnt, entNum);

        *(int *)(svs + SVS_ARCHIVEDENTNUMINDEX) += 1;
        if (*(int *)(svs + SVS_ARCHIVEDENTNUMINDEX) > 0x7ffffffd)
            Com_Error(0, "SV_GetCachedSnapshot: too many entities");

        cachedFrame->num_entities++;
    }

    /* Increment archived frame number */
    svs = (byte *)imp_svs;
    *(int *)(svs + SVS_NEXTARCHIVEDFRAMENUM) += 1;
    if (*(int *)(svs + SVS_NEXTARCHIVEDFRAMENUM) > 0x7ffffffd)
        Com_Error(0, "SV_GetCachedSnapshot: too many frames");

    goto cleanup;

return_null:
    cachedFrame = NULL;
cleanup:
    ZN10LargeLocalD1Ev(msg_buf_ll);
    return cachedFrame;
}

/* line 1772 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void SV_ArchiveSnapshot(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1772 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x282c, %esp\n"
        /* { scope 1 */
        "movl $0x20000, 4(%esp)\n" /* line 1795 */
        "leal -0x1c(%ebp), %eax\n" /* msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* msg_buf_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %edx\n"
        "movl imp_sv, %eax\n" /* line 1800 */
        "cmpl $2, (%eax)\n"
        "je .Lf192a4c_00192a98\n"
        ".Lf192a4c_00192a82:\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 2067 | msg_buf_large_local */
        "movl %ecx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x282c, %esp\n" /* line 2068 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf192a4c_00192a98:\n"
        "movl imp_svs, %edi\n" /* line 1803 | c */
        "movl 0x28(%edi), %eax\n" /* c */
        "testl %eax, %eax\n"
        "je .Lf192a4c_00192a82\n"
        "movl $0x20000, 8(%esp)\n" /* line 1814 */
        "movl %edx, 4(%esp)\n"
        "leal -0x34(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_Init\n"
        "movl 0x44(%edi), %edx\n" /* line 1816 | c */
        "movl %edx, %esi\n" /* line 1817 | oldindex */
        "subl $0x200, %esi\n" /* oldindex */
        "movl $0, %eax\n"
        "cmovsl %eax, %esi\n" /* oldindex */
        "movl imp_sv_fps, %eax\n" /* line 1820 */
        "movl (%eax), %eax\n"
        "movl 0x2c(%edi), %ebx\n" /* c, newnum */
        "subl 8(%eax), %ebx\n" /* newnum */
        "subl $1, %edx\n" /* line 1822 */
        "cmpl %edx, %esi\n" /* oldindex */
        "jg .Lf192a4c_00192b30\n"
        "movl 0x50(%edi), %edi\n" /* line 1824 | c */
        "movl %edi, -0x2800(%ebp)\n" /* c */
        "jmp .Lf192a4c_00192b18\n"
        ".Lf192a4c_00192aee:\n"
        "leal (, %ecx, 4), %eax\n"
        "shll $5, %ecx\n"
        "subl %eax, %ecx\n"
        "movl -0x2800(%ebp), %edi\n" /* c */
        "addl %ecx, %edi\n" /* c */
        "cmpl (%edi), %ebx\n" /* line 1825 | c, newnum */
        "jg .Lf192a4c_00192b11\n"
        "movl 0x18(%edi), %eax\n" /* line 1827 | c */
        "testl %eax, %eax\n"
        "je .Lf192a4c_00193093\n"
        ".Lf192a4c_00192b11:\n"
        "subl $1, %edx\n" /* line 1822 */
        "cmpl %edx, %esi\n" /* oldindex */
        "jg .Lf192a4c_00192b30\n"
        ".Lf192a4c_00192b18:\n"
        "movl %edx, %ecx\n" /* line 1824 */
        "andl $0x800001ff, %ecx\n"
        "jns .Lf192a4c_00192aee\n"
        "subl $1, %ecx\n"
        "orl $0xfffffe00, %ecx\n"
        "addl $1, %ecx\n"
        "jmp .Lf192a4c_00192aee\n"
        ".Lf192a4c_00192b30:\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1944 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit1\n"
        "movl imp_svs, %ebx\n" /* line 1945 | newnum */
        "movl 4(%ebx), %eax\n" /* newnum */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl 0x44(%ebx), %edx\n" /* line 1948 | newnum */
        "andl $0x800001ff, %edx\n"
        "js .Lf192a4c_0019302e\n"
        ".Lf192a4c_00192b62:\n"
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x50(%ebx), %ecx\n" /* newnum */
        "addl %ecx, %edx\n"
        "movl %edx, -0x2810(%ebp)\n" /* cachedFrame */
        "movl 0x2c(%ebx), %eax\n" /* line 1950 | newnum */
        "movl %eax, (%edx)\n"
        "movl $0, 8(%edx)\n" /* line 1951 */
        "movl 0x3c(%ebx), %eax\n" /* line 1952 | newnum */
        "movl %eax, 0xc(%edx)\n"
        "movl $0, 0x10(%edx)\n" /* line 1953 */
        "movl 0x40(%ebx), %eax\n" /* line 1954 | newnum */
        "movl %eax, 0x14(%edx)\n"
        "movl $0, 0x18(%edx)\n" /* line 1955 */
        "movl 4(%ebx), %eax\n" /* line 1956 | newnum */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebx), %edi\n" /* line 1958 | newnum, c */
        "movl imp_sv_maxclients, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf192a4c_00192d11\n"
        "movl $0, -0x27fc(%ebp)\n"
        "movl %ebx, -0x2814(%ebp)\n" /* newnum */
        "movl %ebx, -0x2818(%ebp)\n" /* newnum */
        "movl %edx, -0x281c(%ebp)\n"
        "jmp .Lf192a4c_00192c43\n"
        ".Lf192a4c_00192bd9:\n"
        "leal -0x34(%ebp), %eax\n" /* line 1970 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBit1\n"
        "movl %ebx, 8(%esp)\n" /* line 1971 | newnum */
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "movl -0x2814(%ebp), %edx\n" /* line 1978 */
        "movl 0x40(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x40(%edx)\n"
        "cmpl $0x7ffffffd, %eax\n" /* line 1980 */
        "jg .Lf192a4c_00192cf8\n"
        ".Lf192a4c_00192c15:\n"
        "movl -0x2810(%ebp), %ecx\n" /* line 1982 | cachedFrame */
        "addl $1, 0x10(%ecx)\n"
        "movl -0x281c(%ebp), %edx\n"
        ".Lf192a4c_00192c25:\n"
        "addl $1, -0x27fc(%ebp)\n" /* line 1958 */
        "addl $0x78f0c, %edi\n" /* c */
        "movl (%edx), %eax\n"
        "movl -0x27fc(%ebp), %ecx\n"
        "cmpl 8(%eax), %ecx\n"
        "jge .Lf192a4c_00192d11\n"
        ".Lf192a4c_00192c43:\n"
        "cmpl $1, (%edi)\n" /* line 1960 | c */
        "jle .Lf192a4c_00192c25\n"
        "movl -0x2818(%ebp), %ecx\n" /* line 1963 */
        "movl 0x40(%ecx), %edx\n"
        "andl $0x80000fff, %edx\n"
        "js .Lf192a4c_00192e30\n"
        ".Lf192a4c_00192c5d:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl 0x4c(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %esi\n" /* oldindex */
        "movl -0x27fc(%ebp), %eax\n" /* line 1965 */
        "movl %eax, (%esp)\n"
        "calll G_GetClientState\n"
        "leal 4(%esi), %ebx\n" /* oldindex, newnum */
        "movl $0x5c, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll memcpy\n"
        "movl $1, 0xc(%esp)\n" /* line 1966 */
        "movl %ebx, 8(%esp)\n" /* newnum */
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "leal 0x60(%esi), %ebx\n" /* line 1967 | oldindex, newnum */
        "movl %ebx, 4(%esp)\n" /* newnum */
        "movl -0x27fc(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll GetFollowPlayerState\n"
        "movl %eax, (%esi)\n" /* oldindex */
        "testl %eax, %eax\n" /* line 1968 */
        "jne .Lf192a4c_00192bd9\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1975 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "movl -0x2814(%ebp), %edx\n" /* line 1978 */
        "movl 0x40(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x40(%edx)\n"
        "cmpl $0x7ffffffd, %eax\n" /* line 1980 */
        "jle .Lf192a4c_00192c15\n"
        ".Lf192a4c_00192cf8:\n"
        "movl $str_002b0440, 4(%esp)\n" /* line 1981 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192a4c_00192c15\n"
        ".Lf192a4c_00192d11:\n"
        "leal -0x34(%ebp), %eax\n" /* line 1985 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "movl imp_sv, %eax\n" /* line 1987 */
        "movl 0x5f424(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf192a4c_00192ea9\n"
        ".Lf192a4c_00192d2f:\n"
        "movl imp_svs, %eax\n" /* line 2026 */
        "movl 0x44(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0x44(%eax)\n"
        "cmpl $0x7ffffffd, %edx\n" /* line 2028 */
        "jg .Lf192a4c_00192e90\n"
        ".Lf192a4c_00192d49:\n"
        "movl $0xa, 8(%esp)\n" /* line 2032 */
        "movl $0x3ff, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBits\n"
        "movl -0x34(%ebp), %ebx\n" /* line 2034 | msg, newnum */
        "testl %ebx, %ebx\n" /* newnum */
        "jne .Lf192a4c_00192e7f\n"
        "movl imp_svs, %edi\n" /* line 2041 | c */
        "movl 0x2c(%edi), %ecx\n" /* c */
        "movl $0x1b4e81b5, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $7, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %eax, %ecx\n"
        "movl 0x30(%edi), %eax\n" /* c */
        "leal (%eax, %ecx, 8), %ecx\n"
        "movl 0x38(%edi), %eax\n" /* line 2042 | c */
        "movl %eax, (%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 2043 */
        "movl %eax, 4(%ecx)\n"
        "movl 0x38(%edi), %eax\n" /* line 2044 | c */
        "movl %eax, %ebx\n" /* newnum */
        "andl $0x81ffffff, %ebx\n" /* newnum */
        "js .Lf192a4c_00193082\n"
        ".Lf192a4c_00192dbc:\n"
        "movl -0x28(%ebp), %edx\n" /* line 2046 */
        "addl %edx, %eax\n"
        "movl %eax, 0x38(%edi)\n" /* c */
        "cmpl $0x7ffffffd, %eax\n" /* line 2048 */
        "jg .Lf192a4c_00193012\n"
        ".Lf192a4c_00192dcf:\n"
        "movl $0x2000000, %esi\n" /* line 2051 | oldindex */
        "subl %ebx, %esi\n" /* newnum, oldindex */
        "cmpl %edx, %esi\n" /* line 2052 | oldindex */
        "jl .Lf192a4c_00192e47\n"
        "addl 0x34(%edi), %ebx\n" /* line 2054 | c, newnum */
        "movl %edx, 8(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll memcpy\n"
        ".Lf192a4c_00192df0:\n"
        "movl imp_svs, %eax\n" /* line 2062 */
        "movl 0x2c(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0x2c(%eax)\n"
        "cmpl $0x7ffffffd, %edx\n" /* line 2064 */
        "jle .Lf192a4c_00192e1a\n"
        "movl $str_002b0520, 4(%esp)\n" /* line 2065 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf192a4c_00192e1a:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2067 | msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x282c, %esp\n" /* line 2068 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf192a4c_00192e30:\n"
        "subl $1, %edx\n" /* line 1963 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "movl -0x2818(%ebp), %ecx\n"
        "jmp .Lf192a4c_00192c5d\n"
        ".Lf192a4c_00192e47:\n"
        "addl 0x34(%edi), %ebx\n" /* line 2058 | c, newnum */
        "movl %esi, 8(%esp)\n" /* oldindex */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll memcpy\n"
        "movl 0x34(%edi), %ecx\n" /* line 2059 | c */
        "movl -0x28(%ebp), %edx\n"
        "subl %esi, %edx\n" /* oldindex */
        "movl %esi, %eax\n" /* oldindex */
        "addl -0x30(%ebp), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf192a4c_00192df0\n"
        ".Lf192a4c_00192e7f:\n"
        "movl $str_002b04b8, (%esp)\n" /* line 2037 */
        "calll Com_DPrintf\n"
        "jmp .Lf192a4c_00192a82\n"
        ".Lf192a4c_00192e90:\n"
        "movl $str_002b0490, 4(%esp)\n" /* line 2029 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192a4c_00192d49\n"
        ".Lf192a4c_00192ea9:\n"
        "xorl %edi, %edi\n" /* line 1987 | c */
        "jmp .Lf192a4c_00192ece\n"
        ".Lf192a4c_00192ead:\n"
        "testb $1, 0xf2(%eax)\n" /* line 1997 */
        "je .Lf192a4c_0019303f\n"
        ".Lf192a4c_00192eba:\n"
        "addl $1, %edi\n" /* line 1987 | c */
        "movl imp_sv, %eax\n"
        "cmpl 0x5f424(%eax), %edi\n" /* c */
        "jge .Lf192a4c_00192d2f\n"
        ".Lf192a4c_00192ece:\n"
        "movl %edi, (%esp)\n" /* line 1989 | c */
        "calll SV_GentityNum\n"
        "movl %eax, %ebx\n" /* newnum */
        "cmpb $0, 0xf0(%eax)\n" /* line 1990 */
        "je .Lf192a4c_00192eba\n"
        "movl 0x100(%eax), %esi\n" /* line 1995 | oldindex */
        "testl %esi, %esi\n" /* oldindex */
        "je .Lf192a4c_00192ead\n"
        ".Lf192a4c_00192eeb:\n"
        "movl imp_svs, %ecx\n" /* line 2005 */
        "movl 0x3c(%ecx), %edx\n"
        "andl $0x80003fff, %edx\n"
        "js .Lf192a4c_0019306b\n"
        ".Lf192a4c_00192f00:\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x48(%ecx), %edx\n"
        "leal (%edx, %eax, 4), %esi\n" /* oldindex */
        "movl $0xf0, 8(%esp)\n" /* line 2007 */
        "movl %ebx, 4(%esp)\n" /* newnum */
        "movl %esi, (%esp)\n" /* oldindex */
        "calll memcpy\n"
        "movzbl 0xf2(%ebx), %eax\n" /* line 2008 | newnum */
        "movl %eax, 0xf0(%esi)\n" /* oldindex */
        "movl 0x100(%ebx), %edx\n" /* line 2009 | newnum */
        "testl %edx, %edx\n"
        "je .Lf192a4c_00192f44\n"
        "orl $8, %eax\n" /* line 2010 */
        "movl %eax, 0xf0(%esi)\n" /* oldindex */
        ".Lf192a4c_00192f44:\n"
        "movl 0xf4(%ebx), %eax\n" /* line 2011 | newnum */
        "movl %eax, 0xf4(%esi)\n" /* oldindex */
        "movl 0xf8(%ebx), %eax\n" /* line 2012 | newnum */
        "movl %eax, 0xf8(%esi)\n" /* oldindex */
        "leal 0xfc(%esi), %ecx\n" /* line 2013 | oldindex, to */
        "leal 0x120(%ebx), %edx\n" /* newnum, from */
        /* { scope 2 */
        "movl 0x120(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0xfc(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x108(%esi), %ecx\n" /* line 2014 | oldindex, to */
        "leal 0x12c(%ebx), %edx\n" /* newnum, from */
        /* { scope 2 */
        "movl 0x12c(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x108(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $1, 0xc(%esp)\n" /* line 2016 */
        "movl %esi, 8(%esp)\n" /* oldindex */
        "movl (%ebx), %eax\n" /* newnum */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl imp_sv, %eax\n"
        "leal 0x241c(%eax, %edx, 4), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaArchivedEntity\n"
        "movl imp_svs, %edx\n" /* line 2018 */
        "movl 0x3c(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x3c(%edx)\n"
        "cmpl $0x7ffffffd, %eax\n" /* line 2021 */
        "jg .Lf192a4c_00192ffc\n"
        ".Lf192a4c_00192fed:\n"
        "movl -0x2810(%ebp), %ecx\n" /* line 2023 | cachedFrame */
        "addl $1, 8(%ecx)\n"
        "jmp .Lf192a4c_00192eba\n"
        ".Lf192a4c_00192ffc:\n"
        "movl $str_002b0468, 4(%esp)\n" /* line 2022 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192a4c_00192fed\n"
        ".Lf192a4c_00193012:\n"
        "movl $str_002b04f8, 4(%esp)\n" /* line 2049 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x28(%ebp), %edx\n"
        "jmp .Lf192a4c_00192dcf\n"
        ".Lf192a4c_0019302e:\n"
        "subl $1, %edx\n" /* line 1948 */
        "orl $0xfffffe00, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192a4c_00192b62\n"
        ".Lf192a4c_0019303f:\n"
        "movl %eax, (%esp)\n" /* line 2000 */
        "calll SV_SvEntityForGentity\n"
        "movl %eax, %edx\n"
        "movzbl 0xf2(%ebx), %eax\n" /* line 2001 | newnum */
        "testb $0x18, %al\n"
        "jne .Lf192a4c_00192eeb\n"
        "movl 0x118(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf192a4c_00192eba\n"
        "jmp .Lf192a4c_00192eeb\n"
        ".Lf192a4c_0019306b:\n"
        "subl $1, %edx\n" /* line 2005 */
        "orl $0xffffc000, %edx\n"
        "addl $1, %edx\n"
        "movl imp_svs, %ecx\n"
        "jmp .Lf192a4c_00192f00\n"
        ".Lf192a4c_00193082:\n"
        "subl $1, %ebx\n" /* line 2044 | newnum */
        "orl $0xfe000000, %ebx\n" /* newnum */
        "addl $1, %ebx\n" /* newnum */
        "jmp .Lf192a4c_00192dbc\n"
        ".Lf192a4c_00193093:\n"
        "movl imp_svs, %ebx\n" /* line 1829 | newnum */
        "movl 0x3c(%ebx), %eax\n" /* newnum */
        "subl $0x4000, %eax\n"
        "cmpl %eax, 0xc(%edi)\n" /* c */
        "jl .Lf192a4c_00192b30\n"
        "movl 0x40(%ebx), %eax\n" /* line 1831 | newnum */
        "subl $__mh_execute_header, %eax\n"
        "cmpl %eax, 0x14(%edi)\n" /* c */
        "jl .Lf192a4c_00192b30\n"
        "leal -0x34(%ebp), %eax\n" /* line 1834 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "movl (%edi), %eax\n" /* line 1835 | c */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl 4(%ebx), %eax\n" /* line 1836 | newnum */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl imp_sv_maxclients, %eax\n" /* line 1838 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x2808(%ebp)\n" /* to_num_clients */
        "movl 0x10(%edi), %eax\n" /* line 1839 | c */
        "movl %eax, -0x2804(%ebp)\n" /* from_num_clients */
        "movl $0, -0x280c(%ebp)\n" /* cachedClient */
        "xorl %ebx, %ebx\n" /* newnum */
        "xorl %esi, %esi\n" /* oldindex */
        ".Lf192a4c_00193110:\n"
        "cmpl -0x2808(%ebp), %ebx\n" /* line 1843 | to_num_clients, newnum */
        "jl .Lf192a4c_00193173\n"
        ".Lf192a4c_00193118:\n"
        "cmpl -0x2804(%ebp), %esi\n" /* from_num_clients, oldindex */
        "jge .Lf192a4c_001932d5\n"
        ".Lf192a4c_00193124:\n"
        "movl %esi, %eax\n" /* line 1860 | oldindex */
        "addl 0x14(%edi), %eax\n" /* c */
        "movl %eax, %edx\n"
        "andl $0x80000fff, %edx\n"
        "js .Lf192a4c_0019329e\n"
        ".Lf192a4c_00193137:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl imp_svs, %ecx\n"
        "movl 0x4c(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, -0x280c(%ebp)\n" /* cachedClient */
        "movl 4(%eax), %edx\n" /* line 1861 */
        "cmpl %edx, %ebx\n" /* line 1864 | newnum */
        "je .Lf192a4c_001931b3\n"
        ".Lf192a4c_0019315d:\n"
        "jl .Lf192a4c_00193231\n" /* line 1884 */
        "leal 1(%esi), %eax\n" /* line 1904 | oldindex */
        "cmpl %edx, %ebx\n" /* newnum */
        "cmovgl %eax, %esi\n" /* oldindex */
        "cmpl -0x2808(%ebp), %ebx\n" /* line 1843 | to_num_clients, newnum */
        "jge .Lf192a4c_00193118\n"
        ".Lf192a4c_00193173:\n"
        "movl imp_svs, %edx\n" /* line 1847 */
        "movl 0xc(%edx), %ecx\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* newnum */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ebx, %eax\n" /* newnum */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "cmpl $1, (%ecx, %edx, 4)\n"
        "jle .Lf192a4c_00193229\n"
        "cmpl -0x2804(%ebp), %esi\n" /* line 1854 | from_num_clients, oldindex */
        "jl .Lf192a4c_00193124\n"
        "movl $0x270f, %edx\n"
        "cmpl %edx, %ebx\n" /* line 1864 | newnum */
        "jne .Lf192a4c_0019315d\n"
        ".Lf192a4c_001931b3:\n"
        "movl %ebx, (%esp)\n" /* line 1869 | newnum */
        "calll G_GetClientState\n"
        "movl $1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x280c(%ebp), %eax\n" /* cachedClient */
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "leal -0x27f0(%ebp), %edx\n" /* line 1870 | ps */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll GetFollowPlayerState\n"
        "testl %eax, %eax\n"
        "je .Lf192a4c_001932c2\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1872 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit1\n"
        "leal -0x27f0(%ebp), %eax\n" /* line 1873 | ps */
        "movl %eax, 8(%esp)\n"
        "movl -0x280c(%ebp), %eax\n" /* cachedClient */
        "addl $0x60, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "addl $1, %esi\n" /* line 1879 | oldindex */
        ".Lf192a4c_00193229:\n"
        "addl $1, %ebx\n" /* line 1880 | newnum */
        "jmp .Lf192a4c_00193110\n"
        ".Lf192a4c_00193231:\n"
        "movl %ebx, (%esp)\n" /* line 1887 | newnum */
        "calll G_GetClientState\n"
        "movl $1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "leal -0x27f0(%ebp), %edx\n" /* line 1888 | ps */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll GetFollowPlayerState\n"
        "testl %eax, %eax\n"
        "je .Lf192a4c_001932af\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1890 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit1\n"
        "leal -0x27f0(%ebp), %eax\n" /* line 1891 | ps */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "addl $1, %ebx\n" /* line 1880 | newnum */
        "jmp .Lf192a4c_00193110\n"
        ".Lf192a4c_0019329e:\n"
        "subl $1, %edx\n" /* line 1860 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192a4c_00193137\n"
        ".Lf192a4c_001932af:\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1895 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "addl $1, %ebx\n" /* line 1880 | newnum */
        "jmp .Lf192a4c_00193110\n"
        ".Lf192a4c_001932c2:\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1877 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "addl $1, %esi\n" /* line 1879 | oldindex */
        "jmp .Lf192a4c_00193229\n"
        ".Lf192a4c_001932d5:\n"
        "leal -0x34(%ebp), %eax\n" /* line 1909 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "movl imp_sv, %eax\n" /* line 1911 */
        "movl 0x5f424(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf192a4c_00192d49\n"
        "xorl %esi, %esi\n" /* oldindex */
        "jmp .Lf192a4c_00193318\n"
        ".Lf192a4c_001932f7:\n"
        "testb $1, 0xf2(%eax)\n" /* line 1921 */
        "je .Lf192a4c_001933e9\n"
        ".Lf192a4c_00193304:\n"
        "addl $1, %esi\n" /* line 1911 | oldindex */
        "movl imp_sv, %eax\n"
        "cmpl %esi, 0x5f424(%eax)\n" /* oldindex */
        "jle .Lf192a4c_00192d49\n"
        ".Lf192a4c_00193318:\n"
        "movl %esi, (%esp)\n" /* line 1913 | oldindex */
        "calll SV_GentityNum\n"
        "movl %eax, %ebx\n" /* newnum */
        "cmpb $0, 0xf0(%eax)\n" /* line 1914 */
        "je .Lf192a4c_00193304\n"
        "movl 0x100(%eax), %edi\n" /* line 1919 | c */
        "testl %edi, %edi\n" /* c */
        "je .Lf192a4c_001932f7\n"
        ".Lf192a4c_00193335:\n"
        "leal -0x148(%ebp), %edi\n" /* line 1929 | archivedEnt, c */
        "movl $0xf0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* newnum */
        "movl %edi, (%esp)\n" /* c */
        "calll memcpy\n"
        "movzbl 0xf2(%ebx), %eax\n" /* line 1930 | newnum */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x100(%ebx), %edx\n" /* line 1931 | newnum */
        "testl %edx, %edx\n"
        "je .Lf192a4c_00193369\n"
        "orl $8, %eax\n" /* line 1932 */
        "movl %eax, -0x58(%ebp)\n"
        ".Lf192a4c_00193369:\n"
        "movl 0xf4(%ebx), %eax\n" /* line 1933 | newnum */
        "movl %eax, -0x54(%ebp)\n"
        "movl 0xf8(%ebx), %eax\n" /* line 1934 | newnum */
        "movl %eax, -0x50(%ebp)\n"
        "leal 0x120(%ebx), %edx\n" /* newnum */
        /* { scope 2 */
        "movl 0x120(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x44(%ebp)\n"
        "leal 0x12c(%ebx), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x12c(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x40(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x38(%ebp)\n"
        /* } scope */
        "movl $1, 0xc(%esp)\n" /* line 1938 */
        "movl %edi, 8(%esp)\n" /* c */
        "movl (%ebx), %eax\n" /* newnum */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl imp_sv, %eax\n"
        "leal 0x241c(%eax, %edx, 4), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaArchivedEntity\n"
        "jmp .Lf192a4c_00193304\n"
        ".Lf192a4c_001933e9:\n"
        "movl %eax, (%esp)\n" /* line 1924 */
        "calll SV_SvEntityForGentity\n"
        "movl %eax, %edx\n"
        "movzbl 0xf2(%ebx), %eax\n" /* line 1925 | newnum */
        "testb $0x18, %al\n"
        "jne .Lf192a4c_00193335\n"
        "movl 0x118(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf192a4c_00193304\n"
        "jmp .Lf192a4c_00193335\n"
        "movl %eax, %ebx\n" /* newnum */
        "leal -0x1c(%ebp), %edx\n" /* line 2067 | msg_buf_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll __Unwind_Resume\n"
    );
}

/* line 1619 */
/* line 1619 */
void SV_SendMessageToClient(msg_t *msg, client_t *client)
{
    byte *cl = (byte *)client;
    byte *svs = (byte *)imp_svs;
    byte *sv = (byte *)imp_sv;
    byte compressedBuf_ll[24];
    byte *compressedBuf;
    int compressedSize;
    int idx;
    int rateMsec;
    int rate;
    int messageSize;
    byte *dvar;
    int svsTime;

    LargeLocal_LargeLocal(compressedBuf_ll, 0x20000);
    compressedBuf = LargeLocal_GetBuf(compressedBuf_ll);

    /* Copy sequence number as first 4 bytes */
    *(int *)compressedBuf = *(int *)*(byte **)((byte *)msg + 4);

    /* Compress the message data */
    compressedSize = MSG_WriteBitsCompress(*(byte **)((byte *)msg + 4) + 4, compressedBuf + 4, *(int *)((byte *)msg + 0xc) - 4) + 4;

    /* Check for client error */
    if (*(int *)(cl + 8) != 0) {
        SV_DropClient(client, (const char *)*(int *)(cl + 8));
    }

    /* Store snapshot info in client frame history */
    /* idx = netchan.outgoingSequence & 31 */
    /* frame index math: idx*5 => *32 - idx*5 => *16 + idx = idx*2401, *4 for array */
    idx = *(int *)(cl + CLIENT_NETCHAN) & 0x1f;
    {
        int t = idx * 5;
        int frameOff = ((t * 32 - t) * 16 + idx) * 4;
        *(int *)(cl + 0x233e4 + frameOff) = compressedSize;
        *(int *)(cl + 0x233dc + frameOff) = *(int *)(svs + SVS_TIME);
        *(int *)(cl + 0x233e0 + frameOff) = -1;
    }

    /* Transmit */
    SV_Netchan_Transmit(client, compressedSize, compressedBuf);

    /* Rate limiting */
    if (*(int *)(cl + CLIENT_NETTYPE) == 2 ||
        Sys_IsLANAddress(*(int *)(cl + CLIENT_NETTYPE), *(int *)(cl + CLIENT_NETTYPE + 4), *(int *)(cl + CLIENT_NETTYPE + 8))) {
        /* LAN client - set next snapshot time to svs.time - 1 */
        *(int *)(cl + CLIENT_SNAPSHOTMSEC) = *(int *)(svs + SVS_TIME) - 1;
        ZN10LargeLocalD1Ev(compressedBuf_ll);
        return;
    }

    /* Rate-limited client */
    messageSize = compressedSize;
    if (messageSize > 0x5dc)
        messageSize = 0x5dc;

    rate = *(int *)(cl + CLIENT_RATE);
    dvar = *(byte **)&sv_minPingRate_dvar;
    dvar = *(byte **)dvar;
    if (*(int *)(dvar + 8) != 0) {
        if (*(int *)(dvar + 8) <= 0x3e7) {
            Dvar_SetInt(dvar, 0x3e8);
            dvar = *(byte **)&sv_minPingRate_dvar;
            dvar = *(byte **)dvar;
        }
        if (rate > *(int *)(dvar + 8))
            rate = *(int *)(dvar + 8);
    }

    /* rateMsec = (messageSize * 1000 * 8 + 48000) / rate */
    rateMsec = (messageSize * 5 * 5 * 5 * 8 + 0xbb80) / rate;

    /* showpackets dvar check */
    dvar = *(byte **)&showpackets_dvar;
    if (*(byte *)(*(byte **)dvar + 8) != 0) {
        Com_Printf("It would take %ims to send %i bytes to client %s (rate %i)\n",
            rateMsec, messageSize, cl + CLIENT_NAME, *(int *)(cl + CLIENT_RATE));
    }

    if (rateMsec < *(int *)(cl + CLIENT_RATEDELAYED)) {
        *(int *)(cl + CLIENT_PUREAUTH) = 0;
        rateMsec = *(int *)(cl + CLIENT_RATEDELAYED);
    } else {
        *(int *)(cl + CLIENT_PUREAUTH) = 1;
    }

    svsTime = *(int *)(svs + SVS_TIME);
    *(int *)(cl + CLIENT_SNAPSHOTMSEC) = rateMsec + svsTime;

    if (*(int *)(cl + CLIENT_STATE) != 4) {
        if (*(byte *)(cl + CLIENT_DOWNLOAD) == 0) {
            if (rateMsec + svsTime < svsTime + 0x3e8) {
                *(int *)(cl + CLIENT_SNAPSHOTMSEC) = svsTime + 0x3e8;
            }
        }
    }

    /* Track bandwidth */
    *(int *)(sv + 0x5f48c) += compressedSize;

    ZN10LargeLocalD1Ev(compressedBuf_ll);
}

/* line 1302 */
qboolean SV_GetArchivedClientInfo(int clientNum, int *pArchiveTime, int (*ps)[4], void (*cs)())
{
    byte *svs = (byte *)imp_svs;
    cachedSnapshot_t *snap = NULL;
    int archivedFrame = 0;

    if (*(int *)(svs + SVS_NUMONEWAYCLIENTS) != 0 && *pArchiveTime > 0) {
        int archivedSnapshotCount = *(int *)(svs + SVS_ARCHIVEDFRAMECOUNT);
        int rate = *(int *)(*(byte **)sv_maxRate_dvar + 8);
        int minFrame;

        archivedFrame = archivedSnapshotCount - (*pArchiveTime * rate / 1000);
        minFrame = archivedSnapshotCount - 0x4b0;

        if (archivedFrame < minFrame) {
            *pArchiveTime = (archivedSnapshotCount - minFrame) * 1000 / rate;
            archivedFrame = minFrame;
        }

        if (archivedFrame < 0) {
            *pArchiveTime = archivedSnapshotCount * 1000 / rate;
            archivedFrame = 0;
        }

        if (*(int *)(svs + SVS_ARCHIVEDFRAMECOUNT) > archivedFrame) {
            byte *svsReload = (byte *)imp_svs;
            while (archivedFrame < *(int *)(svsReload + SVS_ARCHIVEDFRAMECOUNT)) {
                snap = SV_GetCachedSnapshotInternal(archivedFrame);
                if (snap != NULL)
                    break;
                archivedFrame++;
            }
        }

        if (snap == NULL) {
            *pArchiveTime = 0;
        }
    }

    if (snap != NULL) {
        /* Found cached snapshot - extract archived client data */
        byte *snapBytes = (byte *)snap;
        byte *svs2 = (byte *)imp_svs;
        int deltaTime = *(int *)(svs2 + SVS_TIME) - *(int *)(snapBytes + 4);
        int numClients = *(int *)(snapBytes + 0x10);
        byte *cachedClientsBase;
        int firstIndex;
        byte *cachedClient = NULL;
        byte *psBytes;
        int i;

        if (numClients <= 0)
            return 0;

        cachedClientsBase = *(byte **)(svs2 + SVS_ARCHIVEDCLIENTDATA);
        firstIndex = *(int *)(snapBytes + 0x14);

        for (i = 0; i < numClients; i++) {
            int idx = (firstIndex + i) % 0x1000;
            byte *cc = cachedClientsBase + idx * CACHEDCLIENT_STRIDE;
            if (*(int *)(cc + 4) == clientNum) {
                cachedClient = cc;
                break;
            }
        }

        if (cachedClient == NULL || *(int *)cachedClient == 0)
            return 0;

        /* Copy playerState and clientState from cache */
        memcpy(ps, cachedClient + 0x60, 0x26a8);
        memcpy(cs, cachedClient + 4, 0x5c);

        /* Adjust time fields by deltaTime */
        psBytes = (byte *)ps;

        if (*(int *)(psBytes + 0x0) != 0)
            *(int *)(psBytes + 0x0) += deltaTime;
        if (*(int *)(psBytes + 0x10) != 0)
            *(int *)(psBytes + 0x10) += deltaTime;
        if (*(int *)(psBytes + 0x44) != 0)
            *(int *)(psBytes + 0x44) += deltaTime;
        if (*(int *)(psBytes + 0x70) != 0)
            *(int *)(psBytes + 0x70) += deltaTime;
        if (*(int *)(psBytes + 0xfc) != 0)
            *(int *)(psBytes + 0xfc) += deltaTime;
        if (*(int *)(psBytes + 0x5dc) != 0)
            *(int *)(psBytes + 0x5dc) += deltaTime;

        /* Adjust time fields in 31 weapon/anim entries at stride 0x80 */
        {
            byte *p = psBytes;
            byte *svsPtr = (byte *)imp_svs;
            for (i = 0; i < 31; i++) {
                if (*(int *)(p + 0x1790) != 0)
                    *(int *)(p + 0x1790) += deltaTime;
                if (*(int *)(p + 0x1750) != 0) {
                    *(int *)(p + 0x1750) += deltaTime;
                    if (*(int *)(p + 0x1750) > *(int *)(svsPtr + SVS_TIME))
                        *(int *)(p + 0x1750) = *(int *)(svsPtr + SVS_TIME);
                }
                if (*(int *)(p + 0x1770) != 0)
                    *(int *)(p + 0x1770) += deltaTime;
                if (*(int *)(p + 0x1788) != 0)
                    *(int *)(p + 0x1788) += deltaTime;
                p += 0x80;
            }
        }

        *(int *)(psBytes + 0x7a4) += deltaTime;
        return 1;
    }

    /* Live data path */
    if (*pArchiveTime > 0)
        return 0;

    {
        byte *clients = *(byte **)(svs + SVS_CLIENTS);
        byte *client = clients + clientNum * CLIENT_STRIDE;

        if (*(int *)(client + CLIENT_STATE) != 4)
            return 0;

        if (!GetFollowPlayerState(clientNum, (byte *)ps))
            return 0;

        memcpy(cs, G_GetClientState(clientNum), 0x5c);
        return 1;
    }
}

/* line 1179 */
Bool SV_GetClientPositionAtTime(int clientNum, int gametime, vec_t *pos)
{
    byte *svs = (byte *)imp_svs;
    byte *maxRateDvar = *(byte **)imp_sv_maxRate;
    int msPerFrame;
    int svsTime;
    int frameOffset;
    int startTime, endTime;
    int timeRequest;
    int i;
    byte foundStart, foundEnd;
    float startPos[3], endPos[3];
    float startWeight, endWeight;
    byte ps[0x26a8];
    byte cs[0x74];

    /* msPerFrame = 1000 / sv_maxRate->current.integer */
    msPerFrame = 1000 / *(int *)(*(byte **)maxRateDvar + 8);

    svsTime = *(int *)(svs + SVS_TIME);
    frameOffset = (svsTime / msPerFrame) * msPerFrame - gametime;
    frameOffset = frameOffset / msPerFrame;

    startTime = (frameOffset + startOffset) * msPerFrame;
    endTime = (frameOffset + endOffset) * msPerFrame;

    /* Search forward for start position */
    timeRequest = startTime;
    foundStart = 0;
    for (i = 10; i > 0; i--) {
        if (SV_GetArchivedClientInfo(clientNum, &timeRequest, (int (*)[4])ps, (void (*)())cs)) {
            startTime = timeRequest;
            startPos[0] = *(float *)(ps + 0x14);
            startPos[1] = *(float *)(ps + 0x18);
            startPos[2] = *(float *)(ps + 0x1c);
            foundStart = 1;
            break;
        }
        timeRequest += msPerFrame;
    }

    /* Search backward for end position */
    timeRequest = endTime;
    foundEnd = 0;
    for (i = 10; i > 0; i--) {
        if (SV_GetArchivedClientInfo(clientNum, &timeRequest, (int (*)[4])ps, (void (*)())cs)) {
            endTime = timeRequest;
            endPos[0] = *(float *)(ps + 0x14);
            endPos[1] = *(float *)(ps + 0x18);
            endPos[2] = *(float *)(ps + 0x1c);
            foundEnd = 1;
            break;
        }
        timeRequest -= msPerFrame;
    }

    if (foundStart && !foundEnd) {
        /* Only have start - zero end, weight = (0.0, 1.0) */
        endPos[0] = 0.0f;
        endPos[1] = 0.0f;
        endPos[2] = 0.0f;
        endWeight = 0.0f;
        startWeight = 1.0f;
    } else if (!foundStart && foundEnd) {
        /* Only have end - zero start, weight = (1.0, 0.0) */
        startPos[0] = 0.0f;
        startPos[1] = 0.0f;
        startPos[2] = 0.0f;
        endWeight = 1.0f;
        startWeight = 0.0f;
    } else if (!foundStart && !foundEnd) {
        return 0;
    } else {
        /* Both found - interpolate */
        endWeight = (float)(gametime % msPerFrame) / (float)(startTime - endTime);
        startWeight = 1.0f - endWeight;
    }

    for (i = 0; i < 3; i++) {
        pos[i] = startWeight * startPos[i] + endWeight * endPos[i];
    }
    return 1;
}

/* line 1699 */
__attribute__((naked))
void SV_SendClientSnapshot(client_t *client)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1699 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x132c, %esp\n"
        /* { scope 1: frame, client */
        "movl $0x20000, 4(%esp)\n" /* line 1702 */
        "leal -0x1c(%ebp), %eax\n" /* msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* msg_buf_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x12f8(%ebp)\n" /* msg_buf */
        "movl 8(%ebp), %ecx\n" /* line 1704 | client */
        "movl (%ecx), %eax\n"
        "cmpl $4, %eax\n"
        "je .Lf193c24_0019419e\n"
        "subl $1, %eax\n"
        "je .Lf193c24_0019453b\n"
        ".Lf193c24_00193c6b:\n"
        "movl $0x20000, 8(%esp)\n" /* line 1710 */
        "movl -0x12f8(%ebp), %edx\n" /* msg_buf */
        "movl %edx, 4(%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_Init\n"
        "movl 8(%ebp), %ebx\n" /* line 1714 | client, state */
        "movl 0x20840(%ebx), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl (%ebx), %eax\n" /* line 1716 | state */
        "cmpl $4, %eax\n"
        "je .Lf193c24_00193d49\n"
        "subl $1, %eax\n"
        "je .Lf193c24_00193d49\n"
        "movl 8(%ebp), %ebx\n" /* client, state */
        ".Lf193c24_00193cb7:\n"
        "leal -0x50(%ebp), %ecx\n" /* line 1730 | msg */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll SV_WriteDownloadToClient\n"
        ".Lf193c24_00193cc6:\n"
        "movl $7, 4(%esp)\n" /* line 1734 */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl -0x50(%ebp), %ecx\n" /* line 1737 | msg */
        "testl %ecx, %ecx\n"
        "je .Lf193c24_00193d21\n"
        "movl 8(%ebp), %edx\n" /* line 1739 | client */
        "addl $0x20c48, %edx\n"
        "movl %edx, -0x12fc(%ebp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002b064c, (%esp)\n" /* "WARNING: msg overflowed for %s, trying to recover
" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %ecx\n" /* line 1741 | client */
        "movl (%ecx), %eax\n"
        "cmpl $4, %eax\n"
        "je .Lf193c24_0019460e\n"
        "subl $1, %eax\n"
        "je .Lf193c24_0019479e\n"
        ".Lf193c24_00193d16:\n"
        "movl -0x50(%ebp), %edx\n" /* line 1754 | msg */
        "testl %edx, %edx\n"
        "jne .Lf193c24_00194543\n"
        ".Lf193c24_00193d21:\n"
        "movl 8(%ebp), %eax\n" /* line 1762 | client */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll SV_SendMessageToClient\n"
        "leal -0x1c(%ebp), %ebx\n" /* msg_buf_large_local, state */
        "movl %ebx, (%esp)\n" /* state */
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x132c, %esp\n" /* line 1763 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: frame, client */
        ".Lf193c24_00193d49:\n"
        "leal -0x50(%ebp), %edx\n" /* line 1719 | msg */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "movl %ecx, (%esp)\n"
        "calll SV_UpdateServerCommandsToClient\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        "movl 8(%ebp), %eax\n" /* line 374 | client */
        "movl 0x6e5b4(%eax), %ebx\n" /* i */
        "movl %ebx, %eax\n" /* i */
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "shll $4, %edx\n"
        "addl %eax, %edx\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "leal 0x20d24(%ecx, %edx, 4), %edx\n"
        "movl %edx, -0x12a4(%ebp)\n" /* frame */
        "movl 0x20d08(%ecx), %eax\n" /* line 377 */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00193d9b\n"
        "cmpl $4, (%ecx)\n"
        "je .Lf193c24_001945ae\n"
        ".Lf193c24_00193d9b:\n"
        "xorl %ebx, %ebx\n" /* line 399 | i */
        "xorl %esi, %esi\n" /* lastframe */
        ".Lf193c24_00193d9f:\n"
        "movl $6, 4(%esp)\n" /* line 405 */
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl imp_svs, %edi\n" /* line 409 | newindex */
        "movl 4(%edi), %eax\n" /* newindex */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl %esi, 4(%esp)\n" /* line 412 | lastframe */
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 8(%edi), %edx\n" /* line 414 | newindex */
        "movl %edx, %eax\n" /* line 416 */
        "orl $1, %eax\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "movl 0x20d1c(%ecx), %edi\n" /* newindex */
        "testl %edi, %edi\n" /* newindex */
        "cmovnel %eax, %edx\n"
        "movl (%ecx), %eax\n" /* line 417 */
        "cmpl $4, %eax\n"
        "je .Lf193c24_001947cf\n"
        "subl $1, %eax\n" /* line 419 */
        "je .Lf193c24_00193e09\n"
        "movl 8(%ebp), %eax\n" /* line 420 | client */
        "movl $0, 4(%eax)\n"
        ".Lf193c24_00193e09:\n"
        "movl %edx, %eax\n" /* line 422 */
        "orl $2, %eax\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "movl 4(%ecx), %esi\n" /* lastframe */
        "testl %esi, %esi\n" /* lastframe */
        "cmovel %eax, %edx\n"
        "movl %edx, 4(%esp)\n" /* line 424 */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "testl %ebx, %ebx\n" /* line 431 | i */
        "je .Lf193c24_001947db\n"
        "movl -0x12a4(%ebp), %edx\n" /* line 433 | frame */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "movl 0x26a8(%ebx), %eax\n" /* line 439 | i */
        "movl %eax, -0x1294(%ebp)\n" /* from_num_entities */
        "movl 0x26b0(%ebx), %edx\n" /* line 440 | i */
        "movl %edx, -0x1298(%ebp)\n" /* from_first_entity */
        "movl 0x26ac(%ebx), %ecx\n" /* line 441 | i */
        "movl %ecx, -0x127c(%ebp)\n" /* from_num_clients */
        "movl 0x26b4(%ebx), %ebx\n" /* line 442 | i */
        "movl %ebx, -0x1280(%ebp)\n" /* i, from_first_client */
        ".Lf193c24_00193e79:\n"
        "movl -0x12a4(%ebp), %edx\n" /* line 461 | frame */
        "movl 0x26b0(%edx), %edx\n"
        "movl %edx, -0x12a0(%ebp)\n" /* to_first_entity */
        "movl -0x12a4(%ebp), %ecx\n" /* frame */
        "movl 0x26a8(%ecx), %ecx\n"
        "movl %ecx, -0x129c(%ebp)\n" /* to_num_entities */
        "xorl %edi, %edi\n" /* newindex */
        "xorl %ebx, %ebx\n" /* i */
        "movl $0, -0x128c(%ebp)\n" /* newindex */
        "movl $0, -0x1290(%ebp)\n" /* oldindex */
        "movl %ecx, %edx\n"
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00193eb7:\n"
        "cmpl %edx, -0x128c(%ebp)\n" /* line 173 | newindex */
        "jge .Lf193c24_00193f17\n"
        ".Lf193c24_00193ebf:\n"
        "movl imp_svs, %esi\n" /* line 181 */
        "movl -0x128c(%ebp), %eax\n" /* newindex */
        "addl -0x12a0(%ebp), %eax\n" /* to_first_entity */
        "cltd\n"
        "idivl 0x10(%esi)\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %edi\n" /* newent */
        "shll $8, %edi\n" /* newent */
        "subl %eax, %edi\n" /* newent */
        "addl 0x20(%esi), %edi\n" /* newent */
        "movl (%edi), %ecx\n" /* line 182 | newent */
        "movl -0x1290(%ebp), %eax\n" /* line 185 | oldindex */
        "cmpl %eax, -0x1294(%ebp)\n" /* from_num_entities */
        "jg .Lf193c24_00193f34\n"
        "movl $0x270f, %eax\n"
        "cmpl %ecx, %eax\n" /* line 205 */
        "je .Lf193c24_00193f59\n"
        ".Lf193c24_00193efd:\n"
        "jg .Lf193c24_00193f8d\n" /* line 221 */
        "jl .Lf193c24_00193fd0\n" /* line 234 */
        "movl -0x129c(%ebp), %edx\n" /* to_num_entities */
        "cmpl %edx, -0x128c(%ebp)\n" /* line 173 | newindex */
        "jl .Lf193c24_00193ebf\n"
        ".Lf193c24_00193f17:\n"
        "movl -0x1290(%ebp), %ecx\n" /* oldindex */
        "cmpl %ecx, -0x1294(%ebp)\n" /* from_num_entities */
        "jle .Lf193c24_00194001\n"
        "movl $0x270f, %ecx\n"
        "movl imp_svs, %esi\n"
        ".Lf193c24_00193f34:\n"
        "movl -0x1298(%ebp), %eax\n" /* line 191 | from_first_entity */
        "addl -0x1290(%ebp), %eax\n" /* oldindex */
        "cltd\n"
        "idivl 0x10(%esi)\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %ebx\n" /* oldent */
        "shll $8, %ebx\n" /* oldent */
        "subl %eax, %ebx\n" /* oldent */
        "addl 0x20(%esi), %ebx\n" /* oldent */
        "movl (%ebx), %eax\n" /* line 192 | oldent */
        "cmpl %ecx, %eax\n" /* line 205 */
        "jne .Lf193c24_00193efd\n"
        ".Lf193c24_00193f59:\n"
        "movl $0, 0xc(%esp)\n" /* line 210 */
        "movl %edi, 8(%esp)\n" /* newent */
        "movl %ebx, 4(%esp)\n" /* oldent */
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaEntity\n"
        "addl $1, -0x1290(%ebp)\n" /* line 216 | oldindex */
        "addl $1, -0x128c(%ebp)\n" /* line 217 | newindex */
        "movl -0x129c(%ebp), %edx\n" /* to_num_entities */
        "jmp .Lf193c24_00193eb7\n"
        ".Lf193c24_00193f8d:\n"
        "movl $1, 0xc(%esp)\n" /* line 224 */
        "movl %edi, 8(%esp)\n" /* newent */
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl imp_sv, %eax\n"
        "leal 0x241c(%eax, %edx, 4), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteDeltaEntity\n"
        "addl $1, -0x128c(%ebp)\n" /* line 230 | newindex */
        "movl -0x129c(%ebp), %edx\n" /* to_num_entities */
        "jmp .Lf193c24_00193eb7\n"
        ".Lf193c24_00193fd0:\n"
        "movl $1, 0xc(%esp)\n" /* line 237 */
        "movl $0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* oldent */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaEntity\n"
        "addl $1, -0x1290(%ebp)\n" /* line 243 | oldindex */
        "movl -0x129c(%ebp), %edx\n" /* to_num_entities */
        "jmp .Lf193c24_00193eb7\n"
        ".Lf193c24_00194001:\n"
        "movl $0xa, 8(%esp)\n" /* line 249 */
        "movl $0x3ff, 4(%esp)\n"
        "leal -0x50(%ebp), %ebx\n" /* msg, oldent */
        "movl %ebx, (%esp)\n" /* oldent */
        "calll MSG_WriteBits\n"
        /* } scope */
        /* } scope */
        "movl -0x12a4(%ebp), %eax\n" /* line 464 | frame */
        "movl 0x26b4(%eax), %eax\n"
        "movl %eax, -0x1288(%ebp)\n" /* to_first_client */
        "movl -0x12a4(%ebp), %edx\n" /* frame */
        "movl 0x26ac(%edx), %edx\n"
        "movl %edx, -0x1284(%ebp)\n" /* to_num_clients */
        "movl $0, -0x1274(%ebp)\n" /* newclient */
        "movl $0, -0x1278(%ebp)\n" /* oldclient */
        "xorl %edi, %edi\n" /* newindex */
        "xorl %ebx, %ebx\n" /* i */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194058:\n"
        "cmpl -0x1284(%ebp), %edi\n" /* line 281 | to_num_clients, newindex */
        "jge .Lf193c24_001940d2\n"
        ".Lf193c24_00194060:\n"
        "movl imp_svs, %esi\n" /* line 289 */
        "movl -0x1288(%ebp), %ecx\n" /* to_first_client */
        "leal (%edi, %ecx), %eax\n" /* newindex */
        "cltd\n"
        "idivl 0x14(%esi)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x24(%esi), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x1274(%ebp)\n" /* newclient */
        "movl (%eax), %ecx\n" /* line 290 */
        "cmpl %ebx, -0x127c(%ebp)\n" /* line 293 | oldindex, from_num_clients */
        "jg .Lf193c24_001940e9\n"
        "movl $0x270f, %eax\n"
        "cmpl %ecx, %eax\n" /* line 303 */
        "je .Lf193c24_0019410f\n"
        ".Lf193c24_0019409a:\n"
        "jg .Lf193c24_00194141\n" /* line 319 */
        "jge .Lf193c24_00194058\n" /* line 332 */
        "movl $1, 0xc(%esp)\n" /* line 335 */
        "movl $0, 8(%esp)\n"
        "movl -0x1278(%ebp), %edx\n" /* oldclient */
        "movl %edx, 4(%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "addl $1, %ebx\n" /* line 341 | oldindex */
        "cmpl -0x1284(%ebp), %edi\n" /* line 281 | to_num_clients, newindex */
        "jl .Lf193c24_00194060\n"
        ".Lf193c24_001940d2:\n"
        "cmpl %ebx, -0x127c(%ebp)\n" /* oldindex, from_num_clients */
        "jle .Lf193c24_0019416e\n"
        "movl $0x270f, %ecx\n"
        "movl imp_svs, %esi\n"
        ".Lf193c24_001940e9:\n"
        "movl -0x1280(%ebp), %eax\n" /* line 299 | from_first_client */
        "addl %ebx, %eax\n" /* oldindex */
        "cltd\n"
        "idivl 0x14(%esi)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x24(%esi), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x1278(%ebp)\n" /* oldclient */
        "movl (%eax), %eax\n" /* line 300 */
        "cmpl %ecx, %eax\n" /* line 303 */
        "jne .Lf193c24_0019409a\n"
        ".Lf193c24_0019410f:\n"
        "movl $0, 0xc(%esp)\n" /* line 308 */
        "movl -0x1274(%ebp), %ecx\n" /* newclient */
        "movl %ecx, 8(%esp)\n"
        "movl -0x1278(%ebp), %eax\n" /* oldclient */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "addl $1, %ebx\n" /* line 314 | oldindex */
        "addl $1, %edi\n" /* line 315 | newindex */
        "jmp .Lf193c24_00194058\n"
        ".Lf193c24_00194141:\n"
        "movl $1, 0xc(%esp)\n" /* line 322 */
        "movl -0x1274(%ebp), %ecx\n" /* newclient */
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "addl $1, %edi\n" /* line 328 | newindex */
        "jmp .Lf193c24_00194058\n"
        ".Lf193c24_0019416e:\n"
        "leal -0x50(%ebp), %ebx\n" /* line 346 | msg, oldindex */
        "movl %ebx, (%esp)\n" /* oldindex */
        "calll MSG_WriteBit0\n"
        /* } scope */
        /* } scope */
        "movl imp_sv_padPackets, %eax\n" /* line 467 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf193c24_001947a6\n"
        /* } scope */
        ".Lf193c24_0019418b:\n"
        "movl 8(%ebp), %edx\n" /* line 1727 | client */
        "cmpl $1, (%edx)\n"
        "je .Lf193c24_00193cc6\n"
        "movl %edx, %ebx\n" /* state */
        "jmp .Lf193c24_00193cb7\n"
        ".Lf193c24_0019419e:\n"
        "movl %ecx, %ebx\n" /* state */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        ".Lf193c24_001941a0:\n"
        "movl 0x6e5b4(%ebx), %eax\n" /* line 1417 | state */
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "shll $4, %edx\n"
        "addl %eax, %edx\n"
        "leal 0x20d24(%ebx, %edx, 4), %esi\n" /* state, frame */
        "movl $0, 0x26a8(%esi)\n" /* line 1418 | frame */
        "movl $0, 0x26ac(%esi)\n" /* line 1419 | frame */
        "movl 0x20c44(%ebx), %ecx\n" /* line 1423 | state */
        "testl %ecx, %ecx\n"
        "je .Lf193c24_00193c6b\n"
        "cmpl $1, (%ebx)\n" /* state */
        "je .Lf193c24_00193c6b\n"
        "movl imp_svs, %edi\n" /* line 1429 | i */
        "movl 0x18(%edi), %eax\n" /* i */
        "movl %eax, 0x26b0(%esi)\n" /* frame */
        "movl 0x1c(%edi), %eax\n" /* line 1430 | i */
        "movl %eax, 0x26b4(%esi)\n" /* frame */
        "movl imp_sv, %eax\n" /* line 1435 */
        "cmpl $2, (%eax)\n"
        "jne .Lf193c24_00193c6b\n"
        "movl %ebx, %eax\n" /* line 1441 | state */
        "subl 0xc(%edi), %eax\n" /* i */
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, -0x1300(%ebp)\n"
        "movl %eax, (%esp)\n" /* line 1443 */
        "calll G_GetClientArchiveTime\n"
        "movl %eax, -0x12e8(%ebp)\n" /* archiveTime */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        "movl 0x28(%edi), %edx\n" /* line 1116 | i */
        "testl %edx, %edx\n"
        "je .Lf193c24_00194938\n"
        "testl %eax, %eax\n" /* line 1126 */
        "jle .Lf193c24_00194938\n"
        "movl 0x2c(%edi), %eax\n" /* line 1129 | i */
        "movl %eax, -0x12e4(%ebp)\n"
        "movl imp_sv_fps, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x12e0(%ebp)\n"
        "movl -0x12e8(%ebp), %ecx\n" /* archiveTime */
        "imull %eax, %ecx\n"
        "movl $0x10624dd3, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl -0x12e4(%ebp), %ebx\n" /* archivedFrame */
        "subl %edx, %ebx\n" /* archivedFrame */
        "movl -0x12e4(%ebp), %ecx\n" /* line 1130 */
        "subl $0x4b0, %ecx\n"
        "cmpl %ecx, %ebx\n" /* archivedFrame */
        "jge .Lf193c24_001942bb\n"
        "movl -0x12e4(%ebp), %eax\n" /* line 1133 */
        "subl %ecx, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl -0x12e0(%ebp)\n"
        "movl %eax, -0x12e8(%ebp)\n" /* archiveTime */
        "movl %ecx, %ebx\n" /* archivedFrame */
        ".Lf193c24_001942bb:\n"
        "testl %ebx, %ebx\n" /* line 1135 | archivedFrame */
        "js .Lf193c24_00194c41\n"
        ".Lf193c24_001942c3:\n"
        "cmpl -0x12e4(%ebp), %ebx\n" /* line 1141 | archivedFrame */
        "jl .Lf193c24_00194825\n"
        ".Lf193c24_001942cf:\n"
        "movl $0, -0x12f0(%ebp)\n" /* cachedFrame */
        "movl $0, -0x12e8(%ebp)\n" /* archiveTime */
        /* } scope */
        ".Lf193c24_001942e3:\n"
        "movl -0x12e8(%ebp), %edx\n" /* line 1445 | archiveTime */
        "movl %edx, 4(%esp)\n"
        "movl -0x1300(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll G_SetClientArchiveTime\n"
        "movl -0x12f0(%ebp), %ebx\n" /* line 1446 | cachedFrame, state */
        "testl %ebx, %ebx\n" /* state */
        "je .Lf193c24_00194c2a\n"
        "movl imp_svs, %eax\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x12ec(%ebp)\n" /* deltaTime */
        "movl -0x12f0(%ebp), %ebx\n" /* cachedFrame, state */
        "movl 4(%ebx), %ebx\n" /* state */
        "subl %ebx, %eax\n" /* state */
        "movl %eax, -0x12ec(%ebp)\n" /* deltaTime */
        ".Lf193c24_00194328:\n"
        "movl -0x1300(%ebp), %eax\n" /* line 1449 */
        "movl %eax, (%esp)\n"
        "calll SV_GameClientNum\n"
        "movl $0x26a8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* frame */
        "calll memcpy\n"
        "movl 0xcc(%esi), %edx\n" /* line 1451 | frame */
        "movl %edx, -0x12c4(%ebp)\n" /* clientNum */
        "cmpl $0x3ff, %edx\n" /* line 1452 */
        "jbe .Lf193c24_00194372\n"
        "movl $str_002b0584, 4(%esp)\n" /* line 1454 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf193c24_00194372:\n"
        "leal 0x14(%esi), %edx\n" /* frame */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        "movl 0x14(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x2c(%ebp)\n" /* org */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x24(%ebp)\n"
        /* } scope */
        "addss 0xf8(%esi), %xmm0\n" /* line 1459 | frame */
        "movss %xmm0, -0x24(%ebp)\n"
        "movl $0x41a00000, 0x10(%esp)\n" /* line 1462 */
        "movl $0x41800000, 0xc(%esp)\n"
        "movl 0x4c(%esi), %eax\n" /* frame */
        "movl %eax, 8(%esp)\n"
        "movl 0xec(%esi), %eax\n" /* frame */
        "movl %eax, 4(%esp)\n"
        "leal -0x2c(%ebp), %ecx\n" /* org */
        "movl %ecx, (%esp)\n"
        "calll AddLeanToPosition\n"
        "movl -0x12f0(%ebp), %ecx\n" /* line 1468 | cachedFrame */
        "testl %ecx, %ecx\n"
        "je .Lf193c24_00194947\n"
        "movl -0x12f0(%ebp), %eax\n" /* line 1517 | cachedFrame */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x12c0(%ebp)\n" /* from_first_entity */
        "movl -0x12f0(%ebp), %edx\n" /* cachedFrame */
        "movl 8(%edx), %edx\n"
        "movl %edx, -0x12bc(%ebp)\n" /* from_num_entities */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        /* { scope 5: e */
        "leal -0x2c(%ebp), %ecx\n" /* line 756 | org */
        "movl %ecx, (%esp)\n"
        "calll CM_PointLeafnum\n"
        "movl %eax, (%esp)\n" /* line 758 */
        "calll CM_LeafCluster\n"
        "testl %eax, %eax\n" /* line 759 */
        "js .Lf193c24_00194847\n"
        "movl %eax, (%esp)\n" /* line 762 */
        "calll CM_ClusterPVS\n"
        "movl %eax, -0x12b0(%ebp)\n" /* clientpvs */
        "calll G_GetFogOpaqueDistSqrd\n" /* line 764 */
        "fstps -0x12ac(%ebp)\n" /* fogOpaqueDistSqrd */
        "movss -0x12ac(%ebp), %xmm0\n" /* line 765 | fogOpaqueDistSqrd */
        "movaps %xmm0, %xmm1\n"
        "cmpneqss lit4_002ed684, %xmm0\n" /* 3.4028234663852886e+38f */
        "andps %xmm1, %xmm0\n"
        "movss %xmm0, -0x12ac(%ebp)\n" /* fogOpaqueDistSqrd */
        "movl -0x12bc(%ebp), %eax\n" /* line 772 | from_num_entities */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00194847\n"
        "movl -0x12c4(%ebp), %eax\n" /* clientNum */
        "sarl $5, %eax\n"
        "movl %eax, -0x126c(%ebp)\n"
        "movl -0x12c4(%ebp), %edx\n" /* clientNum */
        "andl $0x1f, %edx\n"
        "movl %edx, -0x1268(%ebp)\n"
        "movl $0, -0x12a8(%ebp)\n" /* e */
        "movl $0, -0x1264(%ebp)\n"
        "jmp .Lf193c24_00194510\n"
        ".Lf193c24_00194488:\n"
        "movl %edx, %eax\n" /* line 774 */
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl imp_svs, %ecx\n"
        "movl 0x48(%ecx), %edx\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl -0x126c(%ebp), %ebx\n" /* line 782 | num_leafs */
        "movl 0xf4(%edx, %ebx, 4), %eax\n"
        "movzbl -0x1268(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf193c24_001944f7\n"
        "movl -0x12c4(%ebp), %ebx\n" /* line 785 | clientNum, num_leafs */
        "cmpl (%edx), %ebx\n" /* num_leafs */
        "je .Lf193c24_001944f7\n"
        "testb $0x18, 0xf0(%edx)\n" /* line 798 */
        "je .Lf193c24_00194b8f\n"
        "cmpl $0x400, -0x1264(%ebp)\n" /* line 608 */
        "je .Lf193c24_001944f7\n"
        "movl -0x12a8(%ebp), %edx\n" /* line 613 | e */
        "movl -0x1264(%ebp), %eax\n"
        "movl %edx, -0x1250(%ebp, %eax, 4)\n"
        "addl $1, %eax\n" /* line 614 */
        "movl %eax, -0x1264(%ebp)\n"
        ".Lf193c24_001944f7:\n"
        "addl $1, -0x12a8(%ebp)\n" /* line 772 | e */
        "movl -0x12a8(%ebp), %edx\n" /* e */
        "cmpl %edx, -0x12bc(%ebp)\n" /* from_num_entities */
        "je .Lf193c24_00194a73\n"
        ".Lf193c24_00194510:\n"
        "movl -0x12c0(%ebp), %eax\n" /* line 774 | from_first_entity */
        "addl -0x12a8(%ebp), %eax\n" /* e */
        "movl %eax, %edx\n"
        "andl $0x80003fff, %edx\n"
        "jns .Lf193c24_00194488\n"
        "subl $1, %edx\n"
        "orl $0xffffc000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf193c24_00194488\n"
        ".Lf193c24_0019453b:\n"
        "movl 8(%ebp), %ebx\n" /* client, num_leafs */
        "jmp .Lf193c24_001941a0\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf193c24_00194543:\n"
        "movl -0x12fc(%ebp), %eax\n" /* line 1756 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b0680, (%esp)\n" /* "WARNING: client disconnected for msg overflow: %s
" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %edx\n" /* line 1757 | client */
        "movl 0x6e5c4(%edx), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl %edx, %ebx\n" /* state */
        "movl 0x6e5c8(%edx), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* state */
        "movl %eax, -0x30(%ebp)\n"
        "movl $str_00228e90, 0x10(%esp)\n" /* "disconnect" */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl $str_002b06b4, 4(%esp)\n" /* line 1758 */
        "movl %ebx, (%esp)\n" /* state */
        "calll SV_DropClient\n"
        "jmp .Lf193c24_00193d21\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_001945ae:\n"
        "movl %ebx, %esi\n" /* line 383 | i, lastframe */
        "subl %eax, %esi\n" /* lastframe */
        "cmpl $0x1c, %esi\n" /* lastframe */
        "jg .Lf193c24_0019491c\n"
        "movl %eax, %edx\n" /* line 393 */
        "andl $0x1f, %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* client */
        "leal 0x20d24(%edx, %eax, 4), %ebx\n" /* i */
        "movl imp_svs, %edx\n" /* line 397 */
        "movl 0x18(%edx), %eax\n"
        "subl 0x10(%edx), %eax\n"
        "cmpl %eax, 0x26b0(%ebx)\n" /* i */
        "jge .Lf193c24_00193d9f\n"
        "movl 8(%ebp), %eax\n" /* line 399 | client */
        "addl $0x20c48, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b061c, (%esp)\n" /* "%s: Delta request from out of date entities.
" */
        "calll Com_DPrintf\n"
        "jmp .Lf193c24_00193d9b\n"
        ".Lf193c24_0019460e:\n"
        "movl %ecx, %edx\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_00194610:\n"
        "movl -0x12fc(%ebp), %ebx\n" /* line 557 | i */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl imp_svs, %eax\n"
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b03d4, (%esp)\n" /* "-- Unacknowledged Server Commands for client %i:%s --
" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %ecx\n" /* line 559 | client */
        "movl 0x20810(%ecx), %ebx\n" /* i */
        "addl $1, %ebx\n" /* i */
        "cmpl 0x20814(%ecx), %ebx\n" /* i */
        "jle .Lf193c24_001946d7\n"
        ".Lf193c24_00194655:\n"
        "movl $str_002b040c, (%esp)\n" /* line 562 */
        "calll Com_Printf\n"
        /* } scope */
        "movl $0x20000, 8(%esp)\n" /* line 1746 */
        "movl -0x12f8(%ebp), %edx\n" /* msg_buf */
        "movl %edx, 4(%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_Init\n"
        "movl 8(%ebp), %ebx\n" /* line 1747 | client, state */
        "movl 0x20840(%ebx), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        "movl 8(%ebp), %edx\n" /* line 531 | client */
        "movl 0x20810(%edx), %ebx\n" /* i */
        "addl $1, %ebx\n" /* i */
        "cmpl 0x20814(%edx), %ebx\n" /* i */
        "jle .Lf193c24_0019471d\n"
        ".Lf193c24_001946aa:\n"
        "movl %edx, %ecx\n"
        ".Lf193c24_001946ac:\n"
        "leal -1(%ebx), %eax\n" /* line 542 | i */
        "cmpl 0x20814(%ecx), %eax\n" /* line 543 */
        "jle .Lf193c24_001946bd\n"
        "movl %eax, 0x20814(%ecx)\n" /* line 544 */
        /* } scope */
        ".Lf193c24_001946bd:\n"
        "movl $7, 4(%esp)\n" /* line 1750 */
        "leal -0x50(%ebp), %ebx\n" /* msg, state */
        "movl %ebx, (%esp)\n" /* state */
        "calll MSG_WriteByte\n"
        "jmp .Lf193c24_00193d16\n"
        ".Lf193c24_001946d5:\n"
        "movl %eax, %ecx\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_001946d7:\n"
        "movl %ebx, %eax\n" /* line 560 | i */
        "andl $0x7f, %eax\n"
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0x40c(%eax, %ecx), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0x80c(%eax, %ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $str_002ab3fc, (%esp)\n" /* "cmd %5d: %8d: %s
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 559 | i */
        "movl 8(%ebp), %eax\n" /* client */
        "cmpl 0x20814(%eax), %ebx\n" /* i */
        "jle .Lf193c24_001946d5\n"
        "jmp .Lf193c24_00194655\n"
        ".Lf193c24_0019471d:\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "jmp .Lf193c24_00194724\n"
        ".Lf193c24_00194722:\n"
        "movl %edx, %ecx\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_00194724:\n"
        "movl %ebx, %eax\n" /* line 533 | i */
        "andl $0x7f, %eax\n"
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal 0x400(%edx, %eax, 8), %eax\n"
        "leal 0xc(%ecx, %eax), %esi\n" /* lastframe */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* lastframe, newindex */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* newindex */
        "notl %ecx\n"
        "movl -0x44(%ebp), %eax\n"
        "leal 5(%ecx, %eax), %ecx\n"
        "cmpl $0x1ffff, %ecx\n"
        "jg .Lf193c24_00194c39\n"
        "movl $4, 4(%esp)\n" /* line 537 */
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl %ebx, 4(%esp)\n" /* line 538 | i */
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl %esi, 4(%esp)\n" /* line 539 | lastframe */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteString\n"
        "addl $1, %ebx\n" /* line 531 | i */
        "movl 8(%ebp), %edx\n" /* client */
        "cmpl 0x20814(%edx), %ebx\n" /* i */
        "jle .Lf193c24_00194722\n"
        "jmp .Lf193c24_001946aa\n"
        ".Lf193c24_0019479e:\n"
        "movl 8(%ebp), %edx\n" /* client */
        "jmp .Lf193c24_00194610\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_001947a6:\n"
        "xorl %ebx, %ebx\n" /* line 467 | i */
        ".Lf193c24_001947a8:\n"
        "movl $0, 4(%esp)\n" /* line 468 */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "addl $1, %ebx\n" /* line 467 | i */
        "movl imp_sv_padPackets, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ebx\n" /* i */
        "jl .Lf193c24_001947a8\n"
        "jmp .Lf193c24_0019418b\n"
        ".Lf193c24_001947cf:\n"
        "movl $1, 4(%ecx)\n" /* line 418 */
        "jmp .Lf193c24_00193e09\n"
        ".Lf193c24_001947db:\n"
        "movl -0x12a4(%ebp), %ebx\n" /* line 448 | frame, i */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl $0, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "movl $0, -0x1294(%ebp)\n" /* from_num_entities */
        "movl $0, -0x1298(%ebp)\n" /* from_first_entity */
        "movl $0, -0x127c(%ebp)\n" /* from_num_clients */
        "movl $0, -0x1280(%ebp)\n" /* from_first_client */
        "jmp .Lf193c24_00193e79\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194825:\n"
        "movl %ebx, %eax\n" /* line 1143 | archivedFrame */
        "calll SV_GetCachedSnapshotInternal\n"
        "movl %eax, -0x12f0(%ebp)\n" /* cachedFrame */
        "testl %eax, %eax\n" /* line 1144 */
        "jne .Lf193c24_001942e3\n"
        "addl $1, %ebx\n" /* line 1146 | archivedFrame */
        "cmpl 0x2c(%edi), %ebx\n" /* line 1141 | i, archivedFrame */
        "jl .Lf193c24_00194825\n"
        "jmp .Lf193c24_001942cf\n"
        /* } scope */
        ".Lf193c24_00194847:\n"
        "movl -0x12f0(%ebp), %ebx\n" /* line 1546 | cachedFrame, state */
        "movl 0x10(%ebx), %eax\n" /* state */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00193c6b\n"
        "xorl %edi, %edi\n" /* i */
        "movl imp_svs, %ebx\n" /* state */
        "movl -0x12f0(%ebp), %ecx\n" /* cachedFrame */
        "jmp .Lf193c24_00194883\n"
        ".Lf193c24_00194868:\n"
        "addl $1, 0x26ac(%esi)\n" /* line 1561 | frame */
        "addl $1, %edi\n" /* line 1546 | i */
        "movl -0x12f0(%ebp), %eax\n" /* cachedFrame */
        "cmpl %edi, 0x10(%eax)\n" /* i */
        "jle .Lf193c24_00193c6b\n"
        "movl %eax, %ecx\n"
        ".Lf193c24_00194883:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1550 | state */
        "cltd\n"
        "idivl 0x14(%ebx)\n" /* state */
        "movl 0x24(%ebx), %eax\n" /* state */
        "movl %eax, -0x1304(%ebp)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "movl %edi, %eax\n" /* i */
        "addl 0x14(%ecx), %eax\n"
        "movl %eax, %ecx\n"
        "andl $0x80000fff, %ecx\n"
        "js .Lf193c24_0019490e\n"
        ".Lf193c24_001948b1:\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %ecx, %eax\n"
        "shll $5, %eax\n"
        "addl %ecx, %eax\n"
        "shll $3, %eax\n"
        "addl -0x1304(%ebp), %edx\n"
        "addl 0x4c(%ebx), %eax\n" /* state */
        "addl $4, %eax\n"
        "movl $0x5c, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1555 | state */
        "addl $1, %eax\n"
        "movl %eax, 0x1c(%ebx)\n" /* state */
        "cmpl $0x7ffffffd, %eax\n" /* line 1557 */
        "jle .Lf193c24_00194868\n"
        "movl $str_002b05cc, 4(%esp)\n" /* line 1559 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf193c24_00194868\n"
        ".Lf193c24_0019490e:\n"
        "subl $1, %ecx\n" /* line 1550 */
        "orl $0xfffff000, %ecx\n"
        "addl $1, %ecx\n"
        "jmp .Lf193c24_001948b1\n"
        /* } scope */
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_0019491c:\n"
        "movl %ecx, %eax\n" /* line 386 */
        "addl $0x20c48, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b05f0, (%esp)\n" /* "%s: Delta request from out of date packet.
" */
        "calll Com_DPrintf\n"
        "jmp .Lf193c24_00193d9b\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194938:\n"
        "movl $0, -0x12f0(%ebp)\n" /* line 1141 | cachedFrame */
        "jmp .Lf193c24_001942e3\n"
        /* } scope */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194947:\n"
        "leal -0x2c(%ebp), %ebx\n" /* line 639 | org, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll CM_PointLeafnum\n"
        "movl %eax, (%esp)\n" /* line 641 */
        "calll CM_LeafCluster\n"
        "testl %eax, %eax\n" /* line 642 */
        "js .Lf193c24_001949a9\n"
        "movl %eax, (%esp)\n" /* line 645 */
        "calll CM_ClusterPVS\n"
        "movl %eax, -0x12d0(%ebp)\n" /* bitvector */
        "calll G_GetFogOpaqueDistSqrd\n" /* line 647 */
        "fstps -0x12cc(%ebp)\n" /* fogOpaqueDistSqrd */
        "movss -0x12cc(%ebp), %xmm0\n" /* line 648 | fogOpaqueDistSqrd */
        "movaps %xmm0, %xmm1\n"
        "cmpneqss lit4_002ed684, %xmm0\n" /* 3.4028234663852886e+38f */
        "andps %xmm1, %xmm0\n"
        "movss %xmm0, -0x12cc(%ebp)\n" /* fogOpaqueDistSqrd */
        "movl imp_sv, %eax\n" /* line 651 */
        "movl 0x5f424(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf193c24_00194c86\n"
        /* } scope */
        ".Lf193c24_001949a9:\n"
        "movl imp_svs, %edx\n" /* line 1488 */
        "movl 0xc(%edx), %ecx\n"
        "movl %ecx, -0x12f4(%ebp)\n" /* client */
        "movl imp_sv_maxclients, %ecx\n"
        "movl (%ecx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf193c24_00193c6b\n"
        "movl $0, -0x1260(%ebp)\n"
        "movl %edx, %edi\n" /* i */
        "jmp .Lf193c24_00194a01\n"
        ".Lf193c24_001949d9:\n"
        "movl imp_sv_maxclients, %ecx\n"
        ".Lf193c24_001949df:\n"
        "addl $1, -0x1260(%ebp)\n"
        "addl $0x78f0c, -0x12f4(%ebp)\n" /* client */
        "movl (%ecx), %eax\n"
        "movl -0x1260(%ebp), %ebx\n" /* state */
        "cmpl 8(%eax), %ebx\n" /* state */
        "jge .Lf193c24_00193c6b\n"
        ".Lf193c24_00194a01:\n"
        "movl -0x12f4(%ebp), %ebx\n" /* line 1490 | client, state */
        "cmpl $1, (%ebx)\n" /* state */
        "jle .Lf193c24_001949df\n"
        "movl 0x1c(%edi), %eax\n" /* line 1492 | i */
        "cltd\n"
        "idivl 0x14(%edi)\n" /* i */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x24(%edi), %edx\n" /* i */
        "leal (%edx, %eax, 4), %ebx\n" /* state */
        "movl -0x1260(%ebp), %eax\n" /* line 1493 */
        "movl %eax, (%esp)\n"
        "calll G_GetClientState\n"
        "movl $0x5c, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll memcpy\n"
        "movl -0x1260(%ebp), %edx\n" /* line 1496 */
        "cmpl (%ebx), %edx\n" /* state */
        "jne .Lf193c24_001949d9\n"
        "movl 0x1c(%edi), %eax\n" /* line 1506 | i */
        "addl $1, %eax\n"
        "movl %eax, 0x1c(%edi)\n" /* i */
        "cmpl $0x7ffffffd, %eax\n" /* line 1508 */
        "jg .Lf193c24_00194c6d\n"
        ".Lf193c24_00194a61:\n"
        "addl $1, 0x26ac(%esi)\n" /* line 1512 | frame */
        "movl imp_sv_maxclients, %ecx\n"
        "jmp .Lf193c24_001949df\n"
        ".Lf193c24_00194a73:\n"
        "movl -0x1264(%ebp), %eax\n" /* line 1520 */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00194847\n"
        "movl $0, -0x125c(%ebp)\n"
        "movl imp_svs, %edi\n" /* i */
        "jmp .Lf193c24_00194ab3\n"
        ".Lf193c24_00194a93:\n"
        "addl $1, 0x26a8(%esi)\n" /* line 1542 | frame */
        "addl $1, -0x125c(%ebp)\n" /* line 1520 */
        "movl -0x1264(%ebp), %ecx\n"
        "cmpl %ecx, -0x125c(%ebp)\n"
        "je .Lf193c24_00194847\n"
        ".Lf193c24_00194ab3:\n"
        "movl 0x18(%edi), %eax\n" /* line 1523 | i */
        "cltd\n"
        "idivl 0x10(%edi)\n" /* i */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %ebx\n" /* state */
        "shll $8, %ebx\n" /* state */
        "subl %eax, %ebx\n" /* state */
        "addl 0x20(%edi), %ebx\n" /* i, state */
        "movl -0x12f0(%ebp), %ecx\n" /* line 1524 | cachedFrame */
        "movl 0xc(%ecx), %eax\n"
        "movl -0x125c(%ebp), %edx\n"
        "addl -0x1250(%ebp, %edx, 4), %eax\n"
        "movl %eax, %edx\n"
        "andl $0x80003fff, %edx\n"
        "js .Lf193c24_00194b7e\n"
        ".Lf193c24_00194aed:\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl 0x48(%edi), %eax\n" /* i */
        "movl $0xf0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll memcpy\n"
        "movl 0x10(%ebx), %eax\n" /* line 1527 | state */
        "testl %eax, %eax\n"
        "je .Lf193c24_00194b21\n"
        "addl -0x12ec(%ebp), %eax\n" /* line 1528 | deltaTime */
        "movl %eax, 0x10(%ebx)\n" /* state */
        ".Lf193c24_00194b21:\n"
        "movl 0x34(%ebx), %eax\n" /* line 1529 | state */
        "testl %eax, %eax\n"
        "je .Lf193c24_00194b31\n"
        "addl -0x12ec(%ebp), %eax\n" /* line 1530 | deltaTime */
        "movl %eax, 0x34(%ebx)\n" /* state */
        ".Lf193c24_00194b31:\n"
        "movl 0x54(%ebx), %eax\n" /* line 1531 | state */
        "testl %eax, %eax\n"
        "je .Lf193c24_00194b41\n"
        "addl -0x12ec(%ebp), %eax\n" /* line 1532 | deltaTime */
        "movl %eax, 0x54(%ebx)\n" /* state */
        ".Lf193c24_00194b41:\n"
        "movl 0x58(%ebx), %eax\n" /* line 1533 | state */
        "testl %eax, %eax\n"
        "je .Lf193c24_00194b51\n"
        "addl -0x12ec(%ebp), %eax\n" /* line 1534 | deltaTime */
        "movl %eax, 0x58(%ebx)\n" /* state */
        ".Lf193c24_00194b51:\n"
        "movl 0x18(%edi), %eax\n" /* line 1536 | i */
        "addl $1, %eax\n"
        "movl %eax, 0x18(%edi)\n" /* i */
        "cmpl $0x7ffffffd, %eax\n" /* line 1538 */
        "jle .Lf193c24_00194a93\n"
        "movl $str_002b05a8, 4(%esp)\n" /* line 1540 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf193c24_00194a93\n"
        ".Lf193c24_00194b7e:\n"
        "subl $1, %edx\n" /* line 1524 */
        "orl $0xffffc000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf193c24_00194aed\n"
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        /* { scope 5: e */
        ".Lf193c24_00194b8f:\n"
        "leal 0x108(%edx), %ecx\n" /* line 805 */
        "movl %ecx, -0x12b8(%ebp)\n"
        "addl $0xfc, %edx\n"
        "movl %edx, -0x12b4(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* lastLeaf */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x80, 0xc(%esp)\n"
        "leal -0x250(%ebp), %eax\n" /* leafs */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CM_BoxLeafnums\n"
        "movl %eax, %ebx\n" /* num_leafs */
        "testl %eax, %eax\n" /* line 806 */
        "je .Lf193c24_001944f7\n"
        "testl %ebx, %ebx\n" /* line 809 | num_leafs */
        "jg .Lf193c24_00194fb0\n"
        ".Lf193c24_00194bde:\n"
        "movss -0x12ac(%ebp), %xmm0\n" /* line 821 | fogOpaqueDistSqrd */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf193c24_00194f7e\n"
        "jne .Lf193c24_00194f7e\n"
        /* { scope 6 */
        ".Lf193c24_00194bf9:\n"
        "cmpl $0x400, -0x1264(%ebp)\n" /* line 608 */
        "je .Lf193c24_001944f7\n"
        "movl -0x12a8(%ebp), %eax\n" /* line 613 | e */
        "movl -0x1264(%ebp), %ebx\n" /* i */
        "movl %eax, -0x1250(%ebp, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 614 | i */
        "movl %ebx, -0x1264(%ebp)\n" /* i */
        "jmp .Lf193c24_001944f7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf193c24_00194c2a:\n"
        "movl $0, -0x12ec(%ebp)\n" /* line 1446 | deltaTime */
        "jmp .Lf193c24_00194328\n"
        ".Lf193c24_00194c39:\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "jmp .Lf193c24_001946ac\n"
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194c41:\n"
        "movl -0x12e4(%ebp), %edx\n" /* line 1138 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl -0x12e0(%ebp)\n"
        "movl %eax, -0x12e8(%ebp)\n" /* archiveTime */
        "xorl %ebx, %ebx\n" /* archivedFrame */
        "jmp .Lf193c24_001942c3\n"
        /* } scope */
        ".Lf193c24_00194c6d:\n"
        "movl $str_002b05cc, 4(%esp)\n" /* line 1510 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf193c24_00194a61\n"
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194c86:\n"
        "movl $0, -0x12c8(%ebp)\n" /* line 651 | entnum */
        "movl $0, -0x1270(%ebp)\n"
        "jmp .Lf193c24_00194cf2\n"
        ".Lf193c24_00194c9c:\n"
        "jl .Lf193c24_00194cac\n" /* line 675 */
        "movl imp_svs, %eax\n"
        "cmpl 4(%eax), %edx\n"
        "js .Lf193c24_0019500d\n"
        ".Lf193c24_00194cac:\n"
        "cmpl $0x400, -0x1270(%ebp)\n" /* line 590 */
        "je .Lf193c24_00194cd4\n"
        "movl -0x12c8(%ebp), %eax\n" /* line 595 | entnum */
        "movl -0x1270(%ebp), %ebx\n" /* i */
        "movl %eax, -0x1250(%ebp, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 596 | i */
        "movl %ebx, -0x1270(%ebp)\n" /* i */
        ".Lf193c24_00194cd4:\n"
        "addl $1, -0x12c8(%ebp)\n" /* line 651 | entnum */
        "movl imp_sv, %eax\n"
        "movl -0x12c8(%ebp), %ebx\n" /* entnum, i */
        "cmpl %ebx, 0x5f424(%eax)\n" /* i */
        "jle .Lf193c24_00194e55\n"
        ".Lf193c24_00194cf2:\n"
        "movl -0x12c8(%ebp), %eax\n" /* line 653 | entnum */
        "movl %eax, (%esp)\n"
        "calll SV_GentityNum\n"
        "movl %eax, -0x12d4(%ebp)\n" /* ent */
        "cmpb $0, 0xf0(%eax)\n" /* line 656 */
        "je .Lf193c24_00194cd4\n"
        "movl -0x12c4(%ebp), %edx\n" /* line 661 | clientNum */
        "cmpl %edx, -0x12c8(%ebp)\n" /* entnum */
        "je .Lf193c24_00194cd4\n"
        "movl 0x100(%eax), %edx\n" /* line 664 */
        "cmpl $0, %edx\n"
        "jne .Lf193c24_00194c9c\n"
        "testb $1, 0xf2(%eax)\n" /* line 667 */
        "jne .Lf193c24_00194cd4\n"
        "movl -0x12c4(%ebp), %eax\n" /* line 670 | clientNum */
        "sarl $5, %eax\n"
        "movl -0x12c4(%ebp), %ecx\n" /* clientNum */
        "andl $0x1f, %ecx\n"
        "movl -0x12d4(%ebp), %ebx\n" /* ent, i */
        "movl 0xf4(%ebx, %eax, 4), %eax\n" /* i */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf193c24_00194cd4\n"
        ".Lf193c24_00194d5e:\n"
        "movl -0x12d4(%ebp), %ecx\n" /* line 684 | ent */
        "movzbl 0xf2(%ecx), %eax\n"
        "testb $0x18, %al\n"
        "jne .Lf193c24_00194cac\n"
        "movl -0x12d4(%ebp), %edx\n" /* line 690 | ent */
        "movl %edx, (%esp)\n"
        "calll SV_SvEntityForGentity\n"
        "movl %eax, %edi\n" /* svEnt */
        "movl 0x118(%eax), %ecx\n" /* line 693 */
        "movl %ecx, -0x12dc(%ebp)\n"
        "testl %ecx, %ecx\n"
        "je .Lf193c24_00194cd4\n"
        "movl -0x12dc(%ebp), %eax\n" /* line 699 */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00194e09\n"
        "movl 0x11c(%edi), %edx\n" /* line 701 | svEnt */
        "movl %edx, %eax\n" /* line 702 */
        "sarl $3, %eax\n"
        "movl -0x12d0(%ebp), %ecx\n" /* bitvector */
        "movzbl (%eax, %ecx), %eax\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf193c24_00194e09\n"
        "movl %edi, %ebx\n" /* line 703 | svEnt, i */
        "movl $0, -0x12d8(%ebp)\n" /* i */
        ".Lf193c24_00194dcd:\n"
        "addl $1, -0x12d8(%ebp)\n" /* line 699 | i */
        "movl -0x12d8(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x12dc(%ebp)\n"
        "je .Lf193c24_00194ef1\n"
        "movl 0x120(%ebx), %edx\n" /* line 701 | i */
        "addl $4, %ebx\n" /* i */
        "movl %edx, %eax\n" /* line 702 */
        "sarl $3, %eax\n"
        "movl -0x12d0(%ebp), %ecx\n" /* bitvector */
        "movzbl (%eax, %ecx), %eax\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf193c24_00194dcd\n"
        ".Lf193c24_00194e09:\n"
        "movss -0x12cc(%ebp), %xmm0\n" /* line 722 | fogOpaqueDistSqrd */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf193c24_00194f42\n"
        "jne .Lf193c24_00194f42\n"
        /* { scope 5: e */
        ".Lf193c24_00194e24:\n"
        "cmpl $0x400, -0x1270(%ebp)\n" /* line 590 */
        "je .Lf193c24_00194cd4\n"
        "movl -0x12c8(%ebp), %ecx\n" /* line 595 | entnum */
        "movl -0x1270(%ebp), %edx\n"
        "movl %ecx, -0x1250(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 596 */
        "movl %edx, -0x1270(%ebp)\n"
        "jmp .Lf193c24_00194cd4\n"
        /* } scope */
        /* } scope */
        ".Lf193c24_00194e55:\n"
        "movl -0x1270(%ebp), %eax\n" /* line 1473 */
        "testl %eax, %eax\n"
        "jle .Lf193c24_001949a9\n"
        "xorl %edi, %edi\n" /* i */
        "movl imp_svs, %ebx\n" /* state */
        "jmp .Lf193c24_00194e83\n"
        ".Lf193c24_00194e6d:\n"
        "addl $1, 0x26a8(%esi)\n" /* line 1484 | frame */
        "addl $1, %edi\n" /* line 1473 | i */
        "cmpl -0x1270(%ebp), %edi\n" /* i */
        "je .Lf193c24_001949a9\n"
        ".Lf193c24_00194e83:\n"
        "movl -0x1250(%ebp, %edi, 4), %eax\n" /* line 1475 */
        "movl %eax, (%esp)\n"
        "calll SV_GentityNum\n"
        "movl %eax, -0x130c(%ebp)\n" /* ent */
        "movl 0x18(%ebx), %ecx\n" /* line 1477 | state */
        "movl %ecx, %eax\n"
        "cltd\n"
        "idivl 0x10(%ebx)\n" /* state */
        "movl %edx, %ecx\n"
        "shll $4, %edx\n"
        "shll $8, %ecx\n"
        "subl %edx, %ecx\n"
        "addl 0x20(%ebx), %ecx\n" /* state */
        "movl $0xf0, 8(%esp)\n"
        "movl -0x130c(%ebp), %eax\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x18(%ebx), %eax\n" /* line 1478 | state */
        "addl $1, %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* state */
        "cmpl $0x7ffffffd, %eax\n" /* line 1480 */
        "jle .Lf193c24_00194e6d\n"
        "movl $str_002b05a8, 4(%esp)\n" /* line 1482 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf193c24_00194e6d\n"
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194ef1:\n"
        "movl 0x15c(%edi), %ebx\n" /* line 710 | svEnt, i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf193c24_00194cd4\n"
        "cmpl %edx, %ebx\n" /* line 713 | i */
        "jl .Lf193c24_00194f35\n"
        "movl %edx, %eax\n" /* line 715 */
        "sarl $3, %eax\n"
        "movl -0x12d0(%ebp), %ecx\n" /* bitvector */
        "movzbl (%ecx, %eax), %eax\n"
        ".Lf193c24_00194f12:\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf193c24_00194f35\n"
        "addl $1, %edx\n" /* line 713 */
        "cmpl %ebx, %edx\n" /* i */
        "jg .Lf193c24_00194f35\n"
        "movl %edx, %eax\n" /* line 715 */
        "sarl $3, %eax\n"
        "movl -0x12d0(%ebp), %ecx\n" /* bitvector */
        "movzbl (%eax, %ecx), %eax\n"
        "jmp .Lf193c24_00194f12\n"
        ".Lf193c24_00194f35:\n"
        "cmpl %ebx, %edx\n" /* line 718 | i */
        "jne .Lf193c24_00194e09\n"
        "jmp .Lf193c24_00194cd4\n"
        ".Lf193c24_00194f42:\n"
        "movss %xmm0, 0xc(%esp)\n" /* line 722 */
        "leal -0x2c(%ebp), %eax\n" /* org */
        "movl %eax, 8(%esp)\n"
        "movl -0x12d4(%ebp), %eax\n" /* ent */
        "addl $0x12c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x12d4(%ebp), %eax\n" /* ent */
        "addl $0x120, %eax\n"
        "movl %eax, (%esp)\n"
        "calll BoxDistSqrdExceeds\n"
        "testl %eax, %eax\n"
        "jne .Lf193c24_00194cd4\n"
        "jmp .Lf193c24_00194e24\n"
        /* } scope */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        /* { scope 5: e */
        ".Lf193c24_00194f7e:\n"
        "movss %xmm0, 0xc(%esp)\n" /* line 821 */
        "leal -0x2c(%ebp), %eax\n" /* org */
        "movl %eax, 8(%esp)\n"
        "movl -0x12b8(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x12b4(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll BoxDistSqrdExceeds\n"
        "testl %eax, %eax\n"
        "jne .Lf193c24_001944f7\n"
        "jmp .Lf193c24_00194bf9\n"
        ".Lf193c24_00194fb0:\n"
        "xorl %edi, %edi\n" /* line 806 | i */
        "jmp .Lf193c24_00194fbf\n"
        ".Lf193c24_00194fb4:\n"
        "addl $1, %edi\n" /* line 809 | i */
        "cmpl %ebx, %edi\n" /* num_leafs, i */
        "je .Lf193c24_001944f7\n"
        ".Lf193c24_00194fbf:\n"
        "movl -0x250(%ebp, %edi, 4), %eax\n" /* line 811 */
        "movl %eax, (%esp)\n"
        "calll CM_LeafCluster\n"
        "movl %eax, %ecx\n"
        "cmpl $-1, %eax\n" /* line 812 */
        "je .Lf193c24_00194fb4\n"
        "sarl $3, %eax\n"
        "movl -0x12b0(%ebp), %edx\n" /* clientpvs */
        "movzbl (%edx, %eax), %eax\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf193c24_00194fb4\n"
        "cmpl %edi, %ebx\n" /* line 818 | i, num_leafs */
        "je .Lf193c24_001944f7\n"
        "jmp .Lf193c24_00194bde\n"
        "movl %eax, %ebx\n" /* num_leafs */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "leal -0x1c(%ebp), %ecx\n" /* line 1762 | msg_buf_large_local */
        "movl %ecx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll __Unwind_Resume\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_0019500d:\n"
        "movl -0x12d4(%ebp), %edx\n" /* line 680 | ent */
        "movl $0, 0x100(%edx)\n"
        "jmp .Lf193c24_00194d5e\n"
    );
}

/* line 2077 */
void SV_SendClientMessages(void)
{
    byte *sv = (byte *)imp_sv;
    byte *svs = (byte *)imp_svs;
    byte *c;
    int i, numclients;
    int maxClients;
    int svsTime;
    int sendFrag, messageSize;
    int rate, rateMsec;
    byte *dvar;
    float totalBps, totalUBps;
    int j;

    /* Reset bandwidth counters */
    *(int *)(sv + 0x5f48c) = 0;
    *(int *)(sv + 0x5f4e4) = 0;

    c = *(byte **)(svs + SVS_CLIENTS);
    dvar = *(byte **)imp_sv_maxclients;
    maxClients = *(int *)(dvar + 8);
    numclients = 0;

    svsTime = *(int *)(svs + SVS_TIME);

    for (i = 0; i < maxClients; i++, c += CLIENT_STRIDE) {
        if (*(int *)(c + CLIENT_STATE) == 0)
            continue;
        /* Skip timing check: the game clock runs too slowly with the
           stub renderer (~1ms per frame) causing fragment delivery and
           snapshot timing to stall.  TODO: fix the clock properly. */
        #if 0
        if (svsTime < *(int *)(c + CLIENT_SNAPSHOTMSEC))
            continue;
        #endif

        numclients++;

        /* If the client is CS_CONNECTED (2) and hasn't received a
           gamestate yet, send it now.  In a listen-server +devmap flow
           the local client never sends the initial netchan packet that
           normally triggers the gamestate send in SV_ExecuteClientMessage. */
        if (*(int *)(c + CLIENT_STATE) == 2) {
            extern void SV_SendClientGameState(client_t *);
            SV_SendClientGameState((client_t *)c);
            continue;
        }

        sendFrag = *(int *)(c + CLIENT_NETCHAN_SENDFRAG);
        if (sendFrag != 0) {
            /* Send pending fragments immediately instead of rate-limiting.
               The stub renderer makes the game clock advance very slowly
               (~1ms per frame) so the original rate-limited path stalls
               fragment delivery for minutes.  For local/listen-server
               play this is fine; for remote play the rate-limited path
               below will still be reached once this fast-path is
               made conditional on NA_LOOPBACK. */
            SV_Netchan_TransmitNextFragment((netchan_t *)(c + CLIENT_NETCHAN));
            continue;
        }
        if (sendFrag == 0) {
            /* No pending fragment - send snapshot */
            SV_SendClientSnapshot((client_t *)c);
            SV_SendClientVoiceData((client_t *)c);
            continue;
        }

        /* Has pending fragment - calculate rate and retransmit */
        messageSize = *(int *)(c + CLIENT_NETCHAN_SENDLEN) - *(int *)(c + CLIENT_NETCHAN_SENDSTART);
        if (messageSize > 0x5dc)
            messageSize = 0x5dc;

        /* messageSize * 1000 (messageSize * 5 * 5 * 5 * 8) */
        {
            int msgBytes = messageSize * 5 * 5 * 5 * 8;

            rate = *(int *)(c + CLIENT_RATE);
            dvar = *(byte **)&sv_minPingRate_dvar;
            dvar = *(byte **)dvar;
            if (*(int *)(dvar + 8) != 0) {
                if (*(int *)(dvar + 8) <= 0x3e7) {
                    Dvar_SetInt(dvar, 0x3e8);
                    dvar = *(byte **)&sv_minPingRate_dvar;
                    dvar = *(byte **)dvar;
                }
                if (rate > *(int *)(dvar + 8))
                    rate = *(int *)(dvar + 8);
            }

            rateMsec = (msgBytes + 0xbb80) / rate;

            dvar = *(byte **)&showpackets_dvar;
            if (*(byte *)(*(byte **)dvar + 8) != 0) {
                Com_Printf("It would take %ims to send %i bytes to client %s (rate %i)\n",
                    rateMsec, messageSize, c + CLIENT_NAME, *(int *)(c + CLIENT_RATE));
            }
        }

        *(int *)(c + CLIENT_SNAPSHOTMSEC) = svsTime + rateMsec;
        SV_Netchan_TransmitNextFragment((netchan_t *)(c + CLIENT_NETCHAN));
    }

    /* BPS tracking */
    dvar = *(byte **)imp_sv_showAverageBPS;
    if (*(byte *)(dvar + 8) == 0 || numclients <= 0)
        return;

    sv = (byte *)imp_sv;
    totalBps = 0.0f;
    totalUBps = 0.0f;

    /* Loop over 19 history slots (sv + 0 to sv + 0x4c, step 4) */
    for (j = 0; j < 19; j++) {
        int bpsVal = *(int *)(sv + 0x5f43c + j * 4);
        *(int *)(sv + 0x5f438 + j * 4) = bpsVal;
        totalBps += (float)bpsVal;

        int ubpsVal = *(int *)(sv + 0x5f498 + j * 4);
        *(int *)(sv + 0x5f494 + j * 4) = ubpsVal;
        totalUBps += (float)ubpsVal;
    }

    {
        int sentBps = *(int *)(sv + 0x5f48c);
        *(int *)(sv + 0x5f484) = sentBps;
        float bpsTotal = (float)sentBps + totalBps;

        int sentUBps = *(int *)(sv + 0x5f4e4);
        *(int *)(sv + 0x5f4e0) = sentUBps;
        float ubpsTotal = (float)sentUBps + totalUBps;

        if (sentBps >= *(int *)(sv + 0x5f490))
            *(int *)(sv + 0x5f490) = sentBps;
        if (sentUBps >= *(int *)(sv + 0x5f4e8))
            *(int *)(sv + 0x5f4e8) = sentUBps;

        int counter = *(int *)(sv + 0x5f488) + 1;
        *(int *)(sv + 0x5f488) = counter;

        if (counter > 19) {
            *(int *)(sv + 0x5f488) = 0;
            float bpsAvg = bpsTotal / 20.0f;
            float ubpsAvg = ubpsTotal / 20.0f;
            float compressionRatio = bpsAvg / ubpsAvg;
            float pctSaved = (1.0f - compressionRatio) * 100.0f;
            float totalPctSaved = pctSaved + *(float *)(sv + 0x5f4ec);
            *(float *)(sv + 0x5f4ec) = totalPctSaved;
            int numSamples = *(int *)(sv + 0x5f4f0) + 1;
            *(int *)(sv + 0x5f4f0) = numSamples;
            float avgPctSaved = totalPctSaved / (float)numSamples;
            Com_DPrintf("bpspc(%2.0f) bps(%2.0f) pk(%i) ubps(%2.0f) upk(%i) cr(%2.2f)",
                (double)(bpsAvg / (float)numclients), (double)bpsAvg,
                *(int *)(sv + 0x5f490), (double)ubpsAvg,
                *(int *)(sv + 0x5f4e8), (double)pctSaved, (double)avgPctSaved);
        }
    }
}

#else

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
    byte *svs_p = (byte *)imp_svs;
    byte *sv_p = (byte *)imp_sv;
    byte ps[0x26a8]; /* playerState_t buffer */
    byte archivedEnt[0xf0]; /* archived entity buffer */

    LargeLocal_LargeLocal(msg_buf_large_local, 0x20000);
    msg_buf = LargeLocal_GetBuf(msg_buf_large_local);

    /* Check sv.state == 2 (SS_GAME) */
    if (*(int *)sv_p != 2)
        goto cleanup;

    /* Check numOneWayClients > 0 */
    if (*(int *)(svs_p + 0x28) == 0)
        goto cleanup;

    /* Init message buffer */
    MSG_Init((msg_t *)msg, msg_buf, 0x20000);

    /* Find old cached frame to delta against */
    {
        int archivedFrameNum = *(int *)(svs_p + 0x44);
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
            newnum = *(int *)(svs_p + 0x2c) - *(int *)(fps_val + 8);
        }

        /* Walk backwards to find a suitable old frame */
        {
            int idx = archivedFrameNum - 1;
            cachedFrames = *(byte **)(svs_p + 0x50);

            while (idx >= oldindex) {
                int cfSlot = signedMod512(idx);
                byte *cf = cachedFrames + cfSlot * 28;

                if (*(int *)cf <= newnum) {
                    /* Check if this frame has valid delta data */
                    if (*(int *)(cf + 0x18) == 0) {
                        /* This frame doesn't use delta - check if its entity/client indices are recent enough */
                        byte *svs2 = (byte *)imp_svs;
                        if (*(int *)(cf + 0x0c) < *(int *)(svs2 + 0x3c) - 0x4000)
                            break;
                        if (*(int *)(cf + 0x14) < *(int *)(svs2 + 0x40) - (int)&__mh_execute_header)
                            break;

                        /* Write delta reference */
                        MSG_WriteBit0((msg_t *)msg);
                        MSG_WriteLong((msg_t *)msg, *(int *)cf);
                        MSG_WriteLong((msg_t *)msg, *(int *)(svs2 + 4));

                        /* Write client deltas */
                        {
                            byte *maxclients_dvar = *(byte **)&sv_maxclients_dvar;
                            byte *maxclients_val = *(byte **)maxclients_dvar;
                            int to_num_clients = *(int *)(maxclients_val + 8);
                            int from_num_clients = *(int *)(cf + 0x10);
                            byte *cachedClient = NULL;
                            int newIdx = 0;
                            int oldIdx2 = 0;

                            while (1) {
                                if (newIdx >= to_num_clients) {
                                    /* Process remaining old clients */
                                    while (oldIdx2 < from_num_clients) {
                                        int archClientIdx = oldIdx2 + *(int *)(cf + 0x14);
                                        int archSlot = signedMod4096(archClientIdx);
                                        byte *svs3 = (byte *)imp_svs;
                                        cachedClient = *(byte **)(svs3 + 0x4c) + archSlot * 9992;

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
                                    byte *svs4 = (byte *)imp_svs;
                                    byte *clients = *(byte **)(svs4 + 0x0c);
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
                                    int archClientIdx = oldIdx2 + *(int *)(cf + 0x14);
                                    int archSlot = signedMod4096(archClientIdx);
                                    byte *svs3 = (byte *)imp_svs;
                                    cachedClient = *(byte **)(svs3 + 0x4c) + archSlot * 9992;
                                    int oldClientNum = *(int *)(cachedClient + 4);

                                    if (oldClientNum == newIdx) {
                                        /* Delta from old */
                                        void *clientState = G_GetClientState(newIdx);
                                        MSG_WriteDeltaClient((msg_t *)msg, cachedClient + 4, (byte *)clientState, 1);

                                        /* Write playerstate */
                                        int hasPS = GetFollowPlayerState(newIdx, ps);
                                        if (hasPS) {
                                            MSG_WriteBit1((msg_t *)msg);
                                            MSG_WriteDeltaPlayerstate((msg_t *)msg, cachedClient + 0x60, ps);
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
                                            MSG_WriteDeltaPlayerstate((msg_t *)msg, cachedClient + 0x60, ps);
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
                            int numEnts = *(int *)(sv_p + 0x5f424);
                            int i;

                            if (numEnts > 0) {
                                for (i = 0; i < numEnts; i++) {
                                    byte *gent = SV_GentityNum(i);
                                    if (*(byte *)(gent + 0xf0) == 0)
                                        continue;

                                    /* Check if entity has locational data */
                                    int contents = *(int *)(gent + 0x100);
                                    if (contents == 0) {
                                        /* Check svFlags bit 0 */
                                        if (!(*(byte *)(gent + 0xf2) & 1)) {
                                            /* Check if linked to any clusters */
                                            byte *svEnt = (byte *)SV_SvEntityForGentity(gent);
                                            if (!(*(byte *)(gent + 0xf2) & 0x18)) {
                                                if (*(int *)(svEnt + 0x118) == 0)
                                                    continue;
                                            }
                                        }
                                    }

                                    /* Build archived entity */
                                    memcpy(archivedEnt, gent, 0xf0);
                                    *(int *)(archivedEnt + 0xf0) = *(byte *)(gent + 0xf2);
                                    if (*(int *)(gent + 0x100) != 0) {
                                        *(int *)(archivedEnt + 0xf0) |= 8;
                                    }
                                    *(int *)(archivedEnt + 0xf4) = *(int *)(gent + 0xf4);
                                    *(int *)(archivedEnt + 0xf8) = *(int *)(gent + 0xf8);
                                    /* Copy absmin (3 floats) */
                                    *(int *)(archivedEnt + 0xfc) = *(int *)(gent + 0x120);
                                    *(int *)(archivedEnt + 0x100) = *(int *)(gent + 0x124);
                                    *(int *)(archivedEnt + 0x104) = *(int *)(gent + 0x128);
                                    /* Copy absmax (3 floats) */
                                    *(int *)(archivedEnt + 0x108) = *(int *)(gent + 0x12c);
                                    *(int *)(archivedEnt + 0x10c) = *(int *)(gent + 0x130);
                                    *(int *)(archivedEnt + 0x110) = *(int *)(gent + 0x134);

                                    /* Write delta from baseline */
                                    {
                                        int entNum = *(int *)gent;
                                        byte *baseline = sv_p + 0x241c + entNum * 372;
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
        byte *svs2 = (byte *)imp_svs;
        MSG_WriteLong((msg_t *)msg, *(int *)(svs2 + 4));
    }

    /* Set up cached frame for current archive */
    {
        byte *svs2 = (byte *)imp_svs;
        int frameNum = *(int *)(svs2 + 0x44);
        int frameSlot = signedMod512(frameNum);
        byte *cachedFrames = *(byte **)(svs2 + 0x50);
        byte *cachedFrame = cachedFrames + frameSlot * 28;

        *(int *)(cachedFrame + 0) = *(int *)(svs2 + 0x2c); /* serverTime = archivedFrameCount */
        *(int *)(cachedFrame + 8) = 0;                       /* numEntities = 0 */
        *(int *)(cachedFrame + 0xc) = *(int *)(svs2 + 0x3c); /* firstEntity = archivedEntNumIndex */
        *(int *)(cachedFrame + 0x10) = 0;                     /* numClients = 0 */
        *(int *)(cachedFrame + 0x14) = *(int *)(svs2 + 0x40); /* firstClient = archivedClientNumIndex */
        *(int *)(cachedFrame + 0x18) = 0;                     /* usesDelta = 0 */
        *(int *)(cachedFrame + 4) = *(int *)(svs2 + 4);       /* archiveTime = svs.time */

        /* Write per-client data */
        {
            byte *clients = *(byte **)(svs2 + 0x0c);
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
                    int clientArchIdx = *(int *)(svs2 + 0x40);
                    int clientSlot = signedMod4096(clientArchIdx);
                    byte *archivedClient = *(byte **)(svs2 + 0x4c) + clientSlot * 9992;

                    /* Copy client state */
                    {
                        void *clientState = G_GetClientState(c);
                        memcpy(archivedClient + 4, clientState, 0x5c);
                    }

                    /* Write delta */
                    MSG_WriteDeltaClient((msg_t *)msg, NULL, archivedClient + 4, 1);

                    /* Write playerstate */
                    {
                        int hasPS = GetFollowPlayerState(c, archivedClient + 0x60);
                        *(int *)archivedClient = hasPS;

                        if (hasPS) {
                            MSG_WriteBit1((msg_t *)msg);
                            MSG_WriteDeltaPlayerstate((msg_t *)msg, NULL, archivedClient + 0x60);
                        } else {
                            MSG_WriteBit0((msg_t *)msg);
                        }
                    }

                    /* Increment archivedClientNumIndex */
                    {
                        byte *svs3 = (byte *)imp_svs;
                        int newClientIdx = *(int *)(svs3 + 0x40) + 1;
                        *(int *)(svs3 + 0x40) = newClientIdx;
                        if (newClientIdx > 0x7ffffffd) {
                            Com_Error(0, str_002b0440);
                        }
                    }

                    /* Increment cachedFrame numClients */
                    cachedFrame = *(byte **)(((byte *)imp_svs) + 0x50) + frameSlot * 28;
                    *(int *)(cachedFrame + 0x10) += 1;

                    /* Re-read maxclients_dvar */
                    maxclients_val = *(byte **)(*(byte **)&sv_maxclients_dvar);
                }
            }
        }

        /* Write client end marker */
        MSG_WriteBit0((msg_t *)msg);

        /* Write entity data */
        {
            int numEnts = *(int *)(sv_p + 0x5f424);
            int i;

            if (numEnts > 0) {
                for (i = 0; i < numEnts; i++) {
                    byte *gent = SV_GentityNum(i);
                    if (*(byte *)(gent + 0xf0) == 0)
                        continue;

                    int entityContents = *(int *)(gent + 0x100);
                    if (entityContents == 0) {
                        if (!(*(byte *)(gent + 0xf2) & 1)) {
                            byte *svEnt = (byte *)SV_SvEntityForGentity(gent);
                            if (!(*(byte *)(gent + 0xf2) & 0x18)) {
                                if (*(int *)(svEnt + 0x118) == 0)
                                    continue;
                            }
                        }
                    }

                    /* Write archived entity */
                    {
                        byte *svs4 = (byte *)imp_svs;
                        int entArchIdx = *(int *)(svs4 + 0x3c);
                        int entSlot = signedMod16384(entArchIdx);

                        byte *archivedEntSlot = *(byte **)(svs4 + 0x48) + entSlot * 276;

                        /* Copy entity state */
                        memcpy(archivedEntSlot, gent, 0xf0);
                        *(int *)(archivedEntSlot + 0xf0) = *(byte *)(gent + 0xf2);
                        if (*(int *)(gent + 0x100) != 0) {
                            *(int *)(archivedEntSlot + 0xf0) |= 8;
                        }
                        *(int *)(archivedEntSlot + 0xf4) = *(int *)(gent + 0xf4);
                        *(int *)(archivedEntSlot + 0xf8) = *(int *)(gent + 0xf8);
                        /* absmin */
                        *(int *)(archivedEntSlot + 0xfc) = *(int *)(gent + 0x120);
                        *(int *)(archivedEntSlot + 0x100) = *(int *)(gent + 0x124);
                        *(int *)(archivedEntSlot + 0x104) = *(int *)(gent + 0x128);
                        /* absmax */
                        *(int *)(archivedEntSlot + 0x108) = *(int *)(gent + 0x12c);
                        *(int *)(archivedEntSlot + 0x10c) = *(int *)(gent + 0x130);
                        *(int *)(archivedEntSlot + 0x110) = *(int *)(gent + 0x134);

                        /* Write delta from baseline */
                        {
                            int entNum = *(int *)gent;
                            byte *baseline = sv_p + 0x241c + entNum * 372;
                            MSG_WriteDeltaArchivedEntity((msg_t *)msg, baseline, archivedEntSlot, 1);
                        }

                        /* Increment archivedEntNumIndex */
                        {
                            byte *svs5 = (byte *)imp_svs;
                            int newEntIdx = *(int *)(svs5 + 0x3c) + 1;
                            *(int *)(svs5 + 0x3c) = newEntIdx;
                            if (newEntIdx > 0x7ffffffd) {
                                Com_Error(0, str_002b0468);
                            }
                        }

                        /* Increment cachedFrame numEntities */
                        {
                            byte *cf2 = *(byte **)(((byte *)imp_svs) + 0x50) + frameSlot * 28;
                            *(int *)(cf2 + 8) += 1;
                        }
                    }
                }
            }
        }

        /* Increment archivedFrameNum */
        {
            byte *svs5 = (byte *)imp_svs;
            int newFrameNum = *(int *)(svs5 + 0x44) + 1;
            *(int *)(svs5 + 0x44) = newFrameNum;
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
        byte *svs2 = (byte *)imp_svs;
        int archivedFrameCount = *(int *)(svs2 + 0x2c);
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

        entParts = *(byte **)(svs2 + 0x30);
        byte *partEntry = entParts + bufIndex * 8;

        bufOffset = *(int *)(svs2 + 0x38);
        *(int *)partEntry = bufOffset; /* startOffset */

        /* msg data offset and length */
        msgDataLen = *(int *)(msg + 0xc); /* msg.cursize, stored at offset 0xc from msg_t base */
        /* Actually checking the asm: "movl -0x28(%ebp), %eax" with msg at -0x34(%ebp).
         * -0x28 = -0x34 + 0xc. So yes, msg.cursize is at offset 0xc in msg_t. */
        *(int *)(partEntry + 4) = msgDataLen;

        /* Copy message data to archived entity buffer with ring wrap */
        bufSize = 0x2000000; /* 33554432 */
        remaining = signedMod33554432(bufOffset);

        if (remaining + msgDataLen <= bufSize) {
            /* No wrap needed */
            byte *archBuf = *(byte **)(svs2 + 0x34);
            byte *msgData = *(byte **)(msg + 4); /* msg.data pointer at offset 4 */
            memcpy(archBuf + remaining, msgData, msgDataLen);
        } else {
            /* Wrap around */
            int firstPart = bufSize - remaining;
            byte *archBuf = *(byte **)(svs2 + 0x34);
            byte *msgData = *(byte **)(msg + 4);

            memcpy(archBuf + remaining, msgData, firstPart);
            memcpy(archBuf, msgData + firstPart, msgDataLen - firstPart);
        }
    }

    /* Increment archivedFrameCount */
    {
        byte *svs2 = (byte *)imp_svs;
        int newCount = *(int *)(svs2 + 0x2c) + 1;
        *(int *)(svs2 + 0x2c) = newCount;
        if (newCount > 0x7ffffffd) {
            Com_Error(0, str_002b0520);
        }
    }

cleanup:
    ZN10LargeLocalD1Ev(msg_buf_large_local);
}
#endif
