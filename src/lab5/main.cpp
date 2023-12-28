#include "header.h"

void pattern();

// void try_cathc_list() {
//   try {
//     List a(5);
//     // List a(1000000000);
//     // List a(-34);

//     const size_t size = 3;

//     double **arr = new double *[size];
//     for (int i = 0; i < size; i++) arr[i] = new double[size];
//     for (int i = 0; i < size; i++)
//       for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
//     Matrix a1(arr, size);

//     for (int i = 0; i < size; i++)
//       for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
//     Matrix a2(arr, size);

//     for (int i = 0; i < size; i++)
//       for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
//     Matrix a3(arr, size);

//     for (int i = 0; i < size; i++)
//       for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
//     Matrix a4(arr, size);

//     for (int i = 0; i < size; i++)
//       for (int j = 0; j < size; j++) arr[i][j] = rand() % 100;
//     Matrix a5(arr, size);

//     a.enQueue(&a1);
//     a.enQueue(&a2);
//     a.enQueue(&a3);
//     a.enQueue(&a4);
//     a.enQueue(&a5);
//     // a.enQueue(nullptr);
//     a.Print();
//     cout << endl;

//     a.deQueue();
//     a.deQueue();
//     a.Print();
//     cout << endl;

//     a.enQueue(&a1);
//     a.Print();
//     cout << endl;

//     for (int i = 0; i < size; i++) delete[] arr[i];
//     delete[] arr;

//     List<Matrix> b(a);
//     a.Print();
//     b.Print();

//     // Matrix *bb = a.Get(2);

//     // Matrix *bb = a.Get(4);

//     // cout<<*bb<<endl;
//     // delete bb;

//   } catch (const char *errorMessage) {
//     cout << endl << errorMessage << endl;
//   }
// }

// void try_cath_matrix() {
//   try {
//     // Matrix a(100000000000);
//     Matrix b(NULL, 10);

//   } catch (int i) {
//     cout << "Error code: " << i << endl;
//   }
// }

int main() {
  //try_cathc_list();
  // try_cath_matrix();
  pattern();
}

void pattern() {
  List<int> a(10);

  int arr[10];
   for (int i = 0; i < 10; i++)
   {
    arr[i]='A'+i;
    a.enQueue(&arr[i]);
   }
   a.deQueue();
   
   a.Print();
}

