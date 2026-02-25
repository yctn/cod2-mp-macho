/* ASM dump from: r_light.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_light.cpp */

#include "common_types.h"
#include "imports.h"

extern struct lightGlob_type lightGlob; /* 0x0 */

GfxLightDef * R_RegisterLightDef(const char *name);
long unsigned int R_InitLightDefs(void);
long unsigned int R_ShutdownLightDefs(void);
int R_GetPointLightPartitions(const GfxDrawSurf *drawSurfs, int drawSurfCount, PointLightPartition *partitions, int partitionLimit);

/* line 21 */
__attribute__((naked))
GfxLightDef * R_RegisterLightDef(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 21 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        "movl 0x195eee0, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 1 */
        "movl lightGlob, %eax\n" /* line 28 */
        "testl %eax, %eax\n"
        "jg .Lfee408_000ee462\n"
        ".Lfee408_000ee425:\n"
        "cmpl $0x40, %eax\n" /* line 36 */
        "je .Lfee408_000ee4c0\n"
        "movl %edi, (%esp)\n" /* line 44 | name */
        "calll R_LoadLightDef\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 46 */
        "jne .Lfee408_000ee507\n"
        ".Lfee408_000ee440:\n"
        "movl $0x225974, 4(%esp)\n" /* line 48 */
        "movl %edi, (%esp)\n" /* name */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfee408_000ee4a1\n"
        "movl $0x225974, %edi\n" /* line 49 | name */
        ".Lfee408_000ee459:\n"
        "movl lightGlob, %eax\n" /* line 28 */
        "testl %eax, %eax\n"
        "jle .Lfee408_000ee425\n"
        ".Lfee408_000ee462:\n"
        "xorl %esi, %esi\n" /* defIndex */
        "movl $lightGlob, %ebx\n"
        "jmp .Lfee408_000ee47a\n"
        ".Lfee408_000ee46b:\n"
        "addl $1, %esi\n" /* defIndex */
        "movl lightGlob, %eax\n"
        "addl $4, %ebx\n"
        "cmpl %eax, %esi\n" /* defIndex */
        "jge .Lfee408_000ee425\n"
        ".Lfee408_000ee47a:\n"
        "movl 4(%ebx), %eax\n" /* line 32 */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* name */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfee408_000ee46b\n"
        "movl 0x1218824(, %esi, 4), %ecx\n" /* line 33 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 57 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfee408_000ee4a1:\n"
        "movl %edi, 8(%esp)\n" /* line 49 | name */
        "movl $0x225984, 4(%esp)\n" /* "Can't load the default light def '%s'" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl $0x225974, %edi\n" /* name */
        "jmp .Lfee408_000ee459\n"
        ".Lfee408_000ee4c0:\n"
        "movl $0x225920, 4(%esp)\n" /* line 38 */
        "movl $0, (%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "calll *(%eax)\n"
        "movl lightGlob, %eax\n" /* line 39 */
        "testl %eax, %eax\n"
        "jg .Lfee408_000ee529\n"
        ".Lfee408_000ee4dd:\n"
        "movl %eax, 8(%esp)\n" /* line 41 */
        "movl $0x225934, 4(%esp)\n" /* "Can't load light def %s; %i unique light defs already loaded" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl %edi, (%esp)\n" /* line 44 | name */
        "calll R_LoadLightDef\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 46 */
        "je .Lfee408_000ee440\n"
        ".Lfee408_000ee507:\n"
        "movl lightGlob, %edx\n" /* line 53 */
        "movl $lightGlob, %eax\n"
        "movl %ecx, 4(%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 54 */
        "movl %edx, lightGlob\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 57 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfee408_000ee529:\n"
        "xorl %esi, %esi\n" /* line 39 | defIndex */
        "movl $lightGlob, %ebx\n"
        ".Lfee408_000ee530:\n"
        "movl 4(%ebx), %eax\n" /* line 40 */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2182fc, 4(%esp)\n" /* "  %s
" */
        "movl $0, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "addl $1, %esi\n" /* line 39 | defIndex */
        "movl lightGlob, %eax\n"
        "addl $4, %ebx\n"
        "cmpl %eax, %esi\n" /* defIndex */
        "jl .Lfee408_000ee530\n"
        "jmp .Lfee408_000ee4dd\n"
    );
}

/* line 62 */
__attribute__((naked))
long unsigned int R_InitLightDefs(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 62 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x225974, (%esp)\n" /* line 67 */
        "calll R_RegisterLightDef\n"
        "movl 0x195eebc, %edx\n"
        "movl %eax, 0x1028(%edx)\n"
        "leave\n" /* line 68 */
        "retl\n"
    );
}

/* line 71 */
__attribute__((naked))
long unsigned int R_ShutdownLightDefs(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "movl $0, lightGlob\n" /* line 74 */
        "popl %ebp\n" /* line 76 */
        "retl\n"
    );
}

/* line 205 */
__attribute__((naked))
int R_GetPointLightPartitions(const GfxDrawSurf *drawSurfs, int drawSurfCount, PointLightPartition *partitions, int partitionLimit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 205 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10c, %esp\n"
        "movl 0x14(%ebp), %esi\n" /* partitionLimit */
        /* { scope 1: lights, origin */
        "movl 0x195f0f4, %eax\n" /* line 217 */
        "movl %eax, -0xf4(%ebp)\n"
        "movl 0x14(%eax), %ebx\n" /* light1 */
        "testl %ebx, %ebx\n" /* light1 */
        "jg .Lfee594_000eea12\n"
        "movl $0, -0xa4(%ebp)\n"
        ".Lfee594_000ee5c3:\n"
        "movl 0x195eeac, %eax\n" /* line 227 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpl %esi, %eax\n" /* partitionLimit */
        "cmovll %eax, %esi\n" /* partitionLimit */
        "movl %esi, -0xe4(%ebp)\n" /* partitionLimit, visibleLimit */
        "movl -0xa4(%ebp), %eax\n" /* line 228 */
        "cmpl %eax, %esi\n" /* partitionLimit */
        "jge .Lfee594_000ee866\n"
        "movl %esi, -0xa0(%ebp)\n" /* partitionLimit */
        "leal -0x98(%ebp), %ecx\n" /* visibleLights */
        "movl %ecx, -0xdc(%ebp)\n" /* lights */
        "movl %ecx, %edi\n"
        /* { scope 2: cutoffDistSq, distSq */
        /* { scope 3: light0 */
        ".Lfee594_000ee5fa:\n"
        "movl (%edi), %edi\n" /* line 154 */
        "movl %edi, -0xd0(%ebp)\n" /* light0 */
        "movl -0xa4(%ebp), %edi\n"
        "movl $0, -0xe0(%ebp)\n" /* visibleCount */
        ".Lfee594_000ee612:\n"
        "movl 0x195eec8, %esi\n"
        "addl $4, %esi\n"
        "movl -0xd0(%ebp), %ebx\n" /* light0 */
        "addl $4, %ebx\n"
        ".Lfee594_000ee624:\n"
        "addl $1, -0xe0(%ebp)\n" /* line 159 | visibleCount */
        "cmpl -0xe0(%ebp), %edi\n" /* line 157 | visibleCount */
        "jg .Lfee594_000ee737\n"
        ".Lfee594_000ee637:\n"
        "movl -0xdc(%ebp), %edx\n" /* lights */
        "leal -4(%edx, %edi, 4), %eax\n" /* light0 */
        "movl 0x195eec8, %ecx\n"
        "addl $4, %ecx\n"
        "movl %ecx, -0xec(%ebp)\n"
        "movl -0xd0(%ebp), %ebx\n" /* light0 */
        "addl $4, %ebx\n"
        "movl %ebx, -0xf0(%ebp)\n"
        ".Lfee594_000ee65f:\n"
        "subl $1, %edi\n" /* line 164 */
        "cmpl %edi, -0xe0(%ebp)\n" /* line 162 | visibleCount */
        "jg .Lfee594_000ee7df\n"
        "movl %eax, %esi\n"
        "movl (%eax), %ebx\n" /* light1 */
        /* { scope 4 */
        "movl -0xd0(%ebp), %eax\n" /* line 128 | light0 */
        "movss 0x10(%eax), %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss 0x10(%ebx), %xmm0\n" /* line 129 */
        "movss %xmm0, -0xc8(%ebp)\n"
        "movl -0xec(%ebp), %eax\n" /* line 130 */
        "movl %eax, 4(%esp)\n"
        "movl -0xf0(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0xac(%ebp)\n"
        "movl -0xec(%ebp), %ecx\n" /* line 131 */
        "movl %ecx, 4(%esp)\n"
        "addl $4, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0xb0(%ebp)\n"
        "leal -4(%esi), %eax\n"
        /* } scope */
        "movss -0xcc(%ebp), %xmm0\n" /* line 162 */
        "mulss %xmm0, %xmm0\n"
        "mulss -0xb0(%ebp), %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc8(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "mulss -0xac(%ebp), %xmm0\n"
        "movss %xmm0, -0xc8(%ebp)\n"
        "movss -0xcc(%ebp), %xmm0\n"
        "ucomiss -0xc8(%ebp), %xmm0\n"
        "jae .Lfee594_000ee65f\n"
        /* } scope */
        /* } scope */
        "movl -0xe0(%ebp), %ebx\n" /* line 205 | visibleCount, light1 */
        "movl -0xdc(%ebp), %edx\n" /* lights */
        "leal (%edx, %ebx, 4), %eax\n"
        /* { scope 2: cutoffDistSq, distSq */
        /* { scope 3: light0 */
        "movl (%eax), %ecx\n" /* line 170 */
        "movl (%esi), %edx\n" /* line 171 */
        "movl %edx, (%eax)\n"
        "movl %ecx, (%esi)\n" /* line 172 */
        "jmp .Lfee594_000ee612\n"
        ".Lfee594_000ee737:\n"
        "movl -0xe0(%ebp), %edx\n" /* line 157 | visibleCount */
        "movl -0xdc(%ebp), %ecx\n" /* lights */
        "movl (%ecx, %edx, 4), %eax\n" /* light0 */
        /* { scope 4 */
        "movss 0x10(%eax), %xmm0\n" /* line 128 */
        "movss %xmm0, -0xd8(%ebp)\n"
        "movl -0xd0(%ebp), %edx\n" /* line 129 | light0 */
        "movss 0x10(%edx), %xmm0\n"
        "movss %xmm0, -0xd4(%ebp)\n"
        "movl %esi, 4(%esp)\n" /* line 130 */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0xb4(%ebp)\n"
        "movl %esi, 4(%esp)\n" /* line 131 */
        "movl %ebx, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0xb8(%ebp)\n"
        /* } scope */
        "movss -0xd8(%ebp), %xmm0\n" /* line 157 */
        "mulss %xmm0, %xmm0\n"
        "mulss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, -0xd8(%ebp)\n"
        "movss -0xd4(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "mulss -0xb4(%ebp), %xmm0\n"
        "movss %xmm0, -0xd4(%ebp)\n"
        "movss -0xd8(%ebp), %xmm0\n"
        "ucomiss -0xd4(%ebp), %xmm0\n"
        "jae .Lfee594_000ee624\n"
        "jmp .Lfee594_000ee637\n"
        ".Lfee594_000ee7df:\n"
        "movl -0xe0(%ebp), %eax\n" /* line 176 | visibleCount */
        "cmpl %eax, -0xa4(%ebp)\n"
        "je .Lfee594_000ee832\n"
        "movl %eax, %edi\n"
        "cmpl %edi, -0xa0(%ebp)\n" /* line 188 */
        "je .Lfee594_000ee85a\n"
        ".Lfee594_000ee7f7:\n"
        "jle .Lfee594_000ee81b\n" /* line 191 */
        "movl -0xdc(%ebp), %eax\n" /* line 193 | lights */
        "leal (%eax, %edi, 4), %eax\n"
        "movl %eax, -0xdc(%ebp)\n" /* lights */
        "subl %edi, -0xa4(%ebp)\n" /* line 194 */
        "subl %edi, -0xa0(%ebp)\n" /* line 195 */
        "movl %eax, %edi\n"
        "jmp .Lfee594_000ee5fa\n"
        /* } scope */
        /* } scope */
        ".Lfee594_000ee81b:\n"
        "movl -0xe0(%ebp), %ebx\n" /* line 228 | visibleCount, light1 */
        "movl %ebx, -0xa4(%ebp)\n" /* light1 */
        "movl -0xdc(%ebp), %edi\n" /* lights */
        "jmp .Lfee594_000ee5fa\n"
        /* { scope 2: cutoffDistSq, distSq */
        /* { scope 3: light0 */
        ".Lfee594_000ee832:\n"
        "movl -0xdc(%ebp), %edx\n" /* line 180 | lights */
        "movl (%edx), %ecx\n"
        "movl %edx, %ebx\n" /* line 181 | light1 */
        "leal (%edx, %edi, 4), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%ebx)\n" /* light1 */
        "movl %ecx, (%edx)\n" /* line 182 */
        "subl $1, -0xe0(%ebp)\n" /* line 183 | visibleCount */
        "movl -0xe0(%ebp), %edi\n" /* visibleCount */
        "cmpl %edi, -0xa0(%ebp)\n" /* line 188 */
        "jne .Lfee594_000ee7f7\n"
        ".Lfee594_000ee85a:\n"
        "movl -0xe4(%ebp), %edx\n" /* line 195 | visibleLimit */
        "movl %edx, -0xa4(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lfee594_000ee866:\n"
        "movl -0xa4(%ebp), %edx\n" /* line 235 */
        "testl %edx, %edx\n"
        "jle .Lfee594_000ee9f7\n"
        "movl 0xc(%ebp), %ecx\n" /* drawSurfCount */
        "subl $1, %ecx\n"
        "movl %ecx, -0xa8(%ebp)\n"
        "movl $0, -0x9c(%ebp)\n"
        "movl $0, -0xe8(%ebp)\n" /* partitionCount */
        "movl 0x195f0f4, %ebx\n" /* light1 */
        "movl %ebx, -0xf4(%ebp)\n" /* light1 */
        "movl 0xc(%ebp), %edi\n" /* drawSurfCount */
        "movl %edi, -0xf8(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* partitions */
        "movl %eax, -0xfc(%ebp)\n"
        "movl %ebx, -0x100(%ebp)\n" /* light1 */
        "movl %eax, %ebx\n" /* light1 */
        ".Lfee594_000ee8ba:\n"
        "movl -0x9c(%ebp), %ecx\n" /* line 237 */
        "movl -0x98(%ebp, %ecx, 4), %edx\n"
        "movl %edx, (%ebx)\n" /* line 238 | light1 */
        "movl -0xf4(%ebp), %edi\n" /* line 239 */
        "movl 0x5b8(%edi), %eax\n"
        "movl %eax, 4(%ebx)\n" /* light1 */
        "movss 0x10(%edx), %xmm0\n" /* line 240 */
        "addl $4, %edx\n"
        "movl %edx, -0xc4(%ebp)\n" /* origin */
        /* { scope 2: cutoffDistSq, distSq */
        /* { scope 3: light0 */
        "mulss %xmm0, %xmm0\n" /* line 97 */
        "movss %xmm0, -0xc0(%ebp)\n" /* cutoffDistSq */
        "movl -0xa8(%ebp), %eax\n" /* line 100 */
        "testl %eax, %eax\n"
        "js .Lfee594_000ee9ef\n"
        "movl -0xa8(%ebp), %eax\n" /* line 205 */
        "movl 8(%ebp), %edx\n" /* drawSurfs */
        "leal (%edx, %eax, 8), %esi\n" /* partitionLimit */
        "xorl %edi, %edi\n"
        ".Lfee594_000ee90e:\n"
        "movl %esi, (%esp)\n" /* line 103 */
        "calll R_BoundsForDrawSurf\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 104 */
        "je .Lfee594_000ee989\n"
        "leal 0xc(%eax), %eax\n" /* line 106 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0xc4(%ebp), %ecx\n" /* origin */
        "movl %ecx, (%esp)\n"
        "calll PointToBoxDistSq\n"
        "fstps -0xbc(%ebp)\n" /* distSq */
        "movss -0xbc(%ebp), %xmm0\n" /* line 107 | distSq */
        "ucomiss -0xc0(%ebp), %xmm0\n" /* cutoffDistSq */
        "ja .Lfee594_000ee989\n"
        "movl -0x100(%ebp), %eax\n" /* line 110 */
        "movl %eax, -0xf4(%ebp)\n"
        "movl 0x5b8(%eax), %ebx\n"
        "movl 0x5bc(%eax), %ecx\n"
        "movl (%esi), %eax\n"
        "movl 4(%esi), %edx\n"
        "movl %eax, (%ecx, %ebx, 8)\n"
        "movl %edx, 4(%ecx, %ebx, 8)\n"
        "movl -0xf4(%ebp), %edx\n" /* line 115 */
        "addl $1, 0x5b8(%edx)\n"
        "movl 0x195eef4, %ecx\n" /* line 116 */
        "movl (%ecx), %eax\n"
        "addl $1, 4(%eax)\n"
        ".Lfee594_000ee989:\n"
        "addl $1, %edi\n"
        "subl $8, %esi\n"
        "cmpl %edi, -0xf8(%ebp)\n" /* line 100 */
        "jne .Lfee594_000ee90e\n"
        "movl 0x195f0f4, %ebx\n"
        "movl %ebx, -0xf4(%ebp)\n"
        "movl %ebx, %edi\n"
        /* } scope */
        /* } scope */
        ".Lfee594_000ee9a9:\n"
        "movl 0x5b8(%edi), %eax\n" /* line 241 */
        "movl -0xfc(%ebp), %edx\n"
        "subl 4(%edx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "testl %eax, %eax\n" /* line 242 */
        "je .Lfee594_000ee9cf\n"
        "addl $1, -0xe8(%ebp)\n" /* line 243 | partitionCount */
        "addl $0xc, %edx\n"
        "movl %edx, -0xfc(%ebp)\n"
        ".Lfee594_000ee9cf:\n"
        "addl $1, -0x9c(%ebp)\n" /* line 235 */
        "movl -0x9c(%ebp), %ecx\n"
        "cmpl %ecx, -0xa4(%ebp)\n"
        "je .Lfee594_000eea01\n"
        "movl -0xfc(%ebp), %ebx\n" /* light1 */
        "jmp .Lfee594_000ee8ba\n"
        ".Lfee594_000ee9ef:\n"
        "movl -0xf4(%ebp), %edi\n"
        "jmp .Lfee594_000ee9a9\n"
        ".Lfee594_000ee9f7:\n"
        "movl $0, -0xe8(%ebp)\n" /* partitionCount */
        /* } scope */
        ".Lfee594_000eea01:\n"
        "movl -0xe8(%ebp), %eax\n" /* line 247 | partitionCount */
        "addl $0x10c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lights, origin */
        ".Lfee594_000eea12:\n"
        "xorl %ecx, %ecx\n" /* line 217 */
        "movl $0, -0xa4(%ebp)\n"
        "leal 0x18(%eax), %edx\n"
        ".Lfee594_000eea21:\n"
        "cmpb $0, 0x598(%eax)\n" /* line 219 */
        "jne .Lfee594_000eea40\n"
        "movl -0xa4(%ebp), %edi\n" /* line 222 */
        "movl %edx, -0x98(%ebp, %edi, 4)\n"
        "addl $1, %edi\n" /* line 223 */
        "movl %edi, -0xa4(%ebp)\n"
        ".Lfee594_000eea40:\n"
        "addl $1, %ecx\n" /* line 217 */
        "addl $0x2c, %edx\n"
        "addl $1, %eax\n"
        "cmpl %ebx, %ecx\n" /* light1 */
        "jne .Lfee594_000eea21\n"
        "jmp .Lfee594_000ee5c3\n"
    );
}

