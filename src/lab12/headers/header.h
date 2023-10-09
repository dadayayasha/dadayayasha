
#ifndef HEADERS
#define HEADERS

#include <stdio.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

class Matrix {
 private:
  double **matrix;
  size_t sizeMatrix;

 public:
  //Matrix() : Matrix(3) {}
  Matrix(const size_t sizeMatrix);
  Matrix(double **matrix, const size_t sizeMatrix);
  Matrix(const Matrix &other);
  ~Matrix();

  void SetMatrix(double **matrix, const size_t sizeMatrix);
  double **GetMatrix();
  void PrintMatrix();
  void Transposition();
  double **Sum(const Matrix &other);

  Matrix operator+(const Matrix &other);
  friend Matrix operator-(const Matrix &minuend, const Matrix &subtrahend);
  Matrix operator=(const Matrix &other);
  Matrix operator++();
  Matrix operator++(int);
  operator bool();

  friend ostream& operator << (ostream& out, Matrix& C);
  friend istream& operator >> (istream& in, Matrix& C);

};

#endif