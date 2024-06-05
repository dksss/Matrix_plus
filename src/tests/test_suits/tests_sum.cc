#include "../matrix_oop_tests.h"

TEST(SumTests, SumExceptionTest1) {
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 3);

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
}

TEST(SumTests, SumExceptionTest2) {
  Matrix matrix1(3, 2);
  Matrix matrix2(2, 2);

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
}

TEST(SumTests, SumExceptionTest3) {
  Matrix matrix1(3, 2);
  Matrix matrix2(2, 3);

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
}

TEST(SumTests, SumExceptionTest4) {
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 3);

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
}

TEST(SumTests, SumOperatorTest1) {
  Matrix matrix1;
  Matrix matrix2;
  double num1 = 2.5, num2 = 3.5;

  matrix1 = test_helpers::FillMatrixValue(5, 5, num1);
  matrix2 = test_helpers::FillMatrixValue(5, 5, num2);

  matrix1 += matrix2;

  test_helpers::CheckMatrix(matrix1, num1 + num2);

  matrix2 = matrix2 + matrix1;

  test_helpers::CheckMatrix(matrix2, num1 + num2 + num2);
}

TEST(SumTests, SumTest1) {
  Matrix matrix1;
  Matrix matrix2;
  double num1 = 2.5, num2 = 3.5;

  matrix1 = test_helpers::FillMatrixValue(5, 5, num1);
  matrix2 = test_helpers::FillMatrixValue(5, 5, num2);

  matrix1.SumMatrix(matrix2);

  test_helpers::CheckMatrix(matrix1, num1 + num2);

  matrix2.SumMatrix(matrix1);

  test_helpers::CheckMatrix(matrix2, num1 + num2 + num2);
}

TEST(SumTests, SumOperatorTest2) {
  Matrix matrix1;
  Matrix matrix2;
  double num1 = 2.5, num2 = -2.5;

  matrix1 = test_helpers::FillMatrixValue(5, 5, num1);
  matrix2 = test_helpers::FillMatrixValue(5, 5, num2);

  matrix1 += matrix2;

  test_helpers::CheckMatrix(matrix1, 0.0);

  matrix2 = matrix2 + matrix1;

  test_helpers::CheckMatrix(matrix2, -2.5);
}

TEST(SumTests, SumTest2) {
  Matrix matrix1;
  Matrix matrix2;
  double num1 = 2.5, num2 = -2.5;

  matrix1 = test_helpers::FillMatrixValue(5, 5, num1);
  matrix2 = test_helpers::FillMatrixValue(5, 5, num2);

  matrix1.SumMatrix(matrix2);

  test_helpers::CheckMatrix(matrix1, 0.0);

  matrix2.SumMatrix(matrix1);

  test_helpers::CheckMatrix(matrix2, -2.5);
}

TEST(SumTests, SumOperatorTest3) {
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 2);
  Matrix check_matrix(2, 2);
  Matrix check_matrix2(2, 2);

  matrix1(0, 0) = 59.0;
  matrix1(0, 1) = 86.0;
  matrix1(1, 0) = -29.0;
  matrix1(1, 1) = -10.0;

  matrix2(0, 0) = 61.0;
  matrix2(0, 1) = 36.0;
  matrix2(1, 0) = -6.0;
  matrix2(1, 1) = 13.0;

  check_matrix(0, 0) = 120.0;
  check_matrix(0, 1) = 122.0;
  check_matrix(1, 0) = -35.0;
  check_matrix(1, 1) = 3.0;

  check_matrix2(0, 0) = 181.0;
  check_matrix2(0, 1) = 158.0;
  check_matrix2(1, 0) = -41.0;
  check_matrix2(1, 1) = 16.0;

  matrix1 += matrix2;

  EXPECT_TRUE(matrix1 == check_matrix);

  matrix2 = matrix2 + matrix1;

  EXPECT_TRUE(matrix2 == check_matrix2);
}

TEST(SumTests, SumTest3) {
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 2);
  Matrix check_matrix(2, 2);

  matrix1(0, 0) = 59.0;
  matrix1(0, 1) = 86.0;
  matrix1(1, 0) = -29.0;
  matrix1(1, 1) = -10.0;

  matrix2(0, 0) = 61.0;
  matrix2(0, 1) = 36.0;
  matrix2(1, 0) = -6.0;
  matrix2(1, 1) = 13.0;

  check_matrix(0, 0) = 120.0;
  check_matrix(0, 1) = 122.0;
  check_matrix(1, 0) = -35.0;
  check_matrix(1, 1) = 3.0;

  matrix1.SumMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}