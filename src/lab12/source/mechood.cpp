#include "../headers/header.h"

Matrix::Matrix() {
  sizeMatrix = 0;
  matrix = nullptr;
}

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
    if (matrix[i]) delete[] matrix[i];
    matrix[i] = nullptr;
  }
  if (matrix) delete[] matrix;
  matrix = nullptr;
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

void Matrix ::Print() {
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
  if (&other == this) return *this;
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
  // for (int i = 0; i < sizeMatrix; i++) {
  //   for (int j = 0; j < sizeMatrix; j++) {
  //     matrix[i][j]++;
  //   }
  // }
  ++(*this);
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

ostream &operator<<(ostream &out, Matrix &C) {
  for (int i = 0; i < C.sizeMatrix; i++) {
    for (int j = 0; j < C.sizeMatrix; j++) out << C.matrix[i][j] << " ";
    // printf("%-8.2lf", C.matrix[i][j]);
    out << endl;
  }
  return out;
}

istream &operator>>(istream &in, Matrix &C) {
  for (int i = 0; i < C.sizeMatrix; i++) {
    for (int j = 0; j < C.sizeMatrix; j++) in >> C.matrix[i][j];
  }
  return in;
}

void Matrix ::WriteBinary(char *name) {
  ofstream out(name, ios::binary);
  if (out.is_open()) {
    out.write((char *)&sizeMatrix, sizeof(sizeMatrix));
    for (int i = 0; i < sizeMatrix; i++) {
      for (int j = 0; j < sizeMatrix; j++) {
        out.write((char *)&matrix[i][j], sizeof(matrix[i][j]));
      }
    }
  }
  out.close();
}

void Matrix ::ReadBinary(char *name) {
  ifstream in(name, ios::binary);
  if (in.is_open()) {
    for (int i = 0; i < sizeMatrix; i++) delete[] matrix[i];
    delete[] matrix;
    in.read((char *)&sizeMatrix, sizeof(sizeMatrix));
    matrix = new double *[sizeMatrix];
    for (int i = 0; i < sizeMatrix; i++) matrix[i] = new double[sizeMatrix];
    for (int i = 0; i < sizeMatrix; i++) {
      for (int j = 0; j < sizeMatrix; j++) {
        in.read((char *)&matrix[i][j], sizeof(matrix[i][j]));
      }
    }
  }
  in.close();
}

DateCreate ::DateCreate() {
  day = 0;
  month = 0;
  year = 0;
}
DateCreate ::DateCreate(int day, int month, int year) {
  this->day = day;
  this->month = month;
  this->year = year;
}

DateCreate ::DateCreate(const DateCreate &other) {
  this->day = other.day;
  this->month = other.month;
  this->year = other.year;
}

void DateCreate::SetDate() {
  cout << "day:";
  cin >> day;
  cout << "\nmonth:";
  cin >> month;
  cout << "\nyear:";
  cin >> year;
  cout << endl;
}

void DateCreate::Print() {
  cout << "day: " << day;
  cout << "\nmonth: " << month;
  cout << "\nyear: " << year;
  cout << endl;
}

NameMatrix::NameMatrix() { strcpy(this->name, "none"); }

NameMatrix::NameMatrix(const char *name) { strcpy(this->name, name); }

NameMatrix ::NameMatrix(const NameMatrix &other) {
  strcpy(this->name, other.name);
}

void NameMatrix::SetName() {
  // char name[100];
  cout << "Enter name: ";
  cin >> name;
  cout << endl;
  // strcpy(this->name,name);
}

void NameMatrix::PrintName() { cout << name << endl; }