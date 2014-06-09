
#include <iostream>  // cout, endl
#include <algorithm> // for_each
#include <vector>    // vector, begin, end

int main() {
  std::vector<int> data{1,2,3,4,5};
  for_each(begin(data), end(data), [x : print("%d + 3 = %d" % (x, x+3))]);
}