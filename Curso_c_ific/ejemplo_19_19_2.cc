#include <iostream>       // cout, endl
#include <thread>         // thread
#include <vector>         // vector
#include <mutex>          // mutex, lock_guard

using std::cout; using std::endl;

std::mutex cout_mutex; // Lock this when you want to write to cout

int main() {
  int min = 100;
  int max = min + 20;
  std::vector<std::thread> threads;
  threads.reserve(max-min);

  for (int n = min; n<max; ++n)
    threads.emplace_back([n] { 
        std::lock_guard<std::mutex> lock_cout(cout_mutex); // cout_mutex locked here
        cout << n << " x " << n << " = " << n*n << endl; 
      });                                                  // cout_mutex automatically released here

  for (auto& t : threads)
    t.join();

}