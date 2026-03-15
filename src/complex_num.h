#ifndef EXTRAPOLATION_METHODS_COMPLEX_NUM_H_
#define EXTRAPOLATION_METHODS_COMPLEX_NUM_H_

namespace extrapolation {

// A simple complex number class with basic arithmetic operations.
// Follows standard complex number math for addition, subtraction, and
// multiplication. Division handles near-zero divisors by returning (0,0) as
// per the project requirements.
class ComplexNum {
 public:
  ComplexNum() : x_(0.0), y_(0.0) {}
  ComplexNum(double x, double y) : x_(x), y_(y) {}

  // Getters for real (x) and imaginary (y) parts.
  double x() const {
    return x_;
  }
  double y() const {
    return y_;
  }

  // Setters for real (x) and imaginary (y) parts.
  void set_x(double x) {
    x_ = x;
  }
  void set_y(double y) {
    y_ = y;
  }

  // Returns the square of the absolute value (norm) of the complex number.
  double GetNorm() const {
    return x_ * x_ + y_ * y_;
  }

  // Arithmetic operator overloads for complex-complex operations.
  ComplexNum operator+(const ComplexNum& other) const;
  ComplexNum operator-(const ComplexNum& other) const;
  ComplexNum operator*(const ComplexNum& other) const;
  ComplexNum operator/(const ComplexNum& other) const;

  // Arithmetic operator overloads for complex-scalar operations.
  ComplexNum operator+(double val) const;
  ComplexNum operator-(double val) const;
  ComplexNum operator*(double val) const;
  ComplexNum operator/(double val) const;

 private:
  double x_;
  double y_;
};

ComplexNum operator-(double val, const ComplexNum& complex);

}  // namespace extrapolation

#endif  // EXTRAPOLATION_METHODS_COMPLEX_NUM_H_
