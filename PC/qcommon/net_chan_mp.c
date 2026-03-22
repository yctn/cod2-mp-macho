/* ASM dump from: net_chan_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/net_chan_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

extern int g_qport; /* 0x0 */
extern const dvar_t *net_profile; /* 0x0 */
extern const dvar_t *net_showprofile; /* 0x0 */
extern const dvar_t *net_lanauthorize; /* 0x0 */
extern const dvar_t *showpackets; /* 0x0 */
extern const dvar_t *showdrop; /* 0x0 */
extern const dvar_t *packetDebug; /* 0x0 */
static char s[64]; /* s */
extern const char str_002ab028[];
extern const char str_002ab030[];

__attribute__((used, packed, aligned(4)))
UInt32 netsrcString_storage[7] __asm__("netsrcString") = {
    (UInt32)str_002ab028,
    (UInt32)str_002ab030,
    0,
    0,
    0,
    0,
    0,
}; /* 0x312044 */

#define netsrcString ((char **)netsrcString_storage)
static int net_iProfilingOn; /* net_iProfilingOn */
extern loopback_t loopbacks[2]; /* loopbacks — must be extern to share
                                    with the binary's loopback buffer */

extern void Com_Printf(const char *fmt, ...);
extern void Com_DPrintf(const char *fmt, ...);
extern void Com_Error(int level, const char *fmt, ...);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void Com_Memcpy(void *dest, const void *src, int count);
extern void SV_Netchan_PrintProfileStats(int bDumpRecvStats);
extern void CL_Netchan_PrintProfileStats(int bDumpRecvStats);
extern qboolean Sys_GetPacket(netadr_t *net_from, msg_t *net_message);
extern qboolean Sys_StringToAdr(const char *s, netadr_t *a);
extern Bool Sys_SendPacket(int length, const void *data, netadr_t to);
extern int Sys_Milliseconds(void);
extern void *malloc(int size);
extern void free(void *ptr);
extern char *strchr(const char *s, int c);
extern int atoi(const char *s);
extern void I_strncpyz(char *dest, const char *src, int size);
extern const dvar_t *Dvar_RegisterBool(const char *name, qboolean defaultValue, int flags);
extern const dvar_t *Dvar_RegisterInt(const char *name, int defaultValue, int minValue, int maxValue, int flags);
extern void Cmd_AddCommand(const char *cmd_name, void (*function)(void));
extern void MSG_Init(msg_t *buf, byte *data, int length);
extern void MSG_WriteLong(msg_t *sb, int c);
extern void MSG_WriteShort(msg_t *sb, int c);
extern void MSG_WriteData(msg_t *buf, const void *data, int length);
extern void MSG_BeginReading(msg_t *msg);
extern int MSG_ReadLong(msg_t *msg);
extern int MSG_ReadShort(msg_t *msg);
extern void SV_Netchan_AddOOBProfilePacket(int size);
extern void CL_Netchan_AddOOBProfilePacket(int size);
extern void LargeLocal_LargeLocal(void *ll, int size);
extern void *LargeLocal_GetBuf(void *ll);
extern void ZN10LargeLocalD1Ev(void *ll);
extern void *imp_com_sv_running;
extern void *imp_legacyHacks;

void NetProf_PrepProfiling(netProfileInfo_t * *pProf);
void NetProf_AddPacket(netProfileStream_t *pProfStream, int iSize, qboolean bFragment);
void NetProf_UpdateStatistics(netProfileStream_t *pStream);
void Net_DumpProfile_f(void);
void Net_DisplayProfile(void);
void Netchan_Init(int port);
void Netchan_Setup(netsrc_t sock, netchan_t *chan, struct netadr_t adr, int qport);
int NET_CompareAdrSigned(netadr_t *a, netadr_t *b);
qboolean NET_IsLocalAddress(netadr_t adr);
qboolean NET_GetPacket(netadr_t *net_from, msg_t *net_message);
const char * NET_AdrToString(netadr_t a);
qboolean NET_StringToAdr(const char *s, netadr_t *a);
Bool NET_SendPacket(netsrc_t sock, int length, const void *data, netadr_t to);
void NET_OutOfBandVoiceData(netsrc_t sock, netadr_t adr, byte *format, int len);
Bool NET_OutOfBandData(netsrc_t sock, netadr_t adr, byte *format, int len);
Bool NET_OutOfBandPrint(netsrc_t sock, netadr_t adr, const char *data);
qboolean NET_CompareAdr(netadr_t a, netadr_t b);
qboolean NET_CompareBaseAdr(netadr_t a, netadr_t b);
qboolean NET_GetLoopPacket(netsrc_t sock, netadr_t *net_from, msg_t *net_message);
Bool Netchan_TransmitNextFragment(netchan_t *chan);
Bool Netchan_Transmit(netchan_t *chan, int length, const byte *data);
qboolean Netchan_Process(netchan_t *chan, msg_t *msg);

/* line 156 */
void NetProf_PrepProfiling(netProfileInfo_t * *pProf)
{
    /* net_profile->integer (offset 8 from dvar_t*) */
    int net_profile_val = (int)net_profile->current.integer;

    if (net_profile_val != 0) {
        /* profiling enabled */
        if (net_iProfilingOn != 0) {
            /* profiling was already on */
            if (*pProf != NULL)
                return;
            goto alloc_prof;
        }
        /* profiling was off, turn it on */
        {
            /* check com_sv_running->integer (offset 8) */
            int sv_running = *(int *)((byte *)(*(void **)imp_com_sv_running) + 8);
            if (sv_running != 0) {
                /* server is running - check legacyHacks->field4 */
                int lh_field = *(int *)((byte *)(*(void **)imp_legacyHacks) + 4);
                if (lh_field != 0 && net_iProfilingOn == 2) {
                    /* already mode 2, set to 1 */
                    net_iProfilingOn = 1;
                } else {
                    net_iProfilingOn = 2;
                }
            } else {
                net_iProfilingOn = 1;
            }
            Com_Printf("Net Profiling turned on: %s\n", g_qport);
            if (*pProf != NULL)
                return;
            goto alloc_prof;
        }
    } else {
        /* profiling disabled */
        if (net_iProfilingOn != 0) {
            /* was on, turn it off */
            net_iProfilingOn = 0;
            Com_Printf("Net Profiling turned off\n");
            if (*pProf != NULL) {
                free(*pProf);
                *pProf = NULL;
            }
            return;
        }
        /* was already off */
        if (*pProf != NULL) {
            free(*pProf);
            *pProf = NULL;
        }
        return;
    }

alloc_prof:
    *pProf = (netProfileInfo_t *)malloc(0x5e0);
    memset(*pProf, 0, 0x5e0);
    return;
}

/* line 205 */
void NetProf_AddPacket(netProfileStream_t *pProfStream, int iSize, qboolean bFragment)
{
    /* The ring buffer index logic:
     * newIdx = (pProfStream->iCurrPacket + 1) % 60
     * pProfStream->iCurrPacket = newIdx
     * pPacket = &pProfStream->packets[newIdx]
     * packets is at offset 0 from pProfStream, iCurrPacket at 0x2d0
     * Each packet is 12 bytes (netProfilePacket_t: iTime, iSize, bFragment)
     * offset 0x2d0 = 60 * 12 = 720, correct for iCurrPacket
     */
    int newIdx = (pProfStream->iCurrPacket + 1) % 60;
    pProfStream->iCurrPacket = newIdx;
    netProfilePacket_t *pPacket = &pProfStream->packets[newIdx];
    pPacket->iTime = Sys_Milliseconds();
    pPacket->iSize = iSize;
    pPacket->bFragment = bFragment;
}

/* line 269 */
void NetProf_UpdateStatistics(netProfileStream_t *pStream)
{
    int iCurTime = Sys_Milliseconds();
    netProfilePacket_t *pBase = pStream->packets;
    int iNumPackets = 0;
    int iNumFragments = 0;
    int iOldestPacket = -1;
    int iTotalBytes = 0;
    int iSmallestSize = 0x270f;
    int iLargestSize = 0;
    int i;

    for (i = 0; i < 60; i++) {
        netProfilePacket_t *p = &pBase[i];
        if (p->iTime == 0)
            continue;
        /* skip if older than 1000ms */
        if (Sys_Milliseconds() > p->iTime + 0x3e8)
            continue;
        iNumPackets++;
        if (p->bFragment >= 1)
            iNumFragments++;
        if (p->iTime < iCurTime) {
            iOldestPacket = i;
            iCurTime = p->iTime;
        }
        iTotalBytes += p->iSize;
        if (p->iSize < iSmallestSize)
            iSmallestSize = p->iSize;
        if (p->iSize > iLargestSize)
            iLargestSize = p->iSize;
    }

    if (iNumPackets == 0) {
        pStream->iBytesPerSecond  = 0;
        pStream->iLastBPSCalcTime = 0;
        pStream->iCountedPackets  = 0;
        pStream->iCountedFragments= 0;
        pStream->iLargestPacket   = 0;
        pStream->iSmallestPacket  = 0;
        /* offset 0x2ec */
        pStream->iSmallestPacket = 0;
        return;
    }

    /* iNumFragments != 0 branch */
    if (iNumFragments != 0) {
        /* fragPct = iNumFragments * 100 / iNumPackets */
        int fragPct = iNumFragments * 100 / iNumPackets;
        pStream->iLargestPacket   = fragPct;  /* 0x2e4 */
        pStream->iSmallestPacket  = iLargestSize; /* 0x2e8 */
        pStream->iSmallestPacket = iSmallestSize;
    } else {
        pStream->iLargestPacket   = 0;        /* 0x2e4 */
        pStream->iSmallestPacket  = iLargestSize; /* 0x2e8 */
        pStream->iSmallestPacket = iSmallestSize;
    }

    /* Rate update every 100ms */
    {
        int lastCalc = pStream->iLastBPSCalcTime + 0x64;
        int now = Sys_Milliseconds();
        if (lastCalc < now) {
            /* Need rate recalc */
            int timeDelta = now - iCurTime;  /* Sys_Milliseconds() - iCurTime (before loop modified it) */

            if (iOldestPacket != -1) {
                /* subtract oldest packet */
                netProfilePacket_t *oldest = &pBase[iOldestPacket];
                iTotalBytes -= oldest->iSize;
                iNumPackets--;
                if (oldest->bFragment >= 1)
                    iNumFragments--;
            }

            if (timeDelta <= 0 || iNumPackets == 0) {
                pStream->iBytesPerSecond = 0;
            } else if (iTotalBytes == 0) {
                pStream->iBytesPerSecond = 0;
            } else {
                /* bps = iTotalBytes / (timeDelta * 0.001f) */
                pStream->iBytesPerSecond = (int)((float)iTotalBytes / ((float)timeDelta * 0.001f));
            }
            pStream->iLastBPSCalcTime = Sys_Milliseconds();
        }
        pStream->iCountedPackets   = iNumPackets;
        pStream->iCountedFragments = iNumFragments;
    }
}

/* line 390 */
void Net_DumpProfile_f(void)
{
    if (net_iProfilingOn == 0)
    {
        Com_Printf("Network profiling is not on. Set net_profile to turn on network profiling\n");
        return;
    }
    if (net_iProfilingOn == 1)
    {
        CL_Netchan_PrintProfileStats(1);
        return;
    }
    SV_Netchan_PrintProfileStats(1);
}

/* line 419 */
void Net_DisplayProfile(void)
{
    if (net_iProfilingOn == 0)
        return;
    if (net_iProfilingOn == 1)
    {
        CL_Netchan_PrintProfileStats(0);
        return;
    }
    SV_Netchan_PrintProfileStats(0);
}

/* line 837 */
void Netchan_Init(int port)
{
    showpackets    = Dvar_RegisterBool("showpackets", 0, 0);
    showdrop       = Dvar_RegisterBool("showdrop", 0, 0);
    packetDebug    = Dvar_RegisterBool("packetDebug", 0, 0);
    g_qport        = (unsigned short)port;
    net_profile    = Dvar_RegisterInt("net_profile", 0, 0, 2, 0);
    net_showprofile= Dvar_RegisterInt("net_showprofile", 0, 0, 3, 0);
    net_lanauthorize = Dvar_RegisterBool("net_lanauthorize", 0, 0);
    Cmd_AddCommand("net_dumpprofile", Net_DumpProfile_f);
}

/* line 879 */
void Netchan_Setup(netsrc_t sock, netchan_t *chan, struct netadr_t adr, int qport)
{
    memset(chan, 0, 0x8038);
    chan->sock            = sock;
    chan->remoteAddress   = adr;
    chan->qport           = qport;
    chan->dropped         = 0;
    chan->outgoingSequence = 1;
    NetProf_PrepProfiling((netProfileInfo_t **)((byte *)chan + 0x8034));
}

/* line 1252 */
int NET_CompareAdrSigned(netadr_t *a, netadr_t *b)
{
    int diff;
    if (a->type != b->type) {
        return (int)a->type - (int)b->type;
    }
    if (a->type == 2) {
        /* NA_LOOPBACK - compare port only (word at offset 8) */
        return 0;
    }
    if (a->type != 4) {
        Com_Printf("NET_CompareAdrSigned: bad address type\n");
        return 0;
    }
    /* NA_IP: compare port */
    if (a->port != b->port) {
        return (int)(unsigned short)a->port - (int)(unsigned short)b->port;
    }
    /* compare 4 bytes of IP */
    diff = memcmp(a->ip, b->ip, 4);
    return diff;
}

/* line 1293 */
qboolean NET_IsLocalAddress(netadr_t adr)
{
    if (adr.type == 2 || adr.type == 0)
        return 1;
    return 0;
}

/* line 1308 */
qboolean NET_GetPacket(netadr_t *net_from, msg_t *net_message)
{
    return Sys_GetPacket(net_from, net_message);
}

/* line 126 */
const char * NET_AdrToString(netadr_t a)
{
    if (a.type == 2) {
        /* NA_LOOPBACK */
        Com_sprintf(s, 0x40, "loopback");
    } else if (a.type == 4) {
        /* NA_IP */
        unsigned short portHost = (a.port >> 8) | (a.port << 8);  /* rol 8 */
        Com_sprintf(s, 0x40, "%i.%i.%i.%i:%i",
            (int)a.ip[0],
            (int)a.ip[1],
            (int)a.ip[2],
            (int)a.ip[3],
            (int)(short)portHost);
    }
    /* else: return s as-is (unchanged) */
    return s;
}

/* line 1617 */
qboolean NET_StringToAdr(const char *s, netadr_t *a)
{
    char base[0x400];
    char *port;

    /* check for "loopback" or "localhost" */
    if (memcmp(s, "loopback", 0xa) == 0 || memcmp(s, "localhost", 0xa) == 0) {
        a->port = 0;
        a->type = 0; /* clear ip */
        *(int *)((byte *)a + 4) = 0;
        a->type = 2; /* NA_LOOPBACK */
        return 1;
    }

    I_strncpyz(base, s, 0x400);
    port = strchr(base, ':');
    if (port != NULL) {
        *port = 0;
        port++;
    }

    if (!Sys_StringToAdr(base, a)) {
        a->type = 1; /* NA_BAD */
        return 0;
    }

    if (*(int *)((byte *)a + 4) == -1) {
        /* broadcast */
        a->type = 1; /* NA_BAD */
        return 0;
    }

    if (port != NULL) {
        int portNum = atoi(port);
        /* big-endian byte swap */
        a->port = (unsigned short)((portNum >> 8) | (portNum << 8));
        return 1;
    } else {
        /* default port 8241 (0x2071) */
        a->port = 0x2071;
        return 1;
    }
}

/* line 1389 */
static int net_send_diag = 0;
Bool NET_SendPacket(netsrc_t sock, int length, const void *data, netadr_t to)
{
    net_send_diag++;
    if (net_send_diag <= 50) {
        const char *d = (const char *)data;
        const char *payload = (length > 4 && d[0]==(char)0xff) ? d+4 : d;
        int plen = (length > 4 && d[0]==(char)0xff) ? length-4 : length;
        /* print replacing newlines with | */
        char buf[256];
        int i;
        for (i = 0; i < plen && i < 255; i++) {
            buf[i] = (payload[i] == '\n') ? '|' : (payload[i] ? payload[i] : '?');
        }
        buf[i] = 0;
        fprintf(stderr, "[NET_Send#%d] sock=%d type=%d len=%d data=[%s]\n",
                net_send_diag, sock, to.type, length, buf);
    }
    if (showpackets->current.enabled) {
        if (*(int *)data != -1) {
            Com_Printf("[client %i] send packet %4i\n", 0, length);
        }
    }

    if (length > 100 && to.type != 2) {
        static int dbg_nonloop;
        if (dbg_nonloop++ < 5)
            Com_Printf("DBG NET_SendPacket: NON-LOOPBACK large pkt! sock=%d len=%d type=%d\n",
                sock, length, to.type);
    }
    if (to.type == 2) {
        /* NA_LOOPBACK - send to the OTHER side's inbox (sock^1) */
        int idx;
        loopmsg_t *msg;
        loopback_t *loop;

        if (sock <= 0) {
            /* client sends to server inbox */
            idx = 1;
            loop = &loopbacks[idx];
            int sendSlot = loop->send & 0xf;
            loop->send++;
            msg = &loop->msgs[sendSlot];
            memcpy(msg, data, length);
            msg->datalen = length;
            msg->port = 0;
            return 1;
        } else if (sock == 1) {
            /* server sends to client inbox */
            unsigned short portVal = to.port;
            idx = 0;
            loop = &loopbacks[idx];
            int sendSlot = loop->send & 0xf;
            loop->send++;
            msg = &loop->msgs[sendSlot];
            memcpy(msg, data, length);
            msg->datalen = length;
            msg->port = portVal;
            return 1;
        } else {
            /* sock > 1: not loopback capable */
            return 0;
        }
    } else if (to.type == 1 || to.type == 0) {
        /* NA_BAD or NA_BOT: return 0 */
        return 0;
    } else {
        /* NA_IP or other: send via Sys_SendPacket */
        return Sys_SendPacket(length, data, to);
    }
}

/* line 1569 */
void NET_OutOfBandVoiceData(netsrc_t sock, netadr_t adr, byte *format, int len)
{
    byte string[0x8000 + 4];

    string[0] = 0xff;
    string[1] = 0xff;
    string[2] = 0xff;
    string[3] = 0xff;
    memcpy(string + 4, format, len);
    len += 4;

    NET_SendPacket(sock, len, string, adr);

    if (sock == 1) {
        SV_Netchan_AddOOBProfilePacket(len);
    } else {
        CL_Netchan_AddOOBProfilePacket(len);
    }
}

/* line 1520 */
Bool NET_OutOfBandData(netsrc_t sock, netadr_t adr, byte *format, int len)
{
    /* LargeLocal is 8 bytes on stack (pointer + size) */
    char string_large_local[8];
    byte *string;
    int i;
    Bool res;

    LargeLocal_LargeLocal(string_large_local, 0x4000);
    string = (byte *)LargeLocal_GetBuf(string_large_local);
    string[0] = 0xff;
    string[1] = 0xff;
    string[2] = 0xff;
    string[3] = 0xff;

    for (i = 0; i < len; i++) {
        string[4 + i] = format[i];
    }
    len += 4;

    res = NET_SendPacket(sock, len, string, adr);

    if (sock == 1) {
        SV_Netchan_AddOOBProfilePacket(len);
    } else {
        CL_Netchan_AddOOBProfilePacket(len);
    }

    ZN10LargeLocalD1Ev(string_large_local);
    return res > 0 ? 1 : 0;
}

/* line 1465 */
Bool NET_OutOfBandPrint(netsrc_t sock, netadr_t adr, const char *data)
{
    /* LargeLocal is 8 bytes on stack */
    char string_large_local[8];
    byte *string;
    int iLength;
    Bool res;

    LargeLocal_LargeLocal(string_large_local, 0x4000);
    string = (byte *)LargeLocal_GetBuf(string_large_local);
    string[0] = 0xff;
    string[1] = 0xff;
    string[2] = 0xff;
    string[3] = 0xff;

    if (showpackets->current.enabled) {
        Com_DPrintf("OOB Print: %s\n", data);
    }

    iLength = strlen(data);
    if (iLength + 1 > 0x3ffc) {
        Com_DPrintf("OOB Packet is %i bytes - too large to send\n", iLength);
        ZN10LargeLocalD1Ev(string_large_local);
        return 0;
    }

    memcpy(string + 4, data, iLength + 1);
    iLength = strlen((char *)string);

    res = NET_SendPacket(sock, iLength, string, adr);

    if (sock == 1) {
        SV_Netchan_AddOOBProfilePacket(iLength);
    } else {
        CL_Netchan_AddOOBProfilePacket(iLength);
    }

    res = res > 0 ? 1 : 0;
    ZN10LargeLocalD1Ev(string_large_local);
    return res;
}

/* line 1281 */
qboolean NET_CompareAdr(netadr_t a, netadr_t b)
{
    int diff;
    if (a.type != b.type) {
        diff = (int)a.type - (int)b.type;
        return diff == 0 ? 1 : 0;
    }
    if (a.type == 2) {
        /* NA_LOOPBACK: equal */
        return 1;
    }
    if (a.type != 4) {
        Com_Printf("NET_CompareAdr: bad address type\n");
        return 0;
    }
    /* NA_IP: compare port */
    if (a.port != b.port) {
        return 0;
    }
    /* compare 4 bytes of ip */
    diff = memcmp(a.ip, b.ip, 4);
    return diff == 0 ? 1 : 0;
}

/* line 1246 */
qboolean NET_CompareBaseAdr(netadr_t a, netadr_t b)
{
    int diff;
    if (a.type != b.type) {
        diff = (int)a.type - (int)b.type;
        return diff == 0 ? 1 : 0;
    }
    if (a.type == 2) {
        /* NA_LOOPBACK: compare port word */
        diff = (int)(unsigned short)a.port - (int)(unsigned short)b.port;
        return diff == 0 ? 1 : 0;
    }
    if (a.type == 0) {
        /* NA_BOT: compare port word */
        diff = (int)(unsigned short)a.port - (int)(unsigned short)b.port;
        return diff == 0 ? 1 : 0;
    }
    if (a.type != 4) {
        Com_Printf("NET_CompareBaseAdr: bad address type\n");
        diff = 0;
        return diff == 0 ? 1 : 0;
    }
    /* NA_IP: compare 4 IP bytes only (no port) */
    diff = memcmp(a.ip, b.ip, 4);
    return diff == 0 ? 1 : 0;
}

/* line 1349 */
qboolean NET_GetLoopPacket(netsrc_t sock, netadr_t *net_from, msg_t *net_message)
{
    /* loopback index calculation from sock:
     * loop = &loopbacks[sock * 0x581 * 8]  (the struct size is 0x5808 bytes)
     * Actually the asm does: eax*4+eax -> eax*5, then eax*2+eax -> eax*11... wait
     * Let me re-read: leal(eax,eax,4) = eax*5, leal(eax,edx,2) where edx=eax*5 = eax + eax*10 = eax*11
     * shll $8 = eax*11*256 = eax*2816, then addl eax = eax*2817
     * leal loopbacks(,edx,8) = loopbacks + edx*8 = loopbacks + sock*2817*8
     * But loopback_t is 16*1400+8+4 = 22412 bytes... that seems wrong.
     * Actually loopmsg_t: byte data[1400] + int datalen + int port = 1408 bytes
     * loopback_t: 16 * 1408 + 4 + 4 = 22536 bytes
     * 22536 = 22536... Let's trust the asm: use sock directly as index.
     */
    loopback_t *loop = &loopbacks[(int)sock];
    int send = loop->send;
    int get  = loop->get;
    int pending = send - get;

    static int getloop_diag = 0;
    if (pending > 0 && getloop_diag < 40) {
        getloop_diag++;
        fprintf(stderr, "[GetLoop#%d] sock=%d send=%d get=%d pending=%d\n",
                getloop_diag, sock, send, get, pending);
    }

    if (pending > 16) {
        /* drop overflow */
        loop->get = send - 16;
        get = loop->get;
    }

    if (get >= loop->send) {
        return 0;
    }

    {
        int slot = get & 0xf;
        loop->get++;
        loopmsg_t *m = &loop->msgs[slot];

        memcpy(net_message->data, m, m->datalen);
        net_message->cursize = m->datalen;

        net_from->port = 0;
        *(int *)((byte *)net_from + 4) = 0;
        net_from->type = 2; /* NA_LOOPBACK */
        net_from->port = (unsigned short)m->port;
        return 1;
    }
}

/* line 902 */
Bool Netchan_TransmitNextFragment(netchan_t *chan)
{
    byte send_buf[0x578];
    msg_t send;
    int fragmentLength;
    int res;
    int iSize;

    /* Prep profiling on the send stream (chan->pProf, at offset 0x8034) */
    NetProf_PrepProfiling((netProfileInfo_t **)((byte *)chan + 0x8034));

    MSG_Init(&send, send_buf, 0x578);
    MSG_WriteLong(&send, chan->outgoingSequence | 0x80000000);

    if (chan->sock == 0) {
        MSG_WriteShort(&send, chan->qport);
    }

    /* fragment offset and length */
    {
        int fragStart = chan->unsentFragmentStart;
        int remaining = chan->unsentLength - fragStart;
        if (remaining > 0x514) {
            fragmentLength = 0x514;
        } else {
            fragmentLength = remaining;
        }

        if (chan->sock == 0) {
            MSG_WriteLong(&send, fragStart);
        } else {
            MSG_WriteShort(&send, fragStart);
        }
        MSG_WriteShort(&send, fragmentLength);
        MSG_WriteData(&send, chan->unsentBuffer + fragStart, fragmentLength);
    }

    res = (int)NET_SendPacket(chan->sock, send.cursize, send.data, chan->remoteAddress);
    iSize = send.cursize;

    if (net_iProfilingOn != 0) {
        netProfileStream_t *pProfStream = chan->pProf ? &chan->pProf->send : NULL;
        if (pProfStream) {
            NetProf_AddPacket(pProfStream, iSize, 1);
        }
        if (net_showprofile->current.integer & 2) {
            Com_Printf("%s send%s: %i\n",
                netsrcString[chan->sock],
                " fragment",
                iSize);
        }
    }

    if (showpackets->current.enabled) {
        Com_Printf("[client %i] %s send %4i : s=%i fragment=%i,%i\n",
            0,
            netsrcString[chan->sock],
            send.cursize,
            chan->outgoingSequence - 1,
            chan->unsentFragmentStart,
            fragmentLength);
    }

    chan->unsentFragmentStart += fragmentLength;

    if (chan->unsentFragmentStart == chan->unsentLength) {
        if (fragmentLength != 0x514) {
            /* last fragment */
            chan->outgoingSequence++;
            chan->unsentFragments = 0;
        }
    }

    return res > 0 ? 1 : 0;
}

/* line 977 */
Bool Netchan_Transmit(netchan_t *chan, int length, const byte *data)
{
    byte send_buf[0x578];
    msg_t send;
    int res;
    int iSize;

    if (length > 0x4000) {
        Com_Error(1, "Netchan_Transmit: length = %i", length);
    }

    chan->unsentFragmentStart = 0;

    if (length > 0x513) {
        /* fragmented */
        chan->unsentFragments = 1;
        chan->unsentLength = length;
        Com_Memcpy(chan->unsentBuffer, data, length);
        Netchan_TransmitNextFragment(chan);
        return 1;
    }

    /* Prep profiling */
    NetProf_PrepProfiling((netProfileInfo_t **)((byte *)chan + 0x8034));

    MSG_Init(&send, send_buf, 0x578);
    MSG_WriteLong(&send, chan->outgoingSequence);
    chan->outgoingSequence++;

    if (chan->sock == 0) {
        MSG_WriteShort(&send, chan->qport);
    }

    if (packetDebug->current.enabled) {
        Com_Printf("Adding %i byte payload to packet\n", length);
    }
    MSG_WriteData(&send, data, length);
    if (packetDebug->current.enabled) {
        Com_Printf("Sending %i byte packet\n", send.cursize);
    }

    res = (int)NET_SendPacket(chan->sock, send.cursize, send.data, chan->remoteAddress);
    iSize = send.cursize;

    if (net_iProfilingOn != 0) {
        netProfileStream_t *pProfStream = chan->pProf ? &chan->pProf->send : NULL;
        if (pProfStream) {
            NetProf_AddPacket(pProfStream, iSize, 0);
        }
        if (net_showprofile->current.integer & 2) {
            Com_Printf("%s send%s: %i\n",
                netsrcString[chan->sock],
                "",
                iSize);
        }
    }

    if (showpackets->current.enabled) {
        Com_Printf("[client %i] %s send %4i : s=%i ack=%i\n",
            1,
            netsrcString[chan->sock],
            send.cursize,
            chan->outgoingSequence - 1,
            chan->incomingSequence);
    }

    return res > 0 ? 1 : 0;
}

/* line 1058 */
qboolean Netchan_Process(netchan_t *chan, msg_t *msg)
{
    int sequence;
    int fragmented;
    int fragmentStart;
    int fragmentLength;
    int iSize;

    /* Prep profiling on the receive stream */
    NetProf_PrepProfiling((netProfileInfo_t **)((byte *)chan + 0x8034));

    MSG_BeginReading(msg);
    sequence = MSG_ReadLong(msg);

    if (sequence < 0) {
        sequence &= 0x7fffffff;
        fragmented = 1;
    } else {
        fragmented = 0;
    }

    /* read qport if needed */
    if (chan->sock == 1) {
        MSG_ReadShort(msg);
    }

    if (fragmented) {
        /* The sender writes the fragment offset as Long (client, sock=0)
           or Short (server, sock=1).  The receiver has the OPPOSITE sock
           value, so we must read in the opposite format from what our
           own sock would suggest. */
        if (chan->sock == 1) {
            fragmentStart = MSG_ReadLong(msg);
        } else {
            fragmentStart = MSG_ReadShort(msg);
        }
        fragmentLength = MSG_ReadShort(msg);
    } else {
        fragmentStart  = 0;
        fragmentLength = 0;
    }

    iSize = msg->cursize;

    /* profiling */
    if (net_iProfilingOn != 0) {
        netProfileStream_t *pProfStream = chan->pProf ? (netProfileStream_t *)((byte *)chan->pProf + 0x2f0) : NULL;
        if (pProfStream) {
            NetProf_AddPacket(pProfStream, iSize, fragmented);
        }
        if (net_showprofile->current.integer & 2) {
            Com_Printf("%s recieve%s: %i\n",
                netsrcString[chan->sock],
                fragmented ? " fragment" : "",
                iSize);
        }
    }

    if (showpackets->current.enabled) {
        if (!fragmented) {
            Com_Printf("[client %i] %s recv %4i : s=%i\n",
                1,
                netsrcString[chan->sock],
                msg->cursize,
                sequence);
        } else {
            Com_Printf("[client %i] %s recv %4i : s=%i fragment=%i,%i\n",
                1,
                netsrcString[chan->sock],
                msg->cursize,
                sequence,
                fragmentStart,
                fragmentLength);
        }
    }

    /* out-of-order check */
    if (sequence <= chan->incomingSequence) {
        if (showdrop->current.enabled || showpackets->current.enabled) {
            Com_Printf("[client %i] %s:Out of order packet %i at %i\n",
                1,
                NET_AdrToString(chan->remoteAddress),
                sequence,
                chan->incomingSequence);
        }
        return 0;
    }

    /* dropped packets */
    chan->dropped = sequence - chan->incomingSequence - 1;
    if (chan->dropped > 0) {
        if (showdrop->current.enabled || showpackets->current.enabled) {
            Com_Printf("[client %i] %s: Dropped %i packets at %i\n",
                1,
                NET_AdrToString(chan->remoteAddress),
                chan->dropped,
                sequence);
        }
    }

    if (!fragmented) {
        chan->incomingSequence = sequence;
        return 1;
    }

    /* fragmented packet handling */
    if (sequence != chan->fragmentSequence) {
        chan->fragmentSequence = sequence;
        chan->fragmentLength   = 0;
    }

    if (fragmentStart != chan->fragmentLength) {
        if (showdrop->current.enabled || showpackets->current.enabled) {
            Com_Printf("%s:Dropped a message fragment\n",
                NET_AdrToString(chan->remoteAddress),
                sequence);
        }
        return 0;
    }

    /* validate fragment */
    if (fragmentLength < 0 ||
        msg->readcount + fragmentLength > msg->cursize ||
        fragmentStart + fragmentLength > 0x4000) {
        if (showdrop->current.enabled || showpackets->current.enabled) {
            Com_Printf("%s:illegal fragment length\n",
                NET_AdrToString(chan->remoteAddress));
        }
        return 0;
    }

    /* copy fragment data into fragmentBuffer */
    memcpy(chan->fragmentBuffer + fragmentStart,
           msg->data + msg->readcount,
           fragmentLength);

    chan->fragmentLength += fragmentLength;

    if (fragmentLength == 0x514) {
        /* not last fragment */
        return 0;
    }

    /* check max size */
    if (chan->fragmentLength > msg->maxsize) {
        Com_Printf("%s:fragmentLength %i > msg->maxsize\n",
            NET_AdrToString(chan->remoteAddress),
            chan->fragmentLength);
        return 0;
    }

    /* Reassemble: write sequence into msg header and copy fragment data after it */
    {
        *(int *)(msg->data) = sequence; /* write clean sequence at offset 0 */
        memcpy(msg->data + 4, chan->fragmentBuffer, chan->fragmentLength);
        msg->cursize = chan->fragmentLength + 4;
        chan->fragmentLength = 0;
        MSG_BeginReading(msg);
        MSG_ReadLong(msg); /* consume sequence */
    }

    chan->incomingSequence = sequence;
    return 1;
}
