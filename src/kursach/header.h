#ifndef HEADER
#define HEADER

#include <fstream>
#include <iostream>

using namespace std;

class Visit {
  char *lastName;
  char *group;
  char **date;
  int dateCnt;

 public:
  Visit();
  Visit(const char *name, const char *group);
  Visit(const Visit &other);
  ~Visit();
  void AddDate(const char *date);

  Visit operator=(const Visit &other);

  friend ostream &operator<<(ostream &out, Visit &C);
  friend istream &operator>>(istream &in, Visit &C);

  friend bool operator>(const Visit &first, const Visit &second);
  friend bool operator<(const Visit &first, const Visit &second);
  friend bool operator==(const Visit &first, const Visit &second);
  friend bool operator!=(const Visit &first, const Visit &second);
};

class tree_elem {
 public:
  Visit m_data;
  tree_elem *m_left;
  tree_elem *m_right;
  tree_elem(Visit data) {
    m_left = nullptr;
    m_right = nullptr;
    m_data = data;
  }
};

class binary_tree {
 private:
  tree_elem *m_root;
  int m_size;
  void print_tree(tree_elem *);
  void delete_tree(tree_elem *);

 public:
  binary_tree(Visit);
  ~binary_tree();
  void print();
  bool find(Visit);
  void insert(Visit);
  void erase(Visit);
};

#endif