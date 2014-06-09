#include "movable.cc"
#include <utility> // move

template<class T>
void oldswap(T& a, T& b) { 
  T tmp = a;
  a = b;
  b = tmp;
}

template<class T>
void newswap(T& a, T& b) { 
  T tmp = std::move(a);
  a = std::move(b);
  b = std::move(tmp);
}

int main() {
  Movable   m1(1);
  Movable   m2(2);
  Immovable i1(1);
  Immovable i2(2);  
  cout << "-------- oldswap immovable --------" << endl;
  oldswap(m1, m2);
  cout << "-------- oldswap movable ----------" << endl;
  oldswap(i1, i2);
  cout << "-------- newswap immovable --------" << endl;
  newswap(i1, i2);
  cout << "-------- newswap movable ----------" << endl;
  newswap(m1, m2);
}
