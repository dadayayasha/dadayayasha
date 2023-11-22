#include "header.h"

int main() {
  List a(5);
  const size_t size = 3;

  double **arr = new double *[size];
  for (int i = 0; i < size; i++) arr[i] = new double[size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
  Matrix a1(arr, size);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
  Matrix a2(arr, size);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
  Matrix a3(arr, size);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
  Matrix a4(arr, size);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
  Matrix a5(arr, size);

  a.enQueue(&a1);
  a.enQueue(&a2);
  a.enQueue(&a3);
  a.enQueue(&a4);
  a.enQueue(&a5);
  //a.display();
  cout << endl;

  a.deQueue();
  a.deQueue();
 // a.display();
  cout << endl;

a.enQueue(&a1);
  //a.display();
  cout << endl;

  for (int i = 0; i < size; i++) delete[] arr[i];
  delete[] arr;

  List b(a);
  a.display();
  b.display();
}