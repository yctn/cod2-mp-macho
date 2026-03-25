#!/usr/bin/env python3
"""
Convert data.S (and parts of final_stubs.S) to C source files.
"""
import re
import sys
import struct
import os

STRINGS_C    = "/home/user/work/output/strings.c"
DATA_S       = "/home/user/work/output/data.S"
DATA_C       = "/home/user/work/output/data.c"
STUBS_S      = "/home/user/work/output/stubs/final_stubs.S"
MATERIAL_C   = "/home/user/work/output/stubs/material_tech_names.c"


# ---------------------------------------------------------------------------
# 1. Parse strings.c  →  { "str_XXXXXXXX": '"quoted string"' }
# ---------------------------------------------------------------------------
def load_string_map(path):
    """Return dict mapping str_XXXXXXXX → raw quoted string literal."""
    smap = {}
    # Match:  const char str_XXXXXXXX[] = "...";
    pat = re.compile(
        r'const\s+char\s+(str_[0-9a-fA-F]+)\[\]\s*=\s*("(?:[^"\\]|\\.)*"(?:\s*"(?:[^"\\]|\\.)*")*)\s*;'
    )
    with open(path, encoding="latin-1") as fh:
        for line in fh:
            m = pat.search(line)
            if m:
                name, val = m.group(1), m.group(2).strip()
                smap[name] = val
    return smap


# ---------------------------------------------------------------------------
# 2. Parse data.S  →  list of (name, size, lines)
# ---------------------------------------------------------------------------
def parse_data_s(path):
    """
    Yield (varname, declared_size, data_lines) for each .globl block.
    data_lines is a list of stripped directive strings.
    """
    blocks = []
    with open(path, encoding="latin-1") as fh:
        raw_lines = fh.readlines()

    i = 0
    n = len(raw_lines)

    while i < n:
        line = raw_lines[i].strip()

        # Look for .globl
        if line.startswith(".globl "):
            varname = line[len(".globl "):].strip()
            i += 1
            # Consume .type / .size / .align lines
            declared_size = None
            while i < n:
                l = raw_lines[i].strip()
                if l.startswith(".size "):
                    m = re.match(r'\.size\s+\S+,\s*(\d+)', l)
                    if m:
                        declared_size = int(m.group(1))
                    i += 1
                elif l.startswith(".type ") or l.startswith(".align "):
                    i += 1
                else:
                    break

            # Now look for varname: label
            label_pat = re.compile(r'^' + re.escape(varname) + r'\s*:')
            while i < n and not label_pat.match(raw_lines[i].strip()):
                i += 1
            i += 1  # skip the label line

            # Collect data lines until next .globl / .section / EOF
            data_lines = []
            while i < n:
                l = raw_lines[i].strip()
                if (l.startswith(".globl ")
                        or l.startswith(".section ")
                        or l.startswith(".type ")
                        or l.startswith(".size ")
                        or l.startswith(".align ")):
                    # Don't advance i — next outer loop iteration picks it up
                    break
                if l and not l.startswith("#") and not l.startswith("/*") and not l.startswith("*") and not l.startswith("*/"):
                    # Strip inline C-style comments for analysis but keep original
                    data_lines.append(l)
                i += 1

            blocks.append((varname, declared_size, data_lines))
        else:
            i += 1

    return blocks


# ---------------------------------------------------------------------------
# 3. Helper: check if a name is a valid C identifier
# ---------------------------------------------------------------------------
def is_valid_c_ident(name):
    return bool(re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', name))


# ---------------------------------------------------------------------------
# 4. Check if all data bytes are zero
# ---------------------------------------------------------------------------
def all_bytes_zero(data_lines, smap):
    """Return True if every byte contribution is 0x00."""
    for line in data_lines:
        # Strip comments first
        clean = re.sub(r'/\*.*?\*/', '', line).strip()
        if not clean:
            continue
        if clean.startswith(".long str_"):
            return False
        if clean.startswith(".long ") and not re.match(r'\.long\s+0x?0+\s*$', clean):
            # Check for pure zero
            m = re.match(r'\.long\s+(\d+)\s*$', clean)
            if m and int(m.group(1)) == 0:
                continue
            # .long 0
            if re.match(r'\.long\s+0\s*$', clean):
                continue
            return False
        if clean.startswith(".byte "):
            vals_str = clean[len(".byte "):]
            vals = [v.strip() for v in vals_str.split(",")]
            for v in vals:
                v = v.strip()
                if v:
                    try:
                        if int(v, 0) != 0:
                            return False
                    except ValueError:
                        return False
    return True


# ---------------------------------------------------------------------------
# 5. Check if all data lines are .long str_XXXXXXXX or .long 0 (null terminator)
# ---------------------------------------------------------------------------
def is_pure_string_pointer_array(data_lines):
    """
    Return True if every non-empty data line is either:
      .long str_XXXXXXXX
      .long 0            (null sentinel)
    """
    for line in data_lines:
        clean = re.sub(r'/\*.*?\*/', '', line).strip()
        if not clean:
            continue
        if re.match(r'\.long\s+str_[0-9a-fA-F]+\s*$', clean):
            continue
        if re.match(r'\.long\s+0\s*$', clean):
            continue
        return False
    return True


# ---------------------------------------------------------------------------
# 6. Expand a single data line into a list of (kind, value) tuples
#    kind: 'byte', 'str_ptr', 'sym_ptr', 'long_val'
# ---------------------------------------------------------------------------
def expand_line(line, smap):
    """
    Returns a list of items:
      ('byte', int)
      ('str_ptr', str_name)
      ('sym_ptr', sym_expr, comment)
      ('long_val', int)
    """
    clean = re.sub(r'/\*.*?\*/', '', line).strip()
    if not clean:
        return []

    if clean.startswith(".byte "):
        vals_str = clean[len(".byte "):]
        items = []
        for v in vals_str.split(","):
            v = v.strip()
            if v:
                try:
                    items.append(('byte', int(v, 0)))
                except ValueError:
                    items.append(('byte', 0))  # fallback
        return items

    if clean.startswith(".long "):
        rest = clean[len(".long "):].strip()
        # Check for str_ reference  (possibly with +offset)
        m = re.match(r'^(str_[0-9a-fA-F]+)(\+\d+)?\s*$', rest)
        if m:
            return [('str_ptr', m.group(1), m.group(2) or '')]

        # Pure decimal / hex number
        m = re.match(r'^(0x[0-9a-fA-F]+|\d+)\s*$', rest)
        if m:
            return [('long_val', int(m.group(1), 0))]

        # Symbol expression (symbol, symbol+offset, __mh_execute_header+N, etc.)
        return [('sym_ptr', rest, line)]

    return []


# ---------------------------------------------------------------------------
# 7. Render bytes as hex string with str pointers as comments
# ---------------------------------------------------------------------------
def render_byte_array(varname, declared_size, data_lines, smap):
    """
    Build the body of `unsigned char varname[N] = { ... };`.
    Str pointers → 0,0,0,0 with comment; sym pointers → 0,0,0,0 with comment;
    long values → little-endian bytes.
    """
    out_bytes = []  # list of strings like "0xab" or "/* ptr */ 0x00"

    for line in data_lines:
        clean = re.sub(r'/\*.*?\*/', '', line).strip()
        if not clean:
            continue
        items = expand_line(line, smap)
        for item in items:
            kind = item[0]
            if kind == 'byte':
                out_bytes.append(f"0x{item[1]:02x}")
            elif kind == 'str_ptr':
                str_name = item[1]
                offset_str = item[2]
                str_val = smap.get(str_name, f'/* unknown {str_name} */')
                label = f"/* ptr: {str_name}{offset_str} = {str_val} */"
                out_bytes.append(f"{label} 0x00")
                out_bytes.append("0x00")
                out_bytes.append("0x00")
                out_bytes.append("0x00")
            elif kind == 'sym_ptr':
                sym_expr = item[1]
                out_bytes.append(f"/* ptr: {sym_expr} */ 0x00")
                out_bytes.append("0x00")
                out_bytes.append("0x00")
                out_bytes.append("0x00")
            elif kind == 'long_val':
                val = item[1]
                bs = struct.pack('<I', val & 0xFFFFFFFF)
                for b in bs:
                    out_bytes.append(f"0x{b:02x}")

    if declared_size and len(out_bytes) < declared_size:
        # pad with zeros if needed (rare)
        for _ in range(declared_size - len(out_bytes)):
            out_bytes.append("0x00")

    size_expr = declared_size if declared_size else len(out_bytes)

    # Format into groups of 16 per row
    lines = []
    chunk = 16
    for i in range(0, len(out_bytes), chunk):
        row = out_bytes[i:i+chunk]
        lines.append("    " + ", ".join(row))

    body = ",\n".join(lines)
    return f"unsigned char {varname}[{size_expr}] = {{\n{body}\n}};"


# ---------------------------------------------------------------------------
# 8. Generate a single variable's C output
# ---------------------------------------------------------------------------
def gen_var(varname, declared_size, data_lines, smap):
    """Return C string for this variable, or None to skip."""

    if not is_valid_c_ident(varname):
        return f"/* skipped (not a valid C identifier): {varname} */\n"

    # No data lines → treat as zero-initialized
    if not data_lines:
        if declared_size:
            return f"static char {varname}[{declared_size}] = {{0}};"
        return f"/* empty: {varname} */"

    # Case A: pure string pointer array (with optional null terminator)
    if is_pure_string_pointer_array(data_lines):
        ptrs = []
        for line in data_lines:
            clean = re.sub(r'/\*.*?\*/', '', line).strip()
            if not clean:
                continue
            m = re.match(r'\.long\s+(str_[0-9a-fA-F]+)\s*$', clean)
            if m:
                ptrs.append(m.group(1))
            # .long 0 → null terminator, skip
        if len(ptrs) == 1:
            val = smap.get(ptrs[0], f'"{ptrs[0]}"')
            return f"const char *{varname} = {val};"
        else:
            items = []
            for p in ptrs:
                val = smap.get(p, f'"{p}"')
                items.append(f"    {val}")
            body = ",\n".join(items)
            return f"const char *{varname}[] = {{\n{body}\n}};"

    # Case B: all bytes zero
    if all_bytes_zero(data_lines, smap):
        if declared_size:
            return f"static char {varname}[{declared_size}] = {{0}};"
        return f"/* zero: {varname} */"

    # Case C: mixed / raw bytes
    return render_byte_array(varname, declared_size, data_lines, smap)


# ---------------------------------------------------------------------------
# 9. Main: generate data.c
# ---------------------------------------------------------------------------
def generate_data_c(smap, blocks):
    lines = []
    lines.append("/* Converted from data.S */")
    lines.append('#include "common_types.h"')
    lines.append("")

    for varname, declared_size, data_lines in blocks:
        c_code = gen_var(varname, declared_size, data_lines, smap)
        lines.append(c_code)
        lines.append("")

    return "\n".join(lines)


# ---------------------------------------------------------------------------
# 10. Generate stubs/material_tech_names.c
# ---------------------------------------------------------------------------
def generate_material_c(smap, stubs_s_path):
    """Parse the tech table and 'string' from final_stubs.S."""

    # Collect the .long str_XXXXXXXX lines from __ZZ29Material_TechniqueTypeForNamePKcE5C.359
    with open(stubs_s_path, encoding="latin-1") as fh:
        content = fh.read()

    # Find the block
    tech_block_match = re.search(
        r'__ZZ29Material_TechniqueTypeForNamePKcE5C\.359:\s*\n((?:.*\n)*?)(?=\.globl|\Z)',
        content
    )

    tech_ptrs = []
    if tech_block_match:
        block_text = tech_block_match.group(1)
        for m in re.finditer(r'\.long\s+(str_[0-9a-fA-F]+)', block_text):
            tech_ptrs.append(m.group(1))

    out = []
    out.append("/* Converted from stubs/final_stubs.S */")
    out.append('#include "common_types.h"')
    out.append("")

    # material technique name table
    # The original name has a dot so can't be a C identifier; use a safe alias
    out.append("/* __ZZ29Material_TechniqueTypeForNamePKcE5C.359 — dot in name, using safe alias */")
    if tech_ptrs:
        items = []
        for p in tech_ptrs:
            val = smap.get(p, f'/* unknown {p} */ ""')
            items.append(f"    {val}")
        body = ",\n".join(items)
        out.append(f"const char *Material_TechniqueNames[] = {{")
        out.append(body)
        out.append("};")
    else:
        out.append("/* WARNING: could not find technique table */")

    out.append("")
    out.append("/* 'string' global */")
    out.append("char string[1024] = {0};")
    out.append("")

    return "\n".join(out)


# ---------------------------------------------------------------------------
# 11. Check for unresolved str_ references
# ---------------------------------------------------------------------------
def check_unresolved(path):
    unresolved = []
    pat = re.compile(r'\bstr_[0-9a-fA-F]+\b')
    with open(path, encoding="latin-1") as fh:
        for lineno, line in enumerate(fh, 1):
            # Skip comment lines
            stripped = line.strip()
            if stripped.startswith("//") or stripped.startswith("/*") or stripped.startswith("*"):
                continue
            # Also skip lines where str_ appears only inside a comment
            # Remove block comments
            no_comments = re.sub(r'/\*.*?\*/', '', line)
            no_comments = re.sub(r'//.*', '', no_comments)
            if pat.search(no_comments):
                unresolved.append((lineno, line.rstrip()))
    return unresolved


# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------
def main():
    print("Loading string map from strings.c …")
    smap = load_string_map(STRINGS_C)
    print(f"  {len(smap)} strings loaded.")

    print("Parsing data.S …")
    blocks = parse_data_s(DATA_S)
    print(f"  {len(blocks)} global variables found.")

    print("Generating data.c …")
    data_c_content = generate_data_c(smap, blocks)

    with open(DATA_C, "w", encoding="utf-8") as fh:
        fh.write(data_c_content)
    print(f"  Written to {DATA_C}")

    print("Generating stubs/material_tech_names.c …")
    mat_c_content = generate_material_c(smap, STUBS_S)
    with open(MATERIAL_C, "w", encoding="utf-8") as fh:
        fh.write(mat_c_content)
    print(f"  Written to {MATERIAL_C}")

    # Check for unresolved str_ references in data.c
    print("\nChecking for unresolved str_ references in data.c …")
    unresolved = check_unresolved(DATA_C)
    if unresolved:
        print(f"  WARNING: {len(unresolved)} line(s) still contain str_ references:")
        for lineno, l in unresolved[:20]:
            print(f"    line {lineno}: {l}")
    else:
        print("  All str_ references resolved — none remain in output.")

    # Check material_tech_names.c
    print("\nChecking for unresolved str_ references in material_tech_names.c …")
    unresolved2 = check_unresolved(MATERIAL_C)
    if unresolved2:
        print(f"  WARNING: {len(unresolved2)} line(s) still contain str_ references:")
        for lineno, l in unresolved2[:20]:
            print(f"    line {lineno}: {l}")
    else:
        print("  All str_ references resolved — none remain in output.")

    print("\nDone.")


if __name__ == "__main__":
    main()
