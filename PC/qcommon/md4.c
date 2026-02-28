/* ASM dump from: md4.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/md4.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern long int Com_Memcpy(long int *dest, const long int *src, int count);
extern long int Com_Memset(long int *dest, const int val, int count);

static unsigned char PADDING[64]; /* PADDING */

static void MD4Transform(UINT4 *state, const unsigned char *block);
void MD4Update(MD4_CTX *context, const unsigned char *input, unsigned int inputLen);
void MD4Final(unsigned char *digest, MD4_CTX *context);
unsigned int Com_BlockChecksumKey(void *buffer, int length, int key);
unsigned int Com_BlockChecksum(const void *buffer, int length);

/* MD4 basic functions F, G, H */
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (y)) | ((x) & (z)) | ((y) & (z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))

/* ROTATE_LEFT rotates x left by n bits (implemented as right rotate by 32-n) */
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

/* Decodes input (unsigned char) into output (UINT4). Assumes len is a multiple of 4. */
static void Decode(UINT4 *output, const unsigned char *input, unsigned int len)
{
    unsigned int i, j;
    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[i] = ((UINT4)input[j]) |
                     (((UINT4)input[j+1]) << 8) |
                     (((UINT4)input[j+2]) << 16) |
                     (((UINT4)input[j+3]) << 24);
    }
}

/* Encodes input (UINT4) into output (unsigned char). Assumes len is a multiple of 4. */
static void Encode(unsigned char *output, const UINT4 *input, unsigned int len)
{
    unsigned int i, j;
    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = (unsigned char)(input[i] & 0xff);
        output[j+1] = (unsigned char)((input[i] >> 8) & 0xff);
        output[j+2] = (unsigned char)((input[i] >> 16) & 0xff);
        output[j+3] = (unsigned char)((input[i] >> 24) & 0xff);
    }
}

/* Round 1 macro */
#define FF(a, b, c, d, x, s) { \
    (a) += F((b), (c), (d)) + (x); \
    (a) = ROTATE_LEFT((a), (s)); \
}

/* Round 2 macro */
#define GG(a, b, c, d, x, s) { \
    (a) += G((b), (c), (d)) + (x) + (UINT4)0x5a827999; \
    (a) = ROTATE_LEFT((a), (s)); \
}

/* Round 3 macro */
#define HH(a, b, c, d, x, s) { \
    (a) += H((b), (c), (d)) + (x) + (UINT4)0x6ed9eba1; \
    (a) = ROTATE_LEFT((a), (s)); \
}

/* line 173 */
static void MD4Transform(UINT4 *state, const unsigned char *block)
{
    UINT4 a, b, c, d;
    UINT4 x[16];

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];

    Decode(x, block, 64);

    /* Round 1 */
    FF(a, b, c, d, x[ 0],  3); /* line 180 */
    FF(d, a, b, c, x[ 1],  7); /* line 181 */
    FF(c, d, a, b, x[ 2], 11); /* line 182 */
    FF(b, c, d, a, x[ 3], 19); /* line 183 */
    FF(a, b, c, d, x[ 4],  3); /* line 184 */
    FF(d, a, b, c, x[ 5],  7); /* line 185 */
    FF(c, d, a, b, x[ 6], 11); /* line 186 */
    FF(b, c, d, a, x[ 7], 19); /* line 187 */
    FF(a, b, c, d, x[ 8],  3); /* line 188 */
    FF(d, a, b, c, x[ 9],  7); /* line 189 */
    FF(c, d, a, b, x[10], 11); /* line 190 */
    FF(b, c, d, a, x[11], 19); /* line 191 */
    FF(a, b, c, d, x[12],  3); /* line 192 */
    FF(d, a, b, c, x[13],  7); /* line 193 */
    FF(c, d, a, b, x[14], 11); /* line 194 */
    FF(b, c, d, a, x[15], 19); /* line 195 */

    /* Round 2 */
    GG(a, b, c, d, x[ 0],  3); /* line 198 */
    GG(d, a, b, c, x[ 4],  5); /* line 199 */
    GG(c, d, a, b, x[ 8],  9); /* line 200 */
    GG(b, c, d, a, x[12], 13); /* line 201 */
    GG(a, b, c, d, x[ 1],  3); /* line 202 */
    GG(d, a, b, c, x[ 5],  5); /* line 203 */
    GG(c, d, a, b, x[ 9],  9); /* line 204 */
    GG(b, c, d, a, x[13], 13); /* line 205 */
    GG(a, b, c, d, x[ 2],  3); /* line 206 */
    GG(d, a, b, c, x[ 6],  5); /* line 207 */
    GG(c, d, a, b, x[10],  9); /* line 208 */
    GG(b, c, d, a, x[14], 13); /* line 209 */
    GG(a, b, c, d, x[ 3],  3); /* line 210 */
    GG(d, a, b, c, x[ 7],  5); /* line 211 */
    GG(c, d, a, b, x[11],  9); /* line 212 */
    GG(b, c, d, a, x[15], 13); /* line 213 */

    /* Round 3 */
    HH(a, b, c, d, x[ 0],  3); /* line 216 */
    HH(d, a, b, c, x[ 8],  9); /* line 217 */
    HH(c, d, a, b, x[ 4], 11); /* line 218 */
    HH(b, c, d, a, x[12], 15); /* line 219 */
    HH(a, b, c, d, x[ 2],  3); /* line 220 */
    HH(d, a, b, c, x[10],  9); /* line 221 */
    HH(c, d, a, b, x[ 6], 11); /* line 222 */
    HH(b, c, d, a, x[14], 15); /* line 223 */
    HH(a, b, c, d, x[ 1],  3); /* line 224 */
    HH(d, a, b, c, x[ 9],  9); /* line 225 */
    HH(c, d, a, b, x[ 5], 11); /* line 226 */
    HH(b, c, d, a, x[13], 15); /* line 227 */
    HH(a, b, c, d, x[ 3],  3); /* line 228 */
    HH(d, a, b, c, x[11],  9); /* line 229 */
    HH(c, d, a, b, x[ 7], 11); /* line 230 */
    HH(b, c, d, a, x[15], 15); /* line 231 */

    state[0] += a; /* line 233 */
    state[1] += b; /* line 234 -- note: asm stores to *(&state[0]+4) i.e. state[1] */
    state[2] += c; /* line 235 */
    state[3] += d; /* line 236 */

    /* Zeroize sensitive information */
    Com_Memset((long int *)x, 0, 64); /* line 239 */
}

/* line 113 */
void MD4Update(MD4_CTX *context, const unsigned char *input, unsigned int inputLen)
{
    unsigned int i, index, partLen;

    /* Compute number of bytes mod 64 */
    index = (unsigned int)((context->count[0] >> 3) & 0x3F);

    /* Update number of bits */
    if ((context->count[0] += ((UINT4)inputLen << 3)) < ((UINT4)inputLen << 3)) {
        context->count[1]++;
    }
    context->count[1] += ((UINT4)inputLen >> 29);

    partLen = 64 - index;

    /* Transform as many times as possible */
    if (inputLen >= partLen) {
        Com_Memcpy((long int *)&context->buffer[index], (const long int *)input, partLen);
        MD4Transform(context->state, context->buffer);

        for (i = partLen; i + 63 < inputLen; i += 64) {
            MD4Transform(context->state, &input[i]);
        }
        index = 0;
    } else {
        i = 0;
    }

    /* Buffer remaining input */
    Com_Memcpy((long int *)&context->buffer[index], (const long int *)&input[i], inputLen - i);
}

/* line 148 */
void MD4Final(unsigned char *digest, MD4_CTX *context)
{
    unsigned char bits[8];
    unsigned int index, padLen;

    /* Save number of bits */
    Encode(bits, context->count, 8);

    /* Pad out to 56 mod 64 */
    index = (unsigned int)((context->count[0] >> 3) & 0x3f);
    padLen = (index < 56) ? (56 - index) : (120 - index);
    MD4Update(context, PADDING, padLen);

    /* Append length (before padding) */
    MD4Update(context, bits, 8);

    /* Store state in digest */
    Encode(digest, context->state, 16);

    /* Zeroize sensitive information */
    Com_Memset((long int *)context, 0, sizeof(MD4_CTX));
}

/* line 286 */
unsigned int Com_BlockChecksumKey(void *buffer, int length, int key)
{
    MD4_CTX ctx;
    unsigned int digest[4];

    /* MD4Init inline */
    ctx.count[0] = 0;
    ctx.count[1] = 0;
    ctx.state[0] = 0x67452301;
    ctx.state[1] = 0xefcdab89;
    ctx.state[2] = 0x98badcfe;
    ctx.state[3] = 0x10325476;

    MD4Update(&ctx, (const unsigned char *)&key, 4);
    MD4Update(&ctx, (const unsigned char *)buffer, length);
    MD4Final((unsigned char *)digest, &ctx);

    return digest[0] ^ digest[1] ^ digest[2] ^ digest[3];
}

/* line 270 */
unsigned int Com_BlockChecksum(const void *buffer, int length)
{
    MD4_CTX ctx;
    unsigned int digest[4];

    /* MD4Init inline */
    ctx.count[0] = 0;
    ctx.count[1] = 0;
    ctx.state[0] = 0x67452301;
    ctx.state[1] = 0xefcdab89;
    ctx.state[2] = 0x98badcfe;
    ctx.state[3] = 0x10325476;

    MD4Update(&ctx, (const unsigned char *)buffer, length);
    MD4Final((unsigned char *)digest, &ctx);

    return digest[0] ^ digest[1] ^ digest[2] ^ digest[3];
}
