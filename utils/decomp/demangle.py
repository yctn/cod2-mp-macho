"""C++ name demangling via c++filt subprocess with caching."""

import subprocess
from typing import Optional


class Demangler:
    """Batch-demangles C++ names via a single c++filt subprocess pipe."""

    def __init__(self):
        self._cache: dict[str, str] = {}
        self._proc: Optional[subprocess.Popen] = None

    def _ensure_proc(self):
        if self._proc is None or self._proc.poll() is not None:
            self._proc = subprocess.Popen(
                ['c++filt', '-n'],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.DEVNULL,
                text=True,
            )

    def demangle(self, name: str) -> str:
        """Demangle a single C++ name. Returns clean C name.

        - Mangled C++ names get demangled: _Z14Cmd_AddCommandPKcPFvvE -> Cmd_AddCommand(...)
        - Plain C names with leading _ get stripped: _Cmd_Argc -> Cmd_Argc
        - Names starting with __ are left alone.
        """
        if name in self._cache:
            return self._cache[name]

        result = self._demangle_one(name)
        self._cache[name] = result
        return result

    def _demangle_one(self, name: str) -> str:
        """Demangle a single name via c++filt."""
        try:
            self._ensure_proc()
            self._proc.stdin.write(name + '\n')
            self._proc.stdin.flush()
            result = self._proc.stdout.readline().rstrip('\n')
        except (OSError, BrokenPipeError, AttributeError):
            # c++filt not available, fall back to basic cleanup
            result = name

        if result != name:
            # c++filt demangled it - extract just the function name (before '(')
            clean = self._extract_func_name(result)
            return clean

        # Not a mangled name - strip single leading underscore for C names
        if name.startswith('_') and not name.startswith('__'):
            return name[1:]
        return name

    def _extract_func_name(self, demangled: str) -> str:
        """Extract the function name from a fully demangled signature.

        E.g., 'Cmd_AddCommand(char const*, void (*)())' -> 'Cmd_AddCommand'
        Also handles 'Class::Method(...)' -> 'Class::Method'
        """
        # Find the first '(' that's not inside template brackets
        depth = 0
        for i, c in enumerate(demangled):
            if c == '<':
                depth += 1
            elif c == '>':
                depth -= 1
            elif c == '(' and depth == 0:
                return demangled[:i]
        return demangled

    def demangle_display(self, name: str) -> str:
        """Demangle for display purposes - returns the clean name suitable for C output.

        Same as demangle() but also strips any namespace qualifiers for C compatibility,
        replacing :: with _ .
        """
        result = self.demangle(name)
        # For C output, replace :: with _ since C doesn't have namespaces
        if '::' in result:
            result = result.replace('::', '_')
        return result

    def batch_demangle(self, names: list[str]) -> dict[str, str]:
        """Demangle a batch of names efficiently."""
        results = {}
        uncached = []
        for name in names:
            if name in self._cache:
                results[name] = self._cache[name]
            else:
                uncached.append(name)

        if uncached:
            try:
                # Use a single c++filt invocation for all names
                proc = subprocess.run(
                    ['c++filt', '-n'],
                    input='\n'.join(uncached),
                    capture_output=True,
                    text=True,
                    timeout=10,
                )
                demangled_lines = proc.stdout.strip().split('\n')
                for orig, dem in zip(uncached, demangled_lines):
                    if dem != orig:
                        clean = self._extract_func_name(dem)
                    elif orig.startswith('_') and not orig.startswith('__'):
                        clean = orig[1:]
                    else:
                        clean = orig
                    self._cache[orig] = clean
                    results[orig] = clean
            except (OSError, subprocess.TimeoutExpired):
                # Fallback: basic cleanup
                for name in uncached:
                    if name.startswith('_') and not name.startswith('__'):
                        clean = name[1:]
                    else:
                        clean = name
                    self._cache[name] = clean
                    results[name] = clean

        return results

    def close(self):
        """Close the subprocess if open."""
        if self._proc is not None:
            try:
                self._proc.stdin.close()
                self._proc.wait(timeout=2)
            except (OSError, subprocess.TimeoutExpired):
                self._proc.kill()
            self._proc = None

    def __del__(self):
        self.close()


# Module-level singleton for convenience
_demangler: Optional[Demangler] = None


def get_demangler() -> Demangler:
    global _demangler
    if _demangler is None:
        _demangler = Demangler()
    return _demangler


def demangle(name: str) -> str:
    """Convenience function: demangle a single name."""
    return get_demangler().demangle(name)


def demangle_display(name: str) -> str:
    """Convenience function: demangle for C output display."""
    return get_demangler().demangle_display(name)
