/*
    Copyright (C) 2013  Alexander Lapin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
	Contacts:
	name: Alexander Lapin
	e-mail: lapinra@gmail.com
*/

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
