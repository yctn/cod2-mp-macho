/* Rewritten from decompiled ASM to C based on reference CoD2rev_Server implementation.
 * Fix #105: Replaces ~1800 lines of fragile inline ASM treap code with correct C.
 * Root cause: decompiled treap operations corrupted allocated nodes' data,
 * causing buddy-merge to merge over allocated memory ("eft" corruption). */

#include "common_types.h"
#include "imports.h"

extern struct scrMemTreePub_t scrMemTreePub; /* 0x0 */
extern unsigned char scrMemTreeGlob[]; /* scrMemTreeGlob - BSS */

extern byte * Z_VirtualAllocInternal(int size);
extern void Z_VirtualFreeInternal(void *ptr);
extern void Com_Printf(const char *fmt, ...);
extern void Scr_TerminalError(const char *msg);

/* Forward declarations */
unsigned int Scr_GetStringUsage(void);
byte * MT_InitForceAlloc(void);
unsigned int MT_Init(void);
unsigned int MT_DumpTree(void);
short unsigned int MT_AllocIndex(int numBytes, int type);
unsigned int * MT_Alloc(int numBytes, int type);
unsigned int MT_ForceAllocIndex(byte *allocBits, unsigned int nodeNum, int numBytes);
int MT_Realloc(int oldNumBytes, int newNumbytes);
unsigned int MT_Free(unsigned int *p, int numBytes);
unsigned int MT_FreeIndex(unsigned int nodeNum, int numBytes);
unsigned int MT_FinishForceAlloc(byte *allocBits);

/* ============================================================
 * scrMemTreeGlob layout (8-byte MemoryNode, aligned(8)):
 *   nodes[65536]    @ 0x00000  (65536 * 8 = 524288 bytes)
 *   leftBits[256]   @ 0x80000
 *   numBits[256]    @ 0x80100
 *   logBits[256]    @ 0x80200
 *   head[17]        @ 0x80300  (17 * 2 = 34 bytes)
 *   (2 bytes pad)
 *   totalAlloc      @ 0x80324  (4 bytes)
 *   totalAllocBuckets @ 0x80328 (4 bytes)
 *
 * Each MemoryNode (8 bytes):
 *   bytes 0-1: prev (uint16_t) — left child in treap
 *   bytes 2-3: next (uint16_t) — right child in treap
 *   bytes 4-7: padding (unused when free; string data when allocated)
 * ============================================================ */

#define MEMORY_NODE_BITS  16
#define MEMORY_NODE_COUNT 0x10000

/* Node accessors */
#define NODE_PREV(i) (*(unsigned short *)(scrMemTreeGlob + (unsigned)(i)*8))
#define NODE_NEXT(i) (*(unsigned short *)(scrMemTreeGlob + (unsigned)(i)*8 + 2))

/* Copy all 8 bytes of a node (prev + next + padding/data) */
typedef struct { unsigned int w03; unsigned int w47; } NodeVal;
#define NODE_READ(i) ((NodeVal){ \
    *(unsigned int *)(scrMemTreeGlob + (unsigned)(i)*8), \
    *(unsigned int *)(scrMemTreeGlob + (unsigned)(i)*8 + 4) })
#define NODE_WRITE(i, v) do { \
    *(unsigned int *)(scrMemTreeGlob + (unsigned)(i)*8) = (v).w03; \
    *(unsigned int *)(scrMemTreeGlob + (unsigned)(i)*8 + 4) = (v).w47; \
} while(0)

/* Lookup table accessors */
#define LEFT_BITS(i) ((unsigned char)scrMemTreeGlob[0x80000 + (unsigned char)(i)])
#define NUM_BITS(i)  ((unsigned char)scrMemTreeGlob[0x80100 + (unsigned char)(i)])
#define LOG_BITS(i)  ((unsigned char)scrMemTreeGlob[0x80200 + (unsigned char)(i)])

/* Treap bucket heads */
#define HEAD(i)      (*(unsigned short *)(scrMemTreeGlob + 0x80300 + (unsigned)(i)*2))

/* Allocation counters */
#define TOTAL_ALLOC          (*(int *)(scrMemTreeGlob + 0x80324))
#define TOTAL_ALLOC_BUCKETS  (*(int *)(scrMemTreeGlob + 0x80328))

/* ============================================================
 * Helper functions
 * ============================================================ */

static int MT_GetScore(int num)
{
    int val = MEMORY_NODE_COUNT - num;
    unsigned char b0 = (unsigned char)val;
    unsigned char b1 = (unsigned char)(val >> 8);
    int bits = LEFT_BITS(b0);
    if (b0 == 0)
        bits += LEFT_BITS(b1);
    return val - (NUM_BITS(b1) + NUM_BITS(b0)) + (1 << bits);
}

static int MT_GetSize(int numBytes)
{
    int numBuckets;
    if (numBytes > 0xFFFF) {
        MT_DumpTree();
        Com_Printf("%s: failed memory allocation of %d bytes for script usage\n",
            "MT_GetSize: max allocation exceeded", numBytes);
        Scr_TerminalError("failed memory allocation for script usage");
        return 0;
    }
    numBuckets = (numBytes + 7) / 8 - 1;
    if (numBuckets < 0) numBuckets = 0;
    if (numBuckets > 255)
        return LOG_BITS((unsigned)numBuckets >> 8) + 8;
    return LOG_BITS(numBuckets);
}

static void MT_InitBits(void)
{
    int i, temp;
    unsigned char bits;

    for (i = 0; i < 256; i++) {
        /* numBits: popcount */
        bits = 0;
        for (temp = i; temp; temp >>= 1)
            if (temp & 1) bits++;
        scrMemTreeGlob[0x80100 + i] = bits;

        /* leftBits: number of trailing zero bits from MSB side */
        for (bits = 8; i & ((1 << bits) - 1); bits--) {}
        scrMemTreeGlob[0x80000 + i] = bits;

        /* logBits: ceil(log2(i+1)) or bit width */
        bits = 0;
        for (temp = i; temp; temp >>= 1)
            bits++;
        scrMemTreeGlob[0x80200 + i] = bits;
    }
}

/* ============================================================
 * Treap operations (from reference MT_AddMemoryNode etc.)
 * ============================================================ */

static int MT_GetSubTreeSize(int nodeNum)
{
    if (!nodeNum)
        return 0;
    return MT_GetSubTreeSize(NODE_PREV(nodeNum))
         + MT_GetSubTreeSize(NODE_NEXT(nodeNum)) + 1;
}

static void MT_AddMemoryNode(int newNode, int size)
{
    int node, nodeNum, newScore, score, level;
    unsigned short *parentNode;
    NodeVal temp;

    parentNode = &HEAD(size);
    node = HEAD(size);

    if (node) {
        newScore = MT_GetScore(newNode);
        nodeNum = 0;
        level = MEMORY_NODE_COUNT;

        do {
            score = MT_GetScore(node);
            if (score < newScore) {
                /* newNode has higher priority — insert here and push down */
                while (1) {
                    *parentNode = (unsigned short)newNode;
                    temp = NODE_READ(node);
                    NODE_WRITE(newNode, temp);
                    if (!node)
                        break;
                    level >>= 1;
                    if (node >= nodeNum) {
                        parentNode = &NODE_NEXT(newNode);
                        nodeNum += level;
                    } else {
                        parentNode = &NODE_PREV(newNode);
                        nodeNum -= level;
                    }
                    newNode = node;
                    node = *parentNode;
                }
                return;
            }

            level >>= 1;
            if (newNode >= nodeNum) {
                parentNode = &NODE_NEXT(node);
                nodeNum += level;
            } else {
                parentNode = &NODE_PREV(node);
                nodeNum -= level;
            }
            node = *parentNode;
        } while (node);
    }

    /* Insert as leaf */
    *parentNode = (unsigned short)newNode;
    NODE_PREV(newNode) = 0;
    NODE_NEXT(newNode) = 0;
}

static void MT_RemoveHeadMemoryNode(int size)
{
    NodeVal tempNodeValue, oldNodeValue;
    int oldNode;
    unsigned short *parentNode;
    int prevScore, nextScore;
    unsigned short prevChild, nextChild;

    parentNode = &HEAD(size);
    oldNodeValue = NODE_READ(*parentNode);
    prevChild = oldNodeValue.w03 & 0xFFFF;
    nextChild = (oldNodeValue.w03 >> 16) & 0xFFFF;

    while (1) {
        if (!prevChild) {
            oldNode = nextChild;
            *parentNode = nextChild;
            if (!oldNode)
                break;
            parentNode = &NODE_NEXT(oldNode);
        } else if (!nextChild) {
            oldNode = prevChild;
            *parentNode = prevChild;
            parentNode = &NODE_PREV(oldNode);
        } else {
            prevScore = MT_GetScore(prevChild);
            nextScore = MT_GetScore(nextChild);
            if (prevScore >= nextScore) {
                oldNode = prevChild;
                *parentNode = (unsigned short)oldNode;
                parentNode = &NODE_PREV(oldNode);
            } else {
                oldNode = nextChild;
                *parentNode = (unsigned short)oldNode;
                parentNode = &NODE_NEXT(oldNode);
            }
        }

        /* Swap data: push oldNodeValue down into oldNode */
        tempNodeValue = oldNodeValue;
        oldNodeValue = NODE_READ(oldNode);
        NODE_WRITE(oldNode, tempNodeValue);

        prevChild = oldNodeValue.w03 & 0xFFFF;
        nextChild = (oldNodeValue.w03 >> 16) & 0xFFFF;
    }
}

/* Returns 1 if the node was found and removed, 0 if not found */
static int MT_RemoveMemoryNode(int target, int size)
{
    NodeVal tempNodeValue, oldNodeValue;
    int oldNode, node, nodeNum, level;
    unsigned short *parentNode;
    int prevScore, nextScore;
    unsigned short prevChild, nextChild;

    nodeNum = 0;
    level = MEMORY_NODE_COUNT;
    parentNode = &HEAD(size);

    for (node = *parentNode; node; node = *parentNode) {
        if (target == node) {
            /* Found — rotate it down to a leaf and remove */
            oldNodeValue = NODE_READ(target);
            prevChild = oldNodeValue.w03 & 0xFFFF;
            nextChild = (oldNodeValue.w03 >> 16) & 0xFFFF;

            while (1) {
                if (prevChild) {
                    if (nextChild) {
                        prevScore = MT_GetScore(prevChild);
                        nextScore = MT_GetScore(nextChild);
                        if (prevScore >= nextScore) {
                            oldNode = prevChild;
                            *parentNode = (unsigned short)oldNode;
                            parentNode = &NODE_PREV(oldNode);
                        } else {
                            oldNode = nextChild;
                            *parentNode = (unsigned short)oldNode;
                            parentNode = &NODE_NEXT(oldNode);
                        }
                    } else {
                        oldNode = prevChild;
                        *parentNode = (unsigned short)oldNode;
                        parentNode = &NODE_PREV(oldNode);
                    }
                } else {
                    oldNode = nextChild;
                    *parentNode = nextChild;
                    if (!nextChild)
                        return 1; /* removed as leaf */
                    parentNode = &NODE_NEXT(oldNode);
                }

                tempNodeValue = oldNodeValue;
                oldNodeValue = NODE_READ(oldNode);
                NODE_WRITE(oldNode, tempNodeValue);

                prevChild = oldNodeValue.w03 & 0xFFFF;
                nextChild = (oldNodeValue.w03 >> 16) & 0xFFFF;
            }
        }

        if (target == nodeNum)
            return 0; /* not found — BST search terminated */

        level >>= 1;
        if (target >= nodeNum) {
            parentNode = &NODE_NEXT(node);
            nodeNum += level;
        } else {
            parentNode = &NODE_PREV(node);
            nodeNum -= level;
        }
    }

    return 0; /* not found */
}

/* ============================================================
 * Public API
 * ============================================================ */

unsigned int Scr_GetStringUsage(void)
{
    return TOTAL_ALLOC_BUCKETS;
}

byte * MT_InitForceAlloc(void)
{
    TOTAL_ALLOC = 0;
    TOTAL_ALLOC_BUCKETS = 0;
    return Z_VirtualAllocInternal(0x2000);
}

unsigned int MT_Init(void)
{
    int i;

    *(char **)&scrMemTreePub = (char *)scrMemTreeGlob;

    MT_InitBits();

    for (i = 0; i <= MEMORY_NODE_BITS; i++)
        HEAD(i) = 0;

    NODE_PREV(0) = 0;
    NODE_NEXT(0) = 0;

    for (i = 0; i < MEMORY_NODE_BITS; i++)
        MT_AddMemoryNode(1 << i, i);

    TOTAL_ALLOC = 0;
    TOTAL_ALLOC_BUCKETS = 0;
    return 0;
}

unsigned int MT_DumpTree(void)
{
    int size, subTreeSize, totalBuckets;

    Com_Printf("********************************\n");
    for (size = 0; size <= MEMORY_NODE_BITS; size++) {
        subTreeSize = MT_GetSubTreeSize(HEAD(size));
        Com_Printf("%d subtree has %d * %d = %d free buckets\n",
            size, subTreeSize, 1 << size, subTreeSize << size);
    }
    Com_Printf("********************************\n");
    Com_Printf("********************************\n");
    Com_Printf("total memory alloc buckets: %d (%d instances)\n",
        TOTAL_ALLOC_BUCKETS, TOTAL_ALLOC);
    Com_Printf("total memory free buckets: %d\n",
        MEMORY_NODE_COUNT - 1 - TOTAL_ALLOC_BUCKETS);
    Com_Printf("********************************\n");
    return 0;
}

/* Diagnostic: check if a node is reachable from any tree */
static int MT_SearchTreeRec(int node, int target, int depth)
{
    unsigned short prev, next;
    if (node == 0 || depth > 20) return 0;
    if (node == target) return 1;
    prev = NODE_PREV(node);
    next = NODE_NEXT(node);
    return MT_SearchTreeRec(prev, target, depth + 1)
        || MT_SearchTreeRec(next, target, depth + 1);
}

int MT_SearchTreeAny(int nodeNum)
{
    int size;
    for (size = 0; size <= MEMORY_NODE_BITS; size++) {
        if (MT_SearchTreeRec(HEAD(size), nodeNum, 0))
            return 1;
    }
    return 0;
}

/* Check if nodeNum is covered by any free block (either directly in tree or
 * as part of a larger ancestor block at any level). */
int MT_IsNodeCovered(int nodeNum)
{
    int level;
    for (level = 0; level <= MEMORY_NODE_BITS; level++) {
        unsigned short head = HEAD(level);
        if (!head) continue;
        unsigned int ancestor = (unsigned int)nodeNum & ~((1u << level) - 1u);
        if (MT_SearchTreeRec(head, ancestor, 0))
            return 1;
    }
    return 0;
}

int MT_SearchTreeLevel(int nodeNum, int level)
{
    if (level < 0 || level > MEMORY_NODE_BITS) return 0;
    return MT_SearchTreeRec(HEAD(level), nodeNum, 0);
}

void MT_VerifyNotInTree(int nodeNum)
{
    int size;
    for (size = 0; size <= MEMORY_NODE_BITS; size++) {
        if (MT_SearchTreeRec(HEAD(size), nodeNum, 0))
            Com_Printf("TREE BUG: allocated node %d found in tree[%d]!\n", nodeNum, size);
    }
}

short unsigned int MT_AllocIndex(int numBytes, int type)
{
    int size, newSize, nodeNum;

    (void)type; /* unused — was only for debug prints in the Mac binary */

    size = MT_GetSize(numBytes);
    if (size > MEMORY_NODE_BITS)
        return 0;

    for (newSize = size; ; newSize++) {
        if (newSize > MEMORY_NODE_BITS) {
            MT_DumpTree();
            Com_Printf("%s: failed memory allocation of %d bytes for script usage\n",
                "MT_AllocIndex", numBytes);
            Scr_TerminalError("failed memory allocation for script usage");
            return 0;
        }
        nodeNum = HEAD(newSize);
        if (nodeNum)
            break;
    }

    MT_RemoveHeadMemoryNode(newSize);

    /* Split: add unused halves back to smaller bucket levels */
    while (newSize != size) {
        newSize--;
        MT_AddMemoryNode(nodeNum + (1 << newSize), newSize);
    }

    TOTAL_ALLOC++;
    TOTAL_ALLOC_BUCKETS += 1 << size;

    return (unsigned short)nodeNum;
}

unsigned int * MT_Alloc(int numBytes, int type)
{
    unsigned short idx = MT_AllocIndex(numBytes, type);
    return (unsigned int *)(scrMemTreeGlob + (unsigned)idx * 8);
}

unsigned int MT_FreeIndex(unsigned int nodeNum, int numBytes)
{
    int size, lowBit;

    size = MT_GetSize(numBytes);

    TOTAL_ALLOC--;
    TOTAL_ALLOC_BUCKETS -= 1 << size;

    /* Buddy-merge loop */
    while (1) {
        lowBit = 1 << size;
        if (size == MEMORY_NODE_BITS || !MT_RemoveMemoryNode(nodeNum ^ lowBit, size))
            break;
        nodeNum &= ~(unsigned)lowBit;
        size++;
    }

    MT_AddMemoryNode(nodeNum, size);
    return 0;
}

unsigned int MT_Free(unsigned int *p, int numBytes)
{
    unsigned int nodeIdx = ((unsigned char *)p - scrMemTreeGlob) / 8;
    MT_FreeIndex(nodeIdx, numBytes);
    return 0;
}

unsigned int MT_ForceAllocIndex(byte *allocBits, unsigned int nodeNum, int numBytes)
{
    int size, newSize;

    size = MT_GetSize(numBytes);
    TOTAL_ALLOC++;
    newSize = 1 << size;
    TOTAL_ALLOC_BUCKETS += newSize;

    while (newSize) {
        allocBits[nodeNum >> 3] |= (1 << (nodeNum & 7));
        nodeNum++;
        newSize--;
    }
    return 0;
}

int MT_Realloc(int oldNumBytes, int newNumbytes)
{
    return MT_GetSize(oldNumBytes) >= MT_GetSize(newNumbytes);
}

/* MT_SafeFreeIndex: used by MT_FinishForceAlloc to free individual nodes
 * from a force-allocated bitmap. Tries to find the node's position in the
 * buddy tree hierarchy. */
static void MT_SafeFreeIndex(unsigned int nodeNum)
{
    int oldNode, size, lowBit;

    /* First try: walk up the buddy tree trying to remove this node's
     * ancestor at each level. If found, we know the correct merge level. */
    for (size = 0, oldNode = nodeNum;
         !MT_RemoveMemoryNode(oldNode, size);
         oldNode &= ~(1 << size), size++)
    {
        if (size == MEMORY_NODE_BITS) {
            /* Fallback: try buddy-merge like normal MT_FreeIndex */
            size = 0;
            oldNode = nodeNum;
            while (1) {
                lowBit = 1 << size;
                if (size == MEMORY_NODE_BITS || !MT_RemoveMemoryNode(oldNode ^ lowBit, size))
                    break;
                oldNode &= ~lowBit;
                size++;
            }
            break;
        }
    }

    MT_AddMemoryNode(oldNode, size);
}

unsigned int MT_FinishForceAlloc(byte *allocBits)
{
    unsigned int nodeNum;

    for (nodeNum = 1; nodeNum < MEMORY_NODE_COUNT; nodeNum++) {
        if (!(allocBits[nodeNum >> 3] >> (nodeNum & 7) & 1))
            MT_SafeFreeIndex(nodeNum);
    }

    Z_VirtualFreeInternal(allocBits);
    return 0;
}
