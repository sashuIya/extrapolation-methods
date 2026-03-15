// Copyright 2026 Alexander Lapin
// Implementation of the ComplexNum class.

#include "complex_num.h"

#include <cmath>

namespace extrapolation {

ComplexNum ComplexNum::operator+(const ComplexNum& other) const {
  return ComplexNum(x_ + other.x_, y_ + other.y_);
}

ComplexNum ComplexNum::operator-(const ComplexNum& other) const {
  return ComplexNum(x_ - other.x_, y_ - other.y_);
}

ComplexNum ComplexNum::operator*(const ComplexNum& other) const {
  // (x1 + y1*i) * (x2 + y2*i) = (x1*x2 - y1*y2) + (x1*y2 + x2*y1)*i
  return ComplexNum(x_ * other.x_ - y_ * other.y_, x_ * other.y_ + y_ * other.x_);
}

ComplexNum ComplexNum::operator/(const ComplexNum& other) const {
  double norm = other.GetNorm();
  // As per requirements, division by zero or near-zero returns (0, 0).
  if (norm < 1e-9) {
    return ComplexNum(0.0, 0.0);
  }
  // Standard complex division using the conjugate of the denominator.
  return (*this * ComplexNum(other.x_, -other.y_)) / norm;
}

ComplexNum ComplexNum::operator+(double val) const {
  return ComplexNum(x_ + val, y_);
}

ComplexNum ComplexNum::operator-(double val) const {
  return ComplexNum(x_ - val, y_);
}

ComplexNum ComplexNum::operator*(double val) const {
  return ComplexNum(x_ * val, y_ * val);
}

ComplexNum ComplexNum::operator/(double val) const {
  if (std::abs(val) < 1e-9) {
    return ComplexNum(0.0, 0.0);
  }
  return ComplexNum(x_ / val, y_ / val);
}

ComplexNum operator-(double val, const ComplexNum& complex) {
  return ComplexNum(val - complex.x(), -complex.y());
}

}  // namespace extrapolation
