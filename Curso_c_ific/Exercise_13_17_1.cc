#include <iostream>   // cout, endl
#include <functional> // function
using std::cout; using std::endl;

enum class Fuzzy { Yes, Maybe, No };

Fuzzy is_big(int n) {
  if (n<10)  return Fuzzy::No;
  if (n>100) return Fuzzy::Yes;
  return Fuzzy::Maybe;
}

template<class Y, class M, class N>
void fuzzy_if(Fuzzy condition, Y yes, N no, M maybe) {
  switch (condition) {
  case Fuzzy::Yes  : yes();   break;
  case Fuzzy::Maybe: maybe(); break;
  case Fuzzy::No   : no();
  }
}

int main() {
  for (auto n: {2,7, 30, 50, 200, 1000}) {
     fuzzy_if( is_big(n),                                               // Condition
       [&] { cout << n << " is big" << endl; },                         // YES
       [&] { cout << n << " is definitely not big" << endl; },          // NO
       [&] { cout << "not sure whether " << n << " is big" << endl; }); // MAYBE
  }
}