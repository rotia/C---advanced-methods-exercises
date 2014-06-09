#include <iostream>   // cout, endl
#include <thread>     // thread
#include <functional> // ref

using std::cout; using std::endl;

void function(int& i) {  ++i; }

int main() {
  int i = 1;
  std::thread(function, std::ref(i)).join();  // Solution 1
  std::thread([&i] { function(i); }).join();  // Solution 2
  cout << i << endl;
}
