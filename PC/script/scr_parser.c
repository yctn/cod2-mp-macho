/* ASM dump from: scr_parser.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_parser.cpp */

#include "common_types.h"
#include "imports.h"

extern struct scrParserPub_t scrParserPub; /* 0x0 */
extern struct scrParserGlob_t scrParserGlob; /* 0x0 */

extern void * Z_MallocInternal(int size);
extern void Z_FreeInternal(void *ptr);

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
void Scr_InitOpcodeLookup(void) {
    if (!((struct scrVarPub_t *)imp_scrVarPub)->developer)
        return;

    *(int *)((byte *)&scrParserGlob + 44) = -1;
    *(int *)((byte *)&scrParserGlob + 4) = 0x10000;
    *(int *)((byte *)&scrParserGlob + 8) = 0;
    *(void **)&scrParserGlob = Z_MallocInternal(0x140000);
    memset(*(void **)&scrParserGlob, 0, *(int *)((byte *)&scrParserGlob + 4) * 20);
    *(int *)((byte *)&scrParserGlob + 16) = 0x10000;
    *(int *)((byte *)&scrParserGlob + 20) = 0;
    *(void **)((byte *)&scrParserGlob + 12) = Z_MallocInternal(0x80000);
    *(int *)((byte *)&scrParserGlob + 28) = 0;
    *(int *)((byte *)&scrParserGlob + 32) = 0;
    *(int *)((byte *)&scrParserGlob + 24) = 0x10;
    *(int *)((byte *)&scrParserPub + 4) = 0;
    *(void **)&scrParserPub = Z_MallocInternal(0x180);
}

/* line 92 */
extern int FS_FOpenFileByMode(const char *, int *, int);
extern int FS_Read(void *, int, int);
extern void FS_FCloseFile(int);
extern void *Hunk_AllocateTempMemoryHighInternal(int size);
extern void Com_Printf(const char *fmt, ...);

/* Scr_AddSourceBufferInternal: store source buffer metadata */
static void Scr_AddSourceBufferInternal(const char *codePos, char *sourceBuf, int len, int doEolFixup, int archive)
{
    /* Stub: just store the source buffer info if in developer mode */
    (void)codePos; (void)sourceBuf; (void)len; (void)doEolFixup; (void)archive;
}

/* Scr_ReadFile: read a script file from the filesystem */
static char *Scr_ReadFile(const char *filename, const char *extFilename, const char *codePos, int archive)
{
    int file;
    int len;
    char *buf;

    len = FS_FOpenFileByMode(extFilename, &file, 0 /* FS_READ */);
    if (len < 0) {
        Scr_AddSourceBufferInternal(codePos, NULL, -1, 1, archive);
        return NULL;
    }

    buf = (char *)Hunk_AllocateTempMemoryHighInternal(len + 1);
    FS_Read(buf, len, file);
    buf[len] = 0;
    FS_FCloseFile(file);

    Scr_AddSourceBufferInternal(codePos, buf, len, 1, archive);
    return buf;
}

/* Scr_AddSourceBuffer: load source for a script file */
char *Scr_AddSourceBuffer(const char *filename, const char *extFilename, const char *codePos, int archive)
{
    return Scr_ReadFile(filename, extFilename, codePos, archive);
}

void Scr_ShutdownOpcodeLookup(void) {
    int i;

    if (*(void **)&scrParserGlob) {
        Z_FreeInternal(*(void **)&scrParserGlob);
        *(void **)&scrParserGlob = 0;
    }

    if (*(void **)((byte *)&scrParserGlob + 12)) {
        Z_FreeInternal(*(void **)((byte *)&scrParserGlob + 12));
        *(void **)((byte *)&scrParserGlob + 12) = 0;
    }

    if (*(void **)&scrParserPub) {
        unsigned int count = *(unsigned int *)((byte *)&scrParserPub + 4);
        if (count > 0) {
            byte *base = *(byte **)&scrParserPub;
            for (i = 0; i < (int)count; i++) {
                int idx = i;
                idx = idx * 3;
                void *entry = *(void **)(base + idx * 8 + 4);
                Z_FreeInternal(entry);
            }
        }
        Z_FreeInternal(*(void **)&scrParserPub);
        *(void **)&scrParserPub = 0;
    }

    if (*(void **)((byte *)&scrParserGlob + 36)) {
        int entryCount = *(int *)((byte *)&scrParserGlob + 40);
        if (entryCount > 0) {
            byte *entries = *(byte **)((byte *)&scrParserGlob + 36);
            for (i = 0; i < entryCount; i++) {
                void *entry = *(void **)(entries + i * 8);
                if (entry)
                    Z_FreeInternal(entry);
            }
        }
        Z_FreeInternal(*(void **)((byte *)&scrParserGlob + 36));
        *(void **)((byte *)&scrParserGlob + 36) = 0;
    }
}
