#include "../matrix_oop_tests.h"

TEST(MulMatrixTests, MulMatrixExceptionsTest1) {
  Matrix matrix1(3, 2);
  Matrix matrix2(3, 2);

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
}

TEST(MulMatrixTests, MulMatrixExceptionsTest2) {
  Matrix matrix1(2, 3);
  Matrix matrix2(2, 3);

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
}

TEST(MulMatrixTests, MulMatrixExceptionsTest3) {
  Matrix matrix1(2, 2);
  Matrix matrix2(3, 3);

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
}

TEST(MulMatrixTests, MulMatrixExceptionsTest4) {
  Matrix matrix1(3, 3);
  Matrix matrix2(2, 2);

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
}

TEST(MulMatrixTests, MulMatrixTest1) {
  Matrix matrix1 = test_helpers::FillMatrixRandom(3, 5);
  Matrix matrix2 = test_helpers::FillMatrixRandom(5, 3);

  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 3);
}

TEST(MulMatrixTests, MulMatrixTest2) {
  Matrix matrix1 = test_helpers::FillMatrixRandom(3, 3);
  Matrix matrix2(3, 3);

  Matrix check_matrix = matrix1 * matrix2;
  test_helpers::CheckMatrix(check_matrix, 0.0);

  check_matrix *= matrix1;
  test_helpers::CheckMatrix(check_matrix, 0.0);

  matrix1.MulMatrix(matrix2);
  test_helpers::CheckMatrix(matrix1, 0.0);
}

TEST(MulMatrixTests, MulMatrixTest3) {
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 2);
  Matrix matrix_check(2, 2);

  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  matrix2(0, 0) = 5.0;
  matrix2(0, 1) = 6.0;
  matrix2(1, 0) = 7.0;
  matrix2(1, 1) = 8.0;

  matrix_check(0, 0) = 19.0;
  matrix_check(0, 1) = 22.0;
  matrix_check(1, 0) = 43.0;
  matrix_check(1, 1) = 50.0;

  test_helpers::CheckMatrix(matrix_check, matrix1 * matrix2);

  Matrix matrix_check2 = matrix1;
  test_helpers::CheckMatrix(matrix_check, matrix_check2 *= matrix2);

  matrix1.MulMatrix(matrix2);
  test_helpers::CheckMatrix(matrix_check, matrix1);

  ASSERT_TRUE(matrix_check == matrix1);
}

TEST(MulMatrixTests, MulMatrixTest4) {
  Matrix matrix1(1, 3);
  Matrix matrix2(3, 1);

  matrix1(0, 0) = 85.3565;
  matrix1(0, 1) = -0.8569;
  matrix1(0, 2) = 3.589;

  matrix2(0, 0) = 87.0;
  matrix2(1, 0) = 14.375;
  matrix2(2, 0) = -8.741;

  Matrix matrix_check(1, 1);

  matrix_check(0, 0) = 7382.3261135;

  test_helpers::CheckMatrix(matrix_check, matrix1 * matrix2);

  Matrix matrix_check2 = matrix1;
  test_helpers::CheckMatrix(matrix_check, matrix_check2 *= matrix2);

  matrix1.MulMatrix(matrix2);
  test_helpers::CheckMatrix(matrix_check, matrix1);

  ASSERT_TRUE(matrix_check == matrix1);
}