#include <cstdlib> // NULL

int main() {

  // nullptr works just like NULL and zero when used as a void* value
  void* vp;
  vp = NULL;
  vp = 0;
  vp = nullptr;

  // nullptr works just like NULL and zero when used as an int* value
  int* ip;
  ip = NULL;
  ip = 0;
  ip = nullptr;

  // nullptr is the only one that spots the error when converted to int
  int i;
  i = NULL;    // Warning if we're lucky
  i = 0;       // Silence
  i = nullptr; // Error - which is what we want

}

