/* ASM dump from: cinematics.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/cinematics.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

/* External function declarations for C-converted functions */
extern void Com_DPrintf(const char *fmt, ...);
extern void SND_StopSounds(int);
extern void SND_EndRawSamples(void);
extern void Sys_EndStreamedFile(fileHandle_t);
extern void Sys_BeginStreamedFile(fileHandle_t, int);
extern void Sys_StreamedRead(void *, int, int, fileHandle_t);
extern void FS_FCloseFile(fileHandle_t);
extern int FS_FOpenFileRead(const char *, fileHandle_t *, int);
extern char *va(const char *fmt, ...);
extern void Cbuf_ExecuteText(int, const char *);
extern void Dvar_SetString(void *, const char *);
extern void UI_SetActiveMenu(int);
extern int CL_ScaledMilliseconds(void);
extern char *Cmd_Argv(int);
extern void CL_StopLogo(void);
extern void SND_FadeAllSounds(float, int);
extern void CL_LookupColor(int, float *);
extern float floorf(float);
extern float ceilf(float);

static Boolean sAspyrIntroPlayed; /* sAspyrIntroPlayed */
static long int ROQ_YY_tab[256]; /* ROQ_YY_tab */
static long int ROQ_UB_tab[256]; /* ROQ_UB_tab */
static long int ROQ_UG_tab[256]; /* ROQ_UG_tab */
static long int ROQ_VG_tab[256]; /* ROQ_VG_tab */
static long int ROQ_VR_tab[256]; /* ROQ_VR_tab */
static short unsigned int vq2[16384]; /* vq2 */
static short unsigned int vq4[65536]; /* vq4 */
static short unsigned int vq8[262144]; /* vq8 */
static struct cinematics_t cin; /* cin */
static cin_cache cinTable[16]; /* cinTable */
extern int currentHandle; /* currentHandle */
extern int CL_handle; /* CL_handle */

static inflate_blocks_statef recurseQuad(long int startX, long int startY, long int quadSize, long int xOff, long int yOff);
static inflate_blocks_statef RoQShutdown(void);
e_status ROQ_StopCinematicFromHandle(int handle);
inflate_blocks_statef ROQ_SetExtentsFromHandle(int handle, int x, int y, int w, int h);
inflate_blocks_statef ROQ_UploadCinematicFromHandle(int handle);
static void blitVQQuad32fs(byte * *status, unsigned char *data);
int ROQ_PlayCinematic(const char *arg, int x, int y, int w, int h, int systemBits);
inflate_blocks_statef ROQ_DrawCinematicFromHandle(int handle);
inflate_blocks_statef ROQ_DrawCinematic(void);
static inflate_blocks_statef RoQReset(void);
inflate_blocks_statef ROQ_CloseAllVideos(void);
inflate_blocks_statef ROQ_StopCinematic(void);
e_status ROQ_RunCinematicFromHandle(int handle);
inflate_blocks_statef ROQ_RunCinematic(void);
inflate_blocks_statef ROQ_PlayCinematic_f(void);

/* line 1171 */
static inflate_blocks_statef recurseQuad(long int startX, long int startY, long int quadSize, long int xOff, long int yOff)
{
    int h;
    long int offset;
    unsigned int xsize_clamped, ysize_clamped;
    long int CIN_HEIGHT_val;
    long int scrY, scrX;
    long int onQuad;
    long int half;

    while (quadSize != 4) {
        h = currentHandle;
        offset = cinTable[h].screenDelta;
        xsize_clamped = cinTable[h].xsize;
        ysize_clamped = cinTable[h].ysize;

        if (xsize_clamped > (unsigned int)cinTable[h].CIN_WIDTH) {
            xsize_clamped = cinTable[h].CIN_WIDTH;
        }
        CIN_HEIGHT_val = cinTable[h].CIN_HEIGHT;
        if (ysize_clamped > (unsigned int)CIN_HEIGHT_val) {
            ysize_clamped = CIN_HEIGHT_val;
        }

        if (startX >= 0 && (unsigned int)(startX + quadSize) <= xsize_clamped &&
            (unsigned int)(startY + quadSize) <= ysize_clamped && startY >= 0 &&
            quadSize <= 8) {
            scrY = (startY + (CIN_HEIGHT_val - (long int)ysize_clamped) / 2 + yOff) * cinTable[h].samplesPerLine;
            scrX = (startX + xOff) * cinTable[h].samplesPerPixel;
            onQuad = cinTable[h].onQuad;
            cin.qStatus[0][onQuad] = (byte *)((char *)&cin + scrY + scrX);
            cin.qStatus[1][onQuad] = (byte *)((char *)&cin + scrY + scrX + offset);
            cinTable[h].onQuad = onQuad + 1;
        }

        quadSize >>= 1;
        recurseQuad(startX, startY, quadSize, xOff, yOff);
        half = quadSize;
        recurseQuad(startX + half, startY, quadSize, xOff, yOff);
        startY += half;
        recurseQuad(startX, startY, quadSize, xOff, yOff);
        startX += half;
    }
}

/* line 1561 */
static inflate_blocks_statef RoQShutdown(void)
{
    int h;
    int *clcState;
    char *nextMapStr;
    void (*rendererCallback)(void);

    h = currentHandle;
    if (cinTable[h].buf && cinTable[h].status != FMV_IDLE) {
        Com_DPrintf("finished cinematic\n");
        cinTable[currentHandle].status = FMV_IDLE;

        if (cinTable[currentHandle].sound) {
            SND_EndRawSamples();
        }

        if (cinTable[currentHandle].iFile) {
            Sys_EndStreamedFile(cinTable[currentHandle].iFile);
            FS_FCloseFile(cinTable[currentHandle].iFile);
            cinTable[currentHandle].iFile = 0;
        }

        if (cinTable[currentHandle].alterGameState) {
            clcState = (int *)*(void **)imp_clc;
            *clcState = cinTable[currentHandle].previousGameState;
            CL_handle = -1;
            if (*clcState == 0) {
                nextMapStr = *(char **)((char *)*(void **)imp_nextmap + 8);
                if (*nextMapStr != '\0') {
                    if (!sAspyrIntroPlayed) {
                        if (strstr(nextMapStr, "IW_logo")) {
                            Cbuf_ExecuteText(2, va("%s\n", "cinematic aspyr_intro"));
                            sAspyrIntroPlayed = 1;
                        } else {
                            Cbuf_ExecuteText(2, va("%s\n", nextMapStr));
                            Dvar_SetString(*(void **)imp_nextmap, "");
                        }
                    } else {
                        Cbuf_ExecuteText(2, va("%s\n", nextMapStr));
                        Dvar_SetString(*(void **)imp_nextmap, "");
                    }
                    UI_SetActiveMenu(1);
                } else {
                    UI_SetActiveMenu(0);
                }
            } else {
                UI_SetActiveMenu(0);
            }
        }

        rendererCallback = *(void (**)(void))((char *)(void *)imp_re + 0x148);
        if (rendererCallback) {
            rendererCallback();
        }

        memset(&cinTable[currentHandle], 0, sizeof(cin_cache));
        currentHandle = -1;
    }
}

/* line 1645 */
e_status ROQ_StopCinematicFromHandle(int handle)
{
    if ((unsigned int)handle > 0xf || cinTable[handle].status == FMV_EOF) {
        return FMV_EOF;
    }
    currentHandle = handle;
    Com_DPrintf("trFMV::stop(), closing %s\n", cinTable[currentHandle].fileName);
    if (!cinTable[currentHandle].buf) {
        return FMV_EOF;
    }
    if (cinTable[currentHandle].alterGameState) {
        if (*(int *)*(void **)imp_clc != 1) {
            return cinTable[currentHandle].status;
        }
    }
    cinTable[currentHandle].status = FMV_EOF;
    RoQShutdown();
    return FMV_EOF;
}

/* line 1877 */
inflate_blocks_statef ROQ_SetExtentsFromHandle(int handle, int x, int y, int w, int h)
{
    if ((unsigned int)handle <= 0xf && cinTable[handle].status != FMV_EOF) {
        cinTable[handle].xpos = x;
        cinTable[handle].ypos = y;
        cinTable[handle].width = w;
        cinTable[handle].height = h;
        cinTable[handle].dirty = 1;
    }
}

/* line 2115 */
inflate_blocks_statef ROQ_UploadCinematicFromHandle(int handle)
{
    if ((unsigned int)handle <= 0xf && cinTable[handle].buf) {
        if (cinTable[handle].playonwalls <= 0 && cinTable[handle].dirty) {
            if (cinTable[handle].playonwalls == 0) {
                cinTable[handle].playonwalls = -1;
            } else if (cinTable[handle].playonwalls == -1) {
                cinTable[handle].playonwalls = -2;
            } else {
                cinTable[handle].dirty = 0;
            }
        }
        if (!*(byte *)((*(char **)imp_cl_inGameVideo)[0] + 8)) {
            if (cinTable[handle].playonwalls == 1) {
                cinTable[handle].playonwalls = 0;
            }
        }
    }
}

/* line 587 */
static void blitVQQuad32fs(byte * *status, unsigned char *data)
{
    long int stride;
    long int twoRows;
    int index;
    unsigned int celdata;
    short newd;
    byte *dst;
    byte *src;
    byte **subStatus;
    int subCount;
    int i;

    stride = cinTable[currentHandle].samplesPerLine;
    stride &= ~7;
    twoRows = cinTable[currentHandle].samplesPerLine * 2;
    index = 0;

outer:
    celdata = data[0] | (data[1] << 8);
    data += 2;
    newd = 7;

    goto first_iter;

next_check:
    if (!status[index]) {
        return;
    }

next_iter:
    if (newd == 0) {
        goto outer;
    }
    newd--;

first_iter:
    {
        unsigned short code = (celdata >> 14) & 3;
        celdata <<= 2;

        if (code == 1) {
            /* 0x4000: 8x8 motion-compensated copy */
            dst = status[index];
            src = dst + cin.mcomp[*data];
            for (i = 0; i < 8; i++) {
                memcpy(dst, src, 0x20);
                dst += stride;
                src += stride;
            }
            data++;
            index += 5;
            goto next_check;
        } else if (code == 0) {
            /* 0x0000: skip */
            index += 5;
            goto next_check;
        } else if (code == 2) {
            /* 0x8000: 8x8 VQ8 codebook */
            {
                int vqIdx = (*data) << 8;
                byte *vqSrc = (byte *)&vq8[0] + vqIdx;
                dst = status[index];
                memcpy(dst, vqSrc, 0x20);
                dst += stride;
                memcpy(dst, vqSrc + 0x20, 0x20);
                dst += stride;
                memcpy(dst, vqSrc + 0x40, 0x20);
                dst += stride;
                memcpy(dst, vqSrc + 0x60, 0x20);
                dst += stride;
                memcpy(dst, vqSrc + 0x80, 0x20);
                dst += stride;
                memcpy(dst, vqSrc + 0xa0, 0x20);
                dst += stride;
                memcpy(dst, vqSrc + 0xc0, 0x20);
                dst += stride;
                memcpy(dst, vqSrc + 0xe0, 0x20);
            }
            data++;
            index += 5;
            goto next_check;
        } else {
            /* 0xC000: split into 4 sub-blocks */
            index++;
            subStatus = &status[index];
            subCount = 4;

            if (newd == 0) {
                goto sub_outer;
            }
            goto sub_next;

sub_done:
            index++;
            subStatus += 1;
            subCount--;
            if (subCount == 0) {
                goto next_check;
            }
            if (newd == 0) {
                goto sub_outer;
            }

sub_next:
            newd--;
            {
                unsigned short subCode = (celdata >> 14) & 3;
                celdata <<= 2;
                if (subCode == 2) {
                    goto sub_vq4;
                } else if (subCode == 3) {
                    goto sub_vq2;
                } else if (subCode == 1) {
                    goto sub_motion;
                } else {
                    goto sub_done;
                }
            }

sub_outer:
            celdata = data[0] | (data[1] << 8);
            data += 2;
            newd = 7;
            {
                unsigned short subCode = (celdata >> 14) & 3;
                celdata <<= 2;
                if (subCode == 2) {
                    goto sub_vq4;
                } else if (subCode == 3) {
                    goto sub_vq2;
                } else if (subCode == 1) {
                    goto sub_motion;
                } else {
                    goto sub_done;
                }
            }

sub_vq4:
            /* 4x4 VQ4 block */
            {
                int vqIdx = (*data) << 6;
                byte *vqSrc = (byte *)&vq4[0] + vqIdx;
                dst = *subStatus;
                memcpy(dst, vqSrc, 0x10);
                dst += stride;
                memcpy(dst, vqSrc + 0x10, 0x10);
                dst += stride;
                memcpy(dst, vqSrc + 0x20, 0x10);
                dst += stride;
                memcpy(dst, vqSrc + 0x30, 0x10);
            }
            data++;
            goto sub_done;

sub_motion:
            /* 4x4 motion-compensated copy */
            {
                dst = *subStatus;
                src = dst + cin.mcomp[*data];
                for (i = 0; i < 4; i++) {
                    memcpy(dst, src, 0x10);
                    dst += stride;
                    src += stride;
                }
            }
            data++;
            goto sub_done;

sub_vq2:
            /* 4 2x2 VQ2 blocks */
            {
                byte *ddst;
                int vqIdx;

                /* top-left 2x2 */
                vqIdx = data[0] << 4;
                ddst = *subStatus;
                memcpy(ddst, (byte *)&vq2[0] + vqIdx, 8);
                memcpy(ddst + stride, (byte *)&vq2[0] + vqIdx + 8, 8);

                /* top-right 2x2 */
                vqIdx = data[1] << 4;
                ddst = *subStatus;
                memcpy(ddst + 8, (byte *)&vq2[0] + vqIdx, 8);
                memcpy(ddst + stride + 8, (byte *)&vq2[0] + vqIdx + 8, 8);

                /* bottom-left 2x2 */
                vqIdx = data[2] << 4;
                ddst = *subStatus + twoRows;
                memcpy(ddst, (byte *)&vq2[0] + vqIdx, 8);
                memcpy(ddst + stride, (byte *)&vq2[0] + vqIdx + 8, 8);

                /* bottom-right 2x2 */
                vqIdx = data[3] << 4;
                ddst = *subStatus + twoRows;
                memcpy(ddst + 8, (byte *)&vq2[0] + vqIdx, 8);
                memcpy(ddst + stride + 8, (byte *)&vq2[0] + vqIdx + 8, 8);
            }
            data += 4;
            goto sub_done;
        }
    }
}


/* line 1786 */
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern int I_stricmp(const char *s1, const char *s2);
extern void Com_Error(int level, const char *fmt, ...);
extern void Com_Memset(void *dest, int val, int count);
extern void FS_Read(void *buffer, int len, fileHandle_t f);
extern void SND_RawSamples(int samples, int rate, int width, int channels, const byte *data);
extern void Con_Close(void);

static int CIN_findHandle(void)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (cinTable[i].fileName[0] == '\0') {
            return i;
        }
    }
    Com_Error(1, "CIN_findHandle: none free");
    return 0;
}

int ROQ_PlayCinematic(const char *arg, int x, int y, int w, int h, int systemBits)
{
    char name[256];
    unsigned char looping;
    int i;
    int handle;
    unsigned short id;
    int fps;

    Com_sprintf(name, 256, "video/%s.roq", arg);
    looping = (unsigned char)systemBits & 1;

    if (!looping) {
        for (i = 0; i < 16; i++) {
            if (I_stricmp(cinTable[i].fileName, name) == 0) {
                return i;
            }
        }
    }

    Com_DPrintf("SCR_PlayCinematic( %s )\n", arg);
    Com_Memset(&cin, 0, sizeof(cin));
    handle = CIN_findHandle();
    currentHandle = handle;
    cin.currentHandle = handle;

    strcpy(cinTable[handle].fileName, name);
    cinTable[handle].ROQSize = 0;
    cinTable[handle].ROQSize = FS_FOpenFileRead(cinTable[handle].fileName, &cinTable[handle].iFile, 1);

    if (cinTable[handle].ROQSize <= 0) {
        Com_DPrintf("play(%s), ROQSize<=0\n", arg);
        cinTable[currentHandle].fileName[0] = '\0';
        return -1;
    }

    if ((unsigned int)handle <= 0xf && cinTable[handle].status != FMV_EOF) {
        cinTable[handle].xpos = x;
        cinTable[handle].ypos = y;
        cinTable[handle].width = w;
        cinTable[handle].height = h;
        cinTable[handle].dirty = 1;
    }

    {
        int loop = (systemBits >> 1) & 1;
        if ((unsigned int)handle <= 0xf && cinTable[handle].status != FMV_EOF) {
            cinTable[handle].looping = loop;
        }
    }

    cinTable[handle].holdAtEnd = (systemBits >> 2) & 1;
    cinTable[handle].alterGameState = looping;
    cinTable[handle].playonwalls = 1;
    cinTable[handle].silent = (systemBits >> 3) & 1;
    cinTable[handle].material = (systemBits >> 4) & 1;
    cinTable[handle].letterBox = (systemBits >> 5) & 1;
    cinTable[handle].sound = 0;

    if (cinTable[handle].alterGameState) {
        if (*(int *)((char *)imp_cls + 0x110)) {
            UI_SetActiveMenu(0);
        }
    } else {
        cinTable[handle].playonwalls = *(byte *)((*(char **)imp_cl_inGameVideo)[8]) != 0;
    }

    if (handle >= 0) {
        cinTable[handle].VQ0 = (void *)blitVQQuad32fs;
        cinTable[handle].VQ1 = (void *)blitVQQuad32fs;
        cinTable[handle].samplesPerPixel = 4;

        for (i = 0; i < 256; i++) {
            float f = (float)(i * 2 - 255);
            ROQ_UB_tab[i] = (long int)(f * 57.204f + 32.0f);
            ROQ_VR_tab[i] = (long int)(f * 45.364f + 32.0f);
            ROQ_UG_tab[i] = (long int)(f * -11.5125f);
            ROQ_VG_tab[i] = (long int)(f * -23.3525f + 32.0f);
            ROQ_YY_tab[i] = (long int)((i << 6) | (i >> 2));
        }

        {
            int d;
            short *tab = cin.sqrTable;
            for (d = 0; d < 128; d++) {
                tab[d] = (short)(d * d);
                tab[d + 128] = (short)(-(d * d));
            }
        }
    }

    FS_Read(cin.file, 16, cinTable[handle].iFile);

    id = cin.file[0] | (cin.file[1] << 8);
    if (id != 0x1084) {
        Com_DPrintf("trFMV::play(), invalid RoQ ID\n");
        RoQShutdown();
        return -1;
    }

    {
        unsigned int t;
        t = CL_ScaledMilliseconds();
        cinTable[currentHandle].startTime = t;
        cinTable[currentHandle].lastTime = t;
        cinTable[currentHandle].lastFrameTime = t;
        cinTable[currentHandle].RoQPlayed = 24;

        fps = cin.file[6] | (cin.file[7] << 8);
        if (fps == 0) fps = 30;
        cinTable[currentHandle].roqFPS = fps;
        cinTable[currentHandle].numQuads = -1;
        cinTable[currentHandle].roq_id = cin.file[8] | (cin.file[9] << 8);
        cinTable[currentHandle].RoQFrameSize = cin.file[10] | (cin.file[11] << 8) | (cin.file[12] << 16);
        cinTable[currentHandle].roq_flags = cin.file[14] | (cin.file[15] << 8);
    }

    Sys_BeginStreamedFile(cinTable[currentHandle].iFile, 0x10000);
    cinTable[currentHandle].letterBox = 1;

    Com_DPrintf("trFMV::play(), playing %s\n", arg);

    if (cinTable[currentHandle].alterGameState) {
        int *clcState = (int *)*(void **)imp_clc;
        cinTable[currentHandle].previousGameState = (connstate_t)*clcState;
        *clcState = 1;
    }

    Con_Close();
    i = currentHandle;
    return i;
}


/* line 1994 */
inflate_blocks_statef ROQ_DrawCinematicFromHandle(int handle)
{
    byte *buf;
    float aspect;
    float clearColor[3];
    int x, y, w, h;
    char *cls;
    char *re;
    float screenAspect;
    int screenW, screenH;
    float barSize;
    int barSizeCeil;
    float xf, wf;
    int material;

    if ((unsigned int)handle > 0xf || cinTable[handle].status == FMV_EOF) {
        goto done;
    }
    buf = cinTable[handle].buf;
    if (!buf) {
        goto done;
    }

    aspect = (float)cinTable[handle].width / (float)cinTable[handle].height;
    CL_LookupColor(0x30, clearColor);

    cls = (char *)imp_cls;
    screenAspect = *(float *)(cls + 0x2a0a74);

    if (aspect == screenAspect) {
        /* aspect matches screen exactly */
        w = *(int *)(cls + 0x2a0a64);
        h = *(int *)(cls + 0x2a0a68);
        x = 0;
        y = 0;
    } else if (aspect > screenAspect) {
        /* wider than screen: pillarbox (bars on top/bottom) */
        h = *(int *)(cls + 0x2a0a68);
        barSize = ((float)h - screenAspect / aspect * (float)h) * 0.5f;
        y = (int)floorf(barSize);
        barSizeCeil = (int)ceilf(barSize);
        h = h - barSizeCeil * 2;
        w = *(int *)(cls + 0x2a0a64);
        x = 0;
    } else {
        /* taller than screen: letterbox (bars on sides) */
        w = *(int *)(cls + 0x2a0a64);
        barSize = ((float)w - aspect / screenAspect * (float)w) * 0.5f;
        x = (int)floorf(barSize);
        barSizeCeil = (int)ceilf(barSize);
        w = w - barSizeCeil * 2;
        h = *(int *)(cls + 0x2a0a68);
        y = 0;
    }

    /* draw clear/background */
    re = *(char **)imp_re;
    ((void (*)(int, float *, int, int))*(void **)(re + 0xc8))(1, clearColor, 0, 0);

    /* draw cinematic image */
    ((void (*)(int, int, int, int, int, int, byte *, int, int))*(void **)(re + 0x9c))(
        x, y, w, h, cinTable[handle].CIN_WIDTH, cinTable[handle].CIN_HEIGHT,
        buf, handle, cinTable[handle].dirty);
    cinTable[handle].dirty = 0;

    if (cinTable[handle].letterBox) {
        /* draw letterbox bars */
        cls = (char *)imp_cls;
        barSize = (float)*(int *)(cls + 0x2a0a68) / 480.0f * 105.0f;
        barSizeCeil = (int)ceilf(barSize);
        xf = (float)x;
        wf = (float)w;
        material = *(int *)(cls + 0x2a0a58);

        re = *(char **)imp_re;
        ((void (*)(float, float, float, float, int, int, int, int, float *, int))*(void **)(re + 0x94))(
            xf, (float)y, wf, (float)(int)floorf(barSize),
            0, 0, 0, 0, clearColor, material);
        ((void (*)(float, float, float, float, int, int, int, int, float *, int))*(void **)(re + 0x94))(
            xf, (float)(y + h - barSizeCeil), wf, (float)barSizeCeil,
            0, 0, 0, 0, clearColor, material);
    }
done:
    ;
}

/* line 2086 */
inflate_blocks_statef ROQ_DrawCinematic(void)
{
    if ((unsigned int)CL_handle <= 0xf) {
        ROQ_DrawCinematicFromHandle(CL_handle);
    }
}

/* line 1327 */
static inflate_blocks_statef RoQReset(void)
{
    int h;
    int fps;
    unsigned int t;

    h = currentHandle;
    if (h >= 0) {
        Sys_EndStreamedFile(cinTable[h].iFile);
        FS_FCloseFile(cinTable[h].iFile);
        cinTable[currentHandle].iFile = 0;
        FS_FOpenFileRead(cinTable[currentHandle].fileName, &cinTable[currentHandle].iFile, 1);
        Sys_BeginStreamedFile(cinTable[currentHandle].iFile, 0x10000);
        Sys_StreamedRead(cin.file, 0x10, 1, cinTable[currentHandle].iFile);

        t = CL_ScaledMilliseconds();
        cinTable[currentHandle].startTime = t;
        cinTable[currentHandle].lastTime = t;
        cinTable[currentHandle].lastFrameTime = t;
        cinTable[currentHandle].RoQPlayed = 0x18;

        fps = cin.file[6] | (cin.file[7] << 8);
        if (fps == 0) {
            fps = 30;
        }
        cinTable[currentHandle].roqFPS = fps;
        cinTable[currentHandle].numQuads = -1;
        cinTable[currentHandle].roq_id = cin.file[8] | (cin.file[9] << 8);
        cinTable[currentHandle].RoQFrameSize = cin.file[10] | (cin.file[11] << 8) | (cin.file[12] << 16);
        cinTable[currentHandle].roq_flags = cin.file[14] | (cin.file[15] << 8);
        cinTable[currentHandle].status = FMV_LOOPED;
    }
}

/* line 130 */
inflate_blocks_statef ROQ_CloseAllVideos(void)
{
    int i;

    for (i = 0; i < 16; i++) {
        if (cinTable[i].fileName[0] == '\0') {
            continue;
        }
        if (cinTable[i].status == FMV_EOF) {
            continue;
        }
        currentHandle = i;
        Com_DPrintf("trFMV::stop(), closing %s\n", cinTable[currentHandle].fileName);
        if (!cinTable[currentHandle].buf) {
            continue;
        }
        if (!cinTable[currentHandle].alterGameState || *(int *)*(void **)imp_clc == 1) {
            cinTable[currentHandle].status = FMV_EOF;
            RoQShutdown();
        }
    }
}

/* line 2104 */
inflate_blocks_statef ROQ_StopCinematic(void)
{
    int h;

    h = CL_handle;
    if ((unsigned int)h <= 0xf) {
        if (cinTable[h].status != FMV_EOF) {
            currentHandle = h;
            Com_DPrintf("trFMV::stop(), closing %s\n", cinTable[currentHandle].fileName);
            if (cinTable[currentHandle].buf) {
                if (!cinTable[currentHandle].alterGameState || *(int *)*(void **)imp_clc == 1) {
                    cinTable[currentHandle].status = FMV_EOF;
                    RoQShutdown();
                }
            }
        }
        SND_StopSounds(0);
        CL_handle = -1;
    }
}

/* line 1681 */
extern void Com_Memcpy(void *dest, const void *src, int count);

e_status ROQ_RunCinematicFromHandle(int handle)
{
    unsigned int thisTime;
    unsigned int start;
    int h;
    unsigned int numFrames;
    byte *framedata;
    short samplesBuf[16384];

    if ((unsigned int)handle > 0xf || cinTable[handle].status == FMV_EOF) {
        return FMV_EOF;
    }

    if (cin.currentHandle != handle) {
        currentHandle = handle;
        cin.currentHandle = handle;
        cinTable[handle].status = FMV_EOF;
        RoQReset();
    }

    if (cinTable[handle].playonwalls < -1) {
        return cinTable[handle].status;
    }

    currentHandle = handle;

    if (cinTable[handle].alterGameState) {
        if (*(int *)*(void **)imp_clc != 1) {
            return cinTable[handle].status;
        }
    }

    if (cinTable[handle].status == FMV_IDLE) {
        return (e_status)0;
    }

    thisTime = CL_ScaledMilliseconds();
    h = currentHandle;

    if (cinTable[h].material) {
        int elapsed = (int)thisTime - (int)cinTable[h].lastTime;
        float fElapsed;
        int absElapsed;
        if (elapsed >= 0) {
            fElapsed = (float)elapsed;
        } else {
            fElapsed = (float)(unsigned int)((unsigned int)thisTime - cinTable[h].lastTime);
        }
        absElapsed = (int)fElapsed;
        if (absElapsed < 0) absElapsed = -absElapsed;
        if (absElapsed > 100) {
            cinTable[h].startTime += (unsigned int)elapsed;
        }
    }

    handle = currentHandle;
    if (cinTable[handle].sound) {
        numFrames = 0;
    } else {
        numFrames = (unsigned int)((unsigned int)(thisTime - cinTable[handle].startTime) * (unsigned int)cinTable[handle].roqFPS) / 1000;
    }
    h = currentHandle;

    if ((long int)numFrames <= cinTable[h].tfps) {
        if ((thisTime - cinTable[h].lastFrameTime) * (unsigned int)cinTable[h].roqFPS > 4000) {
            cinTable[h].status = FMV_EOF;
        }
        goto frame_done;
    }
    cinTable[h].tfps = numFrames;
    cinTable[h].lastFrameTime = thisTime;

    h = currentHandle;
    start = cinTable[h].startTime;

frame_loop:
    h = currentHandle;
    if (cinTable[h].tfps == cinTable[h].numQuads) {
        goto frame_done_time;
    }

    if (cinTable[h].status != FMV_PLAY) {
        goto frame_done_time;
    }

    if (handle < 0) {
        goto after_parse;
    }

    Sys_StreamedRead(cin.file, cinTable[h].RoQFrameSize + 8, 1, cinTable[h].iFile);
    h = currentHandle;

    if (cinTable[h].RoQPlayed >= cinTable[h].ROQSize) {
        if (cinTable[h].holdAtEnd) {
            cinTable[h].status = FMV_EOF;
            handle = currentHandle;
            goto after_parse;
        }
        if (cinTable[h].looping) {
            RoQReset();
            h = currentHandle;
            handle = h;
            goto after_parse;
        } else {
            cinTable[h].status = FMV_EOF;
            handle = currentHandle;
            goto after_parse;
        }
    }

    framedata = cin.file;

parse_roq:
    h = currentHandle;
    {
        unsigned int roqId = cinTable[h].roq_id;
        if (roqId < 0x1001 || roqId > 0x1030) {
            cinTable[h].status = FMV_EOF;
            handle = h;
            goto do_packet_advance;
        }

        switch (roqId) {
        case 0x1001: /* RoQ_SOUND_MONO */
        {
            if (!cinTable[h].silent) {
                unsigned int frameSize = cinTable[h].RoQFrameSize;
                unsigned short roqFlags = (unsigned short)cinTable[h].roq_flags;

                if (frameSize > 0) {
                    unsigned int j;
                    short accum = roqFlags;
                    for (j = 0; j < frameSize; j++) {
                        accum += cin.sqrTable[framedata[j]];
                        samplesBuf[j * 2 + 1] = accum;
                        samplesBuf[j * 2] = accum;
                    }
                }
                SND_RawSamples(frameSize, 0x5622, 2, 1, (byte *)samplesBuf);
                h = currentHandle;
            }
            cinTable[h].sound = 1;
            handle = currentHandle;
            goto do_packet_advance;
        }

        case 0x1002: /* RoQ_SOUND_STEREO */
        {
            if (!cinTable[h].silent) {
                unsigned int frameSize = cinTable[h].RoQFrameSize;
                unsigned short roqFlags = (unsigned short)cinTable[h].roq_flags;
                short left = (short)(roqFlags & 0xff00);
                short right = (short)((roqFlags & 0xff) << 8);

                if (frameSize > 0) {
                    unsigned int j;
                    for (j = 0; j < frameSize; j += 2) {
                        left += cin.sqrTable[framedata[j]];
                        right += cin.sqrTable[framedata[j + 1]];
                        samplesBuf[j] = left;
                        samplesBuf[j + 1] = right;
                    }
                }
                SND_RawSamples(frameSize >> 1, 0x5622, 2, 2, (byte *)samplesBuf);
                h = currentHandle;
            }
            cinTable[h].sound = 1;
            handle = currentHandle;
            goto do_packet_advance;
        }

        case 0x1011: /* RoQ_QUAD_VQ */
        {
            /* Render callback */
            {
                void (*rendererCb)(void) = *(void (**)(void))((char *)(void *)imp_re + 0x148);
                if (rendererCb) rendererCb();
            }
            h = currentHandle;

            if (cinTable[h].numQuads & 1) {
                cinTable[h].normalBuffer0 = cinTable[h].t[1];
                /* Set up output for odd frame */
                {
                    long int roqF1 = cinTable[h].roqF1;
                    long int roqF0 = cinTable[h].roqF0;
                    long int sampLine = cinTable[h].samplesPerLine;
                    long int spp = cinTable[h].samplesPerPixel;
                    long int ysize = cinTable[h].ysize;

                    if (cinTable[h].xsize == ysize * 4) {
                        /* Special widescreen case */
                    } else {
                        roqF1 -= 8;
                        long int rowOff = (roqF0 - 8) * spp;
                        int col;
                        long int offset = cinTable[h].normalBuffer0;
                        long int baseOff = rowOff;
                        for (col = 0; col < 16; col++) {
                            byte **qp = (byte **)((byte *)&cin + 0x210200 + col * 4);
                            int row;
                            long int val = offset - (baseOff + roqF1 * sampLine);
                            for (row = 0; row < 16; row++) {
                                *qp = (byte *)(unsigned long)val;
                                val += (-spp);
                                qp = (byte **)((byte *)qp + 0x40);
                            }
                            roqF1 += sampLine;
                        }
                    }

                    /* Call VQ1 */
                    cinTable[h].VQ1(cin.qStatus[1], framedata);
                    h = currentHandle;
                    cinTable[h].buf = (byte *)((byte *)&cin + cinTable[h].screenDelta);
                }
            } else {
                cinTable[h].normalBuffer0 = cinTable[h].t[0];
                /* Set up output for even frame */
                {
                    long int roqF1 = cinTable[h].roqF1;
                    long int roqF0 = cinTable[h].roqF0;
                    long int sampLine = cinTable[h].samplesPerLine;
                    long int spp = cinTable[h].samplesPerPixel;
                    long int ysize = cinTable[h].ysize;

                    if (cinTable[h].xsize == ysize * 4) {
                        /* Special widescreen case */
                    } else {
                        roqF1 -= 8;
                        long int rowOff = (roqF0 - 8) * spp;
                        int col;
                        long int offset = cinTable[h].normalBuffer0;
                        long int baseOff = rowOff;
                        for (col = 0; col < 16; col++) {
                            byte **qp = (byte **)((byte *)&cin + 0x210200 + col * 4);
                            int row;
                            long int val = offset - (baseOff + roqF1 * sampLine);
                            for (row = 0; row < 16; row++) {
                                *qp = (byte *)(unsigned long)val;
                                val += (-spp);
                                qp = (byte **)((byte *)qp + 0x40);
                            }
                            roqF1 += sampLine;
                        }
                    }

                    /* Call VQ0 */
                    cinTable[h].VQ0(cin.qStatus[0], framedata);
                    h = currentHandle;
                    cinTable[h].buf = (byte *)&cin;
                }
            }

            {
                int numQ = cinTable[h].numQuads;
                if (numQ == 0) {
                    /* First frame: copy to other buffer */
                    if (cinTable[h].numQuads == 0) {
                        Com_Memcpy((byte *)&cin + cinTable[h].screenDelta,
                                   (byte *)&cin,
                                   cinTable[h].samplesPerLine * cinTable[h].ysize);
                    }
                }
            }

            cinTable[h].numQuads++;
            cinTable[h].dirty = 1;
            handle = currentHandle;
            goto do_packet_advance;
        }

        case 0x1020: /* RoQ_QUAD_INFO */
        {
            if (cinTable[h].numQuads == -1) {
                /* First info packet - set up dimensions */
                if (h >= 0) {
                    cinTable[h].CIN_WIDTH = framedata[0] | (framedata[1] << 8);
                    cinTable[h].CIN_HEIGHT = framedata[2] | (framedata[3] << 8);
                    cinTable[h].maxsize = framedata[4] | (framedata[5] << 8);
                    cinTable[h].minsize = framedata[6] | (framedata[7] << 8);
                    cinTable[h].CIN_HEIGHT = cinTable[h].CIN_HEIGHT;
                    cinTable[h].CIN_WIDTH = cinTable[h].CIN_WIDTH;
                    cinTable[h].samplesPerLine = cinTable[h].CIN_WIDTH * cinTable[h].samplesPerPixel;
                    cinTable[h].screenDelta = cinTable[h].samplesPerLine * cinTable[h].CIN_HEIGHT;
                    cinTable[h].half = 0;
                    cinTable[h].smootheddouble = 0;
                    cinTable[h].VQNormal = cinTable[h].VQ0;
                    cinTable[h].VQBuffer = cinTable[h].VQ1;
                    cinTable[h].t[0] = cinTable[h].screenDelta;
                    cinTable[h].t[1] = -(cinTable[h].screenDelta);
                }

                if (cin.oldXOff == 0 && cin.oldYOff == 0 &&
                    cinTable[h].ysize == (unsigned int)cin.oldysize &&
                    cinTable[h].xsize == (unsigned int)cin.oldxsize) {
                    /* No change in dimensions */
                } else {
                    int numCells, halfCells;
                    int sx, sy;

                    cin.oldXOff = 0;
                    cin.oldYOff = 0;
                    cin.oldysize = cinTable[h].ysize;
                    cin.oldxsize = cinTable[h].xsize;

                    numCells = (cinTable[h].xsize * cinTable[h].ysize) >> 4;
                    halfCells = numCells >> 2;

                    cinTable[h].onQuad = 0;

                    for (sy = 0; (unsigned int)sy < cinTable[h].ysize; sy += 16) {
                        for (sx = 0; (unsigned int)sx < cinTable[h].xsize; sx += 16) {
                            recurseQuad(sx, sy, 16, 0, 0);
                            h = currentHandle;
                        }
                    }

                    {
                        int sentStart = numCells + halfCells - 0x40 + 0x40;
                        int sentEnd = numCells + halfCells + 0x40;
                        int j;
                        for (j = sentStart; j < sentEnd; j++) {
                            cin.qStatus[0][j] = 0;
                            cin.qStatus[1][j] = 0;
                        }
                    }
                }

                thisTime = CL_ScaledMilliseconds();
                h = currentHandle;
                cinTable[h].lastTime = thisTime;
                cinTable[h].startTime = thisTime;
            }
            handle = currentHandle;
            {
                int hh = handle;
                cinTable[hh].numQuads++;
                if (cinTable[hh].numQuads == 0) {
                    cinTable[hh].numQuads = 0;
                }
                cinTable[hh].dirty = 1;
            }
            goto do_packet_advance;
        }

        case 0x1021: /* RoQ_QUAD_CODEBOOK */
        {
            unsigned short roqFlags = (unsigned short)cinTable[h].roq_flags;
            int numY, numCb;

            if ((roqFlags >> 8) == 0) {
                numY = 256;
            } else {
                numY = roqFlags >> 8;
            }
            numCb = (roqFlags & 0xff) * 2;

            if (cinTable[h].half) {
                /* half-resolution codebook */
                int bpp = cinTable[h].samplesPerPixel;
                if (bpp == 2) {
                    /* 16bpp half */
                } else if (bpp == 4) {
                    /* 32bpp half - build vq2/vq4/vq8 */
                    byte *input = framedata;
                    int idx;
                    for (idx = 0; idx < numY; idx++) {
                        unsigned char y[4], cb_val, cr_val;
                        long int *yy, *ub, *vr, *ug, *vg;
                        int p, q;
                        y[0] = input[0]; y[1] = input[1]; y[2] = input[2]; y[3] = input[3];
                        cb_val = input[4]; cr_val = input[5];
                        input += 6;

                        yy = ROQ_YY_tab; ub = ROQ_UB_tab; vr = ROQ_VR_tab;
                        ug = ROQ_UG_tab; vg = ROQ_VG_tab;

                        for (p = 0; p < 4; p++) {
                            unsigned long pixel = yy[y[p]] | (ub[cb_val] << 8) | (vr[cr_val] << 16);
                            ((unsigned short *)vq2)[idx * 8 + p] = (unsigned short)pixel;
                        }
                    }
                    for (idx = 0; idx < numCb; idx++) {
                        /* Build vq4 and vq8 from vq2 */
                    }
                } else if (bpp == 1) {
                    /* grayscale */
                }
            } else if (cinTable[h].smootheddouble) {
                /* smoothed double */
                int bpp = cinTable[h].samplesPerPixel;
                if (bpp == 2) {
                    /* 16bpp smoothed */
                } else if (bpp == 4) {
                    /* 32bpp smoothed */
                    byte *input = framedata;
                    int idx;
                    for (idx = 0; idx < numY; idx++) {
                        input += 6;
                    }
                    for (idx = 0; idx < numCb; idx++) {
                        /* Build vq4/vq8 */
                    }
                }
            } else {
                int bpp = cinTable[h].samplesPerPixel;
                if (bpp == 2) {
                    /* 16bpp normal */
                } else if (bpp == 4) {
                    /* 32bpp normal codebook */
                    {
                        byte *input = framedata;
                        int idx;
                        short unsigned int *vq2p = vq2;
                        for (idx = 0; idx < numY; idx++) {
                            unsigned char y0 = *input++;
                            unsigned char y1 = *input++;
                            unsigned char y2 = *input++;
                            unsigned char y3 = *input++;
                            unsigned char cbv = *input++;
                            unsigned char crv = *input++;

                            /* Build 2x2 cell entries */
                            {
                                byte c0 = (byte)(ROQ_YY_tab[y0] + ROQ_UB_tab[cbv]);
                                byte c1 = (byte)(ROQ_YY_tab[y0] + ROQ_UG_tab[cbv] + ROQ_VG_tab[crv]);
                                byte c2 = (byte)(ROQ_YY_tab[y0] + ROQ_VR_tab[crv]);
                                byte c3 = (byte)(ROQ_YY_tab[y1] + ROQ_UB_tab[cbv]);
                                byte c4 = (byte)(ROQ_YY_tab[y1] + ROQ_UG_tab[cbv] + ROQ_VG_tab[crv]);
                                byte c5 = (byte)(ROQ_YY_tab[y1] + ROQ_VR_tab[crv]);
                                byte c6 = (byte)(ROQ_YY_tab[y2] + ROQ_UB_tab[cbv]);
                                byte c7 = (byte)(ROQ_YY_tab[y2] + ROQ_UG_tab[cbv] + ROQ_VG_tab[crv]);
                                byte c8 = (byte)(ROQ_YY_tab[y2] + ROQ_VR_tab[crv]);
                                byte c9 = (byte)(ROQ_YY_tab[y3] + ROQ_UB_tab[cbv]);
                                byte ca = (byte)(ROQ_YY_tab[y3] + ROQ_UG_tab[cbv] + ROQ_VG_tab[crv]);
                                byte cb2 = (byte)(ROQ_YY_tab[y3] + ROQ_VR_tab[crv]);
                                ((byte *)vq2p)[0] = c0;
                                ((byte *)vq2p)[1] = c1;
                                ((byte *)vq2p)[2] = c2;
                                ((byte *)vq2p)[3] = 255;
                                ((byte *)vq2p)[4] = c3;
                                ((byte *)vq2p)[5] = c4;
                                ((byte *)vq2p)[6] = c5;
                                ((byte *)vq2p)[7] = 255;
                                ((byte *)vq2p)[8] = c6;
                                ((byte *)vq2p)[9] = c7;
                                ((byte *)vq2p)[10] = c8;
                                ((byte *)vq2p)[11] = 255;
                                ((byte *)vq2p)[12] = c9;
                                ((byte *)vq2p)[13] = ca;
                                ((byte *)vq2p)[14] = cb2;
                                ((byte *)vq2p)[15] = 255;
                            }
                            vq2p += 8;
                        }
                        /* Build vq4 from pairs of vq2 entries */
                        {
                            byte *vq4p = (byte *)vq4;
                            byte *vq8p = (byte *)vq8;
                            for (idx = 0; idx < numCb; idx++) {
                                unsigned char i0 = *input++;
                                unsigned char i1 = *input++;
                                /* Copy 2x2 blocks into 4x4 */
                                memcpy(vq4p, (byte *)vq2 + i0 * 16, 8);
                                memcpy(vq4p + 8, (byte *)vq2 + i1 * 16, 8);
                                memcpy(vq4p + 16, (byte *)vq2 + i0 * 16 + 8, 8);
                                memcpy(vq4p + 24, (byte *)vq2 + i1 * 16 + 8, 8);
                                vq4p += 32;
                                /* Build vq8 similarly */
                                /* 8x8 = 4 4x4 blocks */
                            }
                        }
                    }
                } else if (bpp == 1) {
                    /* grayscale */
                    byte *input = framedata;
                    int idx;
                    for (idx = 0; idx < numY; idx++) {
                        input += 6;
                    }
                }
            }

            handle = currentHandle;
            goto do_packet_advance;
        }

        case 0x1013: /* RoQ_QUAD_HANG */
        {
            handle = currentHandle;
            goto do_packet_advance;
        }

        case 0x1030: /* End marker */
        {
            cinTable[h].status = FMV_EOF;
            handle = h;
            goto do_packet_advance;
        }

        default:
            cinTable[h].status = FMV_EOF;
            handle = h;
            goto do_packet_advance;
        }
    }

do_packet_advance:
    h = currentHandle;
    cinTable[h].RoQPlayed += cinTable[h].RoQFrameSize + 8;
    handle = h;

after_parse:
    h = handle;
    if (cinTable[h].startTime != start) {
        thisTime = CL_ScaledMilliseconds();
        h = currentHandle;
        numFrames = (unsigned int)((unsigned int)(thisTime - cinTable[h].startTime) * (unsigned int)cinTable[h].roqFPS) / 1000;
        cinTable[h].tfps = numFrames;
        start = cinTable[h].startTime;
        h = currentHandle;
        if (cinTable[h].tfps != cinTable[h].numQuads) {
            if (cinTable[h].status == FMV_PLAY) {
                goto frame_loop;
            }
        }
    } else {
        h = currentHandle;
    }

frame_done_time:
    cinTable[h].lastTime = thisTime;

    if (cinTable[h].status == FMV_LOOPED) {
        cinTable[h].status = FMV_PLAY;
    }

    if (cinTable[h].status == FMV_EOF) {
        /* done */
    }

frame_done:
    h = currentHandle;
    return cinTable[h].status;
}


/* line 2095 */
inflate_blocks_statef ROQ_RunCinematic(void)
{
    if ((unsigned int)CL_handle <= 0xf) {
        ROQ_RunCinematicFromHandle(CL_handle);
    }
}

/* line 2031 */
inflate_blocks_statef ROQ_PlayCinematic_f(void)
{
    int argc;
    char *arg;
    char *argv2;
    int systemBits;
    int h;

    Com_DPrintf("CL_PlayCinematic_f\n");
    argc = *(int *)*(void **)imp_clc;

    if (argc == 1) {
        /* inlined ROQ_StopCinematic */
        h = CL_handle;
        if ((unsigned int)h <= 0xf) {
            if (cinTable[h].status != FMV_EOF) {
                currentHandle = h;
                Com_DPrintf("trFMV::stop(), closing %s\n", cinTable[currentHandle].fileName);
                if (cinTable[currentHandle].buf) {
                    if (!cinTable[currentHandle].alterGameState || *(int *)*(void **)imp_clc == 1) {
                        cinTable[currentHandle].status = FMV_EOF;
                        RoQShutdown();
                    }
                }
            }
            SND_StopSounds(0);
            CL_handle = -1;
        }
    } else if (argc == 2) {
        CL_StopLogo();
    }

    arg = Cmd_Argv(1);
    argv2 = Cmd_Argv(2);
    if (!argv2) {
        systemBits = 1;
    } else {
        switch (argv2[0]) {
        case '1':
            systemBits = 5;
            break;
        case '2':
            systemBits = 3;
            break;
        case '3':
            systemBits = 0x21;
            break;
        default:
            systemBits = 1;
            break;
        }
    }

    if (systemBits & 0x20) {
        CL_handle = ROQ_PlayCinematic(arg, 0, 0x69, 0x280, 0x10e, systemBits);
    } else {
        CL_handle = ROQ_PlayCinematic(arg, 0, 0, 0x280, 0x1e0, systemBits);
    }

    if (CL_handle >= 0) {
        SND_StopSounds(0);
        SND_FadeAllSounds(1.0f, 0);
        do {
            if ((unsigned int)CL_handle <= 0xf) {
                ROQ_RunCinematicFromHandle(CL_handle);
            }
            if (cinTable[currentHandle].buf) {
                break;
            }
        } while (cinTable[currentHandle].status == FMV_PLAY);
    }
}

