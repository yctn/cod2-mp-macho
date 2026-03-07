/* Converted to C from ASM: scr_parsetree.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_parsetree.cpp */

#include "common_types.h"
#include "imports.h"

extern void *Hunk_AllocateTempMemoryHighInternal(int size);

unsigned int node1_(int val1);
unsigned int node_pos(unsigned int pos);
unsigned int node0(int type);
unsigned int node1(int type, unsigned int val1);
unsigned int node2(int type, unsigned int val1, unsigned int val2);
unsigned int node2_(unsigned int val1, unsigned int val2);
unsigned int node3(int type, unsigned int val1, unsigned int val2, unsigned int val3);
unsigned int node4(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4);
unsigned int node5(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5);
unsigned int node6(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5, unsigned int val6);
unsigned int node7(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5, unsigned int val6, unsigned int val7);
unsigned int node8(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5, unsigned int val6, unsigned int val7, unsigned int val8);
unsigned int linked_list_end(unsigned int val);
unsigned int prepend_node(unsigned int val1, unsigned int val2);
unsigned int append_node(unsigned int val1, unsigned int val2);

/* line 26 */
unsigned int node1_(int val1)
{
    return (unsigned int)val1;
}

/* line 35 */
unsigned int node_pos(unsigned int pos)
{
    return pos;
}

/* line 44 */
unsigned int node0(int type)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(4);
    n[0] = type;
    return (unsigned int)n;
}

/* line 54 */
unsigned int node1(int type, unsigned int val1)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    n[0] = type;
    n[1] = (int)val1;
    return (unsigned int)n;
}

/* line 65 */
unsigned int node2(int type, unsigned int val1, unsigned int val2)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(12);
    n[0] = type;
    n[1] = (int)val1;
    n[2] = (int)val2;
    return (unsigned int)n;
}

/* line 77 */
unsigned int node2_(unsigned int val1, unsigned int val2)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    n[0] = (int)val1;
    n[1] = (int)val2;
    return (unsigned int)n;
}

/* line 88 */
unsigned int node3(int type, unsigned int val1, unsigned int val2, unsigned int val3)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(16);
    n[0] = type;
    n[1] = (int)val1;
    n[2] = (int)val2;
    n[3] = (int)val3;
    return (unsigned int)n;
}

/* line 113 */
unsigned int node4(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(20);
    n[0] = type;
    n[1] = (int)val1;
    n[2] = (int)val2;
    n[3] = (int)val3;
    n[4] = (int)val4;
    return (unsigned int)n;
}

/* line 140 */
unsigned int node5(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(24);
    n[0] = type;
    n[1] = (int)val1;
    n[2] = (int)val2;
    n[3] = (int)val3;
    n[4] = (int)val4;
    n[5] = (int)val5;
    return (unsigned int)n;
}

/* line 155 */
unsigned int node6(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5, unsigned int val6)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(28);
    n[0] = type;
    n[1] = (int)val1;
    n[2] = (int)val2;
    n[3] = (int)val3;
    n[4] = (int)val4;
    n[5] = (int)val5;
    n[6] = (int)val6;
    return (unsigned int)n;
}

/* line 171 */
unsigned int node7(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5, unsigned int val6, unsigned int val7)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(32);
    n[0] = type;
    n[1] = (int)val1;
    n[2] = (int)val2;
    n[3] = (int)val3;
    n[4] = (int)val4;
    n[5] = (int)val5;
    n[6] = (int)val6;
    n[7] = (int)val7;
    return (unsigned int)n;
}

/* line 188 */
unsigned int node8(int type, unsigned int val1, unsigned int val2, unsigned int val3, unsigned int val4, unsigned int val5, unsigned int val6, unsigned int val7, unsigned int val8)
{
    int *n = (int *)Hunk_AllocateTempMemoryHighInternal(36);
    n[0] = type;
    n[1] = (int)val1;
    n[2] = (int)val2;
    n[3] = (int)val3;
    n[4] = (int)val4;
    n[5] = (int)val5;
    n[6] = (int)val6;
    n[7] = (int)val7;
    n[8] = (int)val8;
    return (unsigned int)n;
}

/* line 206 */
unsigned int linked_list_end(unsigned int val)
{
    int *node = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    node[0] = (int)val;
    node[1] = 0;
    int *list = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    list[0] = (int)node;
    list[1] = (int)node;
    return (unsigned int)list;
}

/* line 221 */
unsigned int prepend_node(unsigned int val1, unsigned int val2)
{
    int *list = (int *)val2;
    int *newNode = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    newNode[0] = (int)val1;
    newNode[1] = list[0];
    list[0] = (int)newNode;
    return val2;
}

/* line 233 */
unsigned int append_node(unsigned int val1, unsigned int val2)
{
    int *list = (int *)val1;
    int *newNode = (int *)Hunk_AllocateTempMemoryHighInternal(8);
    newNode[0] = (int)val2;
    newNode[1] = 0;
    int *oldTail = (int *)list[1];
    oldTail[1] = (int)newNode;
    list[1] = (int)newNode;
    return val1;
}
