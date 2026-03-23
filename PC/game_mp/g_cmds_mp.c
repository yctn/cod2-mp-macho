/* ASM dump from: g_cmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_cmds_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 */

static char line[1024]; /* line */
extern const char str_002b3564[];
extern const char str_002b3580[];
extern const char str_002b359c[];
extern const char str_002b35b0[];
extern const char str_002b35c0[];
extern const char str_002b35d8[];
extern const char str_002b35f0[];

__attribute__((used, packed, aligned(4)))
UInt32 gc_orders_storage[8] __asm__("gc_orders") = {
    (UInt32)str_002b3564,
    (UInt32)str_002b3580,
    (UInt32)str_002b359c,
    (UInt32)str_002b35b0,
    (UInt32)str_002b35c0,
    (UInt32)str_002b35d8,
    (UInt32)str_002b35f0,
    0,
}; /* 0x313c80 */

#define gc_orders ((char **)gc_orders_storage)
extern level_locals_t level;
extern gentity_t g_entities[1024];
extern const dvar_t *g_cheats;
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern char *va(const char *fmt, ...);
extern int SV_GetClientPing(int clientNum);
extern void SV_GameSendServerCommand(int clientNum, int type, const char *text);
extern void SV_SetConfigstring(int index, const char *val);
extern int SV_Cmd_Argc(void);
extern void SV_Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength);

enum {
    GCMDS_MAX_CLIENTS = 64
};

void DeathmatchScoreboardMessage(gentity_t *ent);
void Cmd_Score_f(gentity_t *ent);
qboolean CheatsOk(gentity_t *ent);
char * ConcatArgs(int start);
void G_setfog(const char *fogstring);
qboolean Cmd_FollowCycle_f(gentity_t *ent, int dir);
qboolean G_IsPlaying(gentity_t *ent);
void Cmd_CallVote_f(gentity_t *ent);
void Cmd_Vote_f(gentity_t *ent);
void Cmd_SetViewpos_f(gentity_t *ent);
void Cmd_MenuResponse_f(gentity_t *pEnt);
static void G_SayTo(int color, const char *name, const char *message);
void G_Say(gentity_t *ent, gentity_t *target, int mode, const char *chatText);
void Cmd_GameCommand_f(gentity_t *ent);
void StopFollowing(gentity_t *ent);
void Cmd_Give_f(gentity_t *ent);
void Cmd_Take_f(gentity_t *ent);
void ClientCommand(int clientNum);

/* line 13 */
void DeathmatchScoreboardMessage(gentity_t *ent)
{
    gclient_t *client;
    int clientNum;
    char entry[1024];
    int i;
    int j;
    int numSorted;
    int ping;
    char string[1400];
    int stringlength;

    string[0] = '\0';
    stringlength = 0;

    numSorted = level.numConnectedClients;
    if (numSorted > GCMDS_MAX_CLIENTS) {
        numSorted = GCMDS_MAX_CLIENTS;
    }

    for (i = 0; i < numSorted; ++i) {
        clientNum = level.sortedClients[i];
        client = &level.clients[clientNum];

        if (client->sess.connected == CON_CONNECTING) {
            Com_sprintf(entry, sizeof(entry), " %i %i %i %i %i",
                level.sortedClients[i], client->sess.score, -1,
                client->sess.deaths, client->sess.status_icon);
        } else {
            ping = SV_GetClientPing(clientNum);
            Com_sprintf(entry, sizeof(entry), " %i %i %i %i %i",
                level.sortedClients[i], client->sess.score, ping,
                client->sess.deaths, client->sess.status_icon);
        }

        j = strlen(entry);
        if (stringlength + j > 1024) {
            break;
        }

        strcpy(string + stringlength, entry);
        stringlength += j;
    }

    SV_GameSendServerCommand(ent - g_entities, SV_CMD_RELIABLE,
        va("%c %i %i %i%s", 98, i, level.teamScores[TEAM_AXIS],
            level.teamScores[TEAM_ALLIES], string));
}

/* line 66 */
void Cmd_Score_f(gentity_t *ent)
{
    DeathmatchScoreboardMessage(ent);
}

/* line 77 */
qboolean CheatsOk(gentity_t *ent)
{
    if (!g_cheats->current.enabled) {
        SV_GameSendServerCommand(ent - g_entities, SV_CMD_CAN_IGNORE,
            va("%c \"GAME_CHEATSNOTENABLED\"", 101));
        return 0;
    }

    if (ent->health <= 0) {
        SV_GameSendServerCommand(ent - g_entities, SV_CMD_CAN_IGNORE,
            va("%c \"GAME_MUSTBEALIVECOMMAND\"", 101));
        return 0;
    }

    return 1;
}

/* line 98 */
char * ConcatArgs(int start)
{
    char arg[1024];
    int argc;
    int i;
    int len;
    int tlen;

    argc = SV_Cmd_Argc();
    len = 0;

    for (i = start; i < argc; ++i) {
        SV_Cmd_ArgvBuffer(i, arg, sizeof(arg));
        tlen = strlen(arg);

        if (len + tlen >= (int)sizeof(line) - 1) {
            break;
        }

        memcpy(line + len, arg, tlen);
        len += tlen;

        if (i != argc - 1) {
            line[len] = ' ';
            ++len;
        }
    }

    line[len] = '\0';
    return line;
}

/* line 217 */
void G_setfog(const char *fogstring)
{
    float fTime;
    float r;
    float g;
    float b;
    float fDensity;
    float fFar;
    float fNear;

    SV_SetConfigstring(12, fogstring);

    level.fFogOpaqueDist = 3.402823466e+38f;
    level.fFogOpaqueDistSqrd = 3.402823466e+38f;

    if (sscanf(fogstring, "%f %f %f %f %f %f %f", &fNear, &fFar, &fDensity, &r, &g, &b, &fTime) != 7) {
        return;
    }

    if (fDensity < 1.0f) {
        return;
    }

    level.fFogOpaqueDist = fFar;
    level.fFogOpaqueDistSqrd = fFar * fFar;
}

/* line 732 */
extern void Com_Error(int code, const char *fmt, ...);
extern qboolean SV_GetArchivedClientInfo(int clientNum, int *archiveTime, playerState_t *ps, clientState_t *cs);
extern qboolean G_ClientCanSpectateTeam(gclient_t *client, int team);

qboolean Cmd_FollowCycle_f(gentity_t *ent, int dir) {
    int clientnum;
    int original;
    gclient_t *client;
    playerState_t ps;
    clientState_t cs;
    int maxclients;

    if (dir != 1 && dir != -1) {
        Com_Error(1, str_002b3724, dir);
    }

    client = ent->client;
    /* Check session state == 2 (spectating) */
    if (((gclient_t *)client)->sess.sessionState != 2)
        return 0;

    /* Check forceSpectatorClient >= 0 */
    if (((gclient_t *)client)->sess.forceSpectatorClient >= 0)
        return 0;

    /* Get spectatorClient */
    clientnum = ((gclient_t *)client)->spectatorClient;
    if (clientnum < 0)
        clientnum = 0;

    original = clientnum;

    for (;;) {
        clientnum += dir;

        maxclients = level.maxclients;
        if (clientnum >= maxclients) {
            clientnum = 0;
        }
        if (clientnum == -1) {
            clientnum = maxclients - 1;
        }

        /* Try to get archived client info */
        client = ent->client;
        if (SV_GetArchivedClientInfo(clientnum, &client->sess.archiveTime, &ps, &cs)) {
            /* Check if we can spectate this team */
            if (G_ClientCanSpectateTeam(ent->client, cs.team)) {
                /* Set spectatorClient and session state */
                ((gclient_t *)client)->spectatorClient = clientnum;
                ((gclient_t *)client)->sess.sessionState = 2;
                return 1;
            }
        }

        if (clientnum == original)
            return 0;
    }
}
