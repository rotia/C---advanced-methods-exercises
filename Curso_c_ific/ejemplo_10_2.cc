

#include <iostream> // cout, endl

using std::cout; using std::endl;

struct Delegate {
  Delegate()  { cout << "Default constructing" << endl;}
  ~Delegate() { cout << "Destructing"          << endl;}
  Delegate(int) 
    : Delegate() // Delegation may occur in constructor initializer list
  { 
    cout << "Int constructing" << endl;
    Delegate();  // This isn't delegation: creating a temporary
    cout << "Finished int constructing" << endl;
  }
};

int main() {
  Delegate d(1);
  cout << "---------- Leaving main ----------" << endl;
}
