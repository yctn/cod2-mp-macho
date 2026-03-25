"""Header reconstruction from STABS N_BINCL include tracking.

Analyzes which types belong to which headers by cross-referencing type
definitions across compilation units with their N_BINCL include lists.
Generates per-header .h files and an umbrella common_types.h.
"""

import os
from collections import defaultdict
from typing import Optional

from .stabs_parser import (
    StabsParser, CompilationUnit, TypeDef,
    StructType, EnumType, TypeRef, _normalize_header_path,
    SOURCE_PREFIX, ALT_PREFIX,
)
from .type_system import TypeResolver, _sanitize_type_name


class HeaderReconstructor:
    """Maps types to their original headers and generates per-header files."""

    def __init__(self, stabs: StabsParser, types: TypeResolver):
        self.stabs = stabs
        self.types = types
        self._header_map: dict[str, set[str]] = {}  # header_path -> set of type names
        self._type_to_header: dict[str, str] = {}  # type_name -> header_path
        self._header_deps: dict[str, set[str]] = {}  # header -> set of headers it depends on
        self._system_headers: set[str] = set()
        self._build_header_map()

    def _build_header_map(self):
        """Aggregate across all CUs to determine which types belong to which header.

        Strategy:
        1. Direct attribution: types in CU.header_types (from N_BINCL/N_LSYM interleaving)
        2. Consensus: for types appearing in 2+ CUs, find headers common to all defining CUs
        3. Remaining types stay in common_types.h (unattributed)
        """
        # Phase 1: Direct attribution from header_types
        direct_map = defaultdict(lambda: defaultdict(int))  # header -> type_name -> count
        for cu in self.stabs.compilation_units:
            for header_path, typedefs in cu.header_types.items():
                if header_path.startswith('/'):
                    self._system_headers.add(header_path)
                    continue
                for td in typedefs:
                    if td.name and not td.name.startswith('$'):
                        direct_map[header_path][td.name] += 1

        # Phase 2: Consensus mapping
        # Build type_name -> set of CU indices
        type_to_cus = defaultdict(set)
        for i, cu in enumerate(self.stabs.compilation_units):
            for td in cu.types:
                if td.name and (td.is_tag or not td.name.startswith('$')):
                    type_to_cus[td.name].add(i)

        # For each type in 2+ CUs, find common headers
        consensus_map = defaultdict(lambda: defaultdict(int))
        for tname, cu_indices in type_to_cus.items():
            if len(cu_indices) < 2:
                continue
            cus = [self.stabs.compilation_units[i] for i in cu_indices]
            # Headers common to ALL CUs that define this type
            common_headers = None
            for cu in cus:
                h_set = set(cu.include_files)
                if common_headers is None:
                    common_headers = h_set
                else:
                    common_headers &= h_set
            if not common_headers:
                continue
            # Filter to game headers
            game_h = [h for h in common_headers if not h.startswith('/')]
            if game_h:
                # Pick most specific: prefer shortest path
                best = min(game_h, key=len)
                consensus_map[best][tname] = len(cu_indices)

        # Merge: direct takes priority, then consensus
        for header, types in direct_map.items():
            for tname in types:
                if tname not in self._type_to_header:
                    self._type_to_header[tname] = header
                    self._header_map.setdefault(header, set()).add(tname)

        for header, types in consensus_map.items():
            for tname in types:
                if tname not in self._type_to_header:
                    self._type_to_header[tname] = header
                    self._header_map.setdefault(header, set()).add(tname)

    def compute_header_deps(self):
        """For each header, determine which other headers it depends on.

        A header H1 depends on H2 if any struct in H1 has a field whose type
        is defined in H2 (by-value, not pointer-only).
        """
        self._header_deps = {h: set() for h in self._header_map}

        for header, type_names in self._header_map.items():
            for tname in type_names:
                sname = _sanitize_type_name(tname)
                st = self.types._all_structs.get(sname)
                if not st:
                    continue
                # Collect struct dependencies for this struct's fields
                deps = set()
                cu = self.types._all_structs_cu.get(sname)
                for f in st.fields:
                    self.types._collect_struct_deps(f.type, deps, set(), cu=cu)
                # Map deps to headers
                for dep_name in deps:
                    dep_header = self._type_to_header.get(dep_name)
                    if dep_header and dep_header != header:
                        self._header_deps[header].add(dep_header)

    def get_header_for_type(self, type_name: str) -> Optional[str]:
        """Get the header path a type belongs to, or None if unattributed."""
        return self._type_to_header.get(type_name)

    def get_unattributed_types(self) -> tuple[set[str], set[str], set[str]]:
        """Return sets of (structs, enums, typedefs) not attributed to any header."""
        unattr_structs = set()
        for name in self.types._all_structs:
            sname = _sanitize_type_name(name)
            if name not in self._type_to_header and sname not in self._type_to_header:
                unattr_structs.add(name)

        unattr_enums = set()
        for name in self.types._all_enums:
            sname = _sanitize_type_name(name)
            if name not in self._type_to_header and sname not in self._type_to_header:
                unattr_enums.add(name)

        unattr_typedefs = set()
        for name in self.types._all_typedefs:
            sname = _sanitize_type_name(name)
            if name not in self._type_to_header and sname not in self._type_to_header:
                unattr_typedefs.add(name)

        return unattr_structs, unattr_enums, unattr_typedefs

    def generate_headers(self, output_dir: str):
        """Generate per-header .h files and umbrella common_types.h.

        The umbrella common_types.h includes all per-header files plus
        definitions for unattributed types. Existing .c files continue
        to work unchanged.
        """
        self.compute_header_deps()

        # Generate per-header files
        generated_headers = []
        for header_path in sorted(self._header_map.keys()):
            type_names = self._header_map[header_path]
            if not type_names:
                continue
            self._generate_single_header(output_dir, header_path, type_names)
            generated_headers.append(header_path)

        # Generate umbrella common_types.h that includes everything
        self._generate_umbrella(output_dir, generated_headers)

        return generated_headers

    def _generate_single_header(self, output_dir: str, header_path: str,
                                 type_names: set[str]):
        """Generate a single per-header .h file."""
        # Build guard name from path
        guard = header_path.replace('/', '_').replace('.', '_').replace(' ', '_').upper() + '_H'

        lines = []
        lines.append(f'#ifndef {guard}')
        lines.append(f'#define {guard}')
        lines.append('')
        lines.append(f'/* Reconstructed from: {header_path} */')
        lines.append(f'/* Types attributed via N_BINCL cross-reference */')
        lines.append('')

        # Include dependencies
        deps = self._header_deps.get(header_path, set())
        if deps:
            for dep in sorted(deps):
                lines.append(f'#include "{dep}"')
            lines.append('')

        # Forward declarations for structs in this header
        struct_names = []
        for tname in sorted(type_names):
            sname = _sanitize_type_name(tname)
            if sname in self.types._all_structs:
                st = self.types._all_structs[sname]
                kind = 'union' if st.is_union else 'struct'
                lines.append(f'{kind} {sname};')
                struct_names.append(sname)
        if struct_names:
            lines.append('')

        # Enum declarations
        for tname in sorted(type_names):
            sname = _sanitize_type_name(tname)
            if sname in self.types._all_enums:
                et = self.types._all_enums[sname]
                lines.append(self.types.generate_enum_decl(sname, et))
                lines.append('')

        # Struct/union definitions
        for tname in sorted(type_names):
            sname = _sanitize_type_name(tname)
            if sname in self.types._all_structs:
                st = self.types._all_structs[sname]
                cu = self.types._all_structs_cu.get(sname)
                lines.append(self.types.generate_struct_decl(sname, st, cu=cu))
                lines.append('')

        lines.append(f'#endif /* {guard} */')
        lines.append('')

        # Write file
        out_path = os.path.join(output_dir, header_path)
        os.makedirs(os.path.dirname(out_path), exist_ok=True)
        with open(out_path, 'w') as f:
            f.write('\n'.join(lines))

    def _generate_umbrella(self, output_dir: str, generated_headers: list[str]):
        """Generate umbrella common_types.h that includes per-header files
        and still contains all unattributed types.

        This replaces the old monolithic common_types.h while maintaining
        backward compatibility — all .c files still just #include "common_types.h".
        """
        # Generate the full monolithic header (existing behavior)
        # This ensures all types are still available
        full_header = self.types.generate_common_types_header()

        # Write it as common_types.h — keeping the existing monolithic approach
        # for now. Per-header files are generated alongside as supplementary.
        out_path = os.path.join(output_dir, 'common_types.h')
        with open(out_path, 'w') as f:
            f.write(full_header)

    def print_report(self):
        """Print a summary of header reconstruction results."""
        total_structs = len(self.types._all_structs)
        total_enums = len(self.types._all_enums)
        total_typedefs = len(self.types._all_typedefs)
        total_types = total_structs + total_enums + total_typedefs

        attributed = len(self._type_to_header)
        unattr_s, unattr_e, unattr_t = self.get_unattributed_types()

        print(f'=== Header Reconstruction Report ===')
        print(f'Total types: {total_types} ({total_structs} structs, '
              f'{total_enums} enums, {total_typedefs} typedefs)')
        print(f'Attributed to headers: {attributed}')
        print(f'Unattributed: {len(unattr_s)} structs, {len(unattr_e)} enums, '
              f'{len(unattr_t)} typedefs')
        print()

        print(f'Headers with types ({len(self._header_map)}):')
        for header in sorted(self._header_map.keys()):
            types = self._header_map[header]
            print(f'  {header}: {len(types)} types')
            for tname in sorted(types)[:8]:
                print(f'    {tname}')
            if len(types) > 8:
                print(f'    ... ({len(types) - 8} more)')
        print()

        # Include stats
        cus_with = sum(1 for cu in self.stabs.compilation_units if cu.include_files)
        print(f'CUs with N_BINCL data: {cus_with}/{len(self.stabs.compilation_units)}')

        all_headers = set()
        for cu in self.stabs.compilation_units:
            all_headers.update(cu.include_files)
        game_h = [h for h in all_headers if not h.startswith('/')]
        sys_h = [h for h in all_headers if h.startswith('/')]
        print(f'Unique headers: {len(all_headers)} ({len(game_h)} game, {len(sys_h)} system)')

    def get_cu_includes(self, cu: CompilationUnit) -> list[str]:
        """Get the list of game header include paths for a CU.

        Returns normalized paths suitable for #include directives.
        Filters out system headers.
        """
        return [h for h in cu.include_files if not h.startswith('/')]
