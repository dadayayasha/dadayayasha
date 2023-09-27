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
  for (int i = 0; i < 3; i++) delete[] matrix[i];
  delete[] matrix;
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
  for (int i = 0; i < 3; i++) delete[] tmp[i];
  delete[] tmp;
}

double **Matrix ::Sum(Matrix &other) {
    double **tmp = other.GetMatrix();
    for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      tmp[i][j]+=matrix[i][j];
    }
  }
  return tmp;
}
