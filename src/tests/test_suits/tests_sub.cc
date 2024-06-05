#include "../matrix_oop_tests.h"

TEST(SubTests, SubExceptionTest1) {
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 3);

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2 = matrix2 - matrix1);
  EXPECT_ANY_THROW(matrix1 -= matrix2);
}

TEST(SubTests, SubExceptionTest2) {
  Matrix matrix1(2, 2);
  Matrix matrix2(3, 2);

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2 = matrix2 - matrix1);
  EXPECT_ANY_THROW(matrix1 -= matrix2);
}

TEST(SubTests, SubExceptionTest3) {
  Matrix matrix1(2, 3);
  Matrix matrix2(2, 2);

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2 = matrix2 - matrix1);
  EXPECT_ANY_THROW(matrix1 -= matrix2);
}

TEST(SubTests, SubExceptionTest4) {
  Matrix matrix1(3, 2);
  Matrix matrix2(2, 2);

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2 = matrix2 - matrix1);
  EXPECT_ANY_THROW(matrix1 -= matrix2);
}

TEST(SubTests, SubExceptionTest5) {
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 3);

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2 = matrix2 - matrix1);
  EXPECT_ANY_THROW(matrix1 -= matrix2);
}

TEST(SubTests, SubTest1) {
  Matrix matrix1, matrix2;

  matrix1 = test_helpers::FillMatrixValue(3, 3, 10.0);
  matrix2 = test_helpers::FillMatrixValue(3, 3, 1.0);

  matrix1.SubMatrix(matrix2);
  test_helpers::CheckMatrix(matrix1, 9.0);

  matrix2 = matrix2 - matrix1;
  test_helpers::CheckMatrix(matrix2, -8.0);

  matrix1 -= matrix2;
  test_helpers::CheckMatrix(matrix1, 17.0);
}

TEST(SubTests, SubTest2) {
  Matrix matrix1, matrix2, check_matrix;

  matrix1 = test_helpers::FillMatrixValue(100, 100, 5.5);
  matrix2 = test_helpers::FillMatrixValue(100, 100, 0.5);
  check_matrix = test_helpers::FillMatrixValue(100, 100, 5.0);

  matrix1.SubMatrix(matrix2);
  test_helpers::CheckMatrix(matrix1, check_matrix);

  matrix2 = matrix2 - matrix1;
  test_helpers::CheckMatrix(matrix2, -4.5);

  matrix1 -= matrix2;
  test_helpers::CheckMatrix(matrix1, 9.5);
}

TEST(SubTests, SubTest3) {
  Matrix matrix1(2, 2), matrix2(2, 2), check_matrix(2, 2),
      check_matrix2(2, 2);

  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  matrix2(0, 0) = 0.5;
  matrix2(0, 1) = 1.5;
  matrix2(1, 0) = 2.5;
  matrix2(1, 1) = 3.5;

  check_matrix(0, 0) = 0.0;
  check_matrix(0, 1) = 1.0;
  check_matrix(1, 0) = 2.0;
  check_matrix(1, 1) = 3.0;

  check_matrix2(0, 0) = 0.5;
  check_matrix2(0, 1) = -0.5;
  check_matrix2(1, 0) = -1.5;
  check_matrix2(1, 1) = -2.5;

  matrix1.SubMatrix(matrix2);
  test_helpers::CheckMatrix(matrix1, 0.5);

  matrix2 = matrix2 - matrix1;
  test_helpers::CheckMatrix(matrix2, check_matrix);

  matrix1 -= matrix2;
  test_helpers::CheckMatrix(matrix1, check_matrix2);
}

TEST(SubTests, SubTest4) {
  Matrix matrix1(2, 2), matrix2(2, 2), check_matrix(2, 2);

  matrix1(0, 0) = 358.123;
  matrix1(0, 1) = -322.0;
  matrix1(1, 0) = 85.3258;
  matrix1(1, 1) = -4.0;

  matrix2(0, 0) = -100.0;
  matrix2(0, 1) = 96.35;
  matrix2(1, 0) = -700.789;
  matrix2(1, 1) = 3.5;

  check_matrix(0, 0) = 458.123;
  check_matrix(0, 1) = -418.35;
  check_matrix(1, 0) = 786.1148;
  check_matrix(1, 1) = -7.5;

  matrix1.SubMatrix(matrix2);
  test_helpers::CheckMatrix(matrix1, check_matrix);

  matrix2 = matrix2 - matrix1;

  check_matrix(0, 0) = -558.123;
  check_matrix(0, 1) = 514.7;
  check_matrix(1, 0) = -1486.9038;
  check_matrix(1, 1) = 11.0;

  test_helpers::CheckMatrix(matrix2, check_matrix);

  matrix1 -= matrix2;

  check_matrix(0, 0) = 1016.246;
  check_matrix(0, 1) = -933.05;
  check_matrix(1, 0) = 2273.0186;
  check_matrix(1, 1) = -18.5;

  test_helpers::CheckMatrix(matrix1, check_matrix);
}
