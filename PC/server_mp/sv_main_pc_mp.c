/* Converted to C from ASM: sv_main_pc_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_main_pc_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern Bool NET_OutOfBandPrint(netsrc_t sock, netadr_t adr, const char *data);
extern const char *NET_AdrToString(netadr_t a);
extern qboolean NET_StringToAdr(const char *s, netadr_t *a);
extern int Com_Milliseconds(void);
extern char *SV_Cmd_Argv(int arg);
extern int SV_Cmd_Argc(void);
extern void SV_Cmd_ExecuteString(const char *text);
extern void Com_BeginRedirect(char *buffer, int buffersize, void (*flush)(char *));
extern void Com_EndRedirect(void);
extern int Com_AddToString(const char *add, char *msg, int len, int maxlen, qboolean mayAddQuotes);
extern const char *va(const char *fmt, ...);
extern long int SVC_Status(netadr_t from);
extern long int SVC_GameCompleteStatus(netadr_t from);

/* Global pointers accessed by absolute address in the original binary */
extern byte *svs_ptr;                /* imp_svs - pointer to serverStatic_t */
extern const dvar_t **sv_dedicated_dvar; /* imp_com_dedicated */
extern const dvar_t **rcon_password_dvar; /* imp_rcon_password */

/* serverStatic_t field offsets */
#define SVS_TIME_OFF              0x4
#define SVS_NEXTHEARTBEATTIME_OFF 0x54
#define SVS_NEXTSTATUSRESPTIME_OFF 0x58
#define SVS_REDIRECTADDR_OFF      0xa05c

static int lasttime; /* lasttime */
static netadr_t adr; /* adr */

void SV_FlushRedirect(char *outputbuf);
void SVC_RemoteCommand(struct netadr_t from, msg_t *msg);
void SV_MatchEnd(void);
const netadr_t *SV_MasterAddress(void);
void SV_MasterGameCompleteStatus(void);
void SV_MasterHeartbeat(const char *hbname);
void SV_MasterShutdown(void);

/* line 180 */
void SV_FlushRedirect(char *outputbuf)
{
    char buf[0x514];
    int len;
    char *ptr;
    char c;
    netadr_t addr;
    byte *svs;

    svs = *(byte **)&svs_ptr;

    len = strlen(outputbuf);

    if (len > 0x50e) {
        ptr = outputbuf;
        while (len > 0x50e) {
            c = ptr[0x50e];
            ptr[0x50e] = '\0';

            Com_sprintf(buf, 0x514, "print\n%s", ptr);
            addr = *(netadr_t *)(svs + SVS_REDIRECTADDR_OFF);
            NET_OutOfBandPrint(NS_SERVER, addr, buf);

            len -= 0x50e;
            ptr[0x50e] = c;
            ptr += 0x50e;
        }
        outputbuf = ptr;
    }

    /* Send remaining (or only) chunk */
    Com_sprintf(buf, 0x514, "print\n%s", outputbuf);
    addr = *(netadr_t *)(svs + SVS_REDIRECTADDR_OFF);
    NET_OutOfBandPrint(NS_SERVER, addr, buf);
}

/* line 214 */
void SVC_RemoteCommand(struct netadr_t from, msg_t *msg)
{
    char sv_outputbuf[0x3ff0];
    char remaining[0x400];
    char *password;
    char *cmd;
    int valid;
    int time;
    int i;
    int len;
    byte *svs;
    netadr_t addr;
    const dvar_t *rcon_dvar;

    svs = *(byte **)&svs_ptr;

    time = Com_Milliseconds();

    if (lasttime != 0 && (time - lasttime) <= 499) {
        return;
    }

    lasttime = time;

    password = SV_Cmd_Argv(1);

    rcon_dvar = *rcon_password_dvar;
    if (rcon_dvar->current.string[0] != '\0' && strcmp(password, rcon_dvar->current.string) == 0) {
        /* Valid rcon */
        cmd = SV_Cmd_Argv(2);
        Com_Printf("Rcon from %s:\n%s\n", NET_AdrToString(from), cmd);
        valid = 1;
    } else {
        /* Bad rcon */
        cmd = SV_Cmd_Argv(2);
        Com_Printf("Bad rcon from %s:\n%s\n", NET_AdrToString(from), cmd);
        valid = 0;
    }

    /* Set redirect address */
    *(netadr_t *)(svs + SVS_REDIRECTADDR_OFF) = from;

    Com_BeginRedirect(sv_outputbuf, 0x3ff0, SV_FlushRedirect);

    rcon_dvar = *rcon_password_dvar;
    if (rcon_dvar->current.string[0] == '\0') {
        /* No rcon password set on the server */
        Com_Printf("No rconpassword set on the server.\n");
        Com_EndRedirect();
        return;
    }

    if (valid == 0) {
        if (password[0] != '\0') {
            Com_Printf("Invalid password.\n");
        } else {
            Com_Printf("No rconpassword.\n");
        }
        Com_EndRedirect();
        return;
    }

    /* Build and execute the command */
    len = 0;
    for (i = 2; i < SV_Cmd_Argc(); i++) {
        len = Com_AddToString(SV_Cmd_Argv(i), remaining, len, 0x400, 1);
        len = Com_AddToString(" ", remaining, len, 0x400, 0);
    }

    if (len > 0x3ff) {
        Com_EndRedirect();
        return;
    }

    remaining[len] = '\0';
    SV_Cmd_ExecuteString(remaining);

    Com_EndRedirect();
}

/* line 287 */
void SV_MatchEnd(void)
{
    /* Empty function */
}

/* line 32 */
const netadr_t *SV_MasterAddress(void)
{
    if (adr.type == NA_BOT) {
        Com_Printf("Resolving %s\n", "cod2master.activision.com");

        if (!NET_StringToAdr("cod2master.activision.com", &adr)) {
            Com_Printf("Couldn't resolve address: cod2master.activision.com\n");
            return &adr;
        }

        adr.port = (unsigned short)((20966 >> 8) | (20966 << 8));

        Com_Printf("cod2master.activision.com resolved to %i.%i.%i.%i:%i\n",
                    adr.ip[0], adr.ip[1], adr.ip[2], adr.ip[3], 20966);
    }

    return &adr;
}

/* line 124 */
void SV_MasterGameCompleteStatus(void)
{
    const dvar_t *dedicated;
    const netadr_t *master;
    netadr_t addr;

    dedicated = *sv_dedicated_dvar;
    if (!dedicated || dedicated->current.integer != 2) {
        return;
    }

    master = SV_MasterAddress();
    if (master->type == NA_BAD) {
        return;
    }

    Com_Printf("Sending gameCompleteStatus to master server\n");

    addr = *master;
    SVC_GameCompleteStatus(addr);
}

/* line 74 */
void SV_MasterHeartbeat(const char *hbname)
{
    const dvar_t *dedicated;
    byte *svs;
    const netadr_t *master;
    netadr_t addr;
    int time;

    svs = *(byte **)&svs_ptr;

    dedicated = *sv_dedicated_dvar;
    if (!dedicated || dedicated->current.integer != 2) {
        return;
    }

    time = *(int *)(svs + SVS_TIME_OFF);

    if (time < *(int *)(svs + SVS_NEXTHEARTBEATTIME_OFF)) {
        /* First heartbeat: set nextHeartbeatTime, resolve and send */
        *(int *)(svs + SVS_NEXTHEARTBEATTIME_OFF) = time + 180000;

        master = SV_MasterAddress();
        if (master->type == NA_BAD) {
            /* Master resolve failed, fall through to status check */
            time = *(int *)(svs + SVS_TIME_OFF);
        } else {
            Com_Printf("Sending heartbeat to master server\n");
            addr = *master;
            NET_OutOfBandPrint(NS_SERVER, addr, va("heartbeat %s\n", hbname));
            time = *(int *)(svs + SVS_TIME_OFF);
        }
    }

    /* Status response time check */
    if (time < *(int *)(svs + SVS_NEXTSTATUSRESPTIME_OFF)) {
        return;
    }

    *(int *)(svs + SVS_NEXTSTATUSRESPTIME_OFF) = time + 600000;

    master = SV_MasterAddress();
    if (master->type == NA_BAD) {
        return;
    }

    addr = *master;
    SVC_Status(addr);
}

/* line 154 */
void SV_MasterShutdown(void)
{
    byte *svs;

    svs = *(byte **)&svs_ptr;
    *(int *)(svs + SVS_NEXTHEARTBEATTIME_OFF) = (int)0x80000000;

    SV_MasterHeartbeat("flatline");
}
