#include <iostream> // cout, endl

using std::cout; using std::endl;

struct B {
  void hmm() { [=] { i++; } (); }
  int i = 1;
};

int main() {

  B b;
  b.hmm();
  cout << b.i << endl; // 2

}