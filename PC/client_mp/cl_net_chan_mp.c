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
static int cl_decode_count = 0;

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
    reliableAcknowledge = ((clientConnection_t *)clc_base)->reliableAcknowledge;
    string = ((clientConnection_t *)clc_base)->reliableCommands[reliableAcknowledge & 0x7f];

    /* Compute initial key from serverMessageSequence XOR challenge */
    key = (byte)(((clientConnection_t *)clc_base)->serverMessageSequence);
    key ^= (byte)(((clientConnection_t *)clc_base)->challenge);

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
    serverCommandSequence = ((clientConnection_t *)clc_base)->serverCommandSequence;
    string = ((clientConnection_t *)clc_base)->serverCommands[serverCommandSequence & 0x7f];

    /* Compute initial key from cl->serverId XOR challenge XOR serverMessageSequence */
    key = (byte)((*(clientActive_t **)cl_ptr)->serverId);
    key ^= (byte)(((clientConnection_t *)clc_base)->challenge);
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
    NetProf_PrepProfiling(&((clientConnection_t *)clc_base)->pOOBProf);
    pOOBProf = ((clientConnection_t *)clc_base)->pOOBProf;
    NetProf_AddPacket(&pOOBProf->send, iLength, 0);
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
    NetProf_PrepProfiling(&((clientConnection_t *)clc_base)->pOOBProf);

    /* Send the packet */
    NET_SendPacket(NS_CLIENT1, iLength, pData, to);

    /* Profile the packet if net profiling is enabled */
    if (*(int *)(*(byte **)net_profile_dvar + 8) == 0)
        return;

    NetProf_PrepProfiling(&((clientConnection_t *)clc_base)->pOOBProf);
    NetProf_AddPacket(&((clientConnection_t *)clc_base)->pOOBProf->send, iLength, 0);
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
    pProf = ((clientConnection_t *)clc_base)->netchan.pProf;
    if (pProf != NULL) {
        NetProf_UpdateStatistics(&pProf->send);
        NetProf_UpdateStatistics(&pProf->recieve);
    }

    /* Update OOB profiling statistics if pOOBProf is set */
    pOOBProf = ((clientConnection_t *)clc_base)->pOOBProf;
    if (pOOBProf != NULL) {
        NetProf_UpdateStatistics(&pOOBProf->send);
        NetProf_UpdateStatistics(&pOOBProf->recieve);
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
    pOOBProf = ((clientConnection_t *)clc_base)->pOOBProf;
    if (pOOBProf != NULL) {
        iTotalBPSSent = pOOBProf->send.iBytesPerSecond;
        iTotalBPSRecieved = pOOBProf->recieve.iBytesPerSecond;

        /* OOB Sent line */
        Com_sprintf(szLine, 0x400, "    OOB Sent: %5i %5i %5i    -",
            iTotalBPSSent,
            pOOBProf->send.iLargestPacket,
            pOOBProf->send.iSmallestPacket);
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }

        /* OOB Recieved line */
        Com_sprintf(szLine, 0x400, "OOB Recieved: %5i %5i %5i    -",
            pOOBProf->recieve.iBytesPerSecond,
            pOOBProf->recieve.iLargestPacket,
            pOOBProf->recieve.iSmallestPacket);
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
    pProf = ((clientConnection_t *)clc_base)->netchan.pProf;
    if (pProf != NULL) {
        iTotalBPSSent += pProf->send.iBytesPerSecond;
        iTotalBPSRecieved += pProf->recieve.iBytesPerSecond;

        /* Sent line with fragment percentage */
        Com_sprintf(szLine, 0x400, "        Sent: %5i %5i %5i  %3i%%",
            pProf->send.iBytesPerSecond,
            pProf->send.iLargestPacket,
            pProf->send.iSmallestPacket,
            pProf->send.iFragmentPercentage);
        if (bPrintToConsole) {
            Com_Printf("%s\n", szLine);
        } else {
            iYPos += 0xa;
            CL_DrawString(0x20, iYPos, szLine, 0, 0xa);
        }

        /* Recieved line with fragment percentage */
        Com_sprintf(szLine, 0x400, "    Recieved: %5i %5i %5i  %3i%%",
            pProf->recieve.iBytesPerSecond,
            pProf->recieve.iLargestPacket,
            pProf->recieve.iSmallestPacket,
            pProf->recieve.iFragmentPercentage);
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
