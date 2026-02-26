/* Converted to C from ASM: scr_parsetree.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_parsetree.cpp */

#include "common_types.h"
#include "imports.h"

extern void *Hunk_AllocateTempMemoryHighInternal(int size);

sval_t node1_(int val1);
sval_t node_pos(unsigned int pos);
sval_t node0(int type);
sval_t node1(int type, sval_t val1);
sval_t node2(int type, sval_t val1, sval_t val2);
sval_t node2_(sval_t val1, sval_t val2);
sval_t node3(int type, sval_t val1, sval_t val2, sval_t val3);
sval_t node4(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4);
sval_t node5(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5);
sval_t node6(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5, sval_t val6);
sval_t node7(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5, sval_t val6, sval_t val7);
sval_t node8(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5, sval_t val6, sval_t val7, sval_t val8);
sval_t linked_list_end(sval_t val);
sval_t prepend_node(sval_t val1, sval_t val2);
sval_t append_node(sval_t val1, sval_t val2);

/* line 26 */
sval_t node1_(int val1)
{
    sval_t result;
    result.node = val1;
    return result;
}

/* line 35 */
sval_t node_pos(unsigned int pos)
{
    sval_t result;
    result.sourcePosValue = pos;
    return result;
}

/* line 44 */
sval_t node0(int type)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(4);
    n[0] = type;
    result.node = (int)n;
    return result;
}

/* line 54 */
sval_t node1(int type, sval_t val1)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    n[0] = type;
    n[1] = val1.node;
    result.node = (int)n;
    return result;
}

/* line 65 */
sval_t node2(int type, sval_t val1, sval_t val2)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(12);
    n[0] = type;
    n[1] = val1.node;
    n[2] = val2.node;
    result.node = (int)n;
    return result;
}

/* line 77 */
sval_t node2_(sval_t val1, sval_t val2)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    n[0] = val1.node;
    n[1] = val2.node;
    result.node = (int)n;
    return result;
}

/* line 88 */
sval_t node3(int type, sval_t val1, sval_t val2, sval_t val3)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(16);
    n[0] = type;
    n[1] = val1.node;
    n[2] = val2.node;
    n[3] = val3.node;
    result.node = (int)n;
    return result;
}

/* line 113 */
sval_t node4(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(20);
    n[0] = type;
    n[1] = val1.node;
    n[2] = val2.node;
    n[3] = val3.node;
    n[4] = val4.node;
    result.node = (int)n;
    return result;
}

/* line 140 */
sval_t node5(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(24);
    n[0] = type;
    n[1] = val1.node;
    n[2] = val2.node;
    n[3] = val3.node;
    n[4] = val4.node;
    n[5] = val5.node;
    result.node = (int)n;
    return result;
}

/* line 155 */
sval_t node6(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5, sval_t val6)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(28);
    n[0] = type;
    n[1] = val1.node;
    n[2] = val2.node;
    n[3] = val3.node;
    n[4] = val4.node;
    n[5] = val5.node;
    n[6] = val6.node;
    result.node = (int)n;
    return result;
}

/* line 171 */
sval_t node7(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5, sval_t val6, sval_t val7)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(32);
    n[0] = type;
    n[1] = val1.node;
    n[2] = val2.node;
    n[3] = val3.node;
    n[4] = val4.node;
    n[5] = val5.node;
    n[6] = val6.node;
    n[7] = val7.node;
    result.node = (int)n;
    return result;
}

/* line 188 */
sval_t node8(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5, sval_t val6, sval_t val7, sval_t val8)
{
    sval_t result;
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(36);
    n[0] = type;
    n[1] = val1.node;
    n[2] = val2.node;
    n[3] = val3.node;
    n[4] = val4.node;
    n[5] = val5.node;
    n[6] = val6.node;
    n[7] = val7.node;
    n[8] = val8.node;
    result.node = (int)n;
    return result;
}

/* line 206 */
sval_t linked_list_end(sval_t val)
{
    sval_t result;
    int *node = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    node[0] = val.node;
    node[1] = 0;
    int *list = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    list[0] = (int)node;
    list[1] = (int)node;
    result.node = (int)list;
    return result;
}

/* line 221 */
sval_t prepend_node(sval_t val1, sval_t val2)
{
    int *list = (int *)val2.node;
    int *newNode = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    newNode[0] = val1.node;
    newNode[1] = list[0];
    list[0] = (int)newNode;
    return val2;
}

/* line 233 */
sval_t append_node(sval_t val1, sval_t val2)
{
    int *list = (int *)val1.node;
    int *newNode = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    newNode[0] = val2.node;
    newNode[1] = 0;
    int *oldTail = (int *)list[1];
    oldTail[1] = (int)newNode;
    list[1] = (int)newNode;
    return val1;
}
