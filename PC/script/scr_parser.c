/* ASM dump from: scr_parser.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_parser.cpp */

#include "common_types.h"
#include "imports.h"

extern struct scrParserPub_t scrParserPub; /* 0x0 */
extern struct scrParserGlob_t scrParserGlob; /* 0x0 */

void Scr_InitOpcodeLookup(void);
void Scr_ShutdownOpcodeLookup(void);
void AddOpcodePos(unsigned int sourcePos, int type);
void RemoveOpcodePos(void);
void AddThreadStartOpcodePos(unsigned int sourcePos);
int Scr_GetSourceBuffer(const char *codePos);
static void Scr_AddSourceBufferInternal(const char *codePos, char *sourceBuf, int len, int doEolFixup, int archive);
char * Scr_AddSourceBuffer(const char *filename, const char *extFilename, const char *codePos, int archive);
static void Scr_PrintSourcePos(const char *filename, unsigned int sourcePos);
void CompileError(unsigned int sourcePos, const char *msg);
void Scr_PrintPrevCodePos(print_msg_type_t type, const char *codePos, unsigned int index);
void RuntimeError(const char *codePos, unsigned int index, const char *msg, const char *dialogMessage);
void CompileError2(const char *codePos, const char *msg);

/* line 63 */
__attribute__((naked))
void Scr_InitOpcodeLookup(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 63 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl imp_scrVarPub, %eax\n" /* line 69 */
        "cmpb $0, 0xa(%eax)\n"
        "jne .Lf9b454_0009b467\n"
        "leave\n" /* line 89 */
        "retl\n"
        ".Lf9b454_0009b467:\n"
        "movl $0xffffffff, scrParserGlob+44\n" /* line 72 */
        "movl $0x10000, scrParserGlob+4\n" /* line 74 */
        "movl $0, scrParserGlob+8\n" /* line 75 */
        "movl $0x140000, (%esp)\n" /* line 76 */
        "calll Z_MallocInternal\n"
        "movl %eax, scrParserGlob\n"
        "movl scrParserGlob+4, %edx\n" /* line 77 */
        "leal (%edx, %edx, 4), %edx\n"
        "shll $2, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0x10000, scrParserGlob+16\n" /* line 79 */
        "movl $0, scrParserGlob+20\n" /* line 80 */
        "movl $0x80000, (%esp)\n" /* line 81 */
        "calll Z_MallocInternal\n"
        "movl %eax, scrParserGlob+12\n"
        "movl $0, scrParserGlob+28\n" /* line 83 */
        "movl $0, scrParserGlob+32\n" /* line 84 */
        "movl $0x10, scrParserGlob+24\n" /* line 86 */
        "movl $0, scrParserPub+4\n" /* line 87 */
        "movl $0x180, (%esp)\n" /* line 88 */
        "calll Z_MallocInternal\n"
        "movl %eax, scrParserPub\n"
        "leave\n" /* line 89 */
        "retl\n"
    );
}

/* line 92 */
__attribute__((naked))
void Scr_ShutdownOpcodeLookup(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 92 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl scrParserGlob, %eax\n" /* line 96 */
        "testl %eax, %eax\n"
        "je .Lf9b516_0009b538\n"
        "movl %eax, (%esp)\n" /* line 98 */
        "calll Z_FreeInternal\n"
        "movl $0, scrParserGlob\n" /* line 99 */
        ".Lf9b516_0009b538:\n"
        "movl scrParserGlob+12, %eax\n" /* line 102 */
        "testl %eax, %eax\n"
        "je .Lf9b516_0009b553\n"
        "movl %eax, (%esp)\n" /* line 104 */
        "calll Z_FreeInternal\n"
        "movl $0, scrParserGlob+12\n" /* line 105 */
        ".Lf9b516_0009b553:\n"
        "movl scrParserPub, %ebx\n" /* line 108 | i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf9b516_0009b582\n"
        "movl scrParserPub+4, %edx\n" /* line 110 */
        "testl %edx, %edx\n"
        "jne .Lf9b516_0009b5ef\n"
        ".Lf9b516_0009b56b:\n"
        "movl scrParserPub, %eax\n" /* line 112 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $0, scrParserPub\n" /* line 113 */
        ".Lf9b516_0009b582:\n"
        "movl scrParserGlob+36, %ecx\n" /* line 116 */
        "testl %ecx, %ecx\n"
        "je .Lf9b516_0009b5cf\n"
        "movl scrParserGlob+40, %eax\n" /* line 118 */
        "testl %eax, %eax\n"
        "jle .Lf9b516_0009b5d5\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl scrParserGlob+36, %edx\n"
        ".Lf9b516_0009b59d:\n"
        "movl (%edx, %ebx, 8), %eax\n" /* line 120 */
        "testl %eax, %eax\n"
        "je .Lf9b516_0009b5b2\n"
        "movl %eax, (%esp)\n" /* line 121 */
        "calll Z_FreeInternal\n"
        "movl scrParserGlob+36, %edx\n"
        ".Lf9b516_0009b5b2:\n"
        "addl $1, %ebx\n" /* line 118 | i */
        "cmpl scrParserGlob+40, %ebx\n" /* i */
        "jl .Lf9b516_0009b59d\n"
        "movl %edx, (%esp)\n" /* line 123 */
        "calll Z_FreeInternal\n"
        "movl $0, scrParserGlob+36\n" /* line 124 */
        /* } scope */
        ".Lf9b516_0009b5cf:\n"
        "addl $0x14, %esp\n" /* line 126 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9b516_0009b5d5:\n"
        "movl scrParserGlob+36, %edx\n"
        /* { scope 1 */
        "movl %edx, (%esp)\n" /* line 123 */
        "calll Z_FreeInternal\n"
        "movl $0, scrParserGlob+36\n" /* line 124 */
        "jmp .Lf9b516_0009b5cf\n"
        ".Lf9b516_0009b5ef:\n"
        "xorl %ebx, %ebx\n" /* line 110 | i */
        "xorl %eax, %eax\n"
        ".Lf9b516_0009b5f3:\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 111 */
        "movl scrParserPub, %edx\n"
        "movl 4(%edx, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "addl $1, %ebx\n" /* line 110 | i */
        "movl %ebx, %eax\n" /* i */
        "cmpl scrParserPub+4, %ebx\n" /* i */
        "jb .Lf9b516_0009b5f3\n"
        "jmp .Lf9b516_0009b56b\n"
    );
}

/* line 129 */
__attribute__((naked))
void AddOpcodePos(unsigned int sourcePos, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 129 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* type */
        /* { scope 1 */
        "movl imp_scrVarPub, %eax\n" /* line 137 */
        "cmpb $0, 0xa(%eax)\n"
        "je .Lf9b61a_0009b713\n"
        "movl imp_scrCompilePub, %edi\n" /* line 140 */
        "cmpl $2, 0x28(%edi)\n"
        "je .Lf9b61a_0009b713\n"
        "movl %esi, %eax\n" /* line 152 | type */
        "andl $0xfffffffe, %eax\n"
        "cmpb $0, 0x25(%edi)\n"
        "cmovel %eax, %esi\n" /* type */
        "movl scrParserGlob+4, %edx\n" /* line 159 */
        "cmpl %edx, scrParserGlob+8\n"
        "jae .Lf9b61a_0009b774\n"
        "movl scrParserGlob+16, %edx\n" /* line 169 */
        "cmpl %edx, scrParserGlob+20\n"
        "jae .Lf9b61a_0009b71b\n"
        ".Lf9b61a_0009b675:\n"
        "movl 0x2c(%edi), %eax\n" /* line 179 */
        "cmpl %eax, scrParserGlob+28\n"
        "je .Lf9b61a_0009b811\n"
        ".Lf9b61a_0009b684:\n"
        "movl $0, scrParserGlob+32\n" /* line 192 */
        "movl %eax, scrParserGlob+28\n" /* line 193 */
        "movl scrParserGlob+8, %eax\n" /* line 195 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl scrParserGlob, %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* opcodeLookup */
        "movl scrParserGlob+20, %eax\n" /* line 197 */
        "movl %eax, 4(%ebx)\n" /* opcodeLookup */
        "movl scrParserGlob+28, %eax\n" /* line 198 */
        "movl %eax, (%ebx)\n" /* opcodeLookup */
        "movl 4(%ebx), %edx\n" /* line 201 | opcodeLookup */
        "addl scrParserGlob+32, %edx\n"
        "movl scrParserGlob+12, %eax\n" /* line 202 */
        "leal (%eax, %edx, 8), %ecx\n"
        "movl 8(%ebp), %eax\n" /* line 203 | sourcePos */
        "movl %eax, (%ecx)\n"
        "addl $1, %eax\n" /* line 205 */
        "je .Lf9b61a_0009b849\n"
        ".Lf9b61a_0009b6d2:\n"
        "cmpl $-2, 8(%ebp)\n" /* line 211 | sourcePos */
        "je .Lf9b61a_0009b875\n"
        "movl scrParserGlob+44, %edx\n" /* line 215 */
        "testl %edx, %edx\n"
        "js .Lf9b61a_0009b6f2\n"
        "testl $1, %esi\n" /* type */
        "jne .Lf9b61a_0009b7d6\n"
        ".Lf9b61a_0009b6f2:\n"
        "orl %esi, 4(%ecx)\n" /* line 222 | type */
        "movl scrParserGlob+32, %eax\n" /* line 224 */
        "addl $1, %eax\n"
        "movl %eax, scrParserGlob+32\n"
        "movl %eax, 8(%ebx)\n" /* line 226 | opcodeLookup */
        "addl $1, scrParserGlob+8\n" /* line 228 */
        "addl $1, scrParserGlob+20\n" /* line 229 */
        /* } scope */
        ".Lf9b61a_0009b713:\n"
        "addl $0x1c, %esp\n" /* line 230 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9b61a_0009b71b:\n"
        "leal (%edx, %edx), %eax\n" /* line 171 */
        "movl %eax, scrParserGlob+16\n"
        "shll $4, %edx\n" /* line 173 */
        "movl %edx, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n" /* opcodeLookup */
        "movl scrParserGlob+20, %eax\n" /* line 174 */
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl scrParserGlob+12, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* opcodeLookup */
        "calll memcpy\n"
        "movl scrParserGlob+12, %eax\n" /* line 175 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl %ebx, scrParserGlob+12\n" /* line 176 | opcodeLookup */
        "movl 0x2c(%edi), %eax\n" /* line 179 */
        "cmpl %eax, scrParserGlob+28\n"
        "jne .Lf9b61a_0009b684\n"
        "jmp .Lf9b61a_0009b811\n"
        ".Lf9b61a_0009b774:\n"
        "leal (%edx, %edx), %eax\n" /* line 161 */
        "movl %eax, scrParserGlob+4\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 163 */
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n" /* opcodeLookup */
        "movl scrParserGlob+8, %eax\n" /* line 164 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl scrParserGlob, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* opcodeLookup */
        "calll memcpy\n"
        "movl scrParserGlob, %eax\n" /* line 165 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl %ebx, scrParserGlob\n" /* line 166 | opcodeLookup */
        "movl scrParserGlob+16, %edx\n" /* line 169 */
        "cmpl %edx, scrParserGlob+20\n"
        "jb .Lf9b61a_0009b675\n"
        "jmp .Lf9b61a_0009b71b\n"
        ".Lf9b61a_0009b7d6:\n"
        "movl scrParserGlob+12, %eax\n" /* line 218 */
        "movl 8(%ebp), %edi\n" /* sourcePos */
        "movl %edi, (%eax, %edx, 8)\n"
        "movl $0xffffffff, scrParserGlob+44\n" /* line 219 */
        "orl %esi, 4(%ecx)\n" /* line 222 | type */
        "movl scrParserGlob+32, %eax\n" /* line 224 */
        "addl $1, %eax\n"
        "movl %eax, scrParserGlob+32\n"
        "movl %eax, 8(%ebx)\n" /* line 226 | opcodeLookup */
        "addl $1, scrParserGlob+8\n" /* line 228 */
        "addl $1, scrParserGlob+20\n" /* line 229 */
        "jmp .Lf9b61a_0009b713\n"
        ".Lf9b61a_0009b811:\n"
        "movl scrParserGlob+8, %eax\n" /* line 183 */
        "subl $1, %eax\n"
        "movl %eax, scrParserGlob+8\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 185 */
        "movl scrParserGlob, %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* opcodeLookup */
        "movl 4(%ebx), %edx\n" /* line 201 | opcodeLookup */
        "addl scrParserGlob+32, %edx\n"
        "movl scrParserGlob+12, %eax\n" /* line 202 */
        "leal (%eax, %edx, 8), %ecx\n"
        "movl 8(%ebp), %eax\n" /* line 203 | sourcePos */
        "movl %eax, (%ecx)\n"
        "addl $1, %eax\n" /* line 205 */
        "jne .Lf9b61a_0009b6d2\n"
        ".Lf9b61a_0009b849:\n"
        "movl %edx, scrParserGlob+44\n" /* line 209 */
        "orl %esi, 4(%ecx)\n" /* line 222 | type */
        "movl scrParserGlob+32, %eax\n" /* line 224 */
        "addl $1, %eax\n"
        "movl %eax, scrParserGlob+32\n"
        "movl %eax, 8(%ebx)\n" /* line 226 | opcodeLookup */
        "addl $1, scrParserGlob+8\n" /* line 228 */
        "addl $1, scrParserGlob+20\n" /* line 229 */
        "jmp .Lf9b61a_0009b713\n"
        ".Lf9b61a_0009b875:\n"
        "movl %edx, scrParserGlob+48\n" /* line 213 */
        "orl %esi, 4(%ecx)\n" /* line 222 | type */
        "movl scrParserGlob+32, %eax\n" /* line 224 */
        "addl $1, %eax\n"
        "movl %eax, scrParserGlob+32\n"
        "movl %eax, 8(%ebx)\n" /* line 226 | opcodeLookup */
        "addl $1, scrParserGlob+8\n" /* line 228 */
        "addl $1, scrParserGlob+20\n" /* line 229 */
        "jmp .Lf9b61a_0009b713\n"
    );
}

/* line 233 */
__attribute__((naked))
void RemoveOpcodePos(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 233 */
        "movl %esp, %ebp\n"
        "movl imp_scrVarPub, %eax\n" /* line 237 */
        "cmpb $0, 0xa(%eax)\n"
        "je .Lf9b8a2_0009b8fc\n"
        "movl imp_scrCompilePub, %eax\n" /* line 240 */
        "cmpl $2, 0x28(%eax)\n"
        "je .Lf9b8a2_0009b8fc\n"
        "subl $1, scrParserGlob+20\n" /* line 252 */
        "movl scrParserGlob+8, %edx\n" /* line 255 */
        "subl $1, %edx\n"
        "movl %edx, scrParserGlob+8\n"
        "movl scrParserGlob+32, %ecx\n" /* line 258 */
        "subl $1, %ecx\n"
        "movl %ecx, scrParserGlob+32\n"
        "leal (%edx, %edx, 4), %edx\n" /* line 260 */
        "xorl %eax, %eax\n" /* line 267 */
        "testl %ecx, %ecx\n"
        "cmovnel scrParserGlob+28, %eax\n"
        "movl %eax, scrParserGlob+28\n"
        "movl scrParserGlob, %eax\n" /* line 269 */
        "movl %ecx, 8(%eax, %edx, 4)\n"
        ".Lf9b8a2_0009b8fc:\n"
        "popl %ebp\n" /* line 270 */
        "retl\n"
    );
}

/* line 273 */
__attribute__((naked))
void AddThreadStartOpcodePos(unsigned int sourcePos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl imp_scrVarPub, %eax\n" /* line 277 */
        "cmpb $0, 0xa(%eax)\n"
        "je .Lf9b8fe_0009b93b\n"
        "movl imp_scrCompilePub, %eax\n" /* line 280 */
        "cmpl $2, 0x28(%eax)\n"
        "je .Lf9b8fe_0009b93b\n"
        "movl scrParserGlob+48, %eax\n" /* line 287 */
        "movl scrParserGlob+12, %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 8(%ebp), %edx\n" /* line 288 | sourcePos */
        "movl %edx, (%eax)\n"
        "movl $4, 4(%eax)\n" /* line 290 */
        "movl $0xffffffff, scrParserGlob+48\n" /* line 291 */
        /* } scope */
        ".Lf9b8fe_0009b93b:\n"
        "popl %ebp\n" /* line 292 */
        "retl\n"
    );
}

/* line 862 */
__attribute__((naked))
int Scr_GetSourceBuffer(const char *codePos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 862 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edi\n" /* codePos */
        /* { scope 1 */
        "movl scrParserPub+4, %ecx\n" /* line 869 */
        "subl $1, %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf9b940_0009b97c\n"
        "movl %ecx, %esi\n" /* line 862 */
        "leal (%ecx, %ecx, 2), %edx\n"
        "movl scrParserPub, %eax\n"
        "leal (%eax, %edx, 8), %edx\n"
        "xorl %ebx, %ebx\n"
        ".Lf9b940_0009b965:\n"
        "movl (%edx), %eax\n" /* line 871 */
        "testl %eax, %eax\n"
        "je .Lf9b940_0009b96f\n"
        "cmpl %edi, %eax\n" /* line 873 | codePos */
        "jbe .Lf9b940_0009b97c\n"
        ".Lf9b940_0009b96f:\n"
        "subl $1, %ecx\n" /* line 869 */
        "addl $1, %ebx\n"
        "subl $0x18, %edx\n"
        "cmpl %esi, %ebx\n"
        "jne .Lf9b940_0009b965\n"
        /* } scope */
        ".Lf9b940_0009b97c:\n"
        "movl %ecx, %eax\n" /* line 878 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 571 */
static __attribute__((naked))
void Scr_AddSourceBufferInternal(const char *codePos, char *sourceBuf, int len, int doEolFixup, int archive)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 571 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %esi\n" /* extFilename */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n" /* doEolFixup */
        "movb %al, -0x21(%ebp)\n" /* doEolFixup */
        "movzbl 0x10(%ebp), %edx\n" /* archive */
        "movb %dl, -0x22(%ebp)\n" /* archive */
        /* { scope 1 */
        "movl scrParserPub, %eax\n" /* line 583 */
        "testl %eax, %eax\n"
        "je .Lf9b986_0009bad6\n"
        "cld\n" /* line 589 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* sourceBuf2, buf */
        "repne scasb %es:(%edi), %al\n" /* buf */
        "movl %ecx, %ebx\n" /* dest */
        "notl %ebx\n" /* dest */
        "movl 8(%ebp), %edx\n" /* line 591 | len */
        "leal 2(%ebx, %edx), %eax\n" /* dest */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %edi\n" /* buf */
        "movl %esi, 4(%esp)\n" /* line 592 | sourceBuf2 */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x20(%ebp), %eax\n" /* line 594 */
        "testl %eax, %eax\n"
        "je .Lf9b986_0009bb28\n"
        "leal (%edi, %ebx), %esi\n" /* buf, sourceBuf2 */
        ".Lf9b986_0009b9ed:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 595 */
        "cmpb $0, -0x21(%ebp)\n" /* line 598 | doEolFixup */
        "je .Lf9b986_0009ba59\n"
        "movl 8(%ebp), %eax\n" /* line 600 | len */
        "testl %eax, %eax\n"
        "jns .Lf9b986_0009bae8\n"
        ".Lf9b986_0009ba01:\n"
        "movl scrParserGlob+24, %edx\n" /* line 554 */
        "cmpl %edx, scrParserPub+4\n"
        "jae .Lf9b986_0009ba85\n"
        ".Lf9b986_0009ba0f:\n"
        "movl scrParserPub, %ecx\n"
        ".Lf9b986_0009ba15:\n"
        "movl scrParserPub+4, %eax\n" /* line 564 */
        "leal (%eax, %eax, 2), %edx\n"
        "leal (%ecx, %edx, 8), %edx\n"
        "addl $1, %eax\n" /* line 565 */
        "movl %eax, scrParserPub+4\n"
        "movl -0x1c(%ebp), %eax\n" /* line 624 */
        "movl %eax, (%edx)\n"
        "movl %edi, 4(%edx)\n" /* line 625 | buf */
        "movl %esi, 8(%edx)\n" /* line 626 | sourceBuf2 */
        "movl 8(%ebp), %eax\n" /* line 627 | len */
        "movl %eax, 0xc(%edx)\n"
        "movl $0xffffffff, 0x10(%edx)\n" /* line 628 */
        "movzbl -0x22(%ebp), %eax\n" /* line 629 | archive */
        "movb %al, 0x14(%edx)\n"
        "testl %esi, %esi\n" /* line 631 | sourceBuf2 */
        "je .Lf9b986_0009ba51\n"
        "movl %esi, scrParserPub+12\n" /* line 632 | sourceBuf2 */
        /* } scope */
        ".Lf9b986_0009ba51:\n"
        "addl $0x2c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9b986_0009ba59:\n"
        "movl 8(%ebp), %eax\n" /* line 613 | len */
        "testl %eax, %eax\n"
        "js .Lf9b986_0009ba01\n"
        "movl %esi, %ebx\n" /* sourceBuf2, dest */
        "xorl %edx, %edx\n"
        ".Lf9b986_0009ba64:\n"
        "movzbl (%ecx), %eax\n" /* line 615 */
        "addl $1, %ecx\n" /* line 616 */
        "movb %al, (%ebx)\n" /* line 617 | dest */
        "addl $1, %ebx\n" /* line 618 | dest */
        "addl $1, %edx\n" /* line 613 */
        "cmpl %edx, 8(%ebp)\n" /* len */
        "jge .Lf9b986_0009ba64\n"
        "movl scrParserGlob+24, %edx\n" /* line 554 */
        "cmpl %edx, scrParserPub+4\n"
        "jb .Lf9b986_0009ba0f\n"
        ".Lf9b986_0009ba85:\n"
        "leal (%edx, %edx), %eax\n" /* line 556 */
        "movl %eax, scrParserGlob+24\n"
        "addl %edx, %eax\n" /* line 558 */
        "shll $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl scrParserPub+4, %eax\n" /* line 559 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl scrParserPub, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl scrParserPub, %eax\n" /* line 560 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl %ebx, scrParserPub\n" /* line 561 */
        "movl %ebx, %ecx\n"
        "jmp .Lf9b986_0009ba15\n"
        ".Lf9b986_0009bad6:\n"
        "movl $0, scrParserPub+12\n" /* line 585 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9b986_0009bae8:\n"
        "movl $1, %edx\n" /* line 600 */
        "movzbl (%ecx), %eax\n" /* line 602 */
        "addl $1, %ecx\n" /* line 603 */
        "cmpb $0xa, %al\n" /* line 604 */
        "je .Lf9b986_0009bb15\n"
        ".Lf9b986_0009baf7:\n"
        "cmpb $0xd, %al\n"
        "je .Lf9b986_0009bb1c\n"
        ".Lf9b986_0009bafb:\n"
        "movb %al, -1(%esi, %edx)\n" /* line 607 | sourceBuf2 */
        ".Lf9b986_0009baff:\n"
        "cmpl %edx, 8(%ebp)\n" /* line 600 | len */
        "jl .Lf9b986_0009ba01\n"
        "addl $1, %edx\n" /* line 598 */
        "movzbl (%ecx), %eax\n" /* line 602 */
        "addl $1, %ecx\n" /* line 603 */
        "cmpb $0xa, %al\n" /* line 604 */
        "jne .Lf9b986_0009baf7\n"
        ".Lf9b986_0009bb15:\n"
        "movb $0, -1(%esi, %edx)\n" /* line 605 | sourceBuf2 */
        "jmp .Lf9b986_0009baff\n"
        ".Lf9b986_0009bb1c:\n"
        "cmpb $0xa, (%ecx)\n" /* line 604 */
        "je .Lf9b986_0009bafb\n"
        "movb $0, -1(%esi, %edx)\n" /* line 605 | sourceBuf2 */
        "jmp .Lf9b986_0009baff\n"
        ".Lf9b986_0009bb28:\n"
        "xorl %esi, %esi\n" /* line 594 | sourceBuf2 */
        "jmp .Lf9b986_0009b9ed\n"
    );
}

/* line 750 */
__attribute__((naked))
char * Scr_AddSourceBuffer(const char *filename, const char *extFilename, const char *codePos, int archive)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 750 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movzbl 0x14(%ebp), %eax\n" /* archive */
        "movb %al, -0x31(%ebp)\n" /* archive */
        /* { scope 1 */
        "testb %al, %al\n" /* line 760 */
        "je .Lf9bb30_0009bbee\n"
        "movl scrParserGlob+36, %edx\n"
        "testl %edx, %edx\n"
        "je .Lf9bb30_0009bc94\n"
        "movl scrParserGlob+40, %edx\n" /* line 763 */
        "subl $1, %edx\n"
        "movl %edx, scrParserGlob+40\n"
        "movl scrParserGlob+36, %eax\n" /* line 764 */
        "leal (%eax, %edx, 8), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* saveSourceBuffer */
        "movl 4(%edx), %edx\n" /* line 765 */
        "movl %edx, -0x30(%ebp)\n" /* len */
        "testl %edx, %edx\n" /* line 768 */
        "js .Lf9bb30_0009bbbf\n"
        "movl %edx, %eax\n" /* line 774 */
        "addl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %edi\n" /* sourceBuf */
        "movl -0x2c(%ebp), %eax\n" /* line 776 | saveSourceBuffer */
        "movl (%eax), %ebx\n" /* source */
        "movl -0x30(%ebp), %eax\n" /* line 779 | len */
        "testl %eax, %eax\n"
        "jg .Lf9bb30_0009bc6e\n"
        "movl %edi, %ecx\n" /* sourceBuf */
        ".Lf9bb30_0009bb9b:\n"
        "movb $0, (%ecx)\n" /* line 786 */
        "movl -0x2c(%ebp), %edx\n" /* line 788 | saveSourceBuffer */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf9bb30_0009bbc1\n"
        "movl scrParserGlob+40, %eax\n" /* line 789 */
        "movl scrParserGlob+36, %edx\n"
        "movl (%edx, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "jmp .Lf9bb30_0009bbc1\n"
        /* { scope 2: f */
        /* { scope 3 */
        ".Lf9bb30_0009bbbf:\n"
        "xorl %edi, %edi\n" /* line 705 */
        /* } scope */
        /* } scope */
        ".Lf9bb30_0009bbc1:\n"
        "movzbl -0x31(%ebp), %eax\n" /* line 797 | archive */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* len */
        "movl %eax, (%esp)\n"
        "movl %edi, %ecx\n" /* sourceBuf */
        "movl 0x10(%ebp), %edx\n" /* codePos */
        "movl 0xc(%ebp), %eax\n" /* extFilename */
        "calll Scr_AddSourceBufferInternal\n"
        /* } scope */
        ".Lf9bb30_0009bbe4:\n"
        "movl %edi, %eax\n" /* line 799 | sourceBuf */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9bb30_0009bbee:\n"
        "movl %eax, %esi\n" /* archive */
        /* { scope 1 */
        /* { scope 2: f */
        /* { scope 3 */
        ".Lf9bb30_0009bbf0:\n"
        "movl $0, 8(%esp)\n" /* line 692 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* extFilename */
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %ebx\n" /* len */
        "testl %eax, %eax\n" /* line 693 */
        "js .Lf9bb30_0009bc9d\n"
        "leal 1(%eax), %eax\n" /* line 699 */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %edi\n"
        "movl -0x1c(%ebp), %eax\n" /* line 700 | f */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* len */
        "movl %edi, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, (%edi, %ebx)\n" /* line 701 */
        "movl -0x1c(%ebp), %eax\n" /* line 702 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %esi, %edx\n" /* line 705 */
        "movzbl %dl, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* len */
        "movl %edi, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* codePos */
        "movl 0xc(%ebp), %eax\n" /* extFilename */
        "calll Scr_AddSourceBufferInternal\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %edi, %eax\n" /* line 799 | sourceBuf */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9bb30_0009bc6e:\n"
        "movl %edi, %ecx\n" /* line 779 | sourceBuf */
        "xorl %esi, %esi\n" /* i */
        ".Lf9bb30_0009bc72:\n"
        "movzbl (%ebx), %eax\n" /* line 781 | source */
        "addl $1, %ebx\n" /* line 782 | source */
        "testb %al, %al\n" /* line 783 */
        "movl $0xa, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, (%ecx)\n"
        "addl $1, %ecx\n" /* line 784 */
        "addl $1, %esi\n" /* line 779 | i */
        "cmpl %esi, -0x30(%ebp)\n" /* i, len */
        "jne .Lf9bb30_0009bc72\n"
        "jmp .Lf9bb30_0009bb9b\n"
        ".Lf9bb30_0009bc94:\n"
        "movzbl -0x31(%ebp), %esi\n" /* archive, i */
        "jmp .Lf9bb30_0009bbf0\n"
        /* { scope 2: f */
        /* { scope 3 */
        ".Lf9bb30_0009bc9d:\n"
        "movl %esi, %edx\n" /* line 695 */
        "movzbl %dl, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* codePos */
        "movl 0xc(%ebp), %eax\n" /* extFilename */
        "calll Scr_AddSourceBufferInternal\n"
        "xorl %edi, %edi\n"
        "jmp .Lf9bb30_0009bbe4\n"
    );
}

/* line 830 */
static __attribute__((naked))
void Scr_PrintSourcePos(const char *filename, unsigned int sourcePos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 830 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl %eax, %esi\n" /* type */
        "movl %edx, -0x424(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* sourcePos */
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        "testl %edi, %edi\n" /* line 488 */
        "jne .Lf9bcca_0009be09\n"
        "movl %ecx, %ebx\n"
        "movl $0, -0x420(%ebp)\n"
        "movl $0, -0x41c(%ebp)\n"
        /* } scope */
        ".Lf9bcca_0009bcff:\n"
        "cld\n" /* line 813 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* startLine */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x3ff, %ecx\n" /* line 814 */
        "jle .Lf9bcca_0009bde6\n"
        "movl $0x3ff, %ecx\n"
        ".Lf9bcca_0009bd21:\n"
        "movl $1, %edi\n" /* line 817 */
        "jmp .Lf9bcca_0009bd2b\n"
        ".Lf9bcca_0009bd28:\n"
        "addl $1, %edi\n"
        ".Lf9bcca_0009bd2b:\n"
        "movzbl -1(%ebx, %edi), %eax\n" /* line 819 | startLine */
        "cmpb $9, %al\n" /* line 820 */
        "movl $0x20, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, -0x419(%edi, %ebp)\n"
        "cmpl %edi, %ecx\n" /* line 817 */
        "jge .Lf9bcca_0009bd28\n"
        "leal -0x418(%ebp), %eax\n" /* line 823 | line */
        "addl %ecx, %eax\n"
        "cmpb $0xd, -1(%eax)\n"
        "je .Lf9bcca_0009be00\n"
        /* } scope */
        ".Lf9bcca_0009bd57:\n"
        "movl -0x41c(%ebp), %ecx\n" /* line 839 | buf */
        "addl $1, %ecx\n" /* buf */
        "movl $str_0021dc08, %edx\n" /* " (savegame)" */
        "movl scrParserGlob+36, %ebx\n" /* startLine */
        "testl %ebx, %ebx\n" /* startLine */
        "movl $str_002157b8, %eax\n"
        "cmovel %eax, %edx\n"
        "movl %ecx, 0xc(%esp)\n" /* buf */
        "movl %edx, 8(%esp)\n"
        "movl -0x424(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021dc14, (%esp)\n" /* "(file '%s'%s, line %d)
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* type */
        "calll Com_PrintMessage\n"
        "leal -0x418(%ebp), %eax\n" /* line 840 | line */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* type */
        "calll Com_PrintMessage\n"
        "movl -0x420(%ebp), %ecx\n" /* line 842 | buf */
        "testl %ecx, %ecx\n" /* buf */
        "jg .Lf9bcca_0009be42\n"
        "movl $str_0021dc2c, 4(%esp)\n" /* line 844 */
        "movl %esi, (%esp)\n" /* type */
        "calll Com_PrintMessage\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 845 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf9bcca_0009bde6:\n"
        "testl %ecx, %ecx\n" /* line 817 */
        "jns .Lf9bcca_0009bd21\n"
        "leal -0x418(%ebp), %eax\n" /* line 823 | line */
        "addl %ecx, %eax\n"
        "cmpb $0xd, -1(%eax)\n"
        "jne .Lf9bcca_0009bd57\n"
        ".Lf9bcca_0009be00:\n"
        "movb $0, -1(%eax)\n" /* line 824 */
        "jmp .Lf9bcca_0009bd57\n"
        /* { scope 3 */
        ".Lf9bcca_0009be09:\n"
        "movl %ecx, %ebx\n" /* line 488 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "jmp .Lf9bcca_0009be1b\n"
        ".Lf9bcca_0009be11:\n"
        "addl $1, %ecx\n" /* line 490 */
        "addl $1, %eax\n" /* line 493 */
        "cmpl %eax, %edi\n" /* line 488 */
        "je .Lf9bcca_0009be2f\n"
        ".Lf9bcca_0009be1b:\n"
        "cmpb $0, (%ecx)\n" /* line 490 */
        "jne .Lf9bcca_0009be11\n"
        "leal 1(%ecx), %ebx\n" /* line 492 */
        "addl $1, %edx\n" /* line 493 */
        "movl %ebx, %ecx\n"
        "addl $1, %eax\n"
        "cmpl %eax, %edi\n" /* line 488 */
        "jne .Lf9bcca_0009be1b\n"
        ".Lf9bcca_0009be2f:\n"
        "subl %ebx, %ecx\n"
        "movl %ecx, -0x420(%ebp)\n"
        "movl %edx, -0x41c(%ebp)\n"
        "jmp .Lf9bcca_0009bcff\n"
        /* } scope */
        /* } scope */
        ".Lf9bcca_0009be42:\n"
        "xorl %edi, %edi\n" /* line 842 | i */
        ".Lf9bcca_0009be44:\n"
        "movl $str_00217914, 4(%esp)\n" /* line 843 */
        "movl %esi, (%esp)\n" /* type */
        "calll Com_PrintMessage\n"
        "addl $1, %edi\n" /* line 842 | i */
        "cmpl -0x420(%ebp), %edi\n" /* i */
        "jne .Lf9bcca_0009be44\n"
        "movl $str_0021dc2c, 4(%esp)\n" /* line 844 */
        "movl %esi, (%esp)\n" /* type */
        "calll Com_PrintMessage\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 845 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1106 */
__attribute__((naked))
void CompileError(unsigned int sourcePos, const char *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1106 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        /* { scope 1 */
        "leal 0x10(%ebp), %eax\n" /* line 1111 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 1112 */
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x40c(%ebp), %esi\n" /* text */
        "movl %esi, (%esp)\n"
        "calll vsnprintf\n"
        "movl imp_scrVarPub, %ebx\n" /* line 1115 */
        "cmpb $0, 0xc(%ebx)\n"
        "je .Lf9be7a_0009becd\n"
        "movl 0x10(%ebx), %eax\n" /* line 1117 */
        "testl %eax, %eax\n"
        "je .Lf9be7a_0009bf50\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 1137 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9be7a_0009becd:\n"
        "movl $str_002160e8, (%esp)\n" /* line 1122 */
        "calll Com_Printf\n"
        "movl $str_0021dc30, (%esp)\n" /* line 1123 */
        "calll Com_Printf\n"
        "cmpb $0, 0xa(%ebx)\n" /* line 1125 */
        "jne .Lf9be7a_0009bf25\n"
        "movl %esi, 4(%esp)\n" /* line 1127 */
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf9be7a_0009befb:\n"
        "movl $str_0021dc60, (%esp)\n" /* line 1135 */
        "calll Com_Printf\n"
        "movl $str_0021dc88, 4(%esp)\n" /* line 1136 */
        "movl $5, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 1137 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9be7a_0009bf25:\n"
        "movl %esi, 4(%esp)\n" /* line 1132 */
        "movl $str_0021dc58, (%esp)\n" /* "%s: " */
        "calll Com_Printf\n"
        "movl 8(%ebp), %eax\n" /* line 1133 | sourcePos */
        "movl %eax, (%esp)\n"
        "movl scrParserPub+12, %ecx\n"
        "movl scrParserPub+8, %edx\n"
        "xorl %eax, %eax\n"
        "calll Scr_PrintSourcePos\n"
        "jmp .Lf9be7a_0009befb\n"
        ".Lf9be7a_0009bf50:\n"
        "movl %esi, 4(%esp)\n" /* line 1118 */
        "movl $str_00216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "movl %eax, 0x10(%ebx)\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 1137 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 881 */
__attribute__((naked))
void Scr_PrintPrevCodePos(print_msg_type_t type, const char *codePos, unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 881 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %eax\n" /* type */
        "movl %eax, -0x2c(%ebp)\n" /* type */
        "movl 0xc(%ebp), %ebx\n" /* codePos */
        "movl 0x10(%ebp), %edx\n" /* index */
        "movl %edx, -0x30(%ebp)\n" /* index */
        /* { scope 1: codePos */
        "testl %ebx, %ebx\n" /* line 885 | codePos */
        "je .Lf9bf70_0009c104\n"
        "cmpl imp_g_EndPos, %ebx\n" /* line 891 | codePos */
        "je .Lf9bf70_0009c110\n"
        "movl imp_scrVarPub, %esi\n" /* line 893 | bufferIndex */
        "cmpb $0, 0xa(%esi)\n" /* bufferIndex */
        "je .Lf9bf70_0009c078\n"
        "movl 0x48(%esi), %ecx\n" /* line 903 | bufferIndex */
        "testl %ecx, %ecx\n"
        "je .Lf9bf70_0009c087\n"
        "movl %ebx, (%esp)\n" /* codePos */
        "calll Scr_IsInOpcodeMemory\n"
        "testl %eax, %eax\n"
        "je .Lf9bf70_0009c087\n"
        "subl $1, %ebx\n" /* line 905 | codePos */
        "movl %ebx, -0x28(%ebp)\n" /* codePos */
        /* { scope 2 */
        "movl scrParserPub+4, %esi\n" /* line 869 */
        "subl $1, %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf9bf70_0009c11f\n"
        "movl %esi, %ebx\n" /* line 881 | codePos */
        "leal (%esi, %esi, 2), %eax\n"
        "movl scrParserPub, %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "leal (%edx, %eax, 8), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf9bf70_0009bff1:\n"
        "movl (%edx), %eax\n" /* line 871 */
        "testl %eax, %eax\n"
        "je .Lf9bf70_0009bffc\n"
        "cmpl %eax, -0x28(%ebp)\n" /* line 873 | codePos */
        "jae .Lf9bf70_0009c009\n"
        ".Lf9bf70_0009bffc:\n"
        "subl $1, %esi\n" /* line 869 */
        "addl $1, %ecx\n"
        "subl $0x18, %edx\n"
        "cmpl %ecx, %ebx\n"
        "jne .Lf9bf70_0009bff1\n"
        /* } scope */
        ".Lf9bf70_0009c009:\n"
        "movl scrParserGlob+12, %eax\n" /* line 477 */
        "movl %eax, -0x24(%ebp)\n"
        /* { scope 2 */
        "movl scrParserGlob+8, %edx\n" /* line 424 */
        "movl %edx, -0x20(%ebp)\n"
        "movl %edx, %ecx\n" /* line 425 */
        "subl $1, %ecx\n"
        "js .Lf9bf70_0009c0ca\n"
        "movl scrParserGlob, %ebx\n" /* line 428 */
        "movl %ebx, -0x1c(%ebp)\n"
        "xorl %edi, %edi\n" /* low */
        "jmp .Lf9bf70_0009c054\n"
        ".Lf9bf70_0009c032:\n"
        "leal 1(%edx), %edi\n" /* line 430 | low */
        "cmpl %edi, -0x20(%ebp)\n" /* line 431 | low */
        "je .Lf9bf70_0009c0d1\n"
        "leal (%edi, %edi, 4), %edx\n" /* low */
        "movl %edx, -0x3c(%ebp)\n"
        "movl -0x1c(%ebp), %ebx\n"
        "cmpl (%ebx, %edx, 4), %eax\n"
        "jb .Lf9bf70_0009c0d1\n"
        ".Lf9bf70_0009c050:\n"
        "cmpl %edi, %ecx\n" /* line 425 | low */
        "jl .Lf9bf70_0009c0ca\n"
        ".Lf9bf70_0009c054:\n"
        "leal (%edi, %ecx), %eax\n" /* line 427 | low */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "leal (%edx, %edx, 4), %ebx\n" /* line 428 */
        "movl -0x1c(%ebp), %eax\n"
        "leal (%eax, %ebx, 4), %ebx\n"
        "movl %ebx, -0x4c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* codePos */
        "cmpl (%ebx), %eax\n"
        "jae .Lf9bf70_0009c032\n"
        "leal -1(%edx), %ecx\n" /* line 436 */
        "jmp .Lf9bf70_0009c050\n"
        /* } scope */
        ".Lf9bf70_0009c078:\n"
        "leal -1(%ebx), %eax\n" /* line 895 | codePos */
        "movl %eax, (%esp)\n"
        "calll Scr_IsInOpcodeMemory\n"
        "testl %eax, %eax\n"
        "jne .Lf9bf70_0009c0ac\n"
        ".Lf9bf70_0009c087:\n"
        "movl %ebx, 4(%esp)\n" /* line 911 | codePos */
        "movl $str_0021dcd4, (%esp)\n" /* "%s

" */
        "calll va\n"
        "movl %eax, 0xc(%ebp)\n" /* codePos */
        "movl -0x2c(%ebp), %eax\n" /* type */
        "movl %eax, 8(%ebp)\n" /* type */
        /* } scope */
        ".Lf9bf70_0009c0a0:\n"
        "addl $0x5c, %esp\n" /* line 916 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: codePos */
        "jmp Com_PrintMessage\n" /* line 897 */
        ".Lf9bf70_0009c0ac:\n"
        "subl 0x48(%esi), %ebx\n" /* bufferIndex, codePos */
        "movl %ebx, 4(%esp)\n" /* codePos */
        "movl $str_0021dccc, (%esp)\n" /* "@ %d
" */
        "calll va\n"
        "movl %eax, 0xc(%ebp)\n" /* codePos */
        "movl -0x2c(%ebp), %ecx\n" /* type */
        "movl %ecx, 8(%ebp)\n" /* type */
        "jmp .Lf9bf70_0009c0a0\n"
        /* { scope 2 */
        ".Lf9bf70_0009c0ca:\n"
        "movl $0, -0x4c(%ebp)\n" /* line 425 */
        /* } scope */
        ".Lf9bf70_0009c0d1:\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 906 | bufferIndex */
        "movl -0x34(%ebp), %esi\n" /* bufferIndex */
        "leal (%esi, %eax, 8), %eax\n" /* bufferIndex */
        "movl 8(%eax), %ecx\n"
        "movl 4(%eax), %edx\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl 4(%eax), %eax\n"
        "addl %eax, -0x30(%ebp)\n" /* index */
        "movl -0x30(%ebp), %ebx\n" /* index, codePos */
        "movl -0x24(%ebp), %esi\n" /* bufferIndex */
        "movl (%esi, %ebx, 8), %eax\n" /* bufferIndex */
        "movl %eax, 8(%ebp)\n" /* type */
        "movl -0x2c(%ebp), %eax\n" /* type */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 916 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: codePos */
        "jmp Scr_PrintSourcePos\n" /* line 906 */
        ".Lf9bf70_0009c104:\n"
        "movl $str_0021dcb8, 0xc(%ebp)\n" /* line 887 | codePos */
        "movl %eax, 8(%ebp)\n" /* type */
        "jmp .Lf9bf70_0009c0a0\n"
        ".Lf9bf70_0009c110:\n"
        "movl $str_0021dcdc, 0xc(%ebp)\n" /* line 915 | codePos */
        "movl -0x2c(%ebp), %edx\n" /* type */
        "movl %edx, 8(%ebp)\n" /* type */
        "jmp .Lf9bf70_0009c0a0\n"
        ".Lf9bf70_0009c11f:\n"
        "movl scrParserPub, %ebx\n" /* codePos */
        "movl %ebx, -0x34(%ebp)\n" /* codePos */
        "jmp .Lf9bf70_0009c009\n"
    );
}

/* line 1187 */
__attribute__((naked))
void RuntimeError(const char *codePos, unsigned int index, const char *msg, const char *dialogMessage)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1187 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl imp_scrVarPub, %eax\n" /* line 1191 */
        "cmpb $0, 0xa(%eax)\n"
        "jne .Lf9c12e_0009c218\n"
        "movl imp_scrVmPub, %ebx\n" /* line 1194 */
        "cmpb $0, 0x16(%ebx)\n"
        "je .Lf9c12e_0009c210\n"
        "cmpb $0, 0x14(%ebx)\n" /* line 1198 */
        "jne .Lf9c12e_0009c228\n"
        ".Lf9c12e_0009c160:\n"
        "testl $g_effectVisArray+4096, 0x14(%ebx)\n" /* line 1206 */
        "setne -0x1d(%ebp)\n" /* abort_on_error */
        "cmpb $1, -0x1d(%ebp)\n" /* line 1208 | abort_on_error */
        "sbbl %esi, %esi\n" /* type */
        "andl $4, %esi\n" /* type */
        /* { scope 2 */
        "movl 0x10(%ebp), %edx\n" /* line 1167 | msg */
        "movl %edx, 4(%esp)\n"
        "movl $str_0021dcf0, (%esp)\n" /* "
******* script runtime error *******
%s: " */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_PrintMessage\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1168 | index */
        "movl %ecx, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* codePos */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Scr_PrintPrevCodePos\n"
        "movl imp_scrVmPub, %edx\n" /* line 1170 */
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf9c12e_0009c24d\n"
        "movl $str_0021dc60, 4(%esp)\n" /* line 1183 */
        "movl %esi, (%esp)\n"
        "calll Com_PrintMessage\n"
        /* } scope */
        "cmpb $0, -0x1d(%ebp)\n" /* line 1210 | abort_on_error */
        "je .Lf9c12e_0009c210\n"
        ".Lf9c12e_0009c1d0:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1214 | dialogMessage */
        "testl %ebx, %ebx\n"
        "je .Lf9c12e_0009c2e1\n"
        ".Lf9c12e_0009c1db:\n"
        "movl $str_002160e8, %edx\n" /* "
" */
        ".Lf9c12e_0009c1e0:\n"
        "movl imp_scrVmPub, %eax\n"
        "cmpb $1, 0x16(%eax)\n"
        "sbbl %eax, %eax\n"
        "addl $5, %eax\n"
        "movl 0x14(%ebp), %ecx\n" /* dialogMessage */
        "movl %ecx, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* msg */
        "movl %edx, 8(%esp)\n"
        "movl $str_0021dd2c, 4(%esp)\n" /* "script runtime error
(see console for details)
%s%s%s" */
        "movl %eax, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf9c12e_0009c210:\n"
        "addl $0x3c, %esp\n" /* line 1215 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9c12e_0009c218:\n"
        "movl imp_scrVmPub, %ebx\n"
        /* { scope 1 */
        "cmpb $0, 0x14(%ebx)\n" /* line 1198 */
        "je .Lf9c12e_0009c160\n"
        ".Lf9c12e_0009c228:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1200 | msg */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "cmpb $0, 0x16(%ebx)\n" /* line 1201 */
        "je .Lf9c12e_0009c210\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1214 | dialogMessage */
        "testl %ebx, %ebx\n"
        "jne .Lf9c12e_0009c1db\n"
        "jmp .Lf9c12e_0009c2e1\n"
        /* { scope 2 */
        ".Lf9c12e_0009c24d:\n"
        "subl $1, %eax\n" /* line 1172 */
        "movl %eax, -0x1c(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf9c12e_0009c296\n"
        "xorl %edi, %edi\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x20(%edx, %eax, 8), %ebx\n"
        ".Lf9c12e_0009c260:\n"
        "movl $str_0021d430, 4(%esp)\n" /* line 1174 */
        "movl %esi, (%esp)\n"
        "calll Com_PrintMessage\n"
        "xorl %eax, %eax\n" /* line 1176 */
        "cmpl $0, 4(%ebx)\n"
        "sete %al\n"
        "movl %eax, 8(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Scr_PrintPrevCodePos\n"
        "addl $1, %edi\n"
        "subl $0x18, %ebx\n"
        "cmpl %edi, -0x1c(%ebp)\n" /* line 1172 */
        "jne .Lf9c12e_0009c260\n"
        ".Lf9c12e_0009c296:\n"
        "movl $str_0021dd1c, 4(%esp)\n" /* line 1179 */
        "movl %esi, (%esp)\n"
        "calll Com_PrintMessage\n"
        "movl $1, 8(%esp)\n" /* line 1180 */
        "movl imp_scrVmPub, %eax\n"
        "movl 0x20(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Scr_PrintPrevCodePos\n"
        "movl $str_0021dc60, 4(%esp)\n" /* line 1183 */
        "movl %esi, (%esp)\n"
        "calll Com_PrintMessage\n"
        /* } scope */
        "cmpb $0, -0x1d(%ebp)\n" /* line 1210 | abort_on_error */
        "jne .Lf9c12e_0009c1d0\n"
        "jmp .Lf9c12e_0009c210\n"
        ".Lf9c12e_0009c2e1:\n"
        "movl $str_002157b8, %edx\n" /* line 1214 */
        "movl $str_002157b8, 0x14(%ebp)\n" /* dialogMessage */
        "jmp .Lf9c12e_0009c1e0\n"
    );
}

/* line 1140 */
__attribute__((naked))
void CompileError2(const char *codePos, const char *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1140 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x424, %esp\n"
        /* { scope 1 */
        "movl $str_002160e8, (%esp)\n" /* line 1148 */
        "calll Com_Printf\n"
        "movl $str_0021dc30, (%esp)\n" /* line 1149 */
        "calll Com_Printf\n"
        "leal 0x10(%ebp), %eax\n" /* line 1151 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 1152 */
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x40c(%ebp), %ebx\n" /* text */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "movl %ebx, 4(%esp)\n" /* line 1154 */
        "movl $str_0021dc58, (%esp)\n" /* "%s: " */
        "calll Com_Printf\n"
        "movl $0, 8(%esp)\n" /* line 1155 */
        "movl 8(%ebp), %eax\n" /* codePos */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_PrintPrevCodePos\n"
        "movl $str_0021dc60, (%esp)\n" /* line 1156 */
        "calll Com_Printf\n"
        "movl $str_0021dc88, 4(%esp)\n" /* line 1157 */
        "movl $5, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x424, %esp\n" /* line 1158 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

