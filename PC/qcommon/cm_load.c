/* ASM dump from: cm_load.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_load.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern struct clipMap_t cm; /* 0x0 */

void CM_LoadMap(const char *name, int *checksum);
void CM_Shutdown(void);
int CM_NumInlineModels(void);
const char * CM_EntityString(void);
int CM_LeafCluster(int leafnum);
void * CM_Hunk_Alloc(int size, const char *name, int type);
void CM_Hunk_CheckTempMemoryClear(void);
void CM_Hunk_CheckTempMemoryHighClear(void);
void * CM_Hunk_AllocateTempMemoryHigh(int size, const char *name);
void CM_Hunk_ClearTempMemory(void);
void CM_Hunk_ClearTempMemoryHigh(void);
void CM_ModelBounds(clipHandle_t model, vec_t *mins, vec_t *maxs);
void CM_SaveLump(int lumpnum, byte *newLump, int size, int *checksum);

/* line 144 */
__attribute__((naked))
void CM_LoadMap(const char *name, int *checksum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 144 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        "testl %ebx, %ebx\n" /* line 146 | name */
        "je .Lf74080_000741a4\n"
        "cmpb $0, (%ebx)\n" /* name */
        "je .Lf74080_000741a4\n"
        ".Lf74080_0007409b:\n"
        "movl cm, %eax\n" /* line 149 */
        "testl %eax, %eax\n"
        "je .Lf74080_000740b8\n"
        "movl %ebx, 4(%esp)\n" /* name */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf74080_00074193\n"
        ".Lf74080_000740b8:\n"
        "movl $1, 4(%esp)\n" /* line 102 */
        "movl %ebx, (%esp)\n"
        "calll CM_LoadMapFromBsp\n"
        "calll CM_LoadStaticModels\n" /* line 107 */
        "movl 0x195ee1c, %ebx\n" /* line 54 */
        "movl $0, (%ebx)\n" /* line 55 */
        "movl 0x1007e84, %eax\n" /* line 56 */
        "addl %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl 0x1007e6c, %eax\n" /* line 57 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, 4(%ebx)\n"
        "movl 0x1007e64, %eax\n" /* line 58 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, 8(%ebx)\n"
        "movl $0x30, (%esp)\n" /* line 60 */
        "calll Hunk_AllocInternal\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl 0x1007ebc, %ecx\n" /* line 61 */
        "movl (%ecx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, 4(%eax)\n"
        "movl 8(%ecx), %edx\n"
        "movl %edx, 8(%eax)\n"
        "movl 0xc(%ecx), %edx\n"
        "movl %edx, 0xc(%eax)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, 0x10(%eax)\n"
        "movl 0x14(%ecx), %edx\n"
        "movl %edx, 0x14(%eax)\n"
        "movl 0x18(%ecx), %edx\n"
        "movl %edx, 0x18(%eax)\n"
        "movl 0x1c(%ecx), %edx\n"
        "movl %edx, 0x1c(%eax)\n"
        "movl 0x20(%ecx), %edx\n"
        "movl %edx, 0x20(%eax)\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %edx, 0x24(%eax)\n"
        "movl 0x28(%ecx), %edx\n"
        "movl %edx, 0x28(%eax)\n"
        "movl 0x2c(%ecx), %edx\n"
        "movl %edx, 0x2c(%eax)\n"
        "movl $0x48, (%esp)\n" /* line 63 */
        "calll Hunk_AllocInternal\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl $0x48, 8(%esp)\n" /* line 64 */
        "movl $0x1007ec0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        ".Lf74080_00074193:\n"
        "movl 0x1007f2c, %edx\n" /* line 155 */
        "movl 0xc(%ebp), %eax\n" /* checksum */
        "movl %edx, (%eax)\n"
        "addl $0x14, %esp\n" /* line 156 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf74080_000741a4:\n"
        "movl $0x21bf70, 4(%esp)\n" /* line 147 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf74080_0007409b\n"
    );
}

/* line 165 */
__attribute__((naked))
void CM_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 165 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x110, 8(%esp)\n" /* line 167 */
        "movl $0, 4(%esp)\n"
        "movl $cm, (%esp)\n"
        "calll Com_Memset\n"
        "leave\n" /* line 168 */
        "retl\n"
    );
}

/* line 303 */
__attribute__((naked))
int CM_NumInlineModels(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 303 */
        "movl %esp, %ebp\n"
        "movl 0x1007e94, %eax\n"
        "popl %ebp\n" /* line 306 */
        "retl\n"
    );
}

/* line 309 */
__attribute__((naked))
const char * CM_EntityString(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 309 */
        "movl %esp, %ebp\n"
        "movl 0x1007eb8, %eax\n"
        "popl %ebp\n" /* line 312 */
        "retl\n"
    );
}

/* line 316 */
__attribute__((naked))
int CM_LeafCluster(int leafnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 316 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* leafnum */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x1007e48, %eax\n" /* leafnum */
        "movswl 0x28(%eax, %edx, 4), %eax\n" /* leafnum */
        "popl %ebp\n" /* line 320 */
        "retl\n"
    );
}

/* line 349 */
__attribute__((naked))
void * CM_Hunk_Alloc(int size, const char *name, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 349 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 352 */
        "jmp Hunk_AllocInternal\n" /* line 351 */
    );
}

/* line 360 */
__attribute__((naked))
void CM_Hunk_CheckTempMemoryClear(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 360 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 363 */
        "retl\n"
    );
}

/* line 371 */
__attribute__((naked))
void CM_Hunk_CheckTempMemoryHighClear(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 371 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 374 */
        "retl\n"
    );
}

/* line 382 */
__attribute__((naked))
void * CM_Hunk_AllocateTempMemoryHigh(int size, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 382 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 385 */
        "jmp Hunk_AllocateTempMemoryHighInternal\n" /* line 384 */
    );
}

/* line 393 */
__attribute__((naked))
void CM_Hunk_ClearTempMemory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 393 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 396 */
        "jmp Hunk_ClearTempMemory\n" /* line 395 */
    );
}

/* line 404 */
__attribute__((naked))
void CM_Hunk_ClearTempMemoryHigh(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 404 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 407 */
        "jmp Hunk_ClearTempMemoryHigh\n" /* line 406 */
    );
}

/* line 332 */
__attribute__((naked))
void CM_ModelBounds(clipHandle_t model, vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 332 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* mins */
        "movl 0x10(%ebp), %esi\n" /* maxs */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 336 | model */
        "movl %eax, (%esp)\n"
        "calll CM_ClipHandleToModel\n"
        "movl (%eax), %edx\n" /* line 199 */
        "movl %edx, (%ebx)\n"
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, 4(%ebx)\n"
        "movl 8(%eax), %edx\n" /* line 201 */
        "movl %edx, 8(%ebx)\n"
        "leal 0xc(%eax), %edx\n"
        /* { scope 2 */
        "movl 0xc(%eax), %eax\n" /* line 199 */
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        /* } scope */
        /* } scope */
        "addl $0x10, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 206 */
__attribute__((naked))
void CM_SaveLump(int lumpnum, byte *newLump, int size, int *checksum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 206 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2ac, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* size */
        /* { scope 1 */
        "movl $0, 8(%esp)\n" /* line 224 */
        "leal -0x24(%ebp), %eax\n" /* h */
        "movl %eax, 4(%esp)\n"
        "movl cm, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileRead\n"
        "movl %eax, %ebx\n" /* length */
        "movl -0x24(%ebp), %edx\n" /* line 225 | h */
        "testl %edx, %edx\n"
        "je .Lf74286_000744e5\n"
        ".Lf74286_000742be:\n"
        "leal 1(%ebx), %eax\n" /* line 228 | length */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, -0x1c(%ebp)\n" /* buf */
        "movl -0x24(%ebp), %edx\n" /* line 230 | h */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* length */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "movl -0x1c(%ebp), %eax\n" /* line 232 | buf */
        "movb $0, (%eax, %ebx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 233 | h */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0x164(%ebp), %edi\n" /* line 235 | header */
        "movl $0x140, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* buf */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memcpy\n"
        "movl -0x160(%ebp), %eax\n" /* line 236 */
        "cmpl $4, %eax\n"
        "je .Lf74286_00074341\n"
        "cmpl $0x3d, %eax\n"
        "je .Lf74286_00074341\n"
        "movl %eax, 8(%esp)\n" /* line 244 */
        "movl $0x21bfa0, 4(%esp)\n" /* "bad bsp version %d" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf74286_00074336:\n"
        "addl $0x2ac, %esp\n" /* line 298 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf74286_00074341:\n"
        "movl $1, %eax\n" /* line 200 */
        ".Lf74286_00074346:\n"
        "addl $1, %eax\n" /* line 202 */
        "cmpl $0x28, %eax\n" /* line 201 */
        "jne .Lf74286_00074346\n"
        "movl $0x140, 8(%esp)\n" /* line 248 */
        "movl %edi, 4(%esp)\n"
        "leal -0x2a4(%ebp), %eax\n" /* oldHeader */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl cm, %eax\n" /* line 250 */
        "movl %eax, (%esp)\n"
        "calll FS_OpenFileOverwrite\n"
        "movl %eax, -0x24(%ebp)\n" /* h */
        "testl %eax, %eax\n" /* line 251 */
        "je .Lf74286_00074507\n"
        "movl $0x140, %ecx\n" /* line 254 */
        "xorl %edx, %edx\n"
        "jmp .Lf74286_000743a8\n"
        ".Lf74286_00074389:\n"
        "leal (, %edx, 8), %eax\n" /* line 267 */
        "movl %ecx, 0xc(%edi, %eax)\n"
        "movl 8(%edi, %eax), %eax\n" /* line 268 */
        "addl $3, %eax\n"
        "andl $0xfffffffc, %eax\n"
        "addl %eax, %ecx\n"
        "addl $1, %edx\n" /* line 263 */
        "cmpl $0x27, %edx\n"
        "je .Lf74286_000743d6\n"
        ".Lf74286_000743a8:\n"
        "cmpl %edx, 8(%ebp)\n" /* line 265 | lumpnum */
        "jne .Lf74286_00074389\n"
        "movl 8(%ebp), %eax\n" /* line 266 | lumpnum */
        "movl %esi, -0x15c(%ebp, %eax, 8)\n" /* i */
        "leal (, %edx, 8), %eax\n" /* line 267 */
        "movl %ecx, 0xc(%edi, %eax)\n"
        "movl 8(%edi, %eax), %eax\n" /* line 268 */
        "addl $3, %eax\n"
        "andl $0xfffffffc, %eax\n"
        "addl %eax, %ecx\n"
        "addl $1, %edx\n" /* line 263 */
        "cmpl $0x27, %edx\n"
        "jne .Lf74286_000743a8\n"
        ".Lf74286_000743d6:\n"
        "movl $1, %eax\n"
        ".Lf74286_000743db:\n"
        "addl $1, %eax\n" /* line 202 */
        "cmpl $0x28, %eax\n" /* line 201 */
        "jne .Lf74286_000743db\n"
        "movl -0x24(%ebp), %eax\n" /* line 272 | h */
        "movl %eax, 8(%esp)\n"
        "movl $0x140, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FS_Write\n"
        "movl $1, %eax\n"
        ".Lf74286_000743ff:\n"
        "addl $1, %eax\n" /* line 202 */
        "cmpl $0x28, %eax\n" /* line 201 */
        "jne .Lf74286_000743ff\n"
        "movl $0, -0x20(%ebp)\n" /* line 275 | zero */
        "xorl %esi, %esi\n" /* i */
        "xorl %ebx, %ebx\n" /* length */
        "jmp .Lf74286_0007441f\n"
        ".Lf74286_00074414:\n"
        "addl $1, %esi\n" /* line 276 | i */
        "addl $8, %ebx\n" /* length */
        "cmpl $0x27, %esi\n" /* i */
        "je .Lf74286_0007447e\n"
        ".Lf74286_0007441f:\n"
        "movl 8(%ebx, %edi), %ecx\n" /* line 278 | length */
        "testl %ecx, %ecx\n"
        "je .Lf74286_00074414\n"
        "cmpl %esi, 8(%ebp)\n" /* line 280 | i, lumpnum */
        "je .Lf74286_000744dd\n"
        "movl -0x298(%ebx, %ebp), %edx\n" /* line 283 | length */
        "addl -0x1c(%ebp), %edx\n" /* buf */
        ".Lf74286_0007443a:\n"
        "movl -0x24(%ebp), %eax\n" /* line 284 | h */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FS_Write\n"
        "movl 8(%ebx, %edi), %edx\n" /* line 285 | length */
        "leal 3(%edx), %eax\n"
        "andl $0xfffffffc, %eax\n"
        "subl %edx, %eax\n" /* line 286 */
        "movl %eax, %edx\n"
        "je .Lf74286_00074414\n"
        "movl -0x24(%ebp), %eax\n" /* line 287 | h */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x20(%ebp), %edx\n" /* zero */
        "movl %edx, (%esp)\n"
        "calll FS_Write\n"
        "addl $1, %esi\n" /* line 276 | i */
        "addl $8, %ebx\n" /* length */
        "cmpl $0x27, %esi\n" /* i */
        "jne .Lf74286_0007441f\n"
        ".Lf74286_0007447e:\n"
        "movl -0x24(%ebp), %eax\n" /* line 289 | h */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl -0x1c(%ebp), %eax\n" /* line 290 | buf */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl 0x14(%ebp), %eax\n" /* line 292 | checksum */
        "testl %eax, %eax\n"
        "je .Lf74286_00074336\n"
        "leal -0x1c(%ebp), %eax\n" /* line 294 | buf */
        "movl %eax, 4(%esp)\n"
        "movl cm, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_ReadFile\n"
        "movl %eax, 4(%esp)\n" /* line 295 */
        "movl -0x1c(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll Com_BlockChecksum\n"
        "movl 0x14(%ebp), %edx\n" /* checksum */
        "movl %eax, (%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 296 | buf */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "addl $0x2ac, %esp\n" /* line 298 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf74286_000744dd:\n"
        "movl 0xc(%ebp), %edx\n" /* line 281 | newLump */
        "jmp .Lf74286_0007443a\n"
        ".Lf74286_000744e5:\n"
        "movl cm, %eax\n" /* line 226 */
        "movl %eax, 8(%esp)\n"
        "movl $0x21bf88, 4(%esp)\n" /* "EXE_ERR_COULDNT_LOAD%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf74286_000742be\n"
        ".Lf74286_00074507:\n"
        "movl cm, %eax\n" /* line 253 */
        "movl %eax, 8(%esp)\n"
        "movl $0x21bfb4, 4(%esp)\n" /* "Failed to open file %s for writing" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x2ac, %esp\n" /* line 298 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

