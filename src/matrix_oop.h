#ifndef MATRIX_OOP_H_
#define MATRIX_OOP_H_

#include <algorithm>
#include <cstring>
#include <stdexcept>

class Matrix {
 public:
  Matrix();
  explicit Matrix(int rows, int cols);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other);
  Matrix& operator=(const Matrix&);
  Matrix& operator=(Matrix&&);
  ~Matrix();

  Matrix& operator+=(const Matrix&);
  Matrix& operator-=(const Matrix&);
  Matrix& operator*=(const Matrix&);
  Matrix& operator*=(double);
  Matrix operator+(const Matrix&) const;
  Matrix operator-(const Matrix&) const;
  Matrix operator*(const Matrix&) const;
  friend Matrix operator*(double, const Matrix&);
  friend Matrix operator*(const Matrix&, double);
  bool operator==(const Matrix& other) const;
  double& operator()(int, int);  // для мутабельных объектов
  const double& operator()(int, int) const;  // для иммутабельных объектов

  bool EqMatrix(const Matrix& other) const;
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const Matrix& other);
  Matrix Transpose() const;
  double Determinant() const;
  Matrix CalcComplements() const;
  Matrix InverseMatrix() const;

  int get_rows() const { return rows_; }
  int get_cols() const { return cols_; }
  void set_rows(const int rows);
  void set_cols(const int cols);

 private:
  int rows_, cols_;
  double** matrix_ = nullptr;
  const double kEpsilon = 1e-7;

  void MemDel();
  void MemGet();
  bool EqualSize(const Matrix&) const;
  bool CheckMul(const Matrix&) const;
  bool IsSquare() const;
  void MakeColZero(int);
  double CalculateDeterminant();
  bool MakeTriangleMatrix(int*);
  Matrix GetMinor(int&, int&) const;
};

#endif  // MATRIX_OOP_H_