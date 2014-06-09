#include <iostream>      // cout, endl
#include <unordered_map> // unordered_map
#include <vector>        // vector
#include <string>        // string
#include <algorithm>     // count_if
#include <utility>       // pair

using std::cout; using std::endl;

int main() {

  // Just some data to play with below
  std::unordered_map<std::string, std::vector<std::string>> aliases {
    {"Robert", {"Bob", "Rob", "Bobby"}},
    {"John",   {"Johnny"}},
    {"Alex",   {"Alexander", "Sasha", "Lex"}}};

  // This will work in C++14 but not in C++11
  cout << std::count_if(begin(aliases), end(aliases),
                        [](const auto& pair) { // auto used as function parameter type
                          return pair.second.size() > 2;}) << endl;

  // In C++11 it's not quite as bad as
  cout << std::count_if(begin(aliases), end(aliases),
                        [](const std::pair<std::string, std::vector<std::string>>& pair) { // Very noisy parameter type declaration
                          return pair.second.size() > 2;}) << endl;

  // because decltype can help you out
  cout <<  std::count_if(begin(aliases), end(aliases),
                         [](const decltype(*begin(aliases))& pair) { // Less noisy parameter type declaration
                           return pair.second.size() > 2;}) << endl;
}