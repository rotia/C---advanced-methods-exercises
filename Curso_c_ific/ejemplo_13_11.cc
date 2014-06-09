#include <iostream> // cout, endl

using std::cout; using std::endl;

int main() {
  int i = 3;

  cout << [ i] ()         { i++; return i;} () << endl; // Error
  cout << [ i] () mutable { i++; return i;} () << endl; // OK
  cout << [&i] ()         { i++; return i;} () << endl; // OK, different behaviour
}