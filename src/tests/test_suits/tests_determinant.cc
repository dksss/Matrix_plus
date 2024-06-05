#include "../matrix_oop_tests.h"

TEST(DeterminantTests, DeterminantExceptionTest1) {
  Matrix test(2, 3);
  EXPECT_ANY_THROW(test.Determinant());
}

TEST(DeterminantTests, DeterminantExceptionTest2) {
  Matrix test(3, 2);
  EXPECT_ANY_THROW(test.Determinant());
}

TEST(DeterminantTests, ZeroDeterminantTest1) {
  Matrix test(1, 1);
  test(0, 0) = 0.0;

  double check = 0.0;

  EXPECT_NEAR(test.Determinant(), check, test_helpers::kEpsilon);
}

TEST(DeterminantTests, ZeroDeterminantTest2) {
  Matrix test(3, 3);

  test(0, 0) = 1.0;
  test(0, 1) = 2.0;
  test(0, 2) = 3.0;
  test(1, 0) = 4.0;
  test(1, 1) = 5.0;
  test(1, 2) = 6.0;
  test(2, 0) = 7.0;
  test(2, 1) = 8.0;
  test(2, 2) = 9.0;

  double check = 0.0;

  EXPECT_NEAR(test.Determinant(), check, test_helpers::kEpsilon);
}

TEST(DeterminantTests, ZeroDeterminantTest3) {
  Matrix test(3, 3);

  test(0, 0) = 1.1;
  test(0, 1) = 1.2;
  test(0, 2) = 1.3;
  test(1, 0) = 1.4;
  test(1, 1) = 1.5;
  test(1, 2) = 1.6;
  test(2, 0) = 1.7;
  test(2, 1) = 1.8;
  test(2, 2) = 1.9;

  double check = 0.0;

  EXPECT_NEAR(test.Determinant(), check, test_helpers::kEpsilon);
}

TEST(DeterminantTests, ZeroDeterminantTest4) {
  Matrix test = test_helpers::FillMatrixValue(3, 3, 4.4);

  double check = 0.0;

  EXPECT_NEAR(test.Determinant(), check, test_helpers::kEpsilon);
}

TEST(DeterminantTests, ZeroDeterminantTest5) {
  Matrix test(3, 3);

  test(0, 0) = 22.5e-7;
  test(0, 1) = 12.0e-7;
  test(0, 2) = 0.25e-7;
  test(1, 0) = 1.0e-7;
  test(1, 1) = 2.54e-7;
  test(1, 2) = 7.14e-7;
  test(2, 0) = 14.0e-7;
  test(2, 1) = 0.5e-7;
  test(2, 2) = 78.0e-7;

  double check = 0.0;

  EXPECT_NEAR(test.Determinant(), check, test_helpers::kEpsilon);
}

TEST(DeterminantTests, DeterminantTest1) {
  Matrix test(1, 1);
  test(0, 0) = 225.0;

  double check = 225.0;

  EXPECT_NEAR(test.Determinant(), check, test_helpers::kEpsilon);
}

TEST(DeterminantTests, DeterminantTest2) {
  Matrix test(3, 3);

  test(0, 0) = 0.0;
  test(0, 1) = 1.0;
  test(0, 2) = 2.0;
  test(1, 0) = 3.0;
  test(1, 1) = 4.0;
  test(1, 2) = 5.0;
  test(2, 0) = 6.0;
  test(2, 1) = 0.0;
  test(2, 2) = 7.0;

  double check = -39.0;

  EXPECT_NEAR(test.Determinant(), check, test_helpers::kEpsilon);
}

TEST(DeterminantTests, DeterminantTest3) {
  Matrix test(3, 3);

  test(0, 0) = 22.5;
  test(0, 1) = 12.0;
  test(0, 2) = 0.25;
  test(1, 0) = 1.0;
  test(1, 1) = 2.54;
  test(1, 2) = 7.14;
  test(2, 0) = 14.0;
  test(2, 1) = 0.5;
  test(2, 2) = 78.0;

  double check = 4632.13;

  EXPECT_NEAR(test.Determinant(), check, test_helpers::kEpsilon);
}

TEST(DeterminantTests, DeterminantConstTest) {
  Matrix test(3, 3);

  test(0, 0) = 22.5;
  test(0, 1) = 12.0;
  test(0, 2) = 0.25;
  test(1, 0) = 1.0;
  test(1, 1) = 2.54;
  test(1, 2) = 7.14;
  test(2, 0) = 14.0;
  test(2, 1) = 0.5;
  test(2, 2) = 78.0;

  const Matrix test2 = test;

  double check = 4632.13;

  EXPECT_NEAR(test2.Determinant(), check, test_helpers::kEpsilon);
}