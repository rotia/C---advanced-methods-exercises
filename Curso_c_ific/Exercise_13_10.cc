#include <iostream> // cout, endl

using std::cout; using std::endl;

class A {
public:
  A(int m) : member(m) {}
  void doit(int n) { [this, n] { cout << n+member << endl; }(); }
private:
  int member;
};

int main() {
 A(2).doit(3);
}