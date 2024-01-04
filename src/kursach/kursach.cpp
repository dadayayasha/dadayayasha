#include <string>

#include "header.h"

int main() {
  Visit v1("Johnson", "AVT-209");
  v1.addDate("01.01.2023");
  v1.addDate("07.01.2023");
  v1.addDate("01.02.2023");
  Visit v2("Kennedy", "AVT-209");
  Visit v3("Taft", "AVT-209");
  Visit v4("Biden", "AVT-242");
  v4.addDate("01.01.2023");
  v4.addDate("06.01.2023");
  v4.addDate("21.01.2023");
  Visit v5("Trump", "AVT-209");
  Visit v6("Obama", "AVT-209");
  v6.addDate("01.01.2023");
  v6.addDate("03.02.2023");
  v6.addDate("07.01.2023");
  v6.addDate("05.02.2023");
  v6.addDate("08.05.2023");
  v6.addDate("09.04.2023");
  Visit v7("Bush", "AVT-208");
  Visit v8("Clinton", "AVT-209");
  Visit v9("Reagan", "AVT-209");
  v9.addDate("01.01.2023");
  v9.addDate("07.01.2023");
  v9.addDate("14.01.2023");
  Visit v10("Lincoln", "AVT-242");
  Visit v11("Ford", "AVT-208");
  v11.addDate("01.01.2023");
  v11.addDate("07.01.2023");
  v11.addDate("01.02.2023");
  v11.addDate("07.02.2023");
  v11.addDate("14.02.2023");
  v11.addDate("21.02.2023");
  Visit v12("Nixon", "AVT-242");

  Visit v13("Charlie", "AVT-219");

  Tree tree;
  tree.insert(v1);
  tree.insert(v2);
  tree.insert(v3);
  tree.insert(v4);
  tree.insert(v5);
  tree.insert(v6);
  tree.insert(v7);
  tree.insert(v8);
  tree.insert(v9);
  tree.insert(v10);
  tree.insert(v11);
  tree.insert(v12);

  while (true) {
    cout << "\n1. Print tree\n"
         << "2. Find Visit\n"
         << "3. Insert Visit\n"
         << "4. Erase Visit\n"
         << "5. Find by name\n"
         << "6. Find by number\n"
         << "7. Write to file\n"
         << "8. Read from file\n"
         << "9. Find by group\n"
         << "10. Find by date\n"
         << "11. Test Iterator\n"
         << "12. Exit\n"
         << "Enter your choice: ";
    int choice;
    cin >> choice;
    cout << endl << endl;
    switch (choice) {
      case 1:
        cout<<tree.getSize()<<endl;
        tree.print();
        break;
      case 2: {
        cout << (tree.find(v2) ? "Found" : "Not found") << endl;
        break;
      }
      case 3:
        tree.insert(v13);
        cout << "Element \"Charlie AVT-219\" has been added" << endl;
        break;
      case 4: {
        tree.erase(v4);
        cout << "Element \"Biden AVT-242\" has been deleted" << endl;
        break;
      }
      case 5: {
        cout << "Find Obama" << endl;
        Visit visit = tree.findName("Obama");
        cout << visit << endl;
        break;
      }
      case 6: {
        cout << "Find node with number 2" << endl;
        Visit* visit = tree.findNumber(2);
        cout << *visit << endl;
        break;
      }
      case 7:
        cout << "Write tree in binary file..." << endl;
        tree.writeTreeToFile("tree.bin");
        break;
      case 8:
        cout << "Read tree from binary file..." << endl;
        tree.readTreeFromFile("tree.bin");
        tree.print();
        break;
      case 9:
        cout << "Find group AVT-209" << endl;
        tree.findGroup("AVT-209");
        break;
      case 10:
        cout << "Find date 7.01.2023" << endl;
        tree.findDate("07.01.2023");
        break;
      case 11: {
        cout << "Print tree using an iterator..." << endl;
        ;
        for (Tree::Iterator it = tree.begin(); it.hasNext();) {
          Visit* visit = it.next();
          cout << *visit;
        }
        break;
      }
      case 12:
        return 0;
      default:
        cout << "Invalid choice" << endl;
        break;
    }
  }

  return 0;
}
