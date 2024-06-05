#include "../matrix_oop_tests.h"

TEST(CalcComplementsTests, CalcComplementsExceptionTest1) {
  Matrix matrix(3, 5);
  EXPECT_ANY_THROW(matrix.CalcComplements());
}

TEST(CalcComplementsTests, CalcComplementsExceptionTest2) {
  Matrix matrix(5, 3);
  EXPECT_ANY_THROW(matrix.CalcComplements());
}

TEST(CalcComplementsTests, CalcComplementsExceptionTest3) {
  Matrix matrix(1, 3);
  EXPECT_ANY_THROW(matrix.CalcComplements());
}

TEST(CalcComplementsTests, CalcComplementsExceptionTest4) {
  Matrix matrix(3, 1);
  EXPECT_ANY_THROW(matrix.CalcComplements());
}

TEST(CalcComplementsTests, CalcComplementsExceptionTest5) {
  Matrix matrix(1, 1);
  EXPECT_ANY_THROW(matrix.CalcComplements());
}

TEST(CalcComplementsTests, CalcComplementsTest1) {
  Matrix matrix(3, 3);

  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 1.0;
  matrix(1, 1) = 2.0;
  matrix(1, 2) = 3.0;
  matrix(2, 0) = 1.0;
  matrix(2, 1) = 2.0;
  matrix(2, 2) = 3.0;

  Matrix check(3, 3);

  test_helpers::CheckMatrix(check, matrix.CalcComplements());
}

TEST(CalcComplementsTests, CalcComplementsTest2) {
  Matrix matrix(2, 2);

  matrix(0, 0) = 11.0;
  matrix(0, 1) = 22.0;
  matrix(1, 0) = 33.0;
  matrix(1, 1) = 44.0;

  Matrix check(2, 2);

  check(0, 0) = 44.0;
  check(0, 1) = -33.0;
  check(1, 0) = -22.0;
  check(1, 1) = 11.0;

  test_helpers::CheckMatrix(check, matrix.CalcComplements());
}

TEST(CalcComplementsTests, CalcComplementsTest3) {
  Matrix matrix(3, 3);

  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;
  matrix(2, 0) = 7.0;
  matrix(2, 1) = 8.0;
  matrix(2, 2) = 9.0;

  Matrix check(3, 3);

  check(0, 0) = -3.0;
  check(1, 0) = 6.0;
  check(2, 0) = -3.0;
  check(0, 1) = 6.0;
  check(1, 1) = -12.0;
  check(2, 1) = 6.0;
  check(0, 2) = -3.0;
  check(1, 2) = 6.0;
  check(2, 2) = -3.0;

  test_helpers::CheckMatrix(check, matrix.CalcComplements());
}

TEST(CalcComplementsTests, CalcComplementsConstTest) {
  Matrix matrix(3, 3);

  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;
  matrix(2, 0) = 7.0;
  matrix(2, 1) = 8.0;
  matrix(2, 2) = 9.0;

  Matrix check(3, 3);

  check(0, 0) = -3.0;
  check(1, 0) = 6.0;
  check(2, 0) = -3.0;
  check(0, 1) = 6.0;
  check(1, 1) = -12.0;
  check(2, 1) = 6.0;
  check(0, 2) = -3.0;
  check(1, 2) = 6.0;
  check(2, 2) = -3.0;

  const Matrix check2 = matrix;

  test_helpers::CheckMatrix(check, check2.CalcComplements());
}
