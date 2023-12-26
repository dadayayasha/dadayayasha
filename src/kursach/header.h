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
  ~Visit();
  void AddDate(const char *date);

  friend ostream &operator<<(ostream &out, Visit &C);
  friend istream &operator>>(istream &in, Visit &C);
};

class tree_elem {
 public:
  int m_data;
  tree_elem *m_left;
  tree_elem *m_right;
  tree_elem(int val) {
    m_left = nullptr;
    m_right = nullptr;
    m_data = val;
  }
};

class binary_tree {
 private:
  tree_elem *m_root;
  int m_size;
  void print_tree(tree_elem *);
  void delete_tree(tree_elem *);

 public:
  binary_tree(int);
  ~binary_tree();
  void print();
  bool find(int);
  void insert(int);
  void erase(int);
  int size();
};

#endif