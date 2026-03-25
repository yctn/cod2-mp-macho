"""Type resolver and C header generator from STABS type information."""

from typing import Optional
from .stabs_parser import (
    StabsParser, StabsType, TypeRef, RangeType, PointerType, ReferenceType,
    ConstType, VolatileType, ArrayType, StructType, StructField, EnumType,
    FuncType, CrossRefType, SizedType, MethodType, TypeDef, CompilationUnit
)


# Map STABS range types to C primitive names
PRIMITIVE_MAP = {
    # Signed integer types
    ('int', '-2147483648', '2147483647'): 'int',
    ('long int', '-2147483648', '2147483647'): 'long',
    ('short int', '-32768', '32767'): 'short',
    ('char', '-128', '127'): 'char',
    ('signed char', '-128', '127'): 'signed char',
    ('long long int', '-0', '0'): 'long long',  # GCC2 range for 64-bit
    # Unsigned integer types
    ('unsigned int', '0', '4294967295'): 'unsigned int',
    ('unsigned long', '0', '4294967295'): 'unsigned long',
    ('long unsigned int', '0', '4294967295'): 'unsigned long',
    ('unsigned short', '0', '65535'): 'unsigned short',
    ('short unsigned int', '0', '65535'): 'unsigned short',
    ('unsigned char', '0', '255'): 'unsigned char',
    ('long long unsigned int', '0', '0'): 'unsigned long long',
    # Floating point (GCC2 encodes as range with special values)
    ('float', '4', '0'): 'float',
    ('double', '8', '0'): 'double',
    ('long double', '12', '0'): 'long double',
    # Boolean
    ('bool', '0', '1'): '_Bool',
    ('_Bool', '0', '1'): '_Bool',
    # Void
    ('void', '0', '0'): 'void',
}

# Register names for i386
REGISTER_NAMES = {
    0: 'eax', 1: 'ecx', 2: 'edx', 3: 'ebx',
    4: 'esp', 5: 'ebp', 6: 'esi', 7: 'edi',
}


def _sanitize_type_name(name: str) -> str:
    """Replace C++ template syntax with valid C identifiers.
    e.g. allocator<char> → allocator_char, FxMemMgr<Particle> → FxMemMgr_Particle"""
    if '<' not in name and '&' not in name:
        return name
    name = name.replace('<', '_').replace('>', '').replace(',', '_').replace('*', 'ptr').replace('&', 'ref').replace(' ', '')
    return name


class TypeResolver:
    def __init__(self, stabs: StabsParser):
        self.stabs = stabs
        self._cache: dict[tuple, str] = {}
        self._resolving: set[tuple] = set()  # cycle detection
        self._struct_names: dict[tuple, str] = {}  # type key -> struct tag name
        self._enum_names: dict[tuple, str] = {}
        self._typedef_names: dict[tuple, str] = {}
        self._all_structs: dict[str, StructType] = {}  # name -> struct
        self._all_structs_cu: dict[str, 'CompilationUnit'] = {}  # name -> originating CU
        self._all_enums: dict[str, EnumType] = {}
        self._all_typedefs: dict[str, tuple] = {}  # name -> (key, type_def, cu)
        self._forward_decls: set[str] = set()
        self._build_name_maps()

    @staticmethod
    def _is_anonymous_name(name: str) -> bool:
        """Check if a type name is compiler-generated/anonymous (e.g., $_, empty)."""
        if not name or not name.strip():
            return True
        if name.startswith('$_') or name.startswith('.$_'):
            return True
        return False

    @staticmethod
    def _resolve_cu_local(cu, key, stabs, depth=0):
        """Resolve a type through CU-local type_map instead of global all_types.
        This avoids TypeRef key collisions across CUs where the same key
        (file_num, type_id) maps to completely different types in different CUs."""
        if depth > 20 or key not in cu.type_map:
            return None
        cur = cu.type_map[key]
        if isinstance(cur, TypeRef):
            k = (cur.file_num, cur.type_id)
            if k == key:
                return None
            return TypeResolver._resolve_cu_local(cu, k, stabs, depth + 1)
        return cur

    def _build_name_maps(self):
        """Build maps from type keys to their names.
        Prefer standard C type names over library-specific typedefs.
        Filters out anonymous/compiler-generated type names.

        IMPORTANT: Struct/enum bodies are resolved through cu.type_map (CU-local)
        rather than stabs.resolve_type() (global) to avoid TypeRef collisions.
        Different CUs reuse the same TypeRef keys for completely different types
        (e.g., JPEG, DirectX, LARGE_INTEGER types colliding with game types).
        CU-local resolution always gives the correct field names."""
        # Standard C type names that should be preferred
        std_names = {
            'int', 'char', 'short', 'long', 'float', 'double', 'void',
            'unsigned int', 'unsigned char', 'unsigned short', 'unsigned long',
            'signed char', 'short int', 'long int', 'long long int',
            'short unsigned int', 'long unsigned int', 'long long unsigned int',
            'bool', '_Bool',
        }
        # Build per-CU type name caches and anonymous type maps
        for cu in self.stabs.compilation_units:
            cu._type_name_cache = {}
            cu._anon_struct_types = {}  # anon name -> StructType (for $_XXXX unions/structs)
            for td in cu.types:
                if td.name and not self._is_anonymous_name(td.name):
                    cu._type_name_cache[(td.file_num, td.type_id)] = _sanitize_type_name(td.name)
                elif td.name and self._is_anonymous_name(td.name):
                    # Register anonymous struct/union types so they can be
                    # inlined when referenced from struct fields
                    if isinstance(td.type_def, StructType) and td.type_def.fields:
                        cu._anon_struct_types[td.name] = td.type_def

        _tag_struct_names = set()  # struct names from tag entries (trustworthy)
        _tag_enum_names = set()
        for cu in self.stabs.compilation_units:
            for td in cu.types:
                key = (td.file_num, td.type_id)
                if td.name and not self._is_anonymous_name(td.name):
                    sname = _sanitize_type_name(td.name)
                    # Resolve through CU-local type_map to avoid cross-CU
                    # TypeRef collisions.  Fall back to global only if
                    # the CU doesn't have a local definition.
                    resolved = self._resolve_cu_local(cu, key, self.stabs)
                    if resolved is None:
                        resolved = self.stabs.resolve_type(td.type_def)
                    if isinstance(resolved, StructType):
                        if td.is_tag:
                            _tag_struct_names.add(sname)
                            # Prefer LARGEST definition (most complete type).
                            # With CU-local resolution, field counts are now
                            # accurate (no JPEG/DirectX pollution inflating
                            # counts), so "prefer largest" works correctly.
                            if sname not in self._all_structs:
                                self._struct_names[key] = sname
                                self._all_structs[sname] = resolved
                                self._all_structs_cu[sname] = cu
                            else:
                                self._struct_names[key] = sname
                                existing = self._all_structs[sname]
                                new_n = len(resolved.fields)
                                old_n = len(existing.fields)
                                if new_n > old_n:
                                    self._all_structs[sname] = resolved
                                    self._all_structs_cu[sname] = cu
                        else:
                            self._typedef_names[key] = sname
                    elif isinstance(resolved, EnumType):
                        if td.is_tag:
                            _tag_enum_names.add(sname)
                            if sname not in self._all_enums:
                                self._enum_names[key] = sname
                                self._all_enums[sname] = resolved
                            else:
                                self._enum_names[key] = sname
                        else:
                            self._typedef_names[key] = sname
                    else:
                        # For non-struct/enum types, prefer standard names
                        existing = self._typedef_names.get(key)
                        if existing in std_names:
                            continue  # Don't override a standard name
                        if td.name in std_names:
                            self._typedef_names[key] = td.name
                        elif existing is None:
                            self._typedef_names[key] = sname

        # Build typedef map: resolve each typedef within its originating CU
        # to avoid cross-CU type pollution. Keep first definition only.
        # Also collect typedef→struct/enum aliases (e.g., typedef struct msg_s msg_t;)
        # and register inline anonymous struct/enum typedefs as named definitions.
        self._typedef_struct_aliases: dict[str, str] = {}  # alias_name → struct_name
        self._typedef_enum_aliases: dict[str, str] = {}  # alias_name → enum_name
        # Names that must not be registered as new structs/enums
        _reserved_names = {
            'int', 'char', 'short', 'long', 'float', 'double', 'void',
            'unsigned', 'signed', 'const', 'volatile', 'struct', 'union', 'enum',
            'byte', 'word', 'dword', 'qboolean', 'qbyte', 'BOOL', '_Bool', 'bool',
            'size_t', 'wchar_t', 'ptrdiff_t', 'ssize_t', 'off_t', 'time_t', 'pid_t',
            'FILE', 'fpos_t', 'div_t', 'ldiv_t', 'index', 'send', 'time',
            'int8_t', 'int16_t', 'int32_t', 'int64_t',
            'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t',
            'intptr_t', 'uintptr_t', 'boolean',
            'fd_set', 'pthread_mutex_t', 'pthread_t',
        }
        for cu in self.stabs.compilation_units:
            for td in cu.types:
                if td.name and not td.is_tag and not self._is_anonymous_name(td.name):
                    key = (td.file_num, td.type_id)
                    cu_resolved = self._resolve_cu_local(cu, key, self.stabs)
                    # For struct/enum registration, use CU-local resolution ONLY
                    # to avoid TypeRef collision pollution. For non-struct/enum
                    # typedefs, allow global fallback.
                    resolved = cu_resolved
                    if resolved is None:
                        # Check if type_def itself is a direct struct/enum (inline)
                        if isinstance(td.type_def, (StructType, EnumType)):
                            resolved = td.type_def
                        else:
                            resolved = self.stabs.resolve_type(td.type_def)
                    sname = _sanitize_type_name(td.name)
                    if sname in _reserved_names or ' ' in sname:
                        continue
                    if isinstance(resolved, StructType):
                        # This is a typedef to a struct. Two cases:
                        # 1) typedef struct X_s X_t — there's a tag name to alias
                        # 2) typedef struct { ... } X_t — anonymous struct, need to register as named
                        struct_tag = None
                        if isinstance(td.type_def, TypeRef):
                            tkey = (td.type_def.file_num, td.type_def.type_id)
                            # Look for a TAG entry at this key in the SAME CU.
                            # Must be a tag (is_tag=True) to avoid TypeRef collision.
                            # Do NOT use global _struct_names — it's polluted across CUs.
                            for other_td in cu.types:
                                if other_td.is_tag and not self._is_anonymous_name(other_td.name):
                                    if (other_td.file_num, other_td.type_id) == tkey:
                                        candidate = _sanitize_type_name(other_td.name)
                                        if candidate != sname:
                                            struct_tag = candidate
                                            break
                        # Heuristic fallback: if name ends in _t, check for _s struct
                        if not struct_tag and sname.endswith('_t'):
                            s_variant = sname[:-2] + '_s'
                            if s_variant in self._all_structs:
                                struct_tag = s_variant
                        if struct_tag:
                            struct_tag = _sanitize_type_name(struct_tag)
                            if struct_tag in self._all_structs and sname not in self._typedef_struct_aliases:
                                self._typedef_struct_aliases[sname] = struct_tag
                        else:
                            # No separate tag — anonymous struct typedef.
                            # Register the struct under the typedef name.
                            # Include empty structs (0 fields = opaque/forward-declared)
                            # so the type name is available for pointer params.
                            if sname not in self._all_structs:
                                self._all_structs[sname] = resolved
                                self._all_structs_cu[sname] = cu
                            elif sname in self._all_structs:
                                # Already registered — possibly prefer larger definition
                                existing = self._all_structs[sname]
                                if len(resolved.fields) > len(existing.fields):
                                    self._all_structs[sname] = resolved
                                    self._all_structs_cu[sname] = cu
                        continue
                    if isinstance(resolved, EnumType):
                        enum_tag = None
                        if isinstance(td.type_def, TypeRef):
                            ekey = (td.type_def.file_num, td.type_def.type_id)
                            # Look for a TAG entry at this key in the SAME CU
                            for other_td in cu.types:
                                if other_td.is_tag and not self._is_anonymous_name(other_td.name):
                                    if (other_td.file_num, other_td.type_id) == ekey:
                                        candidate = _sanitize_type_name(other_td.name)
                                        if candidate != sname:
                                            enum_tag = candidate
                                            break
                        # Heuristic: check for _e or same-name enum
                        if not enum_tag and sname.endswith('_t'):
                            e_variant = sname[:-2] + '_e'
                            if e_variant in self._all_enums:
                                enum_tag = e_variant
                        if enum_tag:
                            enum_tag = _sanitize_type_name(enum_tag)
                            if enum_tag in self._all_enums and sname not in self._typedef_enum_aliases:
                                self._typedef_enum_aliases[sname] = enum_tag
                        else:
                            # No separate tag — anonymous enum typedef.
                            # Register under the typedef name.
                            if sname not in self._all_enums:
                                self._all_enums[sname] = resolved
                        continue
                    if sname not in self._all_typedefs:
                        self._all_typedefs[sname] = (key, td.type_def, cu)

        # Clean up false struct/enum registrations: typedef entries that
        # resolved to StructType/EnumType due to CU-local TypeRef collisions
        # (e.g., BYTE→jpeg_common_struct) but are actually scalar typedefs.
        # If a name was NOT registered from a real tag entry AND has a simple
        # typedef definition, the struct/enum registration is pollution.
        for name in list(self._all_structs.keys()):
            if name not in _tag_struct_names and name in self._all_typedefs:
                del self._all_structs[name]
                self._all_structs_cu.pop(name, None)
        for name in list(self._all_enums.keys()):
            if name not in _tag_enum_names and name in self._all_typedefs:
                del self._all_enums[name]

        # typedef→struct map is built later from generated typedef lines
        # (avoids CU pollution in the STABS type chains)
        self._typedef_to_struct: dict[str, str] = {}

    def type_to_c(self, t: StabsType, name: str = '', visited: Optional[set] = None,
                  cu=None) -> str:
        """Convert a STABS type to a C type string.
        If name is provided, returns the declaration form (e.g., 'int x').
        If cu is provided, resolve types through the CU's local type map first."""
        if visited is None:
            visited = set()

        if t is None:
            return f'int {name}'.strip() if name else 'int'

        result = self._type_to_c_inner(t, name, visited, cu)
        return result

    def _type_to_c_inner(self, t: StabsType, name: str, visited: set,
                         cu=None) -> str:
        if isinstance(t, TypeRef):
            key = (t.file_num, t.type_id)
            # Try CU-local type name cache first (avoids cross-CU pollution)
            if cu and hasattr(cu, '_type_name_cache'):
                cu_name = cu._type_name_cache.get(key)
                if cu_name and not self._is_anonymous_name(cu_name):
                    return f'{cu_name} {name}'.strip() if name else cu_name
            # Try CU-local type map if available - this takes priority over
            # global maps to prevent cross-CU type pollution (e.g., JPEG
            # types appearing in non-JPEG code)
            if cu and key in cu.type_map:
                cu_type = cu.type_map[key]
                # Resolve through the CU's definition (skip global name maps)
                if key not in visited:
                    visited.add(key)
                    return self._type_to_c_inner(cu_type, name, visited, cu)
            # When CU is provided but doesn't own this type (not in name cache
            # or type_map), resolve through actual type structure before
            # global name maps.  Global name maps are polluted across CUs —
            # the same TypeRef key means different types in different CUs.
            # The type structure (all_types) gives the correct KIND (array,
            # pointer, func-ptr) even if inner names may differ.
            if cu and key not in visited:
                has_cu_name = (hasattr(cu, '_type_name_cache')
                               and key in cu._type_name_cache)
                if not has_cu_name:
                    resolved = self.stabs.all_types.get(key)
                    # Skip StructType — inline struct rendering would be ugly,
                    # global name maps are better for named structs
                    if resolved and not isinstance(resolved, StructType):
                        visited.add(key)
                        return self._type_to_c_inner(resolved, name, visited, cu)
            # Fall through to global maps (used when no CU, or CU owns the type,
            # or all_types has a StructType)
            tname = self._typedef_names.get(key)
            if tname and not self._is_anonymous_name(tname):
                return f'{tname} {name}'.strip() if name else tname
            tname = self._struct_names.get(key)
            if tname and not self._is_anonymous_name(tname):
                tag = f'struct {tname}'
                return f'{tag} {name}'.strip() if name else tag
            tname = self._enum_names.get(key)
            if tname and not self._is_anonymous_name(tname):
                tag = f'enum {tname}'
                return f'{tag} {name}'.strip() if name else tag
            # Check type name from stabs (skip anonymous)
            tname = self.stabs.type_names.get(key)
            if tname and not self._is_anonymous_name(tname):
                return f'{tname} {name}'.strip() if name else tname
            # Resolve
            if key in visited:
                return f'void {name}'.strip() if name else 'void'
            visited.add(key)
            resolved = self.stabs.all_types.get(key)
            if resolved:
                return self._type_to_c_inner(resolved, name, visited, cu)
            return f'int {name}'.strip() if name else 'int'

        if isinstance(t, RangeType):
            # Empty range bounds = type alias, resolve through base type
            if t.low == '' and t.high == '':
                base_key = t.base
                base_ref = TypeRef(base_key[0], base_key[1])
                if base_key not in visited:
                    return self._type_to_c_inner(base_ref, name, visited, cu)
            # Use CU-local name first for the base type
            tname = None
            if cu and hasattr(cu, '_type_name_cache'):
                tname = cu._type_name_cache.get(t.base)
            if not tname:
                tname = self.stabs.type_names.get(t.base)
            # Look up in primitive map
            for (pname, plo, phi), ctype in PRIMITIVE_MAP.items():
                if t.low == plo and t.high == phi:
                    if tname and tname == pname:
                        return f'{ctype} {name}'.strip() if name else ctype
                    if not tname:
                        return f'{ctype} {name}'.strip() if name else ctype
            # Fallback: check the name associated with the base type
            if tname and not self._is_anonymous_name(tname):
                for (pname, plo, phi), ctype in PRIMITIVE_MAP.items():
                    if pname == tname:
                        return f'{ctype} {name}'.strip() if name else ctype
                return f'{tname} {name}'.strip() if name else tname
            # Resolve the base type directly through CU
            if cu:
                base_key = t.base
                if base_key in cu.type_map and base_key not in visited:
                    visited.add(base_key)
                    return self._type_to_c_inner(cu.type_map[base_key], name, visited, cu)
            return f'int {name}'.strip() if name else 'int'

        if isinstance(t, PointerType):
            # Resolve target type to check for special cases
            resolved_target = t.target
            if isinstance(resolved_target, TypeRef):
                tkey = (resolved_target.file_num, resolved_target.type_id)
                if cu and tkey in cu.type_map:
                    resolved_target = self.stabs.resolve_type(cu.type_map[tkey])
                elif tkey in self.stabs.all_types:
                    resolved_target = self.stabs.resolve_type(self.stabs.all_types[tkey])
            # Pointer to function: ret (*name)()
            if isinstance(resolved_target, FuncType):
                # Check if return type resolves to an array (invalid in C)
                ret_resolved = resolved_target.return_type
                if isinstance(ret_resolved, TypeRef):
                    rkey = (ret_resolved.file_num, ret_resolved.type_id)
                    if cu and rkey in cu.type_map:
                        ret_resolved = self.stabs.resolve_type(cu.type_map[rkey])
                    elif rkey in self.stabs.all_types:
                        ret_resolved = self.stabs.resolve_type(self.stabs.all_types[rkey])
                if isinstance(ret_resolved, ArrayType):
                    # Can't return array from function — use void *
                    if name:
                        return f'void *(*{name})()'
                    return 'void *(*)()'
                ret = self._type_to_c_inner(resolved_target.return_type, '', visited, cu)
                # Sanitize: bare 'enum'/'struct' or complex nested func ptr → simplify
                if ret in ('enum', 'struct', 'union'):
                    ret = 'int'
                if '(*)' in ret:
                    # Nested function pointer return type — too complex for C declarator
                    ret = 'void *'
                # Check for array typedef as return type (e.g., vec3_t = float[3])
                if '[' in ret:
                    ret = 'void *'
                # Also check known array typedef names (e.g., vec3_t is float[3])
                if hasattr(self, '_array_typedef_names') and ret in self._array_typedef_names:
                    ret = 'void *'
                if name:
                    return f'{ret} (*{name})()'
                return f'{ret} (*)()'
            # Pointer to array: base (*name)[dims]
            if isinstance(resolved_target, ArrayType):
                dims = []
                inner_arr = resolved_target
                while isinstance(inner_arr, ArrayType):
                    count = inner_arr.high - inner_arr.low + 1 if inner_arr.high >= inner_arr.low else 0
                    dims.append(count)
                    elem = inner_arr.elem_type
                    resolved_elem = elem
                    if isinstance(elem, TypeRef):
                        ekey = (elem.file_num, elem.type_id)
                        if cu and ekey in cu.type_map:
                            resolved_elem = cu.type_map[ekey]
                        elif ekey in self.stabs.all_types:
                            resolved_elem = self.stabs.all_types[ekey]
                    if isinstance(resolved_elem, ArrayType):
                        inner_arr = resolved_elem
                    else:
                        inner_arr = elem
                        break
                base = self._type_to_c_inner(inner_arr, '', visited, cu)
                # If base is a function pointer, simplify — can't nest cleanly
                if '(*)' in base:
                    ptr = f'void * *'
                    return f'{ptr}{name}'.strip() if name else ptr.strip()
                dim_str = ''.join(f'[{d}]' for d in dims)
                if name:
                    return f'{base} (*{name}){dim_str}'
                return f'{base} (*){dim_str}'
            inner = self._type_to_c_inner(t.target, '', visited, cu)
            # Fix array-in-pointer: "const JCOEF[64] *" is invalid C.
            # Strip array dimensions when wrapping in a pointer.
            import re as _re_ptr
            if _re_ptr.search(r'\w\[\d+\]', inner) and '(*)' not in inner:
                inner = _re_ptr.sub(r'\[\d+\]', '', inner).strip()
            if inner.endswith(')'):
                # Already a function pointer type string - insert name
                if name:
                    idx = inner.find('(*)')
                    if idx >= 0:
                        # Avoid nested function pointer mangling
                        if inner.count('(*)') > 1:
                            return f'void *{name}'
                        return inner[:idx] + f'(*{name})' + inner[idx+3:]
                return f'{inner}'
            ptr = f'{inner} *'
            return f'{ptr}{name}'.strip() if name else ptr.strip()

        if isinstance(t, ReferenceType):
            inner = self._type_to_c_inner(t.target, '', visited, cu)
            ptr = f'{inner} *'
            return f'{ptr}{name}'.strip() if name else ptr.strip()

        if isinstance(t, ConstType):
            inner = self._type_to_c_inner(t.target, '', visited, cu)
            c = f'const {inner}'
            return f'{c} {name}'.strip() if name else c

        if isinstance(t, VolatileType):
            inner = self._type_to_c_inner(t.target, '', visited, cu)
            c = f'volatile {inner}'
            return f'{c} {name}'.strip() if name else c

        if isinstance(t, ArrayType):
            # Collect all array dimensions from outermost to innermost,
            # resolving TypeRefs to find nested arrays
            dims = []
            inner = t
            while isinstance(inner, ArrayType):
                count = inner.high - inner.low + 1 if inner.high >= inner.low else 0
                dims.append(count)
                elem = inner.elem_type
                # Resolve TypeRef to check if element is also an array
                resolved_elem = elem
                if isinstance(elem, TypeRef):
                    key = (elem.file_num, elem.type_id)
                    if cu and key in cu.type_map:
                        resolved_elem = cu.type_map[key]
                    elif key in self.stabs.all_types:
                        resolved_elem = self.stabs.all_types[key]
                if isinstance(resolved_elem, ArrayType):
                    inner = resolved_elem
                else:
                    inner = elem
                    break
            # inner is now the base element type
            base = self._type_to_c_inner(inner, '', visited, cu)
            dim_str = ''.join(f'[{d}]' for d in dims)
            # Handle arrays of function pointers: void (*)() → void (*name[N])()
            if '(*)' in base and name:
                idx = base.find('(*)')
                return base[:idx] + f'(*{name}{dim_str})' + base[idx+3:]
            # Handle pointer-to-array as element: base (*)[K] → simplify
            if '(*)' in base:
                return f'void *{name}{dim_str}' if name else f'void *{dim_str}'
            if name:
                return f'{base} {name}{dim_str}'
            return f'{base}{dim_str}'

        if isinstance(t, StructType):
            # Inline anonymous structs with their fields
            if t.fields:
                kind = 'union' if t.is_union else 'struct'
                field_strs = []
                for f in t.fields:
                    ftype_str = self._type_to_c_inner(f.type, f.name, set(), cu)
                    field_strs.append(f'{ftype_str};')
                body = ' '.join(field_strs)
                tag = f'{kind} {{ {body} }}'
                return f'{tag} {name}'.strip() if name else tag
            if t.is_union:
                return f'union {name}'.strip() if name else 'union'
            return f'struct {name}'.strip() if name else 'struct'

        if isinstance(t, EnumType):
            return f'enum {name}'.strip() if name else 'enum'

        if isinstance(t, FuncType):
            ret = self._type_to_c_inner(t.return_type, '', visited, cu)
            # Sanitize: bare 'enum'/'struct'/'union' (no tag) → 'int'
            if ret in ('enum', 'struct', 'union'):
                ret = 'int'
            # Can't return arrays from functions (e.g., vec3_t = float[3])
            if '[' in ret:
                ret = 'void *'
            if hasattr(self, '_array_typedef_names') and ret in self._array_typedef_names:
                ret = 'void *'
            if name:
                return f'{ret} (*{name})()'
            return f'{ret} (*)()'

        if isinstance(t, CrossRefType):
            kind = {'s': 'struct', 'u': 'union', 'e': 'enum'}.get(t.kind, 'struct')
            sref = _sanitize_type_name(t.name)
            if self._is_anonymous_name(t.name):
                if t.kind in ('s', 'u') and t.name in self._all_structs:
                    st = self._all_structs[t.name]
                    return self._type_to_c_inner(st, name, visited, cu)
                # Check CU-local anonymous types (e.g., $_XXXX unions/structs)
                if cu and t.kind in ('s', 'u') and hasattr(cu, '_anon_struct_types'):
                    if t.name in cu._anon_struct_types:
                        st = cu._anon_struct_types[t.name]
                        return self._type_to_c_inner(st, name, visited, cu)
                return f'int {name}'.strip() if name else 'int'
            # For enum cross-refs: use bare name (not 'enum X') because enums
            # may be emitted as 'typedef int X;' (for conflicting members)
            # rather than real 'enum X { ... }' definitions.  Bare name works
            # in all cases: 'typedef enum X X;' or 'typedef int X;'.
            if t.kind == 'e':
                if sref in self._all_enums:
                    return f'{sref} {name}'.strip() if name else sref
                return f'int {name}'.strip() if name else 'int'
            # If this is a struct/union cross-ref but the name is NOT a real
            # struct tag, drop the struct/union prefix (it's a typedef or
            # placeholder, using "struct X" would cause incomplete type errors)
            if t.kind in ('s', 'u') and sref not in self._all_structs:
                return f'{sref} {name}'.strip() if name else sref
            # Fix wrong struct/union kind: check the actual definition
            if t.kind in ('s', 'u') and sref in self._all_structs:
                actual_union = self._all_structs[sref].is_union
                kind = 'union' if actual_union else 'struct'
            tag = f'{kind} {sref}'
            self._forward_decls.add(tag)
            return f'{tag} {name}'.strip() if name else tag

        if isinstance(t, SizedType):
            return self._type_to_c_inner(t.inner, name, visited, cu)

        if isinstance(t, MethodType):
            return f'void (*{name})()' if name else 'void (*)()'

        return f'int {name}'.strip() if name else 'int'

    def get_struct_field_at_offset(self, t: StabsType, byte_offset: int,
                                    visited: Optional[set] = None,
                                    cu=None) -> Optional[tuple]:
        """Look up struct field by byte offset. Returns (field_name, field_type) or None.
        If cu is provided, resolve types through CU-local map first."""
        if visited is None:
            visited = set()
        resolved = self._resolve_to_struct(t, visited, cu)
        if not isinstance(resolved, StructType):
            return None
        bit_offset = byte_offset * 8
        for f in resolved.fields:
            if f.bit_offset == bit_offset:
                return (f.name, f.type)
            # Also check byte-aligned offsets
            if f.bit_offset // 8 == byte_offset:
                return (f.name, f.type)
        return None

    def _resolve_to_struct(self, t: StabsType, visited: set,
                           cu=None) -> Optional[StructType]:
        """Follow type refs to find an underlying struct type.
        If cu is provided, resolve through CU-local type map first."""
        if isinstance(t, StructType):
            return t
        if isinstance(t, PointerType):
            return self._resolve_to_struct(t.target, visited, cu)
        if isinstance(t, TypeRef):
            key = (t.file_num, t.type_id)
            if key in visited:
                return None
            visited.add(key)
            # Try CU-local type map first to avoid cross-CU pollution
            if cu and key in cu.type_map:
                cu_type = cu.type_map[key]
                return self._resolve_to_struct(cu_type, visited, cu)
            resolved = self.stabs.all_types.get(key)
            if resolved:
                return self._resolve_to_struct(resolved, visited, cu)
        if isinstance(t, RangeType):
            # Empty range = type alias, resolve through base ref
            if t.low == '' and t.high == '':
                base_key = t.base
                if base_key not in visited:
                    visited.add(base_key)
                    if cu and base_key in cu.type_map:
                        return self._resolve_to_struct(cu.type_map[base_key], visited, cu)
                    resolved = self.stabs.all_types.get(base_key)
                    if resolved:
                        return self._resolve_to_struct(resolved, visited, cu)
        if isinstance(t, (ConstType, VolatileType)):
            return self._resolve_to_struct(t.target, visited, cu)
        if isinstance(t, CrossRefType):
            if t.kind in ('s', 'u') and t.name in self._all_structs:
                return self._all_structs[t.name]
        return None

    def generate_struct_decl(self, name: str, st: StructType, cu=None,
                             emitted_structs=None) -> str:
        """Generate C struct declaration. If cu is provided, resolve field
        types through that CU to avoid cross-CU type pollution.
        emitted_structs: set of already-defined struct names, used to detect
        by-value fields referencing not-yet-defined structs."""
        import re
        sname = _sanitize_type_name(name)
        kind = 'union' if st.is_union else 'struct'
        lines = [f'{kind} {sname} {{']
        has_fields = False
        for f in st.fields:
            ftype_str = self.type_to_c(f.type, f.name, cu=cu)
            # Fix malformed types: bare "struct;" or "struct name;"
            # with no definition should become int
            if re.match(r'^(struct|union|enum)\s*;$', ftype_str.strip()):
                ftype_str = f'int {f.name}'
            # Fix malformed: "(*)() (*name)()" nested func ptr issues
            if '(*)()' in ftype_str and ftype_str.count('(*)') > 1:
                ftype_str = f'void *{f.name}'
            # Fix malformed: "(*)() * *name" — pointer to function pointer
            if '(*)()' in ftype_str and f.name not in ftype_str.split('(*)')[0]:
                ftype_str = f'void *{f.name}'
            # Fix malformed: "Type * (*)[N] *name" — pointer-to-array-of-ptrs
            if re.search(r'\(\*\)\[\d+\]', ftype_str):
                ftype_str = f'void *{f.name}'
            # Fix malformed: "type[N] (*name)()" — array return from func ptr
            if re.search(r'\w+\[\d+\]\s*\(\*', ftype_str):
                ftype_str = f'void *(*{f.name})()'
            # Fix malformed: "type *[N] * *name" — pointer-to-array-of-ptrs
            if re.search(r'\*\[\d+\]\s*\*', ftype_str):
                ftype_str = f'void *{f.name}'
            # Fix: oversized arrays that exceed GCC's max object size (2GB)
            # Check actual estimated total size rather than element count alone
            m = re.search(r'\[(\d+)\]', ftype_str)
            if m:
                arr_len = int(m.group(1))
                if arr_len > 1000000:
                    # Check estimated total size — only collapse if > 2GB
                    elem_size = 4  # assume int-sized by default
                    fts_before = ftype_str.split('[')[0].strip()
                    for word in re.findall(r'\b(\w+)\b', fts_before):
                        if word in self._all_structs:
                            elem_size = self._all_structs[word].size or 4
                            break
                        if (hasattr(self, '_typedef_to_struct')
                                and word in self._typedef_to_struct):
                            sn = self._typedef_to_struct[word]
                            if sn in self._all_structs:
                                elem_size = self._all_structs[sn].size or 4
                            break
                    if arr_len * elem_size > 0x7FFFFFFF:  # > 2GB
                        ftype_str = f'int {f.name}'
            # Fix: bare "struct" or "union" or "enum" without name
            if ftype_str.strip() in ('struct', 'union', 'enum'):
                ftype_str = f'int {f.name}'
            # Fix: "enum * name" — pointer to unnamed enum
            if re.match(r'^enum\s+\*', ftype_str.strip()):
                ftype_str = f'void *{f.name}'
            # Fix: void fields (void is not a valid field type, including const void)
            fts = ftype_str.strip()
            if fts == f'void {f.name}' or fts == 'void' or \
               fts == f'const void {f.name}' or fts.startswith('const void '):
                if '*' not in fts:  # const void * is fine (opaque pointer)
                    ftype_str = f'int {f.name}'
            # Fix: function pointer with array-typedef return type
            # e.g., vec3_t (*field)() where vec3_t is float[3] — invalid "func returning array"
            fts = ftype_str.strip()
            if re.match(r'^(\w+)\s+\(\*' + re.escape(f.name) + r'\)\(\)$', fts):
                ret_name = fts.split()[0]
                if hasattr(self, '_array_typedef_names') and ret_name in self._array_typedef_names:
                    ftype_str = f'void *(*{f.name})()'
            # Fix: self-referential by-value field (struct contains itself)
            # e.g., DObjAnimMat_s { DObjAnimMat field; } where DObjAnimMat = DObjAnimMat_s
            fts = ftype_str.strip()
            for word in re.findall(r'\b(\w+)\b', fts):
                if word == f.name or word in ('const', 'volatile', 'struct', 'union', 'enum'):
                    continue
                if word == sname:
                    # Direct self-reference
                    ftype_str = f'int {f.name}'
                    break
                if hasattr(self, '_typedef_to_struct') and self._typedef_to_struct.get(word) == sname:
                    # Indirect self-reference via typedef
                    ftype_str = f'int {f.name}'
                    break
            # Fix: by-value field referencing a struct not yet defined
            # (incomplete type error). This catches CU-pollution cycles where
            # mutual by-value embedding is physically impossible.
            if emitted_structs is not None and '*' not in ftype_str:
                fts = ftype_str.strip()
                for word in re.findall(r'\b(\w+)\b', fts):
                    if word == f.name or word in ('const', 'volatile', 'struct',
                                                   'union', 'enum', 'int', 'char',
                                                   'short', 'long', 'float', 'double',
                                                   'unsigned', 'signed', 'void'):
                        continue
                    # Check if this word is a struct/typedef-to-struct that
                    # hasn't been emitted yet
                    is_struct = word in self._all_structs
                    tgt = self._typedef_to_struct.get(word) if hasattr(self, '_typedef_to_struct') else None
                    if is_struct and word not in emitted_structs:
                        ftype_str = f'int {f.name}'
                        break
                    if tgt and tgt not in emitted_structs:
                        ftype_str = f'int {f.name}'
                        break
            # Skip anonymous fields that produce bare type declarations (e.g., "int;")
            fts_final = ftype_str.strip()
            if re.match(r'^(int|char|short|long|float|double|void|unsigned|signed'
                        r'|const\s+\w+|volatile\s+\w+)$', fts_final):
                continue
            has_fields = True
            lines.append(f'    {ftype_str};')
        if not has_fields:
            lines.append('    int _placeholder;')
        lines.append('};')
        return '\n'.join(lines)

    def generate_enum_decl(self, name: str, et: EnumType) -> str:
        """Generate C enum declaration."""
        sname = _sanitize_type_name(name)
        lines = [f'enum {sname} {{']
        for i, v in enumerate(et.values):
            comma = ',' if i < len(et.values) - 1 else ''
            lines.append(f'    {v.name} = {v.value}{comma}')
        lines.append('};')
        return '\n'.join(lines)

    def generate_common_types_header(self) -> str:
        """Generate common_types.h with all struct/enum/typedef definitions.

        Output order:
        1. Includes and platform types
        2. Forward declarations for all structs/unions
        3. Enum declarations
        4. Simple typedefs (aliases to basic types, pointers, etc.)
        5. "typedef struct X X;" convenience aliases
        6. Placeholder typedefs for all unresolved type names
        7. Struct/union definitions (topologically sorted)
        8. Complex typedefs (those containing inline anonymous structs)
        """
        import re
        _ident_re = re.compile(r'\b([A-Za-z_]\w*)\b')
        self._array_typedef_names = set()  # populated during typedef generation
        _c_keywords = {'int', 'char', 'short', 'long', 'float', 'double', 'void',
                        'unsigned', 'signed', 'const', 'volatile', 'struct', 'union',
                        'enum', 'static', 'extern', 'register', 'typedef', 'return',
                        'if', 'else', 'while', 'for', 'do', 'switch', 'case', 'break',
                        'continue', 'default', 'goto', 'sizeof', 'typeof', 'inline',
                        '__attribute__', '__extension__', '__volatile__',
                        '__asm__', 'naked', 'rep', 'stosl'}
        _std_type_names = {
            'int', 'char', 'short', 'long', 'float', 'double', 'void',
            'unsigned int', 'unsigned char', 'unsigned short', 'unsigned long',
            'signed char', 'short int', 'long int', 'long long int',
            'short unsigned int', 'long unsigned int', 'long long unsigned int',
            'bool', '_Bool', 'long long', 'unsigned long long',
        }

        lines = [
            '#ifndef COMMON_TYPES_H',
            '#define COMMON_TYPES_H',
            '',
            '#include <stdint.h>',
            '#include <stddef.h>',
            '#include <string.h>',
            '#include <sys/types.h>',
            '#include <netinet/in.h>',
            '#include <pthread.h>',
            '#include <stdio.h>',
            '',
            '/* Platform type definitions */',
            'typedef int BOOL;',
            'typedef unsigned char byte;',
            'typedef unsigned short word;',
            'typedef unsigned int dword;',
            'typedef int qboolean;',
            'typedef unsigned char qbyte;',
            '',
        ]

        # Struct names provided by system headers — skip forward decls and aliases
        _system_struct_names = {'fd_set', 'timespec', 'timeval', 'sockaddr',
                                'sockaddr_in', 'in_addr', 'stat', 'dirent',
                                'tm', 'iovec', 'addrinfo', 'hostent',
                                'sigaction', 'passwd', 'sched_param',
                                # BSD stdio internals
                                '__sbuf', '__sFILE',
                                # pthread types (defined by system headers)
                                'pthread_mutexattr_t', 'pthread_mutex_t',
                                'pthread_cond_t', 'pthread_attr_t'}

        # --- Section 2: Forward declarations ---
        declared_structs = set()
        for name in sorted(self._all_structs.keys()):
            if self._is_anonymous_name(name):
                continue
            sname = _sanitize_type_name(name)
            if sname in _system_struct_names:
                continue
            st = self._all_structs[name]
            kind = 'union' if st.is_union else 'struct'
            lines.append(f'{kind} {sname};')
            declared_structs.add(sname)
        if declared_structs:
            lines.append('')

        # --- Section 3: Enum declarations ---
        emitted_enum_sets: dict[frozenset, str] = {}
        emitted_enum_names = set()
        emitted_enum_tags = set()  # Only actual enum tag definitions
        emitted_enum_members = set()  # Track all enum member names to avoid conflicts
        # Typedef names that enum members must not shadow (used as types in struct fields)
        _typedef_type_names = {_sanitize_type_name(n) for n in self._all_typedefs}
        for name in sorted(self._all_enums.keys()):
            if self._is_anonymous_name(name):
                continue
            sname = _sanitize_type_name(name)
            if sname in declared_structs:
                continue
            et = self._all_enums[name]
            member_set = frozenset((v.name, v.value) for v in et.values)
            if member_set in emitted_enum_sets:
                lines.append(f'typedef enum {emitted_enum_sets[member_set]} {sname};')
                lines.append('')
            else:
                # Check for member name conflicts with already-emitted enums
                # AND with typedef names (enum member FLOAT would shadow typedef FLOAT)
                new_members = {v.name for v in et.values}
                conflicts = new_members & (emitted_enum_members | _typedef_type_names)
                if conflicts:
                    # Skip this enum — emit as int typedef instead
                    lines.append(f'typedef int {sname}; /* enum with conflicting members */')
                    lines.append('')
                else:
                    emitted_enum_sets[member_set] = sname
                    lines.append(self.generate_enum_decl(sname, et))
                    lines.append('')
                    emitted_enum_tags.add(sname)
                    emitted_enum_members.update(new_members)
            emitted_enum_names.add(sname)

        # --- Section 4: Build all typedefs ---
        all_typedef_names = set()
        for name, typedef_info in self._all_typedefs.items():
            if self._is_anonymous_name(name):
                continue
            sname = _sanitize_type_name(name)
            if name in _std_type_names or sname in _std_type_names:
                continue
            # Skip names that are C keywords or keyword combinations
            if sname in _c_keywords or ' ' in name:
                continue
            all_typedef_names.add(sname)

        typedef_map: dict[str, str] = {}
        typedef_deps: dict[str, set] = {}
        # Track complex typedefs and their underlying StructType for merging
        complex_typedef_structs: dict[str, tuple] = {}  # sname → (StructType, cu)

        for name, typedef_info in self._all_typedefs.items():
            if self._is_anonymous_name(name):
                continue
            sname = _sanitize_type_name(name)
            if sname not in all_typedef_names:
                continue
            key, tdef, cu = typedef_info

            c_decl = self.type_to_c(tdef, name=sname, cu=cu)
            c_type_only = self.type_to_c(tdef, cu=cu)

            if c_type_only == sname or not c_type_only.strip():
                continue
            # Skip typedefs that would conflict with standard C types
            _system_types = {'size_t', 'wchar_t', 'ptrdiff_t', 'ssize_t',
                             'wint_t', 'time_t', 'pid_t',
                             'intptr_t', 'uintptr_t', 'index',
                             'fd_set', 'pthread_mutex_t', 'pthread_mutexattr_t',
                             'pthread_t', 'nlink_t', 'blksize_t', 'dev_t',
                             'blkcnt_t', 'mode_t', 'ino_t', 'uid_t', 'gid_t',
                             'off_t', 'in_addr_t', 'in_port_t', 'sa_family_t',
                             'socklen_t',
                             # System functions redeclared as typedefs
                             'send', 'time',
                             # stdio types
                             'FILE', 'fpos_t'}
            if sname in _system_types:
                continue
            # Bare 'enum'/'struct'/'union' (no tag) → use int
            if c_type_only in ('enum', 'struct', 'union'):
                c_type_only = 'int'
                c_decl = f'int {sname}'

            # Build typedef line
            if '(*' + sname + ')' in c_decl or sname + '[' in c_decl:
                line = f'typedef {c_decl};'
            else:
                line = f'typedef {c_type_only} {sname};'

            # Detect complex typedefs (inline anonymous structs)
            is_complex = 'typedef struct {' in line or 'typedef union {' in line

            if is_complex:
                # Try to find the underlying StructType by deep resolution
                resolved = tdef
                for _ in range(20):  # follow chain
                    if isinstance(resolved, TypeRef):
                        rkey = (resolved.file_num, resolved.type_id)
                        if cu and rkey in cu.type_map:
                            resolved = cu.type_map[rkey]
                        elif rkey in self.stabs.all_types:
                            resolved = self.stabs.all_types[rkey]
                        else:
                            break
                    elif isinstance(resolved, (ConstType, VolatileType)):
                        resolved = resolved.target
                    else:
                        break
                if isinstance(resolved, StructType) and resolved.fields:
                    complex_typedef_structs[sname] = (resolved, cu)
                    continue

            typedef_map[sname] = line
            # Track array typedefs for function-returning-array detection
            if '[' in line and '(*)' not in line:
                self._array_typedef_names.add(sname)

            deps = set()
            for m in _ident_re.finditer(c_type_only):
                ident = m.group(1)
                if ident != sname and ident not in _c_keywords:
                    if (ident in all_typedef_names or ident in self._all_structs
                            or ident in complex_typedef_structs
                            or ident in self._typedef_struct_aliases
                            or ident in self._typedef_enum_aliases):
                        deps.add(ident)
            typedef_deps[sname] = deps

        # --- Build typedef→struct map from rendered typedef lines ---
        # For each typedef line "typedef X Y;", check if X is a struct name.
        # Also follow chains: if X is itself a typedef for a struct, trace it.
        self._typedef_to_struct = {}
        for sname, line in typedef_map.items():
            for m in _ident_re.finditer(line):
                ident = m.group(1)
                if ident == 'typedef' or ident == sname:
                    continue
                if ident in self._all_structs:
                    self._typedef_to_struct[sname] = ident
                    break
                if ident in complex_typedef_structs:
                    self._typedef_to_struct[sname] = ident
                    break
                # Record typedef→typedef references for chain following
                if ident in all_typedef_names and ident != sname:
                    self._typedef_to_struct[sname] = ident
                    break
        # Follow chains: if X → Y and Y → struct_s, then X → struct_s
        changed = True
        while changed:
            changed = False
            for tname, target in list(self._typedef_to_struct.items()):
                if target not in self._all_structs and target not in complex_typedef_structs:
                    if target in self._typedef_to_struct:
                        new_target = self._typedef_to_struct[target]
                        if new_target != target:
                            self._typedef_to_struct[tname] = new_target
                            changed = True
        # Remove entries that don't ultimately resolve to a struct
        self._typedef_to_struct = {
            k: v for k, v in self._typedef_to_struct.items()
            if v in self._all_structs or v in complex_typedef_structs
        }

        sorted_typedefs = self._topological_sort_map(typedef_deps)

        simple_typedef_lines = []
        post_struct_typedef_lines = []  # Array typedefs that need struct defs first
        for sname in sorted_typedefs:
            if sname in typedef_map:
                line = typedef_map[sname]
                # Array typedefs with struct element types must come after
                # struct definitions (compiler needs complete element type)
                if '[' in line and '(*)' not in line:
                    # Check if array element type is a by-value struct.
                    # Pointer typedefs (like GfxImagePtr→GfxImage) don't need
                    # complete struct types, but by-value typedefs
                    # (like centity_t→centity_s) do.
                    has_struct_dep = False
                    for d in typedef_deps.get(sname, set()):
                        if d in self._all_structs or d in complex_typedef_structs:
                            has_struct_dep = True
                            break
                        if d in self._typedef_to_struct:
                            # Check if this typedef is a pointer (contains *)
                            d_line = typedef_map.get(d, '')
                            if '*' not in d_line:
                                has_struct_dep = True
                                break
                        # Check typedef-struct aliases (e.g., weaponInfo_t→weaponInfo_s)
                        if d in self._typedef_struct_aliases:
                            has_struct_dep = True
                            break
                    if has_struct_dep:
                        post_struct_typedef_lines.append(line)
                        continue
                simple_typedef_lines.append(line)

        # Clean up malformed typedef lines from all_types fallback
        cleaned_simple = []
        for line in simple_typedef_lines:
            # "typedef enum * Name;" — pointer to unnamed enum
            if re.match(r'^typedef\s+enum\s+\*', line):
                tname = line.rstrip(';').rsplit(None, 1)[-1].lstrip('*').strip()
                line = f'typedef void *{tname};'
            # "typedef X (*)() (*Name)();" — anonymous func ptr in typedef
            if '(*)()' in line:
                m = re.search(r'\(\*(\w+)\)', line)
                if m:
                    tname = m.group(1)
                    line = f'typedef void *{tname};'
            cleaned_simple.append(line)
        simple_typedef_lines = cleaned_simple

        # --- Merge complex typedefs into struct definitions ---
        # Register complex typedef structs as named structs for topo sort
        merged_structs = dict(self._all_structs)
        merged_structs_cu = dict(self._all_structs_cu)
        for sname, (st, cu) in complex_typedef_structs.items():
            if sname not in merged_structs:
                merged_structs[sname] = st
                merged_structs_cu[sname] = cu

        # --- Section 4a: Placeholders FIRST ---
        known_types = set(declared_structs)
        for sn in merged_structs:
            known_types.add(_sanitize_type_name(sn))
        for en in self._all_enums:
            known_types.add(_sanitize_type_name(en))
        known_types.update(emitted_enum_names)
        known_types.update(typedef_map.keys())
        known_types.update(complex_typedef_structs.keys())
        known_types.update({
            'int', 'char', 'short', 'long', 'float', 'double', 'void',
            'unsigned', 'signed', 'const', 'volatile', 'struct', 'union', 'enum',
            '_Bool', 'BOOL', 'byte', 'word', 'dword', 'qboolean', 'qbyte',
            'int8_t', 'int16_t', 'int32_t', 'int64_t',
            'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t',
            'size_t', 'ptrdiff_t', 'intptr_t', 'uintptr_t',
            'wchar_t', 'wint_t', 'ssize_t', 'off_t', 'time_t', 'pid_t',
            'true', 'false', 'NULL',
            # System function/type names that conflict with headers
            'index', 'div_t', 'ldiv_t', 'send', 'time', 'printf', 'FILE', 'fpos_t',
            # POSIX/Darwin types (from macOS binary, defined by system headers)
            'fd_set', 'pthread_mutex_t', 'pthread_mutexattr_t', 'pthread_t',
            'pthread_cond_t', 'pthread_attr_t', 'pthread_key_t',
            'nlink_t', 'blksize_t', 'dev_t', 'blkcnt_t', 'mode_t', 'ino_t',
            'uid_t', 'gid_t', 'in_addr_t', 'in_port_t', 'sa_family_t',
            'socklen_t', 'sockaddr', 'sockaddr_in', 'in_addr',
            'timespec', 'timeval',
        })
        # Add typedef-to-struct/enum aliases to known types
        known_types.update(self._typedef_struct_aliases.keys())
        known_types.update(self._typedef_enum_aliases.keys())

        # Scan ALL typedef lines AND struct fields for unknown type references
        placeholder_types = set()

        def _scan_for_unknowns(text):
            for m in _ident_re.finditer(text):
                ident = m.group(1)
                if (ident not in known_types and ident not in _c_keywords
                        and len(ident) > 1 and not ident.startswith('0')
                        and not ident.isdigit()):
                    placeholder_types.add(ident)

        for line in simple_typedef_lines:
            _scan_for_unknowns(line)

        # Build topological sort for merged structs
        sorted_structs = self._topological_sort_structs_merged(merged_structs, merged_structs_cu)
        for name in sorted_structs:
            if self._is_anonymous_name(name) or name not in merged_structs:
                continue
            st = merged_structs[name]
            cu = merged_structs_cu.get(name)
            for f in st.fields:
                # Scan TYPE only (not field name) to avoid creating placeholders
                # for identifiers that are actually global variable names
                ftype_only = self.type_to_c(f.type, '', cu=cu)
                _scan_for_unknowns(ftype_only)

        # Post-struct typedefs are defined AFTER struct defs but may be used
        # IN struct fields. Add placeholder typedefs for them so struct fields
        # compile. Then skip the conflicting post-struct typedef lines.
        post_struct_names = set()
        import re as _re
        for line in post_struct_typedef_lines:
            m = _re.match(r'typedef\s+.+?\s+(\w+)\s*(?:\[.*\])?\s*;', line)
            if m:
                post_struct_names.add(m.group(1))
        placeholder_types.update(post_struct_names)

        # These opaque names conflict with common variable/function names
        _CONFLICTING_OPAQUE_NAMES = {
            'buf', 'buffer', 'color', 'main', 'name', 'start', 'str', 'tess',
        }
        if placeholder_types:
            lines.append('/* Placeholder typedefs for unresolved types */')
            for pt in sorted(placeholder_types):
                if pt in _CONFLICTING_OPAQUE_NAMES:
                    lines.append(f'/* typedef int {pt}; */ /* removed: conflicts with variable name */')
                else:
                    lines.append(f'typedef int {pt};  /* opaque */')
            lines.append('')
        # Filter out post-struct typedefs that conflict with placeholders
        post_struct_typedef_lines = [
            line for line in post_struct_typedef_lines
            if not any(pn in post_struct_names
                      for pn in _re.findall(r'\b(\w+)\s*(?:\[.*?\])?\s*;$', line))
        ]

        # --- Section 4b: Struct aliases FIRST (makes struct names usable as bare types) ---
        struct_alias_lines = []
        # System structs that need bare-name aliases but are NOT already
        # typedef'd by system headers. POSIX structs like sockaddr, in_addr
        # etc. have no typedef — they're always 'struct sockaddr'. We add
        # a typedef so generated code using bare names compiles.
        _system_needs_alias = {'sockaddr', 'sockaddr_in', 'in_addr',
                               'timeval', 'timespec', 'addrinfo', 'hostent',
                               'iovec', 'dirent', 'stat', 'tm', 'passwd',
                               'sigaction', 'sched_param'}
        for sn in sorted(merged_structs.keys()):
            if self._is_anonymous_name(sn):
                continue
            ssn = _sanitize_type_name(sn)
            st = merged_structs[sn]
            kind = 'union' if st.is_union else 'struct'
            if ssn in _system_struct_names:
                if ssn in _system_needs_alias:
                    struct_alias_lines.append(f'typedef {kind} {ssn} {ssn};')
                continue
            struct_alias_lines.append(f'typedef {kind} {ssn} {ssn};')
        if struct_alias_lines:
            lines.extend(struct_alias_lines)
            lines.append('')

        # --- Section 4c: Enum aliases (makes enum names usable as bare types) ---
        # Only for actual enum tag definitions, not aliases/typedefs
        enum_alias_lines = []
        for en in sorted(emitted_enum_tags):
            enum_alias_lines.append(f'typedef enum {en} {en};')
        if enum_alias_lines:
            lines.extend(enum_alias_lines)
            lines.append('')

        # --- Section 4d: Typedef-to-struct/enum aliases (e.g., typedef struct msg_s msg_t;) ---
        # Emitted here (before struct definitions) because struct fields may
        # reference these aliases. Only needs forward declarations, not full defs.
        # Note: do NOT include typedef_map.keys() — aliases should override simple typedefs
        _already_defined = set(declared_structs) | set(emitted_enum_names) | placeholder_types
        alias_lines = []
        for alias_name in sorted(self._typedef_struct_aliases.keys()):
            struct_name = self._typedef_struct_aliases[alias_name]
            if self._is_anonymous_name(alias_name) or alias_name in _c_keywords:
                continue
            if alias_name == struct_name:
                continue
            if alias_name in _already_defined:
                continue
            ssn = _sanitize_type_name(struct_name)
            st = merged_structs.get(struct_name)
            if st:
                kind = 'union' if st.is_union else 'struct'
            else:
                kind = 'struct'
            alias_lines.append(f'typedef {kind} {ssn} {alias_name};')
            _already_defined.add(alias_name)
        for alias_name in sorted(self._typedef_enum_aliases.keys()):
            enum_name = self._typedef_enum_aliases[alias_name]
            if self._is_anonymous_name(alias_name) or alias_name in _c_keywords:
                continue
            if alias_name == enum_name:
                continue
            if alias_name in _already_defined:
                continue
            if enum_name in emitted_enum_names:
                alias_lines.append(f'typedef enum {enum_name} {alias_name};')
            else:
                alias_lines.append(f'typedef int {alias_name}; /* enum alias */')
            _already_defined.add(alias_name)
        if alias_lines:
            lines.append('/* Typedef aliases for struct/enum types */')
            lines.extend(alias_lines)
            lines.append('')

        # --- Section 4e: Simple typedefs ---
        # Filter out simple typedefs that conflict with:
        # - struct/enum alias names (alias section 4d already defined these)
        # - enum member names (would conflict with enum constant definitions)
        _alias_defined = set()
        for alias_name in self._typedef_struct_aliases:
            _alias_defined.add(alias_name)
        for alias_name in self._typedef_enum_aliases:
            _alias_defined.add(alias_name)
        _skip_names = _alias_defined | emitted_enum_members
        if simple_typedef_lines:
            filtered_simple = []
            for line in simple_typedef_lines:
                # Match typedef name, including array typedefs like "typedef char X[8192];"
                m = _re.match(r'typedef\s+.+?\s+(\w+)\s*(?:\[.*?\])?\s*;', line)
                if not m:
                    m = _re.search(r'\(\*(\w+)\)', line)
                if m and m.group(1) in _skip_names:
                    continue  # Skip — conflicts with alias or enum member
                filtered_simple.append(line)
            lines.extend(filtered_simple)
            lines.append('')

        # --- Section 7: Struct/union definitions (merged, topologically sorted) ---
        emitted_structs = set()
        for name in sorted_structs:
            if self._is_anonymous_name(name):
                continue
            if _sanitize_type_name(name) in _system_struct_names:
                continue
            if name in merged_structs:
                st = merged_structs[name]
                cu = merged_structs_cu.get(name)
                lines.append(self.generate_struct_decl(
                    name, st, cu=cu, emitted_structs=emitted_structs))
                lines.append('')
                emitted_structs.add(_sanitize_type_name(name))

        # --- Section 8: Post-struct typedefs (array typedefs needing complete element types) ---
        if post_struct_typedef_lines:
            lines.append('/* Array typedefs (require complete element types) */')
            lines.extend(post_struct_typedef_lines)
            lines.append('')

        lines.extend(['', '#endif /* COMMON_TYPES_H */', ''])
        return '\n'.join(lines)

    def _topological_sort_structs(self) -> list[str]:
        """Sort struct names so dependencies come first."""
        # Build dependency graph
        deps: dict[str, set[str]] = {}
        for name, st in self._all_structs.items():
            deps[name] = set()
            for f in st.fields:
                self._collect_struct_deps(f.type, deps[name], set())

        # Kahn's algorithm
        in_degree = {n: 0 for n in deps}
        for n, d in deps.items():
            for dep in d:
                if dep in in_degree:
                    in_degree[n] = in_degree.get(n, 0)  # ensure exists

        # Calculate actual in-degrees
        in_degree = {n: 0 for n in deps}
        reverse: dict[str, set[str]] = {n: set() for n in deps}
        for n, d in deps.items():
            for dep in d:
                if dep in deps and dep != n:
                    reverse.setdefault(dep, set()).add(n)
                    in_degree[n] = in_degree.get(n, 0) + 1

        queue = [n for n, d in in_degree.items() if d == 0]
        result = []
        while queue:
            queue.sort()
            node = queue.pop(0)
            result.append(node)
            for dependent in reverse.get(node, set()):
                in_degree[dependent] -= 1
                if in_degree[dependent] == 0:
                    queue.append(dependent)

        # Add any remaining (cycles) at the end
        for name in sorted(deps.keys()):
            if name not in result:
                result.append(name)
        return result

    def _topological_sort_structs_merged(self, structs: dict, structs_cu: dict = None) -> list[str]:
        """Sort struct names so dependencies come first. Uses provided struct map.

        For nodes stuck in cycles, uses iterative cycle-breaking: repeatedly
        picks the node with the fewest unresolved deps (among remaining nodes)
        and emits it, breaking cycles where necessary.
        """
        deps: dict[str, set[str]] = {}
        for name, st in structs.items():
            deps[name] = set()
            cu = structs_cu.get(name) if structs_cu else None
            for f in st.fields:
                self._collect_struct_deps(f.type, deps[name], set(),
                                          cu=cu, all_structs=structs)
            deps[name] = {d for d in deps[name] if d in structs}

        in_degree = {n: 0 for n in deps}
        reverse: dict[str, set[str]] = {n: set() for n in deps}
        for n, d in deps.items():
            for dep in d:
                if dep in deps and dep != n:
                    reverse.setdefault(dep, set()).add(n)
                    in_degree[n] = in_degree.get(n, 0) + 1

        queue = [n for n, d in in_degree.items() if d == 0]
        result = []
        while queue:
            queue.sort()
            node = queue.pop(0)
            result.append(node)
            for dependent in reverse.get(node, set()):
                in_degree[dependent] -= 1
                if in_degree[dependent] == 0:
                    queue.append(dependent)

        # Cycle-breaking: iteratively emit remaining nodes, preferring those
        # with fewest unresolved deps. This breaks cycles by treating emitted
        # nodes as "resolved" and continuing the topological sort.
        result_set = set(result)
        remaining = {n for n in deps if n not in result_set}
        while remaining:
            # Pick node with fewest unresolved deps among remaining
            best = min(remaining, key=lambda n: (
                len(deps[n] - result_set),  # fewest unresolved deps
                -len(reverse.get(n, set()) & remaining),  # most dependents
                n  # alphabetical tiebreak
            ))
            result.append(best)
            result_set.add(best)
            remaining.discard(best)
            # Cascade: emit any now-unblocked nodes
            changed = True
            while changed:
                changed = False
                for n in sorted(remaining):
                    if not (deps[n] - result_set):
                        result.append(n)
                        result_set.add(n)
                        remaining.discard(n)
                        changed = True
        return result

    @staticmethod
    def _topological_sort_map(deps: dict[str, set[str]]) -> list[str]:
        """Topologically sort items given a dependency map. Kahn's algorithm."""
        in_degree = {n: 0 for n in deps}
        reverse: dict[str, set[str]] = {n: set() for n in deps}
        for n, d in deps.items():
            for dep in d:
                if dep in deps and dep != n:
                    reverse.setdefault(dep, set()).add(n)
                    in_degree[n] = in_degree.get(n, 0) + 1
        queue = sorted([n for n, d in in_degree.items() if d == 0])
        result = []
        while queue:
            node = queue.pop(0)
            result.append(node)
            for dependent in sorted(reverse.get(node, set())):
                in_degree[dependent] -= 1
                if in_degree[dependent] == 0:
                    queue.append(dependent)
        for name in sorted(deps.keys()):
            if name not in result:
                result.append(name)
        return result

    def _collect_struct_deps(self, t: StabsType, deps: set, visited: set,
                             cu=None, all_structs=None):
        """Collect struct names that a type depends on (hard/by-value deps only).
        When cu is provided, use CU-local type resolution to avoid cross-CU pollution.
        all_structs allows checking against merged struct set (includes complex typedefs)."""
        if all_structs is None:
            all_structs = self._all_structs
        if isinstance(t, TypeRef):
            key = (t.file_num, t.type_id)
            if key in visited:
                return
            visited.add(key)
            # CU-local name check FIRST — prevents global map pollution
            if cu and hasattr(cu, '_type_name_cache'):
                tname = cu._type_name_cache.get(key)
                if tname:
                    sname = _sanitize_type_name(tname)
                    if sname in all_structs:
                        deps.add(sname)
                        return
                    # Check typedef→struct chain
                    if sname in self._typedef_to_struct:
                        target = self._typedef_to_struct[sname]
                        if target in all_structs:
                            deps.add(target)
                            return
                    # Check typedef-struct aliases (e.g., weaponInfo_t→weaponInfo_s)
                    if sname in self._typedef_struct_aliases:
                        target = self._typedef_struct_aliases[sname]
                        if target in all_structs:
                            deps.add(target)
                            return
                    # CU says this is a non-struct type — skip global maps
                    return
            # CU has the type but no name — resolve through CU type_map
            if cu and key in cu.type_map:
                resolved = cu.type_map[key]
                self._collect_struct_deps(resolved, deps, visited, cu, all_structs)
                return
            # No CU info — fall back to global maps
            name = self._struct_names.get(key)
            if name:
                deps.add(name)
                return
            # Use global _typedef_names only for typedef→struct chains
            tname = self._typedef_names.get(key)
            if tname and not self._is_anonymous_name(tname):
                sname = _sanitize_type_name(tname)
                if sname in self._typedef_to_struct:
                    target = self._typedef_to_struct[sname]
                    if target in all_structs:
                        deps.add(target)
                        return
                if sname in self._typedef_struct_aliases:
                    target = self._typedef_struct_aliases[sname]
                    if target in all_structs:
                        deps.add(target)
                        return
            # Resolve through type structure
            resolved = None
            if cu and key in cu.type_map:
                resolved = cu.type_map[key]
            if not resolved:
                resolved = self.stabs.all_types.get(key)
            if resolved:
                self._collect_struct_deps(resolved, deps, visited, cu, all_structs)
        elif isinstance(t, PointerType):
            pass  # Pointers don't create hard dependencies
        elif isinstance(t, ArrayType):
            self._collect_struct_deps(t.elem_type, deps, visited, cu, all_structs)
        elif isinstance(t, (ConstType, VolatileType)):
            self._collect_struct_deps(t.target, deps, visited, cu, all_structs)
        elif isinstance(t, CrossRefType):
            if t.kind in ('s', 'u') and not self._is_anonymous_name(t.name):
                sref = _sanitize_type_name(t.name)
                if sref in all_structs:
                    deps.add(sref)
                elif sref in self._typedef_to_struct:
                    target = self._typedef_to_struct[sref]
                    if target in all_structs:
                        deps.add(target)
                elif sref in self._typedef_struct_aliases:
                    target = self._typedef_struct_aliases[sref]
                    if target in all_structs:
                        deps.add(target)
            elif t.kind in ('s', 'u') and self._is_anonymous_name(t.name):
                # Anonymous struct/union — resolve through CU-local cache
                # to collect dependencies from its inlined fields
                if cu and hasattr(cu, '_anon_struct_types'):
                    anon_st = cu._anon_struct_types.get(t.name)
                    if anon_st:
                        for f in anon_st.fields:
                            self._collect_struct_deps(f.type, deps, visited,
                                                      cu, all_structs)
        elif isinstance(t, StructType):
            # Inline struct — collect deps from its fields
            for f in t.fields:
                self._collect_struct_deps(f.type, deps, visited, cu, all_structs)

    def generate_file_header(self, cu: CompilationUnit) -> str:
        """Generate a header file for a specific compilation unit."""
        lines = []
        guard = cu.source_file.split('/')[-1].replace('.', '_').upper() + '_H'
        lines.append(f'#ifndef {guard}')
        lines.append(f'#define {guard}')
        lines.append('')
        lines.append('#include "common_types.h"')
        lines.append('')

        # File-specific types
        for td in cu.types:
            if td.name and td.is_tag:
                resolved = self.stabs.resolve_type(td.type_def)
                if isinstance(resolved, StructType) and td.name not in self._all_structs:
                    lines.append(self.generate_struct_decl(td.name, resolved))
                    lines.append('')
                elif isinstance(resolved, EnumType) and td.name not in self._all_enums:
                    lines.append(self.generate_enum_decl(td.name, resolved))
                    lines.append('')

        # Function declarations
        for func in cu.functions:
            decl = self._generate_func_decl(func)
            lines.append(f'{decl};')

        lines.extend(['', f'#endif /* {guard} */', ''])
        return '\n'.join(lines)

    def _generate_func_decl(self, func) -> str:
        """Generate a C function declaration from STABS info."""
        # Determine return type (from function name descriptor)
        ret_type = 'int'  # default
        params_str = 'void'

        if func.params:
            parts = []
            for p in func.params:
                ptype = self.type_to_c(p.type_ref, p.name)
                parts.append(ptype)
            params_str = ', '.join(parts)

        name = func.name
        # Strip leading underscore for C names
        if name.startswith('_') and not name.startswith('__'):
            name = name[1:]

        return f'{ret_type} {name}({params_str})'
