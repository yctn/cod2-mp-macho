/* Decompiled from: cl_net_chan_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_net_chan_mp.cpp */

#include "common_types.h"
#include "imports.h"

/*
 * Client-side globals accessed by absolute address in the original binary.
 * imp_clc -> pointer to clientConnection_t* (clc)
 * imp_cl -> pointer to clientActive_t* (cl)
 * imp_net_profile -> pointer to net profiling dvar
 */
extern byte *clc_ptr;          /* imp_clc */
extern byte *cl_ptr;           /* imp_cl */
extern byte *net_profile_dvar; /* imp_net_profile */

/* clientConnection_t field offsets (verified against struct layout) */
#define CLC_CHALLENGE_OFF            0x128
#define CLC_RELIABLEACK_OFF          0x134
#define CLC_RELIABLECMDS_OFF         0x138  /* reliableCommands[128][1024] */
#define CLC_SERVERMSGSEQ_OFF         0x20138
#define CLC_SERVERCMDSEQ_OFF         0x2013c
#define CLC_SERVERCMDS_OFF           0x20144 /* serverCommands[128][1024] */
#define CLC_NETCHAN_OFF              0x407c8
#define CLC_NETCHAN_PPROF_OFF        0x487fc /* netchan.pProf */
#define CLC_POOBPROF_OFF             0x48800 /* pOOBProf */

/* clientActive_t field offset for serverId (at 0x8628 from base) */
#define CL_SERVERID_OFF              0x8628

#define RELIABLECMD_SIZE             1024

extern void Netchan_TransmitNextFragment(netchan_t *chan);
extern void Netchan_Transmit(netchan_t *chan, int length, const byte *data);
extern void NetProf_PrepProfiling(netProfileInfo_t **pProf);
extern void NetProf_AddPacket(netProfileStream_t *stream, int iLength, qboolean bFragment);
extern void NetProf_UpdateStatistics(netProfileStream_t *stream);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void CL_DrawString(int x, int y, const char *str, int color, int size);
extern void NET_SendPacket(netsrc_t sock, int length, const void *data, netadr_t to);

void CL_Netchan_Decode(byte *data, int size);
void CL_Netchan_TransmitNextFragment(netchan_t *chan);
void CL_Netchan_Transmit(netchan_t *chan, byte *data, int length);
void CL_Netchan_AddOOBProfilePacket(int iLength);
void CL_Netchan_SendOOBPacket(int iLength, const void *pData, netadr_t to);
void CL_Netchan_PrintProfileStats(qboolean bPrintToConsole);

/* line 58 */
void CL_Netchan_Decode(byte *data, int size)
{
    byte *clc_base;
    int reliableAcknowledge;
    const char *string;
    byte key;
    int index;
    int i;

    /* Get clientConnection_t base pointer */
    clc_base = *(byte **)clc_ptr;

    /* Compute string from reliableCommands[reliableAcknowledge & 0x7f] */
    reliableAcknowledge = *(int *)(clc_base + CLC_RELIABLEACK_OFF);
    string = (const char *)(clc_base + CLC_RELIABLECMDS_OFF
             + (reliableAcknowledge & 0x7f) * RELIABLECMD_SIZE);

    /* Compute initial key from serverMessageSequence XOR challenge */
    key = (byte)(*(int *)(clc_base + CLC_SERVERMSGSEQ_OFF));
    key ^= (byte)(*(int *)(clc_base + CLC_CHALLENGE_OFF));

    /* XOR decode the data using the key and cycling through the string */
    index = 0;
    for (i = 0; i < size; i++) {
        byte ch;

        /* Get next character from the string, wrapping on null */
        if (string[index] == '\0') {
            ch = (unsigned char)string[0];
            index = 1;
        } else {
            ch = (unsigned char)string[index];
            index++;
        }

        /* Modify key using current string character, shifted by parity of position */
        key ^= (byte)(ch << (i & 1));

        /* Apply the key to the data byte */
        data[i] ^= key;
    }
}

/* line 88 */
void CL_Netchan_TransmitNextFragment(netchan_t *chan)
{
    Netchan_TransmitNextFragment(chan);
}

/* line 99 */
void CL_Netchan_Transmit(netchan_t *chan, byte *data, int length)
{
    byte *clc_base;
    int serverCommandSequence;
    const char *string;
    byte key;
    int index;
    int dataSize;
    byte *encodeData;
    int i;

    /* The first 9 bytes of data are not encoded */
    dataSize = length - 9;
    encodeData = data + 9;

    /* Get clientConnection_t base pointer */
    clc_base = *(byte **)clc_ptr;

    /* Get the string from serverCommands[serverCommandSequence & 0x7f] */
    serverCommandSequence = *(int *)(clc_base + CLC_SERVERCMDSEQ_OFF);
    string = (const char *)(clc_base + CLC_SERVERCMDS_OFF
             + (serverCommandSequence & 0x7f) * RELIABLECMD_SIZE);

    /* Compute initial key from cl->serverId XOR challenge XOR serverMessageSequence */
    key = (byte)(*(int *)(*(byte **)cl_ptr + CL_SERVERID_OFF));
    key ^= (byte)(*(int *)(clc_base + CLC_CHALLENGE_OFF));
    key ^= (byte)(*(int *)(clc_base + CLC_SERVERMSGSEQ_OFF));

    /* XOR encode the data using the key and cycling through the string */
    index = 0;
    for (i = 0; i < dataSize; i++) {
        byte ch;

        if (string[index] == '\0') {
            ch = (unsigned char)string[0];
            index = 1;
        } else {
            ch = (unsigned char)string[index];
            index++;
        }

        key ^= (byte)(ch << (i & 1));

        encodeData[i] ^= key;
    }

    /* Transmit via netchan */
    Netchan_Transmit(chan, length, data);
}

/* line 119 */
void CL_Netchan_AddOOBProfilePacket(int iLength)
{
    byte *clc_base;
    netProfileInfo_t *pOOBProf;

    /*
     * Check if net profiling is enabled.
     * net_profile_dvar is a pointer to a dvar_t*; double-deref to get enabled state.
     */
    if (*(int *)(*(byte **)net_profile_dvar + 8) == 0)
        return;

    clc_base = *(byte **)clc_ptr;
    NetProf_PrepProfiling((netProfileInfo_t **)(clc_base + CLC_POOBPROF_OFF));
    pOOBProf = *(netProfileInfo_t **)(clc_base + CLC_POOBPROF_OFF);
    NetProf_AddPacket((netProfileStream_t *)pOOBProf, iLength, 0);
}

/* line 134 */
void CL_Netchan_SendOOBPacket(int iLength, const void *pData, netadr_t to)
{
    byte *clc_base;

    /* Check that the packet starts with 0xFFFFFFFF (OOB marker) */
    if (*(int *)pData != -1) {
        Com_Printf("CL_Netchan_SendOOBPacket used to send non-OOB packet.\n");
    }

    clc_base = *(byte **)clc_ptr;
    NetProf_PrepProfiling((netProfileInfo_t **)(clc_base + CLC_POOBPROF_OFF));

    /* Send the packet */
    NET_SendPacket(NS_CLIENT1, iLength, pData, to);

    /* Profile the packet if net profiling is enabled */
    if (*(int *)(*(byte **)net_profile_dvar + 8) == 0)
        return;

    NetProf_PrepProfiling((netProfileInfo_t **)(clc_base + CLC_POOBPROF_OFF));
    NetProf_AddPacket((netProfileStream_t *)*(netProfileInfo_t **)(clc_base + CLC_POOBPROF_OFF), iLength, 0);
}

/* line 187 */
void CL_Netchan_PrintProfileStats(qboolean bPrintToConsole)
{
    char szLine[1024];
    int iYPos;
    int iTotalBPSSent;
    int iTotalBPSRecieved;
    byte *clc_base;
    netProfileInfo_t *pOOBProf;
    netProfileInfo_t *pProf;

    /* Get clientConnection_t base pointer */
    clc_base = *(byte **)clc_ptr;

    /* Update netchan profiling statistics if netchan.pProf is set */
    pProf = *(netProfileInfo_t **)(clc_base + CLC_NETCHAN_PPROF_OFF);
    if (pProf != NULL) {
        NetProf_UpdateStatistics((netProfileStream_t *)pProf);
        NetProf_UpdateStatistics((netProfileStream_t *)((byte *)pProf + 0x2f0));
    }

    /* Update OOB profiling statistics if pOOBProf is set */
    pOOBProf = *(netProfileInfo_t **)(clc_base + CLC_POOBPROF_OFF);
    if (pOOBProf != NULL) {
        NetProf_UpdateStatistics((netProfileStream_t *)pOOBProf);
        NetProf_UpdateStatistics((netProfileStream_t *)((byte *)pOOBProf + 0x2f0));
    }

    /* Print header */
    if (bPrintToConsole) {
        Com_Printf("\n\n");
    }

    Com_sprintf(szLine, 0x400, "====================");
    if (bPrintToConsole) {
        Com_Printf("%s\n", szLine);
        iYPos = 0x50;
    } else {
        CL_DrawString(0x20, 0x5a, szLine, 0, 0xa);
        iYPos = 0x5a;
    }

    Com_sprintf(szLine, 0x400, "Client Network Profile:");
    if (bPrintToConsole) {
        Com_Printf("%s\n\n", szLine);
    } else {
        CL_DrawString(0x20, iYPos + 0xa, szLine, 0, 0xa);
        iYPos += 0x14;
    }

    Com_sprintf(szLine, 0x400, "      Source    bps   max   min frag%%");
    if (bPrintToConsole) {
        Com_Printf("%s\n", szLine);
    } else {
        iYPos += 0xa;
        CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
    }

    /* Get OOB profiling info */
    clc_base = *(byte **)clc_ptr;
    pOOBProf = *(netProfileInfo_t **)(clc_base + CLC_POOBPROF_OFF);
    if (pOOBProf != NULL) {
        iTotalBPSSent = *(int *)((byte *)pOOBProf + 0x2d4);
        iTotalBPSRecieved = *(int *)((byte *)pOOBProf + 0x5c4);

        /* OOB Sent line */
        Com_sprintf(szLine, 0x400, "    OOB Sent: %5i %5i %5i    -",
            iTotalBPSSent,
            *(int *)((byte *)pOOBProf + 0x2e8),
            *(int *)((byte *)pOOBProf + 0x2ec));
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }

        /* OOB Recieved line */
        Com_sprintf(szLine, 0x400, "OOB Recieved: %5i %5i %5i    -",
            *(int *)((byte *)pOOBProf + 0x5c4),
            *(int *)((byte *)pOOBProf + 0x5d8),
            *(int *)((byte *)pOOBProf + 0x5dc));
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }
    } else {
        /* No OOB profile data */
        Com_sprintf(szLine, 0x400, "    OOB Sent:     0     0     0    -");
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }

        Com_sprintf(szLine, 0x400, "OOB Recieved:     0     0     0    -");
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }

        iTotalBPSSent = 0;
        iTotalBPSRecieved = 0;
    }

    /* Get netchan profiling info */
    clc_base = *(byte **)clc_ptr;
    pProf = *(netProfileInfo_t **)(clc_base + CLC_NETCHAN_PPROF_OFF);
    if (pProf != NULL) {
        iTotalBPSSent += *(int *)((byte *)pProf + 0x2d4);
        iTotalBPSRecieved += *(int *)((byte *)pProf + 0x5c4);

        /* Sent line with fragment percentage */
        Com_sprintf(szLine, 0x400, "        Sent: %5i %5i %5i  %3i%%",
            *(int *)((byte *)pProf + 0x2d4),
            *(int *)((byte *)pProf + 0x2e8),
            *(int *)((byte *)pProf + 0x2ec),
            *(int *)((byte *)pProf + 0x2e4));
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }

        /* Recieved line with fragment percentage */
        Com_sprintf(szLine, 0x400, "    Recieved: %5i %5i %5i  %3i%%",
            *(int *)((byte *)pProf + 0x5c4),
            *(int *)((byte *)pProf + 0x5d8),
            *(int *)((byte *)pProf + 0x5dc),
            *(int *)((byte *)pProf + 0x5d4));
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }
    } else {
        /* No netchan profile data */
        Com_sprintf(szLine, 0x400, "        Sent:     0     0     0    0%");
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }

        Com_sprintf(szLine, 0x400, "    Recieved:     0     0     0    0%");
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }
    }

    /* Total line */
    iYPos += 0xa;
    if (!bPrintToConsole) {
        CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
    }

    Com_sprintf(szLine, 0x400, "       Total: %5i",
        iTotalBPSSent + iTotalBPSRecieved);
    if (bPrintToConsole) {
        Com_Printf("%s\n", szLine);
    } else {
        CL_DrawString(0x20, iYPos + 0xa, szLine, 0, 0xa);
    }
}
