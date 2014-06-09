

#include <iostream> // cout, endl
#include <thread>   // thread, this_thread

using std::cout; using std::endl;

struct Functor {
  Functor(int i): i(i) {}
  void operator() (int j)  { cout << "Functor gets " << i+j << endl; }
  int i;
};

void function(int i) {
  int j = 2;
  cout << "Function gets " << i+j << endl;
}

int main() {
  int i = 3;
  std::thread t1(function, i);
  std::thread t2(Functor(2), i);
  std::thread t3([](int i) { cout << "LambdaA gets" << i+2 << endl;}, i);
  std::thread t4([i]       { cout << "LambdaB gets" << i+2 << endl;});
  t1.join(); t2.join(); t3.join(); t4.join(); 
}

