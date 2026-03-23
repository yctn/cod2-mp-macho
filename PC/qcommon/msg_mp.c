/* ASM dump from: msg_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/msg_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern NetField objectiveFields[6]; /* 0x0 */
extern NetField hudElemFields[32]; /* 0x0 */
extern int msg_hData[256]; /* 0x0 */
static char string_00f0e860[1024]; /* string */
static char string_00f0ec60[8192]; /* string */
static char string_00f10c60[1024]; /* string */
static struct huffman_t msgHuff; /* msgHuff */
static qboolean msgInit; /* msgInit */
__attribute__((used)) unsigned int kbitmask[40] = {
    0x00000000, 0x00000001, 0x00000003, 0x00000007,
    0x0000000F, 0x0000001F, 0x0000003F, 0x0000007F,
    0x000000FF, 0x000001FF, 0x000003FF, 0x000007FF,
    0x00000FFF, 0x00001FFF, 0x00003FFF, 0x00007FFF,
    0x0000FFFF, 0x0001FFFF, 0x0003FFFF, 0x0007FFFF,
    0x000FFFFF, 0x001FFFFF, 0x003FFFFF, 0x007FFFFF,
    0x00FFFFFF, 0x01FFFFFF, 0x03FFFFFF, 0x07FFFFFF,
    0x0FFFFFFF, 0x1FFFFFFF, 0x3FFFFFFF, 0x7FFFFFFF,
    0xFFFFFFFF,
    0, 0, 0, 0, 0, 0, 0,
}; /* 0x312c00 */
extern void Com_Printf(const char *fmt, ...);
extern int I_CleanChar(int ch);

#define PSF(x) #x, __builtin_offsetof(playerState_t, x)
#define CSF(x) #x, __builtin_offsetof(clientState_t, x)
#define AEF(x) #x, __builtin_offsetof(archivedEntity_t, x)
#define ESF(x) #x, __builtin_offsetof(entityState_t, x)

static const NetField playerStateFields[105] = {
    { PSF(commandTime), 32 }, { PSF(origin[1]), 0 }, { PSF(origin[0]), 0 }, { PSF(bobCycle), 8 },
    { PSF(viewangles[1]), -100 }, { PSF(origin[2]), 0 }, { PSF(velocity[1]), 0 }, { PSF(velocity[0]), 0 },
    { PSF(viewangles[0]), -100 }, { PSF(movementDir), -8 }, { PSF(velocity[2]), 0 }, { PSF(eventSequence), 8 },
    { PSF(legsAnim), 10 }, { PSF(aimSpreadScale), 0 }, { PSF(weaponTime), -16 }, { PSF(pm_flags), 27 },
    { PSF(events[0]), 8 }, { PSF(events[1]), 8 }, { PSF(events[2]), 8 }, { PSF(events[3]), 8 },
    { PSF(weapAnim), 10 }, { PSF(viewHeightCurrent), 0 }, { PSF(torsoTimer), 16 }, { PSF(torsoAnim), 10 },
    { PSF(eFlags), 24 }, { PSF(fWeaponPosFrac), 0 }, { PSF(holdBreathScale), 0 }, { PSF(weaponstate), 5 },
    { PSF(viewHeightTarget), -8 }, { PSF(weaponDelay), -16 }, { PSF(legsTimer), 16 }, { PSF(viewHeightLerpTarget), -8 },
    { PSF(groundEntityNum), 10 }, { PSF(pm_time), -16 }, { PSF(eventParms[3]), 8 }, { PSF(eventParms[1]), 8 },
    { PSF(eventParms[0]), 8 }, { PSF(eventParms[2]), 8 }, { PSF(weapon), 7 }, { PSF(weapons[0]), 32 },
    { PSF(viewHeightLerpDown), 1 }, { PSF(weaponslots[0]), 32 }, { PSF(delta_angles[0]), 16 }, { PSF(delta_angles[1]), 16 },
    { PSF(cursorHintString), -8 }, { PSF(offHandIndex), 7 }, { PSF(clientNum), 8 }, { PSF(viewlocked_entNum), 16 },
    { PSF(viewmodelIndex), 8 }, { PSF(viewHeightLerpTime), 32 }, { PSF(speed), 16 }, { PSF(mins[1]), 0 },
    { PSF(mins[0]), 0 }, { PSF(maxs[2]), 0 }, { PSF(maxs[1]), 0 }, { PSF(maxs[0]), 0 },
    { PSF(gravity), 16 }, { PSF(damageTimer), 16 }, { PSF(cursorHint), 8 }, { PSF(mantleState.flags), 4 },
    { PSF(flinchYaw), 16 }, { PSF(fWaistPitch), 0 }, { PSF(mantleState.timer), 32 }, { PSF(fTorsoPitch), 0 },
    { PSF(proneTorsoPitch), 0 }, { PSF(holdBreathTimer), 16 }, { PSF(jumpTime), 32 }, { PSF(viewangles[2]), -100 },
    { PSF(foliageSoundTime), 32 }, { PSF(weapons[1]), 32 }, { PSF(damageEvent), 8 }, { PSF(damageDuration), 16 },
    { PSF(damageYaw), 8 }, { PSF(proneDirection), 0 }, { PSF(proneDirectionPitch), 0 }, { PSF(mantleState.yaw), 0 },
    { PSF(mantleState.transIndex), 4 }, { PSF(fTorsoHeight), 0 }, { PSF(damagePitch), 8 }, { PSF(jumpOriginZ), 0 },
    { PSF(pm_type), 8 }, { PSF(viewlocked), 8 }, { PSF(weaponrechamber[0]), 32 }, { PSF(vLadderVec[0]), 0 },
    { PSF(weaponslots[4]), 32 }, { PSF(weaponRestrictKickTime), -16 }, { PSF(vLadderVec[1]), 0 }, { PSF(viewAngleClampRange[1]), 0 },
    { PSF(viewAngleClampRange[0]), 0 }, { PSF(viewAngleClampBase[1]), 0 }, { PSF(weaponrechamber[1]), 32 }, { PSF(leanf), 0 },
    { PSF(damageCount), 7 }, { PSF(grenadeTimeLeft), -16 }, { PSF(deltaTime), 32 }, { PSF(shellshockTime), 32 },
    { PSF(shellshockIndex), 4 }, { PSF(shellshockDuration), 16 }, { PSF(vLadderVec[2]), 0 }, { PSF(delta_angles[2]), 16 },
    { PSF(viewHeightLerpPosAdj), 0 }, { PSF(mins[2]), 0 }, { PSF(viewAngleClampBase[0]), 0 }, { PSF(adsDelayTime), 32 },
    { PSF(iCompassFriendInfo), 32 },
};

static const NetField clientStateFields[22] = {
    { CSF(team), 2 }, { CSF(name[0]), 32 }, { CSF(name[4]), 32 }, { CSF(modelindex), 8 },
    { CSF(attachModelIndex[1]), 8 }, { CSF(attachModelIndex[0]), 8 }, { CSF(name[8]), 32 }, { CSF(name[12]), 32 },
    { CSF(name[16]), 32 }, { CSF(name[20]), 32 }, { CSF(name[24]), 32 }, { CSF(name[28]), 32 },
    { CSF(attachTagIndex[5]), 5 }, { CSF(attachTagIndex[0]), 5 }, { CSF(attachTagIndex[1]), 5 }, { CSF(attachTagIndex[2]), 5 },
    { CSF(attachTagIndex[3]), 5 }, { CSF(attachTagIndex[4]), 5 }, { CSF(attachModelIndex[2]), 8 }, { CSF(attachModelIndex[3]), 8 },
    { CSF(attachModelIndex[4]), 8 }, { CSF(attachModelIndex[5]), 8 },
};

static const NetField archivedEntityFields[68] = {
    { AEF(r.absmin[1]), 0 }, { AEF(r.absmax[1]), 0 }, { AEF(r.absmin[0]), 0 }, { AEF(r.absmax[0]), 0 },
    { AEF(r.absmin[2]), 0 }, { AEF(r.absmax[2]), 0 }, { AEF(s.pos.trBase[1]), 0 }, { AEF(s.pos.trBase[0]), 0 },
    { AEF(s.eType), 8 }, { AEF(s.eFlags), 24 }, { AEF(s.pos.trBase[2]), 0 }, { AEF(r.svFlags), 32 },
    { AEF(s.groundEntityNum), 10 }, { AEF(s.apos.trBase[1]), 0 }, { AEF(s.clientNum), 8 }, { AEF(s.apos.trBase[0]), 0 },
    { AEF(s.index), 10 }, { AEF(s.apos.trBase[2]), 0 }, { AEF(s.eventSequence), 8 }, { AEF(s.events[0]), 8 },
    { AEF(s.legsAnim), 10 }, { AEF(s.events[1]), 8 }, { AEF(s.events[2]), 8 }, { AEF(s.events[3]), 8 },
    { AEF(s.weapon), 7 }, { AEF(s.pos.trType), 8 }, { AEF(s.pos.trTime), 32 }, { AEF(s.apos.trType), 8 },
    { AEF(s.solid), 24 }, { AEF(s.pos.trDuration), 32 }, { AEF(s.eventParms[0]), 8 }, { AEF(s.torsoAnim), 10 },
    { AEF(s.pos.trDelta[0]), 0 }, { AEF(s.pos.trDelta[1]), 0 }, { AEF(s.angles2[1]), 0 }, { AEF(s.angles2[0]), 0 },
    { AEF(s.animMovetype), 4 }, { AEF(s.pos.trDelta[2]), 0 }, { AEF(s.otherEntityNum), 10 }, { AEF(s.eventParms[1]), 8 },
    { AEF(s.surfType), 8 }, { AEF(s.eventParm), 8 }, { AEF(s.eventParms[2]), 8 }, { AEF(s.scale), 8 },
    { AEF(s.eventParms[3]), 8 }, { AEF(s.fTorsoHeight), 0 }, { AEF(s.fWaistPitch), 0 }, { AEF(s.fTorsoPitch), 0 },
    { AEF(s.apos.trTime), 32 }, { AEF(s.apos.trDelta[0]), 0 }, { AEF(s.apos.trDelta[2]), 0 }, { AEF(r.clientMask[0]), 32 },
    { AEF(r.clientMask[1]), 32 }, { AEF(s.leanf), 0 }, { AEF(s.apos.trDelta[1]), 0 }, { AEF(s.loopSound), 8 },
    { AEF(s.attackerEntityNum), 10 }, { AEF(s.iHeadIcon), 4 }, { AEF(s.iHeadIconTeam), 2 }, { AEF(s.apos.trDuration), 32 },
    { AEF(s.time), 32 }, { AEF(s.time2), 32 }, { AEF(s.origin2[0]), 0 }, { AEF(s.origin2[1]), 0 },
    { AEF(s.origin2[2]), 0 }, { AEF(s.angles2[2]), 0 }, { AEF(s.constantLight), 32 }, { AEF(s.dmgFlags), 32 },
};

static const NetField entityStateFields[59] = {
    { ESF(pos.trTime), 32 }, { ESF(pos.trBase[1]), 0 }, { ESF(pos.trBase[0]), 0 }, { ESF(pos.trDelta[0]), 0 },
    { ESF(pos.trDelta[1]), 0 }, { ESF(angles2[1]), 0 }, { ESF(apos.trBase[1]), -100 }, { ESF(pos.trDelta[2]), 0 },
    { ESF(pos.trBase[2]), 0 }, { ESF(apos.trBase[0]), -100 }, { ESF(eventSequence), 8 }, { ESF(legsAnim), 10 },
    { ESF(eType), 8 }, { ESF(eFlags), 24 }, { ESF(otherEntityNum), 10 }, { ESF(surfType), 8 },
    { ESF(eventParm), 8 }, { ESF(scale), 8 }, { ESF(clientNum), 8 }, { ESF(torsoAnim), 10 },
    { ESF(groundEntityNum), 10 }, { ESF(events[0]), 8 }, { ESF(events[1]), 8 }, { ESF(events[2]), 8 },
    { ESF(angles2[0]), 0 }, { ESF(events[3]), 8 }, { ESF(apos.trBase[2]), -100 }, { ESF(pos.trType), 8 },
    { ESF(fWaistPitch), 0 }, { ESF(fTorsoPitch), 0 }, { ESF(apos.trTime), 32 }, { ESF(solid), 24 },
    { ESF(apos.trDelta[0]), 0 }, { ESF(apos.trType), 8 }, { ESF(animMovetype), 4 }, { ESF(fTorsoHeight), 0 },
    { ESF(apos.trDelta[2]), 0 }, { ESF(weapon), 7 }, { ESF(index), 10 }, { ESF(apos.trDelta[1]), 0 },
    { ESF(eventParms[0]), 8 }, { ESF(eventParms[1]), 8 }, { ESF(eventParms[2]), 8 }, { ESF(eventParms[3]), 8 },
    { ESF(iHeadIcon), 4 }, { ESF(pos.trDuration), 32 }, { ESF(iHeadIconTeam), 2 }, { ESF(time), 32 },
    { ESF(leanf), 0 }, { ESF(attackerEntityNum), 10 }, { ESF(time2), 32 }, { ESF(loopSound), 8 },
    { ESF(origin2[2]), 0 }, { ESF(origin2[0]), 0 }, { ESF(origin2[1]), 0 }, { ESF(angles2[2]), 0 },
    { ESF(constantLight), 32 }, { ESF(apos.trDuration), 32 }, { ESF(dmgFlags), 32 },
};

void MSG_BeginReading(msg_t *msg);
void MSG_WriteBits(msg_t *msg, int value, int bits);
void MSG_WriteBit0(msg_t *msg);
void MSG_WriteBit1(msg_t *msg);
int MSG_ReadBits(msg_t *msg, int bits);
int MSG_ReadBit(msg_t *msg);
int MSG_WriteBitsCompress(byte *from, byte *to, int size);
int MSG_ReadBitsCompress(byte *from, byte *to, int size);
void MSG_WriteByte(msg_t *msg, int c);
void MSG_WriteData(msg_t *buf, const void *data, int length);
int MSG_ReadByte(msg_t *msg);
int MSG_ReadShort(msg_t *msg);
int MSG_ReadLong(msg_t *msg);
void MSG_ReadData(msg_t *msg, void *data, int len);
void MSG_WriteReliableCommandToBuffer(const char *pszCommand, char *pszBuffer, int iBufferSize);
void MSG_SetDefaultUserCmd(playerState_t *ps, usercmd_t *cmd);
char * MSG_ReadString(msg_t *msg);
char * MSG_ReadBigString(msg_t *msg);
char * MSG_ReadStringLine(msg_t *msg);
void MSG_WriteShort(msg_t *msg, int c);
void MSG_WriteLong(msg_t *msg, int c);
void MSG_Init(msg_t *buf, byte *data, int length);
void MSG_WriteString(msg_t *sb, const char *s);
void MSG_WriteBigString(msg_t *sb, const char *s, msg_t *msg, int key, int oldV, int bits);
void MSG_ReadDeltaField(msg_t *msg, byte *from, byte *to, const NetField *field, qboolean print);
static qboolean MSG_ReadDeltaStruct(byte *from, byte *to, unsigned int number, int numFields, int indexBits, const NetField *stateFields);
qboolean MSG_ReadDeltaClient(msg_t *msg, clientState_t *from, clientState_t *to, int number);
qboolean MSG_ReadDeltaArchivedEntity(msg_t *msg, archivedEntity_t *from, archivedEntity_t *to, int number);
qboolean MSG_ReadDeltaEntity(msg_t *msg, entityState_t *from, entityState_t *to, int number);
static void MSG_ReadDeltaHudElems(hudelem_t *from, hudelem_t *to, int count);
void MSG_ReadDeltaPlayerstate(msg_t *msg, playerState_t *from, playerState_t *to);
void MSG_ReadDeltaUsercmdKey(msg_t *msg, int key, usercmd_t *from, usercmd_t *to);
void MSG_WriteDeltaUsercmdKey(msg_t *msg, int key, usercmd_t *from, usercmd_t *to);
static void MSG_WriteDeltaField(const NetField *field);
static void MSG_WriteDeltaHudElems(msg_t *msg, hudelem_t *from, hudelem_t *to, int count);
static void MSG_WriteDeltaStruct(byte *from, byte *to, qboolean force, int numFields, int indexBits, const NetField *stateFields, qboolean bChangeBit);
void MSG_WriteDeltaClient(msg_t *msg, clientState_s *from, clientState_s *to, qboolean force);
void MSG_WriteDeltaArchivedEntity(msg_t *msg, archivedEntity_t *from, archivedEntity_t *to, qboolean force);
void MSG_WriteDeltaEntity(msg_t *msg, entityState_s *from, entityState_s *to, qboolean force);
void MSG_WriteDeltaPlayerstate(msg_t *msg, playerState_s *from, playerState_s *to);

/* line 781 */
void MSG_BeginReading(msg_t *msg)
{
    msg->overflowed = 0;
    msg->readcount = 0;
    msg->bit = 0;
}

/* line 804 */
void MSG_WriteBits(msg_t *msg, int value, int bits)
{
    int i, bit;

    if (msg->maxsize - msg->cursize <= 3) {
        msg->overflowed = 1;
        return;
    }

    for (i = 0; i < bits; i++) {
        bit = msg->bit & 7;
        if (bit == 0) {
            msg->bit = msg->cursize * 8;
            msg->data[msg->cursize] = 0;
            msg->cursize++;
        }
        if (value & 1)
            msg->data[msg->bit >> 3] |= (1 << bit);
        msg->bit++;
        value >>= 1;
    }
}

/* line 835 */
void MSG_WriteBit0(msg_t *msg)
{
    if (msg->cursize >= msg->maxsize)
    {
        msg->overflowed = 1;
        return;
    }
    if (!(msg->bit & 7))
    {
        msg->bit = msg->cursize * 8;
        msg->data[msg->cursize] = 0;
        msg->cursize++;
    }
    msg->bit++;
}

/* line 856 */
void MSG_WriteBit1(msg_t *msg)
{
    int bit;

    if (msg->cursize >= msg->maxsize) {
        msg->overflowed = 1;
        return;
    }

    bit = msg->bit & 7;
    if (bit == 0) {
        msg->bit = msg->cursize * 8;
        msg->data[msg->cursize] = 0;
        msg->cursize++;
    }
    msg->data[msg->bit >> 3] |= (1 << bit);
    msg->bit++;
}

/* line 879 */
int MSG_ReadBits(msg_t *msg, int bits)
{
    int value, i, bit;

    if (bits <= 0)
        return 0;

    value = 0;
    for (i = 0; i < bits; i++) {
        bit = msg->bit & 7;
        if (bit == 0) {
            if (msg->readcount >= msg->cursize) {
                msg->overflowed = 1;
                return -1;
            }
            msg->bit = msg->readcount * 8;
            msg->readcount++;
        }
        value |= ((msg->data[msg->bit >> 3] >> (msg->bit & 7)) & 1) << i;
        msg->bit++;
    }
    return value;
}

/* line 910 */
int MSG_ReadBit(msg_t *msg)
{
    int bit, value;

    bit = msg->bit & 7;
    if (bit == 0) {
        if (msg->readcount >= msg->cursize) {
            msg->overflowed = 1;
            return -1;
        }
        msg->bit = msg->readcount * 8;
        msg->readcount++;
    }
    value = (msg->data[msg->bit >> 3] >> (msg->bit & 7)) & 1;
    msg->bit++;
    return value;
}

/* line 942 */
extern void Huff_offsetTransmit(void *huff, int ch, byte *fout, int *offset);
extern void Huff_offsetReceive(void *node, int *ch, byte *fin, int *offset);
int MSG_WriteBitsCompress(byte *from, byte *to, int size)
{
    int bit = 0;
    int i;

    for (i = 0; i < size; i++)
        Huff_offsetTransmit(&msgHuff, from[i], to, &bit);

    return (bit + 7) >> 3;
}

/* line 959 */
int MSG_ReadBitsCompress(byte *from, byte *to, int size)
{
    int bits = size * 8;
    int bit = 0;
    int get;
    byte *data = to;

    if (bits <= 0)
        return 0;

    do {
        Huff_offsetReceive(*(void **)((byte *)&msgHuff + 28708), &get, from, &bit);
        *data++ = (byte)get;
    } while (bits > bit);

    return (int)(data - to);
}

/* line 990 */
void MSG_WriteByte(msg_t *msg, int c)
{
    if (msg->cursize >= msg->maxsize)
    {
        msg->overflowed = 1;
        return;
    }
    msg->data[msg->cursize] = (byte)c;
    msg->cursize++;
}

/* line 1003 */
void MSG_WriteData(msg_t *buf, const void *data, int length)
{
    int newsize = buf->cursize + length;
    if (newsize > buf->maxsize) {
        buf->overflowed = 1;
        return;
    }
    memcpy(buf->data + buf->cursize, data, length);
    buf->cursize = newsize;
}

/* line 1133 */
int MSG_ReadByte(msg_t *msg)
{
    int readcount = msg->readcount;

    if (readcount >= msg->cursize) {
        msg->overflowed = 1;
        return -1;
    }

    msg->readcount = readcount + 1;
    return (unsigned char)msg->data[readcount];
}

/* line 1148 */
int MSG_ReadShort(msg_t *msg)
{
    int readcount = msg->readcount;
    int next = readcount + 2;
    if (next > msg->cursize)
    {
        msg->overflowed = 1;
        return -1;
    }
    msg->readcount = next;
    return *(short *)(msg->data + readcount);
}

/* line 1165 */
int MSG_ReadLong(msg_t *msg)
{
    int readcount = msg->readcount;
    int next = readcount + 4;
    if (next > msg->cursize)
    {
        msg->overflowed = 1;
        return -1;
    }
    msg->readcount = next;
    return *(int *)(msg->data + readcount);
}

/* line 1289 */
void MSG_ReadData(msg_t *msg, void *data, int len)
{
    int newcount = msg->readcount + len;
    if (newcount > msg->cursize) {
        msg->overflowed = 1;
        memset(data, 0xff, len);
        return;
    }
    memcpy(data, msg->data + msg->readcount, len);
    msg->readcount = newcount;
}

/* line 1424 */
void MSG_WriteReliableCommandToBuffer(const char *pszCommand, char *pszBuffer, int iBufferSize) {
    int len = strlen(pszCommand);
    int i;

    if (len >= iBufferSize) {
        Com_Printf((const char *)str_002ad8b0, len, iBufferSize, pszCommand);
    }

    if (len == 0) {
        Com_Printf((const char *)str_002ad8fc);
    }

    if (iBufferSize <= 0) {
        pszBuffer[iBufferSize - 1] = '\0';
        return;
    }

    for (i = 0; i < iBufferSize; i++) {
        char ch = pszCommand[i];
        if (!ch) {
            pszBuffer[i] = '\0';
            return;
        }
        ch = (char)I_CleanChar((int)(signed char)ch);
        if (ch == '%')
            ch = '.';
        pszBuffer[i] = ch;
    }

    pszBuffer[iBufferSize - 1] = '\0';
}
