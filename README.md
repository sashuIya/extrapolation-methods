# Extrapolation Methods Solver

## Objective
Modernized C++ implementation of **Polynomial** and **Rational** extrapolation methods. This project provides a robust engine for approximating values of complex-valued functions based on a set of discrete data points.

## Mathematical Background

### 1. Polynomial Extrapolation (Neville's Algorithm)
Given $n$ points $(x_i, f_i)$, there exists a unique polynomial $P(x)$ of degree $n-1$ passing through all points. We compute $P(z)$ at a complex point $z$ using the recurrence:

$$P_{i,i+1,\dots,i+k}(z) = \frac{(x_{i+k} - z)P_{i,\dots,i+k-1}(z) + (z - x_i)P_{i+1,\dots,i+k}(z)}{x_{i+k} - x_i}$$

where $P_i(z) = f_i$.

### 2. Rational Extrapolation (Bulirsch-Stoer Algorithm)
Rational functions often provide better approximations than polynomials, especially near singularities. We use a recurrence based on the Thiele interpolating continued fraction:

$$R_{i, \dots, i+k}(z) = R_{i+1, \dots, i+k}(z) + \frac{R_{i+1, \dots, i+k}(z) - R_{i, \dots, i+k-1}(z)}{\left( \frac{z - x_i}{z - x_{i+k}} \right) \left[ 1 - \frac{R_{i+1, \dots, i+k}(z) - R_{i, \dots, i+k-1}(z)}{R_{i+1, \dots, i+k}(z) - R_{i+1, \dots, i+k-1}(z)} \right] - 1}$$

## Project Structure
- `src/`: Implementation files (`.cc`) and header files (`.h`).
- `tests/`: Unit tests using Google Test.
- `input.txt`: Default input data ($(x, f(x))$ pairs).

## Build Requirements
- CMake (>= 3.14)
- C++17 compliant compiler
- Google Test (handled via `FetchContent`)

## Build & Run

```bash
mkdir build && cd build
cmake .. && make
./extrapolation_solver [input_file] [output_file] [imaginary_part]
```

## Verification
The project includes a regression suite to ensure numerical parity with the original 2013 implementation:
```bash
bash regression_test.sh
```

## License
Copyright (C) 2013-2026 Alexander Lapin
Distributed under the GNU General Public License, v3.
