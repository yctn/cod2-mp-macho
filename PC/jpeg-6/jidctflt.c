/* ASM dump from: jidctflt.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jidctflt.c */

#include "common_types.h"
#include "imports.h"

void jpeg_idct_float(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col);

/* line 71 */
__attribute__((naked))
void jpeg_idct_float(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 79 | cinfo */
        "movl 0x128(%eax), %eax\n"
        "subl $-0x80, %eax\n"
        "movl %eax, -0x13c(%ebp)\n" /* range_limit */
        "movl 0xc(%ebp), %eax\n" /* line 87 | compptr */
        "movl 0x50(%eax), %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* coef_block */
        "leal -0x118(%ebp), %esi\n" /* workspace, wsptr */
        "movl $8, -0x124(%ebp)\n"
        "jmp .Lf21359c_002137e2\n"
        ".Lf21359c_002135dd:\n"
        "leal 0x20(%edx), %edi\n" /* line 99 */
        "movl %edi, -0x138(%ebp)\n"
        "cmpw $0, 0x20(%edx)\n"
        "je .Lf21359c_0021382b\n"
        "leal 0x40(%edx), %eax\n"
        "movl %eax, -0x134(%ebp)\n"
        "leal 0x60(%edx), %edi\n"
        "movl %edi, -0x130(%ebp)\n"
        "leal 0x30(%edx), %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "leal 0x50(%edx), %edi\n"
        "movl %edi, -0x128(%ebp)\n"
        "leal 0x70(%edx), %edi\n"
        ".Lf21359c_00213618:\n"
        "movswl (%edx), %eax\n" /* line 123 */
        "cvtsi2ssl %eax, %xmm4\n"
        "mulss (%ecx), %xmm4\n"
        "movl -0x138(%ebp), %eax\n" /* line 124 */
        "movswl (%eax), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x40(%ecx), %xmm0\n"
        "movl -0x134(%ebp), %eax\n" /* line 125 */
        "movswl (%eax), %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "mulss 0x80(%ecx), %xmm2\n"
        "movl -0x130(%ebp), %eax\n" /* line 126 */
        "movswl (%eax), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss 0xc0(%ecx), %xmm1\n"
        "movaps %xmm4, %xmm6\n" /* line 128 */
        "addss %xmm2, %xmm6\n"
        "subss %xmm2, %xmm4\n" /* line 129 */
        "movaps %xmm0, %xmm2\n" /* line 131 */
        "addss %xmm1, %xmm2\n"
        "subss %xmm1, %xmm0\n" /* line 132 */
        "leal 0xda407(%ebx), %eax\n" /* 1.4142135381698608f */
        "mulss (%eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movaps %xmm6, %xmm1\n" /* line 134 */
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x11c(%ebp)\n"
        "subss %xmm2, %xmm6\n" /* line 135 */
        "movaps %xmm4, %xmm2\n" /* line 136 */
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x120(%ebp)\n"
        "subss %xmm0, %xmm4\n" /* line 137 */
        "movswl -0x146(%ebp), %eax\n" /* line 141 */
        "cvtsi2ssl %eax, %xmm3\n"
        "mulss 0x20(%ecx), %xmm3\n"
        "movl -0x12c(%ebp), %eax\n" /* line 142 */
        "movswl (%eax), %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "mulss 0x60(%ecx), %xmm2\n"
        "movl -0x128(%ebp), %eax\n" /* line 143 */
        "movswl (%eax), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0xa0(%ecx), %xmm0\n"
        "movswl (%edi), %eax\n" /* line 144 */
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss 0xe0(%ecx), %xmm1\n"
        "movaps %xmm2, %xmm7\n" /* line 146 */
        "addss %xmm0, %xmm7\n"
        "subss %xmm2, %xmm0\n" /* line 147 */
        "movaps %xmm3, %xmm2\n" /* line 148 */
        "addss %xmm1, %xmm2\n"
        "subss %xmm1, %xmm3\n" /* line 149 */
        "movaps %xmm7, %xmm5\n" /* line 151 */
        "addss %xmm2, %xmm5\n"
        "movaps %xmm0, %xmm1\n" /* line 154 */
        "addss %xmm3, %xmm1\n"
        "leal 0xda527(%ebx), %edi\n" /* 1.8477590084075928f */
        "mulss (%edi), %xmm1\n"
        "leal 0xda52b(%ebx), %eax\n" /* line 158 | -2.613126039505005f */
        "mulss (%eax), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "subss %xmm5, %xmm0\n"
        "subss %xmm7, %xmm2\n" /* line 159 */
        "leal 0xda407(%ebx), %edi\n" /* 1.4142135381698608f */
        "mulss (%edi), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "leal 0xda52f(%ebx), %eax\n" /* line 160 | 1.0823922157287598f */
        "mulss (%eax), %xmm3\n"
        "subss %xmm1, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "movss -0x11c(%ebp), %xmm1\n" /* line 162 */
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, (%esi)\n" /* wsptr */
        "movss -0x11c(%ebp), %xmm1\n" /* line 163 */
        "subss %xmm5, %xmm1\n"
        "movss %xmm1, 0xe0(%esi)\n" /* wsptr */
        "movss -0x120(%ebp), %xmm1\n" /* line 164 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x20(%esi)\n" /* wsptr */
        "movss -0x120(%ebp), %xmm1\n" /* line 165 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc0(%esi)\n" /* wsptr */
        "movaps %xmm4, %xmm0\n" /* line 166 */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 0x40(%esi)\n" /* wsptr */
        "subss %xmm2, %xmm4\n" /* line 167 */
        "movss %xmm4, 0xa0(%esi)\n" /* wsptr */
        "movaps %xmm6, %xmm0\n" /* line 168 */
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, 0x80(%esi)\n" /* wsptr */
        "subss %xmm3, %xmm6\n" /* line 169 */
        "movss %xmm6, 0x60(%esi)\n" /* wsptr */
        "addl $2, %edx\n" /* line 171 */
        "addl $4, %ecx\n" /* line 172 */
        "addl $4, %esi\n" /* line 173 | wsptr */
        ".Lf21359c_002137d5:\n"
        "subl $1, -0x124(%ebp)\n" /* line 89 */
        "je .Lf21359c_00213862\n"
        ".Lf21359c_002137e2:\n"
        "movzwl 0x10(%edx), %eax\n" /* line 99 */
        "movw %ax, -0x146(%ebp)\n"
        "testw %ax, %ax\n"
        "je .Lf21359c_002135dd\n"
        /* { scope 2 */
        "leal 0x20(%edx), %eax\n" /* line 118 */
        "movl %eax, -0x138(%ebp)\n"
        "leal 0x40(%edx), %edi\n"
        "movl %edi, -0x134(%ebp)\n"
        "leal 0x60(%edx), %eax\n"
        "movl %eax, -0x130(%ebp)\n"
        "leal 0x30(%edx), %edi\n"
        "movl %edi, -0x12c(%ebp)\n"
        "leal 0x50(%edx), %eax\n"
        "movl %eax, -0x128(%ebp)\n"
        ".Lf21359c_00213823:\n"
        "leal 0x70(%edx), %edi\n"
        "jmp .Lf21359c_00213618\n"
        /* } scope */
        ".Lf21359c_0021382b:\n"
        "leal 0x30(%edx), %eax\n" /* line 99 */
        "movl %eax, -0x12c(%ebp)\n"
        "cmpw $0, 0x30(%edx)\n"
        "je .Lf21359c_00213a5e\n"
        "leal 0x40(%edx), %edi\n"
        "movl %edi, -0x134(%ebp)\n"
        "leal 0x60(%edx), %eax\n"
        "movl %eax, -0x130(%ebp)\n"
        "leal 0x50(%edx), %edi\n"
        "movl %edi, -0x128(%ebp)\n"
        "leal 0x70(%edx), %edi\n"
        "jmp .Lf21359c_00213618\n"
        ".Lf21359c_00213862:\n"
        "leal -0xf8(%ebp), %ecx\n" /* line 89 */
        "movl $1, %esi\n" /* wsptr */
        ".Lf21359c_0021386d:\n"
        "movl 0x18(%ebp), %edx\n" /* line 181 | output_col */
        "movl 0x14(%ebp), %eax\n" /* output_buf */
        "addl -4(%eax, %esi, 4), %edx\n"
        "movss -0x20(%ecx), %xmm4\n" /* line 190 */
        "movss -0x10(%ecx), %xmm0\n"
        "movaps %xmm4, %xmm7\n"
        "addss %xmm0, %xmm7\n"
        "subss %xmm0, %xmm4\n" /* line 191 */
        "movss -0x18(%ecx), %xmm0\n" /* line 193 */
        "movss -8(%ecx), %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "subss %xmm2, %xmm0\n" /* line 194 */
        "leal 0xda407(%ebx), %edi\n" /* 1.4142135381698608f */
        "mulss (%edi), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movaps %xmm7, %xmm6\n" /* line 196 */
        "addss %xmm1, %xmm6\n"
        "subss %xmm1, %xmm7\n" /* line 197 */
        "movaps %xmm4, %xmm1\n" /* line 198 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x144(%ebp)\n" /* tmp1 */
        "subss %xmm0, %xmm4\n" /* line 199 */
        "movss -0xc(%ecx), %xmm1\n" /* line 203 */
        "movss -0x14(%ecx), %xmm0\n"
        "movaps %xmm1, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x140(%ebp)\n" /* z13 */
        "subss %xmm0, %xmm1\n" /* line 204 */
        "movss -0x1c(%ecx), %xmm3\n" /* line 205 */
        "movss -4(%ecx), %xmm0\n"
        "movaps %xmm3, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "subss %xmm0, %xmm3\n" /* line 206 */
        "movss -0x140(%ebp), %xmm5\n" /* line 208 | z13 */
        "addss %xmm2, %xmm5\n"
        "movaps %xmm1, %xmm0\n" /* line 211 */
        "addss %xmm3, %xmm0\n"
        "leal 0xda527(%ebx), %eax\n" /* 1.8477590084075928f */
        "mulss (%eax), %xmm0\n"
        "leal 0xda52b(%ebx), %edi\n" /* line 215 | -2.613126039505005f */
        "mulss (%edi), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "subss -0x140(%ebp), %xmm2\n" /* line 216 | z13 */
        "leal 0xda407(%ebx), %eax\n" /* 1.4142135381698608f */
        "mulss (%eax), %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "leal 0xda52f(%ebx), %edi\n" /* line 217 | 1.0823922157287598f */
        "mulss (%edi), %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "movaps %xmm6, %xmm0\n" /* line 221 */
        "addss %xmm5, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "addl $4, %eax\n"
        "sarl $3, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x13c(%ebp), %edi\n" /* range_limit */
        "movzbl (%edi, %eax), %eax\n"
        "movb %al, (%edx)\n"
        "subss %xmm5, %xmm6\n" /* line 223 */
        "cvttss2si %xmm6, %eax\n"
        "addl $4, %eax\n"
        "sarl $3, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "movb %al, 7(%edx)\n"
        "movss -0x144(%ebp), %xmm0\n" /* line 225 | tmp1 */
        "addss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "addl $4, %eax\n"
        "sarl $3, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "movb %al, 1(%edx)\n"
        "movss -0x144(%ebp), %xmm0\n" /* line 227 | tmp1 */
        "subss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "addl $4, %eax\n"
        "sarl $3, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "movb %al, 6(%edx)\n"
        "movaps %xmm4, %xmm0\n" /* line 229 */
        "addss %xmm2, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "addl $4, %eax\n"
        "sarl $3, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "movb %al, 2(%edx)\n"
        "subss %xmm2, %xmm4\n" /* line 231 */
        "cvttss2si %xmm4, %eax\n"
        "addl $4, %eax\n"
        "sarl $3, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "movb %al, 5(%edx)\n"
        "movaps %xmm7, %xmm0\n" /* line 233 */
        "addss %xmm3, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "addl $4, %eax\n"
        "sarl $3, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "movb %al, 4(%edx)\n"
        "subss %xmm3, %xmm7\n" /* line 235 */
        "cvttss2si %xmm7, %eax\n"
        "addl $4, %eax\n"
        "sarl $3, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "movb %al, 3(%edx)\n"
        "addl $0x20, %ecx\n"
        "addl $1, %esi\n" /* wsptr */
        "cmpl $9, %esi\n" /* line 180 | wsptr */
        "jne .Lf21359c_0021386d\n"
        "addl $0x14c, %esp\n" /* line 240 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf21359c_00213a5e:\n"
        "leal 0x40(%edx), %eax\n" /* line 99 */
        "movl %eax, -0x134(%ebp)\n"
        "cmpw $0, 0x40(%edx)\n"
        "je .Lf21359c_00213a88\n"
        "leal 0x60(%edx), %edi\n"
        "movl %edi, -0x130(%ebp)\n"
        "leal 0x50(%edx), %eax\n"
        "movl %eax, -0x128(%ebp)\n"
        "leal 0x70(%edx), %edi\n"
        "jmp .Lf21359c_00213618\n"
        ".Lf21359c_00213a88:\n"
        "leal 0x50(%edx), %edi\n"
        "movl %edi, -0x128(%ebp)\n"
        "cmpw $0, 0x50(%edx)\n"
        "jne .Lf21359c_00213b06\n"
        "leal 0x60(%edx), %edi\n"
        "movl %edi, -0x130(%ebp)\n"
        "cmpw $0, 0x60(%edx)\n"
        "jne .Lf21359c_00213823\n"
        "leal 0x70(%edx), %edi\n"
        "cmpw $0, 0x70(%edx)\n"
        "jne .Lf21359c_00213618\n"
        /* { scope 2 */
        "movswl (%edx), %eax\n" /* line 104 */
        "cvtsi2ssl %eax, %xmm0\n" /* dcval */
        "mulss (%ecx), %xmm0\n" /* dcval */
        "movss %xmm0, (%esi)\n" /* line 106 | wsptr */
        "movss %xmm0, 0x20(%esi)\n" /* line 107 | wsptr */
        "movss %xmm0, 0x40(%esi)\n" /* line 108 | wsptr */
        "movss %xmm0, 0x60(%esi)\n" /* line 109 | wsptr */
        "movss %xmm0, 0x80(%esi)\n" /* line 110 | wsptr */
        "movss %xmm0, 0xa0(%esi)\n" /* line 111 | wsptr */
        "movss %xmm0, 0xc0(%esi)\n" /* line 112 | wsptr */
        "movss %xmm0, 0xe0(%esi)\n" /* line 113 | wsptr */
        "addl $2, %edx\n" /* line 115 */
        "addl $4, %ecx\n" /* line 116 */
        "addl $4, %esi\n" /* line 117 | wsptr */
        "jmp .Lf21359c_002137d5\n"
        /* } scope */
        ".Lf21359c_00213b06:\n"
        "leal 0x60(%edx), %eax\n" /* line 99 */
        "movl %eax, -0x130(%ebp)\n"
        "leal 0x70(%edx), %edi\n"
        "jmp .Lf21359c_00213618\n"
    );
}

