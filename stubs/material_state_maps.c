#include <stddef.h>
/* Material state map bit name tables for the renderer.
 * These were in the Mac binary's data section and stripped in refactors.
 * Reconstructed from D3D9 render state knowledge. */

typedef struct {
    const char *name;
    int bits;
} MtlStateMapBitName;

typedef struct {
    const char *name;
    const MtlStateMapBitName *bitNames;
    int stateBitsMask[2];
} MtlStateMapBitGroup;

/* Alpha test compare functions (D3DCMPFUNC) */
const MtlStateMapBitName s_alphaTestBitNames[] = {
    {"Always", 0x00},
    {"GE128", 0x10},
    {"GT0",   0x20},
    {NULL, 0}
};

/* Blend operations (D3DBLENDOP) */
const MtlStateMapBitName s_blendOpRgbBitNames[] = {
    {"Disable",     0x00},
    {"Add",         0x00},
    {"Subtract",    0x40},
    {"RevSubtract", 0x80},
    {"Min",         0xC0},
    {"Max",         0x100},
    {NULL, 0}
};

/* Source blend factors (D3DBLEND) */
const MtlStateMapBitName s_srcBlendRgbBitNames[] = {
    {"Zero",           0x000},
    {"One",            0x100},
    {"SrcColor",       0x200},
    {"InvSrcColor",    0x300},
    {"SrcAlpha",       0x400},
    {"InvSrcAlpha",    0x500},
    {"DestAlpha",      0x600},
    {"InvDestAlpha",   0x700},
    {"DestColor",      0x800},
    {"InvDestColor",   0x900},
    {"SrcAlphaSat",    0xA00},
    {NULL, 0}
};

/* Dest blend factors */
const MtlStateMapBitName s_dstBlendRgbBitNames[] = {
    {"Zero",           0x0000},
    {"One",            0x1000},
    {"SrcColor",       0x2000},
    {"InvSrcColor",    0x3000},
    {"SrcAlpha",       0x4000},
    {"InvSrcAlpha",    0x5000},
    {"DestAlpha",      0x6000},
    {"InvDestAlpha",   0x7000},
    {"DestColor",      0x8000},
    {"InvDestColor",   0x9000},
    {NULL, 0}
};

const MtlStateMapBitName s_blendOpAlphaBitNames[] = {
    {"Disable",     0x00},
    {"Add",         0x00},
    {"Subtract",    0x40},
    {"RevSubtract", 0x80},
    {"Min",         0xC0},
    {"Max",         0x100},
    {NULL, 0}
};

const MtlStateMapBitName s_srcBlendAlphaBitNames[] = {
    {"Disable",        0x000},
    {"Zero",           0x000},
    {"One",            0x100},
    {"SrcAlpha",       0x400},
    {"InvSrcAlpha",    0x500},
    {"DestAlpha",      0x600},
    {"InvDestAlpha",   0x700},
    {NULL, 0}
};

const MtlStateMapBitName s_dstBlendAlphaBitNames[] = {
    {"Zero",           0x0000},
    {"One",            0x1000},
    {"SrcAlpha",       0x4000},
    {"InvSrcAlpha",    0x5000},
    {"DestAlpha",      0x6000},
    {"InvDestAlpha",   0x7000},
    {NULL, 0}
};

/* Cull face modes */
const MtlStateMapBitName s_cullFaceBitNames[] = {
    {"None",  0x00},
    {"Back",  0x40},
    {"Front", 0x80},
    {NULL, 0}
};

/* Depth test */
const MtlStateMapBitName s_depthTestBitNames[] = {
    {"Disable",    0x00},
    {"Less",       0x10},
    {"LessEqual",  0x20},
    {"Equal",      0x30},
    {"Always",     0x40},
    {NULL, 0}
};

/* Depth write */
const MtlStateMapBitName s_depthWriteBitNames[] = {
    {"Enable",  0x04},
    {"Disable", 0x00},
    {NULL, 0}
};

/* Color write */
const MtlStateMapBitName s_colorWriteRgbBitNames[] = {
    {"Enable",  0x00},
    {"Disable", 0x01},
    {NULL, 0}
};

const MtlStateMapBitName s_colorWriteAlphaBitNames[] = {
    {"Enable",  0x00},
    {"Disable", 0x02},
    {NULL, 0}
};

/* Fog */
const MtlStateMapBitName s_fogBitNames[] = {
    {"Enable",      0x00},
    {"Disable",     0x01},
    {"passthrough", 0x00},
    {NULL, 0}
};

/* Polygon offset */
const MtlStateMapBitName s_polygonOffsetBitNames[] = {
    {"0",  0x00},
    {"1",  0x10},
    {"2",  0x20},
    {NULL, 0}
};

/* Wireframe */
const MtlStateMapBitName s_wireframeBitNames[] = {
    {"Disable", 0x00},
    {"Enable",  0x01},
    {"false", 0x00},
    {"true",  0x01},
    {NULL, 0}
};

/* Source condition bit groups for state map condition tests
 * Maps "mtlXxx" source names to their bit name tables.
 * Used by Material_ParseRuleSetConditionTest_impl (stride 0x10). */
const MtlStateMapBitGroup s_stateMapSrcBitGroup[] = {
    {"mtlAlphaTest",     s_alphaTestBitNames,      {0x30, 0}},
    {"mtlBlendOp",       s_blendOpRgbBitNames,     {0xC0, 0}},
    {"mtlSrcBlend",      s_srcBlendRgbBitNames,    {0xF00, 0}},
    {"mtlDestBlend",     s_dstBlendRgbBitNames,    {0xF000, 0}},
    {"mtlDepthTest",     s_depthTestBitNames,       {0x70, 0}},
    {"mtlDepthWrite",    s_depthWriteBitNames,      {0x04, 0}},
    {"mtlPolygonOffset", s_polygonOffsetBitNames,   {0x30, 0}},
    {"mtlCullFace",      s_cullFaceBitNames,        {0xC0, 0}},
    {NULL, NULL, {0, 0}}
};

/* Destination state map bit groups for Material_LoadPassStateMap */
const MtlStateMapBitGroup s_stateMapDstAlphaTestBitGroup[] = {
    {"alphaTest", s_alphaTestBitNames, {0x30, 0}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitGroup s_stateMapDstBlendFuncRgbBitGroup[] = {
    {"blendOp",   s_blendOpRgbBitNames,   {0xC0, 0}},
    {"srcBlend",  s_srcBlendRgbBitNames,   {0xF00, 0}},
    {"dstBlend",  s_dstBlendRgbBitNames,   {0xF000, 0}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitGroup s_stateMapDstBlendFuncAlphaBitGroup[] = {
    {"blendOp",   s_blendOpAlphaBitNames,  {0, 0xC0}},
    {"srcBlend",  s_srcBlendAlphaBitNames,  {0, 0xF00}},
    {"dstBlend",  s_dstBlendAlphaBitNames,  {0, 0xF000}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitGroup s_stateMapDstCullFaceBitGroup[] = {
    {"cullFace", s_cullFaceBitNames, {0xC0, 0}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitGroup s_stateMapDstDepthTestBitGroup[] = {
    {"depthTest", s_depthTestBitNames, {0x70, 0}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitGroup s_stateMapDstDepthWriteBitGroup[] = {
    {"depthWrite", s_depthWriteBitNames, {0x04, 0}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitGroup s_stateMapDstColorWriteBitGroup[] = {
    {"colorWriteRgb",   s_colorWriteRgbBitNames,   {0x01, 0}},
    {"colorWriteAlpha", s_colorWriteAlphaBitNames,  {0x02, 0}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitGroup s_stateMapDstFogBitGroup[] = {
    {"fog", s_fogBitNames, {0x01, 0}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitGroup s_stateMapDstPolygonOffsetBitGroup[] = {
    {"polygonOffset", s_polygonOffsetBitNames, {0x30, 0}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitName s_stencilModeBitNames[] = {
    {"Disable",     0x00},
    {"OneSided",    0x01},
    {"TwoSided",    0x02},
    {"passthrough", 0x00},
    {NULL, 0}
};
const MtlStateMapBitName s_stencilFuncBitNames[] = {
    {"Always",       0x00}, {"Never",        0x01}, {"Less",      0x02},
    {"Equal",        0x03}, {"LessEqual",    0x04}, {"Greater",   0x05},
    {"NotEqual",     0x06}, {"GreaterEqual", 0x07},
    {"Keep",         0x00}, {"Zero",         0x00}, {"Replace",   0x01},
    {"IncrSat",      0x02}, {"DecrSat",      0x03}, {"Invert",    0x04},
    {"Incr",         0x05}, {"Decr",         0x06},
    {"passthrough",  0x00},
    {NULL, 0}
};
const MtlStateMapBitGroup s_stateMapDstStencilBitGroup[] = {
    {"mode",    s_stencilModeBitNames,   {0, 0}},
    {"func1",   s_stencilFuncBitNames,   {0, 0}},
    {"pass1",   s_stencilFuncBitNames,   {0, 0}},
    {"fail1",   s_stencilFuncBitNames,   {0, 0}},
    {"zfail1",  s_stencilFuncBitNames,   {0, 0}},
    {"func2",   s_stencilFuncBitNames,   {0, 0}},
    {"pass2",   s_stencilFuncBitNames,   {0, 0}},
    {"fail2",   s_stencilFuncBitNames,   {0, 0}},
    {"zfail2",  s_stencilFuncBitNames,   {0, 0}},
    {NULL, NULL, {0, 0}}
};
const MtlStateMapBitGroup s_stateMapDstWireframeBitGroup[] = {
    {"wireframe", s_wireframeBitNames, {0x01, 0}},
    {NULL, NULL, {0, 0}}
};

/* State map bit groups - these define which ruleSetName maps to which bit names */
const MtlStateMapBitGroup s_mtlStateMapBitGroups[] = {
    {"alphaTest",       s_alphaTestBitNames,       {0x30, 0}},
    {"blendFunc",       s_srcBlendRgbBitNames,     {0xFF00, 0}},
    {"cullFace",        s_cullFaceBitNames,         {0xC0, 0}},
    {"depthTest",       s_depthTestBitNames,        {0x70, 0}},
    {"depthWrite",      s_depthWriteBitNames,       {0x04, 0}},
    {"colorWriteRgb",   s_colorWriteRgbBitNames,    {0x01, 0}},
    {"colorWriteAlpha", s_colorWriteAlphaBitNames,  {0x02, 0}},
    {NULL, NULL, {0, 0}}
};
