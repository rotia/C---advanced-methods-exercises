#include <iostream> // cout, endl

using std::cout; using std::endl;

int main() {

  int a = 1;
  [] { int b = 2;
    [a&,b] { cout << a+b << endl; } ();
  } ();

}