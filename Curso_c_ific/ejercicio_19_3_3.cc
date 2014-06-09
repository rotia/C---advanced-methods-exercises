#include <iostream>   // cout, endl
#include <thread>     // thread

using std::cout; using std::endl;

//void function(int& i) {  ++i; }

int main() {
  int i = 1;
  std::thread(function(int& i) {  ++i; }).join(); 
  // We use lambda
  cout << i << endl;