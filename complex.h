#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include "complex.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

double eps = 1e-9;

struct Complex
{
  double x, y;

  Complex()
  {
    x = y = 0;
  }

  Complex(double a, double b)
  {
    x = a;
    y = b;
  }

  double get_norm()
  {
    return x * x + y * y;
  }

  Complex operator + (Complex b)
  {
    return Complex(x + b.x, y + b.y);
  }

  Complex operator - (Complex b)
  {
    return Complex(x - b.x, y - b.y);
  }

  Complex operator * (Complex b)
  {
    return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
  }

  Complex operator / (double b)
  {
    return Complex(x / b, y / b);
  }

  Complex operator / (Complex b)
  {
    if (b.get_norm() < eps)
    {
//      cerr << "Wrong division!" << endl;
      /*
       * it is true, that if we divide by zero,
       * then we should return 0,
       * as it mentioned in the book
      */
      return Complex(0., 0.); // it is true, that
    }
    return (Complex(x, y) * Complex(b.x, -b.y) / b.get_norm());
  }

  Complex operator + (double a)
  {
    return Complex(x, y) + Complex(a, 0.);
  }

  Complex operator - (double a)
  {
    return Complex(x, y) - Complex(a, 0.);
  }

  Complex operator * (double a)
  {
    return Complex(x, y) * Complex(a, 0.);
  }
};

Complex operator - (double a, Complex b)
{
  return Complex(a - b.x, -b.y);
}

#endif
