#include <utility> // move, forward
#include "movable.cc"

class Base {
public:
  template<class T1, class T2>
  Base(T1&&  m1_, T2&&  m2_) : m1(std::forward<T1>(m1_)), m2(std::forward<T2>(m2_)) {}
private:
  Movable m1;
  Movable m2;
};

int main() {
  Movable m3(3), m4(4), m5(5), m8(8);
  Base b1(Movable(1), Movable(2)); // Should move 1 & 2
  Base b2(m3, m4);                 // Should copy 3 & 4
  Base b3(m5, Movable(6));         // Should copy 5, move 6
  Base b4(Movable(7), m8);         // Should move 7, copy 8
}
