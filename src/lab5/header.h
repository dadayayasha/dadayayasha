#ifndef HEADER
#define HEADER

#include <iostream>

#include "../lab12/headers/header.h"
using namespace std;




template <typename Data>
class List {

  struct Node {
  Data *data;
  Node *next;
  Node *prev;

};

  Node *start;

  Node *head;
  int front;
  
  Node *tail;
  int rear;

  long long int size;

 public:

 List(long long int size) {
  if (size > MAX_MEM / sizeof(Node) || size < 1) throw "Uncorrect size\n";

  head = tail = nullptr;
  front = rear = -1;
  this->size = size;

  while (size > 0) {
    Node *temp = new Node;
    temp->next = head;
    temp->data = nullptr;
    temp->prev = tail;
    // cout<<temp->next<<endl;

    if (tail != 0) {
      head->prev = temp;
      tail->next = temp;
    }

    if (size == this->size) {
      head = tail = temp;
    } else {
      tail = temp;
    }

    size--;
  }
  start = head;
}

List(const List &other) {
  // создание очереди
  this->head = this->tail = nullptr;
  this->front = other.front;
  this->rear = other.rear;
  this->size = other.size;

  for (int i = 0; i < other.size; i++) {
    Node *temp = new Node;
    temp->next = this->head;
    temp->data = nullptr;
    temp->prev = this->tail;

    if (tail != 0) {
      this->head->prev = temp;
      this->tail->next = temp;
    }

    if (i == 0) {
      this->head = this->tail = temp;
    } else {
      this->tail = temp;
    }
  }
  // копирование данных
  this->start = this->head;
  Node *tmp = this->start;
  Node *tmp2 = other.start;

  for (int i = 0; i < size; i++) {
    if (tmp2->data) {
      Data *newElement = new Data(*tmp2->data);
      tmp->data = newElement;
    }
    tmp = tmp->next;
    tmp2 = tmp2->next;
  }
  // копирование front и rear
  for (int i = 0; i < front; i++) {
    this->head = this->head->next;
  }
  for (int i = 0; i < rear; i++) {
    this->tail = this->tail->next;
  }
}

~List() {
  long long int n = size;
  Node *tmp = start;
  while (n > 1) {
    tmp = tmp->next;
    if (tmp->prev->data) delete tmp->prev->data;
    delete tmp->prev;
    n--;
  }
  if (tmp->data) delete tmp->data;
  delete tmp;
}

bool isFull() {
  if (front == 0 && rear == size - 1) {
    return true;
  }
  if (front == rear + 1) {
    return true;
  }
  return false;
}

bool isEmpty() {
  if (front == -1)
    return true;
  else
    return false;
}

void enQueue(Data *element) {
  if (isFull()) {
    cout << "Queue is full\n";
  } else {
    if (!element) throw "Matrix is empty\n";
    Data *newElement =
        new Data(*element);  // Create a new Matrix object on the heap
    if (front == -1) {
      front = 0;
      rear = 0;
      tail = head;
      tail->data = newElement;
    } else {
      rear = (rear + 1) % size;
      tail = tail->next;
      tail->data = newElement;
    }
    cout << endl << "Inserted \n" << *newElement << endl;
  }
}

int deQueue() {
  if (isEmpty()) {
    cout << "Queue is empty\n" << endl;
    return (-1);
  } else {
    // head->data = nullptr;

    if (front == rear) {
      front = -1;
      rear = -1;

      head = tail = nullptr;
    } else {
      front = (front + 1) % size;
      delete head->data;
      head->data = nullptr;
      head = head->next;
    }
    return 0;
  }
}

void Print() {
  Node *tmp;
  tmp = head;
  int i;
  if (isEmpty()) {
    cout << endl << "Empty Queue\n" << endl;
  } else {
    cout << "Front -> " << front;
    cout << endl << "Items:\n";
    for (i = front; i != rear; i = (i + 1) % size) {
      if (!(tmp->data)) throw "Node is empty";
      cout << *tmp->data;
      tmp = tmp->next;
      cout << endl;
    }
    cout << *tmp->data;
    cout << endl << "Rear -> " << rear << endl;
  }
}

// // Matrix *Get(int pos) {
//   Node *tmp = start;
//   if ((pos < 0 || pos >= size) || (pos < front || pos > rear)) {
//     throw "Uncorrect position!!!\n";
//   }

//   while (pos--) tmp = tmp->next;

//   data *newElement = new data(*tmp->data);

//   return newElement;
//   ;
// }
//   List(long long int size);
//   List(const List &other);
//   ~List();


//   //Matrix* Get(int pos);
//   bool isFull();
//   bool isEmpty();
//   void enQueue(data *element);
//   int deQueue();
//   void Print();
};

#endif
