#include "../headers/header.h"

Matrix::Matrix() {
  sizeMatrix = 0;
  matrix = nullptr;
}

Matrix::Matrix(const size_t sizeMatrix) {
  if (sizeMatrix * sizeMatrix > MAX_MEM / sizeof(double) || sizeMatrix < 1)
    throw -1;

  this->sizeMatrix = sizeMatrix;
  matrix = new double *[sizeMatrix];
  for (int i = 0; i < sizeMatrix; i++) matrix[i] = new double[sizeMatrix];

  for (int i = 0; i < sizeMatrix; i++)
    for (int j = 0; j < sizeMatrix; j++) matrix[i][j] = 0;
}

Matrix::Matrix(double **matrix, const size_t sizeMatrix) {
  if (sizeMatrix * sizeMatrix > MAX_MEM / sizeof(double) || sizeMatrix < 1)
    throw -1;
  if (!matrix) throw 0;

  this->sizeMatrix = sizeMatrix;
  this->matrix = new double *[sizeMatrix];
  for (int i = 0; i < sizeMatrix; i++) this->matrix[i] = new double[sizeMatrix];

  for (int i = 0; i < sizeMatrix; i++)
    for (int j = 0; j < sizeMatrix; j++) this->matrix[i][j] = matrix[i][j];
}

Matrix ::Matrix(const Matrix &other) {
  //if (!(&other)) throw 1;

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
  if (sizeMatrix * sizeMatrix > MAX_MEM / sizeof(double) || sizeMatrix < 1)
    throw -1;
  if (!matrix) throw 0;

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
  //if (!(&other)) throw 1;

  double **tmp = this->GetMatrix();
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      tmp[i][j] += other.matrix[i][j];
    }
  }
  return tmp;
}

Matrix Matrix ::operator+(const Matrix &other) {
  //if (!(&other)) throw 1;

  Matrix sum = other;
  for (int i = 0; i < sizeMatrix; i++) {
    for (int j = 0; j < sizeMatrix; j++) {
      sum.matrix[i][j] += matrix[i][j];
    }
  }
  return sum;
}

Matrix operator-(const Matrix &minuend, const Matrix &subtrahend) {
  //if (!(&minuend || &subtrahend)) throw 1;

  Matrix diff = minuend;
  for (int i = 0; i < minuend.sizeMatrix; i++) {
    for (int j = 0; j < minuend.sizeMatrix; j++) {
      diff.matrix[i][j] -= subtrahend.matrix[i][j];
    }
  }
  return diff;
}

Matrix Matrix ::operator=(const Matrix &other) {
  //if (!(&other)) throw 1;

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
DateCreate ::DateCreate(int day, int month, int year, int n) : Matrix(n) {
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
  Matrix::Print();
  cout << "day: " << day;
  cout << "\nmonth: " << month;
  cout << "\nyear: " << year;
  cout << endl;
}

NameMatrix::NameMatrix() { strcpy(this->name, "none"); }

NameMatrix::NameMatrix(const char *name, int n) : Matrix(n) {
  strcpy(this->name, name);
}

NameMatrix ::NameMatrix(const NameMatrix &other) {
  strcpy(this->name, other.name);
}

void NameMatrix::SetName() {
  cout << "Enter name: ";
  cin >> name;
  cout << endl;
}

void NameMatrix::Print() {
  Matrix::Print();
  cout << name << endl;
}


List::List(long long int size) {
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

List::List(const List &other) {
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
      Matrix *newElement = new Matrix(*tmp2->data);
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

List::~List() {
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
    cout << "Queue is full\n";
  } else {
    if (!element) throw "Matrix is empty\n";
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
      head = head->next;
    }
    return 0;
  }
}

void List::Print() {
  Node *tmp;
  tmp = head;
  int i;
  if (isEmpty()) {
    cout << endl << "Empty Queue\n" << endl;
  } else {
    cout << "Front -> " << front;
    cout << endl << "Items:\n ";
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

