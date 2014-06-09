#include <iostream> // cout, endl
#include <memory>   // shared_ptr, weak_ptr

using std::cout; using std::endl;

class Resource {
public:
  Resource(int i) : id(i) { cout << "Acquiring " << id << endl; }
  ~Resource()             { cout << "Releasing " << id << endl; id = 666; }
  void use() const        { cout << "Using "     << id << endl; }
private:
  int id;
};

void use(const std::weak_ptr<Resource>& weak) { 
  cout << "use(weak): "; cout.flush();
  if (auto shared = weak.lock()) // Must copy into shared_ptr to use.
    shared->use();
  // RAII releases the lock acquired two lines above.
  else 
    cout << "Not using: resource expired." << endl;
}

void use(const Resource* const bare) {
  cout << "use(bare): "; cout.flush();
  if (bare)
    bare->use();
  else
    cout << "Not using: resource expired." << endl;
}

int main() {
  Resource*               observe_dangerously;
  std::weak_ptr<Resource> observe_safely;
  {
    auto resource = std::make_shared<Resource>(1);
    observe_dangerously = resource.get();
    observe_safely      = resource;
    use(observe_safely);
    use(observe_dangerously);
  } // Resource released at this point
  use(observe_safely);
  use(observe_dangerously);
}