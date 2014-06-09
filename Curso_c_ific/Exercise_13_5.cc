#include <iostream>   // cout, endl
#include <vector>     // vector, begin, end
#include <algorithm>  // for_each, transform

// A guinea pig class that we will use in the exercises below.
struct Powers {
  Powers(int n_) : n(n_) {}
  int get_square() const { return n*n; }
  int get_cube()   const { return n*n*n; }
  int multiply_by(int m) const { return m*n; }
private:
  int n;
};

// Rewrite the following code without the use of lambdas.
int main() {
  std::vector<int> source{1,2,3,4,5};
  std::vector<Powers*> input(source.size(), nullptr);

  transform(begin(source), end(source), begin(input),
            [](int n){ return new Powers(n);});
  // Hint: write a functor

  for_each(begin(input), end(input), 
           [](Powers* p){ std::cout << p->get_square() << " ";});
  std::cout << std::endl;
  // Hint: use mem_fun, copy and ostream_iterator (or write a functor)
  
  for_each(begin(input), end(input), 
           [](Powers* p){ std::cout << p->multiply_by(10) << " ";});
  std::cout << std::endl;
  // Hint: use bind, mem_fun, copy and ostream_iterator (or write a functor)

  for_each(begin(input), end(input), 
           [](Powers* p){ std::cout << p->get_square() + p->get_cube() << " ";});
  std::cout << std::endl;
  // Hint: Finding an inline expression to replace the lambda looks
  // very painful. A functor is your only realistic option.

  // BTW, did you spot our use of Koenig (argument dependent) lookup?
}