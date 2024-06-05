#include "../matrix_oop_tests.h"

TEST(EqMatrixTests, EqMatrixOperatorTest1) {
  Matrix matrix1(3, 3);
  Matrix matrix2(3, 3);

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(EqMatrixTests, EqMatrixOperatorTest2) {
  Matrix matrix1(3, 3);
  Matrix matrix2(1, 1);

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(EqMatrixTests, EqMatrixOperatorTest3) {
  Matrix matrix1(3, 3);
  Matrix matrix2(3, 3);

  matrix1(0, 1) = 2.0;
  matrix2(1, 0) = 3.0;

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(EqMatrixTests, EqMatrixOperatorTest4) {
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(EqMatrixTests, EqMatrixOperatorTest5) {
  Matrix matrix1 = test_helpers::FillMatrixRandom(4, 4);
  Matrix matrix2 = matrix1;

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(EqMatrixTests, EqMatrixFuncTest1) {
  const Matrix matrix1 = test_helpers::FillMatrixRandom(4, 4);
  Matrix matrix2 = matrix1;

  bool result = matrix1.EqMatrix(matrix2);

  EXPECT_TRUE(result);
}

TEST(EqMatrixTests, EqMatrixFuncTest2) {
  Matrix matrix1 = test_helpers::FillMatrixRandom(4, 4);
  Matrix matrix2(3, 3);

  bool result = matrix1.EqMatrix(matrix2);

  EXPECT_FALSE(result);
}

TEST(EqMatrixTests, EqMatrixFuncTest3) {
  Matrix matrix1 = test_helpers::FillMatrixRandom(4, 4);
  Matrix matrix2(4, 4);

  bool result = matrix1.EqMatrix(matrix2);

  EXPECT_FALSE(result);
}

TEST(EqMatrixTests, EqMatrixFuncTest4) {
  Matrix matrix1{2, 2};
  Matrix matrix2{2, 2};

  matrix2(0, 0) = 0.0000001;

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  test_helpers::CheckMatrix(matrix1, 0.0);
  test_helpers::CheckMatrix(matrix2, 0.0);

  matrix1(0, 0) = 0.0000001;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);

  test_helpers::CheckMatrix(matrix1, 0.0);
  test_helpers::CheckMatrix(matrix2, 0.0);
}

TEST(EqMatrixTests, EqMatrixFuncTest5) {
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 2);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  test_helpers::CheckMatrix(matrix1, 0.0);
  test_helpers::CheckMatrix(matrix2, 0.0);

  matrix1(0, 0) = 5.0;
  matrix2(0, 0) = 5.0;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 100.0000001;
  matrix2(0, 0) = 100.0;

  bool result3 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result3);
  EXPECT_TRUE(matrix1 == matrix2);
}