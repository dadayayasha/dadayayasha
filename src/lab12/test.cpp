#include "headers/header.h"

void TestMethod();
void TestConstructor();
void TestOperator();
void TestStream();

int main() {
  srand(time(NULL));
  int menu = 1;
  system("clear");

  while (menu) {
    cout << "0. Exit\n";
    cout << "1. Test Constructor\n";
    cout << "2. Test Method\n";
    cout << "3. Test Operator\n";
    cout << "4. Test Stream \n";

    cin >> menu;
    system("clear");
    switch (menu) {
      case 1:
        TestConstructor();
        break;

      case 2:
        TestMethod();
        break;

      case 3:
        TestOperator();
        break;

      case 4:
        TestStream();
        break;

      default:
        break;
    }
  }

  return 0;
}

void TestMethod() {
  cout << "Test SetMatrix:\n";
  const size_t size = 3;
  double **arr = new double *[size];
  for (int i = 0; i < size; i++) arr[i] = new double[size];

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;

  Matrix a(3);
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
  cout << endl << endl;

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

  cout << endl;
}

void TestConstructor() {
  cout << "Default constructor create matrix 3x3 filled with zeros:\n";
  Matrix a(3);
  a.PrintMatrix();
  cout << endl;

  cout << "Constructor who accepts matrix sizes and filled with zeros:\n";
  Matrix b(5);
  b.PrintMatrix();
  cout << endl;

  cout << "Constructor who accepts matrix and sizes:\n";
  const size_t size = 3;
  double **arr = new double *[size];
  for (int i = 0; i < size; i++) arr[i] = new double[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
  Matrix c(arr, size);
  c.PrintMatrix();

  cout << endl;

  cout << "Constructor copying:\nСopy the previous matrix\n";
  Matrix d(c);
  c.PrintMatrix();
  for (int i = 0; i < size; i++) delete[] arr[i];
  delete[] arr;
  cout << endl;
}

void TestOperator() {
  const size_t size = 3;

  cout << "Test operator + :\n";

  double **arr = new double *[size];
  for (int i = 0; i < size; i++) arr[i] = new double[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;

  double **arr2 = new double *[size];
  for (int i = 0; i < size; i++) arr2[i] = new double[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr2[i][j] = rand() % 100;
  Matrix a(arr, size);
  Matrix b(arr2, size);
  cout << "Matrix A\n";
  a.PrintMatrix();
  cout << "Matrix B\n";
  b.PrintMatrix();
  cout << endl;
  Matrix c = a + b;
  cout << "Matrix C=A+B\n";
  c.PrintMatrix();
  cout << endl;

  cout << "Test operator - :\n";
  cout << "Matrix D=A-B\n";
  Matrix d = a - b;
  d.PrintMatrix();
  cout << endl;

  cout << "Test operator = :\n";
  cout << "Matrix A\n";
  a.PrintMatrix();
  cout << "Matrix B\n";
  b.PrintMatrix();
  cout << "Matrix A=B\n";
  a = b;
  a.PrintMatrix();
  cout << endl;

  cout << "Test operator ++ :\n";
  cout << "Matrix A\n";
  a.PrintMatrix();
  cout << "Matrix ++A\n";
  (++a).PrintMatrix();
  cout << "Matrix A++\n";
  (a++).PrintMatrix();
  cout << "Second print A++\n";
  a.PrintMatrix();
  cout << endl;

  cout << "Test operator (bool) :\n";
  cout << "Matrix A\n";
  a.PrintMatrix();
  if (bool(a))
    cout << "Matrix filled\n";
  else
    cout << "Matrix empty\n";
  cout << endl;
  cout << "Matrix F\n";
  Matrix f(3);
  f.PrintMatrix();
  if (bool(f))
    cout << "Matrix filled\n";
  else
    cout << "Matrix empty\n";
  cout << endl;

  for (int i = 0; i < size; i++) delete[] arr[i];
  delete[] arr;
  for (int i = 0; i < size; i++) delete[] arr2[i];
  delete[] arr2;
}

void TestStream() {
  // const size_t size = 3;

  // double **arr = new double *[size];
  // for (int i = 0; i < size; i++) arr[i] = new double[size];
  // for (int i = 0; i < size; i++)
  //   for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
  char name[20] = "test.bin";
  {
    Matrix a(3);
    cout << "Enter matrix 3x3\n";
    cin >> a;
    cout << "3x3 matrix output\n";
    cout << a;

    cout << "Write matrix in file \"test.txt\"\n";
    ofstream out("test.txt");
    if (out.is_open()) {
      out << a;
    }
    out.close();
    system("open test.txt");

    cout << "Write matrix in binary file \"test.bin\"\n";
    a.WriteBinary(name);
  }

  cout << "Read matrix from binary file \"test.bin\"\n";
  Matrix b(3);
  b.ReadBinary(name);
  cout << b;
  // ofstream out("test.bin",ios_base::binary);
  //   if (out.is_open()){
  //     cout <<"Writing...\n";
  //     out.write((char*)&a, sizeof(a));
  //     //out << a;
  //   }
  // out.close();

  // Matrix b(3);
  // ifstream in("test.bin",ios_base::binary);
  //   if(in.is_open()){
  //     cout<< "Reading...\n";
  //     in.read((char*)&b, sizeof(b));

  //   }
  // in.close();
  // cout << b;

  // for (int i = 0; i < size; i++) delete[] arr[i];
  // delete[] arr;
}
