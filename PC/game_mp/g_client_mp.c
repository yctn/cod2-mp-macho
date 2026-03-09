/* Converted to C from ASM: g_client_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_client_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>
#include <stdlib.h>

extern void Com_Printf(const char *fmt, ...);
extern void AngleVectors(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
extern float AngleDelta(float a1, float a2);
extern float AngleNormalize180(float angle);
extern float AngleNormalize360(float angle);
extern void CalculateRanks(void);
extern void Scr_Notify(gentity_t *ent, unsigned short name, int numArgs);
extern int Scr_IsSystemActive(int flag);
extern void Scr_AddString(const char *str);
extern void Scr_PlayerConnect(gentity_t *ent);
extern void Scr_PlayerDisconnect(gentity_t *ent);
extern void StopFollowing(gentity_t *ent);
extern void HudElem_ClientDisconnect(gentity_t *ent);
extern void G_FreeEntity(gentity_t *ent);
extern void G_InitGentity(gentity_t *ent);
extern void G_EntUnlink(gentity_t *ent);
extern void G_SetOrigin(gentity_t *ent, const vec_t *origin);
extern void G_SetClientContents(gentity_t *ent);
extern void G_ClientStopUsingTurret(gentity_t *ent);
extern int G_DObjGetWorldTagPos(gentity_t *ent, unsigned short tag, vec_t *origin);
extern void SV_UnlinkEntity(gentity_t *ent);
extern int SV_inSnapshot(vec_t *vPosition, int clientNum);
extern int OnSameTeam(gentity_t *a, gentity_t *b);
extern int SV_ClientHasClientMuted(int clientNum, int mutedClientNum);
extern int SV_ClientWantsVoiceData(int clientNum);
extern void SV_QueueVoicePacket(int talkerNum, int clientNum, VoicePacket_t *voicePacket);
extern void SV_GetUserinfo(int clientNum, char *buffer, int bufSize);
extern void SV_GetUsercmd(int clientNum, byte *dest);
extern int SV_IsLocalClient(int clientNum);
extern int Info_Validate(const char *s);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern int I_stricmp(const char *s1, const char *s2);
extern void Scr_SetString(unsigned short *dest, unsigned short value);
extern void ClientEndFrame(gentity_t *ent);
extern void ClientThink_real(gentity_t *ent, byte *ucmd);
extern void BG_PlayerStateToEntityState(byte *ps, gentity_t *ent, int snap, int forceOverride);
extern float BG_GetBobCycle(byte *ps);
extern float BG_GetSpeed(byte *ps, int serverTime);
extern float BG_GetVerticalBobFactor(byte *ps, float bobCycle, float xyspeed, int bobMax);
extern float BG_GetHorizontalBobFactor(byte *ps, float bobCycle, float xyspeed, int bobMax);
extern void AddLeanToPosition(vec_t *origin, int viewAngle, int leanFrac, float maxStand, float maxCrouch);
extern int ColorIndex(int c);
extern void Com_Error(int level, const char *fmt, ...);

extern vec3_t playerMins; /* 0x0 */
extern vec3_t playerMaxs; /* 0x0 */

extern byte g_entities_ptr[]; /* imp_g_entities - g_entities base */
extern byte level_ptr[]; /* imp_level - used for level metadata */
extern unsigned char g_clients[]; /* BSS client array - used for client data access */
/* In original game, imp_level pointed to combined level+clients memory.
   In decomp, level and g_clients are separate BSS arrays.
   Client data access must use g_clients, not level_ptr. */
#define CLIENT_BASE g_clients
extern byte *g_scr_data_ptr; /* imp_scr_const */
extern byte *g_sv_running_ptr; /* imp_voice_global */
extern byte *g_deadChat_ptr; /* imp_voice_deadChat */
extern byte *g_voiceChatsAllowed_ptr; /* imp_voice_localEcho */
extern byte *g_voiceChatTalkingDuration_ptr; /* imp_g_inactivity */
extern byte *g_password_ptr; /* imp_g_password */
extern byte *g_bobMax_ptr; /* imp_bg_bobMax */
extern int __mh_execute_header;
extern int g_time; /* imp_level_bgs */

void G_GetPlayerViewDirection(const gentity_t *ent, vec_t *forward, vec_t *right, vec_t *up);
void ClientBegin(int clientNum);
void ClientDisconnect(int clientNum);
int G_GetNonPVSFriendlyInfo(gentity_t *pSelf, vec_t *vPosition, int iLastUpdateEnt);
void G_BroadcastVoice(gentity_t *talker, VoicePacket_t *voicePacket);
void SetClientViewAngle(gentity_t *ent, const vec_t *angle);
void ClientSpawn(gentity_t *ent, const vec_t *spawn_origin, const vec_t *spawn_angles);
void G_GetPlayerViewOrigin(const gentity_t *ent, vec_t *origin);
void ClientUserinfoChanged(int clientNum);
char * ClientConnect(int clientNum, int scriptPersId);

#define GENTITY_STRIDE sizeof(gentity_s)
#define CLIENT_STRIDE sizeof(gclient_s)

/* line 156 */
void G_GetPlayerViewDirection(const gentity_t *ent, vec_t *forward, vec_t *right, vec_t *up)
{
    byte *client = *(byte **)((byte *)ent + 0x158);
    AngleVectors((vec_t *)(client + 0xe8), forward, right, up);
}

/* line 426 */
void ClientBegin(int clientNum)
{
    byte *level = (byte *)CLIENT_BASE;
    byte *client = level +clientNum * CLIENT_STRIDE;
    byte *ents = (byte *)g_entities_ptr;
    byte *scr_data = *(byte **)g_scr_data_ptr;
    gentity_t *ent;

    *(int *)(client + 0x26c4) = 2;
    *(int *)(client + 4) = 4;

    CalculateRanks();

    ent = (gentity_t *)(ents + clientNum * GENTITY_STRIDE);
    Scr_Notify(ent, *(unsigned short *)(scr_data + 0x6c), 0);
}

/* line 596 */
void ClientDisconnect(int clientNum)
{
    byte *level = (byte *)CLIENT_BASE;
    byte *client;
    gentity_t *ent;
    byte *ents;
    int i;

    client = level +clientNum * CLIENT_STRIDE;
    ents = (byte *)g_entities_ptr;
    ent = (gentity_t *)(ents + clientNum * GENTITY_STRIDE);

    if (Scr_IsSystemActive(1)) {
        Scr_AddString("disconnect");
        Scr_AddString("^1teleport");
        {
            byte *scr_data = *(byte **)g_scr_data_ptr;
            Scr_Notify(ent, *(unsigned short *)(scr_data + 0x70), 2);
        }
    }

    /* Stop other players following this client */
    if (*(int *)(level + 0x1e4) > 0) {
        for (i = 0; i < *(int *)(level + 0x1e4); i++) {
            byte *otherClient = level +i * CLIENT_STRIDE;
            gentity_t *otherEnt = (gentity_t *)(ents + i * GENTITY_STRIDE);

            if (*(int *)(otherClient + 0x26c4) == 0)
                continue;
            if (*(int *)(otherClient + 0x26a8) != 2)
                continue;
            if (*(int *)(otherClient + 0x27a8) != clientNum)
                continue;

            StopFollowing(otherEnt);
        }
    }

    HudElem_ClientDisconnect(ent);

    if (Scr_IsSystemActive(1)) {
        Scr_PlayerDisconnect(ent);
    }

    G_FreeEntity(ent);

    *(int *)(client + 0x26c4) = 0;
    memset(client + 0x2748, 0, 0x5c);

    CalculateRanks();
}

/* line 651 */
int G_GetNonPVSFriendlyInfo(gentity_t *pSelf, vec_t *vPosition, int iLastUpdateEnt)
{
    byte *selfClient;
    int team;
    int iBaseEnt;
    int iEntCount;
    int ent_num;
    byte *ents;
    byte *pEnt;
    byte *pEntClient;
    int dx, dy;
    float scaleX, scaleY, ratioX, ratioY;

    selfClient = *(byte **)((byte *)pSelf + 0x158);
    team = *(int *)(selfClient + 0x274c);

    if (team == 0 || team == 3)
        return 0;

    if (iLastUpdateEnt == 0x3ff)
        iBaseEnt = 0;
    else
        iBaseEnt = iLastUpdateEnt + 1;

    ents = (byte *)g_entities_ptr;

    for (iEntCount = 0; iEntCount < 64; iEntCount++) {
        ent_num = (iBaseEnt + iEntCount) % 64;
        if (ent_num < 0)
            ent_num += 64;

        pEnt = ents + ent_num * GENTITY_STRIDE;

        if (*(byte *)(pEnt + 0xfc) == 0)
            continue;

        pEntClient = *(byte **)(pEnt + 0x158);
        if (pEntClient == NULL)
            continue;

        if (*(int *)(pEntClient + 0x26a8) != 0)
            continue;

        if (*(int *)(pEntClient + 0x274c) != team)
            continue;

        if ((gentity_t *)pEnt == pSelf)
            continue;

        /* Check if in snapshot */
        if (SV_inSnapshot(vPosition, *(int *)pEnt))
            continue;

        /* Calculate relative position */
        {
            int result = *(int *)pEnt;
            float ex = *(float *)(pEnt + 0x138);
            float ey = *(float *)(pEnt + 0x13c);

            dx = (int)(ex - vPosition[0] + 0.5f);
            dy = (int)(ey - vPosition[1] + 0.5f);

            /* Compute scale factors */
            if (dx > 0x400) {
                scaleX = 1024.0f / (float)dx;
                ratioX = 1.0f;
            } else if (dx < -1022) {
                scaleX = -1022.0f / (float)dx;
                ratioX = 1.0f;
            } else {
                scaleX = 1.0f;
                ratioX = 1.0f;
            }

            if (dy > 0x400) {
                scaleY = 1024.0f / (float)dy;
            } else if (dy < -1022) {
                scaleY = -1022.0f / (float)dy;
            } else {
                scaleY = ratioX;  /* 1.0f */
            }

            /* Scale coordinates to fit range */
            if (ratioX > scaleX) {
                if (scaleX > scaleY) {
                    /* scaleY is smallest - scale dx by scaleY */
                    dx = (int)((float)dx * scaleY);
                } else {
                    /* scaleX <= scaleY - scale dy by scaleX */
                    dy = (int)((float)dy * scaleX);
                }
            } else if (ratioX > scaleY) {
                /* ratioX <= scaleX, ratioX > scaleY - scale dx by scaleY ratio */
                dx = (int)((float)dx * scaleY);
            }

            /* Clamp to range */
            if (dx > 0x400)
                dx = 0x402;
            else if (dx < -1022)
                dx = -1020;
            else
                dx = dx + 2;

            if (dy > 0x400)
                dy = 0x402;
            else if (dy < -1022)
                dy = -1020;
            else
                dy = dy + 2;

            /* Pack result: bits [6:14] = dx/4+255, bits [15:23] = dy/4+255, bits [24:31] = yaw */
            result &= 0xffff803f;
            {
                int scaledDx = (dx < 0 ? (dx + 3) : dx) >> 2;
                scaledDx = (scaledDx + 0xff) & 0x1ff;
                result |= (scaledDx << 6);
            }
            result &= 0xff007fff;
            {
                int scaledDy = (dy < 0 ? (dy + 3) : dy) >> 2;
                scaledDy = (scaledDy + 0xff) & 0x1ff;
                result |= (scaledDy << 15);
            }
            result &= 0xffffff;
            {
                int yawByte = (int)(*(float *)(pEnt + 0x148) * 0.7111111283302307f);
                result |= (yawByte << 24);
            }

            return result;
        }
    }

    return 0;
}

/* line 748 */
void G_BroadcastVoice(gentity_t *talker, VoicePacket_t *voicePacket)
{
    byte *talkerClient;
    byte *ents;
    byte *otherEnt;
    byte *otherClient;
    int otherPlayer;
    int talkerTeam;

    talkerClient = *(byte **)((byte *)talker + 0x158);

    /* Set voice chat timestamp */
    {
        byte *level = (byte *)CLIENT_BASE;
        *(int *)(talkerClient + 0x2808) = *(int *)(level + 0x1ec);
    }

    ents = (byte *)g_entities_ptr;

    for (otherPlayer = 0; otherPlayer < 64; otherPlayer++) {
        otherEnt = ents + otherPlayer * GENTITY_STRIDE;

        if (*(byte *)(otherEnt + 0xfc) == 0)
            continue;

        otherClient = *(byte **)(otherEnt + 0x158);
        if (otherClient == NULL)
            continue;

        /* Check sv_voice_enabled dvar */
        {
            byte *dvar = *(byte **)g_sv_running_ptr;
            dvar = *(byte **)dvar;
            if (*(byte *)(dvar + 8) != 0)
                goto check_team;
        }

        if (!OnSameTeam((gentity_t *)((byte *)talker), (gentity_t *)otherEnt))
        {
            talkerClient = *(byte **)((byte *)talker + 0x158);
            talkerTeam = *(int *)(talkerClient + 0x274c);
            if (talkerTeam != 0) {
                continue;
            }
        }

        talkerClient = *(byte **)((byte *)talker + 0x158);
    check_team:
        /* Check if same team or spectator */
        {
            int otherSessTeam = *(int *)(*(byte **)(otherEnt + 0x158) + 0x26a8);
            int talkerSessTeam = *(int *)(talkerClient + 0x26a8);
            if (otherSessTeam == talkerSessTeam)
                goto check_can_send;

            if (otherSessTeam - 1 == 0 || talkerSessTeam - 1 == 0) {
                byte *deadChatDvar = *(byte **)g_deadChat_ptr;
                deadChatDvar = *(byte **)deadChatDvar;
                if (*(byte *)(deadChatDvar + 8) == 0)
                    continue;
            }
        }

    check_can_send:
        /* Don't send to self unless voiceChatsAllowed */
        if ((gentity_t *)otherEnt == talker) {
            byte *dvar = *(byte **)g_voiceChatsAllowed_ptr;
            dvar = *(byte **)dvar;
            if (*(byte *)(dvar + 8) == 0)
                continue;
        }

        if (SV_ClientHasClientMuted(otherPlayer, *(int *)talker))
            continue;

        if (!SV_ClientWantsVoiceData(otherPlayer))
            continue;

        SV_QueueVoicePacket(*(int *)talker, otherPlayer, voicePacket);
    }
}

/* line 22 */
void SetClientViewAngle(gentity_t *ent, const vec_t *angle)
{
    vec3_t newAngle;
    byte *client;
    int i;
    float delta;

    newAngle[0] = angle[0];
    newAngle[1] = angle[1];
    newAngle[2] = angle[2];

    client = *(byte **)((byte *)ent + 0x158);

    if ((*(byte *)(client + 0xc) & 1) == 0 || (*(int *)(client + 0xa0) & 0x300) != 0) {
        /* Pitch angle clamping vs vehicle turret limits */
        delta = AngleNormalize180(AngleDelta(*(float *)(client + 0x584), newAngle[1]));

        if (delta > 45.0f) {
            float overflow = delta - 45.0f;
            client = *(byte **)((byte *)ent + 0x158);
            *(int *)(client + 0x58) += (int)(overflow * 182.04444885253906f) & 0xffff;
            if (overflow > 0.0f)
                newAngle[1] = AngleNormalize360(*(float *)(client + 0x584) - 45.0f);
            else
                newAngle[1] = AngleNormalize360(45.0f + *(float *)(client + 0x584));
        } else if (delta < -45.0f) {
            float overflow = delta + 45.0f;
            client = *(byte **)((byte *)ent + 0x158);
            *(int *)(client + 0x58) += (int)(overflow * 182.04444885253906f) & 0xffff;
            if (overflow > 0.0f)
                newAngle[1] = AngleNormalize360(*(float *)(client + 0x584) - 45.0f);
            else
                newAngle[1] = AngleNormalize360(45.0f + *(float *)(client + 0x584));
        }

        /* Yaw angle clamping */
        client = *(byte **)((byte *)ent + 0x158);
        delta = AngleNormalize180(AngleDelta(*(float *)(client + 0x58c), newAngle[0]));

        if (delta > 45.0f) {
            float overflow = delta - 45.0f;
            client = *(byte **)((byte *)ent + 0x158);
            *(int *)(client + 0x54) += (int)(overflow * 182.04444885253906f) & 0xffff;
            if (overflow > 0.0f)
                newAngle[0] = AngleNormalize180(*(float *)(client + 0x58c) - 45.0f);
            else
                newAngle[0] = AngleNormalize180(15.0f + *(float *)(client + 0x58c));
        } else if (delta < -15.0f) {
            float overflow = delta + 15.0f;
            client = *(byte **)((byte *)ent + 0x158);
            *(int *)(client + 0x54) += (int)(overflow * 182.04444885253906f) & 0xffff;
            if (overflow > 0.0f)
                newAngle[0] = AngleNormalize180(*(float *)(client + 0x58c) - 45.0f);
            else
                newAngle[0] = AngleNormalize180(15.0f + *(float *)(client + 0x58c));
        }

        client = *(byte **)((byte *)ent + 0x158);
    }

    /* Set delta angles and copy angles */
    for (i = 0; i < 3; i++) {
        int cmdAngle = (int)(newAngle[i] * 182.04444885253906f) & 0xffff;
        *(int *)(client + 0x54 + i * 4) = cmdAngle - *(int *)(client + 0x26d4 + i * 4);
        client = *(byte **)((byte *)ent + 0x158);
    }

    /* Copy to ent->s.apos + ent angles */
    *(float *)((byte *)ent + 0x144) = newAngle[0];
    *(float *)((byte *)ent + 0x148) = newAngle[1];
    *(float *)((byte *)ent + 0x14c) = newAngle[2];

    client = *(byte **)((byte *)ent + 0x158);
    *(float *)(client + 0xe8) = newAngle[0];
    *(float *)(client + 0xec) = newAngle[1];
    *(float *)(client + 0xf0) = newAngle[2];
}

/* line 452 */
void ClientSpawn(gentity_t *ent, const vec_t *spawn_origin, const vec_t *spawn_angles)
{
    byte *client;
    byte *level;
    byte *ents;
    int clientNum;
    int iFlags;
    int savedSpawnCount;
    byte savedSess[0x100];
    byte *scr_data;

    ents = (byte *)g_entities_ptr;
    clientNum = ((byte *)ent - ents) / GENTITY_STRIDE;

    client = *(byte **)((byte *)ent + 0x158);
    level = (byte *)CLIENT_BASE;

    /* Check if player is in turret */
    if (*(byte *)(client + 0xe) & 0x80) {
        if (*(int *)(client + 0xa0) & 0x300) {
            /* Stop using turret first */
            int turretEntNum = *(int *)(client + 0x594);
            byte *turretEnt = (byte *)CLIENT_BASE + 4;
            turretEnt = *(byte **)turretEnt;
            byte *actualTurretEnt = turretEnt + turretEntNum * GENTITY_STRIDE;
            G_ClientStopUsingTurret((gentity_t *)actualTurretEnt);
        }
    }

    G_EntUnlink(ent);

    if (*(byte *)((byte *)ent + 0xf0) != 0)
        SV_UnlinkEntity(ent);

    *(int *)((byte *)ent + 0x7c) = 0x3ff;

    scr_data = *(byte **)g_scr_data_ptr;
    Scr_SetString((unsigned short *)((byte *)ent + 0x168), *(unsigned short *)(scr_data + 0x32));

    *(int *)((byte *)ent + 0x184) = 0x2810011;
    *(byte *)((byte *)ent + 0xf2) |= 1;
    *(byte *)((byte *)ent + 0x161) = 0;

    G_SetClientContents(ent);

    *(byte *)((byte *)ent + 0x166) = 0xa;
    *(int *)((byte *)ent + 0x174) = (int)&__mh_execute_header;

    /* Set mins/maxs */
    *(float *)((byte *)ent + 0x104) = playerMins[0];
    *(float *)((byte *)ent + 0x108) = playerMins[1];
    *(float *)((byte *)ent + 0x10c) = playerMins[2];

    *(float *)((byte *)ent + 0x110) = playerMaxs[0];
    *(float *)((byte *)ent + 0x114) = playerMaxs[1];
    *(float *)((byte *)ent + 0x118) = playerMaxs[2];

    /* Save session data */
    iFlags = *(int *)(client + 0xa0) & 0x100002;

    memcpy(savedSess, client + 0x26a8, 0x100);
    savedSpawnCount = *(int *)(client + 0x140);

    /* Clear client */
    memset(client, 0, CLIENT_STRIDE);

    /* Restore session */
    memcpy(client + 0x26a8, savedSess, 0x100);

    *(int *)(client + 0x27a8) = -1;
    *(int *)(client + 0x2830) = 0x3ff;

    savedSpawnCount++;
    *(int *)(client + 0x140) = savedSpawnCount;

    *(int *)(client + 0x134) = *(int *)(client + 0x2728);
    *(int *)(client + 0xa0) = iFlags;

    *(int *)(client + 0x2748) = clientNum;
    *(int *)(client + 0xcc) = clientNum;
    *(int *)(client + 0x594) = 0x3ff;

    /* Get user command */
    {
        byte *lev = (byte *)CLIENT_BASE;
        int clientIdx = (int)(client - *(byte **)lev) / 4;
        /* Complex multiplication to compute client index from pointer offset */
        int ucmdIdx;
        /* The original asm does: client - level->clients, then a complex multiply sequence
           to get the client number, which is used for SV_GetUsercmd */
        SV_GetUsercmd(clientNum, client + 0x26c8);
    }

    *(int *)(client + 0xa0) ^= 2;

    /* Copy mins/maxs to client */
    *(float *)(client + 0x56c) = *(float *)((byte *)ent + 0x104);
    *(float *)(client + 0x570) = *(float *)((byte *)ent + 0x108);
    *(float *)(client + 0x574) = *(float *)((byte *)ent + 0x10c);

    *(float *)(client + 0x578) = *(float *)((byte *)ent + 0x110);
    *(float *)(client + 0x57c) = *(float *)((byte *)ent + 0x114);
    *(float *)(client + 0x580) = *(float *)((byte *)ent + 0x118);

    *(int *)(client + 0xf4) = 0x3c;
    *(int *)(client + 0xf8) = 0x42700000;  /* 60.0f */
    *(int *)(client + 0xfc) = 0;
    *(int *)(client + 0x108) = 0;

    G_SetOrigin(ent, spawn_origin);

    /* Copy origin to client */
    *(float *)(client + 0x14) = spawn_origin[0];
    *(float *)(client + 0x18) = spawn_origin[1];
    *(float *)(client + 0x1c) = spawn_origin[2];

    *(int *)(client + 0xc) |= (int)&__mh_execute_header;

    SetClientViewAngle(ent, spawn_angles);

    /* Set spawn time */
    {
        byte *dvar = *(byte **)g_voiceChatTalkingDuration_ptr;
        dvar = *(byte **)dvar;
        int dvarVal = *(int *)(dvar + 8);
        int time = dvarVal * 5 * 5 * 5;  /* dvarVal * 125 */
        byte *lev = (byte *)CLIENT_BASE;
        int serverTime = *(int *)(lev + 0x1ec);
        *(int *)(client + 0x2800) = serverTime + time * 8;
    }

    *(int *)(client + 0x27bc) = *(int *)(client + 0x26cc);

    {
        byte *lev = (byte *)CLIENT_BASE;
        *(int *)(lev + 0x20) = 1;
        *(int *)(client + 0x28a0) = *(int *)(lev + 0x1ec);
        *(int *)(client + 0x26c8) = *(int *)(lev + 0x1ec);
        *(int *)(client + 0) = *(int *)(lev + 0x1ec) - 100;

        ClientEndFrame(ent);
        ClientThink_real(ent, client + 0x26c8);

        *(int *)(lev + 0x20) = 0;

        BG_PlayerStateToEntityState(client, ent, 1, 1);
    }
}

/* line 103 */
void G_GetPlayerViewOrigin(const gentity_t *ent, vec_t *origin)
{
    byte *ps;
    float fBobCycle, xyspeed;
    float vertBob, horzBob;
    vec3_t vRight;
    int bobMax;

    ps = *(byte **)((byte *)ent + 0x158);

    if (*(int *)(ps + 0xa0) & 0x300) {
        /* Turret - use tag position */
        byte *scr_data = *(byte **)g_scr_data_ptr;
        int turretEntNum = *(int *)(ps + 0x594);
        byte *ents = (byte *)g_entities_ptr;
        gentity_t *turretEnt = (gentity_t *)(ents + turretEntNum * GENTITY_STRIDE);

        if (!G_DObjGetWorldTagPos(turretEnt, *(unsigned short *)(scr_data + 0x9a), origin)) {
            Com_Error(1, "G_GetPlayerViewOrigin: couldn't find tag");
        }
        return;
    }

    /* Copy origin from playerState */
    origin[0] = *(float *)(ps + 0x14);
    origin[1] = *(float *)(ps + 0x18);
    origin[2] = *(float *)(ps + 0x1c);

    /* Add viewheight */
    origin[2] += *(float *)(ps + 0xf8);

    /* Bob calculations */
    fBobCycle = BG_GetBobCycle(ps);

    {
        byte *lev = (byte *)CLIENT_BASE;
        int serverTime = *(int *)(lev + 0x1ec);
        xyspeed = BG_GetSpeed(ps, serverTime);
    }

    /* Vertical bob */
    {
        byte *bobMaxDvar = *(byte **)g_bobMax_ptr;
        bobMaxDvar = *(byte **)bobMaxDvar;
        bobMax = *(int *)(bobMaxDvar + 8);
        vertBob = BG_GetVerticalBobFactor(ps, fBobCycle, xyspeed, bobMax);
    }
    origin[2] += vertBob;

    /* Horizontal bob */
    {
        byte *bobMaxDvar = *(byte **)g_bobMax_ptr;
        bobMaxDvar = *(byte **)bobMaxDvar;
        bobMax = *(int *)(bobMaxDvar + 8);
        horzBob = BG_GetHorizontalBobFactor(ps, fBobCycle, xyspeed, bobMax);
    }

    /* Apply horizontal bob via right vector */
    AngleVectors((vec_t *)(ps + 0xe8), NULL, vRight, NULL);

    origin[0] += horzBob * vRight[0];
    origin[1] += horzBob * vRight[1];
    origin[2] += horzBob * vRight[2];

    /* Add lean */
    AddLeanToPosition(origin, *(int *)(ps + 0xec), *(int *)(ps + 0x4c), 20.0f, 16.0f);

    /* Clamp to ground + 8 */
    {
        float minZ = *(float *)(ps + 0x1c) + 8.0f;
        if (minZ > origin[2])
            origin[2] = minZ;
    }
}

/* Helper for CleanName - used by ClientUserinfoChanged */
static void CleanName(const char *in, char *out, int outSize)
{
    int len = 0;
    int colorlessLen = 0;
    int spaces = 0;
    char *dst = out;

    *out = 0;

    while (*in) {
        if (*out == 0 && *in == ' ') {
            in++;
            continue;
        }

        if (*in == '^') {
            if (in[1] == 0)
                break;
            if (ColorIndex((unsigned char)in[1])) {
                if (len > 29)
                    break;
                *dst++ = '^';
                *dst++ = in[1];
                len += 2;
            }
            in += 2;
            continue;
        }

        if (*in == ' ') {
            spaces++;
            if (spaces > 3) {
                in++;
                continue;
            }
        } else {
            spaces = 0;
        }

        if (len > 30)
            break;

        *dst++ = *in;
        colorlessLen++;
        len++;
        in++;
    }

    *dst = 0;

    if (*out == 0 || colorlessLen == 0) {
        I_strncpyz(out, "UnnamedPlayer", outSize);
    }
}

/* line 270 */
void ClientUserinfoChanged(int clientNum)
{
    byte *ents;
    byte *client;
    char userinfo[0x400];
    char oldname[0x400];
    byte *scr_data;

    ents = (byte *)g_entities_ptr;
    client = *(byte **)(ents + clientNum * GENTITY_STRIDE + 0x158);

    SV_GetUserinfo(clientNum, userinfo, 0x400);

    if (!Info_Validate(userinfo)) {
        /* Set a default userinfo */
        userinfo[0] = '\\'; userinfo[1] = 'n'; userinfo[2] = 'a'; userinfo[3] = 'm';
        userinfo[4] = 'e'; userinfo[5] = '\\'; userinfo[6] = 'b'; userinfo[7] = 'a';
        userinfo[8] = 'd'; userinfo[9] = 'i'; userinfo[10] = 'n'; userinfo[11] = 'f';
        userinfo[12] = 'o'; userinfo[13] = 0;
    }

    /* Check local client */
    *(int *)(client + 0x2700) = SV_IsLocalClient(clientNum);

    /* Check handicap */
    {
        int handicap = atoi(Info_ValueForKey(userinfo, "handicap"));
        *(int *)(client + 0x2704) = (handicap != 0) ? 1 : 0;
    }

    /* If client is connected and level has restarted, use different name field */
    if (*(int *)(client + 0x26c4) == 2) {
        byte *lev = (byte *)CLIENT_BASE;
        if (*(int *)(lev + 0x214) != 0) {
            const char *name = Info_ValueForKey(userinfo, "name");
            char *shortName = (char *)(client + 0x2708);

            /* Clean the name for short name */
            {
                int len = 0, colorlessLen = 0, spaces = 0;
                char *dst = shortName;
                const char *src = name;

                *(client + 0x2708) = 0;

                while (*src) {
                    if (*shortName == 0 && *src == ' ') {
                        src++;
                        continue;
                    }
                    if (*src == '^') {
                        if (src[1] == 0) break;
                        if (ColorIndex((unsigned char)src[1])) {
                            if (len > 29) break;
                            *dst++ = '^';
                            *dst++ = src[1];
                            len += 2;
                        }
                        src += 2;
                        continue;
                    }
                    if (*src == ' ') {
                        spaces++;
                        if (spaces > 3) { src++; continue; }
                    } else {
                        spaces = 0;
                    }
                    if (len > 30) break;
                    *dst++ = *src;
                    colorlessLen++;
                    len++;
                    src++;
                }
                *dst = 0;
                if (*shortName == 0 || colorlessLen == 0) {
                    I_strncpyz(shortName, "UnnamedPlayer", 0x1f);
                }
            }

            /* Update score info */
            {
                char *longName = (char *)(client + 0x2784);
                goto do_score_update;
            }
        }
    }

    /* Normal name processing */
    {
        char *longName = (char *)(client + 0x2784);

        /* Copy old name */
        I_strncpyz(oldname, longName, 0x400);

        /* Clean the name */
        {
            const char *name = Info_ValueForKey(userinfo, "name");
            int len = 0, colorlessLen = 0, spaces = 0;
            char *dst = longName;
            const char *src = name;

            *(client + 0x2784) = 0;

            while (*src) {
                if (*longName == 0 && *src == ' ') {
                    src++;
                    continue;
                }
                if (*src == '^') {
                    if (src[1] == 0) break;
                    if (ColorIndex((unsigned char)src[1])) {
                        if (len > 29) break;
                        *dst++ = '^';
                        *dst++ = src[1];
                        len += 2;
                    }
                    src += 2;
                    continue;
                }
                if (*src == ' ') {
                    spaces++;
                    if (spaces > 3) { src++; continue; }
                } else {
                    spaces = 0;
                }
                if (len > 30) break;
                *dst++ = *src;
                colorlessLen++;
                len++;
                src++;
            }
            *dst = 0;
            if (*longName == 0 || colorlessLen == 0) {
                I_strncpyz(longName, "UnnamedPlayer", 0x1f);
            }
        }

        /* Copy to short name */
        I_strncpyz((char *)(client + 0x2708), longName, 0x20);

    do_score_update:
        /* Update score board info */
        {
            byte *g_time_base = *(byte **)&g_time;
            byte *scoreInfo = g_time_base + 0xb3bf0 + clientNum * GENTITY_STRIDE;
            byte *si = scoreInfo + 0xc;

            *(int *)(si + 8) = clientNum;
            I_strncpyz((char *)(si + 0x18 - 0xc), longName, 0x20);
            *(int *)(si + 0x2c) = *(int *)(client + 0x274c);
        }
    }
}

/* line 344 */
char * ClientConnect(int clientNum, int scriptPersId)
{
    byte *ents;
    byte *level;
    byte *client;
    gentity_t *ent;
    byte *ci;
    int pXAnimTree;
    char userinfo[0x400];

    ents = (byte *)g_entities_ptr;
    ent = (gentity_t *)(ents + clientNum * GENTITY_STRIDE);

    level = (byte *)CLIENT_BASE;
    client = level +clientNum * CLIENT_STRIDE;

    /* Clear client */
    memset(client, 0, CLIENT_STRIDE);

    /* Get client info pointer */
    {
        byte *g_time_base = *(byte **)&g_time;
        ci = g_time_base + 0xb3bf0 + clientNum * GENTITY_STRIDE + 0xc;
    }

    /* Save and restore anim tree */
    pXAnimTree = *(int *)(ci + 0x4a4);
    memset(ci, 0, 0x4b8);
    *(int *)(ci + 0x4a4) = pXAnimTree;

    *(int *)(ci - 0xc + 0xc) = 1;  /* ci base valid */
    *(int *)(ci + 4) = 1;

    *(int *)(client + 0x26c4) = 1;  /* CS_CONNECTED */
    *(unsigned short *)(client + 0x26c0) = (unsigned short)scriptPersId;

    *(int *)(client + 0x274c) = 3;  /* TEAM_SPECTATOR */
    *(int *)(client + 0x26a8) = 2;  /* SESS_SPECTATOR */
    *(int *)(client + 0x27a8) = -1;
    *(int *)(client + 0x26ac) = -1;

    G_InitGentity(ent);
    *(byte *)((byte *)ent + 0x166) = 0;
    *(byte **)((byte *)ent + 0x158) = client;
    *(int *)(client + 0x2830) = 0x3ff;
    *(int *)(client + 0x2748) = clientNum;
    *(int *)(client + 0xcc) = clientNum;

    ClientUserinfoChanged(clientNum);

    SV_GetUserinfo(clientNum, userinfo, 0x400);

    /* Check password if not local client */
    if (*(int *)(client + 0x2700) == 0) {
        const char *password = Info_ValueForKey(userinfo, "password");
        byte *passwordDvar = *(byte **)g_password_ptr;
        passwordDvar = *(byte **)passwordDvar;
        const char *serverPassword = (const char *)(*(int *)(passwordDvar + 8));

        if (*serverPassword != 0) {
            if (I_stricmp(serverPassword, "")) {
                if (strcmp(serverPassword, password)) {
                    G_FreeEntity(ent);
                    return "GAME_INVALIDPASSWORD";
                }
            }
        }
    }

    /* DBG: count free script variables */
    {
        extern unsigned char scrVarGlob[];
        extern void *imp_scrVarPub;
        extern unsigned char g_scr_data[];
        int freeCount = 0;
        unsigned short idx = *(unsigned short *)(scrVarGlob + 4);
        while (idx != 0 && freeCount < 70000) {
            freeCount++;
            idx = *(unsigned short *)(scrVarGlob + (unsigned int)idx * 16 + 4);
        }
        extern unsigned char scrVmPub[];
        unsigned int codeBase = *(unsigned int *)((char *)imp_scrVarPub + 0x48);
        unsigned int handle = *(unsigned int *)(g_scr_data + 16);
        unsigned int startGameTypeHandle = *(unsigned int *)(g_scr_data + 0x10b4);
        unsigned int vmTop = *(unsigned int *)(scrVmPub + 16);
        unsigned int vmDepth = *(unsigned int *)(scrVmPub + 8);
        unsigned int vmInUse = *(unsigned int *)(scrVmPub + 24);
        Com_Printf("DBG ClientConnect: %d free vars, codeBase=0x%x, handle=%u, startGT=%u\n",
            freeCount, codeBase, handle, startGameTypeHandle);
        Com_Printf("DBG ClientConnect: vmTop=0x%x, vmDepth=%d, vmInUse=%d\n",
            vmTop, vmDepth, vmInUse);
    }
    Scr_PlayerConnect(ent);
    CalculateRanks();

    return NULL;
}
