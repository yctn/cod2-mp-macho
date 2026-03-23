/* ASM dump from: scr_stringlist.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_stringlist.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

extern unsigned char scrStringGlob[]; /* scrStringGlob - BSS */

/*
 * scrStringGlob layout (as raw bytes):
 *   bytes 0..65535:  hash table, 16384 slots of 4 bytes each
 *     slot[i] at byte offset i*4:
 *       offset+0..1: link word (unsigned short): bits[15:14]=flags, bits[13:0]=next_index
 *       offset+2..3: stringValue (unsigned short)
 *   byte 65536: initialized flag
 *   bytes 65540..65543: restart pointer (void*)
 */

/* Raw slot accessors: i is a slot index (NOT a byte offset) */
#define SG_W0(i)     (*(unsigned short *)((char *)&scrStringGlob + (unsigned int)(i)*4))
#define SG_W1(i)     (*(unsigned short *)((char *)&scrStringGlob + (unsigned int)(i)*4 + 2))
#define SG_INIT_FLAG (*(unsigned char *)((char *)&scrStringGlob + 65536))
#define SG_RESTART   (*(void **)((char *)&scrStringGlob + 65540))

extern void MT_Init(void);
extern byte * MT_InitForceAlloc(void);
extern unsigned short MT_AllocIndex(int numBytes, int type);
extern void MT_FreeIndex(unsigned int nodeNum, int numBytes);
extern void MT_ForceAllocIndex(byte *allocBits, unsigned int nodeNum, int numBytes);
extern void MT_FinishForceAlloc(byte *allocBits);
extern void Scr_DumpScriptThreads(void);
extern void Scr_DumpScriptVariables(void);
extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);

unsigned int SL_ConvertFromString(const char *str);
unsigned int SL_Shutdown(void);
const char * SL_ConvertToString(unsigned int stringValue);
unsigned int SL_TransferRefToUser(unsigned int stringValue, unsigned int user);
unsigned int SL_AddRefToString(unsigned int stringValue);
unsigned int SL_RemoveRefToStringOfLen(unsigned int stringValue, unsigned int len);
int SL_GetStringLen(unsigned int stringValue);
unsigned int SL_FindStringOfLen(const char *str, unsigned int len);
unsigned int SL_FindLowercaseString(const char *str);
unsigned int SL_FindString(const char *str);
unsigned int SL_GetStringOfLen(const char *str, unsigned int user, unsigned int len, int type);
unsigned int SL_GetLowercaseString_(const char *str, unsigned int user, int type);
unsigned int SL_GetString_(const char *str, unsigned int user, int type);
unsigned int SL_RemoveRefToString(unsigned int stringValue);
unsigned int SL_ShutdownSystem(unsigned int user);
unsigned int Scr_SetString(scr_string_t *to, unsigned int from);
unsigned int SL_ConvertToLowercase(unsigned int stringValue, unsigned int user, int type);
unsigned int Scr_ShutdownGameStrings(void);
unsigned int SL_Init(void);
unsigned int Scr_AllocString(const char *s, int sys);
unsigned int SL_GetString(const char *str, unsigned int user);
unsigned int SL_GetStringForFloat(float f);
unsigned int SL_GetStringForInt(int i);
unsigned int SL_GetStringForVector(const float *v);
unsigned int Scr_CreateCanonicalFilename(const char *filename);

/* line 206 */
unsigned int SL_ConvertFromString(const char *str)
{
    return (int)((byte *)str - 4 - *(byte **)imp_scrMemTreePub) >> 3;
}

/* line 299 */
unsigned int SL_Shutdown(void)
{
    SG_INIT_FLAG = 0;
    return 0;
}

/* line 151 */
const char * SL_ConvertToString(unsigned int stringValue)
{
    if (!stringValue)
        return 0;
    byte *base = *(byte **)imp_scrMemTreePub;
    const char *result = (const char *)(base + stringValue * 8 + 4);
    if (!result[0] && stringValue > 1) {
        /* Print first few bytes at this location for debugging */
        byte *entry = base + stringValue * 8;
        Com_Printf("DBG SL_Convert EMPTY: strVal=%u base=%p entry=%p bytes=[%02x %02x %02x %02x %02x %02x %02x %02x]\n",
            stringValue, base, entry, entry[0], entry[1], entry[2], entry[3], entry[4], entry[5], entry[6], entry[7]);
    }
    return result;
}

/* line 759 */
static int dbg_transfer_count = 0;
static int dbg_transfer_decr = 0;
static int dbg_transfer_setbit = 0;
unsigned int SL_TransferRefToUser(unsigned int stringValue, unsigned int user)
{
    byte *entry = *(byte **)imp_scrMemTreePub + stringValue * 8;
    dbg_transfer_count++;
    if (entry[1] & user)
    {
        dbg_transfer_decr++;
        *(unsigned short *)(entry + 2) -= 1;
    }
    else
    {
        dbg_transfer_setbit++;
        entry[1] |= (byte)user;
    }
    return 0;
}
void DBG_PrintTransferStats(void)
{
    Com_Printf("DBG SL_TransferRefToUser stats: total=%d decr=%d setbit=%d\n",
        dbg_transfer_count, dbg_transfer_decr, dbg_transfer_setbit);
}

/* line 810 */
unsigned int SL_AddRefToString(unsigned int stringValue)
{
    byte *base = *(byte **)imp_scrMemTreePub;

    /* Fix #105: Guard against stale VM bytecode calling AddRef on freed nodes.
     * After SL_ShutdownSystem frees server strings, stale bytecode refs can
     * call SL_AddRefToString on freed memory. Writing to bytes 2-3 of a freed
     * node corrupts the treap 'next' pointer, leading to buddy-merge over
     * allocated data (the "eft" corruption). */
    {
        extern int MT_IsNodeCovered(int nodeNum);
        if (MT_IsNodeCovered(stringValue))
            return 0;
    }

    *(unsigned short *)(base + stringValue * 8 + 2) += 1;
    return 0;
}

/*
 * Compute hash slot for string of given length.
 * For len <= 0xff: djb2-style hash of the string bytes mod 16383, +1
 * For len > 0xff: (len>>2) mod 16383, +1
 * For len == 0: slot = 1
 */
static unsigned int compute_hash_slot(const char *str, unsigned int len)
{
    unsigned int x;
    if (len > 0xff)
    {
        x = len >> 2;
        return (x % 16383) + 1;
    }
    if (len == 0)
        return 1;
    /* hash = sum of (hash*31 + byte) for each byte */
    {
        unsigned int hash = 0;
        const char *p = str;
        const char *end = str + len;
        while (p != end)
        {
            hash = hash * 31 + (unsigned char)*p;
            p++;
        }
        return (hash % 16383) + 1;
    }
}

/*
 * Get the strlen of a string in the mem tree.
 * entry[0] stores (len-1) low byte. If entry[4 + (len-1)] != 0,
 * the string is longer; add 0x100 and check 0x100 bytes further.
 * Returns the full length (number of characters including null? or without?).
 * From the ASM: ecx = prev (starts at entry[0]-1), returns ecx (which = len-1 final).
 * But line 197 says "movl %ecx, %eax" and returns it.
 * Actually looking more carefully: the ASM returns ecx directly which is the full count
 * after the loop: prev starts at (entry[0]-1)&0xff, then is incremented by 0x100 each
 * time the zero-check fails. So it returns the index of the last byte of the string
 * (0-based), NOT length+1. This is the "length - 1" in the final block, so +1 = length.
 * BUT the callers of SL_GetStringLen use it as a length.
 * Looking at SL_RemoveRefToString which uses the same pattern then passes len+4 to MT_FreeIndex:
 * len = prev+1, so the allocated size = (len+4). That means len is the true string length
 * including null terminator (since MT_AllocIndex gets len+4 = strlen+1+4).
 */
static unsigned int get_entry_strlen(byte *entry)
{
    unsigned int prev = (unsigned int)((unsigned char)(entry[0] - 1));
    if (entry[4 + prev] != 0)
    {
        byte *p = entry + 4 + prev;
        do {
            prev += 0x100;
            p += 0x100;
        } while (*p != 0);
    }
    return prev + 1;
}

/* line 986 */
/*
 * Translated faithfully from ASM. The function:
 * 1. Decrements refcount at entry[2..3]
 * 2. If nonzero, returns
 * 3. If zero: computes hash slot for the string, frees the memory entry,
 *    finds and unlinks it from the hash chain, adds to freelist
 *
 * Hash slot (esi) is computed based on len:
 *   len > 0xff: esi = (len>>2) % 16383 + 1
 *   len == 0:   esi = 1
 *   else:       esi = hash(str[0..len-1]) % 16383 + 1
 *
 * After computing esi, the code at .Lf43568_000435c8:
 *   newEntry_offset = esi*4  (stored in -0x1c(%ebp))
 *   edi = &scrStringGlob[esi*4] = newEntry pointer
 *   MT_FreeIndex(stringValue, len+4)
 *   chain_next_idx = SG_W0(esi) & 0x3fff
 *   hash_base = &scrStringGlob[chain_next_idx*4]  (ecx = hash)
 *
 *   if newEntry[1] (word1) == stringValue: goto .Lf43568_000436da
 *   else: check hash[1] == stringValue? if yes goto .Lf43568_0004363d (which is "found in chain walk starting at hash")
 *   else: walk the chain (prev=ecx/esi, follow word0&0x3fff links until word1==stringValue)
 *         .Lf43568_0004363d: patch prev's word0 to skip cur
 *         edi = cur (the found node)
 *   .Lf43568_0004365d: (add edi to freelist)
 *     edi[0] = SG_W0(0) (freelist head)
 *     edi[1] = 0
 *     SG_W0(0) bucket's word1 = ecx (our slot index... wait)
 *     Actually: "movw %cx, scrStringGlob+2(, %eax, 4)" where eax = SG_W0(0) (old freelist head)
 *       and cx = what? At that point cx = esi (our newEntry slot index)
 *     "movw %cx, scrStringGlob" = SG_W0(0) = cx (esi = newEntry slot index)
 *     So the freelist: slot 0's word0 = newEntry_idx, and the old freelist head's word1 = newEntry_idx
 *
 *   .Lf43568_000436da: (newEntry holds stringValue)
 *     if hash_base == newEntry (edi): goto .Lf43568_0004370c (they're the same slot)
 *     else: this means stringValue is at the head slot (newEntry/edi) but chain_next != newEntry
 *       - copy chain_next's slot into newEntry's slot (set new flags, copy word1)
 *       - store newEntry ptr in SG_RESTART
 *       - edi = chain_next; goto .Lf43568_0004365d (free chain_next)
 *
 *   .Lf43568_0004370c: (stringValue at newEntry which == hash_base)
 *     ecx = esi; goto .Lf43568_0004365d
 *     This means: we free newEntry itself (edi=newEntry=hash)
 */
unsigned int SL_RemoveRefToStringOfLen(unsigned int stringValue, unsigned int len)
{
    byte *base = *(byte **)imp_scrMemTreePub;
    byte *entry = base + stringValue * 8;
    unsigned short ref;
    unsigned int esi; /* hash slot index */
    unsigned int newEntry_offset; /* esi*4 */
    unsigned short *edi; /* newEntry = &scrStringGlob[newEntry_offset] */
    unsigned int chain_next_idx;
    unsigned short *hash_ptr; /* hash = &scrStringGlob[chain_next_idx*4] */
    unsigned short *adr0; /* &scrStringGlob[0] */
    unsigned int ecx_slot; /* tracks the "prev" slot index for freelist linkage */

    /* Decrement refcount */
    ref = *(unsigned short *)(entry + 2) - 1;
    *(unsigned short *)(entry + 2) = ref;

    if (stringValue == 374) {
        Com_Printf("DBG SL_RemoveRefToStringOfLen(374): refcount=%u -> %u len=%u ret=%p str=\"%.16s\"\n",
            ref + 1, ref, len, __builtin_return_address(0), (const char *)(entry + 4));
    }

    if (ref != 0)
        return 0;

    /* Compute hash slot into esi */
    /* The string data pointer is entry+4 */
    esi = compute_hash_slot((const char *)(entry + 4), len);

    /* .Lf43568_000435c8: */
    newEntry_offset = esi * 4;
    edi = (unsigned short *)((char *)&scrStringGlob + newEntry_offset);

    MT_FreeIndex(stringValue, len + 4);

    /* Re-read chain_next from newEntry's word0 */
    chain_next_idx = (unsigned int)(SG_W0(esi) & 0x3fff);
    hash_ptr = (unsigned short *)((char *)&scrStringGlob + chain_next_idx * 4);

    /* Check if newEntry[1] == stringValue (the stringValue is at the hash head) */
    if (edi[1] == (unsigned short)stringValue)
    {
        /* .Lf43568_000436da: */
        if (hash_ptr == edi)
        {
            /* .Lf43568_0004370c: */
            ecx_slot = esi;
            goto add_to_freelist;
        }
        else
        {
            /* Move chain_next into newEntry's position, free chain_next */
            /* "movzwl scrStringGlob(%edx), %eax; andw $0x3fff, %ax; orw $0x8000, %ax" */
            /* edx = newEntry_offset */
            unsigned short new_w0 = (unsigned short)((chain_next_idx & 0x3fff) | 0x8000);
            SG_W0(esi) = new_w0;
            /* edi[1] = hash_ptr[1] */
            edi[1] = hash_ptr[1];
            /* SG_RESTART = edi (newEntry) */
            SG_RESTART = (void *)edi;
            /* edi = hash_ptr (chain_next); then fall to freelist add */
            edi = hash_ptr;
            ecx_slot = esi;
            goto add_to_freelist;
        }
    }
    else
    {
        unsigned int prev_idx;
        /* Check if hash_ptr[1] == stringValue */
        if (hash_ptr[1] == (unsigned short)stringValue)
        {
            /* .Lf43568_0004363d: arrived with esi=prev_idx, hash_ptr=cur */
            prev_idx = esi;
            goto patch_and_free;
        }
        /* Walk the chain */
        prev_idx = esi;
        { int _rml_iters = 0;
        while (1)
        {
            if (++_rml_iters > 16384) { /* cycle */
                edi = hash_ptr; ecx_slot = esi;
                goto add_to_freelist;
            }
            unsigned int old_prev = prev_idx;
            prev_idx = chain_next_idx;
            chain_next_idx = (unsigned int)(hash_ptr[0] & 0x3fff);
            hash_ptr = (unsigned short *)((char *)&scrStringGlob + chain_next_idx * 4);
            if (hash_ptr[1] == (unsigned short)stringValue)
                break;
        } }
        /* .Lf43568_0004363d: */
    patch_and_free:
        /* Patch prev's word0: keep upper flags, replace lower 14 bits with hash_ptr's lower 14 */
        {
            unsigned short pf = SG_W0(prev_idx) & 0xc000;
            unsigned short cn = hash_ptr[0] & 0x3fff;
            SG_W0(prev_idx) = pf | cn;
        }
        edi = hash_ptr;
        ecx_slot = esi; /* ecx at this point still holds esi (newEntry slot) */
        goto add_to_freelist;
    }

add_to_freelist:
    /* .Lf43568_0004365d: */
    /* edi[0] = SG_W0(0) (old freelist head word0) */
    /* edi[1] = 0 */
    /* SG_W0(0)'s entry's word1 = ecx_slot */
    /* SG_W0(0) = ecx_slot */
    {
        unsigned short old_head = SG_W0(0);
        edi[0] = old_head;
        edi[1] = 0;
        /* "movw %cx, scrStringGlob+2(, %eax, 4)": SG_W1(old_head) = ecx_slot */
        SG_W1((unsigned int)old_head) = (unsigned short)ecx_slot;
        /* "movw %cx, scrStringGlob": SG_W0(0) = ecx_slot */
        SG_W0(0) = (unsigned short)ecx_slot;
    }

    return 0;
}

/* line 190 */
int SL_GetStringLen(unsigned int stringValue)
{
    byte *base = *(byte **)imp_scrMemTreePub;
    byte *entry = base + stringValue * 8;
    unsigned int ecx;
    byte *edx_ptr;

    ecx = (unsigned int)((unsigned char)(entry[0] - 1));
    if (entry[4 + ecx] != 0)
    {
        edx_ptr = entry + 4 + ecx;
        do {
            ecx += 0x100;
            edx_ptr += 0x100;
        } while (*edx_ptr != 0);
    }
    return (int)ecx;
}

/*
 * SL_FindStringOfLen: looks up a string in the hash table.
 * Returns the stringValue if found (and moves it to front of chain), 0 if not found.
 *
 * Key observations from ASM:
 * - slot/hash = compute_hash_slot(str, len), stored in -0x20(%ebp) as "hash"
 * - entry = &scrStringGlob[hash*4], stored in -0x28(%ebp)
 * - The slot's word0 is checked: if (word0 & 0xc000) != 0x8000 -> return 0 (not occupied)
 * - stringValue = entry->word1, stored in -0x14(%ebp)
 * - byteLen = len & 0xff, stored in -0x18(%ebp)
 * - Compare entry's byte0 with byteLen, then compare string data with memcmp(str, entry+4, len)
 * - If match at head: do LRU reorder (chain manipulation) and return stringValue
 * - If not match: walk chain nodes (newEntry_idx = entry->word0 & 0x3fff)
 *   - For each node: check if node points back to entry (loop termination = not found)
 *   - If byteLen match and string match: do LRU reorder, return
 * - LRU reorder (lines 364-369 / 548-553):
 *   - prev's word0: keep flags, use cur->word0 & 0x3fff as new next
 *   - cur's word0: keep flags, use entry->word0 & 0x3fff as new next
 *   - entry's word0: keep flags, use newIndex (cur's slot index) as new next
 *   - swap: tmp=cur->word1; cur->word1=entry->word1; entry->word1=stringValue(cur's old sv)
 */
unsigned int SL_FindStringOfLen(const char *str, unsigned int len)
{
    unsigned int hash;        /* -0x20(%ebp) */
    unsigned short *entry;    /* -0x28(%ebp) = &scrStringGlob[hash*4] */
    unsigned int stringValue; /* -0x14(%ebp) */
    unsigned int byteLen;     /* -0x18(%ebp) */
    byte *base;               /* -0x10(%ebp) */
    unsigned int newEntry_offset; /* -0x1c(%ebp) */
    unsigned int newIndex;    /* -0x1c(%ebp) after first use */
    unsigned int prev_idx;    /* -0x24(%ebp) */

    /* Compute hash slot */
    hash = compute_hash_slot(str, len);

    /* entry = &scrStringGlob[hash*4] */
    entry = (unsigned short *)((char *)&scrStringGlob + hash * 4);

    /* Check flags of entry->word0 */
    {
        unsigned int flags = (unsigned int)(entry[0]) & 0xc000;
        if (flags != 0x8000)
        {
            stringValue = 0;
            return stringValue;
        }
    }

    /* Occupied: get stringValue and base */
    stringValue = (unsigned int)entry[1];
    base = *(byte **)imp_scrMemTreePub;
    byteLen = len & 0xff;

    /* Check head entry */
    {
        byte *refEntry = base + stringValue * 8;
        if ((unsigned char)refEntry[0] == (unsigned char)byteLen)
        {
            /* Compare string */
            if (memcmp(str, refEntry + 4, len) == 0)
            {
                /* Match at head - no reorder needed for head */
                /* ASM .Lf43752_00043936: jumps to memcmp check, then falls to .Lf43752_00043802 */
                return stringValue;
            }
        }
    }

    /* .Lf43752_0004385f: walk the chain */
    {
        unsigned int cur_link = (unsigned int)(entry[0]) & 0x3fff;
        unsigned int newEntry_idx = cur_link;
        unsigned short *newEntry_ptr = (unsigned short *)((char *)&scrStringGlob + newEntry_idx * 4);

        /* Check if chain immediately wraps back to entry (empty chain) */
        if (newEntry_ptr == entry)
        {
            return 0;
        }

        prev_idx = hash;

        { int _find_iters = 0;
        while (1)
        {
            unsigned int sv2;
            byte *e2;

            if (++_find_iters > 16384)
                return 0; /* cycle detected */

            sv2 = (unsigned int)newEntry_ptr[1];
            e2 = base + sv2 * 8;

            if ((unsigned char)e2[0] == (unsigned char)byteLen)
            {
                if (memcmp(str, e2 + 4, len) == 0)
                {
                    {
                        unsigned short pf = SG_W0(prev_idx) & 0xc000;
                        unsigned short nxt1 = newEntry_ptr[0] & 0x3fff;
                        SG_W0(prev_idx) = pf | nxt1;
                    }
                    {
                        unsigned short cf = newEntry_ptr[0] & 0xc000;
                        unsigned short nxt2 = entry[0] & 0x3fff;
                        newEntry_ptr[0] = cf | nxt2;
                    }
                    {
                        unsigned short ef = entry[0] & 0xc000;
                        entry[0] = ef | (unsigned short)(newEntry_idx & 0x3fff);
                    }
                    {
                        unsigned short tmp = newEntry_ptr[1];
                        newEntry_ptr[1] = entry[1];
                        entry[1] = (unsigned short)sv2;
                    }
                    stringValue = sv2;
                    return stringValue;
                }
            }

            prev_idx = newEntry_idx;
            newEntry_idx = (unsigned int)(newEntry_ptr[0]) & 0x3fff;
            newEntry_ptr = (unsigned short *)((char *)&scrStringGlob + newEntry_idx * 4);

            if (newEntry_ptr == entry)
                return 0;
        } }
    }
}

/* line 407 */
/*
 * SL_FindLowercaseString: converts str to lowercase into a 0x2000-byte stack buffer,
 * then calls SL_FindStringOfLen.
 * If strlen > 0x2000: return 0 (too long, ASM jg -> xorl %eax, %eax; ret)
 * Note: the ASM uses scasb which gives strlen+1 (incl. null), stored in ebx.
 * Then jg 0x2000 (with signed compare: if ebx > 0x2000 goto error).
 * jg >0 means: if (ebx > 0), convert lowercase.
 * Actually: slen = strlen(str)+1 (includes null).
 *   if slen > 0x2000: return 0
 *   if slen <= 0 (impossible since strlen>=0 so slen>=1): call with 0
 *   else: convert slen-1 chars (indices 0..slen-2, which is the string without null)
 * Wait, re-reading the ASM:
 *   repne scasb -> ecx = ~(strlen+1) = -(strlen+2), after "notl %ebx" we get strlen+1
 *   so ebx = strlen + 1 (includes null byte)
 *   jg 0x2000: if (ebx > 0x2000) goto error (return 0)
 *   jg >0: but ebx is always >= 1 for any string, so this test:
 *     "testl %ebx, %ebx; jg .Lf43968_000439b0" means if ebx > 0 goto convert
 *     (since jg is signed, and ebx >=1 always for a valid C string, this always branches)
 *   Convert loop: i from 0 to ebx-1, newStr[i] = tolower(str[i])
 *   then call SL_FindStringOfLen(newStr, ebx)
 * So the len passed is strlen+1 (includes null).
 */
unsigned int SL_FindLowercaseString(const char *str)
{
    char newStr[0x2000];
    int slen;
    int i;

    slen = (int)strlen(str) + 1;  /* includes null */

    if (slen > 0x2000)
        return 0;

    if (slen > 0)
    {
        for (i = 0; i < slen; i++)
        {
            newStr[i] = (char)tolower((unsigned char)str[i]);
        }
    }

    return SL_FindStringOfLen(newStr, (unsigned int)slen);
}

/* line 398 */
/*
 * SL_FindString: computes strlen+1 (scasb pattern: notl %ecx gives strlen+1)
 * then calls SL_FindStringOfLen(str, len).
 */
unsigned int SL_FindString(const char *str)
{
    unsigned int len = (unsigned int)strlen(str) + 1;
    return SL_FindStringOfLen(str, len);
}

/* line 491 */
/*
 * SL_GetStringOfLen: find or insert a string in the hash table.
 *
 * This is the most complex function. Translated from ASM carefully.
 *
 * Parameters: str, user, len, type
 *
 * The hash table slot structure:
 *   slot[i].word0: flags(2 bits) | next_index(14 bits)
 *     flags == 0x0000: slot is on freelist or unused
 *     flags == 0x4000: slot is part of a chain (not the head)
 *     flags == 0x8000: slot is the head of a hash bucket
 *   slot[i].word1: stringValue stored here
 *
 * Freelist: slot[0].word0 = head of freelist (index)
 *
 * Algorithm overview:
 * 1. Compute hash slot (esi in .Lf43a06_00043a91)
 * 2. entry = &slot[hash], byteLen = len&0xff
 * 3. Check entry->word0 flags:
 *    == 0x8000: occupied head -> search chain for match
 *    == 0x0000: empty (on freelist) -> allocate fresh
 *    == 0x4000: part of another chain -> need to split; insert as new head
 *
 * For 0x8000 path (search):
 *   - Get stringValue = entry->word1
 *   - Compare entry's string: if match -> update user/refcount, return
 *   - Walk chain: for each node, compare string; if match -> LRU reorder, update, return
 *   - If not found in chain: allocate new node from freelist, insert into chain
 *
 * For 0x0000 path (empty):
 *   - Get newIndex from freelist (SG_W0(0)), error if 0
 *   - Allocate string entry via MT_AllocIndex
 *   - Update freelist, link newIndex into entry's chain
 *   - entry gets hash marker, store stringValue, copy string data
 *
 * For 0x4000 path (mid-chain):
 *   - Walk to find who "owns" this hash slot in their chain (walk forward until looping back)
 *   - Get newIndex from freelist, error if 0
 *   - Allocate string entry
 *   - Copy entry's contents to newIndex, update links, entry becomes new head
 *
 * Let me translate each code path directly.
 */
unsigned int SL_GetStringOfLen(const char *str, unsigned int user, unsigned int len, int type)
{
    unsigned int hash;         /* -0x30(%ebp) */
    unsigned short *entry_ptr; /* -0x38(%ebp) */
    unsigned int byteLen;      /* -0x2c(%ebp) */
    unsigned int stringValue;  /* -0x40(%ebp) initially (word0&0xc000 area), then -0x44 for found sv */
    unsigned int esi_sv;       /* esi = stringValue after match */
    byte *base;                /* -0x28(%ebp) */

    /* Compute hash slot */
    hash = compute_hash_slot(str, len);

    /* .Lf43a06_00043a91: */
loop_top:
    {
        unsigned int ebx_hash = hash; /* ebx used as hash/refStr index */
        unsigned int ebx_offset = ebx_hash * 4; /* shll $2, %ebx */
        entry_ptr = (unsigned short *)((char *)&scrStringGlob + ebx_offset);
        byteLen = len & 0xff;

        {
            unsigned int sw0_val = (unsigned int)SG_W0(hash);
            unsigned int sw1_val = (unsigned int)SG_W1(hash);
            unsigned int flags0 = sw0_val & 0xc000;

            if (flags0 == 0x8000)
            {
                /* Occupied head: search chain */
                /* .Lf43a06_00043c21: */
                base = *(byte **)imp_scrMemTreePub;
                {
                    unsigned int sv_head = sw1_val; /* -0x44(%ebp) */
                    byte *refEntry = base + sv_head * 8;

                    /* Check head entry's byteLen */
                    if ((unsigned char)refEntry[0] == (unsigned char)byteLen)
                    {
                        /* Compare string */
                        if (memcmp(str, refEntry + 4, len) == 0)
                        {
                            /* Match at head */
                            /* Update user bit and refcount */
                            /* .Lf43a06_00043e11: compare match code */
                            if (!((unsigned char)refEntry[1] & (unsigned char)user))
                            {
                                refEntry[1] |= (unsigned char)user;
                                *(unsigned short *)(refEntry + 2) += 1;
                                /* get entry's word1 as sv */
                                sv_head = (unsigned int)entry_ptr[1];
                            }
                            esi_sv = sv_head;
                            if (esi_sv == 374) {
                                Com_Printf("DBG SL_GetStringOfLen FOUND-HEAD sv=374: refcount=%u user=%u ret=%p\n",
                                    (unsigned int)*(unsigned short *)(refEntry + 2), user, __builtin_return_address(0));
                            }
                            return esi_sv;
                        }
                    }
                }

                /* Not at head: walk chain (.Lf43a06_00043c43) */
                {
                    unsigned int cur_sv = sw0_val & 0x3fff; /* -0x24(%ebp): first cur index */
                    unsigned int cur_idx = cur_sv;
                    unsigned short *cur_ptr = (unsigned short *)((char *)&scrStringGlob + cur_idx * 4);

                    /* Check if chain loops back to entry immediately */
                    if (cur_ptr == entry_ptr)
                    {
                        /* Not found -> allocate */
                        goto alloc_mid_chain_occupied;
                    }

                    {
                        unsigned int prev_sv = hash; /* -0x20(%ebp) */
                        int _chain_iters = 0;

                        while (1)
                        {
                            unsigned int node_sv;
                            byte *node_entry;

                            if (++_chain_iters > 16384) {
                                /* Chain cycle detected — treat as not found */
                                goto alloc_mid_chain_occupied;
                            }

                            /* -0x3c(%ebp) = cur_ptr[1] = sv2 */
                            node_sv = (unsigned int)cur_ptr[1];
                            node_entry = base + node_sv * 8;

                            /* Check byteLen */
                            if ((unsigned char)node_entry[0] == (unsigned char)byteLen)
                            {
                                byte *cmp_ptr = node_entry + 4;
                                if (memcmp(str, cmp_ptr, len) == 0)
                                {
                                    /* Found in chain (.Lf43a06_00043cc7 match): LRU reorder */
                                    {
                                        unsigned short pf = SG_W0(prev_sv) & 0xc000;
                                        unsigned short cn = cur_ptr[0] & 0x3fff;
                                        SG_W0(prev_sv) = pf | cn;
                                    }
                                    {
                                        unsigned short cf = cur_ptr[0] & 0xc000;
                                        unsigned short en = entry_ptr[0] & 0x3fff;
                                        cur_ptr[0] = cf | en;
                                    }
                                    {
                                        unsigned short ef = entry_ptr[0] & 0xc000;
                                        entry_ptr[0] = ef | (unsigned short)(cur_idx & 0x3fff);
                                    }
                                    {
                                        unsigned short tmp = cur_ptr[1];
                                        cur_ptr[1] = entry_ptr[1];
                                        entry_ptr[1] = (unsigned short)node_sv;
                                        /* DBG: check for sv=23 swap */
                                        if (cur_ptr[1] == 23 || entry_ptr[1] == 23) {
                                            unsigned int ci = (unsigned int)((char *)cur_ptr - (char *)&scrStringGlob) / 4;
                                            unsigned int ei = (unsigned int)((char *)entry_ptr - (char *)&scrStringGlob) / 4;
                                            Com_Printf("DBG swap created sv=23: cur[%u]=%u entry[%u]=%u str=\"%.16s\"\n",
                                                ci, (unsigned int)cur_ptr[1], ei, (unsigned int)entry_ptr[1], str);
                                        }
                                    }

                                    if (!((unsigned char)node_entry[1] & (unsigned char)user))
                                    {
                                        node_entry[1] |= (unsigned char)user;
                                        *(unsigned short *)(node_entry + 2) += 1;
                                    }
                                    esi_sv = node_sv;
                                    return esi_sv;
                                }
                            }

                            /* Advance */
                            prev_sv = cur_idx;
                            cur_idx = (unsigned int)(cur_ptr[0]) & 0x3fff;
                            cur_sv = cur_idx;
                            cur_ptr = (unsigned short *)((char *)&scrStringGlob + cur_idx * 4);

                            /* Check if looped back to entry */
                            if (cur_ptr == entry_ptr)
                                goto alloc_mid_chain_occupied;
                        }
                    }

                alloc_mid_chain_occupied:;
                    /* Not found in occupied bucket. Allocate new entry.
                     * Use freelist. If freelist empty: error.
                     * Path: .Lf43a06_00043d45 -> .Lf43a06_00043d54
                     */
                    {
                        unsigned int newIndex = (unsigned int)SG_W0(0);
                        unsigned short *newNode;

                        if (newIndex == 0)
                        {
                            /* .Lf43a06_00043dcb: */
                            Scr_DumpScriptThreads();
                            Scr_DumpScriptVariables();
                            Com_Error(1, "\x15" "exceeded maximum number of script strings\n");
                            newIndex = (unsigned int)SG_W0(0);
                        }

                        /* .Lf43a06_00043d54: */
                        esi_sv = (unsigned int)MT_AllocIndex((int)(len + 4), type);
                        if (esi_sv >= 370 && esi_sv <= 376)
                            Com_Printf("DBG SL alloc-path1 sv=%u str=\"%.16s\" len=%u numBytes=%u\n", esi_sv, str, len, len+4);

                        newNode = (unsigned short *)((char *)&scrStringGlob + newIndex * 4);

                        /* Update freelist: newNode->word0 & 0x3fff = new freelist head */
                        /* "movzwl scrStringGlob(%ecx), %eax; andl $0x3fff, %eax; movw %ax, scrStringGlob" */
                        /* ecx = newIndex*4 */
                        {
                            unsigned short freenext = SG_W0(newIndex) & 0x3fff;
                            SG_W0(0) = freenext;
                        }
                        /* "movl $scrStringGlob, %edx; movw $0, 2(%edx, %eax, 4)" */
                        /* The new freelist head's word1 = 0 */
                        {
                            unsigned short fh = SG_W0(0);
                            SG_W1((unsigned int)fh) = 0;
                        }

                        /* Link newNode: entry->word0 & 0x3fff was the chain head link */
                        /* "movl -0x38(%ebp), %edx; movzwl (%edx), %eax; andw $0x3fff, %ax; orb $0x40, %ah" */
                        /* newNode->word0 = (entry->word0 & 0x3fff) | 0x4000 */
                        {
                            unsigned short chain_next2 = entry_ptr[0] & 0x3fff;
                            newNode[0] = chain_next2 | 0x4000;
                        }
                        /* "movzwl (%edx), %eax; andw $0xc000, %ax; movl %ebx, %edx; andw $0x3fff, %dx; orl %edx, %eax; movl -0x38(%ebp), %edx; movw %ax, (%edx)" */
                        /* entry->word0 = (entry->word0 & 0xc000) | (newIndex & 0x3fff) */
                        {
                            unsigned short ef2 = entry_ptr[0] & 0xc000;
                            entry_ptr[0] = ef2 | (unsigned short)(newIndex & 0x3fff);
                        }
                        /* "movzwl 2(%edx), %eax; movw %ax, scrStringGlob+2(%ecx)" */
                        /* newNode->word1 = entry->word1 */
                        newNode[1] = entry_ptr[1];

                        /* entry_ptr is now -0x38 = the entry we're modifying (ecx=entry) */
                        /* Fall to .Lf43a06_00043b6f and .Lf43a06_00043b79 */
                        goto store_and_return;
                    }
                }
            }
            else if (flags0 == 0)
            {
                /* Empty slot (freelist). Allocate. */
                /* .Lf43a06_00043bcf: */
                base = *(byte **)imp_scrMemTreePub;

                {
                    unsigned int newIndex2 = (unsigned int)SG_W0(0);

                    if (newIndex2 == 0)
                    {
                        Scr_DumpScriptThreads();
                        Scr_DumpScriptVariables();
                        Com_Error(1, "\x15" "exceeded maximum number of script strings\n");
                        newIndex2 = (unsigned int)SG_W0(0);
                    }

                    esi_sv = (unsigned int)MT_AllocIndex((int)(len + 4), type);
                    if (esi_sv >= 370 && esi_sv <= 376)
                        Com_Printf("DBG SL alloc-path2 sv=%u str=\"%.16s\" len=%u numBytes=%u\n", esi_sv, str, len, len+4);

                    /* "movl -0x38(%ebp), %eax; movzwl 2(%eax), %ecx" - ecx = entry->word1 (old sv on freelist = garbage/0) */
                    /* "movzwl scrStringGlob(%ebx), %edx; andl $0x3fff, %edx" - edx = SG_W0(hash) & 0x3fff = newIndex2->next in freelist */
                    /* "movzwl scrStringGlob(, %ecx, 4), %eax; andw $0xc000, %ax; orl %edx, %eax; movw %ax, scrStringGlob(, %ecx, 4)" */
                    /* This patches ecx's slot: ecx = entry->word1, ecx's word0: keep flags, link = edx */
                    /* Remove hash slot from doubly-linked freelist:
                     * ASM loads ecx=entry[1] and edx=SG_W0(hash)&0x3fff ONCE, uses both.
                     * ecx = hash.prev (backward link), edx = hash.next (forward link) */
                    {
                        unsigned int ecx2 = (unsigned int)entry_ptr[1]; /* hash's backward link */
                        unsigned short edx2 = entry_ptr[0] & 0x3fff; /* hash's forward link */
                        unsigned short af2 = SG_W0(ecx2) & 0xc000;
                        SG_W0(ecx2) = af2 | edx2; /* prev.next = hash.next */
                        SG_W1((unsigned int)edx2) = (unsigned short)ecx2; /* next.prev = hash.prev */
                    }
                    /* "movl -0x38(%ebp), %ecx" - ecx = entry_ptr */
                    /* Fall to .Lf43a06_00043b6f */

                    /* .Lf43a06_00043b6f: */
                    /* "movl -0x30(%ebp), %eax; orw $0x8000, %ax; movw %ax, (%ecx)" */
                    /* entry->word0 = hash | 0x8000 */
                    entry_ptr[0] = (unsigned short)(hash | 0x8000);

                    goto store_and_return;
                }
            }
            else
            {
                /* flags0 == 0x4000: slot is part of another chain */
                /* Need to find the true head of this chain and insert our string as new head */
                /* .Lf43a06_00043ad8/.Lf43a06_00043ada: find who has hash as their next */
                /* Walk: starting from -0x34(%ebp) = next = entry->word0 & 0x3fff */
                /* then loop: ebx = SG_W0(ebx) & 0x3fff while SG_W0(ebx)&0x3fff != hash */
                /* i.e., find ebx such that SG_W0(ebx) & 0x3fff == hash */
                unsigned int next_idx = sw0_val & 0x3fff; /* -0x34(%ebp) */
                unsigned int cur_search = next_idx;

                /* Find the node whose next points to hash */
                { int _mid_iters = 0;
                while ((SG_W0(cur_search) & 0x3fff) != hash)
                {
                    cur_search = (unsigned int)(SG_W0(cur_search) & 0x3fff);
                    if (++_mid_iters > 16384) break; /* cycle safety */
                } }
                /* cur_search is now the node that points to hash */

                base = *(byte **)imp_scrMemTreePub;

                /* Get freelist head */
                {
                    unsigned int newIndex3 = (unsigned int)SG_W0(0);
                    unsigned short *newNode3;

                    if (newIndex3 == 0)
                    {
                        /* .Lf43a06_00043dee: */
                        Scr_DumpScriptThreads();
                        Scr_DumpScriptVariables();
                        Com_Error(1, "\x15" "exceeded maximum number of script strings\n");
                        newIndex3 = (unsigned int)SG_W0(0);
                    }

                    /* .Lf43a06_00043aff: */
                    esi_sv = (unsigned int)MT_AllocIndex((int)(len + 4), type);
                    if (esi_sv >= 370 && esi_sv <= 376)
                        Com_Printf("DBG SL alloc-path3 sv=%u str=\"%.16s\" len=%u numBytes=%u\n", esi_sv, str, len, len+4);

                    newNode3 = (unsigned short *)((char *)&scrStringGlob + newIndex3 * 4);

                    /* Update freelist: remove newIndex3 */
                    {
                        unsigned short freenext3 = SG_W0(newIndex3) & 0x3fff;
                        SG_W0(0) = freenext3;
                        SG_W1((unsigned int)freenext3) = 0;
                    }

                    /* "movzwl scrStringGlob(, %ebx, 4), %eax; andl $0x3fff, %eax; movw %ax, scrStringGlob" */
                    /* SG_W0(cur_search) & 0x3fff... but wait we need to patch cur_search to point to newNode3 */
                    /* Actually: re-reading ASM:
                     *   leal (, %edi, 4), %ecx  where edi = newIndex (freelist node)
                     *   movzwl scrStringGlob(%ecx), %eax; andl $0x3fff, %eax -> freenext of newNode3
                     *   movw %ax, scrStringGlob  -> SG_W0(0) = freenext3 (already done above)
                     *   movl $scrStringGlob, %edx; movw $0, 2(%edx, %eax, 4) -> SG_W1(freenext3) = 0 (done)
                     *
                     *   movzwl scrStringGlob(, %ebx, 4), %eax where ebx = cur_search
                     *   andw $0xc000, %ax -> flags of cur_search
                     *   orl %edi, %eax  -> cur_search's flags | newIndex3
                     *   movw %ax, scrStringGlob(, %ebx, 4) -> SG_W0(cur_search) = flags | newIndex3
                     */
                    {
                        unsigned short csf = SG_W0(cur_search) & 0xc000;
                        SG_W0(cur_search) = csf | (unsigned short)(newIndex3 & 0x3fff);
                    }

                    /* "movl -0x34(%ebp), %eax; orb $0x40, %ah; movw %ax, scrStringGlob(%ecx)" */
                    /* newNode3->word0 = next_idx | 0x4000 */
                    newNode3[0] = (unsigned short)(next_idx | 0x4000);

                    /* "movl -0x38(%ebp), %edx; movzwl 2(%edx), %eax; movw %ax, scrStringGlob+2(%ecx)" */
                    /* newNode3->word1 = entry->word1 */
                    newNode3[1] = entry_ptr[1];

                    /* ecx = entry_ptr (for .Lf43a06_00043b6f) */
                    /* .Lf43a06_00043b6f: */
                    /* entry->word0 = hash | 0x8000 */
                    entry_ptr[0] = (unsigned short)(hash | 0x8000);

                    goto store_and_return;
                }
            }
        }
    }

store_and_return:
    /* .Lf43a06_00043b79: */
    /* Store stringValue in entry->word1, copy string data */
    entry_ptr[1] = (unsigned short)esi_sv;

    {
        byte *newMem = *(byte **)imp_scrMemTreePub + esi_sv * 8;
        memcpy(newMem + 4, str, len);
        newMem[1] = (byte)user;
        *(unsigned short *)(newMem + 2) = 1;
        newMem[0] = (byte)byteLen;
    }

    if (esi_sv == 374) {
        extern unsigned char scrMemTreeGlob_arr2[];
        unsigned short tree1_head = *(unsigned short *)(scrMemTreeGlob_arr2 + 525056 + 2*1);
        unsigned short tree2_head = *(unsigned short *)(scrMemTreeGlob_arr2 + 525056 + 2*2);
        /* Check tree[1] for node 374 and tree[2] for node 372 */
        unsigned int w0_374 = *(unsigned int *)(scrMemTreeGlob_arr2 + 374*8);
        unsigned int w1_374 = *(unsigned int *)(scrMemTreeGlob_arr2 + 374*8 + 4);
        unsigned int w0_372 = *(unsigned int *)(scrMemTreeGlob_arr2 + 372*8);
        unsigned int w1_372 = *(unsigned int *)(scrMemTreeGlob_arr2 + 372*8 + 4);
        Com_Printf("DBG SL_GetStringOfLen ALLOC sv=374: str=\"%.16s\" user=%u len=%u ret=%p "
                   "tree1_hd=%u tree2_hd=%u mt374=[%08x %08x] mt372=[%08x %08x]\n",
            str, user, len, __builtin_return_address(0),
            tree1_head, tree2_head, w0_374, w1_374, w0_372, w1_372);
        /* Full tree check: for each level, search BST for 374's aligned ancestor */
        {
            extern int MT_SearchTreeAny(int nodeNum);
            extern int MT_SearchTreeLevel(int nodeNum, int level);
            int level;
            if (MT_SearchTreeAny(374))
                Com_Printf("TREE BUG: sv=374 still in tree after alloc!\n");
            /* At each level, the block that would contain 374 is at 374 & ~((1<<level)-1) */
            for (level = 1; level <= 16; level++) {
                unsigned int ancestor = 374u & ~((1u << level) - 1u);
                unsigned short tree_head = *(unsigned short *)(scrMemTreeGlob_arr2 + 525056 + 2*level);
                if (MT_SearchTreeLevel(ancestor, level)) {
                    Com_Printf("TREE OVERLAP: level=%d node=%u covers 374! tree_head=%u\n",
                        level, ancestor, tree_head);
                }
            }
            /* Also dump tree heads for levels 7-16 */
            {
                int l;
                for (l = 7; l <= 12; l++) {
                    unsigned short h = *(unsigned short *)(scrMemTreeGlob_arr2 + 525056 + 2*l);
                    if (h) Com_Printf("  tree[%d] head=%u\n", l, h);
                }
            }
        }
    }

    /* DBG: detect when any hash entry points to sv=23 */
    {
        static int sv23_checked = 0;
        if (!sv23_checked) {
            unsigned int slot;
            for (slot = 1; slot < 16384; slot++) {
                if (SG_W1(slot) == 23 && (SG_W0(slot) & 0xc000) != 0) {
                    unsigned int entry_idx = (unsigned int)((char *)entry_ptr - (char *)&scrStringGlob) / 4;
                    Com_Printf("DBG sv=23 appeared in slot %u (w0=0x%04x) after alloc sv=%u str=\"%.16s\" hash=%u entry_idx=%u\n",
                        slot, (unsigned int)SG_W0(slot), esi_sv, str, hash, entry_idx);
                    sv23_checked = 1;
                    break;
                }
            }
        }
    }

    /* DBG: track allocations near node 23 */
    if (esi_sv >= 20 && esi_sv <= 24) {
        Com_Printf("DBG ALLOC sv=%u: len=%u byteLen=%u user=%u numBytes=%u str=\"%.16s\"\n",
            esi_sv, len, byteLen, user, (unsigned int)(len + 4), (const char *)str);
    }
    /* DBG: check if node 23 data changes unexpectedly */
    {
        static unsigned char last_node23_byte0 = 0;
        static int alloc_count = 0;
        byte *m23 = *(byte **)imp_scrMemTreePub + 23 * 8;
        alloc_count++;
        if (m23[0] != last_node23_byte0) {
            Com_Printf("DBG node23 byte0 changed: %u -> %u at alloc #%d (sv=%u str=\"%.16s\")\n",
                (unsigned int)last_node23_byte0, (unsigned int)m23[0], alloc_count, esi_sv, str);
            last_node23_byte0 = m23[0];
        }
    }

    return esi_sv;
}

/* line 719 */
/*
 * SL_GetLowercaseString_: same as SL_GetLowercaseString but calls SL_GetStringOfLen.
 * ebx = strlen+1 (scasb pattern)
 * if ebx > 0x2000: Com_Error
 * if ebx > 0 (always true): convert loop; call SL_GetStringOfLen(newStr, user, ebx, type)
 * else: call SL_GetStringOfLen(newStr, user, 0, type)
 */
unsigned int SL_GetLowercaseString_(const char *str, unsigned int user, int type)
{
    char newStr[0x2000];
    int slen;
    unsigned int i;

    slen = (int)strlen(str) + 1;

    if ((unsigned int)slen > 0x2000)
    {
        Com_Error(1, "max string length exceeded: \"%s\"", str);
        return 0;
    }

    if (slen > 0)
    {
        i = 0;
        while ((unsigned int)i < (unsigned int)slen)
        {
            newStr[i] = (char)tolower((unsigned char)str[i]);
            i++;
        }
    }

    return SL_GetStringOfLen(newStr, user, (unsigned int)slen, type);
}

/* line 685 */
/*
 * SL_GetString_: strlen+1 via scasb, then SL_GetStringOfLen(str, user, len, type).
 */
unsigned int SL_GetString_(const char *str, unsigned int user, int type)
{
    unsigned int len = (unsigned int)strlen(str) + 1;
    return SL_GetStringOfLen(str, user, len, type);
}

/* line 935 */
/*
 * SL_RemoveRefToString: same logic as SL_RemoveRefToStringOfLen but computes len
 * from the string entry's stored length.
 *
 * First: compute strlen from entry[0] (same as get_entry_strlen).
 * Then: decrement refcount, if nonzero return.
 * Then: free string from hash table.
 *
 * Notable difference: the ASM for SL_RemoveRefToString computes:
 *   ecx = (entry[0]-1) & 0xff
 *   if entry[4+ecx] != 0: loop adding 0x100 until zero
 *   len = ecx + 1  (stored in -0x1c(%ebp))
 *
 * Then after checking refcount reaches 0:
 *   str_ptr = entry + 4  (leal 4(%ebx), %eax -- but wait, %ebx = entry ptr at this point)
 * Wait, re-reading the ASM at .Lf43f48_00043f71:
 *   "addl $1, %ecx"  -> len = ecx + 1
 *   "movl %ecx, -0x1c(%ebp)"
 *   Then refcount decrement.
 *   "jne .Lf43f48_0004407a" (return if nonzero)
 *   "leal 4(%ebx), %eax" where %ebx is the entry pointer -> str_ptr = entry+4
 *   Then hash computation using -0x1c(%ebp) = len.
 *
 * For the freelist add (.Lf43f48_0004405b):
 *   "movzwl scrStringGlob, %eax" -> eax = SG_W0(0) (old freelist head)
 *   "movw %ax, (%edi)" -> edi[0] = old_head
 *   "movw $0, 2(%edi)" -> edi[1] = 0
 *   "movw %bx, scrStringGlob+2(, %eax, 4)" -> SG_W1(old_head) = bx
 *   "movw %bx, scrStringGlob" -> SG_W0(0) = bx
 * Where bx = ebx at that point.
 * At .Lf43f48_0004405b: what is bx?
 *   At .Lf43f48_00043fc1 (loop top): ebx = hash (slot index from compute_hash_slot)
 *   After MT_FreeIndex: esi = SG_W0(hash_offset) & 0x3fff = chain_next_idx
 *   If newEntry[1] == stringValue AND esi==newEntry: ecx=hash -> bx=hash_slot
 *   If newEntry[1] == stringValue AND esi!=newEntry: (move chain_next to head) -> edi=chain_next; bx=esi(hash_slot)? No...
 *     at .Lf43f48_000440f8: "movl %esi, %ebx; movl %ecx, %edi; jmp .Lf43f48_0004405b"
 *     where esi = chain_next_idx (from esi after "andl $0x3fff, %esi")
 *     so bx = chain_next_idx??? That doesn't seem right.
 *
 * Wait let me re-read more carefully:
 * At .Lf43f48_00043fc1:
 *   "leal (, %ebx, 4), %edx" -> edx = ebx*4 (stored in -0x20(%ebp))
 *   "movl %edx, -0x20(%ebp)"
 *   "movl %edx, %edi" -> edi = edx = ebx*4
 *   "addl $scrStringGlob, %edi" -> edi = &scrStringGlob[ebx*4] = newEntry ptr
 * So edi = newEntry POINTER, and "movl %edx, -0x20(%ebp)" stores the OFFSET (ebx*4).
 * ebx = hash slot index (esi from compute_hash_slot)
 *
 * "movzwl scrStringGlob(%edx), %esi; andl $0x3fff, %esi" -> esi = SG_W0_by_offset(ebx*4) & 0x3fff = chain_next_idx
 * "leal (, %esi, 4), %edx; leal scrStringGlob(%edx), %ecx" -> ecx = &scrStringGlob[esi*4] = hash_ptr (chain_next pointer)
 *
 * "movzwl 2(%edi), %eax; cmpl %eax, 8(%ebp)" -> if edi[1] == stringValue
 *   je .Lf43f48_000440f8
 * "movzwl 2(%ecx), %eax; cmpl %eax, 8(%ebp)" -> if ecx[1] == stringValue
 *   jne .Lf43f48_00044022 (not equal -> skip to .Lf43f48_00044022)
 *   "jmp .Lf43f48_00044130"
 * .Lf43f48_00044020:
 *   "movl %ebx, %esi" -> esi = ebx = hash slot index? Wait, at loop entry ebx=hash slot.
 *   But at .Lf43f48_00044020: "movl %ebx, %esi" - what is ebx here?
 *   At loop start: ebx = hash slot index.
 *   After first check fails, we enter .Lf43f48_00044022:
 *     "movzwl (%ecx), %ebx; andl $0x3fff, %ebx" -> ebx = ecx[0] & 0x3fff = next of chain_next = newIndex
 *     "leal scrStringGlob(, %ebx, 4), %ecx" -> ecx = &scrStringGlob[newIndex*4]
 *     "movzwl 2(%ecx), %eax; cmpl %eax, 8(%ebp)" -> if ecx[1] == stringValue
 *       jne .Lf43f48_00044020 (loop back)
 * So the walk loop: ecx walks the chain, ebx = index of ecx.
 * When ecx[1] == stringValue: break.
 * At .Lf43f48_0004403b (after loop, or via .Lf43f48_00044130):
 *   "movzwl scrStringGlob(, %esi, 4), %eax; andw $0xc000, %ax" -> SG_W0(esi) flags
 *   "movzwl (%ecx), %edx; andw $0x3fff, %dx; orl %edx, %eax" -> SG_W0(esi) = flags | ecx[0]&0x3fff
 *   "movw %ax, scrStringGlob(, %esi, 4)" -> patch prev
 *   "movl %ecx, %edi" -> edi = ecx (found node)
 *   goto .Lf43f48_0004405b (freelist add)
 *
 * At .Lf43f48_0004405b:
 *   edi = node to free, ebx = ... at this point what is bx?
 *   After the loop: bx = ebx = index of ecx (the found node's index)
 *   But "movw %bx, scrStringGlob" means SG_W0(0) = bx = found node's index!
 *   And "movw %bx, scrStringGlob+2(, %eax, 4)" = SG_W1(old_head) = bx = found node index
 * Wait that means: the freelist's new head = found_node_index, and edi[0] = old_head.
 * But edi = found_node_ptr = &scrStringGlob[found_node_idx*4].
 * So: edi[0] = old_head (next ptr), edi[1]=0, old_head's word1 = found_node_idx, SG_W0(0)=found_node_idx.
 * But this should use newEntry (the hash head) as the slot being freed...
 *
 * I think I'm overcomplicating this. Let me re-read the .Lf43f48_0004405b block:
 * "movzwl scrStringGlob, %eax" -> eax = SG_W0(0)  (old freelist head index)
 * "movw %ax, (%edi)" -> edi[0] = old_freelist_head (word0 of node being freed = old head)
 * "movw $0, 2(%edi)" -> edi[1] = 0
 * "movw %bx, scrStringGlob+2(, %eax, 4)" -> SG_W1(old_freelist_head) = bx
 * "movw %bx, scrStringGlob" -> SG_W0(0) = bx
 *
 * What is bx at each call site:
 * 1. From .Lf43f48_0004405b directly (edi=newEntry, came from "je .Lf43f48_0004405b"):
 *    At .Lf43f48_000440f8 -> .Lf43f48_0004405b: this only happens when chain_next == newEntry (je)
 *    In that case bx = ebx = hash_slot_index (the initial value at .Lf43f48_00043fc1)
 *    edi = newEntry = &scrStringGlob[hash*4]
 *    So: edi[0] = old_head, edi[1]=0, SG_W1(old_head)=hash, SG_W0(0)=hash
 *
 * 2. From .Lf43f48_000440f8 (newEntry holds stringValue, esi=chain_next_idx != newEntry):
 *    "movl %esi, %ebx; movl %ecx, %edi; jmp .Lf43f48_0004405b"
 *    ebx = esi = chain_next_idx, edi = ecx = chain_next_ptr
 *    bx = chain_next_idx
 *    So: chain_next[0]=old_head, chain_next[1]=0, SG_W1(old_head)=chain_next_idx, SG_W0(0)=chain_next_idx
 *
 * 3. From .Lf43f48_0004403b (found in chain walk):
 *    ecx = found_ptr, ebx = found_idx, edi = ecx = found_ptr (movl %ecx, %edi)
 *    bx = found_idx
 *    So: found_ptr[0]=old_head, found_ptr[1]=0, SG_W1(old_head)=found_idx, SG_W0(0)=found_idx
 *
 * 4. From .Lf43f48_00044130 (ecx[1]==stringValue where ecx=hash_ptr/chain_next):
 *    "movl %esi, %eax; movl %ebx, %esi; movl %eax, %ebx"
 *    Before this: esi = chain_next_idx (esi from after "andl $0x3fff, %esi"), ecx = chain_next_ptr, ebx = hash_slot_index
 *    After: eax=esi(chain_next_idx), esi=ebx(hash_slot), ebx=eax(chain_next_idx)
 *    Then "jmp .Lf43f48_0004403b":
 *    At .Lf43f48_0004403b: esi = prev (hash_slot as prev for this case)
 *    "movzwl scrStringGlob(, %esi, 4), %eax; andw $0xc000, %ax" = SG_W0(hash_slot) flags
 *    "movzwl (%ecx), %edx; andw $0x3fff, %dx" = ecx[0] & 0x3fff = chain_next's next
 *    "orl %edx, %eax; movw %ax, scrStringGlob(, %esi, 4)" = patch hash_slot's next to skip chain_next
 *    "movl %ecx, %edi" = edi = chain_next_ptr (found node)
 *    Then freelist add with bx = ebx = chain_next_idx.
 *
 * OK so the pattern is consistent: bx is always the INDEX of edi (the node being freed).
 * The freelist links: new_node[0]=old_head_idx, old_head's word1 = new_node_idx, freelist_head=new_node_idx.
 * This is a doubly-linked-ish freelist where each node's word1 points back to who added it.
 *
 * Actually I think this is just: freelist is singly linked via word0, and word1 is unused (set to 0 normally).
 * The "SG_W1(old_head) = bx" line sets the word1 of what WAS the freelist head.
 * But looking at .Lf43f48_0004405b again: it sets SG_W0(0) = bx which means the freelist HEAD is now bx.
 * And edi[0] = old_head means the freed node points to the old head.
 * And SG_W1(old_head) = bx means... the old head's word1 = the new head index?
 *
 * Wait - maybe this is scrStringGlob[0].word0 and scrStringGlob[0].word1 being used differently.
 * scrStringGlob[0] is the "master head" slot: word0 = freelist head index.
 * But here: SG_W1(old_head) = bx, then SG_W0(0) = bx.
 * If old_head was 5 (slot 5 is old freelist head), and bx is the newly freed slot (say slot 3):
 *   slot[3].word0 = 5 (points to slot 5 = old head)
 *   slot[3].word1 = 0
 *   slot[5].word1 = 3 (the new head points back? Or is this initialization for something?)
 *   slot[0].word0 = 3 (new freelist head is slot 3)
 * Hmm, why would we set old_head's word1?
 *
 * Actually re-reading SL_RemoveRefToStringOfLen:
 * "movw %cx, scrStringGlob+2(, %eax, 4)" where cx = esi = hash_slot (newEntry_idx in my translation)
 * "movw %cx, scrStringGlob" -> SG_W0(0) = cx = hash_slot (newEntry_idx)
 * So in that function: freelist head = hash_slot (NOT the node being freed).
 * And in SL_RemoveRefToString: SG_W0(0) = bx = found_node_idx...
 *
 * So in SL_RemoveRefToStringOfLen, cx = esi = hash_slot = newEntry slot index.
 * In SL_RemoveRefToString, bx = found node index.
 * These are DIFFERENT! So the freelist add in SL_RemoveRefToString adds the FOUND NODE to freelist
 * using the found node's index (bx), not the newEntry index.
 *
 * BUT in SL_RemoveRefToStringOfLen: "movw %cx, scrStringGlob" = SG_W0(0) = esi = hash_slot = newEntry_idx!
 * That means in SL_RemoveRefToStringOfLen, the freelist adds the HASH SLOT (not the found node directly).
 *
 * Let me just translate SL_RemoveRefToString's freelist add with bx = found_idx:
 */
unsigned int SL_RemoveRefToString(unsigned int stringValue)
{
    byte *base = *(byte **)imp_scrMemTreePub;
    byte *entry = base + stringValue * 8;
    unsigned int ecx_len;  /* strlen */
    unsigned int len;
    byte *str_ptr;
    unsigned int hash_slot;
    unsigned int newEntry_idx;
    unsigned short *edi_newEntry;
    unsigned int esi_chain_next_idx;
    unsigned short *ecx_hash;

    /* Fix #105: Guard against stale refs on freed nodes.
     * After SL_ShutdownSystem, stale bytecode may call AddRef then RemoveRef
     * on freed memory. The bytes are treap data now — reading entry[0] as
     * byteLen would produce garbage. Skip entirely if covered by free block. */
    {
        extern int MT_IsNodeCovered(int nodeNum);
        if (MT_IsNodeCovered(stringValue))
            return 0;
    }

    /* Compute strlen from entry[0] (same pattern as SL_GetStringLen) */
    ecx_len = (unsigned int)((unsigned char)(entry[0] - 1));
    if (entry[4 + ecx_len] != 0)
    {
        byte *p = entry + 4 + ecx_len;
        do {
            ecx_len += 0x100;
            p += 0x100;
        } while (*p != 0);
    }
    ecx_len += 1;  /* .Lf43f48_00043f71: addl $1, %ecx */
    len = ecx_len;

    /* Decrement refcount */
    {
        unsigned short ref = *(unsigned short *)(entry + 2) - 1;
        *(unsigned short *)(entry + 2) = ref;
        if (ref != 0)
            return 0;
    }

    /* String data pointer: entry+4 */
    str_ptr = entry + 4;

    /* Compute hash slot */
    if (len > 0xff)
        hash_slot = (((len >> 2) % 16383) + 1);
    else if (len == 0)
        hash_slot = 1;
    else
        hash_slot = compute_hash_slot((const char *)str_ptr, len);

    /* .Lf43f48_00043fc1: */
    {
        unsigned int ebx_hash = hash_slot;
        unsigned int edx_offset = ebx_hash * 4;
        edi_newEntry = (unsigned short *)((char *)&scrStringGlob + edx_offset);
        newEntry_idx = hash_slot;

        /* Free the memory node. The MT_IsNodeCovered guard at the top
         * of this function already prevents double-frees from stale refs. */
        MT_FreeIndex(stringValue, len + 4);

        /* Re-read chain_next */
        esi_chain_next_idx = (unsigned int)(SG_W0(hash_slot) & 0x3fff);
        ecx_hash = (unsigned short *)((char *)&scrStringGlob + esi_chain_next_idx * 4);

        if (edi_newEntry[1] == (unsigned short)stringValue)
        {
            /* .Lf43f48_000440f8: newEntry holds stringValue */
            if (ecx_hash == edi_newEntry)
            {
                /* esi = chain_next == newEntry: single-node case */
                /* ecx = esi = chain_next_idx, bx = ebx = hash_slot, edi = newEntry */
                /* But "je .Lf43f48_0004405b" -> go to freelist add with current registers */
                /* At that point: esi = newEntry idx, bx = hash_slot */
                /* "movl %esi, %ebx; movl %ecx, %edi; jmp .Lf43f48_0004405b" -- NO, that's the else branch */
                /* .Lf43f48_000440f8: "cmpl %ecx, %edi; je .Lf43f48_0004405b" */
                /* If equal, jump to freelist add directly. At that point: */
                /* edi = newEntry (= edi_newEntry), bx = ebx = hash_slot */
                /* goto freelist_add with edi=edi_newEntry, bx=hash_slot */
                goto freelist_add_with_hash;
            }
            else
            {
                /* "movzwl scrStringGlob(%edx), %eax; andw $0x3fff, %ax; orw $0x8000, %ax" */
                /* FIX #103: %edx = chain_next_idx*4 at this point (not hash_slot*4).
                 * Read chain_next's w0 to skip past chain_next, since chain_next is being freed.
                 * Original decompilation assumed %edx was still hash_slot*4, but it was reloaded
                 * to chain_next_idx*4 when computing ecx_hash pointer. */
                {
                    unsigned short new_w0 = (unsigned short)((SG_W0(esi_chain_next_idx) & 0x3fff) | 0x8000);
                    SG_W0(hash_slot) = new_w0;
                }
                /* "movzwl 2(%ecx), %eax; movw %ax, 2(%edi)" */
                /* edi_newEntry[1] = ecx_hash[1] */
                edi_newEntry[1] = ecx_hash[1];
                /* "movl %edi, scrStringGlob+65540" */
                SG_RESTART = (void *)edi_newEntry;
                /* "movl %esi, %ebx; movl %ecx, %edi; jmp .Lf43f48_0004405b" */
                /* ebx = esi = chain_next_idx, edi = ecx = chain_next_ptr */
                {
                    unsigned int bx_new = esi_chain_next_idx;
                    unsigned short *edi_new = ecx_hash;
                    /* freelist add: edi=ecx_hash, bx=chain_next_idx */
                    unsigned short old_head2 = SG_W0(0);
                    edi_new[0] = old_head2;
                    edi_new[1] = 0;
                    SG_W1((unsigned int)old_head2) = (unsigned short)bx_new;
                    SG_W0(0) = (unsigned short)bx_new;
                    return 0;
                }
            }
        }
        else
        {
            unsigned int esi_prev;
            /* Check ecx_hash[1] == stringValue */
            if (ecx_hash[1] == (unsigned short)stringValue)
            {
                /* .Lf43f48_00044130: */
                /* "movl %esi, %eax; movl %ebx, %esi; movl %eax, %ebx" */
                /* eax = esi_chain_next_idx, esi = ebx(hash_slot), ebx = chain_next_idx */
                /* Then jmp .Lf43f48_0004403b */
                /* At .Lf43f48_0004403b: esi = prev = hash_slot (became esi), ecx = chain_next, ebx = chain_next_idx */
                esi_prev = hash_slot;
                /* ecx_hash = chain_next (already set) */
                /* ebx = esi_chain_next_idx */
                unsigned int ebx_found_idx = esi_chain_next_idx;
                goto patch_chain;
                /* patch_chain: */
                /* "movzwl scrStringGlob(, %esi, 4), %eax; andw $0xc000, %ax" = SG_W0(esi_prev) flags */
                /* "movzwl (%ecx), %edx; andw $0x3fff, %dx; orl %edx, %eax" = flags | (ecx_hash[0]&0x3fff) */
                /* "movw %ax, scrStringGlob(, %esi, 4)" */
                /* "movl %ecx, %edi" = edi = ecx_hash */
                /* goto freelist_add with bx=ebx_found_idx */

            patch_chain:
                {
                    unsigned short pf2 = SG_W0(esi_prev) & 0xc000;
                    unsigned short cn2 = ecx_hash[0] & 0x3fff;
                    SG_W0(esi_prev) = pf2 | cn2;
                }
                {
                    unsigned short old_head3 = SG_W0(0);
                    ecx_hash[0] = old_head3;
                    ecx_hash[1] = 0;
                    SG_W1((unsigned int)old_head3) = (unsigned short)ebx_found_idx;
                    SG_W0(0) = (unsigned short)ebx_found_idx;
                    return 0;
                }
            }
            else
            {
                /* .Lf43f48_00044022: walk chain */
                /* ebx = ecx_hash[0] & 0x3fff = next of chain_next */
                /* ecx = &scrStringGlob[ebx*4] */
                /* loop until ecx[1] == stringValue */
                unsigned int ebx_walk = (unsigned int)(ecx_hash[0] & 0x3fff);
                unsigned short *ecx_walk = (unsigned short *)((char *)&scrStringGlob + ebx_walk * 4);
                esi_prev = esi_chain_next_idx; /* esi = chain_next_idx as initial prev */

                { int _iters = 0;
                while (ecx_walk[1] != (unsigned short)stringValue)
                {
                    if (ebx_walk == 0 || ++_iters > 16384)
                        return 0; /* chain end or cycle */
                    esi_prev = ebx_walk;
                    ebx_walk = (unsigned int)(ecx_walk[0] & 0x3fff);
                    ecx_walk = (unsigned short *)((char *)&scrStringGlob + ebx_walk * 4);
                } }

                /* Found: ecx_walk = found node, ebx_walk = found_idx, esi_prev = prev_idx */
                /* .Lf43f48_0004403b: */
                {
                    unsigned short pf3 = SG_W0(esi_prev) & 0xc000;
                    unsigned short cn3 = ecx_walk[0] & 0x3fff;
                    SG_W0(esi_prev) = pf3 | cn3;
                }
                {
                    unsigned short old_head4 = SG_W0(0);
                    ecx_walk[0] = old_head4;
                    ecx_walk[1] = 0;
                    SG_W1((unsigned int)old_head4) = (unsigned short)ebx_walk;
                    SG_W0(0) = (unsigned short)ebx_walk;
                    return 0;
                }
            }
        }
    }

freelist_add_with_hash:
    /* edi = edi_newEntry, bx = hash_slot (ebx_hash = newEntry_idx) */
    {
        unsigned short old_head5 = SG_W0(0);
        edi_newEntry[0] = old_head5;
        edi_newEntry[1] = 0;
        SG_W1((unsigned int)old_head5) = (unsigned short)hash_slot;
        SG_W0(0) = (unsigned short)hash_slot;
    }
    return 0;
}

/* line 1094 */
/*
 * SL_ShutdownSystem: iterate hash table slots 1..0x3fff.
 * For each occupied slot (word0 & 0xc000 != 0):
 *   get mem entry, check if entry[1] & user != 0
 *   if yes: entry[1] &= ~user, SG_RESTART=0, SL_RemoveRefToString(sv)
 *   After SL_RemoveRefToString, check SG_RESTART: if nonzero, re-process same slot
 *
 * The ASM loops esi from 1 to 0x3fff, incrementing AFTER the per-slot work.
 * If SG_RESTART != 0, we go back to the SAME slot (the outer loop continues from esi).
 * But esi is incremented at "addl $1, %esi" at the end, so we'd skip one...
 * Wait: looking at .Lf4413c_000441a9: "addl $1, %esi; cmpl $0x4000, %esi; jne .Lf4413c_00044152"
 * .Lf4413c_00044152 is the loop body. And after SL_RemoveRefToString:
 * "movl scrStringGlob+65540, %eax; testl %eax, %eax; jne .Lf4413c_00044152"
 * This re-runs the loop body WITHOUT incrementing esi! So same slot is re-tried.
 */
unsigned int SL_ShutdownSystem(unsigned int user)
{
    unsigned int esi;
    unsigned char user_notb = (unsigned char)(~(unsigned char)user);
    byte *base;
    unsigned short *entry_ptr;
    extern void DBG_PrintTransferStats(void);
    if (user == 1) DBG_PrintTransferStats();
    unsigned int sv;
    byte *mem;
    static int dbg_shutdown_count = 0;
    int freed_count = 0, underflow_count = 0, survived_count = 0;

    for (esi = 1; esi < 0x4000; esi++)
    {
    retry_slot:
        entry_ptr = (unsigned short *)((char *)&scrStringGlob + esi * 4);

        if ((SG_W0(esi) & 0xc000) == 0)
            continue;

        sv = (unsigned int)entry_ptr[1];
        base = *(byte **)imp_scrMemTreePub;
        mem = base + sv * 8;

        if (!((unsigned char)mem[1] & (unsigned char)user))
            continue;

        {
            unsigned short refcount_before = *(unsigned short *)(mem + 2);
            if (dbg_shutdown_count < 3 && user == 1) {
                const char *str_data = (const char *)(mem + 4);
                if (refcount_before == 1) {
                    Com_Printf("DBG SHUTDOWN(1) WILL-FREE: sv=%u ref=%u user=0x%02x str=\"%.24s\"\n",
                        sv, refcount_before, (unsigned)mem[1], str_data);
                    freed_count++;
                } else if (refcount_before == 0) {
                    underflow_count++;
                } else {
                    survived_count++;
                }
            } else if (user == 1) {
                if (refcount_before == 1)
                    freed_count++;
                else if (refcount_before == 0)
                    underflow_count++;
                else
                    survived_count++;
            }
        }

        mem[1] &= user_notb;
        SG_RESTART = (void *)0;
        SL_RemoveRefToString(sv);

        if (SG_RESTART != (void *)0)
            goto retry_slot;
    }

    if (user == 1) {
        Com_Printf("DBG SL_ShutdownSystem(1) SUMMARY: freed=%d underflow=%d survived=%d\n",
            freed_count, underflow_count, survived_count);
        dbg_shutdown_count++;
    }

    return 0;
}

/* line 1040 */
/*
 * Scr_SetString: if from != 0, increment refcount of from.
 * If *to != 0, call SL_RemoveRefToString(*to).
 * Set *to = from.
 */
unsigned int Scr_SetString(scr_string_t *to, unsigned int from)
{
    if (from)
    {
        byte *base = *(byte **)imp_scrMemTreePub;
        *(unsigned short *)(base + from * 8 + 2) += 1;
    }

    if (*to)
    {
        SL_RemoveRefToString((unsigned int)*to);
    }

    *to = (scr_string_t)from;
    return 0;
}

/* line 731 */
/*
 * SL_ConvertToLowercase: get the string for stringValue, convert to lowercase,
 * call SL_GetStringOfLen with the lowercase version, remove ref to original.
 *
 * From ASM:
 * - entry = base + stringValue*8
 * - strlen via get_entry_strlen pattern -> ecx = prev, esi = ecx+1 = len
 * - if esi > 0x2000: return stringValue (too long)
 * - if stringValue != 0: str_ptr = entry+4; else: -0x201c(%ebp) = 0 (str_ptr = null? stored in local)
 * - if esi == 0: skip copy loop
 * - else: copy loop, tolower each char
 * - call SL_GetStringOfLen(newStr, user, esi, type) -> newStringValue in ebx
 * - SL_RemoveRefToString(stringValue)
 * - return newStringValue
 *
 * Wait, looking at the ASM more carefully:
 * .Lf441f8_00044220:
 *   "leal 1(%ecx), %esi" -> esi = ecx+1 = len
 *   "cmpl $0x2000, %esi; ja .Lf441f8_00044269" -> if esi > 0x2000: return stringValue (movl %edi, %eax; ret)
 *   "testl %edi, %edi; jne .Lf441f8_00044293" -> if stringValue != 0: goto get_str_ptr
 *   "movl $0, -0x201c(%ebp)" -> str_ptr local = null
 *   "testl %esi, %esi; jne .Lf441f8_000442a0" -> if len > 0: goto copy_loop
 * .Lf441f8_0004423d: (after copy or if len==0)
 *   SL_GetStringOfLen(newStr, user, len, type)
 *   SL_RemoveRefToString(stringValue)
 *   return newStringValue
 *
 * .Lf441f8_00044293: (stringValue != 0)
 *   "addl $4, %ebx" where ebx = entry ptr at this point -> str_ptr = entry+4
 *   "movl %ebx, -0x201c(%ebp)"
 *   "testl %esi, %esi; je .Lf441f8_0004423d" -> if len==0: skip copy
 *
 * .Lf441f8_000442a0: (copy loop)
 *   ebx (index) = 0, eax = 0
 * .Lf441f8_000442a4:
 *   "movl -0x201c(%ebp), %edx; movsbl (%edx, %eax), %eax" -> char at str_ptr[i]
 *   "calll ___tolower"
 *   "movb %al, -0x2018(%ebx, %ebp)" -> newStr[ebx] = tolower(char)
 *   "addl $1, %ebx" -> ebx++
 *   "movl %ebx, %eax" -> eax = ebx
 *   "cmpl %ebx, %esi; ja .Lf441f8_000442a4" -> if esi > ebx: continue (unsigned compare: ja)
 *
 * Note: "ja" is unsigned "above" = CF=1 OR ZF=0, same as > for unsigned.
 * So loop while esi > ebx (unsigned), i.e., ebx from 0..esi-1, which is esi iterations.
 * Also: in the loop, "movsbl (%edx, %eax), %eax" uses eax as index (initialized 0, then ebx).
 * Actually: eax starts at 0, then becomes ebx. So on iteration 0: reads str_ptr[0] (eax=0).
 * After tolower: ebx becomes 1, eax = ebx = 1. On iteration 1: reads str_ptr[1] (eax=1). Etc.
 * This works correctly: i from 0 to esi-1.
 */
unsigned int SL_ConvertToLowercase(unsigned int stringValue, unsigned int user, int type)
{
    char newStr[0x2000];
    byte *base = *(byte **)imp_scrMemTreePub;
    byte *entry = base + stringValue * 8;
    unsigned int ecx_prev;
    unsigned int esi_len;
    const char *str_ptr;
    unsigned int newStringValue;
    unsigned int i;

    /* Compute strlen */
    ecx_prev = (unsigned int)((unsigned char)(entry[0] - 1));
    if (entry[4 + ecx_prev] != 0)
    {
        byte *p = entry + 4 + ecx_prev;
        do {
            ecx_prev += 0x100;
            p += 0x100;
        } while (*p != 0);
    }
    esi_len = ecx_prev + 1;

    /* If too long, return unchanged */
    if (esi_len > 0x2000)
        return stringValue;

    /* Get str_ptr */
    if (stringValue != 0)
        str_ptr = (const char *)(entry + 4);
    else
        str_ptr = (const char *)0;

    /* Copy + lowercase */
    if (esi_len > 0)
    {
        if (str_ptr != (const char *)0)
        {
            for (i = 0; i < esi_len; i++)
            {
                newStr[i] = (char)tolower((unsigned char)str_ptr[i]);
            }
        }
        /* if str_ptr == null but len > 0: copy loop would read from null, but
         * that can't happen since stringValue==0 implies the string is "" which has len==0 */
    }

    newStringValue = SL_GetStringOfLen(newStr, user, esi_len, type);
    SL_RemoveRefToString(stringValue);
    return newStringValue;
}

/* line 1130 */
/*
 * Scr_ShutdownGameStrings: same structure as SL_ShutdownSystem but checks bit 1 (user=1, "game" strings).
 * Uses imp_scrMemTreePub cached differently (esi = imp_scrMemTreePub, then (%esi) each time).
 */
unsigned int Scr_ShutdownGameStrings(void)
{
    unsigned int ebx_i;
    byte *base;
    unsigned short *entry_ptr;
    unsigned int sv;
    byte *mem;

    for (ebx_i = 1; ebx_i < 0x4000; ebx_i++)
    {
    retry_game:
        entry_ptr = (unsigned short *)((char *)&scrStringGlob + ebx_i * 4);

        if ((SG_W0(ebx_i) & 0xc000) == 0)
            continue;

        sv = (unsigned int)entry_ptr[1];
        base = *(byte **)imp_scrMemTreePub;
        mem = base + sv * 8;

        if (!(mem[1] & 1))
            continue;

        mem[1] &= 0xfe;  /* ~1 = 0xfe */
        SG_RESTART = (void *)0;
        SL_RemoveRefToString(sv);

        if (SG_RESTART != (void *)0)
            goto retry_game;
    }

    return 0;
}

/* line 287 */
/*
 * SL_Init: Initialize or re-initialize the string list.
 *
 * If already initialized (SG_INIT_FLAG != 0):
 *   Phase 1: iterate hash table, free entries without bit 4 set in user, reset those with bit 4.
 *   Phase 2: MT_InitForceAlloc, re-alloc remaining script strings, MT_FinishForceAlloc.
 *
 * If not initialized:
 *   Call MT_Init().
 *   Build freelist: slots 1..0x3fff in a linked list, slot 0 = head.
 *   Set SG_INIT_FLAG = 1.
 *
 * For the first-init path, the ASM:
 *   SG_W0(0) = 0  ("movw $0, scrStringGlob")
 *   Loop: edx=0, ecx=1, ebx=4
 *     "movw $0, scrStringGlob(%ebx)" -> SG_W0 at offset ebx = 0? Actually it's the LOW word at %ebx.
 *     Wait: "leal 1(%ecx), %eax" gives next ecx. The loop at .Lf4433e_00044637:
 *       movl %ecx, %edx; movl %eax, %ecx; addl $4, %ebx
 *     .Lf4433e_0004463e:
 *       movw $0, scrStringGlob(%ebx)  -> word at scrStringGlob+ebx = 0 (this is slot[ebx/4].word0? No, it's not slot-indexed)
 *       orw %cx, scrStringGlob(, %edx, 4)  -> SG_W0(edx) |= cx (i.e., SG_W0(prev) |= cur)
 *       movw %dx, scrStringGlob+2(%ebx)   -> word at scrStringGlob+ebx+2 = dx = prev
 *       leal 1(%ecx), %eax -> next = cur + 1
 *       cmpl $0x4000, %eax; jne .Lf4433e_00044637
 *     After loop: "movw %cx, scrStringGlob+2" -> SG_W1(0) = cur (last cur = 0x3fff)
 *
 * So the loop builds a chain: for i = 1..0x3fff:
 *   slot[i].word0 = 0 (the movw $0 at offset i*4)
 *   SG_W0(prev) |= cur  (prev's word0 |= i) -> this sets the "next" in prev's freelist link
 *   slot[i].word1 = prev (= word at offset i*4+2)
 * Initially SG_W0(0) = 0 and no bits set, so SG_W0(0) |= 1 => SG_W0(0) = 1.
 * Then SG_W0(1) |= 2 = 2. Etc.
 * slot[i].word0 = 0 initially, then SG_W0(i) |= i+1 = i+1 (next in chain).
 * slot[i].word1 = i-1 (prev).
 * After loop: SG_W1(0) = 0x3fff (last cur).
 * This builds a doubly-linked freelist.
 * SG_W0(0) = 1 (first free slot), slots 1..0x3fff each point to next, with SG_W1 as "owner" tracking.
 *
 * For re-init path (already initialized):
 * Loop idx from 1 to 0x3fff:
 *   if SG_W0(idx) & 0xc000 == 0: skip
 *   SG_RESTART = 0; sv = SG_W1(idx); mem = base + sv*8
 *   if mem[1] & 4 (script string bit):
 *     mem[2..3] = 1; mem[1] = 4; check SG_RESTART and retry/continue
 *   else:
 *     mem[2..3] = 0; mem[1] = 0
 *     compute strlen, compute hash, MT_FreeIndex, unlink from hash, add to freelist
 *     check SG_RESTART and retry/continue
 *
 * Phase 2: for each occupied slot, if mem[1]&4: call MT_ForceAllocIndex
 *
 * The re-init inner loop for SL_RemoveRefToString-like unlink is nearly identical to
 * SL_RemoveRefToString. I'll use a helper approach via shared goto structure.
 */
unsigned int SL_Init(void)
{
    {
        extern unsigned char scrMemTreeGlob_dbg[];
        Com_Printf("DBG SL_Init: init_flag=%d totalAlloc=%d totalAllocBuckets=%d\n",
            SG_INIT_FLAG != 0 ? 1 : 0,
            *(int *)(scrMemTreeGlob_dbg + 525092), *(int *)(scrMemTreeGlob_dbg + 525096));
    }
    /* Phase check */
    if (SG_INIT_FLAG != 0)
    {
        /* Re-initialize: clean non-script strings */
        unsigned int idx;
        for (idx = 1; idx < 0x4000; idx++)
        {
            unsigned int sv2;
            byte *base2;
            byte *mem2;

        reinit_retry:
            if ((SG_W0(idx) & 0xc000) == 0)
                continue;

            SG_RESTART = (void *)0;
            sv2 = (unsigned int)SG_W1(idx);
            base2 = *(byte **)imp_scrMemTreePub;
            mem2 = base2 + sv2 * 8;

            if (mem2[1] & 4)
            {
                /* Script string: reset refcount and user to fresh */
                *(unsigned short *)(mem2 + 2) = 1;
                mem2[1] = 4;

                if (SG_RESTART != (void *)0)
                    goto reinit_retry;
                continue;
            }

            /* Not a script string: free it */
            *(unsigned short *)(mem2 + 2) = 0;
            mem2[1] = 0;

            /* Compute strlen */
            {
                unsigned int ecx3 = (unsigned int)((unsigned char)(mem2[0] - 1));
                if (mem2[4 + ecx3] != 0)
                {
                    byte *pp3 = mem2 + 4 + ecx3;
                    do {
                        ecx3 += 0x100;
                        pp3 += 0x100;
                    } while (*pp3 != 0);
                }
                ecx3 += 1;

                /* ecx3 = len, leal 4(%edi) = str_ptr */
                {
                    unsigned int len3 = ecx3;
                    byte *str_ptr3 = mem2 + 4;
                    unsigned int hash3;
                    unsigned int newEntry_idx3;
                    unsigned short *edi3;
                    unsigned int esi3_chain;
                    unsigned short *ecx3_hash;

                    if (len3 > 0xff)
                        hash3 = ((len3 >> 2) % 16383) + 1;
                    else if (len3 == 0)
                        hash3 = 1;
                    else
                        hash3 = compute_hash_slot((const char *)str_ptr3, len3);

                    newEntry_idx3 = hash3;
                    edi3 = (unsigned short *)((char *)&scrStringGlob + newEntry_idx3 * 4);

                    MT_FreeIndex(sv2, len3 + 4);

                    esi3_chain = (unsigned int)(SG_W0(hash3) & 0x3fff);
                    ecx3_hash = (unsigned short *)((char *)&scrStringGlob + esi3_chain * 4);

                    /* Unlink sv2 from hash chain (same logic as SL_RemoveRefToString) */
                    if (edi3[1] == (unsigned short)sv2)
                    {
                        /* newEntry holds sv2 */
                        if (ecx3_hash == edi3)
                        {
                            /* Single node: free newEntry */
                            unsigned short old_h3 = SG_W0(0);
                            edi3[0] = old_h3;
                            edi3[1] = 0;
                            SG_W1((unsigned int)old_h3) = (unsigned short)hash3;
                            SG_W0(0) = (unsigned short)hash3;
                        }
                        else
                        {
                            /* Move chain_next to head, free chain_next */
                            unsigned short new_w03 = (unsigned short)((esi3_chain & 0x3fff) | 0x8000);
                            SG_W0(hash3) = new_w03;
                            edi3[1] = ecx3_hash[1];
                            SG_RESTART = (void *)edi3;
                            {
                                unsigned short old_h4 = SG_W0(0);
                                ecx3_hash[0] = old_h4;
                                ecx3_hash[1] = 0;
                                SG_W1((unsigned int)old_h4) = (unsigned short)esi3_chain;
                                SG_W0(0) = (unsigned short)esi3_chain;
                            }
                        }
                    }
                    else
                    {
                        unsigned int esi3_prev;
                        if (ecx3_hash[1] == (unsigned short)sv2)
                        {
                            /* .Lf4433e_00044130 -> .Lf4433e_0004403b equiv */
                            esi3_prev = hash3;
                            {
                                unsigned short pf4 = SG_W0(esi3_prev) & 0xc000;
                                unsigned short cn4 = ecx3_hash[0] & 0x3fff;
                                SG_W0(esi3_prev) = pf4 | cn4;
                                {
                                    unsigned short old_h5 = SG_W0(0);
                                    ecx3_hash[0] = old_h5;
                                    ecx3_hash[1] = 0;
                                    SG_W1((unsigned int)old_h5) = (unsigned short)esi3_chain;
                                    SG_W0(0) = (unsigned short)esi3_chain;
                                }
                            }
                        }
                        else
                        {
                            unsigned int ebx3w = (unsigned int)(ecx3_hash[0] & 0x3fff);
                            unsigned short *ecx3w = (unsigned short *)((char *)&scrStringGlob + ebx3w * 4);
                            esi3_prev = esi3_chain;
                            while (ecx3w[1] != (unsigned short)sv2)
                            {
                                esi3_prev = ebx3w;
                                ebx3w = (unsigned int)(ecx3w[0] & 0x3fff);
                                ecx3w = (unsigned short *)((char *)&scrStringGlob + ebx3w * 4);
                            }
                            {
                                unsigned short pf5 = SG_W0(esi3_prev) & 0xc000;
                                unsigned short cn5 = ecx3w[0] & 0x3fff;
                                SG_W0(esi3_prev) = pf5 | cn5;
                                {
                                    unsigned short old_h6 = SG_W0(0);
                                    ecx3w[0] = old_h6;
                                    ecx3w[1] = 0;
                                    SG_W1((unsigned int)old_h6) = (unsigned short)ebx3w;
                                    SG_W0(0) = (unsigned short)ebx3w;
                                }
                            }
                        }
                    }
                }
            }

            if (SG_RESTART != (void *)0)
                goto reinit_retry;
        }

        /* Phase 2: force-alloc */
        {
            byte *allocBits = MT_InitForceAlloc();
            unsigned int i2;
            for (i2 = 1; i2 < 0x4000; i2++)
            {
                if ((SG_W0(i2) & 0xc000) == 0)
                    continue;

                {
                    unsigned int sv3 = (unsigned int)SG_W1(i2);
                    byte *base3 = *(byte **)imp_scrMemTreePub;
                    byte *mem3 = base3 + sv3 * 8;

                    if (!(mem3[1] & 4))
                        continue;

                    /* Get string ptr and length */
                    {
                        const char *s3;
                        unsigned int sz3;

                        if (sv3 != 0)
                            s3 = (const char *)(mem3 + 4);
                        else
                            s3 = (const char *)0;

                        if (s3 != (const char *)0)
                            sz3 = (unsigned int)strlen(s3) + 1 + 4;
                        else
                            sz3 = 4;

                        MT_ForceAllocIndex(allocBits, sv3, (int)sz3);
                    }
                }
            }
            MT_FinishForceAlloc(allocBits);
        }

        return 0;
    }

    /* First initialization */
    MT_Init();

    /* Initialize freelist: SG_W0(0) = 0, then build chain 1..0x3fff */
    SG_W0(0) = 0;

    {
        unsigned int edx_prev = 0;
        unsigned int ecx_cur = 1;
        unsigned int ebx_off = 4;
        unsigned int eax_next;

    init_loop:
        /* movw $0, scrStringGlob(%ebx) -> word at offset ebx = 0 */
        *(unsigned short *)((char *)&scrStringGlob + ebx_off) = 0;
        /* orw %cx, scrStringGlob(, %edx, 4) -> SG_W0(prev) |= cur */
        SG_W0(edx_prev) |= (unsigned short)ecx_cur;
        /* movw %dx, scrStringGlob+2(%ebx) -> word at offset ebx+2 = prev */
        *(unsigned short *)((char *)&scrStringGlob + ebx_off + 2) = (unsigned short)edx_prev;

        eax_next = ecx_cur + 1;
        if (eax_next == 0x4000)
            goto init_done;

        edx_prev = ecx_cur;
        ecx_cur = eax_next;
        ebx_off += 4;
        goto init_loop;

    init_done:
        /* movw %cx, scrStringGlob+2 -> SG_W1(0) = ecx_cur (= 0x3fff) */
        *(unsigned short *)((char *)&scrStringGlob + 2) = (unsigned short)ecx_cur;
    }

    SG_INIT_FLAG = 1;

    return 0;
}

/* line 1059 */
/*
 * Scr_AllocString: call SL_GetStringOfLen(s, 1, strlen(s)+1, 6).
 * The type argument in the ASM is "movl $6, 0xc(%esp)" which is passed as 4th arg.
 * user = 1.
 */
unsigned int Scr_AllocString(const char *s, int sys)
{
    unsigned int len = (unsigned int)strlen(s) + 1;
    return SL_GetStringOfLen(s, 1, len, 6);
}

/* line 691 */
/*
 * SL_GetString: SL_GetStringOfLen(str, user, strlen(str)+1, 6).
 */
unsigned int SL_GetString(const char *str, unsigned int user)
{
    unsigned int len = (unsigned int)strlen(str) + 1;
    return SL_GetStringOfLen(str, user, len, 6);
}

/* line 1067 */
/*
 * SL_GetStringForFloat: sprintf(buf, "%g", (double)f), then SL_GetStringOfLen(buf, 0, len, 0xe).
 */
unsigned int SL_GetStringForFloat(float f)
{
    char tempString[0x88];
    unsigned int len;

    sprintf(tempString, "%g", (double)f);
    len = (unsigned int)strlen(tempString) + 1;
    return SL_GetStringOfLen(tempString, 0, len, 0xe);
}

/* line 1076 */
/*
 * SL_GetStringForInt: sprintf(buf, "%i", i), then SL_GetStringOfLen(buf, 0, len, 0xe).
 */
unsigned int SL_GetStringForInt(int i)
{
    char tempString[0x88];
    unsigned int len;

    sprintf(tempString, "%i", i);
    len = (unsigned int)strlen(tempString) + 1;
    return SL_GetStringOfLen(tempString, 0, len, 0xe);
}

/* line 1085 */
/*
 * SL_GetStringForVector: sprintf(buf, "(%g, %g, %g)", v[0], v[1], v[2]), SL_GetStringOfLen(buf, 0, len, 0xe).
 */
unsigned int SL_GetStringForVector(const float *v)
{
    char tempString[0x88];
    unsigned int len;

    sprintf(tempString, "(%g, %g, %g)", (double)v[0], (double)v[1], (double)v[2]);
    len = (unsigned int)strlen(tempString) + 1;
    return SL_GetStringOfLen(tempString, 0, len, 0xe);
}

/* line 1267 */
/*
 * Scr_CreateCanonicalFilename: builds a canonical filename by:
 * - Replacing backslashes with forward slashes
 * - Skipping leading slashes (between path segments)
 * - Converting to lowercase
 * - Detecting buffer overflow (max 0x400 bytes)
 *
 * The ASM has a somewhat complex loop structure. Translating faithfully:
 *
 * Variables:
 *   newFilename[0x400] on stack
 *   newFilename_ptr (-0x41c(%ebp)) = current write position into newFilename
 *   remaining (esi) = 0x400
 *   src (ebx) = filename
 *   c (edi) = current character
 *
 * Main loop (.Lf4482c_0004484c):
 *   c = *src++ (movzbl/movsbl)
 *   if c == '\\' or c == '/': skip (goto .Lf4482c_0004484c)
 *   // c is a non-slash character
 *
 * .Lf4482c_0004485d:
 *   if c <= 0x1f:
 *     if c == 0: *newFilename_ptr = 0; goto get_len_and_return
 *     else (other control): goto .Lf4482c_0004484c (skip)
 *   // c > 0x1f: normal char
 *
 * .Lf4482c_000448b3 (tolower and store):
 *   c = tolower(c)  (if c was '\\': set c='/' first at .Lf4482c_000448ae)
 *   *newFilename_ptr = (char)c
 *   newFilename_ptr++
 *   remaining--
 *   if remaining == 0: Com_Error(...)
 *   if c == '/': goto .Lf4482c_0004484c (skip slashes and restart)
 *
 * .Lf4482c_000448d1: (inner loop: read next char in current path segment)
 *   c = *src++ (movzbl/movsbl)
 *   if c == '\\': c = '/' (jmp .Lf4482c_000448ae -> set edi='/', then .Lf4482c_000448b3)
 *   goto .Lf4482c_0004485d
 *
 * Wait, .Lf4482c_000448d1 is inside the "remaining > 0" check.
 * Let me re-read: after storing char and decrementing remaining:
 *   "subl $1, %esi; je .Lf4482c_000448ed" -> if remaining == 0: error
 *   ".Lf4482c_000448d1: cmpl $0x2f, %edi; je .Lf4482c_0004484c"
 *     -> if c == '/': goto skip-slashes loop
 *   "movzbl (%ebx), %eax; movsbl %al, %edi; addl $1, %ebx"
 *     -> c = *src++
 *   "cmpb $0x5c, %al; jne .Lf4482c_0004485d" -> if c != '\\': goto check c
 *   "jmp .Lf4482c_000448ae" -> c was '\\': set c = '/'
 *
 * And .Lf4482c_000448ae: "movl $0x2f, %edi" -> c = '/'
 * Then falls to .Lf4482c_000448b3 (tolower and store '/')
 *
 * So the structure is:
 * skip_slashes: while c is '\\' or '/': c = *src++
 * check_c:
 *   if c <= 0x1f:
 *     if c == 0: null-terminate and return
 *     else: goto skip_slashes
 *   tolower_store:
 *     *dst++ = tolower(c); remaining--
 *     if remaining == 0: error
 *     if c == '/': goto skip_slashes
 *   inner_loop:
 *     c = *src++
 *     if c == '\\': c = '/'; goto tolower_store
 *     goto check_c
 *
 * This effectively builds canonical paths like "foo/bar/baz" with normalized slashes.
 */
unsigned int Scr_CreateCanonicalFilename(const char *filename)
{
    char newFilename[0x400];
    char *dst = newFilename;
    unsigned int remaining = 0x400;
    const char *src = filename;
    int c;

skip_slashes:
    c = (int)(unsigned char)*src++;
    if (c == '\\' || c == '/')
        goto skip_slashes;

check_c:
    if ((unsigned int)c <= 0x1f)
    {
        if (c == 0)
        {
            *dst = '\0';
            goto get_len_and_return;
        }
        /* Other control char: skip to next segment */
        goto skip_slashes;
    }

    /* c > 0x1f: store it */
    if (c == '\\')
        c = '/';

tolower_store:
    *dst = (char)tolower(c);
    dst++;
    remaining--;
    if (remaining == 0)
    {
        Com_Error(1, "\x15" "Filename '%s' exceeds maximum length of %d", filename, 0);
        /* After error: fall through to inner_loop */
    }

    /* inner_loop */
    if (c == '/')
        goto skip_slashes;

inner_loop:
    c = (int)(unsigned char)*src++;
    if (c == '\\')
    {
        c = '/';
        goto tolower_store;
    }
    goto check_c;

get_len_and_return:
    {
        unsigned int len = (unsigned int)strlen(newFilename) + 1;
        return SL_GetStringOfLen(newFilename, 0, len, 7);
    }
}
