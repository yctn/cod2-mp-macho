/* Linux replacement for Mac CRT startup */
/* Replaces: /SourceCache/Csu/Csu-58/crt.c */
/* Replaces: Mac/Tools/MacGameEngine.cp + Mac/Main/GameMain.cp */

#include "common_types.h"
#include "imports.h"

extern int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

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

    return WinMain(0, 0, cmdLine, 0);
}
