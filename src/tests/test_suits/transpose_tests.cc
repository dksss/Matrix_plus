#include "../matrix_oop_tests.h"

TEST(TransposeTests, TransposeTest1) {
  Matrix matrix(1, 3);

  Matrix check = matrix.Transpose();

  EXPECT_EQ(check.get_rows(), 3);
  EXPECT_EQ(check.get_cols(), 1);
}

TEST(TransposeTests, TransposeTest2) {
  Matrix matrix = test_helpers::FillMatrixRandom(3, 5);

  Matrix check = matrix.Transpose();

  EXPECT_EQ(check.get_rows(), 5);
  EXPECT_EQ(check.get_cols(), 3);

  test_helpers::CheckMatrix(check.Transpose(), matrix);
}

TEST(TransposeTests, TransposeTest3) {
  Matrix matrix(1, 4);

  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(0, 3) = 4.0;

  Matrix check(4, 1);

  check(0, 0) = 1.0;
  check(1, 0) = 2.0;
  check(2, 0) = 3.0;
  check(3, 0) = 4.0;

  test_helpers::CheckMatrix(check, matrix.Transpose());
  test_helpers::CheckMatrix(matrix, check.Transpose());
}

TEST(TransposeTests, TransposeTest4) {
  Matrix matrix(1, 1);
  matrix(0, 0) = 355.0;

  Matrix check(1, 1);
  check(0, 0) = 355.0;

  test_helpers::CheckMatrix(check, matrix.Transpose());
  test_helpers::CheckMatrix(matrix, check.Transpose());
}

TEST(TransposeTests, TransposeTest5) {
  Matrix matrix(2, 2);

  matrix(0, 0) = 255.0;
  matrix(0, 1) = 178.0;
  matrix(1, 0) = -5.0;
  matrix(1, 1) = 60.123;

  Matrix check(2, 2);

  check(0, 0) = 255.0;
  check(1, 0) = 178.0;
  check(0, 1) = -5.0;
  check(1, 1) = 60.123;

  test_helpers::CheckMatrix(check, matrix.Transpose());
  test_helpers::CheckMatrix(matrix, check.Transpose());
}

TEST(TransposeTests, TransposeConstMatrixTest) {
  Matrix matrix(2, 2);

  matrix(0, 0) = 255.0;
  matrix(0, 1) = 178.0;
  matrix(1, 0) = -5.0;
  matrix(1, 1) = 60.123;

  Matrix check(2, 2);

  check(0, 0) = 255.0;
  check(0, 1) = -5.0;
  check(1, 0) = 178.0;
  check(1, 1) = 60.123;

  const Matrix check2 = matrix;

  test_helpers::CheckMatrix(check, check2.Transpose());
}