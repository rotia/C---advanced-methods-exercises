#include <iostream>  // cout, endl
#include <algorithm> // for_each
#include <vector>    // vector, begin, end

int main() {
  std::vector<int> data{1,2,3,4,5};
  for_each(begin(data), end(data), [](int square){return i*istd::cout << "The square of " << i << " is " << i*i << std::endl]);
}