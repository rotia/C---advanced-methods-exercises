#include <iostream> // cout, endl
#include <utility>  // move

using std::cout; using std::endl;

auto nl = [] { cout << endl;};

int main() {

  int a = 1;
  auto fn1 = [=] () mutable { cout << a++;};  
  fn1(); fn1(); fn1(); /* 123 */ nl();

  auto fn2 = fn1;
  fn2(); fn2(); fn2(); /* 456 */ nl();
  fn1();               /* 4   */ nl();

  auto fn3 = std::move(fn1);
  fn3(); fn3(); fn3(); /* 567 */ nl();
  fn1(); fn1(); fn1(); /* ??? */ nl();

}