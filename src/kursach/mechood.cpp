#include "header.h"

Visit::Visit() {
  lastName = new char[20];
  group = new char[20];
  date = new char *[18];
  for (int i = 0; i < 18; i++) {
    date[i] = new char[20];
  }
  dateCnt = 0;
}

Visit::Visit(const char *name, const char *group) {
  lastName = new char[20];
  this->group = new char[20];
  date = new char *[18];
  for (int i = 0; i < 18; i++) {
    date[i] = new char[20];
  }
  dateCnt = 0;
  strcpy(lastName, name);
  strcpy(this->group, group);
}

Visit::Visit(const Visit &other) {
  lastName = new char[20];
  group = new char[20];
  date = new char *[18];
  for (int i = 0; i < 18; i++) {
    date[i] = new char[20];
  }
  dateCnt = other.dateCnt;
  for (int i = 0; i < dateCnt; i++) {
    strcpy(date[i], other.date[i]);
  }
  strcpy(lastName, other.lastName);
  strcpy(group, other.group);
}

Visit::~Visit() {
  if (lastName) delete[] lastName;
  if (group) delete[] group;
  if (date) {
    for (int i = 0; i < 18; i++) {
      delete[] date[i];
    }
    delete[] date;
  }
}

void Visit::addDate(const char *date) {
  strcpy(this->date[dateCnt], date);
  dateCnt++;
}

char *Visit::getName() { return this->lastName; }
char *Visit::getGroup() { return this->group; }
char **Visit::getDate() { return this->date; }
int Visit::getDateCnt() { return this->dateCnt; }

ostream &operator<<(ostream &out, Visit &C) {
  cout << C.lastName << "\t";
  cout << C.group << endl;
  for (int i = 0; i < C.dateCnt; i++) {
    cout << C.date[i] << "  ";
  }
  cout << endl;

  return out;
}

istream &operator>>(istream &in, Visit &C) {
  cout << "\nEnter students lastname: ";
  cin >> C.lastName;
  cout << "\nEnter students group: ";
  cin >> C.group;
  cout << "\nThe number of classes attended: ";
  cin >> C.dateCnt;
  cout << "\nEnter the dates of the attended classes in the format of DD.MM.YY "
          ": ";

  for (int i = 0; i < C.dateCnt; i++) {
    cin >> C.date[i];
  }

  return in;
}

bool operator>(const Visit &first, const Visit &second) {
  if (strcmp(first.lastName, second.lastName) > 0) return true;
  return false;
}

bool operator<(const Visit &first, const Visit &second) {
  if (strcmp(first.lastName, second.lastName) < 0) return true;
  return false;
}
bool operator==(const Visit &first, const Visit &second) {
  if (strcmp(first.lastName, second.lastName) == 0) return true;
  return false;
}
bool operator!=(const Visit &first, const Visit &second) {
  if (strcmp(first.lastName, second.lastName) != 0) return true;
  return false;
}

Visit Visit::operator=(const Visit &other) {
  dateCnt = other.dateCnt;
  for (int i = 0; i < dateCnt; i++) {
    strcpy(date[i], other.date[i]);
  }
  strcpy(lastName, other.lastName);
  strcpy(group, other.group);

  return *this;
}

/////////////
Tree::Tree(Visit key) {
  root = new Node(key);
  size = 1;
}

Tree::Tree() {
  root = nullptr;
  size = 0;
}

Tree::~Tree() { deleteTree(root); }

Tree::Tree(const Tree &other) {
  root = copyTree(other.root);
  size = other.size;
}

Node *Tree::copyTree(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }

  Node *newNode = new Node(node->data);
  newNode->left = copyTree(node->left);
  newNode->right = copyTree(node->right);

  return newNode;
}

Tree &Tree::operator=(const Tree &other) {
  if (this != &other) {
    deleteTree(root);
    root = copyTree(other.root);
    size = other.size;
  }
  return *this;
}

void Tree::deleteTree(Node *curr) {
  if (curr) {
    deleteTree(curr->left);
    deleteTree(curr->right);
    delete curr;
  }
}

int Tree ::getSize() { return this->size; }

void Tree::print() {
  printTree(root);
  cout << endl;
}

void Tree::printTree(Node *curr) {
  if (curr) {
    printTree(curr->left);
    cout << curr->data;
    printTree(curr->right);
  }
}

void Tree::findGroup(const char *group) { findGroup(root, group); }
void Tree::findGroup(Node *curr, const char *group) {
  if (curr) {
    findGroup(curr->left, group);
    if (!strcmp(group, curr->data.getGroup())) cout << curr->data;
    findGroup(curr->right, group);
  }
}

void Tree::findDate(const char *date) { findDate(root, date); }
void Tree::findDate(Node *curr, const char *date) {
  if (curr) {
    findDate(curr->left, date);
    char **daate = curr->data.getDate();
    int siize = curr->data.getDateCnt();
    for (int i = 0; i < siize; i++) {
      if (!strcmp(date, daate[i])) {
        cout << curr->data;
        break;
      }
    }

    findDate(curr->right, date);
  }
}

bool Tree::find(Visit key) {
  Node *curr = root;
  while (curr && curr->data != key) {
    if (curr->data > key)
      curr = curr->left;
    else
      curr = curr->right;
  }
  return curr != nullptr;
}

Visit Tree::findName(const char *name) {
  Node *curr = root;
  while (curr && strcmp(name, curr->data.getName())) {
    if (strcmp(name, curr->data.getName()) < 0) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }
  return curr->data;
}

Visit *Tree::findNumber(Node *root, int &count,
                                    int logical_number) {
  if (root == nullptr) {
    return nullptr;
  }

  Visit *found_visit =
      findNumber(root->left, count, logical_number);
  if (found_visit != nullptr) {
    return found_visit;
  }

  if (++count == logical_number) {
    return &(root->data);
  }

  return findNumber(root->right, count, logical_number);
}

Visit *Tree::findNumber(int logical_number) {
  int count = 0;
  return findNumber(root, count, logical_number);
}

void Tree::insert(Visit key) {
  if (root == nullptr) {
    root = new Node(key);
    size = 1;
    return;
  }
  Node *curr = root;
  while (curr && curr->data != key) {
    if (curr->data > key && curr->left == NULL) {
      curr->left = new Node(key);
      ++size;
      return;
    }
    if (curr->data < key && curr->right == NULL) {
      curr->right = new Node(key);
      ++size;
      return;
    }
    if (curr->data > key)
      curr = curr->left;
    else
      curr = curr->right;
  }
}

void Tree::erase(Visit key) {
  Node *curr = root;
  Node *parent = NULL;
  while (curr && curr->data != key) {
    parent = curr;
    if (curr->data > key) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }
  if (!curr) return;
  if (curr->left == NULL) {
    // Вместо curr подвешивается его правое поддерево
    if (parent && parent->left == curr) parent->left = curr->right;
    if (parent && parent->right == curr) parent->right = curr->right;
    --size;
    delete curr;
    return;
  }
  if (curr->right == NULL) {
    // Вместо curr подвешивается его левое поддерево
    if (parent && parent->left == curr) parent->left = curr->left;
    if (parent && parent->right == curr) parent->right = curr->left;
    --size;
    delete curr;
    return;
  }
  // У элемента есть два потомка, тогда на место элемента поставим
  // наименьший элемент из его правого поддерева
  Node *replace = curr->right;
  while (replace->left) replace = replace->left;
  Visit replace_value = replace->data;
  erase(replace_value);
  curr->data = replace_value;
}

void Tree::writeNodeToFile(Node *node, ofstream &outFile) {
  if (node == nullptr) {
    return;
  }

  char *name = node->data.getName();
  char *group = node->data.getGroup();
  int dateCnt = node->data.getDateCnt();
  char **date = node->data.getDate();

  int sizeArr = strlen(name) + 1;
  outFile.write((char *)&(sizeArr), sizeof(sizeArr));
  for (int i = 0; i < sizeArr; i++) {
    outFile.write((char *)&(name[i]), sizeof(name[i]));
  }

  sizeArr = strlen(group) + 1;
  outFile.write((char *)&(sizeArr), sizeof(sizeArr));
  for (int i = 0; i < sizeArr; i++) {
    outFile.write((char *)&(group[i]), sizeof(group[i]));
  }

  outFile.write((char *)&(dateCnt), sizeof(dateCnt));
  for (int i = 0; i < dateCnt; i++) {
    sizeArr = strlen(date[i]) + 1;
    outFile.write((char *)&(sizeArr), sizeof(sizeArr));
    for (int j = 0; j < sizeArr; j++) {
      outFile.write((char *)&(date[i][j]), sizeof(date[i][j]));
    }
  }

  writeNodeToFile(node->left, outFile);
  writeNodeToFile(node->right, outFile);
}

void Tree::writeTreeToFile(const char*filename) {
  std::ofstream outFile(filename, std::ios::binary);
  if (!outFile) {
    std::cerr << "Could not open file for writing: " << filename << std::endl;
    return;
  }

  writeNodeToFile(this->root, outFile);

  outFile.close();
}

void Tree::readTreeFromFile(const char*filename) {
  std::ifstream inFile(filename, std::ios::binary);
  if (!inFile) {
    std::cerr << "Could not open file for reading: " << filename << std::endl;
    return;
  }

  int sizeArr;
  while (inFile.read((char *)&(sizeArr), sizeof(sizeArr))) {
    char name[20];
    char group[20];
    int dateCnt;

    for (int i = 0; i < sizeArr; i++) {
      inFile.read((char *)&(name[i]), sizeof(name[i]));
    }
    name[sizeArr] = '\0';

    inFile.read((char *)&(sizeArr), sizeof(sizeArr));
    for (int i = 0; i < sizeArr; i++) {
      inFile.read((char *)&(group[i]), sizeof(group[i]));
    }
    group[sizeArr] = '\0';

    Visit tmp(name, group);

    inFile.read((char *)&(dateCnt), sizeof(dateCnt));
    for (int i = 0; i < dateCnt; i++) {
      inFile.read((char *)&(sizeArr), sizeof(sizeArr));
      char date[20];
      for (int j = 0; j < sizeArr; j++) {
        inFile.read((char *)&(date[j]), sizeof(date[j]));
      }
      date[sizeArr] = '\0';
    }

    this->insert(tmp);
  }

  inFile.close();
}

void Tree::Iterator::pushLeftmost(Node *node) {
  while (node != nullptr) {
    nodeStack.push(node);
    node = node->left;
  }
}

Tree::Iterator::Iterator(Node *root) { pushLeftmost(root); }

bool Tree::Iterator::hasNext() { return !nodeStack.empty(); }

Visit *Tree::Iterator::next() {
  if (!hasNext()) return nullptr;

  Node *nextNode = nodeStack.top();
  nodeStack.pop();

  if (nextNode->right != nullptr) {
    pushLeftmost(nextNode->right);
  }

  return &(nextNode->data);
}