#include "matrix_oop_tests.h"

void test_helpers::CheckMatrix(const Matrix& test, double num) {
  for (int i = 0; i < test.get_rows(); ++i)
    for (int j = 0; j < test.get_cols(); ++j)
      ASSERT_NEAR(test(i, j), num, test_helpers::kEpsilon);
}

void test_helpers::CheckMatrix(const Matrix& test, const Matrix& check) {
  for (int i = 0; i < test.get_rows(); ++i)
    for (int j = 0; j < test.get_cols(); ++j)
      ASSERT_NEAR(test(i, j), check(i, j), kEpsilon);
}

double test_helpers::GetRandomValue() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-99, 99);

  double random_value = dis(gen);
  return random_value;
}

Matrix test_helpers::FillMatrixRandom(int rows, int cols) {
  Matrix test(rows, cols);

  for (int i = 0; i < test.get_rows(); ++i)
    for (int j = 0; j < test.get_cols(); ++j) test(i, j) = GetRandomValue();

  return test;
}

Matrix test_helpers::FillMatrixValue(int rows, int cols, double value) {
  Matrix test(rows, cols);

  for (int i = 0; i < test.get_rows(); ++i)
    for (int j = 0; j < test.get_cols(); ++j) test(i, j) = value;

  return test;
}