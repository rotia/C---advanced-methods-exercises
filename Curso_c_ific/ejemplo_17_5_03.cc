#include <iostream> // cout, endl
#include <memory>   // shared_ptr, weak_ptr, make_shared

using std::cout; using std::endl;

class Resource {
public:
  Resource(int i) : id(i) { cout << "---> " << id         << endl; }
  virtual ~Resource()     { cout << "     " << id << " X" << endl; }
  virtual void point_to(std::shared_ptr<Resource>) = 0;
protected:
  int id;
};

template<class SMART_PTR>
class ResourceImp : public Resource {
public:
  using Resource::Resource; // Inherit constructors
  virtual void point_to(std::shared_ptr<Resource> p) { partner = p; };
private:
  SMART_PTR partner;
};

using Weak   = ResourceImp<std::  weak_ptr<Resource>>;
using Shared = ResourceImp<std::shared_ptr<Resource>>;

int main() {
  {
    // A cycle with 2 strong links
    auto r1 = std::make_shared<Shared>(1);
    auto r2 = std::make_shared<Shared>(2);
    r1->point_to(r2);
    r2->point_to(r1);

    // A cycle with 1 strong and 1 weak link
    auto r3 = std::make_shared<Shared>(3);
    auto r4 = std::make_shared<Weak  >(4);
    r3->point_to(r4);
    r4->point_to(r3);

  } // r3 & r4 are     released at this point
  //   r1 & r2 have been leaked by this point
}
