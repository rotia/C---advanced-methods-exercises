#include <iostream>       // cout, endl
#include <thread>         // thread
#include <vector>         // vector
#include <unordered_map>  // unordered_map
#include <cstdint>        // intmax_t

using std::cout; using std::endl;

using INT = std::intmax_t;

INT fib(INT n) { return n<2 ? 1 : fib(n-1) + fib(n-2); }

std::unordered_map<INT, INT> fibs;

int main() {
  INT min = 32;
  INT max = min + 10;
  std::vector<std::thread> threads;
  threads.reserve(max-min);

  for (INT n = min; n<max; ++n)
    threads.emplace_back([n] { fibs[n] = fib(n);} );

  for (auto& t : threads)
    t.join();

  for (auto& pair : fibs)
    cout << pair.first << " " << pair.second << endl;
}