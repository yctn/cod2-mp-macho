/* ASM dump from: scr_parsetree.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_parsetree.cpp */

#include "common_types.h"
#include "imports.h"

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
__attribute__((naked))
sval_t node1_(int val1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 26 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* val1 */
        "popl %ebp\n" /* line 32 */
        "retl\n"
    );
}

/* line 35 */
__attribute__((naked))
sval_t node_pos(unsigned int pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 35 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* pos */
        "popl %ebp\n" /* line 41 */
        "retl\n"
    );
}

/* line 44 */
__attribute__((naked))
sval_t node0(int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 44 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $4, (%esp)\n" /* line 48 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 49 | type */
        "movl %edx, (%eax)\n"
        "leave\n" /* line 51 */
        "retl\n"
    );
}

/* line 54 */
__attribute__((naked))
sval_t node1(int type, sval_t val1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 54 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $8, (%esp)\n" /* line 58 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 59 | type */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 60 | val1 */
        "movl %edx, 4(%eax)\n"
        "leave\n" /* line 62 */
        "retl\n"
    );
}

/* line 65 */
__attribute__((naked))
sval_t node2(int type, sval_t val1, sval_t val2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 65 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0xc, (%esp)\n" /* line 69 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 70 | type */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 71 | val1 */
        "movl %edx, 4(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 72 | val2 */
        "movl %edx, 8(%eax)\n"
        "leave\n" /* line 74 */
        "retl\n"
    );
}

/* line 77 */
__attribute__((naked))
sval_t node2_(sval_t val1, sval_t val2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 77 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $8, (%esp)\n" /* line 81 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 82 | val1 */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 83 | val2 */
        "movl %edx, 4(%eax)\n"
        "leave\n" /* line 85 */
        "retl\n"
    );
}

/* line 88 */
__attribute__((naked))
sval_t node3(int type, sval_t val1, sval_t val2, sval_t val3)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x10, (%esp)\n" /* line 92 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 93 | type */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 94 | val1 */
        "movl %edx, 4(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 95 | val2 */
        "movl %edx, 8(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 96 | val3 */
        "movl %edx, 0xc(%eax)\n"
        "leave\n" /* line 98 */
        "retl\n"
    );
}

/* line 113 */
__attribute__((naked))
sval_t node4(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 113 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x14, (%esp)\n" /* line 117 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 118 | type */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 119 | val1 */
        "movl %edx, 4(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 120 | val2 */
        "movl %edx, 8(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 121 | val3 */
        "movl %edx, 0xc(%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 122 | val4 */
        "movl %edx, 0x10(%eax)\n"
        "leave\n" /* line 124 */
        "retl\n"
    );
}

/* line 140 */
__attribute__((naked))
sval_t node5(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 140 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x18, (%esp)\n" /* line 144 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 145 | type */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 146 | val1 */
        "movl %edx, 4(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 147 | val2 */
        "movl %edx, 8(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 148 | val3 */
        "movl %edx, 0xc(%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 149 | val4 */
        "movl %edx, 0x10(%eax)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 150 | val5 */
        "movl %edx, 0x14(%eax)\n"
        "leave\n" /* line 152 */
        "retl\n"
    );
}

/* line 155 */
__attribute__((naked))
sval_t node6(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5, sval_t val6)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 155 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x1c, (%esp)\n" /* line 159 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 160 | type */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 161 | val1 */
        "movl %edx, 4(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 162 | val2 */
        "movl %edx, 8(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 163 | val3 */
        "movl %edx, 0xc(%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 164 | val4 */
        "movl %edx, 0x10(%eax)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 165 | val5 */
        "movl %edx, 0x14(%eax)\n"
        "movl 0x20(%ebp), %edx\n" /* line 166 | val6 */
        "movl %edx, 0x18(%eax)\n"
        "leave\n" /* line 168 */
        "retl\n"
    );
}

/* line 171 */
__attribute__((naked))
sval_t node7(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5, sval_t val6, sval_t val7)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 171 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x20, (%esp)\n" /* line 175 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 176 | type */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 177 | val1 */
        "movl %edx, 4(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 178 | val2 */
        "movl %edx, 8(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 179 | val3 */
        "movl %edx, 0xc(%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 180 | val4 */
        "movl %edx, 0x10(%eax)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 181 | val5 */
        "movl %edx, 0x14(%eax)\n"
        "movl 0x20(%ebp), %edx\n" /* line 182 | val6 */
        "movl %edx, 0x18(%eax)\n"
        "movl 0x24(%ebp), %edx\n" /* line 183 | val7 */
        "movl %edx, 0x1c(%eax)\n"
        "leave\n" /* line 185 */
        "retl\n"
    );
}

/* line 188 */
__attribute__((naked))
sval_t node8(int type, sval_t val1, sval_t val2, sval_t val3, sval_t val4, sval_t val5, sval_t val6, sval_t val7, sval_t val8)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 188 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x24, (%esp)\n" /* line 192 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 193 | type */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 194 | val1 */
        "movl %edx, 4(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 195 | val2 */
        "movl %edx, 8(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 196 | val3 */
        "movl %edx, 0xc(%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 197 | val4 */
        "movl %edx, 0x10(%eax)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 198 | val5 */
        "movl %edx, 0x14(%eax)\n"
        "movl 0x20(%ebp), %edx\n" /* line 199 | val6 */
        "movl %edx, 0x18(%eax)\n"
        "movl 0x24(%ebp), %edx\n" /* line 200 | val7 */
        "movl %edx, 0x1c(%eax)\n"
        "movl 0x28(%ebp), %edx\n" /* line 201 | val8 */
        "movl %edx, 0x20(%eax)\n"
        "leave\n" /* line 203 */
        "retl\n"
    );
}

/* line 206 */
__attribute__((naked))
sval_t linked_list_end(sval_t val)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 206 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $8, (%esp)\n" /* line 211 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %ebx\n"
        "movl 8(%ebp), %eax\n" /* line 212 | val */
        "movl %eax, (%ebx)\n"
        "movl $0, 4(%ebx)\n" /* line 213 */
        "movl $8, (%esp)\n" /* line 214 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %ebx, (%eax)\n" /* line 215 */
        "movl %ebx, 4(%eax)\n" /* line 216 */
        "addl $0x14, %esp\n" /* line 218 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 221 */
__attribute__((naked))
sval_t prepend_node(sval_t val1, sval_t val2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 221 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* val2 */
        "movl $8, (%esp)\n" /* line 225 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 8(%ebp), %edx\n" /* line 226 | val1 */
        "movl %edx, (%eax)\n"
        "movl (%ebx), %edx\n" /* line 227 | val2 */
        "movl %edx, 4(%eax)\n"
        "movl %eax, (%ebx)\n" /* line 228 | val2 */
        "movl %ebx, %eax\n" /* line 230 | val2 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 233 */
__attribute__((naked))
sval_t append_node(sval_t val1, sval_t val2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 233 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* val1 */
        "movl $8, (%esp)\n" /* line 237 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl 0xc(%ebp), %edx\n" /* line 238 | val2 */
        "movl %edx, (%eax)\n"
        "movl $0, 4(%eax)\n" /* line 239 */
        "movl 4(%ebx), %edx\n" /* line 240 | val1 */
        "movl %eax, 4(%edx)\n"
        "movl %eax, 4(%ebx)\n" /* line 241 | val1 */
        "movl %ebx, %eax\n" /* line 243 | val1 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

