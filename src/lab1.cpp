#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Matrix {
 private:
  double **matrix;
  size_t sizeY, sizeX;

 public:
  Matrix() : Matrix(3, 3) {}
  Matrix(const size_t x, const size_t y) {
    sizeY = y;
    sizeX = x;
    matrix = new double *[sizeX];
    for (int i = 0; i < sizeX; i++) matrix[i] = new double[sizeY];

    for (int i = 0; i < sizeX; i++)
      for (int j = 0; j < sizeY; j++) matrix[i][j] = 0;
  }
  Matrix(double **matrix, const size_t x, const size_t y) {
    sizeY = y;
    sizeX = x;
    this->matrix = new double *[sizeX];
    for (int i = 0; i < sizeX; i++) this->matrix[i] = new double[sizeY];

    for (int i = 0; i < sizeX; i++)
      for (int j = 0; j < sizeY; j++) this->matrix[i][j] = matrix[i][j];
  }
  Matrix(const Matrix &other) {
    this->sizeX = other.sizeX;
    this->sizeY = other.sizeY;
    this->matrix = new double *[sizeX];
    for (int i = 0; i < sizeX; i++) this->matrix[i] = new double[sizeY];

    for (int i = 0; i < sizeX; i++)
      for (int j = 0; j < sizeY; j++) this->matrix[i][j] = other.matrix[i][j];
  }

  ~Matrix() {
    for (int i = 0; i < 3; i++) delete[] matrix[i];
    delete[] matrix;
  }

  void SetMatrix(double **matrix, const size_t x, const size_t y) {
    sizeY = y;
    sizeX = x;
    this->matrix = new double *[sizeX];
    for (int i = 0; i < sizeX; i++) this->matrix[i] = new double[sizeY];

    for (int i = 0; i < sizeX; i++)
      for (int j = 0; j < sizeY; j++) this->matrix[i][j] = matrix[i][j];
  }
  double **GetMatrix() {
    double **matrix = new double *[sizeX];
    for (int i = 0; i < sizeX; i++) matrix[i] = new double[sizeY];

    for (int i = 0; i < sizeX; i++)
      for (int j = 0; j < sizeY; j++) matrix[i][j] = this->matrix[i][j];
    return matrix;
  }
  size_t GetSizeX() { return sizeX; }
  size_t GetSizeY() { return sizeY; }
  void ReadMatrix() {
    for (int i = 0; i < sizeX; i++)
      for (int j = 0; j < sizeY; j++) cin >> matrix[i][j];
  }

  void PrintMatrix() {
    for (int i = 0; i < sizeX; i++) {
      for (int j = 0; j < sizeY; j++) cout << matrix[i][j] << ' ';
      cout << endl;
    }
  }

  double *FindElement(double element) {
    for (int i = 0; i < sizeX; i++)
      for (int j = 0; j < sizeY; j++)
        if (element == matrix[i][j]) {
          return &matrix[i][j];
        }
    return NULL;
  }

  void SortByStr() {
    for (int i = 1; i < sizeX; i++) {
      for (int j = i; j > 0 && matrix[j - 1][0] > matrix[j][0]; j--) {
        swap(matrix[j], matrix[j - 1]);
      }
    }
  }
  void SortByСolumn() {
    for (int i = 1; i < sizeY; i++) {
      for (int j = i; j > 0 && matrix[0][j - 1] > matrix[0][j]; j--) {
        for (int k = 0; k < sizeX; k++) {
          swap(matrix[k][j], matrix[k][j - 1]);
        }
      }
    }
  }
  void ReplaсeElement(double replaceElement, double newElement) {
    double *tmp = this->FindElement(replaceElement);
    if(tmp)
    *tmp = newElement;
  }
  void TranspositionMatrix() {
    double **tmpMatrix = this->GetMatrix();
    for (int i = 0; i < sizeX; i++) {
      for (int j = 0; j < sizeY; j++) {
        matrix[i][j] = tmpMatrix[j][i];
      }
    }
    for (int i = 0; i < 3; i++) delete[] tmpMatrix[i];
    delete[] tmpMatrix;
  }
};

void TestMethod() {
  srand(time(NULL));
  cout << "Test SetMatrix:\n";
  const size_t sizeX = 3, sizeY = 3;
  double **arr = new double *[sizeX];
  for (int i = 0; i < sizeX; i++) arr[i] = new double[sizeY];
  for (int i = 0; i < sizeX; i++)
    for (int j = 0; j < sizeY; j++) arr[i][j] = rand() % 10;
  Matrix a(arr, sizeX, sizeY);
  a.PrintMatrix();
  cout << "Test GetMatrix:\n";
  double **t2 = a.GetMatrix();
  for (int i = 0; i < sizeX; i++) {
    for (int j = 0; j < sizeY; j++) cout << t2[i][j] << ' ';
    cout << endl;
  }
  cout << "Test GetSizeX and GetSizeY:\n";
  size_t t3X = a.GetSizeX();
  size_t t3Y = a.GetSizeY();
  cout << "X = " << t3X << "    Y = " << t3Y << endl;

  cout << "Test PrintMatrix:\n";
  a.PrintMatrix();

  cout << "Test FindElement:\nFind 2\n";
  double *t5 = a.FindElement(2);
  if (t5) cout << *t5 << endl;
  cout << "Element not find" << endl;

  cout << "Test ReplaсeElement:\n";
  a.ReplaсeElement(2, 88);
  a.PrintMatrix();
  cout << "Test SortByStr:\n";
  a.SortByStr();
  a.PrintMatrix();
  cout << "Test SortByСolumn:\n";
  a.SortByСolumn();
  a.PrintMatrix();
  cout << "Test TranspositionMatrix:\n";
  a.TranspositionMatrix();
  a.PrintMatrix();
  cout << "Test ReadMatrix:\n";

  for (int i = 0; i < 3; i++) delete[] arr[i];
  delete[] arr;
  for (int i = 0; i < 3; i++) delete[] t2[i];
  delete[] t2;
}

void TestConstructor() {
  cout << "Default constructor create matrix 3x3 filled with zeros:\n";
  Matrix a;
  a.PrintMatrix();

  cout << "Constructor who accepts matrix sizes and filled with zeros:\n";
  Matrix b(5, 5);
  b.PrintMatrix();

  cout << "Constructor who accepts matrix and sizes:\n";
  const size_t sizeX = 3, sizeY = 3;
  double **arr = new double *[sizeX];
  for (int i = 0; i < sizeX; i++) arr[i] = new double[sizeY];
  for (int i = 0; i < sizeX; i++)
    for (int j = 0; j < sizeY; j++) arr[i][j] = i + j;
  Matrix c(arr, sizeX, sizeY);
  c.PrintMatrix();

  cout << "Constructor copying:\nСopy the previous matrix\n";
  Matrix d(c);
  c.PrintMatrix();
  for (int i = 0; i < 3; i++) delete[] arr[i];
  delete[] arr;
  cout << endl << endl;
}

int main() {
  TestConstructor();
  TestMethod();

  return 0;
}
