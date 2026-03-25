#!/usr/bin/env python3
"""Scan data.c for embedded Mach-O pointer values (addresses in __DATA or __TEXT segments)."""

import re
import sys

DATA_C = "/home/user/decomp/output/data.c"

# Address ranges to detect (little-endian 4-byte values)
RANGES = [
    ("__DATA/BSS", 0x01000000, 0x01FFFFFF),
    ("__TEXT",     0x00100000, 0x002FFFFF),
]

def parse_data_c(path):
    """Parse all unsigned char NAME[SIZE] = { ... }; entries from data.c."""
    with open(path, 'r') as f:
        content = f.read()

    # Match entries that may span multiple lines
    # Pattern: unsigned char NAME[SIZE] = { byte_list };
    pattern = re.compile(
        r'unsigned\s+char\s+(\w+)\[(\d+)\]\s*=\s*\{([^}]+)\};',
        re.DOTALL
    )

    entries = []
    for m in pattern.finditer(content):
        name = m.group(1)
        size = int(m.group(2))
        byte_str = m.group(3)

        # Extract all hex byte values
        hex_values = re.findall(r'0x([0-9a-fA-F]{2})', byte_str)
        byte_data = bytes([int(h, 16) for h in hex_values])

        if len(byte_data) != size:
            print(f"WARNING: {name} declared size {size} but got {len(byte_data)} bytes", file=sys.stderr)

        entries.append((name, size, byte_data))

    return entries


def scan_for_pointers(entries):
    """Scan each entry for 4-byte aligned little-endian values in target ranges."""
    results = []

    for name, size, data in entries:
        # Check at every 4-byte aligned offset
        for offset in range(0, len(data) - 3, 4):
            val = int.from_bytes(data[offset:offset+4], 'little')

            for range_name, lo, hi in RANGES:
                if lo <= val <= hi:
                    results.append({
                        'var': name,
                        'var_size': size,
                        'offset': offset,
                        'value': val,
                        'range': range_name,
                        'bytes': data[offset:offset+4],
                    })
                    break  # Don't double-report

    return results


def main():
    entries = parse_data_c(DATA_C)
    print(f"Parsed {len(entries)} variable entries from data.c\n")

    results = scan_for_pointers(entries)

    if not results:
        print("No Mach-O pointer values found.")
        return

    print(f"Found {len(results)} embedded Mach-O pointer values:\n")
    print(f"{'Variable':<45} {'Offset':>6}  {'Value':>12}  {'Hex Bytes':<15}  {'Segment'}")
    print("-" * 100)

    for r in results:
        hex_bytes = ' '.join(f'{b:02x}' for b in r['bytes'])
        print(f"{r['var']:<45} {r['offset']:>6}  0x{r['value']:08x}  {hex_bytes:<15}  {r['range']}")

    # Summary by segment
    print(f"\n--- Summary ---")
    for range_name, lo, hi in RANGES:
        count = sum(1 for r in results if r['range'] == range_name)
        if count:
            print(f"  {range_name} (0x{lo:08x}-0x{hi:08x}): {count} pointers")

    # List unique variables affected
    unique_vars = sorted(set(r['var'] for r in results))
    print(f"\n{len(unique_vars)} unique variables affected:")
    for v in unique_vars:
        ptrs = [r for r in results if r['var'] == v]
        print(f"  {v} ({ptrs[0]['var_size']} bytes): {len(ptrs)} pointer(s)")
        for p in ptrs:
            print(f"    offset {p['offset']:4d}: 0x{p['value']:08x} ({p['range']})")


if __name__ == '__main__':
    main()
