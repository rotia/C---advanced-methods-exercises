#include <iostream>  // cout, endl
#include <vector>    // vector
#include <algorithm> // transform

using std::cout; using std::endl; using std::begin; using std::end;

auto F11_1     (int i) -> decltype(i) {          return i+1;                  }
auto F11_2     (int i) -> decltype(i) { if (i%2) return i+1; else return i/2; }
auto F14_2     (int i)                { if (i%2) return i+1; else return i/2; }  // C++14

// Lambda expressions: ignore on first reading
auto L11_1 = [](int i)                {          return i+1;                  };
auto L11_2 = [](int i) -> decltype(i) { if (i%2) return i+1; else return i/2; };
auto L14_2 = [](int i)                { if (i%2) return i+1; else return i/2; }; // C++14

// A client for all the above: don't need to understand it
void use(std::function<int(int)> f) {     // std::function is covered later in the course
  std::vector<int> v{1,2,3,4,5};
  std::transform(begin(v), end(v), begin(v), f);
  for (const auto& e: v) cout << e << " ";
  cout << endl;
}

int main() {
  use(F11_1);
  use(F11_2);
  use(F14_2);

  use(L11_1);
  use(L11_2);
  use(L14_2);
}
