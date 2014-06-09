#include <iostream> // cout, endl
#include <cassert>  // assert

// A class with a variety of constructors
class Base {
public:
  Base()                    : value(0) {}
  Base(int a)               : value(a+1) {}
  Base(int a, int b)        : value(a+b+2) {}
  Base(int a, int b, int c) : value(a+b+c+3) {}
  int check() { return value; }
private:
  int value;
};

// A subclass which should provide the same variety of constructors as
// the base class
//In the old-fashioned way, we need to define 3 sub-classes in order to obtain the desired result
class Dold : public Base {
public:
  Dold()                    : Base() {}
  Dold(int a)               : Base(a) {}
  Dold(int a, int b)        : Base(a,b) {}
  Dold(int a, int b, int c) : Base(a,b,c) {}
};

// A subclass which should provide the same variety of constructors as
// the base class
class Dmodern : public Base {
  using Base::Base;
public:
  // Overriding inherited constructors is possible (TODO: only seems to work for default constructor!)
  Dmodern() : Base() { std::cout << "overriding" << std::endl; };
};

int main() {

  assert(Base().check()      == 0);
  assert(Base(1).check()     == 2);
  assert(Base(1,1).check()   == 4);
  assert(Base(1,1,1).check() == 6);

  assert(Dold().check()      == 0);
  assert(Dold(1).check()     == 2);
  assert(Dold(1,1).check()   == 4);
  assert(Dold(1,1,1).check() == 6);

  assert(Dmodern().check()      == 0);
  assert(Dmodern(1).check()     == 2);
  assert(Dmodern(1,1).check()   == 4);
  assert(Dmodern(1,1,1).check() == 6);

}
