#include "../matrix_oop_tests.h"

TEST(ConstructorsTests, IncorrectInitialization1) {
  EXPECT_ANY_THROW(Matrix test_matrix(-1, 5));
}

TEST(ConstructorsTests, IncorrectInitialization2) {
  EXPECT_ANY_THROW(Matrix test_matrix(5, -1));
}

TEST(ConstructorsTests, IncorrectInitialization3) {
  EXPECT_ANY_THROW(Matrix test_matrix(-1, -1));
}

TEST(ConstructorsTests, IncorrectInitialization4) {
  EXPECT_ANY_THROW(Matrix test_matrix(0, 0));
}

TEST(ConstructorsTests, DefaultConstructorTest1) {
  Matrix test_matrix;

  EXPECT_EQ(test_matrix.get_rows(), 3);
  EXPECT_EQ(test_matrix.get_cols(), 3);

  test_helpers::CheckMatrix(test_matrix, 0.0);
}

TEST(ConstructorsTests, ParamsConstructorTest1) {
  Matrix test(2, 2);

  test(0, 0) = 1.0;
  test(0, 1) = 1.0;
  test(1, 0) = 1.0;
  test(1, 1) = 1.0;

  EXPECT_EQ(test.get_rows(), 2);
  EXPECT_EQ(test.get_cols(), 2);
  test_helpers::CheckMatrix(test, 1.0);
}

TEST(ConstructorsTests, ParamsConstructorTest2) {
  Matrix test(5, 5);

  EXPECT_EQ(test.get_rows(), 5);
  EXPECT_EQ(test.get_cols(), 5);
  test_helpers::CheckMatrix(test, 0.0);
}

TEST(ConstructorsTests, CopyConstructorTest1) {
  Matrix matrix_check(2, 2);

  matrix_check(0, 0) = 2.0;
  matrix_check(0, 1) = 2.0;
  matrix_check(1, 0) = 2.0;
  matrix_check(1, 1) = 2.0;

  Matrix matrix_copy = matrix_check;

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  test_helpers::CheckMatrix(matrix_check, 2.0);
  test_helpers::CheckMatrix(matrix_copy, 2.0);
}

TEST(ConstructorsTests, CopyConstructorTest2) {
  Matrix matrix_check(2, 2);

  matrix_check(0, 0) = 2.0;
  matrix_check(0, 1) = 2.0;
  matrix_check(1, 0) = 2.0;
  matrix_check(1, 1) = 2.0;

  Matrix matrix_copy(matrix_check);

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  test_helpers::CheckMatrix(matrix_check, 2.0);
  test_helpers::CheckMatrix(matrix_copy, 2.0);
}

TEST(ConstructorsTests, CopyConstructorTest3) {
  Matrix matrix_check(2, 2);

  matrix_check(0, 0) = 2.0;
  matrix_check(0, 1) = 2.0;
  matrix_check(1, 0) = 2.0;
  matrix_check(1, 1) = 2.0;

  Matrix matrix_copy(matrix_check);

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  test_helpers::CheckMatrix(matrix_check, 2.0);
  test_helpers::CheckMatrix(matrix_copy, 2.0);
}

TEST(ConstructorsTests, CopyConstructorTest4) {
  Matrix check, test;
  test = test_helpers::FillMatrixRandom(test.get_rows(), test.get_cols());

  check = test;

  test_helpers::CheckMatrix(check, test);
}

TEST(ConstructorsTests, MoveConstructorTest1) {
  Matrix test(3, 3);
  Matrix check = std::move(test);

  EXPECT_EQ(check.get_cols(), 3);
  EXPECT_EQ(check.get_rows(), 3);

  test_helpers::CheckMatrix(check, 0.0);

  EXPECT_EQ(test.get_cols(), 0);
  EXPECT_EQ(test.get_rows(), 0);
}

TEST(ConstructorsTests, MoveConstructorTest2) {
  Matrix test(3, 3);
  Matrix check(std::move(test));

  EXPECT_EQ(check.get_cols(), 3);
  EXPECT_EQ(check.get_rows(), 3);

  test_helpers::CheckMatrix(check, 0.0);

  EXPECT_EQ(test.get_cols(), 0);
  EXPECT_EQ(test.get_rows(), 0);
}

TEST(ConstructorsTests, MoveConstructorTest3) {
  double value(5.0);
  Matrix test = test_helpers::FillMatrixValue(5, 5, value);
  Matrix check = std::move(test);

  EXPECT_EQ(check.get_cols(), 5);
  EXPECT_EQ(check.get_rows(), 5);

  EXPECT_EQ(test.get_cols(), 0);
  EXPECT_EQ(test.get_rows(), 0);

  test_helpers::CheckMatrix(check, value);
}