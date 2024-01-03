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
  char *GetName();
  char *GetGroup();
  char **GetDate();
  int GetDateCnt();
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

class Node{
 public:
  Visit data;
  Node *left;
  Node *right;
  Node(Visit data) {
    left = nullptr;
    right = nullptr;
    this->data = data;
  }
};

class Tree {
 private:
  Node *root;
  int size;
  void print_tree(Node *);
  void delete_tree(Node *);
  Visit *find_by_logical_number(Node *root, int &count, int logical_number);
  void writeNodeToFile(Node *node, std::ofstream &outFile);
  void findGroup(Node*curr,const char * group);
  void findDate(Node*curr,const char * date);

 public:
  Tree(Visit);
  Tree();
  ~Tree();
  void print();
  bool find(Visit);
  Visit namefind(const char *name);
  void insert(Visit);
  void erase(Visit);
  Visit *find_by_logical_number(int logical_number);
  int GetSize();
  void writeTreeToFile(const std::string &filename);
  void readTreeFromFile(const std::string &filename);
  void findGroup(const char * group);
  void findDate(const char * date);

};

#endif