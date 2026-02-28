/* Converted to C from ASM: mac_syscon.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_syscon.cpp */
/* Linux replacement: uses stdout for console output */

#include <stdio.h>
#include <string.h>
#include "common_types.h"
#include "imports.h"

extern Boolean gConsoleRunning; /* 0x0 */
static char sConsoleText[512]; /* 0x7f1920 */
static char sReturnedText[512]; /* 0x7f1720 */

extern void Sys_Print(const char *msg);
extern int MessageBoxA(void *hWnd, const char *lpText, const char *lpCaption, unsigned int uType);

void Sys_CreateConsole(HINSTANCE hInstance)
{
    sConsoleText[0] = '\0';
    sReturnedText[0] = '\0';
}

void Sys_DestroyConsole(void)
{
    /* No-op on Linux */
}

void Sys_ShowConsole(int visLevel, qboolean quitOnClose)
{
    gConsoleRunning = 0;

    switch (visLevel) {
    case 0:
        /* Hide console - no-op on Linux */
        break;
    case 1:
        /* Show console for error display */
        gConsoleRunning = 1;
        break;
    case 2:
        /* Minimize console - no-op on Linux */
        break;
    }
}

char *Sys_ConsoleInput(void)
{
    if (sConsoleText[0] == '\0')
        return NULL;

    strcpy(sReturnedText, sConsoleText);
    sConsoleText[0] = '\0';
    return sReturnedText;
}

void Conbuf_AppendText(const char *pMsg)
{
    if (!pMsg)
        return;

    fputs(pMsg, stdout);
    fflush(stdout);
}

void Sys_SetErrorText(const char *buf)
{
    fprintf(stderr, "ERROR: %s\n", buf);
}
