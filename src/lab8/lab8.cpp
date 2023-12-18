#include <chrono>
#include <iostream>
#include <random>
#include <set>
#include <stack>

using namespace std;
using namespace chrono;

#define MAX 10000000

int main() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, 1000);

  stack<int> stack;
  multiset<int> multiset;




  high_resolution_clock::time_point start = high_resolution_clock::now();

  for (int n = 0; n < MAX; ++n) {
    int num = dis(gen);
    stack.push(num);
  }
  high_resolution_clock::time_point end = high_resolution_clock::now();

  duration<double> diff = end - start;
  cout << "\nTime for addition stack: " << diff.count() << " s\n";





  start = high_resolution_clock::now();

  for (int n = 0; n < MAX; ++n) {
    if (!stack.empty()) {
      stack.pop();
    }
  }

  end = high_resolution_clock::now();

  diff = end - start;
  cout << "Time for deletion stack: " << diff.count() << " s\n\n\n";






  start = high_resolution_clock::now();

  for (int n = 0; n < MAX; ++n) {
    int num = dis(gen);
    multiset.insert(num);
  }

  end = high_resolution_clock::now();

  diff = end - start;
  cout << "Time for addition multiset: " << diff.count() << " s\n";






  start = high_resolution_clock::now();

  for (int n = 0; n < MAX; ++n) {
    int num = dis(gen);
    std::multiset<int>::iterator it = multiset.find(num);
    if (it != multiset.end()) {
    }
  }

  end = high_resolution_clock::now();

  diff = end - start;
  cout << "Time for search: " << diff.count() << " s\n";






  start = high_resolution_clock::now();

  for (int n = 0; n < MAX; ++n) {
    if (!multiset.empty()) {
      multiset.erase(multiset.begin());
    }
  }

  end = high_resolution_clock::now();

  diff = end - start;
  cout << "Time for deletion multiset: " << diff.count() << " s\n\n";

  return 0;
}
