/* Converted to C from ASM: sv_voice_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_voice_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern void LargeLocal_LargeLocal(LargeLocal *ll, int size);
extern void *LargeLocal_GetBuf(LargeLocal *ll);
extern void ZN10LargeLocalD1Ev(LargeLocal *ll);
extern void MSG_Init(msg_t *msg, byte *data, int length);
extern void MSG_WriteString(msg_t *msg, const char *s);
extern void MSG_WriteByte(msg_t *msg, int c);
extern void MSG_WriteData(msg_t *msg, const void *data, int length);
extern int MSG_ReadByte(msg_t *msg);
extern int MSG_ReadShort(msg_t *msg);
extern void MSG_ReadData(msg_t *msg, void *data, int len);
extern void NET_OutOfBandVoiceData(netsrc_t sock, netadr_t adr, byte *data, int len);
extern void G_BroadcastVoice(gentity_t *talker, VoicePacket_t *voicePacket);
extern void Com_Printf(const char *msg, ...);

extern byte *svs_ptr;        /* imp_svs */
extern byte *sv_voice_dvar;  /* imp_sv_voice */

void SV_SendClientVoiceData(client_t *client);
Bool SV_ClientWantsVoiceData(int clientNum);
Bool SV_ClientHasClientMuted(int listener, int talker);
void SV_QueueVoicePacket(int talkerNum, int clientNum, VoicePacket_t *voicePacket);
void SV_UserVoice(client_t *cl, msg_t *msg);
void SV_PreGameUserVoice(client_t *cl, msg_t *msg);

/* Voice packet stride: sizeof(VoicePacket_t) = 0x105 (261 bytes, packed) */
/* Voice packets start at client + 0x765fc */
/* voicePacketCount at client + 0x78ec4 */
/* muteList at client + 0x78ec8 */
/* sendVoice at client + 0x78f08 */
/* Client stride: 0x78f0c */

/* line 59 */
void SV_SendClientVoiceData(client_t *client)
{
    byte _ll_buf[16];
    byte *buf;
    msg_t msg;
    netadr_t adr;
    int i;
    byte *pkt;

    LargeLocal_LargeLocal((LargeLocal *)_ll_buf, 0x20000);
    buf = (byte *)LargeLocal_GetBuf((LargeLocal *)_ll_buf);

    /* Check client state == CS_ACTIVE (4) */
    if (client->state != 4) {
        ZN10LargeLocalD1Ev((LargeLocal *)_ll_buf);
        return;
    }

    /* Check voicePacketCount > 0 */
    if (*(int *)((byte *)client + 0x78ec4) == 0) {
        ZN10LargeLocalD1Ev((LargeLocal *)_ll_buf);
        return;
    }

    /* Build voice data message */
    MSG_Init(&msg, buf, 0x20000);
    MSG_WriteString(&msg, "voicePacket");

    /* Write packet count */
    MSG_WriteByte(&msg, *(int *)((byte *)client + 0x78ec4));

    /* Write each voice packet */
    if (*(int *)((byte *)client + 0x78ec4) > 0) {
        pkt = (byte *)client;
        for (i = 0; i < *(int *)((byte *)client + 0x78ec4); i++) {
            /* Write talker byte */
            MSG_WriteByte(&msg, *(byte *)(pkt + 0x765fc));
            /* Write data size */
            MSG_WriteByte(&msg, *(int *)(pkt + 0x766fd));
            /* Write voice data */
            MSG_WriteData(&msg, pkt + 0x765fd, *(int *)(pkt + 0x766fd));
            pkt += 0x105;
        }
    }

    /* Check for overflow */
    if (msg.overflowed) {
        Com_Printf("WARNING: voice msg overflowed for %s\n", (char *)client + 0x20c48);
        ZN10LargeLocalD1Ev((LargeLocal *)_ll_buf);
        return;
    }

    /* Send voice data via OOB */
    memcpy(&adr, (byte *)client + 0x6e5c4, sizeof(netadr_t));
    NET_OutOfBandVoiceData(1, adr, msg.data, msg.cursize);

    /* Reset voice packet count */
    *(int *)((byte *)client + 0x78ec4) = 0;
    ZN10LargeLocalD1Ev((LargeLocal *)_ll_buf);
}

/* line 97 */
Bool SV_ClientWantsVoiceData(int clientNum)
{
    byte *svs = *(byte **)&svs_ptr;
    byte *clients = *(byte **)(svs + 0xc);
    return *(Bool *)(clients + clientNum * 0x78f0c + 0x78f08);
}

/* line 106 */
Bool SV_ClientHasClientMuted(int listener, int talker)
{
    byte *svs = *(byte **)&svs_ptr;
    byte *clients = *(byte **)(svs + 0xc);
    byte *client = clients + listener * 0x78f0c;
    return *(Bool *)(client + 0x78ec8 + talker);
}

/* line 115 */
void SV_QueueVoicePacket(int talkerNum, int clientNum, VoicePacket_t *voicePacket)
{
    byte *svs = *(byte **)&svs_ptr;
    byte *clients = *(byte **)(svs + 0xc);
    byte *client = clients + clientNum * 0x78f0c;
    int count;

    count = *(int *)(client + 0x78ec4);
    if (count > 39)
        return;

    /* Copy dataSize */
    *(int *)(client + 0x766fd + count * 0x105) = *(int *)((byte *)voicePacket + 0x101);

    /* Copy voice data */
    memcpy(client + 0x765fd + count * 0x105, (byte *)voicePacket + 1, *(int *)((byte *)voicePacket + 0x101));

    /* Set talker */
    *(byte *)(client + 0x765fc + count * 0x105) = (byte)talkerNum;

    /* Increment count */
    *(int *)(client + 0x78ec4) = count + 1;
}

/* line 153 */
void SV_UserVoice(client_t *cl, msg_t *msg)
{
    byte voicePacket[0x105]; /* VoicePacket_t: talker(1) + data(256) + dataSize(4) */
    int packetCount;
    int dataSize;
    int i;

    /* Check voice dvar enabled */
    if (*(byte *)(*(int *)(*(int *)&sv_voice_dvar) + 8) == 0)
        return;

    packetCount = MSG_ReadByte(msg);
    if (packetCount <= 0)
        return;

    for (i = 0; i < packetCount; i++) {
        dataSize = MSG_ReadByte(msg);

        /* Validate: dataSize must be 1-256 */
        if ((unsigned int)(dataSize - 1) > 255) {
            Com_Printf("Received invalid voice packet of size %i from %s\n",
                       dataSize, (char *)cl + 0x20c48);
            return;
        }

        /* Store dataSize at VoicePacket_t offset 0x101 */
        *(int *)(voicePacket + 0x101) = dataSize;

        /* Read voice data into VoicePacket_t data field at offset 1 */
        MSG_ReadData(msg, voicePacket + 1, dataSize);

        /* Broadcast: pass client's gentity pointer */
        G_BroadcastVoice(*(gentity_t **)((byte *)cl + 0x20c44),
                         (VoicePacket_t *)voicePacket);
    }
}

/* line 203 */
void SV_PreGameUserVoice(client_t *cl, msg_t *msg)
{
    byte voiceData[256];
    int packetCount;
    int dataSize;
    int clientNum;
    int i, j;
    byte *svs;
    byte *clients;
    byte *other;
    int otherOffset;

    /* Check voice dvar enabled */
    if (*(byte *)(*(int *)(*(int *)&sv_voice_dvar) + 8) == 0)
        return;

    /* Compute clientNum from pointer difference */
    svs = *(byte **)&svs_ptr;
    clients = *(byte **)(svs + 0xc);
    clientNum = (int)((byte *)cl - clients) / 0x78f0c;

    packetCount = MSG_ReadByte(msg);
    if (packetCount <= 0)
        return;

    for (i = 0; i < packetCount; i++) {
        dataSize = MSG_ReadShort(msg);

        /* Validate: dataSize must be 1-256 */
        if ((unsigned int)(dataSize - 1) > 255) {
            Com_Printf("Received invalid voice packet of size %i from %s\n",
                       dataSize, (char *)cl + 0x20c48);
            return;
        }

        MSG_ReadData(msg, voiceData, dataSize);

        /* Queue to all eligible clients */
        otherOffset = 0;
        for (j = 0; j < 64; j++) {
            if (j == clientNum)
                goto sv_pregame_next;

            other = clients + otherOffset;

            /* Check client state > 1 (at least CS_CONNECTED) */
            if (*(int *)other <= 1)
                goto sv_pregame_next;

            /* Check mute list */
            if (*(byte *)(other + 0x78ec8 + clientNum) != 0)
                goto sv_pregame_next;

            /* Check sendVoice flag */
            if (*(byte *)(other + 0x78f08) == 0)
                goto sv_pregame_next;

            /* Inline SV_QueueVoicePacket */
            {
                int count = *(int *)(other + 0x78ec4);
                if (count <= 39) {
                    /* Copy dataSize */
                    *(int *)(other + 0x766fd + count * 0x105) = dataSize;
                    /* Copy voice data */
                    memcpy(other + 0x765fd + count * 0x105, voiceData, dataSize);
                    /* Set talker */
                    *(byte *)(other + 0x765fc + count * 0x105) = (byte)clientNum;
                    /* Increment count */
                    *(int *)(other + 0x78ec4) = count + 1;
                }
            }

        sv_pregame_next:
            otherOffset += 0x78f0c;
        }
    }
}
