
#ifndef HEADERS
#define HEADERS

#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Matrix {
 private:
  double **matrix;
  size_t sizeMatrix;

 public:
  Matrix() : Matrix(3) {}
  Matrix(const size_t sizeMatrix);
  Matrix(double **matrix, const size_t sizeMatrix);
  Matrix(const Matrix &other);
  ~Matrix();

  void SetMatrix(double **matrix, const size_t sizeMatrix);
  double **GetMatrix();
  void PrintMatrix();
  void Transposition();
  double **Sum(Matrix &other); 
};

#endif