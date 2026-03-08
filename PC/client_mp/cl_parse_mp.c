/* Decompiled from: cl_parse_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_parse_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

extern int cl_connectedToPureServer; /* 0x0 */
extern char * svc_strings[256]; /* 0x0 */

/* Global pointer externs - these are indirect pointers to game structures */
extern byte cls_ptr[];          /* defsym alias for imp_cls — single deref */
extern byte **clc_ptr;          /* imp_clc - clientConnection_t** */
extern dvar_t *com_dedicated;
extern byte **cl_paused;        /* imp_net_lanauthorize - dvar_t** */
extern byte **cl_packetdelay;   /* imp_cl_paused - dvar_t** */
extern byte *com_frameTime;     /* imp_cls */
extern byte **download_ui_ptr;  /* imp_legacyHacks - download progress** */
extern byte **cl_shownet;       /* imp_cl_shownet - dvar_t** */
extern byte **cl_showPackets;   /* imp_cl_shownuments - dvar_t** */

/* Function declarations */
void CL_SystemInfoChanged(void);
void CL_ParseGamestate(msg_t *msg);
void CL_ParseDownload(msg_t *msg);
void CL_ParseSnapshot(msg_t *msg);
void CL_ParseServerMessage(msg_t *msg);

extern void LargeLocal_LargeLocal(const LargeLocal *_this, int size);
extern void *LargeLocal_GetBuf(const LargeLocal *_this);
extern void ZN10LargeLocalD1Ev(const LargeLocal *_this);

extern char *Info_ValueForKey(const char *s, const char *key);
extern void Info_NextPair(const char **head, char *key, char *value);
extern void FS_PureServerSetLoadedIwds(const char *iwdSums, const char *iwdNames);
extern void FS_PureServerSetReferencedIwds(const char *iwdSums, const char *iwdNames);
extern void Dvar_SetFromStringByName(const char *dvarName, const char *string);
extern Bool Dvar_GetBool(const char *dvarName);
extern void Dvar_SetCheatState(void);
extern void Dvar_SetInt(const void *dvar, int value);
extern void Con_Close(void);
extern void CL_ClearState(void);
extern void CL_SystemInfoChanged(void);
extern qboolean FS_ConditionalRestart(int checksumFeed);
extern qboolean Sys_IsLANAddress(int addr0, int addr1, int addr2);
extern void CL_RequestAuthorization(void);
extern void CL_InitDownloads(void);
extern void CL_AddReliableCommand(const char *cmd);
extern void CL_WritePacket(void);
extern void CL_NextDownload(void);
extern void Com_Error(int level, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void Com_DPrintf(const char *fmt, ...);
extern int MSG_ReadLong(msg_t *msg);
extern int MSG_ReadByte(msg_t *msg);
extern int MSG_ReadShort(msg_t *msg);
extern int MSG_ReadBits(msg_t *msg, int bits);
extern int MSG_ReadBit(msg_t *msg);
extern char *MSG_ReadString(msg_t *msg);
extern char *MSG_ReadBigString(msg_t *msg);
extern void MSG_ReadData(msg_t *msg, void *data, int len);
extern void MSG_ReadDeltaPlayerstate(msg_t *msg, playerState_t *from, playerState_t *to);
extern qboolean MSG_ReadDeltaEntity(msg_t *msg, entityState_t *from, entityState_t *to, int number);
extern qboolean MSG_ReadDeltaClient(msg_t *msg, clientState_t *from, clientState_t *to, int number);
extern void MSG_Init(msg_t *buf, byte *data, int length);
extern int MSG_ReadBitsCompress(byte *from, byte *to, int size);
extern char *va(const char *format, ...);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern fileHandle_t FS_SV_FOpenFileWrite(const char *filename);
extern void FS_SV_Rename(const char *from, const char *to);
extern void FS_Write(const void *buffer, int len, fileHandle_t h);
extern void FS_FCloseFile(fileHandle_t h);

/* line 572 */
void CL_SystemInfoChanged(void)
{
    LargeLocal key_large_local;
    LargeLocal value_large_local;
    char *key;
    char *value;
    byte *cls;
    byte *clc;
    char *systemInfo;
    const char *s;

    LargeLocal_LargeLocal(&key_large_local, 0x2000);
    key = (char *)LargeLocal_GetBuf(&key_large_local);

    LargeLocal_LargeLocal(&value_large_local, 0x2000);
    value = (char *)LargeLocal_GetBuf(&value_large_local);

    /* line 582 */
    cls = *(byte **)cls_ptr;
    clc = *clc_ptr;
    systemInfo = (char *)(clc + 0x470c + *(int *)(clc + 0x2710));

    /* line 583 - sv_serverid */
    *(int *)(clc + 0x8628) = atoi(Info_ValueForKey(systemInfo, "sv_serverid"));

    /* line 586 */
    if (*(int *)((*clc_ptr) + 0x407a0) != 0) {
        ZN10LargeLocalD1Ev(&value_large_local);
        ZN10LargeLocalD1Ev(&key_large_local);
        return;
    }

    /* line 591 - sv_cheats */
    s = Info_ValueForKey(systemInfo, "sv_cheats");
    if (atoi(s) == 0) {
        /* line 593 */
        Dvar_SetCheatState();
    }

    /* line 597 - sv_iwds */
    s = Info_ValueForKey(systemInfo, "sv_iwds");
    /* line 598 - sv_iwdNames */
    FS_PureServerSetLoadedIwds(s, Info_ValueForKey(systemInfo, "sv_iwdNames"));

    /* line 601 - sv_referencedIwds */
    s = Info_ValueForKey(systemInfo, "sv_referencedIwds");
    /* line 602 - sv_referencedIwdNames */
    FS_PureServerSetReferencedIwds(s, Info_ValueForKey(systemInfo, "sv_referencedIwdNames"));

    /* line 606 */
    if (!com_dedicated->current.integer) {
        /* line 609 - iterate info string pairs */
        s = systemInfo;
        while (s) {
            Info_NextPair(&s, key, value);
            if (key[0] == '\0')
                break;
            /* line 618 */
            Dvar_SetFromStringByName(key, value);
        }
    }

    /* line 622 - sv_pure */
    cl_connectedToPureServer = (int)Dvar_GetBool("sv_pure");

    ZN10LargeLocalD1Ev(&value_large_local);
    ZN10LargeLocalD1Ev(&key_large_local);
}

/* line 632 */
void CL_ParseGamestate(msg_t *msg)
{
    byte *clc;
    byte *cls;
    int newnum;
    int i;
    char *s;
    int len;
    entityState_t nullstate;

    /* line 641 */
    Con_Close();

    /* line 643 */
    clc = *clc_ptr;
    *(int *)(clc + 0x24) = 0;

    /* line 646 */
    CL_ClearState();

    /* line 649 */
    *(int *)(clc + 0x2013c) = MSG_ReadLong(msg);

    /* line 652 */
    cls = *(byte **)cls_ptr;
    *(int *)(cls + 0x858c) = 1;

    for (;;) {
        /* line 655 */
        int cmd = MSG_ReadByte(msg);

        /* line 657 */
        if (cmd == 7)
            break;

        if (cmd == 2) {
            /* line 666 - configstring */
            i = MSG_ReadShort(msg);
            if (i > 0x7ff) {
                Com_Error(1, "\x15configstring > MAX_CONFIGSTRINGS");
            }

            /* line 671 */
            s = MSG_ReadBigString(msg);

            /* line 672 - strlen inline */
            len = strlen(s);

            /* line 674 */
            cls = *(byte **)cls_ptr;
            if (len + 1 + *(int *)(cls + 0x858c) > 0x3e80) {
                Com_Error(1, "\x15MAX_GAMESTATE_CHARS exceeded");
            }

            /* line 680 */
            *(int *)(cls + 0x270c + i * 4) = *(int *)(cls + 0x858c);
            /* line 681 */
            memcpy(cls + 0x470c + *(int *)(cls + 0x858c), s, len + 1);
            /* line 682 */
            *(int *)(cls + 0x858c) = *(int *)(cls + 0x858c) + len + 1;
        } else if (cmd == 3) {
            /* line 686 - baseline */
            newnum = MSG_ReadBits(msg, 10);
            if (newnum > 0x3ff) {
                Com_Error(1, "\x15Baseline number out of range: %i", newnum);
            }

            /* line 691 */
            memset(&nullstate, 0, sizeof(entityState_t));

            /* line 693 */
            MSG_ReadDeltaEntity(msg, &nullstate,
                (entityState_t *)(cls + 0x970e0 + newnum * 240),
                newnum);
        } else {
            /* line 697 */
            Com_Error(1, "\x15CL_ParseGamestate: bad command byte");
        }
    }

    /* line 701 */
    clc = *clc_ptr;
    *(int *)(clc + 8) = MSG_ReadLong(msg);

    /* line 703 */
    *(int *)(clc + 0x12c) = MSG_ReadLong(msg);

    /* line 706 */
    CL_SystemInfoChanged();

    /* line 710 */
    FS_ConditionalRestart(*(int *)(clc + 0x12c));

    /* line 720 */
    if (*(byte *)((*cl_paused) + 8) == 0) {
        int addr0 = *(int *)(clc + 0x14);
        int addr1 = *(int *)(clc + 0x18);
        int addr2 = *(int *)(clc + 0x1c);
        if (!Sys_IsLANAddress(addr0, addr1, addr2)) {
            /* line 721 */
            CL_RequestAuthorization();
        }
    } else {
        CL_RequestAuthorization();
    }

    /* line 726 */
    CL_InitDownloads();

    /* line 732 */
    Dvar_SetInt(*(void **)cl_packetdelay, 0);
}

/* line 748 */
void CL_ParseDownload(msg_t *msg)
{
    LargeLocal data_large_local;
    byte *data;
    int block;
    int size;
    byte *clc;

    /* line 752 */
    LargeLocal_LargeLocal(&data_large_local, 0x4000);
    data = (byte *)LargeLocal_GetBuf(&data_large_local);

    /* line 755 */
    block = MSG_ReadShort(msg);

    /* line 757 */
    if (block == 0) {
        /* line 760 */
        clc = *clc_ptr;
        *(int *)(clc + 0x40354) = MSG_ReadLong(msg);

        /* line 762 */
        *(int *)((*download_ui_ptr) + 0x10) = *(int *)(clc + 0x40354);

        /* line 764 */
        size = *(int *)(clc + 0x40354);
        if (size < 0) {
            /* line 766 - error message from server */
            Com_Error(1, "%s", va("%s", MSG_ReadString(msg)));
            ZN10LargeLocalD1Ev(&data_large_local);
            return;
        }
    }

    /* line 771 */
    size = MSG_ReadShort(msg);

    /* line 772 */
    if (size > 0) {
        /* line 773 */
        MSG_ReadData(msg, data, size);
    }

    /* line 775 */
    clc = *clc_ptr;
    if (*(int *)(clc + 0x4034c) != block) {
        /* line 777 */
        Com_DPrintf("CL_ParseDownload: Expected block %d, got %d\n",
                    *(int *)(clc + 0x4034c), block);

        /* line 779 */
        if (block > *(int *)(clc + 0x4034c)) {
            /* line 781 */
            Com_DPrintf("CL_ParseDownload: Sending retransmit request to get the missed block\n");
            /* line 782 */
            CL_AddReliableCommand(va("retransdl %d", *(int *)(clc + 0x4034c)));
        }
        ZN10LargeLocalD1Ev(&data_large_local);
        return;
    }

    /* line 789 */
    if (*(int *)(clc + 0x40144) == 0) {
        /* line 791 */
        if (*(byte *)(clc + 0x40148) == '\0') {
            /* line 793 */
            Com_Printf("Server sending download, but no download was requested\n");
            CL_AddReliableCommand("stopdl");
            ZN10LargeLocalD1Ev(&data_large_local);
            return;
        }

        /* line 798 */
        *(int *)(clc + 0x40144) = FS_SV_FOpenFileWrite((const char *)(clc + 0x40148));
        if (*(int *)(clc + 0x40144) == 0) {
            /* line 802 */
            Com_Printf("Could not create %s\n", (const char *)(clc + 0x40148));
            CL_AddReliableCommand("stopdl");
            CL_NextDownload();
            ZN10LargeLocalD1Ev(&data_large_local);
            return;
        }
    }

    /* line 809 */
    if (size != 0) {
        /* line 810 */
        FS_Write(data, size, *(int *)((*clc_ptr) + 0x40144));
    }

    /* line 812 */
    clc = *clc_ptr;
    CL_AddReliableCommand(va("nextdl %d", *(int *)(clc + 0x4034c)));
    /* line 813 */
    *(int *)(clc + 0x4034c) += 1;

    /* line 815 */
    *(int *)(clc + 0x40350) += size;

    /* line 818 */
    *(int *)((*download_ui_ptr) + 0x14) = *(int *)(clc + 0x40350);

    /* line 820 */
    if (size != 0) {
        ZN10LargeLocalD1Ev(&data_large_local);
        return;
    }

    /* line 822 - download complete */
    if (*(int *)(clc + 0x40144) != 0) {
        /* line 824 */
        FS_FCloseFile(*(int *)(clc + 0x40144));
        /* line 825 */
        *(int *)(clc + 0x40144) = 0;
        /* line 828 */
        FS_SV_Rename((const char *)(clc + 0x40148), (const char *)(clc + 0x40248));
    }

    /* line 830 */
    *(byte *)(clc + 0x40248) = 0;
    *(byte *)(clc + 0x40148) = 0;

    /* line 831 */
    *(byte *)((*download_ui_ptr) + 0x1c) = 0;

    /* line 838 */
    CL_WritePacket();
    /* line 839 */
    CL_WritePacket();
    /* line 842 */
    CL_NextDownload();

    ZN10LargeLocalD1Ev(&data_large_local);
}

/*
 * Helper: compute entity slot address from frame buffer.
 * slot = base + 0xd30e0 + ((num & 0x7ff) * 240)
 * The multiply is done as: num * 240 = (num << 8) - (num << 4)
 */
static byte *CL_EntitySlot(byte *base, int num)
{
    int idx = num & 0x7ff;
    return base + 0xd30e0 + idx * 240;
}

/*
 * Helper: compute client slot address from frame buffer.
 * slot = base + 0x14b0e0 + ((num & 0x7ff) * 92)
 * The multiply is done as: (num*3*8 - num) * 4 = num * 92
 */
static byte *CL_ClientSlot(byte *base, int num)
{
    int idx = num & 0x7ff;
    return base + 0x14b0e0 + idx * 92;
}

/*
 * Helper: compute snapshot address from frame ring buffer.
 * Each snapshot is 0x26d8 bytes; ring buffer of 32 entries at offset 0x495e0.
 * index = messageNum & 0x1f
 * The complex multiply computes index * 0x26d8:
 *   x = index
 *   c = x * 5
 *   a = c << 5 = x * 160
 *   a = a - c = x * 155
 *   a = x + a*4 = x + x*620 = x*621
 *   a = x + a*2 = x + x*1242 = x*1243
 *   result = base + 0x495e0 + a*8 = base + 0x495e0 + x * 9944
 *   9944 = 0x26d8
 */
static byte *CL_SnapSlot(byte *base, int messageNum)
{
    int idx = messageNum & 0x1f;
    return base + 0x495e0 + idx * 0x26d8;
}

/* line 407 */
void CL_ParseSnapshot(msg_t *msg)
{
    LargeLocal newSnap_large_local;
    byte *newSnap;
    byte *cls;
    byte *clc;
    byte *old;
    int oldMessageNum;
    int deltaNum;
    int newnum;
    int oldindex;
    entityState_t nullstate_ent;
    clientState_t dummy;
    byte *oldEntitySlot;
    int oldEntityNum;
    byte *oldClientSlot;
    int oldClientNum;

    /* line 413 */
    LargeLocal_LargeLocal(&newSnap_large_local, 0x26d8);
    newSnap = (byte *)LargeLocal_GetBuf(&newSnap_large_local);

    /* line 421 */
    memset(newSnap, 0, 0x26d8);

    /* line 425 */
    clc = *clc_ptr;
    *(int *)(newSnap + 0x26d4) = *(int *)(clc + 0x2013c);

    /* line 427 */
    *(int *)(newSnap + 8) = MSG_ReadLong(msg);

    /* line 429 */
    *(int *)(newSnap + 0xc) = *(int *)(clc + 0x20138);

    /* line 431 */
    deltaNum = MSG_ReadByte(msg);

    /* line 432 */
    if (deltaNum == 0) {
        /* line 434 */
        *(int *)(newSnap + 0x10) = -1;
    } else {
        /* line 438 */
        *(int *)(newSnap + 0x10) = *(int *)(newSnap + 0xc) - deltaNum;
    }

    /* line 440 */
    *(int *)(newSnap + 4) = MSG_ReadByte(msg);

    /* line 446 */
    oldMessageNum = *(int *)(newSnap + 0x10);
    if (oldMessageNum <= 0) {
        /* line 448 */
        *(int *)(newSnap) = 1;
        /* line 450 */
        *(int *)((*clc_ptr) + 0x407a8) = 0;
        old = NULL;
    } else {
        /* line 454 */
        cls = *(byte **)cls_ptr;
        old = CL_SnapSlot(cls, oldMessageNum);

        /* line 455 */
        if (*(int *)old == 0) {
            /* line 458 */
            Com_Printf("Delta from invalid frame (not supposed to happen!).\n");
        } else if (*(int *)(old + 0xc) != oldMessageNum) {
            /* line 464 */
            Com_DPrintf("Delta frame too old.\n");
        } else {
            /* line 466 */
            if (*(int *)(cls + 0x85d0) - *(int *)(old + 0x26cc) > 0x780) {
                /* line 468 */
                Com_DPrintf("Delta parseEntitiesNum too old.\n");
            } else if (*(int *)(cls + 0x85d4) - *(int *)(old + 0x26d0) > 0x780) {
                /* line 472 */
                Com_DPrintf("Delta parseClientsNum too old.\n");
            } else {
                /* line 476 */
                *(int *)(newSnap) = 1;
            }
        }
    }

    /* Logging */
    if (*(int *)((*cl_shownet) + 8) > 1) {
        Com_Printf("%3i:%s\n", msg->readcount - 1, "playerstate");
    }

    /* line 482 - read delta playerstate */
    if (old) {
        MSG_ReadDeltaPlayerstate(msg, (playerState_t *)(old + 0x1c), (playerState_t *)(newSnap + 0x1c));
    } else {
        /* line 488 */
        MSG_ReadDeltaPlayerstate(msg, NULL, (playerState_t *)(newSnap + 0x1c));
    }

    /* Logging */
    if (*(int *)((*cl_shownet) + 8) > 1) {
        Com_Printf("%3i:%s\n", msg->readcount - 1, "packet clients");
    }

    /* ---- CL_ParsePacketEntities (inlined, line 142+) ---- */
    cls = *(byte **)cls_ptr;
    *(int *)(newSnap + 0x26cc) = *(int *)(cls + 0x85d0);
    *(int *)(newSnap + 0x26c4) = 0;

    /* line 148 */
    if (old && *(int *)(old + 0x26c4) > 0) {
        /* line 160 */
        oldEntitySlot = CL_EntitySlot(cls, *(int *)(old + 0x26cc));
        oldEntityNum = *(int *)oldEntitySlot;
    } else {
        oldEntitySlot = NULL;
        oldEntityNum = 0x1869f; /* MAX */
    }

    oldindex = 0;

    for (;;) {
        /* line 165 - read next entity number from message */
        if (msg->overflowed)
            break;

        /* line 168 */
        newnum = MSG_ReadBits(msg, 10);

        /* line 170 */
        if (newnum == 0x3ff)
            break;

        /* line 175 */
        if (msg->readcount > msg->cursize) {
            Com_Error(1, "\x15CL_ParsePacketEntities: end of message");
        }

        /* line 180 - copy unchanged old entities before this one */
        while (oldEntityNum < newnum) {
            if (msg->overflowed)
                break;

            /* Logging */
            if (*(int *)((*cl_shownet) + 8) == 3) {
                Com_Printf("%3i:  unchanged: %i\n", msg->readcount, oldEntityNum);
            }

            /* line 82-95: CL_DeltaEntity - copy old entity unchanged */
            cls = *(byte **)cls_ptr;
            memcpy(CL_EntitySlot(cls, *(int *)(cls + 0x85d0)), oldEntitySlot, 0xf0);
            *(int *)(cls + 0x85d0) += 1;
            *(int *)(newSnap + 0x26c4) += 1;

            /* line 189-198: advance old */
            oldindex += 1;
            if (oldindex >= *(int *)(old + 0x26c4)) {
                oldEntityNum = 0x1869f;
            } else {
                oldEntitySlot = CL_EntitySlot(cls, oldindex + *(int *)(old + 0x26cc));
                oldEntityNum = *(int *)oldEntitySlot;
            }
        }

        /* line 201 */
        if (oldEntityNum == newnum) {
            /* line 204 - delta from old */
            if (*(int *)((*cl_shownet) + 8) == 3) {
                Com_Printf("%3i:  delta: %i\n", msg->readcount, oldEntityNum);
            }

            /* line 82-95: CL_DeltaEntity - delta */
            cls = *(byte **)cls_ptr;
            if (!MSG_ReadDeltaEntity(msg, (entityState_t *)oldEntitySlot,
                    (entityState_t *)CL_EntitySlot(cls, *(int *)(cls + 0x85d0)),
                    oldEntityNum)) {
                *(int *)(cls + 0x85d0) += 1;
                *(int *)(newSnap + 0x26c4) += 1;
            }

            /* advance old */
            oldindex += 1;
            if (oldindex >= *(int *)(old + 0x26c4)) {
                oldEntityNum = 0x1869f;
            } else {
                oldEntitySlot = CL_EntitySlot(cls, oldindex + *(int *)(old + 0x26cc));
                oldEntityNum = *(int *)oldEntitySlot;
            }
        } else {
            /* line 227 - baseline entity */
            if (*(int *)((*cl_shownet) + 8) == 3) {
                Com_Printf("%3i:  baseline: %i\n", msg->readcount, newnum);
            }

            /* line 231 - CL_DeltaEntity with baseline */
            cls = *(byte **)cls_ptr;
            if (!MSG_ReadDeltaEntity(msg,
                    (entityState_t *)(cls + 0x970e0 + newnum * 240),
                    (entityState_t *)CL_EntitySlot(cls, *(int *)(cls + 0x85d0)),
                    newnum)) {
                *(int *)(cls + 0x85d0) += 1;
                *(int *)(newSnap + 0x26c4) += 1;
            }
        }
    }

    /* line 235-253: copy remaining old entities */
    while (oldEntityNum != 0x1869f) {
        if (msg->overflowed)
            break;

        /* line 238 */
        if (*(int *)((*cl_shownet) + 8) == 3) {
            Com_Printf("%3i:  unchanged: %i\n", msg->readcount, oldEntityNum);
        }

        /* CL_DeltaEntity - copy unchanged */
        cls = *(byte **)cls_ptr;
        memcpy(CL_EntitySlot(cls, *(int *)(cls + 0x85d0)), oldEntitySlot, 0xf0);
        *(int *)(cls + 0x85d0) += 1;
        *(int *)(newSnap + 0x26c4) += 1;

        /* advance old */
        oldindex += 1;
        if (oldindex >= *(int *)(old + 0x26c4))
            break;

        oldEntitySlot = CL_EntitySlot(cls, oldindex + *(int *)(old + 0x26cc));
        oldEntityNum = *(int *)oldEntitySlot;
    }

    /* line 257 */
    if (*(byte *)((*cl_showPackets) + 8) != 0) {
        Com_Printf("Entities in packet: %i\n", *(int *)(newSnap + 0x26c4));
    }

    /* Logging */
    if (*(int *)((*cl_shownet) + 8) > 1) {
        Com_Printf("%3i:%s\n", msg->readcount - 1, "packet clients");
    }

    /* ---- CL_ParsePacketClients (inlined, line 277+) ---- */
    cls = *(byte **)cls_ptr;
    *(int *)(newSnap + 0x26d0) = *(int *)(cls + 0x85d4);
    *(int *)(newSnap + 0x26c8) = 0;

    /* line 283 */
    if (old && *(int *)(old + 0x26c8) > 0) {
        /* line 295 */
        oldClientSlot = CL_ClientSlot(cls, *(int *)(old + 0x26d0));
        oldClientNum = *(int *)oldClientSlot;
    } else {
        oldClientSlot = NULL;
        oldClientNum = 0x1869f;
    }

    oldindex = 0;

    for (;;) {
        /* line 300 */
        if (msg->overflowed)
            break;

        /* line 302 */
        if (!MSG_ReadBit(msg))
            break;

        /* line 306 */
        newnum = MSG_ReadBits(msg, 6);

        /* line 308 */
        if (msg->readcount > msg->cursize) {
            Com_Error(1, "\x15CL_ParsePacketClients: end of message");
        }

        /* line 313 - copy unchanged old clients before this one */
        while (oldClientNum < newnum) {
            /* line 316 */
            if (*(int *)((*cl_shownet) + 8) == 3) {
                Com_Printf("%3i:  unchanged: %i\n", msg->readcount, oldClientNum);
            }

            /* line 113-126: CL_DeltaClient - copy old */
            cls = *(byte **)cls_ptr;
            memcpy(CL_ClientSlot(cls, *(int *)(cls + 0x85d4)), oldClientSlot, 0x5c);
            *(int *)(cls + 0x85d4) += 1;
            *(int *)(newSnap + 0x26c8) += 1;

            /* line 322-331: advance old */
            oldindex += 1;
            if (oldindex >= *(int *)(old + 0x26c8)) {
                oldClientNum = 0x1869f;
                break;
            }
            oldClientSlot = CL_ClientSlot(cls, oldindex + *(int *)(old + 0x26d0));
            oldClientNum = *(int *)oldClientSlot;
        }

        /* line 334 */
        if (oldClientNum == newnum) {
            /* line 337 - delta from old */
            if (*(int *)((*cl_shownet) + 8) == 3) {
                Com_Printf("%3i:  delta: %i\n", msg->readcount, oldClientNum);
            }

            /* line 113-126: CL_DeltaClient - delta */
            cls = *(byte **)cls_ptr;
            if (!MSG_ReadDeltaClient(msg, (clientState_t *)oldClientSlot,
                    (clientState_t *)CL_ClientSlot(cls, *(int *)(cls + 0x85d4)),
                    oldClientNum)) {
                *(int *)(cls + 0x85d4) += 1;
                *(int *)(newSnap + 0x26c8) += 1;
            }

            /* advance old */
            oldindex += 1;
            if (oldindex >= *(int *)(old + 0x26c8)) {
                oldClientNum = 0x1869f;
            } else {
                oldClientSlot = CL_ClientSlot(cls, oldindex + *(int *)(old + 0x26d0));
                oldClientNum = *(int *)oldClientSlot;
            }
        } else {
            /* line 360 - baseline client */
            if (*(int *)((*cl_shownet) + 8) == 3) {
                Com_Printf("%3i:  baseline: %i\n", msg->readcount, newnum);
            }

            /* line 364 */
            memset(&dummy, 0, sizeof(clientState_t));

            /* line 113-126: CL_DeltaClient - delta with dummy baseline */
            cls = *(byte **)cls_ptr;
            if (!MSG_ReadDeltaClient(msg, (clientState_t *)&dummy,
                    (clientState_t *)CL_ClientSlot(cls, *(int *)(cls + 0x85d4)),
                    newnum)) {
                *(int *)(cls + 0x85d4) += 1;
                *(int *)(newSnap + 0x26c8) += 1;
            }
        }
    }

    /* line 369-387: copy remaining old clients */
    while (oldClientNum != 0x1869f) {
        if (msg->overflowed)
            break;

        /* line 372 */
        if (*(int *)((*cl_shownet) + 8) == 3) {
            Com_Printf("%3i:  unchanged: %i\n", msg->readcount, oldClientNum);
        }

        /* CL_DeltaClient - copy unchanged */
        cls = *(byte **)cls_ptr;
        memcpy(CL_ClientSlot(cls, *(int *)(cls + 0x85d4)), oldClientSlot, 0x5c);
        *(int *)(cls + 0x85d4) += 1;
        *(int *)(newSnap + 0x26c8) += 1;

        /* advance old */
        oldindex += 1;
        if (oldindex >= *(int *)(old + 0x26c8))
            break;

        oldClientSlot = CL_ClientSlot(cls, oldindex + *(int *)(old + 0x26d0));
        oldClientNum = *(int *)oldClientSlot;
    }

    /* line 391 */
    if (*(byte *)((*cl_showPackets) + 8) != 0) {
        Com_Printf("Clients in packet: %i\n", *(int *)(newSnap + 0x26c8));
    }

    /* line 499 */
    if (msg->overflowed) {
        /* line 501 */
        *(int *)(newSnap) = 0;
        ZN10LargeLocalD1Ev(&newSnap_large_local);
        return;
    }

    /* line 507 */
    if (*(int *)(newSnap) == 0) {
        ZN10LargeLocalD1Ev(&newSnap_large_local);
        return;
    }

    /* line 516 */
    cls = *(byte **)cls_ptr;
    {
        int oldMsg = *(int *)(cls + 0x24) + 1;
        int serverMessageSequence = *(int *)(newSnap + 0xc);

        /* line 520 */
        if (serverMessageSequence - oldMsg >= 0x20) {
            oldMsg = serverMessageSequence - 0x1f;
        }

        /* line 522 - invalidate old snapshots */
        while (oldMsg < serverMessageSequence) {
            byte *snapSlot = CL_SnapSlot(cls, oldMsg);
            *(int *)snapSlot = 0;
            oldMsg++;
        }
    }

    /* line 528 */
    cls = *(byte **)cls_ptr;
    *(int *)(cls + 0x2700) = *(int *)(cls + 0x20);

    /* line 529 - copy newSnap to current snap */
    memcpy(cls + 0x18, newSnap, 0x26d8);

    /* line 530 */
    *(int *)(cls + 0x2c) = 999;

    /* line 534-538 - compute ping */
    {
        int parseEntNum = *(int *)((*clc_ptr) + 0x407c8);
        int snapTime = *(int *)(cls + 0x34);
        int i;

        for (i = 1; i < 0x21; i++) {
            int idx = (parseEntNum - i) & 0x1f;
            byte *slot = cls + 0x49464 + idx * 12;
            if (*(int *)slot >= snapTime) {
                *(int *)(cls + 0x2c) = *(int *)(com_frameTime + 0x118) - *(int *)(slot + 4);
                break;
            }
        }
    }

    /* line 542 - copy current snap to frame ring buffer */
    cls = *(byte **)cls_ptr;
    memcpy(CL_SnapSlot(cls, *(int *)(cls + 0x24)), cls + 0x18, 0x26d8);

    /* line 544 */
    if (*(int *)((*cl_shownet) + 8) == 3) {
        Com_Printf("   snapshot:%i  delta:%i  ping:%i\n",
                    *(int *)(cls + 0x24), *(int *)(cls + 0x28), *(int *)(cls + 0x2c));
    }

    /* line 549 */
    *(int *)(cls + 0x2708) = 1;

    ZN10LargeLocalD1Ev(&newSnap_large_local);
}

/* line 883 */
void CL_ParseServerMessage(msg_t *msg)
{
    LargeLocal msgCompressed_buf_large_local;
    byte *msgCompressed_buf;
    msg_t msgCompressed;
    int cmd;

    /* line 887 */
    LargeLocal_LargeLocal(&msgCompressed_buf_large_local, 0x4000);
    msgCompressed_buf = (byte *)LargeLocal_GetBuf(&msgCompressed_buf_large_local);

    /* line 892 */
    if (*(int *)((*cl_shownet) + 8) == 1) {
        /* line 894 */
        Com_Printf("%i ", msg->cursize);
    } else if (*(int *)((*cl_shownet) + 8) > 1) {
        /* line 898 */
        Com_Printf("------------------\n");
    }

    /* line 901 */
    MSG_Init(&msgCompressed, msgCompressed_buf, 0x4000);

    /* line 902 - decompress message */
    msgCompressed.cursize = MSG_ReadBitsCompress(msg->data + msg->readcount,
                         msgCompressed_buf,
                         msg->cursize - msg->readcount);

    /* line 907 - parse commands loop */
    while (!msgCompressed.overflowed) {
        /* line 909 */
        cmd = MSG_ReadByte(&msgCompressed);

        /* line 911 */
        if (cmd == 7) {
            /* svc_EOF */
            if (*(int *)((*cl_shownet) + 8) > 1) {
                Com_Printf("%3i:%s\n", msgCompressed.readcount - 1, "END OF MESSAGE");
            }
            break;
        }

        /* line 917-921 */
        if (*(int *)((*cl_shownet) + 8) > 1) {
            if (svc_strings[cmd] == NULL) {
                Com_Printf("%3i:BAD CMD %i\n", msgCompressed.readcount - 1, cmd);
            } else {
                Com_Printf("%3i:%s\n", msgCompressed.readcount - 1, svc_strings[cmd]);
            }
        }

        /* line 930 - command dispatch */
        switch (cmd) {
        case 0:
            /* svc_nop / svc_bad - handled as default */
            break;
        case 1: {
            /* svc_gamestate (line 950) */
            CL_ParseGamestate(&msgCompressed);
            break;
        }
        case 2: {
            /* svc_configstring / svc_serverCommand (line 863) */
            int seq = MSG_ReadLong(&msgCompressed);
            char *str = MSG_ReadString(&msgCompressed);
            byte *clc = *clc_ptr;
            if (seq <= *(int *)(clc + 0x2013c))
                break;
            /* line 871 */
            *(int *)(clc + 0x2013c) = seq;
            /* line 874 */
            I_strncpyz((char *)(clc + 0x20144 + (seq & 0x7f) * 0x400), str, 0x400);
            break;
        }
        case 3:
            /* svc_download (line 957) */
            CL_ParseDownload(&msgCompressed);
            break;
        case 4:
            /* svc_snapshot (line 953) */
            CL_ParseSnapshot(&msgCompressed);
            break;
        default:
            /* line 942 */
            Com_Error(1, "\x15CL_ParseServerMessage: Illegible server message %d\n", cmd);
            break;
        }
    }

    ZN10LargeLocalD1Ev(&msgCompressed_buf_large_local);
}
