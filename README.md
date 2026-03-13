# Extrapolation Methods Solver

## Overview

Modernized C++ implementation of Polynomial and Rational extrapolation methods.

## Mathematical Methods

### Polynomial Extrapolation
Uses the Neville's algorithm to compute the value of the unique polynomial of degree $n-1$ that passes through $n$ given points.

### Rational Extrapolation
Uses the Bulirsch-Stoer algorithm (a variation of the Thiele's interpolation formula) to extrapolate values using rational functions. This is often more robust than polynomial extrapolation for functions with singularities.

## Build Requirements
- CMake (>= 3.14)
- C++17 compliant compiler (e.g., GCC 9+, Clang 10+)
- Google Test (automatically downloaded via CMake)

## Building the Project

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

Run the solver with default parameters (reads `input.txt`, writes `output.txt`, imaginary part `0.1`):
```bash
./extrapolation_solver
```

Specify custom parameters:
```bash
./extrapolation_solver [input_file] [output_file] [imaginary_part]
```

Example:
```bash
./extrapolation_solver my_data.txt results.csv 0.05
```

## Running Tests

After building, you can run the unit tests:
```bash
cd build
ctest
```
Or run the specific test binary:
```bash
./complex_num_test
```

## Regression Testing
A script is provided to ensure numerical parity with the original implementation:
```bash
bash regression_test.sh
```

## License
Copyright (C) 2013-2026 Alexander Lapin
Distributed under the GNU General Public License, version 3 or later.
