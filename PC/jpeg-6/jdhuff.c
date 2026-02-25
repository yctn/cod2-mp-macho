/* ASM dump from: jdhuff.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdhuff.c */

#include "common_types.h"
#include "imports.h"

static const int extend_test[16]; /* 0x3073e0 */
static const int extend_offset[16]; /* 0x3073a0 */

void jpeg_make_d_derived_tbl(j_decompress_ptr cinfo, int isDC, int tblno, d_derived_tbl * *pdtbl);
static void start_pass_huff_decoder(j_decompress_ptr cinfo);
boolean jpeg_fill_bit_buffer(bitread_working_state *state, bit_buf_type get_buffer, int bits_left, int nbits);
int jpeg_huff_decode(bitread_working_state *state, bit_buf_type get_buffer, int bits_left, d_derived_tbl *htbl, int min_bits);
void jinit_huff_decoder(j_decompress_ptr cinfo);
static boolean decode_mcu(j_decompress_ptr cinfo, JBLOCKROW *MCU_data);

/* line 151 */
__attribute__((naked))
void jpeg_make_d_derived_tbl(j_decompress_ptr cinfo, int isDC, int tblno, d_derived_tbl * *pdtbl)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 151 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x560, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* tblno */
        "movl 0x14(%ebp), %edi\n" /* pdtbl */
        "movzbl 0xc(%ebp), %eax\n" /* isDC */
        "movb %al, -0x549(%ebp)\n" /* isDC */
        "cmpl $3, %esi\n" /* line 165 | code */
        "ja .Lf206df8_0020723f\n"
        ".Lf206df8_00206e1c:\n"
        "cmpb $0, -0x549(%ebp)\n" /* line 167 | isDC */
        "je .Lf206df8_002071db\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0xa8(%ecx, %esi, 4), %ecx\n"
        "movl %ecx, -0x548(%ebp)\n" /* htbl */
        "movl -0x548(%ebp), %eax\n" /* line 169 | htbl */
        "testl %eax, %eax\n"
        "je .Lf206df8_002071f9\n"
        ".Lf206df8_00206e47:\n"
        "movl (%edi), %ecx\n" /* line 173 | l */
        "testl %ecx, %ecx\n"
        "je .Lf206df8_0020721b\n"
        ".Lf206df8_00206e51:\n"
        "movl (%edi), %edi\n" /* l */
        ".Lf206df8_00206e53:\n"
        "movl %edi, -0x544(%ebp)\n" /* line 177 | l, dtbl */
        "movl -0x548(%ebp), %eax\n" /* line 178 | htbl */
        "movl %eax, 0x8c(%edi)\n" /* l */
        "movl %eax, -0x528(%ebp)\n"
        "movl $0, -0x51c(%ebp)\n"
        "movl $1, %edi\n" /* l */
        "movl %eax, %edx\n"
        ".Lf206df8_00206e7c:\n"
        "movzbl 1(%edx), %esi\n" /* line 184 | code */
        "movl -0x51c(%ebp), %ecx\n" /* line 185 */
        "leal (%esi, %ecx), %eax\n" /* code */
        "cmpl $0x100, %eax\n"
        "jle .Lf206df8_00206ea3\n"
        "movl 8(%ebp), %edx\n" /* line 186 | cinfo */
        "movl (%edx), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf206df8_00206ea3:\n"
        "testl %esi, %esi\n" /* line 187 | code */
        "je .Lf206df8_00206ecb\n"
        "movl -0x51c(%ebp), %ecx\n"
        "leal -0x109(%ebp, %ecx), %eax\n"
        "xorl %edx, %edx\n"
        ".Lf206df8_00206eb6:\n"
        "movl %edi, %ecx\n" /* line 188 | l */
        "movb %cl, (%eax)\n"
        "addl $1, -0x51c(%ebp)\n"
        "addl $1, %edx\n"
        "addl $1, %eax\n"
        "cmpl %esi, %edx\n" /* line 187 | code */
        "jne .Lf206df8_00206eb6\n"
        ".Lf206df8_00206ecb:\n"
        "addl $1, %edi\n" /* line 183 | l */
        "addl $1, -0x528(%ebp)\n"
        "cmpl $0x11, %edi\n" /* l */
        "je .Lf206df8_00206ee2\n"
        "movl -0x528(%ebp), %edx\n"
        "jmp .Lf206df8_00206e7c\n"
        ".Lf206df8_00206ee2:\n"
        "movl -0x51c(%ebp), %esi\n" /* line 190 | code */
        "movb $0, -0x109(%ebp, %esi)\n"
        "movzbl -0x109(%ebp), %eax\n" /* line 197 | huffsize */
        "movsbl %al, %edx\n"
        "movl %edx, -0x538(%ebp)\n" /* si */
        "testb %al, %al\n" /* line 199 */
        "je .Lf206df8_00206f89\n"
        "movl $0, -0x540(%ebp)\n" /* p */
        "xorl %esi, %esi\n" /* code */
        "movl -0x540(%ebp), %eax\n" /* p */
        "jmp .Lf206df8_00206f37\n"
        ".Lf206df8_00206f1c:\n"
        "addl %esi, %esi\n" /* line 209 | code */
        "addl $1, -0x538(%ebp)\n" /* line 210 | si */
        "movl -0x540(%ebp), %ecx\n" /* line 199 | p */
        "cmpb $0, -0x109(%ebp, %ecx)\n"
        "je .Lf206df8_00206f89\n"
        ".Lf206df8_00206f35:\n"
        "movl %ecx, %eax\n"
        ".Lf206df8_00206f37:\n"
        "movsbl -0x109(%ebp, %eax), %edi\n" /* line 200 | l */
        "cmpl -0x538(%ebp), %edi\n" /* si, l */
        "je .Lf206df8_0020710f\n"
        ".Lf206df8_00206f4b:\n"
        "movl $1, %eax\n" /* line 207 */
        "movzbl -0x538(%ebp), %ecx\n" /* si */
        "shll %cl, %eax\n"
        "cmpl %eax, %esi\n" /* code */
        "jl .Lf206df8_00206f1c\n"
        "movl 8(%ebp), %edx\n" /* line 208 | cinfo */
        "movl (%edx), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "addl %esi, %esi\n" /* line 209 | code */
        "addl $1, -0x538(%ebp)\n" /* line 210 | si */
        "movl -0x540(%ebp), %ecx\n" /* line 199 | p */
        "cmpb $0, -0x109(%ebp, %ecx)\n"
        "jne .Lf206df8_00206f35\n"
        ".Lf206df8_00206f89:\n"
        "movl -0x548(%ebp), %ecx\n" /* line 200 | htbl */
        "movl -0x544(%ebp), %edx\n" /* dtbl */
        "xorl %edi, %edi\n" /* l */
        "movl $0x10, %esi\n" /* code */
        "jmp .Lf206df8_00206fc5\n"
        ".Lf206df8_00206f9e:\n"
        "movl %edi, %eax\n" /* line 221 | l */
        "subl -0x510(%ebp, %edi, 4), %eax\n"
        "movl %eax, 0x4c(%edx)\n"
        "movzbl 1(%ecx), %eax\n" /* line 222 */
        "addl %eax, %edi\n" /* l */
        "movl -0x514(%ebp, %edi, 4), %eax\n" /* line 223 */
        "movl %eax, 4(%edx)\n"
        "addl $1, %ecx\n" /* line 225 */
        "addl $4, %edx\n"
        "subl $1, %esi\n" /* line 216 | code */
        "je .Lf206df8_00206fdd\n"
        ".Lf206df8_00206fc5:\n"
        "cmpb $0, 1(%ecx)\n" /* line 217 */
        "jne .Lf206df8_00206f9e\n"
        "movl $0xffffffff, 4(%edx)\n" /* line 225 */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "subl $1, %esi\n" /* line 216 | code */
        "jne .Lf206df8_00206fc5\n"
        ".Lf206df8_00206fdd:\n"
        "movl -0x544(%ebp), %ecx\n" /* line 228 | dtbl */
        "movl $0xfffff, 0x44(%ecx)\n"
        "movl %ecx, %eax\n" /* line 237 */
        "addl $0x90, %eax\n"
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl -0x548(%ebp), %eax\n" /* htbl */
        "movl $0, -0x520(%ebp)\n"
        "movl $7, -0x52c(%ebp)\n"
        "leal -0x510(%ebp), %esi\n" /* huffcode, code */
        "movl %esi, -0x550(%ebp)\n" /* code */
        ".Lf206df8_0020702f:\n"
        "movl $8, %edx\n"
        "subl -0x52c(%ebp), %edx\n"
        "movl %edx, -0x524(%ebp)\n"
        "leal 1(%eax), %ecx\n" /* line 151 */
        "movl %ecx, -0x554(%ebp)\n"
        "cmpb $0, 1(%eax)\n" /* line 241 */
        "je .Lf206df8_00207148\n"
        "movl $1, %esi\n" /* code */
        "movzbl -0x52c(%ebp), %ecx\n"
        "shll %cl, %esi\n" /* code */
        "movl %esi, -0x534(%ebp)\n" /* code */
        "movl -0x520(%ebp), %eax\n"
        "movl -0x550(%ebp), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x530(%ebp)\n"
        "movl -0x520(%ebp), %edx\n"
        "movl -0x548(%ebp), %ecx\n" /* htbl */
        "leal 0x11(%edx, %ecx), %edi\n" /* l */
        "movl $1, -0x53c(%ebp)\n" /* i */
        "movl %eax, %esi\n" /* code */
        ".Lf206df8_00207098:\n"
        "movl (%esi), %eax\n" /* line 244 | code */
        "movzbl -0x52c(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x534(%ebp), %edx\n" /* line 245 */
        "testl %edx, %edx\n"
        "jle .Lf206df8_002070e1\n"
        "movl -0x544(%ebp), %esi\n" /* dtbl, code */
        "leal 0x90(%esi, %eax, 4), %ecx\n" /* code */
        "leal 0x490(%eax, %esi), %edx\n"
        "xorl %esi, %esi\n" /* code */
        ".Lf206df8_002070c3:\n"
        "movl -0x524(%ebp), %eax\n" /* line 246 */
        "movl %eax, (%ecx)\n"
        "movzbl (%edi), %eax\n" /* line 247 | l */
        "movb %al, (%edx)\n"
        "addl $1, %esi\n" /* code */
        "addl $4, %ecx\n"
        "addl $1, %edx\n"
        "cmpl -0x534(%ebp), %esi\n" /* line 245 | code */
        "jne .Lf206df8_002070c3\n"
        ".Lf206df8_002070e1:\n"
        "addl $1, -0x53c(%ebp)\n" /* line 241 | i */
        "addl $4, -0x530(%ebp)\n"
        "addl $1, %edi\n" /* l */
        "movl -0x554(%ebp), %edx\n"
        "movzbl (%edx), %eax\n"
        "cmpl %eax, -0x53c(%ebp)\n" /* i */
        "jg .Lf206df8_002071ba\n"
        "movl -0x530(%ebp), %esi\n" /* code */
        "jmp .Lf206df8_00207098\n"
        ".Lf206df8_0020710f:\n"
        "leal -0x510(%ebp, %eax, 4), %ecx\n" /* line 200 */
        "leal -0x109(%ebp), %edx\n" /* huffsize */
        "movl %edx, -0x558(%ebp)\n"
        "addl %eax, %edx\n"
        ".Lf206df8_00207124:\n"
        "movl %esi, (%ecx)\n" /* line 201 | code */
        "addl $1, %esi\n" /* line 202 | code */
        "movsbl 1(%edx), %eax\n" /* line 200 */
        "addl $4, %ecx\n"
        "addl $1, %edx\n"
        "cmpl %eax, %edi\n" /* l */
        "je .Lf206df8_00207124\n"
        "subl -0x558(%ebp), %edx\n"
        "movl %edx, -0x540(%ebp)\n" /* p */
        "jmp .Lf206df8_00206f4b\n"
        ".Lf206df8_00207148:\n"
        "movl %ecx, %eax\n"
        ".Lf206df8_0020714a:\n"
        "subl $1, -0x52c(%ebp)\n" /* line 241 */
        "cmpl $-1, -0x52c(%ebp)\n" /* line 240 */
        "jne .Lf206df8_0020702f\n"
        "cmpb $0, -0x549(%ebp)\n" /* line 259 | isDC */
        "je .Lf206df8_002071b0\n"
        "movl -0x51c(%ebp), %eax\n" /* line 260 */
        "testl %eax, %eax\n"
        "jle .Lf206df8_002071b0\n"
        "movl -0x548(%ebp), %edi\n" /* htbl, l */
        "xorl %esi, %esi\n" /* code */
        "jmp .Lf206df8_00207189\n"
        ".Lf206df8_0020717b:\n"
        "addl $1, %esi\n" /* code */
        "addl $1, %edi\n" /* l */
        "cmpl -0x51c(%ebp), %esi\n" /* code */
        "je .Lf206df8_002071b0\n"
        ".Lf206df8_00207189:\n"
        "cmpb $0xf, 0x11(%edi)\n" /* line 262 | l */
        "jbe .Lf206df8_0020717b\n"
        "movl 8(%ebp), %edx\n" /* line 263 | cinfo */
        "movl (%edx), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "addl $1, %esi\n" /* line 260 | code */
        "addl $1, %edi\n" /* l */
        "cmpl -0x51c(%ebp), %esi\n" /* code */
        "jne .Lf206df8_00207189\n"
        ".Lf206df8_002071b0:\n"
        "addl $0x560, %esp\n" /* line 266 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf206df8_002071ba:\n"
        "movl -0x520(%ebp), %ecx\n" /* line 241 */
        "movl -0x53c(%ebp), %esi\n" /* i, code */
        "leal -1(%ecx, %esi), %ecx\n"
        "movl %ecx, -0x520(%ebp)\n"
        "movl -0x554(%ebp), %eax\n"
        "jmp .Lf206df8_0020714a\n"
        ".Lf206df8_002071db:\n"
        "movl 8(%ebp), %eax\n" /* line 167 | cinfo */
        "movl 0xb8(%eax, %esi, 4), %eax\n"
        "movl %eax, -0x548(%ebp)\n" /* htbl */
        "movl -0x548(%ebp), %eax\n" /* line 169 | htbl */
        "testl %eax, %eax\n"
        "jne .Lf206df8_00206e47\n"
        ".Lf206df8_002071f9:\n"
        "movl 8(%ebp), %edx\n" /* line 170 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x32, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* code */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl (%edi), %ecx\n" /* line 173 | l */
        "testl %ecx, %ecx\n"
        "jne .Lf206df8_00206e51\n"
        ".Lf206df8_0020721b:\n"
        "movl 8(%ebp), %ecx\n" /* line 174 | cinfo */
        "movl 4(%ecx), %eax\n"
        "movl $0x590, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, (%edi)\n" /* l */
        "movl %eax, %edi\n" /* l */
        "jmp .Lf206df8_00206e53\n"
        ".Lf206df8_0020723f:\n"
        "movl 8(%ebp), %edx\n" /* line 166 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x32, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* code */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf206df8_00206e1c\n"
    );
}

/* line 87 */
static __attribute__((naked))
void start_pass_huff_decoder(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 87 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 88 | cinfo */
        "movl 0x1a0(%eax), %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* entropy */
        "movl 8(%ebp), %edx\n" /* line 96 | cinfo */
        "movl 0x174(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf20725c_002073ad\n"
        "cmpl $0x3f, 0x178(%edx)\n"
        "je .Lf20725c_0020738c\n"
        ".Lf20725c_0020728e:\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        ".Lf20725c_00207291:\n"
        "movl (%ecx), %eax\n" /* line 98 */
        "movl $0x7a, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf20725c_002072aa:\n"
        "movl 8(%ebp), %edi\n" /* line 100 | cinfo */
        "movl 0x12c(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf20725c_002073b4\n"
        "movl %edi, %ecx\n"
        ".Lf20725c_002072bd:\n"
        "movl 0x148(%ecx), %eax\n" /* line 115 */
        "testl %eax, %eax\n"
        "jle .Lf20725c_00207364\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl -0x18(%ebp), %esi\n" /* entropy, actbl */
        "movl %esi, %ecx\n" /* actbl */
        "movl $0, -0x10(%ebp)\n" /* blkn */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf20725c_0020730d\n"
        ".Lf20725c_002072df:\n"
        "movb $1, 0x98(%ecx)\n" /* line 123 */
        "cmpl $1, 0x24(%edx)\n" /* line 125 */
        "setg 0xa2(%ecx)\n"
        "addl $1, -0x10(%ebp)\n" /* line 115 | blkn */
        "addl $4, -0x2c(%ebp)\n"
        "addl $4, %esi\n" /* actbl */
        "addl $1, %ecx\n"
        "movl -0x10(%ebp), %edx\n" /* blkn */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x148(%eax), %edx\n"
        "jge .Lf20725c_00207364\n"
        ".Lf20725c_0020730d:\n"
        "movl -0x2c(%ebp), %edi\n" /* line 117 */
        "movl 0x14c(%edi), %edx\n"
        "movl 0x130(%eax, %edx, 4), %edx\n"
        "movl 0x14(%edx), %eax\n" /* line 119 */
        "movl -0x18(%ebp), %edi\n" /* entropy */
        "movl 0x28(%edi, %eax, 4), %eax\n"
        "movl %eax, 0x48(%esi)\n" /* actbl */
        "movl 0x18(%edx), %eax\n" /* line 120 */
        "movl 0x38(%edi, %eax, 4), %eax\n"
        "movl %eax, 0x70(%esi)\n" /* actbl */
        "cmpb $0, 0x30(%edx)\n" /* line 122 */
        "jne .Lf20725c_002072df\n"
        "movb $0, 0xa2(%ecx)\n" /* line 127 */
        "movb $0, 0x98(%ecx)\n"
        "addl $1, -0x10(%ebp)\n" /* line 115 | blkn */
        "addl $4, -0x2c(%ebp)\n"
        "addl $4, %esi\n" /* actbl */
        "addl $1, %ecx\n"
        "movl -0x10(%ebp), %edx\n" /* blkn */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x148(%eax), %edx\n"
        "jl .Lf20725c_0020730d\n"
        ".Lf20725c_00207364:\n"
        "movl -0x18(%ebp), %ecx\n" /* line 132 | entropy */
        "movl $0, 0x10(%ecx)\n"
        "movl $0, 0xc(%ecx)\n" /* line 133 */
        "movb $0, 8(%ecx)\n" /* line 134 */
        "movl 8(%ebp), %edi\n" /* line 137 | cinfo */
        "movl 0x104(%edi), %eax\n"
        "movl %eax, 0x24(%ecx)\n"
        "addl $0x40, %esp\n" /* line 138 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20725c_0020738c:\n"
        "movl 0x17c(%edx), %eax\n" /* line 96 */
        "testl %eax, %eax\n"
        "jne .Lf20725c_0020728e\n"
        "movl 0x180(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf20725c_002072aa\n"
        "jmp .Lf20725c_0020728e\n"
        ".Lf20725c_002073ad:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf20725c_00207291\n"
        ".Lf20725c_002073b4:\n"
        "movl %edi, -0xc(%ebp)\n" /* line 100 */
        "movl -0x18(%ebp), %edi\n" /* entropy */
        "movl $0, -0x14(%ebp)\n" /* ci */
        "movl %edi, %eax\n"
        "addl $0x28, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edi, %edx\n"
        "addl $0x38, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        ".Lf20725c_002073d1:\n"
        "movl -0xc(%ebp), %ecx\n" /* line 101 */
        "movl 0x130(%ecx), %eax\n"
        "movl 0x14(%eax), %edx\n" /* line 102 */
        "movl 0x18(%eax), %esi\n" /* line 103 | actbl */
        "movl -0x20(%ebp), %ecx\n" /* line 106 */
        "leal (%ecx, %edx, 4), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_make_d_derived_tbl\n"
        "movl -0x1c(%ebp), %edx\n" /* line 108 */
        "leal (%edx, %esi, 4), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* actbl */
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll jpeg_make_d_derived_tbl\n"
        "movl $0, 0x14(%edi)\n" /* line 111 */
        "addl $1, -0x14(%ebp)\n" /* line 100 | ci */
        "addl $4, -0xc(%ebp)\n"
        "addl $4, %edi\n"
        "movl -0x14(%ebp), %edx\n" /* ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x12c(%eax), %edx\n"
        "jl .Lf20725c_002073d1\n"
        "movl %eax, %ecx\n"
        "jmp .Lf20725c_002072bd\n"
    );
}

/* line 296 */
__attribute__((naked))
boolean jpeg_fill_bit_buffer(bitread_working_state *state, bit_buf_type get_buffer, int bits_left, int nbits)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 296 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 298 | state */
        "movl (%eax), %edi\n" /* next_input_byte */
        "movl 4(%eax), %esi\n" /* line 299 | bytes_in_buffer */
        "movl 0x10(%eax), %edx\n" /* line 300 */
        "movl %edx, -0xc(%ebp)\n" /* cinfo */
        "movl 0x184(%edx), %edx\n" /* line 306 */
        "testl %edx, %edx\n"
        "jne .Lf207449_00207530\n"
        "cmpl $0x18, 0x10(%ebp)\n" /* line 307 | bits_left */
        "jle .Lf207449_002074d3\n"
        ".Lf207449_00207473:\n"
        "movl 8(%ebp), %eax\n" /* line 383 | state */
        "movl %edi, (%eax)\n" /* next_input_byte */
        "movl %esi, 4(%eax)\n" /* line 384 | bytes_in_buffer */
        "movl 0xc(%ebp), %edx\n" /* line 385 | get_buffer */
        "movl %edx, 8(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 386 | bits_left */
        "movl %edx, 0xc(%eax)\n"
        "movl $1, %eax\n"
        ".Lf207449_0020748c:\n"
        "addl $0x20, %esp\n" /* line 389 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf207449_00207493:\n"
        "movl -0xc(%ebp), %edx\n" /* line 312 | cinfo */
        "movl 0x20(%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testb %al, %al\n"
        "je .Lf207449_0020758a\n"
        "movl -0xc(%ebp), %edx\n" /* line 314 | cinfo */
        "movl 0x20(%edx), %eax\n"
        "movl (%eax), %edi\n" /* next_input_byte */
        "movl 4(%eax), %esi\n" /* line 315 | bytes_in_buffer */
        ".Lf207449_002074b2:\n"
        "subl $1, %esi\n" /* line 317 | bytes_in_buffer */
        "movzbl (%edi), %eax\n" /* line 318 | next_input_byte */
        "movzbl %al, %edx\n"
        "addl $1, %edi\n" /* next_input_byte */
        "addb $1, %al\n" /* line 321 */
        "je .Lf207449_00207508\n"
        ".Lf207449_002074c2:\n"
        "shll $8, 0xc(%ebp)\n" /* line 357 | get_buffer */
        "orl %edx, 0xc(%ebp)\n" /* get_buffer */
        "addl $8, 0x10(%ebp)\n" /* line 358 | bits_left */
        /* } scope */
        "cmpl $0x18, 0x10(%ebp)\n" /* line 307 | bits_left */
        "jg .Lf207449_00207473\n"
        /* { scope 2 */
        ".Lf207449_002074d3:\n"
        "testl %esi, %esi\n" /* line 311 | bytes_in_buffer */
        "jne .Lf207449_002074b2\n"
        "jmp .Lf207449_00207493\n"
        ".Lf207449_002074d9:\n"
        "movl -0xc(%ebp), %edx\n" /* line 329 | cinfo */
        "movl 0x20(%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testb %al, %al\n"
        "je .Lf207449_0020758a\n"
        "movl -0xc(%ebp), %edx\n" /* line 331 | cinfo */
        "movl 0x20(%edx), %eax\n"
        "movl (%eax), %edi\n" /* next_input_byte */
        "movl 4(%eax), %esi\n" /* line 332 | bytes_in_buffer */
        "subl $1, %esi\n" /* line 334 | bytes_in_buffer */
        "movzbl (%edi), %eax\n" /* line 335 | next_input_byte */
        "movzbl %al, %edx\n"
        "addl $1, %edi\n" /* next_input_byte */
        "cmpb $0xff, %al\n" /* line 336 */
        "jne .Lf207449_0020751c\n"
        ".Lf207449_00207508:\n"
        "testl %esi, %esi\n" /* line 328 | bytes_in_buffer */
        "je .Lf207449_002074d9\n"
        "subl $1, %esi\n" /* line 334 | bytes_in_buffer */
        "movzbl (%edi), %eax\n" /* line 335 | next_input_byte */
        "movzbl %al, %edx\n"
        "addl $1, %edi\n" /* next_input_byte */
        "cmpb $0xff, %al\n" /* line 336 */
        "je .Lf207449_00207508\n"
        ".Lf207449_0020751c:\n"
        "testb %al, %al\n" /* line 338 */
        "jne .Lf207449_00207527\n"
        "movl $0xff, %edx\n" /* line 352 */
        "jmp .Lf207449_002074c2\n"
        ".Lf207449_00207527:\n"
        "movl -0xc(%ebp), %eax\n" /* line 350 | cinfo */
        "movl %edx, 0x184(%eax)\n"
        /* } scope */
        ".Lf207449_00207530:\n"
        "movl 0x10(%ebp), %edx\n" /* line 366 | bits_left */
        "cmpl 0x14(%ebp), %edx\n" /* nbits */
        "jge .Lf207449_00207473\n"
        "movl -0xc(%ebp), %edx\n" /* line 372 | cinfo */
        "movl 0x1a0(%edx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf207449_00207562\n"
        ".Lf207449_0020754b:\n"
        "movl $0x19, %ecx\n" /* line 377 */
        "subl 0x10(%ebp), %ecx\n" /* bits_left */
        "shll %cl, 0xc(%ebp)\n" /* get_buffer */
        "movl $0x19, 0x10(%ebp)\n" /* bits_left */
        "jmp .Lf207449_00207473\n"
        ".Lf207449_00207562:\n"
        "movl (%edx), %eax\n" /* line 373 */
        "movl $0x75, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl -0xc(%ebp), %edx\n" /* line 374 | cinfo */
        "movl 0x1a0(%edx), %eax\n"
        "movb $1, 8(%eax)\n"
        "jmp .Lf207449_0020754b\n"
        ".Lf207449_0020758a:\n"
        "xorl %eax, %eax\n" /* line 388 */
        "jmp .Lf207449_0020748c\n"
    );
}

/* line 401 */
__attribute__((naked))
int jpeg_huff_decode(bitread_working_state *state, bit_buf_type get_buffer, int bits_left, d_derived_tbl *htbl, int min_bits)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 401 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* bits_left */
        "movl 0x18(%ebp), %esi\n" /* min_bits */
        "cmpl %eax, %esi\n" /* line 408 | min_bits */
        "jg .Lf207591_002076a8\n"
        "movl 0xc(%ebp), %edx\n" /* get_buffer */
        ".Lf207591_002075aa:\n"
        "subl %esi, %eax\n" /* line 409 | min_bits */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ecx\n"
        "sarl %cl, %edx\n"
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* min_bits */
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl %eax, %edx\n"
        "movl 0x14(%ebp), %eax\n" /* line 414 | htbl */
        "cmpl (%eax, %esi, 4), %edx\n"
        "jle .Lf207591_0020762b\n"
        "movl %esi, %edi\n" /* min_bits, l */
        "leal (%eax, %edi, 4), %esi\n" /* min_bits */
        ".Lf207591_002075ce:\n"
        "addl %edx, %edx\n" /* line 415 */
        "movl %edx, -0xc(%ebp)\n" /* code */
        "movl -0x1c(%ebp), %ecx\n" /* line 416 */
        "testl %ecx, %ecx\n"
        "jle .Lf207591_0020766c\n"
        "movl 0xc(%ebp), %edx\n" /* get_buffer */
        ".Lf207591_002075e1:\n"
        "subl $1, -0x1c(%ebp)\n" /* line 417 */
        "movzbl -0x1c(%ebp), %ecx\n"
        "sarl %cl, %edx\n"
        "andl $1, %edx\n"
        "orl -0xc(%ebp), %edx\n" /* code */
        "addl $1, %edi\n" /* line 418 | l */
        "movl 4(%esi), %eax\n" /* line 414 | min_bits */
        "addl $4, %esi\n" /* min_bits */
        "cmpl %edx, %eax\n"
        "jl .Lf207591_002075ce\n"
        "movl 0xc(%ebp), %ecx\n" /* line 422 | get_buffer */
        "movl 8(%ebp), %eax\n" /* state */
        "movl %ecx, 8(%eax)\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 423 */
        "movl %ecx, 0xc(%eax)\n"
        "cmpl $0x10, %edi\n" /* line 427 | l */
        "jg .Lf207591_00207641\n"
        ".Lf207591_00207612:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 432 | htbl */
        "movl 0x48(%ecx, %edi, 4), %eax\n"
        "addl 0x8c(%ecx), %eax\n"
        "movzbl 0x11(%eax, %edx), %eax\n"
        ".Lf207591_00207624:\n"
        "addl $0x30, %esp\n" /* line 433 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf207591_0020762b:\n"
        "movl %esi, %edi\n" /* line 414 | min_bits, l */
        "movl 0xc(%ebp), %ecx\n" /* line 422 | get_buffer */
        "movl 8(%ebp), %eax\n" /* state */
        "movl %ecx, 8(%eax)\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 423 */
        "movl %ecx, 0xc(%eax)\n"
        "cmpl $0x10, %edi\n" /* line 427 | l */
        "jle .Lf207591_00207612\n"
        ".Lf207591_00207641:\n"
        "movl 8(%ebp), %edx\n" /* line 428 | state */
        "movl 0x10(%edx), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x76, 0x14(%eax)\n"
        "movl 0x10(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n"
        "addl $0x30, %esp\n" /* line 433 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf207591_0020766c:\n"
        "movl $1, 0xc(%esp)\n" /* line 416 */
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207591_002076dc\n"
        "movl 8(%ebp), %edx\n" /* state */
        "movl 8(%edx), %edx\n"
        "movl %edx, 0xc(%ebp)\n" /* get_buffer */
        "movl 8(%ebp), %ecx\n" /* state */
        "movl 0xc(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "jmp .Lf207591_002075e1\n"
        ".Lf207591_002076a8:\n"
        "movl %esi, 0xc(%esp)\n" /* line 408 | min_bits */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* get_buffer */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* state */
        "movl %edx, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207591_002076dc\n"
        "movl 8(%ebp), %ecx\n" /* state */
        "movl 8(%ecx), %ecx\n"
        "movl %ecx, 0xc(%ebp)\n" /* get_buffer */
        "movl 8(%ebp), %edx\n" /* state */
        "movl 0xc(%edx), %eax\n"
        "movl %ecx, %edx\n"
        "jmp .Lf207591_002075aa\n"
        ".Lf207591_002076dc:\n"
        "movl $0xffffffff, %eax\n" /* line 432 */
        "jmp .Lf207591_00207624\n"
    );
}

/* line 636 */
__attribute__((naked))
void jinit_huff_decoder(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 636 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 4(%esi), %eax\n" /* line 640 | cinfo */
        "movl $0xac, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x1a0(%esi)\n" /* line 643 | cinfo */
        "leal -0x497(%ebx), %edx\n" /* line 644 */
        "movl %edx, (%eax)\n"
        "leal 0x54(%ebx), %edx\n" /* line 645 */
        "movl %edx, 4(%eax)\n"
        "movl $4, %edx\n"
        ".Lf2076e6_0020772a:\n"
        "movl $0, 0x38(%eax)\n" /* line 649 */
        "movl $0, 0x28(%eax)\n"
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 648 */
        "jne .Lf2076e6_0020772a\n"
        "addl $0x10, %esp\n" /* line 651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 518 */
static __attribute__((naked))
boolean decode_mcu(j_decompress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1: block, dctbl, actbl, k */
        "pushl %ebp\n" /* line 518 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 519 | cinfo */
        "movl 0x1a0(%eax), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 525 | cinfo */
        "movl 0x104(%edx), %esi\n" /* bits_left */
        "testl %esi, %esi\n" /* bits_left */
        "je .Lf207747_0020777f\n"
        "movl 0x24(%eax), %ecx\n" /* line 526 */
        "testl %ecx, %ecx\n"
        "je .Lf207747_00208033\n"
        ".Lf207747_0020777c:\n"
        "movl -0x60(%ebp), %eax\n"
        ".Lf207747_0020777f:\n"
        "cmpb $0, 8(%eax)\n" /* line 534 */
        "jne .Lf207747_00207b1e\n"
        "movl 8(%ebp), %edx\n" /* line 537 | cinfo */
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x20(%edx), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* br_state */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x60(%ebp), %ecx\n"
        "movl 0x10(%ecx), %esi\n" /* bits_left */
        "movl 0x14(%ecx), %eax\n" /* line 538 */
        "movl %eax, -0x28(%ebp)\n" /* state */
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x20(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 542 | cinfo */
        "movl 0x148(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf207747_00207ae3\n"
        "movl %ecx, -0x68(%ebp)\n"
        "movl %ecx, -0x64(%ebp)\n"
        "movl $1, -0x6c(%ebp)\n"
        "leal -0x3c(%ebp), %ecx\n" /* br_state */
        "movl %ecx, -0x88(%ebp)\n"
        "movl %ecx, -0x90(%ebp)\n"
        "movl %ecx, -0x8c(%ebp)\n"
        "movl %ecx, -0x94(%ebp)\n"
        "movl %ecx, -0x98(%ebp)\n"
        /* { scope 2 */
        ".Lf207747_00207806:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 543 */
        "movl 0xc(%ebp), %edx\n" /* MCU_data */
        "movl -4(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* block */
        "movl -0x68(%ebp), %edx\n" /* line 544 */
        "movl 0x48(%edx), %edx\n"
        "movl %edx, -0x7c(%ebp)\n" /* dctbl */
        "movl -0x68(%ebp), %ecx\n" /* line 545 */
        "movl 0x70(%ecx), %ecx\n"
        "movl %ecx, -0x78(%ebp)\n" /* actbl */
        /* { scope 3: bits_left */
        "cmpl $7, %esi\n" /* line 551 | bits_left */
        "jle .Lf207747_00207f97\n"
        "movl -0x84(%ebp), %eax\n" /* get_buffer, look */
        ".Lf207747_00207834:\n"
        "leal -8(%esi), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n" /* look */
        "andl $0xff, %eax\n" /* look */
        "movl 0x90(%edx, %eax, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf207747_00207f46\n"
        "movl $9, %edi\n" /* nb */
        /* { scope 4: code */
        /* { scope 5 */
        "cmpl %edi, %esi\n" /* line 408 */
        "jl .Lf207747_00207fde\n"
        ".Lf207747_0020785a:\n"
        "movl -0x84(%ebp), %edx\n" /* get_buffer */
        ".Lf207747_00207860:\n"
        "subl %edi, %esi\n" /* line 409 */
        "movl %esi, -0x9c(%ebp)\n" /* bits_left */
        "movzbl -0x9c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl %eax, %edx\n"
        "movl -0x7c(%ebp), %eax\n" /* line 414 | dctbl */
        "cmpl (%eax, %edi, 4), %edx\n"
        "jle .Lf207747_002078c6\n"
        "leal (%eax, %edi, 4), %esi\n"
        ".Lf207747_0020788a:\n"
        "addl %edx, %edx\n" /* line 415 */
        "movl %edx, -0x5c(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n" /* line 416 | bits_left */
        "testl %eax, %eax\n"
        "jle .Lf207747_00207f58\n"
        "movl -0x84(%ebp), %edx\n" /* get_buffer */
        ".Lf207747_002078a3:\n"
        "subl $1, -0x9c(%ebp)\n" /* line 417 | bits_left */
        "movzbl -0x9c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "andl $1, %edx\n"
        "orl -0x5c(%ebp), %edx\n"
        "addl $1, %edi\n" /* line 418 */
        "movl 4(%esi), %eax\n" /* line 414 */
        "addl $4, %esi\n"
        "cmpl %edx, %eax\n"
        "jl .Lf207747_0020788a\n"
        ".Lf207747_002078c6:\n"
        "movl -0x84(%ebp), %eax\n" /* line 422 | get_buffer */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x9c(%ebp), %ecx\n" /* line 423 | bits_left */
        "movl %ecx, -0x30(%ebp)\n"
        "cmpl $0x10, %edi\n" /* line 427 */
        "jg .Lf207747_002080c8\n"
        "movl -0x7c(%ebp), %eax\n" /* line 432 | dctbl */
        "addl 0x8c(%eax), %edx\n"
        "addl 0x48(%eax, %edi, 4), %edx\n"
        "movzbl 0x11(%edx), %edi\n"
        /* } scope */
        /* } scope */
        ".Lf207747_002078f2:\n"
        "movl -0x34(%ebp), %edx\n" /* line 551 */
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n" /* bits_left */
        /* } scope */
        ".Lf207747_002078fe:\n"
        "testl %edi, %edi\n" /* line 552 | nb */
        "je .Lf207747_00207933\n"
        "cmpl %edi, %esi\n" /* line 553 | nb, bits_left */
        "jl .Lf207747_002080ee\n"
        "movl -0x84(%ebp), %edx\n" /* get_buffer */
        ".Lf207747_00207910:\n"
        "subl %edi, %esi\n" /* line 554 | nb, bits_left */
        "movl %esi, %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n" /* nb */
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl %eax, %edx\n"
        "cmpl 0xffc88(%ebx, %edi, 4), %edx\n" /* line 555 */
        "jl .Lf207747_00208010\n"
        ".Lf207747_00207931:\n"
        "movl %edx, %edi\n" /* nb */
        ".Lf207747_00207933:\n"
        "movl -0x64(%ebp), %eax\n" /* line 558 */
        "cmpb $0, 0x98(%eax)\n"
        "je .Lf207747_00207f3f\n"
        /* { scope 3: bits_left */
        "movl -0x6c(%ebp), %edx\n" /* line 560 */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0x148(%ecx, %edx, 4), %eax\n" /* ci */
        "movl %edi, %edx\n" /* line 561 | nb */
        "addl -0x28(%ebp, %eax, 4), %edx\n"
        "movl %edx, -0x28(%ebp, %eax, 4)\n" /* line 562 */
        "movl -0x80(%ebp), %eax\n" /* line 564 | block */
        "movw %dx, (%eax)\n"
        "movl -0x64(%ebp), %edx\n"
        /* } scope */
        ".Lf207747_00207963:\n"
        "cmpb $0, 0xa2(%edx)\n" /* line 567 */
        "je .Lf207747_00207c9a\n"
        "movl $1, -0x4c(%ebp)\n"
        /* { scope 3: bits_left */
        ".Lf207747_00207977:\n"
        "cmpl $7, %esi\n" /* line 572 | bits_left */
        "jle .Lf207747_00207b63\n"
        "movl -0x84(%ebp), %eax\n" /* get_buffer, look */
        ".Lf207747_00207986:\n"
        "leal -8(%esi), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n" /* look */
        "andl $0xff, %eax\n" /* look */
        "movl -0x78(%ebp), %ecx\n" /* actbl */
        "movl 0x90(%ecx, %eax, 4), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf207747_00207b47\n"
        "movl $9, %edi\n" /* nb */
        /* { scope 4: code */
        /* { scope 5 */
        ".Lf207747_002079a7:\n"
        "cmpl %edi, %esi\n" /* line 408 */
        "jl .Lf207747_00207bf4\n"
        "movl -0x84(%ebp), %edx\n" /* get_buffer */
        ".Lf207747_002079b5:\n"
        "subl %edi, %esi\n" /* line 409 */
        "movl %esi, -0x9c(%ebp)\n" /* bits_left */
        "movzbl -0x9c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl %eax, %edx\n"
        "movl -0x78(%ebp), %eax\n" /* line 414 | actbl */
        "cmpl (%eax, %edi, 4), %edx\n"
        "jle .Lf207747_00207a1b\n"
        "leal (%eax, %edi, 4), %esi\n"
        ".Lf207747_002079df:\n"
        "addl %edx, %edx\n" /* line 415 */
        "movl %edx, -0x58(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n" /* line 416 | bits_left */
        "testl %eax, %eax\n"
        "jle .Lf207747_00207bab\n"
        "movl -0x84(%ebp), %edx\n" /* get_buffer */
        ".Lf207747_002079f8:\n"
        "subl $1, -0x9c(%ebp)\n" /* line 417 | bits_left */
        "movzbl -0x9c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "andl $1, %edx\n"
        "orl -0x58(%ebp), %edx\n"
        "addl $1, %edi\n" /* line 418 */
        "movl 4(%esi), %eax\n" /* line 414 */
        "addl $4, %esi\n"
        "cmpl %eax, %edx\n"
        "jg .Lf207747_002079df\n"
        ".Lf207747_00207a1b:\n"
        "movl -0x84(%ebp), %eax\n" /* line 422 | get_buffer */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x9c(%ebp), %ecx\n" /* line 423 | bits_left */
        "movl %ecx, -0x30(%ebp)\n"
        "cmpl $0x10, %edi\n" /* line 427 */
        "jg .Lf207747_00207c2d\n"
        "movl -0x78(%ebp), %eax\n" /* line 432 | actbl */
        "addl 0x8c(%eax), %edx\n"
        "addl 0x48(%eax, %edi, 4), %edx\n"
        "movzbl 0x11(%edx), %eax\n"
        /* } scope */
        /* } scope */
        "movl %eax, %edx\n" /* line 572 | look */
        "sarl $4, %edx\n"
        "movl %eax, %edi\n" /* look, nb */
        "andl $0xf, %edi\n" /* nb */
        ".Lf207747_00207a51:\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl %ecx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n" /* bits_left */
        /* } scope */
        ".Lf207747_00207a5d:\n"
        "testl %edi, %edi\n" /* line 577 | nb */
        "je .Lf207747_00207b32\n"
        "addl -0x4c(%ebp), %edx\n" /* line 578 */
        "movl %edx, -0x74(%ebp)\n" /* k */
        "cmpl %edi, %esi\n" /* line 579 | nb, bits_left */
        "jl .Lf207747_00207c5f\n"
        "movl -0x84(%ebp), %edx\n" /* get_buffer */
        ".Lf207747_00207a79:\n"
        "subl %edi, %esi\n" /* line 580 | nb, bits_left */
        "movl %esi, %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n" /* nb */
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl %eax, %edx\n"
        "cmpl 0xffc88(%ebx, %edi, 4), %edx\n" /* line 581 */
        "jge .Lf207747_00207a9d\n"
        "addl 0xffc48(%ebx, %edi, 4), %edx\n"
        ".Lf207747_00207a9d:\n"
        "movl 0x1758270(%ebx), %eax\n" /* line 586 */
        "movl -0x74(%ebp), %ecx\n" /* k */
        "movl (%eax, %ecx, 4), %eax\n"
        "movl -0x80(%ebp), %ecx\n" /* block */
        "movw %dx, (%ecx, %eax, 2)\n"
        "movl -0x74(%ebp), %edx\n" /* k */
        ".Lf207747_00207ab3:\n"
        "addl $1, %edx\n" /* line 571 */
        "movl %edx, -0x4c(%ebp)\n"
        "cmpl $0x3f, %edx\n"
        "jle .Lf207747_00207977\n"
        ".Lf207747_00207ac2:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 598 */
        "addl $1, -0x6c(%ebp)\n"
        "addl $4, -0x68(%ebp)\n"
        "addl $1, -0x64(%ebp)\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 542 | cinfo */
        "cmpl 0x148(%edx), %eax\n"
        "jl .Lf207747_00207806\n"
        "movl 0x20(%edx), %edx\n"
        ".Lf207747_00207ae3:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 619 | br_state */
        "movl %eax, (%edx)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x20(%eax), %edx\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x84(%ebp), %ecx\n" /* get_buffer */
        "movl -0x60(%ebp), %edx\n"
        "movl %ecx, 0xc(%edx)\n"
        "movl %esi, 0x10(%edx)\n" /* bits_left */
        "movl -0x28(%ebp), %eax\n" /* line 620 | state */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl -0x60(%ebp), %eax\n"
        ".Lf207747_00207b1e:\n"
        "subl $1, 0x24(%eax)\n" /* line 624 */
        "movl $1, %eax\n"
        "addl $0xac, %esp\n" /* line 627 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf207747_00207b32:\n"
        "cmpl $0xf, %edx\n" /* line 588 */
        "jne .Lf207747_00207ac2\n"
        "movl -0x4c(%ebp), %eax\n" /* line 590 */
        "addl $0xf, %eax\n"
        "movl %eax, -0x74(%ebp)\n" /* k */
        "movl %eax, %edx\n"
        "jmp .Lf207747_00207ab3\n"
        /* { scope 3: bits_left */
        ".Lf207747_00207b47:\n"
        "subl %edx, %esi\n" /* line 572 | bits_left */
        "movl -0x78(%ebp), %edx\n" /* actbl */
        "movzbl 0x490(%eax, %edx), %eax\n" /* look */
        "movl %eax, %edx\n" /* look */
        "sarl $4, %edx\n"
        "movl %eax, %edi\n" /* look, nb */
        "andl $0xf, %edi\n" /* nb */
        "jmp .Lf207747_00207a5d\n"
        ".Lf207747_00207b63:\n"
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x84(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl -0x8c(%ebp), %eax\n" /* look */
        "movl %eax, (%esp)\n" /* look */
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n" /* look */
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n" /* bits_left */
        "cmpl $7, %esi\n" /* bits_left */
        "jle .Lf207747_00207c55\n"
        "movl %edx, %eax\n" /* look */
        "jmp .Lf207747_00207986\n"
        /* { scope 4: code */
        /* { scope 5 */
        ".Lf207747_00207bab:\n"
        "movl $1, 0xc(%esp)\n" /* line 416 */
        "movl -0x9c(%ebp), %edx\n" /* bits_left */
        "movl %edx, 8(%esp)\n"
        "movl -0x84(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %ecx\n"
        "movl %ecx, -0x9c(%ebp)\n" /* bits_left */
        "jmp .Lf207747_002079f8\n"
        ".Lf207747_00207bf4:\n"
        "movl %edi, 0xc(%esp)\n" /* line 408 */
        "movl %esi, 8(%esp)\n"
        "movl -0x84(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n"
        "jmp .Lf207747_002079b5\n"
        ".Lf207747_00207c2d:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 428 */
        "movl (%eax), %eax\n"
        "movl $0x76, 0x14(%eax)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %edx, %edx\n"
        "xorl %edi, %edi\n"
        "jmp .Lf207747_00207a51\n"
        /* } scope */
        /* } scope */
        ".Lf207747_00207c55:\n"
        "movl $1, %edi\n" /* line 572 | nb */
        "jmp .Lf207747_002079a7\n"
        /* } scope */
        ".Lf207747_00207c5f:\n"
        "movl %edi, 0xc(%esp)\n" /* line 579 | nb */
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x84(%ebp), %eax\n" /* get_buffer */
        "movl %eax, 4(%esp)\n"
        "movl -0x8c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl %ecx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n" /* bits_left */
        "movl %ecx, %edx\n"
        "jmp .Lf207747_00207a79\n"
        ".Lf207747_00207c9a:\n"
        "movl $1, -0x50(%ebp)\n" /* line 571 */
        /* { scope 3: bits_left */
        "cmpl $7, %esi\n" /* line 599 | bits_left */
        "jle .Lf207747_00207dbb\n"
        ".Lf207747_00207caa:\n"
        "movl -0x84(%ebp), %eax\n" /* get_buffer, look */
        "leal -8(%esi), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n" /* look */
        "andl $0xff, %eax\n" /* look */
        "movl -0x78(%ebp), %ecx\n" /* actbl */
        "movl 0x90(%ecx, %eax, 4), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf207747_00207e1a\n"
        ".Lf207747_00207ccc:\n"
        "movl $9, %edi\n" /* nb */
        /* { scope 4: code */
        /* { scope 5 */
        ".Lf207747_00207cd1:\n"
        "cmpl %edi, %esi\n" /* line 408 */
        "jl .Lf207747_00207ed4\n"
        "movl -0x84(%ebp), %edx\n" /* get_buffer */
        ".Lf207747_00207cdf:\n"
        "subl %edi, %esi\n" /* line 409 */
        "movl %esi, -0x9c(%ebp)\n" /* bits_left */
        "movzbl -0x9c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl %eax, %edx\n"
        "movl -0x78(%ebp), %eax\n" /* line 414 | actbl */
        "cmpl (%eax, %edi, 4), %edx\n"
        "jle .Lf207747_00207d45\n"
        "leal (%eax, %edi, 4), %esi\n"
        ".Lf207747_00207d09:\n"
        "addl %edx, %edx\n" /* line 415 */
        "movl %edx, -0x70(%ebp)\n" /* code */
        "movl -0x9c(%ebp), %eax\n" /* line 416 | bits_left */
        "testl %eax, %eax\n"
        "jle .Lf207747_00207e8b\n"
        "movl -0x84(%ebp), %edx\n" /* get_buffer */
        ".Lf207747_00207d22:\n"
        "subl $1, -0x9c(%ebp)\n" /* line 417 | bits_left */
        "movzbl -0x9c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "andl $1, %edx\n"
        "orl -0x70(%ebp), %edx\n" /* code */
        "addl $1, %edi\n" /* line 418 */
        "movl 4(%esi), %eax\n" /* line 414 */
        "addl $4, %esi\n"
        "cmpl %eax, %edx\n"
        "jg .Lf207747_00207d09\n"
        ".Lf207747_00207d45:\n"
        "movl -0x84(%ebp), %eax\n" /* line 422 | get_buffer */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x9c(%ebp), %ecx\n" /* line 423 | bits_left */
        "movl %ecx, -0x30(%ebp)\n"
        "cmpl $0x10, %edi\n" /* line 427 */
        "jg .Lf207747_00207f0d\n"
        "movl -0x78(%ebp), %ecx\n" /* line 432 | actbl */
        "movl 0x48(%ecx, %edi, 4), %eax\n"
        "addl 0x8c(%ecx), %eax\n"
        "movzbl 0x11(%eax, %edx), %eax\n"
        /* } scope */
        /* } scope */
        "movl %eax, %edx\n" /* line 599 | look */
        "sarl $4, %edx\n"
        "movl %eax, %edi\n" /* look, nb */
        "andl $0xf, %edi\n" /* nb */
        ".Lf207747_00207d7c:\n"
        "movl -0x34(%ebp), %eax\n" /* look */
        "movl %eax, -0x84(%ebp)\n" /* look, get_buffer */
        "movl -0x30(%ebp), %esi\n" /* bits_left */
        /* } scope */
        "testl %edi, %edi\n" /* line 604 | nb */
        "je .Lf207747_00207e39\n"
        ".Lf207747_00207d90:\n"
        "addl -0x50(%ebp), %edx\n" /* line 605 */
        "movl %edx, -0x54(%ebp)\n"
        "cmpl %edi, %esi\n" /* line 606 | nb, bits_left */
        "jl .Lf207747_00207e52\n"
        ".Lf207747_00207d9e:\n"
        "subl %edi, %esi\n" /* line 607 | nb, bits_left */
        "movl -0x54(%ebp), %ecx\n"
        ".Lf207747_00207da3:\n"
        "addl $1, %ecx\n" /* line 598 */
        "movl %ecx, -0x50(%ebp)\n"
        "cmpl $0x3f, %ecx\n"
        "jg .Lf207747_00207ac2\n"
        /* { scope 3: bits_left */
        "cmpl $7, %esi\n" /* line 599 | bits_left */
        "jg .Lf207747_00207caa\n"
        ".Lf207747_00207dbb:\n"
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x84(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl -0x90(%ebp), %eax\n" /* look */
        "movl %eax, (%esp)\n" /* look */
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n" /* look */
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n" /* bits_left */
        "cmpl $7, %esi\n" /* bits_left */
        "jle .Lf207747_00207f35\n"
        "movl %edx, %eax\n" /* look */
        "leal -8(%esi), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n" /* look */
        "andl $0xff, %eax\n" /* look */
        "movl -0x78(%ebp), %ecx\n" /* actbl */
        "movl 0x90(%ecx, %eax, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf207747_00207ccc\n"
        ".Lf207747_00207e1a:\n"
        "subl %edx, %esi\n" /* bits_left */
        "movl -0x78(%ebp), %edx\n" /* actbl */
        "movzbl 0x490(%eax, %edx), %eax\n" /* look */
        "movl %eax, %edx\n" /* look */
        "sarl $4, %edx\n"
        "movl %eax, %edi\n" /* look, nb */
        "andl $0xf, %edi\n" /* nb */
        /* } scope */
        "testl %edi, %edi\n" /* line 604 | nb */
        "jne .Lf207747_00207d90\n"
        ".Lf207747_00207e39:\n"
        "cmpl $0xf, %edx\n" /* line 609 */
        "jne .Lf207747_00207ac2\n"
        "movl -0x50(%ebp), %edx\n" /* line 611 */
        "addl $0xf, %edx\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lf207747_00207da3\n"
        ".Lf207747_00207e52:\n"
        "movl %edi, 0xc(%esp)\n" /* line 606 | nb */
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x84(%ebp), %edx\n" /* get_buffer */
        "movl %edx, 4(%esp)\n"
        "movl -0x90(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n" /* bits_left */
        "jmp .Lf207747_00207d9e\n"
        /* { scope 3: bits_left */
        /* { scope 4: code */
        /* { scope 5 */
        ".Lf207747_00207e8b:\n"
        "movl $1, 0xc(%esp)\n" /* line 416 */
        "movl -0x9c(%ebp), %edx\n" /* bits_left */
        "movl %edx, 8(%esp)\n"
        "movl -0x84(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl -0x98(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %ecx\n"
        "movl %ecx, -0x9c(%ebp)\n" /* bits_left */
        "jmp .Lf207747_00207d22\n"
        ".Lf207747_00207ed4:\n"
        "movl %edi, 0xc(%esp)\n" /* line 408 */
        "movl %esi, 8(%esp)\n"
        "movl -0x84(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n"
        "jmp .Lf207747_00207cdf\n"
        ".Lf207747_00207f0d:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 428 */
        "movl (%eax), %eax\n"
        "movl $0x76, 0x14(%eax)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %edx, %edx\n"
        "xorl %edi, %edi\n"
        "jmp .Lf207747_00207d7c\n"
        /* } scope */
        /* } scope */
        ".Lf207747_00207f35:\n"
        "movl $1, %edi\n" /* line 599 | nb */
        "jmp .Lf207747_00207cd1\n"
        ".Lf207747_00207f3f:\n"
        "movl %eax, %edx\n" /* look */
        "jmp .Lf207747_00207963\n"
        /* } scope */
        /* { scope 3: bits_left */
        ".Lf207747_00207f46:\n"
        "subl %ecx, %esi\n" /* line 551 | bits_left */
        "movl -0x7c(%ebp), %ecx\n" /* dctbl */
        "movzbl 0x490(%eax, %ecx), %edi\n" /* nb */
        "jmp .Lf207747_002078fe\n"
        /* { scope 4: code */
        /* { scope 5 */
        ".Lf207747_00207f58:\n"
        "movl $1, 0xc(%esp)\n" /* line 416 */
        "movl -0x9c(%ebp), %edx\n" /* bits_left */
        "movl %edx, 8(%esp)\n"
        "movl -0x84(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "jne .Lf207747_0020801c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf207747_00207f8a:\n"
        "xorl %eax, %eax\n" /* line 626 */
        "addl $0xac, %esp\n" /* line 627 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        /* { scope 3: bits_left */
        ".Lf207747_00207f97:\n"
        "movl $0, 0xc(%esp)\n" /* line 551 */
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x84(%ebp), %eax\n" /* get_buffer, look */
        "movl %eax, 4(%esp)\n" /* look */
        "leal -0x3c(%ebp), %eax\n" /* br_state, look */
        "movl %eax, (%esp)\n" /* look */
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n" /* look */
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n" /* bits_left */
        "cmpl $7, %esi\n" /* bits_left */
        "jg .Lf207747_002080be\n"
        "movl $1, %edi\n" /* nb */
        /* { scope 4: code */
        /* { scope 5 */
        "cmpl %edi, %esi\n" /* line 408 */
        "jge .Lf207747_0020785a\n"
        ".Lf207747_00207fde:\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl -0x84(%ebp), %eax\n" /* get_buffer */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* br_state */
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n"
        "jmp .Lf207747_00207860\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf207747_00208010:\n"
        "addl 0xffc48(%ebx, %edi, 4), %edx\n" /* line 555 */
        "jmp .Lf207747_00207931\n"
        /* { scope 3: bits_left */
        /* { scope 4: code */
        /* { scope 5 */
        ".Lf207747_0020801c:\n"
        "movl -0x34(%ebp), %edx\n" /* line 416 */
        "movl %edx, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %ecx\n"
        "movl %ecx, -0x9c(%ebp)\n" /* bits_left */
        "jmp .Lf207747_002078a3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf207747_00208033:\n"
        "movl 0x19c(%edx), %ecx\n" /* line 475 */
        "movl 0x10(%eax), %eax\n"
        "leal 7(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $3, %eax\n"
        "addl %eax, 0x14(%ecx)\n"
        "movl -0x60(%ebp), %ecx\n" /* line 476 */
        "movl $0, 0x10(%ecx)\n"
        "movl 8(%ebp), %edx\n" /* line 479 | cinfo */
        "movl 0x19c(%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        "testb %al, %al\n"
        "je .Lf207747_00207f8a\n"
        "movl 8(%ebp), %edx\n" /* line 483 | cinfo */
        "movl 0x12c(%edx), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf207747_00208098\n"
        "movl -0x60(%ebp), %edx\n"
        "xorl %eax, %eax\n"
        ".Lf207747_0020807e:\n"
        "movl $0, 0x14(%edx)\n" /* line 484 */
        "addl $1, %eax\n" /* line 483 */
        "addl $4, %edx\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x12c(%ecx), %eax\n"
        "jl .Lf207747_0020807e\n"
        "movl %ecx, %edx\n"
        ".Lf207747_00208098:\n"
        "movl 0x104(%edx), %eax\n" /* line 487 */
        "movl -0x60(%ebp), %ecx\n"
        "movl %eax, 0x24(%ecx)\n"
        "movl 0x184(%edx), %eax\n" /* line 494 */
        "testl %eax, %eax\n"
        "jne .Lf207747_0020777c\n"
        "movb $0, 8(%ecx)\n" /* line 495 */
        "movl -0x60(%ebp), %eax\n"
        "jmp .Lf207747_0020777f\n"
        ".Lf207747_002080be:\n"
        "movl %edx, %eax\n"
        "movl -0x7c(%ebp), %edx\n" /* dctbl */
        "jmp .Lf207747_00207834\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3: bits_left */
        /* { scope 4: code */
        /* { scope 5 */
        ".Lf207747_002080c8:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 428 */
        "movl (%eax), %eax\n"
        "movl $0x76, 0x14(%eax)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %edi, %edi\n"
        "jmp .Lf207747_002078f2\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf207747_002080ee:\n"
        "movl %edi, 0xc(%esp)\n" /* line 553 | nb */
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x84(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* br_state */
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf207747_00207f8a\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, -0x84(%ebp)\n" /* get_buffer */
        "movl -0x30(%ebp), %esi\n" /* bits_left */
        "movl %eax, %edx\n"
        "jmp .Lf207747_00207910\n"
    );
}

