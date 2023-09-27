#include "headers/header.h"

void TestMethod();
void TestConstructor();

int main() {
  srand(time(NULL));
  TestConstructor();
  TestMethod();

  return 0;
}


void TestMethod() {
  cout << "Test SetMatrix:\n";
  const size_t size = 3;
  double **arr = new double *[size];
  for (int i = 0; i < size; i++) arr[i] = new double[size];

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;

  Matrix a;
  a.SetMatrix(arr, size);
  a.PrintMatrix();
  for (int i = 0; i < 3; i++) delete[] arr[i];
  delete[] arr;
  cout << endl;

  cout << "Test GetMatrix:\n";
  arr = a.GetMatrix();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) printf("%-8.2lf", arr[i][j]);
    cout << endl;
  }
  cout << endl;

  cout << "Test Transposition Matrix:\n";
  a.PrintMatrix();
  a.Transposition();
  cout << endl;
  a.PrintMatrix();
  cout << endl;

  cout << "Test Sum Matrix:\n";
  double **arr2 = new double *[size];
  for (int i = 0; i < size; i++) arr2[i] = new double[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr2[i][j] = rand() % 100;

  Matrix b(arr2, size);
  a.PrintMatrix();
  cout << endl;
  b.PrintMatrix();
  cout << endl;

  double **tmp = a.Sum(b);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) printf("%-8.2lf", tmp[i][j]);
    cout << endl;
  }

  for (int i = 0; i < 3; i++) delete[] arr[i];
  delete[] arr;
  for (int i = 0; i < 3; i++) delete[] arr2[i];
  delete[] arr2;
  for (int i = 0; i < 3; i++) delete[] tmp[i];
  delete[] tmp;
}

void TestConstructor() {
  cout << "Default constructor create matrix 3x3 filled with zeros:\n";
  Matrix a;
  a.PrintMatrix();
  cout << endl;

  cout << "Constructor who accepts matrix sizes and filled with zeros:\n";
  Matrix b(5);
  b.PrintMatrix();
  cout << endl;

  cout << "Constructor who accepts matrix and sizes:\n";
  const size_t size = 4;
  double **arr = new double *[size];
  for (int i = 0; i < size; i++) arr[i] = new double[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
  Matrix c(arr, size);
  c.PrintMatrix();
  for (int i = 0; i < 3; i++) delete[] arr[i];
  delete[] arr;
  cout << endl;

  cout << "Constructor copying:\nСopy the previous matrix\n";
  Matrix d(c);
  c.PrintMatrix();

  cout << endl << endl;
}


