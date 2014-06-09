#include <iostream>   // cout, endl
#include <memory>     // unique_ptr

using std::cout; using std::endl;

struct Foo {
  Foo(int n) :n(n) { cout << "Acquiring " << n << endl;}
  int n;
  void id() { cout << n << endl;}
  ~Foo() { cout << "Releasing " << n << endl;}
};

int main() {

  std::shared_ptr<Foo> fp = new Foo{7};
  std::shared_ptr<Foo> b{fp};
  b->id();
  {
    std::make_shared<Foo> c{fp};
    c->id();
  } // Foo released here
  b->id(); // Using a released Foo
}

/* Another possibilities are:
//2
auto fp =make_shared<Foo>(7);
std::shared_ptr<Foo>b(fp);
//3
std::shared_ptr<Foo> b(new Foo{7});
/4
auto b(make_shared<Foo>(7));
{
  std::shared_ptr<Foo> c(b);

}*/