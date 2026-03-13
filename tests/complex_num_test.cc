#include "include/complex_num.h"

#include <gtest/gtest.h>

namespace extrapolation {

TEST(ComplexNumTest, BasicArithmetic) {
  ComplexNum a(1.0, 2.0);
  ComplexNum b(3.0, 4.0);

  ComplexNum sum = a + b;
  EXPECT_DOUBLE_EQ(sum.x(), 4.0);
  EXPECT_DOUBLE_EQ(sum.y(), 6.0);

  ComplexNum diff = b - a;
  EXPECT_DOUBLE_EQ(diff.x(), 2.0);
  EXPECT_DOUBLE_EQ(diff.y(), 2.0);

  ComplexNum prod = a * b;
  // (1 + 2i) * (3 + 4i) = 3 + 4i + 6i - 8 = -5 + 10i
  EXPECT_DOUBLE_EQ(prod.x(), -5.0);
  EXPECT_DOUBLE_EQ(prod.y(), 10.0);
}

TEST(ComplexNumTest, DivisionByZero) {
  ComplexNum a(1.0, 2.0);
  ComplexNum zero(0.0, 0.0);

  ComplexNum res = a / zero;
  EXPECT_DOUBLE_EQ(res.x(), 0.0);
  EXPECT_DOUBLE_EQ(res.y(), 0.0);
}

TEST(ComplexNumTest, ScalarOperations) {
  ComplexNum a(1.0, 2.0);

  ComplexNum sum = a + 5.0;
  EXPECT_DOUBLE_EQ(sum.x(), 6.0);
  EXPECT_DOUBLE_EQ(sum.y(), 2.0);

  ComplexNum diff = a - 1.0;
  EXPECT_DOUBLE_EQ(diff.x(), 0.0);
  EXPECT_DOUBLE_EQ(diff.y(), 2.0);

  ComplexNum prod = a * 2.0;
  EXPECT_DOUBLE_EQ(prod.x(), 2.0);
  EXPECT_DOUBLE_EQ(prod.y(), 4.0);

  ComplexNum diff2 = 10.0 - a;
  EXPECT_DOUBLE_EQ(diff2.x(), 9.0);
  EXPECT_DOUBLE_EQ(diff2.y(), -2.0);
}

}  // namespace extrapolation
