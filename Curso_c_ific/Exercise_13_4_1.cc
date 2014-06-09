#include <iostream>
#include <vector>
#include <algorithm>

struct fulanito{
	fulanito(int i):i(i){}
	int i;
	void operator()(int j){
		cout << i << " + " << j << " = " << i+j <<endl;
	}
};

int main() {
  /*std::vector<int> data{1,2,3,4,5};*/
  for_each(begin(data), end(data),fulanito(3));
} 