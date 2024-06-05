#include "matrix_oop.h"

/*==============================================
=         Constructors and destructor          =
==============================================*/

Matrix::Matrix() : rows_(3), cols_(3) { MemGet(); }

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Rows and cols must be > 0");
  }

  MemGet();
}

Matrix::Matrix(const Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  MemGet();

  for (int i = 0; i < rows_; ++i) {
    std::copy(other.matrix_[i], other.matrix_[i] + other.cols_, matrix_[i]);
  }
}

Matrix::Matrix(Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_) {
  MemGet();

  for (int i = 0; i < rows_; ++i) {
    std::copy(other.matrix_[i], other.matrix_[i] + other.cols_, matrix_[i]);
  }

  other.MemDel();
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

Matrix::~Matrix() { MemDel(); }

/*==============================================
=              Helpfull methods                =
==============================================*/

void Matrix::set_rows(int other_rows) {
  if (other_rows <= 0) {
    throw std::invalid_argument("Rows must be > 0");
  }

  if (other_rows != rows_) {
    Matrix new_matrix(other_rows, cols_);

    int min_rows = std::min(other_rows, rows_);
    for (int i = 0; i < min_rows; ++i)
      for (int j = 0; j < cols_; ++j) new_matrix.matrix_[i][j] = matrix_[i][j];

    *this = new_matrix;
  }
}

void Matrix::set_cols(int other_cols) {
  if (other_cols <= 0) {
    throw std::invalid_argument("Cols must be > 0");
  }

  if (other_cols != cols_) {
    Matrix new_matrix(rows_, other_cols);

    int min_cols = std::min(other_cols, cols_);
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < min_cols; ++j)
        new_matrix.matrix_[i][j] = matrix_[i][j];

    *this = new_matrix;
  }
}

void Matrix::MemDel() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }

    delete[] matrix_;
    matrix_ = nullptr;
  }
}

void Matrix::MemGet() {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]();
  }
}

bool Matrix::EqualSize(const Matrix& other) const {
  return rows_ == other.rows_ && cols_ == other.cols_;
}

bool Matrix::CheckMul(const Matrix& other) const {
  return cols_ == other.rows_;
}

bool Matrix::IsSquare() const { return cols_ == rows_; }

/*==============================================
=                  Operators                   =
==============================================*/

Matrix& Matrix::operator=(const Matrix& other) {
  if (&other != this) {
    MemDel();

    rows_ = other.rows_;
    cols_ = other.cols_;

    MemGet();
    for (int i = 0; i < rows_; ++i)
      std::copy(other.matrix_[i], other.matrix_[i] + other.cols_, matrix_[i]);
  }

  return *this;
}

Matrix& Matrix::operator=(Matrix&& other) {
  MemDel();

  rows_ = other.rows_;
  cols_ = other.rows_;
  MemGet();

  for (int i = 0; i < rows_; ++i)
    std::copy(other.matrix_[i], other.matrix_[i] + other.cols_, matrix_[i]);

  other.MemDel();
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;

  return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
  SumMatrix(other);
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
  SubMatrix(other);
  return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
  MulMatrix(other);

  return *this;
}

Matrix& Matrix::operator*=(double number) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] *= number;

  return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
  Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
  if (!CheckMul(other)) {
    throw std::invalid_argument("Cols of 1st matrix must be = rows of 2nd");
  }

  Matrix result = *this;

  return result *= other;
}

Matrix operator*(double number, const Matrix& other) {
  Matrix result = other;

  return result *= number;
}

Matrix operator*(const Matrix& other, double number) {
  Matrix result = other;

  return result *= number;
}

bool Matrix::operator==(const Matrix& other) const {
  return EqMatrix(other);
}

double& Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Sega))00)");
  }

  return matrix_[i][j];
}

const double& Matrix::operator()(int i, int j) const {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Sega))00)");
  }

  return matrix_[i][j];
}

/*==============================================
=                  Methods                     =
==============================================*/

bool Matrix::EqMatrix(const Matrix& other) const {
  bool check = true;

  if (!EqualSize(other)) {
    check = false;
  } else {
    for (int i = 0; i < rows_ && check; ++i)
      for (int j = 0; j < cols_ && check; ++j)
        if (std::abs(matrix_[i][j] - other.matrix_[i][j]) > kEpsilon)
          check = false;
  }

  return check;
}

void Matrix::SumMatrix(const Matrix& other) {
  if (!EqualSize(other)) {
    throw std::invalid_argument("Matrixes must be the same size");
  }

  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] += other.matrix_[i][j];
}

void Matrix::SubMatrix(const Matrix& other) {
  if (!EqualSize(other)) {
    throw std::invalid_argument("Matrixes must be the same size");
  }

  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] -= other.matrix_[i][j];
}

void Matrix::MulNumber(const double num) { *this *= num; }

void Matrix::MulMatrix(const Matrix& other) {
  if (!CheckMul(other)) {
    throw std::invalid_argument("Cols of 1st matrix must be = rows of 2nd");
  }

  Matrix result_matrix(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < other.cols_; ++j)
      for (int k = 0; k < cols_; ++k)
        result_matrix.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];

  *this = std::move(result_matrix);
}

Matrix Matrix::Transpose() const {
  Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) result.matrix_[j][i] = matrix_[i][j];

  return result;
}

double Matrix::Determinant() const {
  if (!IsSquare()) {
    throw std::invalid_argument("Matrix isn't square");
  }

  Matrix copy(*this);

  return copy.CalculateDeterminant();
}

double Matrix::CalculateDeterminant() {
  double result = 1.0;
  int sign = 1;
  bool check_zero_determinant = MakeTriangleMatrix(&sign);

  if (check_zero_determinant) {
    result = 0.0;
  } else {
    result *= sign;

    for (int i = 0; i < rows_; ++i) result *= matrix_[i][i];
  }

  return result;
}

// Приводим матрицу к треугольному виду
bool Matrix::MakeTriangleMatrix(int* sign) {
  bool zero_determinant = false;

  for (int i = 0; i < rows_ - 1 && !zero_determinant; ++i) {
    int not_null_row_index = -1;  // "-1", т.к. "0" уже занят (индекс элемента)
    int null_row_index = -1;
    bool zero_flag = true;

    // Находим строку с ненулевым первым элементом (относительно rows_)
    for (int ii = i; ii < rows_ && zero_flag; ++ii) {
      if (std::abs(matrix_[ii][i]) > kEpsilon) {
        zero_flag = false;
        not_null_row_index = ii;
      }
    }

    if (!zero_flag) {
      if (std::abs(matrix_[i][i]) < kEpsilon) {
        null_row_index = i;
        std::swap(matrix_[null_row_index], matrix_[not_null_row_index]);
        *sign *= -1;
      }

      MakeColZero(i);
    } else {
      zero_determinant = true;
    }
  }

  return zero_determinant;
}

// Делаем весь столбец в матрице нулевым, за исключением 1ой строки
void Matrix::MakeColZero(int row_index) {
  for (int ii = row_index + 1; ii < rows_; ++ii) {
    double elem = matrix_[ii][row_index] / matrix_[row_index][row_index];

    for (int j = row_index; j < cols_; ++j) {
      matrix_[ii][j] -= matrix_[row_index][j] * elem;
    }
  }
}

Matrix Matrix::CalcComplements() const {
  if (!IsSquare()) {
    throw std::invalid_argument("Matrix isn't square");
  } else if (rows_ < 2 || cols_ < 2) {
    throw std::invalid_argument("Matrix rows or cols < 2");
  }

  Matrix result(rows_, cols_);
  Matrix minor(rows_ - 1, cols_ - 1);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      minor = this->GetMinor(i, j);

      double determinant = minor.CalculateDeterminant();

      if ((i + j) % 2) {
        determinant *= -1.0;
      }

      result.matrix_[i][j] = determinant;
    }
  }

  return result;
}

Matrix Matrix::GetMinor(int& index_i, int& index_j) const {
  Matrix minor(this->rows_ - 1, this->cols_ - 1);

  for (int i = 0, i_mnr = 0; i < this->rows_; ++i) {
    for (int j = 0, j_mnr = 0; j < this->cols_; ++j) {
      if (i != index_i && j != index_j) {
        minor.matrix_[i_mnr][j_mnr] = this->matrix_[i][j];
        ++j_mnr;

        if (j_mnr == minor.cols_) {
          ++i_mnr;
          j_mnr = 0;
        }
      }
    }
  }

  return minor;
}

Matrix Matrix::InverseMatrix() const {
  double determinant = this->Determinant();

  if (std::abs(determinant) < kEpsilon) {
    throw std::invalid_argument("Determinant is 0");
  }

  Matrix calc_complements = CalcComplements();
  Matrix transposed_complements = calc_complements.Transpose();

  Matrix result = 1 / determinant * transposed_complements;

  return result;
}