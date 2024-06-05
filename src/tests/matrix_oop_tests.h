#ifndef MATRIX_OOP_TESTS_H_
#define MATRIX_OOP_TESTS_H_

#include <gtest/gtest.h>

#include <random>

#include "../matrix_oop.h"

namespace test_helpers {

const double kEpsilon(1e-7);

void CheckMatrix(const Matrix&, double);
void CheckMatrix(const Matrix&, const Matrix&);
double GetRandomValue();
Matrix FillMatrixRandom(int, int);
Matrix FillMatrixValue(int, int, double);

}  // namespace test_helpers

#endif  // MATRIX_OOP_TESTS_H_