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


double get_polynomial_value(
    const vector < double > &x, 
    const vector < double > &f,
    Complex &point)
{
  int count = x.size();
  vector < Complex > P(count);
  vector < Complex > P_next(count);
  for (int i = 0; i < count; ++i)
    P[i] = Complex(f[i], 0.);

  for (int first_index = 1; first_index < count; ++first_index)
  {
    for (int second_index = 0; second_index < count - first_index; ++second_index)
    {
      P_next[second_index] = (P[second_index] * (x[second_index + first_index] - point) 
                              + P[second_index + 1] * (point - x[second_index]))
                             / (x[second_index + first_index] - x[second_index]);
    }

    swap(P, P_next);
  }

  return P[0].x;
}

double get_rational_value(
    const vector < double > &x,
    const vector < double > &f,
    Complex &point)
{
  int count = x.size();
  vector < Complex > R1(count);
  vector < Complex > R2(count);
  vector < Complex > R_next(count);
  for (int i = 0; i < count; ++i)
  {
    R1[i] = Complex(0., 0.);
    R2[i] = Complex(f[i] + 1000, 0.);
  }

  for (int first_index = 1; first_index < count; ++first_index)
  {
    for (int second_index = 0; second_index < count - first_index; ++second_index)
    {
      Complex denominator =  (point - x[second_index]) / (point - x[second_index + first_index])
                              * (1. - (R2[second_index + 1] - R2[second_index]) / (R2[second_index + 1] - R1[second_index + 1])) 
                             - 1.;

      R_next[second_index] = R2[second_index + 1] + (R2[second_index + 1] - R2[second_index]) / denominator;
    }

    swap(R1, R2);
    swap(R2, R_next);
  }

  return R2[0].x - 1000.;
}

void read_data(vector < double > *x, vector < double > *f)
{
  x->resize(0);
  f->resize(0);
  double x_curr, f_curr;
  while (cin >> x_curr >> f_curr)
  {
    x->push_back(x_curr);
    f->push_back(f_curr);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  vector < double > x(0);
  vector < double > f(0);

  read_data(&x, &f);
  Complex point;
  point.y = 0.1;

  for (int index = 0; index < x.size(); ++index)
  {
    point.x = x[index];
    printf("%.2lf\n", get_polynomial_value(x, f, point));
  }

  for (int index = 0; index < x.size(); ++index)
  {
    point.x = x[index];
    printf("%.2lf\n", get_rational_value(x, f, point));
  }


  fclose(stdin);
  fclose(stdout);
  return 0;
}

