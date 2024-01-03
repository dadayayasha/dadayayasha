#ifndef HEADER
#define HEADER

#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

class Visit {
  char *lastName;
  char *group;
  char **date;
  int dateCnt;

 public:
  char *getName();
  char *getGroup();
  char **getDate();
  int getDateCnt();
  Visit();
  Visit(const char *name, const char *group);
  Visit(const Visit &other);
  ~Visit();
  void addDate(const char *date);

  Visit operator=(const Visit &other);

  friend ostream &operator<<(ostream &out, Visit &C);
  friend istream &operator>>(istream &in, Visit &C);

  friend bool operator>(const Visit &first, const Visit &second);
  friend bool operator<(const Visit &first, const Visit &second);
  friend bool operator==(const Visit &first, const Visit &second);
  friend bool operator!=(const Visit &first, const Visit &second);
};

class Node {
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
  void printTree(Node *);
  void deleteTree(Node *);
  Node *copyTree(Node *node);
  Visit *findNumber(Node *root, int &count, int logical_number);
  void writeNodeToFile(Node *node, ofstream &outFile);
  void findGroup(Node *curr, const char *group);
  void findDate(Node *curr, const char *date);

 public:
  class Iterator {
   private:
    stack<Node *> nodeStack;

    void pushLeftmost(Node *node);

   public:
    Iterator(Node *root);

    bool hasNext();

    Visit *next();
  };
  Iterator begin() { return Iterator(root); }
  Iterator end() { return Iterator(nullptr); }
  Tree(Visit);
  Tree();
  Tree(const Tree &other);
  ~Tree();
  Tree &operator=(const Tree &other);
  void print();
  bool find(Visit);
  Visit findName(const char *name);
  void insert(Visit);
  void erase(Visit);
  Visit *findNumber(int logical_number);
  int getSize();
  void writeTreeToFile(const char*filename);
  void readTreeFromFile(const char*filename);
  void findGroup(const char *group);
  void findDate(const char *date);
};



#endif