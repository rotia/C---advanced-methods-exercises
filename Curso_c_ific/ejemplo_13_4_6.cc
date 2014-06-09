#include <iostream>   // cout, endl

// Helper function: prints out anything
template <class T>
void show(const T& it) { std::cout << it << std::endl; }

int main() {
  // Pay attention here: make_adder MAKES closures
  auto make_adder = [](int outer) { //      outer lambda
    return [=](int inner) { // returning an inner lambda
      return outer+inner;
    };
  };

  // add_1 and add_2 ARE closures
  auto add_1 = make_adder(1);
  auto add_2 = make_adder(2);

  show(add_1(10));
  show(add_2(10));
}