#include <iostream>   // cout, endl
#include <thread>     // thread

using std::cout; using std::endl;

void function(int& i) {  ++i; }

int main() {
  int i = 1;
  std::thread(function, std::ref(i)).join(); // Error fixed by adding std::ref(i)
  cout << i << endl;
}

//std::cref() is used when 'i' is defined as const