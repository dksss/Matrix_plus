#include "../matrix_oop_tests.h"

TEST(InverseTests, InverseExceptionTest1) {
  Matrix matrix(5, 3);
  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

TEST(InverseTests, InverseExceptionTest2) {
  Matrix matrix(3, 5);
  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

TEST(InverseTests, InverseExceptionTest3) {
  Matrix matrix(1, 3);
  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

TEST(InverseTests, InverseExceptionTest4) {
  Matrix matrix(3, 1);
  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

TEST(InverseTests, ZeroDeterminantTest1) {
  Matrix matrix(3, 3);

  matrix(0, 0) = 1.0;
  matrix(0, 0) = 2.0;
  matrix(0, 0) = 3.0;
  matrix(0, 0) = 4.0;
  matrix(0, 0) = 5.0;
  matrix(0, 0) = 6.0;
  matrix(0, 0) = 7.0;
  matrix(0, 0) = 8.0;
  matrix(0, 0) = 9.0;

  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

TEST(InverseTests, ZeroDeterminantTest2) {
  Matrix matrix(2, 2);

  matrix(0, 0) = -78.0;
  matrix(0, 1) = -78.0;
  matrix(1, 0) = -78.0;
  matrix(1, 1) = -78.0;

  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

TEST(InverseTests, InverseTest1) {
  Matrix matrix(2, 2);

  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  Matrix check(2, 2);

  check(0, 0) = -2.0;
  check(0, 1) = 1.0;
  check(1, 0) = 1.5;
  check(1, 1) = -0.5;

  test_helpers::CheckMatrix(check, matrix.InverseMatrix());
}

TEST(InverseTests, InverseTest2) {
  Matrix matrix(3, 3);

  matrix(0, 0) = 22.5;
  matrix(0, 1) = 12.0;
  matrix(0, 2) = 0.25;
  matrix(1, 0) = 1.0;
  matrix(1, 1) = 2.54;
  matrix(1, 2) = 7.14;
  matrix(2, 0) = 14.0;
  matrix(2, 1) = 0.5;
  matrix(2, 2) = 78.0;

  Matrix check(3, 3);

  check(0, 0) = 19455.0 / 463213.0;
  check(0, 1) = -187175.0 / 926426.0;
  check(0, 2) = 17009.0 / 926426.0;
  check(1, 0) = 2196.0 / 463213.0;
  check(1, 1) = 175150.0 / 463213.0;
  check(1, 2) = -16040.0 / 463213.0;
  check(2, 0) = -3506.0 / 463213.0;
  check(2, 1) = 15675.0 / 463213.0;
  check(2, 2) = 4515.0 / 463213.0;

  test_helpers::CheckMatrix(check, matrix.InverseMatrix());
}

TEST(InverseTests, InverseConstTest) {
  Matrix matrix(3, 3);

  matrix(0, 0) = 22.5;
  matrix(0, 1) = 12.0;
  matrix(0, 2) = 0.25;
  matrix(1, 0) = 1.0;
  matrix(1, 1) = 2.54;
  matrix(1, 2) = 7.14;
  matrix(2, 0) = 14.0;
  matrix(2, 1) = 0.5;
  matrix(2, 2) = 78.0;

  Matrix check(3, 3);

  check(0, 0) = 19455.0 / 463213.0;
  check(0, 1) = -187175.0 / 926426.0;
  check(0, 2) = 17009.0 / 926426.0;
  check(1, 0) = 2196.0 / 463213.0;
  check(1, 1) = 175150.0 / 463213.0;
  check(1, 2) = -16040.0 / 463213.0;
  check(2, 0) = -3506.0 / 463213.0;
  check(2, 1) = 15675.0 / 463213.0;
  check(2, 2) = 4515.0 / 463213.0;

  const Matrix check2 = matrix;

  test_helpers::CheckMatrix(check, check2.InverseMatrix());
}