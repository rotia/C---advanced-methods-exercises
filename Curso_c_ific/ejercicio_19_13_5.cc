#include <iostream>   // cout, endl
#include <thread>     // thread

using std::cout; using std::endl;

struct Foo {
  int n;
  Foo(int n) : n(n) {}
  void one()       { cout << n   << endl; }
  void two(int m)  { cout << n+m << endl; }
  void ovd()       { cout << n*n << endl; }
  void ovd(int m)  { cout << n*m << endl; }
};

int main() {
  Foo f1{1};
  Foo f2{2};

  //with lambda expression
  std::thread([&f1] {f1.one( );}).join();
  std::thread([&f2] {f2.two(3);}).join();
  std::thread([&f2] {f2.ovd( );}).join();
  std::thread([&f2] {f2.ovd(3);}).join();
  //with constructor
  std::thread(                                &Foo::one,  &f1   ).join();
  std::thread(                                &Foo::two,  &f2, 3).join();
  std::thread(static_cast<void (Foo::*)(   )>(&Foo::ovd), &f2   ).join();
  std::thread(static_cast<void (Foo::*)(int)>(&Foo::ovd), &f2, 3).join();

}