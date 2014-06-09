#include <iostream> // cout, endl
#include <vector>   // vector

int main() {
  std::vector<int> v{1,2,3,4,5,6};  // C++11 initializer list: see later in course.
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << "^2 = " << *it**it << std::endl;
  }
  for (int i : v){
	std::cout<<i<<"^2: "<< i*i << std::endl; 
  }
}
