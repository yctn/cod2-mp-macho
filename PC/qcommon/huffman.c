/* ASM dump from: huffman.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/huffman.cpp */

#include "common_types.h"
#include "imports.h"

static int bloc; /* 0xf2f600 */

void Huff_Init(huffman_t *huff);
void Huff_offsetReceive(node_t *node, int *ch, byte *fin, int *offset);
static void increment(void);
void Huff_addRef(huff_t *huff, int ch, msg_t *mbuf, int offset);
void huffman_send(node_t *node, node_t *child, byte *fout);
void Huff_offsetTransmit(huff_t *huff, int ch, byte *fout, int *offset);

/* line 526 */
__attribute__((naked))
void Huff_Init(huffman_t *huff)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 526 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* huff */
        "movl $0x701c, 8(%esp)\n" /* line 529 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* huff */
        "calll Com_Memset\n"
        "movl $0x701c, 8(%esp)\n" /* line 530 */
        "movl $0, 4(%esp)\n"
        "leal 0x701c(%ebx), %eax\n" /* huff */
        "movl %eax, (%esp)\n"
        "calll Com_Memset\n"
        "movl 0x701c(%ebx), %edx\n" /* line 533 | huff */
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x7438(%eax, %ebx), %eax\n"
        "movl %eax, 0x7430(%ebx)\n" /* huff */
        "movl %eax, 0x702c(%ebx)\n" /* huff */
        "movl %eax, 0x7028(%ebx)\n" /* huff */
        "movl %eax, 0x7024(%ebx)\n" /* huff */
        "addl $1, %edx\n"
        "movl %edx, 0x701c(%ebx)\n" /* huff */
        "movl $0x100, 0x1c(%eax)\n" /* line 534 */
        "movl 0x7024(%ebx), %eax\n" /* line 535 | huff */
        "movl $0, 0x18(%eax)\n"
        "movl 0x7028(%ebx), %eax\n" /* line 536 | huff */
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl 0x7024(%ebx), %eax\n" /* line 537 | huff */
        "movl $0, 4(%eax)\n"
        "movl $0, (%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl (%ebx), %edx\n" /* line 540 | huff */
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x41c(%eax, %ebx), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* huff */
        "movl %eax, 8(%ebx)\n" /* huff */
        "addl $1, %edx\n"
        "movl %edx, (%ebx)\n" /* huff */
        "movl $0x100, 0x1c(%eax)\n" /* line 541 */
        "movl 8(%ebx), %eax\n" /* line 542 | huff */
        "movl $0, 0x18(%eax)\n"
        "movl 0xc(%ebx), %eax\n" /* line 543 | huff */
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl 8(%ebx), %eax\n" /* line 544 | huff */
        "movl $0, 4(%eax)\n"
        "movl $0, (%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl 8(%ebx), %eax\n" /* line 545 | huff */
        "movl %eax, 0x414(%ebx)\n" /* huff */
        "addl $0x14, %esp\n" /* line 546 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 340 */
__attribute__((naked))
void Huff_offsetReceive(node_t *node, int *ch, byte *fin, int *offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 340 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* node */
        "movl 0x10(%ebp), %esi\n" /* fin */
        "movl 0x14(%ebp), %edi\n" /* offset */
        "movl (%edi), %edx\n" /* line 342 | offset */
        "movl %edx, bloc\n"
        "testl %ebx, %ebx\n" /* line 343 | node */
        "je .Lf18f45a_0018f4c2\n"
        "movl 0x1c(%ebx), %eax\n" /* node */
        "cmpl $0x101, %eax\n"
        "je .Lf18f45a_0018f4a1\n"
        ".Lf18f45a_0018f47f:\n"
        "movl 0xc(%ebp), %edx\n" /* line 360 | ch */
        "movl %eax, (%edx)\n"
        "movl bloc, %eax\n" /* line 361 */
        "movl %eax, (%edi)\n" /* offset */
        "popl %ebx\n" /* line 362 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf18f45a_0018f490:\n"
        "movl 4(%ebx), %ebx\n" /* line 347 | node */
        ".Lf18f45a_0018f493:\n"
        "testl %ebx, %ebx\n" /* line 343 | node */
        "je .Lf18f45a_0018f4bc\n"
        "movl 0x1c(%ebx), %eax\n" /* node */
        "cmpl $0x101, %eax\n"
        "jne .Lf18f45a_0018f4d0\n"
        ".Lf18f45a_0018f4a1:\n"
        "movl %edx, %eax\n" /* line 55 */
        "sarl $3, %eax\n"
        "movzbl (%esi, %eax), %eax\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "addl $1, %edx\n"
        "testb $1, %al\n" /* line 345 */
        "jne .Lf18f45a_0018f490\n"
        "movl (%ebx), %ebx\n" /* line 351 | node */
        "jmp .Lf18f45a_0018f493\n"
        ".Lf18f45a_0018f4bc:\n"
        "movl %edx, bloc\n" /* line 343 */
        ".Lf18f45a_0018f4c2:\n"
        "movl 0xc(%ebp), %eax\n" /* line 356 | ch */
        "movl $0, (%eax)\n"
        "popl %ebx\n" /* line 362 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf18f45a_0018f4d0:\n"
        "movl %edx, bloc\n" /* line 357 */
        "jmp .Lf18f45a_0018f47f\n"
    );
}

/* line 171 */
static __attribute__((naked))
void increment(void)
{
    __asm__ __volatile__ (
        ".Lf18f4d8_0018f4d8:\n"
        "pushl %ebp\n" /* line 171 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl %eax, %edi\n" /* huff */
        "movl %edx, %ebx\n" /* node */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 175 */
        "je .Lf18f4d8_0018f577\n"
        "movl 0xc(%edx), %edx\n" /* line 180 */
        "testl %edx, %edx\n"
        "je .Lf18f4d8_0018f500\n"
        "movl 0x18(%edx), %eax\n"
        "cmpl 0x18(%ebx), %eax\n" /* node */
        "je .Lf18f4d8_0018f5e3\n"
        ".Lf18f4d8_0018f500:\n"
        "movl 0x14(%ebx), %esi\n" /* node */
        "movl 0x10(%ebx), %edx\n" /* node */
        ".Lf18f4d8_0018f506:\n"
        "testl %edx, %edx\n" /* line 189 */
        "je .Lf18f4d8_0018f516\n"
        "movl 0x18(%edx), %eax\n"
        "cmpl 0x18(%ebx), %eax\n" /* node */
        "je .Lf18f4d8_0018f5dc\n"
        ".Lf18f4d8_0018f516:\n"
        "movl $0, (%esi)\n" /* line 195 */
        "movl 0x14(%ebx), %edx\n" /* line 196 | node, ppnode */
        /* { scope 2 */
        "movl 0x418(%edi), %eax\n" /* line 80 */
        "movl %eax, (%edx)\n"
        "movl %edx, 0x418(%edi)\n" /* line 81 */
        /* } scope */
        ".Lf18f4d8_0018f52d:\n"
        "movl 0x18(%ebx), %edx\n" /* line 198 | node */
        "addl $1, %edx\n"
        "movl %edx, 0x18(%ebx)\n" /* node */
        "movl 0xc(%ebx), %eax\n" /* line 199 | node */
        "testl %eax, %eax\n"
        "je .Lf18f4d8_0018f546\n"
        "cmpl 0x18(%eax), %edx\n"
        "je .Lf18f4d8_0018f674\n"
        /* { scope 2 */
        ".Lf18f4d8_0018f546:\n"
        "movl 0x418(%edi), %edx\n" /* line 65 */
        "testl %edx, %edx\n"
        "je .Lf18f4d8_0018f67f\n"
        "movl (%edx), %eax\n" /* line 72 */
        "movl %eax, 0x418(%edi)\n"
        /* } scope */
        ".Lf18f4d8_0018f55c:\n"
        "movl %edx, 0x14(%ebx)\n" /* line 205 | node */
        "movl %ebx, (%edx)\n" /* line 206 | node */
        ".Lf18f4d8_0018f561:\n"
        "movl 8(%ebx), %edx\n" /* line 208 | node */
        "testl %edx, %edx\n"
        "je .Lf18f4d8_0018f577\n"
        "movl %edi, %eax\n" /* line 210 | huff */
        "calll increment\n"
        "movl 0x10(%ebx), %ecx\n" /* line 211 | node */
        "cmpl 8(%ebx), %ecx\n" /* node */
        "je .Lf18f4d8_0018f57f\n"
        /* } scope */
        ".Lf18f4d8_0018f577:\n"
        "addl $0xc, %esp\n" /* line 220 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf18f4d8_0018f57f:\n"
        "movl 0xc(%ebx), %eax\n" /* line 135 */
        "movl 0xc(%ecx), %edx\n" /* line 136 */
        "movl %edx, 0xc(%ebx)\n"
        "movl %eax, 0xc(%ecx)\n" /* line 137 */
        "movl 0x10(%ecx), %eax\n" /* line 140 */
        "movl %eax, 0x10(%ebx)\n"
        "movl %ecx, 0x10(%ecx)\n" /* line 141 */
        "cmpl 0xc(%ebx), %ebx\n" /* line 143 */
        "je .Lf18f4d8_0018f69c\n"
        ".Lf18f4d8_0018f59d:\n"
        "cmpl 0xc(%ecx), %ecx\n" /* line 147 */
        "je .Lf18f4d8_0018f694\n"
        ".Lf18f4d8_0018f5a6:\n"
        "movl 0xc(%ebx), %eax\n" /* line 151 */
        "testl %eax, %eax\n"
        "je .Lf18f4d8_0018f5b0\n"
        "movl %ebx, 0x10(%eax)\n" /* line 153 */
        ".Lf18f4d8_0018f5b0:\n"
        "movl 0xc(%ecx), %eax\n" /* line 155 */
        "testl %eax, %eax\n"
        "je .Lf18f4d8_0018f5ba\n"
        "movl %ecx, 0x10(%eax)\n" /* line 157 */
        ".Lf18f4d8_0018f5ba:\n"
        "movl 0x10(%ebx), %eax\n" /* line 159 */
        "testl %eax, %eax\n"
        "je .Lf18f4d8_0018f5c4\n"
        "movl %ebx, 0xc(%eax)\n" /* line 161 */
        ".Lf18f4d8_0018f5c4:\n"
        "movl 0x10(%ecx), %eax\n" /* line 163 */
        "testl %eax, %eax\n"
        "je .Lf18f4d8_0018f5ce\n"
        "movl %ecx, 0xc(%eax)\n" /* line 165 */
        /* } scope */
        ".Lf18f4d8_0018f5ce:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 214 | node */
        "cmpl (%ecx), %ebx\n" /* node */
        "jne .Lf18f4d8_0018f577\n"
        "movl 8(%ebx), %eax\n" /* line 216 | node */
        "movl %eax, (%ecx)\n"
        "jmp .Lf18f4d8_0018f577\n"
        ".Lf18f4d8_0018f5dc:\n"
        "movl %edx, (%esi)\n" /* line 191 */
        "jmp .Lf18f4d8_0018f52d\n"
        ".Lf18f4d8_0018f5e3:\n"
        "movl 0x14(%ebx), %esi\n" /* line 182 | node */
        "movl (%esi), %ecx\n"
        "movl 8(%ebx), %eax\n" /* line 183 | node */
        "cmpl %eax, %ecx\n"
        "je .Lf18f4d8_0018f624\n"
        /* { scope 2 */
        "movl 8(%ecx), %edx\n" /* line 90 */
        "testl %edx, %edx\n" /* line 93 */
        "je .Lf18f4d8_0018f6ae\n"
        "cmpl (%edx), %ecx\n" /* line 95 */
        "je .Lf18f4d8_0018f6c5\n"
        "movl %ebx, 4(%edx)\n" /* line 101 */
        ".Lf18f4d8_0018f605:\n"
        "testl %eax, %eax\n" /* line 109 */
        "je .Lf18f4d8_0018f6b6\n"
        "cmpl (%eax), %ebx\n" /* line 111 */
        "je .Lf18f4d8_0018f6be\n"
        "movl %ecx, 4(%eax)\n" /* line 117 */
        ".Lf18f4d8_0018f618:\n"
        "movl %eax, 8(%ecx)\n" /* line 125 */
        "movl %edx, 8(%ebx)\n" /* line 126 */
        "movl 0xc(%ebx), %edx\n"
        "movl 0x14(%ebx), %esi\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18f4d8_0018f624:\n"
        "movl 0xc(%ecx), %eax\n" /* line 135 */
        "movl %edx, 0xc(%ecx)\n" /* line 136 */
        "movl %eax, 0xc(%ebx)\n" /* line 137 */
        "movl 0x10(%ecx), %edx\n" /* line 139 */
        "movl 0x10(%ebx), %eax\n" /* line 140 */
        "movl %eax, 0x10(%ecx)\n"
        "movl %edx, 0x10(%ebx)\n" /* line 141 */
        "cmpl 0xc(%ecx), %ecx\n" /* line 143 */
        "je .Lf18f4d8_0018f6a9\n"
        ".Lf18f4d8_0018f63e:\n"
        "cmpl 0xc(%ebx), %ebx\n" /* line 147 */
        "je .Lf18f4d8_0018f6a4\n"
        ".Lf18f4d8_0018f643:\n"
        "movl 0xc(%ecx), %eax\n" /* line 151 */
        "testl %eax, %eax\n"
        "je .Lf18f4d8_0018f64d\n"
        "movl %ecx, 0x10(%eax)\n" /* line 153 */
        ".Lf18f4d8_0018f64d:\n"
        "movl 0xc(%ebx), %eax\n" /* line 155 */
        "testl %eax, %eax\n"
        "je .Lf18f4d8_0018f657\n"
        "movl %ebx, 0x10(%eax)\n" /* line 157 */
        ".Lf18f4d8_0018f657:\n"
        "movl 0x10(%ecx), %eax\n" /* line 159 */
        "testl %eax, %eax\n"
        "je .Lf18f4d8_0018f661\n"
        "movl %ecx, 0xc(%eax)\n" /* line 161 */
        ".Lf18f4d8_0018f661:\n"
        "movl 0x10(%ebx), %edx\n" /* line 163 */
        "testl %edx, %edx\n"
        "je .Lf18f4d8_0018f516\n"
        "movl %ebx, 0xc(%edx)\n" /* line 165 */
        "jmp .Lf18f4d8_0018f506\n"
        /* } scope */
        ".Lf18f4d8_0018f674:\n"
        "movl 0x14(%eax), %esi\n" /* line 201 */
        "movl %esi, 0x14(%ebx)\n" /* node */
        "jmp .Lf18f4d8_0018f561\n"
        /* { scope 2 */
        ".Lf18f4d8_0018f67f:\n"
        "movl 4(%edi), %eax\n" /* line 67 */
        "leal 0x641c(%edi, %eax, 4), %edx\n"
        "addl $1, %eax\n"
        "movl %eax, 4(%edi)\n"
        "jmp .Lf18f4d8_0018f55c\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18f4d8_0018f694:\n"
        "movl %ebx, 0xc(%ecx)\n" /* line 149 */
        "jmp .Lf18f4d8_0018f5a6\n"
        ".Lf18f4d8_0018f69c:\n"
        "movl %ecx, 0xc(%ebx)\n" /* line 145 */
        "jmp .Lf18f4d8_0018f59d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18f4d8_0018f6a4:\n"
        "movl %ecx, 0xc(%ebx)\n" /* line 149 */
        "jmp .Lf18f4d8_0018f643\n"
        ".Lf18f4d8_0018f6a9:\n"
        "movl %ebx, 0xc(%ecx)\n" /* line 145 */
        "jmp .Lf18f4d8_0018f63e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18f4d8_0018f6ae:\n"
        "movl %ebx, 8(%edi)\n" /* line 106 */
        "jmp .Lf18f4d8_0018f605\n"
        ".Lf18f4d8_0018f6b6:\n"
        "movl %ecx, 8(%edi)\n" /* line 122 */
        "jmp .Lf18f4d8_0018f618\n"
        ".Lf18f4d8_0018f6be:\n"
        "movl %ecx, (%eax)\n" /* line 113 */
        "jmp .Lf18f4d8_0018f618\n"
        ".Lf18f4d8_0018f6c5:\n"
        "movl %ebx, (%edx)\n" /* line 97 */
        "jmp .Lf18f4d8_0018f605\n"
    );
}

/* line 223 */
__attribute__((naked))
void Huff_addRef(huff_t *huff, int ch, msg_t *mbuf, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 223 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* huff */
        /* { scope 1 */
        "movzbl 0xc(%ebp), %edi\n" /* line 227 | ch */
        "movl 0x14(%ecx, %edi, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf18f6cc_0018f6ec\n"
        "movl %ecx, %eax\n" /* line 311 */
        /* } scope */
        "popl %ebx\n" /* line 313 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp increment\n" /* line 311 */
        ".Lf18f6cc_0018f6ec:\n"
        "movl (%ecx), %eax\n" /* line 229 */
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "leal 0x41c(%edx, %ecx), %esi\n" /* tnode */
        "leal 0x43c(%edx, %ecx), %ebx\n" /* line 230 | tnode2 */
        "addl $2, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl $0x101, 0x1c(%ebx)\n" /* line 232 | tnode2 */
        "movl $1, 0x18(%ebx)\n" /* line 233 | tnode2 */
        "movl 0xc(%ecx), %eax\n" /* line 234 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* tnode2 */
        "movl 0xc(%ecx), %eax\n" /* line 235 */
        "movl 0xc(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18f6cc_0018f73a\n"
        "movl %ebx, 0x10(%eax)\n" /* line 237 | tnode2 */
        "movl 0xc(%ecx), %eax\n" /* line 238 */
        "movl 0xc(%eax), %eax\n"
        "cmpl $1, 0x18(%eax)\n"
        "je .Lf18f6cc_0018f80a\n"
        /* { scope 2 */
        ".Lf18f6cc_0018f73a:\n"
        "movl 0x418(%ecx), %edx\n" /* line 65 */
        "testl %edx, %edx\n"
        "je .Lf18f6cc_0018f83a\n"
        "movl (%edx), %eax\n" /* line 72 */
        "movl %eax, 0x418(%ecx)\n"
        /* } scope */
        ".Lf18f6cc_0018f750:\n"
        "movl %edx, 0x14(%ebx)\n" /* line 250 | tnode2 */
        "movl %ebx, (%edx)\n" /* line 251 | tnode2 */
        ".Lf18f6cc_0018f755:\n"
        "movl 0xc(%ecx), %eax\n" /* line 253 */
        "movl %ebx, 0xc(%eax)\n" /* tnode2 */
        "movl 0xc(%ecx), %eax\n" /* line 254 */
        "movl %eax, 0x10(%ebx)\n" /* tnode2 */
        "movl %edi, 0x1c(%esi)\n" /* line 256 | tnode */
        "movl $1, 0x18(%esi)\n" /* line 257 | tnode */
        "movl 0xc(%ecx), %eax\n" /* line 258 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0xc(%esi)\n" /* tnode */
        "movl 0xc(%ecx), %eax\n" /* line 259 */
        "movl 0xc(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18f6cc_0018f815\n"
        "movl %esi, 0x10(%eax)\n" /* line 261 | tnode */
        "movl 0xc(%ecx), %eax\n" /* line 262 */
        "movl 0xc(%eax), %eax\n"
        "cmpl $1, 0x18(%eax)\n"
        "je .Lf18f6cc_0018f802\n"
        /* { scope 2 */
        "movl 0x418(%ecx), %edx\n" /* line 65 */
        "testl %edx, %edx\n"
        "je .Lf18f6cc_0018f84f\n"
        "movl (%edx), %eax\n" /* line 72 */
        "movl %eax, 0x418(%ecx)\n"
        /* } scope */
        ".Lf18f6cc_0018f7a7:\n"
        "movl %edx, 0x14(%esi)\n" /* line 269 | tnode */
        "movl %ebx, (%edx)\n" /* line 270 | tnode2 */
        ".Lf18f6cc_0018f7ac:\n"
        "movl 0xc(%ecx), %eax\n" /* line 279 */
        "movl %esi, 0xc(%eax)\n" /* tnode */
        "movl 0xc(%ecx), %eax\n" /* line 280 */
        "movl %eax, 0x10(%esi)\n" /* tnode */
        "movl $0, 4(%esi)\n" /* line 281 | tnode */
        "movl $0, (%esi)\n" /* tnode */
        "movl 0xc(%ecx), %edx\n" /* line 283 */
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18f6cc_0018f831\n"
        "cmpl (%eax), %edx\n" /* line 285 */
        "je .Lf18f6cc_0018f836\n"
        "movl %ebx, 4(%eax)\n" /* line 291 | tnode2 */
        ".Lf18f6cc_0018f7d6:\n"
        "movl %esi, 4(%ebx)\n" /* line 299 | tnode, tnode2 */
        "movl 0xc(%ecx), %eax\n" /* line 300 */
        "movl %eax, (%ebx)\n" /* tnode2 */
        "movl 0xc(%ecx), %eax\n" /* line 302 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%ebx)\n" /* tnode2 */
        "movl 0xc(%ecx), %eax\n" /* line 303 */
        "movl %ebx, 8(%esi)\n" /* tnode2, tnode */
        "movl %ebx, 8(%eax)\n" /* tnode2 */
        "movl %esi, 0x14(%ecx, %edi, 4)\n" /* line 305 | tnode */
        "movl 8(%ebx), %edx\n" /* line 307 | tnode2 */
        "movl %ecx, %eax\n" /* line 311 */
        /* } scope */
        "popl %ebx\n" /* line 313 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp increment\n" /* line 311 */
        ".Lf18f6cc_0018f802:\n"
        "movl 0x14(%eax), %eax\n" /* line 264 */
        "movl %eax, 0x14(%esi)\n" /* tnode */
        "jmp .Lf18f6cc_0018f7ac\n"
        ".Lf18f6cc_0018f80a:\n"
        "movl 0x14(%eax), %eax\n" /* line 240 */
        "movl %eax, 0x14(%ebx)\n" /* tnode2 */
        "jmp .Lf18f6cc_0018f755\n"
        /* { scope 2 */
        ".Lf18f6cc_0018f815:\n"
        "movl 0x418(%ecx), %edx\n" /* line 65 */
        "testl %edx, %edx\n"
        "je .Lf18f6cc_0018f864\n"
        "movl (%edx), %eax\n" /* line 72 */
        "movl %eax, 0x418(%ecx)\n"
        /* } scope */
        "movl %edx, 0x14(%esi)\n" /* line 276 | tnode */
        "movl %esi, (%edx)\n" /* line 277 | tnode */
        "jmp .Lf18f6cc_0018f7ac\n"
        ".Lf18f6cc_0018f831:\n"
        "movl %ebx, 8(%ecx)\n" /* line 296 | tnode2 */
        "jmp .Lf18f6cc_0018f7d6\n"
        ".Lf18f6cc_0018f836:\n"
        "movl %ebx, (%eax)\n" /* line 287 | tnode2 */
        "jmp .Lf18f6cc_0018f7d6\n"
        /* { scope 2 */
        ".Lf18f6cc_0018f83a:\n"
        "movl 4(%ecx), %eax\n" /* line 67 */
        "leal 0x641c(%ecx, %eax, 4), %edx\n"
        "addl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "jmp .Lf18f6cc_0018f750\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18f6cc_0018f84f:\n"
        "movl 4(%ecx), %eax\n"
        "leal 0x641c(%ecx, %eax, 4), %edx\n"
        "addl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "jmp .Lf18f6cc_0018f7a7\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18f6cc_0018f864:\n"
        "movl 4(%ecx), %eax\n"
        "leal 0x641c(%ecx, %eax, 4), %edx\n"
        "addl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        /* } scope */
        "movl %edx, 0x14(%esi)\n" /* line 276 | tnode */
        "movl %esi, (%edx)\n" /* line 277 | tnode */
        "jmp .Lf18f6cc_0018f7ac\n"
        "addb %al, (%eax)\n"
        /* } scope */
        ".Lf18f6cc_0018f880:\n"
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %eax\n" /* huff */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "testl %eax, %eax\n"
        "je 0x18fa66\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "testl %edx, %edx\n"
        "je 0x18fa38\n"
        "movl 8(%edx), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "testl %ecx, %ecx\n"
        "je 0x18fa0a\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* huff_large_local */
        "testl %eax, %eax\n"
        "je 0x18f9dc\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* seq_large_local */
        "testl %edx, %edx\n"
        "je 0x18f9ae\n"
        "movl 8(%edx), %edi\n"
        "testl %edi, %edi\n"
        "je 0x18f980\n"
        "movl 8(%edi), %esi\n" /* tnode */
        "testl %esi, %esi\n" /* tnode */
        "je .Lf18f6cc_0018f955\n"
        "movl 8(%esi), %ebx\n" /* tnode, tnode2 */
        "testl %ebx, %ebx\n" /* tnode2 */
        "je .Lf18f6cc_0018f92d\n"
        "movl 8(%ebx), %eax\n" /* tnode2 */
        "testl %eax, %eax\n"
        "je .Lf18f6cc_0018f905\n"
        "movl 0x10(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* tnode2 */
        "movl %eax, (%esp)\n"
        "calll huffman_send\n"
        ".Lf18f6cc_0018f905:\n"
        "cmpl 4(%ebx), %esi\n" /* tnode2, tnode */
        "je 0x18fccb\n"
        "movl bloc, %edx\n"
        "testb $7, %dl\n"
        "jne .Lf18f6cc_0018f925\n"
        "movl %edx, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n"
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f6cc_0018f925:\n"
        "leal 1(%edx), %eax\n"
        "movl %eax, bloc\n"
        ".Lf18f6cc_0018f92d:\n"
        "cmpl 4(%esi), %edi\n" /* tnode */
        "je 0x18fc62\n"
        "movl bloc, %edx\n"
        "testb $7, %dl\n"
        "jne .Lf18f6cc_0018f94d\n"
        "movl %edx, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n"
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f6cc_0018f94d:\n"
        "leal 1(%edx), %eax\n"
        "movl %eax, bloc\n"
        ".Lf18f6cc_0018f955:\n"
        "movl -0x1c(%ebp), %eax\n" /* seq_large_local */
        "cmpl 4(%edi), %eax\n"
        "je 0x18fc1d\n"
        "movl bloc, %edx\n"
        "testb $7, %dl\n"
        "jne 0x18f978\n"
        "movl %edx, %eax\n"
    );
}

/* line 366 */
__attribute__((naked))
void huffman_send(node_t *node, node_t *child, byte *fout)
{
    __asm__ __volatile__ (
        ".Lf18f880_0018f880:\n"
        "pushl %ebp\n" /* line 366 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 368 | node */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf18f880_0018fa66\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "testl %edx, %edx\n"
        "je .Lf18f880_0018fa38\n"
        "movl 8(%edx), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "testl %ecx, %ecx\n"
        "je .Lf18f880_0018fa0a\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf18f880_0018f9dc\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "testl %edx, %edx\n"
        "je .Lf18f880_0018f9ae\n"
        "movl 8(%edx), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf18f880_0018f980\n"
        "movl 8(%edi), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf18f880_0018f955\n"
        "movl 8(%esi), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf18f880_0018f92d\n"
        "movl 8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18f880_0018f905\n"
        "movl 0x10(%ebp), %ecx\n" /* line 370 | fout */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll huffman_send\n"
        ".Lf18f880_0018f905:\n"
        "cmpl 4(%ebx), %esi\n" /* line 374 */
        "je .Lf18f880_0018fccb\n"
        "movl bloc, %edx\n" /* line 41 */
        "testb $7, %dl\n"
        "jne .Lf18f880_0018f925\n"
        "movl %edx, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* fout */
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f880_0018f925:\n"
        "leal 1(%edx), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        ".Lf18f880_0018f92d:\n"
        "cmpl 4(%esi), %edi\n" /* line 374 */
        "je .Lf18f880_0018fc62\n"
        "movl bloc, %edx\n" /* line 41 */
        "testb $7, %dl\n"
        "jne .Lf18f880_0018f94d\n"
        "movl %edx, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* fout */
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f880_0018f94d:\n"
        "leal 1(%edx), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        ".Lf18f880_0018f955:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 374 */
        "cmpl 4(%edi), %eax\n"
        "je .Lf18f880_0018fc1d\n"
        "movl bloc, %edx\n" /* line 41 */
        "testb $7, %dl\n"
        "jne .Lf18f880_0018f978\n"
        "movl %edx, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* fout */
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f880_0018f978:\n"
        "leal 1(%edx), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        ".Lf18f880_0018f980:\n"
        "movl -0x20(%ebp), %edx\n" /* line 374 */
        "movl -0x1c(%ebp), %eax\n"
        "cmpl 4(%eax), %edx\n"
        "je .Lf18f880_0018fbd8\n"
        "movl bloc, %edx\n" /* line 41 */
        "testb $7, %dl\n"
        "jne .Lf18f880_0018f9a6\n"
        "movl %edx, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* fout */
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f880_0018f9a6:\n"
        "leal 1(%edx), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        ".Lf18f880_0018f9ae:\n"
        "movl -0x24(%ebp), %edx\n" /* line 374 */
        "movl -0x20(%ebp), %eax\n"
        "cmpl 4(%eax), %edx\n"
        "je .Lf18f880_0018fb93\n"
        "movl bloc, %edx\n" /* line 41 */
        "testb $7, %dl\n"
        "jne .Lf18f880_0018f9d4\n"
        "movl %edx, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* fout */
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f880_0018f9d4:\n"
        "leal 1(%edx), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        ".Lf18f880_0018f9dc:\n"
        "movl -0x28(%ebp), %edx\n" /* line 374 */
        "movl -0x24(%ebp), %eax\n"
        "cmpl 4(%eax), %edx\n"
        "je .Lf18f880_0018faa5\n"
        "movl bloc, %edx\n" /* line 41 */
        "testb $7, %dl\n"
        "jne .Lf18f880_0018fa02\n"
        "movl %edx, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* fout */
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f880_0018fa02:\n"
        "leal 1(%edx), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        ".Lf18f880_0018fa0a:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 374 */
        "movl -0x28(%ebp), %eax\n"
        "cmpl 4(%eax), %edx\n"
        "je .Lf18f880_0018fae2\n"
        ".Lf18f880_0018fa19:\n"
        "movl bloc, %edx\n" /* line 41 */
        "testb $7, %dl\n"
        "jne .Lf18f880_0018fa30\n"
        "movl %edx, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* fout */
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f880_0018fa30:\n"
        "leal 1(%edx), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        ".Lf18f880_0018fa38:\n"
        "movl 8(%ebp), %edx\n" /* line 374 | node */
        "movl -0x2c(%ebp), %eax\n"
        "cmpl 4(%eax), %edx\n"
        "je .Lf18f880_0018fb1f\n"
        ".Lf18f880_0018fa47:\n"
        "movl bloc, %edx\n" /* line 41 */
        "testb $7, %dl\n"
        "jne .Lf18f880_0018fa5e\n"
        "movl %edx, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* fout */
        "movb $0, (%ecx, %eax)\n"
        ".Lf18f880_0018fa5e:\n"
        "leal 1(%edx), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        ".Lf18f880_0018fa66:\n"
        "movl 0xc(%ebp), %eax\n" /* line 372 | child */
        "testl %eax, %eax\n"
        "je .Lf18f880_0018fa8f\n"
        "movl 0xc(%ebp), %edx\n" /* line 374 | child */
        "movl 8(%ebp), %eax\n" /* node */
        "cmpl 4(%eax), %edx\n"
        "je .Lf18f880_0018fb52\n"
        "movl bloc, %edx\n" /* line 41 */
        "testb $7, %dl\n"
        "je .Lf18f880_0018fa97\n"
        ".Lf18f880_0018fa87:\n"
        "leal 1(%edx), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        ".Lf18f880_0018fa8f:\n"
        "addl $0x4c, %esp\n" /* line 383 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf18f880_0018fa97:\n"
        "movl %edx, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* fout */
        "movb $0, (%ecx, %eax)\n"
        "jmp .Lf18f880_0018fa87\n"
        ".Lf18f880_0018faa5:\n"
        "movl bloc, %esi\n" /* line 41 */
        "movl %esi, %ebx\n"
        "andl $7, %ebx\n"
        "je .Lf18f880_0018fc50\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        ".Lf18f880_0018fac0:\n"
        "movl $1, %eax\n" /* line 45 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "leal 1(%esi), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        "movl -0x2c(%ebp), %edx\n" /* line 374 */
        "movl -0x28(%ebp), %eax\n"
        "cmpl 4(%eax), %edx\n"
        "jne .Lf18f880_0018fa19\n"
        ".Lf18f880_0018fae2:\n"
        "movl bloc, %esi\n" /* line 41 */
        "movl %esi, %ebx\n"
        "andl $7, %ebx\n"
        "je .Lf18f880_0018fc0b\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        ".Lf18f880_0018fafd:\n"
        "movl $1, %eax\n" /* line 45 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "leal 1(%esi), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        "movl 8(%ebp), %edx\n" /* line 374 | node */
        "movl -0x2c(%ebp), %eax\n"
        "cmpl 4(%eax), %edx\n"
        "jne .Lf18f880_0018fa47\n"
        ".Lf18f880_0018fb1f:\n"
        "movl bloc, %esi\n" /* line 41 */
        "movl %esi, %ebx\n"
        "andl $7, %ebx\n"
        "je .Lf18f880_0018fbc6\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        ".Lf18f880_0018fb3a:\n"
        "movl $1, %eax\n" /* line 45 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "leal 1(%esi), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        "jmp .Lf18f880_0018fa66\n"
        ".Lf18f880_0018fb52:\n"
        "movl bloc, %esi\n" /* line 41 */
        "movl %esi, %ebx\n"
        "andl $7, %ebx\n"
        "je .Lf18f880_0018fb84\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        ".Lf18f880_0018fb69:\n"
        "movl $1, %eax\n" /* line 45 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "leal 1(%esi), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        "addl $0x4c, %esp\n" /* line 383 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf18f880_0018fb84:\n"
        "movl %esi, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        "movb $0, (%edx)\n"
        "jmp .Lf18f880_0018fb69\n"
        ".Lf18f880_0018fb93:\n"
        "movl bloc, %esi\n" /* line 41 */
        "movl %esi, %ebx\n"
        "andl $7, %ebx\n"
        "je .Lf18f880_0018fc95\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        ".Lf18f880_0018fbae:\n"
        "movl $1, %eax\n" /* line 45 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "leal 1(%esi), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        "jmp .Lf18f880_0018f9dc\n"
        ".Lf18f880_0018fbc6:\n"
        "movl %esi, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        "movb $0, (%edx)\n"
        "jmp .Lf18f880_0018fb3a\n"
        ".Lf18f880_0018fbd8:\n"
        "movl bloc, %esi\n" /* line 41 */
        "movl %esi, %ebx\n"
        "andl $7, %ebx\n"
        "je .Lf18f880_0018fca7\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        ".Lf18f880_0018fbf3:\n"
        "movl $1, %eax\n" /* line 45 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "leal 1(%esi), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        "jmp .Lf18f880_0018f9ae\n"
        ".Lf18f880_0018fc0b:\n"
        "movl %esi, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        "movb $0, (%edx)\n"
        "jmp .Lf18f880_0018fafd\n"
        ".Lf18f880_0018fc1d:\n"
        "movl bloc, %esi\n" /* line 41 */
        "movl %esi, %ebx\n"
        "andl $7, %ebx\n"
        "je .Lf18f880_0018fcb9\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        ".Lf18f880_0018fc38:\n"
        "movl $1, %eax\n" /* line 45 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "leal 1(%esi), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        "jmp .Lf18f880_0018f980\n"
        ".Lf18f880_0018fc50:\n"
        "movl %esi, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        "movb $0, (%edx)\n"
        "jmp .Lf18f880_0018fac0\n"
        ".Lf18f880_0018fc62:\n"
        "movl bloc, %esi\n" /* line 41 */
        "movl %esi, %ebx\n"
        "andl $7, %ebx\n"
        "je .Lf18f880_0018fcfd\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        ".Lf18f880_0018fc7d:\n"
        "movl $1, %eax\n" /* line 45 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "leal 1(%esi), %eax\n" /* line 46 */
        "movl %eax, bloc\n"
        "jmp .Lf18f880_0018f955\n"
        ".Lf18f880_0018fc95:\n"
        "movl %esi, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        "movb $0, (%edx)\n"
        "jmp .Lf18f880_0018fbae\n"
        ".Lf18f880_0018fca7:\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        "movb $0, (%edx)\n"
        "jmp .Lf18f880_0018fbf3\n"
        ".Lf18f880_0018fcb9:\n"
        "movl %esi, %eax\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        "movb $0, (%edx)\n"
        "jmp .Lf18f880_0018fc38\n"
        ".Lf18f880_0018fccb:\n"
        "movl bloc, %eax\n" /* line 41 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, %ebx\n"
        "andl $7, %ebx\n"
        "je .Lf18f880_0018fd0f\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        ".Lf18f880_0018fce2:\n"
        "movl $1, %eax\n" /* line 45 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 46 */
        "addl $1, %eax\n"
        "movl %eax, bloc\n"
        "jmp .Lf18f880_0018f92d\n"
        ".Lf18f880_0018fcfd:\n"
        "movl %esi, %eax\n" /* line 43 */
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        "movb $0, (%edx)\n"
        "jmp .Lf18f880_0018fc7d\n"
        ".Lf18f880_0018fd0f:\n"
        "sarl $3, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* fout */
        "addl %eax, %edx\n"
        "movb $0, (%edx)\n"
        "jmp .Lf18f880_0018fce2\n"
    );
}

/* line 409 */
__attribute__((naked))
void Huff_offsetTransmit(huff_t *huff, int ch, byte *fout, int *offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 409 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x14(%ebp), %ebx\n" /* offset */
        "movl (%ebx), %eax\n" /* line 411 | offset */
        "movl %eax, bloc\n"
        "movl 0xc(%ebp), %edx\n" /* line 412 | ch, node */
        "movl 8(%ebp), %eax\n" /* huff */
        "movl 0x14(%eax, %edx, 4), %edx\n" /* node */
        /* { scope 1 */
        "movl 8(%edx), %eax\n" /* line 368 */
        "testl %eax, %eax\n"
        "je .Lf18fd1c_0018fd51\n"
        "movl 0x10(%ebp), %ecx\n" /* line 370 | fout */
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll huffman_send\n"
        /* } scope */
        ".Lf18fd1c_0018fd51:\n"
        "movl bloc, %eax\n" /* line 413 */
        "movl %eax, (%ebx)\n" /* offset */
        "addl $0x14, %esp\n" /* line 414 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

