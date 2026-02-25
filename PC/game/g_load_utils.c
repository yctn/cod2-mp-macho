/* ASM dump from: g_load_utils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game/g_load_utils.cpp */

#include "common_types.h"
#include "imports.h"

static int index_00fea280; /* 0xfea280 */
static char str[8][32]; /* 0xfea180 */

qboolean G_SpawnStringInternal(SpawnVar *spawnVar, const char *key, const char *defaultString, const char * *out);
unsigned int G_NewString(const char *string);
char * vtos(const vec_t *v);
qboolean G_ParseSpawnVars(SpawnVar *spawnVar);

/* line 92 */
__attribute__((naked))
qboolean G_SpawnStringInternal(SpawnVar *spawnVar, const char *key, const char *defaultString, const char * *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 92 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 98 | spawnVar */
        "movl 4(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jg .Lf1c9c44_001c9c69\n"
        ".Lf1c9c44_001c9c57:\n"
        "movl 0x10(%ebp), %edx\n" /* line 107 | defaultString */
        "movl 0x14(%ebp), %eax\n" /* out */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1c9c44_001c9c61:\n"
        "addl $0x1c, %esp\n" /* line 109 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c9c44_001c9c69:\n"
        "movl %eax, %ebx\n" /* line 98 */
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf1c9c44_001c9c79\n"
        ".Lf1c9c44_001c9c6f:\n"
        "addl $1, %esi\n" /* i */
        "addl $8, %ebx\n"
        "cmpl %esi, %edi\n" /* i */
        "je .Lf1c9c44_001c9c57\n"
        ".Lf1c9c44_001c9c79:\n"
        "movl 8(%ebx), %eax\n" /* line 100 */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* key */
        "movl %edx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1c9c44_001c9c6f\n"
        "movl 8(%ebp), %edx\n" /* line 102 | spawnVar */
        "movl 0xc(%edx, %esi, 8), %eax\n"
        "movl 0x14(%ebp), %edx\n" /* out */
        "movl %eax, (%edx)\n"
        "movl $1, %eax\n"
        "jmp .Lf1c9c44_001c9c61\n"
    );
}

/* line 120 */
__attribute__((naked))
unsigned int G_NewString(const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 120 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x401c, %esp\n"
        "movl 8(%ebp), %esi\n" /* string */
        /* { scope 1 */
        "cld\n" /* line 126 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* string */
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "cmpl $0x4000, %ebx\n" /* line 127 */
        "ja .Lf1c9ca2_001c9d22\n"
        ".Lf1c9ca2_001c9cc9:\n"
        "testl %ebx, %ebx\n" /* line 133 */
        "jle .Lf1c9ca2_001c9cec\n"
        "leal -0x4018(%ebp), %ecx\n" /* strbuf */
        "xorl %edx, %edx\n"
        "leal -1(%ebx), %edi\n"
        ".Lf1c9ca2_001c9cd8:\n"
        "movzbl (%esi, %edx), %eax\n" /* line 135 | string */
        "cmpb $0x5c, %al\n"
        "je .Lf1c9ca2_001c9d0d\n"
        ".Lf1c9ca2_001c9ce0:\n"
        "movb %al, (%ecx)\n" /* line 149 */
        "addl $1, %ecx\n"
        ".Lf1c9ca2_001c9ce5:\n"
        "addl $1, %edx\n" /* line 133 */
        "cmpl %edx, %ebx\n"
        "jg .Lf1c9ca2_001c9cd8\n"
        ".Lf1c9ca2_001c9cec:\n"
        "movl $0, 4(%esp)\n" /* line 153 */
        "leal -0x4018(%ebp), %eax\n" /* strbuf */
        "movl %eax, (%esp)\n"
        "calll SL_GetString\n"
        /* } scope */
        "addl $0x401c, %esp\n" /* line 154 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c9ca2_001c9d0d:\n"
        "cmpl %edi, %edx\n" /* line 135 */
        "jge .Lf1c9ca2_001c9ce0\n"
        "addl $1, %edx\n" /* line 137 */
        "cmpb $0x6e, (%esi, %edx)\n" /* line 138 | string */
        "je .Lf1c9ca2_001c9d44\n"
        "movb $0x5c, (%ecx)\n" /* line 144 */
        "addl $1, %ecx\n"
        "jmp .Lf1c9ca2_001c9ce5\n"
        ".Lf1c9ca2_001c9d22:\n"
        "movl $0x4000, 0xc(%esp)\n" /* line 128 */
        "movl %ebx, 8(%esp)\n"
        "movl $0x2b6eb8, 4(%esp)\n" /* "G_NewString: len = %i > %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1c9ca2_001c9cc9\n"
        ".Lf1c9ca2_001c9d44:\n"
        "movb $0xa, (%ecx)\n" /* line 140 */
        "addl $1, %ecx\n"
        "jmp .Lf1c9ca2_001c9ce5\n"
    );
}

/* line 165 */
__attribute__((naked))
char * vtos(const vec_t *v)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 165 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %edx\n" /* v */
        /* { scope 1 */
        "movl index, %eax\n" /* line 172 */
        "movl %eax, %ecx\n"
        "shll $5, %ecx\n"
        "leal str(%ecx), %ebx\n" /* s */
        "addl $1, %eax\n" /* line 173 */
        "andl $7, %eax\n"
        "movl %eax, index\n"
        "cvttss2si 8(%edx), %eax\n" /* line 175 */
        "movl %eax, 0x14(%esp)\n"
        "cvttss2si 4(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "cvttss2si (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2b6ed8, 8(%esp)\n" /* "(%i %i %i)" */
        "movl $0x20, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* s */
        "calll Com_sprintf\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 178 | s */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 41 */
__attribute__((naked))
qboolean G_ParseSpawnVars(SpawnVar *spawnVar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 41 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x82c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 46 | spawnVar */
        "movb $0, (%eax)\n"
        "movl $0, 4(%eax)\n" /* line 47 */
        "movl $0, 0x208(%eax)\n" /* line 48 */
        "movl $0x400, 4(%esp)\n" /* line 51 */
        "leal -0x818(%ebp), %edx\n" /* com_token */
        "movl %edx, (%esp)\n"
        "calll SV_GetEntityToken\n"
        "testl %eax, %eax\n"
        "je .Lf1c9dac_001c9fb0\n"
        "cmpb $0x7b, -0x818(%ebp)\n" /* line 57 | com_token */
        "je .Lf1c9dac_001c9f66\n"
        "leal -0x818(%ebp), %ecx\n" /* line 58 | com_token */
        "movl %ecx, 8(%esp)\n"
        "movl $0x2b6ee4, 4(%esp)\n" /* "G_ParseSpawnVars: found %s when expecting {" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0x400, 4(%esp)\n" /* line 64 */
        "leal -0x418(%ebp), %eax\n" /* keyname */
        "movl %eax, (%esp)\n"
        "calll SV_GetEntityToken\n"
        "testl %eax, %eax\n"
        "je .Lf1c9dac_001c9f84\n"
        ".Lf1c9dac_001c9e36:\n"
        "cmpb $0x7d, -0x418(%ebp)\n" /* line 67 | keyname */
        "je .Lf1c9dac_001c9fa5\n"
        ".Lf1c9dac_001c9e43:\n"
        "movl $0x400, 4(%esp)\n" /* line 71 */
        "leal -0x818(%ebp), %edx\n" /* com_token */
        "movl %edx, (%esp)\n"
        "calll SV_GetEntityToken\n"
        "testl %eax, %eax\n"
        "je .Lf1c9dac_001ca001\n"
        "cmpb $0x7d, -0x818(%ebp)\n" /* line 76 | com_token */
        "je .Lf1c9dac_001ca022\n"
        ".Lf1c9dac_001c9e6e:\n"
        "movl 8(%ebp), %ecx\n" /* line 79 | spawnVar */
        "cmpl $0x40, 4(%ecx)\n"
        "je .Lf1c9dac_001ca043\n"
        ".Lf1c9dac_001c9e7b:\n"
        "movl %ecx, %eax\n"
        ".Lf1c9dac_001c9e7d:\n"
        "movl 4(%eax), %eax\n" /* line 82 */
        "movl %eax, -0x820(%ebp)\n"
        /* { scope 2 */
        "cld\n" /* line 18 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x418(%ebp), %edi\n" /* keyname, l */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* l */
        "movl %ecx, %esi\n"
        "notl %esi\n"
        "leal -1(%esi), %edi\n" /* l */
        "movl 8(%ebp), %eax\n" /* line 19 | spawnVar */
        "movl 0x208(%eax), %edx\n"
        "leal 1(%edi, %edx), %eax\n" /* l */
        "cmpl $0x800, %eax\n"
        "jg .Lf1c9dac_001c9fdd\n"
        "movl 8(%ebp), %eax\n" /* spawnVar */
        ".Lf1c9dac_001c9eb8:\n"
        "addl $0x20c, %eax\n" /* line 22 */
        "movl %eax, -0x824(%ebp)\n"
        "movl %eax, %ebx\n" /* dest */
        "addl %edx, %ebx\n" /* dest */
        "movl %esi, 8(%esp)\n" /* line 23 */
        "leal -0x418(%ebp), %edx\n" /* keyname */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* dest */
        "calll memcpy\n"
        "movl 8(%ebp), %ecx\n" /* line 25 | spawnVar */
        "addl 0x208(%ecx), %edi\n" /* l */
        "leal 1(%edi), %edx\n" /* l */
        "movl %edx, 0x208(%ecx)\n"
        /* } scope */
        "movl -0x820(%ebp), %eax\n" /* line 82 */
        "movl %ebx, 8(%ecx, %eax, 8)\n" /* dest */
        "movl 4(%ecx), %ecx\n" /* line 83 */
        "movl %ecx, -0x81c(%ebp)\n"
        /* { scope 2 */
        "cld\n" /* line 18 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x818(%ebp), %edi\n" /* com_token, l */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* l */
        "movl %ecx, %esi\n"
        "notl %esi\n"
        "leal -1(%esi), %edi\n" /* l */
        "leal 1(%edi, %edx), %eax\n" /* line 19 | l */
        "cmpl $0x800, %eax\n"
        "jg .Lf1c9dac_001c9fbb\n"
        ".Lf1c9dac_001c9f28:\n"
        "movl -0x824(%ebp), %ebx\n" /* line 22 | dest */
        "addl %edx, %ebx\n" /* dest */
        "movl %esi, 8(%esp)\n" /* line 23 */
        "leal -0x818(%ebp), %edx\n" /* com_token */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* dest */
        "calll memcpy\n"
        "movl 8(%ebp), %ecx\n" /* line 25 | spawnVar */
        "addl 0x208(%ecx), %edi\n" /* l */
        "leal 1(%edi), %eax\n" /* l */
        "movl %eax, 0x208(%ecx)\n"
        /* } scope */
        "movl -0x81c(%ebp), %eax\n" /* line 83 */
        "movl %ebx, 0xc(%ecx, %eax, 8)\n" /* dest */
        "addl $1, 4(%ecx)\n" /* line 84 */
        ".Lf1c9dac_001c9f66:\n"
        "movl $0x400, 4(%esp)\n" /* line 64 */
        "leal -0x418(%ebp), %eax\n" /* keyname */
        "movl %eax, (%esp)\n"
        "calll SV_GetEntityToken\n"
        "testl %eax, %eax\n"
        "jne .Lf1c9dac_001c9e36\n"
        ".Lf1c9dac_001c9f84:\n"
        "movl $0x2b6f14, 4(%esp)\n" /* line 65 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "cmpb $0x7d, -0x418(%ebp)\n" /* line 67 | keyname */
        "jne .Lf1c9dac_001c9e43\n"
        ".Lf1c9dac_001c9fa5:\n"
        "movl 8(%ebp), %edx\n" /* line 87 | spawnVar */
        "movb $1, (%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1c9dac_001c9fb0:\n"
        "addl $0x82c, %esp\n" /* line 89 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1c9dac_001c9fbb:\n"
        "movl $0x2b6f98, 4(%esp)\n" /* line 20 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 8(%ebp), %eax\n" /* spawnVar */
        "movl 0x208(%eax), %edx\n"
        "jmp .Lf1c9dac_001c9f28\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1c9dac_001c9fdd:\n"
        "movl $0x2b6f98, 4(%esp)\n" /* "G_AddSpawnVarToken: MAX_SPAWN_VARS" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 8(%ebp), %ecx\n" /* spawnVar */
        "movl 0x208(%ecx), %edx\n"
        "movl %ecx, %eax\n"
        "jmp .Lf1c9dac_001c9eb8\n"
        /* } scope */
        ".Lf1c9dac_001ca001:\n"
        "movl $0x2b6f14, 4(%esp)\n" /* line 73 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "cmpb $0x7d, -0x818(%ebp)\n" /* line 76 | com_token */
        "jne .Lf1c9dac_001c9e6e\n"
        ".Lf1c9dac_001ca022:\n"
        "movl $0x2b6f44, 4(%esp)\n" /* line 77 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 8(%ebp), %ecx\n" /* line 79 | spawnVar */
        "cmpl $0x40, 4(%ecx)\n"
        "jne .Lf1c9dac_001c9e7b\n"
        ".Lf1c9dac_001ca043:\n"
        "movl $0x2b6f74, 4(%esp)\n" /* line 80 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 8(%ebp), %eax\n" /* spawnVar */
        "jmp .Lf1c9dac_001c9e7d\n"
    );
}

