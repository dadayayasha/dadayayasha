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
  group = new char[20];
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
  delete[] lastName;
  delete[] group;
  for (int i = 0; i < 18; i++) {
    delete[] date[i];
  }
  delete[] date;
}

void Visit::AddDate(const char *date) {
  strcpy(this->date[dateCnt], date);
  dateCnt++;
}

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
}

/////////////
binary_tree::binary_tree(Visit key) {
  m_root = new tree_elem(key);
  m_size = 1;
}

binary_tree::~binary_tree() { delete_tree(m_root); }

void binary_tree::delete_tree(tree_elem *curr) {
  if (curr) {
    delete_tree(curr->m_left);
    delete_tree(curr->m_right);
    delete curr;
  }
}

void binary_tree::print() {
  print_tree(m_root);
  cout << endl;
}

void binary_tree::print_tree(tree_elem *curr) {
  if (curr)  // Проверка на ненулевой указатель
  {
    print_tree(curr->m_left);
    cout << curr->m_data << " ";
    print_tree(curr->m_right);
  }
}

bool binary_tree::find(Visit key) {
  tree_elem *curr = m_root;
  while (curr && curr->m_data != key) {
    if (curr->m_data > key)
      curr = curr->m_left;
    else
      curr = curr->m_right;
  }
  return curr != NULL;
}

void binary_tree::insert(Visit key) {
  tree_elem *curr = m_root;
  while (curr && curr->m_data != key) {
    if (curr->m_data > key && curr->m_left == NULL) {
      curr->m_left = new tree_elem(key);
      ++m_size;
      return;
    }
    if (curr->m_data < key && curr->m_right == NULL) {
      curr->m_right = new tree_elem(key);
      ++m_size;
      return;
    }
    if (curr->m_data > key)
      curr = curr->m_left;
    else
      curr = curr->m_right;
  }
}

void binary_tree::erase(Visit key) {
  tree_elem *curr = m_root;
  tree_elem *parent = NULL;
  while (curr && curr->m_data != key) {
    parent = curr;
    if (curr->m_data > key) {
      curr = curr->m_left;
    } else {
      curr = curr->m_right;
    }
  }
  if (!curr) return;
  if (curr->m_left == NULL) {
    // Вместо curr подвешивается его правое поддерево
    if (parent && parent->m_left == curr) parent->m_left = curr->m_right;
    if (parent && parent->m_right == curr) parent->m_right = curr->m_right;
    --m_size;
    delete curr;
    return;
  }
  if (curr->m_right == NULL) {
    // Вместо curr подвешивается его левое поддерево
    if (parent && parent->m_left == curr) parent->m_left = curr->m_left;
    if (parent && parent->m_right == curr) parent->m_right = curr->m_left;
    --m_size;
    delete curr;
    return;
  }
  // У элемента есть два потомка, тогда на место элемента поставим
  // наименьший элемент из его правого поддерева
  tree_elem *replace = curr->m_right;
  while (replace->m_left) replace = replace->m_left;
  Visit replace_value = replace->m_data;
  erase(replace_value);
  curr->m_data = replace_value;
}