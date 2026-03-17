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
extern unsigned int kbitmask[33]; /* kbitmask */
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
    *(int *)msg = 0;
    *(int *)((byte *)msg + 0x10) = 0;
    *(int *)((byte *)msg + 0x14) = 0;
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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void MSG_WriteReliableCommandToBuffer(const char *pszCommand, char *pszBuffer, int iBufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1424 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pszCommand */
        /* { scope 1 */
        "cld\n" /* line 1431 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* pszCommand, ch */
        "repne scasb %es:(%edi), %al\n" /* ch */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* ch */
        "cmpl 0x10(%ebp), %edi\n" /* line 1432 | iBufferSize, ch */
        "jge .Lf171fc8_0017202e\n"
        ".Lf171fc8_00171fea:\n"
        "testl %edi, %edi\n" /* line 1435 | ch */
        "je .Lf171fc8_00172020\n"
        ".Lf171fc8_00171fee:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1440 | iBufferSize */
        "testl %ecx, %ecx\n"
        "jg .Lf171fc8_00172008\n"
        ".Lf171fc8_00171ff5:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1451 | pszBuffer */
        "movl 0x10(%ebp), %edx\n" /* iBufferSize */
        "movb $0, -1(%eax, %edx)\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1452 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf171fc8_00172008:\n"
        "movzbl (%esi), %eax\n" /* line 1440 | pszCommand */
        "testb %al, %al\n"
        "jne .Lf171fc8_0017204b\n"
        "xorl %eax, %eax\n"
        ".Lf171fc8_00172011:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1449 | pszBuffer */
        "movb $0, (%edx, %eax)\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1452 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf171fc8_00172020:\n"
        "movl $str_002ad8fc, (%esp)\n" /* line 1436 */
        "calll Com_Printf\n"
        "jmp .Lf171fc8_00171fee\n"
        ".Lf171fc8_0017202e:\n"
        "movl %esi, 0xc(%esp)\n" /* line 1433 | pszCommand */
        "movl 0x10(%ebp), %eax\n" /* iBufferSize */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* ch */
        "movl $str_002ad8b0, (%esp)\n" /* "WARNING: Reliable command is too long (%i/%i) and will be tr" */
        "calll Com_Printf\n"
        "jmp .Lf171fc8_00171fea\n"
        ".Lf171fc8_0017204b:\n"
        "movl 0xc(%ebp), %edi\n" /* line 1440 | pszBuffer, ch */
        "xorl %ebx, %ebx\n" /* i */
        ".Lf171fc8_00172050:\n"
        "movsbl %al, %eax\n" /* line 1442 */
        "movl %eax, (%esp)\n"
        "calll I_CleanChar\n"
        "movl $0x2e, %edx\n" /* line 1444 */
        "cmpb $0x25, %al\n"
        "cmovnel %eax, %edx\n"
        "movb %dl, (%edi)\n" /* ch */
        "addl $1, %ebx\n" /* line 1440 | i */
        "addl $1, %edi\n" /* ch */
        "cmpl %ebx, 0x10(%ebp)\n" /* i, iBufferSize */
        "je .Lf171fc8_00171ff5\n"
        "movzbl (%esi, %ebx), %eax\n" /* pszCommand */
        "testb %al, %al\n"
        "jne .Lf171fc8_00172050\n"
        "movl %ebx, %eax\n" /* i */
        "jmp .Lf171fc8_00172011\n"
    );
}

/* line 1483 */
__attribute__((naked))
void MSG_SetDefaultUserCmd(playerState_t *ps, usercmd_t *cmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1483 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* ps */
        "movl 0xc(%ebp), %ebx\n" /* cmd */
        "cld\n" /* line 1487 */
        "movl $7, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* cmd */
        "rep stosl %eax, %es:(%edi)\n"
        "movl 0xd4(%esi), %eax\n" /* line 1489 | ps */
        "movb %al, 8(%ebx)\n" /* cmd */
        "movl 0xd0(%esi), %eax\n" /* line 1490 | ps */
        "movb %al, 9(%ebx)\n" /* cmd */
        "movl %esi, %edx\n" /* ps */
        "movl %ebx, %ecx\n" /* cmd */
        "movl $2, %edi\n"
        "movss lit4_002ed644, %xmm1\n" /* 182.04444885253906f */
        ".Lf17207e_001720b9:\n"
        "movss 0xe8(%edx), %xmm0\n" /* line 1494 */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "subw 0x54(%edx), %ax\n"
        "movzwl %ax, %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "subl $1, %edi\n" /* line 1493 */
        "jne .Lf17207e_001720b9\n"
        "testb $0x80, 0xe(%esi)\n" /* line 1496 | ps */
        "je .Lf17207e_0017211c\n"
        "movl 0xa0(%esi), %eax\n" /* line 1499 | ps */
        "testb $8, %al\n"
        "je .Lf17207e_00172121\n"
        "orl $0x100, 4(%ebx)\n" /* line 1500 | cmd */
        ".Lf17207e_001720f5:\n"
        "movss 0x4c(%esi), %xmm0\n" /* line 1504 | ps */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf17207e_0017213a\n"
        ".Lf17207e_00172103:\n"
        "orl $0x80, 4(%ebx)\n" /* line 1505 | cmd */
        ".Lf17207e_0017210a:\n"
        "ucomiss 0xdc(%esi), %xmm1\n" /* line 1509 | ps */
        "jp .Lf17207e_00172115\n"
        "je .Lf17207e_0017211c\n"
        ".Lf17207e_00172115:\n"
        "orl $__mh_execute_header, 4(%ebx)\n" /* line 1510 | cmd */
        ".Lf17207e_0017211c:\n"
        "popl %ebx\n" /* line 1511 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17207e_00172121:\n"
        "testb $4, %al\n" /* line 1501 */
        "je .Lf17207e_001720f5\n"
        "orl $0x200, 4(%ebx)\n" /* line 1502 | cmd */
        "movss 0x4c(%esi), %xmm0\n" /* line 1504 | ps */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf17207e_00172103\n"
        ".Lf17207e_0017213a:\n"
        "ucomiss %xmm0, %xmm1\n" /* line 1506 */
        "jbe .Lf17207e_0017210a\n"
        "orl $0x40, 4(%ebx)\n" /* line 1507 | cmd */
        "jmp .Lf17207e_0017210a\n"
    );
}

/* line 1199 */
__attribute__((naked))
char * MSG_ReadString(msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1199 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* msg */
        "xorl %edi, %edi\n"
        "jmp .Lf172146_00172177\n"
        /* { scope 1 */
        ".Lf172146_00172156:\n"
        "movl 4(%esi), %eax\n" /* line 1139 */
        "movzbl (%eax, %edx), %ebx\n"
        "leal 1(%edx), %eax\n" /* line 1140 */
        "movl %eax, 0x10(%esi)\n"
        "cmpl $-1, %ebx\n" /* line 1208 | c */
        "je .Lf172146_00172185\n"
        "cmpl $0x3ff, %edi\n" /* line 1210 | l */
        "jbe .Lf172146_0017218f\n"
        ".Lf172146_00172170:\n"
        "testl %ebx, %ebx\n" /* line 1212 | c */
        "je .Lf172146_001721a4\n"
        ".Lf172146_00172174:\n"
        "addl $1, %edi\n" /* line 1214 | l */
        ".Lf172146_00172177:\n"
        "movl 0x10(%esi), %edx\n" /* line 1137 */
        "cmpl 0xc(%esi), %edx\n"
        "jl .Lf172146_00172156\n"
        "movl $1, (%esi)\n" /* line 1143 */
        ".Lf172146_00172185:\n"
        "xorl %ebx, %ebx\n"
        "cmpl $0x3ff, %edi\n" /* line 1210 | l */
        "ja .Lf172146_00172170\n"
        ".Lf172146_0017218f:\n"
        "movsbl %bl, %eax\n" /* line 1211 | c */
        "movl %eax, (%esp)\n"
        "calll I_CleanChar\n"
        "movb %al, string(%edi)\n" /* l */
        "testl %ebx, %ebx\n" /* line 1212 | c */
        "jne .Lf172146_00172174\n"
        ".Lf172146_001721a4:\n"
        "movb $0, string+1023\n" /* line 1217 */
        /* } scope */
        "movl $string, %eax\n" /* line 1220 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1223 */
__attribute__((naked))
char * MSG_ReadBigString(msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1223 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* msg */
        "xorl %edi, %edi\n"
        "jmp .Lf1721b8_001721f1\n"
        /* { scope 1 */
        ".Lf1721b8_001721c8:\n"
        "movl 4(%esi), %eax\n" /* line 1139 */
        "movzbl (%eax, %ecx), %edx\n"
        "movzbl %dl, %ebx\n"
        "leal 1(%ecx), %eax\n" /* line 1140 */
        "movl %eax, 0x10(%esi)\n"
        "cmpb $0x25, %dl\n" /* line 1234 */
        "je .Lf1721b8_00172232\n"
        "cmpl $-1, %ebx\n" /* line 1236 | c */
        "je .Lf1721b8_001721ff\n"
        ".Lf1721b8_001721e2:\n"
        "cmpl $0x1fff, %edi\n" /* line 1239 | l */
        "jbe .Lf1721b8_00172209\n"
        ".Lf1721b8_001721ea:\n"
        "testl %ebx, %ebx\n" /* line 1241 | c */
        "je .Lf1721b8_0017221e\n"
        ".Lf1721b8_001721ee:\n"
        "addl $1, %edi\n" /* line 1244 | l */
        ".Lf1721b8_001721f1:\n"
        "movl 0x10(%esi), %ecx\n" /* line 1137 */
        "cmpl 0xc(%esi), %ecx\n"
        "jl .Lf1721b8_001721c8\n"
        "movl $1, (%esi)\n" /* line 1143 */
        ".Lf1721b8_001721ff:\n"
        "xorl %ebx, %ebx\n" /* line 1236 | c */
        "cmpl $0x1fff, %edi\n" /* line 1239 | l */
        "ja .Lf1721b8_001721ea\n"
        ".Lf1721b8_00172209:\n"
        "movsbl %bl, %eax\n" /* line 1240 | c */
        "movl %eax, (%esp)\n"
        "calll I_CleanChar\n"
        "movb %al, string(%edi)\n" /* l */
        "testl %ebx, %ebx\n" /* line 1241 | c */
        "jne .Lf1721b8_001721ee\n"
        ".Lf1721b8_0017221e:\n"
        "movb $0, string+8191\n" /* line 1247 */
        /* } scope */
        "movl $string, %eax\n" /* line 1250 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1721b8_00172232:\n"
        "movl $0x2e, %ebx\n" /* line 1234 | c */
        "jmp .Lf1721b8_001721e2\n"
    );
}

/* line 1253 */
__attribute__((naked))
char * MSG_ReadStringLine(msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1253 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* msg */
        "xorl %edi, %edi\n"
        /* { scope 1 */
        "movl 0x10(%esi), %edx\n" /* line 1137 */
        "cmpl 0xc(%esi), %edx\n"
        "jge .Lf17223a_00172283\n"
        ".Lf17223a_00172250:\n"
        "movl 4(%esi), %eax\n" /* line 1139 */
        "movzbl (%eax, %edx), %ecx\n"
        "movzbl %cl, %ebx\n"
        "leal 1(%edx), %eax\n" /* line 1140 */
        "movl %eax, 0x10(%esi)\n"
        "cmpb $0x25, %cl\n" /* line 1264 */
        "je .Lf17223a_001722c1\n"
        "cmpb $0xa, %cl\n" /* line 1266 */
        "jne .Lf17223a_0017228b\n"
        ".Lf17223a_0017226a:\n"
        "xorl %ebx, %ebx\n" /* c */
        ".Lf17223a_0017226c:\n"
        "cmpl $0x3ff, %edi\n" /* line 1269 | l */
        "jbe .Lf17223a_00172298\n"
        ".Lf17223a_00172274:\n"
        "testl %ebx, %ebx\n" /* line 1271 | c */
        "je .Lf17223a_001722ad\n"
        ".Lf17223a_00172278:\n"
        "addl $1, %edi\n" /* line 1274 | l */
        "movl 0x10(%esi), %edx\n" /* line 1137 */
        "cmpl 0xc(%esi), %edx\n"
        "jl .Lf17223a_00172250\n"
        ".Lf17223a_00172283:\n"
        "movl $1, (%esi)\n" /* line 1143 */
        "jmp .Lf17223a_0017226a\n"
        ".Lf17223a_0017228b:\n"
        "cmpl $-1, %ebx\n" /* line 1266 | c */
        "je .Lf17223a_0017226a\n"
        "cmpl $0x3ff, %edi\n" /* line 1269 | l */
        "ja .Lf17223a_00172274\n"
        ".Lf17223a_00172298:\n"
        "movsbl %bl, %eax\n" /* line 1270 | c */
        "movl %eax, (%esp)\n"
        "calll I_CleanChar\n"
        "movb %al, string(%edi)\n" /* l */
        "testl %ebx, %ebx\n" /* line 1271 | c */
        "jne .Lf17223a_00172278\n"
        ".Lf17223a_001722ad:\n"
        "movb $0, string+1023\n" /* line 1277 */
        /* } scope */
        "movl $string, %eax\n" /* line 1280 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17223a_001722c1:\n"
        "movl $0x2e, %ebx\n" /* line 1264 | c */
        "jmp .Lf17223a_0017226c\n"
    );
}

/* line 1019 */
void MSG_WriteShort(msg_t *msg, int c)
{
    int cursize = msg->cursize;
    int newsize = cursize + 2;
    if (newsize > msg->maxsize) {
        msg->overflowed = 1;
        return;
    }
    *(short *)(msg->data + cursize) = (short)c;
    msg->cursize = newsize;
}

/* line 1035 */
void MSG_WriteLong(msg_t *msg, int c)
{
    int cursize = msg->cursize;
    int newsize = cursize + 4;
    if (newsize > msg->maxsize) {
        msg->overflowed = 1;
        return;
    }
    *(int *)(msg->data + cursize) = c;
    msg->cursize = newsize;
}

/* line 769 */
extern void Huff_Init(void *huff);
extern void Huff_addRef(void *huff, byte ch);
void MSG_Init(msg_t *buf, byte *data, int length)
{
    int i, j;

    if (!msgInit) {
        msgInit = 1;
        Huff_Init(&msgHuff);
        for (i = 0; i < 256; i++) {
            for (j = 0; j < msg_hData[i]; j++) {
                Huff_addRef(&msgHuff, (byte)i);
                Huff_addRef((byte *)&msgHuff + 28700, (byte)i);
            }
        }
    }

    memset(buf, 0, sizeof(msg_t));
    buf->data = data;
    buf->maxsize = length;
}

/* line 1067 */
__attribute__((naked))
void MSG_WriteString(msg_t *sb, const char *s)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1067 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* s */
        /* { scope 1 */
        "cld\n" /* line 1074 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* s, i */
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n" /* l */
        "cmpl $0x3ff, %ebx\n" /* line 1075 | l */
        "jg .Lf1723ca_00172487\n"
        "testl %ebx, %ebx\n" /* line 1083 | l */
        "jg .Lf1723ca_00172426\n"
        "xorl %eax, %eax\n"
        "movb $0, -0x418(%ebp, %eax)\n" /* line 1085 */
        "leal 1(%ebx), %ecx\n" /* line 1087 | l, length */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 1007 | sb */
        "movl 0xc(%eax), %edx\n"
        "leal (%ecx, %edx), %ebx\n" /* newsize */
        "cmpl 8(%eax), %ebx\n" /* line 1008 | newsize */
        "jle .Lf1723ca_0017245d\n"
        ".Lf1723ca_00172415:\n"
        "movl $1, (%eax)\n" /* line 1015 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1723ca_0017241b:\n"
        "addl $0x41c, %esp\n" /* line 1088 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1723ca_00172426:\n"
        "xorl %edi, %edi\n" /* line 1015 */
        /* } scope */
        ".Lf1723ca_00172428:\n"
        "movsbl (%esi, %edi), %eax\n" /* line 1084 | s */
        "movl %eax, (%esp)\n"
        "calll I_CleanChar\n"
        "movb %al, -0x418(%edi, %ebp)\n" /* i */
        "addl $1, %edi\n" /* line 1083 | i */
        "cmpl %ebx, %edi\n" /* l, i */
        "jne .Lf1723ca_00172428\n"
        "movl %ebx, %eax\n" /* l */
        "movb $0, -0x418(%ebp, %eax)\n" /* line 1085 */
        "leal 1(%ebx), %ecx\n" /* line 1087 | l, length */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 1007 | sb */
        "movl 0xc(%eax), %edx\n"
        "leal (%ecx, %edx), %ebx\n" /* newsize */
        "cmpl 8(%eax), %ebx\n" /* line 1008 | newsize */
        "jg .Lf1723ca_00172415\n"
        ".Lf1723ca_0017245d:\n"
        "addl 4(%eax), %edx\n" /* line 1010 */
        "leal -0x418(%ebp), %eax\n" /* string */
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%ebp), %edx\n" /* line 1011 | sb */
        "movl %ebx, 0xc(%edx)\n" /* newsize */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 1088 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1723ca_00172487:\n"
        "movl $str_002ad920, (%esp)\n" /* line 1077 */
        "calll Com_Printf\n"
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 1007 | sb */
        "movl 0xc(%edx), %eax\n"
        "leal 1(%eax), %edx\n"
        "movl 8(%ebp), %ecx\n" /* line 1008 | sb */
        "cmpl 8(%ecx), %edx\n"
        "jle .Lf1723ca_001724b5\n"
        "movl $1, (%ecx)\n" /* line 1015 */
        /* } scope */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 1088 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1723ca_001724b5:\n"
        "addl 4(%ecx), %eax\n" /* line 1010 */
        "movb $0, (%eax)\n"
        "movl %edx, 0xc(%ecx)\n" /* line 1011 */
        "jmp .Lf1723ca_0017241b\n"
    );
}

/* line 1091 */
__attribute__((naked))
void MSG_WriteBigString(msg_t *sb, const char *s, msg_t *msg, int key, int oldV, int bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1091 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x201c, %esp\n"
        /* { scope 1 */
        "cld\n" /* line 1098 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* s, i */
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* l */
        "cmpl $0x1fff, %esi\n" /* line 1099 | l */
        "jle .Lf1724c4_00172518\n"
        "movl $str_002ad944, (%esp)\n" /* line 1101 */
        "calll Com_Printf\n"
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 1007 | sb */
        "movl 0xc(%edx), %eax\n"
        "leal 1(%eax), %edx\n"
        "movl 8(%ebp), %ecx\n" /* line 1008 | sb */
        "cmpl 8(%ecx), %edx\n"
        "jle .Lf1724c4_00172574\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1724c4_00172507:\n"
        "movl $1, (%ecx)\n" /* line 1015 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x201c, %esp\n" /* line 1112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1724c4_00172518:\n"
        "movl $0x2000, 8(%esp)\n" /* line 1105 */
        "movl 0xc(%ebp), %edx\n" /* s */
        "movl %edx, 4(%esp)\n"
        "leal -0x2018(%ebp), %ecx\n" /* string */
        "movl %ecx, (%esp)\n"
        "calll I_strncpyz\n"
        "testl %esi, %esi\n" /* line 1108 | l */
        "jg .Lf1724c4_00172588\n"
        "leal 1(%esi), %edx\n" /* line 1111 | l, length */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %ecx\n" /* line 1007 | sb */
        "movl 0xc(%ecx), %eax\n"
        "leal (%edx, %eax), %ebx\n" /* newsize */
        "cmpl 8(%ecx), %ebx\n" /* line 1008 | newsize */
        "jg .Lf1724c4_00172507\n"
        ".Lf1724c4_0017254a:\n"
        "addl 4(%ecx), %eax\n" /* line 1010 */
        "movl %edx, 8(%esp)\n"
        "leal -0x2018(%ebp), %edx\n" /* string */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%ebp), %ecx\n" /* line 1011 | sb */
        "movl %ebx, 0xc(%ecx)\n" /* newsize */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x201c, %esp\n" /* line 1112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1724c4_00172574:\n"
        "addl 4(%ecx), %eax\n" /* line 1010 */
        "movb $0, (%eax)\n"
        "movl %edx, 0xc(%ecx)\n" /* line 1011 */
        /* } scope */
        /* } scope */
        "addl $0x201c, %esp\n" /* line 1112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1724c4_00172588:\n"
        "xorl %edi, %edi\n" /* line 1108 | i */
        ".Lf1724c4_0017258a:\n"
        "leal -0x2018(%ebp), %eax\n" /* line 1091 | string */
        "leal (%edi, %eax), %ebx\n" /* bit, newsize */
        "movsbl (%ebx), %eax\n" /* line 1109 | newsize */
        "movl %eax, (%esp)\n"
        "calll I_CleanChar\n"
        "movb %al, (%ebx)\n" /* newsize */
        "addl $1, %edi\n" /* line 1108 | i */
        "cmpl %edi, %esi\n" /* i, l */
        "jne .Lf1724c4_0017258a\n"
        "leal 1(%esi), %edx\n" /* line 1111 | l, length */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %ecx\n" /* line 1007 | sb */
        "movl 0xc(%ecx), %eax\n"
        "leal (%edx, %eax), %ebx\n" /* newsize */
        "cmpl 8(%ecx), %ebx\n" /* line 1008 | newsize */
        "jg .Lf1724c4_00172507\n"
        "jmp .Lf1724c4_0017254a\n"
    );
}

/* line 2117 */
__attribute__((naked))
void MSG_ReadDeltaField(msg_t *msg, byte *from, byte *to, const NetField *field, qboolean print)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2117 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl 0x14(%ebp), %eax\n" /* field */
        "movl %eax, -0x2c(%ebp)\n" /* field */
        "movl 0x18(%ebp), %edx\n" /* print */
        "movl %edx, -0x30(%ebp)\n" /* print */
        /* { scope 1: bit, i */
        "movl 4(%eax), %eax\n" /* line 2128 */
        "movl %eax, %edi\n" /* bits */
        "addl 0xc(%ebp), %edi\n" /* from, bits */
        "addl 0x10(%ebp), %eax\n" /* line 2129 | to */
        "movl %eax, -0x28(%ebp)\n" /* toF */
        /* { scope 2 */
        "movl 0x14(%ebx), %eax\n" /* line 915 */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1725c0_0017272a\n"
        "movl 0x10(%ebx), %edx\n" /* line 918 */
        "cmpl 0xc(%ebx), %edx\n"
        "jl .Lf1725c0_00172714\n"
        "movl $1, (%ebx)\n" /* line 920 */
        /* } scope */
        ".Lf1725c0_00172609:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2138 | field */
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1725c0_00172759\n"
        /* { scope 2 */
        "movl -0x38(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1725c0_00172804\n"
        "movl 0x10(%ebx), %edx\n" /* line 918 */
        "cmpl 0xc(%ebx), %edx\n"
        "jl .Lf1725c0_001727f1\n"
        "movl $1, (%ebx)\n" /* line 920 */
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_00172635:\n"
        "movl -0x38(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "je .Lf1725c0_0017290e\n"
        ".Lf1725c0_00172641:\n"
        "movl -0x38(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%ebx), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movzbl (%ecx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x38(%ebp)\n" /* line 928 */
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2147 */
        "jne .Lf1725c0_00172881\n"
        "movl $0, -0x24(%ebp)\n" /* trunc */
        "xorl %esi, %esi\n" /* j */
        /* { scope 2 */
        ".Lf1725c0_00172670:\n"
        "movl -0x38(%ebp), %edi\n" /* line 891 | bit */
        "andl $7, %edi\n" /* bit */
        "jne .Lf1725c0_00172694\n"
        "cmpl 0xc(%ebx), %edx\n" /* line 893 */
        "jge .Lf1725c0_00172bb5\n"
        "leal (, %edx, 8), %eax\n" /* line 898 */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 899 */
        "movl %edx, 0x10(%ebx)\n"
        ".Lf1725c0_00172694:\n"
        "movl -0x38(%ebp), %eax\n" /* line 902 */
        "sarl $3, %eax\n"
        "movl -0x34(%ebp), %ecx\n"
        "movzbl (%ecx, %eax), %eax\n"
        "movl %edi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x24(%ebp)\n" /* trunc */
        "addl $1, -0x38(%ebp)\n" /* line 903 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, %esi\n" /* line 888 | i */
        "cmpl $5, %esi\n" /* i */
        "jne .Lf1725c0_00172670\n"
        /* } scope */
        ".Lf1725c0_001726c1:\n"
        "cmpl 0xc(%ebx), %edx\n" /* line 1137 */
        "jge .Lf1725c0_00172956\n"
        "movl -0x34(%ebp), %ecx\n" /* line 1139 */
        "movzbl (%ecx, %edx), %eax\n"
        "addl $1, %edx\n" /* line 1140 */
        "movl %edx, 0x10(%ebx)\n"
        "shll $5, %eax\n"
        ".Lf1725c0_001726da:\n"
        "movl -0x24(%ebp), %edx\n" /* line 2154 | trunc */
        "leal -0x1000(%edx, %eax), %eax\n"
        ".Lf1725c0_001726e4:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 2189 */
        "movl -0x28(%ebp), %ecx\n" /* toF */
        "movss %xmm0, (%ecx)\n"
        "movl -0x30(%ebp), %edx\n" /* line 2190 | print */
        "testl %edx, %edx\n"
        "je .Lf1725c0_00172751\n"
        "movl %eax, 0x10(%ebp)\n" /* line 2192 | to */
        "movl -0x2c(%ebp), %edx\n" /* field */
        "movl (%edx), %eax\n"
        ".Lf1725c0_001726fe:\n"
        "movl %eax, 0xc(%ebp)\n" /* line 2261 | from */
        "movl $str_002ad968, 8(%ebp)\n" /* msg */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2266 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: bit, i */
        "jmp Com_Printf\n" /* line 2261 */
        /* { scope 2 */
        ".Lf1725c0_00172714:\n"
        "leal (, %edx, 8), %ecx\n" /* line 923 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl %ecx, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%ebx)\n"
        "movl -0x38(%ebp), %eax\n"
        ".Lf1725c0_0017272a:\n"
        "sarl $3, %eax\n" /* line 927 */
        "movl 4(%ebx), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x38(%ebp)\n" /* line 928 */
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2131 */
        "jne .Lf1725c0_00172609\n"
        "movl (%edi), %eax\n" /* line 2134 | bits */
        "movl -0x28(%ebp), %ecx\n" /* toF */
        "movl %eax, (%ecx)\n"
        /* } scope */
        ".Lf1725c0_00172751:\n"
        "addl $0x2c, %esp\n" /* line 2266 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bit, i */
        ".Lf1725c0_00172759:\n"
        "cmpl $-0x63, %eax\n" /* line 2172 */
        "je .Lf1725c0_00172838\n"
        "cmpl $-0x64, %eax\n" /* line 2206 */
        "je .Lf1725c0_001729a5\n"
        /* { scope 2 */
        "movl -0x38(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1725c0_001728dd\n"
        "movl 0x10(%ebx), %eax\n" /* line 918 */
        "cmpl 0xc(%ebx), %eax\n"
        "jl .Lf1725c0_001728ca\n"
        "movl $1, (%ebx)\n" /* line 920 */
        /* } scope */
        ".Lf1725c0_00172789:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2228 | field */
        "movl 8(%eax), %edi\n" /* bits */
        "cmpl $-0x62, %edi\n" /* bits */
        "je .Lf1725c0_00172aff\n"
        "movl %edi, %edx\n" /* line 2236 | bits */
        "shrl $0x1f, %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* sgn */
        "je .Lf1725c0_001727a4\n"
        "negl %edi\n" /* bits */
        ".Lf1725c0_001727a4:\n"
        "movl %edi, %esi\n" /* bits, j */
        "andl $7, %esi\n" /* j */
        "cmpl $0, %esi\n" /* line 2243 | j */
        "je .Lf1725c0_001727b4\n"
        /* { scope 2 */
        "jg .Lf1725c0_00172b25\n" /* line 888 */
        ".Lf1725c0_001727b4:\n"
        "movl $0, -0x1c(%ebp)\n" /* value */
        "jmp .Lf1725c0_001727d4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_001727bd:\n"
        "movl 4(%ebx), %eax\n" /* line 1139 */
        "movzbl (%eax, %ecx), %edx\n"
        "leal 1(%ecx), %eax\n" /* line 1140 */
        "movl %eax, 0x10(%ebx)\n"
        /* } scope */
        ".Lf1725c0_001727ca:\n"
        "movl %esi, %ecx\n" /* line 2246 | j */
        "shll %cl, %edx\n"
        "orl %edx, -0x1c(%ebp)\n" /* value */
        "addl $8, %esi\n" /* line 2245 | j */
        ".Lf1725c0_001727d4:\n"
        "cmpl %esi, %edi\n" /* j, bits */
        "jle .Lf1725c0_00172966\n"
        /* { scope 2 */
        "movl 0x10(%ebx), %ecx\n" /* line 1137 */
        "cmpl 0xc(%ebx), %ecx\n"
        "jl .Lf1725c0_001727bd\n"
        "movl $1, (%ebx)\n" /* line 1143 */
        "movl $0xffffffff, %edx\n"
        "jmp .Lf1725c0_001727ca\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_001727f1:\n"
        "leal (, %edx, 8), %ecx\n" /* line 923 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl %ecx, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%ebx)\n"
        ".Lf1725c0_00172804:\n"
        "movl -0x38(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%ebx), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x38(%ebp)\n" /* line 928 */
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2141 */
        "jne .Lf1725c0_001729e9\n"
        ".Lf1725c0_00172827:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 2211 | toF */
        "movl $0, (%ecx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2266 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bit, i */
        /* { scope 2 */
        ".Lf1725c0_00172838:\n"
        "movl -0x38(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "je .Lf1725c0_0017292f\n"
        ".Lf1725c0_00172844:\n"
        "movl -0x38(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%ebx), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x38(%ebp)\n" /* line 928 */
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2175 */
        "je .Lf1725c0_00172827\n"
        "movl 0x10(%ebx), %edx\n" /* msg */
        /* { scope 2 */
        ".Lf1725c0_00172866:\n"
        "movl -0x38(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1725c0_00172a3f\n"
        "cmpl 0xc(%ebx), %edx\n" /* line 918 */
        "jl .Lf1725c0_00172a2c\n"
        ".Lf1725c0_0017287b:\n"
        "movl $1, (%ebx)\n" /* line 920 */
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_00172881:\n"
        "leal 4(%edx), %ecx\n" /* line 1170 */
        "cmpl 0xc(%ebx), %ecx\n" /* line 1171 */
        "jg .Lf1725c0_00172946\n"
        "movl 4(%ebx), %eax\n" /* line 1173 */
        "movl (%eax, %edx), %eax\n"
        "movl %ecx, 0x10(%ebx)\n" /* line 1174 */
        /* } scope */
        ".Lf1725c0_00172896:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 2198 | toF */
        "movl %eax, (%ecx)\n"
        "movl -0x30(%ebp), %eax\n" /* line 2199 | print */
        "testl %eax, %eax\n"
        "je .Lf1725c0_00172751\n"
        "cvtss2sd (%ecx), %xmm0\n" /* line 2201 */
        "movsd %xmm0, 0x10(%ebp)\n" /* to */
        "movl -0x2c(%ebp), %edx\n" /* field */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* from */
        "movl $str_002ad970, 8(%ebp)\n" /* msg */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2266 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: bit, i */
        "jmp Com_Printf\n" /* line 2201 */
        /* { scope 2 */
        ".Lf1725c0_001728ca:\n"
        "leal (, %eax, 8), %edx\n" /* line 923 */
        "movl %edx, -0x38(%ebp)\n"
        "movl %edx, 0x14(%ebx)\n"
        "leal 1(%eax), %edx\n" /* line 924 */
        "movl %edx, 0x10(%ebx)\n"
        ".Lf1725c0_001728dd:\n"
        "movl -0x38(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%ebx), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x38(%ebp)\n" /* line 928 */
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2220 */
        "jne .Lf1725c0_00172789\n"
        "movl -0x28(%ebp), %ecx\n" /* line 2222 | toF */
        "movl $0, (%ecx)\n"
        "jmp .Lf1725c0_00172751\n"
        /* { scope 2 */
        ".Lf1725c0_0017290e:\n"
        "cmpl 0xc(%ebx), %edx\n" /* line 918 */
        "jge .Lf1725c0_0017287b\n"
        "leal (, %edx, 8), %eax\n" /* line 923 */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%ebx)\n"
        "jmp .Lf1725c0_00172641\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_0017292f:\n"
        "movl 0x10(%ebx), %edx\n" /* line 918 */
        "cmpl 0xc(%ebx), %edx\n"
        "jl .Lf1725c0_00172ae7\n"
        "movl $1, (%ebx)\n" /* line 920 */
        "jmp .Lf1725c0_00172866\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_00172946:\n"
        "movl $1, (%ebx)\n" /* line 1177 */
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1725c0_00172896\n"
        /* } scope */
        ".Lf1725c0_00172956:\n"
        "movl $1, (%ebx)\n" /* line 1143 */
        "movl $0xffffffe0, %eax\n"
        "jmp .Lf1725c0_001726da\n"
        ".Lf1725c0_00172966:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2248 | sgn */
        "testl %eax, %eax\n"
        "je .Lf1725c0_00172985\n"
        "leal -1(%edi), %ecx\n" /* bits */
        "movl -0x1c(%ebp), %eax\n" /* value */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1725c0_00172985\n"
        "movl $0xffffffff, %eax\n" /* line 2249 */
        "movl %edi, %ecx\n" /* bits */
        "shll %cl, %eax\n"
        "orl %eax, -0x1c(%ebp)\n" /* value */
        ".Lf1725c0_00172985:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 2257 | value */
        "movl -0x28(%ebp), %eax\n" /* toF */
        "movl %edx, (%eax)\n"
        "movl -0x30(%ebp), %eax\n" /* line 2259 | print */
        "testl %eax, %eax\n"
        "je .Lf1725c0_00172751\n"
        "movl %edx, 0x10(%ebp)\n" /* line 2261 | to */
        "movl -0x2c(%ebp), %ecx\n" /* field */
        "movl (%ecx), %eax\n"
        "jmp .Lf1725c0_001726fe\n"
        /* { scope 2 */
        ".Lf1725c0_001729a5:\n"
        "movl -0x38(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1725c0_00172a04\n"
        "movl 0x10(%ebx), %edx\n" /* line 918 */
        "cmpl 0xc(%ebx), %edx\n"
        "jl .Lf1725c0_001729f1\n"
        "movl $1, (%ebx)\n" /* line 920 */
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_001729bb:\n"
        "leal 2(%edx), %ecx\n" /* line 1153 */
        "cmpl 0xc(%ebx), %ecx\n" /* line 1154 */
        "jg .Lf1725c0_00172b12\n"
        "movl 4(%ebx), %eax\n" /* line 1156 */
        "movswl (%eax, %edx), %eax\n"
        "movl %ecx, 0x10(%ebx)\n" /* line 1157 */
        "cvtsi2ssl %eax, %xmm0\n"
        /* } scope */
        ".Lf1725c0_001729d5:\n"
        "mulss lit4_002ed648, %xmm0\n" /* line 2215 | 0.0054931640625f */
        "movl -0x28(%ebp), %eax\n" /* toF */
        "movss %xmm0, (%eax)\n"
        "jmp .Lf1725c0_00172751\n"
        ".Lf1725c0_001729e9:\n"
        "movl 0x10(%ebx), %edx\n" /* msg */
        "jmp .Lf1725c0_00172635\n"
        /* { scope 2 */
        ".Lf1725c0_001729f1:\n"
        "leal (, %edx, 8), %ecx\n" /* line 923 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl %ecx, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%ebx)\n"
        ".Lf1725c0_00172a04:\n"
        "movl -0x38(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%ebx), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x38(%ebp)\n" /* line 928 */
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2209 */
        "je .Lf1725c0_00172827\n"
        "movl 0x10(%ebx), %edx\n" /* msg */
        "jmp .Lf1725c0_001729bb\n"
        /* { scope 2 */
        ".Lf1725c0_00172a2c:\n"
        "leal (, %edx, 8), %eax\n" /* line 923 */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%ebx)\n"
        ".Lf1725c0_00172a3f:\n"
        "movl -0x38(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%ebx), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movzbl (%ecx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x38(%ebp)\n" /* line 928 */
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2181 */
        "jne .Lf1725c0_00172881\n"
        "movl $0, -0x10(%ebp)\n"
        "xorl %esi, %esi\n" /* j */
        /* { scope 2 */
        ".Lf1725c0_00172a6e:\n"
        "movl -0x38(%ebp), %edi\n" /* line 891 | bit */
        "andl $7, %edi\n" /* bit */
        "jne .Lf1725c0_00172a92\n"
        "cmpl 0xc(%ebx), %edx\n" /* line 893 */
        "jge .Lf1725c0_00172bc7\n"
        "leal (, %edx, 8), %eax\n" /* line 898 */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 899 */
        "movl %edx, 0x10(%ebx)\n"
        ".Lf1725c0_00172a92:\n"
        "movl -0x38(%ebp), %eax\n" /* line 902 */
        "sarl $3, %eax\n"
        "movl -0x34(%ebp), %ecx\n"
        "movzbl (%ecx, %eax), %eax\n"
        "movl %edi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x10(%ebp)\n"
        "addl $1, -0x38(%ebp)\n" /* line 903 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, %esi\n" /* line 888 | i */
        "cmpl $2, %esi\n" /* i */
        "jne .Lf1725c0_00172a6e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_00172abf:\n"
        "cmpl 0xc(%ebx), %edx\n" /* line 1137 */
        "jge .Lf1725c0_00172ba5\n"
        "movl -0x34(%ebp), %ecx\n" /* line 1139 */
        "movzbl (%ecx, %edx), %eax\n"
        "addl $1, %edx\n" /* line 1140 */
        "movl %edx, 0x10(%ebx)\n"
        "shll $2, %eax\n"
        /* } scope */
        ".Lf1725c0_00172ad8:\n"
        "movl -0x10(%ebp), %edx\n" /* line 2188 */
        "leal -0x200(%edx, %eax), %eax\n"
        "jmp .Lf1725c0_001726e4\n"
        /* { scope 2 */
        ".Lf1725c0_00172ae7:\n"
        "leal (, %edx, 8), %ecx\n" /* line 923 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl %ecx, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%ebx)\n"
        "jmp .Lf1725c0_00172844\n"
        /* } scope */
        ".Lf1725c0_00172aff:\n"
        "movl $0, -0x20(%ebp)\n" /* line 2228 | sgn */
        "movl $0x20, %edi\n" /* bits */
        "xorl %esi, %esi\n" /* j */
        "jmp .Lf1725c0_001727b4\n"
        /* { scope 2 */
        ".Lf1725c0_00172b12:\n"
        "movl $1, (%ebx)\n" /* line 1160 */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        "jmp .Lf1725c0_001729d5\n"
        /* } scope */
        ".Lf1725c0_00172b25:\n"
        "movl $0, -0x14(%ebp)\n" /* line 2243 | i */
        "movl $0, -0x1c(%ebp)\n" /* value */
        "jmp .Lf1725c0_00172b80\n"
        /* { scope 2 */
        ".Lf1725c0_00172b35:\n"
        "leal (, %eax, 8), %edx\n" /* line 898 */
        "movl %edx, -0x38(%ebp)\n"
        "movl %edx, 0x14(%ebx)\n"
        "leal 1(%eax), %edx\n" /* line 899 */
        "movl %edx, 0x10(%ebx)\n"
        ".Lf1725c0_00172b48:\n"
        "movl -0x38(%ebp), %edx\n" /* line 902 */
        "sarl $3, %edx\n"
        "movl 4(%ebx), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movzbl -0x18(%ebp), %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movzbl -0x14(%ebp), %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x1c(%ebp)\n" /* value */
        "movl -0x38(%ebp), %eax\n" /* line 903 */
        "addl $1, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, -0x14(%ebp)\n" /* line 888 | i */
        "cmpl -0x14(%ebp), %esi\n" /* i */
        "je .Lf1725c0_001727d4\n"
        ".Lf1725c0_00172b80:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 891 */
        "andl $7, %ecx\n"
        "movl %ecx, -0x18(%ebp)\n" /* bit */
        "jne .Lf1725c0_00172b48\n"
        "movl 0x10(%ebx), %eax\n" /* line 893 */
        "cmpl 0xc(%ebx), %eax\n"
        "jl .Lf1725c0_00172b35\n"
        "movl $1, (%ebx)\n" /* line 895 */
        "movl $0xffffffff, -0x1c(%ebp)\n" /* value */
        "jmp .Lf1725c0_001727d4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_00172ba5:\n"
        "movl $1, (%ebx)\n" /* line 1143 */
        "movl $0xfffffffc, %eax\n"
        "jmp .Lf1725c0_00172ad8\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_00172bb5:\n"
        "movl $1, (%ebx)\n" /* line 895 */
        "movl $0xffffffff, -0x24(%ebp)\n" /* trunc */
        "jmp .Lf1725c0_001726c1\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1725c0_00172bc7:\n"
        "movl $1, (%ebx)\n"
        "movl $0xffffffff, -0x10(%ebp)\n"
        "jmp .Lf1725c0_00172abf\n"
    );
}

/* line 2307 */
static __attribute__((naked))
qboolean MSG_ReadDeltaStruct(byte *from, byte *to, unsigned int number, int numFields, int indexBits, const NetField *stateFields)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2307 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ebx\n" /* msg */
        "movl %edx, -0x24(%ebp)\n"
        "movl %ecx, -0x28(%ebp)\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x14(%eax), %edi\n" /* line 915 */
        "movl %edi, %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf172bda_00172c0d\n"
        "movl 0x10(%eax), %edx\n" /* line 918 */
        "cmpl 0xc(%eax), %edx\n"
        "jge .Lf172bda_00172c69\n"
        "leal (, %edx, 8), %edi\n" /* line 923 */
        "movl %edi, 0x14(%eax)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%eax)\n"
        ".Lf172bda_00172c0d:\n"
        "movl %edi, %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%ebx), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, %edi\n" /* line 928 */
        "movl %edi, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2317 */
        "je .Lf172bda_00172c6f\n"
        "movl imp_cl_shownet, %eax\n" /* line 2320 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf172bda_00172dd4\n"
        "movl 8(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "jle .Lf172bda_00172dcb\n"
        ".Lf172bda_00172c42:\n"
        "movl 8(%ebp), %edi\n" /* line 2321 | number, i */
        "movl %edi, 8(%esp)\n" /* i */
        "movl 0x10(%ebx), %eax\n" /* msg */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ad978, (%esp)\n" /* "%3i: #%-3i remove
" */
        "calll Com_Printf\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf172bda_00172c69:\n"
        "movl $1, (%eax)\n" /* line 920 */
        /* } scope */
        /* { scope 2 */
        ".Lf172bda_00172c6f:\n"
        "movl %edi, %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "je .Lf172bda_00172cba\n"
        "movl %edi, %edx\n" /* line 927 */
        "sarl $3, %edx\n"
        "movl 4(%ebx), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "leal 1(%edi), %edx\n" /* line 928 */
        "movl %edx, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2327 */
        "jne .Lf172bda_00172cf0\n"
        ".Lf172bda_00172c90:\n"
        "movl 0xc(%ebp), %edi\n" /* line 2329 | numFields, i */
        "leal 4(, %edi, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf172bda_00172cba:\n"
        "movl 0x10(%ebx), %edx\n" /* line 918 */
        "cmpl 0xc(%ebx), %edx\n"
        "jge .Lf172bda_00172dc0\n"
        "leal (, %edx, 8), %edi\n" /* line 923 */
        "movl %edi, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%ebx)\n"
        "movl %edi, %edx\n" /* line 927 */
        "sarl $3, %edx\n"
        "movl 4(%ebx), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "leal 1(%edi), %edx\n" /* line 928 */
        "movl %edx, 0x14(%ebx)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2327 */
        "je .Lf172bda_00172c90\n"
        ".Lf172bda_00172cf0:\n"
        "movl 0x10(%ebx), %edx\n" /* msg */
        ".Lf172bda_00172cf3:\n"
        "cmpl 0xc(%ebx), %edx\n" /* line 1137 */
        "jge .Lf172bda_00172d20\n"
        "movl 4(%ebx), %eax\n" /* line 1139 */
        "movzbl (%eax, %edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* lc */
        "leal 1(%edx), %eax\n" /* line 1140 */
        "movl %eax, 0x10(%ebx)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 2335 | numFields */
        "cmpl %ecx, -0x20(%ebp)\n" /* lc */
        "jle .Lf172bda_00172d35\n"
        ".Lf172bda_00172d10:\n"
        "movl $1, (%ebx)\n" /* line 2337 | msg */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf172bda_00172d20:\n"
        "movl $1, (%ebx)\n" /* line 1143 */
        "movl $0xffffffff, -0x20(%ebp)\n" /* lc */
        "movl 0xc(%ebp), %ecx\n" /* line 2335 | numFields */
        "cmpl %ecx, -0x20(%ebp)\n" /* lc */
        "jg .Lf172bda_00172d10\n"
        ".Lf172bda_00172d35:\n"
        "movl imp_cl_shownet, %eax\n" /* line 2344 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf172bda_00172dea\n"
        "movl 8(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "jle .Lf172bda_00172de1\n"
        ".Lf172bda_00172d50:\n"
        "movl -0x28(%ebp), %edi\n" /* line 2347 | i */
        "movl (%edi), %eax\n" /* i */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* msg */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ad98c, (%esp)\n" /* "%3i: #%-3i " */
        "calll Com_Printf\n"
        "movl $1, -0x1c(%ebp)\n" /* print */
        ".Lf172bda_00172d73:\n"
        "movl 8(%ebp), %edx\n" /* line 2355 | number */
        "movl -0x28(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "movl -0x20(%ebp), %ecx\n" /* line 2357 | lc */
        "testl %ecx, %ecx\n"
        "jg .Lf172bda_00172df3\n"
        ".Lf172bda_00172d82:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 2360 | lc */
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl 0x14(%ebp), %edi\n" /* stateFields, i */
        "leal (%edi, %eax, 4), %ecx\n" /* i */
        "movl 0xc(%ebp), %eax\n" /* numFields */
        "cmpl %eax, -0x20(%ebp)\n" /* lc */
        "jge .Lf172bda_00172db6\n"
        "xorl %ebx, %ebx\n" /* msg */
        "movl %eax, %esi\n" /* field */
        "subl -0x20(%ebp), %esi\n" /* lc, field */
        ".Lf172bda_00172d9d:\n"
        "movl 4(%ecx), %edx\n" /* line 2362 */
        "movl -0x24(%ebp), %edi\n" /* line 2365 | i */
        "movl (%edx, %edi), %eax\n"
        "movl -0x28(%ebp), %edi\n" /* i */
        "movl %eax, (%edi, %edx)\n" /* i */
        "addl $0xc, %ecx\n" /* line 2360 */
        "addl $1, %ebx\n" /* msg */
        "cmpl %ebx, %esi\n" /* msg, field */
        "jne .Lf172bda_00172d9d\n"
        ".Lf172bda_00172db6:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf172bda_00172dc0:\n"
        "movl $1, (%ebx)\n" /* line 920 */
        "jmp .Lf172bda_00172cf3\n"
        /* } scope */
        ".Lf172bda_00172dcb:\n"
        "addl $1, %eax\n" /* line 2320 */
        "je .Lf172bda_00172c42\n"
        ".Lf172bda_00172dd4:\n"
        "movl $1, %eax\n" /* line 2360 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf172bda_00172de1:\n"
        "addl $1, %eax\n" /* line 2344 */
        "je .Lf172bda_00172d50\n"
        ".Lf172bda_00172dea:\n"
        "movl $0, -0x1c(%ebp)\n" /* print */
        "jmp .Lf172bda_00172d73\n"
        ".Lf172bda_00172df3:\n"
        "movl 0x14(%ebp), %esi\n" /* line 2357 | stateFields, field */
        "xorl %edi, %edi\n" /* i */
        ".Lf172bda_00172df8:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 2358 | print */
        "movl %ecx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* field */
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* msg */
        "calll MSG_ReadDeltaField\n"
        "addl $1, %edi\n" /* line 2357 | i */
        "addl $0xc, %esi\n" /* field */
        "cmpl %edi, -0x20(%ebp)\n" /* i, lc */
        "jne .Lf172bda_00172df8\n"
        "jmp .Lf172bda_00172d82\n"
    );
}

/* line 2420 */
__attribute__((naked))
qboolean MSG_ReadDeltaClient(msg_t *msg, clientState_t *from, clientState_t *to, int number)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2420 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x74, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* from */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 2429 */
        "je .Lf172e2a_00172e67\n"
        ".Lf172e2a_00172e38:\n"
        "movl $clientStateFields, 0xc(%esp)\n" /* line 2435 */
        "movl $6, 8(%esp)\n"
        "movl $0x16, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* number */
        "movl %eax, (%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* to */
        "movl 8(%ebp), %eax\n" /* msg */
        "calll MSG_ReadDeltaStruct\n"
        /* } scope */
        "addl $0x74, %esp\n" /* line 2436 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf172e2a_00172e67:\n"
        "leal -0x64(%ebp), %ebx\n" /* line 2432 | dummy */
        "movl $0x5c, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memset\n"
        "movl %ebx, %edx\n"
        "jmp .Lf172e2a_00172e38\n"
    );
}

/* line 2402 */
__attribute__((naked))
qboolean MSG_ReadDeltaArchivedEntity(msg_t *msg, archivedEntity_t *from, archivedEntity_t *to, int number)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2402 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0xc(%ebp), %edx\n" /* from */
        "movl 0x10(%ebp), %ecx\n" /* to */
        "movl 0x14(%ebp), %ebx\n" /* number */
        "movl $archivedEntityFields, 0x14(%ebp)\n" /* line 2410 | number */
        "movl $0xa, 0x10(%ebp)\n" /* to */
        "movl $0x44, 0xc(%ebp)\n" /* from */
        "movl %ebx, 8(%ebp)\n" /* number, msg */
        "popl %ebx\n" /* line 2411 */
        "popl %ebp\n"
        "jmp MSG_ReadDeltaStruct\n" /* line 2410 */
    );
}

/* line 2384 */
__attribute__((naked))
qboolean MSG_ReadDeltaEntity(msg_t *msg, entityState_t *from, entityState_t *to, int number)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2384 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0xc(%ebp), %edx\n" /* from */
        "movl 0x10(%ebp), %ecx\n" /* to */
        "movl 0x14(%ebp), %ebx\n" /* number */
        "movl $entityStateFields, 0x14(%ebp)\n" /* line 2392 | number */
        "movl $0xa, 0x10(%ebp)\n" /* to */
        "movl $0x3b, 0xc(%ebp)\n" /* from */
        "movl %ebx, 8(%ebp)\n" /* number, msg */
        "popl %ebx\n" /* line 2393 */
        "popl %ebp\n"
        "jmp MSG_ReadDeltaStruct\n" /* line 2392 */
    );
}

/* line 2504 */
static __attribute__((naked))
void MSG_ReadDeltaHudElems(hudelem_t *from, hudelem_t *to, int count)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2504 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %ebx\n" /* msg */
        "movl %edx, -0x30(%ebp)\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movl $0, -0x28(%ebp)\n" /* inuse */
        "xorl %esi, %esi\n" /* i */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, %edi\n" /* bit */
        /* { scope 1 */
        /* { scope 2 */
        "andl $7, %edi\n" /* line 891 | bit */
        "jne .Lf172ee6_00172f5d\n"
        ".Lf172ee6_00172f0d:\n"
        "movl 0x10(%ebx), %eax\n" /* line 893 */
        "cmpl 0xc(%ebx), %eax\n"
        "jge .Lf172ee6_001730c1\n"
        "leal (, %eax, 8), %edx\n" /* line 898 */
        "movl %edx, -0x3c(%ebp)\n"
        "movl %edx, 0x14(%ebx)\n"
        "addl $1, %eax\n" /* line 899 */
        "movl %eax, 0x10(%ebx)\n"
        ".Lf172ee6_00172f2c:\n"
        "sarl $3, %edx\n" /* line 902 */
        "movl 4(%ebx), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %edi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x28(%ebp)\n" /* inuse */
        "addl $1, -0x3c(%ebp)\n" /* line 903 */
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, %esi\n" /* line 888 | i */
        "cmpl $5, %esi\n" /* i */
        "je .Lf172ee6_00172f62\n"
        "movl %eax, %edi\n" /* bit */
        "andl $7, %edi\n" /* line 891 | bit */
        "je .Lf172ee6_00172f0d\n"
        ".Lf172ee6_00172f5d:\n"
        "movl -0x3c(%ebp), %edx\n"
        "jmp .Lf172ee6_00172f2c\n"
        /* } scope */
        ".Lf172ee6_00172f62:\n"
        "movl -0x28(%ebp), %edi\n" /* line 2514 | inuse, j */
        "testl %edi, %edi\n" /* j */
        "jle .Lf172ee6_001730bc\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* i */
        ".Lf172ee6_00172f80:\n"
        "movl $0, -0x24(%ebp)\n" /* lc */
        "xorl %esi, %esi\n" /* i */
        "movl -0x3c(%ebp), %edi\n" /* j */
        /* { scope 2 */
        "andl $7, %edi\n" /* line 891 | bit */
        "jne .Lf172ee6_00172fe3\n"
        ".Lf172ee6_00172f91:\n"
        "movl 0x10(%ebx), %eax\n" /* line 893 */
        "cmpl 0xc(%ebx), %eax\n"
        "jge .Lf172ee6_001730b1\n"
        "leal (, %eax, 8), %edx\n" /* line 898 */
        "movl %edx, -0x3c(%ebp)\n"
        "movl %edx, 0x14(%ebx)\n"
        "addl $1, %eax\n" /* line 899 */
        "movl %eax, 0x10(%ebx)\n"
        ".Lf172ee6_00172fb0:\n"
        "sarl $3, %edx\n" /* line 902 */
        "movl 4(%ebx), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %edi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x24(%ebp)\n" /* lc */
        "movl -0x3c(%ebp), %eax\n" /* line 903 */
        "addl $1, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, %esi\n" /* line 888 | i */
        "cmpl $5, %esi\n" /* i */
        "je .Lf172ee6_00172fe8\n"
        "movl %eax, %edi\n" /* bit */
        "andl $7, %edi\n" /* line 891 | bit */
        "je .Lf172ee6_00172f91\n"
        ".Lf172ee6_00172fe3:\n"
        "movl -0x3c(%ebp), %edx\n"
        "jmp .Lf172ee6_00172fb0\n"
        /* } scope */
        ".Lf172ee6_00172fe8:\n"
        "movl -0x24(%ebp), %esi\n" /* line 2517 | lc, i */
        "testl %esi, %esi\n" /* i */
        "jns .Lf172ee6_00173034\n"
        /* { scope 2 */
        ".Lf172ee6_00172fef:\n"
        "xorl %edi, %edi\n" /* line 895 | bit */
        /* } scope */
        ".Lf172ee6_00172ff1:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 2519 | j */
        "leal hudElemFields(, %eax, 4), %ecx\n"
        ".Lf172ee6_00172ffb:\n"
        "movl 4(%ecx), %edx\n" /* line 2520 */
        "movl -0x20(%ebp), %esi\n" /* i */
        "movl (%edx, %esi), %eax\n"
        "movl -0x1c(%ebp), %esi\n" /* i */
        "movl %eax, (%edx, %esi)\n"
        "addl $1, %edi\n" /* line 2519 | j */
        "addl $0xc, %ecx\n"
        "cmpl $0x1f, %edi\n" /* j */
        "jbe .Lf172ee6_00172ffb\n"
        "addl $1, -0x2c(%ebp)\n" /* line 2514 | i */
        "subl $-0x80, -0x20(%ebp)\n"
        "subl $-0x80, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* inuse */
        "cmpl %eax, -0x2c(%ebp)\n" /* i */
        "je .Lf172ee6_00173081\n"
        ".Lf172ee6_00173029:\n"
        "movl 0x14(%ebx), %esi\n" /* msg, i */
        "movl %esi, -0x3c(%ebp)\n" /* i */
        "jmp .Lf172ee6_00172f80\n"
        ".Lf172ee6_00173034:\n"
        "xorl %edi, %edi\n" /* line 2517 | j */
        "movl $hudElemFields, %esi\n" /* i */
        ".Lf172ee6_0017303b:\n"
        "movl $0, 0x10(%esp)\n" /* line 2518 */
        "movl %esi, 0xc(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* msg */
        "calll MSG_ReadDeltaField\n"
        "addl $1, %edi\n" /* line 2517 | j */
        "addl $0xc, %esi\n" /* i */
        "cmpl %edi, -0x24(%ebp)\n" /* j, lc */
        "jge .Lf172ee6_0017303b\n"
        "cmpl $0x1f, %edi\n" /* line 2519 | j */
        "jbe .Lf172ee6_00172ff1\n"
        "addl $1, -0x2c(%ebp)\n" /* line 2514 | i */
        "subl $-0x80, -0x20(%ebp)\n"
        "subl $-0x80, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* inuse */
        "cmpl %eax, -0x2c(%ebp)\n" /* i */
        "jne .Lf172ee6_00173029\n"
        ".Lf172ee6_00173081:\n"
        "movl %eax, %edx\n"
        ".Lf172ee6_00173083:\n"
        "subl %edx, 8(%ebp)\n" /* line 2522 | count */
        "shll $7, 8(%ebp)\n" /* count */
        "shll $7, %edx\n"
        "movl %edx, %eax\n"
        "addl -0x34(%ebp), %eax\n"
        "movl 8(%ebp), %ecx\n" /* count */
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2523 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf172ee6_001730b1:\n"
        "movl $1, (%ebx)\n" /* line 895 */
        "jmp .Lf172ee6_00172fef\n"
        ".Lf172ee6_001730bc:\n"
        "movl -0x28(%ebp), %edx\n" /* inuse */
        "jmp .Lf172ee6_00173083\n"
        /* } scope */
        /* { scope 2 */
        ".Lf172ee6_001730c1:\n"
        "movl $1, (%ebx)\n"
        "movl $0xffffffff, -0x28(%ebp)\n" /* inuse */
        "movl -0x28(%ebp), %edx\n" /* inuse */
        "jmp .Lf172ee6_00173083\n"
    );
}

/* line 2822 */
__attribute__((naked))
void MSG_ReadDeltaPlayerstate(msg_t *msg, playerState_t *from, playerState_t *to)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2822 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x274c, %esp\n"
        "movl 8(%ebp), %edi\n" /* msg */
        /* { scope 1: value, to, value, bit */
        "movl 0xc(%ebp), %ecx\n" /* line 2836 | from */
        "testl %ecx, %ecx\n"
        "je .Lf1730d4_0017409e\n"
        "movl 0xc(%ebp), %eax\n" /* from */
        ".Lf1730d4_001730f1:\n"
        "movl $0x26a8, 8(%esp)\n" /* line 2841 */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* to */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl imp_cl_shownet, %eax\n" /* line 2846 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1730d4_00173ebe\n"
        "movl 8(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "jle .Lf1730d4_00173eb5\n"
        ".Lf1730d4_00173123:\n"
        "movl 0x10(%edi), %eax\n" /* line 2849 | msg */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ad998, (%esp)\n" /* "%3i: playerstate " */
        "calll Com_Printf\n"
        "movl $1, -0x2714(%ebp)\n" /* print */
        ".Lf1730d4_00173140:\n"
        "movl 0x10(%edi), %edx\n" /* line 1137 */
        "cmpl 0xc(%edi), %edx\n"
        "jge .Lf1730d4_00173a29\n"
        "movl 4(%edi), %eax\n" /* line 1139 */
        "movzbl (%eax, %edx), %eax\n"
        "movl %eax, -0x2718(%ebp)\n" /* lc */
        "addl $1, %edx\n" /* line 1140 */
        "movl %edx, 0x10(%edi)\n"
        "testl %eax, %eax\n" /* line 2860 */
        "jle .Lf1730d4_00173a39\n"
        "movl $0, -0x271c(%ebp)\n" /* line 1143 | i */
        "movl $playerStateFields+4, -0x26e0(%ebp)\n"
        ".Lf1730d4_0017317b:\n"
        "movl -0x26e0(%ebp), %ecx\n" /* line 2862 */
        "movl (%ecx), %eax\n"
        "movl 0xc(%ebp), %ebx\n" /* from, bit */
        "addl %eax, %ebx\n" /* bit */
        "addl 0x10(%ebp), %eax\n" /* line 2863 | to */
        "movl %eax, -0x26dc(%ebp)\n"
        /* { scope 2 */
        "movl 0x14(%edi), %eax\n" /* line 915 */
        "movl %eax, -0x272c(%ebp)\n"
        "movl %eax, %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1730d4_00173625\n"
        "movl 0x10(%edi), %edx\n" /* line 918 */
        "cmpl 0xc(%edi), %edx\n"
        "jl .Lf1730d4_00173609\n"
        "movl $1, (%edi)\n" /* line 920 */
        /* } scope */
        ".Lf1730d4_001731b7:\n"
        "movl -0x26e0(%ebp), %ebx\n" /* line 2872 | bit */
        "movl 4(%ebx), %esi\n" /* bit, field */
        "testl %esi, %esi\n" /* field */
        "jne .Lf1730d4_0017367a\n"
        /* { scope 2 */
        "movl -0x272c(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1730d4_00173918\n"
        "movl 0x10(%edi), %edx\n" /* line 918 */
        "cmpl 0xc(%edi), %edx\n"
        "jl .Lf1730d4_00173902\n"
        "movl $1, (%edi)\n" /* line 920 */
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_001731e9:\n"
        "leal 4(%edx), %ecx\n" /* line 1170 */
        "cmpl 0xc(%edi), %ecx\n" /* line 1171 */
        "jg .Lf1730d4_00173ff1\n"
        "movl 4(%edi), %eax\n" /* line 1173 */
        "movl (%eax, %edx), %eax\n"
        "movl %ecx, 0x10(%edi)\n" /* line 1174 */
        /* } scope */
        ".Lf1730d4_001731fe:\n"
        "movl -0x26dc(%ebp), %ebx\n" /* line 2892 | bit */
        "movl %eax, (%ebx)\n" /* bit */
        "movl -0x2714(%ebp), %esi\n" /* line 2893 | print, field */
        "testl %esi, %esi\n" /* field */
        "je .Lf1730d4_00173655\n"
        "cvtss2sd (%ebx), %xmm0\n" /* line 2895 | bit */
        "movsd %xmm0, 8(%esp)\n"
        "movl -0x26e0(%ebp), %edx\n"
        "movl -4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ad970, (%esp)\n" /* "%s:%f " */
        "calll Com_Printf\n"
        "addl $1, -0x271c(%ebp)\n" /* line 2860 | i */
        "addl $0xc, -0x26e0(%ebp)\n"
        "movl -0x2718(%ebp), %ecx\n" /* lc */
        "cmpl %ecx, -0x271c(%ebp)\n" /* i */
        "jne .Lf1730d4_0017317b\n"
        ".Lf1730d4_00173257:\n"
        "movl %ecx, %ebx\n" /* bit */
        ".Lf1730d4_00173259:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 2934 | bit */
        "leal playerStateFields(, %eax, 4), %esi\n" /* field */
        "cmpl $0x68, %ebx\n" /* bit */
        "jg .Lf1730d4_00173284\n"
        "movl %ebx, %ecx\n" /* bit */
        ".Lf1730d4_0017326a:\n"
        "movl 4(%esi), %edx\n" /* line 2936 | field */
        "movl 0xc(%ebp), %ebx\n" /* line 2939 | from, bit */
        "movl (%ebx, %edx), %eax\n" /* bit */
        "movl 0x10(%ebp), %ebx\n" /* to, bit */
        "movl %eax, (%ebx, %edx)\n" /* bit */
        "addl $1, %ecx\n" /* line 2934 */
        "addl $0xc, %esi\n" /* field */
        "cmpl $0x69, %ecx\n"
        "jne .Lf1730d4_0017326a\n"
        /* { scope 2 */
        ".Lf1730d4_00173284:\n"
        "movl 0x14(%edi), %eax\n" /* line 915 */
        "movl %eax, -0x272c(%ebp)\n"
        "movl %eax, %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1730d4_001732bc\n"
        "movl 0x10(%edi), %eax\n" /* line 918 */
        "cmpl 0xc(%edi), %eax\n"
        "jge .Lf1730d4_0017374d\n"
        "leal (, %eax, 8), %edx\n" /* line 923 */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 924 */
        "movl %edx, 0x10(%edi)\n"
        "movl -0x272c(%ebp), %eax\n"
        ".Lf1730d4_001732bc:\n"
        "sarl $3, %eax\n" /* line 927 */
        "movl 4(%edi), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x272c(%ebp)\n" /* line 928 */
        "movl -0x272c(%ebp), %ebx\n" /* bit */
        "movl %ebx, 0x14(%edi)\n" /* bit */
        /* } scope */
        "testb $1, %al\n" /* line 2943 */
        "jne .Lf1730d4_00173753\n"
        "movl -0x272c(%ebp), %esi\n" /* field */
        /* { scope 2 */
        ".Lf1730d4_001732e8:\n"
        "andl $7, %esi\n" /* line 916 | bit */
        "jne .Lf1730d4_001738d1\n"
        ".Lf1730d4_001732f1:\n"
        "movl 0x10(%edi), %eax\n" /* line 918 */
        "cmpl 0xc(%edi), %eax\n"
        "jl .Lf1730d4_00173f93\n"
        "movl $1, (%edi)\n" /* line 920 */
        /* } scope */
        ".Lf1730d4_00173303:\n"
        "movl $0, -0x26e4(%ebp)\n" /* line 2974 */
        "movl 0x10(%ebp), %eax\n" /* to */
        "addl $0x140, %eax\n"
        "movl %eax, -0x2728(%ebp)\n"
        /* { scope 2 */
        ".Lf1730d4_0017331b:\n"
        "movl -0x272c(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1730d4_00173de2\n"
        "movl 0x10(%edi), %eax\n" /* line 918 */
        "cmpl 0xc(%edi), %eax\n"
        "jl .Lf1730d4_00173dcc\n"
        "movl $1, (%edi)\n" /* line 920 */
        /* } scope */
        ".Lf1730d4_0017333c:\n"
        "movl imp_cl_shownet, %eax\n" /* line 2980 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1730d4_00173351\n"
        "cmpl $4, 8(%eax)\n"
        "je .Lf1730d4_0017407d\n"
        /* { scope 2 */
        ".Lf1730d4_00173351:\n"
        "movl 0x10(%edi), %ecx\n" /* line 1153 */
        "leal 2(%ecx), %edx\n"
        "cmpl 0xc(%edi), %edx\n" /* line 1154 */
        "jg .Lf1730d4_00173e28\n"
        "movl 4(%edi), %eax\n" /* line 1156 */
        "movswl (%eax, %ecx), %eax\n"
        "movl %eax, -0x26d8(%ebp)\n"
        "movl %edx, 0x10(%edi)\n" /* line 1157 */
        ".Lf1730d4_00173370:\n"
        "movl -0x2728(%ebp), %edx\n" /* line 1160 */
        "addl $4, %edx\n"
        "xorl %ebx, %ebx\n" /* bit */
        /* } scope */
        ".Lf1730d4_0017337b:\n"
        "movl -0x26d8(%ebp), %eax\n" /* line 2984 */
        "movl %ebx, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1730d4_001733a4\n"
        /* { scope 2 */
        "movl 0x10(%edi), %esi\n" /* line 1153 | bit */
        "leal 2(%esi), %ecx\n" /* bit */
        "cmpl 0xc(%edi), %ecx\n" /* line 1154 */
        "jg .Lf1730d4_00173d75\n"
        "movl 4(%edi), %eax\n" /* line 1156 */
        "movswl (%eax, %esi), %eax\n"
        "movl %ecx, 0x10(%edi)\n" /* line 1157 */
        /* } scope */
        ".Lf1730d4_001733a2:\n"
        "movl %eax, (%edx)\n" /* line 2986 */
        ".Lf1730d4_001733a4:\n"
        "addl $1, %ebx\n" /* line 2982 | bit */
        "addl $4, %edx\n"
        "cmpl $0x10, %ebx\n" /* bit */
        "jne .Lf1730d4_0017337b\n"
        "movl 0x14(%edi), %ebx\n" /* msg, bit */
        "movl %ebx, -0x272c(%ebp)\n" /* bit */
        ".Lf1730d4_001733b8:\n"
        "addl $0x10, -0x26e4(%ebp)\n"
        "addl $0x40, -0x2728(%ebp)\n"
        "cmpl $0x40, -0x26e4(%ebp)\n" /* line 2976 */
        "jne .Lf1730d4_0017331b\n"
        ".Lf1730d4_001733d3:\n"
        "movl $0, -0x26e8(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* to */
        "addl $0x340, %eax\n"
        "movl %eax, -0x2724(%ebp)\n"
        /* { scope 2 */
        ".Lf1730d4_001733eb:\n"
        "movl -0x272c(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1730d4_00173d9b\n"
        "movl 0x10(%edi), %eax\n" /* line 918 */
        "cmpl 0xc(%edi), %eax\n"
        "jl .Lf1730d4_00173d85\n"
        "movl $1, (%edi)\n" /* line 920 */
        /* } scope */
        ".Lf1730d4_0017340c:\n"
        "movl imp_cl_shownet, %eax\n" /* line 2998 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1730d4_00173421\n"
        "cmpl $4, 8(%eax)\n"
        "je .Lf1730d4_00173ecd\n"
        /* { scope 2 */
        ".Lf1730d4_00173421:\n"
        "movl 0x10(%edi), %ecx\n" /* line 1153 */
        "leal 2(%ecx), %edx\n"
        "cmpl 0xc(%edi), %edx\n" /* line 1154 */
        "jg .Lf1730d4_00173e13\n"
        "movl 4(%edi), %eax\n" /* line 1156 */
        "movswl (%eax, %ecx), %eax\n"
        "movl %eax, -0x26d4(%ebp)\n"
        "movl %edx, 0x10(%edi)\n" /* line 1157 */
        ".Lf1730d4_00173440:\n"
        "movl -0x2724(%ebp), %edx\n" /* line 1160 */
        "addl $4, %edx\n"
        "xorl %esi, %esi\n" /* bit */
        /* } scope */
        ".Lf1730d4_0017344b:\n"
        "movl -0x26d4(%ebp), %eax\n" /* line 3002 */
        "movl %esi, %ecx\n" /* field */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1730d4_00173474\n"
        /* { scope 2 */
        "movl 0x10(%edi), %ebx\n" /* line 1153 | bit */
        "leal 2(%ebx), %ecx\n" /* bit */
        "cmpl 0xc(%edi), %ecx\n" /* line 1154 */
        "jg .Lf1730d4_00173c2b\n"
        "movl 4(%edi), %eax\n" /* line 1156 */
        "movswl (%eax, %ebx), %eax\n"
        "movl %ecx, 0x10(%edi)\n" /* line 1157 */
        /* } scope */
        ".Lf1730d4_00173472:\n"
        "movl %eax, (%edx)\n" /* line 3004 */
        ".Lf1730d4_00173474:\n"
        "addl $1, %esi\n" /* line 3000 | field */
        "addl $4, %edx\n"
        "cmpl $0x10, %esi\n" /* field */
        "jne .Lf1730d4_0017344b\n"
        "movl 0x14(%edi), %ebx\n" /* msg, bit */
        "movl %ebx, -0x272c(%ebp)\n" /* bit */
        ".Lf1730d4_00173488:\n"
        "addl $0x10, -0x26e8(%ebp)\n"
        "addl $0x40, -0x2724(%ebp)\n"
        "cmpl $0x40, -0x26e8(%ebp)\n" /* line 2994 */
        "jne .Lf1730d4_001733eb\n"
        /* { scope 2 */
        "movl -0x272c(%ebp), %esi\n" /* line 916 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf1730d4_00173e53\n"
        "movl 0x10(%edi), %eax\n" /* line 918 */
        "cmpl 0xc(%edi), %eax\n"
        "jl .Lf1730d4_00173e3d\n"
        "movl $1, (%edi)\n" /* line 920 */
        /* } scope */
        ".Lf1730d4_001734c4:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3011 | to */
        "movl %eax, -0x26ec(%ebp)\n"
        "movl $0, -0x26cc(%ebp)\n"
        ".Lf1730d4_001734d7:\n"
        "movl $0, -0x26f8(%ebp)\n" /* value */
        "xorl %esi, %esi\n" /* field */
        /* { scope 2 */
        ".Lf1730d4_001734e3:\n"
        "movl -0x272c(%ebp), %ebx\n" /* line 891 | i */
        "andl $7, %ebx\n" /* i */
        "jne .Lf1730d4_00173510\n"
        "movl 0x10(%edi), %eax\n" /* line 893 */
        "cmpl 0xc(%edi), %eax\n"
        "jge .Lf1730d4_00173ea5\n"
        "leal (, %eax, 8), %ecx\n" /* line 898 */
        "movl %ecx, -0x272c(%ebp)\n"
        "movl %ecx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 899 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_00173510:\n"
        "movl -0x272c(%ebp), %edx\n" /* line 902 */
        "sarl $3, %edx\n"
        "movl 4(%edi), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %ebx, %ecx\n" /* i */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x26f8(%ebp)\n" /* value */
        "addl $1, -0x272c(%ebp)\n" /* line 903 */
        "movl -0x272c(%ebp), %ebx\n" /* i */
        "movl %ebx, 0x14(%edi)\n" /* i */
        "addl $1, %esi\n" /* line 888 | i */
        "cmpl $3, %esi\n" /* i */
        "jne .Lf1730d4_001734e3\n"
        "movl -0x26f8(%ebp), %eax\n" /* value */
        /* } scope */
        ".Lf1730d4_0017354f:\n"
        "movl -0x26ec(%ebp), %edx\n" /* line 3016 */
        "movl %eax, 0x5e4(%edx)\n"
        "movl -0x26cc(%ebp), %edx\n" /* line 3017 */
        "shll $2, %edx\n"
        "movl -0x26cc(%ebp), %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "addl $0x5e0, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* to */
        "leal 4(%ecx, %eax), %ecx\n"
        "movl %ecx, -0x26f4(%ebp)\n" /* to */
        "movl 0xc(%ebp), %ebx\n" /* from, bit */
        "leal 4(%ebx, %eax), %esi\n" /* bit, from */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x14(%edi), %eax\n" /* line 915 */
        "movl %eax, -0x272c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 916 | bit */
        "andl $7, %ebx\n" /* bit */
        "jne .Lf1730d4_00173c57\n"
        "movl 0x10(%edi), %eax\n" /* line 918 */
        "cmpl 0xc(%edi), %eax\n"
        "jl .Lf1730d4_00173c3b\n"
        "movl $1, (%edi)\n" /* line 920 */
        /* } scope */
        ".Lf1730d4_001735ae:\n"
        "movl $objectiveFields, %ebx\n" /* line 2281 | bit */
        ".Lf1730d4_001735b3:\n"
        "movl $0, 0x10(%esp)\n" /* line 2284 */
        "movl %ebx, 0xc(%esp)\n" /* bit */
        "movl -0x26f4(%ebp), %eax\n" /* to */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* bit */
        "movl %edi, (%esp)\n"
        "calll MSG_ReadDeltaField\n"
        "addl $0xc, %ebx\n" /* bit */
        "cmpl $objectiveFields+72, %ebx\n" /* line 2283 | bit */
        "jne .Lf1730d4_001735b3\n"
        /* } scope */
        "addl $1, -0x26cc(%ebp)\n" /* line 3013 */
        "addl $0x1c, -0x26ec(%ebp)\n"
        "cmpl $0x10, -0x26cc(%ebp)\n"
        "je .Lf1730d4_00173cb6\n"
        ".Lf1730d4_001735fb:\n"
        "movl 0x14(%edi), %edx\n" /* msg */
        "movl %edx, -0x272c(%ebp)\n"
        "jmp .Lf1730d4_001734d7\n"
        /* { scope 2 */
        ".Lf1730d4_00173609:\n"
        "leal (, %edx, 8), %ecx\n" /* line 923 */
        "movl %ecx, -0x272c(%ebp)\n"
        "movl %ecx, 0x14(%edi)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%edi)\n"
        "movl -0x272c(%ebp), %eax\n"
        ".Lf1730d4_00173625:\n"
        "sarl $3, %eax\n" /* line 927 */
        "movl 4(%edi), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x272c(%ebp)\n" /* line 928 */
        "movl -0x272c(%ebp), %edx\n"
        "movl %edx, 0x14(%edi)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2865 */
        "jne .Lf1730d4_001731b7\n"
        "movl (%ebx), %eax\n" /* line 2868 | bit */
        "movl -0x26dc(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        ".Lf1730d4_00173655:\n"
        "addl $1, -0x271c(%ebp)\n" /* line 2860 | i */
        "addl $0xc, -0x26e0(%ebp)\n"
        "movl -0x2718(%ebp), %ecx\n" /* lc */
        "cmpl %ecx, -0x271c(%ebp)\n" /* i */
        "jne .Lf1730d4_0017317b\n"
        "jmp .Lf1730d4_00173257\n"
        ".Lf1730d4_0017367a:\n"
        "cmpl $-0x64, %esi\n" /* line 2899 | field */
        "je .Lf1730d4_00173ee6\n"
        "movl %esi, %eax\n" /* line 2915 | field */
        "negl %eax\n"
        "movl %esi, %ecx\n" /* field */
        "shrl $0x1f, %ecx\n"
        "movl %ecx, -0x270c(%ebp)\n" /* sgn */
        "cmovnel %eax, %esi\n" /* field */
        "movl %esi, %ebx\n" /* line 2916 | field, bit */
        "andl $7, %ebx\n" /* bit */
        "movl %ebx, -0x2708(%ebp)\n" /* bit, partialBits */
        "cmpl $0, %ebx\n" /* line 2917 | bit */
        "jne .Lf1730d4_00173a87\n"
        ".Lf1730d4_001736a9:\n"
        "movl $0, -0x2704(%ebp)\n" /* value */
        ".Lf1730d4_001736b3:\n"
        "cmpl -0x2708(%ebp), %esi\n" /* line 2919 | partialBits, field */
        "jle .Lf1730d4_00173701\n"
        "movl -0x2708(%ebp), %ecx\n" /* partialBits */
        "jmp .Lf1730d4_001736df\n"
        /* { scope 2 */
        ".Lf1730d4_001736c3:\n"
        "movl 4(%edi), %eax\n" /* line 1139 */
        "movzbl (%eax, %edx), %eax\n"
        "addl $1, %edx\n" /* line 1140 */
        "movl %edx, 0x10(%edi)\n"
        /* } scope */
        "shll %cl, %eax\n" /* line 2920 */
        "orl %eax, -0x2704(%ebp)\n" /* value */
        "addl $8, %ecx\n" /* line 2919 */
        "cmpl %ecx, %esi\n" /* field */
        "jle .Lf1730d4_00173701\n"
        /* { scope 2 */
        ".Lf1730d4_001736df:\n"
        "movl 0x10(%edi), %edx\n" /* line 1137 */
        "cmpl 0xc(%edi), %edx\n"
        "jl .Lf1730d4_001736c3\n"
        "movl $1, (%edi)\n" /* line 1143 */
        "movl $0xffffffff, %eax\n"
        /* } scope */
        "shll %cl, %eax\n" /* line 2920 */
        "orl %eax, -0x2704(%ebp)\n" /* value */
        "addl $8, %ecx\n" /* line 2919 */
        "cmpl %ecx, %esi\n" /* field */
        "jg .Lf1730d4_001736df\n"
        ".Lf1730d4_00173701:\n"
        "movl -0x270c(%ebp), %ecx\n" /* line 2922 | sgn */
        "testl %ecx, %ecx\n"
        "jne .Lf1730d4_00173a44\n"
        ".Lf1730d4_0017370f:\n"
        "movl -0x2704(%ebp), %eax\n" /* line 2925 | value */
        "movl -0x26dc(%ebp), %ebx\n" /* bit */
        "movl %eax, (%ebx)\n" /* bit */
        "movl -0x2714(%ebp), %edx\n" /* line 2927 | print */
        "testl %edx, %edx\n"
        "je .Lf1730d4_00173655\n"
        ".Lf1730d4_0017372b:\n"
        "movl %eax, 8(%esp)\n" /* line 2929 */
        "movl -0x26e0(%ebp), %edx\n"
        "movl -4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ad968, (%esp)\n" /* "%s:%i " */
        "calll Com_Printf\n"
        "jmp .Lf1730d4_00173655\n"
        /* { scope 2 */
        ".Lf1730d4_0017374d:\n"
        "movl $1, (%edi)\n" /* line 920 */
        /* } scope */
        ".Lf1730d4_00173753:\n"
        "movl imp_cl_shownet, %eax\n" /* line 2945 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1730d4_00173768\n"
        "cmpl $4, 8(%eax)\n"
        "je .Lf1730d4_00174053\n"
        ".Lf1730d4_00173768:\n"
        "movl $0, -0x26d0(%ebp)\n"
        "xorl %esi, %esi\n" /* field */
        /* { scope 2 */
        ".Lf1730d4_00173774:\n"
        "movl -0x272c(%ebp), %ebx\n" /* line 891 | i */
        "andl $7, %ebx\n" /* i */
        "jne .Lf1730d4_001737a1\n"
        "movl 0x10(%edi), %eax\n" /* line 893 */
        "cmpl 0xc(%edi), %eax\n"
        "jge .Lf1730d4_00173bea\n"
        "leal (, %eax, 8), %edx\n" /* line 898 */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 899 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_001737a1:\n"
        "movl -0x272c(%ebp), %edx\n" /* line 902 */
        "sarl $3, %edx\n"
        "movl 4(%edi), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %ebx, %ecx\n" /* i */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x26d0(%ebp)\n"
        "addl $1, -0x272c(%ebp)\n" /* line 903 */
        "movl -0x272c(%ebp), %ebx\n" /* i */
        "movl %ebx, 0x14(%edi)\n" /* i */
        "addl $1, %esi\n" /* line 888 | i */
        "cmpl $6, %esi\n" /* i */
        "jne .Lf1730d4_00173774\n"
        "movl -0x26d0(%ebp), %eax\n"
        "movl %eax, -0x26f0(%ebp)\n"
        /* } scope */
        "testb $1, %al\n" /* line 2947 */
        "jne .Lf1730d4_00173bfa\n"
        "testb $2, -0x26f0(%ebp)\n" /* line 2949 */
        "jne .Lf1730d4_00173bb9\n"
        ".Lf1730d4_001737fb:\n"
        "testb $4, -0x26f0(%ebp)\n" /* line 2951 */
        "jne .Lf1730d4_00173b85\n"
        ".Lf1730d4_00173808:\n"
        "testb $8, -0x26f0(%ebp)\n" /* line 2953 */
        "je .Lf1730d4_001738a3\n"
        ".Lf1730d4_00173815:\n"
        "movl $0, -0x26fc(%ebp)\n" /* value */
        "xorl %esi, %esi\n" /* field */
        "movl 0x14(%edi), %eax\n" /* msg */
        "movl %eax, -0x272c(%ebp)\n"
        "movl %eax, %ebx\n" /* bit */
        "jmp .Lf1730d4_00173834\n"
        ".Lf1730d4_0017382e:\n"
        "movl -0x272c(%ebp), %ebx\n" /* bit */
        /* { scope 2 */
        ".Lf1730d4_00173834:\n"
        "andl $7, %ebx\n" /* line 891 | i */
        "jne .Lf1730d4_0017385b\n"
        "movl 0x10(%edi), %eax\n" /* line 893 */
        "cmpl 0xc(%edi), %eax\n"
        "jge .Lf1730d4_001740ee\n"
        "leal (, %eax, 8), %edx\n" /* line 898 */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 899 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_0017385b:\n"
        "movl -0x272c(%ebp), %edx\n" /* line 902 */
        "sarl $3, %edx\n"
        "movl 4(%edi), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %ebx, %ecx\n" /* i */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x26fc(%ebp)\n" /* value */
        "addl $1, -0x272c(%ebp)\n" /* line 903 */
        "movl -0x272c(%ebp), %ebx\n" /* i */
        "movl %ebx, 0x14(%edi)\n" /* i */
        "addl $1, %esi\n" /* line 888 | i */
        "cmpl $6, %esi\n" /* i */
        "jne .Lf1730d4_0017382e\n"
        /* } scope */
        ".Lf1730d4_00173894:\n"
        "movl -0x26fc(%ebp), %edx\n" /* line 2954 | value */
        "movl 0x10(%ebp), %eax\n" /* to */
        "movl %edx, 0x138(%eax)\n"
        ".Lf1730d4_001738a3:\n"
        "testb $0x10, -0x26f0(%ebp)\n" /* line 2955 */
        "jne .Lf1730d4_00173b54\n"
        "testb $0x20, -0x26f0(%ebp)\n" /* line 2957 */
        "jne .Lf1730d4_00173b24\n"
        ".Lf1730d4_001738bd:\n"
        "movl 0x14(%edi), %edx\n" /* msg */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, %esi\n" /* field */
        /* { scope 2 */
        "andl $7, %esi\n" /* line 916 | bit */
        "je .Lf1730d4_001732f1\n"
        ".Lf1730d4_001738d1:\n"
        "movl -0x272c(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%edi), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x272c(%ebp)\n" /* line 928 */
        "movl -0x272c(%ebp), %ebx\n" /* bit */
        "movl %ebx, 0x14(%edi)\n" /* bit */
        /* } scope */
        "testb $1, %al\n" /* line 2974 */
        "je .Lf1730d4_001733d3\n"
        "jmp .Lf1730d4_00173303\n"
        /* { scope 2 */
        ".Lf1730d4_00173902:\n"
        "leal (, %edx, 8), %eax\n" /* line 923 */
        "movl %eax, -0x272c(%ebp)\n"
        "movl %eax, 0x14(%edi)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_00173918:\n"
        "movl -0x272c(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%edi), %edx\n"
        "movl %edx, -0x2720(%ebp)\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x272c(%ebp)\n" /* line 928 */
        "movl -0x272c(%ebp), %ebx\n" /* bit */
        "movl %ebx, 0x14(%edi)\n" /* bit */
        /* } scope */
        "testb $1, %al\n" /* line 2875 */
        "jne .Lf1730d4_00174096\n"
        "movl $0, -0x2710(%ebp)\n" /* trunc */
        "xorl %esi, %esi\n" /* field */
        /* { scope 2 */
        ".Lf1730d4_00173956:\n"
        "movl -0x272c(%ebp), %ebx\n" /* line 891 | i */
        "andl $7, %ebx\n" /* i */
        "jne .Lf1730d4_00173983\n"
        "movl 0x10(%edi), %edx\n" /* line 893 */
        "cmpl 0xc(%edi), %edx\n"
        "jge .Lf1730d4_001740d9\n"
        "leal (, %edx, 8), %eax\n" /* line 898 */
        "movl %eax, -0x272c(%ebp)\n"
        "movl %eax, 0x14(%edi)\n"
        "addl $1, %edx\n" /* line 899 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_00173983:\n"
        "movl -0x272c(%ebp), %eax\n" /* line 902 */
        "sarl $3, %eax\n"
        "movl -0x2720(%ebp), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %ebx, %ecx\n" /* i */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x2710(%ebp)\n" /* trunc */
        "addl $1, -0x272c(%ebp)\n" /* line 903 */
        "movl -0x272c(%ebp), %ebx\n" /* i */
        "movl %ebx, 0x14(%edi)\n" /* i */
        "addl $1, %esi\n" /* line 888 | i */
        "cmpl $5, %esi\n" /* i */
        "jne .Lf1730d4_00173956\n"
        "movl 0x10(%edi), %edx\n"
        /* } scope */
        ".Lf1730d4_001739c2:\n"
        "cmpl 0xc(%edi), %edx\n" /* line 1137 */
        "jge .Lf1730d4_00173f83\n"
        "movl -0x2720(%ebp), %ecx\n" /* line 1139 */
        "movzbl (%ecx, %edx), %eax\n"
        "addl $1, %edx\n" /* line 1140 */
        "movl %edx, 0x10(%edi)\n"
        "shll $5, %eax\n"
        ".Lf1730d4_001739de:\n"
        "movl -0x2710(%ebp), %ebx\n" /* line 2882 | trunc, bit */
        "leal -0x1000(%ebx, %eax), %eax\n" /* bit */
        "cvtsi2ssl %eax, %xmm0\n" /* line 2883 */
        "movl -0x26dc(%ebp), %edx\n"
        "movss %xmm0, (%edx)\n"
        "movl -0x2714(%ebp), %edx\n" /* line 2884 | print */
        "testl %edx, %edx\n"
        "je .Lf1730d4_00173655\n"
        "movl %eax, 8(%esp)\n" /* line 2886 */
        "movl -0x26e0(%ebp), %ecx\n"
        "movl -4(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ad968, (%esp)\n" /* "%s:%i " */
        "calll Com_Printf\n"
        "jmp .Lf1730d4_00173655\n"
        ".Lf1730d4_00173a29:\n"
        "movl $1, (%edi)\n" /* line 1143 */
        "movl $0xffffffff, -0x2718(%ebp)\n" /* lc */
        ".Lf1730d4_00173a39:\n"
        "movl -0x2718(%ebp), %ebx\n" /* lc, bit */
        "jmp .Lf1730d4_00173259\n"
        ".Lf1730d4_00173a44:\n"
        "leal -1(%esi), %ecx\n" /* line 2922 | field */
        "movl -0x2704(%ebp), %eax\n" /* value */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1730d4_0017370f\n"
        "movl $0xffffffff, %eax\n" /* line 2923 */
        "movl %esi, %ecx\n" /* field */
        "shll %cl, %eax\n"
        "orl %eax, -0x2704(%ebp)\n" /* value */
        "movl -0x2704(%ebp), %eax\n" /* line 2925 | value */
        "movl -0x26dc(%ebp), %ebx\n" /* bit */
        "movl %eax, (%ebx)\n" /* bit */
        "movl -0x2714(%ebp), %edx\n" /* line 2927 | print */
        "testl %edx, %edx\n"
        "je .Lf1730d4_00173655\n"
        "jmp .Lf1730d4_0017372b\n"
        /* { scope 2 */
        ".Lf1730d4_00173a87:\n"
        "jle .Lf1730d4_001736a9\n" /* line 888 */
        /* } scope */
        "xorl %ebx, %ebx\n" /* line 2917 | bit */
        "movl $0, -0x2704(%ebp)\n" /* value */
        "jmp .Lf1730d4_00173af6\n"
        /* { scope 2 */
        ".Lf1730d4_00173a9b:\n"
        "leal (, %eax, 8), %edx\n" /* line 898 */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 899 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_00173ab1:\n"
        "movl -0x272c(%ebp), %edx\n" /* line 902 */
        "sarl $3, %edx\n"
        "movl 4(%edi), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movzbl -0x2700(%ebp), %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %ebx, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "orl %eax, -0x2704(%ebp)\n" /* value */
        "addl $1, -0x272c(%ebp)\n" /* line 903 */
        "movl -0x272c(%ebp), %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "addl $1, %ebx\n" /* line 888 | i */
        "cmpl %ebx, -0x2708(%ebp)\n" /* i, partialBits */
        "je .Lf1730d4_001736b3\n"
        ".Lf1730d4_00173af6:\n"
        "movl -0x272c(%ebp), %eax\n" /* line 891 */
        "andl $7, %eax\n"
        "movl %eax, -0x2700(%ebp)\n" /* bit */
        "jne .Lf1730d4_00173ab1\n"
        "movl 0x10(%edi), %eax\n" /* line 893 */
        "cmpl 0xc(%edi), %eax\n"
        "jl .Lf1730d4_00173a9b\n"
        "movl $1, (%edi)\n" /* line 895 */
        "movl $0xffffffff, -0x2704(%ebp)\n" /* value */
        "jmp .Lf1730d4_001736b3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173b24:\n"
        "movl 0x10(%edi), %edx\n" /* line 1137 */
        "cmpl 0xc(%edi), %edx\n"
        "jl .Lf1730d4_00174041\n"
        "movl $1, (%edi)\n" /* line 1143 */
        "movl $0xffffffff, %eax\n"
        /* } scope */
        ".Lf1730d4_00173b3b:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 2958 | to, bit */
        "movl %eax, 0x140(%ebx)\n" /* bit */
        "movl 0x14(%edi), %eax\n" /* msg */
        "movl %eax, -0x272c(%ebp)\n"
        "movl %eax, %esi\n" /* field */
        "jmp .Lf1730d4_001732e8\n"
        /* { scope 2 */
        ".Lf1730d4_00173b54:\n"
        "movl 0x10(%edi), %ecx\n" /* line 1153 */
        "leal 2(%ecx), %edx\n"
        "cmpl 0xc(%edi), %edx\n" /* line 1154 */
        "jg .Lf1730d4_00174031\n"
        "movl 4(%edi), %eax\n" /* line 1156 */
        "movswl (%eax, %ecx), %eax\n"
        "movl %edx, 0x10(%edi)\n" /* line 1157 */
        /* } scope */
        ".Lf1730d4_00173b6d:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2956 | to */
        "movl %eax, 0x13c(%ecx)\n"
        "testb $0x20, -0x26f0(%ebp)\n" /* line 2957 */
        "je .Lf1730d4_001738bd\n"
        "jmp .Lf1730d4_00173b24\n"
        /* { scope 2 */
        ".Lf1730d4_00173b85:\n"
        "movl 0x10(%edi), %ecx\n" /* line 1153 */
        "leal 2(%ecx), %edx\n"
        "cmpl 0xc(%edi), %edx\n" /* line 1154 */
        "jg .Lf1730d4_00174011\n"
        "movl 4(%edi), %eax\n" /* line 1156 */
        "movswl (%eax, %ecx), %eax\n"
        "movl %edx, 0x10(%edi)\n" /* line 1157 */
        /* } scope */
        ".Lf1730d4_00173b9e:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 2952 | to, bit */
        "movl %eax, 0x134(%ebx)\n" /* bit */
        "testb $8, -0x26f0(%ebp)\n" /* line 2953 */
        "je .Lf1730d4_001738a3\n"
        "jmp .Lf1730d4_00173815\n"
        /* { scope 2 */
        ".Lf1730d4_00173bb9:\n"
        "movl 0x10(%edi), %ecx\n" /* line 1153 */
        "leal 2(%ecx), %edx\n"
        "cmpl 0xc(%edi), %edx\n" /* line 1154 */
        "jg .Lf1730d4_00174021\n"
        "movl 4(%edi), %eax\n" /* line 1156 */
        "movswl (%eax, %ecx), %eax\n"
        "movl %edx, 0x10(%edi)\n" /* line 1157 */
        /* } scope */
        ".Lf1730d4_00173bd2:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2950 | to */
        "movl %eax, 0x130(%ecx)\n"
        "testb $4, -0x26f0(%ebp)\n" /* line 2951 */
        "je .Lf1730d4_00173808\n"
        "jmp .Lf1730d4_00173b85\n"
        /* { scope 2 */
        ".Lf1730d4_00173bea:\n"
        "movl $1, (%edi)\n" /* line 895 */
        "movl $0xffffffff, -0x26f0(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173bfa:\n"
        "movl 0x10(%edi), %ecx\n" /* line 1153 */
        "leal 2(%ecx), %edx\n"
        "cmpl 0xc(%edi), %edx\n" /* line 1154 */
        "jg .Lf1730d4_00174001\n"
        "movl 4(%edi), %eax\n" /* line 1156 */
        "movswl (%eax, %ecx), %eax\n"
        "movl %edx, 0x10(%edi)\n" /* line 1157 */
        /* } scope */
        ".Lf1730d4_00173c13:\n"
        "movl 0x10(%ebp), %edx\n" /* line 2948 | to */
        "movl %eax, 0x12c(%edx)\n"
        "testb $2, -0x26f0(%ebp)\n" /* line 2949 */
        "je .Lf1730d4_001737fb\n"
        "jmp .Lf1730d4_00173bb9\n"
        /* { scope 2 */
        ".Lf1730d4_00173c2b:\n"
        "movl $1, (%edi)\n" /* line 1160 */
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1730d4_00173472\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1730d4_00173c3b:\n"
        "leal (, %eax, 8), %edx\n" /* line 923 */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 924 */
        "movl %edx, 0x10(%edi)\n"
        "movl -0x272c(%ebp), %eax\n"
        ".Lf1730d4_00173c57:\n"
        "sarl $3, %eax\n" /* line 927 */
        "movl 4(%edi), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x272c(%ebp)\n" /* line 928 */
        "movl -0x272c(%ebp), %ebx\n" /* bit */
        "movl %ebx, 0x14(%edi)\n" /* bit */
        /* } scope */
        "testb $1, %al\n" /* line 2281 */
        "jne .Lf1730d4_001735ae\n"
        "movl $objectiveFields+4, %ecx\n" /* line 2283 */
        ".Lf1730d4_00173c82:\n"
        "movl (%ecx), %edx\n" /* line 2292 */
        "movl (%esi, %edx), %eax\n" /* line 2294 | bit */
        "movl -0x26f4(%ebp), %ebx\n" /* to, bit */
        "movl %eax, (%ebx, %edx)\n" /* bit */
        "addl $0xc, %ecx\n"
        "cmpl $objectiveFields+76, %ecx\n" /* line 2289 */
        "jne .Lf1730d4_00173c82\n"
        /* } scope */
        "addl $1, -0x26cc(%ebp)\n" /* line 3013 */
        "addl $0x1c, -0x26ec(%ebp)\n"
        "cmpl $0x10, -0x26cc(%ebp)\n"
        "jne .Lf1730d4_001735fb\n"
        ".Lf1730d4_00173cb6:\n"
        "movl 0x14(%edi), %eax\n" /* msg */
        "movl %eax, -0x272c(%ebp)\n"
        "movl %eax, %esi\n" /* field */
        /* { scope 2 */
        "andl $7, %esi\n" /* line 916 | bit */
        "je .Lf1730d4_00173e8e\n"
        ".Lf1730d4_00173cca:\n"
        "movl -0x272c(%ebp), %edx\n" /* line 927 */
        "sarl $3, %edx\n"
        "movl 4(%edi), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "movl -0x272c(%ebp), %edx\n" /* line 928 */
        "addl $1, %edx\n"
        "movl %edx, 0x14(%edi)\n"
        /* } scope */
        "testb $1, %al\n" /* line 3022 */
        "je .Lf1730d4_00173d6a\n"
        ".Lf1730d4_00173cee:\n"
        "movl $0x1f, %eax\n"
        ".Lf1730d4_00173cf3:\n"
        "subl $1, %eax\n" /* line 2533 | i */
        "jne .Lf1730d4_00173cf3\n"
        "movl $0x1f, %eax\n" /* i */
        ".Lf1730d4_00173cfd:\n"
        "subl $1, %eax\n" /* i */
        "jne .Lf1730d4_00173cfd\n"
        "movl 0x10(%ebp), %ecx\n" /* line 3029 | to */
        "addl $0x1728, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* from */
        "addl $0x1728, %edx\n"
        "movl $0x1f, (%esp)\n"
        "movl %edi, %eax\n" /* msg */
        "calll MSG_ReadDeltaHudElems\n"
        "movl 0x10(%ebp), %ecx\n" /* line 3030 | to */
        "addl $0x7a8, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* from */
        "addl $0x7a8, %edx\n"
        "movl $0x1f, (%esp)\n"
        "movl %edi, %eax\n" /* msg */
        "calll MSG_ReadDeltaHudElems\n"
        "xorl %eax, %eax\n"
        /* { scope 2 */
        ".Lf1730d4_00173d44:\n"
        "addl $1, %eax\n" /* line 2533 | i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf1730d4_00173d44\n"
        "xorb %al, %al\n" /* i */
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173d4e:\n"
        "addl $1, %eax\n" /* i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf1730d4_00173d4e\n"
        "xorb %al, %al\n" /* i */
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173d58:\n"
        "addl $1, %eax\n" /* i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf1730d4_00173d58\n"
        "xorb %al, %al\n" /* i */
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173d62:\n"
        "addl $1, %eax\n" /* i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf1730d4_00173d62\n"
        /* } scope */
        /* } scope */
        ".Lf1730d4_00173d6a:\n"
        "addl $0x274c, %esp\n" /* line 3040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value, to, value, bit */
        /* { scope 2 */
        ".Lf1730d4_00173d75:\n"
        "movl $1, (%edi)\n" /* line 1160 */
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1730d4_001733a2\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173d85:\n"
        "leal (, %eax, 8), %edx\n" /* line 923 */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 924 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_00173d9b:\n"
        "movl -0x272c(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%edi), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x272c(%ebp)\n" /* line 928 */
        "movl -0x272c(%ebp), %ebx\n" /* bit */
        "movl %ebx, 0x14(%edi)\n" /* bit */
        /* } scope */
        "testb $1, %al\n" /* line 2996 */
        "je .Lf1730d4_00173488\n"
        "jmp .Lf1730d4_0017340c\n"
        /* { scope 2 */
        ".Lf1730d4_00173dcc:\n"
        "leal (, %eax, 8), %edx\n" /* line 923 */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 924 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_00173de2:\n"
        "movl -0x272c(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%edi), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x272c(%ebp)\n" /* line 928 */
        "movl -0x272c(%ebp), %ebx\n" /* bit */
        "movl %ebx, 0x14(%edi)\n" /* bit */
        /* } scope */
        "testb $1, %al\n" /* line 2978 */
        "je .Lf1730d4_001733b8\n"
        "jmp .Lf1730d4_0017333c\n"
        /* { scope 2 */
        ".Lf1730d4_00173e13:\n"
        "movl $1, (%edi)\n" /* line 1160 */
        "movl $0xffffffff, -0x26d4(%ebp)\n"
        "jmp .Lf1730d4_00173440\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173e28:\n"
        "movl $1, (%edi)\n"
        "movl $0xffffffff, -0x26d8(%ebp)\n"
        "jmp .Lf1730d4_00173370\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173e3d:\n"
        "leal (, %eax, 8), %edx\n" /* line 923 */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 924 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_00173e53:\n"
        "movl -0x272c(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%edi), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x272c(%ebp)\n" /* line 928 */
        "movl -0x272c(%ebp), %ebx\n" /* bit */
        "movl %ebx, 0x14(%edi)\n" /* bit */
        /* } scope */
        "testb $1, %al\n" /* line 3011 */
        "jne .Lf1730d4_001734c4\n"
        "movl -0x272c(%ebp), %esi\n" /* field */
        /* { scope 2 */
        "andl $7, %esi\n" /* line 916 | bit */
        "jne .Lf1730d4_00173cca\n"
        ".Lf1730d4_00173e8e:\n"
        "movl 0x10(%edi), %eax\n" /* line 918 */
        "cmpl 0xc(%edi), %eax\n"
        "jl .Lf1730d4_00173fae\n"
        "movl $1, (%edi)\n" /* line 920 */
        "jmp .Lf1730d4_00173cee\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173ea5:\n"
        "movl $1, (%edi)\n" /* line 895 */
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1730d4_0017354f\n"
        /* } scope */
        ".Lf1730d4_00173eb5:\n"
        "cmpl $-2, %eax\n" /* line 2846 */
        "je .Lf1730d4_00173123\n"
        ".Lf1730d4_00173ebe:\n"
        "movl $0, -0x2714(%ebp)\n" /* print */
        "jmp .Lf1730d4_00173140\n"
        ".Lf1730d4_00173ecd:\n"
        "movl $str_002ad9c4, 4(%esp)\n" /* line 2998 */
        "movl $str_002ad9b8, (%esp)\n" /* "%s " */
        "calll Com_Printf\n"
        "jmp .Lf1730d4_00173421\n"
        /* { scope 2 */
        ".Lf1730d4_00173ee6:\n"
        "movl -0x272c(%ebp), %ebx\n" /* line 916 | bit */
        "andl $7, %ebx\n" /* bit */
        "jne .Lf1730d4_00173f46\n"
        "movl 0x10(%edi), %edx\n" /* line 918 */
        "cmpl 0xc(%edi), %edx\n"
        "jl .Lf1730d4_00173f30\n"
        "movl $1, (%edi)\n" /* line 920 */
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173eff:\n"
        "leal 2(%edx), %ecx\n" /* line 1153 */
        "cmpl 0xc(%edi), %ecx\n" /* line 1154 */
        "jg .Lf1730d4_001740c6\n"
        "movl 4(%edi), %eax\n" /* line 1156 */
        "movswl (%eax, %edx), %eax\n"
        "movl %ecx, 0x10(%edi)\n" /* line 1157 */
        "cvtsi2ssl %eax, %xmm0\n"
        /* } scope */
        ".Lf1730d4_00173f19:\n"
        "mulss lit4_002ed648, %xmm0\n" /* line 2908 | 0.0054931640625f */
        "movl -0x26dc(%ebp), %edx\n"
        "movss %xmm0, (%edx)\n"
        "jmp .Lf1730d4_00173655\n"
        /* { scope 2 */
        ".Lf1730d4_00173f30:\n"
        "leal (, %edx, 8), %ecx\n" /* line 923 */
        "movl %ecx, -0x272c(%ebp)\n"
        "movl %ecx, 0x14(%edi)\n"
        "addl $1, %edx\n" /* line 924 */
        "movl %edx, 0x10(%edi)\n"
        ".Lf1730d4_00173f46:\n"
        "movl -0x272c(%ebp), %eax\n" /* line 927 */
        "sarl $3, %eax\n"
        "movl 4(%edi), %edx\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "addl $1, -0x272c(%ebp)\n" /* line 928 */
        "movl -0x272c(%ebp), %ebx\n" /* bit */
        "movl %ebx, 0x14(%edi)\n" /* bit */
        /* } scope */
        "testb $1, %al\n" /* line 2902 */
        "jne .Lf1730d4_00174075\n"
        "movl -0x26dc(%ebp), %eax\n" /* line 2904 */
        "movl $0, (%eax)\n"
        "jmp .Lf1730d4_00173655\n"
        ".Lf1730d4_00173f83:\n"
        "movl $1, (%edi)\n" /* line 1143 */
        "movl $0xffffffe0, %eax\n"
        "jmp .Lf1730d4_001739de\n"
        /* { scope 2 */
        ".Lf1730d4_00173f93:\n"
        "leal (, %eax, 8), %ecx\n" /* line 923 */
        "movl %ecx, -0x272c(%ebp)\n"
        "movl %ecx, 0x14(%edi)\n"
        "leal 1(%eax), %edx\n" /* line 924 */
        "movl %edx, 0x10(%edi)\n"
        "jmp .Lf1730d4_001738d1\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00173fae:\n"
        "leal (, %eax, 8), %edx\n" /* line 923 */
        "movl %edx, -0x272c(%ebp)\n"
        "movl %edx, 0x14(%edi)\n"
        "addl $1, %eax\n" /* line 924 */
        "movl %eax, 0x10(%edi)\n"
        "movl -0x272c(%ebp), %edx\n" /* line 927 */
        "sarl $3, %edx\n"
        "movl 4(%edi), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "sarl %cl, %eax\n"
        "movl -0x272c(%ebp), %edx\n" /* line 928 */
        "addl $1, %edx\n"
        "movl %edx, 0x14(%edi)\n"
        /* } scope */
        "testb $1, %al\n" /* line 3022 */
        "jne .Lf1730d4_00173cee\n"
        "jmp .Lf1730d4_00173d6a\n"
        /* { scope 2 */
        ".Lf1730d4_00173ff1:\n"
        "movl $1, (%edi)\n" /* line 1177 */
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1730d4_001731fe\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00174001:\n"
        "movl $1, (%edi)\n" /* line 1160 */
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1730d4_00173c13\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00174011:\n"
        "movl $1, (%edi)\n"
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1730d4_00173b9e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00174021:\n"
        "movl $1, (%edi)\n"
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1730d4_00173bd2\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00174031:\n"
        "movl $1, (%edi)\n"
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1730d4_00173b6d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_00174041:\n"
        "movl 4(%edi), %eax\n" /* line 1139 */
        "movzbl (%eax, %edx), %eax\n"
        "addl $1, %edx\n" /* line 1140 */
        "movl %edx, 0x10(%edi)\n"
        "jmp .Lf1730d4_00173b3b\n"
        /* } scope */
        ".Lf1730d4_00174053:\n"
        "movl $str_002ad9ac, 4(%esp)\n" /* line 2945 */
        "movl $str_002ad9b8, (%esp)\n" /* "%s " */
        "calll Com_Printf\n"
        "movl 0x14(%edi), %eax\n" /* msg */
        "movl %eax, -0x272c(%ebp)\n"
        "jmp .Lf1730d4_00173768\n"
        ".Lf1730d4_00174075:\n"
        "movl 0x10(%edi), %edx\n" /* msg */
        "jmp .Lf1730d4_00173eff\n"
        ".Lf1730d4_0017407d:\n"
        "movl $str_002ad9bc, 4(%esp)\n" /* line 2980 */
        "movl $str_002ad9b8, (%esp)\n" /* "%s " */
        "calll Com_Printf\n"
        "jmp .Lf1730d4_00173351\n"
        ".Lf1730d4_00174096:\n"
        "movl 0x10(%edi), %edx\n" /* msg */
        "jmp .Lf1730d4_001731e9\n"
        ".Lf1730d4_0017409e:\n"
        "leal -0x26c0(%ebp), %ebx\n" /* line 2839 | dummy, bit */
        "movl $0x26a8, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* bit */
        "calll memset\n"
        "movl %ebx, 0xc(%ebp)\n" /* bit, from */
        "movl %ebx, %eax\n" /* bit */
        "jmp .Lf1730d4_001730f1\n"
        /* { scope 2 */
        ".Lf1730d4_001740c6:\n"
        "movl $1, (%edi)\n" /* line 1160 */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        "jmp .Lf1730d4_00173f19\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_001740d9:\n"
        "movl $1, (%edi)\n" /* line 895 */
        "movl $0xffffffff, -0x2710(%ebp)\n" /* trunc */
        "jmp .Lf1730d4_001739c2\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1730d4_001740ee:\n"
        "movl $1, (%edi)\n"
        "movl $0xffffffff, -0x26fc(%ebp)\n" /* value */
        "jmp .Lf1730d4_00173894\n"
    );
}

/* line 1648 */
/*
 * MSG_ReadDeltaUsercmdKey — C rewrite (fix #152)
 *
 * The decompiled version was severely truncated (8 jumps to raw Mac addresses,
 * missing function epilogue). Rewritten based on analysis of the matching
 * MSG_WriteDeltaUsercmdKey and Q3 reference.
 *
 * Encoding (from MSG_WriteDeltaUsercmdKey analysis):
 *   1 bit: serverTime format (1=byte delta, 0=absolute 32-bit)
 *   [8 or 32 bits: serverTime value]
 *   1 bit: delta flag XOR'd with key bit 0 (match=no delta, mismatch=delta)
 *   If no delta: done (from already copied to to)
 *   If delta:
 *     1 bit: buttons bit 0 flag XOR'd with key bit 0
 *     1 bit: (modKey ^ buttons) bit 0
 *     1+16 bits: angles[0] if changed (flag bit + value XOR'd with modKey)
 *     1+16 bits: angles[1] if changed
 *     1+4 bits: horToMove if changed (movement direction encoding)
 *   Where modKey = key ^ to->serverTime (byte-delta path)
 *         modKey = key (absolute path, first fields)
 *
 * Note: caller pushes only 4 args (msg, key, from, to). The 9-param
 * declaration from the decompiler was wrong.
 */
static int MSG_ReadDeltaKeyField(msg_t *msg, int key, int oldV, int bits)
{
    if (MSG_ReadBit(msg) != (key & kbitmask[1])) {
        return MSG_ReadBits(msg, bits) ^ (key & kbitmask[bits]);
    }
    return oldV;
}

void MSG_ReadDeltaUsercmdKey(msg_t *msg, int key, usercmd_t *from, usercmd_t *to)
{
    int modKey;

    /* Step 1: Copy from → to (7 dwords = 28 bytes) */
    *to = *from;

    /* Step 2: Read serverTime */
    if (MSG_ReadBit(msg)) {
        /* Byte-delta serverTime */
        to->serverTime = from->serverTime + MSG_ReadByte(msg);
    } else {
        /* Absolute serverTime */
        to->serverTime = MSG_ReadLong(msg);
    }

    /* Step 3: Read delta-present flag (XOR'd with key) */
    if (MSG_ReadBit(msg) == (key & 1)) {
        /* No delta — from already copied to to */
        return;
    }

    /* Delta present */
    /* Step 4: Handle buttons bit 0 */
    to->buttons &= ~1;
    if (MSG_ReadBit(msg) != (key & 1)) {
        to->buttons |= 1;
    }

    /* Step 5: Compute modKey */
    modKey = key ^ to->serverTime;

    /* Step 6: Read one more bit (modKey ^ buttons flag) */
    {
        int bit = MSG_ReadBit(msg);
        if (bit != (modKey & 1)) {
            /* buttons upper bits changed — read them */
            /* From the write analysis, this just means there IS a buttons change.
             * The actual buttons value comes from subsequent field reads. */
        }
        /* Whether or not this bit matched, we continue reading delta fields.
         * The bit is informational for the decoder. */
    }

    /* Step 7: Read delta fields */
    /* angles[0] — 16 bit delta */
    to->angles[0] = MSG_ReadDeltaKeyField(msg, modKey, from->angles[0], 16);
    /* angles[1] — 16 bit delta */
    to->angles[1] = MSG_ReadDeltaKeyField(msg, modKey, from->angles[1], 16);
    /* horToMove — 4 bit packed movement direction */
    {
        int horFromMove = 0;
        int horToMove;
        /* Compute horFromMove from from->forwardmove/rightmove */
        if ((signed char)from->forwardmove > 10)
            horFromMove = 1;
        else if ((signed char)from->forwardmove <= -11)
            horFromMove = 2;
        if ((signed char)from->rightmove > 10)
            horFromMove |= 4;
        else if ((signed char)from->rightmove <= -11)
            horFromMove |= 8;

        /* Read horToMove delta (4 bits) */
        if (MSG_ReadBit(msg) != (modKey & 1)) {
            /* Changed — read 4 bits */
            horToMove = MSG_ReadBits(msg, 4) ^ (modKey & 0xf);
        } else {
            horToMove = horFromMove;
        }
        /* Decode horToMove to forwardmove/rightmove */
        if (horToMove & 1)
            to->forwardmove = 127;
        else if (horToMove & 2)
            to->forwardmove = -127;
        else
            to->forwardmove = 0;

        if (horToMove & 4)
            to->rightmove = 127;
        else if (horToMove & 8)
            to->rightmove = -127;
        else
            to->rightmove = 0;
    }
}

/* line 1558 */
__attribute__((naked))
void MSG_WriteDeltaUsercmdKey(msg_t *msg, int key, usercmd_t *from, usercmd_t *to)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1558 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 0x14(%ebp), %eax\n" /* line 1577 | to */
        "movl (%eax), %edx\n"
        "movl 0x10(%ebp), %ecx\n" /* from */
        "subl (%ecx), %edx\n"
        "cmpl $0xff, %edx\n" /* line 1578 */
        "ja .Lf174d52_00174ff8\n"
        /* { scope 2 */
        "movl 8(%ebp), %ebx\n" /* line 860 | msg, bit */
        "movl 0xc(%ebx), %esi\n" /* bit */
        "cmpl 8(%ebx), %esi\n" /* bit */
        "jl .Lf174d52_00175307\n"
        "movl $1, (%ebx)\n" /* line 862 | bit */
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 992 | msg */
        "cmpl 8(%ecx), %esi\n"
        "jge .Lf174d52_00175349\n"
        ".Lf174d52_00174d92:\n"
        "movl 4(%ecx), %eax\n" /* line 994 */
        "movb %dl, (%eax, %esi)\n"
        "movl 0xc(%ecx), %esi\n" /* line 995 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ecx)\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1590 | to */
        "movzbl 0x19(%ecx), %edx\n"
        "movzbl 0x18(%ecx), %eax\n"
        "cmpb $0xa, %al\n" /* line 1519 */
        "jg .Lf174d52_00175041\n"
        ".Lf174d52_00174db4:\n"
        "cmpb $0xf5, %al\n" /* line 1521 */
        "setle %al\n"
        "movzbl %al, %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* horToMove */
        "cmpb $0xa, %dl\n" /* line 1524 */
        "jg .Lf174d52_00175051\n"
        ".Lf174d52_00174dca:\n"
        "movl -0x18(%ebp), %eax\n" /* line 1527 | horToMove */
        "orl $8, %eax\n"
        "cmpb $0xf5, %dl\n"
        "cmovgl -0x18(%ebp), %eax\n" /* horToMove */
        "movl %eax, -0x18(%ebp)\n" /* horToMove */
        "movl 0x10(%ebp), %ebx\n" /* line 1591 | from, value */
        "movzbl 0x19(%ebx), %edx\n" /* value */
        "movzbl 0x18(%ebx), %eax\n" /* value */
        "cmpb $0xa, %al\n" /* line 1519 */
        "jg .Lf174d52_00175068\n"
        ".Lf174d52_00174ded:\n"
        "cmpb $0xf5, %al\n" /* line 1521 */
        "setle %al\n"
        "movzbl %al, %edi\n" /* bit */
        "addl %edi, %edi\n" /* bit */
        "cmpb $0xa, %dl\n" /* line 1524 */
        "jg .Lf174d52_00175076\n"
        ".Lf174d52_00174e00:\n"
        "movl %edi, %eax\n" /* line 1527 | bit */
        "orl $8, %eax\n"
        "cmpb $0xf5, %dl\n"
        "cmovlel %eax, %edi\n" /* bit */
        "movl 0x10(%ebp), %eax\n" /* line 1597 | from */
        "movl 4(%eax), %ebx\n" /* value */
        "movl 0x14(%ebp), %edx\n" /* to */
        "movl 4(%edx), %ecx\n"
        "movl %ebx, %edx\n" /* value */
        "sarl $1, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf174d52_00175095\n"
        ".Lf174d52_00174e27:\n"
        "movl 0x10(%ebp), %edx\n" /* from */
        "movzwl 8(%edx), %eax\n"
        "movl 0x14(%ebp), %edx\n" /* to */
        "cmpw 8(%edx), %ax\n"
        "jne .Lf174d52_00175095\n"
        "movl 0x10(%ebp), %edx\n" /* from */
        "movl 0x14(%edx), %eax\n"
        "movl 0x14(%ebp), %edx\n" /* to */
        "cmpl 0x14(%edx), %eax\n"
        "jne .Lf174d52_00175095\n"
        "movl 0x10(%ebp), %edx\n" /* line 1599 | from */
        "movl 0xc(%edx), %eax\n"
        "movl 0x14(%ebp), %edx\n" /* to */
        "cmpl 0xc(%edx), %eax\n"
        "je .Lf174d52_001760d6\n"
        ".Lf174d52_00174e5f:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1353 | key, value */
        "xorl $1, %ebx\n" /* value */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 810 | msg */
        "movl 8(%eax), %edx\n"
        "movl %edx, %eax\n"
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf174d52_00175edd\n"
        "movl 8(%ebp), %ecx\n" /* line 812 | msg */
        "movl $1, (%ecx)\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00174e81:\n"
        "movl %edx, %eax\n" /* line 810 */
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf174d52_00175e67\n"
        "movl 8(%ebp), %eax\n" /* line 812 | msg */
        "movl $1, (%eax)\n"
        /* } scope */
        ".Lf174d52_00174e97:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1607 | key */
        "movl 0x14(%ebp), %eax\n" /* to */
        "xorl (%eax), %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl %ecx, %ebx\n" /* line 1353 | value */
        "xorl 4(%eax), %ebx\n" /* value */
        /* { scope 2 */
        /* { scope 3 */
        "subl %esi, %edx\n" /* line 810 */
        "cmpl $3, %edx\n"
        "jg .Lf174d52_00175df0\n"
        "movl 8(%ebp), %ebx\n" /* line 812 | msg */
        "movl $1, (%ebx)\n"
        /* } scope */
        /* } scope */
        ".Lf174d52_00174ebb:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1609 | to */
        "movl 0xc(%eax), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ecx\n" /* line 1387 | from */
        "cmpw %dx, 0xc(%ecx)\n"
        "je .Lf174d52_00176072\n"
        /* { scope 3 */
        "movl 8(%ebp), %ecx\n" /* line 860 | msg */
        "cmpl 8(%ecx), %esi\n"
        "jl .Lf174d52_00175fba\n"
        "movl $1, (%ecx)\n" /* line 862 */
        /* } scope */
        ".Lf174d52_00174ee0:\n"
        "movl -0x10(%ebp), %ecx\n" /* line 1393 | c */
        "xorl %edx, %ecx\n" /* c */
        /* { scope 3 */
        /* { scope 4 */
        "leal 2(%esi), %edx\n" /* line 1023 */
        "movl 8(%ebp), %ebx\n" /* line 1024 | msg, bit */
        "cmpl 8(%ebx), %edx\n" /* bit */
        "jg .Lf174d52_00175faf\n"
        "movl 4(%ebx), %eax\n" /* line 1026 | bit */
        "movw %cx, (%eax, %esi)\n"
        "movl %edx, %esi\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n" /* bit */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf174d52_00174f00:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1610 | to */
        "movl 0x10(%ecx), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 1387 | from, value */
        "cmpw %dx, 0x10(%ebx)\n" /* value */
        "je .Lf174d52_0017611b\n"
        /* { scope 3 */
        "movl 8(%ebp), %ebx\n" /* line 860 | msg, bit */
        "cmpl 8(%ebx), %esi\n" /* bit */
        "jl .Lf174d52_0017601a\n"
        "movl $1, (%ebx)\n" /* line 862 | bit */
        /* } scope */
        ".Lf174d52_00174f25:\n"
        "movl -0x10(%ebp), %ecx\n" /* line 1393 | c */
        "xorl %edx, %ecx\n" /* c */
        /* { scope 3 */
        /* { scope 4 */
        "leal 2(%esi), %edx\n" /* line 1023 */
        "movl 8(%ebp), %ebx\n" /* line 1024 | msg, bit */
        "cmpl 8(%ebx), %edx\n" /* bit */
        "jg .Lf174d52_0017600d\n"
        "movl 4(%ebx), %eax\n" /* line 1026 | bit */
        "movw %cx, (%eax, %esi)\n"
        "movl %edx, %esi\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n" /* bit */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf174d52_00174f45:\n"
        "cmpl %edi, -0x18(%ebp)\n" /* line 1331 | bit, horToMove */
        "je .Lf174d52_00176089\n"
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 860 | msg */
        "cmpl 8(%edx), %esi\n"
        "jl .Lf174d52_00175f57\n"
        "movl $1, (%edx)\n" /* line 862 */
        /* } scope */
        ".Lf174d52_00174f60:\n"
        "movl -0x18(%ebp), %ebx\n" /* line 1337 | horToMove, value */
        "xorl -0x10(%ebp), %ebx\n" /* value */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %edx\n" /* line 810 | msg */
        "movl 8(%edx), %eax\n"
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jle .Lf174d52_001752be\n"
        "movl $4, %esi\n" /* line 812 */
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edi\n" /* bit */
        "andl $7, %edi\n" /* line 820 | bit */
        "jne .Lf174d52_00174fad\n"
        ".Lf174d52_00174f89:\n"
        "movl 8(%ebp), %eax\n" /* line 822 | msg */
        "movl 0xc(%eax), %edx\n"
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 823 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ecx)\n" /* line 824 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00174fad:\n"
        "testb $1, %bl\n" /* line 827 */
        "je .Lf174d52_00174fd6\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 4(%edx), %edx\n"
        "addl %edx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 0x14(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lf174d52_00174fd6:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %edx, 0x14(%eax)\n"
        "sarl $1, %ebx\n" /* line 830 */
        "subl $1, %esi\n" /* line 816 */
        "je .Lf174d52_001752c4\n"
        "movl -0x1c(%ebp), %edi\n" /* bit */
        "andl $7, %edi\n" /* line 820 | bit */
        "jne .Lf174d52_00174fad\n"
        "jmp .Lf174d52_00174f89\n"
        /* } scope */
        /* } scope */
        ".Lf174d52_00174ff8:\n"
        "movl 8(%ebp), %eax\n" /* line 839 | msg */
        "movl 0xc(%eax), %esi\n"
        "cmpl 8(%eax), %esi\n"
        "jl .Lf174d52_001752cc\n"
        "movl $1, (%eax)\n" /* line 841 */
        "movl 0x14(%ebp), %ebx\n" /* line 1586 | to, value */
        "movl (%ebx), %ecx\n" /* value */
        /* { scope 2 */
        "leal 4(%esi), %edx\n" /* line 1039 */
        "movl 8(%ebp), %eax\n" /* line 1040 | msg */
        "cmpl 8(%eax), %edx\n"
        "jg .Lf174d52_001752fc\n"
        ".Lf174d52_00175021:\n"
        "movl %eax, %ebx\n" /* line 1042 | bit */
        "movl 4(%eax), %eax\n"
        "movl %ecx, (%eax, %esi)\n"
        "movl %edx, %esi\n" /* line 1043 */
        "movl %edx, 0xc(%ebx)\n" /* bit */
        /* } scope */
        ".Lf174d52_0017502e:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1590 | to */
        "movzbl 0x19(%ecx), %edx\n"
        "movzbl 0x18(%ecx), %eax\n"
        "cmpb $0xa, %al\n" /* line 1519 */
        "jle .Lf174d52_00174db4\n"
        ".Lf174d52_00175041:\n"
        "movl $1, -0x18(%ebp)\n" /* horToMove */
        "cmpb $0xa, %dl\n" /* line 1524 */
        "jle .Lf174d52_00174dca\n"
        ".Lf174d52_00175051:\n"
        "orl $4, -0x18(%ebp)\n" /* line 1525 | horToMove */
        "movl 0x10(%ebp), %ebx\n" /* line 1591 | from, value */
        "movzbl 0x19(%ebx), %edx\n" /* value */
        "movzbl 0x18(%ebx), %eax\n" /* value */
        "cmpb $0xa, %al\n" /* line 1519 */
        "jle .Lf174d52_00174ded\n"
        ".Lf174d52_00175068:\n"
        "movl $1, %edi\n" /* bit */
        "cmpb $0xa, %dl\n" /* line 1524 */
        "jle .Lf174d52_00174e00\n"
        ".Lf174d52_00175076:\n"
        "orl $4, %edi\n" /* line 1525 | bit */
        "movl 0x10(%ebp), %eax\n" /* line 1597 | from */
        "movl 4(%eax), %ebx\n" /* value */
        "movl 0x14(%ebp), %edx\n" /* to */
        "movl 4(%edx), %ecx\n"
        "movl %ebx, %edx\n" /* value */
        "sarl $1, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf174d52_00174e27\n"
        ".Lf174d52_00175095:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1353 | key, value */
        "xorl $1, %ebx\n" /* value */
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 810 | msg */
        "movl 8(%ecx), %edx\n"
        "movl %edx, %eax\n"
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf174d52_001756c4\n"
        "movl $1, (%ecx)\n" /* line 812 */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_001750b4:\n"
        "movl %edx, %eax\n" /* line 810 */
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf174d52_0017564a\n"
        "movl 8(%ebp), %ecx\n" /* line 812 | msg */
        "movl $1, (%ecx)\n"
        /* } scope */
        /* } scope */
        ".Lf174d52_001750ca:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1353 | key, value */
        "movl 0x14(%ebp), %eax\n" /* to */
        "xorl 4(%eax), %ebx\n" /* value */
        /* { scope 2 */
        /* { scope 3 */
        "subl %esi, %edx\n" /* line 810 */
        "cmpl $3, %edx\n"
        "jg .Lf174d52_00175354\n"
        "movl 8(%ebp), %edx\n" /* line 812 | msg */
        "movl $1, (%edx)\n"
        /* } scope */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 1624 | to */
        "movl 0xc(%eax), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ecx\n" /* line 1387 | from */
        "cmpw %dx, 0xc(%ecx)\n"
        "je .Lf174d52_001753d6\n"
        /* { scope 3 */
        ".Lf174d52_001750fa:\n"
        "movl 8(%ebp), %ecx\n" /* line 860 | msg */
        "cmpl 8(%ecx), %esi\n"
        "jl .Lf174d52_001757a0\n"
        "movl $1, (%ecx)\n" /* line 862 */
        /* } scope */
        ".Lf174d52_0017510c:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1393 | key, c */
        "xorl %edx, %ecx\n" /* c */
        /* { scope 3 */
        /* { scope 4 */
        "leal 2(%esi), %edx\n" /* line 1023 */
        "movl 8(%ebp), %ebx\n" /* line 1024 | msg, bit */
        "cmpl 8(%ebx), %edx\n" /* bit */
        "jg .Lf174d52_00175795\n"
        "movl 4(%ebx), %eax\n" /* line 1026 | bit */
        "movw %cx, (%eax, %esi)\n"
        "movl %edx, %esi\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n" /* bit */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf174d52_0017512c:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1625 | to */
        "movl 0x10(%ecx), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 1387 | from, value */
        "cmpw %dx, 0x10(%ebx)\n" /* value */
        "je .Lf174d52_0017542f\n"
        /* { scope 3 */
        ".Lf174d52_0017513f:\n"
        "movl 8(%ebp), %ebx\n" /* line 860 | msg, bit */
        "cmpl 8(%ebx), %esi\n" /* bit */
        "jl .Lf174d52_0017573e\n"
        "movl $1, (%ebx)\n" /* line 862 | bit */
        /* } scope */
        "movl 0xc(%ebp), %ecx\n" /* line 1393 | key, c */
        "xorl %edx, %ecx\n" /* c */
        /* { scope 3 */
        /* { scope 4 */
        "leal 2(%esi), %edx\n" /* line 1023 */
        "movl 8(%ebp), %ebx\n" /* line 1024 | msg, bit */
        "cmpl 8(%ebx), %edx\n" /* bit */
        "jg .Lf174d52_00175788\n"
        ".Lf174d52_00175165:\n"
        "movl 4(%ebx), %eax\n" /* line 1026 | bit */
        "movw %cx, (%eax, %esi)\n"
        "movl %edx, %esi\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n" /* bit */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf174d52_00175171:\n"
        "cmpl %edi, -0x18(%ebp)\n" /* line 1331 | bit, horToMove */
        "je .Lf174d52_0017547f\n"
        /* { scope 2 */
        ".Lf174d52_0017517a:\n"
        "movl 8(%ebp), %edx\n" /* line 860 | msg */
        "cmpl 8(%edx), %esi\n"
        "jl .Lf174d52_00175ad8\n"
        "movl $1, (%edx)\n" /* line 862 */
        /* } scope */
        ".Lf174d52_0017518c:\n"
        "movl -0x18(%ebp), %ebx\n" /* line 1337 | horToMove, value */
        "xorl 0xc(%ebp), %ebx\n" /* key, value */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %edx\n" /* line 810 | msg */
        "movl 8(%edx), %eax\n"
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf174d52_00175a56\n"
        ".Lf174d52_001751a3:\n"
        "movl $1, (%edx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        ".Lf174d52_001751a9:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1634 | key, value */
        "movl 0x14(%ebp), %ecx\n" /* to */
        "xorl (%ecx), %ebx\n" /* value */
        "movl %ebx, -0x14(%ebp)\n" /* value */
        "movl 0x14(%ecx), %edx\n" /* line 1635 | newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %eax\n" /* line 1387 | from */
        "cmpw %dx, 0x14(%eax)\n"
        "je .Lf174d52_001754e4\n"
        /* { scope 3 */
        ".Lf174d52_001751c4:\n"
        "movl 8(%ebp), %ecx\n" /* line 860 | msg */
        "cmpl 8(%ecx), %esi\n"
        "jl .Lf174d52_00175a1d\n"
        "movl $1, (%ecx)\n" /* line 862 */
        /* } scope */
        ".Lf174d52_001751d6:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 1393 | c */
        "xorl %edx, %ecx\n" /* c */
        /* { scope 3 */
        /* { scope 4 */
        "leal 2(%esi), %edx\n" /* line 1023 */
        "movl 8(%ebp), %ebx\n" /* line 1024 | msg, bit */
        "cmpl 8(%ebx), %edx\n" /* bit */
        "jg .Lf174d52_00175a12\n"
        "movl 4(%ebx), %eax\n" /* line 1026 | bit */
        "movw %cx, (%eax, %esi)\n"
        "movl %edx, %esi\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n" /* bit */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf174d52_001751f6:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1636 | to */
        "movl 4(%ecx), %edx\n" /* newV */
        "sarl $1, %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 1331 | from, bit */
        "movl 4(%ebx), %eax\n" /* bit */
        "sarl $1, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf174d52_00175546\n"
        /* { scope 3 */
        ".Lf174d52_0017520e:\n"
        "movl 8(%ebp), %ebx\n" /* line 860 | msg, bit */
        "cmpl 8(%ebx), %esi\n" /* bit */
        "jl .Lf174d52_001759d7\n"
        "movl $1, (%ebx)\n" /* line 862 | bit */
        /* } scope */
        ".Lf174d52_00175220:\n"
        "movl %edx, %ebx\n" /* line 1337 | value */
        "xorl -0x14(%ebp), %ebx\n" /* value */
        /* { scope 3 */
        /* { scope 4 */
        "movl 8(%ebp), %edx\n" /* line 810 | msg */
        "movl 8(%edx), %eax\n"
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf174d52_00175955\n"
        "movl $1, (%edx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf174d52_0017523c:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1637 | to */
        "movzbl 8(%ecx), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 1331 | from, bit */
        "movzbl 8(%ebx), %eax\n" /* bit */
        "cmpl %eax, %edx\n"
        "je .Lf174d52_001755a3\n"
        /* { scope 3 */
        ".Lf174d52_00175252:\n"
        "movl 8(%ebp), %ebx\n" /* line 860 | msg, bit */
        "cmpl 8(%ebx), %esi\n" /* bit */
        "jl .Lf174d52_0017591a\n"
        "movl $1, (%ebx)\n" /* line 862 | bit */
        /* } scope */
        ".Lf174d52_00175264:\n"
        "movl -0x14(%ebp), %ebx\n" /* line 1337 | value */
        "xorl %edx, %ebx\n" /* value */
        /* { scope 3 */
        /* { scope 4 */
        "movl 8(%ebp), %edx\n" /* line 810 | msg */
        "movl 8(%edx), %eax\n"
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf174d52_00175898\n"
        "movl $1, (%edx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf174d52_00175280:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1638 | to */
        "movzbl 9(%ecx), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 1331 | from, bit */
        "movzbl 9(%ebx), %eax\n" /* bit */
        "cmpl %eax, %edx\n"
        "je .Lf174d52_00175600\n"
        /* { scope 3 */
        ".Lf174d52_00175296:\n"
        "movl 8(%ebp), %ebx\n" /* line 860 | msg, bit */
        "cmpl 8(%ebx), %esi\n" /* bit */
        "jl .Lf174d52_0017585d\n"
        "movl $1, (%ebx)\n" /* line 862 | bit */
        /* } scope */
        ".Lf174d52_001752a8:\n"
        "movl -0x14(%ebp), %ebx\n" /* line 1337 | value */
        "xorl %edx, %ebx\n" /* value */
        /* { scope 3 */
        /* { scope 4 */
        "movl 8(%ebp), %edx\n" /* line 810 | msg */
        "movl 8(%edx), %eax\n"
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf174d52_001757d9\n"
        ".Lf174d52_001752be:\n"
        "movl $1, (%edx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf174d52_001752c4:\n"
        "addl $0x10, %esp\n" /* line 1639 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf174d52_001752cc:\n"
        "movl 0x14(%eax), %edx\n" /* line 846 */
        "movl %edx, -0x1c(%ebp)\n"
        "andb $7, %dl\n"
        "je .Lf174d52_00175dbb\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %ecx\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %ecx, 0x14(%edx)\n"
        ".Lf174d52_001752e8:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1586 | to, value */
        "movl (%ebx), %ecx\n" /* value */
        /* { scope 2 */
        "leal 4(%esi), %edx\n" /* line 1039 */
        "movl 8(%ebp), %eax\n" /* line 1040 | msg */
        "cmpl 8(%eax), %edx\n"
        "jle .Lf174d52_00175021\n"
        ".Lf174d52_001752fc:\n"
        "movl $1, (%eax)\n" /* line 1047 */
        "jmp .Lf174d52_0017502e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00175307:\n"
        "movl 0x14(%ebx), %eax\n" /* line 866 | bit */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 867 | bit */
        "andl $7, %ebx\n" /* bit */
        "je .Lf174d52_00175d70\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        /* } scope */
        ".Lf174d52_0017533d:\n"
        "movl 8(%ebp), %ecx\n" /* line 992 | msg */
        "cmpl 8(%ecx), %esi\n"
        "jl .Lf174d52_00174d92\n"
        ".Lf174d52_00175349:\n"
        "movl $1, (%ecx)\n" /* line 999 */
        "jmp .Lf174d52_0017502e\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175354:\n"
        "movl 8(%ebp), %ecx\n" /* line 819 | msg */
        "movl 0x14(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edx\n" /* line 820 */
        "andl $7, %edx\n"
        "jne .Lf174d52_00175387\n"
        "leal (, %esi, 8), %eax\n" /* line 822 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %eax, 0x14(%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 823 */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ecx), %esi\n" /* line 824 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ecx)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175387:\n"
        "andb $1, %bl\n" /* line 827 */
        "je .Lf174d52_00175b1f\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n"
        "orb %al, (%ebx)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0xc(%eax), %esi\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lf174d52_001753b9:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %ebx\n"
        "movl %ebx, 0x14(%ecx)\n"
        /* } scope */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 1624 | to */
        "movl 0xc(%eax), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ecx\n" /* line 1387 | from */
        "cmpw %dx, 0xc(%ecx)\n"
        "jne .Lf174d52_001750fa\n"
        ".Lf174d52_001753d6:\n"
        "movl 8(%ebp), %ebx\n" /* line 839 | msg */
        "cmpl 8(%ebx), %esi\n"
        "jge .Lf174d52_00175d36\n"
        "movl 0x14(%ebx), %eax\n" /* line 846 */
        "movl %eax, -0x1c(%ebp)\n"
        "testb $7, %al\n"
        "jne .Lf174d52_0017540f\n"
        "leal (, %esi, 8), %edx\n" /* line 848 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %edx, 0x14(%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 849 */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ecx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ecx)\n"
        "movl 0x14(%ecx), %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n"
        ".Lf174d52_0017540f:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %edx, 0x14(%eax)\n"
        /* } scope */
        "movl 0x14(%ebp), %ecx\n" /* line 1625 | to */
        "movl 0x10(%ecx), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 1387 | from, value */
        "cmpw %dx, 0x10(%ebx)\n" /* value */
        "jne .Lf174d52_0017513f\n"
        ".Lf174d52_0017542f:\n"
        "movl 8(%ebp), %eax\n" /* line 839 | msg */
        "cmpl 8(%eax), %esi\n"
        "jge .Lf174d52_0017578a\n"
        "movl 0x14(%eax), %edx\n" /* line 846 */
        "movl %edx, -0x1c(%ebp)\n"
        "andb $7, %dl\n"
        "jne .Lf174d52_00175469\n"
        "leal (, %esi, 8), %ecx\n" /* line 848 */
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ebx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175469:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %ecx\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %ecx, 0x14(%edx)\n"
        /* } scope */
        "cmpl %edi, -0x18(%ebp)\n" /* line 1331 | bit, horToMove */
        "jne .Lf174d52_0017517a\n"
        ".Lf174d52_0017547f:\n"
        "movl 8(%ebp), %edx\n" /* line 839 | msg */
        "cmpl 8(%edx), %esi\n"
        "jge .Lf174d52_001751a3\n"
        "movl 0x14(%edx), %ecx\n" /* line 846 */
        "movl %ecx, -0x1c(%ebp)\n"
        "andb $7, %cl\n"
        "jne .Lf174d52_001754bc\n"
        "leal (, %esi, 8), %ebx\n" /* line 848 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ebx, 0x14(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 849 | msg */
        "movl 4(%edx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%edx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%edx)\n"
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lf174d52_001754bc:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %eax\n"
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %eax, 0x14(%ebx)\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1634 | key, value */
        "movl 0x14(%ebp), %ecx\n" /* to */
        "xorl (%ecx), %ebx\n" /* value */
        "movl %ebx, -0x14(%ebp)\n" /* value */
        "movl 0x14(%ecx), %edx\n" /* line 1635 | newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %eax\n" /* line 1387 | from */
        "cmpw %dx, 0x14(%eax)\n"
        "jne .Lf174d52_001751c4\n"
        ".Lf174d52_001754e4:\n"
        "movl 8(%ebp), %edx\n" /* line 839 | msg */
        "cmpl 8(%edx), %esi\n"
        "jge .Lf174d52_00175d5a\n"
        "movl 0x14(%edx), %ecx\n" /* line 846 */
        "movl %ecx, -0x1c(%ebp)\n"
        "andb $7, %cl\n"
        "jne .Lf174d52_00175521\n"
        "leal (, %esi, 8), %ebx\n" /* line 848 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ebx, 0x14(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 849 | msg */
        "movl 4(%edx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%edx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%edx)\n"
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lf174d52_00175521:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %eax\n"
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %eax, 0x14(%ebx)\n"
        /* } scope */
        "movl 0x14(%ebp), %ecx\n" /* line 1636 | to */
        "movl 4(%ecx), %edx\n" /* newV */
        "sarl $1, %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 1331 | from, bit */
        "movl 4(%ebx), %eax\n" /* bit */
        "sarl $1, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf174d52_0017520e\n"
        ".Lf174d52_00175546:\n"
        "movl 8(%ebp), %eax\n" /* line 839 | msg */
        "cmpl 8(%eax), %esi\n"
        "jge .Lf174d52_00175d65\n"
        "movl 0x14(%eax), %edx\n" /* line 846 */
        "movl %edx, -0x1c(%ebp)\n"
        "andb $7, %dl\n"
        "jne .Lf174d52_00175580\n"
        "leal (, %esi, 8), %ecx\n" /* line 848 */
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ebx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175580:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %ecx\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %ecx, 0x14(%edx)\n"
        /* } scope */
        "movl 0x14(%ebp), %ecx\n" /* line 1637 | to */
        "movzbl 8(%ecx), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 1331 | from, bit */
        "movzbl 8(%ebx), %eax\n" /* bit */
        "cmpl %eax, %edx\n"
        "jne .Lf174d52_00175252\n"
        ".Lf174d52_001755a3:\n"
        "movl 8(%ebp), %eax\n" /* line 839 | msg */
        "cmpl 8(%eax), %esi\n"
        "jge .Lf174d52_00175d41\n"
        "movl 0x14(%eax), %edx\n" /* line 846 */
        "movl %edx, -0x1c(%ebp)\n"
        "andb $7, %dl\n"
        "jne .Lf174d52_001755dd\n"
        "leal (, %esi, 8), %ecx\n" /* line 848 */
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ebx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_001755dd:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %ecx\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %ecx, 0x14(%edx)\n"
        /* } scope */
        "movl 0x14(%ebp), %ecx\n" /* line 1638 | to */
        "movzbl 9(%ecx), %edx\n" /* newV */
        /* { scope 2 */
        "movl 0x10(%ebp), %ebx\n" /* line 1331 | from, bit */
        "movzbl 9(%ebx), %eax\n" /* bit */
        "cmpl %eax, %edx\n"
        "jne .Lf174d52_00175296\n"
        ".Lf174d52_00175600:\n"
        "movl 8(%ebp), %eax\n" /* line 839 | msg */
        "cmpl 8(%eax), %esi\n"
        "jge .Lf174d52_00175d4c\n"
        "movl 0x14(%eax), %edx\n" /* line 846 */
        "movl %edx, -0x1c(%ebp)\n"
        "andb $7, %dl\n"
        "jne .Lf174d52_00175635\n"
        "leal (, %esi, 8), %ecx\n" /* line 848 */
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ebx)\n" /* line 850 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175635:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %ecx\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %ecx, 0x14(%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1639 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_0017564a:\n"
        "movl 8(%ebp), %eax\n" /* line 819 | msg */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %edx\n" /* line 820 */
        "andl $7, %edx\n"
        "jne .Lf174d52_00175680\n"
        "leal (, %esi, 8), %ecx\n" /* line 822 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 823 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ecx), %esi\n" /* line 824 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ecx)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175680:\n"
        "andb $1, %bl\n" /* line 827 */
        "je .Lf174d52_00175b27\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n"
        "orb %al, (%ebx)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0xc(%eax), %esi\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lf174d52_001756b2:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %ebx\n"
        "movl %ebx, 0x14(%ecx)\n"
        "movl 8(%ecx), %edx\n"
        "jmp .Lf174d52_001750ca\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_001756c4:\n"
        "movl 0x14(%ecx), %eax\n" /* line 819 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %edx\n" /* line 820 */
        "andl $7, %edx\n"
        "jne .Lf174d52_001756f7\n"
        "leal (, %esi, 8), %ecx\n" /* line 822 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 823 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ecx), %esi\n" /* line 824 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ecx)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_001756f7:\n"
        "testb $1, %bl\n" /* line 827 */
        "je .Lf174d52_00175b17\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 0xc(%ecx), %esi\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, %edx\n"
        ".Lf174d52_00175729:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %ecx\n"
        "movl %ecx, 0x14(%edx)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 8(%eax), %edx\n"
        "jmp .Lf174d52_001750b4\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_0017573e:\n"
        "movl 0x14(%ebx), %eax\n" /* line 866 | bit */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 867 | bit */
        "andl $7, %ebx\n" /* bit */
        "je .Lf174d52_00175ceb\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        /* } scope */
        ".Lf174d52_00175774:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1393 | key, c */
        "xorl %edx, %ecx\n" /* c */
        /* { scope 3 */
        /* { scope 4 */
        "leal 2(%esi), %edx\n" /* line 1023 */
        "movl 8(%ebp), %ebx\n" /* line 1024 | msg, bit */
        "cmpl 8(%ebx), %edx\n" /* bit */
        "jle .Lf174d52_00175165\n"
        ".Lf174d52_00175788:\n"
        "movl %ebx, %eax\n" /* bit */
        ".Lf174d52_0017578a:\n"
        "movl $1, (%eax)\n" /* line 1031 */
        "jmp .Lf174d52_00175171\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf174d52_00175795:\n"
        "movl $1, (%ebx)\n" /* bit */
        "jmp .Lf174d52_0017512c\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf174d52_001757a0:\n"
        "movl 0x14(%ecx), %ebx\n" /* line 866 | bit */
        "movl %ebx, -0x1c(%ebp)\n" /* bit */
        "andl $7, %ebx\n" /* line 867 | bit */
        "je .Lf174d52_00175ca3\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_0017510c\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf174d52_001757d9:\n"
        "movl $7, %esi\n" /* line 812 */
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edi\n" /* bit */
        "jmp .Lf174d52_00175827\n"
        ".Lf174d52_001757e8:\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 4(%edx), %edx\n"
        "addl %edx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 0x14(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %eax\n"
        ".Lf174d52_0017580e:\n"
        "addl $1, %eax\n" /* line 829 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %eax, 0x14(%edx)\n"
        "sarl $1, %ebx\n" /* line 830 */
        "testl %esi, %esi\n" /* line 816 */
        "je .Lf174d52_001752c4\n"
        "movl -0x1c(%ebp), %edi\n" /* bit */
        ".Lf174d52_00175827:\n"
        "subl $1, %esi\n" /* line 818 */
        "andl $7, %edi\n" /* line 820 | bit */
        "jne .Lf174d52_00175853\n"
        "movl 8(%ebp), %eax\n" /* line 822 | msg */
        "movl 0xc(%eax), %edx\n"
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 823 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ecx)\n" /* line 824 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175853:\n"
        "testb $1, %bl\n" /* line 827 */
        "jne .Lf174d52_001757e8\n"
        "movl -0x1c(%ebp), %eax\n"
        "jmp .Lf174d52_0017580e\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf174d52_0017585d:\n"
        "movl 0x14(%ebx), %eax\n" /* line 866 | bit */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 867 | bit */
        "andl $7, %ebx\n" /* bit */
        "je .Lf174d52_00175c58\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_001752a8\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf174d52_00175898:\n"
        "movl $7, %esi\n" /* line 812 */
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edi\n" /* bit */
        "jmp .Lf174d52_001758aa\n"
        ".Lf174d52_001758a7:\n"
        "movl -0x1c(%ebp), %edi\n" /* bit */
        ".Lf174d52_001758aa:\n"
        "subl $1, %esi\n" /* line 818 */
        "andl $7, %edi\n" /* line 820 | bit */
        "jne .Lf174d52_001758d6\n"
        "movl 8(%ebp), %eax\n" /* line 822 | msg */
        "movl 0xc(%eax), %edx\n"
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 823 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ecx)\n" /* line 824 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_001758d6:\n"
        "testb $1, %bl\n" /* line 827 */
        "je .Lf174d52_001758ff\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 4(%edx), %edx\n"
        "addl %edx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 0x14(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lf174d52_001758ff:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %edx, 0x14(%eax)\n"
        "sarl $1, %ebx\n" /* line 830 */
        "testl %esi, %esi\n" /* line 816 */
        "jne .Lf174d52_001758a7\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_00175280\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf174d52_0017591a:\n"
        "movl 0x14(%ebx), %eax\n" /* line 866 | bit */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 867 | bit */
        "andl $7, %ebx\n" /* bit */
        "je .Lf174d52_00175c0d\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_00175264\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf174d52_00175955:\n"
        "movl $0x12, %esi\n" /* line 812 */
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edi\n" /* bit */
        "jmp .Lf174d52_00175967\n"
        ".Lf174d52_00175964:\n"
        "movl -0x1c(%ebp), %edi\n" /* bit */
        ".Lf174d52_00175967:\n"
        "subl $1, %esi\n" /* line 818 */
        "andl $7, %edi\n" /* line 820 | bit */
        "jne .Lf174d52_00175993\n"
        "movl 8(%ebp), %eax\n" /* line 822 | msg */
        "movl 0xc(%eax), %edx\n"
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 823 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ecx)\n" /* line 824 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175993:\n"
        "testb $1, %bl\n" /* line 827 */
        "je .Lf174d52_001759bc\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 4(%edx), %edx\n"
        "addl %edx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 0x14(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lf174d52_001759bc:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %edx, 0x14(%eax)\n"
        "sarl $1, %ebx\n" /* line 830 */
        "testl %esi, %esi\n" /* line 816 */
        "jne .Lf174d52_00175964\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_0017523c\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf174d52_001759d7:\n"
        "movl 0x14(%ebx), %eax\n" /* line 866 | bit */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 867 | bit */
        "andl $7, %ebx\n" /* bit */
        "je .Lf174d52_00175bc2\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_00175220\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf174d52_00175a12:\n"
        "movl $1, (%ebx)\n" /* line 1031 | bit */
        "jmp .Lf174d52_001751f6\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf174d52_00175a1d:\n"
        "movl 0x14(%ecx), %ebx\n" /* line 866 | bit */
        "movl %ebx, -0x1c(%ebp)\n" /* bit */
        "andl $7, %ebx\n" /* line 867 | bit */
        "je .Lf174d52_00175b7a\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_001751d6\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175a56:\n"
        "movl $4, %esi\n" /* line 812 */
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edi\n" /* bit */
        "subl $1, %esi\n" /* line 818 */
        "andl $7, %edi\n" /* line 820 | bit */
        "jne .Lf174d52_00175a8f\n"
        ".Lf174d52_00175a6b:\n"
        "movl 8(%ebp), %eax\n" /* line 822 | msg */
        "movl 0xc(%eax), %edx\n"
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 823 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ecx)\n" /* line 824 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175a8f:\n"
        "testb $1, %bl\n" /* line 827 */
        "je .Lf174d52_00175ab8\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 4(%edx), %edx\n"
        "addl %edx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 0x14(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lf174d52_00175ab8:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %edx, 0x14(%eax)\n"
        "sarl $1, %ebx\n" /* line 830 */
        "testl %esi, %esi\n" /* line 816 */
        "je .Lf174d52_00175b0f\n"
        "movl -0x1c(%ebp), %edi\n" /* bit */
        "subl $1, %esi\n" /* line 818 */
        "andl $7, %edi\n" /* line 820 | bit */
        "jne .Lf174d52_00175a8f\n"
        "jmp .Lf174d52_00175a6b\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00175ad8:\n"
        "movl 0x14(%edx), %ecx\n" /* line 866 */
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edx\n" /* line 867 */
        "andl $7, %edx\n"
        "je .Lf174d52_00175b2f\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 4(%eax), %eax\n"
        "addl %eax, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_0017518c\n"
        ".Lf174d52_00175b0f:\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_001751a9\n"
        ".Lf174d52_00175b17:\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "jmp .Lf174d52_00175729\n"
        ".Lf174d52_00175b1f:\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "jmp .Lf174d52_001753b9\n"
        ".Lf174d52_00175b27:\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "jmp .Lf174d52_001756b2\n"
        ".Lf174d52_00175b2f:\n"
        "leal (, %esi, 8), %ebx\n" /* line 869 | bit */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ebx, 0x14(%eax)\n" /* bit */
        "movl 8(%ebp), %ecx\n" /* line 870 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %ebx\n" /* bit */
        "movl %ebx, -0x1c(%ebp)\n" /* bit */
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 4(%eax), %eax\n"
        "addl %eax, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_0017518c\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175b7a:\n"
        "leal (, %esi, 8), %eax\n" /* line 869 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %eax, 0x14(%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 870 */
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_001751d6\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175bc2:\n"
        "leal (, %esi, 8), %ecx\n" /* line 869 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 870 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_00175220\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175c0d:\n"
        "leal (, %esi, 8), %ecx\n" /* line 869 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 870 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_00175264\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175c58:\n"
        "leal (, %esi, 8), %ecx\n" /* line 869 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 870 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_001752a8\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175ca3:\n"
        "leal (, %esi, 8), %eax\n" /* line 869 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %eax, 0x14(%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 870 */
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_0017510c\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175ceb:\n"
        "leal (, %esi, 8), %ecx\n" /* line 869 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 870 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_00175774\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00175d36:\n"
        "movl $1, (%ebx)\n" /* line 841 */
        "jmp .Lf174d52_0017512c\n"
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00175d41:\n"
        "movl $1, (%eax)\n"
        "jmp .Lf174d52_00175280\n"
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00175d4c:\n"
        "movl $1, (%eax)\n"
        /* } scope */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1639 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf174d52_00175d5a:\n"
        "movl $1, (%edx)\n" /* line 841 */
        "jmp .Lf174d52_001751f6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00175d65:\n"
        "movl $1, (%eax)\n"
        "jmp .Lf174d52_0017523c\n"
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00175d70:\n"
        "leal (, %esi, 8), %ecx\n" /* line 869 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 870 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_0017533d\n"
        /* } scope */
        ".Lf174d52_00175dbb:\n"
        "leal (, %esi, 8), %ecx\n" /* line 848 */
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ebx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %ecx\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %ecx, 0x14(%edx)\n"
        "jmp .Lf174d52_001752e8\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175df0:\n"
        "movl 8(%ebp), %eax\n" /* line 819 | msg */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %edx\n" /* line 820 */
        "andl $7, %edx\n"
        "jne .Lf174d52_00175e26\n"
        "leal (, %esi, 8), %ecx\n" /* line 822 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 823 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ecx), %esi\n" /* line 824 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ecx)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175e26:\n"
        "andb $1, %bl\n" /* line 827 */
        "je .Lf174d52_0017617a\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n"
        "orb %al, (%ebx)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0xc(%eax), %esi\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lf174d52_00175e58:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %ebx\n"
        "movl %ebx, 0x14(%ecx)\n"
        "jmp .Lf174d52_00174ebb\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00175e67:\n"
        "movl 8(%ebp), %edx\n" /* line 819 | msg */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "andl $7, %edx\n" /* line 820 */
        "jne .Lf174d52_00175e98\n"
        "leal (, %esi, 8), %ecx\n" /* line 822 */
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 823 */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ebx), %esi\n" /* line 824 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175e98:\n"
        "testb $1, 0xc(%ebp)\n" /* line 827 | key */
        "je .Lf174d52_0017616a\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n"
        "orb %al, (%ebx)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0xc(%eax), %esi\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lf174d52_00175ecb:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %ebx\n"
        "movl %ebx, 0x14(%ecx)\n"
        "movl 8(%ecx), %edx\n"
        "jmp .Lf174d52_00174e97\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf174d52_00175edd:\n"
        "movl 8(%ebp), %eax\n" /* line 819 | msg */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %edx\n" /* line 820 */
        "andl $7, %edx\n"
        "jne .Lf174d52_00175f13\n"
        "leal (, %esi, 8), %ecx\n" /* line 822 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 823 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ecx), %esi\n" /* line 824 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ecx)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175f13:\n"
        "andb $1, %bl\n" /* line 827 */
        "je .Lf174d52_00176172\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n"
        "orb %al, (%ebx)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0xc(%eax), %esi\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lf174d52_00175f45:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 829 */
        "movl -0x1c(%ebp), %ebx\n"
        "movl %ebx, 0x14(%ecx)\n"
        "movl 8(%ecx), %edx\n"
        "jmp .Lf174d52_00174e81\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00175f57:\n"
        "movl 0x14(%edx), %ecx\n" /* line 866 */
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edx\n" /* line 867 */
        "andl $7, %edx\n"
        "jne .Lf174d52_00175f85\n"
        "leal (, %esi, 8), %ebx\n" /* line 869 | bit */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ebx, 0x14(%eax)\n" /* bit */
        "movl 8(%ebp), %ecx\n" /* line 870 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %ebx\n" /* bit */
        "movl %ebx, -0x1c(%ebp)\n" /* bit */
        ".Lf174d52_00175f85:\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 4(%eax), %eax\n"
        "addl %eax, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_00174f60\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf174d52_00175faf:\n"
        "movl $1, (%ebx)\n" /* line 1031 | bit */
        "jmp .Lf174d52_00174f00\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf174d52_00175fba:\n"
        "movl 0x14(%ecx), %ebx\n" /* line 866 | bit */
        "movl %ebx, -0x1c(%ebp)\n" /* bit */
        "andl $7, %ebx\n" /* line 867 | bit */
        "jne .Lf174d52_00175fe3\n"
        "leal (, %esi, 8), %eax\n" /* line 869 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %eax, 0x14(%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 870 */
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00175fe3:\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_00174ee0\n"
        ".Lf174d52_0017600d:\n"
        "movl %ebx, %eax\n" /* bit */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf174d52_0017600f:\n"
        "movl $1, (%eax)\n" /* line 1031 */
        "jmp .Lf174d52_00174f45\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf174d52_0017601a:\n"
        "movl 0x14(%ebx), %eax\n" /* line 866 | bit */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 867 | bit */
        "andl $7, %ebx\n" /* bit */
        "jne .Lf174d52_00176048\n"
        "leal (, %esi, 8), %ecx\n" /* line 869 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ecx, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 870 | msg */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 871 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00176048:\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 874 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* bit */
        "orb %al, (%ebx)\n" /* bit */
        "movl 8(%ebp), %eax\n" /* line 875 | msg */
        "addl $1, 0x14(%eax)\n"
        "movl 0xc(%eax), %esi\n"
        "jmp .Lf174d52_00174f25\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00176072:\n"
        "movl 8(%ebp), %ebx\n" /* line 839 | msg */
        "cmpl 8(%ebx), %esi\n"
        "jl .Lf174d52_00176182\n"
        "movl $1, (%ebx)\n" /* line 841 */
        "jmp .Lf174d52_00174f00\n"
        /* } scope */
        ".Lf174d52_00176089:\n"
        "movl 8(%ebp), %edx\n" /* line 839 | msg */
        "cmpl 8(%edx), %esi\n"
        "jge .Lf174d52_001752be\n"
        "movl 8(%ebp), %ecx\n" /* line 846 | msg */
        "movl 0x14(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "andb $7, %cl\n"
        "jne .Lf174d52_001760c4\n"
        "leal (, %esi, 8), %ebx\n" /* line 848 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %ebx, 0x14(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 849 | msg */
        "movl 4(%edx), %eax\n"
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%edx)\n" /* line 850 */
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lf174d52_001760c4:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %eax\n"
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %eax, 0x14(%ebx)\n"
        "jmp .Lf174d52_001752c4\n"
        ".Lf174d52_001760d6:\n"
        "movl 0x10(%ebp), %edx\n" /* line 1599 | from */
        "movl 0x10(%edx), %eax\n"
        "movl 0x14(%ebp), %edx\n" /* to */
        "cmpl 0x10(%edx), %eax\n"
        "jne .Lf174d52_00174e5f\n"
        "andl $1, %ebx\n" /* value */
        "andl $1, %ecx\n"
        "cmpl %ecx, %ebx\n" /* value */
        "jne .Lf174d52_00174e5f\n"
        "cmpl %edi, -0x18(%ebp)\n" /* horFromMove, horToMove */
        "jne .Lf174d52_00174e5f\n"
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 810 | msg */
        "movl 8(%ecx), %eax\n"
        "subl %esi, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf174d52_001761c4\n"
        "movl $1, (%ecx)\n" /* line 812 */
        "jmp .Lf174d52_001752c4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_0017611b:\n"
        "movl 8(%ebp), %eax\n" /* line 839 | msg */
        "cmpl 8(%eax), %esi\n"
        "jge .Lf174d52_0017600f\n"
        "movl 8(%ebp), %edx\n" /* line 846 | msg */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "andb $7, %dl\n"
        "jne .Lf174d52_00176158\n"
        "leal (, %esi, 8), %ecx\n" /* line 848 */
        "movl 8(%ebp), %ebx\n" /* msg */
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ebx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf174d52_00176158:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %ecx\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %ecx, 0x14(%edx)\n"
        "jmp .Lf174d52_00174f45\n"
        ".Lf174d52_0017616a:\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "jmp .Lf174d52_00175ecb\n"
        ".Lf174d52_00176172:\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "jmp .Lf174d52_00175f45\n"
        ".Lf174d52_0017617a:\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "jmp .Lf174d52_00175e58\n"
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_00176182:\n"
        "movl 8(%ebp), %eax\n" /* line 846 | msg */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testb $7, %al\n"
        "jne .Lf174d52_001761b2\n"
        "leal (, %esi, 8), %edx\n" /* line 848 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %edx, 0x14(%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 849 */
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ecx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, 0xc(%ecx)\n"
        "movl 0x14(%ecx), %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n"
        ".Lf174d52_001761b2:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 852 */
        "movl -0x1c(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %edx, 0x14(%eax)\n"
        "jmp .Lf174d52_00174f00\n"
        /* } scope */
        /* { scope 2 */
        ".Lf174d52_001761c4:\n"
        "movl 8(%ebp), %ebx\n" /* line 819 | msg */
        "movl 0x14(%ebx), %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n"
        "movl %ebx, %edx\n" /* line 820 */
        "andl $7, %edx\n"
        "jne .Lf174d52_001761f2\n"
        "leal (, %esi, 8), %eax\n" /* line 822 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %eax, 0x14(%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 823 */
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ecx)\n" /* line 824 */
        "movl 0x14(%ecx), %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n"
        ".Lf174d52_001761f2:\n"
        "testb $1, 0xc(%ebp)\n" /* line 827 | key */
        "je .Lf174d52_00175635\n"
        "sarl $3, -0x1c(%ebp)\n" /* line 828 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 4(%eax), %eax\n"
        "addl %eax, -0x1c(%ebp)\n"
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ebx\n"
        "orb %al, (%ebx)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "jmp .Lf174d52_00175635\n"
    );
}

/* line 1744 */
static __attribute__((naked))
void MSG_WriteDeltaField(const NetField *field)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1744 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %ebx\n" /* msg */
        /* { scope 1: bit, bit, bit */
        "movl 8(%ebp), %esi\n" /* line 1755 | field, bits */
        "movl 4(%esi), %eax\n" /* bits */
        "leal (%eax, %ecx), %edi\n" /* line 1756 | value */
        "movl (%eax, %edx), %eax\n" /* line 1758 */
        "cmpl (%edi), %eax\n" /* value */
        "je .Lf176226_0017635e\n"
        /* { scope 2: bit, bit */
        "movl 0xc(%ebx), %edx\n" /* line 860 */
        "cmpl 8(%ebx), %edx\n"
        "jl .Lf176226_001762f1\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 1769 | field, to */
        "movl 8(%ecx), %eax\n" /* to */
        "testl %eax, %eax\n"
        "jne .Lf176226_0017632f\n"
        ".Lf176226_00176265:\n"
        "movss (%edi), %xmm1\n" /* line 1772 | value */
        "cvttss2si %xmm1, %esi\n" /* line 1773 | bits */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 1775 | 0.0f */
        "je .Lf176226_001763c1\n"
        /* { scope 2: bit, bit */
        ".Lf176226_0017627a:\n"
        "cmpl 8(%ebx), %edx\n" /* line 860 */
        "jl .Lf176226_001765c1\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        ".Lf176226_00176289:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 1782 | bits */
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf176226_0017645b\n"
        "jp .Lf176226_0017645b\n"
        "addl $__mh_execute_header, %esi\n" /* bits */
        "movl %esi, -0x14(%ebp)\n" /* bits */
        "js .Lf176226_0017645b\n"
        "cmpl $0x1fff, %esi\n" /* bits */
        "jg .Lf176226_0017645b\n"
        "cmpl 8(%ebx), %edx\n" /* line 839 */
        "jl .Lf176226_001767c4\n"
        "movl $1, (%ebx)\n" /* line 841 */
        /* { scope 2: bit, bit */
        /* { scope 3 */
        ".Lf176226_001762c6:\n"
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl %edx, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf176226_00176747\n"
        "movl $1, (%ebx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        ".Lf176226_001762da:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 1789 | c */
        "sarl $5, %ecx\n" /* c */
        /* { scope 2: bit, bit */
        "cmpl 8(%ebx), %edx\n" /* line 992 */
        "jge .Lf176226_00176350\n"
        /* } scope */
        /* { scope 2: bit, bit */
        ".Lf176226_001762e5:\n"
        "movl 4(%ebx), %eax\n" /* line 994 */
        "movb %cl, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 995 */
        "jmp .Lf176226_00176356\n"
        /* } scope */
        /* { scope 2: bit, bit */
        ".Lf176226_001762f1:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 866 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl %ecx, %esi\n" /* line 867 | bit */
        "andl $7, %esi\n" /* bit */
        "je .Lf176226_00176382\n"
        "sarl $3, -0x38(%ebp)\n" /* line 874 */
        "movl 4(%ebx), %ecx\n"
        "addl %ecx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %esi\n" /* bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edx\n"
        /* } scope */
        ".Lf176226_00176321:\n"
        "movl 8(%ebp), %ecx\n" /* line 1769 | field, to */
        "movl 8(%ecx), %eax\n" /* to */
        "testl %eax, %eax\n"
        "je .Lf176226_00176265\n"
        ".Lf176226_0017632f:\n"
        "cmpl $-0x63, %eax\n" /* line 1799 */
        "je .Lf176226_00176486\n"
        "cmpl $-0x64, %eax\n" /* line 1829 */
        "je .Lf176226_00176414\n"
        "movl (%edi), %eax\n" /* line 1845 | bits */
        "testl %eax, %eax\n"
        "jne .Lf176226_00176536\n"
        ".Lf176226_0017634b:\n"
        "cmpl 8(%ebx), %edx\n" /* line 839 */
        "jl .Lf176226_00176366\n"
        ".Lf176226_00176350:\n"
        "movl $1, (%ebx)\n" /* line 841 */
        /* } scope */
        ".Lf176226_00176356:\n"
        "addl $0x2c, %esp\n" /* line 1883 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bit, bit, bit */
        ".Lf176226_0017635e:\n"
        "movl 0xc(%ebx), %edx\n" /* line 839 */
        "cmpl 8(%ebx), %edx\n"
        "jge .Lf176226_00176350\n"
        ".Lf176226_00176366:\n"
        "movl 0x14(%ebx), %eax\n" /* line 846 */
        "movl %eax, -0x38(%ebp)\n"
        "testb $7, %al\n"
        "je .Lf176226_001763ea\n"
        "addl $1, -0x38(%ebp)\n" /* line 852 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        /* } scope */
        ".Lf176226_0017637a:\n"
        "addl $0x2c, %esp\n" /* line 1883 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bit, bit, bit */
        /* { scope 2: bit, bit */
        ".Lf176226_00176382:\n"
        "leal (, %edx, 8), %eax\n" /* line 869 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "sarl $3, -0x38(%ebp)\n" /* line 874 */
        "movl 4(%ebx), %ecx\n"
        "addl %ecx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %esi\n" /* bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edx\n"
        "jmp .Lf176226_00176321\n"
        /* } scope */
        ".Lf176226_001763c1:\n"
        "jp .Lf176226_0017627a\n" /* line 1775 */
        "cmpl 8(%ebx), %edx\n" /* line 839 */
        "jge .Lf176226_00176350\n"
        "movl 0x14(%ebx), %esi\n" /* line 846 */
        "movl %esi, -0x38(%ebp)\n"
        "andl $7, %esi\n"
        "je .Lf176226_00176662\n"
        ".Lf176226_001763db:\n"
        "addl $1, -0x38(%ebp)\n" /* line 852 */
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "jmp .Lf176226_00176356\n"
        ".Lf176226_001763ea:\n"
        "leal (, %edx, 8), %ecx\n" /* line 848 */
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 850 */
        "movl 0x14(%ebx), %esi\n"
        "movl %esi, -0x38(%ebp)\n"
        "addl $1, -0x38(%ebp)\n" /* line 852 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "jmp .Lf176226_0017637a\n"
        ".Lf176226_00176414:\n"
        "movl (%edi), %eax\n" /* line 1832 | bits */
        "testl %eax, %eax\n"
        "je .Lf176226_0017634b\n"
        /* { scope 2: bit, bit */
        "cmpl 8(%ebx), %edx\n" /* line 860 */
        "jl .Lf176226_001766fb\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        ".Lf176226_0017642d:\n"
        "movss lit4_002ed644, %xmm0\n" /* line 1123 | 182.04444885253906f */
        "mulss (%edi), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movzwl %ax, %esi\n" /* c */
        /* { scope 2: bit, bit */
        /* { scope 3 */
        "leal 2(%edx), %ecx\n" /* line 1023 */
        "cmpl 8(%ebx), %ecx\n" /* line 1024 */
        "jg .Lf176226_00176350\n"
        "movl 4(%ebx), %eax\n" /* line 1026 */
        "movw %si, (%eax, %edx)\n" /* bit */
        "movl %ecx, 0xc(%ebx)\n" /* line 1027 */
        "jmp .Lf176226_00176356\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit */
        ".Lf176226_0017645b:\n"
        "cmpl 8(%ebx), %edx\n" /* line 860 */
        "jl .Lf176226_00176501\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        ".Lf176226_0017646a:\n"
        "movl (%edi), %esi\n" /* line 1825 | bits */
        /* { scope 2: bit, bit */
        "leal 4(%edx), %ecx\n" /* line 1039 */
        "cmpl 8(%ebx), %ecx\n" /* line 1040 */
        "jg .Lf176226_00176350\n"
        "movl 4(%ebx), %eax\n" /* line 1042 */
        "movl %esi, (%eax, %edx)\n" /* bit */
        "movl %ecx, 0xc(%ebx)\n" /* line 1043 */
        "jmp .Lf176226_00176356\n"
        /* } scope */
        ".Lf176226_00176486:\n"
        "movss (%edi), %xmm1\n" /* line 1802 | bits */
        "cvttss2si %xmm1, %esi\n" /* line 1803 | bits */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 1805 | 0.0f */
        "jne .Lf176226_0017649d\n"
        "jnp .Lf176226_0017634b\n"
        /* { scope 2: bit, bit */
        ".Lf176226_0017649d:\n"
        "cmpl 8(%ebx), %edx\n" /* line 860 */
        "jl .Lf176226_001766a2\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        ".Lf176226_001764ac:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 1812 | bits */
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf176226_0017645b\n"
        "jp .Lf176226_0017645b\n"
        "addl $0x200, %esi\n" /* bits */
        "movl %esi, -0x18(%ebp)\n" /* bits */
        "js .Lf176226_0017645b\n"
        "cmpl $0x3ff, %esi\n" /* bits */
        "jg .Lf176226_0017645b\n"
        "cmpl 8(%ebx), %edx\n" /* line 839 */
        "jl .Lf176226_001768fd\n"
        "movl $1, (%ebx)\n" /* line 841 */
        /* { scope 2: bit, bit */
        /* { scope 3 */
        ".Lf176226_001764d9:\n"
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl %edx, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf176226_00176884\n"
        "movl $1, (%ebx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        ".Lf176226_001764ed:\n"
        "movl -0x18(%ebp), %ecx\n" /* line 1819 | c */
        "sarl $2, %ecx\n" /* c */
        /* { scope 2: bit, bit */
        "cmpl 8(%ebx), %edx\n" /* line 992 */
        "jge .Lf176226_00176350\n"
        "jmp .Lf176226_001762e5\n"
        /* } scope */
        /* { scope 2: bit, bit */
        ".Lf176226_00176501:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 866 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl %ecx, %esi\n" /* line 867 | bit */
        "andl $7, %esi\n" /* bit */
        "je .Lf176226_001765f9\n"
        ".Lf176226_00176512:\n"
        "sarl $3, -0x38(%ebp)\n" /* line 874 */
        "movl 4(%ebx), %ecx\n"
        "addl %ecx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %esi\n" /* bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edx\n"
        "jmp .Lf176226_0017646a\n"
        /* } scope */
        /* { scope 2: bit, bit */
        ".Lf176226_00176536:\n"
        "cmpl 8(%ebx), %edx\n" /* line 860 */
        "jl .Lf176226_00176619\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        ".Lf176226_00176545:\n"
        "movl (%edi), %edi\n" /* line 1854 | bits */
        "movl 8(%ebp), %edx\n" /* line 1856 | field, from */
        "movl 8(%edx), %eax\n" /* from */
        "cmpl $-0x62, %eax\n"
        "je .Lf176226_001766f1\n"
        "movl %eax, %esi\n" /* line 1863 | bits */
        "negl %eax\n"
        "cmpl $-1, %esi\n" /* bits */
        "cmovlel %eax, %esi\n" /* bits */
        "movl %esi, %ecx\n" /* line 1869 | bits */
        "andl $7, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "je .Lf176226_00176588\n"
        /* { scope 2: bit, bit */
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl 0xc(%ebx), %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf176226_001767fe\n"
        "movl $1, (%ebx)\n" /* line 812 */
        /* } scope */
        ".Lf176226_0017657f:\n"
        "subl -0x20(%ebp), %esi\n" /* line 1872 | bits */
        "movzbl -0x20(%ebp), %ecx\n" /* line 1873 */
        "sarl %cl, %edi\n" /* bits */
        ".Lf176226_00176588:\n"
        "testl %esi, %esi\n" /* line 1875 | bits */
        "je .Lf176226_00176356\n"
        ".Lf176226_00176590:\n"
        "movl 0xc(%ebx), %edx\n" /* msg, from */
        "jmp .Lf176226_001765b4\n"
        ".Lf176226_00176595:\n"
        "movl 4(%ebx), %eax\n" /* line 994 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax, %edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 995 */
        "addl $1, %eax\n"
        "movl %eax, %edx\n"
        "movl %eax, 0xc(%ebx)\n"
        ".Lf176226_001765a8:\n"
        "sarl $8, %edi\n" /* line 1878 | bits */
        "subl $8, %esi\n" /* line 1875 | bits */
        "je .Lf176226_00176356\n"
        ".Lf176226_001765b4:\n"
        "cmpl 8(%ebx), %edx\n" /* line 992 */
        "jl .Lf176226_00176595\n"
        "movl $1, (%ebx)\n" /* line 999 */
        "jmp .Lf176226_001765a8\n"
        /* { scope 2: bit, bit */
        ".Lf176226_001765c1:\n"
        "movl 0x14(%ebx), %eax\n" /* line 866 */
        "movl %eax, -0x38(%ebp)\n"
        "andl $7, %eax\n" /* line 867 */
        "movl %eax, -0x34(%ebp)\n" /* bit */
        "je .Lf176226_00176682\n"
        ".Lf176226_001765d3:\n"
        "sarl $3, -0x38(%ebp)\n" /* line 874 */
        "movl 4(%ebx), %edx\n"
        "addl %edx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movzbl -0x34(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edx\n"
        "jmp .Lf176226_00176289\n"
        /* } scope */
        /* { scope 2: bit, bit */
        ".Lf176226_001765f9:\n"
        "leal (, %edx, 8), %eax\n" /* line 869 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "jmp .Lf176226_00176512\n"
        /* } scope */
        /* { scope 2: bit, bit */
        ".Lf176226_00176619:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 866 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl %ecx, %esi\n" /* line 867 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf176226_00176641\n"
        "leal (, %edx, 8), %eax\n" /* line 869 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        ".Lf176226_00176641:\n"
        "sarl $3, -0x38(%ebp)\n" /* line 874 */
        "movl 4(%ebx), %ecx\n"
        "addl %ecx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %esi\n" /* bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "jmp .Lf176226_00176545\n"
        /* } scope */
        ".Lf176226_00176662:\n"
        "leal (, %edx, 8), %eax\n" /* line 848 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 850 */
        "movl 0x14(%ebx), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "jmp .Lf176226_001763db\n"
        /* { scope 2: bit, bit */
        ".Lf176226_00176682:\n"
        "leal (, %edx, 8), %ecx\n" /* line 869 */
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "jmp .Lf176226_001765d3\n"
        /* } scope */
        /* { scope 2: bit, bit */
        ".Lf176226_001766a2:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 866 */
        "movl %ecx, -0x38(%ebp)\n"
        "andl $7, %ecx\n" /* line 867 */
        "movl %ecx, -0x2c(%ebp)\n" /* bit */
        "jne .Lf176226_001766cb\n"
        "leal (, %edx, 8), %eax\n" /* line 869 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        ".Lf176226_001766cb:\n"
        "sarl $3, -0x38(%ebp)\n" /* line 874 */
        "movl 4(%ebx), %ecx\n"
        "addl %ecx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movzbl -0x2c(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edx\n"
        "jmp .Lf176226_001764ac\n"
        /* } scope */
        ".Lf176226_001766f1:\n"
        "movl $0x20, %esi\n" /* line 1856 | bits */
        "jmp .Lf176226_00176590\n"
        /* { scope 2: bit, bit */
        ".Lf176226_001766fb:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 866 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl %ecx, %esi\n" /* line 867 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf176226_00176723\n"
        "leal (, %edx, 8), %eax\n" /* line 869 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        ".Lf176226_00176723:\n"
        "sarl $3, -0x38(%ebp)\n" /* line 874 */
        "movl 4(%ebx), %ecx\n"
        "addl %ecx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %esi\n" /* bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edx\n"
        "jmp .Lf176226_0017642d\n"
        /* } scope */
        /* { scope 2: bit, bit */
        /* { scope 3 */
        ".Lf176226_00176747:\n"
        "movl -0x14(%ebp), %esi\n" /* line 812 */
        "movl $5, %edi\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf176226_0017675b\n"
        ".Lf176226_00176759:\n"
        "movl %eax, %edx\n"
        ".Lf176226_0017675b:\n"
        "subl $1, %edi\n" /* line 818 */
        "andl $7, %edx\n" /* line 820 */
        "movl %edx, -0x30(%ebp)\n" /* bit */
        "jne .Lf176226_00176784\n"
        "movl 0xc(%ebx), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 824 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        ".Lf176226_00176784:\n"
        "testl $1, %esi\n" /* line 827 */
        "je .Lf176226_001767ac\n"
        "sarl $3, -0x38(%ebp)\n" /* line 828 */
        "movl 4(%ebx), %edx\n"
        "addl %edx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movzbl -0x30(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        ".Lf176226_001767ac:\n"
        "addl $1, -0x38(%ebp)\n" /* line 829 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "sarl $1, %esi\n" /* line 830 */
        "testl %edi, %edi\n" /* line 816 */
        "jne .Lf176226_00176759\n"
        "movl 0xc(%ebx), %edx\n"
        "jmp .Lf176226_001762da\n"
        /* } scope */
        /* } scope */
        ".Lf176226_001767c4:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 846 */
        "movl %ecx, -0x38(%ebp)\n"
        "andb $7, %cl\n"
        "jne .Lf176226_001767ef\n"
        "leal (, %edx, 8), %esi\n" /* line 848 */
        "movl %esi, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %edx)\n"
        "movl 0xc(%ebx), %edx\n" /* line 850 */
        "addl $1, %edx\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        ".Lf176226_001767ef:\n"
        "addl $1, -0x38(%ebp)\n" /* line 852 */
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "jmp .Lf176226_001762c6\n"
        /* { scope 2: bit, bit */
        ".Lf176226_001767fe:\n"
        "movl %edi, -0x10(%ebp)\n" /* line 812 */
        "movl $0, -0x1c(%ebp)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf176226_00176853\n"
        ".Lf176226_00176812:\n"
        "sarl $3, -0x38(%ebp)\n" /* line 828 */
        "movl 4(%ebx), %edx\n"
        "addl %edx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movzbl -0x24(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl %ecx, %eax\n"
        ".Lf176226_00176834:\n"
        "addl $1, %eax\n" /* line 829 */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, 0x14(%ebx)\n"
        "sarl -0x10(%ebp)\n" /* line 830 */
        "addl $1, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 816 */
        "cmpl %eax, -0x20(%ebp)\n"
        "je .Lf176226_0017657f\n"
        "movl -0x38(%ebp), %edx\n"
        ".Lf176226_00176853:\n"
        "andl $7, %edx\n" /* line 820 */
        "movl %edx, -0x24(%ebp)\n" /* bit */
        "jne .Lf176226_00176879\n"
        "movl 0xc(%ebx), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 824 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        ".Lf176226_00176879:\n"
        "testb $1, -0x10(%ebp)\n" /* line 827 */
        "jne .Lf176226_00176812\n"
        "movl -0x38(%ebp), %eax\n"
        "jmp .Lf176226_00176834\n"
        /* } scope */
        /* { scope 2: bit, bit */
        /* { scope 3 */
        ".Lf176226_00176884:\n"
        "movl -0x18(%ebp), %esi\n" /* line 812 */
        "movl $2, %edi\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, %edx\n"
        ".Lf176226_00176894:\n"
        "subl $1, %edi\n" /* line 818 */
        "andl $7, %edx\n" /* line 820 */
        "movl %edx, -0x28(%ebp)\n" /* bit */
        "jne .Lf176226_001768bd\n"
        "movl 0xc(%ebx), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 824 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        ".Lf176226_001768bd:\n"
        "testl $1, %esi\n" /* line 827 */
        "je .Lf176226_001768e5\n"
        "sarl $3, -0x38(%ebp)\n" /* line 828 */
        "movl 4(%ebx), %edx\n"
        "addl %edx, -0x38(%ebp)\n"
        "movl $1, %eax\n"
        "movzbl -0x28(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "orb %al, (%edx)\n"
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        ".Lf176226_001768e5:\n"
        "addl $1, -0x38(%ebp)\n" /* line 829 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "sarl $1, %esi\n" /* line 830 */
        "testl %edi, %edi\n" /* line 816 */
        "jne .Lf176226_00176937\n"
        "movl 0xc(%ebx), %edx\n"
        "jmp .Lf176226_001764ed\n"
        /* } scope */
        /* } scope */
        ".Lf176226_001768fd:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 846 */
        "movl %ecx, -0x38(%ebp)\n"
        "andb $7, %cl\n"
        "jne .Lf176226_00176928\n"
        "leal (, %edx, 8), %esi\n" /* line 848 */
        "movl %esi, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movb $0, (%eax, %edx)\n"
        "movl 0xc(%ebx), %edx\n" /* line 850 */
        "addl $1, %edx\n"
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        ".Lf176226_00176928:\n"
        "addl $1, -0x38(%ebp)\n" /* line 852 */
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "jmp .Lf176226_001764d9\n"
        ".Lf176226_00176937:\n"
        "movl %eax, %edx\n"
        "jmp .Lf176226_00176894\n"
    );
}

/* line 2452 */
static __attribute__((naked))
void MSG_WriteDeltaHudElems(msg_t *msg, hudelem_t *from, hudelem_t *to, int count)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2452 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 8(%ebp), %ebx\n" /* count */
        /* { scope 1: bit */
        "testl %ebx, %ebx\n" /* line 2463 | count */
        "jle .Lf17693e_00176963\n"
        "movl %ecx, %edx\n"
        "movl (%ecx), %eax\n" /* line 2465 */
        "testl %eax, %eax\n"
        "jne .Lf17693e_00176b06\n"
        ".Lf17693e_00176963:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 2463 | inuse */
        /* { scope 2 */
        ".Lf17693e_0017696a:\n"
        "movl -0x34(%ebp), %edx\n" /* line 810 */
        "movl 8(%edx), %eax\n"
        "subl 0xc(%edx), %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf17693e_00176a9b\n"
        "movl $1, (%edx)\n" /* line 812 */
        /* } scope */
        ".Lf17693e_00176982:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2469 | inuse */
        "testl %eax, %eax\n"
        "jle .Lf17693e_001769f2\n"
        "movl -0x3c(%ebp), %ebx\n" /* count */
        "movl %ebx, -0x20(%ebp)\n" /* count */
        "movl -0x38(%ebp), %edi\n"
        "movl %edi, -0x50(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* i */
        ".Lf17693e_0017699c:\n"
        "xorl %ecx, %ecx\n"
        "xorl %esi, %esi\n" /* lc */
        "movl $hudElemFields, %ebx\n" /* count */
        ".Lf17693e_001769a5:\n"
        "movl 4(%ebx), %edx\n" /* line 2474 | count */
        "movl -0x50(%ebp), %edi\n" /* line 2476 */
        "movl (%edi, %edx), %eax\n"
        "movl -0x20(%ebp), %edi\n"
        "cmpl (%edi, %edx), %eax\n"
        "cmovnel %ecx, %esi\n" /* lc */
        "addl $1, %ecx\n" /* line 2472 */
        "addl $0xc, %ebx\n" /* count */
        "cmpl $0x20, %ecx\n"
        "jne .Lf17693e_001769a5\n"
        /* { scope 2 */
        "movl -0x34(%ebp), %edx\n" /* line 810 */
        "movl 8(%edx), %eax\n"
        "subl 0xc(%edx), %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf17693e_001769fa\n"
        "movl $1, (%edx)\n" /* line 812 */
        /* } scope */
        "testl %esi, %esi\n" /* line 2487 | lc */
        "jns .Lf17693e_00176a6d\n"
        ".Lf17693e_001769de:\n"
        "addl $1, -0x30(%ebp)\n" /* line 2469 | i */
        "subl $-0x80, -0x20(%ebp)\n"
        "subl $-0x80, -0x50(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* inuse */
        "cmpl %eax, -0x30(%ebp)\n" /* i */
        "jne .Lf17693e_0017699c\n"
        /* } scope */
        ".Lf17693e_001769f2:\n"
        "addl $0x5c, %esp\n" /* line 2496 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bit */
        /* { scope 2 */
        ".Lf17693e_001769fa:\n"
        "movl %esi, -0x4c(%ebp)\n" /* line 812 */
        "movl $5, -0x24(%ebp)\n"
        "movl 0x14(%edx), %ebx\n"
        ".Lf17693e_00176a07:\n"
        "movl %ebx, %edi\n" /* line 820 */
        "andl $7, %edi\n"
        "movl %edi, -0x28(%ebp)\n" /* bit */
        "jne .Lf17693e_00176a32\n"
        "movl -0x34(%ebp), %eax\n" /* line 822 */
        "movl 0xc(%eax), %edx\n"
        "leal (, %edx, 8), %ebx\n"
        "movl %ebx, 0x14(%eax)\n"
        "movl -0x34(%ebp), %ecx\n" /* line 823 */
        "movl 4(%ecx), %eax\n"
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ecx)\n" /* line 824 */
        "movl 0x14(%ecx), %ebx\n"
        ".Lf17693e_00176a32:\n"
        "testb $1, -0x4c(%ebp)\n" /* line 827 */
        "je .Lf17693e_00176a51\n"
        "sarl $3, %ebx\n" /* line 828 */
        "movl -0x34(%ebp), %edi\n"
        "addl 4(%edi), %ebx\n"
        "movl $1, %eax\n"
        "movzbl -0x28(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "movl 0x14(%edi), %ebx\n"
        ".Lf17693e_00176a51:\n"
        "leal 1(%ebx), %eax\n" /* line 829 */
        "movl %eax, %ebx\n"
        "movl -0x34(%ebp), %edi\n"
        "movl %eax, 0x14(%edi)\n"
        "sarl -0x4c(%ebp)\n" /* line 830 */
        "subl $1, -0x24(%ebp)\n" /* line 816 */
        "jne .Lf17693e_00176a07\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 2487 | lc */
        "js .Lf17693e_001769de\n"
        ".Lf17693e_00176a6d:\n"
        "movl $0, -0x1c(%ebp)\n"
        "movl $hudElemFields, %ebx\n" /* count */
        ".Lf17693e_00176a79:\n"
        "movl %ebx, (%esp)\n" /* line 2492 | count */
        "movl -0x20(%ebp), %ecx\n"
        "movl -0x50(%ebp), %edx\n"
        "movl -0x34(%ebp), %eax\n"
        "calll MSG_WriteDeltaField\n"
        "addl $1, -0x1c(%ebp)\n" /* line 2487 */
        "addl $0xc, %ebx\n" /* count */
        "cmpl %esi, -0x1c(%ebp)\n" /* lc */
        "jle .Lf17693e_00176a79\n"
        "jmp .Lf17693e_001769de\n"
        /* { scope 2 */
        ".Lf17693e_00176a9b:\n"
        "movl -0x2c(%ebp), %esi\n" /* line 812 | inuse */
        "movl $5, %edi\n"
        "movl 0x14(%edx), %ebx\n"
        ".Lf17693e_00176aa6:\n"
        "movl %ebx, %ecx\n" /* line 820 */
        "andl $7, %ecx\n"
        "jne .Lf17693e_00176ad4\n"
        "movl -0x34(%ebp), %ebx\n" /* line 822 */
        "movl 0xc(%ebx), %edx\n"
        "leal (, %edx, 8), %ebx\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %ebx, 0x14(%eax)\n"
        "movl -0x34(%ebp), %ebx\n" /* line 823 */
        "movl 4(%ebx), %eax\n"
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 824 */
        "movl -0x34(%ebp), %eax\n"
        "movl 0x14(%eax), %ebx\n"
        ".Lf17693e_00176ad4:\n"
        "testl $1, %esi\n" /* line 827 */
        "je .Lf17693e_00176af1\n"
        "sarl $3, %ebx\n" /* line 828 */
        "movl -0x34(%ebp), %edx\n"
        "addl 4(%edx), %ebx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "movl 0x14(%edx), %ebx\n"
        ".Lf17693e_00176af1:\n"
        "addl $1, %ebx\n" /* line 829 */
        "movl -0x34(%ebp), %ecx\n"
        "movl %ebx, 0x14(%ecx)\n"
        "sarl $1, %esi\n" /* line 830 */
        "subl $1, %edi\n" /* line 816 */
        "jne .Lf17693e_00176aa6\n"
        "jmp .Lf17693e_00176982\n"
        /* } scope */
        ".Lf17693e_00176b06:\n"
        "subl $-0x80, %edx\n" /* line 2466 */
        "movl $0, -0x2c(%ebp)\n" /* inuse */
        ".Lf17693e_00176b10:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 2463 | inuse */
        "cmpl -0x2c(%ebp), %ebx\n" /* inuse, count */
        "je .Lf17693e_0017696a\n"
        "movl (%edx), %eax\n" /* line 2465 */
        "subl $-0x80, %edx\n"
        "testl %eax, %eax\n"
        "jne .Lf17693e_00176b10\n"
        "jmp .Lf17693e_0017696a\n"
    );
}

/* line 1938 */
static __attribute__((naked))
void MSG_WriteDeltaStruct(byte *from, byte *to, qboolean force, int numFields, int indexBits, const NetField *stateFields, qboolean bChangeBit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1938 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, %esi\n" /* msg */
        "movl %edx, -0x2c(%ebp)\n"
        "movl %ecx, -0x30(%ebp)\n"
        /* { scope 1: value */
        "testl %ecx, %ecx\n" /* line 1946 */
        "je .Lf176b2c_00176e9d\n"
        "movl 0xc(%ebp), %edi\n" /* line 1964 | numFields, i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf176b2c_00176cc7\n"
        "movl 0x14(%ebp), %ebx\n" /* stateFields, field */
        "xorl %ecx, %ecx\n"
        "movl $0, -0x28(%ebp)\n" /* lc */
        "jmp .Lf176b2c_00176b6c\n"
        ".Lf176b2c_00176b5e:\n"
        "addl $1, %ecx\n" /* line 1973 */
        "movl %ecx, -0x28(%ebp)\n" /* lc */
        "addl $0xc, %ebx\n" /* line 1964 | field */
        "cmpl %ecx, 0xc(%ebp)\n" /* numFields */
        "jle .Lf176b2c_00176b88\n"
        ".Lf176b2c_00176b6c:\n"
        "movl 4(%ebx), %edx\n" /* line 1966 | field */
        "movl -0x2c(%ebp), %edi\n" /* line 1968 | i */
        "movl (%edi, %edx), %eax\n" /* i */
        "movl -0x30(%ebp), %edi\n" /* i */
        "cmpl (%edi, %edx), %eax\n" /* i */
        "jne .Lf176b2c_00176b5e\n"
        "addl $1, %ecx\n"
        "addl $0xc, %ebx\n" /* line 1964 | field */
        "cmpl %ecx, 0xc(%ebp)\n" /* numFields */
        "jg .Lf176b2c_00176b6c\n"
        ".Lf176b2c_00176b88:\n"
        "movl -0x28(%ebp), %eax\n" /* line 1978 | lc */
        "testl %eax, %eax\n"
        "je .Lf176b2c_00176cc7\n"
        "movl 0x18(%ebp), %eax\n" /* line 1995 | bChangeBit */
        "testl %eax, %eax\n"
        "je .Lf176b2c_00176d2d\n"
        /* { scope 2: bit, bit, bit */
        "movl 0xc(%esi), %edx\n" /* line 860 */
        "cmpl 8(%esi), %edx\n"
        "jge .Lf176b2c_00176e37\n"
        "movl 0x14(%esi), %ebx\n" /* line 866 */
        "movl %ebx, %ecx\n" /* line 867 */
        "andl $7, %ecx\n"
        "jne .Lf176b2c_00176bcc\n"
        "leal (, %edx, 8), %ebx\n" /* line 869 */
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 871 */
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176bcc:\n"
        "sarl $3, %ebx\n" /* line 874 */
        "addl 4(%esi), %ebx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "addl $1, 0x14(%esi)\n" /* line 875 */
        "movl 0xc(%esi), %edx\n"
        /* } scope */
        "movl -0x30(%ebp), %edi\n" /* line 1997 | i */
        "movl (%edi), %edi\n" /* i */
        "movl %edi, -0x3c(%ebp)\n" /* i, value */
        /* { scope 2: bit, bit, bit */
        /* { scope 3 */
        "movl 8(%esi), %eax\n" /* line 810 */
        "subl %edx, %eax\n"
        "cmpl $3, %eax\n"
        "jle .Lf176b2c_00176d46\n"
        ".Lf176b2c_00176bf8:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 816 | indexBits */
        "testl %ebx, %ebx\n"
        "je .Lf176b2c_00176d4c\n"
        "xorl %edi, %edi\n" /* line 812 */
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176c08:\n"
        "movl %ebx, %eax\n" /* line 820 */
        "andl $7, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* bit */
        "jne .Lf176b2c_00176c2d\n"
        "movl 0xc(%esi), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ebx\n"
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 824 */
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176c2d:\n"
        "testb $1, -0x3c(%ebp)\n" /* line 827 | value */
        "je .Lf176b2c_00176c49\n"
        "sarl $3, %ebx\n" /* line 828 */
        "addl 4(%esi), %ebx\n"
        "movl $1, %eax\n"
        "movzbl -0x1c(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176c49:\n"
        "addl $1, %ebx\n" /* line 829 */
        "movl %ebx, 0x14(%esi)\n"
        "sarl -0x3c(%ebp)\n" /* line 830 | value */
        "addl $1, %edi\n"
        "cmpl %edi, 0x10(%ebp)\n" /* line 816 | indexBits */
        "jne .Lf176b2c_00176c08\n"
        "movl 0xc(%esi), %edx\n"
        /* } scope */
        /* } scope */
        "cmpl 8(%esi), %edx\n" /* line 839 */
        "jge .Lf176b2c_00176d55\n"
        ".Lf176b2c_00176c66:\n"
        "movl 0x14(%esi), %ebx\n" /* line 846 */
        "testb $7, %bl\n"
        "je .Lf176b2c_00176e42\n"
        "addl $1, %ebx\n" /* line 852 */
        "movl %ebx, 0x14(%esi)\n"
        /* { scope 2: bit, bit, bit */
        ".Lf176b2c_00176c78:\n"
        "cmpl 8(%esi), %edx\n" /* line 860 */
        "jge .Lf176b2c_00176d64\n"
        ".Lf176b2c_00176c81:\n"
        "movl 0x14(%esi), %ebx\n" /* line 866 */
        "movl %ebx, %ecx\n" /* line 867 */
        "andl $7, %ecx\n"
        "je .Lf176b2c_00176e6a\n"
        "sarl $3, %ebx\n" /* line 874 */
        "addl 4(%esi), %ebx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "addl $1, 0x14(%esi)\n" /* line 875 */
        "movl 0xc(%esi), %edx\n"
        /* } scope */
        ".Lf176b2c_00176ca5:\n"
        "cmpl 8(%esi), %edx\n" /* line 992 */
        "jl .Lf176b2c_00176d73\n"
        ".Lf176b2c_00176cae:\n"
        "movl $1, (%esi)\n" /* line 999 */
        "movl -0x28(%ebp), %eax\n" /* line 2003 | lc */
        "testl %eax, %eax\n"
        "jg .Lf176b2c_00176d8c\n"
        /* } scope */
        ".Lf176b2c_00176cbf:\n"
        "addl $0x4c, %esp\n" /* line 2011 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value */
        ".Lf176b2c_00176cc7:\n"
        "movl 8(%ebp), %eax\n" /* line 1981 | force */
        "testl %eax, %eax\n"
        "je .Lf176b2c_00176cbf\n"
        "movl 0x18(%ebp), %eax\n" /* line 1986 | bChangeBit */
        "testl %eax, %eax\n"
        "je .Lf176b2c_00176db4\n"
        /* { scope 2: bit, bit, bit */
        "movl 0xc(%esi), %edx\n" /* line 860 */
        "cmpl 8(%esi), %edx\n"
        "jl .Lf176b2c_0017702f\n"
        "movl $1, (%esi)\n" /* line 862 */
        /* } scope */
        ".Lf176b2c_00176ceb:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1989 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* value */
        /* { scope 2: bit, bit, bit */
        /* { scope 3 */
        "movl 8(%esi), %eax\n" /* line 810 */
        "subl %edx, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf176b2c_00176dcd\n"
        ".Lf176b2c_00176d01:\n"
        "movl $1, (%esi)\n" /* line 812 */
        /* } scope */
        /* } scope */
        ".Lf176b2c_00176d07:\n"
        "cmpl 8(%esi), %edx\n" /* line 839 */
        "jl .Lf176b2c_00176f4f\n"
        "movl $1, (%esi)\n" /* line 841 */
        ".Lf176b2c_00176d16:\n"
        "cmpl 8(%esi), %edx\n" /* line 839 */
        "jl .Lf176b2c_00176f21\n"
        ".Lf176b2c_00176d1f:\n"
        "movl $1, (%esi)\n" /* line 841 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2011 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf176b2c_00176d2d:\n"
        "movl 0xc(%esi), %edx\n" /* msg */
        /* { scope 1: value */
        ".Lf176b2c_00176d30:\n"
        "movl -0x30(%ebp), %edi\n" /* line 1997 | i */
        "movl (%edi), %edi\n" /* i */
        "movl %edi, -0x3c(%ebp)\n" /* i, value */
        /* { scope 2: bit, bit, bit */
        /* { scope 3 */
        "movl 8(%esi), %eax\n" /* line 810 */
        "subl %edx, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf176b2c_00176bf8\n"
        ".Lf176b2c_00176d46:\n"
        "movl $1, (%esi)\n" /* line 812 */
        /* } scope */
        /* } scope */
        ".Lf176b2c_00176d4c:\n"
        "cmpl 8(%esi), %edx\n" /* line 839 */
        "jl .Lf176b2c_00176c66\n"
        ".Lf176b2c_00176d55:\n"
        "movl $1, (%esi)\n" /* line 841 */
        /* { scope 2: bit, bit, bit */
        "cmpl 8(%esi), %edx\n" /* line 860 */
        "jl .Lf176b2c_00176c81\n"
        ".Lf176b2c_00176d64:\n"
        "movl $1, (%esi)\n" /* line 862 */
        /* } scope */
        "cmpl 8(%esi), %edx\n" /* line 992 */
        "jge .Lf176b2c_00176cae\n"
        ".Lf176b2c_00176d73:\n"
        "movl 4(%esi), %eax\n" /* line 994 */
        "movzbl -0x28(%ebp), %ecx\n" /* lc */
        "movb %cl, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 995 */
        "movl -0x28(%ebp), %eax\n" /* line 2003 | lc */
        "testl %eax, %eax\n"
        "jle .Lf176b2c_00176cbf\n"
        ".Lf176b2c_00176d8c:\n"
        "movl 0x14(%ebp), %ebx\n" /* stateFields, field */
        "xorl %edi, %edi\n" /* i */
        ".Lf176b2c_00176d91:\n"
        "movl %ebx, (%esp)\n" /* line 2008 | field */
        "movl -0x30(%ebp), %ecx\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %esi, %eax\n" /* msg */
        "calll MSG_WriteDeltaField\n"
        "addl $1, %edi\n" /* line 2003 | i */
        "addl $0xc, %ebx\n" /* field */
        "cmpl -0x28(%ebp), %edi\n" /* lc, i */
        "jne .Lf176b2c_00176d91\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2011 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf176b2c_00176db4:\n"
        "movl 0xc(%esi), %edx\n" /* msg */
        /* { scope 1: value */
        "movl -0x30(%ebp), %eax\n" /* line 1989 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* value */
        /* { scope 2: bit, bit, bit */
        /* { scope 3 */
        "movl 8(%esi), %eax\n" /* line 810 */
        "subl %edx, %eax\n"
        "cmpl $3, %eax\n"
        "jle .Lf176b2c_00176d01\n"
        ".Lf176b2c_00176dcd:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 816 | indexBits */
        "testl %ecx, %ecx\n"
        "je .Lf176b2c_00176d07\n"
        "xorl %edi, %edi\n" /* line 812 */
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176ddd:\n"
        "movl %ebx, %edx\n" /* line 820 */
        "andl $7, %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* bit */
        "jne .Lf176b2c_00176e02\n"
        "movl 0xc(%esi), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ebx\n"
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 824 */
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176e02:\n"
        "testb $1, -0x3c(%ebp)\n" /* line 827 | value */
        "je .Lf176b2c_00176e1e\n"
        "sarl $3, %ebx\n" /* line 828 */
        "addl 4(%esi), %ebx\n"
        "movl $1, %eax\n"
        "movzbl -0x20(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176e1e:\n"
        "addl $1, %ebx\n" /* line 829 */
        "movl %ebx, 0x14(%esi)\n"
        "sarl -0x3c(%ebp)\n" /* line 830 | value */
        "addl $1, %edi\n"
        "cmpl 0x10(%ebp), %edi\n" /* line 816 | indexBits */
        "jne .Lf176b2c_00176ddd\n"
        "movl 0xc(%esi), %edx\n"
        "jmp .Lf176b2c_00176d07\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit, bit */
        ".Lf176b2c_00176e37:\n"
        "movl $1, (%esi)\n" /* line 862 */
        "jmp .Lf176b2c_00176d30\n"
        /* } scope */
        ".Lf176b2c_00176e42:\n"
        "leal (, %edx, 8), %ebx\n" /* line 848 */
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 849 */
        "movb $0, (%eax, %edx)\n"
        "movl 0xc(%esi), %edx\n" /* line 850 */
        "addl $1, %edx\n"
        "movl %edx, 0xc(%esi)\n"
        "movl 0x14(%esi), %ebx\n"
        "addl $1, %ebx\n" /* line 852 */
        "movl %ebx, 0x14(%esi)\n"
        "jmp .Lf176b2c_00176c78\n"
        /* { scope 2: bit, bit, bit */
        ".Lf176b2c_00176e6a:\n"
        "leal (, %edx, 8), %ebx\n" /* line 869 */
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 871 */
        "movl 0x14(%esi), %ebx\n"
        "sarl $3, %ebx\n" /* line 874 */
        "addl 4(%esi), %ebx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "addl $1, 0x14(%esi)\n" /* line 875 */
        "movl 0xc(%esi), %edx\n"
        "jmp .Lf176b2c_00176ca5\n"
        /* } scope */
        ".Lf176b2c_00176e9d:\n"
        "movl imp_cl_shownet, %eax\n" /* line 1950 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf176b2c_00176ed0\n"
        "movl 8(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "jle .Lf176b2c_00177054\n"
        ".Lf176b2c_00176eb4:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1951 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* msg */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ad9d0, (%esp)\n" /* "W|%3i: #%-3i remove
" */
        "calll Com_Printf\n"
        ".Lf176b2c_00176ed0:\n"
        "movl 0x18(%ebp), %eax\n" /* line 1953 | bChangeBit */
        "testl %eax, %eax\n"
        "je .Lf176b2c_00176f7f\n"
        /* { scope 2: bit, bit, bit */
        "movl 0xc(%esi), %edx\n" /* line 860 */
        "cmpl 8(%esi), %edx\n"
        "jge .Lf176b2c_0017707f\n"
        "movl 0x14(%esi), %ebx\n" /* line 866 */
        "movl %ebx, %ecx\n" /* line 867 */
        "andl $7, %ecx\n"
        "jne .Lf176b2c_00176f09\n"
        "leal (, %edx, 8), %ebx\n" /* line 869 */
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 871 */
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176f09:\n"
        "sarl $3, %ebx\n" /* line 874 */
        "addl 4(%esi), %ebx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "addl $1, 0x14(%esi)\n" /* line 875 */
        "movl 0xc(%esi), %edx\n"
        "jmp .Lf176b2c_00176f82\n"
        /* } scope */
        ".Lf176b2c_00176f21:\n"
        "movl 0x14(%esi), %ebx\n" /* line 846 */
        "testb $7, %bl\n"
        "jne .Lf176b2c_00176f41\n"
        "leal (, %edx, 8), %ebx\n" /* line 848 */
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 849 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 850 */
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176f41:\n"
        "addl $1, %ebx\n" /* line 852 */
        "movl %ebx, 0x14(%esi)\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2011 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value */
        ".Lf176b2c_00176f4f:\n"
        "movl 0x14(%esi), %ebx\n" /* line 846 */
        "testb $7, %bl\n"
        "jne .Lf176b2c_00176f74\n"
        "leal (, %edx, 8), %ebx\n" /* line 848 */
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 849 */
        "movb $0, (%eax, %edx)\n"
        "movl 0xc(%esi), %edx\n" /* line 850 */
        "addl $1, %edx\n"
        "movl %edx, 0xc(%esi)\n"
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176f74:\n"
        "addl $1, %ebx\n" /* line 852 */
        "movl %ebx, 0x14(%esi)\n"
        "jmp .Lf176b2c_00176d16\n"
        ".Lf176b2c_00176f7f:\n"
        "movl 0xc(%esi), %edx\n"
        ".Lf176b2c_00176f82:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 1955 */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n" /* value */
        /* { scope 2: bit, bit, bit */
        /* { scope 3 */
        "movl 8(%esi), %eax\n" /* line 810 */
        "subl %edx, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf176b2c_00176fc9\n"
        "movl $1, (%esi)\n" /* line 812 */
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit, bit */
        ".Lf176b2c_00176f9a:\n"
        "cmpl 8(%esi), %edx\n" /* line 860 */
        "jge .Lf176b2c_00176d1f\n"
        "movl 0x14(%esi), %ebx\n" /* line 866 */
        "movl %ebx, %ecx\n" /* line 867 */
        "andl $7, %ecx\n"
        "je .Lf176b2c_00177062\n"
        ".Lf176b2c_00176fb1:\n"
        "sarl $3, %ebx\n" /* line 874 */
        "addl 4(%esi), %ebx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "addl $1, 0x14(%esi)\n" /* line 875 */
        "jmp .Lf176b2c_00176cbf\n"
        /* } scope */
        /* { scope 2: bit, bit, bit */
        /* { scope 3 */
        ".Lf176b2c_00176fc9:\n"
        "movl 0x10(%ebp), %eax\n" /* line 816 | indexBits */
        "testl %eax, %eax\n"
        "je .Lf176b2c_00176f9a\n"
        "xorl %edi, %edi\n" /* line 812 */
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176fd5:\n"
        "movl %ebx, %eax\n" /* line 820 */
        "andl $7, %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* bit */
        "jne .Lf176b2c_00176ffa\n"
        "movl 0xc(%esi), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ebx\n"
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 824 */
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00176ffa:\n"
        "testb $1, -0x3c(%ebp)\n" /* line 827 | value */
        "je .Lf176b2c_00177016\n"
        "sarl $3, %ebx\n" /* line 828 */
        "addl 4(%esi), %ebx\n"
        "movl $1, %eax\n"
        "movzbl -0x24(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "movl 0x14(%esi), %ebx\n"
        ".Lf176b2c_00177016:\n"
        "addl $1, %ebx\n" /* line 829 */
        "movl %ebx, 0x14(%esi)\n"
        "sarl -0x3c(%ebp)\n" /* line 830 | value */
        "addl $1, %edi\n"
        "cmpl %edi, 0x10(%ebp)\n" /* line 816 | indexBits */
        "jne .Lf176b2c_00176fd5\n"
        "movl 0xc(%esi), %edx\n"
        "jmp .Lf176b2c_00176f9a\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit, bit */
        ".Lf176b2c_0017702f:\n"
        "movl 0x14(%esi), %ebx\n" /* line 866 */
        "movl %ebx, %ecx\n" /* line 867 */
        "andl $7, %ecx\n"
        "je .Lf176b2c_0017708a\n"
        ".Lf176b2c_00177039:\n"
        "sarl $3, %ebx\n" /* line 874 */
        "addl 4(%esi), %ebx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orb %al, (%ebx)\n"
        "addl $1, 0x14(%esi)\n" /* line 875 */
        "movl 0xc(%esi), %edx\n"
        "jmp .Lf176b2c_00176ceb\n"
        /* } scope */
        ".Lf176b2c_00177054:\n"
        "addl $1, %eax\n" /* line 1950 */
        "jne .Lf176b2c_00176ed0\n"
        "jmp .Lf176b2c_00176eb4\n"
        /* { scope 2: bit, bit, bit */
        ".Lf176b2c_00177062:\n"
        "leal (, %edx, 8), %ebx\n" /* line 869 */
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 871 */
        "movl 0x14(%esi), %ebx\n"
        "jmp .Lf176b2c_00176fb1\n"
        /* } scope */
        /* { scope 2: bit, bit, bit */
        ".Lf176b2c_0017707f:\n"
        "movl $1, (%esi)\n" /* line 862 */
        "jmp .Lf176b2c_00176f82\n"
        /* } scope */
        /* { scope 2: bit, bit, bit */
        ".Lf176b2c_0017708a:\n"
        "leal (, %edx, 8), %ebx\n" /* line 869 */
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%esi), %eax\n" /* line 870 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%esi)\n" /* line 871 */
        "movl 0x14(%esi), %ebx\n"
        "jmp .Lf176b2c_00177039\n"
    );
}

/* line 2083 */
__attribute__((naked))
void MSG_WriteDeltaClient(msg_t *msg, clientState_s *from, clientState_s *to, qboolean force)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2083 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x84, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* from */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 2098 */
        "je .Lf1770a4_001770ef\n"
        ".Lf1770a4_001770b5:\n"
        "movl $1, 0x10(%esp)\n" /* line 2107 */
        "movl $clientStateFields, 0xc(%esp)\n"
        "movl $6, 8(%esp)\n"
        "movl $0x16, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* force */
        "movl %eax, (%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* to */
        "movl 8(%ebp), %eax\n" /* msg */
        "calll MSG_WriteDeltaStruct\n"
        /* } scope */
        "addl $0x84, %esp\n" /* line 2109 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1770a4_001770ef:\n"
        "leal -0x64(%ebp), %ebx\n" /* line 2101 | dummy */
        "movl $0x5c, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memset\n"
        "movl %ebx, %edx\n"
        "jmp .Lf1770a4_001770b5\n"
    );
}

/* line 2055 */
__attribute__((naked))
void MSG_WriteDeltaArchivedEntity(msg_t *msg, archivedEntity_t *from, archivedEntity_t *to, qboolean force)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2055 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0xc(%ebp), %edx\n" /* from */
        "movl 0x10(%ebp), %ecx\n" /* to */
        "movl $0, 0x10(%esp)\n" /* line 2072 */
        "movl $archivedEntityFields, 0xc(%esp)\n"
        "movl $0xa, 8(%esp)\n"
        "movl $0x44, 4(%esp)\n"
        "movl 0x14(%ebp), %ebx\n" /* force */
        "movl %ebx, (%esp)\n" /* force */
        "calll MSG_WriteDeltaStruct\n"
        "addl $0x24, %esp\n" /* line 2074 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2025 */
__attribute__((naked))
void MSG_WriteDeltaEntity(msg_t *msg, entityState_s *from, entityState_s *to, qboolean force)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2025 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl 0xc(%ebp), %edx\n" /* from */
        "movl 0x10(%ebp), %ecx\n" /* to */
        "movl $0, 0x10(%esp)\n" /* line 2044 */
        "movl $entityStateFields, 0xc(%esp)\n"
        "movl $0xa, 8(%esp)\n"
        "movl $0x3b, 4(%esp)\n"
        "movl 0x14(%ebp), %ebx\n" /* force */
        "movl %ebx, (%esp)\n" /* force */
        "calll MSG_WriteDeltaStruct\n"
        "addl $0x24, %esp\n" /* line 2046 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2548 */
__attribute__((naked))
void MSG_WriteDeltaPlayerstate(msg_t *msg, playerState_s *from, playerState_s *to)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2548 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x279c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* msg */
        /* { scope 1: c, bit */
        "movl 0xc(%ebp), %eax\n" /* line 2564 | from */
        "testl %eax, %eax\n"
        "je .Lf177192_00178840\n"
        ".Lf177192_001771ac:\n"
        "movl $0, -0x271c(%ebp)\n" /* line 2567 | lc */
        "xorl %esi, %esi\n" /* bits */
        "movl $playerStateFields+4, %ecx\n"
        "jmp .Lf177192_001771d2\n"
        ".Lf177192_001771bf:\n"
        "leal 1(%esi), %eax\n" /* line 2582 | bits */
        "movl %eax, -0x271c(%ebp)\n" /* lc */
        "movl %eax, %esi\n" /* bits */
        "addl $0xc, %ecx\n"
        "cmpl $0x68, %esi\n" /* line 2573 | bits */
        "jg .Lf177192_001771ed\n"
        ".Lf177192_001771d2:\n"
        "movl (%ecx), %edx\n" /* line 2575 */
        "movl 0xc(%ebp), %edi\n" /* line 2577 | from */
        "movl (%edi, %edx), %eax\n"
        "movl 0x10(%ebp), %edi\n" /* to */
        "cmpl (%edi, %edx), %eax\n"
        "jne .Lf177192_001771bf\n"
        "addl $1, %esi\n" /* bits */
        "addl $0xc, %ecx\n" /* line 2582 */
        "cmpl $0x68, %esi\n" /* line 2573 | bits */
        "jle .Lf177192_001771d2\n"
        ".Lf177192_001771ed:\n"
        "movl 0xc(%ebx), %edx\n" /* line 992 */
        "movl %edx, -0x2738(%ebp)\n"
        "cmpl 8(%ebx), %edx\n"
        "jge .Lf177192_00177b41\n"
        "movl 4(%ebx), %eax\n" /* line 994 */
        "movzbl -0x271c(%ebp), %ecx\n" /* lc */
        "movb %cl, (%eax, %edx)\n"
        "movl 0xc(%ebx), %esi\n" /* line 995 | bit */
        "addl $1, %esi\n" /* bit */
        "movl %esi, -0x2738(%ebp)\n" /* bit */
        "movl %esi, 0xc(%ebx)\n" /* bit */
        ".Lf177192_0017721b:\n"
        "movl -0x271c(%ebp), %eax\n" /* line 2588 | lc */
        "testl %eax, %eax\n"
        "jle .Lf177192_0017730f\n"
        "movl $0, -0x2724(%ebp)\n" /* i */
        "movl $playerStateFields+4, -0x26e8(%ebp)\n"
        "movss lit4_002ed644, %xmm2\n" /* 182.04444885253906f */
        ".Lf177192_00177245:\n"
        "movl -0x26e8(%ebp), %edi\n" /* line 2590 */
        "movl (%edi), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* line 2591 | to */
        "addl %eax, %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* line 2593 | from */
        "movl (%ecx, %eax), %eax\n"
        "cmpl (%edx), %eax\n"
        "je .Lf177192_00177ac4\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        "movl -0x2738(%ebp), %eax\n" /* line 860 */
        "cmpl 8(%ebx), %eax\n"
        "jl .Lf177192_001778fb\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        "movl -0x26e8(%ebp), %ecx\n" /* line 2604 */
        "movl 4(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf177192_00177970\n"
        ".Lf177192_00177286:\n"
        "movss (%edx), %xmm1\n" /* line 2607 */
        "cvttss2si %xmm1, %eax\n" /* line 2608 */
        "cvtsi2ssl %eax, %xmm0\n" /* line 2610 */
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf177192_001772b1\n"
        "jp .Lf177192_001772b1\n"
        "addl $__mh_execute_header, %eax\n"
        "movl %eax, -0x26e4(%ebp)\n"
        "js .Lf177192_001772b1\n"
        "cmpl $0x1fff, %eax\n"
        "jle .Lf177192_00177bf2\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_001772b1:\n"
        "movl -0x2738(%ebp), %edi\n" /* line 860 */
        "cmpl 8(%ebx), %edi\n"
        "jl .Lf177192_00177afa\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        ".Lf177192_001772c6:\n"
        "movl (%edx), %ecx\n" /* line 2623 */
        /* { scope 2: bit, bit, newsize, bit, ... */
        "movl -0x2738(%ebp), %edx\n" /* line 1039 */
        "addl $4, %edx\n"
        "cmpl 8(%ebx), %edx\n" /* line 1040 */
        "jg .Lf177192_001778f0\n"
        "movl 4(%ebx), %eax\n" /* line 1042 */
        "movl -0x2738(%ebp), %esi\n" /* bit */
        "movl %ecx, (%eax, %esi)\n"
        "movl %edx, -0x2738(%ebp)\n" /* line 1043 */
        "movl %edx, 0xc(%ebx)\n"
        /* } scope */
        ".Lf177192_001772ef:\n"
        "addl $1, -0x2724(%ebp)\n" /* line 2588 | i */
        "addl $0xc, -0x26e8(%ebp)\n"
        "movl -0x2724(%ebp), %esi\n" /* i, bits */
        "cmpl %esi, -0x271c(%ebp)\n" /* bits, lc */
        "jne .Lf177192_00177245\n"
        ".Lf177192_0017730f:\n"
        "movl 0x10(%ebp), %edi\n" /* to */
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "movl 0xc(%ebp), %edx\n" /* from */
        "xorl %esi, %esi\n" /* bits */
        "movl $0, -0x2718(%ebp)\n" /* statsbits */
        "movl $1, %edi\n"
        ".Lf177192_0017732c:\n"
        "movl -0x275c(%ebp), %ecx\n" /* line 2667 | newsize */
        "movl 0x12c(%ecx), %eax\n"
        "cmpl 0x12c(%edx), %eax\n"
        "je .Lf177192_0017734c\n"
        "movl %edi, %eax\n" /* line 2669 | bits */
        "movl %esi, %ecx\n" /* bits */
        "shll %cl, %eax\n"
        "orl %eax, -0x2718(%ebp)\n" /* statsbits */
        ".Lf177192_0017734c:\n"
        "addl $1, %esi\n" /* line 2665 | bits */
        "addl $4, -0x275c(%ebp)\n" /* newsize */
        "addl $4, %edx\n"
        "cmpl $6, %esi\n" /* bits */
        "jne .Lf177192_0017732c\n"
        "movl -0x2718(%ebp), %eax\n" /* line 2673 | statsbits */
        "testl %eax, %eax\n"
        "je .Lf177192_00177b4c\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        "movl -0x2738(%ebp), %esi\n" /* line 860 | bit */
        "cmpl 8(%ebx), %esi\n" /* bit */
        "jl .Lf177192_00177c6f\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl -0x2738(%ebp), %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf177192_00177cc3\n"
        ".Lf177192_00177393:\n"
        "movl $1, (%ebx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        ".Lf177192_00177399:\n"
        "testb $1, -0x2718(%ebp)\n" /* line 2677 | statsbits */
        "je .Lf177192_001773c3\n"
        "movl 0x10(%ebp), %esi\n" /* line 2678 | to, bits */
        "movl 0x12c(%esi), %ecx\n" /* bits, c */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl -0x2738(%ebp), %edx\n" /* line 1023 */
        "addl $2, %edx\n"
        "cmpl 8(%ebx), %edx\n" /* line 1024 */
        "jle .Lf177192_001786dc\n"
        "movl $1, (%ebx)\n" /* line 1031 */
        /* } scope */
        /* } scope */
        ".Lf177192_001773c3:\n"
        "testb $2, -0x2718(%ebp)\n" /* line 2679 | statsbits */
        "je .Lf177192_001773ed\n"
        "movl 0x10(%ebp), %eax\n" /* line 2680 | to */
        "movl 0x130(%eax), %ecx\n" /* c */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl -0x2738(%ebp), %edx\n" /* line 1023 */
        "addl $2, %edx\n"
        "cmpl 8(%ebx), %edx\n" /* line 1024 */
        "jle .Lf177192_00178696\n"
        "movl $1, (%ebx)\n" /* line 1031 */
        /* } scope */
        /* } scope */
        ".Lf177192_001773ed:\n"
        "testb $4, -0x2718(%ebp)\n" /* line 2681 | statsbits */
        "je .Lf177192_00177417\n"
        "movl 0x10(%ebp), %edi\n" /* line 2682 | to, bits */
        "movl 0x134(%edi), %ecx\n" /* bits, c */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl -0x2738(%ebp), %edx\n" /* line 1023 */
        "addl $2, %edx\n"
        "cmpl 8(%ebx), %edx\n" /* line 1024 */
        "jle .Lf177192_0017867b\n"
        "movl $1, (%ebx)\n" /* line 1031 */
        /* } scope */
        /* } scope */
        ".Lf177192_00177417:\n"
        "testb $8, -0x2718(%ebp)\n" /* line 2683 | statsbits */
        "je .Lf177192_001774e0\n"
        "movl 0x10(%ebp), %edi\n" /* line 2684 | to, bits */
        "movl 0x138(%edi), %esi\n" /* bits, value */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl -0x2738(%ebp), %eax\n"
        "cmpl $3, %eax\n"
        "jle .Lf177192_00178670\n"
        "movl $6, %edi\n" /* line 812 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl %eax, %edx\n"
        "jmp .Lf177192_00177457\n"
        ".Lf177192_00177451:\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        ".Lf177192_00177457:\n"
        "subl $1, %edi\n" /* line 818 */
        "andl $7, %edx\n" /* line 820 */
        "movl %edx, -0x26fc(%ebp)\n" /* bit */
        "jne .Lf177192_00177486\n"
        "movl 0xc(%ebx), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 824 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00177486:\n"
        "testl $1, %esi\n" /* line 827 */
        "je .Lf177192_001774bd\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 828 | newsize */
        "movl 4(%ebx), %edx\n"
        "addl %edx, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movzbl -0x26fc(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        "orb %al, (%edx)\n"
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_001774bd:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 829 | newsize */
        "movl -0x275c(%ebp), %eax\n" /* newsize */
        "movl %eax, 0x14(%ebx)\n"
        "sarl $1, %esi\n" /* line 830 */
        "testl %edi, %edi\n" /* line 816 */
        "jne .Lf177192_00177451\n"
        "movl 0xc(%ebx), %edx\n"
        "movl %edx, -0x2738(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf177192_001774e0:\n"
        "testb $0x10, -0x2718(%ebp)\n" /* line 2685 | statsbits */
        "je .Lf177192_0017750a\n"
        "movl 0x10(%ebp), %esi\n" /* line 2686 | to, value */
        "movl 0x13c(%esi), %ecx\n" /* value, c */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl -0x2738(%ebp), %edx\n" /* line 1023 */
        "addl $2, %edx\n"
        "cmpl 8(%ebx), %edx\n" /* line 1024 */
        "jle .Lf177192_00178655\n"
        "movl $1, (%ebx)\n" /* line 1031 */
        /* } scope */
        /* } scope */
        ".Lf177192_0017750a:\n"
        "testb $0x20, -0x2718(%ebp)\n" /* line 2687 | statsbits */
        "je .Lf177192_00177531\n"
        "movl 0x10(%ebp), %eax\n" /* line 2688 | to */
        "movl 0x140(%eax), %edx\n" /* c */
        /* { scope 2: bit, bit, newsize, bit, ... */
        "movl -0x2738(%ebp), %ecx\n" /* line 992 */
        "cmpl 8(%ebx), %ecx\n"
        "jl .Lf177192_0017863b\n"
        /* } scope */
        ".Lf177192_0017752b:\n"
        "movl $1, (%ebx)\n" /* line 841 */
        ".Lf177192_00177531:\n"
        "movl $0, -0x2720(%ebp)\n" /* line 852 | j */
        "movl $0x140, -0x2748(%ebp)\n"
        "leal -0x28(%ebp), %edi\n" /* ammobits */
        ".Lf177192_00177548:\n"
        "movl $0, (%edi)\n" /* line 2708 | bits */
        "movl 0x10(%ebp), %edx\n" /* to */
        "movl -0x2748(%ebp), %ecx\n"
        "leal 4(%edx, %ecx), %edx\n"
        "movl %edx, -0x275c(%ebp)\n" /* newsize */
        "movl 0xc(%ebp), %esi\n" /* from, value */
        "leal 4(%esi, %ecx), %edx\n" /* value */
        "xorl %esi, %esi\n" /* value */
        ".Lf177192_0017756a:\n"
        "movl -0x275c(%ebp), %ecx\n" /* line 2711 | newsize */
        "movl (%ecx), %eax\n"
        "cmpl (%edx), %eax\n"
        "je .Lf177192_00177581\n"
        "movl $1, %eax\n" /* line 2713 */
        "movl %esi, %ecx\n" /* value */
        "shll %cl, %eax\n"
        "orl %eax, (%edi)\n" /* bits */
        ".Lf177192_00177581:\n"
        "addl $1, %esi\n" /* line 2709 | value */
        "addl $4, -0x275c(%ebp)\n" /* newsize */
        "addl $4, %edx\n"
        "cmpl $0x10, %esi\n" /* value */
        "jne .Lf177192_0017756a\n"
        "addl $1, -0x2720(%ebp)\n" /* line 2706 | j */
        "addl $4, %edi\n" /* bits */
        "addl $0x40, -0x2748(%ebp)\n"
        "cmpl $4, -0x2720(%ebp)\n" /* j */
        "jne .Lf177192_00177548\n"
        "movl -0x28(%ebp), %eax\n" /* line 2720 | ammobits */
        "testl %eax, %eax\n"
        "jne .Lf177192_001775c6\n"
        "movl -0x24(%ebp), %edi\n" /* bits */
        "testl %edi, %edi\n" /* bits */
        "jne .Lf177192_001775c6\n"
        "movl -0x20(%ebp), %esi\n" /* value */
        "testl %esi, %esi\n" /* value */
        "je .Lf177192_0017873d\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_001775c6:\n"
        "movl -0x2738(%ebp), %esi\n" /* line 860 | bit */
        "cmpl 8(%ebx), %esi\n" /* bit */
        "jl .Lf177192_0017827a\n"
        "movl $1, (%ebx)\n" /* line 862 */
        ".Lf177192_001775db:\n"
        "movl $0, -0x26dc(%ebp)\n" /* line 875 */
        "movl 0x10(%ebp), %eax\n" /* to */
        "addl $0x140, %eax\n"
        "movl %eax, -0x2744(%ebp)\n"
        /* } scope */
        ".Lf177192_001775f3:\n"
        "movl -0x26dc(%ebp), %edx\n" /* line 2725 */
        "movl -0x28(%ebp, %edx, 4), %edx\n"
        "movl %edx, -0x2728(%ebp)\n"
        "testl %edx, %edx\n"
        "je .Lf177192_00177d89\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        "movl -0x2738(%ebp), %ecx\n" /* line 860 */
        "cmpl 8(%ebx), %ecx\n"
        "jl .Lf177192_00177ec1\n"
        "movl $1, (%ebx)\n" /* line 862 */
        "movl -0x2738(%ebp), %edx\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        "addl $2, %edx\n" /* line 1023 */
        "cmpl 8(%ebx), %edx\n" /* line 1024 */
        "jg .Lf177192_00177f33\n"
        ".Lf177192_00177632:\n"
        "movl 4(%ebx), %eax\n" /* line 1026 */
        "movl -0x2728(%ebp), %esi\n" /* bit */
        "movl -0x2738(%ebp), %ecx\n"
        "movw %si, (%eax, %ecx)\n" /* bit */
        "movl %edx, -0x2738(%ebp)\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n"
        ".Lf177192_0017764e:\n"
        "movl -0x2744(%ebp), %edx\n" /* line 1031 */
        "addl $4, %edx\n"
        "xorl %esi, %esi\n" /* bit */
        "jmp .Lf177192_00177682\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        ".Lf177192_0017765b:\n"
        "movl 4(%ebx), %ecx\n" /* line 1026 */
        "movl -0x2738(%ebp), %eax\n"
        "movw %di, (%ecx, %eax)\n"
        "movl -0x275c(%ebp), %ecx\n" /* line 1027 | newsize */
        "movl %ecx, -0x2738(%ebp)\n"
        "movl %ecx, 0xc(%ebx)\n"
        /* } scope */
        /* } scope */
        ".Lf177192_00177677:\n"
        "addl $1, %esi\n" /* line 2729 | value */
        "addl $4, %edx\n"
        "cmpl $0x10, %esi\n" /* value */
        "je .Lf177192_001776bd\n"
        ".Lf177192_00177682:\n"
        "movl -0x2728(%ebp), %eax\n" /* line 2730 */
        "movl %esi, %ecx\n" /* value */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf177192_00177677\n"
        "movl (%edx), %edi\n" /* line 2731 | bits */
        "movl %edi, -0x276c(%ebp)\n" /* bits, c */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl -0x2738(%ebp), %eax\n" /* line 1023 */
        "addl $2, %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "cmpl 8(%ebx), %eax\n" /* line 1024 */
        "jle .Lf177192_0017765b\n"
        "movl $1, (%ebx)\n" /* line 1031 */
        /* } scope */
        /* } scope */
        "addl $1, %esi\n" /* line 2729 | value */
        "addl $4, %edx\n"
        "cmpl $0x10, %esi\n" /* value */
        "jne .Lf177192_00177682\n"
        ".Lf177192_001776bd:\n"
        "addl $1, -0x26dc(%ebp)\n" /* line 2723 */
        "addl $0x40, -0x2744(%ebp)\n"
        "cmpl $4, -0x26dc(%ebp)\n"
        "jne .Lf177192_001775f3\n"
        ".Lf177192_001776d8:\n"
        "movl $0, -0x26f0(%ebp)\n" /* line 852 */
        "movl 0x10(%ebp), %ecx\n" /* to */
        "addl $0x340, %ecx\n"
        "movl %ecx, -0x273c(%ebp)\n"
        "movl $0x340, -0x2740(%ebp)\n"
        ".Lf177192_001776fb:\n"
        "movl 0x10(%ebp), %esi\n" /* to */
        "movl -0x2740(%ebp), %eax\n"
        "leal 4(%esi, %eax), %edi\n"
        "movl 0xc(%ebp), %ecx\n" /* from */
        "leal 4(%ecx, %eax), %edx\n"
        "xorl %esi, %esi\n"
        "movl $0, -0x2714(%ebp)\n" /* clipbits */
        ".Lf177192_0017771b:\n"
        "movl (%edi), %eax\n" /* line 2750 | bits */
        "cmpl (%edx), %eax\n"
        "je .Lf177192_00177730\n"
        "movl $1, %eax\n" /* line 2752 */
        "movl %esi, %ecx\n" /* value */
        "shll %cl, %eax\n"
        "orl %eax, -0x2714(%ebp)\n" /* clipbits */
        ".Lf177192_00177730:\n"
        "addl $1, %esi\n" /* line 2748 | value */
        "addl $4, %edi\n" /* bits */
        "addl $4, %edx\n"
        "cmpl $0x10, %esi\n" /* value */
        "jne .Lf177192_0017771b\n"
        "movl -0x2714(%ebp), %edx\n" /* line 2755 | clipbits */
        "testl %edx, %edx\n"
        "je .Lf177192_00177d6f\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        "movl -0x2738(%ebp), %esi\n" /* line 860 | bit */
        "cmpl 8(%ebx), %esi\n" /* bit */
        "jl .Lf177192_00177dae\n"
        "movl $1, (%ebx)\n" /* line 862 */
        "movl -0x2738(%ebp), %edx\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177767:\n"
        "addl $2, %edx\n" /* line 1023 */
        "cmpl 8(%ebx), %edx\n" /* line 1024 */
        "jg .Lf177192_00177da3\n"
        "movl 4(%ebx), %eax\n" /* line 1026 */
        "movl -0x2714(%ebp), %esi\n" /* clipbits, bit */
        "movl -0x2738(%ebp), %ecx\n"
        "movw %si, (%eax, %ecx)\n" /* bit */
        "movl %edx, -0x2738(%ebp)\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n"
        ".Lf177192_0017778f:\n"
        "movl -0x273c(%ebp), %edx\n" /* line 1031 */
        "addl $4, %edx\n"
        "xorl %esi, %esi\n" /* bit */
        "jmp .Lf177192_001777c3\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        ".Lf177192_0017779c:\n"
        "movl 4(%ebx), %ecx\n" /* line 1026 */
        "movl -0x2738(%ebp), %eax\n"
        "movw %di, (%ecx, %eax)\n"
        "movl -0x275c(%ebp), %ecx\n" /* line 1027 | newsize */
        "movl %ecx, -0x2738(%ebp)\n"
        "movl %ecx, 0xc(%ebx)\n"
        /* } scope */
        /* } scope */
        ".Lf177192_001777b8:\n"
        "addl $1, %esi\n" /* line 2759 | value */
        "addl $4, %edx\n"
        "cmpl $0x10, %esi\n" /* value */
        "je .Lf177192_001777fe\n"
        ".Lf177192_001777c3:\n"
        "movl -0x2714(%ebp), %eax\n" /* line 2760 | clipbits */
        "movl %esi, %ecx\n" /* value */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf177192_001777b8\n"
        "movl (%edx), %edi\n" /* line 2761 | bits */
        "movl %edi, -0x276c(%ebp)\n" /* bits, c */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl -0x2738(%ebp), %eax\n" /* line 1023 */
        "addl $2, %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "cmpl 8(%ebx), %eax\n" /* line 1024 */
        "jle .Lf177192_0017779c\n"
        "movl $1, (%ebx)\n" /* line 1031 */
        /* } scope */
        /* } scope */
        "addl $1, %esi\n" /* line 2759 | value */
        "addl $4, %edx\n"
        "cmpl $0x10, %esi\n" /* value */
        "jne .Lf177192_001777c3\n"
        ".Lf177192_001777fe:\n"
        "addl $0x10, -0x26f0(%ebp)\n" /* line 852 */
        "addl $0x40, -0x2740(%ebp)\n"
        "addl $0x40, -0x273c(%ebp)\n"
        "cmpl $0x40, -0x26f0(%ebp)\n" /* line 2745 */
        "jne .Lf177192_001776fb\n"
        "movl 0xc(%ebp), %eax\n" /* line 2770 | from */
        "addl $0x5e4, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* to */
        "addl $0x5e4, %edx\n"
        "movl $0x1c0, -0x272c(%ebp)\n"
        "cld\n"
        "movl %eax, %esi\n" /* value */
        "movl %edx, %edi\n" /* bits */
        "movl $0x1c0, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* bits, value */
        "movl $0, %eax\n"
        "je .Lf177192_00177858\n"
        "movzbl -1(%esi), %eax\n" /* value */
        "movzbl -1(%edi), %ecx\n" /* bits */
        "subl %ecx, %eax\n"
        ".Lf177192_00177858:\n"
        "testl %eax, %eax\n"
        "jne .Lf177192_00177fe8\n"
        "movl -0x2738(%ebp), %ecx\n" /* line 839 */
        "cmpl 8(%ebx), %ecx\n"
        "jl .Lf177192_00178321\n"
        "movl $1, (%ebx)\n" /* line 841 */
        ".Lf177192_00177875:\n"
        "movl 0xc(%ebp), %eax\n" /* line 2790 | from */
        "addl $0x7a8, %eax\n"
        "movl %eax, -0x2730(%ebp)\n"
        "movl 0x10(%ebp), %edx\n" /* to */
        "addl $0x7a8, %edx\n"
        "movl %edx, -0x2734(%ebp)\n"
        "movl $0x1f00, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n" /* value */
        "movl %edx, %edi\n" /* bits */
        "repe cmpsb %es:(%edi), (%esi)\n" /* bits, value */
        "movl $0, %eax\n"
        "je .Lf177192_001778af\n"
        "movzbl -1(%esi), %eax\n" /* value */
        "movzbl -1(%edi), %ecx\n" /* bits */
        "subl %ecx, %eax\n"
        ".Lf177192_001778af:\n"
        "testl %eax, %eax\n"
        "jne .Lf177192_00177f3e\n"
        "movl -0x2738(%ebp), %ecx\n" /* line 839 */
        "cmpl 8(%ebx), %ecx\n"
        "jl .Lf177192_00178348\n"
        "movl $1, (%ebx)\n" /* line 841 */
        /* } scope */
        "addl $0x279c, %esp\n" /* line 2814 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: c, bit */
        ".Lf177192_001778d7:\n"
        "movl (%edx), %eax\n" /* line 2629 */
        "testl %eax, %eax\n"
        "jne .Lf177192_001783ba\n"
        "movl -0x2738(%ebp), %edi\n" /* line 839 */
        "cmpl 8(%ebx), %edi\n"
        "jl .Lf177192_001787ab\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        ".Lf177192_001778f0:\n"
        "movl $1, (%ebx)\n" /* line 1031 */
        "jmp .Lf177192_001772ef\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_001778fb:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 866 */
        "movl %ecx, -0x275c(%ebp)\n" /* newsize */
        "movl %ecx, %esi\n" /* line 867 | bit */
        "andl $7, %esi\n" /* bit */
        "jne .Lf177192_00177931\n"
        "movl -0x2738(%ebp), %edi\n" /* line 869 */
        "shll $3, %edi\n"
        "movl %edi, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %ecx\n"
        "movb $0, (%eax, %ecx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %edi\n"
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00177931:\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %eax\n"
        "addl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        /* } scope */
        "movl -0x26e8(%ebp), %ecx\n" /* line 2604 */
        "movl 4(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf177192_00177286\n"
        ".Lf177192_00177970:\n"
        "cmpl $-0x64, %eax\n" /* line 2626 */
        "je .Lf177192_001778d7\n"
        "movl (%edx), %edx\n" /* line 2643 */
        "movl %edx, -0x2710(%ebp)\n" /* value */
        "movl %eax, %esi\n" /* line 2644 | bits */
        "negl %eax\n"
        "cmpl $-1, %esi\n" /* bits */
        "cmovlel %eax, %esi\n" /* bits */
        "movl %esi, %edi\n" /* line 2646 | bits */
        "andl $7, %edi\n" /* bits */
        "movl %edi, -0x270c(%ebp)\n" /* bits, partialBits */
        "je .Lf177192_00177a7b\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl -0x2738(%ebp), %eax\n"
        "cmpl $3, %eax\n"
        "jle .Lf177192_00177c51\n"
        "movl -0x2710(%ebp), %edi\n" /* line 812 | value */
        "movl $0, -0x26ec(%ebp)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl %eax, %edx\n"
        "jmp .Lf177192_001779d1\n"
        ".Lf177192_001779cb:\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        ".Lf177192_001779d1:\n"
        "andl $7, %edx\n" /* line 820 */
        "movl %edx, -0x2704(%ebp)\n" /* bit */
        "jne .Lf177192_001779fd\n"
        "movl 0xc(%ebx), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 824 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_001779fd:\n"
        "testl $1, %edi\n" /* line 827 */
        "je .Lf177192_00177a34\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 828 | newsize */
        "movl 4(%ebx), %edx\n"
        "addl %edx, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movzbl -0x2704(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        "orb %al, (%edx)\n"
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00177a34:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 829 | newsize */
        "movl -0x275c(%ebp), %eax\n" /* newsize */
        "movl %eax, 0x14(%ebx)\n"
        "sarl $1, %edi\n" /* line 830 */
        "addl $1, -0x26ec(%ebp)\n"
        "movl -0x26ec(%ebp), %edx\n" /* line 816 */
        "cmpl %edx, -0x270c(%ebp)\n" /* partialBits */
        "jne .Lf177192_001779cb\n"
        "movl 0xc(%ebx), %ecx\n"
        "movl %ecx, -0x2738(%ebp)\n"
        /* } scope */
        "subl -0x270c(%ebp), %esi\n" /* line 2649 | partialBits, bits */
        "movzbl -0x270c(%ebp), %ecx\n" /* line 2650 | partialBits */
        "sarl %cl, -0x2710(%ebp)\n" /* value */
        ".Lf177192_00177a7b:\n"
        "testl %esi, %esi\n" /* line 2652 | bits */
        "je .Lf177192_001772ef\n"
        "jmp .Lf177192_00177ab1\n"
        ".Lf177192_00177a85:\n"
        "movl 4(%ebx), %eax\n" /* line 994 */
        "movzbl -0x2710(%ebp), %edx\n" /* value */
        "movb %dl, (%eax, %edi)\n"
        "movl 0xc(%ebx), %ecx\n" /* line 995 */
        "addl $1, %ecx\n"
        "movl %ecx, -0x2738(%ebp)\n"
        "movl %ecx, 0xc(%ebx)\n"
        ".Lf177192_00177aa1:\n"
        "sarl $8, -0x2710(%ebp)\n" /* line 2655 | value */
        "subl $8, %esi\n" /* line 2652 | bits */
        "je .Lf177192_001772ef\n"
        ".Lf177192_00177ab1:\n"
        "movl -0x2738(%ebp), %edi\n" /* line 992 */
        "cmpl 8(%ebx), %edi\n"
        "jl .Lf177192_00177a85\n"
        "movl $1, (%ebx)\n" /* line 999 */
        "jmp .Lf177192_00177aa1\n"
        ".Lf177192_00177ac4:\n"
        "movl -0x2738(%ebp), %esi\n" /* line 839 */
        "cmpl 8(%ebx), %esi\n"
        "jge .Lf177192_001778f0\n"
        "movl 0x14(%ebx), %edi\n" /* line 846 */
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "andl $7, %edi\n"
        "je .Lf177192_00177b81\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %edi\n" /* newsize */
        "movl %edi, 0x14(%ebx)\n"
        "jmp .Lf177192_001772ef\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177afa:\n"
        "movl 0x14(%ebx), %eax\n" /* line 866 */
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl %eax, %esi\n" /* line 867 | bit */
        "andl $7, %esi\n" /* bit */
        "je .Lf177192_00177bc7\n"
        ".Lf177192_00177b0e:\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %ecx\n"
        "addl %ecx, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        "jmp .Lf177192_001772c6\n"
        /* } scope */
        ".Lf177192_00177b41:\n"
        "movl $1, (%ebx)\n" /* line 999 */
        "jmp .Lf177192_0017721b\n"
        ".Lf177192_00177b4c:\n"
        "movl -0x2738(%ebp), %edi\n" /* line 839 */
        "cmpl 8(%ebx), %edi\n"
        "jge .Lf177192_0017752b\n"
        "movl 0x14(%ebx), %eax\n" /* line 846 */
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "testb $7, %al\n"
        "je .Lf177192_001786f7\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %eax\n" /* newsize */
        "movl %eax, 0x14(%ebx)\n"
        "jmp .Lf177192_00177531\n"
        ".Lf177192_00177b81:\n"
        "movl -0x2738(%ebp), %eax\n" /* line 848 */
        "shll $3, %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %edx\n"
        "movb $0, (%eax, %edx)\n"
        "movl 0xc(%ebx), %ecx\n" /* line 850 */
        "addl $1, %ecx\n"
        "movl %ecx, -0x2738(%ebp)\n"
        "movl %ecx, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %esi\n"
        "movl %esi, -0x275c(%ebp)\n" /* newsize */
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %edi\n" /* newsize */
        "movl %edi, 0x14(%ebx)\n"
        "jmp .Lf177192_001772ef\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177bc7:\n"
        "movl -0x2738(%ebp), %ecx\n" /* line 869 */
        "shll $3, %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %edi\n"
        "movb $0, (%eax, %edi)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "jmp .Lf177192_00177b0e\n"
        /* } scope */
        ".Lf177192_00177bf2:\n"
        "movl -0x2738(%ebp), %esi\n" /* line 839 */
        "cmpl 8(%ebx), %esi\n"
        "jl .Lf177192_00178430\n"
        "movl $1, (%ebx)\n" /* line 841 */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl -0x2738(%ebp), %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf177192_00178491\n"
        ".Lf177192_00177c19:\n"
        "movl $1, (%ebx)\n" /* line 812 */
        "movl -0x2738(%ebp), %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf177192_00177c25:\n"
        "movl -0x26e4(%ebp), %edx\n" /* line 2617 | c */
        "sarl $5, %edx\n" /* c */
        /* { scope 2: bit, bit, newsize, bit, ... */
        "cmpl 8(%ebx), %ecx\n" /* line 992 */
        "jge .Lf177192_001778f0\n"
        "movl 4(%ebx), %eax\n" /* line 994 */
        "movb %dl, (%eax, %ecx)\n"
        "movl 0xc(%ebx), %esi\n" /* line 995 | bit */
        "addl $1, %esi\n" /* bit */
        "movl %esi, -0x2738(%ebp)\n" /* bit */
        "movl %esi, 0xc(%ebx)\n" /* bit */
        "jmp .Lf177192_001772ef\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177c51:\n"
        "movl $1, (%ebx)\n" /* line 812 */
        /* } scope */
        "subl -0x270c(%ebp), %esi\n" /* line 2649 | partialBits, bits */
        "movzbl -0x270c(%ebp), %ecx\n" /* line 2650 | partialBits */
        "sarl %cl, -0x2710(%ebp)\n" /* value */
        "jmp .Lf177192_00177a7b\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177c6f:\n"
        "movl 0x14(%ebx), %edi\n" /* line 866 */
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "movl %edi, %edx\n" /* line 867 */
        "andl $7, %edx\n"
        "je .Lf177192_001786b1\n"
        ".Lf177192_00177c83:\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %edi\n"
        "addl %edi, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl -0x2738(%ebp), %eax\n"
        "cmpl $3, %eax\n"
        "jle .Lf177192_00177393\n"
        ".Lf177192_00177cc3:\n"
        "movl -0x2718(%ebp), %esi\n" /* line 812 | statsbits */
        "movl $6, %edi\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl %eax, %edx\n"
        "jmp .Lf177192_00177ce1\n"
        ".Lf177192_00177cdb:\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        ".Lf177192_00177ce1:\n"
        "subl $1, %edi\n" /* line 818 */
        "andl $7, %edx\n" /* line 820 */
        "movl %edx, -0x2700(%ebp)\n" /* bit */
        "jne .Lf177192_00177d10\n"
        "movl 0xc(%ebx), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 824 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00177d10:\n"
        "testl $1, %esi\n" /* line 827 */
        "je .Lf177192_00177d47\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 828 | newsize */
        "movl 4(%ebx), %edx\n"
        "addl %edx, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movzbl -0x2700(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        "orb %al, (%edx)\n"
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00177d47:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 829 | newsize */
        "movl -0x275c(%ebp), %eax\n" /* newsize */
        "movl %eax, 0x14(%ebx)\n"
        "sarl $1, %esi\n" /* line 830 */
        "testl %edi, %edi\n" /* line 816 */
        "jne .Lf177192_00177cdb\n"
        "movl 0xc(%ebx), %edx\n"
        "movl %edx, -0x2738(%ebp)\n"
        "jmp .Lf177192_00177399\n"
        /* } scope */
        /* } scope */
        ".Lf177192_00177d6f:\n"
        "movl -0x2738(%ebp), %esi\n" /* line 839 */
        "cmpl 8(%ebx), %esi\n"
        "jl .Lf177192_00177e19\n"
        "movl $1, (%ebx)\n" /* line 841 */
        "jmp .Lf177192_001777fe\n"
        ".Lf177192_00177d89:\n"
        "movl -0x2738(%ebp), %esi\n" /* line 839 */
        "cmpl 8(%ebx), %esi\n"
        "jl .Lf177192_00177e6d\n"
        "movl $1, (%ebx)\n" /* line 841 */
        "jmp .Lf177192_001776bd\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177da3:\n"
        "movl $1, (%ebx)\n" /* line 1031 */
        "jmp .Lf177192_0017778f\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177dae:\n"
        "movl 0x14(%ebx), %edi\n" /* line 866 */
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "movl %edi, %edx\n" /* line 867 */
        "andl $7, %edx\n"
        "jne .Lf177192_00177de4\n"
        "movl -0x2738(%ebp), %eax\n" /* line 869 */
        "shll $3, %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %ecx\n"
        "movb $0, (%eax, %ecx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %esi\n" /* bit */
        "movl %esi, -0x275c(%ebp)\n" /* bit, newsize */
        ".Lf177192_00177de4:\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %edi\n"
        "addl %edi, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        "movl %edi, %edx\n"
        "jmp .Lf177192_00177767\n"
        /* } scope */
        ".Lf177192_00177e19:\n"
        "movl 0x14(%ebx), %edi\n" /* line 846 */
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "andl $7, %edi\n"
        "jne .Lf177192_00177e58\n"
        "movl -0x2738(%ebp), %eax\n" /* line 848 */
        "shll $3, %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %edx\n"
        "movb $0, (%eax, %edx)\n"
        "movl 0xc(%ebx), %ecx\n" /* line 850 */
        "addl $1, %ecx\n"
        "movl %ecx, -0x2738(%ebp)\n"
        "movl %ecx, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %esi\n"
        "movl %esi, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00177e58:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %edi\n" /* newsize */
        "movl %edi, 0x14(%ebx)\n"
        "jmp .Lf177192_001777fe\n"
        ".Lf177192_00177e6d:\n"
        "movl 0x14(%ebx), %edi\n" /* line 846 */
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "andl $7, %edi\n"
        "jne .Lf177192_00177eac\n"
        "movl -0x2738(%ebp), %eax\n" /* line 848 */
        "shll $3, %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %edx\n"
        "movb $0, (%eax, %edx)\n"
        "movl 0xc(%ebx), %ecx\n" /* line 850 */
        "addl $1, %ecx\n"
        "movl %ecx, -0x2738(%ebp)\n"
        "movl %ecx, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %esi\n"
        "movl %esi, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00177eac:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %edi\n" /* newsize */
        "movl %edi, 0x14(%ebx)\n"
        "jmp .Lf177192_001776bd\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177ec1:\n"
        "movl 0x14(%ebx), %esi\n" /* line 866 | bit */
        "movl %esi, -0x275c(%ebp)\n" /* bit, newsize */
        "movl %esi, %edx\n" /* line 867 | bit */
        "andl $7, %edx\n"
        "jne .Lf177192_00177ef7\n"
        "movl -0x2738(%ebp), %edi\n" /* line 869 */
        "shll $3, %edi\n"
        "movl %edi, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %ecx\n"
        "movb $0, (%eax, %ecx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %esi\n" /* bit */
        "movl %esi, -0x275c(%ebp)\n" /* bit, newsize */
        ".Lf177192_00177ef7:\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %edi\n"
        "addl %edi, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        "movl %edi, %edx\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        "addl $2, %edx\n" /* line 1023 */
        "cmpl 8(%ebx), %edx\n" /* line 1024 */
        "jle .Lf177192_00177632\n"
        ".Lf177192_00177f33:\n"
        "movl $1, (%ebx)\n" /* line 1031 */
        "jmp .Lf177192_0017764e\n"
        /* } scope */
        ".Lf177192_00177f3e:\n"
        "movl $0x1f, %eax\n" /* line 852 */
        ".Lf177192_00177f43:\n"
        "subl $1, %eax\n" /* line 2533 | i */
        "jne .Lf177192_00177f43\n"
        "xorl %eax, %eax\n" /* i */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177f4a:\n"
        "addl $1, %eax\n" /* i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf177192_00177f4a\n"
        "xorb %al, %al\n" /* i */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177f54:\n"
        "addl $1, %eax\n" /* i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf177192_00177f54\n"
        "xorb %al, %al\n" /* i */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177f5e:\n"
        "addl $1, %eax\n" /* i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf177192_00177f5e\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        "movl -0x2738(%ebp), %edi\n" /* line 860 */
        "cmpl 8(%ebx), %edi\n"
        "jl .Lf177192_001782e3\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        ".Lf177192_00177f7b:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2804 | to */
        "addl $0x1728, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* from */
        "addl $0x1728, %edx\n"
        "movl $0x1f, (%esp)\n"
        "movl %ebx, %eax\n" /* msg */
        "calll MSG_WriteDeltaHudElems\n"
        "movl $0x1f, (%esp)\n" /* line 2805 */
        "movl -0x2734(%ebp), %ecx\n"
        "movl -0x2730(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* msg */
        "calll MSG_WriteDeltaHudElems\n"
        "xorl %eax, %eax\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177fb7:\n"
        "addl $1, %eax\n" /* line 2533 | i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf177192_00177fb7\n"
        "xorb %al, %al\n" /* i */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177fc1:\n"
        "addl $1, %eax\n" /* i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf177192_00177fc1\n"
        "xorb %al, %al\n" /* i */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177fcb:\n"
        "addl $1, %eax\n" /* i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf177192_00177fcb\n"
        "xorb %al, %al\n" /* i */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177fd5:\n"
        "addl $1, %eax\n" /* i */
        "cmpl $0x1f, %eax\n" /* i */
        "jne .Lf177192_00177fd5\n"
        /* } scope */
        /* } scope */
        "addl $0x279c, %esp\n" /* line 2814 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: c, bit */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00177fe8:\n"
        "movl -0x2738(%ebp), %eax\n" /* line 860 */
        "cmpl 8(%ebx), %eax\n"
        "jl .Lf177192_00178375\n"
        "movl $1, (%ebx)\n" /* line 862 */
        ".Lf177192_00177ffd:\n"
        "movl 0x10(%ebp), %eax\n" /* line 875 | to */
        "movl %eax, -0x26f4(%ebp)\n"
        "movl $0, -0x26e0(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* from */
        "addl $0x5e4, %edx\n"
        "movl %edx, -0x274c(%ebp)\n"
        "movl %eax, %ecx\n"
        "addl $0x5e4, %ecx\n"
        "movl %ecx, -0x2750(%ebp)\n"
        "movl %eax, %edi\n"
        /* } scope */
        "movl 0x5e4(%edi), %esi\n" /* line 2780 | bits, value */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl -0x2738(%ebp), %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lf177192_001780d3\n"
        ".Lf177192_00178047:\n"
        "movl $1, (%ebx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        ".Lf177192_0017804d:\n"
        "movl $objectiveFields+4, %ecx\n" /* line 2784 */
        ".Lf177192_00178052:\n"
        "movl (%ecx), %edx\n" /* line 1907 */
        "movl -0x274c(%ebp), %esi\n" /* line 1909 | bit */
        "movl (%esi, %edx), %eax\n" /* bit */
        "movl -0x2750(%ebp), %edi\n"
        "cmpl (%edi, %edx), %eax\n"
        "jne .Lf177192_001781d5\n"
        "addl $0xc, %ecx\n" /* line 1910 */
        "cmpl $objectiveFields+76, %ecx\n" /* line 1904 */
        "jne .Lf177192_00178052\n"
        "movl -0x2738(%ebp), %eax\n" /* line 839 */
        "cmpl 8(%ebx), %eax\n"
        "jl .Lf177192_00178181\n"
        "movl $1, (%ebx)\n" /* line 841 */
        ".Lf177192_0017808c:\n"
        "addl $1, -0x26e0(%ebp)\n" /* line 2777 */
        "addl $0x1c, -0x2750(%ebp)\n"
        "addl $0x1c, -0x274c(%ebp)\n"
        "addl $0x1c, -0x26f4(%ebp)\n"
        "cmpl $0x10, -0x26e0(%ebp)\n"
        "je .Lf177192_00177875\n"
        "movl -0x26f4(%ebp), %edi\n" /* bits */
        "movl 0x5e4(%edi), %esi\n" /* line 2780 | bits, value */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl -0x2738(%ebp), %eax\n"
        "cmpl $3, %eax\n"
        "jle .Lf177192_00178047\n"
        ".Lf177192_001780d3:\n"
        "movl $3, %edi\n" /* line 812 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl %eax, %edx\n"
        "andl $7, %edx\n" /* line 820 */
        "movl %edx, -0x26f8(%ebp)\n" /* bit */
        "jne .Lf177192_0017810f\n"
        ".Lf177192_001780ee:\n"
        "movl 0xc(%ebx), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 824 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_0017810f:\n"
        "testl $1, %esi\n" /* line 827 */
        "je .Lf177192_00178146\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 828 | newsize */
        "movl 4(%ebx), %edx\n"
        "addl %edx, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movzbl -0x26f8(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        "orb %al, (%edx)\n"
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00178146:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 829 | newsize */
        "movl -0x275c(%ebp), %eax\n" /* newsize */
        "movl %eax, 0x14(%ebx)\n"
        "sarl $1, %esi\n" /* line 830 */
        "subl $1, %edi\n" /* line 816 */
        "je .Lf177192_00178173\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        "andl $7, %edx\n" /* line 820 */
        "movl %edx, -0x26f8(%ebp)\n" /* bit */
        "jne .Lf177192_0017810f\n"
        "jmp .Lf177192_001780ee\n"
        ".Lf177192_00178173:\n"
        "movl 0xc(%ebx), %edx\n"
        "movl %edx, -0x2738(%ebp)\n"
        "jmp .Lf177192_0017804d\n"
        /* } scope */
        /* } scope */
        ".Lf177192_00178181:\n"
        "movl 0x14(%ebx), %edx\n" /* line 846 */
        "movl %edx, -0x275c(%ebp)\n" /* newsize */
        "andb $7, %dl\n"
        "jne .Lf177192_001781c0\n"
        "movl -0x2738(%ebp), %ecx\n" /* line 848 */
        "shll $3, %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %esi\n"
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ebx), %edi\n" /* line 850 */
        "addl $1, %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        "movl %edi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_001781c0:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        "movl %edx, 0x14(%ebx)\n"
        "jmp .Lf177192_0017808c\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_001781d5:\n"
        "movl -0x2738(%ebp), %ecx\n" /* line 860 */
        "cmpl 8(%ebx), %ecx\n"
        "jl .Lf177192_0017821a\n"
        "movl $1, (%ebx)\n" /* line 862 */
        ".Lf177192_001781e6:\n"
        "movl $objectiveFields, %esi\n" /* line 875 | bit */
        /* } scope */
        ".Lf177192_001781eb:\n"
        "movl %esi, (%esp)\n" /* line 1923 | bit */
        "movl -0x2750(%ebp), %ecx\n"
        "movl -0x274c(%ebp), %edx\n"
        "movl %ebx, %eax\n"
        "calll MSG_WriteDeltaField\n"
        "addl $0xc, %esi\n" /* bit */
        "cmpl $objectiveFields+72, %esi\n" /* line 1918 | bit */
        "jne .Lf177192_001781eb\n"
        "movl 0xc(%ebx), %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        "jmp .Lf177192_0017808c\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_0017821a:\n"
        "movl 0x14(%ebx), %esi\n" /* line 866 | bit */
        "movl %esi, -0x275c(%ebp)\n" /* bit, newsize */
        "movl %esi, %edx\n" /* line 867 | bit */
        "andl $7, %edx\n"
        "jne .Lf177192_00178250\n"
        "movl -0x2738(%ebp), %edi\n" /* line 869 */
        "shll $3, %edi\n"
        "movl %edi, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %ecx\n"
        "movb $0, (%eax, %ecx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %esi\n" /* bit */
        "movl %esi, -0x275c(%ebp)\n" /* bit, newsize */
        ".Lf177192_00178250:\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %edi\n"
        "addl %edi, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "jmp .Lf177192_001781e6\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_0017827a:\n"
        "movl 0x14(%ebx), %edi\n" /* line 866 */
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "movl %edi, %edx\n" /* line 867 */
        "andl $7, %edx\n"
        "jne .Lf177192_001782b0\n"
        "movl -0x2738(%ebp), %eax\n" /* line 869 */
        "shll $3, %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %ecx\n"
        "movb $0, (%eax, %ecx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %esi\n" /* bit */
        "movl %esi, -0x275c(%ebp)\n" /* bit, newsize */
        ".Lf177192_001782b0:\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %edi\n"
        "addl %edi, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        "jmp .Lf177192_001775db\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_001782e3:\n"
        "movl 0x14(%ebx), %eax\n" /* line 866 */
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl %eax, %edx\n" /* line 867 */
        "andl $7, %edx\n"
        "je .Lf177192_001785eb\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %eax\n"
        "addl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "jmp .Lf177192_00177f7b\n"
        /* } scope */
        ".Lf177192_00178321:\n"
        "movl 0x14(%ebx), %esi\n" /* line 846 */
        "movl %esi, -0x275c(%ebp)\n" /* newsize */
        "andl $7, %esi\n"
        "je .Lf177192_001785a5\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %edi\n" /* newsize */
        "movl %edi, 0x14(%ebx)\n"
        "jmp .Lf177192_00177875\n"
        ".Lf177192_00178348:\n"
        "movl 0x14(%ebx), %esi\n" /* line 846 */
        "movl %esi, -0x275c(%ebp)\n" /* newsize */
        "andl $7, %esi\n"
        "je .Lf177192_0017856a\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %esi\n" /* newsize */
        "movl %esi, 0x14(%ebx)\n"
        /* } scope */
        ".Lf177192_0017836a:\n"
        "addl $0x279c, %esp\n" /* line 2814 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: c, bit */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_00178375:\n"
        "movl 0x14(%ebx), %edx\n" /* line 866 */
        "movl %edx, -0x275c(%ebp)\n" /* newsize */
        "andl $7, %edx\n" /* line 867 */
        "je .Lf177192_0017853f\n"
        ".Lf177192_00178387:\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %eax\n"
        "addl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        "jmp .Lf177192_00177ffd\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_001783ba:\n"
        "movl -0x2738(%ebp), %ecx\n" /* line 860 */
        "cmpl 8(%ebx), %ecx\n"
        "jge .Lf177192_001787fe\n"
        "movl 0x14(%ebx), %esi\n" /* line 866 | bit */
        "movl %esi, -0x275c(%ebp)\n" /* bit, newsize */
        "andl $7, %esi\n" /* line 867 | bit */
        "jne .Lf177192_001783fd\n"
        "movl -0x2738(%ebp), %edi\n" /* line 869 */
        "shll $3, %edi\n"
        "movl %edi, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %ecx\n"
        "movb $0, (%eax, %ecx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %edi\n"
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_001783fd:\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %eax\n"
        "addl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "movl 0xc(%ebx), %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        "jmp .Lf177192_00178804\n"
        /* } scope */
        ".Lf177192_00178430:\n"
        "movl 0x14(%ebx), %edi\n" /* line 846 */
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "andl $7, %edi\n"
        "jne .Lf177192_0017846f\n"
        "movl -0x2738(%ebp), %eax\n" /* line 848 */
        "shll $3, %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %edx\n"
        "movb $0, (%eax, %edx)\n"
        "movl 0xc(%ebx), %ecx\n" /* line 850 */
        "addl $1, %ecx\n"
        "movl %ecx, -0x2738(%ebp)\n"
        "movl %ecx, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %esi\n"
        "movl %esi, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_0017846f:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %edi\n" /* newsize */
        "movl %edi, 0x14(%ebx)\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl 8(%ebx), %eax\n" /* line 810 */
        "subl -0x2738(%ebp), %eax\n"
        "cmpl $3, %eax\n"
        "jle .Lf177192_00177c19\n"
        ".Lf177192_00178491:\n"
        "movl -0x26e4(%ebp), %esi\n" /* line 812 */
        "movl $5, %edi\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl %eax, %edx\n"
        "jmp .Lf177192_001784af\n"
        ".Lf177192_001784a9:\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        ".Lf177192_001784af:\n"
        "subl $1, %edi\n" /* line 818 */
        "andl $7, %edx\n" /* line 820 */
        "movl %edx, -0x2708(%ebp)\n" /* bit */
        "jne .Lf177192_001784de\n"
        "movl 0xc(%ebx), %edx\n" /* line 822 */
        "leal (, %edx, 8), %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 823 */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 824 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_001784de:\n"
        "testl $1, %esi\n" /* line 827 */
        "je .Lf177192_00178515\n"
        "sarl $3, -0x275c(%ebp)\n" /* line 828 | newsize */
        "movl 4(%ebx), %edx\n"
        "addl %edx, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movzbl -0x2708(%ebp), %ecx\n" /* bit */
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        "orb %al, (%edx)\n"
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00178515:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 829 | newsize */
        "movl -0x275c(%ebp), %eax\n" /* newsize */
        "movl %eax, 0x14(%ebx)\n"
        "sarl $1, %esi\n" /* line 830 */
        "testl %edi, %edi\n" /* line 816 */
        "jne .Lf177192_001784a9\n"
        "movl 0xc(%ebx), %edx\n"
        "movl %edx, -0x2738(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lf177192_00177c25\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_0017853f:\n"
        "movl -0x2738(%ebp), %ecx\n" /* line 869 */
        "shll $3, %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %esi\n" /* bit */
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %edi\n"
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "jmp .Lf177192_00178387\n"
        /* } scope */
        ".Lf177192_0017856a:\n"
        "movl -0x2738(%ebp), %edi\n" /* line 848 */
        "shll $3, %edi\n"
        "movl %edi, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %edx\n"
        "movb $0, (%eax, %edx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 850 */
        "movl 0x14(%ebx), %ecx\n"
        "movl %ecx, -0x275c(%ebp)\n" /* newsize */
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %esi\n" /* newsize */
        "movl %esi, 0x14(%ebx)\n"
        "jmp .Lf177192_0017836a\n"
        ".Lf177192_001785a5:\n"
        "movl -0x2738(%ebp), %edi\n" /* line 848 */
        "shll $3, %edi\n"
        "movl %edi, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %edx\n"
        "movb $0, (%eax, %edx)\n"
        "movl 0xc(%ebx), %ecx\n" /* line 850 */
        "addl $1, %ecx\n"
        "movl %ecx, -0x2738(%ebp)\n"
        "movl %ecx, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %esi\n"
        "movl %esi, -0x275c(%ebp)\n" /* newsize */
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %edi\n" /* newsize */
        "movl %edi, 0x14(%ebx)\n"
        "jmp .Lf177192_00177875\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_001785eb:\n"
        "movl -0x2738(%ebp), %ecx\n" /* line 869 */
        "shll $3, %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %esi\n" /* bit */
        "movb $0, (%eax, %esi)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %edi\n"
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "sarl $3, -0x275c(%ebp)\n" /* line 874 | newsize */
        "movl 4(%ebx), %eax\n"
        "addl %eax, -0x275c(%ebp)\n" /* newsize */
        "movl $1, %eax\n"
        "movl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x275c(%ebp), %esi\n" /* newsize, bit */
        "orb %al, (%esi)\n" /* bit */
        "addl $1, 0x14(%ebx)\n" /* line 875 */
        "jmp .Lf177192_00177f7b\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_0017863b:\n"
        "movl 4(%ebx), %eax\n" /* line 994 */
        "movb %dl, (%eax, %ecx)\n"
        "movl 0xc(%ebx), %esi\n" /* line 995 | bit */
        "addl $1, %esi\n" /* bit */
        "movl %esi, -0x2738(%ebp)\n" /* bit */
        "movl %esi, 0xc(%ebx)\n" /* bit */
        "jmp .Lf177192_00177531\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        ".Lf177192_00178655:\n"
        "movl 4(%ebx), %eax\n" /* line 1026 */
        "movl -0x2738(%ebp), %edi\n"
        "movw %cx, (%eax, %edi)\n"
        "movl %edx, -0x2738(%ebp)\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n"
        "jmp .Lf177192_0017750a\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        ".Lf177192_00178670:\n"
        "movl $1, (%ebx)\n" /* line 812 */
        "jmp .Lf177192_001774e0\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        ".Lf177192_0017867b:\n"
        "movl 4(%ebx), %eax\n" /* line 1026 */
        "movl -0x2738(%ebp), %esi\n" /* bit */
        "movw %cx, (%eax, %esi)\n"
        "movl %edx, -0x2738(%ebp)\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n"
        "jmp .Lf177192_00177417\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        ".Lf177192_00178696:\n"
        "movl 4(%ebx), %eax\n" /* line 1026 */
        "movl -0x2738(%ebp), %esi\n" /* bit */
        "movw %cx, (%eax, %esi)\n"
        "movl %edx, -0x2738(%ebp)\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n"
        "jmp .Lf177192_001773ed\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_001786b1:\n"
        "movl -0x2738(%ebp), %eax\n" /* line 869 */
        "shll $3, %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 870 */
        "movl -0x2738(%ebp), %ecx\n"
        "movb $0, (%eax, %ecx)\n"
        "addl $1, 0xc(%ebx)\n" /* line 871 */
        "movl 0x14(%ebx), %esi\n" /* bit */
        "movl %esi, -0x275c(%ebp)\n" /* bit, newsize */
        "jmp .Lf177192_00177c83\n"
        /* } scope */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        ".Lf177192_001786dc:\n"
        "movl 4(%ebx), %eax\n" /* line 1026 */
        "movl -0x2738(%ebp), %edi\n"
        "movw %cx, (%eax, %edi)\n"
        "movl %edx, -0x2738(%ebp)\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n"
        "jmp .Lf177192_001773c3\n"
        /* } scope */
        /* } scope */
        ".Lf177192_001786f7:\n"
        "movl -0x2738(%ebp), %edx\n" /* line 848 */
        "shll $3, %edx\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %ecx\n"
        "movb $0, (%eax, %ecx)\n"
        "movl 0xc(%ebx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, -0x2738(%ebp)\n"
        "movl %esi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %edi\n"
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %eax\n" /* newsize */
        "movl %eax, 0x14(%ebx)\n"
        "jmp .Lf177192_00177531\n"
        ".Lf177192_0017873d:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 2720 */
        "testl %ecx, %ecx\n"
        "jne .Lf177192_001775c6\n"
        "movl -0x2738(%ebp), %eax\n" /* line 839 */
        "cmpl 8(%ebx), %eax\n"
        "jge .Lf177192_00178866\n"
        "movl 0x14(%ebx), %edx\n" /* line 846 */
        "movl %edx, -0x275c(%ebp)\n" /* newsize */
        "andb $7, %dl\n"
        "jne .Lf177192_00178796\n"
        "movl -0x2738(%ebp), %ecx\n" /* line 848 */
        "shll $3, %ecx\n"
        "movl %ecx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %esi\n"
        "movb $0, (%eax, %esi)\n"
        "movl 0xc(%ebx), %edi\n" /* line 850 */
        "addl $1, %edi\n"
        "movl %edi, -0x2738(%ebp)\n"
        "movl %edi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_00178796:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %edx\n" /* newsize */
        "movl %edx, 0x14(%ebx)\n"
        "jmp .Lf177192_001776d8\n"
        ".Lf177192_001787ab:\n"
        "movl 0x14(%ebx), %eax\n" /* line 846 */
        "movl %eax, -0x275c(%ebp)\n" /* newsize */
        "testb $7, %al\n"
        "jne .Lf177192_001787e9\n"
        "movl -0x2738(%ebp), %edx\n" /* line 848 */
        "shll $3, %edx\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 849 */
        "movl -0x2738(%ebp), %ecx\n"
        "movb $0, (%eax, %ecx)\n"
        "movl 0xc(%ebx), %esi\n" /* line 850 */
        "addl $1, %esi\n"
        "movl %esi, -0x2738(%ebp)\n"
        "movl %esi, 0xc(%ebx)\n"
        "movl 0x14(%ebx), %edi\n"
        "movl %edi, -0x275c(%ebp)\n" /* newsize */
        ".Lf177192_001787e9:\n"
        "addl $1, -0x275c(%ebp)\n" /* line 852 | newsize */
        "movl -0x275c(%ebp), %eax\n" /* newsize */
        "movl %eax, 0x14(%ebx)\n"
        "jmp .Lf177192_001772ef\n"
        /* { scope 2: bit, bit, newsize, bit, ... */
        ".Lf177192_001787fe:\n"
        "movl $1, (%ebx)\n" /* line 862 */
        /* } scope */
        ".Lf177192_00178804:\n"
        "movss (%edx), %xmm0\n" /* line 1123 */
        "mulss %xmm2, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movzwl %ax, %ecx\n" /* c */
        /* { scope 2: bit, bit, newsize, bit, ... */
        /* { scope 3 */
        "movl -0x2738(%ebp), %edx\n" /* line 1023 */
        "addl $2, %edx\n"
        "cmpl 8(%ebx), %edx\n" /* line 1024 */
        "jg .Lf177192_001778f0\n"
        "movl 4(%ebx), %eax\n" /* line 1026 */
        "movl -0x2738(%ebp), %esi\n" /* bit */
        "movw %cx, (%eax, %esi)\n"
        "movl %edx, -0x2738(%ebp)\n" /* line 1027 */
        "movl %edx, 0xc(%ebx)\n"
        "jmp .Lf177192_001772ef\n"
        /* } scope */
        /* } scope */
        ".Lf177192_00178840:\n"
        "leal -0x26d0(%ebp), %esi\n" /* line 2567 | dummy, bits */
        "movl $0x26a8, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* bits */
        "calll memset\n"
        "movl %esi, 0xc(%ebp)\n" /* bits, from */
        "jmp .Lf177192_001771ac\n"
        ".Lf177192_00178866:\n"
        "movl $1, (%ebx)\n" /* line 841 */
        "jmp .Lf177192_001776d8\n"
    );
}
#else
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
#endif
