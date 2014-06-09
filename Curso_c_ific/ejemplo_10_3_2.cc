#include <iostream> // cout, endl

#define DIRECT // Comment out to switch style below
struct A {
#ifdef DIRECT // Direct initialization
  int a{1};
  int b{a+1};
  int c{calculate(a,b)};
  int d{e - 1}; // legal, but e is not initialized yet!
  int e{2*c-1};
#else         // Copy initialization
  int a = 1;
  int b = a+1;
  int c = calculate(a,b);
  int d = e - 1; // legal, but e is not initialized yet!
  int e = 2*c-1;
#endif // DIRECT

  int calculate(int x, int y) { return x+y; }
};

int main() {
  A a;
  std::cout << a.a << " " // 1
            << a.b << " " // 2
            << a.c << " " // 3
            << a.d << " " // NOT 4 !
            << a.e <<     // 5
    std::endl;
}
