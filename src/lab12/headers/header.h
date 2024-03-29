#ifndef HEADERS
#define HEADERS

#include <stdio.h>

#include <ctime>
#include <fstream>
#include <iostream>

#define MAX_MEM 4000000000

using namespace std;

class Matrix {
 protected:
  double **matrix;
  size_t sizeMatrix;

 public: 
  Matrix();
  Matrix(const size_t sizeMatrix);
  Matrix(double **matrix, const size_t sizeMatrix);
  Matrix(const Matrix &other);
  ~Matrix();

  void SetMatrix(double **matrix, const size_t sizeMatrix);
  double **GetMatrix();
  virtual void Print();
  void Transposition();
  double **Sum(const Matrix &other);

  Matrix operator+(const Matrix &other);
  friend Matrix operator-(const Matrix &minuend, const Matrix &subtrahend);
  Matrix operator=(const Matrix &other);
  Matrix operator++();
  Matrix operator++(int);
  operator bool();

  friend ostream &operator<<(ostream &out, Matrix &C);
  friend istream &operator>>(istream &in, Matrix &C);

  void WriteBinary(char *name);
  void ReadBinary(char *name);
};

class DateCreate : public Matrix {
  int day;
  int month;
  int year;

 public:
  DateCreate();
  DateCreate(int day, int month, int year, int n);
  DateCreate(const DateCreate &other);

  void SetDate();
  virtual void Print();
};

class NameMatrix : public Matrix {
  char name[100];

 public:
  NameMatrix();
  NameMatrix(const char *name, int n);
  NameMatrix(const NameMatrix &other);

  void SetName();
  virtual void Print();
};

struct Node {
    Matrix *data;
    Node *next;
    Node *prev;
  };

class List {
  Node *start;
  Node *head;
  int front;
  Node *tail;
  int rear;

  long long int size;

 public:
  List(long long int size);
  List(const List &other);
  ~List();
  bool isFull();
  bool isEmpty();
  void enQueue(Matrix *element);
  int deQueue();
  void Print();
};

#endif
