#include "headers/header.h"

void TestMethod();
void TestConstructor();
void TestOperator();
void TestStream();
void TestChildren();

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
    cout << "5. Test Children \n";

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

      case 5:
        TestChildren();
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
  a.Print();
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
  a.Print();
  a.Transposition();
  cout << endl;
  a.Print();
  cout << endl << endl;

  cout << "Test Sum Matrix:\n";
  double **arr2 = new double *[size];
  for (int i = 0; i < size; i++) arr2[i] = new double[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr2[i][j] = rand() % 100;

  Matrix b(arr2, size);
  a.Print();
  cout << endl;
  b.Print();
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
  cout << "Default constructor create matrix 0x0 filled with zeros:\n";
  Matrix a;

  cout << "Constructor who accepts matrix sizes and filled with zeros:\n";
  Matrix b(5);
  b.Print();
  cout << endl;

  cout << "Constructor who accepts matrix and sizes:\n";
  const size_t size = 3;
  double **arr = new double *[size];
  for (int i = 0; i < size; i++) arr[i] = new double[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
  Matrix c(arr, size);
  c.Print();

  cout << endl;

  cout << "Constructor copying:\nСopy the previous matrix\n";
  Matrix d(c);
  c.Print();
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
  a.Print();
  cout << "Matrix B\n";
  b.Print();
  cout << endl;
  Matrix c = a + b;
  a.operator+(b);
  cout << "Matrix C=A+B\n";
  c.Print();
  cout << endl;
  cout << "Test operator - :\n";
  cout << "Matrix D=A-B\n";
  Matrix d = a - b;
  d.Print();
  cout << endl;

  cout << "Test operator = :\n";
  cout << "Matrix A\n";
  a.Print();
  cout << "Matrix B\n";
  b.Print();
  cout << "Matrix A=B\n";
  a = b;
  a.Print();
  cout << endl;

  cout << "Test operator ++ :\n";
  cout << "Matrix A\n";
  a.Print();
  cout << "Matrix ++A\n";
  (++a).Print();
  cout << "Matrix A++\n";
  (a++).Print();
  cout << "Second print A++\n";
  a.Print();
  cout << endl;

  cout << "Test operator (bool) :\n";
  cout << "Matrix A\n";
  a.Print();
  if (bool(a))
    cout << "Matrix filled\n";
  else
    cout << "Matrix empty\n";
  cout << endl;
  cout << "Matrix F\n";
  Matrix f(3);
  f.Print();
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
  const size_t size = 10;

  double **arr = new double *[size];
  for (int i = 0; i < size; i++) arr[i] = new double[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 10000000000;
  char name[20] = "test.bin";

  {
    Matrix a(3);
    cout << "Enter matrix 3x3\n";
    cin >> a;
    cout << "3x3 matrix output\n";
    cout << a;

    Matrix c(arr,size);
    cout << "Write matrix in file \"test.txt\"\n";
    ofstream out("test.txt");
    if (out.is_open()) {
      out << c;
    }
    out.close();
    system("open test.txt");

    cout << "Write matrix in binary file \"test.bin\"\n";
    c.WriteBinary(name);
  }

  cout << "Read matrix from binary file \"test.bin\"\n";
  Matrix b(size);
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

  for (int i = 0; i < size; i++) delete[] arr[i];
  delete[] arr;
}

void TestChildren(){

  DateCreate a(12,3,2022);
  NameMatrix b("Matrica");
  a.Print();
  cout<< endl;
  b.PrintName();

  cout<< endl;
  cout<< endl;
  Matrix *p= new DateCreate;
  p->Print();
  cout<< endl;

}