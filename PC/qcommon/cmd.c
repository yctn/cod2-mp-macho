/* ASM dump from: cmd.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cmd.cpp */

#include "common_types.h"
#include "imports.h"

extern int cmd_wait; /* 0x0 */
extern cmd_t cmd_texts[1]; /* 0x0 */
extern cmd_t *cmd_text; /* 0x0 */
static cmd_text_buf_t cmd_text_buf; /* 0x485f00 */
static int cmd_argc; /* 0x483880 */
static char * cmd_argv[512]; /* 0x483080 */
static char cmd_tokenized[8704]; /* 0x483900 */
static cmd_function_t *cmd_functions; /* 0x483000 */
static char cmd_args1[1024]; /* 0x485b00 */

int Cmd_Argc(void);
char * Cmd_Argv(int arg);
void Cbuf_Init(void);
void Cbuf_AddText(const char *text);
int SV_Cmd_Argc(void);
char * SV_Cmd_Argv(int arg);
char * Cmd_Args(int start);
static int Cmd_TokenizeStringInternal(char *textOut);
void Cmd_TokenizeString2(const char *text_in, int max_tokens);
void Cmd_RemoveCommand(const char *cmdName);
void Cmd_Shutdown(void);
void Cmd_ForEach(void (*callback)());
void Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength);
void Cmd_Wait_f(void);
void Cmd_List_f(void);
void SV_Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength);
void Cmd_ExecuteString(const char *text);
void SV_Cmd_ExecuteString(const char *text);
static void Cbuf_ExecuteInternal(void);
void Cbuf_Execute(void);
void Cmd_TokenizeString(const char *text_in);
void SV_Cmd_TokenizeString(const char *text_in);
void Cmd_AddCommand(const char *cmdName, xcommand_t function);
void Cmd_SetAutoComplete(const char *cmdName, const char *dir, const char *ext);
const char * * Cmd_GetAutoCompleteFileList(const char *cmdName, int *fileCount, int allocTrackType);
void Cmd_ArgsBuffer(char *buffer, int bufferLength);
void Cbuf_ExecuteText(int exec_when, const char *text);
void Cmd_Vstr_f(void);
static void Cmd_Exec_f(void);
void Cmd_Init(void);

/* line 649 */
__attribute__((naked))
int Cmd_Argc(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 649 */
        "movl %esp, %ebp\n"
        "movl cmd_argc, %eax\n"
        "popl %ebp\n" /* line 652 */
        "retl\n"
    );
}

/* line 677 */
__attribute__((naked))
char * Cmd_Argv(int arg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 677 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* arg */
        "cmpl %eax, cmd_argc\n" /* line 680 */
        "jle .Lf4f150_0004f167\n"
        "movl cmd_argv(, %eax, 4), %eax\n" /* line 685 */
        "popl %ebp\n" /* line 686 */
        "retl\n"
        ".Lf4f150_0004f167:\n"
        "movl $0x2157b8, %eax\n" /* line 680 */
        "popl %ebp\n" /* line 686 */
        "retl\n"
    );
}

/* line 148 */
__attribute__((naked))
void Cbuf_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 148 */
        "movl %esp, %ebp\n"
        "movl $0x485f00, cmd_texts\n" /* line 154 */
        "movl $0x10000, 0xffec08\n" /* line 155 */
        "movl $0, 0xffec0c\n" /* line 156 */
        "popl %ebp\n" /* line 164 */
        "retl\n"
    );
}

/* line 174 */
__attribute__((naked))
void Cbuf_AddText(const char *text)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 174 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* text */
        /* { scope 1 */
        "cld\n" /* line 178 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* text, length */
        "repne scasb %es:(%edi), %al\n" /* length */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* length */
        "movl cmd_text, %edx\n" /* line 180 */
        "movl 8(%edx), %ecx\n"
        "leal (%edi, %ecx), %eax\n" /* length */
        "cmpl 4(%edx), %eax\n"
        "jl .Lf4f192_0004f1d1\n"
        "movl $0x218f18, 8(%ebp)\n" /* line 182 | text */
        /* } scope */
        "addl $0x10, %esp\n" /* line 187 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 182 */
        ".Lf4f192_0004f1d1:\n"
        "addl (%edx), %ecx\n" /* line 185 */
        "movl %edi, 8(%esp)\n" /* length */
        "movl %ebx, 4(%esp)\n" /* text */
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl cmd_text, %eax\n" /* line 186 */
        "addl %edi, 8(%eax)\n" /* length */
        /* } scope */
        "addl $0x10, %esp\n" /* line 187 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 660 */
__attribute__((naked))
int SV_Cmd_Argc(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 660 */
        "movl %esp, %ebp\n"
        "movl cmd_argc, %eax\n"
        "popl %ebp\n" /* line 669 */
        "retl\n"
    );
}

/* line 694 */
__attribute__((naked))
char * SV_Cmd_Argv(int arg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 694 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* arg */
        "cmpl %eax, cmd_argc\n" /* line 708 */
        "jle .Lf4f1fe_0004f215\n"
        "movl cmd_argv(, %eax, 4), %eax\n" /* line 713 */
        "popl %ebp\n" /* line 715 */
        "retl\n"
        ".Lf4f1fe_0004f215:\n"
        "movl $0x2157b8, %eax\n" /* line 708 */
        "popl %ebp\n" /* line 715 */
        "retl\n"
    );
}

/* line 753 */
__attribute__((naked))
char * Cmd_Args(int start)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 753 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* start */
        /* { scope 1 */
        "movb $0, cmd_args1\n" /* line 760 */
        "cmpl cmd_argc, %eax\n" /* line 761 */
        "jl .Lf4f21c_0004f242\n"
        /* } scope */
        "movl $cmd_args1, %eax\n" /* line 771 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f21c_0004f242:\n"
        "leal cmd_argv(, %eax, 4), %esi\n" /* line 761 */
        "movl %eax, %ebx\n" /* i */
        ".Lf4f21c_0004f24b:\n"
        "movl (%esi), %eax\n" /* line 763 */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl $cmd_args1, (%esp)\n"
        "calll I_strncat\n"
        "movl cmd_argc, %eax\n" /* line 764 */
        "subl $1, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "je .Lf4f21c_0004f28d\n"
        "movl $0x217914, 8(%esp)\n" /* line 766 */
        "movl $0x400, 4(%esp)\n"
        "movl $cmd_args1, (%esp)\n"
        "calll I_strncat\n"
        ".Lf4f21c_0004f28d:\n"
        "addl $1, %ebx\n" /* line 761 | i */
        "addl $4, %esi\n"
        "cmpl %ebx, cmd_argc\n" /* i */
        "jg .Lf4f21c_0004f24b\n"
        /* } scope */
        "movl $cmd_args1, %eax\n" /* line 771 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 798 */
static __attribute__((naked))
int Cmd_TokenizeStringInternal(char *textOut)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 798 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl %ecx, %edi\n" /* argv */
        "movl 8(%ebp), %ebx\n" /* textOut */
        "movl %eax, %ecx\n" /* text_in */
        "movl $0, -0x14(%ebp)\n" /* argc */
        "xorl %esi, %esi\n"
        "subl $1, %edx\n" /* max_tokens */
        "movl %edx, -0x18(%ebp)\n" /* max_tokens */
        /* { scope 1 */
        ".Lf4f2a8_0004f2c7:\n"
        "cmpl %esi, -0x18(%ebp)\n" /* line 815 */
        "je .Lf4f2a8_0004f423\n"
        ".Lf4f2a8_0004f2d0:\n"
        "movzbl (%ecx), %eax\n" /* line 824 | text_in */
        "testb %al, %al\n" /* text_in */
        "je .Lf4f2a8_0004f333\n"
        "cmpb $0x20, %al\n" /* text_in */
        "jle .Lf4f2a8_0004f36b\n"
        "cmpb $0x2f, %al\n" /* line 835 | text_in */
        "je .Lf4f2a8_0004f388\n"
        "cmpb $0x22, %al\n" /* line 854 | text_in */
        "jne .Lf4f2a8_0004f3b5\n"
        "movl -0x14(%ebp), %eax\n" /* line 856 | argc, text_in */
        "movl %ebx, (%edi, %eax, 4)\n" /* textOut, argv */
        "addl $1, %eax\n" /* line 857 | text_in */
        "movl %eax, -0x14(%ebp)\n" /* text_in, argc */
        "leal 1(%ecx), %edx\n" /* line 858 | max_tokens */
        "movzbl 1(%ecx), %eax\n" /* line 859 | text_in */
        "testb %al, %al\n" /* text_in */
        "jne .Lf4f2a8_0004f350\n"
        ".Lf4f2a8_0004f306:\n"
        "movb $0, (%ebx)\n" /* line 865 | textOut */
        "addl $1, %ebx\n" /* textOut */
        "cmpb $0, (%edx)\n" /* line 866 | max_tokens */
        "je .Lf4f2a8_0004f333\n"
        "leal 1(%edx), %ecx\n" /* line 868 | max_tokens */
        "movzbl 1(%edx), %eax\n" /* line 870 | max_tokens, text_in */
        "testb %al, %al\n" /* text_in */
        "je .Lf4f2a8_0004f333\n"
        "cmpb $0x20, %al\n" /* line 877 | text_in */
        "jle .Lf4f2a8_0004f373\n"
        /* } scope */
        ".Lf4f2a8_0004f320:\n"
        "addl $1, %esi\n" /* line 798 */
        /* { scope 1 */
        "cmpl $0x200, -0x14(%ebp)\n" /* line 811 | argc */
        "jne .Lf4f2a8_0004f2c7\n"
        ".Lf4f2a8_0004f32c:\n"
        "movl $0, -0x14(%ebp)\n" /* argc */
        /* } scope */
        ".Lf4f2a8_0004f333:\n"
        "movl -0x14(%ebp), %eax\n" /* line 942 | argc, text_in */
        "addl $0xc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f2a8_0004f33e:\n"
        "addl $1, %edx\n" /* line 861 | max_tokens */
        ".Lf4f2a8_0004f341:\n"
        "movzbl (%ecx), %eax\n" /* line 863 | text_in */
        "movb %al, (%ebx)\n" /* text_in, textOut */
        "addl $1, %ebx\n" /* textOut */
        "movzbl (%edx), %eax\n" /* line 859 | max_tokens, text_in */
        "testb %al, %al\n" /* text_in */
        "je .Lf4f2a8_0004f306\n"
        ".Lf4f2a8_0004f350:\n"
        "cmpb $0x22, %al\n" /* text_in */
        "je .Lf4f2a8_0004f306\n"
        "movl %edx, %ecx\n" /* max_tokens */
        "cmpb $0x5c, %al\n" /* line 861 | text_in */
        "jne .Lf4f2a8_0004f33e\n"
        "leal 1(%edx), %eax\n" /* max_tokens, text_in */
        "cmpb $0x22, 1(%edx)\n" /* max_tokens */
        "je .Lf4f2a8_0004f419\n"
        "movl %eax, %edx\n" /* text_in, max_tokens */
        "jmp .Lf4f2a8_0004f341\n"
        ".Lf4f2a8_0004f36b:\n"
        "addl $1, %ecx\n" /* line 829 */
        "jmp .Lf4f2a8_0004f2d0\n"
        ".Lf4f2a8_0004f373:\n"
        "leal 2(%edx), %ecx\n" /* line 882 | max_tokens */
        /* } scope */
        "addl $1, %esi\n" /* line 798 */
        /* { scope 1 */
        "cmpl $0x200, -0x14(%ebp)\n" /* line 811 | argc */
        "jne .Lf4f2a8_0004f2c7\n"
        "jmp .Lf4f2a8_0004f32c\n"
        ".Lf4f2a8_0004f388:\n"
        "movzbl 1(%ecx), %eax\n" /* line 835 | text_in */
        "cmpb $0x2f, %al\n" /* text_in */
        "je .Lf4f2a8_0004f333\n"
        "cmpb $0x2a, %al\n" /* line 839 | text_in */
        "je .Lf4f2a8_0004f39c\n"
        "jmp .Lf4f2a8_0004f3b5\n"
        ".Lf4f2a8_0004f396:\n"
        "movl %edx, %ecx\n" /* max_tokens */
        "movzbl 1(%edx), %eax\n" /* max_tokens, text_in */
        ".Lf4f2a8_0004f39c:\n"
        "leal 1(%ecx), %edx\n" /* line 842 | max_tokens */
        "testb %al, %al\n" /* line 841 | text_in */
        "je .Lf4f2a8_0004f333\n"
        "cmpb $0x2a, %al\n" /* text_in */
        "jne .Lf4f2a8_0004f396\n"
        "cmpb $0x2f, 2(%ecx)\n"
        "jne .Lf4f2a8_0004f396\n"
        "leal 2(%edx), %ecx\n" /* line 845 | max_tokens */
        "jmp .Lf4f2a8_0004f2d0\n"
        ".Lf4f2a8_0004f3b5:\n"
        "movl -0x14(%ebp), %edx\n" /* line 889 | argc, max_tokens */
        "movl %ebx, (%edi, %edx, 4)\n" /* textOut, argv */
        "addl $1, %edx\n" /* line 890 | max_tokens */
        "movl %edx, -0x14(%ebp)\n" /* max_tokens, argc */
        "movzbl (%ecx), %eax\n" /* line 896 | text_in */
        "cmpb $0x20, %al\n" /* text_in */
        "jg .Lf4f2a8_0004f3f8\n"
        ".Lf4f2a8_0004f3c8:\n"
        "movb $0, (%ebx)\n" /* line 914 | textOut */
        "addl $1, %ebx\n" /* textOut */
        "movzbl (%ecx), %eax\n" /* line 916 | text_in */
        "testb %al, %al\n" /* text_in */
        "je .Lf4f2a8_0004f333\n"
        "cmpb $0x20, %al\n" /* line 923 | text_in */
        "jg .Lf4f2a8_0004f320\n"
        "addl $1, %ecx\n" /* line 928 */
        "jmp .Lf4f2a8_0004f320\n"
        ".Lf4f2a8_0004f3e9:\n"
        "addl $1, %ecx\n" /* line 904 */
        ".Lf4f2a8_0004f3ec:\n"
        "movb %al, (%ebx)\n" /* line 911 | text_in, textOut */
        "addl $1, %ebx\n" /* textOut */
        "movzbl (%ecx), %eax\n" /* line 896 | text_in */
        "cmpb $0x20, %al\n" /* text_in */
        "jle .Lf4f2a8_0004f3c8\n"
        ".Lf4f2a8_0004f3f8:\n"
        "cmpb $0x22, %al\n" /* line 901 | text_in */
        "je .Lf4f2a8_0004f3c8\n"
        "cmpb $0x2f, %al\n" /* line 904 | text_in */
        "jne .Lf4f2a8_0004f3e9\n"
        "leal 1(%ecx), %edx\n" /* max_tokens */
        "movl %edx, -0x10(%ebp)\n" /* max_tokens */
        "movzbl 1(%ecx), %edx\n" /* max_tokens */
        "cmpb $0x2f, %dl\n" /* max_tokens */
        "je .Lf4f2a8_0004f3c8\n"
        "cmpb $0x2a, %dl\n" /* line 908 | max_tokens */
        "je .Lf4f2a8_0004f3c8\n"
        "movl -0x10(%ebp), %ecx\n" /* line 909 */
        "jmp .Lf4f2a8_0004f3ec\n"
        ".Lf4f2a8_0004f419:\n"
        "addl $2, %edx\n" /* line 861 | max_tokens */
        "movl %eax, %ecx\n" /* text_in */
        "jmp .Lf4f2a8_0004f341\n"
        ".Lf4f2a8_0004f423:\n"
        "cmpb $0, (%ecx)\n" /* line 932 */
        "je .Lf4f2a8_0004f333\n"
        "movl -0x14(%ebp), %eax\n" /* line 935 | argc, text_in */
        "movl %ebx, (%edi, %eax, 4)\n" /* textOut, argv */
        "addl $1, %eax\n" /* line 936 | text_in */
        "movl %eax, -0x14(%ebp)\n" /* text_in, argc */
        "movzbl (%ecx), %edx\n" /* line 937 | max_tokens */
        "testb %dl, %dl\n" /* max_tokens */
        "je .Lf4f2a8_0004f451\n"
        "movl %ecx, %eax\n" /* text_in */
        ".Lf4f2a8_0004f441:\n"
        "movb %dl, (%ebx)\n" /* line 938 | max_tokens, textOut */
        "addl $1, %ebx\n" /* textOut */
        "movzbl 1(%eax), %edx\n" /* line 937 | text_in, max_tokens */
        "addl $1, %eax\n" /* text_in */
        "testb %dl, %dl\n" /* max_tokens */
        "jne .Lf4f2a8_0004f441\n"
        ".Lf4f2a8_0004f451:\n"
        "movb $0, (%ebx)\n" /* line 940 | textOut */
        "jmp .Lf4f2a8_0004f333\n"
    );
}

/* line 955 */
__attribute__((naked))
void Cmd_TokenizeString2(const char *text_in, int max_tokens)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 955 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* text_in */
        "movl 0xc(%ebp), %edx\n" /* max_tokens */
        "movl $cmd_tokenized, (%esp)\n" /* line 959 */
        "movl $cmd_argv, %ecx\n"
        "calll Cmd_TokenizeStringInternal\n"
        "movl %eax, cmd_argc\n"
        "leave\n" /* line 960 */
        "retl\n"
    );
}

/* line 1035 */
__attribute__((naked))
void Cmd_RemoveCommand(const char *cmdName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1035 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* cmdName */
        /* { scope 1 */
        "movl cmd_functions, %ebx\n" /* line 1042 | cmd */
        "testl %ebx, %ebx\n" /* line 1043 | cmd */
        "je .Lf4f480_0004f4b6\n"
        "movl $cmd_functions, %edi\n" /* line 1046 | back */
        ".Lf4f480_0004f49b:\n"
        "movl 4(%ebx), %eax\n" /* line 1048 | cmd */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cmdName */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf4f480_0004f4be\n"
        "movl %ebx, %edi\n" /* line 1058 | cmd, back */
        "movl (%ebx), %ebx\n" /* line 1042 | cmd */
        "testl %ebx, %ebx\n" /* line 1043 | cmd */
        "jne .Lf4f480_0004f49b\n"
        /* } scope */
        ".Lf4f480_0004f4b6:\n"
        "addl $0x1c, %esp\n" /* line 1060 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f480_0004f4be:\n"
        "movl (%ebx), %eax\n" /* line 1050 | cmd */
        "movl %eax, (%edi)\n" /* back */
        "movl 4(%ebx), %eax\n" /* line 1051 | cmd */
        "testl %eax, %eax\n"
        "je .Lf4f480_0004f4d1\n"
        "movl %eax, (%esp)\n" /* line 1053 */
        "calll Z_FreeInternal\n"
        ".Lf4f480_0004f4d1:\n"
        "movl %ebx, 8(%ebp)\n" /* line 1055 | cmd, cmdName */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1060 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Z_FreeInternal\n" /* line 1055 */
    );
}

/* line 1087 */
__attribute__((naked))
void Cmd_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1087 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl cmd_functions, %ebx\n" /* line 1091 */
        "testl %ebx, %ebx\n"
        "je .Lf4f4e0_0004f515\n"
        ".Lf4f4e0_0004f4f1:\n"
        "movl (%ebx), %eax\n" /* line 1094 */
        "movl %eax, cmd_functions\n"
        "movl 4(%ebx), %eax\n" /* line 1096 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl %ebx, (%esp)\n" /* line 1097 */
        "calll Z_FreeInternal\n"
        "movl cmd_functions, %ebx\n" /* line 1091 */
        "testl %ebx, %ebx\n"
        "jne .Lf4f4e0_0004f4f1\n"
        ".Lf4f4e0_0004f515:\n"
        "addl $0x14, %esp\n" /* line 1110 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1113 */
__attribute__((naked))
void Cmd_ForEach(void (*callback)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1113 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* callback */
        /* { scope 1 */
        "movl cmd_functions, %ebx\n" /* line 1117 | cmd */
        "testl %ebx, %ebx\n" /* cmd */
        "je .Lf4f51c_0004f53f\n"
        ".Lf4f51c_0004f531:\n"
        "movl 4(%ebx), %eax\n" /* line 1118 | cmd */
        "movl %eax, (%esp)\n"
        "calll *%esi\n" /* callback */
        "movl (%ebx), %ebx\n" /* line 1117 | cmd */
        "testl %ebx, %ebx\n" /* cmd */
        "jne .Lf4f51c_0004f531\n"
        /* } scope */
        ".Lf4f51c_0004f53f:\n"
        "addl $0x10, %esp\n" /* line 1119 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 726 */
__attribute__((naked))
void Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 726 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* arg */
        "movl 0xc(%ebp), %ecx\n" /* buffer */
        "movl 0x10(%ebp), %edx\n" /* bufferLength */
        "cmpl cmd_argc, %eax\n" /* line 680 */
        "jge .Lf4f546_0004f570\n"
        "movl cmd_argv(, %eax, 4), %eax\n" /* line 685 */
        "movl %edx, 0x10(%ebp)\n" /* line 728 | bufferLength */
        "movl %eax, 0xc(%ebp)\n" /* buffer */
        "movl %ecx, 8(%ebp)\n" /* arg */
        "popl %ebp\n" /* line 729 */
        "jmp I_strncpyz\n" /* line 728 */
        ".Lf4f546_0004f570:\n"
        "movl $0x2157b8, %eax\n" /* line 680 */
        "movl %edx, 0x10(%ebp)\n" /* line 728 | bufferLength */
        "movl %eax, 0xc(%ebp)\n" /* buffer */
        "movl %ecx, 8(%ebp)\n" /* arg */
        "popl %ebp\n" /* line 729 */
        "jmp I_strncpyz\n" /* line 728 */
    );
}

/* line 122 */
__attribute__((naked))
void Cmd_Wait_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpl $2, cmd_argc\n" /* line 124 */
        "je .Lf4f584_0004f59f\n"
        "movl $1, cmd_wait\n" /* line 130 */
        "leave\n" /* line 132 */
        "retl\n"
        ".Lf4f584_0004f59f:\n"
        "movl 0x483084, %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, cmd_wait\n"
        "leave\n" /* line 132 */
        "retl\n"
    );
}

/* line 1250 */
__attribute__((naked))
void Cmd_List_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1250 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "cmpl $1, cmd_argc\n" /* line 1256 */
        "jle .Lf4f5b4_0004f62b\n"
        "movl 0x483084, %esi\n" /* line 685 */
        "movl cmd_functions, %ebx\n" /* line 1266 | cmd */
        "testl %ebx, %ebx\n" /* cmd */
        "je .Lf4f5b4_0004f637\n"
        ".Lf4f5b4_0004f5d6:\n"
        "testl %esi, %esi\n" /* line 1275 | match */
        "je .Lf4f5b4_0004f651\n"
        "xorl %edi, %edi\n" /* i */
        ".Lf4f5b4_0004f5dc:\n"
        "movl $0, 8(%esp)\n" /* line 1268 */
        "movl 4(%ebx), %eax\n" /* cmd */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* match */
        "calll Com_Filter\n"
        "testb %al, %al\n"
        "je .Lf4f5b4_0004f60d\n"
        "movl 4(%ebx), %eax\n" /* line 1271 | cmd */
        "movl %eax, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "addl $1, %edi\n" /* line 1272 | i */
        ".Lf4f5b4_0004f60d:\n"
        "movl (%ebx), %ebx\n" /* line 1266 | cmd */
        "testl %ebx, %ebx\n" /* cmd */
        "jne .Lf4f5b4_0004f5dc\n"
        ".Lf4f5b4_0004f613:\n"
        "movl %edi, 4(%esp)\n" /* line 1274 | i */
        "movl $0x218f4c, (%esp)\n" /* "%i commands
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1275 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f5b4_0004f62b:\n"
        "xorl %esi, %esi\n" /* line 1256 | match */
        "movl cmd_functions, %ebx\n" /* line 1266 | cmd */
        "testl %ebx, %ebx\n" /* cmd */
        "jne .Lf4f5b4_0004f5d6\n"
        ".Lf4f5b4_0004f637:\n"
        "xorl %edi, %edi\n" /* i */
        "movl %edi, 4(%esp)\n" /* line 1274 | i */
        "movl $0x218f4c, (%esp)\n" /* "%i commands
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1275 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f5b4_0004f651:\n"
        "xorl %edi, %edi\n" /* line 1266 | i */
        ".Lf4f5b4_0004f653:\n"
        "movl 4(%ebx), %eax\n" /* line 1271 | cmd */
        "movl %eax, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "addl $1, %edi\n" /* line 1272 | i */
        "movl (%ebx), %ebx\n" /* line 1266 | cmd */
        "testl %ebx, %ebx\n" /* cmd */
        "jne .Lf4f5b4_0004f653\n"
        "jmp .Lf4f5b4_0004f613\n"
    );
}

/* line 740 */
__attribute__((naked))
void SV_Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 740 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* arg */
        "movl 0xc(%ebp), %ecx\n" /* buffer */
        "movl 0x10(%ebp), %edx\n" /* bufferLength */
        "cmpl cmd_argc, %eax\n" /* line 708 */
        "jge .Lf4f672_0004f69c\n"
        "movl cmd_argv(, %eax, 4), %eax\n" /* line 713 */
        "movl %edx, 0x10(%ebp)\n" /* line 742 | bufferLength */
        "movl %eax, 0xc(%ebp)\n" /* buffer */
        "movl %ecx, 8(%ebp)\n" /* arg */
        "popl %ebp\n" /* line 743 */
        "jmp I_strncpyz\n" /* line 742 */
        ".Lf4f672_0004f69c:\n"
        "movl $0x2157b8, %eax\n" /* line 708 */
        "movl %edx, 0x10(%ebp)\n" /* line 742 | bufferLength */
        "movl %eax, 0xc(%ebp)\n" /* buffer */
        "movl %ecx, 8(%ebp)\n" /* arg */
        "popl %ebp\n" /* line 743 */
        "jmp I_strncpyz\n" /* line 742 */
    );
}

/* line 1151 */
__attribute__((naked))
void Cmd_ExecuteString(const char *text)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1151 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* text */
        /* { scope 1 */
        "movl $cmd_tokenized, (%esp)\n" /* line 959 */
        "movl $cmd_argv, %ecx\n"
        "xorl %edx, %edx\n"
        "movl %edi, %eax\n"
        "calll Cmd_TokenizeStringInternal\n"
        "movl %eax, cmd_argc\n"
        "testl %eax, %eax\n" /* line 1164 */
        "je .Lf4f6b0_0004f749\n"
        "movl cmd_functions, %ebx\n" /* line 1170 */
        "testl %ebx, %ebx\n"
        "je .Lf4f6b0_0004f709\n"
        "movl $cmd_functions, %esi\n" /* prev */
        ".Lf4f6b0_0004f6e9:\n"
        "movl 4(%ebx), %eax\n" /* line 1173 */
        "movl %eax, 4(%esp)\n"
        "movl cmd_argv, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf4f6b0_0004f751\n"
        "movl %ebx, %esi\n" /* line 1170 | prev */
        "movl (%ebx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf4f6b0_0004f6e9\n"
        ".Lf4f6b0_0004f709:\n"
        "calll Dvar_Command\n" /* line 1207 */
        "testl %eax, %eax\n"
        "jne .Lf4f6b0_0004f749\n"
        "movl 0x195ecb4, %eax\n" /* line 1214 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf4f6b0_0004f772\n"
        ".Lf4f6b0_0004f720:\n"
        "movl 0x195ecbc, %eax\n" /* line 1219 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf4f6b0_0004f731\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf4f6b0_0004f740\n"
        ".Lf4f6b0_0004f731:\n"
        "movl %edi, 8(%ebp)\n" /* line 1225 | text */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1227 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CL_ForwardCommandToServer\n" /* line 1225 */
        ".Lf4f6b0_0004f740:\n"
        "calll SV_GameCommand\n" /* line 1219 */
        "testl %eax, %eax\n"
        "je .Lf4f6b0_0004f731\n"
        /* } scope */
        ".Lf4f6b0_0004f749:\n"
        "addl $0x1c, %esp\n" /* line 1227 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f6b0_0004f751:\n"
        "movl (%ebx), %eax\n" /* line 1177 */
        "movl %eax, (%esi)\n" /* prev */
        "movl cmd_functions, %eax\n" /* line 1178 */
        "movl %eax, (%ebx)\n"
        "movl %ebx, cmd_functions\n" /* line 1179 */
        "movl 0x10(%ebx), %ecx\n" /* line 1182 */
        "testl %ecx, %ecx\n"
        "je .Lf4f6b0_0004f709\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1227 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 1199 */
        ".Lf4f6b0_0004f772:\n"
        "calll CL_GameCommand\n" /* line 1214 */
        "testl %eax, %eax\n"
        "je .Lf4f6b0_0004f720\n"
        "jmp .Lf4f6b0_0004f749\n"
    );
}

/* line 1238 */
__attribute__((naked))
void SV_Cmd_ExecuteString(const char *text)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1238 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1241 */
        "jmp Cmd_ExecuteString\n" /* line 1240 */
    );
}

/* line 429 */
static __attribute__((naked))
void Cbuf_ExecuteInternal(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 429 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x101c, %esp\n"
        /* { scope 1 */
        "movl cmd_text, %edx\n" /* line 436 */
        "movl 8(%edx), %ebx\n" /* i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf4f788_0004f809\n"
        ".Lf4f788_0004f7a1:\n"
        "movl cmd_wait, %eax\n" /* line 438 */
        "testl %eax, %eax\n"
        "jne .Lf4f788_0004f87f\n"
        "movl (%edx), %edi\n" /* line 447 | text */
        "testl %ebx, %ebx\n" /* line 450 | i */
        "jg .Lf4f788_0004f83a\n"
        "xorl %esi, %esi\n"
        "xorl %eax, %eax\n"
        ".Lf4f788_0004f7bc:\n"
        "movl %eax, 8(%esp)\n" /* line 465 */
        "movl %edi, 4(%esp)\n" /* text */
        "leal -0x1018(%ebp), %eax\n" /* line */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movb $0, -0x1018(%ebp, %esi)\n" /* line 466 */
        "movl cmd_text, %ecx\n" /* line 472 */
        "movl 8(%ecx), %edx\n"
        "cmpl %edx, %esi\n"
        "jne .Lf4f788_0004f814\n"
        "movl $0, 8(%ecx)\n" /* line 474 */
        ".Lf4f788_0004f7ee:\n"
        "leal -0x1018(%ebp), %eax\n" /* line 485 | line */
        "movl %eax, (%esp)\n"
        "calll Cmd_ExecuteString\n"
        "movl cmd_text, %edx\n" /* line 436 */
        "movl 8(%edx), %ebx\n" /* i */
        "testl %ebx, %ebx\n" /* i */
        "jne .Lf4f788_0004f7a1\n"
        /* } scope */
        ".Lf4f788_0004f809:\n"
        "addl $0x101c, %esp\n" /* line 487 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f788_0004f814:\n"
        "leal 1(%esi), %eax\n" /* line 478 */
        "subl %eax, %edx\n" /* line 479 */
        "movl %edx, 8(%ecx)\n"
        "movl cmd_text, %edx\n" /* line 480 */
        "movl 8(%edx), %edx\n"
        "movl %edx, 8(%esp)\n"
        "leal (%edi, %eax), %eax\n" /* text */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* text */
        "calll memmove\n"
        "jmp .Lf4f788_0004f7ee\n"
        ".Lf4f788_0004f83a:\n"
        "xorl %ecx, %ecx\n" /* line 450 */
        "xorl %esi, %esi\n"
        ".Lf4f788_0004f83e:\n"
        "movzbl (%edi, %esi), %edx\n" /* line 452 | text */
        "leal 1(%ecx), %eax\n" /* line 453 */
        "cmpb $0x22, %dl\n"
        "cmovel %eax, %ecx\n"
        "testb $1, %cl\n" /* line 454 */
        "jne .Lf4f788_0004f855\n"
        "cmpb $0x3b, %dl\n"
        "je .Lf4f788_0004f868\n"
        ".Lf4f788_0004f855:\n"
        "cmpb $0xa, %dl\n" /* line 456 */
        "je .Lf4f788_0004f868\n"
        "cmpb $0xd, %dl\n"
        "je .Lf4f788_0004f868\n"
        "addl $1, %esi\n" /* line 450 */
        "cmpl %esi, %ebx\n" /* i */
        "jne .Lf4f788_0004f83e\n"
        "movl %ebx, %esi\n" /* i */
        ".Lf4f788_0004f868:\n"
        "cmpl $0xffe, %esi\n" /* line 460 */
        "jle .Lf4f788_0004f892\n"
        "movl $0xfff, %esi\n"
        "movl $0xfff, %eax\n"
        "jmp .Lf4f788_0004f7bc\n"
        ".Lf4f788_0004f87f:\n"
        "subl $1, %eax\n" /* line 442 */
        "movl %eax, cmd_wait\n"
        /* } scope */
        "addl $0x101c, %esp\n" /* line 487 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f788_0004f892:\n"
        "movl %esi, %eax\n" /* line 460 */
        "jmp .Lf4f788_0004f7bc\n"
    );
}

/* line 495 */
__attribute__((naked))
void Cbuf_Execute(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 495 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 502 */
        "jmp Cbuf_ExecuteInternal\n" /* line 497 */
    );
}

/* line 985 */
__attribute__((naked))
void Cmd_TokenizeString(const char *text_in)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 985 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* text_in */
        "movl $cmd_tokenized, (%esp)\n" /* line 959 */
        "movl $cmd_argv, %ecx\n"
        "xorl %edx, %edx\n"
        "calll Cmd_TokenizeStringInternal\n"
        "movl %eax, cmd_argc\n"
        "leave\n" /* line 988 */
        "retl\n"
    );
}

/* line 991 */
__attribute__((naked))
void SV_Cmd_TokenizeString(const char *text_in)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 991 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* text_in */
        "movl $cmd_tokenized, (%esp)\n" /* line 980 */
        "movl $cmd_argv, %ecx\n"
        "xorl %edx, %edx\n"
        "calll Cmd_TokenizeStringInternal\n"
        "movl %eax, cmd_argc\n"
        "leave\n" /* line 994 */
        "retl\n"
    );
}

/* line 1010 */
__attribute__((naked))
void Cmd_AddCommand(const char *cmdName, xcommand_t function)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1010 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* cmdName */
        "movl 0xc(%ebp), %edi\n" /* function */
        /* { scope 1 */
        "movl cmd_functions, %ebx\n" /* line 1001 */
        "testl %ebx, %ebx\n"
        "je .Lf4f8ec_0004f91e\n"
        ".Lf4f8ec_0004f905:\n"
        "movl 4(%ebx), %eax\n" /* line 1003 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf4f8ec_0004f94f\n"
        "movl (%ebx), %ebx\n" /* line 1001 */
        "testl %ebx, %ebx\n"
        "jne .Lf4f8ec_0004f905\n"
        ".Lf4f8ec_0004f91e:\n"
        "movl $0x14, (%esp)\n" /* line 1027 */
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n" /* cmd */
        "movl %esi, (%esp)\n" /* line 1028 | cmdName */
        "calll CopyStringInternal\n"
        "movl %eax, 4(%ebx)\n" /* cmd */
        "movl %edi, 0x10(%ebx)\n" /* line 1029 | function, cmd */
        "movl cmd_functions, %eax\n" /* line 1030 */
        "movl %eax, (%ebx)\n" /* cmd */
        "movl %ebx, cmd_functions\n" /* line 1031 | cmd */
        /* } scope */
        ".Lf4f8ec_0004f947:\n"
        "addl $0x1c, %esp\n" /* line 1032 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f8ec_0004f94f:\n"
        "testl %edi, %edi\n" /* line 1021 | function */
        "je .Lf4f8ec_0004f947\n"
        "movl %esi, 0xc(%ebp)\n" /* line 1022 | cmdName, function */
        "movl $0x218f5c, 8(%ebp)\n" /* cmdName */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1032 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 1022 */
    );
}

/* line 1063 */
__attribute__((naked))
void Cmd_SetAutoComplete(const char *cmdName, const char *dir, const char *ext)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1063 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* cmdName */
        /* { scope 1 */
        "movl cmd_functions, %ebx\n" /* line 1001 */
        "testl %ebx, %ebx\n"
        "je .Lf4f96a_0004f998\n"
        ".Lf4f96a_0004f97f:\n"
        "movl 4(%ebx), %eax\n" /* line 1003 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf4f96a_0004f99a\n"
        "movl (%ebx), %ebx\n" /* line 1001 */
        "testl %ebx, %ebx\n"
        "jne .Lf4f96a_0004f97f\n"
        ".Lf4f96a_0004f998:\n"
        "xorl %ebx, %ebx\n"
        ".Lf4f96a_0004f99a:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1077 | dir */
        "movl %eax, 8(%ebx)\n" /* cmd */
        "movl 0x10(%ebp), %eax\n" /* line 1078 | ext */
        "movl %eax, 0xc(%ebx)\n" /* cmd */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1079 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1124 */
__attribute__((naked))
const char * * Cmd_GetAutoCompleteFileList(const char *cmdName, int *fileCount, int allocTrackType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1124 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* cmdName */
        "movl 0xc(%ebp), %edi\n" /* fileCount */
        /* { scope 1 */
        "movl $0, (%edi)\n" /* line 1131 | fileCount */
        "movl cmd_functions, %ebx\n" /* line 1001 */
        "testl %ebx, %ebx\n"
        "je .Lf4f9ae_0004f9e6\n"
        ".Lf4f9ae_0004f9cd:\n"
        "movl 4(%ebx), %eax\n" /* line 1003 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf4f9ae_0004f9e8\n"
        "movl (%ebx), %ebx\n" /* line 1001 */
        "testl %ebx, %ebx\n"
        "jne .Lf4f9ae_0004f9cd\n"
        ".Lf4f9ae_0004f9e6:\n"
        "xorl %ebx, %ebx\n"
        ".Lf4f9ae_0004f9e8:\n"
        "movl 8(%ebx), %eax\n" /* line 1135 | cmd */
        "testl %eax, %eax\n"
        "jne .Lf4f9ae_0004f9f9\n"
        ".Lf4f9ae_0004f9ef:\n"
        "xorl %eax, %eax\n" /* line 1138 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1139 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4f9ae_0004f9f9:\n"
        "movl 0xc(%ebx), %edx\n" /* line 1135 | cmd */
        "testl %edx, %edx\n"
        "je .Lf4f9ae_0004f9ef\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1138 | allocTrackType */
        "movl %ecx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n" /* fileCount */
        "movl $0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_ListFiles\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1139 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 782 */
__attribute__((naked))
void Cmd_ArgsBuffer(char *buffer, int bufferLength)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 782 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movb $0, cmd_args1\n" /* line 760 */
        "cmpl $1, cmd_argc\n" /* line 761 */
        "jg .Lf4fa28_0004fa61\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 784 | bufferLength */
        "movl %eax, 8(%esp)\n"
        "movl $cmd_args1, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x10, %esp\n" /* line 785 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4fa28_0004fa61:\n"
        "movl $1, %ebx\n" /* line 761 | i */
        "movl $cmd_argv, %esi\n"
        ".Lf4fa28_0004fa6b:\n"
        "movl 4(%esi), %eax\n" /* line 763 */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl $cmd_args1, (%esp)\n"
        "calll I_strncat\n"
        "movl cmd_argc, %eax\n" /* line 764 */
        "subl $1, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "je .Lf4fa28_0004faae\n"
        "movl $0x217914, 8(%esp)\n" /* line 766 */
        "movl $0x400, 4(%esp)\n"
        "movl $cmd_args1, (%esp)\n"
        "calll I_strncat\n"
        ".Lf4fa28_0004faae:\n"
        "addl $1, %ebx\n" /* line 761 | i */
        "addl $4, %esi\n"
        "cmpl cmd_argc, %ebx\n" /* i */
        "jl .Lf4fa28_0004fa6b\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 784 | bufferLength */
        "movl %eax, 8(%esp)\n"
        "movl $cmd_args1, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x10, %esp\n" /* line 785 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 231 */
__attribute__((naked))
void Cbuf_ExecuteText(int exec_when, const char *text)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 231 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* exec_when */
        "movl 0xc(%ebp), %esi\n" /* text */
        "cmpl $1, %eax\n" /* line 233 */
        "je .Lf4fade_0004fb32\n"
        "cmpl $2, %eax\n"
        "je .Lf4fade_0004fbb5\n"
        "testl %eax, %eax\n"
        "jne .Lf4fade_0004fb18\n"
        "testl %esi, %esi\n" /* line 236 | text */
        "je .Lf4fade_0004fb0c\n"
        "cmpb $0, (%esi)\n" /* text */
        "jne .Lf4fade_0004fc0c\n"
        ".Lf4fade_0004fb0c:\n"
        "addl $0x2c, %esp\n" /* line 254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Cbuf_ExecuteInternal\n" /* line 497 */
        ".Lf4fade_0004fb18:\n"
        "movl $0x218f80, 0xc(%ebp)\n" /* line 252 | text */
        "movl $0, 8(%ebp)\n" /* exec_when */
        "addl $0x2c, %esp\n" /* line 254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Com_Error\n" /* line 252 */
        /* { scope 1 */
        ".Lf4fade_0004fb32:\n"
        "cld\n" /* line 203 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n" /* length */
        "notl %ebx\n" /* length */
        "movl cmd_text, %edx\n" /* line 204 */
        "movl 8(%edx), %ecx\n"
        "leal (%ebx, %ecx), %eax\n" /* length */
        "cmpl 4(%edx), %eax\n"
        "jg .Lf4fade_0004fc1b\n"
        "subl $1, %ecx\n" /* line 211 */
        "movl %ecx, -0x1c(%ebp)\n"
        "js .Lf4fade_0004fb84\n"
        "leal (%ebx, %ecx), %edi\n" /* length */
        "jmp .Lf4fade_0004fb6a\n"
        ".Lf4fade_0004fb64:\n"
        "movl cmd_text, %edx\n"
        ".Lf4fade_0004fb6a:\n"
        "movl (%edx), %edx\n" /* line 213 */
        "movzbl (%ecx, %edx), %eax\n"
        "movb %al, (%edi, %edx)\n"
        "subl $1, %ecx\n" /* line 211 */
        "subl $1, %edi\n"
        "cmpl $-1, %ecx\n"
        "jne .Lf4fade_0004fb64\n"
        "movl cmd_text, %edx\n"
        ".Lf4fade_0004fb84:\n"
        "movl (%edx), %edx\n" /* line 217 */
        "leal -1(%ebx), %eax\n" /* length */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl cmd_text, %eax\n" /* line 220 */
        "movl (%eax), %eax\n"
        "movb $0xa, -1(%eax, %ebx)\n"
        "movl cmd_text, %eax\n" /* line 222 */
        "addl %ebx, 8(%eax)\n" /* length */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4fade_0004fbb5:\n"
        "cld\n" /* line 178 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n" /* length */
        "movl cmd_text, %edx\n" /* line 180 */
        "movl 8(%edx), %ecx\n"
        "leal (%ebx, %ecx), %eax\n" /* length */
        "cmpl 4(%edx), %eax\n"
        "jl .Lf4fade_0004fbea\n"
        "movl $0x218f18, 8(%ebp)\n" /* line 182 | exec_when */
        /* } scope */
        ".Lf4fade_0004fbde:\n"
        "addl $0x2c, %esp\n" /* line 254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 182 */
        ".Lf4fade_0004fbea:\n"
        "addl (%edx), %ecx\n" /* line 185 */
        "movl %ebx, 8(%esp)\n" /* length */
        "movl %esi, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl cmd_text, %eax\n" /* line 186 */
        "addl %ebx, 8(%eax)\n" /* length */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf4fade_0004fc0c:\n"
        "movl %esi, 8(%ebp)\n" /* line 238 | text, exec_when */
        "addl $0x2c, %esp\n" /* line 254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Cmd_ExecuteString\n" /* line 238 */
        /* { scope 1 */
        ".Lf4fade_0004fc1b:\n"
        "movl $0x218f30, 8(%ebp)\n" /* line 206 | exec_when */
        "jmp .Lf4fade_0004fbde\n"
    );
}

/* line 586 */
__attribute__((naked))
void Cmd_Vstr_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 586 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1: text */
        "cmpl $2, cmd_argc\n" /* line 591 */
        "je .Lf4fc24_0004fc4a\n"
        "movl $0x218fa4, (%esp)\n" /* line 593 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf4fc24_0004fc42:\n"
        "addl $0x2c, %esp\n" /* line 611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: text */
        ".Lf4fc24_0004fc4a:\n"
        "movl 0x483084, %edi\n" /* line 597 | dvarName */
        "movl %edi, (%esp)\n" /* line 598 | dvarName */
        "calll Dvar_FindVar\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 599 */
        "je .Lf4fc24_0004fd1d\n"
        "movzbl 6(%eax), %eax\n" /* line 604 */
        "subb $6, %al\n"
        "cmpb $1, %al\n"
        "jbe .Lf4fc24_0004fc86\n"
        "movl (%edx), %eax\n" /* line 606 */
        "movl %eax, 4(%esp)\n"
        "movl $0x218fec, (%esp)\n" /* "%s is not a string-based dvar
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: text */
        ".Lf4fc24_0004fc86:\n"
        "movl 8(%edx), %eax\n" /* line 610 */
        "movl %eax, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll va\n"
        "movl %eax, -0x1c(%ebp)\n" /* text */
        /* { scope 2 */
        /* { scope 3 */
        "cld\n" /* line 203 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x1c(%ebp), %edi\n" /* text */
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "movl cmd_text, %edx\n" /* line 204 */
        "movl 8(%edx), %ecx\n"
        "leal (%ebx, %ecx), %eax\n"
        "cmpl 4(%edx), %eax\n"
        "jg .Lf4fc24_0004fd32\n"
        "movl %ecx, %esi\n" /* line 211 */
        "subl $1, %esi\n"
        "js .Lf4fc24_0004fcec\n"
        "leal (%ebx, %esi), %edi\n"
        "movl %esi, %ecx\n"
        "jmp .Lf4fc24_0004fcd2\n"
        ".Lf4fc24_0004fccc:\n"
        "movl cmd_text, %edx\n"
        ".Lf4fc24_0004fcd2:\n"
        "movl (%edx), %edx\n" /* line 213 */
        "movzbl (%ecx, %edx), %eax\n"
        "movb %al, (%edx, %edi)\n"
        "subl $1, %ecx\n" /* line 211 */
        "subl $1, %edi\n"
        "cmpl $-1, %ecx\n"
        "jne .Lf4fc24_0004fccc\n"
        "movl cmd_text, %edx\n"
        ".Lf4fc24_0004fcec:\n"
        "movl (%edx), %edx\n" /* line 217 */
        "leal -1(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* text */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl cmd_text, %eax\n" /* line 220 */
        "movl (%eax), %eax\n"
        "movb $0xa, -1(%eax, %ebx)\n"
        "movl cmd_text, %eax\n" /* line 222 */
        "addl %ebx, 8(%eax)\n"
        "jmp .Lf4fc24_0004fc42\n"
        /* } scope */
        /* } scope */
        ".Lf4fc24_0004fd1d:\n"
        "movl %edi, 4(%esp)\n" /* line 601 | dvarName */
        "movl $0x218fd8, (%esp)\n" /* "%s doesn't exist
" */
        "calll Com_Printf\n"
        "jmp .Lf4fc24_0004fc42\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf4fc24_0004fd32:\n"
        "movl $0x218f30, (%esp)\n" /* line 206 */
        "calll Com_Printf\n"
        "jmp .Lf4fc24_0004fc42\n"
    );
}

/* line 549 */
static __attribute__((naked))
void Cmd_Exec_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 549 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1: text */
        "cmpl $2, cmd_argc\n" /* line 553 */
        "je .Lf4fd44_0004fd6a\n"
        "movl $0x21900c, (%esp)\n" /* line 555 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf4fd44_0004fd62:\n"
        "addl $0x7c, %esp\n" /* line 576 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: text */
        ".Lf4fd44_0004fd6a:\n"
        "movl $0x40, 8(%esp)\n" /* line 559 */
        "movl 0x483084, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x5c(%ebp), %ebx\n" /* filename */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x216330, 8(%esp)\n" /* line 560 */
        "movl $0x40, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_DefaultExtension\n"
        /* { scope 2: text */
        "leal -0x1c(%ebp), %eax\n" /* line 522 | text */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_ReadFile\n"
        "movl -0x1c(%ebp), %edx\n" /* line 523 | text */
        "testl %edx, %edx\n"
        "je .Lf4fd44_0004fe6b\n"
        "movl %ebx, 4(%esp)\n" /* line 526 */
        "movl $0x219038, (%esp)\n" /* "execing %s
" */
        "calll Com_Printf\n"
        "movl -0x1c(%ebp), %eax\n" /* text */
        "movl %eax, -0x6c(%ebp)\n" /* text */
        /* { scope 3 */
        /* { scope 4 */
        "cld\n" /* line 203 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x6c(%ebp), %edi\n" /* text */
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "movl cmd_text, %edx\n" /* line 204 */
        "movl 8(%edx), %ecx\n"
        "leal (%ebx, %ecx), %eax\n"
        "cmpl 4(%edx), %eax\n"
        "jg .Lf4fd44_0004fe5d\n"
        "movl %ecx, %esi\n" /* line 211 */
        "subl $1, %esi\n"
        "js .Lf4fd44_0004fe1e\n"
        "leal (%ebx, %esi), %edi\n"
        "movl %esi, %ecx\n"
        "jmp .Lf4fd44_0004fe04\n"
        ".Lf4fd44_0004fdfe:\n"
        "movl cmd_text, %edx\n"
        ".Lf4fd44_0004fe04:\n"
        "movl (%edx), %edx\n" /* line 213 */
        "movzbl (%ecx, %edx), %eax\n"
        "movb %al, (%edi, %edx)\n"
        "subl $1, %ecx\n" /* line 211 */
        "subl $1, %edi\n"
        "cmpl $-1, %ecx\n"
        "jne .Lf4fd44_0004fdfe\n"
        "movl cmd_text, %edx\n"
        ".Lf4fd44_0004fe1e:\n"
        "movl (%edx), %edx\n" /* line 217 */
        "leal -1(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x6c(%ebp), %eax\n" /* text */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl cmd_text, %eax\n" /* line 220 */
        "movl (%eax), %eax\n"
        "movb $0xa, -1(%eax, %ebx)\n"
        "movl cmd_text, %eax\n" /* line 222 */
        "addl %ebx, 8(%eax)\n"
        /* } scope */
        /* } scope */
        ".Lf4fd44_0004fe4a:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 528 | text */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 576 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: text */
        /* { scope 2: text */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf4fd44_0004fe5d:\n"
        "movl $0x218f30, (%esp)\n" /* line 206 */
        "calll Com_Printf\n"
        "jmp .Lf4fd44_0004fe4a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf4fd44_0004fe6b:\n"
        "cmpl $1, cmd_argc\n" /* line 680 */
        "jle .Lf4fd44_0004fe8e\n"
        "movl 0x483084, %eax\n" /* line 685 */
        ".Lf4fd44_0004fe79:\n"
        "movl %eax, 4(%esp)\n" /* line 575 */
        "movl $0x219044, (%esp)\n" /* "couldn't exec %s
" */
        "calll Com_Printf\n"
        "jmp .Lf4fd44_0004fd62\n"
        ".Lf4fd44_0004fe8e:\n"
        "movl $0x2157b8, %eax\n" /* line 680 */
        "jmp .Lf4fd44_0004fe79\n"
    );
}

/* line 1285 */
__attribute__((naked))
void Cmd_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1285 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl cmd_functions, %eax\n" /* line 1001 */
        "movl %eax, -0x1c(%ebp)\n" /* cmd */
        "testl %eax, %eax\n"
        "je .Lf4fe96_0004fee7\n"
        "cld\n"
        ".Lf4fe96_0004feac:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1003 | cmd */
        "movl 4(%edx), %edx\n"
        "movl $8, %ebx\n"
        "movl $0x219058, %esi\n" /* "cmdlist" */
        "movl %edx, %edi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf4fe96_0004fed3\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf4fe96_0004fed3:\n"
        "testl %eax, %eax\n"
        "je .Lf4fe96_0005007e\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1001 | cmd */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* cmd */
        "testl %ecx, %ecx\n"
        "jne .Lf4fe96_0004feac\n"
        ".Lf4fe96_0004fee7:\n"
        "movl $0x14, (%esp)\n" /* line 1027 */
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl $0x219058, (%esp)\n" /* line 1028 */
        "calll CopyStringInternal\n"
        "movl %eax, 4(%ebx)\n"
        "movl $Cmd_List_f, 0x10(%ebx)\n" /* line 1029 */
        "movl cmd_functions, %eax\n" /* line 1030 */
        "movl %eax, (%ebx)\n"
        "movl %ebx, cmd_functions\n" /* line 1031 */
        "movl %ebx, %edi\n"
        /* } scope */
        /* { scope 1 */
        ".Lf4fe96_0004ff1a:\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 1001 | cmd */
        "testl %edi, %edi\n"
        "je .Lf4fe96_0004ff5d\n"
        "cld\n"
        ".Lf4fe96_0004ff22:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1003 | cmd */
        "movl 4(%eax), %eax\n"
        "movl $5, %ebx\n"
        "movl $0x219060, %esi\n" /* "exec" */
        "movl %eax, %edi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf4fe96_0004ff49\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf4fe96_0004ff49:\n"
        "testl %eax, %eax\n"
        "je .Lf4fe96_000500d8\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1001 | cmd */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* cmd */
        "testl %ecx, %ecx\n"
        "jne .Lf4fe96_0004ff22\n"
        ".Lf4fe96_0004ff5d:\n"
        "movl $0x14, (%esp)\n" /* line 1027 */
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl $0x219060, (%esp)\n" /* line 1028 */
        "calll CopyStringInternal\n"
        "movl %eax, 4(%ebx)\n"
        "movl $Cmd_Exec_f, 0x10(%ebx)\n" /* line 1029 */
        "movl cmd_functions, %eax\n" /* line 1030 */
        "movl %eax, (%ebx)\n"
        "movl %ebx, cmd_functions\n" /* line 1031 */
        "movl %ebx, %edi\n"
        /* } scope */
        /* { scope 1 */
        ".Lf4fe96_0004ff90:\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 1001 | cmd */
        "testl %edi, %edi\n"
        "je .Lf4fe96_0004ffd3\n"
        "cld\n"
        ".Lf4fe96_0004ff98:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1003 | cmd */
        "movl 4(%eax), %eax\n"
        "movl $5, %ebx\n"
        "movl $0x219068, %esi\n" /* "vstr" */
        "movl %eax, %edi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf4fe96_0004ffbf\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf4fe96_0004ffbf:\n"
        "testl %eax, %eax\n"
        "je .Lf4fe96_000500b9\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1001 | cmd */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* cmd */
        "testl %ecx, %ecx\n"
        "jne .Lf4fe96_0004ff98\n"
        ".Lf4fe96_0004ffd3:\n"
        "movl $0x14, (%esp)\n" /* line 1027 */
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl $0x219068, (%esp)\n" /* line 1028 */
        "calll CopyStringInternal\n"
        "movl %eax, 4(%ebx)\n"
        "movl $Cmd_Vstr_f, 0x10(%ebx)\n" /* line 1029 */
        "movl cmd_functions, %eax\n" /* line 1030 */
        "movl %eax, (%ebx)\n"
        "movl %ebx, cmd_functions\n" /* line 1031 */
        "movl %ebx, %edi\n"
        /* } scope */
        /* { scope 1 */
        ".Lf4fe96_00050006:\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 1001 | cmd */
        "testl %edi, %edi\n"
        "je .Lf4fe96_00050045\n"
        "cld\n"
        ".Lf4fe96_0005000e:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1003 | cmd */
        "movl 4(%eax), %eax\n"
        "movl $5, %ebx\n"
        "movl $0x219070, %esi\n" /* "wait" */
        "movl %eax, %edi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf4fe96_00050035\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf4fe96_00050035:\n"
        "testl %eax, %eax\n"
        "je .Lf4fe96_0005009d\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1001 | cmd */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* cmd */
        "testl %ecx, %ecx\n"
        "jne .Lf4fe96_0005000e\n"
        ".Lf4fe96_00050045:\n"
        "movl $0x14, (%esp)\n" /* line 1027 */
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl $0x219070, (%esp)\n" /* line 1028 */
        "calll CopyStringInternal\n"
        "movl %eax, 4(%ebx)\n"
        "movl $Cmd_Wait_f, 0x10(%ebx)\n" /* line 1029 */
        "movl cmd_functions, %eax\n" /* line 1030 */
        "movl %eax, (%ebx)\n"
        "movl %ebx, cmd_functions\n" /* line 1031 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1291 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4fe96_0005007e:\n"
        "movl $0x219058, 4(%esp)\n" /* line 1022 */
        "movl $0x218f5c, (%esp)\n" /* "Cmd_AddCommand: %s already defined
" */
        "calll Com_Printf\n"
        "movl cmd_functions, %edi\n"
        "jmp .Lf4fe96_0004ff1a\n"
        /* } scope */
        /* { scope 1 */
        ".Lf4fe96_0005009d:\n"
        "movl $0x219070, 4(%esp)\n" /* "wait" */
        "movl $0x218f5c, (%esp)\n" /* "Cmd_AddCommand: %s already defined
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1291 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4fe96_000500b9:\n"
        "movl $0x219068, 4(%esp)\n" /* line 1022 */
        "movl $0x218f5c, (%esp)\n" /* "Cmd_AddCommand: %s already defined
" */
        "calll Com_Printf\n"
        "movl cmd_functions, %edi\n"
        "jmp .Lf4fe96_00050006\n"
        /* } scope */
        /* { scope 1 */
        ".Lf4fe96_000500d8:\n"
        "movl $0x219060, 4(%esp)\n" /* "exec" */
        "movl $0x218f5c, (%esp)\n" /* "Cmd_AddCommand: %s already defined
" */
        "calll Com_Printf\n"
        "movl cmd_functions, %edi\n"
        "jmp .Lf4fe96_0004ff90\n"
    );
}

