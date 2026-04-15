# cpp_startup_template — Development Guidelines

Italian-language C++ student management system demonstrating menu-driven OOP architecture.

## Build and Test

**Compile:** `make` (g++ with `-Iinclude` flag)
**Clean:** `make clean` (removes `.o` object files)
**Run:** `./output`

Build files: Header files in `include/`, implementation in `src/`, executable outputs to `output`.

## Architecture

**Three-layer structure:**
1. **Main Entry** — `main.cpp`: Event loop that displays menu, captures user choice, delegates to `Menu` class
2. **Menu Layer** — `Menu` class (`include/funzioniMenu.h`, `src/funzioniMenu.cpp`): Manages menu options, routes user input to operations
3. **Data Layer** — `Studente` class (`include/Studente.h`, `src/Studente.cpp`): Encapsulates student data (matricola, nome, cognome, eta, mediaVoti, provincia, residenza, sesso)

Currently implements: Insert (case 1), Print all (case 2). Stubbed: Sort (case 3), Search (case 4), Delete (case 5).

## Code Style & Conventions

**Naming:** Italian identifiers + camelCase (`setMatricola`, `stampaStudente`, `leggiInt`)
**File organization:** Header/source separation, include guards (`#ifndef ... #define ... #endif`)
**Encapsulation:** Private data, public accessors
**Header includes:** `<iostream>` for I/O, `<iomanip>` for formatting
**Input validation:** Use validation functions (`leggiUchar`, `leggiInt`, `leggiFloat`, `leggiChar`) and `cin.clear()` + `cin.ignore()` for stream recovery

Keep comments in Italian to match the project's language convention. Use const correctness in function parameters and return types.

## Known Issues & Limitations

⚠️ **High Priority:**
- **Fixed array limits**: Can manage only 10 students max; arrays are static (`Studente s[10]`, `opzioni[10]`)
- **Platform-specific code**: `system("cls")` and `system("pause")` work on Windows only; Linux/macOS need ANSI escape codes or portable alternatives

⚠️ **Medium Priority:**
- **No data persistence**: Student data lost on exit; no file I/O
- **Incomplete functionality**: Sort, Search, Delete operations not implemented (switch cases stubbed)
- **Menu indexing mismatch**: 6 menu items defined but switch handles up to 10 cases
- **Mixed concerns**: Menu class combines UI and business logic routing; should separate concerns

⚠️ **Low Priority:**
- Unusual age representation: `unsigned char` (0-255) instead of `int`
- No input validation in setter methods (validation only during interactive data entry)
- Missing `const` correctness on getter methods

## Recommended Enhancements

When implementing missing features or refactoring:
1. **Replace fixed arrays with `std::vector<Studente>`** for dynamic sizing
2. **Extract UI logic**: Move screen formatting to separate class, keep `Menu` for data routing
3. **Complete sort/search/delete** operations with appropriate algorithms
4. **Add file persistence**: JSON or CSV import/export
5. **Cross-platform screen control**: Use ANSI escape codes or cross-platform library instead of `system()` calls
6. **Improve validation**: Implement at setter level, not just during `setStudente()`
7. **Add exception handling** for invalid inputs and edge cases

## Communication

Use Italian for comments, variable names, and user-facing messages to maintain consistency with the existing codebase. When adding features, follow the established pattern: validate input using module-level functions, store via getters/setters, display via formatted `stampa*()` methods.
