

#include <iostream>   // cout, endl
#include <thread>     // thread

using std::cout; using std::endl;

void overload()      { cout << "void"        << endl; }
void overload(int i) { cout << "int = " << i << endl; }

int main() {
  std::thread(static_cast<void (*)(   )>(overload)   ).join();
  std::thread(static_cast<void (*)(int)>(overload), 2).join();

  std::thread([] { overload( ); }).join();
  std::thread([] { overload(2); }).join();
}

