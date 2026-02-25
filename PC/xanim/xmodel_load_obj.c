/* ASM dump from: xmodel_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/xmodel_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/consumedata.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/xanim/xanim_local.h"
 *   #include "PC/xanim/xanim_public.h"
 */

int XModelGetStaticBounds(const XModel *model, vec3_t *axis, vec_t *mins, vec_t *maxs);
XModel * XModelLoad(const char *name, Alloc_t Alloc, Alloc_t AllocColl);

/* line 711 */
__attribute__((naked))
int XModelGetStaticBounds(const XModel *model, vec3_t *axis, vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 711 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 718 | model */
        "movl 0x58(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfbbb82_000bbcbc\n"
        "movl $0x7f7fffff, %eax\n" /* line 191 */
        "movl 0x10(%ebp), %edx\n" /* mins */
        "movl %eax, (%edx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl %eax, 8(%edx)\n" /* line 193 */
        "movl $0xff7fffff, %eax\n" /* line 191 */
        "movl 0x14(%ebp), %edx\n" /* maxs */
        "movl %eax, (%edx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl %eax, 8(%edx)\n" /* line 193 */
        "movl 8(%ebp), %eax\n" /* line 728 | model */
        "movl 0x58(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfbbb82_000bbc97\n"
        "movl $0, -0x40(%ebp)\n" /* i */
        "movl $0, -0x3c(%ebp)\n"
        ".Lfbbb82_000bbbd5:\n"
        "movl -0x3c(%ebp), %esi\n" /* line 730 | csurf */
        "movl 8(%ebp), %edx\n" /* model */
        "addl 0x54(%edx), %esi\n" /* csurf */
        "xorl %edi, %edi\n" /* k */
        ".Lfbbb82_000bbbe0:\n"
        "testl $1, %edi\n" /* line 734 | k */
        "je .Lfbbb82_000bbcb4\n"
        "movl 8(%esi), %eax\n" /* csurf */
        ".Lfbbb82_000bbbef:\n"
        "movl %eax, -0x24(%ebp)\n" /* corner */
        "testl $2, %edi\n" /* line 735 | k */
        "je .Lfbbb82_000bbcac\n"
        "movl 0xc(%esi), %eax\n" /* csurf */
        ".Lfbbb82_000bbc01:\n"
        "movl %eax, -0x20(%ebp)\n"
        "testl $4, %edi\n" /* line 736 | k */
        "je .Lfbbb82_000bbca4\n"
        "movl 0x10(%esi), %eax\n" /* csurf */
        ".Lfbbb82_000bbc13:\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 738 | rotated */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* axis */
        "movl %edx, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* corner */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movl $1, %ebx\n"
        ".Lfbbb82_000bbc34:\n"
        "leal (, %ebx, 4), %eax\n" /* line 711 */
        "movl 0x10(%ebp), %edx\n" /* mins */
        "addl %eax, %edx\n"
        "leal -0x30(%ebp), %ecx\n" /* rotated */
        "addl %eax, %ecx\n"
        "movss -4(%ecx), %xmm1\n" /* line 742 */
        "movss -4(%edx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfbbb82_000bbc5e\n"
        "movss %xmm1, -4(%edx)\n" /* line 743 */
        "movss -4(%ecx), %xmm1\n"
        ".Lfbbb82_000bbc5e:\n"
        "addl 0x14(%ebp), %eax\n" /* line 711 | maxs */
        "ucomiss -4(%eax), %xmm1\n" /* line 744 */
        "jbe .Lfbbb82_000bbc6c\n"
        "movss %xmm1, -4(%eax)\n" /* line 745 */
        ".Lfbbb82_000bbc6c:\n"
        "addl $1, %ebx\n"
        "cmpl $4, %ebx\n" /* line 740 */
        "jne .Lfbbb82_000bbc34\n"
        "addl $1, %edi\n" /* line 732 | k */
        "cmpl $8, %edi\n" /* k */
        "jne .Lfbbb82_000bbbe0\n"
        "addl $1, -0x40(%ebp)\n" /* line 728 | i */
        "addl $0x2c, -0x3c(%ebp)\n"
        "movl -0x40(%ebp), %eax\n" /* i */
        "movl 8(%ebp), %edx\n" /* model */
        "cmpl 0x58(%edx), %eax\n"
        "jl .Lfbbb82_000bbbd5\n"
        ".Lfbbb82_000bbc97:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 751 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbbb82_000bbca4:\n"
        "movl 0x1c(%esi), %eax\n" /* line 736 | csurf */
        "jmp .Lfbbb82_000bbc13\n"
        ".Lfbbb82_000bbcac:\n"
        "movl 0x18(%esi), %eax\n" /* line 735 | csurf */
        "jmp .Lfbbb82_000bbc01\n"
        ".Lfbbb82_000bbcb4:\n"
        "movl 0x14(%esi), %eax\n" /* line 734 | csurf */
        "jmp .Lfbbb82_000bbbef\n"
        ".Lfbbb82_000bbcbc:\n"
        "xorl %eax, %eax\n" /* line 728 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 751 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 679 */
__attribute__((naked))
XModel * XModelLoad(const char *name, Alloc_t Alloc, Alloc_t AllocColl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 679 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11bc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        /* { scope 1: config, nameLens, lodFilename, j, ... */
        /* { scope 2: i, i, u, modelParts */
        "movl %ebx, 0xc(%esp)\n" /* line 387 | size */
        "movl $0x21fdc8, 8(%esp)\n" /* "xmodel/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0xc0(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "testl %eax, %eax\n"
        "js .Lfbbcc6_000bc5cb\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 393 | buf */
        "movl %ecx, 4(%esp)\n"
        "leal -0xc0(%ebp), %edi\n" /* filename, j */
        "movl %edi, (%esp)\n" /* j */
        "calll FS_ReadFile\n"
        "cmpl $0, %eax\n" /* line 395 */
        "jl .Lfbbcc6_000bc6ed\n"
        "je .Lfbbcc6_000bc53b\n" /* line 406 */
        "movl -0x1c(%ebp), %edx\n" /* line 413 | buf */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movzwl (%edx), %eax\n" /* line 104 */
        "movw %ax, -0x30(%ebp)\n" /* u */
        "movswl %ax, %ecx\n" /* line 106 */
        /* } scope */
        "cmpw $0x14, %ax\n" /* line 245 */
        "je .Lfbbcc6_000bbd78\n"
        "movl $0x14, 0xc(%esp)\n" /* line 247 */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* size */
        "movl $0x21fe18, (%esp)\n" /* "^1ERROR: xmodel '%s' out of date (version %d, expecting %d)." */
        ".Lfbbcc6_000bbd4d:\n"
        "calll Com_Printf\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 416 | buf */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl $0, -0x1170(%ebp)\n" /* model */
        /* } scope */
        /* } scope */
        ".Lfbbcc6_000bbd67:\n"
        "movl -0x1170(%ebp), %eax\n" /* line 701 | model */
        "addl $0x11bc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: config, nameLens, lodFilename, j, ... */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        ".Lfbbcc6_000bbd78:\n"
        "movzbl 2(%edx), %eax\n" /* line 251 */
        "movb %al, -0xc4(%ebp)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 3(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 254 | u */
        "movl %eax, -0xe0(%ebp)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 7(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 255 | u */
        "movl %eax, -0xdc(%ebp)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0xb(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 256 | u */
        "movl %eax, -0xd8(%ebp)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0xf(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 258 | u */
        "movl %eax, -0xd4(%ebp)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x13(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 259 | u */
        "movl %eax, -0xd0(%ebp)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x17(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        "leal 0x1b(%edx), %ecx\n" /* line 150 */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 260 | u */
        "movl %eax, -0xcc(%ebp)\n"
        "movl $0, -0x1164(%ebp)\n" /* i */
        "leal -0x10f0(%ebp), %esi\n" /* config, trans */
        "movl %esi, %ebx\n" /* trans, size */
        /* { scope 4: buf, pos, filename, filename, ... */
        ".Lfbbcc6_000bbdf1:\n"
        "movl (%ecx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        "addl $4, %ecx\n" /* line 150 */
        "movl %ecx, -0x11ac(%ebp)\n" /* boneInfo */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 264 | u */
        "movl %eax, 0x400(%esi)\n" /* trans */
        "movl %ecx, 4(%esp)\n" /* line 265 */
        "movl %ebx, (%esp)\n" /* size */
        "calll strcpy\n"
        "cld\n" /* line 266 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x11ac(%ebp), %edi\n" /* boneInfo, parentList */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* parentList */
        "notl %ecx\n"
        "movl -0x11ac(%ebp), %eax\n" /* boneInfo */
        "leal -1(%ecx, %eax), %edx\n"
        "leal 1(%edx), %ecx\n"
        "addl $1, -0x1164(%ebp)\n" /* line 262 | i */
        "addl $0x404, %ebx\n" /* size */
        "addl $0x404, %esi\n" /* trans */
        "cmpl $4, -0x1164(%ebp)\n" /* i */
        "jne .Lfbbcc6_000bbdf1\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 1(%edx), %eax\n" /* line 134 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        "addl $5, %edx\n" /* line 135 */
        "movl %edx, -0x1104(%ebp)\n"
        /* } scope */
        "movl %eax, -0xc8(%ebp)\n" /* line 269 */
        /* } scope */
        "xorl %ebx, %ebx\n" /* line 416 | size */
        "xorl %edx, %edx\n"
        "xorl %esi, %esi\n" /* numBones */
        "leal -0x10f0(%ebp), %ecx\n" /* config */
        "movl %ecx, -0x11b0(%ebp)\n"
        "movl %ecx, %edi\n" /* j */
        "movl $0xffffffff, %ecx\n" /* line 896 */
        "movl %esi, %eax\n" /* modelSurfs */
        "repne scasb %es:(%edi), %al\n" /* j */
        "notl %ecx\n"
        "movl %ecx, -0x40(%ebp, %edx, 4)\n" /* line 423 */
        "addl %ecx, %ebx\n" /* line 424 | size */
        "addl $1, %edx\n" /* line 421 */
        "addl $0x404, -0x11b0(%ebp)\n"
        "cmpl $4, %edx\n"
        "je .Lfbbcc6_000bbec4\n"
        ".Lfbbcc6_000bbe9b:\n"
        "movl -0x11b0(%ebp), %edi\n" /* j */
        "movl $0xffffffff, %ecx\n" /* line 896 */
        "movl %esi, %eax\n" /* modelSurfs */
        "repne scasb %es:(%edi), %al\n" /* j */
        "notl %ecx\n"
        "movl %ecx, -0x40(%ebp, %edx, 4)\n" /* line 423 */
        "addl %ecx, %ebx\n" /* line 424 | size */
        "addl $1, %edx\n" /* line 421 */
        "addl $0x404, -0x11b0(%ebp)\n"
        "cmpl $4, %edx\n"
        "jne .Lfbbcc6_000bbe9b\n"
        ".Lfbbcc6_000bbec4:\n"
        "addl $0x90, %ebx\n" /* line 427 | size */
        "movl %ebx, (%esp)\n" /* line 428 | size */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0x1170(%ebp)\n" /* model */
        "movl %ebx, 0x84(%eax)\n" /* line 429 | size */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl -0x1104(%ebp), %ecx\n" /* line 134 */
        "movl (%ecx), %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* u */
        "addl $4, %ecx\n" /* line 135 */
        "movl %ecx, -0x1108(%ebp)\n"
        /* } scope */
        "movl %edx, 0x58(%eax)\n" /* line 281 */
        "testl %edx, %edx\n" /* line 282 */
        "jne .Lfbbcc6_000bc24a\n"
        /* } scope */
        ".Lfbbcc6_000bbefb:\n"
        "movl -0x1170(%ebp), %eax\n" /* line 433 | model */
        "addl $0x90, %eax\n"
        "movl %eax, -0x116c(%ebp)\n" /* lodFilename */
        "movl -0x1170(%ebp), %edx\n" /* line 434 | model */
        "movw $0, 0x7c(%edx)\n"
        "movl %edx, %esi\n" /* numBones */
        "movl $0, -0x10fc(%ebp)\n"
        "leal -0x10f0(%ebp), %ecx\n" /* config */
        "movl %ecx, -0x1118(%ebp)\n"
        "movl $0, -0x118c(%ebp)\n"
        "movl %ecx, -0x1190(%ebp)\n"
        "movl %ecx, %edi\n" /* j */
        "movl %edi, 4(%esp)\n" /* line 437 | j */
        "movl -0x116c(%ebp), %eax\n" /* lodFilename */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x116c(%ebp), %edx\n" /* line 438 | lodFilename */
        "movl %edx, 8(%esi)\n" /* numBones */
        "cmpb $0, (%edx)\n" /* line 439 */
        "jne .Lfbbcc6_000bbfe6\n"
        ".Lfbbcc6_000bbf66:\n"
        "movl $0, 0x10(%esi)\n" /* line 459 | numBones */
        ".Lfbbcc6_000bbf6d:\n"
        "movl -0x1118(%ebp), %ecx\n" /* line 462 */
        "movl 0x400(%ecx), %eax\n"
        "movl %eax, 4(%esi)\n" /* numBones */
        "movl -0x118c(%ebp), %edi\n" /* line 463 | j */
        "movl -0x40(%edi, %ebp), %edi\n" /* j */
        "addl %edi, -0x116c(%ebp)\n" /* j, lodFilename */
        "addl $1, -0x10fc(%ebp)\n" /* line 435 */
        "addl $0x404, -0x1190(%ebp)\n"
        "addl $4, -0x118c(%ebp)\n"
        "addl $0x14, %esi\n" /* numBones */
        "addl $0x404, %ecx\n"
        "movl %ecx, -0x1118(%ebp)\n"
        "cmpl $4, -0x10fc(%ebp)\n"
        "je .Lfbbcc6_000bc0aa\n"
        "movl -0x1190(%ebp), %edi\n" /* j */
        "movl %edi, 4(%esp)\n" /* line 437 | j */
        "movl -0x116c(%ebp), %eax\n" /* lodFilename */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x116c(%ebp), %edx\n" /* line 438 | lodFilename */
        "movl %edx, 8(%esi)\n" /* numBones */
        "cmpb $0, (%edx)\n" /* line 439 */
        "je .Lfbbcc6_000bbf66\n"
        ".Lfbbcc6_000bbfe6:\n"
        "movl -0x1170(%ebp), %ecx\n" /* line 441 | model */
        "addw $1, 0x7c(%ecx)\n"
        /* { scope 3: u, modelName, name */
        "movl -0x1108(%ebp), %edi\n" /* line 104 | parentList */
        "movswl (%edi), %ebx\n" /* parentList */
        "movw %bx, -0x30(%ebp)\n" /* u */
        "addl $2, %edi\n" /* line 105 | parentList */
        "movl %edi, -0x1108(%ebp)\n" /* parentList */
        "leal 0xc(%esi), %eax\n" /* line 679 | modelSurfs */
        "movl %eax, -0x1114(%ebp)\n"
        /* } scope */
        "movw %bx, 0xc(%esi)\n" /* line 443 | size, numBones */
        "addl %ebx, %ebx\n" /* line 445 | size */
        "movl %ebx, (%esp)\n" /* line 446 | size */
        "calll *0xc(%ebp)\n" /* Alloc */
        "leal 0x10(%esi), %edx\n" /* line 679 | modelSurfs */
        "movl %edx, -0x1110(%ebp)\n"
        "movl %eax, 0x10(%esi)\n" /* line 446 | numBones */
        "movl -0x1170(%ebp), %ecx\n" /* line 447 | model */
        "addl %ebx, 0x84(%ecx)\n" /* size */
        "cmpw $0, 0xc(%esi)\n" /* line 449 | numBones */
        "jle .Lfbbcc6_000bbf6d\n"
        "movl $0, -0x1168(%ebp)\n" /* j */
        ".Lfbbcc6_000bc049:\n"
        "movl -0x1108(%ebp), %edx\n" /* line 451 */
        "cld\n" /* line 452 */
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n" /* j */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* j */
        "notl %ecx\n"
        "addl %ecx, -0x1108(%ebp)\n"
        "movl -0x1110(%ebp), %ecx\n" /* line 454 */
        "movl (%ecx), %eax\n"
        "movl -0x1168(%ebp), %edi\n" /* j */
        "leal (%eax, %edi, 2), %ebx\n" /* size */
        "movl $8, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SL_GetString_\n"
        "movw %ax, (%ebx)\n" /* size */
        "addl $1, %edi\n" /* line 449 | j */
        "movl %edi, -0x1168(%ebp)\n" /* j */
        "movl -0x1114(%ebp), %edx\n"
        "movswl (%edx), %eax\n"
        "cmpl %edi, %eax\n" /* j */
        "jg .Lfbbcc6_000bc049\n"
        "jmp .Lfbbcc6_000bbf6d\n"
        ".Lfbbcc6_000bc0aa:\n"
        "movl -0x1170(%ebp), %eax\n" /* line 467 | model */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x1158(%ebp)\n" /* name */
        /* { scope 3: u, modelName, name */
        "movl %eax, (%esp)\n" /* line 349 */
        "calll XModelPartsFindData\n"
        "movl %eax, -0x115c(%ebp)\n" /* modelParts */
        "testl %eax, %eax\n" /* line 350 */
        "je .Lfbbcc6_000bc5f0\n"
        "movl %eax, %ecx\n"
        /* } scope */
        ".Lfbbcc6_000bc0d1:\n"
        "movl -0x1170(%ebp), %edx\n" /* line 467 | model */
        "movl %ecx, (%edx)\n"
        "testl %ecx, %ecx\n" /* line 468 */
        "je .Lfbbcc6_000bc76d\n"
        "movl -0x115c(%ebp), %edx\n" /* line 475 | modelParts */
        "movswl (%edx), %esi\n" /* numBones */
        "leal (%esi, %esi, 4), %ebx\n" /* line 477 | numBones, size */
        "shll $3, %ebx\n" /* size */
        "movl %ebx, (%esp)\n" /* line 478 | size */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0x11ac(%ebp)\n" /* boneInfo */
        "movl -0x1170(%ebp), %ecx\n" /* line 479 | model */
        "addl %ebx, 0x84(%ecx)\n" /* size */
        "testl %esi, %esi\n" /* line 481 | numBones */
        "jg .Lfbbcc6_000bc452\n"
        ".Lfbbcc6_000bc110:\n"
        "movl -0x11ac(%ebp), %edx\n" /* line 500 | boneInfo */
        "movl -0x1170(%ebp), %eax\n" /* model */
        "movl %edx, 0x60(%eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 502 | buf */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl -0x1170(%ebp), %edx\n" /* line 504 | model, to */
        "addl $0x64, %edx\n" /* to */
        /* { scope 3: u, modelName, name */
        "movl -0xe0(%ebp), %eax\n" /* line 199 */
        "movl -0x1170(%ebp), %ecx\n" /* model */
        "movl %eax, 0x64(%ecx)\n"
        "movl -0xdc(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0xd8(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl %ecx, %edx\n" /* line 505 | to */
        "addl $0x70, %edx\n" /* to */
        /* { scope 3: u, modelName, name */
        "movl -0xd4(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x70(%ecx)\n"
        "movl -0xd0(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0xcc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl -0xc8(%ebp), %eax\n" /* line 507 */
        "movw %ax, 0x7e(%ecx)\n"
        "movzbl -0xc4(%ebp), %eax\n" /* line 510 */
        "movb %al, 0x8c(%ecx)\n"
        /* } scope */
        "movl 0x195eca8, %eax\n" /* line 687 */
        "cmpb $0, 0x144(%eax)\n"
        "je .Lfbbcc6_000bbd67\n"
        "movl $0, -0x1128(%ebp)\n" /* lodIndex */
        "addl $4, %ecx\n"
        "movl %ecx, -0x1188(%ebp)\n"
        "movl %ecx, %eax\n"
        /* { scope 2: i, i, u, modelParts */
        "movl 4(%eax), %edi\n" /* line 668 | j */
        "cmpb $0, (%edi)\n" /* j */
        "je .Lfbbcc6_000bc21f\n"
        ".Lfbbcc6_000bc1ba:\n"
        "movl -0x1170(%ebp), %edx\n" /* line 671 | model */
        "movl 0x88(%edx), %edx\n"
        "movl %edx, -0x1124(%ebp)\n" /* modelName */
        "movzwl 8(%eax), %ebx\n" /* modelNumsurfs */
        "movswl %bx, %ecx\n" /* modelNumsurfs */
        "movl %ecx, -0x112c(%ebp)\n"
        /* { scope 3: u, modelName, name */
        "movl %edi, (%esp)\n" /* line 641 | j */
        "calll XModelSurfsFindData\n"
        "movl %eax, %esi\n" /* modelSurfs */
        "testl %eax, %eax\n" /* line 642 */
        "je .Lfbbcc6_000bc54b\n"
        /* } scope */
        ".Lfbbcc6_000bc1eb:\n"
        "movl -0x1188(%ebp), %edi\n" /* line 671 | j */
        "movl %esi, 0x10(%edi)\n" /* modelSurfs, j */
        "testl %esi, %esi\n" /* line 672 | modelSurfs */
        "je .Lfbbcc6_000bc687\n"
        "addl $1, -0x1128(%ebp)\n" /* line 665 | lodIndex */
        "addl $0x14, %edi\n" /* j */
        "movl %edi, -0x1188(%ebp)\n" /* j */
        "cmpl $4, -0x1128(%ebp)\n" /* lodIndex */
        "je .Lfbbcc6_000bc21f\n"
        "movl %edi, %eax\n" /* j */
        "movl 4(%eax), %edi\n" /* line 668 | j */
        "cmpb $0, (%edi)\n" /* j */
        "jne .Lfbbcc6_000bc1ba\n"
        /* } scope */
        ".Lfbbcc6_000bc21f:\n"
        "movl -0x1170(%ebp), %eax\n" /* line 696 | model */
        "movl %eax, (%esp)\n"
        "calll R_LoadXSkins\n"
        "movl -0x1170(%ebp), %edx\n" /* model */
        "movl %eax, 0x80(%edx)\n"
        /* } scope */
        "movl -0x1170(%ebp), %eax\n" /* line 701 | model */
        "addl $0x11bc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: config, nameLens, lodFilename, j, ... */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        ".Lfbbcc6_000bc24a:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 288 */
        "leal (%edx, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x10(%ebp)\n" /* AllocColl */
        "movl -0x1170(%ebp), %edi\n" /* model, j */
        "movl %eax, 0x54(%edi)\n" /* j */
        "movl 0x58(%edi), %eax\n" /* line 290 | j */
        "testl %eax, %eax\n"
        "jle .Lfbbcc6_000bbefb\n"
        "movl $0, -0x1160(%ebp)\n" /* i */
        "movl $0, -0x110c(%ebp)\n"
        "movss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
        "jmp .Lfbbcc6_000bc35a\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        ".Lfbbcc6_000bc28e:\n"
        "movl (%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movss -0x30(%ebp), %xmm0\n" /* line 324 | u */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esi)\n" /* surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 4(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movss -0x30(%ebp), %xmm0\n" /* line 325 | u */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esi)\n" /* surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 8(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movss -0x30(%ebp), %xmm0\n" /* line 326 | u */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%esi)\n" /* surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0xc(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movss -0x30(%ebp), %xmm0\n" /* line 328 | u */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x14(%esi)\n" /* surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x10(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movss -0x30(%ebp), %xmm0\n" /* line 329 | u */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x18(%esi)\n" /* surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x14(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movss -0x30(%ebp), %xmm0\n" /* line 330 | u */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x1c(%esi)\n" /* surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x18(%ebx), %eax\n" /* line 134 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl %eax, 0x20(%esi)\n" /* line 332 | surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x1c(%ebx), %eax\n" /* line 134 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "andl $0xdffffffb, %eax\n" /* line 334 */
        "movl %eax, 0x24(%esi)\n" /* surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x20(%ebx), %eax\n" /* line 134 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        "addl $0x24, %ebx\n" /* line 135 | size */
        "movl %ebx, -0x1108(%ebp)\n" /* size */
        /* } scope */
        "movl %eax, 0x28(%esi)\n" /* line 337 | surf */
        "movl -0x1170(%ebp), %ecx\n" /* line 340 | model */
        "movl 0x5c(%ecx), %eax\n"
        "orl 0x24(%esi), %eax\n" /* surf */
        "movl %eax, 0x5c(%ecx)\n"
        "addl $1, -0x1160(%ebp)\n" /* line 290 | i */
        "addl $0x2c, -0x110c(%ebp)\n"
        "movl -0x1160(%ebp), %edi\n" /* i, j */
        "cmpl 0x58(%ecx), %edi\n" /* j */
        "jge .Lfbbcc6_000bbefb\n"
        ".Lfbbcc6_000bc35a:\n"
        "movl -0x110c(%ebp), %esi\n" /* line 292 | surf */
        "movl -0x1170(%ebp), %eax\n" /* model */
        "addl 0x54(%eax), %esi\n" /* surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl -0x1108(%ebp), %edx\n" /* line 134 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* u */
        "movl %edx, %ebx\n" /* line 135 | size */
        "addl $4, %ebx\n" /* size */
        /* } scope */
        "movl %eax, 4(%esi)\n" /* line 294 | surf */
        "leal (%eax, %eax, 2), %eax\n" /* line 300 */
        "shll $4, %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x11a8(%ebp)\n"
        "calll *0x10(%ebp)\n" /* AllocColl */
        "movl %eax, (%esi)\n" /* surf */
        "movl 4(%esi), %edi\n" /* line 302 | surf, j */
        "testl %edi, %edi\n" /* j */
        "movss -0x11a8(%ebp), %xmm1\n"
        "jle .Lfbbcc6_000bc28e\n"
        "xorl %edi, %edi\n" /* j */
        "xorl %ecx, %ecx\n"
        ".Lfbbcc6_000bc3a9:\n"
        "movl %ecx, %edx\n" /* line 304 */
        "addl (%esi), %edx\n" /* surf */
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl (%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 306 | u */
        "movl %eax, (%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 4(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 307 | u */
        "movl %eax, 4(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 8(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 308 | u */
        "movl %eax, 8(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0xc(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 309 | u */
        "movl %eax, 0xc(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x10(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 313 | u */
        "movl %eax, 0x10(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x14(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 314 | u */
        "movl %eax, 0x14(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x18(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 315 | u */
        "movl %eax, 0x18(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x1c(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 316 | u */
        "movl %eax, 0x1c(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x20(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 318 | u */
        "movl %eax, 0x20(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x24(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 319 | u */
        "movl %eax, 0x24(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x28(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 320 | u */
        "movl %eax, 0x28(%edx)\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        "movl 0x2c(%ebx), %eax\n" /* line 149 | size */
        "movl %eax, -0x30(%ebp)\n" /* u */
        "addl $0x30, %ebx\n" /* line 150 | size */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 321 | u */
        "movl %eax, 0x2c(%edx)\n"
        "addl $1, %edi\n" /* line 302 | j */
        "addl $0x30, %ecx\n"
        "cmpl 4(%esi), %edi\n" /* surf, j */
        "jl .Lfbbcc6_000bc3a9\n"
        "jmp .Lfbbcc6_000bc28e\n"
        /* } scope */
        ".Lfbbcc6_000bc452:\n"
        "movl %eax, %ecx\n" /* line 481 */
        "xorl %ebx, %ebx\n" /* size */
        "movss 0x2ed5d8, %xmm3\n" /* 0.5f */
        /* { scope 3: u, modelName, name */
        ".Lfbbcc6_000bc45e:\n"
        "movl -0x1108(%ebp), %edi\n" /* line 149 | parentList */
        "movl (%edi), %eax\n" /* parentList */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 484 | u */
        "movl %eax, (%ecx)\n"
        /* { scope 3: u, modelName, name */
        "movl 4(%edi), %eax\n" /* line 149 | parentList */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 485 | u */
        "movl %eax, 4(%ecx)\n"
        /* { scope 3: u, modelName, name */
        "movl 8(%edi), %eax\n" /* line 149 | parentList */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 486 | u */
        "movl %eax, 8(%ecx)\n"
        "leal 0xc(%ecx), %edx\n" /* line 488 */
        /* { scope 3: u, modelName, name */
        "movl 0xc(%edi), %eax\n" /* line 149 | parentList */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 489 | u */
        "movl %eax, 0xc(%ecx)\n"
        /* { scope 3: u, modelName, name */
        "movl 0x10(%edi), %eax\n" /* line 149 | parentList */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 490 | u */
        "movl %eax, 4(%edx)\n"
        /* { scope 3: u, modelName, name */
        "movl 0x14(%edi), %eax\n" /* line 149 | parentList */
        "movl %eax, -0x30(%ebp)\n" /* u */
        "addl $0x18, %edi\n" /* line 150 | parentList */
        "movl %edi, -0x1108(%ebp)\n" /* parentList */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 491 | u */
        "movl %eax, 8(%edx)\n"
        "leal 0x18(%ecx), %eax\n" /* line 493 */
        /* { scope 3: u, modelName, name */
        "movss (%ecx), %xmm0\n" /* line 256 */
        "addss 0xc(%ecx), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 0x18(%ecx)\n"
        "movss 4(%ecx), %xmm0\n" /* line 257 */
        "addss 0x10(%ecx), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%ecx), %xmm0\n" /* line 258 */
        "addss 0x14(%ecx), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movss 0xc(%ecx), %xmm0\n" /* line 248 */
        "subss 0x18(%ecx), %xmm0\n"
        "movss 0x10(%ecx), %xmm1\n" /* line 249 */
        "subss 4(%eax), %xmm1\n"
        "movss 0x14(%ecx), %xmm2\n" /* line 250 */
        "subss 8(%eax), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 497 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 0x24(%ecx)\n"
        "addl $1, %ebx\n" /* line 481 | size */
        "addl $0x28, %ecx\n"
        "cmpl %ebx, %esi\n" /* size, numBones */
        "jne .Lfbbcc6_000bc45e\n"
        "jmp .Lfbbcc6_000bc110\n"
        ".Lfbbcc6_000bc53b:\n"
        "movl %ebx, 4(%esp)\n" /* line 408 | size */
        "movl $0x21fdf4, (%esp)\n" /* "^1ERROR: xmodel '%s' has 0 length
" */
        "jmp .Lfbbcc6_000bbd4d\n"
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bc54b:\n"
        "movl %edi, 0xc(%esp)\n" /* line 580 | j */
        "movl $0x21ff54, 8(%esp)\n" /* "xmodelsurfs/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0xc0(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "testl %eax, %eax\n"
        "js .Lfbbcc6_000bc70c\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 586 | buf */
        "movl %ecx, 4(%esp)\n"
        "leal -0xc0(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll FS_ReadFile\n"
        "cmpl $0, %eax\n" /* line 588 */
        "jl .Lfbbcc6_000bc7e9\n"
        "jne .Lfbbcc6_000bc6a4\n" /* line 595 */
        "movl %edi, 4(%esp)\n" /* line 597 | j */
        "movl $0x21ff88, (%esp)\n" /* "^1ERROR: xmodelsurf '%s' has 0 length
" */
        "calll Com_Printf\n"
        "movl -0x1c(%ebp), %eax\n" /* line 598 | buf */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        /* } scope */
        ".Lfbbcc6_000bc5b4:\n"
        "movl %edi, 4(%esp)\n" /* line 648 | j */
        "movl $0x220070, (%esp)\n" /* "^1ERROR: Cannot find 'xmodelsurfs '%s'.
" */
        "calll Com_Printf\n"
        "xorl %esi, %esi\n" /* modelSurfs */
        "jmp .Lfbbcc6_000bc1eb\n"
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        ".Lfbbcc6_000bc5cb:\n"
        "leal -0xc0(%ebp), %edx\n" /* line 389 | filename */
        "movl %edx, 4(%esp)\n"
        "movl $0x21fd24, (%esp)\n" /* "^1ERROR: filename '%s' too long
" */
        "calll Com_Printf\n"
        "movl $0, -0x1170(%ebp)\n" /* model */
        "jmp .Lfbbcc6_000bbd67\n"
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bc5f0:\n"
        "movl -0x1158(%ebp), %edx\n" /* line 115 | name */
        "movl %edx, 0xc(%esp)\n"
        "movl $0x21fe58, 8(%esp)\n" /* "xmodelparts/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x80(%ebp), %ebx\n" /* filename, size */
        "movl %ebx, (%esp)\n" /* size */
        "calll Com_sprintf\n"
        "testl %eax, %eax\n"
        "js .Lfbbcc6_000bc7d4\n"
        "leal -0x20(%ebp), %eax\n" /* line 121 | pos */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* size */
        "calll FS_ReadFile\n"
        "cmpl $0, %eax\n" /* line 123 */
        "jl .Lfbbcc6_000bc891\n"
        "jne .Lfbbcc6_000bc727\n" /* line 130 */
        "movl -0x1158(%ebp), %edi\n" /* line 132 | name, parentList */
        "movl %edi, 4(%esp)\n" /* parentList */
        "movl $0x21fe90, (%esp)\n" /* "^1ERROR: xmodelparts '%s' has 0 length
" */
        "calll Com_Printf\n"
        "movl -0x20(%ebp), %eax\n" /* line 133 | pos */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        /* } scope */
        ".Lfbbcc6_000bc65c:\n"
        "movl -0x1158(%ebp), %eax\n" /* line 356 | name */
        "movl %eax, 4(%esp)\n"
        "movl $0x21ff2c, (%esp)\n" /* "^1ERROR: Cannot find xmodelparts '%s'.
" */
        "calll Com_Printf\n"
        "movl $0, -0x115c(%ebp)\n" /* modelParts */
        "movl -0x115c(%ebp), %ecx\n" /* modelParts */
        "jmp .Lfbbcc6_000bc0d1\n"
        /* } scope */
        /* } scope */
        ".Lfbbcc6_000bc687:\n"
        "movl -0x1170(%ebp), %eax\n" /* line 691 | model */
        "movl %eax, (%esp)\n"
        "calll XModelFree\n"
        "movl $0, -0x1170(%ebp)\n" /* model */
        "jmp .Lfbbcc6_000bbd67\n"
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bc6a4:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 604 | buf */
        "movl %ecx, -0x20(%ebp)\n" /* pos */
        /* { scope 6 */
        "movzwl (%ecx), %edx\n" /* line 104 */
        "movw %dx, -0x30(%ebp)\n" /* u */
        "leal 2(%ecx), %eax\n" /* line 105 */
        "movl %eax, -0x20(%ebp)\n" /* pos */
        "movswl %dx, %esi\n" /* line 106 | i */
        /* } scope */
        "cmpw $0x14, %dx\n" /* line 606 */
        "je .Lfbbcc6_000bc795\n"
        "movl %ecx, (%esp)\n" /* line 608 */
        "calll FS_FreeFile\n"
        "movl $0x14, 0xc(%esp)\n" /* line 609 */
        "movl %esi, 8(%esp)\n" /* numBones */
        "movl %edi, 4(%esp)\n" /* j */
        "movl $0x21ffb0, (%esp)\n" /* "^1ERROR: xmodelsurfs '%s' out of date (version %d, expecting" */
        "calll Com_Printf\n"
        "jmp .Lfbbcc6_000bc5b4\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        ".Lfbbcc6_000bc6ed:\n"
        "movl %ebx, 4(%esp)\n" /* line 402 | size */
        "movl $0x21fdd4, (%esp)\n" /* "^1ERROR: xmodel '%s' not found
" */
        "calll Com_Printf\n"
        "movl $0, -0x1170(%ebp)\n" /* model */
        "jmp .Lfbbcc6_000bbd67\n"
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bc70c:\n"
        "leal -0xc0(%ebp), %edx\n" /* line 582 | filename */
        "movl %edx, 4(%esp)\n"
        "movl $0x21fd24, (%esp)\n" /* "^1ERROR: filename '%s' too long
" */
        "calll Com_Printf\n"
        "jmp .Lfbbcc6_000bc5b4\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bc727:\n"
        "movl -0x20(%ebp), %edx\n" /* line 139 | pos */
        /* { scope 6 */
        "movzwl (%edx), %eax\n" /* line 104 */
        "movw %ax, -0x30(%ebp)\n" /* u */
        "movswl %ax, %ebx\n" /* line 106 */
        /* } scope */
        "cmpw $0x14, %ax\n" /* line 141 */
        "je .Lfbbcc6_000bc7fe\n"
        "movl %edx, (%esp)\n" /* line 143 */
        "calll FS_FreeFile\n"
        "movl $0x14, 0xc(%esp)\n" /* line 144 */
        "movl %ebx, 8(%esp)\n" /* size */
        "movl -0x1158(%ebp), %eax\n" /* name */
        "movl %eax, 4(%esp)\n"
        "movl $0x21feb8, (%esp)\n" /* "^1ERROR: xmodelparts '%s' out of date (version %d, expecting" */
        "calll Com_Printf\n"
        "jmp .Lfbbcc6_000bc65c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfbbcc6_000bc76d:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 470 | buf */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl -0x1170(%ebp), %edi\n" /* line 471 | model, j */
        "movl %edi, (%esp)\n" /* j */
        "calll XModelFree\n"
        "movl $0, -0x1170(%ebp)\n" /* model */
        "jmp .Lfbbcc6_000bbd67\n"
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        /* { scope 6 */
        ".Lfbbcc6_000bc795:\n"
        "movzwl 2(%ecx), %eax\n" /* line 104 */
        "movw %ax, -0x30(%ebp)\n" /* u */
        "leal 4(%ecx), %eax\n" /* line 105 */
        "movl %eax, -0x20(%ebp)\n" /* pos */
        /* } scope */
        "cmpw -0x30(%ebp), %bx\n" /* line 615 | u, size */
        "je .Lfbbcc6_000bc8ac\n"
        "movl %ecx, (%esp)\n" /* line 617 */
        "calll FS_FreeFile\n"
        "movl -0x1124(%ebp), %edx\n" /* line 618 | modelName */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* j */
        "movl $0x21fff4, (%esp)\n" /* "^1ERROR: File conflict (between non-iwd and iwd file) on xmo" */
        "calll Com_Printf\n"
        "jmp .Lfbbcc6_000bc5b4\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bc7d4:\n"
        "movl %ebx, 4(%esp)\n" /* line 117 | size */
        "movl $0x21fd24, (%esp)\n" /* "^1ERROR: filename '%s' too long
" */
        "calll Com_Printf\n"
        "jmp .Lfbbcc6_000bc65c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bc7e9:\n"
        "movl %edi, 4(%esp)\n" /* line 591 | j */
        "movl $0x21ff64, (%esp)\n" /* "^1ERROR: xmodelsurf '%s' not found
" */
        "calll Com_Printf\n"
        "jmp .Lfbbcc6_000bc5b4\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        /* { scope 6 */
        ".Lfbbcc6_000bc7fe:\n"
        "movzwl 2(%edx), %edi\n" /* line 104 | parentList */
        "movw %di, -0x30(%ebp)\n" /* parentList, u */
        /* } scope */
        /* { scope 6 */
        "movzwl 4(%edx), %ecx\n"
        "movw %cx, -0x1176(%ebp)\n"
        "movw %cx, -0x30(%ebp)\n" /* u */
        "addl $6, %edx\n" /* line 105 */
        "movl %edx, -0x1100(%ebp)\n"
        "movswl %cx, %eax\n" /* line 106 */
        "movl %eax, -0x1174(%ebp)\n"
        /* } scope */
        "addl %edi, %ecx\n" /* line 151 | parentList */
        "movw %cx, -0x1142(%ebp)\n" /* numBones */
        "movswl %cx, %edx\n" /* line 153 */
        "movl %edx, -0x1154(%ebp)\n"
        "movl %edx, %ebx\n" /* size */
        "addl %ebx, %ebx\n" /* size */
        "movl %ebx, (%esp)\n" /* line 154 | size */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0x114c(%ebp)\n" /* boneNames */
        "movl -0x1170(%ebp), %ecx\n" /* line 155 | model */
        "addl %ebx, 0x84(%ecx)\n" /* size */
        "cmpw $0x7f, -0x1142(%ebp)\n" /* line 157 | numBones */
        "jle .Lfbbcc6_000bc912\n"
        "movl -0x20(%ebp), %eax\n" /* line 159 | pos */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl $0x7f, 8(%esp)\n" /* line 160 */
        "movl -0x1158(%ebp), %edi\n" /* name, parentList */
        "movl %edi, 4(%esp)\n" /* parentList */
        "movl $0x21fefc, (%esp)\n" /* "^1ERROR: xmodel '%s' has more than %d bones
" */
        "calll Com_Printf\n"
        "jmp .Lfbbcc6_000bc65c\n"
        ".Lfbbcc6_000bc891:\n"
        "movl -0x1158(%ebp), %ecx\n" /* line 126 | name */
        "movl %ecx, 4(%esp)\n"
        "movl $0x21fe68, (%esp)\n" /* "^1ERROR: xmodelparts '%s' not found
" */
        "calll Com_Printf\n"
        "jmp .Lfbbcc6_000bc65c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bc8ac:\n"
        "movl -0x112c(%ebp), %ecx\n" /* line 622 */
        "leal 0x14(, %ecx, 4), %ebx\n" /* size */
        "movl %ebx, (%esp)\n" /* line 623 | size */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, %esi\n" /* numBones */
        "movl -0x1170(%ebp), %eax\n" /* line 624 | model */
        "addl %ebx, 0x84(%eax)\n" /* size */
        "leal 0x14(%esi), %edx\n" /* line 626 | numBones */
        "movl %edx, -0x1120(%ebp)\n"
        "movl %edx, (%esi)\n" /* numBones */
        "leal 4(%esi), %ecx\n" /* line 627 | numBones */
        "movl %ecx, -0x111c(%ebp)\n" /* modelPartBits */
        /* { scope 6 */
        /* { scope 7: u */
        "movl -0x112c(%ebp), %ecx\n" /* line 564 */
        "testl %ecx, %ecx\n"
        "jg .Lfbbcc6_000bcbac\n"
        /* } scope */
        /* } scope */
        ".Lfbbcc6_000bc8ef:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 629 | buf */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %ecx\n" /* line 652 | Alloc */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* modelSurfs */
        "movl %edi, (%esp)\n" /* j */
        "calll XModelSurfsSetData\n"
        "jmp .Lfbbcc6_000bc1eb\n"
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bc912:\n"
        "movswl %di, %eax\n" /* line 164 | parentList */
        "movl %eax, -0x1150(%ebp)\n"
        "movl %eax, %ebx\n" /* size */
        "addl $7, %ebx\n" /* size */
        "movl %ebx, (%esp)\n" /* line 165 | size */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, %esi\n" /* trans */
        "movl -0x1170(%ebp), %edx\n" /* line 166 | model */
        "addl %ebx, 0x84(%edx)\n" /* size */
        "movl -0x114c(%ebp), %ecx\n" /* line 168 | boneNames */
        "movl %ecx, (%eax)\n"
        "leal 4(%eax), %eax\n" /* line 169 */
        "movl %eax, -0x1148(%ebp)\n" /* parentList */
        "movl -0x1154(%ebp), %ebx\n" /* line 171 | size */
        "shll $5, %ebx\n" /* size */
        "addl $0x44, %ebx\n" /* size */
        "movl %ebx, (%esp)\n" /* line 172 | size */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, -0x115c(%ebp)\n" /* modelParts */
        "movl -0x1170(%ebp), %edx\n" /* line 173 | model */
        "addl %ebx, 0x84(%edx)\n" /* size */
        "movl %esi, 4(%eax)\n" /* line 175 | trans */
        "testw %di, %di\n" /* line 177 | parentList */
        "jne .Lfbbcc6_000bcb65\n"
        "movl -0x115c(%ebp), %ecx\n" /* line 189 | modelParts */
        "movl $0, 8(%ecx)\n"
        "movl $0, 0xc(%ecx)\n" /* line 190 */
        ".Lfbbcc6_000bc989:\n"
        "movl -0x1154(%ebp), %edi\n" /* line 194 | parentList */
        "movl %edi, (%esp)\n" /* parentList */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0x115c(%ebp), %edx\n" /* modelParts */
        "movl %eax, 0x10(%edx)\n"
        "movl -0x1170(%ebp), %ecx\n" /* line 195 | model */
        "addl %edi, 0x84(%ecx)\n" /* parentList */
        "movzwl -0x1142(%ebp), %edi\n" /* line 197 | numBones, parentList */
        "movw %di, (%edx)\n" /* parentList */
        "movzwl -0x1176(%ebp), %eax\n" /* line 198 */
        "movw %ax, 2(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 200 */
        "movl 0xc(%edx), %esi\n" /* line 201 | trans */
        "movl -0x1154(%ebp), %edx\n" /* line 203 */
        "cmpl %edx, -0x1174(%ebp)\n"
        "jl .Lfbbcc6_000bcbed\n"
        ".Lfbbcc6_000bc9d7:\n"
        "movl -0x1154(%ebp), %ebx\n" /* line 220 | size */
        "testl %ebx, %ebx\n" /* size */
        "jg .Lfbbcc6_000bcb09\n"
        "movl -0x1100(%ebp), %edx\n"
        ".Lfbbcc6_000bc9eb:\n"
        "movl -0x115c(%ebp), %ecx\n" /* line 227 | modelParts */
        "movl 0x10(%ecx), %eax\n"
        "movl -0x1154(%ebp), %edi\n" /* parentList */
        "movl %edi, 8(%esp)\n" /* parentList */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x20(%ebp), %eax\n" /* line 230 | pos */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* { scope 6 */
        "movl -0x115c(%ebp), %ecx\n" /* line 60 | modelParts */
        "movl 4(%ecx), %edi\n" /* parentList */
        "addl $4, %edi\n" /* parentList */
        "movswl (%ecx), %esi\n" /* line 61 | numBones */
        "movl 8(%ecx), %eax\n" /* line 62 */
        "movl %eax, -0x1140(%ebp)\n" /* quats */
        "movl 0xc(%ecx), %edx\n" /* line 63 */
        "movl %edx, -0x113c(%ebp)\n" /* trans */
        "movl %ecx, %ebx\n" /* line 65 */
        "addl $0x44, %ebx\n"
        "movzwl 2(%ecx), %eax\n" /* line 68 */
        "movswl %ax, %ecx\n"
        "testw %ax, %ax\n"
        "je .Lfbbcc6_000bca8d\n"
        "xorl %edx, %edx\n"
        ".Lfbbcc6_000bca49:\n"
        "movl $0, (%ebx)\n" /* line 183 | size */
        "movl $0, 4(%ebx)\n" /* line 184 | size */
        "movl $0, 8(%ebx)\n" /* line 185 | size */
        "movl $0x3f800000, 0xc(%ebx)\n" /* line 71 */
        "leal 0x10(%ebx), %eax\n" /* line 73 | v */
        /* { scope 7: u */
        "movl $0, 0x10(%ebx)\n" /* line 183 | size */
        "movl $0, 4(%eax)\n" /* line 184 */
        "movl $0, 8(%eax)\n" /* line 185 */
        /* } scope */
        "movl $0x40000000, 0x1c(%ebx)\n" /* line 74 */
        "addl $0x20, %ebx\n" /* line 68 */
        "addl $1, %edx\n"
        "cmpl %ecx, %edx\n"
        "jne .Lfbbcc6_000bca49\n"
        ".Lfbbcc6_000bca8d:\n"
        "movl -0x115c(%ebp), %ecx\n" /* line 78 | modelParts */
        "movswl 2(%ecx), %eax\n"
        "subl %eax, %esi\n" /* numBones */
        "movl %esi, %eax\n" /* numBones */
        "jne .Lfbbcc6_000bccd3\n"
        "movl %ecx, %eax\n"
        "movl %ecx, %edx\n"
        ".Lfbbcc6_000bcaa5:\n"
        "addl $0x14, %eax\n" /* line 89 */
        "movl $0xffffffff, 0x14(%edx)\n"
        "movl $0xffffffff, 4(%eax)\n"
        "movl $0xffffffff, 8(%eax)\n"
        "movl $0xffffffff, 0xc(%eax)\n"
        "movl %edx, %eax\n" /* line 90 */
        "addl $0x34, %eax\n"
        "movl $0xffffffff, 0x34(%edx)\n"
        "movl $0xffffffff, 4(%eax)\n"
        "movl $0xffffffff, 8(%eax)\n"
        "movl $0xffffffff, 0xc(%eax)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %ecx\n" /* line 360 | Alloc */
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x1158(%ebp), %edi\n" /* name, j */
        "movl %edi, (%esp)\n" /* j */
        "calll XModelPartsSetData\n"
        "movl -0x115c(%ebp), %ecx\n" /* modelParts */
        "jmp .Lfbbcc6_000bc0d1\n"
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bcb09:\n"
        "xorl %esi, %esi\n" /* line 220 | trans */
        "movl -0x1100(%ebp), %edi\n" /* parentList */
        ".Lfbbcc6_000bcb11:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* j */
        "movl %ecx, %ebx\n" /* name */
        "notl %ebx\n" /* name */
        "movl $0xa, 0xc(%esp)\n" /* line 223 */
        "movl %ebx, 8(%esp)\n" /* size */
        "movl $0, 4(%esp)\n"
        "movl -0x1100(%ebp), %edi\n" /* parentList */
        "movl %edi, (%esp)\n" /* parentList */
        "calll SL_GetStringOfLen\n"
        "movl -0x114c(%ebp), %edx\n" /* boneNames */
        "movw %ax, (%edx, %esi, 2)\n"
        "addl %ebx, %edi\n" /* line 224 | size, parentList */
        "movl %edi, -0x1100(%ebp)\n" /* parentList */
        "addl $1, %esi\n" /* line 220 | trans */
        "cmpl %esi, -0x1154(%ebp)\n" /* trans */
        "jne .Lfbbcc6_000bcb11\n"
        "movl %edi, %edx\n" /* parentList */
        "jmp .Lfbbcc6_000bc9eb\n"
        ".Lfbbcc6_000bcb65:\n"
        "movl -0x1150(%ebp), %ebx\n" /* line 179 | size */
        "shll $3, %ebx\n" /* size */
        "movl %ebx, (%esp)\n" /* line 180 | size */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0x115c(%ebp), %ecx\n" /* modelParts */
        "movl %eax, 8(%ecx)\n"
        "movl -0x1170(%ebp), %edi\n" /* line 181 | model, parentList */
        "addl %ebx, 0x84(%edi)\n" /* size, parentList */
        "movl -0x1150(%ebp), %ebx\n" /* line 183 | size */
        "shll $4, %ebx\n" /* size */
        "movl %ebx, (%esp)\n" /* line 184 | size */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl -0x115c(%ebp), %edx\n" /* modelParts */
        "movl %eax, 0xc(%edx)\n"
        "addl %ebx, 0x84(%edi)\n" /* line 185 | size, parentList */
        "jmp .Lfbbcc6_000bc989\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        /* { scope 6 */
        /* { scope 7: u */
        ".Lfbbcc6_000bcbac:\n"
        "xorl %ebx, %ebx\n" /* line 564 | surfIndex */
        ".Lfbbcc6_000bcbae:\n"
        "movl 0xc(%ebp), %eax\n" /* line 565 | Alloc */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %edx\n" /* pos */
        "movl %edx, 8(%esp)\n"
        "movl -0x111c(%ebp), %ecx\n" /* modelPartBits */
        "movl %ecx, 4(%esp)\n"
        "movl -0x1170(%ebp), %eax\n" /* model */
        "movl %eax, (%esp)\n"
        "calll XModelReadSurface\n"
        "movl -0x1120(%ebp), %edx\n"
        "movl %eax, (%edx, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 564 | surfIndex */
        "cmpl %ebx, -0x112c(%ebp)\n" /* surfIndex */
        "jne .Lfbbcc6_000bcbae\n"
        "jmp .Lfbbcc6_000bc8ef\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, u, modelParts */
        /* { scope 3: u, modelName, name */
        /* { scope 4: buf, pos, filename, filename, ... */
        /* { scope 5: u, modelPartBits, quats, trans */
        ".Lfbbcc6_000bcbed:\n"
        "xorl %edi, %edi\n" /* line 203 | parentList */
        "movl %eax, %ebx\n" /* size */
        "jmp .Lfbbcc6_000bcc3c\n"
        /* { scope 6 */
        /* { scope 7: u */
        ".Lfbbcc6_000bcbf3:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 81 */
        "sqrtss %xmm0, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x117c(%ebp)\n"
        "cvttss2si -0x117c(%ebp), %eax\n"
        ".Lfbbcc6_000bcc1b:\n"
        "movw %ax, 6(%ebx)\n" /* line 38 */
        /* } scope */
        /* } scope */
        "addl $0xc, %esi\n" /* line 203 | trans */
        "addl $1, %edi\n" /* parentList */
        "addl $8, %ebx\n" /* size */
        "movl -0x1154(%ebp), %eax\n"
        "subl -0x1174(%ebp), %eax\n"
        "cmpl %edi, %eax\n" /* parentList */
        "je .Lfbbcc6_000bc9d7\n"
        ".Lfbbcc6_000bcc3c:\n"
        "movzbl -0x1174(%ebp), %ecx\n" /* line 210 */
        "leal (%edi, %ecx), %eax\n" /* parentList */
        "movl -0x1100(%ebp), %edx\n"
        "subb (%edx), %al\n"
        "movl -0x1148(%ebp), %ecx\n" /* parentList */
        "movb %al, (%ecx, %edi)\n"
        /* { scope 6 */
        "movl 1(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 213 | u */
        "movl %eax, (%esi)\n" /* trans */
        /* { scope 6 */
        "movl 5(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 214 | u */
        "movl %eax, 4(%esi)\n" /* trans */
        /* { scope 6 */
        "movl 9(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 215 | u */
        "movl %eax, 8(%esi)\n" /* trans */
        /* { scope 6 */
        /* { scope 7: u */
        /* { scope 8: xx, yy, yz */
        "movzwl 0xd(%edx), %eax\n" /* line 104 */
        "movw %ax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movw %ax, (%ebx)\n" /* line 25 */
        /* { scope 8: xx, yy, yz */
        "movzwl 0xf(%edx), %eax\n" /* line 104 */
        "movw %ax, -0x30(%ebp)\n" /* u */
        /* } scope */
        "movw %ax, 2(%ebx)\n" /* line 26 */
        /* { scope 8: xx, yy, yz */
        "movzwl 0x11(%edx), %eax\n" /* line 104 */
        "movw %ax, -0x30(%ebp)\n" /* u */
        "addl $0x13, %edx\n" /* line 105 */
        "movl %edx, -0x1100(%ebp)\n"
        "movswl %ax, %ecx\n" /* line 106 */
        /* } scope */
        "movw %ax, 4(%ebx)\n" /* line 27 */
        "movswl (%ebx), %eax\n" /* line 29 */
        "movswl 2(%ebx), %edx\n" /* line 30 */
        "imull %eax, %eax\n" /* line 33 */
        "imull %edx, %edx\n"
        "addl %edx, %eax\n"
        "imull %ecx, %ecx\n"
        "addl %ecx, %eax\n"
        "movl $0x3fff0001, %edx\n"
        "subl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 35 */
        "jg .Lfbbcc6_000bcbf3\n"
        "xorl %eax, %eax\n"
        "jmp .Lfbbcc6_000bcc1b\n"
        /* } scope */
        /* } scope */
        /* { scope 6 */
        ".Lfbbcc6_000bccd3:\n"
        "movl -0x113c(%ebp), %esi\n" /* line 78 | trans, numBones */
        "addl $0xc, %esi\n" /* numBones */
        "leal (%edi, %eax), %eax\n" /* parentList */
        "movl %eax, -0x1180(%ebp)\n"
        "jmp .Lfbbcc6_000bce7f\n"
        /* { scope 7: u */
        ".Lfbbcc6_000bccea:\n"
        "movss 0x2ed5d0, %xmm6\n" /* line 155 | 1.0f */
        "movss %xmm6, -0x1184(%ebp)\n"
        "movss %xmm6, 0xc(%ebx)\n" /* size */
        "movl $0x40000000, 0x1c(%ebx)\n" /* line 156 | size */
        /* } scope */
        ".Lfbbcc6_000bcd06:\n"
        "leal 0x10(%ebx), %edx\n" /* line 86 | out */
        "movzbl (%edi), %eax\n" /* parentList */
        "shll $5, %eax\n"
        "movl %ebx, %ecx\n"
        "subl %eax, %ecx\n"
        /* { scope 7: u */
        /* { scope 8: xx, yy, yz */
        /* { scope 9 */
        "movss 0x1c(%ecx), %xmm3\n" /* line 306 | scale */
        /* { scope 10 */
        "movaps %xmm3, %xmm5\n" /* line 272 */
        "mulss (%ecx), %xmm5\n"
        "movaps %xmm3, %xmm7\n" /* line 273 */
        "mulss 4(%ecx), %xmm7\n"
        "mulss 8(%ecx), %xmm3\n" /* line 274 */
        /* } scope */
        "movaps %xmm5, %xmm0\n" /* line 308 */
        "mulss (%ecx), %xmm0\n"
        "movss %xmm0, -0x1138(%ebp)\n" /* xx */
        "movss 4(%ecx), %xmm6\n" /* line 309 */
        "movaps %xmm5, %xmm2\n"
        "mulss %xmm6, %xmm2\n"
        "movss 8(%ecx), %xmm1\n" /* line 310 */
        "movaps %xmm5, %xmm4\n"
        "mulss %xmm1, %xmm4\n"
        "movss 0xc(%ecx), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm5\n"
        "mulss %xmm7, %xmm6\n" /* line 313 */
        "movss %xmm6, -0x1134(%ebp)\n" /* yy */
        "movaps %xmm7, %xmm6\n" /* line 314 */
        "mulss %xmm1, %xmm6\n"
        "movss %xmm6, -0x1130(%ebp)\n" /* yz */
        "mulss %xmm0, %xmm7\n" /* line 315 */
        "movaps %xmm3, %xmm6\n" /* line 317 */
        "mulss %xmm1, %xmm6\n"
        "mulss %xmm0, %xmm3\n" /* line 318 */
        /* } scope */
        /* } scope */
        "movss -0x1134(%ebp), %xmm0\n" /* line 398 | yy */
        "addss %xmm6, %xmm0\n"
        "movss -0x1184(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss -0xc(%esi), %xmm1\n" /* numBones */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss -8(%esi), %xmm0\n" /* numBones */
        "addss %xmm0, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "addss %xmm7, %xmm0\n"
        "mulss -4(%esi), %xmm0\n" /* numBones */
        "addss %xmm0, %xmm1\n"
        "addss 0x10(%ecx), %xmm1\n"
        "movss %xmm1, 0x10(%ebx)\n" /* size */
        "addss %xmm3, %xmm2\n" /* line 399 */
        "mulss -0xc(%esi), %xmm2\n" /* numBones */
        "addss -0x1138(%ebp), %xmm6\n" /* xx */
        "movss -0x1184(%ebp), %xmm0\n"
        "subss %xmm6, %xmm0\n"
        "mulss -8(%esi), %xmm0\n" /* numBones */
        "addss %xmm0, %xmm2\n"
        "movss -0x1130(%ebp), %xmm0\n" /* yz */
        "subss %xmm5, %xmm0\n"
        "mulss -4(%esi), %xmm0\n" /* numBones */
        "addss %xmm0, %xmm2\n"
        "addss 0x14(%ecx), %xmm2\n"
        "movss %xmm2, 4(%edx)\n"
        "subss %xmm7, %xmm4\n" /* line 400 */
        "mulss -0xc(%esi), %xmm4\n" /* numBones */
        "addss -0x1130(%ebp), %xmm5\n" /* yz */
        "mulss -8(%esi), %xmm5\n" /* numBones */
        "addss %xmm5, %xmm4\n"
        "movss -0x1138(%ebp), %xmm0\n" /* xx */
        "addss -0x1134(%ebp), %xmm0\n" /* yy */
        "movss -0x1184(%ebp), %xmm6\n"
        "subss %xmm0, %xmm6\n"
        "movss %xmm6, -0x1184(%ebp)\n"
        "mulss -4(%esi), %xmm6\n" /* numBones */
        "addss %xmm6, %xmm4\n"
        "addss 0x18(%ecx), %xmm4\n"
        "movss %xmm4, 8(%edx)\n"
        /* } scope */
        "addl $8, -0x1140(%ebp)\n" /* line 78 | quats */
        "addl $0x20, %ebx\n"
        "addl $1, %edi\n" /* parentList */
        "addl $0xc, %esi\n" /* numBones */
        "cmpl %edi, -0x1180(%ebp)\n" /* parentList */
        "je .Lfbbcc6_000bcf59\n"
        ".Lfbbcc6_000bce7f:\n"
        "movl -0x1140(%ebp), %edx\n" /* line 80 | quats */
        "movswl (%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed664, %xmm0\n" /* 3.0518509447574615e-05f */
        "movss %xmm0, -0x30(%ebp)\n" /* u */
        "movswl 2(%edx), %eax\n" /* line 81 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed664, %xmm0\n" /* 3.0518509447574615e-05f */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movswl 4(%edx), %eax\n" /* line 82 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed664, %xmm0\n" /* 3.0518509447574615e-05f */
        "movss %xmm0, -0x28(%ebp)\n"
        "movswl 6(%edx), %eax\n" /* line 83 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed664, %xmm0\n" /* 3.0518509447574615e-05f */
        "movss %xmm0, -0x24(%ebp)\n"
        "movl %ebx, 8(%esp)\n" /* line 84 */
        "movzbl (%edi), %eax\n" /* parentList */
        "shll $5, %eax\n"
        "movl %ebx, %ecx\n"
        "subl %eax, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* u */
        "movl %eax, (%esp)\n"
        "calll QuatMultiply\n"
        /* { scope 7: u */
        "movss (%ebx), %xmm3\n" /* line 567 | surfIndex */
        "movss 4(%ebx), %xmm0\n" /* surfIndex */
        "movss 8(%ebx), %xmm1\n" /* surfIndex */
        "movss 0xc(%ebx), %xmm2\n" /* surfIndex */
        "mulss %xmm3, %xmm3\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "ucomiss 0x2ed5e8, %xmm3\n" /* line 149 | 0.0f */
        "jp .Lfbbcc6_000bcf33\n"
        "je .Lfbbcc6_000bccea\n"
        ".Lfbbcc6_000bcf33:\n"
        "movss 0x2ed62c, %xmm0\n" /* line 151 | 2.0f */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, 0x1c(%ebx)\n" /* size */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x1184(%ebp)\n"
        "jmp .Lfbbcc6_000bcd06\n"
        ".Lfbbcc6_000bcf59:\n"
        "movl -0x115c(%ebp), %eax\n" /* modelParts */
        "movl -0x115c(%ebp), %edx\n" /* modelParts */
        "jmp .Lfbbcc6_000bcaa5\n"
    );
}

