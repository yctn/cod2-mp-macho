/* ASM dump from: sv_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_main_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern void Scr_FreeValue(int value);
extern void SV_ResetSkeletonCache(void);
extern void G_RunFrame(int levelTime);

extern struct serverStatic_t svs; /* 0x0 */
extern struct server_t sv; /* 0x0 */
extern const dvar_t *sv_fps; /* 0x0 */
extern const dvar_t *sv_timeout; /* 0x0 */
extern const dvar_t *sv_zombietime; /* 0x0 */
extern const dvar_t *rcon_password; /* 0x0 */
extern const dvar_t *sv_privatePassword; /* 0x0 */
extern const dvar_t *sv_allowDownload; /* 0x0 */
extern const dvar_t *sv_maxclients; /* 0x0 */
extern const dvar_t *sv_privateClients; /* 0x0 */
extern const dvar_t *sv_hostname; /* 0x0 */
extern const dvar_t *sv_reconnectlimit; /* 0x0 */
extern const dvar_t *sv_padPackets; /* 0x0 */
extern const dvar_t *sv_mapname; /* 0x0 */
extern const dvar_t *sv_cheats; /* 0x0 */
extern const dvar_t *sv_serverid; /* 0x0 */
extern const dvar_t *sv_maxRate; /* 0x0 */
extern const dvar_t *sv_minPing; /* 0x0 */
extern const dvar_t *sv_maxPing; /* 0x0 */
extern const dvar_t *sv_gametype; /* 0x0 */
extern const dvar_t *sv_debugRate; /* 0x0 */
extern const dvar_t *sv_debugReliableCmds; /* 0x0 */
extern const dvar_t *sv_pure; /* 0x0 */
extern const dvar_t *sv_floodProtect; /* 0x0 */
extern const dvar_t *sv_allowAnonymous; /* 0x0 */
extern const dvar_t *sv_showCommands; /* 0x0 */
extern const dvar_t *sv_packet_info; /* 0x0 */
extern const dvar_t *sv_voice; /* 0x0 */
extern const dvar_t *sv_voiceQuality; /* 0x0 */
extern const dvar_t *sv_showAverageBPS; /* 0x0 */
extern const dvar_t *sv_kickBanTime; /* 0x0 */
extern const dvar_t *sv_iwds; /* 0x0 */
extern const dvar_t *sv_iwdNames; /* 0x0 */
extern const dvar_t *sv_referencedIwds; /* 0x0 */
extern const dvar_t *sv_referencedIwdNames; /* 0x0 */
extern const dvar_t *sv_allowedClan1; /* 0x0 */
extern const dvar_t *sv_allowedClan2; /* 0x0 */
extern const dvar_t *sv_mapRotation; /* 0x0 */
extern const dvar_t *sv_mapRotationCurrent; /* 0x0 */
extern const dvar_t *sv_disableClientConsole; /* 0x0 */
static char string_00edae00[1024]; /* string */

long int SV_AddServerCommand(client_t *client, svscmd_type type, const char *cmd);
long int SV_VoicePacket(netadr_t from, msg_t *msg);
long int SVC_Status(netadr_t from);
long int SVC_GameCompleteStatus(netadr_t from);
long int SVC_Info(netadr_t from);
long int SV_ConnectionlessPacket(netadr_t from, msg_t *msg);
long int SV_PacketEvent(netadr_t from, msg_t *msg);
long int SV_FreeClientScriptId(client_t *cl);
long int SV_RunFrame(void);
long int SV_BotUserMove(client_t *cl);
long int SV_SendServerCommand(client_t *cl, svscmd_type type, const char *fmt);
long int SV_Frame(int msec);

/* line 281 */

extern void Com_Printf(const char *fmt, ...);
extern void SV_DelayDropClient(client_t *cl, const char *reason);
extern void NET_OutOfBandPrint(int sock, ...);
extern char *va(const char *fmt, ...);
extern void MSG_WriteReliableCommandToBuffer(const char *cmd, char *buf, int bufSize);

/*
 * SV_AddServerCommand: adds a reliable command to the server command buffer.
 *
 * client_t field offsets:
 *   0x00000: state (int)
 *   0x20810: reliableAck (int)
 *   0x20814: reliableSequence (int)
 *   0x765f4: netchanState or similar (int) - if non-zero, return immediately
 *   0x6e5c4: netchan net address (3 ints at +0, +4, +8)
 *
 * Command entry layout (at (idx & 0x7f) * 0x408 + client_base):
 *   +0x40c: command string start (0x400 bytes for string)
 *   +0x80c: server time (int)
 *   +0x810: command type (int)
 *
 * svs+4: svs.time
 */
long int SV_AddServerCommand(client_t *client, svscmd_type type, const char *cmd)
{
    byte *cl = (byte *)client;
    int i;
    int reliableSequence;

    /* Check bIsTestClient */
    if (client->bIsTestClient != 0)
        return 0;

    reliableSequence = client->reliableSent;
    i = reliableSequence;

    /* Check if too many unacknowledged commands */
    if (i - client->reliableAcknowledge > 0x3f) {
        /* Compress: remove acknowledged commands by shifting buffer down */
        int toIndex;
        int from = client->reliableSent + 1;

        toIndex = from;
        while (from <= reliableSequence) {
            int fromSlot = from & 0x7f;
            int fromOff = fromSlot * 0x408;
            int entryType = client->reliableCommandInfo[fromSlot].type;

            if (entryType == 0) {
                /* Empty entry, skip */
                from++;
                continue;
            }

            {
                int toSlot = toIndex & 0x7f;

                if (toSlot != fromSlot) {
                    /* Copy the entry */
                    memcpy(&client->reliableCommandInfo[toSlot], &client->reliableCommandInfo[fromSlot], sizeof(svscmd_info_t));
                }
            }
            toIndex++;
            from++;
        }
        reliableSequence = toIndex - 1;
        client->reliableSent = reliableSequence;
    }

    /* If type != 0, try to deduplicate (find matching command) */
    if (type != 0) {
        int from;
        int foundIdx = -1;

        from = client->reliableSent + 1;
        while (from <= i) {
            int slot = from & 0x7f;
            int entryType = client->reliableCommandInfo[slot].type;

            if (entryType == 0) {
                from++;
                continue;
            }

            /* Check if first char matches */
            {
                char firstChar = cmd[0];
                if (client->reliableCommandInfo[slot].cmd[0] != firstChar) {
                    from++;
                    continue;
                }

                /* Check if command is dedup-eligible based on first character */
                /* Characters 'C'(0x43), 'D'(0x44), 'q'(0x71), 'r'(0x72), 'v'(0x76), 'w'(0x77), 'x'(0x78), 'y'(0x79) are eligible for dedup,
                 * BUT 'x'(0x78), 'y'(0x79), 'z'(0x7a) always skip (force no-dedup).
                 * For 'v'(0x76) and 'w'(0x77), also eligible for dedup. */
                /* Actually, looking at the jump table more carefully:
                 * 'x'-'z' (0x78-0x7a) = offset 0x35-0x37 from 'C' -> always skip dedup
                 * So these characters simply cause "continue" */
                if (firstChar == 'x' || firstChar == 'y' || firstChar == 'z') {
                    from++;
                    continue;
                }

                /* For eligible chars, compare the rest of the command.
                 * The jump table has two categories:
                 * Category 1 (direct match): 'C','D','q','r' -- go to string match check
                 * Category 2 (partial match): 'v','w' -- compare from 3rd character onwards
                 * All other characters: continue (no dedup) */
                {
                    int eligible = 0;
                    int partialMatch = 0;

                    switch (firstChar) {
                        case 'C': case 'D':
                        case 'q': case 'r':
                        case 'v': case 'w':
                            eligible = 1;
                            break;
                        default:
                            break;
                    }

                    if (!eligible) {
                        from++;
                        continue;
                    }

                    if (firstChar == 'v' || firstChar == 'w') {
                        partialMatch = 1;
                    }

                    if (partialMatch) {
                        /* Compare from offset 2: cmd[2..] vs entry[2..], skipping spaces */
                        const char *str1 = cmd + 2;
                        const char *str2 = client->reliableCommandInfo[slot].cmd + 2;
                        int matched = 1;

                        while (1) {
                            char c1 = *str1;
                            char c2 = *str2;

                            if (c1 == '\0') {
                                /* Check if str2 is also end or space */
                                if (c2 == '\0' || c2 == ' ')
                                    break; /* match */
                                matched = 0;
                                break;
                            }
                            if (c2 == '\0') {
                                if (c1 == ' ')
                                    break; /* match */
                                matched = 0;
                                break;
                            }
                            if (c1 == ' ') {
                                if (c2 == '\0' || c2 == ' ')
                                    break; /* match */
                                matched = 0;
                                break;
                            }
                            if (c2 == ' ') {
                                if (c1 == '\0' || c1 == ' ')
                                    break;
                                matched = 0;
                                break;
                            }
                            if (c1 != c2) {
                                matched = 0;
                                break;
                            }
                            str1++;
                            str2++;
                        }

                        if (!matched) {
                            from++;
                            continue;
                        }
                    } else {
                        /* Full match: compare cmd+1 vs entry+1 (using strcmp) */
                        char *entryStr = client->reliableCommandInfo[slot].cmd + 1;
                        if (strcmp(cmd + 1, entryStr) != 0) {
                            from++;
                            continue;
                        }
                    }
                }
            }

            /* Found a duplicate */
            foundIdx = from;

            /* Compact: shift commands from foundIdx+1..reliableSequence down */
            if (foundIdx >= 0) {
                int fromCmd = foundIdx + 1;
                int toCmd = foundIdx;

                if (fromCmd <= reliableSequence) {
                    while (fromCmd <= client->reliableSent) {
                        int fromSlot2 = fromCmd & 0x7f;
                        int toSlot2 = toCmd & 0x7f;

                        memcpy(&client->reliableCommandInfo[toSlot2], &client->reliableCommandInfo[fromSlot2], sizeof(svscmd_info_t));
                        fromCmd++;
                        toCmd++;
                    }
                }

                reliableSequence = client->reliableSent;
                i = reliableSequence;
            }
            break;
        }
    }

    /* Check if buffer overflow */
    if (i - client->reliableAcknowledge == 0x81) {
        /* Overflow: dump pending commands and disconnect */
        int dumpFrom;

        Com_Printf("===== pending server commands =====\n"); /* "===== pending server commands =====\n" */

        dumpFrom = client->reliableAcknowledge + 1;
        while (dumpFrom <= client->reliableSent) {
            int dumpSlot = dumpFrom & 0x7f;
            Com_Printf("cmd %5d: %8d: %s\n", dumpFrom, client->reliableCommandInfo[dumpSlot].time,
                        client->reliableCommandInfo[dumpSlot].cmd);
            dumpFrom++;
        }

        /* Send current command info */
        Com_Printf("cmd %5d: %8d: %s\n", i, *(int *)((byte *)&svs + 4), cmd);

        /* Send disconnect to client via OOB */
        {
            netadr_t addr = client->netchan.remoteAddress;
            NET_OutOfBandPrint(1, *(int *)&addr, ((int *)&addr)[1], ((int *)&addr)[2], "disconnect"); /* "disconnect" */
        }

        /* Delay-drop the client */
        SV_DelayDropClient(client, "EXE_SERVERCOMMANDOVERFLOW"); /* "EXE_SERVERCOMMANDOVERFLOW" */

        /* Replace command with overflow indicator */
        cmd = va("%c \"EXE_SERVERCOMMANDOVERFLOW\"", 0x77); /* "%c \"EXE_SERVERCOMMANDOVERFLOW\"" */
        type = 1;
        i = client->reliableSent;
    }

    /* Write the new command */
    {
        int newSeq = i + 1;
        client->reliableSent = newSeq;
        i = newSeq;
    }

    {
        int slot = i & 0x7f;

        MSG_WriteReliableCommandToBuffer(cmd, client->reliableCommandInfo[slot].cmd, 0x400);

        client->reliableCommandInfo[slot].time = *(int *)((byte *)&svs + 4);
        client->reliableCommandInfo[slot].type = type;
    }

    return 0;
}
