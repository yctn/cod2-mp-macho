/* ASM dump from: xanim_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/xanim_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/consumedata.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

static void ConsumeQuat(void);
XAnimParts * XAnimLoadFile(const char *name, Alloc_t Alloc);

/* line 15 */
static __attribute__((naked))
void ConsumeQuat(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 15 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl %edx, %esi\n" /* out */
        /* { scope 1: u */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 104 | pos */
        "movzwl (%edx), %ecx\n"
        "movw %cx, -0xa(%ebp)\n" /* u */
        "addl $2, %edx\n" /* line 105 */
        "movl %edx, (%eax)\n" /* pos */
        /* } scope */
        "movw %cx, (%esi)\n" /* line 20 | out */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 104 | pos */
        "movzwl (%edx), %ecx\n"
        "movw %cx, -0xa(%ebp)\n" /* u */
        "addl $2, %edx\n" /* line 105 */
        "movl %edx, (%eax)\n" /* pos */
        /* } scope */
        "movw %cx, 2(%esi)\n" /* line 21 | out */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 104 | pos */
        "movzwl (%edx), %ecx\n"
        "movw %cx, -0xa(%ebp)\n" /* u */
        "addl $2, %edx\n" /* line 105 */
        "movl %edx, (%eax)\n" /* pos */
        "movswl %cx, %ebx\n" /* line 106 */
        /* } scope */
        "movw %cx, 4(%esi)\n" /* line 22 | out */
        "movswl (%esi), %eax\n" /* line 24 | out, pos */
        "movswl 2(%esi), %edx\n" /* line 25 | out */
        "imull %eax, %eax\n" /* line 28 | pos */
        "imull %edx, %edx\n"
        "addl %edx, %eax\n" /* pos */
        "imull %ebx, %ebx\n"
        "addl %ebx, %eax\n" /* pos */
        "movl $0x3fff0001, %edx\n"
        "subl %eax, %edx\n" /* pos */
        "testl %edx, %edx\n" /* line 30 */
        "jle .Lfba818_000ba8a6\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 81 */
        "sqrtss %xmm0, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n" /* pos */
        "movw %ax, 6(%esi)\n" /* line 33 | pos, out */
        /* } scope */
        "addl $0x30, %esp\n" /* line 34 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: u */
        ".Lfba818_000ba8a6:\n"
        "xorl %eax, %eax\n" /* line 30 | pos */
        "movw %ax, 6(%esi)\n" /* line 33 | pos, out */
        /* } scope */
        "addl $0x30, %esp\n" /* line 34 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 90 */
__attribute__((naked))
XAnimParts * XAnimLoadFile(const char *name, Alloc_t Alloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10c, %esp\n"
        "movl 8(%ebp), %esi\n" /* name */
        /* { scope 1: u, i */
        "movl %esi, 0xc(%esp)\n" /* line 125 | sQ2 */
        "movl $0x21fd18, 8(%esp)\n" /* "xanim/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x6c(%ebp), %ebx\n" /* filename, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll Com_sprintf\n"
        "testl %eax, %eax\n"
        "js .Lfba8b4_000bb85c\n"
        "leal -0x20(%ebp), %eax\n" /* line 131 | buf */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll FS_ReadFile\n"
        "cmpl $0, %eax\n" /* line 133 */
        "jl .Lfba8b4_000bba37\n"
        "je .Lfba8b4_000bb7b4\n" /* line 140 */
        "movl -0x20(%ebp), %eax\n" /* line 149 | buf */
        "movl %eax, -0xe8(%ebp)\n"
        "movl %eax, %edx\n"
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        /* { scope 2: u */
        "movl %eax, %ecx\n" /* line 104 */
        "movzwl (%eax), %eax\n"
        "movw %ax, -0x24(%ebp)\n" /* u */
        "addl $2, %ecx\n" /* line 105 */
        "movl %ecx, -0x1c(%ebp)\n" /* pos */
        "movswl %ax, %ebx\n" /* line 106 | notify */
        /* } scope */
        "cmpw $0xe, %ax\n" /* line 151 */
        "jne .Lfba8b4_000bb3da\n"
        /* { scope 2: u */
        "movzwl 2(%edx), %ebx\n" /* line 104 | notify */
        "movw %bx, -0xc8(%ebp)\n" /* notify */
        "movw %bx, -0x24(%ebp)\n" /* notify, u */
        "leal 4(%edx), %edi\n" /* line 105 */
        "movl %edi, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        /* { scope 2: u */
        "movzwl 4(%edx), %eax\n" /* line 104 */
        "movw %ax, -0xca(%ebp)\n"
        "movw %ax, -0x24(%ebp)\n" /* u */
        "addl $6, %edx\n" /* line 105 */
        "movl %edx, -0x1c(%ebp)\n" /* pos */
        "movswl %ax, %edx\n" /* line 106 */
        "movl %edx, -0xec(%ebp)\n"
        /* } scope */
        "testw %ax, %ax\n" /* line 161 */
        "jne .Lfba8b4_000baae8\n"
        "movl $0, -0xc0(%ebp)\n" /* boneNames */
        ".Lfba8b4_000ba978:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 163 | pos */
        "movzbl (%eax), %ebx\n" /* i */
        "leal 1(%eax), %ecx\n" /* line 164 */
        "movl %ecx, -0x1c(%ebp)\n" /* pos */
        "movzbl %bl, %ebx\n" /* line 165 | i */
        "movl %ebx, %edi\n" /* i */
        "andl $1, %edi\n"
        "movl %edi, %edx\n"
        "movb %dl, -0xc6(%ebp)\n"
        "shrl $1, %ebx\n" /* line 166 | i */
        "andl $1, %ebx\n" /* i */
        "movb %bl, -0xc5(%ebp)\n" /* i */
        /* { scope 2: u */
        "movswl 1(%eax), %esi\n" /* line 104 | j */
        "movw %si, -0x24(%ebp)\n" /* j, u */
        "addl $3, %eax\n" /* line 105 */
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl $0x2c, (%esp)\n" /* line 170 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0xbc(%ebp)\n" /* parts */
        "movzwl -0xca(%ebp), %ecx\n" /* line 173 */
        "movw %cx, 0xe(%eax)\n"
        "movl -0xc0(%ebp), %edx\n" /* line 174 | boneNames */
        "movl %edx, 0x10(%eax)\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 175 | sQ2 */
        "movss %xmm0, 4(%eax)\n"
        "movl %edi, %ecx\n" /* line 176 */
        "movb %cl, 2(%eax)\n"
        "movb %bl, 3(%eax)\n" /* line 177 | i */
        "cmpb $0, -0xc6(%ebp)\n" /* line 180 */
        "jne .Lfba8b4_000bac59\n"
        "movl -0xc8(%ebp), %ebx\n" /* i */
        "movw %bx, -0xb6(%ebp)\n" /* i, numloopframes */
        "movl %ebx, %eax\n" /* i */
        ".Lfba8b4_000ba9fe:\n"
        "cmpw $0x100, -0xb6(%ebp)\n" /* line 181 | numloopframes */
        "setbe -0xa5(%ebp)\n" /* bSmallIndices */
        "subl $1, %eax\n" /* line 182 */
        "movl -0xbc(%ebp), %edx\n" /* parts */
        "movw %ax, (%edx)\n"
        "testw %ax, %ax\n" /* line 183 */
        "jne .Lfba8b4_000baafd\n"
        "pxor %xmm1, %xmm1\n"
        "movl -0xbc(%ebp), %ebx\n" /* parts, i */
        "movss %xmm1, 8(%ebx)\n" /* i */
        "cmpb $0, -0xc5(%ebp)\n" /* line 187 */
        "jne .Lfba8b4_000bab27\n"
        ".Lfba8b4_000baa3f:\n"
        "cmpw $0, -0xca(%ebp)\n" /* line 341 */
        "jne .Lfba8b4_000bad04\n"
        "movl $0, -0xac(%ebp)\n" /* flipQuatBits */
        "movl $0, -0xa0(%ebp)\n" /* simpleQuatBits */
        "movl -0xec(%ebp), %edx\n" /* line 359 */
        "testl %edx, %edx\n"
        "jg .Lfba8b4_000bad7e\n"
        /* { scope 2: u */
        ".Lfba8b4_000baa6f:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 62 | pos */
        "movzbl (%eax), %esi\n" /* numNoteTracks */
        "addl $1, %eax\n" /* line 63 */
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        "leal 1(%esi), %eax\n" /* line 66 | numNoteTracks */
        "movl -0xbc(%ebp), %edx\n" /* parts */
        "movb %al, 0xc(%edx)\n"
        "movzbl %al, %eax\n" /* line 68 */
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, %ebx\n" /* notify */
        "movl -0xbc(%ebp), %ecx\n" /* line 69 | parts */
        "movl %eax, 0x1c(%ecx)\n"
        "testl %esi, %esi\n" /* line 71 | numNoteTracks */
        "jg .Lfba8b4_000bac70\n"
        ".Lfba8b4_000baaa6:\n"
        "movl $3, 8(%esp)\n" /* line 85 */
        "movl $0, 4(%esp)\n"
        "movl $0x217830, (%esp)\n" /* "end" */
        "calll SL_GetString_\n"
        "movw %ax, (%ebx)\n" /* notify */
        "movl $0x3f800000, 4(%ebx)\n" /* line 86 | notify */
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 611 | buf */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        ".Lfba8b4_000baad7:\n"
        "movl -0xbc(%ebp), %eax\n" /* line 614 | parts */
        "addl $0x10c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfba8b4_000baae8:\n"
        "movl %edx, %eax\n"
        /* { scope 1: u, i */
        "addl %eax, %eax\n" /* line 161 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0xc0(%ebp)\n" /* boneNames */
        "jmp .Lfba8b4_000ba978\n"
        ".Lfba8b4_000baafd:\n"
        "movzwl %ax, %eax\n" /* line 183 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl -0xbc(%ebp), %ecx\n" /* parts */
        "movss 4(%ecx), %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "movl %ecx, %ebx\n" /* i */
        "movss %xmm1, 8(%ebx)\n" /* i */
        "cmpb $0, -0xc5(%ebp)\n" /* line 187 */
        "je .Lfba8b4_000baa3f\n"
        ".Lfba8b4_000bab27:\n"
        "movl $8, (%esp)\n" /* line 189 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0xb0(%ebp)\n" /* deltaPart */
        "movl %eax, 0x20(%ebx)\n" /* line 190 | i */
        /* { scope 2: u */
        "movl -0x1c(%ebp), %ecx\n" /* line 119 | pos */
        "movzwl (%ecx), %eax\n"
        "movw %ax, -0x24(%ebp)\n" /* u */
        "leal 2(%ecx), %edi\n" /* line 120 */
        "movl %edi, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl %eax, %esi\n" /* line 192 | sQ2 */
        "testw %ax, %ax\n" /* line 193 */
        "je .Lfba8b4_000bb37a\n"
        "cmpw $1, %ax\n" /* line 197 */
        "je .Lfba8b4_000bb955\n"
        "cmpw %ax, -0xb6(%ebp)\n" /* line 210 | numloopframes */
        "jbe .Lfba8b4_000bb932\n"
        "cmpb $0, -0xa5(%ebp)\n" /* line 212 | bSmallIndices */
        "je .Lfba8b4_000bb820\n"
        "movzwl %ax, %edi\n" /* line 215 */
        "leal 0xa(%edi, %edi), %eax\n" /* line 216 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb0(%ebp), %ebx\n" /* deltaPart, i */
        "movl %eax, 4(%ebx)\n" /* i */
        "movl %edi, -0x8c(%ebp)\n" /* line 220 */
        "addl $8, %eax\n" /* line 221 */
        "movl %edi, 8(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pos */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 222 */
        "addl %ecx, -0x1c(%ebp)\n" /* pos */
        ".Lfba8b4_000babb4:\n"
        "movl -0xb0(%ebp), %eax\n" /* line 248 | deltaPart */
        "movl 4(%eax), %edx\n"
        "leal -1(%esi), %eax\n" /* sQ2 */
        "movw %ax, (%edx)\n"
        "movl -0xb0(%ebp), %edx\n" /* line 249 | deltaPart */
        "movl 4(%edx), %ebx\n" /* i */
        "leal (, %edi, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, 4(%ebx)\n" /* i */
        "movl -0x8c(%ebp), %ebx\n" /* line 251 | i */
        "testl %ebx, %ebx\n" /* i */
        "jg .Lfba8b4_000bb89d\n"
        ".Lfba8b4_000babea:\n"
        "cmpl $1, -0x8c(%ebp)\n" /* line 258 */
        "jle .Lfba8b4_000bb387\n"
        "movl $1, -0x84(%ebp)\n"
        "movl $4, %edi\n"
        "jmp .Lfba8b4_000bac24\n"
        ".Lfba8b4_000bac08:\n"
        "addl $1, -0x84(%ebp)\n"
        "addl $4, %edi\n"
        "movl -0x8c(%ebp), %ecx\n"
        "cmpl %ecx, -0x84(%ebp)\n"
        "je .Lfba8b4_000bb387\n"
        ".Lfba8b4_000bac24:\n"
        "movl -0xb0(%ebp), %edx\n" /* line 260 | deltaPart */
        "movl 4(%edx), %eax\n"
        "movl %edi, %ebx\n" /* i */
        "addl 4(%eax), %ebx\n" /* i */
        "movzwl (%ebx), %esi\n" /* line 263 | i, sQ2 */
        "movswl %si, %ecx\n" /* line 264 | sQ2 */
        "movswl -4(%ebx), %eax\n" /* i */
        "imull %eax, %ecx\n"
        "movswl 2(%ebx), %eax\n" /* i */
        "movswl -2(%ebx), %edx\n" /* i */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "jns .Lfba8b4_000bac08\n"
        "negl %esi\n" /* line 266 | sQ2 */
        "movw %si, (%ebx)\n" /* sQ2, i */
        "negw 2(%ebx)\n" /* line 267 | i */
        "jmp .Lfba8b4_000bac08\n"
        ".Lfba8b4_000bac59:\n"
        "movl -0xc8(%ebp), %edi\n" /* line 180 */
        "addl $1, %edi\n"
        "movw %di, -0xb6(%ebp)\n" /* numloopframes */
        "movl %edi, %eax\n"
        "jmp .Lfba8b4_000ba9fe\n"
        /* { scope 2: u */
        ".Lfba8b4_000bac70:\n"
        "movl $0, -0x9c(%ebp)\n" /* line 71 | i */
        ".Lfba8b4_000bac7a:\n"
        "movl $3, 8(%esp)\n" /* line 73 */
        "movl $0, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pos */
        "movl %eax, (%esp)\n"
        "calll SL_GetString_\n"
        "movw %ax, (%ebx)\n" /* notify */
        "movl -0x1c(%ebp), %edx\n" /* line 75 | pos */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %edx), %ecx\n"
        "leal 1(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        /* { scope 3 */
        "movzwl 1(%ecx), %eax\n" /* line 119 */
        "movw %ax, -0x24(%ebp)\n" /* u */
        "addl $3, %ecx\n" /* line 120 */
        "movl %ecx, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl %eax, %edx\n" /* line 77 */
        "movl -0xbc(%ebp), %ecx\n" /* line 79 | parts */
        "movzwl (%ecx), %eax\n"
        "pxor %xmm1, %xmm1\n"
        "testw %ax, %ax\n"
        "je .Lfba8b4_000bace4\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "movzwl %ax, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        ".Lfba8b4_000bace4:\n"
        "movss %xmm1, 4(%ebx)\n" /* notify */
        "addl $1, -0x9c(%ebp)\n" /* line 71 | i */
        "addl $8, %ebx\n" /* notify */
        "cmpl -0x9c(%ebp), %esi\n" /* i, numNoteTracks */
        "jne .Lfba8b4_000bac7a\n"
        "jmp .Lfba8b4_000baaa6\n"
        /* } scope */
        ".Lfba8b4_000bad04:\n"
        "movl -0xec(%ebp), %ebx\n" /* line 343 | i */
        "subl $1, %ebx\n" /* i */
        "sarl $3, %ebx\n" /* i */
        "addl $1, %ebx\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* line 344 | pos */
        "movl %eax, -0xac(%ebp)\n" /* flipQuatBits */
        "addl %ebx, %eax\n" /* line 345 | i */
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        "movl %ebx, (%esp)\n" /* line 346 | i */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0xa0(%ebp)\n" /* simpleQuatBits */
        "movl %ebx, 8(%esp)\n" /* line 347 | i */
        "movl -0x1c(%ebp), %eax\n" /* pos */
        "movl %eax, 4(%esp)\n"
        "movl -0xa0(%ebp), %edx\n" /* simpleQuatBits */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "addl %ebx, -0x1c(%ebp)\n" /* line 348 | i, pos */
        "movl -0xa0(%ebp), %ebx\n" /* line 350 | simpleQuatBits, i */
        "movl -0xbc(%ebp), %ecx\n" /* parts */
        "movl %ebx, 0x14(%ecx)\n" /* i */
        "movl -0xec(%ebp), %eax\n" /* line 351 */
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xbc(%ebp), %edi\n" /* parts */
        "movl %eax, 0x18(%edi)\n"
        "movl -0xec(%ebp), %edx\n" /* line 359 */
        "testl %edx, %edx\n"
        "jle .Lfba8b4_000baa6f\n"
        ".Lfba8b4_000bad7e:\n"
        "xorl %esi, %esi\n" /* sQ2 */
        "movl -0x1c(%ebp), %eax\n" /* pos */
        "movl %eax, -0xe8(%ebp)\n"
        "movl %eax, %edi\n"
        "jmp .Lfba8b4_000bad8f\n"
        ".Lfba8b4_000bad8d:\n"
        "movl %ebx, %edi\n" /* i */
        ".Lfba8b4_000bad8f:\n"
        "cld\n" /* line 361 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n" /* i */
        "notl %ebx\n" /* i */
        "movl $9, 0xc(%esp)\n" /* line 362 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl $0, 4(%esp)\n"
        "movl -0xe8(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        "movl -0xc0(%ebp), %edx\n" /* boneNames */
        "movw %ax, (%edx, %esi, 2)\n"
        "addl -0x1c(%ebp), %ebx\n" /* line 363 | pos, i */
        "movl %ebx, -0xe8(%ebp)\n" /* i */
        "movl %ebx, -0x1c(%ebp)\n" /* i, pos */
        "addl $1, %esi\n" /* line 359 | sQ2 */
        "cmpl %esi, -0xec(%ebp)\n" /* sQ2 */
        "jne .Lfba8b4_000bad8d\n"
        "movl $0, -0x88(%ebp)\n"
        ".Lfba8b4_000badea:\n"
        "movl -0x88(%ebp), %edx\n" /* line 368 */
        "sarl $3, %edx\n"
        "movl -0x88(%ebp), %ecx\n"
        "andl $7, %ecx\n"
        "movl -0xac(%ebp), %ebx\n" /* flipQuatBits, i */
        "movzbl (%ebx, %edx), %eax\n" /* i */
        "sarl %cl, %eax\n"
        "andb $1, %al\n"
        "movb %al, -0xc1(%ebp)\n"
        "movl -0xa0(%ebp), %edi\n" /* line 369 | simpleQuatBits */
        "movsbl (%edi, %edx), %eax\n"
        "sarl %cl, %eax\n"
        "andb $1, %al\n"
        "movl %eax, %edi\n"
        "movl -0xbc(%ebp), %edx\n" /* line 371 | parts */
        "movl 0x18(%edx), %eax\n"
        "movl -0x88(%ebp), %ecx\n"
        "leal (%eax, %ecx, 8), %eax\n"
        "movl %eax, -0xb4(%ebp)\n" /* part */
        /* { scope 2: u */
        "movl -0xe8(%ebp), %ecx\n" /* line 119 */
        "movl %ecx, %ebx\n" /* i */
        "movzwl (%ecx), %eax\n"
        "movw %ax, -0x24(%ebp)\n" /* u */
        "addl $2, %ebx\n" /* line 120 | i */
        "movl %ebx, -0x1c(%ebp)\n" /* i, pos */
        /* } scope */
        "movw %ax, -0xa8(%ebp)\n" /* line 373 | numQuatIndices */
        "testw %ax, %ax\n" /* line 374 */
        "je .Lfba8b4_000baf9c\n"
        "cmpw $1, -0xa8(%ebp)\n" /* line 379 | numQuatIndices */
        "je .Lfba8b4_000bb1dd\n"
        "movl -0xa8(%ebp), %ebx\n" /* line 420 | numQuatIndices, i */
        "cmpw %bx, -0xb6(%ebp)\n" /* i, numloopframes */
        "jbe .Lfba8b4_000bb3b3\n"
        "cmpb $0, -0xa5(%ebp)\n" /* line 422 | bSmallIndices */
        "je .Lfba8b4_000bb2b9\n"
        "movzwl %bx, %esi\n" /* line 425 | i, sQ2 */
        "leal 0xa(%esi, %esi), %eax\n" /* line 426 | sQ2 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb4(%ebp), %edx\n" /* part */
        "movl %eax, 4(%edx)\n"
        "movl %esi, -0x90(%ebp)\n" /* line 430 | sQ2 */
        "movl %eax, %edx\n" /* line 431 */
        "addl $8, %edx\n"
        "movl %esi, 8(%esp)\n" /* sQ2 */
        "movl -0x1c(%ebp), %eax\n" /* pos */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x90(%ebp), %ebx\n" /* line 432 | i */
        "addl %ebx, -0x1c(%ebp)\n" /* i, pos */
        ".Lfba8b4_000baec8:\n"
        "movl %edi, %eax\n" /* line 458 */
        "testb %al, %al\n"
        "je .Lfba8b4_000bb0f1\n"
        "movl -0xb4(%ebp), %edx\n" /* line 460 | part */
        "movl 4(%edx), %ebx\n" /* i */
        "leal (, %esi, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, 4(%ebx)\n" /* i */
        /* { scope 2: u */
        /* { scope 3 */
        "movl -0x1c(%ebp), %eax\n" /* line 104 | pos */
        "movzwl (%eax), %edx\n"
        "movw %dx, -0x24(%ebp)\n" /* u */
        "addl $2, %eax\n" /* line 105 */
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        "movswl %dx, %eax\n" /* line 106 */
        /* } scope */
        "movw %dx, -0x2c(%ebp)\n" /* line 42 | quat */
        "imull %eax, %eax\n" /* line 46 */
        "movl $0x3fff0001, %edx\n"
        "subl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 48 */
        "jle .Lfba8b4_000bb470\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 81 */
        "sqrtss %xmm0, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xdc(%ebp)\n"
        "cvttss2si -0xdc(%ebp), %eax\n"
        ".Lfba8b4_000baf3c:\n"
        "movw %ax, -0x2a(%ebp)\n" /* line 51 */
        /* } scope */
        "cmpb $0, -0xc1(%ebp)\n" /* line 464 */
        "je .Lfba8b4_000bb303\n"
        "movl -0x2c(%ebp), %edx\n" /* line 466 | quat */
        "negl %edx\n"
        "movw %dx, -0x2c(%ebp)\n" /* quat */
        "negl %eax\n" /* line 467 */
        "movw %ax, -0x2a(%ebp)\n"
        ".Lfba8b4_000baf5c:\n"
        "movl -0xb4(%ebp), %ecx\n" /* line 470 | part */
        "movl 4(%ecx), %eax\n"
        "movl 4(%eax), %eax\n"
        "movw %dx, (%eax)\n"
        "movl 4(%ecx), %eax\n" /* line 471 */
        "movl 4(%eax), %edx\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, 2(%edx)\n"
        "cmpl $1, -0x90(%ebp)\n" /* line 473 */
        "jg .Lfba8b4_000bb6aa\n"
        "movl -0xb4(%ebp), %edi\n" /* part */
        "movl 4(%edi), %edi\n"
        "movl %edi, -0xe4(%ebp)\n"
        "movl %edi, %edx\n"
        "jmp .Lfba8b4_000bb191\n"
        ".Lfba8b4_000baf9c:\n"
        "movl -0xb4(%ebp), %edi\n" /* line 377 | part */
        "movl $0, 4(%edi)\n"
        /* { scope 2: u */
        ".Lfba8b4_000bafa9:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 119 | pos */
        "movzwl (%edx), %eax\n"
        "movw %ax, -0x24(%ebp)\n" /* u */
        "leal 2(%edx), %ecx\n" /* line 120 */
        "movl %ecx, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl %eax, %esi\n" /* line 540 | sQ2 */
        "testw %ax, %ax\n" /* line 541 */
        "jne .Lfba8b4_000baff3\n"
        "movl -0xb4(%ebp), %ebx\n" /* line 543 | part, i */
        "movl $0, (%ebx)\n" /* i */
        ".Lfba8b4_000bafcc:\n"
        "addl $1, -0x88(%ebp)\n" /* line 366 */
        "movl -0x88(%ebp), %eax\n"
        "cmpl %eax, -0xec(%ebp)\n"
        "je .Lfba8b4_000baa6f\n"
        "movl -0x1c(%ebp), %ecx\n" /* pos */
        "movl %ecx, -0xe8(%ebp)\n"
        "jmp .Lfba8b4_000badea\n"
        ".Lfba8b4_000baff3:\n"
        "cmpw $1, %ax\n" /* line 545 */
        "je .Lfba8b4_000bb419\n"
        "cmpw %ax, -0xb6(%ebp)\n" /* line 559 | numloopframes */
        "jbe .Lfba8b4_000bb297\n"
        "cmpb $0, -0xa5(%ebp)\n" /* line 561 | bSmallIndices */
        "je .Lfba8b4_000bb1a2\n"
        "movzwl %ax, %edi\n" /* line 564 */
        "leal 0xe(%edi, %edi), %eax\n" /* line 565 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb4(%ebp), %ecx\n" /* part */
        "movl %eax, (%ecx)\n"
        "movl %edi, -0x94(%ebp)\n" /* line 569 */
        "addl $8, %eax\n" /* line 570 */
        "movl %edi, 8(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pos */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl %edi, -0x1c(%ebp)\n" /* line 571 | pos */
        ".Lfba8b4_000bb04b:\n"
        "movl -0xb4(%ebp), %eax\n" /* line 597 | part */
        "movl (%eax), %edx\n"
        "leal -1(%esi), %eax\n" /* sQ2 */
        "movw %ax, (%edx)\n"
        "movl -0xb4(%ebp), %edx\n" /* line 598 | part */
        "movl (%edx), %ebx\n" /* i */
        "leal (%edi, %edi, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, 4(%ebx)\n" /* i */
        "movl -0x94(%ebp), %eax\n" /* line 600 */
        "testl %eax, %eax\n"
        "jle .Lfba8b4_000bafcc\n"
        "xorl %esi, %esi\n" /* sQ2 */
        "xorl %ebx, %ebx\n" /* i */
        ".Lfba8b4_000bb082:\n"
        "movl -0xb4(%ebp), %ecx\n" /* line 602 | part */
        "movl (%ecx), %eax\n"
        "movl %ebx, %ecx\n" /* i */
        "addl 4(%eax), %ecx\n"
        /* { scope 2: u */
        "movl -0x1c(%ebp), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* u */
        "addl $4, %edx\n" /* line 150 */
        "movl %edx, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 602 | u */
        "movl %eax, (%ecx)\n"
        "movl -0xb4(%ebp), %edi\n" /* line 603 | part */
        "movl (%edi), %eax\n"
        "movl %ebx, %ecx\n" /* i */
        "addl 4(%eax), %ecx\n"
        /* { scope 2: u */
        "movl -0x1c(%ebp), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* u */
        "addl $4, %edx\n" /* line 150 */
        "movl %edx, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 603 | u */
        "movl %eax, 4(%ecx)\n"
        "movl (%edi), %eax\n" /* line 604 */
        "movl %ebx, %ecx\n" /* i */
        "addl 4(%eax), %ecx\n"
        /* { scope 2: u */
        "movl -0x1c(%ebp), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* u */
        "addl $4, %edx\n" /* line 150 */
        "movl %edx, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 604 | u */
        "movl %eax, 8(%ecx)\n"
        "addl $1, %esi\n" /* line 600 | sQ2 */
        "addl $0xc, %ebx\n" /* i */
        "cmpl -0x94(%ebp), %esi\n" /* sQ2 */
        "jne .Lfba8b4_000bb082\n"
        "jmp .Lfba8b4_000bafcc\n"
        ".Lfba8b4_000bb0f1:\n"
        "movl -0xb4(%ebp), %edi\n" /* line 495 | part */
        "movl 4(%edi), %ebx\n" /* i */
        "leal (, %esi, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, 4(%ebx)\n" /* i */
        "leal -0x2c(%ebp), %edi\n" /* line 497 | quat */
        "leal -0x1c(%ebp), %esi\n" /* pos, sQ2 */
        "movl %edi, %edx\n"
        "movl %esi, %eax\n" /* sQ2 */
        "calll ConsumeQuat\n"
        "cmpb $0, -0xc1(%ebp)\n" /* line 499 */
        "je .Lfba8b4_000bb2fb\n"
        "movl -0x2c(%ebp), %edx\n" /* line 501 | quat */
        "negl %edx\n"
        "movw %dx, -0x2c(%ebp)\n" /* quat */
        "negw -0x2a(%ebp)\n" /* line 502 */
        "negw -0x28(%ebp)\n" /* line 503 */
        "negw -0x26(%ebp)\n" /* line 504 */
        ".Lfba8b4_000bb13b:\n"
        "movl -0xb4(%ebp), %ecx\n" /* line 507 | part */
        "movl 4(%ecx), %eax\n"
        "movl 4(%eax), %eax\n"
        "movw %dx, (%eax)\n"
        "movl 4(%ecx), %eax\n" /* line 508 */
        "movl 4(%eax), %edx\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, 2(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 509 */
        "movl 4(%eax), %edx\n"
        "movl -0x28(%ebp), %eax\n"
        "movw %ax, 4(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 510 */
        "movl 4(%eax), %edx\n"
        "movzwl -0x26(%ebp), %eax\n"
        "movw %ax, 6(%edx)\n"
        "cmpl $1, -0x90(%ebp)\n" /* line 512 */
        "jg .Lfba8b4_000bb575\n"
        "movl -0xb4(%ebp), %eax\n" /* part */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0xe4(%ebp)\n"
        "movl %eax, %edx\n"
        ".Lfba8b4_000bb191:\n"
        "movl -0xa8(%ebp), %eax\n" /* line 537 | numQuatIndices */
        "subl $1, %eax\n"
        "movw %ax, (%edx)\n"
        "jmp .Lfba8b4_000bafa9\n"
        ".Lfba8b4_000bb1a2:\n"
        "movzwl %ax, %edi\n" /* line 576 */
        "leal (%edi, %edi), %ebx\n" /* i */
        "leal 0xe(%ebx), %eax\n" /* line 577 | i */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb4(%ebp), %edx\n" /* part */
        "movl %eax, (%edx)\n"
        "addl $8, %eax\n" /* line 583 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl -0x1c(%ebp), %edx\n" /* pos */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl %ebx, -0x1c(%ebp)\n" /* line 584 | i, pos */
        "movl %edi, -0x94(%ebp)\n"
        "jmp .Lfba8b4_000bb04b\n"
        ".Lfba8b4_000bb1dd:\n"
        "movl %edi, %eax\n" /* line 381 */
        "testb %al, %al\n"
        "je .Lfba8b4_000bb30b\n"
        /* { scope 2: u */
        /* { scope 3 */
        "movzwl 2(%ecx), %edx\n" /* line 104 */
        "movw %dx, -0x24(%ebp)\n" /* u */
        "addl $4, %ecx\n" /* line 105 */
        "movl %ecx, -0x1c(%ebp)\n" /* pos */
        "movswl %dx, %eax\n" /* line 106 */
        /* } scope */
        "movw %dx, -0x2c(%ebp)\n" /* line 42 | quat */
        "imull %eax, %eax\n" /* line 46 */
        "movl $0x3fff0001, %edx\n"
        "subl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 48 */
        "jle .Lfba8b4_000bb7de\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 81 */
        "sqrtss %xmm0, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xd8(%ebp)\n"
        "cvttss2si -0xd8(%ebp), %eax\n"
        ".Lfba8b4_000bb236:\n"
        "movw %ax, -0x2a(%ebp)\n" /* line 51 */
        /* } scope */
        "cmpb $0, -0xc1(%ebp)\n" /* line 385 */
        "je .Lfba8b4_000bb24d\n"
        "negw -0x2c(%ebp)\n" /* line 387 | quat */
        "negl %eax\n" /* line 388 */
        "movw %ax, -0x2a(%ebp)\n"
        ".Lfba8b4_000bb24d:\n"
        "movl $8, (%esp)\n" /* line 391 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0xe4(%ebp)\n"
        "movl -0xb4(%ebp), %edx\n" /* part */
        "movl %eax, 4(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 392 | quat */
        "movl -0xe4(%ebp), %ecx\n"
        "movw %ax, 4(%ecx)\n"
        "movl -0xb4(%ebp), %ebx\n" /* line 393 | part, i */
        "movl 4(%ebx), %edx\n" /* i */
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, 6(%edx)\n"
        ".Lfba8b4_000bb284:\n"
        "movl -0xb4(%ebp), %ecx\n" /* line 414 | part */
        "movl 4(%ecx), %eax\n"
        "movw $0, (%eax)\n"
        "jmp .Lfba8b4_000bafa9\n"
        ".Lfba8b4_000bb297:\n"
        "movl $8, (%esp)\n" /* line 594 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb4(%ebp), %ecx\n" /* part */
        "movl %eax, (%ecx)\n"
        "movzwl %si, %ebx\n" /* sQ2, i */
        "movl %ebx, -0x94(%ebp)\n" /* i */
        "movl %ebx, %edi\n" /* i */
        "jmp .Lfba8b4_000bb04b\n"
        ".Lfba8b4_000bb2b9:\n"
        "movzwl -0xa8(%ebp), %esi\n" /* line 437 | numQuatIndices, sQ2 */
        "leal (%esi, %esi), %ebx\n" /* sQ2, i */
        "leal 0xa(%ebx), %eax\n" /* line 438 | i */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb4(%ebp), %edx\n" /* part */
        "movl %eax, 4(%edx)\n"
        "movl %eax, %edx\n" /* line 444 */
        "addl $8, %edx\n"
        "movl %ebx, 8(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* pos */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "addl %ebx, -0x1c(%ebp)\n" /* line 445 | i, pos */
        "movl %esi, -0x90(%ebp)\n" /* sQ2 */
        "jmp .Lfba8b4_000baec8\n"
        ".Lfba8b4_000bb2fb:\n"
        "movl -0x2c(%ebp), %edx\n" /* quat */
        "jmp .Lfba8b4_000bb13b\n"
        ".Lfba8b4_000bb303:\n"
        "movl -0x2c(%ebp), %edx\n" /* quat */
        "jmp .Lfba8b4_000baf5c\n"
        ".Lfba8b4_000bb30b:\n"
        "leal -0x2c(%ebp), %edx\n" /* line 397 | quat */
        "leal -0x1c(%ebp), %eax\n" /* pos */
        "calll ConsumeQuat\n"
        "cmpb $0, -0xc1(%ebp)\n" /* line 399 */
        "je .Lfba8b4_000bb32f\n"
        "negw -0x2c(%ebp)\n" /* line 401 | quat */
        "negw -0x2a(%ebp)\n" /* line 402 */
        "negw -0x28(%ebp)\n" /* line 403 */
        "negw -0x26(%ebp)\n" /* line 404 */
        ".Lfba8b4_000bb32f:\n"
        "movl $0xc, (%esp)\n" /* line 407 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0xe4(%ebp)\n"
        "movl -0xb4(%ebp), %edi\n" /* part */
        "movl %eax, 4(%edi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 408 | quat */
        "movl -0xe4(%ebp), %edx\n"
        "movw %ax, 4(%edx)\n"
        "movl 4(%edi), %edx\n" /* line 409 */
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, 6(%edx)\n"
        "movl 4(%edi), %edx\n" /* line 410 */
        "movl -0x28(%ebp), %eax\n"
        "movw %ax, 8(%edx)\n"
        "movl 4(%edi), %edx\n" /* line 411 */
        "movzwl -0x26(%ebp), %eax\n"
        "movw %ax, 0xa(%edx)\n"
        "jmp .Lfba8b4_000bb284\n"
        ".Lfba8b4_000bb37a:\n"
        "movl -0xb0(%ebp), %eax\n" /* line 195 | deltaPart */
        "movl $0, 4(%eax)\n"
        /* { scope 2: u */
        ".Lfba8b4_000bb387:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 119 | pos */
        "movzwl (%edx), %eax\n"
        "movw %ax, -0x24(%ebp)\n" /* u */
        "leal 2(%edx), %ebx\n" /* line 120 | i */
        "movl %ebx, -0x1c(%ebp)\n" /* i, pos */
        /* } scope */
        "movl %eax, %esi\n" /* line 272 | sQ2 */
        "testw %ax, %ax\n" /* line 273 */
        "jne .Lfba8b4_000bb477\n"
        "movl -0xb0(%ebp), %edi\n" /* line 275 | deltaPart */
        "movl $0, (%edi)\n"
        "jmp .Lfba8b4_000baa3f\n"
        ".Lfba8b4_000bb3b3:\n"
        "movl $8, (%esp)\n" /* line 455 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb4(%ebp), %ecx\n" /* part */
        "movl %eax, 4(%ecx)\n"
        "movzwl -0xa8(%ebp), %ebx\n" /* numQuatIndices, i */
        "movl %ebx, -0x90(%ebp)\n" /* i */
        "movl %ebx, %esi\n" /* i, sQ2 */
        "jmp .Lfba8b4_000baec8\n"
        ".Lfba8b4_000bb3da:\n"
        "movl %edx, (%esp)\n" /* line 153 */
        "calll FS_FreeFile\n"
        "movl $0xe, 0xc(%esp)\n" /* line 154 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl %esi, 4(%esp)\n" /* sQ2 */
        "movl $0x21fd8c, (%esp)\n" /* "^1ERROR: xanim '%s' out of date (version %d, expecting %d)
" */
        "calll Com_Printf\n"
        "movl $0, -0xbc(%ebp)\n" /* parts */
        /* } scope */
        "movl -0xbc(%ebp), %eax\n" /* line 614 | parts */
        "addl $0x10c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: u, i */
        /* { scope 2: u */
        ".Lfba8b4_000bb419:\n"
        "movl 2(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x24(%ebp)\n" /* u */
        "leal 6(%edx), %edi\n" /* line 150 */
        "movl %edi, -0x1c(%ebp)\n" /* pos */
        "movl -0x24(%ebp), %edi\n" /* line 151 | u */
        /* } scope */
        /* { scope 2: u */
        "movl 6(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x24(%ebp)\n" /* u */
        "leal 0xa(%edx), %eax\n" /* line 150 */
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        "movl -0x24(%ebp), %esi\n" /* line 151 | u, sQ2 */
        /* } scope */
        /* { scope 2: u */
        "movl 0xa(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x24(%ebp)\n" /* u */
        "addl $0xe, %edx\n" /* line 150 */
        "movl %edx, -0x1c(%ebp)\n" /* pos */
        "movl -0x24(%ebp), %ebx\n" /* line 151 | u, i */
        /* } scope */
        "movl $0x10, (%esp)\n" /* line 551 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb4(%ebp), %edx\n" /* part */
        "movl %eax, (%edx)\n"
        "movw $0, (%eax)\n" /* line 552 */
        "movl (%edx), %eax\n" /* line 553 */
        "leal 4(%eax), %edx\n" /* to */
        /* { scope 2: u */
        "movl %edi, 4(%eax)\n" /* line 199 */
        "movl %esi, 4(%edx)\n" /* line 200 | sQ2 */
        "movl %ebx, 8(%edx)\n" /* line 201 | i */
        "jmp .Lfba8b4_000bafcc\n"
        /* } scope */
        /* { scope 2: u */
        ".Lfba8b4_000bb470:\n"
        "xorl %eax, %eax\n" /* line 48 */
        "jmp .Lfba8b4_000baf3c\n"
        /* } scope */
        ".Lfba8b4_000bb477:\n"
        "cmpw $1, %ax\n" /* line 277 */
        "je .Lfba8b4_000bb9e0\n"
        "cmpw %ax, -0xb6(%ebp)\n" /* line 291 | numloopframes */
        "jbe .Lfba8b4_000bb87b\n"
        "cmpb $0, -0xa5(%ebp)\n" /* line 293 | bSmallIndices */
        "je .Lfba8b4_000bb7e5\n"
        "movzwl %ax, %edi\n" /* line 296 */
        "leal 0xe(%edi, %edi), %eax\n" /* line 297 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb0(%ebp), %ecx\n" /* deltaPart */
        "movl %eax, (%ecx)\n"
        "movl %edi, -0xa4(%ebp)\n" /* line 301 | size */
        "addl $8, %eax\n" /* line 302 */
        "movl %edi, 8(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pos */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl %edi, -0x1c(%ebp)\n" /* line 303 | pos */
        ".Lfba8b4_000bb4cf:\n"
        "movl -0xb0(%ebp), %eax\n" /* line 329 | deltaPart */
        "movl (%eax), %edx\n"
        "leal -1(%esi), %eax\n" /* sQ2 */
        "movw %ax, (%edx)\n"
        "movl -0xb0(%ebp), %edx\n" /* line 330 | deltaPart */
        "movl (%edx), %ebx\n" /* i */
        "leal (%edi, %edi, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, 4(%ebx)\n" /* i */
        "movl -0xa4(%ebp), %ecx\n" /* line 332 | size */
        "testl %ecx, %ecx\n"
        "jle .Lfba8b4_000baa3f\n"
        "xorl %esi, %esi\n" /* sQ2 */
        "xorl %ebx, %ebx\n" /* i */
        ".Lfba8b4_000bb506:\n"
        "movl -0xb0(%ebp), %ecx\n" /* line 334 | deltaPart */
        "movl (%ecx), %eax\n"
        "movl %ebx, %ecx\n" /* i */
        "addl 4(%eax), %ecx\n"
        /* { scope 2: u */
        "movl -0x1c(%ebp), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* u */
        "addl $4, %edx\n" /* line 150 */
        "movl %edx, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 334 | u */
        "movl %eax, (%ecx)\n"
        "movl -0xb0(%ebp), %edi\n" /* line 335 | deltaPart */
        "movl (%edi), %eax\n"
        "movl %ebx, %ecx\n" /* i */
        "addl 4(%eax), %ecx\n"
        /* { scope 2: u */
        "movl -0x1c(%ebp), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* u */
        "addl $4, %edx\n" /* line 150 */
        "movl %edx, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 335 | u */
        "movl %eax, 4(%ecx)\n"
        "movl (%edi), %eax\n" /* line 336 */
        "movl %ebx, %ecx\n" /* i */
        "addl 4(%eax), %ecx\n"
        /* { scope 2: u */
        "movl -0x1c(%ebp), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* u */
        "addl $4, %edx\n" /* line 150 */
        "movl %edx, -0x1c(%ebp)\n" /* pos */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 336 | u */
        "movl %eax, 8(%ecx)\n"
        "addl $1, %esi\n" /* line 332 | sQ2 */
        "addl $0xc, %ebx\n" /* i */
        "cmpl %esi, -0xa4(%ebp)\n" /* sQ2, size */
        "jne .Lfba8b4_000bb506\n"
        "jmp .Lfba8b4_000baa3f\n"
        ".Lfba8b4_000bb575:\n"
        "movl $1, %ebx\n" /* line 512 | i */
        ".Lfba8b4_000bb57a:\n"
        "movl %edi, %edx\n" /* line 514 */
        "movl %esi, %eax\n" /* sQ2 */
        "calll ConsumeQuat\n"
        "leal (, %ebx, 8), %ecx\n"
        "movl -0xb4(%ebp), %edx\n" /* line 515 | part */
        "movl 4(%edx), %eax\n"
        "movl 4(%eax), %edx\n"
        "movl -0x2c(%ebp), %eax\n" /* quat */
        "movw %ax, (%ecx, %edx)\n"
        "movl -0xb4(%ebp), %edx\n" /* line 516 | part */
        "movl 4(%edx), %eax\n"
        "movl 4(%eax), %edx\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, 2(%ecx, %edx)\n"
        "movl -0xb4(%ebp), %edx\n" /* line 517 | part */
        "movl 4(%edx), %eax\n"
        "movl 4(%eax), %edx\n"
        "movl -0x28(%ebp), %eax\n"
        "movw %ax, 4(%ecx, %edx)\n"
        "movl -0xb4(%ebp), %edx\n" /* line 518 | part */
        "movl 4(%edx), %eax\n"
        "movl 4(%eax), %edx\n"
        "movzwl -0x26(%ebp), %eax\n"
        "movw %ax, 6(%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 512 | i */
        "cmpl -0x90(%ebp), %ebx\n" /* i */
        "jne .Lfba8b4_000bb57a\n"
        "movl $1, -0x7c(%ebp)\n"
        "movl $8, -0x98(%ebp)\n"
        "movl -0xb4(%ebp), %ecx\n" /* part */
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0xe4(%ebp)\n"
        "movl %ecx, %ebx\n" /* i */
        "jmp .Lfba8b4_000bb626\n"
        ".Lfba8b4_000bb60a:\n"
        "addl $1, -0x7c(%ebp)\n" /* line 521 */
        "addl $8, -0x98(%ebp)\n"
        "movl -0x90(%ebp), %ebx\n" /* i */
        "cmpl %ebx, -0x7c(%ebp)\n" /* i */
        "je .Lfba8b4_000bb69f\n"
        "movl -0xe4(%ebp), %ebx\n" /* i */
        ".Lfba8b4_000bb626:\n"
        "movl -0x98(%ebp), %edi\n" /* line 523 */
        "addl 4(%ebx), %edi\n" /* i */
        "leal -8(%edi), %esi\n" /* line 524 | sQ2 */
        "movzwl (%edi), %eax\n" /* line 526 */
        "movw %ax, -0xc4(%ebp)\n"
        "movswl %ax, %ebx\n" /* line 527 | i */
        "movswl -8(%edi), %eax\n"
        "imull %eax, %ebx\n" /* i */
        "movswl 2(%edi), %eax\n"
        "movswl 2(%esi), %edx\n" /* sQ2 */
        "imull %edx, %eax\n"
        "addl %eax, %ebx\n" /* i */
        "movswl 6(%edi), %ecx\n"
        "movswl 6(%esi), %eax\n" /* sQ2 */
        "imull %eax, %ecx\n"
        "movswl 4(%edi), %eax\n"
        "movswl 4(%esi), %edx\n" /* sQ2 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "addl %ecx, %ebx\n" /* i */
        "jns .Lfba8b4_000bb60a\n"
        "negw -0xc4(%ebp)\n" /* line 529 */
        "movl -0xc4(%ebp), %edx\n"
        "movw %dx, (%edi)\n"
        "negw 2(%edi)\n" /* line 530 */
        "negw 4(%edi)\n" /* line 531 */
        "negw 6(%edi)\n" /* line 532 */
        "movl -0xb4(%ebp), %ecx\n" /* part */
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0xe4(%ebp)\n"
        "jmp .Lfba8b4_000bb60a\n"
        ".Lfba8b4_000bb69f:\n"
        "movl -0xe4(%ebp), %edx\n"
        "jmp .Lfba8b4_000bb191\n"
        ".Lfba8b4_000bb6aa:\n"
        "movl $1, %ebx\n" /* line 473 | i */
        "jmp .Lfba8b4_000bb711\n"
        /* { scope 2: u */
        ".Lfba8b4_000bb6b1:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 81 */
        "sqrtss %xmm0, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xe0(%ebp)\n"
        "cvttss2si -0xe0(%ebp), %eax\n"
        ".Lfba8b4_000bb6d9:\n"
        "movw %ax, -0x2a(%ebp)\n" /* line 51 */
        "leal (, %ebx, 4), %ecx\n"
        /* } scope */
        "movl -0xb4(%ebp), %edi\n" /* line 476 | part */
        "movl 4(%edi), %eax\n"
        "movl 4(%eax), %edx\n"
        "movl -0x2c(%ebp), %eax\n" /* quat */
        "movw %ax, (%ecx, %edx)\n"
        "movl 4(%edi), %eax\n" /* line 477 */
        "movl 4(%eax), %edx\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, 2(%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 473 | i */
        "cmpl -0x90(%ebp), %ebx\n" /* i */
        "je .Lfba8b4_000bb73e\n"
        /* { scope 2: u */
        /* { scope 3 */
        ".Lfba8b4_000bb711:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 104 | pos */
        "movzwl (%eax), %edx\n"
        "movw %dx, -0x24(%ebp)\n" /* u */
        "addl $2, %eax\n" /* line 105 */
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        "movswl %dx, %eax\n" /* line 106 */
        /* } scope */
        "movw %dx, -0x2c(%ebp)\n" /* line 42 | quat */
        "imull %eax, %eax\n" /* line 46 */
        "movl $0x3fff0001, %edx\n"
        "subl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 48 */
        "jg .Lfba8b4_000bb6b1\n"
        "xorl %eax, %eax\n"
        "jmp .Lfba8b4_000bb6d9\n"
        /* } scope */
        ".Lfba8b4_000bb73e:\n"
        "movl $1, -0x80(%ebp)\n" /* line 473 */
        "movl $4, %edi\n"
        "movl -0xb4(%ebp), %eax\n" /* part */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0xe4(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfba8b4_000bb779\n"
        ".Lfba8b4_000bb75d:\n"
        "addl $1, -0x80(%ebp)\n" /* line 480 */
        "addl $4, %edi\n"
        "movl -0x90(%ebp), %ebx\n" /* i */
        "cmpl %ebx, -0x80(%ebp)\n" /* i */
        "je .Lfba8b4_000bb69f\n"
        "movl -0xe4(%ebp), %edx\n"
        ".Lfba8b4_000bb779:\n"
        "movl %edi, %ebx\n" /* line 482 | i */
        "addl 4(%edx), %ebx\n" /* i */
        "movzwl (%ebx), %esi\n" /* line 485 | i, sQ2 */
        "movswl %si, %ecx\n" /* line 486 | sQ2 */
        "movswl -4(%ebx), %eax\n" /* i */
        "imull %eax, %ecx\n"
        "movswl 2(%ebx), %eax\n" /* i */
        "movswl -2(%ebx), %edx\n" /* i */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "jns .Lfba8b4_000bb75d\n"
        "negl %esi\n" /* line 488 | sQ2 */
        "movw %si, (%ebx)\n" /* sQ2, i */
        "negw 2(%ebx)\n" /* line 489 | i */
        "movl -0xb4(%ebp), %ecx\n" /* part */
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0xe4(%ebp)\n"
        "jmp .Lfba8b4_000bb75d\n"
        ".Lfba8b4_000bb7b4:\n"
        "movl %esi, 4(%esp)\n" /* line 142 | sQ2 */
        "movl $0x21fd68, (%esp)\n" /* "^1ERROR: xanim '%s' has 0 length
" */
        "calll Com_Printf\n"
        "movl -0x20(%ebp), %eax\n" /* line 143 | buf */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl $0, -0xbc(%ebp)\n" /* parts */
        "jmp .Lfba8b4_000baad7\n"
        /* { scope 2: u */
        ".Lfba8b4_000bb7de:\n"
        "xorl %eax, %eax\n" /* line 48 */
        "jmp .Lfba8b4_000bb236\n"
        /* } scope */
        ".Lfba8b4_000bb7e5:\n"
        "movzwl %ax, %edi\n" /* line 308 */
        "leal (%edi, %edi), %ebx\n" /* i */
        "leal 0xe(%ebx), %eax\n" /* line 309 | i */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb0(%ebp), %edx\n" /* deltaPart */
        "movl %eax, (%edx)\n"
        "addl $8, %eax\n" /* line 315 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl -0x1c(%ebp), %edx\n" /* pos */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl %ebx, -0x1c(%ebp)\n" /* line 316 | i, pos */
        "movl %edi, -0xa4(%ebp)\n" /* size */
        "jmp .Lfba8b4_000bb4cf\n"
        ".Lfba8b4_000bb820:\n"
        "movzwl %ax, %edi\n" /* line 227 */
        "leal (%edi, %edi), %ebx\n" /* i */
        "leal 0xa(%ebx), %eax\n" /* line 228 | i */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb0(%ebp), %edx\n" /* deltaPart */
        "movl %eax, 4(%edx)\n"
        "addl $8, %eax\n" /* line 234 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl -0x1c(%ebp), %edx\n" /* pos */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl %ebx, -0x1c(%ebp)\n" /* line 235 | i, pos */
        "movl %edi, -0x8c(%ebp)\n"
        "jmp .Lfba8b4_000babb4\n"
        ".Lfba8b4_000bb85c:\n"
        "movl %ebx, 4(%esp)\n" /* line 127 | i */
        "movl $0x21fd24, (%esp)\n" /* "^1ERROR: filename '%s' too long
" */
        "calll Com_Printf\n"
        "movl $0, -0xbc(%ebp)\n" /* parts */
        "jmp .Lfba8b4_000baad7\n"
        ".Lfba8b4_000bb87b:\n"
        "movl $8, (%esp)\n" /* line 326 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb0(%ebp), %ecx\n" /* deltaPart */
        "movl %eax, (%ecx)\n"
        "movzwl %si, %ebx\n" /* sQ2, i */
        "movl %ebx, -0xa4(%ebp)\n" /* i, size */
        "movl %ebx, %edi\n" /* i */
        "jmp .Lfba8b4_000bb4cf\n"
        ".Lfba8b4_000bb89d:\n"
        "xorl %ebx, %ebx\n" /* line 251 | i */
        "jmp .Lfba8b4_000bb905\n"
        /* { scope 2: u */
        ".Lfba8b4_000bb8a1:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 81 */
        "sqrtss %xmm0, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xd4(%ebp)\n"
        "cvttss2si -0xd4(%ebp), %eax\n"
        ".Lfba8b4_000bb8c9:\n"
        "movw %ax, -0x2a(%ebp)\n" /* line 51 */
        "leal (, %ebx, 4), %ecx\n"
        /* } scope */
        "movl -0xb0(%ebp), %edi\n" /* line 254 | deltaPart */
        "movl 4(%edi), %eax\n"
        "movl 4(%eax), %edx\n"
        "movl -0x2c(%ebp), %eax\n" /* quat */
        "movw %ax, (%ecx, %edx)\n"
        "movl 4(%edi), %eax\n" /* line 255 */
        "movl 4(%eax), %edx\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, 2(%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 251 | i */
        "cmpl -0x8c(%ebp), %ebx\n" /* i */
        "je .Lfba8b4_000babea\n"
        /* { scope 2: u */
        /* { scope 3 */
        ".Lfba8b4_000bb905:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 104 | pos */
        "movzwl (%eax), %edx\n"
        "movw %dx, -0x24(%ebp)\n" /* u */
        "addl $2, %eax\n" /* line 105 */
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        "movswl %dx, %eax\n" /* line 106 */
        /* } scope */
        "movw %dx, -0x2c(%ebp)\n" /* line 42 | quat */
        "imull %eax, %eax\n" /* line 46 */
        "movl $0x3fff0001, %edx\n"
        "subl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 48 */
        "jg .Lfba8b4_000bb8a1\n"
        "xorl %eax, %eax\n"
        "jmp .Lfba8b4_000bb8c9\n"
        /* } scope */
        ".Lfba8b4_000bb932:\n"
        "movl $8, (%esp)\n" /* line 245 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb0(%ebp), %ecx\n" /* deltaPart */
        "movl %eax, 4(%ecx)\n"
        "movzwl %si, %ebx\n" /* sQ2, i */
        "movl %ebx, -0x8c(%ebp)\n" /* i */
        "movl %ebx, %edi\n" /* i */
        "jmp .Lfba8b4_000babb4\n"
        /* { scope 2: u */
        /* { scope 3 */
        ".Lfba8b4_000bb955:\n"
        "movzwl 2(%ecx), %edx\n" /* line 104 */
        "movw %dx, -0x24(%ebp)\n" /* u */
        "addl $4, %ecx\n" /* line 105 */
        "movl %ecx, -0x1c(%ebp)\n" /* pos */
        "movswl %dx, %eax\n" /* line 106 */
        /* } scope */
        "movw %dx, -0x2c(%ebp)\n" /* line 42 | quat */
        "imull %eax, %eax\n" /* line 46 */
        "movl $0x3fff0001, %edx\n"
        "subl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 48 */
        "jle .Lfba8b4_000bba56\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 81 */
        "sqrtss %xmm0, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xd0(%ebp)\n"
        "cvttss2si -0xd0(%ebp), %eax\n"
        ".Lfba8b4_000bb9a4:\n"
        "movw %ax, -0x2a(%ebp)\n" /* line 51 */
        /* } scope */
        "movl $8, (%esp)\n" /* line 201 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb0(%ebp), %edx\n" /* deltaPart */
        "movl %eax, 4(%edx)\n"
        "movw $0, (%eax)\n" /* line 202 */
        "movl -0xb0(%ebp), %ecx\n" /* line 203 | deltaPart */
        "movl 4(%ecx), %edx\n"
        "movl -0x2c(%ebp), %eax\n" /* quat */
        "movw %ax, 4(%edx)\n"
        "movl 4(%ecx), %edx\n" /* line 204 */
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, 6(%edx)\n"
        "jmp .Lfba8b4_000bb387\n"
        /* { scope 2: u */
        ".Lfba8b4_000bb9e0:\n"
        "movl 2(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x24(%ebp)\n" /* u */
        "leal 6(%edx), %eax\n" /* line 150 */
        "movl %eax, -0x1c(%ebp)\n" /* pos */
        "movl -0x24(%ebp), %edi\n" /* line 151 | u */
        /* } scope */
        /* { scope 2: u */
        "movl 6(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x24(%ebp)\n" /* u */
        "leal 0xa(%edx), %ecx\n" /* line 150 */
        "movl %ecx, -0x1c(%ebp)\n" /* pos */
        "movl -0x24(%ebp), %esi\n" /* line 151 | u, sQ2 */
        /* } scope */
        /* { scope 2: u */
        "movl 0xa(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x24(%ebp)\n" /* u */
        "addl $0xe, %edx\n" /* line 150 */
        "movl %edx, -0x1c(%ebp)\n" /* pos */
        "movl -0x24(%ebp), %ebx\n" /* line 151 | u, i */
        /* } scope */
        "movl $0x10, (%esp)\n" /* line 283 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0xb0(%ebp), %edx\n" /* deltaPart */
        "movl %eax, (%edx)\n"
        "movw $0, (%eax)\n" /* line 284 */
        "movl (%edx), %eax\n" /* line 285 */
        "leal 4(%eax), %edx\n" /* to */
        /* { scope 2: u */
        "movl %edi, 4(%eax)\n" /* line 199 */
        "movl %esi, 4(%edx)\n" /* line 200 | sQ2 */
        "movl %ebx, 8(%edx)\n" /* line 201 | i */
        "jmp .Lfba8b4_000baa3f\n"
        /* } scope */
        ".Lfba8b4_000bba37:\n"
        "movl %esi, 4(%esp)\n" /* line 136 | sQ2 */
        "movl $0x21fd48, (%esp)\n" /* "^1ERROR: xanim '%s' not found
" */
        "calll Com_Printf\n"
        "movl $0, -0xbc(%ebp)\n" /* parts */
        "jmp .Lfba8b4_000baad7\n"
        /* { scope 2: u */
        ".Lfba8b4_000bba56:\n"
        "xorl %eax, %eax\n" /* line 48 */
        "jmp .Lfba8b4_000bb9a4\n"
    );
}

