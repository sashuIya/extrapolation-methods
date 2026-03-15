#ifndef EXTRAPOLATION_METHODS_EXTRAPOLATION_H_
#define EXTRAPOLATION_METHODS_EXTRAPOLATION_H_

#include <vector>

#include "complex_num.h"

namespace extrapolation {

// ExtrapolationEngine provides methods for polynomial and rational extrapolation.
// These methods use the Neville's and Bulirsch-Stoer algorithms respectively.
class ExtrapolationEngine {
 public:
  // Performs polynomial extrapolation at the given point.
  // Uses Neville's algorithm to compute the value of the unique polynomial
  // of degree n-1 that passes through n given points.
  // x: vector of input x-coordinates.
  // f: vector of input f(x) values.
  // point: the complex point at which to extrapolate.
  static double GetPolynomialValue(const std::vector<double>& x, const std::vector<double>& f,
                                   const ComplexNum& point);

  // Performs rational extrapolation at the given point.
  // Uses the Bulirsch-Stoer algorithm to extrapolate values using rational functions.
  // x: vector of input x-coordinates.
  // f: vector of input f(x) values.
  // point: the complex point at which to extrapolate.
  static double GetRationalValue(const std::vector<double>& x, const std::vector<double>& f,
                                 const ComplexNum& point);
};

}  // namespace extrapolation

#endif  // EXTRAPOLATION_METHODS_EXTRAPOLATION_H_
