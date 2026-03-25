#!/usr/bin/env python3
"""
Fix jump tables for the COD2 ELF port.

In the Mach-O binary, jump table entries contain hardcoded Mach-O code addresses.
When linked as ELF, these addresses are wrong, causing segfaults.

This script:
1. Finds all jmpl *SYMBOL+OFFSET(, %reg, 4) patterns in .c files
2. Reads the Mach-O binary to get the actual jump table entries
3. Maps each entry to a .L label in the containing function
4. Inserts missing labels into the function's inline asm
5. Creates local jump table definitions using those labels
6. Replaces the jmpl to use the local jump table
"""

import os
import re
import struct
import sys
from pathlib import Path
from collections import defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from decomp.macho_loader import MachOLoader
from decomp.stabs_parser import StabsParser
import capstone


def main():
    binary_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'binary.x86')
    output_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'output')

    print("Loading Mach-O binary...")
    loader = MachOLoader(binary_path)
    stabs = StabsParser(loader)

    text_sect = loader.section_by_name[('__TEXT', '__text')]
    text_start = text_sect.addr
    text_end = text_sect.end_addr
    print(f"TEXT section: 0x{text_start:08x} - 0x{text_end:08x}")

    # Build sorted function list for binary search
    func_list = sorted(stabs.all_functions, key=lambda f: f.addr)

    def find_func_containing(addr):
        """Find function containing a given address."""
        lo, hi = 0, len(func_list) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            f = func_list[mid]
            if addr < f.addr:
                hi = mid - 1
            elif addr >= f.addr + f.size:
                lo = mid + 1
            else:
                return f
        return None

    def is_code_addr(val):
        return text_start <= val < text_end

    # Capstone disassembler
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

    # Regex patterns
    jmpl_re = re.compile(r'"jmpl \*([\w.]+)\+(\d+)\(, %(\w+), 4\)\\n"')
    label_def_re = re.compile(r'"(\.Lf([0-9a-f]+)_([0-9a-f]+)):\\n"')
    instr_line_re = re.compile(r'^\s*"(.+?)\\n"')

    # Step 1: Scan all .c files for jmpl patterns
    print("\nScanning .c files for jmpl patterns...")
    pc_dir = os.path.join(output_dir, 'PC')

    # Collect per file: { filepath: [(line_no, symbol, offset, reg)] }
    file_jmpls = defaultdict(list)
    for root, dirs, files in os.walk(pc_dir):
        for fname in sorted(files):
            if not fname.endswith('.c'):
                continue
            fpath = os.path.join(root, fname)
            with open(fpath, 'r') as f:
                for i, line in enumerate(f):
                    m = jmpl_re.search(line)
                    if m:
                        file_jmpls[fpath].append((i, m.group(1), int(m.group(2)), m.group(3)))

    total_jmpls = sum(len(v) for v in file_jmpls.values())
    print(f"Found {total_jmpls} jump table references in {len(file_jmpls)} files")

    # Step 2: Process each file
    total_fixed = 0
    total_labels_added = 0
    warnings = []

    for fpath in sorted(file_jmpls.keys()):
        jmpls = file_jmpls[fpath]
        relpath = os.path.relpath(fpath, output_dir)
        print(f"\nProcessing {relpath}:")

        with open(fpath, 'r') as f:
            lines = f.readlines()

        # Find all inline asm blocks in the file
        # Each naked function has __asm__ __volatile__ ( ... );
        # Collect: asm_blocks = [(block_start_line, block_end_line)]
        # Also find labels and their addresses to build addr<->line mapping

        # Parse: for each asm block, collect the labels and instruction lines
        # A label like ".Lf5140e_0005142f:\n" tells us:
        #   - func_addr = 0x5140e
        #   - label_addr = 0x0005142f

        # Strategy: for each function containing a jmpl:
        # 1. Find all label definitions -> gives us (addr, line_no) anchors
        # 2. Disassemble the function from the binary
        # 3. Correlate labels to instructions to build a full addr<->line mapping
        # 4. Read jump table from binary, find target addrs, insert labels

        # First pass: find all asm blocks and their label definitions
        # An asm block: __asm__ __volatile__ ( ... );
        asm_blocks = []  # (asm_start, asm_end)
        i = 0
        while i < len(lines):
            if '__asm__' in lines[i] and '__volatile__' in lines[i]:
                asm_start = i
                # Find closing );
                depth = 0
                for j in range(i, len(lines)):
                    depth += lines[j].count('(') - lines[j].count(')')
                    if depth <= 0 and j > i:
                        asm_blocks.append((asm_start, j))
                        i = j + 1
                        break
                else:
                    i += 1
            else:
                i += 1

        # For each asm block, find which function it belongs to (from label prefixes)
        func_labels = defaultdict(list)  # func_addr -> [(label_addr, line_no, label_name)]
        block_func_addr = {}  # (asm_start, asm_end) -> func_addr

        # Also collect label references (not just definitions) for func_addr detection
        label_ref_re = re.compile(r'\.Lf([0-9a-f]+)_')

        for asm_start, asm_end in asm_blocks:
            # Find function addr from any label reference or definition in this block
            block_func_addr_val = None
            for li in range(asm_start, asm_end + 1):
                m = label_ref_re.search(lines[li])
                if m:
                    block_func_addr_val = int(m.group(1), 16)
                    break

            if block_func_addr_val is not None:
                block_func_addr[(asm_start, asm_end)] = block_func_addr_val
                # Collect label definitions
                for li in range(asm_start, asm_end + 1):
                    m = label_def_re.search(lines[li])
                    if m:
                        fa = int(m.group(2), 16)
                        if fa == block_func_addr_val:
                            label_name = m.group(1)
                            label_addr = int(m.group(3), 16)
                            func_labels[fa].append((label_addr, li, label_name))

        # Map each jmpl to its asm block -> function
        jmpl_func_map = {}  # jmpl_line -> func_addr
        jmpl_block_map = {}  # jmpl_line -> (asm_start, asm_end)
        for line_no, symbol, offset, reg in jmpls:
            for asm_start, asm_end in asm_blocks:
                if asm_start <= line_no <= asm_end:
                    if (asm_start, asm_end) in block_func_addr:
                        jmpl_func_map[line_no] = block_func_addr[(asm_start, asm_end)]
                        jmpl_block_map[line_no] = (asm_start, asm_end)
                    break

        # Group jmpls by function
        func_jmpls = defaultdict(list)
        for line_no, symbol, offset, reg in jmpls:
            if line_no in jmpl_func_map:
                func_jmpls[jmpl_func_map[line_no]].append((line_no, symbol, offset, reg))

        # Process each function
        label_insertions = defaultdict(list)  # line_no -> [label_names to insert before]
        line_replacements = {}  # line_no -> new_content
        jt_definitions = defaultdict(list)  # func_asm_end_line -> [(jt_label, entry_labels)]

        for func_addr, func_jmpl_list in func_jmpls.items():
            stabs_func = find_func_containing(func_addr)
            if stabs_func is None:
                print(f"  WARNING: No stabs function at 0x{func_addr:x}")
                continue

            # Disassemble the function
            code = loader.read_bytes(stabs_func.addr, stabs_func.size)
            disasm = list(md.disasm(code, stabs_func.addr))
            disasm_addr_set = {ins.address for ins in disasm}

            # Build addr -> instruction index
            addr_to_idx = {ins.address: i for i, ins in enumerate(disasm)}

            # Find the asm block for this function from pre-computed blocks
            # Use the first jmpl's block
            first_jmpl_line = func_jmpl_list[0][0]
            if first_jmpl_line not in jmpl_block_map:
                print(f"  WARNING: No asm block found for function at 0x{func_addr:x}")
                continue
            asm_start_line, asm_end_line = jmpl_block_map[first_jmpl_line]

            # Collect instruction lines (non-label asm lines) in the block
            instr_lines = []  # (line_no, text)
            for i in range(asm_start_line, asm_end_line + 1):
                m = instr_line_re.match(lines[i])
                if m:
                    text = m.group(1)
                    # Skip label-only lines
                    if re.match(r'^\.L\w+:$', text.strip()):
                        continue
                    # Skip empty lines or pure comments
                    if not text.strip():
                        continue
                    instr_lines.append((i, text))

            # Build addr<->line mapping using labels as anchors
            # Each label at (label_addr, label_line) tells us that the NEXT
            # instruction after the label is at label_addr.
            # But actually, the label IS at label_addr - the next instruction
            # after it in the disasm is also at label_addr.

            # Strategy: walk through instruction lines and disasm in parallel
            # Use labels to resync if needed.

            # Build a map from line_no to whether it's an instruction or label
            all_asm_items = []  # (line_no, 'label', addr) or (line_no, 'instr', text)
            for i in range(asm_start_line, asm_end_line + 1):
                m_label = label_def_re.search(lines[i])
                if m_label:
                    label_func = int(m_label.group(2), 16)
                    # Only use labels from this function as sync points
                    if label_func == func_addr:
                        laddr = int(m_label.group(3), 16)
                        all_asm_items.append((i, 'label', laddr))
                    continue
                m_instr = instr_line_re.match(lines[i])
                if m_instr:
                    text = m_instr.group(1).strip()
                    if text and not re.match(r'^\.L\w+:$', text):
                        all_asm_items.append((i, 'instr', text))

            # Now correlate: walk through all_asm_items and disasm together
            # Labels act as synchronization points
            addr_to_line = {}
            line_to_addr = {}

            disasm_ptr = 0  # current position in disasm list

            for item_idx, (line_no, item_type, item_val) in enumerate(all_asm_items):
                if item_type == 'label':
                    # This label corresponds to addr item_val
                    # Find this address in disasm
                    target_addr = item_val
                    if target_addr in addr_to_idx:
                        disasm_ptr = addr_to_idx[target_addr]
                elif item_type == 'instr':
                    # This instruction corresponds to disasm[disasm_ptr]
                    if disasm_ptr < len(disasm):
                        ins = disasm[disasm_ptr]
                        addr_to_line[ins.address] = line_no
                        line_to_addr[line_no] = ins.address
                        disasm_ptr += 1

            # Now process each jmpl in this function
            jt_counter = 0
            func_name = stabs_func.name.split('(')[0]  # rough cleanup
            # Try to get clean C func name
            for part in func_name.split('::'):
                func_name = part

            for (jmpl_line, symbol, offset, reg) in func_jmpl_list:
                # Get the Mach-O address of the jmpl instruction
                if jmpl_line not in line_to_addr:
                    # Try adjacent lines
                    found = False
                    for delta in range(-2, 3):
                        if jmpl_line + delta in line_to_addr:
                            jmpl_macho_addr = line_to_addr[jmpl_line + delta]
                            found = True
                            break
                    if not found:
                        print(f"  WARNING: Cannot find addr for jmpl at line {jmpl_line+1}")
                        continue
                else:
                    jmpl_macho_addr = line_to_addr[jmpl_line]

                # Find the jmpl in disasm and extract raw jump table address
                jmpl_idx = addr_to_idx.get(jmpl_macho_addr)
                if jmpl_idx is None:
                    print(f"  WARNING: jmpl addr 0x{jmpl_macho_addr:08x} not in disasm")
                    continue

                jmpl_ins = disasm[jmpl_idx]
                # Extract raw address from operand: "dword ptr [reg*4 + 0xADDR]"
                op_str = jmpl_ins.op_str
                addr_match = re.search(r'0x([0-9a-f]+)\]', op_str)
                if not addr_match:
                    print(f"  WARNING: Cannot extract JT addr from '{op_str}'")
                    continue
                jt_macho_addr = int(addr_match.group(1), 16)

                # Determine entry count
                # Look back for cmp instruction
                expected_count = None
                for back in range(1, min(6, jmpl_idx + 1)):
                    prev = disasm[jmpl_idx - back]
                    if prev.mnemonic == 'cmp':
                        cmp_match = re.search(r'0x([0-9a-f]+)$', prev.op_str)
                        if cmp_match:
                            expected_count = int(cmp_match.group(1), 16) + 1
                        else:
                            cmp_match = re.search(r', (\d+)$', prev.op_str)
                            if cmp_match:
                                expected_count = int(cmp_match.group(1)) + 1
                        break

                # Read entries — validate they point within the containing function
                func_start = stabs_func.addr
                func_end_addr = stabs_func.addr + stabs_func.size
                entries = []
                max_entries = expected_count if expected_count else 256
                for entry_idx in range(max_entries):
                    try:
                        val = loader.read_u32(jt_macho_addr + entry_idx * 4)
                    except:
                        break
                    if is_code_addr(val) and func_start <= val < func_end_addr:
                        entries.append(val)
                    elif expected_count and is_code_addr(val):
                        # Entry is valid code but outside function — trust cmp count
                        entries.append(val)
                    else:
                        break

                if not entries:
                    print(f"  WARNING: No valid entries at JT 0x{jt_macho_addr:08x}")
                    continue

                # If we have expected_count and got more, trim
                if expected_count and len(entries) > expected_count:
                    entries = entries[:expected_count]
                # If no expected_count, trim to only intra-function entries
                if not expected_count:
                    trimmed = []
                    for val in entries:
                        if func_start <= val < func_end_addr:
                            trimmed.append(val)
                        else:
                            break  # Stop at first out-of-function entry
                    entries = trimmed

                print(f"  jmpl *{symbol}+{offset}: JT at 0x{jt_macho_addr:08x}, "
                      f"{len(entries)} entries (func 0x{stabs_func.addr:x})")

                # Map entries to labels and find which need to be inserted
                entry_labels = []
                needed_labels = {}  # target_addr -> label_name
                for val in entries:
                    # Find which function contains this target
                    target_func = find_func_containing(val)
                    if target_func is None:
                        # Use the current function's addr as fallback
                        label = f'.Lf{stabs_func.addr:x}_{val:08x}'
                    else:
                        label = f'.Lf{target_func.addr:x}_{val:08x}'
                    entry_labels.append(label)
                    needed_labels[val] = label

                # Check which labels exist
                existing_labels = set()
                for _, _, lname in func_labels.get(func_addr, []):
                    existing_labels.add(lname)
                # Also check in all_asm_items for any labels we might have missed
                for i in range(asm_start_line, asm_end_line + 1):
                    m = re.search(r'"(\.L\w+):\\n"', lines[i])
                    if m:
                        existing_labels.add(m.group(1))

                # Insert missing labels
                missing_count = 0
                for target_addr, label_name in needed_labels.items():
                    if label_name in existing_labels:
                        continue
                    if target_addr in addr_to_line:
                        target_line = addr_to_line[target_addr]
                        label_insertions[target_line].append(label_name)
                        total_labels_added += 1
                        missing_count += 1
                    else:
                        # Target might be in a different function or unmapped
                        # Check if target is actually in this function
                        if stabs_func.addr <= target_addr < stabs_func.addr + stabs_func.size:
                            warnings.append(
                                f"  {relpath}: Cannot map 0x{target_addr:08x} to line "
                                f"in func at 0x{stabs_func.addr:x}")
                        else:
                            # Target is in a different function — the label needs to be
                            # in that other function's file. This is a cross-file reference.
                            target_func = find_func_containing(target_addr)
                            if target_func:
                                warnings.append(
                                    f"  {relpath}: JT entry 0x{target_addr:08x} is in "
                                    f"{target_func.name}, not current func")
                            else:
                                warnings.append(
                                    f"  {relpath}: JT entry 0x{target_addr:08x} not in any function")

                # Create jump table label and definition
                jt_label = f'.Ljt_{stabs_func.addr:x}_{jt_counter}'
                jt_counter += 1

                # Replace the jmpl line
                old_pattern = f'jmpl *{symbol}+{offset}(, %{reg}, 4)'
                new_pattern = f'jmpl *{jt_label}(, %{reg}, 4)'
                new_line = lines[jmpl_line].replace(old_pattern, new_pattern)
                if new_line == lines[jmpl_line]:
                    print(f"  WARNING: Failed to replace jmpl pattern at line {jmpl_line+1}")
                    print(f"    Looking for: {old_pattern}")
                    print(f"    In: {lines[jmpl_line].rstrip()}")
                    continue
                line_replacements[jmpl_line] = new_line

                # Store JT definition to add at end of asm block
                jt_definitions[asm_end_line].append((jt_label, entry_labels))

                total_fixed += 1

                if missing_count:
                    print(f"    Added {missing_count} labels, "
                          f"{len(existing_labels & set(needed_labels.values()))} existed")

        # Apply all edits
        if not line_replacements and not label_insertions and not jt_definitions:
            continue

        new_lines = []
        for i, line in enumerate(lines):
            # Insert labels before this instruction line
            if i in label_insertions:
                indent = re.match(r'^(\s*)', line).group(1)
                for label_name in label_insertions[i]:
                    new_lines.append(f'{indent}"{label_name}:\\n"\n')

            # Replace line if needed
            if i in line_replacements:
                new_lines.append(line_replacements[i])
            elif i in jt_definitions:
                # This is the ");" line — insert JT definitions BEFORE it
                indent = '        '
                for jt_label, entry_labels in jt_definitions[i]:
                    new_lines.append(f'{indent}".section .rodata\\n"\n')
                    new_lines.append(f'{indent}".balign 4\\n"\n')
                    new_lines.append(f'{indent}"{jt_label}:\\n"\n')
                    for elabel in entry_labels:
                        new_lines.append(f'{indent}".long {elabel}\\n"\n')
                    new_lines.append(f'{indent}".text\\n"\n')
                new_lines.append(line)
            else:
                new_lines.append(line)

        with open(fpath, 'w') as f:
            f.writelines(new_lines)
        print(f"  -> Updated {relpath}")

    print(f"\n{'='*60}")
    print(f"Total jump tables fixed: {total_fixed}")
    print(f"Total labels added: {total_labels_added}")
    if warnings:
        print(f"\nWarnings ({len(warnings)}):")
        for w in warnings[:20]:
            print(w)
        if len(warnings) > 20:
            print(f"  ... and {len(warnings)-20} more")


if __name__ == '__main__':
    main()
