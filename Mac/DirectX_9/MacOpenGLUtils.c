/* ASM dump from: MacOpenGLUtils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/MacOpenGLUtils.cpp */
/* Rewritten from naked x86 ASM to clean C for Linux/Emscripten/WebGL2 port */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 */

static UINT32 sD3DTextureOpToOpenGL[16] = {
    0x00008577, 0x00008578, 0x00001702, 0x00008576,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
}; /* 0x308360 */
static UINT8 FastTranslateTbl[32] = {
    0x10, 0x20, 0x00, 0x00, 0x30, 0x12, 0x12, 0x40,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
}; /* 0x308340 */
static UINT32 sDeclarationTable[8] = {
    0x11406040, 0x21406040, 0x31406040, 0x41406040,
    0x41401011, 0x41401010, 0x21402020, 0x41402020,
}; /* 0x308320 */

bool MacOpenGLUtils_IsGLExtensionSupported(const char * pExtension);
bool MacOpenGLUtils_AreMatricesDifferent4x4(const int * pA, const int * pB);
bool MacOpenGLUtils_IsCompressed(const D3DFORMAT *f);
UINT32 MacOpenGLUtils_GetFormatSizeInBits(const D3DFORMAT *f);
int MacOpenGLUtils_GetOpenGLTextureOp(GLenum *Source, GLenum *Params, UINT32 D3DTextureOp);
int MacOpenGLUtils_GetOpenGLTextureAlphaOp(GLenum *Source, GLenum *Params, UINT32 D3DTextureOp);
UINT32 MacOpenGLUtils_GetElementCount(GLenum Mode, UINT32 PrimitiveCount);
UINT32 MacOpenGLUtils_GetPCPixelShaderVersion(void);
UINT32 MacOpenGLUtils_GetNumTextureLevels(UINT32 Width, UINT32 Height, UINT32 Depth);
int MacOpenGLUtils_GetDeclarationInfo(GLint *VSize, GLenum *VType, UINT32 *ComponentSize, GLboolean *Normalized, UINT32 Type);
int MacOpenGLUtils_GetSubPixelOffset(float *XOffset, float *YOffset);
int MacOpenGLUtils_GetOpenGLTextureType(bool *CreateOpenGLResources, GLenum *OpenGLInternalFormat, GLenum *OpenGLFormat, GLenum *OpenGLElementType, D3DFORMAT mFormat);
UINT32 MacOpenGLUtils_GetLevelSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, const D3DFORMAT *f);
float MacOpenGLUtils_SquareRootLowPrecision(float fp0);
int MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL(float *m, float ViewportWidth, float ViewportHeight);
UINT32 MacOpenGLUtils_GetImageSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, UINT32 LevelCount, const D3DFORMAT *f);
int MacDisplay_GetCardType(void);
int MacDisplay_IsGLExtensionSupported(const char *ext);
UINT32 MacDisplay_GetPCPixelShaderVersion(void);

/* line 104 */
bool MacOpenGLUtils_IsGLExtensionSupported(const char * pExtension)
{
    return MacDisplay_IsGLExtensionSupported(pExtension) != 0;
}

/* line 116 */
bool MacOpenGLUtils_AreMatricesDifferent4x4(const int * pA, const int * pB)
{
    int code = 0;
    int count;

    for (count = 0; count < 4; count++) {
        code |= pA[count * 4 + 0] ^ pB[count * 4 + 0];
        code |= pA[count * 4 + 1] ^ pB[count * 4 + 1];
        code |= pA[count * 4 + 2] ^ pB[count * 4 + 2];
        code |= pA[count * 4 + 3] ^ pB[count * 4 + 3];
    }

    return code != 0;
}

/* line 144 */
bool MacOpenGLUtils_IsCompressed(const D3DFORMAT *f)
{
    D3DFORMAT fmt = *f;

    switch (fmt) {
        case D3DFMT_DXT1: /* 0x31545844 */
        case D3DFMT_DXT2: /* 0x32545844 */
        case D3DFMT_DXT3: /* 0x33545844 */
        case D3DFMT_DXT4: /* 0x34545844 */
        case D3DFMT_DXT5: /* 0x35545844 */
            return 1;
        default:
            return 0;
    }
}

/*
 * Returns the number of bits per pixel for a given D3DFORMAT.
 * Decompiled from the branch tree in the naked ASM.
 *
 * Format hex values (from enum):
 *   0x14 = 20 = D3DFMT_R8G8B8         -> 24 bits
 *   0x15 = 21 = D3DFMT_A8R8G8B8       -> 32 bits
 *   0x16 = 22 = D3DFMT_X8R8G8B8       -> 32 bits (jg to 16-bit path... re-check)
 *   0x17 = 23 = D3DFMT_R5G6B5         -> 16 bits
 *   0x1a = 26 = D3DFMT_A4R4G4B4       -> 16 bits
 *   0x1b = 27 = D3DFMT_R3G3B2         -> 8 bits
 *   0x1c = 28 = D3DFMT_A8             -> 8 bits
 *   0x1e = 30 = D3DFMT_X4R4G4B4       -> 16 bits
 *   0x28 = 40 = D3DFMT_A8P8           -> 16 bits
 *   0x29 = 41 = D3DFMT_P8             -> 8 bits
 *   0x32 = 50 = D3DFMT_L8             -> 8 bits
 *   0x33 = 51 = D3DFMT_A8L8           -> 16 bits
 *   0x34 = 52 = D3DFMT_A4L4           -> 8 bits
 *   0x3c = 60 = D3DFMT_V8U8           -> 16 bits
 *   0x3d = 61 = D3DFMT_L6V5U5         -> 16 bits
 *   0x3e-0x3f (62-63) fall to 16 via >= 0x3c
 *   0x40 = 64 = D3DFMT_V16U16         -> 32 bits (via <= 0x40)
 *   0x46 = 70 = D3DFMT_D16_LOCKABLE   -> 16 bits
 *   0x47 = 71 = D3DFMT_D32            -> 32 bits
 *   0x49 = 73 = D3DFMT_D15S1          -> 16 bits
 *   0x4b = 75 = D3DFMT_D24S8          -> 32 bits
 *   0x4d = 77 = D3DFMT_D24X8          -> 32 bits
 *   0x4f = 79 = D3DFMT_D24X4S4        -> 32 bits
 *   0x50 = 80 = D3DFMT_D16            -> 16 bits
 *   0x65 = 101= D3DFMT_INDEX16        -> 16 bits
 *   0x66 = 102= D3DFMT_INDEX32        -> 32 bits
 *   DXT1                              -> 4 bits
 *   DXT2, DXT3, DXT4, DXT5            -> 8 bits
 */
/* line 203 */
UINT32 MacOpenGLUtils_GetFormatSizeInBits(const D3DFORMAT *f)
{
    D3DFORMAT fmt = *f;

    switch (fmt) {
        /* 24 bits */
        case D3DFMT_R8G8B8:         /* 0x14 = 20 */
            return 24;

        /* 32 bits */
        case D3DFMT_A8R8G8B8:       /* 0x15 = 21 */
        case D3DFMT_X8R8G8B8:       /* 0x16 = 22 */
        case D3DFMT_X8L8V8U8:       /* 0x3e = 62 */
        case D3DFMT_Q8W8V8U8:       /* 0x3f = 63 */
        case D3DFMT_V16U16:         /* 0x40 = 64 */
        case D3DFMT_D32:            /* 0x47 = 71 */
        case D3DFMT_D24S8:          /* 0x4b = 75 */
        case D3DFMT_D24X8:          /* 0x4d = 77 */
        case D3DFMT_D24X4S4:        /* 0x4f = 79 */
        case D3DFMT_INDEX32:        /* 0x66 = 102 */
            return 32;

        /* 16 bits */
        case D3DFMT_R5G6B5:         /* 0x17 = 23 */
        case D3DFMT_X1R5G5B5:       /* 0x18 = 24 */
        case D3DFMT_A1R5G5B5:       /* 0x19 = 25 */
        case D3DFMT_A4R4G4B4:       /* 0x1a = 26 */
        case D3DFMT_A8R3G3B2:       /* 0x1d = 29 */
        case D3DFMT_X4R4G4B4:       /* 0x1e = 30 */
        case D3DFMT_A8P8:           /* 0x28 = 40 */
        case D3DFMT_A8L8:           /* 0x33 = 51 */
        case D3DFMT_V8U8:           /* 0x3c = 60 */
        case D3DFMT_L6V5U5:         /* 0x3d = 61 */
        case D3DFMT_D16_LOCKABLE:   /* 0x46 = 70 */
        case D3DFMT_D15S1:          /* 0x49 = 73 */
        case D3DFMT_D16:            /* 0x50 = 80 */
        case D3DFMT_INDEX16:        /* 0x65 = 101 */
            return 16;

        /* 8 bits */
        case D3DFMT_R3G3B2:         /* 0x1b = 27 */
        case D3DFMT_A8:             /* 0x1c = 28 */
        case D3DFMT_P8:             /* 0x29 = 41 */
        case D3DFMT_L8:             /* 0x32 = 50 */
        case D3DFMT_A4L4:           /* 0x34 = 52 */
        case D3DFMT_DXT3:
        case D3DFMT_DXT2:
        case D3DFMT_DXT4:
        case D3DFMT_DXT5:
            return 8;

        /* 4 bits */
        case D3DFMT_DXT1:
            return 4;

        default:
            return 0;
    }
}

/* line 367 */
int MacOpenGLUtils_GetOpenGLTextureOp(GLenum *Source, GLenum *Params, UINT32 D3DTextureOp)
{
    UINT32 opIndex;
    UINT32 bit4;
    UINT32 bit5;

    opIndex = D3DTextureOp & 0xF;
    *Source = sD3DTextureOpToOpenGL[opIndex];

    bit4 = (D3DTextureOp >> 4) & 1;
    /* if bit4 == 1: 0x301-1 = 0x300; if bit4 == 0: 0x301-0 = 0x301 */
    /* Actually: sbb eax,eax with cmp 1 sets CF=0 if bit4==1, CF=1 if bit4==0 */
    /* cmpb $1, %dl; sbbl %eax,%eax; addl $0x301, %eax */
    /* if bit4==1: CF=0, sbb->0, result=0x301 */
    /* if bit4==0: CF=1, sbb->-1, result=0x300 */
    *Params = bit4 ? 0x301 : 0x300;

    bit5 = D3DTextureOp & 0x20;
    if (bit5) {
        /* cmpb $1, %dl; sbbl %eax,%eax; addl $0x303, %eax */
        /* if bit4==1: 0x303; if bit4==0: 0x302 */
        *Params = bit4 ? 0x303 : 0x302;
    }

    return 0;
}

/* line 385 */
int MacOpenGLUtils_GetOpenGLTextureAlphaOp(GLenum *Source, GLenum *Params, UINT32 D3DTextureOp)
{
    UINT32 opIndex;
    UINT32 bit4;

    opIndex = D3DTextureOp & 0xF;
    *Source = sD3DTextureOpToOpenGL[opIndex];

    bit4 = D3DTextureOp & 0x10;
    /* cmpl $1, %edx; sbbl %eax,%eax; addl $0x303, %eax */
    /* if bit4 >= 1 (nonzero, i.e. 0x10): CF=0, sbb->0, result=0x303 */
    /* if bit4 == 0: CF=1, sbb->-1, result=0x302 */
    *Params = bit4 ? 0x303 : 0x302;

    return 0;
}

/* line 433 */
UINT32 MacOpenGLUtils_GetElementCount(GLenum Mode, UINT32 PrimitiveCount)
{
    UINT8 MultAdd;
    UINT32 mult;
    UINT32 add;

    MultAdd = FastTranslateTbl[Mode];
    mult = (MultAdd >> 4);
    add = MultAdd & 0xF;

    return mult * PrimitiveCount + add;
}

/* line 496 */
UINT32 MacOpenGLUtils_GetPCPixelShaderVersion(void)
{
    return MacDisplay_GetPCPixelShaderVersion();
}

/* line 510 */
UINT32 MacOpenGLUtils_GetNumTextureLevels(UINT32 Width, UINT32 Height, UINT32 Depth)
{
    UINT32 ActualLevels = 0;
    UINT32 TempWidth = Width;
    UINT32 TempHeight = Height;
    UINT32 TempDepth = Depth;

    for (;;) {
        if (TempWidth) {
            if (TempHeight) {
                /* Both Width and Height nonzero: halve both */
                TempWidth >>= 1;
                TempHeight >>= 1;
            } else {
                /* Width nonzero, Height zero: halve Width, keep Height=0 */
                TempWidth >>= 1;
                TempHeight = 0;
            }
        } else {
            if (TempHeight) {
                /* Width zero, Height nonzero: halve Height */
                TempHeight >>= 1;
            } else if (TempDepth) {
                /* Width=0, Height=0, Depth nonzero: set Width=1 then halve to 0 */
                TempWidth = 1;
                TempWidth >>= 1;
                TempHeight = 0;
            } else {
                /* All zero: done */
                break;
            }
        }

        /* Halve depth if nonzero */
        if (TempDepth) {
            TempDepth >>= 1;
        }

        ActualLevels++;
    }

    return ActualLevels;
}

/* line 552 */
int MacOpenGLUtils_GetDeclarationInfo(GLint *VSize, GLenum *VType, UINT32 *ComponentSize, GLboolean *Normalized, UINT32 Type)
{
    UINT32 DeclarationInfo;

    DeclarationInfo = sDeclarationTable[Type];
    *VSize = (DeclarationInfo >> 28);
    *VType = (DeclarationInfo >> 12) & 0xFFFF;
    *ComponentSize = (DeclarationInfo >> 4) & 0xF;
    *Normalized = (GLboolean)(DeclarationInfo & 1);

    return 0;
}

/* line 584 */
int MacOpenGLUtils_GetSubPixelOffset(float *XOffset, float *YOffset)
{
    if (MacDisplay_GetCardType() == 2) {
        /* 0xbe99999a = -0.3f */
        *XOffset = -0.30000001192092896f;
        *YOffset = -0.30000001192092896f;
    } else {
        /* 0xbe19999a = -0.15f */
        *XOffset = -0.15000000596046448f;
        /* 0xbd99999a = -0.075f */
        *YOffset = -0.07500000298023224f;
    }

    return 0;
}

/*
 * Maps D3DFORMAT to OpenGL internal format, format, and element type.
 *
 * GL constant values used:
 *   GL_RGB             = 0x1907
 *   GL_RGBA            = 0x1908
 *   GL_LUMINANCE       = 0x1909
 *   GL_LUMINANCE_ALPHA = 0x190A
 *   GL_ALPHA           = 0x1906
 *   GL_DEPTH_COMPONENT = 0x1902
 *   GL_RGBA8           = 0x8058 (but code uses 0x8057 = GL_RGB8)
 *   GL_RGB5_A1         = 0x8057
 *   GL_RGBA4           = 0x8056
 *   GL_BGRA            = 0x80E1
 *   GL_UNSIGNED_BYTE   = 0x1401
 *   GL_UNSIGNED_SHORT_5_6_5_REV      = 0x8364 (not used here)
 *   GL_UNSIGNED_SHORT_5_6_5          = 0x8363
 *   GL_UNSIGNED_SHORT_4_4_4_4_REV    = 0x8365
 *   GL_UNSIGNED_SHORT_1_5_5_5_REV    = 0x8366
 *   GL_COMPRESSED_RGB_S3TC_DXT1_EXT  = 0x83F1
 *   GL_COMPRESSED_RGBA_S3TC_DXT3_EXT = 0x83F2
 *   GL_COMPRESSED_RGBA_S3TC_DXT5_EXT = 0x83F3
 */
/* line 629 */
int MacOpenGLUtils_GetOpenGLTextureType(bool *CreateOpenGLResources, GLenum *OpenGLInternalFormat, GLenum *OpenGLFormat, GLenum *OpenGLElementType, D3DFORMAT mFormat)
{
    GLenum tmpInternal = 0, tmpFormat = 0, tmpElement = 0;
    if (CreateOpenGLResources)
        *CreateOpenGLResources = 1;
    if (!OpenGLInternalFormat) OpenGLInternalFormat = &tmpInternal;
    if (!OpenGLFormat) OpenGLFormat = &tmpFormat;
    if (!OpenGLElementType) OpenGLElementType = &tmpElement;

    switch (mFormat) {
        case D3DFMT_A1R5G5B5:    /* 0x19 = 25 */
            *OpenGLInternalFormat = 0x8057; /* GL_RGB5_A1 */
            *OpenGLFormat = 0x80E1;         /* GL_BGRA */
            *OpenGLElementType = 0x8366;    /* GL_UNSIGNED_SHORT_1_5_5_5_REV */
            break;

        case D3DFMT_R5G6B5:      /* 0x17 = 23 */
            *OpenGLInternalFormat = 0x1907; /* GL_RGB */
            *OpenGLFormat = 0x1907;         /* GL_RGB */
            *OpenGLElementType = 0x8363;    /* GL_UNSIGNED_SHORT_5_6_5 */
            break;

        case D3DFMT_A4R4G4B4:    /* 0x1a = 26 */
            *OpenGLInternalFormat = 0x8056; /* GL_RGBA4 */
            *OpenGLFormat = 0x80E1;         /* GL_BGRA */
            *OpenGLElementType = 0x8365;    /* GL_UNSIGNED_SHORT_4_4_4_4_REV */
            break;

        case D3DFMT_R8G8B8:      /* 0x14 = 20 */
            *OpenGLInternalFormat = 0x1907; /* GL_RGB */
            *OpenGLFormat = 0x1907;         /* GL_RGB */
            *OpenGLElementType = 0x1401;    /* GL_UNSIGNED_BYTE */
            break;

        case D3DFMT_A8R8G8B8:    /* 0x15 = 21 */
        case D3DFMT_X8R8G8B8:    /* 0x16 = 22 */
            *OpenGLInternalFormat = 0x1908; /* GL_RGBA */
            *OpenGLFormat = 0x80E1;         /* GL_BGRA */
            *OpenGLElementType = 0x1401;    /* GL_UNSIGNED_BYTE */
            break;

        case D3DFMT_A8:          /* 0x1c = 28 */
            *OpenGLInternalFormat = 0x1906; /* GL_ALPHA */
            *OpenGLFormat = 0x1906;         /* GL_ALPHA */
            *OpenGLElementType = 0x1401;    /* GL_UNSIGNED_BYTE */
            break;

        case D3DFMT_L8:          /* 0x32 = 50 */
            *OpenGLInternalFormat = 0x1909; /* GL_LUMINANCE */
            *OpenGLFormat = 0x1909;         /* GL_LUMINANCE */
            *OpenGLElementType = 0x1401;    /* GL_UNSIGNED_BYTE */
            break;

        case D3DFMT_A8L8:        /* 0x33 = 51 */
            *OpenGLInternalFormat = 0x190A; /* GL_LUMINANCE_ALPHA */
            *OpenGLFormat = 0x190A;         /* GL_LUMINANCE_ALPHA */
            *OpenGLElementType = 0x1401;    /* GL_UNSIGNED_BYTE */
            break;

        case D3DFMT_DXT1:
            *OpenGLInternalFormat = 0x83F1; /* GL_COMPRESSED_RGB_S3TC_DXT1_EXT */
            *OpenGLElementType = 0;
            *OpenGLFormat = 0;
            break;

        case D3DFMT_DXT2:
        case D3DFMT_DXT3:
            *OpenGLInternalFormat = 0x83F2; /* GL_COMPRESSED_RGBA_S3TC_DXT3_EXT */
            *OpenGLElementType = 0;
            *OpenGLFormat = 0;
            break;

        case D3DFMT_DXT5:
            *OpenGLInternalFormat = 0x83F3; /* GL_COMPRESSED_RGBA_S3TC_DXT5_EXT */
            *OpenGLElementType = 0;
            *OpenGLFormat = 0;
            break;

        case D3DFMT_D24S8:       /* 0x4b = 75 */
            *OpenGLInternalFormat = 0x1902; /* GL_DEPTH_COMPONENT */
            *OpenGLFormat = 0x1902;         /* GL_DEPTH_COMPONENT */
            *OpenGLElementType = 0x1401;    /* GL_UNSIGNED_BYTE */
            break;

        /* Non-renderable formats: D3DFMT_D32 (71), D3DFMT_D15S1 (73), D3DFMT_D16 (80) */
        case D3DFMT_D32:         /* 0x47 = 71 */
        case D3DFMT_D15S1:       /* 0x49 = 73 */
        case D3DFMT_D16:         /* 0x50 = 80 */
            *CreateOpenGLResources = 0;
            break;

        default:
            break;
    }

    return 0;
}

/*
 * Computes the byte size of a single mip level for a given format.
 * For uncompressed formats: (Width * Height * Depth * BitsPerPixel) / 8
 * For compressed (DXT): block-aligned with 4x4 blocks.
 *   DXT1: 8 bytes per block
 *   DXT2/3/4/5: 16 bytes per block
 */
/* line 277 */
UINT32 MacOpenGLUtils_GetLevelSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, const D3DFORMAT *f)
{
    UINT32 w, h, d;
    UINT32 bitsPerPixel;
    UINT32 blockSize;
    D3DFORMAT fmt;

    w = Width ? Width : 1;
    h = Height ? Height : 1;
    d = Depth ? Depth : 1;

    fmt = *f;

    if (MacOpenGLUtils_IsCompressed(f)) {
        if (fmt == D3DFMT_DXT1) {
            blockSize = 8;
        } else {
            blockSize = 16;
        }
        return ((w + 3) / 4) * ((h + 3) / 4) * d * blockSize;
    }

    bitsPerPixel = MacOpenGLUtils_GetFormatSizeInBits(f);
    return (w * h * d * bitsPerPixel) / 8;
}

/* line 95 - fast inverse square root approximation, then multiply by input */
float MacOpenGLUtils_SquareRootLowPrecision(float fp0)
{
    union {
        float f;
        int i;
    } conv;
    float xhalf;
    float y;

    conv.f = fp0;
    conv.i = 0x5f375a86 - (conv.i >> 1);
    y = conv.f;
    xhalf = fp0 * 0.5f;
    y = y * (1.5f - xhalf * y * y);
    return fp0 * y;
}

/* line 737 */
int MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL(float *m, float ViewportWidth, float ViewportHeight)
{
    float x;
    float y;

    if (MacDisplay_GetCardType() == 2) {
        x = -0.30000001192092896f;
        y = -0.30000001192092896f;
    } else {
        x = -0.15000000596046448f;
        y = -0.07500000298023224f;
    }

    x /= ViewportWidth;
    y /= ViewportHeight;

    m[0] += x * m[3];
    m[1] += y * m[3];
    m[2] = 2.0f * m[2] - m[3];

    m[4] += x * m[7];
    m[5] += y * m[7];
    m[6] = 2.0f * m[6] - m[7];

    m[8] = -(m[8] + x * m[11]);
    m[9] = -(m[9] + y * m[11]);
    m[10] = m[11] - 2.0f * m[10];
    m[11] = -m[11];

    m[12] += x * m[15];
    m[13] += y * m[15];
    m[14] = 2.0f * m[14] - m[15];

    return 0;
}

/*
 * Computes total image size across all mip levels.
 * Iterates LevelCount levels, halving dimensions each time,
 * accumulating GetLevelSizeInBytes for each.
 */
/* line 315 */
UINT32 MacOpenGLUtils_GetImageSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, UINT32 LevelCount, const D3DFORMAT *f)
{
    UINT32 ImageSizeInBytes;
    UINT32 Level;
    UINT32 w, h, d;

    if (LevelCount == 0) {
        return 0;
    }

    ImageSizeInBytes = 0;
    w = Width;
    h = Height;
    d = Depth;

    for (Level = 0; Level < LevelCount; Level++) {
        D3DFORMAT fmt_val = *f;
        UINT32 ew, eh, ed;
        UINT32 levelSize;

        ew = w ? w : 1;
        eh = h ? h : 1;
        ed = d ? d : 1;

        if (fmt_val == D3DFMT_DXT1 || fmt_val == D3DFMT_DXT2 || fmt_val == D3DFMT_DXT3 ||
            fmt_val == D3DFMT_DXT4 || fmt_val == D3DFMT_DXT5) {
            UINT32 blockSize;
            if (fmt_val == D3DFMT_DXT1) {
                blockSize = 8;
            } else {
                blockSize = 16;
            }
            levelSize = ((ew + 3) / 4) * ((eh + 3) / 4) * ed * blockSize;
        } else {
            UINT32 bitsPerPixel = MacOpenGLUtils_GetFormatSizeInBits(f);
            levelSize = (ew * eh * ed * bitsPerPixel) / 8;
        }

        ImageSizeInBytes += levelSize;

        /* Halve dimensions for next level */
        if (w) w >>= 1;
        if (h) h >>= 1;
        if (d) d >>= 1;
    }

    return ImageSizeInBytes;
}
