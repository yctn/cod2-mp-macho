/* Linux replacement for Mac CRT startup */
/* Replaces: /SourceCache/Csu/Csu-58/crt.c */
/* Replaces: Mac/Tools/MacGameEngine.cp + Mac/Main/GameMain.cp */

#include "common_types.h"
#include "imports.h"
#include <signal.h>
#include <sys/ucontext.h>
#include <stdio.h>
#define __USE_GNU
#include <ucontext.h>

extern int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

static int null_call_count = 0;
static int segfault_count = 0;

static void null_call_handler(int sig, siginfo_t *info, void *ucontext)
{
    ucontext_t *ctx = (ucontext_t *)ucontext;
    unsigned int eip = ctx->uc_mcontext.gregs[14]; /* REG_EIP = 14 on i386 */

    if (eip == 0) {
        /* Call to unresolved function (address 0). */
        unsigned int *esp = (unsigned int *)(unsigned long)ctx->uc_mcontext.gregs[7];
        unsigned int retaddr = *esp;
        null_call_count++;
        if (null_call_count <= 50) {
            fprintf(stderr, "NULL_CALL #%d from 0x%08x\n", null_call_count, retaddr);
        }
        ctx->uc_mcontext.gregs[7] = (unsigned int)(unsigned long)(esp + 1);
        ctx->uc_mcontext.gregs[14] = retaddr;
        ctx->uc_mcontext.gregs[11] = 0; /* EAX = 0 */
        return;
    }

    segfault_count++;
    if (segfault_count > 50000) {
        fprintf(stderr, "Too many segfaults (%d), aborting at EIP=0x%08x\n", segfault_count, eip);
        signal(SIGSEGV, SIG_DFL);
        raise(SIGSEGV);
        return;
    }

    /* Try to return from faulting function */
    unsigned int ebp = ctx->uc_mcontext.gregs[6]; /* REG_EBP = 6 */
    if (ebp > 0x08000000 && ebp < 0xfffff000) {
        unsigned int *frame = (unsigned int *)(unsigned long)ebp;
        unsigned int saved_ebp = frame[0];
        unsigned int ret_addr = frame[1];
        if (ret_addr > 0x08000000 && ret_addr < 0x09000000) {
            if (segfault_count <= 50)
                fprintf(stderr, "SEGFAULT #%d at EIP=0x%08x, returning to 0x%08x\n", segfault_count, eip, ret_addr);
            ctx->uc_mcontext.gregs[6] = saved_ebp;
            ctx->uc_mcontext.gregs[7] = (unsigned int)(unsigned long)(frame + 2);
            ctx->uc_mcontext.gregs[14] = ret_addr;
            ctx->uc_mcontext.gregs[11] = 0;
            return;
        }
    }

    fprintf(stderr, "SEGFAULT at 0x%08x, cannot recover (EBP=0x%08x)\n", eip, ebp);
    signal(SIGSEGV, SIG_DFL);
    raise(SIGSEGV);
}

static void install_null_call_handler(void)
{
    struct sigaction sa;
    sa.sa_sigaction = null_call_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGSEGV, &sa, NULL);
}

int main(int argc, char **argv)
{
    char cmdLine[4096];
    int i;
    int offset;

    /* Build command line string from argv (skip argv[0]) */
    cmdLine[0] = '\0';
    offset = 0;
    for (i = 1; i < argc; i++) {
        int len = strlen(argv[i]);
        if (offset + len + 2 >= (int)sizeof(cmdLine))
            break;
        if (offset > 0)
            cmdLine[offset++] = ' ';
        memcpy(cmdLine + offset, argv[i], len);
        offset += len;
    }
    cmdLine[offset] = '\0';

    install_null_call_handler();

    /* Fix up data pointers that weren't resolved at link time */
    {
        extern unsigned char legacyHacks[32];
        extern unsigned char legacyHacksArray[1792];
        *(void **)legacyHacks = legacyHacksArray;

        /* cmd_text pointer → cmd_texts[0] */
        extern void *cmd_text;
        extern char cmd_texts[];
        cmd_text = cmd_texts;
    }

    return WinMain(0, 0, cmdLine, 0);
}
