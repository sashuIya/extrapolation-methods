# Plan: Modernizing Extrapolation Methods Solver

## Objective
Refactor the existing `task2.cpp` and `complex.h` into a modular, modern C++ application following the Google C++ Style Guide. The goal is to improve maintainability, testability, and readability while preserving the mathematical correctness of the polynomial and rational extrapolation algorithms.

## Key Constraints & Standards
1.  **File Extensions**: Use `.h` for headers and `.cc` for implementation files.
2.  **Style**: Follow the Google C++ Style Guide (enforced via `.clang-format`).
3.  **Modern C++**: Utilize C++17 features (e.g., `std::vector`, `std::optional`, `std::filesystem`).
4.  **Error Handling**: Replace manual error checks with structured exceptions or result types.
5.  **Testing**: Implement unit tests using Google Test for all mathematical operations and extrapolation logic.
6.  **I/O**: Transition from C-style `freopen`/`printf` to modern C++ `<fstream>` and `<iostream>` (or `{fmt}`/`std::format` if available).

---

## Phase 1: Infrastructure and Baseline
1.  **Setup Build System**:
    *   Create `CMakeLists.txt` with C++17 support and Google Test integration.
    *   Add `.clang-format` configured for Google Style.
2.  **Baseline Verification**:
    *   Create a simple regression script to ensure the current `task2.cpp` output remains consistent after refactoring.
3.  *Commit: "chore: add CMake build system, formatting, and baseline verification"*

## Phase 2: Modularization - Complex Number Library
1.  **Refactor `Complex`**:
    *   Move `Complex` struct to `include/complex_num.h` and `src/complex_num.cc`.
    *   Rename to `ComplexNum` and follow `CamelCase` for types and `snake_case` for methods.
    *   Add comprehensive unit tests for addition, subtraction, multiplication, and the specific division logic (handling the "divide by zero returns zero" requirement).
2.  *Commit: "refactor: extract ComplexNum module with unit tests"*

## Phase 3: Modularization - Extrapolation Engines
1.  **Extrapolation Module**:
    *   Create `include/extrapolation.h` and `src/extrapolation.cc`.
    *   Encapsulate `get_polynomial_value` and `get_rational_value` into an `Extrapolator` class or a dedicated namespace.
    *   Optimize internal vector allocations (reuse buffers instead of creating new ones inside loops).
2.  **Unit Tests**:
    *   Write tests for both methods using known datasets (e.g., simple linear or quadratic functions).
3.  *Commit: "refactor: extract extrapolation algorithms into dedicated module"*

## Phase 4: Modularization - Data I/O and Management
1.  **Data Provider**:
    *   Extract data reading logic into a `DataProvider` class in `src/data_provider.cc`.
    *   Use `std::ifstream` for reading `input.txt`.
2.  **Main Application**:
    *   Refactor `main.cc` to orchestrate the `DataProvider` and `Extrapolator`.
    *   Remove `freopen` and use standard file streams for output.
3.  *Commit: "refactor: modernize I/O and data management"*

## Phase 5: Enhancements and CLI
1.  **CLI Arguments**:
    *   Allow specifying input/output file paths via command-line arguments.
    *   Allow setting the `point.y` (imaginary part) via CLI (currently hardcoded to `0.1`).
2.  **Documentation**:
    *   Update `README.md` with detailed build instructions, usage examples, and a brief mathematical explanation of the methods used.
3.  *Commit: "feat: add CLI support and update documentation"*

---

## Verification
-   **Numerical Parity**: Compare `output.txt` from the new implementation against the baseline to ensure no floating-point regressions.
-   **Test Coverage**: Ensure all new modules have >90% unit test coverage.
-   **Linting**: Verify zero warnings from `clang-tidy` and full compliance with `clang-format`.
