#include <utility> // move
#include "movable.cc"

class Base {
public:
  Base(const Movable& m_) : m(m_) {}
private:
  Movable m1;
  Movable m2;
};


int main() {
  Movable m3(3), m4(4), m5(5), m8(8);
  Base b1(std::move(1), std::move(2)); 	// Should move 1 & 2
  Base b2(std::copy(m3),std::copy(m4));	// Should copy 3 & 4
  Base b3(std::copy(m5), std::move(6)); // Should copy 5, move 6
  Base b4(std::move(7), std::copy(m8));         // Should move 7, copy 8
