#include <iostream> // cout, endl
#include <thread>   // this_thread
#include <future>   // packaged_task
#include <chrono>   // chrono
#include <vector>   // vector

using std::cout; using std::endl; using std::string;

void connect() {
  // Get permission from the EU
  // Hire a translator
  // Establish the communications channel
  // This takes lots of time ...
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

string ask_the_brits()     { connect(); return "OK"        ; }
string ask_the_french()    { connect(); return "D'accord"  ; }
string ask_the_germans()   { connect(); return "In Ordnung"; }
string ask_the_italians()  { connect(); return "Va bene"   ; }
string ask_the_spaniards() { connect(); return "Vale"      ; }

int main() {

  // Store the packaged tasks in a container
  // Your code goes here ...
  std::vector<std::packaged_task<string()>> tasks;
  tasks.reserve(5);
  for(const auto& fn : {ask_the_brits, 
                        ask_the_french, 
                        ask_the_germans,
                        ask_the_italians,
                        ask_the_spaniards})
    tasks.emplace_back(fn);

  // A container of the futures attached to the packaged tasks
  // Your code goes here ...
  std::vector<std::future<string>> futures;
  futures.reserve(5);
  for(auto& task : tasks)
    futures.push_back(task.get_future());

  // A container of threads on which the tasks will be executed
  // Your code goes here ...
  std::vector<std::thread> threads;
  threads.reserve(5);
  for(auto& task : tasks)
    threads.emplace_back(std::move(task));

  // Wait for all threads to complete
  // Your code goes here ...
  for(auto& thread : threads)
    thread.join();

  // Display all the results
  // Your code goes here ...
  for(auto& future : futures)
    cout << future.get() << endl;

}
