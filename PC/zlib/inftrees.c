/* ASM dump from: inftrees.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/inftrees.c */

#include "common_types.h"
#include "imports.h"

static const uInt cplens[31]; /* 0x3070c0 */
static const uInt cplext[31]; /* 0x307040 */
static const uInt cpdist[30]; /* 0x306fc0 */
static const uInt cpdext[30]; /* 0x306f40 */
static uInt fixed_bl; /* 0x315d64 */
static uInt fixed_bd; /* 0x315d60 */
static inflate_huft fixed_tl[512]; /* 0x314d60 */
static inflate_huft fixed_td[32]; /* 0x314c60 */

static int huft_build(uIntf *b, uInt n, uInt s, const uIntf *d, const uIntf *e, inflate_huft * *t, uIntf *m, inflate_huft *hp, uInt *hn, uIntf *v);
int inflate_trees_bits(uIntf *c, uIntf *bb, inflate_huft * *tb, inflate_huft *hp, z_streamp z);
int inflate_trees_dynamic(uInt nl, uInt nd, uIntf *c, uIntf *bl, uIntf *bd, inflate_huft * *tl, inflate_huft * *td, inflate_huft *hp, z_streamp z);
int inflate_trees_fixed(uIntf *bl, uIntf *bd, inflate_huft * *tl, inflate_huft * *td, z_streamp z);

/* line 111 */
static __attribute__((naked))
int huft_build(uIntf *b, uInt n, uInt s, const uIntf *d, const uIntf *e, inflate_huft * *t, uIntf *m, inflate_huft *hp, uInt *hn, uIntf *v)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 111 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x148, %esp\n"
        "movl $0, -0x128(%ebp)\n" /* r */
        "movl $0, -0x124(%ebp)\n"
        "movl %eax, -0x12c(%ebp)\n"
        "movl %edx, -0x130(%ebp)\n"
        "movl %ecx, -0x134(%ebp)\n"
        "movl 0x14(%ebp), %esi\n" /* m */
        "movl $0, -0x84(%ebp)\n" /* line 139 | c */
        "movl $0, -0x80(%ebp)\n"
        "movl $0, -0x7c(%ebp)\n"
        "movl $0, -0x78(%ebp)\n"
        "movl $0, -0x74(%ebp)\n"
        "movl $0, -0x70(%ebp)\n"
        "movl $0, -0x6c(%ebp)\n"
        "movl $0, -0x68(%ebp)\n"
        "movl $0, -0x64(%ebp)\n"
        "movl $0, -0x60(%ebp)\n"
        "movl $0, -0x5c(%ebp)\n"
        "movl $0, -0x58(%ebp)\n"
        "movl $0, -0x54(%ebp)\n"
        "movl $0, -0x50(%ebp)\n"
        "movl $0, -0x4c(%ebp)\n"
        "movl $0, -0x48(%ebp)\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf201318_002013c3:\n"
        "movl (%ecx), %eax\n" /* line 142 */
        "addl $1, -0x84(%ebp, %eax, 4)\n"
        "addl $4, %ecx\n"
        "addl $1, %edx\n"
        "cmpl %edx, -0x130(%ebp)\n" /* line 143 */
        "jne .Lf201318_002013c3\n"
        "movl -0x130(%ebp), %eax\n" /* line 144 */
        "cmpl -0x84(%ebp), %eax\n" /* c */
        "je .Lf201318_002019b9\n"
        "movl (%esi), %ecx\n" /* line 153 | i */
        "movl %ecx, -0x10c(%ebp)\n" /* l */
        "movl $1, -0xd4(%ebp)\n"
        "leal -0x84(%ebp), %edi\n" /* c */
        "movl %edi, -0x138(%ebp)\n"
        "leal -0x80(%ebp), %eax\n"
        ".Lf201318_0020140e:\n"
        "movl (%eax), %edx\n" /* line 155 */
        "testl %edx, %edx\n"
        "jne .Lf201318_00201427\n"
        "addl $1, -0xd4(%ebp)\n" /* line 154 */
        "addl $4, %eax\n"
        "cmpl $0x10, -0xd4(%ebp)\n"
        "jne .Lf201318_0020140e\n"
        ".Lf201318_00201427:\n"
        "movl -0xd4(%ebp), %eax\n" /* line 158 */
        "cmpl %eax, -0x10c(%ebp)\n" /* l */
        "cmovael -0x10c(%ebp), %eax\n" /* l */
        "movl %eax, -0x10c(%ebp)\n" /* l */
        "movl $0xf, -0xe0(%ebp)\n"
        "movl -0x138(%ebp), %eax\n"
        "addl $0x3c, %eax\n"
        ".Lf201318_00201453:\n"
        "movl (%eax), %edi\n" /* line 161 */
        "testl %edi, %edi\n"
        "jne .Lf201318_00201465\n"
        "subl $4, %eax\n" /* line 160 */
        "subl $1, -0xe0(%ebp)\n"
        "jne .Lf201318_00201453\n"
        ".Lf201318_00201465:\n"
        "movl -0x10c(%ebp), %edx\n" /* line 164 | l */
        "movl %edx, -0xfc(%ebp)\n"
        "movl -0xe0(%ebp), %ecx\n"
        "cmpl %ecx, %edx\n"
        "ja .Lf201318_002014db\n"
        "movl %edx, %edi\n"
        "movl %edi, (%esi)\n" /* line 166 | i */
        "movl $1, %esi\n" /* line 170 | i */
        "movzbl -0xd4(%ebp), %ecx\n"
        "shll %cl, %esi\n" /* i */
        "movl -0xe0(%ebp), %edi\n"
        "cmpl %edi, -0xd4(%ebp)\n"
        "jae .Lf201318_00201507\n"
        ".Lf201318_0020149b:\n"
        "movl -0xd4(%ebp), %edx\n" /* line 171 */
        "subl -0x84(%ebp, %edx, 4), %esi\n" /* i */
        "js .Lf201318_002014cc\n"
        "movl -0x138(%ebp), %ecx\n"
        "leal (%ecx, %edx, 4), %edi\n"
        "movl %edx, %eax\n"
        ".Lf201318_002014b5:\n"
        "addl $1, %eax\n" /* line 170 */
        "addl %esi, %esi\n" /* i */
        "cmpl -0xe0(%ebp), %eax\n"
        "je .Lf201318_00201507\n"
        "subl 4(%edi), %esi\n" /* line 171 | i */
        "addl $4, %edi\n"
        "testl %esi, %esi\n" /* i */
        "jns .Lf201318_002014b5\n"
        ".Lf201318_002014cc:\n"
        "movl $0xfffffffd, %eax\n" /* line 292 */
        ".Lf201318_002014d1:\n"
        "addl $0x148, %esp\n" /* line 293 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf201318_002014db:\n"
        "movl %ecx, -0xfc(%ebp)\n" /* line 164 */
        "movl %ecx, -0x10c(%ebp)\n" /* l */
        "movl %ecx, %edi\n"
        "movl %edi, (%esi)\n" /* line 166 | i */
        "movl $1, %esi\n" /* line 170 | i */
        "movzbl -0xd4(%ebp), %ecx\n"
        "shll %cl, %esi\n" /* i */
        "movl -0xe0(%ebp), %edi\n"
        "cmpl %edi, -0xd4(%ebp)\n"
        "jb .Lf201318_0020149b\n"
        ".Lf201318_00201507:\n"
        "movl -0xe0(%ebp), %edx\n" /* line 173 */
        "movl -0x84(%ebp, %edx, 4), %eax\n"
        "subl %eax, %esi\n" /* i */
        "movl %esi, -0x120(%ebp)\n" /* i */
        "js .Lf201318_002014cc\n"
        "addl %esi, %eax\n" /* line 175 | i */
        "movl %eax, -0x84(%ebp, %edx, 4)\n"
        "movl $0, -0xc0(%ebp)\n" /* line 179 */
        "movl -0xe0(%ebp), %edx\n" /* line 181 */
        "subl $1, %edx\n"
        "je .Lf201318_00201557\n"
        "xorl %edi, %edi\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %eax, %eax\n"
        ".Lf201318_00201542:\n"
        "addl -0x80(%eax, %ebp), %edi\n" /* line 182 */
        "movl %edi, -0xbc(%eax, %ebp)\n"
        "addl $1, %esi\n" /* i */
        "addl $4, %eax\n"
        "cmpl %esi, %edx\n" /* line 181 | i */
        "jne .Lf201318_00201542\n"
        ".Lf201318_00201557:\n"
        "movl -0x12c(%ebp), %ecx\n"
        "xorl %esi, %esi\n" /* i */
        ".Lf201318_0020155f:\n"
        "movl (%ecx), %edx\n" /* line 189 */
        "addl $4, %ecx\n"
        "testl %edx, %edx\n"
        "je .Lf201318_0020157f\n"
        "movl -0xc4(%ebp, %edx, 4), %eax\n" /* line 190 */
        "movl 0x20(%ebp), %edi\n" /* v */
        "movl %esi, (%edi, %eax, 4)\n" /* i */
        "addl $1, %eax\n"
        "movl %eax, -0xc4(%ebp, %edx, 4)\n"
        ".Lf201318_0020157f:\n"
        "addl $1, %esi\n" /* line 191 | i */
        "cmpl %esi, -0x130(%ebp)\n" /* i */
        "ja .Lf201318_0020155f\n"
        "movl -0xe0(%ebp), %edx\n" /* line 192 */
        "movl -0xc4(%ebp, %edx, 4), %eax\n"
        "movl $0, -0xc4(%ebp)\n" /* line 196 | x */
        "movl -0x10c(%ebp), %esi\n" /* line 199 | l, i */
        "negl %esi\n" /* i */
        "movl $0, -0x44(%ebp)\n" /* line 200 | u */
        "cmpl %edx, -0xd4(%ebp)\n" /* line 205 */
        "jg .Lf201318_002019fb\n"
        "movl 0x20(%ebp), %ecx\n" /* line 256 | v */
        "leal (%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x11c(%ebp)\n"
        "movl -0xd4(%ebp), %edi\n"
        "movl -0x138(%ebp), %eax\n"
        "leal (%eax, %edi, 4), %edi\n"
        "movl %edi, -0xf0(%ebp)\n"
        "addl $4, %edi\n"
        "movl %edi, -0xec(%ebp)\n"
        "movl %ecx, -0xcc(%ebp)\n"
        "movl -0xd4(%ebp), %eax\n"
        "movl %eax, -0x110(%ebp)\n" /* k */
        "movl $0, -0xdc(%ebp)\n"
        "movl $0xffffffff, -0xe4(%ebp)\n"
        "movl $0, -0x108(%ebp)\n" /* q */
        "movl $0, -0xe8(%ebp)\n"
        ".Lf201318_00201620:\n"
        "movl -0xf0(%ebp), %edx\n" /* line 207 */
        "movl (%edx), %edx\n"
        "movl %edx, -0x118(%ebp)\n" /* a */
        "movl %edx, -0xd0(%ebp)\n"
        ".Lf201318_00201634:\n"
        "subl $1, -0x118(%ebp)\n" /* line 208 | a */
        "cmpl $-1, -0x118(%ebp)\n" /* a */
        "je .Lf201318_002019d4\n"
        "leal -0xc4(%ebp), %eax\n" /* x */
        "movl %eax, -0x13c(%ebp)\n"
        "movl -0xe4(%ebp), %eax\n"
        "shll $2, %eax\n"
        "movl -0x13c(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, -0xf8(%ebp)\n"
        "leal -0x44(%ebp), %ecx\n" /* u */
        "movl %ecx, -0x140(%ebp)\n"
        "addl %ecx, %eax\n"
        "movl %eax, -0xf4(%ebp)\n"
        "movl -0xe4(%ebp), %edi\n"
        "movl %edi, -0x114(%ebp)\n" /* h */
        "movl -0x10c(%ebp), %edi\n" /* line 212 | l */
        "addl %esi, %edi\n" /* i */
        "movl %edi, -0x104(%ebp)\n" /* w */
        "cmpl %edi, -0x110(%ebp)\n" /* k */
        "jle .Lf201318_00201862\n"
        ".Lf201318_002016a2:\n"
        "addl $1, -0x114(%ebp)\n" /* line 214 | h */
        "movl -0xe0(%ebp), %edx\n" /* line 219 */
        "subl -0x104(%ebp), %edx\n" /* w */
        "cmpl -0xfc(%ebp), %edx\n"
        "cmoval -0xfc(%ebp), %edx\n"
        "movl -0x110(%ebp), %ecx\n" /* line 220 | k */
        "subl -0x104(%ebp), %ecx\n" /* w */
        "movl %ecx, -0xd8(%ebp)\n"
        "movl $1, %esi\n" /* i */
        "movl %esi, %edi\n" /* i */
        "shll %cl, %edi\n"
        "movl -0x118(%ebp), %eax\n" /* a */
        "addl $1, %eax\n"
        "cmpl %edi, %eax\n"
        "jae .Lf201318_00201748\n"
        "movl %edi, %eax\n" /* line 222 */
        "subl -0x118(%ebp), %eax\n" /* a */
        "subl $1, %eax\n"
        "cmpl %ecx, %edx\n" /* line 224 */
        "jbe .Lf201318_00201748\n"
        "addl $1, -0xd8(%ebp)\n" /* line 225 */
        "cmpl -0xd8(%ebp), %edx\n"
        "jbe .Lf201318_002019a9\n"
        "addl %eax, %eax\n" /* line 227 */
        "movl -0xec(%ebp), %edi\n"
        "movl (%edi), %ecx\n"
        "cmpl %ecx, %eax\n"
        "jbe .Lf201318_002019a9\n"
        "movl -0xd8(%ebp), %esi\n" /* line 228 | i */
        ".Lf201318_00201724:\n"
        "subl %ecx, %eax\n" /* line 229 */
        "addl $1, %esi\n" /* line 225 | i */
        "cmpl %esi, %edx\n" /* i */
        "je .Lf201318_00201739\n"
        "addl %eax, %eax\n" /* line 227 */
        "movl 4(%edi), %ecx\n"
        "addl $4, %edi\n"
        "cmpl %ecx, %eax\n"
        "ja .Lf201318_00201724\n"
        ".Lf201318_00201739:\n"
        "movl $1, %edi\n" /* line 225 */
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %edi\n"
        "movl %esi, -0xd8(%ebp)\n" /* i */
        ".Lf201318_00201748:\n"
        "movl 0x1c(%ebp), %esi\n" /* line 235 | hn, i */
        "movl (%esi), %eax\n" /* i */
        "leal (%eax, %edi), %edx\n"
        "movl %edx, -0x150(%ebp)\n"
        "cmpl $0x5a0, %edx\n"
        "ja .Lf201318_002014cc\n"
        "movl 0x18(%ebp), %ecx\n" /* line 237 | hp */
        "leal (%ecx, %eax, 8), %eax\n"
        "movl %eax, -0x108(%ebp)\n" /* q */
        "movl -0xe4(%ebp), %esi\n" /* i */
        "leal 4(, %esi, 4), %edx\n"
        "shll $2, %esi\n" /* i */
        "movl %esi, -0x144(%ebp)\n" /* i */
        "movl %edx, %eax\n"
        "subl %esi, %eax\n" /* i */
        "movl %eax, -0x14c(%ebp)\n"
        "movl -0x108(%ebp), %esi\n" /* q, i */
        "movl -0xf4(%ebp), %ecx\n"
        "movl %esi, (%ecx, %eax)\n" /* i */
        "movl -0x150(%ebp), %ecx\n" /* line 238 */
        "movl 0x1c(%ebp), %eax\n" /* hn */
        "movl %ecx, (%eax)\n"
        "movl -0x114(%ebp), %ecx\n" /* line 241 | h */
        "testl %ecx, %ecx\n"
        "je .Lf201318_00201999\n"
        "subl -0x144(%ebp), %edx\n" /* line 243 */
        "movl -0xdc(%ebp), %eax\n"
        "movl -0xf8(%ebp), %esi\n" /* i */
        "movl %eax, (%edx, %esi)\n"
        "movl -0x128(%ebp), %edx\n" /* line 244 | r */
        "movb -0x10c(%ebp), %dh\n" /* l */
        "movl %edx, -0x128(%ebp)\n" /* r */
        "movzbl -0xd8(%ebp), %ecx\n" /* line 245 */
        "movb %cl, -0x128(%ebp)\n" /* r */
        "movl -0x104(%ebp), %ecx\n" /* line 246 | w */
        "subl -0x10c(%ebp), %ecx\n" /* l */
        "movl %eax, %esi\n" /* i */
        "shrl %cl, %esi\n" /* i */
        "movl -0xf4(%ebp), %edx\n" /* line 247 */
        "movl (%edx), %eax\n"
        "movl -0x108(%ebp), %ecx\n" /* q */
        "subl %eax, %ecx\n"
        "sarl $3, %ecx\n"
        "subl %esi, %ecx\n" /* i */
        "movl %ecx, -0x100(%ebp)\n"
        "movl %ecx, -0x124(%ebp)\n" /* line 248 */
        "movl -0x128(%ebp), %edx\n" /* r */
        "movl -0x124(%ebp), %ecx\n"
        "movl %edx, (%eax, %esi, 8)\n"
        "movl %ecx, 4(%eax, %esi, 8)\n"
        ".Lf201318_0020182e:\n"
        "addl $4, -0xf8(%ebp)\n" /* line 251 */
        "addl $4, -0xf4(%ebp)\n"
        "movl %edi, -0xe8(%ebp)\n"
        "movl -0x104(%ebp), %esi\n" /* w, i */
        "movl -0x10c(%ebp), %edi\n" /* line 212 | l */
        "addl %esi, %edi\n" /* i */
        "movl %edi, -0x104(%ebp)\n" /* w */
        "cmpl %edi, -0x110(%ebp)\n" /* k */
        "jg .Lf201318_002016a2\n"
        ".Lf201318_00201862:\n"
        "movzbl -0x110(%ebp), %eax\n" /* line 255 | k */
        "movl %esi, %edx\n" /* i */
        "subb %dl, %al\n"
        "movl -0x128(%ebp), %ecx\n" /* r */
        "movb %al, %ch\n"
        "movl %ecx, -0x128(%ebp)\n" /* r */
        "movl -0x11c(%ebp), %edi\n" /* line 256 */
        "cmpl %edi, -0xcc(%ebp)\n"
        "jb .Lf201318_00201a1e\n"
        "movb $0xc0, -0x128(%ebp)\n" /* line 257 | r */
        ".Lf201318_00201894:\n"
        "movl -0x110(%ebp), %ecx\n" /* line 270 | k */
        "subl %esi, %ecx\n" /* i */
        "movl $1, -0x148(%ebp)\n" /* f */
        "shll %cl, -0x148(%ebp)\n" /* f */
        "movl -0xdc(%ebp), %eax\n" /* line 271 */
        "movl %esi, %ecx\n" /* i */
        "shrl %cl, %eax\n"
        "cmpl -0xe8(%ebp), %eax\n"
        "jae .Lf201318_002018f1\n"
        ".Lf201318_002018be:\n"
        "movl -0x100(%ebp), %edi\n" /* line 272 */
        "movl %edi, -0x124(%ebp)\n"
        "movl -0x128(%ebp), %edx\n" /* r */
        "movl -0x124(%ebp), %ecx\n"
        "movl -0x108(%ebp), %edi\n" /* q */
        "movl %edx, (%edi, %eax, 8)\n"
        "movl %ecx, 4(%edi, %eax, 8)\n"
        "addl -0x148(%ebp), %eax\n" /* line 271 | f */
        "cmpl -0xe8(%ebp), %eax\n"
        "jb .Lf201318_002018be\n"
        ".Lf201318_002018f1:\n"
        "movl -0x110(%ebp), %ecx\n" /* line 275 | k */
        "subl $1, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl %eax, -0xdc(%ebp)\n"
        "je .Lf201318_00201919\n"
        ".Lf201318_00201909:\n"
        "xorl %eax, -0xdc(%ebp)\n" /* line 276 */
        "shrl $1, %eax\n" /* line 275 */
        "testl %eax, -0xdc(%ebp)\n"
        "jne .Lf201318_00201909\n"
        ".Lf201318_00201919:\n"
        "xorl %eax, -0xdc(%ebp)\n" /* line 277 */
        "movl $1, %eax\n" /* line 281 */
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl -0xdc(%ebp), %eax\n"
        "movl -0x114(%ebp), %edi\n" /* h */
        "cmpl -0xc4(%ebp, %edi, 4), %eax\n"
        "je .Lf201318_00201a53\n"
        "movl %edi, -0xe4(%ebp)\n"
        "movl -0x13c(%ebp), %eax\n"
        "leal (%eax, %edi, 4), %eax\n"
        "movl %eax, -0x144(%ebp)\n"
        "movl $1, %edi\n"
        "movl %eax, %ecx\n"
        "jmp .Lf201318_00201968\n"
        ".Lf201318_00201962:\n"
        "movl -0x144(%ebp), %ecx\n"
        ".Lf201318_00201968:\n"
        "subl $1, -0xe4(%ebp)\n" /* line 283 */
        "subl -0x10c(%ebp), %esi\n" /* line 284 | l, i */
        "movl -4(%ecx), %edx\n" /* line 281 */
        "subl $4, %ecx\n"
        "movl %ecx, -0x144(%ebp)\n"
        "movl %edi, %eax\n"
        "movl %esi, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl -0xdc(%ebp), %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf201318_00201962\n"
        "jmp .Lf201318_00201634\n"
        ".Lf201318_00201999:\n"
        "movl -0x108(%ebp), %esi\n" /* line 251 | q, i */
        "movl 0x10(%ebp), %ecx\n" /* t */
        "movl %esi, (%ecx)\n" /* i */
        "jmp .Lf201318_0020182e\n"
        ".Lf201318_002019a9:\n"
        "movl %esi, %edi\n" /* line 228 | i */
        "movzbl -0xd8(%ebp), %ecx\n"
        "shll %cl, %edi\n"
        "jmp .Lf201318_00201748\n"
        ".Lf201318_002019b9:\n"
        "movl 0x10(%ebp), %edx\n" /* line 146 | t */
        "movl $0, (%edx)\n"
        "movl $0, (%esi)\n" /* line 147 | i */
        "xorl %eax, %eax\n"
        "addl $0x148, %esp\n" /* line 293 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf201318_002019d4:\n"
        "addl $1, -0x110(%ebp)\n" /* line 205 | k */
        "addl $4, -0xf0(%ebp)\n"
        "addl $4, -0xec(%ebp)\n"
        "movl -0x110(%ebp), %eax\n" /* k */
        "cmpl %eax, -0xe0(%ebp)\n"
        "jge .Lf201318_00201620\n"
        ".Lf201318_002019fb:\n"
        "movl -0x120(%ebp), %eax\n" /* line 292 */
        "testl %eax, %eax\n"
        "je .Lf201318_00201a12\n"
        "cmpl $1, -0xe0(%ebp)\n"
        "jne .Lf201318_00201a94\n"
        ".Lf201318_00201a12:\n"
        "xorl %eax, %eax\n"
        "addl $0x148, %esp\n" /* line 293 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf201318_00201a1e:\n"
        "movl -0xcc(%ebp), %eax\n" /* line 258 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x100(%ebp)\n"
        "movl -0x134(%ebp), %edx\n"
        "cmpl %edx, %eax\n"
        "jae .Lf201318_00201a5e\n"
        "cmpl $0x100, %eax\n" /* line 260 */
        "sbbl %eax, %eax\n"
        "notb %al\n"
        "andb $0x60, %al\n"
        "movb %al, -0x128(%ebp)\n" /* r */
        "addl $4, -0xcc(%ebp)\n" /* line 261 */
        "jmp .Lf201318_00201894\n"
        ".Lf201318_00201a53:\n"
        "movl %edi, -0xe4(%ebp)\n" /* line 281 */
        "jmp .Lf201318_00201634\n"
        ".Lf201318_00201a5e:\n"
        "subl %edx, -0x100(%ebp)\n" /* line 265 */
        "movl -0x100(%ebp), %edx\n"
        "shll $2, %edx\n"
        "movl 0xc(%ebp), %edi\n" /* e */
        "movzbl (%edx, %edi), %eax\n"
        "addb $0x50, %al\n"
        "movb %al, -0x128(%ebp)\n" /* r */
        "movl 8(%ebp), %eax\n" /* line 266 | d */
        "movl (%edx, %eax), %edx\n"
        "movl %edx, -0x100(%ebp)\n"
        "addl $4, -0xcc(%ebp)\n"
        "jmp .Lf201318_00201894\n"
        ".Lf201318_00201a94:\n"
        "movl $0xfffffffb, %eax\n" /* line 292 */
        "jmp .Lf201318_002014d1\n"
    );
}

/* line 302 */
__attribute__((naked))
int inflate_trees_bits(uIntf *c, uIntf *bb, inflate_huft * *tb, inflate_huft *hp, z_streamp z)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 302 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl $0, -0x1c(%ebp)\n" /* line 304 | hn */
        "movl $4, 8(%esp)\n" /* line 307 */
        "movl $0x13, 4(%esp)\n"
        "movl 0x18(%ebp), %edx\n" /* z */
        "movl 0x28(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x20(%edx)\n"
        "movl %eax, %esi\n" /* v */
        "testl %eax, %eax\n"
        "je .Lf201a9e_00201b6a\n"
        "movl %eax, 0x18(%esp)\n" /* line 309 */
        "leal -0x1c(%ebp), %eax\n" /* hn */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* hp */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* bb */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* tb */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $0x13, %ecx\n"
        "movl $0x13, %edx\n"
        "movl 8(%ebp), %eax\n" /* c */
        "calll huft_build\n"
        "movl %eax, %edi\n" /* r */
        "cmpl $-3, %eax\n" /* line 311 */
        "je .Lf201a9e_00201b5c\n"
        "cmpl $-5, %eax\n" /* line 313 */
        "je .Lf201a9e_00201b49\n"
        "movl 0xc(%ebp), %eax\n" /* bb */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf201a9e_00201b49\n"
        ".Lf201a9e_00201b2f:\n"
        "movl %esi, 4(%esp)\n" /* line 318 | v */
        "movl 0x18(%ebp), %edx\n" /* z */
        "movl 0x28(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%edx)\n"
        "movl %edi, %eax\n" /* line 320 | r */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf201a9e_00201b49:\n"
        "leal 0xb8b50(%ebx), %eax\n" /* line 315 */
        "movl 0x18(%ebp), %edx\n" /* z */
        "movl %eax, 0x18(%edx)\n"
        "movl $0xfffffffd, %edi\n" /* r */
        "jmp .Lf201a9e_00201b2f\n"
        ".Lf201a9e_00201b5c:\n"
        "leal 0xb8b28(%ebx), %eax\n" /* line 312 */
        "movl 0x18(%ebp), %edx\n" /* z */
        "movl %eax, 0x18(%edx)\n"
        "jmp .Lf201a9e_00201b2f\n"
        ".Lf201a9e_00201b6a:\n"
        "movl $0xfffffffc, %edi\n" /* line 307 | r */
        "movl %edi, %eax\n" /* line 320 | r */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 333 */
__attribute__((naked))
int inflate_trees_dynamic(uInt nl, uInt nd, uIntf *c, uIntf *bl, uIntf *bd, inflate_huft * *tl, inflate_huft * *td, inflate_huft *hp, z_streamp z)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 333 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl $0, -0x1c(%ebp)\n" /* line 335 | hn */
        "movl $4, 8(%esp)\n" /* line 339 */
        "movl $0x120, 4(%esp)\n"
        "movl 0x28(%ebp), %edx\n" /* z */
        "movl 0x28(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x20(%edx)\n"
        "movl %eax, %edi\n" /* v */
        "testl %eax, %eax\n"
        "je .Lf201b79_00201c44\n"
        "movl %eax, 0x18(%esp)\n" /* line 343 */
        "leal -0x1c(%ebp), %ecx\n" /* hn */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* hp */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* bl */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x1c(%ebp), %ecx\n" /* tl */
        "movl %ecx, 8(%esp)\n"
        "leal 0x1054b9(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x105539(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "movl $0x101, %ecx\n"
        "movl 8(%ebp), %edx\n" /* nl */
        "movl 0x10(%ebp), %eax\n" /* c */
        "calll huft_build\n"
        "movl %eax, %esi\n" /* r */
        "testl %eax, %eax\n" /* line 344 */
        "jne .Lf201b79_00201c34\n"
        "movl 0x14(%ebp), %eax\n" /* bl */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf201b79_00201c53\n"
        ".Lf201b79_00201c09:\n"
        "leal 0xb8abd(%ebx), %eax\n" /* line 350 */
        "movl 0x28(%ebp), %ecx\n" /* z */
        "movl %eax, 0x18(%ecx)\n"
        "movl $0xfffffffd, %esi\n" /* r */
        ".Lf201b79_00201c1a:\n"
        "movl %edi, 4(%esp)\n" /* line 353 | v */
        "movl 0x28(%ebp), %edx\n" /* z */
        "movl 0x28(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%edx)\n"
        ".Lf201b79_00201c2a:\n"
        "movl %esi, %eax\n" /* line 384 | r */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf201b79_00201c34:\n"
        "cmpl $-3, %eax\n" /* line 346 */
        "je .Lf201b79_00201cc8\n"
        "cmpl $-4, %eax\n" /* line 348 */
        "jne .Lf201b79_00201c09\n"
        "jmp .Lf201b79_00201c1a\n"
        ".Lf201b79_00201c44:\n"
        "movl $0xfffffffc, %esi\n" /* line 339 | r */
        "movl %esi, %eax\n" /* line 384 | r */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf201b79_00201c53:\n"
        "movl 8(%ebp), %ecx\n" /* line 358 | nl */
        "movl 0x10(%ebp), %edx\n" /* c */
        "leal (%edx, %ecx, 4), %eax\n"
        "movl %edi, 0x18(%esp)\n" /* v */
        "movl -0x2c(%ebp), %ecx\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl 0x24(%ebp), %edx\n" /* hp */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x18(%ebp), %ecx\n" /* bd */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x20(%ebp), %edx\n" /* td */
        "movl %edx, 8(%esp)\n"
        "leal 0x1053b9(%ebx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal 0x105439(%ebx), %edx\n"
        "movl %edx, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* nd */
        "calll huft_build\n"
        "movl %eax, %esi\n" /* r */
        "testl %eax, %eax\n" /* line 359 */
        "jne .Lf201b79_00201cd9\n"
        "movl 0x18(%ebp), %ecx\n" /* bd */
        "movl (%ecx), %esi\n" /* r */
        "testl %esi, %esi\n" /* r */
        "jne .Lf201b79_00201cb1\n"
        "cmpl $0x101, 8(%ebp)\n" /* nl */
        "ja .Lf201b79_00201ce8\n"
        ".Lf201b79_00201cb1:\n"
        "movl %edi, 4(%esp)\n" /* line 382 | v */
        "movl 0x28(%ebp), %edx\n" /* z */
        "movl 0x28(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%edx)\n"
        "xorl %esi, %esi\n" /* r */
        "jmp .Lf201b79_00201c2a\n"
        ".Lf201b79_00201cc8:\n"
        "leal 0xb8a99(%ebx), %eax\n" /* line 347 */
        "movl 0x28(%ebp), %edx\n" /* z */
        "movl %eax, 0x18(%edx)\n"
        "jmp .Lf201b79_00201c1a\n"
        ".Lf201b79_00201cd9:\n"
        "cmpl $-3, %eax\n" /* line 361 */
        "je .Lf201b79_00201d0e\n"
        "cmpl $-5, %eax\n" /* line 363 */
        "je .Lf201b79_00201d1c\n"
        "cmpl $-4, %eax\n" /* line 371 */
        "je .Lf201b79_00201cf9\n"
        ".Lf201b79_00201ce8:\n"
        "leal 0xb8b19(%ebx), %eax\n" /* line 373 */
        "movl 0x28(%ebp), %edx\n" /* z */
        "movl %eax, 0x18(%edx)\n"
        "movl $0xfffffffd, %esi\n" /* r */
        ".Lf201b79_00201cf9:\n"
        "movl %edi, 4(%esp)\n" /* line 376 | v */
        "movl 0x28(%ebp), %ecx\n" /* z */
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%ecx)\n"
        "jmp .Lf201b79_00201c2a\n"
        ".Lf201b79_00201d0e:\n"
        "leal 0xb8add(%ebx), %eax\n" /* line 362 */
        "movl 0x28(%ebp), %edx\n" /* z */
        "movl %eax, 0x18(%edx)\n"
        "jmp .Lf201b79_00201cf9\n"
        ".Lf201b79_00201d1c:\n"
        "leal 0xb8afd(%ebx), %eax\n" /* line 368 */
        "movl 0x28(%ebp), %ecx\n" /* z */
        "movl %eax, 0x18(%ecx)\n"
        "movw $0xfffd, %si\n" /* r */
        "jmp .Lf201b79_00201cf9\n"
    );
}

/* line 407 */
__attribute__((naked))
int inflate_trees_fixed(uIntf *bl, uIntf *bd, inflate_huft * *tl, inflate_huft * *td, z_streamp z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 407 */
        "movl %esp, %ebp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 0x11402e(%ecx), %edx\n" /* line 452 */
        "movl 8(%ebp), %eax\n" /* bl */
        "movl %edx, (%eax)\n"
        "movl 0x11402a(%ecx), %edx\n" /* line 453 */
        "movl 0xc(%ebp), %eax\n" /* bd */
        "movl %edx, (%eax)\n"
        "leal 0x11302a(%ecx), %edx\n" /* line 454 */
        "movl 0x10(%ebp), %eax\n" /* tl */
        "movl %edx, (%eax)\n"
        "leal 0x112f2a(%ecx), %edx\n" /* line 455 */
        "movl 0x14(%ebp), %eax\n" /* td */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n" /* line 457 */
        "popl %ebp\n"
        "retl\n"
    );
}

