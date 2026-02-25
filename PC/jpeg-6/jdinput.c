/* ASM dump from: jdinput.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdinput.c */

#include "common_types.h"
#include "imports.h"

static void start_input_pass(j_decompress_ptr cinfo);
static void finish_input_pass(j_decompress_ptr cinfo);
static int consume_markers(j_decompress_ptr cinfo);
static void reset_input_controller(j_decompress_ptr cinfo);
void jinit_input_controller(j_decompress_ptr cinfo);

/* line 255 */
static __attribute__((naked))
void start_input_pass(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 255 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 128 | cinfo */
        "movl 0x12c(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1fd5a8_001fd822\n"
        "subl $1, %eax\n" /* line 157 */
        "cmpl $3, %eax\n"
        "ja .Lf1fd5a8_001fd7da\n"
        ".Lf1fd5a8_001fd5ce:\n"
        "movl 8(%ebp), %edx\n" /* line 162 | cinfo */
        "movl 0x118(%edx), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0x140(%ecx)\n"
        "movl 0x11c(%ecx), %eax\n" /* line 165 */
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl %eax, 0x144(%esi)\n"
        "movl $0, 0x148(%esi)\n" /* line 169 */
        "movl 0x12c(%esi), %edi\n" /* line 171 */
        "testl %edi, %edi\n"
        "jle .Lf1fd5a8_001fd6ea\n"
        "movl %esi, -0xc(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* ci */
        "movl %esi, %eax\n"
        ".Lf1fd5a8_001fd637:\n"
        "movl 0x130(%eax), %ecx\n" /* line 172 */
        "movl 8(%ecx), %esi\n" /* line 174 */
        "movl %esi, 0x34(%ecx)\n"
        "movl 0xc(%ecx), %edx\n" /* line 175 */
        "movl %edx, 0x38(%ecx)\n"
        "movl %edx, %edi\n" /* line 176 */
        "imull 0x34(%ecx), %edi\n"
        "movl %edi, 0x3c(%ecx)\n"
        "movl %esi, %eax\n" /* line 177 */
        "imull 0x24(%ecx), %eax\n"
        "movl %eax, 0x40(%ecx)\n"
        "movl 0x1c(%ecx), %eax\n" /* line 179 */
        "xorl %edx, %edx\n"
        "divl %esi\n"
        "testl %edx, %edx\n" /* line 180 */
        "cmovel %esi, %edx\n"
        "movl %edx, 0x44(%ecx)\n" /* line 181 */
        "movl 0x20(%ecx), %eax\n" /* line 182 */
        "xorl %edx, %edx\n"
        "divl 0xc(%ecx)\n"
        "testl %edx, %edx\n" /* line 183 */
        "cmovel 0xc(%ecx), %edx\n"
        "movl %edx, 0x48(%ecx)\n" /* line 184 */
        "movl %edi, %eax\n" /* line 187 */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "addl 0x148(%ecx), %eax\n"
        "cmpl $0xa, %eax\n"
        "jg .Lf1fd5a8_001fd806\n"
        ".Lf1fd5a8_001fd68f:\n"
        "leal -1(%edi), %ecx\n" /* line 189 */
        "testl %edi, %edi\n"
        "jle .Lf1fd5a8_001fd6c8\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x148(%esi), %edx\n"
        "movl %esi, %eax\n"
        "jmp .Lf1fd5a8_001fd6a6\n"
        ".Lf1fd5a8_001fd6a3:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        ".Lf1fd5a8_001fd6a6:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 190 | ci */
        "movl %esi, 0x14c(%eax, %edx, 4)\n"
        "leal 1(%edx), %esi\n"
        "movl %esi, %edx\n"
        "subl $1, %ecx\n" /* line 189 */
        "leal 1(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf1fd5a8_001fd6a3\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %esi, 0x148(%eax)\n"
        ".Lf1fd5a8_001fd6c8:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 171 | ci */
        "addl $4, -0xc(%ebp)\n"
        "movl -0x1c(%ebp), %ecx\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x12c(%edx), %ecx\n"
        "jge .Lf1fd5a8_001fd81b\n"
        "movl -0xc(%ebp), %eax\n"
        "jmp .Lf1fd5a8_001fd637\n"
        ".Lf1fd5a8_001fd6ea:\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        /* } scope */
        /* { scope 1 */
        ".Lf1fd5a8_001fd6ed:\n"
        "movl 0x12c(%esi), %ecx\n" /* line 226 */
        "testl %ecx, %ecx\n"
        "jle .Lf1fd5a8_001fd7ac\n"
        "movl %esi, %edi\n"
        "movl $0, -0x18(%ebp)\n" /* ci */
        "jmp .Lf1fd5a8_001fd71f\n"
        ".Lf1fd5a8_001fd706:\n"
        "addl $1, -0x18(%ebp)\n" /* ci */
        "addl $4, %edi\n"
        "movl -0x18(%ebp), %ecx\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x12c(%edx), %ecx\n"
        "jge .Lf1fd5a8_001fd7aa\n"
        ".Lf1fd5a8_001fd71f:\n"
        "movl 0x130(%edi), %eax\n" /* line 227 */
        "movl %eax, -0x10(%ebp)\n" /* compptr */
        "movl 0x4c(%eax), %edx\n" /* line 229 */
        "testl %edx, %edx\n"
        "jne .Lf1fd5a8_001fd706\n"
        "movl 0x10(%eax), %edx\n" /* line 232 */
        "movl %edx, -0x14(%ebp)\n" /* qtblno */
        "cmpl $3, %edx\n" /* line 233 */
        "ja .Lf1fd5a8_001fd88d\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0x98(%ecx, %edx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1fd5a8_001fd8b0\n"
        ".Lf1fd5a8_001fd750:\n"
        "movl 4(%ecx), %eax\n" /* line 237 */
        "movl $0x82, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, %esi\n"
        "movl -0x14(%ebp), %edx\n" /* line 240 | qtblno */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0x98(%ecx, %edx, 4), %eax\n"
        "movl $0x82, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "movl -0x10(%ebp), %eax\n" /* line 241 | compptr */
        "movl %esi, 0x4c(%eax)\n"
        "addl $1, -0x18(%ebp)\n" /* line 226 | ci */
        "addl $4, %edi\n"
        "movl -0x18(%ebp), %ecx\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x12c(%edx), %ecx\n"
        "jl .Lf1fd5a8_001fd71f\n"
        ".Lf1fd5a8_001fd7aa:\n"
        "movl %edx, %esi\n"
        /* } scope */
        ".Lf1fd5a8_001fd7ac:\n"
        "movl 0x1a0(%esi), %eax\n" /* line 258 */
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0x190(%esi), %eax\n" /* line 259 */
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0x198(%esi), %edx\n" /* line 260 */
        "movl 0x190(%esi), %eax\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "addl $0x30, %esp\n" /* line 261 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1fd5a8_001fd7da:\n"
        "movl 8(%ebp), %esi\n" /* line 158 | cinfo */
        "movl (%esi), %eax\n"
        "movl $0x1a, 0x14(%eax)\n"
        "movl (%esi), %edx\n"
        "movl 0x12c(%esi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n"
        "movl $4, 0x1c(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fd5a8_001fd5ce\n"
        ".Lf1fd5a8_001fd806:\n"
        "movl (%ecx), %eax\n" /* line 188 */
        "movl $0xd, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fd5a8_001fd68f\n"
        ".Lf1fd5a8_001fd81b:\n"
        "movl %edx, %esi\n"
        "jmp .Lf1fd5a8_001fd6ed\n"
        ".Lf1fd5a8_001fd822:\n"
        "movl 0x130(%edx), %ecx\n" /* line 131 */
        "movl 0x1c(%ecx), %eax\n" /* line 134 */
        "movl %eax, 0x140(%edx)\n"
        "movl 0x20(%ecx), %eax\n" /* line 135 */
        "movl %eax, 0x144(%edx)\n"
        "movl $1, 0x34(%ecx)\n" /* line 138 */
        "movl $1, 0x38(%ecx)\n" /* line 139 */
        "movl $1, 0x3c(%ecx)\n" /* line 140 */
        "movl 0x24(%ecx), %eax\n" /* line 141 */
        "movl %eax, 0x40(%ecx)\n"
        "movl $1, 0x44(%ecx)\n" /* line 142 */
        "movl 0xc(%ecx), %edi\n" /* line 146 */
        "movl 0x20(%ecx), %eax\n"
        "xorl %edx, %edx\n"
        "divl %edi\n"
        "testl %edx, %edx\n" /* line 147 */
        "cmovnel %edx, %edi\n"
        "movl %edi, 0x48(%ecx)\n" /* line 148 */
        "movl 8(%ebp), %ecx\n" /* line 151 | cinfo */
        "movl $1, 0x148(%ecx)\n"
        "movl $0, 0x14c(%ecx)\n" /* line 152 */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "jmp .Lf1fd5a8_001fd6ed\n"
        ".Lf1fd5a8_001fd88d:\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        /* } scope */
        /* { scope 1 */
        ".Lf1fd5a8_001fd890:\n"
        "movl (%esi), %eax\n" /* line 235 */
        "movl $0x34, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl -0x14(%ebp), %edx\n" /* qtblno */
        "movl %edx, 0x18(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "jmp .Lf1fd5a8_001fd750\n"
        ".Lf1fd5a8_001fd8b0:\n"
        "movl %ecx, %esi\n"
        "jmp .Lf1fd5a8_001fd890\n"
    );
}

/* line 272 */
static __attribute__((naked))
void finish_input_pass(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 272 */
        "movl %esp, %ebp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 273 | cinfo */
        "movl 0x198(%eax), %edx\n"
        "leal 0x13(%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "popl %ebp\n" /* line 274 */
        "retl\n"
    );
}

/* line 289 */
static __attribute__((naked))
int consume_markers(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: ci */
        "pushl %ebp\n" /* line 289 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0x198(%edi), %eax\n" /* line 290 | cinfo */
        "movl %eax, -0x18(%ebp)\n" /* inputctl */
        "cmpb $0, 0x11(%eax)\n" /* line 293 */
        "je .Lf1fd8cf_001fd8f7\n"
        ".Lf1fd8cf_001fd8e9:\n"
        "movl $2, %esi\n" /* line 323 | val */
        ".Lf1fd8cf_001fd8ee:\n"
        "movl %esi, %eax\n" /* line 331 | val */
        "addl $0x20, %esp\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fd8cf_001fd8f7:\n"
        "movl 0x19c(%edi), %eax\n" /* line 296 | cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "movl %eax, %esi\n" /* val */
        "cmpl $1, %eax\n" /* line 298 */
        "je .Lf1fd8cf_001fd936\n"
        "cmpl $2, %eax\n"
        "jne .Lf1fd8cf_001fd8ee\n"
        "movl -0x18(%ebp), %eax\n" /* line 314 | inputctl */
        "movb $1, 0x11(%eax)\n"
        "cmpb $0, 0x14(%eax)\n" /* line 315 */
        "jne .Lf1fd8cf_001fdaad\n"
        "movl 0x84(%edi), %eax\n" /* line 322 | cinfo */
        "cmpl %eax, 0x8c(%edi)\n" /* cinfo */
        "jle .Lf1fd8cf_001fd8e9\n"
        "movl %eax, 0x8c(%edi)\n" /* line 323 | cinfo */
        "jmp .Lf1fd8cf_001fd8ee\n"
        ".Lf1fd8cf_001fd936:\n"
        "movl -0x18(%ebp), %ecx\n" /* line 300 | inputctl */
        "cmpb $0, 0x14(%ecx)\n"
        "je .Lf1fd8cf_001fda9a\n"
        /* { scope 2 */
        "cmpl $0xffdc, 0x28(%edi)\n" /* line 46 */
        "jg .Lf1fd8cf_001fd955\n"
        "cmpl $0xffdc, 0x24(%edi)\n"
        "jle .Lf1fd8cf_001fd96e\n"
        ".Lf1fd8cf_001fd955:\n"
        "movl (%edi), %eax\n" /* line 48 */
        "movl $0x29, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl $0xffdc, 0x18(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fd8cf_001fd96e:\n"
        "cmpl $8, 0xc8(%edi)\n" /* line 51 */
        "je .Lf1fd8cf_001fd992\n"
        "movl (%edi), %eax\n" /* line 52 */
        "movl $0xf, 0x14(%eax)\n"
        "movl (%edi), %edx\n"
        "movl 0xc8(%edi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fd8cf_001fd992:\n"
        "cmpl $0xa, 0x2c(%edi)\n" /* line 55 */
        "jg .Lf1fd8cf_001fdae4\n"
        ".Lf1fd8cf_001fd99c:\n"
        "movl $1, 0x118(%edi)\n" /* line 60 */
        "movl $1, 0x11c(%edi)\n" /* line 61 */
        "movl 0xcc(%edi), %eax\n" /* line 62 */
        "movl %eax, %esi\n" /* compptr */
        "movl 0x2c(%edi), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1fd8cf_001fda32\n"
        "movl $0, -0x14(%ebp)\n" /* ci */
        ".Lf1fd8cf_001fd9c6:\n"
        "leal 8(%esi), %eax\n" /* line 289 | compptr */
        "movl %eax, -0x10(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 64 | compptr */
        "subl $1, %eax\n"
        "cmpl $3, %eax\n"
        "ja .Lf1fd8cf_001fd9e3\n"
        "movl 0xc(%esi), %eax\n" /* compptr */
        "testl %eax, %eax\n"
        "jle .Lf1fd8cf_001fd9e3\n"
        "cmpl $4, %eax\n"
        "jle .Lf1fd8cf_001fd9f3\n"
        ".Lf1fd8cf_001fd9e3:\n"
        "movl (%edi), %eax\n" /* line 66 */
        "movl $0x12, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fd8cf_001fd9f3:\n"
        "movl 0x118(%edi), %edx\n" /* line 67 */
        "movl -0x10(%ebp), %ecx\n"
        "movl (%ecx), %eax\n"
        "cmpl %edx, %eax\n"
        "cmovll %edx, %eax\n"
        "movl %eax, 0x118(%edi)\n"
        "movl 0x11c(%edi), %edx\n" /* line 69 */
        "movl 0xc(%esi), %eax\n" /* compptr */
        "cmpl %edx, %eax\n"
        "cmovll %edx, %eax\n"
        "movl %eax, 0x11c(%edi)\n"
        "addl $1, -0x14(%ebp)\n" /* line 63 | ci */
        "addl $0x54, %esi\n" /* compptr */
        "movl -0x14(%ebp), %eax\n" /* line 62 | ci */
        "cmpl %eax, 0x2c(%edi)\n"
        "jg .Lf1fd8cf_001fd9c6\n"
        "movl 0xcc(%edi), %eax\n"
        ".Lf1fd8cf_001fda32:\n"
        "movl $8, 0x120(%edi)\n" /* line 77 */
        "movl %eax, %esi\n" /* line 80 | compptr */
        "movl 0x2c(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf1fd8cf_001fdb0a\n"
        ".Lf1fd8cf_001fda49:\n"
        "movl 0x11c(%edi), %eax\n" /* line 108 */
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x124(%edi)\n"
        "movl 0x12c(%edi), %eax\n" /* line 113 */
        "cmpl 0x2c(%edi), %eax\n"
        "jl .Lf1fd8cf_001fda7f\n"
        "cmpb $0, 0xd0(%edi)\n"
        "je .Lf1fd8cf_001fdbb1\n"
        ".Lf1fd8cf_001fda7f:\n"
        "movl 0x198(%edi), %eax\n" /* line 114 */
        "movb $1, 0x10(%eax)\n"
        /* } scope */
        ".Lf1fd8cf_001fda89:\n"
        "movl -0x18(%ebp), %eax\n" /* line 302 | inputctl */
        "movb $0, 0x14(%eax)\n"
        "movl $1, %esi\n" /* val */
        "jmp .Lf1fd8cf_001fd8ee\n"
        ".Lf1fd8cf_001fda9a:\n"
        "cmpb $0, 0x10(%ecx)\n" /* line 308 */
        "je .Lf1fd8cf_001fdad2\n"
        ".Lf1fd8cf_001fdaa0:\n"
        "movl %edi, (%esp)\n" /* line 310 | cinfo */
        "calll start_input_pass\n"
        "jmp .Lf1fd8cf_001fd8ee\n"
        ".Lf1fd8cf_001fdaad:\n"
        "movl 0x19c(%edi), %eax\n" /* line 316 | cinfo */
        "cmpb $0, 0xd(%eax)\n"
        "je .Lf1fd8cf_001fd8e9\n"
        "movl (%edi), %eax\n" /* line 317 | cinfo */
        "movl $0x3b, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1fd8cf_001fd8ee\n"
        ".Lf1fd8cf_001fdad2:\n"
        "movl (%edi), %eax\n" /* line 309 | cinfo */
        "movl $0x23, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1fd8cf_001fdaa0\n"
        /* { scope 2 */
        ".Lf1fd8cf_001fdae4:\n"
        "movl (%edi), %eax\n" /* line 56 */
        "movl $0x1a, 0x14(%eax)\n"
        "movl (%edi), %edx\n"
        "movl 0x2c(%edi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%edi), %eax\n"
        "movl $0xa, 0x1c(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fd8cf_001fd99c\n"
        ".Lf1fd8cf_001fdb0a:\n"
        "movl $0, -0xc(%ebp)\n" /* line 80 */
        ".Lf1fd8cf_001fdb11:\n"
        "movl $8, 0x24(%esi)\n" /* line 82 | compptr */
        "movl 0x118(%edi), %eax\n" /* line 84 */
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%edi), %eax\n"
        "imull 8(%esi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x1c(%esi)\n" /* compptr */
        "movl 0x11c(%edi), %eax\n" /* line 87 */
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n"
        "imull 0xc(%esi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x20(%esi)\n" /* compptr */
        "movl 0x118(%edi), %eax\n" /* line 95 */
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%edi), %eax\n"
        "imull 8(%esi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x28(%esi)\n" /* compptr */
        "movl 0x11c(%edi), %eax\n" /* line 98 */
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n"
        "imull 0xc(%esi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x2c(%esi)\n" /* compptr */
        "movb $1, 0x30(%esi)\n" /* line 102 | compptr */
        "movl $0, 0x4c(%esi)\n" /* line 104 | compptr */
        "addl $1, -0xc(%ebp)\n" /* line 81 */
        "addl $0x54, %esi\n" /* compptr */
        "movl -0xc(%ebp), %ecx\n" /* line 80 */
        "cmpl 0x2c(%edi), %ecx\n"
        "jl .Lf1fd8cf_001fdb11\n"
        "jmp .Lf1fd8cf_001fda49\n"
        ".Lf1fd8cf_001fdbb1:\n"
        "movl 0x198(%edi), %eax\n" /* line 116 */
        "movb $0, 0x10(%eax)\n"
        "jmp .Lf1fd8cf_001fda89\n"
    );
}

/* line 340 */
static __attribute__((naked))
void reset_input_controller(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 340 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x198(%esi), %eax\n" /* line 341 | cinfo, inputctl */
        "leal -0x2fe(%ebx), %edx\n" /* line 343 */
        "movl %edx, (%eax)\n"
        "movb $0, 0x10(%eax)\n" /* line 344 */
        "movb $0, 0x11(%eax)\n" /* line 345 */
        "movb $1, 0x14(%eax)\n" /* line 346 */
        "movl (%esi), %eax\n" /* line 348 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *0x10(%eax)\n"
        "movl 0x19c(%esi), %eax\n" /* line 349 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl $0, 0x94(%esi)\n" /* line 351 | cinfo */
        "addl $0x10, %esp\n" /* line 352 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 362 */
__attribute__((naked))
void jinit_input_controller(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 362 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 4(%esi), %eax\n" /* line 366 | cinfo */
        "movl $0x18, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x198(%esi)\n" /* line 369 | cinfo */
        "leal -0x34c(%ebx), %edx\n" /* line 371 */
        "movl %edx, (%eax)\n"
        "leal -0x5b(%ebx), %edx\n" /* line 372 */
        "movl %edx, 4(%eax)\n"
        "leal -0x673(%ebx), %edx\n" /* line 373 */
        "movl %edx, 8(%eax)\n"
        "leal -0x367(%ebx), %edx\n" /* line 374 */
        "movl %edx, 0xc(%eax)\n"
        "movb $0, 0x10(%eax)\n" /* line 378 */
        "movb $0, 0x11(%eax)\n" /* line 379 */
        "movb $1, 0x14(%eax)\n" /* line 380 */
        "addl $0x10, %esp\n" /* line 381 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

