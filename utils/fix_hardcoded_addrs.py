#!/usr/bin/env python3
"""
Fix hardcoded Mach-O addresses in manually-converted C functions.

Replaces patterns like *(int *)0x1220964 with *(int *)((char *)&cls + 4)
by resolving the address to the nearest known symbol + offset.
"""

import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from decomp.macho_loader import MachOLoader
from decomp.stabs_parser import StabsParser
from decomp.disasm import Disassembler
from decomp.type_system import TypeResolver
from decomp.asm_emit import AsmEmitter


def main():
    binary_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'binary.x86')
    output_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'output')

    print("Loading Mach-O binary...")
    loader = MachOLoader(binary_path)
    stabs = StabsParser(loader)
    disasm = Disassembler(loader, stabs)
    types = TypeResolver(stabs)
    emitter = AsmEmitter(loader, stabs, disasm, types)

    # Determine valid data address ranges (BSS, DATA, COMMON)
    data_ranges = []
    for seg in loader.segments:
        if seg.segname.strip('\0') == '__DATA':
            data_ranges.append((seg.vmaddr, seg.vmaddr + seg.vmsize))

    def is_data_addr(addr):
        """Check if address is in a data/BSS section (not code)."""
        for start, end in data_ranges:
            if start <= addr < end:
                return True
        return False

    def resolve_addr(addr):
        """Resolve a Mach-O address to symbol+offset."""
        if addr in emitter._addr_map:
            return emitter._addr_map[addr], 0

        # Try _resolve_nearest (may reject large offsets)
        nearest = emitter._resolve_nearest(addr)
        if nearest and '+' in nearest:
            parts = nearest.rsplit('+', 1)
            return parts[0], int(parts[1])
        elif nearest:
            return nearest, 0

        # Manual: find nearest symbol below
        best_addr = 0
        best_name = None
        for a, n in emitter._addr_map.items():
            if a <= addr and a > best_addr and is_data_addr(a):
                best_addr = a
                best_name = n
        if best_name and addr - best_addr < 0x400000:
            return best_name, addr - best_addr
        return None, 0

    # Pattern: *(type *)0xADDR  or  (type *)0xADDR
    # We need to match the full cast+deref pattern to replace correctly
    # Pattern 1: *(type *)0xADDR (dereference)
    deref_re = re.compile(r'\*\(([\w\s\*]+?)\s*\*\)\s*(0x[0-9a-fA-F]{5,8})\b')
    # Pattern 2: (type *)0xADDR (cast to pointer, not dereferenced)
    cast_re = re.compile(r'(?<!\*)\(([\w\s\*]+?)\s*\*\)\s*(0x[0-9a-fA-F]{5,8})\b')

    pc_dir = os.path.join(output_dir, 'PC')
    total_fixed = 0
    files_fixed = 0

    for root, dirs, files in os.walk(pc_dir):
        for fname in sorted(files):
            if not fname.endswith('.c'):
                continue
            fpath = os.path.join(root, fname)
            with open(fpath, 'r') as f:
                lines = f.readlines()

            file_fixes = 0
            new_lines = []
            in_asm = False

            for line in lines:
                # Track asm blocks
                if '__asm__' in line and '__volatile__' in line:
                    in_asm = True
                if in_asm:
                    if ');' in line and '"' not in line:
                        in_asm = False
                    new_lines.append(line)
                    continue

                # Skip lines that look like asm strings
                if '"' in line and ('\\n"' in line or '\\n\\t"' in line):
                    new_lines.append(line)
                    continue

                modified = line

                # Process dereferences: *(type *)0xADDR
                def replace_deref(m):
                    nonlocal file_fixes
                    cast_type = m.group(1).strip()
                    addr = int(m.group(2), 16)
                    if not is_data_addr(addr):
                        return m.group(0)
                    sym, offset = resolve_addr(addr)
                    if sym is None:
                        return m.group(0)
                    if offset == 0:
                        return f'*({cast_type} *)&{sym}'
                    else:
                        return f'*({cast_type} *)((char *)&{sym} + {offset})'

                modified = deref_re.sub(replace_deref, modified)

                # Process casts: (type *)0xADDR
                def replace_cast(m):
                    nonlocal file_fixes
                    cast_type = m.group(1).strip()
                    addr = int(m.group(2), 16)
                    if not is_data_addr(addr):
                        return m.group(0)
                    sym, offset = resolve_addr(addr)
                    if sym is None:
                        return m.group(0)
                    if offset == 0:
                        return f'({cast_type} *)&{sym}'
                    else:
                        return f'({cast_type} *)((char *)&{sym} + {offset})'

                modified = cast_re.sub(replace_cast, modified)

                if modified != line:
                    file_fixes += 1
                new_lines.append(modified)

            if file_fixes > 0:
                with open(fpath, 'w') as f:
                    f.writelines(new_lines)
                relpath = os.path.relpath(fpath, output_dir)
                print(f"  {relpath}: {file_fixes} fixes")
                total_fixed += file_fixes
                files_fixed += 1

    print(f"\nTotal: {total_fixed} fixes across {files_fixed} files")


if __name__ == '__main__':
    main()
