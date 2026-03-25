#!/usr/bin/env python3
"""
Convert data.c to data.S with proper symbol relocations.

The data.c file contains raw byte arrays extracted from Mach-O __DATA,__data.
Many of these contain embedded Mach-O absolute addresses (pointers to strings,
BSS variables, etc.) which are meaningless in the ELF build.

This script:
1. Parses all variable entries in data.c
2. Scans for 4-byte aligned values that are Mach-O addresses
3. Resolves each to the correct ELF symbol+offset using the emitter
4. Generates data.S with .long symbol+offset for pointers, .byte for data
"""

import os
import re
import sys
import struct

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from decomp.macho_loader import MachOLoader
from decomp.stabs_parser import StabsParser
from decomp.disasm import Disassembler
from decomp.type_system import TypeResolver
from decomp.asm_emit import AsmEmitter
from decomp.data_extract import DataExtractor


def main():
    binary_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'binary.x86')
    output_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'output')

    print("Loading Mach-O binary...")
    loader = MachOLoader(binary_path)
    stabs = StabsParser(loader)
    disasm = Disassembler(loader, stabs)
    types = TypeResolver(stabs)
    emitter = AsmEmitter(loader, stabs, disasm, types)

    # Get Mach-O address ranges
    text_start = text_end = 0
    data_start = data_end = 0
    for seg in loader.segments:
        segname = seg.segname.strip('\0')
        if segname == '__TEXT':
            text_start = seg.vmaddr
            text_end = seg.vmaddr + seg.vmsize
        elif segname == '__DATA':
            data_start = seg.vmaddr
            data_end = seg.vmaddr + seg.vmsize

    def is_macho_addr(val):
        """Check if a 32-bit value looks like a Mach-O address."""
        return (text_start <= val < text_end) or (data_start <= val < data_end)

    # Known false positive patterns (bitmask constants that look like addresses)
    false_positive_values = {
        0x01000000, 0x01100000, 0x01200000, 0x01300000,  # CONTENTS_* flags
        0x01400000, 0x01600000, 0x01800000,
        0x01ffffff,  # bitmask
        0x00FFFFFF, 0x00FFFFFE, 0x00FFFF00,  # RGB/color masks
        0x00FF0000, 0x00F00000,              # byte/nibble masks
        0x00800000, 0x00400000,              # bit flags
        0x007FFFFF, 0x003FFFFF,              # inverse masks
        0x00810011, 0x00820011, 0x00800811,  # trace mask constants
        0x00878000,                          # flags constant
        0x00480000,                          # D3D format constant
        0x00444E55,                          # ASCII "UND\0"
        0x01110000,                          # flags constant
    }

    # Build set of symbols that actually exist in the build (from strings.c)
    # Parse strings.c for defined symbol names
    strings_c_path = os.path.join(output_dir, 'strings.c')
    defined_str_syms = set()
    if os.path.exists(strings_c_path):
        with open(strings_c_path, 'r') as sf:
            for line in sf:
                m = re.match(r'const char (str_[0-9a-f]+)\[', line)
                if m:
                    defined_str_syms.add(m.group(1))
    print(f"  Loaded {len(defined_str_syms)} defined string symbols")

    # Build sorted list of defined string addresses for offset calculation
    defined_str_addrs = []
    for sym in defined_str_syms:
        addr_hex = sym[4:]  # strip 'str_'
        defined_str_addrs.append((int(addr_hex, 16), sym))
    defined_str_addrs.sort()

    import bisect
    def find_nearest_string(addr):
        """Find the nearest defined string symbol at or below addr."""
        idx = bisect.bisect_right(defined_str_addrs, (addr, '')) - 1
        if idx >= 0:
            base_addr, sym = defined_str_addrs[idx]
            if addr - base_addr < 0x10000:  # reasonable offset
                return sym, addr - base_addr
        return None, 0

    # Build a direct lookup from address to defined string symbol
    defined_str_addr_map = {}
    for sym in defined_str_syms:
        addr_hex = sym[4:]  # strip 'str_'
        defined_str_addr_map[int(addr_hex, 16)] = sym

    def resolve_addr(addr):
        """Resolve a Mach-O address to a symbol name and offset."""
        # First: check if this exactly matches a defined string symbol
        if addr in defined_str_addr_map:
            return defined_str_addr_map[addr], 0

        # Second: check if this is in the cstring range and find nearest string
        cstring_start = 0x2157b8  # __TEXT.__cstring range
        cstring_end = 0x2ba6c4
        if cstring_start <= addr < cstring_end:
            return find_nearest_string(addr)

        if addr in emitter._addr_map:
            sym = emitter._addr_map[addr]
            # Check if the symbol is actually defined
            if sym.startswith('str_') and sym not in defined_str_syms:
                # Mid-string pointer — find nearest defined string
                return find_nearest_string(addr)
            return sym, 0

        nearest = emitter._resolve_nearest(addr)
        if nearest and '+' in nearest:
            parts = nearest.rsplit('+', 1)
            sym = parts[0]
            off = int(parts[1])
            if sym.startswith('str_') and sym not in defined_str_syms:
                return find_nearest_string(addr)
            return sym, off
        elif nearest:
            if nearest.startswith('str_') and nearest not in defined_str_syms:
                return find_nearest_string(addr)
            return nearest, 0

        # Manual: find nearest symbol below
        best_addr = 0
        best_name = None
        for a, n in emitter._addr_map.items():
            if a <= addr and a > best_addr:
                best_addr = a
                best_name = n
        if best_name and addr - best_addr < 0x400000:
            if best_name.startswith('str_') and best_name not in defined_str_syms:
                return find_nearest_string(addr)
            return best_name, addr - best_addr
        return None, 0

    # Parse data.c (or data.c.bak if already renamed)
    data_c_path = os.path.join(output_dir, 'data.c')
    if not os.path.exists(data_c_path):
        data_c_path = data_c_path + '.bak'
    with open(data_c_path, 'r') as f:
        content = f.read()

    # Parse entries: find each variable declaration and read bytes directly
    # from the Mach-O binary instead of parsing hex from data.c
    # (The data.c hex parser had a bug with 1-digit hex matches near comments)
    header_re = re.compile(
        r'/\*\s*(\w+)\s*-\s*(\d+)\s*bytes?\s*\*/\s*\n'
        r'(?:const\s+)?unsigned\s+char\s+(\w+)\[(\d+)\]\s*=\s*\{'
    )

    # Build name→address map from symbol table and STABS
    sym_addr_map = loader.build_symbol_addr_map()
    name_to_addr = {}
    for addr, sym_name in sym_addr_map.items():
        linux_name = DataExtractor._linux_name(sym_name)
        name_to_addr[linux_name] = addr
    # Also check stabs globals
    for g in stabs.all_globals:
        if g.addr and g.name:
            linux_name = DataExtractor._linux_name(g.name)
            if linux_name not in name_to_addr:
                name_to_addr[linux_name] = g.addr

    entries = []
    for m in header_re.finditer(content):
        name = m.group(3)
        size = int(m.group(4))

        # Get the Mach-O address for this variable
        addr = name_to_addr.get(name)
        if addr and data_start <= addr < data_end:
            # Read bytes directly from the binary — guaranteed correct
            bytes_list = list(loader.read_bytes(addr, size))
        else:
            # Fallback: parse hex bytes from data.c (with fixed 2-digit regex)
            start = m.end()
            bytes_list = []
            pos = start
            while len(bytes_list) < size and pos < len(content):
                hex_m = re.search(r'0x([0-9a-fA-F]{2})', content[pos:pos+20])
                if hex_m:
                    bytes_list.append(int(hex_m.group(1), 16))
                    pos += hex_m.end()
                else:
                    pos += 1

        if len(bytes_list) != size:
            print(f"  WARNING: {name} expected {size} bytes, got {len(bytes_list)}")
        entries.append((name, size, bytes_list))

    print(f"Parsed {len(entries)} entries from data.c")

    # Certain variable names that contain integer bitmask data, not pointers.
    # These are struct arrays where some fields happen to have values in pointer range.
    bitmask_vars = set()

    # Generate data.S
    data_s_path = os.path.join(output_dir, 'data.S')
    total_ptrs = 0
    total_resolved = 0
    total_unresolved = 0

    with open(data_s_path, 'w') as f:
        f.write("/* Generated from data.c with Mach-O pointer relocations */\n")
        f.write("/* Do not edit manually - regenerate with fix_data_pointers.py */\n")
        f.write(".section .data\n\n")

        for name, size, bytes_list in entries:
            f.write(f".globl {name}\n")
            f.write(f".type {name}, @object\n")
            f.write(f".size {name}, {size}\n")
            f.write(f".align 4\n")
            f.write(f"{name}:\n")

            # Scan for pointers at 4-byte aligned offsets
            ptr_offsets = {}  # offset -> (symbol, sym_offset)

            for off in range(0, size - 3, 4):
                val = (bytes_list[off]
                       | (bytes_list[off+1] << 8)
                       | (bytes_list[off+2] << 16)
                       | (bytes_list[off+3] << 24))

                if val == 0:
                    continue
                if val in false_positive_values:
                    continue
                if not is_macho_addr(val):
                    continue

                sym, sym_off = resolve_addr(val)
                if sym is not None:
                    ptr_offsets[off] = (sym, sym_off)
                    total_ptrs += 1
                    total_resolved += 1
                else:
                    # Unresolved - could be false positive or missing symbol
                    total_unresolved += 1

            # Emit bytes, replacing pointer positions with .long symbol+offset
            off = 0
            pending_bytes = []

            def flush_bytes():
                nonlocal pending_bytes
                if pending_bytes:
                    # Emit in chunks of 16
                    for i in range(0, len(pending_bytes), 16):
                        chunk = pending_bytes[i:i+16]
                        hex_str = ', '.join(f'0x{b:02x}' for b in chunk)
                        f.write(f"    .byte {hex_str}\n")
                    pending_bytes = []

            while off < size:
                if off in ptr_offsets:
                    flush_bytes()
                    sym, sym_off = ptr_offsets[off]
                    if sym_off == 0:
                        f.write(f"    .long {sym}\n")
                    else:
                        f.write(f"    .long {sym}+{sym_off}\n")
                    off += 4
                else:
                    pending_bytes.append(bytes_list[off])
                    off += 1

            flush_bytes()
            f.write("\n")

    print(f"\nGenerated {data_s_path}")
    print(f"  Total pointer relocations: {total_resolved}")
    print(f"  Unresolved addresses: {total_unresolved}")

    # Rename data.c to data.c.bak (only if source was data.c, not already .bak)
    orig_c = os.path.join(output_dir, 'data.c')
    bak_path = orig_c + '.bak'
    if os.path.exists(orig_c) and not os.path.exists(bak_path):
        os.rename(orig_c, bak_path)
        print(f"  Renamed data.c -> data.c.bak")
    else:
        print(f"  data.c.bak already exists, not renaming")


if __name__ == '__main__':
    main()
