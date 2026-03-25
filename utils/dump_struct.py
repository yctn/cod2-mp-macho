#!/usr/bin/env python3
"""Dump field offsets for specific structs from binary STABS debug info."""

import sys
import os
sys.path.insert(0, os.path.dirname(__file__))

from decomp.macho_loader import MachOLoader
from decomp.stabs_parser import StabsParser, StructType, TypeRef, ArrayType, PointerType, EnumType
from decomp.type_system import TypeResolver

BINARY = os.path.join(os.path.dirname(__file__), "binary.x86")

def type_to_str(t, resolver, depth=0):
    if depth > 5:
        return "..."
    resolved = resolver.stabs.resolve_type(t)
    name = resolver.stabs.get_type_name(t) if isinstance(t, TypeRef) else None
    if name:
        return name
    if isinstance(resolved, TypeRef):
        name2 = resolver.stabs.get_type_name(resolved)
        if name2:
            return name2
        return f"type({resolved.file_num},{resolved.type_id})"
    if isinstance(resolved, PointerType):
        inner = type_to_str(resolved.target, resolver, depth+1)
        return f"{inner} *"
    if isinstance(resolved, ArrayType):
        elem = type_to_str(resolved.elem_type, resolver, depth+1)
        count = resolved.high - resolved.low + 1
        return f"{elem}[{count}]"
    if isinstance(resolved, StructType):
        return f"struct(size={resolved.size})"
    if isinstance(resolved, EnumType):
        return "enum"
    return str(type(resolved).__name__)


def dump_struct(name, resolver):
    st = resolver._all_structs.get(name)
    if st is None:
        print(f"  *** NOT FOUND ***")
        return
    print(f"  Size: {st.size} bytes (0x{st.size:x})")
    for f in st.fields:
        byte_off = f.bit_offset // 8
        byte_size = f.bit_size // 8
        cu = resolver._all_structs_cu.get(name)
        tname = type_to_str(f.type, resolver)
        print(f"    +0x{byte_off:04x}  {f.name:40s}  ({tname}, {byte_size} bytes)")


def main():
    targets = sys.argv[1:] if len(sys.argv) > 1 else ["DxGlobals", "DxState", "cg_t"]

    loader = MachOLoader(BINARY)
    stabs = StabsParser(loader)
    resolver = TypeResolver(stabs)

    for name in targets:
        print(f"\n=== {name} ===")
        dump_struct(name, resolver)


if __name__ == "__main__":
    main()
