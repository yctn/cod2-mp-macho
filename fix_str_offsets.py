#!/usr/bin/env python3
"""Fix str_XXXX+N patterns in decompiled C files.

The decompiler resolved Mac addresses to str_XXXX+N where XXXX is the nearest
known string symbol. On Linux, strings are laid out differently, so str_XXXX+N
points to the wrong data. This script replaces each str_XXXX+N with the correct
str_YYYYYY symbol.

Strategy:
1. Parse strings.c to build mac_addr -> symbol name and text -> [symbols] maps
2. For each str_XXXX+N, compute target_addr = XXXX + N
3. If str_{target_addr} exists -> use it
4. Else, parse the comment on the same line for the expected string text
5. Find a matching str_ symbol with that text -> use it
6. If no match, create a new entry in strings.c
"""

import re
import os
import sys

STRINGS_FILE = "strings.c"

def parse_strings_file():
    """Parse strings.c to build mappings."""
    addr_to_sym = {}  # mac_addr_int -> symbol_name
    addr_to_text = {}  # mac_addr_int -> string_text
    text_to_syms = {}  # string_text -> [symbol_names]

    with open(STRINGS_FILE, 'r') as f:
        for line in f:
            # Match: const char str_XXXXXXXX[] = "..."; /* str_XXXXXXXX */
            m = re.match(r'const char (str_([0-9a-f]{8}))\[\] = "(.*?)";', line)
            if m:
                sym = m.group(1)
                addr = int(m.group(2), 16)
                text = m.group(3)
                addr_to_sym[addr] = sym
                addr_to_text[addr] = text
                if text not in text_to_syms:
                    text_to_syms[text] = []
                text_to_syms[text].append(sym)

    return addr_to_sym, addr_to_text, text_to_syms

def extract_comment_string(line):
    """Extract quoted string from a comment on the line."""
    # Look for /* "some string" */ or /* "some string" at end
    m = re.search(r'/\*\s*"((?:[^"\\]|\\.)*)"\s*\*/', line)
    if m:
        return m.group(1)
    # Also try: /* "string" */  or just /* "string"
    m = re.search(r'/\*\s*"((?:[^"\\]|\\.)*)"', line)
    if m:
        return m.group(1)
    return None

def fix_file(filepath, addr_to_sym, addr_to_text, text_to_syms, new_strings, dry_run=False):
    """Fix str_XXXX+N patterns in a single file."""
    with open(filepath, 'r', errors='replace') as f:
        content = f.read()

    # Pattern: str_XXXXXXXX+N (where N can be decimal or hex)
    pattern = re.compile(r'\bstr_([0-9a-f]{8})\+(\d+|0x[0-9a-fA-F]+)\b')

    changes = []

    def replace_match(m):
        base_addr = int(m.group(1), 16)
        offset_str = m.group(2)
        if offset_str.startswith('0x'):
            offset = int(offset_str, 16)
        else:
            offset = int(offset_str)

        target_addr = base_addr + offset
        old_ref = m.group(0)

        # Strategy 1: Direct address match
        if target_addr in addr_to_sym:
            new_ref = addr_to_sym[target_addr]
            changes.append((old_ref, new_ref, "direct"))
            return new_ref

        # Strategy 2: Check if we already created this string
        target_sym = f"str_{target_addr:08x}"
        if target_sym in [s[0] for s in new_strings]:
            changes.append((old_ref, target_sym, "created"))
            return target_sym

        return None  # Signal that we need context

    lines = content.split('\n')
    new_lines = []
    total_fixed = 0
    total_unfixed = 0

    for line in lines:
        matches = list(pattern.finditer(line))
        if not matches:
            new_lines.append(line)
            continue

        new_line = line
        for m in reversed(matches):  # Reverse to preserve positions
            base_addr = int(m.group(1), 16)
            offset_str = m.group(2)
            if offset_str.startswith('0x'):
                offset = int(offset_str, 16)
            else:
                offset = int(offset_str)

            target_addr = base_addr + offset
            old_ref = m.group(0)

            # Strategy 1: Direct address match
            if target_addr in addr_to_sym:
                new_ref = addr_to_sym[target_addr]
                new_line = new_line[:m.start()] + new_ref + new_line[m.end():]
                total_fixed += 1
                continue

            # Strategy 2: Already queued new string
            target_sym = f"str_{target_addr:08x}"
            found_in_new = False
            for ns in new_strings:
                if ns[0] == target_sym:
                    new_line = new_line[:m.start()] + target_sym + new_line[m.end():]
                    total_fixed += 1
                    found_in_new = True
                    break
            if found_in_new:
                continue

            # Strategy 3: Extract from comment
            comment_str = extract_comment_string(line)
            if comment_str and comment_str in text_to_syms:
                new_ref = text_to_syms[comment_str][0]
                new_line = new_line[:m.start()] + new_ref + new_line[m.end():]
                total_fixed += 1
                continue

            # Strategy 4: Create new string entry from comment
            if comment_str:
                new_strings.append((target_sym, comment_str))
                addr_to_sym[target_addr] = target_sym
                addr_to_text[target_addr] = comment_str
                if comment_str not in text_to_syms:
                    text_to_syms[comment_str] = []
                text_to_syms[comment_str].append(target_sym)
                new_line = new_line[:m.start()] + target_sym + new_line[m.end():]
                total_fixed += 1
                continue

            # Strategy 5: Try to find string by looking at Mac string table
            # Find the string that contains this address
            # Sort known addresses and find which string spans target_addr
            found = False
            for known_addr in sorted(addr_to_text.keys()):
                if known_addr > target_addr:
                    break
                known_text = addr_to_text[known_addr]
                known_end = known_addr + len(known_text) + 1  # +1 for null
                if known_addr <= target_addr < known_end:
                    # target_addr is within this string
                    str_offset = target_addr - known_addr
                    substr = known_text[str_offset:]
                    if substr and substr in text_to_syms:
                        new_ref = text_to_syms[substr][0]
                        new_line = new_line[:m.start()] + new_ref + new_line[m.end():]
                        total_fixed += 1
                        found = True
                        break
                    elif substr:
                        # Create new string for this substring
                        new_strings.append((target_sym, substr))
                        addr_to_sym[target_addr] = target_sym
                        addr_to_text[target_addr] = substr
                        if substr not in text_to_syms:
                            text_to_syms[substr] = []
                        text_to_syms[substr].append(target_sym)
                        new_line = new_line[:m.start()] + target_sym + new_line[m.end():]
                        total_fixed += 1
                        found = True
                        break

            if not found:
                total_unfixed += 1
                if not dry_run:
                    print(f"  UNFIXED: {old_ref} in {filepath}:{lines.index(line)+1}")

        new_lines.append(new_line)

    if total_fixed > 0 and not dry_run:
        with open(filepath, 'w', errors='replace') as f:
            f.write('\n'.join(new_lines))

    return total_fixed, total_unfixed

def main():
    dry_run = '--dry-run' in sys.argv

    print("Parsing strings.c...")
    addr_to_sym, addr_to_text, text_to_syms = parse_strings_file()
    print(f"  Found {len(addr_to_sym)} string symbols")

    # Find all C files with str_+offset patterns
    import subprocess
    result = subprocess.run(
        ['grep', '-rl', r'str_[0-9a-f]\+\+[0-9]', 'PC/'],
        capture_output=True, text=True, cwd='.'
    )
    files = [f.strip() for f in result.stdout.strip().split('\n') if f.strip()]
    print(f"  Found {len(files)} files with str_+offset patterns")

    new_strings = []  # (symbol_name, text) tuples for new entries
    total_fixed = 0
    total_unfixed = 0

    for filepath in sorted(files):
        fixed, unfixed = fix_file(filepath, addr_to_sym, addr_to_text, text_to_syms, new_strings, dry_run)
        if fixed > 0 or unfixed > 0:
            print(f"  {filepath}: {fixed} fixed, {unfixed} unfixed")
        total_fixed += fixed
        total_unfixed += unfixed

    # Add new strings to strings.c
    if new_strings and not dry_run:
        print(f"\nAdding {len(new_strings)} new string entries to strings.c...")
        with open(STRINGS_FILE, 'r') as f:
            content = f.read()

        # Find insertion point (before last line or at end)
        new_entries = []
        for sym, text in new_strings:
            # Escape the text for C string
            escaped = text.replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n')
            new_entries.append(f'const char {sym}[] = "{escaped}"; /* {sym} */')

        # Append to end of file
        if not content.endswith('\n'):
            content += '\n'
        content += '\n/* Added by fix_str_offsets.py */\n'
        content += '\n'.join(new_entries) + '\n'

        with open(STRINGS_FILE, 'w') as f:
            f.write(content)

    print(f"\nTotal: {total_fixed} fixed, {total_unfixed} unfixed, {len(new_strings)} new strings created")

if __name__ == '__main__':
    main()
