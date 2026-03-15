// Copyright 2026 Alexander Lapin
// Implementation of polynomial and rational extrapolation algorithms.

#include "extrapolation.h"

#include <algorithm>
#include <vector>

namespace extrapolation {

double ExtrapolationEngine::GetPolynomialValue(const std::vector<double>& x,
                                               const std::vector<double>& f,
                                               const ComplexNum& point) {
  int count = x.size();
  if (count == 0) return 0.0;

  // Uses Neville's algorithm for polynomial interpolation/extrapolation.
  // P[i] initially holds the values f(x_i).
  std::vector<ComplexNum> P(count);
  std::vector<ComplexNum> P_next(count);
  for (int i = 0; i < count; ++i) P[i] = ComplexNum(f[i], 0.0);

  for (int first_index = 1; first_index < count; ++first_index) {
    for (int second_index = 0; second_index < count - first_index; ++second_index) {
      // Computes the next order of polynomial values.
      P_next[second_index] = (P[second_index] * (x[second_index + first_index] - point) +
                              P[second_index + 1] * (point - x[second_index])) /
                             (x[second_index + first_index] - x[second_index]);
    }
    std::swap(P, P_next);
  }

  return P[0].x();
}

double ExtrapolationEngine::GetRationalValue(const std::vector<double>& x,
                                             const std::vector<double>& f,
                                             const ComplexNum& point) {
  int count = x.size();
  if (count == 0) return 0.0;

  // Implements the Bulirsch-Stoer algorithm for rational extrapolation.
  // This method uses a recurrence relation similar to Neville's algorithm
  // but with rational functions.
  std::vector<ComplexNum> R1(count);
  std::vector<ComplexNum> R2(count);
  std::vector<ComplexNum> R_next(count);
  for (int i = 0; i < count; ++i) {
    R1[i] = ComplexNum(0.0, 0.0);
    // Use an offset (1000) for numerical stability or specific algorithm requirements.
    R2[i] = ComplexNum(f[i] + 1000.0, 0.0);
  }

  for (int first_index = 1; first_index < count; ++first_index) {
    for (int second_index = 0; second_index < count - first_index; ++second_index) {
      ComplexNum denominator = (point - x[second_index]) / (point - x[second_index + first_index]) *
                                   (1.0 - (R2[second_index + 1] - R2[second_index]) /
                                              (R2[second_index + 1] - R1[second_index + 1])) -
                               1.0;

      // Update the rational extrapolation value.
      R_next[second_index] =
          R2[second_index + 1] + (R2[second_index + 1] - R2[second_index]) / denominator;
    }

    std::swap(R1, R2);
    std::swap(R2, R_next);
  }

  return R2[0].x() - 1000.0;
}

}  // namespace extrapolation
