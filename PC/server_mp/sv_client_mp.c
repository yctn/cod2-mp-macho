/* ASM dump from: sv_client_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_client_mp.cpp */

#include "common_types.h"
#include "imports.h"

static int botport; /* botport */

extern float FX_GetServerVisibility(const vec_t *start, const vec_t *end);
extern void Com_DPrintf(const char *fmt, ...);
extern const char *SV_Cmd_Argv(int arg);
extern int atoi(const char *s);

static int sv_exec_dbg_count = 0;
void SV_ExecDbg(const char *fmt, int clSid, int svSid, int clState) {
    if (sv_exec_dbg_count < 20 || (sv_exec_dbg_count % 500 == 0)) {
        fprintf(stderr, fmt, clSid, svSid, clState);
    }
    sv_exec_dbg_count++;
}

void SV_AuthorizeRequest(struct netadr_t from, int challenge);
static qboolean SV_IsBannedGuid(void);
void SV_BanGuidBriefly(int guid);
void SV_UnbanClient(const char *name);
void SV_AuthorizeIpPacket(netadr_t from);
void SV_UserinfoChanged(client_t *cl);
void SV_FreeClientScriptPers(void);
void SV_DelayDropClient(client_t *drop, const char *reason);
void SV_SendClientGameState(client_t *client);
void SV_ClientEnterWorld(client_t *client, const dvar_t * (*cmd)[4]);
void SV_DoneDownload_f(client_t *cl);
void SV_RetransmitDownload_f(client_t *cl);
void SV_WriteDownloadToClient(client_t *cl, msg_t *msg);
void SV_VerifyIwds_f(client_t *cl);
void SV_ResetPureClient_f(client_t *cl);
void SV_UpdateUserinfo_f(client_t *cl);
void SV_MutePlayer_f(client_t *cl);
void SV_UnmutePlayer_f(client_t *cl);
float SV_FX_GetVisibility(const vec_t *start, const vec_t *end);
void SV_ExecuteClientCommand(client_t *cl, const char *s, qboolean clientOK);
void SV_ClientThink(client_t *cl, const dvar_t * (*cmd)[4]);
void SV_GetChallenge(netadr_t from);
void SV_FreeClient(client_t *cl);
void SV_DropClient(client_t *drop, const char *reason);
void SV_Disconnect_f(client_t *cl);
void SV_BanClient(client_t *cl);
void SV_DirectConnect(netadr_t from);
void SV_FreeClients(void);
void SV_StopDownload_f(client_t *cl);
void SV_NextDownload_f(client_t *cl);
void SV_BeginDownload_f(client_t *cl);
void SV_UserMove(client_t *cl, msg_t *msg, qboolean delta);
void SV_ExecuteClientMessage(client_t *cl, msg_t *msg);
gentity_t * SV_AddTestClient(void);

__attribute__((used)) ucmd_t ucmds[12] = {
    { (char *)"userinfo", (void (*)())SV_UpdateUserinfo_f },
    { (char *)"disconnect", (void (*)())SV_Disconnect_f },
    { (char *)"cp", (void (*)())SV_VerifyIwds_f },
    { (char *)"vdr", (void (*)())SV_ResetPureClient_f },
    { (char *)"download", (void (*)())SV_BeginDownload_f },
    { (char *)"nextdl", (void (*)())SV_NextDownload_f },
    { (char *)"stopdl", (void (*)())SV_StopDownload_f },
    { (char *)"donedl", (void (*)())SV_DoneDownload_f },
    { (char *)"retransdl", (void (*)())SV_RetransmitDownload_f },
    { (char *)"muteplayer", (void (*)())SV_MutePlayer_f },
    { (char *)"unmuteplayer", (void (*)())SV_UnmutePlayer_f },
    { 0, 0 },
}; /* 0x312ca0 */

/* line 138 */
extern const dvar_t * Dvar_RegisterString(const char *dvarName, const char *value, int flags);
extern const char *NET_AdrToString(netadr_t adr);
extern char *va(const char *fmt, ...);
extern Bool Dvar_GetBool(const char *dvarName);
extern void NET_OutOfBandPrint(int sock, netadr_t adr, const char *data);

static const dvar_t * Dvar_RegisterString_mac_sv(const char *name, const char *value, int flags) {
    return Dvar_RegisterString(name, value ? value : "", flags);
}

/* line 138 */
void SV_AuthorizeRequest(struct netadr_t from, int challenge)
{
    char game[0x400];
    extern void *imp_svs;
    serverStatic_t *svsPtr = (serverStatic_t *)imp_svs;

    /* line 146 */
    if (svsPtr->authorizeAddress.type == 1) {
        return;
    }

    /* line 149 */
    game[0] = '\0';

    /* line 150 */
    const dvar_t *fs_game = Dvar_RegisterString_mac_sv((const char *)"fs_game", (const char *)"", 0x101c);

    /* line 151 */
    if (fs_game) {
        const char *val = *(const char **)((char *)fs_game + 8);
        if (val[0] != '\0') {
            /* line 152 */
            strcpy(game, val);
        }
    }

    /* line 154 */
    Com_DPrintf((const char *)"sending getIpAuthorize for %s\n", NET_AdrToString(from));

    /* line 155 */
    Bool allowAnon = Dvar_GetBool((const char *)"sv_allowAnonymous");

    /* line 158 */
    const char *s = va((const char *)"getIpAuthorize %i %i.%i.%i.%i %s %i", challenge,
        (unsigned int)from.ip[0], (unsigned int)from.ip[1],
        (unsigned int)from.ip[2], (unsigned int)from.ip[3],
        game, (int)(unsigned char)allowAnon);

    /* line 159 */
    NET_OutOfBandPrint(1, svsPtr->authorizeAddress, s);
}
