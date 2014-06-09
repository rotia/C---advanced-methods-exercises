#include <iostream>       // cout, endl
#include <thread>         // thread
#include <vector>         // vector
#include <mutex>          // mutex, lock_guard

using std::cout; using std::endl;

std::mutex source_mutex;
std::mutex target_mutex;

const int N_threads = 8;
const int jobs_per_thread = 1000000;

int source = jobs_per_thread * N_threads;
int target = 0;

void report () { cout << source << " + " << target << " = " << source + target << endl;}

int main() {

  report();

  std::vector<std::thread> threads;
  threads.reserve(N_threads);

  for (int n=0; n<N_threads; n++)
    threads.emplace_back([] {
        for (int x=0; x<jobs_per_thread; x++) {

          // Prevent other threads from interfering for the duration
          // of the transfer.
          std::lock_guard<decltype(source_mutex)> source_guard(source_mutex);
          std::lock_guard<decltype(source_mutex)> target_guard(target_mutex);

          source--;
          target++;

        } // both locks automatically released here by RAII
      });

  for (auto& t: threads)
    t.join();

  report();
}
