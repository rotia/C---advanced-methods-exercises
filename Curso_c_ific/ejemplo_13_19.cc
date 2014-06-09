#include <iostream>   // cout, endl
using std::cout; using std::endl;

int main() {

  const auto i = [] {
    // Arbitrarily complex initialization
    auto a = 1;
    auto b = 2;
    auto c = 3;
    return (a+b) *  c;
  }();

  cout << i << endl;
}