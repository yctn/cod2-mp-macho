"""Q3A/ioq3 struct cross-reference comparison.

Compares COD2 STABS struct definitions against Quake III Arena source
to validate the parser and identify naming conventions.
"""

import os
import re
from dataclasses import dataclass, field
from typing import Optional

from .stabs_parser import StabsParser, StructType, StructField
from .type_system import TypeResolver, _sanitize_type_name


@dataclass
class Q3Field:
    """A field from a Q3 struct definition."""
    name: str
    type_str: str
    # Computed from STABS comparison
    offset: int = -1
    size: int = -1


@dataclass
class Q3Struct:
    """A struct parsed from Q3 source headers."""
    name: str
    fields: list[Q3Field]
    size: int = 0
    source_file: str = ''
    line: int = 0


@dataclass
class CompareResult:
    """Result of comparing a COD2 struct against Q3."""
    cod2_name: str
    q3_name: str
    status: str  # 'MATCH', 'SIMILAR', 'DIVERGENT', 'COD2_ONLY', 'Q3_ONLY'
    cod2_size: int = 0
    q3_size: int = 0
    cod2_fields: int = 0
    q3_fields: int = 0
    matching_fields: list[str] = field(default_factory=list)
    different_fields: list[str] = field(default_factory=list)
    notes: str = ''


class Q3Comparator:
    """Compare COD2 STABS structs against Quake III Arena source."""

    # Key Q3 structs we know about and can compare
    # Format: name -> (Q3 size, [(field_name, field_type_str, bit_offset, bit_size)])
    # These are hand-verified from ioq3 source
    Q3_REFERENCE = {
        'cplane_s': Q3Struct(
            name='cplane_s',
            fields=[
                Q3Field('normal', 'vec3_t', 0, 96),      # float[3] at offset 0
                Q3Field('dist', 'float', 96, 32),         # float at offset 12
                Q3Field('type', 'byte', 128, 8),           # byte at offset 16
                Q3Field('signbits', 'byte', 136, 8),       # byte at offset 17
                Q3Field('pad', 'byte[2]', 144, 16),        # byte[2] at offset 18
            ],
            size=20,
            source_file='q_shared.h',
        ),
        'usercmd_s': Q3Struct(
            name='usercmd_s',
            fields=[
                Q3Field('serverTime', 'int', 0, 32),
                Q3Field('angles', 'int[3]', 32, 96),
                Q3Field('buttons', 'int', 128, 32),
                Q3Field('weapon', 'byte', 160, 8),
                Q3Field('forwardmove', 'signed char', 168, 8),
                Q3Field('rightmove', 'signed char', 176, 8),
                Q3Field('upmove', 'signed char', 184, 8),
            ],
            size=24,
            source_file='q_shared.h',
        ),
    }

    # Q3 source directories to search
    Q3_PATHS = [
        '/home/user/decomp/ioq3/code',
        '/home/user/decomp/Quake-III-Arena/code',
    ]

    def __init__(self, stabs: StabsParser, types: TypeResolver):
        self.stabs = stabs
        self.types = types
        self._q3_structs: dict[str, Q3Struct] = {}
        self._results: list[CompareResult] = []
        self._load_q3_reference()
        self._parse_q3_headers()
        self._compare()

    def _load_q3_reference(self):
        """Load the hand-verified Q3 reference structs."""
        self._q3_structs.update(self.Q3_REFERENCE)

    def _parse_q3_headers(self):
        """Parse Q3 header files to extract struct definitions."""
        headers_to_parse = [
            'qcommon/q_shared.h',
            'game/bg_public.h',
            'game/g_local.h',
            'qcommon/cm_local.h',
            'qcommon/qcommon.h',
        ]

        for q3_path in self.Q3_PATHS:
            if not os.path.isdir(q3_path):
                continue
            for header in headers_to_parse:
                full_path = os.path.join(q3_path, header)
                if os.path.exists(full_path):
                    self._parse_header_file(full_path, header)
            break  # Use first available Q3 source

    def _parse_header_file(self, path: str, rel_path: str):
        """Parse struct definitions from a C header file using regex."""
        try:
            with open(path) as f:
                content = f.read()
        except IOError:
            return

        # Match struct definitions: struct name { ... };
        # or typedef struct name { ... } alias;
        pattern = re.compile(
            r'(?:typedef\s+)?struct\s+(\w+)\s*\{([^}]+)\}',
            re.DOTALL
        )

        for m in pattern.finditer(content):
            name = m.group(1)
            body = m.group(2)

            if name in self._q3_structs:
                continue  # Already have hand-verified version

            fields = self._parse_struct_body(body)
            if fields:
                self._q3_structs[name] = Q3Struct(
                    name=name,
                    fields=fields,
                    source_file=rel_path,
                )

    def _parse_struct_body(self, body: str) -> list[Q3Field]:
        """Parse struct field declarations from the body text."""
        fields = []
        # Remove comments
        body = re.sub(r'//[^\n]*', '', body)
        body = re.sub(r'/\*.*?\*/', '', body, flags=re.DOTALL)

        for line in body.split(';'):
            line = line.strip()
            if not line:
                continue
            # Skip preprocessor directives
            if line.startswith('#'):
                continue
            # Skip function pointers (complex to parse)
            if '(' in line and '*' in line:
                # Try to extract name from void (*name)(...)
                m = re.search(r'\(\*(\w+)\)', line)
                if m:
                    fields.append(Q3Field(m.group(1), 'funcptr'))
                continue

            # Parse: type name; or type name[N];
            m = re.match(r'([\w\s*]+?)\s+(\w+)(\[\d+\])?$', line)
            if m:
                type_str = m.group(1).strip()
                fname = m.group(2)
                arr = m.group(3) or ''
                fields.append(Q3Field(fname, type_str + arr))
            else:
                # Try comma-separated: type name1, name2;
                m = re.match(r'([\w\s*]+?)\s+([\w,\s\[\]]+)$', line)
                if m:
                    type_str = m.group(1).strip()
                    for part in m.group(2).split(','):
                        part = part.strip()
                        nm = re.match(r'(\w+)(\[\d+\])?$', part)
                        if nm:
                            fields.append(Q3Field(nm.group(1),
                                                  type_str + (nm.group(2) or '')))

        return fields

    def _compare(self):
        """Compare all COD2 structs against Q3 reference."""
        # Build set of COD2 struct names
        cod2_names = set()
        for name in self.types._all_structs:
            cod2_names.add(_sanitize_type_name(name))

        q3_names = set(self._q3_structs.keys())

        # Find common names
        common = cod2_names & q3_names

        for name in sorted(common):
            result = self._compare_struct(name)
            if result:
                self._results.append(result)

        # Q3-only structs that we'd expect in a COD derivative
        interesting_q3_only = {'gentity_s', 'gclient_s', 'pmove_t'}
        for name in sorted(q3_names - cod2_names):
            if name in interesting_q3_only or name.endswith('_s'):
                self._results.append(CompareResult(
                    cod2_name='',
                    q3_name=name,
                    status='Q3_ONLY',
                    q3_fields=len(self._q3_structs[name].fields),
                    q3_size=self._q3_structs[name].size,
                ))

    def _compare_struct(self, name: str) -> Optional[CompareResult]:
        """Compare a single struct between COD2 and Q3."""
        q3_st = self._q3_structs.get(name)
        cod2_st = self.types._all_structs.get(name)

        if not q3_st or not cod2_st:
            return None

        q3_field_names = [f.name for f in q3_st.fields]
        cod2_field_names = [f.name for f in cod2_st.fields]

        # Find matching fields (by name, in order)
        matching = []
        different = []
        q3_set = set(q3_field_names)
        cod2_set = set(cod2_field_names)

        common_fields = q3_set & cod2_set
        for fname in q3_field_names:
            if fname in cod2_set:
                matching.append(fname)

        # Fields only in COD2
        cod2_only = cod2_set - q3_set
        # Fields only in Q3
        q3_only = q3_set - cod2_set

        for fname in sorted(cod2_only):
            different.append(f'+COD2: {fname}')
        for fname in sorted(q3_only):
            different.append(f'-Q3: {fname}')

        # Determine status
        if not different and len(cod2_field_names) == len(q3_field_names):
            # Check if field ORDER matches too
            if cod2_field_names == q3_field_names:
                status = 'MATCH'
            else:
                status = 'SIMILAR'
                different.append('(field order differs)')
        elif len(matching) >= len(q3_field_names) * 0.7:
            status = 'SIMILAR'
        else:
            status = 'DIVERGENT'

        # Check size if available
        notes = ''
        if q3_st.size > 0:
            if cod2_st.size == q3_st.size:
                notes = f'Size match: {cod2_st.size} bytes'
            else:
                notes = f'Size: COD2={cod2_st.size} Q3={q3_st.size}'
                if status == 'MATCH':
                    status = 'SIMILAR'

        return CompareResult(
            cod2_name=name,
            q3_name=name,
            status=status,
            cod2_size=cod2_st.size,
            q3_size=q3_st.size,
            cod2_fields=len(cod2_st.fields),
            q3_fields=len(q3_st.fields),
            matching_fields=matching,
            different_fields=different,
            notes=notes,
        )

    def print_report(self):
        """Print the full comparison report."""
        print('=== COD2 vs Q3A Struct Comparison ===')
        print(f'Q3 reference structs: {len(self._q3_structs)}')
        print(f'COD2 STABS structs: {len(self.types._all_structs)}')
        print()

        # Group by status
        by_status = {}
        for r in self._results:
            by_status.setdefault(r.status, []).append(r)

        status_order = ['MATCH', 'SIMILAR', 'DIVERGENT', 'Q3_ONLY']
        for status in status_order:
            results = by_status.get(status, [])
            if not results:
                continue

            print(f'--- {status} ({len(results)}) ---')
            for r in results:
                if r.status == 'Q3_ONLY':
                    print(f'  {r.q3_name}: Q3 only ({r.q3_fields} fields)')
                    continue

                size_str = ''
                if r.cod2_size > 0 or r.q3_size > 0:
                    size_str = f' [COD2:{r.cod2_size}B Q3:{r.q3_size}B]'

                print(f'  {r.cod2_name}: COD2={r.cod2_fields}f Q3={r.q3_fields}f'
                      f' match={len(r.matching_fields)}{size_str}')

                if r.matching_fields and r.status != 'MATCH':
                    print(f'    Matching: {", ".join(r.matching_fields[:10])}')
                if r.different_fields:
                    for d in r.different_fields[:8]:
                        print(f'    {d}')
                    if len(r.different_fields) > 8:
                        print(f'    ... ({len(r.different_fields) - 8} more)')
                if r.notes:
                    print(f'    Note: {r.notes}')
            print()

        # Summary
        total_compared = len([r for r in self._results if r.status != 'Q3_ONLY'])
        matches = len(by_status.get('MATCH', []))
        similar = len(by_status.get('SIMILAR', []))
        divergent = len(by_status.get('DIVERGENT', []))
        print(f'Summary: {total_compared} compared, {matches} match, '
              f'{similar} similar, {divergent} divergent')

        # Validate key structs
        print('\n--- Key Struct Validation ---')
        key_structs = ['cplane_s', 'usercmd_s', 'cmodel_s', 'entityState_s',
                       'playerState_s']
        for name in key_structs:
            cod2_st = self.types._all_structs.get(name)
            q3_st = self._q3_structs.get(name)
            if cod2_st and q3_st:
                result = self._compare_struct(name)
                if result:
                    print(f'  {name}: {result.status} '
                          f'(COD2:{result.cod2_size}B/{result.cod2_fields}f '
                          f'Q3:{result.q3_size}B/{result.q3_fields}f)')
            elif cod2_st:
                print(f'  {name}: COD2 only ({cod2_st.size}B/{len(cod2_st.fields)}f)')
            elif q3_st:
                print(f'  {name}: Q3 only')
            else:
                print(f'  {name}: not found in either')
