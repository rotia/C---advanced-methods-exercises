#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; using std::endl;

int main() {
  int i;
      
  auto data{1,2,3,4,5};
  std::for_each(begin(data), end(data),[data](int j=1){
  	 cout << data << " + " << j << " = " << data+j <<endl;
  });
} 