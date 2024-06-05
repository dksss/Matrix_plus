#include "../matrix_oop_tests.h"

TEST(MulNumberTests, MulNumberTest1) {
  Matrix matrix = test_helpers::FillMatrixRandom(10, 10);
  double number = 0.0;

  test_helpers::CheckMatrix(matrix * number, 0.0);
  test_helpers::CheckMatrix(number * matrix, 0.0);

  Matrix check = matrix;
  test_helpers::CheckMatrix(check *= number, 0.0);

  matrix.MulNumber(number);
  test_helpers::CheckMatrix(matrix, 0.0);
}

TEST(MulNumberTests, MulNumberTest2) {
  Matrix matrix(2, 2);
  Matrix check(2, 2);
  double number = 254.03;

  matrix(0, 0) = -1.0;
  matrix(0, 1) = 12.35;
  matrix(1, 0) = 0.00856;
  matrix(1, 1) = 158.56;

  check(0, 0) = -254.03;
  check(0, 1) = 3137.2705;
  check(1, 0) = 2.1744968;
  check(1, 1) = 40278.9968;

  test_helpers::CheckMatrix(check, matrix * number);
  test_helpers::CheckMatrix(check, number * matrix);

  Matrix check2 = matrix;
  test_helpers::CheckMatrix(check, check2 *= number);

  matrix.MulNumber(number);
  test_helpers::CheckMatrix(check, matrix);

  EXPECT_TRUE(check == matrix);
}