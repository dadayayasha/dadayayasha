#include "../headers/header.h"

Matrix::Matrix(const size_t sizeMatrix) {
  this->sizeMatrix = sizeMatrix;
  matrix = new double *[sizeMatrix];
  for (int i = 0; i < sizeMatrix; i++) matrix[i] = new double[sizeMatrix];

  for (int i = 0; i < sizeMatrix; i++)
    for (int j = 0; j < sizeMatrix; j++) matrix[i][j] = 0;
}

Matrix::Matrix(double **matrix, const size_t sizeMatrix) {
  this->sizeMatrix = sizeMatrix;
  this->matrix = new double *[sizeMatrix];
  for (int i = 0; i < sizeMatrix; i++) this->matrix[i] = new double[sizeMatrix];

  for (int i = 0; i < sizeMatrix; i++)
    for (int j = 0; j < sizeMatrix; j++) this->matrix[i][j] = matrix[i][j];
}

Matrix ::Matrix(const Matrix &other) {
  this->sizeMatrix = other.sizeMatrix;
  this->matrix = new double *[sizeMatrix];
  for (int i = 0; i < sizeMatrix; i++) this->matrix[i] = new double[sizeMatrix];

  for (int i = 0; i < sizeMatrix; i++)
    for (int j = 0; j < sizeMatrix; j++)
      this->matrix[i][j] = other.matrix[i][j];
}

Matrix ::~Matrix() {
  for (int i = 0; i < sizeMatrix; i++) {
    if(matrix[i])delete[] matrix[i];
    matrix[i] = nullptr;  // Set pointer to nullptr after deletion
  }
  if(matrix)delete[] matrix;
  matrix = nullptr;  // Set pointer to nullptr after deletion
}

void Matrix ::SetMatrix(double **matrix, const size_t sizeMatrix) {
  for (int i = 0; i < sizeMatrix; i++)
    for (int j = 0; j < sizeMatrix; j++) this->matrix[i][j] = matrix[i][j];
}

double **Matrix ::GetMatrix() {
  double **matrix = new double *[sizeMatrix];
  for (int i = 0; i < sizeMatrix; i++) matrix[i] = new double[sizeMatrix];

  for (int i = 0; i < sizeMatrix; i++)
    for (int j = 0; j < sizeMatrix; j++) matrix[i][j] = this->matrix[i][j];
  return matrix;
}

void Matrix ::PrintMatrix() {
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) printf("%-8.2lf", matrix[i][j]);
    cout << endl;
  }
}

void Matrix ::Transposition() {
  double **tmp = this->GetMatrix();
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      matrix[i][j] = tmp[j][i];
    }
  }
  for (int i = 0; i < sizeMatrix; i++) delete[] tmp[i];
  delete[] tmp;
}

double **Matrix ::Sum(const Matrix &other) {
  double **tmp = this->GetMatrix();
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      tmp[i][j] += other.matrix[i][j];
    }
  }
  return tmp;
}

Matrix Matrix ::operator+(const Matrix &other) {
  Matrix sum = other;
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      sum.matrix[i][j] += matrix[i][j];
    }
  }
  return sum;
}

Matrix operator-(const Matrix &minuend, const Matrix &subtrahend) {
  Matrix diff = minuend;
  for (int i = 0; i < minuend.sizeMatrix; i++) {
    for (int j = 0; j < minuend.sizeMatrix; j++) {
      diff.matrix[i][j] -= subtrahend.matrix[i][j];
    }
  }
  return diff;
}

Matrix Matrix ::operator=(const Matrix &other) {
  sizeMatrix = other.sizeMatrix;
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      matrix[i][j] = other.matrix[i][j];
    }
  }

  return *this;
}

Matrix Matrix ::operator++() {
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      matrix[i][j] += 1;
    }
  }
  return *this;
}

Matrix Matrix ::operator++(int) {
  Matrix copy(*this);
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      matrix[i][j]++;
    }
  }
  return copy;
}

Matrix ::operator bool() {
  bool matrixExists = false;
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      if (matrix[i][j] != 0) {
        matrixExists = true;
        break;
      }
    }
  }

  return matrixExists;
}

ostream& operator << (ostream& out, Matrix& C){
  for (int i = 0; i < C.sizeMatrix; i++) {
    for (int j = 0; j < C.sizeMatrix; j++) out << C.matrix[i][j]<<" ";
    //printf("%-8.2lf", C.matrix[i][j]);
    out << endl;
  }
  return out;
}

istream& operator >> (istream& in, Matrix& C){
  
  for (int i = 0; i < C.sizeMatrix; i++) {
    for (int j = 0; j < C.sizeMatrix; j++) in>> C.matrix[i][j];
  }
  return in;
}

