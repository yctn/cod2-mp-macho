/* ASM dump from: r_image_wavelet.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_image_wavelet.cpp */

#include "common_types.h"
#include "imports.h"

static const WaveletHuffmanDecode waveletDecodeBlue[4096]; /* waveletDecodeBlue */
static const WaveletHuffmanDecode waveletDecodeRedGreen[4096]; /* waveletDecodeRedGreen */
static const WaveletHuffmanDecode waveletDecodeAlpha[4096]; /* waveletDecodeAlpha */

void Wavelet_DecompressLevel(byte *src, byte *dst, WaveletDecode *decode);

static unsigned int Wavelet_ReadDword(const byte *p) {
    return (unsigned int)p[0]
        | ((unsigned int)p[1] << 8)
        | ((unsigned int)p[2] << 16)
        | ((unsigned int)p[3] << 24);
}

static void Wavelet_AdvanceBits(WaveletDecode *decode, int numBits) {
    unsigned short newBit = decode->bit + numBits;
    decode->data += (newBit >> 3);
    decode->bit = newBit & 7;
}

static int Wavelet_ReadBit1(WaveletDecode *decode) {
    unsigned short val = decode->value;
    int bit = val & 1;
    unsigned int dword;

    val >>= 1;
    dword = Wavelet_ReadDword(decode->data);
    dword >>= decode->bit;
    dword <<= 15;
    val |= (unsigned short)dword;
    decode->value = val;
    Wavelet_AdvanceBits(decode, 1);
    return bit;
}

/* 9-bit extended huffman decode (for blue and alpha channels) */
static int Wavelet_HuffmanDecode9(WaveletDecode *decode, const WaveletHuffmanDecode *table) {
    unsigned short val = decode->value;
    int index = val & 0xfff;
    int bits = table[index].bits;
    int result;
    unsigned int dword;

    val >>= bits;
    dword = Wavelet_ReadDword(decode->data);
    dword >>= decode->bit;
    dword <<= (16 - bits);
    val |= (unsigned short)dword;
    decode->value = val;
    Wavelet_AdvanceBits(decode, bits);

    result = table[index].value;
    if (result != (short)0x8000) {
        return result;
    }

    /* Extended 9-bit decode */
    result = (val & 0x1ff) - 0xff;
    val >>= 9;
    dword = Wavelet_ReadDword(decode->data);
    dword >>= decode->bit;
    dword <<= 7;
    val |= (unsigned short)dword;
    decode->value = val;
    Wavelet_AdvanceBits(decode, 9);
    return result;
}

/* 10-bit extended huffman decode (for red/green channel) */
static int Wavelet_HuffmanDecode10(WaveletDecode *decode, const WaveletHuffmanDecode *table) {
    unsigned short val = decode->value;
    int index = val & 0xfff;
    int bits = table[index].bits;
    int result;
    unsigned int dword;

    val >>= bits;
    dword = Wavelet_ReadDword(decode->data);
    dword >>= decode->bit;
    dword <<= (16 - bits);
    val |= (unsigned short)dword;
    decode->value = val;
    Wavelet_AdvanceBits(decode, bits);

    result = table[index].value;
    if (result != (short)0x8000) {
        return result;
    }

    /* Extended 10-bit decode */
    result = (val & 0x3ff) - 0x1fe;
    val >>= 10;
    dword = Wavelet_ReadDword(decode->data);
    dword >>= decode->bit;
    dword <<= 6;
    val |= (unsigned short)dword;
    decode->value = val;
    Wavelet_AdvanceBits(decode, 10);
    return result;
}

/* line 98 */
void Wavelet_DecompressLevel(byte *src, byte *dst, WaveletDecode *decode)
{
    int w, h;
    int dstBpp, stride;
    int alpha0, alpha1;
    int dstBpp2;
    int x, y;
    int numBlocks;
    int hasAlphaRLE;

    /* line 117 */
    w = decode->width >> decode->mipLevel;
    /* line 118 */
    h = decode->height >> decode->mipLevel;

    /* line 120 */
    if (w - 1 <= 0) {
        /* line 122 */
        if (w > 0) {
            /* w stays */
        } else {
            w = 1;
        }
        goto small_case;
    }
    if (h - 1 <= 0) {
        goto small_case;
    }

    /* line 140 */
    if (!decode->dataInitialized) {
        /* lines 143-146: initialize bitstream */
        const byte *p = decode->data;
        unsigned short initVal;
        initVal = (unsigned short)p[0] | ((unsigned short)p[1] << 8);
        decode->value = initVal;
        decode->bit = 0;
        decode->data = p + 2;
        decode->dataInitialized = 1;
    }

    /* line 149 */
    dstBpp = decode->bpp;
    /* line 151 */
    stride = w * dstBpp;
    /* line 152 */
    alpha0 = dstBpp - 1;
    /* line 153 */
    dstBpp2 = dstBpp * 2;
    alpha1 = dstBpp2 - 1;

    /* line 155-157: Read 1 bit for hasAlphaRLE flag */
    hasAlphaRLE = Wavelet_ReadBit1(decode);

    if (hasAlphaRLE) {
        /* line 158 */
        int totalPixels = w * h;

        if (totalPixels <= -1) {
            numBlocks = (totalPixels + 3) >> 2;
        } else {
            numBlocks = totalPixels >> 2;
        }

        /* line 68 */
        if (decode->channels == decode->bpp) {
            /* All channels present - decode all bytes directly */
            int totalBytes = numBlocks * dstBpp;
            int srcIndex = 0;

            while (srcIndex < totalBytes) {
                byte prev = src[srcIndex];
                int delta = Wavelet_HuffmanDecode9(decode, waveletDecodeAlpha);
                src[srcIndex] = (byte)(prev + delta);
                srcIndex++;
            }
        } else {
            /* lines 81-91: Alpha RLE decode loop */
            int srcIndex = 0;
            int blockIdx;

            for (blockIdx = 0; blockIdx < numBlocks; blockIdx++) {
                int runLen = decode->channels;
                int i;

                for (i = 0; i < runLen; i++) {
                    byte prev = src[srcIndex + i];
                    int delta = Wavelet_HuffmanDecode9(decode, waveletDecodeAlpha);
                    src[srcIndex + i] = (byte)(prev + delta);
                }
                /* line 90: write alpha marker */
                src[srcIndex + i] = 0xff;
                /* line 91 */
                srcIndex += i + 1;
            }
        }
    }

    /* line 160: Main 2D wavelet reconstruction loop */
    for (y = 0; y < h; y += 2) {
        for (x = 0; x < w; x += 2) {
            int blue_d0, blue_d1, blue_d2;
            int rg_d0, rg_d1, rg_d2;
            int parityBlue, parityRG, parityAlpha;
            int base, a, b, c, e;
            byte *dstTR, *dstBL, *dstBR;

            /* line 166 */
            if (decode->channels == 1) {
                goto check_alpha;
            }

            /* line 168: Read blue channel parity bit */
            parityBlue = Wavelet_ReadBit1(decode);

            /* Decode 3 blue coefficients */
            blue_d0 = Wavelet_HuffmanDecode9(decode, waveletDecodeBlue);
            blue_d1 = Wavelet_HuffmanDecode9(decode, waveletDecodeBlue);
            blue_d2 = Wavelet_HuffmanDecode9(decode, waveletDecodeBlue);

            /* line 173-177: Reconstruct blue channel in 2x2 block */
            base = src[0] * 2;
            a = base + blue_d0;
            b = blue_d1 + blue_d2;
            dst[0] = (byte)(((a + b) >> 1) + parityBlue);
            dst[dstBpp] = (byte)((a - b) >> 1);
            c = base - blue_d0;
            e = blue_d1 - blue_d2;
            dst[stride] = (byte)((c + e) >> 1);
            dstBR = dst + stride + dstBpp;
            dst[stride + dstBpp] = (byte)((c - e) >> 1);

            /* line 179 */
            if (decode->channels <= 2) {
                goto check_alpha;
            }

            /* line 181: RG component 1 (index 1) parity + 3 coefficients */
            parityRG = Wavelet_ReadBit1(decode);

            rg_d0 = Wavelet_HuffmanDecode10(decode, waveletDecodeRedGreen) + blue_d0;
            rg_d1 = Wavelet_HuffmanDecode10(decode, waveletDecodeRedGreen) + blue_d1;
            rg_d2 = blue_d2 + Wavelet_HuffmanDecode10(decode, waveletDecodeRedGreen);

            /* line 186-190: Reconstruct component 1 in 2x2 block */
            base = src[1] * 2;
            a = base + rg_d0;
            b = rg_d1 + rg_d2;
            dst[1] = (byte)(((a + b) >> 1) + parityRG);
            dstTR = dst + dstBpp;
            dstTR[1] = (byte)((a - b) >> 1);
            dstBL = dst + stride;
            c = base - rg_d0;
            e = rg_d1 - rg_d2;
            dstBL[1] = (byte)((c + e) >> 1);
            dstBR = dst + stride + dstBpp;
            dstBR[1] = (byte)((c - e) >> 1);

            /* line 192: RG component 2 (index 2) parity + 3 coefficients */
            parityRG = Wavelet_ReadBit1(decode);

            rg_d0 = Wavelet_HuffmanDecode10(decode, waveletDecodeRedGreen) + blue_d0;
            rg_d1 = Wavelet_HuffmanDecode10(decode, waveletDecodeRedGreen) + blue_d1;
            rg_d2 = blue_d2 + Wavelet_HuffmanDecode10(decode, waveletDecodeRedGreen);

            /* line 197-201: Reconstruct component 2 in 2x2 block */
            base = src[2] * 2;
            a = base + rg_d0;
            b = rg_d1 + rg_d2;
            dst[2] = (byte)(((a + b) >> 1) + parityRG);
            dstTR[2] = (byte)((a - b) >> 1);
            c = base - rg_d0;
            e = rg_d1 - rg_d2;
            dstBL[2] = (byte)((c + e) >> 1);
            dstBR[2] = (byte)((c - e) >> 1);

check_alpha:
            /* line 205 */
            if (decode->channels == 3) {
                /* line 218: Check bpp for alpha fill */
                if (decode->bpp != 3) {
                    /* lines 220-223: Fill alpha with 0xff */
                    dst[alpha0] = 0xff;
                    dst[alpha1] = 0xff;
                    *(dst + stride + alpha0) = 0xff;
                    *(dst + stride + alpha1) = 0xff;
                }
                goto advance_ptrs;
            }

            /* line 207: Alpha parity + 3 coefficients */
            parityAlpha = Wavelet_ReadBit1(decode);

            {
                int alpha_d0, alpha_d1, alpha_d2;

                alpha_d0 = Wavelet_HuffmanDecode9(decode, waveletDecodeAlpha);
                alpha_d1 = Wavelet_HuffmanDecode9(decode, waveletDecodeAlpha);
                alpha_d2 = Wavelet_HuffmanDecode9(decode, waveletDecodeAlpha);

                /* line 212-216: Reconstruct alpha in 2x2 block */
                base = src[alpha0] * 2;
                a = base + alpha_d0;
                b = alpha_d1 + alpha_d2;
                dst[alpha0] = (byte)(((a + b) >> 1) + parityAlpha);
                dst[alpha1] = (byte)((a - b) >> 1);
                c = base - alpha_d0;
                e = alpha_d1 - alpha_d2;
                *(dst + stride + alpha0) = (byte)((c + e) >> 1);
                *(dst + stride + alpha1) = (byte)((c - e) >> 1);
            }

advance_ptrs:
            /* line 226-227: Advance src and dst pointers */
            src += dstBpp;
            dst += dstBpp2;
        }
        /* line 229 */
        dst += stride;
    }
    return;

small_case:
    /* lines 124-134: Simple case for w <= 1 or h <= 1 */
    {
        int maxH;
        int totalPixels;
        int i;

        if (h > 0) {
            maxH = h;
        } else {
            maxH = 1;
        }
        totalPixels = w + maxH - 1;

        for (i = 0; i < totalPixels; i++) {
            int channels = decode->channels;
            int j;

            for (j = 0; j < channels; j++) {
                /* line 132 */
                *dst = *(decode->data);
                dst++;
                decode->data++;
            }
            /* line 133 */
            if (decode->bpp != channels) {
                /* line 134 */
                *dst = 0xff;
                dst++;
            }
        }
    }
}
