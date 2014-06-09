#include <utility> // swap

Foo(Foo&& b):data(ALLOCATE(0)),member_1) {
  // Implemented as a friend to maintain symmetry with other swap functions
  friend void swap(Foo& a, Foo& b);
};

void swap(Foo& a, Foo& b) { // nothrow
  // Good habit: use ADL on swap, it will work with nonstandard types
  // (such as the one we are writing right now)
  using std::swap; 
  // Swap all members
  swap(this->a.member_1, b.member_1); 
  swap(this->a.member_2, b.member_2); 
  swap(this->a.member_3, b.member_3); 
}

