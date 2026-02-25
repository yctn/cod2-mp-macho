/* ASM dump from: md4.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/md4.cpp */

#include "common_types.h"
#include "imports.h"

static unsigned char PADDING[64]; /* 0x30f5a0 */

static void MD4Transform(UINT4 *state);
void MD4Update(MD4_CTX *context, const unsigned char *input, unsigned int inputLen);
void MD4Final(unsigned char *digest, MD4_CTX *context);
unsigned int Com_BlockChecksumKey(void *buffer, int length, int key);
unsigned int Com_BlockChecksum(const void *buffer, int length);

/* line 173 */
static __attribute__((naked))
void MD4Transform(UINT4 *state)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 173 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl %edx, %edi\n" /* block */
        /* { scope 1 */
        "movl (%eax), %eax\n" /* line 175 */
        "movl %eax, -0x78(%ebp)\n"
        "movl -0x74(%ebp), %eax\n"
        "addl $4, %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl -0x74(%ebp), %eax\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x64(%ebp)\n" /* b */
        "movl -0x74(%ebp), %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0x74(%ebp), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* c */
        "movl -0x74(%ebp), %eax\n"
        "addl $0xc, %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x74(%ebp), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x5c(%ebp)\n" /* d */
        "movl $1, %esi\n"
        ".Lfb664e_000b669c:\n"
        "leal (, %esi, 4), %ebx\n" /* line 173 */
        "leal (%edi, %ebx), %ecx\n" /* block */
        "movzbl -4(%ecx), %edx\n" /* line 264 */
        "movzbl -3(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl -2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl -1(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %edx, -0x5c(%ebp, %ebx)\n"
        "addl $1, %esi\n"
        "cmpl $0x11, %esi\n" /* line 263 */
        "jne .Lfb664e_000b669c\n"
        "movl -0x64(%ebp), %ebx\n" /* line 180 | b */
        "andl -0x60(%ebp), %ebx\n" /* c */
        "movl -0x64(%ebp), %eax\n" /* b */
        "notl %eax\n"
        "andl -0x5c(%ebp), %eax\n" /* d */
        "orl %eax, %ebx\n"
        "addl -0x58(%ebp), %ebx\n" /* x */
        "addl -0x78(%ebp), %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl -0x64(%ebp), %edi\n" /* line 181 | b, block */
        "andl %ebx, %edi\n" /* block */
        "movl %ebx, %eax\n"
        "notl %eax\n"
        "andl -0x60(%ebp), %eax\n" /* c */
        "orl %eax, %edi\n" /* block */
        "addl -0x54(%ebp), %edi\n" /* block */
        "addl -0x5c(%ebp), %edi\n" /* d, block */
        "rorl $0x19, %edi\n" /* block */
        "movl %ebx, %esi\n" /* line 182 */
        "andl %edi, %esi\n" /* block */
        "movl %edi, %eax\n" /* block */
        "notl %eax\n"
        "andl -0x64(%ebp), %eax\n" /* b */
        "orl %eax, %esi\n"
        "addl -0x50(%ebp), %esi\n"
        "addl -0x60(%ebp), %esi\n" /* c */
        "rorl $0x15, %esi\n"
        "movl %edi, %ecx\n" /* line 183 | block */
        "andl %esi, %ecx\n"
        "movl %esi, %eax\n"
        "notl %eax\n"
        "andl %ebx, %eax\n"
        "orl %eax, %ecx\n"
        "addl -0x4c(%ebp), %ecx\n"
        "addl -0x64(%ebp), %ecx\n" /* b */
        "rorl $0xd, %ecx\n"
        "movl %esi, %edx\n" /* line 184 */
        "andl %ecx, %edx\n"
        "movl %ecx, %eax\n"
        "notl %eax\n"
        "andl %edi, %eax\n" /* block */
        "orl %eax, %edx\n"
        "addl -0x48(%ebp), %edx\n"
        "addl %edx, %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %ecx, %edx\n" /* line 185 */
        "andl %ebx, %edx\n"
        "movl %ebx, %eax\n"
        "notl %eax\n"
        "andl %esi, %eax\n"
        "orl %eax, %edx\n"
        "addl -0x44(%ebp), %edx\n"
        "addl %edx, %edi\n" /* block */
        "rorl $0x19, %edi\n" /* block */
        "movl %ebx, %edx\n" /* line 186 */
        "andl %edi, %edx\n" /* block */
        "movl %edi, %eax\n" /* block */
        "notl %eax\n"
        "andl %ecx, %eax\n"
        "orl %eax, %edx\n"
        "addl -0x40(%ebp), %edx\n"
        "addl %edx, %esi\n"
        "rorl $0x15, %esi\n"
        "movl %edi, %edx\n" /* line 187 | block */
        "andl %esi, %edx\n"
        "movl %esi, %eax\n"
        "notl %eax\n"
        "andl %ebx, %eax\n"
        "orl %eax, %edx\n"
        "addl -0x3c(%ebp), %edx\n"
        "addl %edx, %ecx\n"
        "rorl $0xd, %ecx\n"
        "movl %esi, %edx\n" /* line 188 */
        "andl %ecx, %edx\n"
        "movl %ecx, %eax\n"
        "notl %eax\n"
        "andl %edi, %eax\n" /* block */
        "orl %eax, %edx\n"
        "addl -0x38(%ebp), %edx\n"
        "addl %edx, %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %ecx, %edx\n" /* line 189 */
        "andl %ebx, %edx\n"
        "movl %ebx, %eax\n"
        "notl %eax\n"
        "andl %esi, %eax\n"
        "orl %eax, %edx\n"
        "addl -0x34(%ebp), %edx\n"
        "addl %edx, %edi\n" /* block */
        "rorl $0x19, %edi\n" /* block */
        "movl %ebx, %edx\n" /* line 190 */
        "andl %edi, %edx\n" /* block */
        "movl %edi, %eax\n" /* block */
        "notl %eax\n"
        "andl %ecx, %eax\n"
        "orl %eax, %edx\n"
        "addl -0x30(%ebp), %edx\n"
        "addl %edx, %esi\n"
        "rorl $0x15, %esi\n"
        "movl %edi, %edx\n" /* line 191 | block */
        "andl %esi, %edx\n"
        "movl %esi, %eax\n"
        "notl %eax\n"
        "andl %ebx, %eax\n"
        "orl %eax, %edx\n"
        "addl -0x2c(%ebp), %edx\n"
        "addl %edx, %ecx\n"
        "rorl $0xd, %ecx\n"
        "movl %esi, %edx\n" /* line 192 */
        "andl %ecx, %edx\n"
        "movl %ecx, %eax\n"
        "notl %eax\n"
        "andl %edi, %eax\n" /* block */
        "orl %eax, %edx\n"
        "addl -0x28(%ebp), %edx\n"
        "addl %edx, %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %ecx, %edx\n" /* line 193 */
        "andl %ebx, %edx\n"
        "movl %ebx, %eax\n"
        "notl %eax\n"
        "andl %esi, %eax\n"
        "orl %eax, %edx\n"
        "addl -0x24(%ebp), %edx\n"
        "addl %edx, %edi\n" /* block */
        "rorl $0x19, %edi\n" /* block */
        "movl %ebx, %edx\n" /* line 194 */
        "andl %edi, %edx\n" /* block */
        "movl %edi, %eax\n" /* block */
        "notl %eax\n"
        "andl %ecx, %eax\n"
        "orl %eax, %edx\n"
        "addl -0x20(%ebp), %edx\n"
        "addl %edx, %esi\n"
        "rorl $0x15, %esi\n"
        "movl %edi, %edx\n" /* line 195 | block */
        "andl %esi, %edx\n"
        "movl %esi, %eax\n"
        "notl %eax\n"
        "andl %ebx, %eax\n"
        "orl %edx, %eax\n"
        "addl -0x1c(%ebp), %eax\n"
        "addl %eax, %ecx\n"
        "rorl $0xd, %ecx\n"
        "movl %edi, %eax\n" /* line 198 | block */
        "orl %esi, %eax\n"
        "andl %ecx, %eax\n"
        "orl %eax, %edx\n"
        "addl -0x58(%ebp), %edx\n" /* x */
        "leal 0x5a827999(%ebx, %edx), %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %esi, %eax\n" /* line 199 */
        "orl %ecx, %eax\n"
        "andl %ebx, %eax\n"
        "movl %esi, %edx\n"
        "andl %ecx, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x48(%ebp), %eax\n"
        "leal 0x5a827999(%edi, %eax), %edi\n" /* block */
        "rorl $0x1b, %edi\n" /* block */
        "movl %ecx, %eax\n" /* line 200 */
        "orl %ebx, %eax\n"
        "andl %edi, %eax\n" /* block */
        "movl %ecx, %edx\n"
        "andl %ebx, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x38(%ebp), %eax\n"
        "leal 0x5a827999(%esi, %eax), %esi\n"
        "rorl $0x17, %esi\n"
        "movl %ebx, %eax\n" /* line 201 */
        "orl %edi, %eax\n" /* block */
        "andl %esi, %eax\n"
        "movl %ebx, %edx\n"
        "andl %edi, %edx\n" /* block */
        "orl %edx, %eax\n"
        "addl -0x28(%ebp), %eax\n"
        "leal 0x5a827999(%ecx, %eax), %ecx\n"
        "rorl $0x13, %ecx\n"
        "movl %edi, %eax\n" /* line 202 | block */
        "orl %esi, %eax\n"
        "andl %ecx, %eax\n"
        "movl %edi, %edx\n" /* block */
        "andl %esi, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x54(%ebp), %eax\n"
        "leal 0x5a827999(%ebx, %eax), %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %esi, %eax\n" /* line 203 */
        "orl %ecx, %eax\n"
        "andl %ebx, %eax\n"
        "movl %esi, %edx\n"
        "andl %ecx, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x44(%ebp), %eax\n"
        "leal 0x5a827999(%edi, %eax), %edi\n" /* block */
        "rorl $0x1b, %edi\n" /* block */
        "movl %ecx, %eax\n" /* line 204 */
        "orl %ebx, %eax\n"
        "andl %edi, %eax\n" /* block */
        "movl %ecx, %edx\n"
        "andl %ebx, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x34(%ebp), %eax\n"
        "leal 0x5a827999(%esi, %eax), %esi\n"
        "rorl $0x17, %esi\n"
        "movl %ebx, %eax\n" /* line 205 */
        "orl %edi, %eax\n" /* block */
        "andl %esi, %eax\n"
        "movl %ebx, %edx\n"
        "andl %edi, %edx\n" /* block */
        "orl %edx, %eax\n"
        "addl -0x24(%ebp), %eax\n"
        "leal 0x5a827999(%ecx, %eax), %ecx\n"
        "rorl $0x13, %ecx\n"
        "movl %edi, %eax\n" /* line 206 | block */
        "orl %esi, %eax\n"
        "andl %ecx, %eax\n"
        "movl %edi, %edx\n" /* block */
        "andl %esi, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x50(%ebp), %eax\n"
        "leal 0x5a827999(%ebx, %eax), %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %esi, %eax\n" /* line 207 */
        "orl %ecx, %eax\n"
        "andl %ebx, %eax\n"
        "movl %esi, %edx\n"
        "andl %ecx, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x40(%ebp), %eax\n"
        "leal 0x5a827999(%edi, %eax), %edi\n" /* block */
        "rorl $0x1b, %edi\n" /* block */
        "movl %ecx, %eax\n" /* line 208 */
        "orl %ebx, %eax\n"
        "andl %edi, %eax\n" /* block */
        "movl %ecx, %edx\n"
        "andl %ebx, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x30(%ebp), %eax\n"
        "leal 0x5a827999(%esi, %eax), %esi\n"
        "rorl $0x17, %esi\n"
        "movl %ebx, %eax\n" /* line 209 */
        "orl %edi, %eax\n" /* block */
        "andl %esi, %eax\n"
        "movl %ebx, %edx\n"
        "andl %edi, %edx\n" /* block */
        "orl %edx, %eax\n"
        "addl -0x20(%ebp), %eax\n"
        "leal 0x5a827999(%ecx, %eax), %ecx\n"
        "rorl $0x13, %ecx\n"
        "movl %edi, %eax\n" /* line 210 | block */
        "orl %esi, %eax\n"
        "andl %ecx, %eax\n"
        "movl %edi, %edx\n" /* block */
        "andl %esi, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x4c(%ebp), %eax\n"
        "leal 0x5a827999(%ebx, %eax), %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %esi, %eax\n" /* line 211 */
        "orl %ecx, %eax\n"
        "andl %ebx, %eax\n"
        "movl %esi, %edx\n"
        "andl %ecx, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x3c(%ebp), %eax\n"
        "leal 0x5a827999(%edi, %eax), %edi\n" /* block */
        "rorl $0x1b, %edi\n" /* block */
        "movl %ecx, %eax\n" /* line 212 */
        "orl %ebx, %eax\n"
        "andl %edi, %eax\n" /* block */
        "movl %ecx, %edx\n"
        "andl %ebx, %edx\n"
        "orl %edx, %eax\n"
        "addl -0x2c(%ebp), %eax\n"
        "leal 0x5a827999(%esi, %eax), %esi\n"
        "rorl $0x17, %esi\n"
        "movl %ebx, %eax\n" /* line 213 */
        "orl %edi, %eax\n" /* block */
        "andl %esi, %eax\n"
        "movl %ebx, %edx\n"
        "andl %edi, %edx\n" /* block */
        "orl %edx, %eax\n"
        "addl -0x1c(%ebp), %eax\n"
        "leal 0x5a827999(%ecx, %eax), %ecx\n"
        "rorl $0x13, %ecx\n"
        "movl %esi, %eax\n" /* line 216 */
        "xorl %ecx, %eax\n"
        "xorl %edi, %eax\n" /* block */
        "addl -0x58(%ebp), %eax\n" /* x */
        "leal 0x6ed9eba1(%ebx, %eax), %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %ecx, %eax\n" /* line 217 */
        "xorl %ebx, %eax\n"
        "xorl %esi, %eax\n"
        "addl -0x38(%ebp), %eax\n"
        "leal 0x6ed9eba1(%edi, %eax), %edi\n" /* block */
        "rorl $0x17, %edi\n" /* block */
        "movl %ebx, %eax\n" /* line 218 */
        "xorl %edi, %eax\n" /* block */
        "xorl %ecx, %eax\n"
        "addl -0x48(%ebp), %eax\n"
        "leal 0x6ed9eba1(%esi, %eax), %esi\n"
        "rorl $0x15, %esi\n"
        "movl %edi, %eax\n" /* line 219 | block */
        "xorl %esi, %eax\n"
        "xorl %ebx, %eax\n"
        "addl -0x28(%ebp), %eax\n"
        "leal 0x6ed9eba1(%ecx, %eax), %ecx\n"
        "rorl $0x11, %ecx\n"
        "movl %esi, %eax\n" /* line 220 */
        "xorl %ecx, %eax\n"
        "xorl %edi, %eax\n" /* block */
        "addl -0x50(%ebp), %eax\n"
        "leal 0x6ed9eba1(%ebx, %eax), %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %ecx, %eax\n" /* line 221 */
        "xorl %ebx, %eax\n"
        "xorl %esi, %eax\n"
        "addl -0x30(%ebp), %eax\n"
        "leal 0x6ed9eba1(%edi, %eax), %edi\n" /* block */
        "rorl $0x17, %edi\n" /* block */
        "movl %ebx, %eax\n" /* line 222 */
        "xorl %edi, %eax\n" /* block */
        "xorl %ecx, %eax\n"
        "addl -0x40(%ebp), %eax\n"
        "leal 0x6ed9eba1(%esi, %eax), %esi\n"
        "rorl $0x15, %esi\n"
        "movl %edi, %eax\n" /* line 223 | block */
        "xorl %esi, %eax\n"
        "xorl %ebx, %eax\n"
        "addl -0x20(%ebp), %eax\n"
        "leal 0x6ed9eba1(%ecx, %eax), %ecx\n"
        "rorl $0x11, %ecx\n"
        "movl %esi, %eax\n" /* line 224 */
        "xorl %ecx, %eax\n"
        "xorl %edi, %eax\n" /* block */
        "addl -0x54(%ebp), %eax\n"
        "leal 0x6ed9eba1(%ebx, %eax), %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %ecx, %eax\n" /* line 225 */
        "xorl %ebx, %eax\n"
        "xorl %esi, %eax\n"
        "addl -0x34(%ebp), %eax\n"
        "leal 0x6ed9eba1(%edi, %eax), %edi\n" /* block */
        "rorl $0x17, %edi\n" /* block */
        "movl %ebx, %eax\n" /* line 226 */
        "xorl %edi, %eax\n" /* block */
        "xorl %ecx, %eax\n"
        "addl -0x44(%ebp), %eax\n"
        "leal 0x6ed9eba1(%esi, %eax), %esi\n"
        "rorl $0x15, %esi\n"
        "movl %edi, %eax\n" /* line 227 | block */
        "xorl %esi, %eax\n"
        "xorl %ebx, %eax\n"
        "addl -0x24(%ebp), %eax\n"
        "leal 0x6ed9eba1(%ecx, %eax), %ecx\n"
        "rorl $0x11, %ecx\n"
        "movl %esi, %eax\n" /* line 228 */
        "xorl %ecx, %eax\n"
        "xorl %edi, %eax\n" /* block */
        "addl -0x4c(%ebp), %eax\n"
        "leal 0x6ed9eba1(%ebx, %eax), %ebx\n"
        "rorl $0x1d, %ebx\n"
        "movl %ecx, %eax\n" /* line 229 */
        "xorl %ebx, %eax\n"
        "xorl %esi, %eax\n"
        "addl -0x2c(%ebp), %eax\n"
        "leal 0x6ed9eba1(%edi, %eax), %edi\n" /* block */
        "rorl $0x17, %edi\n" /* block */
        "movl %ebx, %eax\n" /* line 230 */
        "xorl %edi, %eax\n" /* block */
        "xorl %ecx, %eax\n"
        "addl -0x3c(%ebp), %eax\n"
        "leal 0x6ed9eba1(%esi, %eax), %esi\n"
        "rorl $0x15, %esi\n"
        "movl %edi, %eax\n" /* line 231 | block */
        "xorl %esi, %eax\n"
        "xorl %ebx, %eax\n"
        "addl -0x1c(%ebp), %eax\n"
        "leal 0x6ed9eba1(%ecx, %eax), %ecx\n"
        "addl -0x78(%ebp), %ebx\n" /* line 233 */
        "movl -0x74(%ebp), %eax\n"
        "movl %ebx, (%eax)\n"
        "rorl $0x11, %ecx\n" /* line 234 */
        "movl -0x70(%ebp), %eax\n"
        "addl %ecx, (%eax)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 235 */
        "addl %esi, (%eax)\n"
        "movl -0x68(%ebp), %eax\n" /* line 236 */
        "addl %edi, (%eax)\n" /* block */
        "movl $0x40, 8(%esp)\n" /* line 239 */
        "movl $0, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll Com_Memset\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 240 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 113 */
__attribute__((naked))
void MD4Update(MD4_CTX *context, const unsigned char *input, unsigned int inputLen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 113 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* context */
        "movl %eax, -0x1c(%ebp)\n" /* context */
        "movl 0xc(%ebp), %edx\n" /* input */
        "movl %edx, -0x20(%ebp)\n" /* input */
        "movl 0x10(%ebp), %edi\n" /* inputLen */
        /* { scope 1 */
        "movl %eax, %ebx\n" /* line 118 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, %ecx\n"
        "shrl $3, %ecx\n"
        "andl $0x3f, %ecx\n"
        "leal (, %edi, 8), %edx\n" /* line 121 */
        "addl %edx, %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "cmpl %eax, %edx\n"
        "jbe .Lfb6b12_000b6b8f\n"
        "movl 0x14(%ebx), %edx\n" /* line 122 */
        "addl $1, %edx\n"
        "movl %edx, 0x14(%ebx)\n"
        "movl %edi, %eax\n" /* line 124 | inputLen */
        "shrl $0x1d, %eax\n"
        "addl %edx, %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* context */
        "movl %eax, 0x14(%edx)\n"
        "movl $0x40, %esi\n" /* line 126 | partLen */
        "subl %ecx, %esi\n" /* partLen */
        "cmpl %esi, %edi\n" /* line 129 | partLen, inputLen */
        "jae .Lfb6b12_000b6bad\n"
        ".Lfb6b12_000b6b68:\n"
        "xorl %eax, %eax\n"
        "xorl %edx, %edx\n"
        "subl %eax, %edi\n" /* line 143 | inputLen */
        "movl %edi, 0x10(%ebp)\n" /* inputLen */
        "movl -0x20(%ebp), %eax\n" /* input */
        "addl %edx, %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* input */
        "movl -0x1c(%ebp), %edx\n" /* context */
        "leal 0x18(%ecx, %edx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* context */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 144 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Memcpy\n" /* line 143 */
        ".Lfb6b12_000b6b8f:\n"
        "movl -0x1c(%ebp), %eax\n" /* context */
        "movl 0x14(%eax), %edx\n"
        "movl %edi, %eax\n" /* line 124 | inputLen */
        "shrl $0x1d, %eax\n"
        "addl %edx, %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* context */
        "movl %eax, 0x14(%edx)\n"
        "movl $0x40, %esi\n" /* line 126 | partLen */
        "subl %ecx, %esi\n" /* partLen */
        "cmpl %esi, %edi\n" /* line 129 | partLen, inputLen */
        "jb .Lfb6b12_000b6b68\n"
        ".Lfb6b12_000b6bad:\n"
        "movl %esi, 8(%esp)\n" /* line 131 | partLen */
        "movl -0x20(%ebp), %ebx\n" /* input */
        "movl %ebx, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* context */
        "leal 0x18(%ecx, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl -0x1c(%ebp), %edx\n" /* line 132 | context */
        "addl $0x18, %edx\n"
        "movl -0x1c(%ebp), %eax\n" /* context */
        "calll MD4Transform\n"
        "leal 0x3f(%esi), %eax\n" /* line 134 | partLen */
        "cmpl %eax, %edi\n" /* inputLen */
        "ja .Lfb6b12_000b6c05\n"
        "movl %esi, %edx\n" /* partLen */
        "movl %esi, %eax\n" /* partLen */
        "xorl %ecx, %ecx\n"
        "subl %eax, %edi\n" /* line 143 | inputLen */
        "movl %edi, 0x10(%ebp)\n" /* inputLen */
        "movl -0x20(%ebp), %eax\n" /* input */
        "addl %edx, %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* input */
        "movl -0x1c(%ebp), %edx\n" /* context */
        "leal 0x18(%ecx, %edx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* context */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 144 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Memcpy\n" /* line 143 */
        ".Lfb6b12_000b6c05:\n"
        "movl -0x20(%ebp), %eax\n" /* line 134 | input */
        "leal (%esi, %eax), %ebx\n" /* partLen */
        "addl $0x7f, %esi\n" /* partLen */
        "jmp .Lfb6b12_000b6c13\n"
        ".Lfb6b12_000b6c10:\n"
        "addl $0x40, %esi\n" /* partLen */
        ".Lfb6b12_000b6c13:\n"
        "movl %ebx, %edx\n" /* line 135 */
        "movl -0x1c(%ebp), %eax\n" /* context */
        "calll MD4Transform\n"
        "addl $0x40, %ebx\n"
        "cmpl %esi, %edi\n" /* line 134 | partLen, inputLen */
        "ja .Lfb6b12_000b6c10\n"
        "leal -0x3f(%esi), %eax\n" /* partLen */
        "movl %eax, %edx\n"
        "xorl %ecx, %ecx\n"
        "subl %eax, %edi\n" /* line 143 | inputLen */
        "movl %edi, 0x10(%ebp)\n" /* inputLen */
        "movl -0x20(%ebp), %eax\n" /* input */
        "addl %edx, %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* input */
        "movl -0x1c(%ebp), %edx\n" /* context */
        "leal 0x18(%ecx, %edx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* context */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 144 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Memcpy\n" /* line 143 */
    );
}

/* line 148 */
__attribute__((naked))
void MD4Final(unsigned char *digest, MD4_CTX *context)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 148 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* context */
        /* { scope 1 */
        "leal 0x10(%esi), %edi\n" /* line 154 | context, input */
        "movl $1, %ebx\n"
        ".Lfb6c4e_000b6c62:\n"
        "leal (, %ebx, 4), %edx\n" /* line 148 */
        "leal (%edx, %edi), %ecx\n"
        "leal -0x20(%ebp), %eax\n" /* bits */
        "leal (%eax, %edx), %edx\n"
        /* { scope 2 */
        "movl -4(%ecx), %eax\n" /* line 250 */
        "movb %al, -4(%edx)\n"
        "movl -4(%ecx), %eax\n" /* line 251 */
        "shrl $8, %eax\n"
        "movb %al, -3(%edx)\n"
        "movzwl -2(%ecx), %eax\n" /* line 252 */
        "movb %al, -2(%edx)\n"
        "movzbl -1(%ecx), %eax\n" /* line 253 */
        "movb %al, -1(%edx)\n"
        "addl $1, %ebx\n"
        "cmpl $3, %ebx\n" /* line 248 */
        "jne .Lfb6c4e_000b6c62\n"
        /* } scope */
        "movl 0x10(%esi), %eax\n" /* line 157 | context */
        "shrl $3, %eax\n"
        "andl $0x3f, %eax\n"
        "cmpl $0x37, %eax\n" /* line 158 */
        "ja .Lfb6c4e_000b6d32\n"
        "movl $0x38, %edx\n"
        "subl %eax, %edx\n"
        ".Lfb6c4e_000b6cb0:\n"
        "movl %edx, 8(%esp)\n" /* line 159 */
        "movl $PADDING, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* context */
        "calll MD4Update\n"
        "movl $8, 8(%esp)\n" /* line 162 */
        "leal -0x20(%ebp), %eax\n" /* bits */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* context */
        "calll MD4Update\n"
        "movl $1, %ebx\n" /* line 165 */
        ".Lfb6c4e_000b6ce0:\n"
        "leal (, %ebx, 4), %edx\n" /* line 148 */
        "leal (%esi, %edx), %ecx\n" /* context */
        "addl 8(%ebp), %edx\n" /* digest */
        "movl -4(%ecx), %eax\n" /* line 250 */
        "movb %al, -4(%edx)\n"
        "movl -4(%ecx), %eax\n" /* line 251 */
        "shrl $8, %eax\n"
        "movb %al, -3(%edx)\n"
        "movzwl -2(%ecx), %eax\n" /* line 252 */
        "movb %al, -2(%edx)\n"
        "movzbl -1(%ecx), %eax\n" /* line 253 */
        "movb %al, -1(%edx)\n"
        "addl $1, %ebx\n"
        "cmpl $5, %ebx\n" /* line 248 */
        "jne .Lfb6c4e_000b6ce0\n"
        "movl $0x58, 8(%esp)\n" /* line 168 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* context */
        "calll Com_Memset\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 169 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb6c4e_000b6d32:\n"
        "movl $0x78, %edx\n" /* line 158 */
        "subl %eax, %edx\n"
        "jmp .Lfb6c4e_000b6cb0\n"
    );
}

/* line 286 */
__attribute__((naked))
unsigned int Com_BlockChecksumKey(void *buffer, int length, int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 286 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x84, %esp\n"
        /* { scope 1 */
        "movl $0, -0x5c(%ebp)\n" /* line 102 */
        "movl $0, -0x60(%ebp)\n"
        "movl $0x67452301, -0x70(%ebp)\n" /* line 105 | ctx */
        "movl $0xefcdab89, -0x6c(%ebp)\n" /* line 106 */
        "movl $0x98badcfe, -0x68(%ebp)\n" /* line 107 */
        "movl $0x10325476, -0x64(%ebp)\n" /* line 108 */
        "leal 0x10(%ebp), %eax\n" /* line 293 | key */
        "movl $4, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x70(%ebp), %ebx\n" /* ctx */
        "movl %ebx, (%esp)\n"
        "calll MD4Update\n"
        "movl 0xc(%ebp), %eax\n" /* line 294 | length */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* buffer */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MD4Update\n"
        "leal -0x18(%ebp), %eax\n" /* line 295 | digest */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MD4Final\n"
        "movl -0x18(%ebp), %eax\n" /* digest */
        "xorl -0x14(%ebp), %eax\n"
        "xorl -0x10(%ebp), %eax\n"
        "xorl -0xc(%ebp), %eax\n"
        /* } scope */
        "addl $0x84, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 270 */
__attribute__((naked))
unsigned int Com_BlockChecksum(const void *buffer, int length)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 270 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x84, %esp\n"
        /* { scope 1 */
        "movl $0, -0x5c(%ebp)\n" /* line 102 */
        "movl $0, -0x60(%ebp)\n"
        "movl $0x67452301, -0x70(%ebp)\n" /* line 105 | ctx */
        "movl $0xefcdab89, -0x6c(%ebp)\n" /* line 106 */
        "movl $0x98badcfe, -0x68(%ebp)\n" /* line 107 */
        "movl $0x10325476, -0x64(%ebp)\n" /* line 108 */
        "movl 0xc(%ebp), %eax\n" /* line 277 | length */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* buffer */
        "movl %eax, 4(%esp)\n"
        "leal -0x70(%ebp), %ebx\n" /* ctx */
        "movl %ebx, (%esp)\n"
        "calll MD4Update\n"
        "leal -0x18(%ebp), %eax\n" /* line 278 | digest */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MD4Final\n"
        "movl -0x18(%ebp), %eax\n" /* digest */
        "xorl -0x14(%ebp), %eax\n"
        "xorl -0x10(%ebp), %eax\n"
        "xorl -0xc(%ebp), %eax\n"
        /* } scope */
        "addl $0x84, %esp\n" /* line 283 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

