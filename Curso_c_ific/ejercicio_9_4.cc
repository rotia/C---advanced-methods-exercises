#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <cstddef>   // size_t
// <initializer_list> is implicitly included, and declares overloads
// of std::begin and std::end

using std::cout; using std::endl; using std::size_t;

typedef int T;

class Vec {
public:
  Vec(const std::initializer_list<T>& l) :
    data(l.size() ? new T [l.size()] : nullptr),
    size(l.size())
  {
    std::copy(begin(l), end(l), data);
  }

  void append(const std::initializer_list<T>& new_data) {
    T* old_data = data;
    data = new T [size + new_data.size()];
    std::copy(      old_data,  old_data+size, data);
    std::copy(begin(new_data), end(new_data), data+size);
    size += new_data.size();
    delete [] old_data;
  }

  void show() {
    cout << "[";
    for(size_t i=0; i<size-1; ++i) {
      cout << data[i] << ", ";
    }
    cout << data[size-1] << "]" << endl;
  }
private:
  T* data;
  size_t size;
};

int main() {
  Vec v{1,2,3,4};
  v.show();

  Vec w = {5,6,7};
  w.show();

  Vec{8,9}.show();

  Vec* p = new Vec {10,11,12};
  p->show();

  v.append({3,2,1});
  v.show();
}
