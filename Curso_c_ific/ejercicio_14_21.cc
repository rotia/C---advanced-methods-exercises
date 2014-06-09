#include <utility> // move
#include "movable.cc"

class Base {
public:
  Base(const Movable& m_) : m(m_) {}
private:
  Movable m;
};


int main() {
  Movable m2(2), m3(3);
  Base b1(std::move(m2));    // Should move 1
  Base b2(m2);            // Should copy 2
  Base b3(std::move(m3)); // Should move 3
}
