#include <iostream>   // cout, endl
#include <chrono>     // steady_clock::now
#include <functional> // function
#include <cstdint>        // intmax_t

using INT = std::intmax_t;
using std::cout; using std::endl;

auto now = std::chrono::steady_clock::now;

auto timethis(std::function<void()> thunk) -> decltype((now()-now()).count()) {
  auto start = now();
  thunk();
  auto stop  = now();
  return (stop - start).count();
}

// Something deliberately slow
INT fib(INT n) { return n<2 ? 1 : fib(n-1) + fib(n-2); }

int main() {

  // How long does it take to calculate fib(42) ?
  auto fibtime = timethis([] {fib(42);});
  cout << fibtime << endl;

  // How long does it take to execute an arbitrary chunk of code ?
  auto footime = timethis([] {
      // An arbitrarily complex chunk of code   ////////////////////// |
      int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;   // |
      auto overflow = [](int& ones, int& tens) {                    // |
        if (10 == ones) {                                           // |
          ones = 0;                                                 // |
          ++tens;                                                   // |
        }                                                           // |
      };                                                            // |
      while (a<10) {                                                // |
        ++h;                                                        // |
        overflow(h,g); overflow(g,f); overflow(f,e); overflow(e,d); // |
        overflow(d,c); overflow(c,b); overflow(b,a);                // |
      }                                                             // |
    }); ////////////////////////////////////////////////////////////// |

  cout << footime << endl;
}