#include "header.h"

List::List(int size) {
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

List::List(const List &other) {
//создание очереди
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
//копирование данных
  this->start = this->head;
  Node *tmp = this->start;
  Node *tmp2 = other.start;

  for (int i = 0; i < size; i++) {
    tmp->data = tmp2->data;
    tmp = tmp->next;
    tmp2 = tmp2->next;
  }
//копирование front и rear
  for (int i = 0; i < front; i++) {
    this->head = this->head->next;
  }
  for (int i = 0; i < rear; i++)
  {
    this->tail=this->tail->next;
  }
  
}



List::~List() {
  Node *tmp = start;
  while (size > 1) {
    tmp = tmp->next;
    delete tmp->prev;
    size--;
  }
  delete tmp;
}

bool List::isFull() {
  if (front == 0 && rear == size - 1) {
    return true;
  }
  if (front == rear + 1) {
    return true;
  }
  return false;
}

bool List::isEmpty() {
  if (front == -1)
    return true;
  else
    return false;
}



void List::enQueue(Matrix *element) {
  if (isFull()) {
    cout << "Queue is full";
  } else {
    Matrix *newElement =
        new Matrix(*element);  // Create a new Matrix object on the heap
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

int List::deQueue() {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return (-1);
  } else {
    // head->data = nullptr;

    if (front == rear) {
      front = -1;
      rear = -1;

      head = tail = nullptr;
    } else {
      front = (front + 1) % size;
      head = head->next;
    }
    return 0;
  }
}

void List::display() {
  Node *tmp;
  tmp = head;
  int i;
  if (isEmpty()) {
    cout << endl << "Empty Queue" << endl;
  } else {
    cout << "Front -> " << front;
    cout << endl << "Items:\n ";
    for (i = front; i != rear; i = (i + 1) % size) {
      cout << *tmp->data;
      tmp = tmp->next;
      cout << endl;
    }
    cout << *tmp->data;
    cout << endl << "Rear -> " << rear << endl;
  }
}