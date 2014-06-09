#include <iostream> // cout, endl
#include <memory>   // shared_ptr, make_shared
#include <utility>  // move

using std::cout; using std::endl;
using std::shared_ptr; using std::make_shared;

class Foo {
public:
  Foo(int n)         : n{n}   { cout << "construct " << n << endl; }
  Foo(const Foo&  o) : n{o.n} { cout << "copy      " << n << endl; }
  Foo(      Foo&& o) : n{o.n} { cout << "move      " << n << endl; }
  ~Foo()                      { cout << "destroy   " << n << endl; }
  void id() const { cout << n << endl; }
private:
  int n;
};

std::shared_ptr<Foo> g = nullptr;

void observe_with_overhead  (shared_ptr<Foo>  f) { f->id(); }
void observe_sans_overhead  (const Foo&       f) { f.id();  }

void increment_refcount_slow(shared_ptr<Foo>  f) { g =           f;  };
void increment_refcount_fast(shared_ptr<Foo>  f) { g = std::move(f); };
void increment_refcount_Fast(shared_ptr<Foo>& f) { g =           f;  };

void steal_ownership        (shared_ptr<Foo>& f) { g = std::move(f); };


void report(const shared_ptr<Foo>& f) {
  cout << "*" << f.get() << " = "; cout.flush();
}

int main() {
  {
    auto f1 = make_shared<Foo>(1);
    observe_with_overhead( f1); // Refcount goes up, then down
    observe_sans_overhead(*f1); // Refcount untouched
  }
  {
    auto f2 = make_shared<Foo>(2);
    increment_refcount_slow(f2); // Refcount goes up by 2, then down by 1
  }
  {
    auto f3 = make_shared<Foo>(3);
    increment_refcount_fast(f3); // Refcount goes up by one on function entry
  }
  {
    auto f4 = make_shared<Foo>(4);
    increment_refcount_Fast(f4); // Refcount goes up by one on assignment to g
  }

  auto f5 = make_shared<Foo>(5);
  report(f5); f5->id();
  steal_ownership(f5); // f5's guts ripped out by move inside the function
  report(f5); f5->id(); // Bang !

}