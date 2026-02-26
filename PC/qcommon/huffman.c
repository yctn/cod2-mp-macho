/* ASM dump from: huffman.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/huffman.cpp */

#include "common_types.h"
#include "imports.h"

/*
 * Adaptive Huffman compression based on Sayood's Data Compression book.
 * Ranks are implicitly defined by node location in a doubly-linked list.
 *
 * node_t fields (all declared as int but used as pointers on 32-bit):
 *   offset 0x00: left    (node_t *)
 *   offset 0x04: right   (node_t *)
 *   offset 0x08: parent  (node_t *)
 *   offset 0x0c: next    (node_t *)
 *   offset 0x10: prev    (node_t *)
 *   offset 0x14: head    (node_t **)
 *   offset 0x18: weight  (int)
 *   offset 0x1c: symbol  (int)
 */

/* Cast helpers for node_t fields that are int but store pointers */
#define NODE_LEFT(n)    ((node_t *)(n)->left)
#define NODE_RIGHT(n)   ((node_t *)(n)->right)
#define NODE_PARENT(n)  ((node_t *)(n)->parent)
#define NODE_NEXT(n)    ((node_t *)(n)->next)
#define NODE_PREV(n)    ((node_t *)(n)->prev)
#define NODE_HEAD(n)    ((node_t **)(n)->head)

#define SET_LEFT(n, v)    ((n)->left = (int)(v))
#define SET_RIGHT(n, v)   ((n)->right = (int)(v))
#define SET_PARENT(n, v)  ((n)->parent = (int)(v))
#define SET_NEXT(n, v)    ((n)->next = (int)(v))
#define SET_PREV(n, v)    ((n)->prev = (int)(v))
#define SET_HEAD(n, v)    ((n)->head = (int)(v))

#define NYT         256
#define INTERNAL_NODE 257

static int bloc; /* 0xf2f600 */

extern void Com_Memset(void *dest, int val, int count);

void Huff_Init(huffman_t *huff);
void Huff_offsetReceive(node_t *node, int *ch, byte *fin, int *offset);
static void increment(huff_t *huff, node_t *node);
void Huff_addRef(huff_t *huff, int ch, msg_t *mbuf, int offset);
void huffman_send(node_t *node, node_t *child, byte *fout);
void Huff_offsetTransmit(huff_t *huff, int ch, byte *fout, int *offset);

/* Add a bit to the output file (buffered) */
static void add_bit(int bit, byte *fout) {
    if ((bloc & 7) == 0) {
        fout[bloc >> 3] = 0;
    }
    fout[bloc >> 3] |= bit << (bloc & 7);
    bloc++;
}

/* Receive one bit from the input file (buffered) */
static int get_bit(byte *fin) {
    int t;
    t = (fin[bloc >> 3] >> (bloc & 7)) & 0x1;
    bloc++;
    return t;
}

/* Get a free pointer-to-pointer node from the pool */
static node_t **get_ppnode(huff_t *huff) {
    node_t **tppnode;
    if (!huff->freelist) {
        return &(huff->nodePtrs[huff->blocPtrs++]);
    } else {
        tppnode = huff->freelist;
        huff->freelist = (node_t **)*tppnode;
        return tppnode;
    }
}

/* Return a pointer-to-pointer node to the free pool */
static void free_ppnode(huff_t *huff, node_t **ppnode) {
    *ppnode = (node_t *)huff->freelist;
    huff->freelist = ppnode;
}

/* Swap two nodes' positions in the tree */
static void swap(huff_t *huff, node_t *node1, node_t *node2) {
    node_t *par1, *par2;

    par1 = NODE_PARENT(node1);
    par2 = NODE_PARENT(node2);

    if (par1) {
        if (NODE_LEFT(par1) == node1) {
            SET_LEFT(par1, node2);
        } else {
            SET_RIGHT(par1, node2);
        }
    } else {
        huff->tree = node2;
    }

    if (par2) {
        if (NODE_LEFT(par2) == node2) {
            SET_LEFT(par2, node1);
        } else {
            SET_RIGHT(par2, node1);
        }
    } else {
        huff->tree = node1;
    }

    SET_PARENT(node1, par2);
    SET_PARENT(node2, par1);
}

/* Swap two nodes in the linked list (update ranks) */
static void swaplist(node_t *node1, node_t *node2) {
    node_t *par1;

    par1 = NODE_NEXT(node1);
    SET_NEXT(node1, NODE_NEXT(node2));
    SET_NEXT(node2, par1);

    par1 = NODE_PREV(node1);
    SET_PREV(node1, NODE_PREV(node2));
    SET_PREV(node2, par1);

    if (NODE_NEXT(node1) == node1) {
        SET_NEXT(node1, node2);
    }
    if (NODE_NEXT(node2) == node2) {
        SET_NEXT(node2, node1);
    }
    if (NODE_NEXT(node1)) {
        SET_PREV(NODE_NEXT(node1), node1);
    }
    if (NODE_NEXT(node2)) {
        SET_PREV(NODE_NEXT(node2), node2);
    }
    if (NODE_PREV(node1)) {
        SET_NEXT(NODE_PREV(node1), node1);
    }
    if (NODE_PREV(node2)) {
        SET_NEXT(NODE_PREV(node2), node2);
    }
}

/* line 171 */
/* Do the increments */
static void increment(huff_t *huff, node_t *node) {
    node_t *lnode;

    if (!node) {
        return;
    }

    if (NODE_NEXT(node) != NULL && NODE_NEXT(node)->weight == node->weight) {
        lnode = *NODE_HEAD(node);
        if (lnode != NODE_PARENT(node)) {
            swap(huff, lnode, node);
        }
        swaplist(lnode, node);
    }
    if (NODE_PREV(node) && NODE_PREV(node)->weight == node->weight) {
        *NODE_HEAD(node) = NODE_PREV(node);
    } else {
        *NODE_HEAD(node) = NULL;
        free_ppnode(huff, NODE_HEAD(node));
    }
    node->weight++;
    if (NODE_NEXT(node) && NODE_NEXT(node)->weight == node->weight) {
        SET_HEAD(node, NODE_NEXT(node)->head);
    } else {
        SET_HEAD(node, get_ppnode(huff));
        *NODE_HEAD(node) = node;
    }
    if (NODE_PARENT(node)) {
        increment(huff, NODE_PARENT(node));
        if (NODE_PREV(node) == NODE_PARENT(node)) {
            swaplist(node, NODE_PARENT(node));
            if (*NODE_HEAD(node) == node) {
                *NODE_HEAD(node) = NODE_PARENT(node);
            }
        }
    }
}

/* line 340 */
void Huff_offsetReceive(node_t *node, int *ch, byte *fin, int *offset)
{
    bloc = *offset;
    while (node && node->symbol == INTERNAL_NODE) {
        if (get_bit(fin)) {
            node = NODE_RIGHT(node);
        } else {
            node = NODE_LEFT(node);
        }
    }
    if (!node) {
        *ch = 0;
        return;
    }
    *ch = node->symbol;
    *offset = bloc;
}

/* line 366 */
/* Send the prefix code for this node */
void huffman_send(node_t *node, node_t *child, byte *fout)
{
    if (NODE_PARENT(node)) {
        huffman_send(NODE_PARENT(node), node, fout);
    }
    if (child) {
        if (NODE_RIGHT(node) == child) {
            add_bit(1, fout);
        } else {
            add_bit(0, fout);
        }
    }
}

/* line 223 */
void Huff_addRef(huff_t *huff, int ch, msg_t *mbuf, int offset)
{
    node_t *tnode, *tnode2;

    ch = (byte)ch;

    if (huff->loc[ch] != NULL) {
        /* Symbol already in tree, just increment */
        increment(huff, huff->loc[ch]);
        return;
    }

    /* First transmission of this symbol */
    tnode = &(huff->nodeList[huff->blocNode]);
    tnode2 = &(huff->nodeList[huff->blocNode + 1]);
    huff->blocNode += 2;

    tnode2->symbol = INTERNAL_NODE;
    tnode2->weight = 1;
    SET_NEXT(tnode2, NODE_NEXT(huff->lhead));
    if (NODE_NEXT(huff->lhead)) {
        SET_PREV(NODE_NEXT(huff->lhead), tnode2);
        if (NODE_NEXT(huff->lhead)->weight == 1) {
            SET_HEAD(tnode2, NODE_NEXT(huff->lhead)->head);
        } else {
            SET_HEAD(tnode2, get_ppnode(huff));
            *NODE_HEAD(tnode2) = tnode2;
        }
    } else {
        SET_HEAD(tnode2, get_ppnode(huff));
        *NODE_HEAD(tnode2) = tnode2;
    }
    SET_NEXT(huff->lhead, tnode2);
    SET_PREV(tnode2, huff->lhead);

    tnode->symbol = ch;
    tnode->weight = 1;
    SET_NEXT(tnode, NODE_NEXT(huff->lhead));
    if (NODE_NEXT(huff->lhead)) {
        SET_PREV(NODE_NEXT(huff->lhead), tnode);
        if (NODE_NEXT(huff->lhead)->weight == 1) {
            SET_HEAD(tnode, NODE_NEXT(huff->lhead)->head);
        } else {
            SET_HEAD(tnode, get_ppnode(huff));
            *NODE_HEAD(tnode) = tnode;
        }
    } else {
        SET_HEAD(tnode, get_ppnode(huff));
        *NODE_HEAD(tnode) = tnode;
    }
    SET_NEXT(huff->lhead, tnode);
    SET_PREV(tnode, huff->lhead);
    SET_LEFT(tnode, NULL);
    SET_RIGHT(tnode, NULL);

    if (NODE_PARENT(huff->lhead)) {
        if (NODE_LEFT(NODE_PARENT(huff->lhead)) == huff->lhead) {
            SET_LEFT(NODE_PARENT(huff->lhead), tnode2);
        } else {
            SET_RIGHT(NODE_PARENT(huff->lhead), tnode2);
        }
    } else {
        huff->tree = tnode2;
    }

    SET_RIGHT(tnode2, tnode);
    SET_LEFT(tnode2, huff->lhead);

    SET_PARENT(tnode2, NODE_PARENT(huff->lhead));
    SET_PARENT(huff->lhead, tnode2);
    SET_PARENT(tnode, tnode2);

    huff->loc[ch] = tnode;

    increment(huff, NODE_PARENT(tnode2));
}

/* line 409 */
void Huff_offsetTransmit(huff_t *huff, int ch, byte *fout, int *offset)
{
    bloc = *offset;
    huffman_send(huff->loc[ch], NULL, fout);
    *offset = bloc;
}

/* line 526 */
void Huff_Init(huffman_t *huff)
{
    node_t *node;

    Com_Memset(&huff->compressor, 0, sizeof(huff_t));
    Com_Memset(&huff->decompressor, 0, sizeof(huff_t));

    /* Initialize the decompressor tree & list with the NYT node */
    node = &(huff->decompressor.nodeList[huff->decompressor.blocNode++]);
    huff->decompressor.ltail = node;
    huff->decompressor.lhead = node;
    huff->decompressor.loc[NYT] = node;
    huff->decompressor.tree = node;
    node->symbol = NYT;
    node->weight = 0;
    SET_NEXT(node, NULL);
    SET_PREV(node, NULL);
    SET_LEFT(node, NULL);
    SET_RIGHT(node, NULL);
    SET_PARENT(node, NULL);

    /* Initialize the compressor tree & list with the NYT node */
    node = &(huff->compressor.nodeList[huff->compressor.blocNode++]);
    huff->compressor.lhead = node;
    huff->compressor.tree = node;
    node->symbol = NYT;
    node->weight = 0;
    SET_NEXT(node, NULL);
    SET_PREV(node, NULL);
    SET_LEFT(node, NULL);
    SET_RIGHT(node, NULL);
    SET_PARENT(node, NULL);
    huff->compressor.loc[NYT] = node;
}
