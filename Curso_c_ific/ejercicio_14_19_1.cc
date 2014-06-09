

#include <iostream> // cout, endl
#include <cstddef>  // size_t
#include <utility>  // move

using std::cout; using std::endl; using std::size_t;

typedef int T;

class Vectorish {
public:
  // Plain constructor remains unchanged
  Vectorish(size_t N, int start=0) : data(nullptr), size(N) {
    if (N>0) {
      data = ALLOCATE(N);
      for (size_t i=0; i<N; ++i)
        data[i] = start+i;
    }
  }

  // Copy constructor remains unchanged (COPY has been inlined, as
  // it's the only place it is used in this idiom).
  Vectorish(const Vectorish& other) : data(ALLOCATE(other.size)), size(other.size) {
    cout << "Copying      " << size << " elements" << endl;
    for (size_t i=0; i<size; ++i) {
      data[i] = other.data[i];
    }
  }

  // Move constructor delegates to default constructor, to highlight
  // common practice in the idiom.
  Vectorish(Vectorish&& other) : Vectorish() { swap(*this, other); }

  // Both the move assignment and copy assignment operators are
  // replaced by this single version which TAKES THE SOURCE OBJECT BY
  // VALUE.
  Vectorish& operator=(Vectorish other) {
    swap(*this, other);
    return *this;
  }

  T& operator[](size_t n) { return data[n]; }

  // Destructor is unchanged (RELEASE has been inlined, as it's the
  // only place it is used in this idiom).
  ~Vectorish() { 
    cout << "Deallocating " << size << " elements" << endl;
    delete [] data;
  }

  // Making swap a friend (with the help of ADL) overloads the generic
  // swap and enables clients to use it in a generic way.
  friend void swap(Vectorish& lhs, Vectorish& rhs);

private:
  T* data;
  std::size_t size;

  // Only used by the move constructor.
  Vectorish() : data(nullptr), size(0) {}

  // ALLOCATE is was used explicitly in the copy assignment operator,
  // the plain constructor and the copy constructor. Now it is used
  // explicitly only in the plain constructor and the copy
  // constructor.
  T* ALLOCATE(size_t N) {
    cout << "Allocating   " << N << " elements" << endl;
    return new T[N];
  }

  // RELEASE was used explicilty in both the destructor and the copy
  // assignment operator. Now used explicitly only in the destructor,
  // so it has been inlined there.

  // COPY was used explicitly in the copy constructor and the copy
  // assignment operator. Now it is used explicitly only in the
  // assignment operator, so it has been inlined there.

};

void swap(Vectorish& lhs, Vectorish& rhs) {
  using std::swap; // Get in the habit of using ADL in the swap
                   // implementation
  swap(lhs.size, rhs.size);
  swap(lhs.data, rhs.data);
}


int main() {
  cout << "---------- Construction: should allocate 10000 ----------" << endl;
  Vectorish* v = new Vectorish(10000);
  cout << "---------- Destruction: should deallocate 10000 ----------" << endl;
  delete v;
  cout << "---------- done ----------" << endl;
  // Use dynamically allocated objects to keep precise control over
  // destruction times.
  Vectorish* source1 = new Vectorish(100);
  Vectorish* source2 = new Vectorish(200);
  Vectorish* source3 = new Vectorish(300);
  cout << "---------- Copy construction should allocate 100, copy 100 ----------" << endl;
  Vectorish* target1 = new Vectorish(*source1);
  cout << "---------- Move construction should NOT allocate, copy or deallocate ...  ----------" << endl;
  Vectorish* target2 = new Vectorish(std::move(*source2));
  cout << "---------- ... but source2 destructor should deallocate 0 ----------" << endl;
  delete source2;
  cout << "---------- Copy assignment should allocate 100 copy 100 deallocate 200  ----------" << endl;
  *target2 = *source1;
  cout << "---------- Move assignment and source3 destructor should deallocate 100 between them  ----------" << endl;
  *target2 = std::move(*source3);
  delete source3;
  cout << "---------- target1 destructor should deallocate 100 ----------" << endl;
  delete target1;
  cout << "---------- target2 destructor should deallocate 300 ----------" << endl;
  delete target2;
  cout << "---------- source1 destructor should deallocate 100 ----------" << endl;
  delete source1;
  cout << "---------- done ----------" << endl;

}


