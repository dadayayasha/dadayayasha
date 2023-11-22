#ifndef HEADER
#define HEADER

#include <iostream>

#include "../lab12/headers/header.h"
using namespace std;



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

  int size;

 public:
  List(int size);
  List(const List &other);
  ~List();

  // int GetCount();
  // Node *GetNode(int);

  // void DelAll();
  // void Del(int pos = 0);
  // void Insert(int pos = 0,Matrix *data);

  // void AddTail(Matrix *data);

  // void Print();
  // void Print(int pos);
  bool isFull();
  bool isEmpty();
  void enQueue(Matrix *element);
  int deQueue();
  void display();
};

#endif
