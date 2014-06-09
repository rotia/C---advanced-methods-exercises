#include <iostream>       // cout, endl
#include <thread>         // thread
#include <vector>         // vector
#include <future>         // async, future
#include <string>         // string, to_string

using std::cout; using std::endl; using std::to_string;

int main() {
  int min = 100;
  int max = min + 20;
  std::vector<std::future<std::string>> results;
  results.reserve(max-min);

  for (int n = min; n<max; ++n)
    results.push_back(std::async(std::launch::async,
                                 [n] { 
                                   return to_string(n) + " x " + to_string(n) + " = " 
                                     + to_string(n*n) + "\n";
                                 }));

  for (auto& r : results)
    cout << r.get();
}