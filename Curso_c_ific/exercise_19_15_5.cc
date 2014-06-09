#include <iostream>  // cout, endl
#include <thread>    // thread
#include <random>    // random_device, uniform_int_distribution
#include <stdexcept> // runtime_error

using std::cout; using std::endl;

class thread_guard {
public:
  thread_guard(std::thread& t) : t(t) {}
  ~thread_guard() {
    if (t.joinable()) // Someone could have already joined or detached by hand
      t.join();
  }

  // Explicitly forbid copying the guard: it must not outlive the
  // scope in which it was created
  thread_guard           (const std::thread&) = delete;
  thread_guard& operator=(const std::thread&) = delete;
private:
  std::thread& t;
};

void do_something_else() {
  std::random_device rd;
  std::uniform_int_distribution<int> true_or_false(0, 1);
  if (true_or_false(rd)) 
    cout << "Nothing to see here, move along now." << endl;
  else {
    cout << "Something exceptional is happening ..." << endl;
    throw(std::runtime_error("Very exceptional indeed"));
  }
}

void intermediate_level() {
  std::thread t([] { cout << "Strut your stuff: "; });
  thread_guard gt(t);
  do_something_else();
}

int main() {
  for (int i=0; i<10; ++i)
    try {
      intermediate_level();
    } catch (...) {
      cout << "                  ... Dealing with it" << endl;
    }
}