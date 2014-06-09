#include <iostream> // cout, endl
#include <vector>   // vector

using std::cout; using std::endl;

class Foo {
public:
  Foo(int n)         : n{n}   { cout << "construct " << n << endl; }
  Foo(const Foo&  o) : n{o.n} { cout << "copy      " << n << endl; }
  Foo(      Foo&& o) : n{o.n} { cout << "move      " << n << endl; }
private:
  int n;
};

int main() {
  std::vector<Foo> v;
  v.reserve(100);
  Foo f{1};                  // construct       1
  v.push_back(f);            //            copy 1
  v.push_back(std::move(f)); //            move 1
  v.push_back(Foo(2));       // construct, move 2
  v.push_back({3});          // construct, move 3
  v.emplace_back(4);         // construct       4
}
