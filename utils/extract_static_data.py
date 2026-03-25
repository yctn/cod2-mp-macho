#!/usr/bin/env python3
"""Extract static const data from the original Mach-O binary for r_material_load_obj.c.
Emits an ASM data blob covering the full range of static arrays, with symbol labels."""

import struct

BINARY = "/home/user/prog/decomp/binary.x86"
OUTPUT = "/home/user/prog/decomp/output/PC/gfx_d3d/r_material_load_obj_data.h"

def vm_to_file(vmaddr):
    return vmaddr - 0x1000

def read_string_at(data, vmaddr):
    off = vm_to_file(vmaddr)
    if off < 0 or off >= len(data):
        return None
    end = data.index(b'\x00', off)
    try:
        return data[off:end].decode('ascii')
    except:
        return None

# All known symbol addresses for static arrays in r_material_load_obj.c
LABELS = {
    0x003307a0: "s_stateMapDstWireframeBitGroup",
    0x003307c0: "s_wireframeBitNames",
    0x003307e0: "s_stateMapDstStencilBitGroup",
    0x00330880: "s_stencilFuncBackBitNames",
    0x00330940: "s_stencilOpBackZFailBitNames",
    0x003309a0: "s_stencilOpBackFailBitNames",
    0x00330a00: "s_stencilFuncFrontBitNames",
    0x00330a60: "s_stencilOpFrontZFailBitNames",
    0x00330ac0: "s_stencilOpFrontFailBitNames",
    0x00330b20: "s_stencilOpFrontPassBitNames",
    0x00330b80: "s_stencilBitNames",
    0x00330ba0: "s_stateMapDstPolygonOffsetBitGroup",
    0x00330bc0: "s_polygonOffsetBitNames",
    0x00330be0: "s_stateMapDstFogBitGroup",
    0x00330c00: "s_fogBitNames",
    0x00330c20: "s_stateMapDstColorWriteBitGroup",
    0x00330c50: "s_colorWriteAlphaBitNames",
    0x00330c68: "s_colorWriteRgbBitNames",
    0x00330c80: "s_stateMapDstDepthWriteBitGroup",
    0x00330ca0: "s_depthWriteBitNames",
    0x00330cc0: "s_stateMapDstDepthTestBitGroup",
    0x00330ce0: "s_depthTestBitNames",
    0x00330d20: "s_stateMapDstCullFaceBitGroup",
    0x00330d40: "s_cullFaceBitNames",
    0x00330d60: "s_stateMapDstBlendFuncAlphaBitGroup",
    0x00330da0: "s_dstBlendAlphaBitNames",
    0x00330e20: "s_srcBlendAlphaBitNames",
    0x00330ee0: "s_stateMapDstBlendFuncRgbBitGroup",  # also s_blendOpAlphaBitNames
    0x00330f20: "s_dstBlendRgbBitNames",
    0x00330fa0: "s_srcBlendRgbBitNames",
    0x00331020: "s_blendOpRgbBitNames",
    0x00331060: "s_stateMapDstAlphaTestBitGroup",
    0x00331080: "s_alphaTestBitNames",
    0x003310c0: "s_stateMapSrcBitGroup",
    0x00331280: "s_codeSamplers",
    0x00331400: "s_lightGridSamplers",
    0x00331440: "s_lightSamplers",
    0x00331480: "s_lightmapSamplers",
    0x00331680: "s_codeConsts",
    0x00331cc0: "s_lightGridConsts",
    0x00331d20: "s_lightConsts",
    0x00331da0: "s_nearPlaneConsts",
    0x00331e00: "s_cameraConsts",
    0x00331e80: "s_defaultCodeConsts",
    0x00332040: "s_defaultCodeSamplers",
}

# String section range (for identifying string pointers)
CSTRING_START = 0x2157b8
CSTRING_END = 0x2157b8 + 0xa4f0c

def main():
    with open(BINARY, "rb") as f:
        data = f.read()

    # Find the full range to extract
    start_addr = min(LABELS.keys())
    # For end, we need the last symbol + its data
    # s_defaultCodeSamplers at 0x332040, 15 elements * 16 bytes = 240 bytes
    end_addr = 0x00332040 + 15 * 16  # = 0x332130

    # But we also need to include any unlabeled data between known symbols
    # (like the stencil sub-arrays at 0x330880-0x330b80)
    # Scan for pointers in the range that point to data within or near our range
    range_start = start_addr
    range_end = end_addr

    # First pass: find all internal pointer targets
    extra_labels = {}
    for addr in range(range_start, range_end, 4):
        off = vm_to_file(addr)
        val = struct.unpack_from("<I", data, off)[0]
        # If it points within the const section but not to a known label
        if 0x330000 <= val < 0x333000 and val not in LABELS and val not in extra_labels:
            # Check if any data is at this address (non-zero)
            voff = vm_to_file(val)
            if 0 <= voff < len(data):
                extra_labels[val] = f"_data_{val:08x}"
                # Extend range if needed
                if val < range_start:
                    range_start = val
                if val + 64 > range_end:  # assume at least 64 bytes
                    range_end = val + 256

    # Merge extra labels
    all_labels = dict(LABELS)
    all_labels.update(extra_labels)

    # Extend range_start to include all labels
    range_start = min(range_start, min(all_labels.keys()))

    # Also scan extended range for more internal pointers (second pass)
    for addr in range(range_start, range_end, 4):
        off = vm_to_file(addr)
        if off + 4 > len(data):
            break
        val = struct.unpack_from("<I", data, off)[0]
        if range_start <= val < range_end and val not in all_labels:
            all_labels[val] = f"_data_{val:08x}"

    print(f"Range: {range_start:#x} - {range_end:#x} ({range_end - range_start} bytes)")
    print(f"Labels: {len(all_labels)} ({len(LABELS)} known + {len(extra_labels)} discovered)")

    # Build set of string symbols we reference
    str_syms = set()

    # Generate output
    lines = []
    lines.append("/* Auto-generated static data for r_material_load_obj.c */")
    lines.append("/* Extracted from original Mach-O binary */")
    lines.append("/* Range: %#x - %#x */" % (range_start, range_end))
    lines.append("")
    lines.append('__asm__(')
    lines.append('    ".section .rodata\\n"')
    lines.append('    ".align 4\\n"')

    sorted_labels = sorted(all_labels.items())

    for addr in range(range_start, range_end, 4):
        # Check if there's a label at this address
        if addr in all_labels:
            name = all_labels[addr]
            if not name.startswith("_data_"):
                lines.append(f'    ".globl {name}\\n"')
            lines.append(f'    "{name}:\\n"')

        off = vm_to_file(addr)
        if off + 4 > len(data):
            lines.append(f'    ".long 0x00000000\\n"')
            continue

        val = struct.unpack_from("<I", data, off)[0]

        # Check if it's a pointer to a known label
        if val in all_labels:
            lines.append(f'    ".long {all_labels[val]}\\n"')
            continue

        # Check if it's a string pointer
        if CSTRING_START <= val < CSTRING_END:
            s = read_string_at(data, val)
            if s is not None and len(s) > 0:
                sym = f"str_{val:08x}"
                str_syms.add(sym)
                comment = s[:50].replace('"', '\\"')
                lines.append(f'    ".long {sym}\\n"  /* "{comment}" */')
                continue

        # Raw value
        lines.append(f'    ".long 0x{val:08x}\\n"')

    lines.append('    ".previous\\n"')
    lines.append(');')

    # Check which string symbols exist in strings.c
    with open("/home/user/prog/decomp/output/strings.c", "r") as f:
        strings_c = f.read()

    missing_strs = []
    for sym in sorted(str_syms):
        if sym not in strings_c:
            missing_strs.append(sym)

    if missing_strs:
        print(f"\nWARNING: {len(missing_strs)} string symbols not found in strings.c:")
        for s in missing_strs[:10]:
            addr = int(s[4:], 16)
            actual = read_string_at(data, addr)
            print(f"  {s} = \"{actual}\"")

    with open(OUTPUT, "w") as f:
        f.write("\n".join(lines) + "\n")

    print(f"\nGenerated {OUTPUT}")
    print(f"Total .long entries: {(range_end - range_start) // 4}")
    print(f"String references: {len(str_syms)}")

if __name__ == "__main__":
    main()
