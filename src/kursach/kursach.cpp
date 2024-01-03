#include "header.h"

int main() {
  Visit v1("Johnson", "AVT-209");
  Visit v2("Kennedy", "AVT-209");
  Visit v3("Taft", "AVT-209");
  Visit v4("Biden", "AVT-242");
  Visit v5("Trump", "AVT-209");
  Visit v6("Obama", "AVT-209");
  Visit v7("Bush", "AVT-208");
  Visit v8("Clinton", "AVT-209");
  Visit v9("Reagan", "AVT-209");
  Visit v10("Lincoln", "AVT-242");
  Visit v11("Ford", "AVT-208");
  Visit v12("Nixon", "AVT-242");

  Tree a;
  a.insert(v1);
  a.insert(v2);
  a.insert(v3);
  a.insert(v4);
  a.insert(v5);
  a.insert(v6);
  a.insert(v7);
  a.insert(v8);
  a.insert(v9);
  a.insert(v10);
  a.insert(v11);
  a.insert(v12);
  //a.print();
  cout << endl << endl;

Tree::Iterator it = a.begin();

while(it.hasNext()){
    Visit* tmp = it.next();
    cout<<*tmp;
}


  // a.writeTreeToFile("tree.bin");
  // a.findGroup("AVT-242");

  //   cout << endl << endl;
  //   a.erase(kolya);
  //   a.print();
}