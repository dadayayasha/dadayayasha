#include "header.h"

int main() {
  Visit y1asha("6", "AVT-209");
  Visit y2asha("8", "AVT-209");
  Visit y3asha("9", "AVT-209");
  Visit y4asha("3", "AVT-209");
  Visit yasha("5", "AVT-209");
  Visit easha("4", "AVT-209");
  Visit tolya("2", "AVT-209");
  Visit kolya("1", "AVT-209");
  Visit igor("7", "AVT-209");

  Tree a(yasha);
  a.insert(tolya);
  a.insert(kolya);
  a.insert(y3asha);
  a.insert(y1asha);
  a.insert(easha);
  a.insert(y2asha);
  a.insert(y4asha);
  a.insert(igor);
  // a.print();
  cout << endl << endl;

    //a.writeTreeToFile("tree.bin");
    a.findGroup("AVT-209");

  
  //   cout << endl << endl;
  //   a.erase(kolya);
  //   a.print();
}