#include "../matrix_oop_tests.h"

TEST(AccsessorTests, AccessorTest1) {
  Matrix matrix(3, 3);
  int check = 3;

  EXPECT_EQ(matrix.get_rows(), check);
  EXPECT_EQ(matrix.get_cols(), check);
}

TEST(AccsessorTests, AccessorTest2) {
  const Matrix matrix(3, 3);
  int check = 3;

  EXPECT_EQ(matrix.get_rows(), check);
  EXPECT_EQ(matrix.get_cols(), check);
}

TEST(AccsessorTests, AccessorTest3) {
  Matrix matrix(3, 5);
  int check1 = 3;
  int check2 = 5;

  EXPECT_EQ(matrix.get_rows(), check1);
  EXPECT_EQ(matrix.get_cols(), check2);
}

TEST(AccsessorTests, AccessorTest4) {
  const Matrix matrix(5, 3);
  int check1 = 5;
  int check2 = 3;

  EXPECT_EQ(matrix.get_rows(), check1);
  EXPECT_EQ(matrix.get_cols(), check2);
}

TEST(MutatorTests, MutatorsTest1) {
  Matrix matrix(3, 3);

  int rows = 9;
  int cols = 9;

  matrix.set_rows(rows);
  matrix.set_cols(cols);

  EXPECT_EQ(matrix.get_rows(), rows);
  EXPECT_EQ(matrix.get_cols(), cols);
  test_helpers::CheckMatrix(matrix, 0.0);
}

TEST(MutatorTests, MutatorsTest2) {
  Matrix matrix(3, 3);

  int rows = 3;
  int cols = 3;

  matrix.set_rows(rows);
  matrix.set_cols(cols);

  EXPECT_EQ(matrix.get_rows(), rows);
  EXPECT_EQ(matrix.get_cols(), cols);
  test_helpers::CheckMatrix(matrix, 0.0);
}

TEST(MutatorTests, MutatorsTest3) {
  Matrix matrix(3, 3);

  int rows = -5;

  EXPECT_ANY_THROW(matrix.set_rows(rows));
}

TEST(MutatorTests, MutatorsTest4) {
  Matrix matrix(3, 3);

  int cols = -5;

  EXPECT_ANY_THROW(matrix.set_cols(cols));
}

TEST(MutatorTests, MutatorsTest5) {
  Matrix matrix(3, 3);

  int rows = 3;
  int cols = 5;

  matrix.set_rows(rows);
  matrix.set_cols(cols);

  EXPECT_EQ(matrix.get_rows(), rows);
  EXPECT_EQ(matrix.get_cols(), cols);
  test_helpers::CheckMatrix(matrix, 0.0);
}

TEST(MutatorTests, MutatorsTest6) {
  Matrix matrix(3, 3);

  int rows = 5;
  int cols = 3;

  matrix.set_rows(rows);
  matrix.set_cols(cols);

  EXPECT_EQ(matrix.get_rows(), rows);
  EXPECT_EQ(matrix.get_cols(), cols);
  test_helpers::CheckMatrix(matrix, 0.0);
}

TEST(BracketsTests, BracketTest1) {
  double check_value = 3.5;
  Matrix matrix = test_helpers::FillMatrixValue(3, 3, check_value);

  EXPECT_EQ(matrix(1, 2), check_value);
}

TEST(BracketsTests, BracketTest2) {
  double check_value = 3.5;
  Matrix matrix = test_helpers::FillMatrixValue(3, 3, check_value);

  EXPECT_ANY_THROW(matrix(5, 2));
}

TEST(BracketsTests, BracketTest3) {
  double check_value = 3.5;
  Matrix matrix = test_helpers::FillMatrixValue(3, 3, check_value);

  EXPECT_ANY_THROW(matrix(1, 5));
}

TEST(BracketsTests, BracketConstTest1) {
  double check_value = 3.5;
  Matrix matrix = test_helpers::FillMatrixValue(3, 3, check_value);
  const Matrix check_matrix(matrix);

  EXPECT_ANY_THROW(check_matrix(1, 5));
}

TEST(BracketsTests, BracketConstTest2) {
  double check_value = 3.5;
  Matrix matrix = test_helpers::FillMatrixValue(3, 3, check_value);
  const Matrix check_matrix(matrix);

  EXPECT_ANY_THROW(check_matrix(5, 1));
}

TEST(BracketsTests, BracketConstTest3) {
  double check_value = 3.5;
  Matrix matrix = test_helpers::FillMatrixValue(3, 3, check_value);
  const Matrix check_matrix(matrix);

  EXPECT_ANY_THROW(check_matrix(5, 5));
}