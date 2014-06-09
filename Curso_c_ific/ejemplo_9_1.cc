#include <iostream> // cout, endl
#include <vector>   // vector

using std::cout; using std::endl;

struct A {
  A()         { cout << "A::A()"         << endl; }
  A(int)      { cout << "A::A(int)"      << endl; }
  A(int, int) { cout << "A::A(int, int)" << endl; }
};

struct C {
  int a;
  float b;
};

int main() {
              A(1,2);     // A::A(int, int)
           A a2(1,2);     // A::A(int, int)
  A* p2 = new A(1,2);     // A::A(int, int)

              A(1);       // A::A(int)
           A a1(1);       // A::A(int)
  A* p1 = new A(1);       // A::A(int)
          A a1x = 1;      // A::A(int) - identical meaning to a1

              A();        // A::A()
           A a0();        // declaration of a function called a0
  A* p0 = new A;          // A::A()
          A a0x;          // A::A()

  struct B {
    B() :
      a2(1,2),            // A::A(int, int)
      a1(1),              // A::A(int)
      a0()                // A::A()  - contrast with a0 above and a0x
    {}
    A a2, a1, a0;
  };

  int ia1[  ] = {1,2,3};  // array containing the three integers 1,2,3
  int ia2[ 3] = {1,2,3};  // array containing the three integers 1,2,3
  int ia3[10] = {1,2,3};  // array containing the three integers 1,2,3 and 7 garbage integers
  //int* ip2 = new int[3] = {1,2,3}; // Can't do this at all in C++98

  C c = {1, 2.3};         // POD-initialization of C's members
  //A a = {1,2};          // Can't do this in C++98: A is not POD

  C ca[3] = {{1, 1.0}, {2, 2.0}, {3, 3.0}};
  //C* cp = new C[3] = {{1, 1.0}, {2, 2.0}, {3, 3.0}}; // Cannot be done in C++98
  //A* ap = new A[3] = {{}, {1}, {1,2}}; // Cannot be done in C++98

  std::vector<int> v;     // Veeeeery tedious
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

}
